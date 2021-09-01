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

#ifndef BB_BSP_TVIIC2D6M_H
#define BB_BSP_TVIIC2D6M_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/******************************************************************************/

// PSVP supports only 500-bga package

#if (CY_USE_PSVP == 1) && defined (CYT4DNDBHS)

// Adapter Board Entities

/******************************************************************************/
/*                      USER LED AB Mux (GPIO_133)                            */
/******************************************************************************/
#define CY_AB_LED_PORT                  GPIO_PRT7
#define CY_AB_LED_PIN                   5
#define CY_AB_LED_PIN_MUX               P7_5_GPIO

/******************************************************************************/
/*                      Button AB Mux (GPIO_134)                              */
/******************************************************************************/
#define CY_AB_BUTTON_PORT               GPIO_PRT4
#define CY_AB_BUTTON_PIN                7
#define CY_AB_BUTTON_PIN_MUX            P4_7_GPIO

/* Setup GPIO for BUTTON AB interrupt sources */
#define CY_AB_BUTTON_IRQN               ioss_interrupts_gpio_dpslp_4_IRQn

/******************************************************************************/
/*                      SCB AB Mux                                            */
/******************************************************************************/
/* USB-UART Mux */
#define CY_USB_SCB_TYPE                 SCB1
#define CY_USB_SCB_UART_RX_PORT         GPIO_PRT15
#define CY_USB_SCB_UART_RX_PIN          2
#define CY_USB_SCB_UART_RX_MUX          P15_2_SCB1_UART_RX
#define CY_USB_SCB_UART_TX_PORT         GPIO_PRT15
#define CY_USB_SCB_UART_TX_PIN          3
#define CY_USB_SCB_UART_TX_MUX          P15_3_SCB1_UART_TX
#define CY_USB_SCB_UART_PCLK            PCLK_SCB1_CLOCK
#define CY_USB_SCB_UART_IRQN            scb_1_interrupt_IRQn

/******************************************************************************/
/*                      SMIF0 Definitions                                     */
/******************************************************************************/
#define CY_BSP_HDR_SMIF0_AVAILABLE             // Definitions for this functionality are available

#define CY_SMIF_S25FXXXS                       (0u)
#define CY_SMIF_S25FXXXL                       (1u)

#define CY_SMIF0_CLK_PORT                      GPIO_PRT24
#define CY_SMIF0_CLK_PIN                       1
#define CY_SMIF0_CLK_PIN_MUX                   P24_1_SMIF0_SPIHB_CLK

#define CY_SMIF0_RWDS_PORT                     GPIO_PRT23
#define CY_SMIF0_RWDS_PIN                      4
#define CY_SMIF0_RWDS_PIN_MUX                  P23_4_SMIF0_SPIHB_RWDS

#define CY_SMIF0_SELECT0_PORT                  GPIO_PRT25
#define CY_SMIF0_SELECT0_PIN                   2
#define CY_SMIF0_SELECT0_PIN_MUX               P25_2_SMIF0_SPIHB_SELECT0

#define CY_SMIF0_SELECT1_PORT                  GPIO_PRT25
#define CY_SMIF0_SELECT1_PIN                   5
#define CY_SMIF0_SELECT1_PIN_MUX               P25_5_SMIF0_SPIHB_SELECT1

#define CY_SMIF0_DATA0_PORT                    GPIO_PRT25
#define CY_SMIF0_DATA0_PIN                     0
#define CY_SMIF0_DATA0_PIN_MUX                 P25_0_SMIF0_SPIHB_DATA0

#define CY_SMIF0_DATA1_PORT                    GPIO_PRT25
#define CY_SMIF0_DATA1_PIN                     3
#define CY_SMIF0_DATA1_PIN_MUX                 P25_3_SMIF0_SPIHB_DATA1

#define CY_SMIF0_DATA2_PORT                    GPIO_PRT23
#define CY_SMIF0_DATA2_PIN                     1
#define CY_SMIF0_DATA2_PIN_MUX                 P23_1_SMIF0_SPIHB_DATA2

#define CY_SMIF0_DATA3_PORT                    GPIO_PRT23
#define CY_SMIF0_DATA3_PIN                     2
#define CY_SMIF0_DATA3_PIN_MUX                 P23_2_SMIF0_SPIHB_DATA3

#define CY_SMIF0_DATA4_PORT                    GPIO_PRT23
#define CY_SMIF0_DATA4_PIN                     0
#define CY_SMIF0_DATA4_PIN_MUX                 P23_0_SMIF0_SPIHB_DATA4

#define CY_SMIF0_DATA5_PORT                    GPIO_PRT23
#define CY_SMIF0_DATA5_PIN                     3
#define CY_SMIF0_DATA5_PIN_MUX                 P23_3_SMIF0_SPIHB_DATA5

#define CY_SMIF0_DATA6_PORT                    GPIO_PRT25
#define CY_SMIF0_DATA6_PIN                     1
#define CY_SMIF0_DATA6_PIN_MUX                 P25_1_SMIF0_SPIHB_DATA6

#define CY_SMIF0_DATA7_PORT                    GPIO_PRT25
#define CY_SMIF0_DATA7_PIN                     4
#define CY_SMIF0_DATA7_PIN_MUX                 P25_4_SMIF0_SPIHB_DATA7

#define CY_SMIF0_QUAD_MEMORY                   CY_SMIF_S25FXXXS

// BB Board Entities

/******************************************************************************/
/*                      LEDs Base Board Mux                                   */
/******************************************************************************/
#define CY_LED0_PORT                    GPIO_PRT7
#define CY_LED0_PIN                     1
#define CY_LED0_PIN_MUX                 P7_1_GPIO

#define CY_LED1_PORT                    GPIO_PRT4
#define CY_LED1_PIN                     5
#define CY_LED1_PIN_MUX                 P4_5_GPIO

#define CY_LED2_PORT                    GPIO_PRT3
#define CY_LED2_PIN                     4
#define CY_LED2_PIN_MUX                 P3_4_GPIO

#define CY_LED3_PORT                    GPIO_PRT2
#define CY_LED3_PIN                     1
#define CY_LED3_PIN_MUX                 P2_1_GPIO

#define CY_LED4_PORT                    GPIO_PRT7
#define CY_LED4_PIN                     6
#define CY_LED4_PIN_MUX                 P7_6_GPIO

#define CY_LED5_PORT                    GPIO_PRT7
#define CY_LED5_PIN                     4
#define CY_LED5_PIN_MUX                 P7_4_GPIO

#define CY_LED6_PORT                    GPIO_PRT4
#define CY_LED6_PIN                     6
#define CY_LED6_PIN_MUX                 P4_6_GPIO

#define CY_LED7_PORT                    GPIO_PRT3
#define CY_LED7_PIN                     1
#define CY_LED7_PIN_MUX                 P3_1_GPIO

#define CY_LED8_PORT                    GPIO_PRT2
#define CY_LED8_PIN                     2
#define CY_LED8_PIN_MUX                 P2_2_GPIO

#define CY_LED9_PORT                    GPIO_PRT7
#define CY_LED9_PIN                     7
#define CY_LED9_PIN_MUX                 P7_7_GPIO

/******************************************************************************/
/*                      Buttons Base Board Mux                                */
/******************************************************************************/
#define CY_BUTTON1_PORT                 GPIO_PRT7
#define CY_BUTTON1_PIN                  2
#define CY_BUTTON1_PIN_MUX              P7_2_GPIO

#define CY_BUTTON2_PORT                 GPIO_PRT4
#define CY_BUTTON2_PIN                  4
#define CY_BUTTON2_PIN_MUX              P4_4_GPIO

#define CY_BUTTON3_PORT                 GPIO_PRT2
#define CY_BUTTON3_PIN                  0
#define CY_BUTTON3_PIN_MUX              P2_0_GPIO

#define CY_BUTTON4_PORT                 GPIO_PRT12
#define CY_BUTTON4_PIN                  1
#define CY_BUTTON4_PIN_MUX              P12_1_GPIO

#define CY_BUTTON5_PORT                 GPIO_PRT7
#define CY_BUTTON5_PIN                  3
#define CY_BUTTON5_PIN_MUX              P7_3_GPIO

/* Setup GPIO for BUTTONs 1/2/3/4/5 interrupt sources */
#define CY_BUTTON1_IRQN                 ioss_interrupts_gpio_dpslp_7_IRQn
#define CY_BUTTON2_IRQN                 ioss_interrupts_gpio_dpslp_4_IRQn
#define CY_BUTTON3_IRQN                 ioss_interrupts_gpio_dpslp_2_IRQn
#define CY_BUTTON4_IRQN                 ioss_interrupts_gpio_dpslp_12_IRQn
#define CY_BUTTON5_IRQN                 ioss_interrupts_gpio_dpslp_7_IRQn

/******************************************************************************/
/*                      ADC POT                                               */
/******************************************************************************/

#define CY_ADC_POT_MACRO                PASS0_SAR0
#define CY_ADC_POT_IN_NO               	18
#define CY_ADC_POT_PORT                 GPIO_PRT0
#define CY_ADC_POT_PIN                  6
#define CY_ADC_POT_PIN_MUX              P0_6_GPIO
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
#define CY_CANFD0_TYPE                  CY_CANFD1_0_TYPE
#define CY_CANFD0_RX_PORT               GPIO_PRT21
#define CY_CANFD0_RX_PIN                3
#define CY_CANFD0_RX_MUX                P21_3_CANFD1_TTCAN_RX0
#define CY_CANFD0_TX_PORT               GPIO_PRT21
#define CY_CANFD0_TX_PIN                2
#define CY_CANFD0_TX_MUX                P21_2_CANFD1_TTCAN_TX0
#define CY_CANFD0_PCLK                  PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD0_IRQN                  canfd_1_interrupts0_0_IRQn

/* CAN1 Pin Mux */
#define CY_CANFD1_TYPE                  CY_CANFD1_3_TYPE                   // TODO
#define CY_CANFD1_RX_PORT               GPIO_PRT15                         // TODO
#define CY_CANFD1_RX_PIN                1                                  // TODO
#define CY_CANFD1_RX_MUX                P15_1_CANFD1_TTCAN_RX3             // TODO
#define CY_CANFD1_TX_PORT               GPIO_PRT15                         // TODO
#define CY_CANFD1_TX_PIN                0                                  // TODO
#define CY_CANFD1_TX_MUX                P15_0_CANFD1_TTCAN_TX3             // TODO
#define CY_CANFD1_PCLK                  PCLK_CANFD1_CLOCK_CAN3             // TODO
#define CY_CANFD1_IRQN                  canfd_1_interrupts0_3_IRQn         // TODO

/* CAN2 Pin Mux */                                                         // TODO
#define CY_CANFD2_TYPE                  CY_CANFD0_2_TYPE                   // TODO
#define CY_CANFD2_RX_PORT               GPIO_PRT6                          // TODO
#define CY_CANFD2_RX_PIN                3                                  // TODO
#define CY_CANFD2_RX_MUX                P6_3_CANFD0_TTCAN_RX2              // TODO
#define CY_CANFD2_TX_PORT               GPIO_PRT12                         // TODO
#define CY_CANFD2_TX_PIN                0                                  // TODO
#define CY_CANFD2_TX_MUX                P12_0_CANFD0_TTCAN_TX2             // TODO
#define CY_CANFD2_PCLK                  PCLK_CANFD0_CLOCK_CAN2             // TODO
#define CY_CANFD2_IRQN                  canfd_0_interrupts0_2_IRQn         // TODO

/* CAN3 Pin Mux */                                                         // TODO
#define CY_CANFD3_TYPE                  CY_CANFD1_0_TYPE                   // TODO
#define CY_CANFD3_RX_PORT               GPIO_PRT23                         // TODO
#define CY_CANFD3_RX_PIN                1                                  // TODO
#define CY_CANFD3_RX_MUX                P23_1_CANFD1_TTCAN_RX0             // TODO
#define CY_CANFD3_TX_PORT               GPIO_PRT14                         // TODO
#define CY_CANFD3_TX_PIN                0                                  // TODO
#define CY_CANFD3_TX_MUX                P14_0_CANFD1_TTCAN_TX0             // TODO
#define CY_CANFD3_PCLK                  PCLK_CANFD1_CLOCK_CAN0             // TODO
#define CY_CANFD3_IRQN                  canfd_1_interrupts0_0_IRQn         // TODO

/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/* LIN Channel 0 */
#define CY_LINCH0_TYPE                  LIN0_CH0                            // TODO
#define CY_LINCH0_RX_PORT               GPIO_PRT1                           // TODO
#define CY_LINCH0_RX_PIN                2                                   // TODO
#define CY_LINCH0_RX_PIN_MUX            P1_2_LIN0_LIN_RX0                   // TODO
#define CY_LINCH0_TX_PORT               GPIO_PRT21                          // TODO
#define CY_LINCH0_TX_PIN                6                                   // TODO
#define CY_LINCH0_TX_PIN_MUX            P21_6_LIN0_LIN_TX0                  // TODO
#define CY_LINCH0_PCLK                  PCLK_LIN0_CLOCK_CH_EN0              // TODO
#define CY_LINCH0_IRQN                  lin_0_interrupts_0_IRQn             // TODO

/* LIN Channel 1 */
#define CY_LINCH1_TYPE                  LIN0_CH6                            // TODO
#define CY_LINCH1_RX_PORT               GPIO_PRT12                          // TODO
#define CY_LINCH1_RX_PIN                2                                   // TODO
#define CY_LINCH1_RX_PIN_MUX            P12_2_LIN0_LIN_RX6                  // TODO
#define CY_LINCH1_TX_PORT               GPIO_PRT12                          // TODO
#define CY_LINCH1_TX_PIN                3                                   // TODO
#define CY_LINCH1_TX_PIN_MUX            P12_3_LIN0_LIN_TX6                  // TODO
#define CY_LINCH1_PCLK                  PCLK_LIN0_CLOCK_CH_EN6              // TODO
#define CY_LINCH1_IRQN                  lin_0_interrupts_6_IRQn

/******************************************************************************/
/*                      SMARTIO Base Board Mux                                */
/******************************************************************************/

#define CY_SMARTIO_MACRO                SMARTIO
#define CY_SMARTIO_PORT                 SMARTIO_PRT7
#define CY_SMARTIO_CLK                  PCLK_SMARTIO7_CLOCK
  
#define CY_SMARTIO_OUT_PORT             GPIO_PRT7
#define CY_SMARTIO_OUT_PIN              2
#define CY_SMARTIO_OUT_PORT_MUX         P7_2_GPIO
  
#define CY_SMARTIO_IN_PORT              GPIO_PRT7
#define CY_SMARTIO_IN_PIN               1
#define CY_SMARTIO_IN_PORT_MUX          P7_1_GPIO
#define CY_SMARTIO_IN_PORT_MUX_PWM      P7_1_TCPWM0_LINE21

#define CY_SMARTIO_IN2_PORT             GPIO_PRT7
#define CY_SMARTIO_IN2_PIN              3
#define CY_SMARTIO_IN2_PORT_MUX         P7_3_GPIO
#define CY_SMARTIO_IN2_PORT_MUX_PWM     P7_3_TCPWM0_LINE23

/* PWM PR Mode Configuration def */
#define CY_SMARTIO_TCPWM_GRP0_CNT       TCPWM0_GRP0_CNT21
#define CY_SMARTIO_TCPWM_PCLK           PCLK_TCPWM0_CLOCKS21

#define CY_SMARTIO_TCPWM_GRP0_CNT2      TCPWM0_GRP0_CNT23
#define CY_SMARTIO_TCPWM_PCLK2          PCLK_TCPWM0_CLOCKS23

// Cluster Extension Board entities

/******************************************************************************/
/*                      USER LED CEB Mux (GPIO_202)                           */
/******************************************************************************/

#define CY_CEB_LED_PORT                         GPIO_PRT13                          // TODO for CFR, configuring unused GPIO_002 net on AB for now
#define CY_CEB_LED_PIN                          4                                   // TODO for CFR, configuring unused GPIO_002 net on AB for now
#define CY_CEB_LED_PIN_MUX                      P13_4_GPIO                          // TODO for CFR, configuring unused GPIO_002 net on AB for now

/******************************************************************************/
/*                      Button CEB Mux (GPIO_201)                             */
/******************************************************************************/

#define CY_CEB_BUTTON_PORT                      GPIO_PRT13                          // TODO for CFR, configuring unused GPIO_003 net on AB for now
#define CY_CEB_BUTTON_PIN                       1                                   // TODO for CFR, configuring unused GPIO_003 net on AB for now
#define CY_CEB_BUTTON_PIN_MUX                   P13_1_GPIO                          // TODO for CFR, configuring unused GPIO_003 net on AB for now

#define CY_CEB_BUTTON_IRQN                      ioss_interrupts_gpio_dpslp_13_IRQn  // TODO for CFR, configuring unused GPIO_003 net on AB for now

/******************************************************************************/
/*                      SMIF1 Definitions                                     */
/******************************************************************************/
#define CY_BSP_HDR_SMIF1_AVAILABLE             // Definitions for this functionality are available


#define CY_SMIF1_CLK_PORT                      GPIO_PRT27
#define CY_SMIF1_CLK_PIN                       1
#define CY_SMIF1_CLK_PIN_MUX                   P27_1_SMIF1_SPIHB_CLK

#define CY_SMIF1_RWDS_PORT                     GPIO_PRT26
#define CY_SMIF1_RWDS_PIN                      4
#define CY_SMIF1_RWDS_PIN_MUX                  P26_4_SMIF1_SPIHB_RWDS

#define CY_SMIF1_SELECT0_PORT                  GPIO_PRT28
#define CY_SMIF1_SELECT0_PIN                   2
#define CY_SMIF1_SELECT0_PIN_MUX               P28_2_SMIF1_SPIHB_SELECT0

#define CY_SMIF1_SELECT1_PORT                  GPIO_PRT28
#define CY_SMIF1_SELECT1_PIN                   5
#define CY_SMIF1_SELECT1_PIN_MUX               P28_5_SMIF1_SPIHB_SELECT1

#define CY_SMIF1_DATA0_PORT                    GPIO_PRT28
#define CY_SMIF1_DATA0_PIN                     0
#define CY_SMIF1_DATA0_PIN_MUX                 P28_0_SMIF1_SPIHB_DATA0

#define CY_SMIF1_DATA1_PORT                    GPIO_PRT28
#define CY_SMIF1_DATA1_PIN                     3
#define CY_SMIF1_DATA1_PIN_MUX                 P28_3_SMIF1_SPIHB_DATA1

#define CY_SMIF1_DATA2_PORT                    GPIO_PRT26
#define CY_SMIF1_DATA2_PIN                     1
#define CY_SMIF1_DATA2_PIN_MUX                 P26_1_SMIF1_SPIHB_DATA2

#define CY_SMIF1_DATA3_PORT                    GPIO_PRT26
#define CY_SMIF1_DATA3_PIN                     2
#define CY_SMIF1_DATA3_PIN_MUX                 P26_2_SMIF1_SPIHB_DATA3

#define CY_SMIF1_DATA4_PORT                    GPIO_PRT26
#define CY_SMIF1_DATA4_PIN                     0
#define CY_SMIF1_DATA4_PIN_MUX                 P26_0_SMIF1_SPIHB_DATA4

#define CY_SMIF1_DATA5_PORT                    GPIO_PRT26
#define CY_SMIF1_DATA5_PIN                     3
#define CY_SMIF1_DATA5_PIN_MUX                 P26_3_SMIF1_SPIHB_DATA5

#define CY_SMIF1_DATA6_PORT                    GPIO_PRT28
#define CY_SMIF1_DATA6_PIN                     1
#define CY_SMIF1_DATA6_PIN_MUX                 P28_1_SMIF1_SPIHB_DATA6

#define CY_SMIF1_DATA7_PORT                    GPIO_PRT28
#define CY_SMIF1_DATA7_PIN                     4
#define CY_SMIF1_DATA7_PIN_MUX                 P28_4_SMIF1_SPIHB_DATA7

#define CY_SMIF1_QUAD_MEMORY                   CY_SMIF_S25FXXXS


/******************************************************************************/
/*                 Backlight Display #0 Definitions                           */
/******************************************************************************/

// #define CY_BL_DISP0_EN_PORT                    GPIO_PRT?      // only jumper, not SW controllable
// #define CY_BL_DISP0_EN_PIN                     ?              // only jumper, not SW controllable
// #define CY_BL_DISP0_EN_PIN_MUX                 P?_?_GPIO      // only jumper, not SW controllable

#define CY_BL_DISP0_PWM_PORT                   GPIO_PRT13                                             // TODO for CFR, configuring unused GPIO_006 net on AB for now
#define CY_BL_DISP0_PWM_PIN                    6                                                      // TODO for CFR, configuring unused GPIO_006 net on AB for now
#define CY_BL_DISP0_PWM_PIN_MUX                P13_6_GPIO  // use as GPIO for now (0% or 100% PWM)    // TODO for CFR, configuring unused GPIO_006 net on AB for now

/******************************************************************************/
/*                 Backlight Display #1 Definitions                           */
/******************************************************************************/

// #define CY_BL_DISP1_EN_PORT                    GPIO_PRT?      // only jumper, not SW controllable
// #define CY_BL_DISP1_EN_PIN                     ?              // only jumper, not SW controllable
// #define CY_BL_DISP1_EN_PIN_MUX                 P?_?_GPIO      // only jumper, not SW controllable

#define CY_BL_DISP1_PWM_PORT                   GPIO_PRT13                                             // TODO for CFR, configuring unused GPIO_007 net on AB for now
#define CY_BL_DISP1_PWM_PIN                    7                                                      // TODO for CFR, configuring unused GPIO_007 net on AB for now
#define CY_BL_DISP1_PWM_PIN_MUX                P13_7_GPIO  // use as GPIO for now (0% or 100% PWM)    // TODO for CFR, configuring unused GPIO_007 net on AB for now

