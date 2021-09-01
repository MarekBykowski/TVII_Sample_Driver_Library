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

#if (CY_USE_PSVP == 1)
  #error "This example is not supported in PSVP"
#endif

/* User Option */
#define CM4_160MHz_CM0_80MHz  (1u)
#define CM4_100MHz_CM0_100MHz (2u)
#define TEST_CASE_CPU_FREQ    CM4_100MHz_CM0_100MHz

#define USE_PLL               (1u)
#define USE_FLL               (2u)
#define USE_PLL_OR_FLL        USE_PLL
/* End of User Option */

#define USER_LED_PORT           CY_LED0_PORT
#define USER_LED_PIN            CY_LED0_PIN
#define USER_LED_PIN_MUX        CY_LED0_PIN_MUX

#define CLK_FREQ_ECO         (16000000ul)

#define FLL_PATH_NO          (0u)
#define PLL_PATH_NO          (1u)
#define BYPASSED_PATH_NO     (2u)

#if TEST_CASE_CPU_FREQ == CM4_160MHz_CM0_80MHz
// CM4: 160MHz, CM0+: 80MHz
  #define PLLFLL_OUT_FREQ_TSET (160000000ul)
  #define PERI_SOURCE_DIV   (1u)
#else
// CM4: 100MHz, CM0+: 100MHz
  #define PLLFLL_OUT_FREQ_TSET (100000000ul)
  #define PERI_SOURCE_DIV   (0u)
#endif

/** ECO parameters **/
#define LOAD_CAP_IN_PF         (20ul)

#if CLK_FREQ_ECO   < 16000000ul
#define ESR_IN_OHM            (250ul)
#elif CLK_FREQ_ECO < 20000000ul
#define ESR_IN_OHM            (150ul)
#elif CLK_FREQ_ECO < 30000000ul
#define ESR_IN_OHM            (100ul)
#else
#define ESR_IN_OHM            (70ul)
#endif

#define MAX_DRIVE_LEVEL_IN_UW  (100ul)

/** Wait time definition **/
#define WAIT_FOR_STABILIZATION (10000ul)


cy_stc_pll_config_t pllConfig = 
{
    .inputFreq  = CLK_FREQ_ECO,                 // ECO: 16MHz
    .outputFreq = PLLFLL_OUT_FREQ_TSET,         // target PLL output: 150MHz
    .lfMode     = 0u,                           // VCO frequency is [200MHz, 400MHz]
    .outputMode = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
};

cy_stc_pll_manual_config_t monitorPllConfig;
cy_stc_fll_manual_config_t monitorFllConfig;


cy_stc_gpio_pin_config_t user_led_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = USER_LED_PIN_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

void ToggleGpio(void)
{
    Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
}

int main(void)
{
    Cy_WDT_Disable();

    __enable_irq(); /* Enable global interrupts. */

    Cy_SysLib_SetWaitStates(PLLFLL_OUT_FREQ_TSET / 1000000ul);

    /***** ECO setting ******/
    {
        cy_en_sysclk_status_t ecoStatus;
        ecoStatus = Cy_SysClk_EcoConfigure(
                           CLK_FREQ_ECO,
                           LOAD_CAP_IN_PF,
                           ESR_IN_OHM,
                           MAX_DRIVE_LEVEL_IN_UW 
                           );
        CY_ASSERT(ecoStatus == CY_SYSCLK_SUCCESS);

        ecoStatus = Cy_SysClk_EcoEnable(WAIT_FOR_STABILIZATION);
        CY_ASSERT(ecoStatus == CY_SYSCLK_SUCCESS);
    }

    {
        // Set ECO to PATH2 source clock
        cy_en_sysclk_status_t status;
        status = Cy_SysClk_ClkPathSetSource( BYPASSED_PATH_NO, CY_SYSCLK_CLKPATH_IN_ECO);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);
        // Set CPU clock to PATH2
        status = Cy_SysClk_HfClockSetSource(CY_SYSCLK_HFCLK_0, CY_SYSCLK_HFCLK_IN_CLKPATH2);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);
    }


#if USE_PLL_OR_FLL == USE_FLL
    /***** FLL(PATH0) source setting ******/
    {
        cy_en_sysclk_status_t fllStatus;
        fllStatus = Cy_SysClk_ClkPathSetSource(FLL_PATH_NO, CY_SYSCLK_CLKPATH_IN_ECO);
        CY_ASSERT(fllStatus == CY_SYSCLK_SUCCESS);

        // disable FLL before setting up
        Cy_SysClk_FllDisableSequence(100ul);

        fllStatus = Cy_SysClk_FllConfigureStandard(CLK_FREQ_ECO, PLLFLL_OUT_FREQ_TSET, CY_SYSCLK_FLLPLL_OUTPUT_AUTO);
        CY_ASSERT(fllStatus == CY_SYSCLK_SUCCESS);

        fllStatus = Cy_SysClk_FllEnable(WAIT_FOR_STABILIZATION);
        CY_ASSERT(fllStatus == CY_SYSCLK_SUCCESS);

        Cy_SysClk_FllGetConfiguration(&monitorFllConfig);
    }
#else
    /***** PLL source setting ******/
    {
        cy_en_sysclk_status_t status;
        status = Cy_SysClk_ClkPathSetSource( PLL_PATH_NO, CY_SYSCLK_CLKPATH_IN_ECO);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_PllConfigure(PLL_PATH_NO , &pllConfig);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_PllEnable(PLL_PATH_NO, WAIT_FOR_STABILIZATION);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_PllGetConfiguration(PLL_PATH_NO, &monitorPllConfig);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);
    }

#endif

    /***** CLK FAST source setting ******/
    {
        Cy_SysClk_FastClkSetDivider(0ul); // No div
    }

    /***** CLK Peri source setting ******/
    {
        Cy_SysClk_PeriClkSetDivider(PERI_SOURCE_DIV);
    }

    /***** CLK SLOW source setting ******/
    {
        Cy_SysClk_SlowClkSetDivider(0ul); // No div
    }

    /***** CLK HF0 source setting ******/
    {
        cy_en_sysclk_status_t clkHf0status; 

        clkHf0status = Cy_SysClk_HfClockSetDivider(CY_SYSCLK_HFCLK_0, CY_SYSCLK_HFCLK_NO_DIVIDE);
        CY_ASSERT(clkHf0status == CY_SYSCLK_SUCCESS);

#if USE_PLL_OR_FLL == USE_PLL
        clkHf0status = Cy_SysClk_HfClockSetSource(CY_SYSCLK_HFCLK_0, CY_SYSCLK_HFCLK_IN_CLKPATH1 /* PLL 0*/);
#else
        clkHf0status = Cy_SysClk_HfClockSetSource(CY_SYSCLK_HFCLK_0, CY_SYSCLK_HFCLK_IN_CLKPATH0 /* FLL 0*/);
#endif
        CY_ASSERT(clkHf0status == CY_SYSCLK_SUCCESS);
    }


    /* Enable CM4. CY_CORTEX_M4_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR); 

    /*****  Cy_SysTick_Init ******/
    {
        Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
        Cy_SysTick_Init(CY_SYSTICK_CLOCK_SOURCE_CLK_CPU, 1000ul);
        Cy_SysTick_SetCallback(0ul, ToggleGpio);
    }

    // Now please check the frequency of LED0 blinking.
    // If clk_slow =  80MHz, the LED will be toggle at the interval of 80KHz
    // If clk_slow = 100MHz, the LED will be toggle at the interval of 100KHz

    for(;;);
}



/* [] END OF FILE */
