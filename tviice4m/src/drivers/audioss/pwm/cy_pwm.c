/***************************************************************************//**
* \file cy_pwm.c
* \version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
* The source code file for the PWM driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2018, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_pwm.h"

#ifdef CY_IP_MXPWM

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
* Function Name: Cy_Pwm_Tx_Init
****************************************************************************//**
*
* Initializes the PWM generator in accordance with a configuration structure.
*
* \pre If the PWM TX module is initialized previously, the \ref Cy_PWM_Tx_DeInit()
* must be called before calling this function.
*
* \param base The pointer to the PWM->TX instance address.
*
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_pwm_tx_status_t.
*
* \funcusage
*
*******************************************************************************/
cy_en_pwm_tx_status_t Cy_Pwm_Tx_Init(volatile stc_PWM_TX_t * base, cy_stc_pwm_tx_config_t const * config)
{
    cy_en_pwm_tx_status_t ret = CY_PWM_BAD_PARAM;

    un_PWM_TX_IF_CTL_t      temp_IF_CTL = {0};
    un_PWM_TX_CTL_t         temp_TX_CTL = {0};
    un_PWM_TX_GAIN_CTL_t    temp_GAIN_CTL = {0};
    un_PWM_TX_PWM_CTL0_t    temp_PWM_CTL0 = {0};
    un_PWM_TX_PWM_CTL1_t    temp_PWM_CTL1 = {0};
    un_PWM_TX_PWM_CTL2_t    temp_PWM_CTL2 = {0};
    un_PWM_TX_PWM_CTL3_t    temp_PWM_CTL3 = {0};
    un_PWM_TX_DOUBLE_CTL_t  temp_DOUBLE_CTL = {0};

    if((NULL != base) && (NULL != config))
    {
        /* The Tx control setting */
        if (config->txEnabled)
        {
            CY_ASSERT_L3(CY_PWM_IS_WORD_LEN_VALID(config->txWordSize));         /* Validation for the PWM word size. */
            temp_TX_CTL.stcField.u1ENABLED      = config->txEnabled;
            temp_TX_CTL.stcField.u4WORD_SIZE    = config->txWordSize;
            base->unCTL.u32Register             = temp_TX_CTL.u32Register;
            
            /* The TX interface setting */
            CY_ASSERT_L2(CY_PWM_IS_CLOCK_VALID(config->txClkSel));                  /* Validation for the clock selection value. */
            CY_ASSERT_L2(CY_PWM_IS_TX_LINE_POL_VALID(config->txLineOutPolarity));   /* Validation for the PWM line out polarity. */
            temp_IF_CTL.stcField.u8CLOCK_DIV        = config->txClkDiv;             
            temp_IF_CTL.stcField.u4LINE_POLARITY    = config->txLineOutPolarity;
            temp_IF_CTL.stcField.u3CLOCK_SEL        = config->txClkSel;
            base->unIF_CTL.u32Register              = temp_IF_CTL.u32Register;

            CY_ASSERT_L3(CY_PWM_IS_GAIN_CODE_VALID(config->txGainCode));        /* Validation for the PWM wave gain control value. */
            temp_GAIN_CTL.stcField.u7CODE       = config->txGainCode;
            base->unGAIN_CTL.u32Register        = temp_GAIN_CTL.u32Register;

            CY_ASSERT_L3(CY_PWM_IS_FORMAT_VALID(config->txFormat));             /* Validation for the PWM configuration and format. */
            CY_ASSERT_L3(CY_PWM_IS_GAIN_SCALE_VALID(config->txGainScale));      /* Validation for the PWM wave gain correction scale. */
            temp_PWM_CTL0.stcField.u4SCALE      = config->txGainScale;
            temp_PWM_CTL0.stcField.u2FORMAT     = config->txFormat;
            base->unPWM_CTL0.u32Register        = temp_PWM_CTL0.u32Register;

            temp_PWM_CTL1.stcField.u16MIN       = config->pwmMinValue;
            temp_PWM_CTL1.stcField.u16MAX       = config->pwmMaxValue;
            base->unPWM_CTL1.u32Register        = temp_PWM_CTL1.u32Register;            

            CY_ASSERT_L3(CY_PWM_IS_PERIOD_VALID(config->pwmPeriod, config->pwmOffset)); /* Validation for the PWM period and offset. */
            temp_PWM_CTL2.stcField.u16PERIOD    = config->pwmPeriod;
            temp_PWM_CTL2.stcField.u16OFFSET    = config->pwmOffset;
            base->unPWM_CTL2.u32Register        = temp_PWM_CTL2.u32Register;

            temp_PWM_CTL3.stcField.u16DT        = config->pwmDeadTime;
            base->unPWM_CTL3.u32Register        = temp_PWM_CTL3.u32Register;

            /* Settings for the PWM wave doubler. */
            if(config->txDoublerEnabled)
            {
                CY_ASSERT_L3(CY_PWM_IS_DOUBLE_MODE_VALID(config->txDoublerMode));       /* Validation for the PWM mode value. */
                temp_DOUBLE_CTL.stcField.u1MODE     = config->txDoublerMode;
                temp_DOUBLE_CTL.stcField.u1ENABLED  = config->txDoublerEnabled;
                base->unDOUBLE_CTL.u32Register      = temp_DOUBLE_CTL.u32Register;
            }

            /* PSVP workaround -- Need some clarification */
            base->unTX_FIFO_CTL.stcField.u6TRIGGER_LEVEL = config->txFifoTriggerLevel;  /* Settings for PWM transmit FIFO and trigger. */

            ret = CY_PWM_SUCCESS;
        }
    }

    return (ret);
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_DeInit
****************************************************************************//**
*
* Uninitializes the PWM generator module (reverts default register values).
*
* \param base The pointer to the PWM->TX instance address.
*
* \funcusage
* \
*
*******************************************************************************/
void Cy_Pwm_Tx_DeInit(volatile stc_PWM_TX_t * base)
{
    base->unTX_FIFO_CTL.u32Register     = 0UL;                          /* Disable interrupts prior to stopping the operation */
    base->unCTL.u32Register             = 0UL;
    base->unIF_CTL.u32Register          = CY_PWM_TX_IF_CTL_DEFAULT;
    Cy_Pwm_Tx_Disable(base);
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_Enable
****************************************************************************//**
*
* Starts an PWM generation. Interrupts enabling (by the 
* \ref Cy_PWM_Tx_SetTxInterruptMask) is required after this function call, in case
* if any PWM_Tx interrupts are used in the application.
*
* \pre Cy_PWM_Tx_Init() must be called before.
*
* \param base The pointer to the PWM->TX instance address.
*
* \funcusage
* \
*
*******************************************************************************/
cy_en_pwm_tx_status_t Cy_Pwm_Tx_Enable(volatile stc_PWM_TX_t * base)
{
    uint8_t txChannelBitMask = 0;
    cy_en_pwm_tx_status_t ret = CY_PWM_BAD_PARAM;
    
    if(base->unCTL.stcField.u1ENABLED)                                          /* Check if the PWM macro is enabled. */
    {
        if(base == PWM0_TX0)
        {
            txChannelBitMask = (1 << 0);                                        /* Bit mask for PWM_TX0 in PWM_CTL registor. */
        }
        else if(base == PWM0_TX1)
        {
            txChannelBitMask = (1 << 1);                                        /* Bit mask for PWM_TX1 in PWM_CTL registor. */
        }
        PWM0->unCTL.stcField.u8ACTIVE    |= txChannelBitMask;                   /* Enable the PWM transmitter. */
        ret = CY_PWM_SUCCESS;
    }
    return ret;
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_Disable
****************************************************************************//**
*
* Stops an PWM generation. 
*
* \pre TX interrupts disabling (by the \ref Cy_PWM_Tx_SetInterruptMask) is required
* prior to this function call, in case if any TX interrupts are used.
*
* \param base The pointer to the PWM->Tx instance address.
*
* \funcusage
* \
*
*******************************************************************************/
void Cy_Pwm_Tx_Disable(volatile stc_PWM_TX_t * base)
{
    uint8_t txChannelBitMask = 0;

    if(base == PWM0_TX0)
    {
        txChannelBitMask = (1 << 0);                                    /* Get the PWM_TX0 mask. */
    }
    else if(base == PWM0_TX1)
    {
        txChannelBitMask = (1 << 1);                                    /* Get the PWM_TX1 mask. */
    }
    PWM0->unCTL.stcField.u8ACTIVE    &= ~txChannelBitMask;              /* Disable the PWM transmitter. */
}

/*******************************************************************************
* Function Name: Cy_Pwm_DeepSleepCallback
****************************************************************************//**
*
* This is a callback function to be used at the application layer to manage an 
* PWM operation during the Deep-Sleep cycle. It stores the PWM state (Tx/Rx 
* enabled/disabled) into the context structure and stops the communication before 
* entering into Deep-Sleep power mode and restores the PWM state after waking up.
*
* \param 
* callbackParams - The pointer to the callback parameters structure, 
* see \ref cy_stc_syspm_callback_params_t.
*
* \return the SysPm callback status \ref cy_en_syspm_status_t.
*
* \note Use the \ref cy_stc_pwm_tx_context_t data type for definition of the 
* *context element of the \ref cy_stc_syspm_callback_params_t strusture.
*
* \funcusage
* \
*
*******************************************************************************/
cy_en_syspm_status_t Cy_Pwm_Tx_DeepSleepCallback(cy_stc_syspm_callback_params_t * callbackParams)
{
    cy_en_syspm_status_t ret = CY_SYSPM_SUCCESS;
    CY_ASSERT_L1(NULL != callbackParams->context);

    stc_PWM_TX_t * locTxBase = (stc_PWM_TX_t *) callbackParams->base;

    uint32_t * locTxInterruptMask = (uint32_t*) &(((cy_stc_pwm_tx_context_t*)(callbackParams->context))->interruptTxMask);
    uint32_t * locTxState = (uint32_t*) &(((cy_stc_pwm_tx_context_t*)(callbackParams->context))->enableTxState);
    
    switch(callbackParams->mode)
    {
        case CY_SYSPM_CHECK_READY:            
        case CY_SYSPM_CHECK_FAIL:
            break;
        
        case CY_SYSPM_BEFORE_ENTER:
            *locTxInterruptMask = Cy_Pwm_Tx_GetInterruptMask(locTxBase); /* Store PWM interrupts */
            *locTxState = Cy_Pwm_Tx_GetCurrentState(locTxBase);          /* Store PWM state */

            if (0UL != (*locTxState & PWM_CTL_ACTIVE_Msk))
            {
                Cy_Pwm_Tx_Disable(locTxBase);                            /* Stop TX operation */
            }
            Cy_Pwm_Tx_SetInterruptMask(locTxBase, 0UL);                  /* Disable PWM interrupts */
            /* Unload FIFOs in order not to lose data (if needed) */
            break;
            
        case CY_SYSPM_AFTER_EXIT:
            if (0UL != (*locTxState & PWM_CTL_ACTIVE_Msk))
            {
                Cy_Pwm_Tx_WriteData(locTxBase, 0UL);                     /* Fill at least one TX frame */
                Cy_Pwm_Tx_Enable(locTxBase);                             /* Start TX operation */
            }
            Cy_Pwm_Tx_ClearInterrupt(locTxBase, *locTxInterruptMask);    /* Clear possible pending PWM interrupts */
            Cy_Pwm_Tx_SetInterruptMask(locTxBase, *locTxInterruptMask);  /* Restore PWM interrupts */
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

#endif /* CY_IP_MXPWM */

/* [] END OF FILE */
