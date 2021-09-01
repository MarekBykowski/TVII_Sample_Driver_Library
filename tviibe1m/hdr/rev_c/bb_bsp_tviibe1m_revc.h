/***************************************************************************//**
* \file bb_bsp_tviibe1m_revc.h
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
* Copyright 2018, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef BB_BSP_TVIIBE1M_REVC_H
#define BB_BSP_TVIIBE1M_REVC_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/******************************************************************************/

// PSVP supports only 176-LQFP package

#if (CY_USE_PSVP == 1) && ( defined(CYT2B78BAS) || defined(CYT2B78BAE) || \
                            defined(CYT2B78CAS) || defined(CYT2B78CAE) )

/******************************************************************************/
/*                      LEDs Base Board Mux                                   */
/******************************************************************************/

#define CY_LED0_PORT                    GPIO_PRT3
#define CY_LED0_PIN                     4
#define CY_LED0_PIN_MUX                 P3_4_GPIO
  
#define CY_LED1_PORT                    GPIO_PRT8
#define CY_LED1_PIN                     2
#define CY_LED1_PIN_MUX                 P8_2_GPIO
  
#define CY_LED2_PORT                    GPIO_PRT3
#define CY_LED2_PIN                     1
#define CY_LED2_PIN_MUX                 P3_1_GPIO
  
#define CY_LED3_PORT                    GPIO_PRT3
#define CY_LED3_PIN                     2
#define CY_LED3_PIN_MUX                 P3_2_GPIO
  
#define CY_LED4_PORT                    GPIO_PRT15
#define CY_LED4_PIN                     6
#define CY_LED4_PIN_MUX                 P15_6_GPIO
  
#define CY_LED5_PORT                    GPIO_PRT15
#define CY_LED5_PIN                     1
#define CY_LED5_PIN_MUX                 P15_1_GPIO
  
#define CY_LED6_PORT                    GPIO_PRT9
#define CY_LED6_PIN                     0
#define CY_LED6_PIN_MUX                 P9_0_GPIO
  
#define CY_LED7_PORT                    GPIO_PRT9
#define CY_LED7_PIN                     1
#define CY_LED7_PIN_MUX                 P9_1_GPIO
  
#define CY_LED8_PORT                    GPIO_PRT8
#define CY_LED8_PIN                     3
#define CY_LED8_PIN_MUX                 P8_3_GPIO
  
#define CY_LED9_PORT                    GPIO_PRT18
#define CY_LED9_PIN                     4
#define CY_LED9_PIN_MUX                 P18_4_GPIO  

/******************************************************************************/
/*                      Buttons Base Board Mux                                */
/******************************************************************************/

#define CY_BUTTON1_PORT                 GPIO_PRT7
#define CY_BUTTON1_PIN                  4
#define CY_BUTTON1_PIN_MUX              P7_4_GPIO

#define CY_BUTTON2_PORT                 GPIO_PRT7
#define CY_BUTTON2_PIN                  5
#define CY_BUTTON2_PIN_MUX              P7_5_GPIO
  
#define CY_BUTTON3_PORT                 GPIO_PRT7
#define CY_BUTTON3_PIN                  6
#define CY_BUTTON3_PIN_MUX              P7_6_GPIO
  
#define CY_BUTTON4_PORT                 GPIO_PRT3
#define CY_BUTTON4_PIN                  5
#define CY_BUTTON4_PIN_MUX              P3_5_GPIO
  
#define CY_BUTTON5_PORT                 GPIO_PRT7
#define CY_BUTTON5_PIN                  7
#define CY_BUTTON5_PIN_MUX              P7_7_GPIO

/* Setup GPIO for BUTTONs 1/2/3/5 interrupt sources */
#define CY_BUTTON1_IRQN		        ioss_interrupts_gpio_7_IRQn
#define CY_BUTTON2_IRQN		        ioss_interrupts_gpio_7_IRQn
#define CY_BUTTON3_IRQN		        ioss_interrupts_gpio_7_IRQn
#define CY_BUTTON4_IRQN		        ioss_interrupts_gpio_3_IRQn
#define CY_BUTTON5_IRQN		        ioss_interrupts_gpio_7_IRQn

/******************************************************************************/
/*                      ADC POT                                		      */
/******************************************************************************/

#define CY_ADC_POT_MACRO                PASS0_SAR0
#define CY_ADC_POT_IN_NO               20
#define CY_ADC_POT_PORT                 GPIO_PRT9
#define CY_ADC_POT_PIN                  0
#define CY_ADC_POT_PIN_MUX              P9_0_GPIO
#define CY_ADC_POT_PCLK                 PCLK_PASS0_CLOCK_SAR0
#define CY_ADC_POT_IRQN                 pass_0_interrupts_sar_0_IRQn


/******************************************************************************/
/*                      SCB-UART Base Board Mux                               */
/******************************************************************************/
  
/* USB-UART Mux */
#define CY_USB_SCB_TYPE                 SCB3
#define CY_USB_SCB_UART_RX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_RX_PIN          0
#define CY_USB_SCB_UART_RX_MUX          P13_0_SCB3_UART_RX
#define CY_USB_SCB_UART_TX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_TX_PIN          1
#define CY_USB_SCB_UART_TX_MUX          P13_1_SCB3_UART_TX
#define CY_USB_SCB_UART_PCLK            PCLK_SCB3_CLOCK
#define CY_USB_SCB_UART_IRQN            scb_3_interrupt_IRQn  
  
/* CANFD-SPI Mux */
#define CY_CANFD_SCB_TYPE               SCB1
#define CY_CANFD_SCB_MOSI_PORT          GPIO_PRT17
#define CY_CANFD_SCB_MOSI_PIN           1
#define CY_CANFD_SCB_MOSI_PIN_MUX       P17_1_SCB1_SPI_MOSI
#define CY_CANFD_SCB_MISO_PORT          GPIO_PRT17
#define CY_CANFD_SCB_MISO_PIN           0
#define CY_CANFD_SCB_MISO_PIN_MUX       P17_0_SCB1_SPI_MISO
#define CY_CANFD_SCB_SCK_PORT           GPIO_PRT17
#define CY_CANFD_SCB_SCK_PIN            2
#define CY_CANFD_SCB_SCK_PIN_MUX        P17_2_SCB1_SPI_CLK
#define CY_CANFD_SCB_SS0_PORT           GPIO_PRT17
#define CY_CANFD_SCB_SS0_PIN            3
#define CY_CANFD_SCB_SS0_PIN_MUX        P17_3_SCB1_SPI_SELECT0
#define CY_CANFD_SCB_SS1_PORT           GPIO_PRT17
#define CY_CANFD_SCB_SS1_PIN            4
#define CY_CANFD_SCB_SS1_PIN_MUX        P17_4_SCB1_SPI_SELECT1
#define CY_CANFD_SCB_SS2_PORT           GPIO_PRT17
#define CY_CANFD_SCB_SS2_PIN            5
#define CY_CANFD_SCB_SS2_PIN_MUX        P17_5_SCB1_SPI_SELECT2
#define CY_CANFD_SCB_PCLK               PCLK_SCB1_CLOCK
#define CY_CANFD_SCB_IRQN               scb_1_interrupt_IRQn

/* EEPROM SPI Mux */
#define CY_EEPROM_SCB_TYPE              SCB3
#define CY_EEPROM_SCB_MISO_PORT         GPIO_PRT16
#define CY_EEPROM_SCB_MISO_PIN          1
#define CY_EEPROM_SCB_MISO_PIN_MUX      P16_1_SCB3_SPI_MISO
#define CY_EEPROM_SCB_MOSI_PORT         GPIO_PRT16
#define CY_EEPROM_SCB_MOSI_PIN          2
#define CY_EEPROM_SCB_MOSI_PIN_MUX      P16_2_SCB3_SPI_MOSI
#define CY_EEPROM_SCB_SCK_PORT          GPIO_PRT16
#define CY_EEPROM_SCB_SCK_PIN           3
#define CY_EEPROM_SCB_SCK_PIN_MUX       P16_3_SCB3_SPI_CLK
#define CY_EEPROM_SCB_SSEL_PORT         GPIO_PRT16
#define CY_EEPROM_SCB_SSEL_PIN          4
#define CY_EEPROM_SCB_SSEL_PIN_MUX      P16_4_SCB3_SPI_SELECT0
#define CY_EEPROM_SCB_SS_IDX            CY_SCB_SPI_SLAVE_SELECT0
#define CY_EEPROM_HOLD_PORT             GPIO_PRT12
#define CY_EEPROM_HOLD_PIN              2
#define CY_EEPROM_HOLD_PIN_MUX          P12_2_GPIO
#define CY_EEPROM_WP_PORT               GPIO_PRT12
#define CY_EEPROM_WP_PIN                3
#define CY_EEPROM_WP_PIN_MUX            P12_3_GPIO
#define CY_EEPROM_SCB_PCLK              PCLK_SCB3_CLOCK
#define CY_EEPROM_SCB_IRQN              scb_3_interrupt_IRQn


/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/
  
/* CAN0 Pin Mux */
#define CY_CANFD0_TYPE                  CY_CANFD0_0_TYPE
#define CY_CANFD0_RX_PORT               GPIO_PRT8
#define CY_CANFD0_RX_PIN                1
#define CY_CANFD0_RX_MUX                P8_1_CANFD0_TTCAN_RX0
#define CY_CANFD0_TX_PORT               GPIO_PRT8
#define CY_CANFD0_TX_PIN                0
#define CY_CANFD0_TX_MUX                P8_0_CANFD0_TTCAN_TX0
#define CY_CANFD0_PCLK                  PCLK_CANFD0_CLOCK_CAN0
#define CY_CANFD0_IRQN                  canfd_0_interrupts0_0_IRQn
  
/* CAN1 Pin Mux */
#define CY_CANFD1_TYPE                  CY_CANFD0_1_TYPE
#define CY_CANFD1_RX_PORT               GPIO_PRT4
#define CY_CANFD1_RX_PIN                4
#define CY_CANFD1_RX_MUX                P4_4_CANFD0_TTCAN_RX1
#define CY_CANFD1_TX_PORT               GPIO_PRT4
#define CY_CANFD1_TX_PIN                3
#define CY_CANFD1_TX_MUX                P4_3_CANFD0_TTCAN_TX1
#define CY_CANFD1_PCLK                  PCLK_CANFD0_CLOCK_CAN1
#define CY_CANFD1_IRQN                  canfd_0_interrupts0_1_IRQn
  
/* CAN2 Pin Mux */
#define CY_CANFD2_TYPE                  CY_CANFD0_2_TYPE
#define CY_CANFD2_RX_PORT               GPIO_PRT12
#define CY_CANFD2_RX_PIN                1
#define CY_CANFD2_RX_MUX                P12_1_CANFD0_TTCAN_RX2
#define CY_CANFD2_TX_PORT               GPIO_PRT12
#define CY_CANFD2_TX_PIN                0
#define CY_CANFD2_TX_MUX                P12_0_CANFD0_TTCAN_TX2
#define CY_CANFD2_PCLK                  PCLK_CANFD0_CLOCK_CAN2
#define CY_CANFD2_IRQN                  canfd_0_interrupts0_2_IRQn
  
/* CAN3 Pin Mux */
#define CY_CANFD3_TYPE                  CY_CANFD1_0_TYPE
#define CY_CANFD3_RX_PORT               GPIO_PRT14
#define CY_CANFD3_RX_PIN                1
#define CY_CANFD3_RX_MUX                P14_1_CANFD1_TTCAN_RX0
#define CY_CANFD3_TX_PORT               GPIO_PRT14
#define CY_CANFD3_TX_PIN                0
#define CY_CANFD3_TX_MUX                P14_0_CANFD1_TTCAN_TX0
#define CY_CANFD3_PCLK                  PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD3_IRQN                  canfd_1_interrupts0_0_IRQn
  
/* CAN4 Pin Mux */
#define CY_CANFD4_TYPE                  CY_CANFD1_1_TYPE
#define CY_CANFD4_RX_PORT               GPIO_PRT16
#define CY_CANFD4_RX_PIN                1
#define CY_CANFD4_RX_MUX                P16_1_CANFD1_TTCAN_RX1
#define CY_CANFD4_TX_PORT               GPIO_PRT16
#define CY_CANFD4_TX_PIN                0
#define CY_CANFD4_TX_MUX                P16_0_CANFD1_TTCAN_TX1
#define CY_CANFD4_PCLK                  PCLK_CANFD1_CLOCK_CAN1
#define CY_CANFD4_IRQN                  canfd_1_interrupts0_1_IRQn
  
/* CAN5 Pin Mux */
#define CY_CANFD5_TYPE                  CY_CANFD1_2_TYPE
#define CY_CANFD5_RX_PORT               GPIO_PRT19
#define CY_CANFD5_RX_PIN                4
#define CY_CANFD5_RX_MUX                P19_4_CANFD1_TTCAN_RX2
#define CY_CANFD5_TX_PORT               GPIO_PRT19
#define CY_CANFD5_TX_PIN                3
#define CY_CANFD5_TX_MUX                P19_3_CANFD1_TTCAN_TX2
#define CY_CANFD5_PCLK                  PCLK_CANFD1_CLOCK_CAN2
#define CY_CANFD5_IRQN                  canfd_1_interrupts0_2_IRQn
  
/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/* LIN Channel 0 */
#define CY_LINCH0_TYPE                  LIN0_CH0
#define CY_LINCH0_RX_PORT               GPIO_PRT20
#define CY_LINCH0_RX_PIN                5
#define CY_LINCH0_RX_PIN_MUX            P20_5_LIN_LIN_RX0
#define CY_LINCH0_TX_PORT               GPIO_PRT20
#define CY_LINCH0_TX_PIN                6
#define CY_LINCH0_TX_PIN_MUX            P20_6_LIN_LIN_TX0
#define CY_LINCH0_PCLK                  PCLK_LIN0_CLOCK_CH_EN0
#define CY_LINCH0_IRQN                  lin_0_interrupts_0_IRQn
  
