/***************************************************************************//**
* \file cy_sysclk.h
* \version 1.0
*
* Provides an API declaration of the sysclk driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_sysclk System Clock Service (SysClk)
* \{
* The System Clock (SysClk) driver contains the API for configuring system and
* peripheral clocks. Firmware uses the API to configure , enable, or disable
* a clock.
* 
* The Traveo II clock system includes a variety of resources that can vary per
* device, including:
* - Internal clock sources such as internal oscillators
* - External clock sources such as crystal oscillators or a signal on an I/O pin
* - Generated clocks such as an FLL, a PLL, and peripheral clocks
*
* Consult the Technical Reference Manual for your device for details of the 
* clock system.
*
* The API for any given clock contains the functions to manage that clock. These
* functions may include:
* - Enable or Disable
* - Get or Set Source
* - Get or Set Divider
* - Configure
*
* In the API reference for this driver, most clocks have
* a dedicated section, so the information to manage that clock is in one
* place. Use the left navigation menu to locate the desired information.
*
* \section group_sysclk_configuration Configuration Considerations
* There are no general SysClk configuration concerns. 
* Some clocks (for example the PLL) require configuration. For such a clock the
* API typically provides a Configure function to set up the clock. See notes on
* individual function definitions.
* \warning When the device is in the Ultra-Low Power (ULP) mode, the maximum
* frequency of some clocks is reduced. See the device datasheet for details.
*
*
* \section group_sysclk_more_information More Information
*
* See the Clock Component datasheet.
* See also the sysclk chapter of the device technical reference manual (TRM).
*
* \section group_sysclk_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_sysclk_macros           Macros
* \{
* \}
* \defgroup group_sysclk_enums           General Enumerated Types
* \{
*   \defgroup group_sysclk_returns         Function return values
* \}
* \defgroup group_sysclk_eco             External Crystal Oscillator (ECO)
* \{
*   <p>The Traveo II BLE device contains an oscillator to drive an external 
*   crystal. This clock source is built using an oscillator circuit
*   in Traveo II. The circuit employs an external crystal that must be populated on
*   the external crystal pins of the Traveo II. The ECO can be the source clock for
*   any of the clock paths. See \ref group_sysclk_path_src.</p>
*
*   Use Cy_SysClk_EcoConfigure() to configure the ECO. Pass in the required
*   parameters, there is no configuration structure. Use Cy_SysClk_ClkPathSetSource()
*   to specify the clock path source as \ref CY_SYSCLK_CLKPATH_IN_ECO
*
*   \defgroup group_sysclk_eco_funcs       Functions
* \}
* \defgroup group_sysclk_muxes           Input Multiplexers
* \{
*   Configures two multiplexers: a DSI multiplexer and a path multiplexer. The outputs of these multiplexers generally
*   drive the FLL and the PLLs. See CLK_DSI_SELECT registers, DSI_MUX bits, and CLK_PATH_SELECT registers, PATH_MUX
*   bits. Used with functions \ref Cy_SysClk_ClkPathSetSource and \ref Cy_SysClk_ClkPathGetSource.
*   \note Each path multiplexer output is a source for the corresponding FLL/PLL input source multiplexer.
*   \note The PDL driver cannot use the DSI outputs as sources. This must be done through DSI configuration using PSoC Creator.
*   \defgroup group_sysclk_muxes_funcs     Functions
*   \defgroup group_sysclk_muxes_enums     Enumerated Types
* \}
* \defgroup group_sysclk_fll             Frequency Locked Loop (FLL)
* \{
*   <p>The FLL generates a clock output based on the input frequency. Consult 
*   device-specific documentation for the frequency ranges for your device. 
*   The design makes it possible to use a lower
*   frequency source, such as IMO, to generate higher clock frequencies
*   for the rest of the system.</p>
*
*   The FLL is similar in purpose to a PLL but is not equivalent.
*   - They may have different frequency ranges.
*   - The FLL starts up (locks) faster and consumes less current than the PLL.
*   - The FLL accepts a source clock with lower frequency than PLL, such as the WCO (32 KHz). 
*   - The FLL does not lock phase. It is essentially a counter with a
*   current-controlled oscillator (CCO). The counter counts the number of output
*   clock edges in a reference clock period and adjusts the CCO until the
*   expected ratio is achieved (locked). After initial lock, the CCO is
*   adjusted dynamically to keep the ratio within tolerance. The lock tolerance
*   is user-adjustable.
*
*   Firmware configures the FLL using Cy_SysClk_FllConfigure(). Specify the input
*   and output frequencies, and the output mode. See \ref cy_en_fll_pll_output_mode_t
*   for output choices.
*
*   Alternatively, firmware can fill in values for the
*   \ref cy_stc_fll_manual_config_t structure, and call Cy_SysClk_FllManualConfigure().
*   This call provides precise control over the FLL configuration, such as the
*   lock tolerance.
*
* See the Clocking System chapter of the device technical reference manual (TRM).
*
*   \defgroup group_sysclk_fll_funcs       Functions
*   \defgroup group_sysclk_fll_structs     Data Structures
*   \defgroup group_sysclk_fll_enums       Enumerated Types
* \}
* \defgroup group_sysclk_pll             Phase Locked Loop (PLL)
* \{
*   <p>The PLL generates a clock output based on the input frequency. Consult 
*   device-specific documentation for the frequency ranges for your device. The 
*   design makes it possible to use a lower frequency source, such as IMO, to 
*   generate higher clock frequencies for the rest of the system. </p>
*
*   The PLL is similar in purpose to the FLL but is not equivalent.
*   - They may have different frequency ranges.
*   - The PLL starts up more slowly and consumes more current than the FLL.
*   - The PLL requires a higher frequency source clock than PLL. 
*
*   Firmware can configure the PLL using Cy_SysClk_PllConfigure(). Provide
*   configuration values in a filled \ref cy_stc_pll_config_t structure. See
*   \ref cy_en_fll_pll_output_mode_t for output choices.
*
*   Alternatively, firmware can fill in values for the \ref cy_stc_pll_manual_config_t
*   structure, and call Cy_SysClk_PllManualConfigure().
* 
*   See the Clocking System chapter of the device technical reference manual (TRM).
*
*   \defgroup group_sysclk_pll_funcs       Functions
*   \defgroup group_sysclk_pll_structs     Data Structures
* \}
* \defgroup group_sysclk_ilo             Internal Low-Speed Oscillator (ILO)
* \{
*   <p>The ILO operates with no external components and outputs a stable clock at
*   32.768 kHz nominal. The ILO is relatively low power and low
*   accuracy. The ILO is in the backup domain. It is available in all
*   power modes. The ILO can be used as a source for the \ref group_sysclk_clk_lf.</p>
*
*   The ILO is always the source clock for the \ref group_wdt. Therefore:
*   - The WDT must be unlocked when making an ILO function call in the PDL
*   - It is recommended to always have the ILO enabled
*
*   API functions enable or disable the clock. To ensure the ILO remains active
*   in Hibernate mode, and across power-on-reset (POR) or brown out detect (BOD),
*   firmware must call Cy_SysClk_IloHibernateOn() and pass in a Boolean TRUE. 
*
*   This clock can be trimmed. Firmware uses functions described in
*   \ref group_sysclk_calclk to get the current clock frequency before trimming.
*   Then call Cy_SysClk_IloTrim().
*
*   See the Clocking System chapter of the device technical reference manual (TRM).
*
*   \defgroup group_sysclk_ilo_funcs       Functions
* \}
* \defgroup group_sysclk_calclk          Clock Measurement
* \{
*   <p>These functions measure the frequency of a specified clock relative to a
*   reference clock. They are typically called in the following order:</p>
*   1. Specify the measured clock, the count, and the reference clock; then start the counters:
*   Cy_SysClk_StartClkMeasurementCounters();
*   2. Wait for the measurement counter to finish counting:
*   while(Cy_SysClk_ClkMeasurementCountersDone() != CY_RET_FINISHED);
*   3. Get the measured frequency:<br>
*   freq_measure = Cy_SysClk_ClkMeasurementCountersGetFreq();
*
*   \note These functions may also be used as part of a clock trimming
*   process - see the \ref group_sysclk_trim "Clock Trim" section.
*
*   See the Clocking System chapter of the device technical reference manual (TRM).
*
*   \defgroup group_sysclk_calclk_funcs    Functions
*   \defgroup group_sysclk_calclk_enums    Enumerated Types
* \}
* \defgroup group_sysclk_trim            Clock Trim (ILO)
* \{
*   <p>These functions perform a single trim operation on the ILO. The
*   function's parameter is the actual frequency of the clock. To measure the
*   frequency, use the functions described in the \ref group_sysclk_calclk section.</p>
*
*   To trim the clock as close as possible to the target frequency, multiple
*   calls to the trim function may be needed. A typical usage example is to:
*   1. Call the clock measurement functions to get the actual frequency of the clock
*   2. Call the trim function, passing in the measured frequency:
*   Cy_SysClk_IloTrim()
*   3. Repeat the above until the trim function reports trimming is done.
*
*   See the Clocking System chapter of the device technical reference manual (TRM).
*
*   \defgroup group_sysclk_trim_funcs      Functions
* \}
* \defgroup group_sysclk_pm              Power Management
* \{
*   The PDL provides a callback function that firmware can use to handle
*   transition to DeepSleep mode: Cy_SysClk_DeepSleepCallback().
*   
*   Firmware can configure the system to call this function during execution of
*   Cy_SysPm_DeepSleep(). To do so, register this function as a callback before
*   calling Cy_SysPm_DeepSleep(). Specify \ref CY_SYSPM_DEEPSLEEP as the callback type,
*   and call Cy_SysPm_RegisterCallback().
*   
*   \note If the FLL or PLL source is the ECO, this function must be registered,
*   and it must be the last callback function that is registered.
*   
*   See the Clocking System chapter of the device technical reference manual (TRM).
*
*   \defgroup group_sysclk_pm_funcs        Functions
* \}
* \defgroup group_sysclk_wco             Watch Crystal Oscillator (WCO)
* \{
*   <p>The WCO is a highly accurate 32.768-kHz clock source. It is the primary
*   clock source for the real-time clock (RTC). The WCO can be used as a
*   source for the low-frequency clock. A design can bypass the WCO. If so,
*   an external 32 KHz clock must be provided on the WCO_OUT pin.</p>
*
*   The WCO has a built-in clock supervisor (CSV). The supervisor detects if
*   the WCO has been lost; that is, the WCO is no longer producing clock
*   pulses. The CSV does this by checking to ensure there is at least one WCO
*   clock pulse within a certain time window. The ILO can be the
*   supervising clock. Firmware can configure the CSV to trigger a fault,
*   a reset, or a fault after four cycles of the supervising clock.
*
*   To configure the CSV, fill in the values of a \ref cy_stc_wco_csv_config_t
*   structure and call Cy_SysClk_WcoConfigureCsv(). This structure specifies
*   the supervising clock, that the CSV is enabled, the time window, and the
*   action on error.
*
*   See the Clocking System chapter of the device technical reference manual (TRM).
*
*   \defgroup group_sysclk_wco_funcs       Functions
*   \defgroup group_sysclk_wco_structs     Data Structures
*   \defgroup group_sysclk_wco_enums       Enumerated Types
* \}
* \defgroup group_sysclk_clk_hf          High-Frequency Clocks
* \{
*   \defgroup group_sysclk_clk_hf_funcs    Functions
*   \defgroup group_sysclk_clk_hf_structs  Data Structures
*   \defgroup group_sysclk_clk_hf_enums    Enumerated Types
* \}
* \defgroup group_sysclk_clk_fast        Fast Clock
* \{
*   <p>The fast clock drives the Cortex-M4 processor. This clock is a divided
*   version of CLK_HF[0]. See \ref group_sysclk_clk_hf "HF Clocks".
*
*   The API functions for this clock set or get the divider.
*
*   See the Clocking System chapter of the device technical reference manual (TRM).
*
*   \defgroup group_sysclk_clk_fast_funcs  Functions
* \}
* \defgroup group_sysclk_clk_peri        Peripheral Clock
* \{
*   <p>The peripheral clock is a divided clock of CLK_HF0. See
*   \ref group_sysclk_clk_hf "HF Clocks". It is the source clock for the
*   \ref group_sysclk_clk_slow, and multiple peripheral clocks. See
*   \ref group_sysclk_clk_peripheral.</p>
*
*   The API functions for this clock set or get the divider. 
*
*   ![](sysclk_peri.png)
*
*   See the Clocking System chapter of the device technical reference manual (TRM).
*
*   \defgroup group_sysclk_clk_peri_funcs  Functions
* \}
* \defgroup group_sysclk_clk_peripheral  Peripherals Clock Dividers
* \{
*   \defgroup group_sysclk_clk_peripheral_funcs Functions
*   \defgroup group_sysclk_clk_peripheral_enums Enumerated Types
* \}
* \defgroup group_sysclk_clk_slow        Slow Clock
* \{
*   <p>The slow clock is the source clock for the Cortex-M0+. This clock is a
*   divided version of the \ref group_sysclk_clk_peri, which in turn is a divided version
*   of CLK_HF[0]. See \ref group_sysclk_clk_hf "HF Clocks".</p>
*
*   The API functions for this clock set or get the divider.
*
*   See the Clocking System chapter of the device technical reference manual (TRM).
*
*   \defgroup group_sysclk_clk_slow_funcs  Functions
* \}
* \defgroup group_sysclk_clk_lf          Low-Frequency Clock
* \{
*   <p>The low-frequency clock is the source clock for the \ref group_mcwdt
*   and can be the source clock for \ref group_sysclk_clk_bak, which drives the
*   \ref group_rtc.</p>
*   
*   The low-frequency clock has three possible source clocks:
*   \ref group_sysclk_ilo "ILO" and
*   \ref group_sysclk_wco "WCO".
*   
*   The API functions for this clock set or get the source clock.
*
*   See the Clocking System chapter of the device technical reference manual (TRM).
*
*   \defgroup group_sysclk_clk_lf_funcs    Functions
*   \defgroup group_sysclk_clk_lf_enums    Enumerated Types
* \}
* \defgroup group_sysclk_clk_timer       Timer Clock
* \{
*   <p>The timer clock can be the source clock for the \ref group_arm_system_timer
*   (Cy_SysTick_SetClockSource()). It can also be used as a reference clock for
*   a counter in the \ref group_energy_profiler "Profile" (Cy_Profile_ConfigureCounter()).</p>
*   
*   The timer clock is a divided clock of either IMO or CLK_HF[0]. See
*   \ref group_sysclk_clk_hf "HF Clocks".
*   
*   API functions for this clock set or get the source, set or get the divider,
*   and enable or disable the clock.
*   
*   See the Clocking System chapter of the device technical reference manual (TRM).
*
*   \defgroup group_sysclk_clk_timer_funcs Functions
*   \defgroup group_sysclk_clk_timer_enums Enumerated Types
* \}
* \defgroup group_sysclk_clk_pump        Pump Clock
* \{
*   The pump clock may be required to drive the internal voltage pump for the
*   Continuous Time Block mini (CTBm) in the analog subsystem.
*   
*   The pump clock is a divided clock of one of the clock paths. See
*   \ref group_sysclk_path_src.
*   
*   API functions for this clock set or get the source, set or get the divider,
*   and enable or disable the clock.
*   
*   See the Clocking System chapter of the device technical reference manual
*   (TRM) and the Continuous Time Block mini chapter of the TRM.
*
*   \defgroup group_sysclk_clk_pump_funcs  Functions
*   \defgroup group_sysclk_clk_pump_enums  Enumerated Types
* \}
* \defgroup group_sysclk_clk_bak         Backup Domain Clock
* \{
*   The backup domain clock drives the \ref group_rtc. 
*   
*   The backup domain clock has two possible source clocks: \ref group_sysclk_wco "WCO"
*   or the \ref group_sysclk_clk_lf. In turn the low frequency clock is sourced by
*   \ref group_sysclk_ilo "ILO" or
*   \ref group_sysclk_wco "WCO". Typically ILO is not suitable as an RTC source,
*   because of its low accuracy.
*   
*   The API functions for this clock set or get the source clock. 
*   
*   See the Clocking System chapter of the device technical reference manual (TRM).
*
*   \defgroup group_sysclk_clk_bak_funcs   Functions
*   \defgroup group_sysclk_clk_bak_enums   Enumerated Types
* \}
* \defgroup group_sysclk_reculc_freq         Recalculation
* \{
*
*   \defgroup group_sysclk_reculc_freq_funcs   Functions
*   \defgroup group_sysclk_reculc_freq_enums   Enumerated Types
* \}
*/

