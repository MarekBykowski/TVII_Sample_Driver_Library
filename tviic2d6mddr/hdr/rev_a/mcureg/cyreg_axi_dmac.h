/***************************************************************************//**
* \file cyreg_axi_dmac.h
*
* \brief
* AXI_DMAC register definition header
*
* \note
* Generator version: 1.6.0.453
* Database revision: TVIIC2D6MDDR_A0_CMR2
*
********************************************************************************
* \copyright
* Copyright 2016-2021, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYREG_AXI_DMAC_H_
#define _CYREG_AXI_DMAC_H_

#include "cyip_axi_dmac.h"

/**
  * \brief AXI DMA controller channel (AXI_DMAC_CH0)
  */
#define CYREG_AXI_DMAC_CH0_CTL          ((volatile un_AXI_DMAC_CH_CTL_t*) 0x402B1000UL)
#define CYREG_AXI_DMAC_CH0_STATUS       ((volatile un_AXI_DMAC_CH_STATUS_t*) 0x402B1004UL)
#define CYREG_AXI_DMAC_CH0_IDX          ((volatile un_AXI_DMAC_CH_IDX_t*) 0x402B1010UL)
#define CYREG_AXI_DMAC_CH0_SRC          ((volatile un_AXI_DMAC_CH_SRC_t*) 0x402B1014UL)
#define CYREG_AXI_DMAC_CH0_DST          ((volatile un_AXI_DMAC_CH_DST_t*) 0x402B1018UL)
#define CYREG_AXI_DMAC_CH0_M_IDX        ((volatile un_AXI_DMAC_CH_M_IDX_t*) 0x402B101CUL)
#define CYREG_AXI_DMAC_CH0_CURR         ((volatile un_AXI_DMAC_CH_CURR_t*) 0x402B1020UL)
#define CYREG_AXI_DMAC_CH0_TR_CMD       ((volatile un_AXI_DMAC_CH_TR_CMD_t*) 0x402B1028UL)
#define CYREG_AXI_DMAC_CH0_DESCR_STATUS ((volatile un_AXI_DMAC_CH_DESCR_STATUS_t*) 0x402B1040UL)
#define CYREG_AXI_DMAC_CH0_DESCR_CTL    ((volatile un_AXI_DMAC_CH_DESCR_CTL_t*) 0x402B1050UL)
#define CYREG_AXI_DMAC_CH0_DESCR_SRC    ((volatile un_AXI_DMAC_CH_DESCR_SRC_t*) 0x402B1054UL)
#define CYREG_AXI_DMAC_CH0_DESCR_DST    ((volatile un_AXI_DMAC_CH_DESCR_DST_t*) 0x402B1058UL)
#define CYREG_AXI_DMAC_CH0_DESCR_M_SIZE ((volatile un_AXI_DMAC_CH_DESCR_M_SIZE_t*) 0x402B105CUL)
#define CYREG_AXI_DMAC_CH0_DESCR_X_SIZE ((volatile un_AXI_DMAC_CH_DESCR_X_SIZE_t*) 0x402B1060UL)
#define CYREG_AXI_DMAC_CH0_DESCR_X_INCR ((volatile un_AXI_DMAC_CH_DESCR_X_INCR_t*) 0x402B1064UL)
#define CYREG_AXI_DMAC_CH0_DESCR_Y_SIZE ((volatile un_AXI_DMAC_CH_DESCR_Y_SIZE_t*) 0x402B1068UL)
#define CYREG_AXI_DMAC_CH0_DESCR_Y_INCR ((volatile un_AXI_DMAC_CH_DESCR_Y_INCR_t*) 0x402B106CUL)
#define CYREG_AXI_DMAC_CH0_DESCR_NEXT   ((volatile un_AXI_DMAC_CH_DESCR_NEXT_t*) 0x402B1070UL)
#define CYREG_AXI_DMAC_CH0_INTR         ((volatile un_AXI_DMAC_CH_INTR_t*) 0x402B1080UL)
#define CYREG_AXI_DMAC_CH0_INTR_SET     ((volatile un_AXI_DMAC_CH_INTR_SET_t*) 0x402B1084UL)
#define CYREG_AXI_DMAC_CH0_INTR_MASK    ((volatile un_AXI_DMAC_CH_INTR_MASK_t*) 0x402B1088UL)
#define CYREG_AXI_DMAC_CH0_INTR_MASKED  ((volatile un_AXI_DMAC_CH_INTR_MASKED_t*) 0x402B108CUL)

