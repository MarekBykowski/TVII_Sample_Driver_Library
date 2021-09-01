/***************************************************************************//**
* \file main_cm7_0.c
*
* \version 1.0
*
* \brief Main example file for CM7_0
*
********************************************************************************
* \copyright
* Copyright 2016-2020, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <stdio.h>
#include <stdarg.h>

#include "cy_project.h"
#include "cy_device_headers.h"

/* I2C Master Mode Test                              */
/*                                                   */
/* Partner Address(Slave): 0x08 (E_I2C_SLAVE_ADDR)   */

#if (CY_USE_PSVP == 1)
#define USER_I2C_SCB_TYPE               SCB1 
#define USER_I2C_SDA_PORT               GPIO_PRT15              // TP277
#define USER_I2C_SDA_PIN                2
#define USER_I2C_SDA_PIN_MUX            P15_2_SCB1_I2C_SDA
#define USER_I2C_SCL_PORT               GPIO_PRT15              // TP278
#define USER_I2C_SCL_PIN                3
#define USER_I2C_SCL_PIN_MUX            P15_3_SCB1_I2C_SCL
#define USER_I2C_SCB_PCLK               PCLK_SCB1_CLOCK
#define USER_I2C_SCB_IRQN               scb_1_interrupt_IRQn
#else
#define USER_I2C_SCB_TYPE               SCB7
#define USER_I2C_SDA_PORT               GPIO_PRT9
#define USER_I2C_SDA_PIN                0
#define USER_I2C_SDA_PIN_MUX            P9_0_SCB7_I2C_SDA
#define USER_I2C_SCL_PORT               GPIO_PRT9
#define USER_I2C_SCL_PIN                1
#define USER_I2C_SCL_PIN_MUX            P9_1_SCB7_I2C_SCL
#define USER_I2C_SCB_PCLK               PCLK_SCB7_CLOCK
#define USER_I2C_SCB_IRQN               scb_7_interrupt_IRQn
#endif  // CY_USE_PSVP 


#define I2C_SDA_DRIVE_MODE              CY_GPIO_DM_OD_DRIVESLOW
#define I2C_SCL_DRIVE_MODE              CY_GPIO_DM_OD_DRIVESLOW

#define DIVIDER_NO_1 (1u)

/* Select Frequency */
#if (CY_USE_PSVP == 1)
  #define E_SOURCE_CLK_FREQ             (24000000) // fixed
#else
  #define E_SOURCE_CLK_FREQ             (80000000) // fixed
#endif
#define E_I2C_INCLK_TARGET_FREQ         (2000000)  // modifiable
#define E_I2C_DATARATE                  (100000)   // modifiable

#define E_I2C_SLAVE_ADDR                8
#define E_I2C_RECV_SIZE                 9

static cy_stc_gpio_pin_config_t I2S_port_pin_cfg =
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

static cy_stc_sysint_irq_t irq_cfg =
{
    .sysIntSrc  = USER_I2C_SCB_IRQN,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = true,
};

/* SCB - I2C Configuration */
static cy_stc_scb_i2c_context_t g_stc_i2c_context;
static const cy_stc_scb_i2c_config_t  g_stc_i2c_config =
{
    .i2cMode             = CY_SCB_I2C_MASTER,
    .useRxFifo           = true,
    .useTxFifo           = true,
    .slaveAddress        = E_I2C_SLAVE_ADDR,
    .slaveAddressMask    = E_I2C_SLAVE_ADDR,
    .acceptAddrInFifo    = false,
    .ackGeneralAddr      = false,
    .enableWakeFromSleep = false
};

static cy_stc_scb_i2c_master_xfer_config_t g_stc_i2c_master_config =
{
    .slaveAddress = E_I2C_SLAVE_ADDR,
    .buffer       = 0,
    .bufferSize   = 0,
    .xferPending  = false
};

/* Local Variables */
static uint8_t g_i2c_tx_buf[32];
static uint8_t g_i2c_rx_buf[32];
static uint8_t g_send_byte = 0xF1;
static uint8_t g_recv_byte = 0x00;

void Scb_I2C_IntrISR(void)
{
    /* I2C interrupt handler for High-Level APIs */
    Cy_SCB_I2C_Interrupt(USER_I2C_SCB_TYPE, &g_stc_i2c_context);
}

void SetPeripheFracDiv24_5(uint64_t targetFreq, uint64_t sourceFreq, uint8_t divNum)
{
    uint64_t temp = ((uint64_t)sourceFreq << 5ull);
    uint32_t divSetting;

    divSetting = (uint32_t)(temp / targetFreq);
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(USER_I2C_SCB_PCLK), 
                                   CY_SYSCLK_DIV_24_5_BIT, divNum, 
                                   (((divSetting >> 5u) & 0x00000FFF) - 1u), 
                                   (divSetting & 0x0000001F));
}
void Scb_I2C_Master_Event(uint32_t locEvents)
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