#if !defined(__CY_SYSCLK_H__)
#define __CY_SYSCLK_H__

#include "cy_device_headers.h"
#include "syslib/cy_syslib.h"
#include "syspm/cy_syspm.h"
#include "systick/cy_systick.h"
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/** *******************************************************************/

/**
* \addtogroup group_sysclk_macros
* \{
*/
/** Driver major version */
#define  CY_SYSCLK_DRV_VERSION_MAJOR   1
/** Driver minor version */
#define  CY_SYSCLK_DRV_VERSION_MINOR   0
/** \} group_sysclk_macros */

/**
* \addtogroup group_sysclk_returns
* \{
*/
/** Defines general-purpose function return values. */
typedef enum
{
    CY_SYSCLK_SUCCESS       = 0u, /**< Command completed with no errors */
    CY_SYSCLK_BAD_PARAM     = 1u, /**< Invalid function input parameter */
    CY_SYSCLK_TIMEOUT       = 2u, /**< Timeout occurred */
    CY_SYSCLK_INVALID_STATE = 3u  /**< Clock is in an invalid state */
} cy_en_sysclk_status_t;
/** \} group_sysclk_returns */

/** \cond INTERNAL */
/* Generates shorter code for setting register bitfields */
#define CY_SYSCLK_CLR_SET(reg, field, value) (reg) = _CLR_SET_FLD32U((reg), field, (value))
/* Calculate a / b with rounding to the nearest integer. a and b must have the same sign. */
#define CY_SYSCLK_DIV_ROUND(a, b) (((a) + ((b) / 2ull)) / (b))
/* Calculate a / b with rounding up if remainder != 0. a and b must both be positive. */
#define CY_SYSCLK_DIV_ROUNDUP(a, b) ((((a) - 1u) / (b)) + 1u)
/** \endcond */

#define CY_SYSCLK_INVALID_TRIM_VALUE (0xFFFFFFFFul)

/* ========================================================================== */
/* ===========================    ECO SECTION    ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_eco_funcs
* \{
*/

typedef enum
{
    CY_SYSCLK_ECO_PRESCALE_DISABLE = 0u,
    CY_SYSCLK_ECO_PRESCALE_ENABLE  = 1u,
} cy_en_eco_prescale_enable_t;

cy_en_sysclk_status_t Cy_SysClk_EcoConfigure(uint32_t freq, uint32_t cLoad, uint32_t esr, uint32_t driveLevel);
cy_en_sysclk_status_t Cy_SysClk_EcoEnable(uint32_t timeoutus);
cy_en_sysclk_status_t Cy_SysClk_EcoPrescaleEnable(uint32_t timeoutus);
cy_en_sysclk_status_t Cy_SysClk_EcoPrescaleDisable(uint32_t timeoutus);
cy_en_sysclk_status_t Cy_SysClk_SetEcoPrescale(uint32_t ecoFreq, uint32_t targetFreq);
__STATIC_INLINE void Cy_SysClk_EcoDisable(void);
__STATIC_INLINE uint32_t Cy_SysClk_EcoGetStatus(void);

/*******************************************************************************
* Function Name: Cy_SysClk_SelectEcoAtrim
****************************************************************************//**
*
*   In accordance with the table below, this function Outputs proper
*   value for ATRIM bits in register CLK_ECO_CONFIG2.
*   max amplitude (Vp) |   ATRIM value
*      0.30[V] <= Vp < 0.35[V]    |      0x00
*      0.35[V] <= Vp < 0.40[V]    |      0x01
*      0.40[V] <= Vp < 0.45[V]    |      0x02
*      0.45[V] <= Vp < 0.45[V]    |      0x03
*      0.50[V] <= Vp < 0.55[V]    |      0x04
*      0.55[V] <= Vp < 0.55[V]    |      0x05
*      0.60[V] <= Vp < 0.65[V]    |      0x06
*      0.65[V] <= Vp < 0.65[V]    |      0x07
*      0.70[V] <= Vp < 0.75[V]    |      0x08
*      0.75[V] <= Vp < 0.75[V]    |      0x09
*      0.80[V] <= Vp < 0.85[V]    |      0x0A
*      0.85[V] <= Vp < 0.75[V]    |      0x0B
*      0.90[V] <= Vp < 0.95[V]    |      0x0C
*      0.95[V] <= Vp < 1.00[V]    |      0x0D
*      1.00[V] <= Vp < 1.05[V]    |      0x0E
*      1.05[V] <= Vp < 1.10[V]    |      0x0F
*      1.10[V] <= Vp              |      0x00
*
*   \param maxAmplitude: Max amplitude (Vp) calculated by below formula.
*         Vpp = 1,000 * sqrt(drivelevel / 2 / esr) / 3.14 / freqMHz / cLoad
*
*   \return : value to be set to ATRIM.
*             It returns 0xFFFFFFFF, when there are no proper value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_SelectEcoAtrim(float32_t maxAmplitude)
{
    if((0.3f <= maxAmplitude) && (maxAmplitude < 0.35f))
    {
        return(0x00ul);
    }
    else if(maxAmplitude < 0.40f)
    {
        return(0x01ul);
    }
    else if(maxAmplitude < 0.45f)
    {
        return(0x02ul);
    }
    else if(maxAmplitude < 0.50f)
    {
        return(0x03ul);
    }
    else if(maxAmplitude < 0.55f)
    {
        return(0x04ul);
    }
    else if(maxAmplitude < 0.60f)
    {
        return(0x05ul);
    }
    else if(maxAmplitude < 0.65f)
    {
        return(0x06ul);
    }
    else if(maxAmplitude < 0.70f)
    {
        return(0x07ul);
    }
    else if(maxAmplitude < 0.75f)
    {
        return(0x08ul);
    }
    else if(maxAmplitude < 0.80f)
    {
        return(0x09ul);
    }
    else if(maxAmplitude < 0.85f)
    {
        return(0x0Aul);
    }
    else if(maxAmplitude < 0.90f)
    {
        return(0x0Bul);
    }
    else if(maxAmplitude < 0.95f)
    {
        return(0x0Cul);
    }
    else if(maxAmplitude < 1.00f)
    {
        return(0x0Dul);
    }
    else if(maxAmplitude < 1.05f)
    {
        return(0x0Eul);
    }
    else if(maxAmplitude < 1.10f)
    {
        return(0x0Ful);
    }
    else if(1.1f <= maxAmplitude)
    {
        return(0x00ul);
    }
    else
    {
        // invalid input
        return(CY_SYSCLK_INVALID_TRIM_VALUE);
    }
}

/*******************************************************************************
* Function Name: Cy_SysClk_SelectEcoWDtrim
****************************************************************************//**
*
*   In accordance with the table below, this function Outputs proper
*   value for WDTRIM bits in register CLK_ECO_CONFIG2.
*   max amplitude (Vp) |   WDTRIM value
*      0.3[V] <= Vp <  0.4[V]    |      0x00
*      0.4[V] <= Vp <  0.5[V]    |      0x01
*      0.5[V] <= Vp <  0.6[V]    |      0x02
*      0.6[V] <= Vp <  0.7[V]    |      0x03
*      0.7[V] <= Vp <  0.8[V]    |      0x04
*      0.8[V] <= Vp <  0.9[V]    |      0x05
*      0.9[V] <= Vp <  1.0[V]    |      0x06
*      1.0[V] <= Vp <  1.1[V]    |      0x07
*
*   \param maxAmplitude: Max amplitude (Vp) calculated by below formula.
*         Vp = 1,000 * sqrt(drivelevel / 2 / esr) / 3.14 / freqMHz / cLoad
*
*   \return : value to be set to WDTRIM.
*             It returns CY_SYSCLK_INVALID_TRIM_VALUE, when there are no proper value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_SelectEcoWDtrim(float32_t amplitude)
{
    if( (0.3f <= amplitude) && (amplitude < 0.4f))
    {
        return(0x00ul);
    }
    else if(amplitude < 0.5f)
    {
        return(0x01ul);
    }
    else if(amplitude < 0.6f)
    {
        return(0x02ul);
    }
    else if(amplitude < 0.7f)
    {
        return(0x03ul);
    }
    else if(amplitude < 0.8f)
    {
        return(0x04ul);
    }
    else if(amplitude < 0.9f)
    {
        return(0x05ul);
    }
    else if(amplitude < 1.0f)
    {
        return(0x06ul);
    }
    else if(amplitude < 1.1f)
    {
        return(0x07ul);
    }
    else
    {
        // invalid input
        return(CY_SYSCLK_INVALID_TRIM_VALUE);
    }
}

/*******************************************************************************
* Function Name: Cy_SysClk_SelectEcoGtrim
****************************************************************************//**
*
*   In accordance with the table below, this function Outputs proper
*   value for GTRIM bits in register CLK_ECO_CONFIG2.
*   minimum gm  (gm_min)  |   GTRIM value
*    0.0[mA/V] <= gm_min < 2.2[mA/V]  |      0x00
*    2.2[mA/V] <= gm_min < 4.4[mA/V]  |      0x01
*    4.4[mA/V] <= gm_min < 6.6[mA/V]  |      0x02
*    6.6[mA/V] <= gm_min < 8.8[mA/V]  |      0x03
*    8.8[mA/V] <= gm_min <11.0[mA/V]  |      0x04
*   11.0[mA/V] <= gm_min <13.2[mA/V]  |      0x05
*   13.2[mA/V] <= gm_min <15.4[mA/V]  |      0x06
*   15.4[mA/V] <= gm_min <17.6[mA/V]  |      0x07
*
*   \param gm_min: Minimum of gm (gm_min) calculated by below formula.
*   gm_min mA/V = 5 * 4 * 3.14 * 3.14 * freqMhz^2 * cLoad^2 * 4 * esr / 1,000,000,000
*
*   \return : value to be set to GTRIM.
*             It returns CY_SYSCLK_INVALID_TRIM_VALUE, when there are no proper value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_SelectEcoGtrim(float32_t gm_min)
{
    if( (0.0f <= gm_min) && (gm_min < 2.2f))
    {
        return(0x00ul);
    }
    else if(gm_min < 4.4f)
    {
        return(0x01ul);
    }
    else if(gm_min < 6.6f)
    {
        return(0x02ul);
    }
    else if(gm_min < 8.8f)
    {
        return(0x03ul);
    }
    else if(gm_min < 11.0f)
    {
        return(0x04ul);
    }
    else if(gm_min < 13.2f)
    {
        return(0x05ul);
    }
    else if(gm_min < 15.4f)
    {
        return(0x06ul);
    }
    else if(gm_min < 17.6)
    {
        return(0x07ul);
    }
    else
    {
        // invalid input
        return(CY_SYSCLK_INVALID_TRIM_VALUE);
    }
}

/*******************************************************************************
* Function Name: Cy_SysClk_SelectEcoRtrim
****************************************************************************//**
*
*   In accordance with the table below, this function Outputs proper
*   value for RTRIM bits in register CLK_ECO_CONFIG2.
*         Eco freq  (F)            |   RTRIM value
*                  F > 28.60[MHz]  |      0x00
*    28.60[MHz] >= F > 23.33[MHz]  |      0x01
*    23.33[MHz] >= F > 16.50[MHz]  |      0x02
*    16.50[MHz] >= F               |      0x03
*
*   \param freqMHz: Operating frequency of the crystal in MHz.
*
*   \return : value to be set to RTRIM.
*             It returns CY_SYSCLK_INVALID_TRIM_VALUE, when there are no proper value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_SelectEcoRtrim(float32_t freqMHz)
{
    if(freqMHz > 28.6f)
    {
        return(0x00ul);
    }
    else if(freqMHz > 23.33f)
    {
        return(0x01ul);
    }
    else if(freqMHz > 16.5f)
    {
        return(0x02ul);
    }
    else if(freqMHz > 0.0f)
    {
        return(0x03ul);
    }
    else
    {
        // invalid input
        return(CY_SYSCLK_INVALID_TRIM_VALUE);
    }
}

/*******************************************************************************
* Function Name: Cy_SysClk_SelectEcoFtrim
****************************************************************************//**
*
*   In accordance with the table below, this function Outputs proper
*   value for FTRIM bits in register CLK_ECO_CONFIG2.
*     ATRIM value     |   FTRIM value
*         ATRIM <  4  |      0x00
*    4 <= ATRIM <  8  |      0x01
*    8 <= ATRIM < 12  |      0x02
*   12 <= ATRIM       |      0x03
*
*   \param atrim: value of ATRIM to be set.
*
*   \return : value to be set to FTRIM.
*
*   \note: This function does not check the invalid input value.
*          It should be cared by caller program.
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_SelectEcoFtrim(uint32_t atrim)
{
    if(atrim < 4ul)
    {
        return(0x00ul);
    }
    else if(atrim < 8ul)
    {
        return(0x01ul);
    }
    else if(atrim < 12ul)
    {
        return(0x02ul);
    }
    else
    {
        return(0x03ul);
    }
}

/*******************************************************************************
* Function Name: Cy_SysClk_EcoDisable
****************************************************************************//**
*
* Disables the external crystal oscillator (ECO). This function should not be
* called if the ECO is sourcing clk_hf[0].
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_EcoDisable(void)
{
    SRSS->unCLK_ECO_CONFIG.stcField.u1ECO_EN = 0ul; /* 0 = disable */
}

