/***************************************************************************//**
* \file cy_mipicsi2.h
* \version 1.0
*
* \brief
* Provides an API declaration of the MIPI CSI-2 (mipicsi2) driver
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_mipicsi2 MIPI CSI-2 (mipicsi2)
* \{
* The mipicsi2 driver provides an API to initialize the MIPI CSI-2.
*
* \defgroup group_mipicsi2_functions Functions
* \defgroup group_mipicsi2_data_structures Data structures
* \defgroup group_mipicsi2_enums Enumerated types
*/


#if !defined(CY_MIPICSI2_H)
#define CY_MIPICSI2_H

#include <stddef.h>
#include <stdbool.h>
#include "cy_device_headers.h"


#if defined(__cplusplus)
extern "C" {
#endif


/***************************************
*       Enumeration
***************************************/

/**
* \addtogroup group_mipicsi2_enums
* \{
*/


/**
* Function return values
*/
typedef enum
{
    CY_MIPICSI2_SUCCESS   = 0x00u, /**< Returned successful */
    CY_MIPICSI2_ERROR     = 0x01u, /**< General error */
    CY_MIPICSI2_BAD_PARAM = 0x02u, /**< Bad parameter was passed */
} cy_mipicsi2_en_result_t;

/**
* MIPI CSI-2 lane count
*/
typedef enum
{
    Mipicsi2LaneCount1 = 1, /**< 1 data lane */
    Mipicsi2LaneCount2 = 2, /**< 2 data lanes */
    Mipicsi2LaneCount3 = 3, /**< 3 data lanes */
    Mipicsi2LaneCount4 = 4, /**< 4 data lanes */    
} cy_mipicsi2_en_lane_count_t;

/**
* MIPI CSI-2 IRQ types
*/
typedef enum
{
    Mipicsi2IrqErrorCrc                   =  0, /**< CRC error IRQ */
    Mipicsi2IrqErrorEccSingle             =  1, /**< Single Bit ECC error IRQ */
    Mipicsi2IrqErrorEccDouble             =  2, /**< Double Bit ECC error IRQ */
    Mipicsi2IrqStatusUlpsActiveChange     =  3, /**< ULPS active status change */
    Mipicsi2IrqStatusUlpsMarkActiveChange =  4, /**< ULPS mark active status change */
} cy_mipicsi2_en_irq_type_t;

/**
* MIPI CSI-2 Escape Clock Selection
*/
typedef enum
{
    Mipicsi2EscapeClockClkVideo = 0, /**< clk_video (i.e. clk_videoss in Traveo II cluster) */
    Mipicsi2EscapeClockClkSys   = 1, /**< clk_sys   (i.e. clk_slow    in Traveo II cluster) */
} cy_mipicsi2_en_escape_clock_t;


/**
* MIPI CSI-2 receiver termination calibration
*/
typedef enum
{
    Mipicsi2Calib20PctHigherThanMidrange =   0, /**< 20% higher than mid-range (highest impedance setting) */
    Mipicsi2CalibMidrange                =   1, /**< Mid-range impedance setting */
    Mipicsi2Calib15PctLowerThanMidrange  =   2, /**< 15% lower than mid-range */
    Mipicsi2Calib20PctLowerThanMidrange  =   3, /**< 20% lower than mid-range (lowest impedance setting) */
    Mipicsi2CalibAutomatic               = 128, /**< Automatic calibration (based on accurate, chip external 15k resistor) */
} cy_mipicsi2_en_calibration_t;
/** \} group_mipicsi2_enums */

/**
* \addtogroup group_mipicsi2_data_structures
* \{
*/
/**
* MIPI CSI-2 payload disable bit field struct
*/
typedef struct
{
    uint64_t u1Null              : 1;
    uint64_t u1Blank             : 1;
    uint64_t u1Embedded          : 1;
    uint64_t u5Reserved_1        : 5;
    uint64_t u1Yuv420_8Bit       : 1;
    uint64_t u1Yuv420_10Bit      : 1;
    uint64_t u1LegacyYuv420_8Bit : 1;
    uint64_t u1Reserved_2        : 1;
    uint64_t u1Yuv422_8BitCsp    : 1;
    uint64_t u1Yuv422_10BitCsp   : 1;
    uint64_t u1Yuv422_8Bit       : 1;
    uint64_t u1Yuv422_10Bit      : 1;
    uint64_t u1Rgb444            : 1;
    uint64_t u1Rgb555            : 1;
    uint64_t u1Rgb565            : 1;
    uint64_t u1Rgb666            : 1;
    uint64_t u1Rgb888            : 1;
    uint64_t u3Reserved_3        : 3;
    uint64_t u1Raw6              : 1;
    uint64_t u1Raw7              : 1;
    uint64_t u1Raw8              : 1;
    uint64_t u1Raw10             : 1;
    uint64_t u1Raw12             : 1;
    uint64_t u1Raw14             : 1;
    uint64_t u1Raw16             : 1;
    uint64_t u1Raw20             : 1;
    uint64_t u1UserType0x30      : 1;
    uint64_t u1UserType0x31      : 1;
    uint64_t u1UserType0x32      : 1;
    uint64_t u1UserType0x33      : 1;
    uint64_t u1UserType0x34      : 1;
    uint64_t u1UserType0x35      : 1;
    uint64_t u1UserType0x36      : 1;
    uint64_t u1UserType0x37      : 1;
    uint64_t u8Reserved_4        : 8;
    uint64_t u1UnsupportedTypes  : 1;
} cy_mipicsi2_stc_payload_disable_t;


/**
* MIPI CSI-2 payload disable configuration union
*/
typedef union
{
    cy_mipicsi2_stc_payload_disable_t   stcField;
    uint64_t                            u64Settings;
    uint32_t                            au32Settings[2];
} cy_mipicsi2_un_payload_disable_t;


/***************************************
*       Configuration Structure
***************************************/


/**
* Settings for MIPI CSI-2 initialization
*/
typedef struct
{
    bool                               bAutoPowerDown;     /**< Auto Power-Down Enable */
    bool                               bContClkMode;       /**< Continuous Clock Mode Enable */
    bool                               bHighSpeed;         /**< High Speed Select (false: <= 1.0Gbps; true: > 1.0Gbps) */
    uint32_t                           u4FlushCount : 4;   /**< FIFO flush count (default: 3), a value of 3 works for most applications but should be set higher if core clock 10x or more of byte clock, refer TRM */
    uint32_t                           u32BitrateBps;      /**< Bitrate (in bits per second) of a single data lane of the MIPI CSI-2 interface. Used to calculate the RX High Speed Settle Time (S_PRG_RXHS_SETTLE/SC_PRG_RXHS_SETTLE) */
    uint32_t                           u32EscClkFreqHz;    /**< Frequency (in Hz) of the escape clock selected by #enEscClk. Used to calculate the RX High Speed Settle Time (S_PRG_RXHS_SETTLE/SC_PRG_RXHS_SETTLE) */
    cy_mipicsi2_en_escape_clock_t      enEscClk;           /**< Escape clock selection (should be >= 60 MHz!)*/
    cy_mipicsi2_en_lane_count_t        enLaneCount;        /**< Number of (data) lanes to be configured */
    cy_mipicsi2_en_calibration_t       enCalibration;      /**< Calibration for receiver termination */
    cy_mipicsi2_un_payload_disable_t   unPayloadDisable;   /**< Determines the payload types that shall be disabled (Note: YUV420 and RAW types are not supported by VIDEOSS) */
} cy_mipicsi2_stc_cfg_t;


/** \} group_mipicsi2_data_structures */


/***************************************
*       Function Prototypes
***************************************/

/**
* \addtogroup group_mipicsi2_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_Mipicsi2_FastInit
****************************************************************************//**
*
* \brief  Initializes the MIPICSI2 CSI-2 with the most commonly used settings
*
* \param  base : The pointer to the MIPICSI2-CSI2 instance
*
* \return Result of initialization attempt
*
*******************************************************************************/
cy_mipicsi2_en_result_t Cy_Mipicsi2_FastInit(volatile stc_VIDEOSS_MIPICSI_t* base);


/*******************************************************************************
* Function Name: Cy_Mipicsi2_Init
****************************************************************************//**
*
* \brief  Initializes the MIPICSI2 CSI-2
*
* \param  base    : The pointer to the MIPICSI2-CSI2 instance
* \param  pstcCfg : The pointer to the init configuration struct
*
* \return Result of initialization attempt
*
*******************************************************************************/
cy_mipicsi2_en_result_t Cy_Mipicsi2_Init(volatile stc_VIDEOSS_MIPICSI_t* base, const cy_mipicsi2_stc_cfg_t * pstcCfg);


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
void Cy_Mipicsi2_DeInit(volatile stc_VIDEOSS_MIPICSI_t* base);


/*******************************************************************************
* Function Name: Cy_Mipicsi2_GetInterruptStatus
****************************************************************************//**
*
* \brief  Returns the IRQ flag status of the specified IRQ type
*
* \param  base      : The pointer to the MIPICSI2-CSI2 instance
* \param  enIrqType : The interrupt type
*
* \return '0' if IRQ flag has been set, '1' if IRQ flag has been set
*
*******************************************************************************/
uint32_t Cy_Mipicsi2_GetInterruptStatus(volatile stc_VIDEOSS_MIPICSI_t* base, cy_mipicsi2_en_irq_type_t enIrqType);


/*******************************************************************************
* Function Name: Cy_Mipicsi2_GetInterruptMask
****************************************************************************//**
*
* \brief  Returns the IRQ mask status of the specified IRQ type
*
* \param  base      : The pointer to the MIPICSI2-CSI2 instance
* \param  enIrqType : The interrupt type
*
* \return '0' if IRQ is disabled, '1' if IRQ is enabled
*
*******************************************************************************/
uint32_t Cy_Mipicsi2_GetInterruptMask(volatile stc_VIDEOSS_MIPICSI_t* base, cy_mipicsi2_en_irq_type_t enIrqType);


/*******************************************************************************
* Function Name: Cy_Mipicsi2_ClearInterrupt
****************************************************************************//**
*
* \brief  Clears the IRQ flag status of the specified IRQ type
*
* \param  base      : The pointer to the MIPICSI2-CSI2 instance
* \param  enIrqType : The interrupt type
*
* \return None
*
*******************************************************************************/
void Cy_Mipicsi2_ClearInterrupt(volatile stc_VIDEOSS_MIPICSI_t* base, cy_mipicsi2_en_irq_type_t enIrqType);


/*******************************************************************************
* Function Name: Cy_Mipicsi2_SetInterruptMask
****************************************************************************//**
*
* \brief  Changes the IRQ enable state of the specified IRQ type
*
* \param  base       : The pointer to the MIPICSI2-CSI2 instance
* \param  enIrqType  : The interrupt type
* \param  bEnableIrq : Controls whether IRQ will be enabled ('true') or disabled ('false')
*
* \return None
*
*******************************************************************************/
void Cy_Mipicsi2_SetInterruptMask(volatile stc_VIDEOSS_MIPICSI_t* base, cy_mipicsi2_en_irq_type_t enIrqType, bool bEnableIrq);


/** \} group_mipicsi2_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_MIPICSI2_H */

/** \} group_mipicsi2 */

/* [] END OF FILE */
