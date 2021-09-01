/***************************************************************************//**
* \file bb_bsp_tvic2d6m.h
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

#ifndef BB_BSP_TVIIC2D4M_H
#define BB_BSP_TVIIC2D4M_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/******************************************************************************/

// PSVP supports only 272-bga package

#if (CY_USE_PSVP == 1) && defined(CYT3DLBBHS)
  
// Adapter Board Entities

/******************************************************************************/
/*                      USER LED AB Mux (GPIO_133)                            */
/******************************************************************************/
#define CY_AB_LED_PORT                  GPIO_PRT4
#define CY_AB_LED_PIN                   4
#define CY_AB_LED_PIN_MUX               P4_4_GPIO

/******************************************************************************/
/*                      Button AB Mux (GPIO_134)                              */
/******************************************************************************/
#define CY_AB_BUTTON_PORT               GPIO_PRT5
#define CY_AB_BUTTON_PIN                2
#define CY_AB_BUTTON_PIN_MUX            P5_2_GPIO

/* Setup GPIO for BUTTON AB interrupt sources */
#define CY_AB_BUTTON_IRQN               ioss_interrupts_gpio_dpslp_5_IRQn

/******************************************************************************/
/*                      SCB AB Mux                                            */
/******************************************************************************/
/* USB-UART Mux */
#define CY_USB_SCB_TYPE                 SCB0
#define CY_USB_SCB_UART_RX_PORT         GPIO_PRT5
#define CY_USB_SCB_UART_RX_PIN          0
#define CY_USB_SCB_UART_RX_MUX          P5_0_SCB0_UART_RX
#define CY_USB_SCB_UART_TX_PORT         GPIO_PRT5
#define CY_USB_SCB_UART_TX_PIN          1
#define CY_USB_SCB_UART_TX_MUX          P5_1_SCB0_UART_TX
#define CY_USB_SCB_UART_PCLK            PCLK_SCB0_CLOCK
#define CY_USB_SCB_UART_IRQN            scb_0_interrupt_IRQn

/******************************************************************************/
/*                      SMIF0 Definitions                                     */
/******************************************************************************/
#define CY_BSP_HDR_SMIF0_AVAILABLE             // Definitions for this functionality are available

#define CY_SMIF_S25FXXXS                       (0u)
#define CY_SMIF_S25FXXXL                       (1u)

#define CY_SMIF0_CLK_PORT                      GPIO_PRT19
#define CY_SMIF0_CLK_PIN                       0
#define CY_SMIF0_CLK_PIN_MUX                   P19_0_SMIF0_SPIHB_CLK

// #define CY_SMIF0_CLK_INV_PORT               // no inverted clock available on this device
// #define CY_SMIF0_CLK_INV_PIN                // no inverted clock available on this device
// #define CY_SMIF0_CLK_INV_PIN_MUX            // no inverted clock available on this device

#define CY_SMIF0_RWDS_PORT                     GPIO_PRT19
#define CY_SMIF0_RWDS_PIN                      1
#define CY_SMIF0_RWDS_PIN_MUX                  P19_1_SMIF0_SPIHB_RWDS

#define CY_SMIF0_SELECT0_PORT                  GPIO_PRT19
#define CY_SMIF0_SELECT0_PIN                   2
#define CY_SMIF0_SELECT0_PIN_MUX               P19_2_SMIF0_SPIHB_SELECT0

#define CY_SMIF0_SELECT1_PORT                  GPIO_PRT19
#define CY_SMIF0_SELECT1_PIN                   3
#define CY_SMIF0_SELECT1_PIN_MUX               P19_3_SMIF0_SPIHB_SELECT1

#define CY_SMIF0_DATA0_PORT                    GPIO_PRT18
#define CY_SMIF0_DATA0_PIN                     4
#define CY_SMIF0_DATA0_PIN_MUX                 P18_4_SMIF0_SPIHB_DATA0

#define CY_SMIF0_DATA1_PORT                    GPIO_PRT18
#define CY_SMIF0_DATA1_PIN                     6
#define CY_SMIF0_DATA1_PIN_MUX                 P18_6_SMIF0_SPIHB_DATA1

#define CY_SMIF0_DATA2_PORT                    GPIO_PRT18
#define CY_SMIF0_DATA2_PIN                     1
#define CY_SMIF0_DATA2_PIN_MUX                 P18_1_SMIF0_SPIHB_DATA2

#define CY_SMIF0_DATA3_PORT                    GPIO_PRT18
#define CY_SMIF0_DATA3_PIN                     2
#define CY_SMIF0_DATA3_PIN_MUX                 P18_2_SMIF0_SPIHB_DATA3

#define CY_SMIF0_DATA4_PORT                    GPIO_PRT18
#define CY_SMIF0_DATA4_PIN                     0
#define CY_SMIF0_DATA4_PIN_MUX                 P18_0_SMIF0_SPIHB_DATA4

#define CY_SMIF0_DATA5_PORT                    GPIO_PRT18
#define CY_SMIF0_DATA5_PIN                     3
#define CY_SMIF0_DATA5_PIN_MUX                 P18_3_SMIF0_SPIHB_DATA5

#define CY_SMIF0_DATA6_PORT                    GPIO_PRT18
#define CY_SMIF0_DATA6_PIN                     5
#define CY_SMIF0_DATA6_PIN_MUX                 P18_5_SMIF0_SPIHB_DATA6

#define CY_SMIF0_DATA7_PORT                    GPIO_PRT18
#define CY_SMIF0_DATA7_PIN                     7
#define CY_SMIF0_DATA7_PIN_MUX                 P18_7_SMIF0_SPIHB_DATA7

#define CY_SMIF0_QUAD_MEMORY                   CY_SMIF_S25FXXXS


/******************************************************************************/
/*                      SMIF1 Definitions                                     */
/******************************************************************************/
#define CY_BSP_HDR_SMIF1_AVAILABLE             // Definitions for this functionality are available

#define CY_SMIF_S25FXXXS                       (0u)
#define CY_SMIF_S25FXXXL                       (1u)

#define CY_SMIF1_CLK_PORT                      GPIO_PRT21
#define CY_SMIF1_CLK_PIN                       0
#define CY_SMIF1_CLK_PIN_MUX                   P21_0_SMIF1_SPIHB_CLK

// #define CY_SMIF1_CLK_INV_PORT               // no inverted clock available on this device
// #define CY_SMIF1_CLK_INV_PIN                // no inverted clock available on this device
// #define CY_SMIF1_CLK_INV_PIN_MUX            // no inverted clock available on this device

#define CY_SMIF1_RWDS_PORT                     GPIO_PRT21
#define CY_SMIF1_RWDS_PIN                      1
#define CY_SMIF1_RWDS_PIN_MUX                  P21_1_SMIF1_SPIHB_RWDS

#define CY_SMIF1_SELECT0_PORT                  GPIO_PRT21
#define CY_SMIF1_SELECT0_PIN                   2
#define CY_SMIF1_SELECT0_PIN_MUX               P21_2_SMIF1_SPIHB_SELECT0

#define CY_SMIF1_SELECT1_PORT                  GPIO_PRT21
#define CY_SMIF1_SELECT1_PIN                   3
#define CY_SMIF1_SELECT1_PIN_MUX               P21_3_SMIF1_SPIHB_SELECT1

#define CY_SMIF1_DATA0_PORT                    GPIO_PRT20
#define CY_SMIF1_DATA0_PIN                     4
#define CY_SMIF1_DATA0_PIN_MUX                 P20_4_SMIF1_SPIHB_DATA0

#define CY_SMIF1_DATA1_PORT                    GPIO_PRT20
#define CY_SMIF1_DATA1_PIN                     6
#define CY_SMIF1_DATA1_PIN_MUX                 P20_6_SMIF1_SPIHB_DATA1

#define CY_SMIF1_DATA2_PORT                    GPIO_PRT20
#define CY_SMIF1_DATA2_PIN                     1
#define CY_SMIF1_DATA2_PIN_MUX                 P20_1_SMIF1_SPIHB_DATA2

#define CY_SMIF1_DATA3_PORT                    GPIO_PRT20
#define CY_SMIF1_DATA3_PIN                     2
#define CY_SMIF1_DATA3_PIN_MUX                 P20_2_SMIF1_SPIHB_DATA3

#define CY_SMIF1_DATA4_PORT                    GPIO_PRT20
#define CY_SMIF1_DATA4_PIN                     0
#define CY_SMIF1_DATA4_PIN_MUX                 P20_0_SMIF1_SPIHB_DATA4

#define CY_SMIF1_DATA5_PORT                    GPIO_PRT20
#define CY_SMIF1_DATA5_PIN                     3
#define CY_SMIF1_DATA5_PIN_MUX                 P20_3_SMIF1_SPIHB_DATA5

#define CY_SMIF1_DATA6_PORT                    GPIO_PRT20
#define CY_SMIF1_DATA6_PIN                     5
#define CY_SMIF1_DATA6_PIN_MUX                 P20_5_SMIF1_SPIHB_DATA6

#define CY_SMIF1_DATA7_PORT                    GPIO_PRT20
#define CY_SMIF1_DATA7_PIN                     7
#define CY_SMIF1_DATA7_PIN_MUX                 P20_7_SMIF1_SPIHB_DATA7

#define CY_SMIF1_QUAD_MEMORY                   CY_SMIF_S25FXXXS
  
/******************************************************************************/
/*                      AUDIOSS PCM-PWM                                       */
/******************************************************************************/

// Sound Generator driver circuit is not present on board, so for testing SG fly
// wire can be connected to the external driver circuit.

#define CY_AUDIOSS_PWM_TYPE                     PWM0_TX0
  
#define CY_AUDIOSS_PWM0_L1P1_PORT               GPIO_PRT16  //J7.35
#define CY_AUDIOSS_PWM0_L1P1_PIN                2
#define CY_AUDIOSS_PWM0_L1P1_PIN_MUX            P16_2_PWM0_PWM_LINE1_P0
  
#define CY_AUDIOSS_PWM0_L1N1_PORT               GPIO_PRT16 //J7.9
#define CY_AUDIOSS_PWM0_L1N1_PIN                3
#define CY_AUDIOSS_PWM0_L1N1_PIN_MUX            P16_3_PWM0_PWM_LINE1_N0
    
#define CY_AUDIOSS_PWM0_L2P1_PORT               GPIO_PRT12 //Tp271
#define CY_AUDIOSS_PWM0_L2P1_PIN                4
#define CY_AUDIOSS_PWM0_L2P1_PIN_MUX            P12_4_PWM0_PWM_LINE2_P0
    
#define CY_AUDIOSS_PWM0_L2N1_PORT               GPIO_PRT14 //J7.14
#define CY_AUDIOSS_PWM0_L2N1_PIN                5
#define CY_AUDIOSS_PWM0_L2N1_PIN_MUX            P14_5_PWM0_PWM_LINE2_N0

#define CY_AUDIOSS_PWM0_IRQN                    pwm_0_interrupts_0_IRQn
  
/******************************************************************************/
/*                      AUDIO-SG Definitions                                  */
/******************************************************************************/

// Sound Generator driver circuit is not present on board, so for testing SG fly
// wire can be connected to the external driver circuit.


#define CY_AUDIOSS_SG0_TYPE                     SG0_SG_STRUCT0
  
#define CY_AUDIOSS_SG0_AMPL_PORT                GPIO_PRT5
#define CY_AUDIOSS_SG0_AMPL_PIN                 4
#define CY_AUDIOSS_SG0_AMPL_PIN_MUX             P5_4_SG0_SG_AMPL0
  
#define CY_AUDIOSS_SG0_TONE_PORT                GPIO_PRT5
#define CY_AUDIOSS_SG0_TONE_PIN                 5
#define CY_AUDIOSS_SG0_TONE_PIN_MUX             P5_5_SG0_SG_TONE0
  
#define CY_AUDIOSS_SG0_IRQ_IRQN                 sg_0_interrupts_0_IRQn
  
/******************************************************************************/
/*                      AUDIO-TDM Definitions                                 */
/******************************************************************************/

// By default on board Codec doesn't support TDM, so for testing TDM fly wire
// can be connected to the external Codec.

#define CY_AUDIOSS_TDM_TYPE                     TDM0_TDM_STRUCT3
  
#define CY_AUDIOSS_TDM0_TX_MCK_PORT             GPIO_PRT14
#define CY_AUDIOSS_TDM0_TX_MCK_PIN              6
#define CY_AUDIOSS_TDM0_TX_MCK_PIN_MUX          P14_6_TDM0_TDM_TX_MCK3
  
