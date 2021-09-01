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
* Function Name: Cy_Cpu_WaitClear
********************************************************************************
* \brief 
* Clears the CPU_WAIT bit.
*
* \param
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2   
*
* \return 
* None.
*******************************************************************************/
void Cy_Cpu_WaitClear(cy_en_cpu_core_type_t coreType)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        CPUSS->unCM7_0_CTL.stcField.u1CPU_WAIT = 0;
        break;
    case CY_CPU_CM7_1:
        CPUSS->unCM7_1_CTL.stcField.u1CPU_WAIT = 0;
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_WaitSet
********************************************************************************
* \brief Sets the CPU_WAIT bit.
*
* \param
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
*
* \return
* None.
*******************************************************************************/
void Cy_Cpu_WaitSet(cy_en_cpu_core_type_t coreType)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        CPUSS->unCM7_0_CTL.stcField.u1CPU_WAIT = 1;
        break;
    case CY_CPU_CM7_1:
        CPUSS->unCM7_1_CTL.stcField.u1CPU_WAIT = 1;
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_TcmEnable
********************************************************************************
* \brief 
* Enable the INIT_TCM_EN bit.
*
* \param
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* TCM type, refer to cy_en_cpu_tcm_type_t.
*   CY_CPU_ITCM = 0
*   CY_CPU_DTCM = 1   
*
* \return 
* None.
*******************************************************************************/
void Cy_Cpu_TcmEnable(cy_en_cpu_core_type_t coreType, cy_en_cpu_tcm_type_t tcmType)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_0_CTL.stcField.u2INIT_TCM_EN = 1;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_0_CTL.stcField.u2INIT_TCM_EN = 2;
        }
        break;
    case CY_CPU_CM7_1:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_1_CTL.stcField.u2INIT_TCM_EN = 1;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_1_CTL.stcField.u2INIT_TCM_EN = 2;
        }
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_TcmDisable
********************************************************************************
* \brief 
* Clear the INIT_TCM_EN bit.
*
* \param
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* TCM type, refer to cy_en_cpu_tcm_type_t.
*   CY_CPU_ITCM = 0
*   CY_CPU_DTCM = 1
*
* \return 
* None.
*******************************************************************************/
void Cy_Cpu_TcmDisable(cy_en_cpu_core_type_t coreType, cy_en_cpu_tcm_type_t tcmType)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_0_CTL.stcField.u2INIT_TCM_EN &= 2;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_0_CTL.stcField.u2INIT_TCM_EN &= 1;
        }
        break;
    case CY_CPU_CM7_1:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_1_CTL.stcField.u2INIT_TCM_EN &= 2;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_1_CTL.stcField.u2INIT_TCM_EN &= 1;
        }
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_TcmReadModifyWriteEnable
********************************************************************************
* \brief 
* Enable the INIT_RMW_EN bit.
*
* \param
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* TCM type, refer to cy_en_cpu_tcm_type_t.
*   CY_CPU_ITCM = 0
*   CY_CPU_DTCM = 1
*
* \return 
* None.
*******************************************************************************/
void Cy_Cpu_TcmReadModifyWriteEnable(cy_en_cpu_core_type_t coreType, cy_en_cpu_tcm_type_t tcmType)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_0_CTL.stcField.u2INIT_RMW_EN = 1;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_0_CTL.stcField.u2INIT_RMW_EN = 2;
        }
        break;
    case CY_CPU_CM7_1:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_1_CTL.stcField.u2INIT_RMW_EN = 1;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_1_CTL.stcField.u2INIT_RMW_EN = 2;
        }
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_TcmReadModifyWriteDisable
********************************************************************************
* \brief 
* Clear the INIT_RMW_EN bit.
* 
* \param
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* TCM type, refer to cy_en_cpu_tcm_type_t.
*   CY_CPU_ITCM = 0
*   CY_CPU_DTCM = 1
*
* \return 
* None.
*******************************************************************************/
void Cy_Cpu_TcmReadModifyWriteDisable(cy_en_cpu_core_type_t coreType, cy_en_cpu_tcm_type_t tcmType)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_0_CTL.stcField.u2INIT_RMW_EN &= 2;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_0_CTL.stcField.u2INIT_RMW_EN &= 1;
        }
        break;
    case CY_CPU_CM7_1:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_1_CTL.stcField.u2INIT_RMW_EN &= 2;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_1_CTL.stcField.u2INIT_RMW_EN &= 1;
        }
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_TcmEccEnable
********************************************************************************
* \brief 
* Enable the ITCM_ECC_EN bit.
*
* \param
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* TCM type, refer to cy_en_cpu_tcm_type_t.
*   CY_CPU_ITCM = 0
*   CY_CPU_DTCM = 1
*
* \return 
* None.
*******************************************************************************/
void Cy_Cpu_TcmEccEnable(cy_en_cpu_core_type_t coreType, cy_en_cpu_tcm_type_t tcmType)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_0_CTL.stcField.u1ITCM_ECC_EN = 1;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_0_CTL.stcField.u1DTCM_ECC_EN = 1;
        }
        break;
    case CY_CPU_CM7_1:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_1_CTL.stcField.u1ITCM_ECC_EN = 1;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_1_CTL.stcField.u1DTCM_ECC_EN = 1;
        }
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_TcmEccDisable
********************************************************************************
* \brief 
* Clear the ITCM_ECC_EN bit.
*
* \param
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* TCM type, refer to cy_en_cpu_tcm_type_t.
*   CY_CPU_ITCM = 0
*   CY_CPU_DTCM = 1
*
* \return 
* None.
*******************************************************************************/
void Cy_Cpu_TcmEccDisable(cy_en_cpu_core_type_t coreType, cy_en_cpu_tcm_type_t tcmType)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_0_CTL.stcField.u1ITCM_ECC_EN = 0;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_0_CTL.stcField.u1DTCM_ECC_EN = 0;
        }
        break;
    case CY_CPU_CM7_1:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_1_CTL.stcField.u1ITCM_ECC_EN = 0;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_1_CTL.stcField.u1DTCM_ECC_EN = 0;
        }
        break;        
    default:
        break;      
    }
}