/*******************************************************************************
* Function Name: Cy_SysClk_EcoGetStatus
****************************************************************************//**
*
* Reports the current status of the external crystal oscillator (ECO).
*
* \return
* 0 = ECO does not have sufficient amplitude<br>
* 1 = ECO has sufficient amplitude but may not be meeting accuracy and duty cycle specifications<br>
* 2 = ECO has fully stabilized
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_EcoGetStatus(void)
{
    /* if ECO is not ready, just report the ECO_OK bit. Otherwise report 2 = ECO ready */
    if(SRSS->unCLK_ECO_STATUS.stcField.u1ECO_READY != 1ul)
    {
        return SRSS->unCLK_ECO_STATUS.stcField.u1ECO_OK;
    }
    else
    {
        return 2ul;
    }
}

/*******************************************************************************
* Function Name: Cy_SysClk_GetEcoPrescaleStatus
****************************************************************************//**
*
* Get ECO prescaler status
*
* \return \cy_en_eco_prescale_enable_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_eco_prescale_enable_t Cy_SysClk_GetEcoPrescaleStatus(void)
{
    return (cy_en_eco_prescale_enable_t)(SRSS->unCLK_ECO_PRESCALE.stcField.u1ECO_DIV_ENABLED);
}

/*******************************************************************************
* Function Name: Cy_SysClk_SetEcoPrescaleManual
****************************************************************************//**
*
* Set divider num according to input parameters
*
* \param divInt integer portion of divider number
*
* \param divFract fractional portion of divider number
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_SetEcoPrescaleManual(uint16_t divInt, uint8_t divFract)
{
    un_CLK_ECO_PRESCALE_t tempRegEcoPrescale;
    tempRegEcoPrescale.u32Register             = SRSS->unCLK_ECO_PRESCALE.u32Register;
    tempRegEcoPrescale.stcField.u10ECO_INT_DIV = divInt;
    tempRegEcoPrescale.stcField.u8ECO_FRAC_DIV = divFract;
    SRSS->unCLK_ECO_PRESCALE.u32Register       = tempRegEcoPrescale.u32Register;

    return;
}

/** \} group_sysclk_eco_funcs */


/* ========================================================================== */
/* ====================    INPUT MULTIPLEXER SECTION    ===================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_muxes_enums
* \{
*/
/**
*   Input multiplexer clock sources
*/
#define CY_SYSCLK_CLKPATH_MSK     0x0000001Ful
typedef enum
{
    CY_SYSCLK_CLKPATH_IN_IMO    =     0u, /**< Select the IMO as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_EXT    =     1u, /**< Select the EXT as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_ECO    =     2u, /**< Select the ECO as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_DSIMUX =     4u, /**< Select the DSI MUX output as the output of the path mux */
#if defined(SRSS_BACKUP_S40E_LPECO_PRESENT) && (SRSS_BACKUP_S40E_LPECO_PRESENT == 1)
    CY_SYSCLK_CLKPATH_IN_LPECO  =     5u, /**< Select the LPECO as the output of the path mux */
#endif
    CY_SYSCLK_CLKPATH_IN_DSI0   = 0x100u, /**< Select a DSI signal 0 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI1   = 0x101u, /**< Select a DSI signal 1 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI2   = 0x102u, /**< Select a DSI signal 2 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI3   = 0x103u, /**< Select a DSI signal 3 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI4   = 0x104u, /**< Select a DSI signal 4 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI5   = 0x105u, /**< Select a DSI signal 5 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI6   = 0x106u, /**< Select a DSI signal 6 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI7   = 0x107u, /**< Select a DSI signal 7 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI8   = 0x108u, /**< Select a DSI signal 8 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI9   = 0x109u, /**< Select a DSI signal 9 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI10  = 0x10Au, /**< Select a DSI signal 10 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI11  = 0x10Bu, /**< Select a DSI signal 11 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI12  = 0x10Cu, /**< Select a DSI signal 12 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI13  = 0x10Du, /**< Select a DSI signal 13 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI14  = 0x10Eu, /**< Select a DSI signal 14 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_DSI15  = 0x10Fu, /**< Select a DSI signal 15 as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_ILO0   = 0x110u, /**< Select the ILO0 (16) as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_WCO    = 0x111u, /**< Select the WCO (17) as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_ILO1   = 0x114u  /**< Select the ILO1 (20) as the output of the DSI mux and path mux */
} cy_en_clkpath_in_sources_t;
/** \} group_sysclk_muxes_enums */

/**
* \addtogroup group_sysclk_muxes_funcs
* \{
*/
cy_en_sysclk_status_t Cy_SysClk_ClkPathSetSource(uint32_t clkPath, cy_en_clkpath_in_sources_t source);
cy_en_clkpath_in_sources_t Cy_SysClk_ClkPathGetSource(uint32_t clkPath);
/** \} group_sysclk_muxes_funcs */


/* ========================================================================== */
/* ===========================    FLL SECTION    ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_fll_enums
* \{
*/
/** FLL and PLL output mode.
* See registers CLK_FLL_CONFIG3 and CLK_PLL_CONFIG0, bits BYPASS_SEL.
*/
typedef enum
{
    CY_SYSCLK_FLLPLL_OUTPUT_AUTO              = 0u, /**< Output FLL/PLL input source when not locked, and FLL/PLL output when locked. */
    CY_SYSCLK_FLLPLL_OUTPUT_LOCKED_OR_NOTHING = 1u, /**< Similar to AUTO, except the clock is gated off when unlocked */
    CY_SYSCLK_FLLPLL_OUTPUT_INPUT             = 2u, /**< Output FLL/PLL input source regardless of lock status. */
    CY_SYSCLK_FLLPLL_OUTPUT_OUTPUT            = 3u  /**< Output FLL/PLL output regardless of lock status. This can be dangerous if used to clock hf_clk because FLL/PLL output may be unstable. */
} cy_en_fll_pll_output_mode_t;

/** FLL current-controlled oscillator (CCO) frequency ranges.
* See register CLK_FLL_CONFIG4, bits CCO_RANGE.
*/
typedef enum
{
    CY_SYSCLK_FLL_CCO_RANGE0                 = 0u, /**< Target frequency is in range  48 -  64 MHz. */
    CY_SYSCLK_FLL_CCO_RANGE1                 = 1u, /**< Target frequency is in range  64 -  85 MHz. */
    CY_SYSCLK_FLL_CCO_RANGE2                 = 2u, /**< Target frequency is in range  85 - 113 MHz. */
    CY_SYSCLK_FLL_CCO_RANGE3                 = 3u, /**< Target frequency is in range 113 - 150 MHz. */
    CY_SYSCLK_FLL_CCO_RANGE4                 = 4u,  /**< Target frequency is in range 150 - 200 MHz. */
} cy_en_fll_cco_ranges_t;
/** \} group_sysclk_fll_enums */

#define  CY_SYSCLK_FLL_CCO_BOUNDARY1_FREQ   (63855600ul)
#define  CY_SYSCLK_FLL_CCO_BOUNDARY2_FREQ   (88494870ul)
#define  CY_SYSCLK_FLL_CCO_BOUNDARY3_FREQ  (113009380ul)
#define  CY_SYSCLK_FLL_CCO_BOUNDARY4_FREQ  (150339200ul)

/**
* \addtogroup group_sysclk_fll_structs
* \{
*/
/** Structure containing information for manual configuration of FLL.
*/
typedef struct
{
    uint32_t                    fllMult;            /**< CLK_FLL_CONFIG  register, FLL_MULT bits */
    uint16_t                    refDiv;             /**< CLK_FLL_CONFIG2 register, FLL_REF_DIV bits */
    cy_en_fll_cco_ranges_t      ccoRange;           /**< CLK_FLL_CONFIG4 register, CCO_RANGE bits */
    bool                        enableOutputDiv;    /**< CLK_FLL_CONFIG  register, FLL_OUTPUT_DIV bit */
    uint16_t                    lockTolerance;      /**< CLK_FLL_CONFIG2 register, LOCK_TOL bits */
    uint16_t                    updateTolerance;    /**< CLK_FLL_CONFIG2 register, UPDATE_TOL bits */
    uint8_t                     igain;              /**< CLK_FLL_CONFIG3 register, FLL_LF_IGAIN bits */
    uint8_t                     pgain;              /**< CLK_FLL_CONFIG3 register, FLL_LF_PGAIN bits */
    uint16_t                    settlingCount;      /**< CLK_FLL_CONFIG3 register, SETTLING_COUNT bits */
    cy_en_fll_pll_output_mode_t outputMode;         /**< CLK_FLL_CONFIG3 register, BYPASS_SEL bits */
    uint16_t                    cco_Freq;           /**< CLK_FLL_CONFIG4 register, CCO_FREQ bits */
    uint8_t                     ccoHwUpdateDisable; /**< CLK_FLL_CONFIG4 register, CCO_HW_UPDATE_DIS bits */
} cy_stc_fll_manual_config_t;
/** \} group_sysclk_fll_structs */

/**
* \addtogroup group_sysclk_fll_funcs
* \{
*/
cy_en_sysclk_status_t Cy_SysClk_FllConfigureStandard(uint32_t inputFreq, uint32_t outputFreq, cy_en_fll_pll_output_mode_t outputMode);
cy_en_sysclk_status_t Cy_SysClk_FllManualConfigure(const cy_stc_fll_manual_config_t *config);
void Cy_SysClk_FllGetConfiguration(cy_stc_fll_manual_config_t *config);
cy_en_sysclk_status_t Cy_SysClk_FllEnable(uint32_t timeoutus);
cy_en_sysclk_status_t Cy_SysClk_FllDisableSequence(uint32_t waitCycle);
__STATIC_INLINE bool Cy_SysClk_FllGetLockStatus(void);
__STATIC_INLINE bool Cy_SysClk_FllLostLock(void);
__STATIC_INLINE void Cy_SysClk_FllDisable(void);

/*******************************************************************************
* Function Name: Cy_SysClk_FllGetLockStatus
****************************************************************************//**
*
* Returns lock status of the FLL
*
* \return 0 = not locked, 1 = locked
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_FllGetLockStatus(void)
{
    return (bool)(SRSS->unCLK_FLL_STATUS.stcField.u1LOCKED);
}

/*******************************************************************************
* Function Name: Cy_SysClk_FllLostLock
****************************************************************************//**
*
* Reports whether or not the FLL lost its lock since the last time this function
* was called. Clears the lost lock indicator.
*
* \return 0 = didn't lose lock, 1 = lost lock
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_FllLostLock(void)
{
    uint32_t retval = SRSS->unCLK_FLL_STATUS.stcField.u1UNLOCK_OCCURRED;
    /* write a 1 to clear the unlock occurred bit */
    SRSS->unCLK_FLL_STATUS.stcField.u1UNLOCK_OCCURRED = 1ul;
    return ((bool)retval);
}

/*******************************************************************************
* Function Name: Cy_SysClk_FllDisable
****************************************************************************//**
*
* Disables the FLL and the CCO.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_FllDisable(void)
{
    SRSS->unCLK_FLL_CONFIG.stcField.u1FLL_ENABLE = 0ul; /* 0 = disable */
    SRSS->unCLK_FLL_CONFIG4.stcField.u1CCO_ENABLE = 0ul; /* 0 = disable */
}
/** \} group_sysclk_fll_funcs */


/* ========================================================================== */
/* ===========================    PLL SECTION    ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_pll_structs
* \{
*/
/** Structure containing information for configuration of a PLL.
*/
typedef struct
{
    uint32_t                    inputFreq;  /**< frequency of PLL source, in Hz */
    uint32_t                    outputFreq; /**< frequency of PLL output, in Hz */
    bool                        lfMode;     /**< CLK_PLL_CONFIG register, PLL_LF_MODE bit */
    cy_en_fll_pll_output_mode_t outputMode; /**< CLK_PLL_CONFIG register, BYPASS_SEL bits */
} cy_stc_pll_config_t;

/** Structure containing information for manual configuration of a PLL.
*/
typedef struct
{
    uint32_t                    feedbackDiv;  /**< CLK_PLL_CONFIG register, FEEDBACK_DIV (P) bits */
    uint32_t                    referenceDiv; /**< CLK_PLL_CONFIG register, REFERENCE_DIV (Q) bits */
    uint32_t                    outputDiv;    /**< CLK_PLL_CONFIG register, OUTPUT_DIV bits */
    bool                        lfMode;       /**< CLK_PLL_CONFIG register, PLL_LF_MODE bit */
    cy_en_fll_pll_output_mode_t outputMode;   /**< CLK_PLL_CONFIG register, BYPASS_SEL bits */
} cy_stc_pll_manual_config_t;
/** \} group_sysclk_pll_structs */

/**
* \addtogroup group_sysclk_pll_funcs
* \{
*/
cy_en_sysclk_status_t Cy_SysClk_PllConfigure(uint32_t clkPath, const cy_stc_pll_config_t *config);
cy_en_sysclk_status_t Cy_SysClk_PllManualConfigure(uint32_t clkPath, const cy_stc_pll_manual_config_t *config);
cy_en_sysclk_status_t Cy_SysClk_PllGetConfiguration(uint32_t clkPath, cy_stc_pll_manual_config_t *config);
cy_en_sysclk_status_t Cy_SysClk_PllEnable(uint32_t clkPath, uint32_t timeoutus);
__STATIC_INLINE uint8_t Cy_SysClk_PllGetLockStatus(uint32_t clkPath);
__STATIC_INLINE uint8_t Cy_SysClk_PllLostLock(uint32_t clkPath);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PllDisable(uint32_t clkPath);

/*******************************************************************************
* Function Name: Cy_SysClk_PllGetLockStatus
****************************************************************************//**
*
* Reports the lock status of the selected PLL.
*
* \param clkPath Selects which PLL to check. 1 is the first PLL; 0 is invalid.
*
* \return 0 = not locked, 1 = locked, 0xFF = invalid clock path number
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_SysClk_PllGetLockStatus(uint32_t clkPath)
{
    uint8_t retval = 0xFFu; /* invalid clock path number */
    if ((clkPath != 0ul) && (clkPath <= SRSS_NUM_PLL))
    {
        retval = SRSS->unCLK_PLL_STATUS[clkPath - 1ul].stcField.u1LOCKED;
    }
    return (retval);
}

