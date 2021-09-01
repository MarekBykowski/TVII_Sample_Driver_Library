/***************************************************************************//**
* \file cy_i2s.c
* \version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
* The source code file for the I2S driver.
*
********************************************************************************
* \copyright
* Copyright 2018-2020, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_i2s.h"

#ifdef CY_IP_MXTDM

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
* Function Name: Cy_I2S_Init
****************************************************************************//**
*
* Initializes the I2S module in accordance with a configuration structure.
*
* \pre If the I2S module is initialized previously, the \ref Cy_I2S_DeInit()
* must be called before calling this function.
*
* \param base The pointer to the I2S instance address.
*
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_i2s_status_t.
*
* \funcusage
* \
*
*******************************************************************************/
cy_en_i2s_status_t Cy_I2S_Init(volatile stc_TDM_TDM_STRUCT_t * base, cy_stc_i2s_config_t const * config)
{
    cy_en_i2s_status_t ret = CY_I2S_BAD_PARAM;

    if((NULL != base) && (NULL != config))
    {
        Cy_I2S_Tx_Init(&(base->TDM_TX_STRUCT), config);
        Cy_I2S_Rx_Init(&(base->TDM_RX_STRUCT), config);
    }

    return (ret);
}

/*******************************************************************************
* Function Name: Cy_I2S_Tx_Init
****************************************************************************//**
*
* Initializes the I2S Transmitter module in accordance with a configuration structure.
*
* \pre If the I2S TX module is initialized previously, the \ref Cy_I2S_Tx_DeInit()
* must be called before calling this function.
*
* \param base The pointer to the I2S->TX instance address.
*
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_i2s_status_t.
*
* \funcusage
*
*******************************************************************************/
cy_en_i2s_status_t Cy_I2S_Tx_Init(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base, cy_stc_i2s_config_t const * config)
{
    cy_en_i2s_status_t ret = CY_I2S_BAD_PARAM;

    un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_t temp_IF_CTL = {0};
    un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_t    temp_TX_CTL = {0};
    un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CH_CTL_t temp_TX_CH_TRL = {0};

    if((NULL != base) && (NULL != config))
    {
        CY_ASSERT_L2(CY_I2S_IS_CLK_DIV_VALID((uint16_t)config->txClkDiv));
        CY_ASSERT_L3(CY_I2S_IS_CHANNEL_SIZE_VALID(config->txChannelSize));
        
        /* The TX interface setting */
        temp_IF_CTL.stcField.u8CLOCK_DIV        = config->txClkDiv;
        temp_IF_CTL.stcField.u3CLOCK_SEL        = config->txClkSel;
        temp_IF_CTL.stcField.u1SCK_POLARITY     = config->txSckPolarity;
        temp_IF_CTL.stcField.u1FSYNC_POLARITY   = config->txFsyncPolarity;
        temp_IF_CTL.stcField.u1FSYNC_FORMAT     = config->txFsyncFormat;
        temp_IF_CTL.stcField.u5CH_NR            = config->txChannelNum;
        temp_IF_CTL.stcField.u5CH_SIZE          = config->txChannelSize;
        temp_IF_CTL.stcField.u1I2S_MODE         = 1u;
        base->unTX_IF_CTL.u32Register           = temp_IF_CTL.u32Register;
        
        temp_TX_CH_TRL.stcField.u32CH_EN        = config->txChannelEnable;
        base->unTX_CH_CTL.u32Register           = temp_TX_CH_TRL.u32Register;

        /* The Tx control setting */
        if (config->txEnabled)
        {
            CY_ASSERT_L3(CY_I2S_IS_FORMAT_VALID(config->txFormat));
            CY_ASSERT_L3(CY_I2S_IS_CHAN_WORD_VALID(config->txChannelSize, config->txWordSize));
            
            temp_TX_CTL.stcField.u4WORD_SIZE   = config->txWordSize;
            temp_TX_CTL.stcField.u2FORMAT      = config->txFormat;
            temp_TX_CTL.stcField.u1MS          = config->txMasterMode;
            temp_TX_CTL.stcField.u1ENABLED     = config->txEnabled;
            base->unTX_CTL.u32Register         = temp_TX_CTL.u32Register;
        }

        /* The FIFO setting */
        if (config->txEnabled)
        {
            CY_ASSERT_L2(CY_I2S_IS_TRIG_LEVEL_VALID(config->txFifoTriggerLevel));
            base->unTX_FIFO_CTL.stcField.u7TRIGGER_LEVEL = config->txFifoTriggerLevel;
        }
        
        ret = CY_I2S_SUCCESS;
    }

    return (ret);
}

