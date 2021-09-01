/***************************************************************************//**
* \file main_cm0plus.c
*
* \version 1.0
*
* \brief Main example file for CM0+
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

/* I2C Slave Mode Test                              */
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

#define DIVIDER_NO_1                    (1u)

/* Select Frequency */
#if (CY_USE_PSVP == 1)
  #define E_SOURCE_CLK_FREQ             (24000000) // fixed
#else
  #define E_SOURCE_CLK_FREQ             (80000000) // fixed
#endif
#define E_I2C_INCLK_TARGET_FREQ         (2000000)  // modifiable
#define E_I2C_DATARATE                  (100000)   // modifiable

#define E_I2C_SLAVE_ADDR                8
#define E_I2C_SLAVE_TXRX_BUF_SIZE       32
#define E_I2C_SLAVE_USER_BUF_SIZE       32     // should be 2^n

static cy_stc_gpio_pin_config_t I2C_port_pin_cfg =
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
static cy_stc_scb_i2c_context_t    g_stc_i2c_context;
static cy_stc_scb_i2c_config_t     g_stc_i2c_config =
{
    .i2cMode             = CY_SCB_I2C_SLAVE,
    .useRxFifo           = true,
    .useTxFifo           = true,
    .slaveAddress        = E_I2C_SLAVE_ADDR,
    .slaveAddressMask    = 0x7F,
    .acceptAddrInFifo    = false,
    .ackGeneralAddr      = true,
    .enableWakeFromSleep = false
};

/* Local Variables */
static uint8_t g_i2c_tx_buf[E_I2C_SLAVE_TXRX_BUF_SIZE] = 
{
    0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x50,
    0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x60,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
    0x71, 0x72
};
static uint8_t          g_i2c_rx_buf[E_I2C_SLAVE_TXRX_BUF_SIZE];
static volatile uint8_t g_i2c_user_buf[E_I2C_SLAVE_USER_BUF_SIZE] = {0};
static uint8_t          g_i2c_user_buf_index = 0;

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
void Scb_I2C_Slave_Event(uint32_t locEvents)
{
    uint8_t recv_size;
    switch (locEvents)
    {
    case CY_SCB_I2C_SLAVE_READ_EVENT:
        break;
    case CY_SCB_I2C_SLAVE_WRITE_EVENT:
        break;
    case CY_SCB_I2C_SLAVE_RD_IN_FIFO_EVENT:
        break;
    case CY_SCB_I2C_SLAVE_RD_BUF_EMPTY_EVENT:
        break;
    case CY_SCB_I2C_SLAVE_RD_CMPLT_EVENT:
        /* Clear Read Buffer (use same buffer) */
        Cy_SCB_I2C_SlaveConfigReadBuf(USER_I2C_SCB_TYPE, &g_i2c_tx_buf[0], E_I2C_SLAVE_TXRX_BUF_SIZE, &g_stc_i2c_context);
        break;
    case CY_SCB_I2C_SLAVE_WR_CMPLT_EVENT:
        /* Copy Recieved Data to User Buffer(g_i2c_user_buf[32]) */
        recv_size  = Cy_SCB_I2C_SlaveGetWriteTransferCount(USER_I2C_SCB_TYPE, &g_stc_i2c_context);
        if (recv_size != 0)
        {
            for (uint8_t i = 0; i < recv_size; i++)
            {
                g_i2c_user_buf[g_i2c_user_buf_index] = g_i2c_rx_buf[i];
                g_i2c_user_buf_index = (g_i2c_user_buf_index + 1) & (E_I2C_SLAVE_USER_BUF_SIZE - 1);
            }
        }
        /* Clear Write Buffer */
        Cy_SCB_I2C_SlaveConfigWriteBuf(USER_I2C_SCB_TYPE, &g_i2c_rx_buf[0], E_I2C_SLAVE_TXRX_BUF_SIZE, &g_stc_i2c_context);
        break;
    case CY_SCB_I2C_SLAVE_ERR_EVENT:
        break;
    default:
        break;
    }
}

int main(void)
{
    SystemInit();

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
    I2C_port_pin_cfg.driveMode = I2C_SDA_DRIVE_MODE;
    I2C_port_pin_cfg.hsiom     = USER_I2C_SDA_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_I2C_SDA_PORT, USER_I2C_SDA_PIN, &I2C_port_pin_cfg);

    I2C_port_pin_cfg.driveMode = I2C_SCL_DRIVE_MODE;
    I2C_port_pin_cfg.hsiom     = USER_I2C_SCL_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_I2C_SCL_PORT, USER_I2C_SCL_PIN, &I2C_port_pin_cfg);

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
    Cy_SCB_I2C_SlaveConfigWriteBuf(USER_I2C_SCB_TYPE, &g_i2c_rx_buf[0], E_I2C_SLAVE_TXRX_BUF_SIZE, &g_stc_i2c_context);
    Cy_SCB_I2C_SlaveConfigReadBuf(USER_I2C_SCB_TYPE, &g_i2c_tx_buf[0], E_I2C_SLAVE_TXRX_BUF_SIZE, &g_stc_i2c_context);
    Cy_SCB_I2C_RegisterEventCallback(USER_I2C_SCB_TYPE, (scb_i2c_handle_events_t)Scb_I2C_Slave_Event, &g_stc_i2c_context);
    Cy_SCB_I2C_Enable(USER_I2C_SCB_TYPE);
    for(;;);
}
/* [] END OF FILE */

