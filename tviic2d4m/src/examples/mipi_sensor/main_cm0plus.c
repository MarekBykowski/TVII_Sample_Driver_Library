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

#if(CY_USE_PSVP==1)
#define USER_LED_PORT           CY_LED0_PORT
#define USER_LED_PIN            CY_LED0_PIN
#define USER_LED_PIN_MUX        CY_LED0_PIN_MUX 
#else
#define USER_LED_PORT           CY_USER_LED1_PORT
#define USER_LED_PIN            CY_USER_LED1_PIN
#define USER_LED_PIN_MUX        CY_USER_LED1_PIN_MUX 
#endif

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

const cy_mipicsi2_stc_cfg_t stcMipiUserCfg = {
    .bAutoPowerDown   = true,                         // ???
    .bContClkMode     = true,                         // ???
    .bHighSpeed       = true,                         // ???
    .u4FlushCount     = 3,                            // ???
    .u32BitrateBps    = 1500000000UL,                 // ???
    .u32EscClkFreqHz  = 220000000UL,                  // ???
    .enEscClk         = Mipicsi2EscapeClockClkVideo,  // ???
    .enLaneCount      = Mipicsi2LaneCount2,           // Mipicsi2LaneCount4,           // ???
    .enCalibration    = Mipicsi2CalibAutomatic,       // ???        
};


int main(void)
{
    SystemInit();
    
    __enable_irq();
    
    /* Enable CM7_0. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
    Cy_Mipi_Image_Sensor_DeInit();
    
    /* Initialize mipi sensor interface */
    Cy_Mipi_Image_Sensor_Init();
    
    /* To initialize videoss clock */
    Cy_GfxEnv_FastInit(false, false, NULL); 
    
    /* Initialize mipi interface */
    Cy_Mipicsi2_FastInit(VIDEOSS0_MIPICSI0);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqStatusUlpsMarkActiveChange, true);
    
    /* Set resolution mipi sensor interface */
    Cy_Mipi_Image_Sensor_Wakeup();
    Cy_Mipi_Image_Sensor_Set_Resolution((cy_en_mipi_sensor_resolution_type_t)CY_MIPI_SENSOR_RES_VGA);
    
    for(;;)
    {
        // Delay for 0.05[s]
        Cy_SysTick_DelayInUs(50000);      
        Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
    }
}



/* [] END OF FILE */