/* LIN Channel 1 */
#define CY_LINCH1_TYPE                  LIN0_CH1
#define CY_LINCH1_RX_PORT               GPIO_PRT4
#define CY_LINCH1_RX_PIN                0
#define CY_LINCH1_RX_PIN_MUX            P4_0_LIN0_LIN_RX1
#define CY_LINCH1_TX_PORT               GPIO_PRT4
#define CY_LINCH1_TX_PIN                1
#define CY_LINCH1_TX_PIN_MUX            P4_1_LIN0_LIN_TX1
#define CY_LINCH1_PCLK                  PCLK_LIN0_CLOCK_CH_EN1
#define CY_LINCH1_IRQN                  lin_0_interrupts_1_IRQn

/* LIN Channel 2 */
#define CY_LINCH2_TYPE                  LIN0_CH2
#define CY_LINCH2_RX_PORT               GPIO_PRT5
#define CY_LINCH2_RX_PIN                3
#define CY_LINCH2_RX_PIN_MUX            P5_3_LIN_LIN_RX2
#define CY_LINCH2_TX_PORT               GPIO_PRT5
#define CY_LINCH2_TX_PIN                4
#define CY_LINCH2_TX_PIN_MUX            P5_4_LIN_LIN_TX2
#define CY_LINCH2_PCLK                  PCLK_LIN0_CLOCK_CH_EN2
#define CY_LINCH2_IRQN                  lin_0_interrupts_2_IRQn

/* LIN Channel 3 */
#define CY_LINCH3_TYPE                  LIN0_CH3
#define CY_LINCH3_RX_PORT               GPIO_PRT6
#define CY_LINCH3_RX_PIN                0
#define CY_LINCH3_RX_PIN_MUX            P6_0_LIN_LIN_RX3
#define CY_LINCH3_TX_PORT               GPIO_PRT6
#define CY_LINCH3_TX_PIN                1
#define CY_LINCH3_TX_PIN_MUX            P6_1_LIN_LIN_TX3
#define CY_LINCH3_PCLK                  PCLK_LIN0_CLOCK_CH_EN3
#define CY_LINCH3_IRQN                  lin_0_interrupts_3_IRQn

/* LIN Channel 4 */
#define CY_LINCH4_TYPE                  LIN0_CH4
#define CY_LINCH4_RX_PORT               GPIO_PRT6
#define CY_LINCH4_RX_PIN                3
#define CY_LINCH4_RX_PIN_MUX            P6_3_LIN_LIN_RX4
#define CY_LINCH4_TX_PORT               GPIO_PRT6
#define CY_LINCH4_TX_PIN                4
#define CY_LINCH4_TX_PIN_MUX            P6_4_LIN_LIN_TX4
#define CY_LINCH4_PCLK                  PCLK_LIN0_CLOCK_CH_EN4
#define CY_LINCH4_IRQN                  lin_0_interrupts_4_IRQn

/* LIN Channel 5 */
#define CY_LINCH5_TYPE                  LIN0_CH5
#define CY_LINCH5_RX_PORT               GPIO_PRT19
#define CY_LINCH5_RX_PIN                0
#define CY_LINCH5_RX_PIN_MUX            P19_0_LIN_LIN_RX5
#define CY_LINCH5_TX_PORT               GPIO_PRT19
#define CY_LINCH5_TX_PIN                1
#define CY_LINCH5_TX_PIN_MUX            P19_1_LIN_LIN_TX5
#define CY_LINCH5_PCLK                  PCLK_LIN0_CLOCK_CH_EN5
#define CY_LINCH5_IRQN                  lin_0_interrupts_5_IRQn   

  
/******************************************************************************/
/*                      SMARTIO Base Board Mux                                */
/******************************************************************************/

#define CY_SMARTIO_MACRO                SMARTIO
#define CY_SMARTIO_PORT                 SMARTIO_PRT15
#define CY_SMARTIO_CLK                  PCLK_SMARTIO15_CLOCK

#define CY_SMARTIO_OUT_PORT             GPIO_PRT15
#define CY_SMARTIO_OUT_PIN              1
#define CY_SMARTIO_OUT_PORT_MUX         P15_1_GPIO

#define CY_SMARTIO_IN_PORT              GPIO_PRT15
#define CY_SMARTIO_IN_PIN               0
#define CY_SMARTIO_IN_PORT_MUX          P15_0_GPIO

/******************************************************************************/
/*                              EXT CLK PORT                                  */
/******************************************************************************/
#define HF1_CLK_OUT_PORT                        GPIO_PRT23
#define HF1_CLK_OUT_PIN                         (2ul)
#define HF1_CLK_OUT_PIN_MUX                     P21_2_SRSS_EXT_CLK

/******************************************************************************/
/******************************************************************************/

// tviibe1m - 176-LQFP Package devices
    
// #if (CY_USE_PSVP == 0) (--> Silicon), project setting CY_USE_PSVP should be changed to '0'
// select the supported or required device accordingly
  
#elif (CY_USE_PSVP == 0) && ( defined(CYT2B58BAS) || defined(CYT2B58BAE) || defined(CYT2B78BAS) || \
                              defined(CYT2B78BAE) || defined(CYT2B78CAS) || defined(CYT2B78CAE) )

/******************************************************************************/
/******************************************************************************/

// CPU Board Entities

/******************************************************************************/
/******************************************************************************/

// USER LED
#define CY_CB_LED_PORT                 	GPIO_PRT8
#define CY_CB_LED_PIN                   2
#define CY_CB_LED_PIN_MUX               P8_2_GPIO

// PUSH BUTTON
#define CY_CB_BUTTON_PORT              	GPIO_PRT6
#define CY_CB_BUTTON_PIN                5
#define CY_CB_BUTTON_PIN_MUX            P6_5_GPIO
#define CY_CB_BUTTON_IRQN               ioss_interrupts_gpio_6_IRQn

/******************************************************************************/
/******************************************************************************/

// BB Board Entities

/******************************************************************************/
/*                      LEDs Base Board Mux                                   */
/******************************************************************************/

#define CY_LED0_PORT                    GPIO_PRT19
#define CY_LED0_PIN                     3
#define CY_LED0_PIN_MUX                 P19_3_GPIO
  
#define CY_LED1_PORT                    GPIO_PRT23
#define CY_LED1_PIN                     3
#define CY_LED1_PIN_MUX                 P23_3_GPIO
  
#define CY_LED2_PORT                    GPIO_PRT19
#define CY_LED2_PIN                     1
#define CY_LED2_PIN_MUX                 P19_1_GPIO
  
#define CY_LED3_PORT                    GPIO_PRT19
#define CY_LED3_PIN                     0
#define CY_LED3_PIN_MUX                 P19_0_GPIO
  
#define CY_LED4_PORT                    GPIO_PRT17
#define CY_LED4_PIN                     2
#define CY_LED4_PIN_MUX                 P17_2_GPIO
  
#define CY_LED5_PORT                    GPIO_PRT14
#define CY_LED5_PIN                     3
#define CY_LED5_PIN_MUX                 P14_3_GPIO
  
#define CY_LED6_PORT                    GPIO_PRT13
#define CY_LED6_PIN                     2
#define CY_LED6_PIN_MUX                 P13_2_GPIO
  
#define CY_LED7_PORT                    GPIO_PRT13
#define CY_LED7_PIN                     3
#define CY_LED7_PIN_MUX                 P13_3_GPIO
  
#define CY_LED8_PORT                    GPIO_PRT13
#define CY_LED8_PIN                     4
#define CY_LED8_PIN_MUX                 P13_4_GPIO
  
#define CY_LED9_PORT                    GPIO_PRT13
#define CY_LED9_PIN                     5
#define CY_LED9_PIN_MUX                 P13_5_GPIO  

/******************************************************************************/
/*                      Buttons Base Board Mux                                */
/******************************************************************************/

#define CY_BUTTON1_PORT                 GPIO_PRT13
#define CY_BUTTON1_PIN                  6
#define CY_BUTTON1_PIN_MUX              P13_6_GPIO

#define CY_BUTTON2_PORT                 GPIO_PRT13
#define CY_BUTTON2_PIN                  7
#define CY_BUTTON2_PIN_MUX              P13_7_GPIO
  
#define CY_BUTTON3_PORT                 GPIO_PRT14
#define CY_BUTTON3_PIN                  2
#define CY_BUTTON3_PIN_MUX              P14_2_GPIO
  
#define CY_BUTTON4_PORT                 GPIO_PRT12
#define CY_BUTTON4_PIN                  4
#define CY_BUTTON4_PIN_MUX              P12_4_GPIO
  
#define CY_BUTTON5_PORT                 GPIO_PRT19
#define CY_BUTTON5_PIN                  2
#define CY_BUTTON5_PIN_MUX              P19_2_GPIO

/* Setup GPIO for BUTTONs 1/2/3/5 interrupt sources */
#define CY_BUTTON1_IRQN		        ioss_interrupts_gpio_13_IRQn
#define CY_BUTTON2_IRQN		        ioss_interrupts_gpio_13_IRQn
#define CY_BUTTON3_IRQN		        ioss_interrupts_gpio_14_IRQn
#define CY_BUTTON4_IRQN		        ioss_interrupts_gpio_12_IRQn
#define CY_BUTTON5_IRQN		        ioss_interrupts_gpio_19_IRQn

/******************************************************************************/
/*                      ADC POT                                		      */
/******************************************************************************/
#define CY_ADC_POT_MACRO                PASS0_SAR2
#define CY_ADC_POT_IN_NO                5
#define CY_ADC_POT_PORT                 GPIO_PRT18
#define CY_ADC_POT_PIN                  5
#define CY_ADC_POT_PIN_MUX              P18_5_GPIO
#define CY_ADC_POT_PCLK                 PCLK_PASS0_CLOCK_SAR2
#define CY_ADC_POT_IRQN                 pass_0_interrupts_sar_64_IRQn

/******************************************************************************/
/*                      SCB-UART Base Board Mux                               */
/******************************************************************************/
  
/* USB-UART Mux */
#define CY_USB_SCB_TYPE                 SCB3
#define CY_USB_SCB_UART_RX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_RX_PIN          0
#define CY_USB_SCB_UART_RX_MUX          P13_0_SCB3_UART_RX
#define CY_USB_SCB_UART_TX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_TX_PIN          1
#define CY_USB_SCB_UART_TX_MUX          P13_1_SCB3_UART_TX
#define CY_USB_SCB_UART_PCLK            PCLK_SCB3_CLOCK
#define CY_USB_SCB_UART_IRQN            scb_3_interrupt_IRQn  
  
/* CANFD-SPI Mux */
#define CY_CANFD_SCB_TYPE               SCB5
#define CY_CANFD_SCB_MISO_PORT          GPIO_PRT7
#define CY_CANFD_SCB_MISO_PIN           0
#define CY_CANFD_SCB_MISO_PIN_MUX       P7_0_SCB5_SPI_MISO
#define CY_CANFD_SCB_MOSI_PORT          GPIO_PRT7
#define CY_CANFD_SCB_MOSI_PIN           1
#define CY_CANFD_SCB_MOSI_PIN_MUX       P7_1_SCB5_SPI_MOSI
#define CY_CANFD_SCB_SCK_PORT           GPIO_PRT7
#define CY_CANFD_SCB_SCK_PIN            2
#define CY_CANFD_SCB_SCK_PIN_MUX        P7_2_SCB5_SPI_CLK
#define CY_CANFD_SCB_SS0_PORT           GPIO_PRT7
#define CY_CANFD_SCB_SS0_PIN            3
#define CY_CANFD_SCB_SS0_PIN_MUX        P7_3_SCB5_SPI_SELECT0
#define CY_CANFD_SCB_SS1_PORT           GPIO_PRT7
#define CY_CANFD_SCB_SS1_PIN            4
#define CY_CANFD_SCB_SS1_PIN_MUX        P7_4_SCB5_SPI_SELECT1
#define CY_CANFD_SCB_SS2_PORT           GPIO_PRT7
#define CY_CANFD_SCB_SS2_PIN            5
#define CY_CANFD_SCB_SS2_PIN_MUX        P7_5_SCB5_SPI_SELECT2
#define CY_CANFD_SCB_PCLK               PCLK_SCB5_CLOCK
#define CY_CANFD_SCB_IRQN               scb_5_interrupt_IRQn

/* EEPROM SPI Mux */
#define CY_EEPROM_SCB_TYPE              SCB1
#define CY_EEPROM_SCB_MOSI_PORT         GPIO_PRT18
#define CY_EEPROM_SCB_MOSI_PIN          1
#define CY_EEPROM_SCB_MOSI_PIN_MUX      P18_1_SCB1_SPI_MOSI
#define CY_EEPROM_SCB_MISO_PORT         GPIO_PRT18
#define CY_EEPROM_SCB_MISO_PIN          0
#define CY_EEPROM_SCB_MISO_PIN_MUX      P18_0_SCB1_SPI_MISO
#define CY_EEPROM_SCB_SCK_PORT          GPIO_PRT18
#define CY_EEPROM_SCB_SCK_PIN           2
#define CY_EEPROM_SCB_SCK_PIN_MUX       P18_2_SCB1_SPI_CLK
#define CY_EEPROM_SCB_SSEL_PORT         GPIO_PRT18
#define CY_EEPROM_SCB_SSEL_PIN          4
#define CY_EEPROM_SCB_SSEL_PIN_MUX      P18_4_SCB1_SPI_SELECT1
#define CY_EEPROM_SCB_SS_IDX            CY_SCB_SPI_SLAVE_SELECT1
#define CY_EEPROM_HOLD_PORT             GPIO_PRT18
#define CY_EEPROM_HOLD_PIN              5
#define CY_EEPROM_HOLD_PIN_MUX          P18_5_GPIO
#define CY_EEPROM_WP_PORT               GPIO_PRT16
#define CY_EEPROM_WP_PIN                2
#define CY_EEPROM_WP_PIN_MUX            P17_2_GPIO
#define CY_EEPROM_SCB_PCLK              PCLK_SCB1_CLOCK
#define CY_EEPROM_SCB_IRQN              scb_1_interrupt_IRQn
#define CY_EEPROM_SCB_SS                1

/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/
  
/* CAN0 Pin Mux */
#define CY_CANFD0_TYPE                  CY_CANFD0_0_TYPE
#define CY_CANFD0_RX_PORT               GPIO_PRT8
#define CY_CANFD0_RX_PIN                1
#define CY_CANFD0_RX_MUX                P8_1_CANFD0_TTCAN_RX0
#define CY_CANFD0_TX_PORT               GPIO_PRT8
#define CY_CANFD0_TX_PIN                0
#define CY_CANFD0_TX_MUX                P8_0_CANFD0_TTCAN_TX0
#define CY_CANFD0_PCLK                  PCLK_CANFD0_CLOCK_CAN0
#define CY_CANFD0_IRQN                  canfd_0_interrupts0_0_IRQn
  
