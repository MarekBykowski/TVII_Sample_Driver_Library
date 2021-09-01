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

uint32_t test = 0;

int main(void)
{
    uint32_t value = 0;
    SystemInit();
  
    __enable_irq();
    
    // VIDEOSS Clock (enable clk_hf_videoss(clk_hf11) and clk_hf_dsp0(clk_hf12))
    CY_SET_REG32(0x4026126c, 0x80000100);
    CY_SET_REG32(0x40261270, 0x80000100);
    
    // GPIO Output MUX and Enable    
    
    // VIDEOSSCFG/IPCTRL
    CY_SET_REG32(0x40a00000, 0x80000000);
    
    // VIDEOSSCFG/CLKDSP0
    CY_SET_REG32(0x40a0000c, 0x00000000);
    
    // TCON0 Control
    //CY_SET_REG32(0x40AA3408, 0x00000004);
#if 1
    // Framegen
    // HTCFG1.HACT
    //value = 0x320;
    //value = value << 0;
    //CY_SET_REG32(0x40AA2004, value); // 0x320
    // HTCFG1.HTOTAL
    //value = 0x41A;
    //value = value << 16;
    value = 0x041A0320;
    //test = CY_GET_REG32(0x40AA2004);
    //test = test & 0xFFFF0000;
    //value = test | 0x320;
    CY_SET_REG32(0x40AA2004, value); // 0x41A
    // HTCFG2.HSYNC
    //value = 0x320;
    //value = value << 0;
    //value = value | 0x80000000;
    //value = 0x83860320;
    //CY_SET_REG32(0x40AA2008, value);
    // VTCFG1.VACT
    //value = 0x1E0;
    //value = value << 0;
    //CY_SET_REG32(0x40AA200C, value);
    // VTCFG1.VTOTAL
    //value = 0x208;
    //value = value << 16;
    value = 0x020801E0;
    //test = CY_GET_REG32(0x40AA200C);
    //test = test & 0xFFFF0000;
    //value = test | 0x1E0;
    CY_SET_REG32(0x40AA200C, value);
    // VTCFG2.VSYNC
    //value = 0x1E0;
    //value = value << 0;
    //value = value | 0x80000000;
    //value = 0x81EA01E0;
    //CY_SET_REG32(0x40AA2010, value);
#endif
    // Framegen0.Enable = 1
    CY_SET_REG32(0x40AA2064, 0x00000001);
    test = CY_GET_REG32(0x40AA2064);
    
    /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    //Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    //Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR);

    for(;;)
    {
        Cy_SysTick_DelayInUs(50000);
    }
}



/* [] END OF FILE */
