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
#include "DP83848Q_Q1_Reg.h"

/********************************************************/

#define EMAC_RMII               1

#define ETH_LINKSPEED_10        10
#define ETH_LINKSPEED_100       100

/********************************************************/
/** PHY Mode Selection      */
#define EMAC_INTERFACE              EMAC_RMII
#define EMAC_LINKSPEED              ETH_LINKSPEED_100

#if EMAC_LINKSPEED == ETH_LINKSPEED_10
 #define SPEED_SELECTION_BIT_VALUE (0u)
#else // EMAC_LINKSPEED == ETH_LINKSPEED_100
 #define SPEED_SELECTION_BIT_VALUE (1u)
#endif

/********************************************************/

#define USER_LED_PORT           CY_USER_LED1_PORT
#define USER_LED_PIN            CY_USER_LED1_PIN
#define USER_LED_PIN_MUX        CY_USER_LED1_PIN_MUX

/********************************************************/
#define ETH_REG_BASE         CY_GIG_ETH_TYPE

#define ETH_INTR_SRC         (CY_GIG_ETH_IRQN0)
#define ETH_INTR_SRC_Q1      (CY_GIG_ETH_IRQN1)
#define ETH_INTR_SRC_Q2      (CY_GIG_ETH_IRQN2)

#define ETHx_TD0_PORT        CY_GIG_ETH_TD0_PORT
#define ETHx_TD0_PIN         CY_GIG_ETH_TD0_PIN
#define ETHx_TD0_PIN_MUX     CY_GIG_ETH_TD0_PIN_MUX

#define ETHx_TD1_PORT        CY_GIG_ETH_TD1_PORT
#define ETHx_TD1_PIN         CY_GIG_ETH_TD1_PIN
#define ETHx_TD1_PIN_MUX     CY_GIG_ETH_TD1_PIN_MUX

#define ETHx_TX_CTL_PORT     CY_GIG_ETH_TX_CTL_PORT
#define ETHx_TX_CTL_PIN      CY_GIG_ETH_TX_CTL_PIN
#define ETHx_TX_CTL_PIN_MUX  CY_GIG_ETH_TX_CTL_PIN_MUX

#define ETHx_RD0_PORT        CY_GIG_ETH_RD0_PORT
#define ETHx_RD0_PIN         CY_GIG_ETH_RD0_PIN
#define ETHx_RD0_PIN_MUX     CY_GIG_ETH_RD0_PIN_MUX

#define ETHx_RD1_PORT        CY_GIG_ETH_RD1_PORT
#define ETHx_RD1_PIN         CY_GIG_ETH_RD1_PIN
#define ETHx_RD1_PIN_MUX     CY_GIG_ETH_RD1_PIN_MUX

#define ETHx_RX_CTL_PORT     CY_GIG_ETH_RX_CTL_PORT
#define ETHx_RX_CTL_PIN      CY_GIG_ETH_RX_CTL_PIN
#define ETHx_RX_CTL_PIN_MUX  CY_GIG_ETH_RX_CTL_PIN_MUX

#define ETHx_RX_ER_PORT      CY_GIG_ETH_RX_ER_PORT
#define ETHx_RX_ER_PIN       CY_GIG_ETH_RX_ER_PIN
#define ETHx_RX_ER_PIN_MUX   CY_GIG_ETH_RX_ER_PIN_MUX

#define ETHx_REF_CLK_PORT    CY_GIG_ETH_REF_CLK_PORT
#define ETHx_REF_CLK_PIN     CY_GIG_ETH_REF_CLK_PIN
#define ETHx_REF_CLK_PIN_MUX CY_GIG_ETH_REF_CLK_PIN_MUX

#define ETHx_MDC_PORT        CY_GIG_ETH_MDC_PORT
#define ETHx_MDC_PIN         CY_GIG_ETH_MDC_PIN
#define ETHx_MDC_PIN_MUX     CY_GIG_ETH_MDC_PIN_MUX

