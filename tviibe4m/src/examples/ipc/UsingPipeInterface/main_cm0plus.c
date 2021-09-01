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
#include "example_config.h"


typedef struct
{
    uint32_t clientId;  /* PIPE I/F internal use area. Must be first element of the structure. */
    uint32_t LedData;
} custom_data_t;

custom_data_t pipeData = 
{
    .clientId = 0x01u,
    .LedData  = 0x00u
};

bool released;

cy_en_ipc_pipe_status_t status;

cy_stc_ipc_pipe_config_t pipeConfig = 
{
    .epIndexForThisCpu = EP_INDEX_THIS_CPU,
    .epConfigData      = CY_IPC_PIPE_ENDPOINTS_DEFAULT_CONFIG,
};

/* Call when the other end point release the handle corresponding this end point */
void ReleaseCallback(void)
{
    /* Notified core already got the data. */
    /* Update send data for next transmission. */
    released = true;
}

int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    /* Initialize PIPE */
    Cy_IPC_Pipe_Init(&pipeConfig);

    /* Already registered the handler to the system interrup structure.
     * So just enable corresponding IRQ channel.
     */
    NVIC_ClearPendingIRQ(pipeConfig.epConfigData[EP_INDEX_THIS_CPU].ipcCpuIntIdx);
    NVIC_EnableIRQ(pipeConfig.epConfigData[EP_INDEX_THIS_CPU].ipcCpuIntIdx);

    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR);

    for(;;)
    {
        /* Send data */
        released = false;
        status = Cy_IPC_Pipe_SendMessage
        (
            EP_INDEX_OTHER_CPU,
            &pipeData,
            ReleaseCallback
        );
        
        /* When the data successfully into the pipe */
        if (status == CY_IPC_PIPE_SUCCESS)
        {
            while(!released)
            {
                /* wait until the data has been received by the other core */
            }
            /* Update the data to be sent */
            pipeData.LedData = (pipeData.LedData + 1) % 5;
            
            // Wait 0.05 [s]
            Cy_SysTick_DelayInUs(50000);
        }
    }
}



/* [] END OF FILE */