/*******************************************************************************
* Function Name: Cy_I2S_Rx_Init
****************************************************************************//**
*
* Initializes the I2S Receiver module in accordance with a configuration structure.
*
* \pre If the I2S RX module is initialized previously, the \ref Cy_I2S_Rx_DeInit()
* must be called before calling this function.
*
* \param base The pointer to the I2S->RX instance address.
*
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_i2s_status_t.
*
* \funcusage
*
*******************************************************************************/
cy_en_i2s_status_t Cy_I2S_Rx_Init(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base, cy_stc_i2s_config_t const * config)
{
    cy_en_i2s_status_t ret = CY_I2S_BAD_PARAM;

    un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_t temp_IF_CTL = {0};
    un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_t    temp_RX_CTL = {0};
    un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CH_CTL_t temp_RX_CH_TRL = {0};

    if((NULL != base) && (NULL != config))
    {
        CY_ASSERT_L2(CY_I2S_IS_CLK_DIV_VALID((uint16_t)config->rxClkDiv));
        CY_ASSERT_L3(CY_I2S_IS_CHANNEL_SIZE_VALID(config->rxChannelSize));
        
        /* The RX interface setting */
        temp_IF_CTL.stcField.u8CLOCK_DIV        = config->rxClkDiv;
        temp_IF_CTL.stcField.u3CLOCK_SEL        = config->rxClkSel;
        temp_IF_CTL.stcField.u1SCK_POLARITY     = config->rxSckPolarity;
        temp_IF_CTL.stcField.u1FSYNC_POLARITY   = config->rxFsyncPolarity;
        temp_IF_CTL.stcField.u1LATE_SAMPLE      = config->rxLateSampleDelay;
        temp_IF_CTL.stcField.u1FSYNC_FORMAT     = config->rxFsyncFormat;
        temp_IF_CTL.stcField.u5CH_NR            = config->rxChannelNum;
        temp_IF_CTL.stcField.u5CH_SIZE          = config->rxChannelSize;
        temp_IF_CTL.stcField.u2LATE_CAPTURE     = config->rxLateCaptureDelay;
        temp_IF_CTL.stcField.u1I2S_MODE         = 1u;
        base->unRX_IF_CTL.u32Register           = temp_IF_CTL.u32Register;
        
        temp_RX_CH_TRL.stcField.u32CH_EN        = config->rxChannelEnable;
        base->unRX_CH_CTL.u32Register           = temp_RX_CH_TRL.u32Register;

        /* The Rx control setting */
        if (config->rxEnabled)
        {
            CY_ASSERT_L3(CY_I2S_IS_FORMAT_VALID(config->rxFormat));
            CY_ASSERT_L3(CY_I2S_IS_CHAN_WORD_VALID(config->rxChannelSize, config->rxWordSize));
            
            temp_RX_CTL.stcField.u4WORD_SIZE        = config->rxWordSize;
            temp_RX_CTL.stcField.u1WORD_SIGN_EXTEND = config->rxWsExtension;
            temp_RX_CTL.stcField.u2FORMAT           = config->rxFormat;
            temp_RX_CTL.stcField.u1MS               = config->rxMasterMode;
            temp_RX_CTL.stcField.u1ENABLED          = config->rxEnabled;
            base->unRX_CTL.u32Register              = temp_RX_CTL.u32Register;
        }

        /* The FIFO setting */
        if (config->rxEnabled)
        {
            CY_ASSERT_L2(CY_I2S_IS_TRIG_LEVEL_VALID(config->rxFifoTriggerLevel));
            base->unRX_FIFO_CTL.stcField.u7TRIGGER_LEVEL = config->rxFifoTriggerLevel;
        }
        
        ret = CY_I2S_SUCCESS;
    }

    return (ret);
}

/*******************************************************************************
* Function Name: Cy_I2S_DeInit
****************************************************************************//**
*
* Uninitializes the I2S module (reverts default register values).
*
* \param base The pointer to the I2S instance address.
*
* \funcusage
* \
*
*******************************************************************************/
void Cy_I2S_DeInit(volatile stc_TDM_TDM_STRUCT_t * base)
{
    Cy_I2S_Tx_DeInit(&(base->TDM_TX_STRUCT));
    Cy_I2S_Rx_DeInit(&(base->TDM_RX_STRUCT));
}

/*******************************************************************************
* Function Name: Cy_I2S_Tx_DeInit
****************************************************************************//**
*
* Uninitializes the I2S transmitter module (reverts default register values).
*
* \param base The pointer to the I2S->TX instance address.
*
* \funcusage
* \
*
*******************************************************************************/
void Cy_I2S_Tx_DeInit(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
    base->unINTR_TX_MASK.u32Register = 0UL;     /* Disable interrupts prior to stopping the operation */
    base->unTX_FIFO_CTL.u32Register = 0UL;
    base->unTX_IF_CTL.u32Register = CY_I2S_TX_IF_CTL_DEFAULT;
    base->unTX_CTL.u32Register = CY_I2S_TX_CTL_DEFAULT;
}