#define ETHx_MDIO_PORT       CY_GIG_ETH_MDIO_PORT
#define ETHx_MDIO_PIN        CY_GIG_ETH_MDIO_PIN
#define ETHx_MDIO_PIN_MUX    CY_GIG_ETH_MDIO_PIN_MUX

/** Interrupt Handlers for Ethernet 1     */
void Cy_Ethx_InterruptHandler (void)
{
    Cy_EthIf00_DecodeEvent();
}

/********************************************************/

/** PHY related constants   */  
#define PHY_ADDR     (1)       // DP83848Q_Q1's PHYAD0 pin has internal week pull up register
#define PHY_OUI_MSB  (0x2000u)
#define PHY_OUI_LSB  (0x17u)
#define PHY_VNDR_MDL (9u)
#define PHY_MDL_REV  (0u)

/********************************************************/

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

/********************************************************/
// EMAC *********

cy_stc_gpio_pin_prt_config_t gEthPortsConfg[] =
{
//  {                 portReg,                 pinNum, outVal,                driveMode,                hsiom, intEdge, intMask, vtrip, slewRate, driveSel  }
    {  CY_GIG_ETH_TX_CTL_PORT,  CY_GIG_ETH_TX_CTL_PIN,      0, CY_GPIO_DM_STRONG_IN_OFF,  ETHx_TX_CTL_PIN_MUX,       0,       0,     0,        0,        0 },
    {     CY_GIG_ETH_TD0_PORT,     CY_GIG_ETH_TD0_PIN,      0, CY_GPIO_DM_STRONG_IN_OFF,     ETHx_TD0_PIN_MUX,       0,       0,     0,        0,        0 },
    {     CY_GIG_ETH_TD1_PORT,     CY_GIG_ETH_TD1_PIN,      0, CY_GPIO_DM_STRONG_IN_OFF,     ETHx_TD0_PIN_MUX,       0,       0,     0,        0,        0 },
    {  CY_GIG_ETH_RX_CTL_PORT,  CY_GIG_ETH_RX_CTL_PIN,      0,         CY_GPIO_DM_HIGHZ,  ETHx_RX_CTL_PIN_MUX,       0,       0,     0,        0,        0 },
    {     CY_GIG_ETH_RD0_PORT,     CY_GIG_ETH_RD0_PIN,      0,         CY_GPIO_DM_HIGHZ,     ETHx_RD0_PIN_MUX,       0,       0,     0,        0,        0 },
    {     CY_GIG_ETH_RD1_PORT,     CY_GIG_ETH_RD1_PIN,      0,         CY_GPIO_DM_HIGHZ,     ETHx_RD0_PIN_MUX,       0,       0,     0,        0,        0 },
    {   CY_GIG_ETH_RX_ER_PORT,   CY_GIG_ETH_RX_ER_PIN,      0,         CY_GPIO_DM_HIGHZ,   ETHx_RX_ER_PIN_MUX,       0,       0,     0,        0,        0 },
    { CY_GIG_ETH_REF_CLK_PORT, CY_GIG_ETH_REF_CLK_PIN,      0,         CY_GPIO_DM_HIGHZ, ETHx_REF_CLK_PIN_MUX,       0,       0,     0,        0,        0 },
    {     CY_GIG_ETH_MDC_PORT,     CY_GIG_ETH_MDC_PIN,      0, CY_GPIO_DM_STRONG_IN_OFF,     ETHx_MDC_PIN_MUX,       0,       0,     0,        0,        3 },
    {    CY_GIG_ETH_MDIO_PORT,    CY_GIG_ETH_MDIO_PIN,      0,        CY_GPIO_DM_STRONG,    ETHx_MDIO_PIN_MUX,       0,       0,     0,        0,        3 },

};
#define ETH_PIN_COUNT (sizeof(gEthPortsConfg)/sizeof(gEthPortsConfg[0]))

/********************************************************/

