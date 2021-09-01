/***************************************************************************//**
* \file cy_cs42448.h
* \version 1.0
*
* \brief
* Provides an API declaration of the audio codec (CS42448) driver.
*
********************************************************************************
* \copyright
* Copyright 2019-2020, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_mw_codec Middleware Audio Codec (CS42448)
* \{
* Offers communication and control of audio codec supporting TDM-I2S.
*
* \defgroup group_mw_cs42448_macros Macro definition
* \defgroup group_mw_cs42448_functions Functions
* \defgroup group_mw_cs42448_data_structures Data structures
* \defgroup group_mw_cs42448_enums Enumerated types
*/

#ifndef CY_CS42448_H
#define CY_CS42448_H

/** Include section */
#include "cy_project.h"
#include "cy_device_headers.h"

#if defined(__cplusplus)
extern "C" {
#endif


/**
* \addtogroup group_mw_cs42448_macros
* \{
*/

/* Codec slave address macro */
#define CY_CS42448_SLAVE_ADDR                   (0x4B)
#define CY_CS42448_RW_DELAY                     (50000u)

/* I2C clock configuration macro */
#define CY_CS42448_I2C_DIVIDER_NO               (1u)
#define CY_CS42448_I2C_SOURCE_CLK_FREQ          (80000000) // fixed
#define CY_CS42448_I2C_INCLK_TARGET_FREQ        (2000000)  // modifiable
#define CY_CS42448_I2C_DATARATE                 (100000)   // modifiable
  
/** \} group_mw_cs42448_macros */

/**
* \addtogroup group_mw_cs42448_enums
* \{
*/

/** Codec CS42448 Registers list */
typedef enum
{
    CY_CS42448_ID_REGISTER                  = 0x01,
    CY_CS42448_POWER_CTRL_REGISTER          = 0x02,
    CY_CS42448_FUNCTIONAL_MODE_REGISTER     = 0x03,
    CY_CS42448_INTERFACE_CTRL_REGISTER      = 0x04,
    CY_CS42448_ADC_CTRL_REGISTER            = 0x05,
    CY_CS42448_TRANSITION_CTRL_REGISTER     = 0x06,
    CY_CS42448_DAC_MUTE_CTRL_REGISTER       = 0x07,
    CY_CS42448_VOLUME_CTRL_AOUT_1_REGISTER  = 0x08,
    CY_CS42448_VOLUME_CTRL_AOUT_2_REGISTER  = 0x09,
    CY_CS42448_VOLUME_CTRL_AOUT_3_REGISTER  = 0x0A,
    CY_CS42448_VOLUME_CTRL_AOUT_4_REGISTER  = 0x0B,
    CY_CS42448_VOLUME_CTRL_AOUT_5_REGISTER  = 0x0C,
    CY_CS42448_VOLUME_CTRL_AOUT_6_REGISTER  = 0x0D,
    CY_CS42448_VOLUME_CTRL_AOUT_7_REGISTER  = 0x0E,
    CY_CS42448_VOLUME_CTRL_AOUT_8_REGISTER  = 0x0F,
    CY_CS42448_DAC_CHANNEL_INVERT_REGISTER  = 0x10,
    CY_CS42448_VOLUME_CTRL_AIN_1_REGISTER   = 0x11,
    CY_CS42448_VOLUME_CTRL_AIN_2_REGISTER   = 0x12,
    CY_CS42448_VOLUME_CTRL_AIN_3_REGISTER   = 0x13,
    CY_CS42448_VOLUME_CTRL_AIN_4_REGISTER   = 0x14,
    CY_CS42448_VOLUME_CTRL_AIN_5_REGISTER   = 0x15,
    CY_CS42448_VOLUME_CTRL_AIN_6_REGISTER   = 0x16,
    CY_CS42448_ADC_CHANNEL_INVERT_REGISTER  = 0x17,
    CY_CS42448_STATUS_CTRL_REGISTER         = 0x18,
    CY_CS42448_STATUS_REGISTER              = 0x19,
    CY_CS42448_STATUS_MASK_REGISTER         = 0x1A,
    CY_CS42448_MUTEC_REGISTER               = 0x1B,
} cy_en_cs42448_registers_t;

/** \} group_mw_cs42448_enums */

/**
* \addtogroup group_mw_cs42448_data_structures
* \{
*/

/** Register 0x02: Power Control Register */
typedef union 
{
    uint8_t u8;
    struct
    {
        uint8_t pdn:       1;
        uint8_t pdndac:    4;
        uint8_t pdnadc:    3;
    } bitField;
}cy_un_cs42448_reg_powerCtl_t; 

/** Register 0x03: Functional Mode Register */
typedef union 
{
    uint8_t u8;
    struct
    {
        uint8_t reserved:   1;
        uint8_t MFreq:      3;
        uint8_t ADCFM:      2;
        uint8_t DACFM:      2;
    } bitField;
}cy_un_cs42448_reg_funcMode_t;

/** Register 0x04: Interface Formats Register */
typedef union 
{
    uint8_t u8;
    struct
    {
        uint8_t ADCDIF:     3;
        uint8_t DACDIF:     3;
        uint8_t AUXDIF:     1;
        uint8_t Freeze:     1;
    } bitField;
}cy_un_cs42448_reg_interfaceFmt_t;

/** Register 0x05: ADC Control & DAC De-Emphasis Register */
typedef union 
{
    uint8_t u8;
    struct
    {
        uint8_t AinMux:     2;
        uint8_t ADCSingle:  3;
        uint8_t DACDEM:     1;
        uint8_t ADC3HPF:    1;
        uint8_t ADC12HPF:   1;
    } bitField;
}sv_un_cs42448_reg_adcDacCtl_t;

/** Register 0x06: Transition Control Register */
typedef union 
{
    uint8_t u8;
    struct
    {
        uint8_t ADCSZC:     2;
        uint8_t ADCVol:     1;
        uint8_t MuteADC:    1;
        uint8_t AMute:      1;
        uint8_t DACSZC:     2;
        uint8_t DACVol:     1;
    } bitField;
}cy_un_cs42448_reg_transCtl_t;

/** Register 0x07: DAC Channel Mute Control Register */
typedef union 
{
    uint8_t u8;
    struct
    {
        uint8_t aoutmute:   8;
    } bitField;
}cy_un_cs42448_reg_dacMuteCtl_t;

/** Register 0x08: AOUTX Volume Control Register */
typedef union 
{
    uint8_t u8;
    struct
    {
        uint8_t aoutvol:    8;
    } bitField;
}cy_un_cs42448_reg_aout1VolCtl_t;

/** Register 0x11: AINX Volume Control Register */
typedef union 
{
    uint8_t u8;
    struct
    {
        uint8_t ainvol:     8;
    } bitField;
}cy_un_cs42448_reg_ain1VolCtl_t;

/** \} group_mw_cs42448_data_structures */

/**
* \addtogroup group_mw_cs42448_functions
* \{
*/

/** Function to write the codec control registers */
void Cy_Cs42448_Init(void);

/** Function to read the codec control registers */
uint8_t Cy_Cs42448_ReadCtrReg(cy_en_cs42448_registers_t regAddr);

/** Function to write the codec control registers */
void Cy_Cs42448_WriteCtrReg(cy_en_cs42448_registers_t regAddr, uint8_t data);
         
/** \} group_mw_cs42448_functions */


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* CY_CS42448_H */

/* [] END OF FILE */
