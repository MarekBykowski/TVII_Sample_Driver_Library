/***************************************************************************//**
* \file main_cm7_0.c
*
* \version 1.0
*
* \brief Main example file for CM7_0
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
#include "AUDIO_CODEC.h"
#include <stdio.h>
#include <stdarg.h>

/* for UART */
//------------------------------------------------------------------------------
static void Peripheral_Initialization(void);
static void Term_Printf(void *fmt, ...);

/* User setting for clock and  */
//------------------------------------------------------------------------------
#define INTERNAL_CLOCK          0
#define EXTERNAL_CLOCK          1



/* User setting value */
//------------------------------------------------------------------------------
#if (CY_USE_PSVP == 1)  
  #define SOURCE_CLOCK_FRQ      24000000ul
#else
  #define SOURCE_CLOCK_FRQ      80000000ul
#endif

#define SCB_SPI_BAUDRATE        125000ul        /* Please set baudrate value of SPI you want */
#define SCB_SPI_OVERSAMPLING    16ul            /* Please set oversampling of SPI you want */
#define SCB_SPI_CLOCK           (SCB_SPI_BAUDRATE * SCB_SPI_OVERSAMPLING)
#define DIVIDER_NO_1            (1u)

/* Port pin config for SPI */
//------------------------------------------------------------------------------
static cy_stc_gpio_pin_config_t SPI_port_pin_cfg =
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

/* Port pin config for I2S */
//------------------------------------------------------------------------------
static cy_stc_gpio_pin_config_t I2S_port_pin_cfg =
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

/* I2S-Tx and I2S-Rx interface confiuration */
//------------------------------------------------------------------------------

cy_stc_i2s_config_t const config_I2S =
{
    .txEnabled          = true,
    .txMasterMode       = CY_I2S_DEVICE_MASTER,
    .txFormat           = CY_I2S_LEFT,
    .txWordSize         = CY_I2S_LEN16,
    .txClkDiv           = 7u,                   // Divided by 6 -- 4MHz
    .txClkSel           = CY_I2S_SEL_SRSS_CLK0,
    .txSckPolarity      = 0,
    .txWsPolarity       = 0,
    .txChannel0Enable   = true,
    .txChannel1Enable   = true,
    .txChannelSize      = 15,                   // 16 bit
    .txFifoTriggerLevel = 63,                    // DATA_NUM_PER_PERIOD,
    .rxEnabled          = true,
    .rxMasterMode       = CY_I2S_DEVICE_SLAVE,
    .rxFormat           = CY_I2S_LEFT_DELAYED,
    .rxWordSize         = CY_I2S_LEN16,
    .rxSignExtension    = 0,
    .rxClkDiv           = 7u,
    .rxClkSel           = CY_I2S_SEL_SRSS_CLK0,
    .rxSckPolarity      = 0,
    .rxWsPolarity       = 0,
    .rxLateSampleDelay  = 0,
    .rxChannel0Enable   = true,
    .rxChannel1Enable   = true,
    .rxChannelSize      = 15,                   // 16 bit
    .rxFifoTriggerLevel = 63,                   // DATA_NUM_PER_PERIOD,
};

/* Audio SPI interface confiuration */
//------------------------------------------------------------------------------
static const cy_stc_scb_spi_config_t SCB_SPI_cfg =
{
    .spiMode                    = CY_SCB_SPI_MASTER,        /*** Specifies the mode of operation    */     
    .subMode                    = CY_SCB_SPI_MOTOROLA,      /*** Specifies the submode of SPI operation    */
    .sclkMode                   = CY_SCB_SPI_CPHA1_CPOL0,   /*** When clock is inactive, the level is low. Data signal is sampled on first edge*/
    .oversample                 = SCB_SPI_OVERSAMPLING, 
    .rxDataWidth                = 16,
    .txDataWidth                = 16,
    .enableMsbFirst             = true,
    .enableFreeRunSclk          = false,
    .enableInputFilter          = false,
    .enableMisoLateSample       = true,
    .enableTransferSeperation   = false,
    .ssPolarity0                = 0,
    .ssPolarity1                = 0,
    .ssPolarity2                = 0,
    .ssPolarity3                = 0,
    .enableWakeFromSleep        = 0,
    .rxFifoTriggerLevel         = 0,
    .rxFifoIntEnableMask        = 0,
    .txFifoTriggerLevel         = 0,
    .txFifoIntEnableMask        = 0,
    .masterSlaveIntEnableMask   = 0,
    .enableSpiDoneInterrupt     = 0,
    .enableSpiBusErrorInterrupt = 0,
};
cy_stc_scb_spi_context_t spiCtx;

