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
#include <string.h>

#include "cy_project.h" 
#include "cy_device_headers.h"

#if CY_USE_PSVP == 1
  #define USER_LED_PORT           CY_LED9_PORT
  #define USER_LED_PIN            CY_LED9_PIN
  #define USER_LED_PIN_MUX        CY_LED9_PIN_MUX
#else
  #define USER_LED_PORT           CY_CB_USER_LED2_PORT
  #define USER_LED_PIN            CY_CB_USER_LED2_PIN
  #define USER_LED_PIN_MUX        CY_CB_USER_LED2_PIN_MUX
#endif

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED_PIN_MUX,                           
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
};

cy_stc_gpio_pin_config_t sdhc_port_pin_cfg =             
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

/* Assign divider number for SD Host driver (to have 100 MHz) */
#define SD_HOST_CLK_DIV_NUM             (0U)

#define SECTORNUM                       (8)
#define TOTAL_SIZE                      (100*1024*1024)
#define RETRY_WRITE_READ                (8)
#define VALUE1                          (0x71)
#define VALUE2                          (0x72)
#define WRITE_READ_TIME                 (500)

#define CY_SD_HOST_RETRY_TIME           (1000UL)  /* The number loops to make the timeout in msec. */
#define CY_SD_HOST_WRITE_TIMEOUT_MS     (250U)  /* The Write timeout for one block. */
#define CY_SD_HOST_SD_CMD18             (18UL)
#define CY_SD_HOST_SD_CMD25             (25UL)
#define CY_SD_HOST_SDSC_ADDR_SHIFT      (9U)

#define CY_SD_HOST_ADMA_NOP             (0x0UL) /* Do not execute current line and go to next line. */
#define CY_SD_HOST_ADMA_RSV             (0x2UL) /* Reserved. */
#define CY_SD_HOST_ADMA_TRAN            (0x4UL) /* Transfer data of one descriptor line. */
#define CY_SD_HOST_ADMA_LINK            (0x6UL) /* Link to another descriptor. */
#define CY_SD_HOST_ADMA3_CMD            (0x1UL) /* The Command descriptor. */
#define CY_SD_HOST_ADMA3_INTERGRATED    (0x7UL) /* The Integrated descriptor. */
#define CY_SD_HOST_ADMA2_DESCR_SIZE     (0x2UL) /* The ADMA2 descriptor size. */


/** The SD/eMMC/SDIO ADMA description table structure */
typedef struct
{
    uint16_t u16AttrValid   :1; /**< Indicates validity of a the descriptor line. */
    uint16_t u16AttrEnd     :1; /**< The end of the descriptor. */
    uint16_t u16AttrInt     :1; /**< The attribute to force to generate ADMA interrupt attribute. */
    //uint16_t u16Reserved1   :1; /**< Reserved. */
    uint16_t u16Act         :3; /**< Act0, Act1 and Act2 attributes. */
    uint16_t u16Reserved2   :10; /**< Reserved. */
    uint16_t u16Len; /**< The data length. */
    uint32_t u32addr; /**< The data address. */
} cy_stc_sd_host_sdcmd_adma_desc_tbl_t;


uint8_t      u8RxBuff[CY_SD_HOST_BLOCK_SIZE*SECTORNUM];
//static uint8_t      u8RxBuff_1[CY_SD_HOST_BLOCK_SIZE*SECTORNUM];
uint8_t      u8TxBuff[CY_SD_HOST_BLOCK_SIZE*SECTORNUM];
uint8_t      u8TxBuff_1[CY_SD_HOST_BLOCK_SIZE*SECTORNUM];
static uint32_t     gu8StartSector  = 0;
uint32_t gcount = 0;
uint32_t    rca = 0;
cy_en_sd_host_card_capacity_t cardCapacity;
cy_stc_sd_host_context_t sd_host_context;
cy_stc_sd_host_sdcmd_adma_desc_tbl_t CommandDescriptor1[5] = { 0u };
cy_stc_sd_host_sdcmd_adma_desc_tbl_t CommandDescriptor1_1[5] = { 0u };
cy_stc_sd_host_sdcmd_adma_desc_tbl_t CommandDescriptor2[5] = { 0u };
cy_stc_sd_host_sdcmd_adma_desc_tbl_t IntegratedDescriptor1[3] = { 0u };
bool           bSuccess        = true;
cy_stc_sd_host_write_read_config_t dataRead;
cy_stc_sd_host_write_read_config_t dataWrite;

