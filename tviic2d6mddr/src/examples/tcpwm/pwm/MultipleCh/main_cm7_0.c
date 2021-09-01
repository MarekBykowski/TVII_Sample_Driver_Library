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

/* To check this example is functional,
   please see following pin outputs the 976.5625Hz pulse with duty 50%.  */

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

#define TCPWM_PERI_CLK_DIVIDER_COMMON_NO   0u

typedef struct
{
    volatile stc_TCPWM_GRP_CNT_t* tcpwm;
    en_clk_dst_t                  clkDest;
    volatile stc_GPIO_PRT_t*      port;
    uint32_t                      pin;
    en_hsiom_sel_t                hsiom;
} cy_stc_pwm_info_t;

// All PWM information to be used in this example
const cy_stc_pwm_info_t g_pwms[] =
{
#if (CY_USE_PSVP == 1u)
//  {             tcpwm,               clkDest,       port, pin,                hsiom },
    { TCPWM0_GRP0_CNT3,   PCLK_TCPWM0_CLOCKS3,    GPIO_PRT5, 0ul,   P5_0_TCPWM0_LINE3},
    { TCPWM0_GRP2_CNT16,  PCLK_TCPWM0_CLOCKS528,  GPIO_PRT7, 1ul,   P7_1_TCPWM0_LINE528},
    { TCPWM0_GRP0_CNT10,  PCLK_TCPWM0_CLOCKS10,   GPIO_PRT4, 5ul,   P4_5_TCPWM0_LINE10},    
    { TCPWM0_GRP0_CNT12,  PCLK_TCPWM0_CLOCKS12,   GPIO_PRT4, 7ul,   P4_7_TCPWM0_LINE12},
    { TCPWM0_GRP0_CNT18,  PCLK_TCPWM0_CLOCKS18,   GPIO_PRT8, 7ul,   P8_7_TCPWM0_LINE18},
    { TCPWM0_GRP0_CNT17,  PCLK_TCPWM0_CLOCKS17,   GPIO_PRT8, 5ul,   P8_5_TCPWM0_LINE17},  
    { TCPWM0_GRP0_CNT16,  PCLK_TCPWM0_CLOCKS16,   GPIO_PRT6, 3ul,   P6_3_TCPWM0_LINE16},    
    { TCPWM0_GRP1_CNT2,   PCLK_TCPWM0_CLOCKS258,  GPIO_PRT7, 4ul,   P7_4_TCPWM0_LINE258},
    { TCPWM0_GRP2_CNT18,  PCLK_TCPWM0_CLOCKS530,  GPIO_PRT7, 5ul,   P7_5_TCPWM0_LINE530},    
    { TCPWM0_GRP1_CNT3,   PCLK_TCPWM0_CLOCKS259,  GPIO_PRT7, 6ul,   P7_6_TCPWM0_LINE259},
#else
    { TCPWM0_GRP0_CNT3,   PCLK_TCPWM0_CLOCKS3,    GPIO_PRT5, 0ul,   P5_0_TCPWM0_LINE3},
    { TCPWM0_GRP2_CNT16,  PCLK_TCPWM0_CLOCKS528,  GPIO_PRT7, 1ul,   P7_1_TCPWM0_LINE528},
    { TCPWM0_GRP0_CNT10,  PCLK_TCPWM0_CLOCKS10,   GPIO_PRT4, 5ul,   P4_5_TCPWM0_LINE10},    
    { TCPWM0_GRP0_CNT12,  PCLK_TCPWM0_CLOCKS12,   GPIO_PRT4, 7ul,   P4_7_TCPWM0_LINE12},
    { TCPWM0_GRP0_CNT18,  PCLK_TCPWM0_CLOCKS18,   GPIO_PRT8, 7ul,   P8_7_TCPWM0_LINE18},
    { TCPWM0_GRP0_CNT17,  PCLK_TCPWM0_CLOCKS17,   GPIO_PRT8, 5ul,   P8_5_TCPWM0_LINE17},  
    { TCPWM0_GRP0_CNT16,  PCLK_TCPWM0_CLOCKS16,   GPIO_PRT6, 3ul,   P6_3_TCPWM0_LINE16},    
    { TCPWM0_GRP1_CNT2,   PCLK_TCPWM0_CLOCKS258,  GPIO_PRT7, 4ul,   P7_4_TCPWM0_LINE258},
    { TCPWM0_GRP2_CNT18,  PCLK_TCPWM0_CLOCKS530,  GPIO_PRT7, 5ul,   P7_5_TCPWM0_LINE530},    
    { TCPWM0_GRP1_CNT3,   PCLK_TCPWM0_CLOCKS259,  GPIO_PRT7, 6ul,   P7_6_TCPWM0_LINE259},
#endif
};
#define PWM_NUM (sizeof(g_pwms) / sizeof(g_pwms[0]))