/*******************************************************************************
* Function Name: Cy_SysClk_PllLostLock
****************************************************************************//**
*
* Reports whether or not the selected PLL lost its lock since the last time this
* function was called. Clears the lost lock indicator.
*
* \param clkPath Selects which PLL to check. 1 is the first PLL; 0 is invalid.
*
* \return 0 = didn't lose lock, 1 = lost lock, 0xFF = invalid clock path number
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_SysClk_PllLostLock(uint32_t clkPath)
{
    uint8_t retval = 0xFFu; /* invalid clock path number */
    if ((clkPath != 0ul) && (clkPath <= SRSS_NUM_PLL))
    {
        retval = SRSS->unCLK_PLL_STATUS[clkPath - 1ul].stcField.u1UNLOCK_OCCURRED;
        /* write a 1 to clear the unlock occurred bit */
        SRSS->unCLK_PLL_STATUS[clkPath - 1ul].stcField.u1UNLOCK_OCCURRED = 1ul;
    }
    return (retval);
}

/*******************************************************************************
* Function Name: Cy_SysClk_PllDisable
****************************************************************************//**
*
* Disables the selected PLL.
*
* \param clkPath Selects which PLL to disable. 1 is the first PLL; 0 is invalid.
*
* \return Error / status code:<br>
* CY_SYSCLK_SUCCESS - PLL successfully disabled<br>
* CY_SYSCLK_BAD_PARAM - invalid clock path number
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PllDisable(uint32_t clkPath)
{
    cy_en_sysclk_status_t retval = CY_SYSCLK_BAD_PARAM;
    if ((clkPath != 0ul) && (clkPath <= SRSS_NUM_PLL))
    {
        SRSS->unCLK_PLL_CONFIG[clkPath - 1ul].stcField.u1ENABLE = 0ul; /* 0 = disable */
        retval = CY_SYSCLK_SUCCESS;
    }
    return (retval);
}
/** \} group_sysclk_pll_funcs */


/* ========================================================================== */
/* ===========================    ILO SECTION    ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_ilo_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_IloEnable(void);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_IloDisable(void);
__STATIC_INLINE void Cy_SysClk_IloHibernateOn(bool on);

/*******************************************************************************
* Function Name: Cy_SysClk_Ilo0Enable
****************************************************************************//**
*
* Enables the ILO0.
*
* \note The watchdog timer (WDT) must be unlocked before calling this function.
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_Ilo0Enable(void)
{
    if(WDT->unLOCK.stcField.u2WDT_LOCK != 0ul) /* WDT registers are disabled */
    {
        return(CY_SYSCLK_INVALID_STATE);
    }

    SRSS->unCLK_ILO0_CONFIG.stcField.u1ENABLE = 1ul; /* 1 = enable */
    return(CY_SYSCLK_SUCCESS);
}


/*******************************************************************************
* Function Name: Cy_SysClk_Ilo1Enable
****************************************************************************//**
*
* Enables the ILO1.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_Ilo1Enable(void)
{
    SRSS->unCLK_ILO1_CONFIG.stcField.u1ENABLE = 1ul; /* 1 = enable */
}

/*******************************************************************************
* Function Name: Cy_SysClk_Ilo0Disable
****************************************************************************//**
*
* Disables the ILO0. ILO0 can't be disabled if WDT is enabled.
*
* \return Error / status code:<br>
* CY_SYSCLK_SUCCESS - ILO0 successfully disabled<br>
* CY_SYSCLK_INVALID_STATE - Cannot disable the ILO0 if the WDT is enabled.
*
* \note The watchdog timer (WDT) must be unlocked before calling this function.
* Do not call this function if the WDT is enabled, because the WDT is clocked by
* the ILO0.
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_Ilo0Disable(void)
{
    if(WDT->unLOCK.stcField.u2WDT_LOCK != 0ul) /* WDT registers are disabled */
    {
        return(CY_SYSCLK_INVALID_STATE);
    }

    if (WDT->unCTL.stcField.u1ENABLED != 0ul) /* WDT is enabled */
    {
        return(CY_SYSCLK_INVALID_STATE);
    }

    SRSS->unCLK_ILO0_CONFIG.stcField.u1ENABLE = 0ul; /* 0 = disable */

    return CY_SYSCLK_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SysClk_Ilo1Disable
