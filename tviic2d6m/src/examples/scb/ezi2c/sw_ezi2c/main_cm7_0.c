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

/*
    In this example, TVII works like as a serial memory.

    When master writes some data into TVII, master sends
    1 byte top address at first and then data consequentially.
    e.g.
        Master write 0x11, 0x22, 0x33 to address 0x01, 0x02, 0x03
        accordingly.
        - Master will send 0x01, 0x11, 0x22, 0x33

    When master reads some data from TVII, master sends 1 byte top address
    at first, and then sends read command.
     e.g.
        Master reads from address 0x04, 0x05, 0x06
        accordingly.
        - Master will send 0x04, then read 3 bytes.

    Own Address Buffer1(Primary):   0x08 (E_I2C_SLAVE_ADDR1)
    Own Address Buffer2(Secondary): 0x09 (E_I2C_SLAVE_ADDR2)
    Partner (Master) can access 2 memories of this EZI2C Slave
*/

/* Select Frequency */
/*   100KHz and 400KHz are checked on PSVP */
/*   1000KHz doesn't work on PSVP          */
#define E_I2C_DATARATE_100KHZ           100000
#define E_I2C_DATARATE_400KHZ           400000
#define E_I2C_DATARATE_1000KHZ          1000000
#define E_I2C_FREQUENCY                 E_I2C_DATARATE_100KHZ

/* Local Definision */
#define E_I2C_SCBCLK_2MHZ               2000000
#define E_I2C_SCBCLK_9_6MHZ             9600000
#define E_I2C_SCBCLK_24MHZ              24000000

#if   (E_I2C_FREQUENCY == E_I2C_DATARATE_100KHZ)
#define E_I2C_SCBCLK                    E_I2C_SCBCLK_2MHZ
#elif (E_I2C_FREQUENCY == E_I2C_DATARATE_400KHZ)
#define E_I2C_SCBCLK                    E_I2C_SCBCLK_9_6MHZ
#else // (E_I2C_FREQUENCY == E_I2C_DATARATE_1000KHZ)
#define E_I2C_SCBCLK                    E_I2C_SCBCLK_24MHZ
#endif

#define E_I2C_SLAVE_ADDR1               8
#define E_I2C_SLAVE_ADDR2               9
#define E_EZI2C_BUF1_SIZE               256
#define E_EZI2C_BUF1_REGION             128     // R/W:128 R:128
#define E_EZI2C_BUF2_SIZE               256
#define E_EZI2C_BUF2_REGION             192     // R/W:192 R:64

#if (CY_USE_PSVP == 1)
#define USER_I2C_SCB_TYPE               SCB0
#define USER_I2C_SDA_PORT               GPIO_PRT0           // TP7
#define USER_I2C_SDA_PIN                2
#define USER_I2C_SDA_PIN_MUX            P0_2_SCB0_I2C_SDA
#define USER_I2C_SCL_PORT               GPIO_PRT0           // TP6
#define USER_I2C_SCL_PIN                3
#define USER_I2C_SCL_PIN_MUX            P0_3_SCB0_I2C_SCL
#define USER_I2C_SCB_PCLK               PCLK_SCB0_CLOCK
#define USER_I2C_SCB_IRQN               scb_0_interrupt_IRQn
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


/* Local Functions Declaration */
void Peripheral_Initialization(void);
void Scb_EZI2C_Slave_IntrISR(void);

/* SCB - EZI2C Configuration */
static cy_stc_scb_ezi2c_context_t  g_stc_ezi2c_context;
static cy_stc_scb_ezi2c_config_t   g_stc_ezi2c_config = {
                                                   .numberOfAddresses   = CY_SCB_EZI2C_TWO_ADDRESSES,
                                                   .slaveAddress1       = E_I2C_SLAVE_ADDR1,
                                                   .slaveAddress2       = E_I2C_SLAVE_ADDR2,
                                                   .subAddressSize      = CY_SCB_EZI2C_SUB_ADDR8_BITS,
                                                   .enableWakeFromSleep = false
                                                };

/* Local Variables */
static uint8_t                     g_ezi2c_buf1[E_EZI2C_BUF1_SIZE] = {0};   // Primary
static uint8_t                     g_ezi2c_buf2[E_EZI2C_BUF2_SIZE] = {0};   // Secondary