#define ETH_FRAME_SIZE               64 // Min: 64 byte, Max:1518 byte
#define ETH_FRAME_SIZE_FCS            4 // Frame check sequence length. This is constant.
#define ETH_FRAME_SIZE_HEADER        14 // 6byte for destination address, 6 byte for source address, 2 byte for Type (This is constant)
#define ETH_FRAME_SIZE_EXCLUDING_FCS (ETH_FRAME_SIZE - ETH_FRAME_SIZE_FCS)
#define ETH_FRAME_SIZE_DATA          (ETH_FRAME_SIZE_EXCLUDING_FCS - ETH_FRAME_SIZE_HEADER)

#pragma pack(1)
typedef struct
{
    uint8_t desMacAddr[6];
    uint8_t srcMacAddr[6];
    uint16_t type;
    uint8_t data[ETH_FRAME_SIZE_DATA];
} cy_stc_ether_frame_t;
#pragma pack()

/** Transmit source buffer  */
#if   defined ( __ghs__ )
  #pragma alignvar (8) 
#elif defined ( __ICCARM__ )
  __attribute((aligned(8))) 
#else
  #warning "This driver is supported only by GHS and IAR compiler"
#endif
cy_stc_ether_frame_t g_txFrameTest =
{
    .desMacAddr = { 0x04u, 0x00u, 0x00u, 0x00u, 0x00u, 0x04u, },
    .srcMacAddr = { 0x02u, 0x00u, 0x00u, 0x00u, 0x00u, 0x02u, },
    .type       = 0xF022u,
    .data       =
    {
        0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u, 0x09u, 0x0Au, 0x0Bu, 0x0Cu, 0x0Du, 0x0Eu, 0x0Fu,
        0x10u, 0x11u, 0x12u, 0x13u, 0x14u, 0x15u, 0x16u, 0x17u, 0x18u, 0x19u, 0x1Au, 0x1Bu, 0x1Cu, 0x1Du, 0x1Eu, 0x1Fu,
        0x20u, 0x21u, 0x22u, 0x23u, 0x24u, 0x25u, 0x26u, 0x27u, 0x28u, 0x29u, 0x2Au, 0x2Bu, 0x2Cu, 0x2Du,
    }
};
uint8_t u8DummyTxBuf[ETH_FRAME_SIZE_DATA];

bool bFrameReceived = false;
bool bFrameTransmit = false;
uint16_t u16TransmitLength = 0;

/********************************************************/

static void Ethx_RxFrameCB ( cy_pstc_eth_type_t pstcEth, uint8_t * u8RxBuffer, uint32_t u32Length );
static void Ethx_TSUIncrement ( cy_pstc_eth_type_t pstcEth );
static void Ethx_TxFrameSuccessful ( cy_pstc_eth_type_t pstcEth, uint8_t u8QueueIndex );

static void InitPHY_DP83848Q_Q1(void);
static bool Check_DP83848Q_Q1_LinkStatus(void);

//EMAC End ***********

/********************************************************/

#define CORE_FREQ_IN_MHZ (CY_INITIAL_TARGET_FAST0_FREQ / 1000000UL)

