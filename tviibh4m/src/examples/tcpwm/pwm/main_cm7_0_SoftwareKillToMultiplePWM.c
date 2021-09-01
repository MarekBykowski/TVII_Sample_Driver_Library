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

/* Please check TCPWM0_LINE0 outputs the 976.5625Hz pulse with duty 50% by Oscilloscope. */
/* PWM Mode Configuration def for 1st instance*/
#define TCPWMx_GRPx_CNTx_PWM_INST1            TCPWM0_GRP0_CNT0
#define PCLK_TCPWMx_CLOCKSx_PWM_INST1         PCLK_TCPWM0_CLOCKS0
#define TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST1   0u

/* TCPWM LINE Output for 1st instance */
#define TCPWMx_LINEx_PORT_INST1                GPIO_PRT6
#define TCPWMx_LINEx_PIN_INST1                 1u
#define TCPWMx_LINEx_MUX_INST1                 P6_1_TCPWM0_LINE0

/* Please check TCPWM0_LINE1 outputs the 976.5625Hz pulse with duty 50% by Oscilloscope. */
/* PWM Mode Configuration def for 2nd instance*/
#define TCPWMx_GRPx_CNTx_PWM_INST2            TCPWM0_GRP0_CNT1
#define PCLK_TCPWMx_CLOCKSx_PWM_INST2         PCLK_TCPWM0_CLOCKS1
#define TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST2   1u

/* TCPWM LINE Output for 2nd instance */
#define TCPWMx_LINEx_PORT_INST2                GPIO_PRT6
#define TCPWMx_LINEx_PIN_INST2                 3u
#define TCPWMx_LINEx_MUX_INST2                 P6_3_TCPWM0_LINE1

/* Please check TCPWM0_LINE2 outputs the 976.5625Hz pulse with duty 50% by Oscilloscope. */
/* PWM Mode Configuration def for 3rd instance*/
#define TCPWMx_GRPx_CNTx_PWM_INST3            TCPWM0_GRP0_CNT2
#define PCLK_TCPWMx_CLOCKSx_PWM_INST3         PCLK_TCPWM0_CLOCKS2
#define TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST3   2u

/* TCPWM LINE Output for 3rd instance */
#define TCPWMx_LINEx_PORT_INST3                GPIO_PRT6
#define TCPWMx_LINEx_PIN_INST3                 5u
#define TCPWMx_LINEx_MUX_INST3                 P6_5_TCPWM0_LINE2

/* Please check TCPWM0_LINE3 outputs the 976.5625Hz pulse with duty 50% by Oscilloscope. */
/* PWM Mode Configuration def for 4th instance*/
#define TCPWMx_GRPx_CNTx_PWM_INST4            TCPWM0_GRP0_CNT3
#define PCLK_TCPWMx_CLOCKSx_PWM_INST4         PCLK_TCPWM0_CLOCKS3
#define TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST4   3u

/* TCPWM LINE Output for 4th instance */
#define TCPWMx_LINEx_PORT_INST4                GPIO_PRT6
#define TCPWMx_LINEx_PIN_INST4                 7u
#define TCPWMx_LINEx_MUX_INST4                 P6_7_TCPWM0_LINE3

/* Please check TCPWM0_LINE4 outputs the 976.5625Hz pulse with duty 50% by Oscilloscope. */
/* PWM Mode Configuration def for 5th instance*/
#define TCPWMx_GRPx_CNTx_PWM_INST5            TCPWM0_GRP0_CNT4
#define PCLK_TCPWMx_CLOCKSx_PWM_INST5         PCLK_TCPWM0_CLOCKS4
#define TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST5   4u

/* TCPWM LINE Output for 5th instance */
#define TCPWMx_LINEx_PORT_INST5                GPIO_PRT2
#define TCPWMx_LINEx_PIN_INST5                 3u
#define TCPWMx_LINEx_MUX_INST5                 P2_3_TCPWM0_LINE4

/* Please check TCPWM0_LINE5 outputs the 976.5625Hz pulse with duty 50% by Oscilloscope. */
/* PWM Mode Configuration def for 6th instance*/
#define TCPWMx_GRPx_CNTx_PWM_INST6            TCPWM0_GRP0_CNT5
#define PCLK_TCPWMx_CLOCKSx_PWM_INST6         PCLK_TCPWM0_CLOCKS5
#define TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST6   5u

