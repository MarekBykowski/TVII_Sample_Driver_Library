/***************************************************************************//**
* \file bb_bsp_tvic2d6mddr.h
*
* \brief
* Project specific header
*
* \note
* It contains references to all generated header files and should
* not be modified.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef BB_BSP_TVIIC2D6MDDR_H
#define BB_BSP_TVIIC2D6MDDR_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/******************************************************************************/

// PSVP supports only 500-bga package

#if (CY_USE_PSVP == 1) && defined (TVIIC2D6MDDR)

// Adapter Board Entities

/******************************************************************************/
/*                      USER LED AB Mux (GPIO_133)                            */
/******************************************************************************/
// Not Assigned
#define CY_AB_LED_PORT                  GPIO_PRT8
#define CY_AB_LED_PIN                   1
#define CY_AB_LED_PIN_MUX               P8_1_GPIO

/******************************************************************************/
/*                      Button AB Mux (GPIO_134)                              */
/******************************************************************************/
// Not Assigned
#define CY_AB_BUTTON_PORT               GPIO_PRT7
#define CY_AB_BUTTON_PIN                1
#define CY_AB_BUTTON_PIN_MUX            P7_1_GPIO

/* Setup GPIO for BUTTON AB interrupt sources */
#define CY_AB_BUTTON_IRQN               ioss_interrupts_gpio_dpslp_7_IRQn

/******************************************************************************/
/*                      SCB AB Mux                                            */
/******************************************************************************/
/* USB-UART Mux */
#define CY_USB_SCB_TYPE                 SCB6
#define CY_USB_SCB_UART_RX_PORT         GPIO_PRT1
#define CY_USB_SCB_UART_RX_PIN          0
#define CY_USB_SCB_UART_RX_MUX          P1_0_SCB6_UART_RX
#define CY_USB_SCB_UART_TX_PORT         GPIO_PRT1
#define CY_USB_SCB_UART_TX_PIN          1
#define CY_USB_SCB_UART_TX_MUX          P1_1_SCB6_UART_TX
#define CY_USB_SCB_UART_PCLK            PCLK_SCB6_CLOCK
#define CY_USB_SCB_UART_IRQN            scb_6_interrupt_IRQn
  
/******************************************************************************/
/*                      SMIF0 Definitions                                     */
/******************************************************************************/
#define CY_BSP_HDR_SMIF0_AVAILABLE             // Definitions for this functionality are available

#define CY_SMIF_S25FXXXS                       (0u)
#define CY_SMIF_S25FXXXL                       (1u)

#define CY_SMIF0_CLK_PORT                      GPIO_PRT15
#define CY_SMIF0_CLK_PIN                       0
#define CY_SMIF0_CLK_PIN_MUX                   P15_0_SMIF0_SMIF0_SPIHB_CLK

#define CY_SMIF0_RWDS_PORT                     GPIO_PRT14
#define CY_SMIF0_RWDS_PIN                      4
#define CY_SMIF0_RWDS_PIN_MUX                  P14_4_SMIF0_SMIF0_SPIHB_RWDS

#define CY_SMIF0_SELECT0_PORT                  GPIO_PRT16
#define CY_SMIF0_SELECT0_PIN                   2
#define CY_SMIF0_SELECT0_PIN_MUX               P16_2_SMIF0_SMIF0_SPIHB_SELECT0

#define CY_SMIF0_SELECT1_PORT                  GPIO_PRT16
#define CY_SMIF0_SELECT1_PIN                   5
#define CY_SMIF0_SELECT1_PIN_MUX               P16_5_SMIF0_SMIF0_SPIHB_SELECT1

#define CY_SMIF0_DATA0_PORT                    GPIO_PRT16
#define CY_SMIF0_DATA0_PIN                     0
#define CY_SMIF0_DATA0_PIN_MUX                 P16_0_SMIF0_SMIF0_SPIHB_DATA0

#define CY_SMIF0_DATA1_PORT                    GPIO_PRT16
#define CY_SMIF0_DATA1_PIN                     3
#define CY_SMIF0_DATA1_PIN_MUX                 P16_3_SMIF0_SMIF0_SPIHB_DATA1

#define CY_SMIF0_DATA2_PORT                    GPIO_PRT14
#define CY_SMIF0_DATA2_PIN                     1
#define CY_SMIF0_DATA2_PIN_MUX                 P14_1_SMIF0_SMIF0_SPIHB_DATA2

#define CY_SMIF0_DATA3_PORT                    GPIO_PRT14
#define CY_SMIF0_DATA3_PIN                     2
#define CY_SMIF0_DATA3_PIN_MUX                 P14_2_SMIF0_SMIF0_SPIHB_DATA3

#define CY_SMIF0_DATA4_PORT                    GPIO_PRT14
#define CY_SMIF0_DATA4_PIN                     0
#define CY_SMIF0_DATA4_PIN_MUX                 P14_0_SMIF0_SMIF0_SPIHB_DATA4

#define CY_SMIF0_DATA5_PORT                    GPIO_PRT14
#define CY_SMIF0_DATA5_PIN                     3
#define CY_SMIF0_DATA5_PIN_MUX                 P14_3_SMIF0_SMIF0_SPIHB_DATA5

#define CY_SMIF0_DATA6_PORT                    GPIO_PRT16
#define CY_SMIF0_DATA6_PIN                     1
#define CY_SMIF0_DATA6_PIN_MUX                 P16_1_SMIF0_SMIF0_SPIHB_DATA6

#define CY_SMIF0_DATA7_PORT                    GPIO_PRT16
#define CY_SMIF0_DATA7_PIN                     4
#define CY_SMIF0_DATA7_PIN_MUX                 P16_4_SMIF0_SMIF0_SPIHB_DATA7

#define CY_SMIF0_QUAD_MEMORY                   CY_SMIF_S25FXXXS

// BB Board Entities

/******************************************************************************/
/*                      LEDs Base Board Mux                                   */
/******************************************************************************/
#define CY_LED0_PORT                    GPIO_PRT8
#define CY_LED0_PIN                     2
#define CY_LED0_PIN_MUX                 P8_2_GPIO

#define CY_LED1_PORT                    GPIO_PRT7
#define CY_LED1_PIN                     6
#define CY_LED1_PIN_MUX                 P7_6_GPIO

#define CY_LED2_PORT                    GPIO_PRT8
#define CY_LED2_PIN                     5
#define CY_LED2_PIN_MUX                 P8_5_GPIO

#define CY_LED3_PORT                    GPIO_PRT10
#define CY_LED3_PIN                     3
#define CY_LED3_PIN_MUX                 P10_3_GPIO
  
#define CY_LED4_PORT                    GPIO_PRT10
#define CY_LED4_PIN                     2
#define CY_LED4_PIN_MUX                 P10_2_GPIO
  
// Not Assigned
#define CY_LED5_PORT                    GPIO_PRT7
#define CY_LED5_PIN                     4
#define CY_LED5_PIN_MUX                 P7_4_GPIO
  
// Not Assigned
#define CY_LED6_PORT                    GPIO_PRT4
#define CY_LED6_PIN                     6
#define CY_LED6_PIN_MUX                 P4_6_GPIO
  
// Not Assigned
#define CY_LED7_PORT                    GPIO_PRT3
#define CY_LED7_PIN                     1
#define CY_LED7_PIN_MUX                 P3_1_GPIO
  
// Not Assigned
#define CY_LED8_PORT                    GPIO_PRT2
#define CY_LED8_PIN                     2
#define CY_LED8_PIN_MUX                 P2_2_GPIO

// Not Assigned
#define CY_LED9_PORT                    GPIO_PRT1
#define CY_LED9_PIN                     3
#define CY_LED9_PIN_MUX                 P1_3_GPIO

/******************************************************************************/
/*                      Buttons Base Board Mux                                */
/******************************************************************************/
#define CY_BUTTON1_PORT                 GPIO_PRT1
#define CY_BUTTON1_PIN                  5
#define CY_BUTTON1_PIN_MUX              P1_5_GPIO

