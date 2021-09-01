/***************************************************************************//**
* \file cy_tdm.c
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
#include "cy_tdm.h"
#include "syslib/cy_syslib.h"

#include <stdlib.h>

#ifdef CY_IP_MXTDM

#if defined(__cplusplus)
extern "C" {
    
#endif /* __cplusplus */

/*************************************************************************
* Function Name: Cy_AudioTDM_Init                                        
**************************************************************************
*
* Initializes the TDM structure.
*
* \param base The pointer to the TDM instance address.
*
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_tdm_status_t.
*
***************************************************************************/
cy_en_tdm_status_t Cy_AudioTDM_Init(volatile stc_TDM_TDM_STRUCT_t * base, cy_stc_tdm_config_t const * config)
{
    cy_en_tdm_status_t ret = CY_TDM_BAD_PARAM;
    
    if((NULL != base) && (NULL != config))
    {
       ret = Cy_AudioTDM_TX_Init(&(base->TDM_TX_STRUCT),&(config->tx_config));
       if(ret == CY_TDM_BAD_PARAM)
       {
            return(ret);
        }
       ret = Cy_AudioTDM_RX_Init(&(base->TDM_RX_STRUCT),&(config->rx_config));
    }
    return (ret);
}

/************************************************************************
 Function Name: Cy_AudioTDM_TX_Init                                     
*************************************************************************
*
* Initializes the TDM Transmitter module in accordance with a configuration structure.
*
* \param base The pointer to the TDM->TX instance address.
*
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_tdm_status_t.
*
****************************************************************************/
cy_en_tdm_status_t Cy_AudioTDM_TX_Init(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base, cy_stc_tdm_config_tx_t const * config)
{
   // cy_en_tdm_source_status_t   status  = CY_TDM_OK;
    cy_en_tdm_status_t          ret     = CY_TDM_SUCCESS;
    
    un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_t  temp_IF_CTL = {0};
    un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_t     temp_TX_CTL = {0};
    
    if((NULL != base) && (NULL != config))
    {
        if((config->txClkDiv == 0) || (config->txClkDiv > 256))
        {
            ret = CY_TDM_BAD_PARAM;
            return(ret);
        }
        uint8_t clockDiv = config->txClkDiv -1U;

        if(config->txChannelNUM == 0) 
        {
            ret = CY_TDM_BAD_PARAM;
            return(ret);
        }
        uint8_t ChannelNum = config->txChannelNUM - 1U;

        if(config->txChannelSize == 0)
        {
            ret = CY_TDM_BAD_PARAM;
            return(ret);
        }
        uint8_t ChannelSIZE = config->txChannelSize - 1U;
        
        /* Channnel Default */
        if(base->unTX_CTL.stcField.u1ENABLED == 1u)
        {
            ret = CY_TDM_BAD_PARAM;
            return(ret);
        }
        
        /* The TX interface setting */
        temp_IF_CTL.stcField.u8CLOCK_DIV                = clockDiv; 
        temp_IF_CTL.stcField.u3CLOCK_SEL                = config->txClkSel;
        temp_IF_CTL.stcField.u1SCK_POLARITY             = config->txSckPolarity;
        temp_IF_CTL.stcField.u1FSYNC_POLARITY           = config->txFsyncPolarity;
        temp_IF_CTL.stcField.u1FSYNC_FORMAT             = config->txFsyncFormat;
        temp_IF_CTL.stcField.u5CH_NR                    = ChannelNum;
        temp_IF_CTL.stcField.u5CH_SIZE                  = ChannelSIZE;
        base->unTX_IF_CTL.u32Register                   = temp_IF_CTL.u32Register;
        /*test Mode */
        base->unTX_TEST_CTL.stcField.u1ENABLED      = config->txTestMode;
        /* Chanel Enable */
        base->unTX_CH_CTL.stcField.u32CH_EN             = config->txChEN;
        /* The FIFO setting */           
        base->unTX_FIFO_CTL.stcField.u7TRIGGER_LEVEL    = config->txFIFOTriggerLevel;
        /* The TC Interface setting */      
        temp_TX_CTL.stcField.u4WORD_SIZE                = config->txWordSize;
        temp_TX_CTL.stcField.u2FORMAT                   = config->txFormat;
        temp_TX_CTL.stcField.u1ENABLED                  = config->txEnable;
        temp_TX_CTL.stcField.u1MS                       = config->txMasterMode; 
        base->unTX_CTL.u32Register                      = temp_TX_CTL.u32Register; 
    }
    else
    {
        ret = CY_TDM_BAD_PARAM;
    }
    return (ret);
}
        
        
/**************************************************************************
* Function Name: Cy_AudioTDM_RX_Init                                     
**************************************************************************
*
* Initializes the TDM Receiver structure.
*
* \param base The pointer to the TDM->RX instance address.
*
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_tdm_status_t.
*
****************************************************************************/
cy_en_tdm_status_t Cy_AudioTDM_RX_Init(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base, cy_stc_tdm_config_rx_t const * config)
{
    cy_en_tdm_status_t ret = CY_TDM_SUCCESS;
    
    un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_t  temp_IF_CTL = {0};
    un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_t     temp_RX_CTL = {0};
    
    if((NULL != base) && (NULL != config))
    {
        if((config->rxClkDiv == 0) || (config->rxClkDiv > 256))
        {
            ret = CY_TDM_BAD_PARAM;
            return(ret);
        }
        uint16_t clockDiv   = (uint32_t)config->rxClkDiv - 1U;
        
        if(config->rxChannelSize == 0)
        {
            ret = CY_TDM_BAD_PARAM;
            return(ret);
        }
        uint8_t ChannelSIZE = config->rxChannelSize - 1U;
        
        if(config->rxChannelNUM == 0) 
        {
            ret = CY_TDM_BAD_PARAM;
            return(ret);
        }
        uint8_t ChannelNum  = config->rxChannelNUM - 1U;
        
        /* The RX interface setting */
        temp_IF_CTL.stcField.u8CLOCK_DIV                = clockDiv;
        temp_IF_CTL.stcField.u3CLOCK_SEL                = config->rxClkSel;
        temp_IF_CTL.stcField.u1SCK_POLARITY             = config->rxSckPolarity;
        temp_IF_CTL.stcField.u1FSYNC_POLARITY           = config->rxFsyncPolarity;
        temp_IF_CTL.stcField.u1LATE_SAMPLE              = config->rxLateSample;
        temp_IF_CTL.stcField.u1FSYNC_FORMAT             = config->rxFsyncFormat;
        temp_IF_CTL.stcField.u5CH_NR                    = ChannelNum; 
        temp_IF_CTL.stcField.u5CH_SIZE                  = ChannelSIZE;
        base->unRX_IF_CTL.u32Register                   = temp_IF_CTL.u32Register;
        /*test Mode */
        base->unRX_TEST_CTL.stcField.u1ENABLED          = config->rxTestMode;
        /* Chanel Enable */
        base->unRX_CH_CTL.stcField.u32CH_EN             = config->rxChEN;
        base->unRX_FIFO_CTL.stcField.u7TRIGGER_LEVEL    = config->rxFIFOTriggerLevel;     
        /* The RX Interface setting */
        temp_RX_CTL.stcField.u4WORD_SIZE                = config->rxWordSize;
        temp_RX_CTL.stcField.u1WORD_SIGN_EXTEND         = config->rxSignExtend;
        temp_RX_CTL.stcField.u2FORMAT                   = config->rxFormat;
        temp_RX_CTL.stcField.u1MS                       = config->rxMasterMode;
        temp_RX_CTL.stcField.u1ENABLED                  = config->rxEnable;
        base->unRX_CTL.u32Register                      = temp_RX_CTL.u32Register;
    }
    else
    {
        ret = CY_TDM_BAD_PARAM;
    }

    return (ret);
}


