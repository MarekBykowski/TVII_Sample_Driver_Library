/***************************************************************************//**
* \file main_cm4.c
*
* \version 1.0
*
* \brief Main example file for CM4
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
#include "example_config.h"

#define ENABLE_VARIABLE_DEFINITION
#include "cy_bargraph_definitions.h"
#undef ENABLE_VARIABLE_DEFINITION

#define MAX_ANALOG_VALUE            ((1UL << 12) - 1UL)  // 12-bit ADC

#define BB_POTI_ANALOG_MACRO        CY_ADC_POT_MACRO
#define BB_POTI_ANALOG_CHANNEL_NR   ((cy_en_adc_pin_address_t)CY_ADC_POT_IN_NO)
#define BB_POTI_ANALOG_PCLK         CY_ADC_POT_PCLK


uint16_t resultBuff[16];
cy_stc_adc_ch_status_t  statusBuff[16]; 
uint8_t resultIdx;

void AdcIntHandler(void)
{
    cy_stc_adc_interrupt_source_t intrSource = { false };
    /* Get the result(s) */
    Cy_Adc_Channel_GetResult(&BB_POTI_ANALOG_MACRO->CH[BB_POTI_ANALOG_CHANNEL_NR], &resultBuff[resultIdx], &statusBuff[resultIdx]);
    
    uint8_t u8Percent = (resultBuff[resultIdx] * 100UL) / MAX_ANALOG_VALUE;
    SET_BARGRAPH_PERCENT(u8Percent);
    
    resultIdx = (resultIdx + 1) % (sizeof(resultBuff) / sizeof(resultBuff[0]));
    /* Clear inerrupt source */
    Cy_Adc_Channel_GetInterruptMaskedStatus(&BB_POTI_ANALOG_MACRO->CH[BB_POTI_ANALOG_CHANNEL_NR], &intrSource);
    Cy_Adc_Channel_ClearInterruptStatus(&BB_POTI_ANALOG_MACRO->CH[BB_POTI_ANALOG_CHANNEL_NR], &intrSource);
    /* Then trigger next conversion */
    Cy_Adc_Channel_SoftwareTrigger(&BB_POTI_ANALOG_MACRO->CH[BB_POTI_ANALOG_CHANNEL_NR]);
}

/* This is an ADC example file for following settings:
 *  - Single channle conversion
 *  - Sw trigger
 *  - handling conversion done interrupt then get the result into the buffer
 *  - the result (percentage) is also displayed with a LED bargraph made up of the 10 LEDs on the Traveo II base board
 *  - if PSVP is not used, the potentiometer on the Traveo II base board is used as analog source
 */