/******************************************************************************/
/*                      Display #0 Definitions                                */
/******************************************************************************/
#define CY_BSP_HDR_DISP0_TTL_AVAILABLE         // Definitions for this functionality are available

#define CY_DISP0_CLK_PORT                      GPIO_PRT8
#define CY_DISP0_CLK_PIN                       3
#define CY_DISP0_CLK_PIN_MUX                   P8_3_VIDEOSS0_TTL_DSP0_CLOCK

#define CY_DISP0_CTRL0_PORT                    GPIO_PRT8
#define CY_DISP0_CTRL0_PIN                     0
#define CY_DISP0_CTRL0_PIN_MUX                 P8_0_VIDEOSS0_TTL_DSP0_CONTROL0

#define CY_DISP0_CTRL1_PORT                    GPIO_PRT8
#define CY_DISP0_CTRL1_PIN                     1
#define CY_DISP0_CTRL1_PIN_MUX                 P8_1_VIDEOSS0_TTL_DSP0_CONTROL1

#define CY_DISP0_CTRL2_PORT                    GPIO_PRT8
#define CY_DISP0_CTRL2_PIN                     2
#define CY_DISP0_CTRL2_PIN_MUX                 P8_2_VIDEOSS0_TTL_DSP0_CONTROL2

#define CY_DISP0_DATA_A0_0_PORT                GPIO_PRT12
#define CY_DISP0_DATA_A0_0_PIN                 2
#define CY_DISP0_DATA_A0_0_PIN_MUX             P12_2_VIDEOSS0_TTL_DSP0_DATA_A00

#define CY_DISP0_DATA_A0_1_PORT                GPIO_PRT12
#define CY_DISP0_DATA_A0_1_PIN                 4
#define CY_DISP0_DATA_A0_1_PIN_MUX             P12_4_VIDEOSS0_TTL_DSP0_DATA_A01

#define CY_DISP0_DATA_A0_2_PORT                GPIO_PRT12
#define CY_DISP0_DATA_A0_2_PIN                 6
#define CY_DISP0_DATA_A0_2_PIN_MUX             P12_6_VIDEOSS0_TTL_DSP0_DATA_A02

#define CY_DISP0_DATA_A0_3_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A0_3_PIN                 0
#define CY_DISP0_DATA_A0_3_PIN_MUX             P5_0_VIDEOSS0_TTL_DSP0_DATA_A03

#define CY_DISP0_DATA_A0_4_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A0_4_PIN                 2
#define CY_DISP0_DATA_A0_4_PIN_MUX             P5_2_VIDEOSS0_TTL_DSP0_DATA_A04

#define CY_DISP0_DATA_A0_5_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A0_5_PIN                 4
#define CY_DISP0_DATA_A0_5_PIN_MUX             P5_4_VIDEOSS0_TTL_DSP0_DATA_A05

#define CY_DISP0_DATA_A0_6_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A0_6_PIN                 6
#define CY_DISP0_DATA_A0_6_PIN_MUX             P5_6_VIDEOSS0_TTL_DSP0_DATA_A06

#define CY_DISP0_DATA_A0_7_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A0_7_PIN                 0
#define CY_DISP0_DATA_A0_7_PIN_MUX             P6_0_VIDEOSS0_TTL_DSP0_DATA_A07

#define CY_DISP0_DATA_A0_8_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A0_8_PIN                 2
#define CY_DISP0_DATA_A0_8_PIN_MUX             P6_2_VIDEOSS0_TTL_DSP0_DATA_A08

#define CY_DISP0_DATA_A0_9_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A0_9_PIN                 4
#define CY_DISP0_DATA_A0_9_PIN_MUX             P6_4_VIDEOSS0_TTL_DSP0_DATA_A09

#define CY_DISP0_DATA_A0_10_PORT               GPIO_PRT6
#define CY_DISP0_DATA_A0_10_PIN                6
#define CY_DISP0_DATA_A0_10_PIN_MUX            P6_6_VIDEOSS0_TTL_DSP0_DATA_A010

#define CY_DISP0_DATA_A0_11_PORT               GPIO_PRT7
#define CY_DISP0_DATA_A0_11_PIN                0
#define CY_DISP0_DATA_A0_11_PIN_MUX            P7_0_VIDEOSS0_TTL_DSP0_DATA_A011

#define CY_DISP0_DATA_A1_0_PORT                GPIO_PRT12
#define CY_DISP0_DATA_A1_0_PIN                 3
#define CY_DISP0_DATA_A1_0_PIN_MUX             P12_3_VIDEOSS0_TTL_DSP0_DATA_A10

#define CY_DISP0_DATA_A1_1_PORT                GPIO_PRT12
#define CY_DISP0_DATA_A1_1_PIN                 5
#define CY_DISP0_DATA_A1_1_PIN_MUX             P12_5_VIDEOSS0_TTL_DSP0_DATA_A11

#define CY_DISP0_DATA_A1_2_PORT                GPIO_PRT12
#define CY_DISP0_DATA_A1_2_PIN                 7
#define CY_DISP0_DATA_A1_2_PIN_MUX             P12_7_VIDEOSS0_TTL_DSP0_DATA_A12

#define CY_DISP0_DATA_A1_3_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A1_3_PIN                 1
#define CY_DISP0_DATA_A1_3_PIN_MUX             P5_1_VIDEOSS0_TTL_DSP0_DATA_A13

#define CY_DISP0_DATA_A1_4_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A1_4_PIN                 3
#define CY_DISP0_DATA_A1_4_PIN_MUX             P5_3_VIDEOSS0_TTL_DSP0_DATA_A14

#define CY_DISP0_DATA_A1_5_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A1_5_PIN                 5
#define CY_DISP0_DATA_A1_5_PIN_MUX             P5_5_VIDEOSS0_TTL_DSP0_DATA_A15

#define CY_DISP0_DATA_A1_6_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A1_6_PIN                 7
#define CY_DISP0_DATA_A1_6_PIN_MUX             P5_7_VIDEOSS0_TTL_DSP0_DATA_A16

#define CY_DISP0_DATA_A1_7_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A1_7_PIN                 1
#define CY_DISP0_DATA_A1_7_PIN_MUX             P6_1_VIDEOSS0_TTL_DSP0_DATA_A17

#define CY_DISP0_DATA_A1_8_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A1_8_PIN                 3
#define CY_DISP0_DATA_A1_8_PIN_MUX             P6_3_VIDEOSS0_TTL_DSP0_DATA_A18

#define CY_DISP0_DATA_A1_9_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A1_9_PIN                 5
#define CY_DISP0_DATA_A1_9_PIN_MUX             P6_5_VIDEOSS0_TTL_DSP0_DATA_A19

#define CY_DISP0_DATA_A1_10_PORT               GPIO_PRT6
#define CY_DISP0_DATA_A1_10_PIN                7
#define CY_DISP0_DATA_A1_10_PIN_MUX            P6_7_VIDEOSS0_TTL_DSP0_DATA_A110

#define CY_DISP0_DATA_A1_11_PORT               GPIO_PRT0
#define CY_DISP0_DATA_A1_11_PIN                7
#define CY_DISP0_DATA_A1_11_PIN_MUX            P0_7_VIDEOSS0_TTL_DSP0_DATA_A111

/******************************************************************************/
/*                      Display #1 Definitions                                */
/******************************************************************************/
#define CY_BSP_HDR_DISP1_TTL_AVAILABLE         // Definitions for this functionality are available

#define CY_DISP1_CLK_PORT                      GPIO_PRT21
#define CY_DISP1_CLK_PIN                       1
#define CY_DISP1_CLK_PIN_MUX                   P21_1_VIDEOSS0_TTL_DSP1_CLOCK

#define CY_DISP1_CTRL0_PORT                    GPIO_PRT20
#define CY_DISP1_CTRL0_PIN                     6
#define CY_DISP1_CTRL0_PIN_MUX                 P20_6_VIDEOSS0_TTL_DSP1_CONTROL0

#define CY_DISP1_CTRL1_PORT                    GPIO_PRT20
#define CY_DISP1_CTRL1_PIN                     7
#define CY_DISP1_CTRL1_PIN_MUX                 P20_7_VIDEOSS0_TTL_DSP1_CONTROL1

#define CY_DISP1_CTRL2_PORT                    GPIO_PRT21
#define CY_DISP1_CTRL2_PIN                     0
#define CY_DISP1_CTRL2_PIN_MUX                 P21_0_VIDEOSS0_TTL_DSP1_CONTROL2

#define CY_DISP1_DATA_A0_0_PORT                GPIO_PRT16
#define CY_DISP1_DATA_A0_0_PIN                 7
#define CY_DISP1_DATA_A0_0_PIN_MUX             P16_7_VIDEOSS0_TTL_DSP1_DATA_A00

#define CY_DISP1_DATA_A0_1_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A0_1_PIN                 0
#define CY_DISP1_DATA_A0_1_PIN_MUX             P18_0_VIDEOSS0_TTL_DSP1_DATA_A01

#define CY_DISP1_DATA_A0_2_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A0_2_PIN                 2
#define CY_DISP1_DATA_A0_2_PIN_MUX             P18_2_VIDEOSS0_TTL_DSP1_DATA_A02

#define CY_DISP1_DATA_A0_3_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A0_3_PIN                 4
#define CY_DISP1_DATA_A0_3_PIN_MUX             P18_4_VIDEOSS0_TTL_DSP1_DATA_A03

#define CY_DISP1_DATA_A0_4_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A0_4_PIN                 6
#define CY_DISP1_DATA_A0_4_PIN_MUX             P18_6_VIDEOSS0_TTL_DSP1_DATA_A04

#define CY_DISP1_DATA_A0_5_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A0_5_PIN                 0
#define CY_DISP1_DATA_A0_5_PIN_MUX             P19_0_VIDEOSS0_TTL_DSP1_DATA_A05

#define CY_DISP1_DATA_A0_6_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A0_6_PIN                 2
#define CY_DISP1_DATA_A0_6_PIN_MUX             P19_2_VIDEOSS0_TTL_DSP1_DATA_A06

#define CY_DISP1_DATA_A0_7_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A0_7_PIN                 4
#define CY_DISP1_DATA_A0_7_PIN_MUX             P19_4_VIDEOSS0_TTL_DSP1_DATA_A07

#define CY_DISP1_DATA_A0_8_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A0_8_PIN                 6
#define CY_DISP1_DATA_A0_8_PIN_MUX             P19_6_VIDEOSS0_TTL_DSP1_DATA_A08

#define CY_DISP1_DATA_A0_9_PORT                GPIO_PRT20
#define CY_DISP1_DATA_A0_9_PIN                 0
#define CY_DISP1_DATA_A0_9_PIN_MUX             P20_0_VIDEOSS0_TTL_DSP1_DATA_A09

#define CY_DISP1_DATA_A0_10_PORT               GPIO_PRT20
#define CY_DISP1_DATA_A0_10_PIN                2
#define CY_DISP1_DATA_A0_10_PIN_MUX            P20_2_VIDEOSS0_TTL_DSP1_DATA_A010

#define CY_DISP1_DATA_A0_11_PORT               GPIO_PRT20
#define CY_DISP1_DATA_A0_11_PIN                4
#define CY_DISP1_DATA_A0_11_PIN_MUX            P20_4_VIDEOSS0_TTL_DSP1_DATA_A011

#define CY_DISP1_DATA_A1_0_PORT                GPIO_PRT17
#define CY_DISP1_DATA_A1_0_PIN                 0
#define CY_DISP1_DATA_A1_0_PIN_MUX             P17_0_VIDEOSS0_TTL_DSP1_DATA_A10

#define CY_DISP1_DATA_A1_1_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A1_1_PIN                 1
#define CY_DISP1_DATA_A1_1_PIN_MUX             P18_1_VIDEOSS0_TTL_DSP1_DATA_A11

#define CY_DISP1_DATA_A1_2_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A1_2_PIN                 3
#define CY_DISP1_DATA_A1_2_PIN_MUX             P18_3_VIDEOSS0_TTL_DSP1_DATA_A12

#define CY_DISP1_DATA_A1_3_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A1_3_PIN                 5
#define CY_DISP1_DATA_A1_3_PIN_MUX             P18_5_VIDEOSS0_TTL_DSP1_DATA_A13

#define CY_DISP1_DATA_A1_4_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A1_4_PIN                 7
#define CY_DISP1_DATA_A1_4_PIN_MUX             P18_7_VIDEOSS0_TTL_DSP1_DATA_A14

#define CY_DISP1_DATA_A1_5_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A1_5_PIN                 1
#define CY_DISP1_DATA_A1_5_PIN_MUX             P19_1_VIDEOSS0_TTL_DSP1_DATA_A15

#define CY_DISP1_DATA_A1_6_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A1_6_PIN                 3
#define CY_DISP1_DATA_A1_6_PIN_MUX             P19_3_VIDEOSS0_TTL_DSP1_DATA_A16

#define CY_DISP1_DATA_A1_7_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A1_7_PIN                 5
#define CY_DISP1_DATA_A1_7_PIN_MUX             P19_5_VIDEOSS0_TTL_DSP1_DATA_A17

#define CY_DISP1_DATA_A1_8_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A1_8_PIN                 7
#define CY_DISP1_DATA_A1_8_PIN_MUX             P19_7_VIDEOSS0_TTL_DSP1_DATA_A18

#define CY_DISP1_DATA_A1_9_PORT                GPIO_PRT20
#define CY_DISP1_DATA_A1_9_PIN                 1
#define CY_DISP1_DATA_A1_9_PIN_MUX             P20_1_VIDEOSS0_TTL_DSP1_DATA_A19

#define CY_DISP1_DATA_A1_10_PORT               GPIO_PRT20
#define CY_DISP1_DATA_A1_10_PIN                3
#define CY_DISP1_DATA_A1_10_PIN_MUX            P20_3_VIDEOSS0_TTL_DSP1_DATA_A110

#define CY_DISP1_DATA_A1_11_PORT               GPIO_PRT20
#define CY_DISP1_DATA_A1_11_PIN                5
#define CY_DISP1_DATA_A1_11_PIN_MUX            P20_5_VIDEOSS0_TTL_DSP1_DATA_A111

/******************************************************************************/
/*                      Capture #0 Definitions                                */
/******************************************************************************/
#define CY_BSP_HDR_CAP0_TTL_AVAILABLE          // Definitions for this functionality are available

#define CY_CAP0_CLK_PORT                       GPIO_PRT15
#define CY_CAP0_CLK_PIN                        6
#define CY_CAP0_CLK_PIN_MUX                    P15_6_VIDEOSS0_TTL_CAP0_CLK

#define CY_CAP0_DATA0_PORT                     GPIO_PRT15
#define CY_CAP0_DATA0_PIN                      7
#define CY_CAP0_DATA0_PIN_MUX                  P15_7_VIDEOSS0_TTL_CAP0_DATA0

#define CY_CAP0_DATA1_PORT                     GPIO_PRT16
#define CY_CAP0_DATA1_PIN                      0
#define CY_CAP0_DATA1_PIN_MUX                  P16_0_VIDEOSS0_TTL_CAP0_DATA1

#define CY_CAP0_DATA2_PORT                     GPIO_PRT16
#define CY_CAP0_DATA2_PIN                      1
#define CY_CAP0_DATA2_PIN_MUX                  P16_1_VIDEOSS0_TTL_CAP0_DATA2

#define CY_CAP0_DATA3_PORT                     GPIO_PRT16
#define CY_CAP0_DATA3_PIN                      2
#define CY_CAP0_DATA3_PIN_MUX                  P16_2_VIDEOSS0_TTL_CAP0_DATA3

#define CY_CAP0_DATA4_PORT                     GPIO_PRT16
#define CY_CAP0_DATA4_PIN                      3
#define CY_CAP0_DATA4_PIN_MUX                  P16_3_VIDEOSS0_TTL_CAP0_DATA4

#define CY_CAP0_DATA5_PORT                     GPIO_PRT16
#define CY_CAP0_DATA5_PIN                      4
#define CY_CAP0_DATA5_PIN_MUX                  P16_4_VIDEOSS0_TTL_CAP0_DATA5

#define CY_CAP0_DATA6_PORT                     GPIO_PRT16
#define CY_CAP0_DATA6_PIN                      5
#define CY_CAP0_DATA6_PIN_MUX                  P16_5_VIDEOSS0_TTL_CAP0_DATA6

#define CY_CAP0_DATA7_PORT                     GPIO_PRT16
#define CY_CAP0_DATA7_PIN                      6
#define CY_CAP0_DATA7_PIN_MUX                  P16_6_VIDEOSS0_TTL_CAP0_DATA7

#define CY_CAP0_DATA8_PORT                     GPIO_PRT9
#define CY_CAP0_DATA8_PIN                      0
#define CY_CAP0_DATA8_PIN_MUX                  P9_0_VIDEOSS0_TTL_CAP0_DATA8

#define CY_CAP0_DATA9_PORT                     GPIO_PRT9
#define CY_CAP0_DATA9_PIN                      1
#define CY_CAP0_DATA9_PIN_MUX                  P9_1_VIDEOSS0_TTL_CAP0_DATA9

#define CY_CAP0_DATA10_PORT                    GPIO_PRT9
#define CY_CAP0_DATA10_PIN                     2
#define CY_CAP0_DATA10_PIN_MUX                 P9_2_VIDEOSS0_TTL_CAP0_DATA10

#define CY_CAP0_DATA11_PORT                    GPIO_PRT9
#define CY_CAP0_DATA11_PIN                     3
#define CY_CAP0_DATA11_PIN_MUX                 P9_3_VIDEOSS0_TTL_CAP0_DATA11

#define CY_CAP0_DATA12_PORT                    GPIO_PRT9
#define CY_CAP0_DATA12_PIN                     4
#define CY_CAP0_DATA12_PIN_MUX                 P9_4_VIDEOSS0_TTL_CAP0_DATA12

#define CY_CAP0_DATA13_PORT                    GPIO_PRT9
#define CY_CAP0_DATA13_PIN                     5
#define CY_CAP0_DATA13_PIN_MUX                 P9_5_VIDEOSS0_TTL_CAP0_DATA13

#define CY_CAP0_DATA14_PORT                    GPIO_PRT9
#define CY_CAP0_DATA14_PIN                     6
#define CY_CAP0_DATA14_PIN_MUX                 P9_6_VIDEOSS0_TTL_CAP0_DATA14

#define CY_CAP0_DATA15_PORT                    GPIO_PRT9
#define CY_CAP0_DATA15_PIN                     7
#define CY_CAP0_DATA15_PIN_MUX                 P9_7_VIDEOSS0_TTL_CAP0_DATA15

#define CY_CAP0_DATA16_PORT                    GPIO_PRT10
#define CY_CAP0_DATA16_PIN                     0
#define CY_CAP0_DATA16_PIN_MUX                 P10_0_VIDEOSS0_TTL_CAP0_DATA16

#define CY_CAP0_DATA17_PORT                    GPIO_PRT10
#define CY_CAP0_DATA17_PIN                     1
#define CY_CAP0_DATA17_PIN_MUX                 P10_1_VIDEOSS0_TTL_CAP0_DATA17

#define CY_CAP0_DATA18_PORT                    GPIO_PRT11
#define CY_CAP0_DATA18_PIN                     0
#define CY_CAP0_DATA18_PIN_MUX                 P11_0_VIDEOSS0_TTL_CAP0_DATA18

#define CY_CAP0_DATA19_PORT                    GPIO_PRT11
#define CY_CAP0_DATA19_PIN                     1
#define CY_CAP0_DATA19_PIN_MUX                 P11_1_VIDEOSS0_TTL_CAP0_DATA19

#define CY_CAP0_DATA20_PORT                    GPIO_PRT11
#define CY_CAP0_DATA20_PIN                     2
#define CY_CAP0_DATA20_PIN_MUX                 P11_2_VIDEOSS0_TTL_CAP0_DATA20

#define CY_CAP0_DATA21_PORT                    GPIO_PRT11
#define CY_CAP0_DATA21_PIN                     3
#define CY_CAP0_DATA21_PIN_MUX                 P11_3_VIDEOSS0_TTL_CAP0_DATA21

#define CY_CAP0_DATA22_PORT                    GPIO_PRT11
#define CY_CAP0_DATA22_PIN                     4
#define CY_CAP0_DATA22_PIN_MUX                 P11_4_VIDEOSS0_TTL_CAP0_DATA22

#define CY_CAP0_DATA23_PORT                    GPIO_PRT11
#define CY_CAP0_DATA23_PIN                     5
#define CY_CAP0_DATA23_PIN_MUX                 P11_5_VIDEOSS0_TTL_CAP0_DATA23

#define CY_CAP0_DATA24_PORT                    GPIO_PRT11
#define CY_CAP0_DATA24_PIN                     6
#define CY_CAP0_DATA24_PIN_MUX                 P11_6_VIDEOSS0_TTL_CAP0_DATA24

#define CY_CAP0_DATA25_PORT                    GPIO_PRT11
#define CY_CAP0_DATA25_PIN                     7
#define CY_CAP0_DATA25_PIN_MUX                 P11_7_VIDEOSS0_TTL_CAP0_DATA25

#define CY_CAP0_DATA26_PORT                    GPIO_PRT12
#define CY_CAP0_DATA26_PIN                     0
#define CY_CAP0_DATA26_PIN_MUX                 P12_0_VIDEOSS0_TTL_CAP0_DATA26

  
/******************************************************************************/
/*                      AUDIOSS Port (I2S0) and SCB                           */
/******************************************************************************/
  
#define CY_AUDIOSS_I2S_TYPE                     I2S0_I2S_STRUCT0
  
#define CY_AUDIOSS_I2S_TX_MCLK_PORT             GPIO_PRT20
#define CY_AUDIOSS_I2S_TX_MCLK_PIN              2
#define CY_AUDIOSS_I2S_TX_MCLK_PIN_MUX          P20_2_I2S0_I2S_TX_MCK0
  
