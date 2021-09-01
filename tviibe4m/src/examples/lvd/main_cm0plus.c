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
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,         
    .hsiom = CY_LED0_PIN_MUX,                      
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

uint32_t violatingSsvData = 0;

volatile uint32_t testRead0;
volatile uint32_t testRead1;

void irqFaultReport0Handler(void)
{
    cy_en_sysflt_source_t status;

    status = Cy_SysFlt_GetErrorSource(FAULT_STRUCT0);

    if(status != CY_SYSFLT_NO_FAULT)
    {
        if(status == CY_SYSFLT_SRSS_SSV) // SRSS Supply SuperVisor (SSV) violation
        {
            violatingSsvData = Cy_SysFlt_GetData0(FAULT_STRUCT0);
            
            for(;;)
            {
                // Wait 0.05 [s]
                Cy_SysTick_DelayInUs(50000);
                Cy_GPIO_Inv(CY_LED0_PORT, CY_LED0_PIN);
            }
        }
    }

    while(1);
}

int main(void)
{
    SystemInit();

    cy_stc_sysflt_t tFlt_Temp = {0};
    
    __enable_irq(); /* Enable global interrupts. */
    /* Enable CM4. CY_CORTEX_M4_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR); 

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(CY_LED0_PORT, CY_LED0_PIN, &user_led_port_pin_cfg);
    
    /*********************************************************************/
    /*****                LVD settings                               *****/
    /*********************************************************************/

    // Set the LVD threshold
    Cy_LVD_SetThreshold(CY_LVD_TYPE_1, CY_LVD_THRESHOLD_4_8_V);    
    // Action Select
    Cy_LVD_SetActionSelect(CY_LVD_TYPE_1, CY_LVD_ACTION_FAULT);
    // Edge Select
    Cy_LVD_SetEdgeSelect(CY_LVD_TYPE_1, CY_LVD_EDGE_BOTH);
    // Enable LVD1
    Cy_LVD_Enable(CY_LVD_TYPE_1);
    
    
    /*********************************************************************/
    /*****                 Fault report settings                     *****/
    /*********************************************************************/
    {
        Cy_SysFlt_ClearStatus(FAULT_STRUCT0); // clear status (typically this process is done by boot code)
        Cy_SysFlt_SetMaskByIdx(FAULT_STRUCT0, CY_SYSFLT_SRSS_SSV); // enable SRSS Supply SuperVisor (SSV) violation
        Cy_SysFlt_SetInterruptMask(FAULT_STRUCT0);
    }
    
    tFlt_Temp.ResetEnable = false;
    tFlt_Temp.OutputEnable = true;
    tFlt_Temp.TriggerEnable = false;
    Cy_SysFlt_Init(FAULT_STRUCT0, &tFlt_Temp);

    {
        cy_stc_sysint_irq_t irq_cfg;
        irq_cfg = (cy_stc_sysint_irq_t){
            .sysIntSrc  = cpuss_interrupts_fault_0_IRQn,
            .intIdx     = CPUIntIdx2_IRQn,
            .isEnabled  = true,
        };
        irq_cfg.sysIntSrc = cpuss_interrupts_fault_0_IRQn;
        Cy_SysInt_InitIRQ(&irq_cfg);
		Cy_SysInt_SetSystemIrqVector(cpuss_interrupts_fault_0_IRQn, irqFaultReport0Handler);
        NVIC_SetPriority(CPUIntIdx2_IRQn, 0);
        NVIC_ClearPendingIRQ(CPUIntIdx2_IRQn);
        NVIC_EnableIRQ(CPUIntIdx2_IRQn);
    }

    for(;;)
    {
        Cy_SysTick_DelayInUs(50000);
        Cy_GPIO_Inv(CY_LED0_PORT, CY_LED0_PIN);
    }
}



/* [] END OF FILE */
