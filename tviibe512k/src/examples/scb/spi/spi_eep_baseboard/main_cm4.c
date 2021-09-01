/***************************************************************************//**
* \file main_cm4.c
*
* \version 1.0
*
* \brief Main example file for CM4
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
#if (CY_USE_PSVP == 1)
    #define PERI_CLOCK_FREQ           24000000ul      /* Please set peri clock frequency value */
#else
    #define PERI_CLOCK_FREQ           80000000ul      /* Please set peri clock frequency value */
#endif 

#if (CY_USE_PSVP == 1)
  #warning "These port settings will not work on MTO bitfile!"
#endif

#define EEPROM_SCB_INSTANCE       CY_EEPROM_SCB_TYPE
#define EEPROM_SCB_IRQN           CY_EEPROM_SCB_IRQN
#define EEPROM_SCB_PCLOCK         CY_EEPROM_SCB_PCLK


#define SCB_SPI_BAUDRATE        50000ul         /* Please set baudrate value of SPI you want */
#define SCB_SPI_OVERSAMPLING    8ul             /* Please set oversampling of SPI you want */

#define READ                    03              // READ       instruction code  
#define WRITE                   02              // WRITE      instruction code 
#define WRDI                    04              // WR DISBALE instruction code 
#define WREN                    06              // WR ENABLE  instruction code
#define RDSR                    05              // RD STATUS  instruction code 
#define WRSR                    01              // WR STATUS  instruction code 
#define NOPROT                  00              // NO WRITE PROTECTION 

#define PAGE_WRITE_SIZE 32u
#define WRITE_TEST_SIZE 256u

static void PortInit(void);
static void SPI_Initialize(void);
static void WriteEEPROM(uint16_t address, uint8_t data);
static uint8_t ReadEEPROM(uint16_t address);
static uint8_t GetStatusEEPROM(void);
static uint8_t GetWEL_EEPROM(void);
static uint8_t GetWIP_EEPROM(void);
static void WriteEnableEEPROM(void);
static void PageWriteEEPROM(uint16_t address, uint8_t data[], uint8_t size);

/* Port configuration */
typedef struct
{
    volatile stc_GPIO_PRT_t* portReg;
    uint8_t pinNum;
    cy_stc_gpio_pin_config_t cfg;
}stc_pin_config;

/* SPi Context holder */
cy_stc_scb_spi_context_t spiCtx;

/*  port configuration */
/* If you use 64 pin MCU, short below pins on the base board */
/* J6.15 and J50 pin 1 (MISO) */
/* J6.14 and J45 pin 1 (MOSI) */
/* J6.9  and J47 pin 1 (CLK)  */
/* J6.12 and J46 pin 1 (HOLD) */
/* J6.11 and J45 pin 1 (WP)   */

