/***************************************************************************//**
* \file cy_fpdlink.h
* \version 1.0
*
* \brief
* Provides an API declaration of the FPD-Link (fpdlink) driver
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_fpdlink FPD-Link (fpdlink)
* \{
* The fpdlink driver provides an API to initialize the FPD-Link.
*
* \defgroup group_fpdlink_macros Macro
* \defgroup group_fpdlink_enums Enumerated Types
* \defgroup group_fpdlink_functions Functions
* \defgroup group_fpdlink_data_structures Data structures
* \defgroup group_fpdlink_enums Enumerated types
*/


#if !defined(CY_FPDLINK_H)
#define CY_FPDLINK_H

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
* \addtogroup group_fpdlink_enums
* \{
*/

/**
* FPD-Link Instance
*/
typedef enum
{
    Fpdlink0      =   0, /**< FPD-Link instance #0 */
  #ifdef VIDEOSS0_FPDLINK1
    Fpdlink1      =   1, /**< FPD-Link instance #1 */
    FpdlinkDual01 = 128, /**< FPD-Link instance #0 and #1 in dual pixel mode */    
  #endif
} cy_fpdlink_en_instance_t;

/**
* Function return values
*/
typedef enum
{
    CY_FPDLINK_SUCCESS   = 0x00u, /**< Returned successful */
    CY_FPDLINK_ERROR     = 0x01u, /**< General error */
    CY_FPDLINK_BAD_PARAM = 0x02u, /**< Bad parameter was passed */
} cy_fpdlink_en_result_t;

/**
* FPD-Link bit order
*/
typedef enum
{
    FpdlinkLsbFirst = 0, /**< LSB is sent first */
    FpdlinkMsbFirst = 1, /**< MSB is sent first (default)*/
} cy_fpdlink_en_bit_order_t;

/**
* FPD-Link driver output current
*/
typedef enum
{
    FpdlinkCurrent2m40 = 0, /**< 2.40 mA */
    FpdlinkCurrent2m72 = 1, /**< 2.72 mA */
    FpdlinkCurrent2m88 = 2, /**< 2.88 mA */
    FpdlinkCurrent3m20 = 3, /**< 3.20 mA */
    FpdlinkCurrent3m36 = 4, /**< 3.36 mA (default) */
    FpdlinkCurrent3m68 = 5, /**< 3.68 mA */
    FpdlinkCurrent3m84 = 6, /**< 3.84 mA */
    FpdlinkCurrent4m32 = 7, /**< 4.32 mA */
} cy_fpdlink_en_current_t;


/**
* FPD-Link PLL output divider
*/
typedef enum
{
    FpdlinkPllOutDiv1 = 0, /**< Divide by 1 */
    FpdlinkPllOutDiv2 = 1, /**< Divide by 2 */
    FpdlinkPllOutDiv4 = 2, /**< Divide by 4 */
    FpdlinkPllOutDiv8 = 3, /**< Divide by 8 */
} cy_fpdlink_en_pll_out_div_t;

/**
* FPD-Link PLL bandwidth
*/
typedef enum
{
    FpdlinkPllBandwidthDefault    = 0, /**< Default */
    FpdlinkPllBandwidthLowA       = 1, /**< Lower bandwidth */
    FpdlinkPllBandwidthLowB       = 2, /**< Lower bandwidth */
    FpdlinkPllBandwidthLess800kHz = 3, /**< Less than 800 kHz */
} cy_fpdlink_en_pll_bandwidth_t;

/** \} group_fpdlink_enums */


/***************************************
*       Configuration Structure
***************************************/

/**
* \addtogroup group_fpdlink_data_structures
* \{
*/

/**
* Settings for FPD-Link initialization
*/
typedef struct
{
    cy_fpdlink_en_bit_order_t     enBitOrder;         /**< Bit order */
    cy_fpdlink_en_current_t       enCurrent;          /**< Output driver current */
    cy_fpdlink_en_pll_out_div_t   enPllOutDiv;        /**< PLL output divider */
    cy_fpdlink_en_pll_bandwidth_t enPllBandwidth;     /**< PLL bandwidth */
    uint32_t                      u32PllLockTimeout;  /**< Simple timeout count value (0: indefinite waiting for PLL lock) */
} cy_fpdlink_stc_cfg_t;


/** \} group_fpdlink_data_structures */


/***************************************
*       Function Prototypes
***************************************/

/**
* \addtogroup group_fpdlink_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_Fpdlink_FastInit
****************************************************************************//**
*
* \brief  Initializes the FPD-Link with the most commonly used settings
*
* \param  enFpdlink : Defines the FPD-Link instance to be initialized
* \param  enPllDiv  : FPD-Link PLL divider (needs to match the display clock
*                     divider in VIDEOSS)
*
* \return Result of initialization attempt
*
*******************************************************************************/
cy_fpdlink_en_result_t Cy_Fpdlink_FastInit(cy_fpdlink_en_instance_t enFpdlink, cy_fpdlink_en_pll_out_div_t enPllDiv);


/*******************************************************************************
* Function Name: Cy_Fpdlink_Init
****************************************************************************//**
*
* \brief  Initializes the FPD-Link
*
* \param  enFpdlink : Defines the FPD-Link instance to be initialized
* \param  pstcCfg   : The pointer to the init configuration struct
*
* \return Result of initialization attempt
*
*******************************************************************************/
cy_fpdlink_en_result_t Cy_Fpdlink_Init(cy_fpdlink_en_instance_t enFpdlink, const cy_fpdlink_stc_cfg_t * pstcCfg);


/*******************************************************************************
* Function Name: Cy_Fpdlink_DeInit
****************************************************************************//**
*
* \brief  De-Initializes the FPD-Link
*
* \param  enFpdlink : Defines the FPD-Link instance to be de-initialized
*
* \return None
*
*******************************************************************************/
void Cy_Fpdlink_DeInit(cy_fpdlink_en_instance_t enFpdlink);


/*******************************************************************************
* Function Name: Cy_Fpdlink_IsPllLocked
****************************************************************************//**
*
* \brief  Returns PLL lock status
*
* \param  enFpdlink : Defines the FPD-Link instance to be checked
*
* \return 'true' if Pll is locked, otherwise 'false'
*
*******************************************************************************/
bool Cy_Fpdlink_IsPllLocked(cy_fpdlink_en_instance_t enFpdlink);




/** \} group_fpdlink_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_FPDLINK_H */

/** \} group_fpdlink */

/* [] END OF FILE */