/**
  * \brief AXI DMA controller channel (AXI_DMAC_CH1)
  */
#define CYREG_AXI_DMAC_CH1_CTL          ((volatile un_AXI_DMAC_CH_CTL_t*) 0x402B1100UL)
#define CYREG_AXI_DMAC_CH1_STATUS       ((volatile un_AXI_DMAC_CH_STATUS_t*) 0x402B1104UL)
#define CYREG_AXI_DMAC_CH1_IDX          ((volatile un_AXI_DMAC_CH_IDX_t*) 0x402B1110UL)
#define CYREG_AXI_DMAC_CH1_SRC          ((volatile un_AXI_DMAC_CH_SRC_t*) 0x402B1114UL)
#define CYREG_AXI_DMAC_CH1_DST          ((volatile un_AXI_DMAC_CH_DST_t*) 0x402B1118UL)
#define CYREG_AXI_DMAC_CH1_M_IDX        ((volatile un_AXI_DMAC_CH_M_IDX_t*) 0x402B111CUL)
#define CYREG_AXI_DMAC_CH1_CURR         ((volatile un_AXI_DMAC_CH_CURR_t*) 0x402B1120UL)
#define CYREG_AXI_DMAC_CH1_TR_CMD       ((volatile un_AXI_DMAC_CH_TR_CMD_t*) 0x402B1128UL)
#define CYREG_AXI_DMAC_CH1_DESCR_STATUS ((volatile un_AXI_DMAC_CH_DESCR_STATUS_t*) 0x402B1140UL)
#define CYREG_AXI_DMAC_CH1_DESCR_CTL    ((volatile un_AXI_DMAC_CH_DESCR_CTL_t*) 0x402B1150UL)
#define CYREG_AXI_DMAC_CH1_DESCR_SRC    ((volatile un_AXI_DMAC_CH_DESCR_SRC_t*) 0x402B1154UL)
#define CYREG_AXI_DMAC_CH1_DESCR_DST    ((volatile un_AXI_DMAC_CH_DESCR_DST_t*) 0x402B1158UL)
#define CYREG_AXI_DMAC_CH1_DESCR_M_SIZE ((volatile un_AXI_DMAC_CH_DESCR_M_SIZE_t*) 0x402B115CUL)
#define CYREG_AXI_DMAC_CH1_DESCR_X_SIZE ((volatile un_AXI_DMAC_CH_DESCR_X_SIZE_t*) 0x402B1160UL)
#define CYREG_AXI_DMAC_CH1_DESCR_X_INCR ((volatile un_AXI_DMAC_CH_DESCR_X_INCR_t*) 0x402B1164UL)
#define CYREG_AXI_DMAC_CH1_DESCR_Y_SIZE ((volatile un_AXI_DMAC_CH_DESCR_Y_SIZE_t*) 0x402B1168UL)
#define CYREG_AXI_DMAC_CH1_DESCR_Y_INCR ((volatile un_AXI_DMAC_CH_DESCR_Y_INCR_t*) 0x402B116CUL)
#define CYREG_AXI_DMAC_CH1_DESCR_NEXT   ((volatile un_AXI_DMAC_CH_DESCR_NEXT_t*) 0x402B1170UL)
#define CYREG_AXI_DMAC_CH1_INTR         ((volatile un_AXI_DMAC_CH_INTR_t*) 0x402B1180UL)
#define CYREG_AXI_DMAC_CH1_INTR_SET     ((volatile un_AXI_DMAC_CH_INTR_SET_t*) 0x402B1184UL)
#define CYREG_AXI_DMAC_CH1_INTR_MASK    ((volatile un_AXI_DMAC_CH_INTR_MASK_t*) 0x402B1188UL)
#define CYREG_AXI_DMAC_CH1_INTR_MASKED  ((volatile un_AXI_DMAC_CH_INTR_MASKED_t*) 0x402B118CUL)