#define CY_AUDIOSS_I2S_TX_SCK_PORT              GPIO_PRT20
#define CY_AUDIOSS_I2S_TX_SCK_PIN               3
#define CY_AUDIOSS_I2S_TX_SCK_PIN_MUX           P20_3_I2S0_I2S_TX_SCK0
  
#define CY_AUDIOSS_I2S_TX_WS_PORT               GPIO_PRT20
#define CY_AUDIOSS_I2S_TX_WS_PIN                4
#define CY_AUDIOSS_I2S_TX_WS_PIN_MUX            P20_4_I2S0_I2S_TX_WS0
  
#define CY_AUDIOSS_I2S_TX_SDO_PORT              GPIO_PRT20
#define CY_AUDIOSS_I2S_TX_SDO_PIN               5
#define CY_AUDIOSS_I2S_TX_SDO_PIN_MUX           P20_5_I2S0_I2S_TX_SD0
  
#define CY_AUDIOSS_I2S_RX_MCLK_PORT             GPIO_PRT20
#define CY_AUDIOSS_I2S_RX_MCLK_PIN              6
#define CY_AUDIOSS_I2S_RX_MCLK_PIN_MUX          P20_6_I2S0_I2S_RX_MCK0
    
#define CY_AUDIOSS_I2S_RX_SCK_PORT              GPIO_PRT20
#define CY_AUDIOSS_I2S_RX_SCK_PIN               7
#define CY_AUDIOSS_I2S_RX_SCK_PIN_MUX           P20_7_I2S0_I2S_RX_SCK0
  
#define CY_AUDIOSS_I2S_RX_WS_PORT               GPIO_PRT21
#define CY_AUDIOSS_I2S_RX_WS_PIN                0
#define CY_AUDIOSS_I2S_RX_WS_PIN_MUX            P21_0_I2S0_I2S_RX_WS0
  
#define CY_AUDIOSS_I2S_RX_SDI_PORT              GPIO_PRT21
#define CY_AUDIOSS_I2S_RX_SDI_PIN               1
#define CY_AUDIOSS_I2S_RX_SDI_PIN_MUX           P21_1_I2S0_I2S_RX_SD0
  
#define CY_AUDIOSS_I2S_TX_IRQN                  i2s_0_interrupts_tx_0_IRQn
#define CY_AUDIOSS_I2S_RX_IRQN                  i2s_0_interrupts_rx_0_IRQn

/* AUDIOSS-SPI port for Codec Communication */
#define CY_AUDIOSS_SPI_TYPE                     SCB0
  
#define CY_AUDIOSS_SPI_MISO_PORT                GPIO_PRT11
#define CY_AUDIOSS_SPI_MISO_PIN                 4
#define CY_AUDIOSS_SPI_MISO_PIN_MUX             P11_4_SCB0_SPI_MISO
  
#define CY_AUDIOSS_SPI_MOSI_PORT                GPIO_PRT11
#define CY_AUDIOSS_SPI_MOSI_PIN                 3
#define CY_AUDIOSS_SPI_MOSI_PIN_MUX             P11_3_SCB0_SPI_MOSI
  
#define CY_AUDIOSS_SPI_CLK_PORT                 GPIO_PRT11
#define CY_AUDIOSS_SPI_CLK_PIN                  2
#define CY_AUDIOSS_SPI_CLK_PIN_MUX              P11_2_SCB0_SPI_CLK
  
#define CY_AUDIOSS_SPI_SS0_PORT                 GPIO_PRT11
#define CY_AUDIOSS_SPI_SS0_PIN                  5
#define CY_AUDIOSS_SPI_SS0_PIN_MUX              P11_5_SCB0_SPI_SELECT0
  
#define CY_AUDIOSS_SPI_PCLK                     PCLK_SCB0_CLOCK
#define CY_AUDIOSS_SPI_IRQN                     scb_0_interrupt_IRQn

  
/******************************************************************************/
/*                      AUDIOSS PCM-PWM                                       */
/******************************************************************************/

// Sound Generator driver circuit is not present on board, so for testing SG fly
// wire can be connected to the external driver circuit.
// TP355 : SG0_1 Amplitude, TP389 : SG0_1 Tone

#define CY_AUDIOSS_PWM_TYPE                     PWM0_TX0
  
#define CY_AUDIOSS_PWM0_L1P1_PORT               GPIO_PRT7
#define CY_AUDIOSS_PWM0_L1P1_PIN                1
#define CY_AUDIOSS_PWM0_L1P1_PIN_MUX            P7_1_PWM0_PWM_LINE1_P0
  
#define CY_AUDIOSS_PWM0_L1N1_PORT               GPIO_PRT7
#define CY_AUDIOSS_PWM0_L1N1_PIN                2
#define CY_AUDIOSS_PWM0_L1N1_PIN_MUX            P7_2_PWM0_PWM_LINE1_N0
    
#define CY_AUDIOSS_PWM0_L2P1_PORT               GPIO_PRT7
#define CY_AUDIOSS_PWM0_L2P1_PIN                3
#define CY_AUDIOSS_PWM0_L2P1_PIN_MUX            P7_3_PWM0_PWM_LINE2_P0
    
#define CY_AUDIOSS_PWM0_L2N1_PORT               GPIO_PRT7
#define CY_AUDIOSS_PWM0_L2N1_PIN                4
#define CY_AUDIOSS_PWM0_L2N1_PIN_MUX            P7_4_PWM0_PWM_LINE2_N0

#define CY_AUDIOSS_PWM0_IRQN                    pwm_0_interrupts_0_IRQn

  
/******************************************************************************/
/*                      AUDIO-TDM Definitions                                 */
/******************************************************************************/

#define CY_GIG_ETH_TYPE                         ETH0
#define CY_GIG_ETH_INSTANCE_NUM                	(0)
                                          
#define CY_GIG_ETH_TX_CLK_PORT                  GPIO_PRT13
#define CY_GIG_ETH_TX_CLK_PIN                   3
#define CY_GIG_ETH_TX_CLK_PIN_MUX               P13_3_ETH0_TX_CLK
                                          
#define CY_GIG_ETH_TX_CTL_PORT                  GPIO_PRT15
#define CY_GIG_ETH_TX_CTL_PIN                   0
#define CY_GIG_ETH_TX_CTL_PIN_MUX               P15_0_ETH0_TX_CTL
                                          
#define CY_GIG_ETH_TD0_PORT                     GPIO_PRT0
#define CY_GIG_ETH_TD0_PIN                      0
#define CY_GIG_ETH_TD0_PIN_MUX                  P0_0_ETH0_TXD0
                                          
#define CY_GIG_ETH_TD1_PORT                     GPIO_PRT0
#define CY_GIG_ETH_TD1_PIN                      1
#define CY_GIG_ETH_TD1_PIN_MUX                  P0_1_ETH0_TXD1
                                          
#define CY_GIG_ETH_TD2_PORT                     GPIO_PRT0
#define CY_GIG_ETH_TD2_PIN                      2
#define CY_GIG_ETH_TD2_PIN_MUX                  P0_2_ETH0_TXD2
                                          
#define CY_GIG_ETH_TD3_PORT                     GPIO_PRT0
#define CY_GIG_ETH_TD3_PIN                      3
#define CY_GIG_ETH_TD3_PIN_MUX                  P0_3_ETH0_TXD3
                                          
#define CY_GIG_ETH_TXER_PORT                    GPIO_PRT23
#define CY_GIG_ETH_TXER_PIN                     6
#define CY_GIG_ETH_TXER_PIN_MUX                 P23_6_ETH0_TX_ER
                                          
#define CY_GIG_ETH_RX_CLK_PORT                  GPIO_PRT5
#define CY_GIG_ETH_RX_CLK_PIN                   0
#define CY_GIG_ETH_RX_CLK_PIN_MUX               P5_0_ETH0_RX_CLK
                                          
#define CY_GIG_ETH_RX_CTL_PORT                  GPIO_PRT3
#define CY_GIG_ETH_RX_CTL_PIN                   0
#define CY_GIG_ETH_RX_CTL_PIN_MUX               P3_0_ETH0_RX_CTL
                                          
#define CY_GIG_ETH_RD0_PORT                     GPIO_PRT33
#define CY_GIG_ETH_RD0_PIN                      7
#define CY_GIG_ETH_RD0_PIN_MUX                  P33_7_ETH0_RXD0
                                          
#define CY_GIG_ETH_RD1_PORT                     GPIO_PRT2
#define CY_GIG_ETH_RD1_PIN                      1
#define CY_GIG_ETH_RD1_PIN_MUX                  P2_1_ETH0_RXD1
                                          
#define CY_GIG_ETH_RD2_PORT                     GPIO_PRT2
#define CY_GIG_ETH_RD2_PIN                      2
#define CY_GIG_ETH_RD2_PIN_MUX                  P2_2_ETH0_RXD2
                                          
#define CY_GIG_ETH_RD3_PORT                     GPIO_PRT2
#define CY_GIG_ETH_RD3_PIN                      3
#define CY_GIG_ETH_RD3_PIN_MUX                  P2_3_ETH0_RXD3
                                          
#define CY_GIG_ETH_RX_ER_PORT                   GPIO_PRT3
#define CY_GIG_ETH_RX_ER_PIN                    1
#define CY_GIG_ETH_RX_ER_PIN_MUX                P3_1_ETH0_RX_ER
                                          
#define CY_GIG_ETH_MDC_PORT                     GPIO_PRT5
#define CY_GIG_ETH_MDC_PIN                      2
#define CY_GIG_ETH_MDC_PIN_MUX                  P5_2_ETH0_MDC
                                          
#define CY_GIG_ETH_MDIO_PORT                    GPIO_PRT5
#define CY_GIG_ETH_MDIO_PIN                     1
#define CY_GIG_ETH_MDIO_PIN_MUX                 P5_1_ETH0_MDIO
                                          
#define CY_GIG_ETH_REF_CLK_PORT                 GPIO_PRT33
#define CY_GIG_ETH_REF_CLK_PIN                  0
#define CY_GIG_ETH_REF_CLK_PIN_MUX              P33_0_ETH0_REF_CLK
  
/* Setup IRQ source for 0, 1 and 2 Priority Queue */
#define CY_GIG_ETH_IRQN0                        eth_0_interrupt_eth_0_IRQn
#define CY_GIG_ETH_IRQN1                        eth_0_interrupt_eth_1_IRQn
#define CY_GIG_ETH_IRQN2                        eth_0_interrupt_eth_2_IRQn

  
/******************************************************************************/
/*                      AUDIO-TDM Definitions                                 */
/******************************************************************************/

// By default on board Codec doesn't support TDM, so for testing TDM fly wire
// can be connected to the external Codec.

#define CY_AUDIOSS_TDM_TYPE                     TDM0_TDM_STRUCT0
  
#define CY_AUDIOSS_TDM0_TX_MCK_PORT             GPIO_PRT15
#define CY_AUDIOSS_TDM0_TX_MCK_PIN              6
#define CY_AUDIOSS_TDM0_TX_MCK_PIN_MUX          P15_6_TDM0_TDM_TX_MCK0
  
#define CY_AUDIOSS_TDM0_TX_SCK_PORT             GPIO_PRT15
#define CY_AUDIOSS_TDM0_TX_SCK_PIN              7
#define CY_AUDIOSS_TDM0_TX_SCK_PIN_MUX          P15_7_TDM0_TDM_TX_SCK0
  
#define CY_AUDIOSS_TDM0_TX_FSYNC_PORT           GPIO_PRT16
#define CY_AUDIOSS_TDM0_TX_FSYNC_PIN            0
#define CY_AUDIOSS_TDM0_TX_FSYNC_PIN_MUX        P16_0_TDM0_TDM_TX_FSYNC0
  
#define CY_AUDIOSS_TDM0_TX_SD_PORT              GPIO_PRT16
#define CY_AUDIOSS_TDM0_TX_SD_PIN               1
#define CY_AUDIOSS_TDM0_TX_SD_PIN_MUX           P16_1_TDM0_TDM_TX_SD0
  
#define CY_AUDIOSS_TDM0_RX_MCK_PORT             GPIO_PRT9
#define CY_AUDIOSS_TDM0_RX_MCK_PIN              4
#define CY_AUDIOSS_TDM0_RX_MCK_PIN_MUX          P9_4_TDM0_TDM_RX_MCK0
  
#define CY_AUDIOSS_TDM0_RX_SCK_PORT             GPIO_PRT9
#define CY_AUDIOSS_TDM0_RX_SCK_PIN              5
#define CY_AUDIOSS_TDM0_RX_SCK_PIN_MUX          P9_5_TDM0_TDM_RX_SCK0
  
#define CY_AUDIOSS_TDM0_RX_FSYNC_PORT           GPIO_PRT9
#define CY_AUDIOSS_TDM0_RX_FSYNC_PIN            6
#define CY_AUDIOSS_TDM0_RX_FSYNC_PIN_MUX        P9_6_TDM0_TDM_RX_FSYNC0
  
#define CY_AUDIOSS_TDM0_RX_SD_PORT              GPIO_PRT9
#define CY_AUDIOSS_TDM0_RX_SD_PIN               7
#define CY_AUDIOSS_TDM0_RX_SD_PIN_MUX           P9_7_TDM0_TDM_RX_SD0
  
#define CY_AUDIOSS_TDM0_TX_IRQN                 tdm_0_interrupts_tx_0_IRQn
#define CY_AUDIOSS_TDM0_RX_IRQN                 tdm_0_interrupts_rx_0_IRQn 

// Based on the Codec communication interface, corresponding scb can be defined here.


/******************************************************************************/
/*                      AUDIO-SG Definitions                                  */
/******************************************************************************/

// Sound Generator driver circuit is not present on board, so for testing SG fly
// wire can be connected to the external driver circuit.
// TP355 : SG0_1 Amplitude, TP389 : SG0_1 Tone

#define CY_AUDIOSS_SG0_TYPE                     SG0_SG_STRUCT1
  
#define CY_AUDIOSS_SG0_AMPL_PORT                GPIO_PRT4
#define CY_AUDIOSS_SG0_AMPL_PIN                 2
#define CY_AUDIOSS_SG0_AMPL_PIN_MUX             P4_2_SG0_SG_AMPL1
  
#define CY_AUDIOSS_SG0_TONE_PORT                GPIO_PRT4
#define CY_AUDIOSS_SG0_TONE_PIN                 3
#define CY_AUDIOSS_SG0_TONE_PIN_MUX             P4_3_SG0_SG_TONE1
  
#define CY_AUDIOSS_SG0_IRQ_IRQN                 sg_0_interrupts_1_IRQn
  
/******************************************************************************/
/*                      MIPI CSI-2 Definitions                                */
/******************************************************************************/
// MIPI CONFIGURATION is UNTESTED on PSVP, user should not use them.
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
#define CY_MIPI_CSI_I2C_TYPE                    SCB0
  
#define CY_MIPI_CSI_I2C_SDA_PORT                GPIO_PRT0
#define CY_MIPI_CSI_I2C_SDA_PIN                 2
#define CY_MIPI_CSI_I2C_SDA_PIN_MUX             P0_2_SCB0_I2C_SDA
  
#define CY_MIPI_CSI_I2C_SCL_PORT                GPIO_PRT0
#define CY_MIPI_CSI_I2C_SCL_PIN                 3
#define CY_MIPI_CSI_I2C_SCL_PIN_MUX             P0_3_SCB0_I2C_SCL
  
#define CY_MIPI_CSI_I2C_PCLK                    PCLK_SCB0_CLOCK
#define CY_MIPI_CSI_I2C_IRQN                    scb_0_interrupt_IRQn

  
/******************************************************************************/
/******************************************************************************/

// tviic2d6m - 500-BGA Package devices
    
// #if (CY_USE_PSVP == 0) (--> Silicon), project setting CY_USE_PSVP should be changed to '0'
// select the supported or required device accordingly
  
#elif (CY_USE_PSVP == 0) && defined(CYT4DNDBHS)
    
/******************************************************************************/
/******************************************************************************/

// CPU Board Entities

/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/*                      USER LED's                                            */
/******************************************************************************/    

#define CY_USER_LED1_PORT                       GPIO_PRT10
#define CY_USER_LED1_PIN                        0
#define CY_USER_LED1_PIN_MUX                    P10_0_GPIO
    
#define CY_USER_LED2_PORT                       GPIO_PRT10
#define CY_USER_LED2_PIN                        1
#define CY_USER_LED2_PIN_MUX                    P10_1_GPIO
    
#define CY_USER_LED3_PORT                       GPIO_PRT15
#define CY_USER_LED3_PIN                        1
#define CY_USER_LED3_PIN_MUX                    P15_1_GPIO


/******************************************************************************/
/*                      USER BUTTON's                                         */
/******************************************************************************/

#define CY_USER_BUTTON_UP_PORT                  GPIO_PRT2
#define CY_USER_BUTTON_UP_PIN                   1
#define CY_USER_BUTTON_UP_PIN_MUX               P2_1_GPIO
  
#define CY_USER_BUTTON_LEFT_PORT                GPIO_PRT15
#define CY_USER_BUTTON_LEFT_PIN                 4
#define CY_USER_BUTTON_LEFT_PIN_MUX             P15_4_GPIO
    
#define CY_USER_BUTTON_WAKE_PORT                GPIO_PRT3
#define CY_USER_BUTTON_WAKE_PIN                 1
#define CY_USER_BUTTON_WAKE_PIN_MUX             P3_1_GPIO
    
#define CY_USER_BUTTON_RIGHT_PORT               GPIO_PRT2
#define CY_USER_BUTTON_RIGHT_PIN                2
#define CY_USER_BUTTON_RIGHT_PIN_MUX            P2_2_GPIO
  
#define CY_USER_BUTTON_DOWN_PORT                GPIO_PRT15
#define CY_USER_BUTTON_DOWN_PIN                 3
#define CY_USER_BUTTON_DOWN_PIN_MUX             P15_3_GPIO
    
/* Setup GPIO for BUTTONs interrupt sources */
#define CY_USER_BUTTON_UP_IRQN                  ioss_interrupts_gpio_dpslp_2_IRQn
#define CY_USER_BUTTON_LEFT_IRQN                ioss_interrupts_gpio_act_15_IRQn
#define CY_USER_BUTTON_WAKE_IRQN                ioss_interrupts_gpio_dpslp_3_IRQn
#define CY_USER_BUTTON_RIGHT_IRQN               ioss_interrupts_gpio_dpslp_2_IRQn
#define CY_USER_BUTTON_DOWN_IRQN                ioss_interrupts_gpio_act_15_IRQn


/******************************************************************************/
/*                      ADC POT                                               */
/******************************************************************************/

#define CY_ADC_POT_PORT                         GPIO_PRT7
#define CY_ADC_POT_PIN                          0
#define CY_ADC_POT_PIN_MUX                      P7_0_GPIO
  
#define CY_ADC_POT_MACRO                        PASS0_SAR0
#define CY_ADC_POT_IN_NO                        10
#define CY_ADC_POT_PCLK                         PCLK_PASS0_CLOCK_SAR0
#define CY_ADC_POT_IRQN                         pass_0_interrupts_sar_0_IRQn    // sar logical channel irq


/******************************************************************************/
/*                      SCB Mux                                               */
/******************************************************************************/
/* USB-UART Mux */
#define CY_USB_SCB_TYPE                         SCB11
  
#define CY_USB_SCB_UART_RX_PORT                 GPIO_PRT0
#define CY_USB_SCB_UART_RX_PIN                  4
#define CY_USB_SCB_UART_RX_MUX                  P0_4_SCB11_UART_RX

#define CY_USB_SCB_UART_TX_PORT                 GPIO_PRT0
#define CY_USB_SCB_UART_TX_PIN                  5
#define CY_USB_SCB_UART_TX_MUX                  P0_5_SCB11_UART_TX

#define CY_USB_SCB_UART_PCLK                    PCLK_SCB11_CLOCK
#define CY_USB_SCB_UART_IRQN                    scb_11_interrupt_IRQn


/******************************************************************************/
/*                      SMIF0 Definitions                                     */
/******************************************************************************/
#define CY_BSP_HDR_SMIF0_AVAILABLE              // Definitions for this functionality are available

#define CY_SMIF0_CLK_INV_PORT                   GPIO_PRT24
#define CY_SMIF0_CLK_INV_PIN                    0
#define CY_SMIF0_CLK_INV_PIN_MUX                P24_0_SMIF0_SPIHB_CLK
    
#define CY_SMIF0_CLK_PORT                       GPIO_PRT24
#define CY_SMIF0_CLK_PIN                        1
#define CY_SMIF0_CLK_PIN_MUX                    P24_1_SMIF0_SPIHB_CLK
  
#define CY_SMIF0_RWDS_PORT                      GPIO_PRT23
#define CY_SMIF0_RWDS_PIN                       4
#define CY_SMIF0_RWDS_PIN_MUX                   P23_4_SMIF0_SPIHB_RWDS
  
#define CY_SMIF0_SELECT0_PORT                   GPIO_PRT25
#define CY_SMIF0_SELECT0_PIN                    2
#define CY_SMIF0_SELECT0_PIN_MUX                P25_2_SMIF0_SPIHB_SELECT0
  
#define CY_SMIF0_SELECT1_PORT                   GPIO_PRT25
#define CY_SMIF0_SELECT1_PIN                    5
#define CY_SMIF0_SELECT1_PIN_MUX                P25_5_SMIF0_SPIHB_SELECT1
  
#define CY_SMIF0_DATA0_PORT                     GPIO_PRT25
#define CY_SMIF0_DATA0_PIN                      0
#define CY_SMIF0_DATA0_PIN_MUX                  P25_0_SMIF0_SPIHB_DATA0
  
#define CY_SMIF0_DATA1_PORT                     GPIO_PRT25
#define CY_SMIF0_DATA1_PIN                      3
#define CY_SMIF0_DATA1_PIN_MUX                  P25_3_SMIF0_SPIHB_DATA1
  
