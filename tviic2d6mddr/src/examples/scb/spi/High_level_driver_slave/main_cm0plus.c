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

#include "cy_project.h"
#include "cy_device_headers.h"

#if (CY_USE_PSVP == 1)
#define SCB_CH_TO_BE_USED               SCB1
#define SCB_MISO_PORT                   GPIO_PRT17                      // TP298
#define SCB_MISO_PIN                    1
#define SCB_MISO_PIN_MUX                P17_1_SCB1_SPI_MISO
#define SCB_MOSI_PORT                   GPIO_PRT17                      // J1_36
#define SCB_MOSI_PIN                    0
#define SCB_MOSI_PIN_MUX                P17_0_SCB1_SPI_MOSI
#define SCB_CLK_PORT                    GPIO_PRT16                      // J1_38
#define SCB_CLK_PIN                     7
#define SCB_CLK_PIN_MUX                 P16_7_SCB1_SPI_CLK
#define SCB_SS0_PORT                    GPIO_PRT16                      // J12_10
#define SCB_SS0_PIN                     6
#define SCB_SS0_PIN_MUX                 P16_6_SCB1_SPI_SELECT0
#define SCB_CLOCK                       PCLK_SCB1_CLOCK
#define SCB_INTERRUPT_NO                scb_1_interrupt_IRQn
#define SOURCE_CLOCK_FRQ                24000000ul
#else
#define SCB_CH_TO_BE_USED               SCB0
#define SCB_MISO_PORT                   GPIO_PRT11
#define SCB_MISO_PIN                    0
#define SCB_MISO_PIN_MUX                P11_0_SCB0_SPI_MISO
#define SCB_MOSI_PORT                   GPIO_PRT10
#define SCB_MOSI_PIN                    1
#define SCB_MOSI_PIN_MUX                P10_1_SCB0_SPI_MOSI
#define SCB_CLK_PORT                    GPIO_PRT10
#define SCB_CLK_PIN                     0
#define SCB_CLK_PIN_MUX                 P10_0_SCB0_SPI_CLK
#define SCB_SS0_PORT                    GPIO_PRT11
#define SCB_SS0_PIN                     1
#define SCB_SS0_PIN_MUX                 P11_1_SCB0_SPI_SELECT0
#define SCB_CLOCK                       PCLK_SCB0_CLOCK
#define SCB_INTERRUPT_NO                scb_0_interrupt_IRQn
#define SOURCE_CLOCK_FRQ                80000000ul
#endif

#define SCB_SPI_BAUDRATE                125000ul  /* Please set baudrate value of SPI you want */
#define SCB_SPI_OVERSAMPLING            16ul   /* Please set oversampling of SPI you want */
#define SCB_SPI_CLOCK_FREQ              (SCB_SPI_BAUDRATE * SCB_SPI_OVERSAMPLING)
#define DIVIDER_NO_1                    (1u)

/* Slave Settings */
#define SCB_MISO_DRIVE_MODE             CY_GPIO_DM_STRONG_IN_OFF
#define SCB_MOSI_DRIVE_MODE             CY_GPIO_DM_HIGHZ
#define SCB_CLK_DRIVE_MODE              CY_GPIO_DM_HIGHZ
#define SCB_SEL0_DRIVE_MODE             CY_GPIO_DM_HIGHZ

cy_stc_scb_spi_context_t contextSCB;

static cy_stc_gpio_pin_config_t SPI_port_pin_cfg =
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
    .sysIntSrc  = SCB_INTERRUPT_NO,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = true,
};
uint8_t testRxBuff[256];
uint8_t testTxBuff[256];
uint32_t transferStatus;

static const cy_stc_scb_spi_config_t SCB_SPI_cfg =
{
    .spiMode                    = CY_SCB_SPI_SLAVE,       /*** Specifies the mode of operation    ***/
    .subMode                    = CY_SCB_SPI_MOTOROLA,    /*** Specifies the submode of SPI operation    ***/
    .sclkMode                   = CY_SCB_SPI_CPHA0_CPOL0, /*** Clock is active low, data is changed on first edge ***/
    .oversample                 = SCB_SPI_OVERSAMPLING,   /*** SPI_CLOCK divided by SCB_SPI_OVERSAMPLING shoud be baudrate  ***/
    .rxDataWidth                = 16,                     /*** The width of RX data (valid range 4-16). It must be the same as \ref txDataWidth except in National sub-mode. ***/
    .txDataWidth                = 16,                     /*** The width of TX data (valid range 4-16). It must be the same as \ref rxDataWidth except in National sub-mode. ***/
    .enableMsbFirst             = true,                   /*** Enables the hardware to shift out the data element MSB first, otherwise, LSB first ***/
    .enableFreeRunSclk          = false,                  /*** Enables the master to generate a continuous SCLK regardless of whether there is data to send  ***/
    .enableInputFilter          = false,                  /*** Enables a digital 3-tap median filter to be applied to the input of the RX FIFO to filter glitches on the line. ***/
    .enableMisoLateSample       = true,                   /*** Enables the master to sample MISO line one half clock later to allow better timings. ***/
    .enableTransferSeperation   = true,                   /*** Enables the master to transmit each data element separated by a de-assertion of the slave select line (only applicable for the master mode) ***/
    .ssPolarity0                = 0,                      /*** SS0: active low ***/
    .ssPolarity1                = 0,                      /*** SS1: active low ***/
    .ssPolarity2                = 0,                      /*** SS2: active low ***/
    .ssPolarity3                = 0,                      /*** SS3: active low ***/
    .enableWakeFromSleep        = 0,                      /*** When set, the slave will wake the device when the slave select line becomes active. Note that not all SCBs support this mode. Consult the device datasheet to determine which SCBs support wake from deep sleep. ***/
    // In case of using high level APIs, an user does not need to set these parameter. These parameter will be set in high level APIs such as "Cy_SCB_SPI_Transfer".
    .txFifoTriggerLevel         = 0,                      /*** When there are fewer entries in the TX FIFO, then at this level the TX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_TX_TRIGGER interrupt source. ***/
    .rxFifoTriggerLevel         = 255,                    /*** When there are more entries in the RX FIFO, then at this level the RX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_RX_TRIGGER interrupt source.  ***/
    .rxFifoIntEnableMask        = 0,                      /*** Bits set in this mask will allow events to cause an interrupt  ***/
    .txFifoIntEnableMask        = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
    .masterSlaveIntEnableMask   = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
    .enableSpiDoneInterrupt     = 0,
    .enableSpiBusErrorInterrupt = 0,
};

