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
#include <stdio.h>

#define BB_POTI_ANALOG_MACRO        CY_ADC_POT_MACRO
#define BB_POTI_ANALOG_PCLK         CY_ADC_POT_PCLK

// USED ADC logical channel and analog input
#define ADC0_USED_LOGICAL_CHANNEL       0
#define ADC1_USED_ANALOG_IN             ((cy_en_adc_pin_address_t)CY_ADC_POT_IN_NO)

// VDDA Voltage
#define VDDA_VOLTAGE_4_5V_TO_5_5V   0
#define VDDA_VOLTAGE_2_7V_TO_4_5V   1
#define VDDA_VOLTAGE                VDDA_VOLTAGE_4_5V_TO_5_5V

// Definition of SAR ADC AC Specified Parameters
#if VDDA_VOLTAGE == VDDA_VOLTAGE_4_5V_TO_5_5V
  #define ADC_OPERATION_FREQUENCY_MAX_IN_HZ (26670000ul)
  #define ANALOG_IN_SAMPLING_TIME_MIN_IN_NS (412ull)
#else // VDDA_VOLTAGE == VDDA_VOLTAGE_2_7V_TO_4_5V
  #define ADC_OPERATION_FREQUENCY_MAX_IN_HZ (13340000ul)
  #define ANALOG_IN_SAMPLING_TIME_MIN_IN_NS (824ull)
#endif

#define DIV_ROUND_UP(a,b) (((a) + (b)/2) / (b))

uint16_t               resultBuff[16];
cy_stc_adc_ch_status_t statusBuff[16];
uint8_t                resultIdx;

void AdcIntHandler(void)
{
    cy_stc_adc_interrupt_source_t intrSource = { false };

    /* Get interrupt source */
    Cy_Adc_Channel_GetInterruptMaskedStatus(&BB_POTI_ANALOG_MACRO->CH[ADC0_USED_LOGICAL_CHANNEL], &intrSource);

    if(intrSource.grpDone)
    {
        /* Get the result(s) */
        Cy_Adc_Channel_GetResult(&BB_POTI_ANALOG_MACRO->CH[ADC0_USED_LOGICAL_CHANNEL], &resultBuff[resultIdx], &statusBuff[resultIdx]);

        /* Display ADC result */
        printf("\rADC result = %04d          ", resultBuff[resultIdx]);

        /* Increment result idx */
        resultIdx = (resultIdx + 1) % (sizeof(resultBuff) / sizeof(resultBuff[0]));

        /* Clear interrupt source */
        Cy_Adc_Channel_ClearInterruptStatus(&BB_POTI_ANALOG_MACRO->CH[ADC0_USED_LOGICAL_CHANNEL], &intrSource);

        /* Trigger next conversion */
        Cy_Adc_Channel_SoftwareTrigger(&BB_POTI_ANALOG_MACRO->CH[ADC0_USED_LOGICAL_CHANNEL]);
    }
    else
    {
        // Unexpected interrupt
        CY_ASSERT(false);
    }
}

/* This is an ADC example file for following settings:
 *  - Single channel conversion
 *  - Sw trigger
 *  - handling conversion done interrupt then get the result into the buffer
 *  - the result is displayed UART terminal on PC.
 *  - if PSVP is not used, the potentiometer on the Traveo II base board is used as analog source
 */

