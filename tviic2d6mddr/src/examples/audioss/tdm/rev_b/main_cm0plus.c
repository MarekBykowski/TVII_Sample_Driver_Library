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

/*
     For now Only CY_TDM_EXTERNAL_CLOCK mode is functional because of HW issue.
     CY_TDM_TX_1K_SINE mode 		: It will output 1K sine wave to left and right.
     						  		Please check the signal at pin R714_1.

     CY_TDM_RX_TX_LOOP_BACK mode 	: Left output 1K sine wave. and
                                   	Right output data which has been received from the CODEC.
                                   	If you don't have proper microphone. Please connect the left output to
                                   	CODEC Analog input. Then the sine wave from left output will be copied and
                                   	output from the right output.
									Please short R714_1 and R727_2 and check the signal at pin R714_1, R715_1.
*/

/* User setting value */
//------------------------------------------------------------------------------
#define CY_TDM_INTERNAL_CLOCK   (0)
#define CY_TDM_EXTERNAL_CLOCK   (1)

#define CY_TDM_RX_TX_LOOP_BACK  (0)
#define CY_TDM_TX_1K_SINE       (1)

/* Application Functionality Selection */
#define CY_TDM_USE_CLK          CY_TDM_EXTERNAL_CLOCK
#define CY_TDM_APP_FUNCTION     CY_TDM_TX_1K_SINE

/* End of Application Functionality Selection */

/* Clock Selection Macros */
//------------------------------------------------------------------------------
#define TDM_IP_FIFO_SIZE_MAX    (128)
#define TDM_FIFO_THRESHOLD      (TDM_IP_FIFO_SIZE_MAX/2)

#if (CY_USE_PSVP == 1)  
  #define SOURCE_CLOCK_FRQ      24000000ul
#else
  #if CY_TDM_USE_CLK == CY_TDM_INTERNAL_CLOCK
    #define SOURCE_CLOCK_FRQ    196608000ul
  #else
    #define SOURCE_CLOCK_FRQ    12288000ul
  #endif
#endif

/* Smaple rate and clock setup */
#define TDM_SAMPLING_RATE       (24000ul)
#define TDM_SLOT_WIDTH          (32ul)
#define TDM_CNANNEL_COUNT       (8ul)

#define TDM_CLK_FREQ            (TDM_SAMPLING_RATE*TDM_SLOT_WIDTH*TDM_CNANNEL_COUNT)
#define TDM_BIT_CLOCK_DIV       (SOURCE_CLOCK_FRQ/TDM_CLK_FREQ)

/* PCM data to be transmitted over tdm */
//------------------------------------------------------------------------------
#define SINE_1K_DATA_COUNT      (48)
static uint16_t gSine1Khz[SINE_1K_DATA_COUNT] =
{
    0x0000, 0x10B5, 0x2121, 0x30FB, 0x3FFF, 0x4DEB, 0x5A82, 0x658C,
    0x6ED9, 0x7641, 0x7BA2, 0x7EE7, 0x7FFF, 0x7EE7, 0x7BA3, 0x7641,
    0x6ED9, 0x658C, 0x5A82, 0x4DEB, 0x4000, 0x30FB, 0x2121, 0x10B5,
    0x0000, 0xEF4B, 0xDEDF, 0xCF05, 0xC001, 0xB215, 0xA57E, 0x9A74,
    0x9127, 0x89BF, 0x845E, 0x8119, 0x8001, 0x8119, 0x845D, 0x89BF,
    0x9127, 0x9A74, 0xA57E, 0xB215, 0xC000, 0xCF04, 0xDEDF, 0xEF4B,
};

static uint16_t GetSine1KData(void)
{
    static uint32_t txBufPoint = 0;
    uint16_t tmp = gSine1Khz[txBufPoint];
    txBufPoint = (txBufPoint+1)%SINE_1K_DATA_COUNT;
    return tmp;
}

#if CY_TDM_APP_FUNCTION == CY_TDM_RX_TX_LOOP_BACK
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