****************************************************************************//**
*
* Disables the ILO1.
*
* \return Error / status code:<br>
* CY_SYSCLK_SUCCESS - ILO1 successfully disabled<br>
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_Ilo1Disable(void)
{
    SRSS->unCLK_ILO1_CONFIG.stcField.u1ENABLE = 0ul; /* 0 = disable */

    return CY_SYSCLK_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SysClk_Ilo0HibernateOn
****************************************************************************//**
*
* Controls whether the ILO0 stays on during a hibernate, or through an XRES or
* brown-out detect (BOD) event.
*
* \param on
* 1 = ILO0 stays on during hibernate or across XRES/BOD. 0 = ILO0 turns off for
* hibernate or XRES/BOD.
*
* \note Writes to the register/bit are ignored if the watchdog (WDT) is locked.
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_Ilo0HibernateOn(bool on)
{
    if(WDT->unLOCK.stcField.u2WDT_LOCK != 0ul) /* WDT registers are disabled */
    {
        return(CY_SYSCLK_INVALID_STATE);
    }

    SRSS->unCLK_ILO0_CONFIG.stcField.u1ILO0_BACKUP = (uint32_t)on;

    return(CY_SYSCLK_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_SysClk_Ilo0MonitorOn
****************************************************************************//**
*
* Enable the internal ILO0 clock monitoring circuit.
*
* \param on
* 1 = Enable monitoring circuit. 0 = Disable monitoring circuit.
*
* \note Writes to the register/bit are ignored if the watchdog (WDT) is locked.
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_Ilo0MonitorEnable(bool on)
{
    if(WDT->unLOCK.stcField.u2WDT_LOCK != 0ul) /* WDT registers are disabled */
    {
        return(CY_SYSCLK_INVALID_STATE);
    }

    SRSS->unCLK_ILO0_CONFIG.stcField.u1ILO0_MON_ENABLE = (uint32_t)on;

    return(CY_SYSCLK_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_SysClk_Ilo1MonitorOn
****************************************************************************//**
*
* Enable the internal ILO1 clock monitoring circuit.
*
* \param on
* 1 = Enable monitoring circuit. 0 = Disable monitoring circuit.
*
* \note Writes to the register/bit are ignored if the watchdog (WDT) is locked.
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_Ilo1MonitorEnable(bool on)
{
    SRSS->unCLK_ILO0_CONFIG.stcField.u1ILO0_MON_ENABLE = (uint32_t)on;
    return(CY_SYSCLK_SUCCESS);
}

/** \} group_sysclk_ilo_funcs */


/* ========================================================================== */
/* ====================    CLOCK MEASUREMENT SECTION    ===================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_calclk_enums
* \{
*/
/** Defines all possible clock sources. */
typedef enum
{
    CY_SYSCLK_MEAS_CLK_ILO0      = 1u,
    CY_SYSCLK_MEAS_CLK_WCO       = 2u,
    CY_SYSCLK_MEAS_CLK_BAK       = 3u,
    CY_SYSCLK_MEAS_CLK_LFCLK     = 5u,
    CY_SYSCLK_MEAS_CLK_IMO       = 6u,
    CY_SYSCLK_MEAS_CLK_SLPCTRL   = 7u,
    CY_SYSCLK_MEAS_CLK_ILO1      = 9u,
    CY_SYSCLK_MEAS_CLK_ECO_PRE   = 10u,
    CY_SYSCLK_MEAS_CLK_FAST_CLKS = 0x100u,
    CY_SYSCLK_MEAS_CLK_ECO       = 0x101u,
    CY_SYSCLK_MEAS_CLK_EXT       = 0x102u,
    CY_SYSCLK_MEAS_CLK_TIMER     = 0x103u,
    CY_SYSCLK_MEAS_CLK_PATH_CLKS = 0x500u,
    CY_SYSCLK_MEAS_CLK_PATH0     = 0x500u,
    CY_SYSCLK_MEAS_CLK_PATH1     = 0x501u,
    CY_SYSCLK_MEAS_CLK_PATH2     = 0x502u,
    CY_SYSCLK_MEAS_CLK_PATH3     = 0x503u,
    CY_SYSCLK_MEAS_CLK_PATH4     = 0x504u,
    CY_SYSCLK_MEAS_CLK_PATH5     = 0x505u,
    CY_SYSCLK_MEAS_CLK_PATH6     = 0x506u,
    CY_SYSCLK_MEAS_CLK_PATH7     = 0x507u,
    CY_SYSCLK_MEAS_CLK_PATH8     = 0x508u,
    CY_SYSCLK_MEAS_CLK_PATH9     = 0x509u,
    CY_SYSCLK_MEAS_CLK_PATH10    = 0x50Au,
    CY_SYSCLK_MEAS_CLK_PATH11    = 0x50Bu,
    CY_SYSCLK_MEAS_CLK_PATH12    = 0x50Cu,
    CY_SYSCLK_MEAS_CLK_PATH13    = 0x50Du,
    CY_SYSCLK_MEAS_CLK_PATH14    = 0x50Eu,
    CY_SYSCLK_MEAS_CLK_PATH15    = 0x50Fu,
    CY_SYSCLK_MEAS_CLK_HF_CLKS   = 0x600u,
    CY_SYSCLK_MEAS_CLK_HFCLK0    = 0x600u,
    CY_SYSCLK_MEAS_CLK_HFCLK1    = 0x601u,
    CY_SYSCLK_MEAS_CLK_HFCLK2    = 0x602u,
    CY_SYSCLK_MEAS_CLK_HFCLK3    = 0x603u,
    CY_SYSCLK_MEAS_CLK_HFCLK4    = 0x604u,
    CY_SYSCLK_MEAS_CLK_HFCLK5    = 0x605u,
    CY_SYSCLK_MEAS_CLK_HFCLK6    = 0x606u,
    CY_SYSCLK_MEAS_CLK_HFCLK7    = 0x607u,
    CY_SYSCLK_MEAS_CLK_HFCLK8    = 0x608u,
    CY_SYSCLK_MEAS_CLK_HFCLK9    = 0x609u,
    CY_SYSCLK_MEAS_CLK_HFCLK10   = 0x60Au,
    CY_SYSCLK_MEAS_CLK_HFCLK11   = 0x60Bu,
    CY_SYSCLK_MEAS_CLK_HFCLK12   = 0x60Cu,
    CY_SYSCLK_MEAS_CLK_HFCLK13   = 0x60Du,
    CY_SYSCLK_MEAS_CLK_HFCLK14   = 0x60Eu,
    CY_SYSCLK_MEAS_CLK_HFCLK15   = 0x60Fu,
    CY_SYSCLK_MEAS_CLK_LAST_CLK  = 0x610u
} cy_en_meas_clks_t;
/** \} group_sysclk_calclk_enums */

/**
* \addtogroup group_sysclk_calclk_funcs
* \{
*/
cy_en_sysclk_status_t Cy_SysClk_StartClkMeasurementCounters(cy_en_meas_clks_t clock1, uint32_t count1, cy_en_meas_clks_t clock2);
__STATIC_INLINE bool Cy_SysClk_ClkMeasurementCountersDone(void);
cy_en_sysclk_status_t Cy_SysClk_ClkMeasurementCountersGetFreq(uint32_t *measuredFreq, uint32_t refClkFreq);

/*******************************************************************************
* Function Name: Cy_SysClk_ClkMeasurementCountersDone
****************************************************************************//**
*
* Checks if clock measurement counting is done, that is, counter1 has counted down
* to zero. Call \ref Cy_SysClk_StartClkMeasurementCounters() before calling this function.
*
* \return Status of calibration counters: true if done, false if not.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_ClkMeasurementCountersDone(void)
{
   return (bool)(SRSS->unCLK_CAL_CNT1.stcField.u1CAL_COUNTER_DONE); /* 1 = done */
}
/** \} group_sysclk_calclk_funcs */


/* ========================================================================== */
/* ==========================    TRIM SECTION    ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_trim_funcs
* \{
*/
int32_t Cy_SysClk_IloTrim(uint32_t iloFreq, uint8_t iloNo);
/** \} group_sysclk_trim_funcs */


/* ========================================================================== */
/* ======================    POWER MANAGEMENT SECTION    ==================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_pm_funcs
* \{
*/
cy_en_syspm_status_t Cy_SysClk_DeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams);
/** \} group_sysclk_pm_funcs */


/* ========================================================================== */
/* ===========================    WCO SECTION    ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_wco_enums
* \{
*/
/** WCO bypass modes */
typedef enum
{
    CY_SYSCLK_WCO_NOT_BYPASSED = 0u, /**< WCO is not bypassed crystal is used */
    CY_SYSCLK_WCO_BYPASSED     = 1u  /**< WCO is bypassed external clock must be supplied  on XTAL pin */
} cy_en_wco_bypass_modes_t;

/** WCO CSV supervisor clock selections */
typedef enum
{
    CY_SYSCLK_WCO_CSV_SUPERVISOR_ILO,   /**< WCO CSV supervisor clock source is the ILO */
} cy_en_wco_csv_supervisor_clock_t;

/**
* Clock supervisor clock loss window. There must be one clock of the supervised
* clock within this many clocks of the supervising clock.
* See registers CLK_CSV_HF_CTL and CLK_CSV_WCO_CTL, bitfield CSV_LOSS_WINDOW.
*/
typedef enum
{
    CY_SYSCLK_CSV_LOSS_4_CYCLES   = 0u, /**< 1 clock must be seen within 4 cycles of the supervising clock. */
    CY_SYSCLK_CSV_LOSS_8_CYCLES   = 1u, /**< 1 clock must be seen within 8 cycles of the supervising clock. */
    CY_SYSCLK_CSV_LOSS_16_CYCLES  = 2u, /**< 1 clock must be seen within 16 cycles of the supervising clock. */
    CY_SYSCLK_CSV_LOSS_32_CYCLES  = 3u, /**< 1 clock must be seen within 32 cycles of the supervising clock. */
    CY_SYSCLK_CSV_LOSS_64_CYCLES  = 4u, /**< 1 clock must be seen within 64 cycles of the supervising clock. */
    CY_SYSCLK_CSV_LOSS_128_CYCLES = 5u, /**< 1 clock must be seen within 128 cycles of the supervising clock. */
    CY_SYSCLK_CSV_LOSS_256_CYCLES = 6u, /**< 1 clock must be seen within 256 cycles of the supervising clock. */
    CY_SYSCLK_CSV_LOSS_512_CYCLES = 7u  /**< 1 clock must be seen within 512 cycles of the supervising clock. */
} cy_en_csv_loss_window_t;

/**
* Clock supervisor error actions. See register CLK_CSV_HF_CTL[CSV_FREQ_ACTION and CSV_LOSS_ACTION].
*/
typedef enum
{
    CY_SYSCLK_CSV_ERROR_IGNORE      = 0u, /**< Ignore the error reported by the clock supervisor. */
    CY_SYSCLK_CSV_ERROR_FAULT       = 1u, /**< Trigger a fault when an error is reported by the clock supervisor. */
    CY_SYSCLK_CSV_ERROR_RESET       = 2u, /**< Trigger a reset when an error is reported by the clock supervisor. */
    CY_SYSCLK_CSV_ERROR_FAULT_RESET = 3u  /**< Trigger a fault then reset when an error is reported by the supervisor. */
} cy_en_csv_error_actions_t;
/** \} group_sysclk_wco_enums */

/**
* \addtogroup group_sysclk_wco_structs
* \{
*/
/**
* This structure is used to configure the clock supervisor for the WCO.
*/
typedef struct
{
    cy_en_wco_csv_supervisor_clock_t SupervisorClock;     /**< supervisor clock selection */
    bool                             enableLossDetection; /**< 1= enabled, 0= disabled. Note that if loss detection is enabled, writes to other register bits are ignored. */
    cy_en_csv_loss_window_t          LossWindow;          /**< \ref cy_en_csv_loss_window_t */
    cy_en_csv_error_actions_t        LossAction;          /**< \ref cy_en_csv_error_actions_t */
} cy_stc_wco_csv_config_t;
/** \} group_sysclk_wco_structs */

/**
* \addtogroup group_sysclk_wco_funcs
* \{
*/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_WcoEnable(uint32_t timeoutus);
__STATIC_INLINE bool Cy_SysClk_WcoOkay(void);
__STATIC_INLINE void Cy_SysClk_WcoDisable(void);
__STATIC_INLINE void Cy_SysClk_WcoBypass(cy_en_wco_bypass_modes_t bypass);
cy_en_sysclk_status_t Cy_SysClk_WcoConfigureCsv(const cy_stc_wco_csv_config_t *config);

/*******************************************************************************
* Function Name: Cy_SysClk_WcoEnable
****************************************************************************//**
*
* Enables the WCO.
*
* \param timeoutus amount of time in microseconds to wait for the WCO to be ready.
* If WCO is not ready, WCO is stopped. To avoid waiting for WCO ready set this to 0,
* and manually check if WCO is okay using \ref Cy_SysClk_WcoOkay.
*
* \return Error / status code:<br>
* CY_SYSCLK_SUCCESS - WCO successfully enabled<br>
* CY_SYSCLK_TIMEOUT - Timeout waiting for WCO to stabilize
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_WcoEnable(uint32_t timeoutus)
{
    cy_en_sysclk_status_t rtnval = CY_SYSCLK_TIMEOUT;

    BACKUP->unCTL.stcField.u1WCO_EN = 1ul;

    /* now do the timeout wait for STATUS, bit WCO_OK */
    for (; (Cy_SysClk_WcoOkay() == false) && (timeoutus != 0ul); timeoutus--)
    {
        Cy_SysLib_DelayUs(1u);
    }
    if (timeoutus != 0ul)
    {
        rtnval = CY_SYSCLK_SUCCESS;
    }

    return (rtnval);
}

/*******************************************************************************
* Function Name: Cy_SysClk_WcoOkay
****************************************************************************//**
*
* Reports the status of the WCO_OK bit.
*
* \return true = okay false = not okay
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_WcoOkay(void)
{
    return (bool)(BACKUP->unSTATUS.stcField.u1WCO_OK);
}

/*******************************************************************************
* Function Name: Cy_SysClk_WcoDisable
****************************************************************************//**
*
* Disables the WCO.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_WcoDisable(void)
{
    BACKUP->unCTL.stcField.u1WCO_EN = 0ul;
}

/*******************************************************************************
* Function Name: Cy_SysClk_WcoBypass
****************************************************************************//**
*
* Sets whether the WCO is bypassed or not. If it is bypassed then a 32-kHz clock
* must be provided on the wco_in pin.
*
* \param bypass \ref cy_en_wco_bypass_modes_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_WcoBypass(cy_en_wco_bypass_modes_t bypass)
{
    BACKUP->unCTL.stcField.u1WCO_BYPASS = bypass;
}
/** \} group_sysclk_wco_funcs */


/* ========================================================================== */
/* ========================    clk_hf[n] SECTION    ========================= */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_hf_enums
* \{
*/
/**
* Selects which hf_clk input, or root mux, to configure.
* See CLK_ROOT_SELECT registers, bits ROOT_MUX.
* Used with functions \ref Cy_SysClk_HfClockSetSource and \ref Cy_SysClk_HfClockGetSource.
*/
typedef enum
{
    CY_SYSCLK_HFCLK_IN_CLKPATH0  = 0u,    /**< hf_clk input is Clock Path 0 */
    CY_SYSCLK_HFCLK_IN_CLKPATH1  = 1u,    /**< hf_clk input is Clock Path 1 */
    CY_SYSCLK_HFCLK_IN_CLKPATH2  = 2u,    /**< hf_clk input is Clock Path 2 */
    CY_SYSCLK_HFCLK_IN_CLKPATH3  = 3u,    /**< hf_clk input is Clock Path 3 */
    CY_SYSCLK_HFCLK_IN_CLKPATH4  = 4u,    /**< hf_clk input is Clock Path 4 */
    CY_SYSCLK_HFCLK_IN_CLKPATH5  = 5u,    /**< hf_clk input is Clock Path 5 */
    CY_SYSCLK_HFCLK_IN_CLKPATH6  = 6u,    /**< hf_clk input is Clock Path 6 */
    CY_SYSCLK_HFCLK_IN_CLKPATH7  = 7u,    /**< hf_clk input is Clock Path 7 */
    CY_SYSCLK_HFCLK_IN_CLKPATH8  = 8u,    /**< hf_clk input is Clock Path 8 */
    CY_SYSCLK_HFCLK_IN_CLKPATH9  = 9u,    /**< hf_clk input is Clock Path 9 */
    CY_SYSCLK_HFCLK_IN_CLKPATH10 = 10u,   /**< hf_clk input is Clock Path 10 */
    CY_SYSCLK_HFCLK_IN_CLKPATH11 = 11u,   /**< hf_clk input is Clock Path 11 */
    CY_SYSCLK_HFCLK_IN_CLKPATH12 = 12u,   /**< hf_clk input is Clock Path 12 */
    CY_SYSCLK_HFCLK_IN_CLKPATH13 = 13u,   /**< hf_clk input is Clock Path 13 */
    CY_SYSCLK_HFCLK_IN_CLKPATH14 = 14u,   /**< hf_clk input is Clock Path 14 */
    CY_SYSCLK_HFCLK_IN_CLKPATH15 = 15u,   /**< hf_clk input is Clock Path 15 */
} cy_en_hf_clk_sources_t;

/**
* hf_clk divider values. See CLK_ROOT_SELECT registers, bits ROOT_DIV.
* Used with functions \ref Cy_SysClk_HfClockSetDivider and \ref Cy_SysClk_HfClockGetDivider.
*/
typedef enum
{
    CY_SYSCLK_HFCLK_NO_DIVIDE   = 0u,    /**< don't divide hf_clk. */
    CY_SYSCLK_HFCLK_DIVIDE_BY_2 = 1u,    /**< divide hf_clk by 2 */
    CY_SYSCLK_HFCLK_DIVIDE_BY_4 = 2u,    /**< divide hf_clk by 4 */
    CY_SYSCLK_HFCLK_DIVIDE_BY_8 = 3u     /**< divide hf_clk by 8 */
} cy_en_hf_clk_dividers_t;

/**
* hf_clk clock supervisor input sources. See register CLK_CSV_HF_CTL[CSV_MUX].
*/
typedef enum
{
    CY_SYSCLK_HFCLK_CSV_SUPERVISOR_IMO = 0u, /**< Supervising clock is the IMO. */
    CY_SYSCLK_HFCLK_CSV_SUPERVISOR_EXT = 1u, /**< Supervising clock is the external clock */
} cy_en_hfclk_csv_supervisor_clock_t;

typedef enum
{
    CY_SYSCLK_HFCLK_0  = 0u,
    CY_SYSCLK_HFCLK_1  = 1u,
    CY_SYSCLK_HFCLK_NUM,
} cy_en_hfclk_t;

/** \} group_sysclk_clk_hf_enums */

/**
* \addtogroup group_sysclk_clk_hf_structs
* \{
*/
/**
* This structure is used to configure the clock supervisor for hf_clk.
*/
typedef struct
{
    cy_en_hfclk_csv_supervisor_clock_t SupervisorClock;              /**< \ref cy_en_hfclk_csv_supervisor_clock_t */
    uint16_t                           SupervisingWindow;            /**< Number of supervising clock cycles */
    bool                               enableFrquencyFaultDetection; /**< 1= enabled, 0= disabled */
    uint16_t                           FrequencyLowerLimit;          /**< Lowest frequency in kHz that supervised clock can go */
    uint16_t                           FrequencyUpperLimit;          /**< Highest frequency in kHz that supervised clock can go */
    cy_en_csv_error_actions_t          FrequencyAction;              /**< \ref cy_en_csv_error_actions_t */
    bool                               enableLossDetection;          /**< 1= enabled, 0= disabled */
    cy_en_csv_loss_window_t            LossWindow;                   /**< \ref cy_en_csv_loss_window_t */
    cy_en_csv_error_actions_t          LossAction;                   /**< \ref cy_en_csv_error_actions_t */
} cy_stc_hf_csv_config_t;
/** \} group_sysclk_clk_hf_structs */

/**
* \addtogroup group_sysclk_clk_hf_funcs
* \{
*/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_HfClkEnable(cy_en_hfclk_t hfClk);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_HfClkDisable(cy_en_hfclk_t hfClk);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_HfClockSetSource(cy_en_hfclk_t hfClk, cy_en_hf_clk_sources_t source);
__STATIC_INLINE cy_en_hf_clk_sources_t Cy_SysClk_HfClockGetSource(cy_en_hfclk_t hfClk);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_HfClockSetDivider(cy_en_hfclk_t hfClk, cy_en_hf_clk_dividers_t divider);
__STATIC_INLINE cy_en_hf_clk_dividers_t Cy_SysClk_HfClockGetDivider(cy_en_hfclk_t hfClk);
cy_en_sysclk_status_t Cy_SysClk_HfClockConfigureCsv(cy_en_hfclk_t hfClk, const cy_stc_hf_csv_config_t *config);

/*******************************************************************************
* Function Name: Cy_SysClk_HfClkEnable
****************************************************************************//**
*
* Enables the selected HfClk.
*
* \param hfClk Selects which HfClk to enable.
*
* \return \ref cy_en_sysclk_status_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_HfClkEnable(cy_en_hfclk_t hfClk)
{
    if(hfClk >= SRSS_NUM_HFROOT)
    {
        return CY_SYSCLK_BAD_PARAM;
    }

    SRSS->unCLK_ROOT_SELECT[hfClk].stcField.u1ENABLE = 1ul; /* 1 = enable */
    
    return CY_SYSCLK_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SysClk_HfClkDisable
****************************************************************************//**
*
* Disables the selected HfClk.
*
* \param hfClk Selects which HfClk to enable.
*
* \return \ref cy_en_sysclk_status_t
*
* \note HfClk[0] cannot be disabled.
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_HfClkDisable(cy_en_hfclk_t hfClk)
{
    if(hfClk >= SRSS_NUM_HFROOT)
    {
        return CY_SYSCLK_BAD_PARAM;
    }

    SRSS->unCLK_ROOT_SELECT[hfClk].stcField.u1ENABLE = 0ul; /* 0 = disable */

    return CY_SYSCLK_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SysClk_HfClockSetSource
****************************************************************************//**
*
* Selects the source of the selected HfClk.
*
* \param hfClk Which HfClk mux to configure.
*
* \param source \ref cy_en_hf_clk_sources_t
*
* \return \ref cy_en_sysclk_status_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_HfClockSetSource(cy_en_hfclk_t hfClk, cy_en_hf_clk_sources_t source)
{
    if(hfClk >= SRSS_NUM_HFROOT)
    {
        return CY_SYSCLK_BAD_PARAM;
    }

    SRSS->unCLK_ROOT_SELECT[hfClk].stcField.u4ROOT_MUX = source;

    return CY_SYSCLK_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SysClk_HfClockGetSource
****************************************************************************//**
*
* Reports the source of the selected HfClk.
*
* \param hfClk selects which HfClk to get the source of.
*
* \return \ref cy_en_hf_clk_sources_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_hf_clk_sources_t Cy_SysClk_HfClockGetSource(cy_en_hfclk_t hfClk)
{
    CY_ASSERT(hfClk < SRSS_NUM_HFROOT);

    return (cy_en_hf_clk_sources_t)SRSS->unCLK_ROOT_SELECT[hfClk].stcField.u4ROOT_MUX;
}

/*******************************************************************************
* Function Name: Cy_SysClk_HfClockSetDivider
****************************************************************************//**
*
* Sets the pre-divider for a HfClk.
*
* \param hfClk selects which HfClk divider to configure.
*
* \param divider \ref cy_en_hf_clk_dividers_t
*
* \note Also call \ref Cy_SysClk_HfClockSetSource to set the HfClk source.
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_HfClockSetDivider(cy_en_hfclk_t hfClk, cy_en_hf_clk_dividers_t divider)
{
    if(
        (hfClk >= SRSS_NUM_HFROOT) ||
        (divider > CY_SYSCLK_HFCLK_DIVIDE_BY_8)
      )
    {
        return CY_SYSCLK_BAD_PARAM;
    }

    SRSS->unCLK_ROOT_SELECT[hfClk].stcField.u2ROOT_DIV = divider;

    return CY_SYSCLK_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SysClk_HfClockGetDivider
****************************************************************************//**
*
* Reports the pre-divider value for a HfClk.
*
* \param hfClk selects which HfClk to check divider of.
*
* \return \ref cy_en_hf_clk_dividers_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_hf_clk_dividers_t Cy_SysClk_HfClockGetDivider(cy_en_hfclk_t hfClk)
{
    CY_ASSERT(hfClk < SRSS_NUM_HFROOT);

    return (cy_en_hf_clk_dividers_t)SRSS->unCLK_ROOT_SELECT[hfClk].stcField.u2ROOT_DIV;
}
/** \} group_sysclk_clk_hf_funcs */


/* ========================================================================== */
/* =========================    clk_fast SECTION    ========================= */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_fast_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_FastClkSetDivider(uint32_t divider);
__STATIC_INLINE uint32_t Cy_SysClk_FastClkGetDivider(void);

/*******************************************************************************
* Function Name: Cy_SysClk_FastClkSetDivider
****************************************************************************//**
*
* Sets the clock divider for the fast clock, which sources the main processor.
* The source of this divider is hf_clk[0].
*
* \param divider divider value between 0 and 255.
* Causes integer division of (divider value + 1), or division by 1 to 256.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_FastClkSetDivider(uint32_t divider)
{
    CPUSS->unCM4_CLOCK_CTL.stcField.u8FAST_INT_DIV = divider;
}

/*******************************************************************************
* Function Name: Cy_SysClk_FastClkGetDivider
****************************************************************************//**
*
* Returns the clock divider for the fast clock.
*
* \return The divider value for the fast clock.
* The integer division done is by (divider value + 1), or division by 1 to 256.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_FastClkGetDivider(void)
{
    return CPUSS->unCM4_CLOCK_CTL.stcField.u8FAST_INT_DIV;
}
/** \} group_sysclk_clk_fast_funcs */


/* ========================================================================== */
/* ========================    clk_peri SECTION    ========================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_peri_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_PeriClkSetDivider(uint8_t divider);
__STATIC_INLINE uint8_t Cy_SysClk_PeriClkGetDivider(void);

/*******************************************************************************
* Function Name: Cy_SysClk_PeriClkSetDivider
****************************************************************************//**
*
* Sets the clock divider for the peripheral clock tree. All peripheral clock
* dividers are sourced from this clock. Also the Cortex M0+ clock divider is
* sourced from this clock. The source of this divider is hf_clk[0]
*
* \param divider divider value between 0 and 255
* Causes integer division of (divider value + 1), or division by 1 to 256.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_PeriClkSetDivider(uint8_t divider)
{
    CPUSS->unCM0_CLOCK_CTL.stcField.u8PERI_INT_DIV = divider;
}

/*******************************************************************************
* Function Name: Cy_SysClk_PeriClkGetDivider
****************************************************************************//**
*
* Returns the clock divider of peripheral (peri) clock
*
* \return The divider value.
* The integer division done is by (divider value + 1), or division by 1 to 256.
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_SysClk_PeriClkGetDivider(void)
{
    return CPUSS->unCM0_CLOCK_CTL.stcField.u8PERI_INT_DIV;
}
/** \} group_sysclk_clk_peri_funcs */


/* ========================================================================== */
/* =====================    clk_peripherals SECTION    ====================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_peripheral_enums
* \{
*/
/** Programmable clock divider types */
typedef enum
{
    CY_SYSCLK_DIV_8_BIT    = 0u, /**< Divider Type is an 8 bit divider */
    CY_SYSCLK_DIV_16_BIT   = 1u, /**< Divider Type is a 16 bit divider */
    CY_SYSCLK_DIV_16_5_BIT = 2u, /**< Divider Type is a 16.5 bit fractional divider */
    CY_SYSCLK_DIV_24_5_BIT = 3u, /**< Divider Type is a 24.5 bit fractional divider */
    CY_SYSCLK_DIV_TYPE_NUM,
} cy_en_divider_types_t;
/** \} group_sysclk_clk_peripheral_enums */

/**
* \addtogroup group_sysclk_clk_peripheral_funcs
* \{
*/
typedef enum
{
    CY_DIVIDER_EXISTING     = 0u,
    CY_DIVIDER_NOT_EXISTING = 1u,
} cy_en_divider_existing_t;

__STATIC_INLINE cy_en_divider_existing_t Cy_SysClk_CheckDividerExisting(cy_en_divider_types_t dividerType, uint32_t dividerNum);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphSetDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum, uint32_t dividerValue);
__STATIC_INLINE uint32_t Cy_SysClk_PeriphGetDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphSetFracDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum, uint32_t dividerIntValue, uint32_t dividerFracValue);
__STATIC_INLINE void Cy_SysClk_PeriphGetFracDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum, uint32_t *dividerIntValue, uint32_t *dividerFracValue);
__STATIC_INLINE bool Cy_SysClk_PeriphGetDividerEnabled(cy_en_divider_types_t dividerType, uint32_t dividerNum);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphAssignDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType, uint32_t dividerNum);
__STATIC_INLINE void Cy_SysClk_PeriphGetAssignedDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t *dividerType, uint32_t *dividerNum);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphEnableDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphDisableDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphPhaseDisableDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphPhaseAlignDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum, cy_en_divider_types_t dividerTypePA, uint32_t dividerNumPA);

