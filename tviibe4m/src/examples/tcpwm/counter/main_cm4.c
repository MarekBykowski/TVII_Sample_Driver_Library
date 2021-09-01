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

#define PULSE_NUM    (1000u)
#define COMPARE1_NUM (500u)

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/
/* Counter Configuration def */

  /* If you use 176 pin MCU on Rev.A CPU board, please short J2.10 (Capture) and J10.7 (GPIO) on the base board. */
  /* If you use 176 pin MCU on Rev.C CPU board, please short J2.10 (Capture) and J2.13 (GPIO) on the base board. */
  /* If you use  64 pin MCU, please short J2.10 (Capture) and J10.10 (GPIO) on the base board. */

#if (CY_USE_PSVP == 1)
  #define CY_GPIO_DELAY     (50UL)
#else
  #define CY_GPIO_DELAY     (50UL * 6)
#endif

  #define TCPWM0_GRPx_CNTx_COUNTER                TCPWM0_GRP0_CNT0
  #define PCLK_TCPWM0_CLOCKSx_COUNTER             PCLK_TCPWM0_CLOCKS0
  #define TCPWM_PERI_CLK_DIVIDER_NO_COUNTER       0u
  
  /* TCPWM_TR_ONE_CNT_IN0 */
  #define TCPWM_TR_ONE_CNT_INx_PORT               GPIO_PRT6
  #define TCPWM_TR_ONE_CNT_INx_PIN                1u
  #define TCPWM_TR_ONE_CNT_INx_MUX                P6_1_TCPWM0_TR_ONE_CNT_IN0

  #define GIPO_FOR_COUNT_PORT                     GPIO_PRT6
  #define GIPO_FOR_COUNT_PIN                      3u
  #define GIPO_FOR_COUNT_MUX                      P6_3_GPIO

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
    .outVal    = 0x0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = GIPO_FOR_COUNT_MUX,
    .intEdge   = 0,
    .intMask   = 0,
    .vtrip     = 0,
    .slewRate  = 0,
    .driveSel  = 0,
    .vregEn    = 0,
    .ibufMode  = 0,
    .vtripSel  = 0,
    .vrefSel   = 0,
    .vohSel    = 0,
};

cy_stc_gpio_pin_config_t tcpwm_trig_in_pin_cfg =
{
    .outVal    = 0x0,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom     = TCPWM_TR_ONE_CNT_INx_MUX ,
    .intEdge   = 0,
    .intMask   = 0,
    .vtrip     = 0,
    .slewRate  = 0,
    .driveSel  = 0,
    .vregEn    = 0,
    .ibufMode  = 0,
    .vtripSel  = 0,
    .vrefSel   = 0,
    .vohSel    = 0,
};

cy_stc_tcpwm_counter_config_t const MyCounter_config =
{
    .period             = 0x9999,
    .clockPrescaler     = CY_TCPWM_COUNTER_PRESCALER_DIVBY_4,
    .runMode            = CY_TCPWM_COUNTER_CONTINUOUS,
    .countDirection     = CY_TCPWM_COUNTER_COUNT_UP,
    .debug_pause        = 0uL,
    .CompareOrCapture   = CY_TCPWM_COUNTER_MODE_COMPARE,
    .compare0           = COMPARE1_NUM,                       // Set the comp value
    .compare0_buff      = 32768uL,
    .compare1           = 16384uL,
    .compare1_buff      = 32768uL,
    .enableCompare0Swap = false,
    .enableCompare1Swap = false,
    .interruptSources   = 0uL,
    .capture0InputMode  = 3uL ,
    .capture0Input      = 0uL,
    .reloadInputMode    = 3uL ,
    .reloadInput        = 0uL,
    .startInputMode     = 3uL ,
    .startInput         = 0uL,
    .stopInputMode      = 3uL ,
    .stopInput          = 0uL,
    .capture1InputMode  = 3uL ,
    .capture1Input      = 0uL,
    .countInputMode     = 0uL ,                               // detect rising edge
    .countInput         = 2uL,
    .trigger1           = CY_TCPWM_COUNTER_OVERFLOW ,
};

cy_stc_sysint_irq_t irq_cfg =
{
    .sysIntSrc  = tcpwm_0_interrupts_0_IRQn,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = true,
};

