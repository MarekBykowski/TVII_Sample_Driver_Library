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

#define Wav_used  1 /* if you want to use wav data please write 1 */

/* User setting for clock and  */
//------------------------------------------------------------------------------
#define INTERNAL_CLOCK          0
#define EXTERNAL_CLOCK          1
#define CY_I2S_USE_CLK          INTERNAL_CLOCK


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


/*** Poll command :Codec Control ***/
//------------------------------------------------------------------------------
typedef union 
{
    uint16_t u16;
    struct
    {
        uint16_t reserved: 5;
        uint16_t pg_addr:  10;
        uint16_t wr:       1;
    } bitField;
} un_ACI26ComPcl;

/*** Page1: REGISTER 00H: ADC Control ***/
//------------------------------------------------------------------------------
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t AVGFS:     1; //Average Filter select  
        uint16_t Reserved:  3; //Reserved
        uint16_t ADCR:      2; //Conversion Rate Control.
        uint16_t ADAVG:     2; //Converter Averaging Control.        
        uint16_t RESOL:     2; //Resolution Control.
        uint16_t ADSCM:     4; //A/D Scan Mode.
        uint16_t ADST:      1; //A/D status
        uint16_t Reserved_0:1; //Reserved.
   }bitField;
} un_ADCControl;
un_ADCControl ADC_Control;

/**** Page2:REGISTER 00H: Audio Control_1 ****/
//------------------------------------------------------------------------------
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t ADCFS:     3; //ADC Sampling Rate 
        uint16_t DACFS:     3; //DAC Sampling Rate
        uint16_t Reserved:  2; //Reserved
        uint16_t DATFM:     2; //Digital Data Format
        uint16_t WLEN:      2; //Codec Word Length.
        uint16_t ADCIN:     2; //ADC Input Mux
        uint16_t ADCHPF:    2; //ADC High Pass Filter             
    }bitField;
} un_AudioControl_1;
un_AudioControl_1 AudioControl_1;

/**** REGISTER 01H: CODEC ADC Gain Control ****/
//------------------------------------------------------------------------------
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t AGCEN:     1; //AGC Enable
        uint16_t AGCTC:     4; //AGC Time Constant
        uint16_t AGCTG:     3; //AGC Target Level
        uint16_t ADPGA:     7; //ADC PGA Settings
        uint16_t ADMUT:     1; //ADC Channel Mute                  
    }bitField;
} un_ADCGainControl;
un_ADCGainControl ADCGainControl;

/**** REGISTER 02H: CODEC DAC Gain Control ****/
//------------------------------------------------------------------------------
typedef union
{
    uint16_t u16; 
    struct
    {
        uint16_t DARVL:     7; //DAC Right Channel Muted
        uint16_t DARMU:     1; //DAC Right Channel Muted
        uint16_t DALVL:     7; //DAC Left Channel Muted
        uint16_t DALMU:     1; //DAC Left Channel Muted
    }bitField;
} un_DACGainControl;
un_DACGainControl DACGainControl;

/**** REGISTER 05H: CODEC Power Control ****/
//------------------------------------------------------------------------------
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t DEEMPF:     1; //De_Emphasis Filter Enable
        uint16_t EFFCTL:     1; //Digital Audio Effects Filter Control
        uint16_t Reserved:   2; //Reserved. Write only 00 into this location.
        uint16_t VBIAS:      1; //VBIAS Voltage        
        uint16_t ADWSF:      1; //ADWS Pin Function
        uint16_t DAPWDF:     1; //DAC Power-Down Flag
        uint16_t ADPWDF:     1; //ADC Power-Down Flag
        uint16_t VGPWDN:     1; //Driver Virtual Ground Power Down 
        uint16_t ADPWDN:     1; //ADC Power-Down Control
        uint16_t DAPWDN:     1; //DAC Power-Down Control
        uint16_t ASTPWF:     1; //Analog Sidetone Power-Down Flag
        uint16_t DAODRC:     1; //Audio Output Driver Control
        uint16_t ASTPWD:     1; //Analog Sidetone Power-down Control
        uint16_t Reserve:    1; //Reserved (During read the value of this bit is 0. Write only 0 into this location.)       
        uint16_t PWDNC:      1; //Codec Power-Down Control            
    }bitField;
} un_DACPowerControl;
un_DACPowerControl CODECPowerControl;

