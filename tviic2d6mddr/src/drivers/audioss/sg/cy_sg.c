/***************************************************************************//**
* \file cy_sg.c
* \version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
* The source code file for the SG driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2018, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_sg.h"

#ifdef CY_IP_MXSG

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
* Function Name: Cy_SG_Init
****************************************************************************//**
*
* Initializes the SG module in accordance with a configuration structure.
*
* \pre If the SG module is initialized previously, the \ref Cy_SG_DeInit()
* must be called before calling this function.
*
* \param base The pointer to the SG instance address.
*
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_sg_status_t.
*
* \funcusage
*
*******************************************************************************/
cy_en_sg_status_t    Cy_SG_Init(volatile stc_SG_SG_STRUCT_t * base, cy_stc_sg_config_t const * config)
{
    if(NULL == config)    /*  */
    {
        return CY_SG_BAD_PARAM;
    }
    if(base->unCTL.stcField.u1ENABLED == 1)     /* When the transmitter is enabled,the IF_CTL register should not be modified.  */
    {
        return CY_SG_BAD_STATUS;
    }
    if(CY_SG_CLOCK_VALID(config->clkSel) == false)     /*  */
    {
        return CY_SG_BAD_PARAM;
    }
    if(CY_SG_FORMAT_VALID(config->format) == false)     /*  */
    {
        return CY_SG_BAD_PARAM;
    }
    un_SG_SG_STRUCT_IF_CTL_t    temp_IF_CTL = {.u32Register = base->unIF_CTL.u32Register};

    /* The interface setting */
    temp_IF_CTL.stcField.u8CLOCK_DIV        = config->clkDiv;
    temp_IF_CTL.stcField.u3CLOCK_SEL        = config->clkSel;
    base->unIF_CTL.u32Register              = temp_IF_CTL.u32Register;
    
    un_SG_SG_STRUCT_CTL_t          temp_CTL = {.u32Register = base->unCTL.u32Register};
    
    /* The control setting */
    temp_CTL.stcField.u1FORMAT              = config->format;
    base->unCTL.u32Register                 = temp_CTL.u32Register;
    
    return (CY_SG_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_SG_DeInit
****************************************************************************//**
*
* Uninitializes the SG module (reverts default register values).
*
* \param base The pointer to the SG instance address.
* \
*
*******************************************************************************/
void Cy_SG_DeInit(volatile stc_SG_SG_STRUCT_t * base)
{
    base->unIF_CTL.u32Register          = CY_SG_IF_CTL_DEFAULT;
    base->unCTL.u32Register             = 0UL;
}

/*******************************************************************************
* Function Name: Cy_SG_StartSegment
****************************************************************************//**
*
* Start segment structure.
*
* \param base The pointer to the SG instance address.
*
* \param InputData
*
* \param Size
*
* \param context
*
* \funcusage
*
*******************************************************************************/
cy_en_sg_status_t    Cy_SG_StartSegment(volatile stc_SG_SG_STRUCT_t * base, cy_stc_sg_segment_t * InputData, uint32_t Size, cy_sg_segment_t * context)
{
    if (Size == 0UL)    /* No segment. */
    {
        return CY_SG_BAD_PARAM;
    }
    if (InputData == NULL)    /* No data is inputted. */
    {
        return CY_SG_BAD_PARAM;
    }
    context->size = Size;                /* Position of the current pointer equals to the segment size. */
    context->topSegment = InputData;
    
    if (Size == 1UL)    /*First segment structure is inputted. */
    {
        base->unTIME_CTL.stcField.u8PERIOD8     = InputData[0].timePeriod;
        base->unTIME_CTL.stcField.u8NR          = InputData[0].timeNR;
        base->unTONE_CTL.stcField.u8PERIOD8     = InputData[0].tonePeriod;
        base->unTONE_CTL.stcField.u8HIGH8       = InputData[0].toneHigh;
        base->unAMPL_CTL.stcField.u16PERIOD16   = InputData[0].amplPeriod;
        base->unAMPL_CTL.stcField.u16HIGH16     = InputData[0].amplHigh;
        base->unSTEP_CTL.stcField.u16STEP       = InputData[0].stepSize;
        base->unSTEP_CTL.stcField.u1VALID       = InputData[0].stepValid;
        
        context->currentPosition = 1UL;
        
        base->unCTL.stcField.u1ACTIVE = 1u;    /* Start sound generation process. */
    }
    else if (Size >= 2UL)   /*First segment structure is inputted along with the next segment structure. */
    {
        base->unTIME_CTL.stcField.u8PERIOD8     = InputData[0].timePeriod;
        base->unTIME_CTL.stcField.u8NR          = InputData[0].timeNR;
        base->unTONE_CTL.stcField.u8PERIOD8     = InputData[0].tonePeriod;
        base->unTONE_CTL.stcField.u8HIGH8       = InputData[0].toneHigh;
        base->unAMPL_CTL.stcField.u16PERIOD16   = InputData[0].amplPeriod;
        base->unAMPL_CTL.stcField.u16HIGH16     = InputData[0].amplHigh;
        base->unSTEP_CTL.stcField.u16STEP       = InputData[0].stepSize;
        base->unSTEP_CTL.stcField.u1VALID       = InputData[0].stepValid;
        
        base->unTIME_CTL_BUFF.stcField.u8PERIOD8     = InputData[1].timePeriod;
        base->unTIME_CTL_BUFF.stcField.u8NR          = InputData[1].timeNR;
        base->unTONE_CTL_BUFF.stcField.u8PERIOD8     = InputData[1].tonePeriod;
        base->unTONE_CTL_BUFF.stcField.u8HIGH8       = InputData[1].toneHigh;
        base->unAMPL_CTL_BUFF.stcField.u16PERIOD16   = InputData[1].amplPeriod;
        base->unAMPL_CTL_BUFF.stcField.u16HIGH16     = InputData[1].amplHigh;
        base->unSTEP_CTL_BUFF.stcField.u16STEP       = InputData[1].stepSize;
        base->unSTEP_CTL_BUFF.stcField.u1VALID       = InputData[1].stepValid;
        
        context->currentPosition = 2UL;
        
        base->unCTL.stcField.u1ACTIVE = 1u;    /* Start sound generation process. */
    }
    return (CY_SG_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_SG_PushSegment
****************************************************************************//**
*
* Push next segment to buffer register.
*
* \param base The pointer to the SG instance address.
*
* \param InputData
*
* \param context
*
* \return None.
*
*******************************************************************************/
uint32_t    Cy_SG_PushSegment(volatile stc_SG_SG_STRUCT_t * base, cy_stc_sg_segment_t * InputData, cy_sg_segment_t * context)
{
    if (context->finishFlag == true)    /* All data is sent. */
    {
        base->unCTL.stcField.u1ACTIVE = 0u;  /* Stop sound generation process. */
        return 1;
    }
    if (context->size > context->currentPosition)   /* Push next segment. */
    {
        base->unTIME_CTL_BUFF.stcField.u8PERIOD8     = InputData[context->currentPosition].timePeriod; 
        base->unTIME_CTL_BUFF.stcField.u8NR          = InputData[context->currentPosition].timeNR;
        base->unTONE_CTL_BUFF.stcField.u8PERIOD8     = InputData[context->currentPosition].tonePeriod;
        base->unTONE_CTL_BUFF.stcField.u8HIGH8       = InputData[context->currentPosition].toneHigh;
        base->unAMPL_CTL_BUFF.stcField.u16PERIOD16   = InputData[context->currentPosition].amplPeriod;
        base->unAMPL_CTL_BUFF.stcField.u16HIGH16     = InputData[context->currentPosition].amplHigh;
        base->unSTEP_CTL_BUFF.stcField.u16STEP       = InputData[context->currentPosition].stepSize;
        base->unSTEP_CTL_BUFF.stcField.u1VALID       = InputData[context->currentPosition].stepValid;
        
        context->currentPosition += 1;
    }
    else if (context->size == context->currentPosition)   /* All data is sent. */
    {
        context->finishFlag = true;
    }
    else if (context->size < context->currentPosition)
    {
        CY_ASSERT_L2(false);    /* Should not reach here. */
    }
    return 0;
}



#ifdef __cplusplus
}
#endif

#endif /* CY_IP_MXPWM */

/* [] END OF FILE */
