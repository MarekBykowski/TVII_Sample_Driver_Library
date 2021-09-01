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

/* Assign pins for SD Host on SDHC0 */
#define SDHC_PORT1                     (P6_0_PORT)
#define SDHC_PORT2                     (P7_0_PORT)

#define SDHC_CARD_DETECT_N_NUM         (P6_1_NUM)
#define SDHC_CARD_CMD_NUM              (P6_4_NUM)
#define SDHC_CLK_CARD_NUM              (P6_3_NUM)
#define SDHC_CARD_DAT_3TO00_NUM        (P7_0_NUM)
#define SDHC_CARD_DAT_3TO01_NUM        (P7_1_NUM)
#define SDHC_CARD_DAT_3TO02_NUM        (P7_2_NUM)
#define SDHC_CARD_DAT_3TO03_NUM        (P7_3_NUM)

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

#define SECTORNUM  							(8)
#define TOTAL_SIZE 							(100*1024*1024)
#define SD_HOST_CLK_DIV_NUM   				(0U)
#define RETRY_WRITE_READ  					(8)
#define CY_SD_HOST_FUJE_TIMEOUT_MS          (1000U) /* The Fuje timeout for one block. */
#define CY_SD_HOST_RETRY_TIME               (1000U)  /* The number loops to make the timeout in msec. */
#define CY_SD_HOST_READ_TIMEOUT_MS          (100U)  /* The Read timeout for one block. */
#define CY_SD_HOST_WRITE_TIMEOUT_MS         (250U)  /* The Write timeout for one block. */
#define CY_SD_HOST_BUFFER_RDY_TIMEOUT_MS    (150U)  /* The Buffer read ready timeout. */

static uint8_t      u8RxBuff[CY_SD_HOST_BLOCK_SIZE*SECTORNUM];
static uint8_t      u8TxBuff[CY_SD_HOST_BLOCK_SIZE*SECTORNUM];
static uint8_t      gu8StartCh      = 0x5;
static uint32_t     gu8StartSector  = 0;
uint32_t gcount = 0;
uint32_t dataRx = 0;
uint32_t dataTx = 0x12345678;
uint32_t    rca = 0;
cy_en_sd_host_card_type_t cardType = CY_SD_HOST_UNUSABLE;
cy_stc_sd_host_context_t SDIF0_context;
cy_en_sd_host_card_capacity_t cardCapacity;
uint32_t scr[2];
uint32_t csd[4]; /* The Card-Specific Data register. */
uint32_t cardStatus = 0u;
uint32_t cid[4u];  /* The Device Indentification register. */
cy_en_sd_host_status_t         enRet           = CY_SD_HOST_SUCCESS;
bool           bSuccess        = true;

uint32_t test_temp = 0;

const cy_stc_sysint_irq_t irq_cfg =
{
    .sysIntSrc  = sdhc_0_interrupt_general_IRQn,
    .intIdx     = CPUIntIdx2_IRQn,
    .isEnabled = true
};


static cy_en_sd_host_status_t Cy_SD_Host_PollCmdComplete(stc_SDHC_t *base);

/*******************************************************************************
* Function Name: Cy_SD_Host_PollCmdComplete
****************************************************************************//**
*
*  Waits for the command complete event.
*
* \param *base
*     The SD host registers structure pointer.
*
* \return \ref cy_en_sd_host_status_t
*
*******************************************************************************/
static cy_en_sd_host_status_t Cy_SD_Host_PollCmdComplete(stc_SDHC_t *base)
{
    cy_en_sd_host_status_t ret = CY_SD_HOST_ERROR_TIMEOUT;
    uint32_t               retry = CY_SD_HOST_RETRY_TIME;

    while (retry > 0UL)
    {
        /* Command complete */
        if (true == _FLD2BOOL(SDHC_CORE_NORMAL_INT_STAT_R_CMD_COMPLETE,
                             base->CORE.unNORMAL_INT_STAT_R.u16Register))
        {
            /* Clear interrupt flag */
             base->CORE.unNORMAL_INT_STAT_R.u16Register = CY_SD_HOST_CMD_COMPLETE;

            ret = CY_SD_HOST_SUCCESS;
            break;
        }

        Cy_SysLib_DelayUs(5u);
        retry--;
    }

    return ret;
}



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

/* Implement ISR  */
void SD_Host_User_Isr(void)
{
    uint32_t normalStatus;
    uint32_t errorStatus;

    normalStatus = Cy_SD_Host_GetNormalInterruptStatus((stc_SDHC_t const *)SDHC0);

    /* Check the Error event */
    if (0u < normalStatus)
    {
        /* Clear the normalStatus event */
        Cy_SD_Host_ClearNormalInterruptStatus((stc_SDHC_t *)SDHC0, normalStatus);
    }

    errorStatus = Cy_SD_Host_GetErrorInterruptStatus((stc_SDHC_t const *)SDHC0);

    /* Check the Error event */
    if (0u < errorStatus)
    {
        /* Clear the Error event */
        Cy_SD_Host_ClearErrorInterruptStatus((stc_SDHC_t *)SDHC0, errorStatus);
    }
}


