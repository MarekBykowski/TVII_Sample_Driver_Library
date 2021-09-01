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
    #define USER_LED_PORT           CY_LED0_PORT
    #define USER_LED_PIN            CY_LED0_PIN
    #define USER_LED_PIN_MUX        CY_LED0_PIN_MUX
#else
    #define USER_LED_PORT           CY_USER_LED1_PORT
    #define USER_LED_PIN            CY_USER_LED1_PIN
    #define USER_LED_PIN_MUX        CY_USER_LED1_PIN_MUX 
#endif

#if defined (CY_MCU_rev_a)
    #define CY_SRSS_MCWDT_FAULT        CY_SYSFLT_SRSS_MCWDT0
#elif defined (CY_MCU_rev_b)
    #define CY_SRSS_MCWDT_FAULT        CY_SYSFLT_SRSS_FAULT_MCWDT0
#endif

// #define MCWDT_TICKS_PER_SECOND     32000    /* 1 sec when clk_lf = 32 KHz */
#define MCWDT_TICKS_PER_SECOND      6400    /* 1 sec when clk_lf = 6.4 KHz (CMR bitfile) */

#define FAULT_CPU_IRQ_INDEX     CPUIntIdx2_IRQn

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =   
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,         
    .hsiom = USER_LED_PIN_MUX,                      
    .intEdge = 0,                                  
    .intMask = 0,                                  
    .vtrip = 0,                                    
    .slewRate = 0,                                 
    .driveSel = 0,                                 
    .vregEn = 0,                                   
    .ibufMode = 0,                                 
    .vtripSel = 0,                                 
    .vrefSel = 0,                                  
    .vohSel = 0,                                   
};

cy_stc_sysint_irq_t irq_cfg = 
{
    .sysIntSrc  = cpuss_interrupts_fault_0_IRQn,
    .intIdx     = FAULT_CPU_IRQ_INDEX,
    .isEnabled  = true,
};


void irqFaultReport0Handler(void)
{
    cy_en_sysflt_source_t status;
    uint32_t faultData;

    status = Cy_SysFlt_GetErrorSource(FAULT_STRUCT0);

    if(status != CY_SYSFLT_NO_FAULT)
    {
        if(status == CY_SRSS_MCWDT_FAULT) // MCWDT0 fault
        {
            faultData = Cy_SysFlt_GetData0(FAULT_STRUCT0);
            if(faultData & 0x00000001)
            {
                 // subcounter 0 lower limit fault
            }
            else if(faultData & 0x00000002)
            {
                Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN); // subcounter 0 upper limit fault
                Cy_MCWDT_ClearWatchdog(MCWDT0, CY_MCWDT_COUNTER0);
            }
            else if(faultData & 0x00000004)
            {
                 // subcounter 1 lower limit fault
            }
            else if(faultData & 0x00000008)
            {
                Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN); // subcounter 1 upper limit fault
                Cy_MCWDT_ClearWatchdog(MCWDT0, CY_MCWDT_COUNTER1);
            }
        }
    }

    Cy_SysFlt_ClearStatus(FAULT_STRUCT0);
    Cy_SysFlt_ClearInterrupt(FAULT_STRUCT0);
}