/**** REGISTER 06H: Audio Control 3 ****/
//------------------------------------------------------------------------------
typedef union
{
    uint16_t u16;
    struct
    {  
        uint16_t REVID:     3; //Reserved  
        uint16_t CLPST:     1; //AGC Clip Stepping Enable
        uint16_t AGCNL:     2; //AGC Noise Threshold.
        uint16_t DAROVF:    1; //DAC Right Channel Overflow Flag ( Read Only )
        uint16_t DALOVF:    1; //DAC Left Channel Overflow Flag ( Read Only )
        uint16_t ADCOVF:    1; //ADC Channel Overflow Flag ( Read Only )
        uint16_t DAPK2PK:   2; //DAC Max Output Signal Swing and Common Mode Voltage
        uint16_t SLVMS:     1; //Codec Master Slave Selection
        uint16_t DAXFM:     1; //Master Transfer Mode
        uint16_t REFFS:     1; //Reference Sampling Rate.
        uint16_t DMSVOL:    2; //DAC Channel Master Volume Control       
    }bitField;
} un_AudioControl3;
un_AudioControl3 AudioControl_3;

/**** REGISTER 1BH: PLL Programmability ****/
//------------------------------------------------------------------------------
typedef union
{
    uint16_t u16;
    struct
    {        
        uint16_t Reserved:  2; //Reserved (write only 00)             
        uint16_t JVAL:      6; //J value. Valid only if PLL is enabled.
        uint16_t PVAL:      3; //P value. Valid when PLL is enabled
        uint16_t QVAL:      4; //Q value. Valid only if PLL is disabled.
        uint16_t PLLSEL:    1; //PLL Enable
    }bitField;
} un_PLL_Programmability;
un_PLL_Programmability PLL_1BH;

/**** Register 1CH: PLL2 ***/
//------------------------------------------------------------------------------
typedef union
{
    uint16_t u16;
    struct
    {        
        uint16_t Reserved:  2; //Reserved (write only 00)             
    uint16_t DVAL:     14; //D value
    }bitField;
} un_PLL_Programmability2;
un_PLL_Programmability2 PLL_1CH;

/**** REGISTER 1DH: Audio Control 4 ****/
//------------------------------------------------------------------------------
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t PGID:                  2; //Read only
        uint16_t DAC_POP_RED_SET2:      2; //DAC POP Reduction Setting 2
        uint16_t DAC_POP_RED_SET1:      1; //DAC POP Reduction Setting 1
        uint16_t DAC_POP_RED:           1; //DAC POP Reduction Enable
        uint16_t SHCKT_FLAG:            1; //Short Circuit Detected Flag
        uint16_t SHCKT_PD:              1; //Power Down Drivers if Short Circuit Detected
        uint16_t SHCKT_DIS:             1; //Disable Short Circuit Detection
        uint16_t AGC_HYST:              2; //AGC Hysteresis Control
        uint16_t Reserved:              1; //Reserved
        uint16_t DSTPD:                 1; //Digital Sidetone Zero Cross Control
        uint16_t ASSTPD:                1; //Analog Sidetone Soft-Stepping Control
        uint16_t DASTPD:                1; //DAC PGA Soft-Stepping Control
        uint16_t ASTPD:                 1; //ADC PGA Soft-Stepping Control       
   }bitField;
} un_AudioControl4;
un_AudioControl4 AudioControl_4;


/**** REGISTER 1EH: Audio Control 5 ****/
//------------------------------------------------------------------------------
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t Reserved:      1; // Reserved. Do not write 1 to this location.
        uint16_t DRV_POP_LEN:   1; //Audio Output Driver POP Reduction Duration
        uint16_t DRV_POP_DIS:   1; //Audio Output Driver POP Reduction Enable
        uint16_t AGC_SIG_DEB:   3; //AGC Debounce Time for Silence Mode to Speech Mode Transition
        uint16_t AGC_NOI_DEB:   3; //AGC Debounce Time for Speech Mode to Silence Mode Transition
        uint16_t MAX_AGC_PGA:   7; //MAX Input Gain Applicable for AGC
    }bitField;
} un_AudioControl5;
un_AudioControl5 AudioControl_5;

/**** Audio command type ****/
//------------------------------------------------------------------------------
typedef enum
{
    AIC26_CTROL_WRITE = (0u),
    AIC26_CTROL_READ  = (1u),
} en_ACI26_WR;