/* CAN1 Pin Mux */
#define CY_CANFD1_TYPE                  CY_CANFD0_1_TYPE
#define CY_CANFD1_RX_PORT               GPIO_PRT0
#define CY_CANFD1_RX_PIN                3
#define CY_CANFD1_RX_MUX                P0_3_CANFD0_TTCAN_RX1
#define CY_CANFD1_TX_PORT               GPIO_PRT0
#define CY_CANFD1_TX_PIN                2
#define CY_CANFD1_TX_MUX                P0_2_CANFD0_TTCAN_TX1
#define CY_CANFD1_PCLK                  PCLK_CANFD0_CLOCK_CAN1
#define CY_CANFD1_IRQN                  canfd_0_interrupts0_1_IRQn
  
/* CAN2 Pin Mux */
#define CY_CANFD2_TYPE                  CY_CANFD0_2_TYPE
#define CY_CANFD2_RX_PORT               GPIO_PRT12
#define CY_CANFD2_RX_PIN                1
#define CY_CANFD2_RX_MUX                P12_1_CANFD0_TTCAN_RX2
#define CY_CANFD2_TX_PORT               GPIO_PRT12
#define CY_CANFD2_TX_PIN                0
#define CY_CANFD2_TX_MUX                P12_0_CANFD0_TTCAN_TX2
#define CY_CANFD2_PCLK                  PCLK_CANFD0_CLOCK_CAN2
#define CY_CANFD2_IRQN                  canfd_0_interrupts0_2_IRQn
  
/* CAN3 Pin Mux */
#define CY_CANFD3_TYPE                  CY_CANFD1_0_TYPE
#define CY_CANFD3_RX_PORT               GPIO_PRT14
#define CY_CANFD3_RX_PIN                1
#define CY_CANFD3_RX_MUX                P14_1_CANFD1_TTCAN_RX0
#define CY_CANFD3_TX_PORT               GPIO_PRT14
#define CY_CANFD3_TX_PIN                0
#define CY_CANFD3_TX_MUX                P14_0_CANFD1_TTCAN_TX0
#define CY_CANFD3_PCLK                  PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD3_IRQN                  canfd_1_interrupts0_0_IRQn
  
/* CAN4 Pin Mux */
#define CY_CANFD4_TYPE                  CY_CANFD1_1_TYPE
#define CY_CANFD4_RX_PORT               GPIO_PRT17
#define CY_CANFD4_RX_PIN                1
#define CY_CANFD4_RX_MUX                P17_1_CANFD1_TTCAN_RX1
#define CY_CANFD4_TX_PORT               GPIO_PRT17
#define CY_CANFD4_TX_PIN                0
#define CY_CANFD4_TX_MUX                P17_0_CANFD1_TTCAN_TX1
#define CY_CANFD4_PCLK                  PCLK_CANFD1_CLOCK_CAN1
#define CY_CANFD4_IRQN                  canfd_1_interrupts0_1_IRQn
  
/* CAN5 Pin Mux */
#define CY_CANFD5_TYPE                  CY_CANFD1_2_TYPE
#define CY_CANFD5_RX_PORT               GPIO_PRT18
#define CY_CANFD5_RX_PIN                7
#define CY_CANFD5_RX_MUX                P18_7_CANFD1_TTCAN_RX2
#define CY_CANFD5_TX_PORT               GPIO_PRT18
#define CY_CANFD5_TX_PIN                6
#define CY_CANFD5_TX_MUX                P18_6_CANFD1_TTCAN_TX2
#define CY_CANFD5_PCLK                  PCLK_CANFD1_CLOCK_CAN2
#define CY_CANFD5_IRQN                  canfd_1_interrupts0_2_IRQn
  
/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/* LIN Channel 0 */
#define CY_LINCH0_TYPE                  LIN0_CH0
#define CY_LINCH0_RX_PORT               GPIO_PRT21
#define CY_LINCH0_RX_PIN                5
#define CY_LINCH0_RX_PIN_MUX            P21_5_LIN0_LIN_RX0
#define CY_LINCH0_TX_PORT               GPIO_PRT2
#define CY_LINCH0_TX_PIN                1
#define CY_LINCH0_TX_PIN_MUX            P2_1_LIN0_LIN_TX0
#define CY_LINCH0_PCLK                  PCLK_LIN0_CLOCK_CH_EN0
#define CY_LINCH0_IRQN                  lin_0_interrupts_0_IRQn
  
/* LIN Channel 1 */
#define CY_LINCH1_TYPE                  LIN0_CH1
#define CY_LINCH1_RX_PORT               GPIO_PRT0
#define CY_LINCH1_RX_PIN                0
#define CY_LINCH1_RX_PIN_MUX            P0_0_LIN0_LIN_RX1
#define CY_LINCH1_TX_PORT               GPIO_PRT0
#define CY_LINCH1_TX_PIN                1
#define CY_LINCH1_TX_PIN_MUX            P0_1_LIN0_LIN_TX1
#define CY_LINCH1_PCLK                  PCLK_LIN0_CLOCK_CH_EN1
#define CY_LINCH1_IRQN                  lin_0_interrupts_1_IRQn

/* LIN Channel 2 */
#define CY_LINCH2_TYPE                  LIN0_CH2
#define CY_LINCH2_RX_PORT               GPIO_PRT5
#define CY_LINCH2_RX_PIN                3
#define CY_LINCH2_RX_PIN_MUX            P5_3_LIN0_LIN_RX2
#define CY_LINCH2_TX_PORT               GPIO_PRT8
#define CY_LINCH2_TX_PIN                1
#define CY_LINCH2_TX_PIN_MUX            P8_1_LIN0_LIN_TX2
#define CY_LINCH2_PCLK                  PCLK_LIN0_CLOCK_CH_EN2
#define CY_LINCH2_IRQN                  lin_0_interrupts_2_IRQn

/* LIN Channel 3 */
#define CY_LINCH3_TYPE                  LIN0_CH3
#define CY_LINCH3_RX_PORT               GPIO_PRT6
#define CY_LINCH3_RX_PIN                0
#define CY_LINCH3_RX_PIN_MUX            P6_0_LIN0_LIN_RX3
#define CY_LINCH3_TX_PORT               GPIO_PRT6
#define CY_LINCH3_TX_PIN                1
#define CY_LINCH3_TX_PIN_MUX            P6_1_LIN0_LIN_TX3
#define CY_LINCH3_PCLK                  PCLK_LIN0_CLOCK_CH_EN3
#define CY_LINCH3_IRQN                  lin_0_interrupts_3_IRQn

/* LIN Channel 4 */
#define CY_LINCH4_TYPE                  LIN0_CH4
#define CY_LINCH4_RX_PORT               GPIO_PRT6
#define CY_LINCH4_RX_PIN                3
#define CY_LINCH4_RX_PIN_MUX            P6_3_LIN0_LIN_RX4
#define CY_LINCH4_TX_PORT               GPIO_PRT6
#define CY_LINCH4_TX_PIN                4
#define CY_LINCH4_TX_PIN_MUX            P6_4_LIN0_LIN_TX4
#define CY_LINCH4_PCLK                  PCLK_LIN0_CLOCK_CH_EN4
#define CY_LINCH4_IRQN                  lin_0_interrupts_4_IRQn

/* LIN Channel 5 */
#define CY_LINCH5_TYPE                  LIN0_CH6
#define CY_LINCH5_RX_PORT               GPIO_PRT12
#define CY_LINCH5_RX_PIN                2
#define CY_LINCH5_RX_PIN_MUX            P12_2_LIN0_LIN_RX6
#define CY_LINCH5_TX_PORT               GPIO_PRT12
#define CY_LINCH5_TX_PIN                3
#define CY_LINCH5_TX_PIN_MUX            P12_3_LIN0_LIN_TX6
#define CY_LINCH5_PCLK                  PCLK_LIN0_CLOCK_CH_EN6
#define CY_LINCH5_IRQN                  lin_0_interrupts_6_IRQn


/******************************************************************************/
/*                      SMARTIO Base Board Mux                                */
/******************************************************************************/

#define CY_SMARTIO_MACRO                SMARTIO
#define CY_SMARTIO_PORT                 SMARTIO_PRT14
#define CY_SMARTIO_CLK                  PCLK_SMARTIO14_CLOCK

#define CY_SMARTIO_OUT_PORT             GPIO_PRT14
#define CY_SMARTIO_OUT_PIN              3
#define CY_SMARTIO_OUT_PORT_MUX         P14_3_GPIO

#define CY_SMARTIO_IN_PORT              GPIO_PRT14
#define CY_SMARTIO_IN_PIN               2
#define CY_SMARTIO_IN_PORT_MUX          P14_2_GPIO
#define CY_SMARTIO_IN_PORT_MUX_PWM      P14_2_TCPWM0_LINE50

#define CY_SMARTIO_IN2_PORT             GPIO_PRT14
#define CY_SMARTIO_IN2_PIN              1
#define CY_SMARTIO_IN2_PORT_MUX_PWM     P14_1_TCPWM0_LINE49

/* PWM PR Mode Configuration def */
#define CY_SMARTIO_TCPWM_GRP0_CNT       TCPWM0_GRP0_CNT50
#define CY_SMARTIO_TCPWM_PCLK           PCLK_TCPWM0_CLOCKS50

#define CY_SMARTIO_TCPWM_GRP0_CNT2      TCPWM0_GRP0_CNT49
#define CY_SMARTIO_TCPWM_PCLK2          PCLK_TCPWM0_CLOCKS49

/******************************************************************************/
/*                              EXT CLK PORT                                  */
/******************************************************************************/
#define HF1_CLK_OUT_PORT                        GPIO_PRT23
#define HF1_CLK_OUT_PIN                         (2ul)
#define HF1_CLK_OUT_PIN_MUX                     P21_2_SRSS_EXT_CLK

/******************************************************************************/
/******************************************************************************/

// tviibe1m - 144-LQFP Package devices
    
// #if (CY_USE_PSVP == 0) (--> Silicon), project setting CY_USE_PSVP should be changed to '0'
// select the supported or required device accordingly
    
#elif (CY_USE_PSVP == 0) && ( defined(CYT2B57BAS) || defined(CYT2B57BAE) || defined(CYT2B77BAS) || \
                              defined(CYT2B77BAE) || defined(CYT2B77CAS) || defined(CYT2B77CAE) )


/******************************************************************************/
/******************************************************************************/

// CPU Board Entities

/******************************************************************************/
/******************************************************************************/

// USER LED
#define CY_CB_LED_PORT                 	GPIO_PRT8
#define CY_CB_LED_PIN                   2
#define CY_CB_LED_PIN_MUX               P8_2_GPIO

// PUSH BUTTON
#define CY_CB_BUTTON_PORT              	GPIO_PRT6
#define CY_CB_BUTTON_PIN                5
#define CY_CB_BUTTON_PIN_MUX            P6_5_GPIO
#define CY_CB_BUTTON_IRQN               ioss_interrupts_gpio_6_IRQn

/******************************************************************************/
/******************************************************************************/

// BB Board Entities

/******************************************************************************/
/*                      LEDs Base Board Mux                                   */
/******************************************************************************/
#define CY_LED0_PORT                    GPIO_PRT2
#define CY_LED0_PIN                     2
#define CY_LED0_PIN_MUX                 P2_2_GPIO
  
#define CY_LED1_PORT                    GPIO_PRT2
#define CY_LED1_PIN                     3
#define CY_LED1_PIN_MUX                 P2_3_GPIO
  
#define CY_LED2_PORT                    GPIO_PRT5
#define CY_LED2_PIN                     0
#define CY_LED2_PIN_MUX                 P5_0_GPIO
  
#define CY_LED3_PORT                    GPIO_PRT5
#define CY_LED3_PIN                     1
#define CY_LED3_PIN_MUX                 P5_1_GPIO
  
#define CY_LED4_PORT                    GPIO_PRT5
#define CY_LED4_PIN                     2
#define CY_LED4_PIN_MUX                 P5_2_GPIO
  
#define CY_LED5_PORT                    GPIO_PRT5
#define CY_LED5_PIN                     3
#define CY_LED5_PIN_MUX                 P5_3_GPIO
  
#define CY_LED6_PORT                    GPIO_PRT6
#define CY_LED6_PIN                     5
#define CY_LED6_PIN_MUX                 P6_5_GPIO
  
#define CY_LED7_PORT                    GPIO_PRT19
#define CY_LED7_PIN                     0
#define CY_LED7_PIN_MUX                 P19_0_GPIO
  
#define CY_LED8_PORT                    GPIO_PRT19
#define CY_LED8_PIN                     1
#define CY_LED8_PIN_MUX                 P19_1_GPIO
  
#define CY_LED9_PORT                    GPIO_PRT23
#define CY_LED9_PIN                     3
#define CY_LED9_PIN_MUX                 P23_3_GPIO  

/******************************************************************************/
/*                      Buttons Base Board Mux                                */
/******************************************************************************/

#define CY_BUTTON1_PORT                 GPIO_PRT18
#define CY_BUTTON1_PIN                  2
#define CY_BUTTON1_PIN_MUX              P18_2_GPIO

#define CY_BUTTON2_PORT                 GPIO_PRT18
#define CY_BUTTON2_PIN                  1
#define CY_BUTTON2_PIN_MUX              P18_1_GPIO
  
#define CY_BUTTON3_PORT                 GPIO_PRT18
#define CY_BUTTON3_PIN                  0
#define CY_BUTTON3_PIN_MUX              P18_0_GPIO
  
#define CY_BUTTON4_PORT                 GPIO_PRT13
#define CY_BUTTON4_PIN                  7
#define CY_BUTTON4_PIN_MUX              P13_7_GPIO
  
#define CY_BUTTON5_PORT                 GPIO_PRT13
#define CY_BUTTON5_PIN                  2
#define CY_BUTTON5_PIN_MUX              P13_2_GPIO