/**
  * \brief AXI DMA controller channel (AXI_DMAC_CH2)
  */
#define CYREG_AXI_DMAC_CH2_CTL          ((volatile un_AXI_DMAC_CH_CTL_t*) 0x402B1200UL)
#define CYREG_AXI_DMAC_CH2_STATUS       ((volatile un_AXI_DMAC_CH_STATUS_t*) 0x402B1204UL)
#define CYREG_AXI_DMAC_CH2_IDX          ((volatile un_AXI_DMAC_CH_IDX_t*) 0x402B1210UL)
#define CYREG_AXI_DMAC_CH2_SRC          ((volatile un_AXI_DMAC_CH_SRC_t*) 0x402B1214UL)
#define CYREG_AXI_DMAC_CH2_DST          ((volatile un_AXI_DMAC_CH_DST_t*) 0x402B1218UL)
#define CYREG_AXI_DMAC_CH2_M_IDX        ((volatile un_AXI_DMAC_CH_M_IDX_t*) 0x402B121CUL)
#define CYREG_AXI_DMAC_CH2_CURR         ((volatile un_AXI_DMAC_CH_CURR_t*) 0x402B1220UL)
#define CYREG_AXI_DMAC_CH2_TR_CMD       ((volatile un_AXI_DMAC_CH_TR_CMD_t*) 0x402B1228UL)
#define CYREG_AXI_DMAC_CH2_DESCR_STATUS ((volatile un_AXI_DMAC_CH_DESCR_STATUS_t*) 0x402B1240UL)
#define CYREG_AXI_DMAC_CH2_DESCR_CTL    ((volatile un_AXI_DMAC_CH_DESCR_CTL_t*) 0x402B1250UL)
#define CYREG_AXI_DMAC_CH2_DESCR_SRC    ((volatile un_AXI_DMAC_CH_DESCR_SRC_t*) 0x402B1254UL)
#define CYREG_AXI_DMAC_CH2_DESCR_DST    ((volatile un_AXI_DMAC_CH_DESCR_DST_t*) 0x402B1258UL)
#define CYREG_AXI_DMAC_CH2_DESCR_M_SIZE ((volatile un_AXI_DMAC_CH_DESCR_M_SIZE_t*) 0x402B125CUL)
#define CYREG_AXI_DMAC_CH2_DESCR_X_SIZE ((volatile un_AXI_DMAC_CH_DESCR_X_SIZE_t*) 0x402B1260UL)
#define CYREG_AXI_DMAC_CH2_DESCR_X_INCR ((volatile un_AXI_DMAC_CH_DESCR_X_INCR_t*) 0x402B1264UL)
#define CYREG_AXI_DMAC_CH2_DESCR_Y_SIZE ((volatile un_AXI_DMAC_CH_DESCR_Y_SIZE_t*) 0x402B1268UL)
#define CYREG_AXI_DMAC_CH2_DESCR_Y_INCR ((volatile un_AXI_DMAC_CH_DESCR_Y_INCR_t*) 0x402B126CUL)
#define CYREG_AXI_DMAC_CH2_DESCR_NEXT   ((volatile un_AXI_DMAC_CH_DESCR_NEXT_t*) 0x402B1270UL)
#define CYREG_AXI_DMAC_CH2_INTR         ((volatile un_AXI_DMAC_CH_INTR_t*) 0x402B1280UL)
#define CYREG_AXI_DMAC_CH2_INTR_SET     ((volatile un_AXI_DMAC_CH_INTR_SET_t*) 0x402B1284UL)
#define CYREG_AXI_DMAC_CH2_INTR_MASK    ((volatile un_AXI_DMAC_CH_INTR_MASK_t*) 0x402B1288UL)
#define CYREG_AXI_DMAC_CH2_INTR_MASKED  ((volatile un_AXI_DMAC_CH_INTR_MASKED_t*) 0x402B128CUL)

