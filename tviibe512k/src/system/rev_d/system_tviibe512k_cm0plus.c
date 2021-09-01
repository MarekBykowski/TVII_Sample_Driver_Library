/***************************************************************************//**
* \file system_tviibe512k_cm0plus.c
* \version 1.0
*
* The device system-source file.
*
********************************************************************************
* \copyright
* Copyright 2018-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "cy_device_headers.h"
#include "cy_project.h"


#if CY_SYSTEM_USE_CLOCK == CY_SYSTEM_USE_ECO
    #define CY_SYSTEM_PLL_INPUT_SOURCE       CY_SYSCLK_CLKPATH_IN_ECO

    // Reference divider value:  2
    // Feed back divider value: 40
    // Out put divider value  :  2
    // PLL_OUT = 16,000,000(Feco) / 2 * 40 / 2 = 160,000,000Hz
    // Restriction: 300,000,000 < Fvco < 400,000,000
    // This time, Fvco = 16,000,000 *40 /2 = 320,000,000.
    #define CY_SYSTEM_PLL_CONFIG_REFDIV      (2UL)
    #define CY_SYSTEM_PLL_CONFIG_FEEDBACKDIV (40UL)
    #define CY_SYSTEM_PLL_CONFIG_OUTDIV      (2UL)
    
    
#elif CY_SYSTEM_USE_CLOCK == CY_SYSTEM_USE_IMO
    #define CY_SYSTEM_PLL_INPUT_SOURCE CY_SYSCLK_CLKPATH_IN_IMO

    // Reference divider value:  1
    // Feed back divider value: 40
    // Out put divider value  :  2
    // PLL_OUT = 8,000,000(Fimo) / 1 * 40 / 2 = 160,000,000Hz

    // Restriction: 300,000,000 < Fvco < 400,000,000
    // This time, Fvco = 8,000,000 * 40 / 1 = 320,000,000.
    #define CY_SYSTEM_PLL_CONFIG_REFDIV      (1UL)
    #define CY_SYSTEM_PLL_CONFIG_FEEDBACKDIV (40UL)
    #define CY_SYSTEM_PLL_CONFIG_OUTDIV      (2UL)
#elif CY_SYSTEM_USE_CLOCK == CY_SYSTEM_USE_EXT

    #warning "Not implemented yet!!"

#endif


#define CY_SYS_PWR_CTL_KEY_OPEN  (0x05FAUL)
#define CY_SYS_PWR_CTL_KEY_CLOSE (0xFA05UL)


/** Holds the SlowClk system core clock, which is the system clock frequency supplied to the SysTick timer and the
* processor core clock. This variable can be used by debuggers to query the frequency of the debug timer or to configure
* the trace clock speed.
*
* \attention Compilers must be configured to avoid removing this variable in case the application program is not using
* it. Debugging systems require the variable to be physically present in memory so that it can be examined to configure
* the debugger. */
uint32_t SystemCoreClock  = 0UL;

uint32_t cy_delayFreqHz   = 0UL;

uint32_t cy_delayFreqKhz  = 0UL;

uint8_t cy_delayFreqMhz   = 0UL;

uint32_t cy_delay32kMs    = 0UL;


