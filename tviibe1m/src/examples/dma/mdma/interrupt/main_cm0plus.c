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


/* DMA Interrupt Test                                                                     */
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
#define DMAC_CHANNEL_0          0

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/
void DMA0_IntHandler(void);

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/
static  uint8_t                     au8DestBuffer0[BUFFER_SIZE] = {0};
static  uint8_t                     au8DestBuffer1[BUFFER_SIZE] = {0};
static  uint8_t                     au8SrcBuffer[BUFFER_SIZE];
static  uint8_t                     au8DestActSby = 0;
static  cy_stc_mdma_descr_t         stcDescr;
const   cy_stc_mdma_chnl_config_t   chnl0Config = {
        /* CURR_PTR                          */    .MDMA_Descriptor =  &stcDescr,
        /* CH_CTL          PRIO              */    .priority       =   0u,
        /* CH_CTL          ENABLED           */    .enable         =   1u,  /* enabled after initialization */
                                                };
static  cy_stc_mdma_descr_config_t  stcDma0DescrConfig = {
        /* DESCR_CTL       WAIT_FOR_DEACT    */    .deact          =   0u,
        /* DESCR_CTL       INTR_TYPE         */    .intrType       =   CY_MDMA_INTR_1ELEMENT_CMPLT,
        /* DESCR_CTL       TR_OUT_TYPE       */    .trigoutType    =   CY_MDMA_TRIGOUT_1ELEMENT_CMPLT,
        /* DESCR_CTL       CH_DISABLE        */    .chStateAtCmplt =   CY_MDMA_CH_DISABLED,             /* If descriptor changed, this needs to be CH_DISABLED */
        /* DESCR_CTL       TR_IN_TYPE        */    .triginType     =   CY_MDMA_TRIGIN_DESCR,
        /* DESCR_CTL       DATA_PREFETCH     */    .dataPrefetch   =   0u,
        /* DESCR_CTL       DATA_SIZE         */    .dataSize       =   CY_MDMA_BYTE,
        /* DESCR_CTL       SRC_TRANSFER_SIZE */    .srcTxfrSize    =   0u,
        /* DESCR_CTL       DST_TRANSFER_SIZE */    .destTxfrSize   =   0u,
        /* DESCR_CTL       DESCR_TYPE        */    .descrType      =   CY_MDMA_1D_TRANSFER,
        /* DESCR_SRC                         */    .srcAddr        =   &au8SrcBuffer[0],
        /* DESCR_DST                         */    .destAddr       =   &au8DestBuffer0[0],
        /* DESCR_X_INCR    SRC_X_INCR        */    .srcXincr       =   1u,
        /* DESCR_X_INCR    DST_X_INCR        */    .destXincr      =   1u,
        /* DESCR_X_SIZE    X_COUNT           */    .xCount         =   BUFFER_SIZE,
        /* DESCR_Y_INCR    SRC_Y_INCR        */    .srcYincr       =   0u,
        /* DESCR_Y_INCR    DST_Y_INCR        */    .destYincr      =   0u,
        /* DESCR_Y_SIZE    Y_COUNT           */    .yCount         =   0u,
        /* DESCR_NEXT_PTR                    */    .descrNext      =   &stcDescr
                                                };

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/
int main(void)
{
    SystemInit();

    uint32_t            i;
    uint8_t             *p_src;
    cy_stc_sysint_irq_t stc_sysint_irq_cfg;
    uint32_t            intMask = 0x01; // u1COMPLETION

    __enable_irq(); /* Enable global interrupts. */
    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR); 

    /*******/
    /* DMA */
    /*******/
    Cy_MDMA_Disable(DMAC);
    Cy_MDMA_Descr_Init(&stcDescr, &stcDma0DescrConfig);
    Cy_MDMA_Chnl_Init(DMAC,
                      DMAC_CHANNEL_0,
                      (const cy_stc_mdma_chnl_config_t*) &chnl0Config);
    Cy_MDMA_Chnl_SetInterruptMask(DMAC, DMAC_CHANNEL_0, intMask);
    Cy_MDMA_Enable(DMAC);

    /* for test */
    p_src = &au8SrcBuffer[0];
    for (i=BUFFER_SIZE; i>0; i--) {
        *p_src++ = i;
    }

    /**************/
    /* Interrrupt */
    /**************/
    /* Int1 -> DMA-ch.0 */
    stc_sysint_irq_cfg.sysIntSrc = cpuss_interrupts_dmac_0_IRQn;
    stc_sysint_irq_cfg.intIdx    = CPUIntIdx2_IRQn;
    stc_sysint_irq_cfg.isEnabled = true;
    Cy_SysInt_InitIRQ(&stc_sysint_irq_cfg);
    Cy_SysInt_SetSystemIrqVector(cpuss_interrupts_dmac_0_IRQn, DMA0_IntHandler);
    /* Enable Interrrupt */
    NVIC_EnableIRQ(CPUIntIdx2_IRQn);

    /***************/
    /* Trigger MUX */
    /***************/
    Cy_TrigMux_SwTrigger( TRIG_OUT_MUX_2_MDMA_TR_IN0,
                          TRIGGER_TYPE_CPUSS_DMAC_TR_IN__EDGE,
                          1u);

    for(;;)
    {
    }
}

void DMA0_IntHandler(void)
{
    uint32_t    masked;

    masked = Cy_MDMA_Chnl_GetInterruptStatusMasked(DMAC, DMAC_CHANNEL_0);
    if ((masked & CY_MDMA_INTRCAUSE_COMPLETION) != 0u)
    {
        /* Complete DMA */
        Cy_MDMA_Chnl_ClearInterrupt(DMAC, DMAC_CHANNEL_0);

        /* for test */

        /* Swtich destination address */
        if (au8DestActSby == 0u) { 
            Cy_MDMA_Descr_SetDestAddr(&stcDescr, (void *)au8DestBuffer1);
        }
        else {
            Cy_MDMA_Descr_SetDestAddr(&stcDescr, (void *)au8DestBuffer0);
        }
        au8DestActSby ^= 1u;

        // Needs to be checked
        Cy_SysTick_DelayInUs(50000);

        /* Set trigger again */

        /* note:                                                                           */
        /*   if descriptor changed, the channel needs to be changed from DISABLE to ENABLE */
        Cy_MDMA_Chnl_Enable(DMAC, DMAC_CHANNEL_0);
        Cy_TrigMux_SwTrigger( TRIG_OUT_MUX_2_MDMA_TR_IN0,
                              TRIGGER_TYPE_CPUSS_DMAC_TR_IN__EDGE,
                              1u);
    }
}

/* [] END OF FILE */