/* for UART */
//------------------------------------------------------------------------------
uint8_t                             g_uart_out_data[128];
cy_stc_scb_uart_context_t           g_stc_uart_context;
cy_stc_scb_uart_config_t            g_stc_uart_config = {
                                                   .uartMode                   = CY_SCB_UART_STANDARD,
                                                   .oversample                 = 8,
                                                   .dataWidth                  = 8,
                                                   .enableMsbFirst             = false,
                                                   .stopBits                   = CY_SCB_UART_STOP_BITS_1,
                                                   .parity                     = CY_SCB_UART_PARITY_NONE,
                                                   .enableInputFilter          = false,
                                                   .dropOnParityError          = false,
                                                   .dropOnFrameError           = false,
                                                   .enableMutliProcessorMode   = false,
                                                   .receiverAddress            = 0,
                                                   .receiverAddressMask        = 0,
                                                   .acceptAddrInFifo           = false,
                                                   .irdaInvertRx               = false,
                                                   .irdaEnableLowPowerReceiver = false,
                                                   .smartCardRetryOnNack       = false,
                                                   .enableCts                  = false,
                                                   .ctsPolarity                = CY_SCB_UART_ACTIVE_LOW,
                                                   .rtsRxFifoLevel             = 0,
                                                   .rtsPolarity                = CY_SCB_UART_ACTIVE_LOW,
                                                   .breakWidth                 = 0,
                                                   .rxFifoTriggerLevel         = 0,
                                                   .rxFifoIntEnableMask        = 0,
                                                   .txFifoTriggerLevel         = 0,
                                                   .txFifoIntEnableMask        = 0
                                                };

/* SCB irq confiuration */
//------------------------------------------------------------------------------
static const cy_stc_sysint_irq_t irqCfgSCB =
{
    .sysIntSrc  = CY_AUDIOSS_SPI_IRQN,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = true,
};

/* I2S irq confiuration */
//------------------------------------------------------------------------------
static cy_stc_sysint_irq_t irqCfgAudioSS =
{
    .sysIntSrc  = CY_AUDIOSS_I2S_TX_IRQN,
    .intIdx     = CPUIntIdx4_IRQn,
    .isEnabled  = true,
};

/* Global variable declaration */
//------------------------------------------------------------------------------
bool        isTransmitReadyFlag = false;
bool        isReceiveReadyFlag  = false;
volatile    uint16_t readData   = 0xDEAD;

/* SPI Interrupt Handler */
//------------------------------------------------------------------------------
void SpiInterruptHandler(void)
{
    Cy_SCB_SPI_Interrupt(CY_AUDIOSS_SPI_TYPE, &spiCtx);
}

/* Set peri devider */
//------------------------------------------------------------------------------
void SetPeripheFracDiv24_5(uint64_t targetFreq, uint64_t sourceFreq, uint8_t divNum)
{
    uint64_t temp = ((uint64_t)sourceFreq << 5ull);
    uint32_t divSetting;
    divSetting = (uint32_t)(temp / targetFreq);
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_AUDIOSS_SPI_PCLK), 
                                   CY_SYSCLK_DIV_24_5_BIT, divNum, 
                                   (((divSetting >> 5u) & 0x00000FFF) - 1u), 
                                   (divSetting & 0x0000001F));
}

/* Check for complete SPI reception */
//------------------------------------------------------------------------------
void SPI_WaitForCompletion(volatile stc_SCB_t const *base, cy_stc_scb_spi_context_t* spiCtx)
{
    uint32_t status = Cy_SCB_SPI_GetTransferStatus(base, spiCtx);
    while((status & CY_SCB_SPI_TRANSFER_ACTIVE) != 0u)
    {
        status = Cy_SCB_SPI_GetTransferStatus(base, spiCtx);
    }
}

/* Audio codec write control register */
//------------------------------------------------------------------------------
void AIC26_WriteCtlReg(en_AIC26_Registers regName, uint16_t data)
{
    un_ACI26ComPcl command;
    uint16_t rxDummyData[2];
    uint16_t txData[2];
    
    command.bitField.reserved = 0u;
    command.bitField.pg_addr  = regName;
    command.bitField.wr       = AIC26_CTROL_WRITE;

    txData[0] = command.u16;
    txData[1] = data;

    Cy_SCB_SPI_Transfer(CY_AUDIOSS_SPI_TYPE, &txData, &rxDummyData, 2u, &spiCtx);

    /* wait for completion */
    SPI_WaitForCompletion(CY_AUDIOSS_SPI_TYPE, &spiCtx);

    return;
}

