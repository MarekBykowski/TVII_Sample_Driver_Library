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

#define IPC_RELEASE_INT_NUMBER  6   /* Release interrupt number. This interrup is handled by notifier (CM4) */
#define IPC_NOTIFY_INT_NUMBER   7   /* Notify interrupt number. This interrup is handled by notifiee (CM0+) */
#define CY_IPC_CHAN_USRPIPE_CM4 7
/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

int main(void)
{
    SystemInit();

    uint32_t    u32Led= 0;
    __enable_irq(); /* Enable global interrupts. */

    /* At first force release the lock state. */
    (void)Cy_IPC_Drv_LockRelease(Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_USRPIPE_CM4), CY_IPC_NO_NOTIFICATION);

    /* Wait until the CM0+ IPC server is started */
    /* Note:
     * After the CM0+ IPC server is started, the corresponding number of the INTR_MASK is set.
     * So in this case CM4 can recognize whether the server has started or not by the INTR_MASK status.
     */
    while (((1uL << (CY_IPC_CHAN_USRPIPE_CM4)) !=  
        Cy_IPC_Drv_ExtractAcquireMask(Cy_IPC_Drv_GetInterruptMask(Cy_IPC_Drv_GetIntrBaseAddr(CY_IPC_CHAN_USRPIPE_CM4)))))
    {
    }

    for(;;)
    {
        // Wait 0.05 [s]
        Cy_SysTick_DelayInUs(50000);

        /* Send the message to the M0+ through IPC */
        Cy_IPC_Drv_SendMsgWord
        (
            Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_USRPIPE_CM4),
            (1u << IPC_NOTIFY_INT_NUMBER),
            u32Led
        );

        /* Wait until the CM0+ get the message and release the lock. */
        bool status = true;
        do
        {
            status = Cy_IPC_Drv_IsLockAcquired(Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_USRPIPE_CM4));
        } while(status);

        u32Led = (u32Led + 1u) % 3u;
    }
}

/* [] END OF FILE */
