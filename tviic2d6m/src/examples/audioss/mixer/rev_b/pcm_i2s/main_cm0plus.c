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
#include <stdint.h>
#include <stdbool.h>

void Cy_Cs42448_Init(void);
void Cy_Cs42448_DefaultConfig(void);

/*
     For now Only CY_I2S_EXTERNAL_CLOCK mode is functional because of the CPU board.
     This example mixes five sound source, -- 500Hz, 800Hz, 1000Hz, 1200Hz, 1600Hz sine waves,
     and outputs via I2S interface.
*/

/* User setting value */
//------------------------------------------------------------------------------
#define CY_I2S_INTERNAL_CLOCK (0)
#define CY_I2S_EXTERNAL_CLOCK (1)


/* Application Functionality Selection */
#define CY_I2S_USE_CLK      CY_I2S_EXTERNAL_CLOCK

/* End of Application Functionality Selection */

/* */
#define TDM_IP_FIFO_SIZE_MAX (128)
#define TDM_FIFO_THRESHOLD   (TDM_IP_FIFO_SIZE_MAX/4)

#if (CY_USE_PSVP == 1)  
  #define SOURCE_CLOCK_FRQ      24000000ul
#else
  #if CY_I2S_USE_CLK == CY_I2S_INTERNAL_CLOCK
    #define SOURCE_CLOCK_FRQ      196608000ul
  #else
    #define SOURCE_CLOCK_FRQ      12288000ul
  #endif
#endif

#define I2S_SAMPLING_RATE (48000ul)
#define I2S_PCM_DATA_LEN  (16ul)
#define I2S_CNANNEL_COUNT (2ul)

#define I2S_CLK_FREQ      (I2S_SAMPLING_RATE*I2S_PCM_DATA_LEN*I2S_CNANNEL_COUNT)
#define I2S_BIT_CLOCK_DIV (SOURCE_CLOCK_FRQ/I2S_CLK_FREQ)

/* PCM data to be transmitted over i2s */
//------------------------------------------------------------------------------
#define SINE_500_DATA_COUNT (96)
static const uint16_t gSine500hz[SINE_500_DATA_COUNT] =
{
    0x0000, 0x085F, 0x10B5, 0x18F9, 0x2121, 0x2925, 0x30FB, 0x389C,
    0x3FFF, 0x471C, 0x4DEB, 0x5465, 0x5A82, 0x603C, 0x658C, 0x6A6D,
    0x6ED9, 0x72CC, 0x7641, 0x7934, 0x7BA2, 0x7D89, 0x7EE7, 0x7FB9,
    0x7FFF, 0x7FB9, 0x7EE7, 0x7D89, 0x7BA3, 0x7934, 0x7641, 0x72CC,
    0x6ED9, 0x6A6D, 0x658C, 0x603C, 0x5A82, 0x5465, 0x4DEB, 0x471C,
    0x4000, 0x389D, 0x30FB, 0x2925, 0x2121, 0x18F9, 0x10B5, 0x085F,
    0x0000, 0xF7A1, 0xEF4B, 0xE708, 0xDEDF, 0xD6DB, 0xCF05, 0xC764,
    0xC001, 0xB8E4, 0xB215, 0xAB9B, 0xA57E, 0x9FC5, 0x9A74, 0x9593,
    0x9127, 0x8D34, 0x89BF, 0x86CC, 0x845E, 0x8277, 0x8119, 0x8047,
    0x8001, 0x8047, 0x8119, 0x8277, 0x845D, 0x86CC, 0x89BF, 0x8D34,
    0x9127, 0x9593, 0x9A74, 0x9FC4, 0xA57E, 0xAB9B, 0xB215, 0xB8E3,
    0xC000, 0xC763, 0xCF04, 0xD6DB, 0xDEDF, 0xE707, 0xEF4B, 0xF7A1,
};

