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


#if (CY_USE_PSVP == 1)
    #define USER_LED_PORT           CY_LED0_PORT
    #define USER_LED_PIN            CY_LED0_PIN
    #define USER_LED_PIN_MUX        CY_LED0_PIN_MUX
#else
    #define USER_LED_PORT           CY_USER_LED1_PORT
    #define USER_LED_PIN            CY_USER_LED1_PIN
    #define USER_LED_PIN_MUX        CY_USER_LED1_PIN_MUX 
#endif

/* Select UART Echo Type                                                   */
/*                                                                         */
/* Use Low-Level API                                                       */
/*  (1) Polling & Receive by 1 byte unit                                   */
/* Use High-Level API                                                      */
/*  (2) Interrupt & Receive by 1 byte unit                                 */
/*  (3) Interrupt & Receive by threshold byte unit (E_UART_RECV_THRESHOLD) */
/*  (4) Interrupt & Receive using Ring Buffer (Half of RX FIFO size)       */

/* Select Baud Rate */
#define E_UART_BAUD_115200  115200
#define E_UART_BAUD_57600   57600
#define E_UART_BAUD_38400   38400
#define E_UART_BAUD_19200   19200
#define E_UART_BAUD_9600    9600
#define E_UART_BAUD_2400    2400
#define E_UART_BAUD_1200    1200
#define E_UART_BAUD         E_UART_BAUD_115200

/* Local Definision */
#define E_UART_RECV_THRESHOLD    1
#define E_UART_RING_BUF_SIZE     512
#define E_UART_USER_BUF_SIZE     512
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

/* Local Functions Declaration */
void Peripheral_Initialization(void);
void Scb_UART_IntrISR(void);
void Scb_UART_Event(uint32_t locEvents);
void Term_Printf(void *fmt, ...);

/* Local Macro for Termnal Print */
#define TERM_PRINT_H(...) Term_Printf(__VA_ARGS__)
//#define TERM_PRINT_L(...) Term_Printf(__VA_ARGS__)
#define TERM_PRINT_L(...)

/* SCB - UART Configuration */
cy_stc_scb_uart_context_t   g_stc_uart_context;
cy_stc_scb_uart_config_t    g_stc_uart_config = {
                                                   .uartMode                   = CY_SCB_UART_STANDARD,
                                                   .oversample                 = 1,
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
                                                   .rxFifoIntEnableMask        = E_UART_RX_INTR_FACTER,
                                                   .txFifoTriggerLevel         = 0,
                                                   .txFifoIntEnableMask        = E_UART_TX_INTR_FACTER
                                                };

/* Local Variables */
uint8_t                     g_uart_out_data[128];                       // TX Buffer for Terminal Print
uint8_t                     g_uart_in_data[128];                        // RX Buffer
uint8_t                     g_uart_rx_ring[E_UART_RING_BUF_SIZE] = {0}; // RX Ring Buffer
uint8_t                     g_uart_user_buf[E_UART_USER_BUF_SIZE];      // User Buffer for coping from Ring Buffer

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


int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    uint8_t     comment[] = "UART Test";
    uint32_t    major = CY_SCB_DRV_VERSION_MAJOR;
    uint32_t    minor = CY_SCB_DRV_VERSION_MINOR;

    __enable_irq(); /* Enable global interrupts. */

    /* Initialize Port and Clock */
    Peripheral_Initialization();
    
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);

    /* Initilize & Enable UART */
    Cy_SCB_UART_DeInit(CY_USB_SCB_TYPE);
    Cy_SCB_UART_Init(CY_USB_SCB_TYPE, &g_stc_uart_config, &g_stc_uart_context);
    Cy_SCB_UART_RegisterCallback(CY_USB_SCB_TYPE, (scb_uart_handle_events_t)Scb_UART_Event, &g_stc_uart_context);
    Cy_SCB_UART_Enable(CY_USB_SCB_TYPE);

    /* Enable Interrupt */

    NVIC_EnableIRQ(CPUIntIdx1_IRQn);


    /* Opening UART Comment */
    TERM_PRINT_H("\n%s (ver=%d.%d)\n", comment, major, minor);
    TERM_PRINT_H("INTR 1BYTE ECHO\n");


    /* UART Echo Test (High-Level)                                            */
    /* (3) Interrupt & Receive by threshold byte unit (E_UART_RECV_THRESHOLD) */
    Cy_SCB_UART_Receive(CY_USB_SCB_TYPE, g_uart_in_data, E_UART_RECV_THRESHOLD, &g_stc_uart_context);
    
    Cy_SysPm_Sleep(CY_SYSPM_WAIT_FOR_INTERRUPT);


    for(;;)
    { 
       Cy_SysTick_DelayInUs(50000);
       Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN); 
       
       Cy_SysPm_Sleep(CY_SYSPM_WAIT_FOR_INTERRUPT);

    }
}

