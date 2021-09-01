/***************************************************************************//**
* \file cy_cs42448.c
* \version 1.0
*
* \brief
* Provides an API defination of the audio codec (CS42448) driver.
*
********************************************************************************
* \copyright
* Copyright 2019-2020, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/** Include section */
#include"cy_cs42448.h"

#if defined(__cplusplus)
extern "C" {
#endif


/* I2C port configuration macro */
static cy_stc_gpio_pin_config_t codec_i2c_port_pin_cfg =
{
    .outVal   = 0x00,
    .intEdge  = 0,
    .intMask  = 0,
    .driveSel = 0,
};

/* I2C irq configuration macro */
static cy_stc_sysint_irq_t codec_i2c_irq_cfg =
{
    .sysIntSrc  = CY_AUDIOSS_I2C_IRQN,
    .intIdx     = CPUIntIdx4_IRQn,
    .isEnabled  = true,
};

/* I2C master configuration macro */
static cy_stc_scb_i2c_config_t codec_i2c_stc_config =
{
    .i2cMode             = CY_SCB_I2C_MASTER,
    .useRxFifo           = true,
    .useTxFifo           = true,
    .acceptAddrInFifo    = false,
    .ackGeneralAddr      = false,
    .enableWakeFromSleep = false
};

/* I2C master configuration structure */
static cy_stc_scb_i2c_master_xfer_config_t codec_i2c_stc_master_config =
{
    .buffer       = 0,
    .bufferSize   = 0,
    .xferPending  = false
};

/* Audio codec interface I2C contex */
static cy_stc_scb_i2c_context_t codec_i2c_stc_context;


/*******************************************************************************
* Function Name: Cy_Cs42448_Scb_I2C_IntrISR
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
static void Cy_Cs42448_Scb_I2C_IntrISR(void)
{
    /* I2C interrupt handler for High-Level APIs */
    Cy_SCB_I2C_Interrupt(CY_AUDIOSS_I2C_TYPE, &codec_i2c_stc_context);
}

/*******************************************************************************
* Function Name: Cy_Cs42448_SetPeripheFracDiv24_5
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
static void Cy_Cs42448_SetPeripheFracDiv24_5(uint64_t targetFreq, uint64_t sourceFreq, uint8_t divNum)
{
    uint64_t temp = ((uint64_t)sourceFreq << 5ull);
    uint32_t divSetting;

    divSetting = (uint32_t)(temp / targetFreq);
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_AUDIOSS_I2C_PCLK), 
                                   CY_SYSCLK_DIV_24_5_BIT, divNum, 
                                   (((divSetting >> 5u) & 0x00000FFF) - 1u), 
                                   (divSetting & 0x0000001F));
}

/*******************************************************************************
* Function Name: Cy_Cs42448_Scb_I2C_MasterEvent
****************************************************************************//**
*
* \brief
* Codec i2c event callback.
*
* \param
* locEvents : i2c block generated event id
*
* \return none
*
*******************************************************************************/
static void Cy_Cs42448_Scb_I2C_MasterEvent(uint32_t locEvents)
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
* Function Name: Cy_Cs42448_Init
****************************************************************************//**
*
* \brief
* Function to initialize i2c control path for audio codec.
*
* \param
* none
*
* \return 
* none
*
* \note
* SCB3 is fixed for the audio codec control path.
* 
*******************************************************************************/
void Cy_Cs42448_Init(void)
{
    /* Setup the hfclk for i2c interface */
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_2);

    /* Setup the peri clock for i2c interface */
    Cy_SysClk_PeriphAssignDivider(CY_AUDIOSS_I2C_PCLK, CY_SYSCLK_DIV_24_5_BIT, CY_CS42448_I2C_DIVIDER_NO);
    Cy_Cs42448_SetPeripheFracDiv24_5(CY_CS42448_I2C_INCLK_TARGET_FREQ, CY_CS42448_I2C_SOURCE_CLK_FREQ, CY_CS42448_I2C_DIVIDER_NO);
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(CY_AUDIOSS_I2C_PCLK), CY_SYSCLK_DIV_24_5_BIT, CY_CS42448_I2C_DIVIDER_NO);

    /* Port pin configuration for i2c instance */
    codec_i2c_port_pin_cfg.driveMode = CY_GPIO_DM_OD_DRIVESLOW;
    codec_i2c_port_pin_cfg.hsiom     = CY_AUDIOSS_I2C_SDA_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_I2C_SDA_PORT, CY_AUDIOSS_I2C_SDA_PIN, &codec_i2c_port_pin_cfg);

    codec_i2c_port_pin_cfg.driveMode = CY_GPIO_DM_OD_DRIVESLOW;
    codec_i2c_port_pin_cfg.hsiom     = CY_AUDIOSS_I2C_SCL_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_I2C_SCL_PORT, CY_AUDIOSS_I2C_SCL_PIN, &codec_i2c_port_pin_cfg);

    /* Interrrupt configuration for i2c instance */
    Cy_SysInt_InitIRQ(&codec_i2c_irq_cfg);
    Cy_SysInt_SetSystemIrqVector(codec_i2c_irq_cfg.sysIntSrc, Cy_Cs42448_Scb_I2C_IntrISR);
    NVIC_EnableIRQ(codec_i2c_irq_cfg.intIdx);
    
    /* Initilize & enable i2c  */
    Cy_SCB_I2C_Init(CY_AUDIOSS_I2C_TYPE, &codec_i2c_stc_config, &codec_i2c_stc_context);
    Cy_SCB_I2C_SetDataRate(CY_AUDIOSS_I2C_TYPE, CY_CS42448_I2C_DATARATE, CY_CS42448_I2C_INCLK_TARGET_FREQ);
    Cy_SCB_I2C_RegisterEventCallback(CY_AUDIOSS_I2C_TYPE, (scb_i2c_handle_events_t)Cy_Cs42448_Scb_I2C_MasterEvent, &codec_i2c_stc_context);
    Cy_SCB_I2C_Enable(CY_AUDIOSS_I2C_TYPE);
}

