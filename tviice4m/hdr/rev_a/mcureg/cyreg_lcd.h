/***************************************************************************//**
* \file cyreg_lcd.h
*
* \brief
* LCD register definition header
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

#ifndef _CYREG_LCD_H_
#define _CYREG_LCD_H_

#include "cyip_lcd_v2.h"

/**
  * \brief LCD Controller Block (LCD)
  */
#define CYREG_LCD0_ID                   ((volatile un_LCD_ID_t*) 0x403B0000UL)
#define CYREG_LCD0_DIVIDER              ((volatile un_LCD_DIVIDER_t*) 0x403B0004UL)
#define CYREG_LCD0_CONTROL              ((volatile un_LCD_CONTROL_t*) 0x403B0008UL)
#define CYREG_LCD0_DATA00               ((volatile un_LCD_DATA0_t*) 0x403B0100UL)
#define CYREG_LCD0_DATA01               ((volatile un_LCD_DATA0_t*) 0x403B0104UL)
#define CYREG_LCD0_DATA02               ((volatile un_LCD_DATA0_t*) 0x403B0108UL)
#define CYREG_LCD0_DATA03               ((volatile un_LCD_DATA0_t*) 0x403B010CUL)
#define CYREG_LCD0_DATA04               ((volatile un_LCD_DATA0_t*) 0x403B0110UL)

#endif /* _CYREG_LCD_H_ */


/* [] END OF FILE */
