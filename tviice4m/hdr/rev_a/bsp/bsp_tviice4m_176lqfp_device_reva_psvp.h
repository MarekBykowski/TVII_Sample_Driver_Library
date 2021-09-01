
/***************************************************************************//**
* \file :
* bsp_tviice4m_176lqfp_device_reva_psvp.h
* 
* \brief
* Project specific header
* 
* \note
* Auto generated file and should not be modified.
* 
********************************************************************************
* \copyright
* Copyright 2016-2021, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef BSP_TVIICE4M_176LQFP_DEVICE_REVA_PSVP_H
#define BSP_TVIICE4M_176LQFP_DEVICE_REVA_PSVP_H

#ifdef __cplusplus
extern C {
#endif

/******************************************************************************/
/******************************************************************************/


#if (defined(CYT2CL8BAS)) && (CY_USE_PSVP == 1)


/******************************************************************************/
/* GPIO                                                                       */
/******************************************************************************/


/**** LED ****/
#define CY_BSP_BB_USER_LED0_PORT   		GPIO_PRT8
#define CY_BSP_BB_USER_LED0_PIN    		0
#define CY_BSP_BB_USER_LED0_PIN_MUX		P8_0_GPIO
#define CY_BSP_BB_USER_LED0_IRQN   		ioss_interrupts_gpio_act_8_IRQn

#define CY_BSP_BB_USER_LED1_PORT   		GPIO_PRT8
#define CY_BSP_BB_USER_LED1_PIN    		1
#define CY_BSP_BB_USER_LED1_PIN_MUX		P8_1_GPIO
#define CY_BSP_BB_USER_LED1_IRQN   		ioss_interrupts_gpio_act_8_IRQn

#define CY_BSP_BB_USER_LED2_PORT   		GPIO_PRT8
#define CY_BSP_BB_USER_LED2_PIN    		2
#define CY_BSP_BB_USER_LED2_PIN_MUX		P8_2_GPIO
#define CY_BSP_BB_USER_LED2_IRQN   		ioss_interrupts_gpio_act_8_IRQn

#define CY_BSP_BB_USER_LED3_PORT   		GPIO_PRT8
#define CY_BSP_BB_USER_LED3_PIN    		3
#define CY_BSP_BB_USER_LED3_PIN_MUX		P8_3_GPIO
#define CY_BSP_BB_USER_LED3_IRQN   		ioss_interrupts_gpio_act_8_IRQn

#define CY_BSP_BB_USER_LED4_PORT   		GPIO_PRT8
#define CY_BSP_BB_USER_LED4_PIN    		4
#define CY_BSP_BB_USER_LED4_PIN_MUX		P8_4_GPIO
#define CY_BSP_BB_USER_LED4_IRQN   		ioss_interrupts_gpio_act_8_IRQn

#define CY_BSP_BB_USER_LED5_PORT   		GPIO_PRT8
#define CY_BSP_BB_USER_LED5_PIN    		5
#define CY_BSP_BB_USER_LED5_PIN_MUX		P8_5_GPIO
#define CY_BSP_BB_USER_LED5_IRQN   		ioss_interrupts_gpio_act_8_IRQn

#define CY_BSP_BB_USER_LED6_PORT   		GPIO_PRT8
#define CY_BSP_BB_USER_LED6_PIN    		6
#define CY_BSP_BB_USER_LED6_PIN_MUX		P8_6_GPIO
#define CY_BSP_BB_USER_LED6_IRQN   		ioss_interrupts_gpio_act_8_IRQn

#define CY_BSP_BB_USER_LED7_PORT   		GPIO_PRT8
#define CY_BSP_BB_USER_LED7_PIN    		7
#define CY_BSP_BB_USER_LED7_PIN_MUX		P8_7_GPIO
#define CY_BSP_BB_USER_LED7_IRQN   		ioss_interrupts_gpio_act_8_IRQn

#define CY_BSP_BB_USER_LED8_PORT   		GPIO_PRT9
#define CY_BSP_BB_USER_LED8_PIN    		0
#define CY_BSP_BB_USER_LED8_PIN_MUX		P9_0_GPIO
#define CY_BSP_BB_USER_LED8_IRQN   		ioss_interrupts_gpio_act_9_IRQn

#define CY_BSP_BB_USER_LED9_PORT   		GPIO_PRT9
#define CY_BSP_BB_USER_LED9_PIN    		1
#define CY_BSP_BB_USER_LED9_PIN_MUX		P9_1_GPIO
#define CY_BSP_BB_USER_LED9_IRQN   		ioss_interrupts_gpio_act_9_IRQn


