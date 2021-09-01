/*******************************************************************************
* \file cy_syspmic.h
* \version 1.0
*
* Provides an API declaration of the system PMIC driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
/**
* \defgroup group_syspmic Power Management (SysPMIC)
* \{
* This driver provides global SysPMIC defines and API function definitions.
*
* \defgroup group_syspmic_macros Macro
* \defgroup group_syspmic_functions Functions
* \defgroup group_syspmic_data_structures Data structures
* \defgroup group_syspmic_enums Enumerated types
*/

#if !defined(__CY_SYSPMIC_H__)
#define __CY_SYSPMIC_H__

#include "cy_device_headers.h"
#include <stdbool.h>

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
* \addtogroup group_syspmic_macros
* \{
*/
/** Driver major version */
#define  CY_SYSPMIC_DRV_VERSION_MAJOR   1
/** Driver minor version */
#define  CY_SYSPMIC_DRV_VERSION_MINOR   0
/** \} group_syspmic_macros */

/**
* \addtogroup group_syspmic_enums
* \{
*/
/** This enumeration is used to set the voltage trims */
typedef enum
{
    CY_SYSPMIC_VADJ_1V040 =  3u,
    CY_SYSPMIC_VADJ_1V049 =  4u,
    CY_SYSPMIC_VADJ_1V057 =  5u,
    CY_SYSPMIC_VADJ_1V066 =  6u,
    CY_SYSPMIC_VADJ_1V074 =  7u,
    CY_SYSPMIC_VADJ_1V083 =  8u,
    CY_SYSPMIC_VADJ_1V091 =  9u,
    CY_SYSPMIC_VADJ_1V099 = 10u,
    CY_SYSPMIC_VADJ_1V108 = 11u,
    CY_SYSPMIC_VADJ_1V116 = 12u,
    CY_SYSPMIC_VADJ_1V125 = 13u,
    CY_SYSPMIC_VADJ_1V133 = 14u,
    CY_SYSPMIC_VADJ_1V142 = 15u,
    CY_SYSPMIC_VADJ_1V150 = 16u, // default value
    CY_SYSPMIC_VADJ_1V158 = 17u,
    CY_SYSPMIC_VADJ_1V167 = 18u,
    CY_SYSPMIC_VADJ_1V175 = 19u,
    CY_SYSPMIC_VADJ_1V184 = 20u,
    CY_SYSPMIC_VADJ_1V192 = 21u,
    CY_SYSPMIC_VADJ_1V201 = 22u,
    CY_SYSPMIC_VADJ_1V209 = 23u,
    CY_SYSPMIC_VADJ_1V218 = 24u,
    CY_SYSPMIC_VADJ_1V226 = 25u,
    CY_SYSPMIC_VADJ_1V234 = 26u,
    CY_SYSPMIC_VADJ_1V243 = 27u,
    CY_SYSPMIC_VADJ_1V251 = 28u,
} cy_en_syspmic_vadj_t;


/** This enumeration is used to set the reference voltage */
typedef enum 
{
    CY_SYSPMIC_VREF_0V9      = 0u, /**< VREF => VCCD * 0.9 / VADJ (Scale for vref=0.9V, use PMIC_VADJ to set the vccd target) */
    CY_SYSPMIC_VREF_0V8      = 1u, /**< VREF => VCCD * 0.8 / VADJ (Scale for vref=0.8V, use PMIC_VADJ to set the vccd target) */
    CY_SYSPMIC_VREF_0V6      = 2u, /**< VREF => VCCD * 0.6 / VADJ (Scale for vref=0.6V, use PMIC_VADJ to set the vccd target) */
    CY_SYSPMIC_VREF_NO_SCALE = 3u  /**< VREF => VCCD (No scaling, PMIC_VADJ has no effect)                                    */
} cy_en_syspmic_vref_t;
/** \} group_syspmic_enums */

/**
* \addtogroup group_syspmic_functions
* \{
*/
// APIs for internal regulators
void Cy_SysPmic_DisableLinearRegulator(void);
void Cy_SysPmic_EnableLinearRegulator(void);
bool Cy_SysPmic_GetLinearRegulatorStatus(void);
void Cy_SysPmic_DisableDeepSleepRegulator(void);
void Cy_SysPmic_EnableDeepSleepRegulator(void);

// APIs for PMIC
void Cy_SysPmic_SelectPmicVref(cy_en_syspmic_vref_t vref);
void Cy_SysPmic_AdjustOutputVoltage(cy_en_syspmic_vadj_t trim);

void Cy_SysPmic_DisableIntSupplyWhileExtActive(void);
void Cy_SysPmic_EnableIntSupplyWhileExtActive(void);

void Cy_SysPmic_EnableAnalogBuffer(void);
void Cy_SysPmic_DisableAnalogBuffer(void);

void Cy_SysPmic_DisablePmicEnableOutput(void);
void Cy_SysPmic_EnablePmicEnableOutput(bool polarity);

void Cy_SysPmic_EnablePmicStatusInput(bool polarity);
void Cy_SysPmic_DisablePmicStatusInput(void);
void Cy_SysPmic_SetPmicStatusWaitTime(uint16_t waitTime);

bool Cy_SysPmic_IsConfigured(void);
void Cy_SysPmic_SetConfigured(void);

void Cy_SysPmic_Disable(void);
void Cy_SysPmic_Enable(void);

void Cy_SysPmic_DisablePmicStatusTimeout(void);
void Cy_SysPmic_EnablePmicStatusTimeout(uint8_t timeout);

bool Cy_SysPmic_IsEnabled(void);
bool Cy_SysPmic_IsStatusOk(void);
bool Cy_SysPmic_IsSequencerBusy(void);

void Cy_SysPmic_DisableVAdj(void);
void Cy_SysPmic_EnableVAdj(void);

void Cy_SysPmic_DisablePmicInDeepSleep(void);
void Cy_SysPmic_EnablePmicInDeepSleep(void);

/** \} group_syspmic_functions */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* __CY_SYSPMIC_H__ */

/** \} group_syspmic */


/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