#define CY_BUTTON2_PORT                 GPIO_PRT8
#define CY_BUTTON2_PIN                  1
#define CY_BUTTON2_PIN_MUX              P8_1_GPIO

#define CY_BUTTON3_PORT                 GPIO_PRT7
#define CY_BUTTON3_PIN                  5
#define CY_BUTTON3_PIN_MUX              P7_5_GPIO

#define CY_BUTTON4_PORT                 GPIO_PRT10
#define CY_BUTTON4_PIN                  1
#define CY_BUTTON4_PIN_MUX              P10_1_GPIO

#define CY_BUTTON5_PORT                 GPIO_PRT10
#define CY_BUTTON5_PIN                  0
#define CY_BUTTON5_PIN_MUX              P10_0_GPIO

/* Setup GPIO for BUTTONs 1/2/3/4/5 interrupt sources */
#define CY_BUTTON1_IRQN                 ioss_interrupts_gpio_dpslp_1_IRQn
#define CY_BUTTON2_IRQN                 ioss_interrupts_gpio_dpslp_8_IRQn
#define CY_BUTTON3_IRQN                 ioss_interrupts_gpio_dpslp_7_IRQn
#define CY_BUTTON4_IRQN                 ioss_interrupts_gpio_dpslp_10_IRQn
#define CY_BUTTON5_IRQN                 ioss_interrupts_gpio_dpslp_10_IRQn

/******************************************************************************/
/*                      ADC POT                                               */
/******************************************************************************/
// Not defined
#define CY_ADC_POT_MACRO                PASS0_SAR0
#define CY_ADC_CHANNEL_NO               1
#define CY_ADC_POT_PORT                 GPIO_PRT1
#define CY_ADC_POT_PIN                  4
#define CY_ADC_POT_PIN_MUX              P1_4_GPIO
#define CY_ADC_POT_PCLK                 PCLK_PASS0_CLOCK_SAR0
#define CY_ADC_POT_IRQN                 pass_0_interrupts_sar_0_IRQn  // This is logical channel, so it is not board specific

/******************************************************************************/
/*                      SCB Base Board Mux                                    */
/******************************************************************************/

/* CANFD-SPI Mux (BB_CAN_SPI) */


/* EEPROM SPI Mux (BB_SPI0) */


/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/
/* CAN0 Pin Mux */
#define CY_CANFD0_TYPE                  CY_CANFD1_0_TYPE
#define CY_CANFD0_RX_PORT               GPIO_PRT4
#define CY_CANFD0_RX_PIN                7
#define CY_CANFD0_RX_MUX                P4_7_CANFD1_TTCAN_RX0
#define CY_CANFD0_TX_PORT               GPIO_PRT4
#define CY_CANFD0_TX_PIN                6
#define CY_CANFD0_TX_MUX                P4_6_CANFD1_TTCAN_TX0
#define CY_CANFD0_PCLK                  PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD0_IRQN                  canfd_1_interrupts0_0_IRQn

// Not Assigned
/* CAN1 Pin Mux */
#define CY_CANFD1_TYPE                  CY_CANFD1_3_TYPE                   
#define CY_CANFD1_RX_PORT               GPIO_PRT15                         
#define CY_CANFD1_RX_PIN                1                                  
#define CY_CANFD1_RX_MUX                P15_1_CANFD1_TTCAN_RX3             
#define CY_CANFD1_TX_PORT               GPIO_PRT15                         
#define CY_CANFD1_TX_PIN                0                                  
#define CY_CANFD1_TX_MUX                P15_0_CANFD1_TTCAN_TX3             
#define CY_CANFD1_PCLK                  PCLK_CANFD1_CLOCK_CAN3             
#define CY_CANFD1_IRQN                  canfd_1_interrupts0_3_IRQn         

// Not Assigned
/* CAN2 Pin Mux */                                                        
#define CY_CANFD2_TYPE                  CY_CANFD0_2_TYPE                  
#define CY_CANFD2_RX_PORT               GPIO_PRT6                         
#define CY_CANFD2_RX_PIN                3                                 
#define CY_CANFD2_RX_MUX                P6_3_CANFD0_TTCAN_RX2             
#define CY_CANFD2_TX_PORT               GPIO_PRT12                        
#define CY_CANFD2_TX_PIN                0                                 
#define CY_CANFD2_TX_MUX                P12_0_CANFD0_TTCAN_TX2            
#define CY_CANFD2_PCLK                  PCLK_CANFD0_CLOCK_CAN2            
#define CY_CANFD2_IRQN                  canfd_0_interrupts0_2_IRQn        

// Not Assigned
/* CAN3 Pin Mux */                                                         
#define CY_CANFD3_TYPE                  CY_CANFD1_0_TYPE                   
#define CY_CANFD3_RX_PORT               GPIO_PRT23                         
#define CY_CANFD3_RX_PIN                1                                  
#define CY_CANFD3_RX_MUX                P23_1_CANFD1_TTCAN_RX0             
#define CY_CANFD3_TX_PORT               GPIO_PRT14                         
#define CY_CANFD3_TX_PIN                0                                  
#define CY_CANFD3_TX_MUX                P14_0_CANFD1_TTCAN_TX0             
#define CY_CANFD3_PCLK                  PCLK_CANFD1_CLOCK_CAN0             
#define CY_CANFD3_IRQN                  canfd_1_interrupts0_0_IRQn         

/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/
/* LIN Channel 0 */
#define CY_LINCH0_TYPE                  LIN0_CH1                            
#define CY_LINCH0_RX_PORT               GPIO_PRT5                           
#define CY_LINCH0_RX_PIN                2                                   
#define CY_LINCH0_RX_PIN_MUX            P5_2_LIN0_LIN_RX1                   
#define CY_LINCH0_TX_PORT               GPIO_PRT5
#define CY_LINCH0_TX_PIN                1                           
#define CY_LINCH0_TX_PIN_MUX            P5_1_LIN0_LIN_TX1                 
#define CY_LINCH0_PCLK                  PCLK_LIN0_CLOCK_CH_EN1              
#define CY_LINCH0_IRQN                  lin_0_interrupts_1_IRQn             

// Not Assigned
/* LIN Channel 1 */
#define CY_LINCH1_TYPE                  LIN0_CH6                            
#define CY_LINCH1_RX_PORT               GPIO_PRT12                          
#define CY_LINCH1_RX_PIN                2                                   
#define CY_LINCH1_RX_PIN_MUX            P12_2_LIN0_LIN_RX6                  
#define CY_LINCH1_TX_PORT               GPIO_PRT12                          
#define CY_LINCH1_TX_PIN                3                                   
#define CY_LINCH1_TX_PIN_MUX            P12_3_LIN0_LIN_TX6                  
#define CY_LINCH1_PCLK                  PCLK_LIN0_CLOCK_CH_EN6              
#define CY_LINCH1_IRQN                  lin_0_interrupts_6_IRQn

/******************************************************************************/
/*                      CXPI Definitions                                      */
/******************************************************************************/
/* CXPI0 Channel */
#define CY_CXPI0_TYPE                   CXPI0_CH0
  
#define CY_CXPI0_RX_PORT                GPIO_PRT1                        
#define CY_CXPI0_RX_PIN                 7
#define CY_CXPI0_RX_PIN_MUX             P1_7_CXPI0_CXPI_RX0
    
#define CY_CXPI0_TX_PORT                GPIO_PRT1                      
#define CY_CXPI0_TX_PIN                 6
#define CY_CXPI0_TX_PIN_MUX             P1_6_CXPI0_CXPI_TX0
    
#define CY_CXPI0_EN_PORT                GPIO_PRT2
#define CY_CXPI0_EN_PIN                 0
#define CY_CXPI0_EN_PIN_MUX             P2_0_CXPI0_CXPI_EN0
  