/**
  * \brief AXI DMA controller channel (AXI_DMAC_CH3)
  */
#define CYREG_AXI_DMAC_CH3_CTL          ((volatile un_AXI_DMAC_CH_CTL_t*) 0x402B1300UL)
#define CYREG_AXI_DMAC_CH3_STATUS       ((volatile un_AXI_DMAC_CH_STATUS_t*) 0x402B1304UL)
#define CYREG_AXI_DMAC_CH3_IDX          ((volatile un_AXI_DMAC_CH_IDX_t*) 0x402B1310UL)
#define CYREG_AXI_DMAC_CH3_SRC          ((volatile un_AXI_DMAC_CH_SRC_t*) 0x402B1314UL)
#define CYREG_AXI_DMAC_CH3_DST          ((volatile un_AXI_DMAC_CH_DST_t*) 0x402B1318UL)
#define CYREG_AXI_DMAC_CH3_M_IDX        ((volatile un_AXI_DMAC_CH_M_IDX_t*) 0x402B131CUL)
#define CYREG_AXI_DMAC_CH3_CURR         ((volatile un_AXI_DMAC_CH_CURR_t*) 0x402B1320UL)
#define CYREG_AXI_DMAC_CH3_TR_CMD       ((volatile un_AXI_DMAC_CH_TR_CMD_t*) 0x402B1328UL)
#define CYREG_AXI_DMAC_CH3_DESCR_STATUS ((volatile un_AXI_DMAC_CH_DESCR_STATUS_t*) 0x402B1340UL)
#define CYREG_AXI_DMAC_CH3_DESCR_CTL    ((volatile un_AXI_DMAC_CH_DESCR_CTL_t*) 0x402B1350UL)
#define CYREG_AXI_DMAC_CH3_DESCR_SRC    ((volatile un_AXI_DMAC_CH_DESCR_SRC_t*) 0x402B1354UL)
#define CYREG_AXI_DMAC_CH3_DESCR_DST    ((volatile un_AXI_DMAC_CH_DESCR_DST_t*) 0x402B1358UL)
#define CYREG_AXI_DMAC_CH3_DESCR_M_SIZE ((volatile un_AXI_DMAC_CH_DESCR_M_SIZE_t*) 0x402B135CUL)
#define CYREG_AXI_DMAC_CH3_DESCR_X_SIZE ((volatile un_AXI_DMAC_CH_DESCR_X_SIZE_t*) 0x402B1360UL)
#define CYREG_AXI_DMAC_CH3_DESCR_X_INCR ((volatile un_AXI_DMAC_CH_DESCR_X_INCR_t*) 0x402B1364UL)
#define CYREG_AXI_DMAC_CH3_DESCR_Y_SIZE ((volatile un_AXI_DMAC_CH_DESCR_Y_SIZE_t*) 0x402B1368UL)
#define CYREG_AXI_DMAC_CH3_DESCR_Y_INCR ((volatile un_AXI_DMAC_CH_DESCR_Y_INCR_t*) 0x402B136CUL)
#define CYREG_AXI_DMAC_CH3_DESCR_NEXT   ((volatile un_AXI_DMAC_CH_DESCR_NEXT_t*) 0x402B1370UL)
#define CYREG_AXI_DMAC_CH3_INTR         ((volatile un_AXI_DMAC_CH_INTR_t*) 0x402B1380UL)
#define CYREG_AXI_DMAC_CH3_INTR_SET     ((volatile un_AXI_DMAC_CH_INTR_SET_t*) 0x402B1384UL)
#define CYREG_AXI_DMAC_CH3_INTR_MASK    ((volatile un_AXI_DMAC_CH_INTR_MASK_t*) 0x402B1388UL)
#define CYREG_AXI_DMAC_CH3_INTR_MASKED  ((volatile un_AXI_DMAC_CH_INTR_MASKED_t*) 0x402B138CUL)

/**
  * \brief AXI DMA controller channel (AXI_DMAC_CH4)
  */
