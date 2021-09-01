
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

#define USER_LED_PORT           CY_LED8_PORT
#define USER_LED_PIN            CY_LED8_PIN
#define USER_LED_PIN_MUX        CY_LED8_PIN_MUX


cy_stc_gpio_pin_config_t user_led_port_pin_cfg =
{
    .outVal    = 0u,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = USER_LED_PIN_MUX,
    .intEdge   = 0u,
    .intMask   = 0u,
    .vtrip     = 0u,
    .slewRate  = 0u,
    .driveSel  = 0u,
};

void ToggleGpio(void)
{
    Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
}

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    /***** Cy_SysTick_Init ******/
    {
        Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
        Cy_SysTick_Init(CY_SYSTICK_CLOCK_SOURCE_CLK_CPU, 1000ul);
        Cy_SysTick_SetCallback(0ul, ToggleGpio);
    }

    // Now please check the frequency of LED8 blinking.
    //  If clk_fast = 160MHz, the LED shoud be toggle at the interval of 160KHz
    //  If clk_fast = 100MHz, the LED shoud be toggle at the interval of 100KHz
    for(;;);
}



/* [] END OF FILE */
