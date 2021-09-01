/***************************************************************************//**
* \file main_cm7_0.c
*
* \version 1.0
*
* \brief Main example file for CM7
*
********************************************************************************
* \copyright
* Copyright 2016-2020, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_project.h"
#include "cy_device_headers.h"
#include "drivers\ethernet\cy_ethif.h"

/* device depending code */
#define HF_CLK_IDX_TO_TSU (CY_SYSCLK_HFCLK_5) 
/* device depending code end */

#if (CY_USE_PSVP == 1)
    #define USER_LED_PORT    CY_LED8_PORT
    #define USER_LED_PIN     CY_LED8_PIN
    #define USER_LED_PIN_MUX CY_LED8_PIN_MUX
#else
    #define USER_LED_PORT    CY_USER_LED2_PORT
    #define USER_LED_PIN     CY_USER_LED2_PIN
    #define USER_LED_PIN_MUX CY_USER_LED2_PIN_MUX
#endif

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = USER_LED_PIN_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

static void Cy_Eth0_InterruptHandler (void);
static void Eth0_TSUIncrement ( cy_pstc_eth_type_t pstcEth );
//EMAC End ***********

#define CLK_FREQ_WCO       (   32768ul)
#define CLK_FREQ_ILO0      (   32768ul)
#define CLK_FREQ_ILO1      (   32768ul)
#define CLK_FREQ_ECO       (16000000ul)
#define CLK_FREQ_IMO       ( 8000000ul)
cy_stc_base_clk_freq_t g_baseFreqInfo = 
{
    .clk_imo_freq  = CY_CLK_IMO_FREQ_HZ,
    .clk_ext_freq  = 0ul,
    .clk_eco_freq  = CY_CLK_ECO_FREQ_HZ,
    .clk_ilo0_freq = CY_CLK_HVILO0_FREQ_HZ,
    .clk_ilo1_freq = CY_CLK_HVILO1_FREQ_HZ,
    .clk_wco_freq  = CY_CLK_WCO_FREQ_HZ,
};

void CalcTSUIncValue(uint32_t sourceFreq, CEDI_TimerIncrement* incValue)
{
    uint64_t secInNamo = 1000000000ull;
    uint64_t fractionBitCount = 24; // 24 bit fraction

    uint64_t incValueWithfixedPoint = (secInNamo << fractionBitCount)  / (uint64_t)sourceFreq;
    incValue->nanoSecsInc = (uint32_t)((incValueWithfixedPoint & 0xFFFFFFFFF000000ull) >> fractionBitCount);
    incValue->subNsInc    = (uint16_t)((incValueWithfixedPoint & 0x000000000FFFF00ull) >> 8ull);
    incValue->lsbSubNsInc = (uint8_t)(incValueWithfixedPoint & 0x0000000000000FFull);
    incValue->altIncCount = 0;
    incValue->altNanoSInc = 0;
}