#define CY_AUDIOSS_TDM0_TX_SCK_PORT             GPIO_PRT14
#define CY_AUDIOSS_TDM0_TX_SCK_PIN              7
#define CY_AUDIOSS_TDM0_TX_SCK_PIN_MUX          P14_7_TDM0_TDM_TX_SCK3
  
#define CY_AUDIOSS_TDM0_TX_FSYNC_PORT           GPIO_PRT15
#define CY_AUDIOSS_TDM0_TX_FSYNC_PIN            0
#define CY_AUDIOSS_TDM0_TX_FSYNC_PIN_MUX        P15_0_TDM0_TDM_TX_FSYNC3
  
#define CY_AUDIOSS_TDM0_TX_SD_PORT              GPIO_PRT15
#define CY_AUDIOSS_TDM0_TX_SD_PIN               1
#define CY_AUDIOSS_TDM0_TX_SD_PIN_MUX           P15_1_TDM0_TDM_TX_SD3
  
#define CY_AUDIOSS_TDM0_RX_MCK_PORT             GPIO_PRT16
#define CY_AUDIOSS_TDM0_RX_MCK_PIN              6
#define CY_AUDIOSS_TDM0_RX_MCK_PIN_MUX          P16_6_TDM0_TDM_RX_MCK3
  
#define CY_AUDIOSS_TDM0_RX_SCK_PORT             GPIO_PRT16
#define CY_AUDIOSS_TDM0_RX_SCK_PIN              7
#define CY_AUDIOSS_TDM0_RX_SCK_PIN_MUX          P16_7_TDM0_TDM_RX_SCK3
  
#define CY_AUDIOSS_TDM0_RX_FSYNC_PORT           GPIO_PRT17
#define CY_AUDIOSS_TDM0_RX_FSYNC_PIN            0
#define CY_AUDIOSS_TDM0_RX_FSYNC_PIN_MUX        P17_0_TDM0_TDM_RX_FSYNC3
  
#define CY_AUDIOSS_TDM0_RX_SD_PORT              GPIO_PRT17
#define CY_AUDIOSS_TDM0_RX_SD_PIN               1
#define CY_AUDIOSS_TDM0_RX_SD_PIN_MUX           P17_1_TDM0_TDM_RX_SD3
  
#define CY_AUDIOSS_TDM0_TX_IRQN                 tdm_0_interrupts_tx_3_IRQn
#define CY_AUDIOSS_TDM0_RX_IRQN                 tdm_0_interrupts_rx_3_IRQn 

// Based on the Codec communication interface, corresponding scb can be defined here.
  
/******************************************************************************/
/*                      CXPI Base Board Mux                                    */
/******************************************************************************/

/* CXPI Channel 0 */
#define CY_CXPICH_TYPE                  CXPI0_CH0
  
#define CY_CXPICH_RX_PORT               GPIO_PRT1               //TP75
#define CY_CXPICH_RX_PIN                7
#define CY_CXPICH_RX_PIN_MUX            P1_7_CXPI0_CXPI_RX0
  
#define CY_CXPICH_TX_PORT               GPIO_PRT1               //TP58
#define CY_CXPICH_TX_PIN                6
#define CY_CXPICH_TX_PIN_MUX            P1_6_CXPI0_CXPI_TX0

#define CY_CXPICH_EN_PORT               GPIO_PRT2               //TP25
#define CY_CXPICH_EN_PIN                0
#define CY_CXPICH_EN_PIN_MUX            P2_0_CXPI0_CXPI_EN0

#define CY_CXPICH_CLK_PORT              GPIO_PRT4               //TP78
#define CY_CXPICH_CLK_PIN               4
#define CY_CXPICH_CLK_PIN_MUX           P4_4_TCPWM0_LINE9
#define CY_CXPICH_CLK_TCPWM_CNT         TCPWM0_GRP0_CNT9
#define CY_CXPICH_CLK_TCPWM_PCLK        PCLK_TCPWM0_CLOCKS9
#define TCPWM_PERI_CLK_DIVIDER_NO_PWM   0u
  
#define CY_CXPICH_SEL_PORT              GPIO_PRT5               //TP61
#define CY_CXPICH_SEL_PIN               2
#define CY_CXPICH_SEL_PIN_MUX           P5_2_GPIO

#define CY_CXPICH_PCLK                  PCLK_CXPI0_CLOCK_CH_EN0
#define CY_CXPICH_IRQN                  cxpi_0_interrupts_0_IRQn

// BB Board Entities

/******************************************************************************/
/*                      LEDs Base Board Mux                                   */
/******************************************************************************/
#define CY_LED0_PORT                    GPIO_PRT6
#define CY_LED0_PIN                     1
#define CY_LED0_PIN_MUX                 P6_1_GPIO

#define CY_LED1_PORT                    GPIO_PRT4
#define CY_LED1_PIN                     5
#define CY_LED1_PIN_MUX                 P4_5_GPIO

#define CY_LED2_PORT                    GPIO_PRT5
#define CY_LED2_PIN                     3
#define CY_LED2_PIN_MUX                 P5_3_GPIO

#define CY_LED3_PORT                    GPIO_PRT1
#define CY_LED3_PIN                     5
#define CY_LED3_PIN_MUX                 P1_5_GPIO

#define CY_LED4_PORT                    GPIO_PRT8
#define CY_LED4_PIN                     7
#define CY_LED4_PIN_MUX                 P8_7_GPIO

#define CY_LED5_PORT                    GPIO_PRT8
#define CY_LED5_PIN                     3
#define CY_LED5_PIN_MUX                 P8_3_GPIO

#define CY_LED6_PORT                    GPIO_PRT7
#define CY_LED6_PIN                     7
#define CY_LED6_PIN_MUX                 P7_7_GPIO

#define CY_LED7_PORT                    GPIO_PRT7
#define CY_LED7_PIN                     3
#define CY_LED7_PIN_MUX                 P7_3_GPIO

#define CY_LED8_PORT                    GPIO_PRT6
#define CY_LED8_PIN                     2
#define CY_LED8_PIN_MUX                 P6_2_GPIO

#define CY_LED9_PORT                    GPIO_PRT6
#define CY_LED9_PIN                     0
#define CY_LED9_PIN_MUX                 P6_0_GPIO

/******************************************************************************/
/*                      Buttons Base Board Mux                                */
/******************************************************************************/
#define CY_BUTTON1_PORT                 GPIO_PRT8
#define CY_BUTTON1_PIN                  6
#define CY_BUTTON1_PIN_MUX              P8_6_GPIO

#define CY_BUTTON2_PORT                 GPIO_PRT8
#define CY_BUTTON2_PIN                  2
#define CY_BUTTON2_PIN_MUX              P8_2_GPIO

#define CY_BUTTON3_PORT                 GPIO_PRT7
#define CY_BUTTON3_PIN                  6
#define CY_BUTTON3_PIN_MUX              P7_6_GPIO

#define CY_BUTTON4_PORT                 GPIO_PRT7
#define CY_BUTTON4_PIN                  2
#define CY_BUTTON4_PIN_MUX              P7_2_GPIO

#define CY_BUTTON5_PORT                 GPIO_PRT6
#define CY_BUTTON5_PIN                  3
#define CY_BUTTON5_PIN_MUX              P6_3_GPIO

/* Setup GPIO for BUTTONs 1/2/3/4/5 interrupt sources */
#define CY_BUTTON1_IRQN                 ioss_interrupts_gpio_dpslp_8_IRQn
#define CY_BUTTON2_IRQN                 ioss_interrupts_gpio_dpslp_8_IRQn
#define CY_BUTTON3_IRQN                 ioss_interrupts_gpio_dpslp_7_IRQn
#define CY_BUTTON4_IRQN                 ioss_interrupts_gpio_dpslp_7_IRQn
#define CY_BUTTON5_IRQN                 ioss_interrupts_gpio_dpslp_6_IRQn

/******************************************************************************/
/*                      ADC POT                                               */
/******************************************************************************/

#define CY_ADC_POT_MACRO                PASS0_SAR0
#define CY_ADC_POT_IN_NO           		17
#define CY_ADC_POT_PORT                 GPIO_PRT9
#define CY_ADC_POT_PIN                  1
#define CY_ADC_POT_PIN_MUX              P9_1_GPIO
#define CY_ADC_POT_PCLK                 PCLK_PASS0_CLOCK_SAR0
#define CY_ADC_POT_IRQN                 pass_0_interrupts_sar_0_IRQn  // This is logical channel, so it is not board specific

/******************************************************************************/
/*                      SCB Base Board Mux                                    */
/******************************************************************************/

/* USB-UART Mux */


/* CANFD-SPI Mux (BB_CAN_SPI) */


/* EEPROM SPI Mux (BB_SPI0) */


/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/

/* CAN0 Pin Mux */
#define CY_CANFD0_TYPE                  CY_CANFD0_0_TYPE
#define CY_CANFD0_RX_PORT               GPIO_PRT5
#define CY_CANFD0_RX_PIN                5
#define CY_CANFD0_RX_MUX                P5_5_CANFD0_TTCAN_RX0
#define CY_CANFD0_TX_PORT               GPIO_PRT5
#define CY_CANFD0_TX_PIN                4
#define CY_CANFD0_TX_MUX                P5_4_CANFD0_TTCAN_TX0
#define CY_CANFD0_PCLK                  PCLK_CANFD0_CLOCK_CAN0
#define CY_CANFD0_IRQN                  canfd_0_interrupts0_0_IRQn


/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/* LIN Channel 0 */
#define CY_LINCH0_TYPE                  LIN0_CH0                            
#define CY_LINCH0_RX_PORT               GPIO_PRT1                         
#define CY_LINCH0_RX_PIN                7                   
#define CY_LINCH0_RX_PIN_MUX            P1_7_LIN0_LIN_RX0                   
#define CY_LINCH0_TX_PORT               GPIO_PRT1
#define CY_LINCH0_TX_PIN                6
#define CY_LINCH0_TX_PIN_MUX            P1_6_LIN0_LIN_TX0                  
#define CY_LINCH0_PCLK                  PCLK_LIN0_CLOCK_CH_EN0              
#define CY_LINCH0_IRQN                  lin_0_interrupts_0_IRQn             


/******************************************************************************/
/*                      SMARTIO Base Board Mux                                */
/******************************************************************************/

#define CY_SMARTIO_MACRO                        SMARTIO                            
#define CY_SMARTIO_PORT                         SMARTIO_PRT9                       
#define CY_SMARTIO_CLK                          PCLK_SMARTIO9_CLOCK                
     
#define CY_SMARTIO_OUT_PORT                     GPIO_PRT9
#define CY_SMARTIO_OUT_PIN                      0
#define CY_SMARTIO_OUT_PORT_MUX                 P9_0_GPIO

#define CY_SMARTIO_IN_PORT                      GPIO_PRT9
#define CY_SMARTIO_IN_PIN                       1
#define CY_SMARTIO_IN_PORT_MUX                  P9_1_GPIO
#define CY_SMARTIO_IN_PORT_MUX_PWM              P9_1_TCPWM0_LINE19

#define CY_SMARTIO_IN2_PORT                     GPIO_PRT9
#define CY_SMARTIO_IN2_PIN                      3
#define CY_SMARTIO_IN2_PORT_MUX_PWM             P9_3_TCPWM0_LINE20

/* PWM PR Mode Configuration def */
#define CY_SMARTIO_TCPWM_GRP0_CNT               TCPWM0_GRP0_CNT19
#define CY_SMARTIO_TCPWM_PCLK                   PCLK_TCPWM0_CLOCKS19

#define CY_SMARTIO_TCPWM_GRP0_CNT2              TCPWM0_GRP0_CNT20
#define CY_SMARTIO_TCPWM_PCLK2                  PCLK_TCPWM0_CLOCKS20

// Cluster Extension Board entities

/******************************************************************************/
/*                      USER LED CEB Mux (GPIO_202)                           */
/******************************************************************************/

#define CY_CEB_LED_PORT                         GPIO_PRT13                          // Unassigned 
#define CY_CEB_LED_PIN                          4                                   
#define CY_CEB_LED_PIN_MUX                      P13_4_GPIO                          

/******************************************************************************/
/*                      Button CEB Mux (GPIO_201)                             */
/******************************************************************************/

#define CY_CEB_BUTTON_PORT                      GPIO_PRT13                          // Unassigned 
#define CY_CEB_BUTTON_PIN                       1                                  
#define CY_CEB_BUTTON_PIN_MUX                   P13_1_GPIO                         

#define CY_CEB_BUTTON_IRQN                      ioss_interrupts_gpio_dpslp_13_IRQn 


/******************************************************************************/
/*                 Backlight Display #1 Definitions                           */
/******************************************************************************/

