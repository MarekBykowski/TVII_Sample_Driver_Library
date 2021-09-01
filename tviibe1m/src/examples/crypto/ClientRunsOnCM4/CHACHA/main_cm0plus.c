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

/* Include default crypto configuration.
 * You can use other configuration instead follows.
 */
#include "crypto/cy_crypto_config.h"

/* For CRYPTO server that runs on the CM0+ */
cy_stc_crypto_server_context_t cryptoServerCtx;

/***********************************************************************************************************************
 * main function
 ***********************************************************************************************************************/
int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /* Start crypto server */
    {
        Cy_Crypto_Server_Start(&cryptoConfig, &cryptoServerCtx);

        /* Enable CRYPTO regarding IRQn */
        /* In this examle 2 of crypto regarding interrupt uses same number,
            so just one invoking NVIC setting is needed.
                CY_CRYPTO_NOTIFY_INTR_NR    == 
                CY_CRYPTO_ERROR_INTR_NR
        */
        NVIC_SetPriority(CY_CRYPTO_NOTIFY_CPU_INT_IDX, 0);
        NVIC_ClearPendingIRQ(CY_CRYPTO_NOTIFY_CPU_INT_IDX);
        NVIC_EnableIRQ(CY_CRYPTO_NOTIFY_CPU_INT_IDX);
    }

    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR); 

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    /* Now CRYPTO server runs */
    for(;;)
    {
    }
}



/* [] END OF FILE */
