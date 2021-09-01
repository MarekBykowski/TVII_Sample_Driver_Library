/***************************************************************************//**
* \file cyip_axi_dmac.h
*
* \brief
* AXI_DMAC IP definitions
*
* \note
* Generator version: 1.6.0.453
* Database revision: TVIIC2D6M_B0CFR_MTO
*
********************************************************************************
* \copyright
* Copyright 2016-2021, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYIP_AXI_DMAC_H_
#define _CYIP_AXI_DMAC_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                   AXI_DMAC
*******************************************************************************/

#define AXI_DMAC_CH_SECTION_SIZE                0x00000100UL
#define AXI_DMAC_SECTION_SIZE                   0x00010000UL

/**
  * \brief Channel control (AXI_DMAC_CH_CTL)
  */
typedef struct stc_AXI_DMAC_CH_CTL_field {
  uint32_t                         u1P:1;
  uint32_t                         u1NS:1;
  uint32_t                         u1B:1;
  uint32_t                         :1;
  uint32_t                         u4PC:4;
  uint32_t                         u2PRIO:2;
  uint32_t                         :21;
  uint32_t                         u1ENABLED:1;
} stc_AXI_DMAC_CH_CTL_field_t;

typedef union un_AXI_DMAC_CH_CTL {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_CTL_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_CTL_t;

/**
  * \brief Channel status (AXI_DMAC_CH_STATUS)
  */
typedef struct stc_AXI_DMAC_CH_STATUS_field {
  uint32_t                         :31;
  uint32_t                         u1ENABLED:1;
} stc_AXI_DMAC_CH_STATUS_field_t;

typedef union un_AXI_DMAC_CH_STATUS {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_STATUS_field_t   stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_STATUS_t;

/**
  * \brief Channel current X and Y indices (AXI_DMAC_CH_IDX)
  */
typedef struct stc_AXI_DMAC_CH_IDX_field {
  uint32_t                         u16X:16;
  uint32_t                         u16Y:16;
} stc_AXI_DMAC_CH_IDX_field_t;

typedef union un_AXI_DMAC_CH_IDX {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_IDX_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_IDX_t;

/**
  * \brief Channel current source address (AXI_DMAC_CH_SRC)
  */
typedef struct stc_AXI_DMAC_CH_SRC_field {
  uint32_t                         u32ADDR:32;
} stc_AXI_DMAC_CH_SRC_field_t;

typedef union un_AXI_DMAC_CH_SRC {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_SRC_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_SRC_t;

/**
  * \brief Channel current destination address (AXI_DMAC_CH_DST)
  */
typedef struct stc_AXI_DMAC_CH_DST_field {
  uint32_t                         u32ADDR:32;
} stc_AXI_DMAC_CH_DST_field_t;

typedef union un_AXI_DMAC_CH_DST {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_DST_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_DST_t;

/**
  * \brief Channel current M index (AXI_DMAC_CH_M_IDX)
  */
typedef struct stc_AXI_DMAC_CH_M_IDX_field {
  uint32_t                         u24M:24;
  uint32_t                         :8;
} stc_AXI_DMAC_CH_M_IDX_field_t;

typedef union un_AXI_DMAC_CH_M_IDX {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_M_IDX_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_M_IDX_t;

/**
  * \brief Channel current descriptor pointer (AXI_DMAC_CH_CURR)
  */
typedef struct stc_AXI_DMAC_CH_CURR_field {
  uint32_t                         :3;
  uint32_t                         u29PTR:29;
} stc_AXI_DMAC_CH_CURR_field_t;

typedef union un_AXI_DMAC_CH_CURR {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_CURR_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_CURR_t;

/**
  * \brief Channel software trigger (AXI_DMAC_CH_TR_CMD)
  */
typedef struct stc_AXI_DMAC_CH_TR_CMD_field {
  uint32_t                         u1ACTIVATE:1;
  uint32_t                         :31;
} stc_AXI_DMAC_CH_TR_CMD_field_t;

typedef union un_AXI_DMAC_CH_TR_CMD {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_TR_CMD_field_t   stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_TR_CMD_t;

/**
  * \brief Channel descriptor status (AXI_DMAC_CH_DESCR_STATUS)
  */
typedef struct stc_AXI_DMAC_CH_DESCR_STATUS_field {
  uint32_t                         :31;
  uint32_t                         u1VALID:1;
} stc_AXI_DMAC_CH_DESCR_STATUS_field_t;

typedef union un_AXI_DMAC_CH_DESCR_STATUS {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_DESCR_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_DESCR_STATUS_t;

/**
  * \brief Channel descriptor control (AXI_DMAC_CH_DESCR_CTL)
  */
typedef struct stc_AXI_DMAC_CH_DESCR_CTL_field {
  uint32_t                         u2WAIT_FOR_DEACT:2;
  uint32_t                         u2INTR_TYPE:2;
  uint32_t                         u2TR_OUT_TYPE:2;
  uint32_t                         u2TR_IN_TYPE:2;
  uint32_t                         u1DATA_PREFETCH:1;
  uint32_t                         :15;
  uint32_t                         u1CH_DISABLE:1;
  uint32_t                         :3;
  uint32_t                         u2DESCR_TYPE:2;
  uint32_t                         :2;
} stc_AXI_DMAC_CH_DESCR_CTL_field_t;

typedef union un_AXI_DMAC_CH_DESCR_CTL {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_DESCR_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_DESCR_CTL_t;

/**
  * \brief Channel descriptor source (AXI_DMAC_CH_DESCR_SRC)
  */
typedef struct stc_AXI_DMAC_CH_DESCR_SRC_field {
  uint32_t                         u32ADDR:32;
} stc_AXI_DMAC_CH_DESCR_SRC_field_t;

typedef union un_AXI_DMAC_CH_DESCR_SRC {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_DESCR_SRC_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_DESCR_SRC_t;

/**
  * \brief Channel descriptor destination (AXI_DMAC_CH_DESCR_DST)
  */
typedef struct stc_AXI_DMAC_CH_DESCR_DST_field {
  uint32_t                         u32ADDR:32;
} stc_AXI_DMAC_CH_DESCR_DST_field_t;

typedef union un_AXI_DMAC_CH_DESCR_DST {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_DESCR_DST_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_DESCR_DST_t;

/**
  * \brief Channel descriptor M size (AXI_DMAC_CH_DESCR_M_SIZE)
  */
typedef struct stc_AXI_DMAC_CH_DESCR_M_SIZE_field {
  uint32_t                         u24M_COUNT:24;
  uint32_t                         :8;
} stc_AXI_DMAC_CH_DESCR_M_SIZE_field_t;

typedef union un_AXI_DMAC_CH_DESCR_M_SIZE {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_DESCR_M_SIZE_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_DESCR_M_SIZE_t;

/**
  * \brief Channel descriptor X size (AXI_DMAC_CH_DESCR_X_SIZE)
  */
typedef struct stc_AXI_DMAC_CH_DESCR_X_SIZE_field {
  uint32_t                         u16X_COUNT:16;
  uint32_t                         :16;
} stc_AXI_DMAC_CH_DESCR_X_SIZE_field_t;

typedef union un_AXI_DMAC_CH_DESCR_X_SIZE {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_DESCR_X_SIZE_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_DESCR_X_SIZE_t;

/**
  * \brief Channel descriptor X increment (AXI_DMAC_CH_DESCR_X_INCR)
  */
typedef struct stc_AXI_DMAC_CH_DESCR_X_INCR_field {
  uint32_t                         u16SRC_X:16;
  uint32_t                         u16DST_X:16;
} stc_AXI_DMAC_CH_DESCR_X_INCR_field_t;

typedef union un_AXI_DMAC_CH_DESCR_X_INCR {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_DESCR_X_INCR_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_DESCR_X_INCR_t;

/**
  * \brief Channel descriptor Y size (AXI_DMAC_CH_DESCR_Y_SIZE)
  */
typedef struct stc_AXI_DMAC_CH_DESCR_Y_SIZE_field {
  uint32_t                         u16Y_COUNT:16;
  uint32_t                         :16;
} stc_AXI_DMAC_CH_DESCR_Y_SIZE_field_t;

typedef union un_AXI_DMAC_CH_DESCR_Y_SIZE {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_DESCR_Y_SIZE_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_DESCR_Y_SIZE_t;

/**
  * \brief Channel descriptor Y increment (AXI_DMAC_CH_DESCR_Y_INCR)
  */
typedef struct stc_AXI_DMAC_CH_DESCR_Y_INCR_field {
  uint32_t                         u16SRC_Y:16;
  uint32_t                         u16DST_Y:16;
} stc_AXI_DMAC_CH_DESCR_Y_INCR_field_t;

typedef union un_AXI_DMAC_CH_DESCR_Y_INCR {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_DESCR_Y_INCR_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_DESCR_Y_INCR_t;

/**
  * \brief Channel descriptor next pointer (AXI_DMAC_CH_DESCR_NEXT)
  */
typedef struct stc_AXI_DMAC_CH_DESCR_NEXT_field {
  uint32_t                         :3;
  uint32_t                         u29PTR:29;
} stc_AXI_DMAC_CH_DESCR_NEXT_field_t;

typedef union un_AXI_DMAC_CH_DESCR_NEXT {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_DESCR_NEXT_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_DESCR_NEXT_t;

/**
  * \brief Interrupt (AXI_DMAC_CH_INTR)
  */
typedef struct stc_AXI_DMAC_CH_INTR_field {
  uint32_t                         u1COMPLETION:1;
  uint32_t                         u1SRC_BUS_ERROR:1;
  uint32_t                         u1DST_BUS_ERROR:1;
  uint32_t                         u1INVALID_DESCR_TYPE:1;
  uint32_t                         :1;
  uint32_t                         u1CURR_PTR_NULL:1;
  uint32_t                         u1ACTIVE_CH_DISABLED:1;
  uint32_t                         u1DESCR_BUS_ERROR:1;
  uint32_t                         :24;
} stc_AXI_DMAC_CH_INTR_field_t;

typedef union un_AXI_DMAC_CH_INTR {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_INTR_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_INTR_t;

/**
  * \brief Interrupt set (AXI_DMAC_CH_INTR_SET)
  */
typedef struct stc_AXI_DMAC_CH_INTR_SET_field {
  uint32_t                         u1COMPLETION:1;
  uint32_t                         u1SRC_BUS_ERROR:1;
  uint32_t                         u1DST_BUS_ERROR:1;
  uint32_t                         u1INVALID_DESCR_TYPE:1;
  uint32_t                         :1;
  uint32_t                         u1CURR_PTR_NULL:1;
  uint32_t                         u1ACTIVE_CH_DISABLED:1;
  uint32_t                         u1DESCR_BUS_ERROR:1;
  uint32_t                         :24;
} stc_AXI_DMAC_CH_INTR_SET_field_t;

typedef union un_AXI_DMAC_CH_INTR_SET {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_INTR_SET_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_INTR_SET_t;

/**
  * \brief Interrupt mask (AXI_DMAC_CH_INTR_MASK)
  */
typedef struct stc_AXI_DMAC_CH_INTR_MASK_field {
  uint32_t                         u1COMPLETION:1;
  uint32_t                         u1SRC_BUS_ERROR:1;
  uint32_t                         u1DST_BUS_ERROR:1;
  uint32_t                         u1INVALID_DESCR_TYPE:1;
  uint32_t                         :1;
  uint32_t                         u1CURR_PTR_NULL:1;
  uint32_t                         u1ACTIVE_CH_DISABLED:1;
  uint32_t                         u1DESCR_BUS_ERROR:1;
  uint32_t                         :24;
} stc_AXI_DMAC_CH_INTR_MASK_field_t;

typedef union un_AXI_DMAC_CH_INTR_MASK {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_INTR_MASK_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_INTR_MASK_t;

/**
  * \brief Interrupt masked (AXI_DMAC_CH_INTR_MASKED)
  */
typedef struct stc_AXI_DMAC_CH_INTR_MASKED_field {
  uint32_t                         u1COMPLETION:1;
  uint32_t                         u1SRC_BUS_ERROR:1;
  uint32_t                         u1DST_BUS_ERROR:1;
  uint32_t                         u1INVALID_DESCR_TYPE:1;
  uint32_t                         :1;
  uint32_t                         u1CURR_PTR_NULL:1;
  uint32_t                         u1ACTIVE_CH_DISABLED:1;
  uint32_t                         u1DESCR_BUS_ERROR:1;
  uint32_t                         :24;
} stc_AXI_DMAC_CH_INTR_MASKED_field_t;

typedef union un_AXI_DMAC_CH_INTR_MASKED {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CH_INTR_MASKED_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CH_INTR_MASKED_t;



/**
  * \brief Control (AXI_DMAC_CTL)
  */
typedef struct stc_AXI_DMAC_CTL_field {
  uint32_t                         :31;
  uint32_t                         u1ENABLED:1;
} stc_AXI_DMAC_CTL_field_t;

typedef union un_AXI_DMAC_CTL {
  uint32_t                         u32Register;
  stc_AXI_DMAC_CTL_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_CTL_t;

/**
  * \brief Enabled channels (AXI_DMAC_STATUS)
  */
typedef struct stc_AXI_DMAC_STATUS_field {
  uint32_t                         u8CH_EN:8;
  uint32_t                         :24;
} stc_AXI_DMAC_STATUS_field_t;

typedef union un_AXI_DMAC_STATUS {
  uint32_t                         u32Register;
  stc_AXI_DMAC_STATUS_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_STATUS_t;

/**
  * \brief Active secure channels (AXI_DMAC_ACTIVE_SEC)
  */
typedef struct stc_AXI_DMAC_ACTIVE_SEC_field {
  uint32_t                         u8ACTIVE:8;
  uint32_t                         :24;
} stc_AXI_DMAC_ACTIVE_SEC_field_t;

typedef union un_AXI_DMAC_ACTIVE_SEC {
  uint32_t                         u32Register;
  stc_AXI_DMAC_ACTIVE_SEC_field_t  stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_ACTIVE_SEC_t;

/**
  * \brief Active non-secure channels (AXI_DMAC_ACTIVE_NONSEC)
  */
typedef struct stc_AXI_DMAC_ACTIVE_NONSEC_field {
  uint32_t                         u8ACTIVE:8;
  uint32_t                         :24;
} stc_AXI_DMAC_ACTIVE_NONSEC_field_t;

typedef union un_AXI_DMAC_ACTIVE_NONSEC {
  uint32_t                         u32Register;
  stc_AXI_DMAC_ACTIVE_NONSEC_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_AXI_DMAC_ACTIVE_NONSEC_t;



/**
  * \brief AXI DMA controller channel (AXI_DMAC_CH)
  */
typedef struct stc_AXI_DMAC_CH {
  un_AXI_DMAC_CH_CTL_t             unCTL;              /*!< 0x00000000 Channel control */
  un_AXI_DMAC_CH_STATUS_t          unSTATUS;           /*!< 0x00000004 Channel status */
  uint32_t                         au32Reserved[2];
  un_AXI_DMAC_CH_IDX_t             unIDX;              /*!< 0x00000010 Channel current X and Y indices */
  un_AXI_DMAC_CH_SRC_t             unSRC;              /*!< 0x00000014 Channel current source address */
  un_AXI_DMAC_CH_DST_t             unDST;              /*!< 0x00000018 Channel current destination address */
  un_AXI_DMAC_CH_M_IDX_t           unM_IDX;            /*!< 0x0000001C Channel current M index */
  un_AXI_DMAC_CH_CURR_t            unCURR;             /*!< 0x00000020 Channel current descriptor pointer */
  uint32_t                         u32Reserved1;
  un_AXI_DMAC_CH_TR_CMD_t          unTR_CMD;           /*!< 0x00000028 Channel software trigger */
  uint32_t                         au32Reserved2[5];
  un_AXI_DMAC_CH_DESCR_STATUS_t    unDESCR_STATUS;     /*!< 0x00000040 Channel descriptor status */
  uint32_t                         au32Reserved3[3];
  un_AXI_DMAC_CH_DESCR_CTL_t       unDESCR_CTL;        /*!< 0x00000050 Channel descriptor control */
  un_AXI_DMAC_CH_DESCR_SRC_t       unDESCR_SRC;        /*!< 0x00000054 Channel descriptor source */
  un_AXI_DMAC_CH_DESCR_DST_t       unDESCR_DST;        /*!< 0x00000058 Channel descriptor destination */
  un_AXI_DMAC_CH_DESCR_M_SIZE_t    unDESCR_M_SIZE;     /*!< 0x0000005C Channel descriptor M size */
  un_AXI_DMAC_CH_DESCR_X_SIZE_t    unDESCR_X_SIZE;     /*!< 0x00000060 Channel descriptor X size */
  un_AXI_DMAC_CH_DESCR_X_INCR_t    unDESCR_X_INCR;     /*!< 0x00000064 Channel descriptor X increment */
  un_AXI_DMAC_CH_DESCR_Y_SIZE_t    unDESCR_Y_SIZE;     /*!< 0x00000068 Channel descriptor Y size */
  un_AXI_DMAC_CH_DESCR_Y_INCR_t    unDESCR_Y_INCR;     /*!< 0x0000006C Channel descriptor Y increment */
  un_AXI_DMAC_CH_DESCR_NEXT_t      unDESCR_NEXT;       /*!< 0x00000070 Channel descriptor next pointer */
  uint32_t                         au32Reserved4[3];
  un_AXI_DMAC_CH_INTR_t            unINTR;             /*!< 0x00000080 Interrupt */
  un_AXI_DMAC_CH_INTR_SET_t        unINTR_SET;         /*!< 0x00000084 Interrupt set */
  un_AXI_DMAC_CH_INTR_MASK_t       unINTR_MASK;        /*!< 0x00000088 Interrupt mask */
  un_AXI_DMAC_CH_INTR_MASKED_t     unINTR_MASKED;      /*!< 0x0000008C Interrupt masked */
  uint32_t                         au32Reserved5[28];
} stc_AXI_DMAC_CH_t;                                   /*!< Size = 256 (0x100) */

/**
  * \brief AXI DMAC (AXI_DMAC)
  */
typedef struct stc_AXI_DMAC {
  un_AXI_DMAC_CTL_t                unCTL;              /*!< 0x00000000 Control */
  un_AXI_DMAC_STATUS_t             unSTATUS;           /*!< 0x00000004 Enabled channels */
  un_AXI_DMAC_ACTIVE_SEC_t         unACTIVE_SEC;       /*!< 0x00000008 Active secure channels */
  un_AXI_DMAC_ACTIVE_NONSEC_t      unACTIVE_NONSEC;    /*!< 0x0000000C Active non-secure channels */
  uint32_t                         au32Reserved[1020];
  stc_AXI_DMAC_CH_t                CH[8];              /*!< 0x00001000 AXI DMA controller channel */
} stc_AXI_DMAC_t;                                      /*!< Size = 6144 (0x1800) */


/* AXI_DMAC_CH.CTL */
#define AXI_DMAC_CH_CTL_P_Pos                   0UL
#define AXI_DMAC_CH_CTL_P_Msk                   0x1UL
#define AXI_DMAC_CH_CTL_NS_Pos                  1UL
#define AXI_DMAC_CH_CTL_NS_Msk                  0x2UL
#define AXI_DMAC_CH_CTL_B_Pos                   2UL
#define AXI_DMAC_CH_CTL_B_Msk                   0x4UL
#define AXI_DMAC_CH_CTL_PC_Pos                  4UL
#define AXI_DMAC_CH_CTL_PC_Msk                  0xF0UL
#define AXI_DMAC_CH_CTL_PRIO_Pos                8UL
#define AXI_DMAC_CH_CTL_PRIO_Msk                0x300UL
#define AXI_DMAC_CH_CTL_ENABLED_Pos             31UL
#define AXI_DMAC_CH_CTL_ENABLED_Msk             0x80000000UL
/* AXI_DMAC_CH.STATUS */
#define AXI_DMAC_CH_STATUS_ENABLED_Pos          31UL
#define AXI_DMAC_CH_STATUS_ENABLED_Msk          0x80000000UL
/* AXI_DMAC_CH.IDX */
#define AXI_DMAC_CH_IDX_X_Pos                   0UL
#define AXI_DMAC_CH_IDX_X_Msk                   0xFFFFUL
#define AXI_DMAC_CH_IDX_Y_Pos                   16UL
#define AXI_DMAC_CH_IDX_Y_Msk                   0xFFFF0000UL
/* AXI_DMAC_CH.SRC */
#define AXI_DMAC_CH_SRC_ADDR_Pos                0UL
#define AXI_DMAC_CH_SRC_ADDR_Msk                0xFFFFFFFFUL
/* AXI_DMAC_CH.DST */
#define AXI_DMAC_CH_DST_ADDR_Pos                0UL
#define AXI_DMAC_CH_DST_ADDR_Msk                0xFFFFFFFFUL
/* AXI_DMAC_CH.M_IDX */
#define AXI_DMAC_CH_M_IDX_M_Pos                 0UL
#define AXI_DMAC_CH_M_IDX_M_Msk                 0xFFFFFFUL
/* AXI_DMAC_CH.CURR */
#define AXI_DMAC_CH_CURR_PTR_Pos                3UL
#define AXI_DMAC_CH_CURR_PTR_Msk                0xFFFFFFF8UL
/* AXI_DMAC_CH.TR_CMD */
#define AXI_DMAC_CH_TR_CMD_ACTIVATE_Pos         0UL
#define AXI_DMAC_CH_TR_CMD_ACTIVATE_Msk         0x1UL
/* AXI_DMAC_CH.DESCR_STATUS */
#define AXI_DMAC_CH_DESCR_STATUS_VALID_Pos      31UL
#define AXI_DMAC_CH_DESCR_STATUS_VALID_Msk      0x80000000UL
/* AXI_DMAC_CH.DESCR_CTL */
#define AXI_DMAC_CH_DESCR_CTL_WAIT_FOR_DEACT_Pos 0UL
#define AXI_DMAC_CH_DESCR_CTL_WAIT_FOR_DEACT_Msk 0x3UL
#define AXI_DMAC_CH_DESCR_CTL_INTR_TYPE_Pos     2UL
#define AXI_DMAC_CH_DESCR_CTL_INTR_TYPE_Msk     0xCUL
#define AXI_DMAC_CH_DESCR_CTL_TR_OUT_TYPE_Pos   4UL
#define AXI_DMAC_CH_DESCR_CTL_TR_OUT_TYPE_Msk   0x30UL
#define AXI_DMAC_CH_DESCR_CTL_TR_IN_TYPE_Pos    6UL
#define AXI_DMAC_CH_DESCR_CTL_TR_IN_TYPE_Msk    0xC0UL
#define AXI_DMAC_CH_DESCR_CTL_DATA_PREFETCH_Pos 8UL
#define AXI_DMAC_CH_DESCR_CTL_DATA_PREFETCH_Msk 0x100UL
#define AXI_DMAC_CH_DESCR_CTL_CH_DISABLE_Pos    24UL
#define AXI_DMAC_CH_DESCR_CTL_CH_DISABLE_Msk    0x1000000UL
#define AXI_DMAC_CH_DESCR_CTL_DESCR_TYPE_Pos    28UL
#define AXI_DMAC_CH_DESCR_CTL_DESCR_TYPE_Msk    0x30000000UL
/* AXI_DMAC_CH.DESCR_SRC */
#define AXI_DMAC_CH_DESCR_SRC_ADDR_Pos          0UL
#define AXI_DMAC_CH_DESCR_SRC_ADDR_Msk          0xFFFFFFFFUL
/* AXI_DMAC_CH.DESCR_DST */
#define AXI_DMAC_CH_DESCR_DST_ADDR_Pos          0UL
#define AXI_DMAC_CH_DESCR_DST_ADDR_Msk          0xFFFFFFFFUL
/* AXI_DMAC_CH.DESCR_M_SIZE */
#define AXI_DMAC_CH_DESCR_M_SIZE_M_COUNT_Pos    0UL
#define AXI_DMAC_CH_DESCR_M_SIZE_M_COUNT_Msk    0xFFFFFFUL
/* AXI_DMAC_CH.DESCR_X_SIZE */
#define AXI_DMAC_CH_DESCR_X_SIZE_X_COUNT_Pos    0UL
#define AXI_DMAC_CH_DESCR_X_SIZE_X_COUNT_Msk    0xFFFFUL
/* AXI_DMAC_CH.DESCR_X_INCR */
#define AXI_DMAC_CH_DESCR_X_INCR_SRC_X_Pos      0UL
#define AXI_DMAC_CH_DESCR_X_INCR_SRC_X_Msk      0xFFFFUL
#define AXI_DMAC_CH_DESCR_X_INCR_DST_X_Pos      16UL
#define AXI_DMAC_CH_DESCR_X_INCR_DST_X_Msk      0xFFFF0000UL
/* AXI_DMAC_CH.DESCR_Y_SIZE */
#define AXI_DMAC_CH_DESCR_Y_SIZE_Y_COUNT_Pos    0UL
#define AXI_DMAC_CH_DESCR_Y_SIZE_Y_COUNT_Msk    0xFFFFUL
/* AXI_DMAC_CH.DESCR_Y_INCR */
#define AXI_DMAC_CH_DESCR_Y_INCR_SRC_Y_Pos      0UL
#define AXI_DMAC_CH_DESCR_Y_INCR_SRC_Y_Msk      0xFFFFUL
#define AXI_DMAC_CH_DESCR_Y_INCR_DST_Y_Pos      16UL
#define AXI_DMAC_CH_DESCR_Y_INCR_DST_Y_Msk      0xFFFF0000UL
/* AXI_DMAC_CH.DESCR_NEXT */
#define AXI_DMAC_CH_DESCR_NEXT_PTR_Pos          3UL
#define AXI_DMAC_CH_DESCR_NEXT_PTR_Msk          0xFFFFFFF8UL
/* AXI_DMAC_CH.INTR */
#define AXI_DMAC_CH_INTR_COMPLETION_Pos         0UL
#define AXI_DMAC_CH_INTR_COMPLETION_Msk         0x1UL
#define AXI_DMAC_CH_INTR_SRC_BUS_ERROR_Pos      1UL
#define AXI_DMAC_CH_INTR_SRC_BUS_ERROR_Msk      0x2UL
#define AXI_DMAC_CH_INTR_DST_BUS_ERROR_Pos      2UL
#define AXI_DMAC_CH_INTR_DST_BUS_ERROR_Msk      0x4UL
#define AXI_DMAC_CH_INTR_INVALID_DESCR_TYPE_Pos 3UL
#define AXI_DMAC_CH_INTR_INVALID_DESCR_TYPE_Msk 0x8UL
#define AXI_DMAC_CH_INTR_CURR_PTR_NULL_Pos      5UL
#define AXI_DMAC_CH_INTR_CURR_PTR_NULL_Msk      0x20UL
#define AXI_DMAC_CH_INTR_ACTIVE_CH_DISABLED_Pos 6UL
#define AXI_DMAC_CH_INTR_ACTIVE_CH_DISABLED_Msk 0x40UL
#define AXI_DMAC_CH_INTR_DESCR_BUS_ERROR_Pos    7UL
#define AXI_DMAC_CH_INTR_DESCR_BUS_ERROR_Msk    0x80UL
/* AXI_DMAC_CH.INTR_SET */
#define AXI_DMAC_CH_INTR_SET_COMPLETION_Pos     0UL
#define AXI_DMAC_CH_INTR_SET_COMPLETION_Msk     0x1UL
#define AXI_DMAC_CH_INTR_SET_SRC_BUS_ERROR_Pos  1UL
#define AXI_DMAC_CH_INTR_SET_SRC_BUS_ERROR_Msk  0x2UL
#define AXI_DMAC_CH_INTR_SET_DST_BUS_ERROR_Pos  2UL
#define AXI_DMAC_CH_INTR_SET_DST_BUS_ERROR_Msk  0x4UL
#define AXI_DMAC_CH_INTR_SET_INVALID_DESCR_TYPE_Pos 3UL
#define AXI_DMAC_CH_INTR_SET_INVALID_DESCR_TYPE_Msk 0x8UL
#define AXI_DMAC_CH_INTR_SET_CURR_PTR_NULL_Pos  5UL
#define AXI_DMAC_CH_INTR_SET_CURR_PTR_NULL_Msk  0x20UL
#define AXI_DMAC_CH_INTR_SET_ACTIVE_CH_DISABLED_Pos 6UL
#define AXI_DMAC_CH_INTR_SET_ACTIVE_CH_DISABLED_Msk 0x40UL
#define AXI_DMAC_CH_INTR_SET_DESCR_BUS_ERROR_Pos 7UL
#define AXI_DMAC_CH_INTR_SET_DESCR_BUS_ERROR_Msk 0x80UL
/* AXI_DMAC_CH.INTR_MASK */
#define AXI_DMAC_CH_INTR_MASK_COMPLETION_Pos    0UL
#define AXI_DMAC_CH_INTR_MASK_COMPLETION_Msk    0x1UL
#define AXI_DMAC_CH_INTR_MASK_SRC_BUS_ERROR_Pos 1UL
#define AXI_DMAC_CH_INTR_MASK_SRC_BUS_ERROR_Msk 0x2UL
#define AXI_DMAC_CH_INTR_MASK_DST_BUS_ERROR_Pos 2UL
#define AXI_DMAC_CH_INTR_MASK_DST_BUS_ERROR_Msk 0x4UL
#define AXI_DMAC_CH_INTR_MASK_INVALID_DESCR_TYPE_Pos 3UL
#define AXI_DMAC_CH_INTR_MASK_INVALID_DESCR_TYPE_Msk 0x8UL
#define AXI_DMAC_CH_INTR_MASK_CURR_PTR_NULL_Pos 5UL
#define AXI_DMAC_CH_INTR_MASK_CURR_PTR_NULL_Msk 0x20UL
#define AXI_DMAC_CH_INTR_MASK_ACTIVE_CH_DISABLED_Pos 6UL
#define AXI_DMAC_CH_INTR_MASK_ACTIVE_CH_DISABLED_Msk 0x40UL
#define AXI_DMAC_CH_INTR_MASK_DESCR_BUS_ERROR_Pos 7UL
#define AXI_DMAC_CH_INTR_MASK_DESCR_BUS_ERROR_Msk 0x80UL
/* AXI_DMAC_CH.INTR_MASKED */
#define AXI_DMAC_CH_INTR_MASKED_COMPLETION_Pos  0UL
#define AXI_DMAC_CH_INTR_MASKED_COMPLETION_Msk  0x1UL
#define AXI_DMAC_CH_INTR_MASKED_SRC_BUS_ERROR_Pos 1UL
#define AXI_DMAC_CH_INTR_MASKED_SRC_BUS_ERROR_Msk 0x2UL
#define AXI_DMAC_CH_INTR_MASKED_DST_BUS_ERROR_Pos 2UL
#define AXI_DMAC_CH_INTR_MASKED_DST_BUS_ERROR_Msk 0x4UL
#define AXI_DMAC_CH_INTR_MASKED_INVALID_DESCR_TYPE_Pos 3UL
#define AXI_DMAC_CH_INTR_MASKED_INVALID_DESCR_TYPE_Msk 0x8UL
#define AXI_DMAC_CH_INTR_MASKED_CURR_PTR_NULL_Pos 5UL
#define AXI_DMAC_CH_INTR_MASKED_CURR_PTR_NULL_Msk 0x20UL
#define AXI_DMAC_CH_INTR_MASKED_ACTIVE_CH_DISABLED_Pos 6UL
#define AXI_DMAC_CH_INTR_MASKED_ACTIVE_CH_DISABLED_Msk 0x40UL
#define AXI_DMAC_CH_INTR_MASKED_DESCR_BUS_ERROR_Pos 7UL
#define AXI_DMAC_CH_INTR_MASKED_DESCR_BUS_ERROR_Msk 0x80UL


/* AXI_DMAC.CTL */
#define AXI_DMAC_CTL_ENABLED_Pos                31UL
#define AXI_DMAC_CTL_ENABLED_Msk                0x80000000UL
/* AXI_DMAC.STATUS */
#define AXI_DMAC_STATUS_CH_EN_Pos               0UL
#define AXI_DMAC_STATUS_CH_EN_Msk               0xFFUL
/* AXI_DMAC.ACTIVE_SEC */
#define AXI_DMAC_ACTIVE_SEC_ACTIVE_Pos          0UL
#define AXI_DMAC_ACTIVE_SEC_ACTIVE_Msk          0xFFUL
/* AXI_DMAC.ACTIVE_NONSEC */
#define AXI_DMAC_ACTIVE_NONSEC_ACTIVE_Pos       0UL
#define AXI_DMAC_ACTIVE_NONSEC_ACTIVE_Msk       0xFFUL


#endif /* _CYIP_AXI_DMAC_H_ */


/* [] END OF FILE */