/**** Audio codec commands ****/
//------------------------------------------------------------------------------
typedef enum
{
    PAGE0_BAT1                   = (0x05),
    PAGE0_BAT2                   = (0x06),
    PAGE0_AUX                    = (0x07),
    PAGE0_TEMP1                  = (0x09),
    PAGE0_TEMP2                  = (0x0A),
    PAGE1_ADC_CTL                = (0x40),
    PAGE1_STATUS                 = (0x41),
    PAGE1_REFERENCE              = (0x43),
    PAGE1_RESET                  = (0x44),
    PAGE2_AUDIO_CONTROL_1        = (0x80),
    PAGE2_CODEC_ADC_GAIN         = (0x81),
    PAGE2_CODEC_DAC_GAIN         = (0x82),
    PAGE2_CODEC_SIDETONE         = (0x83),
    PAGE2_AUDIO_CONTROL_2        = (0x84),
    PAGE2_CODEC_POWER_CONTROL    = (0x85),
    PAGE2_AUDIO_CONTROL_3        = (0x86),
    PAGE2_FILTER_COEFFICIENTS_0  = (0x87),
    PAGE2_FILTER_COEFFICIENTS_1  = (0x88),
    PAGE2_FILTER_COEFFICIENTS_2  = (0x89),
    PAGE2_FILTER_COEFFICIENTS_3  = (0x8A),
    PAGE2_FILTER_COEFFICIENTS_4  = (0x8B),
    PAGE2_FILTER_COEFFICIENTS_5  = (0x8C),
    PAGE2_FILTER_COEFFICIENTS_6  = (0x8D),
    PAGE2_FILTER_COEFFICIENTS_7  = (0x8E),
    PAGE2_FILTER_COEFFICIENTS_8  = (0x8F),
    PAGE2_FILTER_COEFFICIENTS_9  = (0x90),
    PAGE2_FILTER_COEFFICIENTS_10 = (0x91),
    PAGE2_FILTER_COEFFICIENTS_11 = (0x92),
    PAGE2_FILTER_COEFFICIENTS_12 = (0x93),
    PAGE2_FILTER_COEFFICIENTS_13 = (0x94),
    PAGE2_FILTER_COEFFICIENTS_14 = (0x95),
    PAGE2_FILTER_COEFFICIENTS_15 = (0x96),
    PAGE2_FILTER_COEFFICIENTS_16 = (0x97),
    PAGE2_FILTER_COEFFICIENTS_17 = (0x98),
    PAGE2_FILTER_COEFFICIENTS_18 = (0x99),
    PAGE2_FILTER_COEFFICIENTS_19 = (0x9A),
    PAGE2_PLL_PROGRAMMABILITY_0  = (0x9B),
    PAGE2_PLL_PROGRAMMABILITY_1  = (0x9C),
    PAGE2_AUDIO_CONTROL_4        = (0x9D),
    PAGE2_AUDIO_CONTROL_5        = (0x9E),
} en_AIC26_Registers;

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

#if (Wav_used == 1)

    // Refer to wave.h
    #include "wav.h"    
#else
    /* PCM data to be transmitted over i2s */
    //------------------------------------------------------------------------------
    static int DATA[96] =
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
    #define DATA_NUM_PER_PERIOD (sizeof(DATA) / sizeof(uint32_t))
    int size = 96;

#endif

