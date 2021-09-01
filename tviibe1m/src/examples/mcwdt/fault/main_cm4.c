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

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = CY_LED8_PIN_MUX,
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
    .sysIntSrc  = cpuss_interrupts_fault_1_IRQn,
    .intIdx     = CPUIntIdx2_IRQn,
    .isEnabled  = true,
};

cy_stc_mcwdt_config_t mcwdtConfig = 
{
    .coreSelect       = CY_MCWDT_PAUSED_BY_DPSLP_CM4_CM7_0,
    .c0LowerLimit     = 0,
    // Because of an Errata of SRSS_ver2 if fault of sub-counter0 and sub-counter1 
    // occurred at the same time. One of these fault will be ignored.
    // Therefore I avoid setting exactly divisible number of sub-counter1.
    .c0UpperLimit     = 32002,   /* 1 sec when clk_lf = 32KHz */
    .c0WarnLimit      = 0,
    .c0LowerAction    = CY_MCWDT_ACTION_NONE,
    .c0UpperAction    = CY_MCWDT_ACTION_FAULT,
    .c0WarnAction     = CY_MCWDT_WARN_ACTION_NONE,
    .c0AutoService    = CY_MCWDT_DISABLE,
    .c0SleepDeepPause = CY_MCWDT_ENABLE,
    .c0DebugRun       = CY_MCWDT_ENABLE,
    .c1LowerLimit     = 0,
    .c1UpperLimit     = 64000,  /* 2 sec when clk_lf = 32KHz */
    .c1WarnLimit      = 0,
    .c1LowerAction    = CY_MCWDT_ACTION_NONE,
    .c1UpperAction    = CY_MCWDT_ACTION_FAULT,
    .c1WarnAction     = CY_MCWDT_WARN_ACTION_NONE,
    .c1AutoService    = CY_MCWDT_DISABLE,
    .c1SleepDeepPause = CY_MCWDT_ENABLE,
    .c1DebugRun       = CY_MCWDT_ENABLE,
    .c2ToggleBit      = CY_MCWDT_CNT2_MONITORED_BIT15,
    .c2Action         = CY_MCWDT_CNT2_ACTION_INT,
    .c2SleepDeepPause = CY_MCWDT_ENABLE,
    .c2DebugRun       = CY_MCWDT_ENABLE,
};

void irqFaultReport1Handler(void)
{
    cy_en_sysflt_source_t status;
    uint32_t faultData;

    status = Cy_SysFlt_GetErrorSource(FAULT_STRUCT1);

    if(status != CY_SYSFLT_NO_FAULT)
    {
        if(status == CY_SYSFLT_SRSS_MCWDT1) // MCWDT1 fault
        {
            faultData = Cy_SysFlt_GetData0(FAULT_STRUCT1);
            if(faultData & 0x00000001ul)
            {
                 // subcounter 0 lower limit fault
            }
            else if(faultData & 0x00000002ul)
            {
                Cy_GPIO_Inv(CY_LED8_PORT, CY_LED8_PIN); // subcounter 0 upper limit fault
                Cy_MCWDT_ClearWatchdog(MCWDT1, CY_MCWDT_COUNTER0);
            }
            else if(faultData & 0x00000004ul)
            {
                 // subcounter 1 lower limit fault
            }
            else if(faultData & 0x00000008ul)
            {
                Cy_GPIO_Inv(CY_LED9_PORT, CY_LED9_PIN); // subcounter 1 upper limit fault
                Cy_MCWDT_ClearWatchdog(MCWDT1, CY_MCWDT_COUNTER1);
            }
        }
    }

    Cy_SysFlt_ClearStatus(FAULT_STRUCT1);
    Cy_SysFlt_ClearInterrupt(FAULT_STRUCT1);
}


int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /*********************************************************************/
    /*****                 Fault report settings                     *****/
    /*********************************************************************/
    Cy_SysFlt_ClearStatus(FAULT_STRUCT1); // clear status (typically this process is done by boot code)
    Cy_SysFlt_SetMaskByIdx(FAULT_STRUCT1, CY_SYSFLT_SRSS_MCWDT1); // enalbe Fault MCWDT #1
    Cy_SysFlt_SetInterruptMask(FAULT_STRUCT1);

    /*********************************************************************/
    /*****                     Port settings                         *****/
    /*********************************************************************/
    user_led_port_pin_cfg.hsiom = CY_LED8_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_LED8_PORT, CY_LED8_PIN, &user_led_port_pin_cfg);

    user_led_port_pin_cfg.hsiom = CY_LED9_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_LED9_PORT, CY_LED9_PIN, &user_led_port_pin_cfg);

    /*********************************************************************/
    /*****                   Interrupt setting                       *****/
    /*********************************************************************/
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, irqFaultReport1Handler);
    NVIC_SetPriority(CPUIntIdx2_IRQn, 0);
    NVIC_EnableIRQ(CPUIntIdx2_IRQn);

    Cy_MCWDT_DeInit(MCWDT1);
    Cy_MCWDT_Init(MCWDT1, &mcwdtConfig);

    Cy_MCWDT_Unlock(MCWDT1);
    Cy_MCWDT_SetInterruptMask(MCWDT1, CY_MCWDT_CTR_Msk);
    Cy_MCWDT_Enable(MCWDT1, 
                    CY_MCWDT_CTR_Msk,  // enable all counter
                    0);
    Cy_MCWDT_Lock(MCWDT1);

    for(;;)
    {
    }
}



/* [] END OF FILE */
