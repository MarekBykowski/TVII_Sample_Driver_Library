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

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/
/*  P6_3 is GPIO output to be copyed it's signal (GPIO_OUT).
    P6_2 is TCPWM counter input (TCPWM_IN).
    P6_1 is TCPWM output (TCPWM_OUT). */

/* Short TCPWM_IN and GPIO_OUT on the base board and see the signal of GPIO_OUT and TCPWM_OUT.
    Signal of TCPWM_OUT delays about 8 [us] from GPIO_OUT's */

/* 176 pin MCU on Rev.A CPU board:  J10.7 is GPIO_OUT. J2.12 is TCPWM_IN. J2.10 is TCPWM_OUT. */
/* 176 pin MCU on Rev.C CPU board:  J2.13 is GPIO_OUT. J2.12 is TCPWM_IN. J2.10 is TCPWM_OUT. */
/*  64 pin MCU: J10.10 is GPIO_OUT. J12.5 is TCPWM_IN. J2.10 is TCPWM_OUT. */
  
  #define TCPWM0_GRPx_CNTx_PWM_SR              TCPWM0_GRP0_CNT0
  #define PCLK_TCPWM0_CLOCKSx_PWM_SR           PCLK_TCPWM0_CLOCKS0
  #define TCPWM_PERI_CLK_DIVIDER_NO_PWM_SR     0

  #define TCPWM_LINEx_PORT                     GPIO_PRT6
  #define TCPWM_LINEx_PIN                      1u
  #define TCPWM_LINEx_MUX                      P6_1_TCPWM0_LINE0

  #define TCPWM_LINEx_IN_PORT                  GPIO_PRT6
  #define TCPWM_LINEx_IN_PIN                   2u
  #define TCPWM_LINEx_IN_MUX                   P6_2_TCPWM0_TR_ONE_CNT_IN1 // Counter[0] Trigger[3]

  #define GPIO_TOBE_COPYED_PORT                GPIO_PRT6
  #define GPIO_TOBE_COPYED_PIN                 3u
  #define GPIO_TOBE_COPYED_MUX                 P6_3_GPIO 

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/


/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/

cy_stc_gpio_pin_config_t gpio_port_pin_cfg = 
{
    .outVal    = 0x00u,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = GPIO_TOBE_COPYED_MUX,
    .intEdge   = 0u,
    .intMask   = 0u,
    .vtrip     = 0u,
    .slewRate  = 0u,
    .driveSel  = 0u,
    .vregEn    = 0u,
    .ibufMode  = 0u,
    .vtripSel  = 0u,
    .vrefSel   = 0u,
    .vohSel    = 0u,
};

cy_stc_gpio_pin_config_t pwm_line_out_pin_cfg = 
{
    .outVal    = 0x01u,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom     = TCPWM_LINEx_MUX,
    .intEdge   = 0u,
    .intMask   = 0u,
    .vtrip     = 0u,
    .slewRate  = 0u,
    .driveSel  = 0u,
    .vregEn    = 0u,
    .ibufMode  = 0u,
    .vtripSel  = 0u,
    .vrefSel   = 0u,
    .vohSel    = 0u,
};

cy_stc_gpio_pin_config_t pwm_line_in_pin_cfg = 
{
    .outVal    = 0x0u,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom     = TCPWM_LINEx_IN_MUX,
    .intEdge   = 0u,
    .intMask   = 0u,
    .vtrip     = 0u,
    .slewRate  = 0u,
    .driveSel  = 0u,
    .vregEn    = 0u,
    .ibufMode  = 0u,
    .vtripSel  = 0u,
    .vrefSel   = 0u,
    .vohSel    = 0u,
};

cy_stc_tcpwm_sr_config_t const MyPWM_config =
{
    .clockPrescaler     = CY_TCPWM_SR_PRESCALER_DIVBY_1,
    .debug_pause        = 0uL,
    .runMode            = CY_TCPWM_COUNTER_CONTINUOUS,
    .period             = 0x0000,
    .period_buff        = 0x0001,
    .compare0           = 0x0001,
    .compare1           = 0x0001,
    .enableCompare0Swap = false,
    .enableCompare1Swap = false,
    .interruptSources   = 0uL,
    .SerialInInputMode  = 3uL, // level detect
    .SerialInInput      = 3uL, // Trigger[3]
    .reloadInputMode    = 3uL,
    .reloadInput        = 0uL,
    .startInputMode     = 3uL,
    .startInput         = 0uL,
    .stopInputMode      = 3uL,
    .stopInput          = 0uL,
    .shiftInputMode     = 3uL,
    .shiftInput         = 1uL,
};

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/
int main(void)
{
    SystemInit();
    
    __enable_irq(); /* Enable global interrupts. */
    
    /*--------------------------------*/
    /* Clock Configuration for TCPWMs */
    /*--------------------------------*/
    
    /* Assign a programmable divider  for TCPWM0_GRPx_CNTx_PWM_SR */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKSx_PWM_SR, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_SR);
    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_SR, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_SR, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_SR);

    /*----------------------------------------*/
    /* Port Configuration for TCPWM PR, GPIO  */
    /*----------------------------------------*/
    Cy_GPIO_Pin_Init(GPIO_TOBE_COPYED_PORT, GPIO_TOBE_COPYED_PIN, &gpio_port_pin_cfg);
    Cy_GPIO_Pin_Init(TCPWM_LINEx_PORT, TCPWM_LINEx_PIN, &pwm_line_out_pin_cfg);
    Cy_GPIO_Pin_Init(TCPWM_LINEx_IN_PORT, TCPWM_LINEx_IN_PIN, &pwm_line_in_pin_cfg);
    
    /* Initialize TCPWM0_GRPx_CNTx_PWM_SR & Enable */
    Cy_Tcpwm_Sr_Init(TCPWM0_GRPx_CNTx_PWM_SR, &MyPWM_config);
    Cy_Tcpwm_Sr_Enable(TCPWM0_GRPx_CNTx_PWM_SR);
    Cy_Tcpwm_TriggerStart(TCPWM0_GRPx_CNTx_PWM_SR);

    for(;;)
    {
        Cy_GPIO_Inv(GPIO_TOBE_COPYED_PORT, GPIO_TOBE_COPYED_PIN);

        // Wait 0.05 [s]
        Cy_SysTick_DelayInUs(50000); 
    }
}

/* [] END OF FILE */
