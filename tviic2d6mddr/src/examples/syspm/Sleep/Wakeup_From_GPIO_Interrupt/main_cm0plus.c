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
    #define USER_LED1_PORT           CY_LED0_PORT
    #define USER_LED1_PIN            CY_LED0_PIN
    #define USER_LED1_PIN_MUX        CY_LED0_PIN_MUX

    #define USER_LED2_PORT           CY_LED1_PORT
    #define USER_LED2_PIN            CY_LED1_PIN
    #define USER_LED2_PIN_MUX        CY_LED1_PIN_MUX

    #define USER_LED3_PORT           CY_LED2_PORT
    #define USER_LED3_PIN            CY_LED2_PIN
    #define USER_LED3_PIN_MUX        CY_LED2_PIN_MUX

    #define USER_BUTTON1_PORT        CY_BUTTON3_PORT
    #define USER_BUTTON1_PIN         CY_BUTTON3_PIN
    #define USER_BUTTON1_PIN_MUX     CY_BUTTON3_PIN_MUX
    #define USER_BUTTON1_IRQN        CY_BUTTON3_IRQN
    
    #define USER_BUTTON2_PORT        CY_BUTTON5_PORT
    #define USER_BUTTON2_PIN         CY_BUTTON5_PIN
    #define USER_BUTTON2_PIN_MUX     CY_BUTTON5_PIN_MUX
    #define USER_BUTTON2_IRQN        CY_BUTTON5_IRQN
#else
    #define USER_LED1_PORT           CY_USER_LED1_PORT
    #define USER_LED1_PIN            CY_USER_LED1_PIN
    #define USER_LED1_PIN_MUX        CY_USER_LED1_PIN_MUX

    #define USER_LED2_PORT           CY_USER_LED2_PORT
    #define USER_LED2_PIN            CY_USER_LED2_PIN
    #define USER_LED2_PIN_MUX        CY_USER_LED2_PIN_MUX

    #define USER_LED3_PORT           CY_USER_LED3_PORT
    #define USER_LED3_PIN            CY_USER_LED3_PIN
    #define USER_LED3_PIN_MUX        CY_USER_LED3_PIN_MUX

    #define USER_BUTTON1_PORT        CY_USER_BUTTON_UP_PORT
    #define USER_BUTTON1_PIN         CY_USER_BUTTON_UP_PIN
    #define USER_BUTTON1_PIN_MUX     CY_USER_BUTTON_UP_PIN_MUX
    #define USER_BUTTON1_IRQN        CY_USER_BUTTON_UP_IRQN
    
    #define USER_BUTTON2_PORT        CY_USER_BUTTON_LEFT_PORT
    #define USER_BUTTON2_PIN         CY_USER_BUTTON_LEFT_PIN
    #define USER_BUTTON2_PIN_MUX     CY_USER_BUTTON_LEFT_PIN_MUX
    #define USER_BUTTON2_IRQN        CY_USER_BUTTON_LEFT_IRQN
#endif

cy_stc_gpio_pin_config_t user_led0_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED1_PIN_MUX,                           
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

cy_stc_gpio_pin_config_t user_led2_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED2_PIN_MUX,                           
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

cy_stc_gpio_pin_config_t user_led3_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED3_PIN_MUX,                           
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
    .hsiom = USER_BUTTON1_PIN_MUX,
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

cy_stc_gpio_pin_config_t user_button5_port_pin_cfg = 
{
    .outVal = 0x00,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = USER_BUTTON2_PIN_MUX,
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

void ButtonIntHandler(void)
{
    uint32_t intStatus;

    /* If button 3 falling edge detected */
    intStatus = Cy_GPIO_GetInterruptStatusMasked(USER_BUTTON1_PORT, USER_BUTTON1_PIN);
    if (intStatus != 0uL)
    {
        Cy_GPIO_ClearInterrupt(USER_BUTTON1_PORT, USER_BUTTON1_PIN);
        /* Toggle LED2 */
        Cy_GPIO_Inv(USER_LED2_PORT, USER_LED2_PIN);
    }
    
    /* If button5 falling edge detected */
    intStatus = Cy_GPIO_GetInterruptStatusMasked(USER_BUTTON2_PORT, USER_BUTTON2_PIN);
    if (intStatus != 0uL)
    {
        Cy_GPIO_ClearInterrupt(USER_BUTTON2_PORT, USER_BUTTON2_PIN);
        /* Toggle LED3 */
        Cy_GPIO_Inv(USER_LED3_PORT, USER_LED3_PIN);
    }
}

/*
 * This is an example for GPIO edge detection interrupt.
 * This example uses 3 LED ports and 2 button ports on the base board.
 * Settings are:
 *  - BUTTON3 : Detects falling edge. When falling edge is detected, toggle LED2.
 * 
 *  - BUTTON5 : Detects falling and rising edge. When a edge is detected, toggle LED3.
 */
int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */
	/* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR);

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED1_PORT, USER_LED1_PIN, &user_led0_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_LED2_PORT, USER_LED2_PIN, &user_led2_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_LED3_PORT, USER_LED3_PIN, &user_led3_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_BUTTON1_PORT, USER_BUTTON1_PIN, &user_button3_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_BUTTON2_PORT, USER_BUTTON2_PIN, &user_button5_port_pin_cfg);

    /* Setup GPIO for BUTTON3 interrupt */
    cy_stc_sysint_irq_t irq_cfg =
    {
        .sysIntSrc  = USER_BUTTON1_IRQN,
        .intIdx     = CPUIntIdx2_IRQn,
        .isEnabled  = true,
    };
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, ButtonIntHandler);
    
    /* Setup GPIO for button 5*/
    irq_cfg.sysIntSrc = USER_BUTTON2_IRQN;
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, ButtonIntHandler);

    NVIC_SetPriority(CPUIntIdx2_IRQn, 3);
    NVIC_ClearPendingIRQ(CPUIntIdx2_IRQn);
    NVIC_EnableIRQ(CPUIntIdx2_IRQn);
    
    Cy_SysPm_Sleep(CY_SYSPM_WAIT_FOR_INTERRUPT);

    for(;;)
    {
        Cy_GPIO_Inv(USER_LED1_PORT, USER_LED1_PIN);
        Cy_SysTick_DelayInUs(50000);
    }
}



/* [] END OF FILE */