// #define CY_BL_DISP1_EN_PORT                    GPIO_PRT?      // only jumper, not SW controllable
// #define CY_BL_DISP1_EN_PIN                     ?              // only jumper, not SW controllable
// #define CY_BL_DISP1_EN_PIN_MUX                 P?_?_GPIO      // only jumper, not SW controllable

#define CY_BL_DISP1_PWM_PORT                   GPIO_PRT9                                              // configuring unused GPIO_007 net on AB for now
#define CY_BL_DISP1_PWM_PIN                    7                                                      // configuring unused GPIO_007 net on AB for now
#define CY_BL_DISP1_PWM_PIN_MUX                P9_7_GPIO  // use as GPIO for now (0% or 100% PWM)     // configuring unused GPIO_007 net on AB for now


/******************************************************************************/
/*                      Display #1 Definitions  (routed to DISP 0 on PSVP HW) */
/******************************************************************************/
#define CY_BSP_HDR_DISP1_TTL_AVAILABLE         // Definitions for this functionality are available

#define CY_DISP1_CLK_PORT                      GPIO_PRT16
#define CY_DISP1_CLK_PIN                       2
#define CY_DISP1_CLK_PIN_MUX                   P16_2_VIDEOSS0_TTL_DSP1_CLOCK    // CLK

#define CY_DISP1_CTRL0_PORT                    GPIO_PRT16
#define CY_DISP1_CTRL0_PIN                     3
#define CY_DISP1_CTRL0_PIN_MUX                 P16_3_VIDEOSS0_TTL_DSP1_CONTROL0 // LVALID

#define CY_DISP1_CTRL1_PORT                    GPIO_PRT16
#define CY_DISP1_CTRL1_PIN                     4
#define CY_DISP1_CTRL1_PIN_MUX                 P16_4_VIDEOSS0_TTL_DSP1_CONTROL1 // VSYNC

#define CY_DISP1_CTRL2_PORT                    GPIO_PRT16
#define CY_DISP1_CTRL2_PIN                     5
#define CY_DISP1_CTRL2_PIN_MUX                 P16_5_VIDEOSS0_TTL_DSP1_CONTROL2 // DE

#define CY_DISP1_DATA_A0_0_PORT                GPIO_PRT16
#define CY_DISP1_DATA_A0_0_PIN                 1
#define CY_DISP1_DATA_A0_0_PIN_MUX             P16_1_VIDEOSS0_TTL_DSP1_DATA_A00 // RED0

#define CY_DISP1_DATA_A0_1_PORT                GPIO_PRT15
#define CY_DISP1_DATA_A0_1_PIN                 7
#define CY_DISP1_DATA_A0_1_PIN_MUX             P15_7_VIDEOSS0_TTL_DSP1_DATA_A01 // RED2

#define CY_DISP1_DATA_A0_2_PORT                GPIO_PRT15
#define CY_DISP1_DATA_A0_2_PIN                 5
#define CY_DISP1_DATA_A0_2_PIN_MUX             P15_5_VIDEOSS0_TTL_DSP1_DATA_A02 // RED4

#define CY_DISP1_DATA_A0_3_PORT                GPIO_PRT15
#define CY_DISP1_DATA_A0_3_PIN                 3
#define CY_DISP1_DATA_A0_3_PIN_MUX             P15_3_VIDEOSS0_TTL_DSP1_DATA_A03 // RED6

#define CY_DISP1_DATA_A0_4_PORT                GPIO_PRT15
#define CY_DISP1_DATA_A0_4_PIN                 1
#define CY_DISP1_DATA_A0_4_PIN_MUX             P15_1_VIDEOSS0_TTL_DSP1_DATA_A04 // GREEN0

#define CY_DISP1_DATA_A0_5_PORT                GPIO_PRT14
#define CY_DISP1_DATA_A0_5_PIN                 7
#define CY_DISP1_DATA_A0_5_PIN_MUX             P14_7_VIDEOSS0_TTL_DSP1_DATA_A05 // GREEN2

#define CY_DISP1_DATA_A0_6_PORT                GPIO_PRT14
#define CY_DISP1_DATA_A0_6_PIN                 5
#define CY_DISP1_DATA_A0_6_PIN_MUX             P14_5_VIDEOSS0_TTL_DSP1_DATA_A06 // GREEN4

#define CY_DISP1_DATA_A0_7_PORT                GPIO_PRT14
#define CY_DISP1_DATA_A0_7_PIN                 3
#define CY_DISP1_DATA_A0_7_PIN_MUX             P14_3_VIDEOSS0_TTL_DSP1_DATA_A07 // GREEN6

#define CY_DISP1_DATA_A0_8_PORT                GPIO_PRT14
#define CY_DISP1_DATA_A0_8_PIN                 1
#define CY_DISP1_DATA_A0_8_PIN_MUX             P14_1_VIDEOSS0_TTL_DSP1_DATA_A08 // BLUE0

#define CY_DISP1_DATA_A0_9_PORT                GPIO_PRT13
#define CY_DISP1_DATA_A0_9_PIN                 7
#define CY_DISP1_DATA_A0_9_PIN_MUX             P13_7_VIDEOSS0_TTL_DSP1_DATA_A09 // BLUE2

#define CY_DISP1_DATA_A0_10_PORT               GPIO_PRT13
#define CY_DISP1_DATA_A0_10_PIN                5
#define CY_DISP1_DATA_A0_10_PIN_MUX            P13_5_VIDEOSS0_TTL_DSP1_DATA_A010 // BLUE4

#define CY_DISP1_DATA_A0_11_PORT               GPIO_PRT13
#define CY_DISP1_DATA_A0_11_PIN                3
#define CY_DISP1_DATA_A0_11_PIN_MUX            P13_3_VIDEOSS0_TTL_DSP1_DATA_A011 // BLUE6

#define CY_DISP1_DATA_A1_0_PORT                GPIO_PRT16
#define CY_DISP1_DATA_A1_0_PIN                 0
#define CY_DISP1_DATA_A1_0_PIN_MUX             P16_0_VIDEOSS0_TTL_DSP1_DATA_A10 // RED1

#define CY_DISP1_DATA_A1_1_PORT                GPIO_PRT15
#define CY_DISP1_DATA_A1_1_PIN                 6
#define CY_DISP1_DATA_A1_1_PIN_MUX             P15_6_VIDEOSS0_TTL_DSP1_DATA_A11 // RED3

#define CY_DISP1_DATA_A1_2_PORT                GPIO_PRT15
#define CY_DISP1_DATA_A1_2_PIN                 4
#define CY_DISP1_DATA_A1_2_PIN_MUX             P15_4_VIDEOSS0_TTL_DSP1_DATA_A12 // RED5

#define CY_DISP1_DATA_A1_3_PORT                GPIO_PRT15
#define CY_DISP1_DATA_A1_3_PIN                 2
#define CY_DISP1_DATA_A1_3_PIN_MUX             P15_2_VIDEOSS0_TTL_DSP1_DATA_A13 // RED7

#define CY_DISP1_DATA_A1_4_PORT                GPIO_PRT15
#define CY_DISP1_DATA_A1_4_PIN                 0
#define CY_DISP1_DATA_A1_4_PIN_MUX             P15_0_VIDEOSS0_TTL_DSP1_DATA_A14 // GREEN1

#define CY_DISP1_DATA_A1_5_PORT                GPIO_PRT14
#define CY_DISP1_DATA_A1_5_PIN                 6
#define CY_DISP1_DATA_A1_5_PIN_MUX             P14_6_VIDEOSS0_TTL_DSP1_DATA_A15 // GREEN3

#define CY_DISP1_DATA_A1_6_PORT                GPIO_PRT14
#define CY_DISP1_DATA_A1_6_PIN                 4
#define CY_DISP1_DATA_A1_6_PIN_MUX             P14_4_VIDEOSS0_TTL_DSP1_DATA_A16 // GREEN5

#define CY_DISP1_DATA_A1_7_PORT                GPIO_PRT14
#define CY_DISP1_DATA_A1_7_PIN                 2
#define CY_DISP1_DATA_A1_7_PIN_MUX             P14_2_VIDEOSS0_TTL_DSP1_DATA_A17 // GREEN7

#define CY_DISP1_DATA_A1_8_PORT                GPIO_PRT14
#define CY_DISP1_DATA_A1_8_PIN                 0
#define CY_DISP1_DATA_A1_8_PIN_MUX             P14_0_VIDEOSS0_TTL_DSP1_DATA_A18 // BLUE1

#define CY_DISP1_DATA_A1_9_PORT                GPIO_PRT13
#define CY_DISP1_DATA_A1_9_PIN                 6
#define CY_DISP1_DATA_A1_9_PIN_MUX             P13_6_VIDEOSS0_TTL_DSP1_DATA_A19 // BLUE3

#define CY_DISP1_DATA_A1_10_PORT               GPIO_PRT13
#define CY_DISP1_DATA_A1_10_PIN                4
#define CY_DISP1_DATA_A1_10_PIN_MUX            P13_4_VIDEOSS0_TTL_DSP1_DATA_A110 // BLUE5

#define CY_DISP1_DATA_A1_11_PORT               GPIO_PRT13
#define CY_DISP1_DATA_A1_11_PIN                2
#define CY_DISP1_DATA_A1_11_PIN_MUX            P13_2_VIDEOSS0_TTL_DSP1_DATA_A111 // BLUE7


/******************************************************************************/
/*                      Capture #0 Definitions                                */
/******************************************************************************/
#define CY_BSP_HDR_CAP0_TTL_AVAILABLE          // Definitions for this functionality are available

#define CY_CAP0_CLK_PORT                       GPIO_PRT13
#define CY_CAP0_CLK_PIN                        1
#define CY_CAP0_CLK_PIN_MUX                    P13_1_VIDEOSS0_TTL_CAP0_CLK

#define CY_CAP0_DATA0_PORT                     GPIO_PRT13
#define CY_CAP0_DATA0_PIN                      0
#define CY_CAP0_DATA0_PIN_MUX                  P13_0_VIDEOSS0_TTL_CAP0_DATA0

#define CY_CAP0_DATA1_PORT                     GPIO_PRT12
#define CY_CAP0_DATA1_PIN                      7
#define CY_CAP0_DATA1_PIN_MUX                  P12_7_VIDEOSS0_TTL_CAP0_DATA1

#define CY_CAP0_DATA2_PORT                     GPIO_PRT12
#define CY_CAP0_DATA2_PIN                      6
#define CY_CAP0_DATA2_PIN_MUX                  P12_6_VIDEOSS0_TTL_CAP0_DATA2

#define CY_CAP0_DATA3_PORT                     GPIO_PRT12
#define CY_CAP0_DATA3_PIN                      5
#define CY_CAP0_DATA3_PIN_MUX                  P12_5_VIDEOSS0_TTL_CAP0_DATA3

#define CY_CAP0_DATA4_PORT                     GPIO_PRT12
#define CY_CAP0_DATA4_PIN                      4
#define CY_CAP0_DATA4_PIN_MUX                  P12_4_VIDEOSS0_TTL_CAP0_DATA4

#define CY_CAP0_DATA5_PORT                     GPIO_PRT12
#define CY_CAP0_DATA5_PIN                      3
#define CY_CAP0_DATA5_PIN_MUX                  P12_3_VIDEOSS0_TTL_CAP0_DATA5

#define CY_CAP0_DATA6_PORT                     GPIO_PRT12
#define CY_CAP0_DATA6_PIN                      2
#define CY_CAP0_DATA6_PIN_MUX                  P12_2_VIDEOSS0_TTL_CAP0_DATA6

#define CY_CAP0_DATA7_PORT                     GPIO_PRT12
#define CY_CAP0_DATA7_PIN                      1
#define CY_CAP0_DATA7_PIN_MUX                  P12_1_VIDEOSS0_TTL_CAP0_DATA7

#define CY_CAP0_DATA8_PORT                     GPIO_PRT9
#define CY_CAP0_DATA8_PIN                      7
#define CY_CAP0_DATA8_PIN_MUX                  P9_7_VIDEOSS0_TTL_CAP0_DATA8

#define CY_CAP0_DATA9_PORT                     GPIO_PRT9
#define CY_CAP0_DATA9_PIN                      6
#define CY_CAP0_DATA9_PIN_MUX                  P9_6_VIDEOSS0_TTL_CAP0_DATA9

#define CY_CAP0_DATA10_PORT                    GPIO_PRT9
#define CY_CAP0_DATA10_PIN                     5
#define CY_CAP0_DATA10_PIN_MUX                 P9_5_VIDEOSS0_TTL_CAP0_DATA10

#define CY_CAP0_DATA11_PORT                    GPIO_PRT9
#define CY_CAP0_DATA11_PIN                     4
#define CY_CAP0_DATA11_PIN_MUX                 P9_4_VIDEOSS0_TTL_CAP0_DATA11

