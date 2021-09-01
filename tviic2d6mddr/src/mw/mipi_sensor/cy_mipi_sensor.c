/***************************************************************************//**
* \file cy_iamge_sensor.c
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

#include "cy_project.h"
#include "cy_device_headers.h"
#include "cy_mipi_sensor.h"


/* I2C port configuration macro */
static cy_stc_gpio_pin_config_t mipi_i2c_port_pin_cfg =
{
    .outVal   = 0x00,
    .intEdge  = 0,
    .intMask  = 0,
    .vtrip    = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn   = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel  = 0,
    .vohSel   = 0,
};

/* I2C irq configuration macro */
static cy_stc_sysint_irq_t mipi_i2c_irq_cfg =
{
    .sysIntSrc  = CY_MIPI_CSI_I2C_IRQN,
    .intIdx     = CPUIntIdx4_IRQn,
    .isEnabled  = true,
};

/* I2C master configuration macro */
static cy_stc_scb_i2c_config_t mipi_i2c_stc_config =
{
    .i2cMode             = CY_SCB_I2C_MASTER,
    .useRxFifo           = true,
    .useTxFifo           = true,
    .acceptAddrInFifo    = false,
    .ackGeneralAddr      = false,
    .enableWakeFromSleep = false
};

/* I2C master configuration structure */
static cy_stc_scb_i2c_master_xfer_config_t mipi_i2c_stc_master_config =
{
    .buffer       = 0,
    .bufferSize   = 0,
    .xferPending  = false
};


/* Flag to check validity of sensor during initialization */
static bool glIsValidSensor = false;

/* Sensor interface I2C contex */
static cy_stc_scb_i2c_context_t mipi_i2c_stc_context;


