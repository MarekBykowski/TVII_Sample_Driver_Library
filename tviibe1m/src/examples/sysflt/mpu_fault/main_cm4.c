
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

typedef union
{
    struct
    {
        uint32_t user_read : 1;
        uint32_t user_write : 1;
        uint32_t user_execute : 1;
        uint32_t privileged_read : 1;
        uint32_t privileged_write : 1;
        uint32_t privileged_execute : 1;
        uint32_t non_secure : 1;
        uint32_t : 1;
        uint32_t master : 4;
        uint32_t protection_context : 4;
        uint32_t : 15;
        uint32_t mpu_smpu : 1;
    } mpu_violation_info;
    uint32_t u32;
} un_mpuViolationInfo_t;

uint32_t violatingAddr = 0;
un_mpuViolationInfo_t violatingInfo = {0u};
    
void irqFaultReport0Handler(void)
{
    cy_en_sysflt_source_t status;

    status = Cy_SysFlt_GetErrorSource(FAULT_STRUCT0);

    if(status != CY_SYSFLT_NO_FAULT)
    {
        if(status == CY_SYSFLT_MPU_0) // Master 0 (CM0+) PPU fault
        {
            violatingAddr = Cy_SysFlt_GetData0(FAULT_STRUCT0);
            violatingInfo.u32 = Cy_SysFlt_GetData1(FAULT_STRUCT0);
            for(;;)
            {
                // Wait 0.05 [s]
                Cy_SysTick_DelayInUs(50000);
                Cy_GPIO_Inv(CY_LED8_PORT, CY_LED8_PIN);
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

    /*********************************************************************/
    /*****                     Port settings                         *****/
    /*********************************************************************/
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    user_led_port_pin_cfg.hsiom  = CY_LED8_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_LED8_PORT, CY_LED8_PIN, &user_led_port_pin_cfg);

    /*********************************************************************/
    /*****                 Fault report settings                     *****/
    /*********************************************************************/
    {
        Cy_SysFlt_ClearStatus(FAULT_STRUCT0); // clear status (typically this process is done by boot code)
        Cy_SysFlt_SetMaskByIdx(FAULT_STRUCT0, CY_SYSFLT_MPU_0); // enalbe Fault Master 0 (CM0+) MPU
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
        Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, irqFaultReport0Handler);
        NVIC_SetPriority(irq_cfg.intIdx, 0);
        NVIC_EnableIRQ(irq_cfg.intIdx);
    }

    for(;;)
    {
        // Wait 0.05 [s]
        Cy_SysTick_DelayInUs(50000);
    }
}



/* [] END OF FILE */
