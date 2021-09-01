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

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

/* 1760 pin MCU: Short GPIO and TCPWM0_TR_ONE_CNT_IN1,and check the signal from TCPWM0_LINE0 and TCPWM0_TR_ONE_CNT_IN1 */
/* It is delay about 8us */

  #define TCPWMx_GRPx_CNTx_PWM_SR              TCPWM0_GRP0_CNT0
  #define PCLK_TCPWMx_CLOCKSx_PWM_SR           PCLK_TCPWM0_CLOCKS0
  #define TCPWMx_PERI_CLK_DIVIDER_NO_PWM_SR    0

  #define TCPWMx_LINEx_PORT                    GPIO_PRT6                        // TP_290
  #define TCPWMx_LINEx_PIN                     1u
  #define TCPWMx_LINEx_MUX                     P6_1_TCPWM0_LINE0                

  #define TCPWMx_LINEx_IN_PORT                 GPIO_PRT6                        // TP_273
  #define TCPWMx_LINEx_IN_PIN                  2u
  #define TCPWMx_LINEx_IN_MUX                  P6_2_TCPWM0_TR_ONE_CNT_IN1 // Counter[1] Trigger[3]

  #define GPIO_TOBE_COPYED_PORT                GPIO_PRT6                        // TP_131
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
    .hsiom     = TCPWMx_LINEx_MUX,
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
    .hsiom     = TCPWMx_LINEx_IN_MUX,
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

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache
    
    __enable_irq(); /* Enable global interrupts. */
    
    /*--------------------------------*/
    /* Clock Configuration for TCPWMs */
    /*--------------------------------*/
    
    /* Assign a programmable divider  for TCPWM0_GRPx_CNTx_PWM_SR */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_SR, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM_SR);
    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_SR), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM_SR, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_SR), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM_SR, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_SR), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM_SR);

    /*----------------------------------------*/
    /* Port Configuration for TCPWM PR, GPIO  */
    /*----------------------------------------*/
    Cy_GPIO_Pin_Init(GPIO_TOBE_COPYED_PORT, GPIO_TOBE_COPYED_PIN, &gpio_port_pin_cfg);
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT, TCPWMx_LINEx_PIN, &pwm_line_out_pin_cfg);
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_IN_PORT, TCPWMx_LINEx_IN_PIN, &pwm_line_in_pin_cfg);
    
    /* Initialize TCPWM0_GRPx_CNTx_PWM_SR & Enable */
    Cy_Tcpwm_Sr_Init(TCPWMx_GRPx_CNTx_PWM_SR, &MyPWM_config);
    Cy_Tcpwm_Sr_Enable(TCPWMx_GRPx_CNTx_PWM_SR);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_SR);

    for(;;)
    {
        Cy_GPIO_Inv(GPIO_TOBE_COPYED_PORT, GPIO_TOBE_COPYED_PIN);

        Cy_SysTick_DelayInUs(1000UL);
    }
}

/* [] END OF FILE */