/* Setup GPIO for BUTTONs 1/2/3/5 interrupt sources */
#define CY_BUTTON1_IRQN			ioss_interrupts_gpio_18_IRQn
#define CY_BUTTON2_IRQN			ioss_interrupts_gpio_18_IRQn
#define CY_BUTTON3_IRQN			ioss_interrupts_gpio_18_IRQn
#define CY_BUTTON4_IRQN			ioss_interrupts_gpio_13_IRQn
#define CY_BUTTON5_IRQN			ioss_interrupts_gpio_13_IRQn

/******************************************************************************/
/*                      ADC POT                                	              */
/******************************************************************************/

#define CY_ADC_POT_MACRO                PASS0_SAR2
#define CY_ADC_POT_IN_NO               0
#define CY_ADC_POT_PORT                 GPIO_PRT18
#define CY_ADC_POT_PIN                  0
#define CY_ADC_POT_PIN_MUX              P18_0_GPIO
#define CY_ADC_POT_PCLK                 PCLK_PASS0_CLOCK_SAR2
#define CY_ADC_POT_IRQN                 pass_0_interrupts_sar_64_IRQn

/******************************************************************************/
/*                      SCB-UART Base Board Mux                               */
/******************************************************************************/
  
/* USB-UART Mux */
#define CY_USB_SCB_TYPE                 SCB3
#define CY_USB_SCB_UART_RX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_RX_PIN          0
#define CY_USB_SCB_UART_RX_MUX          P13_0_SCB3_UART_RX
#define CY_USB_SCB_UART_TX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_TX_PIN          1
#define CY_USB_SCB_UART_TX_MUX          P13_1_SCB3_UART_TX
#define CY_USB_SCB_UART_PCLK            PCLK_SCB3_CLOCK
#define CY_USB_SCB_UART_IRQN            scb_3_interrupt_IRQn  
  
/* CANFD-SPI Mux */
#define CY_CANFD_SCB_TYPE               SCB4
#define CY_CANFD_SCB_MOSI_PORT          GPIO_PRT6
#define CY_CANFD_SCB_MOSI_PIN           1
#define CY_CANFD_SCB_MOSI_PIN_MUX       P6_1_SCB4_SPI_MOSI
#define CY_CANFD_SCB_MISO_PORT          GPIO_PRT6
#define CY_CANFD_SCB_MISO_PIN           0
#define CY_CANFD_SCB_MISO_PIN_MUX       P6_0_SCB4_SPI_MISO
#define CY_CANFD_SCB_SCK_PORT           GPIO_PRT6
#define CY_CANFD_SCB_SCK_PIN            2
#define CY_CANFD_SCB_SCK_PIN_MUX        P6_2_SCB4_SPI_CLK
#define CY_CANFD_SCB_SS0_PORT           GPIO_PRT6
#define CY_CANFD_SCB_SS0_PIN            3
#define CY_CANFD_SCB_SS0_PIN_MUX        P6_3_SCB4_SPI_SELECT0
#define CY_CANFD_SCB_SS1_PORT           GPIO_PRT6
#define CY_CANFD_SCB_SS1_PIN            4
#define CY_CANFD_SCB_SS1_PIN_MUX        P6_4_SCB4_SPI_SELECT1
#define CY_CANFD_SCB_SS2_PORT           GPIO_PRT6
#define CY_CANFD_SCB_SS2_PIN            5
#define CY_CANFD_SCB_SS2_PIN_MUX        P6_5_SCB4_SPI_SELECT2
#define CY_CANFD_SCB_PCLK               PCLK_SCB4_CLOCK
#define CY_CANFD_SCB_IRQN               scb_4_interrupt_IRQn

/* EEPROM SPI Mux */
#define CY_EEPROM_SCB_TYPE              SCB5
#define CY_EEPROM_SCB_MISO_PORT         GPIO_PRT7
#define CY_EEPROM_SCB_MISO_PIN          0
#define CY_EEPROM_SCB_MISO_PIN_MUX      P7_0_SCB5_SPI_MISO
#define CY_EEPROM_SCB_MOSI_PORT         GPIO_PRT7
#define CY_EEPROM_SCB_MOSI_PIN          1
#define CY_EEPROM_SCB_MOSI_PIN_MUX      P7_1_SCB5_SPI_MOSI
#define CY_EEPROM_SCB_SCK_PORT          GPIO_PRT7
#define CY_EEPROM_SCB_SCK_PIN           2
#define CY_EEPROM_SCB_SCK_PIN_MUX       P7_2_SCB5_SPI_CLK
#define CY_EEPROM_SCB_SSEL_PORT         GPIO_PRT5
#define CY_EEPROM_SCB_SSEL_PIN          0
#define CY_EEPROM_SCB_SSEL_PIN_MUX      P5_0_SCB5_SPI_SELECT2
#define CY_EEPROM_SCB_SS_IDX            CY_SCB_SPI_SLAVE_SELECT2
#define CY_EEPROM_SCB_PCLK              PCLK_SCB5_CLOCK
#define CY_EEPROM_SCB_IRQN              scb_5_interrupt_IRQn
#define CY_EEPROM_SCB_SS                2

/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/
  
/* CAN0 Pin Mux */
#define CY_CANFD0_TYPE                  CY_CANFD0_0_TYPE
#define CY_CANFD0_RX_PORT               GPIO_PRT8
#define CY_CANFD0_RX_PIN                1
#define CY_CANFD0_RX_MUX                P8_1_CANFD0_TTCAN_RX0
#define CY_CANFD0_TX_PORT               GPIO_PRT8
#define CY_CANFD0_TX_PIN                0
#define CY_CANFD0_TX_MUX                P8_0_CANFD0_TTCAN_TX0
#define CY_CANFD0_PCLK                  PCLK_CANFD0_CLOCK_CAN0
#define CY_CANFD0_IRQN                  canfd_0_interrupts0_0_IRQn
  
/* CAN1 Pin Mux */
#define CY_CANFD1_TYPE                  CY_CANFD0_1_TYPE
#define CY_CANFD1_RX_PORT               GPIO_PRT0
#define CY_CANFD1_RX_PIN                3
#define CY_CANFD1_RX_MUX                P0_3_CANFD0_TTCAN_RX1
#define CY_CANFD1_TX_PORT               GPIO_PRT0
#define CY_CANFD1_TX_PIN                2
#define CY_CANFD1_TX_MUX                P0_2_CANFD0_TTCAN_TX1
#define CY_CANFD1_PCLK                  PCLK_CANFD0_CLOCK_CAN1
#define CY_CANFD1_IRQN                  canfd_0_interrupts0_1_IRQn
  
/* CAN2 Pin Mux */
#define CY_CANFD2_TYPE                  CY_CANFD0_2_TYPE
#define CY_CANFD2_RX_PORT               GPIO_PRT12
#define CY_CANFD2_RX_PIN                1
#define CY_CANFD2_RX_MUX                P12_1_CANFD0_TTCAN_RX2
#define CY_CANFD2_TX_PORT               GPIO_PRT12
#define CY_CANFD2_TX_PIN                0
#define CY_CANFD2_TX_MUX                P12_0_CANFD0_TTCAN_TX2
#define CY_CANFD2_PCLK                  PCLK_CANFD0_CLOCK_CAN2
#define CY_CANFD2_IRQN                  canfd_0_interrupts0_2_IRQn
  
/* CAN3 Pin Mux */
#define CY_CANFD3_TYPE                  CY_CANFD1_0_TYPE
#define CY_CANFD3_RX_PORT               GPIO_PRT14
#define CY_CANFD3_RX_PIN                1
#define CY_CANFD3_RX_MUX                P14_1_CANFD1_TTCAN_RX0
#define CY_CANFD3_TX_PORT               GPIO_PRT14
#define CY_CANFD3_TX_PIN                0
#define CY_CANFD3_TX_MUX                P14_0_CANFD1_TTCAN_TX0
#define CY_CANFD3_PCLK                  PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD3_IRQN                  canfd_1_interrupts0_0_IRQn

/* CAN4 Pin Mux */
#define CY_CANFD4_TYPE                  CY_CANFD1_1_TYPE
#define CY_CANFD4_RX_PORT               GPIO_PRT22
#define CY_CANFD4_RX_PIN                1
#define CY_CANFD4_RX_MUX                P22_1_CANFD1_TTCAN_RX1
#define CY_CANFD4_TX_PORT               GPIO_PRT22
#define CY_CANFD4_TX_PIN                0
#define CY_CANFD4_TX_MUX                P22_0_CANFD1_TTCAN_TX1
#define CY_CANFD4_PCLK                  PCLK_CANFD1_CLOCK_CAN1
#define CY_CANFD4_IRQN                  canfd_1_interrupts0_1_IRQn
  
/* CAN5 Pin Mux */
#define CY_CANFD5_TYPE                  CY_CANFD1_2_TYPE
#define CY_CANFD5_RX_PORT               GPIO_PRT18
#define CY_CANFD5_RX_PIN                7
#define CY_CANFD5_RX_MUX                P18_7_CANFD1_TTCAN_RX2
#define CY_CANFD5_TX_PORT               GPIO_PRT18
#define CY_CANFD5_TX_PIN                6
#define CY_CANFD5_TX_MUX                P18_6_CANFD1_TTCAN_TX2
#define CY_CANFD5_PCLK                  PCLK_CANFD1_CLOCK_CAN2
#define CY_CANFD5_IRQN                  canfd_1_interrupts0_2_IRQn
  
/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/* LIN Channel 0 */
#define CY_LINCH0_TYPE                  LIN0_CH0
#define CY_LINCH0_RX_PORT               GPIO_PRT2
#define CY_LINCH0_RX_PIN                0
#define CY_LINCH0_RX_PIN_MUX            P2_0_LIN0_LIN_RX0
#define CY_LINCH0_TX_PORT               GPIO_PRT2
#define CY_LINCH0_TX_PIN                1
#define CY_LINCH0_TX_PIN_MUX            P2_1_LIN0_LIN_TX0
#define CY_LINCH0_PCLK                  PCLK_LIN0_CLOCK_CH_EN0
#define CY_LINCH0_IRQN                  lin_0_interrupts_0_IRQn
  
/* LIN Channel 1 */
#define CY_LINCH1_TYPE                  LIN0_CH1
#define CY_LINCH1_RX_PORT               GPIO_PRT0
#define CY_LINCH1_RX_PIN                0
#define CY_LINCH1_RX_PIN_MUX            P0_0_LIN0_LIN_RX1
#define CY_LINCH1_TX_PORT               GPIO_PRT0
#define CY_LINCH1_TX_PIN                1
#define CY_LINCH1_TX_PIN_MUX            P0_1_LIN0_LIN_TX1
#define CY_LINCH1_PCLK                  PCLK_LIN0_CLOCK_CH_EN1
#define CY_LINCH1_IRQN                  lin_0_interrupts_1_IRQn

/* LIN Channel 2 */
#define CY_LINCH2_TYPE                  LIN0_CH2
#define CY_LINCH2_RX_PORT               GPIO_PRT8
#define CY_LINCH2_RX_PIN                0
#define CY_LINCH2_RX_PIN_MUX            P8_0_LIN0_LIN_RX2
#define CY_LINCH2_TX_PORT               GPIO_PRT8
#define CY_LINCH2_TX_PIN                1
#define CY_LINCH2_TX_PIN_MUX            P8_1_LIN0_LIN_TX2
#define CY_LINCH2_PCLK                  PCLK_LIN0_CLOCK_CH_EN2
#define CY_LINCH2_IRQN                  lin_0_interrupts_2_IRQn

/* LIN Channel 3 */
#define CY_LINCH3_TYPE                  LIN0_CH3
#define CY_LINCH3_RX_PORT               GPIO_PRT6
#define CY_LINCH3_RX_PIN                0
#define CY_LINCH3_RX_PIN_MUX            P6_0_LIN0_LIN_RX3
#define CY_LINCH3_TX_PORT               GPIO_PRT6
#define CY_LINCH3_TX_PIN                1
#define CY_LINCH3_TX_PIN_MUX            P6_1_LIN0_LIN_TX3
#define CY_LINCH3_PCLK                  PCLK_LIN0_CLOCK_CH_EN3
#define CY_LINCH3_IRQN                  lin_0_interrupts_3_IRQn

/* LIN Channel 4 */
#define CY_LINCH4_TYPE                  LIN0_CH4
#define CY_LINCH4_RX_PORT               GPIO_PRT7
#define CY_LINCH4_RX_PIN                0
#define CY_LINCH4_RX_PIN_MUX            P7_0_LIN0_LIN_RX4
#define CY_LINCH4_TX_PORT               GPIO_PRT7
#define CY_LINCH4_TX_PIN                1
#define CY_LINCH4_TX_PIN_MUX            P7_1_LIN0_LIN_TX4
#define CY_LINCH4_PCLK                  PCLK_LIN0_CLOCK_CH_EN4
#define CY_LINCH4_IRQN                  lin_0_interrupts_4_IRQn

/* LIN Channel 5 */
#define CY_LINCH5_TYPE                  LIN0_CH6
#define CY_LINCH5_RX_PORT               GPIO_PRT12
#define CY_LINCH5_RX_PIN                2
#define CY_LINCH5_RX_PIN_MUX            P12_2_LIN0_LIN_RX6
#define CY_LINCH5_TX_PORT               GPIO_PRT12
#define CY_LINCH5_TX_PIN                3
#define CY_LINCH5_TX_PIN_MUX            P12_3_LIN0_LIN_TX6
#define CY_LINCH5_PCLK                  PCLK_LIN0_CLOCK_CH_EN6
#define CY_LINCH5_IRQN                  lin_0_interrupts_6_IRQn


/******************************************************************************/
/*                      SMARTIO Base Board Mux                                */
/******************************************************************************/

#define CY_SMARTIO_MACRO                SMARTIO
#define CY_SMARTIO_PORT                 SMARTIO_PRT15
#define CY_SMARTIO_CLK                  PCLK_SMARTIO15_CLOCK

#define CY_SMARTIO_OUT_PORT             GPIO_PRT15
#define CY_SMARTIO_OUT_PIN              1
#define CY_SMARTIO_OUT_PORT_MUX         P15_1_GPIO

#define CY_SMARTIO_IN_PORT              GPIO_PRT15
#define CY_SMARTIO_IN_PIN               0
#define CY_SMARTIO_IN_PORT_MUX          P15_0_GPIO
    
