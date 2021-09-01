/***************************************************************************//**
* \file cyreg_smartio.h
*
* \brief
* SMARTIO register definition header
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

#ifndef _CYREG_SMARTIO_H_
#define _CYREG_SMARTIO_H_

#include "cyip_smartio_v5.h"

/**
  * \brief Programmable IO port registers (SMARTIO_PRT8)
  */
#define CYREG_SMARTIO_PRT8_CTL          ((volatile un_SMARTIO_PRT_CTL_t*) 0x40320800UL)
#define CYREG_SMARTIO_PRT8_SYNC_CTL     ((volatile un_SMARTIO_PRT_SYNC_CTL_t*) 0x40320810UL)
#define CYREG_SMARTIO_PRT8_LUT_SEL0     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320820UL)
#define CYREG_SMARTIO_PRT8_LUT_SEL1     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320824UL)
#define CYREG_SMARTIO_PRT8_LUT_SEL2     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320828UL)
#define CYREG_SMARTIO_PRT8_LUT_SEL3     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x4032082CUL)
#define CYREG_SMARTIO_PRT8_LUT_SEL4     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320830UL)
#define CYREG_SMARTIO_PRT8_LUT_SEL5     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320834UL)
#define CYREG_SMARTIO_PRT8_LUT_SEL6     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320838UL)
#define CYREG_SMARTIO_PRT8_LUT_SEL7     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x4032083CUL)
#define CYREG_SMARTIO_PRT8_LUT_CTL0     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320840UL)
#define CYREG_SMARTIO_PRT8_LUT_CTL1     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320844UL)
#define CYREG_SMARTIO_PRT8_LUT_CTL2     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320848UL)
#define CYREG_SMARTIO_PRT8_LUT_CTL3     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x4032084CUL)
#define CYREG_SMARTIO_PRT8_LUT_CTL4     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320850UL)
#define CYREG_SMARTIO_PRT8_LUT_CTL5     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320854UL)
#define CYREG_SMARTIO_PRT8_LUT_CTL6     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320858UL)
#define CYREG_SMARTIO_PRT8_LUT_CTL7     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x4032085CUL)
#define CYREG_SMARTIO_PRT8_DU_SEL       ((volatile un_SMARTIO_PRT_DU_SEL_t*) 0x403208C0UL)
#define CYREG_SMARTIO_PRT8_DU_CTL       ((volatile un_SMARTIO_PRT_DU_CTL_t*) 0x403208C4UL)
#define CYREG_SMARTIO_PRT8_DATA         ((volatile un_SMARTIO_PRT_DATA_t*) 0x403208F0UL)

#endif /* _CYREG_SMARTIO_H_ */


/* [] END OF FILE */
