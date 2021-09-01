/***************************************************************************//**
* \file cyip_lpddr4.h
*
* \brief
* LPDDR4 IP definitions
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

#ifndef _CYIP_LPDDR4_H_
#define _CYIP_LPDDR4_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    LPDDR4
*******************************************************************************/

#define LPDDR4_LPDDR4_WRAPPER_SECTION_SIZE      0x00000200UL
#define LPDDR4_AXI_PERF_CNT_MU_SECTION_SIZE     0x00000040UL
#define LPDDR4_AXI_PERF_CNT_SECTION_SIZE        0x00000400UL
#define LPDDR4_LPDDR4_CORE_SECTION_SIZE         0x00001000UL
#define LPDDR4_EMPU_EMPU_STRUCT_SECTION_SIZE    0x00000040UL
#define LPDDR4_EMPU_SECTION_SIZE                0x00004000UL
#define LPDDR4_SECTION_SIZE                     0x00008000UL

/**
  * \brief Control (LPDDR4_LPDDR4_WRAPPER_CTL)
  */
typedef struct stc_LPDDR4_LPDDR4_WRAPPER_CTL_field {
  uint32_t                         :31;
  uint32_t                         u1ENABLED:1;
} stc_LPDDR4_LPDDR4_WRAPPER_CTL_field_t;

