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

volatile uint32_t testRead0;
volatile uint32_t testRead1;

#define TP_PERMITTED_ADDR     (0x28019000UL) 
#define TP_PROHIBITED_ADDR    (0x28018000UL) 

int main(void)
{
    SystemInit();

    cy_stc_smpu_cfg_t smpuStructTemp = { 0 };


    __enable_irq(); /* Enable global interrupts. */
    /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR);

    /* 1. Setting for MSx_CTL */
    if(Cy_Prot_ConfigBusMaster(CPUSS_MS_ID_CM0, 1 /* privireged */, 0 /* secure */, 1 << (6-1) /* enable context 6 */ )
                               != CY_PROT_SUCCESS)
    {
        while(1); // Setting error
    }

    /* 2. Setting for MPU PC = "6" */
    /* This time MPU_PC can be set to only "6" because only SMPU_MS_CTL_PC_MASK[6] = "1"*/
    if(Cy_Prot_SetActivePC(CPUSS_MS_ID_CM0, 6) != CY_PROT_SUCCESS)
    {
        while(1); // Setting error
    }

    /* 3. Setting for SMPU_STRUCT (using STRUCT 2 and 3 for this time )*/
    /* 0x08010000 ~ 0x08017FFF: Only masters which have "5" as PC value can access this area */
    /* 0x08018000 ~ 0x0801FFFF: Only masters which have "6" as PC value can access this area */
    smpuStructTemp.regionSize = CY_PROT_SIZE_4KB; // 4KB: 0x1000 Byte
    smpuStructTemp.subregions = 0x00;
    smpuStructTemp.userPermission = CY_PROT_PERM_RWX;
    smpuStructTemp.privPermission = CY_PROT_PERM_RWX;
    smpuStructTemp.secure = 0; // Non secure
    smpuStructTemp.pcMatch = 0;

    smpuStructTemp.address = (uint32_t*)(TP_PROHIBITED_ADDR);
    smpuStructTemp.pcMask = 1 << (5 - 1); // enable context 5
    if(Cy_Prot_ConfigSmpuSlaveStruct(PROT_SMPU_SMPU_STRUCT2, &smpuStructTemp) != CY_PROT_SUCCESS)
    {
        while(1); // Setting error
    }

    smpuStructTemp.address = (uint32_t*)(TP_PERMITTED_ADDR);
    smpuStructTemp.pcMask = 1 << (6 - 1); // enable context 6
    if(Cy_Prot_ConfigSmpuSlaveStruct(PROT_SMPU_SMPU_STRUCT3, &smpuStructTemp) != CY_PROT_SUCCESS)
    {
        while(1); // Setting error
    }

    /* 4. Enable SMPU_STRUCT */
    if(Cy_Prot_EnableSmpuSlaveStruct(PROT_SMPU_SMPU_STRUCT2) != CY_PROT_SUCCESS)
    {
        while(1); // Setting error
    }
    if(Cy_Prot_EnableSmpuSlaveStruct(PROT_SMPU_SMPU_STRUCT3) != CY_PROT_SUCCESS)
    {
        while(1); // Setting error
    }

    /* 5. Memory access test1. This area can be accessed by masters which have "6" as PC value */
    /* CM0+ has "6" as PC value, then these accesses are expected to be allowed */
    testRead0 = 0;
    *(uint32_t*)(TP_PERMITTED_ADDR) = 0xA5A5A5A5;
    testRead0 = *(uint32_t*)(TP_PERMITTED_ADDR);

    /* 6. Memory access test2. This area can be accessed by masters which have "5" as PC value */
    /* CM0+ has "6" as PC value, then these accesses are expected to be restricted and cause HardFault */
    testRead1 = 0;
    *(uint32_t*)(TP_PROHIBITED_ADDR) = 0xA5A5A5A5;
    testRead1 = *(uint32_t*)(TP_PROHIBITED_ADDR);

    for(;;);
}

/* [] END OF FILE */
