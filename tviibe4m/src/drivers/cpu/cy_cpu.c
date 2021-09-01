/***************************************************************************//**
* \file cy_sysclk.c
* \version 1.0
*
* Provides an API implementation of the cpu driver.
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_cpu.h"
#include "syslib/cy_syslib.h"

#include <stdlib.h>

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */


/*******************************************************************************
* Function Name: Cy_Cpu_Cm4PowerModeSet
********************************************************************************
* \brief 
* Set the PWR_MODE bit.
*
* \param
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* Pwr Mode, refer to cy_en_cpu_power_mode_t.
*   CY_CPU_PM_OFF       = 0
*   CY_CPU_PM_RESET     = 1
*   CY_CPU_PM_RETAINED  = 2
*   CY_CPU_PM_ENABLED   = 3   
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_Cm4PowerModeSet(cy_en_cpu_core_type_t coreType, cy_en_cpu_power_mode_t pwrMode)
{
    switch(coreType)
    {
    case CY_CPU_CM4:
        CPUSS->unCM4_PWR_CTL.stcField.u2PWR_MODE = pwrMode;
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_Cm4PowerModeGet
********************************************************************************
* \brief 
* Get the PWR_MODE bit.
*
* \param
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
*
* \return
* Pwr Mode, refer to cy_en_cpu_power_mode_t.
*   CY_CPU_PM_OFF       = 0
*   CY_CPU_PM_RESET     = 1
*   CY_CPU_PM_RETAINED  = 2
*   CY_CPU_PM_ENABLED   = 3
*******************************************************************************/
cy_en_cpu_power_mode_t Cy_Cpu_Cm4PowerModeGet(cy_en_cpu_core_type_t coreType)
{
    cy_en_cpu_power_mode_t pwrMode = CY_CPU_PM_OFF;
    
    switch(coreType)
    {
    case CY_CPU_CM4:
        pwrMode = (cy_en_cpu_power_mode_t)CPUSS->unCM4_PWR_CTL.stcField.u2PWR_MODE;
        break;        
    default:
        break;      
    }
    
    return pwrMode;
}

