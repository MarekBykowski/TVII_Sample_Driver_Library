/***************************************************************************//**
* \file main_cm7_0.c
*
* \version 1.0
*
* \brief Main example file for CM7
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
#include <stdio.h>
#include <stdarg.h>
int DST_DATA[64] ={0};

/* for UART */
//------------------------------------------------------------------------------
/* Local Definision */
#define E_UART_RECV_THRESHOLD    8
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
static void Peripheral_Initialization(void);
static void Term_Printf(void *fmt, ...);

/* PCM data  */
//------------------------------------------------------------------------------
static int PCMData_1[96] =
{
    0x0000, 0x085F, 0x10B4, 0x18F8, 0x2120, 0x2924, 0x30FB, 0x389C, 0x3FFF, 0x471C, 0x4DEB, 0x5464,
    0x5A81, 0x603B, 0x658B, 0x6A6C, 0x6ED9, 0x72CB, 0x7640, 0x7934, 0x7BA2, 0x7D89, 0x7EE6, 0x7FB8,
    0x7FFF, 0x7FB8, 0x7EE6, 0x7D89, 0x7BA2, 0x7934, 0x7640, 0x72CB, 0x6ED9, 0x6A6C, 0x658B, 0x603B,
    0x5A81, 0x5464, 0x4DEB, 0x471C, 0x3FFF, 0x389C, 0x30FB, 0x2924, 0x2120, 0x18F8, 0x10B4, 0x085F,
    0x0000, 0xF7A1, 0xEF4B, 0xE708, 0xDEE0, 0xD6DC, 0xCF05, 0xC764, 0xC001, 0xB8E4, 0xB215, 0xAB9C,
    0xA57F, 0x9FC5, 0x9A75, 0x9594, 0x9127, 0x8D35, 0x89C0, 0x86CC, 0x845E, 0x8277, 0x811A, 0x8048,
    0x8001, 0x8048, 0x811A, 0x8277, 0x845E, 0x86CC, 0x89C0, 0x8D35, 0x9127, 0x9594, 0x9A75, 0x9FC5,
    0xA57F, 0xAB9C, 0xB215, 0xB8E4, 0xC001, 0xC764, 0xCF05, 0xD6DC, 0xDEE0, 0xE708, 0xEF4C, 0xF7A1,
 }; 
  

/* PCM data */
//------------------------------------------------------------------------------
static int PCMData_2[96] =
{
    0x0000, 0x085F, 0x10B4, 0x18F8, 0x2120, 0x2924, 0x30FB, 0x389C, 0x3FFF, 0x471C, 0x4DEB, 0x5464,
    0x5A81, 0x603B, 0x658B, 0x6A6C, 0x6ED9, 0x72CB, 0x7640, 0x7934, 0x7BA2, 0x7D89, 0x7EE6, 0x7FB8,
    0x7FFF, 0x7FB8, 0x7EE6, 0x7D89, 0x7BA2, 0x7934, 0x7640, 0x72CB, 0x6ED9, 0x6A6C, 0x658B, 0x603B,
    0x5A81, 0x5464, 0x4DEB, 0x471C, 0x3FFF, 0x389C, 0x30FB, 0x2924, 0x2120, 0x18F8, 0x10B4, 0x085F,
    0x0000, 0xF7A1, 0xEF4B, 0xE708, 0xDEE0, 0xD6DC, 0xCF05, 0xC764, 0xC001, 0xB8E4, 0xB215, 0xAB9C,
    0xA57F, 0x9FC5, 0x9A75, 0x9594, 0x9127, 0x8D35, 0x89C0, 0x86CC, 0x845E, 0x8277, 0x811A, 0x8048,
    0x8001, 0x8048, 0x811A, 0x8277, 0x845E, 0x86CC, 0x89C0, 0x8D35, 0x9127, 0x9594, 0x9A75, 0x9FC5,
    0xA57F, 0xAB9C, 0xB215, 0xB8E4, 0xC001, 0xC764, 0xCF05, 0xD6DC, 0xDEE0, 0xE708, 0xEF4C, 0xF7A1,
};  