int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    __enable_irq();

    /** Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
    
    /********************************************************/
    /***************** EMAC Configuration *******************/
    bool bClearAll = true;
    bool bTransmitBuf = true;
    bool bLastBuffer = true;

    /** Configure Ethernet Port pins    */
    Cy_GPIO_Multi_Pin_Init(gEthPortsConfg, ETH_PIN_COUNT);

    /** Wrapper configuration   */
    cy_str_ethif_wrapper_config stcWrapperConfig = {
        #if ((EMAC_INTERFACE == EMAC_RMII) && (EMAC_LINKSPEED == ETH_LINKSPEED_10))
        .stcInterfaceSel = CY_ETHIF_CTL_RMII_10,      /** 10 Mbps RMII */ 
        #elif ((EMAC_INTERFACE == EMAC_RMII) && (EMAC_LINKSPEED == ETH_LINKSPEED_100))
        .stcInterfaceSel = CY_ETHIF_CTL_RMII_100,     /** 100 Mbps RMII */     
        #else
        .stcInterfaceSel = 8,                         /** Error in configuration */     
        #endif
        .bRefClockSource = CY_ETHIF_EXTERNAL_HSIO,    /** assigning Ref_Clk to HSIO Clock, it is recommended to use external clock coming from HSIO  */
        .u8RefClkDiv = 1,                         /** RefClk: 50MHz, Divide Refclock by 2 to have 25 MHz tx clock  */
    };
    
    /** Default Timer register values   */
    CEDI_1588TimerVal stc1588TimerValue = {
        .secsUpper = 0,
        .secsLower = 0,
        .nanosecs = 0,
    };
    
    /** Increment values for each clock cycles      */
    CEDI_TimerIncrement stc1588TimerIncValue = { /** This Increment values are calculated for source clock of 196.607999 MHz */
        .nanoSecsInc = 5,                        /** Having source clock of 196.607999 MHz, with each clock cycle Nanosecond counter shall be incremented by 5  */
        .subNsInc = 0x1615,                      /** incrementing just Nanosecond counter will not give accuracy, so sub-nanosecond counter also must be incremented  */  
        .lsbSubNsInc = 0x55,                     /** 0x55 is the lower 8 bits increment value for subNanosecond and 0x1615 is the higher 16 bits of the counter */
        .altIncCount = 0,                        /** This example is not using alternate increment mode, also it is not recommended by IP provider          */
        .altNanoSInc = 0,                        /** When Alt increment mode is disabled, then this counter does not play any role                          */
    };
    
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
                    .mdcPclkDiv          = CEDI_MDC_DIV_BY_48,          /** source clock is 80 MHz and MDC must be less than 2.5MHz   */
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
                    .pstcTSUConfig       = &stcTSUConfig,               /** TSU settings    */
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
                    .btsu_sec_inc           = 0,          /** TSU seconds register increment */
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
                    
                    /** call back functions  */
                    .rxframecb  = Ethx_RxFrameCB,
                    .txerrorcb  = NULL,
                    .txcompletecb = Ethx_TxFrameSuccessful,     /** Set it to NULL, if do not wish to have callback */
                    .tsuSecondInccb = Ethx_TSUIncrement,
    };

    /** Enable Ethernet Interrupts  */
    const cy_stc_sysint_irq_t irq_cfg_ethx_q0 = {.sysIntSrc  = ETH_INTR_SRC,    .intIdx  = CPUIntIdx3_IRQn, .isEnabled  = true};
    const cy_stc_sysint_irq_t irq_cfg_ethx_q1 = {.sysIntSrc  = ETH_INTR_SRC_Q1, .intIdx  = CPUIntIdx3_IRQn, .isEnabled  = true};
    const cy_stc_sysint_irq_t irq_cfg_ethx_q2 = {.sysIntSrc  = ETH_INTR_SRC_Q2, .intIdx  = CPUIntIdx3_IRQn, .isEnabled  = true};
    
    Cy_SysInt_InitIRQ(&irq_cfg_ethx_q0);
    Cy_SysInt_SetSystemIrqVector(irq_cfg_ethx_q0.sysIntSrc, Cy_Ethx_InterruptHandler);

    Cy_SysInt_InitIRQ(&irq_cfg_ethx_q1);
    Cy_SysInt_SetSystemIrqVector(irq_cfg_ethx_q1.sysIntSrc, Cy_Ethx_InterruptHandler);

    Cy_SysInt_InitIRQ(&irq_cfg_ethx_q2);
    Cy_SysInt_SetSystemIrqVector(irq_cfg_ethx_q2.sysIntSrc, Cy_Ethx_InterruptHandler);
    
    NVIC_SetPriority(CPUIntIdx3_IRQn, 3);
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);
    
    /** Initialize ENET MAC */
    CY_ASSERT(CY_ETHIF_SUCCESS == Cy_EthIf_Init(ETH_REG_BASE, &stcENETConfig, &stcInterruptConfig));

    /** PHY initialization  */
    InitPHY_DP83848Q_Q1();
    while(Check_DP83848Q_Q1_LinkStatus() == false);

    CY_ASSERT(CY_ETHIF_SUCCESS == Cy_EthIf_TransmitFrame(ETH_REG_BASE, (uint8_t*)&g_txFrameTest, ETH_FRAME_SIZE, CY_ETH_QS0_0, bLastBuffer));
    
    /** Free Release Buffer, this routine shall be called at regular interval of time to free "Released" buffers */
    /** Release all Transmit buffer */
    Cy_EthIF_ClearReleasedBuf(bClearAll, bTransmitBuf);

    for(;;)
    {
        if (bFrameReceived)
        {
            bFrameReceived = false;
            bFrameTransmit = false;
            
            /** Transmit Received Frame  */
            CY_ASSERT(CY_ETHIF_SUCCESS == Cy_EthIf_TransmitFrame(ETH_REG_BASE, (uint8_t*)&g_txFrameTest, ETH_FRAME_SIZE, CY_ETH_QS0_0, bLastBuffer));
            
            /** Clear all released buffer for both Transmit and Receive    */
            Cy_EthIF_ClearReleasedBuf(bClearAll, bTransmitBuf);
            bTransmitBuf = false;
            Cy_EthIF_ClearReleasedBuf(bClearAll, bTransmitBuf);
            bTransmitBuf = true;
        }
    }
}