/*******************************************************************************
* Function Name: Cy_I2S_Rx_DeInit
****************************************************************************//**
*
* Uninitializes the I2S receiver module (reverts default register values).
*
* \param base The pointer to the I2S->RX instance address.
*
* \funcusage
* \
*
*******************************************************************************/
void Cy_I2S_Rx_DeInit(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    base->unINTR_RX_MASK.u32Register = 0UL;     /* Disable interrupts prior to stopping the operation */
    base->unRX_FIFO_CTL.u32Register = 0UL;
    base->unRX_IF_CTL.u32Register = CY_I2S_RX_IF_CTL_DEFAULT;
    base->unRX_CTL.u32Register = CY_I2S_RX_CTL_DEFAULT;
}


/*******************************************************************************
* Function Name: Cy_I2S_DeepSleepCallback
****************************************************************************//**
*
* This is a callback function to be used at the application layer to
* manage an I2S operation during the Deep-Sleep cycle. It stores the I2S state 
* (Tx/Rx enabled/disabled/paused) into the context structure and stops the 
* communication before entering into Deep-Sleep power mode and restores the I2S
* state after waking up.
*
* \param 
* callbackParams - The pointer to the callback parameters structure, 
* see \ref cy_stc_syspm_callback_params_t.
*
* \return the SysPm callback status \ref cy_en_syspm_status_t.
*
* \note Use the \ref cy_stc_i2s_context_t data type for definition of the 
* *context element of the \ref cy_stc_syspm_callback_params_t strusture.
*
* \funcusage
* \
*
*******************************************************************************/
cy_en_syspm_status_t Cy_I2S_DeepSleepCallback(cy_stc_syspm_callback_params_t * callbackParams)
{
    cy_en_syspm_status_t ret = CY_SYSPM_SUCCESS;
    CY_ASSERT_L1(NULL != callbackParams->context);

    stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * locTxBase = (stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t*) callbackParams->base;
    stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * locRxBase = (stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t*) callbackParams->base;

    uint32_t * locTxInterruptMask = (uint32_t*) &(((cy_stc_i2s_context_t*)(callbackParams->context))->interruptTxMask);
    uint32_t * locRxInterruptMask = (uint32_t*) &(((cy_stc_i2s_context_t*)(callbackParams->context))->interruptRxMask);
    uint32_t * locTxState = (uint32_t*) &(((cy_stc_i2s_context_t*)(callbackParams->context))->enableTxState);
    uint32_t * locRxState = (uint32_t*) &(((cy_stc_i2s_context_t*)(callbackParams->context))->enableRxState);
    
    switch(callbackParams->mode)
    {
        case CY_SYSPM_CHECK_READY:            
        case CY_SYSPM_CHECK_FAIL:
            break;
        
        case CY_SYSPM_BEFORE_ENTER:
            *locTxInterruptMask = Cy_I2S_GetTxInterruptMask(locTxBase); /* Store I2S interrupts */
            *locRxInterruptMask = Cy_I2S_GetRxInterruptMask(locRxBase); /* Store I2S interrupts */
            *locTxState = Cy_I2S_GetTxCurrentState(locTxBase);          /* Store I2S state */
            *locRxState = Cy_I2S_GetRxCurrentState(locRxBase);          /* Store I2S state */

            if (0UL != (*locTxState & TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_ACTIVE_Msk))
            {
                Cy_I2S_DisableTx(locTxBase);                            /* Stop TX operation */
            }
            if (0UL != (*locRxState & TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_ACTIVE_Msk))
            {
                Cy_I2S_DisableRx(locRxBase);                            /* Stop RX operation */
            }
            Cy_I2S_SetTxInterruptMask(locTxBase, 0UL);                  /* Disable I2S interrupts */
            Cy_I2S_SetRxInterruptMask(locRxBase, 0UL);                  /* Disable I2S interrupts */
            /* Unload FIFOs in order not to lose data (if needed) */
            break;
            
        case CY_SYSPM_AFTER_EXIT:
            if (0UL != (*locRxState & TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_ACTIVE_Msk))
            {
                Cy_I2S_EnableRx(locRxBase);                         /* Start RX operation */
            }
            if (0UL != (*locTxState & TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_ACTIVE_Msk))
            {
                Cy_I2S_WriteTxData(locTxBase, 0UL);                     /* Fill at least one TX frame */
                Cy_I2S_EnableTx(locTxBase);                             /* Start TX operation */
            }
            Cy_I2S_ClearTxInterrupt(locTxBase, *locTxInterruptMask);    /* Clear possible pending I2S interrupts */
            Cy_I2S_ClearRxInterrupt(locRxBase, *locRxInterruptMask);    /* Clear possible pending I2S interrupts */
            Cy_I2S_SetTxInterruptMask(locTxBase, *locTxInterruptMask);  /* Restore I2S interrupts */
            Cy_I2S_SetRxInterruptMask(locRxBase, *locRxInterruptMask);  /* Restore I2S interrupts */
            break;
        
        default:
            ret = CY_SYSPM_FAIL;
            break;
    }
        
    return(ret);
}


#ifdef __cplusplus
}
#endif

#endif /* CY_IP_MXTDM */

/* [] END OF FILE */
