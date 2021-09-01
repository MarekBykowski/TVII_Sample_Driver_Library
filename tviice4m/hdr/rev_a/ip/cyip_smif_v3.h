/***************************************************************************//**
* \file cyip_smif_v3.h
*
* \brief
* SMIF IP definitions
*
* \note
* Generator version: 1.6.0.481
* Database revision: TVIICE4M_CW2112
*
********************************************************************************
* \copyright
* Copyright 2016-2021, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYIP_SMIF_V3_H_
#define _CYIP_SMIF_V3_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     SMIF
*******************************************************************************/

#define SMIF_SMIF_CRYPTO_SECTION_SIZE           0x00000080UL
#define SMIF_DEVICE_SECTION_SIZE                0x00000080UL
#define SMIF_MPC_SECTION_SIZE                   0x00001000UL
#define SMIF_SECTION_SIZE                       0x00010000UL

/**
  * \brief Cryptography command (SMIF_SMIF_CRYPTO_CRYPTO_CMD)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_CMD_field {
  uint32_t                         u1START:1;
  uint32_t                         :31;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_CMD_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_CMD {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_CMD_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_CMD_t;

/**
  * \brief Cryptography base address (SMIF_SMIF_CRYPTO_CRYPTO_ADDR)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_ADDR_field {
  uint32_t                         :8;
  uint32_t                         u24ADDR:24;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_ADDR_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_ADDR {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_ADDR_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_ADDR_t;

/**
  * \brief Cryptography mask (SMIF_SMIF_CRYPTO_CRYPTO_MASK)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_MASK_field {
  uint32_t                         :8;
  uint32_t                         u24MASK:24;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_MASK_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_MASK {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_MASK_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_MASK_t;

/**
  * \brief Cryptography subregion disable (SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_field {
  uint32_t                         u8SUBREGION_DISABLE:8;
  uint32_t                         :24;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_t;

/**
  * \brief Cryptography input 0 (SMIF_SMIF_CRYPTO_CRYPTO_INPUT0)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_field {
  uint32_t                         u4INPUT_LSB:4;
  uint32_t                         u28INPUT_MSB:28;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0 {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_t;

/**
  * \brief Cryptography input 1 (SMIF_SMIF_CRYPTO_CRYPTO_INPUT1)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_field {
  uint32_t                         u32INPUT:32;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1 {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_t;

/**
  * \brief Cryptography input 2 (SMIF_SMIF_CRYPTO_CRYPTO_INPUT2)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_field {
  uint32_t                         u32INPUT:32;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2 {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_t;

/**
  * \brief Cryptography input 3 (SMIF_SMIF_CRYPTO_CRYPTO_INPUT3)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_field {
  uint32_t                         u32INPUT:32;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3 {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_t;

/**
  * \brief Cryptography key 0 (SMIF_SMIF_CRYPTO_CRYPTO_KEY0)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_KEY0_field {
  uint32_t                         u32KEY:32;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_KEY0_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_KEY0 {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_KEY0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_KEY0_t;

/**
  * \brief Cryptography key 1 (SMIF_SMIF_CRYPTO_CRYPTO_KEY1)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_KEY1_field {
  uint32_t                         u32KEY:32;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_KEY1_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_KEY1 {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_KEY1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_KEY1_t;

/**
  * \brief Cryptography key 2 (SMIF_SMIF_CRYPTO_CRYPTO_KEY2)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_KEY2_field {
  uint32_t                         u32KEY:32;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_KEY2_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_KEY2 {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_KEY2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_KEY2_t;

/**
  * \brief Cryptography key 3 (SMIF_SMIF_CRYPTO_CRYPTO_KEY3)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_KEY3_field {
  uint32_t                         u32KEY:32;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_KEY3_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_KEY3 {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_KEY3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_KEY3_t;

/**
  * \brief Cryptography output 0 (SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_field {
  uint32_t                         u32OUTPUT:32;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0 {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_t;

/**
  * \brief Cryptography output 1 (SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_field {
  uint32_t                         u32OUTPUT:32;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1 {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_t;

/**
  * \brief Cryptography output 2 (SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_field {
  uint32_t                         u32OUTPUT:32;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2 {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_t;

/**
  * \brief Cryptography output 3 (SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3)
  */
typedef struct stc_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_field {
  uint32_t                         u32OUTPUT:32;
} stc_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_field_t;