/* Audio codec read control register */
//------------------------------------------------------------------------------
uint16_t AIC26_ReadCtlReg(en_AIC26_Registers regName)
{
    un_ACI26ComPcl command;
    
    uint16_t rxData[2] = {0};
    uint16_t txData[2] = {0};

    command.bitField.reserved = 0u;
    command.bitField.pg_addr  = regName;
    command.bitField.wr       = AIC26_CTROL_READ;

    txData[0] = command.u16;

    Cy_SCB_SPI_Transfer(CY_AUDIOSS_SPI_TYPE, &txData, &rxData, 2u, &spiCtx);

    /* wait for completion */
    SPI_WaitForCompletion(CY_AUDIOSS_SPI_TYPE, &spiCtx);

    return rxData[1];
}


int DST_DATA[64] ={0};
/* PCM data  */
//------------------------------------------------------------------------------
static int PCMData_1[96] =
{
    0x0000, 0x085F, 0x10B4, 0x18F8, 0x2120, 0x2924, 0x30FB, 0x389C, 0x3FFF, 0x471C, 0x4DEB, 0x5464,
    0x5A81, 0x603B, 0x658B, 0x6A6C, 0x6ED9, 0x72CB, 0x7640, 0x7934, 0x7BA2, 0x7D89, 0x7EE6, 0x7FB8,
    0x7FFF, 0x7FB8, 0x7EE6, 0x7D89, 0x7BA2, 0x7934, 0x7640, 0x72CB, 0x6ED9, 0x6A6C, 0x658B, 0x603B,
    0x5A81, 0x5464, 0x4DEB, 0x471C, 0x3FFF, 0x389C, 0x30FB, 0x2924, 0x2120, 0x18F8, 0x10B4, 0x085F,
    0x0000, 0xF7A1, 0xEF4B, 0xE708, 0xDEE0, 0xD6DC, 0xCF05, 0xC764, 0xC001, 0xB8E4, 0xB215, 0xAB9C,
    0xA57F, 0x9FC5, 0x9A75, 0x9594, 0x9127, 0x8D35, 0x89C0, 0x86CC, 0x845E, 0x8277, 0x811A, 0x8048,
    0x8001, 0x8048, 0x811A, 0x8277, 0x845E, 0x86CC, 0x89C0, 0x8D35, 0x9127, 0x9594, 0x9A75, 0x9FC5,
    0xA57F, 0xAB9C, 0xB215, 0xB8E4, 0xC001, 0xC764, 0xCF05, 0xD6DC, 0xDEE0, 0xE708, 0xEF4C, 0xF7A1,
 }; 
  

/* PCM data */
//------------------------------------------------------------------------------
#if 1
static int PCMData_2[96] =
{
    0x0000, 0x085F, 0x10B4, 0x18F8, 0x2120, 0x2924, 0x30FB, 0x389C, 0x3FFF, 0x471C, 0x4DEB, 0x5464,
    0x5A81, 0x603B, 0x658B, 0x6A6C, 0x6ED9, 0x72CB, 0x7640, 0x7934, 0x7BA2, 0x7D89, 0x7EE6, 0x7FB8,
    0x7FFF, 0x7FB8, 0x7EE6, 0x7D89, 0x7BA2, 0x7934, 0x7640, 0x72CB, 0x6ED9, 0x6A6C, 0x658B, 0x603B,
    0x5A81, 0x5464, 0x4DEB, 0x471C, 0x3FFF, 0x389C, 0x30FB, 0x2924, 0x2120, 0x18F8, 0x10B4, 0x085F,
    0x0000, 0xF7A1, 0xEF4B, 0xE708, 0xDEE0, 0xD6DC, 0xCF05, 0xC764, 0xC001, 0xB8E4, 0xB215, 0xAB9C,
    0xA57F, 0x9FC5, 0x9A75, 0x9594, 0x9127, 0x8D35, 0x89C0, 0x86CC, 0x845E, 0x8277, 0x811A, 0x8048,
    0x8001, 0x8048, 0x811A, 0x8277, 0x845E, 0x86CC, 0x89C0, 0x8D35, 0x9127, 0x9594, 0x9A75, 0x9FC5,
    0xA57F, 0xAB9C, 0xB215, 0xB8E4, 0xC001, 0xC764, 0xCF05, 0xD6DC, 0xDEE0, 0xE708, 0xEF4C, 0xF7A1,
};  
#endif

//static int PCMData_2[96] ={0x0000}; 