typedef union un_LPDDR4_LPDDR4_WRAPPER_CTL {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_WRAPPER_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_WRAPPER_CTL_t;

/**
  * \brief 800MHz PLL Control Register (LPDDR4_LPDDR4_WRAPPER_PLL800_CLOCK_CTL)
  */
typedef struct stc_LPDDR4_LPDDR4_WRAPPER_PLL800_CLOCK_CTL_field {
  uint32_t                         u1ENABLE:1;
  uint32_t                         u1OUTPUT_ENABLE:1;
  uint32_t                         :30;
} stc_LPDDR4_LPDDR4_WRAPPER_PLL800_CLOCK_CTL_field_t;

typedef union un_LPDDR4_LPDDR4_WRAPPER_PLL800_CLOCK_CTL {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_WRAPPER_PLL800_CLOCK_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_WRAPPER_PLL800_CLOCK_CTL_t;

/**
  * \brief 800MHz PLL Configuration Register (LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG)
  */
typedef struct stc_LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_field {
  uint32_t                         u8FEEDBACK_DIV:8;
  uint32_t                         u5REFERENCE_DIV:5;
  uint32_t                         :3;
  uint32_t                         u5OUTPUT_DIV:5;
  uint32_t                         :1;
  uint32_t                         u2VCO_CLK_SEL:2;
  uint32_t                         :1;
  uint32_t                         u2LOCK_DELAY:2;
  uint32_t                         :1;
  uint32_t                         u2WAIT_TIME:2;
  uint32_t                         :2;
} stc_LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_field_t;

typedef union un_LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_t;

/**
  * \brief 800MHz PLL Configuration Register 2 (SSCG) (LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2)
  */
typedef struct stc_LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2_field {
  uint32_t                         u10SSCG_DEPTH:10;
  uint32_t                         :6;
  uint32_t                         u3SSCG_RATE:3;
  uint32_t                         :9;
  uint32_t                         u1SSCG_MODE:1;
  uint32_t                         :2;
  uint32_t                         u1SSCG_EN:1;
} stc_LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2_field_t;

typedef union un_LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2_t;

/**
  * \brief 800MHz PLL Status Register (LPDDR4_LPDDR4_WRAPPER_PLL800_STATUS)
  */
typedef struct stc_LPDDR4_LPDDR4_WRAPPER_PLL800_STATUS_field {
  uint32_t                         u1LOCKED:1;
  uint32_t                         u1UNLOCK_OCCURRED:1;
  uint32_t                         :30;
} stc_LPDDR4_LPDDR4_WRAPPER_PLL800_STATUS_field_t;

typedef union un_LPDDR4_LPDDR4_WRAPPER_PLL800_STATUS {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_WRAPPER_PLL800_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_WRAPPER_PLL800_STATUS_t;

/**
  * \brief QoS Configuration Register for CPUSS master (LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS)
  */
typedef struct stc_LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_field {
  uint32_t                         u2QOS_MASTERID_0:2;
  uint32_t                         u2QOS_MASTERID_1:2;
  uint32_t                         u2QOS_MASTERID_2:2;
  uint32_t                         u2QOS_MASTERID_3:2;
  uint32_t                         u2QOS_MASTERID_4:2;
  uint32_t                         u2QOS_MASTERID_5:2;
  uint32_t                         u2QOS_MASTERID_6:2;
  uint32_t                         u2QOS_MASTERID_7:2;
  uint32_t                         u2QOS_MASTERID_8:2;
  uint32_t                         u2QOS_MASTERID_9:2;
  uint32_t                         u2QOS_MASTERID_10:2;
  uint32_t                         u2QOS_MASTERID_11:2;
  uint32_t                         u2QOS_MASTERID_12:2;
  uint32_t                         u2QOS_MASTERID_13:2;
  uint32_t                         u2QOS_MASTERID_14:2;
  uint32_t                         u2QOS_MASTERID_15:2;
} stc_LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_field_t;

typedef union un_LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_t;

/**
  * \brief QoS Configuration Register for VIDEOSS read master (LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD)
  */
typedef struct stc_LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_field {
  uint32_t                         u2QOS_MASTERID_0:2;
  uint32_t                         u2QOS_MASTERID_1:2;
  uint32_t                         u2QOS_MASTERID_2:2;
  uint32_t                         u2QOS_MASTERID_3:2;
  uint32_t                         u2QOS_MASTERID_4:2;
  uint32_t                         u2QOS_MASTERID_5:2;
  uint32_t                         u2QOS_MASTERID_6:2;
  uint32_t                         u2QOS_MASTERID_7:2;
  uint32_t                         u2QOS_MASTERID_8:2;
  uint32_t                         u2QOS_MASTERID_9:2;
  uint32_t                         u2QOS_MASTERID_10:2;
  uint32_t                         u2QOS_MASTERID_11:2;
  uint32_t                         u2QOS_MASTERID_12:2;
  uint32_t                         u2QOS_MASTERID_13:2;
  uint32_t                         u2QOS_MASTERID_14:2;
  uint32_t                         u2QOS_MASTERID_15:2;
} stc_LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_field_t;

typedef union un_LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_t;

/**
  * \brief QoS Configuration Register for VIDEOSS write master (LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR)
  */
typedef struct stc_LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_field {
  uint32_t                         u2QOS_MASTERID_0:2;
  uint32_t                         u2QOS_MASTERID_1:2;
  uint32_t                         u2QOS_MASTERID_2:2;
  uint32_t                         u2QOS_MASTERID_3:2;
  uint32_t                         u2QOS_MASTERID_4:2;
  uint32_t                         u2QOS_MASTERID_5:2;
  uint32_t                         u2QOS_MASTERID_6:2;
  uint32_t                         u2QOS_MASTERID_7:2;
  uint32_t                         u2QOS_MASTERID_8:2;
  uint32_t                         u2QOS_MASTERID_9:2;
  uint32_t                         u2QOS_MASTERID_10:2;
  uint32_t                         u2QOS_MASTERID_11:2;
  uint32_t                         u2QOS_MASTERID_12:2;
  uint32_t                         u2QOS_MASTERID_13:2;
  uint32_t                         u2QOS_MASTERID_14:2;
  uint32_t                         u2QOS_MASTERID_15:2;
} stc_LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_field_t;

typedef union un_LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_t;



/**
  * \brief Timer control (LPDDR4_AXI_PERF_CNT_MU_TMR_CTL)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT_MU_TMR_CTL_field {
  uint32_t                         u28TMR:28;
  uint32_t                         u4PSC:4;
} stc_LPDDR4_AXI_PERF_CNT_MU_TMR_CTL_field_t;

typedef union un_LPDDR4_AXI_PERF_CNT_MU_TMR_CTL {
  uint32_t                         u32Register;
  stc_LPDDR4_AXI_PERF_CNT_MU_TMR_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_AXI_PERF_CNT_MU_TMR_CTL_t;

/**
  * \brief Timer status (LPDDR4_AXI_PERF_CNT_MU_TMR_STATUS)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT_MU_TMR_STATUS_field {
  uint32_t                         u28TMR:28;
  uint32_t                         :3;
  uint32_t                         u1MEAS:1;
} stc_LPDDR4_AXI_PERF_CNT_MU_TMR_STATUS_field_t;

typedef union un_LPDDR4_AXI_PERF_CNT_MU_TMR_STATUS {
  uint32_t                         u32Register;
  stc_LPDDR4_AXI_PERF_CNT_MU_TMR_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_AXI_PERF_CNT_MU_TMR_STATUS_t;

/**
  * \brief AXI port select (LPDDR4_AXI_PERF_CNT_MU_PORT_SELECT)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT_MU_PORT_SELECT_field {
  uint32_t                         u3SELECT:3;
  uint32_t                         :29;
} stc_LPDDR4_AXI_PERF_CNT_MU_PORT_SELECT_field_t;

typedef union un_LPDDR4_AXI_PERF_CNT_MU_PORT_SELECT {
  uint32_t                         u32Register;
  stc_LPDDR4_AXI_PERF_CNT_MU_PORT_SELECT_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_AXI_PERF_CNT_MU_PORT_SELECT_t;

/**
  * \brief Transaction filter (LPDDR4_AXI_PERF_CNT_MU_FILTER)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT_MU_FILTER_field {
  uint32_t                         u4MID:4;
  uint32_t                         :4;
  uint32_t                         u8TID:8;
  uint32_t                         :7;
  uint32_t                         u1WRITE:1;
  uint32_t                         u4LEN_MIN:4;
  uint32_t                         u4LEN_MAX:4;
} stc_LPDDR4_AXI_PERF_CNT_MU_FILTER_field_t;

typedef union un_LPDDR4_AXI_PERF_CNT_MU_FILTER {
  uint32_t                         u32Register;
  stc_LPDDR4_AXI_PERF_CNT_MU_FILTER_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_AXI_PERF_CNT_MU_FILTER_t;

/**
  * \brief Transaction filter mask (LPDDR4_AXI_PERF_CNT_MU_FILTER_MASK)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT_MU_FILTER_MASK_field {
  uint32_t                         u4MID:4;
  uint32_t                         :4;
  uint32_t                         u8TID:8;
  uint32_t                         :16;
} stc_LPDDR4_AXI_PERF_CNT_MU_FILTER_MASK_field_t;

typedef union un_LPDDR4_AXI_PERF_CNT_MU_FILTER_MASK {
  uint32_t                         u32Register;
  stc_LPDDR4_AXI_PERF_CNT_MU_FILTER_MASK_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_AXI_PERF_CNT_MU_FILTER_MASK_t;

/**
  * \brief Accumulated outstanding transactions (LPDDR4_AXI_PERF_CNT_MU_OT_AC)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT_MU_OT_AC_field {
  uint32_t                         u32CNT:32;
} stc_LPDDR4_AXI_PERF_CNT_MU_OT_AC_field_t;

typedef union un_LPDDR4_AXI_PERF_CNT_MU_OT_AC {
  uint32_t                         u32Register;
  stc_LPDDR4_AXI_PERF_CNT_MU_OT_AC_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_AXI_PERF_CNT_MU_OT_AC_t;

/**
  * \brief Address transfer counter (LPDDR4_AXI_PERF_CNT_MU_ADDR_CNT)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT_MU_ADDR_CNT_field {
  uint32_t                         u32CNT:32;
} stc_LPDDR4_AXI_PERF_CNT_MU_ADDR_CNT_field_t;

typedef union un_LPDDR4_AXI_PERF_CNT_MU_ADDR_CNT {
  uint32_t                         u32Register;
  stc_LPDDR4_AXI_PERF_CNT_MU_ADDR_CNT_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_AXI_PERF_CNT_MU_ADDR_CNT_t;

/**
  * \brief Address stall counter (LPDDR4_AXI_PERF_CNT_MU_ADDR_STALL_CNT)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT_MU_ADDR_STALL_CNT_field {
  uint32_t                         u32CNT:32;
} stc_LPDDR4_AXI_PERF_CNT_MU_ADDR_STALL_CNT_field_t;

typedef union un_LPDDR4_AXI_PERF_CNT_MU_ADDR_STALL_CNT {
  uint32_t                         u32Register;
  stc_LPDDR4_AXI_PERF_CNT_MU_ADDR_STALL_CNT_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_AXI_PERF_CNT_MU_ADDR_STALL_CNT_t;

/**
  * \brief Data transfer counter (LPDDR4_AXI_PERF_CNT_MU_DATA_CNT)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT_MU_DATA_CNT_field {
  uint32_t                         u32CNT:32;
} stc_LPDDR4_AXI_PERF_CNT_MU_DATA_CNT_field_t;

typedef union un_LPDDR4_AXI_PERF_CNT_MU_DATA_CNT {
  uint32_t                         u32Register;
  stc_LPDDR4_AXI_PERF_CNT_MU_DATA_CNT_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_AXI_PERF_CNT_MU_DATA_CNT_t;

/**
  * \brief Data stall counter (LPDDR4_AXI_PERF_CNT_MU_DATA_STALL_CNT)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT_MU_DATA_STALL_CNT_field {
  uint32_t                         u32CNT:32;
} stc_LPDDR4_AXI_PERF_CNT_MU_DATA_STALL_CNT_field_t;

typedef union un_LPDDR4_AXI_PERF_CNT_MU_DATA_STALL_CNT {
  uint32_t                         u32Register;
  stc_LPDDR4_AXI_PERF_CNT_MU_DATA_STALL_CNT_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_AXI_PERF_CNT_MU_DATA_STALL_CNT_t;



/**
  * \brief Control (LPDDR4_AXI_PERF_CNT_CTL)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT_CTL_field {
  uint32_t                         :31;
  uint32_t                         u1ENABLED:1;
} stc_LPDDR4_AXI_PERF_CNT_CTL_field_t;

typedef union un_LPDDR4_AXI_PERF_CNT_CTL {
  uint32_t                         u32Register;
  stc_LPDDR4_AXI_PERF_CNT_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_AXI_PERF_CNT_CTL_t;

/**
  * \brief Timer command (LPDDR4_AXI_PERF_CNT_TMR_CMD)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT_TMR_CMD_field {
  uint32_t                         u1START:1;
  uint32_t                         :7;
  uint32_t                         u1STOP:1;
  uint32_t                         :23;
} stc_LPDDR4_AXI_PERF_CNT_TMR_CMD_field_t;

typedef union un_LPDDR4_AXI_PERF_CNT_TMR_CMD {
  uint32_t                         u32Register;
  stc_LPDDR4_AXI_PERF_CNT_TMR_CMD_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_AXI_PERF_CNT_TMR_CMD_t;



/**
  * \brief User Command Interface (LPDDR4_LPDDR4_CORE_UCI)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_UCI_field {
  uint32_t                         u4CMD_OP:4;
  uint32_t                         u2CMD_CHAN:2;
  uint32_t                         u6MR_SEL:6;
  uint32_t                         u8MR_OP:8;
  uint32_t                         :12;
} stc_LPDDR4_LPDDR4_CORE_UCI_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_UCI {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_UCI_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_UCI_t;

/**
  * \brief Dynamo Control Register (LPDDR4_LPDDR4_CORE_DMCTL)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DMCTL_field {
  uint32_t                         u3DDRT:3;
  uint32_t                         u2DFI_FREQ_RATIO:2;
  uint32_t                         u2DRAM_BANK_EN:2;
  uint32_t                         u1SWITCH_CLOSE:1;
  uint32_t                         u1BANK_POLICY:1;
  uint32_t                         u1WR_DBI:1;
  uint32_t                         u1RD_DBI:1;
  uint32_t                         :21;
} stc_LPDDR4_LPDDR4_CORE_DMCTL_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DMCTL {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DMCTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DMCTL_t;

/**
  * \brief Dynamo Configuration Register (LPDDR4_LPDDR4_CORE_DMCFG)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DMCFG_field {
  uint32_t                         u1REF_POST_PULL_EN:1;
  uint32_t                         u1INT_GC_FSM_EN:1;
  uint32_t                         u1INT_GC_FSM_CLR:1;
  uint32_t                         u1INT_ECC_EN:1;
  uint32_t                         u3REQ_TH:3;
  uint32_t                         u1ZQ_AUTO_EN:1;
  uint32_t                         u1INLINE_ECC_EN:1;
  uint32_t                         :23;
} stc_LPDDR4_LPDDR4_CORE_DMCFG_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DMCFG {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DMCFG_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DMCFG_t;

/**
  * \brief LPDDR Mode Register 1 (LPDDR4_LPDDR4_CORE_LPMR1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_LPMR1_field {
  uint32_t                         u2FS0_BL:2;
  uint32_t                         u1FS0_WPRE:1;
  uint32_t                         u1FS0_RPRE:1;
  uint32_t                         u3FS0_NWR:3;
  uint32_t                         u1FS0_RPST:1;
  uint32_t                         u2FS1_BL:2;
  uint32_t                         u1FS1_WPRE:1;
  uint32_t                         u1FS1_RPRE:1;
  uint32_t                         u3FS1_NWR:3;
  uint32_t                         u1FS1_RPST:1;
  uint32_t                         :16;
} stc_LPDDR4_LPDDR4_CORE_LPMR1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_LPMR1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_LPMR1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_LPMR1_t;

/**
  * \brief LPDDR Mode Register 2 (LPDDR4_LPDDR4_CORE_LPMR2)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_LPMR2_field {
  uint32_t                         u3FS0_RL:3;
  uint32_t                         u3FS0_WL:3;
  uint32_t                         u1FS0_WLS:1;
  uint32_t                         u1WRLEV:1;
  uint32_t                         u3FS1_RL:3;
  uint32_t                         u3FS1_WL:3;
  uint32_t                         u1FS1_WLS:1;
  uint32_t                         :17;
} stc_LPDDR4_LPDDR4_CORE_LPMR2_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_LPMR2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_LPMR2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_LPMR2_t;

/**
  * \brief LPDDR Mode Register 3 (LPDDR4_LPDDR4_CORE_LPMR3)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_LPMR3_field {
  uint32_t                         u1FS0_PUCAL:1;
  uint32_t                         u1FS0_WPST:1;
  uint32_t                         u1PPRP:1;
  uint32_t                         u3FS0_PDDS:3;
  uint32_t                         u1FS0_RDBI:1;
  uint32_t                         u1FS0_WDBI:1;
  uint32_t                         u1FS1_PUCAL:1;
  uint32_t                         u1FS1_WPST:1;
  uint32_t                         u3FS1_PDDS:3;
  uint32_t                         u1FS1_RDBI:1;
  uint32_t                         u1FS1_WDBI:1;
  uint32_t                         :17;
} stc_LPDDR4_LPDDR4_CORE_LPMR3_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_LPMR3 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_LPMR3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_LPMR3_t;

/**
  * \brief LPDDR Mode Register 11 (LPDDR4_LPDDR4_CORE_LPMR11)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_LPMR11_field {
  uint32_t                         u3FS0_DQODT:3;
  uint32_t                         u3FS0_CAODT:3;
  uint32_t                         u3FS1_DQODT:3;
  uint32_t                         u3FS1_CAODT:3;
  uint32_t                         :20;
} stc_LPDDR4_LPDDR4_CORE_LPMR11_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_LPMR11 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_LPMR11_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_LPMR11_t;

/**
  * \brief LPDDR Mode Register 12 (LPDDR4_LPDDR4_CORE_LPMR12)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_LPMR12_field {
  uint32_t                         u6FS0_VREFCAS:6;
  uint32_t                         u1FS0_VREFCAR:1;
  uint32_t                         u6FS1_VREFCAS:6;
  uint32_t                         u1FS1_VREFCAR:1;
  uint32_t                         :18;
} stc_LPDDR4_LPDDR4_CORE_LPMR12_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_LPMR12 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_LPMR12_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_LPMR12_t;

/**
  * \brief LPDDR Mode Register 13 (LPDDR4_LPDDR4_CORE_LPMR13)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_LPMR13_field {
  uint32_t                         u1CBT:1;
  uint32_t                         u1RPT:1;
  uint32_t                         u1VRO:1;
  uint32_t                         u1VRCG:1;
  uint32_t                         u1RRO:1;
  uint32_t                         u1DMD:1;
  uint32_t                         u1FSPWR:1;
  uint32_t                         u1FSPOP:1;
  uint32_t                         :24;
} stc_LPDDR4_LPDDR4_CORE_LPMR13_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_LPMR13 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_LPMR13_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_LPMR13_t;

/**
  * \brief LPDDR Mode Register 14 (LPDDR4_LPDDR4_CORE_LPMR14)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_LPMR14_field {
  uint32_t                         u6FS0_VREFDQS:6;
  uint32_t                         u1FS0_VREFDQR:1;
  uint32_t                         u6FS1_VREFDQS:6;
  uint32_t                         u1FS1_VREFDQR:1;
  uint32_t                         :18;
} stc_LPDDR4_LPDDR4_CORE_LPMR14_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_LPMR14 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_LPMR14_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_LPMR14_t;

/**
  * \brief LPDDR Mode Register 22 (LPDDR4_LPDDR4_CORE_LPMR22)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_LPMR22_field {
  uint32_t                         u3FS0_SOCODT:3;
  uint32_t                         u1FS0_ODTECK:1;
  uint32_t                         u1FS0_ODTECS:1;
  uint32_t                         u1FS0_ODTDCA:1;
  uint32_t                         u2ODTDX8:2;
  uint32_t                         u3FS1_SOCODT:3;
  uint32_t                         u1FS1_ODTECK:1;
  uint32_t                         u1FS1_ODTECS:1;
  uint32_t                         u1FS1_ODTDCA:1;
  uint32_t                         :18;
} stc_LPDDR4_LPDDR4_CORE_LPMR22_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_LPMR22 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_LPMR22_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_LPMR22_t;

/**
  * \brief Route Configuration 0 - Route 0 (LPDDR4_LPDDR4_CORE_RTCFG0_RT0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_RTCFG0_RT0_field {
  uint32_t                         u1EXT_PRI:1;
  uint32_t                         u1MAX_PRI:1;
  uint32_t                         u4ARQ_LVL_HI:4;
  uint32_t                         u4ARQ_LVL_LO:4;
  uint32_t                         u4AWQ_LVL_HI:4;
  uint32_t                         u4AWQ_LVL_LO:4;
  uint32_t                         u1ARQ_LAT_BARRIER_EN:1;
  uint32_t                         u1AWQ_LAT_BARRIER_EN:1;
  uint32_t                         u1ARQ_OOO_EN:1;
  uint32_t                         u1AWQ_OOO_EN:1;
  uint32_t                         u1ACQ_REALTIME_EN:1;
  uint32_t                         u1WM_ENABLE:1;
  uint32_t                         :8;
} stc_LPDDR4_LPDDR4_CORE_RTCFG0_RT0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_RTCFG0_RT0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_RTCFG0_RT0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_RTCFG0_RT0_t;

/**
  * \brief Route Configuration 0 - Route 1 (LPDDR4_LPDDR4_CORE_RTCFG0_RT1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_RTCFG0_RT1_field {
  uint32_t                         u1EXT_PRI:1;
  uint32_t                         u1MAX_PRI:1;
  uint32_t                         u4ARQ_LVL_HI:4;
  uint32_t                         u4ARQ_LVL_LO:4;
  uint32_t                         u4AWQ_LVL_HI:4;
  uint32_t                         u4AWQ_LVL_LO:4;
  uint32_t                         u1ARQ_LAT_BARRIER_EN:1;
  uint32_t                         u1AWQ_LAT_BARRIER_EN:1;
  uint32_t                         u1ARQ_OOO_EN:1;
  uint32_t                         u1AWQ_OOO_EN:1;
  uint32_t                         u1ACQ_REALTIME_EN:1;
  uint32_t                         u1WM_ENABLE:1;
  uint32_t                         :8;
} stc_LPDDR4_LPDDR4_CORE_RTCFG0_RT1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_RTCFG0_RT1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_RTCFG0_RT1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_RTCFG0_RT1_t;

/**
  * \brief Route Configuration 0 - Route 2 (LPDDR4_LPDDR4_CORE_RTCFG0_RT2)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_RTCFG0_RT2_field {
  uint32_t                         u1EXT_PRI:1;
  uint32_t                         u1MAX_PRI:1;
  uint32_t                         u4ARQ_LVL_HI:4;
  uint32_t                         u4ARQ_LVL_LO:4;
  uint32_t                         u4AWQ_LVL_HI:4;
  uint32_t                         u4AWQ_LVL_LO:4;
  uint32_t                         u1ARQ_LAT_BARRIER_EN:1;
  uint32_t                         u1AWQ_LAT_BARRIER_EN:1;
  uint32_t                         u1ARQ_OOO_EN:1;
  uint32_t                         u1AWQ_OOO_EN:1;
  uint32_t                         u1ACQ_REALTIME_EN:1;
  uint32_t                         u1WM_ENABLE:1;
  uint32_t                         :8;
} stc_LPDDR4_LPDDR4_CORE_RTCFG0_RT2_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_RTCFG0_RT2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_RTCFG0_RT2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_RTCFG0_RT2_t;

/**
  * \brief Route Configuration 0 - Route 3 (LPDDR4_LPDDR4_CORE_RTCFG0_RT3)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_RTCFG0_RT3_field {
  uint32_t                         u1EXT_PRI:1;
  uint32_t                         u1MAX_PRI:1;
  uint32_t                         u4ARQ_LVL_HI:4;
  uint32_t                         u4ARQ_LVL_LO:4;
  uint32_t                         u4AWQ_LVL_HI:4;
  uint32_t                         u4AWQ_LVL_LO:4;
  uint32_t                         u1ARQ_LAT_BARRIER_EN:1;
  uint32_t                         u1AWQ_LAT_BARRIER_EN:1;
  uint32_t                         u1ARQ_OOO_EN:1;
  uint32_t                         u1AWQ_OOO_EN:1;
  uint32_t                         u1ACQ_REALTIME_EN:1;
  uint32_t                         u1WM_ENABLE:1;
  uint32_t                         :8;
} stc_LPDDR4_LPDDR4_CORE_RTCFG0_RT3_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_RTCFG0_RT3 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_RTCFG0_RT3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_RTCFG0_RT3_t;

/**
  * \brief Route Configuration 1 - Route 0 (LPDDR4_LPDDR4_CORE_RTCFG1_RT0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_RTCFG1_RT0_field {
  uint32_t                         u8ARQ_LAT_BARRIER:8;
  uint32_t                         u8AWQ_LAT_BARRIER:8;
  uint32_t                         u8ARQ_STARV_TH:8;
  uint32_t                         u8AWQ_STARV_TH:8;
} stc_LPDDR4_LPDDR4_CORE_RTCFG1_RT0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_RTCFG1_RT0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_RTCFG1_RT0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_RTCFG1_RT0_t;

/**
  * \brief Route Configuration 1 - Route 1 (LPDDR4_LPDDR4_CORE_RTCFG1_RT1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_RTCFG1_RT1_field {
  uint32_t                         u8ARQ_LAT_BARRIER:8;
  uint32_t                         u8AWQ_LAT_BARRIER:8;
  uint32_t                         u8ARQ_STARV_TH:8;
  uint32_t                         u8AWQ_STARV_TH:8;
} stc_LPDDR4_LPDDR4_CORE_RTCFG1_RT1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_RTCFG1_RT1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_RTCFG1_RT1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_RTCFG1_RT1_t;

/**
  * \brief Route Configuration 1 - Route 2 (LPDDR4_LPDDR4_CORE_RTCFG1_RT2)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_RTCFG1_RT2_field {
  uint32_t                         u8ARQ_LAT_BARRIER:8;
  uint32_t                         u8AWQ_LAT_BARRIER:8;
  uint32_t                         u8ARQ_STARV_TH:8;
  uint32_t                         u8AWQ_STARV_TH:8;
} stc_LPDDR4_LPDDR4_CORE_RTCFG1_RT2_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_RTCFG1_RT2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_RTCFG1_RT2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_RTCFG1_RT2_t;

/**
  * \brief Route Configuration 1 - Route 3 (LPDDR4_LPDDR4_CORE_RTCFG1_RT3)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_RTCFG1_RT3_field {
  uint32_t                         u8ARQ_LAT_BARRIER:8;
  uint32_t                         u8AWQ_LAT_BARRIER:8;
  uint32_t                         u8ARQ_STARV_TH:8;
  uint32_t                         u8AWQ_STARV_TH:8;
} stc_LPDDR4_LPDDR4_CORE_RTCFG1_RT3_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_RTCFG1_RT3 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_RTCFG1_RT3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_RTCFG1_RT3_t;

/**
  * \brief DRAM Address Register 0 (LPDDR4_LPDDR4_CORE_ADDR0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_ADDR0_field {
  uint32_t                         u5COL_ADDR_MAP_B0:5;
  uint32_t                         u5COL_ADDR_MAP_B1:5;
  uint32_t                         u5COL_ADDR_MAP_B2:5;
  uint32_t                         u5COL_ADDR_MAP_B3:5;
  uint32_t                         u5COL_ADDR_MAP_B4:5;
  uint32_t                         u5COL_ADDR_MAP_B5:5;
  uint32_t                         :2;
} stc_LPDDR4_LPDDR4_CORE_ADDR0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_ADDR0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_ADDR0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_ADDR0_t;

/**
  * \brief DRAM Address Register 1 (LPDDR4_LPDDR4_CORE_ADDR1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_ADDR1_field {
  uint32_t                         u5COL_ADDR_MAP_B6:5;
  uint32_t                         u5COL_ADDR_MAP_B7:5;
  uint32_t                         u5COL_ADDR_MAP_B8:5;
  uint32_t                         u5COL_ADDR_MAP_B9:5;
  uint32_t                         :12;
} stc_LPDDR4_LPDDR4_CORE_ADDR1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_ADDR1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_ADDR1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_ADDR1_t;

/**
  * \brief DRAM Address Register 2 (LPDDR4_LPDDR4_CORE_ADDR2)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_ADDR2_field {
  uint32_t                         u5ROW_ADDR_MAP_B0:5;
  uint32_t                         u5ROW_ADDR_MAP_B1:5;
  uint32_t                         u5ROW_ADDR_MAP_B2:5;
  uint32_t                         u5ROW_ADDR_MAP_B3:5;
  uint32_t                         u5ROW_ADDR_MAP_B4:5;
  uint32_t                         u5ROW_ADDR_MAP_B5:5;
  uint32_t                         :2;
} stc_LPDDR4_LPDDR4_CORE_ADDR2_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_ADDR2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_ADDR2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_ADDR2_t;

/**
  * \brief DRAM Address Register 3 (LPDDR4_LPDDR4_CORE_ADDR3)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_ADDR3_field {
  uint32_t                         u5ROW_ADDR_MAP_B6:5;
  uint32_t                         u5ROW_ADDR_MAP_B7:5;
  uint32_t                         u5ROW_ADDR_MAP_B8:5;
  uint32_t                         u5ROW_ADDR_MAP_B9:5;
  uint32_t                         u5ROW_ADDR_MAP_B10:5;
  uint32_t                         u5ROW_ADDR_MAP_B11:5;
  uint32_t                         :2;
} stc_LPDDR4_LPDDR4_CORE_ADDR3_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_ADDR3 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_ADDR3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_ADDR3_t;

/**
  * \brief DRAM Address Register 4 (LPDDR4_LPDDR4_CORE_ADDR4)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_ADDR4_field {
  uint32_t                         u5ROW_ADDR_MAP_B12:5;
  uint32_t                         u5ROW_ADDR_MAP_B13:5;
  uint32_t                         u5ROW_ADDR_MAP_B14:5;
  uint32_t                         :17;
} stc_LPDDR4_LPDDR4_CORE_ADDR4_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_ADDR4 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_ADDR4_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_ADDR4_t;

/**
  * \brief DRAM Address Register 5 (LPDDR4_LPDDR4_CORE_ADDR5)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_ADDR5_field {
  uint32_t                         u5BANK_ADDR_MAP_B0:5;
  uint32_t                         u5BANK_ADDR_MAP_B1:5;
  uint32_t                         u5BANK_ADDR_MAP_B2:5;
  uint32_t                         u5CHAN_ADDR_MAP_B0:5;
  uint32_t                         :12;
} stc_LPDDR4_LPDDR4_CORE_ADDR5_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_ADDR5 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_ADDR5_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_ADDR5_t;

/**
  * \brief PHY Register (LPDDR4_LPDDR4_CORE_PHY)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PHY_field {
  uint32_t                         u1DTI_DRAM_CLK_DIS:1;
  uint32_t                         u4DTI_DATA_BYTE_DIS:4;
  uint32_t                         :27;
} stc_LPDDR4_LPDDR4_CORE_PHY_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PHY {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PHY_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PHY_t;

/**
  * \brief PHY Operation Mode Register (LPDDR4_LPDDR4_CORE_POM)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_POM_field {
  uint32_t                         u2POM_CHANEN:2;
  uint32_t                         u1POM_DFIEN:1;
  uint32_t                         u1POM_PROC:1;
  uint32_t                         u1POM_PHYSETEN:1;
  uint32_t                         u1POM_PHYFSEN:1;
  uint32_t                         u1POM_PHYINIT:1;
  uint32_t                         u1POM_DLLRSTEN:1;
  uint32_t                         u1POM_DRAMINITEN:1;
  uint32_t                         u1POM_VREFDQRDEN:1;
  uint32_t                         u1POM_VREFCAEN:1;
  uint32_t                         u1POM_GTEN:1;
  uint32_t                         u1POM_WRLVLEN:1;
  uint32_t                         u1POM_RDLVLEN:1;
  uint32_t                         u1POM_VREFDQWREN:1;
  uint32_t                         u1POM_DLYEVALEN:1;
  uint32_t                         u1POM_SANCHKEN:1;
  uint32_t                         u1POM_FS:1;
  uint32_t                         u1POM_CLKLOCKEN:1;
  uint32_t                         u1POM_CMDDLYEN:1;
  uint32_t                         u1POM_PWDEXIT:1;
  uint32_t                         u1POM_ODT:1;
  uint32_t                         u1POM_DQSDQEN:1;
  uint32_t                         :9;
} stc_LPDDR4_LPDDR4_CORE_POM_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_POM {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_POM_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_POM_t;

/**
  * \brief DLL Control Register for PHY Command Module - Channel 0 (LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_field {
  uint32_t                         u5LIMIT:5;
  uint32_t                         u1EN:1;
  uint32_t                         u1UPD:1;
  uint32_t                         u1BYP:1;
  uint32_t                         u8BYPC:8;
  uint32_t                         u6CLKDLY:6;
  uint32_t                         :10;
} stc_LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_t;

/**
  * \brief DLL Control Register for PHY Command Module - Channel 1 (LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_field {
  uint32_t                         u5LIMIT:5;
  uint32_t                         u1EN:1;
  uint32_t                         u1UPD:1;
  uint32_t                         u1BYP:1;
  uint32_t                         u8BYPC:8;
  uint32_t                         u6CLKDLY:6;
  uint32_t                         :10;
} stc_LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_t;

/**
  * \brief DLL Control Register for PHY Data Module (LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_field {
  uint32_t                         u5LIMIT:5;
  uint32_t                         u1EN:1;
  uint32_t                         u1UPD:1;
  uint32_t                         u1BYP:1;
  uint32_t                         u8BYPC:8;
  uint32_t                         :16;
} stc_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_t;

/**
  * \brief DLL Control Register for PHY Data Module (LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_field {
  uint32_t                         u5LIMIT:5;
  uint32_t                         u1EN:1;
  uint32_t                         u1UPD:1;
  uint32_t                         u1BYP:1;
  uint32_t                         u8BYPC:8;
  uint32_t                         :16;
} stc_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_t;

/**
  * \brief DLL Control Register for PHY Data Module (LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_field {
  uint32_t                         u5LIMIT:5;
  uint32_t                         u1EN:1;
  uint32_t                         u1UPD:1;
  uint32_t                         u1BYP:1;
  uint32_t                         u8BYPC:8;
  uint32_t                         :16;
} stc_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_t;

/**
  * \brief DLL Control Register for PHY Data Module (LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_field {
  uint32_t                         u5LIMIT:5;
  uint32_t                         u1EN:1;
  uint32_t                         u1UPD:1;
  uint32_t                         u1BYP:1;
  uint32_t                         u8BYPC:8;
  uint32_t                         :16;
} stc_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_t;

/**
  * \brief PHY Read Training General Control Register 0 (LPDDR4_LPDDR4_CORE_RTGC0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_RTGC0_field {
  uint32_t                         u1GT_UPDT:1;
  uint32_t                         u1GT_DIS:1;
  uint32_t                         u6FS0_TWREN:6;
  uint32_t                         u6FS0_TRDEN:6;
  uint32_t                         u7FS0_TRDENDBI:7;
  uint32_t                         :11;
} stc_LPDDR4_LPDDR4_CORE_RTGC0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_RTGC0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_RTGC0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_RTGC0_t;

/**
  * \brief PHY Read Training General Control Register 1 (LPDDR4_LPDDR4_CORE_RTGC1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_RTGC1_field {
  uint32_t                         u6FS1_TWREN:6;
  uint32_t                         u6FS1_TRDEN:6;
  uint32_t                         u7FS1_TRDENDBI:7;
  uint32_t                         :13;
} stc_LPDDR4_LPDDR4_CORE_RTGC1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_RTGC1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_RTGC1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_RTGC1_t;

/**
  * \brief PHY Sanity Check Address Register (LPDDR4_LPDDR4_CORE_PTAR)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTAR_field {
  uint32_t                         u3BA:3;
  uint32_t                         u15ROW:15;
  uint32_t                         u10COL:10;
  uint32_t                         :4;
} stc_LPDDR4_LPDDR4_CORE_PTAR_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTAR {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTAR_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTAR_t;

/**
  * \brief PHY VREF Training General Control Register (LPDDR4_LPDDR4_CORE_VTGC)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_VTGC_field {
  uint32_t                         u1IVREFR:1;
  uint32_t                         u8IVREFTS:8;
  uint32_t                         u6VREFDQSW:6;
  uint32_t                         u6VREFCASW:6;
  uint32_t                         u1IVREFEN:1;
  uint32_t                         :10;
} stc_LPDDR4_LPDDR4_CORE_VTGC_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_VTGC {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_VTGC_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_VTGC_t;

/**
  * \brief PHY BIST Control Register (LPDDR4_LPDDR4_CORE_PBCR)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PBCR_field {
  uint32_t                         u1BIST_EN:1;
  uint32_t                         u1BIST_START:1;
  uint32_t                         u1LP_EN:1;
  uint32_t                         u1VREFENCA_C0:1;
  uint32_t                         u6VREFSETCA_C0:6;
  uint32_t                         u1VREFENCA_C1:1;
  uint32_t                         u6VREFSETCA_C1:6;
  uint32_t                         :15;
} stc_LPDDR4_LPDDR4_CORE_PBCR_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PBCR {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PBCR_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PBCR_t;

/**
  * \brief PHY Command Module IO Control Register - Channel 0 (LPDDR4_LPDDR4_CORE_CIOR_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_CIOR_CH0_field {
  uint32_t                         u3DRVSEL:3;
  uint32_t                         u1CMOS_EN:1;
  uint32_t                         u1ODIS_RESETN:1;
  uint32_t                         u1ODIS_ODT:1;
  uint32_t                         u1ODIS_CS:1;
  uint32_t                         u1ODIS_CLK:1;
  uint32_t                         u1ODIS_CKE:1;
  uint32_t                         u6ODIS_CA:6;
  uint32_t                         :17;
} stc_LPDDR4_LPDDR4_CORE_CIOR_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_CIOR_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_CIOR_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_CIOR_CH0_t;

/**
  * \brief PHY Command Module IO Control Register - Channel 1 (LPDDR4_LPDDR4_CORE_CIOR_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_CIOR_CH1_field {
  uint32_t                         u3DRVSEL:3;
  uint32_t                         u1CMOS_EN:1;
  uint32_t                         u1ODIS_RESETN:1;
  uint32_t                         u1ODIS_ODT:1;
  uint32_t                         u1ODIS_CS:1;
  uint32_t                         u1ODIS_CLK:1;
  uint32_t                         u1ODIS_CKE:1;
  uint32_t                         u6ODIS_CA:6;
  uint32_t                         :17;
} stc_LPDDR4_LPDDR4_CORE_CIOR_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_CIOR_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_CIOR_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_CIOR_CH1_t;

/**
  * \brief PHY Data Module IO Control Register (LPDDR4_LPDDR4_CORE_DIOR_SL0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DIOR_SL0_field {
  uint32_t                         u3DRVSEL:3;
  uint32_t                         u1CMOS_EN:1;
  uint32_t                         u1FENA_RCV:1;
  uint32_t                         u1RTT_EN:1;
  uint32_t                         u3RTT_SEL:3;
  uint32_t                         u8ODIS_DQ:8;
  uint32_t                         u1ODIS_DM:1;
  uint32_t                         u1ODIS_DQS:1;
  uint32_t                         :13;
} stc_LPDDR4_LPDDR4_CORE_DIOR_SL0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DIOR_SL0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DIOR_SL0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DIOR_SL0_t;

/**
  * \brief PHY Data Module IO Control Register (LPDDR4_LPDDR4_CORE_DIOR_SL1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DIOR_SL1_field {
  uint32_t                         u3DRVSEL:3;
  uint32_t                         u1CMOS_EN:1;
  uint32_t                         u1FENA_RCV:1;
  uint32_t                         u1RTT_EN:1;
  uint32_t                         u3RTT_SEL:3;
  uint32_t                         u8ODIS_DQ:8;
  uint32_t                         u1ODIS_DM:1;
  uint32_t                         u1ODIS_DQS:1;
  uint32_t                         :13;
} stc_LPDDR4_LPDDR4_CORE_DIOR_SL1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DIOR_SL1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DIOR_SL1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DIOR_SL1_t;

/**
  * \brief PHY Data Module IO Control Register (LPDDR4_LPDDR4_CORE_DIOR_SL2)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DIOR_SL2_field {
  uint32_t                         u3DRVSEL:3;
  uint32_t                         u1CMOS_EN:1;
  uint32_t                         u1FENA_RCV:1;
  uint32_t                         u1RTT_EN:1;
  uint32_t                         u3RTT_SEL:3;
  uint32_t                         u8ODIS_DQ:8;
  uint32_t                         u1ODIS_DM:1;
  uint32_t                         u1ODIS_DQS:1;
  uint32_t                         :13;
} stc_LPDDR4_LPDDR4_CORE_DIOR_SL2_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DIOR_SL2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DIOR_SL2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DIOR_SL2_t;

/**
  * \brief PHY Data Module IO Control Register (LPDDR4_LPDDR4_CORE_DIOR_SL3)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DIOR_SL3_field {
  uint32_t                         u3DRVSEL:3;
  uint32_t                         u1CMOS_EN:1;
  uint32_t                         u1FENA_RCV:1;
  uint32_t                         u1RTT_EN:1;
  uint32_t                         u3RTT_SEL:3;
  uint32_t                         u8ODIS_DQ:8;
  uint32_t                         u1ODIS_DM:1;
  uint32_t                         u1ODIS_DQS:1;
  uint32_t                         :13;
} stc_LPDDR4_LPDDR4_CORE_DIOR_SL3_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DIOR_SL3 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DIOR_SL3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DIOR_SL3_t;

/**
  * \brief PHY Compensation Control Register - Channel 0 (LPDDR4_LPDDR4_CORE_PCCR_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PCCR_CH0_field {
  uint32_t                         u1PCCR_CH0_SRST:1;
  uint32_t                         u1PCCR_CH0_TPADEN:1;
  uint32_t                         u1PCCR_CH0_MVG:1;
  uint32_t                         u1PCCR_CH0_EN:1;
  uint32_t                         u1PCCR_CH0_UPD:1;
  uint32_t                         u1PCCR_CH0_BYPEN:1;
  uint32_t                         u4PCCR_CH0_BYP_N:4;
  uint32_t                         u4PCCR_CH0_BYP_P:4;
  uint32_t                         u11PCCR_CH0_INITCNT:11;
  uint32_t                         :7;
} stc_LPDDR4_LPDDR4_CORE_PCCR_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PCCR_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PCCR_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PCCR_CH0_t;

/**
  * \brief PHY Compensation Control Register - Channel 1 (LPDDR4_LPDDR4_CORE_PCCR_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PCCR_CH1_field {
  uint32_t                         u1PCCR_CH1_SRST:1;
  uint32_t                         u1PCCR_CH1_TPADEN:1;
  uint32_t                         u1PCCR_CH1_MVG:1;
  uint32_t                         u1PCCR_CH1_EN:1;
  uint32_t                         u1PCCR_CH1_UPD:1;
  uint32_t                         u1PCCR_CH1_BYPEN:1;
  uint32_t                         u4PCCR_CH1_BYP_N:4;
  uint32_t                         u4PCCR_CH1_BYP_P:4;
  uint32_t                         u11PCCR_CH1_INITCNT:11;
  uint32_t                         :7;
} stc_LPDDR4_LPDDR4_CORE_PCCR_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PCCR_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PCCR_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PCCR_CH1_t;

/**
  * \brief DQS2DQ Delay Control Register (LPDDR4_LPDDR4_CORE_DQSDQCR)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DQSDQCR_field {
  uint32_t                         u8DLYOFFS:8;
  uint32_t                         u4DQSEL:4;
  uint32_t                         u1MUPD:1;
  uint32_t                         u3MPCRPT:3;
  uint32_t                         u8DLYMAX:8;
  uint32_t                         u1DIR:1;
  uint32_t                         :7;
} stc_LPDDR4_LPDDR4_CORE_DQSDQCR_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DQSDQCR {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DQSDQCR_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DQSDQCR_t;

/**
  * \brief PHY Training Setting Register 0 (LPDDR4_LPDDR4_CORE_PTSR0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR0_field {
  uint32_t                         u1VREFCAR:1;
  uint32_t                         u6VREFCAS:6;
  uint32_t                         u6CSC0:6;
  uint32_t                         u6CSC1:6;
  uint32_t                         u6CAC0B0:6;
  uint32_t                         u6CAC0B1:6;
} stc_LPDDR4_LPDDR4_CORE_PTSR0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR0_t;

/**
  * \brief PHY Training Setting Register 1 (LPDDR4_LPDDR4_CORE_PTSR1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR1_field {
  uint32_t                         u6CAC0B2:6;
  uint32_t                         u6CAC0B3:6;
  uint32_t                         u6CAC0B4:6;
  uint32_t                         u6CAC0B5:6;
  uint32_t                         u6CAC1B0:6;
  uint32_t                         :2;
} stc_LPDDR4_LPDDR4_CORE_PTSR1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR1_t;

/**
  * \brief PHY Training Setting Register 2 (LPDDR4_LPDDR4_CORE_PTSR2)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR2_field {
  uint32_t                         u6CAC1B1:6;
  uint32_t                         u6CAC1B2:6;
  uint32_t                         u6CAC1B3:6;
  uint32_t                         u6CAC1B4:6;
  uint32_t                         u6CAC1B5:6;
  uint32_t                         :2;
} stc_LPDDR4_LPDDR4_CORE_PTSR2_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR2_t;

/**
  * \brief PHY Training Setting Register 3 (LPDDR4_LPDDR4_CORE_PTSR3)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR3_field {
  uint32_t                         u6GTS0:6;
  uint32_t                         u6GTS1:6;
  uint32_t                         u6GTS2:6;
  uint32_t                         u6GTS3:6;
  uint32_t                         u1VREFDQWRR:1;
  uint32_t                         u6VREFDQWRS:6;
} stc_LPDDR4_LPDDR4_CORE_PTSR3_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR3 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR3_t;

/**
  * \brief PHY Training Setting Register 4 (LPDDR4_LPDDR4_CORE_PTSR4)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR4_field {
  uint32_t                         u8WRLVLS0:8;
  uint32_t                         u8WRLVLS1:8;
  uint32_t                         u8WRLVLS2:8;
  uint32_t                         u8WRLVLS3:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR4_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR4 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR4_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR4_t;

/**
  * \brief PHY Training Setting Register 5 (LPDDR4_LPDDR4_CORE_PTSR5)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR5_field {
  uint32_t                         u8DQSDQS0B0:8;
  uint32_t                         u8DQSDQS0B1:8;
  uint32_t                         u8DQSDQS0B2:8;
  uint32_t                         u8DQSDQS0B3:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR5_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR5 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR5_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR5_t;

/**
  * \brief PHY Training Setting Register 6 (LPDDR4_LPDDR4_CORE_PTSR6)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR6_field {
  uint32_t                         u8DQSDQS0B4:8;
  uint32_t                         u8DQSDQS0B5:8;
  uint32_t                         u8DQSDQS0B6:8;
  uint32_t                         u8DQSDQS0B7:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR6_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR6 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR6_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR6_t;

/**
  * \brief PHY Training Setting Register 7 (LPDDR4_LPDDR4_CORE_PTSR7)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR7_field {
  uint32_t                         u8DQSDQS1B0:8;
  uint32_t                         u8DQSDQS1B1:8;
  uint32_t                         u8DQSDQS1B2:8;
  uint32_t                         u8DQSDQS1B3:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR7_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR7 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR7_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR7_t;

/**
  * \brief PHY Training Setting Register 8 (LPDDR4_LPDDR4_CORE_PTSR8)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR8_field {
  uint32_t                         u8DQSDQS1B4:8;
  uint32_t                         u8DQSDQS1B5:8;
  uint32_t                         u8DQSDQS1B6:8;
  uint32_t                         u8DQSDQS1B7:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR8_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR8 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR8_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR8_t;

/**
  * \brief PHY Training Setting Register 9 (LPDDR4_LPDDR4_CORE_PTSR9)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR9_field {
  uint32_t                         u8DQSDQS2B0:8;
  uint32_t                         u8DQSDQS2B1:8;
  uint32_t                         u8DQSDQS2B2:8;
  uint32_t                         u8DQSDQS2B3:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR9_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR9 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR9_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR9_t;

/**
  * \brief PHY Training Setting Register 10 (LPDDR4_LPDDR4_CORE_PTSR10)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR10_field {
  uint32_t                         u8DQSDQS2B4:8;
  uint32_t                         u8DQSDQS2B5:8;
  uint32_t                         u8DQSDQS2B6:8;
  uint32_t                         u8DQSDQS2B7:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR10_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR10 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR10_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR10_t;

/**
  * \brief PHY Training Setting Register 11 (LPDDR4_LPDDR4_CORE_PTSR11)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR11_field {
  uint32_t                         u8DQSDQS3B0:8;
  uint32_t                         u8DQSDQS3B1:8;
  uint32_t                         u8DQSDQS3B2:8;
  uint32_t                         u8DQSDQS3B3:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR11_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR11 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR11_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR11_t;

/**
  * \brief PHY Training Setting Register 12 (LPDDR4_LPDDR4_CORE_PTSR12)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR12_field {
  uint32_t                         u8DQSDQS3B4:8;
  uint32_t                         u8DQSDQS3B5:8;
  uint32_t                         u8DQSDQS3B6:8;
  uint32_t                         u8DQSDQS3B7:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR12_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR12 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR12_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR12_t;

/**
  * \brief PHY Training Setting Register 13 (LPDDR4_LPDDR4_CORE_PTSR13)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR13_field {
  uint32_t                         u8DQSDMS0:8;
  uint32_t                         u8DQSDMS1:8;
  uint32_t                         u8DQSDMS2:8;
  uint32_t                         u8DQSDMS3:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR13_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR13 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR13_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR13_t;

/**
  * \brief PHY Training Setting Register 14 (LPDDR4_LPDDR4_CORE_PTSR14)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR14_field {
  uint32_t                         u8RDLVLDQS0B0:8;
  uint32_t                         u8RDLVLDQS0B1:8;
  uint32_t                         u8RDLVLDQS0B2:8;
  uint32_t                         u8RDLVLDQS0B3:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR14_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR14 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR14_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR14_t;

/**
  * \brief PHY Training Setting Register 15 (LPDDR4_LPDDR4_CORE_PTSR15)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR15_field {
  uint32_t                         u8RDLVLDQS0B4:8;
  uint32_t                         u8RDLVLDQS0B5:8;
  uint32_t                         u8RDLVLDQS0B6:8;
  uint32_t                         u8RDLVLDQS0B7:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR15_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR15 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR15_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR15_t;

/**
  * \brief PHY Training Setting Register 16 (LPDDR4_LPDDR4_CORE_PTSR16)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR16_field {
  uint32_t                         u8RDLVLDQS1B0:8;
  uint32_t                         u8RDLVLDQS1B1:8;
  uint32_t                         u8RDLVLDQS1B2:8;
  uint32_t                         u8RDLVLDQS1B3:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR16_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR16 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR16_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR16_t;

/**
  * \brief PHY Training Setting Register 17 (LPDDR4_LPDDR4_CORE_PTSR17)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR17_field {
  uint32_t                         u8RDLVLDQS1B4:8;
  uint32_t                         u8RDLVLDQS1B5:8;
  uint32_t                         u8RDLVLDQS1B6:8;
  uint32_t                         u8RDLVLDQS1B7:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR17_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR17 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR17_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR17_t;

/**
  * \brief PHY Training Setting Register 18 (LPDDR4_LPDDR4_CORE_PTSR18)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR18_field {
  uint32_t                         u8RDLVLDQS2B0:8;
  uint32_t                         u8RDLVLDQS2B1:8;
  uint32_t                         u8RDLVLDQS2B2:8;
  uint32_t                         u8RDLVLDQS2B3:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR18_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR18 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR18_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR18_t;

/**
  * \brief PHY Training Setting Register 19 (LPDDR4_LPDDR4_CORE_PTSR19)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR19_field {
  uint32_t                         u8RDLVLDQS2B4:8;
  uint32_t                         u8RDLVLDQS2B5:8;
  uint32_t                         u8RDLVLDQS2B6:8;
  uint32_t                         u8RDLVLDQS2B7:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR19_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR19 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR19_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR19_t;

/**
  * \brief PHY Training Setting Register 20 (LPDDR4_LPDDR4_CORE_PTSR20)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR20_field {
  uint32_t                         u8RDLVLDQS3B0:8;
  uint32_t                         u8RDLVLDQS3B1:8;
  uint32_t                         u8RDLVLDQS3B2:8;
  uint32_t                         u8RDLVLDQS3B3:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR20_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR20 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR20_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR20_t;

/**
  * \brief PHY Training Setting Register 21 (LPDDR4_LPDDR4_CORE_PTSR21)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR21_field {
  uint32_t                         u8RDLVLDQS3B4:8;
  uint32_t                         u8RDLVLDQS3B5:8;
  uint32_t                         u8RDLVLDQS3B6:8;
  uint32_t                         u8RDLVLDQS3B7:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR21_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR21 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR21_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR21_t;

/**
  * \brief PHY Training Setting Register 22 (LPDDR4_LPDDR4_CORE_PTSR22)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR22_field {
  uint32_t                         u8RDLVLDMS0:8;
  uint32_t                         u8RDLVLDMS1:8;
  uint32_t                         u8RDLVLDMS2:8;
  uint32_t                         u8RDLVLDMS3:8;
} stc_LPDDR4_LPDDR4_CORE_PTSR22_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR22 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR22_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR22_t;

/**
  * \brief PHY Training Setting Register 23 (LPDDR4_LPDDR4_CORE_PTSR23)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR23_field {
  uint32_t                         u6VREFDQRDS0:6;
  uint32_t                         u6VREFDQRDS1:6;
  uint32_t                         u6VREFDQRDS2:6;
  uint32_t                         u6VREFDQRDS3:6;
  uint32_t                         u1VREFDQRDR:1;
  uint32_t                         :7;
} stc_LPDDR4_LPDDR4_CORE_PTSR23_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR23 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR23_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR23_t;

/**
  * \brief PHY Training Setting Register 24 (LPDDR4_LPDDR4_CORE_PTSR24)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR24_field {
  uint32_t                         u6CMDDLY_CKE0:6;
  uint32_t                         u6CMDDLY_CKE1:6;
  uint32_t                         u4PSCK:4;
  uint32_t                         u16SANPAT:16;
} stc_LPDDR4_LPDDR4_CORE_PTSR24_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR24 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR24_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR24_t;

/**
  * \brief PHY Training Setting Register 25 (LPDDR4_LPDDR4_CORE_PTSR25)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTSR25_field {
  uint32_t                         u6CMDDLY_ODT0:6;
  uint32_t                         u6CMDDLY_ODT1:6;
  uint32_t                         u6CMDDLY_RSTN0:6;
  uint32_t                         u6CMDDLY_RSTN1:6;
  uint32_t                         u4DQSLEADCK:4;
  uint32_t                         :4;
} stc_LPDDR4_LPDDR4_CORE_PTSR25_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTSR25 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTSR25_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTSR25_t;

/**
  * \brief Timing Register 0 (LPDDR4_LPDDR4_CORE_TREG0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG0_field {
  uint32_t                         u6T_ALRTP:6;
  uint32_t                         u5T_CKESR:5;
  uint32_t                         u5T_CKEHDQS:5;
  uint32_t                         u5T_PD:5;
  uint32_t                         u3T_DTRAIN:3;
  uint32_t                         u8T_DLLEN:8;
} stc_LPDDR4_LPDDR4_CORE_TREG0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG0_t;

/**
  * \brief Timing Register 1 (LPDDR4_LPDDR4_CORE_TREG1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG1_field {
  uint32_t                         u6T_RCD:6;
  uint32_t                         u7T_FAW:7;
  uint32_t                         u8T_RTW:8;
  uint32_t                         u6T_CCDWM:6;
  uint32_t                         u5T_MRS2LVLEN:5;
} stc_LPDDR4_LPDDR4_CORE_TREG1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG1_t;

/**
  * \brief Timing Register 2 (LPDDR4_LPDDR4_CORE_TREG2)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG2_field {
  uint32_t                         u8T_RC:8;
  uint32_t                         u8T_RAS:8;
  uint32_t                         u8T_RDPDEN:8;
  uint32_t                         u8T_DLLRST:8;
} stc_LPDDR4_LPDDR4_CORE_TREG2_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG2_t;

/**
  * \brief Timing Register 3 (LPDDR4_LPDDR4_CORE_TREG3)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG3_field {
  uint32_t                         u6T_RP:6;
  uint32_t                         u4T_MRR:4;
  uint32_t                         u5T_DQSCKE:5;
  uint32_t                         u5T_DQRPT:5;
  uint32_t                         u5T_MRD:5;
  uint32_t                         u7T_ZQLAT:7;
} stc_LPDDR4_LPDDR4_CORE_TREG3_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG3 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG3_t;

/**
  * \brief Timing Register 4 (LPDDR4_LPDDR4_CORE_TREG4)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG4_field {
  uint32_t                         u8T_WLBR:8;
  uint32_t                         u8T_WRAPDEN:8;
  uint32_t                         u5T_XP:5;
  uint32_t                         u11T_ZQCAL:11;
} stc_LPDDR4_LPDDR4_CORE_TREG4_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG4 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG4_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG4_t;

/**
  * \brief Timing Register 5 (LPDDR4_LPDDR4_CORE_TREG5)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG5_field {
  uint32_t                         u8T_ZQRS:8;
  uint32_t                         u2T_CKCKEH:2;
  uint32_t                         u14T_REFI:14;
  uint32_t                         u8T_OSCO:8;
} stc_LPDDR4_LPDDR4_CORE_TREG5_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG5 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG5_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG5_t;

/**
  * \brief Timing Register 6 (LPDDR4_LPDDR4_CORE_TREG6)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG6_field {
  uint32_t                         u10T_READ_LOW:10;
  uint32_t                         u10T_READ_HIGH:10;
  uint32_t                         u5T_CCD:5;
  uint32_t                         u7T_WLBTR:7;
} stc_LPDDR4_LPDDR4_CORE_TREG6_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG6 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG6_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG6_t;

/**
  * \brief Timing Register 7 (LPDDR4_LPDDR4_CORE_TREG7)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG7_field {
  uint32_t                         u14T_INIT1:14;
  uint32_t                         u6T_MPCWR:6;
  uint32_t                         u4T_CKFSPE:4;
  uint32_t                         u4T_CKFSPX:4;
  uint32_t                         u4T_CKELCK:4;
} stc_LPDDR4_LPDDR4_CORE_TREG7_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG7 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG7_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG7_t;

/**
  * \brief Timing Register 8 (LPDDR4_LPDDR4_CORE_TREG8)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG8_field {
  uint32_t                         u10T_WRITE_LOW:10;
  uint32_t                         u10T_WRITE_HIGH:10;
  uint32_t                         u5T_MRW:5;
  uint32_t                         u7T_MPCWR2RD:7;
} stc_LPDDR4_LPDDR4_CORE_TREG8_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG8 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG8_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG8_t;

/**
  * \brief Timing Register 9 (LPDDR4_LPDDR4_CORE_TREG9)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG9_field {
  uint32_t                         u28T_ZQ_ITV:28;
  uint32_t                         u4T_CMDCKE:4;
} stc_LPDDR4_LPDDR4_CORE_TREG9_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG9 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG9_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG9_t;

/**
  * \brief Timing Register 10 (LPDDR4_LPDDR4_CORE_TREG10)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG10_field {
  uint32_t                         u10T_RFC:10;
  uint32_t                         u6T_MRS2ACT:6;
  uint32_t                         u4T_LVLLOAD:4;
  uint32_t                         u4T_LVLDLL:4;
  uint32_t                         u8T_LVLRESP:8;
} stc_LPDDR4_LPDDR4_CORE_TREG10_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG10 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG10_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG10_t;

/**
  * \brief Timing Register 11 (LPDDR4_LPDDR4_CORE_TREG11)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG11_field {
  uint32_t                         u16T_DLLLOCK:16;
  uint32_t                         u7T_INIT5:7;
  uint32_t                         u9T_CAENT:9;
} stc_LPDDR4_LPDDR4_CORE_TREG11_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG11 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG11_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG11_t;

/**
  * \brief Timing Register 12 (LPDDR4_LPDDR4_CORE_TREG12)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG12_field {
  uint32_t                         u5T_RRD:5;
  uint32_t                         u17T_INIT3:17;
  uint32_t                         u10T_XSR:10;
} stc_LPDDR4_LPDDR4_CORE_TREG12_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG12 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG12_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG12_t;

/**
  * \brief Timing Register 13 (LPDDR4_LPDDR4_CORE_TREG13)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG13_field {
  uint32_t                         u5T_LVLDIS:5;
  uint32_t                         u5T_LVLEXIT:5;
  uint32_t                         u4T_LVLAA:4;
  uint32_t                         u9T_FC:9;
  uint32_t                         :9;
} stc_LPDDR4_LPDDR4_CORE_TREG13_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG13 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG13_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG13_t;

/**
  * \brief Timing Register 14 (LPDDR4_LPDDR4_CORE_TREG14)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG14_field {
  uint32_t                         u8T_ODTUP:8;
  uint32_t                         u8T_VREFTIMESHORT:8;
  uint32_t                         u9T_VREFTIMELONG:9;
  uint32_t                         :7;
} stc_LPDDR4_LPDDR4_CORE_TREG14_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG14 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG14_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG14_t;

/**
  * \brief Timing Register 15 (LPDDR4_LPDDR4_CORE_TREG15)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_TREG15_field {
  uint32_t                         u9T_VRCGEN:9;
  uint32_t                         u8T_VRCGDIS:8;
  uint32_t                         :15;
} stc_LPDDR4_LPDDR4_CORE_TREG15_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_TREG15 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_TREG15_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_TREG15_t;

/**
  * \brief BIST Configuration Register - Channel 0 (LPDDR4_LPDDR4_CORE_BISTCFG_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTCFG_CH0_field {
  uint32_t                         u3START_BANK:3;
  uint32_t                         u3END_BANK:3;
  uint32_t                         u3START_BACKGROUND:3;
  uint32_t                         u3END_BACKGROUND:3;
  uint32_t                         u4ELEMENT:4;
  uint32_t                         u4OPERATION:4;
  uint32_t                         u4RETENTION:4;
  uint32_t                         u1DIAGNOSIS_EN:1;
  uint32_t                         :7;
} stc_LPDDR4_LPDDR4_CORE_BISTCFG_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTCFG_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTCFG_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTCFG_CH0_t;

/**
  * \brief BIST Configuration Register - Channel 1 (LPDDR4_LPDDR4_CORE_BISTCFG_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTCFG_CH1_field {
  uint32_t                         u3START_BANK:3;
  uint32_t                         u3END_BANK:3;
  uint32_t                         u3START_BACKGROUND:3;
  uint32_t                         u3END_BACKGROUND:3;
  uint32_t                         u4ELEMENT:4;
  uint32_t                         u4OPERATION:4;
  uint32_t                         u4RETENTION:4;
  uint32_t                         u1DIAGNOSIS_EN:1;
  uint32_t                         :7;
} stc_LPDDR4_LPDDR4_CORE_BISTCFG_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTCFG_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTCFG_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTCFG_CH1_t;

/**
  * \brief BIST Start Address - Channel 0 (LPDDR4_LPDDR4_CORE_BISTSTADDR_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTSTADDR_CH0_field {
  uint32_t                         u15START_ROW:15;
  uint32_t                         u10START_COL:10;
  uint32_t                         :7;
} stc_LPDDR4_LPDDR4_CORE_BISTSTADDR_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTSTADDR_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTSTADDR_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTSTADDR_CH0_t;

/**
  * \brief BIST Start Address - Channel 1 (LPDDR4_LPDDR4_CORE_BISTSTADDR_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTSTADDR_CH1_field {
  uint32_t                         u15START_ROW:15;
  uint32_t                         u10START_COL:10;
  uint32_t                         :7;
} stc_LPDDR4_LPDDR4_CORE_BISTSTADDR_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTSTADDR_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTSTADDR_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTSTADDR_CH1_t;

/**
  * \brief BIST End Address - Channel 0 (LPDDR4_LPDDR4_CORE_BISTEDADDR_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTEDADDR_CH0_field {
  uint32_t                         u15END_ROW:15;
  uint32_t                         u10END_COL:10;
  uint32_t                         :7;
} stc_LPDDR4_LPDDR4_CORE_BISTEDADDR_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTEDADDR_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTEDADDR_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTEDADDR_CH0_t;

/**
  * \brief BIST End Address - Channel 1 (LPDDR4_LPDDR4_CORE_BISTEDADDR_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTEDADDR_CH1_field {
  uint32_t                         u15END_ROW:15;
  uint32_t                         u10END_COL:10;
  uint32_t                         :7;
} stc_LPDDR4_LPDDR4_CORE_BISTEDADDR_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTEDADDR_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTEDADDR_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTEDADDR_CH1_t;

/**
  * \brief BIST March Element Register 0 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM0_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM0_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_0:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM0_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM0_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM0_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM0_CH0_t;

/**
  * \brief BIST March Element Register 0 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM0_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM0_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_0:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM0_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM0_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM0_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM0_CH1_t;

/**
  * \brief BIST March Element Register 1 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM1_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM1_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_1:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM1_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM1_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM1_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM1_CH0_t;

/**
  * \brief BIST March Element Register 1 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM1_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM1_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_1:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM1_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM1_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM1_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM1_CH1_t;

/**
  * \brief BIST March Element Register 2 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM2_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM2_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_2:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM2_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM2_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM2_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM2_CH0_t;

/**
  * \brief BIST March Element Register 2 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM2_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM2_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_2:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM2_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM2_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM2_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM2_CH1_t;

/**
  * \brief BIST March Element Register 3 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM3_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM3_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_3:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM3_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM3_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM3_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM3_CH0_t;

/**
  * \brief BIST March Element Register 3 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM3_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM3_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_3:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM3_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM3_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM3_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM3_CH1_t;

/**
  * \brief BIST March Element Register 4 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM4_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM4_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_4:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM4_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM4_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM4_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM4_CH0_t;

/**
  * \brief BIST March Element Register 4 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM4_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM4_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_4:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM4_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM4_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM4_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM4_CH1_t;

/**
  * \brief BIST March Element Register 5 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM5_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM5_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_5:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM5_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM5_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM5_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM5_CH0_t;

/**
  * \brief BIST March Element Register 5 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM5_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM5_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_5:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM5_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM5_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM5_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM5_CH1_t;

/**
  * \brief BIST March Element Register 6 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM6_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM6_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_6:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM6_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM6_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM6_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM6_CH0_t;

/**
  * \brief BIST March Element Register 6 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM6_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM6_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_6:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM6_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM6_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM6_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM6_CH1_t;

/**
  * \brief BIST March Element Register 7 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM7_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM7_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_7:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM7_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM7_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM7_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM7_CH0_t;

/**
  * \brief BIST March Element Register 7 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM7_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM7_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_7:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM7_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM7_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM7_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM7_CH1_t;

/**
  * \brief BIST March Element Register 8 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM8_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM8_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_8:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM8_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM8_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM8_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM8_CH0_t;

/**
  * \brief BIST March Element Register 8 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM8_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM8_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_8:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM8_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM8_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM8_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM8_CH1_t;

/**
  * \brief BIST March Element Register 9 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM9_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM9_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_9:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM9_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM9_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM9_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM9_CH0_t;

/**
  * \brief BIST March Element Register 9 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM9_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM9_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_9:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM9_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM9_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM9_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM9_CH1_t;

/**
  * \brief BIST March Element Register 10 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM10_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM10_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_10:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM10_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM10_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM10_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM10_CH0_t;

/**
  * \brief BIST March Element Register 10 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM10_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM10_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_10:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM10_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM10_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM10_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM10_CH1_t;

/**
  * \brief BIST March Element Register 11 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM11_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM11_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_11:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM11_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM11_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM11_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM11_CH0_t;

/**
  * \brief BIST March Element Register 11 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM11_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM11_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_11:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM11_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM11_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM11_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM11_CH1_t;

/**
  * \brief BIST March Element Register 12 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM12_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM12_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_12:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM12_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM12_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM12_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM12_CH0_t;

/**
  * \brief BIST March Element Register 12 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM12_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM12_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_12:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM12_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM12_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM12_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM12_CH1_t;

/**
  * \brief BIST March Element Register 13 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM13_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM13_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_13:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM13_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM13_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM13_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM13_CH0_t;

/**
  * \brief BIST March Element Register 13 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM13_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM13_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_13:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM13_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM13_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM13_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM13_CH1_t;

/**
  * \brief BIST March Element Register 14 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM14_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM14_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_14:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM14_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM14_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM14_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM14_CH0_t;

/**
  * \brief BIST March Element Register 14 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM14_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM14_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_14:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM14_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM14_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM14_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM14_CH1_t;

/**
  * \brief BIST March Element Register 15 - Channel 0 (LPDDR4_LPDDR4_CORE_BISTM15_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM15_CH0_field {
  uint32_t                         u32MARCH_ELEMENT_15:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM15_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM15_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM15_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM15_CH0_t;

/**
  * \brief BIST March Element Register 15 - Channel 1 (LPDDR4_LPDDR4_CORE_BISTM15_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTM15_CH1_field {
  uint32_t                         u32MARCH_ELEMENT_15:32;
} stc_LPDDR4_LPDDR4_CORE_BISTM15_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTM15_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTM15_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTM15_CH1_t;

/**
  * \brief ADFT Register (LPDDR4_LPDDR4_CORE_ADFT)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_ADFT_field {
  uint32_t                         u2TST_EN_CA:2;
  uint32_t                         u4TST_EN_DQ:4;
  uint32_t                         :26;
} stc_LPDDR4_LPDDR4_CORE_ADFT_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_ADFT {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_ADFT_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_ADFT_t;

/**
  * \brief Output Bypass Enable Register 0 (LPDDR4_LPDDR4_CORE_OUTBYPEN0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_OUTBYPEN0_field {
  uint32_t                         u12CA:12;
  uint32_t                         u2CKE:2;
  uint32_t                         u2CS:2;
  uint32_t                         u2ODT:2;
  uint32_t                         u2RESET_N:2;
  uint32_t                         u4DM:4;
  uint32_t                         u4DQS:4;
  uint32_t                         :4;
} stc_LPDDR4_LPDDR4_CORE_OUTBYPEN0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_OUTBYPEN0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_OUTBYPEN0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_OUTBYPEN0_t;

/**
  * \brief Output Bypass Enable Register 1 (LPDDR4_LPDDR4_CORE_OUTBYPEN1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_OUTBYPEN1_field {
  uint32_t                         u32DQ:32;
} stc_LPDDR4_LPDDR4_CORE_OUTBYPEN1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_OUTBYPEN1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_OUTBYPEN1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_OUTBYPEN1_t;

/**
  * \brief Output Data In Register 0 (LPDDR4_LPDDR4_CORE_OUTD0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_OUTD0_field {
  uint32_t                         u12CA:12;
  uint32_t                         u2CKE:2;
  uint32_t                         u2CS:2;
  uint32_t                         u2ODT:2;
  uint32_t                         u2RESET_N:2;
  uint32_t                         u4DM:4;
  uint32_t                         u4DQS:4;
  uint32_t                         :4;
} stc_LPDDR4_LPDDR4_CORE_OUTD0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_OUTD0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_OUTD0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_OUTD0_t;

/**
  * \brief Output Data In Register 1 (LPDDR4_LPDDR4_CORE_OUTD1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_OUTD1_field {
  uint32_t                         u32DQ:32;
} stc_LPDDR4_LPDDR4_CORE_OUTD1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_OUTD1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_OUTD1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_OUTD1_t;

/**
  * \brief Inline ECC Register 0 (LPDDR4_LPDDR4_CORE_INECC0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_INECC0_field {
  uint32_t                         u30ECC_BASE:30;
  uint32_t                         :2;
} stc_LPDDR4_LPDDR4_CORE_INECC0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_INECC0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_INECC0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_INECC0_t;

/**
  * \brief Inline ECC Register 1 (LPDDR4_LPDDR4_CORE_INECC1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_INECC1_field {
  uint32_t                         u30PROT_MEM_BASE:30;
  uint32_t                         :2;
} stc_LPDDR4_LPDDR4_CORE_INECC1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_INECC1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_INECC1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_INECC1_t;

/**
  * \brief Inline ECC Register 2 (LPDDR4_LPDDR4_CORE_INECC2)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_INECC2_field {
  uint32_t                         u30PROT_MEM_SIZE:30;
  uint32_t                         :2;
} stc_LPDDR4_LPDDR4_CORE_INECC2_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_INECC2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_INECC2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_INECC2_t;

/**
  * \brief Device ID Status Register (LPDDR4_LPDDR4_CORE_DVSTT0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DVSTT0_field {
  uint32_t                         u16DEVICE_ID:16;
  uint32_t                         :16;
} stc_LPDDR4_LPDDR4_CORE_DVSTT0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DVSTT0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DVSTT0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DVSTT0_t;

/**
  * \brief Device Mode Status Register (LPDDR4_LPDDR4_CORE_DVSTT1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DVSTT1_field {
  uint32_t                         u2DVSTT1_DRAM_BL_ENC:2;
  uint32_t                         u2DVSTT1_DFI_FREQ_RATIO:2;
  uint32_t                         :28;
} stc_LPDDR4_LPDDR4_CORE_DVSTT1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DVSTT1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DVSTT1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DVSTT1_t;

/**
  * \brief Operation Status Register 1 - Channel 0 (LPDDR4_LPDDR4_CORE_OPSTT_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_OPSTT_CH0_field {
  uint32_t                         u1DRAM_PAUSE:1;
  uint32_t                         u1USER_CMD_READY:1;
  uint32_t                         u8BANK_IDLE:8;
  uint32_t                         u1XQR_EMPTY:1;
  uint32_t                         u1XQR_FULL:1;
  uint32_t                         u1XQW_EMPTY:1;
  uint32_t                         u1XQW_FULL:1;
  uint32_t                         :18;
} stc_LPDDR4_LPDDR4_CORE_OPSTT_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_OPSTT_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_OPSTT_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_OPSTT_CH0_t;

/**
  * \brief Operation Status Register 1 - Channel 1 (LPDDR4_LPDDR4_CORE_OPSTT_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_OPSTT_CH1_field {
  uint32_t                         u1DRAM_PAUSE:1;
  uint32_t                         u1USER_CMD_READY:1;
  uint32_t                         u8BANK_IDLE:8;
  uint32_t                         u1XQR_EMPTY:1;
  uint32_t                         u1XQR_FULL:1;
  uint32_t                         u1XQW_EMPTY:1;
  uint32_t                         u1XQW_FULL:1;
  uint32_t                         :18;
} stc_LPDDR4_LPDDR4_CORE_OPSTT_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_OPSTT_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_OPSTT_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_OPSTT_CH1_t;

/**
  * \brief Interrupt Status Register - Channel 0 (LPDDR4_LPDDR4_CORE_INTSTT_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_INTSTT_CH0_field {
  uint32_t                         u1INT_GC_FSM:1;
  uint32_t                         :31;
} stc_LPDDR4_LPDDR4_CORE_INTSTT_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_INTSTT_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_INTSTT_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_INTSTT_CH0_t;

/**
  * \brief Interrupt Status Register - Channel 1 (LPDDR4_LPDDR4_CORE_INTSTT_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_INTSTT_CH1_field {
  uint32_t                         u1INT_GC_FSM:1;
  uint32_t                         :31;
} stc_LPDDR4_LPDDR4_CORE_INTSTT_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_INTSTT_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_INTSTT_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_INTSTT_CH1_t;

/**
  * \brief BIST Status 0 (LPDDR4_LPDDR4_CORE_BISTSTT0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTSTT0_field {
  uint32_t                         u12BISTERR_CA:12;
  uint32_t                         u4BISTERR_DM:4;
  uint32_t                         u2BISTERR_CKE:2;
  uint32_t                         u2BISTERR_CS_N:2;
  uint32_t                         u2BISTERR_RESET_N:2;
  uint32_t                         u2BISTERR_ODT:2;
  uint32_t                         :8;
} stc_LPDDR4_LPDDR4_CORE_BISTSTT0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTSTT0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTSTT0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTSTT0_t;

/**
  * \brief BIST Status 1 (LPDDR4_LPDDR4_CORE_BISTSTT1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_BISTSTT1_field {
  uint32_t                         u32BISTERR_DQ:32;
} stc_LPDDR4_LPDDR4_CORE_BISTSTT1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_BISTSTT1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_BISTSTT1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_BISTSTT1_t;

/**
  * \brief DDR BIST Status Register - Channel 0 (LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_field {
  uint32_t                         u1ERROR:1;
  uint32_t                         u1ENDTEST:1;
  uint32_t                         u1ERROR_NEW:1;
  uint32_t                         u3BANK_FAIL:3;
  uint32_t                         u15ROW_FAIL:15;
  uint32_t                         :11;
} stc_LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_t;

/**
  * \brief DDR BIST Status Register - Channel 1 (LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_field {
  uint32_t                         u1ERROR:1;
  uint32_t                         u1ENDTEST:1;
  uint32_t                         u1ERROR_NEW:1;
  uint32_t                         u3BANK_FAIL:3;
  uint32_t                         u15ROW_FAIL:15;
  uint32_t                         :11;
} stc_LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_t;

/**
  * \brief PHY Operation Status Register (LPDDR4_LPDDR4_CORE_POS)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_POS_field {
  uint32_t                         u1PHYSETC:1;
  uint32_t                         u1PHYFSC:1;
  uint32_t                         u1PHYINITC:1;
  uint32_t                         u1DLLRSTC:1;
  uint32_t                         u1DRAMINITC:1;
  uint32_t                         u1VREFDQRDC:1;
  uint32_t                         u1VREFCAC:1;
  uint32_t                         u1GTC:1;
  uint32_t                         u1WRLVLC:1;
  uint32_t                         u1RDLVLC:1;
  uint32_t                         u1VREFDQWRC:1;
  uint32_t                         u1DLYEVALC:1;
  uint32_t                         u1SANCHKC:1;
  uint32_t                         u1OFS:1;
  uint32_t                         u1FS0REQ:1;
  uint32_t                         u1FS1REQ:1;
  uint32_t                         u1CLKLOCKC:1;
  uint32_t                         u1CMDDLYC:1;
  uint32_t                         u1DQSDQC:1;
  uint32_t                         :13;
} stc_LPDDR4_LPDDR4_CORE_POS_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_POS {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_POS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_POS_t;

/**
  * \brief PHY Training Status Register 0 (LPDDR4_LPDDR4_CORE_PTS0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTS0_field {
  uint32_t                         u6DLLERR:6;
  uint32_t                         u4VREFDQRDERR:4;
  uint32_t                         u2VREFCAERR:2;
  uint32_t                         u4GTERR:4;
  uint32_t                         u4WRLVLERR:4;
  uint32_t                         u4VREFDQWRERR:4;
  uint32_t                         u4RDLVLDMERR:4;
  uint32_t                         u4SANCHKERR:4;
} stc_LPDDR4_LPDDR4_CORE_PTS0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTS0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTS0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTS0_t;

/**
  * \brief PHY Training Status Register 1 (LPDDR4_LPDDR4_CORE_PTS1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTS1_field {
  uint32_t                         u32RDLVLDQERR:32;
} stc_LPDDR4_LPDDR4_CORE_PTS1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTS1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTS1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTS1_t;

/**
  * \brief PHY Training Status Register 2 (LPDDR4_LPDDR4_CORE_PTS2)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTS2_field {
  uint32_t                         u32DQSDQERR:32;
} stc_LPDDR4_LPDDR4_CORE_PTS2_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTS2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTS2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTS2_t;

/**
  * \brief PHY Training Status Register 3 (LPDDR4_LPDDR4_CORE_PTS3)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PTS3_field {
  uint32_t                         u4DQSDMERR:4;
  uint32_t                         :28;
} stc_LPDDR4_LPDDR4_CORE_PTS3_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PTS3 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PTS3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PTS3_t;

/**
  * \brief DLL  Status Register for PHY Command Module (LPDDR4_LPDDR4_CORE_DLLSTTCA)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DLLSTTCA_field {
  uint32_t                         u2DLLSTTCA_LOCK:2;
  uint32_t                         u2DLLSTTCA_OVFL:2;
  uint32_t                         u2DLLSTTCA_UNFL:2;
  uint32_t                         u8DLYC_CA0:8;
  uint32_t                         u8DLYC_CA1:8;
  uint32_t                         :10;
} stc_LPDDR4_LPDDR4_CORE_DLLSTTCA_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DLLSTTCA {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DLLSTTCA_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DLLSTTCA_t;

/**
  * \brief DLL  Status Register for PHY Data Module 0 (LPDDR4_LPDDR4_CORE_DLLSTTDQ0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DLLSTTDQ0_field {
  uint32_t                         u4LOCK:4;
  uint32_t                         u4OVFL:4;
  uint32_t                         u4UNFL:4;
  uint32_t                         :20;
} stc_LPDDR4_LPDDR4_CORE_DLLSTTDQ0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DLLSTTDQ0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DLLSTTDQ0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DLLSTTDQ0_t;

/**
  * \brief DLL  Status Register for PHY Data Module 1 (LPDDR4_LPDDR4_CORE_DLLSTTDQ1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DLLSTTDQ1_field {
  uint32_t                         u8DLYC_SL0:8;
  uint32_t                         u8DLYC_SL1:8;
  uint32_t                         u8DLYC_SL2:8;
  uint32_t                         u8DLYC_SL3:8;
} stc_LPDDR4_LPDDR4_CORE_DLLSTTDQ1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DLLSTTDQ1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DLLSTTDQ1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DLLSTTDQ1_t;

/**
  * \brief PHY BIST Status Register (LPDDR4_LPDDR4_CORE_PBSR)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PBSR_field {
  uint32_t                         u1BIST_DONE:1;
  uint32_t                         u1BIST_ERR:1;
  uint32_t                         :30;
} stc_LPDDR4_LPDDR4_CORE_PBSR_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PBSR {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PBSR_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PBSR_t;

/**
  * \brief PHY Compensation Status Register - Channel 0 (LPDDR4_LPDDR4_CORE_PCSR_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PCSR_CH0_field {
  uint32_t                         u1SRSTC:1;
  uint32_t                         u1UPDC:1;
  uint32_t                         u4NBC:4;
  uint32_t                         u4PBC:4;
  uint32_t                         :22;
} stc_LPDDR4_LPDDR4_CORE_PCSR_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PCSR_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PCSR_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PCSR_CH0_t;

/**
  * \brief PHY Compensation Status Register - Channel 1 (LPDDR4_LPDDR4_CORE_PCSR_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_PCSR_CH1_field {
  uint32_t                         u1SRSTC:1;
  uint32_t                         u1UPDC:1;
  uint32_t                         u4NBC:4;
  uint32_t                         u4PBC:4;
  uint32_t                         :22;
} stc_LPDDR4_LPDDR4_CORE_PCSR_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_PCSR_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_PCSR_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_PCSR_CH1_t;

/**
  * \brief MR Readout Register - Channel 0 (LPDDR4_LPDDR4_CORE_MRR_CH0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_MRR_CH0_field {
  uint32_t                         u1DONE:1;
  uint32_t                         u8READOUT:8;
  uint32_t                         :23;
} stc_LPDDR4_LPDDR4_CORE_MRR_CH0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_MRR_CH0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_MRR_CH0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_MRR_CH0_t;

/**
  * \brief MR Readout Register - Channel 1 (LPDDR4_LPDDR4_CORE_MRR_CH1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_MRR_CH1_field {
  uint32_t                         u1DONE:1;
  uint32_t                         u8READOUT:8;
  uint32_t                         :23;
} stc_LPDDR4_LPDDR4_CORE_MRR_CH1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_MRR_CH1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_MRR_CH1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_MRR_CH1_t;

/**
  * \brief Shadow LPDDR Mode Register 1 (LPDDR4_LPDDR4_CORE_SHAD_LPMR1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR1_field {
  uint32_t                         u2SHAD_LPMR1_FS0_BL:2;
  uint32_t                         u1SHAD_LPMR1_FS0_WPRE:1;
  uint32_t                         u1SHAD_LPMR1_FS0_RPRE:1;
  uint32_t                         u3SHAD_LPMR1_FS0_NWR:3;
  uint32_t                         u1SHAD_LPMR1_FS0_RPST:1;
  uint32_t                         u2SHAD_LPMR1_FS1_BL:2;
  uint32_t                         u1SHAD_LPMR1_FS1_WPRE:1;
  uint32_t                         u1SHAD_LPMR1_FS1_RPRE:1;
  uint32_t                         u3SHAD_LPMR1_FS1_NWR:3;
  uint32_t                         u1SHAD_LPMR1_FS1_RPST:1;
  uint32_t                         :16;
} stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_SHAD_LPMR1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_SHAD_LPMR1_t;

/**
  * \brief Shadow LPDDR Mode Register 2 (LPDDR4_LPDDR4_CORE_SHAD_LPMR2)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR2_field {
  uint32_t                         u3SHAD_LPMR2_FS0_RL:3;
  uint32_t                         u3SHAD_LPMR2_FS0_WL:3;
  uint32_t                         u1SHAD_LPMR2_FS0_WLS:1;
  uint32_t                         u1SHAD_LPMR2_WRLEV:1;
  uint32_t                         u3SHAD_LPMR2_FS1_RL:3;
  uint32_t                         u3SHAD_LPMR2_FS1_WL:3;
  uint32_t                         u1SHAD_LPMR2_FS1_WLS:1;
  uint32_t                         u1SHAD_LPMR2_RESERVED:1;
  uint32_t                         :16;
} stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR2_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_SHAD_LPMR2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_SHAD_LPMR2_t;

/**
  * \brief Shadow LPDDR Mode Register 3 (LPDDR4_LPDDR4_CORE_SHAD_LPMR3)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR3_field {
  uint32_t                         u1SHAD_LPMR3_FS0_PUCAL:1;
  uint32_t                         u1SHAD_LPMR3_FS0_WPST:1;
  uint32_t                         u1SHAD_LPMR3_PPRP:1;
  uint32_t                         u3SHAD_LPMR3_FS0_PDDS:3;
  uint32_t                         u1SHAD_LPMR3_FS0_RDBI:1;
  uint32_t                         u1SHAD_LPMR3_FS0_WDBI:1;
  uint32_t                         u1SHAD_LPMR3_FS1_PUCAL:1;
  uint32_t                         u1SHAD_LPMR3_FS1_WPST:1;
  uint32_t                         u1SHAD_LPMR3_RESERVED:1;
  uint32_t                         u3SHAD_LPMR3_FS1_PDDS:3;
  uint32_t                         u1SHAD_LPMR3_FS1_RDBI:1;
  uint32_t                         u1SHAD_LPMR3_FS1_WDBI:1;
  uint32_t                         :16;
} stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR3_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_SHAD_LPMR3 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_SHAD_LPMR3_t;

/**
  * \brief Shadow LPDDR Mode Register 11 (LPDDR4_LPDDR4_CORE_SHAD_LPMR11)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR11_field {
  uint32_t                         u3SHAD_LPMR11_FS0_DQODT:3;
  uint32_t                         u1SHAD_LPMR11_RESERVED0:1;
  uint32_t                         u3SHAD_LPMR11_FS0_CAODT:3;
  uint32_t                         u1SHAD_LPMR11_RESERVED1:1;
  uint32_t                         u3SHAD_LPMR11_FS1_DQODT:3;
  uint32_t                         u1SHAD_LPMR11_RESERVED2:1;
  uint32_t                         u3SHAD_LPMR11_FS1_CAODT:3;
  uint32_t                         u1SHAD_LPMR11_RESERVED3:1;
  uint32_t                         :16;
} stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR11_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_SHAD_LPMR11 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR11_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_SHAD_LPMR11_t;

/**
  * \brief Shadow LPDDR Mode Register 12 (LPDDR4_LPDDR4_CORE_SHAD_LPMR12)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR12_field {
  uint32_t                         u6SHAD_LPMR12_FS0_VREFCAS:6;
  uint32_t                         u1SHAD_LPMR12_FS0_VREFCAR:1;
  uint32_t                         u1SHAD_LPMR12_RESERVED0:1;
  uint32_t                         u6SHAD_LPMR12_FS1_VREFCAS:6;
  uint32_t                         u1SHAD_LPMR12_FS1_VREFCAR:1;
  uint32_t                         u1SHAD_LPMR12_RESERVED1:1;
  uint32_t                         :16;
} stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR12_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_SHAD_LPMR12 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR12_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_SHAD_LPMR12_t;

/**
  * \brief Shadow LPDDR Mode Register 13 (LPDDR4_LPDDR4_CORE_SHAD_LPMR13)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR13_field {
  uint32_t                         u1SHAD_LPMR13_CBT:1;
  uint32_t                         u1SHAD_LPMR13_RPT:1;
  uint32_t                         u1SHAD_LPMR13_VRO:1;
  uint32_t                         u1SHAD_LPMR13_VRCG:1;
  uint32_t                         u1SHAD_LPMR13_RRO:1;
  uint32_t                         u1SHAD_LPMR13_DMD:1;
  uint32_t                         u1SHAD_LPMR13_FSPWR:1;
  uint32_t                         u1SHAD_LPMR13_FSPOP:1;
  uint32_t                         :24;
} stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR13_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_SHAD_LPMR13 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR13_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_SHAD_LPMR13_t;

/**
  * \brief Shadow LPDDR Mode Register 14 (LPDDR4_LPDDR4_CORE_SHAD_LPMR14)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR14_field {
  uint32_t                         u6SHAD_LPMR14_FS0_VREFDQS:6;
  uint32_t                         u1SHAD_LPMR14_FS0_VREFDQR:1;
  uint32_t                         u1SHAD_LPMR14_RESERVED0:1;
  uint32_t                         u6SHAD_LPMR14_FS1_VREFDQS:6;
  uint32_t                         u1SHAD_LPMR14_FS1_VREFDQR:1;
  uint32_t                         u1SHAD_LPMR14_RESERVED1:1;
  uint32_t                         :16;
} stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR14_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_SHAD_LPMR14 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR14_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_SHAD_LPMR14_t;

/**
  * \brief Shadow LPDDR Mode Register 22 (LPDDR4_LPDDR4_CORE_SHAD_LPMR22)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR22_field {
  uint32_t                         u3SHAD_LPMR22_FS0_SOCODT:3;
  uint32_t                         u1SHAD_LPMR22_FS0_ODTECK:1;
  uint32_t                         u1SHAD_LPMR22_FS0_ODTECS:1;
  uint32_t                         u1SHAD_LPMR22_FS0_ODTDCA:1;
  uint32_t                         u2SHAD_LPMR22_ODTDX8:2;
  uint32_t                         u3SHAD_LPMR22_FS1_SOCODT:3;
  uint32_t                         u1SHAD_LPMR22_FS1_ODTECK:1;
  uint32_t                         u1SHAD_LPMR22_FS1_ODTECS:1;
  uint32_t                         u1SHAD_LPMR22_FS1_ODTDCA:1;
  uint32_t                         u2SHAD_LPMR22_RESERVED:2;
  uint32_t                         :16;
} stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR22_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_SHAD_LPMR22 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_SHAD_LPMR22_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_SHAD_LPMR22_t;

/**
  * \brief PHY Response Register (LPDDR4_LPDDR4_CORE_RESP)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_RESP_field {
  uint32_t                         u32RESP_WRLEV:32;
} stc_LPDDR4_LPDDR4_CORE_RESP_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_RESP {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_RESP_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_RESP_t;

/**
  * \brief Read Data Register 0 (LPDDR4_LPDDR4_CORE_DATA0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DATA0_field {
  uint32_t                         u32RDDATA:32;
} stc_LPDDR4_LPDDR4_CORE_DATA0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DATA0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DATA0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DATA0_t;

/**
  * \brief Read Data Register 1 (LPDDR4_LPDDR4_CORE_DATA1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DATA1_field {
  uint32_t                         u32RDDATA:32;
} stc_LPDDR4_LPDDR4_CORE_DATA1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DATA1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DATA1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DATA1_t;

/**
  * \brief Read Data Register 2 (LPDDR4_LPDDR4_CORE_DATA2)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DATA2_field {
  uint32_t                         u32RDDATA:32;
} stc_LPDDR4_LPDDR4_CORE_DATA2_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DATA2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DATA2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DATA2_t;

/**
  * \brief Read Data Register 3 (LPDDR4_LPDDR4_CORE_DATA3)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DATA3_field {
  uint32_t                         u32RDDATA:32;
} stc_LPDDR4_LPDDR4_CORE_DATA3_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DATA3 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DATA3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DATA3_t;

/**
  * \brief Read Data Register 4 (LPDDR4_LPDDR4_CORE_DATA4)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DATA4_field {
  uint32_t                         u32RDDATA:32;
} stc_LPDDR4_LPDDR4_CORE_DATA4_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DATA4 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DATA4_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DATA4_t;

/**
  * \brief Read Data Register 5 (LPDDR4_LPDDR4_CORE_DATA5)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DATA5_field {
  uint32_t                         u32RDDATA:32;
} stc_LPDDR4_LPDDR4_CORE_DATA5_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DATA5 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DATA5_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DATA5_t;

/**
  * \brief Read Data Register 6 (LPDDR4_LPDDR4_CORE_DATA6)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DATA6_field {
  uint32_t                         u32RDDATA:32;
} stc_LPDDR4_LPDDR4_CORE_DATA6_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DATA6 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DATA6_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DATA6_t;

/**
  * \brief Read Data Register 7 (LPDDR4_LPDDR4_CORE_DATA7)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DATA7_field {
  uint32_t                         u32RDDATA:32;
} stc_LPDDR4_LPDDR4_CORE_DATA7_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DATA7 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DATA7_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DATA7_t;

/**
  * \brief Read Data Register 8 (LPDDR4_LPDDR4_CORE_DATA8)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_DATA8_field {
  uint32_t                         u1RDVALID:1;
  uint32_t                         :31;
} stc_LPDDR4_LPDDR4_CORE_DATA8_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_DATA8 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_DATA8_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_DATA8_t;

/**
  * \brief Inline ECC Status Register 0 (LPDDR4_LPDDR4_CORE_INECCSTT0)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_INECCSTT0_field {
  uint32_t                         u30ECC_ERROR_ADDR:30;
  uint32_t                         :2;
} stc_LPDDR4_LPDDR4_CORE_INECCSTT0_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_INECCSTT0 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_INECCSTT0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_INECCSTT0_t;

/**
  * \brief Inline ECC Status Register 1 (LPDDR4_LPDDR4_CORE_INECCSTT1)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_INECCSTT1_field {
  uint32_t                         u32ECC_ERROR_SYNDROME:32;
} stc_LPDDR4_LPDDR4_CORE_INECCSTT1_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_INECCSTT1 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_INECCSTT1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_INECCSTT1_t;

/**
  * \brief Inline ECC Status Register 2 (LPDDR4_LPDDR4_CORE_INECCSTT2)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_INECCSTT2_field {
  uint32_t                         u4ECC_ERROR_SEC:4;
  uint32_t                         u4ECC_ERROR_DED:4;
  uint32_t                         :24;
} stc_LPDDR4_LPDDR4_CORE_INECCSTT2_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_INECCSTT2 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_INECCSTT2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_INECCSTT2_t;

/**
  * \brief Inline ECC Status Register 3 (LPDDR4_LPDDR4_CORE_INECCSTT3)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_INECCSTT3_field {
  uint32_t                         u1ECC_ERR_BUFF_EMPTY:1;
  uint32_t                         u1ECC_ERR_BUFF_FULL:1;
  uint32_t                         :30;
} stc_LPDDR4_LPDDR4_CORE_INECCSTT3_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_INECCSTT3 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_INECCSTT3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_INECCSTT3_t;

/**
  * \brief Inline ECC Status Register 4 (LPDDR4_LPDDR4_CORE_INECCSTT4)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE_INECCSTT4_field {
  uint32_t                         u16SEC_NUM:16;
  uint32_t                         u16DED_NUM:16;
} stc_LPDDR4_LPDDR4_CORE_INECCSTT4_field_t;

typedef union un_LPDDR4_LPDDR4_CORE_INECCSTT4 {
  uint32_t                         u32Register;
  stc_LPDDR4_LPDDR4_CORE_INECCSTT4_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_LPDDR4_CORE_INECCSTT4_t;



/**
  * \brief EMPU region address 0 (slave structure) (LPDDR4_EMPU_EMPU_STRUCT_ADDR0)
  */
typedef struct stc_LPDDR4_EMPU_EMPU_STRUCT_ADDR0_field {
  uint32_t                         u8SUBREGION_DISABLE:8;
  uint32_t                         u24ADDR24:24;
} stc_LPDDR4_EMPU_EMPU_STRUCT_ADDR0_field_t;

typedef union un_LPDDR4_EMPU_EMPU_STRUCT_ADDR0 {
  uint32_t                         u32Register;
  stc_LPDDR4_EMPU_EMPU_STRUCT_ADDR0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_EMPU_EMPU_STRUCT_ADDR0_t;

/**
  * \brief EMPU region attributes 0 (slave structure) (LPDDR4_EMPU_EMPU_STRUCT_ATT0)
  */
typedef struct stc_LPDDR4_EMPU_EMPU_STRUCT_ATT0_field {
  uint32_t                         u1UR:1;
  uint32_t                         u1UW:1;
  uint32_t                         u1UX:1;
  uint32_t                         u1PR:1;
  uint32_t                         u1PW:1;
  uint32_t                         u1PX:1;
  uint32_t                         u1NS:1;
  uint32_t                         :1;
  uint32_t                         u1PC_MASK_0:1;
  uint32_t                         u15PC_MASK_15_TO_1:15;
  uint32_t                         u5REGION_SIZE:5;
  uint32_t                         :1;
  uint32_t                         u1PC_MATCH:1;
  uint32_t                         u1ENABLED:1;
} stc_LPDDR4_EMPU_EMPU_STRUCT_ATT0_field_t;

typedef union un_LPDDR4_EMPU_EMPU_STRUCT_ATT0 {
  uint32_t                         u32Register;
  stc_LPDDR4_EMPU_EMPU_STRUCT_ATT0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_EMPU_EMPU_STRUCT_ATT0_t;

/**
  * \brief EMPU region address 1 (master structure) (LPDDR4_EMPU_EMPU_STRUCT_ADDR1)
  */
typedef struct stc_LPDDR4_EMPU_EMPU_STRUCT_ADDR1_field {
  uint32_t                         u8SUBREGION_DISABLE:8;
  uint32_t                         u24ADDR24:24;
} stc_LPDDR4_EMPU_EMPU_STRUCT_ADDR1_field_t;

typedef union un_LPDDR4_EMPU_EMPU_STRUCT_ADDR1 {
  uint32_t                         u32Register;
  stc_LPDDR4_EMPU_EMPU_STRUCT_ADDR1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_EMPU_EMPU_STRUCT_ADDR1_t;

/**
  * \brief EMPU region attributes 1 (master structure) (LPDDR4_EMPU_EMPU_STRUCT_ATT1)
  */
typedef struct stc_LPDDR4_EMPU_EMPU_STRUCT_ATT1_field {
  uint32_t                         u1UR:1;
  uint32_t                         u1UW:1;
  uint32_t                         u1UX:1;
  uint32_t                         u1PR:1;
  uint32_t                         u1PW:1;
  uint32_t                         u1PX:1;
  uint32_t                         u1NS:1;
  uint32_t                         :1;
  uint32_t                         u1PC_MASK_0:1;
  uint32_t                         u15PC_MASK_15_TO_1:15;
  uint32_t                         u5REGION_SIZE:5;
  uint32_t                         :1;
  uint32_t                         u1PC_MATCH:1;
  uint32_t                         u1ENABLED:1;
} stc_LPDDR4_EMPU_EMPU_STRUCT_ATT1_field_t;

typedef union un_LPDDR4_EMPU_EMPU_STRUCT_ATT1 {
  uint32_t                         u32Register;
  stc_LPDDR4_EMPU_EMPU_STRUCT_ATT1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LPDDR4_EMPU_EMPU_STRUCT_ATT1_t;



/**
  * \brief HOBTO specific wrapper (LPDDR4_LPDDR4_WRAPPER)
  */
typedef struct stc_LPDDR4_LPDDR4_WRAPPER {
  un_LPDDR4_LPDDR4_WRAPPER_CTL_t   unCTL;              /*!< 0x00000000 Control */
  un_LPDDR4_LPDDR4_WRAPPER_PLL800_CLOCK_CTL_t unPLL800_CLOCK_CTL; /*!< 0x00000004 800MHz PLL Control Register */
  uint32_t                         au32Reserved[2];
  un_LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_t unPLL800_CONFIG; /*!< 0x00000010 800MHz PLL Configuration Register */
  un_LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2_t unPLL800_CONFIG2; /*!< 0x00000014 800MHz PLL Configuration Register 2 (SSCG) */
  uint32_t                         au32Reserved1[2];
  un_LPDDR4_LPDDR4_WRAPPER_PLL800_STATUS_t unPLL800_STATUS; /*!< 0x00000020 800MHz PLL Status Register */
  uint32_t                         au32Reserved2[7];
  un_LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_t unQOS_CPUSS;    /*!< 0x00000040 QoS Configuration Register for CPUSS master */
  un_LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_t unQOS_VIDEOSS_RD; /*!< 0x00000044 QoS Configuration Register for VIDEOSS read master */
  un_LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_t unQOS_VIDEOSS_WR; /*!< 0x00000048 QoS Configuration Register for VIDEOSS write master */
  uint32_t                         au32Reserved3[109];
} stc_LPDDR4_LPDDR4_WRAPPER_t;                         /*!< Size = 512 (0x200) */

/**
  * \brief Measurement unit (LPDDR4_AXI_PERF_CNT_MU)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT_MU {
  un_LPDDR4_AXI_PERF_CNT_MU_TMR_CTL_t unTMR_CTL;       /*!< 0x00000000 Timer control */
  un_LPDDR4_AXI_PERF_CNT_MU_TMR_STATUS_t unTMR_STATUS; /*!< 0x00000004 Timer status */
  un_LPDDR4_AXI_PERF_CNT_MU_PORT_SELECT_t unPORT_SELECT; /*!< 0x00000008 AXI port select */
  uint32_t                         u32Reserved;
  un_LPDDR4_AXI_PERF_CNT_MU_FILTER_t unFILTER;         /*!< 0x00000010 Transaction filter */
  un_LPDDR4_AXI_PERF_CNT_MU_FILTER_MASK_t unFILTER_MASK; /*!< 0x00000014 Transaction filter mask */
  un_LPDDR4_AXI_PERF_CNT_MU_OT_AC_t unOT_AC;           /*!< 0x00000018 Accumulated outstanding transactions */
  uint32_t                         u32Reserved1;
  un_LPDDR4_AXI_PERF_CNT_MU_ADDR_CNT_t unADDR_CNT;     /*!< 0x00000020 Address transfer counter */
  un_LPDDR4_AXI_PERF_CNT_MU_ADDR_STALL_CNT_t unADDR_STALL_CNT; /*!< 0x00000024 Address stall counter */
  un_LPDDR4_AXI_PERF_CNT_MU_DATA_CNT_t unDATA_CNT;     /*!< 0x00000028 Data transfer counter */
  un_LPDDR4_AXI_PERF_CNT_MU_DATA_STALL_CNT_t unDATA_STALL_CNT; /*!< 0x0000002C Data stall counter */
  uint32_t                         au32Reserved2[4];
} stc_LPDDR4_AXI_PERF_CNT_MU_t;                        /*!< Size = 64 (0x40) */

/**
  * \brief AXI performance counter (LPDDR4_AXI_PERF_CNT)
  */
typedef struct stc_LPDDR4_AXI_PERF_CNT {
  un_LPDDR4_AXI_PERF_CNT_CTL_t     unCTL;              /*!< 0x00000000 Control */
  un_LPDDR4_AXI_PERF_CNT_TMR_CMD_t unTMR_CMD;          /*!< 0x00000004 Timer command */
  uint32_t                         au32Reserved[126];
  stc_LPDDR4_AXI_PERF_CNT_MU_t     MU[4];              /*!< 0x00000200 Measurement unit */
  uint32_t                         au32Reserved1[64];
} stc_LPDDR4_AXI_PERF_CNT_t;                           /*!< Size = 1024 (0x400) */

/**
  * \brief LPDDR4 core (3PIP) (LPDDR4_LPDDR4_CORE)
  */
typedef struct stc_LPDDR4_LPDDR4_CORE {
  uint32_t                         au32Reserved[3];
  un_LPDDR4_LPDDR4_CORE_UCI_t      unUCI;              /*!< 0x0000000C User Command Interface */
  uint32_t                         au32Reserved1[60];
  un_LPDDR4_LPDDR4_CORE_DMCTL_t    unDMCTL;            /*!< 0x00000100 Dynamo Control Register */
  un_LPDDR4_LPDDR4_CORE_DMCFG_t    unDMCFG;            /*!< 0x00000104 Dynamo Configuration Register */
  un_LPDDR4_LPDDR4_CORE_LPMR1_t    unLPMR1;            /*!< 0x00000108 LPDDR Mode Register 1 */
  un_LPDDR4_LPDDR4_CORE_LPMR2_t    unLPMR2;            /*!< 0x0000010C LPDDR Mode Register 2 */
  un_LPDDR4_LPDDR4_CORE_LPMR3_t    unLPMR3;            /*!< 0x00000110 LPDDR Mode Register 3 */
  un_LPDDR4_LPDDR4_CORE_LPMR11_t   unLPMR11;           /*!< 0x00000114 LPDDR Mode Register 11 */
  un_LPDDR4_LPDDR4_CORE_LPMR12_t   unLPMR12;           /*!< 0x00000118 LPDDR Mode Register 12 */
  un_LPDDR4_LPDDR4_CORE_LPMR13_t   unLPMR13;           /*!< 0x0000011C LPDDR Mode Register 13 */
  un_LPDDR4_LPDDR4_CORE_LPMR14_t   unLPMR14;           /*!< 0x00000120 LPDDR Mode Register 14 */
  un_LPDDR4_LPDDR4_CORE_LPMR22_t   unLPMR22;           /*!< 0x00000124 LPDDR Mode Register 22 */
  un_LPDDR4_LPDDR4_CORE_RTCFG0_RT0_t unRTCFG0_RT0;     /*!< 0x00000128 Route Configuration 0 - Route 0 */
  un_LPDDR4_LPDDR4_CORE_RTCFG0_RT1_t unRTCFG0_RT1;     /*!< 0x0000012C Route Configuration 0 - Route 1 */
  un_LPDDR4_LPDDR4_CORE_RTCFG0_RT2_t unRTCFG0_RT2;     /*!< 0x00000130 Route Configuration 0 - Route 2 */
  un_LPDDR4_LPDDR4_CORE_RTCFG0_RT3_t unRTCFG0_RT3;     /*!< 0x00000134 Route Configuration 0 - Route 3 */
  un_LPDDR4_LPDDR4_CORE_RTCFG1_RT0_t unRTCFG1_RT0;     /*!< 0x00000138 Route Configuration 1 - Route 0 */
  un_LPDDR4_LPDDR4_CORE_RTCFG1_RT1_t unRTCFG1_RT1;     /*!< 0x0000013C Route Configuration 1 - Route 1 */
  un_LPDDR4_LPDDR4_CORE_RTCFG1_RT2_t unRTCFG1_RT2;     /*!< 0x00000140 Route Configuration 1 - Route 2 */
  un_LPDDR4_LPDDR4_CORE_RTCFG1_RT3_t unRTCFG1_RT3;     /*!< 0x00000144 Route Configuration 1 - Route 3 */
  un_LPDDR4_LPDDR4_CORE_ADDR0_t    unADDR0;            /*!< 0x00000148 DRAM Address Register 0 */
  un_LPDDR4_LPDDR4_CORE_ADDR1_t    unADDR1;            /*!< 0x0000014C DRAM Address Register 1 */
  un_LPDDR4_LPDDR4_CORE_ADDR2_t    unADDR2;            /*!< 0x00000150 DRAM Address Register 2 */
  un_LPDDR4_LPDDR4_CORE_ADDR3_t    unADDR3;            /*!< 0x00000154 DRAM Address Register 3 */
  un_LPDDR4_LPDDR4_CORE_ADDR4_t    unADDR4;            /*!< 0x00000158 DRAM Address Register 4 */
  un_LPDDR4_LPDDR4_CORE_ADDR5_t    unADDR5;            /*!< 0x0000015C DRAM Address Register 5 */
  un_LPDDR4_LPDDR4_CORE_PHY_t      unPHY;              /*!< 0x00000160 PHY Register */
  un_LPDDR4_LPDDR4_CORE_POM_t      unPOM;              /*!< 0x00000164 PHY Operation Mode Register */
  un_LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_t unDLLCTLCA_CH0; /*!< 0x00000168 DLL Control Register for PHY Command Module - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_t unDLLCTLCA_CH1; /*!< 0x0000016C DLL Control Register for PHY Command Module - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_t unDLLCTLDQ_SL0; /*!< 0x00000170 DLL Control Register for PHY Data Module */
  un_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_t unDLLCTLDQ_SL1; /*!< 0x00000174 DLL Control Register for PHY Data Module */
  un_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_t unDLLCTLDQ_SL2; /*!< 0x00000178 DLL Control Register for PHY Data Module */
  un_LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_t unDLLCTLDQ_SL3; /*!< 0x0000017C DLL Control Register for PHY Data Module */
  un_LPDDR4_LPDDR4_CORE_RTGC0_t    unRTGC0;            /*!< 0x00000180 PHY Read Training General Control Register 0 */
  un_LPDDR4_LPDDR4_CORE_RTGC1_t    unRTGC1;            /*!< 0x00000184 PHY Read Training General Control Register 1 */
  un_LPDDR4_LPDDR4_CORE_PTAR_t     unPTAR;             /*!< 0x00000188 PHY Sanity Check Address Register */
  un_LPDDR4_LPDDR4_CORE_VTGC_t     unVTGC;             /*!< 0x0000018C PHY VREF Training General Control Register */
  un_LPDDR4_LPDDR4_CORE_PBCR_t     unPBCR;             /*!< 0x00000190 PHY BIST Control Register */
  un_LPDDR4_LPDDR4_CORE_CIOR_CH0_t unCIOR_CH0;         /*!< 0x00000194 PHY Command Module IO Control Register - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_CIOR_CH1_t unCIOR_CH1;         /*!< 0x00000198 PHY Command Module IO Control Register - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_DIOR_SL0_t unDIOR_SL0;         /*!< 0x0000019C PHY Data Module IO Control Register */
  un_LPDDR4_LPDDR4_CORE_DIOR_SL1_t unDIOR_SL1;         /*!< 0x000001A0 PHY Data Module IO Control Register */
  un_LPDDR4_LPDDR4_CORE_DIOR_SL2_t unDIOR_SL2;         /*!< 0x000001A4 PHY Data Module IO Control Register */
  un_LPDDR4_LPDDR4_CORE_DIOR_SL3_t unDIOR_SL3;         /*!< 0x000001A8 PHY Data Module IO Control Register */
  un_LPDDR4_LPDDR4_CORE_PCCR_CH0_t unPCCR_CH0;         /*!< 0x000001AC PHY Compensation Control Register - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_PCCR_CH1_t unPCCR_CH1;         /*!< 0x000001B0 PHY Compensation Control Register - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_DQSDQCR_t  unDQSDQCR;          /*!< 0x000001B4 DQS2DQ Delay Control Register */
  un_LPDDR4_LPDDR4_CORE_PTSR0_t    unPTSR0;            /*!< 0x000001B8 PHY Training Setting Register 0 */
  un_LPDDR4_LPDDR4_CORE_PTSR1_t    unPTSR1;            /*!< 0x000001BC PHY Training Setting Register 1 */
  un_LPDDR4_LPDDR4_CORE_PTSR2_t    unPTSR2;            /*!< 0x000001C0 PHY Training Setting Register 2 */
  un_LPDDR4_LPDDR4_CORE_PTSR3_t    unPTSR3;            /*!< 0x000001C4 PHY Training Setting Register 3 */
  un_LPDDR4_LPDDR4_CORE_PTSR4_t    unPTSR4;            /*!< 0x000001C8 PHY Training Setting Register 4 */
  un_LPDDR4_LPDDR4_CORE_PTSR5_t    unPTSR5;            /*!< 0x000001CC PHY Training Setting Register 5 */
  un_LPDDR4_LPDDR4_CORE_PTSR6_t    unPTSR6;            /*!< 0x000001D0 PHY Training Setting Register 6 */
  un_LPDDR4_LPDDR4_CORE_PTSR7_t    unPTSR7;            /*!< 0x000001D4 PHY Training Setting Register 7 */
  un_LPDDR4_LPDDR4_CORE_PTSR8_t    unPTSR8;            /*!< 0x000001D8 PHY Training Setting Register 8 */
  un_LPDDR4_LPDDR4_CORE_PTSR9_t    unPTSR9;            /*!< 0x000001DC PHY Training Setting Register 9 */
  un_LPDDR4_LPDDR4_CORE_PTSR10_t   unPTSR10;           /*!< 0x000001E0 PHY Training Setting Register 10 */
  un_LPDDR4_LPDDR4_CORE_PTSR11_t   unPTSR11;           /*!< 0x000001E4 PHY Training Setting Register 11 */
  un_LPDDR4_LPDDR4_CORE_PTSR12_t   unPTSR12;           /*!< 0x000001E8 PHY Training Setting Register 12 */
  un_LPDDR4_LPDDR4_CORE_PTSR13_t   unPTSR13;           /*!< 0x000001EC PHY Training Setting Register 13 */
  un_LPDDR4_LPDDR4_CORE_PTSR14_t   unPTSR14;           /*!< 0x000001F0 PHY Training Setting Register 14 */
  un_LPDDR4_LPDDR4_CORE_PTSR15_t   unPTSR15;           /*!< 0x000001F4 PHY Training Setting Register 15 */
  un_LPDDR4_LPDDR4_CORE_PTSR16_t   unPTSR16;           /*!< 0x000001F8 PHY Training Setting Register 16 */
  un_LPDDR4_LPDDR4_CORE_PTSR17_t   unPTSR17;           /*!< 0x000001FC PHY Training Setting Register 17 */
  un_LPDDR4_LPDDR4_CORE_PTSR18_t   unPTSR18;           /*!< 0x00000200 PHY Training Setting Register 18 */
  un_LPDDR4_LPDDR4_CORE_PTSR19_t   unPTSR19;           /*!< 0x00000204 PHY Training Setting Register 19 */
  un_LPDDR4_LPDDR4_CORE_PTSR20_t   unPTSR20;           /*!< 0x00000208 PHY Training Setting Register 20 */
  un_LPDDR4_LPDDR4_CORE_PTSR21_t   unPTSR21;           /*!< 0x0000020C PHY Training Setting Register 21 */
  un_LPDDR4_LPDDR4_CORE_PTSR22_t   unPTSR22;           /*!< 0x00000210 PHY Training Setting Register 22 */
  un_LPDDR4_LPDDR4_CORE_PTSR23_t   unPTSR23;           /*!< 0x00000214 PHY Training Setting Register 23 */
  un_LPDDR4_LPDDR4_CORE_PTSR24_t   unPTSR24;           /*!< 0x00000218 PHY Training Setting Register 24 */
  un_LPDDR4_LPDDR4_CORE_PTSR25_t   unPTSR25;           /*!< 0x0000021C PHY Training Setting Register 25 */
  un_LPDDR4_LPDDR4_CORE_TREG0_t    unTREG0;            /*!< 0x00000220 Timing Register 0 */
  un_LPDDR4_LPDDR4_CORE_TREG1_t    unTREG1;            /*!< 0x00000224 Timing Register 1 */
  un_LPDDR4_LPDDR4_CORE_TREG2_t    unTREG2;            /*!< 0x00000228 Timing Register 2 */
  un_LPDDR4_LPDDR4_CORE_TREG3_t    unTREG3;            /*!< 0x0000022C Timing Register 3 */
  un_LPDDR4_LPDDR4_CORE_TREG4_t    unTREG4;            /*!< 0x00000230 Timing Register 4 */
  un_LPDDR4_LPDDR4_CORE_TREG5_t    unTREG5;            /*!< 0x00000234 Timing Register 5 */
  un_LPDDR4_LPDDR4_CORE_TREG6_t    unTREG6;            /*!< 0x00000238 Timing Register 6 */
  un_LPDDR4_LPDDR4_CORE_TREG7_t    unTREG7;            /*!< 0x0000023C Timing Register 7 */
  un_LPDDR4_LPDDR4_CORE_TREG8_t    unTREG8;            /*!< 0x00000240 Timing Register 8 */
  un_LPDDR4_LPDDR4_CORE_TREG9_t    unTREG9;            /*!< 0x00000244 Timing Register 9 */
  un_LPDDR4_LPDDR4_CORE_TREG10_t   unTREG10;           /*!< 0x00000248 Timing Register 10 */
  un_LPDDR4_LPDDR4_CORE_TREG11_t   unTREG11;           /*!< 0x0000024C Timing Register 11 */
  un_LPDDR4_LPDDR4_CORE_TREG12_t   unTREG12;           /*!< 0x00000250 Timing Register 12 */
  un_LPDDR4_LPDDR4_CORE_TREG13_t   unTREG13;           /*!< 0x00000254 Timing Register 13 */
  un_LPDDR4_LPDDR4_CORE_TREG14_t   unTREG14;           /*!< 0x00000258 Timing Register 14 */
  un_LPDDR4_LPDDR4_CORE_TREG15_t   unTREG15;           /*!< 0x0000025C Timing Register 15 */
  un_LPDDR4_LPDDR4_CORE_BISTCFG_CH0_t unBISTCFG_CH0;   /*!< 0x00000260 BIST Configuration Register - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTCFG_CH1_t unBISTCFG_CH1;   /*!< 0x00000264 BIST Configuration Register - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTSTADDR_CH0_t unBISTSTADDR_CH0; /*!< 0x00000268 BIST Start Address - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTSTADDR_CH1_t unBISTSTADDR_CH1; /*!< 0x0000026C BIST Start Address - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTEDADDR_CH0_t unBISTEDADDR_CH0; /*!< 0x00000270 BIST End Address - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTEDADDR_CH1_t unBISTEDADDR_CH1; /*!< 0x00000274 BIST End Address - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM0_CH0_t unBISTM0_CH0;     /*!< 0x00000278 BIST March Element Register 0 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM0_CH1_t unBISTM0_CH1;     /*!< 0x0000027C BIST March Element Register 0 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM1_CH0_t unBISTM1_CH0;     /*!< 0x00000280 BIST March Element Register 1 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM1_CH1_t unBISTM1_CH1;     /*!< 0x00000284 BIST March Element Register 1 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM2_CH0_t unBISTM2_CH0;     /*!< 0x00000288 BIST March Element Register 2 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM2_CH1_t unBISTM2_CH1;     /*!< 0x0000028C BIST March Element Register 2 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM3_CH0_t unBISTM3_CH0;     /*!< 0x00000290 BIST March Element Register 3 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM3_CH1_t unBISTM3_CH1;     /*!< 0x00000294 BIST March Element Register 3 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM4_CH0_t unBISTM4_CH0;     /*!< 0x00000298 BIST March Element Register 4 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM4_CH1_t unBISTM4_CH1;     /*!< 0x0000029C BIST March Element Register 4 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM5_CH0_t unBISTM5_CH0;     /*!< 0x000002A0 BIST March Element Register 5 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM5_CH1_t unBISTM5_CH1;     /*!< 0x000002A4 BIST March Element Register 5 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM6_CH0_t unBISTM6_CH0;     /*!< 0x000002A8 BIST March Element Register 6 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM6_CH1_t unBISTM6_CH1;     /*!< 0x000002AC BIST March Element Register 6 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM7_CH0_t unBISTM7_CH0;     /*!< 0x000002B0 BIST March Element Register 7 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM7_CH1_t unBISTM7_CH1;     /*!< 0x000002B4 BIST March Element Register 7 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM8_CH0_t unBISTM8_CH0;     /*!< 0x000002B8 BIST March Element Register 8 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM8_CH1_t unBISTM8_CH1;     /*!< 0x000002BC BIST March Element Register 8 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM9_CH0_t unBISTM9_CH0;     /*!< 0x000002C0 BIST March Element Register 9 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM9_CH1_t unBISTM9_CH1;     /*!< 0x000002C4 BIST March Element Register 9 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM10_CH0_t unBISTM10_CH0;   /*!< 0x000002C8 BIST March Element Register 10 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM10_CH1_t unBISTM10_CH1;   /*!< 0x000002CC BIST March Element Register 10 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM11_CH0_t unBISTM11_CH0;   /*!< 0x000002D0 BIST March Element Register 11 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM11_CH1_t unBISTM11_CH1;   /*!< 0x000002D4 BIST March Element Register 11 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM12_CH0_t unBISTM12_CH0;   /*!< 0x000002D8 BIST March Element Register 12 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM12_CH1_t unBISTM12_CH1;   /*!< 0x000002DC BIST March Element Register 12 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM13_CH0_t unBISTM13_CH0;   /*!< 0x000002E0 BIST March Element Register 13 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM13_CH1_t unBISTM13_CH1;   /*!< 0x000002E4 BIST March Element Register 13 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM14_CH0_t unBISTM14_CH0;   /*!< 0x000002E8 BIST March Element Register 14 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM14_CH1_t unBISTM14_CH1;   /*!< 0x000002EC BIST March Element Register 14 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTM15_CH0_t unBISTM15_CH0;   /*!< 0x000002F0 BIST March Element Register 15 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_BISTM15_CH1_t unBISTM15_CH1;   /*!< 0x000002F4 BIST March Element Register 15 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_ADFT_t     unADFT;             /*!< 0x000002F8 ADFT Register */
  un_LPDDR4_LPDDR4_CORE_OUTBYPEN0_t unOUTBYPEN0;       /*!< 0x000002FC Output Bypass Enable Register 0 */
  un_LPDDR4_LPDDR4_CORE_OUTBYPEN1_t unOUTBYPEN1;       /*!< 0x00000300 Output Bypass Enable Register 1 */
  un_LPDDR4_LPDDR4_CORE_OUTD0_t    unOUTD0;            /*!< 0x00000304 Output Data In Register 0 */
  un_LPDDR4_LPDDR4_CORE_OUTD1_t    unOUTD1;            /*!< 0x00000308 Output Data In Register 1 */
  un_LPDDR4_LPDDR4_CORE_INECC0_t   unINECC0;           /*!< 0x0000030C Inline ECC Register 0 */
  un_LPDDR4_LPDDR4_CORE_INECC1_t   unINECC1;           /*!< 0x00000310 Inline ECC Register 1 */
  un_LPDDR4_LPDDR4_CORE_INECC2_t   unINECC2;           /*!< 0x00000314 Inline ECC Register 2 */
  uint32_t                         au32Reserved2[698];
  un_LPDDR4_LPDDR4_CORE_DVSTT0_t   unDVSTT0;           /*!< 0x00000E00 Device ID Status Register */
  un_LPDDR4_LPDDR4_CORE_DVSTT1_t   unDVSTT1;           /*!< 0x00000E04 Device Mode Status Register */
  un_LPDDR4_LPDDR4_CORE_OPSTT_CH0_t unOPSTT_CH0;       /*!< 0x00000E08 Operation Status Register 1 - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_OPSTT_CH1_t unOPSTT_CH1;       /*!< 0x00000E0C Operation Status Register 1 - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_INTSTT_CH0_t unINTSTT_CH0;     /*!< 0x00000E10 Interrupt Status Register - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_INTSTT_CH1_t unINTSTT_CH1;     /*!< 0x00000E14 Interrupt Status Register - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_BISTSTT0_t unBISTSTT0;         /*!< 0x00000E18 BIST Status 0 */
  un_LPDDR4_LPDDR4_CORE_BISTSTT1_t unBISTSTT1;         /*!< 0x00000E1C BIST Status 1 */
  un_LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_t unDDRBISTSTT_CH0; /*!< 0x00000E20 DDR BIST Status Register - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_t unDDRBISTSTT_CH1; /*!< 0x00000E24 DDR BIST Status Register - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_POS_t      unPOS;              /*!< 0x00000E28 PHY Operation Status Register */
  un_LPDDR4_LPDDR4_CORE_PTS0_t     unPTS0;             /*!< 0x00000E2C PHY Training Status Register 0 */
  un_LPDDR4_LPDDR4_CORE_PTS1_t     unPTS1;             /*!< 0x00000E30 PHY Training Status Register 1 */
  un_LPDDR4_LPDDR4_CORE_PTS2_t     unPTS2;             /*!< 0x00000E34 PHY Training Status Register 2 */
  un_LPDDR4_LPDDR4_CORE_PTS3_t     unPTS3;             /*!< 0x00000E38 PHY Training Status Register 3 */
  un_LPDDR4_LPDDR4_CORE_DLLSTTCA_t unDLLSTTCA;         /*!< 0x00000E3C DLL  Status Register for PHY Command Module */
  un_LPDDR4_LPDDR4_CORE_DLLSTTDQ0_t unDLLSTTDQ0;       /*!< 0x00000E40 DLL  Status Register for PHY Data Module 0 */
  un_LPDDR4_LPDDR4_CORE_DLLSTTDQ1_t unDLLSTTDQ1;       /*!< 0x00000E44 DLL  Status Register for PHY Data Module 1 */
  un_LPDDR4_LPDDR4_CORE_PBSR_t     unPBSR;             /*!< 0x00000E48 PHY BIST Status Register */
  un_LPDDR4_LPDDR4_CORE_PCSR_CH0_t unPCSR_CH0;         /*!< 0x00000E4C PHY Compensation Status Register - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_PCSR_CH1_t unPCSR_CH1;         /*!< 0x00000E50 PHY Compensation Status Register - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_MRR_CH0_t  unMRR_CH0;          /*!< 0x00000E54 MR Readout Register - Channel 0 */
  un_LPDDR4_LPDDR4_CORE_MRR_CH1_t  unMRR_CH1;          /*!< 0x00000E58 MR Readout Register - Channel 1 */
  un_LPDDR4_LPDDR4_CORE_SHAD_LPMR1_t unSHAD_LPMR1;     /*!< 0x00000E5C Shadow LPDDR Mode Register 1 */
  un_LPDDR4_LPDDR4_CORE_SHAD_LPMR2_t unSHAD_LPMR2;     /*!< 0x00000E60 Shadow LPDDR Mode Register 2 */
  un_LPDDR4_LPDDR4_CORE_SHAD_LPMR3_t unSHAD_LPMR3;     /*!< 0x00000E64 Shadow LPDDR Mode Register 3 */
  un_LPDDR4_LPDDR4_CORE_SHAD_LPMR11_t unSHAD_LPMR11;   /*!< 0x00000E68 Shadow LPDDR Mode Register 11 */
  un_LPDDR4_LPDDR4_CORE_SHAD_LPMR12_t unSHAD_LPMR12;   /*!< 0x00000E6C Shadow LPDDR Mode Register 12 */
  un_LPDDR4_LPDDR4_CORE_SHAD_LPMR13_t unSHAD_LPMR13;   /*!< 0x00000E70 Shadow LPDDR Mode Register 13 */
  un_LPDDR4_LPDDR4_CORE_SHAD_LPMR14_t unSHAD_LPMR14;   /*!< 0x00000E74 Shadow LPDDR Mode Register 14 */
  un_LPDDR4_LPDDR4_CORE_SHAD_LPMR22_t unSHAD_LPMR22;   /*!< 0x00000E78 Shadow LPDDR Mode Register 22 */
  un_LPDDR4_LPDDR4_CORE_RESP_t     unRESP;             /*!< 0x00000E7C PHY Response Register */
  un_LPDDR4_LPDDR4_CORE_DATA0_t    unDATA0;            /*!< 0x00000E80 Read Data Register 0 */
  un_LPDDR4_LPDDR4_CORE_DATA1_t    unDATA1;            /*!< 0x00000E84 Read Data Register 1 */
  un_LPDDR4_LPDDR4_CORE_DATA2_t    unDATA2;            /*!< 0x00000E88 Read Data Register 2 */
  un_LPDDR4_LPDDR4_CORE_DATA3_t    unDATA3;            /*!< 0x00000E8C Read Data Register 3 */
  un_LPDDR4_LPDDR4_CORE_DATA4_t    unDATA4;            /*!< 0x00000E90 Read Data Register 4 */
  un_LPDDR4_LPDDR4_CORE_DATA5_t    unDATA5;            /*!< 0x00000E94 Read Data Register 5 */
  un_LPDDR4_LPDDR4_CORE_DATA6_t    unDATA6;            /*!< 0x00000E98 Read Data Register 6 */
  un_LPDDR4_LPDDR4_CORE_DATA7_t    unDATA7;            /*!< 0x00000E9C Read Data Register 7 */
  un_LPDDR4_LPDDR4_CORE_DATA8_t    unDATA8;            /*!< 0x00000EA0 Read Data Register 8 */
  un_LPDDR4_LPDDR4_CORE_INECCSTT0_t unINECCSTT0;       /*!< 0x00000EA4 Inline ECC Status Register 0 */
  un_LPDDR4_LPDDR4_CORE_INECCSTT1_t unINECCSTT1;       /*!< 0x00000EA8 Inline ECC Status Register 1 */
  un_LPDDR4_LPDDR4_CORE_INECCSTT2_t unINECCSTT2;       /*!< 0x00000EAC Inline ECC Status Register 2 */
  un_LPDDR4_LPDDR4_CORE_INECCSTT3_t unINECCSTT3;       /*!< 0x00000EB0 Inline ECC Status Register 3 */
  un_LPDDR4_LPDDR4_CORE_INECCSTT4_t unINECCSTT4;       /*!< 0x00000EB4 Inline ECC Status Register 4 */
  uint32_t                         au32Reserved3[82];
} stc_LPDDR4_LPDDR4_CORE_t;                            /*!< Size = 4096 (0x1000) */

/**
  * \brief EMPU structures. (LPDDR4_EMPU_EMPU_STRUCT)
  */
typedef struct stc_LPDDR4_EMPU_EMPU_STRUCT {
  un_LPDDR4_EMPU_EMPU_STRUCT_ADDR0_t unADDR0;          /*!< 0x00000000 EMPU region address 0 (slave structure) */
  un_LPDDR4_EMPU_EMPU_STRUCT_ATT0_t unATT0;            /*!< 0x00000004 EMPU region attributes 0 (slave structure) */
  uint32_t                         au32Reserved[6];
  un_LPDDR4_EMPU_EMPU_STRUCT_ADDR1_t unADDR1;          /*!< 0x00000020 EMPU region address 1 (master structure) */
  un_LPDDR4_EMPU_EMPU_STRUCT_ATT1_t unATT1;            /*!< 0x00000024 EMPU region attributes 1 (master structure) */
  uint32_t                         au32Reserved1[6];
} stc_LPDDR4_EMPU_EMPU_STRUCT_t;                       /*!< Size = 64 (0x40) */

/**
  * \brief EMPU configuration (LPDDR4_EMPU)
  */
typedef struct stc_LPDDR4_EMPU {
  uint32_t                         au32Reserved[2048];
  stc_LPDDR4_EMPU_EMPU_STRUCT_t    EMPU_STRUCT[32];    /*!< 0x00002000 EMPU structures. */
  uint32_t                         au32Reserved1[1536];
} stc_LPDDR4_EMPU_t;                                   /*!< Size = 16384 (0x4000) */

/**
  * \brief LPDDR4 (LPDDR4)
  */
typedef struct stc_LPDDR4 {
  stc_LPDDR4_LPDDR4_WRAPPER_t      LPDDR4_WRAPPER;     /*!< 0x00000000 HOBTO specific wrapper */
  uint32_t                         au32Reserved[128];
  stc_LPDDR4_AXI_PERF_CNT_t        AXI_PERF_CNT;       /*!< 0x00000400 AXI performance counter */
  uint32_t                         au32Reserved1[512];
  stc_LPDDR4_LPDDR4_CORE_t         LPDDR4_CORE;        /*!< 0x00001000 LPDDR4 core (3PIP) */
  uint32_t                         au32Reserved2[2048];
  stc_LPDDR4_EMPU_t                EMPU;               /*!< 0x00004000 EMPU configuration */
} stc_LPDDR4_t;                                        /*!< Size = 32768 (0x8000) */


/* LPDDR4_LPDDR4_WRAPPER.CTL */
#define LPDDR4_LPDDR4_WRAPPER_CTL_ENABLED_Pos   31UL
#define LPDDR4_LPDDR4_WRAPPER_CTL_ENABLED_Msk   0x80000000UL
/* LPDDR4_LPDDR4_WRAPPER.PLL800_CLOCK_CTL */
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CLOCK_CTL_ENABLE_Pos 0UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CLOCK_CTL_ENABLE_Msk 0x1UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CLOCK_CTL_OUTPUT_ENABLE_Pos 1UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CLOCK_CTL_OUTPUT_ENABLE_Msk 0x2UL
/* LPDDR4_LPDDR4_WRAPPER.PLL800_CONFIG */
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_FEEDBACK_DIV_Pos 0UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_FEEDBACK_DIV_Msk 0xFFUL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_REFERENCE_DIV_Pos 8UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_REFERENCE_DIV_Msk 0x1F00UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_OUTPUT_DIV_Pos 16UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_OUTPUT_DIV_Msk 0x1F0000UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_VCO_CLK_SEL_Pos 22UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_VCO_CLK_SEL_Msk 0xC00000UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_LOCK_DELAY_Pos 25UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_LOCK_DELAY_Msk 0x6000000UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_WAIT_TIME_Pos 28UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG_WAIT_TIME_Msk 0x30000000UL
/* LPDDR4_LPDDR4_WRAPPER.PLL800_CONFIG2 */
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2_SSCG_DEPTH_Pos 0UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2_SSCG_DEPTH_Msk 0x3FFUL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2_SSCG_RATE_Pos 16UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2_SSCG_RATE_Msk 0x70000UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2_SSCG_MODE_Pos 28UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2_SSCG_MODE_Msk 0x10000000UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2_SSCG_EN_Pos 31UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_CONFIG2_SSCG_EN_Msk 0x80000000UL
/* LPDDR4_LPDDR4_WRAPPER.PLL800_STATUS */
#define LPDDR4_LPDDR4_WRAPPER_PLL800_STATUS_LOCKED_Pos 0UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_STATUS_LOCKED_Msk 0x1UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_STATUS_UNLOCK_OCCURRED_Pos 1UL
#define LPDDR4_LPDDR4_WRAPPER_PLL800_STATUS_UNLOCK_OCCURRED_Msk 0x2UL
/* LPDDR4_LPDDR4_WRAPPER.QOS_CPUSS */
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_0_Pos 0UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_0_Msk 0x3UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_1_Pos 2UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_1_Msk 0xCUL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_2_Pos 4UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_2_Msk 0x30UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_3_Pos 6UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_3_Msk 0xC0UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_4_Pos 8UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_4_Msk 0x300UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_5_Pos 10UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_5_Msk 0xC00UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_6_Pos 12UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_6_Msk 0x3000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_7_Pos 14UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_7_Msk 0xC000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_8_Pos 16UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_8_Msk 0x30000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_9_Pos 18UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_9_Msk 0xC0000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_10_Pos 20UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_10_Msk 0x300000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_11_Pos 22UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_11_Msk 0xC00000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_12_Pos 24UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_12_Msk 0x3000000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_13_Pos 26UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_13_Msk 0xC000000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_14_Pos 28UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_14_Msk 0x30000000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_15_Pos 30UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_CPUSS_QOS_MASTERID_15_Msk 0xC0000000UL
/* LPDDR4_LPDDR4_WRAPPER.QOS_VIDEOSS_RD */
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_0_Pos 0UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_0_Msk 0x3UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_1_Pos 2UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_1_Msk 0xCUL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_2_Pos 4UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_2_Msk 0x30UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_3_Pos 6UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_3_Msk 0xC0UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_4_Pos 8UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_4_Msk 0x300UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_5_Pos 10UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_5_Msk 0xC00UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_6_Pos 12UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_6_Msk 0x3000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_7_Pos 14UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_7_Msk 0xC000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_8_Pos 16UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_8_Msk 0x30000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_9_Pos 18UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_9_Msk 0xC0000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_10_Pos 20UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_10_Msk 0x300000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_11_Pos 22UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_11_Msk 0xC00000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_12_Pos 24UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_12_Msk 0x3000000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_13_Pos 26UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_13_Msk 0xC000000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_14_Pos 28UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_14_Msk 0x30000000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_15_Pos 30UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_RD_QOS_MASTERID_15_Msk 0xC0000000UL
/* LPDDR4_LPDDR4_WRAPPER.QOS_VIDEOSS_WR */
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_0_Pos 0UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_0_Msk 0x3UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_1_Pos 2UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_1_Msk 0xCUL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_2_Pos 4UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_2_Msk 0x30UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_3_Pos 6UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_3_Msk 0xC0UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_4_Pos 8UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_4_Msk 0x300UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_5_Pos 10UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_5_Msk 0xC00UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_6_Pos 12UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_6_Msk 0x3000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_7_Pos 14UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_7_Msk 0xC000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_8_Pos 16UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_8_Msk 0x30000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_9_Pos 18UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_9_Msk 0xC0000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_10_Pos 20UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_10_Msk 0x300000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_11_Pos 22UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_11_Msk 0xC00000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_12_Pos 24UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_12_Msk 0x3000000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_13_Pos 26UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_13_Msk 0xC000000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_14_Pos 28UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_14_Msk 0x30000000UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_15_Pos 30UL
#define LPDDR4_LPDDR4_WRAPPER_QOS_VIDEOSS_WR_QOS_MASTERID_15_Msk 0xC0000000UL


/* LPDDR4_AXI_PERF_CNT_MU.TMR_CTL */
#define LPDDR4_AXI_PERF_CNT_MU_TMR_CTL_TMR_Pos  0UL
#define LPDDR4_AXI_PERF_CNT_MU_TMR_CTL_TMR_Msk  0xFFFFFFFUL
#define LPDDR4_AXI_PERF_CNT_MU_TMR_CTL_PSC_Pos  28UL
#define LPDDR4_AXI_PERF_CNT_MU_TMR_CTL_PSC_Msk  0xF0000000UL
/* LPDDR4_AXI_PERF_CNT_MU.TMR_STATUS */
#define LPDDR4_AXI_PERF_CNT_MU_TMR_STATUS_TMR_Pos 0UL
#define LPDDR4_AXI_PERF_CNT_MU_TMR_STATUS_TMR_Msk 0xFFFFFFFUL
#define LPDDR4_AXI_PERF_CNT_MU_TMR_STATUS_MEAS_Pos 31UL
#define LPDDR4_AXI_PERF_CNT_MU_TMR_STATUS_MEAS_Msk 0x80000000UL
/* LPDDR4_AXI_PERF_CNT_MU.PORT_SELECT */
#define LPDDR4_AXI_PERF_CNT_MU_PORT_SELECT_SELECT_Pos 0UL
#define LPDDR4_AXI_PERF_CNT_MU_PORT_SELECT_SELECT_Msk 0x7UL
/* LPDDR4_AXI_PERF_CNT_MU.FILTER */
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_MID_Pos   0UL
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_MID_Msk   0xFUL
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_TID_Pos   8UL
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_TID_Msk   0xFF00UL
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_WRITE_Pos 23UL
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_WRITE_Msk 0x800000UL
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_LEN_MIN_Pos 24UL
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_LEN_MIN_Msk 0xF000000UL
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_LEN_MAX_Pos 28UL
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_LEN_MAX_Msk 0xF0000000UL
/* LPDDR4_AXI_PERF_CNT_MU.FILTER_MASK */
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_MASK_MID_Pos 0UL
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_MASK_MID_Msk 0xFUL
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_MASK_TID_Pos 8UL
#define LPDDR4_AXI_PERF_CNT_MU_FILTER_MASK_TID_Msk 0xFF00UL
/* LPDDR4_AXI_PERF_CNT_MU.OT_AC */
#define LPDDR4_AXI_PERF_CNT_MU_OT_AC_CNT_Pos    0UL
#define LPDDR4_AXI_PERF_CNT_MU_OT_AC_CNT_Msk    0xFFFFFFFFUL
/* LPDDR4_AXI_PERF_CNT_MU.ADDR_CNT */
#define LPDDR4_AXI_PERF_CNT_MU_ADDR_CNT_CNT_Pos 0UL
#define LPDDR4_AXI_PERF_CNT_MU_ADDR_CNT_CNT_Msk 0xFFFFFFFFUL
/* LPDDR4_AXI_PERF_CNT_MU.ADDR_STALL_CNT */
#define LPDDR4_AXI_PERF_CNT_MU_ADDR_STALL_CNT_CNT_Pos 0UL
#define LPDDR4_AXI_PERF_CNT_MU_ADDR_STALL_CNT_CNT_Msk 0xFFFFFFFFUL
/* LPDDR4_AXI_PERF_CNT_MU.DATA_CNT */
#define LPDDR4_AXI_PERF_CNT_MU_DATA_CNT_CNT_Pos 0UL
#define LPDDR4_AXI_PERF_CNT_MU_DATA_CNT_CNT_Msk 0xFFFFFFFFUL
/* LPDDR4_AXI_PERF_CNT_MU.DATA_STALL_CNT */
#define LPDDR4_AXI_PERF_CNT_MU_DATA_STALL_CNT_CNT_Pos 0UL
#define LPDDR4_AXI_PERF_CNT_MU_DATA_STALL_CNT_CNT_Msk 0xFFFFFFFFUL


/* LPDDR4_AXI_PERF_CNT.CTL */
#define LPDDR4_AXI_PERF_CNT_CTL_ENABLED_Pos     31UL
#define LPDDR4_AXI_PERF_CNT_CTL_ENABLED_Msk     0x80000000UL
/* LPDDR4_AXI_PERF_CNT.TMR_CMD */
#define LPDDR4_AXI_PERF_CNT_TMR_CMD_START_Pos   0UL
#define LPDDR4_AXI_PERF_CNT_TMR_CMD_START_Msk   0x1UL
#define LPDDR4_AXI_PERF_CNT_TMR_CMD_STOP_Pos    8UL
#define LPDDR4_AXI_PERF_CNT_TMR_CMD_STOP_Msk    0x100UL


/* LPDDR4_LPDDR4_CORE.UCI */
#define LPDDR4_LPDDR4_CORE_UCI_CMD_OP_Pos       0UL
#define LPDDR4_LPDDR4_CORE_UCI_CMD_OP_Msk       0xFUL
#define LPDDR4_LPDDR4_CORE_UCI_CMD_CHAN_Pos     4UL
#define LPDDR4_LPDDR4_CORE_UCI_CMD_CHAN_Msk     0x30UL
#define LPDDR4_LPDDR4_CORE_UCI_MR_SEL_Pos       6UL
#define LPDDR4_LPDDR4_CORE_UCI_MR_SEL_Msk       0xFC0UL
#define LPDDR4_LPDDR4_CORE_UCI_MR_OP_Pos        12UL
#define LPDDR4_LPDDR4_CORE_UCI_MR_OP_Msk        0xFF000UL
/* LPDDR4_LPDDR4_CORE.DMCTL */
#define LPDDR4_LPDDR4_CORE_DMCTL_DDRT_Pos       0UL
#define LPDDR4_LPDDR4_CORE_DMCTL_DDRT_Msk       0x7UL
#define LPDDR4_LPDDR4_CORE_DMCTL_DFI_FREQ_RATIO_Pos 3UL
#define LPDDR4_LPDDR4_CORE_DMCTL_DFI_FREQ_RATIO_Msk 0x18UL
#define LPDDR4_LPDDR4_CORE_DMCTL_DRAM_BANK_EN_Pos 5UL
#define LPDDR4_LPDDR4_CORE_DMCTL_DRAM_BANK_EN_Msk 0x60UL
#define LPDDR4_LPDDR4_CORE_DMCTL_SWITCH_CLOSE_Pos 7UL
#define LPDDR4_LPDDR4_CORE_DMCTL_SWITCH_CLOSE_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_DMCTL_BANK_POLICY_Pos 8UL
#define LPDDR4_LPDDR4_CORE_DMCTL_BANK_POLICY_Msk 0x100UL
#define LPDDR4_LPDDR4_CORE_DMCTL_WR_DBI_Pos     9UL
#define LPDDR4_LPDDR4_CORE_DMCTL_WR_DBI_Msk     0x200UL
#define LPDDR4_LPDDR4_CORE_DMCTL_RD_DBI_Pos     10UL
#define LPDDR4_LPDDR4_CORE_DMCTL_RD_DBI_Msk     0x400UL
/* LPDDR4_LPDDR4_CORE.DMCFG */
#define LPDDR4_LPDDR4_CORE_DMCFG_REF_POST_PULL_EN_Pos 0UL
#define LPDDR4_LPDDR4_CORE_DMCFG_REF_POST_PULL_EN_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_DMCFG_INT_GC_FSM_EN_Pos 1UL
#define LPDDR4_LPDDR4_CORE_DMCFG_INT_GC_FSM_EN_Msk 0x2UL
#define LPDDR4_LPDDR4_CORE_DMCFG_INT_GC_FSM_CLR_Pos 2UL
#define LPDDR4_LPDDR4_CORE_DMCFG_INT_GC_FSM_CLR_Msk 0x4UL
#define LPDDR4_LPDDR4_CORE_DMCFG_INT_ECC_EN_Pos 3UL
#define LPDDR4_LPDDR4_CORE_DMCFG_INT_ECC_EN_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_DMCFG_REQ_TH_Pos     4UL
#define LPDDR4_LPDDR4_CORE_DMCFG_REQ_TH_Msk     0x70UL
#define LPDDR4_LPDDR4_CORE_DMCFG_ZQ_AUTO_EN_Pos 7UL
#define LPDDR4_LPDDR4_CORE_DMCFG_ZQ_AUTO_EN_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_DMCFG_INLINE_ECC_EN_Pos 8UL
#define LPDDR4_LPDDR4_CORE_DMCFG_INLINE_ECC_EN_Msk 0x100UL
/* LPDDR4_LPDDR4_CORE.LPMR1 */
#define LPDDR4_LPDDR4_CORE_LPMR1_FS0_BL_Pos     0UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS0_BL_Msk     0x3UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS0_WPRE_Pos   2UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS0_WPRE_Msk   0x4UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS0_RPRE_Pos   3UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS0_RPRE_Msk   0x8UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS0_NWR_Pos    4UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS0_NWR_Msk    0x70UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS0_RPST_Pos   7UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS0_RPST_Msk   0x80UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS1_BL_Pos     8UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS1_BL_Msk     0x300UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS1_WPRE_Pos   10UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS1_WPRE_Msk   0x400UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS1_RPRE_Pos   11UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS1_RPRE_Msk   0x800UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS1_NWR_Pos    12UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS1_NWR_Msk    0x7000UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS1_RPST_Pos   15UL
#define LPDDR4_LPDDR4_CORE_LPMR1_FS1_RPST_Msk   0x8000UL
/* LPDDR4_LPDDR4_CORE.LPMR2 */
#define LPDDR4_LPDDR4_CORE_LPMR2_FS0_RL_Pos     0UL
#define LPDDR4_LPDDR4_CORE_LPMR2_FS0_RL_Msk     0x7UL
#define LPDDR4_LPDDR4_CORE_LPMR2_FS0_WL_Pos     3UL
#define LPDDR4_LPDDR4_CORE_LPMR2_FS0_WL_Msk     0x38UL
#define LPDDR4_LPDDR4_CORE_LPMR2_FS0_WLS_Pos    6UL
#define LPDDR4_LPDDR4_CORE_LPMR2_FS0_WLS_Msk    0x40UL
#define LPDDR4_LPDDR4_CORE_LPMR2_WRLEV_Pos      7UL
#define LPDDR4_LPDDR4_CORE_LPMR2_WRLEV_Msk      0x80UL
#define LPDDR4_LPDDR4_CORE_LPMR2_FS1_RL_Pos     8UL
#define LPDDR4_LPDDR4_CORE_LPMR2_FS1_RL_Msk     0x700UL
#define LPDDR4_LPDDR4_CORE_LPMR2_FS1_WL_Pos     11UL
#define LPDDR4_LPDDR4_CORE_LPMR2_FS1_WL_Msk     0x3800UL
#define LPDDR4_LPDDR4_CORE_LPMR2_FS1_WLS_Pos    14UL
#define LPDDR4_LPDDR4_CORE_LPMR2_FS1_WLS_Msk    0x4000UL
/* LPDDR4_LPDDR4_CORE.LPMR3 */
#define LPDDR4_LPDDR4_CORE_LPMR3_FS0_PUCAL_Pos  0UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS0_PUCAL_Msk  0x1UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS0_WPST_Pos   1UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS0_WPST_Msk   0x2UL
#define LPDDR4_LPDDR4_CORE_LPMR3_PPRP_Pos       2UL
#define LPDDR4_LPDDR4_CORE_LPMR3_PPRP_Msk       0x4UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS0_PDDS_Pos   3UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS0_PDDS_Msk   0x38UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS0_RDBI_Pos   6UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS0_RDBI_Msk   0x40UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS0_WDBI_Pos   7UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS0_WDBI_Msk   0x80UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS1_PUCAL_Pos  8UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS1_PUCAL_Msk  0x100UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS1_WPST_Pos   9UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS1_WPST_Msk   0x200UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS1_PDDS_Pos   10UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS1_PDDS_Msk   0x1C00UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS1_RDBI_Pos   13UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS1_RDBI_Msk   0x2000UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS1_WDBI_Pos   14UL
#define LPDDR4_LPDDR4_CORE_LPMR3_FS1_WDBI_Msk   0x4000UL
/* LPDDR4_LPDDR4_CORE.LPMR11 */
#define LPDDR4_LPDDR4_CORE_LPMR11_FS0_DQODT_Pos 0UL
#define LPDDR4_LPDDR4_CORE_LPMR11_FS0_DQODT_Msk 0x7UL
#define LPDDR4_LPDDR4_CORE_LPMR11_FS0_CAODT_Pos 3UL
#define LPDDR4_LPDDR4_CORE_LPMR11_FS0_CAODT_Msk 0x38UL
#define LPDDR4_LPDDR4_CORE_LPMR11_FS1_DQODT_Pos 6UL
#define LPDDR4_LPDDR4_CORE_LPMR11_FS1_DQODT_Msk 0x1C0UL
#define LPDDR4_LPDDR4_CORE_LPMR11_FS1_CAODT_Pos 9UL
#define LPDDR4_LPDDR4_CORE_LPMR11_FS1_CAODT_Msk 0xE00UL
/* LPDDR4_LPDDR4_CORE.LPMR12 */
#define LPDDR4_LPDDR4_CORE_LPMR12_FS0_VREFCAS_Pos 0UL
#define LPDDR4_LPDDR4_CORE_LPMR12_FS0_VREFCAS_Msk 0x3FUL
#define LPDDR4_LPDDR4_CORE_LPMR12_FS0_VREFCAR_Pos 6UL
#define LPDDR4_LPDDR4_CORE_LPMR12_FS0_VREFCAR_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_LPMR12_FS1_VREFCAS_Pos 7UL
#define LPDDR4_LPDDR4_CORE_LPMR12_FS1_VREFCAS_Msk 0x1F80UL
#define LPDDR4_LPDDR4_CORE_LPMR12_FS1_VREFCAR_Pos 13UL
#define LPDDR4_LPDDR4_CORE_LPMR12_FS1_VREFCAR_Msk 0x2000UL
/* LPDDR4_LPDDR4_CORE.LPMR13 */
#define LPDDR4_LPDDR4_CORE_LPMR13_CBT_Pos       0UL
#define LPDDR4_LPDDR4_CORE_LPMR13_CBT_Msk       0x1UL
#define LPDDR4_LPDDR4_CORE_LPMR13_RPT_Pos       1UL
#define LPDDR4_LPDDR4_CORE_LPMR13_RPT_Msk       0x2UL
#define LPDDR4_LPDDR4_CORE_LPMR13_VRO_Pos       2UL
#define LPDDR4_LPDDR4_CORE_LPMR13_VRO_Msk       0x4UL
#define LPDDR4_LPDDR4_CORE_LPMR13_VRCG_Pos      3UL
#define LPDDR4_LPDDR4_CORE_LPMR13_VRCG_Msk      0x8UL
#define LPDDR4_LPDDR4_CORE_LPMR13_RRO_Pos       4UL
#define LPDDR4_LPDDR4_CORE_LPMR13_RRO_Msk       0x10UL
#define LPDDR4_LPDDR4_CORE_LPMR13_DMD_Pos       5UL
#define LPDDR4_LPDDR4_CORE_LPMR13_DMD_Msk       0x20UL
#define LPDDR4_LPDDR4_CORE_LPMR13_FSPWR_Pos     6UL
#define LPDDR4_LPDDR4_CORE_LPMR13_FSPWR_Msk     0x40UL
#define LPDDR4_LPDDR4_CORE_LPMR13_FSPOP_Pos     7UL
#define LPDDR4_LPDDR4_CORE_LPMR13_FSPOP_Msk     0x80UL
/* LPDDR4_LPDDR4_CORE.LPMR14 */
#define LPDDR4_LPDDR4_CORE_LPMR14_FS0_VREFDQS_Pos 0UL
#define LPDDR4_LPDDR4_CORE_LPMR14_FS0_VREFDQS_Msk 0x3FUL
#define LPDDR4_LPDDR4_CORE_LPMR14_FS0_VREFDQR_Pos 6UL
#define LPDDR4_LPDDR4_CORE_LPMR14_FS0_VREFDQR_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_LPMR14_FS1_VREFDQS_Pos 7UL
#define LPDDR4_LPDDR4_CORE_LPMR14_FS1_VREFDQS_Msk 0x1F80UL
#define LPDDR4_LPDDR4_CORE_LPMR14_FS1_VREFDQR_Pos 13UL
#define LPDDR4_LPDDR4_CORE_LPMR14_FS1_VREFDQR_Msk 0x2000UL
/* LPDDR4_LPDDR4_CORE.LPMR22 */
#define LPDDR4_LPDDR4_CORE_LPMR22_FS0_SOCODT_Pos 0UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS0_SOCODT_Msk 0x7UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS0_ODTECK_Pos 3UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS0_ODTECK_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS0_ODTECS_Pos 4UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS0_ODTECS_Msk 0x10UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS0_ODTDCA_Pos 5UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS0_ODTDCA_Msk 0x20UL
#define LPDDR4_LPDDR4_CORE_LPMR22_ODTDX8_Pos    6UL
#define LPDDR4_LPDDR4_CORE_LPMR22_ODTDX8_Msk    0xC0UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS1_SOCODT_Pos 8UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS1_SOCODT_Msk 0x700UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS1_ODTECK_Pos 11UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS1_ODTECK_Msk 0x800UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS1_ODTECS_Pos 12UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS1_ODTECS_Msk 0x1000UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS1_ODTDCA_Pos 13UL
#define LPDDR4_LPDDR4_CORE_LPMR22_FS1_ODTDCA_Msk 0x2000UL
/* LPDDR4_LPDDR4_CORE.RTCFG0_RT0 */
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_EXT_PRI_Pos 0UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_EXT_PRI_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_MAX_PRI_Pos 1UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_MAX_PRI_Msk 0x2UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_ARQ_LVL_HI_Pos 2UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_ARQ_LVL_HI_Msk 0x3CUL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_ARQ_LVL_LO_Pos 6UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_ARQ_LVL_LO_Msk 0x3C0UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_AWQ_LVL_HI_Pos 10UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_AWQ_LVL_HI_Msk 0x3C00UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_AWQ_LVL_LO_Pos 14UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_AWQ_LVL_LO_Msk 0x3C000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_ARQ_LAT_BARRIER_EN_Pos 18UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_ARQ_LAT_BARRIER_EN_Msk 0x40000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_AWQ_LAT_BARRIER_EN_Pos 19UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_AWQ_LAT_BARRIER_EN_Msk 0x80000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_ARQ_OOO_EN_Pos 20UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_ARQ_OOO_EN_Msk 0x100000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_AWQ_OOO_EN_Pos 21UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_AWQ_OOO_EN_Msk 0x200000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_ACQ_REALTIME_EN_Pos 22UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_ACQ_REALTIME_EN_Msk 0x400000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_WM_ENABLE_Pos 23UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT0_WM_ENABLE_Msk 0x800000UL
/* LPDDR4_LPDDR4_CORE.RTCFG0_RT1 */
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_EXT_PRI_Pos 0UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_EXT_PRI_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_MAX_PRI_Pos 1UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_MAX_PRI_Msk 0x2UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_ARQ_LVL_HI_Pos 2UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_ARQ_LVL_HI_Msk 0x3CUL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_ARQ_LVL_LO_Pos 6UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_ARQ_LVL_LO_Msk 0x3C0UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_AWQ_LVL_HI_Pos 10UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_AWQ_LVL_HI_Msk 0x3C00UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_AWQ_LVL_LO_Pos 14UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_AWQ_LVL_LO_Msk 0x3C000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_ARQ_LAT_BARRIER_EN_Pos 18UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_ARQ_LAT_BARRIER_EN_Msk 0x40000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_AWQ_LAT_BARRIER_EN_Pos 19UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_AWQ_LAT_BARRIER_EN_Msk 0x80000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_ARQ_OOO_EN_Pos 20UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_ARQ_OOO_EN_Msk 0x100000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_AWQ_OOO_EN_Pos 21UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_AWQ_OOO_EN_Msk 0x200000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_ACQ_REALTIME_EN_Pos 22UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_ACQ_REALTIME_EN_Msk 0x400000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_WM_ENABLE_Pos 23UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT1_WM_ENABLE_Msk 0x800000UL
/* LPDDR4_LPDDR4_CORE.RTCFG0_RT2 */
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_EXT_PRI_Pos 0UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_EXT_PRI_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_MAX_PRI_Pos 1UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_MAX_PRI_Msk 0x2UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_ARQ_LVL_HI_Pos 2UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_ARQ_LVL_HI_Msk 0x3CUL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_ARQ_LVL_LO_Pos 6UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_ARQ_LVL_LO_Msk 0x3C0UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_AWQ_LVL_HI_Pos 10UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_AWQ_LVL_HI_Msk 0x3C00UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_AWQ_LVL_LO_Pos 14UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_AWQ_LVL_LO_Msk 0x3C000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_ARQ_LAT_BARRIER_EN_Pos 18UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_ARQ_LAT_BARRIER_EN_Msk 0x40000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_AWQ_LAT_BARRIER_EN_Pos 19UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_AWQ_LAT_BARRIER_EN_Msk 0x80000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_ARQ_OOO_EN_Pos 20UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_ARQ_OOO_EN_Msk 0x100000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_AWQ_OOO_EN_Pos 21UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_AWQ_OOO_EN_Msk 0x200000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_ACQ_REALTIME_EN_Pos 22UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_ACQ_REALTIME_EN_Msk 0x400000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_WM_ENABLE_Pos 23UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT2_WM_ENABLE_Msk 0x800000UL
/* LPDDR4_LPDDR4_CORE.RTCFG0_RT3 */
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_EXT_PRI_Pos 0UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_EXT_PRI_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_MAX_PRI_Pos 1UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_MAX_PRI_Msk 0x2UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_ARQ_LVL_HI_Pos 2UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_ARQ_LVL_HI_Msk 0x3CUL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_ARQ_LVL_LO_Pos 6UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_ARQ_LVL_LO_Msk 0x3C0UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_AWQ_LVL_HI_Pos 10UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_AWQ_LVL_HI_Msk 0x3C00UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_AWQ_LVL_LO_Pos 14UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_AWQ_LVL_LO_Msk 0x3C000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_ARQ_LAT_BARRIER_EN_Pos 18UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_ARQ_LAT_BARRIER_EN_Msk 0x40000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_AWQ_LAT_BARRIER_EN_Pos 19UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_AWQ_LAT_BARRIER_EN_Msk 0x80000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_ARQ_OOO_EN_Pos 20UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_ARQ_OOO_EN_Msk 0x100000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_AWQ_OOO_EN_Pos 21UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_AWQ_OOO_EN_Msk 0x200000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_ACQ_REALTIME_EN_Pos 22UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_ACQ_REALTIME_EN_Msk 0x400000UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_WM_ENABLE_Pos 23UL
#define LPDDR4_LPDDR4_CORE_RTCFG0_RT3_WM_ENABLE_Msk 0x800000UL
/* LPDDR4_LPDDR4_CORE.RTCFG1_RT0 */
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT0_ARQ_LAT_BARRIER_Pos 0UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT0_ARQ_LAT_BARRIER_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT0_AWQ_LAT_BARRIER_Pos 8UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT0_AWQ_LAT_BARRIER_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT0_ARQ_STARV_TH_Pos 16UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT0_ARQ_STARV_TH_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT0_AWQ_STARV_TH_Pos 24UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT0_AWQ_STARV_TH_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.RTCFG1_RT1 */
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT1_ARQ_LAT_BARRIER_Pos 0UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT1_ARQ_LAT_BARRIER_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT1_AWQ_LAT_BARRIER_Pos 8UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT1_AWQ_LAT_BARRIER_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT1_ARQ_STARV_TH_Pos 16UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT1_ARQ_STARV_TH_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT1_AWQ_STARV_TH_Pos 24UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT1_AWQ_STARV_TH_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.RTCFG1_RT2 */
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT2_ARQ_LAT_BARRIER_Pos 0UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT2_ARQ_LAT_BARRIER_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT2_AWQ_LAT_BARRIER_Pos 8UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT2_AWQ_LAT_BARRIER_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT2_ARQ_STARV_TH_Pos 16UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT2_ARQ_STARV_TH_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT2_AWQ_STARV_TH_Pos 24UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT2_AWQ_STARV_TH_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.RTCFG1_RT3 */
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT3_ARQ_LAT_BARRIER_Pos 0UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT3_ARQ_LAT_BARRIER_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT3_AWQ_LAT_BARRIER_Pos 8UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT3_AWQ_LAT_BARRIER_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT3_ARQ_STARV_TH_Pos 16UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT3_ARQ_STARV_TH_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT3_AWQ_STARV_TH_Pos 24UL
#define LPDDR4_LPDDR4_CORE_RTCFG1_RT3_AWQ_STARV_TH_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.ADDR0 */
#define LPDDR4_LPDDR4_CORE_ADDR0_COL_ADDR_MAP_B0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_ADDR0_COL_ADDR_MAP_B0_Msk 0x1FUL
#define LPDDR4_LPDDR4_CORE_ADDR0_COL_ADDR_MAP_B1_Pos 5UL
#define LPDDR4_LPDDR4_CORE_ADDR0_COL_ADDR_MAP_B1_Msk 0x3E0UL
#define LPDDR4_LPDDR4_CORE_ADDR0_COL_ADDR_MAP_B2_Pos 10UL
#define LPDDR4_LPDDR4_CORE_ADDR0_COL_ADDR_MAP_B2_Msk 0x7C00UL
#define LPDDR4_LPDDR4_CORE_ADDR0_COL_ADDR_MAP_B3_Pos 15UL
#define LPDDR4_LPDDR4_CORE_ADDR0_COL_ADDR_MAP_B3_Msk 0xF8000UL
#define LPDDR4_LPDDR4_CORE_ADDR0_COL_ADDR_MAP_B4_Pos 20UL
#define LPDDR4_LPDDR4_CORE_ADDR0_COL_ADDR_MAP_B4_Msk 0x1F00000UL
#define LPDDR4_LPDDR4_CORE_ADDR0_COL_ADDR_MAP_B5_Pos 25UL
#define LPDDR4_LPDDR4_CORE_ADDR0_COL_ADDR_MAP_B5_Msk 0x3E000000UL
/* LPDDR4_LPDDR4_CORE.ADDR1 */
#define LPDDR4_LPDDR4_CORE_ADDR1_COL_ADDR_MAP_B6_Pos 0UL
#define LPDDR4_LPDDR4_CORE_ADDR1_COL_ADDR_MAP_B6_Msk 0x1FUL
#define LPDDR4_LPDDR4_CORE_ADDR1_COL_ADDR_MAP_B7_Pos 5UL
#define LPDDR4_LPDDR4_CORE_ADDR1_COL_ADDR_MAP_B7_Msk 0x3E0UL
#define LPDDR4_LPDDR4_CORE_ADDR1_COL_ADDR_MAP_B8_Pos 10UL
#define LPDDR4_LPDDR4_CORE_ADDR1_COL_ADDR_MAP_B8_Msk 0x7C00UL
#define LPDDR4_LPDDR4_CORE_ADDR1_COL_ADDR_MAP_B9_Pos 15UL
#define LPDDR4_LPDDR4_CORE_ADDR1_COL_ADDR_MAP_B9_Msk 0xF8000UL
/* LPDDR4_LPDDR4_CORE.ADDR2 */
#define LPDDR4_LPDDR4_CORE_ADDR2_ROW_ADDR_MAP_B0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_ADDR2_ROW_ADDR_MAP_B0_Msk 0x1FUL
#define LPDDR4_LPDDR4_CORE_ADDR2_ROW_ADDR_MAP_B1_Pos 5UL
#define LPDDR4_LPDDR4_CORE_ADDR2_ROW_ADDR_MAP_B1_Msk 0x3E0UL
#define LPDDR4_LPDDR4_CORE_ADDR2_ROW_ADDR_MAP_B2_Pos 10UL
#define LPDDR4_LPDDR4_CORE_ADDR2_ROW_ADDR_MAP_B2_Msk 0x7C00UL
#define LPDDR4_LPDDR4_CORE_ADDR2_ROW_ADDR_MAP_B3_Pos 15UL
#define LPDDR4_LPDDR4_CORE_ADDR2_ROW_ADDR_MAP_B3_Msk 0xF8000UL
#define LPDDR4_LPDDR4_CORE_ADDR2_ROW_ADDR_MAP_B4_Pos 20UL
#define LPDDR4_LPDDR4_CORE_ADDR2_ROW_ADDR_MAP_B4_Msk 0x1F00000UL
#define LPDDR4_LPDDR4_CORE_ADDR2_ROW_ADDR_MAP_B5_Pos 25UL
#define LPDDR4_LPDDR4_CORE_ADDR2_ROW_ADDR_MAP_B5_Msk 0x3E000000UL
/* LPDDR4_LPDDR4_CORE.ADDR3 */
#define LPDDR4_LPDDR4_CORE_ADDR3_ROW_ADDR_MAP_B6_Pos 0UL
#define LPDDR4_LPDDR4_CORE_ADDR3_ROW_ADDR_MAP_B6_Msk 0x1FUL
#define LPDDR4_LPDDR4_CORE_ADDR3_ROW_ADDR_MAP_B7_Pos 5UL
#define LPDDR4_LPDDR4_CORE_ADDR3_ROW_ADDR_MAP_B7_Msk 0x3E0UL
#define LPDDR4_LPDDR4_CORE_ADDR3_ROW_ADDR_MAP_B8_Pos 10UL
#define LPDDR4_LPDDR4_CORE_ADDR3_ROW_ADDR_MAP_B8_Msk 0x7C00UL
#define LPDDR4_LPDDR4_CORE_ADDR3_ROW_ADDR_MAP_B9_Pos 15UL
#define LPDDR4_LPDDR4_CORE_ADDR3_ROW_ADDR_MAP_B9_Msk 0xF8000UL
#define LPDDR4_LPDDR4_CORE_ADDR3_ROW_ADDR_MAP_B10_Pos 20UL
#define LPDDR4_LPDDR4_CORE_ADDR3_ROW_ADDR_MAP_B10_Msk 0x1F00000UL
#define LPDDR4_LPDDR4_CORE_ADDR3_ROW_ADDR_MAP_B11_Pos 25UL
#define LPDDR4_LPDDR4_CORE_ADDR3_ROW_ADDR_MAP_B11_Msk 0x3E000000UL
/* LPDDR4_LPDDR4_CORE.ADDR4 */
#define LPDDR4_LPDDR4_CORE_ADDR4_ROW_ADDR_MAP_B12_Pos 0UL
#define LPDDR4_LPDDR4_CORE_ADDR4_ROW_ADDR_MAP_B12_Msk 0x1FUL
#define LPDDR4_LPDDR4_CORE_ADDR4_ROW_ADDR_MAP_B13_Pos 5UL
#define LPDDR4_LPDDR4_CORE_ADDR4_ROW_ADDR_MAP_B13_Msk 0x3E0UL
#define LPDDR4_LPDDR4_CORE_ADDR4_ROW_ADDR_MAP_B14_Pos 10UL
#define LPDDR4_LPDDR4_CORE_ADDR4_ROW_ADDR_MAP_B14_Msk 0x7C00UL
/* LPDDR4_LPDDR4_CORE.ADDR5 */
#define LPDDR4_LPDDR4_CORE_ADDR5_BANK_ADDR_MAP_B0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_ADDR5_BANK_ADDR_MAP_B0_Msk 0x1FUL
#define LPDDR4_LPDDR4_CORE_ADDR5_BANK_ADDR_MAP_B1_Pos 5UL
#define LPDDR4_LPDDR4_CORE_ADDR5_BANK_ADDR_MAP_B1_Msk 0x3E0UL
#define LPDDR4_LPDDR4_CORE_ADDR5_BANK_ADDR_MAP_B2_Pos 10UL
#define LPDDR4_LPDDR4_CORE_ADDR5_BANK_ADDR_MAP_B2_Msk 0x7C00UL
#define LPDDR4_LPDDR4_CORE_ADDR5_CHAN_ADDR_MAP_B0_Pos 15UL
#define LPDDR4_LPDDR4_CORE_ADDR5_CHAN_ADDR_MAP_B0_Msk 0xF8000UL
/* LPDDR4_LPDDR4_CORE.PHY */
#define LPDDR4_LPDDR4_CORE_PHY_DTI_DRAM_CLK_DIS_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PHY_DTI_DRAM_CLK_DIS_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_PHY_DTI_DATA_BYTE_DIS_Pos 1UL
#define LPDDR4_LPDDR4_CORE_PHY_DTI_DATA_BYTE_DIS_Msk 0x1EUL
/* LPDDR4_LPDDR4_CORE.POM */
#define LPDDR4_LPDDR4_CORE_POM_POM_CHANEN_Pos   0UL
#define LPDDR4_LPDDR4_CORE_POM_POM_CHANEN_Msk   0x3UL
#define LPDDR4_LPDDR4_CORE_POM_POM_DFIEN_Pos    2UL
#define LPDDR4_LPDDR4_CORE_POM_POM_DFIEN_Msk    0x4UL
#define LPDDR4_LPDDR4_CORE_POM_POM_PROC_Pos     3UL
#define LPDDR4_LPDDR4_CORE_POM_POM_PROC_Msk     0x8UL
#define LPDDR4_LPDDR4_CORE_POM_POM_PHYSETEN_Pos 4UL
#define LPDDR4_LPDDR4_CORE_POM_POM_PHYSETEN_Msk 0x10UL
#define LPDDR4_LPDDR4_CORE_POM_POM_PHYFSEN_Pos  5UL
#define LPDDR4_LPDDR4_CORE_POM_POM_PHYFSEN_Msk  0x20UL
#define LPDDR4_LPDDR4_CORE_POM_POM_PHYINIT_Pos  6UL
#define LPDDR4_LPDDR4_CORE_POM_POM_PHYINIT_Msk  0x40UL
#define LPDDR4_LPDDR4_CORE_POM_POM_DLLRSTEN_Pos 7UL
#define LPDDR4_LPDDR4_CORE_POM_POM_DLLRSTEN_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_POM_POM_DRAMINITEN_Pos 8UL
#define LPDDR4_LPDDR4_CORE_POM_POM_DRAMINITEN_Msk 0x100UL
#define LPDDR4_LPDDR4_CORE_POM_POM_VREFDQRDEN_Pos 9UL
#define LPDDR4_LPDDR4_CORE_POM_POM_VREFDQRDEN_Msk 0x200UL
#define LPDDR4_LPDDR4_CORE_POM_POM_VREFCAEN_Pos 10UL
#define LPDDR4_LPDDR4_CORE_POM_POM_VREFCAEN_Msk 0x400UL
#define LPDDR4_LPDDR4_CORE_POM_POM_GTEN_Pos     11UL
#define LPDDR4_LPDDR4_CORE_POM_POM_GTEN_Msk     0x800UL
#define LPDDR4_LPDDR4_CORE_POM_POM_WRLVLEN_Pos  12UL
#define LPDDR4_LPDDR4_CORE_POM_POM_WRLVLEN_Msk  0x1000UL
#define LPDDR4_LPDDR4_CORE_POM_POM_RDLVLEN_Pos  13UL
#define LPDDR4_LPDDR4_CORE_POM_POM_RDLVLEN_Msk  0x2000UL
#define LPDDR4_LPDDR4_CORE_POM_POM_VREFDQWREN_Pos 14UL
#define LPDDR4_LPDDR4_CORE_POM_POM_VREFDQWREN_Msk 0x4000UL
#define LPDDR4_LPDDR4_CORE_POM_POM_DLYEVALEN_Pos 15UL
#define LPDDR4_LPDDR4_CORE_POM_POM_DLYEVALEN_Msk 0x8000UL
#define LPDDR4_LPDDR4_CORE_POM_POM_SANCHKEN_Pos 16UL
#define LPDDR4_LPDDR4_CORE_POM_POM_SANCHKEN_Msk 0x10000UL
#define LPDDR4_LPDDR4_CORE_POM_POM_FS_Pos       17UL
#define LPDDR4_LPDDR4_CORE_POM_POM_FS_Msk       0x20000UL
#define LPDDR4_LPDDR4_CORE_POM_POM_CLKLOCKEN_Pos 18UL
#define LPDDR4_LPDDR4_CORE_POM_POM_CLKLOCKEN_Msk 0x40000UL
#define LPDDR4_LPDDR4_CORE_POM_POM_CMDDLYEN_Pos 19UL
#define LPDDR4_LPDDR4_CORE_POM_POM_CMDDLYEN_Msk 0x80000UL
#define LPDDR4_LPDDR4_CORE_POM_POM_PWDEXIT_Pos  20UL
#define LPDDR4_LPDDR4_CORE_POM_POM_PWDEXIT_Msk  0x100000UL
#define LPDDR4_LPDDR4_CORE_POM_POM_ODT_Pos      21UL
#define LPDDR4_LPDDR4_CORE_POM_POM_ODT_Msk      0x200000UL
#define LPDDR4_LPDDR4_CORE_POM_POM_DQSDQEN_Pos  22UL
#define LPDDR4_LPDDR4_CORE_POM_POM_DQSDQEN_Msk  0x400000UL
/* LPDDR4_LPDDR4_CORE.DLLCTLCA_CH0 */
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_LIMIT_Pos 0UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_LIMIT_Msk 0x1FUL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_EN_Pos  5UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_EN_Msk  0x20UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_UPD_Pos 6UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_UPD_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_BYP_Pos 7UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_BYP_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_BYPC_Pos 8UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_BYPC_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_CLKDLY_Pos 16UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH0_CLKDLY_Msk 0x3F0000UL
/* LPDDR4_LPDDR4_CORE.DLLCTLCA_CH1 */
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_LIMIT_Pos 0UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_LIMIT_Msk 0x1FUL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_EN_Pos  5UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_EN_Msk  0x20UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_UPD_Pos 6UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_UPD_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_BYP_Pos 7UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_BYP_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_BYPC_Pos 8UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_BYPC_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_CLKDLY_Pos 16UL
#define LPDDR4_LPDDR4_CORE_DLLCTLCA_CH1_CLKDLY_Msk 0x3F0000UL
/* LPDDR4_LPDDR4_CORE.DLLCTLDQ_SL0 */
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_LIMIT_Pos 0UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_LIMIT_Msk 0x1FUL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_EN_Pos  5UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_EN_Msk  0x20UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_UPD_Pos 6UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_UPD_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_BYP_Pos 7UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_BYP_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_BYPC_Pos 8UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL0_BYPC_Msk 0xFF00UL
/* LPDDR4_LPDDR4_CORE.DLLCTLDQ_SL1 */
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_LIMIT_Pos 0UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_LIMIT_Msk 0x1FUL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_EN_Pos  5UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_EN_Msk  0x20UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_UPD_Pos 6UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_UPD_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_BYP_Pos 7UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_BYP_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_BYPC_Pos 8UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL1_BYPC_Msk 0xFF00UL
/* LPDDR4_LPDDR4_CORE.DLLCTLDQ_SL2 */
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_LIMIT_Pos 0UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_LIMIT_Msk 0x1FUL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_EN_Pos  5UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_EN_Msk  0x20UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_UPD_Pos 6UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_UPD_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_BYP_Pos 7UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_BYP_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_BYPC_Pos 8UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL2_BYPC_Msk 0xFF00UL
/* LPDDR4_LPDDR4_CORE.DLLCTLDQ_SL3 */
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_LIMIT_Pos 0UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_LIMIT_Msk 0x1FUL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_EN_Pos  5UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_EN_Msk  0x20UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_UPD_Pos 6UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_UPD_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_BYP_Pos 7UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_BYP_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_BYPC_Pos 8UL
#define LPDDR4_LPDDR4_CORE_DLLCTLDQ_SL3_BYPC_Msk 0xFF00UL
/* LPDDR4_LPDDR4_CORE.RTGC0 */
#define LPDDR4_LPDDR4_CORE_RTGC0_GT_UPDT_Pos    0UL
#define LPDDR4_LPDDR4_CORE_RTGC0_GT_UPDT_Msk    0x1UL
#define LPDDR4_LPDDR4_CORE_RTGC0_GT_DIS_Pos     1UL
#define LPDDR4_LPDDR4_CORE_RTGC0_GT_DIS_Msk     0x2UL
#define LPDDR4_LPDDR4_CORE_RTGC0_FS0_TWREN_Pos  2UL
#define LPDDR4_LPDDR4_CORE_RTGC0_FS0_TWREN_Msk  0xFCUL
#define LPDDR4_LPDDR4_CORE_RTGC0_FS0_TRDEN_Pos  8UL
#define LPDDR4_LPDDR4_CORE_RTGC0_FS0_TRDEN_Msk  0x3F00UL
#define LPDDR4_LPDDR4_CORE_RTGC0_FS0_TRDENDBI_Pos 14UL
#define LPDDR4_LPDDR4_CORE_RTGC0_FS0_TRDENDBI_Msk 0x1FC000UL
/* LPDDR4_LPDDR4_CORE.RTGC1 */
#define LPDDR4_LPDDR4_CORE_RTGC1_FS1_TWREN_Pos  0UL
#define LPDDR4_LPDDR4_CORE_RTGC1_FS1_TWREN_Msk  0x3FUL
#define LPDDR4_LPDDR4_CORE_RTGC1_FS1_TRDEN_Pos  6UL
#define LPDDR4_LPDDR4_CORE_RTGC1_FS1_TRDEN_Msk  0xFC0UL
#define LPDDR4_LPDDR4_CORE_RTGC1_FS1_TRDENDBI_Pos 12UL
#define LPDDR4_LPDDR4_CORE_RTGC1_FS1_TRDENDBI_Msk 0x7F000UL
/* LPDDR4_LPDDR4_CORE.PTAR */
#define LPDDR4_LPDDR4_CORE_PTAR_BA_Pos          0UL
#define LPDDR4_LPDDR4_CORE_PTAR_BA_Msk          0x7UL
#define LPDDR4_LPDDR4_CORE_PTAR_ROW_Pos         3UL
#define LPDDR4_LPDDR4_CORE_PTAR_ROW_Msk         0x3FFF8UL
#define LPDDR4_LPDDR4_CORE_PTAR_COL_Pos         18UL
#define LPDDR4_LPDDR4_CORE_PTAR_COL_Msk         0xFFC0000UL
/* LPDDR4_LPDDR4_CORE.VTGC */
#define LPDDR4_LPDDR4_CORE_VTGC_IVREFR_Pos      0UL
#define LPDDR4_LPDDR4_CORE_VTGC_IVREFR_Msk      0x1UL
#define LPDDR4_LPDDR4_CORE_VTGC_IVREFTS_Pos     1UL
#define LPDDR4_LPDDR4_CORE_VTGC_IVREFTS_Msk     0x1FEUL
#define LPDDR4_LPDDR4_CORE_VTGC_VREFDQSW_Pos    9UL
#define LPDDR4_LPDDR4_CORE_VTGC_VREFDQSW_Msk    0x7E00UL
#define LPDDR4_LPDDR4_CORE_VTGC_VREFCASW_Pos    15UL
#define LPDDR4_LPDDR4_CORE_VTGC_VREFCASW_Msk    0x1F8000UL
#define LPDDR4_LPDDR4_CORE_VTGC_IVREFEN_Pos     21UL
#define LPDDR4_LPDDR4_CORE_VTGC_IVREFEN_Msk     0x200000UL
/* LPDDR4_LPDDR4_CORE.PBCR */
#define LPDDR4_LPDDR4_CORE_PBCR_BIST_EN_Pos     0UL
#define LPDDR4_LPDDR4_CORE_PBCR_BIST_EN_Msk     0x1UL
#define LPDDR4_LPDDR4_CORE_PBCR_BIST_START_Pos  1UL
#define LPDDR4_LPDDR4_CORE_PBCR_BIST_START_Msk  0x2UL
#define LPDDR4_LPDDR4_CORE_PBCR_LP_EN_Pos       2UL
#define LPDDR4_LPDDR4_CORE_PBCR_LP_EN_Msk       0x4UL
#define LPDDR4_LPDDR4_CORE_PBCR_VREFENCA_C0_Pos 3UL
#define LPDDR4_LPDDR4_CORE_PBCR_VREFENCA_C0_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_PBCR_VREFSETCA_C0_Pos 4UL
#define LPDDR4_LPDDR4_CORE_PBCR_VREFSETCA_C0_Msk 0x3F0UL
#define LPDDR4_LPDDR4_CORE_PBCR_VREFENCA_C1_Pos 10UL
#define LPDDR4_LPDDR4_CORE_PBCR_VREFENCA_C1_Msk 0x400UL
#define LPDDR4_LPDDR4_CORE_PBCR_VREFSETCA_C1_Pos 11UL
#define LPDDR4_LPDDR4_CORE_PBCR_VREFSETCA_C1_Msk 0x1F800UL
/* LPDDR4_LPDDR4_CORE.CIOR_CH0 */
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_DRVSEL_Pos  0UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_DRVSEL_Msk  0x7UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_CMOS_EN_Pos 3UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_CMOS_EN_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_ODIS_RESETN_Pos 4UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_ODIS_RESETN_Msk 0x10UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_ODIS_ODT_Pos 5UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_ODIS_ODT_Msk 0x20UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_ODIS_CS_Pos 6UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_ODIS_CS_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_ODIS_CLK_Pos 7UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_ODIS_CLK_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_ODIS_CKE_Pos 8UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_ODIS_CKE_Msk 0x100UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_ODIS_CA_Pos 9UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH0_ODIS_CA_Msk 0x7E00UL
/* LPDDR4_LPDDR4_CORE.CIOR_CH1 */
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_DRVSEL_Pos  0UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_DRVSEL_Msk  0x7UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_CMOS_EN_Pos 3UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_CMOS_EN_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_ODIS_RESETN_Pos 4UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_ODIS_RESETN_Msk 0x10UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_ODIS_ODT_Pos 5UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_ODIS_ODT_Msk 0x20UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_ODIS_CS_Pos 6UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_ODIS_CS_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_ODIS_CLK_Pos 7UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_ODIS_CLK_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_ODIS_CKE_Pos 8UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_ODIS_CKE_Msk 0x100UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_ODIS_CA_Pos 9UL
#define LPDDR4_LPDDR4_CORE_CIOR_CH1_ODIS_CA_Msk 0x7E00UL
/* LPDDR4_LPDDR4_CORE.DIOR_SL0 */
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_DRVSEL_Pos  0UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_DRVSEL_Msk  0x7UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_CMOS_EN_Pos 3UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_CMOS_EN_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_FENA_RCV_Pos 4UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_FENA_RCV_Msk 0x10UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_RTT_EN_Pos  5UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_RTT_EN_Msk  0x20UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_RTT_SEL_Pos 6UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_RTT_SEL_Msk 0x1C0UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_ODIS_DQ_Pos 9UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_ODIS_DQ_Msk 0x1FE00UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_ODIS_DM_Pos 17UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_ODIS_DM_Msk 0x20000UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_ODIS_DQS_Pos 18UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL0_ODIS_DQS_Msk 0x40000UL
/* LPDDR4_LPDDR4_CORE.DIOR_SL1 */
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_DRVSEL_Pos  0UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_DRVSEL_Msk  0x7UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_CMOS_EN_Pos 3UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_CMOS_EN_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_FENA_RCV_Pos 4UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_FENA_RCV_Msk 0x10UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_RTT_EN_Pos  5UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_RTT_EN_Msk  0x20UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_RTT_SEL_Pos 6UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_RTT_SEL_Msk 0x1C0UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_ODIS_DQ_Pos 9UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_ODIS_DQ_Msk 0x1FE00UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_ODIS_DM_Pos 17UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_ODIS_DM_Msk 0x20000UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_ODIS_DQS_Pos 18UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL1_ODIS_DQS_Msk 0x40000UL
/* LPDDR4_LPDDR4_CORE.DIOR_SL2 */
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_DRVSEL_Pos  0UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_DRVSEL_Msk  0x7UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_CMOS_EN_Pos 3UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_CMOS_EN_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_FENA_RCV_Pos 4UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_FENA_RCV_Msk 0x10UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_RTT_EN_Pos  5UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_RTT_EN_Msk  0x20UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_RTT_SEL_Pos 6UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_RTT_SEL_Msk 0x1C0UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_ODIS_DQ_Pos 9UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_ODIS_DQ_Msk 0x1FE00UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_ODIS_DM_Pos 17UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_ODIS_DM_Msk 0x20000UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_ODIS_DQS_Pos 18UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL2_ODIS_DQS_Msk 0x40000UL
/* LPDDR4_LPDDR4_CORE.DIOR_SL3 */
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_DRVSEL_Pos  0UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_DRVSEL_Msk  0x7UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_CMOS_EN_Pos 3UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_CMOS_EN_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_FENA_RCV_Pos 4UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_FENA_RCV_Msk 0x10UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_RTT_EN_Pos  5UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_RTT_EN_Msk  0x20UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_RTT_SEL_Pos 6UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_RTT_SEL_Msk 0x1C0UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_ODIS_DQ_Pos 9UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_ODIS_DQ_Msk 0x1FE00UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_ODIS_DM_Pos 17UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_ODIS_DM_Msk 0x20000UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_ODIS_DQS_Pos 18UL
#define LPDDR4_LPDDR4_CORE_DIOR_SL3_ODIS_DQS_Msk 0x40000UL
/* LPDDR4_LPDDR4_CORE.PCCR_CH0 */
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_SRST_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_SRST_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_TPADEN_Pos 1UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_TPADEN_Msk 0x2UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_MVG_Pos 2UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_MVG_Msk 0x4UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_EN_Pos 3UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_EN_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_UPD_Pos 4UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_UPD_Msk 0x10UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_BYPEN_Pos 5UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_BYPEN_Msk 0x20UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_BYP_N_Pos 6UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_BYP_N_Msk 0x3C0UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_BYP_P_Pos 10UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_BYP_P_Msk 0x3C00UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_INITCNT_Pos 14UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH0_PCCR_CH0_INITCNT_Msk 0x1FFC000UL
/* LPDDR4_LPDDR4_CORE.PCCR_CH1 */
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_SRST_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_SRST_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_TPADEN_Pos 1UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_TPADEN_Msk 0x2UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_MVG_Pos 2UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_MVG_Msk 0x4UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_EN_Pos 3UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_EN_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_UPD_Pos 4UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_UPD_Msk 0x10UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_BYPEN_Pos 5UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_BYPEN_Msk 0x20UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_BYP_N_Pos 6UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_BYP_N_Msk 0x3C0UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_BYP_P_Pos 10UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_BYP_P_Msk 0x3C00UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_INITCNT_Pos 14UL
#define LPDDR4_LPDDR4_CORE_PCCR_CH1_PCCR_CH1_INITCNT_Msk 0x1FFC000UL
/* LPDDR4_LPDDR4_CORE.DQSDQCR */
#define LPDDR4_LPDDR4_CORE_DQSDQCR_DLYOFFS_Pos  0UL
#define LPDDR4_LPDDR4_CORE_DQSDQCR_DLYOFFS_Msk  0xFFUL
#define LPDDR4_LPDDR4_CORE_DQSDQCR_DQSEL_Pos    8UL
#define LPDDR4_LPDDR4_CORE_DQSDQCR_DQSEL_Msk    0xF00UL
#define LPDDR4_LPDDR4_CORE_DQSDQCR_MUPD_Pos     12UL
#define LPDDR4_LPDDR4_CORE_DQSDQCR_MUPD_Msk     0x1000UL
#define LPDDR4_LPDDR4_CORE_DQSDQCR_MPCRPT_Pos   13UL
#define LPDDR4_LPDDR4_CORE_DQSDQCR_MPCRPT_Msk   0xE000UL
#define LPDDR4_LPDDR4_CORE_DQSDQCR_DLYMAX_Pos   16UL
#define LPDDR4_LPDDR4_CORE_DQSDQCR_DLYMAX_Msk   0xFF0000UL
#define LPDDR4_LPDDR4_CORE_DQSDQCR_DIR_Pos      24UL
#define LPDDR4_LPDDR4_CORE_DQSDQCR_DIR_Msk      0x1000000UL
/* LPDDR4_LPDDR4_CORE.PTSR0 */
#define LPDDR4_LPDDR4_CORE_PTSR0_VREFCAR_Pos    0UL
#define LPDDR4_LPDDR4_CORE_PTSR0_VREFCAR_Msk    0x1UL
#define LPDDR4_LPDDR4_CORE_PTSR0_VREFCAS_Pos    1UL
#define LPDDR4_LPDDR4_CORE_PTSR0_VREFCAS_Msk    0x7EUL
#define LPDDR4_LPDDR4_CORE_PTSR0_CSC0_Pos       7UL
#define LPDDR4_LPDDR4_CORE_PTSR0_CSC0_Msk       0x1F80UL
#define LPDDR4_LPDDR4_CORE_PTSR0_CSC1_Pos       13UL
#define LPDDR4_LPDDR4_CORE_PTSR0_CSC1_Msk       0x7E000UL
#define LPDDR4_LPDDR4_CORE_PTSR0_CAC0B0_Pos     19UL
#define LPDDR4_LPDDR4_CORE_PTSR0_CAC0B0_Msk     0x1F80000UL
#define LPDDR4_LPDDR4_CORE_PTSR0_CAC0B1_Pos     25UL
#define LPDDR4_LPDDR4_CORE_PTSR0_CAC0B1_Msk     0x7E000000UL
/* LPDDR4_LPDDR4_CORE.PTSR1 */
#define LPDDR4_LPDDR4_CORE_PTSR1_CAC0B2_Pos     0UL
#define LPDDR4_LPDDR4_CORE_PTSR1_CAC0B2_Msk     0x3FUL
#define LPDDR4_LPDDR4_CORE_PTSR1_CAC0B3_Pos     6UL
#define LPDDR4_LPDDR4_CORE_PTSR1_CAC0B3_Msk     0xFC0UL
#define LPDDR4_LPDDR4_CORE_PTSR1_CAC0B4_Pos     12UL
#define LPDDR4_LPDDR4_CORE_PTSR1_CAC0B4_Msk     0x3F000UL
#define LPDDR4_LPDDR4_CORE_PTSR1_CAC0B5_Pos     18UL
#define LPDDR4_LPDDR4_CORE_PTSR1_CAC0B5_Msk     0xFC0000UL
#define LPDDR4_LPDDR4_CORE_PTSR1_CAC1B0_Pos     24UL
#define LPDDR4_LPDDR4_CORE_PTSR1_CAC1B0_Msk     0x3F000000UL
/* LPDDR4_LPDDR4_CORE.PTSR2 */
#define LPDDR4_LPDDR4_CORE_PTSR2_CAC1B1_Pos     0UL
#define LPDDR4_LPDDR4_CORE_PTSR2_CAC1B1_Msk     0x3FUL
#define LPDDR4_LPDDR4_CORE_PTSR2_CAC1B2_Pos     6UL
#define LPDDR4_LPDDR4_CORE_PTSR2_CAC1B2_Msk     0xFC0UL
#define LPDDR4_LPDDR4_CORE_PTSR2_CAC1B3_Pos     12UL
#define LPDDR4_LPDDR4_CORE_PTSR2_CAC1B3_Msk     0x3F000UL
#define LPDDR4_LPDDR4_CORE_PTSR2_CAC1B4_Pos     18UL
#define LPDDR4_LPDDR4_CORE_PTSR2_CAC1B4_Msk     0xFC0000UL
#define LPDDR4_LPDDR4_CORE_PTSR2_CAC1B5_Pos     24UL
#define LPDDR4_LPDDR4_CORE_PTSR2_CAC1B5_Msk     0x3F000000UL
/* LPDDR4_LPDDR4_CORE.PTSR3 */
#define LPDDR4_LPDDR4_CORE_PTSR3_GTS0_Pos       0UL
#define LPDDR4_LPDDR4_CORE_PTSR3_GTS0_Msk       0x3FUL
#define LPDDR4_LPDDR4_CORE_PTSR3_GTS1_Pos       6UL
#define LPDDR4_LPDDR4_CORE_PTSR3_GTS1_Msk       0xFC0UL
#define LPDDR4_LPDDR4_CORE_PTSR3_GTS2_Pos       12UL
#define LPDDR4_LPDDR4_CORE_PTSR3_GTS2_Msk       0x3F000UL
#define LPDDR4_LPDDR4_CORE_PTSR3_GTS3_Pos       18UL
#define LPDDR4_LPDDR4_CORE_PTSR3_GTS3_Msk       0xFC0000UL
#define LPDDR4_LPDDR4_CORE_PTSR3_VREFDQWRR_Pos  24UL
#define LPDDR4_LPDDR4_CORE_PTSR3_VREFDQWRR_Msk  0x1000000UL
#define LPDDR4_LPDDR4_CORE_PTSR3_VREFDQWRS_Pos  25UL
#define LPDDR4_LPDDR4_CORE_PTSR3_VREFDQWRS_Msk  0x7E000000UL
/* LPDDR4_LPDDR4_CORE.PTSR4 */
#define LPDDR4_LPDDR4_CORE_PTSR4_WRLVLS0_Pos    0UL
#define LPDDR4_LPDDR4_CORE_PTSR4_WRLVLS0_Msk    0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR4_WRLVLS1_Pos    8UL
#define LPDDR4_LPDDR4_CORE_PTSR4_WRLVLS1_Msk    0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR4_WRLVLS2_Pos    16UL
#define LPDDR4_LPDDR4_CORE_PTSR4_WRLVLS2_Msk    0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR4_WRLVLS3_Pos    24UL
#define LPDDR4_LPDDR4_CORE_PTSR4_WRLVLS3_Msk    0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR5 */
#define LPDDR4_LPDDR4_CORE_PTSR5_DQSDQS0B0_Pos  0UL
#define LPDDR4_LPDDR4_CORE_PTSR5_DQSDQS0B0_Msk  0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR5_DQSDQS0B1_Pos  8UL
#define LPDDR4_LPDDR4_CORE_PTSR5_DQSDQS0B1_Msk  0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR5_DQSDQS0B2_Pos  16UL
#define LPDDR4_LPDDR4_CORE_PTSR5_DQSDQS0B2_Msk  0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR5_DQSDQS0B3_Pos  24UL
#define LPDDR4_LPDDR4_CORE_PTSR5_DQSDQS0B3_Msk  0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR6 */
#define LPDDR4_LPDDR4_CORE_PTSR6_DQSDQS0B4_Pos  0UL
#define LPDDR4_LPDDR4_CORE_PTSR6_DQSDQS0B4_Msk  0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR6_DQSDQS0B5_Pos  8UL
#define LPDDR4_LPDDR4_CORE_PTSR6_DQSDQS0B5_Msk  0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR6_DQSDQS0B6_Pos  16UL
#define LPDDR4_LPDDR4_CORE_PTSR6_DQSDQS0B6_Msk  0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR6_DQSDQS0B7_Pos  24UL
#define LPDDR4_LPDDR4_CORE_PTSR6_DQSDQS0B7_Msk  0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR7 */
#define LPDDR4_LPDDR4_CORE_PTSR7_DQSDQS1B0_Pos  0UL
#define LPDDR4_LPDDR4_CORE_PTSR7_DQSDQS1B0_Msk  0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR7_DQSDQS1B1_Pos  8UL
#define LPDDR4_LPDDR4_CORE_PTSR7_DQSDQS1B1_Msk  0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR7_DQSDQS1B2_Pos  16UL
#define LPDDR4_LPDDR4_CORE_PTSR7_DQSDQS1B2_Msk  0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR7_DQSDQS1B3_Pos  24UL
#define LPDDR4_LPDDR4_CORE_PTSR7_DQSDQS1B3_Msk  0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR8 */
#define LPDDR4_LPDDR4_CORE_PTSR8_DQSDQS1B4_Pos  0UL
#define LPDDR4_LPDDR4_CORE_PTSR8_DQSDQS1B4_Msk  0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR8_DQSDQS1B5_Pos  8UL
#define LPDDR4_LPDDR4_CORE_PTSR8_DQSDQS1B5_Msk  0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR8_DQSDQS1B6_Pos  16UL
#define LPDDR4_LPDDR4_CORE_PTSR8_DQSDQS1B6_Msk  0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR8_DQSDQS1B7_Pos  24UL
#define LPDDR4_LPDDR4_CORE_PTSR8_DQSDQS1B7_Msk  0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR9 */
#define LPDDR4_LPDDR4_CORE_PTSR9_DQSDQS2B0_Pos  0UL
#define LPDDR4_LPDDR4_CORE_PTSR9_DQSDQS2B0_Msk  0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR9_DQSDQS2B1_Pos  8UL
#define LPDDR4_LPDDR4_CORE_PTSR9_DQSDQS2B1_Msk  0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR9_DQSDQS2B2_Pos  16UL
#define LPDDR4_LPDDR4_CORE_PTSR9_DQSDQS2B2_Msk  0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR9_DQSDQS2B3_Pos  24UL
#define LPDDR4_LPDDR4_CORE_PTSR9_DQSDQS2B3_Msk  0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR10 */
#define LPDDR4_LPDDR4_CORE_PTSR10_DQSDQS2B4_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR10_DQSDQS2B4_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR10_DQSDQS2B5_Pos 8UL
#define LPDDR4_LPDDR4_CORE_PTSR10_DQSDQS2B5_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR10_DQSDQS2B6_Pos 16UL
#define LPDDR4_LPDDR4_CORE_PTSR10_DQSDQS2B6_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR10_DQSDQS2B7_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR10_DQSDQS2B7_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR11 */
#define LPDDR4_LPDDR4_CORE_PTSR11_DQSDQS3B0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR11_DQSDQS3B0_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR11_DQSDQS3B1_Pos 8UL
#define LPDDR4_LPDDR4_CORE_PTSR11_DQSDQS3B1_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR11_DQSDQS3B2_Pos 16UL
#define LPDDR4_LPDDR4_CORE_PTSR11_DQSDQS3B2_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR11_DQSDQS3B3_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR11_DQSDQS3B3_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR12 */
#define LPDDR4_LPDDR4_CORE_PTSR12_DQSDQS3B4_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR12_DQSDQS3B4_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR12_DQSDQS3B5_Pos 8UL
#define LPDDR4_LPDDR4_CORE_PTSR12_DQSDQS3B5_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR12_DQSDQS3B6_Pos 16UL
#define LPDDR4_LPDDR4_CORE_PTSR12_DQSDQS3B6_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR12_DQSDQS3B7_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR12_DQSDQS3B7_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR13 */
#define LPDDR4_LPDDR4_CORE_PTSR13_DQSDMS0_Pos   0UL
#define LPDDR4_LPDDR4_CORE_PTSR13_DQSDMS0_Msk   0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR13_DQSDMS1_Pos   8UL
#define LPDDR4_LPDDR4_CORE_PTSR13_DQSDMS1_Msk   0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR13_DQSDMS2_Pos   16UL
#define LPDDR4_LPDDR4_CORE_PTSR13_DQSDMS2_Msk   0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR13_DQSDMS3_Pos   24UL
#define LPDDR4_LPDDR4_CORE_PTSR13_DQSDMS3_Msk   0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR14 */
#define LPDDR4_LPDDR4_CORE_PTSR14_RDLVLDQS0B0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR14_RDLVLDQS0B0_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR14_RDLVLDQS0B1_Pos 8UL
#define LPDDR4_LPDDR4_CORE_PTSR14_RDLVLDQS0B1_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR14_RDLVLDQS0B2_Pos 16UL
#define LPDDR4_LPDDR4_CORE_PTSR14_RDLVLDQS0B2_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR14_RDLVLDQS0B3_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR14_RDLVLDQS0B3_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR15 */
#define LPDDR4_LPDDR4_CORE_PTSR15_RDLVLDQS0B4_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR15_RDLVLDQS0B4_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR15_RDLVLDQS0B5_Pos 8UL
#define LPDDR4_LPDDR4_CORE_PTSR15_RDLVLDQS0B5_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR15_RDLVLDQS0B6_Pos 16UL
#define LPDDR4_LPDDR4_CORE_PTSR15_RDLVLDQS0B6_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR15_RDLVLDQS0B7_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR15_RDLVLDQS0B7_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR16 */
#define LPDDR4_LPDDR4_CORE_PTSR16_RDLVLDQS1B0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR16_RDLVLDQS1B0_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR16_RDLVLDQS1B1_Pos 8UL
#define LPDDR4_LPDDR4_CORE_PTSR16_RDLVLDQS1B1_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR16_RDLVLDQS1B2_Pos 16UL
#define LPDDR4_LPDDR4_CORE_PTSR16_RDLVLDQS1B2_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR16_RDLVLDQS1B3_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR16_RDLVLDQS1B3_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR17 */
#define LPDDR4_LPDDR4_CORE_PTSR17_RDLVLDQS1B4_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR17_RDLVLDQS1B4_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR17_RDLVLDQS1B5_Pos 8UL
#define LPDDR4_LPDDR4_CORE_PTSR17_RDLVLDQS1B5_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR17_RDLVLDQS1B6_Pos 16UL
#define LPDDR4_LPDDR4_CORE_PTSR17_RDLVLDQS1B6_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR17_RDLVLDQS1B7_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR17_RDLVLDQS1B7_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR18 */
#define LPDDR4_LPDDR4_CORE_PTSR18_RDLVLDQS2B0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR18_RDLVLDQS2B0_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR18_RDLVLDQS2B1_Pos 8UL
#define LPDDR4_LPDDR4_CORE_PTSR18_RDLVLDQS2B1_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR18_RDLVLDQS2B2_Pos 16UL
#define LPDDR4_LPDDR4_CORE_PTSR18_RDLVLDQS2B2_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR18_RDLVLDQS2B3_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR18_RDLVLDQS2B3_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR19 */
#define LPDDR4_LPDDR4_CORE_PTSR19_RDLVLDQS2B4_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR19_RDLVLDQS2B4_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR19_RDLVLDQS2B5_Pos 8UL
#define LPDDR4_LPDDR4_CORE_PTSR19_RDLVLDQS2B5_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR19_RDLVLDQS2B6_Pos 16UL
#define LPDDR4_LPDDR4_CORE_PTSR19_RDLVLDQS2B6_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR19_RDLVLDQS2B7_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR19_RDLVLDQS2B7_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR20 */
#define LPDDR4_LPDDR4_CORE_PTSR20_RDLVLDQS3B0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR20_RDLVLDQS3B0_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR20_RDLVLDQS3B1_Pos 8UL
#define LPDDR4_LPDDR4_CORE_PTSR20_RDLVLDQS3B1_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR20_RDLVLDQS3B2_Pos 16UL
#define LPDDR4_LPDDR4_CORE_PTSR20_RDLVLDQS3B2_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR20_RDLVLDQS3B3_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR20_RDLVLDQS3B3_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR21 */
#define LPDDR4_LPDDR4_CORE_PTSR21_RDLVLDQS3B4_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR21_RDLVLDQS3B4_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR21_RDLVLDQS3B5_Pos 8UL
#define LPDDR4_LPDDR4_CORE_PTSR21_RDLVLDQS3B5_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR21_RDLVLDQS3B6_Pos 16UL
#define LPDDR4_LPDDR4_CORE_PTSR21_RDLVLDQS3B6_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR21_RDLVLDQS3B7_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR21_RDLVLDQS3B7_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR22 */
#define LPDDR4_LPDDR4_CORE_PTSR22_RDLVLDMS0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR22_RDLVLDMS0_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_PTSR22_RDLVLDMS1_Pos 8UL
#define LPDDR4_LPDDR4_CORE_PTSR22_RDLVLDMS1_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_PTSR22_RDLVLDMS2_Pos 16UL
#define LPDDR4_LPDDR4_CORE_PTSR22_RDLVLDMS2_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_PTSR22_RDLVLDMS3_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR22_RDLVLDMS3_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PTSR23 */
#define LPDDR4_LPDDR4_CORE_PTSR23_VREFDQRDS0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR23_VREFDQRDS0_Msk 0x3FUL
#define LPDDR4_LPDDR4_CORE_PTSR23_VREFDQRDS1_Pos 6UL
#define LPDDR4_LPDDR4_CORE_PTSR23_VREFDQRDS1_Msk 0xFC0UL
#define LPDDR4_LPDDR4_CORE_PTSR23_VREFDQRDS2_Pos 12UL
#define LPDDR4_LPDDR4_CORE_PTSR23_VREFDQRDS2_Msk 0x3F000UL
#define LPDDR4_LPDDR4_CORE_PTSR23_VREFDQRDS3_Pos 18UL
#define LPDDR4_LPDDR4_CORE_PTSR23_VREFDQRDS3_Msk 0xFC0000UL
#define LPDDR4_LPDDR4_CORE_PTSR23_VREFDQRDR_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR23_VREFDQRDR_Msk 0x1000000UL
/* LPDDR4_LPDDR4_CORE.PTSR24 */
#define LPDDR4_LPDDR4_CORE_PTSR24_CMDDLY_CKE0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR24_CMDDLY_CKE0_Msk 0x3FUL
#define LPDDR4_LPDDR4_CORE_PTSR24_CMDDLY_CKE1_Pos 6UL
#define LPDDR4_LPDDR4_CORE_PTSR24_CMDDLY_CKE1_Msk 0xFC0UL
#define LPDDR4_LPDDR4_CORE_PTSR24_PSCK_Pos      12UL
#define LPDDR4_LPDDR4_CORE_PTSR24_PSCK_Msk      0xF000UL
#define LPDDR4_LPDDR4_CORE_PTSR24_SANPAT_Pos    16UL
#define LPDDR4_LPDDR4_CORE_PTSR24_SANPAT_Msk    0xFFFF0000UL
/* LPDDR4_LPDDR4_CORE.PTSR25 */
#define LPDDR4_LPDDR4_CORE_PTSR25_CMDDLY_ODT0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_PTSR25_CMDDLY_ODT0_Msk 0x3FUL
#define LPDDR4_LPDDR4_CORE_PTSR25_CMDDLY_ODT1_Pos 6UL
#define LPDDR4_LPDDR4_CORE_PTSR25_CMDDLY_ODT1_Msk 0xFC0UL
#define LPDDR4_LPDDR4_CORE_PTSR25_CMDDLY_RSTN0_Pos 12UL
#define LPDDR4_LPDDR4_CORE_PTSR25_CMDDLY_RSTN0_Msk 0x3F000UL
#define LPDDR4_LPDDR4_CORE_PTSR25_CMDDLY_RSTN1_Pos 18UL
#define LPDDR4_LPDDR4_CORE_PTSR25_CMDDLY_RSTN1_Msk 0xFC0000UL
#define LPDDR4_LPDDR4_CORE_PTSR25_DQSLEADCK_Pos 24UL
#define LPDDR4_LPDDR4_CORE_PTSR25_DQSLEADCK_Msk 0xF000000UL
/* LPDDR4_LPDDR4_CORE.TREG0 */
#define LPDDR4_LPDDR4_CORE_TREG0_T_ALRTP_Pos    0UL
#define LPDDR4_LPDDR4_CORE_TREG0_T_ALRTP_Msk    0x3FUL
#define LPDDR4_LPDDR4_CORE_TREG0_T_CKESR_Pos    6UL
#define LPDDR4_LPDDR4_CORE_TREG0_T_CKESR_Msk    0x7C0UL
#define LPDDR4_LPDDR4_CORE_TREG0_T_CKEHDQS_Pos  11UL
#define LPDDR4_LPDDR4_CORE_TREG0_T_CKEHDQS_Msk  0xF800UL
#define LPDDR4_LPDDR4_CORE_TREG0_T_PD_Pos       16UL
#define LPDDR4_LPDDR4_CORE_TREG0_T_PD_Msk       0x1F0000UL
#define LPDDR4_LPDDR4_CORE_TREG0_T_DTRAIN_Pos   21UL
#define LPDDR4_LPDDR4_CORE_TREG0_T_DTRAIN_Msk   0xE00000UL
#define LPDDR4_LPDDR4_CORE_TREG0_T_DLLEN_Pos    24UL
#define LPDDR4_LPDDR4_CORE_TREG0_T_DLLEN_Msk    0xFF000000UL
/* LPDDR4_LPDDR4_CORE.TREG1 */
#define LPDDR4_LPDDR4_CORE_TREG1_T_RCD_Pos      0UL
#define LPDDR4_LPDDR4_CORE_TREG1_T_RCD_Msk      0x3FUL
#define LPDDR4_LPDDR4_CORE_TREG1_T_FAW_Pos      6UL
#define LPDDR4_LPDDR4_CORE_TREG1_T_FAW_Msk      0x1FC0UL
#define LPDDR4_LPDDR4_CORE_TREG1_T_RTW_Pos      13UL
#define LPDDR4_LPDDR4_CORE_TREG1_T_RTW_Msk      0x1FE000UL
#define LPDDR4_LPDDR4_CORE_TREG1_T_CCDWM_Pos    21UL
#define LPDDR4_LPDDR4_CORE_TREG1_T_CCDWM_Msk    0x7E00000UL
#define LPDDR4_LPDDR4_CORE_TREG1_T_MRS2LVLEN_Pos 27UL
#define LPDDR4_LPDDR4_CORE_TREG1_T_MRS2LVLEN_Msk 0xF8000000UL
/* LPDDR4_LPDDR4_CORE.TREG2 */
#define LPDDR4_LPDDR4_CORE_TREG2_T_RC_Pos       0UL
#define LPDDR4_LPDDR4_CORE_TREG2_T_RC_Msk       0xFFUL
#define LPDDR4_LPDDR4_CORE_TREG2_T_RAS_Pos      8UL
#define LPDDR4_LPDDR4_CORE_TREG2_T_RAS_Msk      0xFF00UL
#define LPDDR4_LPDDR4_CORE_TREG2_T_RDPDEN_Pos   16UL
#define LPDDR4_LPDDR4_CORE_TREG2_T_RDPDEN_Msk   0xFF0000UL
#define LPDDR4_LPDDR4_CORE_TREG2_T_DLLRST_Pos   24UL
#define LPDDR4_LPDDR4_CORE_TREG2_T_DLLRST_Msk   0xFF000000UL
/* LPDDR4_LPDDR4_CORE.TREG3 */
#define LPDDR4_LPDDR4_CORE_TREG3_T_RP_Pos       0UL
#define LPDDR4_LPDDR4_CORE_TREG3_T_RP_Msk       0x3FUL
#define LPDDR4_LPDDR4_CORE_TREG3_T_MRR_Pos      6UL
#define LPDDR4_LPDDR4_CORE_TREG3_T_MRR_Msk      0x3C0UL
#define LPDDR4_LPDDR4_CORE_TREG3_T_DQSCKE_Pos   10UL
#define LPDDR4_LPDDR4_CORE_TREG3_T_DQSCKE_Msk   0x7C00UL
#define LPDDR4_LPDDR4_CORE_TREG3_T_DQRPT_Pos    15UL
#define LPDDR4_LPDDR4_CORE_TREG3_T_DQRPT_Msk    0xF8000UL
#define LPDDR4_LPDDR4_CORE_TREG3_T_MRD_Pos      20UL
#define LPDDR4_LPDDR4_CORE_TREG3_T_MRD_Msk      0x1F00000UL
#define LPDDR4_LPDDR4_CORE_TREG3_T_ZQLAT_Pos    25UL
#define LPDDR4_LPDDR4_CORE_TREG3_T_ZQLAT_Msk    0xFE000000UL
/* LPDDR4_LPDDR4_CORE.TREG4 */
#define LPDDR4_LPDDR4_CORE_TREG4_T_WLBR_Pos     0UL
#define LPDDR4_LPDDR4_CORE_TREG4_T_WLBR_Msk     0xFFUL
#define LPDDR4_LPDDR4_CORE_TREG4_T_WRAPDEN_Pos  8UL
#define LPDDR4_LPDDR4_CORE_TREG4_T_WRAPDEN_Msk  0xFF00UL
#define LPDDR4_LPDDR4_CORE_TREG4_T_XP_Pos       16UL
#define LPDDR4_LPDDR4_CORE_TREG4_T_XP_Msk       0x1F0000UL
#define LPDDR4_LPDDR4_CORE_TREG4_T_ZQCAL_Pos    21UL
#define LPDDR4_LPDDR4_CORE_TREG4_T_ZQCAL_Msk    0xFFE00000UL
/* LPDDR4_LPDDR4_CORE.TREG5 */
#define LPDDR4_LPDDR4_CORE_TREG5_T_ZQRS_Pos     0UL
#define LPDDR4_LPDDR4_CORE_TREG5_T_ZQRS_Msk     0xFFUL
#define LPDDR4_LPDDR4_CORE_TREG5_T_CKCKEH_Pos   8UL
#define LPDDR4_LPDDR4_CORE_TREG5_T_CKCKEH_Msk   0x300UL
#define LPDDR4_LPDDR4_CORE_TREG5_T_REFI_Pos     10UL
#define LPDDR4_LPDDR4_CORE_TREG5_T_REFI_Msk     0xFFFC00UL
#define LPDDR4_LPDDR4_CORE_TREG5_T_OSCO_Pos     24UL
#define LPDDR4_LPDDR4_CORE_TREG5_T_OSCO_Msk     0xFF000000UL
/* LPDDR4_LPDDR4_CORE.TREG6 */
#define LPDDR4_LPDDR4_CORE_TREG6_T_READ_LOW_Pos 0UL
#define LPDDR4_LPDDR4_CORE_TREG6_T_READ_LOW_Msk 0x3FFUL
#define LPDDR4_LPDDR4_CORE_TREG6_T_READ_HIGH_Pos 10UL
#define LPDDR4_LPDDR4_CORE_TREG6_T_READ_HIGH_Msk 0xFFC00UL
#define LPDDR4_LPDDR4_CORE_TREG6_T_CCD_Pos      20UL
#define LPDDR4_LPDDR4_CORE_TREG6_T_CCD_Msk      0x1F00000UL
#define LPDDR4_LPDDR4_CORE_TREG6_T_WLBTR_Pos    25UL
#define LPDDR4_LPDDR4_CORE_TREG6_T_WLBTR_Msk    0xFE000000UL
/* LPDDR4_LPDDR4_CORE.TREG7 */
#define LPDDR4_LPDDR4_CORE_TREG7_T_INIT1_Pos    0UL
#define LPDDR4_LPDDR4_CORE_TREG7_T_INIT1_Msk    0x3FFFUL
#define LPDDR4_LPDDR4_CORE_TREG7_T_MPCWR_Pos    14UL
#define LPDDR4_LPDDR4_CORE_TREG7_T_MPCWR_Msk    0xFC000UL
#define LPDDR4_LPDDR4_CORE_TREG7_T_CKFSPE_Pos   20UL
#define LPDDR4_LPDDR4_CORE_TREG7_T_CKFSPE_Msk   0xF00000UL
#define LPDDR4_LPDDR4_CORE_TREG7_T_CKFSPX_Pos   24UL
#define LPDDR4_LPDDR4_CORE_TREG7_T_CKFSPX_Msk   0xF000000UL
#define LPDDR4_LPDDR4_CORE_TREG7_T_CKELCK_Pos   28UL
#define LPDDR4_LPDDR4_CORE_TREG7_T_CKELCK_Msk   0xF0000000UL
/* LPDDR4_LPDDR4_CORE.TREG8 */
#define LPDDR4_LPDDR4_CORE_TREG8_T_WRITE_LOW_Pos 0UL
#define LPDDR4_LPDDR4_CORE_TREG8_T_WRITE_LOW_Msk 0x3FFUL
#define LPDDR4_LPDDR4_CORE_TREG8_T_WRITE_HIGH_Pos 10UL
#define LPDDR4_LPDDR4_CORE_TREG8_T_WRITE_HIGH_Msk 0xFFC00UL
#define LPDDR4_LPDDR4_CORE_TREG8_T_MRW_Pos      20UL
#define LPDDR4_LPDDR4_CORE_TREG8_T_MRW_Msk      0x1F00000UL
#define LPDDR4_LPDDR4_CORE_TREG8_T_MPCWR2RD_Pos 25UL
#define LPDDR4_LPDDR4_CORE_TREG8_T_MPCWR2RD_Msk 0xFE000000UL
/* LPDDR4_LPDDR4_CORE.TREG9 */
#define LPDDR4_LPDDR4_CORE_TREG9_T_ZQ_ITV_Pos   0UL
#define LPDDR4_LPDDR4_CORE_TREG9_T_ZQ_ITV_Msk   0xFFFFFFFUL
#define LPDDR4_LPDDR4_CORE_TREG9_T_CMDCKE_Pos   28UL
#define LPDDR4_LPDDR4_CORE_TREG9_T_CMDCKE_Msk   0xF0000000UL
/* LPDDR4_LPDDR4_CORE.TREG10 */
#define LPDDR4_LPDDR4_CORE_TREG10_T_RFC_Pos     0UL
#define LPDDR4_LPDDR4_CORE_TREG10_T_RFC_Msk     0x3FFUL
#define LPDDR4_LPDDR4_CORE_TREG10_T_MRS2ACT_Pos 10UL
#define LPDDR4_LPDDR4_CORE_TREG10_T_MRS2ACT_Msk 0xFC00UL
#define LPDDR4_LPDDR4_CORE_TREG10_T_LVLLOAD_Pos 16UL
#define LPDDR4_LPDDR4_CORE_TREG10_T_LVLLOAD_Msk 0xF0000UL
#define LPDDR4_LPDDR4_CORE_TREG10_T_LVLDLL_Pos  20UL
#define LPDDR4_LPDDR4_CORE_TREG10_T_LVLDLL_Msk  0xF00000UL
#define LPDDR4_LPDDR4_CORE_TREG10_T_LVLRESP_Pos 24UL
#define LPDDR4_LPDDR4_CORE_TREG10_T_LVLRESP_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.TREG11 */
#define LPDDR4_LPDDR4_CORE_TREG11_T_DLLLOCK_Pos 0UL
#define LPDDR4_LPDDR4_CORE_TREG11_T_DLLLOCK_Msk 0xFFFFUL
#define LPDDR4_LPDDR4_CORE_TREG11_T_INIT5_Pos   16UL
#define LPDDR4_LPDDR4_CORE_TREG11_T_INIT5_Msk   0x7F0000UL
#define LPDDR4_LPDDR4_CORE_TREG11_T_CAENT_Pos   23UL
#define LPDDR4_LPDDR4_CORE_TREG11_T_CAENT_Msk   0xFF800000UL
/* LPDDR4_LPDDR4_CORE.TREG12 */
#define LPDDR4_LPDDR4_CORE_TREG12_T_RRD_Pos     0UL
#define LPDDR4_LPDDR4_CORE_TREG12_T_RRD_Msk     0x1FUL
#define LPDDR4_LPDDR4_CORE_TREG12_T_INIT3_Pos   5UL
#define LPDDR4_LPDDR4_CORE_TREG12_T_INIT3_Msk   0x3FFFE0UL
#define LPDDR4_LPDDR4_CORE_TREG12_T_XSR_Pos     22UL
#define LPDDR4_LPDDR4_CORE_TREG12_T_XSR_Msk     0xFFC00000UL
/* LPDDR4_LPDDR4_CORE.TREG13 */
#define LPDDR4_LPDDR4_CORE_TREG13_T_LVLDIS_Pos  0UL
#define LPDDR4_LPDDR4_CORE_TREG13_T_LVLDIS_Msk  0x1FUL
#define LPDDR4_LPDDR4_CORE_TREG13_T_LVLEXIT_Pos 5UL
#define LPDDR4_LPDDR4_CORE_TREG13_T_LVLEXIT_Msk 0x3E0UL
#define LPDDR4_LPDDR4_CORE_TREG13_T_LVLAA_Pos   10UL
#define LPDDR4_LPDDR4_CORE_TREG13_T_LVLAA_Msk   0x3C00UL
#define LPDDR4_LPDDR4_CORE_TREG13_T_FC_Pos      14UL
#define LPDDR4_LPDDR4_CORE_TREG13_T_FC_Msk      0x7FC000UL
/* LPDDR4_LPDDR4_CORE.TREG14 */
#define LPDDR4_LPDDR4_CORE_TREG14_T_ODTUP_Pos   0UL
#define LPDDR4_LPDDR4_CORE_TREG14_T_ODTUP_Msk   0xFFUL
#define LPDDR4_LPDDR4_CORE_TREG14_T_VREFTIMESHORT_Pos 8UL
#define LPDDR4_LPDDR4_CORE_TREG14_T_VREFTIMESHORT_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_TREG14_T_VREFTIMELONG_Pos 16UL
#define LPDDR4_LPDDR4_CORE_TREG14_T_VREFTIMELONG_Msk 0x1FF0000UL
/* LPDDR4_LPDDR4_CORE.TREG15 */
#define LPDDR4_LPDDR4_CORE_TREG15_T_VRCGEN_Pos  0UL
#define LPDDR4_LPDDR4_CORE_TREG15_T_VRCGEN_Msk  0x1FFUL
#define LPDDR4_LPDDR4_CORE_TREG15_T_VRCGDIS_Pos 9UL
#define LPDDR4_LPDDR4_CORE_TREG15_T_VRCGDIS_Msk 0x1FE00UL
/* LPDDR4_LPDDR4_CORE.BISTCFG_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_START_BANK_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_START_BANK_Msk 0x7UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_END_BANK_Pos 3UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_END_BANK_Msk 0x38UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_START_BACKGROUND_Pos 6UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_START_BACKGROUND_Msk 0x1C0UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_END_BACKGROUND_Pos 9UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_END_BACKGROUND_Msk 0xE00UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_ELEMENT_Pos 12UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_ELEMENT_Msk 0xF000UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_OPERATION_Pos 16UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_OPERATION_Msk 0xF0000UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_RETENTION_Pos 20UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_RETENTION_Msk 0xF00000UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_DIAGNOSIS_EN_Pos 24UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH0_DIAGNOSIS_EN_Msk 0x1000000UL
/* LPDDR4_LPDDR4_CORE.BISTCFG_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_START_BANK_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_START_BANK_Msk 0x7UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_END_BANK_Pos 3UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_END_BANK_Msk 0x38UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_START_BACKGROUND_Pos 6UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_START_BACKGROUND_Msk 0x1C0UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_END_BACKGROUND_Pos 9UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_END_BACKGROUND_Msk 0xE00UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_ELEMENT_Pos 12UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_ELEMENT_Msk 0xF000UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_OPERATION_Pos 16UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_OPERATION_Msk 0xF0000UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_RETENTION_Pos 20UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_RETENTION_Msk 0xF00000UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_DIAGNOSIS_EN_Pos 24UL
#define LPDDR4_LPDDR4_CORE_BISTCFG_CH1_DIAGNOSIS_EN_Msk 0x1000000UL
/* LPDDR4_LPDDR4_CORE.BISTSTADDR_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTSTADDR_CH0_START_ROW_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTSTADDR_CH0_START_ROW_Msk 0x7FFFUL
#define LPDDR4_LPDDR4_CORE_BISTSTADDR_CH0_START_COL_Pos 15UL
#define LPDDR4_LPDDR4_CORE_BISTSTADDR_CH0_START_COL_Msk 0x1FF8000UL
/* LPDDR4_LPDDR4_CORE.BISTSTADDR_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTSTADDR_CH1_START_ROW_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTSTADDR_CH1_START_ROW_Msk 0x7FFFUL
#define LPDDR4_LPDDR4_CORE_BISTSTADDR_CH1_START_COL_Pos 15UL
#define LPDDR4_LPDDR4_CORE_BISTSTADDR_CH1_START_COL_Msk 0x1FF8000UL
/* LPDDR4_LPDDR4_CORE.BISTEDADDR_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTEDADDR_CH0_END_ROW_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTEDADDR_CH0_END_ROW_Msk 0x7FFFUL
#define LPDDR4_LPDDR4_CORE_BISTEDADDR_CH0_END_COL_Pos 15UL
#define LPDDR4_LPDDR4_CORE_BISTEDADDR_CH0_END_COL_Msk 0x1FF8000UL
/* LPDDR4_LPDDR4_CORE.BISTEDADDR_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTEDADDR_CH1_END_ROW_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTEDADDR_CH1_END_ROW_Msk 0x7FFFUL
#define LPDDR4_LPDDR4_CORE_BISTEDADDR_CH1_END_COL_Pos 15UL
#define LPDDR4_LPDDR4_CORE_BISTEDADDR_CH1_END_COL_Msk 0x1FF8000UL
/* LPDDR4_LPDDR4_CORE.BISTM0_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM0_CH0_MARCH_ELEMENT_0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM0_CH0_MARCH_ELEMENT_0_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM0_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM0_CH1_MARCH_ELEMENT_0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM0_CH1_MARCH_ELEMENT_0_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM1_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM1_CH0_MARCH_ELEMENT_1_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM1_CH0_MARCH_ELEMENT_1_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM1_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM1_CH1_MARCH_ELEMENT_1_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM1_CH1_MARCH_ELEMENT_1_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM2_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM2_CH0_MARCH_ELEMENT_2_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM2_CH0_MARCH_ELEMENT_2_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM2_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM2_CH1_MARCH_ELEMENT_2_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM2_CH1_MARCH_ELEMENT_2_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM3_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM3_CH0_MARCH_ELEMENT_3_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM3_CH0_MARCH_ELEMENT_3_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM3_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM3_CH1_MARCH_ELEMENT_3_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM3_CH1_MARCH_ELEMENT_3_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM4_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM4_CH0_MARCH_ELEMENT_4_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM4_CH0_MARCH_ELEMENT_4_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM4_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM4_CH1_MARCH_ELEMENT_4_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM4_CH1_MARCH_ELEMENT_4_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM5_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM5_CH0_MARCH_ELEMENT_5_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM5_CH0_MARCH_ELEMENT_5_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM5_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM5_CH1_MARCH_ELEMENT_5_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM5_CH1_MARCH_ELEMENT_5_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM6_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM6_CH0_MARCH_ELEMENT_6_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM6_CH0_MARCH_ELEMENT_6_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM6_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM6_CH1_MARCH_ELEMENT_6_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM6_CH1_MARCH_ELEMENT_6_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM7_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM7_CH0_MARCH_ELEMENT_7_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM7_CH0_MARCH_ELEMENT_7_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM7_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM7_CH1_MARCH_ELEMENT_7_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM7_CH1_MARCH_ELEMENT_7_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM8_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM8_CH0_MARCH_ELEMENT_8_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM8_CH0_MARCH_ELEMENT_8_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM8_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM8_CH1_MARCH_ELEMENT_8_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM8_CH1_MARCH_ELEMENT_8_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM9_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM9_CH0_MARCH_ELEMENT_9_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM9_CH0_MARCH_ELEMENT_9_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM9_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM9_CH1_MARCH_ELEMENT_9_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM9_CH1_MARCH_ELEMENT_9_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM10_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM10_CH0_MARCH_ELEMENT_10_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM10_CH0_MARCH_ELEMENT_10_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM10_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM10_CH1_MARCH_ELEMENT_10_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM10_CH1_MARCH_ELEMENT_10_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM11_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM11_CH0_MARCH_ELEMENT_11_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM11_CH0_MARCH_ELEMENT_11_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM11_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM11_CH1_MARCH_ELEMENT_11_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM11_CH1_MARCH_ELEMENT_11_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM12_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM12_CH0_MARCH_ELEMENT_12_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM12_CH0_MARCH_ELEMENT_12_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM12_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM12_CH1_MARCH_ELEMENT_12_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM12_CH1_MARCH_ELEMENT_12_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM13_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM13_CH0_MARCH_ELEMENT_13_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM13_CH0_MARCH_ELEMENT_13_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM13_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM13_CH1_MARCH_ELEMENT_13_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM13_CH1_MARCH_ELEMENT_13_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM14_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM14_CH0_MARCH_ELEMENT_14_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM14_CH0_MARCH_ELEMENT_14_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM14_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM14_CH1_MARCH_ELEMENT_14_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM14_CH1_MARCH_ELEMENT_14_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM15_CH0 */
#define LPDDR4_LPDDR4_CORE_BISTM15_CH0_MARCH_ELEMENT_15_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM15_CH0_MARCH_ELEMENT_15_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.BISTM15_CH1 */
#define LPDDR4_LPDDR4_CORE_BISTM15_CH1_MARCH_ELEMENT_15_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTM15_CH1_MARCH_ELEMENT_15_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.ADFT */
#define LPDDR4_LPDDR4_CORE_ADFT_TST_EN_CA_Pos   0UL
#define LPDDR4_LPDDR4_CORE_ADFT_TST_EN_CA_Msk   0x3UL
#define LPDDR4_LPDDR4_CORE_ADFT_TST_EN_DQ_Pos   2UL
#define LPDDR4_LPDDR4_CORE_ADFT_TST_EN_DQ_Msk   0x3CUL
/* LPDDR4_LPDDR4_CORE.OUTBYPEN0 */
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_CA_Pos     0UL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_CA_Msk     0xFFFUL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_CKE_Pos    12UL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_CKE_Msk    0x3000UL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_CS_Pos     14UL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_CS_Msk     0xC000UL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_ODT_Pos    16UL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_ODT_Msk    0x30000UL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_RESET_N_Pos 18UL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_RESET_N_Msk 0xC0000UL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_DM_Pos     20UL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_DM_Msk     0xF00000UL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_DQS_Pos    24UL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN0_DQS_Msk    0xF000000UL
/* LPDDR4_LPDDR4_CORE.OUTBYPEN1 */
#define LPDDR4_LPDDR4_CORE_OUTBYPEN1_DQ_Pos     0UL
#define LPDDR4_LPDDR4_CORE_OUTBYPEN1_DQ_Msk     0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.OUTD0 */
#define LPDDR4_LPDDR4_CORE_OUTD0_CA_Pos         0UL
#define LPDDR4_LPDDR4_CORE_OUTD0_CA_Msk         0xFFFUL
#define LPDDR4_LPDDR4_CORE_OUTD0_CKE_Pos        12UL
#define LPDDR4_LPDDR4_CORE_OUTD0_CKE_Msk        0x3000UL
#define LPDDR4_LPDDR4_CORE_OUTD0_CS_Pos         14UL
#define LPDDR4_LPDDR4_CORE_OUTD0_CS_Msk         0xC000UL
#define LPDDR4_LPDDR4_CORE_OUTD0_ODT_Pos        16UL
#define LPDDR4_LPDDR4_CORE_OUTD0_ODT_Msk        0x30000UL
#define LPDDR4_LPDDR4_CORE_OUTD0_RESET_N_Pos    18UL
#define LPDDR4_LPDDR4_CORE_OUTD0_RESET_N_Msk    0xC0000UL
#define LPDDR4_LPDDR4_CORE_OUTD0_DM_Pos         20UL
#define LPDDR4_LPDDR4_CORE_OUTD0_DM_Msk         0xF00000UL
#define LPDDR4_LPDDR4_CORE_OUTD0_DQS_Pos        24UL
#define LPDDR4_LPDDR4_CORE_OUTD0_DQS_Msk        0xF000000UL
/* LPDDR4_LPDDR4_CORE.OUTD1 */
#define LPDDR4_LPDDR4_CORE_OUTD1_DQ_Pos         0UL
#define LPDDR4_LPDDR4_CORE_OUTD1_DQ_Msk         0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.INECC0 */
#define LPDDR4_LPDDR4_CORE_INECC0_ECC_BASE_Pos  0UL
#define LPDDR4_LPDDR4_CORE_INECC0_ECC_BASE_Msk  0x3FFFFFFFUL
/* LPDDR4_LPDDR4_CORE.INECC1 */
#define LPDDR4_LPDDR4_CORE_INECC1_PROT_MEM_BASE_Pos 0UL
#define LPDDR4_LPDDR4_CORE_INECC1_PROT_MEM_BASE_Msk 0x3FFFFFFFUL
/* LPDDR4_LPDDR4_CORE.INECC2 */
#define LPDDR4_LPDDR4_CORE_INECC2_PROT_MEM_SIZE_Pos 0UL
#define LPDDR4_LPDDR4_CORE_INECC2_PROT_MEM_SIZE_Msk 0x3FFFFFFFUL
/* LPDDR4_LPDDR4_CORE.DVSTT0 */
#define LPDDR4_LPDDR4_CORE_DVSTT0_DEVICE_ID_Pos 0UL
#define LPDDR4_LPDDR4_CORE_DVSTT0_DEVICE_ID_Msk 0xFFFFUL
/* LPDDR4_LPDDR4_CORE.DVSTT1 */
#define LPDDR4_LPDDR4_CORE_DVSTT1_DVSTT1_DRAM_BL_ENC_Pos 0UL
#define LPDDR4_LPDDR4_CORE_DVSTT1_DVSTT1_DRAM_BL_ENC_Msk 0x3UL
#define LPDDR4_LPDDR4_CORE_DVSTT1_DVSTT1_DFI_FREQ_RATIO_Pos 2UL
#define LPDDR4_LPDDR4_CORE_DVSTT1_DVSTT1_DFI_FREQ_RATIO_Msk 0xCUL
/* LPDDR4_LPDDR4_CORE.OPSTT_CH0 */
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_DRAM_PAUSE_Pos 0UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_DRAM_PAUSE_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_USER_CMD_READY_Pos 1UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_USER_CMD_READY_Msk 0x2UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_BANK_IDLE_Pos 2UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_BANK_IDLE_Msk 0x3FCUL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_XQR_EMPTY_Pos 10UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_XQR_EMPTY_Msk 0x400UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_XQR_FULL_Pos 11UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_XQR_FULL_Msk 0x800UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_XQW_EMPTY_Pos 12UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_XQW_EMPTY_Msk 0x1000UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_XQW_FULL_Pos 13UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH0_XQW_FULL_Msk 0x2000UL
/* LPDDR4_LPDDR4_CORE.OPSTT_CH1 */
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_DRAM_PAUSE_Pos 0UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_DRAM_PAUSE_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_USER_CMD_READY_Pos 1UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_USER_CMD_READY_Msk 0x2UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_BANK_IDLE_Pos 2UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_BANK_IDLE_Msk 0x3FCUL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_XQR_EMPTY_Pos 10UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_XQR_EMPTY_Msk 0x400UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_XQR_FULL_Pos 11UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_XQR_FULL_Msk 0x800UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_XQW_EMPTY_Pos 12UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_XQW_EMPTY_Msk 0x1000UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_XQW_FULL_Pos 13UL
#define LPDDR4_LPDDR4_CORE_OPSTT_CH1_XQW_FULL_Msk 0x2000UL
/* LPDDR4_LPDDR4_CORE.INTSTT_CH0 */
#define LPDDR4_LPDDR4_CORE_INTSTT_CH0_INT_GC_FSM_Pos 0UL
#define LPDDR4_LPDDR4_CORE_INTSTT_CH0_INT_GC_FSM_Msk 0x1UL
/* LPDDR4_LPDDR4_CORE.INTSTT_CH1 */
#define LPDDR4_LPDDR4_CORE_INTSTT_CH1_INT_GC_FSM_Pos 0UL
#define LPDDR4_LPDDR4_CORE_INTSTT_CH1_INT_GC_FSM_Msk 0x1UL
/* LPDDR4_LPDDR4_CORE.BISTSTT0 */
#define LPDDR4_LPDDR4_CORE_BISTSTT0_BISTERR_CA_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTSTT0_BISTERR_CA_Msk 0xFFFUL
#define LPDDR4_LPDDR4_CORE_BISTSTT0_BISTERR_DM_Pos 12UL
#define LPDDR4_LPDDR4_CORE_BISTSTT0_BISTERR_DM_Msk 0xF000UL
#define LPDDR4_LPDDR4_CORE_BISTSTT0_BISTERR_CKE_Pos 16UL
#define LPDDR4_LPDDR4_CORE_BISTSTT0_BISTERR_CKE_Msk 0x30000UL
#define LPDDR4_LPDDR4_CORE_BISTSTT0_BISTERR_CS_N_Pos 18UL
#define LPDDR4_LPDDR4_CORE_BISTSTT0_BISTERR_CS_N_Msk 0xC0000UL
#define LPDDR4_LPDDR4_CORE_BISTSTT0_BISTERR_RESET_N_Pos 20UL
#define LPDDR4_LPDDR4_CORE_BISTSTT0_BISTERR_RESET_N_Msk 0x300000UL
#define LPDDR4_LPDDR4_CORE_BISTSTT0_BISTERR_ODT_Pos 22UL
#define LPDDR4_LPDDR4_CORE_BISTSTT0_BISTERR_ODT_Msk 0xC00000UL
/* LPDDR4_LPDDR4_CORE.BISTSTT1 */
#define LPDDR4_LPDDR4_CORE_BISTSTT1_BISTERR_DQ_Pos 0UL
#define LPDDR4_LPDDR4_CORE_BISTSTT1_BISTERR_DQ_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.DDRBISTSTT_CH0 */
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_ERROR_Pos 0UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_ERROR_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_ENDTEST_Pos 1UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_ENDTEST_Msk 0x2UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_ERROR_NEW_Pos 2UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_ERROR_NEW_Msk 0x4UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_BANK_FAIL_Pos 3UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_BANK_FAIL_Msk 0x38UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_ROW_FAIL_Pos 6UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH0_ROW_FAIL_Msk 0x1FFFC0UL
/* LPDDR4_LPDDR4_CORE.DDRBISTSTT_CH1 */
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_ERROR_Pos 0UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_ERROR_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_ENDTEST_Pos 1UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_ENDTEST_Msk 0x2UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_ERROR_NEW_Pos 2UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_ERROR_NEW_Msk 0x4UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_BANK_FAIL_Pos 3UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_BANK_FAIL_Msk 0x38UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_ROW_FAIL_Pos 6UL
#define LPDDR4_LPDDR4_CORE_DDRBISTSTT_CH1_ROW_FAIL_Msk 0x1FFFC0UL
/* LPDDR4_LPDDR4_CORE.POS */
#define LPDDR4_LPDDR4_CORE_POS_PHYSETC_Pos      0UL
#define LPDDR4_LPDDR4_CORE_POS_PHYSETC_Msk      0x1UL
#define LPDDR4_LPDDR4_CORE_POS_PHYFSC_Pos       1UL
#define LPDDR4_LPDDR4_CORE_POS_PHYFSC_Msk       0x2UL
#define LPDDR4_LPDDR4_CORE_POS_PHYINITC_Pos     2UL
#define LPDDR4_LPDDR4_CORE_POS_PHYINITC_Msk     0x4UL
#define LPDDR4_LPDDR4_CORE_POS_DLLRSTC_Pos      3UL
#define LPDDR4_LPDDR4_CORE_POS_DLLRSTC_Msk      0x8UL
#define LPDDR4_LPDDR4_CORE_POS_DRAMINITC_Pos    4UL
#define LPDDR4_LPDDR4_CORE_POS_DRAMINITC_Msk    0x10UL
#define LPDDR4_LPDDR4_CORE_POS_VREFDQRDC_Pos    5UL
#define LPDDR4_LPDDR4_CORE_POS_VREFDQRDC_Msk    0x20UL
#define LPDDR4_LPDDR4_CORE_POS_VREFCAC_Pos      6UL
#define LPDDR4_LPDDR4_CORE_POS_VREFCAC_Msk      0x40UL
#define LPDDR4_LPDDR4_CORE_POS_GTC_Pos          7UL
#define LPDDR4_LPDDR4_CORE_POS_GTC_Msk          0x80UL
#define LPDDR4_LPDDR4_CORE_POS_WRLVLC_Pos       8UL
#define LPDDR4_LPDDR4_CORE_POS_WRLVLC_Msk       0x100UL
#define LPDDR4_LPDDR4_CORE_POS_RDLVLC_Pos       9UL
#define LPDDR4_LPDDR4_CORE_POS_RDLVLC_Msk       0x200UL
#define LPDDR4_LPDDR4_CORE_POS_VREFDQWRC_Pos    10UL
#define LPDDR4_LPDDR4_CORE_POS_VREFDQWRC_Msk    0x400UL
#define LPDDR4_LPDDR4_CORE_POS_DLYEVALC_Pos     11UL
#define LPDDR4_LPDDR4_CORE_POS_DLYEVALC_Msk     0x800UL
#define LPDDR4_LPDDR4_CORE_POS_SANCHKC_Pos      12UL
#define LPDDR4_LPDDR4_CORE_POS_SANCHKC_Msk      0x1000UL
#define LPDDR4_LPDDR4_CORE_POS_OFS_Pos          13UL
#define LPDDR4_LPDDR4_CORE_POS_OFS_Msk          0x2000UL
#define LPDDR4_LPDDR4_CORE_POS_FS0REQ_Pos       14UL
#define LPDDR4_LPDDR4_CORE_POS_FS0REQ_Msk       0x4000UL
#define LPDDR4_LPDDR4_CORE_POS_FS1REQ_Pos       15UL
#define LPDDR4_LPDDR4_CORE_POS_FS1REQ_Msk       0x8000UL
#define LPDDR4_LPDDR4_CORE_POS_CLKLOCKC_Pos     16UL
#define LPDDR4_LPDDR4_CORE_POS_CLKLOCKC_Msk     0x10000UL
#define LPDDR4_LPDDR4_CORE_POS_CMDDLYC_Pos      17UL
#define LPDDR4_LPDDR4_CORE_POS_CMDDLYC_Msk      0x20000UL
#define LPDDR4_LPDDR4_CORE_POS_DQSDQC_Pos       18UL
#define LPDDR4_LPDDR4_CORE_POS_DQSDQC_Msk       0x40000UL
/* LPDDR4_LPDDR4_CORE.PTS0 */
#define LPDDR4_LPDDR4_CORE_PTS0_DLLERR_Pos      0UL
#define LPDDR4_LPDDR4_CORE_PTS0_DLLERR_Msk      0x3FUL
#define LPDDR4_LPDDR4_CORE_PTS0_VREFDQRDERR_Pos 6UL
#define LPDDR4_LPDDR4_CORE_PTS0_VREFDQRDERR_Msk 0x3C0UL
#define LPDDR4_LPDDR4_CORE_PTS0_VREFCAERR_Pos   10UL
#define LPDDR4_LPDDR4_CORE_PTS0_VREFCAERR_Msk   0xC00UL
#define LPDDR4_LPDDR4_CORE_PTS0_GTERR_Pos       12UL
#define LPDDR4_LPDDR4_CORE_PTS0_GTERR_Msk       0xF000UL
#define LPDDR4_LPDDR4_CORE_PTS0_WRLVLERR_Pos    16UL
#define LPDDR4_LPDDR4_CORE_PTS0_WRLVLERR_Msk    0xF0000UL
#define LPDDR4_LPDDR4_CORE_PTS0_VREFDQWRERR_Pos 20UL
#define LPDDR4_LPDDR4_CORE_PTS0_VREFDQWRERR_Msk 0xF00000UL
#define LPDDR4_LPDDR4_CORE_PTS0_RDLVLDMERR_Pos  24UL
#define LPDDR4_LPDDR4_CORE_PTS0_RDLVLDMERR_Msk  0xF000000UL
#define LPDDR4_LPDDR4_CORE_PTS0_SANCHKERR_Pos   28UL
#define LPDDR4_LPDDR4_CORE_PTS0_SANCHKERR_Msk   0xF0000000UL
/* LPDDR4_LPDDR4_CORE.PTS1 */
#define LPDDR4_LPDDR4_CORE_PTS1_RDLVLDQERR_Pos  0UL
#define LPDDR4_LPDDR4_CORE_PTS1_RDLVLDQERR_Msk  0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.PTS2 */
#define LPDDR4_LPDDR4_CORE_PTS2_DQSDQERR_Pos    0UL
#define LPDDR4_LPDDR4_CORE_PTS2_DQSDQERR_Msk    0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.PTS3 */
#define LPDDR4_LPDDR4_CORE_PTS3_DQSDMERR_Pos    0UL
#define LPDDR4_LPDDR4_CORE_PTS3_DQSDMERR_Msk    0xFUL
/* LPDDR4_LPDDR4_CORE.DLLSTTCA */
#define LPDDR4_LPDDR4_CORE_DLLSTTCA_DLLSTTCA_LOCK_Pos 0UL
#define LPDDR4_LPDDR4_CORE_DLLSTTCA_DLLSTTCA_LOCK_Msk 0x3UL
#define LPDDR4_LPDDR4_CORE_DLLSTTCA_DLLSTTCA_OVFL_Pos 2UL
#define LPDDR4_LPDDR4_CORE_DLLSTTCA_DLLSTTCA_OVFL_Msk 0xCUL
#define LPDDR4_LPDDR4_CORE_DLLSTTCA_DLLSTTCA_UNFL_Pos 4UL
#define LPDDR4_LPDDR4_CORE_DLLSTTCA_DLLSTTCA_UNFL_Msk 0x30UL
#define LPDDR4_LPDDR4_CORE_DLLSTTCA_DLYC_CA0_Pos 6UL
#define LPDDR4_LPDDR4_CORE_DLLSTTCA_DLYC_CA0_Msk 0x3FC0UL
#define LPDDR4_LPDDR4_CORE_DLLSTTCA_DLYC_CA1_Pos 14UL
#define LPDDR4_LPDDR4_CORE_DLLSTTCA_DLYC_CA1_Msk 0x3FC000UL
/* LPDDR4_LPDDR4_CORE.DLLSTTDQ0 */
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ0_LOCK_Pos   0UL
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ0_LOCK_Msk   0xFUL
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ0_OVFL_Pos   4UL
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ0_OVFL_Msk   0xF0UL
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ0_UNFL_Pos   8UL
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ0_UNFL_Msk   0xF00UL
/* LPDDR4_LPDDR4_CORE.DLLSTTDQ1 */
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ1_DLYC_SL0_Pos 0UL
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ1_DLYC_SL0_Msk 0xFFUL
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ1_DLYC_SL1_Pos 8UL
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ1_DLYC_SL1_Msk 0xFF00UL
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ1_DLYC_SL2_Pos 16UL
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ1_DLYC_SL2_Msk 0xFF0000UL
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ1_DLYC_SL3_Pos 24UL
#define LPDDR4_LPDDR4_CORE_DLLSTTDQ1_DLYC_SL3_Msk 0xFF000000UL
/* LPDDR4_LPDDR4_CORE.PBSR */
#define LPDDR4_LPDDR4_CORE_PBSR_BIST_DONE_Pos   0UL
#define LPDDR4_LPDDR4_CORE_PBSR_BIST_DONE_Msk   0x1UL
#define LPDDR4_LPDDR4_CORE_PBSR_BIST_ERR_Pos    1UL
#define LPDDR4_LPDDR4_CORE_PBSR_BIST_ERR_Msk    0x2UL
/* LPDDR4_LPDDR4_CORE.PCSR_CH0 */
#define LPDDR4_LPDDR4_CORE_PCSR_CH0_SRSTC_Pos   0UL
#define LPDDR4_LPDDR4_CORE_PCSR_CH0_SRSTC_Msk   0x1UL
#define LPDDR4_LPDDR4_CORE_PCSR_CH0_UPDC_Pos    1UL
#define LPDDR4_LPDDR4_CORE_PCSR_CH0_UPDC_Msk    0x2UL
#define LPDDR4_LPDDR4_CORE_PCSR_CH0_NBC_Pos     2UL
#define LPDDR4_LPDDR4_CORE_PCSR_CH0_NBC_Msk     0x3CUL
#define LPDDR4_LPDDR4_CORE_PCSR_CH0_PBC_Pos     6UL
#define LPDDR4_LPDDR4_CORE_PCSR_CH0_PBC_Msk     0x3C0UL
/* LPDDR4_LPDDR4_CORE.PCSR_CH1 */
#define LPDDR4_LPDDR4_CORE_PCSR_CH1_SRSTC_Pos   0UL
#define LPDDR4_LPDDR4_CORE_PCSR_CH1_SRSTC_Msk   0x1UL
#define LPDDR4_LPDDR4_CORE_PCSR_CH1_UPDC_Pos    1UL
#define LPDDR4_LPDDR4_CORE_PCSR_CH1_UPDC_Msk    0x2UL
#define LPDDR4_LPDDR4_CORE_PCSR_CH1_NBC_Pos     2UL
#define LPDDR4_LPDDR4_CORE_PCSR_CH1_NBC_Msk     0x3CUL
#define LPDDR4_LPDDR4_CORE_PCSR_CH1_PBC_Pos     6UL
#define LPDDR4_LPDDR4_CORE_PCSR_CH1_PBC_Msk     0x3C0UL
/* LPDDR4_LPDDR4_CORE.MRR_CH0 */
#define LPDDR4_LPDDR4_CORE_MRR_CH0_DONE_Pos     0UL
#define LPDDR4_LPDDR4_CORE_MRR_CH0_DONE_Msk     0x1UL
#define LPDDR4_LPDDR4_CORE_MRR_CH0_READOUT_Pos  1UL
#define LPDDR4_LPDDR4_CORE_MRR_CH0_READOUT_Msk  0x1FEUL
/* LPDDR4_LPDDR4_CORE.MRR_CH1 */
#define LPDDR4_LPDDR4_CORE_MRR_CH1_DONE_Pos     0UL
#define LPDDR4_LPDDR4_CORE_MRR_CH1_DONE_Msk     0x1UL
#define LPDDR4_LPDDR4_CORE_MRR_CH1_READOUT_Pos  1UL
#define LPDDR4_LPDDR4_CORE_MRR_CH1_READOUT_Msk  0x1FEUL
/* LPDDR4_LPDDR4_CORE.SHAD_LPMR1 */
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS0_BL_Pos 0UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS0_BL_Msk 0x3UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS0_WPRE_Pos 2UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS0_WPRE_Msk 0x4UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS0_RPRE_Pos 3UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS0_RPRE_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS0_NWR_Pos 4UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS0_NWR_Msk 0x70UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS0_RPST_Pos 7UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS0_RPST_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS1_BL_Pos 8UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS1_BL_Msk 0x300UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS1_WPRE_Pos 10UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS1_WPRE_Msk 0x400UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS1_RPRE_Pos 11UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS1_RPRE_Msk 0x800UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS1_NWR_Pos 12UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS1_NWR_Msk 0x7000UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS1_RPST_Pos 15UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR1_SHAD_LPMR1_FS1_RPST_Msk 0x8000UL
/* LPDDR4_LPDDR4_CORE.SHAD_LPMR2 */
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_FS0_RL_Pos 0UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_FS0_RL_Msk 0x7UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_FS0_WL_Pos 3UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_FS0_WL_Msk 0x38UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_FS0_WLS_Pos 6UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_FS0_WLS_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_WRLEV_Pos 7UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_WRLEV_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_FS1_RL_Pos 8UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_FS1_RL_Msk 0x700UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_FS1_WL_Pos 11UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_FS1_WL_Msk 0x3800UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_FS1_WLS_Pos 14UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_FS1_WLS_Msk 0x4000UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_RESERVED_Pos 15UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR2_SHAD_LPMR2_RESERVED_Msk 0x8000UL
/* LPDDR4_LPDDR4_CORE.SHAD_LPMR3 */
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS0_PUCAL_Pos 0UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS0_PUCAL_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS0_WPST_Pos 1UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS0_WPST_Msk 0x2UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_PPRP_Pos 2UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_PPRP_Msk 0x4UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS0_PDDS_Pos 3UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS0_PDDS_Msk 0x38UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS0_RDBI_Pos 6UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS0_RDBI_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS0_WDBI_Pos 7UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS0_WDBI_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS1_PUCAL_Pos 8UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS1_PUCAL_Msk 0x100UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS1_WPST_Pos 9UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS1_WPST_Msk 0x200UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_RESERVED_Pos 10UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_RESERVED_Msk 0x400UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS1_PDDS_Pos 11UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS1_PDDS_Msk 0x3800UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS1_RDBI_Pos 14UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS1_RDBI_Msk 0x4000UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS1_WDBI_Pos 15UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR3_SHAD_LPMR3_FS1_WDBI_Msk 0x8000UL
/* LPDDR4_LPDDR4_CORE.SHAD_LPMR11 */
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_FS0_DQODT_Pos 0UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_FS0_DQODT_Msk 0x7UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_RESERVED0_Pos 3UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_RESERVED0_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_FS0_CAODT_Pos 4UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_FS0_CAODT_Msk 0x70UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_RESERVED1_Pos 7UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_RESERVED1_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_FS1_DQODT_Pos 8UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_FS1_DQODT_Msk 0x700UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_RESERVED2_Pos 11UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_RESERVED2_Msk 0x800UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_FS1_CAODT_Pos 12UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_FS1_CAODT_Msk 0x7000UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_RESERVED3_Pos 15UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR11_SHAD_LPMR11_RESERVED3_Msk 0x8000UL
/* LPDDR4_LPDDR4_CORE.SHAD_LPMR12 */
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR12_SHAD_LPMR12_FS0_VREFCAS_Pos 0UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR12_SHAD_LPMR12_FS0_VREFCAS_Msk 0x3FUL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR12_SHAD_LPMR12_FS0_VREFCAR_Pos 6UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR12_SHAD_LPMR12_FS0_VREFCAR_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR12_SHAD_LPMR12_RESERVED0_Pos 7UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR12_SHAD_LPMR12_RESERVED0_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR12_SHAD_LPMR12_FS1_VREFCAS_Pos 8UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR12_SHAD_LPMR12_FS1_VREFCAS_Msk 0x3F00UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR12_SHAD_LPMR12_FS1_VREFCAR_Pos 14UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR12_SHAD_LPMR12_FS1_VREFCAR_Msk 0x4000UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR12_SHAD_LPMR12_RESERVED1_Pos 15UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR12_SHAD_LPMR12_RESERVED1_Msk 0x8000UL
/* LPDDR4_LPDDR4_CORE.SHAD_LPMR13 */
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_CBT_Pos 0UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_CBT_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_RPT_Pos 1UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_RPT_Msk 0x2UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_VRO_Pos 2UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_VRO_Msk 0x4UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_VRCG_Pos 3UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_VRCG_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_RRO_Pos 4UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_RRO_Msk 0x10UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_DMD_Pos 5UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_DMD_Msk 0x20UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_FSPWR_Pos 6UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_FSPWR_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_FSPOP_Pos 7UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR13_SHAD_LPMR13_FSPOP_Msk 0x80UL
/* LPDDR4_LPDDR4_CORE.SHAD_LPMR14 */
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR14_SHAD_LPMR14_FS0_VREFDQS_Pos 0UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR14_SHAD_LPMR14_FS0_VREFDQS_Msk 0x3FUL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR14_SHAD_LPMR14_FS0_VREFDQR_Pos 6UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR14_SHAD_LPMR14_FS0_VREFDQR_Msk 0x40UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR14_SHAD_LPMR14_RESERVED0_Pos 7UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR14_SHAD_LPMR14_RESERVED0_Msk 0x80UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR14_SHAD_LPMR14_FS1_VREFDQS_Pos 8UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR14_SHAD_LPMR14_FS1_VREFDQS_Msk 0x3F00UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR14_SHAD_LPMR14_FS1_VREFDQR_Pos 14UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR14_SHAD_LPMR14_FS1_VREFDQR_Msk 0x4000UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR14_SHAD_LPMR14_RESERVED1_Pos 15UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR14_SHAD_LPMR14_RESERVED1_Msk 0x8000UL
/* LPDDR4_LPDDR4_CORE.SHAD_LPMR22 */
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS0_SOCODT_Pos 0UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS0_SOCODT_Msk 0x7UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS0_ODTECK_Pos 3UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS0_ODTECK_Msk 0x8UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS0_ODTECS_Pos 4UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS0_ODTECS_Msk 0x10UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS0_ODTDCA_Pos 5UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS0_ODTDCA_Msk 0x20UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_ODTDX8_Pos 6UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_ODTDX8_Msk 0xC0UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS1_SOCODT_Pos 8UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS1_SOCODT_Msk 0x700UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS1_ODTECK_Pos 11UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS1_ODTECK_Msk 0x800UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS1_ODTECS_Pos 12UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS1_ODTECS_Msk 0x1000UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS1_ODTDCA_Pos 13UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_FS1_ODTDCA_Msk 0x2000UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_RESERVED_Pos 14UL
#define LPDDR4_LPDDR4_CORE_SHAD_LPMR22_SHAD_LPMR22_RESERVED_Msk 0xC000UL
/* LPDDR4_LPDDR4_CORE.RESP */
#define LPDDR4_LPDDR4_CORE_RESP_RESP_WRLEV_Pos  0UL
#define LPDDR4_LPDDR4_CORE_RESP_RESP_WRLEV_Msk  0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.DATA0 */
#define LPDDR4_LPDDR4_CORE_DATA0_RDDATA_Pos     0UL
#define LPDDR4_LPDDR4_CORE_DATA0_RDDATA_Msk     0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.DATA1 */
#define LPDDR4_LPDDR4_CORE_DATA1_RDDATA_Pos     0UL
#define LPDDR4_LPDDR4_CORE_DATA1_RDDATA_Msk     0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.DATA2 */
#define LPDDR4_LPDDR4_CORE_DATA2_RDDATA_Pos     0UL
#define LPDDR4_LPDDR4_CORE_DATA2_RDDATA_Msk     0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.DATA3 */
#define LPDDR4_LPDDR4_CORE_DATA3_RDDATA_Pos     0UL
#define LPDDR4_LPDDR4_CORE_DATA3_RDDATA_Msk     0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.DATA4 */
#define LPDDR4_LPDDR4_CORE_DATA4_RDDATA_Pos     0UL
#define LPDDR4_LPDDR4_CORE_DATA4_RDDATA_Msk     0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.DATA5 */
#define LPDDR4_LPDDR4_CORE_DATA5_RDDATA_Pos     0UL
#define LPDDR4_LPDDR4_CORE_DATA5_RDDATA_Msk     0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.DATA6 */
#define LPDDR4_LPDDR4_CORE_DATA6_RDDATA_Pos     0UL
#define LPDDR4_LPDDR4_CORE_DATA6_RDDATA_Msk     0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.DATA7 */
#define LPDDR4_LPDDR4_CORE_DATA7_RDDATA_Pos     0UL
#define LPDDR4_LPDDR4_CORE_DATA7_RDDATA_Msk     0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.DATA8 */
#define LPDDR4_LPDDR4_CORE_DATA8_RDVALID_Pos    0UL
#define LPDDR4_LPDDR4_CORE_DATA8_RDVALID_Msk    0x1UL
/* LPDDR4_LPDDR4_CORE.INECCSTT0 */
#define LPDDR4_LPDDR4_CORE_INECCSTT0_ECC_ERROR_ADDR_Pos 0UL
#define LPDDR4_LPDDR4_CORE_INECCSTT0_ECC_ERROR_ADDR_Msk 0x3FFFFFFFUL
/* LPDDR4_LPDDR4_CORE.INECCSTT1 */
#define LPDDR4_LPDDR4_CORE_INECCSTT1_ECC_ERROR_SYNDROME_Pos 0UL
#define LPDDR4_LPDDR4_CORE_INECCSTT1_ECC_ERROR_SYNDROME_Msk 0xFFFFFFFFUL
/* LPDDR4_LPDDR4_CORE.INECCSTT2 */
#define LPDDR4_LPDDR4_CORE_INECCSTT2_ECC_ERROR_SEC_Pos 0UL
#define LPDDR4_LPDDR4_CORE_INECCSTT2_ECC_ERROR_SEC_Msk 0xFUL
#define LPDDR4_LPDDR4_CORE_INECCSTT2_ECC_ERROR_DED_Pos 4UL
#define LPDDR4_LPDDR4_CORE_INECCSTT2_ECC_ERROR_DED_Msk 0xF0UL
/* LPDDR4_LPDDR4_CORE.INECCSTT3 */
#define LPDDR4_LPDDR4_CORE_INECCSTT3_ECC_ERR_BUFF_EMPTY_Pos 0UL
#define LPDDR4_LPDDR4_CORE_INECCSTT3_ECC_ERR_BUFF_EMPTY_Msk 0x1UL
#define LPDDR4_LPDDR4_CORE_INECCSTT3_ECC_ERR_BUFF_FULL_Pos 1UL
#define LPDDR4_LPDDR4_CORE_INECCSTT3_ECC_ERR_BUFF_FULL_Msk 0x2UL
/* LPDDR4_LPDDR4_CORE.INECCSTT4 */
#define LPDDR4_LPDDR4_CORE_INECCSTT4_SEC_NUM_Pos 0UL
#define LPDDR4_LPDDR4_CORE_INECCSTT4_SEC_NUM_Msk 0xFFFFUL
#define LPDDR4_LPDDR4_CORE_INECCSTT4_DED_NUM_Pos 16UL
#define LPDDR4_LPDDR4_CORE_INECCSTT4_DED_NUM_Msk 0xFFFF0000UL


/* LPDDR4_EMPU_EMPU_STRUCT.ADDR0 */
#define LPDDR4_EMPU_EMPU_STRUCT_ADDR0_SUBREGION_DISABLE_Pos 0UL
#define LPDDR4_EMPU_EMPU_STRUCT_ADDR0_SUBREGION_DISABLE_Msk 0xFFUL
#define LPDDR4_EMPU_EMPU_STRUCT_ADDR0_ADDR24_Pos 8UL
#define LPDDR4_EMPU_EMPU_STRUCT_ADDR0_ADDR24_Msk 0xFFFFFF00UL
/* LPDDR4_EMPU_EMPU_STRUCT.ATT0 */
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_UR_Pos     0UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_UR_Msk     0x1UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_UW_Pos     1UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_UW_Msk     0x2UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_UX_Pos     2UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_UX_Msk     0x4UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_PR_Pos     3UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_PR_Msk     0x8UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_PW_Pos     4UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_PW_Msk     0x10UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_PX_Pos     5UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_PX_Msk     0x20UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_NS_Pos     6UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_NS_Msk     0x40UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_PC_MASK_0_Pos 8UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_PC_MASK_0_Msk 0x100UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_PC_MASK_15_TO_1_Pos 9UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_PC_MASK_15_TO_1_Msk 0xFFFE00UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_REGION_SIZE_Pos 24UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_REGION_SIZE_Msk 0x1F000000UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_PC_MATCH_Pos 30UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_PC_MATCH_Msk 0x40000000UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_ENABLED_Pos 31UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT0_ENABLED_Msk 0x80000000UL
/* LPDDR4_EMPU_EMPU_STRUCT.ADDR1 */
#define LPDDR4_EMPU_EMPU_STRUCT_ADDR1_SUBREGION_DISABLE_Pos 0UL
#define LPDDR4_EMPU_EMPU_STRUCT_ADDR1_SUBREGION_DISABLE_Msk 0xFFUL
#define LPDDR4_EMPU_EMPU_STRUCT_ADDR1_ADDR24_Pos 8UL
#define LPDDR4_EMPU_EMPU_STRUCT_ADDR1_ADDR24_Msk 0xFFFFFF00UL
/* LPDDR4_EMPU_EMPU_STRUCT.ATT1 */
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_UR_Pos     0UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_UR_Msk     0x1UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_UW_Pos     1UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_UW_Msk     0x2UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_UX_Pos     2UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_UX_Msk     0x4UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_PR_Pos     3UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_PR_Msk     0x8UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_PW_Pos     4UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_PW_Msk     0x10UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_PX_Pos     5UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_PX_Msk     0x20UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_NS_Pos     6UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_NS_Msk     0x40UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_PC_MASK_0_Pos 8UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_PC_MASK_0_Msk 0x100UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_PC_MASK_15_TO_1_Pos 9UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_PC_MASK_15_TO_1_Msk 0xFFFE00UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_REGION_SIZE_Pos 24UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_REGION_SIZE_Msk 0x1F000000UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_PC_MATCH_Pos 30UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_PC_MATCH_Msk 0x40000000UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_ENABLED_Pos 31UL
#define LPDDR4_EMPU_EMPU_STRUCT_ATT1_ENABLED_Msk 0x80000000UL


#endif /* _CYIP_LPDDR4_H_ */


/* [] END OF FILE */
