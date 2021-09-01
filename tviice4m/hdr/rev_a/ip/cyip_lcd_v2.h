/***************************************************************************//**
* \file cyip_lcd_v2.h
*
* \brief
* LCD IP definitions
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

#ifndef _CYIP_LCD_V2_H_
#define _CYIP_LCD_V2_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     LCD
*******************************************************************************/

#define LCD_SECTION_SIZE                        0x00010000UL

/**
  * \brief ID & Revision (LCD_ID)
  */
typedef struct stc_LCD_ID_field {
  uint32_t                         u16ID:16;
  uint32_t                         u16REVISION:16;
} stc_LCD_ID_field_t;

typedef union un_LCD_ID {
  uint32_t                         u32Register;
  stc_LCD_ID_field_t               stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LCD_ID_t;

/**
  * \brief LCD Divider Register (LCD_DIVIDER)
  */
typedef struct stc_LCD_DIVIDER_field {
  uint32_t                         u16SUBFR_DIV:16;
  uint32_t                         u16DEAD_DIV:16;
} stc_LCD_DIVIDER_field_t;

typedef union un_LCD_DIVIDER {
  uint32_t                         u32Register;
  stc_LCD_DIVIDER_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LCD_DIVIDER_t;

/**
  * \brief LCD Configuration Register (LCD_CONTROL)
  */
typedef struct stc_LCD_CONTROL_field {
  uint32_t                         u1LS_EN:1;
  uint32_t                         u1HS_EN:1;
  uint32_t                         u1LCD_MODE:1;
  uint32_t                         u1TYPE:1;
  uint32_t                         u1OP_MODE:1;
  uint32_t                         u2BIAS:2;
  uint32_t                         u1CLOCK_LS_SEL:1;
  uint32_t                         u4COM_NUM:4;
  uint32_t                         :19;
  uint32_t                         u1LS_EN_STAT:1;
} stc_LCD_CONTROL_field_t;

typedef union un_LCD_CONTROL {
  uint32_t                         u32Register;
  stc_LCD_CONTROL_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LCD_CONTROL_t;

/**
  * \brief LCD Pin Data Registers (LCD_DATA0)
  */
typedef struct stc_LCD_DATA0_field {
  uint32_t                         u32DATA:32;
} stc_LCD_DATA0_field_t;

typedef union un_LCD_DATA0 {
  uint32_t                         u32Register;
  stc_LCD_DATA0_field_t            stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LCD_DATA0_t;

/**
  * \brief LCD Pin Data Registers (LCD_DATA1)
  */
typedef struct stc_LCD_DATA1_field {
  uint32_t                         u32DATA:32;
} stc_LCD_DATA1_field_t;

typedef union un_LCD_DATA1 {
  uint32_t                         u32Register;
  stc_LCD_DATA1_field_t            stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LCD_DATA1_t;

/**
  * \brief LCD Pin Data Registers (LCD_DATA2)
  */
typedef struct stc_LCD_DATA2_field {
  uint32_t                         u32DATA:32;
} stc_LCD_DATA2_field_t;

typedef union un_LCD_DATA2 {
  uint32_t                         u32Register;
  stc_LCD_DATA2_field_t            stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LCD_DATA2_t;

/**
  * \brief LCD Pin Data Registers (LCD_DATA3)
  */
typedef struct stc_LCD_DATA3_field {
  uint32_t                         u32DATA:32;
} stc_LCD_DATA3_field_t;

typedef union un_LCD_DATA3 {
  uint32_t                         u32Register;
  stc_LCD_DATA3_field_t            stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_LCD_DATA3_t;



/**
  * \brief LCD Controller Block (LCD)
  */
typedef struct stc_LCD {
  un_LCD_ID_t                      unID;               /*!< 0x00000000 ID & Revision */
  un_LCD_DIVIDER_t                 unDIVIDER;          /*!< 0x00000004 LCD Divider Register */
  un_LCD_CONTROL_t                 unCONTROL;          /*!< 0x00000008 LCD Configuration Register */
  uint32_t                         au32Reserved[61];
  un_LCD_DATA0_t                   unDATA0[8];         /*!< 0x00000100 LCD Pin Data Registers */
  uint32_t                         au32Reserved1[56];
  un_LCD_DATA1_t                   unDATA1[8];         /*!< 0x00000200 LCD Pin Data Registers */
  uint32_t                         au32Reserved2[56];
  un_LCD_DATA2_t                   unDATA2[8];         /*!< 0x00000300 LCD Pin Data Registers */
  uint32_t                         au32Reserved3[56];
  un_LCD_DATA3_t                   unDATA3[8];         /*!< 0x00000400 LCD Pin Data Registers */
} stc_LCD_t;                                           /*!< Size = 1056 (0x420) */


/* LCD.ID */
#define LCD_ID_ID_Pos                           0UL
#define LCD_ID_ID_Msk                           0xFFFFUL
#define LCD_ID_REVISION_Pos                     16UL
#define LCD_ID_REVISION_Msk                     0xFFFF0000UL
/* LCD.DIVIDER */
#define LCD_DIVIDER_SUBFR_DIV_Pos               0UL
#define LCD_DIVIDER_SUBFR_DIV_Msk               0xFFFFUL
#define LCD_DIVIDER_DEAD_DIV_Pos                16UL
#define LCD_DIVIDER_DEAD_DIV_Msk                0xFFFF0000UL
/* LCD.CONTROL */
#define LCD_CONTROL_LS_EN_Pos                   0UL
#define LCD_CONTROL_LS_EN_Msk                   0x1UL
#define LCD_CONTROL_HS_EN_Pos                   1UL
#define LCD_CONTROL_HS_EN_Msk                   0x2UL
#define LCD_CONTROL_LCD_MODE_Pos                2UL
#define LCD_CONTROL_LCD_MODE_Msk                0x4UL
#define LCD_CONTROL_TYPE_Pos                    3UL
#define LCD_CONTROL_TYPE_Msk                    0x8UL
#define LCD_CONTROL_OP_MODE_Pos                 4UL
#define LCD_CONTROL_OP_MODE_Msk                 0x10UL
#define LCD_CONTROL_BIAS_Pos                    5UL
#define LCD_CONTROL_BIAS_Msk                    0x60UL
#define LCD_CONTROL_CLOCK_LS_SEL_Pos            7UL
#define LCD_CONTROL_CLOCK_LS_SEL_Msk            0x80UL
#define LCD_CONTROL_COM_NUM_Pos                 8UL
#define LCD_CONTROL_COM_NUM_Msk                 0xF00UL
#define LCD_CONTROL_LS_EN_STAT_Pos              31UL
#define LCD_CONTROL_LS_EN_STAT_Msk              0x80000000UL
/* LCD.DATA0 */
#define LCD_DATA0_DATA_Pos                      0UL
#define LCD_DATA0_DATA_Msk                      0xFFFFFFFFUL
/* LCD.DATA1 */
#define LCD_DATA1_DATA_Pos                      0UL
#define LCD_DATA1_DATA_Msk                      0xFFFFFFFFUL
/* LCD.DATA2 */
#define LCD_DATA2_DATA_Pos                      0UL
#define LCD_DATA2_DATA_Msk                      0xFFFFFFFFUL
/* LCD.DATA3 */
#define LCD_DATA3_DATA_Pos                      0UL
#define LCD_DATA3_DATA_Msk                      0xFFFFFFFFUL


#endif /* _CYIP_LCD_V2_H_ */


/* [] END OF FILE */