#define CY_SMIF0_DATA2_PORT                     GPIO_PRT23
#define CY_SMIF0_DATA2_PIN                      1
#define CY_SMIF0_DATA2_PIN_MUX                  P23_1_SMIF0_SPIHB_DATA2
  
#define CY_SMIF0_DATA3_PORT                     GPIO_PRT23
#define CY_SMIF0_DATA3_PIN                      2
#define CY_SMIF0_DATA3_PIN_MUX                  P23_2_SMIF0_SPIHB_DATA3
  
#define CY_SMIF0_DATA4_PORT                     GPIO_PRT23
#define CY_SMIF0_DATA4_PIN                      0
#define CY_SMIF0_DATA4_PIN_MUX                  P23_0_SMIF0_SPIHB_DATA4
  
#define CY_SMIF0_DATA5_PORT                     GPIO_PRT23
#define CY_SMIF0_DATA5_PIN                      3
#define CY_SMIF0_DATA5_PIN_MUX                  P23_3_SMIF0_SPIHB_DATA5
  
#define CY_SMIF0_DATA6_PORT                     GPIO_PRT25
#define CY_SMIF0_DATA6_PIN                      1
#define CY_SMIF0_DATA6_PIN_MUX                  P25_1_SMIF0_SPIHB_DATA6
  
#define CY_SMIF0_DATA7_PORT                     GPIO_PRT25
#define CY_SMIF0_DATA7_PIN                      4
#define CY_SMIF0_DATA7_PIN_MUX                  P25_4_SMIF0_SPIHB_DATA7
    
#define CY_SMIF_S25FXXXS                        (0u)
#define CY_SMIF_S25FXXXL                        (1u)
#define CY_SMIF0_QUAD_MEMORY                    CY_SMIF_S25FXXXL

// IO connections P11.1, P12.6 and P12.7 kept for Semper Flash interrupt.


/******************************************************************************/
/*                      SMIF1 Definitions                                     */
/******************************************************************************/
#define CY_BSP_HDR_SMIF1_AVAILABLE              // Definitions for this functionality are available

#define CY_SMIF1_CLK_INV_PORT                   GPIO_PRT27
#define CY_SMIF1_CLK_INV_PIN                    0
#define CY_SMIF1_CLK_INV_PIN_MUX                P27_0_SMIF1_SPIHB_CLK
    
#define CY_SMIF1_CLK_PORT                       GPIO_PRT27
#define CY_SMIF1_CLK_PIN                        1
#define CY_SMIF1_CLK_PIN_MUX                    P27_1_SMIF1_SPIHB_CLK
  
#define CY_SMIF1_RWDS_PORT                      GPIO_PRT26
#define CY_SMIF1_RWDS_PIN                       4
#define CY_SMIF1_RWDS_PIN_MUX                   P26_4_SMIF1_SPIHB_RWDS
  
#define CY_SMIF1_SELECT0_PORT                   GPIO_PRT28
#define CY_SMIF1_SELECT0_PIN                    2
#define CY_SMIF1_SELECT0_PIN_MUX                P28_2_SMIF1_SPIHB_SELECT0
  
#define CY_SMIF1_SELECT1_PORT                   GPIO_PRT28
#define CY_SMIF1_SELECT1_PIN                    5
#define CY_SMIF1_SELECT1_PIN_MUX                P28_5_SMIF1_SPIHB_SELECT1
  
#define CY_SMIF1_DATA0_PORT                     GPIO_PRT28
#define CY_SMIF1_DATA0_PIN                      0
#define CY_SMIF1_DATA0_PIN_MUX                  P28_0_SMIF1_SPIHB_DATA0
  
#define CY_SMIF1_DATA1_PORT                     GPIO_PRT28
#define CY_SMIF1_DATA1_PIN                      3
#define CY_SMIF1_DATA1_PIN_MUX                  P28_3_SMIF1_SPIHB_DATA1
  
#define CY_SMIF1_DATA2_PORT                     GPIO_PRT26
#define CY_SMIF1_DATA2_PIN                      1
#define CY_SMIF1_DATA2_PIN_MUX                  P26_1_SMIF1_SPIHB_DATA2
  
#define CY_SMIF1_DATA3_PORT                     GPIO_PRT26
#define CY_SMIF1_DATA3_PIN                      2
#define CY_SMIF1_DATA3_PIN_MUX                  P26_2_SMIF1_SPIHB_DATA3
  
#define CY_SMIF1_DATA4_PORT                     GPIO_PRT26
#define CY_SMIF1_DATA4_PIN                      0
#define CY_SMIF1_DATA4_PIN_MUX                  P26_0_SMIF1_SPIHB_DATA4
  
#define CY_SMIF1_DATA5_PORT                     GPIO_PRT26
#define CY_SMIF1_DATA5_PIN                      3
#define CY_SMIF1_DATA5_PIN_MUX                  P26_3_SMIF1_SPIHB_DATA5
  
#define CY_SMIF1_DATA6_PORT                     GPIO_PRT28
#define CY_SMIF1_DATA6_PIN                      1
#define CY_SMIF1_DATA6_PIN_MUX                  P28_1_SMIF1_SPIHB_DATA6
  
#define CY_SMIF1_DATA7_PORT                     GPIO_PRT28
#define CY_SMIF1_DATA7_PIN                      4
#define CY_SMIF1_DATA7_PIN_MUX                  P28_4_SMIF1_SPIHB_DATA7
    
#define CY_SMIF_S25FXXXS                        (0u)
#define CY_SMIF_S25FXXXL                        (1u)
#define CY_SMIF1_QUAD_MEMORY                    CY_SMIF_S25FXXXL

// IO connections P12.3 kept for Semper Flash interrupt.
  

/******************************************************************************/
/*                      AUDIOSS Port (I2S0) and SCB                           */
/******************************************************************************/

// I2S is multiplexed with Display 0, one of them can be used at a time.
  
#define CY_AUDIOSS_I2S_TYPE                     I2S0_I2S_STRUCT1
  
#define CY_AUDIOSS_I2S_TX_MCLK_PORT             GPIO_PRT4
#define CY_AUDIOSS_I2S_TX_MCLK_PIN              0
#define CY_AUDIOSS_I2S_TX_MCLK_PIN_MUX          P4_0_I2S0_I2S_TX_MCK1
  
#define CY_AUDIOSS_I2S_TX_SCK_PORT              GPIO_PRT4
#define CY_AUDIOSS_I2S_TX_SCK_PIN               1
#define CY_AUDIOSS_I2S_TX_SCK_PIN_MUX           P4_1_I2S0_I2S_TX_SCK1
  
#define CY_AUDIOSS_I2S_TX_WS_PORT               GPIO_PRT4
#define CY_AUDIOSS_I2S_TX_WS_PIN                2
#define CY_AUDIOSS_I2S_TX_WS_PIN_MUX            P4_2_I2S0_I2S_TX_WS1
  
#define CY_AUDIOSS_I2S_TX_SDO_PORT              GPIO_PRT4
#define CY_AUDIOSS_I2S_TX_SDO_PIN               3
#define CY_AUDIOSS_I2S_TX_SDO_PIN_MUX           P4_3_I2S0_I2S_TX_SD1
  
#define CY_AUDIOSS_I2S_RX_MCLK_PORT             GPIO_PRT5
#define CY_AUDIOSS_I2S_RX_MCLK_PIN              0
#define CY_AUDIOSS_I2S_RX_MCLK_PIN_MUX          P5_0_I2S0_I2S_RX_MCK1
    
#define CY_AUDIOSS_I2S_RX_SCK_PORT              GPIO_PRT5
#define CY_AUDIOSS_I2S_RX_SCK_PIN               1
#define CY_AUDIOSS_I2S_RX_SCK_PIN_MUX           P5_1_I2S0_I2S_RX_SCK1
  
#define CY_AUDIOSS_I2S_RX_WS_PORT               GPIO_PRT5
#define CY_AUDIOSS_I2S_RX_WS_PIN                2
#define CY_AUDIOSS_I2S_RX_WS_PIN_MUX            P5_2_I2S0_I2S_RX_WS1
  
#define CY_AUDIOSS_I2S_RX_SDI_PORT              GPIO_PRT5
#define CY_AUDIOSS_I2S_RX_SDI_PIN               3
#define CY_AUDIOSS_I2S_RX_SDI_PIN_MUX           P5_3_I2S0_I2S_RX_SD1
  
#define CY_AUDIOSS_I2S_TX_IRQN                  i2s_0_interrupts_tx_1_IRQn
#define CY_AUDIOSS_I2S_RX_IRQN                  i2s_0_interrupts_rx_1_IRQn
    
/* AUDIOSS-SPI port for Codec Communication */
#define CY_AUDIOSS_SPI_TYPE                     SCB6
  
#define CY_AUDIOSS_SPI_MISO_PORT                GPIO_PRT22
#define CY_AUDIOSS_SPI_MISO_PIN                 1
#define CY_AUDIOSS_SPI_MISO_PIN_MUX             P22_1_SCB6_SPI_MISO
  
#define CY_AUDIOSS_SPI_MOSI_PORT                GPIO_PRT22
#define CY_AUDIOSS_SPI_MOSI_PIN                 0
#define CY_AUDIOSS_SPI_MOSI_PIN_MUX             P22_0_SCB6_SPI_MOSI
  
#define CY_AUDIOSS_SPI_CLK_PORT                 GPIO_PRT21
#define CY_AUDIOSS_SPI_CLK_PIN                  7
#define CY_AUDIOSS_SPI_CLK_PIN_MUX              P21_7_SCB6_SPI_CLK
  
#define CY_AUDIOSS_SPI_SS0_PORT                 GPIO_PRT22
#define CY_AUDIOSS_SPI_SS0_PIN                  2
#define CY_AUDIOSS_SPI_SS0_PIN_MUX              P22_2_SCB6_SPI_SELECT0
  
#define CY_AUDIOSS_SPI_PCLK                     PCLK_SCB6_CLOCK
#define CY_AUDIOSS_SPI_IRQN                     scb_6_interrupt_IRQn  


/******************************************************************************/
/*                      AUDIOSS PCM-PWM                                       */
/******************************************************************************/

#define CY_AUDIOSS_PWM_TYPE                     PWM0_TX1
  
#define CY_AUDIOSS_PWM0_L1P1_PORT               GPIO_PRT4
#define CY_AUDIOSS_PWM0_L1P1_PIN                4
#define CY_AUDIOSS_PWM0_L1P1_PIN_MUX            P4_4_PWM0_PWM_LINE1_P1
  
#define CY_AUDIOSS_PWM0_L1N1_PORT               GPIO_PRT4
#define CY_AUDIOSS_PWM0_L1N1_PIN                5
#define CY_AUDIOSS_PWM0_L1N1_PIN_MUX            P4_5_PWM0_PWM_LINE1_N1
    
#define CY_AUDIOSS_PWM0_L2P1_PORT               GPIO_PRT4
#define CY_AUDIOSS_PWM0_L2P1_PIN                6
#define CY_AUDIOSS_PWM0_L2P1_PIN_MUX            P4_6_PWM0_PWM_LINE2_P1
    
#define CY_AUDIOSS_PWM0_L2N1_PORT               GPIO_PRT4
#define CY_AUDIOSS_PWM0_L2N1_PIN                7
#define CY_AUDIOSS_PWM0_L2N1_PIN_MUX            P4_7_PWM0_PWM_LINE2_N1
    
#define CY_AUDIOSS_PWM0_IRQN                    pwm_0_interrupts_1_IRQn
  

/******************************************************************************/
/*                      GIGA ETH Port                                         */
/******************************************************************************/

#define CY_GIG_ETH_TYPE                         ETH0
#define CY_GIG_ETH_INSTANCE_NUM                 (0)
                                          
#define CY_GIG_ETH_TX_CLK_PORT                  GPIO_PRT13
#define CY_GIG_ETH_TX_CLK_PIN                   3
#define CY_GIG_ETH_TX_CLK_PIN_MUX               P13_3_ETH0_TX_CLK
                                          
#define CY_GIG_ETH_TX_CTL_PORT                  GPIO_PRT15
#define CY_GIG_ETH_TX_CTL_PIN                   0
#define CY_GIG_ETH_TX_CTL_PIN_MUX               P15_0_ETH0_TX_CTL
                                          
#define CY_GIG_ETH_TD0_PORT                     GPIO_PRT14
#define CY_GIG_ETH_TD0_PIN                      3
#define CY_GIG_ETH_TD0_PIN_MUX                  P14_3_ETH0_TXD0
                                          
#define CY_GIG_ETH_TD1_PORT                     GPIO_PRT14
#define CY_GIG_ETH_TD1_PIN                      4
#define CY_GIG_ETH_TD1_PIN_MUX                  P14_4_ETH0_TXD1
                                          
#define CY_GIG_ETH_TD2_PORT                     GPIO_PRT14       
#define CY_GIG_ETH_TD2_PIN                      5
#define CY_GIG_ETH_TD2_PIN_MUX                  P14_5_ETH0_TXD2
                                          
#define CY_GIG_ETH_TD3_PORT                     GPIO_PRT14
#define CY_GIG_ETH_TD3_PIN                      6
#define CY_GIG_ETH_TD3_PIN_MUX                  P14_6_ETH0_TXD3
                                          
#define CY_GIG_ETH_TXER_PORT                    GPIO_PRT14
#define CY_GIG_ETH_TXER_PIN                     7
#define CY_GIG_ETH_TXER_PIN_MUX                 P14_7_ETH0_TX_ER
                                          
#define CY_GIG_ETH_RX_CLK_PORT                  GPIO_PRT13
#define CY_GIG_ETH_RX_CLK_PIN                   4
#define CY_GIG_ETH_RX_CLK_PIN_MUX               P13_4_ETH0_RX_CLK
                                          
#define CY_GIG_ETH_RX_CTL_PORT                  GPIO_PRT14
#define CY_GIG_ETH_RX_CTL_PIN                   2
#define CY_GIG_ETH_RX_CTL_PIN_MUX               P14_2_ETH0_RX_CTL
                                          
#define CY_GIG_ETH_RD0_PORT                     GPIO_PRT13
#define CY_GIG_ETH_RD0_PIN                      6
#define CY_GIG_ETH_RD0_PIN_MUX                  P13_6_ETH0_RXD0
                                          
#define CY_GIG_ETH_RD1_PORT                     GPIO_PRT13
#define CY_GIG_ETH_RD1_PIN                      7
#define CY_GIG_ETH_RD1_PIN_MUX                  P13_7_ETH0_RXD1
                                          
#define CY_GIG_ETH_RD2_PORT                     GPIO_PRT14
#define CY_GIG_ETH_RD2_PIN                      0
#define CY_GIG_ETH_RD2_PIN_MUX                  P14_0_ETH0_RXD2
                                          
#define CY_GIG_ETH_RD3_PORT                     GPIO_PRT14
#define CY_GIG_ETH_RD3_PIN                      1
#define CY_GIG_ETH_RD3_PIN_MUX                  P14_1_ETH0_RXD3
                                          
#define CY_GIG_ETH_RX_ER_PORT                   GPIO_PRT13        
#define CY_GIG_ETH_RX_ER_PIN                    5
#define CY_GIG_ETH_RX_ER_PIN_MUX                P13_5_ETH0_RX_ER
                                          
#define CY_GIG_ETH_MDC_PORT                     GPIO_PRT13
#define CY_GIG_ETH_MDC_PIN                      0
#define CY_GIG_ETH_MDC_PIN_MUX                  P13_0_ETH0_MDC
                                          
#define CY_GIG_ETH_MDIO_PORT                    GPIO_PRT13
#define CY_GIG_ETH_MDIO_PIN                     1
#define CY_GIG_ETH_MDIO_PIN_MUX                 P13_1_ETH0_MDIO
                                          
#define CY_GIG_ETH_REF_CLK_PORT                 GPIO_PRT13
#define CY_GIG_ETH_REF_CLK_PIN                  2
#define CY_GIG_ETH_REF_CLK_PIN_MUX              P13_2_ETH0_REF_CLK
  
/* Setup IRQ source for 0, 1 and 2 Priority Queue */
#define CY_GIG_ETH_IRQN0                        eth_0_interrupt_eth_0_IRQn
#define CY_GIG_ETH_IRQN1                        eth_0_interrupt_eth_1_IRQn
#define CY_GIG_ETH_IRQN2                        eth_0_interrupt_eth_2_IRQn
  

/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/

/* CAN1 Channel 0 */
#define CY_CANFD0_TYPE                          CY_CANFD1_0_TYPE
#define CY_CANFD0_RX_PORT                       GPIO_PRT21
#define CY_CANFD0_RX_PIN                        3
#define CY_CANFD0_RX_MUX                        P21_3_CANFD1_TTCAN_RX0
#define CY_CANFD0_TX_PORT                       GPIO_PRT21
#define CY_CANFD0_TX_PIN                        2
#define CY_CANFD0_TX_MUX                        P21_2_CANFD1_TTCAN_TX0
#define CY_CANFD0_PCLK                          PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD0_IRQN                          canfd_1_interrupts0_0_IRQn
  
/* CAN1 Channel 1 */    
#define CY_CANFD1_TYPE                          CY_CANFD1_1_TYPE
#define CY_CANFD1_RX_PORT                       GPIO_PRT21
#define CY_CANFD1_RX_PIN                        5
#define CY_CANFD1_RX_MUX                        P21_5_CANFD1_TTCAN_RX1
#define CY_CANFD1_TX_PORT                       GPIO_PRT21
#define CY_CANFD1_TX_PIN                        4
#define CY_CANFD1_TX_MUX                        P21_4_CANFD1_TTCAN_TX1
#define CY_CANFD1_PCLK                          PCLK_CANFD1_CLOCK_CAN1
#define CY_CANFD1_IRQN                          canfd_1_interrupts0_1_IRQn
  

/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

// LIN0_CH0 is multiplexed with SWD interface, add jumper on R62 and R63.
  
/* LIN0 Channel 0 */
#define CY_LINCH0_TYPE                          LIN0_CH0
#define CY_LINCH0_RX_PORT                       GPIO_PRT2
#define CY_LINCH0_RX_PIN                        4
#define CY_LINCH0_RX_PIN_MUX                    P2_4_LIN0_LIN_RX0
#define CY_LINCH0_TX_PORT                       GPIO_PRT3
#define CY_LINCH0_TX_PIN                        0
#define CY_LINCH0_TX_PIN_MUX                    P3_0_LIN0_LIN_TX0
#define CY_LINCH0_PCLK                          PCLK_LIN0_CLOCK_CH_EN0
#define CY_LINCH0_IRQN                          lin_0_interrupts_0_IRQn
  
/* LIN0 Channel 1 */    
#define CY_LINCH1_TYPE                          LIN0_CH1
#define CY_LINCH1_RX_PORT                       GPIO_PRT0
#define CY_LINCH1_RX_PIN                        1
#define CY_LINCH1_RX_PIN_MUX                    P0_1_LIN0_LIN_RX1
#define CY_LINCH1_TX_PORT                       GPIO_PRT0
#define CY_LINCH1_TX_PIN                        0
#define CY_LINCH1_TX_PIN_MUX                    P0_0_LIN0_LIN_TX1
#define CY_LINCH1_PCLK                          PCLK_LIN0_CLOCK_CH_EN1
#define CY_LINCH1_IRQN                          lin_0_interrupts_1_IRQn

  
/******************************************************************************/
/*                      SMARTIO Block                                         */
/******************************************************************************/

#define CY_SMARTIO_MACRO                        SMARTIO
#define CY_SMARTIO_PORT                         SMARTIO_PRT7
#define CY_SMARTIO_CLK                          PCLK_SMARTIO7_CLOCK
  
#define CY_SMARTIO_OUT_PORT                     GPIO_PRT7
#define CY_SMARTIO_OUT_PIN                      2
#define CY_SMARTIO_OUT_PORT_MUX                 P7_2_GPIO
  
#define CY_SMARTIO_IN_PORT                      GPIO_PRT7
#define CY_SMARTIO_IN_PIN                       1
#define CY_SMARTIO_IN_PORT_MUX                  P7_1_GPIO
#define CY_SMARTIO_IN_PORT_MUX_PWM              P7_1_TCPWM0_LINE21

#define CY_SMARTIO_IN2_PORT                     GPIO_PRT7
#define CY_SMARTIO_IN2_PIN                      3
#define CY_SMARTIO_IN2_PORT_MUX                 P7_3_GPIO
#define CY_SMARTIO_IN2_PORT_MUX_PWM             P7_3_TCPWM0_LINE23

/* PWM PR Mode Configuration def */
#define CY_SMARTIO_TCPWM_GRP0_CNT               TCPWM0_GRP0_CNT21
#define CY_SMARTIO_TCPWM_PCLK                   PCLK_TCPWM0_CLOCKS21

#define CY_SMARTIO_TCPWM_GRP0_CNT2              TCPWM0_GRP0_CNT23
#define CY_SMARTIO_TCPWM_PCLK2                  PCLK_TCPWM0_CLOCKS23


/******************************************************************************/
/*                      AUDIO DAC Definitions                                 */
/******************************************************************************/

// No need to configure AUDIO-DAC io mux, it is available on P3 on board.

/* AUDIO-DAC Clock */
#define CY_AUDIO_DAC_MCK_PORT                   GPIO_PRT1
#define CY_AUDIO_DAC_MCK_PIN                    2
#define CY_AUDIO_DAC_MCK_PIN_MUX                P1_2_DAC0_DAC_MCK
  
  
/******************************************************************************/
/*                      Display Backlight Controls                            */
/******************************************************************************/

/* Display 0 Backlight */
#define CY_BL_DISP0_PWM_PORT                    GPIO_PRT15
#define CY_BL_DISP0_PWM_PIN                     2
#define CY_BL_DISP0_PWM_PIN_MUX                 P15_2_GPIO  // use as GPIO for now (0% or 100% PWM)
  
