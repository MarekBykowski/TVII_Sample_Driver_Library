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
 #error "This example is not supposed to work in PSVP environment."
#endif

#define PATH_SOURCE_CLOCK_ECO      (0u)
#define PATH_SOURCE_CLOCK_IMO      (1u)

/*****************************************/
/**********     User Option    ***********/
/*****************************************/
#define PATH_SOURCE_CLOCK_TEST PATH_SOURCE_CLOCK_ECO
#define FLL_TARGET_FREQ        (100000000UL)
#define PLL200_0_TARGET_FREQ   (160000000UL)
#define PLL200_1_TARGET_FREQ   (100000000UL)
#define PLL200_2_TARGET_FREQ   (200000000UL)
#define PLL400_0_TARGET_FREQ   (240000000UL)
#define PLL400_1_TARGET_FREQ   (196608000UL)
#define PLL400_2_TARGET_FREQ   (266000000UL)
#define PLL400_3_TARGET_FREQ   (200000000UL)
#define PLL400_4_TARGET_FREQ   (220000000UL)

/********** End of User Option ***********/

#define CLK_FREQ_ECO       (16000000ul)
#define CLK_FREQ_IMO       ( 8000000ul)

#if PATH_SOURCE_CLOCK_TEST == PATH_SOURCE_CLOCK_ECO
  #define PATH_SOURCE_CLOCK_FREQ CLK_FREQ_ECO
  #define PATH_SOURCE_CLOCK_IN   CY_SYSCLK_CLKPATH_IN_ECO
#elif PATH_SOURCE_CLOCK_TEST == PATH_SOURCE_CLOCK_IMO
  #define PATH_SOURCE_CLOCK_FREQ CLK_FREQ_IMO
  #define PATH_SOURCE_CLOCK_IN   CY_SYSCLK_CLKPATH_IN_IMO
#else
  #error "Option not supported"
#endif

#define USER_LED_PORT        CY_USER_LED1_PORT
#define USER_LED_PIN         CY_USER_LED1_PIN
#define USER_LED_PIN_MUX     CY_USER_LED1_PIN_MUX

#define FLL_PATH_NO          (0u)
#define PLL_400M_0_PATH_NO   (1u)
#define PLL_400M_1_PATH_NO   (2u)
#define PLL_400M_2_PATH_NO   (3u)
#define PLL_400M_3_PATH_NO   (4u)
#define PLL_400M_4_PATH_NO   (5u)
#define PLL_200M_0_PATH_NO   (6u)
#define PLL_200M_1_PATH_NO   (7u)
#define PLL_200M_2_PATH_NO   (8u)
#define BYPASSED_PATH_NO     (9u)


/** ECO parameters **/
#define SUM_LOAD_SHUNT_CAP_IN_PF (17ul)

#if CLK_FREQ_ECO   < 16000000ul
#define ESR_IN_OHM            (250ul)
#elif CLK_FREQ_ECO < 20000000ul
#define ESR_IN_OHM            (150ul)
#elif CLK_FREQ_ECO < 30000000ul
#define ESR_IN_OHM            (100ul)
#else
#define ESR_IN_OHM            (70ul)
#endif

#define MIN_NEG_RESISTANCE     (5 * ESR_IN_OHM)
#define MAX_DRIVE_LEVEL_IN_UW  (100ul)


/** Wait time definition **/
#define WAIT_FOR_STABILIZATION (10000ul)

typedef struct
{
    cy_en_meas_clks_t name;
    uint32_t measuredFreq;
} stc_clock_measure;

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =
{
    .outVal    = 0x00,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = USER_LED_PIN_MUX,
    .intEdge   = 0,
    .intMask   = 0,
    .vtrip     = 0,
    .slewRate  = 0,
    .driveSel  = 0,
};

stc_clock_measure clockMeasuredInfo[] = 
{
    {.name = CY_SYSCLK_MEAS_CLK_ILO0,    .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_WCO,     .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_BAK,     .measuredFreq= 0u}, // CLK_RTC
    {.name = CY_SYSCLK_MEAS_CLK_LFCLK,   .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_IMO,     .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_ILO1,    .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_ECO,     .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_ECO_PRE, .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_PATH0,   .measuredFreq= 0u}, // frequency should be same as that of input in PSVP.
    {.name = CY_SYSCLK_MEAS_CLK_PATH1,   .measuredFreq= 0u}, // frequency should be same as that of input in PSVP.
    {.name = CY_SYSCLK_MEAS_CLK_PATH2,   .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_PATH3,   .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_PATH4,   .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_PATH5,   .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_PATH6,   .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_PATH7,   .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_PATH8,   .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_PATH9,   .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK0,  .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK1,  .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK2,  .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK3,  .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK4,  .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK5,  .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK6,  .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK7,  .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK8,  .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK9,  .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK10, .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK11, .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK12, .measuredFreq= 0u},
    {.name = CY_SYSCLK_MEAS_CLK_HFCLK13, .measuredFreq= 0u},
};