void SetPeripheFracDiv24_5(uint64_t targetFreq, uint64_t sourceFreq, uint8_t divNum)
{
    uint64_t temp = ((uint64_t)sourceFreq << 5ull);
    uint32_t divSetting;

    divSetting = (uint32_t)(temp / targetFreq);
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(SCB_CLOCK), 
                                   CY_SYSCLK_DIV_24_5_BIT, divNum, 
                                   (((divSetting >> 5u) & 0x00000FFF) - 1u), 
                                   (divSetting & 0x0000001F));
}
void irqSCB(void)
{
    Cy_SCB_SPI_Interrupt(SCB_CH_TO_BE_USED, &contextSCB);
}

int main(void)
{
    SystemInit();

    /******************************************************/
    /******* Culculate divider setting for the SCB ********/
    /******************************************************/
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_2);

    Cy_SysClk_PeriphAssignDivider(SCB_CLOCK, CY_SYSCLK_DIV_24_5_BIT, DIVIDER_NO_1);
    SetPeripheFracDiv24_5(SCB_SPI_CLOCK_FREQ, SOURCE_CLOCK_FRQ, DIVIDER_NO_1);
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(SCB_CLOCK), CY_SYSCLK_DIV_24_5_BIT, 1u);

    __enable_irq(); /* Enable global interrupts. */

    /*******************************************/
    /*    Deinitialization for peripherals     */
    /*******************************************/
    Cy_SCB_SPI_DeInit(SCB_CH_TO_BE_USED);

    /*******************************************/
    /* Interrupt setting for SPI communication */
    /*******************************************/
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, irqSCB);
    NVIC_EnableIRQ(irq_cfg.intIdx);

    /**************************************/
    /* Port Setting for SPI communication */
    /**************************************/
    SPI_port_pin_cfg.driveMode = SCB_MISO_DRIVE_MODE;
    SPI_port_pin_cfg.hsiom = SCB_MISO_PIN_MUX;
    Cy_GPIO_Pin_Init(SCB_MISO_PORT, SCB_MISO_PIN, &SPI_port_pin_cfg);

    SPI_port_pin_cfg.driveMode = SCB_MOSI_DRIVE_MODE;
    SPI_port_pin_cfg.hsiom = SCB_MOSI_PIN_MUX;
    Cy_GPIO_Pin_Init(SCB_MOSI_PORT, SCB_MOSI_PIN, &SPI_port_pin_cfg);

    SPI_port_pin_cfg.driveMode = SCB_CLK_DRIVE_MODE;
    SPI_port_pin_cfg.hsiom = SCB_CLK_PIN_MUX;
    Cy_GPIO_Pin_Init(SCB_CLK_PORT,SCB_CLK_PIN, &SPI_port_pin_cfg);
    
    SPI_port_pin_cfg.driveMode = SCB_SEL0_DRIVE_MODE;
    SPI_port_pin_cfg.hsiom = SCB_SS0_PIN_MUX;
    Cy_GPIO_Pin_Init(SCB_SS0_PORT, SCB_SS0_PIN, &SPI_port_pin_cfg);

    /********************************************/
    /* SCB initialization for SPI communication */
    /********************************************/
    Cy_SCB_SPI_Init(SCB_CH_TO_BE_USED, &SCB_SPI_cfg, &contextSCB);
    Cy_SCB_SPI_SetActiveSlaveSelect(SCB_CH_TO_BE_USED, 0);
    Cy_SCB_SPI_Enable(SCB_CH_TO_BE_USED);

    /* Preparing for data transimited */
    for(uint32_t i = 0; i<256; i++)
    {
        testTxBuff[i] = i;
    }

    Cy_SCB_SPI_Transfer(SCB_CH_TO_BE_USED, testTxBuff, testRxBuff, 128, &contextSCB);

    /* Wait for completion by polling the status */
    /* Instead of callbacks, polling can be used for waiting for completion. */
    do
    {
        transferStatus = Cy_SCB_SPI_GetTransferStatus(SCB_CH_TO_BE_USED, &contextSCB);
    } while((transferStatus & CY_SCB_SPI_TRANSFER_ACTIVE) != 0u);

    for(;;);
}
/* [] END OF FILE */