/* I2S data transmit handler */
//------------------------------------------------------------------------------
void TransmitI2sData(uint8_t dataSamples)
{       
    for(uint8_t data_i = 0; data_i <dataSamples; data_i++)
    {
        Cy_I2S_WriteTxData(&CY_AUDIOSS_I2S_TYPE->I2S_TX_STRUCT, DST_DATA[data_i]);
    }
   Cy_I2S_SetTxTriggerInterruptMask(&CY_AUDIOSS_I2S_TYPE->I2S_TX_STRUCT);
}
/* AudioSS i2s interrupt handler */
//------------------------------------------------------------------------------
void AudioSSInterruptHandler(void)
{
    uint32_t maskedIntrStatus;
    
    maskedIntrStatus = Cy_I2S_GetTxInterruptStatusMasked(&CY_AUDIOSS_I2S_TYPE->I2S_TX_STRUCT);

    if((maskedIntrStatus & CY_I2S_INTR_TX_FIFO_TRIGGER) != 0)
    {
        Cy_I2S_ClearTxTriggerInterruptMask(&CY_AUDIOSS_I2S_TYPE->I2S_TX_STRUCT);
        isTransmitReadyFlag = true;
    }
}

/* Main application function */
//------------------------------------------------------------------------------
int main(void)
{
    SystemInit(); 
  
    __enable_irq();
    uint32_t i, ii, srcs=8;
    uint32_t offset;

     Peripheral_Initialization();
     
    /************/
    /* SCB-UART */
    /************/
    Cy_SCB_UART_DeInit(CY_USB_SCB_TYPE);
    Cy_SCB_UART_Init(CY_USB_SCB_TYPE, &g_stc_uart_config, &g_stc_uart_context);
    Cy_SCB_UART_Enable(CY_USB_SCB_TYPE);
    
    /**************************************************/
    /*******    Clock divider setting       ***********/
    /**************************************************/
     Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_5);          //Enable hfclk5 for I2S
     Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_2);          //Enable hfclk2 for SCB
     
    /**************************************************/
    /******* Clock divider setting for CY_AUDIOSS_SPI_TYPE ***********/
    /**************************************************/
    Cy_SysClk_PeriphAssignDivider(CY_AUDIOSS_SPI_PCLK, CY_SYSCLK_DIV_24_5_BIT, DIVIDER_NO_1);
#if (CY_USE_PSVP == 1) 
    SetPeripheFracDiv24_5(SCB_SPI_CLOCK, SOURCE_CLOCK_FRQ, DIVIDER_NO_1);
#else
    SetPeripheFracDiv24_5(SCB_SPI_CLOCK, SOURCE_CLOCK_FRQ, DIVIDER_NO_1); // rmkn: to be checked
