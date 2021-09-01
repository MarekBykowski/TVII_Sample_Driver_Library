/***************************************************************************//**
* \file cy_mipicsi2.c
* \version 1.0
*
* \brief
* Provides an API implementation of the MIPI CSI-2 (mipicsi2) driver
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/*****************************************************************************
* Include files
*****************************************************************************/
#include "cy_project.h"
#include "cy_device_headers.h"
#include "cy_mipicsi2.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*****************************************************************************
* Local pre-processor symbols/macros ('define')
*****************************************************************************/

/*****************************************************************************
* Global variable definitions (declared in header file with 'extern')
*****************************************************************************/

/*****************************************************************************
* Local type definitions ('typedef')
*****************************************************************************/

/*****************************************************************************
* Local variable definitions ('static')
*****************************************************************************/

/*****************************************************************************
* Local function prototypes ('static')
*****************************************************************************/

/*****************************************************************************
* Function implementation - global ('extern') and local ('static')
*****************************************************************************/


/*******************************************************************************
* Function Name: Cy_Mipicsi2_FastInit
****************************************************************************//**
*
* \brief  Initializes the MIPI CSI-2 with the most commonly used settings
*
* \param  base : The pointer to the MIPI-CSI2 instance
*
* \return Result of initialization attempt
*
*******************************************************************************/
cy_mipicsi2_en_result_t Cy_Mipicsi2_FastInit(volatile stc_VIDEOSS_MIPICSI_t* base)
{
    const cy_mipicsi2_stc_cfg_t stcCfg = {
        .bAutoPowerDown         = true,                         // Enable auto power down mode
        .bContClkMode           = true,                         // Enable contineous clock mode
        .bHighSpeed             = false,                        // Enable high speed mode
        .u4FlushCount           = 3,                            // Always 3
        .u32BitrateBps          = 0UL,                          // Based on the transmitter clock and lane count
        .u32EscClkFreqHz        = 0UL,                          // Equal to the system clock
        .enEscClk               = Mipicsi2EscapeClockClkSys,    // Select system clock as escape clock
        .enLaneCount            = Mipicsi2LaneCount2,           // Number of data lane count
        .enCalibration          = Mipicsi2CalibAutomatic,       // Set default calibration mode
        .unPayloadDisable       = (cy_mipicsi2_stc_payload_disable_t)
        {
            .u1Blank            = 1,                            // Only blank frame should be disabled
        }
        
    };

    return Cy_Mipicsi2_Init(base, &stcCfg);
}