/* TCPWM LINE Output for 6th instance */
#define TCPWMx_LINEx_PORT_INST6                GPIO_PRT4
#define TCPWMx_LINEx_PIN_INST6                 1u
#define TCPWMx_LINEx_MUX_INST6                 P4_1_TCPWM0_LINE5

/* Please check TCPWM0_LINE256 outputs the 976.5625Hz pulse with duty 50% by Oscilloscope. */
/* PWM Mode Configuration def for 7th instance*/
#define TCPWMx_GRPx_CNTx_PWM_INST7            TCPWM0_GRP1_CNT0
#define PCLK_TCPWMx_CLOCKSx_PWM_INST7         PCLK_TCPWM0_CLOCKS256
#define TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST7   6u

/* TCPWM LINE Output for 7th instance */
#define TCPWMx_LINEx_PORT_INST7                GPIO_PRT3
#define TCPWMx_LINEx_PIN_INST7                 5u
#define TCPWMx_LINEx_MUX_INST7                 P3_5_TCPWM0_LINE256

/* Please check TCPWM0_LINE257 outputs the 976.5625Hz pulse with duty 50% by Oscilloscope. */
/* PWM Mode Configuration def for 8th instance*/
#define TCPWMx_GRPx_CNTx_PWM_INST8            TCPWM0_GRP1_CNT1
#define PCLK_TCPWMx_CLOCKSx_PWM_INST8         PCLK_TCPWM0_CLOCKS257
#define TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST8   7u

/* TCPWM LINE Output for 8th instance */
#define TCPWMx_LINEx_PORT_INST8                GPIO_PRT3
#define TCPWMx_LINEx_PIN_INST8                 4u
#define TCPWMx_LINEx_MUX_INST8                 P3_4_TCPWM0_LINE257

/* Please check TCPWM0_LINE512 outputs the 976.5625Hz pulse with duty 50% by Oscilloscope. */
/* PWM Mode Configuration def for 9th instance*/
#define TCPWMx_GRPx_CNTx_PWM_INST9            TCPWM0_GRP2_CNT0
#define PCLK_TCPWMx_CLOCKSx_PWM_INST9         PCLK_TCPWM0_CLOCKS512
#define TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST9   8u

/* TCPWM LINE Output for 9th instance */
#define TCPWMx_LINEx_PORT_INST9                GPIO_PRT18
#define TCPWMx_LINEx_PIN_INST9                 0u
#define TCPWMx_LINEx_MUX_INST9                 P18_0_TCPWM0_LINE512

/* Please check TCPWM0_LINE513 outputs the 976.5625Hz pulse with duty 50% by Oscilloscope. */
/* PWM Mode Configuration def for 10tt instance*/
#define TCPWMx_GRPx_CNTx_PWM_INST10           TCPWM0_GRP2_CNT1
#define PCLK_TCPWMx_CLOCKSx_PWM_INST10        PCLK_TCPWM0_CLOCKS513
#define TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST10  9u

/* TCPWM LINE Output for 10th instance */
#define TCPWMx_LINEx_PORT_INST10               GPIO_PRT18
#define TCPWMx_LINEx_PIN_INST10                2u
#define TCPWMx_LINEx_MUX_INST10                P18_2_TCPWM0_LINE513


/* TCWPM prescalar & Period configuration for all instances */
#define TCPWMx_PWM_PRESCALAR_DIV_x      CY_TCPWM_PWM_PRESCALER_DIVBY_1    // 2,000,000 / 1 = 2,000,000Hz
#define TCPWMx_PERIOD                   100u    // 2,000,000 / 100 = 20,000Hz (PWM frequency)
#define TCPWMx_COMPARE0                 50u     // 50 / 100 = 0.5 (PWM duty)

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
    .hsiom     = HSIOM_SEL_GPIO ,
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

