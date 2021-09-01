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

#if (CY_USE_PSVP == 1)
    #define USER_LED_PORT           CY_AB_LED_PORT
    #define USER_LED_PIN            CY_AB_LED_PIN
    #define USER_LED_PIN_MUX        CY_AB_LED_PIN_MUX
    // The core frequency is 24MHz. 1200000 / 24MHz = 0.05[s]
    #define USER_LED_TOGGLE_DELAY   1200000 
#else
    #define USER_LED_PORT           CY_USER_LED1_PORT
    #define USER_LED_PIN            CY_USER_LED1_PIN
    #define USER_LED_PIN_MUX        CY_USER_LED1_PIN_MUX 
    // The core frequency is 80MHz. 4000000 / 80MHz = 0.05[s]
    #define USER_LED_TOGGLE_DELAY   4000000
#endif


cy_stc_gpio_pin_config_t user_led_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED_PIN_MUX,                           
    .intEdge = 0,                                  
    .intMask = 0,                                  
    .vtrip = 0,                                    
    .slewRate = 0,                                 
    .driveSel = 0,                                 
    .vregEn = 0,                                   
    .ibufMode = 0,                                 
    .vtripSel = 0,                                 
    .vrefSel = 0,                                  
    .vohSel = 0,                                   
};

#define BUFFER_SIZE                256
#define DMAC_CHANNEL_SINGLE        0
#define DMAC_CHANNEL_CHAIN         1
#define NR_OF_CHAINED_DESCRIPTORS  4

static uint8_t srcBuffer[BUFFER_SIZE];
static uint8_t dstBuffer[BUFFER_SIZE];

static  cy_stc_axidma_1d_memcopy_descr_t  descriptor;

CY_AXIDMA_SAFELY_INSTANTIATE_1D_MEMCOPY_DESCRIPTORS(static, pDescChain1D, NR_OF_CHAINED_DESCRIPTORS)

const   cy_stc_axidma_chnl_config_t chnlConfig = {
                                                     .AXIDMA_Descriptor = &descriptor,
                                                     .priority          = 0,
                                                     .enable            = 1,
                                                 };

const   cy_stc_axidma_chnl_config_t chnlConfigChain = {
                                                     .AXIDMA_Descriptor = CY_AXIDMA_GET_BUILD_TIME_BASE_ADDRESS_OF_DESCRIPTOR(pDescChain1D, 0),
                                                     .priority          = 0,
                                                     .enable            = 1,
                                                 };


static  cy_stc_axidma_descr_config_t  descriptorConfig = {
                                                   .deact            = CY_AXIDMA_TRIG_DEACT_NO_WAIT,
                                                   .intrType         = CY_AXIDMA_INTR_DESCRCHAIN_CMPLT,    // used for polling
                                                   .trigoutType      = CY_AXIDMA_TRIGOUT_DESCRCHAIN_CMPLT, // unused
                                                   .triginType       = CY_AXIDMA_TRIGIN_DESCRCHAIN,
                                                   .disableChAtCmplt = false,
                                                   .dataPrefetch     = true,
                                                   .descrType        = CY_AXIDMA_1D_MEMCOPY_TRANSFER,
                                                   .srcAddr          = srcBuffer,
                                                   .dstAddr          = dstBuffer,
                                                   .mCount           = BUFFER_SIZE,
                                                   .srcXincr         = 0,                                  // unused
                                                   .dstXincr         = 0,                                  // unused
                                                   .xCount           = 0,                                  // unused
                                                   .srcYincr         = 0,                                  // unused
                                                   .dstYincr         = 0,                                  // unused
                                                   .yCount           = 0,                                  // unused
                                                   .descrNext        = NULL,
                                                };


static  cy_stc_axidma_descr_config_t  descriptorChainConfig = {
                                                   .deact            = CY_AXIDMA_TRIG_DEACT_NO_WAIT,
                                                   .intrType         = CY_AXIDMA_INTR_DESCRCHAIN_CMPLT,         // used for polling
                                                   .trigoutType      = CY_AXIDMA_TRIGOUT_DESCRCHAIN_CMPLT,      // unused
                                                   .triginType       = CY_AXIDMA_TRIGIN_DESCRCHAIN,
                                                   .disableChAtCmplt = false,
                                                   .dataPrefetch     = true,
                                                   .descrType        = CY_AXIDMA_1D_MEMCOPY_TRANSFER,
                                                   .srcAddr          = srcBuffer,                               // updated later in descriptors
                                                   .dstAddr          = dstBuffer,                               // updated later in descriptors
                                                   .mCount           = BUFFER_SIZE / NR_OF_CHAINED_DESCRIPTORS,
                                                   .srcXincr         = 0,                                       // unused
                                                   .dstXincr         = 0,                                       // unused
                                                   .xCount           = 0,                                       // unused
                                                   .srcYincr         = 0,                                       // unused
                                                   .dstYincr         = 0,                                       // unused
                                                   .yCount           = 0,                                       // unused
                                                   .descrNext        = NULL,                                    // updated later in descriptors
                                                };