/* TCWPM prescalar & Period configuration for all instances */
#define TCPWMx_PWM_PRESCALAR_DIV_x CY_TCPWM_PWM_PRESCALER_DIVBY_128 // 2,000,000 / 128 = 15,625Hz
#define TCPWMx_PERIOD              16u                              // 15,625 / 16 = 976.5625Hz (PWM frequency)
#define TCPWMx_COMPARE0            8u                               // 8 / 16 = 0.5 (PWM duty)

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
    .outVal    = 1ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = HSIOM_SEL_GPIO, // will be updated in runtime
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

cy_stc_tcpwm_pwm_config_t const MyPWM_config =
{
    .pwmMode            = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler     = TCPWMx_PWM_PRESCALAR_DIV_x,
    .debug_pause        = false,
    .Cc0MatchMode       = CY_TCPWM_PWM_TR_CTRL2_CLEAR,
    .OverflowMode       = CY_TCPWM_PWM_TR_CTRL2_SET,
    .UnderflowMode      = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .Cc1MatchMode       = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .deadTime           = 0ul,
    .deadTimeComp       = 0ul,
    .runMode            = CY_TCPWM_PWM_CONTINUOUS,
    .period             = TCPWMx_PERIOD - 1ul,
    .period_buff        = 0ul,
    .enablePeriodSwap   = false,
    .compare0           = TCPWMx_COMPARE0,
    .compare1           = 0ul,
    .enableCompare0Swap = false,
    .enableCompare1Swap = false,
    .interruptSources   = 0ul,
    .invertPWMOut       = 0ul,
    .invertPWMOutN      = 0ul,
    .killMode           = CY_TCPWM_PWM_STOP_ON_KILL,
    .switchInputMode    = 3ul,
    .switchInput        = 0ul,
    .reloadInputMode    = 3ul,
    .reloadInput        = 0ul,
    .startInputMode     = 3ul,
    .startInput         = 0ul,
    .kill0InputMode     = 3ul,
    .kill0Input         = 0ul,
    .kill1InputMode     = 3ul,
    .kill1Input         = 0ul,
    .countInputMode     = 3ul,
    .countInput         = 1ul,
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
  #if (CY_USE_PSVP == 1u)
    uint32_t sourceFreq = 24000000ul;
  #else
    uint32_t sourceFreq = 80000000ul;
  #endif
    uint32_t targetFreq = 2000000ul;
    uint32_t divNum = (sourceFreq / targetFreq);
    CY_ASSERT((sourceFreq % targetFreq) == 0ul);

    /* Assuming every TCPWM in common clock group */
    /* Sets the 16-bit divider */
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(g_pwms[0].clkDest), CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_COMMON_NO, (divNum - 1ul));
    /* Enable the divider */
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(g_pwms[0].clkDest), CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_COMMON_NO);

    for(uint32_t i = 0; i < PWM_NUM; i++)
    {
        /* Assign a programmable divider for TCPWM */
        Cy_SysClk_PeriphAssignDivider(g_pwms[i].clkDest, CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_COMMON_NO);

        /*----------------------------*/
        /* Port Configuration for PWM */
        /*----------------------------*/
        pwm_line_out_pin_cfg.hsiom = g_pwms[i].hsiom;
        Cy_GPIO_Pin_Init(g_pwms[i].port, g_pwms[i].pin, &pwm_line_out_pin_cfg);

        /* Initialize PWM & Enable */
        Cy_Tcpwm_Pwm_Init(g_pwms[i].tcpwm, &MyPWM_config);
        Cy_Tcpwm_Pwm_Enable(g_pwms[i].tcpwm);
        Cy_Tcpwm_TriggerStart(g_pwms[i].tcpwm);
    }

    for(;;);
}

/* [] END OF FILE */