static cy_en_sd_host_status_t Cy_SD_Host_PollTransferComplete(stc_SDHC_t *base);

/*******************************************************************************
* Function Name: Cy_SD_Host_PollTransferComplete
****************************************************************************//**
*
*  Waits for the command complete event.
*
* \param *base
*     The SD host registers structure pointer.
*
* \return cy_en_sd_host_status_t
*     *base checking result.
*      If the pointer is NULL, returns error.
*
*******************************************************************************/
static cy_en_sd_host_status_t Cy_SD_Host_PollTransferComplete(stc_SDHC_t *base)
{
    cy_en_sd_host_status_t ret = CY_SD_HOST_ERROR_TIMEOUT;
    uint32_t               retry = CY_SD_HOST_RETRY_TIME;

    while ((CY_SD_HOST_ERROR_TIMEOUT == ret) && (retry-- > 0u))
    {
        /* Transfer complete */
        if (1u == _FLD2BOOL(SDHC_CORE_NORMAL_INT_STAT_R_XFER_COMPLETE, base->CORE.unNORMAL_INT_STAT_R.u16Register))
        {
            /* Clear interrupt flag */
            base->CORE.unNORMAL_INT_STAT_R.u16Register = CY_SD_HOST_XFER_COMPLETE;

            ret = CY_SD_HOST_SUCCESS;
        }

        Cy_SysLib_DelayUs(CY_SD_HOST_WRITE_TIMEOUT_MS);
    }

    return ret;
}


