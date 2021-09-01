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

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/
#define BUFFER_SIZE         100
#define DW_CHANNEL0         0
#define DW_CHANNEL1         1


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
static  uint8_t                     au8SrcBuffer  [BUFFER_SIZE];
static  uint8_t                     au8DestBuffer0[BUFFER_SIZE];
static  uint8_t                     au8DestBuffer1[BUFFER_SIZE];
static  cy_stc_pdma_descr_t         stcDescr0;
const   cy_stc_pdma_chnl_config_t   chnl0Config     =   {
                                                        .PDMA_Descriptor=   &stcDescr0,
                                                        .preemptable    =   0,
                                                        .priority       =   0,
                                                        .enable         =   1,  /*enabled after initialization*/
                                                        };
static  cy_stc_pdma_descr_config_t  stcDmaDescr0Config=  {
                                                        .deact          =   0,  /*Do not wait for trigger de-activation*/
                                                        .intrType       =   CY_PDMA_INTR_1ELEMENT_CMPLT,
                                                        .trigoutType    =   CY_PDMA_TRIGOUT_1ELEMENT_CMPLT,
                                                        .chStateAtCmplt =   CY_PDMA_CH_DISABLED, 
                                                        .triginType     =   CY_PDMA_TRIGIN_DESCR,
                                                        .dataSize       =   CY_PDMA_BYTE,
                                                        .srcTxfrSize    =   0,  /*= dataSize*/
                                                        .destTxfrSize   =   0,  /*= dataSize*/
                                                        .descrType      =   CY_PDMA_1D_TRANSFER,
                                                        .srcAddr        =   au8SrcBuffer,
                                                        .destAddr       =   au8DestBuffer0,
                                                        .srcXincr       =   1,
                                                        .destXincr      =   1,
                                                        .xCount         =   BUFFER_SIZE,
                                                        .srcYincr       =   0,
                                                        .destYincr      =   0,
                                                        .yCount         =   0,
                                                        };
static  cy_stc_pdma_descr_t         stcDescr1;
const   cy_stc_pdma_chnl_config_t   chnl1Config     =   {
                                                        .PDMA_Descriptor=   &stcDescr1,
                                                        .preemptable    =   0,
                                                        .priority       =   0,
                                                        .enable         =   1,  /*enabled after initialization*/
                                                        };
static  cy_stc_pdma_descr_config_t  stcDmaDescr1Config=  {
                                                        .deact          =   0,  /*Do not wait for trigger de-activation*/
                                                        .intrType       =   CY_PDMA_INTR_1ELEMENT_CMPLT,
                                                        .trigoutType    =   CY_PDMA_TRIGOUT_1ELEMENT_CMPLT,
                                                        .chStateAtCmplt =   CY_PDMA_CH_DISABLED, 
                                                        .triginType     =   CY_PDMA_TRIGIN_DESCR,
                                                        .dataSize       =   CY_PDMA_BYTE,
                                                        .srcTxfrSize    =   0,  /*= dataSize*/
                                                        .destTxfrSize   =   0,  /*= dataSize*/
                                                        .descrType      =   CY_PDMA_1D_TRANSFER,
                                                        .srcAddr        =   au8DestBuffer0,
                                                        .destAddr       =   au8DestBuffer1,
                                                        .srcXincr       =   1,
                                                        .destXincr      =   1,
                                                        .xCount         =   BUFFER_SIZE,
                                                        .srcYincr       =   0,
                                                        .destYincr      =   0,
                                                        .yCount         =   0,
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

    uint32_t    u32Idx;
    
    __enable_irq(); /* Enable global interrupts. */


    for(u32Idx = 0; u32Idx < BUFFER_SIZE; u32Idx++)
    {
        au8DestBuffer1[u32Idx]  =   0;
        au8DestBuffer0[u32Idx]  =   0;
        au8SrcBuffer[u32Idx]    =   u32Idx;
    }
    
    Cy_PDMA_Disable(DW0);
    
    //Channel 0
    Cy_PDMA_Descr_Init(&stcDescr0,&stcDmaDescr0Config);
    Cy_PDMA_Chnl_Init(  DW0,
                        DW_CHANNEL0,
                        (const cy_stc_pdma_chnl_config_t*) &chnl0Config);
    //Channel 1
    Cy_PDMA_Descr_Init(&stcDescr1,&stcDmaDescr1Config);
    Cy_PDMA_Chnl_Init(  DW0,
                        DW_CHANNEL1,
                        (const cy_stc_pdma_chnl_config_t*) &chnl1Config);
    
    Cy_PDMA_Enable(DW0);
    
    /*Connect completion of Channel 0 with trigger of Channel 1*/
    Cy_TrigMux_Connect(TRIG_IN_MUX_0_PDMA0_TR_OUT0,
                       TRIG_OUT_MUX_0_PDMA0_TR_IN1,
                       0 /*invert*/,
                       TRIGGER_TYPE_EDGE,
                       0 /*dbg_frz_en*/);
                       
    /*Trigger DMA by SW*/
    Cy_TrigMux_SwTrigger(TRIG_OUT_MUX_0_PDMA0_TR_IN0,
                         TRIGGER_TYPE_EDGE, 
                         1 /*output*/);
    
    
    // Check with debugger if data has been transferred (au8SrcBuffer -> au8DestBuffer0 -> au8DestBuffer1)
    for(;;)
    {

    }
}



/* [] END OF FILE */
