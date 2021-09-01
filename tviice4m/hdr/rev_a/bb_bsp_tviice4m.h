/***************************************************************************//**
* \file bb_bsp_tviice4m.h
*
* \brief
* Project specific header
*
* \note
* It contains references to all generated header files and should 
* not be modified.
*
********************************************************************************
* \copyright
* Copyright 2018, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef BB_BSP_TVIICE4M_H
#define BB_BSP_TVIICE4M_H

#ifdef __cplusplus
extern "C" {
#endif


/******************************************************************************/
/******************************************************************************/

// PSVP supports only 176-LQFP Package

#if (CY_USE_PSVP == 1) && defined(CYT2CL8BAS) && defined(CY_MCU_rev_a)

    #include "bsp\bsp_tviice4m_176lqfp_device_reva_psvp.h"
	
#elif (CY_USE_PSVP == 0) && defined(CYT2CL8BAS) && defined(CY_MCU_rev_a) && defined(CY_176LQFP_EVK_REV_A)
	
    #include "bsp_tviice4m_176lqfp_device_reva_evk_reva.h"
       
#else // No Device or PSVP Selected
    
    #error "Choose either a Device based on TVII-C-E-4M Datasheet or CY_USE_PSVP"
    
#endif // #if (CY_USE_PSVP == 1)
  
  
#ifdef __cplusplus
}
#endif

#endif /* BB_BSP_TVIICE4M_H */

/* [] END OF FILE */