/* Display 1 Backlight */       
#define CY_BL_DISP1_PWM_PORT                    GPIO_PRT15
#define CY_BL_DISP1_PWM_PIN                     2
#define CY_BL_DISP1_PWM_PIN_MUX                 P15_7_GPIO  // use as GPIO for now (0% or 100% PWM)


/******************************************************************************/
/*                      Display #0 Definitions                                */
/******************************************************************************/
 
// Display 0 is not timing matched, connections needs to be taken from io header.
// Display 0 is multiplexed with I2S and ADC-POT, one of them can be used at a time.

#define CY_BSP_HDR_DISP0_TTL_AVAILABLE          // Definitions for this functionality are available

#define CY_DISP0_CLK_PORT                       GPIO_PRT8
#define CY_DISP0_CLK_PIN                        3
#define CY_DISP0_CLK_PIN_MUX                    P8_3_VIDEOSS0_TTL_DSP0_CLOCK     // PCLK
                                          
#define CY_DISP0_CTRL0_PORT                     GPIO_PRT8
#define CY_DISP0_CTRL0_PIN                      0
#define CY_DISP0_CTRL0_PIN_MUX                  P8_0_VIDEOSS0_TTL_DSP0_CONTROL0  // LVALID
                                          
#define CY_DISP0_CTRL1_PORT                     GPIO_PRT8
#define CY_DISP0_CTRL1_PIN                      1
#define CY_DISP0_CTRL1_PIN_MUX                  P8_1_VIDEOSS0_TTL_DSP0_CONTROL1  // VSYNC
                                          
#define CY_DISP0_CTRL2_PORT                     GPIO_PRT8
#define CY_DISP0_CTRL2_PIN                      2
#define CY_DISP0_CTRL2_PIN_MUX                  P8_2_VIDEOSS0_TTL_DSP0_CONTROL2  // DE
                                          
#define CY_DISP0_DATA_A0_0_PORT                 GPIO_PRT12
#define CY_DISP0_DATA_A0_0_PIN                  2
#define CY_DISP0_DATA_A0_0_PIN_MUX              P12_2_VIDEOSS0_TTL_DSP0_DATA_A00 // RED0
                                          
#define CY_DISP0_DATA_A0_1_PORT                 GPIO_PRT12
#define CY_DISP0_DATA_A0_1_PIN                  4
#define CY_DISP0_DATA_A0_1_PIN_MUX              P12_4_VIDEOSS0_TTL_DSP0_DATA_A01 // RED2
                                          
#define CY_DISP0_DATA_A0_2_PORT                 GPIO_PRT12
#define CY_DISP0_DATA_A0_2_PIN                  6
#define CY_DISP0_DATA_A0_2_PIN_MUX              P12_6_VIDEOSS0_TTL_DSP0_DATA_A02 // RED4
                                          
#define CY_DISP0_DATA_A0_3_PORT                 GPIO_PRT5
#define CY_DISP0_DATA_A0_3_PIN                  0
#define CY_DISP0_DATA_A0_3_PIN_MUX              P5_0_VIDEOSS0_TTL_DSP0_DATA_A03  // RED6
                                          
#define CY_DISP0_DATA_A0_4_PORT                 GPIO_PRT5
#define CY_DISP0_DATA_A0_4_PIN                  2
#define CY_DISP0_DATA_A0_4_PIN_MUX              P5_2_VIDEOSS0_TTL_DSP0_DATA_A04  // GREEN0
                                          
#define CY_DISP0_DATA_A0_5_PORT                 GPIO_PRT5
#define CY_DISP0_DATA_A0_5_PIN                  4
#define CY_DISP0_DATA_A0_5_PIN_MUX              P5_4_VIDEOSS0_TTL_DSP0_DATA_A05  // GREEN2
                                          
#define CY_DISP0_DATA_A0_6_PORT                 GPIO_PRT5
#define CY_DISP0_DATA_A0_6_PIN                  6
#define CY_DISP0_DATA_A0_6_PIN_MUX              P5_6_VIDEOSS0_TTL_DSP0_DATA_A06  // GREEN4
                                          
#define CY_DISP0_DATA_A0_7_PORT                 GPIO_PRT6
#define CY_DISP0_DATA_A0_7_PIN                  0
#define CY_DISP0_DATA_A0_7_PIN_MUX              P6_0_VIDEOSS0_TTL_DSP0_DATA_A07  // GREEN6
                                          
#define CY_DISP0_DATA_A0_8_PORT                 GPIO_PRT6
#define CY_DISP0_DATA_A0_8_PIN                  2
#define CY_DISP0_DATA_A0_8_PIN_MUX              P6_2_VIDEOSS0_TTL_DSP0_DATA_A08  // BLUE0
                                          
#define CY_DISP0_DATA_A0_9_PORT                 GPIO_PRT6
#define CY_DISP0_DATA_A0_9_PIN                  4
#define CY_DISP0_DATA_A0_9_PIN_MUX              P6_4_VIDEOSS0_TTL_DSP0_DATA_A09  // BLUE2
                                          
#define CY_DISP0_DATA_A0_10_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A0_10_PIN                 6
#define CY_DISP0_DATA_A0_10_PIN_MUX             P6_6_VIDEOSS0_TTL_DSP0_DATA_A010 // BLUE4
                                          
#define CY_DISP0_DATA_A0_11_PORT                GPIO_PRT7
#define CY_DISP0_DATA_A0_11_PIN                 0
#define CY_DISP0_DATA_A0_11_PIN_MUX             P7_0_VIDEOSS0_TTL_DSP0_DATA_A011 // BLUE6
                                          
#define CY_DISP0_DATA_A1_0_PORT                 GPIO_PRT12
#define CY_DISP0_DATA_A1_0_PIN                  3
#define CY_DISP0_DATA_A1_0_PIN_MUX              P12_3_VIDEOSS0_TTL_DSP0_DATA_A10 // RED1
                                          
#define CY_DISP0_DATA_A1_1_PORT                 GPIO_PRT12
#define CY_DISP0_DATA_A1_1_PIN                  5
#define CY_DISP0_DATA_A1_1_PIN_MUX              P12_5_VIDEOSS0_TTL_DSP0_DATA_A11 // RED3
                                          
#define CY_DISP0_DATA_A1_2_PORT                 GPIO_PRT12
#define CY_DISP0_DATA_A1_2_PIN                  7
#define CY_DISP0_DATA_A1_2_PIN_MUX              P12_7_VIDEOSS0_TTL_DSP0_DATA_A12 // RED5
                                          
#define CY_DISP0_DATA_A1_3_PORT                 GPIO_PRT5
#define CY_DISP0_DATA_A1_3_PIN                  1
#define CY_DISP0_DATA_A1_3_PIN_MUX              P5_1_VIDEOSS0_TTL_DSP0_DATA_A13  // RED7
                                          
#define CY_DISP0_DATA_A1_4_PORT                 GPIO_PRT5
#define CY_DISP0_DATA_A1_4_PIN                  3
#define CY_DISP0_DATA_A1_4_PIN_MUX              P5_3_VIDEOSS0_TTL_DSP0_DATA_A14  // GREEN1
                                          
#define CY_DISP0_DATA_A1_5_PORT                 GPIO_PRT5
#define CY_DISP0_DATA_A1_5_PIN                  5
#define CY_DISP0_DATA_A1_5_PIN_MUX              P5_5_VIDEOSS0_TTL_DSP0_DATA_A15  // GREEN3
                                          
#define CY_DISP0_DATA_A1_6_PORT                 GPIO_PRT5
#define CY_DISP0_DATA_A1_6_PIN                  7
#define CY_DISP0_DATA_A1_6_PIN_MUX              P5_7_VIDEOSS0_TTL_DSP0_DATA_A16  // GREEN5
                                          
#define CY_DISP0_DATA_A1_7_PORT                 GPIO_PRT6
#define CY_DISP0_DATA_A1_7_PIN                  1
#define CY_DISP0_DATA_A1_7_PIN_MUX              P6_1_VIDEOSS0_TTL_DSP0_DATA_A17  // GREEN7
                                          
#define CY_DISP0_DATA_A1_8_PORT                 GPIO_PRT6
#define CY_DISP0_DATA_A1_8_PIN                  3
#define CY_DISP0_DATA_A1_8_PIN_MUX              P6_3_VIDEOSS0_TTL_DSP0_DATA_A18  // BLUE1
                                          
#define CY_DISP0_DATA_A1_9_PORT                 GPIO_PRT6
#define CY_DISP0_DATA_A1_9_PIN                  5
#define CY_DISP0_DATA_A1_9_PIN_MUX              P6_5_VIDEOSS0_TTL_DSP0_DATA_A19  // BLUE3
                                          
#define CY_DISP0_DATA_A1_10_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A1_10_PIN                 7
#define CY_DISP0_DATA_A1_10_PIN_MUX             P6_7_VIDEOSS0_TTL_DSP0_DATA_A110 // BLUE5
                                          
#define CY_DISP0_DATA_A1_11_PORT                GPIO_PRT0
#define CY_DISP0_DATA_A1_11_PIN                 7
#define CY_DISP0_DATA_A1_11_PIN_MUX             P0_7_VIDEOSS0_TTL_DSP0_DATA_A111 // BLUE7

  
/******************************************************************************/
/*                      Display #1 Definitions                                */
/******************************************************************************/
  
// Display 1 is multiplexed with Capture 0, one of them can be used at a time.

#define CY_BSP_HDR_DISP1_TTL_AVAILABLE          // Definitions for this functionality are available

#define CY_DISP1_CLK_PORT                       GPIO_PRT21
#define CY_DISP1_CLK_PIN                        1
#define CY_DISP1_CLK_PIN_MUX                    P21_1_VIDEOSS0_TTL_DSP1_CLOCK    // PCLK
    
#define CY_DISP1_CTRL0_PORT                     GPIO_PRT20
#define CY_DISP1_CTRL0_PIN                      6
#define CY_DISP1_CTRL0_PIN_MUX                  P20_6_VIDEOSS0_TTL_DSP1_CONTROL0 // LVALID
    
#define CY_DISP1_CTRL1_PORT                     GPIO_PRT20
#define CY_DISP1_CTRL1_PIN                      7
#define CY_DISP1_CTRL1_PIN_MUX                  P20_7_VIDEOSS0_TTL_DSP1_CONTROL1 // VSYNC
    
#define CY_DISP1_CTRL2_PORT                     GPIO_PRT21
#define CY_DISP1_CTRL2_PIN                      0
#define CY_DISP1_CTRL2_PIN_MUX                  P21_0_VIDEOSS0_TTL_DSP1_CONTROL2 // DE
    
#define CY_DISP1_DATA_A0_0_PORT                 GPIO_PRT16
#define CY_DISP1_DATA_A0_0_PIN                  7
#define CY_DISP1_DATA_A0_0_PIN_MUX              P16_7_VIDEOSS0_TTL_DSP1_DATA_A00 // RED0
    
#define CY_DISP1_DATA_A0_1_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A0_1_PIN                  0
#define CY_DISP1_DATA_A0_1_PIN_MUX              P18_0_VIDEOSS0_TTL_DSP1_DATA_A01 // RED2
    
#define CY_DISP1_DATA_A0_2_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A0_2_PIN                  2
#define CY_DISP1_DATA_A0_2_PIN_MUX              P18_2_VIDEOSS0_TTL_DSP1_DATA_A02 // RED4
    
#define CY_DISP1_DATA_A0_3_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A0_3_PIN                  4
#define CY_DISP1_DATA_A0_3_PIN_MUX              P18_4_VIDEOSS0_TTL_DSP1_DATA_A03 // RED6
    
#define CY_DISP1_DATA_A0_4_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A0_4_PIN                  6
#define CY_DISP1_DATA_A0_4_PIN_MUX              P18_6_VIDEOSS0_TTL_DSP1_DATA_A04 // GREEN0
    
#define CY_DISP1_DATA_A0_5_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A0_5_PIN                  0
#define CY_DISP1_DATA_A0_5_PIN_MUX              P19_0_VIDEOSS0_TTL_DSP1_DATA_A05 // GREEN2
    
#define CY_DISP1_DATA_A0_6_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A0_6_PIN                  2
#define CY_DISP1_DATA_A0_6_PIN_MUX              P19_2_VIDEOSS0_TTL_DSP1_DATA_A06 // GREEN4
    
#define CY_DISP1_DATA_A0_7_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A0_7_PIN                  4
#define CY_DISP1_DATA_A0_7_PIN_MUX              P19_4_VIDEOSS0_TTL_DSP1_DATA_A07 // GREEN6
    
#define CY_DISP1_DATA_A0_8_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A0_8_PIN                  6
#define CY_DISP1_DATA_A0_8_PIN_MUX              P19_6_VIDEOSS0_TTL_DSP1_DATA_A08 // BLUE0
    
#define CY_DISP1_DATA_A0_9_PORT                 GPIO_PRT20
#define CY_DISP1_DATA_A0_9_PIN                  0
#define CY_DISP1_DATA_A0_9_PIN_MUX              P20_0_VIDEOSS0_TTL_DSP1_DATA_A09 // BLUE2
    
#define CY_DISP1_DATA_A0_10_PORT                GPIO_PRT20
#define CY_DISP1_DATA_A0_10_PIN                 2
#define CY_DISP1_DATA_A0_10_PIN_MUX             P20_2_VIDEOSS0_TTL_DSP1_DATA_A010// BLUE4
    
#define CY_DISP1_DATA_A0_11_PORT                GPIO_PRT20
#define CY_DISP1_DATA_A0_11_PIN                 4
#define CY_DISP1_DATA_A0_11_PIN_MUX             P20_4_VIDEOSS0_TTL_DSP1_DATA_A011// BLUE6
    
#define CY_DISP1_DATA_A1_0_PORT                 GPIO_PRT17
#define CY_DISP1_DATA_A1_0_PIN                  0
#define CY_DISP1_DATA_A1_0_PIN_MUX              P17_0_VIDEOSS0_TTL_DSP1_DATA_A10 // RED1
    
#define CY_DISP1_DATA_A1_1_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A1_1_PIN                  1
#define CY_DISP1_DATA_A1_1_PIN_MUX              P18_1_VIDEOSS0_TTL_DSP1_DATA_A11 // RED3
    
#define CY_DISP1_DATA_A1_2_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A1_2_PIN                  3
#define CY_DISP1_DATA_A1_2_PIN_MUX              P18_3_VIDEOSS0_TTL_DSP1_DATA_A12 // RED5
    
#define CY_DISP1_DATA_A1_3_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A1_3_PIN                  5
#define CY_DISP1_DATA_A1_3_PIN_MUX              P18_5_VIDEOSS0_TTL_DSP1_DATA_A13 // RED7
    
#define CY_DISP1_DATA_A1_4_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A1_4_PIN                  7
#define CY_DISP1_DATA_A1_4_PIN_MUX              P18_7_VIDEOSS0_TTL_DSP1_DATA_A14 // GREEN1
    
#define CY_DISP1_DATA_A1_5_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A1_5_PIN                  1
#define CY_DISP1_DATA_A1_5_PIN_MUX              P19_1_VIDEOSS0_TTL_DSP1_DATA_A15 // GREEN3
    
#define CY_DISP1_DATA_A1_6_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A1_6_PIN                  3
#define CY_DISP1_DATA_A1_6_PIN_MUX              P19_3_VIDEOSS0_TTL_DSP1_DATA_A16 // GREEN5
    
#define CY_DISP1_DATA_A1_7_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A1_7_PIN                  5
#define CY_DISP1_DATA_A1_7_PIN_MUX              P19_5_VIDEOSS0_TTL_DSP1_DATA_A17 // GREEN7
    
#define CY_DISP1_DATA_A1_8_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A1_8_PIN                  7
#define CY_DISP1_DATA_A1_8_PIN_MUX              P19_7_VIDEOSS0_TTL_DSP1_DATA_A18 // BLUE1
    
#define CY_DISP1_DATA_A1_9_PORT                 GPIO_PRT20
#define CY_DISP1_DATA_A1_9_PIN                  1
#define CY_DISP1_DATA_A1_9_PIN_MUX              P20_1_VIDEOSS0_TTL_DSP1_DATA_A19 // BLUE3
    
#define CY_DISP1_DATA_A1_10_PORT                GPIO_PRT20
#define CY_DISP1_DATA_A1_10_PIN                 3
#define CY_DISP1_DATA_A1_10_PIN_MUX             P20_3_VIDEOSS0_TTL_DSP1_DATA_A110// BLUE5
    
#define CY_DISP1_DATA_A1_11_PORT                GPIO_PRT20
#define CY_DISP1_DATA_A1_11_PIN                 5
#define CY_DISP1_DATA_A1_11_PIN_MUX             P20_5_VIDEOSS0_TTL_DSP1_DATA_A111// BLUE7
  
// IO connections P5.6, P5.7, P6.0 and P6.1 kept for FX3 adapter control signals.

  
/******************************************************************************/
/*                      Capture #0 Definitions                                */
/******************************************************************************/

// Capture 0 is multiplexed with Display 1, one of them can be used at a time.

#define CY_BSP_HDR_CAP0_TTL_AVAILABLE           // Definitions for this functionality are available
  
#define CY_CAP0_CLK_PORT                        GPIO_PRT15
#define CY_CAP0_CLK_PIN                         6
#define CY_CAP0_CLK_PIN_MUX                     P15_6_VIDEOSS0_TTL_CAP0_CLK      // CLK
                                          
#define CY_CAP0_DATA0_PORT                      GPIO_PRT15
#define CY_CAP0_DATA0_PIN                       7
#define CY_CAP0_DATA0_PIN_MUX                   P15_7_VIDEOSS0_TTL_CAP0_DATA0    // BLUE0
                                          
#define CY_CAP0_DATA1_PORT                      GPIO_PRT16
#define CY_CAP0_DATA1_PIN                       0
#define CY_CAP0_DATA1_PIN_MUX                   P16_0_VIDEOSS0_TTL_CAP0_DATA1    // BLUE1
                                          
#define CY_CAP0_DATA2_PORT                      GPIO_PRT16
#define CY_CAP0_DATA2_PIN                       1
#define CY_CAP0_DATA2_PIN_MUX                   P16_1_VIDEOSS0_TTL_CAP0_DATA2    // BLUE2
                                          
#define CY_CAP0_DATA3_PORT                      GPIO_PRT16
#define CY_CAP0_DATA3_PIN                       2
#define CY_CAP0_DATA3_PIN_MUX                   P16_2_VIDEOSS0_TTL_CAP0_DATA3    // BLUE3
                                          
#define CY_CAP0_DATA4_PORT                      GPIO_PRT16
#define CY_CAP0_DATA4_PIN                       3
#define CY_CAP0_DATA4_PIN_MUX                   P16_3_VIDEOSS0_TTL_CAP0_DATA4    // BLUE4
                                          
#define CY_CAP0_DATA5_PORT                      GPIO_PRT16
#define CY_CAP0_DATA5_PIN                       4
#define CY_CAP0_DATA5_PIN_MUX                   P16_4_VIDEOSS0_TTL_CAP0_DATA5    // BLUE5
                                          
#define CY_CAP0_DATA6_PORT                      GPIO_PRT16
#define CY_CAP0_DATA6_PIN                       5
#define CY_CAP0_DATA6_PIN_MUX                   P16_5_VIDEOSS0_TTL_CAP0_DATA6    // BLUE6
                                          
#define CY_CAP0_DATA7_PORT                      GPIO_PRT16
#define CY_CAP0_DATA7_PIN                       6
#define CY_CAP0_DATA7_PIN_MUX                   P16_6_VIDEOSS0_TTL_CAP0_DATA7    // BLUE7
                                          
#define CY_CAP0_DATA8_PORT                      GPIO_PRT16
#define CY_CAP0_DATA8_PIN                       7
#define CY_CAP0_DATA8_PIN_MUX                   P16_7_VIDEOSS0_TTL_CAP0_DATA8    // GREEN0
                                          
#define CY_CAP0_DATA9_PORT                      GPIO_PRT17
#define CY_CAP0_DATA9_PIN                       0
#define CY_CAP0_DATA9_PIN_MUX                   P17_0_VIDEOSS0_TTL_CAP0_DATA9    // GREEN1
                                          
#define CY_CAP0_DATA10_PORT                     GPIO_PRT18
#define CY_CAP0_DATA10_PIN                      0
#define CY_CAP0_DATA10_PIN_MUX                  P18_0_VIDEOSS0_TTL_CAP0_DATA10   // GREEN2
                                          
#define CY_CAP0_DATA11_PORT                     GPIO_PRT18
#define CY_CAP0_DATA11_PIN                      1
#define CY_CAP0_DATA11_PIN_MUX                  P18_1_VIDEOSS0_TTL_CAP0_DATA11   // GREEN3
                                          
#define CY_CAP0_DATA12_PORT                     GPIO_PRT18
#define CY_CAP0_DATA12_PIN                      2
#define CY_CAP0_DATA12_PIN_MUX                  P18_2_VIDEOSS0_TTL_CAP0_DATA12   // GREEN4
                                          
#define CY_CAP0_DATA13_PORT                     GPIO_PRT18
#define CY_CAP0_DATA13_PIN                      3
#define CY_CAP0_DATA13_PIN_MUX                  P18_3_VIDEOSS0_TTL_CAP0_DATA13   // GREEN5
                                          
#define CY_CAP0_DATA14_PORT                     GPIO_PRT18
#define CY_CAP0_DATA14_PIN                      4
#define CY_CAP0_DATA14_PIN_MUX                  P18_4_VIDEOSS0_TTL_CAP0_DATA14   // GREEN6
                                          
#define CY_CAP0_DATA15_PORT                     GPIO_PRT18
#define CY_CAP0_DATA15_PIN                      5
#define CY_CAP0_DATA15_PIN_MUX                  P18_5_VIDEOSS0_TTL_CAP0_DATA15   // GREEN7
                                          
