/***************************************************************************//**
* \file main_cm0plus.c
*
* \version 1.0
*
* \brief Main example file for CM0+
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
   Please see the LED on CPU board is blinking at the period of 1 [s]. */

#define TCPWMx_GRPx_CNTx_COUNTER          TCPWM0_GRP0_CNT0
#define PCLK_TCPWMx_CLOCKSx_COUNTER       PCLK_TCPWM0_CLOCKS0
#define TCPWM_PERI_CLK_DIVIDER_NO_COUNTER 0ul


#if (CY_USE_PSVP == 1)
    #define USER_LED_PORT           CY_LED0_PORT
    #define USER_LED_PIN            CY_LED0_PIN
    #define USER_LED_PIN_MUX        CY_LED0_PIN_MUX
#else
    #define USER_LED_PORT           CY_CB_LED_PORT
    #define USER_LED_PIN            CY_CB_LED_PIN
    #define USER_LED_PIN_MUX        CY_CB_LED_PIN_MUX 
#endif

cy_stc_gpio_pin_config_t user_led_port_pin_cfg = 
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = USER_LED_PIN_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

cy_stc_tcpwm_counter_config_t const MyCounter_config =
{
    .period             = 15625ul - 1ul,                         // 15,625 / 15625 = 1s
    .clockPrescaler     = CY_TCPWM_COUNTER_PRESCALER_DIVBY_128,  // 2,000,000Hz / 128 = 15,625Hz
    .runMode            = CY_TCPWM_PWM_CONTINUOUS,
    .countDirection     = CY_TCPWM_COUNTER_COUNT_UP,
    .debug_pause        = 0uL,
    .CompareOrCapture   = CY_TCPWM_COUNTER_MODE_COMPARE,
    .compare0           = 0ul,
    .compare0_buff      = 0ul,
    .compare1           = 0ul,
    .compare1_buff      = 0ul,
    .enableCompare0Swap = false,
    .enableCompare1Swap = false,
    .interruptSources   = 0ul,
    .capture0InputMode  = 3ul,
    .capture0Input      = 0ul,
    .reloadInputMode    = 3ul,
    .reloadInput        = 0ul,
    .startInputMode     = 3ul,
    .startInput         = 0ul,
    .stopInputMode      = 3ul,
    .stopInput          = 0ul,
    .capture1InputMode  = 3ul,
    .capture1Input      = 0ul,
    .countInputMode     = 3ul,
    .countInput         = 1ul,
    .trigger1           = CY_TCPWM_COUNTER_OVERFLOW,
};

cy_stc_sysint_irq_t irq_cfg = 
{
    .sysIntSrc  = tcpwm_0_interrupts_0_IRQn,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = true,
};

void Timer_Handler(void)
{
    if(Cy_Tcpwm_Counter_GetTC_IntrMasked(TCPWMx_GRPx_CNTx_COUNTER) == 1ul)
    {
        Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
        Cy_Tcpwm_Counter_ClearTC_Intr(TCPWMx_GRPx_CNTx_COUNTER);
    }
}

int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /*--------------------------------*/
    /* Clock Configuration for TCPWMs */
    /*--------------------------------*/
    /* Assign a programmable divider for TCPWM1_GRP0_CNT0 */
  #if (CY_USE_PSVP == 1u)
    uint32_t periFreq = 24000000ul;
  #else
    uint32_t periFreq = 80000000ul;
  #endif
    uint32_t targetFreq = 2000000ul;
    uint32_t divNum = (periFreq / targetFreq);
    CY_ASSERT((periFreq % targetFreq) == 0ul); // inaccurate target clock
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_COUNTER, CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER);
    /* Sets the 16-bit divider */
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER, (divNum-1ul));  
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER);

    /*--------------------------------*/
    /* Configure Interrupt for TCPWMs */
    /*--------------------------------*/
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, Timer_Handler);
    /* Set the Interrupt Priority & Enable the Interrupt */
    NVIC_SetPriority(irq_cfg.intIdx, 3ul);
    NVIC_EnableIRQ(irq_cfg.intIdx);

    /*--------------------------------*/
    /* Port Configuration LEDs (GPIOs)*/
    /*--------------------------------*/
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg); //USER_LED0
    
    /* Initialize TCPWM0_GPR0_CNT0 as Timer/Counter & Enable */
    Cy_Tcpwm_Counter_Init(TCPWMx_GRPx_CNTx_COUNTER, &MyCounter_config);
    Cy_Tcpwm_Counter_Enable(TCPWMx_GRPx_CNTx_COUNTER);
    Cy_Tcpwm_Counter_SetTC_IntrMask(TCPWMx_GRPx_CNTx_COUNTER); /* Enable Interrupt */
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_COUNTER);

    for(;;);
}

/* [] END OF FILE */