static cy_en_sd_host_status_t SdcmdRxData(stc_SDHC_t *base,
                                   cy_stc_sd_host_data_config_t *pcmd);
static cy_en_sd_host_status_t SdcmdRxData(stc_SDHC_t *base,
                                   cy_stc_sd_host_data_config_t *pcmd)
{
    cy_en_sd_host_status_t ret;
    uint32_t               blkSize = 0u;
    static uint32_t        blkCnt  = 0u;
    uint32_t               i       = 0u;
    uint32_t               *pu32Buff = NULL;
    uint32_t               retry;

    blkCnt = pcmd->numberOfBlock;
    blkSize = pcmd->blockSize;
    pu32Buff = pcmd->data;

    while (blkCnt > 0u)
    {
        retry   = CY_SD_HOST_RETRY_TIME;
			ret = CY_SD_HOST_ERROR_TIMEOUT;
			while ((CY_SD_HOST_ERROR_TIMEOUT == ret) && (retry-- > 0u))
        {
            /* Buffer read ready */
            if (1u == _FLD2BOOL(SDHC_CORE_NORMAL_INT_STAT_R_BUF_RD_READY, base->CORE.unNORMAL_INT_STAT_R.u16Register))
            {
                /* Clear interrupt flag */
                base->CORE.unNORMAL_INT_STAT_R.u16Register = 0x0020u;

					ret = CY_SD_HOST_SUCCESS;
                break;
            }

            Cy_SysLib_DelayUs(CY_SD_HOST_BUFFER_RDY_TIMEOUT_MS);
        }

        for ( i = blkSize >> 2u; i != 0u; i-- )
        {
            *pu32Buff++ = Cy_SD_Host_BufferRead(base);
        }
        blkCnt--;
    }

	ret = Cy_SD_Host_PollTransferComplete(base);

    return ret;
}

cy_en_sd_host_status_t SdcmdTxData(stc_SDHC_t *base,
                                   cy_stc_sd_host_data_config_t *pstcCmd);
cy_en_sd_host_status_t SdcmdTxData(stc_SDHC_t *base,
                                   cy_stc_sd_host_data_config_t *pstcCmd)
{
    cy_en_sd_host_status_t ret      = CY_SD_HOST_ERROR;
    uint32_t    u32blksize = 0u;
    uint32_t    u32blkcnt  = 0u;
    uint32_t    i          = 0u;
    uint32_t    *pu32Buff  = NULL;
    uint32_t    retry   = CY_SD_HOST_RETRY_TIME;

    u32blkcnt = pstcCmd->numberOfBlock;
    u32blksize = pstcCmd->blockSize;
    pu32Buff = pstcCmd->data;

    {
        retry   = CY_SD_HOST_RETRY_TIME;
		ret = CY_SD_HOST_ERROR_TIMEOUT;
		while ((CY_SD_HOST_ERROR_TIMEOUT == ret) && (retry-- > 0u))
        {
            /* Buffer read ready */
            if (1u == _FLD2BOOL(SDHC_CORE_NORMAL_INT_STAT_R_BUF_WR_READY,
                                                    base->CORE.unNORMAL_INT_STAT_R.u16Register))
            {
                /* Clear interrupt flag */
                base->CORE.unNORMAL_INT_STAT_R.u16Register = CY_SD_HOST_BUF_WR_READY;

				ret = CY_SD_HOST_SUCCESS;
                break;
            }

            Cy_SysLib_DelayUs(CY_SD_HOST_BUFFER_RDY_TIMEOUT_MS);
        }

        if (CY_SD_HOST_SUCCESS != ret)
        {
            return ret;
        }

        while (u32blkcnt > 0u)
        {



            for (i = u32blksize >> 2u; i != 0u; i--)
            {
                Cy_SD_Host_BufferWrite(base, *pu32Buff++);
            }
            u32blkcnt--;
        }

        retry = CY_SD_HOST_RETRY_TIME;
		ret = CY_SD_HOST_ERROR_TIMEOUT;
        while (CY_SD_HOST_SUCCESS != ret && (retry-- > 0u) )
        {
            ret = Cy_SD_Host_PollTransferComplete(base);
        }

        if (CY_SD_HOST_SUCCESS != ret)
        {
            return ret;
        }
    }

    retry = CY_SD_HOST_RETRY_TIME;

    while ((true == _FLD2BOOL(SDHC_CORE_PSTATE_REG_DAT_LINE_ACTIVE, SDHC0->CORE.unPSTATE_REG.u32Register)) && (retry-- > 0u) )
    {
    	Cy_SysLib_DelayUs(CY_SD_HOST_WRITE_TIMEOUT_MS);
    }

    if ( true == _FLD2BOOL(SDHC_CORE_PSTATE_REG_DAT_LINE_ACTIVE, SDHC0->CORE.unPSTATE_REG.u32Register) )
    {
        ret = CY_SD_HOST_ERROR_TIMEOUT;
    }

    return ret;
}

