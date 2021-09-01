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

#if (CY_USE_PSVP == 1)
    #define USER_LED1_PORT           CY_LED8_PORT
    #define USER_LED1_PIN            CY_LED8_PIN
    #define USER_LED1_PIN_MUX        CY_LED8_PIN_MUX
    
    #define USER_LED2_PORT           CY_LED9_PORT
    #define USER_LED2_PIN            CY_LED9_PIN
    #define USER_LED2_PIN_MUX        CY_LED9_PIN_MUX
#else
    #define USER_LED1_PORT           CY_USER_LED2_PORT
    #define USER_LED1_PIN            CY_USER_LED2_PIN
    #define USER_LED1_PIN_MUX        CY_USER_LED2_PIN_MUX 
    
    #define USER_LED2_PORT           CY_USER_LED3_PORT
    #define USER_LED2_PIN            CY_USER_LED3_PIN
    #define USER_LED2_PIN_MUX        CY_USER_LED3_PIN_MUX
#endif

// #define MCWDT_TICKS_PER_SECOND     32000    /* 1 sec when clk_lf = 32 KHz */
#define MCWDT_TICKS_PER_SECOND      6400    /* 1 sec when clk_lf = 6.4 KHz (CMR bitfile) */

#define MCWDT_CPU_IRQ_INDEX         CPUIntIdx2_IRQn

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =   
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,         
    .hsiom = USER_LED1_PIN_MUX,                      
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
    .sysIntSrc  = srss_interrupt_mcwdt_1_IRQn,
    .intIdx     = MCWDT_CPU_IRQ_INDEX,
    .isEnabled  = true,
};

cy_stc_mcwdt_config_t mcwdtConfig = 
{
    .coreSelect       = CY_MCWDT_PAUSED_BY_NO_CORE,
    .c0LowerLimit     = 0,
    .c0UpperLimit     = 0xFFFF,
    .c0WarnLimit      = MCWDT_TICKS_PER_SECOND,  /* 1 sec */
    .c0LowerAction    = CY_MCWDT_ACTION_NONE,
    .c0UpperAction    = CY_MCWDT_ACTION_NONE,
    .c0WarnAction     = CY_MCWDT_WARN_ACTION_INT,
    .c0AutoService    = CY_MCWDT_ENABLE,
    .c0SleepDeepPause = CY_MCWDT_ENABLE,
    .c0DebugRun       = CY_MCWDT_ENABLE,
    .c1LowerLimit     = 0,
    .c1UpperLimit     = 0xFFFF,
    .c1WarnLimit      = MCWDT_TICKS_PER_SECOND * 2, /* 2 sec */
    .c1LowerAction    = CY_MCWDT_ACTION_NONE,
    .c1UpperAction    = CY_MCWDT_ACTION_NONE,
    .c1WarnAction     = CY_MCWDT_WARN_ACTION_INT,
    .c1AutoService    = CY_MCWDT_ENABLE,
    .c1SleepDeepPause = CY_MCWDT_ENABLE,
    .c1DebugRun       = CY_MCWDT_ENABLE,
    .c2ToggleBit      = CY_MCWDT_CNT2_MONITORED_BIT15,
    .c2Action         = CY_MCWDT_CNT2_ACTION_INT,
    .c2SleepDeepPause = CY_MCWDT_ENABLE,
    .c2DebugRun       = CY_MCWDT_ENABLE,
};


uint8_t tFlag = 0;

void irqMCWDT1Handler(void)
{
    uint32_t masked;
    masked = Cy_MCWDT_GetInterruptStatusMasked(MCWDT1);

    if(MCWDT_INTR_MASKED_CTR0_INT_Msk & masked)
    {
        Cy_GPIO_Inv(USER_LED1_PORT, USER_LED1_PIN);
    }
    if(MCWDT_INTR_MASKED_CTR1_INT_Msk & masked)
    {
        Cy_GPIO_Inv(USER_LED2_PORT, USER_LED2_PIN);
    }
    if(MCWDT_INTR_MASKED_CTR2_INT_Msk & masked)
    {
        Cy_GPIO_Inv(USER_LED1_PORT, USER_LED1_PIN);
        Cy_GPIO_Inv(USER_LED2_PORT, USER_LED2_PIN);
    }

    Cy_MCWDT_ClearInterrupt(MCWDT1, masked);
    
    tFlag = 1;
}

int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    user_led_port_pin_cfg.hsiom = CY_LED8_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_LED1_PORT, USER_LED1_PIN, &user_led_port_pin_cfg);

    user_led_port_pin_cfg.hsiom = CY_LED9_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_LED2_PORT, USER_LED2_PIN, &user_led_port_pin_cfg);

    /*********************************************************************/
    /*****                   Interrupt setting                       *****/
    /*********************************************************************/
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(srss_interrupt_mcwdt_1_IRQn, irqMCWDT1Handler);
    NVIC_SetPriority(MCWDT_CPU_IRQ_INDEX, 0);
    NVIC_ClearPendingIRQ(MCWDT_CPU_IRQ_INDEX);
    NVIC_EnableIRQ(MCWDT_CPU_IRQ_INDEX);

    Cy_MCWDT_DeInit(MCWDT1);
    Cy_MCWDT_Init(MCWDT1, &mcwdtConfig);

    Cy_MCWDT_Unlock(MCWDT1);
    Cy_MCWDT_SetInterruptMask(MCWDT1, CY_MCWDT_CTR_Msk);
    Cy_MCWDT_Enable(MCWDT1, 
                    CY_MCWDT_CTR_Msk,  // enable all counter
                    0u);
    Cy_MCWDT_Lock(MCWDT1);
    
    /* Put the system to DeeSleep */
    Cy_SysPm_DeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);

    for(;;)
    {
        while( tFlag == 0 );
        tFlag = 0;
        Cy_SysPm_DeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
    }
}



/* [] END OF FILE */
