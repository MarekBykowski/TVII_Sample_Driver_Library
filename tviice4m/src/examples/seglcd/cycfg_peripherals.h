/*******************************************************************************
* File Name: cycfg_peripherals.h
* Version 1.20
*
* Description:
* LCD Port Assignment
*
********************************************************************************
* \copyright
* Copyright 2018-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(H_CYCFG_LCDPERIPHERAL)
#define H_CYCFG_LCDPERIPHERAL

#include <stdbool.h>
#include <stddef.h>

#include "syslib/cy_syslib.h"
#include "seglcd/cy_seglcd.h"

#define SegLCD_HW               LCD0
#define SegLCD_SEG_NUM          32
#define SegLCD_COM_NUM          4

#define SegLCD_COM_0		10
#define SegLCD_COM_1		11
#define SegLCD_COM_2		12
#define SegLCD_COM_3		13

#define SegLCD_SEG_0		1
#define SegLCD_SEG_1		2
#define SegLCD_SEG_2		3
#define SegLCD_SEG_3		4
#define SegLCD_SEG_4		1
#define SegLCD_SEG_5		2
#define SegLCD_SEG_6		3
#define SegLCD_SEG_7		4
#define SegLCD_SEG_8		1
#define SegLCD_SEG_9		2
#define SegLCD_SEG_10		3
#define SegLCD_SEG_11		4
#define SegLCD_SEG_12		1
#define SegLCD_SEG_13		2
#define SegLCD_SEG_14		3
#define SegLCD_SEG_15		4
#define SegLCD_SEG_16		1
#define SegLCD_SEG_17		2
#define SegLCD_SEG_18		3
#define SegLCD_SEG_19		4
#define SegLCD_SEG_20		1
#define SegLCD_SEG_21		2
#define SegLCD_SEG_22		3
#define SegLCD_SEG_23		4
#define SegLCD_SEG_24		1
#define SegLCD_SEG_25		2
#define SegLCD_SEG_26		3
#define SegLCD_SEG_27		4
#define SegLCD_SEG_28		1
#define SegLCD_SEG_29		2
#define SegLCD_SEG_30		3
#define SegLCD_SEG_31		4

#define SegLCD_CONST_MODIFIER   const

#endif /* H_CYCFG_LCDPERIPHERAL */

/* [] END OF FILE */