int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
  #if (EXAMPLE_CONFIG__TARGET_CPU == EXAMPLE_CONFIG__CPU_CM4)
    
    // No pin configuration is needed for the port connected to the potentiometer on the base board:
    // Default port setting after reset is just fine (High impedance, digital input buffer disabled)
    
    // Note: For correct bargraph operation please ensure that the other core does not access one of the LEDs as well
    
    Cy_GPIO_Pin_Init(BARGRAPH_LED_A_PORT, BARGRAPH_LED_A_PIN, &bargraph_led_a_port_pin_cfg);
    Cy_GPIO_Pin_Init(BARGRAPH_LED_B_PORT, BARGRAPH_LED_B_PIN, &bargraph_led_b_port_pin_cfg);
    Cy_GPIO_Pin_Init(BARGRAPH_LED_C_PORT, BARGRAPH_LED_C_PIN, &bargraph_led_c_port_pin_cfg);
    Cy_GPIO_Pin_Init(BARGRAPH_LED_D_PORT, BARGRAPH_LED_D_PIN, &bargraph_led_d_port_pin_cfg);
    Cy_GPIO_Pin_Init(BARGRAPH_LED_E_PORT, BARGRAPH_LED_E_PIN, &bargraph_led_e_port_pin_cfg);
    Cy_GPIO_Pin_Init(BARGRAPH_LED_F_PORT, BARGRAPH_LED_F_PIN, &bargraph_led_f_port_pin_cfg);
    Cy_GPIO_Pin_Init(BARGRAPH_LED_G_PORT, BARGRAPH_LED_G_PIN, &bargraph_led_g_port_pin_cfg);
    Cy_GPIO_Pin_Init(BARGRAPH_LED_H_PORT, BARGRAPH_LED_H_PIN, &bargraph_led_h_port_pin_cfg);
    Cy_GPIO_Pin_Init(BARGRAPH_LED_I_PORT, BARGRAPH_LED_I_PIN, &bargraph_led_i_port_pin_cfg);
    Cy_GPIO_Pin_Init(BARGRAPH_LED_J_PORT, BARGRAPH_LED_J_PIN, &bargraph_led_j_port_pin_cfg);       

    /* ADC clock divider setting */
    {
        Cy_SysClk_PeriphAssignDivider(BB_POTI_ANALOG_PCLK, CY_SYSCLK_DIV_16_BIT, 0u);
      #if (CY_USE_PSVP == 1)
        Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0u, 1u);
      #else
        Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0u, 5u);
      #endif
        Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 0u);
    }

    /* Initialize ADC */
    {
        cy_stc_adc_config_t adcConfig =
        {
            .preconditionTime = 0u,
            .powerupTime = 0u,
            .enableIdlePowerDown = false,
            .msbStretchMode = CY_ADC_MSB_STRETCH_MODE_1CYCLE,
            .enableHalfLsbConv = 0u,
            .sarMuxEnable = true,
            .adcEnable = true,
            .sarIpEnable = true,
        };
        cy_stc_adc_channel_config_t adcChannelConfig =
        {
            .triggerSelection = CY_ADC_TRIGGER_OFF,
            .channelPriority = 0,
            .preenptionType = CY_ADC_PREEMPTION_FINISH_RESUME,
            .isGroupEnd = true,
            .doneLevel = CY_ADC_DONE_LEVEL_PULSE,
            .pinAddress = BB_POTI_ANALOG_CHANNEL_NR,
            .portAddress = CY_ADC_PORT_ADDRESS_SARMUX0,
            .extMuxSelect = 0,
            .extMuxEnable = true,
            .preconditionMode = CY_ADC_PRECONDITION_MODE_OFF,
            .overlapDiagMode = CY_ADC_OVERLAP_DIAG_MODE_OFF,
            .sampleTime = 60,
            .calibrationValueSelect = CY_ADC_CALIBRATION_VALUE_REGULAR,
            .postProcessingMode = CY_ADC_POST_PROCESSING_MODE_NONE,
            .resultAlignment = CY_ADC_RESULT_ALIGNMENT_RIGHT,
            .signExtention = CY_ADC_SIGN_EXTENTION_UNSIGNED,
            .averageCount = 0,
            .rightShift = 0,
            .rangeDetectionMode = CY_ADC_RANGE_DETECTION_MODE_INSIDE_RANGE,
            .rangeDetectionLoThreshold = 0x0000,
            .rangeDetectionHiThreshold = 0x0FFF,
            .mask.grpDone = true,
            .mask.grpCancelled = false,
            .mask.grpOverflow = false,
            .mask.chRange = false,
            .mask.chPulse = false,
            .mask.chOverflow = false,
        };

        Cy_Adc_Init(BB_POTI_ANALOG_MACRO, &adcConfig);
        Cy_Adc_Channel_Init(&BB_POTI_ANALOG_MACRO->CH[BB_POTI_ANALOG_CHANNEL_NR], &adcChannelConfig);
    }

    /* Register ADC interrupt handler and enable interrupt */
    {
        cy_stc_sysint_irq_t irq_cfg;
        irq_cfg = (cy_stc_sysint_irq_t){
            .sysIntSrc  = (cy_en_intr_t)((uint32_t)CY_ADC_POT_IRQN + BB_POTI_ANALOG_CHANNEL_NR),
            .intIdx     = CPUIntIdx3_IRQn,
            .isEnabled  = true,
        };
        Cy_SysInt_InitIRQ(&irq_cfg);
	    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, AdcIntHandler);
        NVIC_SetPriority(CPUIntIdx3_IRQn, 0);
        NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
        NVIC_EnableIRQ(CPUIntIdx3_IRQn);
    }

    /* Enable ADC ch. */
    Cy_Adc_Channel_Enable(&BB_POTI_ANALOG_MACRO->CH[BB_POTI_ANALOG_CHANNEL_NR]);
    /* Issue SW trigger */
    Cy_Adc_Channel_SoftwareTrigger(&BB_POTI_ANALOG_MACRO->CH[BB_POTI_ANALOG_CHANNEL_NR]);

  #endif    
    
    for(;;)
    {
    }
}



/* [] END OF FILE */