#define CY_CAP0_DATA16_PORT                     GPIO_PRT18
#define CY_CAP0_DATA16_PIN                      6
#define CY_CAP0_DATA16_PIN_MUX                  P18_6_VIDEOSS0_TTL_CAP0_DATA16   // RED0
                                          
#define CY_CAP0_DATA17_PORT                     GPIO_PRT18
#define CY_CAP0_DATA17_PIN                      7
#define CY_CAP0_DATA17_PIN_MUX                  P18_7_VIDEOSS0_TTL_CAP0_DATA17   // RED1
                                          
#define CY_CAP0_DATA18_PORT                     GPIO_PRT19
#define CY_CAP0_DATA18_PIN                      0
#define CY_CAP0_DATA18_PIN_MUX                  P19_0_VIDEOSS0_TTL_CAP0_DATA18   // RED2
                                          
#define CY_CAP0_DATA19_PORT                     GPIO_PRT19
#define CY_CAP0_DATA19_PIN                      1
#define CY_CAP0_DATA19_PIN_MUX                  P19_1_VIDEOSS0_TTL_CAP0_DATA19   // RED3
                                          
#define CY_CAP0_DATA20_PORT                     GPIO_PRT19
#define CY_CAP0_DATA20_PIN                      2
#define CY_CAP0_DATA20_PIN_MUX                  P19_2_VIDEOSS0_TTL_CAP0_DATA20   // RED4
                                          
#define CY_CAP0_DATA21_PORT                     GPIO_PRT19
#define CY_CAP0_DATA21_PIN                      3
#define CY_CAP0_DATA21_PIN_MUX                  P19_3_VIDEOSS0_TTL_CAP0_DATA21   // RED5
                                          
#define CY_CAP0_DATA22_PORT                     GPIO_PRT19
#define CY_CAP0_DATA22_PIN                      4
#define CY_CAP0_DATA22_PIN_MUX                  P19_4_VIDEOSS0_TTL_CAP0_DATA22   // RED6
                                          
#define CY_CAP0_DATA23_PORT                     GPIO_PRT19
#define CY_CAP0_DATA23_PIN                      5
#define CY_CAP0_DATA23_PIN_MUX                  P19_5_VIDEOSS0_TTL_CAP0_DATA23   // RED7
                                          
#define CY_CAP0_DATA24_PORT                     GPIO_PRT19
#define CY_CAP0_DATA24_PIN                      6
#define CY_CAP0_DATA24_PIN_MUX                  P19_6_VIDEOSS0_TTL_CAP0_DATA24   // HSYNC
                                          
#define CY_CAP0_DATA25_PORT                     GPIO_PRT19
#define CY_CAP0_DATA25_PIN                      7
#define CY_CAP0_DATA25_PIN_MUX                  P19_7_VIDEOSS0_TTL_CAP0_DATA25   // VSYNC
                                          
#define CY_CAP0_DATA26_PORT                     GPIO_PRT20
#define CY_CAP0_DATA26_PIN                      0
#define CY_CAP0_DATA26_PIN_MUX                  P20_0_VIDEOSS0_TTL_CAP0_DATA26   // DE
  

/******************************************************************************/
/*                      FPD-LINK Definitions                                  */
/******************************************************************************/

// No need to configure FPDLINK io mux, it is a part of AMUXBUS.

/* FPDLINK Reference Clock */
#define CY_FPDLINK_CLK_REF_PORT                 GPIO_PRT22
#define CY_FPDLINK_CLK_REF_PIN                  3
#define CY_FPDLINK_CLK_REF_PIN_MUX              P22_3_VIDEOSS0_FPDLINK_CLKREF_GPIO

/* FPDLINK 0 Enable */
#define CY_FPDLINK0_BL_EN_PORT                  GPIO_PRT6
#define CY_FPDLINK0_BL_EN_PIN                   6
#define CY_FPDLINK0_BL_EN_PIN_MUX               P6_6_GPIO
  
/* FPDLINK 1 Enable */
#define CY_FPDLINK1_BL_EN_PORT                  GPIO_PRT6
#define CY_FPDLINK1_BL_EN_PIN                   7
#define CY_FPDLINK1_BL_EN_PIN_MUX               P6_7_GPIO
  
/* FPDLINK 0 Pwm */
#define CY_FPDLINK0_BL_PWM_PORT                 GPIO_PRT5
#define CY_FPDLINK0_BL_PWM_PIN                  4
#define CY_FPDLINK0_BL_PWM_PIN_MUX              P5_4_GPIO
  
/* FPDLINK 1 Pwm */
#define CY_FPDLINK1_BL_PWM_PORT                 GPIO_PRT5
#define CY_FPDLINK1_BL_PWM_PIN                  5
#define CY_FPDLINK1_BL_PWM_PIN_MUX              P5_5_GPIO
  
  
/******************************************************************************/
/*                      MIPI CSI-2 Definitions                                */
/******************************************************************************/

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
#define CY_MIPI_CSI_I2C_TYPE                    SCB7
  
#define CY_MIPI_CSI_I2C_SDA_PORT                GPIO_PRT9
#define CY_MIPI_CSI_I2C_SDA_PIN                 0
#define CY_MIPI_CSI_I2C_SDA_PIN_MUX             P9_0_SCB7_I2C_SDA
  
#define CY_MIPI_CSI_I2C_SCL_PORT                GPIO_PRT9
#define CY_MIPI_CSI_I2C_SCL_PIN                 1
#define CY_MIPI_CSI_I2C_SCL_PIN_MUX             P9_1_SCB7_I2C_SCL
  
#define CY_MIPI_CSI_I2C_PCLK                    PCLK_SCB7_CLOCK
#define CY_MIPI_CSI_I2C_IRQN                    scb_7_interrupt_IRQn
  

/******************************************************************************/
/*                      CXPI Definitions                                      */
/******************************************************************************/

// By default CXPI transceiver is not present on board, for testing CXPI fly wire
// can be connected to the external transceiver.

/* CXPI0 Channel 1 */
#define CY_CXPI0_TYPE                           CXPI0_CH1
  
#define CY_CXPI0_RX_PORT                        GPIO_PRT0
#define CY_CXPI0_RX_PIN                         3
#define CY_CXPI0_RX_PIN_MUX                     P0_3_CXPI0_CXPI_RX1
    
#define CY_CXPI0_TX_PORT                        GPIO_PRT0
#define CY_CXPI0_TX_PIN                         2
#define CY_CXPI0_TX_PIN_MUX                     P0_2_CXPI0_CXPI_TX1
    
#define CY_CXPI0_EN_PORT                        GPIO_PRT3
#define CY_CXPI0_EN_PIN                         4
#define CY_CXPI0_EN_PIN_MUX                     P3_4_CXPI0_CXPI_EN1
  
#define CY_CXPI0_CLK_PORT                       GPIO_PRT2               // J25_2
#define CY_CXPI0_CLK_PIN                        3
#define CY_CXPI0_CLK_PIN_MUX                    P2_3_TCPWM0_LINE24
#define CY_CXPI0_CLK_TCPWM_CNT                  TCPWM0_GRP0_CNT24
#define CY_CXPI0_CLK_TCPWM_PCLK                 PCLK_TCPWM0_CLOCKS24
  
#define CY_CXPI0_SEL_PORT                       GPIO_PRT7               // P8_9
#define CY_CXPI0_SEL_PIN                        5
#define CY_CXPI0_SEL_PIN_MUX                    P7_5_GPIO
  
#define CY_CXPI0_PCLK                           PCLK_CXPI0_CLOCK_CH_EN1
#define CY_CXPI0_IRQN                           cxpi_0_interrupts_1_IRQn 


/******************************************************************************/
/*                      AUDIO-TDM Definitions                                 */
/******************************************************************************/

// By default on board Codec doesn't support TDM, so for testing TDM fly wire
// can be connected to the external Codec.

#define CY_AUDIOSS_TDM_TYPE                     TDM0_TDM_STRUCT1
  
#define CY_AUDIOSS_TDM0_TX_MCK_PORT             GPIO_PRT4
#define CY_AUDIOSS_TDM0_TX_MCK_PIN              0
#define CY_AUDIOSS_TDM0_TX_MCK_PIN_MUX          P4_0_TDM0_TDM_TX_MCK1
  
#define CY_AUDIOSS_TDM0_TX_SCK_PORT             GPIO_PRT4
#define CY_AUDIOSS_TDM0_TX_SCK_PIN              1
#define CY_AUDIOSS_TDM0_TX_SCK_PIN_MUX          P4_1_TDM0_TDM_TX_SCK1
  
#define CY_AUDIOSS_TDM0_TX_FSYNC_PORT           GPIO_PRT4
#define CY_AUDIOSS_TDM0_TX_FSYNC_PIN            2
#define CY_AUDIOSS_TDM0_TX_FSYNC_PIN_MUX        P4_2_TDM0_TDM_TX_FSYNC1
  
#define CY_AUDIOSS_TDM0_TX_SD_PORT              GPIO_PRT4
#define CY_AUDIOSS_TDM0_TX_SD_PIN               3
#define CY_AUDIOSS_TDM0_TX_SD_PIN_MUX           P4_3_TDM0_TDM_TX_SD1
  
#define CY_AUDIOSS_TDM0_RX_MCK_PORT             GPIO_PRT5
#define CY_AUDIOSS_TDM0_RX_MCK_PIN              0
#define CY_AUDIOSS_TDM0_RX_MCK_PIN_MUX          P5_0_TDM0_TDM_RX_MCK1
  
#define CY_AUDIOSS_TDM0_RX_SCK_PORT             GPIO_PRT5
#define CY_AUDIOSS_TDM0_RX_SCK_PIN              1
#define CY_AUDIOSS_TDM0_RX_SCK_PIN_MUX          P5_1_TDM0_TDM_RX_SCK1
  
#define CY_AUDIOSS_TDM0_RX_FSYNC_PORT           GPIO_PRT5
#define CY_AUDIOSS_TDM0_RX_FSYNC_PIN            2
#define CY_AUDIOSS_TDM0_RX_FSYNC_PIN_MUX        P5_2_TDM0_TDM_RX_FSYNC1
  
#define CY_AUDIOSS_TDM0_RX_SD_PORT              GPIO_PRT5
#define CY_AUDIOSS_TDM0_RX_SD_PIN               3
#define CY_AUDIOSS_TDM0_RX_SD_PIN_MUX           P5_3_TDM0_TDM_RX_SD1
  
#define CY_AUDIOSS_TDM0_TX_IRQN                 tdm_0_interrupts_tx_1_IRQn
#define CY_AUDIOSS_TDM0_RX_IRQN                 tdm_0_interrupts_rx_1_IRQn 

// Based on the Codec communication interface, corresponding scb can be defined here.

  
/******************************************************************************/
/*                      AUDIO-SG Definitions                                  */
/******************************************************************************/

// Sound Generator driver circuit is not present on board, so for testing SG fly
// wire can be connected to the external driver circuit.

#define CY_AUDIOSS_SG0_TYPE                      SG0_SG_STRUCT0
  
#define CY_AUDIOSS_SG0_AMPL_PORT                 GPIO_PRT4
#define CY_AUDIOSS_SG0_AMPL_PIN                  0
#define CY_AUDIOSS_SG0_AMPL_PIN_MUX              P4_0_SG0_SG_AMPL0
  
#define CY_AUDIOSS_SG0_TONE_PORT                 GPIO_PRT4
#define CY_AUDIOSS_SG0_TONE_PIN                  1
#define CY_AUDIOSS_SG0_TONE_PIN_MUX              P4_1_SG0_SG_TONE0
  
#define CY_AUDIOSS_SG0_IRQ_IRQN                  sg_0_interrupts_0_IRQn
  
/******************************************************************************/
/*                              EXT CLK PORT                                  */
/******************************************************************************/
#define HF3_CLK_OUT_PORT                         GPIO_PRT3
#define HF3_CLK_OUT_PIN                          (3ul)
#define HF3_CLK_OUT_PIN_MUX                      P3_3_SRSS_EXT_CLK

/******************************************************************************/
/******************************************************************************/

// tviic2d6m - 327-BGA Package devices
    
// #if (CY_USE_PSVP == 0) (--> Silicon), project setting CY_USE_PSVP should be changed to '0'
// select the supported or required device accordingly
  
#elif (CY_USE_PSVP == 0) && defined(CYT4DNJBHS)
    
/******************************************************************************/
/******************************************************************************/

// CPU Board Entities

/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/*                      USER LED's                                            */
/******************************************************************************/    

#define CY_USER_LED1_PORT                       GPIO_PRT6 		// LD1
#define CY_USER_LED1_PIN                        2
#define CY_USER_LED1_PIN_MUX                    P6_2_GPIO
    
#define CY_USER_LED2_PORT                       GPIO_PRT6 		// LD2
#define CY_USER_LED2_PIN                        3
#define CY_USER_LED2_PIN_MUX                    P6_3_GPIO
    
#define CY_USER_LED3_PORT                       GPIO_PRT6 		// LD3
#define CY_USER_LED3_PIN                        4
#define CY_USER_LED3_PIN_MUX                    P6_4_GPIO


/******************************************************************************/
/*                      USER BUTTON's                                         */
/******************************************************************************/

#define CY_USER_BUTTON_UP_PORT                  GPIO_PRT6 		// SW6
#define CY_USER_BUTTON_UP_PIN                   7
#define CY_USER_BUTTON_UP_PIN_MUX               P6_7_GPIO
  
#define CY_USER_BUTTON_WAKE_PORT                GPIO_PRT3 		// SW5
#define CY_USER_BUTTON_WAKE_PIN                 1
#define CY_USER_BUTTON_WAKE_PIN_MUX             P3_1_GPIO
    
#define CY_USER_BUTTON_RIGHT_PORT               GPIO_PRT6 		// SW3
#define CY_USER_BUTTON_RIGHT_PIN                5
#define CY_USER_BUTTON_RIGHT_PIN_MUX            P6_5_GPIO
  
#define CY_USER_BUTTON_DOWN_PORT                GPIO_PRT7 		// SW7
#define CY_USER_BUTTON_DOWN_PIN                 1
#define CY_USER_BUTTON_DOWN_PIN_MUX             P7_1_GPIO
    
/* Setup GPIO for BUTTONs interrupt sources */
#define CY_USER_BUTTON_UP_IRQN                  ioss_interrupts_gpio_dpslp_6_IRQn
#define CY_USER_BUTTON_WAKE_IRQN                ioss_interrupts_gpio_dpslp_3_IRQn
#define CY_USER_BUTTON_RIGHT_IRQN               ioss_interrupts_gpio_dpslp_6_IRQn
#define CY_USER_BUTTON_DOWN_IRQN                ioss_interrupts_gpio_dpslp_7_IRQn


/******************************************************************************/
/*                      ADC POT                                               */
/******************************************************************************/

#define CY_ADC_POT_PORT                         GPIO_PRT7
#define CY_ADC_POT_PIN                          0
#define CY_ADC_POT_PIN_MUX                      P7_0_GPIO
  
#define CY_ADC_POT_MACRO                        PASS0_SAR0
#define CY_ADC_POT_IN_NO                        10
#define CY_ADC_POT_PCLK                         PCLK_PASS0_CLOCK_SAR0
#define CY_ADC_POT_IRQN                         pass_0_interrupts_sar_0_IRQn    // sar logical channel irq


/******************************************************************************/
/*                      SCB Mux                                               */
/******************************************************************************/
/* USB-UART Mux */
#define CY_USB_SCB_TYPE                         SCB11
  
#define CY_USB_SCB_UART_RX_PORT                 GPIO_PRT0
#define CY_USB_SCB_UART_RX_PIN                  4
#define CY_USB_SCB_UART_RX_MUX                  P0_4_SCB11_UART_RX

#define CY_USB_SCB_UART_TX_PORT                 GPIO_PRT0
#define CY_USB_SCB_UART_TX_PIN                  5
#define CY_USB_SCB_UART_TX_MUX                  P0_5_SCB11_UART_TX

#define CY_USB_SCB_UART_PCLK                    PCLK_SCB11_CLOCK
#define CY_USB_SCB_UART_IRQN                    scb_11_interrupt_IRQn


/******************************************************************************/
/*                      SMIF0 Definitions                                     */
/******************************************************************************/
#define CY_BSP_HDR_SMIF0_AVAILABLE              // Definitions for this functionality are available

#define CY_SMIF0_CLK_INV_PORT                   GPIO_PRT24
#define CY_SMIF0_CLK_INV_PIN                    0
#define CY_SMIF0_CLK_INV_PIN_MUX                P24_0_SMIF0_SPIHB_CLK
    
#define CY_SMIF0_CLK_PORT                       GPIO_PRT24
#define CY_SMIF0_CLK_PIN                        1
#define CY_SMIF0_CLK_PIN_MUX                    P24_1_SMIF0_SPIHB_CLK
  
#define CY_SMIF0_RWDS_PORT                      GPIO_PRT23
#define CY_SMIF0_RWDS_PIN                       4
#define CY_SMIF0_RWDS_PIN_MUX                   P23_4_SMIF0_SPIHB_RWDS
  
#define CY_SMIF0_SELECT0_PORT                   GPIO_PRT25
#define CY_SMIF0_SELECT0_PIN                    2
#define CY_SMIF0_SELECT0_PIN_MUX                P25_2_SMIF0_SPIHB_SELECT0
  
#define CY_SMIF0_SELECT1_PORT                   GPIO_PRT25
#define CY_SMIF0_SELECT1_PIN                    5
#define CY_SMIF0_SELECT1_PIN_MUX                P25_5_SMIF0_SPIHB_SELECT1
  
#define CY_SMIF0_DATA0_PORT                     GPIO_PRT25
#define CY_SMIF0_DATA0_PIN                      0
#define CY_SMIF0_DATA0_PIN_MUX                  P25_0_SMIF0_SPIHB_DATA0
  
#define CY_SMIF0_DATA1_PORT                     GPIO_PRT25
#define CY_SMIF0_DATA1_PIN                      3
#define CY_SMIF0_DATA1_PIN_MUX                  P25_3_SMIF0_SPIHB_DATA1
  
#define CY_SMIF0_DATA2_PORT                     GPIO_PRT23
#define CY_SMIF0_DATA2_PIN                      1
#define CY_SMIF0_DATA2_PIN_MUX                  P23_1_SMIF0_SPIHB_DATA2
  
#define CY_SMIF0_DATA3_PORT                     GPIO_PRT23
#define CY_SMIF0_DATA3_PIN                      2
#define CY_SMIF0_DATA3_PIN_MUX                  P23_2_SMIF0_SPIHB_DATA3
  
#define CY_SMIF0_DATA4_PORT                     GPIO_PRT23
#define CY_SMIF0_DATA4_PIN                      0
#define CY_SMIF0_DATA4_PIN_MUX                  P23_0_SMIF0_SPIHB_DATA4
  
#define CY_SMIF0_DATA5_PORT                     GPIO_PRT23
#define CY_SMIF0_DATA5_PIN                      3
#define CY_SMIF0_DATA5_PIN_MUX                  P23_3_SMIF0_SPIHB_DATA5
  
#define CY_SMIF0_DATA6_PORT                     GPIO_PRT25
#define CY_SMIF0_DATA6_PIN                      1
#define CY_SMIF0_DATA6_PIN_MUX                  P25_1_SMIF0_SPIHB_DATA6
  
#define CY_SMIF0_DATA7_PORT                     GPIO_PRT25
#define CY_SMIF0_DATA7_PIN                      4
#define CY_SMIF0_DATA7_PIN_MUX                  P25_4_SMIF0_SPIHB_DATA7
    
#define CY_SMIF_S25FXXXS                        (0u)
#define CY_SMIF_S25FXXXL                        (1u)
#define CY_SMIF0_QUAD_MEMORY                    CY_SMIF_S25FXXXL

// IO connections P7.2 kept for Semper Flash interrupt.


/******************************************************************************/
/*                      SMIF1 Definitions                                     */
/******************************************************************************/
#define CY_BSP_HDR_SMIF1_AVAILABLE              // Definitions for this functionality are available

#define CY_SMIF1_CLK_INV_PORT                   GPIO_PRT27
#define CY_SMIF1_CLK_INV_PIN                    0
#define CY_SMIF1_CLK_INV_PIN_MUX                P27_0_SMIF1_SPIHB_CLK
    
#define CY_SMIF1_CLK_PORT                       GPIO_PRT27
#define CY_SMIF1_CLK_PIN                        1
#define CY_SMIF1_CLK_PIN_MUX                    P27_1_SMIF1_SPIHB_CLK
  
#define CY_SMIF1_RWDS_PORT                      GPIO_PRT26
#define CY_SMIF1_RWDS_PIN                       4
#define CY_SMIF1_RWDS_PIN_MUX                   P26_4_SMIF1_SPIHB_RWDS
  
#define CY_SMIF1_SELECT0_PORT                   GPIO_PRT28
#define CY_SMIF1_SELECT0_PIN                    2
#define CY_SMIF1_SELECT0_PIN_MUX                P28_2_SMIF1_SPIHB_SELECT0
  
#define CY_SMIF1_SELECT1_PORT                   GPIO_PRT28
#define CY_SMIF1_SELECT1_PIN                    5
#define CY_SMIF1_SELECT1_PIN_MUX                P28_5_SMIF1_SPIHB_SELECT1
  
#define CY_SMIF1_DATA0_PORT                     GPIO_PRT28
#define CY_SMIF1_DATA0_PIN                      0
#define CY_SMIF1_DATA0_PIN_MUX                  P28_0_SMIF1_SPIHB_DATA0
  
#define CY_SMIF1_DATA1_PORT                     GPIO_PRT28
#define CY_SMIF1_DATA1_PIN                      3
#define CY_SMIF1_DATA1_PIN_MUX                  P28_3_SMIF1_SPIHB_DATA1
  
