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


/* Transmit data from SCB(UART) to memory(DW) via Trigger MUX  */
/*                                                             */
/* Please input any byte on terminal tool(UART-115200)         */
/* After inputting, transfer to memory automotically           */

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
/* for UART */
#define E_UART_RECV_THRESHOLD    4  // This means threshold byte of trigger for transfer to memory
#define E_UART_RX_INTR_FACTER     (                              \
                                 CY_SCB_UART_RX_TRIGGER      |   \
                               /*CY_SCB_UART_RX_NOT_EMPTY    | */\
                               /*CY_SCB_UART_RX_FULL         | */\
                                 CY_SCB_UART_RX_OVERFLOW     |   \
                                 CY_SCB_UART_RX_UNDERFLOW    |   \
                                 CY_SCB_UART_RX_ERR_FRAME    |   \
                                 CY_SCB_UART_RX_ERR_PARITY   |   \
                                 CY_SCB_UART_RX_BREAK_DETECT |   \
                                 0                               \
                                )
#define E_UART_TX_INTR_FACTER     (                              \
                                 CY_SCB_UART_TX_TRIGGER      |   \
                               /*CY_SCB_UART_TX_NOT_FULL     | */\
                               /*CY_SCB_UART_TX_EMPTY        | */\
                                 CY_SCB_UART_TX_OVERFLOW     |   \
                               /*CY_SCB_UART_TX_UNDERFLOW    | */\
                                 CY_SCB_UART_TX_DONE         |   \
                               /*CY_SCB_UART_TX_NACK         | */\
                               /*CY_SCB_UART_TX_ARB_LOST     | */\
                                 0                               \
                                )
#define TERM_PRINT_H(...) Term_Printf(__VA_ARGS__)

/* for DW */
#define BUFFER_SIZE             36  // This needs that BUFFER_SIZE can be divisible by E_UART_RECV_THRESHOLD
#define DW_CHANNEL              15  // DW1-CH15 must be used because of trigger of scb[3].tr_rx_req
#define DW_2D_LOOP              (BUFFER_SIZE / E_UART_RECV_THRESHOLD)

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
void Peripheral_Initialization(void);
void Scb_UART_IntrISR(void);
void Term_Printf(void *fmt, ...);
void Term_Dump_32bit(const unsigned int *p, unsigned int s);
void DW1_CH15_TransferComplete_IntrISR(void);
/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/
/* for UART */
uint8_t                             g_uart_in_data[128];                        /* RX Buffer                    */
uint8_t                             g_uart_out_data[128];                       /* TX Buffer for Terminal Print */
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

/* for DW */
static  uint8_t                     au8DestBuffer[BUFFER_SIZE] = {0};
static  cy_stc_pdma_descr_t         stcDescr;
const   cy_stc_pdma_chnl_config_t   chnlConfig      =   {
        /* CURR_PTR                          */    .PDMA_Descriptor=   &stcDescr,
        /* CH_CTL          PREEMPTABLE       */    .preemptable    =   0,
        /* CH_CTL          PRIO              */    .priority       =   0,
        /* CH_CTL          ENABLED           */    .enable         =   1,  /*enabled after initialization*/
                                                };