/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_Scb_I2C_IntrISR
****************************************************************************//**
*
* \brief
* Sensor i2c interrupt callback.
*
* \param  none
*
* \return none
*
*******************************************************************************/
static void Cy_OV5640_ImageSensor_Scb_I2C_IntrISR(void)
{
    /* I2C interrupt handler for High-Level APIs */
    Cy_SCB_I2C_Interrupt(CY_MIPI_CSI_I2C_TYPE, &mipi_i2c_stc_context);
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_SetPeripheFracDiv24_5
****************************************************************************//**
*
* \brief
* Sensor i2c set up clock fractional divider.
*
* \param
* targetFreq : frequency for i2c operation
*
* \param
* sourceFreq : frequency for scb block
* 
* \param
* divNum : divider no used for the target frequency
*
* \return none
*
*******************************************************************************/
static void Cy_OV5640_ImageSensor_SetPeripheFracDiv24_5(uint64_t targetFreq, uint64_t sourceFreq, uint8_t divNum)
{
    uint64_t temp = ((uint64_t)sourceFreq << 5ull);
    uint32_t divSetting;

    divSetting = (uint32_t)(temp / targetFreq);
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_MIPI_CSI_I2C_PCLK), 
                                   CY_SYSCLK_DIV_24_5_BIT, divNum, 
                                   (((divSetting >> 5u) & 0x00000FFF) - 1u), 
                                   (divSetting & 0x0000001F));
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_I2C_Master_Event
****************************************************************************//**
*
* \brief
* Sensor i2c event callback.
*
* \param
* locEvents : i2c block generated event id
*
* \return none
*
*******************************************************************************/
static void Cy_OV5640_ImageSensor_I2C_Master_Event(uint32_t locEvents)
{
    switch (locEvents)
    {
    case CY_SCB_I2C_MASTER_WR_IN_FIFO_EVENT:
        break;
    case CY_SCB_I2C_MASTER_WR_CMPLT_EVENT:
        break;
    case CY_SCB_I2C_MASTER_RD_CMPLT_EVENT:
        break;
    case CY_SCB_I2C_MASTER_ERR_EVENT:
        break;
    default:
        break;
    }
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_I2C_Init
****************************************************************************//**
*
* \brief
* Function to initialize i2c control path for image sensor
*
* \param  none
*
* \return none
*
* \note
* SCB7 is fixed for the MIPI sensor control path.
* 
*******************************************************************************/
static void Cy_OV5640_ImageSensor_I2C_Init(void)
{
   /*---------------------*/
    /* Clock Configuration */
    /*---------------------*/
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_2);

    Cy_SysClk_PeriphAssignDivider(CY_MIPI_CSI_I2C_PCLK, CY_SYSCLK_DIV_24_5_BIT, CY_MIPI_I2C_DIVIDER_NO);
    Cy_OV5640_ImageSensor_SetPeripheFracDiv24_5(CY_MIPI_I2C_INCLK_TARGET_FREQ, CY_MIPI_I2C_SOURCE_CLK_FREQ, CY_MIPI_I2C_DIVIDER_NO);
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(CY_MIPI_CSI_I2C_PCLK), CY_SYSCLK_DIV_24_5_BIT, CY_MIPI_I2C_DIVIDER_NO);

    /*--------------------*/
    /* Port Configuration */
    /*--------------------*/
    mipi_i2c_port_pin_cfg.driveMode = CY_GPIO_DM_OD_DRIVESLOW;
    mipi_i2c_port_pin_cfg.hsiom     = CY_MIPI_CSI_I2C_SDA_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_MIPI_CSI_I2C_SDA_PORT, CY_MIPI_CSI_I2C_SDA_PIN, &mipi_i2c_port_pin_cfg);

    mipi_i2c_port_pin_cfg.driveMode = CY_GPIO_DM_OD_DRIVESLOW;
    mipi_i2c_port_pin_cfg.hsiom     = CY_MIPI_CSI_I2C_SCL_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_MIPI_CSI_I2C_SCL_PORT, CY_MIPI_CSI_I2C_SCL_PIN, &mipi_i2c_port_pin_cfg);

    /*--------------------------*/
    /* Interrrupt Configuration */
    /*--------------------------*/
    Cy_SysInt_InitIRQ(&mipi_i2c_irq_cfg);
    Cy_SysInt_SetSystemIrqVector(mipi_i2c_irq_cfg.sysIntSrc, Cy_OV5640_ImageSensor_Scb_I2C_IntrISR);
    NVIC_EnableIRQ(mipi_i2c_irq_cfg.intIdx);
    
    /*--------------------------*/
    /*  Initilize & Enable I2C  */
    /*--------------------------*/
    Cy_SCB_I2C_Init(CY_MIPI_CSI_I2C_TYPE, &mipi_i2c_stc_config, &mipi_i2c_stc_context);
    Cy_SCB_I2C_SetDataRate(CY_MIPI_CSI_I2C_TYPE, CY_MIPI_I2C_DATARATE, CY_MIPI_I2C_INCLK_TARGET_FREQ);
    Cy_SCB_I2C_RegisterEventCallback(CY_MIPI_CSI_I2C_TYPE, (scb_i2c_handle_events_t)Cy_OV5640_ImageSensor_I2C_Master_Event, &mipi_i2c_stc_context);
    Cy_SCB_I2C_Enable(CY_MIPI_CSI_I2C_TYPE);    
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_Read
****************************************************************************//**
*
* \brief
* Function to read register in image sensor.
*
* \param
* regAddr : register address of image sensor
*
* \param
* count : no of bytes of data for read/write
*
* \param
* buf : pointer to the data buffer
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Read(uint16_t regAddr, uint8_t count, uint8_t *buf)
{
    cy_en_mipi_sensor_result_t status = CY_MIPI_SENSOR_SUCCESS;
    uint16_t cnt=0;
    
    CY_OV5640_SWAP_U16(regAddr);
    uint8_t *regadd = (uint8_t*)&regAddr;
    
    /* retry command */
    for(cnt=0; cnt<CY_OV5640_CMD_RETRY_COUNT ; cnt++)
    {
        mipi_i2c_stc_master_config.slaveAddress = CY_OV5640_I2C_ADRESS;
        mipi_i2c_stc_master_config.buffer = regadd;
        mipi_i2c_stc_master_config.bufferSize = 2;
        status = (cy_en_mipi_sensor_result_t)Cy_SCB_I2C_MasterWrite(CY_MIPI_CSI_I2C_TYPE, &mipi_i2c_stc_master_config, &mipi_i2c_stc_context);
        DELAY(CY_OV5640_CMD_IN_BW_DELAY);
        
        mipi_i2c_stc_master_config.buffer = buf;
        mipi_i2c_stc_master_config.bufferSize = count;
        status = (cy_en_mipi_sensor_result_t) Cy_SCB_I2C_MasterRead(CY_MIPI_CSI_I2C_TYPE, &mipi_i2c_stc_master_config, &mipi_i2c_stc_context);
        DELAY(CY_OV5640_CMD_IN_BW_DELAY);
        
        if (status == CY_MIPI_SENSOR_SUCCESS)
        {
            break;
        }
    }
    return status;
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_Write
****************************************************************************//**
*
* \brief
* Function to write register in image sensor.
*
* \param
* regAddr : register address of image sensor
* 
* \param
* count : no of bytes of data for read/write
*
* \param
* buf : pointer to the data buffer
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Write(uint16_t regAddr, uint16_t count, uint8_t *buf)
{
    cy_en_mipi_sensor_result_t status = CY_MIPI_SENSOR_SUCCESS;
    uint16_t cnt=0;
    static uint8_t dataWrite[CY_MIPI_I2C_WRITE_BUF_MAX+2];

    CY_ASSERT(count <= CY_MIPI_I2C_WRITE_BUF_MAX);

    dataWrite[0] = regAddr>>8;
    dataWrite[1] = regAddr & 0xFF;
    for(uint32_t i = 0; i<count; i++)
    {
        dataWrite[i+2] = buf[i];
    }
    
    /* retry command */
    for(cnt=0; cnt<CY_OV5640_CMD_RETRY_COUNT ; cnt++)
    {
        mipi_i2c_stc_master_config.slaveAddress = CY_OV5640_I2C_ADRESS;
        mipi_i2c_stc_master_config.buffer = dataWrite;
        mipi_i2c_stc_master_config.bufferSize = count + 2;              // two byte register size
        status = (cy_en_mipi_sensor_result_t)Cy_SCB_I2C_MasterWrite(CY_MIPI_CSI_I2C_TYPE, &mipi_i2c_stc_master_config, &mipi_i2c_stc_context);
        DELAY(CY_OV5640_CMD_IN_BW_DELAY);
        
        if (status == CY_MIPI_SENSOR_SUCCESS)
        {
            /* Fix for the reset to boot-up time */
            if(regAddr == CY_OV5640_SYSTEM_CTRL0)
            {
                DELAY(CY_OV5640_RESET_BOOT_DELAY);
            }
            break;
        }
    }
    return status;
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_Write_ConfigurationSettings
****************************************************************************//**
*
* \brief
* Function to write image sensor default configuration.
*
* \param
* cy_stc_Ov5640_reg_t : set of register needs to be configured
*
* \param
* configSettingsSize : size of the register array
*
* \return 
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Write_ConfigurationSettings(cy_stc_Ov5640_reg_t * configSettings, uint16_t configSettingsSize)
{
    uint16_t regCounter = 0;
    cy_en_mipi_sensor_result_t status = CY_MIPI_SENSOR_SUCCESS;
    uint8_t rwBuffer;

    for (regCounter = 0; ((regCounter < configSettingsSize) && (status == CY_MIPI_SENSOR_SUCCESS)); regCounter++)
    {
        rwBuffer = configSettings[regCounter].regValue;
        status = Cy_OV5640_ImageSensor_Write(configSettings[regCounter].regAddr, 1, &rwBuffer); 
    }

    return status;
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_VerifyChipId
****************************************************************************//**
*
* \brief
* Function to verify that the image sensor is the OV5640 chip.
*
* \param  none
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
* \note 
* Sets a global variable glIsValidSensor for further communication, needs
* to be called just after init();
*
*******************************************************************************/
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_VerifyChipId(void)
{
    uint8_t readBuffer[2] = {0};
    cy_en_mipi_sensor_result_t status = CY_MIPI_SENSOR_SUCCESS;

    status = Cy_OV5640_ImageSensor_Read(CY_OV5640_CHIP_ID_HIGH_BYTE, 2, readBuffer);
    
    if (status != CY_MIPI_SENSOR_SUCCESS)
    {
        return status;
    }

    if (CY_OV5640_CHIP_ID != CY_OV5640_MAKEWORD(readBuffer[0],readBuffer[1]))
    {
        status = CY_MIPI_SENSOR_BAD_PARAM;
    }
    else
    {
        glIsValidSensor = true;
    }
    return status;
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_Set_Base
****************************************************************************//**
*
* \brief
* Configure defaults base setup for sensor.
*
* \param  none
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Set_Base(void)
{
    uint16_t configSize;
    if (glIsValidSensor != true)
    {
        return CY_MIPI_SENSOR_ERROR;
    }
    
    configSize = (sizeof(Cy_OV5640_Base_configuration_settings))/(sizeof(cy_stc_Ov5640_reg_t));
    return Cy_OV5640_ImageSensor_Write_ConfigurationSettings(Cy_OV5640_Base_configuration_settings, configSize);
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_Set_QVGA_Config
****************************************************************************//**
*
* \brief
* Configure OV5640 for QVGA@60FPS.
*
* \param none
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Set_QVGA_Config(void)
{
    uint16_t configSize;
    if (glIsValidSensor != true)
    {
        return CY_MIPI_SENSOR_ERROR;
    }

    configSize = (sizeof(Cy_OV5640_QVGA_configuration_settings))/(sizeof(cy_stc_Ov5640_reg_t));
    return Cy_OV5640_ImageSensor_Write_ConfigurationSettings(Cy_OV5640_QVGA_configuration_settings, configSize);
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_Set_VGA_Config
****************************************************************************//**
*
* \brief
* Configure OV5640 for VGA@60FPS.
*
* \param none
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Set_VGA_Config(void)
{
    uint16_t configSize;
    if (glIsValidSensor != true)
    {
        return CY_MIPI_SENSOR_ERROR;
    }

    configSize = (sizeof(Cy_OV5640_VGA_configuration_settings))/(sizeof(cy_stc_Ov5640_reg_t));
    return Cy_OV5640_ImageSensor_Write_ConfigurationSettings(Cy_OV5640_VGA_configuration_settings, configSize);
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_Set_720P_Config
****************************************************************************//**
*
* \brief
* Configure OV5640 for 720P@60FPS.
*
* \param none
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Set_720P_Config(void)
{
    uint16_t configSize;
    if (glIsValidSensor != true)
    {
        return CY_MIPI_SENSOR_ERROR;
    }

    configSize = (sizeof(Cy_OV5640_720P_configuration_settings))/(sizeof(cy_stc_Ov5640_reg_t));
    return Cy_OV5640_ImageSensor_Write_ConfigurationSettings(Cy_OV5640_720P_configuration_settings, configSize);
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_Set_1080P_Config
****************************************************************************//**
*
* \brief
* Configure OV5640 for 1080P@60FPS.
*
* \param none
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Set_1080P_Config(void)
{
    uint16_t configSize;
    if (glIsValidSensor != true)
    {
        return CY_MIPI_SENSOR_ERROR;
    }

    configSize = (sizeof(Cy_OV5640_1080P_configuration_settings))/(sizeof(cy_stc_Ov5640_reg_t));
    return Cy_OV5640_ImageSensor_Write_ConfigurationSettings(Cy_OV5640_1080P_configuration_settings, configSize);
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_Set_5MP_Config
****************************************************************************//**
*
* \brief
* Configure OV5640 for 5MP@60FPS.
*
* \param none
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Set_5MP_Config(void)
{
    uint16_t configSize;
    if (glIsValidSensor != true)
    {
        return CY_MIPI_SENSOR_ERROR;
    }

    configSize = (sizeof(Cy_OV5640_5MP_configuration_settings))/(sizeof(cy_stc_Ov5640_reg_t));
    return Cy_OV5640_ImageSensor_Write_ConfigurationSettings(Cy_OV5640_5MP_configuration_settings, configSize);
}

/*******************************************************************************
* Function Name: Cy_OV5640_ImageSensor_Configure_Autofocus
****************************************************************************//**
*
* \brief
* Configure image sensor auto focus feature.
*
* \param none
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
static cy_en_mipi_sensor_result_t Cy_OV5640_ImageSensor_Configure_Autofocus(void)
{
    cy_en_mipi_sensor_result_t status = CY_MIPI_SENSOR_SUCCESS;
    uint8_t count = 0;   
    uint8_t rwBuffer = 0;
    
    if (glIsValidSensor != true)
    {
        return CY_MIPI_SENSOR_ERROR;
    }
    
    rwBuffer = 0x20;
    status = Cy_OV5640_ImageSensor_Write(CY_OV5640_SYSTEM_RESET0, 1, &rwBuffer);
    if(status != CY_MIPI_SENSOR_SUCCESS)
    {
        return status;
    }
    DELAY(CY_OV5640_CMD_IN_BW_DELAY); 
    
    for (count = 0; count <= 0x10; count++)
    {
        status = Cy_OV5640_ImageSensor_Write(cy_OV5640_auto_focus_configuration_settings[count].baseAddress, cy_OV5640_auto_focus_configuration_settings[count].numBytes, cy_OV5640_auto_focus_configuration_settings[count].buffer);
        if(status != CY_MIPI_SENSOR_SUCCESS)
        {
            return status;
        }
        DELAY(CY_OV5640_FLASH_FW_DELAY);
    }

    /* Autofocus firmware workaround */
    rwBuffer = 0x7f;
    status = Cy_OV5640_ImageSensor_Write(0x3029, 1, &rwBuffer);
    DELAY(CY_OV5640_CMD_IN_BW_DELAY);
    
    rwBuffer = 0x00;
    status = Cy_OV5640_ImageSensor_Write(CY_OV5640_SYSTEM_RESET0, 1, &rwBuffer);
    DELAY(CY_OV5640_CMD_IN_BW_DELAY);
    
    return status;
}

/*******************************************************************************
* Function Name: Cy_Mipi_Image_Sensor_Wakeup
****************************************************************************//**
*
* \brief
* Image sensor wakeup call.
*
* \param none
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_Wakeup(void)
{
    cy_en_mipi_sensor_result_t status = CY_MIPI_SENSOR_SUCCESS;
    uint8_t rwBuffer = 0;    
    if (glIsValidSensor != true)
    {
        return CY_MIPI_SENSOR_ERROR;
    }

    rwBuffer = 0x21;
    status = Cy_OV5640_ImageSensor_Write(CY_OV5640_POLARITY_CTRL00, 1, &rwBuffer);
    if (status == CY_MIPI_SENSOR_SUCCESS)
    {
        rwBuffer = 0;
        status = Cy_OV5640_ImageSensor_Read(CY_OV5640_SYSTEM_CTRL0, 1, &rwBuffer);
        if (status == CY_MIPI_SENSOR_SUCCESS)
        {
            rwBuffer &= (~CY_OV5640_SYSTEM_POWER_DOWN_MASK);
            status = Cy_OV5640_ImageSensor_Write(CY_OV5640_SYSTEM_CTRL0, 1, &rwBuffer);
            DELAY(CY_OV5640_RESET_BOOT_DELAY);
        }
    }
    return status;
}

/*******************************************************************************
* Function Name: Cy_OV5640_Image_Sensor_Sleep
****************************************************************************//**
*
* \brief
* Configure defaults base setup for sensor.
*
* \param none
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
cy_en_mipi_sensor_result_t Cy_OV5640_Image_Sensor_Sleep(void)
{
    cy_en_mipi_sensor_result_t status = CY_MIPI_SENSOR_SUCCESS;
    uint8_t rwBuffer = 0;

    if (glIsValidSensor != true)
    {
        return CY_MIPI_SENSOR_ERROR;
    }

    status = Cy_OV5640_ImageSensor_Read(CY_OV5640_SYSTEM_CTRL0, 1, &rwBuffer);
    if (status == CY_MIPI_SENSOR_SUCCESS)
    {
        rwBuffer |= CY_OV5640_SYSTEM_POWER_DOWN_MASK;
        status = Cy_OV5640_ImageSensor_Write(CY_OV5640_SYSTEM_CTRL0, 1, &rwBuffer);
        DELAY(CY_OV5640_RESET_BOOT_DELAY);
    }
    return status;
}

/*******************************************************************************
* Function Name: Cy_Mipi_Image_Sensor_Set_Resolution
****************************************************************************//**
*
* \brief
* Set a particular resolution to be captured from the image sensor.
*
* \param
* cy_en_mipi_sensor_resolution_type_t : sensor resolution type
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_Set_Resolution(cy_en_mipi_sensor_resolution_type_t enResType)
{
    cy_en_mipi_sensor_result_t status = CY_MIPI_SENSOR_SUCCESS;
    
    switch(enResType)
    {
        case CY_MIPI_SENSOR_RES_QVGA:
            // Not supported yet
            status = Cy_OV5640_ImageSensor_Set_QVGA_Config();   // Image sensor set QVGA setup
            break;
            
        case CY_MIPI_SENSOR_RES_VGA:
            status = Cy_OV5640_ImageSensor_Set_VGA_Config();    // Image sensor set VGA setup
            break;
            
        case CY_MIPI_SENSOR_RES_720P:
            status = Cy_OV5640_ImageSensor_Set_720P_Config();   // Image sensor set 720P setup
            break;
            
        case CY_MIPI_SENSOR_RES_1080P:
            status = Cy_OV5640_ImageSensor_Set_1080P_Config();  // Image sensor base 1080P setup
            break;
        
        case CY_MIPI_SENSOR_RES_5MP:
            status = Cy_OV5640_ImageSensor_Set_5MP_Config();    // Image sensor base 5MP setup
            break;    
            
        default:
            status = Cy_OV5640_ImageSensor_Set_VGA_Config();    // Image sensor base VGA setup
            break;
    }

    if (status != CY_MIPI_SENSOR_SUCCESS)
    {
        return status;
    }
    return status;
}


/*******************************************************************************
* Function Name: Cy_Mipi_Image_Sensor_Set_ColorFormat
****************************************************************************//**
*
* \brief
* Function to set the color format and output pattern of the OV5640 chip.
*
* \param
* cy_en_mipi_sensor_format_type_t : sensor color format and sequence type
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_Set_ColorFormat(cy_en_mipi_sensor_format_type_t enFmType)
{
    uint8_t rwBuffer;
    cy_en_mipi_sensor_result_t status = CY_MIPI_SENSOR_SUCCESS;

    rwBuffer = enFmType;
    status = Cy_OV5640_ImageSensor_Write(CY_OV5640_FORMAT_CONTROL, 1, &rwBuffer);
    if (status != CY_MIPI_SENSOR_SUCCESS)
    {
        return status;
    }

    return status;
}

/*******************************************************************************
* Function Name: Cy_Mipi_Image_Sensor_Set_TestPattern
****************************************************************************//**
*
* \brief
* Function to enable/disable the default test color pattern of the OV5640 chip.
*
* \param
* bool : true for enable or false for disable
*
* \return 
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_Set_TestPattern(bool enable)
{
    uint8_t rwBuffer;
    cy_en_mipi_sensor_result_t status = CY_MIPI_SENSOR_SUCCESS;

    rwBuffer = (enable?1:0) << 7;
    status = Cy_OV5640_ImageSensor_Write(CY_OV5640_TEST_PATTERN, 1, &rwBuffer);
    if (status != CY_MIPI_SENSOR_SUCCESS)
    {
        return status;
    }

    return status;
}

/*******************************************************************************
* Function Name: Cy_Mipi_Image_Sensor_Enable_Capture
****************************************************************************//**
*
* \brief
* Enable the capture engine for MIPICSI-2 source.
*
* \param
* bool : true for enable or false for disable
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_Set_MipiCapturePath(bool enable)
{
    uint8_t capCfg;
    cy_en_mipi_sensor_result_t status = CY_MIPI_SENSOR_SUCCESS;

    if (glIsValidSensor != true)
    {
        return CY_MIPI_SENSOR_ERROR;
    }
    else
    {
        capCfg = enable ? 1 : 0;
        CY_SET_REG32(CYREG_VIDEOSS0_VIDEOSSCFG_CAP0CFG, (uint32_t)capCfg);   // Set the CSI as capture source
    }

    return status;
}

/*******************************************************************************
* Function Name: Cy_Mipi_Image_Sensor_Init
****************************************************************************//**
*
* \brief
* Initializes the Image Sensor and control interface.
*
* \param none
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
* \note 
* SCB7 is used as a sensor control interface, do not change it. Should be
* called before calling any other image sensor api.
*
*******************************************************************************/
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_Init(void)
{
    cy_en_mipi_sensor_result_t status = CY_MIPI_SENSOR_SUCCESS;
    
    Cy_OV5640_ImageSensor_I2C_Init();                           // Initialize I2C control path
            
    status = Cy_OV5640_ImageSensor_VerifyChipId();              // Verify sensor chip id
    if (status != CY_MIPI_SENSOR_SUCCESS)
    {
        return status;
    }
    
    status = Cy_OV5640_ImageSensor_Set_Base();                  // Image sensor base setup
    if (status != CY_MIPI_SENSOR_SUCCESS)
    {
        return status;
    }
        
    status = Cy_OV5640_ImageSensor_Configure_Autofocus();       // Sensor set auto focus
    if (status != CY_MIPI_SENSOR_SUCCESS)
    {
        return status;
    }
    
    status = Cy_OV5640_ImageSensor_Set_VGA_Config();            // Set default resolution to VGA
    if (status != CY_MIPI_SENSOR_SUCCESS)
    {
        return status;
    }

    status = Cy_OV5640_Image_Sensor_Sleep();                    // Sensor sleep will turn off camera
    if (status != CY_MIPI_SENSOR_SUCCESS)
    {
        return status;
    }

    return status;
}

/*******************************************************************************
* Function Name: Cy_Mipi_Image_Sensor_DeInit
****************************************************************************//**
*
* \brief
* De-Initializes the Image Sensor Interface.
*
* \param none
*
* \return
* cy_en_mipi_sensor_result_t : function result type
*
*******************************************************************************/
cy_en_mipi_sensor_result_t Cy_Mipi_Image_Sensor_DeInit(void)
{
    cy_en_mipi_sensor_result_t status = CY_MIPI_SENSOR_SUCCESS;
    
    status = Cy_OV5640_Image_Sensor_Sleep();                    // Sensor sleep will turn off camera
    if (status != CY_MIPI_SENSOR_SUCCESS)
    {
        return status;
    }

    Cy_SCB_I2C_DeInit(CY_MIPI_CSI_I2C_TYPE);

    return status;
}

/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