/* I2S-Tx and I2S-Rx interface confiuration */
//------------------------------------------------------------------------------
#if (CY_I2S_USE_CLK == INTERNAL_CLOCK)
cy_stc_i2s_config_t const config_I2S =
{
    .txEnabled          = true,
    .txMasterMode       = CY_I2S_DEVICE_MASTER,
    .txFormat           = CY_I2S_LEFT_DELAYED, 
    .txWordSize         = CY_I2S_LEN16,
    .txClkDiv           = 7u,                   // Divided by 6 -- 4MHz
    .txClkSel           = CY_I2S_SEL_SRSS_CLK0,
    .txSckPolarity      = 0,
    .txWsPolarity       = 0,
    .txChannel0Enable   = true,
    .txChannel1Enable   = true,
    .txChannelSize      = 15,                   // 16 bit
    .txFifoTriggerLevel = 63u,    
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
#else
cy_stc_i2s_config_t const config_I2S =
{
    .txEnabled          = true,
    .txMasterMode       = CY_I2S_DEVICE_MASTER,
    .txFormat           = CY_I2S_LEFT_DELAYED,
    .txWordSize         = CY_I2S_LEN16,
    .txClkDiv           = 3u,                   // Divided by 8
    .txClkSel           = CY_I2S_SEL_RX_MCLK_IN,
    .txSckPolarity      = 0,
    .txWsPolarity       = 0,
    .txChannel0Enable   = true,
    .txChannel1Enable   = true,
    .txChannelSize      = 15,                   // 16 bit
    .txFifoTriggerLevel = 63u,
    .rxEnabled          = true,
    .rxMasterMode       = CY_I2S_DEVICE_SLAVE,
    .rxFormat           = CY_I2S_LEFT_DELAYED,
    .rxWordSize         = CY_I2S_LEN16,
    .rxSignExtension    = 0,
    .rxClkDiv           = 3u,
    .rxClkSel           = CY_I2S_SEL_SRSS_CLK0,
    .rxSckPolarity      = 0,
    .rxWsPolarity       = 0,
    .rxLateSampleDelay  = 1,
    .rxChannel0Enable   = true,
    .rxChannel1Enable   = true,
    .rxChannelSize      = 15,                   // 16 bit
    .rxFifoTriggerLevel = 63,
};
#endif  // CY_I2S_USE_CLK

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
volatile    uint16_t readData   = 0xDEAD;

uint32_t NUM = 0;
uint32_t PERIOD = 0;
    

/* I2S data transmit handler */
//------------------------------------------------------------------------------
void TransmitI2sData()
{
    PERIOD = PERIOD + 1; 
    for(NUM; NUM < PERIOD ; NUM++)
    {  
        Cy_I2S_WriteTxData(&CY_AUDIOSS_I2S_TYPE->I2S_TX_STRUCT, DATA[NUM]);           
    }
    
    /* Reset index to 0 on overflow. Value here is derived from array size in wav.h */
    if(NUM >= size && PERIOD >= size) 
    {
        NUM = 0;
        PERIOD = 0;
    }
    Cy_I2S_ClearTxInterrupt(&CY_AUDIOSS_I2S_TYPE->I2S_TX_STRUCT,CY_I2S_INTR_TX_FIFO_TRIGGER); 
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
        
        TransmitI2sData();
    }
    
    if((maskedIntrStatus & CY_I2S_INTR_TX_FIFO_UNDERFLOW) != 0)
    {
      
        Cy_I2S_ClearTxInterrupt(&CY_AUDIOSS_I2S_TYPE->I2S_TX_STRUCT,CY_I2S_INTR_TX_FIFO_UNDERFLOW);
    }
    
    if((maskedIntrStatus & CY_I2S_INTR_TX_FIFO_OVERFLOW) != 0)
    {
        Cy_I2S_ClearTxInterrupt(&CY_AUDIOSS_I2S_TYPE->I2S_TX_STRUCT,CY_I2S_INTR_TX_FIFO_OVERFLOW);
    }

}

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

/* Main application function */
//------------------------------------------------------------------------------
int main(void)
{
    SystemInit(); 
  
    __enable_irq();
    
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
    /* I2S MCLK */ /* Setting MCLK GPIO to output here is optional */
    I2S_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    I2S_port_pin_cfg.hsiom = CY_AUDIOSS_I2S_TX_MCLK_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_I2S_TX_MCLK_PORT, CY_AUDIOSS_I2S_TX_MCLK_PIN, &I2S_port_pin_cfg);
    
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
    
    /* I2S IF CLK */
#if (CY_I2S_USE_CLK == EXTERNAL_CLOCK)
    I2S_port_pin_cfg.driveMode = CY_GPIO_DM_HIGHZ;
    I2S_port_pin_cfg.hsiom = CY_AUDIOSS_CLK_I2S_IF_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_CLK_I2S_IF_PORT, CY_AUDIOSS_CLK_I2S_IF_PIN, &I2S_port_pin_cfg);
#endif
    
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
    Cy_I2S_SetTxInterruptMask(&CY_AUDIOSS_I2S_TYPE->I2S_TX_STRUCT,  CY_I2S_INTR_TX_FIFO_TRIGGER | CY_I2S_INTR_TX_FIFO_OVERFLOW | CY_I2S_INTR_TX_FIFO_UNDERFLOW);
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
    TransmitI2sData();
    
    for(;;);

}

/* [] END OF FILE */
