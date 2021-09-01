/***************************************************************************//**
* \file main_cm0plus.c
*
* \version 1.0
*
* \brief Main example file for CM0+
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

void AudioTDMInterruptHandler(void);

static int TDM_DATA[64] =
{
    0xAAAAAAAA, 0xbbbbbbbb, 0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111,
    0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111,
    0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111,
    0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111,
    0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111,
    0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111,
    0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111,
    0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111, 0x22222222, 0x11111111,
};
#define DATA_NUM_PER_PERIOD (sizeof(TDM_DATA) / sizeof(uint32_t))

static cy_stc_gpio_pin_config_t TDM_port_pin_cfg =
{
    .outVal   = 0,
    .intEdge  = 0,
    .intMask  = 0,
    .vtrip    = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn   = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel  = 0,
    .vohSel   = 0,
};

static const cy_stc_sysint_irq_t irqCfgTDM_TX =
{
    .sysIntSrc  = tdm_0_interrupts_tx_1_IRQn,
    .intIdx     = CPUIntIdx4_IRQn,
    .isEnabled  = true,
};
 
cy_stc_tdm_config_t config_tdm = 
{
    .tx_config =
    {
        .txEnable               =   true,                   //Transmitter Enable
        .txMasterMode           =   CY_TDM_DEVICE_MASTER,   //Master Mode.
        .txWordSize             =   CY_TDM_SIZE_32,
        .txFormat               =   CY_TDM_RIGHT_DELATED,
        .txClkDiv               =   8,                      
        .txClkSel               =   CY_TDM_SEL_SRSS_CLK0,
        .txSckPolarity          =   CY_TDM_CLK,  
        .txFsyncPolarity        =   CY_TDM_SIGN,  
        .txFsyncFormat          =   CY_TDM_CH_PERIOD,       //Duration of the first channel.*/
        .txChannelNUM           =   32,                     //16 channels
        .txChannelSize          =   32,                     //16 bits.channel size must be greater or equal to the word size.E
        .txChEN                 =   0xffffffff,               
        .txTestMode             =   false,                  //Functional Mode.
        .txFIFOTriggerLevel     =   192,
    },
    .rx_config =
    {                    
        .rxEnable               =   true,                   //Receiver Enable.
        .rxMasterMode           =   CY_TDM_DEVICE_SLAVE,    //Slave Mode.
        .rxWordSize             =   CY_TDM_SIZE_32,
        .rxSignExtend           =   CY_ZERO_EXTEND,
        .rxFormat               =   CY_TDM_RIGHT_DELATED,
        .rxClkDiv               =   8,                      //not care
        .rxClkSel               =   CY_TDM_SEL_SRSS_CLK0,   
        .rxSckPolarity          =   CY_TDM_CLK,  
        .rxFsyncPolarity        =   CY_TDM_SIGN,  
        .rxLateSample           =   false,  
        .rxFsyncFormat          =   CY_TDM_CH_PERIOD,  
        .rxChannelNUM           =   32,                      
        .rxChannelSize          =   32,                     
        .rxChEN                 =   0xffffffff,                              
        .rxTestMode             =   false,                  
        .rxFIFOTriggerLevel     =   DATA_NUM_PER_PERIOD ,
    },
};

uint32_t    TDM_READ_DATA[64] = {0};

void AudioTDMInterruptHandler(void)
{
    uint32_t    TX_maskedIntrStatus;
    uint32_t    RX_maskedIntrStatus;    
    uint32_t    DATA_RX = 0;
    TX_maskedIntrStatus = Cy_AudioTDM_GetTxInterruptStatusMasked(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);
    RX_maskedIntrStatus = Cy_AudioTDM_GetRxInterruptStatusMasked(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT);
    
    if((TX_maskedIntrStatus & CY_TDM_INTR_TX_FIFO_TRIGGER) != 0)
    {
        for(uint32_t data_i = 0; data_i < DATA_NUM_PER_PERIOD ; data_i++)
        {  
            Cy_AudioTDM_WriteTxData(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, TDM_DATA[data_i]); 
        }
    }
    
    if((RX_maskedIntrStatus & CY_TDM_INTR_RX_FIFO_TRIGGER) != 0)
    {
        for(uint32_t data_i = 0; data_i < DATA_NUM_PER_PERIOD ; data_i++)
        {
            DATA_RX   = Cy_AudioTDM_ReadRxData(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT);
           TDM_READ_DATA[data_i] = DATA_RX; 
        }
    }
    Cy_AudioTDM_ClearTxInterrupt(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT,TX_maskedIntrStatus);
    Cy_AudioTDM_ClearRxInterrupt(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT,RX_maskedIntrStatus);
}