/* Port pin config for TDM */
//------------------------------------------------------------------------------
cy_stc_gpio_pin_prt_config_t g_tdm_pin_config[] =
{
//  {                       portReg,                       pinNum, outVal,                driveMode,                            hsiom, intEdge, intMask, vtrip, slewRate, driveSel },
    {   CY_AUDIOSS_TDM0_TX_SCK_PORT,   CY_AUDIOSS_TDM0_TX_SCK_PIN,    0ul, CY_GPIO_DM_STRONG_IN_OFF,   CY_AUDIOSS_TDM0_TX_SCK_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
    { CY_AUDIOSS_TDM0_TX_FSYNC_PORT, CY_AUDIOSS_TDM0_TX_FSYNC_PIN,    0ul, CY_GPIO_DM_STRONG_IN_OFF, CY_AUDIOSS_TDM0_TX_FSYNC_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
    {    CY_AUDIOSS_TDM0_TX_SD_PORT,    CY_AUDIOSS_TDM0_TX_SD_PIN,    0ul, CY_GPIO_DM_STRONG_IN_OFF,    CY_AUDIOSS_TDM0_TX_SD_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
    {   CY_AUDIOSS_TDM0_RX_SCK_PORT,   CY_AUDIOSS_TDM0_RX_SCK_PIN,    0ul, CY_GPIO_DM_STRONG_IN_OFF,   CY_AUDIOSS_TDM0_RX_SCK_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
    { CY_AUDIOSS_TDM0_RX_FSYNC_PORT, CY_AUDIOSS_TDM0_RX_FSYNC_PIN,    0ul, CY_GPIO_DM_STRONG_IN_OFF, CY_AUDIOSS_TDM0_RX_FSYNC_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
    {    CY_AUDIOSS_TDM0_RX_SD_PORT,    CY_AUDIOSS_TDM0_RX_SD_PIN,    0ul,         CY_GPIO_DM_HIGHZ,    CY_AUDIOSS_TDM0_RX_SD_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
    {   CY_AUDIOSS_TDM0_RX_MCK_PORT,   CY_AUDIOSS_TDM0_RX_MCK_PIN,    0ul,         CY_GPIO_DM_HIGHZ,   CY_AUDIOSS_TDM0_RX_MCK_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
#if (CY_TDM_USE_CLK == CY_TDM_INTERNAL_CLOCK)
    {   CY_AUDIOSS_TDM0_TX_MCK_PORT,   CY_AUDIOSS_TDM0_TX_MCK_PIN,    0ul, CY_GPIO_DM_STRONG_IN_OFF,   CY_AUDIOSS_TDM0_TX_MCK_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
#else
    {   CY_AUDIOSS_TDM0_TX_MCK_PORT,   CY_AUDIOSS_TDM0_TX_MCK_PIN,    0ul,         CY_GPIO_DM_HIGHZ,   CY_AUDIOSS_TDM0_TX_MCK_PIN_MUX,     0ul,     0ul,   0ul,      0ul,      0ul },
#endif
};
#define TDM_PORT_NUM (sizeof(g_tdm_pin_config)/sizeof(g_tdm_pin_config[0]))

/* TDM-Tx and TDM-Rx interface configuration */
//------------------------------------------------------------------------------
cy_stc_tdm_config_t config_tdm = 
{
    .tx_config =
    {
        .txEnable          = true,
        .txMasterMode       = CY_TDM_DEVICE_MASTER,
        .txFormat           = CY_TDM_LEFT_DELATED,
        .txWordSize         = CY_TDM_SIZE_16,
        .txClkDiv           = TDM_BIT_CLOCK_DIV,
    #if (CY_TDM_USE_CLK == CY_TDM_INTERNAL_CLOCK)
        .txClkSel           = CY_TDM_SEL_SRSS_CLK0,
    #else
        .txClkSel           = CY_TDM_SEL_TX_MCLK_IN,
    #endif
        .txSckPolarity      = CY_TDM_CLK,
        .txFsyncFormat      = CY_TDM_CH_PERIOD,
        .txFsyncPolarity    = CY_TDM_SIGN,
        .txChannelNUM       = TDM_CNANNEL_COUNT,
        .txChEN             = (1ul << TDM_CNANNEL_COUNT) - 1ul,
        .txChannelSize      = TDM_SLOT_WIDTH,
        .txFIFOTriggerLevel = TDM_FIFO_THRESHOLD-1,
    },
    .rx_config =
    {
        .rxEnable           = true,
        .rxMasterMode       = CY_TDM_DEVICE_MASTER,
        .rxFormat           = CY_TDM_LEFT_DELATED,
        .rxWordSize         = CY_TDM_SIZE_16,
        .rxClkDiv           = TDM_BIT_CLOCK_DIV,
    #if (CY_TDM_USE_CLK == CY_TDM_INTERNAL_CLOCK)
        .rxClkSel           = CY_TDM_SEL_SRSS_CLK0,
    #else
        .rxClkSel           = CY_TDM_SEL_TX_MCLK_IN,
    #endif
        .rxSckPolarity      = CY_TDM_CLK,
        .rxFsyncFormat      = CY_TDM_CH_PERIOD,
        .rxFsyncPolarity    = CY_TDM_SIGN,
        .rxChannelNUM       = TDM_CNANNEL_COUNT,
        .rxChEN             = (1ul << TDM_CNANNEL_COUNT) - 1ul,
        .rxChannelSize      = TDM_SLOT_WIDTH,
        .rxLateSample       = false,
        .rxTestMode         = false,
        .rxFIFOTriggerLevel = TDM_FIFO_THRESHOLD-1,
    },
};

/* TDM irq configuration */
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

/* Global function declaration */
//------------------------------------------------------------------------------
void TransmitTdmData(void);
void ReceiveTdmData(void);
void AudioSSInterruptHandlerRx(void);
void AudioSSInterruptHandlerTx(void);
void Cy_Cs42448_DefaultConfig(void);


/* TDM data transmit handler */
//------------------------------------------------------------------------------
void TransmitTdmData(void)
{
    uint32_t txData;
    for(uint8_t data_i = 0; data_i < TDM_FIFO_THRESHOLD; data_i+=TDM_CNANNEL_COUNT)
    {
        txData = GetSine1KData();
        // Same data for left and right.
        Cy_AudioTDM_WriteTxData(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, txData);

#if CY_TDM_APP_FUNCTION == CY_TDM_RX_TX_LOOP_BACK
        txData = SoundRingBuffer_Pop();
#endif
        Cy_AudioTDM_WriteTxData(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, txData);

        // fill data for other channel
        for(uint32_t i = 0; i < TDM_CNANNEL_COUNT-2; i++)
        {
            Cy_AudioTDM_WriteTxData(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, txData);
        }
    }
}

/* TDM data receive handler */
//------------------------------------------------------------------------------
void ReceiveTdmData(void)
{
    volatile uint32_t rxData;
    for(uint8_t data_i = 0; data_i < TDM_FIFO_THRESHOLD; data_i+=TDM_CNANNEL_COUNT)
    {
        rxData = Cy_AudioTDM_ReadRxData(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT);
#if CY_TDM_APP_FUNCTION == CY_TDM_RX_TX_LOOP_BACK
        SoundRingBuffer_Push(rxData);
#endif

        // throw away other channel data
        for(uint32_t i = 0; i < TDM_CNANNEL_COUNT-1; i++)
        {
            Cy_AudioTDM_ReadRxData(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT); // throw garbage
        }
    }
}

/* AudioSS tdm interrupt handler */
//------------------------------------------------------------------------------
void AudioSSInterruptHandlerTx(void)
{
    uint32_t TX_maskedIntrStatus;
    TX_maskedIntrStatus = Cy_AudioTDM_GetTxInterruptStatusMasked(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);

    // only FIFO TRIGGER is acceptable
    CY_ASSERT((Cy_AudioTDM_GetTxInterrupt(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT) & ~CY_TDM_INTR_TX_FIFO_TRIGGER) == 0);

    TransmitTdmData();

    Cy_AudioTDM_ClearTxInterrupt(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, TX_maskedIntrStatus);
}

void AudioSSInterruptHandlerRx(void)
{
    uint32_t RX_maskedIntrStatus;
    RX_maskedIntrStatus = Cy_AudioTDM_GetRxInterruptStatusMasked(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT);

    // only FIFO TRIGGER is acceptable
    CY_ASSERT((Cy_AudioTDM_GetRxInterrupt(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT) & ~CY_TDM_INTR_RX_FIFO_TRIGGER) == 0);

    ReceiveTdmData();

    Cy_AudioTDM_ClearRxInterrupt(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT, RX_maskedIntrStatus);
}

/* Function does defult codec configuration for TDM */
//------------------------------------------------------------------------------
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
    funcMode.bitField.MFreq = 2; // 2.0480MHz to 25.6000MHz
    Cy_Cs42448_WriteCtrReg(CY_CS42448_FUNCTIONAL_MODE_REGISTER, funcMode.u8);
    readRegData = Cy_Cs42448_ReadCtrReg(CY_CS42448_FUNCTIONAL_MODE_REGISTER);
    CY_ASSERT(funcMode.u8 == readRegData);

    cy_un_cs42448_reg_interfaceFmt_t    interfaceFmt    = {.u8  = 0u};
    interfaceFmt.bitField.Freeze = 0;
    interfaceFmt.bitField.AUXDIF = 1; // TDM (does not matter)
    interfaceFmt.bitField.DACDIF = 6; // TDM, up to 24-bit data (slave only)
    interfaceFmt.bitField.ADCDIF = 6; // TDM, up to 24-bit data (slave only)
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

    /* Port Setting for TDM communication */
    Cy_GPIO_Multi_Pin_Init(g_tdm_pin_config, TDM_PORT_NUM);

    /* Interrupt setting for TDM communication */
    Cy_SysInt_InitIRQ(&irqCfgAudioSSTx);
    Cy_SysInt_SetSystemIrqVector(irqCfgAudioSSTx.sysIntSrc, AudioSSInterruptHandlerTx);
    Cy_SysInt_InitIRQ(&irqCfgAudioSSRx);
    Cy_SysInt_SetSystemIrqVector(irqCfgAudioSSRx.sysIntSrc, AudioSSInterruptHandlerRx);
    NVIC_EnableIRQ(irqCfgAudioSSTx.intIdx);

    /* Init TX interface */
    Cy_AudioTDM_DeInit(CY_AUDIOSS_TDM_TYPE);
    Cy_AudioTDM_Init(CY_AUDIOSS_TDM_TYPE, &config_tdm);
    TransmitTdmData(); // Prepare first data into FIFO before enable TDM TX
    Cy_AudioTDM_SetTxTriggerInterruptMask(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);

    /* Enable TX interface */
    Cy_AudioTDM_StartTx(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);

    /* Enable RX interface */
#if CY_TDM_APP_FUNCTION == CY_TDM_RX_TX_LOOP_BACK
    /* Init RX interface */
    Cy_AudioTDM_SetRxTriggerInterruptMask(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT);

    /* Enable RX interface */
    Cy_AudioTDM_StartRx(&CY_AUDIOSS_TDM_TYPE->TDM_RX_STRUCT);
#endif
    for(;;);
}

/* [] END OF FILE */
