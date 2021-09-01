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

/* Include default crypto configuration.
 * You can use other configuration instead follows.
 */
#include "crypto/cy_crypto_config.h"

#if CY_USE_PSVP == 1
  #define USER_LED_PORT           CY_LED0_PORT
  #define USER_LED_PIN            CY_LED0_PIN
  #define USER_LED_PIN_MUX        CY_LED0_PIN_MUX
#else   // 8M 176-pin CPU board
  #define USER_LED_PORT           CY_CB_USER_LED1_PORT
  #define USER_LED_PIN            CY_CB_USER_LED1_PIN
  #define USER_LED_PIN_MUX        CY_CB_USER_LED1_PIN_MUX
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


/* For CRYPTO server that runs on the CM0+ */
cy_stc_crypto_server_context_t cryptoServerCtx;

/***********************************************************************************************************************
 * main function
 ***********************************************************************************************************************/
int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /* Start crypto server */
    {
        Cy_Crypto_Server_Start(&cryptoConfig, &cryptoServerCtx);

        /* Enable CRYPTO regarding IRQn */
        /* In this examle 2 of crypto regarding interrupt uses same number,
            so just one invoking NVIC setting is needed.
                CY_CRYPTO_NOTIFY_INTR_NR    == 
                CY_CRYPTO_ERROR_INTR_NR
        */
        NVIC_SetPriority(CY_CRYPTO_NOTIFY_CPU_INT_IDX, 0);
        NVIC_ClearPendingIRQ(CY_CRYPTO_NOTIFY_CPU_INT_IDX);
        NVIC_EnableIRQ(CY_CRYPTO_NOTIFY_CPU_INT_IDX);
    }

    /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    //Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR);

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
    
    /* Now CRYPTO server runs */
    for(;;)
    {
        Cy_SysTick_DelayInUs(50000);
        Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
    }
}



/* [] END OF FILE */