#define SINE_800_DATA_COUNT (60)
static const uint16_t gSine800hz[SINE_800_DATA_COUNT] =
{
    0x0000, 0x0D61, 0x1A9D, 0x278E, 0x3410, 0x3FFF, 0x4B3C, 0x55A5,
    0x5F1F, 0x678D, 0x6ED9, 0x74EE, 0x79BB, 0x7D33, 0x7F4B, 0x7FFF,
    0x7F4C, 0x7D33, 0x79BB, 0x74EE, 0x6ED9, 0x678D, 0x5F1F, 0x55A5,
    0x4B3C, 0x4000, 0x3410, 0x278E, 0x1A9D, 0x0D61, 0x0000, 0xF29F,
    0xE563, 0xD873, 0xCBF1, 0xC001, 0xB4C4, 0xAA5B, 0xA0E1, 0x9873,
    0x9127, 0x8B12, 0x8645, 0x82CD, 0x80B5, 0x8001, 0x80B4, 0x82CD,
    0x8645, 0x8B12, 0x9127, 0x9873, 0xA0E1, 0xAA5A, 0xB4C4, 0xC000,
    0xCBF0, 0xD872, 0xE563, 0xF29F,
};

#define SINE_1K_DATA_COUNT (48)
static const uint16_t gSine1Khz[SINE_1K_DATA_COUNT] =
{
    0x0000, 0x10B5, 0x2121, 0x30FB, 0x3FFF, 0x4DEB, 0x5A82, 0x658C,
    0x6ED9, 0x7641, 0x7BA2, 0x7EE7, 0x7FFF, 0x7EE7, 0x7BA3, 0x7641,
    0x6ED9, 0x658C, 0x5A82, 0x4DEB, 0x4000, 0x30FB, 0x2121, 0x10B5,
    0x0000, 0xEF4B, 0xDEDF, 0xCF05, 0xC001, 0xB215, 0xA57E, 0x9A74,
    0x9127, 0x89BF, 0x845E, 0x8119, 0x8001, 0x8119, 0x845D, 0x89BF,
    0x9127, 0x9A74, 0xA57E, 0xB215, 0xC000, 0xCF04, 0xDEDF, 0xEF4B,
};

#define SINE_1200_DATA_COUNT (40)
static const uint16_t gSine1200hz[SINE_1200_DATA_COUNT] =
{
    0x0000, 0x1406, 0x278E, 0x3A1C, 0x4B3C, 0x5A82, 0x678D, 0x720C,
    0x79BB, 0x7E6C, 0x7FFF, 0x7E6C, 0x79BB, 0x720C, 0x678D, 0x5A82,
    0x4B3C, 0x3A1C, 0x278E, 0x1406, 0x0000, 0xEBFA, 0xD873, 0xC5E4,
    0xB4C4, 0xA57E, 0x9873, 0x8DF4, 0x8645, 0x8194, 0x8001, 0x8194,
    0x8645, 0x8DF4, 0x9873, 0xA57E, 0xB4C4, 0xC5E4, 0xD872, 0xEBFA,
};

#define SINE_1600_DATA_COUNT (30)
static const uint16_t gSine1600hz[SINE_1600_DATA_COUNT] =
{
    0x0000, 0x1A9D, 0x3410, 0x4B3C, 0x5F1F, 0x6ED9, 0x79BB, 0x7F4B,
    0x7F4C, 0x79BB, 0x6ED9, 0x5F1F, 0x4B3C, 0x3410, 0x1A9D, 0x0000,
    0xE563, 0xCBF1, 0xB4C4, 0xA0E1, 0x9127, 0x8645, 0x80B5, 0x80B4,
    0x8645, 0x9127, 0xA0E1, 0xB4C4, 0xCBF0, 0xE563,
};

