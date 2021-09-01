/***************************************************************************//**
* \file cy_ethif_defines.h
* \version 1.0
*
* \brief
* Provides an API declaration of the Ethernet Interface [Cy_EthIf] driver
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#ifndef CY_ETHIF_DEFINES_H
#define CY_ETHIF_DEFINES_H

/**
* \addtogroup group_ethif_macros
* \{
*/

/***************************************
*        Constants
***************************************/
/** Ethernet configurations constants  */
#define CY_ETH_STANDARD_BD                  (0)                         // Standard Buffer Descriptor Mode
#define CY_ETH_EXTENDED_BD                  (1)                         // Extended Buffer Descriptor Mode
#define CY_ETH_TX_FSFM                      (0)                         // Full Store and Forward Mode [FSFM] for Tx
#define CY_ETH_TX_PSFM                      (1)                         // Partial Store and Forward Mode [PSFM] for Tx
#define CY_ETH_RX_FSFM                      (0)                         // Full Store and Forward Mode for Rx
#define CY_ETH_RX_PSFM                      (1)                         // Partial Store and Forward Mode for Rx

/** Ethernet channel  */
#define CY_ETH_DEFINE_NUM_IP               (2)                         // Number of Ethernet channels intended to use, maximum 2
#define CY_ETH_DEFINE_NUM_RXQS             (2)                         // Number of queues intended to use, maximum 3 
#define CY_ETH_DEFINE_NUM_TXQS             (3)                         // Number of queues intended to use, maximum 3 

/** Ethernet Operation Mode */
#define CY_ETH_DEFINE_TX_OP_MODE            CY_ETH_TX_FSFM             // FSFM OR PSFM
#define CY_ETH_DEFINE_RX_OP_MODE            CY_ETH_RX_FSFM             // FSFM OR PSFM
#define CY_ETH_DEFINE_TX_WATERMARK         (50)                        // Watermark level for Tx
#define CY_ETH_DEFINE_RX_WATERMARK         (50)                        // Watermark level for Rx

/** Buffer Descriptor mode  */
#define CY_ETH_DEFINE_BD                   CY_ETH_EXTENDED_BD           // standard or extended

/** Memory Allocation defines */                                       // Frame Buffers are allocated based on number of buffer descriptors 
#define CY_ETH_DEFINE_TOTAL_BD_PER_TXQUEUE (2)                         // Total number of Buffer Descriptors allocated for each transmit queue
#define CY_ETH_DEFINE_TOTAL_BD_PER_RXQUEUE (4)                         // Total number of Buffer Descriptors allocated for each receive queue

/** \} group_ethif_macros */

#endif /* CY_ETHIF_DEFINES_H */

/** \} cy_ethif_config */

/* [] END OF FILE */
