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
     CY_I2S_TX_1K_SINE mode : It will output 1K sine wave to left and right.
     CY_I2S_RX_TX_LOOP_BACK mode : Left output 1K sine wave. and
                                   Right output data which has been received from the CODEC.
                                   If you don't have proper microphone. Please connect the left output to
                                   CODEC Analog input. Then the sine wave from left output will be copied and
                                   output from the right output.
*/

/* User setting value */
//------------------------------------------------------------------------------
#define CY_I2S_INTERNAL_CLOCK (0)
#define CY_I2S_EXTERNAL_CLOCK (1)

#define CY_I2S_RX_TX_LOOP_BACK (0)
#define CY_I2S_TX_1K_SINE      (1)

/* Application Functionality Selection */
#define CY_I2S_USE_CLK      CY_I2S_EXTERNAL_CLOCK
#define CY_I2S_APP_FUNCTION CY_I2S_TX_1K_SINE

/* End of Application Functionality Selection */

/* */
#define TDM_IP_FIFO_SIZE_MAX (128)
#define TDM_FIFO_THRESHOLD   (TDM_IP_FIFO_SIZE_MAX/2)

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
#define SINE_1K_DATA_COUNT (48)
static uint16_t gSine1Khz[SINE_1K_DATA_COUNT] =
{
    0x0000, 0x10B5, 0x2121, 0x30FB, 0x3FFF, 0x4DEB, 0x5A82, 0x658C,
    0x6ED9, 0x7641, 0x7BA2, 0x7EE7, 0x7FFF, 0x7EE7, 0x7BA3, 0x7641,
    0x6ED9, 0x658C, 0x5A82, 0x4DEB, 0x4000, 0x30FB, 0x2121, 0x10B5,
    0x0000, 0xEF4B, 0xDEDF, 0xCF05, 0xC001, 0xB215, 0xA57E, 0x9A74,
    0x9127, 0x89BF, 0x845E, 0x8119, 0x8001, 0x8119, 0x845D, 0x89BF,
    0x9127, 0x9A74, 0xA57E, 0xB215, 0xC000, 0xCF04, 0xDEDF, 0xEF4B,
};

static uint16_t GetSine1KData()
{
    static uint32_t txBufPoint = 0;
    uint16_t tmp = gSine1Khz[txBufPoint];
    txBufPoint = (txBufPoint+1)%SINE_1K_DATA_COUNT;
    return tmp;
}

#if CY_I2S_APP_FUNCTION == CY_I2S_RX_TX_LOOP_BACK
// Sound Ring Data
#define SOUND_RING_BUF_SIZE (1024ul)
uint16_t g_SoundBuffer[SOUND_RING_BUF_SIZE] = { 0ul };
uint32_t g_SoundDataAmount = (SOUND_RING_BUF_SIZE/ 2ul); // Note: half of buffer is filled with "0" as a initial state
uint32_t g_SoundBufferTail = 0ul;
uint32_t g_SoundBufferHead = (SOUND_RING_BUF_SIZE/ 2ul); // Note: half of buffer is filled with "0" as a initial state

static void SoundRingBuffer_Push(uint16_t data)
{
    CY_ASSERT(g_SoundDataAmount < SOUND_RING_BUF_SIZE); // Check buffer overflow

    g_SoundBuffer[g_SoundBufferHead] = data;
    g_SoundBufferHead = (g_SoundBufferHead + 1ul) % SOUND_RING_BUF_SIZE;
    g_SoundDataAmount++;
}

static uint16_t SoundRingBuffer_Pop(void)
{
    CY_ASSERT(g_SoundDataAmount > 0ul); // Check buffer underflow

    uint32_t data = g_SoundBuffer[g_SoundBufferTail];
    g_SoundBufferTail = (g_SoundBufferTail + 1ul) % SOUND_RING_BUF_SIZE;
    g_SoundDataAmount--;

    return data;
}
#endif

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