typedef struct
{
    uint32_t  size;
    const uint16_t* pData;
    uint32_t  point;
} stc_mixer_src_data_t;
#define CY_MIXER_SRC_STC_COUNT (MIXER0_NR)
stc_mixer_src_data_t gMixerSrcData[CY_MIXER_SRC_STC_COUNT] =
{
    {  SINE_500_DATA_COUNT,  gSine500hz, 0ul },
    {  SINE_800_DATA_COUNT,  gSine800hz, 0ul },
    {   SINE_1K_DATA_COUNT,   gSine1Khz, 0ul },
    { SINE_1200_DATA_COUNT, gSine1200hz, 0ul },
    { SINE_1600_DATA_COUNT, gSine1600hz, 0ul },
};
/* Port pin config for I2S */
//------------------------------------------------------------------------------
cy_stc_gpio_pin_prt_config_t g_i2s_pin_config[] =
{
//  {                       portReg,                       pinNum, outVal,                driveMode,                            hsiom, intEdge, intMask, vtrip, slewRate, driveSel },
    {   CY_AUDIOSS_TDM0_TX_SCK_PORT,   CY_AUDIOSS_TDM0_TX_SCK_PIN,    0ul, CY_GPIO_DM_STRONG_IN_OFF,   CY_AUDIOSS_TDM0_TX_SCK_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
    { CY_AUDIOSS_TDM0_TX_FSYNC_PORT, CY_AUDIOSS_TDM0_TX_FSYNC_PIN,    0ul, CY_GPIO_DM_STRONG_IN_OFF, CY_AUDIOSS_TDM0_TX_FSYNC_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
    {    CY_AUDIOSS_TDM0_TX_SD_PORT,    CY_AUDIOSS_TDM0_TX_SD_PIN,    0ul, CY_GPIO_DM_STRONG_IN_OFF,    CY_AUDIOSS_TDM0_TX_SD_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
    {   CY_AUDIOSS_TDM0_RX_SCK_PORT,   CY_AUDIOSS_TDM0_RX_SCK_PIN,    0ul, CY_GPIO_DM_STRONG_IN_OFF,   CY_AUDIOSS_TDM0_RX_SCK_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
    { CY_AUDIOSS_TDM0_RX_FSYNC_PORT, CY_AUDIOSS_TDM0_RX_FSYNC_PIN,    0ul, CY_GPIO_DM_STRONG_IN_OFF, CY_AUDIOSS_TDM0_RX_FSYNC_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
    {    CY_AUDIOSS_TDM0_RX_SD_PORT,    CY_AUDIOSS_TDM0_RX_SD_PIN,    0ul,         CY_GPIO_DM_HIGHZ,    CY_AUDIOSS_TDM0_RX_SD_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
    {   CY_AUDIOSS_TDM0_RX_MCK_PORT,   CY_AUDIOSS_TDM0_RX_MCK_PIN,    0ul,         CY_GPIO_DM_HIGHZ,   CY_AUDIOSS_TDM0_RX_MCK_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
#if (CY_I2S_USE_CLK == CY_I2S_INTERNAL_CLOCK)
    {   CY_AUDIOSS_TDM0_TX_MCK_PORT,   CY_AUDIOSS_TDM0_TX_MCK_PIN,    0ul, CY_GPIO_DM_STRONG_IN_OFF,   CY_AUDIOSS_TDM0_TX_MCK_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
#else
    {   CY_AUDIOSS_TDM0_TX_MCK_PORT,   CY_AUDIOSS_TDM0_TX_MCK_PIN,    0ul,         CY_GPIO_DM_HIGHZ,   CY_AUDIOSS_TDM0_TX_MCK_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
#endif
};
#define I2S_PORT_NUM (sizeof(g_i2s_pin_config)/sizeof(g_i2s_pin_config[0]))

/* I2S-Tx and I2S-Rx interface configuration */
//------------------------------------------------------------------------------
cy_stc_i2s_config_t const config_I2S_TX =
{
    .txEnabled          = true,
    .txMasterMode       = CY_I2S_DEVICE_MASTER,
    .txFormat           = CY_I2S_LEFT_DELAYED,
    .txWordSize         = CY_I2S_LEN16,
    .txClkDiv           = I2S_BIT_CLOCK_DIV-1u,
#if (CY_I2S_USE_CLK == CY_I2S_INTERNAL_CLOCK)
    .txClkSel           = CY_I2S_SEL_SRSS_CLK0,
#else
    .txClkSel           = CY_I2S_SEL_RX_MCLK_IN,
#endif
    .txSckPolarity      = 0,
    .txFsyncFormat      = CY_I2S_FSYNC_FMT_CHL_PERIOD,
    .txFsyncPolarity    = 1,
    .txChannelNum       = (I2S_CNANNEL_COUNT - 1),
    .txChannelEnable    = (1ul << I2S_CNANNEL_COUNT) - 1ul,
    .txChannelSize      = (I2S_PCM_DATA_LEN - 1),
    .txFifoTriggerLevel = TDM_FIFO_THRESHOLD-1,
};

#define MIXER_SRC_FIFO_MAX (128)
#define MIXER_SRC_FIFO_TH (MIXER_SRC_FIFO_MAX/4)
cy_stc_mixer_src_config_t gMixerSrcConfig =
{
    .fsRatio  = CY_MIXER_SRC_FREQ_NO_RESAMPLE,
    .ch0sel   = CY_MIXER_SRC_DATA_LOW, // 16bit-mono
    .ch1sel   = CY_MIXER_SRC_DATA_LOW, // 16bit-mono
    .fadeCode = CY_MIXER_CODE_MUTE,
    .gainCode = 115 - 14, // -14dB(voltage ratio ->0.1995)
    .trgLevel = MIXER_SRC_FIFO_TH-1,
};

#define MIXER_DST_FIFO_MAX (64)
#define MIXER_DST_FIFO_TH (MIXER_DST_FIFO_MAX/4)
cy_stc_mixer_dst_config_t gMixerDestConfig =
{
    .fadeCode = CY_MIXER_CODE_SAME,
    .gainCode = CY_MIXER_CODE_SAME,
    .trgLevel = MIXER_DST_FIFO_TH-1,
};

/* I2S irq configuration */
//------------------------------------------------------------------------------
static cy_stc_sysint_irq_t irqCfgAudioSSTx =
{
    .sysIntSrc  = CY_AUDIOSS_TDM0_TX_IRQN,
    .intIdx     = CPUIntIdx4_IRQn,
    .isEnabled  = true,
};

static cy_stc_sysint_irq_t irqCfgAudioSSMixDst =
{
    .sysIntSrc  = mixer_0_interrupt_dst_IRQn,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = true,
};

/* I2S data transmit handler */
//------------------------------------------------------------------------------
void MixerDst_To_I2SFifo(void)
{
    uint32_t txData;
    for(uint8_t data_i = 0; data_i < MIXER_DST_FIFO_TH; data_i+=2)
    {
        txData = Cy_Mixer_Dst_FifoReadData(&MIXER0->MIXER_DST_STRUCT);
        // Same data for left and right.
        Cy_I2S_WriteTxData(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, (txData&0xFFFF));
        Cy_I2S_WriteTxData(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, (txData>>16ul));
    }
}

void UserBuffer_To_MixerSrc(uint32_t txCount)
{
    for(uint32_t dataIdx = 0; dataIdx < txCount; dataIdx++)
    {
        for(uint32_t srStcIdx = 0; srStcIdx < 5; srStcIdx++)
        {
            uint32_t point = gMixerSrcData[srStcIdx].point;
            Cy_Mixer_Src_FifoWriteData(&MIXER0->MIXER_SRC_STRUCT[srStcIdx], gMixerSrcData[srStcIdx].pData[point]);
            gMixerSrcData[srStcIdx].point = (point + 1) % gMixerSrcData[srStcIdx].size;
        }
    }
}

/* AudioSS i2s interrupt handler */
//------------------------------------------------------------------------------
void AudioSSInterruptHandlerTx(void)
{
    uint32_t TX_maskedIntrStatus;
    TX_maskedIntrStatus = Cy_I2S_GetTxInterruptStatusMasked(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);

    // only FIFO TRIGGER is acceptable
    CY_ASSERT((Cy_I2S_GetTxInterrupt(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT) & ~CY_I2S_INTR_TX_FIFO_TRIGGER) == 0);

    UserBuffer_To_MixerSrc(MIXER_DST_FIFO_TH);

    Cy_I2S_ClearTxInterrupt(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, TX_maskedIntrStatus);
}

void AudioSSMixerDestHandler(void)
{
    if(Cy_Mixer_Dst_IsTriggerInterrupt(&MIXER0->MIXER_DST_STRUCT))
    {
        MixerDst_To_I2SFifo();

        Cy_Mixer_Dst_ClearInterrupt(&MIXER0->MIXER_DST_STRUCT, CY_MIXER_DST_FIFO_TRIGGER);
    }
    else
    {
        Cy_Mixer_Dst_ClearInterrupt(&MIXER0->MIXER_DST_STRUCT, CY_MIXER_DST_FADE_OUT);
    }
}

/* Main application function */
//------------------------------------------------------------------------------
int main(void)
{
    SystemInit();

    __enable_irq();

    /* Initialize control path for audio codec */
    Cy_Cs42448_Init();

    /* Initialize & default setup for audio codec */
    Cy_Cs42448_DefaultConfig();

    /**************************************/
    /* Port Setting for I2S communication */
    /**************************************/
    Cy_GPIO_Multi_Pin_Init(g_i2s_pin_config, I2S_PORT_NUM);

    /*******************************************/
    /* Interrupt setting for I2S communication */
    /*******************************************/
    Cy_SysInt_InitIRQ(&irqCfgAudioSSTx);
    Cy_SysInt_SetSystemIrqVector(irqCfgAudioSSTx.sysIntSrc, AudioSSInterruptHandlerTx);
    NVIC_EnableIRQ(irqCfgAudioSSTx.intIdx);
    NVIC_SetPriority(irqCfgAudioSSTx.intIdx, 7);

    Cy_SysInt_InitIRQ(&irqCfgAudioSSMixDst);
    Cy_SysInt_SetSystemIrqVector(irqCfgAudioSSMixDst.sysIntSrc, AudioSSMixerDestHandler);
    NVIC_EnableIRQ(irqCfgAudioSSMixDst.intIdx);
    NVIC_SetPriority(irqCfgAudioSSTx.intIdx, 6);


    /********************************************/
    /*          initialization for I2S          */
    /********************************************/ 
    /* Init TX interface */
    Cy_I2S_Tx_Init(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, &config_I2S_TX);

    /**************************************/
    /*        MIXER Setting               */
    /**************************************/
    /* Source FIFO Initialization and Enabling */
    for(uint32_t srcMixerIdx = 0; srcMixerIdx < CY_MIXER_SRC_STC_COUNT; srcMixerIdx++)
    {
        Cy_Mixer_SourceInit(&MIXER0->MIXER_SRC_STRUCT[srcMixerIdx], &gMixerSrcConfig);
        Cy_Mixer_Src_Enable(&MIXER0->MIXER_SRC_STRUCT[srcMixerIdx]);
    }

    /* Destination FIFO Initialization and Enabling */
    Cy_Mixer_DestinationInit(&MIXER0->MIXER_DST_STRUCT, &gMixerDestConfig);
    Cy_Mixer_Dst_Enable(&MIXER0->MIXER_DST_STRUCT);

    /* push sound data to the source FIFO half of source FIFO size */
    UserBuffer_To_MixerSrc(MIXER_SRC_FIFO_MAX/2);

    /* Activate Source FIFO */
    for(uint32_t srcMixerIdx = 0; srcMixerIdx < CY_MIXER_SRC_STC_COUNT; srcMixerIdx++)
    {
        Cy_Mixer_Src_Activate(&MIXER0->MIXER_SRC_STRUCT[srcMixerIdx]);
    }

    /* Activate Destination FIFO */
    Cy_Mixer_Dst_Activate(&MIXER0->MIXER_DST_STRUCT);

    /* Push sound data to the source FIFO, destination FIFO threshold size */
    /* This time, mixing happen and destination FIFO will have enough entry to trigger interrupt */
    UserBuffer_To_MixerSrc(MIXER_DST_FIFO_TH);

    // wait for DST FIFO having enough entry
    while(Cy_Mixer_Dst_IsTriggerInterrupt(&MIXER0->MIXER_DST_STRUCT) == false);

    /* Enable destination FIFO interrupt */
    Cy_Mixer_Dst_SetInterruptMask(&MIXER0->MIXER_DST_STRUCT, CY_MIXER_DST_FIFO_TRIGGER); // <- here supposed to invoke "AudioSSMixerDestHandler".
    Cy_Mixer_Dst_SetInterruptMask(&MIXER0->MIXER_DST_STRUCT, CY_MIXER_DST_FADE_OUT);

    /********************************************/
    /*          initialization for I2S          */
    /********************************************/ 
    /* Enable I2S trigger interrupt */
    Cy_I2S_SetTxTriggerInterruptMask(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);

    /* Enable TX interface */
    Cy_I2S_EnableTx(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);

    for(;;)
    {
        static bool fadeInPhase = true;
        static uint32_t srcMixerIdx = 0;

        if(fadeInPhase == true)
        {
            /* trigger fade in */
            Cy_Mixer_SourceStartFadeIn(&MIXER0->MIXER_SRC_STRUCT[srcMixerIdx], 1023/*use 1024 times*/);
            /* wait for fade in complete */
            while(Cy_Mixer_SourceHasFadeInCompleted(&MIXER0->MIXER_SRC_STRUCT[srcMixerIdx]) == false);
        }
        else // fade out phase
        {
            /* trigger fade out */
            Cy_Mixer_SourceStartFadeOut(&MIXER0->MIXER_SRC_STRUCT[srcMixerIdx], 1023/*use 1024 times*/, false);
            /* wait for fade out complete */
            while(Cy_Mixer_SourceHasFadeOutCompleted(&MIXER0->MIXER_SRC_STRUCT[srcMixerIdx]) == false);
        }

        srcMixerIdx = (srcMixerIdx+1) % CY_MIXER_SRC_STC_COUNT;
        if(srcMixerIdx == 0)
        {
            fadeInPhase = !fadeInPhase;
        }
    }
}

/*******************************************************************************
* Function Name: Cy_Cs42448_DefaultConfig
****************************************************************************//**
*
* \brief
* Function to initialize default settings for audio codec CS42448.
*
* \param
* none
*
* \return 
* none
*
* \note
* SCB3 is fixed for the audio codec control path.
* 
*******************************************************************************/
void Cy_Cs42448_DefaultConfig(void)
{
    uint8_t readRegData = 0;

    cy_un_cs42448_reg_powerCtl_t        powerCtl        = {.u8  = 0u};
    powerCtl.u8 = 0; // set all power down function disable
    Cy_Cs42448_WriteCtrReg(CY_CS42448_POWER_CTRL_REGISTER, powerCtl.u8);
    readRegData = Cy_Cs42448_ReadCtrReg(CY_CS42448_POWER_CTRL_REGISTER);
    CY_ASSERT(powerCtl.u8 == readRegData);

    cy_un_cs42448_reg_funcMode_t        funcMode        = {.u8  = 0u};
    funcMode.bitField.DACFM = 3; // Slave mode: Auto-detect sample rates
    funcMode.bitField.ADCFM = 3; // Slave mode: Auto-detect sample rates
    funcMode.bitField.MFreq = 0; // 2.0480MHz to 25.6000MHz
    Cy_Cs42448_WriteCtrReg(CY_CS42448_FUNCTIONAL_MODE_REGISTER, funcMode.u8);
    readRegData = Cy_Cs42448_ReadCtrReg(CY_CS42448_FUNCTIONAL_MODE_REGISTER);
    CY_ASSERT(funcMode.u8 == readRegData);

    cy_un_cs42448_reg_interfaceFmt_t    interfaceFmt    = {.u8  = 0u};
    interfaceFmt.bitField.Freeze = 0;
    interfaceFmt.bitField.AUXDIF = 1; // I2S (does not matter)
    interfaceFmt.bitField.DACDIF = 1; // I2S, up to 24-bit data
    interfaceFmt.bitField.ADCDIF = 1; // I2S, up to 24-bit data
    Cy_Cs42448_WriteCtrReg(CY_CS42448_INTERFACE_CTRL_REGISTER, interfaceFmt.u8);
    readRegData = Cy_Cs42448_ReadCtrReg(CY_CS42448_INTERFACE_CTRL_REGISTER);
    CY_ASSERT(interfaceFmt.u8 == readRegData);

    sv_un_cs42448_reg_adcDacCtl_t       adcDacCtl       = {.u8  = 0u};
    adcDacCtl.bitField.DACDEM = 0; // De-Emphasis Enabled (Auto-Detect Fs)
    Cy_Cs42448_WriteCtrReg(CY_CS42448_ADC_CTRL_REGISTER, adcDacCtl.u8);
    readRegData = Cy_Cs42448_ReadCtrReg(CY_CS42448_ADC_CTRL_REGISTER);
    CY_ASSERT(adcDacCtl.u8 == readRegData);

    cy_un_cs42448_reg_transCtl_t        transitionCtl   = {.u8  = 0u};
    transitionCtl.bitField.DACSZC = 1;
    transitionCtl.bitField.ADCSZC = 1;
    Cy_Cs42448_WriteCtrReg(CY_CS42448_TRANSITION_CTRL_REGISTER, transitionCtl.u8);
    readRegData = Cy_Cs42448_ReadCtrReg(CY_CS42448_TRANSITION_CTRL_REGISTER);
    CY_ASSERT(transitionCtl.u8 == readRegData);

    cy_un_cs42448_reg_dacMuteCtl_t      dacMuteCtl      = {.u8  = 0u};
    dacMuteCtl.bitField.aoutmute = 0; // all DAC auto mute disable
    Cy_Cs42448_WriteCtrReg(CY_CS42448_DAC_MUTE_CTRL_REGISTER, dacMuteCtl.u8);
    readRegData = Cy_Cs42448_ReadCtrReg(CY_CS42448_DAC_MUTE_CTRL_REGISTER);
    CY_ASSERT(dacMuteCtl.u8 == readRegData);

    cy_un_cs42448_reg_ain1VolCtl_t      ain1VolCtl      = {.u8  = 0u};
    ain1VolCtl.bitField.ainvol = 0; // 0 dB
    Cy_Cs42448_WriteCtrReg(CY_CS42448_VOLUME_CTRL_AIN_1_REGISTER, ain1VolCtl.u8);
    readRegData = Cy_Cs42448_ReadCtrReg(CY_CS42448_VOLUME_CTRL_AIN_1_REGISTER);
    CY_ASSERT(ain1VolCtl.u8 == readRegData);

    cy_un_cs42448_reg_aout1VolCtl_t     aout1VolCtl     = {.u8  = 0u};
    aout1VolCtl.bitField.aoutvol = 0; // 0dB
    Cy_Cs42448_WriteCtrReg(CY_CS42448_VOLUME_CTRL_AOUT_1_REGISTER, aout1VolCtl.u8);
    readRegData = Cy_Cs42448_ReadCtrReg(CY_CS42448_VOLUME_CTRL_AOUT_1_REGISTER);
    CY_ASSERT(aout1VolCtl.u8 == readRegData);
}
/* [] END OF FILE */