/******************************************************************************/
/*                              EXT CLK PORT                                  */
/******************************************************************************/
#define HF1_CLK_OUT_PORT                        GPIO_PRT23
#define HF1_CLK_OUT_PIN                         (2ul)
#define HF1_CLK_OUT_PIN_MUX                     P21_2_SRSS_EXT_CLK

/******************************************************************************/
/******************************************************************************/
    
// tviibe1m - 100-LQFP Package devices
    
// #if (CY_USE_PSVP == 0) (--> Silicon), project setting CY_USE_PSVP should be changed to '0'
// select the supported or required device accordingly
    
#elif (CY_USE_PSVP == 0) && ( defined(CYT2B75BAS) || defined(CYT2B75BAE) || \
                              defined(CYT2B75CAS) || defined(CYT2B75CAE) )

// CPU Board Entities

// USER LED
#define CY_CB_LED_PORT                 	GPIO_PRT8
#define CY_CB_LED_PIN                   2
#define CY_CB_LED_PIN_MUX               P8_2_GPIO

// PUSH BUTTON
#define CY_CB_BUTTON_PORT              	GPIO_PRT6
#define CY_CB_BUTTON_PIN                5
#define CY_CB_BUTTON_PIN_MUX            P6_5_GPIO
#define CY_CB_BUTTON_IRQN               ioss_interrupts_gpio_6_IRQn

// BB Board Entities

/******************************************************************************/
/*                      LEDs Base Board Mux                                   */
/******************************************************************************/

#define CY_LED0_PORT                    GPIO_PRT19
#define CY_LED0_PIN                     3
#define CY_LED0_PIN_MUX                 P19_3_GPIO
  
#define CY_LED1_PORT                    GPIO_PRT23
#define CY_LED1_PIN                     3
#define CY_LED1_PIN_MUX                 P23_3_GPIO
  
#define CY_LED2_PORT                    GPIO_PRT19
#define CY_LED2_PIN                     1
#define CY_LED2_PIN_MUX                 P19_1_GPIO
  
#define CY_LED3_PORT                    GPIO_PRT19
#define CY_LED3_PIN                     0
#define CY_LED3_PIN_MUX                 P19_0_GPIO
  
#define CY_LED4_PORT                    GPIO_PRT17
#define CY_LED4_PIN                     2
#define CY_LED4_PIN_MUX                 P17_2_GPIO
  
#define CY_LED5_PORT                    GPIO_PRT14
#define CY_LED5_PIN                     3
#define CY_LED5_PIN_MUX                 P14_3_GPIO
  
#define CY_LED6_PORT                    GPIO_PRT13
#define CY_LED6_PIN                     2
#define CY_LED6_PIN_MUX                 P13_2_GPIO
  
#define CY_LED7_PORT                    GPIO_PRT13
#define CY_LED7_PIN                     3
#define CY_LED7_PIN_MUX                 P13_3_GPIO
  
#define CY_LED8_PORT                    GPIO_PRT13
#define CY_LED8_PIN                     4
#define CY_LED8_PIN_MUX                 P13_4_GPIO
  
#define CY_LED9_PORT                    GPIO_PRT13
#define CY_LED9_PIN                     5
#define CY_LED9_PIN_MUX                 P13_5_GPIO

/******************************************************************************/
/*                      Buttons Base Board Mux                                */
/******************************************************************************/

#define CY_BUTTON1_PORT                 GPIO_PRT13
#define CY_BUTTON1_PIN                  6
#define CY_BUTTON1_PIN_MUX              P13_6_GPIO

#define CY_BUTTON2_PORT                 GPIO_PRT13
#define CY_BUTTON2_PIN                  7
#define CY_BUTTON2_PIN_MUX              P13_7_GPIO
  
#define CY_BUTTON3_PORT                 GPIO_PRT14
#define CY_BUTTON3_PIN                  2
#define CY_BUTTON3_PIN_MUX              P14_2_GPIO
  
#define CY_BUTTON4_PORT                 GPIO_PRT12
#define CY_BUTTON4_PIN                  4
#define CY_BUTTON4_PIN_MUX              P12_4_GPIO
  
#define CY_BUTTON5_PORT                 GPIO_PRT19
#define CY_BUTTON5_PIN                  2
#define CY_BUTTON5_PIN_MUX              P19_2_GPIO

/* Setup GPIO for BUTTONs 1/2/3/5 interrupt sources */
#define CY_BUTTON1_IRQN			ioss_interrupts_gpio_13_IRQn
#define CY_BUTTON2_IRQN			ioss_interrupts_gpio_13_IRQn
#define CY_BUTTON3_IRQN			ioss_interrupts_gpio_14_IRQn
#define CY_BUTTON4_IRQN			ioss_interrupts_gpio_12_IRQn
#define CY_BUTTON5_IRQN			ioss_interrupts_gpio_19_IRQn

/******************************************************************************/
/*                      ADC POT                                		          */
/******************************************************************************/

#define CY_ADC_POT_MACRO                PASS0_SAR2
#define CY_ADC_POT_IN_NO               21
#define CY_ADC_POT_PORT                 GPIO_PRT14
#define CY_ADC_POT_PIN                  1
#define CY_ADC_POT_PIN_MUX              P14_1_GPIO
#define CY_ADC_POT_PCLK                 PCLK_PASS0_CLOCK_SAR2
#define CY_ADC_POT_IRQN                 pass_0_interrupts_sar_64_IRQn

/******************************************************************************/
/*                      SCB-UART Base Board Mux                               */
/******************************************************************************/

/* USB-UART Mux */
#define CY_USB_SCB_TYPE                 SCB3
#define CY_USB_SCB_UART_RX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_RX_PIN          0
#define CY_USB_SCB_UART_RX_MUX          P13_0_SCB3_UART_RX
#define CY_USB_SCB_UART_TX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_TX_PIN          1
#define CY_USB_SCB_UART_TX_MUX          P13_1_SCB3_UART_TX
#define CY_USB_SCB_UART_PCLK            PCLK_SCB3_CLOCK
#define CY_USB_SCB_UART_IRQN            scb_3_interrupt_IRQn  

/* CANFD-SPI Mux */
#define CY_CANFD_SCB_TYPE               SCB5
#define CY_CANFD_SCB_MOSI_PORT          GPIO_PRT7
#define CY_CANFD_SCB_MOSI_PIN           1
#define CY_CANFD_SCB_MOSI_PIN_MUX       P7_1_SCB5_SPI_MOSI
#define CY_CANFD_SCB_MISO_PORT          GPIO_PRT7
#define CY_CANFD_SCB_MISO_PIN           0
#define CY_CANFD_SCB_MISO_PIN_MUX       P7_0_SCB5_SPI_MISO
#define CY_CANFD_SCB_SCK_PORT           GPIO_PRT7
#define CY_CANFD_SCB_SCK_PIN            2
#define CY_CANFD_SCB_SCK_PIN_MUX        P7_2_SCB5_SPI_CLK
#define CY_CANFD_SCB_SS0_PORT           GPIO_PRT7
#define CY_CANFD_SCB_SS0_PIN            3
#define CY_CANFD_SCB_SS0_PIN_MUX        P7_3_SCB5_SPI_SELECT0
#define CY_CANFD_SCB_SS1_PORT           GPIO_PRT7
#define CY_CANFD_SCB_SS1_PIN            4
#define CY_CANFD_SCB_SS1_PIN_MUX        P7_4_SCB5_SPI_SELECT1
#define CY_CANFD_SCB_SS2_PORT           GPIO_PRT7
#define CY_CANFD_SCB_SS2_PIN            5
#define CY_CANFD_SCB_SS2_PIN_MUX        P7_5_SCB5_SPI_SELECT2
#define CY_CANFD_SCB_PCLK               PCLK_SCB5_CLOCK
#define CY_CANFD_SCB_IRQN               scb_5_interrupt_IRQn

/* EEPROM SPI Mux */
#define CY_EEPROM_SCB_TYPE              SCB1
#define CY_EEPROM_SCB_MISO_PORT         GPIO_PRT18
#define CY_EEPROM_SCB_MISO_PIN          0
#define CY_EEPROM_SCB_MISO_PIN_MUX      P18_0_SCB1_SPI_MISO
#define CY_EEPROM_SCB_MOSI_PORT         GPIO_PRT18
#define CY_EEPROM_SCB_MOSI_PIN          1
#define CY_EEPROM_SCB_MOSI_PIN_MUX      P18_1_SCB1_SPI_MOSI
#define CY_EEPROM_SCB_SCK_PORT          GPIO_PRT18
#define CY_EEPROM_SCB_SCK_PIN           2
#define CY_EEPROM_SCB_SCK_PIN_MUX       P18_2_SCB1_SPI_CLK
#define CY_EEPROM_SCB_SSEL_PORT         GPIO_PRT18
#define CY_EEPROM_SCB_SSEL_PIN          4
#define CY_EEPROM_SCB_SSEL_PIN_MUX      P18_4_SCB1_SPI_SELECT1
#define CY_EEPROM_SCB_SS_IDX            CY_SCB_SPI_SLAVE_SELECT1
#define CY_EEPROM_HOLD_PORT             GPIO_PRT18
#define CY_EEPROM_HOLD_PIN              5
#define CY_EEPROM_HOLD_PIN_MUX          P18_5_GPIO
#define CY_EEPROM_WP_PORT               GPIO_PRT17
#define CY_EEPROM_WP_PIN                2
#define CY_EEPROM_WP_PIN_MUX            P17_2_GPIO
#define CY_EEPROM_SCB_PCLK              PCLK_SCB1_CLOCK
#define CY_EEPROM_SCB_IRQN              scb_1_interrupt_IRQn
#define CY_EEPROM_SCB_SS                0

/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/

/* CANFD0_0/CAN0 Pin Mux */
#define CY_CANFD0_TYPE                  CY_CANFD0_0_TYPE
#define CY_CANFD0_RX_PORT               GPIO_PRT8
#define CY_CANFD0_RX_PIN                1
#define CY_CANFD0_RX_MUX                P8_1_CANFD0_TTCAN_RX0
#define CY_CANFD0_TX_PORT               GPIO_PRT8
#define CY_CANFD0_TX_PIN                0
#define CY_CANFD0_TX_MUX                P8_0_CANFD0_TTCAN_TX0
#define CY_CANFD0_PCLK                  PCLK_CANFD0_CLOCK_CAN0
#define CY_CANFD0_IRQN                  canfd_0_interrupts0_0_IRQn

/* CANFD0_1/CAN1 Pin Mux */
#define CY_CANFD1_TYPE                  CY_CANFD0_1_TYPE
#define CY_CANFD1_RX_PORT               GPIO_PRT0
#define CY_CANFD1_RX_PIN                3
#define CY_CANFD1_RX_MUX                P0_3_CANFD0_TTCAN_RX1
#define CY_CANFD1_TX_PORT               GPIO_PRT0
#define CY_CANFD1_TX_PIN                2
#define CY_CANFD1_TX_MUX                P0_2_CANFD0_TTCAN_TX1
#define CY_CANFD1_PCLK                  PCLK_CANFD0_CLOCK_CAN1
#define CY_CANFD1_IRQN                  canfd_0_interrupts0_1_IRQn

/* CANFD0_2/CAN2 Pin Mux */
#define CY_CANFD2_TYPE                  CY_CANFD0_2_TYPE
#define CY_CANFD2_RX_PORT               GPIO_PRT12
#define CY_CANFD2_RX_PIN                1
#define CY_CANFD2_RX_MUX                P12_1_CANFD0_TTCAN_RX2
#define CY_CANFD2_TX_PORT               GPIO_PRT12
#define CY_CANFD2_TX_PIN                0
#define CY_CANFD2_TX_MUX                P12_0_CANFD0_TTCAN_TX2
#define CY_CANFD2_PCLK                  PCLK_CANFD0_CLOCK_CAN2
#define CY_CANFD2_IRQN                  canfd_0_interrupts0_2_IRQn

/* CANFD1_0/CAN3 Pin Mux */
#define CY_CANFD3_TYPE                  CY_CANFD1_0_TYPE
#define CY_CANFD3_RX_PORT               GPIO_PRT14
#define CY_CANFD3_RX_PIN                1
#define CY_CANFD3_RX_MUX                P14_1_CANFD1_TTCAN_RX0
#define CY_CANFD3_TX_PORT               GPIO_PRT14
#define CY_CANFD3_TX_PIN                0
#define CY_CANFD3_TX_MUX                P14_0_CANFD1_TTCAN_TX0
#define CY_CANFD3_PCLK                  PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD3_IRQN                  canfd_1_interrupts0_0_IRQn

/* CANFD1_1/CAN4 Pin Mux */
#define CY_CANFD4_TYPE                  CY_CANFD1_1_TYPE
#define CY_CANFD4_RX_PORT               GPIO_PRT17
#define CY_CANFD4_RX_PIN                1
#define CY_CANFD4_RX_MUX                P17_1_CANFD1_TTCAN_RX1
#define CY_CANFD4_TX_PORT               GPIO_PRT17
#define CY_CANFD4_TX_PIN                0
#define CY_CANFD4_TX_MUX                P17_0_CANFD1_TTCAN_TX1
#define CY_CANFD4_PCLK                  PCLK_CANFD1_CLOCK_CAN1
#define CY_CANFD4_IRQN                  canfd_1_interrupts0_1_IRQn

/* CANFD1_2/CAN5 Pin Mux */
#define CY_CANFD5_TYPE                  CY_CANFD1_2_TYPE
#define CY_CANFD5_RX_PORT               GPIO_PRT18
#define CY_CANFD5_RX_PIN                7
#define CY_CANFD5_RX_MUX                P18_7_CANFD1_TTCAN_RX2
#define CY_CANFD5_TX_PORT               GPIO_PRT18
#define CY_CANFD5_TX_PIN                6
#define CY_CANFD5_TX_MUX                P18_6_CANFD1_TTCAN_TX2
#define CY_CANFD5_PCLK                  PCLK_CANFD1_CLOCK_CAN2
#define CY_CANFD5_IRQN                  canfd_1_interrupts0_2_IRQn