static  cy_stc_pdma_descr_config_t  stcDmaDescrConfig = {
        /* DESCR_CTL       WAIT_FOR_DEACT    */    .deact          =   0,  /*Do not wait for trigger de-activation*/
        /* DESCR_CTL       INTR_TYPE         */    .intrType       =   CY_PDMA_INTR_X_LOOP_CMPLT,
        /* DESCR_CTL       TR_OUT_TYPE       */    .trigoutType    =   CY_PDMA_INTR_1ELEMENT_CMPLT,
        /* DESCR_CTL       CH_DISABLE        */    .chStateAtCmplt =   CY_PDMA_CH_ENABLED,
        /* DESCR_CTL       TR_IN_TYPE        */    .triginType     =   CY_PDMA_TRIGIN_XLOOP,
        /* DESCR_CTL       DATA_SIZE         */    .dataSize       =   CY_PDMA_BYTE,
        /* DESCR_CTL       SRC_TRANSFER_SIZE */    .srcTxfrSize    =   1,
        /* DESCR_CTL       DST_TRANSFER_SIZE */    .destTxfrSize   =   0,
        /* DESCR_CTL       DESCR_TYPE        */    .descrType      =   CY_PDMA_2D_TRANSFER,
        /* DESCR_SRC                         */    .srcAddr        =   (uint32_t *)&CY_USB_SCB_TYPE->unRX_FIFO_RD.u32Register,
        /* DESCR_DST                         */    .destAddr       =   au8DestBuffer,
        /* DESCR_X_CTL     SRC_X_INCR        */    .srcXincr       =   0,
        /* DESCR_X_CTL     DST_X_INCR        */    .destXincr      =   1,
        /* DESCR_X_CTL     X_COUNT           */    .xCount         =   E_UART_RECV_THRESHOLD,
        /* DESCR_Y_CTL     SRC_Y_INCR        */    .srcYincr       =   0,
        /* DESCR_Y_CTL     DST_Y_INCR        */    .destYincr      =   E_UART_RECV_THRESHOLD,
        /* DESCR_Y_CTL     Y_COUNT           */    .yCount         =   DW_2D_LOOP,
        /* DESCR_NEXT_PTR                    */    .descrNext      =   &stcDescr
                                                };

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Peripheral_Initialization();

    /************/
    /* SCB-UART */
    /************/

    /* Initilize & Enable UART */
    Cy_SCB_UART_DeInit(CY_USB_SCB_TYPE);
    Cy_SCB_UART_Init(CY_USB_SCB_TYPE, &g_stc_uart_config, &g_stc_uart_context);
    Cy_SCB_UART_Enable(CY_USB_SCB_TYPE);
    Cy_SCB_UART_Receive(CY_USB_SCB_TYPE, g_uart_in_data, E_UART_RECV_THRESHOLD, &g_stc_uart_context);  // Set threshold

    /* Opening UART Comment */
    TERM_PRINT_H("\nDW Test");
    TERM_PRINT_H("\nTransfer data from UART(SCB3) to memory(DestBuffer) via DW1");
    TERM_PRINT_H("\nPlease Input %d Charactors\n", E_UART_RECV_THRESHOLD);

    /* Enable Interrupt */
    NVIC_EnableIRQ(CPUIntIdx1_IRQn);

    /*************/
    /* Data Wire */
    /*************/

    /* Initialie & Enable DW1 */
    Cy_PDMA_Disable(DW1);
    Cy_PDMA_Chnl_DeInit(DW1, DW_CHANNEL);
    Cy_PDMA_Descr_Init(&stcDescr,&stcDmaDescrConfig);
    Cy_PDMA_Chnl_Init(  DW1,
                        DW_CHANNEL,
                        (const cy_stc_pdma_chnl_config_t*) &chnlConfig);
    Cy_PDMA_Chnl_Enable( DW1, DW_CHANNEL);
    Cy_PDMA_Chnl_SetInterruptMask( DW1, DW_CHANNEL);
    Cy_PDMA_Enable(DW1);

    /***************/
    /* Trigger MUX */
    /***************/
    Cy_TrigMux_Connect1To1( TRIG_OUT_1TO1_8_SCB_RX_TO_PDMA13,
                            0u,
                            TRIGGER_TYPE_CPUSS_DW1_TR_IN__EDGE,
                            0u);

    for(;;)
    {
    }
}

void Peripheral_Initialization(void)
{
    cy_stc_gpio_pin_config_t    stc_port_pin_cfg_uart = {0};
    cy_stc_sysint_irq_t         stc_sysint_irq_cfg_uart;

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

    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(CY_USB_SCB_UART_PCLK, CY_SYSCLK_DIV_24_5_BIT, 0u);

    /* Sets the 24.5 divider */
  #if (CY_USE_PSVP == 1)
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, 0u, 25u, 1u);
  #else
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, 0u, 85u, 26u); // Divider 86.8125 --> 80MHz / 86.8125 / 8 (oversampling) = 115190 Hz
  #endif

    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_24_5_BIT, 0u);

    /*-----------------------------------*/
    /* Interrrupt Configuration for UART */
    /*-----------------------------------*/

    /* Int1 -> UART(SCB3) */
    stc_sysint_irq_cfg_uart.sysIntSrc = cpuss_interrupts_dw1_15_IRQn;
    stc_sysint_irq_cfg_uart.intIdx    = CPUIntIdx1_IRQn;
    stc_sysint_irq_cfg_uart.isEnabled = true;
    Cy_SysInt_InitIRQ(&stc_sysint_irq_cfg_uart);
	Cy_SysInt_SetSystemIrqVector(stc_sysint_irq_cfg_uart.sysIntSrc, DW1_CH15_TransferComplete_IntrISR);
}

void DW1_CH15_TransferComplete_IntrISR(void)
{
    /* Dump DW Dest Buffer for test */
    Term_Printf("DestBuffer(%d byte):\n", BUFFER_SIZE);
    Term_Dump_32bit((unsigned int *)au8DestBuffer, BUFFER_SIZE);

    Cy_PDMA_Chnl_ClearInterrupt( DW1, DW_CHANNEL);
}

void Term_Printf(void *fmt, ...)
{
    va_list arg;

    /* UART Print */
    va_start(arg, fmt);
    vsprintf((char*)&g_uart_out_data[0], (char*)fmt, arg);
    Cy_SCB_UART_PutArray(CY_USB_SCB_TYPE, g_uart_out_data, strlen((char *)g_uart_out_data));
    va_end(arg);

    Cy_SysTick_DelayInUs(5000);
}

void Term_Dump_32bit(const unsigned int *p, unsigned int s)
{
    unsigned char i;

    /* UART Dump */
    if (s > (unsigned int)p)
    {
        s -= (unsigned int)p;
    }

    while ((signed int)s > 0) {
        Term_Printf("%08x: ", (unsigned int)p);
        for (i = 0;  i < 4;  i++)
        {
            if (i < (signed int)(s/4))
            {
                Term_Printf("%08x ", (unsigned int)p[i]);
            }
            else
            {
                Term_Printf("         ");
            }
        }

        Term_Printf("\n");
        s -= 16;
        p += 4;
    }
}

/* [] END OF FILE */