void Scb_I2C_Master_LowLevelAPI_Test(void)
{
    cy_en_scb_i2c_status_t  result_i2c;

    /*------------------------*/
    /* I2C Low-Level API Test */
    /*------------------------*/

    /* I2C Master Byte Write */

    /* Send START and Recieve ACK/NACK */
    result_i2c = Cy_SCB_I2C_MasterSendStart(USER_I2C_SCB_TYPE, E_I2C_SLAVE_ADDR, CY_SCB_I2C_WRITE_XFER, 2000, &g_stc_i2c_context);
    if (result_i2c == CY_SCB_I2C_SUCCESS)
    {
        /* Check TX FIFO Empty (Pass) */
        /* Transmite One Byte Data */
        result_i2c = Cy_SCB_I2C_MasterWriteByte(USER_I2C_SCB_TYPE, g_send_byte, 2000, &g_stc_i2c_context);

        /* Check Recieve ACK (Pass) */
        /* Send STOP */
        result_i2c = Cy_SCB_I2C_MasterSendStop(USER_I2C_SCB_TYPE, 2000, &g_stc_i2c_context);
    }

    /* I2C Master Byte Read */

    /* Send START and Recieve ACK/NACK */
    result_i2c = Cy_SCB_I2C_MasterSendStart(USER_I2C_SCB_TYPE, E_I2C_SLAVE_ADDR, CY_SCB_I2C_READ_XFER, 2000, &g_stc_i2c_context);
    if (result_i2c == CY_SCB_I2C_SUCCESS)
    {
        /* Check RX FIFO Full (Pass) */
        /* Receive One Byte Data */
        result_i2c = Cy_SCB_I2C_MasterReadByte(USER_I2C_SCB_TYPE, CY_SCB_I2C_NAK, &g_recv_byte, 2000, &g_stc_i2c_context);

        /* Check Recieve ACK (Pass) */
        /* Send STOP */
        result_i2c = Cy_SCB_I2C_MasterSendStop(USER_I2C_SCB_TYPE, 2000, &g_stc_i2c_context);
    }
}

void Scb_I2C_Master_HighLevelAPI_Test(void)
{
    /*-------------------------*/
    /* I2C High-Level API Test */
    /*-------------------------*/

    /* I2C Master Write */
    sprintf((char *)&g_i2c_tx_buf[0], "ABCDEFG012345!");
    g_stc_i2c_master_config.buffer     = &g_i2c_tx_buf[0];
    g_stc_i2c_master_config.bufferSize = strlen((char *)g_i2c_tx_buf);
    Cy_SCB_I2C_MasterWrite(USER_I2C_SCB_TYPE, &g_stc_i2c_master_config, &g_stc_i2c_context);

    Cy_SysTick_DelayInUs(100000UL);

    /* I2C Master Read */
    g_stc_i2c_master_config.buffer     = &g_i2c_rx_buf[0];
    g_stc_i2c_master_config.bufferSize = E_I2C_RECV_SIZE;
    Cy_SCB_I2C_MasterRead(USER_I2C_SCB_TYPE, &g_stc_i2c_master_config, &g_stc_i2c_context);
}

int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    __enable_irq(); /* Enable global interrupts. */

    /*---------------------*/
    /* Clock Configuration */
    /*---------------------*/
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_2);

    Cy_SysClk_PeriphAssignDivider(USER_I2C_SCB_PCLK, CY_SYSCLK_DIV_24_5_BIT, DIVIDER_NO_1);
    SetPeripheFracDiv24_5(E_I2C_INCLK_TARGET_FREQ, E_SOURCE_CLK_FREQ, DIVIDER_NO_1);
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(USER_I2C_SCB_PCLK), CY_SYSCLK_DIV_24_5_BIT, DIVIDER_NO_1);

    /*--------------------*/
    /* Port Configuration */
    /*--------------------*/
    I2S_port_pin_cfg.driveMode = I2C_SDA_DRIVE_MODE;
    I2S_port_pin_cfg.hsiom     = USER_I2C_SDA_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_I2C_SDA_PORT, USER_I2C_SDA_PIN, &I2S_port_pin_cfg);

    I2S_port_pin_cfg.driveMode = I2C_SCL_DRIVE_MODE;
    I2S_port_pin_cfg.hsiom     = USER_I2C_SCL_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_I2C_SCL_PORT, USER_I2C_SCL_PIN, &I2S_port_pin_cfg);

    /*--------------------------*/
    /* Interrrupt Configuration */
    /*--------------------------*/
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, Scb_I2C_IntrISR);
    NVIC_EnableIRQ(irq_cfg.intIdx);

    /*--------------------------*/
    /*  Initilize & Enable I2C  */
    /*--------------------------*/
    Cy_SCB_I2C_DeInit(USER_I2C_SCB_TYPE);
    Cy_SCB_I2C_Init(USER_I2C_SCB_TYPE, &g_stc_i2c_config, &g_stc_i2c_context);
    Cy_SCB_I2C_SetDataRate(USER_I2C_SCB_TYPE, E_I2C_DATARATE, E_I2C_INCLK_TARGET_FREQ);
    Cy_SCB_I2C_RegisterEventCallback(USER_I2C_SCB_TYPE, (scb_i2c_handle_events_t)Scb_I2C_Master_Event, &g_stc_i2c_context);
    Cy_SCB_I2C_Enable(USER_I2C_SCB_TYPE);
    /* I2C Master Mode Test */
    Scb_I2C_Master_LowLevelAPI_Test();
    Scb_I2C_Master_HighLevelAPI_Test();

    for(;;);
}
/* [] END OF FILE */