// EMAC *****************
static void Ethx_RxFrameCB ( cy_pstc_eth_type_t pstcEth, uint8_t * u8RxBuffer, uint32_t u32Length )
{
    bFrameReceived = true;
    
    /** Copy frame to transmit buffer */
    /** Starting from 14, as actual data starts from there. */
    /** Copy function also includes last 4 bytes of CDC     */
    for (uint32_t cntr = 14; cntr < (u32Length - 4); cntr++)
    {
        g_txFrameTest.data[cntr-14] = u8RxBuffer[cntr];
    }
    
    u16TransmitLength = (uint16_t) (u32Length - 4);     /** Echo frame will have last 4 bytes of CRC from EMAC CRC generator */
    
    u16TransmitLength = u16TransmitLength + 64;
    if (u16TransmitLength > 1500)
    {
        u16TransmitLength = 64;
    }
    
    /** Receive buffer should be release to be reused again; done in main while loop along with transmit buffer  */
    
    /** Toggle LED  */
    Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);        
}

static void Ethx_TxFrameSuccessful ( cy_pstc_eth_type_t pstcEth, uint8_t u8QueueIndex )
{
    bFrameTransmit = true;
    u16TransmitLength = u16TransmitLength + 64;
    if (u16TransmitLength > 1500)
    {
        u16TransmitLength = 64;
    }
}

/** TSU One Second Increment Interrupt call back function   */
static void Ethx_TSUIncrement ( cy_pstc_eth_type_t pstcEth )
{
    Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
}

