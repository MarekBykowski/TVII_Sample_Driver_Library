/***************************************************************************//**
* \file cy_mipi_sensor.h
* \version 1.0
*
* \brief
* Provides an API declaration of the MIPI based Image Sensor driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_mw_imgsensor Middleware MIPI Image Sensor (MW Image Sense)
* \{
* The MIPI_Sensor driver provides an API to configure the MIPI Image sensor.
* The MIPI has upto 4 Data lane and one differential Clock lane. About actual
* supported # or modules and channels, please refer to the technical reference
* manual (TRM) and device datasheet.
*
* \section group_mw_imgsensor_configuration Configuration Considerations
* Typical usage as is follows:
*  - Call Cy_Mipi_Image_Sensor_Init() to initialize MIPI Sensor module
*  - Call Cy_Mipi_Image_Sensor_Wakeup() to wakeup the sensor
*  - Call Cy_Mipi_Image_Sensor_Set_Resolution() to configure the resolution.
* After initialize sensor call, by default sensor will go in the Sleep mode.
* Note that before calling any other function, init() function should be called.
* 
* Init() will initiliaze the control path for Image Sensor and basic configuration
* for VGA at 60FPS. For control and config settings SCB7 is used, please do not 
* change this configuartion, because it need a level shifted signals.
* 
* The basic read and write mechanism explained below
*
*       Write Transaction
*       Device         Addr+W  | WriteRegister_high  | WriteRegister_Low  | WriteValue
*       Sensor               A                     A                    A             NA
*
*       Read Transaction
*       Device         Addr+W  | WriteRegister_high  | WriteRegister_Low  | Addr+R          | NA
*       Sensor               A                     A                    A         ReadValue             
*
* Refer to the technical reference manual (TRM) and the device datasheet.
*
* \defgroup group_mw_imgsensor_macros Macro
* \defgroup group_mw_imgsensor_functions Functions
* \defgroup group_mw_imgsensor_enums Enumerated types
*/

#ifndef CY_MIPI_SENSOR_H_
#define CY_MIPI_SENSOR_H_

#include <stddef.h>
#include <stdbool.h>
#include "cy_device_headers.h"
#include "cy_ov5640_config.h"