#define CYREG_AXI_DMAC_CH4_CTL          ((volatile un_AXI_DMAC_CH_CTL_t*) 0x402B1400UL)
#define CYREG_AXI_DMAC_CH4_STATUS       ((volatile un_AXI_DMAC_CH_STATUS_t*) 0x402B1404UL)
#define CYREG_AXI_DMAC_CH4_IDX          ((volatile un_AXI_DMAC_CH_IDX_t*) 0x402B1410UL)
#define CYREG_AXI_DMAC_CH4_SRC          ((volatile un_AXI_DMAC_CH_SRC_t*) 0x402B1414UL)
#define CYREG_AXI_DMAC_CH4_DST          ((volatile un_AXI_DMAC_CH_DST_t*) 0x402B1418UL)
#define CYREG_AXI_DMAC_CH4_M_IDX        ((volatile un_AXI_DMAC_CH_M_IDX_t*) 0x402B141CUL)
#define CYREG_AXI_DMAC_CH4_CURR         ((volatile un_AXI_DMAC_CH_CURR_t*) 0x402B1420UL)
#define CYREG_AXI_DMAC_CH4_TR_CMD       ((volatile un_AXI_DMAC_CH_TR_CMD_t*) 0x402B1428UL)
#define CYREG_AXI_DMAC_CH4_DESCR_STATUS ((volatile un_AXI_DMAC_CH_DESCR_STATUS_t*) 0x402B1440UL)
#define CYREG_AXI_DMAC_CH4_DESCR_CTL    ((volatile un_AXI_DMAC_CH_DESCR_CTL_t*) 0x402B1450UL)
#define CYREG_AXI_DMAC_CH4_DESCR_SRC    ((volatile un_AXI_DMAC_CH_DESCR_SRC_t*) 0x402B1454UL)
#define CYREG_AXI_DMAC_CH4_DESCR_DST    ((volatile un_AXI_DMAC_CH_DESCR_DST_t*) 0x402B1458UL)
#define CYREG_AXI_DMAC_CH4_DESCR_M_SIZE ((volatile un_AXI_DMAC_CH_DESCR_M_SIZE_t*) 0x402B145CUL)
#define CYREG_AXI_DMAC_CH4_DESCR_X_SIZE ((volatile un_AXI_DMAC_CH_DESCR_X_SIZE_t*) 0x402B1460UL)
#define CYREG_AXI_DMAC_CH4_DESCR_X_INCR ((volatile un_AXI_DMAC_CH_DESCR_X_INCR_t*) 0x402B1464UL)
#define CYREG_AXI_DMAC_CH4_DESCR_Y_SIZE ((volatile un_AXI_DMAC_CH_DESCR_Y_SIZE_t*) 0x402B1468UL)
#define CYREG_AXI_DMAC_CH4_DESCR_Y_INCR ((volatile un_AXI_DMAC_CH_DESCR_Y_INCR_t*) 0x402B146CUL)
#define CYREG_AXI_DMAC_CH4_DESCR_NEXT   ((volatile un_AXI_DMAC_CH_DESCR_NEXT_t*) 0x402B1470UL)
#define CYREG_AXI_DMAC_CH4_INTR         ((volatile un_AXI_DMAC_CH_INTR_t*) 0x402B1480UL)
#define CYREG_AXI_DMAC_CH4_INTR_SET     ((volatile un_AXI_DMAC_CH_INTR_SET_t*) 0x402B1484UL)
#define CYREG_AXI_DMAC_CH4_INTR_MASK    ((volatile un_AXI_DMAC_CH_INTR_MASK_t*) 0x402B1488UL)
#define CYREG_AXI_DMAC_CH4_INTR_MASKED  ((volatile un_AXI_DMAC_CH_INTR_MASKED_t*) 0x402B148CUL)

/**
  * \brief AXI DMA controller channel (AXI_DMAC_CH5)
  */
