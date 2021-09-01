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


#define CY_LED0_PORT            CY_BSP_BB_USER_LED0_PORT
#define CY_LED0_PIN             CY_BSP_BB_USER_LED0_PIN
#define CY_LED0_PIN_MUX         CY_BSP_BB_USER_LED0_PIN_MUX


cy_stc_gpio_pin_config_t user_led0_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = CY_LED0_PIN_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};


void toggle_gpio_on_systick_handler(void)
{
    Cy_GPIO_Inv(CY_LED0_PORT, CY_LED0_PIN);
}

extern uint32_t SystemCoreClock;

int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(CY_LED0_PORT, CY_LED0_PIN, &user_led0_port_pin_cfg);

    /* Load the TENMS field value such that the clock cycles that make up 10m sec */
    /* Note: It is SW's responsibility to provide the correct NOREF, SKEW and TENMS field values for the selected clock source. */
    Cy_SysTick_Set10msCalibration(SystemCoreClock / 100ul);

    uint32_t value = Cy_SysTick_Get10msCalibration();
    Cy_SysTick_Init(CY_SYSTICK_CLOCK_SOURCE_CLK_CPU, value-1);
    Cy_SysTick_SetCallback(0, toggle_gpio_on_systick_handler);
    Cy_SysTick_Enable();

    for(;;);
}

/* [] END OF FILE */