/*******************************************************************************
* Function Name: SystemInit
****************************************************************************//**
*
* Initializes the system
*
*******************************************************************************/
void SystemInit (void)
{
#if defined(CY_SYSTEM_WDT_DISABLE)
    /* disable WDT */
    Cy_WDT_Disable();
#endif /* CY_SYSTEM_WDT_DISABLE */
    
#if (CY_USE_PSVP == 0u)
      
    /*********** Setting wait state for ROM **********/
    CPUSS->unROM_CTL.stcField.u2SLOW_WS = 1u;
    CPUSS->unROM_CTL.stcField.u2FAST_WS = 0u;

    /*********** Setting wait state for RAM **********/
    CPUSS->unRAM0_CTL0.stcField.u2SLOW_WS = 1u;
    CPUSS->unRAM0_CTL0.stcField.u2FAST_WS = 0u;

    #if defined (CPUSS_RAMC1_PRESENT) && (CPUSS_RAMC1_PRESENT == 1UL)
    CPUSS->unRAM1_CTL0.stcField.u2SLOW_WS = 1u;
    CPUSS->unRAM1_CTL0.stcField.u2FAST_WS = 0u;
    #endif /* defined (CPUSS_RAMC1_PRESENT) && (CPUSS_RAMC1_PRESENT == 1UL) */

    #if defined (CPUSS_RAMC2_PRESENT) && (CPUSS_RAMC2_PRESENT == 1UL)
    CPUSS->unRAM2_CTL0.stcField.u2SLOW_WS = 1u;
    CPUSS->unRAM2_CTL0.stcField.u2FAST_WS = 0u;
    #endif /* defined (CPUSS_RAMC2_PRESENT) && (CPUSS_RAMC2_PRESENT == 1UL) */

    /*********** Setting wait state for FLASH **********/
    FLASHC->unFLASH_CTL.stcField.u4MAIN_WS = 1u;

    /***    Set clock LF source        ***/
    SRSS->unCLK_SELECT.stcField.u3LFCLK_SEL = CY_SYSCLK_LFCLK_IN_ILO0;

#if CY_SYSTEM_USE_CLOCK == CY_SYSTEM_USE_ECO

    /***    ECO port settings        ***/
    /* Default settings should be OK. */

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

#if defined(CY_SYSTEM_WCO_ENABLE)

    // Enable WCO
    BACKUP->unCTL.stcField.u1WCO_EN = 1ul;

    // Wait until WCO status becomes OK
    while(BACKUP->unSTATUS.stcField.u1WCO_OK == 0ul);

#endif

    /***  Set CPUSS dividrs as required        ***/
    // FAST = 160,000,000; PERI and SLOW = FAST / 2;
    CPUSS->unCM4_CLOCK_CTL.stcField.u8FAST_INT_DIV = 0u; // no division
    CPUSS->unCM0_CLOCK_CTL.stcField.u8PERI_INT_DIV = 1u; // divided by 2
    CPUSS->unCM0_CLOCK_CTL.stcField.u8SLOW_INT_DIV = 0u; // no division

    /***     PLL setting and enabling        ***/
    SRSS->unCLK_PATH_SELECT[1/*PLL0*/].stcField.u3PATH_MUX = CY_SYSTEM_PLL_INPUT_SOURCE;
    SRSS->unCLK_PLL_CONFIG[0].stcField.u5REFERENCE_DIV     = CY_SYSTEM_PLL_CONFIG_REFDIV; 
    SRSS->unCLK_PLL_CONFIG[0].stcField.u7FEEDBACK_DIV      = CY_SYSTEM_PLL_CONFIG_FEEDBACKDIV; 
    SRSS->unCLK_PLL_CONFIG[0].stcField.u5OUTPUT_DIV        = CY_SYSTEM_PLL_CONFIG_OUTDIV; 
    SRSS->unCLK_PLL_CONFIG[0].stcField.u1ENABLE            = 1ul;
    while(SRSS->unCLK_PLL_STATUS[0].stcField.u1LOCKED == 0ul);

    /***   Setting  PATH2  source        ***/
    SRSS->unCLK_PATH_SELECT[2].stcField.u3PATH_MUX = CY_SYSCLK_CLKPATH_IN_IMO;

    /***  Assign  PLL0 as source of clk_hf0        ***/
    /* Select source of clk_hf0 */
    /***  Set HF source, divider, enable   ***/
    SRSS->unCLK_ROOT_SELECT[0/*clk_hf0*/].stcField.u4ROOT_MUX = CY_SYSCLK_HFCLK_IN_CLKPATH1;
    SRSS->unCLK_ROOT_SELECT[0].stcField.u2ROOT_DIV = 0u; /* no div */
    SRSS->unCLK_ROOT_SELECT[0].stcField.u1ENABLE   = 1u; /* 1 = enable */

    /* Select source of clk_hf1 */
    /***  Set HF1 source, divider, enable   ***/
    SRSS->unCLK_ROOT_SELECT[1/*clk_hf1*/].stcField.u4ROOT_MUX = CY_SYSCLK_HFCLK_IN_CLKPATH1;
    SRSS->unCLK_ROOT_SELECT[1].stcField.u2ROOT_DIV = 0u; /* no div */
    SRSS->unCLK_ROOT_SELECT[1].stcField.u1ENABLE   = 1u; /* 1 = enable */

    /***     Enabling ILO0        ***/
    Cy_WDT_Unlock();
    SRSS->unCLK_ILO0_CONFIG.stcField.u1ENABLE = 1;        /* 1 = enable */
    SRSS->unCLK_ILO0_CONFIG.stcField.u1ILO0_BACKUP = 1ul; /* Ilo HibernateOn */
    Cy_WDT_Lock();

#endif  // CY_USE_PSVP == 0u

    SystemCoreClockUpdate();
}

/*******************************************************************************
* Function Name: SystemCoreClockUpdate
****************************************************************************//**
*
* Updates variables with current clock settings
*
*******************************************************************************/
void SystemCoreClockUpdate (void)
{
    cy_stc_base_clk_freq_t freqInfo = 
    {
        .clk_imo_freq  = CY_CLK_IMO_FREQ_HZ,
        .clk_ext_freq  = CY_CLK_EXT_FREQ_HZ,
        .clk_eco_freq  = CY_CLK_ECO_FREQ_HZ,
        .clk_ilo0_freq = CY_CLK_HVILO0_FREQ_HZ,
        .clk_ilo1_freq = CY_CLK_HVILO1_FREQ_HZ,
        .clk_wco_freq  = CY_CLK_WCO_FREQ_HZ,
    };

    cy_en_sysclk_status_t retVal;
    retVal = Cy_SysClk_InitGetFreqParams(&freqInfo);
    CY_ASSERT(retVal == CY_SYSCLK_SUCCESS);
    retVal = Cy_SysClk_GetCoreFrequency(&SystemCoreClock);
    CY_ASSERT(retVal == CY_SYSCLK_SUCCESS);
	
    cy_delayFreqHz   = SystemCoreClock;
    cy_delayFreqMhz  = (uint8_t)((cy_delayFreqHz + CY_DELAY_1M_MINUS_1_THRESHOLD) / CY_DELAY_1M_THRESHOLD);
    cy_delayFreqKhz  = (cy_delayFreqHz + CY_DELAY_1K_MINUS_1_THRESHOLD) / CY_DELAY_1K_THRESHOLD;
    cy_delay32kMs    = CY_DELAY_MS_OVERFLOW_THRESHOLD * cy_delayFreqKhz;
}

