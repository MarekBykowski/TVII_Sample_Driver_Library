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

#if (CY_USE_PSVP == 1)
    #define USER_LED_PORT           CY_LED9_PORT
    #define USER_LED_PIN            CY_LED9_PIN
    #define USER_LED_PIN_MUX        CY_LED9_PIN_MUX

    #define USER_BUTTON_PORT        CY_BUTTON2_PORT
    #define USER_BUTTON_PIN         CY_BUTTON2_PIN
    #define USER_BUTTON_PIN_MUX     CY_BUTTON2_PIN_MUX
    #define USER_BUTTON_IRQ         CY_BUTTON2_IRQN
#else
    #define USER_LED_PORT           CY_USER_LED2_PORT
    #define USER_LED_PIN            CY_USER_LED2_PIN
    #define USER_LED_PIN_MUX        CY_USER_LED2_PIN_MUX

    #define USER_BUTTON_PORT        CY_USER_BUTTON_LEFT_PORT
    #define USER_BUTTON_PIN         CY_USER_BUTTON_LEFT_PIN
    #define USER_BUTTON_PIN_MUX     CY_USER_BUTTON_LEFT_PIN_MUX
    #define USER_BUTTON_IRQ         CY_USER_BUTTON_LEFT_IRQN
#endif

cy_stc_gpio_pin_config_t user_led0_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED_PIN_MUX ,                           
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

cy_stc_gpio_pin_config_t user_button3_port_pin_cfg = 
{
    .outVal = 0x00,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = USER_BUTTON_PIN_MUX ,
    .intEdge = CY_GPIO_INTR_FALLING,
    .intMask = 1,
    .vtrip = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel = 0,
    .vohSel = 0,
};

/* Handler will cause CPU to wake-up from DeepSleep */
void ButtonIntHandler(void)
{
    uint32_t intStatus;

    /* If button falling edge detected */
    intStatus = Cy_GPIO_GetInterruptStatusMasked(USER_BUTTON_PORT, USER_BUTTON_PIN);
    if (intStatus != 0uL)
    {
        Cy_GPIO_ClearInterrupt(USER_BUTTON_PORT, USER_BUTTON_PIN);
    }
}

int main(void)
{
    SystemInit();
    
    /* Enable global interrupts. */
    __enable_irq();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led0_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_BUTTON_PORT, USER_BUTTON_PIN, &user_button3_port_pin_cfg);

    /* Setup interrupt for USER_BUTTON */
    cy_stc_sysint_irq_t irq_cfg =
    {
        .sysIntSrc  = USER_BUTTON_IRQ,
        .intIdx     = CPUIntIdx3_IRQn,
        .isEnabled  = true,
    };
    
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, ButtonIntHandler);
    
    NVIC_SetPriority(CPUIntIdx3_IRQn, 3);
    NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);
    
    /* Toggle an LED for sometime to overcome the non aacessible state from debugger */
    for(uint16_t i=0; i<100; i++)
    {
        /* Turn on LED for to some time to indicate the DeepSleep mode. */
        Cy_SysTick_DelayInUs(50000);
        Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
    }

    /* Put core into DeepSleep mode, LED will be off. */
    Cy_SysPm_DeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);

    for(;;)
    {
        /* Turn on LED after waking-up from DeepSleep */
        Cy_GPIO_Write(USER_LED_PORT, USER_LED_PIN, 1);
    }
}



/* [] END OF FILE */
