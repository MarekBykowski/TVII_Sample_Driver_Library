/***************************************************************************//**
* \file cy_fpdlink.c
* \version 1.0
*
* \brief
* Provides an API implementation of the FPD-Link (fpdlink) driver
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/*****************************************************************************
* Include files
*****************************************************************************/
#include "cy_project.h"
#include "cy_device_headers.h"
#include "cy_fpdlink.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*****************************************************************************
* Local pre-processor symbols/macros ('define')
*****************************************************************************/

#define FPDLINK0_CCM_TRIM_VAL_ADDR  0x17000720
#define FPDLINK1_CCM_TRIM_VAL_ADDR  0x17000721


/*****************************************************************************
* Global variable definitions (declared in header file with 'extern')
*****************************************************************************/

/*****************************************************************************
* Local type definitions ('typedef')
*****************************************************************************/

/*****************************************************************************
* Local variable definitions ('static')
*****************************************************************************/
static volatile stc_VIDEOSS_FPDLINK0_t  * fpdlink_base[] =
{
                                       VIDEOSS0_FPDLINK0,
  #ifdef VIDEOSS0_FPDLINK1
    (volatile stc_VIDEOSS_FPDLINK0_t*) VIDEOSS0_FPDLINK1,
  #endif
};

static uint8_t * fpdlink_ccm_trim_val_ptr[] =
{
    (uint8_t *) FPDLINK0_CCM_TRIM_VAL_ADDR,
  #ifdef VIDEOSS0_FPDLINK1
    (uint8_t *) FPDLINK1_CCM_TRIM_VAL_ADDR    
  #endif
};


/*****************************************************************************
* Local function prototypes ('static')
*****************************************************************************/
static void fpdlinkGenericInitInternal(cy_fpdlink_en_instance_t enFpdlink, const cy_fpdlink_stc_cfg_t * pstcCfg, bool bIsSlaveInDualMode);

/*****************************************************************************
* Function implementation - global ('extern') and local ('static')
*****************************************************************************/


/*******************************************************************************
* Function Name: Cy_Fpdlink_FastInit
****************************************************************************//**
*
* \brief  Initializes the FPD-Link with the most commonly used settings
*
* \param  enFpdlink : Defines the FPD-Link instance to be initialized
* \param  enPllDiv  : FPD-Link PLL divider (needs to match the display clock
*                     divider in VIDEOSS)
*
* \return Result of initialization attempt
*
*******************************************************************************/
cy_fpdlink_en_result_t Cy_Fpdlink_FastInit(cy_fpdlink_en_instance_t enFpdlink, cy_fpdlink_en_pll_out_div_t enPllDiv)
{
    const cy_fpdlink_stc_cfg_t stcCfg = {
        .enBitOrder         = FpdlinkMsbFirst,
        .enCurrent          = FpdlinkCurrent3m36,
        .enPllOutDiv        = enPllDiv,
        .enPllBandwidth     = FpdlinkPllBandwidthDefault,
        .u32PllLockTimeout  = 10000,
    };

    return Cy_Fpdlink_Init(enFpdlink, &stcCfg);
}