/*******************************************************************************
* Function Name: InitPHY_DP83848Q_Q1
****************************************************************************//**
*
* \brief Dedicated to initialize PHY DP83848Q_Q1
*
* \Note:
* If hardware consist of any other PHY than DP83848Q_Q1, dedicated function shall be written to configure relevant 
* registers in side PHY
*******************************************************************************/
static void InitPHY_DP83848Q_Q1(void)
{
    volatile uint32_t    u32ReadData = 0;

    /** Reg PHYIDR1/2 :Read PHY Identifier to check connection */
    un_dp83848q_q1_phyidr1_t r_phyidr1 = {0};
    r_phyidr1.u16 = Cy_EthIf_PhyRegRead(ETH_REG_BASE, DP83848Q_Q1_REG_NORMAL_PHYIDR1, PHY_ADDR, CORE_FREQ_IN_MHZ);
    CY_ASSERT(r_phyidr1.f.u16OUI_MSB == PHY_OUI_MSB);

    un_dp83848q_q1_phyidr2_t r_phyidr2 = {0};
    r_phyidr2.u16 = Cy_EthIf_PhyRegRead(ETH_REG_BASE, DP83848Q_Q1_REG_NORMAL_PHYIDR2, PHY_ADDR, CORE_FREQ_IN_MHZ);
    CY_ASSERT(r_phyidr2.f.u6OUI_LSB  == PHY_OUI_LSB);
    CY_ASSERT(r_phyidr2.f.u6VNDR_MDL == PHY_VNDR_MDL);
    CY_ASSERT(r_phyidr2.f.u4MDL_REV  == PHY_MDL_REV);

    /** Reg BMCR: Perform a full reset, including All registers   */
    un_dp83848q_q1_bmcr_t wr_bmcr = {0};
    wr_bmcr.f.u1RESET             = 1;
    Cy_EthIf_PhyRegWrite(ETH_REG_BASE, DP83848Q_Q1_REG_NORMAL_BMCR, wr_bmcr.u16, PHY_ADDR, CORE_FREQ_IN_MHZ);
    while(1)
    {
        wr_bmcr.u16 = Cy_EthIf_PhyRegRead(ETH_REG_BASE, DP83848Q_Q1_REG_NORMAL_BMCR, PHY_ADDR, CORE_FREQ_IN_MHZ);
        if(wr_bmcr.f.u1RESET == 0)
        {
            break;
        }
    }

    /** Reg BMCR: 10M/100M, Full Duplex and Auto Negotiation OFF  */
    wr_bmcr.u16                         = 0u;                        // clear temporary variable
    wr_bmcr.f.u1SPEED_SELECTION         = SPEED_SELECTION_BIT_VALUE; // speed
    wr_bmcr.f.u1AUTO_NEGOTIATION_ENABLE = 0u;                        // Auto-negotiation off
    wr_bmcr.f.u1DUPLEX_MODE             = 1u;                        // Full-Duplex mode
    Cy_EthIf_PhyRegWrite(ETH_REG_BASE, DP83848Q_Q1_REG_NORMAL_BMCR, wr_bmcr.u16, PHY_ADDR, CORE_FREQ_IN_MHZ);

    wr_bmcr.u16 = Cy_EthIf_PhyRegRead(ETH_REG_BASE, DP83848Q_Q1_REG_NORMAL_BMCR, PHY_ADDR, CORE_FREQ_IN_MHZ);
    CY_ASSERT(wr_bmcr.f.u1DUPLEX_MODE     == 1u);
    CY_ASSERT(wr_bmcr.f.u1SPEED_SELECTION == SPEED_SELECTION_BIT_VALUE);

    /** Reg RBR: RMII and Bypass Register  */
    un_dp83848q_q1_rbr_t wr_rbr = {0};
    wr_rbr.f.u1RMII_MODE        = 1u;
    Cy_EthIf_PhyRegWrite(ETH_REG_BASE, DP83848Q_Q1_REG_EXTENDED_RBR, wr_rbr.u16, PHY_ADDR, CORE_FREQ_IN_MHZ);

    wr_rbr.u16 = Cy_EthIf_PhyRegRead(ETH_REG_BASE, DP83848Q_Q1_REG_EXTENDED_RBR, PHY_ADDR, CORE_FREQ_IN_MHZ);
    CY_ASSERT(wr_rbr.f.u1RMII_MODE == 1u);
}

/*******************************************************************************
* Function Name: Check_DP83848Q_Q1_LinkStatus
****************************************************************************//**
*
* \brief Function reads specific register from DP83867IR to learn Link status
*
* \param 
* \return true Link up
* \return false Link Down 
*
*******************************************************************************/
static bool Check_DP83848Q_Q1_LinkStatus(void)
{
    un_dp83848q_q1_bmsr_t r_bmsr = {0};
    r_bmsr.u16 = Cy_EthIf_PhyRegRead(ETH_REG_BASE, DP83848Q_Q1_REG_NORMAL_BMSR, PHY_ADDR, CORE_FREQ_IN_MHZ);
    if(r_bmsr.f.u1LINK_STATUS == 1u)
    {
        return true;  /** Link up */
    }
    else
    {
        return false; /** Link down   */
    }
}

// EMAC END *******

/* [] END OF FILE */