cy_stc_i2s_config_t const config_I2S_RX =
{
    .rxEnabled          = true,
    .rxMasterMode       = CY_I2S_DEVICE_MASTER,
    .rxFormat           = CY_I2S_LEFT_DELAYED,
    .rxWordSize         = CY_I2S_LEN16,
    .rxClkDiv           = I2S_BIT_CLOCK_DIV-1u,
#if (CY_I2S_USE_CLK == CY_I2S_INTERNAL_CLOCK)
    .rxClkSel           = CY_I2S_SEL_SRSS_CLK0,
#else
    .rxClkSel           = CY_I2S_SEL_RX_MCLK_IN,
#endif
    .rxSckPolarity      = 0, 
    .rxFsyncFormat      = CY_I2S_FSYNC_FMT_CHL_PERIOD,
    .rxFsyncPolarity    = 1,
    .rxChannelNum       = (I2S_CNANNEL_COUNT - 1),
    .rxChannelEnable    = (1ul << I2S_CNANNEL_COUNT) - 1ul,
    .rxChannelSize      = (I2S_PCM_DATA_LEN - 1),
    .rxLateSampleDelay  = CY_I2S_LATE_SAMPLE_RISING,
    .rxLateCaptureDelay = CY_I2S_LATE_CAPT_EXTRA_DELAY_0,
    .rxWsExtension      = CY_I2S_WS_EXTN_SIGN,
    .rxFifoTriggerLevel = TDM_FIFO_THRESHOLD-1,
};
/* I2S irq configuration */
//------------------------------------------------------------------------------
static cy_stc_sysint_irq_t irqCfgAudioSSTx =
{
    .sysIntSrc  = CY_AUDIOSS_TDM0_TX_IRQN,
    .intIdx     = CPUIntIdx4_IRQn,
    .isEnabled  = true,
};

static cy_stc_sysint_irq_t irqCfgAudioSSRx =
{
    .sysIntSrc  = CY_AUDIOSS_TDM0_RX_IRQN,
    .intIdx     = CPUIntIdx4_IRQn,
    .isEnabled  = true,
};

/* Global variable declaration */
//------------------------------------------------------------------------------
bool isTransmitReadyFlag = false;
bool isReceiveReadyFlag = false;

/* I2S data transmit handler */
//------------------------------------------------------------------------------
void TransmitI2sData(void)
{
    uint32_t txData;
    for(uint8_t data_i = 0; data_i < TDM_FIFO_THRESHOLD; data_i+=2)
    {
        txData = GetSine1KData();
        // Same data for left and right.
        Cy_I2S_WriteTxData(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, txData);

#if CY_I2S_APP_FUNCTION == CY_I2S_RX_TX_LOOP_BACK
        txData = SoundRingBuffer_Pop();
#endif
        Cy_I2S_WriteTxData(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, txData);
    }
}

/* I2S data receive handler */
//------------------------------------------------------------------------------
void ReceiveI2sData(void)
{
    volatile uint32_t rxData;
    for(uint8_t data_i = 0; data_i < TDM_FIFO_THRESHOLD; data_i+=2)
    {
        rxData = Cy_I2S_ReadRxData(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT);
#if CY_I2S_APP_FUNCTION == CY_I2S_RX_TX_LOOP_BACK
        SoundRingBuffer_Push(rxData);
#endif
        Cy_I2S_ReadRxData(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT); // throw garbage
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

    TransmitI2sData();

    Cy_I2S_ClearTxInterrupt(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, TX_maskedIntrStatus);
}

void AudioSSInterruptHandlerRx(void)
{
    uint32_t RX_maskedIntrStatus;
    RX_maskedIntrStatus = Cy_I2S_GetRxInterruptStatusMasked(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT);

    // only FIFO TRIGGER is acceptable
    CY_ASSERT((Cy_I2S_GetRxInterrupt(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT) & ~CY_I2S_INTR_RX_FIFO_TRIGGER) == 0);

    ReceiveI2sData();

    Cy_I2S_ClearRxInterrupt(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT, RX_maskedIntrStatus);
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
    Cy_SysInt_InitIRQ(&irqCfgAudioSSRx);
    Cy_SysInt_SetSystemIrqVector(irqCfgAudioSSRx.sysIntSrc, AudioSSInterruptHandlerRx);

    NVIC_EnableIRQ(irqCfgAudioSSTx.intIdx);

    /********************************************/
    /*          initialization for I2S          */
    /********************************************/ 
    /* Init TX interface */
    Cy_I2S_Tx_Init(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, &config_I2S_TX);
    TransmitI2sData(); // Prepare first data into FIFO before enable I2S TX
    Cy_I2S_SetTxTriggerInterruptMask(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);

    /* Enable TX interface */
    Cy_I2S_EnableTx(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);

    /* Enable RX interface */
#if CY_I2S_APP_FUNCTION == CY_I2S_RX_TX_LOOP_BACK
    /* Init RX interface */
    Cy_I2S_Rx_Init(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT, &config_I2S_RX);
    Cy_I2S_SetRxTriggerInterruptMask(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT);

    Cy_I2S_EnableRx(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT);
#endif
    for(;;);
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