uint32_t g_CntValWhenIntr = 0;
uint32_t g_CntValResult   = 0;

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

void Counter_Handler(void)
{   
    if(Cy_Tcpwm_Counter_GetCC0_IntrMasked(TCPWM0_GRPx_CNTx_COUNTER))
    {
        // PC reaches here when the counter gets over COMPARE1_NUM.
        Cy_Tcpwm_Counter_ClearCC0_Intr(TCPWM0_GRPx_CNTx_COUNTER);
        g_CntValWhenIntr = Cy_Tcpwm_Counter_GetCounter(TCPWM0_GRPx_CNTx_COUNTER);
    }
}

int main(void)
{    
    SystemInit();
    
    __enable_irq(); /* Enable global interrupts. */
    
    /*--------------------------------*/
    /* Clock Configuration for TCPWMs */
    /*--------------------------------*/
    
    /* Assign a programmable divider  for TCPWM0_GRPx_CNTx_COUNTER */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKSx_COUNTER, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER);
    
    /* Sets the 16-bit divider */ 
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
  #endif
    
    Cy_SysClk_PeriphEnableDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER); 
    
    /* Set the Interrupt Priority & Enable the Interrupt */
    Cy_SysInt_InitIRQ(&irq_cfg); 
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, Counter_Handler);	
    NVIC_SetPriority(CPUIntIdx3_IRQn, 3u);
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);
    NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);

    /*-------------------------------------------------------*/
    /* Port Configuration for PWM, Counter Trig, LEDs (GPIOs)*/
    /*-------------------------------------------------------*/
    Cy_GPIO_Pin_Init(GIPO_FOR_COUNT_PORT, GIPO_FOR_COUNT_PIN, &gpio_port_pin_cfg);
    Cy_GPIO_Write(GIPO_FOR_COUNT_PORT, GIPO_FOR_COUNT_PIN, 0);
    Cy_GPIO_Pin_Init(TCPWM_TR_ONE_CNT_INx_PORT, TCPWM_TR_ONE_CNT_INx_PIN, &tcpwm_trig_in_pin_cfg);
    
    /* Initialize TCPWM0_GRPx_CNTx_COUNTER as Counter & Enable */
    Cy_Tcpwm_Counter_Init(TCPWM0_GRPx_CNTx_COUNTER, &MyCounter_config);
    Cy_Tcpwm_Counter_Enable(TCPWM0_GRPx_CNTx_COUNTER);
    Cy_Tcpwm_TriggerStart(TCPWM0_GRPx_CNTx_COUNTER);  
    /* Enable Interrupt */
    Cy_Tcpwm_Counter_SetCC0_IntrMask(TCPWM0_GRPx_CNTx_COUNTER);

    /* Generate pulse PULSE_NUM times */
    for(uint32_t i_gpio_tgl = 0;i_gpio_tgl < PULSE_NUM; i_gpio_tgl++)
    {
        Cy_SysTick_DelayInUs(CY_GPIO_DELAY);
        Cy_GPIO_Write(GIPO_FOR_COUNT_PORT, GIPO_FOR_COUNT_PIN, 1);
        Cy_SysTick_DelayInUs(CY_GPIO_DELAY);
        Cy_GPIO_Write(GIPO_FOR_COUNT_PORT, GIPO_FOR_COUNT_PIN, 0);
    }

    /* Get the results */
    g_CntValResult = Cy_Tcpwm_Counter_GetCounter(TCPWM0_GRPx_CNTx_COUNTER);

    // In timer mode, the match interrupt occurs when 
    // the counter changes "from" a state in which COUNTER equals CC0.
    // Therefor g_CntValWhenIntr is assumed to be larger than COMPARE1_NUM by one.
    CY_ASSERT(g_CntValWhenIntr == (COMPARE1_NUM+1));

    // When the pulse is detected, this TCPWM get runnning state.
    // At this time, the pulse won't be counted. 
    // Therefor g_CntValResult is assumed to be smaller than PULSE_NUM by one.
    CY_ASSERT(g_CntValResult == (PULSE_NUM-1));

    for(;;);
}

/* [] END OF FILE */