/*******************************************************************************
* Function Name: Cy_SysClk_CheckDividerExisting
****************************************************************************//**
*
* This function checks whether selected divider is existing or not.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum the divider number.
*
* \return \cy_en_divider_existing_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_divider_existing_t Cy_SysClk_CheckDividerExisting(cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    switch(dividerType)
    {
#if PERI_DIV_8_NR != 0
    case CY_SYSCLK_DIV_8_BIT:
        if(dividerNum >= PERI_DIV_8_NR)
        {
            return CY_DIVIDER_NOT_EXISTING;
        }
        break;
#endif
#if PERI_DIV_16_NR != 0
    case CY_SYSCLK_DIV_16_BIT:
        if(dividerNum >= PERI_DIV_16_NR)
        {
            return CY_DIVIDER_NOT_EXISTING;
        }
        break;
#endif
#if PERI_DIV_16_5_NR != 0
    case CY_SYSCLK_DIV_16_5_BIT:
        if(dividerNum >= PERI_DIV_16_5_NR)
        {
            return CY_DIVIDER_NOT_EXISTING;
        }
        break;
#endif
#if PERI_DIV_24_5_NR != 0
    case CY_SYSCLK_DIV_24_5_BIT:
        if(dividerNum >= PERI_DIV_24_5_NR)
        {
            return CY_DIVIDER_NOT_EXISTING;
        }
        break;
#endif
    default:
        return CY_DIVIDER_NOT_EXISTING;
    }

    return CY_DIVIDER_EXISTING;
}

/*******************************************************************************
* Function Name: Cy_SysClk_PeriphSetDivider
****************************************************************************//**
*
* Sets one of the programmable clock dividers. This is only used for integer
* dividers. Use \ref Cy_SysClk_PeriphSetFracDivider for setting factional dividers.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum the divider number.
*
* \param dividerValue divider value
* Causes integer division of (divider value + 1), or division by 1 to 256
* (8-bit divider) or 1 to 65536 (16-bit divider).
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphSetDivider(cy_en_divider_types_t dividerType,
                                                uint32_t dividerNum, uint32_t dividerValue)
{
    if(Cy_SysClk_CheckDividerExisting(dividerType, dividerNum) == CY_DIVIDER_NOT_EXISTING)
    {
        return CY_SYSCLK_BAD_PARAM;
    }

    if (dividerType == CY_SYSCLK_DIV_8_BIT)
    {
        if (dividerValue <= (PERI_DIV_8_CTL_INT8_DIV_Msk >> PERI_DIV_8_CTL_INT8_DIV_Pos))
        {
            PERI->unDIV_8_CTL[dividerNum].stcField.u8INT8_DIV = dividerValue;
        }
        else
        {
            return CY_SYSCLK_BAD_PARAM;
        }

    }
    else if (dividerType == CY_SYSCLK_DIV_16_BIT)
    {
        if(dividerValue <= (PERI_DIV_16_CTL_INT16_DIV_Msk >> PERI_DIV_16_CTL_INT16_DIV_Pos))
        {
            PERI->unDIV_16_CTL[dividerNum].stcField.u16INT16_DIV =  dividerValue;
        }
        else
        {
            return CY_SYSCLK_BAD_PARAM;
        }
    }
    else
    { /* return bad parameter */
        return CY_SYSCLK_BAD_PARAM;
    }

    return CY_SYSCLK_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SysClk_PeriphGetDivider
****************************************************************************//**
*
* Returns the integer divider value for the specified divider. One works for
* integer dividers. Use \ref Cy_SysClk_PeriphGetFracDivider to get the fractional
* divider value
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \return The divider value.
* The integer division done is by (divider value + 1), or division by 1 to 256
* (8-bit divider) or 1 to 65536 (16-bit divider).
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_PeriphGetDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    uint32_t retval;

    CY_ASSERT(Cy_SysClk_CheckDividerExisting(dividerType, dividerNum) == CY_DIVIDER_EXISTING);

    if (dividerType == CY_SYSCLK_DIV_8_BIT)
    {
        retval = PERI->unDIV_8_CTL[dividerNum].stcField.u8INT8_DIV;
    }
    else if (dividerType == CY_SYSCLK_DIV_16_BIT)
    { /* 16-bit divider */
        retval = PERI->unDIV_16_CTL[dividerNum].stcField.u16INT16_DIV;
    }
    else
    {
        CY_ASSERT(false);
    }

    return (retval);
}

/*******************************************************************************
* Function Name: Cy_SysClk_PeriphSetFracDivider
****************************************************************************//**
*
* Sets one of the programmable clock dividers. This function should only be used
* for fractional clock dividers.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \param dividerIntValue the integer divider value
* The source of the divider is peri_clk, which is a divided version of hf_clk[0].
* The divider value causes integer division of (divider value + 1), or division
* by 1 to 65536 (16-bit divider) or 1 to 16777216 (24-bit divider).
*
* \param dividerFracValue the fraction part of the divider
* The fractional divider can be 1-32, thus it divides the clock by 1/32 for each
* count. To divide the clock by 11/32nds set this value to 11.
*
* \return \ref cy_en_sysclk_status_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphSetFracDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                                    uint32_t dividerIntValue, uint32_t dividerFracValue)
{
    if(Cy_SysClk_CheckDividerExisting(dividerType, dividerNum) == CY_DIVIDER_NOT_EXISTING)
    {
        return CY_SYSCLK_BAD_PARAM;
    }

    if (dividerType == CY_SYSCLK_DIV_16_5_BIT)
    {
        if ((dividerIntValue <= (PERI_DIV_16_5_CTL_INT16_DIV_Msk >> PERI_DIV_16_5_CTL_INT16_DIV_Pos)) &&
            (dividerFracValue <= (PERI_DIV_16_5_CTL_FRAC5_DIV_Msk >> PERI_DIV_16_5_CTL_FRAC5_DIV_Pos)))
        {
            PERI->unDIV_16_5_CTL[dividerNum].stcField.u16INT16_DIV = dividerIntValue;
            PERI->unDIV_16_5_CTL[dividerNum].stcField.u5FRAC5_DIV = dividerFracValue;
        }
        else
        {
            return CY_SYSCLK_BAD_PARAM;
        }
    }
    else if (dividerType == CY_SYSCLK_DIV_24_5_BIT)
    {
        if ((dividerIntValue <= (PERI_DIV_24_5_CTL_INT24_DIV_Msk >> PERI_DIV_24_5_CTL_INT24_DIV_Pos)) &&
            (dividerFracValue <= (PERI_DIV_24_5_CTL_FRAC5_DIV_Msk >> PERI_DIV_24_5_CTL_FRAC5_DIV_Pos)))
        {
            PERI->unDIV_24_5_CTL[dividerNum].stcField.u24INT24_DIV = dividerIntValue;
            PERI->unDIV_24_5_CTL[dividerNum].stcField.u5FRAC5_DIV = dividerFracValue;
        }
        else
        {
            return CY_SYSCLK_BAD_PARAM;
        }
    }
    else
    { /* return bad parameter */
        return CY_SYSCLK_BAD_PARAM;
    }

    return CY_SYSCLK_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SysClk_PeriphGetFracDivider
****************************************************************************//**
*
* Reports the integer and fractional parts of the divider
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \param *dividerIntValue pointer to return integer divider value
*
* \param *dividerFracValue pointer to return fractional divider value
*
* \return None. Loads pointed-to variables.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_PeriphGetFracDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                                    uint32_t *dividerIntValue, uint32_t *dividerFracValue)
{
    CY_ASSERT(Cy_SysClk_CheckDividerExisting(dividerType, dividerNum) == CY_DIVIDER_EXISTING);
    CY_ASSERT((dividerIntValue != NULL) && (dividerFracValue != NULL));

    if (dividerType == CY_SYSCLK_DIV_16_5_BIT)
    {
        *dividerIntValue  = PERI->unDIV_16_5_CTL[dividerNum].stcField.u16INT16_DIV;
        *dividerFracValue = PERI->unDIV_16_5_CTL[dividerNum].stcField.u5FRAC5_DIV;
    }
    else if (dividerType == CY_SYSCLK_DIV_24_5_BIT)
    { /* 24.5-bit divider */
        *dividerIntValue  = PERI->unDIV_24_5_CTL[dividerNum].stcField.u24INT24_DIV;
        *dividerFracValue = PERI->unDIV_24_5_CTL[dividerNum].stcField.u5FRAC5_DIV;
    }
    else
    {
        CY_ASSERT(false);
    }
}

