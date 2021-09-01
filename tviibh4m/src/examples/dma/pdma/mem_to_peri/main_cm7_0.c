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

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include <stdio.h>
#include <stdarg.h>

#include "cy_project.h"
#include "cy_device_headers.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/
/* for DW */
#define BUFFER_SIZE             36
#define DW1_CHANNEL_7           7

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/
/* for UART */
static void Peripheral_Initialization(void);
static void Term_Printf(void *fmt, ...);

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/
/* for DW */
static  uint8_t                     au8SrcBuffer[BUFFER_SIZE];
static  cy_stc_pdma_descr_t         stcDescr;
const   cy_stc_pdma_chnl_config_t   chnl7Config = {
        /* CURR_PTR                          */    .PDMA_Descriptor =  &stcDescr,
        /* CH_CTL          PREEMPTABLE       */    .preemptable    =   0u,
        /* CH_CTL          PRIO              */    .priority       =   0u,
        /* CH_CTL          ENABLED           */    .enable         =   1u,  /* enabled after initialization */
                                                };
static  cy_stc_pdma_descr_config_t  stcDw1DescrConfig = {
        /* DESCR_CTL       WAIT_FOR_DEACT    */    .deact          =   0u,
        /* DESCR_CTL       INTR_TYPE         */    .intrType       =   CY_PDMA_INTR_1ELEMENT_CMPLT,
        /* DESCR_CTL       TR_OUT_TYPE       */    .trigoutType    =   CY_PDMA_TRIGOUT_1ELEMENT_CMPLT,
        /* DESCR_CTL       CH_DISABLE        */    .chStateAtCmplt =   CY_PDMA_CH_DISABLED,
        /* DESCR_CTL       TR_IN_TYPE        */    .triginType     =   CY_PDMA_TRIGIN_DESCR,
        /* DESCR_CTL       DATA_SIZE         */    .dataSize       =   CY_PDMA_BYTE,
        /* DESCR_CTL       SRC_TRANSFER_SIZE */    .srcTxfrSize    =   0u,
        /* DESCR_CTL       DST_TRANSFER_SIZE */    .destTxfrSize   =   1u,
        /* DESCR_CTL       DESCR_TYPE        */    .descrType      =   CY_PDMA_1D_TRANSFER,
        /* DESCR_SRC                         */    .srcAddr        =   &au8SrcBuffer[0],
        /* DESCR_DST                         */    .destAddr       =   (uint32_t *)&CY_USB_SCB_TYPE->unTX_FIFO_WR.u32Register,
        /* DESCR_X_CTL     SRC_X_INCR        */    .srcXincr       =   1u,
        /* DESCR_X_CTL     DST_X_INCR        */    .destXincr      =   0u,
        /* DESCR_X_CTL     X_COUNT           */    .xCount         =   BUFFER_SIZE,
        /* DESCR_Y_CTL     SRC_Y_INCR        */    .srcYincr       =   0u,
        /* DESCR_Y_CTL     DST_Y_INCR        */    .destYincr      =   0u,
        /* DESCR_Y_CTL     Y_COUNT           */    .yCount         =   0u,
        /* DESCR_NEXT_PTR                    */    .descrNext      =   0u
                                                };

