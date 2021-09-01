/***************************************************************************//**
* \file bb_bsp_tviibe1m_starter_kit.h
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

#ifndef BB_BSP_TVIIBE1M_STARTER_KIT_H
#define BB_BSP_TVIIBE1M_STARTER_KIT_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/******************************************************************************/
 
// tviibe1m - 100-LQFP Package devices  
#if (CY_USE_PSVP == 0) && ( defined(CYT2B75BAS) || defined(CYT2B75BAE) || \
                            defined(CYT2B75CAS) || defined(CYT2B75CAE) )

// Starter Board Entities

/******************************************************************************/
/*                      User LEDs Mux                                         */
/******************************************************************************/
#define CY_CB_LED_PORT                 	GPIO_PRT19
#define CY_CB_LED_PIN                  	0
#define CY_CB_LED_PIN_MUX             	P19_0_GPIO

#define CY_LED0_PORT                 	GPIO_PRT12
#define CY_LED0_PIN                  	2
#define CY_LED0_PIN_MUX              	P12_2_GPIO


/******************************************************************************/
/*                      User Buttons Mux                                         */
/******************************************************************************/
#define CY_CB_BUTTON_PORT              	GPIO_PRT7
#define CY_CB_BUTTON_PIN               	0
#define CY_CB_BUTTON_PIN_MUX           	P7_0_GPIO
#define CY_CB_BUTTON_IRQN              	ioss_interrupts_gpio_7_IRQn


/******************************************************************************/
/*                      ADC POT                                		      */
/******************************************************************************/
#define CY_ADC_POT_MACRO             	PASS0_SAR0
#define CY_ADC_POT_IN_NO             	0
#define CY_ADC_POT_PORT              	GPIO_PRT6
#define CY_ADC_POT_PIN               	0
#define CY_ADC_POT_PIN_MUX           	P6_0_GPIO
#define CY_ADC_POT_PCLK              	PCLK_PASS0_CLOCK_SAR0
#define CY_ADC_POT_IRQN              	pass_0_interrupts_sar_0_IRQn


/******************************************************************************/
/*                      SCB-UART USB Port Mux                                 */
/******************************************************************************/
#define CY_USB_SCB_TYPE              	SCB0
#define CY_USB_SCB_UART_RX_PORT      	GPIO_PRT0
#define CY_USB_SCB_UART_RX_PIN       	0
#define CY_USB_SCB_UART_RX_MUX       	P0_0_SCB0_UART_RX
#define CY_USB_SCB_UART_TX_PORT      	GPIO_PRT0
#define CY_USB_SCB_UART_TX_PIN       	1
#define CY_USB_SCB_UART_TX_MUX       	P0_1_SCB0_UART_TX
#define CY_USB_SCB_UART_PCLK         	PCLK_SCB0_CLOCK
#define CY_USB_SCB_UART_IRQN         	scb_0_interrupt_IRQn


/******************************************************************************/
/*                      CANFD Port Mux                                 */
/******************************************************************************/
#define CY_CANFD0_TYPE                	CY_CANFD0_1_TYPE
#define CY_CANFD0_RX_PORT             	GPIO_PRT0
#define CY_CANFD0_RX_PIN              	3u
#define CY_CANFD0_RX_MUX              	P0_3_CANFD0_TTCAN_RX1
#define CY_CANFD0_TX_PORT             	GPIO_PRT0
#define CY_CANFD0_TX_PIN              	2
#define CY_CANFD0_TX_MUX              	P0_2_CANFD0_TTCAN_TX1
#define CY_CANFD0_PCLK                	PCLK_CANFD0_CLOCK_CAN1
#define CY_CANFD0_IRQN                	canfd_0_interrupts0_1_IRQn

/******************************************************************************/
/******************************************************************************/
      
#else // No Device or PSVP Selected
    
    #error "Choose proper device and respective package"
    
#endif // #if (CY_USE_PSVP == 1)
  
  
#ifdef __cplusplus
}
#endif

#endif /* BB_BSP_TVIIBE1M_STARTER_KIT_H */

/* [] END OF FILE */
