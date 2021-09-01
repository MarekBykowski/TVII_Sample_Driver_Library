/***************************************************************************//**
* \file cyreg_lin.h
*
* \brief
* LIN register definition header
*
* \note
* Generator version: 1.5.0.1277
* Database revision: TVIIBE1M_B1_CFR
*
********************************************************************************
* \copyright
* Copyright 2016-2019, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYREG_LIN_H_
#define _CYREG_LIN_H_

#include "cyip_lin.h"

/**
  * \brief LIN channel structure (LIN_CH0)
  */
#define CYREG_LIN0_CH0_CTL0             ((volatile un_LIN_CH_CTL0_t*) 0x40508000UL)
#define CYREG_LIN0_CH0_CTL1             ((volatile un_LIN_CH_CTL1_t*) 0x40508004UL)
#define CYREG_LIN0_CH0_STATUS           ((volatile un_LIN_CH_STATUS_t*) 0x40508008UL)
#define CYREG_LIN0_CH0_CMD              ((volatile un_LIN_CH_CMD_t*) 0x40508010UL)
#define CYREG_LIN0_CH0_TX_RX_STATUS     ((volatile un_LIN_CH_TX_RX_STATUS_t*) 0x40508060UL)
#define CYREG_LIN0_CH0_PID_CHECKSUM     ((volatile un_LIN_CH_PID_CHECKSUM_t*) 0x40508080UL)
#define CYREG_LIN0_CH0_DATA0            ((volatile un_LIN_CH_DATA0_t*) 0x40508084UL)
#define CYREG_LIN0_CH0_DATA1            ((volatile un_LIN_CH_DATA1_t*) 0x40508088UL)
#define CYREG_LIN0_CH0_INTR             ((volatile un_LIN_CH_INTR_t*) 0x405080C0UL)
#define CYREG_LIN0_CH0_INTR_SET         ((volatile un_LIN_CH_INTR_SET_t*) 0x405080C4UL)
#define CYREG_LIN0_CH0_INTR_MASK        ((volatile un_LIN_CH_INTR_MASK_t*) 0x405080C8UL)
#define CYREG_LIN0_CH0_INTR_MASKED      ((volatile un_LIN_CH_INTR_MASKED_t*) 0x405080CCUL)

/**
  * \brief LIN channel structure (LIN_CH1)
  */
#define CYREG_LIN0_CH1_CTL0             ((volatile un_LIN_CH_CTL0_t*) 0x40508100UL)
#define CYREG_LIN0_CH1_CTL1             ((volatile un_LIN_CH_CTL1_t*) 0x40508104UL)
#define CYREG_LIN0_CH1_STATUS           ((volatile un_LIN_CH_STATUS_t*) 0x40508108UL)
#define CYREG_LIN0_CH1_CMD              ((volatile un_LIN_CH_CMD_t*) 0x40508110UL)
#define CYREG_LIN0_CH1_TX_RX_STATUS     ((volatile un_LIN_CH_TX_RX_STATUS_t*) 0x40508160UL)
#define CYREG_LIN0_CH1_PID_CHECKSUM     ((volatile un_LIN_CH_PID_CHECKSUM_t*) 0x40508180UL)
#define CYREG_LIN0_CH1_DATA0            ((volatile un_LIN_CH_DATA0_t*) 0x40508184UL)
#define CYREG_LIN0_CH1_DATA1            ((volatile un_LIN_CH_DATA1_t*) 0x40508188UL)
#define CYREG_LIN0_CH1_INTR             ((volatile un_LIN_CH_INTR_t*) 0x405081C0UL)
#define CYREG_LIN0_CH1_INTR_SET         ((volatile un_LIN_CH_INTR_SET_t*) 0x405081C4UL)
#define CYREG_LIN0_CH1_INTR_MASK        ((volatile un_LIN_CH_INTR_MASK_t*) 0x405081C8UL)
#define CYREG_LIN0_CH1_INTR_MASKED      ((volatile un_LIN_CH_INTR_MASKED_t*) 0x405081CCUL)

/**
  * \brief LIN channel structure (LIN_CH2)
  */
#define CYREG_LIN0_CH2_CTL0             ((volatile un_LIN_CH_CTL0_t*) 0x40508200UL)
#define CYREG_LIN0_CH2_CTL1             ((volatile un_LIN_CH_CTL1_t*) 0x40508204UL)
#define CYREG_LIN0_CH2_STATUS           ((volatile un_LIN_CH_STATUS_t*) 0x40508208UL)
#define CYREG_LIN0_CH2_CMD              ((volatile un_LIN_CH_CMD_t*) 0x40508210UL)
#define CYREG_LIN0_CH2_TX_RX_STATUS     ((volatile un_LIN_CH_TX_RX_STATUS_t*) 0x40508260UL)
#define CYREG_LIN0_CH2_PID_CHECKSUM     ((volatile un_LIN_CH_PID_CHECKSUM_t*) 0x40508280UL)
#define CYREG_LIN0_CH2_DATA0            ((volatile un_LIN_CH_DATA0_t*) 0x40508284UL)
#define CYREG_LIN0_CH2_DATA1            ((volatile un_LIN_CH_DATA1_t*) 0x40508288UL)
#define CYREG_LIN0_CH2_INTR             ((volatile un_LIN_CH_INTR_t*) 0x405082C0UL)
#define CYREG_LIN0_CH2_INTR_SET         ((volatile un_LIN_CH_INTR_SET_t*) 0x405082C4UL)
#define CYREG_LIN0_CH2_INTR_MASK        ((volatile un_LIN_CH_INTR_MASK_t*) 0x405082C8UL)
#define CYREG_LIN0_CH2_INTR_MASKED      ((volatile un_LIN_CH_INTR_MASKED_t*) 0x405082CCUL)