/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/* LIN Channel 0 */
#define CY_LINCH0_TYPE                  LIN0_CH0
#define CY_LINCH0_RX_PORT               GPIO_PRT21
#define CY_LINCH0_RX_PIN                5
#define CY_LINCH0_RX_PIN_MUX            P21_5_LIN0_LIN_RX0
#define CY_LINCH0_TX_PORT               GPIO_PRT2
#define CY_LINCH0_TX_PIN                1
#define CY_LINCH0_TX_PIN_MUX            P2_1_LIN0_LIN_TX0
#define CY_LINCH0_PCLK                  PCLK_LIN0_CLOCK_CH_EN0
#define CY_LINCH0_IRQN                  lin_0_interrupts_0_IRQn

/* LIN Channel 1 */
#define CY_LINCH1_TYPE                  LIN0_CH1
#define CY_LINCH1_RX_PORT               GPIO_PRT0
#define CY_LINCH1_RX_PIN                0
#define CY_LINCH1_RX_PIN_MUX            P0_0_LIN0_LIN_RX1
#define CY_LINCH1_TX_PORT               GPIO_PRT0
#define CY_LINCH1_TX_PIN                1
#define CY_LINCH1_TX_PIN_MUX            P0_1_LIN0_LIN_TX1
#define CY_LINCH1_PCLK                  PCLK_LIN0_CLOCK_CH_EN1
#define CY_LINCH1_IRQN                  lin_0_interrupts_1_IRQn

/* LIN Channel 2 */
#define CY_LINCH2_TYPE                  LIN0_CH2
#define CY_LINCH2_RX_PORT               GPIO_PRT5
#define CY_LINCH2_RX_PIN                3
#define CY_LINCH2_RX_PIN_MUX            P5_3_LIN0_LIN_RX2
#define CY_LINCH2_TX_PORT               GPIO_PRT8
#define CY_LINCH2_TX_PIN                1
#define CY_LINCH2_TX_PIN_MUX            P8_1_LIN0_LIN_TX2
#define CY_LINCH2_PCLK                  PCLK_LIN0_CLOCK_CH_EN2
#define CY_LINCH2_IRQN                  lin_0_interrupts_2_IRQn

/* LIN Channel 3 */
#define CY_LINCH3_TYPE                  LIN0_CH3
#define CY_LINCH3_RX_PORT               GPIO_PRT6
#define CY_LINCH3_RX_PIN                0
#define CY_LINCH3_RX_PIN_MUX            P6_0_LIN0_LIN_RX3
#define CY_LINCH3_TX_PORT               GPIO_PRT6
#define CY_LINCH3_TX_PIN                1
#define CY_LINCH3_TX_PIN_MUX            P6_1_LIN0_LIN_TX3
#define CY_LINCH3_PCLK                  PCLK_LIN0_CLOCK_CH_EN3
#define CY_LINCH3_IRQN                  lin_0_interrupts_3_IRQn

/* LIN Channel 4 */
#define CY_LINCH4_TYPE                  LIN0_CH4
#define CY_LINCH4_RX_PORT               GPIO_PRT6
#define CY_LINCH4_RX_PIN                3
#define CY_LINCH4_RX_PIN_MUX            P6_3_LIN0_LIN_RX4
#define CY_LINCH4_TX_PORT               GPIO_PRT6
#define CY_LINCH4_TX_PIN                4
#define CY_LINCH4_TX_PIN_MUX            P6_4_LIN0_LIN_TX4
#define CY_LINCH4_PCLK                  PCLK_LIN0_CLOCK_CH_EN4
#define CY_LINCH4_IRQN                  lin_0_interrupts_4_IRQn

/* LIN Channel 5 */
#define CY_LINCH5_TYPE                  LIN0_CH6
#define CY_LINCH5_RX_PORT               GPIO_PRT12
#define CY_LINCH5_RX_PIN                2
#define CY_LINCH5_RX_PIN_MUX            P12_2_LIN0_LIN_RX6
#define CY_LINCH5_TX_PORT               GPIO_PRT12
#define CY_LINCH5_TX_PIN                3
#define CY_LINCH5_TX_PIN_MUX            P12_3_LIN0_LIN_TX6
#define CY_LINCH5_PCLK                  PCLK_LIN0_CLOCK_CH_EN6
#define CY_LINCH5_IRQN                  lin_0_interrupts_6_IRQn


/******************************************************************************/
/*                      SMARTIO Base Board Mux                                */
/******************************************************************************/

#define CY_SMARTIO_MACRO                SMARTIO
#define CY_SMARTIO_PORT                 SMARTIO_PRT15
#define CY_SMARTIO_CLK                  PCLK_SMARTIO15_CLOCK

#define CY_SMARTIO_OUT_PORT             GPIO_PRT15 // YOTS: P15_1 is not existing. Please check.
#define CY_SMARTIO_OUT_PIN              1
#define CY_SMARTIO_OUT_PORT_MUX         P15_1_GPIO

#define CY_SMARTIO_IN_PORT              GPIO_PRT15 // YOTS: P15_0 is not existing. Please check.
#define CY_SMARTIO_IN_PIN               0
#define CY_SMARTIO_IN_PORT_MUX          P15_0_GPIO

/******************************************************************************/
/*                              EXT CLK PORT                                  */
/******************************************************************************/
#define HF1_CLK_OUT_PORT                        GPIO_PRT23
#define HF1_CLK_OUT_PIN                         (2ul)
#define HF1_CLK_OUT_PIN_MUX                     P21_2_SRSS_EXT_CLK

/******************************************************************************/
/******************************************************************************/
    
// tviibe1m - 80-LQFP Package devices
    
// #if (CY_USE_PSVP == 0) (--> Silicon), project setting CY_USE_PSVP should be changed to '0'
// select the supported or required device accordingly
    
#elif (CY_USE_PSVP == 0) && ( defined(CYT2B74BAS) || defined(CYT2B74BAE) || \
                              defined(CYT2B74CAS) || defined(CYT2B74CAE) )

// CPU Board Entities

// USER LED
#define CY_CB_LED_PORT                 	GPIO_PRT7
#define CY_CB_LED_PIN                   3
#define CY_CB_LED_PIN_MUX               P7_3_GPIO

// PUSH BUTTON
#define CY_CB_BUTTON_PORT              	GPIO_PRT8
#define CY_CB_BUTTON_PIN                2
#define CY_CB_BUTTON_PIN_MUX            P8_2_GPIO
#define CY_CB_BUTTON_IRQN               ioss_interrupts_gpio_8_IRQn

// BB Board Entities

/******************************************************************************/
/*                      LEDs Base Board Mux                                   */
/******************************************************************************/

#define CY_LED0_PORT                    GPIO_PRT2
#define CY_LED0_PIN                     2
#define CY_LED0_PIN_MUX                 P2_2_GPIO
  
#define CY_LED1_PORT                    GPIO_PRT2
#define CY_LED1_PIN                     3
#define CY_LED1_PIN_MUX                 P2_3_GPIO
  
#define CY_LED2_PORT                    GPIO_PRT5
#define CY_LED2_PIN                     0
#define CY_LED2_PIN_MUX                 P5_0_GPIO
  
#define CY_LED3_PORT                    GPIO_PRT5
#define CY_LED3_PIN                     1
#define CY_LED3_PIN_MUX                 P5_1_GPIO
  
#define CY_LED4_PORT                    GPIO_PRT5
#define CY_LED4_PIN                     2
#define CY_LED4_PIN_MUX                 P5_2_GPIO
  
#define CY_LED5_PORT                    GPIO_PRT5
#define CY_LED5_PIN                     3
#define CY_LED5_PIN_MUX                 P5_3_GPIO
  
#define CY_LED6_PORT                    GPIO_PRT6
#define CY_LED6_PIN                     5
#define CY_LED6_PIN_MUX                 P6_5_GPIO
  
#define CY_LED7_PORT                    GPIO_PRT19
#define CY_LED7_PIN                     0
#define CY_LED7_PIN_MUX                 P19_0_GPIO
  
#define CY_LED8_PORT                    GPIO_PRT19
#define CY_LED8_PIN                     1
#define CY_LED8_PIN_MUX                 P19_1_GPIO
  
#define CY_LED9_PORT                    GPIO_PRT23
#define CY_LED9_PIN                     3
#define CY_LED9_PIN_MUX                 P23_3_GPIO  

/******************************************************************************/
/*                      Buttons Base Board Mux                                */
/******************************************************************************/

#define CY_BUTTON1_PORT                 GPIO_PRT18
#define CY_BUTTON1_PIN                  2
#define CY_BUTTON1_PIN_MUX              P18_2_GPIO

#define CY_BUTTON2_PORT                 GPIO_PRT18
#define CY_BUTTON2_PIN                  1
#define CY_BUTTON2_PIN_MUX              P18_1_GPIO
  
#define CY_BUTTON3_PORT                 GPIO_PRT18
#define CY_BUTTON3_PIN                  0
#define CY_BUTTON3_PIN_MUX              P18_0_GPIO
  
#define CY_BUTTON4_PORT                 GPIO_PRT13
#define CY_BUTTON4_PIN                  7
#define CY_BUTTON4_PIN_MUX              P13_7_GPIO
  
#define CY_BUTTON5_PORT                 GPIO_PRT13
#define CY_BUTTON5_PIN                  2
#define CY_BUTTON5_PIN_MUX              P13_2_GPIO

/* Setup GPIO for BUTTONs 1/2/3/5 interrupt sources */
#define CY_BUTTON1_IRQN			ioss_interrupts_gpio_18_IRQn
#define CY_BUTTON2_IRQN			ioss_interrupts_gpio_18_IRQn
#define CY_BUTTON3_IRQN			ioss_interrupts_gpio_18_IRQn
#define CY_BUTTON4_IRQN			ioss_interrupts_gpio_13_IRQn
#define CY_BUTTON5_IRQN			ioss_interrupts_gpio_13_IRQn

/******************************************************************************/
/*                      ADC POT                                	              */
/******************************************************************************/

#define CY_ADC_POT_MACRO                PASS0_SAR2
#define CY_ADC_POT_IN_NO               0
#define CY_ADC_POT_PORT                 GPIO_PRT18
#define CY_ADC_POT_PIN                  0
#define CY_ADC_POT_PIN_MUX              P18_0_GPIO
#define CY_ADC_POT_PCLK                 PCLK_PASS0_CLOCK_SAR2
#define CY_ADC_POT_IRQN                 pass_0_interrupts_sar_64_IRQn

/******************************************************************************/
/*                      SCB-UART Base Board Mux                               */
/******************************************************************************/
  
/* USB-UART Mux */
#define CY_USB_SCB_TYPE                 SCB3
#define CY_USB_SCB_UART_RX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_RX_PIN          0
#define CY_USB_SCB_UART_RX_MUX          P13_0_SCB3_UART_RX
#define CY_USB_SCB_UART_TX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_TX_PIN          1
#define CY_USB_SCB_UART_TX_MUX          P13_1_SCB3_UART_TX
#define CY_USB_SCB_UART_PCLK            PCLK_SCB3_CLOCK
#define CY_USB_SCB_UART_IRQN            scb_3_interrupt_IRQn  
  
/* CANFD-SPI Mux */
#define CY_CANFD_SCB_TYPE               SCB4
#define CY_CANFD_SCB_MOSI_PORT          GPIO_PRT6
#define CY_CANFD_SCB_MOSI_PIN           1
#define CY_CANFD_SCB_MOSI_PIN_MUX       P6_1_SCB4_SPI_MOSI
#define CY_CANFD_SCB_MISO_PORT          GPIO_PRT6
#define CY_CANFD_SCB_MISO_PIN           0
#define CY_CANFD_SCB_MISO_PIN_MUX       P6_0_SCB4_SPI_MISO
#define CY_CANFD_SCB_SCK_PORT           GPIO_PRT6
#define CY_CANFD_SCB_SCK_PIN            2
#define CY_CANFD_SCB_SCK_PIN_MUX        P6_2_SCB4_SPI_CLK
#define CY_CANFD_SCB_SS0_PORT           GPIO_PRT6
#define CY_CANFD_SCB_SS0_PIN            3
#define CY_CANFD_SCB_SS0_PIN_MUX        P6_3_SCB4_SPI_SELECT0
#define CY_CANFD_SCB_SS1_PORT           GPIO_PRT6
#define CY_CANFD_SCB_SS1_PIN            4
#define CY_CANFD_SCB_SS1_PIN_MUX        P6_4_SCB4_SPI_SELECT1
#define CY_CANFD_SCB_SS2_PORT           GPIO_PRT6
#define CY_CANFD_SCB_SS2_PIN            5
#define CY_CANFD_SCB_SS2_PIN_MUX        P6_5_SCB4_SPI_SELECT2
#define CY_CANFD_SCB_PCLK               PCLK_SCB4_CLOCK
#define CY_CANFD_SCB_IRQN               scb_4_interrupt_IRQn

/* EEPROM SPI Mux */
#define CY_EEPROM_SCB_TYPE              SCB5
#define CY_EEPROM_SCB_MISO_PORT         GPIO_PRT7
#define CY_EEPROM_SCB_MISO_PIN          0
#define CY_EEPROM_SCB_MISO_PIN_MUX      P7_0_SCB5_SPI_MISO
#define CY_EEPROM_SCB_MOSI_PORT         GPIO_PRT7
#define CY_EEPROM_SCB_MOSI_PIN          1
#define CY_EEPROM_SCB_MOSI_PIN_MUX      P7_1_SCB5_SPI_MOSI
#define CY_EEPROM_SCB_SCK_PORT          GPIO_PRT7
#define CY_EEPROM_SCB_SCK_PIN           2
#define CY_EEPROM_SCB_SCK_PIN_MUX       P7_2_SCB5_SPI_CLK
#define CY_EEPROM_SCB_SSEL_PORT         GPIO_PRT5
#define CY_EEPROM_SCB_SSEL_PIN          0
#define CY_EEPROM_SCB_SSEL_PIN_MUX      P5_0_SCB5_SPI_SELECT2
#define CY_EEPROM_SCB_SS_IDX            CY_SCB_SPI_SLAVE_SELECT2
#define CY_EEPROM_SCB_PCLK              PCLK_SCB5_CLOCK
#define CY_EEPROM_SCB_IRQN              scb_5_interrupt_IRQn
#define CY_EEPROM_SCB_SS                2

/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/
  