int main(void)
{
    SystemInit();

    uint32_t i;

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    __enable_irq(); /* Enable global interrupts. */


    /* Initialize Port and Clock */
    Peripheral_Initialization();

    /* Initilize & Enable EZI2C */
    Cy_SCB_EZI2C_DeInit(USER_I2C_SCB_TYPE);
    Cy_SCB_EZI2C_Init(USER_I2C_SCB_TYPE, &g_stc_ezi2c_config, &g_stc_ezi2c_context);
    Cy_SCB_I2C_SetDataRate(USER_I2C_SCB_TYPE, E_I2C_FREQUENCY, E_I2C_SCBCLK);
    Cy_SCB_EZI2C_SetBuffer1(USER_I2C_SCB_TYPE, &g_ezi2c_buf1[0], E_EZI2C_BUF1_SIZE, E_EZI2C_BUF1_REGION, &g_stc_ezi2c_context);
    Cy_SCB_EZI2C_SetBuffer2(USER_I2C_SCB_TYPE, &g_ezi2c_buf2[0], E_EZI2C_BUF2_SIZE, E_EZI2C_BUF2_REGION, &g_stc_ezi2c_context);
    Cy_SCB_SetEzMode(USER_I2C_SCB_TYPE, false); // To execute SW EZI2C, EZ mode need to be disable
    Cy_SCB_EZI2C_Enable(USER_I2C_SCB_TYPE);

    /* Enable Interrrupt & Event*/
    NVIC_EnableIRQ(CPUIntIdx2_IRQn);

    /* EZI2C Slave Mode Test      */
    /*   Primary Address:    0x08 */
    /*   Secondary Address:  0x09 */

    /* Set Initial Value to Buffer for Buffer Test */
    for (i=0; i<E_EZI2C_BUF1_SIZE; i++) {
        g_ezi2c_buf1[i] = i;
    }

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

    /* scb.i2c_sda:0 */
    stc_port_pin_cfg.driveMode = CY_GPIO_DM_OD_DRIVESLOW;
    stc_port_pin_cfg.hsiom     = USER_I2C_SDA_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_I2C_SDA_PORT, USER_I2C_SDA_PIN, &stc_port_pin_cfg);

    /* scb.i2c_scl:0 */
    stc_port_pin_cfg.driveMode = CY_GPIO_DM_OD_DRIVESLOW;
    stc_port_pin_cfg.hsiom     = USER_I2C_SCL_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_I2C_SCL_PORT, USER_I2C_SCL_PIN, &stc_port_pin_cfg);

    /*---------------------*/
    /* Clock Configuration */
    /*---------------------*/

    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_2);

    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(USER_I2C_SCB_PCLK, CY_SYSCLK_DIV_24_5_BIT, 1u);
    
  #if (CY_USE_PSVP == 1)  
    /* Sets divider */
    #if   (E_I2C_FREQUENCY == E_I2C_DATARATE_100KHZ)
    /* Supported Frequency Range = 1.55 - 12.8 MHz */
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(USER_I2C_SCB_PCLK), CY_SYSCLK_DIV_24_5_BIT, 1u, 11u, 0u);        // for 100 kHz  (24 / 12  =  2 MHz)
    #elif (E_I2C_FREQUENCY == E_I2C_DATARATE_400KHZ)
    /* Supported Frequency Range = 7.82 - 15.38 MHz */
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(USER_I2C_SCB_PCLK), CY_SYSCLK_DIV_24_5_BIT, 1u, 1u, 16u);        // for 400 kHz  (24 / 2.5 = 9.6 MHz)
    #else //(E_I2C_FREQUENCY == E_I2C_DATARATE_1000KHZ)
    /* Supported Frequency Range = 15.84 - 48.0 MHz */
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(USER_I2C_SCB_PCLK), CY_SYSCLK_DIV_24_5_BIT, 1u, 0u, 0u);         // for 1000 kHz (24 / 1   = 24 MHz)
    #endif
  #else  
    // Set as close as possible to tested PSVP dividers    
  
    /* Sets divider */
    #if   (E_I2C_FREQUENCY == E_I2C_DATARATE_100KHZ)
    /* Supported Frequency Range = 1.55 - 12.8 MHz */
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(USER_I2C_SCB_PCLK), CY_SYSCLK_DIV_24_5_BIT, 1u, 39u, 0u);        // for 100 kHz  (80 / 40  =  2 MHz)
    #elif (E_I2C_FREQUENCY == E_I2C_DATARATE_400KHZ)
    /* Supported Frequency Range = 7.82 - 15.38 MHz */
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(USER_I2C_SCB_PCLK), CY_SYSCLK_DIV_24_5_BIT, 1u, 7u, 11u);        // for 400 kHz  (80 / 8.34375 = 9.59 MHz)
    #else //(E_I2C_FREQUENCY == E_I2C_DATARATE_1000KHZ)
    /* Supported Frequency Range = 15.84 - 48.0 MHz */
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(USER_I2C_SCB_PCLK), CY_SYSCLK_DIV_24_5_BIT, 1u, 2u, 11u);         // for 1000 kHz (80 / 3.34375   = 23.93 MHz)
    #endif
  #endif 

    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(USER_I2C_SCB_PCLK), CY_SYSCLK_DIV_24_5_BIT, 1u);

    /*--------------------------*/
    /* Interrrupt Configuration */
    /*--------------------------*/

    /* Int2 -> SCBx */
    stc_sysint_irq_cfg.sysIntSrc = USER_I2C_SCB_IRQN;
    stc_sysint_irq_cfg.intIdx    = CPUIntIdx2_IRQn;
    stc_sysint_irq_cfg.isEnabled = true;
    Cy_SysInt_InitIRQ(&stc_sysint_irq_cfg);
    Cy_SysInt_SetSystemIrqVector(stc_sysint_irq_cfg.sysIntSrc, Scb_EZI2C_Slave_IntrISR);
}

void Scb_EZI2C_Slave_IntrISR(void)
{
    /* EZI2C interrupt handler */
    Cy_SCB_EZI2C_Interrupt(USER_I2C_SCB_TYPE, &g_stc_ezi2c_context);
    NVIC_ClearPendingIRQ(CPUIntIdx2_IRQn);
}

/* [] END OF FILE */
