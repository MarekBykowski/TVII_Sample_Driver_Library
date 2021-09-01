/*******************************************************************************
* File Name: cycfg_seglcd.h
* Version 1.20
*
* Description:
* SegLCD display configuration
* This file should not be modified. It was automatically generated by
* Segment LCD Configurator 1.20.0.3158
*
********************************************************************************
* \copyright
* Copyright 2018-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(H_CYCFG_SEGLCD)
#define H_CYCFG_SEGLCD

#include "cycfg_peripherals.h"

#define CY_SEGLCD_CFG_TOOL_VERSION      (120)

/* Supported SegLCD Driver version */
#define CY_SEGLCD_DRV_VERSION_REQUIRED  (100)

#if !defined (CY_SEGLCD_DRV_VERSION)
    #define CY_SEGLCD_DRV_VERSION       (100)
#endif

/* Check the used Driver version */
#if (CY_SEGLCD_DRV_VERSION_REQUIRED > CY_SEGLCD_DRV_VERSION)
    #error The Segment LCD Configurator requires a newer version of the PDL. Update the PDL in your project.
#endif

#if !defined(SegLCD_HW)
    #error The SegLCD Device peripheral Alias expected name is 'SegLCD'. Change Alias to 'SegLCD' or run the SegLCD Configurator using the Device Configurator and save configuration.
#endif /* !defined(SegLCD_HW) */

#if !defined(SegLCD_SEG_NUM) || (SegLCD_SEG_NUM != 32)
    #error The SegLCD Device peripheral expected 32 segments. Run the SegLCD Configurator using the Device Configurator and save configuration.
#endif /* !defined(SegLCD_SEG_NUM) || (SegLCD_SEG_NUM != 32) */

#if !defined(SegLCD_COM_NUM) || (SegLCD_COM_NUM != 4)
    #error The SegLCD Device peripheral expected 4 commons. Run the SegLCD Configurator using the Device Configurator and save configuration.
#endif /* !defined(SegLCD_COM_NUM) || (SegLCD_COM_NUM != 4) */

#if !defined(SegLCD_COM_0)
    #error Common is not assigned: missing #define SegLCD_COM_0
#endif /* !defined(SegLCD_COM_0) */
#if !defined(SegLCD_COM_1)
    #error Common is not assigned: missing #define SegLCD_COM_1
#endif /* !defined(SegLCD_COM_1) */
#if !defined(SegLCD_COM_2)
    #error Common is not assigned: missing #define SegLCD_COM_2
#endif /* !defined(SegLCD_COM_2) */
#if !defined(SegLCD_COM_3)
    #error Common is not assigned: missing #define SegLCD_COM_3
#endif /* !defined(SegLCD_COM_3) */
#if !defined(SegLCD_SEG_0)
    #error Segment is not assigned: missing #define SegLCD_SEG_0
#endif /* !defined(SegLCD_SEG_0) */
#if !defined(SegLCD_SEG_1)
    #error Segment is not assigned: missing #define SegLCD_SEG_1
#endif /* !defined(SegLCD_SEG_1) */
#if !defined(SegLCD_SEG_2)
    #error Segment is not assigned: missing #define SegLCD_SEG_2
#endif /* !defined(SegLCD_SEG_2) */
#if !defined(SegLCD_SEG_3)
    #error Segment is not assigned: missing #define SegLCD_SEG_3
#endif /* !defined(SegLCD_SEG_3) */
#if !defined(SegLCD_SEG_4)
    #error Segment is not assigned: missing #define SegLCD_SEG_4
#endif /* !defined(SegLCD_SEG_4) */
#if !defined(SegLCD_SEG_5)
    #error Segment is not assigned: missing #define SegLCD_SEG_5
#endif /* !defined(SegLCD_SEG_5) */
#if !defined(SegLCD_SEG_6)
    #error Segment is not assigned: missing #define SegLCD_SEG_6
#endif /* !defined(SegLCD_SEG_6) */
#if !defined(SegLCD_SEG_7)
    #error Segment is not assigned: missing #define SegLCD_SEG_7
#endif /* !defined(SegLCD_SEG_7) */
#if !defined(SegLCD_SEG_8)
    #error Segment is not assigned: missing #define SegLCD_SEG_8
#endif /* !defined(SegLCD_SEG_8) */
#if !defined(SegLCD_SEG_9)
    #error Segment is not assigned: missing #define SegLCD_SEG_9