int main(void)
{

    uint32_t            i               = 0;
    bool           bLedOn          = 0;
    cy_stc_sd_host_sd_card_config_t stcSdcardCfg;
    uint8_t             u8ch            = 0;
    uint32_t sdStatus[64] = { 0u };
    uint32_t pstcStatus;
    uint32_t irq_status;
    uint32_t irq_error_status;
    cy_stc_sd_host_write_read_config_t dataRead;
    cy_stc_sd_host_write_read_config_t dataWrite;
    cy_en_sd_host_erase_type_t eraseType = CY_SD_HOST_ERASE_ERASE;
    cy_stc_sd_host_init_config_t   hostConfig      = { 0u };
    uint32_t retry   = CY_SD_HOST_RETRY_TIME;
    cy_stc_sd_host_cmd_config_t  cmd   = { 0u };
    cy_stc_sd_host_data_config_t dataConfig = { 0u };
	
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache
    
    __enable_irq(); /* Enable global interrupts. */

    Cy_SysClk_HfClockSetDivider(CY_SYSCLK_HFCLK_6, CY_SYSCLK_HFCLK_DIVIDE_BY_2);
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_6); //CLK_HF6 enable   

    Cy_SysInt_InitIRQ(&irq_cfg);
    /* Set the Interrupt Priority & Enable the Interrupt */
    NVIC_SetPriority(CPUIntIdx3_IRQn, 3u);
    NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, SD_Host_User_Isr);
    
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);
    
#if 0
    // CLK_HF Setup, for now all HFs enabled
    CY_SET_REG32(0x40261240, 0x80000000);
    CY_SET_REG32(0x40261244, 0x80000000);
    CY_SET_REG32(0x40261248, 0x80000000);
    CY_SET_REG32(0x4026124C, 0x80000000);
    CY_SET_REG32(0x40261250, 0x80000000);
    CY_SET_REG32(0x40261254, 0x80000000);
    CY_SET_REG32(0x40261258, 0x80000000);
    CY_SET_REG32(0x4026125C, 0x80000000);
//    CY_SET_REG32(0x40460000, 0x80000000);
//    CY_SET_REG32(0x4046102C, 0x00000005);
//    CY_SET_REG32(0x40461534, 0x00000008);
    //CY_SET_REG32(0x40300180, 0x00190000);
    //CY_SET_REG32(0x40310C44, 0x00000E00);
//    test_temp = CY_GET_REG32(0x40461000);
//    test_temp = CY_GET_REG32(0x4046103c);
    //CY_SET_REG32(0x4046103c, 0x10000000);
    
    // SDHC0 INIT
    CY_SET_REG32(0x40460000, 0x80000000); // Write WRAP_CTL
    test_temp = CY_GET_REG32(0x40460000); // Read WRAP_CTL
    CY_SET_REG32(0x4046102c, 0x00006005); // Clock Setup
    CY_SET_REG32(0x40461028, 0x00000100);
    // enable card_detect in from pad.
    // enable clock output to pad
    CY_SET_REG32(0x40461534, 0x00000008);
    
    // p12_6/7 p13, to be changed to P24/25
    //CY_SET_REG32(0x403000c4, 0x00001a1a);
    //CY_SET_REG32(0x403000d0, 0x1a1a1a1a);
    //CY_SET_REG32(0x40310644, 0x00ee0000);
    //CY_SET_REG32(0x403106c4, 0x0000eeee);
    
    // CMR1 - P24/25
    // P24_0_SDHC_CARD_DETECT_N
    // P24_2_SDHC_CLK_CARD		
    // P24_3_SDHC_CARD_CMD		
    // P25_0_SDHC_CARD_DAT_3TO00
    // P25_1_SDHC_CARD_DAT_3TO01
    // P25_2_SDHC_CARD_DAT_3TO02
    // P25_3_SDHC_CARD_DAT_3TO03   
    // CY_SET_REG32(0x40300180, 0x19190019);
    // CY_SET_REG32(0x40300190, 0x19191919);
    // CY_SET_REG32(0x40310C44, 0x0000EE0E);
    // CY_SET_REG32(0x40310CC4, 0x0000EEEE);
    
    // CMR3 - P6/7
    // P6_1_SDHC0_CARD_DETECT_N
    // P6_3_SDHC0_CLK_CARD		
    // P6_4_SDHC0_CARD_CMD		
    // P7_0_SDHC0_CARD_DAT_3TO00
    // P7_1_SDHC0_CARD_DAT_3TO01
    // P7_2_SDHC0_CARD_DAT_3TO02
    // P7_3_SDHC0_CARD_DAT_3TO03    
    CY_SET_REG32(0x40300060, 0x19001900); // P6/HSIOM0
    CY_SET_REG32(0x40300064, 0x00000019); // P6/HSIOM1
    CY_SET_REG32(0x40300070, 0x19191919); // P7/HSIOM0
    CY_SET_REG32(0x40310344, 0x000EE0E0); // P6/GPIO
    CY_SET_REG32(0x403103C4, 0x0000EEEE); // P7/GPIO
    
    test_temp = CY_GET_REG32(0x40461024);
    test_temp = CY_GET_REG32(0x40461024);
    test_temp = CY_GET_REG32(0x40461040);
    test_temp = CY_GET_REG32(0x40461044);
    test_temp = CY_GET_REG32(0x404610fc);
    
    CY_SET_REG32(0x40461028, 0x00000f02);
    
    CY_SET_REG32(0x4046103c, 0x10000000);
    CY_SET_REG32(0x4046102c, 0x0000600f);
    // enable interrupt
    CY_SET_REG32(0x40461034, 0xffffffff);
    CY_SET_REG32(0x40461038, 0xffffffff);
    
    // CMD0
    CY_SET_REG32(0x40461008, 0x00000000);
    CY_SET_REG32(0x4046100c, 0x00c00000);
    CY_SET_REG32(0x4046102c, 0x0600760f);
    test_temp = CY_GET_REG32(0x4046102c);
    test_temp = CY_GET_REG32(0x40461030);
    
    // CMD2 - Get CID