/*******************************************************************************
* Function Name: Cy_SysClk_PeriphGetDividerEnabled
****************************************************************************//**
*
* Reports the enabled/disabled state of the selected divider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t.
*
* \param dividerNum specifies which divider of the selected type to configure.
*
* \return The enabled/disabled state; 0 = disabled, 1 = enabled.
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_PeriphGetDividerEnabled(cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    uint32_t retval = 0ul;

    CY_ASSERT(Cy_SysClk_CheckDividerExisting(dividerType, dividerNum) == CY_DIVIDER_EXISTING);

    switch(dividerType)
    {
    case CY_SYSCLK_DIV_8_BIT:
        retval = PERI->unDIV_8_CTL[dividerNum].stcField.u1EN;
        break;
    case CY_SYSCLK_DIV_16_BIT:
        retval = PERI->unDIV_16_CTL[dividerNum].stcField.u1EN;
        break;
    case CY_SYSCLK_DIV_16_5_BIT:
        retval = PERI->unDIV_16_5_CTL[dividerNum].stcField.u1EN;
        break;
    case CY_SYSCLK_DIV_24_5_BIT:
        retval = PERI->unDIV_24_5_CTL[dividerNum].stcField.u1EN;
        break;
    default:
        CY_ASSERT(false);
        break;
    }
    return ((bool)retval);
}

/* ========================================================================== */
/* =========================    clk_gr SECTION    =========================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_gr_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_SetClkGrDiv(uint32_t clkGR, uint8_t divider);
__STATIC_INLINE uint8_t Cy_SysClk_GetClkGrDiv(uint32_t clkGR);

/*******************************************************************************
* Function Name: Cy_SysClk_SetClkGrDiv
****************************************************************************//**
*
* Sets the clock divider for the clock GR.
*
* \param clkGR group No to be set.
*
* \param divider divider value between 0 and 255.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_SetClkGrDiv(uint32_t clkGR, uint8_t divider)
{
    PERI->GR[clkGR].unCLOCK_CTL.stcField.u8INT8_DIV = divider;
}

/*******************************************************************************
* Function Name: Cy_SysClk_GetClkGrDiv
****************************************************************************//**
*
* Returns the clock divider for the clock GR.
*
* \param clkGR group No, divider value of which to be get.
*
* \return The divider value for the clock GR.
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_SysClk_GetClkGrDiv(uint32_t clkGR)
{
    return((uint8_t)PERI->GR[clkGR].unCLOCK_CTL.stcField.u8INT8_DIV);
}

/** \} group_sysclk_clk_gr_funcs */
/*******************************************************************************
* Function Name: Cy_SysClk_PeriphAssignDivider
****************************************************************************//**
*
* Assigns a programmable divider to a selected IP block, such as a TCPWM or SCB.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphAssignDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType,
                                                   uint32_t dividerNum)
{
    if(Cy_SysClk_CheckDividerExisting(dividerType, dividerNum) == CY_DIVIDER_NOT_EXISTING)
    {
        return CY_SYSCLK_BAD_PARAM;
    }

    un_PERI_CLOCK_CTL_t tempCLOCK_CTL_RegValue;
    tempCLOCK_CTL_RegValue.u32Register         = PERI->unCLOCK_CTL[ipBlock].u32Register;
    tempCLOCK_CTL_RegValue.stcField.u2TYPE_SEL = dividerType;
    tempCLOCK_CTL_RegValue.stcField.u8DIV_SEL  = dividerNum;
    PERI->unCLOCK_CTL[ipBlock].u32Register     = tempCLOCK_CTL_RegValue.u32Register;

    return CY_SYSCLK_SUCCESS;

}

/*******************************************************************************
* Function Name: Cy_SysClk_PeriphGetAssignedDivider
****************************************************************************//**
*
* Reports which clock divider is assigned to a selected IP block.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \return The divider type and number, where bits [7:6] = type, bits[5:0] = divider
* number within that type
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_PeriphGetAssignedDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t *dividerType,
                                                   uint32_t *dividerNum)
{
    CY_ASSERT(ipBlock < PERI_CLOCK_NR);
    *dividerType = (cy_en_divider_types_t )PERI->unCLOCK_CTL[ipBlock].stcField.u2TYPE_SEL;
    *dividerNum  = PERI->unCLOCK_CTL[ipBlock].stcField.u8DIV_SEL;

    return;
}

/*******************************************************************************
* Function Name: Cy_SysClk_PeriphEnableDivider
****************************************************************************//**
*
* Enables the selected divider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \note This function also sets the phase alignment bits such that the enabled
* divider is aligned to clk_peri. See \ref Cy_SysClk_PeriphPhaseDisableDivider()
* for information on how to phase-align a divider after it is enabled.
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphEnableDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum)
{

    if(Cy_SysClk_CheckDividerExisting(dividerType, dividerNum) == CY_DIVIDER_NOT_EXISTING)
    {
        return CY_SYSCLK_BAD_PARAM;
    }

    /* specify the divider, make the reference = clk_peri, and enable the divider */
    un_PERI_DIV_CMD_t tempDIV_CMD_RegValue;
    tempDIV_CMD_RegValue.u32Register            = PERI->unDIV_CMD.u32Register;
    tempDIV_CMD_RegValue.stcField.u1ENABLE      = 1ul;
    tempDIV_CMD_RegValue.stcField.u2PA_TYPE_SEL = 3ul;
    tempDIV_CMD_RegValue.stcField.u8PA_DIV_SEL  = 0xFFul;
    tempDIV_CMD_RegValue.stcField.u2TYPE_SEL    = dividerType;
    tempDIV_CMD_RegValue.stcField.u8DIV_SEL     = dividerNum;
    PERI->unDIV_CMD.u32Register                 = tempDIV_CMD_RegValue.u32Register;

    (void)PERI->unDIV_CMD; /* dummy read to handle buffered writes */

    return CY_SYSCLK_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SysClk_PeriphDisableDivider
****************************************************************************//**
*
* Disables the selected divider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t.
*
* \param dividerNum specifies which divider of the selected type to configure.
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphDisableDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    if(Cy_SysClk_CheckDividerExisting(dividerType, dividerNum) == CY_DIVIDER_NOT_EXISTING)
    {
        return CY_SYSCLK_BAD_PARAM;
    }

    /* specify the divider, make the reference = clk_peri, and disable the divider */
    un_PERI_DIV_CMD_t tempDIV_CMD_RegValue;
    tempDIV_CMD_RegValue.u32Register            = PERI->unDIV_CMD.u32Register;
    tempDIV_CMD_RegValue.stcField.u1DISABLE     = 1ul;
    tempDIV_CMD_RegValue.stcField.u2PA_TYPE_SEL = 3ul;
    tempDIV_CMD_RegValue.stcField.u8PA_DIV_SEL  = 0xFFul;
    tempDIV_CMD_RegValue.stcField.u2TYPE_SEL    = dividerType;
    tempDIV_CMD_RegValue.stcField.u8DIV_SEL     = dividerNum;
    PERI->unDIV_CMD.u32Register                 = tempDIV_CMD_RegValue.u32Register;
    (void)PERI->unDIV_CMD; /* dummy read to handle buffered writes */

    return CY_SYSCLK_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SysClk_PeriphPhaseDisableDivider
****************************************************************************//**
*
* Disables a selected divider, preparatory to aligning it with another divider;
* see \ref Cy_SysClk_PeriphPhaseAlignDivider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t.
*
* \param dividerNum specifies which divider of the selected type to configure.
*
* \note
* To phase-align a divider, do the following:<br>
* 1. Call this function.<br>
* 2. Call the appropriate Cy_SysClk_PeriphSet...Divider function to configure the
*    divider.<br>
* 3. Call Cy_SysClk_PeriphPhaseAlignDivider to enable the divider and do the phase
*    alignment.
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphPhaseDisableDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    if(Cy_SysClk_CheckDividerExisting(dividerType, dividerNum) == CY_DIVIDER_NOT_EXISTING)
    {
        return CY_SYSCLK_BAD_PARAM;
    }

    /* specify the divider and disable it */
    un_PERI_DIV_CMD_t tempDIV_CMD_RegValue;
    tempDIV_CMD_RegValue.u32Register         = PERI->unDIV_CMD.u32Register;
    tempDIV_CMD_RegValue.stcField.u1DISABLE  = 1ul;
    tempDIV_CMD_RegValue.stcField.u2TYPE_SEL = dividerType;
    tempDIV_CMD_RegValue.stcField.u8DIV_SEL  = dividerNum;
    PERI->unDIV_CMD.u32Register              = tempDIV_CMD_RegValue.u32Register;
    (void)PERI->unDIV_CMD; /* dummy read to handle buffered writes */

    return CY_SYSCLK_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SysClk_PeriphPhaseAlignDivider
****************************************************************************//**
*
* First disables a selected divider (\ref Cy_SysClk_PeriphPhaseDisableDivider),
* then aligns that divider to another programmable divider, and enables the
* selected divider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t.
*
* \param dividerNum specifies which divider of the selected type to configure.
*
* \param dividerTypePA type of divider to phase-align to; \ref cy_en_divider_types_t.
*
* \param dividerNumPA divider number of type specified to phase align to.
*
* \note
* To phase-align a divider to clk_peri, set dividerTypePA to 3 and dividerNumPA
* to 63.
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PeriphPhaseAlignDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                                       cy_en_divider_types_t dividerTypePA, uint32_t dividerNumPA)
{
    if(Cy_SysClk_CheckDividerExisting(dividerType, dividerNum) == CY_DIVIDER_NOT_EXISTING)
    {
        return CY_SYSCLK_BAD_PARAM;
    }

    if(Cy_SysClk_CheckDividerExisting(dividerTypePA, dividerNumPA) == CY_DIVIDER_NOT_EXISTING)
    {
        return CY_SYSCLK_BAD_PARAM;
    }

    /* first disable the divider that is to be phase-aligned */
    Cy_SysClk_PeriphPhaseDisableDivider(dividerType, dividerNum);
    /* then specify the reference divider, and the divider, and enable the divider */
    un_PERI_DIV_CMD_t tempDIV_CMD_RegValue;
    tempDIV_CMD_RegValue.u32Register            = PERI->unDIV_CMD.u32Register;
    tempDIV_CMD_RegValue.stcField.u1ENABLE      = 1ul;
    tempDIV_CMD_RegValue.stcField.u2PA_TYPE_SEL = dividerTypePA;
    tempDIV_CMD_RegValue.stcField.u8PA_DIV_SEL  = dividerNumPA;
    tempDIV_CMD_RegValue.stcField.u2TYPE_SEL    = dividerType;
    tempDIV_CMD_RegValue.stcField.u8DIV_SEL     = dividerNum;
    PERI->unDIV_CMD.u32Register                 = tempDIV_CMD_RegValue.u32Register;
    (void)PERI->unDIV_CMD; /* dummy read to handle buffered writes */

    return CY_SYSCLK_SUCCESS;

}
/** \} group_sysclk_clk_peripheral_funcs */


/* ========================================================================== */
/* =========================    clk_slow SECTION    ========================= */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_slow_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_SlowClkSetDivider(uint32_t divider);
__STATIC_INLINE uint32_t Cy_SysClk_SlowClkGetDivider(void);

/*******************************************************************************
* Function Name: Cy_SysClk_SlowClkSetDivider
****************************************************************************//**
*
* Sets the clock divider for the slow clock. The source of this clock is the
* peripheral clock (ClkPeri), which is sourced from hf_clk[0].
*
* \param divider Divider value between 0 and 255.
* Causes integer division of (divider value + 1), or division by 1 to 256.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_SlowClkSetDivider(uint32_t divider)
{
    CPUSS->unCM0_CLOCK_CTL.stcField.u8SLOW_INT_DIV = divider;
}

/*******************************************************************************
* Function Name: Cy_SysClk_SlowClkGetDivider
****************************************************************************//**
*
* Reports the divider value for the slow clock.
*
* \return The divider value.
* The integer division done is by (divider value + 1), or division by 1 to 256.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_SlowClkGetDivider(void)
{
    return CPUSS->unCM0_CLOCK_CTL.stcField.u8SLOW_INT_DIV;
}
/** \} group_sysclk_clk_slow_funcs */


/* ========================================================================== */
/* ==========================    clk_lf SECTION    ========================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_lf_enums
* \{
*/
/**
* Low frequency (lf_clk) input sources. See CLK_SELECT register, LFCLK_SEL bits.
* Used with functions \ref Cy_SysClk_LfClkSetSource, and \ref Cy_SysClk_LfClkGetSource.
*/
typedef enum
{
    CY_SYSCLK_LFCLK_IN_ILO0            = 0u, /**< lf_clk is sourced by the internal low speed oscillator (ILO0) */
    CY_SYSCLK_LFCLK_IN_WCO             = 1u, /**< lf_clk is sourced by the watch crystal oscillator (WCO) */
    CY_SYSCLK_LFCLK_IN_ILO1            = 4u, /**< lf_clk is sourced by the internal low speed oscillator (ILO1) */
    CY_SYSCLK_LFCLK_IN_ECO_PRESCALE    = 5u, /**< lf_clk is sourced by the external crystal oscillator prescaler */
#if defined(SRSS_BACKUP_S40E_LPECO_PRESENT) && (SRSS_BACKUP_S40E_LPECO_PRESENT == 1)
    CY_SYSCLK_LFCLK_IN_LPECO_PRESCALER = 6u, /**< lf_clk is sourced by the Low-Power External-Crystal Oscillator after prescaling */
#endif
} cy_en_lfclk_input_sources_t;
/** \} group_sysclk_clk_lf_enums */

/**
* \addtogroup group_sysclk_clk_lf_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_LfClkSetSource(cy_en_lfclk_input_sources_t source);
__STATIC_INLINE cy_en_lfclk_input_sources_t Cy_SysClk_LfClkGetSource(void);

/*******************************************************************************
* Function Name: Cy_SysClk_LfClkSetSource
****************************************************************************//**
*
* Sets the source for the low frequency clock(lf_clk).
*
* \param source \ref cy_en_lfclk_input_sources_t
*
* \note The watchdog timer (WDT) must be unlocked before calling this function.
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_LfClkSetSource(cy_en_lfclk_input_sources_t source)
{
    SRSS->unCLK_SELECT.stcField.u3LFCLK_SEL = source;
}

/*******************************************************************************
* Function Name: Cy_SysClk_LfClkGetSource
****************************************************************************//**
*
* Reports the source for the low frequency clock (lf_clk).
*
* \return \ref cy_en_lfclk_input_sources_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_lfclk_input_sources_t Cy_SysClk_LfClkGetSource(void)
{
    return (cy_en_lfclk_input_sources_t)SRSS->unCLK_SELECT.stcField.u3LFCLK_SEL;
}
/** \} group_sysclk_clk_lf_funcs */


/* ========================================================================== */
/* ========================    clk_timer SECTION    ========================= */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_timer_enums
* \{
*/
/**
* Timer clock (clk_timer) input sources. See CLK_TIMER_CTL register, TIMER_SEL
* and TIMER_HF0_DIV bits. Used with functions \ref Cy_SysClk_ClkTimerSetSource, and
* \ref Cy_SysClk_ClkTimerGetSource.
*/
typedef enum
{
    CY_SYSCLK_CLKTIMER_IN_IMO       =     0u, /**< clk_timer is sourced by the internal main oscillator (IMO) */
    CY_SYSCLK_CLKTIMER_IN_HF0_NODIV =     1u, /**< clk_timer is sourced by clk_hf0 undivided */
    CY_SYSCLK_CLKTIMER_IN_HF0_DIV2  = 0x101u, /**< clk_timer is sourced by clk_hf0 divided by 2 */
    CY_SYSCLK_CLKTIMER_IN_HF0_DIV4  = 0x201u, /**< clk_timer is sourced by clk_hf0 divided by 4 */
    CY_SYSCLK_CLKTIMER_IN_HF0_DIV8  = 0x301u  /**< clk_timer is sourced by clk_hf0 divided by 8 */
} cy_en_clktimer_input_sources_t;
/** \} group_sysclk_clk_timer_enums */

/**
* \addtogroup group_sysclk_clk_timer_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_ClkTimerSetSource(cy_en_clktimer_input_sources_t source);
__STATIC_INLINE cy_en_clktimer_input_sources_t Cy_SysClk_ClkTimerGetSource(void);
__STATIC_INLINE void Cy_SysClk_ClkTimerSetDivider(uint32_t divider);
__STATIC_INLINE uint32_t Cy_SysClk_ClkTimerGetDivider(void);
__STATIC_INLINE void Cy_SysClk_ClkTimerEnable(void);
__STATIC_INLINE void Cy_SysClk_ClkTimerDisable(void);

/*******************************************************************************
* Function Name: Cy_SysClk_ClkTimerSetSource
****************************************************************************//**
*
* Sets the source for the timer clock (clk_timer). The timer clock can be used
* as a source for SYSTICK and one or more of the energy profiler counters.
*
* \param source \ref cy_en_clktimer_input_sources_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ClkTimerSetSource(cy_en_clktimer_input_sources_t source)
{
    /* set both fields TIMER_SEL and TIMER_HF0_DIV with the same input value */
    SRSS->unCLK_TIMER_CTL.u32Register = (uint32_t)source;
}

