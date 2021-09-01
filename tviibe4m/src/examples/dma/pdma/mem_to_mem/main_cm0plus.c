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
#define BUFFER_SIZE         100
#define DW_CHANNEL          0

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
static  uint8_t                     au8SrcBuffer [BUFFER_SIZE];
static  uint8_t                     au8DestBuffer[BUFFER_SIZE];
static  cy_stc_pdma_descr_t         stcDescr;
const   cy_stc_pdma_chnl_config_t   chnlConfig      =   {
                                                        .PDMA_Descriptor=   &stcDescr,
                                                        .preemptable    =   0,
                                                        .priority       =   0,
                                                        .enable         =   1,  /*enabled after initialization*/
                                                        };
static  cy_stc_pdma_descr_config_t  stcDmaDescrConfig=  {
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
                                                        .destAddr       =   au8DestBuffer,
                                                        .srcXincr       =   1,
                                                        .destXincr      =   1,
                                                        .xCount         =   BUFFER_SIZE,
                                                        .srcYincr       =   0,
                                                        .destYincr      =   0,
                                                        .yCount         =   0,
                                                        };
cy_stc_gpio_pin_config_t user_led0_port_pin_cfg    =    {
                                                        .outVal = 0x00,
                                                        .driveMode = CY_GPIO_DM_PULLUP_DOWN_IN_OFF,
                                                        .hsiom = CY_LED0_PIN_MUX,
                                                        .intEdge = 0,
                                                        .intMask = 0,
                                                        .vtrip = 0,
                                                        .slewRate = 0,
                                                        .driveSel = 0,
                                                        .vregEn = 0,
                                                        .ibufMode = 0,
                                                        .vtripSel = 0,
                                                        .vrefSel = 0,
                                                        .vohSel = 0
                                                        };

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/



int main(void)
{
    SystemInit();

    uint32_t    u32Idx;
    
    __enable_irq(); /* Enable global interrupts. */
    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR); 

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(CY_LED0_PORT, CY_LED0_PIN, &user_led0_port_pin_cfg);


    for(u32Idx = 0; u32Idx < BUFFER_SIZE; u32Idx++)
    {
        au8DestBuffer[u32Idx]   =   0;
        au8SrcBuffer[u32Idx]    =   u32Idx;
    }
    
    Cy_PDMA_Disable(DW0);
    Cy_PDMA_Descr_Init(&stcDescr,&stcDmaDescrConfig);
    Cy_PDMA_Chnl_Init(  DW0,
                        DW_CHANNEL,
                        (const cy_stc_pdma_chnl_config_t*) &chnlConfig);
    Cy_PDMA_Enable(DW0);
    
    /*Trigger DMA by SW*/ 
    Cy_TrigMux_SwTrigger(TRIG_OUT_MUX_0_PDMA0_TR_IN0,
                         TRIGGER_TYPE_CPUSS_DW0_TR_IN__EDGE,
                         1);
    
    for(;;)
    {
        // Wait 0.05 [s]
        Cy_SysTick_DelayInUs(50000);
        Cy_GPIO_Inv(CY_LED0_PORT, CY_LED0_PIN);
    }
}



/* [] END OF FILE */