/*******************************************************************************
* Function Name: Cy_Cpu_SramEccEnable
********************************************************************************
* \brief 
* Enable the ECC_EN bit.
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2   
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_SramEccEnable(cy_en_cpu_sram_macro_t sramType)
{
    switch(sramType)
    {
    case CY_CPU_SRAM0:
        CPUSS->unRAM0_CTL0.stcField.u1ECC_EN = 1;
        break;
    case CY_CPU_SRAM1:
        CPUSS->unRAM1_CTL0.stcField.u1ECC_EN = 1;
        break;   
    case CY_CPU_SRAM2:
        CPUSS->unRAM2_CTL0.stcField.u1ECC_EN = 1;
        break;
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_SramEccDisable
********************************************************************************
*
* \brief 
* Disable the ECC_EN bit.
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_SramEccDisable(cy_en_cpu_sram_macro_t sramType)
{
    switch(sramType)
    {
    case CY_CPU_SRAM0:
        CPUSS->unRAM0_CTL0.stcField.u1ECC_EN = 0;
        break;
    case CY_CPU_SRAM1:
        CPUSS->unRAM1_CTL0.stcField.u1ECC_EN = 0;
        break;   
    case CY_CPU_SRAM2:
        CPUSS->unRAM2_CTL0.stcField.u1ECC_EN = 0;
        break;
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_SramEccAutoCorrectionEnable
********************************************************************************
* \brief 
* Enable the ECC_AUTO_CORRECT bit.
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2 
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_SramEccAutoCorrectionEnable(cy_en_cpu_sram_macro_t sramType)
{
    switch(sramType)
    {
    case CY_CPU_SRAM0:
        CPUSS->unRAM0_CTL0.stcField.u1ECC_AUTO_CORRECT = 1;
        break;
    case CY_CPU_SRAM1:
        CPUSS->unRAM1_CTL0.stcField.u1ECC_AUTO_CORRECT = 1;
        break;   
    case CY_CPU_SRAM2:
        CPUSS->unRAM2_CTL0.stcField.u1ECC_AUTO_CORRECT = 1;
        break;
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_SramEccAutoCorrectionDisable
********************************************************************************
* \brief 
* Disable the ECC_AUTO_CORRECT bit.
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_SramEccAutoCorrectionDisable(cy_en_cpu_sram_macro_t sramType)
{
    switch(sramType)
    {
    case CY_CPU_SRAM0:
        CPUSS->unRAM0_CTL0.stcField.u1ECC_AUTO_CORRECT = 0;
        break;
    case CY_CPU_SRAM1:
        CPUSS->unRAM1_CTL0.stcField.u1ECC_AUTO_CORRECT = 0;
        break;   
    case CY_CPU_SRAM2:
        CPUSS->unRAM2_CTL0.stcField.u1ECC_AUTO_CORRECT = 0;
        break;
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_SramEccErrorInjEnable
********************************************************************************
* \brief 
* Enable the ECC_INJ_EN bit.
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_SramEccErrorInjEnable(cy_en_cpu_sram_macro_t sramType)
{
    switch(sramType)
    {
    case CY_CPU_SRAM0:
        CPUSS->unRAM0_CTL0.stcField.u1ECC_INJ_EN = 1;
        break;
    case CY_CPU_SRAM1:
        CPUSS->unRAM1_CTL0.stcField.u1ECC_INJ_EN = 1;
        break;   
    case CY_CPU_SRAM2:
        CPUSS->unRAM2_CTL0.stcField.u1ECC_INJ_EN = 1;
        break;
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_SramEccErrorInjDisable
********************************************************************************
* \brief 
* Disable the ECC_INJ_EN bit.
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_SramEccErrorInjDisable(cy_en_cpu_sram_macro_t sramType)
{
    switch(sramType)
    {
    case CY_CPU_SRAM0:
        CPUSS->unRAM0_CTL0.stcField.u1ECC_INJ_EN = 0;
        break;
    case CY_CPU_SRAM1:
        CPUSS->unRAM1_CTL0.stcField.u1ECC_INJ_EN = 0;
        break;   
    case CY_CPU_SRAM2:
        CPUSS->unRAM2_CTL0.stcField.u1ECC_INJ_EN = 0;
        break;
    default:
        break;      
    }
}

// rmkn: CPR RTL does not have this feature yet
/*******************************************************************************
* Function Name: Cy_Cpu_SramEccCheckEnable
********************************************************************************
* \brief
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_SramEccCheckEnable(cy_en_cpu_sram_macro_t sramType)
{
    switch(sramType)
    {
    case CY_CPU_SRAM0:
        //CPUSS->unRAM0_CTL0.stcField.u1ECC_CHECK_DIS = 0;
        break;
    case CY_CPU_SRAM1:
        //CPUSS->unRAM1_CTL0.stcField.u1ECC_CHECK_DIS = 0;
        break;   
    case CY_CPU_SRAM2:
        //CPUSS->unRAM2_CTL0.stcField.u1ECC_CHECK_DIS = 0;
        break;
    default:
        break;      
    }
}

// rmkn: CPR RTL does not have this feature yet
/*******************************************************************************
* Function Name: Cy_Cpu_SramEccCheckDisable
********************************************************************************
* \brief
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_SramEccCheckDisable(cy_en_cpu_sram_macro_t sramType)
{
    switch(sramType)
    {
    case CY_CPU_SRAM0:
        //CPUSS->unRAM0_CTL0.stcField.u1ECC_CHECK_DIS = 1;
        break;
    case CY_CPU_SRAM1:
        //CPUSS->unRAM1_CTL0.stcField.u1ECC_CHECK_DIS = 1;
        break;   
    case CY_CPU_SRAM2:
        //CPUSS->unRAM2_CTL0.stcField.u1ECC_CHECK_DIS = 1;
        break;
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_SramPowerModeSet
********************************************************************************
* \brief 
* Set the PWR_MODE bit.
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2   
* Power Mode, refer to cy_en_cpu_sram_power_mode_t.
*   CY_CPU_SRAM_PM_OFF       = 0
*   CY_CPU_SRAM_PM_RESERVED  = 1
*   CY_CPU_SRAM_PM_RETAINED  = 2
*   CY_CPU_SRAM_PM_ENABLED   = 3   
* SRAM Macro, Power control register index (max 0x0F)
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_SramPowerModeSet(cy_en_cpu_sram_macro_t sramType, cy_en_cpu_sram_power_mode_t pwrMode, uint8_t sramMacro)
{
    switch(sramType)
    {
    case CY_CPU_SRAM0:
        CPUSS->unRAM0_PWR_MACRO_CTL[sramMacro].stcField.u2PWR_MODE = pwrMode;
        break;
    case CY_CPU_SRAM1:
        CPUSS->unRAM1_PWR_CTL.stcField.u2PWR_MODE = pwrMode;
        break;   
    case CY_CPU_SRAM2:
        CPUSS->unRAM2_PWR_CTL.stcField.u2PWR_MODE = pwrMode;
        break;
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_SramPowerModeGet
********************************************************************************
* \brief 
* Get the PWR_MODE bit.
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2
* SRAM Macro, Power control register index
*
* \return  
* Power Mode, refer to cy_en_cpu_sram_power_mode_t.
*   CY_CPU_SRAM_PM_OFF       = 0
*   CY_CPU_SRAM_PM_RESERVED  = 1
*   CY_CPU_SRAM_PM_RETAINED  = 2
*   CY_CPU_SRAM_PM_ENABLED   = 3
*******************************************************************************/
cy_en_cpu_sram_power_mode_t Cy_Cpu_SramPowerModeGet(cy_en_cpu_sram_macro_t sramType, uint8_t sramMacro)
{
    cy_en_cpu_sram_power_mode_t pwrMode = CY_CPU_SRAM_PM_OFF;
    
    switch(sramType)
    {
    case CY_CPU_SRAM0:
        pwrMode = (cy_en_cpu_sram_power_mode_t)CPUSS->unRAM0_PWR_MACRO_CTL[sramMacro].stcField.u2PWR_MODE;
        break;
    case CY_CPU_SRAM1:
        pwrMode = (cy_en_cpu_sram_power_mode_t)CPUSS->unRAM1_PWR_CTL.stcField.u2PWR_MODE;
        break;   
    case CY_CPU_SRAM2:
        pwrMode = (cy_en_cpu_sram_power_mode_t)CPUSS->unRAM2_PWR_CTL.stcField.u2PWR_MODE;
        break;
    default:
        break;      
    }
    
    return pwrMode;
}