cy_stc_tcpwm_pwm_config_t MyPWM_config =
{
    .pwmMode            = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler     = CY_TCPWM_PWM_PRESCALER_DIVBY_1, // 2,000,000 / 1 = 2,000,000Hz
    .debug_pause        = 0uL,
    .Cc0MatchMode       = CY_TCPWM_PWM_TR_CTRL2_CLEAR,
    .OverflowMode       = CY_TCPWM_PWM_TR_CTRL2_SET,
    .UnderflowMode      = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .Cc1MatchMode       = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .deadTime           = 0uL,
    .deadTimeComp       = 0uL,
    .runMode            = CY_TCPWM_PWM_CONTINUOUS,
    .period             = 100 - 1,                        // 2,000,000 / 100 = 20,000Hz
    .period_buff        = 0,
    .enablePeriodSwap   = false,
    .compare0           = 50,
    .compare1           = 0,
    .enableCompare0Swap = false,
    .enableCompare1Swap = false,
    .interruptSources   = 0uL,
    .invertPWMOut       = 0uL,
    .invertPWMOutN      = 0uL,
    .killMode           = 0x3,                            // Kill event stops the counter, synchronous kill mode
    .switchInputMode    = 3uL,
    .switchInput        = 0uL,
    .reloadInputMode    = 3uL,
    .reloadInput        = 0uL,
    .startInputMode     = 3uL,
    .startInput         = 0uL,
    .kill0InputMode     = 3uL,
    .kill0Input         = 5uL,                            // Initialize counter for kill on tr_all_cnt_in[0] 
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
    
    /* Assign a programmable divider for TCPWMx_GRPx_CNTx_PWM_INST1 */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_INST1, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST1);
    
    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)    
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST1), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST1, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST1), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST1, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST1), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST1);
    
    
    /* Assign a programmable divider for PCLK_TCPWMx_CLOCKSx_PWM_INST2 */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_INST2, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST2);

    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)    
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST2), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST2, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST2), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST2, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST2), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST2);
    
    
    /* Assign a programmable divider for PCLK_TCPWMx_CLOCKSx_PWM_INST3 */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_INST3, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST3);

    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)    
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST3), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST3, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST3), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST3, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST3), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST3);
    
    
    /* Assign a programmable divider for PCLK_TCPWMx_CLOCKSx_PWM_INST4 */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_INST4, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST4);

    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)    
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST4), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST4, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST4), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST4, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST4), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST4);
    
    
    /* Assign a programmable divider for PCLK_TCPWMx_CLOCKSx_PWM_INST5 */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_INST5, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST5);

    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)    
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST5), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST5, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST5), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST5, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST5), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST5);
    
    
    /* Assign a programmable divider for PCLK_TCPWMx_CLOCKSx_PWM_INST6 */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_INST6, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST6);
    
    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST6), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST6, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST6), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST6, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST6), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST6);
    
    
    /* Assign a programmable divider for PCLK_TCPWMx_CLOCKSx_PWM_INST7 */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_INST7, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST7);
    
    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST7), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST7, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST7), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST7, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST7), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST7);
    
    
    /* Assign a programmable divider for PCLK_TCPWMx_CLOCKSx_PWM_INST8 */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_INST8, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST8);
    
    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST8), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST8, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST8), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST8, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST8), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST8);
    
    
    /* Assign a programmable divider for PCLK_TCPWMx_CLOCKSx_PWM_INST9 */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_INST9, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST9);
    
    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST9), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST9, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST9), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST9, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST9), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST9);
    
    
    /* Assign a programmable divider for PCLK_TCPWMx_CLOCKSx_PWM_INST10 */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_INST10, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST10);
    
    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST10), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST10, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST10), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST10, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_INST10), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM_INST10);

 
    /*----------------------------*/
    /* Port Configuration for PWM */
    /*----------------------------*/
    pwm_line_out_pin_cfg.hsiom = TCPWMx_LINEx_MUX_INST1;
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT_INST1, TCPWMx_LINEx_PIN_INST1, &pwm_line_out_pin_cfg); //TCPWMx_LINEx_MUX_INST1
    
    pwm_line_out_pin_cfg.hsiom = TCPWMx_LINEx_MUX_INST2;
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT_INST2, TCPWMx_LINEx_PIN_INST2, &pwm_line_out_pin_cfg); //TCPWMx_LINEx_MUX_INST2
    
    pwm_line_out_pin_cfg.hsiom = TCPWMx_LINEx_MUX_INST3;
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT_INST3, TCPWMx_LINEx_PIN_INST3, &pwm_line_out_pin_cfg); //TCPWMx_LINEx_MUX_INST3
    
    pwm_line_out_pin_cfg.hsiom = TCPWMx_LINEx_MUX_INST4;
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT_INST4, TCPWMx_LINEx_PIN_INST4, &pwm_line_out_pin_cfg); //TCPWMx_LINEx_MUX_INST4
    
    pwm_line_out_pin_cfg.hsiom = TCPWMx_LINEx_MUX_INST5;
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT_INST5, TCPWMx_LINEx_PIN_INST5, &pwm_line_out_pin_cfg); //TCPWMx_LINEx_MUX_INST5
    
    pwm_line_out_pin_cfg.hsiom = TCPWMx_LINEx_MUX_INST6;
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT_INST6, TCPWMx_LINEx_PIN_INST6, &pwm_line_out_pin_cfg); //TCPWMx_LINEx_MUX_INST6
    
    pwm_line_out_pin_cfg.hsiom = TCPWMx_LINEx_MUX_INST7;
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT_INST7, TCPWMx_LINEx_PIN_INST7, &pwm_line_out_pin_cfg); //TCPWMx_LINEx_MUX_INST7
    
    pwm_line_out_pin_cfg.hsiom = TCPWMx_LINEx_MUX_INST8;
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT_INST8, TCPWMx_LINEx_PIN_INST8, &pwm_line_out_pin_cfg); //TCPWMx_LINEx_MUX_INST8
    
    pwm_line_out_pin_cfg.hsiom = TCPWMx_LINEx_MUX_INST9;
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT_INST9, TCPWMx_LINEx_PIN_INST9, &pwm_line_out_pin_cfg); //TCPWMx_LINEx_MUX_INST9
    
    pwm_line_out_pin_cfg.hsiom = TCPWMx_LINEx_MUX_INST10;
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT_INST10, TCPWMx_LINEx_PIN_INST10, &pwm_line_out_pin_cfg); //TCPWMx_LINEx_MUX_INST10
   
    /* Initialize TCPWM0_GPR0_CNT0 as PWM & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWMx_GRPx_CNTx_PWM_INST1, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWMx_GRPx_CNTx_PWM_INST1);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_INST1);
    
    /* Initialize TCPWM0_GPR0_CNT1 as PWM & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWMx_GRPx_CNTx_PWM_INST2, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWMx_GRPx_CNTx_PWM_INST2);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_INST2);
    
    /* Initialize TCPWM0_GPR0_CNT2 as PWM & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWMx_GRPx_CNTx_PWM_INST3, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWMx_GRPx_CNTx_PWM_INST3);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_INST3);
    
    /* Initialize TCPWM0_GPR0_CNT6 as PWM & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWMx_GRPx_CNTx_PWM_INST4, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWMx_GRPx_CNTx_PWM_INST4);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_INST4);
    
    /* Initialize TCPWM0_GPR0_CNT9 as PWM & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWMx_GRPx_CNTx_PWM_INST5, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWMx_GRPx_CNTx_PWM_INST5);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_INST5);
    
    /* Initialize TCPWM0_GPR0_CNT10 as PWM & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWMx_GRPx_CNTx_PWM_INST6, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWMx_GRPx_CNTx_PWM_INST6);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_INST6);
    
    /* Initialize TCPWM0_GPR0_CNT15 as PWM & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWMx_GRPx_CNTx_PWM_INST7, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWMx_GRPx_CNTx_PWM_INST7);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_INST7);
    
    /* Initialize TCPWM0_GPR0_CNT17 as PWM & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWMx_GRPx_CNTx_PWM_INST8, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWMx_GRPx_CNTx_PWM_INST8);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_INST8);
    
    /* Initialize TCPWM0_GPR0_CNT18 as PWM & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWMx_GRPx_CNTx_PWM_INST9, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWMx_GRPx_CNTx_PWM_INST9);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_INST9);
    
    /* Initialize TCPWM0_GPR0_CNT19 as PWM & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWMx_GRPx_CNTx_PWM_INST10, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWMx_GRPx_CNTx_PWM_INST10);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_INST10);

    Cy_SysTick_DelayInUs(2000000);
    
    /*Trigger tr_all_cnt_in[0] by SW*/
    //Cy_TrigMux_SwTrigger(TRIG_OUT_MUX_4_TCPWM0_ALL_CNT_TR_IN0, TRIGGER_TYPE_LEVEL, 1 /*output*/);
    Cy_TrigMux_SwTrigger(TRIG_OUT_MUX_5_TCPWM_ALL_CNT_TR_IN0, TRIGGER_TYPE_LEVEL, 1 /*output*/);

    for(;;);
}

/* [] END OF FILE */