// to be checked while testing
#define CY_CXPI0_CLK_PORT               GPIO_PRT9                      
#define CY_CXPI0_CLK_PIN                5
#define CY_CXPI0_CLK_PIN_MUX            P9_5_TCPWM0_LINE24
#define CY_CXPI0_CLK_TCPWM_CNT          TCPWM0_GRP0_CNT24
#define CY_CXPI0_CLK_TCPWM_PCLK         PCLK_TCPWM0_CLOCKS24

// to be checked while testing
#define CY_CXPI0_SEL_PORT               GPIO_PRT7                       
#define CY_CXPI0_SEL_PIN                5
#define CY_CXPI0_SEL_PIN_MUX            P7_5_GPIO
  
#define CY_CXPI0_PCLK                   PCLK_CXPI0_CLOCK_CH_EN0
#define CY_CXPI0_IRQN                   cxpi_0_interrupts_0_IRQn 

/******************************************************************************/
/*                      SMARTIO Base Board Mux                                */
/******************************************************************************/
#define CY_SMARTIO_MACRO                SMARTIO                           
#define CY_SMARTIO_PORT                 SMARTIO_PRT8
#define CY_SMARTIO_CLK                  PCLK_SMARTIO8_CLOCK               

#define CY_SMARTIO_OUT_PORT             GPIO_PRT8                        
#define CY_SMARTIO_OUT_PIN              2                         
#define CY_SMARTIO_OUT_PORT_MUX         P8_2_GPIO                        

#define CY_SMARTIO_IN_PORT              GPIO_PRT8                        
#define CY_SMARTIO_IN_PIN               1                                 
#define CY_SMARTIO_IN_PORT_MUX          P8_1_GPIO        
#define CY_SMARTIO_IN_PORT_MUX_PWM      P8_1_TCPWM0_LINE532

#define CY_SMARTIO_IN2_PORT             GPIO_PRT8
#define CY_SMARTIO_IN2_PIN              3
#define CY_SMARTIO_IN2_PORT_MUX         P8_3_GPIO
#define CY_SMARTIO_IN2_PORT_MUX_PWM     P8_3_TCPWM0_LINE533

/* PWM PR Mode Configuration def */
#define CY_SMARTIO_TCPWM_GRP0_CNT       TCPWM0_GRP2_CNT21
#define CY_SMARTIO_TCPWM_PCLK           PCLK_TCPWM0_CLOCKS532

#define CY_SMARTIO_TCPWM_GRP0_CNT2      TCPWM0_GRP2_CNT22
#define CY_SMARTIO_TCPWM_PCLK2          PCLK_TCPWM0_CLOCKS533


// Cluster Extension Board entities

/******************************************************************************/
/*                      USER LED CEB Mux (GPIO_202)                           */
/******************************************************************************/
// Not Assigned
#define CY_CEB_LED_PORT                 GPIO_PRT13                          
#define CY_CEB_LED_PIN                  4                                   
#define CY_CEB_LED_PIN_MUX              P13_4_GPIO                          

/******************************************************************************/
/*                      Button CEB Mux (GPIO_201)                             */
/******************************************************************************/
// Not Assigned
#define CY_CEB_BUTTON_PORT              GPIO_PRT13                          
#define CY_CEB_BUTTON_PIN               1                                   
#define CY_CEB_BUTTON_PIN_MUX           P13_1_GPIO                          

#define CY_CEB_BUTTON_IRQN              ioss_interrupts_gpio_dpslp_13_IRQn  

/******************************************************************************/
/*                      SMIF1 Definitions                                     */
/******************************************************************************/
#define CY_BSP_HDR_SMIF1_AVAILABLE      // Definitions for this functionality are available

#define CY_SMIF1_CLK_PORT               GPIO_PRT18
#define CY_SMIF1_CLK_PIN                0
#define CY_SMIF1_CLK_PIN_MUX            P18_0_SMIF0_SMIF1_SPIHB_CLK

#define CY_SMIF1_RWDS_PORT              GPIO_PRT17
#define CY_SMIF1_RWDS_PIN               4
#define CY_SMIF1_RWDS_PIN_MUX           P17_4_SMIF0_SMIF1_SPIHB_RWDS

#define CY_SMIF1_SELECT0_PORT           GPIO_PRT19
#define CY_SMIF1_SELECT0_PIN            2
#define CY_SMIF1_SELECT0_PIN_MUX        P19_2_SMIF0_SMIF1_SPIHB_SELECT0

#define CY_SMIF1_SELECT1_PORT           GPIO_PRT19
#define CY_SMIF1_SELECT1_PIN            5
#define CY_SMIF1_SELECT1_PIN_MUX        P19_5_SMIF0_SMIF1_SPIHB_SELECT1

#define CY_SMIF1_DATA0_PORT             GPIO_PRT19
#define CY_SMIF1_DATA0_PIN              0
#define CY_SMIF1_DATA0_PIN_MUX          P19_0_SMIF0_SMIF1_SPIHB_DATA0

#define CY_SMIF1_DATA1_PORT             GPIO_PRT19
#define CY_SMIF1_DATA1_PIN              3
#define CY_SMIF1_DATA1_PIN_MUX          P19_3_SMIF0_SMIF1_SPIHB_DATA1

#define CY_SMIF1_DATA2_PORT             GPIO_PRT17
#define CY_SMIF1_DATA2_PIN              1
#define CY_SMIF1_DATA2_PIN_MUX          P17_1_SMIF0_SMIF1_SPIHB_DATA2

#define CY_SMIF1_DATA3_PORT             GPIO_PRT17
#define CY_SMIF1_DATA3_PIN              2
#define CY_SMIF1_DATA3_PIN_MUX          P17_2_SMIF0_SMIF1_SPIHB_DATA3

#define CY_SMIF1_DATA4_PORT             GPIO_PRT17
#define CY_SMIF1_DATA4_PIN              0
#define CY_SMIF1_DATA4_PIN_MUX          P17_0_SMIF0_SMIF1_SPIHB_DATA4

#define CY_SMIF1_DATA5_PORT             GPIO_PRT17
#define CY_SMIF1_DATA5_PIN              3
#define CY_SMIF1_DATA5_PIN_MUX          P17_3_SMIF0_SMIF1_SPIHB_DATA5

#define CY_SMIF1_DATA6_PORT             GPIO_PRT19
#define CY_SMIF1_DATA6_PIN              1
#define CY_SMIF1_DATA6_PIN_MUX          P19_1_SMIF0_SMIF1_SPIHB_DATA6

#define CY_SMIF1_DATA7_PORT             GPIO_PRT19
#define CY_SMIF1_DATA7_PIN              4
#define CY_SMIF1_DATA7_PIN_MUX          P19_4_SMIF0_SMIF1_SPIHB_DATA7

#define CY_SMIF1_QUAD_MEMORY            CY_SMIF_S25FXXXS

/******************************************************************************/
/*                      Display #0 Definitions                                */
/******************************************************************************/
// Not available 
// #define CY_BSP_HDR_DISP0_TTL_AVAILABLE               // Definitions for this functionality are available
  
/******************************************************************************/
/*                 Backlight Display #0 Definitions                           */
/******************************************************************************/
// #define CY_BL_DISP0_EN_PORT          GPIO_PRT?      // only jumper, not SW controllable
// #define CY_BL_DISP0_EN_PIN           ?              // only jumper, not SW controllable
// #define CY_BL_DISP0_EN_PIN_MUX       P?_?_GPIO      // only jumper, not SW controllable

#define CY_BL_DISP0_PWM_PORT            GPIO_PRT5                                             
#define CY_BL_DISP0_PWM_PIN             0                                                      
#define CY_BL_DISP0_PWM_PIN_MUX         P5_0_GPIO       // use as GPIO for now (0% or 100% PWM)  TP347   

/******************************************************************************/
/*                      Display #0 Control Definitions                        */
/******************************************************************************/