//    CY_SET_REG32(0x40461008, 0x00000000);
//    CY_SET_REG32(0x4046100c, 0x02010000);
//    test_temp = CY_GET_REG32(0x40461030);
//    CY_SET_REG32(0x40461030, 0x00000001);
//    test_temp = CY_GET_REG32(0x40461030);
//    test_temp = CY_GET_REG32(0x40461030);
//    test_temp = CY_GET_REG32(0x40461030);
//    test_temp = CY_GET_REG32(0x40461030);
//    test_temp = CY_GET_REG32(0x40461030);
//    test_temp = CY_GET_REG32(0x40461030);
//    test_temp = CY_GET_REG32(0x40461030);
//    test_temp = CY_GET_REG32(0x40461010);
//    test_temp = CY_GET_REG32(0x40461014);
//    test_temp = CY_GET_REG32(0x40461018);
//    test_temp = CY_GET_REG32(0x4046101c);
    
    // CMD8
    CY_SET_REG32(0x40461030, 0xffffffff);
    CY_SET_REG32(0x40461008, 0x000001aa);
    // cmd8, index 0, type 3
    CY_SET_REG32(0x4046100c, 0x08020000);
    // delay, wait cmd complete
    test_temp = CY_GET_REG32(0x40461030);
    CY_SET_REG32(0x40461030, 0x01);
    test_temp = CY_GET_REG32(0x40461030);
    test_temp = CY_GET_REG32(0x40461010);
    test_temp = CY_GET_REG32(0x40461014);
    test_temp = CY_GET_REG32(0x40461018);
    test_temp = CY_GET_REG32(0x4046101c);
#endif
    
#if 0    
    CY_SET_REG32(0x40261100, 0x80000000);
    CY_SET_REG32(0x40261240, 0x80000000);
    CY_SET_REG32(0x40261244, 0x80000000);
    CY_SET_REG32(0x40261248, 0x80000000);
    CY_SET_REG32(0x4026124C, 0x80000000);
    CY_SET_REG32(0x40261250, 0x80000000);
    CY_SET_REG32(0x40261254, 0x80000000);
    CY_SET_REG32(0x40261258, 0x80000000);
    CY_SET_REG32(0x4026125C, 0x80000000);
    test_temp = CY_GET_REG32(0x40040C00);
    test_temp = CY_GET_REG32(0x40042c88);
    test_temp = CY_GET_REG32(0x40600000);
    test_temp = CY_GET_REG32(0x40610000);
    test_temp = CY_GET_REG32(0x40630000);
    test_temp = CY_GET_REG32(0x40650000);
    CY_SET_REG32(0x40460000, 0xFFFFFFFF);
    test_temp = CY_GET_REG32(0x40460000);
#endif
    
    /* Initialize the configuration */
    hostConfig.dmaType = CY_SD_HOST_DMA_ADMA2;
    hostConfig.enableLedControl = false;
    hostConfig.emmc = false;

    stcSdcardCfg.lowVoltageSignaling = false; // true;
    stcSdcardCfg.busWidth = CY_SD_HOST_BUS_WIDTH_4_BIT;
    stcSdcardCfg.cardType = &cardType;
    stcSdcardCfg.rca = &rca;
    stcSdcardCfg.cardCapacity = &cardCapacity;

    dataRead.data = (uint32_t*)u8RxBuff;            /**< The pointer to data. */
    dataRead.address = gu8StartSector;         /**< The address to write/read data on the card or eMMC. */
    dataRead.numberOfBlocks = 1u;  /**< The number of blocks to write/read. */
    dataRead.autoCommand = CY_SD_HOST_AUTO_CMD_NONE;     /**< Selects which auto commands are used if any. */
    dataRead.dataTimeout = 0xcu;     /**< The timeout value for the transfer. */
    dataRead.enReliableWrite = false; /**< For EMMC cards enable reliable write. */
    dataRead.enableDma = true;

    dataWrite.data = (uint32_t*)u8TxBuff;            /**< The pointer to data. */
    dataWrite.address = gu8StartSector;         /**< The address to write/read data on the card or eMMC. */
    dataWrite.numberOfBlocks = 1u;  /**< The number of blocks to write/read. */
    dataWrite.autoCommand = CY_SD_HOST_AUTO_CMD_NONE;     /**< Selects which auto commands are used if any. */
    dataWrite.dataTimeout = 0xcu;     /**< The timeout value for the transfer. */
    dataWrite.enReliableWrite = false; /**< For EMMC cards enable reliable write. */
    dataWrite.enableDma = true;

    (void)Cy_SD_Host_Enable((stc_SDHC_t *)SDHC0);
    
    /**************************************/
    /* Port Setting for SDHC0             */
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
    
    /* Connect SD Host SDHC0 function to pins */
    //Cy_GPIO_SetHSIOM(SDHC_PORT1, SDHC_IO_VOLT_SEL_NUM, P12_7_SDHC_IO_VOLT_SEL);
    //Cy_GPIO_SetHSIOM(SDHC_PORT1, SDHC_CARD_IF_PWR_EN_NUM, P12_6_SDHC_CARD_IF_PWR_EN);
