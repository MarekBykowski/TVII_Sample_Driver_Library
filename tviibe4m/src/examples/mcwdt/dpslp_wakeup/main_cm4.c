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

cy_stc_mcwdt_config_t mcwdtConfig = 
{
    .coreSelect       = CY_MCWDT_PAUSED_BY_NO_CORE,
    .c0LowerLimit     = 0,
    .c0UpperLimit     = 0xFFFF,
    .c0WarnLimit      = 32000,  /* 1 sec when clk_lf = 32KHz */
    .c0LowerAction    = CY_MCWDT_ACTION_NONE,
    .c0UpperAction    = CY_MCWDT_ACTION_NONE,
    .c0WarnAction     = CY_MCWDT_WARN_ACTION_INT,
    .c0AutoService    = CY_MCWDT_ENABLE,
    .c0SleepDeepPause = CY_MCWDT_DISABLE,
    .c0DebugRun       = CY_MCWDT_ENABLE,
    .c1LowerLimit     = 0,
    .c1UpperLimit     = 0xFFFF,
    .c1WarnLimit      = 64000,  /* 2 sec when clk_lf = 32KHz */
    .c1LowerAction    = CY_MCWDT_ACTION_NONE,
    .c1UpperAction    = CY_MCWDT_ACTION_NONE,
    .c1WarnAction     = CY_MCWDT_WARN_ACTION_INT,
    .c1AutoService    = CY_MCWDT_ENABLE,
    .c1SleepDeepPause = CY_MCWDT_DISABLE,
    .c1DebugRun       = CY_MCWDT_ENABLE,
    .c2ToggleBit      = CY_MCWDT_CNT2_MONITORED_BIT15,
    .c2Action         = CY_MCWDT_CNT2_ACTION_INT,
    .c2SleepDeepPause = CY_MCWDT_DISABLE,
    .c2DebugRun       = CY_MCWDT_ENABLE,
};

cy_stc_sysint_irq_t irq_cfg =
{
    .sysIntSrc  = srss_interrupt_mcwdt_1_IRQn,
    .intIdx     = CPUIntIdx4_IRQn,
    .isEnabled  = true,
};

uint8_t tFlag = 0u;

void irqMCWDT1Handler(void)
{
    uint32_t masked;
    masked = Cy_MCWDT_GetInterruptStatusMasked(MCWDT1);

    if(MCWDT_INTR_MASKED_CTR0_INT_Msk & masked)
    {
        Cy_GPIO_Inv(CY_LED7_PORT, CY_LED7_PIN);
    }
    if(MCWDT_INTR_MASKED_CTR1_INT_Msk & masked)
    {
        Cy_GPIO_Inv(CY_LED8_PORT, CY_LED8_PIN);
    }
    if(MCWDT_INTR_MASKED_CTR2_INT_Msk & masked)
    {
        Cy_GPIO_Inv(CY_LED9_PORT, CY_LED9_PIN);
    }

    Cy_MCWDT_ClearInterrupt(MCWDT1, masked);
    
    tFlag = 1u;
}

int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    user_led_port_pin_cfg.hsiom = CY_LED7_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_LED7_PORT, CY_LED7_PIN, &user_led_port_pin_cfg);

    user_led_port_pin_cfg.hsiom = CY_LED8_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_LED8_PORT, CY_LED8_PIN, &user_led_port_pin_cfg);

    user_led_port_pin_cfg.hsiom = CY_LED9_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_LED9_PORT, CY_LED9_PIN, &user_led_port_pin_cfg);

    /*********************************************************************/
    /*****                   Interrupt setting                       *****/
    /*********************************************************************/
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, irqMCWDT1Handler);
    NVIC_SetPriority(CPUIntIdx4_IRQn, 0);
    NVIC_EnableIRQ(CPUIntIdx4_IRQn);

    Cy_MCWDT_DeInit(MCWDT1);
    Cy_MCWDT_Init(MCWDT1, &mcwdtConfig);
    Cy_MCWDT_Unlock(MCWDT1);
    Cy_MCWDT_SetInterruptMask(MCWDT1, CY_MCWDT_CTR_Msk);
    Cy_MCWDT_Enable(MCWDT1, 
                    CY_MCWDT_CTR_Msk,  // enable all counter
                    0);
    Cy_MCWDT_Lock(MCWDT1);
    
    /* Put the system to DeeSleep */
    Cy_SysPm_DeepSleep((cy_en_syspm_waitfor_t)CY_SYSPM_WAIT_FOR_INTERRUPT);

    for(;;)
    {
        while( tFlag == 0u );
        tFlag = 0u;
        Cy_SysPm_DeepSleep((cy_en_syspm_waitfor_t)CY_SYSPM_WAIT_FOR_INTERRUPT);
    }
}



/* [] END OF FILE */