#define NUM_OF_MEASURED_CLOCK (sizeof(clockMeasuredInfo) / sizeof(stc_clock_measure))

cy_stc_pll_config_t pll200_0_Config = 
{
    .inputFreq     = PATH_SOURCE_CLOCK_FREQ, // ECO: 16MHz
    .outputFreq    = PLL200_0_TARGET_FREQ,// target PLL output
    .lfMode        = 0u,           // VCO frequency is [200MHz, 400MHz]
    .outputMode    = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
};

cy_stc_pll_config_t pll200_1_Config = 
{
    .inputFreq     = PATH_SOURCE_CLOCK_FREQ, // ECO: 16MHz
    .outputFreq    = PLL200_1_TARGET_FREQ,// target PLL output
    .lfMode        = 0u,           // VCO frequency is [200MHz, 400MHz]
    .outputMode    = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
};

cy_stc_pll_config_t pll200_2_Config = 
{
    .inputFreq     = PATH_SOURCE_CLOCK_FREQ, // ECO: 16MHz
    .outputFreq    = PLL200_2_TARGET_FREQ,// target PLL output
    .lfMode        = 0u,           // VCO frequency is [200MHz, 400MHz]
    .outputMode    = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
};

cy_stc_pll_400M_config_t pll400_0_Config =
{
    .inputFreq    = PATH_SOURCE_CLOCK_FREQ,
    .outputFreq   = PLL400_0_TARGET_FREQ,
    .outputMode   = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
    .fracEn       = false,
    .fracDitherEn = false,
    .sscgEn       = true,
    .sscgDitherEn = true,
    .sscgDepth    = CY_SYSCLK_SSCG_DEPTH_MINUS_2_0,
    .sscgRate     = CY_SYSCLK_SSCG_RATE_DIV_512,
};

cy_stc_pll_400M_config_t pll400_1_Config =
{
    .inputFreq    = PATH_SOURCE_CLOCK_FREQ,
    .outputFreq   = PLL400_1_TARGET_FREQ,
    .outputMode   = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
    .fracEn       = true,
    .fracDitherEn = true,
    .sscgEn       = false,
    .sscgDitherEn = false,
    .sscgDepth    = CY_SYSCLK_SSCG_DEPTH_MINUS_2_0,
    .sscgRate     = CY_SYSCLK_SSCG_RATE_DIV_512,
};

cy_stc_pll_400M_config_t pll400_2_Config =
{
    .inputFreq    = PATH_SOURCE_CLOCK_FREQ,
    .outputFreq   = PLL400_2_TARGET_FREQ,
    .outputMode   = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
    .fracEn       = false,
    .fracDitherEn = false,
    .sscgEn       = true,
    .sscgDitherEn = true,
    .sscgDepth    = CY_SYSCLK_SSCG_DEPTH_MINUS_2_0,
    .sscgRate     = CY_SYSCLK_SSCG_RATE_DIV_512,
};

cy_stc_pll_400M_config_t pll400_3_Config =
{
    .inputFreq    = PATH_SOURCE_CLOCK_FREQ,
    .outputFreq   = PLL400_3_TARGET_FREQ,
    .outputMode   = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
    .fracEn       = false,
    .fracDitherEn = false,
    .sscgEn       = true,
    .sscgDitherEn = true,
    .sscgDepth    = CY_SYSCLK_SSCG_DEPTH_MINUS_2_0,
    .sscgRate     = CY_SYSCLK_SSCG_RATE_DIV_512,
};

cy_stc_pll_400M_config_t pll400_4_Config =
{
    .inputFreq    = PATH_SOURCE_CLOCK_FREQ,
    .outputFreq   = PLL400_4_TARGET_FREQ,
    .outputMode   = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
    .fracEn       = false,
    .fracDitherEn = false,
    .sscgEn       = true,
    .sscgDitherEn = true,
    .sscgDepth    = CY_SYSCLK_SSCG_DEPTH_MINUS_2_0,
    .sscgRate     = CY_SYSCLK_SSCG_RATE_DIV_512,
};

