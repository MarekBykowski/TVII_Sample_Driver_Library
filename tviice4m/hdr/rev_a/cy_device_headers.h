/***************************************************************************//**
* \file cy_device_headers.h
*
* \brief
* Common header file to be included by the drivers.
*
* \note
* Generator version: 1.6.0.481
* Database revision: TVIICE4M_CW2112
*
********************************************************************************
* \copyright
* Copyright 2016-2021, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CY_DEVICE_HEADERS_H_
#define _CY_DEVICE_HEADERS_H_

#if defined (CYT2CL8BAS)
    #include "cyt2cl8bas.h"
#elif defined (CYT2C98BAS)
    #include "cyt2c98bas.h"
#elif defined (CYT2CL7BAS)
    #include "cyt2cl7bas.h"
#elif defined (CYT2C97BAS)
    #include "cyt2c97bas.h"
#elif defined (CYT2CLHBAS)
    #include "cyt2clhbas.h"
#elif defined (CYT2C9HBAS)
    #include "cyt2c9hbas.h"
#else
    #error Undefined part number
#endif

#endif /* _CY_DEVICE_HEADERS_H_ */


/* [] END OF FILE */
