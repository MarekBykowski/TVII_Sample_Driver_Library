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


#define MAX_ANALOG_VALUE                        ((1UL << 12) - 1UL)  // 12-bit ADC

#define BB_POTI_ANALOG_MACRO                    CY_ADC_POT_MACRO
#define BB_POTI_ANALOG_CHANNEL_NR               ((cy_en_adc_pin_address_t)CY_ADC_POT_IN_NO)
#define BB_POTI_ANALOG_PCLK                     CY_ADC_POT_PCLK

// If group config is changed, interrupts may need to be adapted manually!
#define ADC_GROUP_NUMBER_OF_CHANNELS            (3u)
#define ADC_GROUP_FIRST_CHANNEL         CY_ADC_POT_IN_NO
#define ADC_GROUP_LAST_CHANNEL          (ADC_GROUP_FIRST_CHANNEL + ADC_GROUP_NUMBER_OF_CHANNELS - 1)

// Array indices
#define ADC_GROUP_CHANNEL_INDEX_BB_POTI         0   // potentiometer on base board
#define ADC_GROUP_CHANNEL_INDEX_VTEMP           1   // internal temperature sensor
#define ADC_GROUP_CHANNEL_INDEX_VBG             2   // internal bandgap reference
#define ADC_GROUP_CHANNEL_INDEX_VREF_H          3   // ADC reference voltage (high)

/* To select any of the internal signal conversion assign the internal signal pin address to this MACRO */
#define ADC_PIN_ADDRESS_INTERNAL                CY_ADC_PIN_ADDRESS_VTEMP 


cy_en_adc_pin_address_t aenLogicalToPhysicalChannel[ADC_GROUP_NUMBER_OF_CHANNELS] = { BB_POTI_ANALOG_CHANNEL_NR, ADC_PIN_ADDRESS_INTERNAL,
                                                                                      CY_ADC_PIN_ADDRESS_VREF_H };

uint16_t resultBuff[ADC_GROUP_NUMBER_OF_CHANNELS][16];
cy_stc_adc_ch_status_t  statusBuff[ADC_GROUP_NUMBER_OF_CHANNELS][16];
uint8_t resultIdx;

void AdcIntHandler(void)
{
    cy_stc_adc_interrupt_source_t intrSource = { false };

    /* Get the result(s) */
    for (uint8_t ch = ADC_GROUP_FIRST_CHANNEL; ch < (ADC_GROUP_FIRST_CHANNEL + ADC_GROUP_NUMBER_OF_CHANNELS); ch++)
    {
        uint8_t i = ch - ADC_GROUP_FIRST_CHANNEL; // i is 0-based for array indexing
        Cy_Adc_Channel_GetResult(&BB_POTI_ANALOG_MACRO->CH[ch], &resultBuff[i][resultIdx], &statusBuff[i][resultIdx]);
    }
    
    // Show temperature as bargraph, adaptions are probably needed to have a higher resolution around room temperature range
    uint8_t u8Percent = (resultBuff[ADC_GROUP_CHANNEL_INDEX_VTEMP][resultIdx] * 100UL) / MAX_ANALOG_VALUE;
    SET_BARGRAPH_PERCENT(u8Percent);
    
    resultIdx = (resultIdx + 1) % (sizeof(resultBuff[0]) / sizeof(resultBuff[0][0]));

    /* Clear inerrupt source(s) (Only last channel is required) */
    Cy_Adc_Channel_GetInterruptMaskedStatus(&BB_POTI_ANALOG_MACRO->CH[ADC_GROUP_LAST_CHANNEL], &intrSource);
    Cy_Adc_Channel_ClearInterruptStatus(&BB_POTI_ANALOG_MACRO->CH[ADC_GROUP_LAST_CHANNEL], &intrSource);

    /* Then trigger next conversion */
    Cy_Adc_Channel_SoftwareTrigger(&BB_POTI_ANALOG_MACRO->CH[ADC_GROUP_FIRST_CHANNEL]);
}

/* This is an ADC example file for following settings:
 *  - Group conversion (4 channel)
 *  - Sw trigger
 *  - handling group conversion done interrupt then get the results into the buffer
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
            .isGroupEnd = false,
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
            .mask.grpDone = false,
            .mask.grpCancelled = false,
            .mask.grpOverflow = false,
            .mask.chRange = false,
            .mask.chPulse = false,
            .mask.chOverflow = false,
        };

        Cy_Adc_Init(BB_POTI_ANALOG_MACRO, &adcConfig);
        
        adcChannelConfig.isGroupEnd = false;
        adcChannelConfig.mask.grpDone = false;
        for (uint8_t ch = ADC_GROUP_FIRST_CHANNEL; ch < (ADC_GROUP_FIRST_CHANNEL + ADC_GROUP_NUMBER_OF_CHANNELS); ch++)
        {
            uint8_t i = ch - ADC_GROUP_FIRST_CHANNEL; // i is 0-based for array indexing
            
            if(ch == ADC_GROUP_LAST_CHANNEL)
            {
                adcChannelConfig.isGroupEnd = true;
                adcChannelConfig.mask.grpDone = true;                
            }
            adcChannelConfig.pinAddress = aenLogicalToPhysicalChannel[i];

            Cy_Adc_Channel_Init(&BB_POTI_ANALOG_MACRO->CH[ch], &adcChannelConfig);
        }
    }

    /* Register ADC interrupt handler and enable interrupt */
    {
        cy_stc_sysint_irq_t irq_cfg;
        irq_cfg = (cy_stc_sysint_irq_t){
            .sysIntSrc  = (cy_en_intr_t)((uint32_t)CY_ADC_POT_IRQN + ADC_GROUP_LAST_CHANNEL),
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
    for (uint8_t ch = ADC_GROUP_FIRST_CHANNEL; ch < (ADC_GROUP_FIRST_CHANNEL + ADC_GROUP_NUMBER_OF_CHANNELS); ch++)
    {
        Cy_Adc_Channel_Enable(&CY_ADC_POT_MACRO->CH[ch]);
    }
    
    /* Issue SW trigger */
    Cy_Adc_Channel_SoftwareTrigger(&CY_ADC_POT_MACRO->CH[ADC_GROUP_FIRST_CHANNEL]);

  #endif    
    
    for(;;)
    {
    }
}



/* [] END OF FILE */
