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

#if (CY_USE_PSVP == 1)
    #define USER_LED1_PORT           CY_LED0_PORT
    #define USER_LED1_PIN            CY_LED0_PIN
    #define USER_LED1_PIN_MUX        CY_LED0_PIN_MUX

    #define USER_LED2_PORT           CY_LED1_PORT
    #define USER_LED2_PIN            CY_LED1_PIN
    #define USER_LED2_PIN_MUX        CY_LED1_PIN_MUX
#else
    #define USER_LED1_PORT           CY_USER_LED1_PORT
    #define USER_LED1_PIN            CY_USER_LED1_PIN
    #define USER_LED1_PIN_MUX        CY_USER_LED1_PIN_MUX

    #define USER_LED2_PORT           CY_USER_LED2_PORT
    #define USER_LED2_PIN            CY_USER_LED2_PIN
    #define USER_LED2_PIN_MUX        CY_USER_LED2_PIN_MUX
#endif

void evtgenStruct0Handler(void);
void evtgenStruct1Handler(void);

const cy_stc_gpio_pin_config_t user_led1_port_pin_cfg = 
{
    .outVal    = 0x00,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = USER_LED1_PIN_MUX,
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

const cy_stc_gpio_pin_config_t user_led2_port_pin_cfg = 
{
    .outVal    = 0x00,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = USER_LED2_PIN_MUX,
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

const cy_stc_evtgen_config_t evtgenTestConfig = 
{
  #if (CY_USE_PSVP == 1)
    .frequencyRef          = 24000000, // clk_ref = clk_hf1 = CLK_PATH0 -> 24,000,000 for PSVP test.
    .frequencyLf           = 32000,    // clk_lf = 32,000 for PSVP test
  #else
    .frequencyRef          = 8000000,  //  clk_ref = clk_hf3 = CLK_PATH9 (IMO) -> 8,000,000 for silicon
    .frequencyLf           = 32000,    // clk_lf = 32,000 for silicon
  #endif
    
    .frequencyTick         = 1000000,  // Setting 1,000,000 Hz for event generator clock (clk_ref_div)
    .ratioControlMode      = CY_EVTGEN_RATIO_CONTROL_SW,
    .ratioValueDynamicMode = CY_EVTGEN_RATIO_DYNAMIC_MODE0,
};

const cy_stc_evtgen_struct_config_t evtgenStructure0Config =
{
    .functionalitySelection = CY_EVTGEN_ACTIVE_FUNCTIONALITY,
    .triggerOutEdge         = CY_EVTGEN_EDGE_SENSITIVE,
    .valueActiveComparator  = 1000000, // In active functionality, this value is used for making period of interrupts/triggers
                                       // 1,000,000 / 1,000,000 (clk_ref_div) = 1[s]
    .userIsr                = evtgenStruct0Handler,
};

const cy_stc_evtgen_struct_config_t evtgenStructure1Config = 
{
    .functionalitySelection= CY_EVTGEN_ACTIVE_FUNCTIONALITY,
    .triggerOutEdge        = CY_EVTGEN_EDGE_SENSITIVE,
    .valueActiveComparator = 1300000, // In active functionality, this value is used for making period of interrupts/triggers
                                      // 1,300,000 / 1,000,000 (clk_ref_div) = 1.3[s]
    .userIsr               = evtgenStruct1Handler,
};

cy_stc_sysint_irq_t irq_cfg = 
{
    .sysIntSrc  = evtgen_0_interrupt_IRQn,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = true,
};

cy_stc_evtgen_struct_context_t evtgenStruct0Context;
cy_stc_evtgen_struct_context_t evtgenStruct1Context;

void evtgenStruct0Handler(void)
{
    Cy_GPIO_Inv(USER_LED1_PORT, USER_LED1_PIN);
}

void evtgenStruct1Handler(void)
{
    Cy_GPIO_Inv(USER_LED2_PORT, USER_LED2_PIN);
}

void irqEVTGEN(void)
{
    Cy_Evtgen_Interrupt(EVTGEN0);
}

int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /************************/
    /*  LED Ports settings  */
    /************************/
    Cy_GPIO_Pin_Init(USER_LED1_PORT, USER_LED1_PIN, &user_led1_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_LED2_PORT, USER_LED2_PIN, &user_led2_port_pin_cfg);

    /*******************************************/
    /*  Interrupt setting for Event Generator  */
    /*******************************************/
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, irqEVTGEN);
    NVIC_EnableIRQ(irq_cfg.intIdx);

    /*********************/
    /*  Enable clk_hf3   */
    /*********************/
  #if (CY_USE_PSVP == 1)
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_3);
    Cy_SysClk_HfClockSetSource(CY_SYSCLK_HFCLK_3, CY_SYSCLK_HFCLK_IN_CLKPATH0);
  #else
    Cy_SysClk_ClkPathSetSource(9u, CY_SYSCLK_CLKPATH_IN_IMO);
    Cy_SysClk_HfClockSetDivider(CY_SYSCLK_HFCLK_3, CY_SYSCLK_HFCLK_NO_DIVIDE);
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_3);
    Cy_SysClk_HfClockSetSource(CY_SYSCLK_HFCLK_3, CY_SYSCLK_HFCLK_IN_CLKPATH9);
  #endif

    /*******************************************/
    /*  Initialize and start Event generator   */
    /*******************************************/
    Cy_Evtgen_Initialize(EVTGEN0, &evtgenTestConfig);

    /*******************************************/
    /*  Initialize comparator structure 0      */
    /*******************************************/
    Cy_Evtgen_InitializeCompStruct(EVTGEN0, 0, &evtgenStructure0Config, &evtgenStruct0Context);

    /*******************************************/
    /*  Initialize comparator structure 1      */
    /*******************************************/
    Cy_Evtgen_InitializeCompStruct(EVTGEN0, 1, &evtgenStructure1Config, &evtgenStruct1Context);
    
    // Note: if program is halted by debugger, the EVTGEN counter continues running and the correlation to the comparator update done by SW in EVTGEN IRQ handler may be lost.

    for(;;);
}

/* [] END OF FILE */