#define CY_CAP0_DATA12_PORT                    GPIO_PRT9
#define CY_CAP0_DATA12_PIN                     3
#define CY_CAP0_DATA12_PIN_MUX                 P9_3_VIDEOSS0_TTL_CAP0_DATA12

#define CY_CAP0_DATA13_PORT                    GPIO_PRT9
#define CY_CAP0_DATA13_PIN                     2
#define CY_CAP0_DATA13_PIN_MUX                 P9_2_VIDEOSS0_TTL_CAP0_DATA13

#define CY_CAP0_DATA14_PORT                    GPIO_PRT9
#define CY_CAP0_DATA14_PIN                     1
#define CY_CAP0_DATA14_PIN_MUX                 P9_1_VIDEOSS0_TTL_CAP0_DATA14

#define CY_CAP0_DATA15_PORT                    GPIO_PRT9
#define CY_CAP0_DATA15_PIN                     0
#define CY_CAP0_DATA15_PIN_MUX                 P9_0_VIDEOSS0_TTL_CAP0_DATA15

#define CY_CAP0_DATA16_PORT                    GPIO_PRT8
#define CY_CAP0_DATA16_PIN                     7
#define CY_CAP0_DATA16_PIN_MUX                 P8_7_VIDEOSS0_TTL_CAP0_DATA16

#define CY_CAP0_DATA17_PORT                    GPIO_PRT8
#define CY_CAP0_DATA17_PIN                     6
#define CY_CAP0_DATA17_PIN_MUX                 P8_6_VIDEOSS0_TTL_CAP0_DATA17

#define CY_CAP0_DATA18_PORT                    GPIO_PRT8
#define CY_CAP0_DATA18_PIN                     5
#define CY_CAP0_DATA18_PIN_MUX                 P8_5_VIDEOSS0_TTL_CAP0_DATA18

#define CY_CAP0_DATA19_PORT                    GPIO_PRT8
#define CY_CAP0_DATA19_PIN                     4
#define CY_CAP0_DATA19_PIN_MUX                 P8_4_VIDEOSS0_TTL_CAP0_DATA19

#define CY_CAP0_DATA20_PORT                    GPIO_PRT8
#define CY_CAP0_DATA20_PIN                     3
#define CY_CAP0_DATA20_PIN_MUX                 P8_3_VIDEOSS0_TTL_CAP0_DATA20

#define CY_CAP0_DATA21_PORT                    GPIO_PRT8
#define CY_CAP0_DATA21_PIN                     2
#define CY_CAP0_DATA21_PIN_MUX                 P8_2_VIDEOSS0_TTL_CAP0_DATA21

#define CY_CAP0_DATA22_PORT                    GPIO_PRT8
#define CY_CAP0_DATA22_PIN                     1
#define CY_CAP0_DATA22_PIN_MUX                 P8_1_VIDEOSS0_TTL_CAP0_DATA22

#define CY_CAP0_DATA23_PORT                    GPIO_PRT8
#define CY_CAP0_DATA23_PIN                     0
#define CY_CAP0_DATA23_PIN_MUX                 P8_0_VIDEOSS0_TTL_CAP0_DATA23

#define CY_CAP0_DATA24_PORT                    GPIO_PRT7
#define CY_CAP0_DATA24_PIN                     7
#define CY_CAP0_DATA24_PIN_MUX                 P7_7_VIDEOSS0_TTL_CAP0_DATA24

#define CY_CAP0_DATA25_PORT                    GPIO_PRT7
#define CY_CAP0_DATA25_PIN                     6
#define CY_CAP0_DATA25_PIN_MUX                 P7_6_VIDEOSS0_TTL_CAP0_DATA25

#define CY_CAP0_DATA26_PORT                    GPIO_PRT7
#define CY_CAP0_DATA26_PIN                     5
#define CY_CAP0_DATA26_PIN_MUX                 P7_5_VIDEOSS0_TTL_CAP0_DATA26

  


/******************************************************************************/
/*                      AUTO ETHERNET Definitions                             */
/******************************************************************************/

#define CY_AUTO_ETH_TYPE                         ETH0
#define CY_AUTO_ETH_INSTANCE_NUM                (0)
                                          
#define CY_AUTO_ETH_TX_CLK_PORT                  GPIO_PRT12
#define CY_AUTO_ETH_TX_CLK_PIN                   2
#define CY_AUTO_ETH_TX_CLK_PIN_MUX               P12_2_ETH0_TX_CLK
                                          
#define CY_AUTO_ETH_TX_CTL_PORT                  GPIO_PRT11
#define CY_AUTO_ETH_TX_CTL_PIN                   6
#define CY_AUTO_ETH_TX_CTL_PIN_MUX               P11_6_ETH0_TX_CTL
                                          
#define CY_AUTO_ETH_TD0_PORT                     GPIO_PRT11
#define CY_AUTO_ETH_TD0_PIN                      4
#define CY_AUTO_ETH_TD0_PIN_MUX                  P11_4_ETH0_TXD0
                                          
#define CY_AUTO_ETH_TD1_PORT                     GPIO_PRT11
#define CY_AUTO_ETH_TD1_PIN                      5
#define CY_AUTO_ETH_TD1_PIN_MUX                  P11_5_ETH0_TXD1
                                          
#define CY_AUTO_ETH_TD2_PORT                     GPIO_PRT12
#define CY_AUTO_ETH_TD2_PIN                      6
#define CY_AUTO_ETH_TD2_PIN_MUX                  P12_6_ETH0_TXD2
                                          
#define CY_AUTO_ETH_TD3_PORT                     GPIO_PRT12
#define CY_AUTO_ETH_TD3_PIN                      7
#define CY_AUTO_ETH_TD3_PIN_MUX                  P12_7_ETH0_TXD3
                                          
#define CY_AUTO_ETH_TXER_PORT                    GPIO_PRT13
#define CY_AUTO_ETH_TXER_PIN                     0
#define CY_AUTO_ETH_TXER_PIN_MUX                 P13_0_ETH0_TX_ER
                                          
#define CY_AUTO_ETH_RX_CLK_PORT                  GPIO_PRT12
#define CY_AUTO_ETH_RX_CLK_PIN                   3
#define CY_AUTO_ETH_RX_CLK_PIN_MUX               P12_3_ETH0_RX_CLK
                                          
#define CY_AUTO_ETH_RX_CTL_PORT                  GPIO_PRT11
#define CY_AUTO_ETH_RX_CTL_PIN                   7
#define CY_AUTO_ETH_RX_CTL_PIN_MUX               P11_7_ETH0_RX_CTL
                                          
#define CY_AUTO_ETH_RD0_PORT                     GPIO_PRT11
#define CY_AUTO_ETH_RD0_PIN                      2
#define CY_AUTO_ETH_RD0_PIN_MUX                  P11_2_ETH0_RXD0
                                          
#define CY_AUTO_ETH_RD1_PORT                     GPIO_PRT11
#define CY_AUTO_ETH_RD1_PIN                      3
#define CY_AUTO_ETH_RD1_PIN_MUX                  P11_3_ETH0_RXD1
                                          
#define CY_AUTO_ETH_RD2_PORT                     GPIO_PRT12
#define CY_AUTO_ETH_RD2_PIN                      4
#define CY_AUTO_ETH_RD2_PIN_MUX                  P12_4_ETH0_RXD2
                                          
#define CY_AUTO_ETH_RD3_PORT                     GPIO_PRT12
#define CY_AUTO_ETH_RD3_PIN                      5
#define CY_AUTO_ETH_RD3_PIN_MUX                  P12_5_ETH0_RXD3
                                          
#define CY_AUTO_ETH_RX_ER_PORT                   GPIO_PRT11
#define CY_AUTO_ETH_RX_ER_PIN                    1
#define CY_AUTO_ETH_RX_ER_PIN_MUX                P11_1_ETH0_RX_ER
                                          
#define CY_AUTO_ETH_MDC_PORT                     GPIO_PRT12
#define CY_AUTO_ETH_MDC_PIN                      0
#define CY_AUTO_ETH_MDC_PIN_MUX                  P12_0_ETH0_MDC
                                          
#define CY_AUTO_ETH_MDIO_PORT                    GPIO_PRT12
#define CY_AUTO_ETH_MDIO_PIN                     1
#define CY_AUTO_ETH_MDIO_PIN_MUX                 P12_1_ETH0_MDIO
                                          
#define CY_AUTO_ETH_REF_CLK_PORT                 GPIO_PRT11
#define CY_AUTO_ETH_REF_CLK_PIN                  0
#define CY_AUTO_ETH_REF_CLK_PIN_MUX              P11_0_ETH0_REF_CLK
  
/* Setup IRQ source for 0, 1 and 2 Priority Queue */
#define CY_AUTO_ETH_IRQN0                        eth_0_interrupt_eth_0_IRQn
#define CY_AUTO_ETH_IRQN1                        eth_0_interrupt_eth_1_IRQn
#define CY_AUTO_ETH_IRQN2                        eth_0_interrupt_eth_2_IRQn


/******************************************************************************/
/*                      MIPI CSI-2 Definitions                                */
/******************************************************************************/

// rmkn: dummy assignments
// No need to configure MIPI CSI io mux, it is a part of AMUXBUS.

/* MIPI IO Clock */
#define CY_MIPI_CSI_IO_CLK_PORT                 GPIO_PRT15
#define CY_MIPI_CSI_IO_CLK_PIN                  5
#define CY_MIPI_CSI_IO_CLK_PIN_MUX              P15_5_GPIO

/* MIPI Power Enable */
#define CY_MIPI_CSI_PWDN_PORT                   GPIO_PRT17
#define CY_MIPI_CSI_PWDN_PIN                    1
#define CY_MIPI_CSI_PWDN_PIN_MUX                P17_1_GPIO
  
/* MIPI CSI Communication Block */
#define CY_MIPI_CSI_I2C_TYPE                    SCB9
  
#define CY_MIPI_CSI_I2C_SDA_PORT                GPIO_PRT18
#define CY_MIPI_CSI_I2C_SDA_PIN                 0
#define CY_MIPI_CSI_I2C_SDA_PIN_MUX             P18_0_SCB9_I2C_SDA
  
#define CY_MIPI_CSI_I2C_SCL_PORT                GPIO_PRT18
#define CY_MIPI_CSI_I2C_SCL_PIN                 1
#define CY_MIPI_CSI_I2C_SCL_PIN_MUX             P18_1_SCB9_I2C_SCL
  
#define CY_MIPI_CSI_I2C_PCLK                    PCLK_SCB9_CLOCK
#define CY_MIPI_CSI_I2C_IRQN                    scb_9_interrupt_IRQn

/******************************************************************************/
/*                              EXT CLK PORT                                  */
/******************************************************************************/
#define HF3_CLK_OUT_PORT                         GPIO_PRT0
#define HF3_CLK_OUT_PIN                          (2ul)
#define HF3_CLK_OUT_PIN_MUX                      P0_2_SRSS_EXT_CLK

/******************************************************************************/
/******************************************************************************/
  
// tviic2d4m - 272-BGA Package devices
    
// #if (CY_USE_PSVP == 0) (--> Silicon), project setting CY_USE_PSVP should be changed to '0'
// select the supported or required device accordingly
  
#elif (CY_USE_PSVP == 0) && defined(CYT3DLBBHS)
    
/******************************************************************************/
/******************************************************************************/

// CPU Board Entities

/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/*                      USER LED's                                            */
/******************************************************************************/    



/******************************************************************************/
/*                      USER BUTTON's                                         */
/******************************************************************************/


/******************************************************************************/
/*                      ADC POT                                               */
/******************************************************************************/


/******************************************************************************/
/*                      SCB Mux                                               */
/******************************************************************************/

/******************************************************************************/
/*                      SMIF0 Definitions                                     */
/******************************************************************************/

/******************************************************************************/
/*                      SMIF1 Definitions                                     */
/******************************************************************************/

/******************************************************************************/
/*                      AUDIOSS PCM-PWM                                       */
/******************************************************************************/

/******************************************************************************/
/*                      GIGA ETH Port                                         */
/******************************************************************************/

/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/

/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/******************************************************************************/
/*                      SMARTIO Block                                         */
/******************************************************************************/

/******************************************************************************/
/*                      AUDIO DAC Definitions                                 */
/******************************************************************************/

/******************************************************************************/
/*                      Display Backlight Controls                            */
/******************************************************************************/

/******************************************************************************/
/*                      Display #0 Definitions                                */
/******************************************************************************/
 
/******************************************************************************/
/*                      Display #1 Definitions                                */
/******************************************************************************/
  
/******************************************************************************/
/*                      Capture #0 Definitions                                */
/******************************************************************************/