/*************************************************************************
 Function Name: Cy_AudioTDM_DeInit                                      
**************************************************************************
*
* De-Initiallizes the audio TDM structure.
* 
* \param baes
* The pointer to the stc_TDM_t instance address
*
* \return None.
*
***************************************************************************/
void Cy_AudioTDM_DeInit(volatile stc_TDM_TDM_STRUCT_t * base)
{
    Cy_AudioTDM_TX_DeInit(&(base->TDM_TX_STRUCT));
    Cy_AudioTDM_RX_DeInit(&(base->TDM_RX_STRUCT));
}

/************************************************************************
* Function Name: Cy_AudioTDM_TX_DeInit                                   
*************************************************************************
*
* De-Initiallizes the audio TDM Transmitter structure.
* 
* \param base The pointer to the TDM->TX instance address.
*
* \return None.
*
***************************************************************************/
void Cy_AudioTDM_TX_DeInit(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
    base->unINTR_TX_MASK.u32Register    = 0UL;
    base->unTX_FIFO_CTL.u32Register     = 0UL;
    base->unTX_IF_CTL.u32Register       = CY_TDM_TX_IF_CTL_DEFAULT;
    base->unTX_CTL.u32Register          = CY_TDM_TX_CTL_DEFAULT;
}

/***********************************************************************
 Function Name: Cy_AudioTDM_RX_DeInit                                   
************************************************************************
*
* De-Initiallizes the audio TDM Receiver structure.
* 
* \param base The pointer to the TDM->RX instance address.
*
* \return None.
*
***************************************************************************/
void Cy_AudioTDM_RX_DeInit(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    base->unINTR_RX_MASK.u32Register    = 0UL;
    base->unRX_FIFO_CTL.u32Register     = 0UL;
    base->unRX_IF_CTL.u32Register       = CY_TDM_RX_IF_CTL_DEFAULT;
    base->unRX_CTL.u32Register          = CY_TDM_RX_CTL_DEFAULT;
}

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* CY_IP_MXTDM */

/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
