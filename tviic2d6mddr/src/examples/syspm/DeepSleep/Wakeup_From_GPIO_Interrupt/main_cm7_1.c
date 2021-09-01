/***************************************************************************//**
* \file main_cm7_1.c
*
* \brief
* Main file for CM7 #1
*
********************************************************************************
* \copyright
* Copyright 2016-2019, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_project.h"
#include "cy_device_headers.h"

#if (CY_USE_PSVP == 1)
    #define USER_LED_PORT           CY_LED9_PORT
    #define USER_LED_PIN            CY_LED9_PIN
    #define USER_LED_PIN_MUX        CY_LED9_PIN_MUX
#else
    #define USER_LED_PORT           CY_USER_LED3_PORT
    #define USER_LED_PIN            CY_USER_LED3_PIN
    #define USER_LED_PIN_MUX        CY_USER_LED3_PIN_MUX 
#endif


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

int main(void)
{
    SystemInit();
    
    /* Enable global interrupts. */
    __enable_irq();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);

    /* Put core into DeepSleep mode. */
    Cy_SysPm_DeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
    
    for(;;)
    {
        /* Toggle LED after waking-up from DeepSleep */
        Cy_SysTick_DelayInUs(50000);
        Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
    }
}



/* [] END OF FILE */
