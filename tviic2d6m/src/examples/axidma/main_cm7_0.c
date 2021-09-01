/***************************************************************************//**
* \file main_cm7_0.c
*
* \version 1.0
*
* \brief Main example file for CM7
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
    #define USER_LED_PORT           CY_LED8_PORT
    #define USER_LED_PIN            CY_LED8_PIN
    #define USER_LED_PIN_MUX        CY_LED8_PIN_MUX
    // The core frequency is 24MHz. 1200000 / 24MHz = 0.05[s]
    #define USER_LED_TOGGLE_DELAY1  600000
    #define USER_LED_TOGGLE_DELAY2  600000
#else
    #define USER_LED_PORT           CY_USER_LED2_PORT
    #define USER_LED_PIN            CY_USER_LED2_PIN
    #define USER_LED_PIN_MUX        CY_USER_LED2_PIN_MUX 
    // The core frequency is 320MHz. 16000000 / 320MHz = 0.05[s]
    #define USER_LED_TOGGLE_DELAY1  8000000
    #define USER_LED_TOGGLE_DELAY2  8000000	
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
#define DMAC_CHANNEL_2D            2
#define DMAC_CHANNEL_3D            3

#define M_LOOP_COUNT_2D            1
#define X_LOOP_SRC_INCR_2D         2
#define X_LOOP_DST_INCR_2D         1
#define X_LOOP_COUNT_2D            (BUFFER_SIZE / 2)

#define M_LOOP_COUNT_3D            1
#define X_LOOP_SRC_INCR_3D         2
#define X_LOOP_DST_INCR_3D         1
#define X_LOOP_COUNT_3D            (BUFFER_SIZE / 2)
#define Y_LOOP_SRC_INCR_3D         1
#define Y_LOOP_DST_INCR_3D         (BUFFER_SIZE / 2)
#define Y_LOOP_COUNT_3D            2


// In order to avoid potential side-effects when invalidating of corresponding cache lines, the buffer size should be
// a multiple of 32 bytes, because cache lines are 32 bytes.
#if ((BUFFER_SIZE % 32) != 0)
    #error BUFFER_SIZE in this example should be a multiple of 32 bytes
#endif

static uint8_t srcBuffer[BUFFER_SIZE]  __ALIGNED(32); // Align to 32-byte boundary to simplify cache maintenance
static uint8_t dstBuffer[BUFFER_SIZE]  __ALIGNED(32); // Align to 32-byte boundary to simplify cache maintenance

static cy_stc_axidma_2d_memcopy_descr_t descriptor2D  __ALIGNED(32); // Align to 32-byte boundary to simplify cache maintenance
static cy_stc_axidma_3d_memcopy_descr_t descriptor3D  __ALIGNED(32); // Align to 32-byte boundary to simplify cache maintenance

const   cy_stc_axidma_chnl_config_t chnlConfig2D = {
                                                     .AXIDMA_Descriptor = &descriptor2D,
                                                     .priority          = 0,
                                                     .enable            = 1,
                                                 };

static  cy_stc_axidma_descr_config_t  descriptorConfig2D = {
                                                   .deact            = CY_AXIDMA_TRIG_DEACT_NO_WAIT,
                                                   .intrType         = CY_AXIDMA_INTR_DESCRCHAIN_CMPLT,    // used for polling
                                                   .trigoutType      = CY_AXIDMA_TRIGOUT_DESCRCHAIN_CMPLT, // unused
                                                   .triginType       = CY_AXIDMA_TRIGIN_DESCRCHAIN,
                                                   .disableChAtCmplt = false,
                                                   .dataPrefetch     = true,
                                                   .descrType        = CY_AXIDMA_2D_MEMCOPY_TRANSFER,
                                                   .srcAddr          = srcBuffer,
                                                   .dstAddr          = dstBuffer,
                                                   .mCount           = M_LOOP_COUNT_2D,
                                                   .srcXincr         = X_LOOP_SRC_INCR_2D,
                                                   .dstXincr         = X_LOOP_DST_INCR_2D,
                                                   .xCount           = X_LOOP_COUNT_2D,
                                                   .srcYincr         = 0,                                  // unused
                                                   .dstYincr         = 0,                                  // unused
                                                   .yCount           = 0,                                  // unused
                                                   .descrNext        = NULL,
                                                };

const   cy_stc_axidma_chnl_config_t chnlConfig3D = {
                                                     .AXIDMA_Descriptor = &descriptor3D,
                                                     .priority          = 0,
                                                     .enable            = 1,
                                                 };


static  cy_stc_axidma_descr_config_t  descriptorConfig3D = {
                                                   .deact            = CY_AXIDMA_TRIG_DEACT_NO_WAIT,
                                                   .intrType         = CY_AXIDMA_INTR_DESCRCHAIN_CMPLT,    // used for polling
                                                   .trigoutType      = CY_AXIDMA_TRIGOUT_DESCRCHAIN_CMPLT, // unused
                                                   .triginType       = CY_AXIDMA_TRIGIN_DESCRCHAIN,
                                                   .disableChAtCmplt = false,
                                                   .dataPrefetch     = true,
                                                   .descrType        = CY_AXIDMA_3D_MEMCOPY_TRANSFER,
                                                   .srcAddr          = srcBuffer,
                                                   .dstAddr          = dstBuffer,
                                                   .mCount           = M_LOOP_COUNT_3D,
                                                   .srcXincr         = X_LOOP_SRC_INCR_3D,
                                                   .dstXincr         = X_LOOP_DST_INCR_3D,
                                                   .xCount           = X_LOOP_COUNT_3D,
                                                   .srcYincr         = Y_LOOP_SRC_INCR_3D,
                                                   .dstYincr         = Y_LOOP_DST_INCR_3D,
                                                   .yCount           = Y_LOOP_COUNT_3D,
                                                   .descrNext        = NULL,
                                                };



/*======================================================================================
This CM7 example shows 2 AXI DMA transfers in 2D and 3D memory copy mode:

- Transfer #1 (2D): Only the even numbers in the source buffer are copied to a consecutive
                    region in the destination area
- Transfer #2 (3D): The even and the odd numbers in the source buffer are copied individually
                    to a consecutive region in the destination area

========================================================================================*/