/*******************************************************************************
* Function Name: Cy_Cpu_TcmEccErrorInjEnable
********************************************************************************
* \brief 
* Enable the ITCM_ECC_INJ_EN bit.
*
* \param
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* TCM type, refer to cy_en_cpu_tcm_type_t.
*   CY_CPU_ITCM = 0
*   CY_CPU_DTCM = 1
*
* \return 
* None.
*******************************************************************************/
void Cy_Cpu_TcmEccErrorInjEnable(cy_en_cpu_core_type_t coreType, cy_en_cpu_tcm_type_t tcmType)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_0_CTL.stcField.u1ITCM_ECC_INJ_EN = 1;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_0_CTL.stcField.u1DTCM_ECC_INJ_EN = 1;
        }
        break;
    case CY_CPU_CM7_1:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_1_CTL.stcField.u1ITCM_ECC_INJ_EN = 1;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_1_CTL.stcField.u1DTCM_ECC_INJ_EN = 1;
        }
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_TcmEccErrorInjDisable
********************************************************************************
* \brief 
* Clear the ITCM_ECC_INJ_EN bit.
*
* \param
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* TCM type, refer to cy_en_cpu_tcm_type_t.
*   CY_CPU_ITCM = 0
*   CY_CPU_DTCM = 1
*
* \return 
* None.
*******************************************************************************/
void Cy_Cpu_TcmEccErrorInjDisable(cy_en_cpu_core_type_t coreType, cy_en_cpu_tcm_type_t tcmType)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_0_CTL.stcField.u1ITCM_ECC_INJ_EN = 0;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_0_CTL.stcField.u1DTCM_ECC_INJ_EN = 0;
        }
        break;
    case CY_CPU_CM7_1:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_1_CTL.stcField.u1ITCM_ECC_INJ_EN = 0;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_1_CTL.stcField.u1DTCM_ECC_INJ_EN = 0;
        }
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_TcmReadWaitStatesSet
********************************************************************************
* \brief 
* Set the ITCM_READ_WS bit.
*
* \param coreType
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* TCM type, refer to cy_en_cpu_tcm_type_t.
*   CY_CPU_ITCM = 0
*   CY_CPU_DTCM = 1
* Wait states, 0 or 1
*
* \return 
* None.
*******************************************************************************/
void Cy_Cpu_TcmReadWaitStatesSet(cy_en_cpu_core_type_t coreType, cy_en_cpu_tcm_type_t tcmType, uint8_t waitStates)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_0_CTL.stcField.u1ITCM_READ_WS = waitStates;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_0_CTL.stcField.u1DTCM_READ_WS = waitStates;
        }
        break;
    case CY_CPU_CM7_1:
        if(tcmType == CY_CPU_ITCM)
        {
            CPUSS->unCM7_1_CTL.stcField.u1ITCM_READ_WS = waitStates;
        }
        else // CY_CPU_DTCM
        {
            CPUSS->unCM7_1_CTL.stcField.u1DTCM_READ_WS = waitStates;
        }
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_TcmReadWaitStatesGet
********************************************************************************
* \brief 
* Get the ITCM_READ_WS bit.
*
* \param coreType
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* TCM type, refer to cy_en_cpu_tcm_type_t.
*   CY_CPU_ITCM = 0
*   CY_CPU_DTCM = 1
*
* \return
* Wait states, 0 or 1.
*******************************************************************************/
uint8_t Cy_Cpu_TcmReadWaitStatesGet(cy_en_cpu_core_type_t coreType, cy_en_cpu_tcm_type_t tcmType)
{
    uint8_t waitStates = 0;
    
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        if(tcmType == CY_CPU_ITCM)
        {
            waitStates = CPUSS->unCM7_0_CTL.stcField.u1ITCM_READ_WS;
        }
        else // CY_CPU_DTCM
        {
            waitStates = CPUSS->unCM7_0_CTL.stcField.u1DTCM_READ_WS;
        }
        break;
    case CY_CPU_CM7_1:
        if(tcmType == CY_CPU_ITCM)
        {
            waitStates = CPUSS->unCM7_1_CTL.stcField.u1ITCM_READ_WS;
        }
        else // CY_CPU_DTCM
        {
            waitStates = CPUSS->unCM7_1_CTL.stcField.u1DTCM_READ_WS;
        }
        break;        
    default:
        break;      
    }
    
    return waitStates;
}