/**
  * \brief LIN channel structure (LIN_CH3)
  */
#define CYREG_LIN0_CH3_CTL0             ((volatile un_LIN_CH_CTL0_t*) 0x40508300UL)
#define CYREG_LIN0_CH3_CTL1             ((volatile un_LIN_CH_CTL1_t*) 0x40508304UL)
#define CYREG_LIN0_CH3_STATUS           ((volatile un_LIN_CH_STATUS_t*) 0x40508308UL)
#define CYREG_LIN0_CH3_CMD              ((volatile un_LIN_CH_CMD_t*) 0x40508310UL)
#define CYREG_LIN0_CH3_TX_RX_STATUS     ((volatile un_LIN_CH_TX_RX_STATUS_t*) 0x40508360UL)
#define CYREG_LIN0_CH3_PID_CHECKSUM     ((volatile un_LIN_CH_PID_CHECKSUM_t*) 0x40508380UL)
#define CYREG_LIN0_CH3_DATA0            ((volatile un_LIN_CH_DATA0_t*) 0x40508384UL)
#define CYREG_LIN0_CH3_DATA1            ((volatile un_LIN_CH_DATA1_t*) 0x40508388UL)
#define CYREG_LIN0_CH3_INTR             ((volatile un_LIN_CH_INTR_t*) 0x405083C0UL)
#define CYREG_LIN0_CH3_INTR_SET         ((volatile un_LIN_CH_INTR_SET_t*) 0x405083C4UL)
#define CYREG_LIN0_CH3_INTR_MASK        ((volatile un_LIN_CH_INTR_MASK_t*) 0x405083C8UL)
#define CYREG_LIN0_CH3_INTR_MASKED      ((volatile un_LIN_CH_INTR_MASKED_t*) 0x405083CCUL)

/**
  * \brief LIN channel structure (LIN_CH4)
  */
#define CYREG_LIN0_CH4_CTL0             ((volatile un_LIN_CH_CTL0_t*) 0x40508400UL)
#define CYREG_LIN0_CH4_CTL1             ((volatile un_LIN_CH_CTL1_t*) 0x40508404UL)
#define CYREG_LIN0_CH4_STATUS           ((volatile un_LIN_CH_STATUS_t*) 0x40508408UL)
#define CYREG_LIN0_CH4_CMD              ((volatile un_LIN_CH_CMD_t*) 0x40508410UL)
#define CYREG_LIN0_CH4_TX_RX_STATUS     ((volatile un_LIN_CH_TX_RX_STATUS_t*) 0x40508460UL)
#define CYREG_LIN0_CH4_PID_CHECKSUM     ((volatile un_LIN_CH_PID_CHECKSUM_t*) 0x40508480UL)
#define CYREG_LIN0_CH4_DATA0            ((volatile un_LIN_CH_DATA0_t*) 0x40508484UL)
#define CYREG_LIN0_CH4_DATA1            ((volatile un_LIN_CH_DATA1_t*) 0x40508488UL)
#define CYREG_LIN0_CH4_INTR             ((volatile un_LIN_CH_INTR_t*) 0x405084C0UL)
#define CYREG_LIN0_CH4_INTR_SET         ((volatile un_LIN_CH_INTR_SET_t*) 0x405084C4UL)
#define CYREG_LIN0_CH4_INTR_MASK        ((volatile un_LIN_CH_INTR_MASK_t*) 0x405084C8UL)
#define CYREG_LIN0_CH4_INTR_MASKED      ((volatile un_LIN_CH_INTR_MASKED_t*) 0x405084CCUL)

/**
  * \brief LIN channel structure (LIN_CH5)
  */