#define CY_DISP0_CLK_PORT               GPIO_PRT8
#define CY_DISP0_CLK_PIN                3
#define CY_DISP0_CLK_PIN_MUX            P8_3_VIDEOSS0_TTL_DSP0_CLOCK
  
#define CY_DISP0_CTRL0_PORT             GPIO_PRT8
#define CY_DISP0_CTRL0_PIN              0
#define CY_DISP0_CTRL0_PIN_MUX          P8_0_VIDEOSS0_TTL_DSP0_CONTROL0

#define CY_DISP0_CTRL1_PORT             GPIO_PRT8
#define CY_DISP0_CTRL1_PIN              1
#define CY_DISP0_CTRL1_PIN_MUX          P8_1_VIDEOSS0_TTL_DSP0_CONTROL1

#define CY_DISP0_CTRL2_PORT             GPIO_PRT8
#define CY_DISP0_CTRL2_PIN              2
#define CY_DISP0_CTRL2_PIN_MUX          P8_2_VIDEOSS0_TTL_DSP0_CONTROL2

#define CY_DISP0_DATA_A0_0_PORT         GPIO_PRT12
#define CY_DISP0_DATA_A0_0_PIN          2
#define CY_DISP0_DATA_A0_0_PIN_MUX      P12_2_VIDEOSS0_TTL_DSP0_DATA_A00

#define CY_DISP0_DATA_A0_1_PORT         GPIO_PRT12
#define CY_DISP0_DATA_A0_1_PIN          4
#define CY_DISP0_DATA_A0_1_PIN_MUX      P12_4_VIDEOSS0_TTL_DSP0_DATA_A01

#define CY_DISP0_DATA_A0_2_PORT         GPIO_PRT12
#define CY_DISP0_DATA_A0_2_PIN          6
#define CY_DISP0_DATA_A0_2_PIN_MUX      P12_6_VIDEOSS0_TTL_DSP0_DATA_A02

#define CY_DISP0_DATA_A0_3_PORT         GPIO_PRT5
#define CY_DISP0_DATA_A0_3_PIN          0
#define CY_DISP0_DATA_A0_3_PIN_MUX      P5_0_VIDEOSS0_TTL_DSP0_DATA_A03

#define CY_DISP0_DATA_A0_4_PORT         GPIO_PRT5
#define CY_DISP0_DATA_A0_4_PIN          2
#define CY_DISP0_DATA_A0_4_PIN_MUX      P5_2_VIDEOSS0_TTL_DSP0_DATA_A04

#define CY_DISP0_DATA_A0_5_PORT         GPIO_PRT5
#define CY_DISP0_DATA_A0_5_PIN          4
#define CY_DISP0_DATA_A0_5_PIN_MUX      P5_4_VIDEOSS0_TTL_DSP0_DATA_A05

#define CY_DISP0_DATA_A0_6_PORT         GPIO_PRT5
#define CY_DISP0_DATA_A0_6_PIN          6
#define CY_DISP0_DATA_A0_6_PIN_MUX      P5_6_VIDEOSS0_TTL_DSP0_DATA_A06

#define CY_DISP0_DATA_A0_7_PORT         GPIO_PRT6
#define CY_DISP0_DATA_A0_7_PIN          0
#define CY_DISP0_DATA_A0_7_PIN_MUX      P6_0_VIDEOSS0_TTL_DSP0_DATA_A07

#define CY_DISP0_DATA_A0_8_PORT         GPIO_PRT6
#define CY_DISP0_DATA_A0_8_PIN          2
#define CY_DISP0_DATA_A0_8_PIN_MUX      P6_2_VIDEOSS0_TTL_DSP0_DATA_A08

#define CY_DISP0_DATA_A0_9_PORT         GPIO_PRT6
#define CY_DISP0_DATA_A0_9_PIN          4
#define CY_DISP0_DATA_A0_9_PIN_MUX      P6_4_VIDEOSS0_TTL_DSP0_DATA_A09

#define CY_DISP0_DATA_A0_10_PORT        GPIO_PRT6
#define CY_DISP0_DATA_A0_10_PIN         6
#define CY_DISP0_DATA_A0_10_PIN_MUX     P6_6_VIDEOSS0_TTL_DSP0_DATA_A010

#define CY_DISP0_DATA_A0_11_PORT        GPIO_PRT7
#define CY_DISP0_DATA_A0_11_PIN         0
#define CY_DISP0_DATA_A0_11_PIN_MUX     P7_0_VIDEOSS0_TTL_DSP0_DATA_A011

#define CY_DISP0_DATA_A1_0_PORT         GPIO_PRT12
#define CY_DISP0_DATA_A1_0_PIN          3
#define CY_DISP0_DATA_A1_0_PIN_MUX      P12_3_VIDEOSS0_TTL_DSP0_DATA_A10

#define CY_DISP0_DATA_A1_1_PORT         GPIO_PRT12
#define CY_DISP0_DATA_A1_1_PIN          5
#define CY_DISP0_DATA_A1_1_PIN_MUX      P12_5_VIDEOSS0_TTL_DSP0_DATA_A11

#define CY_DISP0_DATA_A1_2_PORT         GPIO_PRT12
#define CY_DISP0_DATA_A1_2_PIN          7
#define CY_DISP0_DATA_A1_2_PIN_MUX      P12_7_VIDEOSS0_TTL_DSP0_DATA_A12

#define CY_DISP0_DATA_A1_3_PORT         GPIO_PRT5
#define CY_DISP0_DATA_A1_3_PIN          1
#define CY_DISP0_DATA_A1_3_PIN_MUX      P5_1_VIDEOSS0_TTL_DSP0_DATA_A13

#define CY_DISP0_DATA_A1_4_PORT         GPIO_PRT5
#define CY_DISP0_DATA_A1_4_PIN          3
#define CY_DISP0_DATA_A1_4_PIN_MUX      P5_3_VIDEOSS0_TTL_DSP0_DATA_A14

#define CY_DISP0_DATA_A1_5_PORT         GPIO_PRT5
#define CY_DISP0_DATA_A1_5_PIN          5
#define CY_DISP0_DATA_A1_5_PIN_MUX      P5_5_VIDEOSS0_TTL_DSP0_DATA_A15

#define CY_DISP0_DATA_A1_6_PORT         GPIO_PRT5
#define CY_DISP0_DATA_A1_6_PIN          7
#define CY_DISP0_DATA_A1_6_PIN_MUX      P5_7_VIDEOSS0_TTL_DSP0_DATA_A16

#define CY_DISP0_DATA_A1_7_PORT         GPIO_PRT6
#define CY_DISP0_DATA_A1_7_PIN          1
#define CY_DISP0_DATA_A1_7_PIN_MUX      P6_1_VIDEOSS0_TTL_DSP0_DATA_A17

#define CY_DISP0_DATA_A1_8_PORT         GPIO_PRT6
#define CY_DISP0_DATA_A1_8_PIN          3
#define CY_DISP0_DATA_A1_8_PIN_MUX      P6_3_VIDEOSS0_TTL_DSP0_DATA_A18

#define CY_DISP0_DATA_A1_9_PORT         GPIO_PRT6
#define CY_DISP0_DATA_A1_9_PIN          5
#define CY_DISP0_DATA_A1_9_PIN_MUX      P6_5_VIDEOSS0_TTL_DSP0_DATA_A19

#define CY_DISP0_DATA_A1_10_PORT        GPIO_PRT6
#define CY_DISP0_DATA_A1_10_PIN         7
#define CY_DISP0_DATA_A1_10_PIN_MUX     P6_7_VIDEOSS0_TTL_DSP0_DATA_A110

#define CY_DISP0_DATA_A1_11_PORT        GPIO_PRT29
#define CY_DISP0_DATA_A1_11_PIN         1
#define CY_DISP0_DATA_A1_11_PIN_MUX     P29_1_VIDEOSS0_TTL_DSP0_DATA_A111