#endif
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(CY_AUDIOSS_SPI_PCLK), CY_SYSCLK_DIV_24_5_BIT, 1u);

    /**************************************/
    /* Port Setting for SPI communication */
    /**************************************/
    /* SCB MISO*/
    SPI_port_pin_cfg.driveMode = CY_GPIO_DM_HIGHZ;
    SPI_port_pin_cfg.hsiom = CY_AUDIOSS_SPI_MISO_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_SPI_MISO_PORT, CY_AUDIOSS_SPI_MISO_PIN, &SPI_port_pin_cfg);
    
    /* SCB MOSI*/
    SPI_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    SPI_port_pin_cfg.hsiom = CY_AUDIOSS_SPI_MOSI_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_SPI_MOSI_PORT, CY_AUDIOSS_SPI_MOSI_PIN, &SPI_port_pin_cfg);
    
    /* SCB CLK*/
    SPI_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    SPI_port_pin_cfg.hsiom = CY_AUDIOSS_SPI_CLK_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_SPI_CLK_PORT, CY_AUDIOSS_SPI_CLK_PIN, &SPI_port_pin_cfg);
    
    /* SCB SEL1*/
    SPI_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    SPI_port_pin_cfg.hsiom = CY_AUDIOSS_SPI_SS0_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_SPI_SS0_PORT, CY_AUDIOSS_SPI_SS0_PIN, &SPI_port_pin_cfg);    
    
    /**************************************/
    /* Port Setting for I2S communication */
    /**************************************/
    /* I2S TX SCK */
    I2S_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    I2S_port_pin_cfg.hsiom = CY_AUDIOSS_I2S_TX_SCK_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_I2S_TX_SCK_PORT, CY_AUDIOSS_I2S_TX_SCK_PIN, &I2S_port_pin_cfg);

    /* I2S TX WS */
    I2S_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    I2S_port_pin_cfg.hsiom = CY_AUDIOSS_I2S_TX_WS_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_I2S_TX_WS_PORT, CY_AUDIOSS_I2S_TX_WS_PIN, &I2S_port_pin_cfg);

    /* I2S TX SDO */
    I2S_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    I2S_port_pin_cfg.hsiom = CY_AUDIOSS_I2S_TX_SDO_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_I2S_TX_SDO_PORT, CY_AUDIOSS_I2S_TX_SDO_PIN, &I2S_port_pin_cfg);
    
    /* I2S RX SCK */
    I2S_port_pin_cfg.driveMode = CY_GPIO_DM_HIGHZ;
    I2S_port_pin_cfg.hsiom = CY_AUDIOSS_I2S_RX_SCK_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_I2S_RX_SCK_PORT, CY_AUDIOSS_I2S_RX_SCK_PIN, &I2S_port_pin_cfg);

    /* I2S RX WS */
    I2S_port_pin_cfg.driveMode = CY_GPIO_DM_HIGHZ;
    I2S_port_pin_cfg.hsiom = CY_AUDIOSS_I2S_RX_WS_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_I2S_RX_WS_PORT, CY_AUDIOSS_I2S_RX_WS_PIN, &I2S_port_pin_cfg);

    /* I2S RX SDI */
    I2S_port_pin_cfg.driveMode = CY_GPIO_DM_HIGHZ;
    I2S_port_pin_cfg.hsiom = CY_AUDIOSS_I2S_RX_SDI_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_I2S_RX_SDI_PORT, CY_AUDIOSS_I2S_RX_SDI_PIN, &I2S_port_pin_cfg);

    /********************************************/
    /* SCB initialization for SPI communication */
    /********************************************/
    Cy_SCB_SPI_Init(CY_AUDIOSS_SPI_TYPE, &SCB_SPI_cfg, &spiCtx);
    Cy_SCB_SPI_SetActiveSlaveSelect(CY_AUDIOSS_SPI_TYPE, 0);
    Cy_SCB_SPI_Enable(CY_AUDIOSS_SPI_TYPE);  
    
    /*******************************************/
    /* Interrupt setting for SPI communication */
    /*******************************************/
    Cy_SysInt_InitIRQ(&irqCfgSCB);
    Cy_SysInt_SetSystemIrqVector(irqCfgSCB.sysIntSrc, SpiInterruptHandler);
    NVIC_EnableIRQ(irqCfgSCB.intIdx);
    
    /********************************************/
    /*          initialization for I2S          */
    /********************************************/
    Cy_I2S_DeInit(CY_AUDIOSS_I2S_TYPE);
    
    /* Init i2s structure */
    Cy_I2S_Init(CY_AUDIOSS_I2S_TYPE, &config_I2S);
    
    /*******************************************/
    /* Interrupt setting for I2S communication */
    /*******************************************/
    Cy_SysInt_InitIRQ(&irqCfgAudioSS);
    Cy_SysInt_SetSystemIrqVector(irqCfgAudioSS.sysIntSrc, AudioSSInterruptHandler);
    NVIC_EnableIRQ(irqCfgAudioSS.intIdx);

     /**************************************/
    /*        ADC/DAC Setting             */
    /**************************************/

    //REGISTER 00H: ADC Control 
    ADC_Control.bitField.AVGFS      = 0x0;      //Mean filter   
    ADC_Control.bitField.Reserved   = 0x0;   
    ADC_Control.bitField.ADCR       = 0x2;      //Conversion Rate: 2MHZ   
    ADC_Control.bitField.ADAVG      = 0x0;      //No conversion averaging
    ADC_Control.bitField.RESOL      = 0x0;      //12 bit resolution
    ADC_Control.bitField.ADSCM      = 0x0;      // No SCAN  
    ADC_Control.bitField.ADST       = 0x0;      // A/D status 
    ADC_Control.bitField.Reserved_0 = 0x0;  
  
    AIC26_WriteCtlReg(PAGE1_ADC_CTL, ADC_Control.u16);
    readData = AIC26_ReadCtlReg(PAGE1_ADC_CTL);

    //register 01H: Status Register
    AIC26_WriteCtlReg(PAGE1_STATUS, 0x4000);
    readData = AIC26_ReadCtlReg(PAGE1_STATUS);
    
    //REGISTER 00H: Audio Control_1 
    AudioControl_1.bitField.ADCFS       = 0x0;  //ADsampling = Fsref/1     
    AudioControl_1.bitField.DACFS       = 0x0;  //DACsampling = Fsref/1   
    AudioControl_1.bitField.Reserved    = 0x0;  //Reserved.
    AudioControl_1.bitField.DATFM       = 0x0;  //I2S Mode
    AudioControl_1.bitField.WLEN        = 0x0;  //Word-length = 16 bit
    AudioControl_1.bitField.ADCIN       = 0x0;  //ADC Input = mic
    AudioControl_1.bitField.ADCHPF      = 0x0;  //ADC High Pass Filter disable  
    
    AIC26_WriteCtlReg(PAGE2_AUDIO_CONTROL_1, AudioControl_1.u16);
    readData =AIC26_ReadCtlReg(PAGE2_AUDIO_CONTROL_1);
         
    //REGISTER 01H: CODEC ADC Gain Control     
    ADCGainControl.bitField.ADMUT = 0x0;        //ADC channel not muted
    ADCGainControl.bitField.ADPGA = 0x0;        //ADC PGA setting()
    ADCGainControl.bitField.AGCTG = 0x0;        //AGC Target level = -5.5db
    ADCGainControl.bitField.AGCTC = 0xC;        //AGC Time Constant  
    ADCGainControl.bitField.AGCEN = 0x0;        //AGC Disable(0)
    AIC26_WriteCtlReg(PAGE2_CODEC_ADC_GAIN, ADCGainControl.u16);
    readData = AIC26_ReadCtlReg(PAGE2_CODEC_ADC_GAIN);   
     
    /* Register */  
    AIC26_WriteCtlReg(PAGE1_REFERENCE, 0x3);    
    
    /* REGISTER 02H: CODEC DAC Gain Control (microphone vol control ) */
    DACGainControl.bitField.DALMU = 0x0;        //DAC left channel not muted
    DACGainControl.bitField.DALVL = 0x0;        //
    DACGainControl.bitField.DARMU = 0x0;        //DAC right channel not muted
    DACGainControl.bitField.DARVL = 0x0; 
    
    AIC26_WriteCtlReg(PAGE2_CODEC_DAC_GAIN, DACGainControl.u16);
    readData = AIC26_ReadCtlReg(PAGE2_CODEC_DAC_GAIN);   

    /* REGISTER 05H: CODEC Power Control */
    CODECPowerControl.bitField.PWDNC    = 0x0;  //Codec Power-up 
    CODECPowerControl.bitField.Reserve  = 0x0;  //Reserved.
    CODECPowerControl.bitField.ASTPWD   = 0x1;  //Analog Sidetone powered down
    CODECPowerControl.bitField.DAODRC   = 0x1;  //audio output drive in high power mode
    CODECPowerControl.bitField.ASTPWF   = 0x1;  //Analog Sidetone Power-Down Flag(read only)
    CODECPowerControl.bitField.DAPWDN   = 0x0;  //DAC power up
    CODECPowerControl.bitField.ADPWDN   = 0x0;  //ADC power up
    CODECPowerControl.bitField.VGPWDN   = 0x1;  //Driver Virtual Ground Power up
    CODECPowerControl.bitField.ADPWDF   = 0x0;  //ADC Power-Down Flag   
    CODECPowerControl.bitField.DAPWDF   = 0x0;  //DAC Power-Down Flag
    CODECPowerControl.bitField.ADWSF    = 0x0;  //ADWS:acts as hardware power down.
    CODECPowerControl.bitField.VBIAS    = 0x1;  //VBIAS = 2.0V
    CODECPowerControl.bitField.Reserved = 0x0;  
    CODECPowerControl.bitField.EFFCTL   = 0x0;  //Disable digital audio effects filter
    CODECPowerControl.bitField.DEEMPF   = 0x0;  //Disable de-emphasis filter
    
    AIC26_WriteCtlReg(PAGE2_CODEC_POWER_CONTROL, CODECPowerControl.u16);
    readData = AIC26_ReadCtlReg(PAGE2_CODEC_POWER_CONTROL);
        
    /* REGISTER 06H: Audio Control 3 */
    AudioControl_3.bitField.DMSVOL  = 0x0;      //Left channel and right channel have independent volume controls  
    AudioControl_3.bitField.REFFS   = 0x0;      //Fsref = 48.0kHz
    AudioControl_3.bitField.DAXFM   = 0x0;      //Continuous data transfer mode
    AudioControl_3.bitField.SLVMS   = 0x0;      //AIC26 is slave codec
    AudioControl_3.bitField.DAPK2PK = 0x0; 
    AudioControl_3.bitField.ADCOVF  = 0x0;
    AudioControl_3.bitField.DALOVF  = 0x0;
    AudioControl_3.bitField.DAROVF  = 0x0;
    AudioControl_3.bitField.AGCNL   = 0x0;      //AGC noise threshold = -60db 
    AudioControl_3.bitField.CLPST   = 0x0;      //AGC Clip-steping disable(0)
    AudioControl_3.bitField.REVID   = 0x0; 
        
    AIC26_WriteCtlReg(PAGE2_AUDIO_CONTROL_3, AudioControl_3.u16);
    readData = AIC26_ReadCtlReg(PAGE2_AUDIO_CONTROL_3); 
    
    /* REGISTER 1BH: PLL Programmability */
    PLL_1BH.bitField.PLLSEL     = 0x1;          // PLL Enable.(MCLK=12MHz)       
    PLL_1BH.bitField.QVAL       = 0x2;          // Valid only if PLL is disabled.