//    Cy_GPIO_SetHSIOM(SDHC_PORT1, SDHC_CARD_DETECT_N_NUM, P24_0_SDHC_CARD_DETECT_N);
//    Cy_GPIO_SetHSIOM(SDHC_PORT1, SDHC_CARD_CMD_NUM, P24_3_SDHC_CARD_CMD);
//    Cy_GPIO_SetHSIOM(SDHC_PORT1, SDHC_CLK_CARD_NUM, P24_2_SDHC_CLK_CARD);
//    Cy_GPIO_SetHSIOM(SDHC_PORT2, SDHC_CARD_DAT_3TO00_NUM, P25_0_SDHC_CARD_DAT_3TO00);
//    Cy_GPIO_SetHSIOM(SDHC_PORT2, SDHC_CARD_DAT_3TO01_NUM, P25_1_SDHC_CARD_DAT_3TO01);
//    Cy_GPIO_SetHSIOM(SDHC_PORT2, SDHC_CARD_DAT_3TO02_NUM, P25_2_SDHC_CARD_DAT_3TO02);
//    Cy_GPIO_SetHSIOM(SDHC_PORT2, SDHC_CARD_DAT_3TO03_NUM, P25_3_SDHC_CARD_DAT_3TO03);

    /* Configure pins for SDHC0 operation */
    //Cy_GPIO_SetDrivemode(SDHC_PORT1, SDHC_IO_VOLT_SEL_NUM, CY_GPIO_DM_STRONG);
    //Cy_GPIO_SetDrivemode(SDHC_PORT1, SDHC_CARD_IF_PWR_EN_NUM, CY_GPIO_DM_STRONG);
//    Cy_GPIO_SetDrivemode(SDHC_PORT1, SDHC_CARD_DETECT_N_NUM, CY_GPIO_DM_STRONG);
//    Cy_GPIO_SetDrivemode(SDHC_PORT1, SDHC_CARD_CMD_NUM, CY_GPIO_DM_STRONG);
//    Cy_GPIO_SetDrivemode(SDHC_PORT1, SDHC_CLK_CARD_NUM, CY_GPIO_DM_STRONG);
//    Cy_GPIO_SetDrivemode(SDHC_PORT2, SDHC_CARD_DAT_3TO00_NUM, CY_GPIO_DM_STRONG);
//    Cy_GPIO_SetDrivemode(SDHC_PORT2, SDHC_CARD_DAT_3TO01_NUM, CY_GPIO_DM_STRONG);
//    Cy_GPIO_SetDrivemode(SDHC_PORT2, SDHC_CARD_DAT_3TO02_NUM, CY_GPIO_DM_STRONG);
//    Cy_GPIO_SetDrivemode(SDHC_PORT2, SDHC_CARD_DAT_3TO03_NUM, CY_GPIO_DM_STRONG);

    /* Configure SD Host to operate */
    enRet = Cy_SD_Host_Init((stc_SDHC_t *)SDHC0, &hostConfig, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = Cy_SD_Host_InitCard((stc_SDHC_t *)SDHC0, &stcSdcardCfg, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        while(1); // Initialization failed
    }

    Cy_SysLib_Delay(1);

#if 0
    enRet = Cy_SD_Host_GetSdStatus((stc_SDHC_t *)SDHC0, sdStatus, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }
#endif


#if 1
    // Single block write
    dataConfig.blockSize = 512u;
    dataConfig.numberOfBlock = 1u;
    dataConfig.enableDma = false;
    dataConfig.autoCommand = CY_SD_HOST_AUTO_CMD_NONE;
    dataConfig.read = false;
    dataConfig.data = (uint32_t *)u8TxBuff;
    dataConfig.dataTimeout = 0xcu;
    dataConfig.enableIntAtBlockGap = false;
    dataConfig.enReliableWrite = false;

    //data read start
    memset(u8RxBuff, 0x0, sizeof(u8RxBuff));
    memset(u8TxBuff, 0x1, sizeof(u8TxBuff));

    enRet = Cy_SD_Host_InitDataTransfer((stc_SDHC_t *)SDHC0, &dataConfig);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    cmd.commandIndex    = 24u;
    cmd.commandArgument = 0u;
    cmd.dataPresent     = true;
    cmd.respType        = CY_SD_HOST_RESPONSE_LEN_48;
    cmd.enableCrcCheck  = true;
    cmd.enableIdxCheck  = true;
    cmd.cmdType         = CY_SD_HOST_CMD_NORMAL;

    enRet = Cy_SD_Host_SendCommand((stc_SDHC_t *)SDHC0, &cmd);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = SdcmdTxData((stc_SDHC_t *)SDHC0, &dataConfig);

	if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }
#endif

#if 1
    // Multi block read
    dataConfig.blockSize = 512u;
    dataConfig.numberOfBlock = 2u;
    dataConfig.enableDma = false;
    dataConfig.autoCommand = CY_SD_HOST_AUTO_CMD_12;
    dataConfig.read = true;
    dataConfig.data = (uint32_t *)u8RxBuff;
    dataConfig.dataTimeout = 0xcu;
    dataConfig.enableIntAtBlockGap = false;
    dataConfig.enReliableWrite = false;

    //data read start
    memset(u8RxBuff, 0x0, sizeof(u8RxBuff));

    enRet = Cy_SD_Host_InitDataTransfer((stc_SDHC_t *)SDHC0, &dataConfig);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    cmd.commandIndex    = 18u;
    cmd.commandArgument = 0u;
    cmd.dataPresent     = true;
    cmd.respType        = CY_SD_HOST_RESPONSE_LEN_48;
    cmd.enableCrcCheck  = true;
    cmd.enableIdxCheck  = true;
    cmd.cmdType         = CY_SD_HOST_CMD_NORMAL;

    enRet = Cy_SD_Host_SendCommand((stc_SDHC_t *)SDHC0, &cmd);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = SdcmdRxData((stc_SDHC_t *)SDHC0, &dataConfig);

	if (CY_SD_HOST_SUCCESS != enRet)
    {
            bSuccess = false;
    }

    if (u8TxBuff[1] != u8RxBuff[1u])
    {
            bSuccess = false;
    }
#endif

#if 0
    memset(u8RxBuff, 0x0, sizeof(u8RxBuff));

    // Single block read to have the status for Cy_SD_Host_GetCardStatus() test
    enRet = Cy_SD_Host_Read(SDHC0, &dataRead, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = Cy_SD_Host_PollTransferComplete(SDHC0);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }
#endif