/*******************************************************************************
* Function Name: Cy_SysGetApplCoreStatus
****************************************************************************//**
*
* Gets the Cortex-M4/M7 core power mode.
*
* \return \ref group_system_config_cm_status_macro
*
*******************************************************************************/
uint32_t Cy_SysGetApplCoreStatus(void)
{
    uint32_t regValue;
    
    /* Get current power mode */
    regValue = CPUSS->unCM4_PWR_CTL.u32Register;
    regValue = (regValue >> CPUSS_CM4_PWR_CTL_PWR_MODE_Pos) & CPUSS_CM4_PWR_CTL_PWR_MODE_Msk;

    return (regValue);
}

/*******************************************************************************
* Function Name: Cy_SysEnableApplCore
****************************************************************************//**
*
* Enables the Cortex-M4/M7 core. The CPU is enabled once if it was in the disabled
* or retained mode. 
*
* \param vectorTableOffset The offset of the vector table base address from
* memory address 0x00000000. The offset should be multiple to 1024 bytes.
*
*******************************************************************************/
void Cy_SysEnableApplCore(uint32_t vectorTableOffset)
{
    uint32_t cmStatus;
    uint32_t interruptState;
    un_CPUSS_CM4_PWR_CTL_t tPwrCtl;

    interruptState = Cy_SaveIRQ();
    
    cmStatus = Cy_SysGetApplCoreStatus();
    if(cmStatus == CY_SYS_CM_STATUS_ENABLED)
    {
        // do nothing
    }
    else
    {
        CPUSS->unCM4_VECTOR_TABLE_BASE.u32Register = vectorTableOffset;
    
        tPwrCtl.stcField.u16VECTKEYSTAT = CY_SYS_PWR_CTL_KEY_OPEN;
        tPwrCtl.stcField.u2PWR_MODE = CY_SYS_CM_STATUS_ENABLED;
        CPUSS->unCM4_PWR_CTL.u32Register = tPwrCtl.u32Register;
    }
    
    Cy_RestoreIRQ(interruptState);
}


/*******************************************************************************
* Function Name: Cy_SysDisableApplCore
****************************************************************************//**
*
* Disables the Cortex-M4 core.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the
* CPU.
*
*******************************************************************************/
void Cy_SysDisableApplCore(void)
{
    un_CPUSS_CM4_PWR_CTL_t tPwrCtl;

    tPwrCtl.stcField.u16VECTKEYSTAT = CY_SYS_PWR_CTL_KEY_OPEN;
    tPwrCtl.stcField.u2PWR_MODE = CY_SYS_CM_STATUS_OFF;
    CPUSS->unCM4_PWR_CTL.u32Register = tPwrCtl.u32Register;  
}


/*******************************************************************************
* Function Name: Cy_SysRetainApplCore
****************************************************************************//**
*
* Retains the Cortex-M4 core.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
void Cy_SysRetainApplCore(void)
{
    uint32_t cmStatus;
    uint32_t  interruptState;
    un_CPUSS_CM4_PWR_CTL_t tPwrCtl;

    interruptState = Cy_SaveIRQ();
	
    cmStatus = Cy_SysGetApplCoreStatus();
    if(cmStatus == CY_SYS_CM_STATUS_ENABLED)
    {
        tPwrCtl.stcField.u16VECTKEYSTAT = CY_SYS_PWR_CTL_KEY_OPEN;
        tPwrCtl.stcField.u2PWR_MODE = CY_SYS_CM_STATUS_RETAINED;
        CPUSS->unCM4_PWR_CTL.u32Register = tPwrCtl.u32Register;
    }
	
    Cy_RestoreIRQ(interruptState);
}


/*******************************************************************************
* Function Name: Cy_SysResetApplCore
****************************************************************************//**
*
* Resets the Cortex-M4 core.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
void Cy_SysResetApplCore(void)
{
    un_CPUSS_CM4_PWR_CTL_t tPwrCtl;

    tPwrCtl.stcField.u16VECTKEYSTAT = CY_SYS_PWR_CTL_KEY_OPEN;
    tPwrCtl.stcField.u2PWR_MODE = CY_SYS_CM_STATUS_RESET;
    CPUSS->unCM4_PWR_CTL.u32Register = tPwrCtl.u32Register;  
}

