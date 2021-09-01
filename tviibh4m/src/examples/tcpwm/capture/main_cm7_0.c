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

/* Please short TCPWM0_TR_ONE_CNT_IN0 and TCPWM0_LINE1 */
/* Check Duty and Period by Oscilloscope. */

/* Capture Mode Configuration def */
#define TCPWMx_GRPx_CNTx_CAPTURE                TCPWM0_GRP0_CNT0
#define PCLK_TCPWMx_CLOCKSx_CAPTURE             PCLK_TCPWM0_CLOCKS0
#define TCPWMx_PERI_CLK_DIVIDER_NO_CAPTURE      0u

/* P6_4_TCPWM0_TR_ONE_CNT_IN0 */
#define TCPWMx_TR_ONE_CNT_INx_PORT               GPIO_PRT6
#define TCPWMx_TR_ONE_CNT_INx_PIN                1u
#define TCPWMx_TR_ONE_CNT_INx_MUX                P6_1_TCPWM0_TR_ONE_CNT_IN0

/* PWM Configuration def */
#define TCPWMx_GRPx_CNTx_PWM                     TCPWM0_GRP0_CNT1
#define PCLK_TCPWMx_CLOCKSx_PWM                  PCLK_TCPWM0_CLOCKS1
#define TCPWMx_PERI_CLK_DIVIDER_NO_PWM           1u

