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

/* User Configuration */
#define INJECT_BUG_TO_NONE     (0)
#define INJECT_BUG_TO_TASK_A   (1)
#define INJECT_BUG_TO_TASK_B_0 (2)
#define INJECT_BUG_TO_TASK_B_1 (3)

#define INJECT_BUG_MODE INJECT_BUG_TO_NONE
/* End of User Configuration */

#define RESERVED_MEMORY_BLOCK_SIZE (0x400) // 1K
#if   defined ( __ghs__ )
  #pragma alignvar (0x400) 
#elif defined ( __ICCARM__ )
  __attribute((aligned(0x400))) 
#else
  #warning "This example is supported only by GHS and IAR compiler"
#endif
#pragma pack(1)
struct
{
    uint8_t taskA_Region0[RESERVED_MEMORY_BLOCK_SIZE];
    uint8_t taskA_Region1[RESERVED_MEMORY_BLOCK_SIZE];
    uint8_t taskB_Region2[RESERVED_MEMORY_BLOCK_SIZE];
} gReservedRam;
#pragma pack()

#define PROTECTION_CONTEXT_OF_TASK_A (4)
#define PROTECTION_CONTEXT_OF_TASK_B (5)

#define PC_MASK_OF_TASK_A (1u<<(PROTECTION_CONTEXT_OF_TASK_A-1u))
#define PC_MASK_OF_TASK_B (1u<<(PROTECTION_CONTEXT_OF_TASK_B-1u))

cy_stc_smpu_cfg_t gSmpuStructConfigOfTaskA =
{
    .address        = NULL,              // Will be updated in run time
    .regionSize     = CY_PROT_SIZE_1KB,
    .subregions     = 0x00u,
    .userPermission = CY_PROT_PERM_RWX,
    .privPermission = CY_PROT_PERM_RWX,
    .secure         = false,             // Non secure
    .pcMatch        = false,
    .pcMask         = PC_MASK_OF_TASK_A, // only enable for task A
};

cy_stc_smpu_cfg_t gSmpuStructConfigOfTaskB =
{
    .address        = NULL,              // Will be updated in run time
    .regionSize     = CY_PROT_SIZE_1KB,
    .subregions     = 0x00u,
    .userPermission = CY_PROT_PERM_RWX,
    .privPermission = CY_PROT_PERM_RWX,
    .secure         = false,             // Non secure
    .pcMatch        = false,
    .pcMask         = PC_MASK_OF_TASK_B, // only enable for task B
};

void Routine_TaskA(void)
{
    for(uint32_t i = 0; i < RESERVED_MEMORY_BLOCK_SIZE; i++)
    {
        gReservedRam.taskA_Region0[i] += 1;
    }

    for(uint32_t i = 0; i < RESERVED_MEMORY_BLOCK_SIZE; i++)
    {
        gReservedRam.taskA_Region1[i] += 1;
    }


#if INJECT_BUG_MODE == INJECT_BUG_TO_TASK_A
    // Here is supposed that the programer took a mistake and access memory area of Task B. It will cause bus fault.
    gReservedRam.taskB_Region2[0] += 1;
#endif

}

void Routine_TaskB(void)
{
    for(uint32_t i = 0; i < RESERVED_MEMORY_BLOCK_SIZE; i++)
    {
        gReservedRam.taskB_Region2[i] += 1;
    }

#if INJECT_BUG_MODE == INJECT_BUG_TO_TASK_B_0
    // Here is supposed that the programer took a mistake and access memory area of Task A region 0. It will cause bus fault.
    gReservedRam.taskA_Region0[0] += 1;
#endif

#if INJECT_BUG_MODE == INJECT_BUG_TO_TASK_B_1
    // Here is supposed that the programer took a mistake and access memory area of Task A region 1. It will cause bus fault.
    gReservedRam.taskA_Region1[0] += 1;
#endif

}

int main(void)
{
    SystemInit();

    cy_en_prot_status_t status;

    /* Setting for MS14_CTL (for CM4) to allow the PC value to become 4 or 5 */
    status = Cy_Prot_ConfigBusMaster(CPUSS_MS_ID_CM4, true, false, (PC_MASK_OF_TASK_A|PC_MASK_OF_TASK_B));
    CY_ASSERT(status == CY_PROT_SUCCESS);

    /* Setting for SMPU_STRUCT 0 */
    /* Setting SMPU_STRUCT 0 for task A */
    gSmpuStructConfigOfTaskA.address = (uint32_t*)gReservedRam.taskA_Region0;
    status = Cy_Prot_ConfigSmpuSlaveStruct(PROT_SMPU_SMPU_STRUCT0, &gSmpuStructConfigOfTaskA);
    CY_ASSERT(status == CY_PROT_SUCCESS);

    /* Enable SMPU_STRUCT 0 */
    status = Cy_Prot_EnableSmpuSlaveStruct(PROT_SMPU_SMPU_STRUCT0);
    CY_ASSERT(status == CY_PROT_SUCCESS);

    /* Setting for SMPU_STRUCT 1 */
    /* Setting SMPU_STRUCT 1 for task A */
    gSmpuStructConfigOfTaskA.address = (uint32_t*)gReservedRam.taskA_Region1;
    status = Cy_Prot_ConfigSmpuSlaveStruct(PROT_SMPU_SMPU_STRUCT1, &gSmpuStructConfigOfTaskA);
    CY_ASSERT(status == CY_PROT_SUCCESS);

    /* Enable SMPU_STRUCT 1 */
    status = Cy_Prot_EnableSmpuSlaveStruct(PROT_SMPU_SMPU_STRUCT1);
    CY_ASSERT(status == CY_PROT_SUCCESS);

    /* Setting for SMPU_STRUCT 2 */
    /* Setting SMPU_STRUCT 2 for task B */
    gSmpuStructConfigOfTaskB.address = (uint32_t*)gReservedRam.taskB_Region2;
    status = Cy_Prot_ConfigSmpuSlaveStruct(PROT_SMPU_SMPU_STRUCT2, &gSmpuStructConfigOfTaskB);
    CY_ASSERT(status == CY_PROT_SUCCESS);

    /* Enable SMPU_STRUCT 2 */
    status = Cy_Prot_EnableSmpuSlaveStruct(PROT_SMPU_SMPU_STRUCT2);
    CY_ASSERT(status == CY_PROT_SUCCESS);

    for(;;)
    {
        /* Setting for MPU so that CM4 PC for task A   */
        status = Cy_Prot_SetActivePC(CPUSS_MS_ID_CM4, PROTECTION_CONTEXT_OF_TASK_A);
        CY_ASSERT(status == CY_PROT_SUCCESS);

        /* Do task A */
        Routine_TaskA();

        /* Setting for MPU so that CM4 PC for task B   */
        status = Cy_Prot_SetActivePC(CPUSS_MS_ID_CM4, PROTECTION_CONTEXT_OF_TASK_B);
        CY_ASSERT(status == CY_PROT_SUCCESS);

        /* Do task B */
        Routine_TaskB();
    }
}

/* [] END OF FILE */
