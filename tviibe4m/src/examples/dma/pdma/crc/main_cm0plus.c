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
#define BUFFER_SIZE         5
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
static  volatile stc_DW_t*          pstcDW          =   DW0;
static  cy_stc_pdma_descr_t         stcDescr;
const   uint8_t                     au8SrcBuffer[]   =   {0x12,0x34,0x56,0x78,0x9a};

const   cy_stc_pdma_crc_config_t    stcCrcConfig    =   {
                                                        .data_reverse = 1,                  
                                                        .rem_reverse  = 1,              
                                                        .data_xor     = 0,                      
                                                        .polynomial   = 0x04c11db7,             
                                                        .lfsr32       = 0xFFFFFFFF,                     
                                                        .rem_xor      = 0xFFFFFFFF,                       
                                                        };
const   cy_stc_pdma_chnl_config_t   chnlConfig      =   {
                                                        .PDMA_Descriptor=   &stcDescr,
                                                        .preemptable    =   0,
                                                        .priority       =   0,
                                                        .enable         =   1,  /*enabled after initialization*/
                                                        };
static  uint32_t                    u32Time         =   0;
static  cy_stc_pdma_descr_config_t  stcDmaDescrConfig=  {
                                                        .deact          =   0,  /*Do not wait for trigger de-activation*/
                                                        .intrType       =   CY_PDMA_INTR_1ELEMENT_CMPLT,
                                                        .trigoutType    =   CY_PDMA_TRIGOUT_1ELEMENT_CMPLT,
                                                        .chStateAtCmplt =   CY_PDMA_CH_DISABLED, 
                                                        .triginType     =   CY_PDMA_TRIGIN_DESCR,
                                                        .dataSize       =   CY_PDMA_BYTE,
                                                        .srcTxfrSize    =   0,  /*= dataSize*/
                                                        .destTxfrSize   =   0,  /*= dataSize*/
                                                        .descrType      =   CY_PDMA_CRC_TRANSFER,
                                                        .srcAddr        =   (void*) au8SrcBuffer,
                                                        .destAddr       =   0,          //below initialized
                                                        .srcXincr       =   1,
                                                        .destXincr      =   1,
                                                        .xCount         =   BUFFER_SIZE,
                                                        .srcYincr       =   0,
                                                        .destYincr      =   0,
                                                        .yCount         =   0,
                                                        };
cy_stc_gpio_pin_config_t user_led0_port_pin_cfg    =    {
                                                        .outVal = 0x00,
                                                        .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
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
static  uint32_t                    u32CrcResult   =    0;

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/


#define EXPECTED_RESULT_VALUE (0x3C4687AFUL)
int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */
    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR); 

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(CY_LED0_PORT, CY_LED0_PIN, &user_led0_port_pin_cfg);

    Cy_PDMA_Disable(pstcDW);
      
    Cy_PDMA_CRC_Config( pstcDW,
                        &stcCrcConfig);
    
    stcDmaDescrConfig.destAddr = (void *)&pstcDW->unCRC_LFSR_CTL.u32Register;      
    Cy_PDMA_Descr_Init(&stcDescr,&stcDmaDescrConfig);
    Cy_PDMA_Chnl_Init(  pstcDW,
                        DW_CHANNEL,
                        (const cy_stc_pdma_chnl_config_t*) &chnlConfig);
    
    
    Cy_PDMA_Enable(pstcDW);
    
    /*Trigger DMA by SW*/
    Cy_TrigMux_SwTrigger(TRIG_OUT_MUX_0_PDMA0_TR_IN0,
                         TRIGGER_TYPE_CPUSS_DW0_TR_IN__EDGE,
                         1);                            /*output*/
    
    //Wait for completion
    while(pstcDW->CH_STRUCT[DW_CHANNEL].unCH_CTL.stcField.u1ENABLED)
    {
        u32Time++;
    }
    
    u32CrcResult                            =   Cy_PDMA_GetCrcRemainderResult(pstcDW);
      
    CY_ASSERT(u32CrcResult == EXPECTED_RESULT_VALUE);

    for(;;)
    {
        // Wait 0.05 [s]
        Cy_SysTick_DelayInUs(50000);
        Cy_GPIO_Inv(CY_LED0_PORT, CY_LED0_PIN);
    }
}



/* [] END OF FILE */