typedef union un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3 {
  uint32_t                         u32Register;
  stc_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_t;



/**
  * \brief Control (SMIF_DEVICE_CTL)
  */
typedef struct stc_SMIF_DEVICE_CTL_field {
  uint32_t                         u1WR_EN:1;
  uint32_t                         :3;
  uint32_t                         u1CRYPTO_EN:1;
  uint32_t                         :3;
  uint32_t                         u2DATA_SEL:2;
  uint32_t                         :2;
  uint32_t                         u3MERGE_TIMEOUT:3;
  uint32_t                         u1MERGE_EN:1;
  uint32_t                         u14TOTAL_TIMEOUT:14;
  uint32_t                         u1TOTAL_TIMEOUT_EN:1;
  uint32_t                         u1ENABLED:1;
} stc_SMIF_DEVICE_CTL_field_t;

typedef union un_SMIF_DEVICE_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_CTL_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_CTL_t;

/**
  * \brief Device region base address (SMIF_DEVICE_ADDR)
  */
typedef struct stc_SMIF_DEVICE_ADDR_field {
  uint32_t                         :8;
  uint32_t                         u24ADDR:24;
} stc_SMIF_DEVICE_ADDR_field_t;

typedef union un_SMIF_DEVICE_ADDR {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_ADDR_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_ADDR_t;

/**
  * \brief Device region mask (SMIF_DEVICE_MASK)
  */
typedef struct stc_SMIF_DEVICE_MASK_field {
  uint32_t                         :8;
  uint32_t                         u24MASK:24;
} stc_SMIF_DEVICE_MASK_field_t;

typedef union un_SMIF_DEVICE_MASK {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_MASK_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_MASK_t;

/**
  * \brief Address control (SMIF_DEVICE_ADDR_CTL)
  */
typedef struct stc_SMIF_DEVICE_ADDR_CTL_field {
  uint32_t                         u3SIZE3:3;
  uint32_t                         :5;
  uint32_t                         u1DIV2:1;
  uint32_t                         :23;
} stc_SMIF_DEVICE_ADDR_CTL_field_t;

typedef union un_SMIF_DEVICE_ADDR_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_ADDR_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_ADDR_CTL_t;

/**
  * \brief RX Clock Delay Tap Select Register (SMIF_DEVICE_DELAY_TAP_SEL)
  */
typedef struct stc_SMIF_DEVICE_DELAY_TAP_SEL_field {
  uint32_t                         u8SEL:8;
  uint32_t                         :24;
} stc_SMIF_DEVICE_DELAY_TAP_SEL_field_t;

typedef union un_SMIF_DEVICE_DELAY_TAP_SEL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_DELAY_TAP_SEL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_DELAY_TAP_SEL_t;

/**
  * \brief Read status (SMIF_DEVICE_RD_STATUS)
  */
typedef struct stc_SMIF_DEVICE_RD_STATUS_field {
  uint32_t                         u8FS_STATUS:8;
  uint32_t                         :24;
} stc_SMIF_DEVICE_RD_STATUS_field_t;

typedef union un_SMIF_DEVICE_RD_STATUS {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_RD_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_RD_STATUS_t;

/**
  * \brief Read command control (SMIF_DEVICE_RD_CMD_CTL)
  */
typedef struct stc_SMIF_DEVICE_RD_CMD_CTL_field {
  uint32_t                         u8CODE:8;
  uint32_t                         u8CODEH:8;
  uint32_t                         u2WIDTH:2;
  uint32_t                         u1DDR_MODE:1;
  uint32_t                         :11;
  uint32_t                         u2PRESENT2:2;
} stc_SMIF_DEVICE_RD_CMD_CTL_field_t;

typedef union un_SMIF_DEVICE_RD_CMD_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_RD_CMD_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_RD_CMD_CTL_t;

/**
  * \brief Read address control (SMIF_DEVICE_RD_ADDR_CTL)
  */
typedef struct stc_SMIF_DEVICE_RD_ADDR_CTL_field {
  uint32_t                         :16;
  uint32_t                         u2WIDTH:2;
  uint32_t                         u1DDR_MODE:1;
  uint32_t                         :13;
} stc_SMIF_DEVICE_RD_ADDR_CTL_field_t;

typedef union un_SMIF_DEVICE_RD_ADDR_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_RD_ADDR_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_RD_ADDR_CTL_t;

/**
  * \brief Read mode control (SMIF_DEVICE_RD_MODE_CTL)
  */
typedef struct stc_SMIF_DEVICE_RD_MODE_CTL_field {
  uint32_t                         u8CODE:8;
  uint32_t                         u8CODEH:8;
  uint32_t                         u2WIDTH:2;
  uint32_t                         u1DDR_MODE:1;
  uint32_t                         :11;
  uint32_t                         u2PRESENT2:2;
} stc_SMIF_DEVICE_RD_MODE_CTL_field_t;

typedef union un_SMIF_DEVICE_RD_MODE_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_RD_MODE_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_RD_MODE_CTL_t;

/**
  * \brief Read dummy control (SMIF_DEVICE_RD_DUMMY_CTL)
  */
typedef struct stc_SMIF_DEVICE_RD_DUMMY_CTL_field {
  uint32_t                         u5SIZE5:5;
  uint32_t                         :25;
  uint32_t                         u2PRESENT2:2;
} stc_SMIF_DEVICE_RD_DUMMY_CTL_field_t;

typedef union un_SMIF_DEVICE_RD_DUMMY_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_RD_DUMMY_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_RD_DUMMY_CTL_t;

/**
  * \brief Read data control (SMIF_DEVICE_RD_DATA_CTL)
  */
typedef struct stc_SMIF_DEVICE_RD_DATA_CTL_field {
  uint32_t                         :16;
  uint32_t                         u2WIDTH:2;
  uint32_t                         u1DDR_MODE:1;
  uint32_t                         :13;
} stc_SMIF_DEVICE_RD_DATA_CTL_field_t;

typedef union un_SMIF_DEVICE_RD_DATA_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_RD_DATA_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_RD_DATA_CTL_t;

/**
  * \brief Read Bus CRC control (SMIF_DEVICE_RD_CRC_CTL)
  */
typedef struct stc_SMIF_DEVICE_RD_CRC_CTL_field {
  uint32_t                         u8STATUS_CHECK_MASK:8;
  uint32_t                         u8STATUS_ERROR_POL:8;
  uint32_t                         u8DATA_CRC_INPUT_SIZE:8;
  uint32_t                         u2CMD_ADDR_CRC_WIDTH:2;
  uint32_t                         u1CMD_ADDR_CRC_DDR_MODE:1;
  uint32_t                         u1CMD_ADDR_CRC_INPUT:1;
  uint32_t                         u1DATA_CRC_CHECK:1;
  uint32_t                         :1;
  uint32_t                         u1CMD_ADDR_CRC_PRESENT:1;
  uint32_t                         u1DATA_CRC_PRESENT:1;
} stc_SMIF_DEVICE_RD_CRC_CTL_field_t;

typedef union un_SMIF_DEVICE_RD_CRC_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_RD_CRC_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_RD_CRC_CTL_t;

/**
  * \brief Read boundary control (SMIF_DEVICE_RD_BOUND_CTL)
  */
typedef struct stc_SMIF_DEVICE_RD_BOUND_CTL_field {
  uint32_t                         u5SIZE5:5;
  uint32_t                         :11;
  uint32_t                         u2SUB_PAGE_SIZE:2;
  uint32_t                         :2;
  uint32_t                         u2SUB_PAGE_NR:2;
  uint32_t                         :6;
  uint32_t                         u1SUBSEQ_BOUND_EN:1;
  uint32_t                         :2;
  uint32_t                         u1PRESENT:1;
} stc_SMIF_DEVICE_RD_BOUND_CTL_field_t;

typedef union un_SMIF_DEVICE_RD_BOUND_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_RD_BOUND_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_RD_BOUND_CTL_t;

/**
  * \brief Write command control (SMIF_DEVICE_WR_CMD_CTL)
  */
typedef struct stc_SMIF_DEVICE_WR_CMD_CTL_field {
  uint32_t                         u8CODE:8;
  uint32_t                         u8CODEH:8;
  uint32_t                         u2WIDTH:2;
  uint32_t                         u1DDR_MODE:1;
  uint32_t                         :11;
  uint32_t                         u2PRESENT2:2;
} stc_SMIF_DEVICE_WR_CMD_CTL_field_t;

typedef union un_SMIF_DEVICE_WR_CMD_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_WR_CMD_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_WR_CMD_CTL_t;

/**
  * \brief Write address control (SMIF_DEVICE_WR_ADDR_CTL)
  */
typedef struct stc_SMIF_DEVICE_WR_ADDR_CTL_field {
  uint32_t                         :16;
  uint32_t                         u2WIDTH:2;
  uint32_t                         u1DDR_MODE:1;
  uint32_t                         :13;
} stc_SMIF_DEVICE_WR_ADDR_CTL_field_t;

typedef union un_SMIF_DEVICE_WR_ADDR_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_WR_ADDR_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_WR_ADDR_CTL_t;

/**
  * \brief Write mode control (SMIF_DEVICE_WR_MODE_CTL)
  */
typedef struct stc_SMIF_DEVICE_WR_MODE_CTL_field {
  uint32_t                         u8CODE:8;
  uint32_t                         u8CODEH:8;
  uint32_t                         u2WIDTH:2;
  uint32_t                         u1DDR_MODE:1;
  uint32_t                         :11;
  uint32_t                         u2PRESENT2:2;
} stc_SMIF_DEVICE_WR_MODE_CTL_field_t;

typedef union un_SMIF_DEVICE_WR_MODE_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_WR_MODE_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_WR_MODE_CTL_t;

/**
  * \brief Write dummy control (SMIF_DEVICE_WR_DUMMY_CTL)
  */
typedef struct stc_SMIF_DEVICE_WR_DUMMY_CTL_field {
  uint32_t                         u5SIZE5:5;
  uint32_t                         :12;
  uint32_t                         u1RWDS_EN:1;
  uint32_t                         :12;
  uint32_t                         u2PRESENT2:2;
} stc_SMIF_DEVICE_WR_DUMMY_CTL_field_t;

typedef union un_SMIF_DEVICE_WR_DUMMY_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_WR_DUMMY_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_WR_DUMMY_CTL_t;

/**
  * \brief Write data control (SMIF_DEVICE_WR_DATA_CTL)
  */
typedef struct stc_SMIF_DEVICE_WR_DATA_CTL_field {
  uint32_t                         :16;
  uint32_t                         u2WIDTH:2;
  uint32_t                         u1DDR_MODE:1;
  uint32_t                         :13;
} stc_SMIF_DEVICE_WR_DATA_CTL_field_t;

typedef union un_SMIF_DEVICE_WR_DATA_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_WR_DATA_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_WR_DATA_CTL_t;

/**
  * \brief Write Bus CRC control (SMIF_DEVICE_WR_CRC_CTL)
  */
typedef struct stc_SMIF_DEVICE_WR_CRC_CTL_field {
  uint32_t                         :16;
  uint32_t                         u8DATA_CRC_INPUT_SIZE:8;
  uint32_t                         u2CMD_ADDR_CRC_WIDTH:2;
  uint32_t                         u1CMD_ADDR_CRC_DDR_MODE:1;
  uint32_t                         u1CMD_ADDR_CRC_INPUT:1;
  uint32_t                         :2;
  uint32_t                         u1CMD_ADDR_CRC_PRESENT:1;
  uint32_t                         u1DATA_CRC_PRESENT:1;
} stc_SMIF_DEVICE_WR_CRC_CTL_field_t;

typedef union un_SMIF_DEVICE_WR_CRC_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DEVICE_WR_CRC_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DEVICE_WR_CRC_CTL_t;



/**
  * \brief Config register with error response, RegionID PPC_MPC_MAIN is the security owner PC. The error response configuration is located in CFG.RESPONSE, only one such configuration exists applying to all protection contexts in the system. (SMIF_MPC_CFG)
  */
typedef struct stc_SMIF_MPC_CFG_field {
  uint32_t                         :4;
  uint32_t                         u1RESPONSE:1;
  uint32_t                         :27;
} stc_SMIF_MPC_CFG_field_t;

typedef union un_SMIF_MPC_CFG {
  uint32_t                         u32Register;
  stc_SMIF_MPC_CFG_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_CFG_t;

/**
  * \brief Interrupt (SMIF_MPC_INTR)
  */
typedef struct stc_SMIF_MPC_INTR_field {
  uint32_t                         u1VIOLATION:1;
  uint32_t                         :31;
} stc_SMIF_MPC_INTR_field_t;

typedef union un_SMIF_MPC_INTR {
  uint32_t                         u32Register;
  stc_SMIF_MPC_INTR_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_INTR_t;

/**
  * \brief Interrupt set (SMIF_MPC_INTR_SET)
  */
typedef struct stc_SMIF_MPC_INTR_SET_field {
  uint32_t                         u1VIOLATION:1;
  uint32_t                         :31;
} stc_SMIF_MPC_INTR_SET_field_t;

typedef union un_SMIF_MPC_INTR_SET {
  uint32_t                         u32Register;
  stc_SMIF_MPC_INTR_SET_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_INTR_SET_t;

/**
  * \brief Interrupt mask (SMIF_MPC_INTR_MASK)
  */
typedef struct stc_SMIF_MPC_INTR_MASK_field {
  uint32_t                         u1VIOLATION:1;
  uint32_t                         :31;
} stc_SMIF_MPC_INTR_MASK_field_t;

typedef union un_SMIF_MPC_INTR_MASK {
  uint32_t                         u32Register;
  stc_SMIF_MPC_INTR_MASK_field_t   stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_INTR_MASK_t;

/**
  * \brief Interrupt masked (SMIF_MPC_INTR_MASKED)
  */
typedef struct stc_SMIF_MPC_INTR_MASKED_field {
  uint32_t                         u1VIOLATION:1;
  uint32_t                         :31;
} stc_SMIF_MPC_INTR_MASKED_field_t;

typedef union un_SMIF_MPC_INTR_MASKED {
  uint32_t                         u32Register;
  stc_SMIF_MPC_INTR_MASKED_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_INTR_MASKED_t;

/**
  * \brief Infor about violation (SMIF_MPC_INTR_INFO1)
  */
typedef struct stc_SMIF_MPC_INTR_INFO1_field {
  uint32_t                         u32VALUE:32;
} stc_SMIF_MPC_INTR_INFO1_field_t;

typedef union un_SMIF_MPC_INTR_INFO1 {
  uint32_t                         u32Register;
  stc_SMIF_MPC_INTR_INFO1_field_t  stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_INTR_INFO1_t;

/**
  * \brief Infor about violation (SMIF_MPC_INTR_INFO2)
  */
typedef struct stc_SMIF_MPC_INTR_INFO2_field {
  uint32_t                         u16HMASTER:16;
  uint32_t                         u1HNONSEC:1;
  uint32_t                         u1CFG_NS:1;
  uint32_t                         u1HWRITE:1;
  uint32_t                         :5;
  uint32_t                         u4HAUSER:4;
  uint32_t                         :2;
  uint32_t                         u1SECURITY_VIOLATION:1;
  uint32_t                         u1ACCESS_VIOLATION:1;
} stc_SMIF_MPC_INTR_INFO2_field_t;

typedef union un_SMIF_MPC_INTR_INFO2 {
  uint32_t                         u32Register;
  stc_SMIF_MPC_INTR_INFO2_field_t  stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_INTR_INFO2_t;

/**
  * \brief Control register with lock bit and auto-increment only (Separate CTRL for each PC depends on access_pc) (SMIF_MPC_CTRL)
  */
typedef struct stc_SMIF_MPC_CTRL_field {
  uint32_t                         :8;
  uint32_t                         u1AUTO_INC:1;
  uint32_t                         :22;
  uint32_t                         u1LOCK:1;
} stc_SMIF_MPC_CTRL_field_t;

typedef union un_SMIF_MPC_CTRL {
  uint32_t                         u32Register;
  stc_SMIF_MPC_CTRL_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_CTRL_t;

/**
  * \brief Max value of block-based index register (SMIF_MPC_BLK_MAX)
  */
typedef struct stc_SMIF_MPC_BLK_MAX_field {
  uint32_t                         u32VALUE:32;
} stc_SMIF_MPC_BLK_MAX_field_t;

typedef union un_SMIF_MPC_BLK_MAX {
  uint32_t                         u32Register;
  stc_SMIF_MPC_BLK_MAX_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_BLK_MAX_t;

/**
  * \brief Block size & initialization in progress (SMIF_MPC_BLK_CFG)
  */
typedef struct stc_SMIF_MPC_BLK_CFG_field {
  uint32_t                         u4BLOCK_SIZE:4;
  uint32_t                         :27;
  uint32_t                         u1INIT_IN_PROGRESS:1;
} stc_SMIF_MPC_BLK_CFG_field_t;

typedef union un_SMIF_MPC_BLK_CFG {
  uint32_t                         u32Register;
  stc_SMIF_MPC_BLK_CFG_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_BLK_CFG_t;

/**
  * \brief Index of 32-block group accessed through BLK_LUT (Separate IDX for each PC depending on access_pc) (SMIF_MPC_BLK_IDX)
  */
typedef struct stc_SMIF_MPC_BLK_IDX_field {
  uint32_t                         u32VALUE:32;
} stc_SMIF_MPC_BLK_IDX_field_t;

typedef union un_SMIF_MPC_BLK_IDX {
  uint32_t                         u32Register;
  stc_SMIF_MPC_BLK_IDX_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_BLK_IDX_t;

/**
  * \brief NS status for 32 blocks at BLK_IDX with PC=<access_pc> (SMIF_MPC_BLK_LUT)
  */
typedef struct stc_SMIF_MPC_BLK_LUT_field {
  uint32_t                         u1ATTR_NS0:1;
  uint32_t                         u1ATTR_NS1:1;
  uint32_t                         u1ATTR_NS2:1;
  uint32_t                         u1ATTR_NS3:1;
  uint32_t                         u1ATTR_NS4:1;
  uint32_t                         u1ATTR_NS5:1;
  uint32_t                         u1ATTR_NS6:1;
  uint32_t                         u1ATTR_NS7:1;
  uint32_t                         u1ATTR_NS8:1;
  uint32_t                         u1ATTR_NS9:1;
  uint32_t                         u1ATTR_NS10:1;
  uint32_t                         u1ATTR_NS11:1;
  uint32_t                         u1ATTR_NS12:1;
  uint32_t                         u1ATTR_NS13:1;
  uint32_t                         u1ATTR_NS14:1;
  uint32_t                         u1ATTR_NS15:1;
  uint32_t                         u1ATTR_NS16:1;
  uint32_t                         u1ATTR_NS17:1;
  uint32_t                         u1ATTR_NS18:1;
  uint32_t                         u1ATTR_NS19:1;
  uint32_t                         u1ATTR_NS20:1;
  uint32_t                         u1ATTR_NS21:1;
  uint32_t                         u1ATTR_NS22:1;
  uint32_t                         u1ATTR_NS23:1;
  uint32_t                         u1ATTR_NS24:1;
  uint32_t                         u1ATTR_NS25:1;
  uint32_t                         u1ATTR_NS26:1;
  uint32_t                         u1ATTR_NS27:1;
  uint32_t                         u1ATTR_NS28:1;
  uint32_t                         u1ATTR_NS29:1;
  uint32_t                         u1ATTR_NS30:1;
  uint32_t                         u1ATTR_NS31:1;
} stc_SMIF_MPC_BLK_LUT_field_t;

typedef union un_SMIF_MPC_BLK_LUT {
  uint32_t                         u32Register;
  stc_SMIF_MPC_BLK_LUT_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_BLK_LUT_t;

/**
  * \brief Control register with lock bit and auto-increment only (SMIF_MPC_ROT_CTRL)
  */
typedef struct stc_SMIF_MPC_ROT_CTRL_field {
  uint32_t                         :8;
  uint32_t                         u1AUTO_INC:1;
  uint32_t                         :22;
  uint32_t                         u1LOCK:1;
} stc_SMIF_MPC_ROT_CTRL_field_t;

typedef union un_SMIF_MPC_ROT_CTRL {
  uint32_t                         u32Register;
  stc_SMIF_MPC_ROT_CTRL_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_ROT_CTRL_t;

/**
  * \brief Sets block-size to match memory size (external memory only) (SMIF_MPC_ROT_CFG)
  */
typedef struct stc_SMIF_MPC_ROT_CFG_field {
  uint32_t                         u4BLOCK_SIZE:4;
  uint32_t                         :28;
} stc_SMIF_MPC_ROT_CFG_field_t;

typedef union un_SMIF_MPC_ROT_CFG {
  uint32_t                         u32Register;
  stc_SMIF_MPC_ROT_CFG_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_ROT_CFG_t;

/**
  * \brief Max value of block-based index register for ROT (SMIF_MPC_ROT_BLK_MAX)
  */
typedef struct stc_SMIF_MPC_ROT_BLK_MAX_field {
  uint32_t                         u32VALUE:32;
} stc_SMIF_MPC_ROT_BLK_MAX_field_t;

typedef union un_SMIF_MPC_ROT_BLK_MAX {
  uint32_t                         u32Register;
  stc_SMIF_MPC_ROT_BLK_MAX_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_ROT_BLK_MAX_t;

/**
  * \brief Same as BLK_CFG (SMIF_MPC_ROT_BLK_CFG)
  */
typedef struct stc_SMIF_MPC_ROT_BLK_CFG_field {
  uint32_t                         u4BLOCK_SIZE:4;
  uint32_t                         :27;
  uint32_t                         u1INIT_IN_PROGRESS:1;
} stc_SMIF_MPC_ROT_BLK_CFG_field_t;

typedef union un_SMIF_MPC_ROT_BLK_CFG {
  uint32_t                         u32Register;
  stc_SMIF_MPC_ROT_BLK_CFG_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_ROT_BLK_CFG_t;

/**
  * \brief Index of 8-block group accessed through ROT_BLK_LUT_* (SMIF_MPC_ROT_BLK_IDX)
  */
typedef struct stc_SMIF_MPC_ROT_BLK_IDX_field {
  uint32_t                         u32VALUE:32;
} stc_SMIF_MPC_ROT_BLK_IDX_field_t;

typedef union un_SMIF_MPC_ROT_BLK_IDX {
  uint32_t                         u32Register;
  stc_SMIF_MPC_ROT_BLK_IDX_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_ROT_BLK_IDX_t;

/**
  * \brief Protection context of 8-block group accesses through ROT_BLK_LUT (SMIF_MPC_ROT_BLK_PC)
  */
typedef struct stc_SMIF_MPC_ROT_BLK_PC_field {
  uint32_t                         u4PC:4;
  uint32_t                         :28;
} stc_SMIF_MPC_ROT_BLK_PC_field_t;

typedef union un_SMIF_MPC_ROT_BLK_PC {
  uint32_t                         u32Register;
  stc_SMIF_MPC_ROT_BLK_PC_field_t  stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_ROT_BLK_PC_t;

/**
  * \brief (R,W,NS) bits for 8 blocks at ROT_BLK_IDX for PC=ROT_BKL_PC (SMIF_MPC_ROT_BLK_LUT)
  */
typedef struct stc_SMIF_MPC_ROT_BLK_LUT_field {
  uint32_t                         u3ATTR0:3;
  uint32_t                         :1;
  uint32_t                         u3ATTR1:3;
  uint32_t                         :1;
  uint32_t                         u3ATTR2:3;
  uint32_t                         :1;
  uint32_t                         u3ATTR3:3;
  uint32_t                         :1;
  uint32_t                         u3ATTR4:3;
  uint32_t                         :1;
  uint32_t                         u3ATTR5:3;
  uint32_t                         :1;
  uint32_t                         u3ATTR6:3;
  uint32_t                         :1;
  uint32_t                         u3ATTR7:3;
} stc_SMIF_MPC_ROT_BLK_LUT_field_t;

typedef union un_SMIF_MPC_ROT_BLK_LUT {
  uint32_t                         u32Register;
  stc_SMIF_MPC_ROT_BLK_LUT_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_MPC_ROT_BLK_LUT_t;



/**
  * \brief Control (SMIF_CTL)
  */
typedef struct stc_SMIF_CTL_field {
  uint32_t                         u1XIP_MODE:1;
  uint32_t                         :3;
  uint32_t                         u1CLOCK_IF_TX_SEL:1;
  uint32_t                         u3DELAY_LINE_SEL:3;
  uint32_t                         u1DELAY_TAP_ENABLED:1;
  uint32_t                         u1INT_CLOCK_DL_ENABLED:1;
  uint32_t                         u2INT_CLOCK_CAPTURE_CYCLE:2;
  uint32_t                         u3CLOCK_IF_RX_SEL:3;
  uint32_t                         :1;
  uint32_t                         u3DESELECT_DELAY:3;
  uint32_t                         :1;
  uint32_t                         u2SELECT_SETUP_DELAY:2;
  uint32_t                         u2SELECT_HOLD_DELAY:2;
  uint32_t                         u1BLOCK:1;
  uint32_t                         u1CLOCK_IF_SEL:1;
  uint32_t                         :5;
  uint32_t                         u1ENABLED:1;
} stc_SMIF_CTL_field_t;

typedef union un_SMIF_CTL {
  uint32_t                         u32Register;
  stc_SMIF_CTL_field_t             stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_CTL_t;

/**
  * \brief Status (SMIF_STATUS)
  */
typedef struct stc_SMIF_STATUS_field {
  uint32_t                         :31;
  uint32_t                         u1BUSY:1;
} stc_SMIF_STATUS_field_t;

typedef union un_SMIF_STATUS {
  uint32_t                         u32Register;
  stc_SMIF_STATUS_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_STATUS_t;

/**
  * \brief Internal Clocking Delay Tap Select Register 0 (SMIF_INT_CLOCK_DELAY_TAP_SEL0)
  */
typedef struct stc_SMIF_INT_CLOCK_DELAY_TAP_SEL0_field {
  uint32_t                         u8DATA_BIT0:8;
  uint32_t                         u8DATA_BIT1:8;
  uint32_t                         u8DATA_BIT2:8;
  uint32_t                         u8DATA_BIT3:8;
} stc_SMIF_INT_CLOCK_DELAY_TAP_SEL0_field_t;

typedef union un_SMIF_INT_CLOCK_DELAY_TAP_SEL0 {
  uint32_t                         u32Register;
  stc_SMIF_INT_CLOCK_DELAY_TAP_SEL0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_INT_CLOCK_DELAY_TAP_SEL0_t;

/**
  * \brief Internal Clocking Delay Tap Select Register 1 (SMIF_INT_CLOCK_DELAY_TAP_SEL1)
  */
typedef struct stc_SMIF_INT_CLOCK_DELAY_TAP_SEL1_field {
  uint32_t                         u8DATA_BIT4:8;
  uint32_t                         u8DATA_BIT5:8;
  uint32_t                         u8DATA_BIT6:8;
  uint32_t                         u8DATA_BIT7:8;
} stc_SMIF_INT_CLOCK_DELAY_TAP_SEL1_field_t;

typedef union un_SMIF_INT_CLOCK_DELAY_TAP_SEL1 {
  uint32_t                         u32Register;
  stc_SMIF_INT_CLOCK_DELAY_TAP_SEL1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_INT_CLOCK_DELAY_TAP_SEL1_t;

/**
  * \brief Data Learning Control Register (SMIF_DL_CTL)
  */
typedef struct stc_SMIF_DL_CTL_field {
  uint32_t                         u16DLP:16;
  uint32_t                         u4DLP_SIZE:4;
  uint32_t                         :4;
  uint32_t                         u4DL_WARNING_LEVEL:4;
  uint32_t                         :4;
} stc_SMIF_DL_CTL_field_t;

typedef union un_SMIF_DL_CTL {
  uint32_t                         u32Register;
  stc_SMIF_DL_CTL_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DL_CTL_t;

/**
  * \brief Data Learning Status Register 0 (SMIF_DL_STATUS0)
  */
typedef struct stc_SMIF_DL_STATUS0_field {
  uint32_t                         u8DATA_BIT0:8;
  uint32_t                         u8DATA_BIT1:8;
  uint32_t                         u8DATA_BIT2:8;
  uint32_t                         u8DATA_BIT3:8;
} stc_SMIF_DL_STATUS0_field_t;

typedef union un_SMIF_DL_STATUS0 {
  uint32_t                         u32Register;
  stc_SMIF_DL_STATUS0_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DL_STATUS0_t;

/**
  * \brief Data Learning Status Register 1 (SMIF_DL_STATUS1)
  */
typedef struct stc_SMIF_DL_STATUS1_field {
  uint32_t                         u8DATA_BIT4:8;
  uint32_t                         u8DATA_BIT5:8;
  uint32_t                         u8DATA_BIT6:8;
  uint32_t                         u8DATA_BIT7:8;
} stc_SMIF_DL_STATUS1_field_t;

typedef union un_SMIF_DL_STATUS1 {
  uint32_t                         u32Register;
  stc_SMIF_DL_STATUS1_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_DL_STATUS1_t;

/**
  * \brief Transmitter command FIFO status (SMIF_TX_CMD_FIFO_STATUS)
  */
typedef struct stc_SMIF_TX_CMD_FIFO_STATUS_field {
  uint32_t                         u4USED4:4;
  uint32_t                         :28;
} stc_SMIF_TX_CMD_FIFO_STATUS_field_t;

typedef union un_SMIF_TX_CMD_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_SMIF_TX_CMD_FIFO_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_TX_CMD_FIFO_STATUS_t;

/**
  * \brief Transmitter command MMIO FIFO status (SMIF_TX_CMD_MMIO_FIFO_STATUS)
  */
typedef struct stc_SMIF_TX_CMD_MMIO_FIFO_STATUS_field {
  uint32_t                         u4USED4:4;
  uint32_t                         :28;
} stc_SMIF_TX_CMD_MMIO_FIFO_STATUS_field_t;

typedef union un_SMIF_TX_CMD_MMIO_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_SMIF_TX_CMD_MMIO_FIFO_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_TX_CMD_MMIO_FIFO_STATUS_t;

/**
  * \brief Transmitter command MMIO FIFO write (SMIF_TX_CMD_MMIO_FIFO_WR)
  */
typedef struct stc_SMIF_TX_CMD_MMIO_FIFO_WR_field {
  uint32_t                         u27DATA27:27;
  uint32_t                         :5;
} stc_SMIF_TX_CMD_MMIO_FIFO_WR_field_t;

typedef union un_SMIF_TX_CMD_MMIO_FIFO_WR {
  uint32_t                         u32Register;
  stc_SMIF_TX_CMD_MMIO_FIFO_WR_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_TX_CMD_MMIO_FIFO_WR_t;

/**
  * \brief Transmitter data MMIO FIFO control (SMIF_TX_DATA_MMIO_FIFO_CTL)
  */
typedef struct stc_SMIF_TX_DATA_MMIO_FIFO_CTL_field {
  uint32_t                         u3TX_TRIGGER_LEVEL:3;
  uint32_t                         :29;
} stc_SMIF_TX_DATA_MMIO_FIFO_CTL_field_t;

typedef union un_SMIF_TX_DATA_MMIO_FIFO_CTL {
  uint32_t                         u32Register;
  stc_SMIF_TX_DATA_MMIO_FIFO_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_TX_DATA_MMIO_FIFO_CTL_t;

/**
  * \brief Transmitter data FIFO status (SMIF_TX_DATA_FIFO_STATUS)
  */
typedef struct stc_SMIF_TX_DATA_FIFO_STATUS_field {
  uint32_t                         u4USED4:4;
  uint32_t                         :28;
} stc_SMIF_TX_DATA_FIFO_STATUS_field_t;

typedef union un_SMIF_TX_DATA_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_SMIF_TX_DATA_FIFO_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_TX_DATA_FIFO_STATUS_t;

/**
  * \brief Transmitter data MMIO FIFO status (SMIF_TX_DATA_MMIO_FIFO_STATUS)
  */
typedef struct stc_SMIF_TX_DATA_MMIO_FIFO_STATUS_field {
  uint32_t                         u4USED4:4;
  uint32_t                         :28;
} stc_SMIF_TX_DATA_MMIO_FIFO_STATUS_field_t;

typedef union un_SMIF_TX_DATA_MMIO_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_SMIF_TX_DATA_MMIO_FIFO_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_TX_DATA_MMIO_FIFO_STATUS_t;

/**
  * \brief Transmitter data MMIO FIFO write (SMIF_TX_DATA_MMIO_FIFO_WR1)
  */
typedef struct stc_SMIF_TX_DATA_MMIO_FIFO_WR1_field {
  uint32_t                         u8DATA0:8;
  uint32_t                         :24;
} stc_SMIF_TX_DATA_MMIO_FIFO_WR1_field_t;

typedef union un_SMIF_TX_DATA_MMIO_FIFO_WR1 {
  uint32_t                         u32Register;
  stc_SMIF_TX_DATA_MMIO_FIFO_WR1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_TX_DATA_MMIO_FIFO_WR1_t;

/**
  * \brief Transmitter data MMIO FIFO write (SMIF_TX_DATA_MMIO_FIFO_WR2)
  */
typedef struct stc_SMIF_TX_DATA_MMIO_FIFO_WR2_field {
  uint32_t                         u8DATA0:8;
  uint32_t                         u8DATA1:8;
  uint32_t                         :16;
} stc_SMIF_TX_DATA_MMIO_FIFO_WR2_field_t;

typedef union un_SMIF_TX_DATA_MMIO_FIFO_WR2 {
  uint32_t                         u32Register;
  stc_SMIF_TX_DATA_MMIO_FIFO_WR2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_TX_DATA_MMIO_FIFO_WR2_t;

/**
  * \brief Transmitter data MMIO FIFO write (SMIF_TX_DATA_MMIO_FIFO_WR4)
  */
typedef struct stc_SMIF_TX_DATA_MMIO_FIFO_WR4_field {
  uint32_t                         u8DATA0:8;
  uint32_t                         u8DATA1:8;
  uint32_t                         u8DATA2:8;
  uint32_t                         u8DATA3:8;
} stc_SMIF_TX_DATA_MMIO_FIFO_WR4_field_t;

typedef union un_SMIF_TX_DATA_MMIO_FIFO_WR4 {
  uint32_t                         u32Register;
  stc_SMIF_TX_DATA_MMIO_FIFO_WR4_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_TX_DATA_MMIO_FIFO_WR4_t;

/**
  * \brief Transmitter data MMIO FIFO write (SMIF_TX_DATA_MMIO_FIFO_WR1ODD)
  */
typedef struct stc_SMIF_TX_DATA_MMIO_FIFO_WR1ODD_field {
  uint32_t                         u8DATA0:8;
  uint32_t                         :24;
} stc_SMIF_TX_DATA_MMIO_FIFO_WR1ODD_field_t;

typedef union un_SMIF_TX_DATA_MMIO_FIFO_WR1ODD {
  uint32_t                         u32Register;
  stc_SMIF_TX_DATA_MMIO_FIFO_WR1ODD_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_TX_DATA_MMIO_FIFO_WR1ODD_t;

/**
  * \brief Receiver data MMIO FIFO control (SMIF_RX_DATA_MMIO_FIFO_CTL)
  */
typedef struct stc_SMIF_RX_DATA_MMIO_FIFO_CTL_field {
  uint32_t                         u3RX_TRIGGER_LEVEL:3;
  uint32_t                         :29;
} stc_SMIF_RX_DATA_MMIO_FIFO_CTL_field_t;

typedef union un_SMIF_RX_DATA_MMIO_FIFO_CTL {
  uint32_t                         u32Register;
  stc_SMIF_RX_DATA_MMIO_FIFO_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_RX_DATA_MMIO_FIFO_CTL_t;

/**
  * \brief Receiver data MMIO FIFO status (SMIF_RX_DATA_MMIO_FIFO_STATUS)
  */
typedef struct stc_SMIF_RX_DATA_MMIO_FIFO_STATUS_field {
  uint32_t                         u4USED4:4;
  uint32_t                         :28;
} stc_SMIF_RX_DATA_MMIO_FIFO_STATUS_field_t;

typedef union un_SMIF_RX_DATA_MMIO_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_SMIF_RX_DATA_MMIO_FIFO_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_RX_DATA_MMIO_FIFO_STATUS_t;

/**
  * \brief Receiver data FIFO status (SMIF_RX_DATA_FIFO_STATUS)
  */
typedef struct stc_SMIF_RX_DATA_FIFO_STATUS_field {
  uint32_t                         u4USED4:4;
  uint32_t                         :4;
  uint32_t                         u1RX_SR_USED:1;
  uint32_t                         :23;
} stc_SMIF_RX_DATA_FIFO_STATUS_field_t;

typedef union un_SMIF_RX_DATA_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_SMIF_RX_DATA_FIFO_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_RX_DATA_FIFO_STATUS_t;

/**
  * \brief Receiver data MMIO FIFO read (SMIF_RX_DATA_MMIO_FIFO_RD1)
  */
typedef struct stc_SMIF_RX_DATA_MMIO_FIFO_RD1_field {
  uint32_t                         u8DATA0:8;
  uint32_t                         :24;
} stc_SMIF_RX_DATA_MMIO_FIFO_RD1_field_t;

typedef union un_SMIF_RX_DATA_MMIO_FIFO_RD1 {
  uint32_t                         u32Register;
  stc_SMIF_RX_DATA_MMIO_FIFO_RD1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_RX_DATA_MMIO_FIFO_RD1_t;

/**
  * \brief Receiver data MMIO FIFO read (SMIF_RX_DATA_MMIO_FIFO_RD2)
  */
typedef struct stc_SMIF_RX_DATA_MMIO_FIFO_RD2_field {
  uint32_t                         u8DATA0:8;
  uint32_t                         u8DATA1:8;
  uint32_t                         :16;
} stc_SMIF_RX_DATA_MMIO_FIFO_RD2_field_t;

typedef union un_SMIF_RX_DATA_MMIO_FIFO_RD2 {
  uint32_t                         u32Register;
  stc_SMIF_RX_DATA_MMIO_FIFO_RD2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_RX_DATA_MMIO_FIFO_RD2_t;

/**
  * \brief Receiver data MMIO FIFO read (SMIF_RX_DATA_MMIO_FIFO_RD4)
  */
typedef struct stc_SMIF_RX_DATA_MMIO_FIFO_RD4_field {
  uint32_t                         u8DATA0:8;
  uint32_t                         u8DATA1:8;
  uint32_t                         u8DATA2:8;
  uint32_t                         u8DATA3:8;
} stc_SMIF_RX_DATA_MMIO_FIFO_RD4_field_t;

typedef union un_SMIF_RX_DATA_MMIO_FIFO_RD4 {
  uint32_t                         u32Register;
  stc_SMIF_RX_DATA_MMIO_FIFO_RD4_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_RX_DATA_MMIO_FIFO_RD4_t;

/**
  * \brief Receiver data MMIO FIFO silent read (SMIF_RX_DATA_MMIO_FIFO_RD1_SILENT)
  */
typedef struct stc_SMIF_RX_DATA_MMIO_FIFO_RD1_SILENT_field {
  uint32_t                         u8DATA0:8;
  uint32_t                         :24;
} stc_SMIF_RX_DATA_MMIO_FIFO_RD1_SILENT_field_t;

typedef union un_SMIF_RX_DATA_MMIO_FIFO_RD1_SILENT {
  uint32_t                         u32Register;
  stc_SMIF_RX_DATA_MMIO_FIFO_RD1_SILENT_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_RX_DATA_MMIO_FIFO_RD1_SILENT_t;

/**
  * \brief Slow cache control (SMIF_SLOW_CA_CTL)
  */
typedef struct stc_SMIF_SLOW_CA_CTL_field {
  uint32_t                         :16;
  uint32_t                         u2WAY:2;
  uint32_t                         :6;
  uint32_t                         u2SET_ADDR:2;
  uint32_t                         :4;
  uint32_t                         u1PREF_EN:1;
  uint32_t                         u1ENABLED:1;
} stc_SMIF_SLOW_CA_CTL_field_t;

typedef union un_SMIF_SLOW_CA_CTL {
  uint32_t                         u32Register;
  stc_SMIF_SLOW_CA_CTL_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SLOW_CA_CTL_t;

/**
  * \brief Slow cache command (SMIF_SLOW_CA_CMD)
  */
typedef struct stc_SMIF_SLOW_CA_CMD_field {
  uint32_t                         u1INV:1;
  uint32_t                         :31;
} stc_SMIF_SLOW_CA_CMD_field_t;

typedef union un_SMIF_SLOW_CA_CMD {
  uint32_t                         u32Register;
  stc_SMIF_SLOW_CA_CMD_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_SLOW_CA_CMD_t;

/**
  * \brief Fast cache control (SMIF_FAST_CA_CTL)
  */
typedef struct stc_SMIF_FAST_CA_CTL_field {
  uint32_t                         :16;
  uint32_t                         u2WAY:2;
  uint32_t                         :6;
  uint32_t                         u2SET_ADDR:2;
  uint32_t                         :4;
  uint32_t                         u1PREF_EN:1;
  uint32_t                         u1ENABLED:1;
} stc_SMIF_FAST_CA_CTL_field_t;

typedef union un_SMIF_FAST_CA_CTL {
  uint32_t                         u32Register;
  stc_SMIF_FAST_CA_CTL_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_FAST_CA_CTL_t;

/**
  * \brief Fast cache command (SMIF_FAST_CA_CMD)
  */
typedef struct stc_SMIF_FAST_CA_CMD_field {
  uint32_t                         u1INV:1;
  uint32_t                         :31;
} stc_SMIF_FAST_CA_CMD_field_t;

typedef union un_SMIF_FAST_CA_CMD {
  uint32_t                         u32Register;
  stc_SMIF_FAST_CA_CMD_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_FAST_CA_CMD_t;

/**
  * \brief CRC Command (SMIF_CRC_CMD)
  */
typedef struct stc_SMIF_CRC_CMD_field {
  uint32_t                         u1START:1;
  uint32_t                         u1CONTINUE:1;
  uint32_t                         :30;
} stc_SMIF_CRC_CMD_field_t;

typedef union un_SMIF_CRC_CMD {
  uint32_t                         u32Register;
  stc_SMIF_CRC_CMD_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_CRC_CMD_t;

/**
  * \brief CRC input 0 (SMIF_CRC_INPUT0)
  */
typedef struct stc_SMIF_CRC_INPUT0_field {
  uint32_t                         u32INPUT:32;
} stc_SMIF_CRC_INPUT0_field_t;

typedef union un_SMIF_CRC_INPUT0 {
  uint32_t                         u32Register;
  stc_SMIF_CRC_INPUT0_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_CRC_INPUT0_t;

/**
  * \brief CRC input 1 (SMIF_CRC_INPUT1)
  */
typedef struct stc_SMIF_CRC_INPUT1_field {
  uint32_t                         u32INPUT:32;
} stc_SMIF_CRC_INPUT1_field_t;

typedef union un_SMIF_CRC_INPUT1 {
  uint32_t                         u32Register;
  stc_SMIF_CRC_INPUT1_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_CRC_INPUT1_t;

/**
  * \brief CRC output (SMIF_CRC_OUTPUT)
  */
typedef struct stc_SMIF_CRC_OUTPUT_field {
  uint32_t                         u8CRC_OUTPUT:8;
  uint32_t                         :24;
} stc_SMIF_CRC_OUTPUT_field_t;

typedef union un_SMIF_CRC_OUTPUT {
  uint32_t                         u32Register;
  stc_SMIF_CRC_OUTPUT_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_CRC_OUTPUT_t;

/**
  * \brief Interrupt register (SMIF_INTR)
  */
typedef struct stc_SMIF_INTR_field {
  uint32_t                         u1TR_TX_REQ:1;
  uint32_t                         u1TR_RX_REQ:1;
  uint32_t                         u1XIP_ALIGNMENT_ERROR:1;
  uint32_t                         u1TX_CMD_FIFO_OVERFLOW:1;
  uint32_t                         u1TX_DATA_FIFO_OVERFLOW:1;
  uint32_t                         u1RX_DATA_MMIO_FIFO_UNDERFLOW:1;
  uint32_t                         :2;
  uint32_t                         u1DL_FAIL:1;
  uint32_t                         :3;
  uint32_t                         u1DL_WARNING:1;
  uint32_t                         :3;
  uint32_t                         u1CRC_ERROR:1;
  uint32_t                         u1FS_STATUS_ERROR:1;
  uint32_t                         :14;
} stc_SMIF_INTR_field_t;

typedef union un_SMIF_INTR {
  uint32_t                         u32Register;
  stc_SMIF_INTR_field_t            stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_INTR_t;

/**
  * \brief Interrupt set register (SMIF_INTR_SET)
  */
typedef struct stc_SMIF_INTR_SET_field {
  uint32_t                         u1TR_TX_REQ:1;
  uint32_t                         u1TR_RX_REQ:1;
  uint32_t                         u1XIP_ALIGNMENT_ERROR:1;
  uint32_t                         u1TX_CMD_FIFO_OVERFLOW:1;
  uint32_t                         u1TX_DATA_FIFO_OVERFLOW:1;
  uint32_t                         u1RX_DATA_MMIO_FIFO_UNDERFLOW:1;
  uint32_t                         :2;
  uint32_t                         u1DL_FAIL:1;
  uint32_t                         :3;
  uint32_t                         u1DL_WARNING:1;
  uint32_t                         :3;
  uint32_t                         u1CRC_ERROR:1;
  uint32_t                         u1FS_STATUS_ERROR:1;
  uint32_t                         :14;
} stc_SMIF_INTR_SET_field_t;

typedef union un_SMIF_INTR_SET {
  uint32_t                         u32Register;
  stc_SMIF_INTR_SET_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_INTR_SET_t;

/**
  * \brief Interrupt mask register (SMIF_INTR_MASK)
  */
typedef struct stc_SMIF_INTR_MASK_field {
  uint32_t                         u1TR_TX_REQ:1;
  uint32_t                         u1TR_RX_REQ:1;
  uint32_t                         u1XIP_ALIGNMENT_ERROR:1;
  uint32_t                         u1TX_CMD_FIFO_OVERFLOW:1;
  uint32_t                         u1TX_DATA_FIFO_OVERFLOW:1;
  uint32_t                         u1RX_DATA_MMIO_FIFO_UNDERFLOW:1;
  uint32_t                         :2;
  uint32_t                         u1DL_FAIL:1;
  uint32_t                         :3;
  uint32_t                         u1DL_WARNING:1;
  uint32_t                         :3;
  uint32_t                         u1CRC_ERROR:1;
  uint32_t                         u1FS_STATUS_ERROR:1;
  uint32_t                         :14;
} stc_SMIF_INTR_MASK_field_t;

typedef union un_SMIF_INTR_MASK {
  uint32_t                         u32Register;
  stc_SMIF_INTR_MASK_field_t       stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_INTR_MASK_t;

/**
  * \brief Interrupt masked register (SMIF_INTR_MASKED)
  */
typedef struct stc_SMIF_INTR_MASKED_field {
  uint32_t                         u1TR_TX_REQ:1;
  uint32_t                         u1TR_RX_REQ:1;
  uint32_t                         u1XIP_ALIGNMENT_ERROR:1;
  uint32_t                         u1TX_CMD_FIFO_OVERFLOW:1;
  uint32_t                         u1TX_DATA_FIFO_OVERFLOW:1;
  uint32_t                         u1RX_DATA_MMIO_FIFO_UNDERFLOW:1;
  uint32_t                         :2;
  uint32_t                         u1DL_FAIL:1;
  uint32_t                         :3;
  uint32_t                         u1DL_WARNING:1;
  uint32_t                         :3;
  uint32_t                         u1CRC_ERROR:1;
  uint32_t                         u1FS_STATUS_ERROR:1;
  uint32_t                         :14;
} stc_SMIF_INTR_MASKED_field_t;

typedef union un_SMIF_INTR_MASKED {
  uint32_t                         u32Register;
  stc_SMIF_INTR_MASKED_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_INTR_MASKED_t;

/**
  * \brief Distinguishes normal vs. MPC interrupt (SMIF_INTR_CAUSE)
  */
typedef struct stc_SMIF_INTR_CAUSE_field {
  uint32_t                         u1NORMAL:1;
  uint32_t                         u1MPC:1;
  uint32_t                         :30;
} stc_SMIF_INTR_CAUSE_field_t;

typedef union un_SMIF_INTR_CAUSE {
  uint32_t                         u32Register;
  stc_SMIF_INTR_CAUSE_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SMIF_INTR_CAUSE_t;



/**
  * \brief Cryptography registers (one set for each key) (SMIF_SMIF_CRYPTO)
  */
typedef struct stc_SMIF_SMIF_CRYPTO {
  un_SMIF_SMIF_CRYPTO_CRYPTO_CMD_t unCRYPTO_CMD;       /*!< 0x00000000 Cryptography command */
  un_SMIF_SMIF_CRYPTO_CRYPTO_ADDR_t unCRYPTO_ADDR;     /*!< 0x00000004 Cryptography base address */
  un_SMIF_SMIF_CRYPTO_CRYPTO_MASK_t unCRYPTO_MASK;     /*!< 0x00000008 Cryptography mask */
  un_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_t unCRYPTO_SUBREGION; /*!< 0x0000000C Cryptography subregion disable */
  uint32_t                         au32Reserved[4];
  un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_t unCRYPTO_INPUT0; /*!< 0x00000020 Cryptography input 0 */
  un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_t unCRYPTO_INPUT1; /*!< 0x00000024 Cryptography input 1 */
  un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_t unCRYPTO_INPUT2; /*!< 0x00000028 Cryptography input 2 */
  un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_t unCRYPTO_INPUT3; /*!< 0x0000002C Cryptography input 3 */
  uint32_t                         au32Reserved1[4];
  un_SMIF_SMIF_CRYPTO_CRYPTO_KEY0_t unCRYPTO_KEY0;     /*!< 0x00000040 Cryptography key 0 */
  un_SMIF_SMIF_CRYPTO_CRYPTO_KEY1_t unCRYPTO_KEY1;     /*!< 0x00000044 Cryptography key 1 */
  un_SMIF_SMIF_CRYPTO_CRYPTO_KEY2_t unCRYPTO_KEY2;     /*!< 0x00000048 Cryptography key 2 */
  un_SMIF_SMIF_CRYPTO_CRYPTO_KEY3_t unCRYPTO_KEY3;     /*!< 0x0000004C Cryptography key 3 */
  uint32_t                         au32Reserved2[4];
  un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_t unCRYPTO_OUTPUT0; /*!< 0x00000060 Cryptography output 0 */
  un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_t unCRYPTO_OUTPUT1; /*!< 0x00000064 Cryptography output 1 */
  un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_t unCRYPTO_OUTPUT2; /*!< 0x00000068 Cryptography output 2 */
  un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_t unCRYPTO_OUTPUT3; /*!< 0x0000006C Cryptography output 3 */
  uint32_t                         au32Reserved3[4];
} stc_SMIF_SMIF_CRYPTO_t;                              /*!< Size = 128 (0x80) */

/**
  * \brief Device (only used for XIP acceses) (SMIF_DEVICE)
  */
typedef struct stc_SMIF_DEVICE {
  un_SMIF_DEVICE_CTL_t             unCTL;              /*!< 0x00000000 Control */
  uint32_t                         u32Reserved;
  un_SMIF_DEVICE_ADDR_t            unADDR;             /*!< 0x00000008 Device region base address */
  un_SMIF_DEVICE_MASK_t            unMASK;             /*!< 0x0000000C Device region mask */
  uint32_t                         au32Reserved1[4];
  un_SMIF_DEVICE_ADDR_CTL_t        unADDR_CTL;         /*!< 0x00000020 Address control */
  uint32_t                         au32Reserved2[2];
  un_SMIF_DEVICE_DELAY_TAP_SEL_t   unDELAY_TAP_SEL;    /*!< 0x0000002C RX Clock Delay Tap Select Register */
  un_SMIF_DEVICE_RD_STATUS_t       unRD_STATUS;        /*!< 0x00000030 Read status */
  uint32_t                         au32Reserved3[3];
  un_SMIF_DEVICE_RD_CMD_CTL_t      unRD_CMD_CTL;       /*!< 0x00000040 Read command control */
  un_SMIF_DEVICE_RD_ADDR_CTL_t     unRD_ADDR_CTL;      /*!< 0x00000044 Read address control */
  un_SMIF_DEVICE_RD_MODE_CTL_t     unRD_MODE_CTL;      /*!< 0x00000048 Read mode control */
  un_SMIF_DEVICE_RD_DUMMY_CTL_t    unRD_DUMMY_CTL;     /*!< 0x0000004C Read dummy control */
  un_SMIF_DEVICE_RD_DATA_CTL_t     unRD_DATA_CTL;      /*!< 0x00000050 Read data control */
  un_SMIF_DEVICE_RD_CRC_CTL_t      unRD_CRC_CTL;       /*!< 0x00000054 Read Bus CRC control */
  un_SMIF_DEVICE_RD_BOUND_CTL_t    unRD_BOUND_CTL;     /*!< 0x00000058 Read boundary control */
  uint32_t                         u32Reserved4;
  un_SMIF_DEVICE_WR_CMD_CTL_t      unWR_CMD_CTL;       /*!< 0x00000060 Write command control */
  un_SMIF_DEVICE_WR_ADDR_CTL_t     unWR_ADDR_CTL;      /*!< 0x00000064 Write address control */
  un_SMIF_DEVICE_WR_MODE_CTL_t     unWR_MODE_CTL;      /*!< 0x00000068 Write mode control */
  un_SMIF_DEVICE_WR_DUMMY_CTL_t    unWR_DUMMY_CTL;     /*!< 0x0000006C Write dummy control */
  un_SMIF_DEVICE_WR_DATA_CTL_t     unWR_DATA_CTL;      /*!< 0x00000070 Write data control */
  un_SMIF_DEVICE_WR_CRC_CTL_t      unWR_CRC_CTL;       /*!< 0x00000074 Write Bus CRC control */
  uint32_t                         au32Reserved5[2];
} stc_SMIF_DEVICE_t;                                   /*!< Size = 128 (0x80) */

/**
  * \brief MPC Memory Protection Controller registers (SMIF_MPC)
  */
typedef struct stc_SMIF_MPC {
  un_SMIF_MPC_CFG_t                unCFG;              /*!< 0x00000000 Config register with error response, RegionID
                                                                                PPC_MPC_MAIN is the security owner PC. The error
                                                                                response configuration is located in
                                                                                CFG.RESPONSE, only one such configuration exists
                                                                                applying to all protection contexts in the
                                                                                system. */
  uint32_t                         au32Reserved[3];
  un_SMIF_MPC_INTR_t               unINTR;             /*!< 0x00000010 Interrupt */
  un_SMIF_MPC_INTR_SET_t           unINTR_SET;         /*!< 0x00000014 Interrupt set */
  un_SMIF_MPC_INTR_MASK_t          unINTR_MASK;        /*!< 0x00000018 Interrupt mask */
  un_SMIF_MPC_INTR_MASKED_t        unINTR_MASKED;      /*!< 0x0000001C Interrupt masked */
  un_SMIF_MPC_INTR_INFO1_t         unINTR_INFO1;       /*!< 0x00000020 Infor about violation */
  un_SMIF_MPC_INTR_INFO2_t         unINTR_INFO2;       /*!< 0x00000024 Infor about violation */
  uint32_t                         au32Reserved1[54];
  un_SMIF_MPC_CTRL_t               unCTRL;             /*!< 0x00000100 Control register with lock bit and auto-increment only
                                                                                (Separate CTRL for each PC depends on access_pc) */
  un_SMIF_MPC_BLK_MAX_t            unBLK_MAX;          /*!< 0x00000104 Max value of block-based index register */
  un_SMIF_MPC_BLK_CFG_t            unBLK_CFG;          /*!< 0x00000108 Block size & initialization in progress */
  un_SMIF_MPC_BLK_IDX_t            unBLK_IDX;          /*!< 0x0000010C Index of 32-block group accessed through BLK_LUT
                                                                                (Separate IDX for each PC depending on
                                                                                access_pc) */
  un_SMIF_MPC_BLK_LUT_t            unBLK_LUT;          /*!< 0x00000110 NS status for 32 blocks at BLK_IDX with PC=<access_pc> */
  uint32_t                         au32Reserved2[59];
  un_SMIF_MPC_ROT_CTRL_t           unROT_CTRL;         /*!< 0x00000200 Control register with lock bit and auto-increment only */
  un_SMIF_MPC_ROT_CFG_t            unROT_CFG;          /*!< 0x00000204 Sets block-size to match memory size (external memory
                                                                                only) */
  un_SMIF_MPC_ROT_BLK_MAX_t        unROT_BLK_MAX;      /*!< 0x00000208 Max value of block-based index register for ROT */
  un_SMIF_MPC_ROT_BLK_CFG_t        unROT_BLK_CFG;      /*!< 0x0000020C Same as BLK_CFG */
  un_SMIF_MPC_ROT_BLK_IDX_t        unROT_BLK_IDX;      /*!< 0x00000210 Index of 8-block group accessed through ROT_BLK_LUT_* */
  un_SMIF_MPC_ROT_BLK_PC_t         unROT_BLK_PC;       /*!< 0x00000214 Protection context of 8-block group accesses through
                                                                                ROT_BLK_LUT */
  un_SMIF_MPC_ROT_BLK_LUT_t        unROT_BLK_LUT;      /*!< 0x00000218 (R,W,NS) bits for 8 blocks at ROT_BLK_IDX for
                                                                                PC=ROT_BKL_PC */
  uint32_t                         au32Reserved3[889];
} stc_SMIF_MPC_t;                                      /*!< Size = 4096 (0x1000) */

/**
  * \brief Serial Memory Interface (SMIF)
  */
typedef struct stc_SMIF {
  un_SMIF_CTL_t                    unCTL;              /*!< 0x00000000 Control */
  un_SMIF_STATUS_t                 unSTATUS;           /*!< 0x00000004 Status */
  uint32_t                         au32Reserved[2];
  un_SMIF_INT_CLOCK_DELAY_TAP_SEL0_t unINT_CLOCK_DELAY_TAP_SEL0; /*!< 0x00000010 Internal Clocking Delay Tap Select Register 0 */
  un_SMIF_INT_CLOCK_DELAY_TAP_SEL1_t unINT_CLOCK_DELAY_TAP_SEL1; /*!< 0x00000014 Internal Clocking Delay Tap Select Register 1 */
  un_SMIF_DL_CTL_t                 unDL_CTL;           /*!< 0x00000018 Data Learning Control Register */
  uint32_t                         u32Reserved1;
  un_SMIF_DL_STATUS0_t             unDL_STATUS0;       /*!< 0x00000020 Data Learning Status Register 0 */
  un_SMIF_DL_STATUS1_t             unDL_STATUS1;       /*!< 0x00000024 Data Learning Status Register 1 */
  uint32_t                         au32Reserved2[7];
  un_SMIF_TX_CMD_FIFO_STATUS_t     unTX_CMD_FIFO_STATUS; /*!< 0x00000044 Transmitter command FIFO status */
  un_SMIF_TX_CMD_MMIO_FIFO_STATUS_t unTX_CMD_MMIO_FIFO_STATUS; /*!< 0x00000048 Transmitter command MMIO FIFO status */
  uint32_t                         u32Reserved3;
  un_SMIF_TX_CMD_MMIO_FIFO_WR_t    unTX_CMD_MMIO_FIFO_WR; /*!< 0x00000050 Transmitter command MMIO FIFO write */
  uint32_t                         au32Reserved4[11];
  un_SMIF_TX_DATA_MMIO_FIFO_CTL_t  unTX_DATA_MMIO_FIFO_CTL; /*!< 0x00000080 Transmitter data MMIO FIFO control */
  un_SMIF_TX_DATA_FIFO_STATUS_t    unTX_DATA_FIFO_STATUS; /*!< 0x00000084 Transmitter data FIFO status */
  un_SMIF_TX_DATA_MMIO_FIFO_STATUS_t unTX_DATA_MMIO_FIFO_STATUS; /*!< 0x00000088 Transmitter data MMIO FIFO status */
  uint32_t                         u32Reserved5;
  un_SMIF_TX_DATA_MMIO_FIFO_WR1_t  unTX_DATA_MMIO_FIFO_WR1; /*!< 0x00000090 Transmitter data MMIO FIFO write */
  un_SMIF_TX_DATA_MMIO_FIFO_WR2_t  unTX_DATA_MMIO_FIFO_WR2; /*!< 0x00000094 Transmitter data MMIO FIFO write */
  un_SMIF_TX_DATA_MMIO_FIFO_WR4_t  unTX_DATA_MMIO_FIFO_WR4; /*!< 0x00000098 Transmitter data MMIO FIFO write */
  un_SMIF_TX_DATA_MMIO_FIFO_WR1ODD_t unTX_DATA_MMIO_FIFO_WR1ODD; /*!< 0x0000009C Transmitter data MMIO FIFO write */
  uint32_t                         au32Reserved6[8];
  un_SMIF_RX_DATA_MMIO_FIFO_CTL_t  unRX_DATA_MMIO_FIFO_CTL; /*!< 0x000000C0 Receiver data MMIO FIFO control */
  un_SMIF_RX_DATA_MMIO_FIFO_STATUS_t unRX_DATA_MMIO_FIFO_STATUS; /*!< 0x000000C4 Receiver data MMIO FIFO status */
  un_SMIF_RX_DATA_FIFO_STATUS_t    unRX_DATA_FIFO_STATUS; /*!< 0x000000C8 Receiver data FIFO status */
  uint32_t                         u32Reserved7;
  un_SMIF_RX_DATA_MMIO_FIFO_RD1_t  unRX_DATA_MMIO_FIFO_RD1; /*!< 0x000000D0 Receiver data MMIO FIFO read */
  un_SMIF_RX_DATA_MMIO_FIFO_RD2_t  unRX_DATA_MMIO_FIFO_RD2; /*!< 0x000000D4 Receiver data MMIO FIFO read */
  un_SMIF_RX_DATA_MMIO_FIFO_RD4_t  unRX_DATA_MMIO_FIFO_RD4; /*!< 0x000000D8 Receiver data MMIO FIFO read */
  uint32_t                         u32Reserved8;
  un_SMIF_RX_DATA_MMIO_FIFO_RD1_SILENT_t unRX_DATA_MMIO_FIFO_RD1_SILENT; /*!< 0x000000E0 Receiver data MMIO FIFO silent read */
  uint32_t                         au32Reserved9[7];
  un_SMIF_SLOW_CA_CTL_t            unSLOW_CA_CTL;      /*!< 0x00000100 Slow cache control */
  uint32_t                         u32Reserved10;
  un_SMIF_SLOW_CA_CMD_t            unSLOW_CA_CMD;      /*!< 0x00000108 Slow cache command */
  uint32_t                         au32Reserved11[29];
  un_SMIF_FAST_CA_CTL_t            unFAST_CA_CTL;      /*!< 0x00000180 Fast cache control */
  uint32_t                         u32Reserved12;
  un_SMIF_FAST_CA_CMD_t            unFAST_CA_CMD;      /*!< 0x00000188 Fast cache command */
  uint32_t                         au32Reserved13[29];
  stc_SMIF_SMIF_CRYPTO_t           SMIF_CRYPTO[8];     /*!< 0x00000200 Cryptography registers (one set for each key) */
  un_SMIF_CRC_CMD_t                unCRC_CMD;          /*!< 0x00000600 CRC Command */
  uint32_t                         au32Reserved14[7];
  un_SMIF_CRC_INPUT0_t             unCRC_INPUT0;       /*!< 0x00000620 CRC input 0 */
  un_SMIF_CRC_INPUT1_t             unCRC_INPUT1;       /*!< 0x00000624 CRC input 1 */
  uint32_t                         au32Reserved15[6];
  un_SMIF_CRC_OUTPUT_t             unCRC_OUTPUT;       /*!< 0x00000640 CRC output */
  uint32_t                         au32Reserved16[95];
  un_SMIF_INTR_t                   unINTR;             /*!< 0x000007C0 Interrupt register */
  un_SMIF_INTR_SET_t               unINTR_SET;         /*!< 0x000007C4 Interrupt set register */
  un_SMIF_INTR_MASK_t              unINTR_MASK;        /*!< 0x000007C8 Interrupt mask register */
  un_SMIF_INTR_MASKED_t            unINTR_MASKED;      /*!< 0x000007CC Interrupt masked register */
  un_SMIF_INTR_CAUSE_t             unINTR_CAUSE;       /*!< 0x000007D0 Distinguishes normal vs. MPC interrupt */
  uint32_t                         au32Reserved17[11];
  stc_SMIF_DEVICE_t                DEVICE[4];          /*!< 0x00000800 Device (only used for XIP acceses) */
  uint32_t                         au32Reserved18[384];
  stc_SMIF_MPC_t                   MPC[1];             /*!< 0x00001000 MPC Memory Protection Controller registers */
} stc_SMIF_t;                                          /*!< Size = 8192 (0x2000) */


/* SMIF_SMIF_CRYPTO.CRYPTO_CMD */
#define SMIF_SMIF_CRYPTO_CRYPTO_CMD_START_Pos   0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_CMD_START_Msk   0x1UL
/* SMIF_SMIF_CRYPTO.CRYPTO_ADDR */
#define SMIF_SMIF_CRYPTO_CRYPTO_ADDR_ADDR_Pos   8UL
#define SMIF_SMIF_CRYPTO_CRYPTO_ADDR_ADDR_Msk   0xFFFFFF00UL
/* SMIF_SMIF_CRYPTO.CRYPTO_MASK */
#define SMIF_SMIF_CRYPTO_CRYPTO_MASK_MASK_Pos   8UL
#define SMIF_SMIF_CRYPTO_CRYPTO_MASK_MASK_Msk   0xFFFFFF00UL
/* SMIF_SMIF_CRYPTO.CRYPTO_SUBREGION */
#define SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_SUBREGION_DISABLE_Pos 0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_SUBREGION_DISABLE_Msk 0xFFUL
/* SMIF_SMIF_CRYPTO.CRYPTO_INPUT0 */
#define SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_INPUT_LSB_Pos 0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_INPUT_LSB_Msk 0xFUL
#define SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_INPUT_MSB_Pos 4UL
#define SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_INPUT_MSB_Msk 0xFFFFFFF0UL
/* SMIF_SMIF_CRYPTO.CRYPTO_INPUT1 */
#define SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_INPUT_Pos 0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_INPUT_Msk 0xFFFFFFFFUL
/* SMIF_SMIF_CRYPTO.CRYPTO_INPUT2 */
#define SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_INPUT_Pos 0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_INPUT_Msk 0xFFFFFFFFUL
/* SMIF_SMIF_CRYPTO.CRYPTO_INPUT3 */
#define SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_INPUT_Pos 0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_INPUT_Msk 0xFFFFFFFFUL
/* SMIF_SMIF_CRYPTO.CRYPTO_KEY0 */
#define SMIF_SMIF_CRYPTO_CRYPTO_KEY0_KEY_Pos    0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_KEY0_KEY_Msk    0xFFFFFFFFUL
/* SMIF_SMIF_CRYPTO.CRYPTO_KEY1 */
#define SMIF_SMIF_CRYPTO_CRYPTO_KEY1_KEY_Pos    0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_KEY1_KEY_Msk    0xFFFFFFFFUL
/* SMIF_SMIF_CRYPTO.CRYPTO_KEY2 */
#define SMIF_SMIF_CRYPTO_CRYPTO_KEY2_KEY_Pos    0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_KEY2_KEY_Msk    0xFFFFFFFFUL
/* SMIF_SMIF_CRYPTO.CRYPTO_KEY3 */
#define SMIF_SMIF_CRYPTO_CRYPTO_KEY3_KEY_Pos    0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_KEY3_KEY_Msk    0xFFFFFFFFUL
/* SMIF_SMIF_CRYPTO.CRYPTO_OUTPUT0 */
#define SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_OUTPUT_Pos 0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_OUTPUT_Msk 0xFFFFFFFFUL
/* SMIF_SMIF_CRYPTO.CRYPTO_OUTPUT1 */
#define SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_OUTPUT_Pos 0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_OUTPUT_Msk 0xFFFFFFFFUL
/* SMIF_SMIF_CRYPTO.CRYPTO_OUTPUT2 */
#define SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_OUTPUT_Pos 0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_OUTPUT_Msk 0xFFFFFFFFUL
/* SMIF_SMIF_CRYPTO.CRYPTO_OUTPUT3 */
#define SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_OUTPUT_Pos 0UL
#define SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_OUTPUT_Msk 0xFFFFFFFFUL


/* SMIF_DEVICE.CTL */
#define SMIF_DEVICE_CTL_WR_EN_Pos               0UL
#define SMIF_DEVICE_CTL_WR_EN_Msk               0x1UL
#define SMIF_DEVICE_CTL_CRYPTO_EN_Pos           4UL
#define SMIF_DEVICE_CTL_CRYPTO_EN_Msk           0x10UL
#define SMIF_DEVICE_CTL_DATA_SEL_Pos            8UL
#define SMIF_DEVICE_CTL_DATA_SEL_Msk            0x300UL
#define SMIF_DEVICE_CTL_MERGE_TIMEOUT_Pos       12UL
#define SMIF_DEVICE_CTL_MERGE_TIMEOUT_Msk       0x7000UL
#define SMIF_DEVICE_CTL_MERGE_EN_Pos            15UL
#define SMIF_DEVICE_CTL_MERGE_EN_Msk            0x8000UL
#define SMIF_DEVICE_CTL_TOTAL_TIMEOUT_Pos       16UL
#define SMIF_DEVICE_CTL_TOTAL_TIMEOUT_Msk       0x3FFF0000UL
#define SMIF_DEVICE_CTL_TOTAL_TIMEOUT_EN_Pos    30UL
#define SMIF_DEVICE_CTL_TOTAL_TIMEOUT_EN_Msk    0x40000000UL
#define SMIF_DEVICE_CTL_ENABLED_Pos             31UL
#define SMIF_DEVICE_CTL_ENABLED_Msk             0x80000000UL
/* SMIF_DEVICE.ADDR */
#define SMIF_DEVICE_ADDR_ADDR_Pos               8UL
#define SMIF_DEVICE_ADDR_ADDR_Msk               0xFFFFFF00UL
/* SMIF_DEVICE.MASK */
#define SMIF_DEVICE_MASK_MASK_Pos               8UL
#define SMIF_DEVICE_MASK_MASK_Msk               0xFFFFFF00UL
/* SMIF_DEVICE.ADDR_CTL */
#define SMIF_DEVICE_ADDR_CTL_SIZE3_Pos          0UL
#define SMIF_DEVICE_ADDR_CTL_SIZE3_Msk          0x7UL
#define SMIF_DEVICE_ADDR_CTL_DIV2_Pos           8UL
#define SMIF_DEVICE_ADDR_CTL_DIV2_Msk           0x100UL
/* SMIF_DEVICE.DELAY_TAP_SEL */
#define SMIF_DEVICE_DELAY_TAP_SEL_SEL_Pos       0UL
#define SMIF_DEVICE_DELAY_TAP_SEL_SEL_Msk       0xFFUL
/* SMIF_DEVICE.RD_STATUS */
#define SMIF_DEVICE_RD_STATUS_FS_STATUS_Pos     0UL
#define SMIF_DEVICE_RD_STATUS_FS_STATUS_Msk     0xFFUL
/* SMIF_DEVICE.RD_CMD_CTL */
#define SMIF_DEVICE_RD_CMD_CTL_CODE_Pos         0UL
#define SMIF_DEVICE_RD_CMD_CTL_CODE_Msk         0xFFUL
#define SMIF_DEVICE_RD_CMD_CTL_CODEH_Pos        8UL
#define SMIF_DEVICE_RD_CMD_CTL_CODEH_Msk        0xFF00UL
#define SMIF_DEVICE_RD_CMD_CTL_WIDTH_Pos        16UL
#define SMIF_DEVICE_RD_CMD_CTL_WIDTH_Msk        0x30000UL
#define SMIF_DEVICE_RD_CMD_CTL_DDR_MODE_Pos     18UL
#define SMIF_DEVICE_RD_CMD_CTL_DDR_MODE_Msk     0x40000UL
#define SMIF_DEVICE_RD_CMD_CTL_PRESENT2_Pos     30UL
#define SMIF_DEVICE_RD_CMD_CTL_PRESENT2_Msk     0xC0000000UL
/* SMIF_DEVICE.RD_ADDR_CTL */
#define SMIF_DEVICE_RD_ADDR_CTL_WIDTH_Pos       16UL
#define SMIF_DEVICE_RD_ADDR_CTL_WIDTH_Msk       0x30000UL
#define SMIF_DEVICE_RD_ADDR_CTL_DDR_MODE_Pos    18UL
#define SMIF_DEVICE_RD_ADDR_CTL_DDR_MODE_Msk    0x40000UL
/* SMIF_DEVICE.RD_MODE_CTL */
#define SMIF_DEVICE_RD_MODE_CTL_CODE_Pos        0UL
#define SMIF_DEVICE_RD_MODE_CTL_CODE_Msk        0xFFUL
#define SMIF_DEVICE_RD_MODE_CTL_CODEH_Pos       8UL
#define SMIF_DEVICE_RD_MODE_CTL_CODEH_Msk       0xFF00UL
#define SMIF_DEVICE_RD_MODE_CTL_WIDTH_Pos       16UL
#define SMIF_DEVICE_RD_MODE_CTL_WIDTH_Msk       0x30000UL
#define SMIF_DEVICE_RD_MODE_CTL_DDR_MODE_Pos    18UL
#define SMIF_DEVICE_RD_MODE_CTL_DDR_MODE_Msk    0x40000UL
#define SMIF_DEVICE_RD_MODE_CTL_PRESENT2_Pos    30UL
#define SMIF_DEVICE_RD_MODE_CTL_PRESENT2_Msk    0xC0000000UL
/* SMIF_DEVICE.RD_DUMMY_CTL */
#define SMIF_DEVICE_RD_DUMMY_CTL_SIZE5_Pos      0UL
#define SMIF_DEVICE_RD_DUMMY_CTL_SIZE5_Msk      0x1FUL
#define SMIF_DEVICE_RD_DUMMY_CTL_PRESENT2_Pos   30UL
#define SMIF_DEVICE_RD_DUMMY_CTL_PRESENT2_Msk   0xC0000000UL
/* SMIF_DEVICE.RD_DATA_CTL */
#define SMIF_DEVICE_RD_DATA_CTL_WIDTH_Pos       16UL
#define SMIF_DEVICE_RD_DATA_CTL_WIDTH_Msk       0x30000UL
#define SMIF_DEVICE_RD_DATA_CTL_DDR_MODE_Pos    18UL
#define SMIF_DEVICE_RD_DATA_CTL_DDR_MODE_Msk    0x40000UL
/* SMIF_DEVICE.RD_CRC_CTL */
#define SMIF_DEVICE_RD_CRC_CTL_STATUS_CHECK_MASK_Pos 0UL
#define SMIF_DEVICE_RD_CRC_CTL_STATUS_CHECK_MASK_Msk 0xFFUL
#define SMIF_DEVICE_RD_CRC_CTL_STATUS_ERROR_POL_Pos 8UL
#define SMIF_DEVICE_RD_CRC_CTL_STATUS_ERROR_POL_Msk 0xFF00UL
#define SMIF_DEVICE_RD_CRC_CTL_DATA_CRC_INPUT_SIZE_Pos 16UL
#define SMIF_DEVICE_RD_CRC_CTL_DATA_CRC_INPUT_SIZE_Msk 0xFF0000UL
#define SMIF_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_WIDTH_Pos 24UL
#define SMIF_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_WIDTH_Msk 0x3000000UL
#define SMIF_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_DDR_MODE_Pos 26UL
#define SMIF_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_DDR_MODE_Msk 0x4000000UL
#define SMIF_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_INPUT_Pos 27UL
#define SMIF_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_INPUT_Msk 0x8000000UL
#define SMIF_DEVICE_RD_CRC_CTL_DATA_CRC_CHECK_Pos 28UL
#define SMIF_DEVICE_RD_CRC_CTL_DATA_CRC_CHECK_Msk 0x10000000UL
#define SMIF_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_PRESENT_Pos 30UL
#define SMIF_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_PRESENT_Msk 0x40000000UL
#define SMIF_DEVICE_RD_CRC_CTL_DATA_CRC_PRESENT_Pos 31UL
#define SMIF_DEVICE_RD_CRC_CTL_DATA_CRC_PRESENT_Msk 0x80000000UL
/* SMIF_DEVICE.RD_BOUND_CTL */
#define SMIF_DEVICE_RD_BOUND_CTL_SIZE5_Pos      0UL
#define SMIF_DEVICE_RD_BOUND_CTL_SIZE5_Msk      0x1FUL
#define SMIF_DEVICE_RD_BOUND_CTL_SUB_PAGE_SIZE_Pos 16UL
#define SMIF_DEVICE_RD_BOUND_CTL_SUB_PAGE_SIZE_Msk 0x30000UL
#define SMIF_DEVICE_RD_BOUND_CTL_SUB_PAGE_NR_Pos 20UL
#define SMIF_DEVICE_RD_BOUND_CTL_SUB_PAGE_NR_Msk 0x300000UL
#define SMIF_DEVICE_RD_BOUND_CTL_SUBSEQ_BOUND_EN_Pos 28UL
#define SMIF_DEVICE_RD_BOUND_CTL_SUBSEQ_BOUND_EN_Msk 0x10000000UL
#define SMIF_DEVICE_RD_BOUND_CTL_PRESENT_Pos    31UL
#define SMIF_DEVICE_RD_BOUND_CTL_PRESENT_Msk    0x80000000UL
/* SMIF_DEVICE.WR_CMD_CTL */
#define SMIF_DEVICE_WR_CMD_CTL_CODE_Pos         0UL
#define SMIF_DEVICE_WR_CMD_CTL_CODE_Msk         0xFFUL
#define SMIF_DEVICE_WR_CMD_CTL_CODEH_Pos        8UL
#define SMIF_DEVICE_WR_CMD_CTL_CODEH_Msk        0xFF00UL
#define SMIF_DEVICE_WR_CMD_CTL_WIDTH_Pos        16UL
#define SMIF_DEVICE_WR_CMD_CTL_WIDTH_Msk        0x30000UL
#define SMIF_DEVICE_WR_CMD_CTL_DDR_MODE_Pos     18UL
#define SMIF_DEVICE_WR_CMD_CTL_DDR_MODE_Msk     0x40000UL
#define SMIF_DEVICE_WR_CMD_CTL_PRESENT2_Pos     30UL
#define SMIF_DEVICE_WR_CMD_CTL_PRESENT2_Msk     0xC0000000UL
/* SMIF_DEVICE.WR_ADDR_CTL */
#define SMIF_DEVICE_WR_ADDR_CTL_WIDTH_Pos       16UL
#define SMIF_DEVICE_WR_ADDR_CTL_WIDTH_Msk       0x30000UL
#define SMIF_DEVICE_WR_ADDR_CTL_DDR_MODE_Pos    18UL
#define SMIF_DEVICE_WR_ADDR_CTL_DDR_MODE_Msk    0x40000UL
/* SMIF_DEVICE.WR_MODE_CTL */
#define SMIF_DEVICE_WR_MODE_CTL_CODE_Pos        0UL
#define SMIF_DEVICE_WR_MODE_CTL_CODE_Msk        0xFFUL
#define SMIF_DEVICE_WR_MODE_CTL_CODEH_Pos       8UL
#define SMIF_DEVICE_WR_MODE_CTL_CODEH_Msk       0xFF00UL
#define SMIF_DEVICE_WR_MODE_CTL_WIDTH_Pos       16UL
#define SMIF_DEVICE_WR_MODE_CTL_WIDTH_Msk       0x30000UL
#define SMIF_DEVICE_WR_MODE_CTL_DDR_MODE_Pos    18UL
#define SMIF_DEVICE_WR_MODE_CTL_DDR_MODE_Msk    0x40000UL
#define SMIF_DEVICE_WR_MODE_CTL_PRESENT2_Pos    30UL
#define SMIF_DEVICE_WR_MODE_CTL_PRESENT2_Msk    0xC0000000UL
/* SMIF_DEVICE.WR_DUMMY_CTL */
#define SMIF_DEVICE_WR_DUMMY_CTL_SIZE5_Pos      0UL
#define SMIF_DEVICE_WR_DUMMY_CTL_SIZE5_Msk      0x1FUL
#define SMIF_DEVICE_WR_DUMMY_CTL_RWDS_EN_Pos    17UL
#define SMIF_DEVICE_WR_DUMMY_CTL_RWDS_EN_Msk    0x20000UL
#define SMIF_DEVICE_WR_DUMMY_CTL_PRESENT2_Pos   30UL
#define SMIF_DEVICE_WR_DUMMY_CTL_PRESENT2_Msk   0xC0000000UL
/* SMIF_DEVICE.WR_DATA_CTL */
#define SMIF_DEVICE_WR_DATA_CTL_WIDTH_Pos       16UL
#define SMIF_DEVICE_WR_DATA_CTL_WIDTH_Msk       0x30000UL
#define SMIF_DEVICE_WR_DATA_CTL_DDR_MODE_Pos    18UL
#define SMIF_DEVICE_WR_DATA_CTL_DDR_MODE_Msk    0x40000UL
/* SMIF_DEVICE.WR_CRC_CTL */
#define SMIF_DEVICE_WR_CRC_CTL_DATA_CRC_INPUT_SIZE_Pos 16UL
#define SMIF_DEVICE_WR_CRC_CTL_DATA_CRC_INPUT_SIZE_Msk 0xFF0000UL
#define SMIF_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_WIDTH_Pos 24UL
#define SMIF_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_WIDTH_Msk 0x3000000UL
#define SMIF_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_DDR_MODE_Pos 26UL
#define SMIF_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_DDR_MODE_Msk 0x4000000UL
#define SMIF_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_INPUT_Pos 27UL
#define SMIF_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_INPUT_Msk 0x8000000UL
#define SMIF_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_PRESENT_Pos 30UL
#define SMIF_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_PRESENT_Msk 0x40000000UL
#define SMIF_DEVICE_WR_CRC_CTL_DATA_CRC_PRESENT_Pos 31UL
#define SMIF_DEVICE_WR_CRC_CTL_DATA_CRC_PRESENT_Msk 0x80000000UL


/* SMIF_MPC.CFG */
#define SMIF_MPC_CFG_RESPONSE_Pos               4UL
#define SMIF_MPC_CFG_RESPONSE_Msk               0x10UL
/* SMIF_MPC.INTR */
#define SMIF_MPC_INTR_VIOLATION_Pos             0UL
#define SMIF_MPC_INTR_VIOLATION_Msk             0x1UL
/* SMIF_MPC.INTR_SET */
#define SMIF_MPC_INTR_SET_VIOLATION_Pos         0UL
#define SMIF_MPC_INTR_SET_VIOLATION_Msk         0x1UL
/* SMIF_MPC.INTR_MASK */
#define SMIF_MPC_INTR_MASK_VIOLATION_Pos        0UL
#define SMIF_MPC_INTR_MASK_VIOLATION_Msk        0x1UL
/* SMIF_MPC.INTR_MASKED */
#define SMIF_MPC_INTR_MASKED_VIOLATION_Pos      0UL
#define SMIF_MPC_INTR_MASKED_VIOLATION_Msk      0x1UL
/* SMIF_MPC.INTR_INFO1 */
#define SMIF_MPC_INTR_INFO1_VALUE_Pos           0UL
#define SMIF_MPC_INTR_INFO1_VALUE_Msk           0xFFFFFFFFUL
/* SMIF_MPC.INTR_INFO2 */
#define SMIF_MPC_INTR_INFO2_HMASTER_Pos         0UL
#define SMIF_MPC_INTR_INFO2_HMASTER_Msk         0xFFFFUL
#define SMIF_MPC_INTR_INFO2_HNONSEC_Pos         16UL
#define SMIF_MPC_INTR_INFO2_HNONSEC_Msk         0x10000UL
#define SMIF_MPC_INTR_INFO2_CFG_NS_Pos          17UL
#define SMIF_MPC_INTR_INFO2_CFG_NS_Msk          0x20000UL
#define SMIF_MPC_INTR_INFO2_HWRITE_Pos          18UL
#define SMIF_MPC_INTR_INFO2_HWRITE_Msk          0x40000UL
#define SMIF_MPC_INTR_INFO2_HAUSER_Pos          24UL
#define SMIF_MPC_INTR_INFO2_HAUSER_Msk          0xF000000UL
#define SMIF_MPC_INTR_INFO2_SECURITY_VIOLATION_Pos 30UL
#define SMIF_MPC_INTR_INFO2_SECURITY_VIOLATION_Msk 0x40000000UL
#define SMIF_MPC_INTR_INFO2_ACCESS_VIOLATION_Pos 31UL
#define SMIF_MPC_INTR_INFO2_ACCESS_VIOLATION_Msk 0x80000000UL
/* SMIF_MPC.CTRL */
#define SMIF_MPC_CTRL_AUTO_INC_Pos              8UL
#define SMIF_MPC_CTRL_AUTO_INC_Msk              0x100UL
#define SMIF_MPC_CTRL_LOCK_Pos                  31UL
#define SMIF_MPC_CTRL_LOCK_Msk                  0x80000000UL
/* SMIF_MPC.BLK_MAX */
#define SMIF_MPC_BLK_MAX_VALUE_Pos              0UL
#define SMIF_MPC_BLK_MAX_VALUE_Msk              0xFFFFFFFFUL
/* SMIF_MPC.BLK_CFG */
#define SMIF_MPC_BLK_CFG_BLOCK_SIZE_Pos         0UL
#define SMIF_MPC_BLK_CFG_BLOCK_SIZE_Msk         0xFUL
#define SMIF_MPC_BLK_CFG_INIT_IN_PROGRESS_Pos   31UL
#define SMIF_MPC_BLK_CFG_INIT_IN_PROGRESS_Msk   0x80000000UL
/* SMIF_MPC.BLK_IDX */
#define SMIF_MPC_BLK_IDX_VALUE_Pos              0UL
#define SMIF_MPC_BLK_IDX_VALUE_Msk              0xFFFFFFFFUL
/* SMIF_MPC.BLK_LUT */
#define SMIF_MPC_BLK_LUT_ATTR_NS0_Pos           0UL
#define SMIF_MPC_BLK_LUT_ATTR_NS0_Msk           0x1UL
#define SMIF_MPC_BLK_LUT_ATTR_NS1_Pos           1UL
#define SMIF_MPC_BLK_LUT_ATTR_NS1_Msk           0x2UL
#define SMIF_MPC_BLK_LUT_ATTR_NS2_Pos           2UL
#define SMIF_MPC_BLK_LUT_ATTR_NS2_Msk           0x4UL
#define SMIF_MPC_BLK_LUT_ATTR_NS3_Pos           3UL
#define SMIF_MPC_BLK_LUT_ATTR_NS3_Msk           0x8UL
#define SMIF_MPC_BLK_LUT_ATTR_NS4_Pos           4UL
#define SMIF_MPC_BLK_LUT_ATTR_NS4_Msk           0x10UL
#define SMIF_MPC_BLK_LUT_ATTR_NS5_Pos           5UL
#define SMIF_MPC_BLK_LUT_ATTR_NS5_Msk           0x20UL
#define SMIF_MPC_BLK_LUT_ATTR_NS6_Pos           6UL
#define SMIF_MPC_BLK_LUT_ATTR_NS6_Msk           0x40UL
#define SMIF_MPC_BLK_LUT_ATTR_NS7_Pos           7UL
#define SMIF_MPC_BLK_LUT_ATTR_NS7_Msk           0x80UL
#define SMIF_MPC_BLK_LUT_ATTR_NS8_Pos           8UL
#define SMIF_MPC_BLK_LUT_ATTR_NS8_Msk           0x100UL
#define SMIF_MPC_BLK_LUT_ATTR_NS9_Pos           9UL
#define SMIF_MPC_BLK_LUT_ATTR_NS9_Msk           0x200UL
#define SMIF_MPC_BLK_LUT_ATTR_NS10_Pos          10UL
#define SMIF_MPC_BLK_LUT_ATTR_NS10_Msk          0x400UL
#define SMIF_MPC_BLK_LUT_ATTR_NS11_Pos          11UL
#define SMIF_MPC_BLK_LUT_ATTR_NS11_Msk          0x800UL
#define SMIF_MPC_BLK_LUT_ATTR_NS12_Pos          12UL
#define SMIF_MPC_BLK_LUT_ATTR_NS12_Msk          0x1000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS13_Pos          13UL
#define SMIF_MPC_BLK_LUT_ATTR_NS13_Msk          0x2000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS14_Pos          14UL
#define SMIF_MPC_BLK_LUT_ATTR_NS14_Msk          0x4000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS15_Pos          15UL
#define SMIF_MPC_BLK_LUT_ATTR_NS15_Msk          0x8000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS16_Pos          16UL
#define SMIF_MPC_BLK_LUT_ATTR_NS16_Msk          0x10000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS17_Pos          17UL
#define SMIF_MPC_BLK_LUT_ATTR_NS17_Msk          0x20000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS18_Pos          18UL
#define SMIF_MPC_BLK_LUT_ATTR_NS18_Msk          0x40000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS19_Pos          19UL
#define SMIF_MPC_BLK_LUT_ATTR_NS19_Msk          0x80000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS20_Pos          20UL
#define SMIF_MPC_BLK_LUT_ATTR_NS20_Msk          0x100000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS21_Pos          21UL
#define SMIF_MPC_BLK_LUT_ATTR_NS21_Msk          0x200000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS22_Pos          22UL
#define SMIF_MPC_BLK_LUT_ATTR_NS22_Msk          0x400000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS23_Pos          23UL
#define SMIF_MPC_BLK_LUT_ATTR_NS23_Msk          0x800000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS24_Pos          24UL
#define SMIF_MPC_BLK_LUT_ATTR_NS24_Msk          0x1000000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS25_Pos          25UL
#define SMIF_MPC_BLK_LUT_ATTR_NS25_Msk          0x2000000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS26_Pos          26UL
#define SMIF_MPC_BLK_LUT_ATTR_NS26_Msk          0x4000000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS27_Pos          27UL
#define SMIF_MPC_BLK_LUT_ATTR_NS27_Msk          0x8000000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS28_Pos          28UL
#define SMIF_MPC_BLK_LUT_ATTR_NS28_Msk          0x10000000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS29_Pos          29UL
#define SMIF_MPC_BLK_LUT_ATTR_NS29_Msk          0x20000000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS30_Pos          30UL
#define SMIF_MPC_BLK_LUT_ATTR_NS30_Msk          0x40000000UL
#define SMIF_MPC_BLK_LUT_ATTR_NS31_Pos          31UL
#define SMIF_MPC_BLK_LUT_ATTR_NS31_Msk          0x80000000UL
/* SMIF_MPC.ROT_CTRL */
#define SMIF_MPC_ROT_CTRL_AUTO_INC_Pos          8UL
#define SMIF_MPC_ROT_CTRL_AUTO_INC_Msk          0x100UL
#define SMIF_MPC_ROT_CTRL_LOCK_Pos              31UL
#define SMIF_MPC_ROT_CTRL_LOCK_Msk              0x80000000UL
/* SMIF_MPC.ROT_CFG */
#define SMIF_MPC_ROT_CFG_BLOCK_SIZE_Pos         0UL
#define SMIF_MPC_ROT_CFG_BLOCK_SIZE_Msk         0xFUL
/* SMIF_MPC.ROT_BLK_MAX */
#define SMIF_MPC_ROT_BLK_MAX_VALUE_Pos          0UL
#define SMIF_MPC_ROT_BLK_MAX_VALUE_Msk          0xFFFFFFFFUL
/* SMIF_MPC.ROT_BLK_CFG */
#define SMIF_MPC_ROT_BLK_CFG_BLOCK_SIZE_Pos     0UL
#define SMIF_MPC_ROT_BLK_CFG_BLOCK_SIZE_Msk     0xFUL
#define SMIF_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Pos 31UL
#define SMIF_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Msk 0x80000000UL
/* SMIF_MPC.ROT_BLK_IDX */
#define SMIF_MPC_ROT_BLK_IDX_VALUE_Pos          0UL
#define SMIF_MPC_ROT_BLK_IDX_VALUE_Msk          0xFFFFFFFFUL
/* SMIF_MPC.ROT_BLK_PC */
#define SMIF_MPC_ROT_BLK_PC_PC_Pos              0UL
#define SMIF_MPC_ROT_BLK_PC_PC_Msk              0xFUL
/* SMIF_MPC.ROT_BLK_LUT */
#define SMIF_MPC_ROT_BLK_LUT_ATTR0_Pos          0UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR0_Msk          0x7UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR1_Pos          4UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR1_Msk          0x70UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR2_Pos          8UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR2_Msk          0x700UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR3_Pos          12UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR3_Msk          0x7000UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR4_Pos          16UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR4_Msk          0x70000UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR5_Pos          20UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR5_Msk          0x700000UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR6_Pos          24UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR6_Msk          0x7000000UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR7_Pos          28UL
#define SMIF_MPC_ROT_BLK_LUT_ATTR7_Msk          0x70000000UL


/* SMIF.CTL */
#define SMIF_CTL_XIP_MODE_Pos                   0UL
#define SMIF_CTL_XIP_MODE_Msk                   0x1UL
#define SMIF_CTL_CLOCK_IF_TX_SEL_Pos            4UL
#define SMIF_CTL_CLOCK_IF_TX_SEL_Msk            0x10UL
#define SMIF_CTL_DELAY_LINE_SEL_Pos             5UL
#define SMIF_CTL_DELAY_LINE_SEL_Msk             0xE0UL
#define SMIF_CTL_DELAY_TAP_ENABLED_Pos          8UL
#define SMIF_CTL_DELAY_TAP_ENABLED_Msk          0x100UL
#define SMIF_CTL_INT_CLOCK_DL_ENABLED_Pos       9UL
#define SMIF_CTL_INT_CLOCK_DL_ENABLED_Msk       0x200UL
#define SMIF_CTL_INT_CLOCK_CAPTURE_CYCLE_Pos    10UL
#define SMIF_CTL_INT_CLOCK_CAPTURE_CYCLE_Msk    0xC00UL
#define SMIF_CTL_CLOCK_IF_RX_SEL_Pos            12UL
#define SMIF_CTL_CLOCK_IF_RX_SEL_Msk            0x7000UL
#define SMIF_CTL_DESELECT_DELAY_Pos             16UL
#define SMIF_CTL_DESELECT_DELAY_Msk             0x70000UL
#define SMIF_CTL_SELECT_SETUP_DELAY_Pos         20UL
#define SMIF_CTL_SELECT_SETUP_DELAY_Msk         0x300000UL
#define SMIF_CTL_SELECT_HOLD_DELAY_Pos          22UL
#define SMIF_CTL_SELECT_HOLD_DELAY_Msk          0xC00000UL
#define SMIF_CTL_BLOCK_Pos                      24UL
#define SMIF_CTL_BLOCK_Msk                      0x1000000UL
#define SMIF_CTL_CLOCK_IF_SEL_Pos               25UL
#define SMIF_CTL_CLOCK_IF_SEL_Msk               0x2000000UL
#define SMIF_CTL_ENABLED_Pos                    31UL
#define SMIF_CTL_ENABLED_Msk                    0x80000000UL
/* SMIF.STATUS */
#define SMIF_STATUS_BUSY_Pos                    31UL
#define SMIF_STATUS_BUSY_Msk                    0x80000000UL
/* SMIF.INT_CLOCK_DELAY_TAP_SEL0 */
#define SMIF_INT_CLOCK_DELAY_TAP_SEL0_DATA_BIT0_Pos 0UL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL0_DATA_BIT0_Msk 0xFFUL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL0_DATA_BIT1_Pos 8UL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL0_DATA_BIT1_Msk 0xFF00UL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL0_DATA_BIT2_Pos 16UL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL0_DATA_BIT2_Msk 0xFF0000UL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL0_DATA_BIT3_Pos 24UL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL0_DATA_BIT3_Msk 0xFF000000UL
/* SMIF.INT_CLOCK_DELAY_TAP_SEL1 */
#define SMIF_INT_CLOCK_DELAY_TAP_SEL1_DATA_BIT4_Pos 0UL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL1_DATA_BIT4_Msk 0xFFUL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL1_DATA_BIT5_Pos 8UL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL1_DATA_BIT5_Msk 0xFF00UL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL1_DATA_BIT6_Pos 16UL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL1_DATA_BIT6_Msk 0xFF0000UL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL1_DATA_BIT7_Pos 24UL
#define SMIF_INT_CLOCK_DELAY_TAP_SEL1_DATA_BIT7_Msk 0xFF000000UL
/* SMIF.DL_CTL */
#define SMIF_DL_CTL_DLP_Pos                     0UL
#define SMIF_DL_CTL_DLP_Msk                     0xFFFFUL
#define SMIF_DL_CTL_DLP_SIZE_Pos                16UL
#define SMIF_DL_CTL_DLP_SIZE_Msk                0xF0000UL
#define SMIF_DL_CTL_DL_WARNING_LEVEL_Pos        24UL
#define SMIF_DL_CTL_DL_WARNING_LEVEL_Msk        0xF000000UL
/* SMIF.DL_STATUS0 */
#define SMIF_DL_STATUS0_DATA_BIT0_Pos           0UL
#define SMIF_DL_STATUS0_DATA_BIT0_Msk           0xFFUL
#define SMIF_DL_STATUS0_DATA_BIT1_Pos           8UL
#define SMIF_DL_STATUS0_DATA_BIT1_Msk           0xFF00UL
#define SMIF_DL_STATUS0_DATA_BIT2_Pos           16UL
#define SMIF_DL_STATUS0_DATA_BIT2_Msk           0xFF0000UL
#define SMIF_DL_STATUS0_DATA_BIT3_Pos           24UL
#define SMIF_DL_STATUS0_DATA_BIT3_Msk           0xFF000000UL
/* SMIF.DL_STATUS1 */
#define SMIF_DL_STATUS1_DATA_BIT4_Pos           0UL
#define SMIF_DL_STATUS1_DATA_BIT4_Msk           0xFFUL
#define SMIF_DL_STATUS1_DATA_BIT5_Pos           8UL
#define SMIF_DL_STATUS1_DATA_BIT5_Msk           0xFF00UL
#define SMIF_DL_STATUS1_DATA_BIT6_Pos           16UL
#define SMIF_DL_STATUS1_DATA_BIT6_Msk           0xFF0000UL
#define SMIF_DL_STATUS1_DATA_BIT7_Pos           24UL
#define SMIF_DL_STATUS1_DATA_BIT7_Msk           0xFF000000UL
/* SMIF.TX_CMD_FIFO_STATUS */
#define SMIF_TX_CMD_FIFO_STATUS_USED4_Pos       0UL
#define SMIF_TX_CMD_FIFO_STATUS_USED4_Msk       0xFUL
/* SMIF.TX_CMD_MMIO_FIFO_STATUS */
#define SMIF_TX_CMD_MMIO_FIFO_STATUS_USED4_Pos  0UL
#define SMIF_TX_CMD_MMIO_FIFO_STATUS_USED4_Msk  0xFUL
/* SMIF.TX_CMD_MMIO_FIFO_WR */
#define SMIF_TX_CMD_MMIO_FIFO_WR_DATA27_Pos     0UL
#define SMIF_TX_CMD_MMIO_FIFO_WR_DATA27_Msk     0x7FFFFFFUL
/* SMIF.TX_DATA_MMIO_FIFO_CTL */
#define SMIF_TX_DATA_MMIO_FIFO_CTL_TX_TRIGGER_LEVEL_Pos 0UL
#define SMIF_TX_DATA_MMIO_FIFO_CTL_TX_TRIGGER_LEVEL_Msk 0x7UL
/* SMIF.TX_DATA_FIFO_STATUS */
#define SMIF_TX_DATA_FIFO_STATUS_USED4_Pos      0UL
#define SMIF_TX_DATA_FIFO_STATUS_USED4_Msk      0xFUL
/* SMIF.TX_DATA_MMIO_FIFO_STATUS */
#define SMIF_TX_DATA_MMIO_FIFO_STATUS_USED4_Pos 0UL
#define SMIF_TX_DATA_MMIO_FIFO_STATUS_USED4_Msk 0xFUL
/* SMIF.TX_DATA_MMIO_FIFO_WR1 */
#define SMIF_TX_DATA_MMIO_FIFO_WR1_DATA0_Pos    0UL
#define SMIF_TX_DATA_MMIO_FIFO_WR1_DATA0_Msk    0xFFUL
/* SMIF.TX_DATA_MMIO_FIFO_WR2 */
#define SMIF_TX_DATA_MMIO_FIFO_WR2_DATA0_Pos    0UL
#define SMIF_TX_DATA_MMIO_FIFO_WR2_DATA0_Msk    0xFFUL
#define SMIF_TX_DATA_MMIO_FIFO_WR2_DATA1_Pos    8UL
#define SMIF_TX_DATA_MMIO_FIFO_WR2_DATA1_Msk    0xFF00UL
/* SMIF.TX_DATA_MMIO_FIFO_WR4 */
#define SMIF_TX_DATA_MMIO_FIFO_WR4_DATA0_Pos    0UL
#define SMIF_TX_DATA_MMIO_FIFO_WR4_DATA0_Msk    0xFFUL
#define SMIF_TX_DATA_MMIO_FIFO_WR4_DATA1_Pos    8UL
#define SMIF_TX_DATA_MMIO_FIFO_WR4_DATA1_Msk    0xFF00UL
#define SMIF_TX_DATA_MMIO_FIFO_WR4_DATA2_Pos    16UL
#define SMIF_TX_DATA_MMIO_FIFO_WR4_DATA2_Msk    0xFF0000UL
#define SMIF_TX_DATA_MMIO_FIFO_WR4_DATA3_Pos    24UL
#define SMIF_TX_DATA_MMIO_FIFO_WR4_DATA3_Msk    0xFF000000UL
/* SMIF.TX_DATA_MMIO_FIFO_WR1ODD */
#define SMIF_TX_DATA_MMIO_FIFO_WR1ODD_DATA0_Pos 0UL
#define SMIF_TX_DATA_MMIO_FIFO_WR1ODD_DATA0_Msk 0xFFUL
/* SMIF.RX_DATA_MMIO_FIFO_CTL */
#define SMIF_RX_DATA_MMIO_FIFO_CTL_RX_TRIGGER_LEVEL_Pos 0UL
#define SMIF_RX_DATA_MMIO_FIFO_CTL_RX_TRIGGER_LEVEL_Msk 0x7UL
/* SMIF.RX_DATA_MMIO_FIFO_STATUS */
#define SMIF_RX_DATA_MMIO_FIFO_STATUS_USED4_Pos 0UL
#define SMIF_RX_DATA_MMIO_FIFO_STATUS_USED4_Msk 0xFUL
/* SMIF.RX_DATA_FIFO_STATUS */
#define SMIF_RX_DATA_FIFO_STATUS_USED4_Pos      0UL
#define SMIF_RX_DATA_FIFO_STATUS_USED4_Msk      0xFUL
#define SMIF_RX_DATA_FIFO_STATUS_RX_SR_USED_Pos 8UL
#define SMIF_RX_DATA_FIFO_STATUS_RX_SR_USED_Msk 0x100UL
/* SMIF.RX_DATA_MMIO_FIFO_RD1 */
#define SMIF_RX_DATA_MMIO_FIFO_RD1_DATA0_Pos    0UL
#define SMIF_RX_DATA_MMIO_FIFO_RD1_DATA0_Msk    0xFFUL
/* SMIF.RX_DATA_MMIO_FIFO_RD2 */
#define SMIF_RX_DATA_MMIO_FIFO_RD2_DATA0_Pos    0UL
#define SMIF_RX_DATA_MMIO_FIFO_RD2_DATA0_Msk    0xFFUL
#define SMIF_RX_DATA_MMIO_FIFO_RD2_DATA1_Pos    8UL
#define SMIF_RX_DATA_MMIO_FIFO_RD2_DATA1_Msk    0xFF00UL
/* SMIF.RX_DATA_MMIO_FIFO_RD4 */
#define SMIF_RX_DATA_MMIO_FIFO_RD4_DATA0_Pos    0UL
#define SMIF_RX_DATA_MMIO_FIFO_RD4_DATA0_Msk    0xFFUL
#define SMIF_RX_DATA_MMIO_FIFO_RD4_DATA1_Pos    8UL
#define SMIF_RX_DATA_MMIO_FIFO_RD4_DATA1_Msk    0xFF00UL
#define SMIF_RX_DATA_MMIO_FIFO_RD4_DATA2_Pos    16UL
#define SMIF_RX_DATA_MMIO_FIFO_RD4_DATA2_Msk    0xFF0000UL
#define SMIF_RX_DATA_MMIO_FIFO_RD4_DATA3_Pos    24UL
#define SMIF_RX_DATA_MMIO_FIFO_RD4_DATA3_Msk    0xFF000000UL
/* SMIF.RX_DATA_MMIO_FIFO_RD1_SILENT */
#define SMIF_RX_DATA_MMIO_FIFO_RD1_SILENT_DATA0_Pos 0UL
#define SMIF_RX_DATA_MMIO_FIFO_RD1_SILENT_DATA0_Msk 0xFFUL
/* SMIF.SLOW_CA_CTL */
#define SMIF_SLOW_CA_CTL_WAY_Pos                16UL
#define SMIF_SLOW_CA_CTL_WAY_Msk                0x30000UL
#define SMIF_SLOW_CA_CTL_SET_ADDR_Pos           24UL
#define SMIF_SLOW_CA_CTL_SET_ADDR_Msk           0x3000000UL
#define SMIF_SLOW_CA_CTL_PREF_EN_Pos            30UL
#define SMIF_SLOW_CA_CTL_PREF_EN_Msk            0x40000000UL
#define SMIF_SLOW_CA_CTL_ENABLED_Pos            31UL
#define SMIF_SLOW_CA_CTL_ENABLED_Msk            0x80000000UL
/* SMIF.SLOW_CA_CMD */
#define SMIF_SLOW_CA_CMD_INV_Pos                0UL
#define SMIF_SLOW_CA_CMD_INV_Msk                0x1UL
/* SMIF.FAST_CA_CTL */
#define SMIF_FAST_CA_CTL_WAY_Pos                16UL
#define SMIF_FAST_CA_CTL_WAY_Msk                0x30000UL
#define SMIF_FAST_CA_CTL_SET_ADDR_Pos           24UL
#define SMIF_FAST_CA_CTL_SET_ADDR_Msk           0x3000000UL
#define SMIF_FAST_CA_CTL_PREF_EN_Pos            30UL
#define SMIF_FAST_CA_CTL_PREF_EN_Msk            0x40000000UL
#define SMIF_FAST_CA_CTL_ENABLED_Pos            31UL
#define SMIF_FAST_CA_CTL_ENABLED_Msk            0x80000000UL
/* SMIF.FAST_CA_CMD */
#define SMIF_FAST_CA_CMD_INV_Pos                0UL
#define SMIF_FAST_CA_CMD_INV_Msk                0x1UL
/* SMIF.CRC_CMD */
#define SMIF_CRC_CMD_START_Pos                  0UL
#define SMIF_CRC_CMD_START_Msk                  0x1UL
#define SMIF_CRC_CMD_CONTINUE_Pos               1UL
#define SMIF_CRC_CMD_CONTINUE_Msk               0x2UL
/* SMIF.CRC_INPUT0 */
#define SMIF_CRC_INPUT0_INPUT_Pos               0UL
#define SMIF_CRC_INPUT0_INPUT_Msk               0xFFFFFFFFUL
/* SMIF.CRC_INPUT1 */
#define SMIF_CRC_INPUT1_INPUT_Pos               0UL
#define SMIF_CRC_INPUT1_INPUT_Msk               0xFFFFFFFFUL
/* SMIF.CRC_OUTPUT */
#define SMIF_CRC_OUTPUT_CRC_OUTPUT_Pos          0UL
#define SMIF_CRC_OUTPUT_CRC_OUTPUT_Msk          0xFFUL
/* SMIF.INTR */
#define SMIF_INTR_TR_TX_REQ_Pos                 0UL
#define SMIF_INTR_TR_TX_REQ_Msk                 0x1UL
#define SMIF_INTR_TR_RX_REQ_Pos                 1UL
#define SMIF_INTR_TR_RX_REQ_Msk                 0x2UL
#define SMIF_INTR_XIP_ALIGNMENT_ERROR_Pos       2UL
#define SMIF_INTR_XIP_ALIGNMENT_ERROR_Msk       0x4UL
#define SMIF_INTR_TX_CMD_FIFO_OVERFLOW_Pos      3UL
#define SMIF_INTR_TX_CMD_FIFO_OVERFLOW_Msk      0x8UL
#define SMIF_INTR_TX_DATA_FIFO_OVERFLOW_Pos     4UL
#define SMIF_INTR_TX_DATA_FIFO_OVERFLOW_Msk     0x10UL
#define SMIF_INTR_RX_DATA_MMIO_FIFO_UNDERFLOW_Pos 5UL
#define SMIF_INTR_RX_DATA_MMIO_FIFO_UNDERFLOW_Msk 0x20UL
#define SMIF_INTR_DL_FAIL_Pos                   8UL
#define SMIF_INTR_DL_FAIL_Msk                   0x100UL
#define SMIF_INTR_DL_WARNING_Pos                12UL
#define SMIF_INTR_DL_WARNING_Msk                0x1000UL
#define SMIF_INTR_CRC_ERROR_Pos                 16UL
#define SMIF_INTR_CRC_ERROR_Msk                 0x10000UL
#define SMIF_INTR_FS_STATUS_ERROR_Pos           17UL
#define SMIF_INTR_FS_STATUS_ERROR_Msk           0x20000UL
/* SMIF.INTR_SET */
#define SMIF_INTR_SET_TR_TX_REQ_Pos             0UL
#define SMIF_INTR_SET_TR_TX_REQ_Msk             0x1UL
#define SMIF_INTR_SET_TR_RX_REQ_Pos             1UL
#define SMIF_INTR_SET_TR_RX_REQ_Msk             0x2UL
#define SMIF_INTR_SET_XIP_ALIGNMENT_ERROR_Pos   2UL
#define SMIF_INTR_SET_XIP_ALIGNMENT_ERROR_Msk   0x4UL
#define SMIF_INTR_SET_TX_CMD_FIFO_OVERFLOW_Pos  3UL
#define SMIF_INTR_SET_TX_CMD_FIFO_OVERFLOW_Msk  0x8UL
#define SMIF_INTR_SET_TX_DATA_FIFO_OVERFLOW_Pos 4UL
#define SMIF_INTR_SET_TX_DATA_FIFO_OVERFLOW_Msk 0x10UL
#define SMIF_INTR_SET_RX_DATA_MMIO_FIFO_UNDERFLOW_Pos 5UL
#define SMIF_INTR_SET_RX_DATA_MMIO_FIFO_UNDERFLOW_Msk 0x20UL
#define SMIF_INTR_SET_DL_FAIL_Pos               8UL
#define SMIF_INTR_SET_DL_FAIL_Msk               0x100UL
#define SMIF_INTR_SET_DL_WARNING_Pos            12UL
#define SMIF_INTR_SET_DL_WARNING_Msk            0x1000UL
#define SMIF_INTR_SET_CRC_ERROR_Pos             16UL
#define SMIF_INTR_SET_CRC_ERROR_Msk             0x10000UL
#define SMIF_INTR_SET_FS_STATUS_ERROR_Pos       17UL
#define SMIF_INTR_SET_FS_STATUS_ERROR_Msk       0x20000UL
/* SMIF.INTR_MASK */
#define SMIF_INTR_MASK_TR_TX_REQ_Pos            0UL
#define SMIF_INTR_MASK_TR_TX_REQ_Msk            0x1UL
#define SMIF_INTR_MASK_TR_RX_REQ_Pos            1UL
#define SMIF_INTR_MASK_TR_RX_REQ_Msk            0x2UL
#define SMIF_INTR_MASK_XIP_ALIGNMENT_ERROR_Pos  2UL
#define SMIF_INTR_MASK_XIP_ALIGNMENT_ERROR_Msk  0x4UL
#define SMIF_INTR_MASK_TX_CMD_FIFO_OVERFLOW_Pos 3UL
#define SMIF_INTR_MASK_TX_CMD_FIFO_OVERFLOW_Msk 0x8UL
#define SMIF_INTR_MASK_TX_DATA_FIFO_OVERFLOW_Pos 4UL
#define SMIF_INTR_MASK_TX_DATA_FIFO_OVERFLOW_Msk 0x10UL
#define SMIF_INTR_MASK_RX_DATA_MMIO_FIFO_UNDERFLOW_Pos 5UL
#define SMIF_INTR_MASK_RX_DATA_MMIO_FIFO_UNDERFLOW_Msk 0x20UL
#define SMIF_INTR_MASK_DL_FAIL_Pos              8UL
#define SMIF_INTR_MASK_DL_FAIL_Msk              0x100UL
#define SMIF_INTR_MASK_DL_WARNING_Pos           12UL
#define SMIF_INTR_MASK_DL_WARNING_Msk           0x1000UL
#define SMIF_INTR_MASK_CRC_ERROR_Pos            16UL
#define SMIF_INTR_MASK_CRC_ERROR_Msk            0x10000UL
#define SMIF_INTR_MASK_FS_STATUS_ERROR_Pos      17UL
#define SMIF_INTR_MASK_FS_STATUS_ERROR_Msk      0x20000UL
/* SMIF.INTR_MASKED */
#define SMIF_INTR_MASKED_TR_TX_REQ_Pos          0UL
#define SMIF_INTR_MASKED_TR_TX_REQ_Msk          0x1UL
#define SMIF_INTR_MASKED_TR_RX_REQ_Pos          1UL
#define SMIF_INTR_MASKED_TR_RX_REQ_Msk          0x2UL
#define SMIF_INTR_MASKED_XIP_ALIGNMENT_ERROR_Pos 2UL
#define SMIF_INTR_MASKED_XIP_ALIGNMENT_ERROR_Msk 0x4UL
#define SMIF_INTR_MASKED_TX_CMD_FIFO_OVERFLOW_Pos 3UL
#define SMIF_INTR_MASKED_TX_CMD_FIFO_OVERFLOW_Msk 0x8UL
#define SMIF_INTR_MASKED_TX_DATA_FIFO_OVERFLOW_Pos 4UL
#define SMIF_INTR_MASKED_TX_DATA_FIFO_OVERFLOW_Msk 0x10UL
#define SMIF_INTR_MASKED_RX_DATA_MMIO_FIFO_UNDERFLOW_Pos 5UL
#define SMIF_INTR_MASKED_RX_DATA_MMIO_FIFO_UNDERFLOW_Msk 0x20UL
#define SMIF_INTR_MASKED_DL_FAIL_Pos            8UL
#define SMIF_INTR_MASKED_DL_FAIL_Msk            0x100UL
#define SMIF_INTR_MASKED_DL_WARNING_Pos         12UL
#define SMIF_INTR_MASKED_DL_WARNING_Msk         0x1000UL
#define SMIF_INTR_MASKED_CRC_ERROR_Pos          16UL
#define SMIF_INTR_MASKED_CRC_ERROR_Msk          0x10000UL
#define SMIF_INTR_MASKED_FS_STATUS_ERROR_Pos    17UL
#define SMIF_INTR_MASKED_FS_STATUS_ERROR_Msk    0x20000UL
/* SMIF.INTR_CAUSE */
#define SMIF_INTR_CAUSE_NORMAL_Pos              0UL
#define SMIF_INTR_CAUSE_NORMAL_Msk              0x1UL
#define SMIF_INTR_CAUSE_MPC_Pos                 1UL
#define SMIF_INTR_CAUSE_MPC_Msk                 0x2UL


#endif /* _CYIP_SMIF_V3_H_ */


/* [] END OF FILE */
