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

/* DW Interrupt Test                                                                      */
/* Destination buffer address is changed alternatly via receiving the complete interrupt. */
/* And, Mem to Mem transfer is executed.                                                  */
/* Please check variables (au8DestBuffer0[] and au8DestBuffer1[]) on debugger             */

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "cy_project.h"
#include "cy_device_headers.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/
#define BUFFER_SIZE             100
#define DW1_CHANNEL_7           7

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/
void DW1_IntHandler(void);

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/
static  uint8_t                     au8DestBuffer0[BUFFER_SIZE] = {0};
static  uint8_t                     au8DestBuffer1[BUFFER_SIZE] = {0};
static  uint8_t                     au8SrcBuffer[BUFFER_SIZE];
static  uint8_t                     au8DestActSby = 0;
static  cy_stc_pdma_descr_t         stcDescr;
const   cy_stc_pdma_chnl_config_t   chnl7Config = {
        /* CURR_PTR                          */    .PDMA_Descriptor =  &stcDescr,
        /* CH_CTL          PREEMPTABLE       */    .preemptable    =   0u,
        /* CH_CTL          PRIO              */    .priority       =   0u,
        /* CH_CTL          ENABLED           */    .enable         =   1u,  /* enabled after initialization */
                                                };
static  cy_stc_pdma_descr_config_t  stcDw1DescrConfig = {
        /* DESCR_CTL       WAIT_FOR_DEACT    */    .deact          =   0u,
        /* DESCR_CTL       INTR_TYPE         */    .intrType       =   CY_PDMA_INTR_1ELEMENT_CMPLT,
        /* DESCR_CTL       TR_OUT_TYPE       */    .trigoutType    =   CY_PDMA_TRIGOUT_1ELEMENT_CMPLT,
        /* DESCR_CTL       CH_DISABLE        */    .chStateAtCmplt =   CY_PDMA_CH_DISABLED,             /* If descriptor changed, this needs to be CH_DISABLED */
        /* DESCR_CTL       TR_IN_TYPE        */    .triginType     =   CY_PDMA_TRIGIN_DESCR,
        /* DESCR_CTL       DATA_SIZE         */    .dataSize       =   CY_PDMA_BYTE,
        /* DESCR_CTL       SRC_TRANSFER_SIZE */    .srcTxfrSize    =   0u,
        /* DESCR_CTL       DST_TRANSFER_SIZE */    .destTxfrSize   =   0u,
        /* DESCR_CTL       DESCR_TYPE        */    .descrType      =   CY_PDMA_1D_TRANSFER,
        /* DESCR_SRC                         */    .srcAddr        =   &au8SrcBuffer[0],
        /* DESCR_DST                         */    .destAddr       =   &au8DestBuffer0[0],
        /* DESCR_X_CTL     SRC_X_INCR        */    .srcXincr       =   1u,
        /* DESCR_X_CTL     DST_X_INCR        */    .destXincr      =   1u,
        /* DESCR_X_CTL     X_COUNT           */    .xCount         =   BUFFER_SIZE,
        /* DESCR_Y_CTL     SRC_Y_INCR        */    .srcYincr       =   0u,
        /* DESCR_Y_CTL     DST_Y_INCR        */    .destYincr      =   0u,
        /* DESCR_Y_CTL     Y_COUNT           */    .yCount         =   0u,
        /* DESCR_NEXT_PTR                    */    .descrNext      =   &stcDescr
                                                };

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/
int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    uint32_t            i;
    uint8_t             *p_src;
    cy_stc_sysint_irq_t stc_sysint_irq_cfg;

    __enable_irq(); /* Enable global interrupts. */

    /******/
    /* DW */
    /******/
    Cy_PDMA_Disable(DW1);
    Cy_PDMA_Descr_Init(&stcDescr, &stcDw1DescrConfig);
    Cy_PDMA_Chnl_Init(DW1,
                      DW1_CHANNEL_7,
                      (const cy_stc_pdma_chnl_config_t*) &chnl7Config);
    Cy_PDMA_Chnl_SetInterruptMask(DW1, DW1_CHANNEL_7);
    Cy_PDMA_Enable(DW1);

    /* for test */
    p_src = &au8SrcBuffer[0];
    for (i=BUFFER_SIZE; i>0; i--) {
        *p_src++ = i;
    }

    /**************/
    /* Interrrupt */
    /**************/
    /* Int1 -> DW1-ch.7 */
    stc_sysint_irq_cfg.sysIntSrc = cpuss_interrupts_dw1_7_IRQn;
    stc_sysint_irq_cfg.intIdx    = CPUIntIdx1_IRQn;
    stc_sysint_irq_cfg.isEnabled = true;
    
    Cy_SysInt_InitIRQ(&stc_sysint_irq_cfg);
    Cy_SysInt_SetSystemIrqVector(stc_sysint_irq_cfg.sysIntSrc, DW1_IntHandler);

    /* Enable Interrrupt */
    NVIC_EnableIRQ(CPUIntIdx1_IRQn);

    /***************/
    /* Trigger MUX */
    /***************/
    Cy_TrigMux_SwTrigger( TRIG_OUT_MUX_2_PDMA1_TR_IN7,
                          TRIGGER_TYPE_CPUSS_DW1_TR_IN__EDGE,
                          1u);

    for(;;)
    {
    }
}

void DW1_IntHandler(void)
{
    uint32_t    masked;

    masked = Cy_PDMA_Chnl_GetInterruptStatusMasked(DW1, DW1_CHANNEL_7);
    if ((masked & CY_PDMA_INTRCAUSE_COMPLETION) != 0u)
    {
        /* Complete DMA */
        Cy_PDMA_Chnl_ClearInterrupt(DW1, DW1_CHANNEL_7);

        /* for test */

        /* Swtich destination address */
        if (au8DestActSby == 0u) { 
            Cy_PDMA_Descr_SetDestAddr(&stcDescr, (void *)au8DestBuffer1);
        }
        else {
            Cy_PDMA_Descr_SetDestAddr(&stcDescr, (void *)au8DestBuffer0);
        }
        au8DestActSby ^= 1u;

        Cy_SysTick_DelayInUs(3000000UL);

        /* Set trigger again */

        /* note:                                                                           */
        /*   if descriptor changed, the channel needs to be changed from DISABLE to ENABLE */
        Cy_PDMA_Chnl_Enable(DW1, DW1_CHANNEL_7);
        Cy_TrigMux_SwTrigger( TRIG_OUT_MUX_2_PDMA1_TR_IN7,
                              TRIGGER_TYPE_CPUSS_DW1_TR_IN__EDGE,
                              1u);
    }
}

/* [] END OF FILE */