/******************************************************************************/
/*                      FPD-LINK Definitions                                  */
/******************************************************************************/

/******************************************************************************/
/*                      MIPI CSI-2 Definitions                                */
/******************************************************************************/

/******************************************************************************/
/*                      CXPI Definitions                                      */
/******************************************************************************/

/******************************************************************************/
/*                      AUDIO-TDM Definitions                                 */
/******************************************************************************/

/******************************************************************************/
/*                      AUDIO-SG Definitions                                  */
/******************************************************************************/

/******************************************************************************/
/*                      AUDIO-TDM Definitions                                 */
/******************************************************************************/
  
  
/******************************************************************************/
/*                              EXT CLK PORT                                  */
/******************************************************************************/
#define HF3_CLK_OUT_PORT                         GPIO_PRT0
#define HF3_CLK_OUT_PIN                          (2ul)
#define HF3_CLK_OUT_PIN_MUX                      P0_2_SRSS_EXT_CLK

// tviic2d4m - 216-TEQFP Package devices
    
// #if (CY_USE_PSVP == 0) (--> Silicon), project setting CY_USE_PSVP should be changed to '0'
// select the supported or required device accordingly

#elif (CY_USE_PSVP == 0) && (defined (CYT3DLABAS) || defined (CYT3DLABBS) || \
                             defined (CYT3DLABCS) || defined (CYT3DLABDS) || \
                             defined (CYT3DLABES) || defined (CYT3DLABFS) || \
                             defined (CYT3DLABGS) || defined (CYT3DLABHS))

/******************************************************************************/
/******************************************************************************/

// CPU Board Entities

/******************************************************************************/
/*                      USER LED's                                            */
/******************************************************************************/ 

#define CY_USER_LED1_PORT                    GPIO_PRT7
#define CY_USER_LED1_PIN                     2
#define CY_USER_LED1_PIN_MUX                 P7_2_GPIO

#define CY_USER_LED2_PORT                    GPIO_PRT7
#define CY_USER_LED2_PIN                     3
#define CY_USER_LED2_PIN_MUX                 P7_3_GPIO

#define CY_USER_LED3_PORT                    GPIO_PRT7
#define CY_USER_LED3_PIN                     4
#define CY_USER_LED3_PIN_MUX                 P7_4_GPIO

/******************************************************************************/
/*                      USER Button (SW1)                                     */
/******************************************************************************/

#define CY_USER_BUTTON_LEFT_PORT                GPIO_PRT7
#define CY_USER_BUTTON_LEFT_PIN                 1
#define CY_USER_BUTTON_LEFT_PIN_MUX             P7_1_GPIO
  
#define CY_USER_BUTTON_RIGHT_PORT               GPIO_PRT6
#define CY_USER_BUTTON_RIGHT_PIN                3
#define CY_USER_BUTTON_RIGHT_PIN_MUX            P6_3_GPIO
  
#define CY_USER_BUTTON_WAKE_PORT                GPIO_PRT5
#define CY_USER_BUTTON_WAKE_PIN                 2
#define CY_USER_BUTTON_WAKE_PIN_MUX             P5_2_GPIO
#define CY_USER_HIB_SOURCE                      CY_SYSPM_LPCOMP1_LOW // WAKEUP_PIN3
    
/* Setup GPIO for BUTTONs interrupt sources */
#define CY_USER_BUTTON_LEFT_IRQN                ioss_interrupts_gpio_dpslp_7_IRQn
#define CY_USER_BUTTON_RIGHT_IRQN               ioss_interrupts_gpio_dpslp_6_IRQn
#define CY_USER_BUTTON_WAKE_IRQN                ioss_interrupts_gpio_dpslp_5_IRQn

/******************************************************************************/
/*                      ADC POT                                               */
/******************************************************************************/

#define CY_ADC_POT_PORT                         GPIO_PRT7
#define CY_ADC_POT_PIN                          0
#define CY_ADC_POT_PIN_MUX                      P7_0_GPIO

#define CY_ADC_POT_MACRO                        PASS0_SAR0
#define CY_ADC_POT_IN_NO                   		0                              // adc physical channel irq
#define CY_ADC_POT_PCLK                         PCLK_PASS0_CLOCK_SAR0
#define CY_ADC_POT_IRQN                         pass_0_interrupts_sar_0_IRQn    // sar logical channel irq

/******************************************************************************/
/*                      SCB Mux                                               */
/******************************************************************************/
/* USB-UART Mux */
#define CY_USB_SCB_TYPE                         SCB0
  
#define CY_USB_SCB_UART_RX_PORT                 GPIO_PRT5
#define CY_USB_SCB_UART_RX_PIN                  0
#define CY_USB_SCB_UART_RX_MUX                  P5_0_SCB0_UART_RX

#define CY_USB_SCB_UART_TX_PORT                 GPIO_PRT5
#define CY_USB_SCB_UART_TX_PIN                  1
#define CY_USB_SCB_UART_TX_MUX                  P5_1_SCB0_UART_TX

#define CY_USB_SCB_UART_PCLK                    PCLK_SCB0_CLOCK
#define CY_USB_SCB_UART_IRQN                    scb_0_interrupt_IRQn

/******************************************************************************/
/*                      SMIF0 Definitions                                     */
/******************************************************************************/
    
#define CY_BSP_HDR_SMIF0_AVAILABLE

#define CY_SMIF0_CLK_PORT                       GPIO_PRT19
#define CY_SMIF0_CLK_PIN                        0
#define CY_SMIF0_CLK_PIN_MUX                    P19_0_SMIF0_SPIHB_CLK
  
// #define CY_SMIF0_CLK_INV_PORT                // no inverted clock available on this device
// #define CY_SMIF0_CLK_INV_PIN                 // no inverted clock available on this device
// #define CY_SMIF0_CLK_INV_PIN_MUX             // no inverted clock available on this device

#define CY_SMIF0_RWDS_PORT                      GPIO_PRT19
#define CY_SMIF0_RWDS_PIN                       1
#define CY_SMIF0_RWDS_PIN_MUX                   P19_1_SMIF0_SPIHB_RWDS
  
#define CY_SMIF0_SELECT0_PORT                   GPIO_PRT19
#define CY_SMIF0_SELECT0_PIN                    2
#define CY_SMIF0_SELECT0_PIN_MUX                P19_2_SMIF0_SPIHB_SELECT0
  
#define CY_SMIF0_SELECT1_PORT                   GPIO_PRT19
#define CY_SMIF0_SELECT1_PIN                    3
#define CY_SMIF0_SELECT1_PIN_MUX                P19_3_SMIF0_SPIHB_SELECT1
  
#define CY_SMIF0_DATA0_PORT                     GPIO_PRT18
#define CY_SMIF0_DATA0_PIN                      4
#define CY_SMIF0_DATA0_PIN_MUX                  P18_4_SMIF0_SPIHB_DATA0
  
#define CY_SMIF0_DATA1_PORT                     GPIO_PRT18
#define CY_SMIF0_DATA1_PIN                      6
#define CY_SMIF0_DATA1_PIN_MUX                  P18_6_SMIF0_SPIHB_DATA1
  
#define CY_SMIF0_DATA2_PORT                     GPIO_PRT18
#define CY_SMIF0_DATA2_PIN                      1
#define CY_SMIF0_DATA2_PIN_MUX                  P18_1_SMIF0_SPIHB_DATA2
  
#define CY_SMIF0_DATA3_PORT                     GPIO_PRT18
#define CY_SMIF0_DATA3_PIN                      2
#define CY_SMIF0_DATA3_PIN_MUX                  P18_2_SMIF0_SPIHB_DATA3
  
#define CY_SMIF0_DATA4_PORT                     GPIO_PRT18
#define CY_SMIF0_DATA4_PIN                      0
#define CY_SMIF0_DATA4_PIN_MUX                  P18_0_SMIF0_SPIHB_DATA4
  
#define CY_SMIF0_DATA5_PORT                     GPIO_PRT18
#define CY_SMIF0_DATA5_PIN                      3
#define CY_SMIF0_DATA5_PIN_MUX                  P18_3_SMIF0_SPIHB_DATA5
  
#define CY_SMIF0_DATA6_PORT                     GPIO_PRT18
#define CY_SMIF0_DATA6_PIN                      5
#define CY_SMIF0_DATA6_PIN_MUX                  P18_5_SMIF0_SPIHB_DATA6
  
#define CY_SMIF0_DATA7_PORT                     GPIO_PRT18
#define CY_SMIF0_DATA7_PIN                      7
#define CY_SMIF0_DATA7_PIN_MUX                  P18_7_SMIF0_SPIHB_DATA7
    
#define CY_SMIF_S25FXXXS                        (0u)
#define CY_SMIF_S25FXXXL                        (1u)
#define CY_SMIF0_QUAD_MEMORY                    CY_SMIF_S25FXXXS		// Memory devices may differ on socketed board

// IO connections P6.2 kept for Semper Flash interrupt.

/******************************************************************************/
/*                      SMIF1 Definitions                                     */
/******************************************************************************/
    
#define CY_BSP_HDR_SMIF1_AVAILABLE

#define CY_SMIF1_CLK_PORT                       GPIO_PRT21
#define CY_SMIF1_CLK_PIN                        0
#define CY_SMIF1_CLK_PIN_MUX                    P21_0_SMIF1_SPIHB_CLK
  
// #define CY_SMIF1_CLK_INV_PORT                // no inverted clock available on this device
// #define CY_SMIF1_CLK_INV_PIN                 // no inverted clock available on this device
// #define CY_SMIF1_CLK_INV_PIN_MUX             // no inverted clock available on this device

#define CY_SMIF1_RWDS_PORT                      GPIO_PRT21
#define CY_SMIF1_RWDS_PIN                       1
#define CY_SMIF1_RWDS_PIN_MUX                   P21_1_SMIF1_SPIHB_RWDS
  
#define CY_SMIF1_SELECT0_PORT                   GPIO_PRT21
#define CY_SMIF1_SELECT0_PIN                    2
#define CY_SMIF1_SELECT0_PIN_MUX                P21_2_SMIF1_SPIHB_SELECT0
  
#define CY_SMIF1_SELECT1_PORT                   GPIO_PRT21
#define CY_SMIF1_SELECT1_PIN                    3
#define CY_SMIF1_SELECT1_PIN_MUX                P21_3_SMIF1_SPIHB_SELECT1
  
#define CY_SMIF1_DATA0_PORT                     GPIO_PRT20
#define CY_SMIF1_DATA0_PIN                      4
#define CY_SMIF1_DATA0_PIN_MUX                  P20_4_SMIF1_SPIHB_DATA0
  
#define CY_SMIF1_DATA1_PORT                     GPIO_PRT20
#define CY_SMIF1_DATA1_PIN                      6
#define CY_SMIF1_DATA1_PIN_MUX                  P20_6_SMIF1_SPIHB_DATA1
  
#define CY_SMIF1_DATA2_PORT                     GPIO_PRT20
#define CY_SMIF1_DATA2_PIN                      1
#define CY_SMIF1_DATA2_PIN_MUX                  P20_1_SMIF1_SPIHB_DATA2
  
#define CY_SMIF1_DATA3_PORT                     GPIO_PRT20
#define CY_SMIF1_DATA3_PIN                      2
#define CY_SMIF1_DATA3_PIN_MUX                  P20_2_SMIF1_SPIHB_DATA3
  
#define CY_SMIF1_DATA4_PORT                     GPIO_PRT20
#define CY_SMIF1_DATA4_PIN                      0
#define CY_SMIF1_DATA4_PIN_MUX                  P20_0_SMIF1_SPIHB_DATA4
  
#define CY_SMIF1_DATA5_PORT                     GPIO_PRT20
#define CY_SMIF1_DATA5_PIN                      3
#define CY_SMIF1_DATA5_PIN_MUX                  P20_3_SMIF1_SPIHB_DATA5
  
#define CY_SMIF1_DATA6_PORT                     GPIO_PRT20
#define CY_SMIF1_DATA6_PIN                      5
#define CY_SMIF1_DATA6_PIN_MUX                  P20_5_SMIF1_SPIHB_DATA6
  
#define CY_SMIF1_DATA7_PORT                     GPIO_PRT20
#define CY_SMIF1_DATA7_PIN                      7
#define CY_SMIF1_DATA7_PIN_MUX                  P20_7_SMIF1_SPIHB_DATA7
    
#define CY_SMIF_S25FXXXS                        (0u)
#define CY_SMIF_S25FXXXL                        (1u)
#define CY_SMIF1_QUAD_MEMORY                    CY_SMIF_S25FXXXS		// Memory devices may differ on socketed board

/******************************************************************************/
/*                      AUDIOSS PCM-PWM                                       */
/******************************************************************************/

