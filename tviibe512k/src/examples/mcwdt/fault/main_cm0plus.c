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

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = CY_LED0_PIN_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
    .vregEn    = 0ul,
    .ibufMode  = 0ul,
    .vtripSel  = 0ul,
    .vrefSel   = 0ul,
    .vohSel    = 0ul,
};

cy_stc_sysint_irq_t irq_cfg =
{
    .sysIntSrc  = cpuss_interrupts_fault_0_IRQn,
    .intIdx     = CPUIntIdx2_IRQn,
    .isEnabled  = true,
};


void irqFaultReport0Handler(void)
{
    cy_en_sysflt_source_t status;
    uint32_t faultData;

    status = Cy_SysFlt_GetErrorSource(FAULT_STRUCT0);

    if(status != CY_SYSFLT_NO_FAULT)
    {
        if(status == CY_SYSFLT_SRSS_MCWDT0) // MCWDT0 fault
        {
            faultData = Cy_SysFlt_GetData0(FAULT_STRUCT0);
            if(faultData & 0x00000001ul)
            {
                 // subcounter 0 lower limit fault
            }
            else if(faultData & 0x00000002ul)
            {
                Cy_GPIO_Inv(CY_LED0_PORT, CY_LED0_PIN); // subcounter 0 upper limit fault
                Cy_MCWDT_ClearWatchdog(MCWDT0, CY_MCWDT_COUNTER0);
            }
            else if(faultData & 0x00000004ul)
            {
                 // subcounter 1 lower limit fault
            }
            else if(faultData & 0x00000008ul)
            {
                Cy_GPIO_Inv(CY_LED1_PORT, CY_LED1_PIN); // subcounter 1 upper limit fault
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
    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR); 


    /*********************************************************************/
    /*****                 Fault report settings                     *****/
    /*********************************************************************/
    Cy_SysFlt_ClearStatus(FAULT_STRUCT0); // clear status (typically this process is done by boot code)
    Cy_SysFlt_SetMaskByIdx(FAULT_STRUCT0, CY_SYSFLT_SRSS_MCWDT0); // enalbe Fault MCWDT #0
    Cy_SysFlt_SetInterruptMask(FAULT_STRUCT0);

    /*********************************************************************/
    /*****                     Port settings                         *****/
    /*********************************************************************/
    user_led_port_pin_cfg.hsiom  = CY_LED0_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_LED0_PORT, CY_LED0_PIN, &user_led_port_pin_cfg);

    user_led_port_pin_cfg.hsiom  = CY_LED1_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_LED1_PORT, CY_LED1_PIN, &user_led_port_pin_cfg);

    /*********************************************************************/
    /*****                   Interrupt setting                       *****/
    /*********************************************************************/
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, irqFaultReport0Handler);
    NVIC_SetPriority(CPUIntIdx2_IRQn, 0);
    NVIC_EnableIRQ(CPUIntIdx2_IRQn);

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
    // Because of an Errata of SRSS_ver2 if fault of sub-counter0 and sub-counter1 
    // occured at the same time. One of these fault will be ignored.
    // Therefore I avoid setting exactly divisible number of sub-counter1.
    Cy_MCWDT_SetUpperLimit(MCWDT0, CY_MCWDT_COUNTER0, 32002, 0);  /* 1 sec when clk_lf = 32KHz */

    Cy_MCWDT_SetLowerLimit(MCWDT0, CY_MCWDT_COUNTER1, 0, 0);
    Cy_MCWDT_SetWarnLimit(MCWDT0, CY_MCWDT_COUNTER1, 0, 0);
    Cy_MCWDT_SetUpperLimit(MCWDT0, CY_MCWDT_COUNTER1, 64000, 0);  /* 2 sec when clk_lf = 32KHz */

    Cy_MCWDT_SetToggleBit(MCWDT0, CY_MCWDT_CNT2_MONITORED_BIT15); // means 32768 count period


    /*********************************************************************/
    /*****                        Set options                        *****/
    /*********************************************************************/
    Cy_MCWDT_SetAutoService(MCWDT0, CY_MCWDT_COUNTER0, 0ul); // disable
    Cy_MCWDT_SetAutoService(MCWDT0, CY_MCWDT_COUNTER1, 0ul); // disable

    Cy_MCWDT_SetSleepDeepPause(MCWDT0, CY_MCWDT_COUNTER0, 1ul); // enable
    Cy_MCWDT_SetSleepDeepPause(MCWDT0, CY_MCWDT_COUNTER1, 1ul); // enable
    Cy_MCWDT_SetSleepDeepPause(MCWDT0, CY_MCWDT_COUNTER2, 1ul); // enable

    Cy_MCWDT_SetDebugRun(MCWDT0, CY_MCWDT_COUNTER0, 1ul); // enable
    Cy_MCWDT_SetDebugRun(MCWDT0, CY_MCWDT_COUNTER1, 1ul); // enable
    Cy_MCWDT_SetDebugRun(MCWDT0, CY_MCWDT_COUNTER2, 1ul); // enable

    Cy_MCWDT_Enable(MCWDT0, 
                    CY_MCWDT_CTR_Msk,  // enable all counter
                    0);

    while(Cy_MCWDT_GetEnabledStatus(MCWDT0, CY_MCWDT_COUNTER0) != 1ul);
    while(Cy_MCWDT_GetEnabledStatus(MCWDT0, CY_MCWDT_COUNTER1) != 1ul);
    while(Cy_MCWDT_GetEnabledStatus(MCWDT0, CY_MCWDT_COUNTER2) != 1ul);
    
    for(;;)
    {
    }
}



/* [] END OF FILE */