// rmkn:  CPR RTL does not have this feature yet
/*******************************************************************************
* Function Name: Cy_Cpu_Cm7TcmSlavePortAccessEnable
********************************************************************************
* \brief
*
* \param coreType
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_Cm7TcmSlavePortAccessEnable(cy_en_cpu_core_type_t coreType)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        //CPUSS->unCM7_0_CTL.stcField.u1TCMC_EN = 1;
        break;
    case CY_CPU_CM7_1:
        //CPUSS->unCM7_1_CTL.stcField.u1TCMC_EN = 1;
        break;        
    default:
        break;      
    }
}

// rmkn: CPR RTL does not have this feature yet
/*******************************************************************************
* Function Name: Cy_Cpu_Cm7TcmSlavePortAccessDisable
********************************************************************************
* \brief
*
* \param
* Core type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
*
* \return
* None
*******************************************************************************/
void Cy_Cpu_Cm7TcmSlavePortAccessDisable(cy_en_cpu_core_type_t coreType)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        //CPUSS->unCM7_0_CTL.stcField.u1TCMC_EN = 0;
        break;
    case CY_CPU_CM7_1:
        //CPUSS->unCM7_1_CTL.stcField.u1TCMC_EN = 0;
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_Cm7PowerModeSet
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
void Cy_Cpu_Cm7PowerModeSet(cy_en_cpu_core_type_t coreType, cy_en_cpu_power_mode_t pwrMode)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        CPUSS->unCM7_0_PWR_CTL.stcField.u2PWR_MODE = pwrMode;
        break;
    case CY_CPU_CM7_1:
        CPUSS->unCM7_1_PWR_CTL.stcField.u2PWR_MODE = pwrMode;
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_Cm7PowerModeGet
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
cy_en_cpu_power_mode_t Cy_Cpu_Cm7PowerModeGet(cy_en_cpu_core_type_t coreType)
{
    cy_en_cpu_power_mode_t pwrMode = CY_CPU_PM_OFF;
    
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        pwrMode = (cy_en_cpu_power_mode_t)CPUSS->unCM7_0_PWR_CTL.stcField.u2PWR_MODE;
        break;
    case CY_CPU_CM7_1:
        pwrMode = (cy_en_cpu_power_mode_t)CPUSS->unCM7_1_PWR_CTL.stcField.u2PWR_MODE;
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
* SRAM Macro, Power control register index
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
    CPUSS->unECC_CTL.stcField.u24WORD_ADDR = wordAddr;
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
    CPUSS->unECC_CTL.stcField.u8PARITY = eccParity;
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
* Function Name: Cy_Cpu_CoreFastClkDividerSet
********************************************************************************
* \brief 
* Set the FRAC_DIV/INT_DIV status.
*
* \param
* Core Type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1
*   CY_CPU_CM4   = 2
* Divider Type, refer to cy_en_cpu_div_type_t.
*   CY_CPU_INTDIV  = 0
    CY_CPU_FRACDIV = 1   
* Divider Value, Clock divider type value.
*
* \return   
* None
*******************************************************************************/
void Cy_Cpu_CoreFastClkDividerSet(cy_en_cpu_core_type_t coreType, cy_en_cpu_div_type_t divType, uint8_t divValue)
{
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        if(divType == CY_CPU_INTDIV)
        {
            CPUSS->unFAST_0_CLOCK_CTL.stcField.u8INT_DIV = divValue;
        }
        else // CY_CPU_FRACDIV
        {
            CPUSS->unFAST_0_CLOCK_CTL.stcField.u5FRAC_DIV = divValue;
        }
        break;
    case CY_CPU_CM7_1:
        if(divType == CY_CPU_INTDIV)
        {
            CPUSS->unFAST_1_CLOCK_CTL.stcField.u8INT_DIV = divValue;
        }
        else // CY_CPU_FRACDIV
        {
            CPUSS->unFAST_1_CLOCK_CTL.stcField.u5FRAC_DIV = divValue;
        }
        break;        
    default:
        break;      
    }
}