#define CY_AUDIOSS_PWM_TYPE                     PWM0_TX1
  
#define CY_AUDIOSS_PWM0_L1P1_PORT               GPIO_PRT14
#define CY_AUDIOSS_PWM0_L1P1_PIN                6
#define CY_AUDIOSS_PWM0_L1P1_PIN_MUX            P14_6_PWM0_PWM_LINE1_P1
  
#define CY_AUDIOSS_PWM0_L1N1_PORT               GPIO_PRT14
#define CY_AUDIOSS_PWM0_L1N1_PIN                7
#define CY_AUDIOSS_PWM0_L1N1_PIN_MUX            P14_7_PWM0_PWM_LINE1_N1
    
#define CY_AUDIOSS_PWM0_L2P1_PORT               GPIO_PRT15
#define CY_AUDIOSS_PWM0_L2P1_PIN                0
#define CY_AUDIOSS_PWM0_L2P1_PIN_MUX            P15_0_PWM0_PWM_LINE2_P1
    
#define CY_AUDIOSS_PWM0_L2N1_PORT               GPIO_PRT15
#define CY_AUDIOSS_PWM0_L2N1_PIN                1
#define CY_AUDIOSS_PWM0_L2N1_PIN_MUX            P15_1_PWM0_PWM_LINE2_N1
    
#define CY_AUDIOSS_PWM0_IRQN                    pwm_0_interrupts_1_IRQn
  
/******************************************************************************/
/*                       ETH 10/100 Mbps Port                                 */
/******************************************************************************/

#define CY_GIG_ETH_TYPE                         ETH0
                                          
#define CY_GIG_ETH_TX_CTL_PORT                  GPIO_PRT11
#define CY_GIG_ETH_TX_CTL_PIN                   6
#define CY_GIG_ETH_TX_CTL_PIN_MUX               P11_6_ETH0_TX_CTL
                                          
#define CY_GIG_ETH_TD0_PORT                     GPIO_PRT11
#define CY_GIG_ETH_TD0_PIN                      4
#define CY_GIG_ETH_TD0_PIN_MUX                  P11_4_ETH0_TXD0
                                          
#define CY_GIG_ETH_TD1_PORT                     GPIO_PRT11
#define CY_GIG_ETH_TD1_PIN                      5
#define CY_GIG_ETH_TD1_PIN_MUX                  P11_5_ETH0_TXD1
                                          
#define CY_GIG_ETH_RX_CTL_PORT                  GPIO_PRT11
#define CY_GIG_ETH_RX_CTL_PIN                   7
#define CY_GIG_ETH_RX_CTL_PIN_MUX               P11_7_ETH0_RX_CTL
                                          
#define CY_GIG_ETH_RD0_PORT                     GPIO_PRT11
#define CY_GIG_ETH_RD0_PIN                      2
#define CY_GIG_ETH_RD0_PIN_MUX                  P11_2_ETH0_RXD0
                                          
#define CY_GIG_ETH_RD1_PORT                     GPIO_PRT11
#define CY_GIG_ETH_RD1_PIN                      3
#define CY_GIG_ETH_RD1_PIN_MUX                  P11_3_ETH0_RXD1
                                          
#define CY_GIG_ETH_RX_ER_PORT                   GPIO_PRT11
#define CY_GIG_ETH_RX_ER_PIN                    1
#define CY_GIG_ETH_RX_ER_PIN_MUX                P11_1_ETH0_RX_ER
                                          
#define CY_GIG_ETH_MDC_PORT                     GPIO_PRT12
#define CY_GIG_ETH_MDC_PIN                      0
#define CY_GIG_ETH_MDC_PIN_MUX                  P12_0_ETH0_MDC
                                          
#define CY_GIG_ETH_MDIO_PORT                    GPIO_PRT12
#define CY_GIG_ETH_MDIO_PIN                     1
#define CY_GIG_ETH_MDIO_PIN_MUX                 P12_1_ETH0_MDIO
                                          
#define CY_GIG_ETH_REF_CLK_PORT                 GPIO_PRT11
#define CY_GIG_ETH_REF_CLK_PIN                  0
#define CY_GIG_ETH_REF_CLK_PIN_MUX              P11_0_ETH0_REF_CLK
  
/* Setup IRQ source for 0, 1 and 2 Priority Queue */
#define CY_GIG_ETH_IRQN0                        eth_0_interrupt_eth_0_IRQn
#define CY_GIG_ETH_IRQN1                        eth_0_interrupt_eth_1_IRQn
#define CY_GIG_ETH_IRQN2                        eth_0_interrupt_eth_2_IRQn

/******************************************************************************/
/*                       CANFD CPU Board Mux                                  */
/******************************************************************************/

/* CAN1 */
#define CY_CANFD0_TYPE                          CY_CANFD0_0_TYPE
#define CY_CANFD0_RX_PORT                       GPIO_PRT5
#define CY_CANFD0_RX_PIN                        5
#define CY_CANFD0_RX_MUX                        P5_5_CANFD0_TTCAN_RX0
#define CY_CANFD0_TX_PORT                       GPIO_PRT5
#define CY_CANFD0_TX_PIN                        4
#define CY_CANFD0_TX_MUX                        P5_4_CANFD0_TTCAN_TX0
#define CY_CANFD0_PCLK                          PCLK_CANFD0_CLOCK_CAN0
#define CY_CANFD0_IRQN                          canfd_0_interrupts0_0_IRQn
  
/* CAN2 */    
#define CY_CANFD1_TYPE                          CY_CANFD1_0_TYPE
#define CY_CANFD1_RX_PORT                       GPIO_PRT4
#define CY_CANFD1_RX_PIN                        7
#define CY_CANFD1_RX_MUX                        P4_7_CANFD1_TTCAN_RX0
#define CY_CANFD1_TX_PORT                       GPIO_PRT4
#define CY_CANFD1_TX_PIN                        6
#define CY_CANFD1_TX_MUX                        P4_6_CANFD1_TTCAN_TX0
#define CY_CANFD1_PCLK                          PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD1_IRQN                          canfd_1_interrupts0_0_IRQn

/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/* LIN0 */
#define CY_LINCH0_TYPE                          LIN0_CH0
#define CY_LINCH0_RX_PORT                       GPIO_PRT1
#define CY_LINCH0_RX_PIN                        7
#define CY_LINCH0_RX_PIN_MUX                    P1_7_LIN0_LIN_RX0
#define CY_LINCH0_TX_PORT                       GPIO_PRT1
#define CY_LINCH0_TX_PIN                        6
#define CY_LINCH0_TX_PIN_MUX                    P1_6_LIN0_LIN_TX0
#define CY_LINCH0_PCLK                          PCLK_LIN0_CLOCK_CH_EN0
#define CY_LINCH0_IRQN                          lin_0_interrupts_0_IRQn

/******************************************************************************/
/*                      SMARTIO Block                                         */
/******************************************************************************/

/******************************************************************************/
/*                      AUDIO DAC Definitions                                 */
/******************************************************************************/

// No need to configure AUDIO-DAC io mux, it is available on J90 on board.

/* AUDIO-DAC Clock */
#define CY_AUDIO_DAC_MCK_PORT                   GPIO_PRT1
#define CY_AUDIO_DAC_MCK_PIN                    6
#define CY_AUDIO_DAC_MCK_PIN_MUX                P1_6_DAC0_DAC_MCK

/******************************************************************************/
/*                      Display Backlight Controls                            */
/******************************************************************************/

/* Display 1 Backlight */
#define CY_BL_DISP1_PWM_PORT                    GPIO_PRT7
#define CY_BL_DISP1_PWM_PIN                     2
#define CY_BL_DISP1_PWM_PIN_MUX                 P7_2_GPIO                      // use as GPIO for now (0% or 100% PWM)
  
/******************************************************************************/
/*                      Display #1 Definitions                                */
/******************************************************************************/
 
#define CY_BSP_HDR_DISP1_TTL_AVAILABLE

// Display 1 is multiplexed with TDM, Ethernet, Trace, Capture one of them can be used at a time.

#define CY_DISP1_CLK_PORT                       GPIO_PRT16
#define CY_DISP1_CLK_PIN                        2
#define CY_DISP1_CLK_PIN_MUX                    P16_2_VIDEOSS0_TTL_DSP1_CLOCK    // PCLK
    
#define CY_DISP1_CTRL0_PORT                     GPIO_PRT16
#define CY_DISP1_CTRL0_PIN                      3
#define CY_DISP1_CTRL0_PIN_MUX                  P16_3_VIDEOSS0_TTL_DSP1_CONTROL0 // LVALID
    
#define CY_DISP1_CTRL1_PORT                     GPIO_PRT16
#define CY_DISP1_CTRL1_PIN                      4
#define CY_DISP1_CTRL1_PIN_MUX                  P16_4_VIDEOSS0_TTL_DSP1_CONTROL1 // VSYNC
    
#define CY_DISP1_CTRL2_PORT                     GPIO_PRT16
#define CY_DISP1_CTRL2_PIN                      5
#define CY_DISP1_CTRL2_PIN_MUX                  P16_5_VIDEOSS0_TTL_DSP1_CONTROL2 // DE
    
#define CY_DISP1_DATA_A0_0_PORT                 GPIO_PRT16
#define CY_DISP1_DATA_A0_0_PIN                  1
#define CY_DISP1_DATA_A0_0_PIN_MUX              P16_1_VIDEOSS0_TTL_DSP1_DATA_A00 // RED0
    
#define CY_DISP1_DATA_A0_1_PORT                 GPIO_PRT15
#define CY_DISP1_DATA_A0_1_PIN                  7
#define CY_DISP1_DATA_A0_1_PIN_MUX              P15_7_VIDEOSS0_TTL_DSP1_DATA_A01 // RED2
    
#define CY_DISP1_DATA_A0_2_PORT                 GPIO_PRT15
#define CY_DISP1_DATA_A0_2_PIN                  5
#define CY_DISP1_DATA_A0_2_PIN_MUX              P15_5_VIDEOSS0_TTL_DSP1_DATA_A02 // RED4
    
#define CY_DISP1_DATA_A0_3_PORT                 GPIO_PRT15
#define CY_DISP1_DATA_A0_3_PIN                  3
#define CY_DISP1_DATA_A0_3_PIN_MUX              P15_3_VIDEOSS0_TTL_DSP1_DATA_A03 // RED6
    
#define CY_DISP1_DATA_A0_4_PORT                 GPIO_PRT15
#define CY_DISP1_DATA_A0_4_PIN                  1
#define CY_DISP1_DATA_A0_4_PIN_MUX              P15_1_VIDEOSS0_TTL_DSP1_DATA_A04 // GREEN0
    
#define CY_DISP1_DATA_A0_5_PORT                 GPIO_PRT14
#define CY_DISP1_DATA_A0_5_PIN                  7
#define CY_DISP1_DATA_A0_5_PIN_MUX              P14_7_VIDEOSS0_TTL_DSP1_DATA_A05 // GREEN2
    
#define CY_DISP1_DATA_A0_6_PORT                 GPIO_PRT14
#define CY_DISP1_DATA_A0_6_PIN                  5
#define CY_DISP1_DATA_A0_6_PIN_MUX              P14_5_VIDEOSS0_TTL_DSP1_DATA_A06 // GREEN4
    
#define CY_DISP1_DATA_A0_7_PORT                 GPIO_PRT14
#define CY_DISP1_DATA_A0_7_PIN                  3
#define CY_DISP1_DATA_A0_7_PIN_MUX              P14_3_VIDEOSS0_TTL_DSP1_DATA_A07 // GREEN6
    
#define CY_DISP1_DATA_A0_8_PORT                 GPIO_PRT12
#define CY_DISP1_DATA_A0_8_PIN                  1
#define CY_DISP1_DATA_A0_8_PIN_MUX              P12_1_VIDEOSS0_TTL_DSP1_DATA_A08 // BLUE0
    
#define CY_DISP1_DATA_A0_9_PORT                 GPIO_PRT11
#define CY_DISP1_DATA_A0_9_PIN                  7
#define CY_DISP1_DATA_A0_9_PIN_MUX              P11_7_VIDEOSS0_TTL_DSP1_DATA_A09 // BLUE2
    
#define CY_DISP1_DATA_A0_10_PORT                GPIO_PRT11
#define CY_DISP1_DATA_A0_10_PIN                 3
#define CY_DISP1_DATA_A0_10_PIN_MUX             P11_3_VIDEOSS0_TTL_DSP1_DATA_A010// BLUE4
    
#define CY_DISP1_DATA_A0_11_PORT                GPIO_PRT11
#define CY_DISP1_DATA_A0_11_PIN                 1
#define CY_DISP1_DATA_A0_11_PIN_MUX             P11_1_VIDEOSS0_TTL_DSP1_DATA_A011// BLUE6
    
