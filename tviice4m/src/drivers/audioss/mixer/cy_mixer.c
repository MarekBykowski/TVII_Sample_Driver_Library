/***************************************************************************//**
* \file cy_mixer.c
* \version 1.0
*
* Provides an API implementation of the mixer driver.
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_mixer.h"
#include "syslib/cy_syslib.h"

#include <stdlib.h>

#ifdef CY_IP_MXMIXER

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
* Function Name: Cy_Mixer_SourceInit
********************************************************************************
* \brief 
* Initializes the Mixer source structure.
*
* \param base The pointer to the stc_MIXER_MIXER_SRC_STRUCT_t instance address.  
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_mixer_status_t.
*
*******************************************************************************/
cy_en_mixer_status_t Cy_Mixer_SourceInit(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_stc_mixer_src_config_t const * config)
{
    cy_en_mixer_status_t                     mxStatus          = CY_MIXER_BAD_PARAM;
    un_MIXER_MIXER_SRC_STRUCT_SRC_CTL_t      temp_SRC_CTL      = {0ul};
    un_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CTL_t temp_SRC_FADE_CTL = {0ul};
    un_MIXER_MIXER_SRC_STRUCT_SRC_GAIN_CTL_t temp_SRC_GAIN_CTL = {0ul};
    un_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL_t temp_SRC_FIFO_CTL = {0ul};
    
    // Check if the base address and the config are not NULL
    if((NULL != base) && (NULL != config))
    {
        // Update Sample frequency upscale ratio
        temp_SRC_CTL.stcField.u3FS_RATIO = config->fsRatio;

        // Based on the selected channel, update the data selection
        temp_SRC_CTL.stcField.u2CH0_SEL = config->ch0sel;
        temp_SRC_CTL.stcField.u2CH1_SEL = config->ch0sel;

        // Update SRC_CTL register
        base->unSRC_CTL.u32Register = temp_SRC_CTL.u32Register;

        // Gain code in the range [0, 115]
        temp_SRC_FADE_CTL.stcField.u7CODE = config->fadeCode;
        base->unSRC_FADE_CTL.u32Register = temp_SRC_FADE_CTL.u32Register;

        // Gain code in the range [0, 127]. Each gain code increment represents 1 dB. 
        // Gain code value "0" represents digital mute
        temp_SRC_GAIN_CTL.stcField.u7CODE = config->gainCode;
        base->unSRC_GAIN_CTL.u32Register = temp_SRC_GAIN_CTL.u32Register;

        // Trigger level
        temp_SRC_FIFO_CTL.stcField.u7TRIGGER_LEVEL = config->trgLevel;
        base->unSRC_FIFO_CTL.u32Register = temp_SRC_FIFO_CTL.u32Register;

        // Update status
        mxStatus = CY_MIXER_SUCCESS;
    }
    
    return mxStatus;
}

/*******************************************************************************
* Function Name: Cy_Mixer_SourceDeInit
********************************************************************************
* \brief 
* De-Initializes the Mixer source structure.
*
* \param base The pointer to the stc_MIXER_MIXER_SRC_STRUCT_t instance address.  
*
* \return None.
*
*******************************************************************************/
void Cy_Mixer_SourceDeInit(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    // Check if the base address is not NULL
    if(NULL != base)
    {
        base->unSRC_CTL.u32Register = 0ul;
        base->unSRC_FADE_CTL.u32Register = 0ul;
        base->unSRC_FADE_CMD.u32Register = 0ul;
        base->unSRC_GAIN_CTL.u32Register = 0ul;
        base->unSRC_FIFO_CTL.u32Register = 0ul;
    }
}

/*******************************************************************************
* Function Name: Cy_Mixer_SourceStartFadeIn
********************************************************************************
* 
* \brief triggers source fade in.
*
* \param base The pointer to the stc_MIXER_MIXER_SRC_STRUCT_t instance address.  
*
* \param pace pace of the fade in
*
* \return None.
*
*******************************************************************************/
void Cy_Mixer_SourceStartFadeIn(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, uint32_t pace)
{
    if(NULL != base)
    {
        un_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_t wFadeCmdReg = {0};
        wFadeCmdReg.stcField.u1FADE_IN   = 1ul;
        wFadeCmdReg.stcField.u10PACE     = pace;
        base->unSRC_FADE_CMD.u32Register = wFadeCmdReg.u32Register;
    }

}