/* P7_0_TCPWM0_LINE1, */
#define TCPWMx_LINEx_PORT                        GPIO_PRT6
#define TCPWMx_LINEx_PIN                         3u
#define TCPWMx_LINEx_MUX                         P6_3_TCPWM0_LINE1

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
cy_stc_gpio_pin_config_t tcpwm_trig_in_pin_cfg = 
{
    .outVal    = 0x0u,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom     = TCPWMx_TR_ONE_CNT_INx_MUX,
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

cy_stc_tcpwm_counter_config_t const MyCounter_config =
{
    .period             = 0xFFFF,                             // A TCPWM in GRP0 has 16 bit counter
    .clockPrescaler     = CY_TCPWM_COUNTER_PRESCALER_DIVBY_4, // 2,000,000 / 4 = 500,000 Hz
    .runMode            = CY_TCPWM_PWM_CONTINUOUS,
    .countDirection     = CY_TCPWM_COUNTER_COUNT_UP,
    .debug_pause        = 0uL,
    .CompareOrCapture   = CY_TCPWM_COUNTER_MODE_CAPTURE,
    .compare0           = 500uL,
    .compare0_buff      = 32768uL,
    .compare1           = 16384uL,
    .compare1_buff      = 32768uL,
    .enableCompare0Swap = false,
    .enableCompare1Swap = false,
    .interruptSources   = 0uL,
    .capture0InputMode  = 0uL,                                // detect rising edge
    .capture0Input      = 2uL,
    .reloadInputMode    = 3uL,
    .reloadInput        = 0uL,
    .startInputMode     = 3uL,
    .startInput         = 0uL,
    .stopInputMode      = 3uL,
    .stopInput          = 0uL,
    .capture1InputMode  = 1uL,                                // detect falling edge
    .capture1Input      = 2uL,
    .countInputMode     = 3uL,
    .countInput         = 1uL,
    .trigger1           = CY_TCPWM_COUNTER_CC0_MATCH,
};

cy_stc_tcpwm_pwm_config_t const MyPWM_config =
{
    .pwmMode            = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler     = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .debug_pause        = 0uL,
    .Cc0MatchMode       = CY_TCPWM_PWM_TR_CTRL2_CLEAR,
    .OverflowMode       = CY_TCPWM_PWM_TR_CTRL2_SET,
    .UnderflowMode      = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .Cc1MatchMode       = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .deadTime           = 0uL,
    .deadTimeComp       = 0uL,
    .runMode            = CY_TCPWM_PWM_CONTINUOUS,
    .period             = 2560 - 1,                            // Period = 2560 / 2000000 = 1280 [us]
    .period_buff        = 32768uL,
    .enablePeriodSwap   = false,
    .compare0           = 640,                                 // Duty 25% (High duration: 320 [us], Low duration: 960 [us])
    .compare1           = 16384uL,
    .enableCompare0Swap = false,
    .enableCompare1Swap = false,
    .interruptSources   = 0uL,
    .invertPWMOut       = 0uL,
    .invertPWMOutN      = 0uL,
    .killMode           = CY_TCPWM_PWM_STOP_ON_KILL,
    .switchInputMode    = 3uL ,
    .switchInput        = 0uL,
    .reloadInputMode    = 3uL ,
    .reloadInput        = 0uL,
    .startInputMode     = 3uL ,
    .startInput         = 0uL,
    .kill0InputMode     = 3uL ,
    .kill0Input         = 0uL,
    .kill1InputMode     = 3uL ,
    .kill1Input         = 0uL,
    .countInputMode     = 3uL ,
    .countInput         = 1uL,
};

cy_stc_sysint_irq_t irq_cfg = 
{
    .sysIntSrc  = tcpwm_0_interrupts_0_IRQn,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = true,
};

uint32_t g_periodLow_us  = 0u;
uint32_t g_periodHigh_us = 0u;
uint32_t g_duty          = 0u;

void capture_isr_handler(void)
{
    static uint16_t countCC0Match = 0u;
    static uint16_t countCC1Match = 0u;
    static uint16_t g_countLow    = 0u;
    static uint16_t g_countHigh   = 0u;

    if(Cy_Tcpwm_Counter_GetCC0_IntrMasked(TCPWMx_GRPx_CNTx_CAPTURE))
    {
        // CCO would capture rising edge of input pulse.
        Cy_Tcpwm_Counter_ClearCC0_Intr(TCPWMx_GRPx_CNTx_CAPTURE);

        countCC0Match = Cy_Tcpwm_Counter_GetCompare0(TCPWMx_GRPx_CNTx_CAPTURE);
        if(countCC0Match >= countCC1Match)
        {
            g_countLow = countCC0Match - countCC1Match;
        }
        else
        {
            g_countLow = countCC0Match + (uint16_t)(0x10000 - (uint32_t)countCC1Match);
        }
        g_periodLow_us = g_countLow * 1000000 / 500000;
    }

    if(Cy_Tcpwm_Counter_GetCC1_IntrMasked(TCPWMx_GRPx_CNTx_CAPTURE))
    {
        // CC1 would capture falling edge of input pulse.
        Cy_Tcpwm_Counter_ClearCC1_Intr(TCPWMx_GRPx_CNTx_CAPTURE);

        countCC1Match = Cy_Tcpwm_Counter_GetCompare1(TCPWMx_GRPx_CNTx_CAPTURE);
        if(countCC1Match >= countCC0Match)
        {
            g_countHigh = countCC1Match - countCC0Match;
        }
        else
        {
            g_countHigh = countCC1Match + (uint16_t)(0x10000 - (uint32_t)countCC0Match);
        }
        g_periodHigh_us = g_countHigh * 1000000 / 500000;
    }
    
    g_duty = (g_periodHigh_us * 100) / (g_periodHigh_us + g_periodLow_us);
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
    
    /* Assign a programmable divider for PCLK_TCPWMx_CLOCKSx_CAPTURE */    
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_CAPTURE, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_CAPTURE);

    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_CAPTURE), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_CAPTURE, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_CAPTURE), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_CAPTURE, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif

    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_CAPTURE), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_CAPTURE);

    /* Assign a programmable divider for PCLK_TCPWMx_CLOCKSx_PWM */  
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM);

    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif    

    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM), (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM);


    /*--------------------------------*/
    /* Interrupt setting for Capture  */
    /*--------------------------------*/
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, capture_isr_handler);
    /* Set the Interrupt Priority & Enable the Interrupt */
    NVIC_SetPriority(CPUIntIdx3_IRQn, 3u);
    NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);

    NVIC_EnableIRQ(CPUIntIdx3_IRQn);

    /*------------------------------------------*/
    /* Port Configuration for PWM, Counter Trig */
    /*------------------------------------------*/
    Cy_GPIO_Pin_Init(TCPWMx_TR_ONE_CNT_INx_PORT, TCPWMx_TR_ONE_CNT_INx_PIN, &tcpwm_trig_in_pin_cfg);
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT, TCPWMx_LINEx_PIN, &pwm_line_out_pin_cfg);

    /* Initialize PCLK_TCPWM0_CLOCKSx_CAPTURE as Capture Mode & Enable */
    Cy_Tcpwm_Counter_Init(TCPWMx_GRPx_CNTx_CAPTURE, &MyCounter_config);
    Cy_Tcpwm_Counter_SetCC0_IntrMask(TCPWMx_GRPx_CNTx_CAPTURE);
    Cy_Tcpwm_Counter_SetCC1_IntrMask(TCPWMx_GRPx_CNTx_CAPTURE);
    Cy_Tcpwm_Counter_Enable(TCPWMx_GRPx_CNTx_CAPTURE);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_CAPTURE); 

    /* Initialize TCPWM0_GRPx_CNTx_PWM as PWM & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWMx_GRPx_CNTx_PWM, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWMx_GRPx_CNTx_PWM);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM);

    for(;;);
}

/* [] END OF FILE */