/* CANFD0_0/CAN0 Pin Mux */
#define CY_CANFD0_TYPE                  CY_CANFD0_0_TYPE
#define CY_CANFD0_RX_PORT               GPIO_PRT8
#define CY_CANFD0_RX_PIN                1
#define CY_CANFD0_RX_MUX                P8_1_CANFD0_TTCAN_RX0
#define CY_CANFD0_TX_PORT               GPIO_PRT8
#define CY_CANFD0_TX_PIN                0
#define CY_CANFD0_TX_MUX                P8_0_CANFD0_TTCAN_TX0
#define CY_CANFD0_PCLK                  PCLK_CANFD0_CLOCK_CAN0
#define CY_CANFD0_IRQN                  canfd_0_interrupts0_0_IRQn
  
/* CANFD0_1/CAN1 Pin Mux */
#define CY_CANFD1_TYPE                  CY_CANFD0_1_TYPE
#define CY_CANFD1_RX_PORT               GPIO_PRT0
#define CY_CANFD1_RX_PIN                3
#define CY_CANFD1_RX_MUX                P0_3_CANFD0_TTCAN_RX1
#define CY_CANFD1_TX_PORT               GPIO_PRT0
#define CY_CANFD1_TX_PIN                2
#define CY_CANFD1_TX_MUX                P0_2_CANFD0_TTCAN_TX1
#define CY_CANFD1_PCLK                  PCLK_CANFD0_CLOCK_CAN1
#define CY_CANFD1_IRQN                  canfd_0_interrupts0_1_IRQn
  
/* CANFD0_2/CAN2 Pin Mux */
#define CY_CANFD2_TYPE                  CY_CANFD0_2_TYPE
#define CY_CANFD2_RX_PORT               GPIO_PRT12
#define CY_CANFD2_RX_PIN                1
#define CY_CANFD2_RX_MUX                P12_1_CANFD0_TTCAN_RX2
#define CY_CANFD2_TX_PORT               GPIO_PRT12
#define CY_CANFD2_TX_PIN                0
#define CY_CANFD2_TX_MUX                P12_0_CANFD0_TTCAN_TX2
#define CY_CANFD2_PCLK                  PCLK_CANFD0_CLOCK_CAN2
#define CY_CANFD2_IRQN                  canfd_0_interrupts0_2_IRQn
  
/* CANFD1_0/CAN3 Pin Mux */
#define CY_CANFD3_TYPE                  CY_CANFD1_0_TYPE
#define CY_CANFD3_RX_PORT               GPIO_PRT14
#define CY_CANFD3_RX_PIN                1
#define CY_CANFD3_RX_MUX                P14_1_CANFD1_TTCAN_RX0
#define CY_CANFD3_TX_PORT               GPIO_PRT14
#define CY_CANFD3_TX_PIN                0
#define CY_CANFD3_TX_MUX                P14_0_CANFD1_TTCAN_TX0
#define CY_CANFD3_PCLK                  PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD3_IRQN                  canfd_1_interrupts0_0_IRQn

/* CANFD1_1/CAN4 Pin Mux */
#define CY_CANFD4_TYPE                  CY_CANFD1_1_TYPE
#define CY_CANFD4_RX_PORT               GPIO_PRT22
#define CY_CANFD4_RX_PIN                1
#define CY_CANFD4_RX_MUX                P22_1_CANFD1_TTCAN_RX1
#define CY_CANFD4_TX_PORT               GPIO_PRT22
#define CY_CANFD4_TX_PIN                0
#define CY_CANFD4_TX_MUX                P22_0_CANFD1_TTCAN_TX1
#define CY_CANFD4_PCLK                  PCLK_CANFD1_CLOCK_CAN1
#define CY_CANFD4_IRQN                  canfd_1_interrupts0_1_IRQn
  
/* CANFD1_2/CAN5 Pin Mux */
#define CY_CANFD5_TYPE                  CY_CANFD1_2_TYPE
#define CY_CANFD5_RX_PORT               GPIO_PRT18
#define CY_CANFD5_RX_PIN                7
#define CY_CANFD5_RX_MUX                P18_7_CANFD1_TTCAN_RX2
#define CY_CANFD5_TX_PORT               GPIO_PRT18
#define CY_CANFD5_TX_PIN                6
#define CY_CANFD5_TX_MUX                P18_6_CANFD1_TTCAN_TX2
#define CY_CANFD5_PCLK                  PCLK_CANFD1_CLOCK_CAN2
#define CY_CANFD5_IRQN                  canfd_1_interrupts0_2_IRQn
  
/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/* LIN Channel 0 */
#define CY_LINCH0_TYPE                  LIN0_CH0
#define CY_LINCH0_RX_PORT               GPIO_PRT2
#define CY_LINCH0_RX_PIN                0
#define CY_LINCH0_RX_PIN_MUX            P2_0_LIN0_LIN_RX0
#define CY_LINCH0_TX_PORT               GPIO_PRT2
#define CY_LINCH0_TX_PIN                1
#define CY_LINCH0_TX_PIN_MUX            P2_1_LIN0_LIN_TX0
#define CY_LINCH0_PCLK                  PCLK_LIN0_CLOCK_CH_EN0
#define CY_LINCH0_IRQN                  lin_0_interrupts_0_IRQn
  
/* LIN Channel 1 */
#define CY_LINCH1_TYPE                  LIN0_CH1
#define CY_LINCH1_RX_PORT               GPIO_PRT0
#define CY_LINCH1_RX_PIN                0
#define CY_LINCH1_RX_PIN_MUX            P0_0_LIN0_LIN_RX1
#define CY_LINCH1_TX_PORT               GPIO_PRT0
#define CY_LINCH1_TX_PIN                1
#define CY_LINCH1_TX_PIN_MUX            P0_1_LIN0_LIN_TX1
#define CY_LINCH1_PCLK                  PCLK_LIN0_CLOCK_CH_EN1
#define CY_LINCH1_IRQN                  lin_0_interrupts_1_IRQn

/* LIN Channel 2 */
#define CY_LINCH2_TYPE                  LIN0_CH2
#define CY_LINCH2_RX_PORT               GPIO_PRT8
#define CY_LINCH2_RX_PIN                0
#define CY_LINCH2_RX_PIN_MUX            P8_0_LIN0_LIN_RX2
#define CY_LINCH2_TX_PORT               GPIO_PRT8
#define CY_LINCH2_TX_PIN                1
#define CY_LINCH2_TX_PIN_MUX            P8_1_LIN0_LIN_TX2
#define CY_LINCH2_PCLK                  PCLK_LIN0_CLOCK_CH_EN2
#define CY_LINCH2_IRQN                  lin_0_interrupts_2_IRQn

/* LIN Channel 3 */
#define CY_LINCH3_TYPE                  LIN0_CH3
#define CY_LINCH3_RX_PORT               GPIO_PRT6
#define CY_LINCH3_RX_PIN                0
#define CY_LINCH3_RX_PIN_MUX            P6_0_LIN0_LIN_RX3
#define CY_LINCH3_TX_PORT               GPIO_PRT6
#define CY_LINCH3_TX_PIN                1
#define CY_LINCH3_TX_PIN_MUX            P6_1_LIN0_LIN_TX3
#define CY_LINCH3_PCLK                  PCLK_LIN0_CLOCK_CH_EN3
#define CY_LINCH3_IRQN                  lin_0_interrupts_3_IRQn

/* LIN Channel 4 */
#define CY_LINCH4_TYPE                  LIN0_CH4
#define CY_LINCH4_RX_PORT               GPIO_PRT7
#define CY_LINCH4_RX_PIN                0
#define CY_LINCH4_RX_PIN_MUX            P7_0_LIN0_LIN_RX4
#define CY_LINCH4_TX_PORT               GPIO_PRT7
#define CY_LINCH4_TX_PIN                1
#define CY_LINCH4_TX_PIN_MUX            P7_1_LIN0_LIN_TX4
#define CY_LINCH4_PCLK                  PCLK_LIN0_CLOCK_CH_EN4
#define CY_LINCH4_IRQN                  lin_0_interrupts_4_IRQn

/* LIN Channel 5 */
#define CY_LINCH5_TYPE                  LIN0_CH6
#define CY_LINCH5_RX_PORT               GPIO_PRT12
#define CY_LINCH5_RX_PIN                2
#define CY_LINCH5_RX_PIN_MUX            P12_2_LIN0_LIN_RX6
#define CY_LINCH5_TX_PORT               GPIO_PRT12
#define CY_LINCH5_TX_PIN                3
#define CY_LINCH5_TX_PIN_MUX            P12_3_LIN0_LIN_TX6
#define CY_LINCH5_PCLK                  PCLK_LIN0_CLOCK_CH_EN5
#define CY_LINCH5_IRQN                  lin_0_interrupts_6_IRQn


/******************************************************************************/
/*                      SMARTIO Base Board Mux                                */
/******************************************************************************/

#define CY_SMARTIO_MACRO                SMARTIO
#define CY_SMARTIO_PORT                 SMARTIO_PRT15
#define CY_SMARTIO_CLK                  PCLK_SMARTIO15_CLOCK

#define CY_SMARTIO_OUT_PORT             GPIO_PRT15 // YOTS: P15_1 is not existing. Please check.
#define CY_SMARTIO_OUT_PIN              1
#define CY_SMARTIO_OUT_PORT_MUX         P15_1_GPIO

#define CY_SMARTIO_IN_PORT              GPIO_PRT15 // YOTS: P15_0 is not existing. Please check.
#define CY_SMARTIO_IN_PIN               0
#define CY_SMARTIO_IN_PORT_MUX          P15_0_GPIO

/******************************************************************************/
/*                              EXT CLK PORT                                  */
/******************************************************************************/
#define HF1_CLK_OUT_PORT                        GPIO_PRT23
#define HF1_CLK_OUT_PIN                         (2ul)
#define HF1_CLK_OUT_PIN_MUX                     P21_2_SRSS_EXT_CLK

/******************************************************************************/
/******************************************************************************/
    
// tviibe1m - 64-LQFP Package devices
    
// #if (CY_USE_PSVP == 0) (--> Silicon), project setting CY_USE_PSVP should be changed to '0'
// select the supported or required device accordingly
    
#elif (CY_USE_PSVP == 0) && ( defined(CYT2B73BAS) || defined(CYT2B73BAE) || \
                              defined(CYT2B73CAS) || defined(CYT2B73CAE) )

// CPU Board Entities

// USER LED
#define CY_CB_LED_PORT                 	GPIO_PRT6
#define CY_CB_LED_PIN                   4
#define CY_CB_LED_PIN_MUX               P6_4_GPIO

// PUSH BUTTON
#define CY_CB_BUTTON_PORT              	GPIO_PRT6
#define CY_CB_BUTTON_PIN                3
#define CY_CB_BUTTON_PIN_MUX            P6_3_GPIO
#define CY_CB_BUTTON_IRQN               ioss_interrupts_gpio_6_IRQn

// BB Board Entities

/******************************************************************************/
/*                      LEDs Base Board Mux                                   */
/******************************************************************************/

#define CY_LED0_PORT                    GPIO_PRT6
#define CY_LED0_PIN                     5
#define CY_LED0_PIN_MUX                 P6_5_GPIO
  
#define CY_LED1_PORT                    GPIO_PRT6
#define CY_LED1_PIN                     6
#define CY_LED1_PIN_MUX                 P6_6_GPIO
  
#define CY_LED2_PORT                    GPIO_PRT7
#define CY_LED2_PIN                     0
#define CY_LED2_PIN_MUX                 P7_0_GPIO
  
#define CY_LED3_PORT                    GPIO_PRT7
#define CY_LED3_PIN                     1
#define CY_LED3_PIN_MUX                 P7_1_GPIO
  
#define CY_LED4_PORT                    GPIO_PRT7
#define CY_LED4_PIN                     2
#define CY_LED4_PIN_MUX                 P7_2_GPIO
  
#define CY_LED5_PORT                    GPIO_PRT12
#define CY_LED5_PIN                     0
#define CY_LED5_PIN_MUX                 P12_0_GPIO
  
#define CY_LED6_PORT                    GPIO_PRT12
#define CY_LED6_PIN                     1
#define CY_LED6_PIN_MUX                 P12_1_GPIO
  
#define CY_LED7_PORT                    GPIO_PRT14
#define CY_LED7_PIN                     2
#define CY_LED7_PIN_MUX                 P14_2_GPIO
  
#define CY_LED8_PORT                    GPIO_PRT18
#define CY_LED8_PIN                     0
#define CY_LED8_PIN_MUX                 P18_0_GPIO
  
#define CY_LED9_PORT                    GPIO_PRT18
#define CY_LED9_PIN                     1
#define CY_LED9_PIN_MUX                 P18_1_GPIO  

/******************************************************************************/
/*                      Buttons Base Board Mux                                */
/******************************************************************************/

#define CY_BUTTON1_PORT                 GPIO_PRT0
#define CY_BUTTON1_PIN                  0
#define CY_BUTTON1_PIN_MUX              P0_0_GPIO

#define CY_BUTTON2_PORT                 GPIO_PRT0
#define CY_BUTTON2_PIN                  1
#define CY_BUTTON2_PIN_MUX              P0_1_GPIO
  
#define CY_BUTTON3_PORT                 GPIO_PRT8
#define CY_BUTTON3_PIN                  0
#define CY_BUTTON3_PIN_MUX              P8_0_GPIO
  
#define CY_BUTTON4_PORT                 GPIO_PRT8
#define CY_BUTTON4_PIN                  1
#define CY_BUTTON4_PIN_MUX              P8_1_GPIO
  
#define CY_BUTTON5_PORT                 GPIO_PRT18
#define CY_BUTTON5_PIN                  4
#define CY_BUTTON5_PIN_MUX              P18_4_GPIO

/* Setup GPIO for BUTTONs 1/2/3/5 interrupt sources */
#define CY_BUTTON1_IRQN			ioss_interrupts_gpio_0_IRQn
#define CY_BUTTON2_IRQN			ioss_interrupts_gpio_0_IRQn
#define CY_BUTTON3_IRQN			ioss_interrupts_gpio_8_IRQn
#define CY_BUTTON4_IRQN			ioss_interrupts_gpio_8_IRQn
#define CY_BUTTON5_IRQN			ioss_interrupts_gpio_18_IRQn

/******************************************************************************/
/*                      ADC POT                                	              */
/******************************************************************************/

