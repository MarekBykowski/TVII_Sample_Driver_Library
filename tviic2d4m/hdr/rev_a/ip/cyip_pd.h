/***************************************************************************//**
* \file cyip_pd.h
*
* \brief
* PD IP definitions
*
* \note
* Generator version: 1.6.0.264
* Database revision: TVIIC2D4M_A0
*
********************************************************************************
* \copyright
* Copyright 2016-2020, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYIP_PD_H_
#define _CYIP_PD_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                      PD
*******************************************************************************/

#define PD_SECTION_SIZE                         0x00000400UL

/**
  * \brief Power Domain Control (PD_CTL)
  */
typedef struct stc_PD_CTL_field {
  uint32_t                         u2PWR_MODE:2;
  uint32_t                         :30;
} stc_PD_CTL_field_t;

typedef union un_PD_CTL {
  uint32_t                         u32Register;
  stc_PD_CTL_field_t               stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PD_CTL_t;

/**
  * \brief Power Domain Status (PD_STATUS)
  */
typedef struct stc_PD_STATUS_field {
  uint32_t                         :4;
  uint32_t                         u1PWR_DONE:1;
  uint32_t                         :27;
} stc_PD_STATUS_field_t;

typedef union un_PD_STATUS {
  uint32_t                         u32Register;
  stc_PD_STATUS_field_t            stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PD_STATUS_t;

/**
  * \brief Power Switch Trim (PD_TRIM)
  */
typedef struct stc_PD_TRIM_field {
  uint32_t                         u2PWRSW_WAIT_CNT:2;
  uint32_t                         :30;
} stc_PD_TRIM_field_t;

typedef union un_PD_TRIM {
  uint32_t                         u32Register;
  stc_PD_TRIM_field_t              stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PD_TRIM_t;



/**
  * \brief Power Domain and Switch Block (PD)
  */
typedef struct stc_PD {
  un_PD_CTL_t                      unCTL;              /*!< 0x00000000 Power Domain Control */
  uint32_t                         au32Reserved[3];
  un_PD_STATUS_t                   unSTATUS;           /*!< 0x00000010 Power Domain Status */
  uint32_t                         au32Reserved1[27];
  un_PD_TRIM_t                     unTRIM;             /*!< 0x00000080 Power Switch Trim */
} stc_PD_t;                                            /*!< Size = 132 (0x84) */


/* PD.CTL */
#define PD_CTL_PWR_MODE_Pos                     0UL
#define PD_CTL_PWR_MODE_Msk                     0x3UL
/* PD.STATUS */
#define PD_STATUS_PWR_DONE_Pos                  4UL
#define PD_STATUS_PWR_DONE_Msk                  0x10UL
/* PD.TRIM */
#define PD_TRIM_PWRSW_WAIT_CNT_Pos              0UL
#define PD_TRIM_PWRSW_WAIT_CNT_Msk              0x3UL


#endif /* _CYIP_PD_H_ */


/* [] END OF FILE */