int main(void)
{
    SystemInit();// not required for PSVP

    __enable_irq(); /* Enable global interrupts. */

    Cy_Semihosting_InitAll(CY_USB_SCB_TYPE, 115200ul, NULL, false);

    // No pin configuration is needed for the port connected to the potentiometer on the base board:
    // Default port setting after reset is just fine (High impedance, digital input buffer disabled)

    /* ADC clock divider setting */
    uint32_t actualAdcOperationFreq;
    {
      #if (CY_USE_PSVP == 1)
        uint32_t periFreq = 24000000ul;
      #else
        uint32_t periFreq = 80000000ul;
      #endif
        uint32_t divNum = DIV_ROUND_UP(periFreq, ADC_OPERATION_FREQUENCY_MAX_IN_HZ);
        actualAdcOperationFreq = periFreq / divNum;
        Cy_SysClk_PeriphAssignDivider(CY_ADC_POT_PCLK, CY_SYSCLK_DIV_16_BIT, 0u);
        Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(CY_ADC_POT_PCLK), CY_SYSCLK_DIV_16_BIT, 0u, (divNum - 1ul));
        Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(CY_ADC_POT_PCLK), CY_SYSCLK_DIV_16_BIT, 0u);
    }

    /* Initialize ADC */
    {
        uint32_t samplingCycle = (uint32_t)DIV_ROUND_UP((ANALOG_IN_SAMPLING_TIME_MIN_IN_NS * (uint64_t)actualAdcOperationFreq), 1000000000ull);

        cy_stc_adc_config_t adc0Config =
        {
            .preconditionTime    = 0u,
            .powerupTime         = 0u,
            .enableIdlePowerDown = false,
            .msbStretchMode      = CY_ADC_MSB_STRETCH_MODE_1CYCLE,
            .enableHalfLsbConv   = 0u,
            .sarMuxEnable        = true,                           // SAR0_MUX should be enabled
            .adcEnable           = true,                           // ADC0_EN should be enabled
            .sarIpEnable         = true,                           // SAR0_IP should be enabled
        };
        cy_stc_adc_config_t adc1Config =
        {
            .preconditionTime    = 0u,
            .powerupTime         = 0u,
            .enableIdlePowerDown = false,
            .msbStretchMode      = CY_ADC_MSB_STRETCH_MODE_1CYCLE,
            .enableHalfLsbConv   = 0u,
            .sarMuxEnable        = true,                           // SAR1_MUX should be enabled
            .adcEnable           = false,                          // ADC1_EN should be disabled
            .sarIpEnable         = true,                           // SAR1_IP should be enabled
        };
        cy_stc_adc_channel_config_t adcChannelConfig =
        {
            .triggerSelection          = CY_ADC_TRIGGER_OFF,
            .channelPriority           = 0u,
            .preenptionType            = CY_ADC_PREEMPTION_FINISH_RESUME,
            .isGroupEnd                = true,
            .doneLevel                 = CY_ADC_DONE_LEVEL_PULSE,
            .pinAddress                = ADC1_USED_ANALOG_IN,               // ADC[1]_x for ADC1
            .portAddress               = CY_ADC_PORT_ADDRESS_SARMUX1,       // ADC0 will use SARMUX1
            .extMuxSelect              = 0u,
            .extMuxEnable              = false,
            .preconditionMode          = CY_ADC_PRECONDITION_MODE_OFF,
            .overlapDiagMode           = CY_ADC_OVERLAP_DIAG_MODE_OFF,
            .sampleTime                = samplingCycle, // May required more sample time for borrow mechanism
            .calibrationValueSelect    = CY_ADC_CALIBRATION_VALUE_REGULAR,
            .postProcessingMode        = CY_ADC_POST_PROCESSING_MODE_NONE,
            .resultAlignment           = CY_ADC_RESULT_ALIGNMENT_RIGHT,
            .signExtention             = CY_ADC_SIGN_EXTENTION_UNSIGNED,
            .averageCount              = 0u,
            .rightShift                = 0u,
            .rangeDetectionMode        = CY_ADC_RANGE_DETECTION_MODE_INSIDE_RANGE,
            .rangeDetectionLoThreshold = 0x0000u,
            .rangeDetectionHiThreshold = 0x0FFFu,
            .mask.grpDone              = true,
            .mask.grpCancelled         = false,
            .mask.grpOverflow          = false,
            .mask.chRange              = false,
            .mask.chPulse              = false,
            .mask.chOverflow           = false,
        };

        Cy_Adc_Init(PASS0_SAR0, &adc0Config);
        Cy_Adc_Init(PASS0_SAR1, &adc1Config);
        Cy_Adc_Channel_Init(&PASS0_SAR0->CH[ADC0_USED_LOGICAL_CHANNEL], &adcChannelConfig);
    }

    /* Register ADC interrupt handler and enable interrupt */
    {
        cy_stc_sysint_irq_t irq_cfg;
        irq_cfg = (cy_stc_sysint_irq_t){
            .sysIntSrc  = (cy_en_intr_t)((uint32_t)CY_ADC_POT_IRQN + ADC0_USED_LOGICAL_CHANNEL),
            .intIdx     = CPUIntIdx3_IRQn,
            .isEnabled  = true,
        };
        Cy_SysInt_InitIRQ(&irq_cfg);
        Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, AdcIntHandler);
        NVIC_SetPriority(irq_cfg.intIdx, 0ul);
        NVIC_EnableIRQ(irq_cfg.intIdx);
    }

    /* Enable ADC ch. */
    Cy_Adc_Channel_Enable(&PASS0_SAR0->CH[ADC0_USED_LOGICAL_CHANNEL]);
    
    /* Issue SW trigger */
    Cy_Adc_Channel_SoftwareTrigger(&PASS0_SAR0->CH[ADC0_USED_LOGICAL_CHANNEL]);
    
    for(;;)
    {
    }
}



/* [] END OF FILE */