#define CY_DISP1_DATA_A1_0_PORT                 GPIO_PRT16
#define CY_DISP1_DATA_A1_0_PIN                  0
#define CY_DISP1_DATA_A1_0_PIN_MUX              P16_0_VIDEOSS0_TTL_DSP1_DATA_A10 // RED1
    
#define CY_DISP1_DATA_A1_1_PORT                 GPIO_PRT15
#define CY_DISP1_DATA_A1_1_PIN                  6
#define CY_DISP1_DATA_A1_1_PIN_MUX              P15_6_VIDEOSS0_TTL_DSP1_DATA_A11 // RED3
    
#define CY_DISP1_DATA_A1_2_PORT                 GPIO_PRT15
#define CY_DISP1_DATA_A1_2_PIN                  4
#define CY_DISP1_DATA_A1_2_PIN_MUX              P15_4_VIDEOSS0_TTL_DSP1_DATA_A12 // RED5
    
#define CY_DISP1_DATA_A1_3_PORT                 GPIO_PRT15
#define CY_DISP1_DATA_A1_3_PIN                  2
#define CY_DISP1_DATA_A1_3_PIN_MUX              P15_2_VIDEOSS0_TTL_DSP1_DATA_A13 // RED7
    
#define CY_DISP1_DATA_A1_4_PORT                 GPIO_PRT15
#define CY_DISP1_DATA_A1_4_PIN                  0
#define CY_DISP1_DATA_A1_4_PIN_MUX              P15_0_VIDEOSS0_TTL_DSP1_DATA_A14 // GREEN1
    
#define CY_DISP1_DATA_A1_5_PORT                 GPIO_PRT14
#define CY_DISP1_DATA_A1_5_PIN                  6
#define CY_DISP1_DATA_A1_5_PIN_MUX              P14_6_VIDEOSS0_TTL_DSP1_DATA_A15 // GREEN3
    
#define CY_DISP1_DATA_A1_6_PORT                 GPIO_PRT14
#define CY_DISP1_DATA_A1_6_PIN                  4
#define CY_DISP1_DATA_A1_6_PIN_MUX              P14_4_VIDEOSS0_TTL_DSP1_DATA_A16 // GREEN5
    
#define CY_DISP1_DATA_A1_7_PORT                 GPIO_PRT14
#define CY_DISP1_DATA_A1_7_PIN                  2
#define CY_DISP1_DATA_A1_7_PIN_MUX              P14_2_VIDEOSS0_TTL_DSP1_DATA_A17 // GREEN7
    
#define CY_DISP1_DATA_A1_8_PORT                 GPIO_PRT12
#define CY_DISP1_DATA_A1_8_PIN                  0
#define CY_DISP1_DATA_A1_8_PIN_MUX              P12_0_VIDEOSS0_TTL_DSP1_DATA_A18 // BLUE1
    
#define CY_DISP1_DATA_A1_9_PORT                 GPIO_PRT11
#define CY_DISP1_DATA_A1_9_PIN                  6
#define CY_DISP1_DATA_A1_9_PIN_MUX              P11_6_VIDEOSS0_TTL_DSP1_DATA_A19 // BLUE3
    
#define CY_DISP1_DATA_A1_10_PORT                GPIO_PRT11
#define CY_DISP1_DATA_A1_10_PIN                 2
#define CY_DISP1_DATA_A1_10_PIN_MUX             P11_2_VIDEOSS0_TTL_DSP1_DATA_A110// BLUE5
    
#define CY_DISP1_DATA_A1_11_PORT                GPIO_PRT11
#define CY_DISP1_DATA_A1_11_PIN                 0
#define CY_DISP1_DATA_A1_11_PIN_MUX             P11_0_VIDEOSS0_TTL_DSP1_DATA_A111// BLUE7
  
// IO connections P6.3, P5.7, P7.1 and P7.3 kept for FX3 adapter control signals.

/******************************************************************************/
/*                      Capture #0 Definitions                                */
/******************************************************************************/

#define CY_BSP_HDR_CAP0_TTL_AVAILABLE

// Capture 0 is multiplexed with Display 1, one of them can be used at a time.
  
#define CY_CAP0_CLK_PORT                        GPIO_PRT15
#define CY_CAP0_CLK_PIN                         0
#define CY_CAP0_CLK_PIN_MUX                     P15_0_VIDEOSS0_TTL_CAP0_CLK      // CLK
                                          
#define CY_CAP0_DATA0_PORT                      GPIO_PRT16
#define CY_CAP0_DATA0_PIN                       2
#define CY_CAP0_DATA0_PIN_MUX                   P16_2_VIDEOSS0_TTL_CAP0_DATA0    // B0
                                          
#define CY_CAP0_DATA1_PORT                      GPIO_PRT16
#define CY_CAP0_DATA1_PIN                       1
#define CY_CAP0_DATA1_PIN_MUX                   P16_1_VIDEOSS0_TTL_CAP0_DATA1    // B1
                                          
#define CY_CAP0_DATA2_PORT                      GPIO_PRT16
#define CY_CAP0_DATA2_PIN                       0
#define CY_CAP0_DATA2_PIN_MUX                   P16_0_VIDEOSS0_TTL_CAP0_DATA2    // G2
                                          
#define CY_CAP0_DATA3_PORT                      GPIO_PRT15
#define CY_CAP0_DATA3_PIN                       7
#define CY_CAP0_DATA3_PIN_MUX                   P15_7_VIDEOSS0_TTL_CAP0_DATA3    // G3
                                          
#define CY_CAP0_DATA4_PORT                      GPIO_PRT15
#define CY_CAP0_DATA4_PIN                       6
#define CY_CAP0_DATA4_PIN_MUX                   P15_6_VIDEOSS0_TTL_CAP0_DATA4    // G4
                                          
#define CY_CAP0_DATA5_PORT                      GPIO_PRT15
#define CY_CAP0_DATA5_PIN                       5
#define CY_CAP0_DATA5_PIN_MUX                   P15_5_VIDEOSS0_TTL_CAP0_DATA5    // G5
                                          
#define CY_CAP0_DATA6_PORT                      GPIO_PRT15
#define CY_CAP0_DATA6_PIN                       4
#define CY_CAP0_DATA6_PIN_MUX                   P15_4_VIDEOSS0_TTL_CAP0_DATA6    // G6
                                          
#define CY_CAP0_DATA7_PORT                      GPIO_PRT15
#define CY_CAP0_DATA7_PIN                       3
#define CY_CAP0_DATA7_PIN_MUX                   P15_3_VIDEOSS0_TTL_CAP0_DATA7    // G7
                                          
#define CY_CAP0_DATA8_PORT                      GPIO_PRT9
#define CY_CAP0_DATA8_PIN                       7
#define CY_CAP0_DATA8_PIN_MUX                   P9_7_VIDEOSS0_TTL_CAP0_DATA8    // R0
                                          
#define CY_CAP0_DATA9_PORT                      GPIO_PRT9
#define CY_CAP0_DATA9_PIN                       6
#define CY_CAP0_DATA9_PIN_MUX                   P9_6_VIDEOSS0_TTL_CAP0_DATA9    // R1
                                          
#define CY_CAP0_DATA10_PORT                     GPIO_PRT9
#define CY_CAP0_DATA10_PIN                      5
#define CY_CAP0_DATA10_PIN_MUX                  P9_5_VIDEOSS0_TTL_CAP0_DATA10   // R2
                                          
#define CY_CAP0_DATA11_PORT                     GPIO_PRT9
#define CY_CAP0_DATA11_PIN                      4
#define CY_CAP0_DATA11_PIN_MUX                  P9_4_VIDEOSS0_TTL_CAP0_DATA11   // R3
                                          
#define CY_CAP0_DATA12_PORT                     GPIO_PRT9
#define CY_CAP0_DATA12_PIN                      3
#define CY_CAP0_DATA12_PIN_MUX                  P9_3_VIDEOSS0_TTL_CAP0_DATA12   // B2
                                          
#define CY_CAP0_DATA13_PORT                     GPIO_PRT9
#define CY_CAP0_DATA13_PIN                      2
#define CY_CAP0_DATA13_PIN_MUX                  P9_2_VIDEOSS0_TTL_CAP0_DATA13   // R4
                                          
#define CY_CAP0_DATA14_PORT                     GPIO_PRT9
#define CY_CAP0_DATA14_PIN                      1
#define CY_CAP0_DATA14_PIN_MUX                  P9_1_VIDEOSS0_TTL_CAP0_DATA14   // R5
                                          
#define CY_CAP0_DATA15_PORT                     GPIO_PRT9
#define CY_CAP0_DATA15_PIN                      0
#define CY_CAP0_DATA15_PIN_MUX                  P9_0_VIDEOSS0_TTL_CAP0_DATA15   // R6
                                          
#define CY_CAP0_DATA16_PORT                     GPIO_PRT8
#define CY_CAP0_DATA16_PIN                      7
#define CY_CAP0_DATA16_PIN_MUX                  P8_7_VIDEOSS0_TTL_CAP0_DATA16   // R7
                                          
#define CY_CAP0_DATA17_PORT                     GPIO_PRT8
#define CY_CAP0_DATA17_PIN                      6
#define CY_CAP0_DATA17_PIN_MUX                  P8_6_VIDEOSS0_TTL_CAP0_DATA17   // B7
                                          
#define CY_CAP0_DATA18_PORT                     GPIO_PRT8
#define CY_CAP0_DATA18_PIN                      5
#define CY_CAP0_DATA18_PIN_MUX                  P8_5_VIDEOSS0_TTL_CAP0_DATA18   // G0
                                          
#define CY_CAP0_DATA19_PORT                     GPIO_PRT8
#define CY_CAP0_DATA19_PIN                      4
#define CY_CAP0_DATA19_PIN_MUX                  P8_4_VIDEOSS0_TTL_CAP0_DATA19   // G1
                                          
#define CY_CAP0_DATA20_PORT                     GPIO_PRT8
#define CY_CAP0_DATA20_PIN                      3
#define CY_CAP0_DATA20_PIN_MUX                  P8_3_VIDEOSS0_TTL_CAP0_DATA20   // B3
                                          
#define CY_CAP0_DATA21_PORT                     GPIO_PRT8
#define CY_CAP0_DATA21_PIN                      2
#define CY_CAP0_DATA21_PIN_MUX                  P8_2_VIDEOSS0_TTL_CAP0_DATA21   // B4
                                          
#define CY_CAP0_DATA22_PORT                     GPIO_PRT8
#define CY_CAP0_DATA22_PIN                      1
#define CY_CAP0_DATA22_PIN_MUX                  P8_1_VIDEOSS0_TTL_CAP0_DATA22   // B5
                                          
#define CY_CAP0_DATA23_PORT                     GPIO_PRT8
#define CY_CAP0_DATA23_PIN                      0
#define CY_CAP0_DATA23_PIN_MUX                  P8_0_VIDEOSS0_TTL_CAP0_DATA23   // B6
                                          
#define CY_CAP0_DATA24_PORT                     GPIO_PRT7
#define CY_CAP0_DATA24_PIN                      7
#define CY_CAP0_DATA24_PIN_MUX                  P7_7_VIDEOSS0_TTL_CAP0_DATA24   // HSYNC
                                          
#define CY_CAP0_DATA25_PORT                     GPIO_PRT7
#define CY_CAP0_DATA25_PIN                      6
#define CY_CAP0_DATA25_PIN_MUX                  P7_6_VIDEOSS0_TTL_CAP0_DATA25   // VSYNC
                                          
#define CY_CAP0_DATA26_PORT                     GPIO_PRT7
#define CY_CAP0_DATA26_PIN                      5
#define CY_CAP0_DATA26_PIN_MUX                  P7_5_VIDEOSS0_TTL_CAP0_DATA26   // DE

/******************************************************************************/
/*                      FPD-LINK Definitions                                  */
/******************************************************************************/

// No need to configure FPDLINK io mux, it is a part of AMUXBUS.

/* FPDLINK Reference Clock */
#define CY_FPDLINK_CLK_REF_PORT                 GPIO_PRT16
#define CY_FPDLINK_CLK_REF_PIN                  4
#define CY_FPDLINK_CLK_REF_PIN_MUX              P16_4_VIDEOSS0_FPDLINK_CLKREF_GPIO

/* FPDLINK 0 Enable */
#define CY_FPDLINK0_BL_EN_PORT                  GPIO_PRT6
#define CY_FPDLINK0_BL_EN_PIN                   3
#define CY_FPDLINK0_BL_EN_PIN_MUX               P6_3_GPIO
  
