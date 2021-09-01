/***************************************************************************//**
* \file main_cm7_1.c
*
* \version 1.0
*
* \brief Main example file for CM7_1
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
    #define USER_LED_PORT           CY_LED9_PORT
    #define USER_LED_PIN            CY_LED9_PIN
    #define USER_LED_PIN_MUX        CY_LED9_PIN_MUX
#else
    #define USER_LED_PORT           CY_USER_LED3_PORT
    #define USER_LED_PIN            CY_USER_LED3_PIN
    #define USER_LED_PIN_MUX        CY_USER_LED3_PIN_MUX 
#endif

#if defined (CY_MCU_rev_a)
    #define CY_SRSS_MCWDT_FAULT        CY_SYSFLT_SRSS_MCWDT2
#elif defined (CY_MCU_rev_b)
    #define CY_SRSS_MCWDT_FAULT        CY_SYSFLT_SRSS_FAULT_MCWDT2
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
    .sysIntSrc  = cpuss_interrupts_fault_2_IRQn,
    .intIdx     = FAULT_CPU_IRQ_INDEX,
    .isEnabled  = true,
};

cy_stc_mcwdt_config_t mcwdtConfig = 
{
    .coreSelect       = CY_MCWDT_PAUSED_BY_DPSLP_CM7_1,
    .c0LowerLimit     = 0,
    .c0UpperLimit     = MCWDT_TICKS_PER_SECOND,  /* 1 sec */
    .c0WarnLimit      = 0,
    .c0LowerAction    = CY_MCWDT_ACTION_NONE,
    .c0UpperAction    = CY_MCWDT_ACTION_FAULT,
    .c0WarnAction     = CY_MCWDT_WARN_ACTION_NONE,
    .c0AutoService    = CY_MCWDT_DISABLE,
    .c0SleepDeepPause = CY_MCWDT_ENABLE,
    .c0DebugRun       = CY_MCWDT_ENABLE,
    .c1LowerLimit     = 0,
    .c1UpperLimit     = MCWDT_TICKS_PER_SECOND * 2, /* 2 sec */
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

void irqFaultReport2Handler(void)
{
    cy_en_sysflt_source_t status;
    uint32_t faultData;

    status = Cy_SysFlt_GetErrorSource(FAULT_STRUCT2);

    if(status != CY_SYSFLT_NO_FAULT)
    {
        if(status == CY_SRSS_MCWDT_FAULT) // MCWDT2 fault
        {
            faultData = Cy_SysFlt_GetData0(FAULT_STRUCT2);
            if(faultData & 0x00000001)
            {
                 // subcounter 0 lower limit fault
            }
            else if(faultData & 0x00000002)
            {
                Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN); // subcounter 0 upper limit fault
                Cy_MCWDT_ClearWatchdog(MCWDT2, CY_MCWDT_COUNTER0);
            }
            else if(faultData & 0x00000004)
            {
                 // subcounter 1 lower limit fault
            }
            else if(faultData & 0x00000008)
            {
                Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN); // subcounter 1 upper limit fault
                Cy_MCWDT_ClearWatchdog(MCWDT2, CY_MCWDT_COUNTER1);
            }
        }
    }

    Cy_SysFlt_ClearStatus(FAULT_STRUCT2);
    Cy_SysFlt_ClearInterrupt(FAULT_STRUCT2);
}


int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    __enable_irq(); /* Enable global interrupts. */

    /*********************************************************************/
    /*****                 Fault report settings                     *****/
    /*********************************************************************/
    Cy_SysFlt_ClearStatus(FAULT_STRUCT2); // clear status (typically this process is done by boot code)
    Cy_SysFlt_SetMaskByIdx(FAULT_STRUCT2, CY_SRSS_MCWDT_FAULT); // enalbe Fault MCWDT #2
    Cy_SysFlt_SetInterruptMask(FAULT_STRUCT2);

    /*********************************************************************/
    /*****                     Port settings                         *****/
    /*********************************************************************/
    user_led_port_pin_cfg.hsiom = USER_LED_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);

    /*********************************************************************/
    /*****                   Interrupt setting                       *****/
    /*********************************************************************/
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(cpuss_interrupts_fault_2_IRQn, irqFaultReport2Handler);
    NVIC_SetPriority(FAULT_CPU_IRQ_INDEX, 0);
    NVIC_ClearPendingIRQ(FAULT_CPU_IRQ_INDEX);
    NVIC_EnableIRQ(FAULT_CPU_IRQ_INDEX);

    Cy_MCWDT_DeInit(MCWDT2);
    Cy_MCWDT_Init(MCWDT2, &mcwdtConfig);

    Cy_MCWDT_Unlock(MCWDT2);
    Cy_MCWDT_SetInterruptMask(MCWDT2, CY_MCWDT_CTR_Msk);
    Cy_MCWDT_Enable(MCWDT2, 
                    CY_MCWDT_CTR_Msk,  // enable all counter
                    0u);
    Cy_MCWDT_Lock(MCWDT2);

    for(;;)
    {
    }
}



/* [] END OF FILE */
