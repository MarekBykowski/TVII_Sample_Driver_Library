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

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "cy_project.h"
#include "cy_device_headers.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/
#define BUFFER_SIZE             36
#define DMAC_CHANNEL            0

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/
static  uint8_t                     au8DestBuffer[BUFFER_SIZE] = {0};
static  uint8_t                     au8SrcBuffer[BUFFER_SIZE];
static  cy_stc_mdma_descr_t         stcDescr;
const   cy_stc_mdma_chnl_config_t   chnlConfig      =   {
        /* CURR_PTR                          */    .MDMA_Descriptor =  &stcDescr,
                                                   .preemptable    =   0,
                                                   .priority       =   0,
                                                   .enable         =   1,  /* enabled after initialization */
                                                };
static  cy_stc_mdma_descr_config_t  stcDmaDescrConfig = {
        /* DESCR_CTL       WAIT_FOR_DEACT    */    .deact          =   0,
        /* DESCR_CTL       INTR_TYPE         */    .intrType       =   CY_PDMA_INTR_1ELEMENT_CMPLT,
        /* DESCR_CTL       TR_OUT_TYPE       */    .trigoutType    =   CY_PDMA_TRIGOUT_1ELEMENT_CMPLT,
        /* DESCR_CTL       CH_DISABLE        */    .chStateAtCmplt =   CY_MDMA_CH_DISABLED,
        /* DESCR_CTL       TR_IN_TYPE        */    .triginType     =   CY_PDMA_TRIGIN_DESCR,
        /* DESCR_CTL       DATA_SIZE         */    .dataSize       =   CY_MDMA_BYTE,
        /* DESCR_CTL       SRC_TRANSFER_SIZE */    .srcTxfrSize    =   0,
        /* DESCR_CTL       DST_TRANSFER_SIZE */    .destTxfrSize   =   0,
        /* DESCR_CTL       DESCR_TYPE        */    .descrType      =   CY_MDMA_1D_TRANSFER,
        /* DESCR_SRC                         */    .srcAddr        =   au8SrcBuffer,
        /* DESCR_DST                         */    .destAddr       =   au8DestBuffer,
        /* DESCR_X_INCR    SRC_X_INCR        */    .srcXincr       =   1,
        /* DESCR_X_INCR    DST_X_INCR        */    .destXincr      =   1,
        /* DESCR_X_SIZE    X_COUNT           */    .xCount         =   BUFFER_SIZE,
        /* DESCR_Y_INCR    SRC_Y_INCR        */    .srcYincr       =   0,
        /* DESCR_Y_INCR    DST_Y_INCR        */    .destYincr      =   0,
        /* DESCR_Y_SIZE    Y_COUNT           */    .yCount         =   0,
        /* DESCR_NEXT_PTR                    */    .descrNext      =   0
                                                };

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/
int main(void)
{
#if (CY_USE_PSVP == 0)
    SystemInit();
#endif

    uint32_t  i;
    uint8_t   *p_src;

    __enable_irq(); /* Enable global interrupts. */
    /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR); 

    /*******/
    /* DMA */
    /*******/

    /* Initialie & Enable DMA */
    Cy_MDMA_Disable(DMAC);
    Cy_MDMA_Descr_Init(&stcDescr,&stcDmaDescrConfig);
    Cy_MDMA_Chnl_Init( DMAC,
                       DMAC_CHANNEL,
                       (const cy_stc_mdma_chnl_config_t*) &chnlConfig);
    Cy_MDMA_Chnl_Enable( DMAC, DMAC_CHANNEL);
    Cy_MDMA_Enable(DMAC);

    /* for test */
    p_src = &au8SrcBuffer[0];
    for (i=BUFFER_SIZE; i>0; i--) {
        *p_src++ = i;
    }

    /***************/
    /* Trigger MUX */
    /***************/
    Cy_TrigMux_SwTrigger( TRIG_OUT_MUX_3_MDMA_TR_IN0,
                          TRIGGER_TYPE_CPUSS_DMAC_TR_IN__EDGE,
                          1u);

    for(;;)
    {
    }
}

/* [] END OF FILE */