/*******************************************************************************
* Function Name: Cy_Cpu_SramWriteBufferStatus
********************************************************************************
* \brief 
* Get the WB_EMPTY bit.
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2

* \return  
* Status, true or false
*******************************************************************************/
bool Cy_Cpu_SramWriteBufferStatus(cy_en_cpu_sram_macro_t sramType)
{
    bool wb_status = false;
    
    switch(sramType)
    {
    case CY_CPU_SRAM0:
        wb_status = CPUSS->unRAM0_STATUS.stcField.u1WB_EMPTY;
        break;
    case CY_CPU_SRAM1:
        wb_status = CPUSS->unRAM1_STATUS.stcField.u1WB_EMPTY;
        break;   
    case CY_CPU_SRAM2:
        wb_status = CPUSS->unRAM2_STATUS.stcField.u1WB_EMPTY;
        break;
    default:
        break;      
    }
    
    return wb_status;
}

/*******************************************************************************
* Function Name: Cy_Cpu_SramWaitStateSet
********************************************************************************
* \brief 
* Set the SLOW_WS/FAST_WS bit.
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2
* Clock Type, refer to cy_en_cpu_clk_type_t.
*   CY_CPU_SLOW_CLK  = 0
*   CY_CPU_FAST_CLK = 1
* Value, SRAM Wait State Value
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_SramWaitStateSet(cy_en_cpu_sram_macro_t sramType, cy_en_cpu_clk_type_t clkType, uint8_t value)
{
    switch(sramType)
    {
    case CY_CPU_SRAM0:
        if(clkType == CY_CPU_SLOW_CLK)
        {
            CPUSS->unRAM0_CTL0.stcField.u2SLOW_WS = value;
        }
        else // CY_CPU_FAST_CLK
        {
            CPUSS->unRAM0_CTL0.stcField.u2FAST_WS = value;
        }
        break;
    case CY_CPU_SRAM1:
        if(clkType == CY_CPU_SLOW_CLK)
        {
            CPUSS->unRAM1_CTL0.stcField.u2SLOW_WS = value;
        }
        else // CY_CPU_FAST_CLK
        {
            CPUSS->unRAM1_CTL0.stcField.u2FAST_WS = value;
        }
        break;   
    case CY_CPU_SRAM2:
        if(clkType == CY_CPU_SLOW_CLK)
        {
            CPUSS->unRAM2_CTL0.stcField.u2SLOW_WS = value;
        }
        else // CY_CPU_FAST_CLK
        {
            CPUSS->unRAM2_CTL0.stcField.u2FAST_WS = value;
        }
        break;
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_SramWaitStateGet
********************************************************************************
* \brief 
* Get the SLOW_WS/FAST_WS bit.
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2
* Clock Type, refer to cy_en_cpu_clk_type_t.
*   CY_CPU_SLOW_CLK  = 0
*   CY_CPU_FAST_CLK = 1
*
* \return
* Value, SRAM Wait State Value
*******************************************************************************/
uint8_t Cy_Cpu_SramWaitStateGet(cy_en_cpu_sram_macro_t sramType, cy_en_cpu_clk_type_t clkType)
{
    uint8_t value = 0;
    
    switch(sramType)
    {
    case CY_CPU_SRAM0:
        if(clkType == CY_CPU_SLOW_CLK)
        {
            value = CPUSS->unRAM0_CTL0.stcField.u2SLOW_WS;
        }
        else // CY_CPU_FAST_CLK
        {
            value = CPUSS->unRAM0_CTL0.stcField.u2FAST_WS;
        }
        break;
    case CY_CPU_SRAM1:
        if(clkType == CY_CPU_SLOW_CLK)
        {
            value = CPUSS->unRAM1_CTL0.stcField.u2SLOW_WS;
        }
        else // CY_CPU_FAST_CLK
        {
            value = CPUSS->unRAM1_CTL0.stcField.u2FAST_WS;
        }
        break;   
    case CY_CPU_SRAM2:
        if(clkType == CY_CPU_SLOW_CLK)
        {
            value = CPUSS->unRAM2_CTL0.stcField.u2SLOW_WS;
        }
        else // CY_CPU_FAST_CLK
        {
            value = CPUSS->unRAM2_CTL0.stcField.u2FAST_WS;
        }
        break;
    default:
        break;      
    }
    
    return value;
}