#define CYREG_AXI_DMAC_CH5_CTL          ((volatile un_AXI_DMAC_CH_CTL_t*) 0x402B1500UL)
#define CYREG_AXI_DMAC_CH5_STATUS       ((volatile un_AXI_DMAC_CH_STATUS_t*) 0x402B1504UL)
#define CYREG_AXI_DMAC_CH5_IDX          ((volatile un_AXI_DMAC_CH_IDX_t*) 0x402B1510UL)
#define CYREG_AXI_DMAC_CH5_SRC          ((volatile un_AXI_DMAC_CH_SRC_t*) 0x402B1514UL)
#define CYREG_AXI_DMAC_CH5_DST          ((volatile un_AXI_DMAC_CH_DST_t*) 0x402B1518UL)
#define CYREG_AXI_DMAC_CH5_M_IDX        ((volatile un_AXI_DMAC_CH_M_IDX_t*) 0x402B151CUL)
#define CYREG_AXI_DMAC_CH5_CURR         ((volatile un_AXI_DMAC_CH_CURR_t*) 0x402B1520UL)
#define CYREG_AXI_DMAC_CH5_TR_CMD       ((volatile un_AXI_DMAC_CH_TR_CMD_t*) 0x402B1528UL)
#define CYREG_AXI_DMAC_CH5_DESCR_STATUS ((volatile un_AXI_DMAC_CH_DESCR_STATUS_t*) 0x402B1540UL)
#define CYREG_AXI_DMAC_CH5_DESCR_CTL    ((volatile un_AXI_DMAC_CH_DESCR_CTL_t*) 0x402B1550UL)
#define CYREG_AXI_DMAC_CH5_DESCR_SRC    ((volatile un_AXI_DMAC_CH_DESCR_SRC_t*) 0x402B1554UL)
#define CYREG_AXI_DMAC_CH5_DESCR_DST    ((volatile un_AXI_DMAC_CH_DESCR_DST_t*) 0x402B1558UL)
#define CYREG_AXI_DMAC_CH5_DESCR_M_SIZE ((volatile un_AXI_DMAC_CH_DESCR_M_SIZE_t*) 0x402B155CUL)
#define CYREG_AXI_DMAC_CH5_DESCR_X_SIZE ((volatile un_AXI_DMAC_CH_DESCR_X_SIZE_t*) 0x402B1560UL)
#define CYREG_AXI_DMAC_CH5_DESCR_X_INCR ((volatile un_AXI_DMAC_CH_DESCR_X_INCR_t*) 0x402B1564UL)
#define CYREG_AXI_DMAC_CH5_DESCR_Y_SIZE ((volatile un_AXI_DMAC_CH_DESCR_Y_SIZE_t*) 0x402B1568UL)
#define CYREG_AXI_DMAC_CH5_DESCR_Y_INCR ((volatile un_AXI_DMAC_CH_DESCR_Y_INCR_t*) 0x402B156CUL)
#define CYREG_AXI_DMAC_CH5_DESCR_NEXT   ((volatile un_AXI_DMAC_CH_DESCR_NEXT_t*) 0x402B1570UL)
#define CYREG_AXI_DMAC_CH5_INTR         ((volatile un_AXI_DMAC_CH_INTR_t*) 0x402B1580UL)
#define CYREG_AXI_DMAC_CH5_INTR_SET     ((volatile un_AXI_DMAC_CH_INTR_SET_t*) 0x402B1584UL)
#define CYREG_AXI_DMAC_CH5_INTR_MASK    ((volatile un_AXI_DMAC_CH_INTR_MASK_t*) 0x402B1588UL)
#define CYREG_AXI_DMAC_CH5_INTR_MASKED  ((volatile un_AXI_DMAC_CH_INTR_MASKED_t*) 0x402B158CUL)

/**
  * \brief AXI DMA controller channel (AXI_DMAC_CH6)
  */
