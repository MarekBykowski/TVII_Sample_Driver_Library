/***************************************************************************//**
* \file main_cm0plus.c
*
* \brief
* Main file for CM0+
*
********************************************************************************
* \copyright
* Copyright 2016-2019, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_project.h"
#include "cy_device_headers.h"

#include "cycfg_seglcd.h"

#if (CY_USE_PSVP == 1)
    #define USER_LED_PORT           CY_LED0_PORT
    #define USER_LED_PIN            CY_LED0_PIN
    #define USER_LED_PIN_MUX        CY_LED0_PIN_MUX
#else
    #define USER_LED_PORT           CY_LED0_PORT
    #define USER_LED_PIN            CY_LED0_PIN
    #define USER_LED_PIN_MUX        CY_LED0_PIN_MUX 
#endif

/* Scenario: There is a heart-shaped sign on an LCD glass: */
#define HEART                       (CY_SEGLCD_PIXEL(SegLCD_SEG_11, 7UL)) /* Seg: P11_6, Com: 7 */

/* Scenario: There is a battery-shaped frame on an LCD glass: */
#define FRAME                       (CY_SEGLCD_PIXEL(SegLCD_SEG_12, 7UL)) /* Seg: P12_6, Com: 7 */

#define BAR_LENGTH                  (4)

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

/* Scenario: Enable an LCD block */
cy_stc_seglcd_config_t config =
{
    .speed = CY_SEGLCD_SPEED_HIGH,
    .wave = CY_SEGLCD_TYPE_B,
    .drive = CY_SEGLCD_PWM,
    .bias = CY_SEGLCD_BIAS_FOURTH,
    .lsClk = CY_SEGLCD_LSCLK_LF,
    .comNum = 4,
    .frRate = 70,
    .contrast = 70,
  /*.clkFreq is unknown here */
};

const uint32_t commons[4] =
{
    CY_SEGLCD_COMMON(SegLCD_COM_0, 0UL),
    CY_SEGLCD_COMMON(SegLCD_COM_1, 1UL),
    CY_SEGLCD_COMMON(SegLCD_COM_2, 2UL),
    CY_SEGLCD_COMMON(SegLCD_COM_3, 3UL),
};

const uint32_t barGraphPixMap[BAR_LENGTH] =
{
    CY_SEGLCD_PIXEL(SegLCD_SEG_6,  7UL),
    CY_SEGLCD_PIXEL(SegLCD_SEG_5,  7UL),
    CY_SEGLCD_PIXEL(SegLCD_SEG_4,  7UL),
    CY_SEGLCD_PIXEL(SegLCD_SEG_2,  7UL)
};

const cy_stc_seglcd_disp_t barGraph =
{
    .type   = CY_SEGLCD_BAR,
    .symNum = BAR_LENGTH,
    .invert = false,
    .pixMap = (uint32_t*)barGraphPixMap,
    .font   = NULL
};

int main(void)
{
    uint32_t barGraphValue = 3UL; /* the value from 0 to barGraph.symNum */
    
    SystemInit();
  
    __enable_irq();
    
    /* Enable CM4. CY_CORTEX_M4_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR);

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);

    /* Scenario: Enable peripheral clock divider for LCD operation with 
     * the 2MHz clock frequency at the PeriClk frequency 50MHz
     */
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, 0U, 24U);
    Cy_SysClk_PeriphAssignDivider(PCLK_LCD0_CLOCK, CY_SYSCLK_DIV_8_BIT, 0U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_8_BIT, 0U);
    
    /* Initialize LCD */
    if (CY_SEGLCD_SUCCESS == Cy_SegLCD_Init((stc_LCD_t *)LCD0, &config))
    {
        if (CY_SEGLCD_SUCCESS == Cy_SegLCD_ClrFrame((stc_LCD_t *)LCD0, commons))
        {
            Cy_SegLCD_Enable((stc_LCD_t *)LCD0);
            
           /* Now the block generates LCD signals (all the pixels are off) and is ready to turn on any pixel
            * (or many pixels) using any of the frame/pixel/character/display management API functions.
            */
        }
        else
        {
            /* error handling */
        }
    }
    else
    {
        /* error handling */
    }
    
    /* Scenario: Write a decimal number starting at the most right symbol on display: */
    if (CY_SEGLCD_SUCCESS != Cy_SegLCD_WriteNumber((stc_LCD_t *)LCD0, 12, 3, &SegLCD_Display0, false, false))
    {
        /* error handling */
    }
    
    /* Scenario: Write a hexadecimal number with trailing zeroes: */
    if (CY_SEGLCD_SUCCESS != Cy_SegLCD_WriteNumber((stc_LCD_t *)LCD0, 12, 3, &SegLCD_Display0, true, true))
    {
        /* error handling */
    }
    
    /* Scenario: Set a pixel (write a true value) */
    if (CY_SEGLCD_SUCCESS != Cy_SegLCD_SetPixel((stc_LCD_t *)LCD0, HEART))
    {
        /* error handling */
    }
    
    /* Scenario: Clear a pixel (write a false value) */
    if (CY_SEGLCD_SUCCESS != Cy_SegLCD_ClrPixel((stc_LCD_t *)LCD0, HEART))
    {
        /* error handling */
    }
    
    /* Scenario: Invert a pixel (change the value to opposite) */
    Cy_SegLCD_InvPixel((stc_LCD_t *)LCD0, HEART);
    
    /* Scenario: Read a pixel value, do some action with it and write it back into the frame */
    bool pixelValue = Cy_SegLCD_ReadPixel((stc_LCD_t *)LCD0, HEART);
    Cy_SegLCD_WritePixel((stc_LCD_t *)LCD0, HEART, !pixelValue);
    
    /* Scenario: Set a frame for the battery-shaped bar-graph display */
    if (CY_SEGLCD_SUCCESS != Cy_SegLCD_SetPixel((stc_LCD_t *)LCD0, FRAME))
    {
        /* error handling */
    }
    
    /* Scenario: Write a bar graph starting from the first pixel of the barGraph display */
    if (CY_SEGLCD_SUCCESS != Cy_SegLCD_BarGraph((stc_LCD_t *)LCD0, barGraphValue, 0UL, &barGraph))
    {
        /* error handling */
    }
    
    for(;;)
    {
        // Wait 0.05 [s]
        Cy_SysTick_DelayInUs(50000);
        Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
    }
}



/* [] END OF FILE */