int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */
    
    /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR);

    /*********************************************************************/
    /*****                 Fault report settings                     *****/
    /*********************************************************************/
    Cy_SysFlt_ClearStatus(FAULT_STRUCT0); // clear status (typically this process is done by boot code)
    Cy_SysFlt_SetMaskByIdx(FAULT_STRUCT0, CY_SRSS_MCWDT_FAULT); // enalbe Fault MCWDT #0
    Cy_SysFlt_SetInterruptMask(FAULT_STRUCT0);

    /*********************************************************************/
    /*****                     Port settings                         *****/
    /*********************************************************************/
    user_led_port_pin_cfg.hsiom  = USER_LED_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);

    /*********************************************************************/
    /*****                   Interrupt setting                       *****/
    /*********************************************************************/
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(cpuss_interrupts_fault_0_IRQn, irqFaultReport0Handler);
    NVIC_SetPriority(FAULT_CPU_IRQ_INDEX, 0);
    NVIC_ClearPendingIRQ(FAULT_CPU_IRQ_INDEX);
    NVIC_EnableIRQ(FAULT_CPU_IRQ_INDEX);

    /*********************************************************************/
    /*****      Set Core DeepSleep of which can pause counter        *****/
    /*********************************************************************/
    Cy_MCWDT_CpuSelectForDpSlpPauseAction(MCWDT0, CY_MCWDT_PAUSED_BY_DPSLP_CM0);

    /*********************************************************************/
    /*****                        Set actions                        *****/
    /*********************************************************************/
    Cy_MCWDT_SetLowerAction(MCWDT0, CY_MCWDT_COUNTER0, CY_MCWDT_ACTION_NONE);
    Cy_MCWDT_SetUpperAction(MCWDT0, CY_MCWDT_COUNTER0, CY_MCWDT_ACTION_FAULT); // sub counter 0 upper limit fault is intended
    Cy_MCWDT_SetWarnAction(MCWDT0, CY_MCWDT_COUNTER0, CY_MCWDT_WARN_ACTION_NONE);

    Cy_MCWDT_SetLowerAction(MCWDT0, CY_MCWDT_COUNTER1, CY_MCWDT_ACTION_NONE);
    Cy_MCWDT_SetUpperAction(MCWDT0, CY_MCWDT_COUNTER1, CY_MCWDT_ACTION_FAULT);
    Cy_MCWDT_SetWarnAction(MCWDT0, CY_MCWDT_COUNTER1, CY_MCWDT_WARN_ACTION_NONE);

    Cy_MCWDT_SetSubCounter2Action(MCWDT0, CY_MCWDT_CNT2_ACTION_NONE);

    /*********************************************************************/
    /*****                      Set limit values                     *****/
    /*********************************************************************/
    Cy_MCWDT_SetLowerLimit(MCWDT0, CY_MCWDT_COUNTER0, 0, 0);
    Cy_MCWDT_SetWarnLimit(MCWDT0, CY_MCWDT_COUNTER0, 0, 0);
    Cy_MCWDT_SetUpperLimit(MCWDT0, CY_MCWDT_COUNTER0, MCWDT_TICKS_PER_SECOND, 0);  /* 1 sec */

    Cy_MCWDT_SetLowerLimit(MCWDT0, CY_MCWDT_COUNTER1, 0, 0);
    Cy_MCWDT_SetWarnLimit(MCWDT0, CY_MCWDT_COUNTER1, 0, 0);
    Cy_MCWDT_SetUpperLimit(MCWDT0, CY_MCWDT_COUNTER1, MCWDT_TICKS_PER_SECOND * 2, 0);  /* 2 sec */

    Cy_MCWDT_SetToggleBit(MCWDT0, CY_MCWDT_CNT2_MONITORED_BIT15); // means 32768 count period


    /*********************************************************************/
    /*****                        Set options                        *****/
    /*********************************************************************/
    Cy_MCWDT_SetAutoService(MCWDT0, CY_MCWDT_COUNTER0, 0u); // disable
    Cy_MCWDT_SetAutoService(MCWDT0, CY_MCWDT_COUNTER1, 0u); // disable

    Cy_MCWDT_SetSleepDeepPause(MCWDT0, CY_MCWDT_COUNTER0, 1u); // enable
    Cy_MCWDT_SetSleepDeepPause(MCWDT0, CY_MCWDT_COUNTER1, 1u); // enable
    Cy_MCWDT_SetSleepDeepPause(MCWDT0, CY_MCWDT_COUNTER2, 1u); // enable

    Cy_MCWDT_SetDebugRun(MCWDT0, CY_MCWDT_COUNTER0, 1u); // enable
    Cy_MCWDT_SetDebugRun(MCWDT0, CY_MCWDT_COUNTER1, 1u); // enable
    Cy_MCWDT_SetDebugRun(MCWDT0, CY_MCWDT_COUNTER2, 1u); // enable

    Cy_MCWDT_Enable(MCWDT0, 
                    CY_MCWDT_CTR_Msk,  // enable all counter
                    0u);

    while(Cy_MCWDT_GetEnabledStatus(MCWDT0, CY_MCWDT_COUNTER0) != 1u);
    while(Cy_MCWDT_GetEnabledStatus(MCWDT0, CY_MCWDT_COUNTER1) != 1u);
    while(Cy_MCWDT_GetEnabledStatus(MCWDT0, CY_MCWDT_COUNTER2) != 1u);
    
    for(;;)
    {
    }
}



/* [] END OF FILE */