int main(void)
{
    cy_en_sd_host_status_t         enRet           = CY_SD_HOST_SUCCESS;
    cy_stc_sd_host_init_config_t   hostConfig      = { 0u };
    cy_stc_sd_host_cmd_config_t stcCmd = { 0u };
    cy_stc_sd_host_sd_card_config_t stcSdcardCfg;
    uint32_t         u32Retry    = 0;
    uint32_t         address; 
    uint32_t         addressOffset; 

    cy_stc_sd_host_data_config_t dataConfig = { 0u };
    cy_en_sd_host_card_type_t cardType = CY_SD_HOST_EMMC;

    stcSdcardCfg.lowVoltageSignaling = false;
    stcSdcardCfg.busWidth = CY_SD_HOST_BUS_WIDTH_4_BIT;
    stcSdcardCfg.cardType = &cardType;
    stcSdcardCfg.rca = &rca;
    stcSdcardCfg.cardCapacity = &cardCapacity;

    /* Initialize the configuration */
    hostConfig.dmaType = CY_SD_HOST_DMA_ADMA2_ADMA3;
    hostConfig.enableLedControl = false;
    hostConfig.emmc = true;

    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache
    
    __enable_irq(); /* Enable global interrupts. */

    Cy_SysClk_HfClockSetDivider(CY_SYSCLK_HFCLK_6, CY_SYSCLK_HFCLK_NO_DIVIDE);
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_6); //CLK_HF6 enable  
    
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);

    (void)Cy_SD_Host_Enable((stc_SDHC_t *)CY_SDHC_TYPE);

    /**************************************/
    /* Port Setting for CY_SDHC_TYPE             */
    /**************************************/

    sdhc_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG;
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CARD_DETECT_N_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CARD_DETECT_N_PORT, CY_SDHC_CARD_DETECT_N_PIN, &sdhc_port_pin_cfg);
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CARD_CMD_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CARD_CMD_PORT, CY_SDHC_CARD_CMD_PIN, &sdhc_port_pin_cfg);
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CLK_CARD_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CLK_CARD_PORT, CY_SDHC_CLK_CARD_PIN, &sdhc_port_pin_cfg);
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CARD_DAT_3TO00_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CARD_DAT_3TO00_PORT, CY_SDHC_CARD_DAT_3TO00_PIN, &sdhc_port_pin_cfg);
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CARD_DAT_3TO01_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CARD_DAT_3TO01_PORT, CY_SDHC_CARD_DAT_3TO01_PIN, &sdhc_port_pin_cfg);
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CARD_DAT_3TO02_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CARD_DAT_3TO02_PORT, CY_SDHC_CARD_DAT_3TO02_PIN, &sdhc_port_pin_cfg);
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CARD_DAT_3TO03_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CARD_DAT_3TO03_PORT, CY_SDHC_CARD_DAT_3TO03_PIN, &sdhc_port_pin_cfg);

    /* Configure SD Host to operate */
    (void) Cy_SD_Host_Init((stc_SDHC_t *)CY_SDHC_TYPE, &hostConfig, &sd_host_context);
    /* Switch the bus to 1.8 V */
    //Cy_SD_Host_ChangeIoVoltage((stc_SDHC_t *)CY_SDHC_TYPE, CY_SD_HOST_IO_VOLT_1_8V);

    Cy_SysLib_Delay(10);
    enRet = Cy_SD_Host_InitCard((stc_SDHC_t *)CY_SDHC_TYPE, &stcSdcardCfg, &sd_host_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

#if 1
    // Multiple block write test.

    dataWrite.data = (uint32_t*)u8TxBuff;            /**< The pointer to data. */

    memset(u8TxBuff, VALUE1, sizeof(u8RxBuff));
    memset(u8TxBuff_1, VALUE2, sizeof(u8RxBuff));
    memset(u8RxBuff, 0x0, sizeof(u8RxBuff));

    address = gu8StartSector;

    if (CY_SD_HOST_SDSC == sd_host_context.cardCapacity)
    {
        address = address << CY_SD_HOST_SDSC_ADDR_SHIFT;
        addressOffset = CY_SD_HOST_BLOCK_SIZE * SECTORNUM;
    }
    else
    {
    	addressOffset = SECTORNUM;
    }

    stcCmd.commandIndex = CY_SD_HOST_SD_CMD25;

    dataConfig.enableIntAtBlockGap = true;

    dataConfig.blockSize = CY_SD_HOST_BLOCK_SIZE;
    dataConfig.numberOfBlock = SECTORNUM;
    dataConfig.enableDma = true;
    dataConfig.autoCommand = CY_SD_HOST_AUTO_CMD_12;
    dataConfig.read = false;

    dataConfig.dataTimeout = 0xcu;
    dataConfig.enReliableWrite = false;
    dataConfig.enableDma = true;

    stcCmd.commandArgument = address;
    stcCmd.dataPresent = true;
    stcCmd.respType = CY_SD_HOST_RESPONSE_LEN_48;
    stcCmd.enableCrcCheck = true;
    stcCmd.enableIdxCheck = true;

    memset(CommandDescriptor1, 0u, sizeof(CommandDescriptor1));
    memset(CommandDescriptor1_1, 0u, sizeof(CommandDescriptor1_1));
    memset(IntegratedDescriptor1, 0u, sizeof(IntegratedDescriptor1));

    /* The Integrated Descriptor */
    IntegratedDescriptor1[0].u16AttrValid = 1u;
    IntegratedDescriptor1[0].u16AttrEnd = 0u;
    IntegratedDescriptor1[0].u16AttrInt = 0u;
    IntegratedDescriptor1[0].u16Act = CY_SD_HOST_ADMA3_INTERGRATED;
    IntegratedDescriptor1[0].u16Len = 0u;
    IntegratedDescriptor1[0].u32addr = (uint32_t)&CommandDescriptor1[0];

    IntegratedDescriptor1[1].u16AttrValid = 1u;
    IntegratedDescriptor1[1].u16AttrEnd = 0u;
    IntegratedDescriptor1[1].u16AttrInt = 0u;
    IntegratedDescriptor1[1].u16Act = CY_SD_HOST_ADMA3_INTERGRATED;
    IntegratedDescriptor1[1].u16Len = 0u;
    IntegratedDescriptor1[1].u32addr = (uint32_t)&CommandDescriptor1_1[0];

    IntegratedDescriptor1[2].u16AttrValid = 1u;
    IntegratedDescriptor1[2].u16AttrEnd = 1u;
    IntegratedDescriptor1[2].u16AttrInt = 0u;
    IntegratedDescriptor1[2].u16Act = CY_SD_HOST_ADMA3_INTERGRATED;
    IntegratedDescriptor1[2].u16Len = 0u;
    IntegratedDescriptor1[2].u32addr = (uint32_t)&CommandDescriptor2[0];

    /* The Command Descriptor for SD Mode - Write  */

    /* 32-bit Block Count */
    CommandDescriptor1[0].u16AttrValid = 1u;
    CommandDescriptor1[0].u16AttrEnd = 0u;
    CommandDescriptor1[0].u16AttrInt = 0u;
    CommandDescriptor1[0].u16Act = CY_SD_HOST_ADMA3_CMD;
    CommandDescriptor1[0].u16Len = 0u;
    CommandDescriptor1[0].u32addr = dataConfig.numberOfBlock;

    /* (16-bit Block Count) + Block Size */
    CommandDescriptor1[1].u16AttrValid = 1u;
    CommandDescriptor1[1].u16AttrEnd = 0u;
    CommandDescriptor1[1].u16AttrInt = 0u;
    CommandDescriptor1[1].u16Act = CY_SD_HOST_ADMA3_CMD;
    CommandDescriptor1[1].u16Len = 0u;
    CommandDescriptor1[1].u32addr = dataConfig.blockSize;

    /* Argument */
    CommandDescriptor1[2].u16AttrValid = 1u;
    CommandDescriptor1[2].u16AttrEnd = 0u;
    CommandDescriptor1[2].u16AttrInt = 0u;
    CommandDescriptor1[2].u16Act = CY_SD_HOST_ADMA3_CMD;
    CommandDescriptor1[2].u16Len = 0u;
    CommandDescriptor1[2].u32addr = address;

    /* Command + Transfer Mode */
    CommandDescriptor1[3].u16AttrValid = 1u;
    CommandDescriptor1[3].u16AttrEnd = 0u;
    CommandDescriptor1[3].u16AttrInt = 0u;
    CommandDescriptor1[3].u16Act = CY_SD_HOST_ADMA3_CMD;
    CommandDescriptor1[3].u16Len = 0u;
    CommandDescriptor1[3].u32addr = CY_SD_HOST_SD_CMD25 << (16u + 0x8u) |
                                                               stcCmd.dataPresent << (16u + 0x5u) |
                                                               stcCmd.enableIdxCheck << (16u + 0x4u) |
                                                               stcCmd.enableCrcCheck << (16u + 0x3u) |
                                                               stcCmd.respType<< (16u + 0x0u) |
                                                               1u << (0x5u) |   /* Multi block/single block Select */
                                                               0u << (0x4u) |   /* 1 - read, 0 - write */
                                                               CY_SD_HOST_AUTO_CMD_12 << (0x2u) |   /* Auto CMD enable */
                                                               1u << (0x1u) |   /* Block count enable */
                                                               1u << (0x0u) |    /* DMA enable */
                                                               1u << (0x8u);   /* Response Interrupt Disable */

    /* The DMA2 Descriptor */
    CommandDescriptor1[4].u16Act = CY_SD_HOST_ADMA_TRAN;
    CommandDescriptor1[4].u16AttrEnd = 1u;
    CommandDescriptor1[4].u16AttrValid = 1u;
    CommandDescriptor1[4].u16AttrInt = 0u;
    CommandDescriptor1[4].u16Len = CY_SD_HOST_BLOCK_SIZE * dataConfig.numberOfBlock;
    CommandDescriptor1[4].u32addr = (uint32_t)&u8TxBuff;


    /* 32-bit Block Count */
    CommandDescriptor1_1[0].u16AttrValid = 1u;
    CommandDescriptor1_1[0].u16AttrEnd = 0u;
    CommandDescriptor1_1[0].u16AttrInt = 0u;
    CommandDescriptor1_1[0].u16Act = CY_SD_HOST_ADMA3_CMD;
    CommandDescriptor1_1[0].u16Len = 0u;
    CommandDescriptor1_1[0].u32addr = dataConfig.numberOfBlock;

    /* (16-bit Block Count) + Block Size */
    CommandDescriptor1_1[1].u16AttrValid = 1u;
    CommandDescriptor1_1[1].u16AttrEnd = 0u;
    CommandDescriptor1_1[1].u16AttrInt = 0u;
    CommandDescriptor1_1[1].u16Act = CY_SD_HOST_ADMA3_CMD;
    CommandDescriptor1_1[1].u16Len = 0u;
    CommandDescriptor1_1[1].u32addr = dataConfig.blockSize;

    /* Argument */
    CommandDescriptor1_1[2].u16AttrValid = 1u;
    CommandDescriptor1_1[2].u16AttrEnd = 0u;
    CommandDescriptor1_1[2].u16AttrInt = 0u;
    CommandDescriptor1_1[2].u16Act = CY_SD_HOST_ADMA3_CMD;
    CommandDescriptor1_1[2].u16Len = 0u;
    CommandDescriptor1_1[2].u32addr = address + addressOffset;

    /* Command + Transfer Mode */
    CommandDescriptor1_1[3].u16AttrValid = 1u;
    CommandDescriptor1_1[3].u16AttrEnd = 0u;
    CommandDescriptor1_1[3].u16AttrInt = 0u;
    CommandDescriptor1_1[3].u16Act = CY_SD_HOST_ADMA3_CMD;
    CommandDescriptor1_1[3].u16Len = 0u;
    CommandDescriptor1_1[3].u32addr = CY_SD_HOST_SD_CMD25 << (16u + 0x8u) |
                                                               stcCmd.dataPresent << (16u + 0x5u) |
                                                               stcCmd.enableIdxCheck << (16u + 0x4u) |
                                                               stcCmd.enableCrcCheck << (16u + 0x3u) |
                                                               stcCmd.respType<< (16u + 0x0u) |
                                                               1u << (0x5u) |   /* Multi block/single block Select */
                                                               0u << (0x4u) |   /* 1 - read, 0 - write */
                                                               CY_SD_HOST_AUTO_CMD_12 << (0x2u) |   /* Auto CMD enable */
                                                               1u << (0x1u) |   /* Block count enable */
                                                               1u << (0x0u) |    /* DMA enable */
                                                               1u << (0x8u);   /* Response Interrupt Disable */
    /* The DMA2 Descriptor */
    CommandDescriptor1_1[4].u16Act = CY_SD_HOST_ADMA_TRAN;
    CommandDescriptor1_1[4].u16AttrEnd = 1u;
    CommandDescriptor1_1[4].u16AttrValid = 1u;
    CommandDescriptor1_1[4].u16AttrInt = 0u;
    CommandDescriptor1_1[4].u16Len = CY_SD_HOST_BLOCK_SIZE * dataConfig.numberOfBlock;
    CommandDescriptor1_1[4].u32addr = (uint32_t)&u8TxBuff_1;

    /* The Command Descriptor for SD Mode - Read */

    /* 32-bit Block Count */
    CommandDescriptor2[0].u16AttrValid = 1u;
    CommandDescriptor2[0].u16AttrEnd = 0u;
    CommandDescriptor2[0].u16AttrInt = 0u;
    CommandDescriptor2[0].u16Act = CY_SD_HOST_ADMA3_CMD;
    CommandDescriptor2[0].u16Len = 0u;
    CommandDescriptor2[0].u32addr = dataConfig.numberOfBlock;

    /* (16-bit Block Count) + Block Size */
    CommandDescriptor2[1].u16AttrValid = 1u;
    CommandDescriptor2[1].u16AttrEnd = 0u;
    CommandDescriptor2[1].u16AttrInt = 0u;
    CommandDescriptor2[1].u16Act = CY_SD_HOST_ADMA3_CMD;
    CommandDescriptor2[1].u16Len = 0u;
    CommandDescriptor2[1].u32addr = dataConfig.blockSize;

    /* Argument */
    CommandDescriptor2[2].u16AttrValid = 1u;
    CommandDescriptor2[2].u16AttrEnd = 0u;
    CommandDescriptor2[2].u16AttrInt = 0u;
    CommandDescriptor2[2].u16Act = CY_SD_HOST_ADMA3_CMD;
    CommandDescriptor2[2].u16Len = 0u;
    CommandDescriptor2[2].u32addr = address + addressOffset;

    /* Command + Transfer Mode */
    CommandDescriptor2[3].u16AttrValid = 1u;
    CommandDescriptor2[3].u16AttrEnd = 0u;
    CommandDescriptor2[3].u16AttrInt = 0u;
    CommandDescriptor2[3].u16Act = CY_SD_HOST_ADMA3_CMD;
    CommandDescriptor2[3].u16Len = 0u;
    CommandDescriptor2[3].u32addr = CY_SD_HOST_SD_CMD18 << (16u + 0x8u) |
                                                               stcCmd.dataPresent << (16u + 0x5u) |
                                                               stcCmd.enableIdxCheck << (16u + 0x4u) |
                                                               stcCmd.enableCrcCheck << (16u + 0x3u) |
                                                               stcCmd.respType<< (16u + 0x0u) |
                                                               1u << (0x5u) |   /* Multi block/single block Select */
                                                               1u << (0x4u) |   /* 1 - read, 0 - write */
                                                               CY_SD_HOST_AUTO_CMD_12 << (0x2u) |   /* Auto CMD enable */
                                                               1u << (0x1u) |   /* Block count enable */
                                                               1u << (0x0u);   /* DMA enable */
    /* The DMA2 Descriptor */
    CommandDescriptor2[4].u16Act = CY_SD_HOST_ADMA_TRAN;
    CommandDescriptor2[4].u16AttrEnd = 1u;
    CommandDescriptor2[4].u16AttrValid = 1u;
    CommandDescriptor2[4].u16AttrInt = 0u;
    CommandDescriptor2[4].u16Len = CY_SD_HOST_BLOCK_SIZE * dataConfig.numberOfBlock;
    CommandDescriptor2[4].u32addr = (uint32_t)&u8RxBuff;

    dataConfig.data = (uint32_t*)&IntegratedDescriptor1[0];

    enRet = Cy_SD_Host_InitDataTransfer((stc_SDHC_t *)CY_SDHC_TYPE, &dataConfig);


    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = CY_SD_HOST_ERROR;
    u32Retry = RETRY_WRITE_READ;
    while (CY_SD_HOST_SUCCESS != enRet && (u32Retry-- > 0u) )
    {
         enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)CY_SDHC_TYPE);
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    u32Retry = CY_SD_HOST_RETRY_TIME;

    while ((true == _FLD2BOOL(SDHC_CORE_PSTATE_REG_DAT_LINE_ACTIVE, CY_SDHC_TYPE->CORE.unPSTATE_REG.u32Register)) && (u32Retry-- > 0u) )
    {
    	Cy_SysLib_DelayUs(CY_SD_HOST_WRITE_TIMEOUT_MS);
    }

    if ( true == _FLD2BOOL(SDHC_CORE_PSTATE_REG_DAT_LINE_ACTIVE, CY_SDHC_TYPE->CORE.unPSTATE_REG.u32Register))
    {
        enRet = CY_SD_HOST_ERROR_TIMEOUT;
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }


#endif


#if 0
    // Write data.
    dataConfig.data = (uint32_t*)&IntegratedDescriptor1[1];

    enRet = Cy_SD_Host_InitDataTransfer((stc_SDHC_t *)CY_SDHC_TYPE, &dataConfig, &sd_host_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = CY_SD_HOST_ERROR;
    u32Retry = RETRY_WRITE_READ;
    while (CY_SD_HOST_SUCCESS != enRet && (u32Retry-- > 0u) )
    {
         enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)CY_SDHC_TYPE);
    }

    u32Retry = CY_SD_HOST_RETRY_TIME;

    while ((true == _FLD2BOOL(SDHC_CORE_PSTATE_REG_DAT_LINE_ACTIVE, CY_SDHC_TYPE->CORE.unPSTATE_REG.u32Register)) && (u32Retry-- > 0u) )
    {
    	Cy_SysLib_DelayUs(CY_SD_HOST_WRITE_TIMEOUT_MS);
    }

    if ( true == _FLD2BOOL(SDHC_CORE_PSTATE_REG_DAT_LINE_ACTIVE, CY_SDHC_TYPE->CORE.unPSTATE_REG.u32Register))
    {
        enRet = CY_SD_HOST_ERROR_TIMEOUT;
    }
#endif

#if 0
    // Read data.
    dataConfig.data = (uint32_t*)&IntegratedDescriptor1[2];

    enRet = Cy_SD_Host_InitDataTransfer((stc_SDHC_t *)CY_SDHC_TYPE, &dataConfig, &sd_host_context);


    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = CY_SD_HOST_ERROR;
    u32Retry = RETRY_WRITE_READ;
    while (CY_SD_HOST_SUCCESS != enRet && (u32Retry-- > 0u) )
    {
         enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)CY_SDHC_TYPE);
    }

    //Cy_SysLib_Delay(WRITE_READ_TIME);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }
    else
    {
        //check value
        if (memcmp(u8RxBuff, u8TxBuff, CY_SD_HOST_BLOCK_SIZE*SECTORNUM))
        {
            bSuccess = false;
        }
    }