/*******************************************************************************
* Function Name: Cy_Mixer_SourceHasFadeInCompleted
********************************************************************************
* 
* \brief checks previous fade in operation already completed or not
*
* \param base The pointer to the stc_MIXER_MIXER_SRC_STRUCT_t instance address.  
*
* \return true : Previous fade in operation already completed
*         false: Previous fade in operation still on the way
*
*******************************************************************************/
bool Cy_Mixer_SourceHasFadeInCompleted(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    return (base->unSRC_FADE_CMD.stcField.u1FADE_IN == 0);
}

/*******************************************************************************
* Function Name: Cy_Mixer_SourceStartFadeOut
********************************************************************************
* 
* \brief triggers fade out
*
* \param base The pointer to the stc_MIXER_MIXER_SRC_STRUCT_t instance address.  
*
* \param pace pace of the fade in
*
* \param deact true: deactivate the src FIFO when fade out completed
*              false: Do not deactivate the src FIFO when fade out completed
*
* \return None.
*
*******************************************************************************/
void Cy_Mixer_SourceStartFadeOut(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, uint32_t pace, bool deact)
{
    if(NULL != base)
    {
        un_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_t wFadeCmdReg = {0};
        wFadeCmdReg.stcField.u1FADE_OUT        = 1ul;
        wFadeCmdReg.stcField.u10PACE           = pace;
        wFadeCmdReg.stcField.u1AUTO_DEACTIVATE = (uint32_t)deact;
        base->unSRC_FADE_CMD.u32Register       = wFadeCmdReg.u32Register;
    }

}

/*******************************************************************************
* Function Name: Cy_Mixer_SourceHasFadeOutCompleted
********************************************************************************
* 
* \brief checks previous fade out operation already completed or not
*
* \param base The pointer to the stc_MIXER_MIXER_SRC_STRUCT_t instance address.  
*
* \return true : Previous fade out operation already completed
*         false: Previous fade out operation still on the way
*
*******************************************************************************/
bool Cy_Mixer_SourceHasFadeOutCompleted(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    return (base->unSRC_FADE_CMD.stcField.u1FADE_OUT == 0);
}


/*******************************************************************************
* Function Name: Cy_Mixer_DestinationInit
********************************************************************************
* \brief 
* Initializes the Mixer destination structure.
*
* \param base The pointer to the stc_MIXER_MIXER_DST_STRUCT_t instance address.  
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_mixer_status_t.
*
*******************************************************************************/
cy_en_mixer_status_t Cy_Mixer_DestinationInit(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, cy_stc_mixer_dst_config_t const * config)
{
    cy_en_mixer_status_t                        mxStatus = CY_MIXER_BAD_PARAM;
    un_MIXER_MIXER_DST_STRUCT_DST_FADE_CTL_t    temp_DST_FADE_CTL = {0ul};
    un_MIXER_MIXER_DST_STRUCT_DST_GAIN_CTL_t    temp_DST_GAIN_CTL = {0ul};
    un_MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL_t    temp_DST_FIFO_CTL = {0ul};

    // Check if the base address and the config are not NULL
    if((NULL != base) && (NULL != config))
    {
        // Gain code in the range [0, 115]
        temp_DST_FADE_CTL.stcField.u7CODE = config->fadeCode;
        base->unDST_FADE_CTL.u32Register = temp_DST_FADE_CTL.u32Register;

        // Gain code in the range [0, 127]. Each gain code increment represents 1 dB. 
        // Gain code value "0" represents digital mute
        temp_DST_GAIN_CTL.stcField.u7CODE = config->gainCode;
        base->unDST_GAIN_CTL.u32Register = temp_DST_GAIN_CTL.u32Register;
        
        // Trigger level
        temp_DST_FIFO_CTL.stcField.u6TRIGGER_LEVEL = config->trgLevel;
        base->unDST_FIFO_CTL.u32Register = temp_DST_FIFO_CTL.u32Register;
        
        // Update status
        mxStatus = CY_MIXER_SUCCESS;      
    }
    
    return mxStatus;
}

