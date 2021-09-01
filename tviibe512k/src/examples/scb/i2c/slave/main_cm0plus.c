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

/* I2C Slave Mode Test                                                        */
/*                                                                            */
/* Own Address(Slave): 0x08 (E_I2C_SLAVE_ADDR)                                */
/*                                                                            */
/* - send read data (g_i2c_tx_buf) when receiving read frame from master      */
/* - receive write data (g_i2c_rx_buf) and copy to user buffer (g_i2c_rx_buf) */

/* Select Frequency */
/*   100KHz and 400KHz are checked on PSVP */
/*   1000KHz doesn't work on PSVP          */
#define E_I2C_DATARATE_100KHZ       100000
#define E_I2C_DATARATE_400KHZ       400000
#define E_I2C_DATARATE_1000KHZ      1000000
#define E_I2C_FREQUENCY             E_I2C_DATARATE_100KHZ

/* Local Definision */
#define E_I2C_SCBCLK_2MHZ           2000000
#define E_I2C_SCBCLK_9_6MHZ         9600000
#define E_I2C_SCBCLK_24MHZ          24000000
#if   (E_I2C_FREQUENCY == E_I2C_DATARATE_100KHZ)
#define E_I2C_SCBCLK                E_I2C_SCBCLK_2MHZ
#elif (E_I2C_FREQUENCY == E_I2C_DATARATE_400KHZ)
#define E_I2C_SCBCLK                E_I2C_SCBCLK_9_6MHZ
#else // (E_I2C_FREQUENCY == E_I2C_DATARATE_1000KHZ)
#define E_I2C_SCBCLK                E_I2C_SCBCLK_24MHZ
#endif
#define E_I2C_SLAVE_ADDR            8
#define E_I2C_SLAVE_TXRX_BUF_SIZE   32
#define E_I2C_SLAVE_USER_BUF_SIZE   32     // should be 2^n

/* Select SCB Index */
#define USER_I2C_SCB_TYPE           SCB4
#define USER_I2C_SCB_PCLK           PCLK_SCB4_CLOCK
#define USER_I2C_SCB_IRQN           scb_4_interrupt_IRQn


/* Local Functions Declaration */
void Peripheral_Initialization(void);
void Scb_I2C_Slave_IntrISR(void);
void Scb_I2C_Slave_Event(uint32_t locEvents);

/* SCB - I2C Configuration */
static cy_stc_scb_i2c_context_t    g_stc_i2c_context;
static cy_stc_scb_i2c_config_t     g_stc_i2c_config = {
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
static uint8_t                     g_i2c_tx_buf[E_I2C_SLAVE_TXRX_BUF_SIZE] = {
                                                   0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x50,
                                                   0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x60,
                                                   0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
                                                   0x71, 0x72
                                                };
static uint8_t                     g_i2c_rx_buf[E_I2C_SLAVE_TXRX_BUF_SIZE];
static volatile uint8_t            g_i2c_user_buf[E_I2C_SLAVE_USER_BUF_SIZE] = {0};
static uint8_t                     g_i2c_user_buf_index = 0;

int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */
    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR); 

    /* Initialize Port and Clock */
    Peripheral_Initialization();

    /* Initilize & Enable I2C */
    Cy_SCB_I2C_DeInit(USER_I2C_SCB_TYPE);
    Cy_SCB_I2C_Init(USER_I2C_SCB_TYPE, &g_stc_i2c_config, &g_stc_i2c_context);
    Cy_SCB_I2C_SetDataRate(USER_I2C_SCB_TYPE, E_I2C_FREQUENCY, E_I2C_SCBCLK);
    Cy_SCB_I2C_SlaveConfigWriteBuf(USER_I2C_SCB_TYPE, &g_i2c_rx_buf[0], E_I2C_SLAVE_TXRX_BUF_SIZE, &g_stc_i2c_context);
    Cy_SCB_I2C_SlaveConfigReadBuf(USER_I2C_SCB_TYPE, &g_i2c_tx_buf[0], E_I2C_SLAVE_TXRX_BUF_SIZE, &g_stc_i2c_context);
    Cy_SCB_I2C_RegisterEventCallback(USER_I2C_SCB_TYPE, (scb_i2c_handle_events_t)Scb_I2C_Slave_Event, &g_stc_i2c_context);
    Cy_SCB_I2C_Enable(USER_I2C_SCB_TYPE);

    /* Enable Interrrupt & Event*/
    NVIC_EnableIRQ(CPUIntIdx2_IRQn);

    for(;;)
    {
    }
}