#if (CY_I2S_USE_CLK == EXTERNAL_CLOCK)
    PLL_1BH.bitField.PVAL       = 0x2;          // P = 2;  
#else 
    PLL_1BH.bitField.PVAL       = 0x1;          // P = 1; 
#endif
    PLL_1BH.bitField.JVAL       = 0x8;          // J = 8; 

    PLL_1BH.bitField.Reserved   = 0x0;          // Reserved.
       
    AIC26_WriteCtlReg(PAGE2_PLL_PROGRAMMABILITY_0, PLL_1BH.u16);
    readData = AIC26_ReadCtlReg(PAGE2_PLL_PROGRAMMABILITY_0); 
    
    /* register 1CH: PLL */
    PLL_1CH.bitField.DVAL       = 0x0;          //D=0
    PLL_1CH.bitField.Reserved   = 0x0;          //Reserved.
    
    AIC26_WriteCtlReg(PAGE2_PLL_PROGRAMMABILITY_1, PLL_1CH.u16); 
    readData = AIC26_ReadCtlReg(PAGE2_PLL_PROGRAMMABILITY_1);
   
    /* REGISTER 1EH: Audio Control 5 */
    AudioControl_5.bitField.MAX_AGC_PGA     = 0x0; 
    AudioControl_5.bitField.AGC_NOI_DEB     = 0x0; 
    AudioControl_5.bitField.AGC_SIG_DEB     = 0x0; 
    AudioControl_5.bitField.DRV_POP_DIS     = 0x0; 
    AudioControl_5.bitField.DRV_POP_LEN     = 0x0; 
    AudioControl_5.bitField.Reserved        = 0x0;    
    
    AIC26_WriteCtlReg(PAGE2_AUDIO_CONTROL_5, AudioControl_5.u16);
    readData = AIC26_ReadCtlReg(PAGE2_AUDIO_CONTROL_5);
    
    Cy_I2S_EnableTx(&CY_AUDIOSS_I2S_TYPE->I2S_TX_STRUCT);
     /**************************************/
    /*        MIXER Setting             */
    /**************************************/
    Term_Printf("Configuring SRC channels\n");
    Cy_Mixer_Src_ChannelSelect(MIXER0_MIXER_SRC_STRUCT0,CY_MIXER_CHANNEL0,CY_MIXER_SRC_DATA_LOW);
    Cy_Mixer_Src_ChannelSelect(MIXER0_MIXER_SRC_STRUCT0,CY_MIXER_CHANNEL1,CY_MIXER_SRC_DATA_HIGH);
    Cy_Mixer_Src_ChannelSelect(MIXER0_MIXER_SRC_STRUCT1,CY_MIXER_CHANNEL0,CY_MIXER_SRC_DATA_LOW);
    Cy_Mixer_Src_ChannelSelect(MIXER0_MIXER_SRC_STRUCT1,CY_MIXER_CHANNEL1,CY_MIXER_SRC_DATA_HIGH);
    Cy_Mixer_Src_SampleFreqRatio(MIXER0_MIXER_SRC_STRUCT0,CY_MIXER_SRC_FREQ_NO_RESAMPLE);
    Cy_Mixer_Src_SampleFreqRatio(MIXER0_MIXER_SRC_STRUCT1,CY_MIXER_SRC_FREQ_NO_RESAMPLE);
    
    Cy_Mixer_Src_GainCodeSelect(MIXER0_MIXER_SRC_STRUCT0,65);
    Cy_Mixer_Src_GainCodeSelect(MIXER0_MIXER_SRC_STRUCT1,65);
    Cy_Mixer_Dst_GainCodeSelect(MIXER0_MIXER_DST_STRUCT,110);
    
    Cy_Mixer_Src_Enable(MIXER0_MIXER_SRC_STRUCT0);
    Cy_Mixer_Src_Enable(MIXER0_MIXER_SRC_STRUCT1);
    
    Term_Printf("Configuring DST \n");
    Cy_Mixer_Dst_Enable(MIXER0_MIXER_DST_STRUCT);

    
    Term_Printf("Writing 96 entries to each SRC FIFO's\n");
    for(i=0; i<srcs; i++) 
    {
        offset=0x0100*i;
        for(ii=0; ii<96; ii++) 
        {
            if((i==0)||(i==1)) 
            {
                Cy_Mixer_Src_FifoWriteData(MIXER0_MIXER_SRC_STRUCT0,PCMData_1[ii]);
                Cy_Mixer_Src_FifoWriteData(MIXER0_MIXER_SRC_STRUCT1,PCMData_2[ii]);
            } else {
                MIXER0_MIXER_SRC_STRUCT1->unSRC_FIFO_WR.stcField.u32DATA = 0x00000000; // all zeros elsewhere
                MIXER0_MIXER_SRC_STRUCT0->unSRC_FIFO_WR.stcField.u32DATA = 0x00000000; // all zeros elsewhere
            }
        }
     }
   
    Term_Printf("Activating FIFO's\n");
    Cy_Mixer_Src_Activate(MIXER0_MIXER_SRC_STRUCT0);
    Cy_Mixer_Src_Activate(MIXER0_MIXER_SRC_STRUCT1);
    Cy_Mixer_Dst_Activate(MIXER0_MIXER_DST_STRUCT);
    
    Term_Printf("Waiting for DST intr\n");
    while(MIXER0_MIXER_DST_STRUCT->unINTR_DST_MASKED.stcField.u1FIFO_TRIGGER); //(tb_mmio_read(MMIO_MIXER_CH_DST_INTR_DST)==0);  
    Term_Printf("DST intr received\n");
    
    for(i=0; i<96; i++) 
    {
       DST_DATA[i] = Cy_Mixer_Dst_FifoReadData(MIXER0_MIXER_DST_STRUCT);
       Term_Printf("DST_FIFO_RD:0x%-x\n",DST_DATA[i]);
    }
    
    TransmitI2sData(96);
    for(;;)
    {
          /* Transmit data if transmmitter is ready */
        if(isTransmitReadyFlag == true)
        {   
            isTransmitReadyFlag = false;
            TransmitI2sData(96);
        }
    }
        
}

