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

#if CY_USE_PSVP == 1
  #define BB_POTI_ANALOG_MACRO       SAR0
  #define BB_POTI_ANALOG_CHANNEL_NR  CY_ADC_PIN_ADDRESS_AN20
  #define BB_POTI_ANALOG_PCLK        PCLK_PASS_CLOCK_SAR0
#else
  /* If you use 64 pin MCU, you need to short JP2.9 and pin 1 of J89 (ADC_POT) */
  #define BB_POTI_ANALOG_MACRO       CY_ADC_POT_MACRO
  #define BB_POTI_ANALOG_CHANNEL_NR  ((cy_en_adc_pin_address_t)CY_ADC_POT_CHANNEL_NO)
  #define BB_POTI_ANALOG_PCLK        CY_ADC_POT_PCLK
  #define BB_POTI_ANALOG_IRQN        CY_ADC_POT_IRQN 
#endif

#define ADC_LOGICAL_CHANNEL         0

#define MAX_ANALOG_VALUE   ((1UL << 12) - 1UL)  // 12-bit ADC

/* ADC regarding definitions */
uint16_t resultBuff[16];
cy_stc_adc_ch_status_t  statusBuff[16];
uint8_t resultIdx;

const cy_stc_adc_config_t adcConfig =
{
    .preconditionTime          = 0u,
    .powerupTime               = 0u,
    .enableIdlePowerDown       = false,
    .msbStretchMode            = CY_ADC_MSB_STRETCH_MODE_1CYCLE,
    .enableHalfLsbConv         = 0u,
    .sarMuxEnable              = true,
    .adcEnable                 = true,
    .sarIpEnable               = true,
};

const cy_stc_adc_channel_config_t adcChannelConfig =
{
    .triggerSelection          = CY_ADC_TRIGGER_GENERIC0,    /* Select HW trigger, SAR0 generic input 0 */
    .channelPriority           = 0,
    .preenptionType            = CY_ADC_PREEMPTION_FINISH_RESUME,
    .isGroupEnd                = true,
    .doneLevel                 = CY_ADC_DONE_LEVEL_PULSE,
    .pinAddress                = BB_POTI_ANALOG_CHANNEL_NR,
    .portAddress               = CY_ADC_PORT_ADDRESS_SARMUX0,
    .extMuxSelect              = 0,
    .extMuxEnable              = true,
    .preconditionMode          = CY_ADC_PRECONDITION_MODE_OFF,
    .overlapDiagMode           = CY_ADC_OVERLAP_DIAG_MODE_OFF,
    .sampleTime                = 60,
    .calibrationValueSelect    = CY_ADC_CALIBRATION_VALUE_REGULAR,
    .postProcessingMode        = CY_ADC_POST_PROCESSING_MODE_NONE,
    .resultAlignment           = CY_ADC_RESULT_ALIGNMENT_RIGHT,
    .signExtention             = CY_ADC_SIGN_EXTENTION_UNSIGNED,
    .averageCount              = 0,
    .rightShift                = 0,
    .rangeDetectionMode        = CY_ADC_RANGE_DETECTION_MODE_INSIDE_RANGE,
    .rangeDetectionLoThreshold = 0x0000,
    .rangeDetectionHiThreshold = 0x0FFF,
    .mask.grpDone              = true,
    .mask.grpCancelled         = false,
    .mask.grpOverflow          = false,
    .mask.chRange              = false,
    .mask.chPulse              = false,
    .mask.chOverflow           = false,
};

const cy_stc_sysint_irq_t irq_cfg_adc =
{
    .sysIntSrc  = BB_POTI_ANALOG_IRQN,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = true,
};

const cy_stc_sysint_irq_t irq_cfg_evtgen =
{
    .sysIntSrc  = evtgen_0_interrupt_IRQn,
    .intIdx     = CPUIntIdx4_IRQn,
    .isEnabled  = true,
};

const cy_stc_evtgen_config_t evtgenTestConfig =
{
  #if (CY_USE_PSVP == 1)
    .frequencyRef          = 24000000, // clk_ref = clk_hf1 = CLK_PATH0 -> 24,000,000 for PSVP test.
    .frequencyLf           = 32000,    // clk_lf = 32,000 for PSVP test
  #else
    .frequencyRef          = 8000000,  //  clk_ref = clk_hf1 = CLK_PATH2 (IMO) -> 8,000,000 for silicon
    .frequencyLf           = 32000,    // clk_lf = 32,000 for silicon
  #endif
    .frequencyTick         = 1000000,  // Setting 1,000,000 Hz for event generator clock (clk_ref_div)
    .ratioControlMode      = CY_EVTGEN_RATIO_CONTROL_HW,
    .ratioValueDynamicMode = CY_EVTGEN_RATIO_DYNAMIC_MODE0,
};

const cy_stc_evtgen_struct_config_t evtgenTestStructureConfig =
{
    .functionalitySelection   = CY_EVTGEN_DEEPSLEEP_FUNCTIONALITY,
    .triggerOutEdge           = CY_EVTGEN_EDGE_SENSITIVE,
    .valueDeepSleepComparator = 1000000, // It wake CPU up after 1s.
    .valueActiveComparator    = 1500000, // It triggers ADC after 1.5s. means 0.5s after CPU being waked up.
    .userIsr = NULL,
};

cy_stc_evtgen_struct_context_t evtgenStruct0Context;
uint8_t adcCompletedFlag = 0;