#endif

#if 0
    // Read data.
    CommandDescriptor2[2].u32addr = address + SECTORNUM;

    dataConfig.data = (uint32_t*)&IntegratedDescriptor1[2];

    enRet = Cy_SD_Host_InitDataTransfer((stc_SDHC_t *)CY_SDHC_TYPE, &dataConfig, &sd_host_context);


    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = CY_SD_HOST_ERROR;
    u32Retry = RETRY_WRITE_READ;
    while (CY_SD_HOST_SUCCESS != enRet && (u32Retry-- > 0u) )
    {
         enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)CY_SDHC_TYPE);
    }

    //Cy_SysLib_Delaay(WRITE_READ_TIME);
#endif


#if 1
    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }
    else
    {
        //check value
        if (memcmp(u8RxBuff, u8TxBuff_1, CY_SD_HOST_BLOCK_SIZE*SECTORNUM))
        {
            bSuccess = false;
        }
    }
#endif

    // finish process.
    memset(CommandDescriptor1, 0u, sizeof(CommandDescriptor1));
    memset(CommandDescriptor2, 0u, sizeof(CommandDescriptor2));
    memset(IntegratedDescriptor1, 0u, sizeof(IntegratedDescriptor1));


    while (1)
    {
        if(bSuccess == true)
        {
            Cy_SysTick_DelayInUs(50000);
            Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
        }
    }
}

// Commented line 454 in sd_host.c