static const stc_pin_config can_pin_cfg[] =
{
  #if (CY_USE_PSVP == 1)
    #warning "I think these port settings will not work on MTO bitfile!"
  #endif
    {
        .portReg = CY_EEPROM_SCB_MISO_PORT, 
        .pinNum  = CY_EEPROM_SCB_MISO_PIN,
        {
            .outVal = 0,
            .driveMode = CY_GPIO_DM_HIGHZ,
            .hsiom = CY_EEPROM_SCB_MISO_PIN_MUX,
            .intEdge = 0,
            .intMask = 0,
            .vtrip = 0,
            .slewRate = 0,
            .driveSel = 0,
            .vregEn = 0,
            .ibufMode = 0,
            .vtripSel = 0,
            .vrefSel = 0,
            .vohSel = 0,
        }
    },
  #if (CY_USE_PSVP == 1)
    #warning "I think these port settings will not work on MTO bitfile!"
  #endif
    {
        .portReg = CY_EEPROM_SCB_MOSI_PORT, 
        .pinNum  = CY_EEPROM_SCB_MOSI_PIN,
        {
            .outVal = 0,
            .driveMode = CY_GPIO_DM_STRONG,
            .hsiom = CY_EEPROM_SCB_MOSI_PIN_MUX,
            .intEdge = 0,
            .intMask = 0,
            .vtrip = 0,
            .slewRate = 0,
            .driveSel = 0,
            .vregEn = 0,
            .ibufMode = 0,
            .vtripSel = 0,
            .vrefSel = 0,
            .vohSel = 0,
        }
    },
  #if (CY_USE_PSVP == 1)
    #warning "I think these port settings will not work on MTO bitfile!"
  #endif
    {
        .portReg = CY_EEPROM_SCB_SCK_PORT, 
        .pinNum  = CY_EEPROM_SCB_SCK_PIN,
        {
            .outVal = 0,
            .driveMode = CY_GPIO_DM_STRONG,
            .hsiom = CY_EEPROM_SCB_SCK_PIN_MUX,
            .intEdge = 0,
            .intMask = 0,
            .vtrip = 0,
            .slewRate = 0,
            .driveSel = 0,
            .vregEn = 0,
            .ibufMode = 0,
            .vtripSel = 0,
            .vrefSel = 0,
            .vohSel = 0,
        }
    },
  #if (CY_USE_PSVP == 1)
    #warning "I think these port settings will not work on MTO bitfile!"
  #endif
    {
        .portReg = CY_EEPROM_SCB_SSEL_PORT, 
        .pinNum  = CY_EEPROM_SCB_SSEL_PIN,
        {
            .outVal = 1,
            .driveMode = CY_GPIO_DM_STRONG,
            .hsiom = CY_EEPROM_SCB_SSEL_PIN_MUX,
            .intEdge = 0,
            .intMask = 0,
            .vtrip = 0,
            .slewRate = 0,
            .driveSel = 0,
            .vregEn = 0,
            .ibufMode = 0,
            .vtripSel = 0,
            .vrefSel = 0,
            .vohSel = 0,
        }
    },
  #if (CY_USE_PSVP == 1)
    #warning "I think these port settings will not work on MTO bitfile!"
  #endif
    {
        .portReg = CY_EEPROM_HOLD_PORT, 
        .pinNum  = CY_EEPROM_HOLD_PIN,
        {
            .outVal = 1,
            .driveMode = CY_GPIO_DM_STRONG,
            .hsiom = CY_EEPROM_HOLD_PIN_MUX,
            .intEdge = 0,
            .intMask = 0,
            .vtrip = 0,
            .slewRate = 0,
            .driveSel = 0,
            .vregEn = 0,
            .ibufMode = 0,
            .vtripSel = 0,
            .vrefSel = 0,
            .vohSel = 0,
        }
    },
  #if (CY_USE_PSVP == 1)
    #warning "I think these port settings will not work on MTO bitfile!"
  #endif
    {
        .portReg = CY_EEPROM_WP_PORT, 
        .pinNum  = CY_EEPROM_WP_PIN,
        {
            .outVal = 1,
            .driveMode = CY_GPIO_DM_STRONG,
            .hsiom = CY_EEPROM_WP_PIN_MUX,
            .intEdge = 0,
            .intMask = 0,
            .vtrip = 0,
            .slewRate = 0,
            .driveSel = 0,
            .vregEn = 0,
            .ibufMode = 0,
            .vtripSel = 0,
            .vrefSel = 0,
            .vohSel = 0,
        }
    },
    
};

volatile uint8_t readData[256];
volatile uint8_t readData2[256];

int main(void)
{
    SystemInit();

    /* Enable global interrupts. */
    __enable_irq(); 

    /* Initialize ports. */
    {
        PortInit();// Initialize port 16 of SPI-EEPROM_SCB_INSTANCE
    }    

    /* Initialize SPI (SCBx.SS0 is connected)*/
    {
        SPI_Initialize();
    }

    /* 1. Write 256 byte one by one from address of 0 to 255 */
    for(uint16_t i = 0;i<WRITE_TEST_SIZE; i++)
    {
        /* Enable writing */
        do
        {
            WriteEnableEEPROM();
        } while(GetWEL_EEPROM() == 0);

        /* Writing 1 Byte data */
        WriteEEPROM(/* addr */ i, /* data */(uint8_t)i);

        /* Waiting if previous writing is in progress */
        while(GetWIP_EEPROM() == 1u);

        readData[i] = ReadEEPROM(/* addr */ i);
    }

    /* 2. Write 256 byte by 32byte page from address of 256 to 511 */
    for(uint16_t i = 0;i < (WRITE_TEST_SIZE / PAGE_WRITE_SIZE); i++)
    {
        uint16_t addrOffset = i * PAGE_WRITE_SIZE;
        uint16_t addr = WRITE_TEST_SIZE + addrOffset;

        /* Enable writing */
        do
        {
            WriteEnableEEPROM();
        } while(GetWEL_EEPROM() == 0);

        /* Writing 32 Byte data */
        PageWriteEEPROM(/* addr */ addr, /* data */(uint8_t*)&readData[addrOffset], /* size */PAGE_WRITE_SIZE);

        /* Waiting if previous writing is in progress */
        while(GetWIP_EEPROM() == 1u);

        for(uint16_t j = 0; j < PAGE_WRITE_SIZE; j++)
        {
            readData2[j+addrOffset] = ReadEEPROM(/* addr */ addr + j);
        }
    }

    for(;;);
}