/******************************************************************************/
/*                      Display #1 Definitions                                */
/******************************************************************************/
#define CY_BSP_HDR_DISP1_TTL_AVAILABLE  // Definitions for this functionality are available

/******************************************************************************/
/*                 Backlight Display #1 Definitions                           */
/******************************************************************************/
// #define CY_BL_DISP1_EN_PORT          GPIO_PRT?      // only jumper, not SW controllable
// #define CY_BL_DISP1_EN_PIN           ?              // only jumper, not SW controllable
// #define CY_BL_DISP1_EN_PIN_MUX       P?_?_GPIO      // only jumper, not SW controllable

#define CY_BL_DISP1_PWM_PORT            GPIO_PRT7  
#define CY_BL_DISP1_PWM_PIN             3   
#define CY_BL_DISP1_PWM_PIN_MUX         P7_3_GPIO 

/******************************************************************************/
/*                      Display #1 Control Definitions                        */
/******************************************************************************/
#define CY_DISP1_CLK_PORT               GPIO_PRT12
#define CY_DISP1_CLK_PIN                6
#define CY_DISP1_CLK_PIN_MUX            P12_6_VIDEOSS0_TTL_DSP1_CLOCK
  
#define CY_DISP1_CTRL0_PORT             GPIO_PRT12
#define CY_DISP1_CTRL0_PIN              7
#define CY_DISP1_CTRL0_PIN_MUX          P12_7_VIDEOSS0_TTL_DSP1_CONTROL0

#define CY_DISP1_CTRL1_PORT             GPIO_PRT13
#define CY_DISP1_CTRL1_PIN              0
#define CY_DISP1_CTRL1_PIN_MUX          P13_0_VIDEOSS0_TTL_DSP1_CONTROL1

#define CY_DISP1_CTRL2_PORT             GPIO_PRT13
#define CY_DISP1_CTRL2_PIN              1
#define CY_DISP1_CTRL2_PIN_MUX          P13_1_VIDEOSS0_TTL_DSP1_CONTROL2

#define CY_DISP1_DATA_A0_0_PORT         GPIO_PRT12
#define CY_DISP1_DATA_A0_0_PIN          5
#define CY_DISP1_DATA_A0_0_PIN_MUX      P12_5_VIDEOSS0_TTL_DSP1_DATA_A00

#define CY_DISP1_DATA_A0_1_PORT         GPIO_PRT12
#define CY_DISP1_DATA_A0_1_PIN          3
#define CY_DISP1_DATA_A0_1_PIN_MUX      P12_3_VIDEOSS0_TTL_DSP1_DATA_A01

#define CY_DISP1_DATA_A0_2_PORT         GPIO_PRT12
#define CY_DISP1_DATA_A0_2_PIN          1
#define CY_DISP1_DATA_A0_2_PIN_MUX      P12_1_VIDEOSS0_TTL_DSP1_DATA_A02

#define CY_DISP1_DATA_A0_3_PORT         GPIO_PRT11
#define CY_DISP1_DATA_A0_3_PIN          7
#define CY_DISP1_DATA_A0_3_PIN_MUX      P11_7_VIDEOSS0_TTL_DSP1_DATA_A03

#define CY_DISP1_DATA_A0_4_PORT         GPIO_PRT11
#define CY_DISP1_DATA_A0_4_PIN          5
#define CY_DISP1_DATA_A0_4_PIN_MUX      P11_5_VIDEOSS0_TTL_DSP1_DATA_A04

#define CY_DISP1_DATA_A0_5_PORT         GPIO_PRT11
#define CY_DISP1_DATA_A0_5_PIN          3
#define CY_DISP1_DATA_A0_5_PIN_MUX      P11_3_VIDEOSS0_TTL_DSP1_DATA_A05

#define CY_DISP1_DATA_A0_6_PORT         GPIO_PRT11
#define CY_DISP1_DATA_A0_6_PIN          1
#define CY_DISP1_DATA_A0_6_PIN_MUX      P11_1_VIDEOSS0_TTL_DSP1_DATA_A06

#define CY_DISP1_DATA_A0_7_PORT         GPIO_PRT10
#define CY_DISP1_DATA_A0_7_PIN          6
#define CY_DISP1_DATA_A0_7_PIN_MUX      P10_6_VIDEOSS0_TTL_DSP1_DATA_A07

#define CY_DISP1_DATA_A0_8_PORT         GPIO_PRT10
#define CY_DISP1_DATA_A0_8_PIN          4
#define CY_DISP1_DATA_A0_8_PIN_MUX      P10_4_VIDEOSS0_TTL_DSP1_DATA_A08

#define CY_DISP1_DATA_A0_9_PORT         GPIO_PRT9
#define CY_DISP1_DATA_A0_9_PIN          5
#define CY_DISP1_DATA_A0_9_PIN_MUX      P9_5_VIDEOSS0_TTL_DSP1_DATA_A09

#define CY_DISP1_DATA_A0_10_PORT        GPIO_PRT9
#define CY_DISP1_DATA_A0_10_PIN         3
#define CY_DISP1_DATA_A0_10_PIN_MUX     P9_3_VIDEOSS0_TTL_DSP1_DATA_A010

#define CY_DISP1_DATA_A0_11_PORT        GPIO_PRT9
#define CY_DISP1_DATA_A0_11_PIN         1
#define CY_DISP1_DATA_A0_11_PIN_MUX     P9_1_VIDEOSS0_TTL_DSP1_DATA_A011

#define CY_DISP1_DATA_A1_0_PORT         GPIO_PRT12
#define CY_DISP1_DATA_A1_0_PIN          4
#define CY_DISP1_DATA_A1_0_PIN_MUX      P12_4_VIDEOSS0_TTL_DSP1_DATA_A10

#define CY_DISP1_DATA_A1_1_PORT         GPIO_PRT12
#define CY_DISP1_DATA_A1_1_PIN          2
#define CY_DISP1_DATA_A1_1_PIN_MUX      P12_2_VIDEOSS0_TTL_DSP1_DATA_A11

#define CY_DISP1_DATA_A1_2_PORT         GPIO_PRT12
#define CY_DISP1_DATA_A1_2_PIN          0
#define CY_DISP1_DATA_A1_2_PIN_MUX      P12_0_VIDEOSS0_TTL_DSP1_DATA_A12

#define CY_DISP1_DATA_A1_3_PORT         GPIO_PRT11
#define CY_DISP1_DATA_A1_3_PIN          6
#define CY_DISP1_DATA_A1_3_PIN_MUX      P11_6_VIDEOSS0_TTL_DSP1_DATA_A13

#define CY_DISP1_DATA_A1_4_PORT         GPIO_PRT11
#define CY_DISP1_DATA_A1_4_PIN          4
#define CY_DISP1_DATA_A1_4_PIN_MUX      P11_4_VIDEOSS0_TTL_DSP1_DATA_A14

#define CY_DISP1_DATA_A1_5_PORT         GPIO_PRT11
#define CY_DISP1_DATA_A1_5_PIN          2
#define CY_DISP1_DATA_A1_5_PIN_MUX      P11_2_VIDEOSS0_TTL_DSP1_DATA_A15

#define CY_DISP1_DATA_A1_6_PORT         GPIO_PRT11
#define CY_DISP1_DATA_A1_6_PIN          0
#define CY_DISP1_DATA_A1_6_PIN_MUX      P11_0_VIDEOSS0_TTL_DSP1_DATA_A16

#define CY_DISP1_DATA_A1_7_PORT         GPIO_PRT10
#define CY_DISP1_DATA_A1_7_PIN          5
#define CY_DISP1_DATA_A1_7_PIN_MUX      P10_5_VIDEOSS0_TTL_DSP1_DATA_A17

#define CY_DISP1_DATA_A1_8_PORT         GPIO_PRT9
#define CY_DISP1_DATA_A1_8_PIN          6
#define CY_DISP1_DATA_A1_8_PIN_MUX      P9_6_VIDEOSS0_TTL_DSP1_DATA_A18

