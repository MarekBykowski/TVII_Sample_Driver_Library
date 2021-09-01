/***************************************************************************//**
* \file cyip_jpegdec.h
*
* \brief
* JPEGDEC IP definitions
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

#ifndef _CYIP_JPEGDEC_H_
#define _CYIP_JPEGDEC_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                   JPEGDEC
*******************************************************************************/

#define JPEGDEC_HF_SECTION_SIZE                 0x00000100UL
#define JPEGDEC_DEC_SECTION_SIZE                0x00000800UL
#define JPEGDEC_SECTION_SIZE                    0x00002000UL

/**
  * \brief AXI cache attributes. (JPEGDEC_HF_AXICTL)
  */
typedef struct stc_JPEGDEC_HF_AXICTL_field {
  uint32_t                         u4ARCACHE:4;
  uint32_t                         :4;
  uint32_t                         u4AWCACHE:4;
  uint32_t                         :20;
} stc_JPEGDEC_HF_AXICTL_field_t;

typedef union un_JPEGDEC_HF_AXICTL {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_AXICTL_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_AXICTL_t;

/**
  * \brief AXI burst settings. (JPEGDEC_HF_BURST)
  */
typedef struct stc_JPEGDEC_HF_BURST_field {
  uint32_t                         u1FETCHBURSTLENGTH:1;
  uint32_t                         :7;
  uint32_t                         u1STOREBURSTLENGTH:1;
  uint32_t                         :23;
} stc_JPEGDEC_HF_BURST_field_t;

typedef union un_JPEGDEC_HF_BURST {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_BURST_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_BURST_t;

/**
  * \brief Source buffer configuration (JPEG). (JPEGDEC_HF_FETCHBUF0)
  */
typedef struct stc_JPEGDEC_HF_FETCHBUF0_field {
  uint32_t                         u32FETCHBASEADDRESS:32;
} stc_JPEGDEC_HF_FETCHBUF0_field_t;

typedef union un_JPEGDEC_HF_FETCHBUF0 {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_FETCHBUF0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_FETCHBUF0_t;

/**
  * \brief Source buffer configuration (JPEG). (JPEGDEC_HF_FETCHBUF1)
  */
typedef struct stc_JPEGDEC_HF_FETCHBUF1_field {
  uint32_t                         u30FETCHLENGTH:30;
  uint32_t                         :2;
} stc_JPEGDEC_HF_FETCHBUF1_field_t;

typedef union un_JPEGDEC_HF_FETCHBUF1 {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_FETCHBUF1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_FETCHBUF1_t;

/**
  * \brief Destination buffer configuration (Y, YUV, RGB). (JPEGDEC_HF_STORE0BUF0)
  */
typedef struct stc_JPEGDEC_HF_STORE0BUF0_field {
  uint32_t                         :6;
  uint32_t                         u26STOREBASEADDRESS0:26;
} stc_JPEGDEC_HF_STORE0BUF0_field_t;

typedef union un_JPEGDEC_HF_STORE0BUF0 {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_STORE0BUF0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_STORE0BUF0_t;

/**
  * \brief Destination buffer configuration (Y, YUV, RGB). (JPEGDEC_HF_STORE0BUF1)
  */
typedef struct stc_JPEGDEC_HF_STORE0BUF1_field {
  uint32_t                         :6;
  uint32_t                         u26STORESTRIDE0:26;
} stc_JPEGDEC_HF_STORE0BUF1_field_t;

typedef union un_JPEGDEC_HF_STORE0BUF1 {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_STORE0BUF1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_STORE0BUF1_t;

/**
  * \brief Destination buffer configuration (Y, YUV, RGB). (JPEGDEC_HF_STORE0BUF2)
  */
typedef struct stc_JPEGDEC_HF_STORE0BUF2_field {
  uint32_t                         :6;
  uint32_t                         u26STORELENGTH0:26;
} stc_JPEGDEC_HF_STORE0BUF2_field_t;

typedef union un_JPEGDEC_HF_STORE0BUF2 {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_STORE0BUF2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_STORE0BUF2_t;

/**
  * \brief Destination buffer configuration (UV). (JPEGDEC_HF_STORE1BUF0)
  */
typedef struct stc_JPEGDEC_HF_STORE1BUF0_field {
  uint32_t                         :6;
  uint32_t                         u26STOREBASEADDRESS1:26;
} stc_JPEGDEC_HF_STORE1BUF0_field_t;

typedef union un_JPEGDEC_HF_STORE1BUF0 {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_STORE1BUF0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_STORE1BUF0_t;

/**
  * \brief Destination buffer configuration (UV). (JPEGDEC_HF_STORE1BUF1)
  */
typedef struct stc_JPEGDEC_HF_STORE1BUF1_field {
  uint32_t                         :6;
  uint32_t                         u26STORESTRIDE1:26;
} stc_JPEGDEC_HF_STORE1BUF1_field_t;

typedef union un_JPEGDEC_HF_STORE1BUF1 {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_STORE1BUF1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_STORE1BUF1_t;

/**
  * \brief Destination buffer configuration (UV). (JPEGDEC_HF_STORE1BUF2)
  */
typedef struct stc_JPEGDEC_HF_STORE1BUF2_field {
  uint32_t                         :6;
  uint32_t                         u26STORELENGTH1:26;
} stc_JPEGDEC_HF_STORE1BUF2_field_t;

typedef union un_JPEGDEC_HF_STORE1BUF2 {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_STORE1BUF2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_STORE1BUF2_t;

/**
  * \brief Destination buffer format settings. (JPEGDEC_HF_STORECTL)
  */
typedef struct stc_JPEGDEC_HF_STORECTL_field {
  uint32_t                         u1UPSAMPLING:1;
  uint32_t                         :31;
} stc_JPEGDEC_HF_STORECTL_field_t;

typedef union un_JPEGDEC_HF_STORECTL {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_STORECTL_field_t  stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_STORECTL_t;

/**
  * \brief Start/Resume triggers. (JPEGDEC_HF_CMD)
  */
typedef struct stc_JPEGDEC_HF_CMD_field {
  uint32_t                         u1START:1;
  uint32_t                         :7;
  uint32_t                         u1RESUME:1;
  uint32_t                         :23;
} stc_JPEGDEC_HF_CMD_field_t;

typedef union un_JPEGDEC_HF_CMD {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_CMD_field_t       stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_CMD_t;

/**
  * \brief Decoder core decoding end interrupt mask. (JPEGDEC_HF_DECODEINTRMASK)
  */
typedef struct stc_JPEGDEC_HF_DECODEINTRMASK_field {
  uint32_t                         u1DECODEINTRMASK:1;
  uint32_t                         :31;
} stc_JPEGDEC_HF_DECODEINTRMASK_field_t;

typedef union un_JPEGDEC_HF_DECODEINTRMASK {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_DECODEINTRMASK_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_DECODEINTRMASK_t;

/**
  * \brief Interrupt status bits. (JPEGDEC_HF_INTR)
  */
typedef struct stc_JPEGDEC_HF_INTR_field {
  uint32_t                         u1FRAME_COMPLETE:1;
  uint32_t                         :7;
  uint32_t                         u1JPEG_CORE:1;
  uint32_t                         :7;
  uint32_t                         u1FETCH_ERROR:1;
  uint32_t                         u1STORE_ERROR:1;
  uint32_t                         :14;
} stc_JPEGDEC_HF_INTR_field_t;

typedef union un_JPEGDEC_HF_INTR {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_INTR_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_INTR_t;

/**
  * \brief Interrupt set bits. (JPEGDEC_HF_INTR_SET)
  */
typedef struct stc_JPEGDEC_HF_INTR_SET_field {
  uint32_t                         u1FRAME_COMPLETE_SET:1;
  uint32_t                         :7;
  uint32_t                         u1JPEG_CORE_SET:1;
  uint32_t                         :7;
  uint32_t                         u1FETCH_ERROR_SET:1;
  uint32_t                         u1STORE_ERROR_SET:1;
  uint32_t                         :14;
} stc_JPEGDEC_HF_INTR_SET_field_t;

typedef union un_JPEGDEC_HF_INTR_SET {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_INTR_SET_field_t  stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_INTR_SET_t;

/**
  * \brief Interrupt mask bits. (JPEGDEC_HF_INTR_MASK)
  */
typedef struct stc_JPEGDEC_HF_INTR_MASK_field {
  uint32_t                         u1FRAME_COMPLETE_MASK:1;
  uint32_t                         :7;
  uint32_t                         u1JPEG_CORE_MASK:1;
  uint32_t                         :7;
  uint32_t                         u1FETCH_ERROR_MASK:1;
  uint32_t                         u1STORE_ERROR_MASK:1;
  uint32_t                         :14;
} stc_JPEGDEC_HF_INTR_MASK_field_t;

typedef union un_JPEGDEC_HF_INTR_MASK {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_INTR_MASK_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_INTR_MASK_t;

/**
  * \brief Interrupt masked bits. (JPEGDEC_HF_INTR_MASKED)
  */
typedef struct stc_JPEGDEC_HF_INTR_MASKED_field {
  uint32_t                         u1FRAME_COMPLETE_MASKED:1;
  uint32_t                         :7;
  uint32_t                         u1JPEG_CORE_MASKED:1;
  uint32_t                         :7;
  uint32_t                         u1FETCH_ERROR_MASKED:1;
  uint32_t                         u1STORE_ERROR_MASKED:1;
  uint32_t                         :14;
} stc_JPEGDEC_HF_INTR_MASKED_field_t;

typedef union un_JPEGDEC_HF_INTR_MASKED {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_INTR_MASKED_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_INTR_MASKED_t;

/**
  * \brief Error status. (JPEGDEC_HF_ERRORSTATUS)
  */
typedef struct stc_JPEGDEC_HF_ERRORSTATUS_field {
  uint32_t                         u2ERRORREADAXI:2;
  uint32_t                         :2;
  uint32_t                         u2ERRORWRITEAXI:2;
  uint32_t                         :2;
  uint32_t                         u1ERRORSTOREOVERLENGTH0:1;
  uint32_t                         :3;
  uint32_t                         u1ERRORSTOREOVERLENGTH1:1;
  uint32_t                         :19;
} stc_JPEGDEC_HF_ERRORSTATUS_field_t;

typedef union un_JPEGDEC_HF_ERRORSTATUS {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_ERRORSTATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_ERRORSTATUS_t;

/**
  * \brief Operating status. (JPEGDEC_HF_OPERATINGSTATUS)
  */
typedef struct stc_JPEGDEC_HF_OPERATINGSTATUS_field {
  uint32_t                         u2OPERATIONMODE:2;
  uint32_t                         :14;
  uint32_t                         u1FETCHUNITACTIVE:1;
  uint32_t                         u1FETCHAXIACTIVE:1;
  uint32_t                         :6;
  uint32_t                         u1STOREUNITACTIVE:1;
  uint32_t                         u1STOREAXIACTIVE:1;
  uint32_t                         :6;
} stc_JPEGDEC_HF_OPERATINGSTATUS_field_t;

typedef union un_JPEGDEC_HF_OPERATINGSTATUS {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_OPERATINGSTATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_OPERATINGSTATUS_t;

/**
  * \brief Fetch Unit status. (JPEGDEC_HF_FETCHSTATUS)
  */
typedef struct stc_JPEGDEC_HF_FETCHSTATUS_field {
  uint32_t                         u30FETCHBYTES:30;
  uint32_t                         :2;
} stc_JPEGDEC_HF_FETCHSTATUS_field_t;

typedef union un_JPEGDEC_HF_FETCHSTATUS {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_FETCHSTATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_FETCHSTATUS_t;

/**
  * \brief Store Unit status. (JPEGDEC_HF_STORESTATUS)
  */
typedef struct stc_JPEGDEC_HF_STORESTATUS_field {
  uint32_t                         u30STOREBYTES:30;
  uint32_t                         :2;
} stc_JPEGDEC_HF_STORESTATUS_field_t;

typedef union un_JPEGDEC_HF_STORESTATUS {
  uint32_t                         u32Register;
  stc_JPEGDEC_HF_STORESTATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_HF_STORESTATUS_t;



/**
  * \brief Image property settings. (JPEGDEC_DEC_IMAGEPROPERTY)
  */
typedef struct stc_JPEGDEC_DEC_IMAGEPROPERTY_field {
  uint32_t                         u3SUBSAMPLE:3;
  uint32_t                         :1;
  uint32_t                         u1ENDIANSTORE:1;
  uint32_t                         u1ENDIANFETCH:1;
  uint32_t                         :26;
} stc_JPEGDEC_DEC_IMAGEPROPERTY_field_t;

typedef union un_JPEGDEC_DEC_IMAGEPROPERTY {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_IMAGEPROPERTY_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_IMAGEPROPERTY_t;

/**
  * \brief Software reset trigger. (JPEGDEC_DEC_SWRESET)
  */
typedef struct stc_JPEGDEC_DEC_SWRESET_field {
  uint32_t                         u1CORESTART_RESERVED:1;
  uint32_t                         u1CORERESUME_RESERVED:1;
  uint32_t                         :29;
  uint32_t                         u1CORERESET:1;
} stc_JPEGDEC_DEC_SWRESET_field_t;

typedef union un_JPEGDEC_DEC_SWRESET {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_SWRESET_field_t  stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_SWRESET_t;

/**
  * \brief Decoding status (JPEGDEC_DEC_DECODINGSTATUS)
  */
typedef struct stc_JPEGDEC_DEC_DECODINGSTATUS_field {
  uint32_t                         u1DECODINGSTATUS:1;
  uint32_t                         :31;
} stc_JPEGDEC_DEC_DECODINGSTATUS_field_t;

typedef union un_JPEGDEC_DEC_DECODINGSTATUS {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_DECODINGSTATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_DECODINGSTATUS_t;

/**
  * \brief Quantization table number downloaded from the JPEG image. (JPEGDEC_DEC_QUANTTABLENO)
  */
typedef struct stc_JPEGDEC_DEC_QUANTTABLENO_field {
  uint32_t                         u2QT1COLOR:2;
  uint32_t                         u2QT2COLOR:2;
  uint32_t                         u2QT3COLOR:2;
  uint32_t                         u2QT4COLOR:2;
  uint32_t                         :24;
} stc_JPEGDEC_DEC_QUANTTABLENO_field_t;

typedef union un_JPEGDEC_DEC_QUANTTABLENO {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_QUANTTABLENO_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_QUANTTABLENO_t;

/**
  * \brief Huffman Table number downloaded from the JPEG image. (JPEGDEC_DEC_HUFFMANTABLENO)
  */
typedef struct stc_JPEGDEC_DEC_HUFFMANTABLENO_field {
  uint32_t                         u2HTDC1COLOR:2;
  uint32_t                         u2HTAC1COLOR:2;
  uint32_t                         u2HTDC2COLOR:2;
  uint32_t                         u2HTAC2COLOR:2;
  uint32_t                         u2HTDC3COLOR:2;
  uint32_t                         u2HTAC3COLOR:2;
  uint32_t                         u2HTDC4COLOR:2;
  uint32_t                         u2HTAC4COLOR:2;
  uint32_t                         :16;
} stc_JPEGDEC_DEC_HUFFMANTABLENO_field_t;

typedef union un_JPEGDEC_DEC_HUFFMANTABLENO {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_HUFFMANTABLENO_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_HUFFMANTABLENO_t;

/**
  * \brief The DRI value downloaded from the JPEG image. (JPEGDEC_DEC_DRI)
  */
typedef struct stc_JPEGDEC_DEC_DRI_field {
  uint32_t                         u16DRI:16;
  uint32_t                         :16;
} stc_JPEGDEC_DEC_DRI_field_t;

typedef union un_JPEGDEC_DEC_DRI {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_DRI_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_DRI_t;

/**
  * \brief Y size downloaded from the JPEG image. (JPEGDEC_DEC_SIZEY)
  */
typedef struct stc_JPEGDEC_DEC_SIZEY_field {
  uint32_t                         u16SIZEY:16;
  uint32_t                         :16;
} stc_JPEGDEC_DEC_SIZEY_field_t;

typedef union un_JPEGDEC_DEC_SIZEY {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_SIZEY_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_SIZEY_t;

/**
  * \brief X size downloaded from the JPEG image. (JPEGDEC_DEC_SIZEX)
  */
typedef struct stc_JPEGDEC_DEC_SIZEX_field {
  uint32_t                         u16SIZEX:16;
  uint32_t                         :16;
} stc_JPEGDEC_DEC_SIZEX_field_t;

typedef union un_JPEGDEC_DEC_SIZEX {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_SIZEX_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_SIZEX_t;

/**
  * \brief Decoding option settings. (JPEGDEC_DEC_DECODINGOPTION)
  */
typedef struct stc_JPEGDEC_DEC_DECODINGOPTION_field {
  uint32_t                         :1;
  uint32_t                         u1MARKERSKIP:1;
  uint32_t                         :1;
  uint32_t                         u1CROP:1;
  uint32_t                         :28;
} stc_JPEGDEC_DEC_DECODINGOPTION_field_t;

typedef union un_JPEGDEC_DEC_DECODINGOPTION {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_DECODINGOPTION_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_DECODINGOPTION_t;

/**
  * \brief Interrupt Setting (JPEGDEC_DEC_INTR_DEC_EN)
  */
typedef struct stc_JPEGDEC_DEC_INTR_DEC_EN_field {
  uint32_t                         u1APPMARKER:1;
  uint32_t                         u1COMMARKER:1;
  uint32_t                         u1UNKNOWNMARKER:1;
  uint32_t                         u1SIZEAVAILABLE:1;
  uint32_t                         :4;
  uint32_t                         u1ERRORINTERVAL:1;
  uint32_t                         u1ERRORTOTALDATA:1;
  uint32_t                         u1CORRECTION:1;
  uint32_t                         :20;
  uint32_t                         u1INTMASK:1;
} stc_JPEGDEC_DEC_INTR_DEC_EN_field_t;

typedef union un_JPEGDEC_DEC_INTR_DEC_EN {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_INTR_DEC_EN_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_INTR_DEC_EN_t;

/**
  * \brief Interrupt status (JPEGDEC_DEC_INTR_DEC)
  */
typedef struct stc_JPEGDEC_DEC_INTR_DEC_field {
  uint32_t                         u1APPMARKER:1;
  uint32_t                         u1COMMARKER:1;
  uint32_t                         u1UNKNOWNMARKER:1;
  uint32_t                         u1SIZEAVAILABLE:1;
  uint32_t                         :4;
  uint32_t                         u1ERRORINTERVAL:1;
  uint32_t                         u1ERRORTOTALDATA:1;
  uint32_t                         u1ERRORMARKER:1;
  uint32_t                         :19;
  uint32_t                         u1CORRECTEDEND:1;
  uint32_t                         u1NORMALEND:1;
} stc_JPEGDEC_DEC_INTR_DEC_field_t;

typedef union un_JPEGDEC_DEC_INTR_DEC {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_INTR_DEC_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_INTR_DEC_t;

/**
  * \brief Error code for INTR_DEC.ErrorMarker. (JPEGDEC_DEC_ERRORCODE)
  */
typedef struct stc_JPEGDEC_DEC_ERRORCODE_field {
  uint32_t                         u6ERRORCODE:6;
  uint32_t                         :26;
} stc_JPEGDEC_DEC_ERRORCODE_field_t;

typedef union un_JPEGDEC_DEC_ERRORCODE {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_ERRORCODE_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_ERRORCODE_t;

/**
  * \brief Correction Mode and Crop Decoding status. This register is initialized by the decoding start trigger (CMD.START). (JPEGDEC_DEC_CORRECTIONCROPSTATUS)
  */
typedef struct stc_JPEGDEC_DEC_CORRECTIONCROPSTATUS_field {
  uint32_t                         u1INTERVAL:1;
  uint32_t                         u1TOTALSIZE:1;
  uint32_t                         :1;
  uint32_t                         u1CROPEND:1;
  uint32_t                         u1CROPSIZEERROR:1;
  uint32_t                         u1MCUUNITERROR:1;
  uint32_t                         u1NODRI:1;
  uint32_t                         u1NORST:1;
  uint32_t                         :24;
} stc_JPEGDEC_DEC_CORRECTIONCROPSTATUS_field_t;

typedef union un_JPEGDEC_DEC_CORRECTIONCROPSTATUS {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_CORRECTIONCROPSTATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_CORRECTIONCROPSTATUS_t;

/**
  * \brief Suspend status. Decoding can be resumed from Suspended State by writing '1' to CMD.RESUME. (JPEGDEC_DEC_SUSPEND)
  */
typedef struct stc_JPEGDEC_DEC_SUSPEND_field {
  uint32_t                         u1SUSPEND:1;
  uint32_t                         :31;
} stc_JPEGDEC_DEC_SUSPEND_field_t;

typedef union un_JPEGDEC_DEC_SUSPEND {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_SUSPEND_field_t  stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_SUSPEND_t;

/**
  * \brief DNL value downloaded from the JPEG image. This register is initialized by the decoding start trigger (CMD.START). (JPEGDEC_DEC_DNL)
  */
typedef struct stc_JPEGDEC_DEC_DNL_field {
  uint32_t                         u16DNL:16;
  uint32_t                         :16;
} stc_JPEGDEC_DEC_DNL_field_t;

typedef union un_JPEGDEC_DEC_DNL {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_DNL_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_DNL_t;

/**
  * \brief Y crop start position (JPEGDEC_DEC_CROPSTARTY)
  */
typedef struct stc_JPEGDEC_DEC_CROPSTARTY_field {
  uint32_t                         u16CROPSTARTY:16;
  uint32_t                         :16;
} stc_JPEGDEC_DEC_CROPSTARTY_field_t;

typedef union un_JPEGDEC_DEC_CROPSTARTY {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_CROPSTARTY_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_CROPSTARTY_t;

/**
  * \brief X crop start position (JPEGDEC_DEC_CROPSTARTX)
  */
typedef struct stc_JPEGDEC_DEC_CROPSTARTX_field {
  uint32_t                         u16CROPSTARTX:16;
  uint32_t                         :16;
} stc_JPEGDEC_DEC_CROPSTARTX_field_t;

typedef union un_JPEGDEC_DEC_CROPSTARTX {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_CROPSTARTX_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_CROPSTARTX_t;

/**
  * \brief Crop size for Y direction (JPEGDEC_DEC_CROPSIZEY)
  */
typedef struct stc_JPEGDEC_DEC_CROPSIZEY_field {
  uint32_t                         u16CROPSIZEY:16;
  uint32_t                         :16;
} stc_JPEGDEC_DEC_CROPSIZEY_field_t;

typedef union un_JPEGDEC_DEC_CROPSIZEY {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_CROPSIZEY_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_CROPSIZEY_t;

/**
  * \brief Crop size for X direction (JPEGDEC_DEC_CROPSIZEX)
  */
typedef struct stc_JPEGDEC_DEC_CROPSIZEX_field {
  uint32_t                         u16CROPSIZEX:16;
  uint32_t                         :16;
} stc_JPEGDEC_DEC_CROPSIZEX_field_t;

typedef union un_JPEGDEC_DEC_CROPSIZEX {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_CROPSIZEX_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_CROPSIZEX_t;

/**
  * \brief Quantization Table number 0 downloaded from a JPEG image. (JPEGDEC_DEC_QUANTTABLE0)
  */
typedef struct stc_JPEGDEC_DEC_QUANTTABLE0_field {
  uint32_t                         u8QT0CONTENT0:8;
  uint32_t                         :8;
  uint32_t                         u8QT0CONTENT1:8;
  uint32_t                         :8;
} stc_JPEGDEC_DEC_QUANTTABLE0_field_t;

typedef union un_JPEGDEC_DEC_QUANTTABLE0 {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_QUANTTABLE0_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_QUANTTABLE0_t;

/**
  * \brief Quantization Table number 1 downloaded from a JPEG image. (JPEGDEC_DEC_QUANTTABLE1)
  */
typedef struct stc_JPEGDEC_DEC_QUANTTABLE1_field {
  uint32_t                         u8QT1CONTENT0:8;
  uint32_t                         :8;
  uint32_t                         u8QT1CONTENT1:8;
  uint32_t                         :8;
} stc_JPEGDEC_DEC_QUANTTABLE1_field_t;

typedef union un_JPEGDEC_DEC_QUANTTABLE1 {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_QUANTTABLE1_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_QUANTTABLE1_t;

/**
  * \brief Quantization Table number 2 downloaded from a JPEG image. (JPEGDEC_DEC_QUANTTABLE2)
  */
typedef struct stc_JPEGDEC_DEC_QUANTTABLE2_field {
  uint32_t                         u8QT2CONTENT0:8;
  uint32_t                         :8;
  uint32_t                         u8QT2CONTENT1:8;
  uint32_t                         :8;
} stc_JPEGDEC_DEC_QUANTTABLE2_field_t;

typedef union un_JPEGDEC_DEC_QUANTTABLE2 {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_QUANTTABLE2_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_QUANTTABLE2_t;

/**
  * \brief Quantization Table number 3 downloaded from a JPEG image. (JPEGDEC_DEC_QUANTTABLE3)
  */
typedef struct stc_JPEGDEC_DEC_QUANTTABLE3_field {
  uint32_t                         u8QT3CONTENT0:8;
  uint32_t                         :8;
  uint32_t                         u8QT3CONTENT1:8;
  uint32_t                         :8;
} stc_JPEGDEC_DEC_QUANTTABLE3_field_t;

typedef union un_JPEGDEC_DEC_QUANTTABLE3 {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_QUANTTABLE3_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_QUANTTABLE3_t;

/**
  * \brief Shows the code length distribution for DC Huffman Table 0. For each Huffman code lengths (0 to 16), the number of used codes is shown. e.g. Field for code length 3 has the value '5' when 010/011/100/101/110 are used. (JPEGDEC_DEC_HUFFMANTABLEDC0CODELENGTH)
  */
typedef struct stc_JPEGDEC_DEC_HUFFMANTABLEDC0CODELENGTH_field {
  uint32_t                         u32DC0NUMCODELENGTHN:32;
} stc_JPEGDEC_DEC_HUFFMANTABLEDC0CODELENGTH_field_t;

typedef union un_JPEGDEC_DEC_HUFFMANTABLEDC0CODELENGTH {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_HUFFMANTABLEDC0CODELENGTH_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_HUFFMANTABLEDC0CODELENGTH_t;

/**
  * \brief Shows the group numbers in the order of descending appearance frequencies for DC Huffman Table 0. (JPEGDEC_DEC_HUFFMANTABLEDC0GROUPNO)
  */
typedef struct stc_JPEGDEC_DEC_HUFFMANTABLEDC0GROUPNO_field {
  uint32_t                         u32DC0GROUPNO:32;
} stc_JPEGDEC_DEC_HUFFMANTABLEDC0GROUPNO_field_t;

typedef union un_JPEGDEC_DEC_HUFFMANTABLEDC0GROUPNO {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_HUFFMANTABLEDC0GROUPNO_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_HUFFMANTABLEDC0GROUPNO_t;

/**
  * \brief Shows the code length distribution for AC Huffman Table 0. For each Huffman code lengths (0 to 16), the number of used codes is shown. e.g. Field for code length 3 has the value '5' when 010/011/100/101/110 are used. (JPEGDEC_DEC_HUFFMANTABLEAC0CODELENGTH)
  */
typedef struct stc_JPEGDEC_DEC_HUFFMANTABLEAC0CODELENGTH_field {
  uint32_t                         u32AC0NUMCODELENGTHN:32;
} stc_JPEGDEC_DEC_HUFFMANTABLEAC0CODELENGTH_field_t;

typedef union un_JPEGDEC_DEC_HUFFMANTABLEAC0CODELENGTH {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_HUFFMANTABLEAC0CODELENGTH_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_HUFFMANTABLEAC0CODELENGTH_t;

/**
  * \brief Shows the zero run-length+group number values in the order of descending appearance frequencies for AC Huffman Table 0. (JPEGDEC_DEC_HUFFMANTABLEAC0GROUPNO)
  */
typedef struct stc_JPEGDEC_DEC_HUFFMANTABLEAC0GROUPNO_field {
  uint32_t                         u32AC0GROUPNO:32;
} stc_JPEGDEC_DEC_HUFFMANTABLEAC0GROUPNO_field_t;

typedef union un_JPEGDEC_DEC_HUFFMANTABLEAC0GROUPNO {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_HUFFMANTABLEAC0GROUPNO_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_HUFFMANTABLEAC0GROUPNO_t;

/**
  * \brief Shows the code length distribution for DC Huffman Table 1. For each Huffman code lengths (0 to 16), the number of used codes is shown. e.g. Field for code length 3 has the value '5' when 010/011/100/101/110 are used. (JPEGDEC_DEC_HUFFMANTABLEDC1CODELENGTH)
  */
typedef struct stc_JPEGDEC_DEC_HUFFMANTABLEDC1CODELENGTH_field {
  uint32_t                         u32DC1NUMCODELENGTHN:32;
} stc_JPEGDEC_DEC_HUFFMANTABLEDC1CODELENGTH_field_t;

typedef union un_JPEGDEC_DEC_HUFFMANTABLEDC1CODELENGTH {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_HUFFMANTABLEDC1CODELENGTH_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_HUFFMANTABLEDC1CODELENGTH_t;

/**
  * \brief Shows the group numbers in the order of descending appearance frequencies for DC Huffman Table 1. (JPEGDEC_DEC_HUFFMANTABLEDC1GROUPNO)
  */
typedef struct stc_JPEGDEC_DEC_HUFFMANTABLEDC1GROUPNO_field {
  uint32_t                         u32DC1GROUPNO:32;
} stc_JPEGDEC_DEC_HUFFMANTABLEDC1GROUPNO_field_t;

typedef union un_JPEGDEC_DEC_HUFFMANTABLEDC1GROUPNO {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_HUFFMANTABLEDC1GROUPNO_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_HUFFMANTABLEDC1GROUPNO_t;

/**
  * \brief Shows the code length distribution for AC Huffman Table 1. For each Huffman code lengths (0 to 16), the number of used codes is shown. e.g. Field for code length 3 has the value '5' when 010/011/100/101/110 are used. (JPEGDEC_DEC_HUFFMANTABLEAC1CODELENGTH)
  */
typedef struct stc_JPEGDEC_DEC_HUFFMANTABLEAC1CODELENGTH_field {
  uint32_t                         u32AC1NUMCODELENGTHN:32;
} stc_JPEGDEC_DEC_HUFFMANTABLEAC1CODELENGTH_field_t;

typedef union un_JPEGDEC_DEC_HUFFMANTABLEAC1CODELENGTH {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_HUFFMANTABLEAC1CODELENGTH_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_HUFFMANTABLEAC1CODELENGTH_t;

/**
  * \brief Shows the zero run-length+group number values in the order of descending appearance frequencies for AC Huffman Table 1. (JPEGDEC_DEC_HUFFMANTABLEAC1GROUPNO)
  */
typedef struct stc_JPEGDEC_DEC_HUFFMANTABLEAC1GROUPNO_field {
  uint32_t                         u32AC1GROUPNO:32;
} stc_JPEGDEC_DEC_HUFFMANTABLEAC1GROUPNO_field_t;

typedef union un_JPEGDEC_DEC_HUFFMANTABLEAC1GROUPNO {
  uint32_t                         u32Register;
  stc_JPEGDEC_DEC_HUFFMANTABLEAC1GROUPNO_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_DEC_HUFFMANTABLEAC1GROUPNO_t;



/**
  * \brief IP control register. (JPEGDEC_CTL)
  */
typedef struct stc_JPEGDEC_CTL_field {
  uint32_t                         :31;
  uint32_t                         u1ENABLED:1;
} stc_JPEGDEC_CTL_field_t;

typedef union un_JPEGDEC_CTL {
  uint32_t                         u32Register;
  stc_JPEGDEC_CTL_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_JPEGDEC_CTL_t;



/**
  * \brief Data fetch, store and interrupt control registers. (JPEGDEC_HF)
  */
typedef struct stc_JPEGDEC_HF {
  un_JPEGDEC_HF_AXICTL_t           unAXICTL;           /*!< 0x00000000 AXI cache attributes. */
  un_JPEGDEC_HF_BURST_t            unBURST;            /*!< 0x00000004 AXI burst settings. */
  uint32_t                         au32Reserved[2];
  un_JPEGDEC_HF_FETCHBUF0_t        unFETCHBUF0;        /*!< 0x00000010 Source buffer configuration (JPEG). */
  un_JPEGDEC_HF_FETCHBUF1_t        unFETCHBUF1;        /*!< 0x00000014 Source buffer configuration (JPEG). */
  uint32_t                         au32Reserved1[2];
  un_JPEGDEC_HF_STORE0BUF0_t       unSTORE0BUF0;       /*!< 0x00000020 Destination buffer configuration (Y, YUV, RGB). */
  un_JPEGDEC_HF_STORE0BUF1_t       unSTORE0BUF1;       /*!< 0x00000024 Destination buffer configuration (Y, YUV, RGB). */
  un_JPEGDEC_HF_STORE0BUF2_t       unSTORE0BUF2;       /*!< 0x00000028 Destination buffer configuration (Y, YUV, RGB). */
  uint32_t                         au32Reserved2[5];
  un_JPEGDEC_HF_STORE1BUF0_t       unSTORE1BUF0;       /*!< 0x00000040 Destination buffer configuration (UV). */
  un_JPEGDEC_HF_STORE1BUF1_t       unSTORE1BUF1;       /*!< 0x00000044 Destination buffer configuration (UV). */
  un_JPEGDEC_HF_STORE1BUF2_t       unSTORE1BUF2;       /*!< 0x00000048 Destination buffer configuration (UV). */
  uint32_t                         au32Reserved3[5];
  un_JPEGDEC_HF_STORECTL_t         unSTORECTL;         /*!< 0x00000060 Destination buffer format settings. */
  uint32_t                         au32Reserved4[3];
  un_JPEGDEC_HF_CMD_t              unCMD;              /*!< 0x00000070 Start/Resume triggers. */
  uint32_t                         au32Reserved5[3];
  un_JPEGDEC_HF_DECODEINTRMASK_t   unDECODEINTRMASK;   /*!< 0x00000080 Decoder core decoding end interrupt mask. */
  uint32_t                         au32Reserved6[3];
  un_JPEGDEC_HF_INTR_t             unINTR;             /*!< 0x00000090 Interrupt status bits. */
  un_JPEGDEC_HF_INTR_SET_t         unINTR_SET;         /*!< 0x00000094 Interrupt set bits. */
  un_JPEGDEC_HF_INTR_MASK_t        unINTR_MASK;        /*!< 0x00000098 Interrupt mask bits. */
  un_JPEGDEC_HF_INTR_MASKED_t      unINTR_MASKED;      /*!< 0x0000009C Interrupt masked bits. */
  uint32_t                         au32Reserved7[4];
  un_JPEGDEC_HF_ERRORSTATUS_t      unERRORSTATUS;      /*!< 0x000000B0 Error status. */
  un_JPEGDEC_HF_OPERATINGSTATUS_t  unOPERATINGSTATUS;  /*!< 0x000000B4 Operating status. */
  un_JPEGDEC_HF_FETCHSTATUS_t      unFETCHSTATUS;      /*!< 0x000000B8 Fetch Unit status. */
  un_JPEGDEC_HF_STORESTATUS_t      unSTORESTATUS;      /*!< 0x000000BC Store Unit status. */
  uint32_t                         au32Reserved8[16];
} stc_JPEGDEC_HF_t;                                    /*!< Size = 256 (0x100) */

/**
  * \brief JPEG decoder core registers. (JPEGDEC_DEC)
  */
typedef struct stc_JPEGDEC_DEC {
  un_JPEGDEC_DEC_IMAGEPROPERTY_t   unIMAGEPROPERTY;    /*!< 0x00000000 Image property settings. */
  un_JPEGDEC_DEC_SWRESET_t         unSWRESET;          /*!< 0x00000004 Software reset trigger. */
  un_JPEGDEC_DEC_DECODINGSTATUS_t  unDECODINGSTATUS;   /*!< 0x00000008 Decoding status */
  un_JPEGDEC_DEC_QUANTTABLENO_t    unQUANTTABLENO;     /*!< 0x0000000C Quantization table number downloaded from the JPEG
                                                                                image. */
  un_JPEGDEC_DEC_HUFFMANTABLENO_t  unHUFFMANTABLENO;   /*!< 0x00000010 Huffman Table number downloaded from the JPEG image. */
  un_JPEGDEC_DEC_DRI_t             unDRI;              /*!< 0x00000014 The DRI value downloaded from the JPEG image. */
  un_JPEGDEC_DEC_SIZEY_t           unSIZEY;            /*!< 0x00000018 Y size downloaded from the JPEG image. */
  un_JPEGDEC_DEC_SIZEX_t           unSIZEX;            /*!< 0x0000001C X size downloaded from the JPEG image. */
  uint32_t                         u32Reserved;
  un_JPEGDEC_DEC_DECODINGOPTION_t  unDECODINGOPTION;   /*!< 0x00000024 Decoding option settings. */
  un_JPEGDEC_DEC_INTR_DEC_EN_t     unINTR_DEC_EN;      /*!< 0x00000028 Interrupt Setting */
  un_JPEGDEC_DEC_INTR_DEC_t        unINTR_DEC;         /*!< 0x0000002C Interrupt status */
  un_JPEGDEC_DEC_ERRORCODE_t       unERRORCODE;        /*!< 0x00000030 Error code for INTR_DEC.ErrorMarker. */
  un_JPEGDEC_DEC_CORRECTIONCROPSTATUS_t unCORRECTIONCROPSTATUS; /*!< 0x00000034 Correction Mode and Crop Decoding status. This register
                                                                                is initialized by the decoding start trigger
                                                                                (CMD.START). */
  un_JPEGDEC_DEC_SUSPEND_t         unSUSPEND;          /*!< 0x00000038 Suspend status. Decoding can be resumed from Suspended
                                                                                State by writing '1' to CMD.RESUME. */
  un_JPEGDEC_DEC_DNL_t             unDNL;              /*!< 0x0000003C DNL value downloaded from the JPEG image. This register
                                                                                is initialized by the decoding start trigger
                                                                                (CMD.START). */
  un_JPEGDEC_DEC_CROPSTARTY_t      unCROPSTARTY;       /*!< 0x00000040 Y crop start position */
  un_JPEGDEC_DEC_CROPSTARTX_t      unCROPSTARTX;       /*!< 0x00000044 X crop start position */
  un_JPEGDEC_DEC_CROPSIZEY_t       unCROPSIZEY;        /*!< 0x00000048 Crop size for Y direction */
  un_JPEGDEC_DEC_CROPSIZEX_t       unCROPSIZEX;        /*!< 0x0000004C Crop size for X direction */
  uint32_t                         au32Reserved1[44];
  un_JPEGDEC_DEC_QUANTTABLE0_t     unQUANTTABLE0[32];  /*!< 0x00000100 Quantization Table number 0 downloaded from a JPEG
                                                                                image. */
  un_JPEGDEC_DEC_QUANTTABLE1_t     unQUANTTABLE1[32];  /*!< 0x00000180 Quantization Table number 1 downloaded from a JPEG
                                                                                image. */
  un_JPEGDEC_DEC_QUANTTABLE2_t     unQUANTTABLE2[32];  /*!< 0x00000200 Quantization Table number 2 downloaded from a JPEG
                                                                                image. */
  un_JPEGDEC_DEC_QUANTTABLE3_t     unQUANTTABLE3[32];  /*!< 0x00000280 Quantization Table number 3 downloaded from a JPEG
                                                                                image. */
  un_JPEGDEC_DEC_HUFFMANTABLEDC0CODELENGTH_t unHUFFMANTABLEDC0CODELENGTH[4]; /*!< 0x00000300 Shows the code length distribution for DC Huffman Table
                                                                                0. For each Huffman code lengths (0 to 16), the
                                                                                number of used codes is shown. e.g. Field for
                                                                                code length 3 has the value '5' when
                                                                                010/011/100/101/110 are used. */
  un_JPEGDEC_DEC_HUFFMANTABLEDC0GROUPNO_t unHUFFMANTABLEDC0GROUPNO[3]; /*!< 0x00000310 Shows the group numbers in the order of descending
                                                                                appearance frequencies for DC Huffman Table 0. */
  uint32_t                         u32Reserved2;
  un_JPEGDEC_DEC_HUFFMANTABLEAC0CODELENGTH_t unHUFFMANTABLEAC0CODELENGTH[4]; /*!< 0x00000320 Shows the code length distribution for AC Huffman Table
                                                                                0. For each Huffman code lengths (0 to 16), the
                                                                                number of used codes is shown. e.g. Field for
                                                                                code length 3 has the value '5' when
                                                                                010/011/100/101/110 are used. */
  un_JPEGDEC_DEC_HUFFMANTABLEAC0GROUPNO_t unHUFFMANTABLEAC0GROUPNO[41]; /*!< 0x00000330 Shows the zero run-length+group number values in the
                                                                                order of descending appearance frequencies for
                                                                                AC Huffman Table 0. */
  uint32_t                         au32Reserved3[16];
  un_JPEGDEC_DEC_HUFFMANTABLEDC1CODELENGTH_t unHUFFMANTABLEDC1CODELENGTH[4]; /*!< 0x00000414 Shows the code length distribution for DC Huffman Table
                                                                                1. For each Huffman code lengths (0 to 16), the
                                                                                number of used codes is shown. e.g. Field for
                                                                                code length 3 has the value '5' when
                                                                                010/011/100/101/110 are used. */
  un_JPEGDEC_DEC_HUFFMANTABLEDC1GROUPNO_t unHUFFMANTABLEDC1GROUPNO[3]; /*!< 0x00000424 Shows the group numbers in the order of descending
                                                                                appearance frequencies for DC Huffman Table 1. */
  uint32_t                         u32Reserved4;
  un_JPEGDEC_DEC_HUFFMANTABLEAC1CODELENGTH_t unHUFFMANTABLEAC1CODELENGTH[4]; /*!< 0x00000434 Shows the code length distribution for AC Huffman Table
                                                                                1. For each Huffman code lengths (0 to 16), the
                                                                                number of used codes is shown. e.g. Field for
                                                                                code length 3 has the value '5' when
                                                                                010/011/100/101/110 are used. */
  un_JPEGDEC_DEC_HUFFMANTABLEAC1GROUPNO_t unHUFFMANTABLEAC1GROUPNO[41]; /*!< 0x00000444 Shows the zero run-length+group number values in the
                                                                                order of descending appearance frequencies for
                                                                                AC Huffman Table 1. */
  uint32_t                         au32Reserved5[198];
} stc_JPEGDEC_DEC_t;                                   /*!< Size = 2048 (0x800) */

/**
  * \brief JPEGDEC (JPEGDEC)
  */
typedef struct stc_JPEGDEC {
  un_JPEGDEC_CTL_t                 unCTL;              /*!< 0x00000000 IP control register. */
  uint32_t                         au32Reserved[1023];
  stc_JPEGDEC_HF_t                 HF;                 /*!< 0x00001000 Data fetch, store and interrupt control registers. */
  uint32_t                         au32Reserved1[448];
  stc_JPEGDEC_DEC_t                DEC;                /*!< 0x00001800 JPEG decoder core registers. */
} stc_JPEGDEC_t;                                       /*!< Size = 8192 (0x2000) */


/* JPEGDEC_HF.AXICTL */
#define JPEGDEC_HF_AXICTL_ARCACHE_Pos           0UL
#define JPEGDEC_HF_AXICTL_ARCACHE_Msk           0xFUL
#define JPEGDEC_HF_AXICTL_AWCACHE_Pos           8UL
#define JPEGDEC_HF_AXICTL_AWCACHE_Msk           0xF00UL
/* JPEGDEC_HF.BURST */
#define JPEGDEC_HF_BURST_FETCHBURSTLENGTH_Pos   0UL
#define JPEGDEC_HF_BURST_FETCHBURSTLENGTH_Msk   0x1UL
#define JPEGDEC_HF_BURST_STOREBURSTLENGTH_Pos   8UL
#define JPEGDEC_HF_BURST_STOREBURSTLENGTH_Msk   0x100UL
/* JPEGDEC_HF.FETCHBUF0 */
#define JPEGDEC_HF_FETCHBUF0_FETCHBASEADDRESS_Pos 0UL
#define JPEGDEC_HF_FETCHBUF0_FETCHBASEADDRESS_Msk 0xFFFFFFFFUL
/* JPEGDEC_HF.FETCHBUF1 */
#define JPEGDEC_HF_FETCHBUF1_FETCHLENGTH_Pos    0UL
#define JPEGDEC_HF_FETCHBUF1_FETCHLENGTH_Msk    0x3FFFFFFFUL
/* JPEGDEC_HF.STORE0BUF0 */
#define JPEGDEC_HF_STORE0BUF0_STOREBASEADDRESS0_Pos 6UL
#define JPEGDEC_HF_STORE0BUF0_STOREBASEADDRESS0_Msk 0xFFFFFFC0UL
/* JPEGDEC_HF.STORE0BUF1 */
#define JPEGDEC_HF_STORE0BUF1_STORESTRIDE0_Pos  6UL
#define JPEGDEC_HF_STORE0BUF1_STORESTRIDE0_Msk  0xFFFFFFC0UL
/* JPEGDEC_HF.STORE0BUF2 */
#define JPEGDEC_HF_STORE0BUF2_STORELENGTH0_Pos  6UL
#define JPEGDEC_HF_STORE0BUF2_STORELENGTH0_Msk  0xFFFFFFC0UL
/* JPEGDEC_HF.STORE1BUF0 */
#define JPEGDEC_HF_STORE1BUF0_STOREBASEADDRESS1_Pos 6UL
#define JPEGDEC_HF_STORE1BUF0_STOREBASEADDRESS1_Msk 0xFFFFFFC0UL
/* JPEGDEC_HF.STORE1BUF1 */
#define JPEGDEC_HF_STORE1BUF1_STORESTRIDE1_Pos  6UL
#define JPEGDEC_HF_STORE1BUF1_STORESTRIDE1_Msk  0xFFFFFFC0UL
/* JPEGDEC_HF.STORE1BUF2 */
#define JPEGDEC_HF_STORE1BUF2_STORELENGTH1_Pos  6UL
#define JPEGDEC_HF_STORE1BUF2_STORELENGTH1_Msk  0xFFFFFFC0UL
/* JPEGDEC_HF.STORECTL */
#define JPEGDEC_HF_STORECTL_UPSAMPLING_Pos      0UL
#define JPEGDEC_HF_STORECTL_UPSAMPLING_Msk      0x1UL
/* JPEGDEC_HF.CMD */
#define JPEGDEC_HF_CMD_START_Pos                0UL
#define JPEGDEC_HF_CMD_START_Msk                0x1UL
#define JPEGDEC_HF_CMD_RESUME_Pos               8UL
#define JPEGDEC_HF_CMD_RESUME_Msk               0x100UL
/* JPEGDEC_HF.DECODEINTRMASK */
#define JPEGDEC_HF_DECODEINTRMASK_DECODEINTRMASK_Pos 0UL
#define JPEGDEC_HF_DECODEINTRMASK_DECODEINTRMASK_Msk 0x1UL
/* JPEGDEC_HF.INTR */
#define JPEGDEC_HF_INTR_FRAME_COMPLETE_Pos      0UL
#define JPEGDEC_HF_INTR_FRAME_COMPLETE_Msk      0x1UL
#define JPEGDEC_HF_INTR_JPEG_CORE_Pos           8UL
#define JPEGDEC_HF_INTR_JPEG_CORE_Msk           0x100UL
#define JPEGDEC_HF_INTR_FETCH_ERROR_Pos         16UL
#define JPEGDEC_HF_INTR_FETCH_ERROR_Msk         0x10000UL
#define JPEGDEC_HF_INTR_STORE_ERROR_Pos         17UL
#define JPEGDEC_HF_INTR_STORE_ERROR_Msk         0x20000UL
/* JPEGDEC_HF.INTR_SET */
#define JPEGDEC_HF_INTR_SET_FRAME_COMPLETE_SET_Pos 0UL
#define JPEGDEC_HF_INTR_SET_FRAME_COMPLETE_SET_Msk 0x1UL
#define JPEGDEC_HF_INTR_SET_JPEG_CORE_SET_Pos   8UL
#define JPEGDEC_HF_INTR_SET_JPEG_CORE_SET_Msk   0x100UL
#define JPEGDEC_HF_INTR_SET_FETCH_ERROR_SET_Pos 16UL
#define JPEGDEC_HF_INTR_SET_FETCH_ERROR_SET_Msk 0x10000UL
#define JPEGDEC_HF_INTR_SET_STORE_ERROR_SET_Pos 17UL
#define JPEGDEC_HF_INTR_SET_STORE_ERROR_SET_Msk 0x20000UL
/* JPEGDEC_HF.INTR_MASK */
#define JPEGDEC_HF_INTR_MASK_FRAME_COMPLETE_MASK_Pos 0UL
#define JPEGDEC_HF_INTR_MASK_FRAME_COMPLETE_MASK_Msk 0x1UL
#define JPEGDEC_HF_INTR_MASK_JPEG_CORE_MASK_Pos 8UL
#define JPEGDEC_HF_INTR_MASK_JPEG_CORE_MASK_Msk 0x100UL
#define JPEGDEC_HF_INTR_MASK_FETCH_ERROR_MASK_Pos 16UL
#define JPEGDEC_HF_INTR_MASK_FETCH_ERROR_MASK_Msk 0x10000UL
#define JPEGDEC_HF_INTR_MASK_STORE_ERROR_MASK_Pos 17UL
#define JPEGDEC_HF_INTR_MASK_STORE_ERROR_MASK_Msk 0x20000UL
/* JPEGDEC_HF.INTR_MASKED */
#define JPEGDEC_HF_INTR_MASKED_FRAME_COMPLETE_MASKED_Pos 0UL
#define JPEGDEC_HF_INTR_MASKED_FRAME_COMPLETE_MASKED_Msk 0x1UL
#define JPEGDEC_HF_INTR_MASKED_JPEG_CORE_MASKED_Pos 8UL
#define JPEGDEC_HF_INTR_MASKED_JPEG_CORE_MASKED_Msk 0x100UL
#define JPEGDEC_HF_INTR_MASKED_FETCH_ERROR_MASKED_Pos 16UL
#define JPEGDEC_HF_INTR_MASKED_FETCH_ERROR_MASKED_Msk 0x10000UL
#define JPEGDEC_HF_INTR_MASKED_STORE_ERROR_MASKED_Pos 17UL
#define JPEGDEC_HF_INTR_MASKED_STORE_ERROR_MASKED_Msk 0x20000UL
/* JPEGDEC_HF.ERRORSTATUS */
#define JPEGDEC_HF_ERRORSTATUS_ERRORREADAXI_Pos 0UL
#define JPEGDEC_HF_ERRORSTATUS_ERRORREADAXI_Msk 0x3UL
#define JPEGDEC_HF_ERRORSTATUS_ERRORWRITEAXI_Pos 4UL
#define JPEGDEC_HF_ERRORSTATUS_ERRORWRITEAXI_Msk 0x30UL
#define JPEGDEC_HF_ERRORSTATUS_ERRORSTOREOVERLENGTH0_Pos 8UL
#define JPEGDEC_HF_ERRORSTATUS_ERRORSTOREOVERLENGTH0_Msk 0x100UL
#define JPEGDEC_HF_ERRORSTATUS_ERRORSTOREOVERLENGTH1_Pos 12UL
#define JPEGDEC_HF_ERRORSTATUS_ERRORSTOREOVERLENGTH1_Msk 0x1000UL
/* JPEGDEC_HF.OPERATINGSTATUS */
#define JPEGDEC_HF_OPERATINGSTATUS_OPERATIONMODE_Pos 0UL
#define JPEGDEC_HF_OPERATINGSTATUS_OPERATIONMODE_Msk 0x3UL
#define JPEGDEC_HF_OPERATINGSTATUS_FETCHUNITACTIVE_Pos 16UL
#define JPEGDEC_HF_OPERATINGSTATUS_FETCHUNITACTIVE_Msk 0x10000UL
#define JPEGDEC_HF_OPERATINGSTATUS_FETCHAXIACTIVE_Pos 17UL
#define JPEGDEC_HF_OPERATINGSTATUS_FETCHAXIACTIVE_Msk 0x20000UL
#define JPEGDEC_HF_OPERATINGSTATUS_STOREUNITACTIVE_Pos 24UL
#define JPEGDEC_HF_OPERATINGSTATUS_STOREUNITACTIVE_Msk 0x1000000UL
#define JPEGDEC_HF_OPERATINGSTATUS_STOREAXIACTIVE_Pos 25UL
#define JPEGDEC_HF_OPERATINGSTATUS_STOREAXIACTIVE_Msk 0x2000000UL
/* JPEGDEC_HF.FETCHSTATUS */
#define JPEGDEC_HF_FETCHSTATUS_FETCHBYTES_Pos   0UL
#define JPEGDEC_HF_FETCHSTATUS_FETCHBYTES_Msk   0x3FFFFFFFUL
/* JPEGDEC_HF.STORESTATUS */
#define JPEGDEC_HF_STORESTATUS_STOREBYTES_Pos   0UL
#define JPEGDEC_HF_STORESTATUS_STOREBYTES_Msk   0x3FFFFFFFUL


/* JPEGDEC_DEC.IMAGEPROPERTY */
#define JPEGDEC_DEC_IMAGEPROPERTY_SUBSAMPLE_Pos 0UL
#define JPEGDEC_DEC_IMAGEPROPERTY_SUBSAMPLE_Msk 0x7UL
#define JPEGDEC_DEC_IMAGEPROPERTY_ENDIANSTORE_Pos 4UL
#define JPEGDEC_DEC_IMAGEPROPERTY_ENDIANSTORE_Msk 0x10UL
#define JPEGDEC_DEC_IMAGEPROPERTY_ENDIANFETCH_Pos 5UL
#define JPEGDEC_DEC_IMAGEPROPERTY_ENDIANFETCH_Msk 0x20UL
/* JPEGDEC_DEC.SWRESET */
#define JPEGDEC_DEC_SWRESET_CORESTART_RESERVED_Pos 0UL
#define JPEGDEC_DEC_SWRESET_CORESTART_RESERVED_Msk 0x1UL
#define JPEGDEC_DEC_SWRESET_CORERESUME_RESERVED_Pos 1UL
#define JPEGDEC_DEC_SWRESET_CORERESUME_RESERVED_Msk 0x2UL
#define JPEGDEC_DEC_SWRESET_CORERESET_Pos       31UL
#define JPEGDEC_DEC_SWRESET_CORERESET_Msk       0x80000000UL
/* JPEGDEC_DEC.DECODINGSTATUS */
#define JPEGDEC_DEC_DECODINGSTATUS_DECODINGSTATUS_Pos 0UL
#define JPEGDEC_DEC_DECODINGSTATUS_DECODINGSTATUS_Msk 0x1UL
/* JPEGDEC_DEC.QUANTTABLENO */
#define JPEGDEC_DEC_QUANTTABLENO_QT1COLOR_Pos   0UL
#define JPEGDEC_DEC_QUANTTABLENO_QT1COLOR_Msk   0x3UL
#define JPEGDEC_DEC_QUANTTABLENO_QT2COLOR_Pos   2UL
#define JPEGDEC_DEC_QUANTTABLENO_QT2COLOR_Msk   0xCUL
#define JPEGDEC_DEC_QUANTTABLENO_QT3COLOR_Pos   4UL
#define JPEGDEC_DEC_QUANTTABLENO_QT3COLOR_Msk   0x30UL
#define JPEGDEC_DEC_QUANTTABLENO_QT4COLOR_Pos   6UL
#define JPEGDEC_DEC_QUANTTABLENO_QT4COLOR_Msk   0xC0UL
/* JPEGDEC_DEC.HUFFMANTABLENO */
#define JPEGDEC_DEC_HUFFMANTABLENO_HTDC1COLOR_Pos 0UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTDC1COLOR_Msk 0x3UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTAC1COLOR_Pos 2UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTAC1COLOR_Msk 0xCUL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTDC2COLOR_Pos 4UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTDC2COLOR_Msk 0x30UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTAC2COLOR_Pos 6UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTAC2COLOR_Msk 0xC0UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTDC3COLOR_Pos 8UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTDC3COLOR_Msk 0x300UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTAC3COLOR_Pos 10UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTAC3COLOR_Msk 0xC00UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTDC4COLOR_Pos 12UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTDC4COLOR_Msk 0x3000UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTAC4COLOR_Pos 14UL
#define JPEGDEC_DEC_HUFFMANTABLENO_HTAC4COLOR_Msk 0xC000UL
/* JPEGDEC_DEC.DRI */
#define JPEGDEC_DEC_DRI_DRI_Pos                 0UL
#define JPEGDEC_DEC_DRI_DRI_Msk                 0xFFFFUL
/* JPEGDEC_DEC.SIZEY */
#define JPEGDEC_DEC_SIZEY_SIZEY_Pos             0UL
#define JPEGDEC_DEC_SIZEY_SIZEY_Msk             0xFFFFUL
/* JPEGDEC_DEC.SIZEX */
#define JPEGDEC_DEC_SIZEX_SIZEX_Pos             0UL
#define JPEGDEC_DEC_SIZEX_SIZEX_Msk             0xFFFFUL
/* JPEGDEC_DEC.DECODINGOPTION */
#define JPEGDEC_DEC_DECODINGOPTION_MARKERSKIP_Pos 1UL
#define JPEGDEC_DEC_DECODINGOPTION_MARKERSKIP_Msk 0x2UL
#define JPEGDEC_DEC_DECODINGOPTION_CROP_Pos     3UL
#define JPEGDEC_DEC_DECODINGOPTION_CROP_Msk     0x8UL
/* JPEGDEC_DEC.INTR_DEC_EN */
#define JPEGDEC_DEC_INTR_DEC_EN_APPMARKER_Pos   0UL
#define JPEGDEC_DEC_INTR_DEC_EN_APPMARKER_Msk   0x1UL
#define JPEGDEC_DEC_INTR_DEC_EN_COMMARKER_Pos   1UL
#define JPEGDEC_DEC_INTR_DEC_EN_COMMARKER_Msk   0x2UL
#define JPEGDEC_DEC_INTR_DEC_EN_UNKNOWNMARKER_Pos 2UL
#define JPEGDEC_DEC_INTR_DEC_EN_UNKNOWNMARKER_Msk 0x4UL
#define JPEGDEC_DEC_INTR_DEC_EN_SIZEAVAILABLE_Pos 3UL
#define JPEGDEC_DEC_INTR_DEC_EN_SIZEAVAILABLE_Msk 0x8UL
#define JPEGDEC_DEC_INTR_DEC_EN_ERRORINTERVAL_Pos 8UL
#define JPEGDEC_DEC_INTR_DEC_EN_ERRORINTERVAL_Msk 0x100UL
#define JPEGDEC_DEC_INTR_DEC_EN_ERRORTOTALDATA_Pos 9UL
#define JPEGDEC_DEC_INTR_DEC_EN_ERRORTOTALDATA_Msk 0x200UL
#define JPEGDEC_DEC_INTR_DEC_EN_CORRECTION_Pos  10UL
#define JPEGDEC_DEC_INTR_DEC_EN_CORRECTION_Msk  0x400UL
#define JPEGDEC_DEC_INTR_DEC_EN_INTMASK_Pos     31UL
#define JPEGDEC_DEC_INTR_DEC_EN_INTMASK_Msk     0x80000000UL
/* JPEGDEC_DEC.INTR_DEC */
#define JPEGDEC_DEC_INTR_DEC_APPMARKER_Pos      0UL
#define JPEGDEC_DEC_INTR_DEC_APPMARKER_Msk      0x1UL
#define JPEGDEC_DEC_INTR_DEC_COMMARKER_Pos      1UL
#define JPEGDEC_DEC_INTR_DEC_COMMARKER_Msk      0x2UL
#define JPEGDEC_DEC_INTR_DEC_UNKNOWNMARKER_Pos  2UL
#define JPEGDEC_DEC_INTR_DEC_UNKNOWNMARKER_Msk  0x4UL
#define JPEGDEC_DEC_INTR_DEC_SIZEAVAILABLE_Pos  3UL
#define JPEGDEC_DEC_INTR_DEC_SIZEAVAILABLE_Msk  0x8UL
#define JPEGDEC_DEC_INTR_DEC_ERRORINTERVAL_Pos  8UL
#define JPEGDEC_DEC_INTR_DEC_ERRORINTERVAL_Msk  0x100UL
#define JPEGDEC_DEC_INTR_DEC_ERRORTOTALDATA_Pos 9UL
#define JPEGDEC_DEC_INTR_DEC_ERRORTOTALDATA_Msk 0x200UL
#define JPEGDEC_DEC_INTR_DEC_ERRORMARKER_Pos    10UL
#define JPEGDEC_DEC_INTR_DEC_ERRORMARKER_Msk    0x400UL
#define JPEGDEC_DEC_INTR_DEC_CORRECTEDEND_Pos   30UL
#define JPEGDEC_DEC_INTR_DEC_CORRECTEDEND_Msk   0x40000000UL
#define JPEGDEC_DEC_INTR_DEC_NORMALEND_Pos      31UL
#define JPEGDEC_DEC_INTR_DEC_NORMALEND_Msk      0x80000000UL
/* JPEGDEC_DEC.ERRORCODE */
#define JPEGDEC_DEC_ERRORCODE_ERRORCODE_Pos     0UL
#define JPEGDEC_DEC_ERRORCODE_ERRORCODE_Msk     0x3FUL
/* JPEGDEC_DEC.CORRECTIONCROPSTATUS */
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_INTERVAL_Pos 0UL
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_INTERVAL_Msk 0x1UL
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_TOTALSIZE_Pos 1UL
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_TOTALSIZE_Msk 0x2UL
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_CROPEND_Pos 3UL
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_CROPEND_Msk 0x8UL
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_CROPSIZEERROR_Pos 4UL
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_CROPSIZEERROR_Msk 0x10UL
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_MCUUNITERROR_Pos 5UL
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_MCUUNITERROR_Msk 0x20UL
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_NODRI_Pos 6UL
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_NODRI_Msk 0x40UL
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_NORST_Pos 7UL
#define JPEGDEC_DEC_CORRECTIONCROPSTATUS_NORST_Msk 0x80UL
/* JPEGDEC_DEC.SUSPEND */
#define JPEGDEC_DEC_SUSPEND_SUSPEND_Pos         0UL
#define JPEGDEC_DEC_SUSPEND_SUSPEND_Msk         0x1UL
/* JPEGDEC_DEC.DNL */
#define JPEGDEC_DEC_DNL_DNL_Pos                 0UL
#define JPEGDEC_DEC_DNL_DNL_Msk                 0xFFFFUL
/* JPEGDEC_DEC.CROPSTARTY */
#define JPEGDEC_DEC_CROPSTARTY_CROPSTARTY_Pos   0UL
#define JPEGDEC_DEC_CROPSTARTY_CROPSTARTY_Msk   0xFFFFUL
/* JPEGDEC_DEC.CROPSTARTX */
#define JPEGDEC_DEC_CROPSTARTX_CROPSTARTX_Pos   0UL
#define JPEGDEC_DEC_CROPSTARTX_CROPSTARTX_Msk   0xFFFFUL
/* JPEGDEC_DEC.CROPSIZEY */
#define JPEGDEC_DEC_CROPSIZEY_CROPSIZEY_Pos     0UL
#define JPEGDEC_DEC_CROPSIZEY_CROPSIZEY_Msk     0xFFFFUL
/* JPEGDEC_DEC.CROPSIZEX */
#define JPEGDEC_DEC_CROPSIZEX_CROPSIZEX_Pos     0UL
#define JPEGDEC_DEC_CROPSIZEX_CROPSIZEX_Msk     0xFFFFUL
/* JPEGDEC_DEC.QUANTTABLE0 */
#define JPEGDEC_DEC_QUANTTABLE0_QT0CONTENT0_Pos 0UL
#define JPEGDEC_DEC_QUANTTABLE0_QT0CONTENT0_Msk 0xFFUL
#define JPEGDEC_DEC_QUANTTABLE0_QT0CONTENT1_Pos 16UL
#define JPEGDEC_DEC_QUANTTABLE0_QT0CONTENT1_Msk 0xFF0000UL
/* JPEGDEC_DEC.QUANTTABLE1 */
#define JPEGDEC_DEC_QUANTTABLE1_QT1CONTENT0_Pos 0UL
#define JPEGDEC_DEC_QUANTTABLE1_QT1CONTENT0_Msk 0xFFUL
#define JPEGDEC_DEC_QUANTTABLE1_QT1CONTENT1_Pos 16UL
#define JPEGDEC_DEC_QUANTTABLE1_QT1CONTENT1_Msk 0xFF0000UL
/* JPEGDEC_DEC.QUANTTABLE2 */
#define JPEGDEC_DEC_QUANTTABLE2_QT2CONTENT0_Pos 0UL
#define JPEGDEC_DEC_QUANTTABLE2_QT2CONTENT0_Msk 0xFFUL
#define JPEGDEC_DEC_QUANTTABLE2_QT2CONTENT1_Pos 16UL
#define JPEGDEC_DEC_QUANTTABLE2_QT2CONTENT1_Msk 0xFF0000UL
/* JPEGDEC_DEC.QUANTTABLE3 */
#define JPEGDEC_DEC_QUANTTABLE3_QT3CONTENT0_Pos 0UL
#define JPEGDEC_DEC_QUANTTABLE3_QT3CONTENT0_Msk 0xFFUL
#define JPEGDEC_DEC_QUANTTABLE3_QT3CONTENT1_Pos 16UL
#define JPEGDEC_DEC_QUANTTABLE3_QT3CONTENT1_Msk 0xFF0000UL
/* JPEGDEC_DEC.HUFFMANTABLEDC0CODELENGTH */
#define JPEGDEC_DEC_HUFFMANTABLEDC0CODELENGTH_DC0NUMCODELENGTHN_Pos 0UL
#define JPEGDEC_DEC_HUFFMANTABLEDC0CODELENGTH_DC0NUMCODELENGTHN_Msk 0xFFFFFFFFUL
/* JPEGDEC_DEC.HUFFMANTABLEDC0GROUPNO */
#define JPEGDEC_DEC_HUFFMANTABLEDC0GROUPNO_DC0GROUPNO_Pos 0UL
#define JPEGDEC_DEC_HUFFMANTABLEDC0GROUPNO_DC0GROUPNO_Msk 0xFFFFFFFFUL
/* JPEGDEC_DEC.HUFFMANTABLEAC0CODELENGTH */
#define JPEGDEC_DEC_HUFFMANTABLEAC0CODELENGTH_AC0NUMCODELENGTHN_Pos 0UL
#define JPEGDEC_DEC_HUFFMANTABLEAC0CODELENGTH_AC0NUMCODELENGTHN_Msk 0xFFFFFFFFUL
/* JPEGDEC_DEC.HUFFMANTABLEAC0GROUPNO */
#define JPEGDEC_DEC_HUFFMANTABLEAC0GROUPNO_AC0GROUPNO_Pos 0UL
#define JPEGDEC_DEC_HUFFMANTABLEAC0GROUPNO_AC0GROUPNO_Msk 0xFFFFFFFFUL
/* JPEGDEC_DEC.HUFFMANTABLEDC1CODELENGTH */
#define JPEGDEC_DEC_HUFFMANTABLEDC1CODELENGTH_DC1NUMCODELENGTHN_Pos 0UL
#define JPEGDEC_DEC_HUFFMANTABLEDC1CODELENGTH_DC1NUMCODELENGTHN_Msk 0xFFFFFFFFUL
/* JPEGDEC_DEC.HUFFMANTABLEDC1GROUPNO */
#define JPEGDEC_DEC_HUFFMANTABLEDC1GROUPNO_DC1GROUPNO_Pos 0UL
#define JPEGDEC_DEC_HUFFMANTABLEDC1GROUPNO_DC1GROUPNO_Msk 0xFFFFFFFFUL
/* JPEGDEC_DEC.HUFFMANTABLEAC1CODELENGTH */
#define JPEGDEC_DEC_HUFFMANTABLEAC1CODELENGTH_AC1NUMCODELENGTHN_Pos 0UL
#define JPEGDEC_DEC_HUFFMANTABLEAC1CODELENGTH_AC1NUMCODELENGTHN_Msk 0xFFFFFFFFUL
/* JPEGDEC_DEC.HUFFMANTABLEAC1GROUPNO */
#define JPEGDEC_DEC_HUFFMANTABLEAC1GROUPNO_AC1GROUPNO_Pos 0UL
#define JPEGDEC_DEC_HUFFMANTABLEAC1GROUPNO_AC1GROUPNO_Msk 0xFFFFFFFFUL


/* JPEGDEC.CTL */
#define JPEGDEC_CTL_ENABLED_Pos                 31UL
#define JPEGDEC_CTL_ENABLED_Msk                 0x80000000UL


#endif /* _CYIP_JPEGDEC_H_ */


/* [] END OF FILE */
