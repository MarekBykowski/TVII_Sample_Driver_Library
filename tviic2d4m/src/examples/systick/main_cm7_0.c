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


#if (CY_USE_PSVP == 1)
    #define USER_LED_PORT           CY_AB_LED_PORT
    #define USER_LED_PIN            CY_AB_LED_PIN
    #define USER_LED_PIN_MUX        CY_AB_LED_PIN_MUX
    #define SYSTICK_RELOAD_VAL      (10000000UL)
#else
    #define USER_LED_PORT           CY_USER_LED2_PORT
    #define USER_LED_PIN            CY_USER_LED2_PIN
    #define USER_LED_PIN_MUX        CY_USER_LED2_PIN_MUX 
    #define SYSTICK_RELOAD_VAL      (10000000UL * 5)
#endif
 

cy_stc_gpio_pin_config_t user_led1_port_pin_cfg = 
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


void toggle_gpio_on_systick_handler(void)
{
    Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
}


int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

      uint32_t value;
      
    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led1_port_pin_cfg);
    Cy_SysTick_Init(CY_SYSTICK_CLOCK_SOURCE_CLK_CPU, SYSTICK_RELOAD_VAL);
    
#if (CY_USE_PSVP == 1) 
    /* Load the TENMS field value such that the clock cycles that make up 10msec
       Here, IMO = 25MHz. That means, it requires 25MHz*10mses cycles = 250000*/
    Cy_SysTick_Set10msCalibration(250000);
#else
	/* Load the TENMS field value such that the clock cycles that make up 10msec
       Here, PLL_OUT = 160 MHz. That means, it requires (160 MHz * 10 ms) cycles = 1600000 */
    Cy_SysTick_Set10msCalibration(1600000);
#endif
    
    Cy_SysTick_SetCallback(0, toggle_gpio_on_systick_handler);
    Cy_SysTick_Enable();
    
    value = Cy_SysTick_Get10msCalibration(); //CountValue_10ms();
    Cy_SysTick_Clear();
    Cy_SysTick_SetReload(value-1);
    
    for(;;)
    {

    }      

}

/* [] END OF FILE */