#define CY_DISP1_DATA_A1_9_PORT         GPIO_PRT9
#define CY_DISP1_DATA_A1_9_PIN          4
#define CY_DISP1_DATA_A1_9_PIN_MUX      P9_4_VIDEOSS0_TTL_DSP1_DATA_A19

#define CY_DISP1_DATA_A1_10_PORT        GPIO_PRT9
#define CY_DISP1_DATA_A1_10_PIN         2
#define CY_DISP1_DATA_A1_10_PIN_MUX     P9_2_VIDEOSS0_TTL_DSP1_DATA_A110

#define CY_DISP1_DATA_A1_11_PORT        GPIO_PRT9
#define CY_DISP1_DATA_A1_11_PIN         0
#define CY_DISP1_DATA_A1_11_PIN_MUX     P9_0_VIDEOSS0_TTL_DSP1_DATA_A111

/******************************************************************************/
/*                      Capture #0 Definitions                                */
/******************************************************************************/
// Not available in PSVP
// #define CY_BSP_HDR_CAP0_TTL_AVAILABLE        // Definitions for this functionality are available

#define CY_CAP0_CLK_PORT                GPIO_PRT15
#define CY_CAP0_CLK_PIN                 6
#define CY_CAP0_CLK_PIN_MUX             P15_6_VIDEOSS0_TTL_CAP0_CLK

#define CY_CAP0_DATA0_PORT              GPIO_PRT15
#define CY_CAP0_DATA0_PIN               7
#define CY_CAP0_DATA0_PIN_MUX           P15_7_VIDEOSS0_TTL_CAP0_DATA0

#define CY_CAP0_DATA1_PORT              GPIO_PRT16
#define CY_CAP0_DATA1_PIN               0
#define CY_CAP0_DATA1_PIN_MUX           P16_0_VIDEOSS0_TTL_CAP0_DATA1

#define CY_CAP0_DATA2_PORT              GPIO_PRT16
#define CY_CAP0_DATA2_PIN               1
#define CY_CAP0_DATA2_PIN_MUX           P16_1_VIDEOSS0_TTL_CAP0_DATA2

#define CY_CAP0_DATA3_PORT              GPIO_PRT16
#define CY_CAP0_DATA3_PIN               2
#define CY_CAP0_DATA3_PIN_MUX           P16_2_VIDEOSS0_TTL_CAP0_DATA3

#define CY_CAP0_DATA4_PORT              GPIO_PRT16
#define CY_CAP0_DATA4_PIN               3
#define CY_CAP0_DATA4_PIN_MUX           P16_3_VIDEOSS0_TTL_CAP0_DATA4

#define CY_CAP0_DATA5_PORT              GPIO_PRT16
#define CY_CAP0_DATA5_PIN               4
#define CY_CAP0_DATA5_PIN_MUX           P16_4_VIDEOSS0_TTL_CAP0_DATA5

#define CY_CAP0_DATA6_PORT              GPIO_PRT16
#define CY_CAP0_DATA6_PIN               5
#define CY_CAP0_DATA6_PIN_MUX           P16_5_VIDEOSS0_TTL_CAP0_DATA6

#define CY_CAP0_DATA7_PORT              GPIO_PRT16
#define CY_CAP0_DATA7_PIN               6
#define CY_CAP0_DATA7_PIN_MUX           P16_6_VIDEOSS0_TTL_CAP0_DATA7

#define CY_CAP0_DATA8_PORT              GPIO_PRT9
#define CY_CAP0_DATA8_PIN               0
#define CY_CAP0_DATA8_PIN_MUX           P9_0_VIDEOSS0_TTL_CAP0_DATA8

#define CY_CAP0_DATA9_PORT              GPIO_PRT9
#define CY_CAP0_DATA9_PIN               1
#define CY_CAP0_DATA9_PIN_MUX           P9_1_VIDEOSS0_TTL_CAP0_DATA9

#define CY_CAP0_DATA10_PORT             GPIO_PRT9
#define CY_CAP0_DATA10_PIN              2
#define CY_CAP0_DATA10_PIN_MUX          P9_2_VIDEOSS0_TTL_CAP0_DATA10

#define CY_CAP0_DATA11_PORT             GPIO_PRT9
#define CY_CAP0_DATA11_PIN              3
#define CY_CAP0_DATA11_PIN_MUX          P9_3_VIDEOSS0_TTL_CAP0_DATA11

#define CY_CAP0_DATA12_PORT             GPIO_PRT9
#define CY_CAP0_DATA12_PIN              4
#define CY_CAP0_DATA12_PIN_MUX          P9_4_VIDEOSS0_TTL_CAP0_DATA12

#define CY_CAP0_DATA13_PORT             GPIO_PRT9
#define CY_CAP0_DATA13_PIN              5
#define CY_CAP0_DATA13_PIN_MUX          P9_5_VIDEOSS0_TTL_CAP0_DATA13

#define CY_CAP0_DATA14_PORT             GPIO_PRT9
#define CY_CAP0_DATA14_PIN              6
#define CY_CAP0_DATA14_PIN_MUX          P9_6_VIDEOSS0_TTL_CAP0_DATA14

#define CY_CAP0_DATA15_PORT             GPIO_PRT9
#define CY_CAP0_DATA15_PIN              7
#define CY_CAP0_DATA15_PIN_MUX          P9_7_VIDEOSS0_TTL_CAP0_DATA15

#define CY_CAP0_DATA16_PORT             GPIO_PRT10
#define CY_CAP0_DATA16_PIN              0
#define CY_CAP0_DATA16_PIN_MUX          P10_0_VIDEOSS0_TTL_CAP0_DATA16

#define CY_CAP0_DATA17_PORT             GPIO_PRT10
#define CY_CAP0_DATA17_PIN              1
#define CY_CAP0_DATA17_PIN_MUX          P10_1_VIDEOSS0_TTL_CAP0_DATA17

#define CY_CAP0_DATA18_PORT             GPIO_PRT11
#define CY_CAP0_DATA18_PIN              0
#define CY_CAP0_DATA18_PIN_MUX          P11_0_VIDEOSS0_TTL_CAP0_DATA18

#define CY_CAP0_DATA19_PORT             GPIO_PRT11
#define CY_CAP0_DATA19_PIN              1
#define CY_CAP0_DATA19_PIN_MUX          P11_1_VIDEOSS0_TTL_CAP0_DATA19

#define CY_CAP0_DATA20_PORT             GPIO_PRT11
#define CY_CAP0_DATA20_PIN              2
#define CY_CAP0_DATA20_PIN_MUX          P11_2_VIDEOSS0_TTL_CAP0_DATA20

#define CY_CAP0_DATA21_PORT             GPIO_PRT11
#define CY_CAP0_DATA21_PIN              3
#define CY_CAP0_DATA21_PIN_MUX          P11_3_VIDEOSS0_TTL_CAP0_DATA21

#define CY_CAP0_DATA22_PORT             GPIO_PRT11
#define CY_CAP0_DATA22_PIN              4
#define CY_CAP0_DATA22_PIN_MUX          P11_4_VIDEOSS0_TTL_CAP0_DATA22

#define CY_CAP0_DATA23_PORT             GPIO_PRT11
#define CY_CAP0_DATA23_PIN              5
#define CY_CAP0_DATA23_PIN_MUX          P11_5_VIDEOSS0_TTL_CAP0_DATA23

#define CY_CAP0_DATA24_PORT             GPIO_PRT11
#define CY_CAP0_DATA24_PIN              6
#define CY_CAP0_DATA24_PIN_MUX          P11_6_VIDEOSS0_TTL_CAP0_DATA24

#define CY_CAP0_DATA25_PORT             GPIO_PRT11
#define CY_CAP0_DATA25_PIN              7
#define CY_CAP0_DATA25_PIN_MUX          P11_7_VIDEOSS0_TTL_CAP0_DATA25