/* for UART */
uint8_t                             g_uart_out_data[128];
cy_stc_scb_uart_context_t           g_stc_uart_context;
cy_stc_scb_uart_config_t            g_stc_uart_config = {
                                                   .uartMode                   = CY_SCB_UART_STANDARD,
                                                   .oversample                 = 8,
                                                   .dataWidth                  = 8,
                                                   .enableMsbFirst             = false,
                                                   .stopBits                   = CY_SCB_UART_STOP_BITS_1,
                                                   .parity                     = CY_SCB_UART_PARITY_NONE,
                                                   .enableInputFilter          = false,
                                                   .dropOnParityError          = false,
                                                   .dropOnFrameError           = false,
                                                   .enableMutliProcessorMode   = false,
                                                   .receiverAddress            = 0,
                                                   .receiverAddressMask        = 0,
                                                   .acceptAddrInFifo           = false,
                                                   .irdaInvertRx               = false,
                                                   .irdaEnableLowPowerReceiver = false,
                                                   .smartCardRetryOnNack       = false,
                                                   .enableCts                  = false,
                                                   .ctsPolarity                = CY_SCB_UART_ACTIVE_LOW,
                                                   .rtsRxFifoLevel             = 0,
                                                   .rtsPolarity                = CY_SCB_UART_ACTIVE_LOW,
                                                   .breakWidth                 = 0,
                                                   .rxFifoTriggerLevel         = 0,
                                                   .rxFifoIntEnableMask        = 0,
                                                   .txFifoTriggerLevel         = 0,
                                                   .txFifoIntEnableMask        = 0
                                                };

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/
int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    uint32_t            i;
    uint8_t             *p_src;

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Peripheral_Initialization();

    /************/
    /* SCB-UART */
    /************/
    Cy_SCB_UART_DeInit(CY_USB_SCB_TYPE);
    Cy_SCB_UART_Init(CY_USB_SCB_TYPE, &g_stc_uart_config, &g_stc_uart_context);
    Cy_SCB_UART_Enable(CY_USB_SCB_TYPE);

    /******/
    /* DW */
    /******/
    Cy_PDMA_Disable(DW1);
    Cy_PDMA_Descr_Init(&stcDescr, &stcDw1DescrConfig);
    Cy_PDMA_Chnl_Init(DW1,
                      DW1_CHANNEL_7,
                      (const cy_stc_pdma_chnl_config_t*) &chnl7Config);
    Cy_PDMA_Chnl_SetInterruptMask(DW1, DW1_CHANNEL_7);
    Cy_PDMA_Enable(DW1);

    /* for test */
    p_src = &au8SrcBuffer[0];
    for (i=BUFFER_SIZE; i>0; i--) {
        *p_src++ = 0x30 + i;
    }

    /* Opening UART Comment */
    Term_Printf("\n\n");
    Term_Printf("DW Test from Mem to Peri(UART)\n");
    Term_Printf("after 2 sec, transfer start (%d byte)\n", BUFFER_SIZE);
    Cy_SysTick_DelayInUs(5000UL);

    /***************/
    /* Trigger MUX */
    /***************/
    Cy_TrigMux_SwTrigger( TRIG_OUT_MUX_2_PDMA1_TR_IN7,
                          TRIGGER_TYPE_CPUSS_DW1_TR_IN__EDGE,
                          1u);

    for(;;)
    {
    }
}

void Peripheral_Initialization(void)
{
    cy_stc_gpio_pin_config_t    stc_port_pin_cfg_uart = {0};

    /*-----------------------------*/
    /* Port Configuration for UART */
    /*-----------------------------*/

    /* P13.0 -> scb[3].uart_rx */
    stc_port_pin_cfg_uart.driveMode = CY_GPIO_DM_HIGHZ;
    stc_port_pin_cfg_uart.hsiom     = CY_USB_SCB_UART_RX_MUX;
    Cy_GPIO_Pin_Init(CY_USB_SCB_UART_RX_PORT, CY_USB_SCB_UART_RX_PIN, &stc_port_pin_cfg_uart);

    /* P13.1 -> scb[3].uart_tx */
    stc_port_pin_cfg_uart.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    stc_port_pin_cfg_uart.hsiom     = CY_USB_SCB_UART_TX_MUX;
    Cy_GPIO_Pin_Init(CY_USB_SCB_UART_TX_PORT, CY_USB_SCB_UART_TX_PIN, &stc_port_pin_cfg_uart);

    /*-----------------------------*/
    /* Clock Configuration for UART */
    /*-----------------------------*/
    
    Cy_SysClk_HfClkEnable(2u); // Enable clk_hf2

    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(CY_USB_SCB_UART_PCLK, CY_SYSCLK_DIV_24_5_BIT, 0u);

    /* Sets the 24.5 divider */
  #if (CY_USE_PSVP == 1)
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 25u,  1u);   // 115246
  #else
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 85u, 26u); // Divider 86.8125 --> 80MHz / 86.8125 / 8 (oversampling) = 115190 Hz
  #endif

    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u);
}

void Term_Printf(void *fmt, ...)
{
    va_list arg;

    /* UART Print */
    va_start(arg, fmt);
    vsprintf((char*)&g_uart_out_data[0], (char*)fmt, arg);
    Cy_SCB_UART_PutArray(CY_USB_SCB_TYPE, g_uart_out_data, strlen((char *)g_uart_out_data));
    va_end(arg);

    Cy_SysTick_DelayInUs(1000UL);
}
/* [] END OF FILE */
