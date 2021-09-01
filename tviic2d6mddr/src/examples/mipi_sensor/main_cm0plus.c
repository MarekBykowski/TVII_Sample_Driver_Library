/***************************************************************************//**
* \file main_cm0plus.c
*
* \version 1.0
*
* \brief Main example file for CM0+
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


#define USER_LED_PORT           CY_USER_LED1_PORT
#define USER_LED_PIN            CY_USER_LED1_PIN
#define USER_LED_PIN_MUX        CY_USER_LED1_PIN_MUX 

// The core frequency is 80MHz. 4000000 / 80MHz = 0.05[s]
#define USER_LED_TOGGLE_DELAY   4000000


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

static uint32_t bitErrStatus, irqErrStatus;

int main(void)
{
    SystemInit(); 
    
    __enable_irq();
    
    /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
    Cy_Mipi_Image_Sensor_DeInit();
    
    /* Initialize mipi sensor interface */
    Cy_Mipi_Image_Sensor_Init();
    
    /* To initialize videoss clock */
    Cy_GfxEnv_FastInit(false, false, NULL); 
    
    /* Initialize mipi interface */
    Cy_Mipicsi2_FastInit(VIDEOSS0_MIPICSI0);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorCrc, true);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccSingle, true);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccDouble, true);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqStatusUlpsActiveChange, true);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqStatusUlpsMarkActiveChange, true);
    
    /* Enable the test pattern for color bar */
    Cy_Mipi_Image_Sensor_Set_TestPattern(true);
    
    /* Set resolution mipi sensor interface */
    Cy_Mipi_Image_Sensor_Wakeup();
    
    for(;;)
    {
        bitErrStatus = CY_GET_REG32(0x40AD0210);        // Check for bit error status register
        irqErrStatus = CY_GET_REG32(0x40AD0214);        // Check for irq status register
        if((bitErrStatus == 0) && (irqErrStatus == 0))
        {
            Cy_SysTick_DelayInUs(50000);    
            Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
        }
    }
} 

/* [] END OF FILE */