#if 0
    enRet =  Cy_SD_Host_WriteProtect(SDHC0, false, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
       bSuccess = false;
    }

    cardStatus = Cy_SD_Host_GetCardStatus(SDHC0, &SDIF0_context);

    Cy_SysLib_DelayUs(10000);

    uint32_t error;

    error = Cy_SD_Host_GetErrorInterruptStatus(SDHC0);

    /* Check the Error event */
    if (0u < error)
    {
        /* Clear the Error event */
        Cy_SD_Host_ClearErrorInterruptStatus(SDHC0, error);

        Cy_SD_Host_SoftwareReset(SDHC0, CY_SD_HOST_RESET_CMD_LINE);
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
       bSuccess = false;
    }

    // Single block write test.
    memset(u8TxBuff, 0x26, sizeof(u8TxBuff));

    enRet = Cy_SD_Host_Write(SDHC0, &dataWrite, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = Cy_SD_Host_PollTransferComplete(SDHC0);

    cardStatus = Cy_SD_Host_GetCardStatus(SDHC0, &SDIF0_context);

    memset(u8RxBuff, 0x0, sizeof(u8RxBuff));

    // Single block read to have the status for Cy_SD_Host_GetCardStatus() test
    enRet = Cy_SD_Host_Read(SDHC0, &dataRead, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = Cy_SD_Host_PollTransferComplete(SDHC0);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }


    Cy_SysLib_DelayUs(10000);

    cardStatus = Cy_SD_Host_GetCardStatus(SDHC0, &SDIF0_context);

#endif

#if 0
    enRet = Cy_SD_Host_GetScr((stc_SDHC_t *)SDHC0, scr, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    if (0x03803502 != scr[0])
    {
       // bSuccess = false;
    }
    if (0x00000000 != scr[1])
    {
       // bSuccess = false;
    }
#endif

    //test start
    memset(&u8TxBuff, 0x0, sizeof(u8TxBuff));

    u8ch = gu8StartCh;

#if 0
    memset(u8RxBuff, 0x0, sizeof(u8RxBuff));

    // Single block read to have the status for Cy_SD_Host_GetCardStatus() test
    enRet = Cy_SD_Host_Read((stc_SDHC_t *)SDHC0, &dataRead, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = CY_SD_HOST_ERROR;
    retry = RETRY_WRITE_READ;
    while (CY_SD_HOST_SUCCESS != enRet && (retry-- > 0u) )
    {
         enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)SDHC0);
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    cardStatus = Cy_SD_Host_GetCardStatus((stc_SDHC_t *)SDHC0, &SDIF0_context);

    if (0x00000900 != cardStatus)
    {
        bSuccess = false;
    }

    enRet = Cy_SD_Host_GetSdStatus((stc_SDHC_t *)SDHC0, sdStatus, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

#endif

#if 1
    // Single block write test.
    memset(u8TxBuff, 0x21, sizeof(u8RxBuff));

    enRet = Cy_SD_Host_Write((stc_SDHC_t *)SDHC0, &dataWrite, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = CY_SD_HOST_ERROR;
    retry = RETRY_WRITE_READ;
    while (CY_SD_HOST_SUCCESS != enRet && (retry-- > 0u) )
    {
         enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)SDHC0);
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    retry = CY_SD_HOST_RETRY_TIME;

    while ((true == _FLD2BOOL(SDHC_CORE_PSTATE_REG_DAT_LINE_ACTIVE, SDHC0->CORE.unPSTATE_REG.u32Register)) && (retry-- > 0u) )
    {
        Cy_SysLib_DelayUs(CY_SD_HOST_WRITE_TIMEOUT_MS);
    }

    if ( true == _FLD2BOOL(SDHC_CORE_PSTATE_REG_DAT_LINE_ACTIVE, SDHC0->CORE.unPSTATE_REG.u32Register) )
    {
        enRet = CY_SD_HOST_ERROR_TIMEOUT;
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }
#endif

#if 1
    pstcStatus =  Cy_SD_Host_GetAutoCmdErrStatus((stc_SDHC_t const *)SDHC0);

    if (0 != pstcStatus)
    {
        bSuccess = false;
    }
#endif

#if 1
    cardStatus = Cy_SD_Host_GetCardStatus((stc_SDHC_t *)SDHC0, &SDIF0_context);

    if (0x00000900 != cardStatus)
    {
        bSuccess = false;
    }
#endif

#if 1
    irq_status = Cy_SD_Host_GetNormalInterruptStatus((stc_SDHC_t const *)SDHC0);

    if (0x100u != (irq_status & 0x100u))
    {
        bSuccess = false;
    }
#endif

#if 1
    irq_error_status = Cy_SD_Host_GetErrorInterruptStatus((stc_SDHC_t const *)SDHC0);

    if (0 != irq_error_status)
    {
        bSuccess = false;
    }
#endif


#if 1
    // Single block read back & check.
    memset(u8RxBuff, 0x0, sizeof(u8RxBuff));

    enRet = Cy_SD_Host_Read((stc_SDHC_t *)SDHC0, &dataRead, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = CY_SD_HOST_ERROR;
    retry = RETRY_WRITE_READ;
    while (CY_SD_HOST_SUCCESS != enRet && (retry-- > 0u) )
    {
         enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)SDHC0);
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }
    else
    {
        //check value
        if (memcmp(u8RxBuff, u8TxBuff, CY_SD_HOST_BLOCK_SIZE))
        {
            bSuccess = false;
        }
    }
#endif


#if 1
    // Multiple block write test.
    //for ( i = 0; i <  TOTAL_SIZE / (CY_SD_HOST_BLOCK_SIZE * SECTORNUM); i++ )
    for ( i = 0; i < 10u; i++ )
    {
        //build data
        memset(u8TxBuff, u8ch, CY_SD_HOST_BLOCK_SIZE*SECTORNUM);
        u8ch++;

        if(2048 == i)
        {
        //  i = i;
        }

        dataWrite.autoCommand = CY_SD_HOST_AUTO_CMD_AUTO;
        dataWrite.address = gu8StartSector + i * SECTORNUM;
        dataWrite.numberOfBlocks = SECTORNUM;
        enRet = Cy_SD_Host_Write((stc_SDHC_t *)SDHC0, &dataWrite, &SDIF0_context);

        if (CY_SD_HOST_SUCCESS != enRet)
        {
            bSuccess = false;
            break;
        }

        enRet = CY_SD_HOST_ERROR;
        retry = RETRY_WRITE_READ;
        while (CY_SD_HOST_SUCCESS != enRet && (retry-- > 0u) )
        {
             enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)SDHC0);
        }

        if (CY_SD_HOST_SUCCESS != enRet)
        {
            bSuccess = false;
            break;
        }

        retry = CY_SD_HOST_RETRY_TIME;

        while ((true == _FLD2BOOL(SDHC_CORE_PSTATE_REG_DAT_LINE_ACTIVE, SDHC0->CORE.unPSTATE_REG.u32Register)) && (retry-- > 0u) )
        {
            Cy_SysLib_DelayUs(CY_SD_HOST_WRITE_TIMEOUT_MS);
        }

        if ( true == _FLD2BOOL(SDHC_CORE_PSTATE_REG_DAT_LINE_ACTIVE, SDHC0->CORE.unPSTATE_REG.u32Register) )
        {
            enRet = CY_SD_HOST_ERROR_TIMEOUT;
        }
        if (CY_SD_HOST_SUCCESS != enRet)
        {
            bSuccess = false;
            break;
        }

        if (i % 100 == 0)
        {
            bLedOn = !bLedOn;
           // TestPin_Set(LED_B, bLedOn);
        }

        gcount = i;
    }
#endif