/* FPDLINK 0 Pwm */
#define CY_FPDLINK0_BL_PWM_PORT                 GPIO_PRT7
#define CY_FPDLINK0_BL_PWM_PIN                  0
#define CY_FPDLINK0_BL_PWM_PIN_MUX              P7_0_GPIO

/******************************************************************************/
/*                      MIPI CSI-2 Definitions                                */
/******************************************************************************/

// No need to configure MIPI CSI io mux, it is a part of AMUXBUS.

/* MIPI IO Clock */
#define CY_MIPI_CSI_IO_CLK_PORT                 GPIO_PRT6
#define CY_MIPI_CSI_IO_CLK_PIN                  0
#define CY_MIPI_CSI_IO_CLK_PIN_MUX              P6_0_GPIO

/* MIPI Power Enable */
#define CY_MIPI_CSI_PWDN_PORT                   GPIO_PRT5
#define CY_MIPI_CSI_PWDN_PIN                    3
#define CY_MIPI_CSI_PWDN_PIN_MUX                P5_3_GPIO
  
/* MIPI CSI Communication Block */
#define CY_MIPI_CSI_I2C_TYPE                    SCB7
  
#define CY_MIPI_CSI_I2C_SDA_PORT                GPIO_PRT1
#define CY_MIPI_CSI_I2C_SDA_PIN                 4
#define CY_MIPI_CSI_I2C_SDA_PIN_MUX             P1_4_SCB7_I2C_SDA
  
#define CY_MIPI_CSI_I2C_SCL_PORT                GPIO_PRT1
#define CY_MIPI_CSI_I2C_SCL_PIN                 5
#define CY_MIPI_CSI_I2C_SCL_PIN_MUX             P1_5_SCB7_I2C_SCL
  
#define CY_MIPI_CSI_I2C_PCLK                    PCLK_SCB7_CLOCK
#define CY_MIPI_CSI_I2C_IRQN                    scb_7_interrupt_IRQn

/******************************************************************************/
/*                      CXPI Definitions                                      */
/******************************************************************************/

#define CY_CXPI0_TYPE                           CXPI0_CH0
  
#define CY_CXPI0_RX_PORT                        GPIO_PRT1
#define CY_CXPI0_RX_PIN                         7
#define CY_CXPI0_RX_PIN_MUX                     P1_7_CXPI0_CXPI_RX0
    
#define CY_CXPI0_TX_PORT                        GPIO_PRT1
#define CY_CXPI0_TX_PIN                         6
#define CY_CXPI0_TX_PIN_MUX                     P1_6_CXPI0_CXPI_TX0
    
#define CY_CXPI0_EN_PORT                        GPIO_PRT2
#define CY_CXPI0_EN_PIN                         1
#define CY_CXPI0_EN_PIN_MUX                     P2_1_CXPI0_CXPI_EN0
  
#define CY_CXPI0_PCLK                           PCLK_CXPI0_CLOCK_CH_EN0
#define CY_CXPI0_IRQN                           cxpi_0_interrupts_0_IRQn 

/******************************************************************************/
/*                      AUDIO-TDM Definitions                                 */
/******************************************************************************/

#define CY_AUDIOSS_TDM_TYPE                     TDM0_TDM_STRUCT2
  
#define CY_AUDIOSS_TDM0_TX_MCK_PORT             GPIO_PRT14
#define CY_AUDIOSS_TDM0_TX_MCK_PIN              2
#define CY_AUDIOSS_TDM0_TX_MCK_PIN_MUX          P14_2_TDM0_TDM_TX_MCK2
  
#define CY_AUDIOSS_TDM0_TX_SCK_PORT             GPIO_PRT14
#define CY_AUDIOSS_TDM0_TX_SCK_PIN              3
#define CY_AUDIOSS_TDM0_TX_SCK_PIN_MUX          P14_3_TDM0_TDM_TX_SCK2
  
#define CY_AUDIOSS_TDM0_TX_FSYNC_PORT           GPIO_PRT14
#define CY_AUDIOSS_TDM0_TX_FSYNC_PIN            4
#define CY_AUDIOSS_TDM0_TX_FSYNC_PIN_MUX        P14_4_TDM0_TDM_TX_FSYNC2
  
#define CY_AUDIOSS_TDM0_TX_SD_PORT              GPIO_PRT14
#define CY_AUDIOSS_TDM0_TX_SD_PIN               5
#define CY_AUDIOSS_TDM0_TX_SD_PIN_MUX           P14_5_TDM0_TDM_TX_SD2
  
#define CY_AUDIOSS_TDM0_RX_MCK_PORT             GPIO_PRT16
#define CY_AUDIOSS_TDM0_RX_MCK_PIN              2
#define CY_AUDIOSS_TDM0_RX_MCK_PIN_MUX          P16_2_TDM0_TDM_RX_MCK2
  
#define CY_AUDIOSS_TDM0_RX_SCK_PORT             GPIO_PRT16
#define CY_AUDIOSS_TDM0_RX_SCK_PIN              3
#define CY_AUDIOSS_TDM0_RX_SCK_PIN_MUX          P16_3_TDM0_TDM_RX_SCK2
  
#define CY_AUDIOSS_TDM0_RX_FSYNC_PORT           GPIO_PRT16
#define CY_AUDIOSS_TDM0_RX_FSYNC_PIN            4
#define CY_AUDIOSS_TDM0_RX_FSYNC_PIN_MUX        P16_4_TDM0_TDM_RX_FSYNC2
  
#define CY_AUDIOSS_TDM0_RX_SD_PORT              GPIO_PRT16
#define CY_AUDIOSS_TDM0_RX_SD_PIN               5
#define CY_AUDIOSS_TDM0_RX_SD_PIN_MUX           P16_5_TDM0_TDM_RX_SD2
  
#define CY_AUDIOSS_TDM0_TX_IRQN                 tdm_0_interrupts_tx_2_IRQn
#define CY_AUDIOSS_TDM0_RX_IRQN                 tdm_0_interrupts_rx_2_IRQn 

/* Audio Codec Communication Block */
#define CY_AUDIOSS_I2C_TYPE                     SCB3
  
#define CY_AUDIOSS_I2C_SDA_PORT                 GPIO_PRT4
#define CY_AUDIOSS_I2C_SDA_PIN                  4
#define CY_AUDIOSS_I2C_SDA_PIN_MUX              P4_4_SCB3_I2C_SDA
  
#define CY_AUDIOSS_I2C_SCL_PORT                 GPIO_PRT4
#define CY_AUDIOSS_I2C_SCL_PIN                  5
#define CY_AUDIOSS_I2C_SCL_PIN_MUX              P4_5_SCB3_I2C_SCL
  
#define CY_AUDIOSS_I2C_PCLK                     PCLK_SCB3_CLOCK
#define CY_AUDIOSS_I2C_IRQN                     scb_3_interrupt_IRQn

/******************************************************************************/
/*                      AUDIO-SG Definitions                                  */
/******************************************************************************/

// Sound Generator driver circuit is not present on board, so for testing SG fly
// wire can be connected to the external driver circuit.

#define CY_AUDIOSS_SG0_TYPE                      SG0_SG_STRUCT1
  
#define CY_AUDIOSS_SG0_AMPL_PORT                 GPIO_PRT4
#define CY_AUDIOSS_SG0_AMPL_PIN                  4
#define CY_AUDIOSS_SG0_AMPL_PIN_MUX              P4_4_SG0_SG_AMPL1
  
#define CY_AUDIOSS_SG0_TONE_PORT                 GPIO_PRT4
#define CY_AUDIOSS_SG0_TONE_PIN                  5
#define CY_AUDIOSS_SG0_TONE_PIN_MUX              P4_5_SG0_SG_TONE1
  
#define CY_AUDIOSS_SG0_IRQ_IRQN                  sg_0_interrupts_1_IRQn


/******************************************************************************/
/*                      SMARTIO Pin Definitions                               */
/******************************************************************************/

#define CY_SMARTIO_MACRO                        SMARTIO
#define CY_SMARTIO_PORT                         SMARTIO_PRT9
#define CY_SMARTIO_CLK                          PCLK_SMARTIO9_CLOCK

#define CY_SMARTIO_OUT_PORT                     GPIO_PRT9
#define CY_SMARTIO_OUT_PIN                      1
#define CY_SMARTIO_OUT_PORT_MUX                 P9_1_GPIO

#define CY_SMARTIO_IN_PORT                      GPIO_PRT9
#define CY_SMARTIO_IN_PIN                       0
#define CY_SMARTIO_IN_PORT_MUX                  P9_0_GPIO
#define CY_SMARTIO_IN_PORT_MUX_PWM              P9_0_TCPWM0_LINE264

#define CY_SMARTIO_IN2_PORT                     GPIO_PRT9
#define CY_SMARTIO_IN2_PIN                      2
#define CY_SMARTIO_IN2_PORT_MUX_PWM             P9_2_TCPWM0_LINE265

/* PWM PR Mode Configuration def */
#define CY_SMARTIO_TCPWM_GRP0_CNT               TCPWM0_GRP1_CNT8
#define CY_SMARTIO_TCPWM_PCLK                   PCLK_TCPWM0_CLOCKS264

#define CY_SMARTIO_TCPWM_GRP0_CNT2              TCPWM0_GRP1_CNT9
#define CY_SMARTIO_TCPWM_PCLK2                  PCLK_TCPWM0_CLOCKS265

/******************************************************************************/
/*                              EXT CLK PORT                                  */
/******************************************************************************/
#define HF3_CLK_OUT_PORT                         GPIO_PRT16
#define HF3_CLK_OUT_PIN                          (2ul)
#define HF3_CLK_OUT_PIN_MUX                      P16_2_SRSS_EXT_CLK


/******************************************************************************/
/******************************************************************************/

// tviic2d4m - 208-TEQFP Package devices
    
// #if (CY_USE_PSVP == 0) (--> Silicon), project setting CY_USE_PSVP should be changed to '0'
// select the supported or required device accordingly
  
#elif (CY_USE_PSVP == 0) && defined(CYT3DL9BGS)

/******************************************************************************/
/******************************************************************************/

// CPU Board Entities

/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/*                      USER LED's                                            */
/******************************************************************************/    



/******************************************************************************/
/*                      USER BUTTON's                                         */
/******************************************************************************/


/******************************************************************************/
/*                      ADC POT                                               */
/******************************************************************************/


/******************************************************************************/
/*                      SCB Mux                                               */
/******************************************************************************/

/******************************************************************************/
/*                      SMIF0 Definitions                                     */
/******************************************************************************/

/******************************************************************************/
/*                      SMIF1 Definitions                                     */
/******************************************************************************/

/******************************************************************************/
/*                      AUDIOSS PCM-PWM                                       */
/******************************************************************************/

/******************************************************************************/
/*                      GIGA ETH Port                                         */
/******************************************************************************/

/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/

/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/******************************************************************************/
/*                      SMARTIO Block                                         */
/******************************************************************************/

/******************************************************************************/
/*                      AUDIO DAC Definitions                                 */
/******************************************************************************/

/******************************************************************************/
/*                      Display Backlight Controls                            */
/******************************************************************************/

/******************************************************************************/
/*                      Display #0 Definitions                                */
/******************************************************************************/
 
/******************************************************************************/
/*                      Display #1 Definitions                                */
/******************************************************************************/
  
/******************************************************************************/
/*                      Capture #0 Definitions                                */
/******************************************************************************/

/******************************************************************************/
/*                      FPD-LINK Definitions                                  */
/******************************************************************************/

/******************************************************************************/
/*                      MIPI CSI-2 Definitions                                */
/******************************************************************************/

/******************************************************************************/
/*                      CXPI Definitions                                      */
/******************************************************************************/

/******************************************************************************/
/*                      AUDIO-TDM Definitions                                 */
/******************************************************************************/

/******************************************************************************/
/*                      AUDIO-SG Definitions                                  */
/******************************************************************************/

/******************************************************************************/
/*                      AUDIO-TDM Definitions                                 */
/******************************************************************************/

/******************************************************************************/
/*                              EXT CLK PORT                                  */
/******************************************************************************/
#define HF3_CLK_OUT_PORT                         GPIO_PRT0
#define HF3_CLK_OUT_PIN                          (2ul)
#define HF3_CLK_OUT_PIN_MUX                      P0_2_SRSS_EXT_CLK

/******************************************************************************/
/******************************************************************************/

#else // No Device or PSVP Selected

    #error "Choose either a Device based on TVII-C-2D-4M Datasheet or CY_USE_PSVP"

#endif // #if (CY_USE_PSVP == 1)


#ifdef __cplusplus
}
#endif

#endif /* BB_BSP_TVIIC2D4M_H */

/* [] END OF FILE */
