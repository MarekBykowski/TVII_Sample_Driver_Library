/***************************************************************************//**
* \file cyreg_smartio.h
*
* \brief
* SMARTIO register definition header
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

#ifndef _CYREG_SMARTIO_H_
#define _CYREG_SMARTIO_H_

#include "cyip_smartio_v5.h"

/**
  * \brief Programmable IO port registers (SMARTIO_PRT9)
  */
#define CYREG_SMARTIO_PRT9_CTL          ((volatile un_SMARTIO_PRT_CTL_t*) 0x40320900UL)
#define CYREG_SMARTIO_PRT9_SYNC_CTL     ((volatile un_SMARTIO_PRT_SYNC_CTL_t*) 0x40320910UL)
#define CYREG_SMARTIO_PRT9_LUT_SEL0     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320920UL)
#define CYREG_SMARTIO_PRT9_LUT_SEL1     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320924UL)
#define CYREG_SMARTIO_PRT9_LUT_SEL2     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320928UL)
#define CYREG_SMARTIO_PRT9_LUT_SEL3     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x4032092CUL)
#define CYREG_SMARTIO_PRT9_LUT_SEL4     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320930UL)
#define CYREG_SMARTIO_PRT9_LUT_SEL5     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320934UL)
#define CYREG_SMARTIO_PRT9_LUT_SEL6     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320938UL)
#define CYREG_SMARTIO_PRT9_LUT_SEL7     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x4032093CUL)
#define CYREG_SMARTIO_PRT9_LUT_CTL0     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320940UL)
#define CYREG_SMARTIO_PRT9_LUT_CTL1     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320944UL)
#define CYREG_SMARTIO_PRT9_LUT_CTL2     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320948UL)
#define CYREG_SMARTIO_PRT9_LUT_CTL3     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x4032094CUL)
#define CYREG_SMARTIO_PRT9_LUT_CTL4     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320950UL)
#define CYREG_SMARTIO_PRT9_LUT_CTL5     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320954UL)
#define CYREG_SMARTIO_PRT9_LUT_CTL6     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320958UL)
#define CYREG_SMARTIO_PRT9_LUT_CTL7     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x4032095CUL)
#define CYREG_SMARTIO_PRT9_DU_SEL       ((volatile un_SMARTIO_PRT_DU_SEL_t*) 0x403209C0UL)
#define CYREG_SMARTIO_PRT9_DU_CTL       ((volatile un_SMARTIO_PRT_DU_CTL_t*) 0x403209C4UL)
#define CYREG_SMARTIO_PRT9_DATA         ((volatile un_SMARTIO_PRT_DATA_t*) 0x403209F0UL)

#endif /* _CYREG_SMARTIO_H_ */


/* [] END OF FILE */