cy_stc_pll_manual_config_t monitorPll200_0_Config;
cy_stc_pll_manual_config_t monitorPll200_1_Config;
cy_stc_pll_manual_config_t monitorPll200_2_Config;
cy_stc_pll_400M_manual_config_t monitorPll400_0_Config;
cy_stc_pll_400M_manual_config_t monitorPll400_1_Config;
cy_stc_pll_400M_manual_config_t monitorPll400_2_Config;
cy_stc_pll_400M_manual_config_t monitorPll400_3_Config;
cy_stc_pll_400M_manual_config_t monitorPll400_4_Config;
cy_stc_fll_manual_config_t monitorFllConfig;

static void AllClockConfiguration(void);
static void MeasureClockFrequency(void);
static void RecalucClockFrequencyValues(void);
static void StartSystickUsingECO(void);
static void ToggleGpio(void);

int main(void)
{
    /* disable watchdog timer */
    Cy_WDT_Disable();

    Cy_SysLib_SetWaitStates((PLL200_0_TARGET_FREQ / 1000000UL));

    /* Set clk_hf0 souce IMO (8MHz) */
    CY_ASSERT(Cy_SysClk_ClkPathSetSource(BYPASSED_PATH_NO, CY_SYSCLK_CLKPATH_IN_IMO) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_0) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_HfClockSetSource(CY_SYSCLK_HFCLK_0, (cy_en_hf_clk_sources_t)BYPASSED_PATH_NO) == CY_SYSCLK_SUCCESS);

    /* Disable Fll */
    Cy_SysClk_FllDisableSequence(100);

    /* Disable Pll */
    CY_ASSERT(Cy_SysClk_Pll400MDisable(PLL_400M_0_PATH_NO) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_Pll400MDisable(PLL_400M_1_PATH_NO) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_Pll400MDisable(PLL_400M_2_PATH_NO) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_Pll400MDisable(PLL_400M_3_PATH_NO) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_Pll400MDisable(PLL_400M_4_PATH_NO) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_PllDisable(PLL_200M_0_PATH_NO) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_PllDisable(PLL_200M_1_PATH_NO) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_PllDisable(PLL_200M_2_PATH_NO) == CY_SYSCLK_SUCCESS);

    __enable_irq();

    AllClockConfiguration();

    MeasureClockFrequency();

    StartSystickUsingECO();

    RecalucClockFrequencyValues();

    // After the PC reach here,
    // 1. check the LED frequency is 8KHz (IRQ occurs with 16kHz --> toggling LED)
    // 2. check "clockMeasuredInfo"
    // 3. check "reportedClockFreq"
    for(;;);
}