void Peripheral_Initialization(void)
{
    cy_stc_gpio_pin_config_t    stc_port_pin_cfg = {0};
    cy_stc_sysint_irq_t         stc_sysint_irq_cfg;

    /*--------------------*/
    /* Port Configuration */
    /*--------------------*/

    /* P6.1 -> scb[4].i2c_sda:0 */
    /* If you use 176 pin MCU, please use J2.10 on the base board. */
    /* If you use 64 pin MCU,  please use J2.10 on the base board. */
    /* If you use 144 pin MCU,  please use J2.10 on the base board. */
    stc_port_pin_cfg.driveMode = CY_GPIO_DM_OD_DRIVESLOW;
    stc_port_pin_cfg.hsiom     = P6_1_SCB4_I2C_SDA;
    Cy_GPIO_Pin_Init(GPIO_PRT6, 1, &stc_port_pin_cfg);

    /* P6.2 -> scb[4].i2c_scl:0 */
    /* If you use 176 pin MCU, please use J2.12 on the base board. */
    /* If you use 64 pin MCU,  please use J12.5 on the base board. */
    /* If you use 144 pin MCU,  please use J2.12 on the base board. */
    stc_port_pin_cfg.driveMode = CY_GPIO_DM_OD_DRIVESLOW;
    stc_port_pin_cfg.hsiom     = P6_2_SCB4_I2C_SCL;
    Cy_GPIO_Pin_Init(GPIO_PRT6, 2, &stc_port_pin_cfg);

    /*---------------------*/
    /* Clock Configuration */
    /*---------------------*/

    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(USER_I2C_SCB_PCLK, CY_SYSCLK_DIV_24_5_BIT, 1u);
    
  #if (CY_USE_PSVP == 1)  
    /* Sets divider */
    #if   (E_I2C_FREQUENCY == E_I2C_DATARATE_100KHZ)
    /* Supported Frequency Range = 1.55 - 12.8 MHz */
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, 1u, 11u, 0u);        // for 100 kHz  (24 / 12  =  2 MHz)
    #elif (E_I2C_FREQUENCY == E_I2C_DATARATE_400KHZ)
    /* Supported Frequency Range = 7.82 - 15.38 MHz */
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, 1u, 1u, 16u);        // for 400 kHz  (24 / 2.5 = 9.6 MHz)
    #else //(E_I2C_FREQUENCY == E_I2C_DATARATE_1000KHZ)
    /* Supported Frequency Range = 15.84 - 48.0 MHz */
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, 1u, 0u, 0u);         // for 1000 kHz (24 / 1   = 24 MHz)
    #endif
  #else  
    // Set as close as possible to tested PSVP dividers    
  
    /* Sets divider */
    #if   (E_I2C_FREQUENCY == E_I2C_DATARATE_100KHZ)
    /* Supported Frequency Range = 1.55 - 12.8 MHz */
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, 1u, 39u, 0u);        // for 100 kHz  (80 / 40  =  2 MHz)
    #elif (E_I2C_FREQUENCY == E_I2C_DATARATE_400KHZ)
    /* Supported Frequency Range = 7.82 - 15.38 MHz */
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, 1u, 7u, 11u);        // for 400 kHz  (80 / 8.34375 = 9.59 MHz)
    #else //(E_I2C_FREQUENCY == E_I2C_DATARATE_1000KHZ)
    /* Supported Frequency Range = 15.84 - 48.0 MHz */
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, 1u, 2u, 11u);         // for 1000 kHz (80 / 3.34375   = 23.93 MHz)
    #endif
  #endif 

    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_24_5_BIT, 1u);

    /*--------------------------*/
    /* Interrrupt Configuration */
    /*--------------------------*/

    /* Int2 -> SCBx */
    stc_sysint_irq_cfg.sysIntSrc = USER_I2C_SCB_IRQN;
    stc_sysint_irq_cfg.intIdx    = CPUIntIdx2_IRQn;
    stc_sysint_irq_cfg.isEnabled = true;
    Cy_SysInt_InitIRQ(&stc_sysint_irq_cfg);
    Cy_SysInt_SetSystemIrqVector(stc_sysint_irq_cfg.sysIntSrc, Scb_I2C_Slave_IntrISR);
}

void Scb_I2C_Slave_IntrISR(void)
{
    /* I2C interrupt handler */
    Cy_SCB_I2C_Interrupt(USER_I2C_SCB_TYPE, &g_stc_i2c_context);
    NVIC_ClearPendingIRQ(CPUIntIdx2_IRQn);
}

void Scb_I2C_Slave_Event(uint32_t locEvents)
{
    uint8_t i;
    uint8_t recv_size;

    switch (locEvents) {

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
            if (recv_size != 0) {
                for (i=0; i<recv_size; i++) {
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

/* [] END OF FILE */