/*******************************************************************************
* Function Name: Cy_Mipicsi2_Init
****************************************************************************//**
*
* \brief  Initializes the MIPI CSI-2
*
* \param  base    : The pointer to the MIPI-CSI2 instance
* \param  pstcCfg : The pointer to the init configuration struct
*
* \return Result of initialization attempt
*
*******************************************************************************/
cy_mipicsi2_en_result_t Cy_Mipicsi2_Init(volatile stc_VIDEOSS_MIPICSI_t* base, const cy_mipicsi2_stc_cfg_t * pstcCfg)
{
    if(pstcCfg == NULL)
    {
        return CY_MIPICSI2_BAD_PARAM;
    }
    
    base->MIPICSI_STRUCT.MIPICSI_CORE.unCFG_NUM_LANES.stcField.u4CFG_NUM_LANES       = pstcCfg->enLaneCount;    
    base->MIPICSI_STRUCT.MIPICSI_CORE.unCFG_DATA_LANE_EN.stcField.u4CFG_DATA_LANE_EN = (1U << pstcCfg->enLaneCount) - 1U;    
    base->MIPICSI_STRUCT.MIPICSI_CORE.unCFG_CLK_LANE_EN.stcField.u1CFG_CLK_LANE_EN   = 1;
    base->MIPICSI_STRUCT.MIPICSI_CORE.unCFG_FLUSH_COUNT.stcField.u4CFG_FLUSH_COUNT   = pstcCfg->u4FlushCount;
    base->MIPICSI_STRUCT.MIPICSI_CORE.unCFG_DISABLE_PAYLOAD_0.u32Register            = pstcCfg->unPayloadDisable.au32Settings[0];
    base->MIPICSI_STRUCT.MIPICSI_CORE.unCFG_DISABLE_PAYLOAD_1.u32Register            = pstcCfg->unPayloadDisable.au32Settings[1];
        
    // Prepare settings for DPHY_CTL register in local variable
    un_VIDEOSS_MIPICSI_MIPICSI_STRUCT_MIPICSI_WRAP_DPHY_CTL_t unDphyCtlCfg;
    unDphyCtlCfg.u32Register              = base->MIPICSI_STRUCT.MIPICSI_WRAP.unDPHY_CTL.u32Register;   // Get current value of register
    unDphyCtlCfg.stcField.u1PD_DPHY       = 0;                                                          // '1': PHY is in power down.'0': PHY is in operation.
    unDphyCtlCfg.stcField.u1AUTO_PD_EN    = (pstcCfg->bAutoPowerDown == false) ? 0 : 1;
    unDphyCtlCfg.stcField.u1CONT_CLK_MODE = (pstcCfg->bContClkMode   == false) ? 0 : 1;
    unDphyCtlCfg.stcField.u1HSEL          = (pstcCfg->bHighSpeed     == false) ? 0 : 1;
    base->MIPICSI_STRUCT.MIPICSI_WRAP.unDPHY_CTL.u32Register = unDphyCtlCfg.u32Register;                // Write back to register
    base->MIPICSI_STRUCT.MIPICSI_WRAP.unCLOCK_CTL.stcField.u1ESC_SEL = pstcCfg->enEscClk;
    
    if(pstcCfg->enCalibration == Mipicsi2CalibAutomatic)
    {
        base->MIPICSI_STRUCT.MIPICSI_WRAP.unCAL_CTL.stcField.u1NOCAL = 0;
    }
    else
    {
        base->MIPICSI_STRUCT.MIPICSI_WRAP.unCAL_CTL.stcField.u1NOCAL   = 1;
        base->MIPICSI_STRUCT.MIPICSI_WRAP.unCAL_CTL.stcField.u2RX_RCAL = pstcCfg->enCalibration;        
    }
    
    if((pstcCfg->u32BitrateBps) && (pstcCfg->u32EscClkFreqHz))
    {
        // PRG_RXHS_SETTLE = round (((115 ns + 8*UI) / T_ESC) – 2.5)   // with UI = one bit-time of a single data lane, T_ESC := period of escape clock
        const float f115nanosecS = 0.000000115f;
        const float f25picosecS  = 0.0000000025f;
        
        float fBitTimeS             = 1.0f / pstcCfg->u32BitrateBps;
        float fEscClkPeriodS        = 1.0f / pstcCfg->u32EscClkFreqHz;    
        float fResultBeforeRounding = ((f115nanosecS + 8.0f * fBitTimeS) / fEscClkPeriodS) - f25picosecS;    
        uint8_t u8SettleTimeVal     = (uint8_t) (fResultBeforeRounding + 0.5f);
        
        base->MIPICSI_STRUCT.MIPICSI_WRAP.unTMG_CLOCK_CTL.stcField.u6SC_PRG_RXHS_SETTLE = u8SettleTimeVal;
        base->MIPICSI_STRUCT.MIPICSI_WRAP.unTMG_DATA_CTL.stcField.u6S_PRG_RXHS_SETTLE   = u8SettleTimeVal;
    }
    else
    {
        // Onboard image sensor settle time is configured
        base->MIPICSI_STRUCT.MIPICSI_WRAP.unTMG_CLOCK_CTL.stcField.u6SC_PRG_RXHS_SETTLE = 0x0f;     // Updated for image sensor;
        base->MIPICSI_STRUCT.MIPICSI_WRAP.unTMG_DATA_CTL.stcField.u6S_PRG_RXHS_SETTLE   = 0x08;     // Updated for image sensor;
    }
    
    base->MIPICSI_STRUCT.MIPICSI_WRAP.unCTL.stcField.u1ENABLED = 1;
    
    return CY_MIPICSI2_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Mipicsi2_DeInit
****************************************************************************//**
*
* \brief  De-Initializes the MIPICSI2 CSI-2
*
* \param  base : The pointer to the MIPICSI2-CSI2 instance
*
* \return None
*
*******************************************************************************/
void Cy_Mipicsi2_DeInit(volatile stc_VIDEOSS_MIPICSI_t* base)
{
    base->MIPICSI_STRUCT.MIPICSI_WRAP.unCTL.stcField.u1ENABLED      = 0;    
    base->MIPICSI_STRUCT.MIPICSI_WRAP.unDPHY_CTL.stcField.u1PD_DPHY = 0; // ???
}


/*******************************************************************************
* Function Name: Cy_Mipicsi2_GetInterruptStatus
****************************************************************************//**
*
* \brief  Returns the IRQ flag status of the specified IRQ type
*
* \param  base      : The pointer to the MIPI-CSI2 instance
* \param  enIrqType : The interrupt type
*
* \return '0' if IRQ flag has been set, '1' if IRQ flag has been set
*
*******************************************************************************/
uint32_t Cy_Mipicsi2_GetInterruptStatus(volatile stc_VIDEOSS_MIPICSI_t* base, cy_mipicsi2_en_irq_type_t enIrqType)
{
    return ((base->MIPICSI_STRUCT.MIPICSI_CORE.unIRQ_STATUS.u32Register & (1UL << enIrqType)) == 0) ? 0 : 1;
}

/*******************************************************************************
* Function Name: Cy_Mipicsi2_GetInterruptMask
****************************************************************************//**
*
* \brief  Returns the IRQ mask status of the specified IRQ type
*
* \param  base      : The pointer to the MIPI-CSI2 instance
* \param  enIrqType : The interrupt type
*
* \return '0' if IRQ is disabled, '1' if IRQ is enabled
*
*******************************************************************************/
uint32_t Cy_Mipicsi2_GetInterruptMask(volatile stc_VIDEOSS_MIPICSI_t* base, cy_mipicsi2_en_irq_type_t enIrqType)
{
    return ((base->MIPICSI_STRUCT.MIPICSI_CORE.unIRQ_ENABLE.u32Register & (1UL << enIrqType)) == 0) ? 0 : 1;
}


/*******************************************************************************
* Function Name: Cy_Mipicsi2_ClearInterrupt
****************************************************************************//**
*
* \brief  Clears the IRQ flag status of the specified IRQ type
*
* \param  base      : The pointer to the MIPI-CSI2 instance
* \param  enIrqType : The interrupt type
*
* \return None
*
*******************************************************************************/
void Cy_Mipicsi2_ClearInterrupt(volatile stc_VIDEOSS_MIPICSI_t* base, cy_mipicsi2_en_irq_type_t enIrqType)
{
    base->MIPICSI_STRUCT.MIPICSI_CORE.unIRQ_CLR.u32Register |= (1UL << enIrqType);     // write '1'
    base->MIPICSI_STRUCT.MIPICSI_CORE.unIRQ_CLR.u32Register &= (~(1UL << enIrqType));  // write '0' (according to spec, refer TRM!)
}


/*******************************************************************************
* Function Name: Cy_Mipicsi2_SetInterruptMask
****************************************************************************//**
*
* \brief  Changes the IRQ enable state of the specified IRQ type
*
* \param  base       : The pointer to the MIPI-CSI2 instance
* \param  enIrqType  : The interrupt type
* \param  bEnableIrq : Controls whether IRQ will be enabled ('true') or disabled ('false')
*
* \return None
*
*******************************************************************************/
void Cy_Mipicsi2_SetInterruptMask(volatile stc_VIDEOSS_MIPICSI_t* base, cy_mipicsi2_en_irq_type_t enIrqType, bool bEnableIrq)
{
    base->MIPICSI_STRUCT.MIPICSI_CORE.unIRQ_ENABLE.u32Register &= (~(1UL << enIrqType));
    if(bEnableIrq != false)
    {
        base->MIPICSI_STRUCT.MIPICSI_CORE.unIRQ_ENABLE.u32Register |= (1UL << enIrqType);
    }
}


#if defined(__cplusplus)
}
#endif


/* [] END OF FILE */