void Peripheral_Initialization(void)
{
    cy_stc_gpio_pin_config_t    stc_port_pin_cfg_uart = {0};

    /*-----------------------------*/
    /* Port Configuration for UART */
    /*-----------------------------*/

    /* P13.0 -> scb[3].uart_rx */
    stc_port_pin_cfg_uart.driveMode = CY_GPIO_DM_HIGHZ;
    stc_port_pin_cfg_uart.hsiom     = CY_USB_SCB_UART_RX_MUX;
    Cy_GPIO_Pin_Init(CY_USB_SCB_UART_RX_PORT, CY_USB_SCB_UART_RX_PIN, &stc_port_pin_cfg_uart);

    /* P13.1 -> scb[3].uart_tx */
    stc_port_pin_cfg_uart.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    stc_port_pin_cfg_uart.hsiom     = CY_USB_SCB_UART_TX_MUX;
    Cy_GPIO_Pin_Init(CY_USB_SCB_UART_TX_PORT, CY_USB_SCB_UART_TX_PIN, &stc_port_pin_cfg_uart);

    /*-----------------------------*/
    /* Clock Configuration for UART */
    /*-----------------------------*/
    
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_2); // Enable clk_hf2

    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(CY_USB_SCB_UART_PCLK, CY_SYSCLK_DIV_24_5_BIT, 0u);

    /* Sets the 24.5 divider */
  #if (CY_USE_PSVP == 1)
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 25u,  1u);   // 115246
  #else
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 85u, 26u); // Divider 86.8125 --> 80MHz / 86.8125 / 8 (oversampling) = 115190 Hz
  #endif

    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u);
}


void Term_Printf(void *fmt, ...)
{
    va_list arg;

    /* UART Print */
    va_start(arg, fmt);
    vsprintf((char*)&g_uart_out_data[0], (char*)fmt, arg);
    Cy_SCB_UART_PutArray(CY_USB_SCB_TYPE, g_uart_out_data, strlen((char *)g_uart_out_data));
    va_end(arg);

    Cy_SysTick_DelayInUs(1000UL);
}
/* [] END OF FILE */

