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

cy_stc_gpio_pin_config_t user_led2_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = CY_LED2_PIN_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
    .vregEn    = 0ul,
    .ibufMode  = 0ul,
    .vtripSel  = 0ul,
    .vrefSel   = 0ul,
    .vohSel    = 0ul,
};

cy_stc_gpio_pin_config_t user_led3_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = CY_LED3_PIN_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
    .vregEn    = 0ul,
    .ibufMode  = 0ul,
    .vtripSel  = 0ul,
    .vrefSel   = 0ul,
    .vohSel    = 0ul,
};

cy_stc_gpio_pin_config_t user_button3_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom     = CY_BUTTON3_PIN_MUX,
    .intEdge   = CY_GPIO_INTR_FALLING,
    .intMask   = 1ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
    .vregEn    = 0ul,
    .ibufMode  = 0ul,
    .vtripSel  = 0ul,
    .vrefSel   = 0ul,
    .vohSel    = 0ul,
};

cy_stc_gpio_pin_config_t user_button5_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom     = CY_BUTTON5_PIN_MUX,
    .intEdge   = CY_GPIO_INTR_FALLING,
    .intMask   = 1ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
    .vregEn    = 0ul,
    .ibufMode  = 0ul,
    .vtripSel  = 0ul,
    .vrefSel   = 0ul,
    .vohSel    = 0ul,
};

void ButtonIntHandler(void)
{
    uint32_t intStatus;

    /* If button3 falling edge detected */
    intStatus = Cy_GPIO_GetInterruptStatusMasked(CY_BUTTON3_PORT, CY_BUTTON3_PIN);
    if (intStatus != 0ul)
    {
        Cy_GPIO_ClearInterrupt(CY_BUTTON3_PORT, CY_BUTTON3_PIN);
        /* Toggle LED2 */
        Cy_GPIO_Inv(CY_LED2_PORT, CY_LED2_PIN);
    }

    /* If button5 rising edge detected */
    intStatus = Cy_GPIO_GetInterruptStatusMasked(CY_BUTTON5_PORT, CY_BUTTON5_PIN);
    if (intStatus != 0ul)
    {
        Cy_GPIO_ClearInterrupt(CY_BUTTON5_PORT, CY_BUTTON5_PIN);
        /* Toggle LED3 */
        Cy_GPIO_Inv(CY_LED3_PORT, CY_LED3_PIN);
    }
}

/*
 * This is an example for GPIO edge detection interrupt.
 * This example uses 2 LED ports and 2 button ports on the base board.
 * Settings are:
 *  - BUTTON3 : Detects falling edge. When falling edge is detected, toggle LED2.
 *  - BUTTON5 : Detects rising edge. When rising edge is detected, toggle LED3.
 */
int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(CY_LED2_PORT, CY_LED2_PIN, &user_led2_port_pin_cfg);
    Cy_GPIO_Pin_Init(CY_LED3_PORT, CY_LED3_PIN, &user_led3_port_pin_cfg);
    Cy_GPIO_Pin_Init(CY_BUTTON3_PORT, CY_BUTTON3_PIN, &user_button3_port_pin_cfg);
    Cy_GPIO_Pin_Init(CY_BUTTON5_PORT, CY_BUTTON5_PIN, &user_button5_port_pin_cfg);
    
    /* Setup GPIO for BUTTON3 interrupt */
    cy_stc_sysint_irq_t irq_cfg = 
    {
        .sysIntSrc  = CY_BUTTON3_IRQN,
        .intIdx     = CPUIntIdx3_IRQn,
        .isEnabled  = true,
    };
    
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, ButtonIntHandler);
    
    /* Setup GPIO for BUTTON5 interrupt */
    irq_cfg.sysIntSrc  = CY_BUTTON5_IRQN;
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, ButtonIntHandler);

    NVIC_SetPriority(CPUIntIdx3_IRQn, 3ul);
    NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);

    for(;;)
    {
    }
}



/* [] END OF FILE */
