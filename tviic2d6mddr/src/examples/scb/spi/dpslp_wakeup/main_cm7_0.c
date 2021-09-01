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

#include "cy_project.h"
#include "cy_device_headers.h"

/* User setting value */
#define SCB_SPI_BAUDRATE                125000ul  /* Please set baudrate value of SPI you want */
#define SCB_SPI_OVERSAMPLING            16ul   /* Please set oversampling of SPI you want */
#define SCB_SPI_CLOCK                   (SCB_SPI_BAUDRATE * SCB_SPI_OVERSAMPLING)

#define DIVIDER_NO_1                    (1u)

#if (CY_USE_PSVP == 1)
    #define USER_LED_PORT               CY_LED8_PORT
    #define USER_LED_PIN                CY_LED8_PIN
    #define USER_LED_PIN_MUX            CY_LED8_PIN_MUX
#else
    #define USER_LED_PORT               CY_USER_LED2_PORT
    #define USER_LED_PIN                CY_USER_LED2_PIN
    #define USER_LED_PIN_MUX            CY_USER_LED2_PIN_MUX 
#endif


#if (CY_USE_PSVP == 1)
#define USER_SPI_TYPE                   SCB0
#define USER_SPI_MISO_PORT              GPIO_PRT0
#define USER_SPI_MISO_PIN               0
#define USER_SPI_MISO_PIN_MUX           P0_0_SCB0_SPI_MISO
#define USER_SPI_MOSI_PORT              GPIO_PRT0
#define USER_SPI_MOSI_PIN               1
#define USER_SPI_MOSI_PIN_MUX           P0_1_SCB0_SPI_MOSI
#define USER_SPI_CLK_PORT               GPIO_PRT0
#define USER_SPI_CLK_PIN                2
#define USER_SPI_CLK_PIN_MUX            P0_2_SCB0_SPI_CLK
#define USER_SPI_SS0_PORT               GPIO_PRT0
#define USER_SPI_SS0_PIN                3
#define USER_SPI_SS0_PIN_MUX            P0_3_SCB0_SPI_SELECT0
#define USER_SPI_PCLK                   PCLK_SCB0_CLOCK
#define USER_SPI_IRQN                   scb_0_interrupt_IRQn  
#else
#define USER_SPI_TYPE                   SCB6
#define USER_SPI_MISO_PORT              GPIO_PRT22
#define USER_SPI_MISO_PIN               1
#define USER_SPI_MISO_PIN_MUX           P22_1_SCB6_SPI_MISO
#define USER_SPI_MOSI_PORT              GPIO_PRT22
#define USER_SPI_MOSI_PIN               0
#define USER_SPI_MOSI_PIN_MUX           P22_0_SCB6_SPI_MOSI
#define USER_SPI_CLK_PORT               GPIO_PRT21
#define USER_SPI_CLK_PIN                7
#define USER_SPI_CLK_PIN_MUX            P21_7_SCB6_SPI_CLK
#define USER_SPI_SS0_PORT               GPIO_PRT22
#define USER_SPI_SS0_PIN                2
#define USER_SPI_SS0_PIN_MUX            P22_2_SCB6_SPI_SELECT0
#define USER_SPI_PCLK                   PCLK_SCB6_CLOCK
#define USER_SPI_IRQN                   scb_6_interrupt_IRQn  
#endif  // CY_USE_PSVP

cy_stc_scb_spi_context_t Context_SCB0_SPI;
uint8_t SCB0CompletedFlag = 0;

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =
{
    .outVal    = 0x00,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = USER_LED_PIN_MUX,
    .intEdge   = 0,
    .intMask   = 0,
    .vtrip     = 0,
    .slewRate  = 0,
    .driveSel  = 0,
    .vregEn    = 0,
    .ibufMode  = 0,
    .vtripSel  = 0,
    .vrefSel   = 0,
    .vohSel    = 0,
};

typedef union
{
    struct
    {
        uint32_t frac    :5;
        uint32_t integer :16;
        uint32_t reserve :11;
    } divType16_5;
    struct
    {
        uint32_t frac    :5;
        uint32_t integer :24;
        uint32_t reserve :3;
    } divType24_5;
    uint32_t u32;
} fixdPointUtil;

