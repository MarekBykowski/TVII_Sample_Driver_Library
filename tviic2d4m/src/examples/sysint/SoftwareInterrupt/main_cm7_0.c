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

void SoftwareInterupt0Handler(void)
{
    __NOP();
}

void SoftwareInterupt7Handler(void)
{
    __NOP();
}

int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /* Software Interrupt 0 */
    {
        /* At first change software interrupt 0 handler */
        cy_stc_sysint_t cfg = 
        {
            .intrSrc = Internal0_IRQn,
            .intrPriority = 3ul,
        };
        Cy_SysInt_Init(&cfg, SoftwareInterupt0Handler);

        /* Enable software interrupt IRQ */
        NVIC_EnableIRQ(Internal0_IRQn);
        /* Force set pending status in the NVIC */
        Cy_SysInt_SoftwareTrig(Internal0_IRQn);
        /* Then goto SoftwareInterupt0Handler */
    }

    /* Software Interrupt 7 */
    {
        /* At first change software interrupt 7 handler */
        cy_stc_sysint_t cfg =
        {
            .intrSrc = Internal7_IRQn,
            .intrPriority = 3ul,
        };
        Cy_SysInt_Init(&cfg, SoftwareInterupt7Handler);

        /* Enable software interrupt IRQ */
        NVIC_EnableIRQ(Internal7_IRQn);
        /* Force set pending status in the NVIC */
        Cy_SysInt_SoftwareTrig(Internal7_IRQn);
        /* Then goto SoftwareInterupt7Handler */
    }

    for(;;)
    {
    }
}



/* [] END OF FILE */