int main(void)
{
     SystemInit();
    
    __enable_irq();
    
    //For debug
    CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT;
    CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT;

    /**************************************************/
    /*******             HF_CLK Enable       **********/
    /**************************************************/
     Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_5); //Enable hfclk5 for Audio
    
    /**************************************/
    /*      Port Setting for AudioTDM     */
    /**************************************/
    /* TDM[0].tdm_tx_mck[0] */
    /* Digital Active - tdm[0].tdm_tx_mck[0]:2 */
    //TDM_port_pin_cfg.driveMode  = CY_GPIO_DM_STRONG_IN_OFF;
    //TDM_port_pin_cfg.hsiom      = CY_AUDIOSS_TDM0_TX_MCK_PIN_MUX;
    //Cy_GPIO_Pin_Init(CY_AUDIOSS_TDM0_TX_MCK_PORT, CY_AUDIOSS_TDM0_TX_MCK_PIN, &TDM_port_pin_cfg);
    
    /* TDM[0].tdm_tx_sck[0] */
    /* Digital Active - tdm[0].tdm_tx_sck[0]:2 */
    TDM_port_pin_cfg.driveMode  = CY_GPIO_DM_STRONG_IN_OFF;
    TDM_port_pin_cfg.hsiom      = CY_AUDIOSS_TDM0_TX_SCK_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_TDM0_TX_SCK_PORT, CY_AUDIOSS_TDM0_TX_SCK_PIN, &TDM_port_pin_cfg);
    
    /* TDM[0].tdm_tx_fsync[0] */
    /* Digital Active - tdm[0].tdm_tx_fsync[0]:2 */
    TDM_port_pin_cfg.driveMode  = CY_GPIO_DM_STRONG_IN_OFF;
    TDM_port_pin_cfg.hsiom      = CY_AUDIOSS_TDM0_TX_FSYNC_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_TDM0_TX_FSYNC_PORT, CY_AUDIOSS_TDM0_TX_FSYNC_PIN, &TDM_port_pin_cfg);
    
    /* TDM[0].tdm_tx_sd[0] */
    /* Digital Active - tdm[0].tdm_tx_sd[0]:2 */
    TDM_port_pin_cfg.driveMode  = CY_GPIO_DM_STRONG_IN_OFF;
    TDM_port_pin_cfg.hsiom      = CY_AUDIOSS_TDM0_TX_SD_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_TDM0_TX_SD_PORT, CY_AUDIOSS_TDM0_TX_SD_PIN, &TDM_port_pin_cfg);

    /* TDM[0].tdm_rx_mck[0] */
    /* Digital Active - tdm[0].tdm_rx_mck[0]:2 */
    //TDM_port_pin_cfg.driveMode  = CY_GPIO_DM_HIGHZ;
    //TDM_port_pin_cfg.hsiom      = CY_AUDIOSS_TDM0_RX_MCK_PIN_MUX;
    //Cy_GPIO_Pin_Init(CY_AUDIOSS_TDM0_RX_MCK_PORT, CY_AUDIOSS_TDM0_RX_MCK_PIN, &TDM_port_pin_cfg);
    
    /* TDM[0].tdm_rx_sck[0] */
    /* Digital Active - tdm[0].tdm_rx_sck[0]:2 */
    TDM_port_pin_cfg.driveMode  = CY_GPIO_DM_HIGHZ;
    TDM_port_pin_cfg.hsiom      = CY_AUDIOSS_TDM0_RX_SCK_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_TDM0_RX_SCK_PORT, CY_AUDIOSS_TDM0_RX_SCK_PIN, &TDM_port_pin_cfg);
    
    /* TDM[0].tdm_rx_fsync[0] */
    /* Digital Active - tdm[0].tdm_rx_fsync[0]:2 */
    TDM_port_pin_cfg.driveMode  = CY_GPIO_DM_HIGHZ;
    TDM_port_pin_cfg.hsiom      = CY_AUDIOSS_TDM0_RX_FSYNC_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_TDM0_RX_FSYNC_PORT, CY_AUDIOSS_TDM0_RX_FSYNC_PIN, &TDM_port_pin_cfg);
    
    /* TDM[0].tdm_rx_sd[0] */
    /* Digital Active - tdm[0].tdm_rx_sd[0]:2 */ 
    TDM_port_pin_cfg.driveMode  = CY_GPIO_DM_HIGHZ; //CY_GPIO_DM_HIGHZ;
    TDM_port_pin_cfg.hsiom      = CY_AUDIOSS_TDM0_RX_SD_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_TDM0_RX_SD_PORT, CY_AUDIOSS_TDM0_RX_SD_PIN, &TDM_port_pin_cfg);
    
    /**************************************/
    /*  Interrupt setting for Audio TDM   */
    /**************************************/
    Cy_SysInt_InitIRQ(&irqCfgTDM_TX);
    Cy_SysInt_SetSystemIrqVector(irqCfgTDM_TX.sysIntSrc, AudioTDMInterruptHandler);
    NVIC_EnableIRQ(CPUIntIdx4_IRQn);

    /**************************************/
    /*    Initialization for AudioTDM     */ 
    /**************************************/
    Cy_AudioTDM_DeInit(CY_AUDIOSS_TDM_TYPE);
    Cy_AudioTDM_Init(CY_AUDIOSS_TDM_TYPE, &config_tdm);
    Cy_AudioTDM_SetTxTriggerInterruptMask(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);
    Cy_AudioTDM_SetRxTriggerInterruptMask(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT);
    Cy_AudioTDM_StartRx(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT);
    Cy_AudioTDM_StartTx(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);
    for(;;);
}


/* [] END OF FILE */