static void AllClockConfiguration(void)
{
    /***** 1. ECO setting ******/
    {
        #if 1
        cy_en_sysclk_status_t ecoStatus;
        ecoStatus = Cy_SysClk_EcoConfigureWithMinRneg(
                           CLK_FREQ_ECO,
                           SUM_LOAD_SHUNT_CAP_IN_PF,
                           ESR_IN_OHM,
                           MAX_DRIVE_LEVEL_IN_UW,
                           MIN_NEG_RESISTANCE
                           );
        CY_ASSERT(ecoStatus == CY_SYSCLK_SUCCESS);

        ecoStatus = Cy_SysClk_EcoEnable(WAIT_FOR_STABILIZATION);
        CY_ASSERT(ecoStatus == CY_SYSCLK_SUCCESS);
        #else
        /***    ECO setting and enabling        ***/
        // These values need to be confirmed
        SRSS->unCLK_ECO_CONFIG2.stcField.u3WDTRIM = 4u;
        SRSS->unCLK_ECO_CONFIG2.stcField.u4ATRIM  = 12u;
        SRSS->unCLK_ECO_CONFIG2.stcField.u2FTRIM  = 3u;
        SRSS->unCLK_ECO_CONFIG2.stcField.u2RTRIM  = 3u;
        SRSS->unCLK_ECO_CONFIG2.stcField.u3GTRIM  = 1u;

        SRSS->unCLK_ECO_CONFIG.stcField.u1ECO_EN = 1ul;
        while(SRSS->unCLK_ECO_STATUS.stcField.u1ECO_OK == 0ul);
        while(SRSS->unCLK_ECO_STATUS.stcField.u1ECO_READY == 0ul);
        #endif
    }

    /***** 2. ILO0 setting ******/
    {
        cy_en_sysclk_status_t ilo0Status;

        Cy_WDT_Unlock();
        ilo0Status = Cy_SysClk_Ilo0Enable();
        Cy_WDT_Lock();
        CY_ASSERT(ilo0Status == CY_SYSCLK_SUCCESS);
    }

    /***** 3. ILO1 setting ******/
    {
        Cy_SysClk_Ilo1Enable();
    }

    /***** 4. WCO setting ******/
    {
        cy_en_sysclk_status_t wcoStatus;
        wcoStatus = Cy_SysClk_WcoEnable(WAIT_FOR_STABILIZATION*10);
        CY_ASSERT(wcoStatus == CY_SYSCLK_SUCCESS);
    }

    /***** 5. ECO prescaler setting ******/
    {
        cy_en_sysclk_status_t ecoPreStatus;

        ecoPreStatus = Cy_SysClk_SetEcoPrescale(CLK_FREQ_ECO, 1234567ul);
        CY_ASSERT(ecoPreStatus == CY_SYSCLK_SUCCESS);

        ecoPreStatus = Cy_SysClk_EcoPrescaleEnable(WAIT_FOR_STABILIZATION);
        CY_ASSERT(ecoPreStatus == CY_SYSCLK_SUCCESS);
    }

    /***** 6. FLL(PATH0) source setting ******/
    {
        cy_en_sysclk_status_t fllStatus;
        fllStatus = Cy_SysClk_ClkPathSetSource(FLL_PATH_NO, PATH_SOURCE_CLOCK_IN);
        CY_ASSERT(fllStatus == CY_SYSCLK_SUCCESS);

        fllStatus = Cy_SysClk_FllConfigureStandard(PATH_SOURCE_CLOCK_FREQ, FLL_TARGET_FREQ, CY_SYSCLK_FLLPLL_OUTPUT_AUTO);
        CY_ASSERT(fllStatus == CY_SYSCLK_SUCCESS);

        fllStatus = Cy_SysClk_FllEnable(WAIT_FOR_STABILIZATION);
        CY_ASSERT((fllStatus == CY_SYSCLK_SUCCESS) || (fllStatus == CY_SYSCLK_TIMEOUT));

        SRSS->unCLK_FLL_STATUS.stcField.u1UNLOCK_OCCURRED = 1ul;
        /* Set the FLL bypass mode to 3 */
        SRSS->unCLK_FLL_CONFIG3.stcField.u2BYPASS_SEL = (uint32_t)CY_SYSCLK_FLLPLL_OUTPUT_OUTPUT;

        Cy_SysClk_FllGetConfiguration(&monitorFllConfig);
    }

    /***** 7. PLL400M#0(PATH1) source setting ******/
    {
        cy_en_sysclk_status_t status;
        status = Cy_SysClk_ClkPathSetSource(PLL_400M_0_PATH_NO, PATH_SOURCE_CLOCK_IN);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MConfigure(PLL_400M_0_PATH_NO, &pll400_0_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MEnable(PLL_400M_0_PATH_NO, WAIT_FOR_STABILIZATION);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MGetConfiguration(PLL_400M_0_PATH_NO, &monitorPll400_0_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);
    }

    /***** 8. PLL400M#1(PATH2) source setting ******/
    {
        cy_en_sysclk_status_t status;
        status = Cy_SysClk_ClkPathSetSource(PLL_400M_1_PATH_NO, PATH_SOURCE_CLOCK_IN);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MConfigure(PLL_400M_1_PATH_NO, &pll400_1_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MEnable(PLL_400M_1_PATH_NO, WAIT_FOR_STABILIZATION);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MGetConfiguration(PLL_400M_1_PATH_NO, &monitorPll400_1_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);
    }

    /***** 9. PLL400M#2(PATH3) source setting ******/
    {
        cy_en_sysclk_status_t status;
        status = Cy_SysClk_ClkPathSetSource(PLL_400M_2_PATH_NO, PATH_SOURCE_CLOCK_IN);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MConfigure(PLL_400M_2_PATH_NO, &pll400_2_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MEnable(PLL_400M_2_PATH_NO, WAIT_FOR_STABILIZATION);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MGetConfiguration(PLL_400M_2_PATH_NO, &monitorPll400_2_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);
    }

    /***** 10. PLL400M#3(PATH4) source setting ******/
    {
        cy_en_sysclk_status_t status;
        status = Cy_SysClk_ClkPathSetSource(PLL_400M_3_PATH_NO, PATH_SOURCE_CLOCK_IN);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MConfigure(PLL_400M_3_PATH_NO, &pll400_3_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MEnable(PLL_400M_3_PATH_NO, WAIT_FOR_STABILIZATION);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MGetConfiguration(PLL_400M_3_PATH_NO, &monitorPll400_3_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);
    }

    /***** 11. PLL400M#4(PATH5) source setting ******/
    {
        cy_en_sysclk_status_t status;
        status = Cy_SysClk_ClkPathSetSource(PLL_400M_4_PATH_NO, PATH_SOURCE_CLOCK_IN);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MConfigure(PLL_400M_4_PATH_NO, &pll400_4_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MEnable(PLL_400M_4_PATH_NO, WAIT_FOR_STABILIZATION);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_Pll400MGetConfiguration(PLL_400M_4_PATH_NO, &monitorPll400_4_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);
    }


    /***** 12. PLL200M#0(PATH6) source setting ******/
    {
        cy_en_sysclk_status_t status;
        status = Cy_SysClk_ClkPathSetSource(PLL_200M_0_PATH_NO, PATH_SOURCE_CLOCK_IN);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_PllConfigure(PLL_200M_0_PATH_NO , &pll200_0_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_PllEnable(PLL_200M_0_PATH_NO, WAIT_FOR_STABILIZATION);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_PllGetConfiguration(PLL_200M_0_PATH_NO, &monitorPll200_0_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);
    }

    /***** 11. PLL200M#1(PATH7) source setting ******/
    {
        cy_en_sysclk_status_t status;
        status = Cy_SysClk_ClkPathSetSource(PLL_200M_1_PATH_NO, PATH_SOURCE_CLOCK_IN);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_PllConfigure(PLL_200M_1_PATH_NO , &pll200_1_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_PllEnable(PLL_200M_1_PATH_NO, WAIT_FOR_STABILIZATION);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_PllGetConfiguration(PLL_200M_1_PATH_NO, &monitorPll200_1_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);
    }

    /***** 12. PLL200M#2(PATH8) source setting ******/
    {
        cy_en_sysclk_status_t status;
        status = Cy_SysClk_ClkPathSetSource(PLL_200M_2_PATH_NO, PATH_SOURCE_CLOCK_IN);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_PllConfigure(PLL_200M_2_PATH_NO , &pll200_2_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_PllEnable(PLL_200M_2_PATH_NO, WAIT_FOR_STABILIZATION);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        status = Cy_SysClk_PllGetConfiguration(PLL_200M_2_PATH_NO, &monitorPll200_2_Config);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);
    }

    /***** 13. PATH9 source setting ******/
    {
        cy_en_sysclk_status_t path9Status;
        path9Status = Cy_SysClk_ClkPathSetSource(BYPASSED_PATH_NO, PATH_SOURCE_CLOCK_IN);
        CY_ASSERT(path9Status == CY_SYSCLK_SUCCESS);
    }

    /***** 14. RTC source setting ******/
    {
        Cy_SysClk_ClkBakSetSource(CY_SYSCLK_BAK_IN_ILO);
    }

    /***** 15. CLK LF source setting ******/
    {
        Cy_WDT_Unlock();
        Cy_SysClk_LfClkSetSource(CY_SYSCLK_LFCLK_IN_WCO);
        Cy_WDT_Lock();
    }

    /***** 16. CLK FAST 0 source setting ******/
    {
        Cy_SysClk_Fast0ClkSetDivider(2, 0x10); // divided by 3.5
    }

    /***** 18. CLK FAST 1 source setting ******/
    {
        Cy_SysClk_Fast1ClkSetDivider(2, 0x10); // divided by 3.5
    }

    /***** 19. CLK Peri source setting ******/
    {
        Cy_SysClk_PeriClkSetDivider(1ul); // divided by 2
    }

    /***** 20. CLK SLOW source setting ******/
    {
        Cy_SysClk_SlowClkSetDivider(2ul); // divided by 3
    }


    /***  21. Setting for all clk_hf        ***/
    struct {cy_en_hf_clk_dividers_t targetDivRegVal; cy_en_hf_clk_sources_t source;} clkHfSetting[CY_SYSCLK_HFCLK_NUM] = 
    {
        { .targetDivRegVal = CY_SYSCLK_HFCLK_NO_DIVIDE,   .source = CY_SYSCLK_HFCLK_IN_CLKPATH6 /* PLL5: PLL200#0 */ }, // setting for clk_hf0
        { .targetDivRegVal = CY_SYSCLK_HFCLK_NO_DIVIDE,   .source = CY_SYSCLK_HFCLK_IN_CLKPATH1 /* PLL0: PLL400#0 */ }, // setting for clk_hf1
        { .targetDivRegVal = CY_SYSCLK_HFCLK_NO_DIVIDE,   .source = CY_SYSCLK_HFCLK_IN_CLKPATH7 /* PLL6: PLL200#1 */ }, // setting for clk_hf2
        { .targetDivRegVal = CY_SYSCLK_HFCLK_DIVIDE_BY_2, .source = CY_SYSCLK_HFCLK_IN_CLKPATH6 /* PLL5: PLL200#0 */ }, // setting for clk_hf3
        { .targetDivRegVal = CY_SYSCLK_HFCLK_DIVIDE_BY_4, .source = CY_SYSCLK_HFCLK_IN_CLKPATH6 /* PLL5: PLL200#0 */ }, // setting for clk_hf4
        { .targetDivRegVal = CY_SYSCLK_HFCLK_NO_DIVIDE,   .source = CY_SYSCLK_HFCLK_IN_CLKPATH2 /* PLL1: PLL400#1 */ }, // setting for clk_hf5
        { .targetDivRegVal = CY_SYSCLK_HFCLK_NO_DIVIDE,   .source = CY_SYSCLK_HFCLK_IN_CLKPATH2 /* PLL1: PLL400#1 */ }, // setting for clk_hf6
        { .targetDivRegVal = CY_SYSCLK_HFCLK_NO_DIVIDE,   .source = CY_SYSCLK_HFCLK_IN_CLKPATH2 /* PLL1: PLL400#1 */ }, // setting for clk_hf7
        { .targetDivRegVal = CY_SYSCLK_HFCLK_NO_DIVIDE,   .source = CY_SYSCLK_HFCLK_IN_CLKPATH3 /* PLL2: PLL400#2 */ }, // setting for clk_hf8
        { .targetDivRegVal = CY_SYSCLK_HFCLK_NO_DIVIDE,   .source = CY_SYSCLK_HFCLK_IN_CLKPATH3 /* PLL2: PLL400#2 */ }, // setting for clk_hf9
        { .targetDivRegVal = CY_SYSCLK_HFCLK_NO_DIVIDE,   .source = CY_SYSCLK_HFCLK_IN_CLKPATH4 /* PLL3: PLL400#3 */ }, // setting for clk_hf10
        { .targetDivRegVal = CY_SYSCLK_HFCLK_NO_DIVIDE,   .source = CY_SYSCLK_HFCLK_IN_CLKPATH5 /* PLL4: PLL400#4 */ }, // setting for clk_hf11
        { .targetDivRegVal = CY_SYSCLK_HFCLK_NO_DIVIDE,   .source = CY_SYSCLK_HFCLK_IN_CLKPATH5 /* PLL4: PLL400#4 */ }, // setting for clk_hf12
        { .targetDivRegVal = CY_SYSCLK_HFCLK_NO_DIVIDE,   .source = CY_SYSCLK_HFCLK_IN_CLKPATH9 /* ECO */            }, // setting for clk_hf13
    };

    for(cy_en_hfclk_t i_clkHfNo = CY_SYSCLK_HFCLK_0; i_clkHfNo < CY_SYSCLK_HFCLK_NUM; i_clkHfNo++)
    {
        cy_en_sysclk_status_t clkHf0status;
        clkHf0status = Cy_SysClk_HfClockSetDivider(i_clkHfNo, clkHfSetting[(uint8_t)i_clkHfNo].targetDivRegVal);
        CY_ASSERT(clkHf0status == CY_SYSCLK_SUCCESS);

        clkHf0status = Cy_SysClk_HfClockSetSource(i_clkHfNo, clkHfSetting[i_clkHfNo].source);
        CY_ASSERT(clkHf0status == CY_SYSCLK_SUCCESS);

        clkHf0status = Cy_SysClk_HfClkEnable(i_clkHfNo);
        CY_ASSERT(clkHf0status == CY_SYSCLK_SUCCESS);
    }

    /***  19. Setting for clock timer        ***/
    Cy_SysClk_ClkTimerSetSource(CY_SYSCLK_CLKTIMER_IN_HF0_DIV8);
    Cy_SysClk_ClkTimerSetDivider(3u); // divided by 4
    Cy_SysClk_ClkTimerEnable();

   return;
}

static void MeasureClockFrequency(void)
{
    uint32_t counter1 = (40000); /* should take 0.0025s for measuring */

    if((SRSS->unCLK_ECO_STATUS.stcField.u1ECO_OK == 0ul)    ||
      (SRSS->unCLK_ECO_STATUS.stcField.u1ECO_READY == 0ul))
    {
        return; // ECO need to be ready.
    }

    for(uint32_t mesuredClock_i = 0; mesuredClock_i < NUM_OF_MEASURED_CLOCK; mesuredClock_i++)
    {
        cy_en_sysclk_status_t status;
        status = Cy_SysClk_StartClkMeasurementCounters(CY_SYSCLK_MEAS_CLK_ECO,      /* reference clock */
                                                       counter1,
                                                       clockMeasuredInfo[mesuredClock_i].name);  /* clock to be measured */
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);

        while(Cy_SysClk_ClkMeasurementCountersDone() == 0u);

        status = Cy_SysClk_ClkMeasurementCountersGetFreq(&clockMeasuredInfo[mesuredClock_i].measuredFreq, CLK_FREQ_ECO);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);
 
        /* clear measuring counter */
        status = Cy_SysClk_StartClkMeasurementCounters(CY_SYSCLK_MEAS_CLK_ECO, 
                                                       3,
                                                       CY_SYSCLK_MEAS_CLK_ECO);
        CY_ASSERT(status == CY_SYSCLK_SUCCESS);
        while(Cy_SysClk_ClkMeasurementCountersDone() == 0u);
    }

    return;
}

struct
{
    uint32_t wcoFreq;
    uint32_t refHfClock;
    uint32_t path0SourceFreq;
    uint32_t path1SourceFreq;
    uint32_t path2SourceFreq;
    uint32_t path3SourceFreq;
    uint32_t path4SourceFreq;
    uint32_t path5SourceFreq;
    uint32_t path6SourceFreq;
    uint32_t path7SourceFreq;
    uint32_t path8SourceFreq;
    uint32_t path9SourceFreq;    

    uint32_t path0Freq;
    uint32_t path1Freq;
    uint32_t path2Freq;
    uint32_t path3Freq;
    uint32_t path4Freq;
    uint32_t path5Freq;
    uint32_t path6Freq;
    uint32_t path7Freq;
    uint32_t path8Freq;
    uint32_t path9Freq;    

    uint32_t fllSourceFreq;
    uint32_t pll400M0SourceFreq;
    uint32_t pll400M1SourceFreq;
    uint32_t pll400M2SourceFreq;
    uint32_t pll400M3SourceFreq;
    uint32_t pll400M4SourceFreq;
    uint32_t pll200M0SourceFreq;
    uint32_t pll200M1SourceFreq;
    uint32_t pll200M2SourceFreq;    

    uint32_t fllFreq;
    uint32_t pll400M0Freq;
    uint32_t pll400M1Freq;
    uint32_t pll400M2Freq;
    uint32_t pll400M3Freq;
    uint32_t pll400M4Freq;
    uint32_t pll200M0Freq;
    uint32_t pll200M1Freq;
    uint32_t pll200M2Freq;

    uint32_t hf0ClockFreq;
    uint32_t hf1ClockFreq;
    uint32_t hf2ClockFreq;
    uint32_t hf3ClockFreq;
    uint32_t hf4ClockFreq;
    uint32_t hf5ClockFreq;
    uint32_t hf6ClockFreq;
    uint32_t hf7ClockFreq;
    uint32_t hf8ClockFreq;
    uint32_t hf9ClockFreq;
    uint32_t hf10ClockFreq;
    uint32_t hf11ClockFreq;
    uint32_t hf12ClockFreq;
    uint32_t hf13ClockFreq;    

    uint32_t WDTClockFreq;
    uint32_t ECOPrescaleClockFreq;
    uint32_t LfClockFreq;
    uint32_t MTWDTClockFreq;
    uint32_t TimerClockFreq;
    uint32_t Fast0ClockFreq;
    uint32_t Fast1ClockFreq;
    uint32_t PeriClockFreq;
    uint32_t MemClockFreq;
    uint32_t SlowClockFreq;
    uint32_t CoreClockFreq;
    uint32_t SysticClockFreq;
} reportedClockFreq;

static void RecalucClockFrequencyValues(void)
{
    cy_stc_base_clk_freq_t freqInfo = 
    {
        .clk_imo_freq  = CLK_FREQ_IMO, //CY_CLK_IMO_FREQ_HZ,
        .clk_ext_freq  = 0,
        .clk_eco_freq  = CLK_FREQ_ECO,
        .clk_ilo0_freq = 32768UL,
        .clk_ilo1_freq = 32768UL,
        .clk_wco_freq  = 32768UL,
    };

    CY_ASSERT(Cy_SysClk_InitGetFreqParams(&freqInfo) == CY_SYSCLK_SUCCESS);

    CY_ASSERT(Cy_SysClk_GetWcoFrequency(&reportedClockFreq.wcoFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetRefHfFrequency(&reportedClockFreq.refHfClock) == CY_SYSCLK_SUCCESS);

    CY_ASSERT(Cy_SysClk_GetPathSourceFrequency(0, &reportedClockFreq.path0SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathSourceFrequency(1, &reportedClockFreq.path1SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathSourceFrequency(2, &reportedClockFreq.path2SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathSourceFrequency(3, &reportedClockFreq.path3SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathSourceFrequency(4, &reportedClockFreq.path4SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathSourceFrequency(5, &reportedClockFreq.path5SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathSourceFrequency(6, &reportedClockFreq.path6SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathSourceFrequency(7, &reportedClockFreq.path7SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathSourceFrequency(8, &reportedClockFreq.path8SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathSourceFrequency(9, &reportedClockFreq.path9SourceFreq) == CY_SYSCLK_SUCCESS);
    
    CY_ASSERT(Cy_SysClk_GetPathFrequency(0, &reportedClockFreq.path0Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathFrequency(1, &reportedClockFreq.path1Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathFrequency(2, &reportedClockFreq.path2Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathFrequency(3, &reportedClockFreq.path3Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathFrequency(4, &reportedClockFreq.path4Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathFrequency(5, &reportedClockFreq.path5Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathFrequency(6, &reportedClockFreq.path6Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathFrequency(7, &reportedClockFreq.path7Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathFrequency(8, &reportedClockFreq.path8Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPathFrequency(9, &reportedClockFreq.path9Freq) == CY_SYSCLK_SUCCESS);
    

    CY_ASSERT(Cy_SysClk_GetFllInputFrequency(&reportedClockFreq.fllSourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllInputFrequency(0, &reportedClockFreq.pll400M0SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllInputFrequency(1, &reportedClockFreq.pll400M1SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllInputFrequency(2, &reportedClockFreq.pll400M2SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllInputFrequency(3, &reportedClockFreq.pll400M3SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllInputFrequency(4, &reportedClockFreq.pll400M4SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllInputFrequency(5, &reportedClockFreq.pll200M0SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllInputFrequency(6, &reportedClockFreq.pll200M1SourceFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllInputFrequency(7, &reportedClockFreq.pll200M2SourceFreq) == CY_SYSCLK_SUCCESS);

    CY_ASSERT(Cy_SysClk_GetFllOutputFrequency(&reportedClockFreq.fllFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllOutputFrequency(0, &reportedClockFreq.pll400M0Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllOutputFrequency(1, &reportedClockFreq.pll400M1Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllOutputFrequency(2, &reportedClockFreq.pll400M2Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllOutputFrequency(3, &reportedClockFreq.pll400M3Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllOutputFrequency(4, &reportedClockFreq.pll400M4Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllOutputFrequency(5, &reportedClockFreq.pll200M0Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllOutputFrequency(6, &reportedClockFreq.pll200M1Freq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetPllOutputFrequency(7, &reportedClockFreq.pll200M2Freq) == CY_SYSCLK_SUCCESS);

    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_0,  &reportedClockFreq.hf0ClockFreq)  == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_1,  &reportedClockFreq.hf1ClockFreq)  == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_2,  &reportedClockFreq.hf2ClockFreq)  == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_3,  &reportedClockFreq.hf3ClockFreq)  == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_4,  &reportedClockFreq.hf4ClockFreq)  == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_5,  &reportedClockFreq.hf5ClockFreq)  == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_6,  &reportedClockFreq.hf6ClockFreq)  == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_7,  &reportedClockFreq.hf7ClockFreq)  == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_8,  &reportedClockFreq.hf8ClockFreq)  == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_9,  &reportedClockFreq.hf9ClockFreq)  == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_10, &reportedClockFreq.hf10ClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_11, &reportedClockFreq.hf11ClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_12, &reportedClockFreq.hf12ClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_13, &reportedClockFreq.hf13ClockFreq) == CY_SYSCLK_SUCCESS);    

    CY_ASSERT(Cy_SysClk_GetWDTClkFrequency(&reportedClockFreq.WDTClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetEcoPrescaleFrequency(&reportedClockFreq.ECOPrescaleClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetLfFrequency(&reportedClockFreq.LfClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetMTWDTFrequency(&reportedClockFreq.MTWDTClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetTimerFrequency(&reportedClockFreq.TimerClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetFast0Frequency(&reportedClockFreq.Fast0ClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetFast1Frequency(&reportedClockFreq.Fast1ClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetClkPeriFrequency(&reportedClockFreq.PeriClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetClkMemFrequency(&reportedClockFreq.MemClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetClkSlowFrequency(&reportedClockFreq.SlowClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetCoreFrequency(&reportedClockFreq.CoreClockFreq) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetSystickFrequency(&reportedClockFreq.SysticClockFreq) == CY_SYSCLK_SUCCESS);
}

static void StartSystickUsingECO(void)
{
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
    Cy_SysTick_Init(CY_SYSTICK_CLOCK_SOURCE_CLK_ECO, 1000ul);
    Cy_SysTick_SetCallback(0, ToggleGpio);
    return;
}

static void ToggleGpio(void)
{
    Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
}




/* [] END OF FILE */