#if 1
    u8ch = gu8StartCh;

    // Multiple block read back & check.
   // for ( i = 0; i < TOTAL_SIZE / (CY_SD_HOST_BLOCK_SIZE * SECTORNUM); i++ )
    for ( i = 0; i < 10u; i++ )
    {
        memset(u8RxBuff, 0x0, sizeof(u8RxBuff));

        dataRead.autoCommand = CY_SD_HOST_AUTO_CMD_AUTO;
        dataRead.address = gu8StartSector + i * SECTORNUM;
        dataRead.numberOfBlocks = SECTORNUM;

        enRet = Cy_SD_Host_Read((stc_SDHC_t *)SDHC0, &dataRead, &SDIF0_context);

        if (CY_SD_HOST_SUCCESS != enRet)
        {
            bSuccess = false;
        }

        enRet = CY_SD_HOST_ERROR;
        retry = RETRY_WRITE_READ;
        while (CY_SD_HOST_SUCCESS != enRet && (retry-- > 0u) )
        {
             enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)SDHC0);
        }

        if (CY_SD_HOST_SUCCESS != enRet)
        {
            bSuccess = false;
            break;
        }
        else
        {
            //check value
            memset(u8TxBuff, u8ch, CY_SD_HOST_BLOCK_SIZE*SECTORNUM);
            u8ch++;

            if (memcmp(u8RxBuff, u8TxBuff, CY_SD_HOST_BLOCK_SIZE*SECTORNUM))
            {
                bSuccess = false;
                break;
            }
        }

        if (i % 100 == 0)
        {
            bLedOn = !bLedOn;
           // TestPin_Set(LED_G, bLedOn);
        }

    }
#endif


#if 1
    /**< Erase block #1 512-1024 bytes . */
    enRet = Cy_SD_Host_Erase((stc_SDHC_t *)SDHC0, 1,
                   2, eraseType, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = Cy_SD_Host_PollCmdComplete((stc_SDHC_t *)SDHC0);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    /* polling result */
    enRet = CY_SD_HOST_ERROR;
    i = CY_SD_HOST_RETRY_TIME;

    while (i-- > 0u)
    {
        cardStatus = Cy_SD_Host_GetCardStatus((stc_SDHC_t *)SDHC0, &SDIF0_context);
        if (((CY_SD_HOST_CARD_TRAN << CY_SD_HOST_CMD13_CURRENT_STATE) |
            (1u << CY_SD_HOST_CMD13_READY_FOR_DATA)) == cardStatus)
        {
            enRet = CY_SD_HOST_SUCCESS;
            break;
        }

        Cy_SysLib_DelayUs(CY_SD_HOST_FUJE_TIMEOUT_MS);
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

#endif


#if 1
    //read back & check.
    memset(u8RxBuff, 0x0, sizeof(u8RxBuff));
    memset(u8TxBuff, 0x5, sizeof(u8TxBuff));

    dataRead.autoCommand = CY_SD_HOST_AUTO_CMD_NONE;
    dataRead.address = 1u;         /**< The address to write/read data on the card or eMMC. */
    dataRead.numberOfBlocks = 1u;  /**< The number of blocks to write/read. */

    enRet = Cy_SD_Host_Read((stc_SDHC_t *)SDHC0, &dataRead, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = CY_SD_HOST_ERROR;
    retry = RETRY_WRITE_READ;
    while (CY_SD_HOST_SUCCESS != enRet && (retry-- > 0u) )
    {
         enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)SDHC0);
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }
    else
    {
        //check value
        if (true == (memcmp(u8TxBuff, u8TxBuff, CY_SD_HOST_BLOCK_SIZE)))
        {
            bSuccess = false;
        }
    }


    dataRead.autoCommand = CY_SD_HOST_AUTO_CMD_NONE;
    dataRead.address = 3u;         /**< The address to write/read data on the card or eMMC. */
    dataRead.numberOfBlocks = 1u;  /**< The number of blocks to write/read. */

    enRet = Cy_SD_Host_Read((stc_SDHC_t *)SDHC0, &dataRead, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = CY_SD_HOST_ERROR;
    retry = RETRY_WRITE_READ;
    while (CY_SD_HOST_SUCCESS != enRet && (retry-- > 0u) )
    {
         enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)SDHC0);
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }
    else
    {
        //check value
        if (memcmp(u8RxBuff, u8TxBuff, CY_SD_HOST_BLOCK_SIZE))
        {
            bSuccess = false;
        }
    }

    dataRead.autoCommand = CY_SD_HOST_AUTO_CMD_NONE;
    dataRead.address = 0u;         /**< The address to write/read data on the card or eMMC. */
    dataRead.numberOfBlocks = 1u;  /**< The number of blocks to write/read. */

    enRet = Cy_SD_Host_Read((stc_SDHC_t *)SDHC0, &dataRead, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = CY_SD_HOST_ERROR;
    retry = RETRY_WRITE_READ;
    while (CY_SD_HOST_SUCCESS != enRet && (retry-- > 0u) )
    {
         enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)SDHC0);
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }
    else
    {
        //check value
        if (memcmp(u8RxBuff, u8TxBuff, CY_SD_HOST_BLOCK_SIZE))
        {
            bSuccess = false;
        }
    }

#endif



#if 1
    Cy_SD_Host_DisableCardVoltage((stc_SDHC_t *)SDHC0);


    cardStatus = Cy_SD_Host_GetCardStatus((stc_SDHC_t *)SDHC0, &SDIF0_context);

    if (0x00000900 == cardStatus)
    {
        //bSuccess = false;
    }
#endif

    while (1);
}