/**** BUTTON ****/
#define CY_BSP_BB_USER_BUTTON1_PORT   	        GPIO_PRT10
#define CY_BSP_BB_USER_BUTTON1_PIN    	        0
#define CY_BSP_BB_USER_BUTTON1_PIN_MUX	        P10_0_GPIO
#define CY_BSP_BB_USER_BUTTON1_IRQN   	        ioss_interrupts_gpio_dpslp_10_IRQn

#define CY_BSP_BB_USER_BUTTON2_PORT   	        GPIO_PRT10
#define CY_BSP_BB_USER_BUTTON2_PIN    	        1
#define CY_BSP_BB_USER_BUTTON2_PIN_MUX	        P10_1_GPIO
#define CY_BSP_BB_USER_BUTTON2_IRQN   	        ioss_interrupts_gpio_dpslp_10_IRQn

#define CY_BSP_BB_USER_BUTTON3_PORT   	        GPIO_PRT10
#define CY_BSP_BB_USER_BUTTON3_PIN    	        2
#define CY_BSP_BB_USER_BUTTON3_PIN_MUX	        P10_2_GPIO
#define CY_BSP_BB_USER_BUTTON3_IRQN   	        ioss_interrupts_gpio_dpslp_10_IRQn

#define CY_BSP_BB_USER_BUTTON4_PORT   	        GPIO_PRT10
#define CY_BSP_BB_USER_BUTTON4_PIN    	        3
#define CY_BSP_BB_USER_BUTTON4_PIN_MUX	        P10_3_GPIO
#define CY_BSP_BB_USER_BUTTON4_IRQN   	        ioss_interrupts_gpio_dpslp_10_IRQn

#define CY_BSP_BB_USER_BUTTON5_PORT   	        GPIO_PRT10
#define CY_BSP_BB_USER_BUTTON5_PIN    	        4
#define CY_BSP_BB_USER_BUTTON5_PIN_MUX	        P10_4_GPIO
#define CY_BSP_BB_USER_BUTTON5_IRQN   	        ioss_interrupts_gpio_dpslp_10_IRQn


/******************************************************************************/
/* SCB                                                                        */
/******************************************************************************/

#define CY_BSP_USB_UART_TYPE   			SCB1
#define CY_BSP_USB_UART_RX_PORT   		GPIO_PRT11
#define CY_BSP_USB_UART_RX_PIN    		0
#define CY_BSP_USB_UART_RX_PIN_MUX		P11_0_SCB1_UART_RX

#define CY_BSP_USB_UART_TX_PORT   		GPIO_PRT11
#define CY_BSP_USB_UART_TX_PIN    		1
#define CY_BSP_USB_UART_TX_PIN_MUX		P11_1_SCB1_UART_TX
#define CY_BSP_USB_UART_PCLK   			PCLK_SCB1_CLOCK
#define CY_BSP_USB_UART_IRQN   			scb_1_interrupt_IRQn

#define CY_BSP_USER_UART2_TYPE   		SCB2
#define CY_BSP_USER_UART2_RX_PORT   	        GPIO_PRT12
#define CY_BSP_USER_UART2_RX_PIN    	        0
#define CY_BSP_USER_UART2_RX_PIN_MUX	        P12_0_SCB2_UART_RX

#define CY_BSP_USER_UART2_TX_PORT   	        GPIO_PRT12
#define CY_BSP_USER_UART2_TX_PIN    	        1
#define CY_BSP_USER_UART2_TX_PIN_MUX	        P12_1_SCB2_UART_TX
#define CY_BSP_USER_UART2_PCLK   		PCLK_SCB2_CLOCK
#define CY_BSP_USER_UART2_IRQN   		scb_2_interrupt_IRQn

#define CY_BSP_USER_UART0_TYPE   		SCB0
#define CY_BSP_USER_UART0_RX_PORT   	        GPIO_PRT14
#define CY_BSP_USER_UART0_RX_PIN    	        0
#define CY_BSP_USER_UART0_RX_PIN_MUX	        P14_0_SCB0_UART_RX

#define CY_BSP_USER_UART0_TX_PORT   	        GPIO_PRT14
#define CY_BSP_USER_UART0_TX_PIN    	        1
#define CY_BSP_USER_UART0_TX_PIN_MUX	        P14_1_SCB0_UART_TX
#define CY_BSP_USER_UART0_PCLK   		PCLK_SCB0_CLOCK
#define CY_BSP_USER_UART0_IRQN   		scb_0_interrupt_IRQn


/******************************************************************************/
/******************************************************************************/

#else 	/* No Device or PSVP Selected */

    #error Choose correct device from the device specific Datasheet. 

#endif 	/* #if(defined(CYT2CL8BAS)) */


#ifdef __cplusplus
}
#endif


#endif 	/* BSP_TVIICE4M_176LQFP_DEVICE_REVA_PSVP_H */


/* [] END OF FILE */