/*******************************************************************************
* Function Name: Cy_Cpu_CoreFastClkDividerGet
********************************************************************************
* \brief 
* Get the FRAC_DIV/INT_DIV status.
*
* \param
* Core Type, refer to cy_en_cpu_core_type_t.
*   CY_CPU_CM7_0 = 0
*   CY_CPU_CM7_1 = 1   
*   CY_CPU_CM4   = 2
* Divider Type, refer to cy_en_cpu_div_type_t.
*   CY_CPU_INTDIV  = 0
    CY_CPU_FRACDIV = 1   
*
* \return   
* Divider Value, Clock divider type value.
*******************************************************************************/
uint8_t Cy_Cpu_CoreFastClkDividerGet(cy_en_cpu_core_type_t coreType, cy_en_cpu_div_type_t divType)
{
    uint8_t divValue = 0;
    
    switch(coreType)
    {
    case CY_CPU_CM7_0:
        if(divType == CY_CPU_INTDIV)
        {
            divValue = CPUSS->unFAST_0_CLOCK_CTL.stcField.u8INT_DIV;
        }
        else // CY_CPU_FRACDIV
        {
            divValue = CPUSS->unFAST_0_CLOCK_CTL.stcField.u5FRAC_DIV;
        }
        break;
    case CY_CPU_CM7_1:
        if(divType == CY_CPU_INTDIV)
        {
            divValue = CPUSS->unFAST_1_CLOCK_CTL.stcField.u8INT_DIV;
        }
        else // CY_CPU_FRACDIV
        {
            divValue = CPUSS->unFAST_1_CLOCK_CTL.stcField.u5FRAC_DIV;
        }
        break;        
    default:
        break;      
    }
    
    return divValue;
}