/* Main application function */
//------------------------------------------------------------------------------
int main(void)
{
    SystemInit(); 
  
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    __enable_irq();
    uint32_t i, ii, srcs=8;
    uint32_t offset;
    
    
     Peripheral_Initialization();
     
    /************/
    /* SCB-UART */
    /************/
    Cy_SCB_UART_DeInit(CY_USB_SCB_TYPE);
    Cy_SCB_UART_Init(CY_USB_SCB_TYPE, &g_stc_uart_config, &g_stc_uart_context);
    Cy_SCB_UART_Enable(CY_USB_SCB_TYPE);
    
    /**************************************************/
    /*******    Clock divider setting       ***********/
    /**************************************************/
     Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_5);          //Enable hfclk5 for I2S

    Term_Printf("Configuring SRC channels\n\r");
    Cy_Mixer_Src_ChannelSelect(MIXER0_MIXER_SRC_STRUCT0,CY_MIXER_CHANNEL0,CY_MIXER_SRC_DATA_LOW);
    Cy_Mixer_Src_ChannelSelect(MIXER0_MIXER_SRC_STRUCT0,CY_MIXER_CHANNEL1,CY_MIXER_SRC_DATA_HIGH);
    Cy_Mixer_Src_ChannelSelect(MIXER0_MIXER_SRC_STRUCT1,CY_MIXER_CHANNEL0,CY_MIXER_SRC_DATA_LOW);
    Cy_Mixer_Src_ChannelSelect(MIXER0_MIXER_SRC_STRUCT1,CY_MIXER_CHANNEL1,CY_MIXER_SRC_DATA_HIGH);
    Cy_Mixer_Src_SampleFreqRatio(MIXER0_MIXER_SRC_STRUCT0,CY_MIXER_SRC_FREQ_NO_RESAMPLE);
    Cy_Mixer_Src_SampleFreqRatio(MIXER0_MIXER_SRC_STRUCT1,CY_MIXER_SRC_FREQ_NO_RESAMPLE);
    Cy_Mixer_Src_Enable(MIXER0_MIXER_SRC_STRUCT0);
    Cy_Mixer_Src_Enable(MIXER0_MIXER_SRC_STRUCT1);
    
    Term_Printf("Configuring DST \n\r");
    Cy_Mixer_Dst_Enable(MIXER0_MIXER_DST_STRUCT);
    
    Term_Printf("Writing 96 entries to each SRC FIFO's\n\r");
    for(i=0; i<srcs; i++) 
    {
        offset=0x0100*i;
        for(ii=0; ii<96; ii++) 
        {
            if((i==0)||(i==1)) 
            {
                Cy_Mixer_Src_FifoWriteData(MIXER0_MIXER_SRC_STRUCT0,PCMData_1[ii]);
                Cy_Mixer_Src_FifoWriteData(MIXER0_MIXER_SRC_STRUCT1,PCMData_2[ii]);
            } else {
                MIXER0_MIXER_SRC_STRUCT1->unSRC_FIFO_WR.stcField.u32DATA = 0x00000000; // all zeros elsewhere
                MIXER0_MIXER_SRC_STRUCT0->unSRC_FIFO_WR.stcField.u32DATA = 0x00000000; // all zeros elsewhere
            }
        }
     }
   
    Term_Printf("Activating FIFO's\n\r");
    Cy_Mixer_Src_Activate(MIXER0_MIXER_SRC_STRUCT0);
    Cy_Mixer_Src_Activate(MIXER0_MIXER_SRC_STRUCT1);
    Cy_Mixer_Dst_Activate(MIXER0_MIXER_DST_STRUCT);
    
    Term_Printf("Waiting for DST intr\n\r");
    while(MIXER0_MIXER_DST_STRUCT->unINTR_DST_MASKED.stcField.u1FIFO_TRIGGER); //(tb_mmio_read(MMIO_MIXER_CH_DST_INTR_DST)==0);  
    Term_Printf("DST intr received\n\r");
    
    for(i=0; i<64; i++) 
    {
       DST_DATA[i] = Cy_Mixer_Dst_FifoReadData(MIXER0_MIXER_DST_STRUCT);
       Term_Printf("DST_FIFO_RD:0x%-x\n\r",DST_DATA[i]);
    }
    for(;;);
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
    
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_2); // Enable clk_hf2

    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(CY_USB_SCB_UART_PCLK, CY_SYSCLK_DIV_24_5_BIT, 0u);

    /* Sets the 24.5 divider */
  #if (CY_USE_PSVP == 1)
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 25u,  1u);   // 115246
    g_stc_uart_config.oversample = 8;
  #else
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_USB_SCB_UART_PCLK), CY_SYSCLK_DIV_24_5_BIT, 0u, 85u, 26u); // Divider 86.8125 --> 80MHz / 86.8125 / 8 (oversampling) = 115190 Hz
    g_stc_uart_config.oversample = 8;
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
    while (Cy_SCB_UART_IsTxComplete(CY_USB_SCB_TYPE) != true) {};
    Cy_SCB_UART_PutArray(CY_USB_SCB_TYPE, g_uart_out_data, strlen((char *)g_uart_out_data));
    va_end(arg);
}
/* [] END OF FILE */
