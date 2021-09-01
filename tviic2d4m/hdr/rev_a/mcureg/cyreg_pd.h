/***************************************************************************//**
* \file cyreg_pd.h
*
* \brief
* PD register definition header
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

#ifndef _CYREG_PD_H_
#define _CYREG_PD_H_

#include "cyip_pd.h"

/**
  * \brief Power Domain and Switch Block (PD)
  */
#define CYREG_PD_CTL                    ((volatile un_PD_CTL_t*) 0x40B00000UL)
#define CYREG_PD_STATUS                 ((volatile un_PD_STATUS_t*) 0x40B00010UL)
#define CYREG_PD_TRIM                   ((volatile un_PD_TRIM_t*) 0x40B00080UL)

#endif /* _CYREG_PD_H_ */


/* [] END OF FILE */
