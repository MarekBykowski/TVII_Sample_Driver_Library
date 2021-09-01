/***************************************************************************//**
* \file cy_dac.c
* \version 1.0
*
* Provides an API implementation of the audio dac driver.
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_dac.h"
#include "syslib/cy_syslib.h"

#include <stdlib.h>

#ifdef CY_IP_MXS40EAUDIODAC

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
* Function Name: Cy_AudioDac_Init
********************************************************************************
* \brief 
* Initializes the audio DAC structure.
*
* \param base The pointer to the stc_DAC_t instance address.  
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_audiodac_status_t.
*
*******************************************************************************/
cy_en_audiodac_status_t Cy_AudioDac_Init(volatile stc_DAC_t * base, cy_stc_audiodac_config_t const * config)
{
    cy_en_audiodac_status_t                     dacStatus = CY_AUDIODAC_BAD_PARAM;
    un_DAC_IF_CTL_t                             temp_DAC_IF_CTL = {0};
    un_DAC_COUNT_t                              temp_DAC_COUNT = {0};
    un_DAC_TX_FIFO_CTL_t                        temp_DAC_TX_FIFO_CTL = {0};
    
    // Check if the base address and the config are not NULL
    if((NULL != base) && (NULL != config))
    {
        // Enable Module
        base->unCTL.stcField.u1ENABLED = true;
        
        // Select DAC interface clock divider, interface clock and sample frequency
        temp_DAC_IF_CTL.stcField.u8CLOCK_DIV = config->clkDiv;  
        temp_DAC_IF_CTL.stcField.u3CLOCK_SEL = config->clkSel;
        temp_DAC_IF_CTL.stcField.u2FS_SEL = config->sampFreq;
        base->unIF_CTL.u32Register = temp_DAC_IF_CTL.u32Register;
        
        // Update 1ms count, fast ramp count and complete ramp count
        temp_DAC_COUNT.stcField.u16COUNT_1MS = config->count;
        temp_DAC_COUNT.stcField.u8FAST_RAMP_COUNT_IN_MS = config->fastRampCount;
        temp_DAC_COUNT.stcField.u8COMP_RAMP_COUNT_IN_MS = config->compRampCount;
        base->unCOUNT.u32Register = temp_DAC_COUNT.u32Register;
        
        // Update TX FIFO trigger level
        temp_DAC_TX_FIFO_CTL.stcField.u6TRIGGER_LEVEL = config->trgLevel;
        base->unTX_FIFO_CTL.u32Register = temp_DAC_TX_FIFO_CTL.u32Register;
        
        // Update status
        dacStatus = CY_AUDIODAC_SUCCESS;
    }
    
    return dacStatus;
}

/*******************************************************************************
* Function Name: Cy_AudioDac_DeInit
********************************************************************************
* \brief 
* De-Initializes the audio DAC structure.
*
* \param base The pointer to the stc_DAC_t instance address.  
*
* \return None.
*
*******************************************************************************/
void Cy_AudioDac_DeInit(volatile stc_DAC_t * base)
{
    // Check if the base address is not NULL
    if(NULL != base)
    {
        base->unIF_CTL.u32Register = 0ul;
        base->unCOUNT.u32Register = 0ul;
        base->unTX_FIFO_CTL.u32Register = 0ul;
    }
}

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* CY_IP_MXMIXER */

/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
