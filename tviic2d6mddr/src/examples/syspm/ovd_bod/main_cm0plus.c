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

    #define USER_LED3_PORT           CY_LED2_PORT
    #define USER_LED3_PIN            CY_LED2_PIN
    #define USER_LED3_PIN_MUX        CY_LED2_PIN_MUX
#else
    #define USER_LED1_PORT           CY_USER_LED1_PORT
    #define USER_LED1_PIN            CY_USER_LED1_PIN
    #define USER_LED1_PIN_MUX        CY_USER_LED1_PIN_MUX

    #define USER_LED2_PORT           CY_USER_LED2_PORT
    #define USER_LED2_PIN            CY_USER_LED2_PIN
    #define USER_LED2_PIN_MUX        CY_USER_LED2_PIN_MUX

    #define USER_LED3_PORT           CY_USER_LED3_PORT
    #define USER_LED3_PIN            CY_USER_LED3_PIN
    #define USER_LED3_PIN_MUX        CY_USER_LED3_PIN_MUX
#endif

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
                Cy_SysTick_DelayInUs(50000);
                Cy_GPIO_Inv(USER_LED1_PORT, USER_LED1_PIN);
            }
        }
    }

    while(1);
}

int main(void)
{
    bool status = false;
    
    SystemInit();

    cy_stc_sysflt_t tFlt_Temp = {0};
    
    __enable_irq(); /* Enable global interrupts. */
    
    /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    //Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR); 

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    user_led_port_pin_cfg.hsiom = USER_LED1_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_LED1_PORT, USER_LED1_PIN, &user_led_port_pin_cfg);
    user_led_port_pin_cfg.hsiom = USER_LED2_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_LED2_PORT, USER_LED2_PIN, &user_led_port_pin_cfg);
    user_led_port_pin_cfg.hsiom = USER_LED3_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_LED3_PORT, USER_LED3_PIN, &user_led_port_pin_cfg);
    
    /*********************************************************************/
    /*****                OVD settings                               *****/
    /*********************************************************************/

    // OVD Action Select
    Cy_Syspm_OvdActionSelect(CY_SYSPM_OVD_ACTION_FAULT);
    
    // Set the VDDD threshold select for OVD
    Cy_SysPm_OvdVdddSelect(CY_SYSPM_OVD_VDDD_5_0V);    
    // Enable OVD on VDDD
    Cy_SysPm_OvdEnable(CY_SYSPM_OVD_ON_VDDD);    
    
    // Set the VDDA threshold select for OVD
    Cy_SysPm_OvdVddaSelect(CY_SYSPM_OVD_VDDA_5_0V);    
    // Enable OVD on VDDA
    Cy_SysPm_OvdEnable(CY_SYSPM_OVD_ON_VDDA);   
    
    /*********************************************************************/
    /*****                BOD settings                               *****/
    /*********************************************************************/
    
    // BOD Action Select
    Cy_Syspm_BodActionSelect(CY_SYSPM_BOD_ACTION_FAULT);
    
    // Set the VDDD threshold select for BOD
    Cy_SysPm_BodVdddSelect(CY_SYSPM_BOD_VDDD_3_0V);    
    // Enable BOD on VDDD
    Cy_SysPm_BodEnable(CY_SYSPM_BOD_ON_VDDD);    
    
    // Set the VDDA threshold select for BOD
    Cy_SysPm_BodVddaSelect(CY_SYSPM_BOD_VDDA_3_0V);    
    // Enable BOD on VDDA
    Cy_SysPm_BodEnable(CY_SYSPM_BOD_ON_VDDA);
    
    /*********************************************************************/
    /*****                 Fault report settings                     *****/
    /*********************************************************************/
//    {
//        Cy_SysFlt_ClearStatus(FAULT_STRUCT0); // clear status (typically this process is done by boot code)
//        Cy_SysFlt_SetMaskByIdx(FAULT_STRUCT0, CY_SYSFLT_SRSS_SSV); // enable SRSS Supply SuperVisor (SSV) violation
//        Cy_SysFlt_SetInterruptMask(FAULT_STRUCT0);
//    }
//    
//    tFlt_Temp.ResetEnable = true;
//    tFlt_Temp.OutputEnable = false;
//    tFlt_Temp.TriggerEnable = false;
//    Cy_SysFlt_Init(FAULT_STRUCT0, &tFlt_Temp);
//
//    {
//        cy_stc_sysint_irq_t irq_cfg;
//        irq_cfg = (cy_stc_sysint_irq_t){
//            .sysIntSrc  = cpuss_interrupts_fault_0_IRQn,
//            .intIdx     = CPUIntIdx2_IRQn,
//            .isEnabled  = true,
//        };
//        irq_cfg.sysIntSrc = cpuss_interrupts_fault_0_IRQn;
//        Cy_SysInt_InitIRQ(&irq_cfg);
//        NVIC_SetPriority(CPUIntIdx2_IRQn, 0);
//        NVIC_ClearPendingIRQ(CPUIntIdx2_IRQn);
//        NVIC_EnableIRQ(CPUIntIdx2_IRQn);
//    }

    for(;;)
    {
        //Cy_SysTick_DelayInUs(50000);
        //Cy_GPIO_Inv(CY_LED0_PORT, CY_LED0_PIN);
        
        status = Cy_Syspm_SupplySupervisionStatus(CY_SYSPM_ENTITY_BOD_VDDD);
        if(status == false)
        {
            Cy_GPIO_Write(USER_LED1_PORT, USER_LED1_PIN, 0);
        }
        else
        {
            Cy_GPIO_Write(USER_LED1_PORT, USER_LED1_PIN, 1);
        }
        
        status = Cy_Syspm_SupplySupervisionStatus(CY_SYSPM_ENTITY_BOD_VDDA);
        if(status == false)
        {
            Cy_GPIO_Write(USER_LED2_PORT, USER_LED2_PIN, 0);
        }
        else
        {
            Cy_GPIO_Write(USER_LED2_PORT, USER_LED2_PIN, 1);
        }
        
        status = Cy_Syspm_SupplySupervisionStatus(CY_SYSPM_ENTITY_OVD_VDDD);
        if(status == false)
        {
            Cy_GPIO_Write(USER_LED3_PORT, USER_LED3_PIN, 0);
        }
        else
        {
            Cy_GPIO_Write(USER_LED3_PORT, USER_LED3_PIN, 1);
        }
        
        status = Cy_Syspm_SupplySupervisionStatus(CY_SYSPM_ENTITY_OVD_VDDA);
        if(status == false)
        {
            Cy_GPIO_Write(USER_LED2_PORT, USER_LED2_PIN, 0);
            Cy_GPIO_Write(USER_LED3_PORT, USER_LED3_PIN, 0);
        }
        else
        {
            Cy_GPIO_Write(USER_LED2_PORT, USER_LED2_PIN, 1);
            Cy_GPIO_Write(USER_LED3_PORT, USER_LED3_PIN, 1);
        }
    }
}

/* [] END OF FILE */