#define CY_SMIF1_DATA2_PORT                     GPIO_PRT26
#define CY_SMIF1_DATA2_PIN                      1
#define CY_SMIF1_DATA2_PIN_MUX                  P26_1_SMIF1_SPIHB_DATA2
  
#define CY_SMIF1_DATA3_PORT                     GPIO_PRT26
#define CY_SMIF1_DATA3_PIN                      2
#define CY_SMIF1_DATA3_PIN_MUX                  P26_2_SMIF1_SPIHB_DATA3
  
#define CY_SMIF1_DATA4_PORT                     GPIO_PRT26
#define CY_SMIF1_DATA4_PIN                      0
#define CY_SMIF1_DATA4_PIN_MUX                  P26_0_SMIF1_SPIHB_DATA4
  
#define CY_SMIF1_DATA5_PORT                     GPIO_PRT26
#define CY_SMIF1_DATA5_PIN                      3
#define CY_SMIF1_DATA5_PIN_MUX                  P26_3_SMIF1_SPIHB_DATA5
  
#define CY_SMIF1_DATA6_PORT                     GPIO_PRT28
#define CY_SMIF1_DATA6_PIN                      1
#define CY_SMIF1_DATA6_PIN_MUX                  P28_1_SMIF1_SPIHB_DATA6
  
#define CY_SMIF1_DATA7_PORT                     GPIO_PRT28
#define CY_SMIF1_DATA7_PIN                      4
#define CY_SMIF1_DATA7_PIN_MUX                  P28_4_SMIF1_SPIHB_DATA7
    
#define CY_SMIF_S25FXXXS                        (0u)
#define CY_SMIF_S25FXXXL                        (1u)
#define CY_SMIF1_QUAD_MEMORY                    CY_SMIF_S25FXXXL
  

/******************************************************************************/
/*                      AUDIOSS Port (I2S0) and SCB                           */
/******************************************************************************/

// I2S is multiplexed with Display 0, one of them can be used at a time.
  
#define CY_AUDIOSS_I2S_TYPE                     I2S0_I2S_STRUCT2
  
#define CY_AUDIOSS_I2S_TX_MCLK_PORT             GPIO_PRT4
#define CY_AUDIOSS_I2S_TX_MCLK_PIN              4
#define CY_AUDIOSS_I2S_TX_MCLK_PIN_MUX          P4_4_I2S0_I2S_TX_MCK2
  
#define CY_AUDIOSS_I2S_TX_SCK_PORT              GPIO_PRT4
#define CY_AUDIOSS_I2S_TX_SCK_PIN               5
#define CY_AUDIOSS_I2S_TX_SCK_PIN_MUX           P4_5_I2S0_I2S_TX_SCK2
  
#define CY_AUDIOSS_I2S_TX_WS_PORT               GPIO_PRT4
#define CY_AUDIOSS_I2S_TX_WS_PIN                6
#define CY_AUDIOSS_I2S_TX_WS_PIN_MUX            P4_6_I2S0_I2S_TX_WS2
  
#define CY_AUDIOSS_I2S_TX_SDO_PORT              GPIO_PRT4
#define CY_AUDIOSS_I2S_TX_SDO_PIN               7
#define CY_AUDIOSS_I2S_TX_SDO_PIN_MUX           P4_7_I2S0_I2S_TX_SD2
  
#define CY_AUDIOSS_I2S_RX_MCLK_PORT             GPIO_PRT5
#define CY_AUDIOSS_I2S_RX_MCLK_PIN              0
#define CY_AUDIOSS_I2S_RX_MCLK_PIN_MUX          P5_0_I2S0_I2S_RX_MCK2
    
#define CY_AUDIOSS_I2S_RX_SCK_PORT              GPIO_PRT5
#define CY_AUDIOSS_I2S_RX_SCK_PIN               1
#define CY_AUDIOSS_I2S_RX_SCK_PIN_MUX           P5_1_I2S0_I2S_RX_SCK2
  
#define CY_AUDIOSS_I2S_RX_WS_PORT               GPIO_PRT5
#define CY_AUDIOSS_I2S_RX_WS_PIN                2
#define CY_AUDIOSS_I2S_RX_WS_PIN_MUX            P5_2_I2S0_I2S_RX_WS2
  
#define CY_AUDIOSS_I2S_RX_SDI_PORT              GPIO_PRT5
#define CY_AUDIOSS_I2S_RX_SDI_PIN               3
#define CY_AUDIOSS_I2S_RX_SDI_PIN_MUX           P5_3_I2S0_I2S_RX_SD2
  
#define CY_AUDIOSS_I2S_TX_IRQN                  i2s_0_interrupts_tx_2_IRQn
#define CY_AUDIOSS_I2S_RX_IRQN                  i2s_0_interrupts_rx_2_IRQn
    
/* AUDIOSS-SPI port for Codec Communication */
#define CY_AUDIOSS_SPI_TYPE                     SCB8
  
#define CY_AUDIOSS_SPI_MISO_PORT                GPIO_PRT6
#define CY_AUDIOSS_SPI_MISO_PIN                 0
#define CY_AUDIOSS_SPI_MISO_PIN_MUX             P6_0_SCB8_SPI_MISO
  
#define CY_AUDIOSS_SPI_MOSI_PORT                GPIO_PRT5
#define CY_AUDIOSS_SPI_MOSI_PIN                 7
#define CY_AUDIOSS_SPI_MOSI_PIN_MUX             P5_7_SCB8_SPI_MOSI
  
#define CY_AUDIOSS_SPI_CLK_PORT                 GPIO_PRT5
#define CY_AUDIOSS_SPI_CLK_PIN                  6
#define CY_AUDIOSS_SPI_CLK_PIN_MUX              P5_6_SCB8_SPI_CLK
  
#define CY_AUDIOSS_SPI_SS0_PORT                 GPIO_PRT6
#define CY_AUDIOSS_SPI_SS0_PIN                  1
#define CY_AUDIOSS_SPI_SS0_PIN_MUX              P6_1_SCB8_SPI_SELECT0
  
#define CY_AUDIOSS_SPI_PCLK                     PCLK_SCB8_CLOCK
#define CY_AUDIOSS_SPI_IRQN                     scb_8_interrupt_IRQn  


/******************************************************************************/
/*                      AUDIOSS PCM-PWM                                       */
/******************************************************************************/

#define CY_AUDIOSS_PWM_TYPE                     PWM0_TX1
  
#define CY_AUDIOSS_PWM0_L1P1_PORT               GPIO_PRT4
#define CY_AUDIOSS_PWM0_L1P1_PIN                0
#define CY_AUDIOSS_PWM0_L1P1_PIN_MUX            P4_0_PWM0_PWM_LINE1_P0
  
#define CY_AUDIOSS_PWM0_L1N1_PORT               GPIO_PRT4
#define CY_AUDIOSS_PWM0_L1N1_PIN                1
#define CY_AUDIOSS_PWM0_L1N1_PIN_MUX            P4_1_PWM0_PWM_LINE1_N0
    
#define CY_AUDIOSS_PWM0_L2P1_PORT               GPIO_PRT4
#define CY_AUDIOSS_PWM0_L2P1_PIN                2
#define CY_AUDIOSS_PWM0_L2P1_PIN_MUX            P4_2_PWM0_PWM_LINE2_P0
    
#define CY_AUDIOSS_PWM0_L2N1_PORT               GPIO_PRT4
#define CY_AUDIOSS_PWM0_L2N1_PIN                3
#define CY_AUDIOSS_PWM0_L2N1_PIN_MUX            P4_3_PWM0_PWM_LINE2_N0
    
#define CY_AUDIOSS_PWM0_IRQN                    pwm_0_interrupts_0_IRQn
  

/******************************************************************************/
/*                      GIGA ETH Port                                         */
/******************************************************************************/

#define CY_GIG_ETH_TYPE                         ETH0
#define CY_GIG_ETH_INSTANCE_NUM                 (0)
                                          
#define CY_GIG_ETH_TX_CLK_PORT                  GPIO_PRT13
#define CY_GIG_ETH_TX_CLK_PIN                   3
#define CY_GIG_ETH_TX_CLK_PIN_MUX               P13_3_ETH0_TX_CLK
                                          
#define CY_GIG_ETH_TX_CTL_PORT                  GPIO_PRT15
#define CY_GIG_ETH_TX_CTL_PIN                   0
#define CY_GIG_ETH_TX_CTL_PIN_MUX               P15_0_ETH0_TX_CTL
                                          
#define CY_GIG_ETH_TD0_PORT                     GPIO_PRT14
#define CY_GIG_ETH_TD0_PIN                      3
#define CY_GIG_ETH_TD0_PIN_MUX                  P14_3_ETH0_TXD0
                                          
#define CY_GIG_ETH_TD1_PORT                     GPIO_PRT14
#define CY_GIG_ETH_TD1_PIN                      4
#define CY_GIG_ETH_TD1_PIN_MUX                  P14_4_ETH0_TXD1
                                          
#define CY_GIG_ETH_TD2_PORT                     GPIO_PRT14       
#define CY_GIG_ETH_TD2_PIN                      5
#define CY_GIG_ETH_TD2_PIN_MUX                  P14_5_ETH0_TXD2
                                          
#define CY_GIG_ETH_TD3_PORT                     GPIO_PRT14
#define CY_GIG_ETH_TD3_PIN                      6
#define CY_GIG_ETH_TD3_PIN_MUX                  P14_6_ETH0_TXD3
                                          
#define CY_GIG_ETH_TXER_PORT                    GPIO_PRT14
#define CY_GIG_ETH_TXER_PIN                     7
#define CY_GIG_ETH_TXER_PIN_MUX                 P14_7_ETH0_TX_ER
                                          
#define CY_GIG_ETH_RX_CLK_PORT                  GPIO_PRT13
#define CY_GIG_ETH_RX_CLK_PIN                   4
#define CY_GIG_ETH_RX_CLK_PIN_MUX               P13_4_ETH0_RX_CLK
                                          
#define CY_GIG_ETH_RX_CTL_PORT                  GPIO_PRT14
#define CY_GIG_ETH_RX_CTL_PIN                   2
#define CY_GIG_ETH_RX_CTL_PIN_MUX               P14_2_ETH0_RX_CTL
                                          
#define CY_GIG_ETH_RD0_PORT                     GPIO_PRT13
#define CY_GIG_ETH_RD0_PIN                      6
#define CY_GIG_ETH_RD0_PIN_MUX                  P13_6_ETH0_RXD0
                                          
#define CY_GIG_ETH_RD1_PORT                     GPIO_PRT13
#define CY_GIG_ETH_RD1_PIN                      7
#define CY_GIG_ETH_RD1_PIN_MUX                  P13_7_ETH0_RXD1
                                          
#define CY_GIG_ETH_RD2_PORT                     GPIO_PRT14
#define CY_GIG_ETH_RD2_PIN                      0
#define CY_GIG_ETH_RD2_PIN_MUX                  P14_0_ETH0_RXD2
                                          
#define CY_GIG_ETH_RD3_PORT                     GPIO_PRT14
#define CY_GIG_ETH_RD3_PIN                      1
#define CY_GIG_ETH_RD3_PIN_MUX                  P14_1_ETH0_RXD3
                                          
#define CY_GIG_ETH_RX_ER_PORT                   GPIO_PRT13        
#define CY_GIG_ETH_RX_ER_PIN                    5
#define CY_GIG_ETH_RX_ER_PIN_MUX                P13_5_ETH0_RX_ER
                                          
#define CY_GIG_ETH_MDC_PORT                     GPIO_PRT13
#define CY_GIG_ETH_MDC_PIN                      0
#define CY_GIG_ETH_MDC_PIN_MUX                  P13_0_ETH0_MDC
                                          
#define CY_GIG_ETH_MDIO_PORT                    GPIO_PRT13
#define CY_GIG_ETH_MDIO_PIN                     1
#define CY_GIG_ETH_MDIO_PIN_MUX                 P13_1_ETH0_MDIO
                                          
#define CY_GIG_ETH_REF_CLK_PORT                 GPIO_PRT13
#define CY_GIG_ETH_REF_CLK_PIN                  2
#define CY_GIG_ETH_REF_CLK_PIN_MUX              P13_2_ETH0_REF_CLK
  
/* Setup IRQ source for 0, 1 and 2 Priority Queue */
#define CY_GIG_ETH_IRQN0                        eth_0_interrupt_eth_0_IRQn
#define CY_GIG_ETH_IRQN1                        eth_0_interrupt_eth_1_IRQn
#define CY_GIG_ETH_IRQN2                        eth_0_interrupt_eth_2_IRQn
  

/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/

/* CAN1 Channel 0, please short J74(2-3) */
#define CY_CANFD0_TYPE                          CY_CANFD1_0_TYPE
#define CY_CANFD0_RX_PORT                       GPIO_PRT2
#define CY_CANFD0_RX_PIN                        4
#define CY_CANFD0_RX_MUX                        P2_4_CANFD1_TTCAN_RX0
#define CY_CANFD0_TX_PORT                       GPIO_PRT2
#define CY_CANFD0_TX_PIN                        3
#define CY_CANFD0_TX_MUX                        P2_3_CANFD1_TTCAN_TX0
#define CY_CANFD0_PCLK                          PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD0_IRQN                          canfd_1_interrupts0_0_IRQn
  
/* CAN1 Channel 1 */    
#define CY_CANFD1_TYPE                          CY_CANFD1_1_TYPE
#define CY_CANFD1_RX_PORT                       GPIO_PRT5
#define CY_CANFD1_RX_PIN                        5
#define CY_CANFD1_RX_MUX                        P5_5_CANFD1_TTCAN_RX1
#define CY_CANFD1_TX_PORT                       GPIO_PRT5
#define CY_CANFD1_TX_PIN                        4
#define CY_CANFD1_TX_MUX                        P5_4_CANFD1_TTCAN_TX1
#define CY_CANFD1_PCLK                          PCLK_CANFD1_CLOCK_CAN1
#define CY_CANFD1_IRQN                          canfd_1_interrupts0_1_IRQn
  

/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/* LIN0 Channel 1, please short J75(2-3) for LIN_EN */
#define CY_LINCH1_TYPE                          LIN0_CH1
#define CY_LINCH1_RX_PORT                       GPIO_PRT0
#define CY_LINCH1_RX_PIN                        1
#define CY_LINCH1_RX_PIN_MUX                    P0_1_LIN0_LIN_RX1
#define CY_LINCH1_TX_PORT                       GPIO_PRT0
#define CY_LINCH1_TX_PIN                        0
#define CY_LINCH1_TX_PIN_MUX                    P0_0_LIN0_LIN_TX1
#define CY_LINCH1_PCLK                          PCLK_LIN0_CLOCK_CH_EN1
#define CY_LINCH1_IRQN                          lin_0_interrupts_1_IRQn

  
/******************************************************************************/
/*                      SMARTIO Block                                         */
/******************************************************************************/

#define CY_SMARTIO_MACRO                        SMARTIO
#define CY_SMARTIO_PORT                         SMARTIO_PRT7
#define CY_SMARTIO_CLK                          PCLK_SMARTIO7_CLOCK
  
#define CY_SMARTIO_OUT_PORT                     GPIO_PRT7 			// TP174
#define CY_SMARTIO_OUT_PIN                      2
#define CY_SMARTIO_OUT_PORT_MUX                 P7_2_GPIO
  
#define CY_SMARTIO_IN_PORT                      GPIO_PRT7 			// J55_15
#define CY_SMARTIO_IN_PIN                       1
#define CY_SMARTIO_IN_PORT_MUX                  P7_1_GPIO
#define CY_SMARTIO_IN_PORT_MUX_PWM              P7_1_TCPWM0_LINE21

#define CY_SMARTIO_IN2_PORT                     GPIO_PRT7 			// TP172
#define CY_SMARTIO_IN2_PIN                      3
#define CY_SMARTIO_IN2_PORT_MUX                 P7_3_GPIO
#define CY_SMARTIO_IN2_PORT_MUX_PWM             P7_3_TCPWM0_LINE23

/* PWM PR Mode Configuration def */
#define CY_SMARTIO_TCPWM_GRP0_CNT               TCPWM0_GRP0_CNT21
#define CY_SMARTIO_TCPWM_PCLK                   PCLK_TCPWM0_CLOCKS21

#define CY_SMARTIO_TCPWM_GRP0_CNT2              TCPWM0_GRP0_CNT23
#define CY_SMARTIO_TCPWM_PCLK2                  PCLK_TCPWM0_CLOCKS23


/******************************************************************************/
/*                      AUDIO DAC Definitions                                 */
/******************************************************************************/

// No need to configure AUDIO-DAC io mux, it is available on P3 on board.

/* AUDIO-DAC Clock */
#define CY_AUDIO_DAC_MCK_PORT                   GPIO_PRT1
#define CY_AUDIO_DAC_MCK_PIN                    2
#define CY_AUDIO_DAC_MCK_PIN_MUX                P1_2_DAC0_DAC_MCK
  
  
/******************************************************************************/
/*                      Display Backlight Controls                            */
/******************************************************************************/

/* Display 1 Backlight */       
#define CY_BL_DISP1_PWM_PORT                    GPIO_PRT7
#define CY_BL_DISP1_PWM_PIN                     5
#define CY_BL_DISP1_PWM_PIN_MUX                 P7_5_GPIO  // use as GPIO for now (0% or 100% PWM)

  
/******************************************************************************/
/*                      Display #1 Definitions                                */
/******************************************************************************/
  
// Display 1 is multiplexed with Capture 0, one of them can be used at a time.

#define CY_BSP_HDR_DISP1_TTL_AVAILABLE          // Definitions for this functionality are available

#define CY_DISP1_CLK_PORT                       GPIO_PRT21
#define CY_DISP1_CLK_PIN                        1
#define CY_DISP1_CLK_PIN_MUX                    P21_1_VIDEOSS0_TTL_DSP1_CLOCK    // PCLK
    
#define CY_DISP1_CTRL0_PORT                     GPIO_PRT20
#define CY_DISP1_CTRL0_PIN                      6
#define CY_DISP1_CTRL0_PIN_MUX                  P20_6_VIDEOSS0_TTL_DSP1_CONTROL0 // LVALID
    
#define CY_DISP1_CTRL1_PORT                     GPIO_PRT20
#define CY_DISP1_CTRL1_PIN                      7
#define CY_DISP1_CTRL1_PIN_MUX                  P20_7_VIDEOSS0_TTL_DSP1_CONTROL1 // VSYNC
    
#define CY_DISP1_CTRL2_PORT                     GPIO_PRT21
#define CY_DISP1_CTRL2_PIN                      0
#define CY_DISP1_CTRL2_PIN_MUX                  P21_0_VIDEOSS0_TTL_DSP1_CONTROL2 // DE
    
#define CY_DISP1_DATA_A0_0_PORT                 GPIO_PRT16
#define CY_DISP1_DATA_A0_0_PIN                  7
#define CY_DISP1_DATA_A0_0_PIN_MUX              P16_7_VIDEOSS0_TTL_DSP1_DATA_A00 // RED0
    
#define CY_DISP1_DATA_A0_1_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A0_1_PIN                  0
#define CY_DISP1_DATA_A0_1_PIN_MUX              P18_0_VIDEOSS0_TTL_DSP1_DATA_A01 // RED2
    
#define CY_DISP1_DATA_A0_2_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A0_2_PIN                  2
#define CY_DISP1_DATA_A0_2_PIN_MUX              P18_2_VIDEOSS0_TTL_DSP1_DATA_A02 // RED4
    
#define CY_DISP1_DATA_A0_3_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A0_3_PIN                  4
#define CY_DISP1_DATA_A0_3_PIN_MUX              P18_4_VIDEOSS0_TTL_DSP1_DATA_A03 // RED6
    
#define CY_DISP1_DATA_A0_4_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A0_4_PIN                  6
#define CY_DISP1_DATA_A0_4_PIN_MUX              P18_6_VIDEOSS0_TTL_DSP1_DATA_A04 // GREEN0
    
#define CY_DISP1_DATA_A0_5_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A0_5_PIN                  0
#define CY_DISP1_DATA_A0_5_PIN_MUX              P19_0_VIDEOSS0_TTL_DSP1_DATA_A05 // GREEN2
    
#define CY_DISP1_DATA_A0_6_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A0_6_PIN                  2
#define CY_DISP1_DATA_A0_6_PIN_MUX              P19_2_VIDEOSS0_TTL_DSP1_DATA_A06 // GREEN4
    
#define CY_DISP1_DATA_A0_7_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A0_7_PIN                  4
#define CY_DISP1_DATA_A0_7_PIN_MUX              P19_4_VIDEOSS0_TTL_DSP1_DATA_A07 // GREEN6
    
#define CY_DISP1_DATA_A0_8_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A0_8_PIN                  6
#define CY_DISP1_DATA_A0_8_PIN_MUX              P19_6_VIDEOSS0_TTL_DSP1_DATA_A08 // BLUE0
    
#define CY_DISP1_DATA_A0_9_PORT                 GPIO_PRT20
#define CY_DISP1_DATA_A0_9_PIN                  0
#define CY_DISP1_DATA_A0_9_PIN_MUX              P20_0_VIDEOSS0_TTL_DSP1_DATA_A09 // BLUE2
    
#define CY_DISP1_DATA_A0_10_PORT                GPIO_PRT20
#define CY_DISP1_DATA_A0_10_PIN                 2
#define CY_DISP1_DATA_A0_10_PIN_MUX             P20_2_VIDEOSS0_TTL_DSP1_DATA_A010// BLUE4
    
#define CY_DISP1_DATA_A0_11_PORT                GPIO_PRT20
#define CY_DISP1_DATA_A0_11_PIN                 4
#define CY_DISP1_DATA_A0_11_PIN_MUX             P20_4_VIDEOSS0_TTL_DSP1_DATA_A011// BLUE6
    