/*******************************************************************************
* Function Name: Cy_Cpu_ErrorInjWordAddress
********************************************************************************
* \brief 
* Set the WORD_ADDR  bit.
*
* \param
* Address, Cpu ECC error injection address.
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_ErrorInjWordAddress(uint32_t wordAddr)
{
    CPUSS->unECC_CTL.stcField.u25WORD_ADDR = wordAddr;
}

/*******************************************************************************
* Function Name: Cy_Cpu_EccParityForErrorInj
********************************************************************************
* \brief 
* Set the PARITY bit.
*
* \param
* Parity, Cpu ECC parity for error injection.
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_EccParityForErrorInj(uint8_t eccParity)
{
    CPUSS->unECC_CTL.stcField.u7PARITY = eccParity;
}

/*******************************************************************************
* Function Name: Cy_Cpu_SramWoundingGet
********************************************************************************
* \brief 
* Get the SRAM_WOUND status.
*
* \param
* SRAM type, refer to cy_en_cpu_sram_macro_t.
*   CY_CPU_SRAM0 = 0
*   CY_CPU_SRAM1 = 1
*   CY_CPU_SRAM2 = 2
*
* \return   
* SRAM Wound, refer to cy_en_cpu_sram_wounding_t.
*   CY_CPU_SRAM_FULL_ACCESS     = 0
*   CY_CPU_SRAM_1_BY_2_ACCESS   = 1
*   CY_CPU_SRAM_1_BY_4_ACCESS   = 2
*   CY_CPU_SRAM_1_BY_8_ACCESS   = 3
*   CY_CPU_SRAM_1_BY_16_ACCESS  = 4
*   CY_CPU_SRAM_1_BY_32_ACCESS  = 5
*   CY_CPU_SRAM_1_BY_64_ACCESS  = 6
*   CY_CPU_SRAM_1_BY_128_ACCESS = 7
*******************************************************************************/
cy_en_cpu_sram_wounding_t Cy_Cpu_SramWoundingGet(cy_en_cpu_sram_macro_t sramType)
{
    cy_en_cpu_sram_wounding_t sramWound = CY_CPU_SRAM_FULL_ACCESS;    
    // rmkn: CPR RTL does not have this feature yet    
    return sramWound;
}

/*******************************************************************************
* Function Name: Cy_Cpu_MainFlashWoundingGet
********************************************************************************
* \brief 
* Get the MAIN_FLASH_WOUND status.
*
* \param
* None
*
* \return   
* Main Flash Wound, refer to cy_en_cpu_flash_wounding_t.
*   CY_CPU_FLASH_FULL_ACCESS     = 0
*   CY_CPU_FLASH_3_BY_4_ACCESS   = 1
*   CY_CPU_FLASH_1_BY_2_ACCESS   = 2
*   CY_CPU_FLASH_ILLEGAL_ACCESS  = 3
*******************************************************************************/
cy_en_cpu_flash_wounding_t Cy_Cpu_MainFlashWoundingGet(void)
{
    cy_en_cpu_flash_wounding_t flsWound = CY_CPU_FLASH_FULL_ACCESS;
    // rmkn: CPR RTL does not have this feature yet
    return flsWound;
}

