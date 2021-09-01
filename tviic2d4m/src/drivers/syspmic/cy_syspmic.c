/***************************************************************************//**
* \file cy_syspmic.c
* \version 1.0
*
* Provides an API implementation of the system PMIC driver.
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_syspmic.h"
#include "syslib/cy_syslib.h"

#include <stdlib.h>

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
* Function Name: Cy_SysPmic_DisableLinearRegulator
********************************************************************************
* \brief 
* Disables internal linear regulator.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_DisableLinearRegulator(void)
{
    SRSS->unPWR_CTL2.stcField.u1LINREG_DIS = 1u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_EnableLinearRegulator
********************************************************************************
* \brief 
* Enables internal linear regulator.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_EnableLinearRegulator(void)
{
    SRSS->unPWR_CTL2.stcField.u1LINREG_DIS = 0u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_GetLinearRegulatorStatus
********************************************************************************
* \brief 
* Check the status of the internal linear regulator.
*
* \param
* None.   
*
* \return 
* true  - status ok
* false - status fail
*******************************************************************************/
bool Cy_SysPmic_GetLinearRegulatorStatus(void)
{
    return ((bool) SRSS->unPWR_CTL2.stcField.u1LINREG_OK);
}

/*******************************************************************************
* Function Name: Cy_SysPmic_DisableDeepSleepRegulator
********************************************************************************
* \brief 
* Disables internal DeepSleep regulator.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_DisableDeepSleepRegulator(void)
{
    SRSS->unPWR_CTL2.stcField.u1DPSLP_REG_DIS = 1u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_EnableDeepSleepRegulator
********************************************************************************
* \brief 
* Enables internal DeepSleep linear regulator.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_EnableDeepSleepRegulator(void)
{
    SRSS->unPWR_CTL2.stcField.u1DPSLP_REG_DIS = 0u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_SelectVref
********************************************************************************
* \brief 
* Selects VREF for the PMIC.
*
* \param
* vref - VREF scaling option
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_SelectVref(cy_en_syspmic_vref_t vref)
{
    SRSS->unPWR_PMIC_CTL.stcField.u2PMIC_VREF = vref;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_AdjustOutputVoltage
********************************************************************************
* \brief 
* Selects PMIC output voltage adjustment.
*
* \param
* trim - Regulator output trim, no effect when PMIC_VREF has no scaling
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_AdjustOutputVoltage(cy_en_syspmic_vadj_t trim)
{
    SRSS->unPWR_PMIC_CTL.stcField.u5PMIC_VADJ = trim;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_DisableIntSupplyWhileExtActive
********************************************************************************
* \brief 
*  Internal Active Linear Regulator disabled after PMIC enabled.  OCD is disabled.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_DisableIntSupplyWhileExtActive(void)
{
    SRSS->unPWR_PMIC_CTL.stcField.u1PMIC_USE_LINREG = 0u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_EnableInternalSupplyWhileExternalSupplyActive
********************************************************************************
* \brief 
*   Internal Active Linear Regulator kept enabled.  See datasheet for minimum 
*   PMIC vccd input to prevent OCD.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_EnableIntSupplyWhileExtActive(void)
{
    SRSS->unPWR_PMIC_CTL.stcField.u1PMIC_USE_LINREG = 1u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_EnableAnalogBuffer
********************************************************************************
* \brief 
* Use analog buffer.  This enables an analog buffer between the resistor divider 
* output and the pin.  The buffer can drive a resistor divider on the PCB that 
* feeds into the PMIC feedback input
*
* \param
* None.
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_EnableAnalogBuffer(void)
{
    SRSS->unPWR_PMIC_CTL.stcField.u1PMIC_VADJ_BUF_EN = 1u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_DisableAnalogBuffer
********************************************************************************
* \brief 
* Bypass buffer.  This connects the resistor divider directly to the output pin.  
* Use this setting for a PMIC with a high-impedance feedback input, such as those 
* that support a resistor divider on the PCB.
*
* \param
* None.
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_DisableAnalogBuffer(void)
{
    SRSS->unPWR_PMIC_CTL.stcField.u1PMIC_VADJ_BUF_EN = 0u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_DisablePmicEnableOutput
********************************************************************************
* \brief 
* Disables "PMIC enable" output.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_DisablePmicEnableOutput(void)
{
    SRSS->unPWR_PMIC_CTL.stcField.u1PMIC_CTL_OUTEN = 0u;
    SRSS->unPWR_PMIC_CTL.stcField.u1PMIC_CTL_POLARITY = 0u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_EnablePmicEnableOutput
********************************************************************************
* \brief 
* Enables "PMIC enable" output.
*
* \param
* polarity => true - output high, false - output low.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_EnablePmicEnableOutput(bool polarity)
{
    SRSS->unPWR_PMIC_CTL.stcField.u1PMIC_CTL_OUTEN = 1u;
    SRSS->unPWR_PMIC_CTL.stcField.u1PMIC_CTL_POLARITY = (polarity == false) ? 0u : 1u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_EnablePmicStatusInput
********************************************************************************
* \brief 
* Enables receiving status from PMIC.
*
* \param
* polarity => true/false -> receiving high/low means abnormal status.
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_EnablePmicStatusInput(bool polarity)
{
    SRSS->unPWR_PMIC_CTL.stcField.u1PMIC_STATUS_INEN = 1u;
    SRSS->unPWR_PMIC_CTL.stcField.u1PMIC_STATUS_POLARITY = (polarity == false) ? 0u : 1u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_DisablePmicStatusInput
********************************************************************************
* \brief 
* Disables PMIC status input 
*
* \param
* None.   
*
* \return 
* None
*******************************************************************************/
void Cy_SysPmic_DisablePmicStatusInput(void)
{
    SRSS->unPWR_PMIC_CTL.stcField.u1PMIC_STATUS_INEN = 0u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_SetPmicStatusWaitTime
********************************************************************************
* \brief 
* Wait count in 4us steps after PMIC status ok.  This is used by the hardware 
* sequencer to allow additional settling time before disabling the internal regulator.  
* The LSB is 32 IMO periods which results in a nominal LSB step of 4us.
*
* \param
* waitTime = 0 to 1023 -> (waitTime * 4us) Delay
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_SetPmicStatusWaitTime(uint16_t waitTime)
{
    SRSS->unPWR_PMIC_CTL.stcField.u10PMIC_STATUS_WAIT = waitTime;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_IsConfigured
********************************************************************************
* \brief 
* Indicates that the PMIC has been configured. 
* Do not change PMIC settings after this bit is high.  
*
* \param
* None.   
*
* \return 
* true - Configured, false - Not configured
*******************************************************************************/
bool Cy_SysPmic_IsConfigured(void)
{
    return ((bool) SRSS->unPWR_PMIC_CTL.stcField.u1PMIC_CONFIGURED);
}

/*******************************************************************************
* Function Name: Cy_SysPmic_SetConfigured
********************************************************************************
* \brief 
* Set PMIC is configured. This is required to apply setting before enabling PMIC.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_SetConfigured(void)
{
    SRSS->unPWR_PMIC_CTL.stcField.u1PMIC_CONFIGURED = 1u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_Disable
********************************************************************************
* \brief 
* Disables PMIC.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_Disable(void)
{
    SRSS->unPWR_PMIC_CTL2.stcField.u1PMIC_EN = 0u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_Enable
********************************************************************************
* \brief 
* Enables PMIC.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_Enable(void)
{
    SRSS->unPWR_PMIC_CTL2.stcField.u1PMIC_EN = 1u;
}
     
/*******************************************************************************
* Function Name: Cy_SysPmic_DisablePmicStatusTimeout
********************************************************************************
* \brief 
* Disables timeout when waiting for PMIC_STATUS_OK==1.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_DisablePmicStatusTimeout(void)
{
    SRSS->unPWR_PMIC_CTL2.stcField.u8PMIC_STATUS_TIMEOUT = 0u;
}
     
/*******************************************************************************
* Function Name: Cy_SysPmic_EnablePmicStatusTimeout
********************************************************************************
* \brief 
* Enables timeout while waiting for PMIC_STATUS_OK==1 when switching to PMIC.  
* Timeout expiration triggers reset.
*
* \param
* timeout = 1 - 255 -> (timeout * 128us) delay until reset
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_EnablePmicStatusTimeout(uint8_t timeout)
{
    SRSS->unPWR_PMIC_CTL2.stcField.u8PMIC_STATUS_TIMEOUT = timeout;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_IsEnabled
********************************************************************************
* \brief 
* Indicates the state of the PMIC enable/disable sequencer.  This bit is only 
* valid when PMIC_SEQ_BUSY==0. 
*
* \param
* None.   
*
* \return 
* true - Enabled, false - Disabled
*******************************************************************************/
bool Cy_SysPmic_IsEnabled(void)
{
    return ((bool) SRSS->unPWR_PMIC_STATUS.stcField.u1PMIC_ENABLED);
}

/*******************************************************************************
* Function Name: Cy_SysPmic_IsStatusOk
********************************************************************************
* \brief 
* Indicates the PMIC status is ok.  This includes polarity adjustment according 
* to PMIC_STATUS_POLARITY.
*
* \param
* None.   
*
* \return 
* false: PMIC status is not ok or PMIC input is disabled (PMIC_STATUS_INEN == 0)
* true:  PMIC status input is enabled and indicates ok
*******************************************************************************/
bool Cy_SysPmic_IsStatusOk(void)
{
    return ((bool) SRSS->unPWR_PMIC_STATUS.stcField.u1PMIC_STATUS_OK);
}

/*******************************************************************************
* Function Name: Cy_SysPmic_IsSequencerBusy
********************************************************************************
* \brief 
* Indicates whether the PMIC circuit is busy. Indicates the PMIC enable/disable 
* sequencer is busy transitioning to/from PMIC.
*
* \param
* None.   
*
* \return 
* true:  PMIC busy
* false: PMIC not busy
*******************************************************************************/
bool Cy_SysPmic_IsSequencerBusy(void)
{
    return ((bool) SRSS->unPWR_PMIC_STATUS.stcField.u1PMIC_SEQ_BUSY);
}

/*******************************************************************************
* Function Name: Cy_SysPmic_DisableVAdj
********************************************************************************
* \brief 
* Device does not generate VADJ, and it must not be part of the PMIC feedback loop.  
* This reduces current by turning off the internal resistor divider that generates VADJ.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_DisableVAdj(void)
{
    SRSS->unPWR_PMIC_CTL4.stcField.u1PMIC_VADJ_DIS = 1u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_EnableVAdj
********************************************************************************
* \brief 
* Device generates VADJ when PMIC is enabled.  This allows the feedback loop to 
* compensate for voltage drops in the PCB and package.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_EnableVAdj(void)
{
    SRSS->unPWR_PMIC_CTL4.stcField.u1PMIC_VADJ_DIS = 0u;
}

/*******************************************************************************
* Function Name: Cy_SysPmic_DisablePmicInDeepSleep
********************************************************************************
* \brief 
* Device operates from internal regulators during DEEPSLEEP.  If PMIC is enabled 
* at the beginning of the DEEPSLEEP transition, hardware changes to the internal 
* regulators and disables the PMIC.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_DisablePmicInDeepSleep(void)
{
    SRSS->unPWR_PMIC_CTL4.stcField.u1PMIC_DPSLP = 0u;
}
                                  
/*******************************************************************************
* Function Name: Cy_SysPmic_EnablePmicInDeepSleep
********************************************************************************
* \brief 
* DEEPSLEEP transition does not change PMIC enable.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysPmic_EnablePmicInDeepSleep(void)
{
    SRSS->unPWR_PMIC_CTL4.stcField.u1PMIC_DPSLP = 1u;
}

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