#define CY_CAP0_DATA26_PORT             GPIO_PRT12
#define CY_CAP0_DATA26_PIN              0
#define CY_CAP0_DATA26_PIN_MUX          P12_0_VIDEOSS0_TTL_CAP0_DATA26

/******************************************************************************/
/*                      MIPI CSI-2 Definitions                                */
/******************************************************************************/
// MIPI CONFIGURATION is UNTESTED on PSVP, user should not use them.
// No need to configure MIPI CSI io mux, it is a part of AMUXBUS.

// Not available in PSVP
  
/* MIPI IO Clock */
#define CY_MIPI_CSI_IO_CLK_PORT         GPIO_PRT15
#define CY_MIPI_CSI_IO_CLK_PIN          5
#define CY_MIPI_CSI_IO_CLK_PIN_MUX      P15_5_GPIO

/* MIPI Power Enable */
#define CY_MIPI_CSI_PWDN_PORT           GPIO_PRT17
#define CY_MIPI_CSI_PWDN_PIN            1
#define CY_MIPI_CSI_PWDN_PIN_MUX        P17_1_GPIO
  
/* MIPI CSI Communication Block */
#define CY_MIPI_CSI_I2C_TYPE            SCB0
  
#define CY_MIPI_CSI_I2C_SDA_PORT        GPIO_PRT3
#define CY_MIPI_CSI_I2C_SDA_PIN         0
#define CY_MIPI_CSI_I2C_SDA_PIN_MUX     P3_0_SCB0_I2C_SDA //rmkn: temp
  
#define CY_MIPI_CSI_I2C_SCL_PORT        GPIO_PRT3
#define CY_MIPI_CSI_I2C_SCL_PIN         1
#define CY_MIPI_CSI_I2C_SCL_PIN_MUX     P3_1_SCB0_I2C_SCL //rmkn: temp
  
#define CY_MIPI_CSI_I2C_PCLK            PCLK_SCB0_CLOCK
#define CY_MIPI_CSI_I2C_IRQN            scb_0_interrupt_IRQn

/******************************************************************************/
/*                      AUDIOSS PCM-PWM                                       */
/******************************************************************************/
#define CY_AUDIOSS_PWM_TYPE             PWM0_TX1
  
#define CY_AUDIOSS_PWM0_L1P1_PORT       GPIO_PRT12
#define CY_AUDIOSS_PWM0_L1P1_PIN        6
#define CY_AUDIOSS_PWM0_L1P1_PIN_MUX    P12_6_PWM0_PWM_LINE1_P1
  
#define CY_AUDIOSS_PWM0_L1N1_PORT       GPIO_PRT12
#define CY_AUDIOSS_PWM0_L1N1_PIN        7
#define CY_AUDIOSS_PWM0_L1N1_PIN_MUX    P12_7_PWM0_PWM_LINE1_N1
    
#define CY_AUDIOSS_PWM0_L2P1_PORT       GPIO_PRT13
#define CY_AUDIOSS_PWM0_L2P1_PIN        0
#define CY_AUDIOSS_PWM0_L2P1_PIN_MUX    P13_0_PWM0_PWM_LINE2_P1
    
#define CY_AUDIOSS_PWM0_L2N1_PORT       GPIO_PRT13
#define CY_AUDIOSS_PWM0_L2N1_PIN        1
#define CY_AUDIOSS_PWM0_L2N1_PIN_MUX    P13_1_PWM0_PWM_LINE2_N1

#define CY_AUDIOSS_PWM0_IRQN            pwm_0_interrupts_1_IRQn
 
/******************************************************************************/
/*                      AUDIO-TDM Definitions                                 */
/******************************************************************************/
// By default on board Codec doesn't support TDM, so for testing TDM fly wire
// can be connected to the external Codec.

#define CY_AUDIOSS_TDM_TYPE                     TDM0_TDM_STRUCT3
  
#define CY_AUDIOSS_TDM0_TX_MCK_PORT             GPIO_PRT12
#define CY_AUDIOSS_TDM0_TX_MCK_PIN              6
#define CY_AUDIOSS_TDM0_TX_MCK_PIN_MUX          P12_6_TDM0_TDM_TX_MCK3
  
#define CY_AUDIOSS_TDM0_TX_SCK_PORT             GPIO_PRT12
#define CY_AUDIOSS_TDM0_TX_SCK_PIN              7
#define CY_AUDIOSS_TDM0_TX_SCK_PIN_MUX          P12_7_TDM0_TDM_TX_SCK3
  
#define CY_AUDIOSS_TDM0_TX_FSYNC_PORT           GPIO_PRT13
#define CY_AUDIOSS_TDM0_TX_FSYNC_PIN            0
#define CY_AUDIOSS_TDM0_TX_FSYNC_PIN_MUX        P13_0_TDM0_TDM_TX_FSYNC3
  
#define CY_AUDIOSS_TDM0_TX_SD_PORT              GPIO_PRT13
#define CY_AUDIOSS_TDM0_TX_SD_PIN               1
#define CY_AUDIOSS_TDM0_TX_SD_PIN_MUX           P13_1_TDM0_TDM_TX_SD3
  
#define CY_AUDIOSS_TDM0_RX_MCK_PORT             GPIO_PRT11
#define CY_AUDIOSS_TDM0_RX_MCK_PIN              2
#define CY_AUDIOSS_TDM0_RX_MCK_PIN_MUX          P11_2_TDM0_TDM_RX_MCK3
  
#define CY_AUDIOSS_TDM0_RX_SCK_PORT             GPIO_PRT11
#define CY_AUDIOSS_TDM0_RX_SCK_PIN              3
#define CY_AUDIOSS_TDM0_RX_SCK_PIN_MUX          P11_3_TDM0_TDM_RX_SCK3
  
#define CY_AUDIOSS_TDM0_RX_FSYNC_PORT           GPIO_PRT11
#define CY_AUDIOSS_TDM0_RX_FSYNC_PIN            4
#define CY_AUDIOSS_TDM0_RX_FSYNC_PIN_MUX        P11_4_TDM0_TDM_RX_FSYNC3
  
#define CY_AUDIOSS_TDM0_RX_SD_PORT              GPIO_PRT11
#define CY_AUDIOSS_TDM0_RX_SD_PIN               5
#define CY_AUDIOSS_TDM0_RX_SD_PIN_MUX           P11_5_TDM0_TDM_RX_SD3
  
#define CY_AUDIOSS_TDM0_TX_IRQN                 tdm_0_interrupts_tx_3_IRQn
#define CY_AUDIOSS_TDM0_RX_IRQN                 tdm_0_interrupts_rx_3_IRQn 

/* Audio Codec Communication Block */
#define CY_AUDIOSS_I2C_TYPE             SCB5
  
#define CY_AUDIOSS_I2C_SDA_PORT         GPIO_PRT7
#define CY_AUDIOSS_I2C_SDA_PIN          0
#define CY_AUDIOSS_I2C_SDA_PIN_MUX      P7_0_SCB5_I2C_SDA
  
#define CY_AUDIOSS_I2C_SCL_PORT         GPIO_PRT7
#define CY_AUDIOSS_I2C_SCL_PIN          1
#define CY_AUDIOSS_I2C_SCL_PIN_MUX      P7_1_SCB5_I2C_SCL
  
#define CY_AUDIOSS_I2C_PCLK             PCLK_SCB5_CLOCK
#define CY_AUDIOSS_I2C_IRQN             scb_5_interrupt_IRQn

/******************************************************************************/
/*                      AUDIO-SG Definitions                                  */
/******************************************************************************/
// Sound Generator driver circuit is not present on board, so for testing SG fly
// wire can be connected to the external driver circuit.

#define CY_AUDIOSS_SG0_TYPE             SG0_SG_STRUCT0
  
#define CY_AUDIOSS_SG0_AMPL_PORT        GPIO_PRT12
#define CY_AUDIOSS_SG0_AMPL_PIN         3
#define CY_AUDIOSS_SG0_AMPL_PIN_MUX     P12_3_SG0_SG_AMPL0
  