/*******************************************************************************
* Function Name: Cy_Mixer_DestinationDeInit
********************************************************************************
* \brief 
* DeInitializes the Mixer destination structure.
*
* \param base The pointer to the stc_MIXER_MIXER_DST_STRUCT_t instance address.  
*
* \return None.
*
*******************************************************************************/
void Cy_Mixer_DestinationDeInit(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    // Check if the base address is not NULL
    if(NULL != base)
    {
        base->unDST_FADE_CTL.u32Register = 0ul;
        base->unDST_FADE_CMD.u32Register = 0ul;
        base->unDST_GAIN_CTL.u32Register = 0ul;
        base->unDST_FIFO_CTL.u32Register = 0ul;
    }
}

/*******************************************************************************
* Function Name: Cy_Mixer_TransmitInit
********************************************************************************
* \brief 
* Initializes the Mixer transmit structure.
*
* \param base The pointer to the stc_MIXER_MIXER_TX_STRUCT_t instance address.  
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_mixer_status_t.
*
*******************************************************************************/
cy_en_mixer_status_t Cy_Mixer_TransmitInit(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_stc_mixer_tx_config_t const * config)
{
    cy_en_mixer_status_t                        mxStatus = CY_MIXER_BAD_PARAM;
    un_MIXER_MIXER_TX_STRUCT_TX_CTL_t           temp_TX_CTL;
    un_MIXER_MIXER_TX_STRUCT_TX_IF_CTL_t        temp_TX_IF_CTL;    
    
    // Check if the base address and the config are not NULL
    if((NULL != base) && (NULL != config))
    {
        // Configure word size, format and the tx mode
        temp_TX_CTL.stcField.u4WORD_SIZE = config->wordSize;        
        temp_TX_CTL.stcField.u2FORMAT = config->txFormat;        
        temp_TX_CTL.stcField.u1MS = config->txMode;
        base->unTX_CTL.u32Register = temp_TX_CTL.u32Register;
        
        // Configure clock divider, selection, polarity
        temp_TX_IF_CTL.stcField.u8CLOCK_DIV = config->clkDiv;
        temp_TX_IF_CTL.stcField.u3CLOCK_SEL = config->clkSel;
        temp_TX_IF_CTL.stcField.u1SCK_POLARITY = config->clkPol;
        temp_TX_IF_CTL.stcField.u1WS_POLARITY = config->wSelPol;
        if(config->channel == CY_MIXER_CHANNEL0)
        {
            temp_TX_IF_CTL.stcField.u1CH0_EN = true;
        }
        else // (config->channel == CY_MIXER_CHANNEL1)
        {
            temp_TX_IF_CTL.stcField.u1CH1_EN = true;
        }
        temp_TX_IF_CTL.stcField.u5CH_SIZE = config->chlSize;
        base->unTX_IF_CTL.u32Register = temp_TX_IF_CTL.u32Register;
        
        // Update status
        mxStatus = CY_MIXER_SUCCESS;  
    }
    
    return mxStatus;
}

/*******************************************************************************
* Function Name: Cy_Mixer_TransmitDeInit
********************************************************************************
* \brief 
* DeInitializes the Mixer transmit structure.
*
* \param base The pointer to the stc_MIXER_MIXER_TX_STRUCT_t instance address.
*
* \return error / status code. See \ref cy_en_mixer_status_t.
*
*******************************************************************************/
void Cy_Mixer_TransmitDeInit(volatile stc_MIXER_MIXER_TX_STRUCT_t * base)
{
    // Check if the base address is not NULL
    if(NULL != base)
    {
        base->unTX_CTL.u32Register = 0ul;
        base->unTX_IF_CTL.u32Register = 0ul;
    }
}

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* CY_IP_MXMIXER */

/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