void Peripheral_Initialization(void)
{
    cy_stc_gpio_pin_config_t    stc_port_pin_cfg_uart = {0};
    cy_stc_sysint_irq_t         stc_sysint_irq_cfg_uart;

    /*-----------------------------*/
    /* Port Configuration for UART */
    /*-----------------------------*/

    /* P18.0 -> scb[1].uart_rx */
    stc_port_pin_cfg_uart.driveMode = CY_GPIO_DM_HIGHZ;
    stc_port_pin_cfg_uart.hsiom     = CY_USB_SCB_UART_RX_MUX;
    Cy_GPIO_Pin_Init(CY_USB_SCB_UART_RX_PORT, CY_USB_SCB_UART_RX_PIN, &stc_port_pin_cfg_uart);

    /* P18.1 -> scb[1].uart_tx */
    stc_port_pin_cfg_uart.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    stc_port_pin_cfg_uart.hsiom     = CY_USB_SCB_UART_TX_MUX;
    Cy_GPIO_Pin_Init(CY_USB_SCB_UART_TX_PORT, CY_USB_SCB_UART_TX_PIN, &stc_port_pin_cfg_uart);

    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_2);
    /*-----------------------------*/
    /* Clock Configuration for UART */
    /*-----------------------------*/

    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(CY_USB_SCB_UART_PCLK, CY_SYSCLK_DIV_24_5_BIT, 0u);

#if (CY_USE_PSVP == 1)    
    /* Sets the 24.5 divider */
  #if   (E_UART_BAUD == E_UART_BAUD_115200)
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 25u,  1u);   // 115246
    g_stc_uart_config.oversample = 8;
  #elif (E_UART_BAUD == E_UART_BAUD_57600)
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 51u,  3u);   // 57588
    g_stc_uart_config.oversample = 8;
  #elif (E_UART_BAUD == E_UART_BAUD_38400)
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 77u,  4u);   // 38400
    g_stc_uart_config.oversample = 8;
  #elif (E_UART_BAUD == E_UART_BAUD_19200)
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 155u, 8u);   // 19200
    g_stc_uart_config.oversample = 8;
  #elif (E_UART_BAUD == E_UART_BAUD_9600)
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 311u, 16u);  // 9600
    g_stc_uart_config.oversample = 8;
  #elif (E_UART_BAUD == E_UART_BAUD_2400)
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 624u, 0u);   // 2400
    g_stc_uart_config.oversample = 16;
  #elif (E_UART_BAUD == E_UART_BAUD_1200)
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 1249, 0u);   // 1200
    g_stc_uart_config.oversample = 16;
  #else 
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 25u,  3u);   // 115246
    g_stc_uart_config.oversample = 8;
  #endif
#else // CY_USE_PSVP
    /* Sets the 24.5 divider */
  #if   (E_UART_BAUD == E_UART_BAUD_115200)
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 85u, 26u); // Divider 86.8125 --> 80MHz / 86.8125 / 8 (oversampling) = 115190 Hz
    g_stc_uart_config.oversample = 8;
  #else 
    #error "Baudrate dividers not yet calculated for 80MHz. Please add on your own!"
  #endif    
#endif

    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u);

    /*-----------------------------------*/
    /* Interrrupt Configuration for UART */
    /*-----------------------------------*/

    /* Int1 -> CY_USB_SCB_TYPE */
    stc_sysint_irq_cfg_uart.sysIntSrc = CY_USB_SCB_UART_IRQN;
    stc_sysint_irq_cfg_uart.intIdx    = CPUIntIdx1_IRQn;
    stc_sysint_irq_cfg_uart.isEnabled = true;
    Cy_SysInt_InitIRQ(&stc_sysint_irq_cfg_uart);
    Cy_SysInt_SetSystemIrqVector(stc_sysint_irq_cfg_uart.sysIntSrc, Scb_UART_IntrISR);
}

void Scb_UART_IntrISR(void)
{

    /* UART Echo Test (High-Level)            */
    /* (2) Interrupt & Receive by 1 byte unit */
    uint32_t num = Cy_SCB_UART_GetNumInRxFifo(CY_USB_SCB_TYPE);
    if (num != 0) 
    {
        Cy_SCB_UART_Receive(CY_USB_SCB_TYPE, &g_uart_in_data[0], num, &g_stc_uart_context);
        Cy_SCB_UART_Transmit(CY_USB_SCB_TYPE, &g_uart_in_data[0], num, &g_stc_uart_context);
        Cy_SCB_SetRxFifoLevel(CY_USB_SCB_TYPE, 0);
    }

    /* UART interrupt handler */
    Cy_SCB_UART_Interrupt(CY_USB_SCB_TYPE, &g_stc_uart_context);
    NVIC_ClearPendingIRQ(CPUIntIdx1_IRQn);
}

void Scb_UART_Event(uint32_t locEvents)
{
    switch (locEvents) {

        case CY_SCB_UART_TRANSMIT_IN_FIFO_EVENT:
            break;

        case CY_SCB_UART_TRANSMIT_DONE_EVENT:
            break;

        case CY_SCB_UART_RECEIVE_DONE_EVENT:
            /* Re-Enable Interrupt */
            Cy_SCB_SetRxInterruptMask(CY_USB_SCB_TYPE, g_stc_uart_config.rxFifoIntEnableMask);
            break;

        case CY_SCB_UART_RB_FULL_EVENT:
            break;

        case CY_SCB_UART_RECEIVE_ERR_EVENT:
            break;

        case CY_SCB_UART_TRANSMIT_ERR_EVENT:
            break;

        default:
            break;
    }
}

void Term_Printf(void *fmt, ...)
{
    va_list arg;

    /* UART Print */
    va_start(arg, fmt);
    vsprintf((char*)&g_uart_out_data[0], (char*)fmt, arg);
    while (Cy_SCB_UART_IsTxComplete(CY_USB_SCB_TYPE) != true) {};
    Cy_SCB_UART_PutArray(CY_USB_SCB_TYPE, g_uart_out_data, strlen((char *)g_uart_out_data));
    va_end(arg);
}



/* [] END OF FILE */