#define CYREG_AXI_DMAC_CH6_CTL          ((volatile un_AXI_DMAC_CH_CTL_t*) 0x402B1600UL)
#define CYREG_AXI_DMAC_CH6_STATUS       ((volatile un_AXI_DMAC_CH_STATUS_t*) 0x402B1604UL)
#define CYREG_AXI_DMAC_CH6_IDX          ((volatile un_AXI_DMAC_CH_IDX_t*) 0x402B1610UL)
#define CYREG_AXI_DMAC_CH6_SRC          ((volatile un_AXI_DMAC_CH_SRC_t*) 0x402B1614UL)
#define CYREG_AXI_DMAC_CH6_DST          ((volatile un_AXI_DMAC_CH_DST_t*) 0x402B1618UL)
#define CYREG_AXI_DMAC_CH6_M_IDX        ((volatile un_AXI_DMAC_CH_M_IDX_t*) 0x402B161CUL)
#define CYREG_AXI_DMAC_CH6_CURR         ((volatile un_AXI_DMAC_CH_CURR_t*) 0x402B1620UL)
#define CYREG_AXI_DMAC_CH6_TR_CMD       ((volatile un_AXI_DMAC_CH_TR_CMD_t*) 0x402B1628UL)
#define CYREG_AXI_DMAC_CH6_DESCR_STATUS ((volatile un_AXI_DMAC_CH_DESCR_STATUS_t*) 0x402B1640UL)
#define CYREG_AXI_DMAC_CH6_DESCR_CTL    ((volatile un_AXI_DMAC_CH_DESCR_CTL_t*) 0x402B1650UL)
#define CYREG_AXI_DMAC_CH6_DESCR_SRC    ((volatile un_AXI_DMAC_CH_DESCR_SRC_t*) 0x402B1654UL)
#define CYREG_AXI_DMAC_CH6_DESCR_DST    ((volatile un_AXI_DMAC_CH_DESCR_DST_t*) 0x402B1658UL)
#define CYREG_AXI_DMAC_CH6_DESCR_M_SIZE ((volatile un_AXI_DMAC_CH_DESCR_M_SIZE_t*) 0x402B165CUL)
#define CYREG_AXI_DMAC_CH6_DESCR_X_SIZE ((volatile un_AXI_DMAC_CH_DESCR_X_SIZE_t*) 0x402B1660UL)
#define CYREG_AXI_DMAC_CH6_DESCR_X_INCR ((volatile un_AXI_DMAC_CH_DESCR_X_INCR_t*) 0x402B1664UL)
#define CYREG_AXI_DMAC_CH6_DESCR_Y_SIZE ((volatile un_AXI_DMAC_CH_DESCR_Y_SIZE_t*) 0x402B1668UL)
#define CYREG_AXI_DMAC_CH6_DESCR_Y_INCR ((volatile un_AXI_DMAC_CH_DESCR_Y_INCR_t*) 0x402B166CUL)
#define CYREG_AXI_DMAC_CH6_DESCR_NEXT   ((volatile un_AXI_DMAC_CH_DESCR_NEXT_t*) 0x402B1670UL)
#define CYREG_AXI_DMAC_CH6_INTR         ((volatile un_AXI_DMAC_CH_INTR_t*) 0x402B1680UL)
#define CYREG_AXI_DMAC_CH6_INTR_SET     ((volatile un_AXI_DMAC_CH_INTR_SET_t*) 0x402B1684UL)
#define CYREG_AXI_DMAC_CH6_INTR_MASK    ((volatile un_AXI_DMAC_CH_INTR_MASK_t*) 0x402B1688UL)
#define CYREG_AXI_DMAC_CH6_INTR_MASKED  ((volatile un_AXI_DMAC_CH_INTR_MASKED_t*) 0x402B168CUL)

/**
  * \brief AXI DMA controller channel (AXI_DMAC_CH7)
  */
