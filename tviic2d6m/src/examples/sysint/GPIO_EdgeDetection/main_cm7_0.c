/***************************************************************************//**
* \file main_cm7_0.c
*
* \version 1.0
*
* \brief Main example file for CM7_0
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
    #define USER_LED1_PORT           CY_LED8_PORT
    #define USER_LED1_PIN            CY_LED8_PIN
    #define USER_LED1_PIN_MUX        CY_LED8_PIN_MUX

    #define USER_LED2_PORT           CY_LED9_PORT
    #define USER_LED2_PIN            CY_LED9_PIN
    #define USER_LED2_PIN_MUX        CY_LED9_PIN_MUX

    #define USER_BUTTON1_PORT        CY_BUTTON3_PORT
    #define USER_BUTTON1_PIN         CY_BUTTON3_PIN
    #define USER_BUTTON1_PIN_MUX     CY_BUTTON3_PIN_MUX
    #define USER_BUTTON1_IRQN        CY_BUTTON3_IRQN

    #define USER_BUTTON2_PORT        CY_BUTTON4_PORT
    #define USER_BUTTON2_PIN         CY_BUTTON4_PIN
    #define USER_BUTTON2_PIN_MUX     CY_BUTTON4_PIN_MUX
    #define USER_BUTTON2_IRQN        CY_BUTTON4_IRQN
#else
    #define USER_LED1_PORT           CY_USER_LED2_PORT
    #define USER_LED1_PIN            CY_USER_LED2_PIN
    #define USER_LED1_PIN_MUX        CY_USER_LED2_PIN_MUX

    #define USER_LED2_PORT           CY_USER_LED3_PORT
    #define USER_LED2_PIN            CY_USER_LED3_PIN
    #define USER_LED2_PIN_MUX        CY_USER_LED3_PIN_MUX

    #define USER_BUTTON1_PORT        CY_USER_BUTTON_RIGHT_PORT
    #define USER_BUTTON1_PIN         CY_USER_BUTTON_RIGHT_PIN
    #define USER_BUTTON1_PIN_MUX     CY_USER_BUTTON_RIGHT_PIN_MUX
    #define USER_BUTTON1_IRQN        CY_USER_BUTTON_RIGHT_IRQN

  #if defined(CY_USER_BUTTON_DOWN_PORT)
    #define USER_BUTTON2_PORT        CY_USER_BUTTON_DOWN_PORT
    #define USER_BUTTON2_PIN         CY_USER_BUTTON_DOWN_PIN
    #define USER_BUTTON2_PIN_MUX     CY_USER_BUTTON_DOWN_PIN_MUX
    #define USER_BUTTON2_IRQN        CY_USER_BUTTON_DOWN_IRQN
  #elif defined(CY_USER_BUTTON_LEFT_PORT)
    #define USER_BUTTON2_PORT        CY_USER_BUTTON_LEFT_PORT
    #define USER_BUTTON2_PIN         CY_USER_BUTTON_LEFT_PIN
    #define USER_BUTTON2_PIN_MUX     CY_USER_BUTTON_LEFT_PIN_MUX
    #define USER_BUTTON2_IRQN        CY_USER_BUTTON_LEFT_IRQN
  #else
    #error "bsp is not supporting."
  #endif
#endif

cy_stc_gpio_pin_config_t user_led0_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = USER_LED1_PIN_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

cy_stc_gpio_pin_config_t user_led1_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = USER_LED2_PIN_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

cy_stc_gpio_pin_config_t user_button1_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom     = USER_BUTTON1_PIN_MUX,
    .intEdge   = CY_GPIO_INTR_FALLING,
    .intMask   = 1ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

cy_stc_gpio_pin_config_t user_button2_port_pin_cfg = 
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom     = USER_BUTTON2_PIN_MUX,
    .intEdge   = CY_GPIO_INTR_FALLING,
    .intMask   = 1ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

void ButtonIntHandler(void)
{
    uint32_t intStatus;

    /* If button1 falling edge detected */
    intStatus = Cy_GPIO_GetInterruptStatusMasked(USER_BUTTON1_PORT, USER_BUTTON1_PIN);
    if (intStatus != 0ul)
    {
        Cy_GPIO_ClearInterrupt(USER_BUTTON1_PORT, USER_BUTTON1_PIN);
        /* Toggle LED1 */
        Cy_GPIO_Inv(USER_LED1_PORT, USER_LED1_PIN);
    }
    
    /* If button2 rising edge detected */
    intStatus = Cy_GPIO_GetInterruptStatusMasked(USER_BUTTON2_PORT, USER_BUTTON2_PIN);
    if (intStatus != 0ul)
    {
        Cy_GPIO_ClearInterrupt(USER_BUTTON2_PORT, USER_BUTTON2_PIN);
        /* Toggle LED2 */
        Cy_GPIO_Inv(USER_LED2_PORT, USER_LED2_PIN);
    }
}

/*
 * This is an example for GPIO edge detection interrupt.
 * This example uses 3 LED ports and 3 button ports on the base board.
 * Settings are:
 *  - BUTTON_RIGHT : Detects falling edge. When falling edge is detected, toggle LED2.
 *  - BUTTON_DOWN : Detects rising edge. When rising edge is detected, toggle LED3.

 */
int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED1_PORT, USER_LED1_PIN, &user_led0_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_LED2_PORT, USER_LED2_PIN, &user_led1_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_BUTTON1_PORT, USER_BUTTON1_PIN, &user_button1_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_BUTTON2_PORT, USER_BUTTON2_PIN, &user_button2_port_pin_cfg);

    /* Setup GPIO for BUTTON1 interrupt */
    cy_stc_sysint_irq_t irq_cfg =
    {
        .sysIntSrc  = USER_BUTTON1_IRQN,
        .intIdx     = CPUIntIdx2_IRQn,
        .isEnabled  = true,
    };

    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, ButtonIntHandler);
    
    /* Setup GPIO for BUTTON2 interrupt */
    irq_cfg.sysIntSrc  = USER_BUTTON2_IRQN;
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, ButtonIntHandler);

    NVIC_SetPriority(CPUIntIdx2_IRQn, 3ul);
    NVIC_EnableIRQ(CPUIntIdx2_IRQn);

    for(;;)
    {
    }
}



/* [] END OF FILE */
