/***************************************************************************//**
* \file main_cm4.c
*
* \version 1.0
*
* \brief Main example file for CM4
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

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = CY_LED8_PIN_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
    .vregEn    = 0ul,
    .ibufMode  = 0ul,
    .vtripSel  = 0ul,
    .vrefSel   = 0ul,
    .vohSel    = 0ul,
};

cy_stc_mcwdt_config_t mcwdtConfig =
{
    .coreSelect       = CY_MCWDT_PAUSED_BY_DPSLP_CM4_CM7_0,
    .c0LowerLimit     = 0,
    .c0UpperLimit     = 32000, /* 1sec when clk_lf = 32KHz */
    .c0WarnLimit      = 0,
    .c0LowerAction    = CY_MCWDT_ACTION_NONE,
    .c0UpperAction    = CY_MCWDT_ACTION_FAULT_THEN_RESET, /* Note */
    .c0WarnAction     = CY_MCWDT_WARN_ACTION_NONE,
    .c0AutoService    = CY_MCWDT_DISABLE,
    .c0SleepDeepPause = CY_MCWDT_ENABLE,
    .c0DebugRun       = CY_MCWDT_ENABLE,
    .c1LowerLimit     = 100,
    .c1UpperLimit     = 64000, /* 2sec when clk_lf = 32KHz */
    .c1WarnLimit      = 0,
    .c1LowerAction    = CY_MCWDT_ACTION_NONE,
    .c1UpperAction    = CY_MCWDT_ACTION_NONE,
    .c1WarnAction     = CY_MCWDT_WARN_ACTION_NONE,
    .c1AutoService    = CY_MCWDT_DISABLE,
    .c1SleepDeepPause = CY_MCWDT_ENABLE,
    .c1DebugRun       = CY_MCWDT_ENABLE,
    .c2ToggleBit      = CY_MCWDT_CNT2_MONITORED_BIT15,
    .c2Action         = CY_MCWDT_CNT2_ACTION_INT,
    .c2SleepDeepPause = CY_MCWDT_ENABLE,
    .c2DebugRun       = CY_MCWDT_ENABLE,
};

int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /* If the reset cause is MCWDT1, it goes to infinite loop blinking a LED */
    {
        uint32_t resetReason;
        resetReason = Cy_SysReset_GetResetReason();
        if((resetReason & CY_SYSRESET_MCWDT1) != 0ul)
        {
            Cy_GPIO_Pin_Init(CY_LED8_PORT, CY_LED8_PIN, &user_led_port_pin_cfg);
            while(1)
            {
                Cy_SysTick_DelayInUs(50000ul);
                Cy_GPIO_Inv(CY_LED8_PORT, CY_LED8_PIN);
            }
        }
    }


    Cy_MCWDT_DeInit(MCWDT1);
    Cy_MCWDT_Init(MCWDT1, &mcwdtConfig);
    Cy_MCWDT_Unlock(MCWDT1);
    Cy_MCWDT_SetInterruptMask(MCWDT1, CY_MCWDT_CTR_Msk);
    Cy_MCWDT_Enable(MCWDT1, 
                    CY_MCWDT_CTR_Msk,  // enable all counter
                    0);
    Cy_MCWDT_Lock(MCWDT1);

    // turn off the LED.
    Cy_GPIO_Pin_Init(CY_LED8_PORT, CY_LED8_PIN, &user_led_port_pin_cfg);

    for(;;)
    {
#if 1 // If you want to trigger reset, remove this code.
        uint16_t lowerCounter = Cy_MCWDT_GetLowerLimit(MCWDT1, CY_MCWDT_COUNTER0);
        uint16_t countValue = (uint16_t)Cy_MCWDT_GetCount(MCWDT1, CY_MCWDT_COUNTER0);

        if(countValue > lowerCounter)
        {
            Cy_MCWDT_ClearWatchdog(MCWDT1, CY_MCWDT_COUNTER0);
            Cy_MCWDT_WaitForCounterReset(MCWDT1, CY_MCWDT_COUNTER0);
        }
#endif
    }
}



/* [] END OF FILE */