/* Initialize  pins */
static void PortInit(void)
{
    for (uint8_t i = 0; i < (sizeof(can_pin_cfg) / sizeof(can_pin_cfg[0])); i++)
    {
        Cy_GPIO_Pin_Init(can_pin_cfg[i].portReg, can_pin_cfg[i].pinNum, &can_pin_cfg[i].cfg);
    }
}

/* SPI Interrupt Handler */
void SpiInterruptHandler(void)
{
    Cy_SCB_SPI_Interrupt(EEPROM_SCB_INSTANCE, &spiCtx);
    NVIC_ClearPendingIRQ(CPUIntIdx2_IRQn);
}

/* SPi Initialize */
static void SPI_Initialize(void)
{
  
    /* Setup SPI clock as 1MHz */
    /* Note that this example uses 8 oversample, so input clock / 8 = actual baudrate */
    struct divBF 
    {
        uint32_t div5bit  : 5;
        uint32_t div24bit : 24;
        uint32_t rev      : 3;
    };
    
    union 
    {
        struct divBF bf;
        uint32_t u32;
    } div24_5_Util;
    
    uint64_t culcDivValueTemp;

    culcDivValueTemp = PERI_CLOCK_FREQ;
    culcDivValueTemp <<= 5;
    culcDivValueTemp /= (SCB_SPI_BAUDRATE * SCB_SPI_OVERSAMPLING);
    div24_5_Util.u32 = (uint32_t)culcDivValueTemp;

    Cy_SysClk_PeriphAssignDivider(EEPROM_SCB_PCLOCK, CY_SYSCLK_DIV_24_5_BIT, 0u);
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, 
                                   0u, 
                                   div24_5_Util.bf.div24bit - 1,
                                   div24_5_Util.bf.div5bit
                                   );
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_24_5_BIT, 0u);

    /* De-initialize SPI */
    Cy_SCB_SPI_DeInit(EEPROM_SCB_INSTANCE);
    
    /* Setup the IRQ */
    cy_stc_sysint_irq_t irq_cfg;
    irq_cfg = (cy_stc_sysint_irq_t){
        .sysIntSrc  = EEPROM_SCB_IRQN,
        .intIdx     = CPUIntIdx2_IRQn,
        .isEnabled  = true,
    };
    Cy_SysInt_InitIRQ(&irq_cfg);
	Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, SpiInterruptHandler);
    NVIC_ClearPendingIRQ(CPUIntIdx2_IRQn);
    NVIC_EnableIRQ(CPUIntIdx2_IRQn);

    cy_stc_scb_spi_config_t spiCfg = 
    {
        .spiMode = CY_SCB_SPI_MASTER,
        .subMode = CY_SCB_SPI_MOTOROLA,  
        .sclkMode = CY_SCB_SPI_CPHA0_CPOL0,
        .oversample = 8u,
        .rxDataWidth = 8u,
        .txDataWidth = 8u,
        .enableMsbFirst = true,
        .enableFreeRunSclk = false,
        .enableInputFilter = false,
        .enableMisoLateSample = false,
        .enableTransferSeperation = false,
        .ssPolarity0 = CY_SCB_SPI_ACTIVE_LOW,
        .ssPolarity1 = CY_SCB_SPI_ACTIVE_LOW,
        .ssPolarity2 = CY_SCB_SPI_ACTIVE_LOW,
        .ssPolarity3 = CY_SCB_SPI_ACTIVE_LOW,
        .enableWakeFromSleep = false,
        .txFifoTriggerLevel = 0,
        .rxFifoTriggerLevel = 1,
        .rxFifoIntEnableMask = 0,
        .txFifoIntEnableMask = 0,
        .masterSlaveIntEnableMask = 0,
        .enableSpiDoneInterrupt = false,
        .enableSpiBusErrorInterrupt = false,
    };
    
    /* Initialize the SPI */
    Cy_SCB_SPI_Init(EEPROM_SCB_INSTANCE, &spiCfg, &spiCtx);
    Cy_SCB_SPI_SetActiveSlaveSelect(EEPROM_SCB_INSTANCE, CY_SCB_SPI_SLAVE_SELECT0);
    Cy_SCB_SPI_Enable(EEPROM_SCB_INSTANCE);
}