#define CYREG_AXI_DMAC_CH7_CTL          ((volatile un_AXI_DMAC_CH_CTL_t*) 0x402B1700UL)
#define CYREG_AXI_DMAC_CH7_STATUS       ((volatile un_AXI_DMAC_CH_STATUS_t*) 0x402B1704UL)
#define CYREG_AXI_DMAC_CH7_IDX          ((volatile un_AXI_DMAC_CH_IDX_t*) 0x402B1710UL)
#define CYREG_AXI_DMAC_CH7_SRC          ((volatile un_AXI_DMAC_CH_SRC_t*) 0x402B1714UL)
#define CYREG_AXI_DMAC_CH7_DST          ((volatile un_AXI_DMAC_CH_DST_t*) 0x402B1718UL)
#define CYREG_AXI_DMAC_CH7_M_IDX        ((volatile un_AXI_DMAC_CH_M_IDX_t*) 0x402B171CUL)
#define CYREG_AXI_DMAC_CH7_CURR         ((volatile un_AXI_DMAC_CH_CURR_t*) 0x402B1720UL)
#define CYREG_AXI_DMAC_CH7_TR_CMD       ((volatile un_AXI_DMAC_CH_TR_CMD_t*) 0x402B1728UL)
#define CYREG_AXI_DMAC_CH7_DESCR_STATUS ((volatile un_AXI_DMAC_CH_DESCR_STATUS_t*) 0x402B1740UL)
#define CYREG_AXI_DMAC_CH7_DESCR_CTL    ((volatile un_AXI_DMAC_CH_DESCR_CTL_t*) 0x402B1750UL)
#define CYREG_AXI_DMAC_CH7_DESCR_SRC    ((volatile un_AXI_DMAC_CH_DESCR_SRC_t*) 0x402B1754UL)
#define CYREG_AXI_DMAC_CH7_DESCR_DST    ((volatile un_AXI_DMAC_CH_DESCR_DST_t*) 0x402B1758UL)
#define CYREG_AXI_DMAC_CH7_DESCR_M_SIZE ((volatile un_AXI_DMAC_CH_DESCR_M_SIZE_t*) 0x402B175CUL)
#define CYREG_AXI_DMAC_CH7_DESCR_X_SIZE ((volatile un_AXI_DMAC_CH_DESCR_X_SIZE_t*) 0x402B1760UL)
#define CYREG_AXI_DMAC_CH7_DESCR_X_INCR ((volatile un_AXI_DMAC_CH_DESCR_X_INCR_t*) 0x402B1764UL)
#define CYREG_AXI_DMAC_CH7_DESCR_Y_SIZE ((volatile un_AXI_DMAC_CH_DESCR_Y_SIZE_t*) 0x402B1768UL)
#define CYREG_AXI_DMAC_CH7_DESCR_Y_INCR ((volatile un_AXI_DMAC_CH_DESCR_Y_INCR_t*) 0x402B176CUL)
#define CYREG_AXI_DMAC_CH7_DESCR_NEXT   ((volatile un_AXI_DMAC_CH_DESCR_NEXT_t*) 0x402B1770UL)
#define CYREG_AXI_DMAC_CH7_INTR         ((volatile un_AXI_DMAC_CH_INTR_t*) 0x402B1780UL)
#define CYREG_AXI_DMAC_CH7_INTR_SET     ((volatile un_AXI_DMAC_CH_INTR_SET_t*) 0x402B1784UL)
#define CYREG_AXI_DMAC_CH7_INTR_MASK    ((volatile un_AXI_DMAC_CH_INTR_MASK_t*) 0x402B1788UL)
#define CYREG_AXI_DMAC_CH7_INTR_MASKED  ((volatile un_AXI_DMAC_CH_INTR_MASKED_t*) 0x402B178CUL)

/**
  * \brief AXI DMAC (AXI_DMAC0)
  */
#define CYREG_AXI_DMAC_CTL              ((volatile un_AXI_DMAC_CTL_t*) 0x402B0000UL)
#define CYREG_AXI_DMAC_STATUS           ((volatile un_AXI_DMAC_STATUS_t*) 0x402B0004UL)
#define CYREG_AXI_DMAC_ACTIVE_SEC       ((volatile un_AXI_DMAC_ACTIVE_SEC_t*) 0x402B0008UL)
#define CYREG_AXI_DMAC_ACTIVE_NONSEC    ((volatile un_AXI_DMAC_ACTIVE_NONSEC_t*) 0x402B000CUL)

#endif /* _CYREG_AXI_DMAC_H_ */


/* [] END OF FILE */
