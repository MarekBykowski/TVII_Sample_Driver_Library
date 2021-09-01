/***************************************************************************//**
* \file main_cm0plus.c
*
* \version 1.0
*
* \brief Main file for CM0+
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


#define USER_LED0_PORT          CY_BSP_BB_USER_LED0_PORT
#define USER_LED0_PIN           CY_BSP_BB_USER_LED0_PIN
#define USER_LED0_PIN_MUX       CY_BSP_BB_USER_LED0_PIN_MUX

#define USER_LED1_PORT          CY_BSP_BB_USER_LED1_PORT
#define USER_LED1_PIN           CY_BSP_BB_USER_LED1_PIN
#define USER_LED1_PIN_MUX       CY_BSP_BB_USER_LED1_PIN_MUX

#define USER_LED2_PORT          CY_BSP_BB_USER_LED2_PORT
#define USER_LED2_PIN           CY_BSP_BB_USER_LED2_PIN
#define USER_LED2_PIN_MUX       CY_BSP_BB_USER_LED2_PIN_MUX


cy_stc_gpio_pin_config_t user_led_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = USER_LED0_PIN_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

int main(void)
{
    SystemInit();
  
    __enable_irq();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    user_led_port_pin_cfg.hsiom = USER_LED0_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_LED0_PORT, USER_LED0_PIN, &user_led_port_pin_cfg);
    user_led_port_pin_cfg.hsiom = USER_LED1_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_LED1_PORT, USER_LED1_PIN, &user_led_port_pin_cfg);
    user_led_port_pin_cfg.hsiom = USER_LED2_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_LED2_PORT, USER_LED2_PIN, &user_led_port_pin_cfg);

    for(;;)
    {
        // Wait 0.05 [s]
        Cy_SysTick_DelayInUs(50000ul);

        Cy_GPIO_Inv(USER_LED0_PORT, USER_LED0_PIN);
        Cy_GPIO_Inv(USER_LED1_PORT, USER_LED1_PIN);
        Cy_GPIO_Inv(USER_LED2_PORT, USER_LED2_PIN);
    }
}

/* [] END OF FILE */