/*======================================================================================
This CM0+ example shows 2 AXI DMA transfers in (1D) memory copy mode:

- Transfer #1: the whole source buffer is transferred to the destination using a single descriptor
- Transfer #2: the whole source buffer is transferred to the destination using a descriptor chain

The corresponding CM7 example will show the 2D and 3D transfer.
========================================================================================*/

int main(void)
{
    SystemInit();
  
    __enable_irq();    
    
    // Globally enable
    Cy_AXIDMA_Enable(AXI_DMAC);    
    
    /* Enable CM7_0. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
   
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
    
    //======================== TRANSFER #1 ==================================================================
    
    // Preset source buffer with test pattern and clear destination
    for(uint32_t i = 0; i < BUFFER_SIZE; i++)
    {
        srcBuffer[i] = (uint8_t) i;
        dstBuffer[i] = 0;
    }
    
    // Initialize the single descriptor
    Cy_AXIDMA_Descr_Init(&descriptor, &descriptorConfig);
    
    // Initialize & enable the channel, trigger transfer by SW
    Cy_AXIDMA_Chnl_Init(AXI_DMAC, DMAC_CHANNEL_SINGLE, &chnlConfig);
    Cy_AXIDMA_Chnl_Enable(AXI_DMAC, DMAC_CHANNEL_SINGLE);
    Cy_AXIDMA_Chnl_SetSwTrigger(AXI_DMAC, DMAC_CHANNEL_SINGLE);
    
    // Wait for the completion interrupt flag to be set, then clear it
    while(Cy_AXIDMA_Chnl_GetInterruptStatus(AXI_DMAC, DMAC_CHANNEL_SINGLE) != CY_AXIDMA_INTRCAUSE_COMPLETION)
    {
    }
    Cy_AXIDMA_Chnl_ClearInterrupt(AXI_DMAC, DMAC_CHANNEL_SINGLE, CY_AXIDMA_INTRCAUSE_COMPLETION);
    
    // Check for expected data
    for(uint32_t i = 0; i < BUFFER_SIZE; i++)
    {
        CY_ASSERT(srcBuffer[i] == dstBuffer[i]);
    }
    
    //======================== TRANSFER #2 ==================================================================
    
    // Preset source buffer with test pattern and clear destination
    for(uint32_t i = 0; i < BUFFER_SIZE; i++)
    {
        srcBuffer[i] = (uint8_t) i;
        dstBuffer[i] = 0;
    }
    
    // Initialize the descriptor chain and make runtime updates to descriptor dependent parameters (src, dest, next)
    for(uint8_t descIndex = 0; descIndex < NR_OF_CHAINED_DESCRIPTORS; descIndex++)
    {
        Cy_AXIDMA_Descr_Init(&pDescChain1D[descIndex], &descriptorChainConfig);
        
        uint32_t addressOffset = descIndex * (BUFFER_SIZE / NR_OF_CHAINED_DESCRIPTORS);
        Cy_AXIDMA_Descr_SetSrcAddr (&pDescChain1D[descIndex], srcBuffer + addressOffset);
        Cy_AXIDMA_Descr_SetDstAddr(&pDescChain1D[descIndex], dstBuffer + addressOffset);
        
        // Last descriptor shall keep its "NULL" next pointer from the default config, to indicate the end of the chain
        if(descIndex < (NR_OF_CHAINED_DESCRIPTORS - 1))
        {
            Cy_AXIDMA_Descr_SetNxtDescr(&pDescChain1D[descIndex], &pDescChain1D[descIndex + 1]);
        }
    }
    
    // Initialize & enable the channel, trigger transfer by SW
    Cy_AXIDMA_Chnl_Init(AXI_DMAC, DMAC_CHANNEL_CHAIN, &chnlConfigChain);
    Cy_AXIDMA_Chnl_Enable(AXI_DMAC, DMAC_CHANNEL_CHAIN);
    Cy_AXIDMA_Chnl_SetSwTrigger(AXI_DMAC, DMAC_CHANNEL_CHAIN);
    
    // Wait for the completion interrupt flag to be set, then clear it
    while(Cy_AXIDMA_Chnl_GetInterruptStatus(AXI_DMAC, DMAC_CHANNEL_CHAIN) != CY_AXIDMA_INTRCAUSE_COMPLETION)
    {
    }
    Cy_AXIDMA_Chnl_ClearInterrupt(AXI_DMAC, DMAC_CHANNEL_CHAIN, CY_AXIDMA_INTRCAUSE_COMPLETION);
    
    // Check for expected data
    for(uint32_t i = 0; i < BUFFER_SIZE; i++)
    {
        CY_ASSERT(srcBuffer[i] == dstBuffer[i]);
    }
    
    //=========================================================================================================

    for(;;)
    {
		// Delay for 0.05[s]
        Cy_SysTick_DelayInUs(50000);       
        Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
    }
}



/* [] END OF FILE */