#define CYREG_LIN0_CH5_CTL0             ((volatile un_LIN_CH_CTL0_t*) 0x40508500UL)
#define CYREG_LIN0_CH5_CTL1             ((volatile un_LIN_CH_CTL1_t*) 0x40508504UL)
#define CYREG_LIN0_CH5_STATUS           ((volatile un_LIN_CH_STATUS_t*) 0x40508508UL)
#define CYREG_LIN0_CH5_CMD              ((volatile un_LIN_CH_CMD_t*) 0x40508510UL)
#define CYREG_LIN0_CH5_TX_RX_STATUS     ((volatile un_LIN_CH_TX_RX_STATUS_t*) 0x40508560UL)
#define CYREG_LIN0_CH5_PID_CHECKSUM     ((volatile un_LIN_CH_PID_CHECKSUM_t*) 0x40508580UL)
#define CYREG_LIN0_CH5_DATA0            ((volatile un_LIN_CH_DATA0_t*) 0x40508584UL)
#define CYREG_LIN0_CH5_DATA1            ((volatile un_LIN_CH_DATA1_t*) 0x40508588UL)
#define CYREG_LIN0_CH5_INTR             ((volatile un_LIN_CH_INTR_t*) 0x405085C0UL)
#define CYREG_LIN0_CH5_INTR_SET         ((volatile un_LIN_CH_INTR_SET_t*) 0x405085C4UL)
#define CYREG_LIN0_CH5_INTR_MASK        ((volatile un_LIN_CH_INTR_MASK_t*) 0x405085C8UL)
#define CYREG_LIN0_CH5_INTR_MASKED      ((volatile un_LIN_CH_INTR_MASKED_t*) 0x405085CCUL)

/**
  * \brief LIN channel structure (LIN_CH6)
  */
#define CYREG_LIN0_CH6_CTL0             ((volatile un_LIN_CH_CTL0_t*) 0x40508600UL)
#define CYREG_LIN0_CH6_CTL1             ((volatile un_LIN_CH_CTL1_t*) 0x40508604UL)
#define CYREG_LIN0_CH6_STATUS           ((volatile un_LIN_CH_STATUS_t*) 0x40508608UL)
#define CYREG_LIN0_CH6_CMD              ((volatile un_LIN_CH_CMD_t*) 0x40508610UL)
#define CYREG_LIN0_CH6_TX_RX_STATUS     ((volatile un_LIN_CH_TX_RX_STATUS_t*) 0x40508660UL)
#define CYREG_LIN0_CH6_PID_CHECKSUM     ((volatile un_LIN_CH_PID_CHECKSUM_t*) 0x40508680UL)
#define CYREG_LIN0_CH6_DATA0            ((volatile un_LIN_CH_DATA0_t*) 0x40508684UL)
#define CYREG_LIN0_CH6_DATA1            ((volatile un_LIN_CH_DATA1_t*) 0x40508688UL)
#define CYREG_LIN0_CH6_INTR             ((volatile un_LIN_CH_INTR_t*) 0x405086C0UL)
#define CYREG_LIN0_CH6_INTR_SET         ((volatile un_LIN_CH_INTR_SET_t*) 0x405086C4UL)
#define CYREG_LIN0_CH6_INTR_MASK        ((volatile un_LIN_CH_INTR_MASK_t*) 0x405086C8UL)
#define CYREG_LIN0_CH6_INTR_MASKED      ((volatile un_LIN_CH_INTR_MASKED_t*) 0x405086CCUL)

/**
  * \brief LIN channel structure (LIN_CH7)
  */
#define CYREG_LIN0_CH7_CTL0             ((volatile un_LIN_CH_CTL0_t*) 0x40508700UL)
#define CYREG_LIN0_CH7_CTL1             ((volatile un_LIN_CH_CTL1_t*) 0x40508704UL)
#define CYREG_LIN0_CH7_STATUS           ((volatile un_LIN_CH_STATUS_t*) 0x40508708UL)
#define CYREG_LIN0_CH7_CMD              ((volatile un_LIN_CH_CMD_t*) 0x40508710UL)
#define CYREG_LIN0_CH7_TX_RX_STATUS     ((volatile un_LIN_CH_TX_RX_STATUS_t*) 0x40508760UL)
#define CYREG_LIN0_CH7_PID_CHECKSUM     ((volatile un_LIN_CH_PID_CHECKSUM_t*) 0x40508780UL)
#define CYREG_LIN0_CH7_DATA0            ((volatile un_LIN_CH_DATA0_t*) 0x40508784UL)
#define CYREG_LIN0_CH7_DATA1            ((volatile un_LIN_CH_DATA1_t*) 0x40508788UL)
#define CYREG_LIN0_CH7_INTR             ((volatile un_LIN_CH_INTR_t*) 0x405087C0UL)
#define CYREG_LIN0_CH7_INTR_SET         ((volatile un_LIN_CH_INTR_SET_t*) 0x405087C4UL)
#define CYREG_LIN0_CH7_INTR_MASK        ((volatile un_LIN_CH_INTR_MASK_t*) 0x405087C8UL)
#define CYREG_LIN0_CH7_INTR_MASKED      ((volatile un_LIN_CH_INTR_MASKED_t*) 0x405087CCUL)

/**
  * \brief LIN (LIN0)
  */
#define CYREG_LIN0_ERROR_CTL            ((volatile un_LIN_ERROR_CTL_t*) 0x40500000UL)
#define CYREG_LIN0_TEST_CTL             ((volatile un_LIN_TEST_CTL_t*) 0x40500004UL)

#endif /* _CYREG_LIN_H_ */


/* [] END OF FILE */
