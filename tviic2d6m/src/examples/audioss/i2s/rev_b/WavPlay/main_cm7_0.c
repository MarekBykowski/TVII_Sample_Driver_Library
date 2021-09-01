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
#include <stdint.h>
#include <stdbool.h>

void Cy_Cs42448_Init(void);
void Cy_Cs42448_DefaultConfig(void);

/*
    This example transmits .wav file to external audio DAC (Cs42448)
    via I2S protocol.
    Please note this example supports only 16 bit length PCM data.
    TVII is master, and the Cs42448 is slave. Sampling rate, 
    monaural/stereo will be determined by wav header.
    When internal clock is used, please connect I2S_MCLK to MCLK input
    port of the Cs42448. When external clock is used please connect
    external crystal output to I2S_IF of TVII and to MCLK input port
    of the Cs42448.
    - Operation Description
    I2S HW will trigger CPU interrupt and the CPU will then copy the 
    .wav sound data to the I2S FIFO in the IRQ.
*/

/* User setting for clock and  */
//------------------------------------------------------------------------------
#define I2S_INTERNAL_CLOCK          (0ul)
#define I2S_EXTERNAL_CLOCK          (1ul)
#define CY_I2S_USE_CLK              I2S_EXTERNAL_CLOCK

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

#pragma pack(1)
typedef struct {
    uint32_t riff;         // offset: 0,  size: 4, Indicates type RIFF value = 'RIFF'
    uint32_t size;         // offset: 4,  size: 4, file size - 8
    uint32_t type;         // offset: 8,  size: 4, = 'WAVE'
    uint32_t id;           // offset: 12, size: 4, Format chunk marker. Includes trailing null
    uint32_t chanksize;    // offset: 16, size: 4, chunk data size (16)
    uint16_t format;       // offset: 20, size: 2, Type of format (1 is PCM) - 2 byte integer
    uint16_t channels;     // offset: 22, size: 2, Number of Channels - 2 byte integer
    uint32_t samplerate;   // offset: 24, size: 4, Sample Rate
    uint32_t bytepersec;   // offset: 28, size: 4, (Sample Rate * BitsPerSample * Channels) / 8
    uint16_t blockalign;   // offset: 30, size: 2, data block size
    uint16_t bitswidth;    // offset: 32, size: 2, Bits per sample
    uint32_t data;         // offset: 36, size: 4, "data"
    uint32_t bytesize;     // offset: 40, size: 4, Size of the data section
} stc_wav_header;
#define WAV_HEADER_SIZE (sizeof(stc_wav_header))
#pragma pack()

// Sound Data
const uint8_t g_Wav16Data[] =
{
    #include "wav_16bit_data.inc"
};
#define I2S_SOUND_SIZE_IN_BYTE ((sizeof(g_Wav16Data) /sizeof(g_Wav16Data[0])) - (sizeof(stc_wav_header)))
#define I2S_SOUND_PCM_NUMBER   (I2S_SOUND_SIZE_IN_BYTE / 2ul)
uint16_t*       gp_SoundData = (uint16_t*)&g_Wav16Data[WAV_HEADER_SIZE];
stc_wav_header* gp_WavHeader = (stc_wav_header*)g_Wav16Data;
uint32_t        g_PcmNumber; // will be updated in runtime

/* I2S-Tx and I2S-Rx interface configuration */
//------------------------------------------------------------------------------
#define CY_I2S_TX_FIFO_NUM (128)
#define I2S_TX_FIFO_TH_NUM   (CY_I2S_TX_FIFO_NUM/2ul)
#define I2S_TX_FIFO_REST_NUM (CY_I2S_TX_FIFO_NUM - I2S_TX_FIFO_TH_NUM)


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
    .txFifoTriggerLevel = I2S_TX_FIFO_TH_NUM - 1,
};

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

static const cy_stc_sysint_irq_t irqCfgAudioSS =
{
    .sysIntSrc  = CY_AUDIOSS_TDM0_TX_IRQN,
    .intIdx     = CPUIntIdx4_IRQn,
    .isEnabled  = true,
};