/*******************************************************************************
* Function Name: Cy_Cs42448_WriteCtrReg
****************************************************************************//**
* \brief
* This function used to write the control registers of the codec CS42448.
*
* \param regAddr
* CS42448 Register address to which the data is to be written
*
* \param data
* Data to be written
*
* \return
* none
*
*******************************************************************************/
void Cy_Cs42448_WriteCtrReg(cy_en_cs42448_registers_t regAddr, uint8_t data)
{
    uint8_t writeBuffer[2] = {regAddr, data};

    codec_i2c_stc_master_config.slaveAddress = CY_CS42448_SLAVE_ADDR;
    codec_i2c_stc_master_config.buffer       = writeBuffer;
    codec_i2c_stc_master_config.bufferSize   = sizeof(writeBuffer);
	
    Cy_SCB_I2C_MasterWrite(CY_AUDIOSS_I2C_TYPE, &codec_i2c_stc_master_config, &codec_i2c_stc_context);

    // Wait until I2C Master is ready
    while (0u != (Cy_SCB_I2C_MasterGetStatus(CY_AUDIOSS_I2C_TYPE, &codec_i2c_stc_context) & CY_SCB_I2C_MASTER_BUSY));
}

/*******************************************************************************
* Function Name: Cy_Cs42448_ReadCtrReg
****************************************************************************//**
* \brief
* This function used to write the control registers of the codec CS42448.
*
* \param regAddr
* CS42448 Register address to which the data is to be written
*
* \return
* uint8_t read data from the codec register
*
*******************************************************************************/
uint8_t Cy_Cs42448_ReadCtrReg(cy_en_cs42448_registers_t regAddr)
{
    uint8_t readData[2] = {0x00u};                                            
    uint8_t writeBuffer[1] = {regAddr};

    codec_i2c_stc_master_config.slaveAddress = CY_CS42448_SLAVE_ADDR;
    codec_i2c_stc_master_config.buffer       = writeBuffer;
    codec_i2c_stc_master_config.bufferSize   = sizeof(writeBuffer);
    Cy_SCB_I2C_MasterWrite(CY_AUDIOSS_I2C_TYPE, &codec_i2c_stc_master_config, &codec_i2c_stc_context);

    // Wait until I2C Master is ready
    while (0u != (Cy_SCB_I2C_MasterGetStatus(CY_AUDIOSS_I2C_TYPE, &codec_i2c_stc_context) & CY_SCB_I2C_MASTER_BUSY));

    codec_i2c_stc_master_config.buffer       = readData;
    codec_i2c_stc_master_config.bufferSize   = 1;
    Cy_SCB_I2C_MasterRead(CY_AUDIOSS_I2C_TYPE, &codec_i2c_stc_master_config, &codec_i2c_stc_context);

    // Wait until I2C Master is ready
    while (0u != (Cy_SCB_I2C_MasterGetStatus(CY_AUDIOSS_I2C_TYPE, &codec_i2c_stc_context) & CY_SCB_I2C_MASTER_BUSY));

    return readData[0];
}


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

/* [] END OF FILE */