void irqSCB0(void)
{
    /***Interrupt flag clear***/
    Cy_SCB_ClearSpiInterrupt(USER_SPI_TYPE, CY_SCB_SPI_INTR_WAKEUP);

    SCB0CompletedFlag = 1;
}
int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    cy_stc_gpio_pin_config_t SPI_port_pin_cfg;
    cy_stc_scb_spi_config_t SCB_SPI_cfg;
    cy_stc_sysint_irq_t irq_cfg;

    /******************************************************/
    /******* Culculate divider setting for USER_SPI_TYPE ***********/
    /******************************************************/
    {
        Cy_SysClk_PeriphAssignDivider(USER_SPI_PCLK, CY_SYSCLK_DIV_24_5_BIT, DIVIDER_NO_1);
        {
            uint64_t      targetFreq = SCB_SPI_CLOCK;
      #if (CY_USE_PSVP == 1)  
            uint64_t      sourceFreq = 24000000ul;   /* clock peri frequency */
      #else  
            uint64_t      sourceFreq = 80000000ul;   /* clock peri frequency */
      #endif 
            uint64_t      temp       = ((uint64_t)sourceFreq << 5ull);
            fixdPointUtil divSetting;
            divSetting.u32 = (uint32_t)(temp / targetFreq);
            Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(USER_SPI_PCLK), CY_SYSCLK_DIV_24_5_BIT, DIVIDER_NO_1, (divSetting.divType24_5.integer - 1u), divSetting.divType24_5.frac);        // for 100 kHz  (24 / 12  =  2 MHz)
        }
        Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(USER_SPI_PCLK), CY_SYSCLK_DIV_24_5_BIT, 1u);
    }

    __enable_irq(); /* Enable global interrupts. */

    /*******************************************/
    /*    Deinitialization for peripherals     */
    /*******************************************/
    Cy_SCB_SPI_DeInit(USER_SPI_TYPE);

    /*************************************/
    /*      Initializing                 */
    /*************************************/
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
  
    /*******************************************/
    /* Interrupt setting for SPI communication */
    /*******************************************/
    irq_cfg.sysIntSrc  = USER_SPI_IRQN;
    irq_cfg.intIdx     = CPUIntIdx3_IRQn;
    irq_cfg.isEnabled  = true;
    Cy_SysInt_InitIRQ(&irq_cfg);
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);

    /**************************************/
    /* Port Setting for SPI communication */
    /**************************************/
    SPI_port_pin_cfg.outVal = 0x00;
    SPI_port_pin_cfg.intEdge = 0;
    SPI_port_pin_cfg.intMask = 0;
    SPI_port_pin_cfg.vtrip = 0;
    SPI_port_pin_cfg.slewRate = 0;
    SPI_port_pin_cfg.driveSel = 0;
    SPI_port_pin_cfg.vregEn = 0;
    SPI_port_pin_cfg.ibufMode = 0;
    SPI_port_pin_cfg.vtripSel = 0;
    SPI_port_pin_cfg.vrefSel = 0;
    SPI_port_pin_cfg.vohSel = 0;

    /* P0.0 -> SCB0 SPI MISO */
    /* If you use 176 pin MCU, please use J6.15 on the base board. */
    /* If you use 64 pin MCU,  please use J6.15 on the base board. */
    SPI_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    SPI_port_pin_cfg.hsiom = USER_SPI_MISO_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_SPI_MISO_PORT, USER_SPI_MISO_PIN, &SPI_port_pin_cfg);

    /* P0.1 -> SCB0 SPI MOSI */
    /* If you use 176 pin MCU, please use J6.14 on the base board. */
    /* If you use 64 pin MCU,  please use J6.14 on the base board. */
    SPI_port_pin_cfg.driveMode = CY_GPIO_DM_HIGHZ;
    SPI_port_pin_cfg.hsiom = USER_SPI_MOSI_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_SPI_MOSI_PORT, USER_SPI_MOSI_PIN, &SPI_port_pin_cfg);

    /* P0.2 -> SCB0 SPI SCK */
    /* If you use 176pin package, please use pin 2 of J109(CAN6 TX) on the base board. */
    /* If you use 64 pin MCU,  please use J6.9 on the base board. */
    SPI_port_pin_cfg.driveMode = CY_GPIO_DM_HIGHZ;
    SPI_port_pin_cfg.hsiom = USER_SPI_CLK_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_SPI_CLK_PORT, USER_SPI_CLK_PIN, &SPI_port_pin_cfg);
    
    /* P0.3 -> SCB0 SPI SELECT0 */
    /* If you use 176pin package, please use pin 2 of J94(CAN6 RX) on the base board. */
    /* If you use 64 pin MCU,  please use J6.8 on the base board. */
    SPI_port_pin_cfg.driveMode = CY_GPIO_DM_HIGHZ;
    SPI_port_pin_cfg.hsiom = USER_SPI_SS0_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_SPI_SS0_PORT, USER_SPI_SS0_PIN, &SPI_port_pin_cfg);

    /********************************************/
    /* SCB initialization for SPI communication */
    /********************************************/
    SCB_SPI_cfg.spiMode = CY_SCB_SPI_SLAVE;         /*** Specifies the mode of operation    */
    SCB_SPI_cfg.subMode = CY_SCB_SPI_MOTOROLA;      /*** Specifies the submode of SPI operation    */
    SCB_SPI_cfg.sclkMode = CY_SCB_SPI_CPHA0_CPOL0;  /*** When clock is inactive, the level is low. Data signal is sampled on first edge ***/
    SCB_SPI_cfg.oversample = SCB_SPI_OVERSAMPLING;  /*** This field has no effect at slave mode   ***/
    SCB_SPI_cfg.rxDataWidth = 16;                   /*** The width of RX data (valid range 4-16). It must be the same as \ref txDataWidth except in National sub-mode.    */
    SCB_SPI_cfg.txDataWidth = 16;                   /*** The width of TX data (valid range 4-16). It must be the same as \ref rxDataWidth except in National sub-mode. */
    SCB_SPI_cfg.enableMsbFirst = true;              /*** Enables the hardware to shift out the data element MSB first, otherwise, LSB first */
    SCB_SPI_cfg.enableFreeRunSclk = false;          /*** Enables the master to generate a continuous SCLK regardless of whether there is data to send  */
    SCB_SPI_cfg.enableInputFilter = false;          /*** Enables a digital 3-tap median filter to be applied to the input of the RX FIFO to filter glitches on the line. */
    SCB_SPI_cfg.enableMisoLateSample = true;        /*** Enables the master to sample MISO line one half clock later to allow better timings. */
    SCB_SPI_cfg.enableTransferSeperation = true;    /*** Enables the master to transmit each data element separated by a de-assertion of the slave select line (only applicable for the master mode) */
    SCB_SPI_cfg.ssPolarity0 = 0;                    /*** SS0: active low ***/
    SCB_SPI_cfg.ssPolarity1 = 0;                    /*** SS1: active low ***/
    SCB_SPI_cfg.ssPolarity2 = 0;                    /*** SS2: active low ***/
    SCB_SPI_cfg.ssPolarity3 = 0;                    /*** SS3: active low ***/
    SCB_SPI_cfg.enableWakeFromSleep = 1;            /*** When set, the slave will wake the device when the slave select line becomes active. Note that not all SCBs support this mode. Consult the device datasheet to determine which SCBs support wake from deep sleep. */
    SCB_SPI_cfg.rxFifoTriggerLevel = 0;             /*** Interrupt occures, when there are more entries of 1 in the RX FIFO */
    SCB_SPI_cfg.rxFifoIntEnableMask = 0;            /*** Bits set in this mask will allow events to cause an interrupt  */
    SCB_SPI_cfg.txFifoTriggerLevel = 0;             /*** When there are fewer entries in the TX FIFO, then at this level the TX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_TX_TRIGGER interrupt source. */
    SCB_SPI_cfg.txFifoIntEnableMask = 0;            /*** Bits set in this mask allow events to cause an interrupt  */
    SCB_SPI_cfg.masterSlaveIntEnableMask = 0;       /*** Bits set in this mask allow events to cause an interrupt  */
    SCB_SPI_cfg.enableSpiDoneInterrupt = 0;
    SCB_SPI_cfg.enableSpiBusErrorInterrupt = 0;

    Cy_SCB_SPI_Init(USER_SPI_TYPE, &SCB_SPI_cfg, &Context_SCB0_SPI);

    /*** Configuring SCB for EZSPI Mode ***/
    Cy_SCB_SetEzMode(USER_SPI_TYPE,1);

    /*** Extenally clocked SPI interrupt mask ***/
    Cy_SCB_SetSpiInterruptMask(USER_SPI_TYPE, CY_SCB_SPI_INTR_WAKEUP);

    Cy_SCB_SPI_SetActiveSlaveSelect(USER_SPI_TYPE, 0);
    Cy_SCB_SPI_Enable(USER_SPI_TYPE);

    for(;;)
    {
        Cy_GPIO_Write(USER_LED_PORT, USER_LED_PIN, 0);
        /* Put the system to DeeSleep */
        Cy_SysPm_DeepSleep((cy_en_syspm_waitfor_t)CY_SYSPM_WAIT_FOR_INTERRUPT);
        Cy_GPIO_Write(USER_LED_PORT, USER_LED_PIN, 1);

        while(SCB0CompletedFlag == 0);
        SCB0CompletedFlag = 0;
        Cy_SysTick_DelayInUs(3000000UL);
    }
}



/* [] END OF FILE */