#define CY_ADC_POT_MACRO                PASS0_SAR0
#define CY_ADC_POT_IN_NO               0
#define CY_ADC_POT_PORT                 GPIO_PRT6
#define CY_ADC_POT_PIN                  0
#define CY_ADC_POT_PIN_MUX              P6_1_GPIO
#define CY_ADC_POT_PCLK                 PCLK_PASS0_CLOCK_SAR0
#define CY_ADC_POT_IRQN                 pass_0_interrupts_sar_0_IRQn

/******************************************************************************/
/*                      SCB-UART Base Board Mux                               */
/******************************************************************************/
  
/* USB-UART Mux */
#define CY_USB_SCB_TYPE                 SCB3
#define CY_USB_SCB_UART_RX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_RX_PIN          0
#define CY_USB_SCB_UART_RX_MUX          P13_0_SCB3_UART_RX
#define CY_USB_SCB_UART_TX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_TX_PIN          1
#define CY_USB_SCB_UART_TX_MUX          P13_1_SCB3_UART_TX
#define CY_USB_SCB_UART_PCLK            PCLK_SCB3_CLOCK
#define CY_USB_SCB_UART_IRQN            scb_3_interrupt_IRQn  
  
/* CANFD-SPI Mux */
#define CY_CANFD_SCB_TYPE               SCB4
#define CY_CANFD_SCB_MOSI_PORT          GPIO_PRT6
#define CY_CANFD_SCB_MOSI_PIN           1
#define CY_CANFD_SCB_MOSI_PIN_MUX       P6_1_SCB4_SPI_MOSI
#define CY_CANFD_SCB_MISO_PORT          GPIO_PRT6
#define CY_CANFD_SCB_MISO_PIN           0
#define CY_CANFD_SCB_MISO_PIN_MUX       P6_0_SCB4_SPI_MISO
#define CY_CANFD_SCB_SCK_PORT           GPIO_PRT6
#define CY_CANFD_SCB_SCK_PIN            2
#define CY_CANFD_SCB_SCK_PIN_MUX        P6_2_SCB4_SPI_CLK
#define CY_CANFD_SCB_SS0_PORT           GPIO_PRT6
#define CY_CANFD_SCB_SS0_PIN            3
#define CY_CANFD_SCB_SS0_PIN_MUX        P6_3_SCB4_SPI_SELECT0
#define CY_CANFD_SCB_SS1_PORT           GPIO_PRT6
#define CY_CANFD_SCB_SS1_PIN            4
#define CY_CANFD_SCB_SS1_PIN_MUX        P6_4_SCB4_SPI_SELECT1
#define CY_CANFD_SCB_SS2_PORT           GPIO_PRT6
#define CY_CANFD_SCB_SS2_PIN            5
#define CY_CANFD_SCB_SS2_PIN_MUX        P6_5_SCB4_SPI_SELECT2
#define CY_CANFD_SCB_PCLK               PCLK_SCB4_CLOCK
#define CY_CANFD_SCB_IRQN               scb_4_interrupt_IRQn

/* EEPROM SPI Mux */
#define CY_EEPROM_SCB_TYPE              SCB5
#define CY_EEPROM_SCB_MISO_PORT         GPIO_PRT7
#define CY_EEPROM_SCB_MISO_PIN          0
#define CY_EEPROM_SCB_MISO_PIN_MUX      P7_0_SCB5_SPI_MISO
#define CY_EEPROM_SCB_MOSI_PORT         GPIO_PRT7
#define CY_EEPROM_SCB_MOSI_PIN          1
#define CY_EEPROM_SCB_MOSI_PIN_MUX      P7_1_SCB5_SPI_MOSI
#define CY_EEPROM_SCB_SCK_PORT          GPIO_PRT7
#define CY_EEPROM_SCB_SCK_PIN           2
#define CY_EEPROM_SCB_SCK_PIN_MUX       P7_2_SCB5_SPI_CLK
#define CY_EEPROM_SCB_SSEL_PORT         GPIO_PRT5
#define CY_EEPROM_SCB_SSEL_PIN          0
#define CY_EEPROM_SCB_SSEL_PIN_MUX      P5_0_SCB5_SPI_SELECT2
#define CY_EEPROM_SCB_SS_IDX            CY_SCB_SPI_SLAVE_SELECT2
#define CY_EEPROM_HOLD_PORT             GPIO_PRT13
#define CY_EEPROM_HOLD_PIN              3
#define CY_EEPROM_HOLD_PIN_MUX          P13_3_GPIO
#define CY_EEPROM_WP_PORT               GPIO_PRT13
#define CY_EEPROM_WP_PIN                2
#define CY_EEPROM_WP_PIN_MUX            P13_2_GPIO
#define CY_EEPROM_SCB_PCLK              PCLK_SCB5_CLOCK
#define CY_EEPROM_SCB_IRQN              scb_5_interrupt_IRQn
#define CY_EEPROM_SCB_SS                2

/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/
  
/* CAN0 Pin Mux */
#define CY_CANFD0_TYPE                  CY_CANFD0_0_TYPE
#define CY_CANFD0_RX_PORT               GPIO_PRT8
#define CY_CANFD0_RX_PIN                1
#define CY_CANFD0_RX_MUX                P8_1_CANFD0_TTCAN_RX0
#define CY_CANFD0_TX_PORT               GPIO_PRT8
#define CY_CANFD0_TX_PIN                0
#define CY_CANFD0_TX_MUX                P8_0_CANFD0_TTCAN_TX0
#define CY_CANFD0_PCLK                  PCLK_CANFD0_CLOCK_CAN0
#define CY_CANFD0_IRQN                  canfd_0_interrupts0_0_IRQn
  
/* CAN1 Pin Mux */
#define CY_CANFD1_TYPE                  CY_CANFD0_1_TYPE
#define CY_CANFD1_RX_PORT               GPIO_PRT0
#define CY_CANFD1_RX_PIN                3
#define CY_CANFD1_RX_MUX                P0_3_CANFD0_TTCAN_RX1
#define CY_CANFD1_TX_PORT               GPIO_PRT0
#define CY_CANFD1_TX_PIN                2
#define CY_CANFD1_TX_MUX                P0_2_CANFD0_TTCAN_TX1
#define CY_CANFD1_PCLK                  PCLK_CANFD0_CLOCK_CAN1
#define CY_CANFD1_IRQN                  canfd_0_interrupts0_1_IRQn
  
/* CAN2 Pin Mux */
#define CY_CANFD2_TYPE                  CY_CANFD0_2_TYPE
#define CY_CANFD2_RX_PORT               GPIO_PRT12
#define CY_CANFD2_RX_PIN                1
#define CY_CANFD2_RX_MUX                P12_1_CANFD0_TTCAN_RX2
#define CY_CANFD2_TX_PORT               GPIO_PRT12
#define CY_CANFD2_TX_PIN                0
#define CY_CANFD2_TX_MUX                P12_0_CANFD0_TTCAN_TX2
#define CY_CANFD2_PCLK                  PCLK_CANFD0_CLOCK_CAN2
#define CY_CANFD2_IRQN                  canfd_0_interrupts0_2_IRQn
  
/* CAN3 Pin Mux */
#define CY_CANFD3_TYPE                  CY_CANFD1_0_TYPE
#define CY_CANFD3_RX_PORT               GPIO_PRT14
#define CY_CANFD3_RX_PIN                1
#define CY_CANFD3_RX_MUX                P14_1_CANFD1_TTCAN_RX0
#define CY_CANFD3_TX_PORT               GPIO_PRT14
#define CY_CANFD3_TX_PIN                0
#define CY_CANFD3_TX_MUX                P14_0_CANFD1_TTCAN_TX0
#define CY_CANFD3_PCLK                  PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD3_IRQN                  canfd_1_interrupts0_0_IRQn
  
/* CAN5 Pin Mux */
#define CY_CANFD5_TYPE                  CY_CANFD1_2_TYPE
#define CY_CANFD5_RX_PORT               GPIO_PRT18
#define CY_CANFD5_RX_PIN                7
#define CY_CANFD5_RX_MUX                P18_7_CANFD1_TTCAN_RX2
#define CY_CANFD5_TX_PORT               GPIO_PRT18
#define CY_CANFD5_TX_PIN                6
#define CY_CANFD5_TX_MUX                P18_6_CANFD1_TTCAN_TX2
#define CY_CANFD5_PCLK                  PCLK_CANFD1_CLOCK_CAN2
#define CY_CANFD5_IRQN                  canfd_1_interrupts0_2_IRQn
  
/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/* LIN Channel 0 */
#define CY_LINCH0_TYPE                  LIN0_CH0
#define CY_LINCH0_RX_PORT               GPIO_PRT2
#define CY_LINCH0_RX_PIN                0
#define CY_LINCH0_RX_PIN_MUX            P2_0_LIN0_LIN_RX0
#define CY_LINCH0_TX_PORT               GPIO_PRT2
#define CY_LINCH0_TX_PIN                1
#define CY_LINCH0_TX_PIN_MUX            P2_1_LIN0_LIN_TX0
#define CY_LINCH0_PCLK                  PCLK_LIN0_CLOCK_CH_EN0
#define CY_LINCH0_IRQN                  lin_0_interrupts_0_IRQn
  
/* LIN Channel 1 */
#define CY_LINCH1_TYPE                  LIN0_CH1
#define CY_LINCH1_RX_PORT               GPIO_PRT0
#define CY_LINCH1_RX_PIN                0
#define CY_LINCH1_RX_PIN_MUX            P0_0_LIN0_LIN_RX1
#define CY_LINCH1_TX_PORT               GPIO_PRT0
#define CY_LINCH1_TX_PIN                1
#define CY_LINCH1_TX_PIN_MUX            P0_1_LIN0_LIN_TX1
#define CY_LINCH1_PCLK                  PCLK_LIN0_CLOCK_CH_EN1
#define CY_LINCH1_IRQN                  lin_0_interrupts_1_IRQn

/* LIN Channel 2 */
#define CY_LINCH2_TYPE                  LIN0_CH2
#define CY_LINCH2_RX_PORT               GPIO_PRT8
#define CY_LINCH2_RX_PIN                0
#define CY_LINCH2_RX_PIN_MUX            P8_0_LIN0_LIN_RX2
#define CY_LINCH2_TX_PORT               GPIO_PRT8
#define CY_LINCH2_TX_PIN                1
#define CY_LINCH2_TX_PIN_MUX            P8_1_LIN0_LIN_TX2
#define CY_LINCH2_PCLK                  PCLK_LIN0_CLOCK_CH_EN2
#define CY_LINCH2_IRQN                  lin_0_interrupts_2_IRQn

/* LIN Channel 3 */
#define CY_LINCH3_TYPE                  LIN0_CH3
#define CY_LINCH3_RX_PORT               GPIO_PRT6
#define CY_LINCH3_RX_PIN                0
#define CY_LINCH3_RX_PIN_MUX            P6_0_LIN0_LIN_RX3
#define CY_LINCH3_TX_PORT               GPIO_PRT6
#define CY_LINCH3_TX_PIN                1
#define CY_LINCH3_TX_PIN_MUX            P6_1_LIN0_LIN_TX3
#define CY_LINCH3_PCLK                  PCLK_LIN0_CLOCK_CH_EN3
#define CY_LINCH3_IRQN                  lin_0_interrupts_3_IRQn

/* LIN Channel 4 */
#define CY_LINCH4_TYPE                  LIN0_CH4
#define CY_LINCH4_RX_PORT               GPIO_PRT7
#define CY_LINCH4_RX_PIN                0
#define CY_LINCH4_RX_PIN_MUX            P7_0_LIN0_LIN_RX4
#define CY_LINCH4_TX_PORT               GPIO_PRT7
#define CY_LINCH4_TX_PIN                1
#define CY_LINCH4_TX_PIN_MUX            P7_1_LIN0_LIN_TX4
#define CY_LINCH4_PCLK                  PCLK_LIN0_CLOCK_CH_EN4
#define CY_LINCH4_IRQN                  lin_0_interrupts_4_IRQn

/* LIN Channel 5 */
#define CY_LINCH5_TYPE                  LIN0_CH7
#define CY_LINCH5_RX_PORT               GPIO_PRT5
#define CY_LINCH5_RX_PIN                0
#define CY_LINCH5_RX_PIN_MUX            P5_0_LIN0_LIN_RX7
#define CY_LINCH5_TX_PORT               GPIO_PRT5
#define CY_LINCH5_TX_PIN                1
#define CY_LINCH5_TX_PIN_MUX            P5_1_LIN0_LIN_TX7
#define CY_LINCH5_PCLK                  PCLK_LIN0_CLOCK_CH_EN7
#define CY_LINCH5_IRQN                  lin_0_interrupts_7_IRQn


/******************************************************************************/
/*                      SMARTIO Base Board Mux                                */
/******************************************************************************/

#define CY_SMARTIO_MACRO                SMARTIO
#define CY_SMARTIO_PORT                 SMARTIO_PRT15
#define CY_SMARTIO_CLK                  PCLK_SMARTIO15_CLOCK

#define CY_SMARTIO_OUT_PORT             GPIO_PRT15 // YOTS: P15_1 is not existing. Please check.
#define CY_SMARTIO_OUT_PIN              1
#define CY_SMARTIO_OUT_PORT_MUX         P15_1_GPIO

#define CY_SMARTIO_IN_PORT              GPIO_PRT15 // YOTS: P15_0 is not existing. Please check.
#define CY_SMARTIO_IN_PIN               0
#define CY_SMARTIO_IN_PORT_MUX          P15_0_GPIO

/******************************************************************************/
/*                              EXT CLK PORT                                  */
/******************************************************************************/
#define HF1_CLK_OUT_PORT                        GPIO_PRT23
#define HF1_CLK_OUT_PIN                         (2ul)
#define HF1_CLK_OUT_PIN_MUX                     P21_2_SRSS_EXT_CLK

/******************************************************************************/
/******************************************************************************/
    
#else // No Device or PSVP Selected
    
    #error "Choose either a Device based on TVII-B-E-1M Datasheet or CY_USE_PSVP"
    
#endif // #if (CY_USE_PSVP == 1)
  
  
#ifdef __cplusplus
}
#endif

#endif /* BB_BSP_TVIIBE1M_REVC_H */

/* [] END OF FILE */