#endif /* !defined(SegLCD_SEG_9) */
#if !defined(SegLCD_SEG_10)
    #error Segment is not assigned: missing #define SegLCD_SEG_10
#endif /* !defined(SegLCD_SEG_10) */
#if !defined(SegLCD_SEG_11)
    #error Segment is not assigned: missing #define SegLCD_SEG_11
#endif /* !defined(SegLCD_SEG_11) */
#if !defined(SegLCD_SEG_12)
    #error Segment is not assigned: missing #define SegLCD_SEG_12
#endif /* !defined(SegLCD_SEG_12) */
#if !defined(SegLCD_SEG_13)
    #error Segment is not assigned: missing #define SegLCD_SEG_13
#endif /* !defined(SegLCD_SEG_13) */
#if !defined(SegLCD_SEG_14)
    #error Segment is not assigned: missing #define SegLCD_SEG_14
#endif /* !defined(SegLCD_SEG_14) */
#if !defined(SegLCD_SEG_15)
    #error Segment is not assigned: missing #define SegLCD_SEG_15
#endif /* !defined(SegLCD_SEG_15) */
#if !defined(SegLCD_SEG_16)
    #error Segment is not assigned: missing #define SegLCD_SEG_16
#endif /* !defined(SegLCD_SEG_16) */
#if !defined(SegLCD_SEG_17)
    #error Segment is not assigned: missing #define SegLCD_SEG_17
#endif /* !defined(SegLCD_SEG_17) */
#if !defined(SegLCD_SEG_18)
    #error Segment is not assigned: missing #define SegLCD_SEG_18
#endif /* !defined(SegLCD_SEG_18) */
#if !defined(SegLCD_SEG_19)
    #error Segment is not assigned: missing #define SegLCD_SEG_19
#endif /* !defined(SegLCD_SEG_19) */
#if !defined(SegLCD_SEG_20)
    #error Segment is not assigned: missing #define SegLCD_SEG_20
#endif /* !defined(SegLCD_SEG_20) */
#if !defined(SegLCD_SEG_21)
    #error Segment is not assigned: missing #define SegLCD_SEG_21
#endif /* !defined(SegLCD_SEG_21) */
#if !defined(SegLCD_SEG_22)
    #error Segment is not assigned: missing #define SegLCD_SEG_22
#endif /* !defined(SegLCD_SEG_22) */
#if !defined(SegLCD_SEG_23)
    #error Segment is not assigned: missing #define SegLCD_SEG_23
#endif /* !defined(SegLCD_SEG_23) */
#if !defined(SegLCD_SEG_24)
    #error Segment is not assigned: missing #define SegLCD_SEG_24
#endif /* !defined(SegLCD_SEG_24) */
#if !defined(SegLCD_SEG_25)
    #error Segment is not assigned: missing #define SegLCD_SEG_25
#endif /* !defined(SegLCD_SEG_25) */
#if !defined(SegLCD_SEG_26)
    #error Segment is not assigned: missing #define SegLCD_SEG_26
#endif /* !defined(SegLCD_SEG_26) */
#if !defined(SegLCD_SEG_27)
    #error Segment is not assigned: missing #define SegLCD_SEG_27
#endif /* !defined(SegLCD_SEG_27) */
#if !defined(SegLCD_SEG_28)
    #error Segment is not assigned: missing #define SegLCD_SEG_28
#endif /* !defined(SegLCD_SEG_28) */
#if !defined(SegLCD_SEG_29)
    #error Segment is not assigned: missing #define SegLCD_SEG_29
#endif /* !defined(SegLCD_SEG_29) */
#if !defined(SegLCD_SEG_30)
    #error Segment is not assigned: missing #define SegLCD_SEG_30
#endif /* !defined(SegLCD_SEG_30) */
#if !defined(SegLCD_SEG_31)
    #error Segment is not assigned: missing #define SegLCD_SEG_31
#endif /* !defined(SegLCD_SEG_31) */

#if defined(__cplusplus)
extern "C" {
#endif


#define SegLCD_Display0_TYPE    ((uint32_t)CY_SEGLCD_7SEG)
#define SegLCD_Display0_SYM_NUM (4UL)

extern SegLCD_CONST_MODIFIER uint32_t SegLCD_commons[SegLCD_COM_NUM];

extern SegLCD_CONST_MODIFIER cy_stc_seglcd_disp_t SegLCD_Display0;


#if defined(__cplusplus)
}
#endif

#endif /* H_CYCFG_SEGLCD */

/* [] END OF FILE */
