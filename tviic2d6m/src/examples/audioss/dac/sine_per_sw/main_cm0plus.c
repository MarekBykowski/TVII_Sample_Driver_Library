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

#if CY_SYSTEM_USE_CLOCK == CY_SYSTEM_USE_ECO
    #define PLL_INPUT_CLK_FREQ_HZ       CY_CLK_ECO_FREQ_HZ
#elif CY_SYSTEM_USE_CLOCK == CY_SYSTEM_USE_IMO
    #define PLL_INPUT_CLK_FREQ_HZ       CY_CLK_IMO_FREQ_HZ
#else
    #error "Please check CY_SYSTEM_USE_CLOCK define!"
#endif

#define DAC_INSTANCE               DAC0
#define DAC_IRQ_NR                 dac_0_interrupt_IRQn

#define DAC_CLK_DIV                8
#define DAC_OVERSAMPLING           256

#define SAMPLE_FREQ_HZ             48000

#define DAC_REQUIRED_INPUT_CLK     (SAMPLE_FREQ_HZ * DAC_CLK_DIV * DAC_OVERSAMPLING)

#define CLK_PATH_HF_CLK_FOR_DAC    2 // PLL400M #1

#define DAC_FIFO_THRESHOLD_WORDS   32



#if (CY_USE_PSVP == 1)
    #define USER_LED_PORT           CY_AB_LED_PORT
    #define USER_LED_PIN            CY_AB_LED_PIN
    #define USER_LED_PIN_MUX        CY_AB_LED_PIN_MUX
    // The core frequency is 24MHz. 1680000 / 24MHz = 0.07[s]
    #define DAG_ANALOG_STAB_DELAY   1680000 
#else
    #define USER_LED_PORT           CY_USER_LED1_PORT
    #define USER_LED_PIN            CY_USER_LED1_PIN
    #define USER_LED_PIN_MUX        CY_USER_LED1_PIN_MUX 
    // The core frequency is 80MHz. 5600000 / 80MHz = 0.07[s]
    #define DAG_ANALOG_STAB_DELAY   5600000
#endif


#include "sine440_norm_0db.h"

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED_PIN_MUX,                           
    .intEdge = 0,                                  
    .intMask = 0,                                  
    .vtrip = 0,                                    
    .slewRate = 0,                                 
    .driveSel = 0,                                 
    .vregEn = 0,                                   
    .ibufMode = 0,                                 
    .vtripSel = 0,                                 
    .vrefSel = 0,                                  
    .vohSel = 0,                                   
};

cy_stc_audiodac_config_t audio_dac_cfg =
{
    .clkDiv        = DAC_CLK_DIV - 1,       
    .clkSel        = CY_AUDIODAC_CLK_SEL_SRSS,       
    .sampFreq      = CY_AUDIODAC_FS_SEL_256FS_256OSR,     
    .count         = 8000,  // clk_timer will be set to 8MHz IMO, so 8000 counts are needed for 1ms
    /* Suggested values: 13ms for 2.2uF caps  60ms for 10uF caps.*/
    .fastRampCount = 13,/* 2.2uF*/
    .compRampCount = 60,/* Default*/
    .trgLevel      = DAC_FIFO_THRESHOLD_WORDS,     
};

int16_t * ps16PcmData = (int16_t *)rawPcmData;
uint32_t u32NumberOfSamples = (sizeof(rawPcmData) / sizeof(rawPcmData[0])) / 2;  // rawPcmData is byte array --> 2 bytes per sample
uint32_t u32SampleIndex = 0;

void Audio_DAC_IRQ_Handler(void)
{    
    static bool bFirstInterrupt = true;    
    
    // Fill FIFO
    for(uint32_t u32Word = 0; u32Word < DAC_FIFO_THRESHOLD_WORDS; u32Word++)
    {
        uint32_t u32LeftRightSample = ((uint32_t)ps16PcmData[u32SampleIndex] << 16) + (uint32_t)ps16PcmData[u32SampleIndex];
        
        Cy_AudioDac_FifoWriteData(DAC_INSTANCE, u32LeftRightSample);
        
        u32SampleIndex++;
        
        // Reset sample index and toggle LED when PCM data has been played
        if (u32SampleIndex >= u32NumberOfSamples)
        {
            u32SampleIndex = 0;
            Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
        }
    }
    
    if(bFirstInterrupt == true)
    {
        // Activate DAC on the first IRQ (FIFO contains data now)
        Cy_AudioDac_Activate(DAC_INSTANCE);
        bFirstInterrupt = false;
    }
    
    Cy_AudioDac_ClearInterrupt(DAC_INSTANCE, CY_AUDIODAC_FIFO_TRIGGER);    
}


int main(void)
{
    SystemInit();
    
    __enable_irq();
    
    /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    // Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    // Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
        
    cy_stc_sysint_irq_t irq_cfg = (cy_stc_sysint_irq_t) {
                                                            .sysIntSrc  = DAC_IRQ_NR,
                                                            .intIdx     = CPUIntIdx2_IRQn,
                                                            .isEnabled  = true,
                                                        };
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, Audio_DAC_IRQ_Handler);
    NVIC_SetPriority(CPUIntIdx2_IRQn, 0);
    NVIC_ClearPendingIRQ(CPUIntIdx2_IRQn);
    NVIC_EnableIRQ(CPUIntIdx2_IRQn);   
   
    CY_ASSERT(Cy_SysClk_Pll400MDisable(CLK_PATH_HF_CLK_FOR_DAC) == CY_SYSCLK_SUCCESS);

    cy_stc_pll_400M_config_t stcPllCfg =
    {
        .inputFreq    = PLL_INPUT_CLK_FREQ_HZ,
        .outputFreq   = DAC_REQUIRED_INPUT_CLK,
        .outputMode   = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
        .fracEn       = true,
        .fracDitherEn = true,
        .sscgEn       = false,
        .sscgDitherEn = false,
    };
    CY_ASSERT(Cy_SysClk_Pll400MConfigure(CLK_PATH_HF_CLK_FOR_DAC, &stcPllCfg) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_Pll400MEnable(CLK_PATH_HF_CLK_FOR_DAC, 10000) == CY_SYSCLK_SUCCESS);
    
    Cy_SysClk_ClkTimerSetSource(CY_SYSCLK_CLKTIMER_IN_IMO);
    Cy_SysClk_ClkTimerEnable();

    Cy_AudioDac_Init(DAC_INSTANCE, &audio_dac_cfg);
    Cy_AudioDac_Enable(DAC_INSTANCE);    
    // Stabilization time 70 ms
    DELAY_CORE_CYCLE(DAG_ANALOG_STAB_DELAY);
    
    // After setting interrupt mask, interrupt should occur because FIFO is empty
    Cy_AudioDac_SetInterruptMask(DAC_INSTANCE, CY_AUDIODAC_FIFO_TRIGGER);

    for(;;)
    {

    }
}



/* [] END OF FILE */
