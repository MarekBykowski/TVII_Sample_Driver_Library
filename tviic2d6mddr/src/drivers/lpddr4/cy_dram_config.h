/***************************************************************************//**
* \file cy_dram_config.h
* \version 1.0
*
* File in which user can set some external DRAM Parameter which have influence
* on some timing parameter.So user has to check parameters of DRAM which will be 
* used.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(__CY_DRAM_CONFIG_H__)
#define __CY_DRAM_CONFIG_H__


#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */



/*******************************************************************************
    Macros for Timining Parameters defined by JEDEC Spec.
*******************************************************************************/
/*******************************************************************************
    Macros for different channel density in Gb as defined in the JEDEC209-4B
                            CHANNEL_DENSITY                                     
*******************************************************************************/
#define DENSITY_PER_CHANNEL_1GB         0
#define DENSITY_PER_CHANNEL_2GB         1
#define DENSITY_PER_CHANNEL_3GB         2
#define DENSITY_PER_CHANNEL_4GB         3
#define DENSITY_PER_CHANNEL_6GB         4
#define DENSITY_PER_CHANNEL_8GB         5
#define DENSITY_PER_CHANNEL_12GB        6
#define DENSITY_PER_CHANNEL_16GB        7

/*******************************************************************************
    Macros for different data rates as defined in the JEDEC209-4B
                                DATA_RATE
*******************************************************************************/
#define DATA_RATE_533                   1
#define DATA_RATE_1066                  2
#define DATA_RATE_1600                  3
#define DATA_RATE_2133                  4
#define DATA_RATE_2667                  5
#define DATA_RATE_3200                  6
#define DATA_RATE_3733                  7
#define DATA_RATE_4267                  8



/** The memory density per channel which will be used */
#define CHANNEL_DENSITY         DENSITY_PER_CHANNEL_4GB    

/** The data rate which will be used */
#define DATA_RATE               DATA_RATE_1600



#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* __CY_DRAM_CONFIG_H__ */

/** \} group_lpddr */

/* [] END OF FILE */