/*******************************************************************************
* Function Name: Cy_Cpu_CoreMemDividerSet
********************************************************************************
* \brief 
* Set the INT_DIV bit.
*
* \param   
* Divider Value, Clock divider type value.
*
* \return   
* None
*******************************************************************************/
void Cy_Cpu_CoreMemDividerSet(uint8_t divValue)
{
    CPUSS->unMEM_CLOCK_CTL.stcField.u8INT_DIV = divValue;
}

/*******************************************************************************
* Function Name: Cy_Cpu_CoreMemDividerGet
********************************************************************************
* \brief 
* Get the INT_DIV bit.
*
* \param   
* None
*
* \return   
* Divider Value, Clock divider type value.
*******************************************************************************/
uint8_t Cy_Cpu_CoreMemDividerGet(void)
{
    return (CPUSS->unMEM_CLOCK_CTL.stcField.u8INT_DIV);
}

/*******************************************************************************
* Function Name: Cy_Cpu_CorePeriDividerSet
********************************************************************************
* \brief 
* Set the INT_DIV bit.
*
* \param   
* Divider Value, Peripheral Clock divider type value.
*
* \return   
* None
*******************************************************************************/
void Cy_Cpu_CorePeriDividerSet(uint8_t divValue)
{
    CPUSS->unPERI_CLOCK_CTL.stcField.u8INT_DIV = divValue;
}

/*******************************************************************************
* Function Name: Cy_Cpu_CorePeriDividerGet
********************************************************************************
* \brief 
* Get the INT_DIV bit.
*
* \param   
* None
*
* \return   
* Divider Value, Peripheral Clock divider type value.
*******************************************************************************/
uint8_t Cy_Cpu_CorePeriDividerGet(void)
{
    return (CPUSS->unPERI_CLOCK_CTL.stcField.u8INT_DIV);
}

/*******************************************************************************
* Function Name: Cy_Cpu_CoreTraceDbgDividerSet
********************************************************************************
* \brief 
* Set the INT_DIV bit.
*
* \param   
* Divider Value, Trace/Debuger Clock divider type value.
*
* \return   
* None
*******************************************************************************/
void Cy_Cpu_CoreTraceDbgDividerSet(uint8_t divValue)
{
    CPUSS->unTRC_DBG_CLOCK_CTL.stcField.u8INT_DIV = divValue;
}

/*******************************************************************************
* Function Name: Cy_Cpu_CoreTraceDbgDividerGet
********************************************************************************
* \brief 
* Get the INT_DIV bit.
*
* \param   
* None
*
* \return   
* Divider Value, Trace/Debuger Clock divider type value.
*******************************************************************************/
uint8_t Cy_Cpu_CoreTraceDbgDividerGet(void)
{
    return (CPUSS->unTRC_DBG_CLOCK_CTL.stcField.u8INT_DIV);
}

/*******************************************************************************
* Function Name: Cy_Cpu_CoreSlowClkDividerSet
********************************************************************************
* \brief 
* Set the INT_DIV bit.
*
* \param   
* Divider Value, Slow Clock divider type value.
*
* \return   
* None
*******************************************************************************/
void Cy_Cpu_CoreSlowClkDividerSet(uint8_t divValue)
{
    CPUSS->unSLOW_CLOCK_CTL.stcField.u8INT_DIV = divValue;
}

/*******************************************************************************
* Function Name: Cy_Cpu_CoreSlowClkDividerGet
********************************************************************************
* \brief 
* Get the INT_DIV bit.
*
* \param   
* None
*
* \return   
* Divider Value, Skow Clock divider type value.
*******************************************************************************/
uint8_t Cy_Cpu_CoreSlowClkDividerGet(void)
{
    return (CPUSS->unSLOW_CLOCK_CTL.stcField.u8INT_DIV);
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
