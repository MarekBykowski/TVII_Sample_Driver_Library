/***************************************************************************//**
* \file cy_axidma.c
* \version 1.0
*
* \brief
* The AXI-DMA driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_axidma.h"

#if defined(__cplusplus)
extern "C" {
#endif


/*******************************************************************************
* Function Name: Cy_AXIDMA_Enable
****************************************************************************//**
*
* This function enables the AXI-DMA block.
*
* \param ptscMDMA
* Pointer to the hardware AXI-DMA block.
*
*******************************************************************************/
void Cy_AXIDMA_Enable(volatile stc_AXI_DMAC_t* pstcAXIDMA)
{
    pstcAXIDMA->unCTL.stcField.u1ENABLED = 1;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Disable
****************************************************************************//**
*
* This function disables the AXI-DMA block.
*
* \param ptscMDMA
* Pointer to the hardware AXI-DMA block.
*
*******************************************************************************/
void Cy_AXIDMA_Disable(volatile stc_AXI_DMAC_t* pstcAXIDMA)
{
    pstcAXIDMA->unCTL.stcField.u1ENABLED = 0;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_GetActiveSecChnl
****************************************************************************//**
*
* This function used to determine the channels that are active/pending in
* the AXI-DMA block and are configured as secure.
*
* \param ptscMDMA
* Pointer to the hardware AXI-DMA block.
*
* \return
* Returns a bit-field with all of the currently active/pending secure channels
* in the AXI-DMA block.
*
*******************************************************************************/
uint32_t Cy_AXIDMA_GetActiveSecChnl(const volatile stc_AXI_DMAC_t* pstcAXIDMA)
{
    return pstcAXIDMA->unACTIVE_SEC.u32Register;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_GetActiveNonSecChnl
****************************************************************************//**
*
* This function used to determine the channels that are active/pending in
* the AXI-DMA block and are configured as non-secure.
*
* \param ptscMDMA
* Pointer to the hardware AXI-DMA block.
*
* \return
* Returns a bit-field with all of the currently active/pending non-secure channels
* in the AXI-DMA block.
*
*******************************************************************************/
uint32_t Cy_AXIDMA_GetActiveNonSecChnl(const volatile stc_AXI_DMAC_t* pstcAXIDMA)
{
    return pstcAXIDMA->unACTIVE_NONSEC.u32Register;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Descr_Init
****************************************************************************//**
*
* This function initializes descriptor structure in SRAM from a pre-initialized
* configuration structure.
* This function initializes only the descriptor and not the channel.
* This function will operate on the descriptor only if it was defined as a RAM
* variable.
* If the descriptor is defined in Flash, then the user must use the
* configuration defines to initialize it.
*
* \param descriptor
* This is an instance of the descriptor structure declared by the user and
* initialized by this function.
*
* \param config
* This is a configuration structure that has all initialization information for
* the descriptor.
*
* \return
* This function returns /ref cy_en_axidma_status_t.
*
*******************************************************************************/
cy_en_axidma_status_t Cy_AXIDMA_Descr_Init(void* descriptor, const cy_stc_axidma_descr_config_t* config)
{
    cy_en_axidma_status_t retVal = CY_AXIDMA_ERR_UNC;    

    // Check NULL pointers and 64-bit alignment of descriptor
    if ((descriptor != NULL) && (config != NULL) && (((uint32_t)descriptor & 0x7) == 0))
    {
        cy_stc_axidma_1d_memcopy_descr_t* descMemcopy1D = (cy_stc_axidma_1d_memcopy_descr_t*) descriptor;
        cy_stc_axidma_2d_memcopy_descr_t* descMemcopy2D = (cy_stc_axidma_2d_memcopy_descr_t*) descriptor;
        cy_stc_axidma_3d_memcopy_descr_t* descMemcopy3D = (cy_stc_axidma_3d_memcopy_descr_t*) descriptor;
        
        /* use "1D memcpy" descriptor type for initialization of items with common offset */
        
        /* Descriptor[0] */
        descMemcopy1D->unAXIDMA_DESCR_CTL.stcField.u2WAIT_FOR_DEACT = config->deact;
        descMemcopy1D->unAXIDMA_DESCR_CTL.stcField.u2INTR_TYPE      = config->intrType;
        descMemcopy1D->unAXIDMA_DESCR_CTL.stcField.u2TR_OUT_TYPE    = config->trigoutType;
        descMemcopy1D->unAXIDMA_DESCR_CTL.stcField.u2TR_IN_TYPE     = config->triginType;
        descMemcopy1D->unAXIDMA_DESCR_CTL.stcField.u1DATA_PREFETCH  = (config->dataPrefetch     == false) ? 0 : 1;
        descMemcopy1D->unAXIDMA_DESCR_CTL.stcField.u1CH_DISABLE     = (config->disableChAtCmplt == false) ? 0 : 1;
        descMemcopy1D->unAXIDMA_DESCR_CTL.stcField.u2DESCR_TYPE     = config->descrType;

        /* Descriptor[1] */
        descMemcopy1D->u32AXIDMA_DESCR_SRC                          = (uint32_t)config->srcAddr;
        
        /* Descriptor[2] */
        descMemcopy1D->u32AXIDMA_DESCR_DST                          = (uint32_t)config->dstAddr;
        
        /* Descriptor[3]  */
        descMemcopy1D->unAXIDMA_DESCR_M_SIZE.u32Register            = (uint32_t)((config->mCount) - 1u);

        /* after 4th word of descripter depends on descripter type */

        switch(config->descrType)
        {
            case CY_AXIDMA_1D_MEMCOPY_TRANSFER:
            {
                /* Descriptor[4] */
                descMemcopy1D->u32AXIDMA_DESCR_NEXT_PTR  = (uint32_t)config->descrNext;
                break;
            }
            case CY_AXIDMA_2D_MEMCOPY_TRANSFER:
            {
                /* Descriptor[4] */
                descMemcopy2D->unAXIDMA_DESCR_X_SIZE.stcField.u16X_COUNT = (uint32_t)((config->xCount) - 1u);

                /* Descriptor[5] */
                descMemcopy2D->unAXIDMA_DESCR_X_INCR.stcField.u16SRC_X   = (uint32_t)config->srcXincr;
                descMemcopy2D->unAXIDMA_DESCR_X_INCR.stcField.u16DST_X   = (uint32_t)config->dstXincr;

                /* Descriptor[6] */
                descMemcopy2D->u32AXIDMA_DESCR_NEXT_PTR                  = (uint32_t)config->descrNext;
                break;
            }
            case CY_AXIDMA_3D_MEMCOPY_TRANSFER:
            {
                /* Descriptor[4] */
                descMemcopy3D->u32AXIDMA_DESCR_DST                       = (uint32_t)config->dstAddr;

                /* Descriptor[5] */
                descMemcopy3D->unAXIDMA_DESCR_X_SIZE.stcField.u16X_COUNT = (uint32_t)((config->xCount) - 1u);

                /* Descriptor[6] */
                descMemcopy3D->unAXIDMA_DESCR_X_INCR.stcField.u16SRC_X   = (uint32_t)config->srcXincr;
                descMemcopy3D->unAXIDMA_DESCR_X_INCR.stcField.u16DST_X   = (uint32_t)config->dstXincr;

                /* Descriptor[7] */
                descMemcopy3D->unAXIDMA_DESCR_Y_SIZE.stcField.u16Y_COUNT = (uint32_t)((config->yCount) - 1u);

                /* Descriptor[8] */
                descMemcopy3D->unAXIDMA_DESCR_Y_INCR.stcField.u16SRC_Y   = (uint32_t)config->srcYincr;
                descMemcopy3D->unAXIDMA_DESCR_Y_INCR.stcField.u16DST_Y   = (uint32_t)config->dstYincr;

                /* Descriptor[7] */
                descMemcopy3D->u32AXIDMA_DESCR_NEXT_PTR                  = (uint32_t)config->descrNext;
                break;
            }
            default:
            {
                /* Unsupported type of descriptor */
                break;
            }
        }

        retVal = CY_AXIDMA_SUCCESS;
    }
    else
    {
        retVal = CY_AXIDMA_INVALID_INPUT_PARAMETERS;
    }

    return retVal;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Descr_DeInit
****************************************************************************//**
*
* This function clears all the content of the descriptor structure.
* This function will operate in the descriptor only if it was defined as a RAM
* variable.
* If the descriptor is being defined in Flash, then the user can't use this
* function to deinitialize it.
*
* \param descriptor
* This is an instance of the descriptor structure to be cleared.
*
*******************************************************************************/
void Cy_AXIDMA_Descr_DeInit(void* descriptor)
{
    cy_stc_axidma_1d_memcopy_descr_t* descMemcopy1D = (cy_stc_axidma_1d_memcopy_descr_t*) descriptor;
    cy_stc_axidma_2d_memcopy_descr_t* descMemcopy2D = (cy_stc_axidma_2d_memcopy_descr_t*) descriptor;
    cy_stc_axidma_3d_memcopy_descr_t* descMemcopy3D = (cy_stc_axidma_3d_memcopy_descr_t*) descriptor;        
        
    // Use generic 1D MemCopy descriptor to get actual descriptor type
    switch(descMemcopy1D->unAXIDMA_DESCR_CTL.stcField.u2DESCR_TYPE)
    {
        case CY_AXIDMA_1D_MEMCOPY_TRANSFER:
        {
            *descMemcopy1D = (cy_stc_axidma_1d_memcopy_descr_t){ 0 };
            break;
        }
        case CY_AXIDMA_2D_MEMCOPY_TRANSFER:
        {
            *descMemcopy2D = (cy_stc_axidma_2d_memcopy_descr_t){ 0 };
            break;
        }
        case CY_AXIDMA_3D_MEMCOPY_TRANSFER:
        {
            *descMemcopy3D = (cy_stc_axidma_3d_memcopy_descr_t){ 0 };
            break;
        }
        default:
        {
            /* Unsupported type of descriptor */
            break;
        }
    }
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Descr_SetNxtDescr
****************************************************************************//**
*
* Sets a next descriptor parameter for the descriptor structure.
* This function will operate in the descriptor only if it was defined as a RAM
* variable.
* If the descriptor is defined in Flash, then the user must use the
* configuration defines to initialize it.
* Based on descriptor type the offset of address for the next descriptor may
* vary. 
*
* \param descriptor
* This is the descriptor-structure instance declared by the user. The function
* modifies the next descriptor address parameter in this descriptor.
*
* \param nxtDescriptor
* The pointer to the next descriptor.
*
*******************************************************************************/
void Cy_AXIDMA_Descr_SetNxtDescr(void* descriptor, const void* nxtDescriptor)
{
    cy_stc_axidma_1d_memcopy_descr_t* descMemcopy1D = (cy_stc_axidma_1d_memcopy_descr_t*) descriptor;
    cy_stc_axidma_2d_memcopy_descr_t* descMemcopy2D = (cy_stc_axidma_2d_memcopy_descr_t*) descriptor;
    cy_stc_axidma_3d_memcopy_descr_t* descMemcopy3D = (cy_stc_axidma_3d_memcopy_descr_t*) descriptor;        
    
    // Use generic 1D MemCopy descriptor to get actual descriptor type
    switch(descMemcopy1D->unAXIDMA_DESCR_CTL.stcField.u2DESCR_TYPE)
    {
        case CY_AXIDMA_1D_MEMCOPY_TRANSFER:
        {
            /* Descriptor[4] */
            descMemcopy1D->u32AXIDMA_DESCR_NEXT_PTR = (uint32_t)nxtDescriptor;
            break;
        }
        case CY_AXIDMA_2D_MEMCOPY_TRANSFER:
        {
            /* Descriptor[6] */
            descMemcopy2D->u32AXIDMA_DESCR_NEXT_PTR = (uint32_t)nxtDescriptor;
            break;
        }
        case CY_AXIDMA_3D_MEMCOPY_TRANSFER:
        {
            /* Descriptor[8] */
            descMemcopy3D->u32AXIDMA_DESCR_NEXT_PTR = (uint32_t)nxtDescriptor;
            break;
        }
        default:
        {
            /* Unsupported type of descriptor */
            break;
        }
    }

}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Descr_SetSrcAddr
****************************************************************************//**
*
* \brief Sets the source address parameter for the descriptor structure.
*
* This function will operate on the descriptor only if it was defined as a RAM
* variable.
* If the descriptor is being defined in Flash, then the user has to use the
* configuration defines to initialize it.
*
* \param descriptor
* This is a descriptor-structure instance declared by the user. The function
* modifies the source-address parameter in this descriptor.
*
* \param srcAddr
* The source address value for the descriptor.
*
*******************************************************************************/
void Cy_AXIDMA_Descr_SetSrcAddr(void* descriptor, const void* srcAddr)
{
    // Item offset is identical in all descriptor types so we can just use "1D MemCopy" type
    ((cy_stc_axidma_1d_memcopy_descr_t*)descriptor)->u32AXIDMA_DESCR_SRC = (uint32_t)srcAddr;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Descr_SetDstAddr
****************************************************************************//**
*
* \brief Sets the destination address parameter for the descriptor structure.
*
* This function will operate in the descriptor only if it was defined as a RAM
* variable.
* If the descriptor is being defined in Flash, then the user has to use the
* configuration defines to initialize it.
*
* \param descriptor
* This is a descriptor-structure instance declared by the user. The function
* modifies the destination-address parameter in this descriptor.
*
* \param dstAddr
* The destination address value for the descriptor.
*
*******************************************************************************/
void Cy_AXIDMA_Descr_SetDstAddr(void* descriptor, const void* dstAddr)
{
    // Item offset is identical in all descriptor types so we can just use "1D MemCopy" type
    ((cy_stc_axidma_1d_memcopy_descr_t*)descriptor)->u32AXIDMA_DESCR_DST = (uint32_t)dstAddr;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Descr_SetIntrType
****************************************************************************//**
*
* Sets the interrupt type parameter for the descriptor structure.
* This function will operate in the descriptor only if it was defined as a RAM
* variable.
* If the descriptor is being defined in Flash, then the user has to use the
* configuration defines to initialize it.
*
* \param descriptor
* This is the descriptor-structure instance declared by the user. This is the
* descriptor being modified.
*
* \param interruptType
* The interrupt type set for the descriptor.. \ref cy_en_axidma_inttype_t
*
*******************************************************************************/
void Cy_AXIDMA_Descr_SetIntrType(void* descriptor, cy_en_axidma_inttype_t interruptType)
{
    // Item offset is identical in all descriptor types so we can just use "1D MemCopy" type
    ((cy_stc_axidma_1d_memcopy_descr_t*)descriptor)->unAXIDMA_DESCR_CTL.stcField.u2INTR_TYPE = interruptType;       
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Descr_SetTrigInType
****************************************************************************//**
*
* Sets the trigger-in-type parameter for the descriptor structure.
* This function will operate in the descriptor only if it was defined as a RAM
* variable.
* If the descriptor is being defined in Flash, then the user has to use the
* configuration defines to initialize it.
*
* \param descriptor
* This is a descriptor structure instance declared by the user. This is the
* descriptor being modified.
*
* \param trigInType
* The trigger-in-type set for the descriptor. \ref cy_en_axidma_trigintype_t
*
*******************************************************************************/
void Cy_AXIDMA_Descr_SetTrigInType(void* descriptor, cy_en_axidma_trigintype_t trigInType)
{
    // Item offset is identical in all descriptor types so we can just use "1D MemCopy" type
    ((cy_stc_axidma_1d_memcopy_descr_t*)descriptor)->unAXIDMA_DESCR_CTL.stcField.u2TR_IN_TYPE = trigInType;       
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Descr_SetTrigOutType
****************************************************************************//**
*
* This function sets the trigger-out-type parameter for for the descriptor
* structure.
* This function will operate in the descriptor only if it was defined as a RAM
* variable.
* If the descriptor is being defined in Flash, then the user has to use the
* configuration defines to initialize it.
*
* \param descriptor
* This is a descriptor-structure instance declared by the user. This is the
* descriptor being modified.
*
* \param trigOutType
* The trigger-out-type set for the descriptor. \ref cy_en_axidma_trigouttype_t
*
*******************************************************************************/
void Cy_AXIDMA_Descr_SetTrigOutType(void* descriptor, cy_en_axidma_trigouttype_t trigOutType)
{
    // Item offset is identical in all descriptor types so we can just use "1D MemCopy" type
    ((cy_stc_axidma_1d_memcopy_descr_t*)descriptor)->unAXIDMA_DESCR_CTL.stcField.u2TR_OUT_TYPE = trigOutType;       
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_Init
****************************************************************************//**
*
* Initializes the AXI-DMA channel with a descriptor and other parameters.
*
* \param ptscMDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
* \param chnlConfig
* This parameter is a structure that has the initialization information for the
* channel.
*
* \return
* This function returns /ref cy_en_axidma_status_t.
*
*******************************************************************************/
cy_en_axidma_status_t Cy_AXIDMA_Chnl_Init(volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum, const cy_stc_axidma_chnl_config_t* chnlConfig)
{
    cy_en_axidma_status_t retVal = CY_AXIDMA_ERR_UNC;

    if ((pstcAXIDMA != NULL) && (chnlConfig != NULL) && (chNum < AXI_DMAC_CH_NR))
    {
        pstcAXIDMA->CH[chNum].unCURR.u32Register       = (uint32_t)chnlConfig->AXIDMA_Descriptor;
        pstcAXIDMA->CH[chNum].unCTL.stcField.u2PRIO    = chnlConfig->priority;
        pstcAXIDMA->CH[chNum].unCTL.stcField.u1ENABLED = chnlConfig->enable;
        retVal = CY_AXIDMA_SUCCESS;
    }
    else
    {
        retVal = CY_AXIDMA_INVALID_INPUT_PARAMETERS;
    }

    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_DeInit
****************************************************************************//**
*
* Clears all the content of registers corresponding to the channel.
*
* \param ptscMDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
*******************************************************************************/
void Cy_AXIDMA_Chnl_DeInit(volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum)
{
    pstcAXIDMA->CH[chNum].unCTL.u32Register       = 0u;
    pstcAXIDMA->CH[chNum].unSRC.u32Register       = 0u;
    pstcAXIDMA->CH[chNum].unDST.u32Register       = 0u;
    pstcAXIDMA->CH[chNum].unCURR.u32Register      = 0u;
    pstcAXIDMA->CH[chNum].unINTR_MASK.u32Register = 0u;
    pstcAXIDMA->CH[chNum].unINTR.u32Register      = 0xffffffffu;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_Enable
****************************************************************************//**
*
* The function is used to enable an AXI-DMA channel.
*
* \param pstcAXIDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
*******************************************************************************/
void Cy_AXIDMA_Chnl_Enable(volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum)
{
    pstcAXIDMA->CH[chNum].unCTL.stcField.u1ENABLED = 1;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_Disable
****************************************************************************//**
*
* The function is used to disable an AXI-DMA channel.
*
* \param pstcAXIDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
*******************************************************************************/
void Cy_AXIDMA_Chnl_Disable(volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum)
{
    pstcAXIDMA->CH[chNum].unCTL.stcField.u1ENABLED = 0;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_SetDescr
****************************************************************************//**
*
* \brief Sets a descriptor as current for specified AXI-DMA channel.
*
* \param pstcAXIDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
* \param descriptor
* This is the descriptor which will be associated with the channel.
*
*******************************************************************************/
void Cy_AXIDMA_Chnl_SetDescr(volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum, const void* descriptor)
{
    pstcAXIDMA->CH[chNum].unCURR.u32Register = (uint32_t)descriptor;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_GetCurrentDescr
****************************************************************************//**
*
* This function returns the descriptor that is active in the channel.
*
* \param pstcAXIDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
* \return
* The pointer to the descriptor associated with the channel.
*
*******************************************************************************/
void* Cy_AXIDMA_Chnl_GetCurrentDescr(const volatile stc_AXI_DMAC_t *pstcAXIDMA, uint8_t chNum)
{
    return (void*) pstcAXIDMA->CH[chNum].unCURR.u32Register;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_SetPriority
****************************************************************************//**
*
* The function is used to set a priority for the AXI-DMA channel.
*
* \param pstcAXIDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
* \param priority
* The priority to be set for the AXI-DMA channel. The allowed values are 0,1,2,3.
* (0 has highest priority)
*
*******************************************************************************/
void Cy_AXIDMA_Chnl_SetPriority(volatile stc_AXI_DMAC_t *pstcAXIDMA, uint8_t chNum, uint8_t priority)
{
    pstcAXIDMA->CH[chNum].unCTL.stcField.u2PRIO = priority;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_GetPriority
****************************************************************************//**
*
* Returns the priority of AXI-DMA channel.
*
* \param pstcAXIDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
* \return
* The priority of the channel.
*
*******************************************************************************/
uint8_t Cy_AXIDMA_Chnl_GetPriority(const volatile stc_AXI_DMAC_t *pstcAXIDMA, uint8_t chNum)
{
    return pstcAXIDMA->CH[chNum].unCTL.stcField.u2PRIO;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_SetInterrupt
****************************************************************************//**
*
* This function sets the interrupt (SW-triggered).
*
* \param pstcAXIDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
* \param intMask
* intMask Interrupt(s) to be SW triggered
*
*******************************************************************************/
void Cy_AXIDMA_Chnl_SetInterrupt(volatile stc_AXI_DMAC_t *pstcAXIDMA, uint8_t chNum, uint32_t intMask)
{
    pstcAXIDMA->CH[chNum].unINTR_SET.u32Register = intMask;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_ClearInterrupt
****************************************************************************//**
*
* This function clears the interrupt status .
*
* \param ptscMDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
* \param intMask
* intMask Interrupt(s) to be cleared
*
*******************************************************************************/
void Cy_AXIDMA_Chnl_ClearInterrupt(volatile stc_AXI_DMAC_t *pstcAXIDMA, uint8_t chNum, uint32_t intMask)
{
    pstcAXIDMA->CH[chNum].unINTR.u32Register = intMask;
    
    /* Readback of the register is required by hardware. */
    (void) pstcAXIDMA->CH[chNum].unINTR.u32Register;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_SetInterruptMask
****************************************************************************//**
*
* This function sets interrupt mask value.
*
* \param pstcAXIDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
* \param intMask
* intMask Interrupt mask to be enabled
*
*******************************************************************************/
void Cy_AXIDMA_Chnl_SetInterruptMask(volatile stc_AXI_DMAC_t *pstcAXIDMA, uint8_t chNum, uint32_t intMask)
{
    pstcAXIDMA->CH[chNum].unINTR_MASK.u32Register = intMask;
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_GetInterruptMask
****************************************************************************//**
*
* This function gets interrupt mask value.
*
* \param pstcAXIDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
* \return
* Returns an interrupt mask value.
*
*******************************************************************************/
uint32_t Cy_AXIDMA_Chnl_GetInterruptMask(const volatile stc_AXI_DMAC_t *pstcAXIDMA, uint8_t chNum)
{
    return (pstcAXIDMA->CH[chNum].unINTR_MASK.u32Register);
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_GetInterruptStatusMasked
****************************************************************************//**
*
* This function returns logical-and of corresponding INTR and INTR_MASK fields
* in a single load operation.
*
* \param pstcAXIDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
* \return
* Returns the interrupt status of the enabled interrupts for the specified channel.
*
*******************************************************************************/
uint32_t Cy_AXIDMA_Chnl_GetInterruptStatusMasked(const volatile stc_AXI_DMAC_t *pstcAXIDMA, uint8_t chNum)
{
    return (pstcAXIDMA->CH[chNum].unINTR_MASKED.u32Register);
}


/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_GetInterruptStatus
****************************************************************************//**
*
* This function can be used to determine the interrupt status of the
* AXI-DMA channel.
*
* \param pstcAXIDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
* \return
* Returns the "raw" interrupt status for the specified channel.
*
*******************************************************************************/
uint32_t Cy_AXIDMA_Chnl_GetInterruptStatus(const volatile stc_AXI_DMAC_t *pstcAXIDMA, uint8_t chNum)
{
    return (pstcAXIDMA->CH[chNum].unINTR.u32Register);
}


#if defined(AXI_DMAC_SW_TR_PRESENT) && (AXI_DMAC_SW_TR_PRESENT == 1)

/*******************************************************************************
* Function Name: Cy_AXIDMA_Chnl_SetSwTrigger
****************************************************************************//**
*
* This function sets the SW trigger for a channel.
*
* \param pstcAXIDMA
* Pointer to the hardware AXI-DMA block.
*
* \param chNum
* Channel number of the AXI-DMA.
*
*******************************************************************************/
void Cy_AXIDMA_Chnl_SetSwTrigger(volatile stc_AXI_DMAC_t *pstcAXIDMA, uint8_t chNum)
{
    pstcAXIDMA->CH[chNum].unTR_CMD.stcField.u1ACTIVATE = 1;
}

#endif




#if defined(__cplusplus)
}
#endif

/* [] END OF FILE */