int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    __enable_irq();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);

    Cy_SysClk_InitGetFreqParams(&g_baseFreqInfo);
    uint32_t ClockFreqOfTSU;
    Cy_SysClk_GetHfClkFrequency(HF_CLK_IDX_TO_TSU, &ClockFreqOfTSU);

    /** Wrapper configuration   */
    cy_str_ethif_wrapper_config stcWrapperConfig = {
        .stcInterfaceSel = CY_ETHIF_CTL_MII_100,    /** MII */ 
        .bRefClockSource = CY_ETHIF_INTERNAL_PLL,   /** Although MII interface does not use this clock, assigning Ref_Clk to internal PLL clock  */
        .u8RefClkDiv = 0,                       /** RefClk is not going to be used in MII mode  */
    };
    
    /** Default Timer register values   */
    CEDI_1588TimerVal stc1588TimerValue = {
        .secsUpper = 0,
        .secsLower = 0,
        .nanosecs = 0,
    };

    /** Increment values for each clock cycles      */
    CEDI_TimerIncrement stc1588TimerIncValue;
    CalcTSUIncValue(ClockFreqOfTSU ,&stc1588TimerIncValue);

    /** To calculate the value to write to the sub-ns register you take the decimal value of 
        the sub-nanosecond value, then multiply it by 2 to the power of 24 (16777216) and 
        convert the result to hexadecimal. For example for a sub-nanosecond value of 0.33333333 
        you would write 0x55005555.  */ 

    /** TSU configuration   */
    cy_str_ethif_TSU_Config stcTSUConfig = {
        .pstcTimerValue    = &stc1588TimerValue,            /** start value for the counter     */
        .pstcTimerIncValue = &stc1588TimerIncValue,         /** Increment value for each clock cycle    */
        .bOneStepTxSyncEnable = false,                      /** useful when PTP protocol is in place    */
        .enTxDescStoreTimeStamp = CEDI_TX_TS_DISABLED,
        .enRxDescStoreTimeStamp = CEDI_RX_TS_DISABLED,
        .bStoreNSinRxDesc = false,
    };

    /** General Ethernet configuration  */
    cy_stc_ethif_configuration_t stcENETConfig = {
        .bintrEnable         = 1,                           /** Interrupt enable  */
        .dmaDataBurstLen     = CEDI_DMA_DBUR_LEN_4, 
        .u8dmaCfgFlags       = CEDI_CFG_DMA_FRCE_TX_BRST,
        .mdcPclkDiv          = CEDI_MDC_DIV_BY_16,          /** For PSVP, source clock is 24 MHz and MDC must be less than 2.5MHz   */
        .u8rxLenErrDisc      = 0,                           /** Length error frame not discarded  */
        .u8disCopyPause      = 0,                           
        .u8chkSumOffEn       = 0,                           /** Checksum for both Tx and Rx disabled    */
        .u8rx1536ByteEn      = 1,                           /** Enable receive frame up to 1536    */
        .u8rxJumboFrEn       = 0,
        .u8enRxBadPreamble   = 1,
        .u8ignoreIpgRxEr     = 0,
        .u8storeUdpTcpOffset = 0,
        .u8aw2wMaxPipeline   = 2,                           /** Value must be > 0   */
        .u8ar2rMaxPipeline   = 2,                           /** Value must be > 0   */
        .u8pfcMultiQuantum   = 0,
        .pstcWrapperConfig   = &stcWrapperConfig,
        .pstcTSUConfig       = &stcTSUConfig,               /** No TSU settings */
        .btxq0enable         = 1,                           /** Tx Q0 Enabled   */
        .btxq1enable         = 0,                           /** Tx Q1 Disabled  */
        .btxq2enable         = 0,                           /** Tx Q2 Disabled  */
        .brxq0enable         = 1,                           /** Rx Q0 Enabled   */
        .brxq1enable         = 0,                           /** Rx Q1 Disabled  */
        .brxq2enable         = 0,                           /** Rx Q2 Disabled  */
    };

    /** Interrupt configurations    */
    cy_stc_ethif_interruptconfig_t stcInterruptConfig = {
        .btsu_time_match        = 0,          /** Time stamp unit time match event */
        .bwol_rx                = 0,          /** Wake on LAN event received */
        .blpi_ch_rx             = 0,          /** LPI indication status bit change received */
        .btsu_sec_inc           = 1,          /** TSU seconds register increment */
        .bptp_tx_pdly_rsp       = 0,          /** PTP pdelay_resp frame transmitted */
        .bptp_tx_pdly_req       = 0,          /** PTP pdelay_req frame transmitted */
        .bptp_rx_pdly_rsp       = 0,          /** PTP pdelay_resp frame received */
        .bptp_rx_pdly_req       = 0,          /** PTP pdelay_req frame received */
        .bptp_tx_sync           = 0,          /** PTP sync frame transmitted */
        .bptp_tx_dly_req        = 0,          /** PTP delay_req frame transmitted */
        .bptp_rx_sync           = 0,          /** PTP sync frame received */
        .bptp_rx_dly_req        = 0,          /** PTP delay_req frame received */
        .bext_intr              = 0,          /** External input interrupt detected */
        .bpause_frame_tx        = 0,          /** Pause frame transmitted */
        .bpause_time_zero       = 0,          /** Pause time reaches zero or zeroq pause frame received */
        .bpause_nz_qu_rx        = 0,          /** Pause frame with non-zero quantum received */
        .bhresp_not_ok          = 0,          /** DMA hresp not OK */
        .brx_overrun            = 1,          /** Rx overrun error */
        .bpcs_link_change_det   = 0,          /** Link status change detected by PCS */
        .btx_complete           = 1,          /** Frame has been transmitted successfully */
        .btx_fr_corrupt         = 1,          /** Tx frame corruption */
        .btx_retry_ex_late_coll = 1,          /** Retry limit exceeded or late collision */
        .btx_underrun           = 1,          /** Tx underrun */
        .btx_used_read          = 1,          /** Used bit set has been read in Tx descriptor list */
        .brx_used_read          = 1,          /** Used bit set has been read in Rx descriptor list */
        .brx_complete           = 1,          /** Frame received successfully and stored */
        .bman_frame             = 0,          /** Management Frame Sent */   

        /** call back function  */
        .rxframecb              = NULL,
        .txerrorcb              = NULL,
        .txcompletecb           = NULL,
        .tsuSecondInccb         = Eth0_TSUIncrement,
    };

    /** Enable Ethernet Interrupts  */
    cy_stc_sysint_irq_t irq_cfg_eth0_q0 = {.sysIntSrc  = CY_GIG_ETH_IRQN0,    .intIdx  = CPUIntIdx3_IRQn, .isEnabled  = true};

    Cy_SysInt_InitIRQ(&irq_cfg_eth0_q0);
    Cy_SysInt_SetSystemIrqVector(irq_cfg_eth0_q0.sysIntSrc, Cy_Eth0_InterruptHandler);
    NVIC_SetPriority(irq_cfg_eth0_q0.intIdx, 3);
    NVIC_EnableIRQ(irq_cfg_eth0_q0.intIdx);

    /** Initialize ENET MAC */
    if (CY_ETHIF_SUCCESS != Cy_EthIf_Init(CY_GIG_ETH_TYPE, &stcENETConfig, &stcInterruptConfig))
    {
        // Error
    }

    for(;;);
}

/** Interrupt Handlers for Ethernet 0     */
void Cy_Eth0_InterruptHandler (void)
{
    Cy_EthIf00_DecodeEvent();
}

/** TSU One Second Increment Interrupt call back function   */
static void Eth0_TSUIncrement ( cy_pstc_eth_type_t pstcEth )
{
    Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
}

/* [] END OF FILE */