/*******************************************************************************
* Function Name: Cy_Fpdlink_Init
****************************************************************************//**
*
* \brief  Initializes the FPD-Link
*
* \param  enFpdlink : Defines the FPD-Link instance to be initialized
* \param  pstcCfg   : The pointer to the init configuration struct
*
* \return Result of initialization attempt
*
*******************************************************************************/
cy_fpdlink_en_result_t Cy_Fpdlink_Init(cy_fpdlink_en_instance_t enFpdlink, const cy_fpdlink_stc_cfg_t * pstcCfg)
{
    uint32_t u32TimeoutCnt = 0;
    
    if(pstcCfg == NULL)
    {
        return CY_FPDLINK_BAD_PARAM;
    }
    
  #ifdef VIDEOSS0_FPDLINK1
    if(enFpdlink == FpdlinkDual01)
    {
        VIDEOSS0_SUBSS0_VIDEOSSCFG->unFPDLINKCFG.stcField.u1FPDLINKSEL = 1; 
        
        fpdlinkGenericInitInternal(Fpdlink0, pstcCfg, false);
        fpdlinkGenericInitInternal(Fpdlink1, pstcCfg, true);
        
        // Power-up the slave first, slave is now waiting to receive the bitclk from the master
        fpdlink_base[Fpdlink1]->unCTL.stcField.u1PD_TX = 0;
        
        // Power-up the master, as soon as it is powered up, it starts emitting the bitclk 
        fpdlink_base[Fpdlink0]->unCTL.stcField.u1PD_TX = 0;        

        // Wait until PLL of master is locked
        while(Cy_Fpdlink_IsPllLocked(Fpdlink0) == false)
        {
            u32TimeoutCnt++;
            if((pstcCfg->u32PllLockTimeout != 0) && (u32TimeoutCnt >= pstcCfg->u32PllLockTimeout))
            {
                fpdlink_base[Fpdlink0]->unCTL.stcField.u1PD_TX = 1; // Power-down again
                fpdlink_base[Fpdlink1]->unCTL.stcField.u1PD_TX = 1; // Power-down again                
                return CY_FPDLINK_ERROR;                
            }
        }

        // Enable the serializers and TX drivers for all lanes
        fpdlink_base[Fpdlink0]->unCMD.stcField.u1LVDS_TX_EN = 1;
        fpdlink_base[Fpdlink1]->unCMD.stcField.u1LVDS_TX_EN = 1;        
    }
    else
  #endif
    {
        fpdlinkGenericInitInternal(enFpdlink, pstcCfg, false);

        // Power-up the master, as soon as it is powered up, it starts emitting the bitclk 
        fpdlink_base[enFpdlink]->unCTL.stcField.u1PD_TX = 0;
        
        // Wait until PLL is locked        
        while(Cy_Fpdlink_IsPllLocked(enFpdlink) == false)
        {
            u32TimeoutCnt++;
            if((pstcCfg->u32PllLockTimeout != 0) && (u32TimeoutCnt >= pstcCfg->u32PllLockTimeout))
            {
                fpdlink_base[enFpdlink]->unCTL.stcField.u1PD_TX = 1; // Power-down again
                return CY_FPDLINK_ERROR;                
            }
        }
        // Enable the serializers and TX drivers for all lanes
        fpdlink_base[enFpdlink]->unCMD.stcField.u1LVDS_TX_EN = 1;
    }

    return CY_FPDLINK_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Fpdlink_DeInit
****************************************************************************//**
*
* \brief  De-Initializes the FPD-Link
*
* \param  enFpdlink : Defines the FPD-Link instance to be de-initialized
*
* \return None
*
*******************************************************************************/
void Cy_Fpdlink_DeInit(cy_fpdlink_en_instance_t enFpdlink)
{
  #ifdef VIDEOSS0_FPDLINK1
    if(enFpdlink == FpdlinkDual01)
    {
        fpdlink_base[Fpdlink1]->unCMD.stcField.u1LVDS_TX_EN = 0; // Disable the serializers and TX drivers for all lanes
        fpdlink_base[Fpdlink0]->unCMD.stcField.u1LVDS_TX_EN = 0; // Disable the serializers and TX drivers for all lanes
        fpdlink_base[Fpdlink1]->unCTL.stcField.u1PD_TX      = 1; // Power-down
        fpdlink_base[Fpdlink0]->unCTL.stcField.u1PD_TX      = 1; // Power-down
        fpdlink_base[Fpdlink1]->unCTL.stcField.u1ENABLED    = 0; // Disable IP
        fpdlink_base[Fpdlink0]->unCTL.stcField.u1ENABLED    = 0; // Disable IP
        
        VIDEOSS0_SUBSS0_VIDEOSSCFG->unFPDLINKCFG.stcField.u1FPDLINKSEL = 0;
    }
    else
  #endif
    {
        fpdlink_base[enFpdlink]->unCMD.stcField.u1LVDS_TX_EN = 0; // Disable the serializers and TX drivers for all lanes
        fpdlink_base[enFpdlink]->unCTL.stcField.u1PD_TX      = 1; // Power-down
        fpdlink_base[enFpdlink]->unCTL.stcField.u1ENABLED    = 0; // Disable IP
    }
}


/*******************************************************************************
* Function Name: Cy_Fpdlink_IsPllLocked
****************************************************************************//**
*
* \brief  Returns PLL lock status
*
* \param  enFpdlink : Defines the FPD-Link instance to be checked
*
* \return 'true' if Pll is locked, otherwise 'false'
*
*******************************************************************************/
bool Cy_Fpdlink_IsPllLocked(cy_fpdlink_en_instance_t enFpdlink)
{
    cy_fpdlink_en_instance_t enFpdlinkToCheck = enFpdlink;
    
  #ifdef VIDEOSS0_FPDLINK1
    if(enFpdlink == FpdlinkDual01)
    {
        // Return PLL status of master FPD-Link #0 which is providing the clock to the slave.
        enFpdlinkToCheck = Fpdlink0;
    }
  #endif
    
    if(fpdlink_base[enFpdlinkToCheck]->unCLK_GEN_STATUS.stcField.u1PLL_LOCK == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}



/*******************************************************************************
* Function Name: fpdlinkGenericInitInternal
****************************************************************************//**
*
* \brief  Initializes some FPD-Link settings
*
* \param  enFpdlink          : Defines the FPD-Link instance to be initialized (single instance!)
* \param  pstcCfg            : The pointer to the init configuration struct
* \param  bIsSlaveInDualMode : Indicates if #enFpdlink is the slave in dual pixel mode configuration
*
* \return none
*
*******************************************************************************/
static void fpdlinkGenericInitInternal(cy_fpdlink_en_instance_t enFpdlink, const cy_fpdlink_stc_cfg_t * pstcCfg, bool bIsSlaveInDualMode)
{
    // Enable IP
    fpdlink_base[enFpdlink]->unCTL.stcField.u1ENABLED = 1;

    // Prepare settings for CLK_GEN_CTL register in local variable
    un_VIDEOSS_FPDLINK0_CLK_GEN_CTL_t unClkGenCfg;
    unClkGenCfg.u32Register          = fpdlink_base[enFpdlink]->unCLK_GEN_CTL.u32Register; // Get current value of register
    unClkGenCfg.stcField.u2FRANGE    = pstcCfg->enPllOutDiv;
    unClkGenCfg.stcField.u2LFCTRL    = pstcCfg->enPllBandwidth; // Same setting for both bitfields
    unClkGenCfg.stcField.u2CN        = pstcCfg->enPllBandwidth; // Same setting for both bitfields
    unClkGenCfg.stcField.u3CA        = pstcCfg->enCurrent;
    unClkGenCfg.stcField.u3CCM       = *(fpdlink_ccm_trim_val_ptr[enFpdlink]);
    unClkGenCfg.stcField.u1MSB_FIRST = pstcCfg->enBitOrder;
    fpdlink_base[enFpdlink]->unCLK_GEN_CTL.u32Register = unClkGenCfg.u32Register; // Write back to register

    // MODE8 bit of "slave" FPD-Link channel in dual pixel mode must be set
    fpdlink_base[enFpdlink]->unCLK_GEN_CMD.stcField.u1MODE8 = (bIsSlaveInDualMode == false) ? 0 : 1;
}


#if defined(__cplusplus)
}
#endif


/* [] END OF FILE */