void AdcIntHandler(void)
{
    cy_stc_adc_interrupt_source_t intrSource = { false };
    
    /* Get the result(s) */
    Cy_Adc_Channel_GetResult(&BB_POTI_ANALOG_MACRO->CH[ADC_LOGICAL_CHANNEL], &resultBuff[resultIdx], &statusBuff[resultIdx]);

    resultIdx = (resultIdx + 1) % (sizeof(resultBuff) / sizeof(resultBuff[0]));
    /* Clear inerrupt source */
    Cy_Adc_Channel_GetInterruptMaskedStatus(&BB_POTI_ANALOG_MACRO->CH[ADC_LOGICAL_CHANNEL], &intrSource);
    Cy_Adc_Channel_ClearInterruptStatus(&BB_POTI_ANALOG_MACRO->CH[ADC_LOGICAL_CHANNEL], &intrSource);

    adcCompletedFlag = 1;
}

void irqEVTGEN_sleep(void)
{
    Cy_Evtgen_ClearStructInterruptDeepSleep(EVTGEN0, 0);
}

int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    // This is temoprary code, since this should be set by default.
    CPUSS->unSLOW_CLOCK_CTL.stcField.u8INT_DIV = 0u;

    __enable_irq(); /* Enable global interrupts. */
    
    /* Enable CM7_0. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    //Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);

    /* ADC clock divider setting */
    Cy_SysClk_PeriphAssignDivider(BB_POTI_ANALOG_PCLK, CY_SYSCLK_DIV_16_BIT, 0u);
    #if (CY_USE_PSVP == 1)
        Cy_SysClk_PeriphSetDivider(BB_POTI_ANALOG_PCLK, CY_SYSCLK_DIV_16_BIT, 0u, 1u);
    #else
        Cy_SysClk_PeriphSetDivider(BB_POTI_ANALOG_PCLK, CY_SYSCLK_DIV_16_BIT, 0u, 5u);
    #endif
        Cy_SysClk_PeriphEnableDivider(BB_POTI_ANALOG_PCLK, CY_SYSCLK_DIV_16_BIT, 0u);

    /*********************/
    /*  Enable clk_hf3   */
    /*********************/
  #if (CY_USE_PSVP == 1)
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_3);
    Cy_SysClk_HfClockSetSource(CY_SYSCLK_HFCLK_3, CY_SYSCLK_HFCLK_IN_CLKPATH0);
  #else
    Cy_SysClk_ClkPathSetSource(2u, CY_SYSCLK_CLKPATH_IN_IMO);
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_3);
    Cy_SysClk_HfClockSetSource(CY_SYSCLK_HFCLK_3, CY_SYSCLK_HFCLK_IN_CLKPATH2);
  #endif

    /* Initialize ADC */
    /* Use tr_sar_gen_in[0] as the generic input 0 for SAR0 */
    Cy_Adc_SetGenericTriggerInput(PASS0_EPASS_MMIO, 0u, 0u, 0u);
    Cy_Adc_Init(BB_POTI_ANALOG_MACRO, &adcConfig);
    Cy_Adc_Channel_Init(&BB_POTI_ANALOG_MACRO->CH[ADC_LOGICAL_CHANNEL], &adcChannelConfig);

    /* Register ADC interrupt handler and enable interrupt */
    Cy_SysInt_InitIRQ(&irq_cfg_adc);
    Cy_SysInt_SetSystemIrqVector(irq_cfg_adc.sysIntSrc, AdcIntHandler);
    NVIC_SetPriority(CPUIntIdx3_IRQn, 4);
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);

    /*******************************************/
    /*        Deinitialize peripherals         */
    /*******************************************/
    Cy_Evtgen_DeinitializeCompStruct(EVTGEN0, 0);
    Cy_Evtgen_Deinitialize(EVTGEN0);
    
    /*******************************************/
    /*  Interrupt setting for Event Generator  */
    /*******************************************/
    Cy_SysInt_InitIRQ(&irq_cfg_evtgen);
    Cy_SysInt_SetSystemIrqVector(irq_cfg_evtgen.sysIntSrc, irqEVTGEN_sleep);
    NVIC_SetPriority(CPUIntIdx4_IRQn, 0);
    NVIC_EnableIRQ(CPUIntIdx4_IRQn);
    
    /*******************************************/
    /*  Initialize and start Event generator   */
    /*******************************************/
    Cy_Evtgen_Initialize(EVTGEN0, &evtgenTestConfig);

    /* Select trigger mux */
    Cy_TrigMux_Connect(TRIG_IN_MUX_7_EVTGEN_TR_OUT12,
                       TRIG_OUT_MUX_7_PASS_GEN_TR_IN0,
                       0u,
                       TRIGGER_TYPE_PASS_TR_SAR_GEN_IN__EDGE,
                       0u);

    /* Enable ADC ch. */
    Cy_Adc_Channel_Enable(&BB_POTI_ANALOG_MACRO->CH[ADC_LOGICAL_CHANNEL]);

    /*******************************************/
    /*  Initialize comparator structure 0      */
    /*******************************************/
    Cy_Evtgen_InitializeCompStruct(EVTGEN0, 0, &evtgenTestStructureConfig, &evtgenStruct0Context);

    /* Put the system to DeeSleep */
    Cy_SysPm_DeepSleep((cy_en_syspm_waitfor_t)CY_SYSPM_WAIT_FOR_INTERRUPT);

    for(;;)
    {
        while(adcCompletedFlag == 0);
        adcCompletedFlag = 0;
        Cy_Evtgen_DeinitializeCompStruct(EVTGEN0, 0);
        Cy_Evtgen_InitializeCompStruct(EVTGEN0, 0, &evtgenTestStructureConfig, &evtgenStruct0Context);
        /* Put the system to DeeSleep */
        Cy_SysPm_DeepSleep((cy_en_syspm_waitfor_t)CY_SYSPM_WAIT_FOR_INTERRUPT);
    }
    
}

/* [] END OF FILE */