#define CY_DISP1_DATA_A1_0_PORT                 GPIO_PRT17
#define CY_DISP1_DATA_A1_0_PIN                  0
#define CY_DISP1_DATA_A1_0_PIN_MUX              P17_0_VIDEOSS0_TTL_DSP1_DATA_A10 // RED1
    
#define CY_DISP1_DATA_A1_1_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A1_1_PIN                  1
#define CY_DISP1_DATA_A1_1_PIN_MUX              P18_1_VIDEOSS0_TTL_DSP1_DATA_A11 // RED3
    
#define CY_DISP1_DATA_A1_2_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A1_2_PIN                  3
#define CY_DISP1_DATA_A1_2_PIN_MUX              P18_3_VIDEOSS0_TTL_DSP1_DATA_A12 // RED5
    
#define CY_DISP1_DATA_A1_3_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A1_3_PIN                  5
#define CY_DISP1_DATA_A1_3_PIN_MUX              P18_5_VIDEOSS0_TTL_DSP1_DATA_A13 // RED7
    
#define CY_DISP1_DATA_A1_4_PORT                 GPIO_PRT18
#define CY_DISP1_DATA_A1_4_PIN                  7
#define CY_DISP1_DATA_A1_4_PIN_MUX              P18_7_VIDEOSS0_TTL_DSP1_DATA_A14 // GREEN1
    
#define CY_DISP1_DATA_A1_5_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A1_5_PIN                  1
#define CY_DISP1_DATA_A1_5_PIN_MUX              P19_1_VIDEOSS0_TTL_DSP1_DATA_A15 // GREEN3
    
#define CY_DISP1_DATA_A1_6_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A1_6_PIN                  3
#define CY_DISP1_DATA_A1_6_PIN_MUX              P19_3_VIDEOSS0_TTL_DSP1_DATA_A16 // GREEN5
    
#define CY_DISP1_DATA_A1_7_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A1_7_PIN                  5
#define CY_DISP1_DATA_A1_7_PIN_MUX              P19_5_VIDEOSS0_TTL_DSP1_DATA_A17 // GREEN7
    
#define CY_DISP1_DATA_A1_8_PORT                 GPIO_PRT19
#define CY_DISP1_DATA_A1_8_PIN                  7
#define CY_DISP1_DATA_A1_8_PIN_MUX              P19_7_VIDEOSS0_TTL_DSP1_DATA_A18 // BLUE1
    
#define CY_DISP1_DATA_A1_9_PORT                 GPIO_PRT20
#define CY_DISP1_DATA_A1_9_PIN                  1
#define CY_DISP1_DATA_A1_9_PIN_MUX              P20_1_VIDEOSS0_TTL_DSP1_DATA_A19 // BLUE3
    
#define CY_DISP1_DATA_A1_10_PORT                GPIO_PRT20
#define CY_DISP1_DATA_A1_10_PIN                 3
#define CY_DISP1_DATA_A1_10_PIN_MUX             P20_3_VIDEOSS0_TTL_DSP1_DATA_A110// BLUE5
    
#define CY_DISP1_DATA_A1_11_PORT                GPIO_PRT20
#define CY_DISP1_DATA_A1_11_PIN                 5
#define CY_DISP1_DATA_A1_11_PIN_MUX             P20_5_VIDEOSS0_TTL_DSP1_DATA_A111// BLUE7
  
// IO connections P16.0, P16.1, P16.2 and P16.3 kept for FX3 adapter control signals.

  
/******************************************************************************/
/*                      Capture #0 Definitions                                */
/******************************************************************************/

// Capture 0 is multiplexed with Display 1, one of them can be used at a time.

#define CY_BSP_HDR_CAP0_TTL_AVAILABLE           // Definitions for this functionality are available
  
#define CY_CAP0_CLK_PORT                        GPIO_PRT15
#define CY_CAP0_CLK_PIN                         6
#define CY_CAP0_CLK_PIN_MUX                     P15_6_VIDEOSS0_TTL_CAP0_CLK      // CLK
                                          
#define CY_CAP0_DATA0_PORT                      GPIO_PRT15
#define CY_CAP0_DATA0_PIN                       7
#define CY_CAP0_DATA0_PIN_MUX                   P15_7_VIDEOSS0_TTL_CAP0_DATA0    // BLUE0
                                          
#define CY_CAP0_DATA1_PORT                      GPIO_PRT16
#define CY_CAP0_DATA1_PIN                       0
#define CY_CAP0_DATA1_PIN_MUX                   P16_0_VIDEOSS0_TTL_CAP0_DATA1    // BLUE1
                                          
#define CY_CAP0_DATA2_PORT                      GPIO_PRT16
#define CY_CAP0_DATA2_PIN                       1
#define CY_CAP0_DATA2_PIN_MUX                   P16_1_VIDEOSS0_TTL_CAP0_DATA2    // BLUE2
                                          
#define CY_CAP0_DATA3_PORT                      GPIO_PRT16
#define CY_CAP0_DATA3_PIN                       2
#define CY_CAP0_DATA3_PIN_MUX                   P16_2_VIDEOSS0_TTL_CAP0_DATA3    // BLUE3
                                          
#define CY_CAP0_DATA4_PORT                      GPIO_PRT16
#define CY_CAP0_DATA4_PIN                       3
#define CY_CAP0_DATA4_PIN_MUX                   P16_3_VIDEOSS0_TTL_CAP0_DATA4    // BLUE4
                                          
#define CY_CAP0_DATA5_PORT                      GPIO_PRT16
#define CY_CAP0_DATA5_PIN                       4
#define CY_CAP0_DATA5_PIN_MUX                   P16_4_VIDEOSS0_TTL_CAP0_DATA5    // BLUE5
                                          
#define CY_CAP0_DATA6_PORT                      GPIO_PRT16
#define CY_CAP0_DATA6_PIN                       5
#define CY_CAP0_DATA6_PIN_MUX                   P16_5_VIDEOSS0_TTL_CAP0_DATA6    // BLUE6
                                          
#define CY_CAP0_DATA7_PORT                      GPIO_PRT16
#define CY_CAP0_DATA7_PIN                       6
#define CY_CAP0_DATA7_PIN_MUX                   P16_6_VIDEOSS0_TTL_CAP0_DATA7    // BLUE7
                                          
#define CY_CAP0_DATA8_PORT                      GPIO_PRT16
#define CY_CAP0_DATA8_PIN                       7
#define CY_CAP0_DATA8_PIN_MUX                   P16_7_VIDEOSS0_TTL_CAP0_DATA8    // GREEN0
                                          
#define CY_CAP0_DATA9_PORT                      GPIO_PRT17
#define CY_CAP0_DATA9_PIN                       0
#define CY_CAP0_DATA9_PIN_MUX                   P17_0_VIDEOSS0_TTL_CAP0_DATA9    // GREEN1
                                          
#define CY_CAP0_DATA10_PORT                     GPIO_PRT18
#define CY_CAP0_DATA10_PIN                      0
#define CY_CAP0_DATA10_PIN_MUX                  P18_0_VIDEOSS0_TTL_CAP0_DATA10   // GREEN2
                                          
#define CY_CAP0_DATA11_PORT                     GPIO_PRT18
#define CY_CAP0_DATA11_PIN                      1
#define CY_CAP0_DATA11_PIN_MUX                  P18_1_VIDEOSS0_TTL_CAP0_DATA11   // GREEN3
                                          
#define CY_CAP0_DATA12_PORT                     GPIO_PRT18
#define CY_CAP0_DATA12_PIN                      2
#define CY_CAP0_DATA12_PIN_MUX                  P18_2_VIDEOSS0_TTL_CAP0_DATA12   // GREEN4
                                          
#define CY_CAP0_DATA13_PORT                     GPIO_PRT18
#define CY_CAP0_DATA13_PIN                      3
#define CY_CAP0_DATA13_PIN_MUX                  P18_3_VIDEOSS0_TTL_CAP0_DATA13   // GREEN5
                                          
#define CY_CAP0_DATA14_PORT                     GPIO_PRT18
#define CY_CAP0_DATA14_PIN                      4
#define CY_CAP0_DATA14_PIN_MUX                  P18_4_VIDEOSS0_TTL_CAP0_DATA14   // GREEN6
                                          
#define CY_CAP0_DATA15_PORT                     GPIO_PRT18
#define CY_CAP0_DATA15_PIN                      5
#define CY_CAP0_DATA15_PIN_MUX                  P18_5_VIDEOSS0_TTL_CAP0_DATA15   // GREEN7
                                          
#define CY_CAP0_DATA16_PORT                     GPIO_PRT18
#define CY_CAP0_DATA16_PIN                      6
#define CY_CAP0_DATA16_PIN_MUX                  P18_6_VIDEOSS0_TTL_CAP0_DATA16   // RED0
                                          
#define CY_CAP0_DATA17_PORT                     GPIO_PRT18
#define CY_CAP0_DATA17_PIN                      7
#define CY_CAP0_DATA17_PIN_MUX                  P18_7_VIDEOSS0_TTL_CAP0_DATA17   // RED1
                                          
#define CY_CAP0_DATA18_PORT                     GPIO_PRT19
#define CY_CAP0_DATA18_PIN                      0
#define CY_CAP0_DATA18_PIN_MUX                  P19_0_VIDEOSS0_TTL_CAP0_DATA18   // RED2
                                          
#define CY_CAP0_DATA19_PORT                     GPIO_PRT19
#define CY_CAP0_DATA19_PIN                      1
#define CY_CAP0_DATA19_PIN_MUX                  P19_1_VIDEOSS0_TTL_CAP0_DATA19   // RED3
                                          
#define CY_CAP0_DATA20_PORT                     GPIO_PRT19
#define CY_CAP0_DATA20_PIN                      2
#define CY_CAP0_DATA20_PIN_MUX                  P19_2_VIDEOSS0_TTL_CAP0_DATA20   // RED4
                                          
#define CY_CAP0_DATA21_PORT                     GPIO_PRT19
#define CY_CAP0_DATA21_PIN                      3
#define CY_CAP0_DATA21_PIN_MUX                  P19_3_VIDEOSS0_TTL_CAP0_DATA21   // RED5
                                          
#define CY_CAP0_DATA22_PORT                     GPIO_PRT19
#define CY_CAP0_DATA22_PIN                      4
#define CY_CAP0_DATA22_PIN_MUX                  P19_4_VIDEOSS0_TTL_CAP0_DATA22   // RED6
                                          
#define CY_CAP0_DATA23_PORT                     GPIO_PRT19
#define CY_CAP0_DATA23_PIN                      5
#define CY_CAP0_DATA23_PIN_MUX                  P19_5_VIDEOSS0_TTL_CAP0_DATA23   // RED7
                                          
#define CY_CAP0_DATA24_PORT                     GPIO_PRT19
#define CY_CAP0_DATA24_PIN                      6
#define CY_CAP0_DATA24_PIN_MUX                  P19_6_VIDEOSS0_TTL_CAP0_DATA24   // HSYNC
                                          
#define CY_CAP0_DATA25_PORT                     GPIO_PRT19
#define CY_CAP0_DATA25_PIN                      7
#define CY_CAP0_DATA25_PIN_MUX                  P19_7_VIDEOSS0_TTL_CAP0_DATA25   // VSYNC
                                          
#define CY_CAP0_DATA26_PORT                     GPIO_PRT20
#define CY_CAP0_DATA26_PIN                      0
#define CY_CAP0_DATA26_PIN_MUX                  P20_0_VIDEOSS0_TTL_CAP0_DATA26   // DE
  

/******************************************************************************/
/*                      FPD-LINK Definitions                                  */
/******************************************************************************/

// No need to configure FPDLINK io mux, it is a part of AMUXBUS.

/* FPDLINK 0 Enable */
#define CY_FPDLINK0_BL_EN_PORT                  GPIO_PRT8
#define CY_FPDLINK0_BL_EN_PIN                   0
#define CY_FPDLINK0_BL_EN_PIN_MUX               P8_0_GPIO
  
/* FPDLINK 1 Enable */
#define CY_FPDLINK1_BL_EN_PORT                  GPIO_PRT8
#define CY_FPDLINK1_BL_EN_PIN                   1
#define CY_FPDLINK1_BL_EN_PIN_MUX               P8_1_GPIO
  
/* FPDLINK 0 Pwm */
#define CY_FPDLINK0_BL_PWM_PORT                 GPIO_PRT8
#define CY_FPDLINK0_BL_PWM_PIN                  2
#define CY_FPDLINK0_BL_PWM_PIN_MUX              P8_2_GPIO
  
/* FPDLINK 1 Pwm */
#define CY_FPDLINK1_BL_PWM_PORT                 GPIO_PRT8
#define CY_FPDLINK1_BL_PWM_PIN                  3
#define CY_FPDLINK1_BL_PWM_PIN_MUX              P8_3_GPIO
  
  
/******************************************************************************/
/*                      MIPI CSI-2 Definitions                                */
/******************************************************************************/

// No need to configure MIPI CSI io mux, it is a part of AMUXBUS.
// Please short J84(2-3) and J88(2-3) for I2C control path.

/* MIPI IO Clock */
#define CY_MIPI_CSI_IO_CLK_PORT                 GPIO_PRT15
#define CY_MIPI_CSI_IO_CLK_PIN                  4
#define CY_MIPI_CSI_IO_CLK_PIN_MUX              P15_4_GPIO

/* MIPI Power Enable */
#define CY_MIPI_CSI_PWDN_PORT                   GPIO_PRT15
#define CY_MIPI_CSI_PWDN_PIN                    5
#define CY_MIPI_CSI_PWDN_PIN_MUX                P15_5_GPIO
  
/* MIPI CSI Communication Block */
#define CY_MIPI_CSI_I2C_TYPE                    SCB0
  
#define CY_MIPI_CSI_I2C_SDA_PORT                GPIO_PRT0
#define CY_MIPI_CSI_I2C_SDA_PIN                 2
#define CY_MIPI_CSI_I2C_SDA_PIN_MUX             P0_2_SCB0_I2C_SDA
  
#define CY_MIPI_CSI_I2C_SCL_PORT                GPIO_PRT0
#define CY_MIPI_CSI_I2C_SCL_PIN                 3
#define CY_MIPI_CSI_I2C_SCL_PIN_MUX             P0_3_SCB0_I2C_SCL
  
#define CY_MIPI_CSI_I2C_PCLK                    PCLK_SCB0_CLOCK
#define CY_MIPI_CSI_I2C_IRQN                    scb_0_interrupt_IRQn
  

/******************************************************************************/
/*                      CXPI Definitions                                      */
/******************************************************************************/

/* CXPI0 Channel 1, please short J84(1-2), J88(1-2) and J75(1-2) */
#define CY_CXPI0_TYPE                           CXPI0_CH1
  
#define CY_CXPI0_RX_PORT                        GPIO_PRT0
#define CY_CXPI0_RX_PIN                         3
#define CY_CXPI0_RX_PIN_MUX                     P0_3_CXPI0_CXPI_RX1
    
#define CY_CXPI0_TX_PORT                        GPIO_PRT0
#define CY_CXPI0_TX_PIN                         2
#define CY_CXPI0_TX_PIN_MUX                     P0_2_CXPI0_CXPI_TX1
    
#define CY_CXPI0_EN_PORT                        GPIO_PRT3
#define CY_CXPI0_EN_PIN                         4
#define CY_CXPI0_EN_PIN_MUX                     P3_4_CXPI0_CXPI_EN1
  
#define CY_CXPI0_CLK_PORT                       GPIO_PRT0               
#define CY_CXPI0_CLK_PIN                        6
#define CY_CXPI0_CLK_PIN_MUX                    P0_6_TCPWM0_LINE28
#define CY_CXPI0_CLK_TCPWM_CNT                  TCPWM0_GRP0_CNT28
#define CY_CXPI0_CLK_TCPWM_PCLK                 PCLK_TCPWM0_CLOCKS28
  
#define CY_CXPI0_SEL_PORT                       GPIO_PRT7               
#define CY_CXPI0_SEL_PIN                        7
#define CY_CXPI0_SEL_PIN_MUX                    P7_7_GPIO
  
#define CY_CXPI0_PCLK                           PCLK_CXPI0_CLOCK_CH_EN1
#define CY_CXPI0_IRQN                           cxpi_0_interrupts_1_IRQn 


/******************************************************************************/
/*                      AUDIO-TDM Definitions                                 */
/******************************************************************************/

// By default board is compatible with TSG7x Audio Validation Board on J86 and J87.

#define CY_AUDIOSS_TDM_TYPE                     TDM0_TDM_STRUCT3
  
#define CY_AUDIOSS_TDM0_TX_MCK_PORT             GPIO_PRT9
#define CY_AUDIOSS_TDM0_TX_MCK_PIN              0
#define CY_AUDIOSS_TDM0_TX_MCK_PIN_MUX          P9_0_TDM0_TDM_TX_MCK3
  
#define CY_AUDIOSS_TDM0_TX_SCK_PORT             GPIO_PRT9
#define CY_AUDIOSS_TDM0_TX_SCK_PIN              1
#define CY_AUDIOSS_TDM0_TX_SCK_PIN_MUX          P9_1_TDM0_TDM_TX_SCK3
  
#define CY_AUDIOSS_TDM0_TX_FSYNC_PORT           GPIO_PRT9
#define CY_AUDIOSS_TDM0_TX_FSYNC_PIN            2
#define CY_AUDIOSS_TDM0_TX_FSYNC_PIN_MUX        P9_2_TDM0_TDM_TX_FSYNC3
  
#define CY_AUDIOSS_TDM0_TX_SD_PORT              GPIO_PRT9
#define CY_AUDIOSS_TDM0_TX_SD_PIN               3
#define CY_AUDIOSS_TDM0_TX_SD_PIN_MUX           P9_3_TDM0_TDM_TX_SD3
  
#define CY_AUDIOSS_TDM0_RX_MCK_PORT             GPIO_PRT9
#define CY_AUDIOSS_TDM0_RX_MCK_PIN              4
#define CY_AUDIOSS_TDM0_RX_MCK_PIN_MUX          P9_4_TDM0_TDM_RX_MCK3
  
#define CY_AUDIOSS_TDM0_RX_SCK_PORT             GPIO_PRT9
#define CY_AUDIOSS_TDM0_RX_SCK_PIN              5
#define CY_AUDIOSS_TDM0_RX_SCK_PIN_MUX          P9_5_TDM0_TDM_RX_SCK3
  
#define CY_AUDIOSS_TDM0_RX_FSYNC_PORT           GPIO_PRT9
#define CY_AUDIOSS_TDM0_RX_FSYNC_PIN            6
#define CY_AUDIOSS_TDM0_RX_FSYNC_PIN_MUX        P9_6_TDM0_TDM_RX_FSYNC3
  
#define CY_AUDIOSS_TDM0_RX_SD_PORT              GPIO_PRT9
#define CY_AUDIOSS_TDM0_RX_SD_PIN               7
#define CY_AUDIOSS_TDM0_RX_SD_PIN_MUX           P9_7_TDM0_TDM_RX_SD3
  
#define CY_AUDIOSS_TDM0_TX_IRQN                 tdm_0_interrupts_tx_3_IRQn
#define CY_AUDIOSS_TDM0_RX_IRQN                 tdm_0_interrupts_rx_3_IRQn 

// Based on the Codec communication interface, corresponding scb can be defined here.
#define CY_AUDIOSS_TDM0_I2C_TYPE                SCB1
  
#define CY_AUDIOSS_TDM0_I2C_SDA_PORT            GPIO_PRT15
#define CY_AUDIOSS_TDM0_I2C_SDA_PIN             2
#define CY_AUDIOSS_TDM0_I2C_SDA_PIN_MUX         P15_2_SCB1_I2C_SDA
  
#define CY_AUDIOSS_TDM0_I2C_SCL_PORT            GPIO_PRT15
#define CY_AUDIOSS_TDM0_I2C_SCL_PIN             3
#define CY_AUDIOSS_TDM0_I2C_SCL_PIN_MUX         P15_3_SCB1_I2C_SCL
  
#define CY_AUDIOSS_TDM0_I2C_PCLK                PCLK_SCB1_CLOCK
#define CY_AUDIOSS_TDM0_I2C_IRQN                scb_1_interrupt_IRQn

  
/******************************************************************************/
/*                      AUDIO-SG Definitions                                  */
/******************************************************************************/

// Sound Generator driver circuit is not present on board, so for testing SG fly
// wire can be connected to the external driver circuit from J85.

#define CY_AUDIOSS_SG0_TYPE                      SG0_SG_STRUCT0
  
#define CY_AUDIOSS_SG0_AMPL_PORT                 GPIO_PRT4
#define CY_AUDIOSS_SG0_AMPL_PIN                  0
#define CY_AUDIOSS_SG0_AMPL_PIN_MUX              P4_0_SG0_SG_AMPL0
  
#define CY_AUDIOSS_SG0_TONE_PORT                 GPIO_PRT4
#define CY_AUDIOSS_SG0_TONE_PIN                  1
#define CY_AUDIOSS_SG0_TONE_PIN_MUX              P4_1_SG0_SG_TONE0
  
#define CY_AUDIOSS_SG0_IRQ_IRQN                  sg_0_interrupts_0_IRQn

/******************************************************************************/
/*                              EXT CLK PORT                                  */
/******************************************************************************/
#define HF3_CLK_OUT_PORT                         GPIO_PRT3
#define HF3_CLK_OUT_PIN                          (3ul)
#define HF3_CLK_OUT_PIN_MUX                      P3_3_SRSS_EXT_CLK

/******************************************************************************/
/******************************************************************************/

#else // No Device or PSVP Selected

    #error "Choose either a Device based on TVII-C-2D-6M Datasheet or CY_USE_PSVP"

#endif // #if (CY_USE_PSVP == 1)


#ifdef __cplusplus
}
#endif

#endif /* BB_BSP_TVIIC2D6M_H */

/* [] END OF FILE */