/*******************************************************************************
* Function Name: Cy_SysClk_ClkTimerGetSource
****************************************************************************//**
*
* Reports the source for the timer clock (clk_timer).
*
* \return \ref cy_en_clktimer_input_sources_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_clktimer_input_sources_t Cy_SysClk_ClkTimerGetSource(void)
{
    /* return both fields TIMER_SEL and TIMER_HF0_DIV as a single combined value */
    return (cy_en_clktimer_input_sources_t)
           (SRSS->unCLK_TIMER_CTL.u32Register & (SRSS_CLK_TIMER_CTL_TIMER_SEL_Msk | SRSS_CLK_TIMER_CTL_TIMER_HF0_DIV_Msk));
}

/*******************************************************************************
* Function Name: Cy_SysClk_ClkTimerSetDivider
****************************************************************************//**
*
* Sets the divider for the timer clock (clk_timer).
*
* \param divider Divider value; valid range is 0 to 255. Divides the selected
* source (\ref Cy_SysClk_ClkTimerSetSource) by the (value + 1).
*
* \note
* Do not change the divider value while the timer clock is enabled.
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ClkTimerSetDivider(uint32_t divider)
{
    SRSS->unCLK_TIMER_CTL.stcField.u8TIMER_DIV = divider;
}

/*******************************************************************************
* Function Name: Cy_SysClk_ClkTimerGetDivider
****************************************************************************//**
*
* Reports the divider value for the timer clock (clk_timer).
*
* \return The divider value
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_ClkTimerGetDivider(void)
{
    return (uint32_t)SRSS->unCLK_TIMER_CTL.stcField.u8TIMER_DIV;
}

/*******************************************************************************
* Function Name: Cy_SysClk_ClkTimerEnable
****************************************************************************//**
*
* Enables the timer clock (clk_timer). The timer clock can be used as a source
* for SYSTICK and one or more of the energy profiler counters.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ClkTimerEnable(void)
{
    SRSS->unCLK_TIMER_CTL.stcField.u1ENABLE = 1ul; /* 1 = enable */
}

/*******************************************************************************
* Function Name: Cy_SysClk_ClkTimerDisable
****************************************************************************//**
*
* Disables the timer clock (clk_timer).
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ClkTimerDisable(void)
{
    SRSS->unCLK_TIMER_CTL.stcField.u1ENABLE = 0ul; /* 0 = disable */
}
/** \} group_sysclk_clk_timer_funcs */


/* ========================================================================== */
/* =========================    clk_pump SECTION    ========================= */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_pump_enums
* \{
*/
/**
* Pump clock (clk_pump) input sources. See CLK_SELECT register, PUMP_SEL bits.
* Used with functions \ref Cy_SysClk_ClkPumpSetSource, and
* \ref Cy_SysClk_ClkPumpGetSource.
*/
typedef enum
{
    CY_SYSCLK_PUMP_IN_CLKPATH0  = 0u,  /**< Pump clock input is clock path 0 */
    CY_SYSCLK_PUMP_IN_CLKPATH1  = 1u,  /**< Pump clock input is clock path 1 */
    CY_SYSCLK_PUMP_IN_CLKPATH2  = 2u,  /**< Pump clock input is clock path 2 */
    CY_SYSCLK_PUMP_IN_CLKPATH3  = 3u,  /**< Pump clock input is clock path 3 */
    CY_SYSCLK_PUMP_IN_CLKPATH4  = 4u,  /**< Pump clock input is clock path 4 */
    CY_SYSCLK_PUMP_IN_CLKPATH5  = 5u,  /**< Pump clock input is clock path 5 */
    CY_SYSCLK_PUMP_IN_CLKPATH6  = 6u,  /**< Pump clock input is clock path 6 */
    CY_SYSCLK_PUMP_IN_CLKPATH7  = 7u,  /**< Pump clock input is clock path 7 */
    CY_SYSCLK_PUMP_IN_CLKPATH8  = 8u,  /**< Pump clock input is clock path 8 */
    CY_SYSCLK_PUMP_IN_CLKPATH9  = 9u,  /**< Pump clock input is clock path 9 */
    CY_SYSCLK_PUMP_IN_CLKPATH10 = 10u, /**< Pump clock input is clock path 10 */
    CY_SYSCLK_PUMP_IN_CLKPATH11 = 11u, /**< Pump clock input is clock path 11 */
    CY_SYSCLK_PUMP_IN_CLKPATH12 = 12u, /**< Pump clock input is clock path 12 */
    CY_SYSCLK_PUMP_IN_CLKPATH13 = 13u, /**< Pump clock input is clock path 13 */
    CY_SYSCLK_PUMP_IN_CLKPATH14 = 14u, /**< Pump clock input is clock path 14 */
    CY_SYSCLK_PUMP_IN_CLKPATH15 = 15u  /**< Pump clock input is clock path 15 */
} cy_en_clkpump_input_sources_t;

/**
* Pump clock (clk_pump) divide options. See CLK_SELECT register, PUMP_DIV bits.
* Used with functions \ref Cy_SysClk_ClkPumpSetDivider, and
* \ref Cy_SysClk_ClkPumpGetDivider.
*/
typedef enum
{
    CY_SYSCLK_PUMP_NO_DIV = 0u, /**< No division on pump clock */
    CY_SYSCLK_PUMP_DIV_2  = 1u, /**< Pump clock divided by 2 */
    CY_SYSCLK_PUMP_DIV_4  = 2u, /**< Pump clock divided by 4 */
    CY_SYSCLK_PUMP_DIV_8  = 3u, /**< Pump clock divided by 8 */
    CY_SYSCLK_PUMP_DIV_16 = 4u  /**< Pump clock divided by 16 */
} cy_en_clkpump_divide_t;
/** \} group_sysclk_clk_pump_enums */

/**
* \addtogroup group_sysclk_clk_pump_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_ClkPumpSetSource(cy_en_clkpump_input_sources_t source);
__STATIC_INLINE cy_en_clkpump_input_sources_t Cy_SysClk_ClkPumpGetSource(void);
__STATIC_INLINE void Cy_SysClk_ClkPumpSetDivider(cy_en_clkpump_divide_t divider);
__STATIC_INLINE cy_en_clkpump_divide_t Cy_SysClk_ClkPumpGetDivider(void);
__STATIC_INLINE void Cy_SysClk_ClkPumpEnable(void);
__STATIC_INLINE void Cy_SysClk_ClkPumpDisable(void);

/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpSetSource
****************************************************************************//**
*
* Sets the source for the pump clock (clk_pump). The pump clock can be used for
* the analog pumps in the CTBm block.
*
* \param source \ref cy_en_clkpump_input_sources_t
*
* \note
* Do not change the source while the pump clock is enabled.
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ClkPumpSetSource(cy_en_clkpump_input_sources_t source)
{
    SRSS->unCLK_SELECT.stcField.u4PUMP_SEL = source;
}

/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpGetSource
****************************************************************************//**
*
* Reports the source for the pump clock (clk_pump).
*
* \return \ref cy_en_clkpump_input_sources_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_clkpump_input_sources_t Cy_SysClk_ClkPumpGetSource(void)
{
    return (cy_en_clkpump_input_sources_t)SRSS->unCLK_SELECT.stcField.u4PUMP_SEL;
}

/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpSetDivider
****************************************************************************//**
*
* Sets the divider of the pump clock (clk_pump).
*
* \param divider \ref cy_en_clkpump_divide_t
*
* \note
* Do not change the divider value while the pump clock is enabled.
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ClkPumpSetDivider(cy_en_clkpump_divide_t divider)
{
    SRSS->unCLK_SELECT.stcField.u3PUMP_DIV = divider;
}

/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpGetDivider
****************************************************************************//**
*
* Reports the divider value for the pump clock (clk_pump).
*
* \return \ref cy_en_clkpump_divide_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_clkpump_divide_t Cy_SysClk_ClkPumpGetDivider(void)
{
    return (cy_en_clkpump_divide_t)SRSS->unCLK_SELECT.stcField.u3PUMP_DIV;
}

/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpEnable
****************************************************************************//**
*
* Enables the pump clock (clk_pump). The pump clock can be used for the analog
* pumps in the CTBm block.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ClkPumpEnable(void)
{
    SRSS->unCLK_SELECT.stcField.u1PUMP_ENABLE = 1ul; /* 1 = enable */
}

/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpDisable
****************************************************************************//**
*
* Disables the pump clock (clk_pump).
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ClkPumpDisable(void)
{
    SRSS->unCLK_SELECT.stcField.u1PUMP_ENABLE = 0ul; /* 0 = disable */
}
/** \} group_sysclk_clk_pump_funcs */


/* ========================================================================== */
/* ==========================    clk_bak SECTION    ========================= */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_bak_enums
* \{
*/
/**
* Backup domain clock (clk_bak) input sources. See BACKUP->unCTL register,
* CLK_SEL bits. Used with functions \ref Cy_SysClk_ClkBakSetSource, and
* \ref Cy_SysClk_ClkBakGetSource.
*/
typedef enum
{
    CY_SYSCLK_BAK_IN_WCO             = 0u, /**< Backup domain clock input is WCO */
    CY_SYSCLK_BAK_IN_ALTBAK          = 1u, /**< Backup domain clock input is ALTBAK */
    CY_SYSCLK_BAK_IN_ILO             = 2u, /**< Backup domain clock input is ILO */
#if defined(SRSS_BACKUP_S40E_LPECO_PRESENT) && (SRSS_BACKUP_S40E_LPECO_PRESENT == 1)
    CY_SYSCLK_BAK_IN_LPECO_PRESCALER = 3u, /**< Backup domain clock input is LPECO */
#endif
} cy_en_clkbak_input_sources_t;
/** \} group_sysclk_clk_bak_enums */

/**
* \addtogroup group_sysclk_clk_bak_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_ClkBakSetSource(cy_en_clkbak_input_sources_t source);
__STATIC_INLINE cy_en_clkbak_input_sources_t Cy_SysClk_ClkBakGetSource(void);

/*******************************************************************************
* Function Name: Cy_SysClk_ClkBakSetSource
****************************************************************************//**
*
* Sets the source for the backup domain clock (clk_bak).
*
* \param source \ref cy_en_clkbak_input_sources_t
*
* \note
* Clk_lf is not available in all power modes.  For this reason, WCO is the
* preferred source. If the WCO is routed through the clk_lf multiplexer
* (see \ref Cy_SysClk_LfClkSetSource), select WCO directly - do not select clk_lf.
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ClkBakSetSource(cy_en_clkbak_input_sources_t source)
{
    BACKUP->unCTL.stcField.u2CLK_SEL = source;
}

/*******************************************************************************
* Function Name: Cy_SysClk_ClkBakGetSource
****************************************************************************//**
*
* Reports the source for the backup domain clock (clk_bak).
*
* \return \ref cy_en_clkbak_input_sources_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_clkbak_input_sources_t Cy_SysClk_ClkBakGetSource(void)
{
    return (cy_en_clkbak_input_sources_t)BACKUP->unCTL.stcField.u2CLK_SEL;
}
/** \} group_sysclk_clk_bak_funcs */

typedef enum
{
    CY_SYSCLK_CLKREF_IN_IMO    = 0u, /**< clk_ref_hf source is the internal R/C Oscillator (IMO) */
    CY_SYSCLK_CLKREF_IN_EXTCLK = 1u, /**< clk_ref_hf source is the external clock (EXTCLK) */
    CY_SYSCLK_CLKREF_IN_ECO    = 2u, /**< clk_ref_hf source is the external crystal oscillator (ECO) */
} cy_en_clkref_input_sources_t;

/*******************************************************************************
* Function Name: Cy_SysClk_ClkRefSetSource
****************************************************************************//**
*
* Reports the source for the backup domain clock (clk_bak).
*
* \return \ref cy_en_clkbak_input_sources_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ClkRefSetSource(cy_en_clkref_input_sources_t source)
{
    SRSS->unCSV_REF_SEL.stcField.u3REF_MUX = source;
}


/*******************************************************************************
* Function Name: Cy_SysClk_ClkRefGetSource
****************************************************************************//**
*
* Reports the source for the backup domain clock (clk_bak).
*
* \return \ref cy_en_clkbak_input_sources_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_clkref_input_sources_t Cy_SysClk_ClkRefGetSource(void)
{
     return (cy_en_clkref_input_sources_t)SRSS->unCSV_REF_SEL.stcField.u3REF_MUX;
}


typedef struct
{
    uint32_t clk_imo_freq;  /**< IMO frequency of the system */
    uint32_t clk_ext_freq;  /**< External clock frequency being input */
    uint32_t clk_eco_freq;  /**< ECO frequency of the system */
    uint32_t clk_ilo0_freq; /**< ILO0 frequency of the system */
    uint32_t clk_ilo1_freq; /**< ILO1 frequency of the system */
    uint32_t clk_wco_freq;  /**< WCO frequency of the system */
} cy_stc_base_clk_freq_t;


cy_en_sysclk_status_t Cy_SysClk_InitGetFreqParams(cy_stc_base_clk_freq_t *in);
cy_en_sysclk_status_t Cy_SysClk_GetImoFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetEcoFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetExtFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetIlo0Frequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetIlo1Frequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetWcoFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetRefHfFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetPathSourceFrequency(uint8_t pathNo, uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetFllInputFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetPllInputFrequency(uint32_t pllNo, uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetFllOutputFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetPllOutputFrequency(uint8_t pllNo, uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetPathFrequency(uint8_t pathNo, uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetHfClkFrequency(cy_en_hfclk_t hfClkNo, uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetWDTClkFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetRTCClkFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetEcoPrescaleFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetLfFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetMTWDTFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetTimerFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetFastFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetClkPeriFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetClkSlowFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetCoreFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetSystickFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetGroupFrequency(uint32_t clkGR, uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetFlashInterfaceFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetRamFastFrequency(uint32_t ramNo, uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetRamSlowFrequency(uint32_t ramNo, uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetRomFastFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_GetRomSlowFrequency(uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_PeriphGetFrequency(en_clk_dst_t ipBlock, uint32_t *result);
cy_en_sysclk_status_t Cy_SysClk_PeriphSetFracDividerAuto(cy_en_divider_types_t dividerType, uint32_t dividerNum, uint32_t targetFreq, uint32_t *targetResutFreq);




#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* __CY_SYSCLK_H__ */

/** \} group_sysclk */


/* [] END OF FILE */
