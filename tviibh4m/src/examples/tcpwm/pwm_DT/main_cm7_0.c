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

/* To check this example is functional,
/* Please check TCPWM_LINE and TCPWM_LINE_COMPL outputs the 200Hz 
/* with right side dead time 250 [us] and left side dead time 500 [us] by Oscilloscope. */


/* PWM DT Mode Configuration def */
  
  #define TCPWMx_GRPx_CNTx_PWM_DT           TCPWM0_GRP1_CNT0
  #define PCLK_TCPWMx_CLOCKSx_PWM_DT        PCLK_TCPWM0_CLOCKS256
  #define TCPWM_PERI_CLK_DIVIDER_NO_PWM_DT  0u

  /* TCPWM_LINE */
  #define TCPWMx_LINEx_PORT                  GPIO_PRT3
  #define TCPWMx_LINEx_PIN                   5u
  #define TCPWMx_LINEx_MUX                   P3_5_TCPWM0_LINE256

  /* TCPWM_LINE_COMPL */
  #define TCPWMx_LINE_CMPLx_PORT             GPIO_PRT4
  #define TCPWMx_LINE_CMPLx_PIN              0u
  #define TCPWMx_LINE_CMPLx_MUX              P4_0_TCPWM0_LINE_COMPL256

  /* PWM_DT Period & DT configurations */
  #define TCPWMx_PERIOD                      10000    // 2,000,000 / 10000 = 200Hz
  #define TCPWMx_COMPARE0                    5000     // 5000 / 10000 = 0.5 (duty)
  #define TCPWMx_DEADTIME                    500      // Right side dead time: 500 * (1 / 2,000,000) = 250 us
  #define TCPWMx_DEADTIME_COMPL              1000     // Left side dead time :1000 * (1 / 2,000,000) = 500 us

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

cy_stc_tcpwm_pwm_config_t const MyPWM_config =
{
    .pwmMode            = CY_TCPWM_PWM_MODE_DEADTIME,
    .clockPrescaler     = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .debug_pause        = 0uL,
    .Cc0MatchMode       = CY_TCPWM_PWM_TR_CTRL2_CLEAR,
    .OverflowMode       = CY_TCPWM_PWM_TR_CTRL2_SET,
    .UnderflowMode      = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .Cc1MatchMode       = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .deadTime           = TCPWMx_DEADTIME,
    .deadTimeComp       = TCPWMx_DEADTIME_COMPL,
    .runMode            = CY_TCPWM_PWM_CONTINUOUS,
    .period             = TCPWMx_PERIOD - 1,
    .period_buff        = 32768uL,
    .enablePeriodSwap   = false,
    .compare0           = TCPWMx_COMPARE0,
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

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache
    
    __enable_irq(); /* Enable global interrupts. */
    
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_2); //CLK_HF2 enable
    
    /*--------------------------------*/
    /* Clock Configuration for TCPWMs */
    /*--------------------------------*/
    
    /* Assign a programmable divider  for TCPWMx_GRPx_CNTx_PWM_PR */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_DT, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_DT);
    
    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_DT), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_DT, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_DT), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_DT, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_DT), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_DT);

    /*------------------------------------------------*/
    /* Port Configuration for TCPWM DT, LEDs (GPIOs)  */
    /*------------------------------------------------*/    
    pwm_line_out_pin_cfg.hsiom = TCPWMx_LINEx_MUX;
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT, TCPWMx_LINEx_PIN, &pwm_line_out_pin_cfg);
    pwm_line_out_pin_cfg.hsiom = TCPWMx_LINE_CMPLx_MUX;
    Cy_GPIO_Pin_Init(TCPWMx_LINE_CMPLx_PORT, TCPWMx_LINE_CMPLx_PIN, &pwm_line_out_pin_cfg);
    
    /* Initialize TCPWMx_GRPx_CNTx_PWM_PR as PWM-DT Mode & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWMx_GRPx_CNTx_PWM_DT, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWMx_GRPx_CNTx_PWM_DT);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_DT);

    for(;;);
}

/* [] END OF FILE */