static void WriteEEPROM(uint16_t address, uint8_t data)
{
    uint8_t txData[4];
    uint8_t rxData[4];
    txData[0] = WRITE;
    txData[1] = (uint8_t)((address & 0xFF00) >> 8u);
    txData[2] = (uint8_t)(address & 0x00FF);
    txData[3] = data;

    uint32_t status;
    Cy_SCB_SPI_Transfer(EEPROM_SCB_INSTANCE, &txData, &rxData, 4u, &spiCtx);
    /* wait for completion */
    do
    {
            status = Cy_SCB_SPI_GetTransferStatus(EEPROM_SCB_INSTANCE, &spiCtx);
    } while((status & CY_SCB_SPI_TRANSFER_ACTIVE) != 0u);        
}

static uint8_t ReadEEPROM(uint16_t address)
{
    uint8_t txData[4];
    uint8_t rxData[4];
    txData[0] = READ;
    txData[1] = (uint8_t)((address & 0xFF00) >> 8u);
    txData[2] = (uint8_t)(address & 0x00FF);
    txData[3] = 0u;

    uint32_t status;
    Cy_SCB_SPI_Transfer(EEPROM_SCB_INSTANCE, &txData, &rxData, 4u, &spiCtx);
    /* wait for completion */
    do
    {
            status = Cy_SCB_SPI_GetTransferStatus(EEPROM_SCB_INSTANCE, &spiCtx);
    } while((status & CY_SCB_SPI_TRANSFER_ACTIVE) != 0u);        
    
    return rxData[3];
}

static uint8_t GetStatusEEPROM(void)
{
    /* RDSR */
    uint8_t txData[2];
    uint8_t rxData[2];

    txData[0] = RDSR ;
    txData[1] = 0u ;

    uint32_t status;
    Cy_SCB_SPI_Transfer(EEPROM_SCB_INSTANCE, &txData, &rxData, 2u, &spiCtx);
    /* wait for completion */
    do
    {
            status = Cy_SCB_SPI_GetTransferStatus(EEPROM_SCB_INSTANCE, &spiCtx);
    } while((status & CY_SCB_SPI_TRANSFER_ACTIVE) != 0u);        
    
    return rxData[1];
}

static uint8_t GetWEL_EEPROM(void)
{
    return((GetStatusEEPROM() & 0x02u) >> 1u);
}

static uint8_t GetWIP_EEPROM(void)
{
    return(GetStatusEEPROM() & 0x01u);
}

static void WriteEnableEEPROM(void)
{
    uint8_t txData = WREN;
    uint8_t rxData;
    uint32_t status;

    Cy_SCB_SPI_Transfer(EEPROM_SCB_INSTANCE, &txData, &rxData, 1u, &spiCtx);

    /* wait for completion */
    do
    {
        status = Cy_SCB_SPI_GetTransferStatus(EEPROM_SCB_INSTANCE, &spiCtx);
    } while((status & CY_SCB_SPI_TRANSFER_ACTIVE) != 0u);        
}

static void PageWriteEEPROM(uint16_t address, uint8_t data[], uint8_t size)
{
    uint32_t status;
    uint8_t rxData[35];
    uint8_t txData[35];

    if(size > 32)
    {
        return;
    }

    txData[0] = WRITE;
    txData[1] = (uint8_t)((address & 0xFF00) >> 8u);
    txData[2] = (uint8_t)(address & 0x00FF);
    for(uint32_t i = 0; i < size; i++)
    {
        txData[3+i] = data[i];
    }

    Cy_SCB_SPI_Transfer(EEPROM_SCB_INSTANCE, &txData, &rxData, (3+size), &spiCtx);

    /* wait for completion */
    do
    {
        status = Cy_SCB_SPI_GetTransferStatus(EEPROM_SCB_INSTANCE, &spiCtx);
    } while((status & CY_SCB_SPI_TRANSFER_ACTIVE) != 0u);        
}

/* [] END OF FILE */