#define CY_AUDIOSS_SG0_TONE_PORT        GPIO_PRT12
#define CY_AUDIOSS_SG0_TONE_PIN         2
#define CY_AUDIOSS_SG0_TONE_PIN_MUX     P12_2_SG0_SG_TONE0
  
#define CY_AUDIOSS_SG0_IRQ_IRQN         sg_0_interrupts_0_IRQn

/******************************************************************************/
/*                      ETH Definitions                                       */
/******************************************************************************/
#define CY_GIG_ETH_TYPE                 ETH0
#define CY_GIG_ETH_INSTANCE_NUM         (0)
                                          
#define CY_GIG_ETH_TX_CLK_PORT          GPIO_PRT10
#define CY_GIG_ETH_TX_CLK_PIN           4
#define CY_GIG_ETH_TX_CLK_PIN_MUX       P10_4_ETH0_TX_CLK

#define CY_GIG_ETH_TX_CTL_PORT          GPIO_PRT10
#define CY_GIG_ETH_TX_CTL_PIN           7
#define CY_GIG_ETH_TX_CTL_PIN_MUX       P10_7_ETH0_TX_CTL

#define CY_GIG_ETH_TD0_PORT             GPIO_PRT10
#define CY_GIG_ETH_TD0_PIN              2
#define CY_GIG_ETH_TD0_PIN_MUX          P10_2_ETH0_TXD0

#define CY_GIG_ETH_TD1_PORT             GPIO_PRT10
#define CY_GIG_ETH_TD1_PIN              3
#define CY_GIG_ETH_TD1_PIN_MUX          P10_3_ETH0_TXD1

#define CY_GIG_ETH_TD2_PORT             GPIO_PRT10
#define CY_GIG_ETH_TD2_PIN              5
#define CY_GIG_ETH_TD2_PIN_MUX          P10_5_ETH0_TXD2

#define CY_GIG_ETH_TD3_PORT             GPIO_PRT10
#define CY_GIG_ETH_TD3_PIN              6
#define CY_GIG_ETH_TD3_PIN_MUX          P10_6_ETH0_TXD3

#define CY_GIG_ETH_TXER_PORT            GPIO_PRT11
#define CY_GIG_ETH_TXER_PIN             0
#define CY_GIG_ETH_TXER_PIN_MUX         P11_0_ETH0_TX_ER

#define CY_GIG_ETH_RX_CLK_PORT          GPIO_PRT9
#define CY_GIG_ETH_RX_CLK_PIN           4
#define CY_GIG_ETH_RX_CLK_PIN_MUX       P9_4_ETH0_RX_CLK

#define CY_GIG_ETH_RX_CTL_PORT          GPIO_PRT9
#define CY_GIG_ETH_RX_CTL_PIN           7
#define CY_GIG_ETH_RX_CTL_PIN_MUX       P9_7_ETH0_RX_CTL

#define CY_GIG_ETH_RD0_PORT             GPIO_PRT9
#define CY_GIG_ETH_RD0_PIN              2
#define CY_GIG_ETH_RD0_PIN_MUX          P9_2_ETH0_RXD0

#define CY_GIG_ETH_RD1_PORT             GPIO_PRT9
#define CY_GIG_ETH_RD1_PIN              3
#define CY_GIG_ETH_RD1_PIN_MUX          P9_3_ETH0_RXD1

#define CY_GIG_ETH_RD2_PORT             GPIO_PRT9
#define CY_GIG_ETH_RD2_PIN              5
#define CY_GIG_ETH_RD2_PIN_MUX          P9_5_ETH0_RXD2

#define CY_GIG_ETH_RD3_PORT             GPIO_PRT9
#define CY_GIG_ETH_RD3_PIN              6
#define CY_GIG_ETH_RD3_PIN_MUX          P9_6_ETH0_RXD3

#define CY_GIG_ETH_RX_ER_PORT           GPIO_PRT9
#define CY_GIG_ETH_RX_ER_PIN            1
#define CY_GIG_ETH_RX_ER_PIN_MUX        P9_1_ETH0_RX_ER

#define CY_GIG_ETH_MDC_PORT             GPIO_PRT10
#define CY_GIG_ETH_MDC_PIN              0
#define CY_GIG_ETH_MDC_PIN_MUX          P10_0_ETH0_MDC

#define CY_GIG_ETH_MDIO_PORT            GPIO_PRT10
#define CY_GIG_ETH_MDIO_PIN             1
#define CY_GIG_ETH_MDIO_PIN_MUX         P10_1_ETH0_MDIO

#define CY_GIG_ETH_REF_CLK_PORT         GPIO_PRT9
#define CY_GIG_ETH_REF_CLK_PIN          0
#define CY_GIG_ETH_REF_CLK_PIN_MUX      P9_0_ETH0_REF_CLK
  
/* Setup IRQ source for 0, 1 and 2 Priority Queue */
#define CY_GIG_ETH_IRQN0                eth_0_interrupt_eth_0_IRQn
#define CY_GIG_ETH_IRQN1                eth_0_interrupt_eth_1_IRQn
#define CY_GIG_ETH_IRQN2                eth_0_interrupt_eth_2_IRQn

/******************************************************************************/
/*                      SDHC Mux                                              */
/******************************************************************************/
// Not assigned as it is multiplexed with ETH/DSP lines
#define CY_SDHC_TYPE                    SDHC0

#define CY_SDHC_CLK_CARD_PORT           GPIO_PRT6
#define CY_SDHC_CLK_CARD_PIN            4
#define CY_SDHC_CLK_CARD_PIN_MUX        P6_4_SDHC0_CLK_CARD

#define CY_SDHC_CARD_CMD_PORT           GPIO_PRT6
#define CY_SDHC_CARD_CMD_PIN            3
#define CY_SDHC_CARD_CMD_PIN_MUX        P6_3_SDHC0_CARD_CMD

#define CY_SDHC_CARD_DETECT_N_PORT      GPIO_PRT6
#define CY_SDHC_CARD_DETECT_N_PIN       5
#define CY_SDHC_CARD_DETECT_N_PIN_MUX   P6_5_SDHC0_CARD_DETECT_N

#define CY_SDHC_CARD_DAT_3TO00_PORT     GPIO_PRT7
#define CY_SDHC_CARD_DAT_3TO00_PIN      1
#define CY_SDHC_CARD_DAT_3TO00_PIN_MUX  P7_1_SDHC0_CARD_DAT_3TO00  

#define CY_SDHC_CARD_DAT_3TO01_PORT     GPIO_PRT7
#define CY_SDHC_CARD_DAT_3TO01_PIN      2
#define CY_SDHC_CARD_DAT_3TO01_PIN_MUX  P7_2_SDHC0_CARD_DAT_3TO01

#define CY_SDHC_CARD_DAT_3TO02_PORT     GPIO_PRT7
#define CY_SDHC_CARD_DAT_3TO02_PIN      3
#define CY_SDHC_CARD_DAT_3TO02_PIN_MUX  P7_3_SDHC0_CARD_DAT_3TO02

#define CY_SDHC_CARD_DAT_3TO03_PORT     GPIO_PRT7
#define CY_SDHC_CARD_DAT_3TO03_PIN      4
#define CY_SDHC_CARD_DAT_3TO03_PIN_MUX  P7_4_SDHC0_CARD_DAT_3TO03

#define CY_SDHC_GENERAL_IRQN            sdhc_0_interrupt_general_IRQn
  
/******************************************************************************/
/******************************************************************************/

#else // No Device or PSVP Selected

    #error "Choose either a Device based on TVII-C-2D-6M-DDR Datasheet or CY_USE_PSVP"

#endif // #if (CY_USE_PSVP == 1)


#ifdef __cplusplus
}
#endif

#endif /* BB_BSP_TVIIC2D6MDDR_H */

/* [] END OF FILE */