int main(void)
{
    SystemInit();
    
    __enable_irq();
    
    // Globally enable (only needed if CM0+ example is not running in parallel, but also does not cause any harm if called here again)
    Cy_AXIDMA_Enable(AXI_DMAC);    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
    
    //======================== TRANSFER #1 ==================================================================

    // Preset source buffer with test pattern and clear destination
    for(uint32_t i = 0; i < BUFFER_SIZE; i++)
    {
        srcBuffer[i] = (uint8_t) i;
        dstBuffer[i] = 0;
    }
    // Ensure buffer data is cleaned out to SRAM (so that it can be accessed by DMA later on)
    SCB_CleanDCache_by_Addr((uint32_t *) srcBuffer, sizeof(srcBuffer));
    SCB_CleanDCache_by_Addr((uint32_t *) dstBuffer, sizeof(dstBuffer));
    
    // Initialize the single descriptor
    Cy_AXIDMA_Descr_Init(&descriptor2D, &descriptorConfig2D);
    // Ensure descriptor data is cleaned out to SRAM (so that it can be accessed by DMA later on)
    SCB_CleanDCache_by_Addr((uint32_t *) &descriptor2D, sizeof(descriptor2D));
    
    // Initialize & enable the channel, trigger transfer by SW
    Cy_AXIDMA_Chnl_Init(AXI_DMAC, DMAC_CHANNEL_2D, &chnlConfig2D);
    Cy_AXIDMA_Chnl_Enable(AXI_DMAC, DMAC_CHANNEL_2D);
    Cy_AXIDMA_Chnl_SetSwTrigger(AXI_DMAC, DMAC_CHANNEL_2D);
    
    // Wait for the completion interrupt flag to be set, then clear it
    while(Cy_AXIDMA_Chnl_GetInterruptStatus(AXI_DMAC, DMAC_CHANNEL_2D) != CY_AXIDMA_INTRCAUSE_COMPLETION)
    {
    }
    Cy_AXIDMA_Chnl_ClearInterrupt(AXI_DMAC, DMAC_CHANNEL_2D, CY_AXIDMA_INTRCAUSE_COMPLETION);
    
    // Destination buffer has bee modified by DMA, so the corresponding area needs to be invalidated before accessing it by CPU
    SCB_InvalidateDCache_by_Addr((uint32_t *) dstBuffer, sizeof(dstBuffer));
    
    // Check for expected data
    for(uint32_t i = 0; i < BUFFER_SIZE; i++)
    {
        if(i < (BUFFER_SIZE / 2))
        {
            // First half contains even numbers
            CY_ASSERT(dstBuffer[i] == (i * 2));
        }
        else
        {
            // Second half should not have been written
            CY_ASSERT(dstBuffer[i] == 0);
        }
    }

    //======================== TRANSFER #2 ==================================================================
    
    // Preset source buffer with test pattern and clear destination
    for(uint32_t i = 0; i < BUFFER_SIZE; i++)
    {
        srcBuffer[i] = (uint8_t) i;
        dstBuffer[i] = 0;
    }
    // Ensure buffer data is cleaned out to SRAM (so that it can be accessed by DMA later on)
    SCB_CleanDCache_by_Addr((uint32_t *) srcBuffer, sizeof(srcBuffer));
    SCB_CleanDCache_by_Addr((uint32_t *) dstBuffer, sizeof(dstBuffer));
    
    // Initialize the single descriptor
    Cy_AXIDMA_Descr_Init(&descriptor3D, &descriptorConfig3D);
    // Ensure descriptor data is cleaned out to SRAM (so that it can be accessed by DMA later on)
    SCB_CleanDCache_by_Addr((uint32_t *) &descriptor3D, sizeof(descriptor3D));
    
    // Initialize & enable the channel, trigger transfer by SW
    Cy_AXIDMA_Chnl_Init(AXI_DMAC, DMAC_CHANNEL_3D, &chnlConfig3D);
    Cy_AXIDMA_Chnl_Enable(AXI_DMAC, DMAC_CHANNEL_3D);
    Cy_AXIDMA_Chnl_SetSwTrigger(AXI_DMAC, DMAC_CHANNEL_3D);
    
    // Wait for the completion interrupt flag to be set, then clear it
    while(Cy_AXIDMA_Chnl_GetInterruptStatus(AXI_DMAC, DMAC_CHANNEL_3D) != CY_AXIDMA_INTRCAUSE_COMPLETION)
    {
    }
    Cy_AXIDMA_Chnl_ClearInterrupt(AXI_DMAC, DMAC_CHANNEL_3D, CY_AXIDMA_INTRCAUSE_COMPLETION);
    
    // Destination buffer has bee modified by DMA, so the corresponding area needs to be invalidated before accessing it by CPU
    SCB_InvalidateDCache_by_Addr((uint32_t *) dstBuffer, sizeof(dstBuffer));
    
    // Check for expected data
    for(uint32_t i = 0; i < BUFFER_SIZE; i++)
    {
        if(i < (BUFFER_SIZE / 2))
        {
            // First half contains even numbers
            CY_ASSERT(dstBuffer[i] == (i * 2));
        }
        else
        {
            // Second half contains odd numbers
            uint32_t j = i - (BUFFER_SIZE / 2); // j: 0-based index for second half of buffer to generate expected data
            CY_ASSERT(dstBuffer[i] == ((j * 2) + 1));
        }
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