#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_mw_imgsensor_macros
* \{
*/

/* Value selection macro */
#define CY_OV5640_MAKEWORD(v1, v2)              ((v1<<8) | v2)
#define CY_OV5640_SWAP_U16(value)               (value = ((value>>8)&0x00FF) | ((value<<8)&0xFF00))

/* OV5640 Sensor related macro definition */
#define CY_OV5640_I2C_ADRESS                    (0x3C)
#define CY_OV5640_I2C_READ_ADDRESS              ((OV5640_I2C_ADRESS << 1) | 1)
#define CY_OV5640_I2C_WRITE_ADDRESS             ((OV5640_I2C_ADRESS << 1))
#define CY_OV5640_CHIP_ID                       (0x5640)

/* OV5640 Register Addresses */
#define CY_OV5640_SYSTEM_RESET0                 (0x3000)
#define CY_OV5640_CLOCK_ENABLE0                 (0x3004)
#define CY_OV5640_SYSTEM_CTRL0                  (0x3008)
#define CY_OV5640_CHIP_ID_HIGH_BYTE             (0x300A)
#define CY_OV5640_CHIP_ID_LOW_BYTE              (0x300B)
#define CY_OV5640_POLARITY_CTRL00               (0x4740)
#define CY_OV5640_AUTOFOCUS_CMD_MAIN            (0x3022)
#define CY_OV5640_AUTOFOCUS_CMD_ACK             (0x3023)
#define CY_OV5640_NIGHT_MODE_CMD                (0x3A00)
#define CY_OV5640_FORMAT_CONTROL		(0x4300)
#define CY_OV5640_TEST_PATTERN			(0x503D)

/* OV5640 Register MASKS */
#define CY_OV5640_SYSTEM_RESET_MASK             (0x80)
#define CY_OV5640_SYSTEM_POWER_DOWN_MASK        (0x40)
#define CY_OV5640_AF_SINGLE_TRIGGER             (0x03)
#define CY_OV5640_AF_CONT_TRIGGER               (0x04)
#define CY_OV5640_AF_RELAUNCH_ZONE_CONFIG       (0x12)

/* OV5640 Delay macros */
#define CY_OV5640_CMD_RETRY_COUNT               (3u)
#define CY_OV5640_CMD_IN_BW_DELAY               (20000u)
#define CY_OV5640_RESET_BOOT_DELAY              (80000u)
#define CY_OV5640_FLASH_FW_DELAY                (CY_OV5640_RESET_BOOT_DELAY*10)

/* I2C clock configuration macro */
#define CY_MIPI_I2C_DIVIDER_NO                  (1u)
#define CY_MIPI_I2C_SOURCE_CLK_FREQ             (80000000) // fixed
#define CY_MIPI_I2C_INCLK_TARGET_FREQ           (2000000)  // modifiable
#define CY_MIPI_I2C_DATARATE                    (400000)   // modifiable

/* I2C buffer size macro */  
#define CY_MIPI_I2C_WRITE_BUF_MAX               256u
  
/** \} group_mw_imgsensor_macros */

/**
* \addtogroup group_mw_imgsensor_enums
* \{
*/

/* Function return value types */
typedef enum
{
    CY_MIPI_SENSOR_SUCCESS   = 0x00u, /**< Returned successful */
    CY_MIPI_SENSOR_ERROR     = 0x01u, /**< General error */
    CY_MIPI_SENSOR_BAD_PARAM = 0x02u, /**< Bad parameter was passed */
} cy_en_mipi_sensor_result_t;

/* Image sensor resolution values */
typedef enum
{
    CY_MIPI_SENSOR_RES_QVGA     = 0x00u, /**< Set resolution QVGA 320x240 */
    CY_MIPI_SENSOR_RES_VGA      = 0x01u, /**< Set resolution VGA 640x480 */
    CY_MIPI_SENSOR_RES_720P     = 0x02u, /**< Set resolution VGA 720P */
    CY_MIPI_SENSOR_RES_1080P    = 0x03u, /**< Set resolution VGA 1080P */
    CY_MIPI_SENSOR_RES_5MP      = 0x04u, /**< Set resolution VGA 5MP */
} cy_en_mipi_sensor_resolution_type_t;

/* Image sensor color and sequence format */
typedef enum
{
    CY_MIPI_SENSOR_SEQ_RAW_BGBG_GRGR		= 0x00u, /**< Set color sequence in RAW */
    CY_MIPI_SENSOR_SEQ_RAW_GBGB_RGRG		= 0x01u, /**< Set color sequence in RAW */
    CY_MIPI_SENSOR_SEQ_RAW_GRGR_BGBG		= 0x02u, /**< Set color sequence in RAW */
    CY_MIPI_SENSOR_SEQ_RAW_RGRG_GBGB		= 0x03u, /**< Set color sequence in RAW */
    CY_MIPI_SENSOR_SEQ_Y8_ANY			= 0x10u, /**< Set color sequence in Y8 */
    CY_MIPI_SENSOR_SEQ_YUV444_YUVYUV		= 0x20u, /**< Set color sequence in YUV444 */
    CY_MIPI_SENSOR_SEQ_YUV444_YVUYVU		= 0x21u, /**< Set color sequence in YUV444 */
    CY_MIPI_SENSOR_SEQ_YUV444_UYVUYV		= 0x22u, /**< Set color sequence in YUV444 */
    CY_MIPI_SENSOR_SEQ_YUV444_VYUVYU		= 0x23u, /**< Set color sequence in YUV444 */
    CY_MIPI_SENSOR_SEQ_YUV444_UVYUVY		= 0x24u, /**< Set color sequence in YUV444 */
    CY_MIPI_SENSOR_SEQ_YUV444_VUYVUY		= 0x25u, /**< Set color sequence in YUV444 */
    CY_MIPI_SENSOR_SEQ_YUV422_YUYV		= 0x30u, /**< Set color sequence in YUV422 */
    CY_MIPI_SENSOR_SEQ_YUV422_YVYU		= 0x31u, /**< Set color sequence in YUV422 */
    CY_MIPI_SENSOR_SEQ_YUV422_UYVY		= 0x32u, /**< Set color sequence in YUV422 */
    CY_MIPI_SENSOR_SEQ_YUV422_VYUY		= 0x33u, /**< Set color sequence in YUV422 */
    CY_MIPI_SENSOR_SEQ_YUV420_YYYY_YUYV		= 0x40u, /**< Set color sequence in YUV420 */
    CY_MIPI_SENSOR_SEQ_YUV420_YYYY_YVYU		= 0x41u, /**< Set color sequence in YUV420 */
    CY_MIPI_SENSOR_SEQ_YUV420_YYYY_UYVY		= 0x42u, /**< Set color sequence in YUV420 */
    CY_MIPI_SENSOR_SEQ_YUV420_YYYY_VYUY		= 0x43u, /**< Set color sequence in YUV420 */
    CY_MIPI_SENSOR_SEQ_YUV420_YUYV_YYYY		= 0x44u, /**< Set color sequence in YUV420 */
    CY_MIPI_SENSOR_SEQ_YUV420_YVYU_YYYY		= 0x45u, /**< Set color sequence in YUV420 */
    CY_MIPI_SENSOR_SEQ_YUV420_UYVY_YYYY		= 0x46u, /**< Set color sequence in YUV420 */
    CY_MIPI_SENSOR_SEQ_YUV420_VYUY_YYYY		= 0x47u, /**< Set color sequence in YUV420 */
    CY_MIPI_SENSOR_SEQ_YUV420_VYY_UVV		= 0x5Eu, /**< Set color sequence in YUV420 */
    CY_MIPI_SENSOR_SEQ_YUV420_UYY_VYY		= 0x5Fu, /**< Set color sequence in YUV420 */
    CY_MIPI_SENSOR_SEQ_RGB565_B40G53_G20R40	= 0x60u, /**< Set color sequence in RGB565 */
    CY_MIPI_SENSOR_SEQ_RGB565_R40G53_G20B40	= 0x61u, /**< Set color sequence in RGB565 */
    CY_MIPI_SENSOR_SEQ_RGB565_G40R53_R20B40	= 0x62u, /**< Set color sequence in RGB565 */
    CY_MIPI_SENSOR_SEQ_RGB565_B40R53_R20G40	= 0x63u, /**< Set color sequence in RGB565 */
    CY_MIPI_SENSOR_SEQ_RGB565_G40B53_B20R40	= 0x64u, /**< Set color sequence in RGB565 */
    CY_MIPI_SENSOR_SEQ_RGB565_R40B53_B40G40	= 0x65u, /**< Set color sequence in RGB565 */
    CY_MIPI_SENSOR_SEQ_RGB565_G20B40_R40G53	= 0x6Fu, /**< Set color sequence in RGB565 */
} cy_en_mipi_sensor_format_type_t;

/** \} group_mipi_sensor_enums */


/**
* \addtogroup group_mw_imgsensor_functions
* \{
*/

/* Image Sensor local function definition */
static void Cy_OV5640_ImageSensor_Scb_I2C_IntrISR(void);
static void Cy_OV5640_ImageSensor_SetPeripheFracDiv24_5(uint64_t targetFreq, uint64_t sourceFreq, uint8_t divNum);
static void Cy_OV5640_ImageSensor_I2C_Master_Event(uint32_t locEvents);
static void Cy_OV5640_ImageSensor_I2C_Init(void);

static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Set_Base(void);
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_VerifyChipId(void);
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Read(uint16_t regAddr, uint8_t count, uint8_t *buf);
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Write(uint16_t regAddr, uint16_t count, uint8_t *buf);
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Write_ConfigurationSettings(cy_stc_Ov5640_reg_t * configSettings, uint16_t configSettingsSize);

static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Set_QVGA_Config(void);
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Set_VGA_Config(void);
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Set_720P_Config(void);
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Set_1080P_Config(void);
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Set_5MP_Config(void);
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Configure_Autofocus(void);

/* Image Sensor global function definition */
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_DeInit(void);
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_Init(void);
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_Sleep(void);
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_Wakeup(void);
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_Set_TestPattern(bool enable);
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_Set_MipiCapturePath(bool enable);
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_Set_ColorFormat(cy_en_mipi_sensor_format_type_t enFmType);
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_Set_Resolution(cy_en_mipi_sensor_resolution_type_t enResType);

/** \} group_mw_imgsensor_functions */


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* CY_MIPI_SENSOR_H_ */

/* [] END OF FILE */