static void AudioSSInterruptHandler(void);
static void Initialize_AIC261(void);
static void AudioDataIntegrityCheck(void);

int main(void)
{
    SystemInit();

    __enable_irq();

    // Check wav file data integrity
    AudioDataIntegrityCheck();

    /********************************************/
    /*    Initialize TI Audio IC (Cs42448)      */
    /********************************************/
    /* Initialize control path for audio codec */
    Cy_Cs42448_Init();

    /* Initialize & default setup for audio codec */
    Cy_Cs42448_DefaultConfig();

    /**************************************/
    /* Port setting for I2S communication */
    /**************************************/
    Cy_GPIO_Multi_Pin_Init(g_i2s_pin_config, I2S_PORT_NUM);

    /*******************************************/
    /* Interrupt setting for I2S communication */
    /*******************************************/
    Cy_SysInt_InitIRQ(&irqCfgAudioSS);
    Cy_SysInt_SetSystemIrqVector(irqCfgAudioSS.sysIntSrc, AudioSSInterruptHandler);
    NVIC_EnableIRQ(irqCfgAudioSS.intIdx);

    /********************************************/
    /*          initialization for I2S          */
    /********************************************/
    // De-Initialize I2S
    Cy_I2S_DeInit(CY_AUDIOSS_TDM_TYPE);

    // Flush FIFO of I2S 
    //Cy_I2S_ClearTxFifo(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);
    //Cy_I2S_ClearRxFifo(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);

    // Initialize I2S Tx settings
    Cy_I2S_Tx_Init(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, &config_I2S_TX);

    // Initialize I2S Interrupt settings
    Cy_I2S_SetTxTriggerInterruptMask(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);

    /* Start I2S Tx */
    Cy_I2S_EnableTx(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);

    for(;;);
}

/* AudioSS i2s interrupt handler */
//------------------------------------------------------------------------------
static void AudioSSInterruptHandler(void)
{
    uint32_t masked = Cy_I2S_GetTxInterruptStatusMasked(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT);

    if((masked & CY_I2S_INTR_TX_FIFO_TRIGGER) != 0ul)
    {
        static uint32_t playPoint = 0ul;
        if((gp_WavHeader->channels == 2u))
        {
            // FIFO filling for stereo data
            for(uint32_t i = 0ul; i < I2S_TX_FIFO_REST_NUM; i++)
            {
                Cy_I2S_WriteTxData(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, gp_SoundData[playPoint]);
                playPoint++;
                playPoint %= I2S_SOUND_PCM_NUMBER;
            }
        }
        else
        {
            // FIFO filling for mono data
            for(uint32_t i = 0ul; i < (I2S_TX_FIFO_REST_NUM / 2ul) - 1ul; i++)
            {
                Cy_I2S_WriteTxData(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, gp_SoundData[playPoint]);
                Cy_I2S_WriteTxData(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, gp_SoundData[playPoint]);
                playPoint++;
                playPoint %= I2S_SOUND_PCM_NUMBER;
            }
        }
    }
    if((masked & CY_I2S_INTR_TX_FIFO_UNDERFLOW) != 0ul)
    {
        CY_ASSERT(false);
    }
    if((masked & CY_I2S_INTR_TX_FIFO_OVERFLOW) != 0ul)
    {
        CY_ASSERT(false);
    }

    Cy_I2S_ClearTxInterrupt(&CY_AUDIOSS_TDM_TYPE->TDM_TX_STRUCT, masked);
}

static void AudioDataIntegrityCheck(void)
{
    CY_ASSERT(memcmp((void*)&gp_WavHeader->riff, "RIFF", 4) == 0);
    CY_ASSERT(memcmp((void*)&gp_WavHeader->type, "WAVE", 4) == 0);
    CY_ASSERT(gp_WavHeader->format == 1/*PCM*/);
    CY_ASSERT((gp_WavHeader->channels == 1) || (gp_WavHeader->channels == 2));
    CY_ASSERT(gp_WavHeader->bitswidth == I2S_PCM_DATA_LEN);
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