/*******************************************************************************
* Function Name: Cy_Cpu_WorkFlashWoundingGet
********************************************************************************
* \brief 
* Get the WORK_FLASH_WOUND status.
*
* \param
* None
*
* \return   
* Main Flash Wound, refer to cy_en_cpu_flash_wounding_t.
*   CY_CPU_FLASH_FULL_ACCESS     = 0
*   CY_CPU_FLASH_3_BY_4_ACCESS   = 1
*   CY_CPU_FLASH_1_BY_2_ACCESS   = 2
*   CY_CPU_FLASH_ILLEGAL_ACCESS  = 3
*******************************************************************************/
cy_en_cpu_flash_wounding_t Cy_Cpu_WorkFlashWoundingGet(void)
{
    cy_en_cpu_flash_wounding_t flsWound = CY_CPU_FLASH_FULL_ACCESS;
    // rmkn: CPR RTL does not have this feature yet
    return flsWound;
}

/*******************************************************************************
* Function Name: Cy_Cpu_ProtectionStateGet
********************************************************************************
* \brief 
* Get the STATE bits.
*
* \param
* None
*
* \return   
* STATE, refer to cy_en_cpu_protection_type_t.
*   CY_CPU_PROTECTION_UNKNOWN   = 0
*   CY_CPU_PROTECTION_VIRGIN    = 1
*   CY_CPU_PROTECTION_NORMAL    = 2
*   CY_CPU_PROTECTION_SECURE    = 3
*   CY_CPU_PROTECTION_DEAD      = 4
*******************************************************************************/
cy_en_cpu_protection_type_t Cy_Cpu_ProtectionStateGet(void)
{
    cy_en_cpu_protection_type_t state = CY_CPU_PROTECTION_UNKNOWN;
    
    state = (cy_en_cpu_protection_type_t)CPUSS->unPROTECTION.stcField.u3STATE;
    
    return state;
}

/*******************************************************************************
* Function Name: Cy_Cpu_CoreClkDividerSet
********************************************************************************
* \brief 
* Set the INT_DIV value.
*
* \param
* Core Type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* Divider Type, refer to cy_en_cpu_div_type_t.
*   CY_CPU_INTDIV  = 0   
* Divider Value, Clock divider type value (0-255).
*
* \return   
* None
*******************************************************************************/
void Cy_Cpu_CoreClkDividerSet(cy_en_cpu_core_type_t coreType, cy_en_cpu_div_type_t divType, uint8_t divValue)
{
    switch(coreType)
    {
    case CY_CPU_CM4:
        if(divType == CY_CPU_INTDIV)
        {
            CPUSS->unCM4_CLOCK_CTL.stcField.u8FAST_INT_DIV = divValue;
        }
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_CoreClkDividerGet
********************************************************************************
* \brief 
* Get the INT_DIV value.
*
* \param
* Core Type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* Divider Type, refer to cy_en_cpu_div_type_t.
*   CY_CPU_INTDIV  = 0   
*
* \return   
* Divider Value, Clock divider type value (0-255).
*******************************************************************************/
uint8_t Cy_Cpu_CoreClkDividerGet(cy_en_cpu_core_type_t coreType, cy_en_cpu_div_type_t divType)
{
    uint8_t divValue = 0;
    
    switch(coreType)
    {
    case CY_CPU_CM4:
        if(divType == CY_CPU_INTDIV)
        {
            divValue = CPUSS->unCM4_CLOCK_CTL.stcField.u8FAST_INT_DIV;
        }
        break;   
    default:
        break;      
    }
    
    return divValue;
}

/*******************************************************************************
* Function Name: Cy_Cpu_GetProductId
********************************************************************************
* \brief
* Get the product index value.
*
* \param pFamilyId: Pointer to a variable into which family index value
*        will be stored.
* 
* \param pMajorRevisionId: Pointer to a variable into which major revision
*        index value will be stored.
* 
* \param pMinorRevisionId: Pointer to a variable into which minor revision
*        index value will be stored.
* 
* \return
* Product Index value
*
*******************************************************************************/
void Cy_Cpu_GetProductId(uint32_t* pFamilyId, uint32_t* pMajorRevisionId, uint32_t* pMinorRevisionId)
{
    if(pFamilyId != NULL)
    {
        *pFamilyId = CPUSS->unPRODUCT_ID.stcField.u12FAMILY_ID;
    }

    if(pMajorRevisionId != NULL)
    {
        *pMajorRevisionId = CPUSS->unPRODUCT_ID.stcField.u4MAJOR_REV;
    }

    if(pMinorRevisionId != NULL)
    {
        *pMinorRevisionId = CPUSS->unPRODUCT_ID.stcField.u4MINOR_REV;
    }
}


#if defined(__cplusplus)
}
#endif /* __cplusplus */

/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
