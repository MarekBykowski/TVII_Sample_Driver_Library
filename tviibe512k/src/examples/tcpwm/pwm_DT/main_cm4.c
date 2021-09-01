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

/* To check this example is functional,
   please see following pin outputs the 200Hz with right side dead time 250 [us] and left side dead time 500 [us] */
/* 176 pin MCU: J2.9 (PWM) and J2.10 (PWM COMPL) on the base board. */
/*  64 pin MCU: J2.9 (PWM) and J2.10 (PWM COMPL) on the base board. */

/* PWM PR Mode Configuration def */
  
  #define TCPWM0_GRPx_CNTx_PWM_DT           TCPWM0_GRP1_CNT0
  #define PCLK_TCPWM0_CLOCKSx_PWM_DT        PCLK_TCPWM0_CLOCKS256
  #define TCPWM_PERI_CLK_DIVIDER_NO_PWM_DT  0u

  /* TCPWM_LINE */
  #define TCPWM_LINEx_PORT                  GPIO_PRT6
  #define TCPWM_LINEx_PIN                   0u
  #define TCPWM_LINEx_MUX                   P6_0_TCPWM0_LINE256

  /* TCPWM_LINE_COMPL */
  #define TCPWM_LINE_CMPLx_PORT             GPIO_PRT6
  #define TCPWM_LINE_CMPLx_PIN              1u
  #define TCPWM_LINE_CMPLx_MUX              P6_1_TCPWM0_LINE_COMPL256

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

cy_stc_tcpwm_pwm_config_t const MyPWM_config =
{
    .pwmMode            = CY_TCPWM_PWM_MODE_DEADTIME,
    .clockPrescaler     = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .debug_pause        = 0uL,
    .Cc0MatchMode       = CY_TCPWM_PWM_TR_CTRL2_CLEAR,
    .OverflowMode       = CY_TCPWM_PWM_TR_CTRL2_SET,
    .UnderflowMode      = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .Cc1MatchMode       = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .deadTime           = 500,                             // Right side dead time: 500 * (1 / 2,000,000) = 250 us
    .deadTimeComp       = 1000,                            // Left side dead time :1000 * (1 / 2,000,000) = 500 us
    .runMode            = CY_TCPWM_PWM_CONTINUOUS,
    .period             = 10000 - 1,                       // 2,000,000 / 10000 = 200Hz
    .period_buff        = 32768uL,
    .enablePeriodSwap   = false,
    .compare0           = 5000,                            // 5000 / 10000 = 0.5 (duty)
    .compare1           = 16384uL,
    .enableCompare0Swap = false,
    .enableCompare1Swap = false,
    .interruptSources   = 0uL,
    .invertPWMOut       = 0uL,
    .invertPWMOutN      = 0uL,
    .killMode           = CY_TCPWM_PWM_STOP_ON_KILL,
    .switchInputMode    = 3uL,
    .switchInput        = 0uL,
    .reloadInputMode    = 3uL,
    .reloadInput        = 0uL,
    .startInputMode     = 3uL,
    .startInput         = 0uL,
    .kill0InputMode     = 3uL,
    .kill0Input         = 0uL,
    .kill1InputMode     = 3uL,
    .kill1Input         = 0uL,
    .countInputMode     = 3uL,
    .countInput         = 1uL,
};

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

void generic_isr_handler(void)
{
    /* ISR Handler */
}

int main(void)
{
    SystemInit();
    
    __enable_irq(); /* Enable global interrupts. */
    
    /*--------------------------------*/
    /* Clock Configuration for TCPWMs */
    /*--------------------------------*/
    
    /* Assign a programmable divider  for TCPWM0_GRPx_CNTx_PWM_PR */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKSx_PWM_DT, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_DT);
    
    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_DT, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_DT, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_DT);

    /*------------------------------------------------*/
    /* Port Configuration for TCPWM PR, LEDs (GPIOs)  */
    /*------------------------------------------------*/    
    pwm_line_out_pin_cfg.hsiom = TCPWM_LINEx_MUX;
    Cy_GPIO_Pin_Init(TCPWM_LINEx_PORT, TCPWM_LINEx_PIN, &pwm_line_out_pin_cfg);
    pwm_line_out_pin_cfg.hsiom = TCPWM_LINE_CMPLx_MUX;
    Cy_GPIO_Pin_Init(TCPWM_LINE_CMPLx_PORT, TCPWM_LINE_CMPLx_PIN, &pwm_line_out_pin_cfg);
    
    /* Initialize TCPWM0_GRPx_CNTx_PWM_PR as PWM-PR Mode & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWM0_GRPx_CNTx_PWM_DT, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWM0_GRPx_CNTx_PWM_DT);
    Cy_Tcpwm_TriggerStart(TCPWM0_GRPx_CNTx_PWM_DT);

    for(;;);
}

/* [] END OF FILE */
