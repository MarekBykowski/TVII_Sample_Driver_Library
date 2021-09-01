/***************************************************************************//**
* \file gpio_cyt2cl_176_lqfp.h
*
* \brief
* CYT2CL device GPIO header for 176-LQFP package
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

#ifndef _GPIO_CYT2CL_176_LQFP_H_
#define _GPIO_CYT2CL_176_LQFP_H_

/* Package type */
enum
{
    CY_GPIO_PACKAGE_QFN,
    CY_GPIO_PACKAGE_BGA,
    CY_GPIO_PACKAGE_CSP,
    CY_GPIO_PACKAGE_WLCSP,
    CY_GPIO_PACKAGE_LQFP,
    CY_GPIO_PACKAGE_TEQFP,
    CY_GPIO_PACKAGE_TEQFP_OPB,
};

#define CY_GPIO_PACKAGE_TYPE            CY_GPIO_PACKAGE_LQFP
#define CY_GPIO_PIN_COUNT               176u

/* AMUXBUS Segments */
enum
{
    AMUXBUS_ECT,
    AMUXBUS_MAIN,
    AMUXBUS_TEST,
    AMUXBUS_TESTSRSS,
};

/* AMUX Splitter Controls */
typedef enum
{
    AMUX_SPLIT_CTL_0                = 0x0000u,  /* Left = AMUXBUS_MAIN; Right = AMUXBUS_TEST */
    AMUX_SPLIT_CTL_1                = 0x0001u,  /* Left = AMUXBUS_ECT; Right = AMUXBUS_TEST */
    AMUX_SPLIT_CTL_2                = 0x0002u   /* Left = AMUXBUS_TESTSRSS; Right = AMUXBUS_TEST */
} cy_en_amux_split_t;

/* Port List */
/* PORT 0 (AUTOLVL) */
#define P0_0_GPIO_STD_PORT              GPIO_PRT0
#define P0_0_GPIO_STD_PIN               0u
#define P0_0_GPIO_STD_NUM               0u
#define P0_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P0_1_GPIO_STD_PORT              GPIO_PRT0
#define P0_1_GPIO_STD_PIN               1u
#define P0_1_GPIO_STD_NUM               1u
#define P0_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P0_2_GPIO_STD_PORT              GPIO_PRT0
#define P0_2_GPIO_STD_PIN               2u
#define P0_2_GPIO_STD_NUM               2u
#define P0_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P0_3_GPIO_STD_PORT              GPIO_PRT0
#define P0_3_GPIO_STD_PIN               3u
#define P0_3_GPIO_STD_NUM               3u
#define P0_3_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 1 (AUTOLVL) */
#define P1_0_GPIO_STD_PORT              GPIO_PRT1
#define P1_0_GPIO_STD_PIN               0u
#define P1_0_GPIO_STD_NUM               0u
#define P1_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_1_GPIO_STD_PORT              GPIO_PRT1
#define P1_1_GPIO_STD_PIN               1u
#define P1_1_GPIO_STD_NUM               1u
#define P1_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_2_GPIO_STD_PORT              GPIO_PRT1
#define P1_2_GPIO_STD_PIN               2u
#define P1_2_GPIO_STD_NUM               2u
#define P1_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_3_GPIO_STD_PORT              GPIO_PRT1
#define P1_3_GPIO_STD_PIN               3u
#define P1_3_GPIO_STD_NUM               3u
#define P1_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_4_GPIO_STD_PORT              GPIO_PRT1
#define P1_4_GPIO_STD_PIN               4u
#define P1_4_GPIO_STD_NUM               4u
#define P1_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_5_GPIO_STD_PORT              GPIO_PRT1
#define P1_5_GPIO_STD_PIN               5u
#define P1_5_GPIO_STD_NUM               5u
#define P1_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_6_GPIO_STD_PORT              GPIO_PRT1
#define P1_6_GPIO_STD_PIN               6u
#define P1_6_GPIO_STD_NUM               6u
#define P1_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_7_GPIO_STD_PORT              GPIO_PRT1
#define P1_7_GPIO_STD_PIN               7u
#define P1_7_GPIO_STD_NUM               7u
#define P1_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 2 (AUTOLVL) */
#define P2_0_GPIO_STD_PORT              GPIO_PRT2
#define P2_0_GPIO_STD_PIN               0u
#define P2_0_GPIO_STD_NUM               0u
#define P2_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P2_1_GPIO_STD_PORT              GPIO_PRT2
#define P2_1_GPIO_STD_PIN               1u
#define P2_1_GPIO_STD_NUM               1u
#define P2_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P2_2_GPIO_STD_PORT              GPIO_PRT2
#define P2_2_GPIO_STD_PIN               2u
#define P2_2_GPIO_STD_NUM               2u
#define P2_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P2_3_GPIO_STD_PORT              GPIO_PRT2
#define P2_3_GPIO_STD_PIN               3u
#define P2_3_GPIO_STD_NUM               3u
#define P2_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P2_4_GPIO_STD_PORT              GPIO_PRT2
#define P2_4_GPIO_STD_PIN               4u
#define P2_4_GPIO_STD_NUM               4u
#define P2_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P2_5_GPIO_STD_PORT              GPIO_PRT2
#define P2_5_GPIO_STD_PIN               5u
#define P2_5_GPIO_STD_NUM               5u
#define P2_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P2_6_GPIO_STD_PORT              GPIO_PRT2
#define P2_6_GPIO_STD_PIN               6u
#define P2_6_GPIO_STD_NUM               6u
#define P2_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P2_7_GPIO_STD_PORT              GPIO_PRT2
#define P2_7_GPIO_STD_PIN               7u
#define P2_7_GPIO_STD_NUM               7u
#define P2_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 3 (AUTOLVL) */
#define P3_0_GPIO_STD_PORT              GPIO_PRT3
#define P3_0_GPIO_STD_PIN               0u
#define P3_0_GPIO_STD_NUM               0u
#define P3_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P3_1_GPIO_STD_PORT              GPIO_PRT3
#define P3_1_GPIO_STD_PIN               1u
#define P3_1_GPIO_STD_NUM               1u
#define P3_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P3_2_GPIO_STD_PORT              GPIO_PRT3
#define P3_2_GPIO_STD_PIN               2u
#define P3_2_GPIO_STD_NUM               2u
#define P3_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P3_3_GPIO_STD_PORT              GPIO_PRT3
#define P3_3_GPIO_STD_PIN               3u
#define P3_3_GPIO_STD_NUM               3u
#define P3_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P3_4_GPIO_STD_PORT              GPIO_PRT3
#define P3_4_GPIO_STD_PIN               4u
#define P3_4_GPIO_STD_NUM               4u
#define P3_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P3_5_GPIO_STD_PORT              GPIO_PRT3
#define P3_5_GPIO_STD_PIN               5u
#define P3_5_GPIO_STD_NUM               5u
#define P3_5_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 4 (AUTOLVL) */
#define P4_0_GPIO_STD_PORT              GPIO_PRT4
#define P4_0_GPIO_STD_PIN               0u
#define P4_0_GPIO_STD_NUM               0u
#define P4_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_1_GPIO_STD_PORT              GPIO_PRT4
#define P4_1_GPIO_STD_PIN               1u
#define P4_1_GPIO_STD_NUM               1u
#define P4_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_2_GPIO_STD_PORT              GPIO_PRT4
#define P4_2_GPIO_STD_PIN               2u
#define P4_2_GPIO_STD_NUM               2u
#define P4_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_3_GPIO_STD_PORT              GPIO_PRT4
#define P4_3_GPIO_STD_PIN               3u
#define P4_3_GPIO_STD_NUM               3u
#define P4_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_4_GPIO_STD_PORT              GPIO_PRT4
#define P4_4_GPIO_STD_PIN               4u
#define P4_4_GPIO_STD_NUM               4u
#define P4_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_5_GPIO_STD_PORT              GPIO_PRT4
#define P4_5_GPIO_STD_PIN               5u
#define P4_5_GPIO_STD_NUM               5u
#define P4_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_6_GPIO_STD_PORT              GPIO_PRT4
#define P4_6_GPIO_STD_PIN               6u
#define P4_6_GPIO_STD_NUM               6u
#define P4_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_7_GPIO_STD_PORT              GPIO_PRT4
#define P4_7_GPIO_STD_PIN               7u
#define P4_7_GPIO_STD_NUM               7u
#define P4_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 5 (AUTOLVL) */
#define P5_0_SMC_PORT                   GPIO_PRT5
#define P5_0_SMC_PIN                    0u
#define P5_0_SMC_NUM                    0u
#define P5_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_1_SMC_PORT                   GPIO_PRT5
#define P5_1_SMC_PIN                    1u
#define P5_1_SMC_NUM                    1u
#define P5_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_2_SMC_PORT                   GPIO_PRT5
#define P5_2_SMC_PIN                    2u
#define P5_2_SMC_NUM                    2u
#define P5_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_3_SMC_PORT                   GPIO_PRT5
#define P5_3_SMC_PIN                    3u
#define P5_3_SMC_NUM                    3u
#define P5_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_4_SMC_PORT                   GPIO_PRT5
#define P5_4_SMC_PIN                    4u
#define P5_4_SMC_NUM                    4u
#define P5_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_5_SMC_PORT                   GPIO_PRT5
#define P5_5_SMC_PIN                    5u
#define P5_5_SMC_NUM                    5u
#define P5_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_6_SMC_PORT                   GPIO_PRT5
#define P5_6_SMC_PIN                    6u
#define P5_6_SMC_NUM                    6u
#define P5_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_7_SMC_PORT                   GPIO_PRT5
#define P5_7_SMC_PIN                    7u
#define P5_7_SMC_NUM                    7u
#define P5_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 6 (AUTOLVL) */
#define P6_0_SMC_PORT                   GPIO_PRT6
#define P6_0_SMC_PIN                    0u
#define P6_0_SMC_NUM                    0u
#define P6_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_1_SMC_PORT                   GPIO_PRT6
#define P6_1_SMC_PIN                    1u
#define P6_1_SMC_NUM                    1u
#define P6_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_2_SMC_PORT                   GPIO_PRT6
#define P6_2_SMC_PIN                    2u
#define P6_2_SMC_NUM                    2u
#define P6_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_3_SMC_PORT                   GPIO_PRT6
#define P6_3_SMC_PIN                    3u
#define P6_3_SMC_NUM                    3u
#define P6_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_4_SMC_PORT                   GPIO_PRT6
#define P6_4_SMC_PIN                    4u
#define P6_4_SMC_NUM                    4u
#define P6_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_5_SMC_PORT                   GPIO_PRT6
#define P6_5_SMC_PIN                    5u
#define P6_5_SMC_NUM                    5u
#define P6_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_6_SMC_PORT                   GPIO_PRT6
#define P6_6_SMC_PIN                    6u
#define P6_6_SMC_NUM                    6u
#define P6_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_7_SMC_PORT                   GPIO_PRT6
#define P6_7_SMC_PIN                    7u
#define P6_7_SMC_NUM                    7u
#define P6_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 7 (AUTOLVL) */
#define P7_0_SMC_PORT                   GPIO_PRT7
#define P7_0_SMC_PIN                    0u
#define P7_0_SMC_NUM                    0u
#define P7_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_1_SMC_PORT                   GPIO_PRT7
#define P7_1_SMC_PIN                    1u
#define P7_1_SMC_NUM                    1u
#define P7_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_2_SMC_PORT                   GPIO_PRT7
#define P7_2_SMC_PIN                    2u
#define P7_2_SMC_NUM                    2u
#define P7_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_3_SMC_PORT                   GPIO_PRT7
#define P7_3_SMC_PIN                    3u
#define P7_3_SMC_NUM                    3u
#define P7_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_4_SMC_PORT                   GPIO_PRT7
#define P7_4_SMC_PIN                    4u
#define P7_4_SMC_NUM                    4u
#define P7_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_5_SMC_PORT                   GPIO_PRT7
#define P7_5_SMC_PIN                    5u
#define P7_5_SMC_NUM                    5u
#define P7_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_6_SMC_PORT                   GPIO_PRT7
#define P7_6_SMC_PIN                    6u
#define P7_6_SMC_NUM                    6u
#define P7_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_7_SMC_PORT                   GPIO_PRT7
#define P7_7_SMC_PIN                    7u
#define P7_7_SMC_NUM                    7u
#define P7_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 8 (HSIO, AUTOLVL, SLEW_EXT, DRIVE_EXT, SLEW_WIDTH, DRIVE_WIDTH) */
#define P8_0_HSIO_STDLN_PORT            GPIO_PRT8
#define P8_0_HSIO_STDLN_PIN             0u
#define P8_0_HSIO_STDLN_NUM             0u
#define P8_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_1_HSIO_STDLN_PORT            GPIO_PRT8
#define P8_1_HSIO_STDLN_PIN             1u
#define P8_1_HSIO_STDLN_NUM             1u
#define P8_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_2_HSIO_STDLN_PORT            GPIO_PRT8
#define P8_2_HSIO_STDLN_PIN             2u
#define P8_2_HSIO_STDLN_NUM             2u
#define P8_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_3_HSIO_STDLN_PORT            GPIO_PRT8
#define P8_3_HSIO_STDLN_PIN             3u
#define P8_3_HSIO_STDLN_NUM             3u
#define P8_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_4_HSIO_STDLN_PORT            GPIO_PRT8
#define P8_4_HSIO_STDLN_PIN             4u
#define P8_4_HSIO_STDLN_NUM             4u
#define P8_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_5_HSIO_STDLN_PORT            GPIO_PRT8
#define P8_5_HSIO_STDLN_PIN             5u
#define P8_5_HSIO_STDLN_NUM             5u
#define P8_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_6_HSIO_STDLN_PORT            GPIO_PRT8
#define P8_6_HSIO_STDLN_PIN             6u
#define P8_6_HSIO_STDLN_NUM             6u
#define P8_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_7_HSIO_STDLN_PORT            GPIO_PRT8
#define P8_7_HSIO_STDLN_PIN             7u
#define P8_7_HSIO_STDLN_NUM             7u
#define P8_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 9 (HSIO, AUTOLVL, SLEW_EXT, DRIVE_EXT, SLEW_WIDTH, DRIVE_WIDTH) */
#define P9_0_HSIO_STDLN_PORT            GPIO_PRT9
#define P9_0_HSIO_STDLN_PIN             0u
#define P9_0_HSIO_STDLN_NUM             0u
#define P9_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_1_HSIO_STDLN_PORT            GPIO_PRT9
#define P9_1_HSIO_STDLN_PIN             1u
#define P9_1_HSIO_STDLN_NUM             1u
#define P9_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_2_HSIO_STDLN_PORT            GPIO_PRT9
#define P9_2_HSIO_STDLN_PIN             2u
#define P9_2_HSIO_STDLN_NUM             2u
#define P9_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_3_HSIO_STDLN_PORT            GPIO_PRT9
#define P9_3_HSIO_STDLN_PIN             3u
#define P9_3_HSIO_STDLN_NUM             3u
#define P9_3_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 10 (AUTOLVL) */
#define P10_0_GPIO_STD_PORT             GPIO_PRT10
#define P10_0_GPIO_STD_PIN              0u
#define P10_0_GPIO_STD_NUM              0u
#define P10_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P10_1_GPIO_STD_PORT             GPIO_PRT10
#define P10_1_GPIO_STD_PIN              1u
#define P10_1_GPIO_STD_NUM              1u
#define P10_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P10_2_GPIO_STD_PORT             GPIO_PRT10
#define P10_2_GPIO_STD_PIN              2u
#define P10_2_GPIO_STD_NUM              2u
#define P10_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P10_3_GPIO_STD_PORT             GPIO_PRT10
#define P10_3_GPIO_STD_PIN              3u
#define P10_3_GPIO_STD_NUM              3u
#define P10_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P10_4_GPIO_STD_PORT             GPIO_PRT10
#define P10_4_GPIO_STD_PIN              4u
#define P10_4_GPIO_STD_NUM              4u
#define P10_4_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 11 (AUTOLVL) */
#define P11_0_GPIO_STD_PORT             GPIO_PRT11
#define P11_0_GPIO_STD_PIN              0u
#define P11_0_GPIO_STD_NUM              0u
#define P11_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_1_GPIO_STD_PORT             GPIO_PRT11
#define P11_1_GPIO_STD_PIN              1u
#define P11_1_GPIO_STD_NUM              1u
#define P11_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_2_GPIO_STD_PORT             GPIO_PRT11
#define P11_2_GPIO_STD_PIN              2u
#define P11_2_GPIO_STD_NUM              2u
#define P11_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_3_GPIO_STD_PORT             GPIO_PRT11
#define P11_3_GPIO_STD_PIN              3u
#define P11_3_GPIO_STD_NUM              3u
#define P11_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_4_GPIO_STD_PORT             GPIO_PRT11
#define P11_4_GPIO_STD_PIN              4u
#define P11_4_GPIO_STD_NUM              4u
#define P11_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_5_GPIO_STD_PORT             GPIO_PRT11
#define P11_5_GPIO_STD_PIN              5u
#define P11_5_GPIO_STD_NUM              5u
#define P11_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_6_GPIO_STD_PORT             GPIO_PRT11
#define P11_6_GPIO_STD_PIN              6u
#define P11_6_GPIO_STD_NUM              6u
#define P11_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_7_GPIO_STD_PORT             GPIO_PRT11
#define P11_7_GPIO_STD_PIN              7u
#define P11_7_GPIO_STD_NUM              7u
#define P11_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 12 (AUTOLVL) */
#define P12_0_GPIO_STD_PORT             GPIO_PRT12
#define P12_0_GPIO_STD_PIN              0u
#define P12_0_GPIO_STD_NUM              0u
#define P12_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_1_GPIO_STD_PORT             GPIO_PRT12
#define P12_1_GPIO_STD_PIN              1u
#define P12_1_GPIO_STD_NUM              1u
#define P12_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_2_GPIO_STD_PORT             GPIO_PRT12
#define P12_2_GPIO_STD_PIN              2u
#define P12_2_GPIO_STD_NUM              2u
#define P12_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_3_GPIO_STD_PORT             GPIO_PRT12
#define P12_3_GPIO_STD_PIN              3u
#define P12_3_GPIO_STD_NUM              3u
#define P12_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_4_GPIO_STD_PORT             GPIO_PRT12
#define P12_4_GPIO_STD_PIN              4u
#define P12_4_GPIO_STD_NUM              4u
#define P12_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_5_GPIO_STD_PORT             GPIO_PRT12
#define P12_5_GPIO_STD_PIN              5u
#define P12_5_GPIO_STD_NUM              5u
#define P12_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_6_GPIO_STD_PORT             GPIO_PRT12
#define P12_6_GPIO_STD_PIN              6u
#define P12_6_GPIO_STD_NUM              6u
#define P12_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_7_GPIO_STD_PORT             GPIO_PRT12
#define P12_7_GPIO_STD_PIN              7u
#define P12_7_GPIO_STD_NUM              7u
#define P12_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 13 (AUTOLVL) */
#define P13_0_GPIO_STD_PORT             GPIO_PRT13
#define P13_0_GPIO_STD_PIN              0u
#define P13_0_GPIO_STD_NUM              0u
#define P13_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P13_1_GPIO_STD_PORT             GPIO_PRT13
#define P13_1_GPIO_STD_PIN              1u
#define P13_1_GPIO_STD_NUM              1u
#define P13_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P13_2_GPIO_STD_PORT             GPIO_PRT13
#define P13_2_GPIO_STD_PIN              2u
#define P13_2_GPIO_STD_NUM              2u
#define P13_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P13_3_GPIO_STD_PORT             GPIO_PRT13
#define P13_3_GPIO_STD_PIN              3u
#define P13_3_GPIO_STD_NUM              3u
#define P13_3_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 14 (AUTOLVL) */
#define P14_0_GPIO_ENH_PORT             GPIO_PRT14
#define P14_0_GPIO_ENH_PIN              0u
#define P14_0_GPIO_ENH_NUM              0u
#define P14_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_1_GPIO_ENH_PORT             GPIO_PRT14
#define P14_1_GPIO_ENH_PIN              1u
#define P14_1_GPIO_ENH_NUM              1u
#define P14_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_2_GPIO_ENH_PORT             GPIO_PRT14
#define P14_2_GPIO_ENH_PIN              2u
#define P14_2_GPIO_ENH_NUM              2u
#define P14_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_3_GPIO_ENH_PORT             GPIO_PRT14
#define P14_3_GPIO_ENH_PIN              3u
#define P14_3_GPIO_ENH_NUM              3u
#define P14_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_4_GPIO_ENH_PORT             GPIO_PRT14
#define P14_4_GPIO_ENH_PIN              4u
#define P14_4_GPIO_ENH_NUM              4u
#define P14_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_5_GPIO_ENH_PORT             GPIO_PRT14
#define P14_5_GPIO_ENH_PIN              5u
#define P14_5_GPIO_ENH_NUM              5u
#define P14_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_6_GPIO_ENH_PORT             GPIO_PRT14
#define P14_6_GPIO_ENH_PIN              6u
#define P14_6_GPIO_ENH_NUM              6u
#define P14_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_7_GPIO_ENH_PORT             GPIO_PRT14
#define P14_7_GPIO_ENH_PIN              7u
#define P14_7_GPIO_ENH_NUM              7u
#define P14_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 15 (AUTOLVL) */
#define P15_0_GPIO_STD_PORT             GPIO_PRT15
#define P15_0_GPIO_STD_PIN              0u
#define P15_0_GPIO_STD_NUM              0u
#define P15_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_1_GPIO_STD_PORT             GPIO_PRT15
#define P15_1_GPIO_STD_PIN              1u
#define P15_1_GPIO_STD_NUM              1u
#define P15_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_2_GPIO_STD_PORT             GPIO_PRT15
#define P15_2_GPIO_STD_PIN              2u
#define P15_2_GPIO_STD_NUM              2u
#define P15_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_3_GPIO_STD_PORT             GPIO_PRT15
#define P15_3_GPIO_STD_PIN              3u
#define P15_3_GPIO_STD_NUM              3u
#define P15_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_4_GPIO_STD_PORT             GPIO_PRT15
#define P15_4_GPIO_STD_PIN              4u
#define P15_4_GPIO_STD_NUM              4u
#define P15_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_5_GPIO_STD_PORT             GPIO_PRT15
#define P15_5_GPIO_STD_PIN              5u
#define P15_5_GPIO_STD_NUM              5u
#define P15_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_6_GPIO_STD_PORT             GPIO_PRT15
#define P15_6_GPIO_STD_PIN              6u
#define P15_6_GPIO_STD_NUM              6u
#define P15_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_7_GPIO_STD_PORT             GPIO_PRT15
#define P15_7_GPIO_STD_PIN              7u
#define P15_7_GPIO_STD_NUM              7u
#define P15_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 16 (AUTOLVL) */
#define P16_0_GPIO_STD_PORT             GPIO_PRT16
#define P16_0_GPIO_STD_PIN              0u
#define P16_0_GPIO_STD_NUM              0u
#define P16_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_1_GPIO_STD_PORT             GPIO_PRT16
#define P16_1_GPIO_STD_PIN              1u
#define P16_1_GPIO_STD_NUM              1u
#define P16_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_2_GPIO_STD_PORT             GPIO_PRT16
#define P16_2_GPIO_STD_PIN              2u
#define P16_2_GPIO_STD_NUM              2u
#define P16_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_3_GPIO_STD_PORT             GPIO_PRT16
#define P16_3_GPIO_STD_PIN              3u
#define P16_3_GPIO_STD_NUM              3u
#define P16_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_4_GPIO_STD_PORT             GPIO_PRT16
#define P16_4_GPIO_STD_PIN              4u
#define P16_4_GPIO_STD_NUM              4u
#define P16_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_5_GPIO_STD_PORT             GPIO_PRT16
#define P16_5_GPIO_STD_PIN              5u
#define P16_5_GPIO_STD_NUM              5u
#define P16_5_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 17 (AUTOLVL) */
#define P17_0_GPIO_STD_PORT             GPIO_PRT17
#define P17_0_GPIO_STD_PIN              0u
#define P17_0_GPIO_STD_NUM              0u
#define P17_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P17_1_GPIO_STD_PORT             GPIO_PRT17
#define P17_1_GPIO_STD_PIN              1u
#define P17_1_GPIO_STD_NUM              1u
#define P17_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P17_2_GPIO_STD_PORT             GPIO_PRT17
#define P17_2_GPIO_STD_PIN              2u
#define P17_2_GPIO_STD_NUM              2u
#define P17_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P17_3_GPIO_STD_PORT             GPIO_PRT17
#define P17_3_GPIO_STD_PIN              3u
#define P17_3_GPIO_STD_NUM              3u
#define P17_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P17_4_GPIO_STD_PORT             GPIO_PRT17
#define P17_4_GPIO_STD_PIN              4u
#define P17_4_GPIO_STD_NUM              4u
#define P17_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P17_5_GPIO_STD_PORT             GPIO_PRT17
#define P17_5_GPIO_STD_PIN              5u
#define P17_5_GPIO_STD_NUM              5u
#define P17_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P17_6_GPIO_STD_PORT             GPIO_PRT17
#define P17_6_GPIO_STD_PIN              6u
#define P17_6_GPIO_STD_NUM              6u
#define P17_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P17_7_GPIO_STD_PORT             GPIO_PRT17
#define P17_7_GPIO_STD_PIN              7u
#define P17_7_GPIO_STD_NUM              7u
#define P17_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 18 (AUTOLVL) */
#define P18_0_GPIO_STD_PORT             GPIO_PRT18
#define P18_0_GPIO_STD_PIN              0u
#define P18_0_GPIO_STD_NUM              0u
#define P18_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_1_GPIO_STD_PORT             GPIO_PRT18
#define P18_1_GPIO_STD_PIN              1u
#define P18_1_GPIO_STD_NUM              1u
#define P18_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_2_GPIO_STD_PORT             GPIO_PRT18
#define P18_2_GPIO_STD_PIN              2u
#define P18_2_GPIO_STD_NUM              2u
#define P18_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_3_GPIO_STD_PORT             GPIO_PRT18
#define P18_3_GPIO_STD_PIN              3u
#define P18_3_GPIO_STD_NUM              3u
#define P18_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_4_GPIO_STD_PORT             GPIO_PRT18
#define P18_4_GPIO_STD_PIN              4u
#define P18_4_GPIO_STD_NUM              4u
#define P18_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_5_GPIO_STD_PORT             GPIO_PRT18
#define P18_5_GPIO_STD_PIN              5u
#define P18_5_GPIO_STD_NUM              5u
#define P18_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_6_GPIO_STD_PORT             GPIO_PRT18
#define P18_6_GPIO_STD_PIN              6u
#define P18_6_GPIO_STD_NUM              6u
#define P18_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_7_GPIO_STD_PORT             GPIO_PRT18
#define P18_7_GPIO_STD_PIN              7u
#define P18_7_GPIO_STD_NUM              7u
#define P18_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 19 (AUTOLVL) */
#define P19_0_GPIO_STD_PORT             GPIO_PRT19
#define P19_0_GPIO_STD_PIN              0u
#define P19_0_GPIO_STD_NUM              0u
#define P19_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_1_GPIO_STD_PORT             GPIO_PRT19
#define P19_1_GPIO_STD_PIN              1u
#define P19_1_GPIO_STD_NUM              1u
#define P19_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_2_GPIO_STD_PORT             GPIO_PRT19
#define P19_2_GPIO_STD_PIN              2u
#define P19_2_GPIO_STD_NUM              2u
#define P19_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_3_GPIO_STD_PORT             GPIO_PRT19
#define P19_3_GPIO_STD_PIN              3u
#define P19_3_GPIO_STD_NUM              3u
#define P19_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_4_GPIO_STD_PORT             GPIO_PRT19
#define P19_4_GPIO_STD_PIN              4u
#define P19_4_GPIO_STD_NUM              4u
#define P19_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_5_GPIO_STD_PORT             GPIO_PRT19
#define P19_5_GPIO_STD_PIN              5u
#define P19_5_GPIO_STD_NUM              5u
#define P19_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_6_GPIO_STD_PORT             GPIO_PRT19
#define P19_6_GPIO_STD_PIN              6u
#define P19_6_GPIO_STD_NUM              6u
#define P19_6_AMUXSEGMENT               AMUXBUS_MAIN

/* Analog Connections */
#define PASS0_I_TEMP_KELVIN_PORT        0u
#define PASS0_I_TEMP_KELVIN_PIN         2u
#define PASS0_SARMUX_PADS0_PORT         1u
#define PASS0_SARMUX_PADS0_PIN          0u
#define PASS0_SARMUX_PADS1_PORT         1u
#define PASS0_SARMUX_PADS1_PIN          1u
#define PASS0_SARMUX_PADS10_PORT        3u
#define PASS0_SARMUX_PADS10_PIN         0u
#define PASS0_SARMUX_PADS11_PORT        3u
#define PASS0_SARMUX_PADS11_PIN         1u
#define PASS0_SARMUX_PADS12_PORT        3u
#define PASS0_SARMUX_PADS12_PIN         2u
#define PASS0_SARMUX_PADS13_PORT        3u
#define PASS0_SARMUX_PADS13_PIN         3u
#define PASS0_SARMUX_PADS14_PORT        3u
#define PASS0_SARMUX_PADS14_PIN         4u
#define PASS0_SARMUX_PADS15_PORT        3u
#define PASS0_SARMUX_PADS15_PIN         5u
#define PASS0_SARMUX_PADS16_PORT        4u
#define PASS0_SARMUX_PADS16_PIN         0u
#define PASS0_SARMUX_PADS17_PORT        4u
#define PASS0_SARMUX_PADS17_PIN         1u
#define PASS0_SARMUX_PADS18_PORT        4u
#define PASS0_SARMUX_PADS18_PIN         2u
#define PASS0_SARMUX_PADS19_PORT        4u
#define PASS0_SARMUX_PADS19_PIN         3u
#define PASS0_SARMUX_PADS2_PORT         1u
#define PASS0_SARMUX_PADS2_PIN          2u
#define PASS0_SARMUX_PADS20_PORT        4u
#define PASS0_SARMUX_PADS20_PIN         4u
#define PASS0_SARMUX_PADS21_PORT        4u
#define PASS0_SARMUX_PADS21_PIN         5u
#define PASS0_SARMUX_PADS22_PORT        4u
#define PASS0_SARMUX_PADS22_PIN         6u
#define PASS0_SARMUX_PADS23_PORT        4u
#define PASS0_SARMUX_PADS23_PIN         7u
#define PASS0_SARMUX_PADS3_PORT         1u
#define PASS0_SARMUX_PADS3_PIN          3u
#define PASS0_SARMUX_PADS32_PORT        5u
#define PASS0_SARMUX_PADS32_PIN         0u
#define PASS0_SARMUX_PADS33_PORT        5u
#define PASS0_SARMUX_PADS33_PIN         1u
#define PASS0_SARMUX_PADS34_PORT        5u
#define PASS0_SARMUX_PADS34_PIN         2u
#define PASS0_SARMUX_PADS35_PORT        5u
#define PASS0_SARMUX_PADS35_PIN         3u
#define PASS0_SARMUX_PADS36_PORT        5u
#define PASS0_SARMUX_PADS36_PIN         4u
#define PASS0_SARMUX_PADS37_PORT        5u
#define PASS0_SARMUX_PADS37_PIN         5u
#define PASS0_SARMUX_PADS38_PORT        5u
#define PASS0_SARMUX_PADS38_PIN         6u
#define PASS0_SARMUX_PADS39_PORT        5u
#define PASS0_SARMUX_PADS39_PIN         7u
#define PASS0_SARMUX_PADS4_PORT         2u
#define PASS0_SARMUX_PADS4_PIN          0u
#define PASS0_SARMUX_PADS40_PORT        6u
#define PASS0_SARMUX_PADS40_PIN         0u
#define PASS0_SARMUX_PADS41_PORT        6u
#define PASS0_SARMUX_PADS41_PIN         1u
#define PASS0_SARMUX_PADS42_PORT        6u
#define PASS0_SARMUX_PADS42_PIN         2u
#define PASS0_SARMUX_PADS43_PORT        6u
#define PASS0_SARMUX_PADS43_PIN         3u
#define PASS0_SARMUX_PADS44_PORT        6u
#define PASS0_SARMUX_PADS44_PIN         4u
#define PASS0_SARMUX_PADS45_PORT        6u
#define PASS0_SARMUX_PADS45_PIN         5u
#define PASS0_SARMUX_PADS46_PORT        6u
#define PASS0_SARMUX_PADS46_PIN         6u
#define PASS0_SARMUX_PADS47_PORT        6u
#define PASS0_SARMUX_PADS47_PIN         7u
#define PASS0_SARMUX_PADS48_PORT        7u
#define PASS0_SARMUX_PADS48_PIN         0u
#define PASS0_SARMUX_PADS49_PORT        7u
#define PASS0_SARMUX_PADS49_PIN         1u
#define PASS0_SARMUX_PADS5_PORT         2u
#define PASS0_SARMUX_PADS5_PIN          1u
#define PASS0_SARMUX_PADS50_PORT        7u
#define PASS0_SARMUX_PADS50_PIN         2u
#define PASS0_SARMUX_PADS51_PORT        7u
#define PASS0_SARMUX_PADS51_PIN         3u
#define PASS0_SARMUX_PADS52_PORT        7u
#define PASS0_SARMUX_PADS52_PIN         4u
#define PASS0_SARMUX_PADS53_PORT        7u
#define PASS0_SARMUX_PADS53_PIN         5u
#define PASS0_SARMUX_PADS54_PORT        7u
#define PASS0_SARMUX_PADS54_PIN         6u
#define PASS0_SARMUX_PADS55_PORT        7u
#define PASS0_SARMUX_PADS55_PIN         7u
#define PASS0_SARMUX_PADS6_PORT         2u
#define PASS0_SARMUX_PADS6_PIN          2u
#define PASS0_SARMUX_PADS7_PORT         2u
#define PASS0_SARMUX_PADS7_PIN          3u
#define PASS0_SARMUX_PADS8_PORT         2u
#define PASS0_SARMUX_PADS8_PIN          4u
#define PASS0_SARMUX_PADS9_PORT         2u
#define PASS0_SARMUX_PADS9_PIN          7u
#define PASS0_VB_TEMP_KELVIN_PORT       2u
#define PASS0_VB_TEMP_KELVIN_PIN        6u
#define PASS0_VE_TEMP_KELVIN_PORT       2u
#define PASS0_VE_TEMP_KELVIN_PIN        4u
#define SRSS_ADFT_PIN0_PORT             2u
#define SRSS_ADFT_PIN0_PIN              6u
#define SRSS_ADFT_PIN1_PORT             2u
#define SRSS_ADFT_PIN1_PIN              5u
#define SRSS_ADFT_POR_PAD_HV_PORT       18u
#define SRSS_ADFT_POR_PAD_HV_PIN        6u
#define SRSS_ECO_IN_PORT                0u
#define SRSS_ECO_IN_PIN                 2u
#define SRSS_ECO_OUT_PORT               0u
#define SRSS_ECO_OUT_PIN                3u
#define SRSS_LPECO_IN_PORT              0u
#define SRSS_LPECO_IN_PIN               0u
#define SRSS_LPECO_OUT_PORT             0u
#define SRSS_LPECO_OUT_PIN              1u
#define SRSS_VEXT_REF_REG_PORT          0u
#define SRSS_VEXT_REF_REG_PIN           3u
#define SRSS_WCO_IN_PORT                0u
#define SRSS_WCO_IN_PIN                 0u
#define SRSS_WCO_OUT_PORT               0u
#define SRSS_WCO_OUT_PIN                1u

/* HSIOM Connections */
typedef enum
{
    /* Generic HSIOM connections */
    HSIOM_SEL_GPIO                  =  0,       /* GPIO controls 'out' */
    HSIOM_SEL_GPIO_DSI              =  1,       /* GPIO controls 'out', DSI controls 'output enable' */
    HSIOM_SEL_DSI_DSI               =  2,       /* DSI controls 'out' and 'output enable' */
    HSIOM_SEL_DSI_GPIO              =  3,       /* DSI controls 'out', GPIO controls 'output enable' */
    HSIOM_SEL_AMUXA                 =  4,       /* Analog mux bus A */
    HSIOM_SEL_AMUXB                 =  5,       /* Analog mux bus B */
    HSIOM_SEL_AMUXA_DSI             =  6,       /* Analog mux bus A, DSI control */
    HSIOM_SEL_AMUXB_DSI             =  7,       /* Analog mux bus B, DSI control */
    HSIOM_SEL_ACT_0                 =  8,       /* Active functionality 0 */
    HSIOM_SEL_ACT_1                 =  9,       /* Active functionality 1 */
    HSIOM_SEL_ACT_2                 = 10,       /* Active functionality 2 */
    HSIOM_SEL_ACT_3                 = 11,       /* Active functionality 3 */
    HSIOM_SEL_DS_0                  = 12,       /* DeepSleep functionality 0 */
    HSIOM_SEL_DS_1                  = 13,       /* DeepSleep functionality 1 */
    HSIOM_SEL_DS_2                  = 14,       /* DeepSleep functionality 2 */
    HSIOM_SEL_DS_3                  = 15,       /* DeepSleep functionality 3 */
    HSIOM_SEL_ACT_4                 = 16,       /* Active functionality 4 */
    HSIOM_SEL_ACT_5                 = 17,       /* Active functionality 5 */
    HSIOM_SEL_ACT_6                 = 18,       /* Active functionality 6 */
    HSIOM_SEL_ACT_7                 = 19,       /* Active functionality 7 */
    HSIOM_SEL_ACT_8                 = 20,       /* Active functionality 8 */
    HSIOM_SEL_ACT_9                 = 21,       /* Active functionality 9 */
    HSIOM_SEL_ACT_10                = 22,       /* Active functionality 10 */
    HSIOM_SEL_ACT_11                = 23,       /* Active functionality 11 */
    HSIOM_SEL_ACT_12                = 24,       /* Active functionality 12 */
    HSIOM_SEL_ACT_13                = 25,       /* Active functionality 13 */
    HSIOM_SEL_ACT_14                = 26,       /* Active functionality 14 */
    HSIOM_SEL_ACT_15                = 27,       /* Active functionality 15 */
    HSIOM_SEL_DS_4                  = 28,       /* DeepSleep functionality 4 */
    HSIOM_SEL_DS_5                  = 29,       /* DeepSleep functionality 5 */
    HSIOM_SEL_DS_6                  = 30,       /* DeepSleep functionality 6 */
    HSIOM_SEL_DS_7                  = 31,       /* DeepSleep functionality 7 */

    /* P0.0 */
    P0_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_0_AMUXA                      =  4,       /* Analog mux bus A */
    P0_0_AMUXB                      =  5,       /* Analog mux bus B */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_1_AMUXA                      =  4,       /* Analog mux bus A */
    P0_1_AMUXB                      =  5,       /* Analog mux bus B */

    /* P0.2 */
    P0_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_2_AMUXA                      =  4,       /* Analog mux bus A */
    P0_2_AMUXB                      =  5,       /* Analog mux bus B */
    P0_2_SRSS_EXT_CLK               = 26,       /* Digital Active - srss.ext_clk:0 */
    P0_2_SRSS_DDFT_PIN_IN1          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[1]:1 */

    /* P0.3 */
    P0_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_3_AMUXA                      =  4,       /* Analog mux bus A */
    P0_3_AMUXB                      =  5,       /* Analog mux bus B */

    /* P1.0 */
    P1_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_0_AMUXA                      =  4,       /* Analog mux bus A */
    P1_0_AMUXB                      =  5,       /* Analog mux bus B */
    P1_0_TCPWM0_LINE512             =  8,       /* Digital Active - tcpwm[0].line[512]:0 */
    P1_0_TCPWM0_LINE_COMPL527       =  9,       /* Digital Active - tcpwm[0].line_compl[527]:0 */
    P1_0_TCPWM0_TR_ONE_CNT_IN526    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[526]:0 */
    P1_0_SCB7_SPI_CLK               = 22,       /* Digital Active - scb[7].spi_clk:0 */
    P1_0_SCB7_UART_RX               = 23,       /* Digital Active - scb[7].uart_rx:0 */
    P1_0_SCB7_I2C_SDA               = 24,       /* Digital Active - scb[7].i2c_sda:0 */
    P1_0_CPUSS_FAULT_OUT0           = 27,       /* Digital Active - cpuss.fault_out[0]:0 */

    /* P1.1 */
    P1_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_1_AMUXA                      =  4,       /* Analog mux bus A */
    P1_1_AMUXB                      =  5,       /* Analog mux bus B */
    P1_1_TCPWM0_LINE513             =  8,       /* Digital Active - tcpwm[0].line[513]:0 */
    P1_1_TCPWM0_LINE_COMPL512       =  9,       /* Digital Active - tcpwm[0].line_compl[512]:0 */
    P1_1_TCPWM0_TR_ONE_CNT_IN527    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[527]:0 */
    P1_1_SCB7_SPI_MOSI              = 22,       /* Digital Active - scb[7].spi_mosi:0 */
    P1_1_SCB7_UART_TX               = 23,       /* Digital Active - scb[7].uart_tx:0 */
    P1_1_SCB7_I2C_SCL               = 24,       /* Digital Active - scb[7].i2c_scl:0 */
    P1_1_CPUSS_FAULT_OUT1           = 27,       /* Digital Active - cpuss.fault_out[1]:0 */

    /* P1.2 */
    P1_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_2_AMUXA                      =  4,       /* Analog mux bus A */
    P1_2_AMUXB                      =  5,       /* Analog mux bus B */
    P1_2_TCPWM0_LINE514             =  8,       /* Digital Active - tcpwm[0].line[514]:0 */
    P1_2_TCPWM0_LINE_COMPL513       =  9,       /* Digital Active - tcpwm[0].line_compl[513]:0 */
    P1_2_TCPWM0_TR_ONE_CNT_IN512    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[512]:0 */
    P1_2_SCB7_SPI_MISO              = 22,       /* Digital Active - scb[7].spi_miso:0 */
    P1_2_SCB7_UART_RTS              = 23,       /* Digital Active - scb[7].uart_rts:0 */
    P1_2_CPUSS_FAULT_OUT2           = 27,       /* Digital Active - cpuss.fault_out[2]:0 */

    /* P1.3 */
    P1_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_3_AMUXA                      =  4,       /* Analog mux bus A */
    P1_3_AMUXB                      =  5,       /* Analog mux bus B */
    P1_3_TCPWM0_LINE515             =  8,       /* Digital Active - tcpwm[0].line[515]:0 */
    P1_3_TCPWM0_LINE_COMPL514       =  9,       /* Digital Active - tcpwm[0].line_compl[514]:0 */
    P1_3_TCPWM0_TR_ONE_CNT_IN513    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[513]:0 */
    P1_3_SCB7_SPI_SELECT0           = 22,       /* Digital Active - scb[7].spi_select0:0 */
    P1_3_SCB7_UART_CTS              = 23,       /* Digital Active - scb[7].uart_cts:0 */
    P1_3_CPUSS_FAULT_OUT3           = 27,       /* Digital Active - cpuss.fault_out[3]:0 */

    /* P1.4 */
    P1_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_4_AMUXA                      =  4,       /* Analog mux bus A */
    P1_4_AMUXB                      =  5,       /* Analog mux bus B */
    P1_4_TCPWM0_LINE516             =  8,       /* Digital Active - tcpwm[0].line[516]:0 */
    P1_4_TCPWM0_LINE_COMPL515       =  9,       /* Digital Active - tcpwm[0].line_compl[515]:0 */
    P1_4_TCPWM0_TR_ONE_CNT_IN514    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[514]:0 */
    P1_4_SCB7_SPI_SELECT1           = 22,       /* Digital Active - scb[7].spi_select1:0 */

    /* P1.5 */
    P1_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_5_AMUXA                      =  4,       /* Analog mux bus A */
    P1_5_AMUXB                      =  5,       /* Analog mux bus B */
    P1_5_TCPWM0_LINE517             =  8,       /* Digital Active - tcpwm[0].line[517]:0 */
    P1_5_TCPWM0_LINE_COMPL516       =  9,       /* Digital Active - tcpwm[0].line_compl[516]:0 */
    P1_5_TCPWM0_TR_ONE_CNT_IN515    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[515]:0 */

    /* P1.6 */
    P1_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_6_AMUXA                      =  4,       /* Analog mux bus A */
    P1_6_AMUXB                      =  5,       /* Analog mux bus B */
    P1_6_TCPWM0_LINE518             =  8,       /* Digital Active - tcpwm[0].line[518]:0 */
    P1_6_TCPWM0_LINE_COMPL517       =  9,       /* Digital Active - tcpwm[0].line_compl[517]:0 */
    P1_6_TCPWM0_TR_ONE_CNT_IN516    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[516]:0 */

    /* P1.7 */
    P1_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_7_AMUXA                      =  4,       /* Analog mux bus A */
    P1_7_AMUXB                      =  5,       /* Analog mux bus B */
    P1_7_TCPWM0_LINE519             =  8,       /* Digital Active - tcpwm[0].line[519]:0 */
    P1_7_TCPWM0_LINE_COMPL518       =  9,       /* Digital Active - tcpwm[0].line_compl[518]:0 */
    P1_7_TCPWM0_TR_ONE_CNT_IN517    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[517]:0 */

    /* P2.0 */
    P2_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_0_AMUXA                      =  4,       /* Analog mux bus A */
    P2_0_AMUXB                      =  5,       /* Analog mux bus B */
    P2_0_TCPWM0_LINE520             =  8,       /* Digital Active - tcpwm[0].line[520]:0 */
    P2_0_TCPWM0_LINE_COMPL519       =  9,       /* Digital Active - tcpwm[0].line_compl[519]:0 */
    P2_0_TCPWM0_TR_ONE_CNT_IN518    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[518]:0 */
    P2_0_SCB8_SPI_CLK               = 22,       /* Digital Active - scb[8].spi_clk:0 */
    P2_0_SCB8_UART_RX               = 23,       /* Digital Active - scb[8].uart_rx:0 */
    P2_0_SCB8_I2C_SDA               = 24,       /* Digital Active - scb[8].i2c_sda:0 */

    /* P2.1 */
    P2_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_1_AMUXA                      =  4,       /* Analog mux bus A */
    P2_1_AMUXB                      =  5,       /* Analog mux bus B */
    P2_1_TCPWM0_LINE521             =  8,       /* Digital Active - tcpwm[0].line[521]:0 */
    P2_1_TCPWM0_LINE_COMPL520       =  9,       /* Digital Active - tcpwm[0].line_compl[520]:0 */
    P2_1_TCPWM0_TR_ONE_CNT_IN519    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[519]:0 */
    P2_1_SCB8_SPI_MOSI              = 22,       /* Digital Active - scb[8].spi_mosi:0 */
    P2_1_SCB8_UART_TX               = 23,       /* Digital Active - scb[8].uart_tx:0 */
    P2_1_SCB8_I2C_SCL               = 24,       /* Digital Active - scb[8].i2c_scl:0 */

    /* P2.2 */
    P2_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_2_AMUXA                      =  4,       /* Analog mux bus A */
    P2_2_AMUXB                      =  5,       /* Analog mux bus B */
    P2_2_TCPWM0_LINE522             =  8,       /* Digital Active - tcpwm[0].line[522]:0 */
    P2_2_TCPWM0_LINE_COMPL521       =  9,       /* Digital Active - tcpwm[0].line_compl[521]:0 */
    P2_2_TCPWM0_TR_ONE_CNT_IN520    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[520]:0 */
    P2_2_LIN0_LIN_TX0               = 16,       /* Digital Active - lin[0].lin_tx[0]:0 */
    P2_2_CXPI0_CXPI_TX0             = 17,       /* Digital Active - cxpi[0].cxpi_tx[0]:0 */
    P2_2_CANFD0_TTCAN_TX0           = 18,       /* Digital Active - canfd[0].ttcan_tx[0]:0 */
    P2_2_SCB8_SPI_MISO              = 22,       /* Digital Active - scb[8].spi_miso:0 */
    P2_2_SCB8_UART_RTS              = 23,       /* Digital Active - scb[8].uart_rts:0 */
    P2_2_PERI_TR_IO_OUTPUT1         = 25,       /* Digital Active - peri.tr_io_output[1]:0 */

    /* P2.3 */
    P2_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_3_AMUXA                      =  4,       /* Analog mux bus A */
    P2_3_AMUXB                      =  5,       /* Analog mux bus B */
    P2_3_TCPWM0_LINE523             =  8,       /* Digital Active - tcpwm[0].line[523]:0 */
    P2_3_TCPWM0_LINE_COMPL522       =  9,       /* Digital Active - tcpwm[0].line_compl[522]:0 */
    P2_3_TCPWM0_TR_ONE_CNT_IN521    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[521]:0 */
    P2_3_LIN0_LIN_RX0               = 16,       /* Digital Active - lin[0].lin_rx[0]:0 */
    P2_3_CXPI0_CXPI_RX0             = 17,       /* Digital Active - cxpi[0].cxpi_rx[0]:0 */
    P2_3_CANFD0_TTCAN_RX0           = 18,       /* Digital Active - canfd[0].ttcan_rx[0]:0 */
    P2_3_SCB8_SPI_SELECT0           = 22,       /* Digital Active - scb[8].spi_select0:0 */
    P2_3_SCB8_UART_CTS              = 23,       /* Digital Active - scb[8].uart_cts:0 */
    P2_3_PERI_TR_IO_INPUT1          = 25,       /* Digital Active - peri.tr_io_input[1]:0 */

    /* P2.4 */
    P2_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_4_AMUXA                      =  4,       /* Analog mux bus A */
    P2_4_AMUXB                      =  5,       /* Analog mux bus B */
    P2_4_TCPWM0_LINE524             =  8,       /* Digital Active - tcpwm[0].line[524]:0 */
    P2_4_TCPWM0_LINE_COMPL523       =  9,       /* Digital Active - tcpwm[0].line_compl[523]:0 */
    P2_4_TCPWM0_TR_ONE_CNT_IN522    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[522]:0 */
    P2_4_LIN0_LIN_EN0               = 16,       /* Digital Active - lin[0].lin_en[0]:0 */
    P2_4_CXPI0_CXPI_EN0             = 17,       /* Digital Active - cxpi[0].cxpi_en[0]:0 */
    P2_4_CANFD0_TTCAN_TX1           = 18,       /* Digital Active - canfd[0].ttcan_tx[1]:0 */
    P2_4_SCB8_SPI_SELECT1           = 22,       /* Digital Active - scb[8].spi_select1:0 */
    P2_4_PERI_TR_IO_INPUT2          = 25,       /* Digital Active - peri.tr_io_input[2]:0 */

    /* P2.5 */
    P2_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_5_AMUXA                      =  4,       /* Analog mux bus A */
    P2_5_AMUXB                      =  5,       /* Analog mux bus B */
    P2_5_TCPWM0_LINE525             =  8,       /* Digital Active - tcpwm[0].line[525]:0 */
    P2_5_TCPWM0_LINE_COMPL524       =  9,       /* Digital Active - tcpwm[0].line_compl[524]:0 */
    P2_5_TCPWM0_TR_ONE_CNT_IN523    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[523]:0 */
    P2_5_CANFD0_TTCAN_RX1           = 18,       /* Digital Active - canfd[0].ttcan_rx[1]:0 */
    P2_5_PERI_TR_IO_OUTPUT0         = 25,       /* Digital Active - peri.tr_io_output[0]:0 */
    P2_5_CPUSS_CAL_SUP_NZ           = 27,       /* Digital Active - cpuss.cal_sup_nz:0 */
    P2_5_SRSS_CAL_WAVE              = 29,       /* Digital Deep Sleep - srss.cal_wave:0 */
    P2_5_SRSS_DDFT_PIN_IN1          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[1]:0 */

    /* P2.6 */
    P2_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_6_AMUXA                      =  4,       /* Analog mux bus A */
    P2_6_AMUXB                      =  5,       /* Analog mux bus B */
    P2_6_TCPWM0_LINE526             =  8,       /* Digital Active - tcpwm[0].line[526]:0 */
    P2_6_TCPWM0_LINE_COMPL525       =  9,       /* Digital Active - tcpwm[0].line_compl[525]:0 */
    P2_6_TCPWM0_TR_ONE_CNT_IN524    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[524]:0 */
    P2_6_LIN0_LIN_RX1               = 16,       /* Digital Active - lin[0].lin_rx[1]:0 */
    P2_6_CXPI0_CXPI_RX1             = 17,       /* Digital Active - cxpi[0].cxpi_rx[1]:0 */
    P2_6_PERI_TR_IO_INPUT0          = 25,       /* Digital Active - peri.tr_io_input[0]:0 */
    P2_6_CPUSS_SWJ_SWO_TDO          = 29,       /* Digital Deep Sleep - cpuss.swj_swo_tdo:0 */
    P2_6_SRSS_DDFT_PIN_IN0          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[0]:0 */

    /* P2.7 */
    P2_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_7_AMUXA                      =  4,       /* Analog mux bus A */
    P2_7_AMUXB                      =  5,       /* Analog mux bus B */
    P2_7_TCPWM0_LINE527             =  8,       /* Digital Active - tcpwm[0].line[527]:0 */
    P2_7_TCPWM0_LINE_COMPL526       =  9,       /* Digital Active - tcpwm[0].line_compl[526]:0 */
    P2_7_TCPWM0_TR_ONE_CNT_IN525    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[525]:0 */
    P2_7_PASS0_SAR_EXT_MUX_SEL0     = 11,       /* Digital Active - pass[0].sar_ext_mux_sel[0] */
    P2_7_LIN0_LIN_TX1               = 16,       /* Digital Active - lin[0].lin_tx[1]:0 */
    P2_7_CXPI0_CXPI_TX1             = 17,       /* Digital Active - cxpi[0].cxpi_tx[1]:0 */
    P2_7_PERI_TR_IO_INPUT3          = 25,       /* Digital Active - peri.tr_io_input[3]:0 */
    P2_7_CPUSS_SWJ_SWCLK_TCLK       = 29,       /* Digital Deep Sleep - cpuss.swj_swclk_tclk:0 */

    /* P3.0 */
    P3_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_0_AMUXA                      =  4,       /* Analog mux bus A */
    P3_0_AMUXB                      =  5,       /* Analog mux bus B */
    P3_0_TCPWM0_LINE24              =  8,       /* Digital Active - tcpwm[0].line[24]:1 */
    P3_0_TCPWM0_LINE_COMPL33        =  9,       /* Digital Active - tcpwm[0].line_compl[33]:1 */
    P3_0_TCPWM0_TR_ONE_CNT_IN32     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[32]:1 */
    P3_0_PASS0_SAR_EXT_MUX_SEL1     = 11,       /* Digital Active - pass[0].sar_ext_mux_sel[1] */
    P3_0_LIN0_LIN_EN1               = 16,       /* Digital Active - lin[0].lin_en[1]:0 */
    P3_0_CXPI0_CXPI_EN1             = 17,       /* Digital Active - cxpi[0].cxpi_en[1]:0 */
    P3_0_SCB8_SPI_CLK               = 22,       /* Digital Active - scb[8].spi_clk:1 */
    P3_0_SCB8_UART_RX               = 23,       /* Digital Active - scb[8].uart_rx:1 */
    P3_0_SCB8_I2C_SDA               = 24,       /* Digital Active - scb[8].i2c_sda:1 */
    P3_0_CPUSS_SWJ_SWDIO_TMS        = 29,       /* Digital Deep Sleep - cpuss.swj_swdio_tms:0 */

    /* P3.1 */
    P3_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_1_AMUXA                      =  4,       /* Analog mux bus A */
    P3_1_AMUXB                      =  5,       /* Analog mux bus B */
    P3_1_TCPWM0_LINE25              =  8,       /* Digital Active - tcpwm[0].line[25]:1 */
    P3_1_TCPWM0_LINE_COMPL24        =  9,       /* Digital Active - tcpwm[0].line_compl[24]:1 */
    P3_1_TCPWM0_TR_ONE_CNT_IN33     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[33]:1 */
    P3_1_PASS0_SAR_EXT_MUX_SEL2     = 11,       /* Digital Active - pass[0].sar_ext_mux_sel[2] */
    P3_1_SCB8_SPI_MOSI              = 22,       /* Digital Active - scb[8].spi_mosi:1 */
    P3_1_SCB8_UART_TX               = 23,       /* Digital Active - scb[8].uart_tx:1 */
    P3_1_SCB8_I2C_SCL               = 24,       /* Digital Active - scb[8].i2c_scl:1 */
    P3_1_CPUSS_SWJ_SWDOE_TDI        = 29,       /* Digital Deep Sleep - cpuss.swj_swdoe_tdi:0 */
    P3_1_SRSS_DDFT_PIN_IN0          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[0]:1 */

    /* P3.2 */
    P3_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_2_AMUXA                      =  4,       /* Analog mux bus A */
    P3_2_AMUXB                      =  5,       /* Analog mux bus B */
    P3_2_TCPWM0_LINE26              =  8,       /* Digital Active - tcpwm[0].line[26]:1 */
    P3_2_TCPWM0_LINE_COMPL25        =  9,       /* Digital Active - tcpwm[0].line_compl[25]:1 */
    P3_2_TCPWM0_TR_ONE_CNT_IN24     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[24]:1 */
    P3_2_PASS0_SAR_EXT_MUX_EN0      = 11,       /* Digital Active - pass[0].sar_ext_mux_en[0] */
    P3_2_SCB8_SPI_MISO              = 22,       /* Digital Active - scb[8].spi_miso:1 */
    P3_2_SCB8_UART_RTS              = 23,       /* Digital Active - scb[8].uart_rts:1 */
    P3_2_PERI_TR_IO_INPUT4          = 25,       /* Digital Active - peri.tr_io_input[4]:0 */
    P3_2_CPUSS_SWJ_TRSTN            = 29,       /* Digital Deep Sleep - cpuss.swj_trstn:0 */

    /* P3.3 */
    P3_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_3_AMUXA                      =  4,       /* Analog mux bus A */
    P3_3_AMUXB                      =  5,       /* Analog mux bus B */
    P3_3_TCPWM0_LINE27              =  8,       /* Digital Active - tcpwm[0].line[27]:1 */
    P3_3_TCPWM0_LINE_COMPL26        =  9,       /* Digital Active - tcpwm[0].line_compl[26]:1 */
    P3_3_TCPWM0_TR_ONE_CNT_IN25     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[25]:1 */
    P3_3_SCB8_SPI_SELECT0           = 22,       /* Digital Active - scb[8].spi_select0:1 */
    P3_3_SCB8_UART_CTS              = 23,       /* Digital Active - scb[8].uart_cts:1 */
    P3_3_PERI_TR_IO_INPUT5          = 25,       /* Digital Active - peri.tr_io_input[5]:0 */

    /* P3.4 */
    P3_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_4_AMUXA                      =  4,       /* Analog mux bus A */
    P3_4_AMUXB                      =  5,       /* Analog mux bus B */
    P3_4_TCPWM0_LINE28              =  8,       /* Digital Active - tcpwm[0].line[28]:1 */
    P3_4_TCPWM0_LINE_COMPL27        =  9,       /* Digital Active - tcpwm[0].line_compl[27]:1 */
    P3_4_TCPWM0_TR_ONE_CNT_IN26     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[26]:1 */

    /* P3.5 */
    P3_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_5_AMUXA                      =  4,       /* Analog mux bus A */
    P3_5_AMUXB                      =  5,       /* Analog mux bus B */
    P3_5_TCPWM0_LINE29              =  8,       /* Digital Active - tcpwm[0].line[29]:1 */
    P3_5_TCPWM0_LINE_COMPL28        =  9,       /* Digital Active - tcpwm[0].line_compl[28]:1 */
    P3_5_TCPWM0_TR_ONE_CNT_IN27     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[27]:1 */

    /* P4.0 */
    P4_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_0_AMUXA                      =  4,       /* Analog mux bus A */
    P4_0_AMUXB                      =  5,       /* Analog mux bus B */
    P4_0_TCPWM0_LINE30              =  8,       /* Digital Active - tcpwm[0].line[30]:1 */
    P4_0_TCPWM0_LINE_COMPL29        =  9,       /* Digital Active - tcpwm[0].line_compl[29]:1 */
    P4_0_TCPWM0_TR_ONE_CNT_IN28     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[28]:1 */
    P4_0_CANFD1_TTCAN_TX0           = 18,       /* Digital Active - canfd[1].ttcan_tx[0]:0 */

    /* P4.1 */
    P4_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_1_AMUXA                      =  4,       /* Analog mux bus A */
    P4_1_AMUXB                      =  5,       /* Analog mux bus B */
    P4_1_TCPWM0_LINE31              =  8,       /* Digital Active - tcpwm[0].line[31]:1 */
    P4_1_TCPWM0_LINE_COMPL30        =  9,       /* Digital Active - tcpwm[0].line_compl[30]:1 */
    P4_1_TCPWM0_TR_ONE_CNT_IN29     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[29]:1 */
    P4_1_CANFD1_TTCAN_RX0           = 18,       /* Digital Active - canfd[1].ttcan_rx[0]:0 */

    /* P4.2 */
    P4_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_2_AMUXA                      =  4,       /* Analog mux bus A */
    P4_2_AMUXB                      =  5,       /* Analog mux bus B */
    P4_2_TCPWM0_LINE32              =  8,       /* Digital Active - tcpwm[0].line[32]:1 */
    P4_2_TCPWM0_LINE_COMPL31        =  9,       /* Digital Active - tcpwm[0].line_compl[31]:1 */
    P4_2_TCPWM0_TR_ONE_CNT_IN30     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[30]:1 */
    P4_2_CANFD1_TTCAN_TX1           = 18,       /* Digital Active - canfd[1].ttcan_tx[1]:0 */

    /* P4.3 */
    P4_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_3_AMUXA                      =  4,       /* Analog mux bus A */
    P4_3_AMUXB                      =  5,       /* Analog mux bus B */
    P4_3_TCPWM0_LINE33              =  8,       /* Digital Active - tcpwm[0].line[33]:1 */
    P4_3_TCPWM0_LINE_COMPL32        =  9,       /* Digital Active - tcpwm[0].line_compl[32]:1 */
    P4_3_TCPWM0_TR_ONE_CNT_IN31     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[31]:1 */
    P4_3_CANFD1_TTCAN_RX1           = 18,       /* Digital Active - canfd[1].ttcan_rx[1]:0 */

    /* P4.4 */
    P4_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_4_AMUXA                      =  4,       /* Analog mux bus A */
    P4_4_AMUXB                      =  5,       /* Analog mux bus B */
    P4_4_TCPWM0_LINE0               =  8,       /* Digital Active - tcpwm[0].line[0]:2 */
    P4_4_TCPWM0_LINE_COMPL3         =  9,       /* Digital Active - tcpwm[0].line_compl[3]:2 */
    P4_4_LIN0_LIN_TX1               = 16,       /* Digital Active - lin[0].lin_tx[1]:1 */
    P4_4_CXPI0_CXPI_EN1             = 17,       /* Digital Active - cxpi[0].cxpi_en[1]:1 */
    P4_4_PERI_TR_IO_INPUT6          = 25,       /* Digital Active - peri.tr_io_input[6]:0 */

    /* P4.5 */
    P4_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_5_AMUXA                      =  4,       /* Analog mux bus A */
    P4_5_AMUXB                      =  5,       /* Analog mux bus B */
    P4_5_TCPWM0_LINE1               =  8,       /* Digital Active - tcpwm[0].line[1]:2 */
    P4_5_TCPWM0_LINE_COMPL0         =  9,       /* Digital Active - tcpwm[0].line_compl[0]:2 */
    P4_5_LIN0_LIN_RX1               = 16,       /* Digital Active - lin[0].lin_rx[1]:1 */
    P4_5_CXPI0_CXPI_RX1             = 17,       /* Digital Active - cxpi[0].cxpi_rx[1]:1 */
    P4_5_PERI_TR_IO_INPUT7          = 25,       /* Digital Active - peri.tr_io_input[7]:0 */

    /* P4.6 */
    P4_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_6_AMUXA                      =  4,       /* Analog mux bus A */
    P4_6_AMUXB                      =  5,       /* Analog mux bus B */
    P4_6_TCPWM0_LINE2               =  8,       /* Digital Active - tcpwm[0].line[2]:2 */
    P4_6_TCPWM0_LINE_COMPL1         =  9,       /* Digital Active - tcpwm[0].line_compl[1]:2 */
    P4_6_LIN0_LIN_EN1               = 16,       /* Digital Active - lin[0].lin_en[1]:1 */
    P4_6_CXPI0_CXPI_TX1             = 17,       /* Digital Active - cxpi[0].cxpi_tx[1]:1 */
    P4_6_PERI_TR_IO_INPUT8          = 25,       /* Digital Active - peri.tr_io_input[8]:0 */

    /* P4.7 */
    P4_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_7_AMUXA                      =  4,       /* Analog mux bus A */
    P4_7_AMUXB                      =  5,       /* Analog mux bus B */
    P4_7_TCPWM0_LINE3               =  8,       /* Digital Active - tcpwm[0].line[3]:2 */
    P4_7_TCPWM0_LINE_COMPL2         =  9,       /* Digital Active - tcpwm[0].line_compl[2]:2 */
    P4_7_PERI_TR_IO_INPUT9          = 25,       /* Digital Active - peri.tr_io_input[9]:0 */

    /* P5.0 */
    P5_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_0_AMUXA                      =  4,       /* Analog mux bus A */
    P5_0_AMUXB                      =  5,       /* Analog mux bus B */
    P5_0_TCPWM0_LINE256             =  8,       /* Digital Active - tcpwm[0].line[256]:0 */
    P5_0_TCPWM0_LINE_COMPL527       =  9,       /* Digital Active - tcpwm[0].line_compl[527]:1 */
    P5_0_PASS0_SAR_EXT_MUX_SEL3     = 11,       /* Digital Active - pass[0].sar_ext_mux_sel[3] */
    P5_0_SCB9_SPI_CLK               = 22,       /* Digital Active - scb[9].spi_clk:0 */
    P5_0_SCB9_UART_RX               = 23,       /* Digital Active - scb[9].uart_rx:0 */
    P5_0_SCB9_I2C_SDA               = 24,       /* Digital Active - scb[9].i2c_sda:0 */

    /* P5.1 */
    P5_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_1_AMUXA                      =  4,       /* Analog mux bus A */
    P5_1_AMUXB                      =  5,       /* Analog mux bus B */
    P5_1_TCPWM0_LINE522             =  8,       /* Digital Active - tcpwm[0].line[522]:1 */
    P5_1_TCPWM0_LINE_COMPL256       =  9,       /* Digital Active - tcpwm[0].line_compl[256]:0 */
    P5_1_TCPWM0_TR_ONE_CNT_IN527    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[527]:1 */
    P5_1_PASS0_SAR_EXT_MUX_SEL4     = 11,       /* Digital Active - pass[0].sar_ext_mux_sel[4] */
    P5_1_SCB9_SPI_MOSI              = 22,       /* Digital Active - scb[9].spi_mosi:0 */
    P5_1_SCB9_UART_TX               = 23,       /* Digital Active - scb[9].uart_tx:0 */
    P5_1_SCB9_I2C_SCL               = 24,       /* Digital Active - scb[9].i2c_scl:0 */

    /* P5.2 */
    P5_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_2_AMUXA                      =  4,       /* Analog mux bus A */
    P5_2_AMUXB                      =  5,       /* Analog mux bus B */
    P5_2_TCPWM0_LINE257             =  8,       /* Digital Active - tcpwm[0].line[257]:0 */
    P5_2_TCPWM0_LINE_COMPL522       =  9,       /* Digital Active - tcpwm[0].line_compl[522]:1 */
    P5_2_PASS0_SAR_EXT_MUX_SEL5     = 11,       /* Digital Active - pass[0].sar_ext_mux_sel[5] */
    P5_2_SCB9_SPI_MISO              = 22,       /* Digital Active - scb[9].spi_miso:0 */
    P5_2_SCB9_UART_RTS              = 23,       /* Digital Active - scb[9].uart_rts:0 */

    /* P5.3 */
    P5_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_3_AMUXA                      =  4,       /* Analog mux bus A */
    P5_3_AMUXB                      =  5,       /* Analog mux bus B */
    P5_3_TCPWM0_LINE523             =  8,       /* Digital Active - tcpwm[0].line[523]:1 */
    P5_3_TCPWM0_LINE_COMPL257       =  9,       /* Digital Active - tcpwm[0].line_compl[257]:0 */
    P5_3_TCPWM0_TR_ONE_CNT_IN522    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[522]:1 */
    P5_3_PASS0_SAR_EXT_MUX_EN1      = 11,       /* Digital Active - pass[0].sar_ext_mux_en[1] */
    P5_3_SCB9_SPI_SELECT0           = 22,       /* Digital Active - scb[9].spi_select0:0 */
    P5_3_SCB9_UART_CTS              = 23,       /* Digital Active - scb[9].uart_cts:0 */

    /* P5.4 */
    P5_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_4_AMUXA                      =  4,       /* Analog mux bus A */
    P5_4_AMUXB                      =  5,       /* Analog mux bus B */
    P5_4_TCPWM0_LINE258             =  8,       /* Digital Active - tcpwm[0].line[258]:0 */
    P5_4_TCPWM0_LINE_COMPL523       =  9,       /* Digital Active - tcpwm[0].line_compl[523]:1 */
    P5_4_SCB9_SPI_SELECT1           = 22,       /* Digital Active - scb[9].spi_select1:0 */
    P5_4_PERI_TR_IO_INPUT10         = 25,       /* Digital Active - peri.tr_io_input[10]:0 */

    /* P5.5 */
    P5_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_5_AMUXA                      =  4,       /* Analog mux bus A */
    P5_5_AMUXB                      =  5,       /* Analog mux bus B */
    P5_5_TCPWM0_LINE524             =  8,       /* Digital Active - tcpwm[0].line[524]:1 */
    P5_5_TCPWM0_LINE_COMPL258       =  9,       /* Digital Active - tcpwm[0].line_compl[258]:0 */
    P5_5_TCPWM0_TR_ONE_CNT_IN523    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[523]:1 */
    P5_5_PERI_TR_IO_INPUT11         = 25,       /* Digital Active - peri.tr_io_input[11]:0 */

    /* P5.6 */
    P5_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_6_AMUXA                      =  4,       /* Analog mux bus A */
    P5_6_AMUXB                      =  5,       /* Analog mux bus B */
    P5_6_TCPWM0_LINE259             =  8,       /* Digital Active - tcpwm[0].line[259]:0 */
    P5_6_TCPWM0_LINE_COMPL524       =  9,       /* Digital Active - tcpwm[0].line_compl[524]:1 */
    P5_6_PERI_TR_IO_INPUT12         = 25,       /* Digital Active - peri.tr_io_input[12]:0 */

    /* P5.7 */
    P5_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_7_AMUXA                      =  4,       /* Analog mux bus A */
    P5_7_AMUXB                      =  5,       /* Analog mux bus B */
    P5_7_TCPWM0_LINE525             =  8,       /* Digital Active - tcpwm[0].line[525]:1 */
    P5_7_TCPWM0_LINE_COMPL259       =  9,       /* Digital Active - tcpwm[0].line_compl[259]:0 */
    P5_7_TCPWM0_TR_ONE_CNT_IN524    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[524]:1 */
    P5_7_PERI_TR_IO_INPUT13         = 25,       /* Digital Active - peri.tr_io_input[13]:0 */

    /* P6.0 */
    P6_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_0_AMUXA                      =  4,       /* Analog mux bus A */
    P6_0_AMUXB                      =  5,       /* Analog mux bus B */
    P6_0_TCPWM0_LINE260             =  8,       /* Digital Active - tcpwm[0].line[260]:0 */
    P6_0_TCPWM0_LINE_COMPL525       =  9,       /* Digital Active - tcpwm[0].line_compl[525]:1 */

    /* P6.1 */
    P6_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_1_AMUXA                      =  4,       /* Analog mux bus A */
    P6_1_AMUXB                      =  5,       /* Analog mux bus B */
    P6_1_TCPWM0_LINE526             =  8,       /* Digital Active - tcpwm[0].line[526]:1 */
    P6_1_TCPWM0_LINE_COMPL260       =  9,       /* Digital Active - tcpwm[0].line_compl[260]:0 */
    P6_1_TCPWM0_TR_ONE_CNT_IN525    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[525]:1 */
    P6_1_SG0_SG_TONE0               = 21,       /* Digital Active - sg[0].sg_tone[0]:2 */

    /* P6.2 */
    P6_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_2_AMUXA                      =  4,       /* Analog mux bus A */
    P6_2_AMUXB                      =  5,       /* Analog mux bus B */
    P6_2_TCPWM0_LINE261             =  8,       /* Digital Active - tcpwm[0].line[261]:0 */
    P6_2_TCPWM0_LINE_COMPL526       =  9,       /* Digital Active - tcpwm[0].line_compl[526]:1 */
    P6_2_SG0_SG_AMPL0               = 21,       /* Digital Active - sg[0].sg_ampl[0]:2 */

    /* P6.3 */
    P6_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_3_AMUXA                      =  4,       /* Analog mux bus A */
    P6_3_AMUXB                      =  5,       /* Analog mux bus B */
    P6_3_TCPWM0_LINE527             =  8,       /* Digital Active - tcpwm[0].line[527]:1 */
    P6_3_TCPWM0_LINE_COMPL261       =  9,       /* Digital Active - tcpwm[0].line_compl[261]:0 */
    P6_3_TCPWM0_TR_ONE_CNT_IN526    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[526]:1 */
    P6_3_SG0_SG_TONE1               = 21,       /* Digital Active - sg[0].sg_tone[1]:2 */

    /* P6.4 */
    P6_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_4_AMUXA                      =  4,       /* Analog mux bus A */
    P6_4_AMUXB                      =  5,       /* Analog mux bus B */
    P6_4_TCPWM0_LINE262             =  8,       /* Digital Active - tcpwm[0].line[262]:0 */
    P6_4_TCPWM0_LINE_COMPL5         =  9,       /* Digital Active - tcpwm[0].line_compl[5]:1 */
    P6_4_SG0_SG_AMPL1               = 21,       /* Digital Active - sg[0].sg_ampl[1]:2 */
    P6_4_PERI_TR_IO_INPUT14         = 25,       /* Digital Active - peri.tr_io_input[14]:0 */

    /* P6.5 */
    P6_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_5_AMUXA                      =  4,       /* Analog mux bus A */
    P6_5_AMUXB                      =  5,       /* Analog mux bus B */
    P6_5_TCPWM0_LINE0               =  8,       /* Digital Active - tcpwm[0].line[0]:1 */
    P6_5_TCPWM0_LINE_COMPL262       =  9,       /* Digital Active - tcpwm[0].line_compl[262]:0 */
    P6_5_SG0_SG_TONE2               = 21,       /* Digital Active - sg[0].sg_tone[2]:2 */
    P6_5_PERI_TR_IO_INPUT15         = 25,       /* Digital Active - peri.tr_io_input[15]:0 */

    /* P6.6 */
    P6_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_6_AMUXA                      =  4,       /* Analog mux bus A */
    P6_6_AMUXB                      =  5,       /* Analog mux bus B */
    P6_6_TCPWM0_LINE263             =  8,       /* Digital Active - tcpwm[0].line[263]:0 */
    P6_6_TCPWM0_LINE_COMPL0         =  9,       /* Digital Active - tcpwm[0].line_compl[0]:1 */
    P6_6_SG0_SG_AMPL2               = 21,       /* Digital Active - sg[0].sg_ampl[2]:2 */
    P6_6_PERI_TR_IO_INPUT16         = 25,       /* Digital Active - peri.tr_io_input[16]:0 */

    /* P6.7 */
    P6_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_7_AMUXA                      =  4,       /* Analog mux bus A */
    P6_7_AMUXB                      =  5,       /* Analog mux bus B */
    P6_7_TCPWM0_LINE1               =  8,       /* Digital Active - tcpwm[0].line[1]:1 */
    P6_7_TCPWM0_LINE_COMPL263       =  9,       /* Digital Active - tcpwm[0].line_compl[263]:0 */
    P6_7_SG0_SG_TONE3               = 21,       /* Digital Active - sg[0].sg_tone[3]:2 */
    P6_7_PERI_TR_IO_INPUT17         = 25,       /* Digital Active - peri.tr_io_input[17]:0 */

    /* P7.0 */
    P7_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_0_AMUXA                      =  4,       /* Analog mux bus A */
    P7_0_AMUXB                      =  5,       /* Analog mux bus B */
    P7_0_TCPWM0_LINE264             =  8,       /* Digital Active - tcpwm[0].line[264]:0 */
    P7_0_TCPWM0_LINE_COMPL1         =  9,       /* Digital Active - tcpwm[0].line_compl[1]:1 */
    P7_0_SG0_SG_AMPL3               = 21,       /* Digital Active - sg[0].sg_ampl[3]:2 */

    /* P7.1 */
    P7_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_1_AMUXA                      =  4,       /* Analog mux bus A */
    P7_1_AMUXB                      =  5,       /* Analog mux bus B */
    P7_1_TCPWM0_LINE2               =  8,       /* Digital Active - tcpwm[0].line[2]:1 */
    P7_1_TCPWM0_LINE_COMPL264       =  9,       /* Digital Active - tcpwm[0].line_compl[264]:0 */
    P7_1_SG0_SG_AMPL4               = 21,       /* Digital Active - sg[0].sg_ampl[4]:2 */

    /* P7.2 */
    P7_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_2_AMUXA                      =  4,       /* Analog mux bus A */
    P7_2_AMUXB                      =  5,       /* Analog mux bus B */
    P7_2_TCPWM0_LINE265             =  8,       /* Digital Active - tcpwm[0].line[265]:0 */
    P7_2_TCPWM0_LINE_COMPL2         =  9,       /* Digital Active - tcpwm[0].line_compl[2]:1 */
    P7_2_SG0_SG_TONE4               = 21,       /* Digital Active - sg[0].sg_tone[4]:2 */

    /* P7.3 */
    P7_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_3_AMUXA                      =  4,       /* Analog mux bus A */
    P7_3_AMUXB                      =  5,       /* Analog mux bus B */
    P7_3_TCPWM0_LINE3               =  8,       /* Digital Active - tcpwm[0].line[3]:1 */
    P7_3_TCPWM0_LINE_COMPL265       =  9,       /* Digital Active - tcpwm[0].line_compl[265]:0 */
    P7_3_SG0_SG_MCK0                = 21,       /* Digital Active - sg[0].sg_mck[0]:2 */

    /* P7.4 */
    P7_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_4_AMUXA                      =  4,       /* Analog mux bus A */
    P7_4_AMUXB                      =  5,       /* Analog mux bus B */
    P7_4_TCPWM0_LINE266             =  8,       /* Digital Active - tcpwm[0].line[266]:0 */
    P7_4_TCPWM0_LINE_COMPL3         =  9,       /* Digital Active - tcpwm[0].line_compl[3]:1 */
    P7_4_SG0_SG_MCK1                = 21,       /* Digital Active - sg[0].sg_mck[1]:2 */

    /* P7.5 */
    P7_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_5_AMUXA                      =  4,       /* Analog mux bus A */
    P7_5_AMUXB                      =  5,       /* Analog mux bus B */
    P7_5_TCPWM0_LINE4               =  8,       /* Digital Active - tcpwm[0].line[4]:1 */
    P7_5_TCPWM0_LINE_COMPL266       =  9,       /* Digital Active - tcpwm[0].line_compl[266]:0 */
    P7_5_SG0_SG_MCK2                = 21,       /* Digital Active - sg[0].sg_mck[2]:2 */

    /* P7.6 */
    P7_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_6_AMUXA                      =  4,       /* Analog mux bus A */
    P7_6_AMUXB                      =  5,       /* Analog mux bus B */
    P7_6_TCPWM0_LINE267             =  8,       /* Digital Active - tcpwm[0].line[267]:0 */
    P7_6_TCPWM0_LINE_COMPL4         =  9,       /* Digital Active - tcpwm[0].line_compl[4]:1 */
    P7_6_SG0_SG_MCK3                = 21,       /* Digital Active - sg[0].sg_mck[3]:2 */

    /* P7.7 */
    P7_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_7_AMUXA                      =  4,       /* Analog mux bus A */
    P7_7_AMUXB                      =  5,       /* Analog mux bus B */
    P7_7_TCPWM0_LINE5               =  8,       /* Digital Active - tcpwm[0].line[5]:1 */
    P7_7_TCPWM0_LINE_COMPL267       =  9,       /* Digital Active - tcpwm[0].line_compl[267]:0 */
    P7_7_SG0_SG_MCK4                = 21,       /* Digital Active - sg[0].sg_mck[4]:2 */

    /* P8.0 */
    P8_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_0_AMUXA                      =  4,       /* Analog mux bus A */
    P8_0_AMUXB                      =  5,       /* Analog mux bus B */
    P8_0_SCB10_SPI_CLK              = 22,       /* Digital Active - scb[10].spi_clk:0 */
    P8_0_SCB10_UART_RX              = 23,       /* Digital Active - scb[10].uart_rx:0 */
    P8_0_SCB10_I2C_SDA              = 24,       /* Digital Active - scb[10].i2c_sda:0 */
    P8_0_SRSS_IO_CLK_HF2            = 26,       /* Digital Active - srss.io_clk_hf[2]:0 */
    P8_0_SMIF0_SPIHB_SELECT1        = 27,       /* Digital Active - smif[0].spihb_select1 */

    /* P8.1 */
    P8_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_1_AMUXA                      =  4,       /* Analog mux bus A */
    P8_1_AMUXB                      =  5,       /* Analog mux bus B */
    P8_1_SCB10_SPI_MOSI             = 22,       /* Digital Active - scb[10].spi_mosi:0 */
    P8_1_SCB10_UART_TX              = 23,       /* Digital Active - scb[10].uart_tx:0 */
    P8_1_SCB10_I2C_SCL              = 24,       /* Digital Active - scb[10].i2c_scl:0 */
    P8_1_SMIF0_SPIHB_SELECT0        = 27,       /* Digital Active - smif[0].spihb_select0 */

    /* P8.2 */
    P8_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_2_AMUXA                      =  4,       /* Analog mux bus A */
    P8_2_AMUXB                      =  5,       /* Analog mux bus B */
    P8_2_SCB10_SPI_MISO             = 22,       /* Digital Active - scb[10].spi_miso:0 */
    P8_2_SCB10_UART_RTS             = 23,       /* Digital Active - scb[10].uart_rts:0 */
    P8_2_SMIF0_SPIHB_DATA7          = 27,       /* Digital Active - smif[0].spihb_data7 */

    /* P8.3 */
    P8_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_3_AMUXA                      =  4,       /* Analog mux bus A */
    P8_3_AMUXB                      =  5,       /* Analog mux bus B */
    P8_3_SCB10_SPI_SELECT0          = 22,       /* Digital Active - scb[10].spi_select0:0 */
    P8_3_SCB10_UART_CTS             = 23,       /* Digital Active - scb[10].uart_cts:0 */
    P8_3_SMIF0_SPIHB_DATA6          = 27,       /* Digital Active - smif[0].spihb_data6 */

    /* P8.4 */
    P8_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_4_AMUXA                      =  4,       /* Analog mux bus A */
    P8_4_AMUXB                      =  5,       /* Analog mux bus B */
    P8_4_SCB10_SPI_SELECT1          = 22,       /* Digital Active - scb[10].spi_select1:0 */
    P8_4_SMIF0_SPIHB_DATA5          = 27,       /* Digital Active - smif[0].spihb_data5 */

    /* P8.5 */
    P8_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_5_AMUXA                      =  4,       /* Analog mux bus A */
    P8_5_AMUXB                      =  5,       /* Analog mux bus B */
    P8_5_SRSS_EXT_CLK               = 26,       /* Digital Active - srss.ext_clk:1 */
    P8_5_SMIF0_SPIHB_DATA4          = 27,       /* Digital Active - smif[0].spihb_data4 */

    /* P8.6 */
    P8_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_6_AMUXA                      =  4,       /* Analog mux bus A */
    P8_6_AMUXB                      =  5,       /* Analog mux bus B */
    P8_6_SCB11_SPI_CLK              = 22,       /* Digital Active - scb[11].spi_clk:0 */
    P8_6_SCB11_UART_RX              = 23,       /* Digital Active - scb[11].uart_rx:0 */
    P8_6_SCB11_I2C_SDA              = 24,       /* Digital Active - scb[11].i2c_sda:0 */
    P8_6_SRSS_DDFT_CLK_DIRECT       = 26,       /* Digital Active - srss.ddft_clk_direct */
    P8_6_SMIF0_SPIHB_DATA3          = 27,       /* Digital Active - smif[0].spihb_data3 */

    /* P8.7 */
    P8_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_7_AMUXA                      =  4,       /* Analog mux bus A */
    P8_7_AMUXB                      =  5,       /* Analog mux bus B */
    P8_7_SCB11_SPI_MOSI             = 22,       /* Digital Active - scb[11].spi_mosi:0 */
    P8_7_SCB11_UART_TX              = 23,       /* Digital Active - scb[11].uart_tx:0 */
    P8_7_SCB11_I2C_SCL              = 24,       /* Digital Active - scb[11].i2c_scl:0 */
    P8_7_CPUSS_TRACE_DATA3          = 26,       /* Digital Active - cpuss.trace_data[3]:0 */
    P8_7_SMIF0_SPIHB_DATA2          = 27,       /* Digital Active - smif[0].spihb_data2 */

    /* P9.0 */
    P9_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_0_AMUXA                      =  4,       /* Analog mux bus A */
    P9_0_AMUXB                      =  5,       /* Analog mux bus B */
    P9_0_SCB11_SPI_MISO             = 22,       /* Digital Active - scb[11].spi_miso:0 */
    P9_0_SCB11_UART_RTS             = 23,       /* Digital Active - scb[11].uart_rts:0 */
    P9_0_CPUSS_TRACE_DATA2          = 26,       /* Digital Active - cpuss.trace_data[2]:0 */
    P9_0_SMIF0_SPIHB_DATA1          = 27,       /* Digital Active - smif[0].spihb_data1 */

    /* P9.1 */
    P9_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_1_AMUXA                      =  4,       /* Analog mux bus A */
    P9_1_AMUXB                      =  5,       /* Analog mux bus B */
    P9_1_SCB11_SPI_SELECT0          = 22,       /* Digital Active - scb[11].spi_select0:0 */
    P9_1_SCB11_UART_CTS             = 23,       /* Digital Active - scb[11].uart_cts:0 */
    P9_1_CPUSS_TRACE_DATA1          = 26,       /* Digital Active - cpuss.trace_data[1]:0 */
    P9_1_SMIF0_SPIHB_DATA0          = 27,       /* Digital Active - smif[0].spihb_data0 */

    /* P9.2 */
    P9_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_2_AMUXA                      =  4,       /* Analog mux bus A */
    P9_2_AMUXB                      =  5,       /* Analog mux bus B */
    P9_2_SCB11_SPI_SELECT1          = 22,       /* Digital Active - scb[11].spi_select1:0 */
    P9_2_CPUSS_TRACE_DATA0          = 26,       /* Digital Active - cpuss.trace_data[0]:0 */
    P9_2_SMIF0_SPIHB_CLK            = 27,       /* Digital Active - smif[0].spihb_clk */

    /* P9.3 */
    P9_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_3_AMUXA                      =  4,       /* Analog mux bus A */
    P9_3_AMUXB                      =  5,       /* Analog mux bus B */
    P9_3_CPUSS_TRACE_CLOCK          = 26,       /* Digital Active - cpuss.trace_clock:0 */
    P9_3_SMIF0_SPIHB_RWDS           = 27,       /* Digital Active - smif[0].spihb_rwds */

    /* P10.0 */
    P10_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_0_AMUXA                     =  4,       /* Analog mux bus A */
    P10_0_AMUXB                     =  5,       /* Analog mux bus B */
    P10_0_TCPWM0_LINE4              =  8,       /* Digital Active - tcpwm[0].line[4]:2 */
    P10_0_TCPWM0_LINE_COMPL3        =  9,       /* Digital Active - tcpwm[0].line_compl[3]:0 */
    P10_0_LCD_SEG0                  = 12,       /* Digital Deep Sleep - lcd.seg[0]:1 */
    P10_0_LCD_COM0                  = 13,       /* Digital Deep Sleep - lcd.com[0]:1 */
    P10_0_SG0_SG_TONE0              = 21,       /* Digital Active - sg[0].sg_tone[0]:1 */
    P10_0_SCB2_SPI_CLK              = 22,       /* Digital Active - scb[2].spi_clk:1 */
    P10_0_SCB2_UART_RX              = 23,       /* Digital Active - scb[2].uart_rx:1 */
    P10_0_SCB2_I2C_SDA              = 24,       /* Digital Active - scb[2].i2c_sda:1 */

    /* P10.1 */
    P10_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_1_AMUXA                     =  4,       /* Analog mux bus A */
    P10_1_AMUXB                     =  5,       /* Analog mux bus B */
    P10_1_TCPWM0_LINE5              =  8,       /* Digital Active - tcpwm[0].line[5]:2 */
    P10_1_TCPWM0_LINE_COMPL4        =  9,       /* Digital Active - tcpwm[0].line_compl[4]:2 */
    P10_1_LCD_SEG1                  = 12,       /* Digital Deep Sleep - lcd.seg[1]:1 */
    P10_1_LCD_COM1                  = 13,       /* Digital Deep Sleep - lcd.com[1]:1 */
    P10_1_SG0_SG_AMPL0              = 21,       /* Digital Active - sg[0].sg_ampl[0]:1 */
    P10_1_SCB2_SPI_MOSI             = 22,       /* Digital Active - scb[2].spi_mosi:1 */
    P10_1_SCB2_UART_TX              = 23,       /* Digital Active - scb[2].uart_tx:1 */
    P10_1_SCB2_I2C_SCL              = 24,       /* Digital Active - scb[2].i2c_scl:1 */

    /* P10.2 */
    P10_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_2_AMUXA                     =  4,       /* Analog mux bus A */
    P10_2_AMUXB                     =  5,       /* Analog mux bus B */
    P10_2_TCPWM0_LINE6              =  8,       /* Digital Active - tcpwm[0].line[6]:2 */
    P10_2_TCPWM0_LINE_COMPL5        =  9,       /* Digital Active - tcpwm[0].line_compl[5]:2 */
    P10_2_LCD_SEG2                  = 12,       /* Digital Deep Sleep - lcd.seg[2]:1 */
    P10_2_LCD_COM2                  = 13,       /* Digital Deep Sleep - lcd.com[2]:1 */
    P10_2_SG0_SG_MCK0               = 21,       /* Digital Active - sg[0].sg_mck[0]:1 */
    P10_2_SCB2_SPI_MISO             = 22,       /* Digital Active - scb[2].spi_miso:1 */
    P10_2_SCB2_UART_RTS             = 23,       /* Digital Active - scb[2].uart_rts:1 */

    /* P10.3 */
    P10_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_3_AMUXA                     =  4,       /* Analog mux bus A */
    P10_3_AMUXB                     =  5,       /* Analog mux bus B */
    P10_3_TCPWM0_LINE7              =  8,       /* Digital Active - tcpwm[0].line[7]:2 */
    P10_3_TCPWM0_LINE_COMPL6        =  9,       /* Digital Active - tcpwm[0].line_compl[6]:2 */
    P10_3_LCD_SEG3                  = 12,       /* Digital Deep Sleep - lcd.seg[3]:1 */
    P10_3_LCD_COM3                  = 13,       /* Digital Deep Sleep - lcd.com[3]:1 */
    P10_3_SG0_SG_TONE1              = 21,       /* Digital Active - sg[0].sg_tone[1]:1 */
    P10_3_SCB2_SPI_SELECT0          = 22,       /* Digital Active - scb[2].spi_select0:1 */
    P10_3_SCB2_UART_CTS             = 23,       /* Digital Active - scb[2].uart_cts:1 */

    /* P10.4 */
    P10_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_4_AMUXA                     =  4,       /* Analog mux bus A */
    P10_4_AMUXB                     =  5,       /* Analog mux bus B */
    P10_4_TCPWM0_LINE8              =  8,       /* Digital Active - tcpwm[0].line[8]:2 */
    P10_4_TCPWM0_LINE_COMPL7        =  9,       /* Digital Active - tcpwm[0].line_compl[7]:2 */
    P10_4_LCD_SEG4                  = 12,       /* Digital Deep Sleep - lcd.seg[4]:1 */
    P10_4_LCD_COM4                  = 13,       /* Digital Deep Sleep - lcd.com[4]:1 */
    P10_4_SG0_SG_AMPL1              = 21,       /* Digital Active - sg[0].sg_ampl[1]:1 */

    /* P11.0 */
    P11_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_0_AMUXA                     =  4,       /* Analog mux bus A */
    P11_0_AMUXB                     =  5,       /* Analog mux bus B */
    P11_0_TCPWM0_LINE9              =  8,       /* Digital Active - tcpwm[0].line[9]:2 */
    P11_0_TCPWM0_LINE_COMPL8        =  9,       /* Digital Active - tcpwm[0].line_compl[8]:2 */
    P11_0_LCD_SEG5                  = 12,       /* Digital Deep Sleep - lcd.seg[5]:1 */
    P11_0_LCD_COM5                  = 13,       /* Digital Deep Sleep - lcd.com[5]:1 */
    P11_0_SG0_SG_MCK1               = 21,       /* Digital Active - sg[0].sg_mck[1]:1 */
    P11_0_SCB1_SPI_CLK              = 22,       /* Digital Active - scb[1].spi_clk:0 */
    P11_0_SCB1_UART_RX              = 23,       /* Digital Active - scb[1].uart_rx:0 */
    P11_0_SCB1_I2C_SDA              = 24,       /* Digital Active - scb[1].i2c_sda:0 */

    /* P11.1 */
    P11_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_1_AMUXA                     =  4,       /* Analog mux bus A */
    P11_1_AMUXB                     =  5,       /* Analog mux bus B */
    P11_1_TCPWM0_LINE10             =  8,       /* Digital Active - tcpwm[0].line[10]:2 */
    P11_1_TCPWM0_LINE_COMPL9        =  9,       /* Digital Active - tcpwm[0].line_compl[9]:2 */
    P11_1_LCD_SEG6                  = 12,       /* Digital Deep Sleep - lcd.seg[6]:1 */
    P11_1_LCD_COM6                  = 13,       /* Digital Deep Sleep - lcd.com[6]:1 */
    P11_1_SCB1_SPI_MOSI             = 22,       /* Digital Active - scb[1].spi_mosi:0 */
    P11_1_SCB1_UART_TX              = 23,       /* Digital Active - scb[1].uart_tx:0 */
    P11_1_SCB1_I2C_SCL              = 24,       /* Digital Active - scb[1].i2c_scl:0 */

    /* P11.2 */
    P11_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_2_AMUXA                     =  4,       /* Analog mux bus A */
    P11_2_AMUXB                     =  5,       /* Analog mux bus B */
    P11_2_TCPWM0_LINE512            =  8,       /* Digital Active - tcpwm[0].line[512]:1 */
    P11_2_TCPWM0_LINE_COMPL10       =  9,       /* Digital Active - tcpwm[0].line_compl[10]:2 */
    P11_2_LCD_SEG7                  = 12,       /* Digital Deep Sleep - lcd.seg[7]:1 */
    P11_2_LCD_COM7                  = 13,       /* Digital Deep Sleep - lcd.com[7]:1 */
    P11_2_TDM0_TDM_TX_MCK0          = 16,       /* Digital Active - tdm[0].tdm_tx_mck[0]:0 */
    P11_2_TDM0_TDM_RX_MCK1          = 17,       /* Digital Active - tdm[0].tdm_rx_mck[1]:0 */
    P11_2_SCB1_SPI_MISO             = 22,       /* Digital Active - scb[1].spi_miso:0 */
    P11_2_SCB1_UART_RTS             = 23,       /* Digital Active - scb[1].uart_rts:0 */

    /* P11.3 */
    P11_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_3_AMUXA                     =  4,       /* Analog mux bus A */
    P11_3_AMUXB                     =  5,       /* Analog mux bus B */
    P11_3_TCPWM0_LINE513            =  8,       /* Digital Active - tcpwm[0].line[513]:1 */
    P11_3_TCPWM0_LINE_COMPL512      =  9,       /* Digital Active - tcpwm[0].line_compl[512]:1 */
    P11_3_LCD_SEG8                  = 12,       /* Digital Deep Sleep - lcd.seg[8]:1 */
    P11_3_LCD_COM8                  = 13,       /* Digital Deep Sleep - lcd.com[8]:1 */
    P11_3_TDM0_TDM_TX_SCK0          = 16,       /* Digital Active - tdm[0].tdm_tx_sck[0]:0 */
    P11_3_TDM0_TDM_RX_SCK1          = 17,       /* Digital Active - tdm[0].tdm_rx_sck[1]:0 */
    P11_3_SCB1_SPI_SELECT0          = 22,       /* Digital Active - scb[1].spi_select0:0 */
    P11_3_SCB1_UART_CTS             = 23,       /* Digital Active - scb[1].uart_cts:0 */

    /* P11.4 */
    P11_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_4_AMUXA                     =  4,       /* Analog mux bus A */
    P11_4_AMUXB                     =  5,       /* Analog mux bus B */
    P11_4_TCPWM0_LINE514            =  8,       /* Digital Active - tcpwm[0].line[514]:1 */
    P11_4_TCPWM0_LINE_COMPL513      =  9,       /* Digital Active - tcpwm[0].line_compl[513]:1 */
    P11_4_TCPWM0_TR_ONE_CNT_IN512   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[512]:1 */
    P11_4_LCD_SEG9                  = 12,       /* Digital Deep Sleep - lcd.seg[9]:1 */
    P11_4_LCD_COM9                  = 13,       /* Digital Deep Sleep - lcd.com[9]:1 */
    P11_4_TDM0_TDM_TX_FSYNC0        = 16,       /* Digital Active - tdm[0].tdm_tx_fsync[0]:0 */
    P11_4_TDM0_TDM_RX_FSYNC1        = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[1]:0 */
    P11_4_SCB1_SPI_SELECT1          = 22,       /* Digital Active - scb[1].spi_select1:0 */

    /* P11.5 */
    P11_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_5_AMUXA                     =  4,       /* Analog mux bus A */
    P11_5_AMUXB                     =  5,       /* Analog mux bus B */
    P11_5_TCPWM0_LINE11             =  8,       /* Digital Active - tcpwm[0].line[11]:2 */
    P11_5_TCPWM0_LINE_COMPL514      =  9,       /* Digital Active - tcpwm[0].line_compl[514]:1 */
    P11_5_TCPWM0_TR_ONE_CNT_IN513   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[513]:1 */
    P11_5_LCD_SEG12                 = 12,       /* Digital Deep Sleep - lcd.seg[12]:1 */
    P11_5_LCD_COM12                 = 13,       /* Digital Deep Sleep - lcd.com[12]:1 */
    P11_5_TDM0_TDM_TX_SD0           = 16,       /* Digital Active - tdm[0].tdm_tx_sd[0]:0 */
    P11_5_TDM0_TDM_RX_SD1           = 17,       /* Digital Active - tdm[0].tdm_rx_sd[1]:0 */
    P11_5_SG0_SG_TONE2              = 21,       /* Digital Active - sg[0].sg_tone[2]:1 */

    /* P11.6 */
    P11_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_6_AMUXA                     =  4,       /* Analog mux bus A */
    P11_6_AMUXB                     =  5,       /* Analog mux bus B */
    P11_6_TCPWM0_LINE6              =  8,       /* Digital Active - tcpwm[0].line[6]:1 */
    P11_6_TCPWM0_LINE_COMPL11       =  9,       /* Digital Active - tcpwm[0].line_compl[11]:2 */
    P11_6_LCD_SEG13                 = 12,       /* Digital Deep Sleep - lcd.seg[13]:1 */
    P11_6_LCD_COM13                 = 13,       /* Digital Deep Sleep - lcd.com[13]:1 */
    P11_6_SG0_SG_AMPL2              = 21,       /* Digital Active - sg[0].sg_ampl[2]:1 */

    /* P11.7 */
    P11_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_7_AMUXA                     =  4,       /* Analog mux bus A */
    P11_7_AMUXB                     =  5,       /* Analog mux bus B */
    P11_7_TCPWM0_LINE7              =  8,       /* Digital Active - tcpwm[0].line[7]:1 */
    P11_7_TCPWM0_LINE_COMPL6        =  9,       /* Digital Active - tcpwm[0].line_compl[6]:1 */
    P11_7_LCD_SEG14                 = 12,       /* Digital Deep Sleep - lcd.seg[14]:1 */
    P11_7_LCD_COM14                 = 13,       /* Digital Deep Sleep - lcd.com[14]:1 */
    P11_7_SG0_SG_MCK2               = 21,       /* Digital Active - sg[0].sg_mck[2]:1 */
    P11_7_PERI_TR_IO_INPUT18        = 25,       /* Digital Active - peri.tr_io_input[18]:0 */

    /* P12.0 */
    P12_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_0_AMUXA                     =  4,       /* Analog mux bus A */
    P12_0_AMUXB                     =  5,       /* Analog mux bus B */
    P12_0_TCPWM0_LINE8              =  8,       /* Digital Active - tcpwm[0].line[8]:1 */
    P12_0_TCPWM0_LINE_COMPL7        =  9,       /* Digital Active - tcpwm[0].line_compl[7]:1 */
    P12_0_TCPWM0_TR_ONE_CNT_IN514   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[514]:1 */
    P12_0_LCD_SEG10                 = 12,       /* Digital Deep Sleep - lcd.seg[10]:1 */
    P12_0_LCD_COM10                 = 13,       /* Digital Deep Sleep - lcd.com[10]:1 */
    P12_0_SG0_SG_TONE0              = 21,       /* Digital Active - sg[0].sg_tone[0]:0 */
    P12_0_SCB2_SPI_CLK              = 22,       /* Digital Active - scb[2].spi_clk:0 */
    P12_0_SCB2_UART_RX              = 23,       /* Digital Active - scb[2].uart_rx:0 */
    P12_0_SCB2_I2C_SDA              = 24,       /* Digital Active - scb[2].i2c_sda:0 */

    /* P12.1 */
    P12_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_1_AMUXA                     =  4,       /* Analog mux bus A */
    P12_1_AMUXB                     =  5,       /* Analog mux bus B */
    P12_1_TCPWM0_LINE9              =  8,       /* Digital Active - tcpwm[0].line[9]:1 */
    P12_1_TCPWM0_LINE_COMPL8        =  9,       /* Digital Active - tcpwm[0].line_compl[8]:1 */
    P12_1_LCD_SEG11                 = 12,       /* Digital Deep Sleep - lcd.seg[11]:1 */
    P12_1_LCD_COM11                 = 13,       /* Digital Deep Sleep - lcd.com[11]:1 */
    P12_1_SG0_SG_AMPL0              = 21,       /* Digital Active - sg[0].sg_ampl[0]:0 */
    P12_1_SCB2_SPI_MOSI             = 22,       /* Digital Active - scb[2].spi_mosi:0 */
    P12_1_SCB2_UART_TX              = 23,       /* Digital Active - scb[2].uart_tx:0 */
    P12_1_SCB2_I2C_SCL              = 24,       /* Digital Active - scb[2].i2c_scl:0 */

    /* P12.2 */
    P12_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_2_AMUXA                     =  4,       /* Analog mux bus A */
    P12_2_AMUXB                     =  5,       /* Analog mux bus B */
    P12_2_TCPWM0_LINE10             =  8,       /* Digital Active - tcpwm[0].line[10]:1 */
    P12_2_TCPWM0_LINE_COMPL9        =  9,       /* Digital Active - tcpwm[0].line_compl[9]:1 */
    P12_2_LCD_SEG15                 = 12,       /* Digital Deep Sleep - lcd.seg[15]:1 */
    P12_2_LCD_COM15                 = 13,       /* Digital Deep Sleep - lcd.com[15]:1 */
    P12_2_SG0_SG_MCK0               = 21,       /* Digital Active - sg[0].sg_mck[0]:0 */
    P12_2_SCB2_SPI_MISO             = 22,       /* Digital Active - scb[2].spi_miso:0 */
    P12_2_SCB2_UART_RTS             = 23,       /* Digital Active - scb[2].uart_rts:0 */

    /* P12.3 */
    P12_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_3_AMUXA                     =  4,       /* Analog mux bus A */
    P12_3_AMUXB                     =  5,       /* Analog mux bus B */
    P12_3_TCPWM0_LINE11             =  8,       /* Digital Active - tcpwm[0].line[11]:1 */
    P12_3_TCPWM0_LINE_COMPL10       =  9,       /* Digital Active - tcpwm[0].line_compl[10]:1 */
    P12_3_LCD_SEG16                 = 12,       /* Digital Deep Sleep - lcd.seg[16]:1 */
    P12_3_LCD_COM16                 = 13,       /* Digital Deep Sleep - lcd.com[16]:1 */
    P12_3_TDM0_TDM_TX_MCK1          = 16,       /* Digital Active - tdm[0].tdm_tx_mck[1]:0 */
    P12_3_TDM0_TDM_RX_MCK0          = 17,       /* Digital Active - tdm[0].tdm_rx_mck[0]:0 */
    P12_3_SCB2_SPI_SELECT0          = 22,       /* Digital Active - scb[2].spi_select0:0 */
    P12_3_SCB2_UART_CTS             = 23,       /* Digital Active - scb[2].uart_cts:0 */

    /* P12.4 */
    P12_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_4_AMUXA                     =  4,       /* Analog mux bus A */
    P12_4_AMUXB                     =  5,       /* Analog mux bus B */
    P12_4_TCPWM0_LINE0              =  8,       /* Digital Active - tcpwm[0].line[0]:0 */
    P12_4_TCPWM0_LINE_COMPL11       =  9,       /* Digital Active - tcpwm[0].line_compl[11]:1 */
    P12_4_LCD_SEG17                 = 12,       /* Digital Deep Sleep - lcd.seg[17]:1 */
    P12_4_LCD_COM17                 = 13,       /* Digital Deep Sleep - lcd.com[17]:1 */
    P12_4_TDM0_TDM_TX_SCK1          = 16,       /* Digital Active - tdm[0].tdm_tx_sck[1]:0 */
    P12_4_TDM0_TDM_RX_SCK0          = 17,       /* Digital Active - tdm[0].tdm_rx_sck[0]:0 */
    P12_4_SCB2_SPI_SELECT1          = 22,       /* Digital Active - scb[2].spi_select1:0 */

    /* P12.5 */
    P12_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_5_AMUXA                     =  4,       /* Analog mux bus A */
    P12_5_AMUXB                     =  5,       /* Analog mux bus B */
    P12_5_TCPWM0_LINE1              =  8,       /* Digital Active - tcpwm[0].line[1]:0 */
    P12_5_TCPWM0_LINE_COMPL0        =  9,       /* Digital Active - tcpwm[0].line_compl[0]:0 */
    P12_5_LCD_SEG18                 = 12,       /* Digital Deep Sleep - lcd.seg[18]:1 */
    P12_5_LCD_COM18                 = 13,       /* Digital Deep Sleep - lcd.com[18]:1 */
    P12_5_TDM0_TDM_TX_FSYNC1        = 16,       /* Digital Active - tdm[0].tdm_tx_fsync[1]:0 */
    P12_5_TDM0_TDM_RX_FSYNC0        = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[0]:0 */

    /* P12.6 */
    P12_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_6_AMUXA                     =  4,       /* Analog mux bus A */
    P12_6_AMUXB                     =  5,       /* Analog mux bus B */
    P12_6_TCPWM0_LINE2              =  8,       /* Digital Active - tcpwm[0].line[2]:0 */
    P12_6_TCPWM0_LINE_COMPL1        =  9,       /* Digital Active - tcpwm[0].line_compl[1]:0 */
    P12_6_LCD_SEG19                 = 12,       /* Digital Deep Sleep - lcd.seg[19]:1 */
    P12_6_LCD_COM19                 = 13,       /* Digital Deep Sleep - lcd.com[19]:1 */
    P12_6_TDM0_TDM_TX_SD1           = 16,       /* Digital Active - tdm[0].tdm_tx_sd[1]:0 */
    P12_6_TDM0_TDM_RX_SD0           = 17,       /* Digital Active - tdm[0].tdm_rx_sd[0]:0 */

    /* P12.7 */
    P12_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_7_AMUXA                     =  4,       /* Analog mux bus A */
    P12_7_AMUXB                     =  5,       /* Analog mux bus B */
    P12_7_TCPWM0_LINE3              =  8,       /* Digital Active - tcpwm[0].line[3]:0 */
    P12_7_TCPWM0_LINE_COMPL2        =  9,       /* Digital Active - tcpwm[0].line_compl[2]:0 */
    P12_7_LCD_SEG20                 = 12,       /* Digital Deep Sleep - lcd.seg[20]:1 */
    P12_7_LCD_COM20                 = 13,       /* Digital Deep Sleep - lcd.com[20]:1 */
    P12_7_PERI_TR_IO_INPUT19        = 25,       /* Digital Active - peri.tr_io_input[19]:0 */

    /* P13.0 */
    P13_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_0_AMUXA                     =  4,       /* Analog mux bus A */
    P13_0_AMUXB                     =  5,       /* Analog mux bus B */
    P13_0_TCPWM0_LINE4              =  8,       /* Digital Active - tcpwm[0].line[4]:0 */
    P13_0_TCPWM0_LINE_COMPL18       =  9,       /* Digital Active - tcpwm[0].line_compl[18]:0 */
    P13_0_TCPWM0_TR_ONE_CNT_IN25    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[25]:0 */
    P13_0_LCD_SEG0                  = 12,       /* Digital Deep Sleep - lcd.seg[0]:0 */
    P13_0_LCD_COM0                  = 13,       /* Digital Deep Sleep - lcd.com[0]:0 */
    P13_0_TDM0_TDM_TX_MCK0          = 16,       /* Digital Active - tdm[0].tdm_tx_mck[0]:1 */
    P13_0_TDM0_TDM_RX_MCK1          = 17,       /* Digital Active - tdm[0].tdm_rx_mck[1]:1 */
    P13_0_PWM0_PWM_LINE1_P0         = 20,       /* Digital Active - pwm[0].pwm_line1_p[0]:1 */
    P13_0_SCB4_SPI_CLK              = 22,       /* Digital Active - scb[4].spi_clk:1 */
    P13_0_SCB4_UART_RX              = 23,       /* Digital Active - scb[4].uart_rx:1 */
    P13_0_SCB4_I2C_SDA              = 24,       /* Digital Active - scb[4].i2c_sda:1 */
    P13_0_PERI_TR_IO_INPUT20        = 25,       /* Digital Active - peri.tr_io_input[20]:0 */

    /* P13.1 */
    P13_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_1_AMUXA                     =  4,       /* Analog mux bus A */
    P13_1_AMUXB                     =  5,       /* Analog mux bus B */
    P13_1_TCPWM0_LINE5              =  8,       /* Digital Active - tcpwm[0].line[5]:0 */
    P13_1_TCPWM0_LINE_COMPL4        =  9,       /* Digital Active - tcpwm[0].line_compl[4]:0 */
    P13_1_TCPWM0_TR_ONE_CNT_IN26    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[26]:0 */
    P13_1_LCD_SEG1                  = 12,       /* Digital Deep Sleep - lcd.seg[1]:0 */
    P13_1_LCD_COM1                  = 13,       /* Digital Deep Sleep - lcd.com[1]:0 */
    P13_1_TDM0_TDM_TX_SCK0          = 16,       /* Digital Active - tdm[0].tdm_tx_sck[0]:1 */
    P13_1_TDM0_TDM_RX_SCK1          = 17,       /* Digital Active - tdm[0].tdm_rx_sck[1]:1 */
    P13_1_PWM0_PWM_LINE1_N0         = 20,       /* Digital Active - pwm[0].pwm_line1_n[0]:1 */
    P13_1_SCB4_SPI_MOSI             = 22,       /* Digital Active - scb[4].spi_mosi:1 */
    P13_1_SCB4_UART_TX              = 23,       /* Digital Active - scb[4].uart_tx:1 */
    P13_1_SCB4_I2C_SCL              = 24,       /* Digital Active - scb[4].i2c_scl:1 */
    P13_1_PERI_TR_IO_INPUT21        = 25,       /* Digital Active - peri.tr_io_input[21]:0 */

    /* P13.2 */
    P13_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_2_AMUXA                     =  4,       /* Analog mux bus A */
    P13_2_AMUXB                     =  5,       /* Analog mux bus B */
    P13_2_TCPWM0_LINE6              =  8,       /* Digital Active - tcpwm[0].line[6]:0 */
    P13_2_TCPWM0_LINE_COMPL5        =  9,       /* Digital Active - tcpwm[0].line_compl[5]:0 */
    P13_2_TCPWM0_TR_ONE_CNT_IN27    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[27]:0 */
    P13_2_LCD_SEG2                  = 12,       /* Digital Deep Sleep - lcd.seg[2]:0 */
    P13_2_LCD_COM2                  = 13,       /* Digital Deep Sleep - lcd.com[2]:0 */
    P13_2_TDM0_TDM_TX_FSYNC0        = 16,       /* Digital Active - tdm[0].tdm_tx_fsync[0]:1 */
    P13_2_TDM0_TDM_RX_FSYNC1        = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[1]:1 */
    P13_2_PWM0_PWM_LINE2_P0         = 20,       /* Digital Active - pwm[0].pwm_line2_p[0]:1 */
    P13_2_SCB4_SPI_MISO             = 22,       /* Digital Active - scb[4].spi_miso:1 */
    P13_2_SCB4_UART_RTS             = 23,       /* Digital Active - scb[4].uart_rts:1 */

    /* P13.3 */
    P13_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_3_AMUXA                     =  4,       /* Analog mux bus A */
    P13_3_AMUXB                     =  5,       /* Analog mux bus B */
    P13_3_TCPWM0_LINE7              =  8,       /* Digital Active - tcpwm[0].line[7]:0 */
    P13_3_TCPWM0_LINE_COMPL6        =  9,       /* Digital Active - tcpwm[0].line_compl[6]:0 */
    P13_3_TCPWM0_TR_ONE_CNT_IN28    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[28]:0 */
    P13_3_LCD_SEG3                  = 12,       /* Digital Deep Sleep - lcd.seg[3]:0 */
    P13_3_LCD_COM3                  = 13,       /* Digital Deep Sleep - lcd.com[3]:0 */
    P13_3_TDM0_TDM_TX_SD0           = 16,       /* Digital Active - tdm[0].tdm_tx_sd[0]:1 */
    P13_3_TDM0_TDM_RX_SD1           = 17,       /* Digital Active - tdm[0].tdm_rx_sd[1]:1 */
    P13_3_PWM0_PWM_LINE2_N0         = 20,       /* Digital Active - pwm[0].pwm_line2_n[0]:1 */
    P13_3_SCB4_SPI_SELECT0          = 22,       /* Digital Active - scb[4].spi_select0:1 */
    P13_3_SCB4_UART_CTS             = 23,       /* Digital Active - scb[4].uart_cts:1 */

    /* P14.0 */
    P14_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_0_AMUXA                     =  4,       /* Analog mux bus A */
    P14_0_AMUXB                     =  5,       /* Analog mux bus B */
    P14_0_TCPWM0_LINE515            =  8,       /* Digital Active - tcpwm[0].line[515]:1 */
    P14_0_TCPWM0_LINE_COMPL7        =  9,       /* Digital Active - tcpwm[0].line_compl[7]:0 */
    P14_0_LCD_SEG4                  = 12,       /* Digital Deep Sleep - lcd.seg[4]:0 */
    P14_0_LCD_COM4                  = 13,       /* Digital Deep Sleep - lcd.com[4]:0 */
    P14_0_SCB0_SPI_CLK              = 14,       /* Digital Deep Sleep - scb[0].spi_clk:0 */
    P14_0_SCB0_I2C_SDA              = 15,       /* Digital Deep Sleep - scb[0].i2c_sda:0 */
    P14_0_SG0_SG_TONE1              = 21,       /* Digital Active - sg[0].sg_tone[1]:0 */
    P14_0_SCB0_UART_RX              = 23,       /* Digital Active - scb[0].uart_rx:0 */

    /* P14.1 */
    P14_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_1_AMUXA                     =  4,       /* Analog mux bus A */
    P14_1_AMUXB                     =  5,       /* Analog mux bus B */
    P14_1_TCPWM0_LINE516            =  8,       /* Digital Active - tcpwm[0].line[516]:1 */
    P14_1_TCPWM0_LINE_COMPL515      =  9,       /* Digital Active - tcpwm[0].line_compl[515]:1 */
    P14_1_LCD_SEG5                  = 12,       /* Digital Deep Sleep - lcd.seg[5]:0 */
    P14_1_LCD_COM5                  = 13,       /* Digital Deep Sleep - lcd.com[5]:0 */
    P14_1_SCB0_SPI_MOSI             = 14,       /* Digital Deep Sleep - scb[0].spi_mosi:0 */
    P14_1_SCB0_I2C_SCL              = 15,       /* Digital Deep Sleep - scb[0].i2c_scl:0 */
    P14_1_SG0_SG_AMPL1              = 21,       /* Digital Active - sg[0].sg_ampl[1]:0 */
    P14_1_SCB0_UART_TX              = 23,       /* Digital Active - scb[0].uart_tx:0 */

    /* P14.2 */
    P14_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_2_AMUXA                     =  4,       /* Analog mux bus A */
    P14_2_AMUXB                     =  5,       /* Analog mux bus B */
    P14_2_TCPWM0_LINE517            =  8,       /* Digital Active - tcpwm[0].line[517]:1 */
    P14_2_TCPWM0_LINE_COMPL516      =  9,       /* Digital Active - tcpwm[0].line_compl[516]:1 */
    P14_2_TCPWM0_TR_ONE_CNT_IN515   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[515]:1 */
    P14_2_LCD_SEG6                  = 12,       /* Digital Deep Sleep - lcd.seg[6]:0 */
    P14_2_LCD_COM6                  = 13,       /* Digital Deep Sleep - lcd.com[6]:0 */
    P14_2_SCB0_SPI_MISO             = 14,       /* Digital Deep Sleep - scb[0].spi_miso:0 */
    P14_2_SG0_SG_MCK1               = 21,       /* Digital Active - sg[0].sg_mck[1]:0 */
    P14_2_SCB0_UART_RTS             = 23,       /* Digital Active - scb[0].uart_rts:0 */
    P14_2_SCB1_I2C_SDA              = 24,       /* Digital Active - scb[1].i2c_sda:1 */

    /* P14.3 */
    P14_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_3_AMUXA                     =  4,       /* Analog mux bus A */
    P14_3_AMUXB                     =  5,       /* Analog mux bus B */
    P14_3_TCPWM0_LINE8              =  8,       /* Digital Active - tcpwm[0].line[8]:0 */
    P14_3_TCPWM0_LINE_COMPL517      =  9,       /* Digital Active - tcpwm[0].line_compl[517]:1 */
    P14_3_TCPWM0_TR_ONE_CNT_IN516   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[516]:1 */
    P14_3_LCD_SEG7                  = 12,       /* Digital Deep Sleep - lcd.seg[7]:0 */
    P14_3_LCD_COM7                  = 13,       /* Digital Deep Sleep - lcd.com[7]:0 */
    P14_3_SCB0_SPI_SELECT0          = 14,       /* Digital Deep Sleep - scb[0].spi_select0:0 */
    P14_3_SG0_SG_TONE2              = 21,       /* Digital Active - sg[0].sg_tone[2]:0 */
    P14_3_SCB0_UART_CTS             = 23,       /* Digital Active - scb[0].uart_cts:0 */
    P14_3_SCB1_I2C_SCL              = 24,       /* Digital Active - scb[1].i2c_scl:1 */

    /* P14.4 */
    P14_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_4_AMUXA                     =  4,       /* Analog mux bus A */
    P14_4_AMUXB                     =  5,       /* Analog mux bus B */
    P14_4_TCPWM0_LINE9              =  8,       /* Digital Active - tcpwm[0].line[9]:0 */
    P14_4_TCPWM0_LINE_COMPL8        =  9,       /* Digital Active - tcpwm[0].line_compl[8]:0 */
    P14_4_TCPWM0_TR_ONE_CNT_IN517   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[517]:1 */
    P14_4_LCD_SEG8                  = 12,       /* Digital Deep Sleep - lcd.seg[8]:0 */
    P14_4_LCD_COM8                  = 13,       /* Digital Deep Sleep - lcd.com[8]:0 */
    P14_4_SCB0_SPI_SELECT1          = 14,       /* Digital Deep Sleep - scb[0].spi_select1:0 */
    P14_4_PWM0_PWM_MCK0             = 20,       /* Digital Active - pwm[0].pwm_mck[0]:1 */
    P14_4_SG0_SG_AMPL2              = 21,       /* Digital Active - sg[0].sg_ampl[2]:0 */
    P14_4_SCB10_I2C_SDA             = 24,       /* Digital Active - scb[10].i2c_sda:1 */

    /* P14.5 */
    P14_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_5_AMUXA                     =  4,       /* Analog mux bus A */
    P14_5_AMUXB                     =  5,       /* Analog mux bus B */
    P14_5_TCPWM0_LINE10             =  8,       /* Digital Active - tcpwm[0].line[10]:0 */
    P14_5_TCPWM0_LINE_COMPL9        =  9,       /* Digital Active - tcpwm[0].line_compl[9]:0 */
    P14_5_TCPWM0_TR_ONE_CNT_IN29    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[29]:0 */
    P14_5_LCD_SEG9                  = 12,       /* Digital Deep Sleep - lcd.seg[9]:0 */
    P14_5_LCD_COM9                  = 13,       /* Digital Deep Sleep - lcd.com[9]:0 */
    P14_5_SCB0_SPI_SELECT2          = 14,       /* Digital Deep Sleep - scb[0].spi_select2:0 */
    P14_5_PWM0_PWM_MCK1             = 20,       /* Digital Active - pwm[0].pwm_mck[1]:1 */
    P14_5_SG0_SG_MCK2               = 21,       /* Digital Active - sg[0].sg_mck[2]:0 */
    P14_5_SCB10_I2C_SCL             = 24,       /* Digital Active - scb[10].i2c_scl:1 */

    /* P14.6 */
    P14_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_6_AMUXA                     =  4,       /* Analog mux bus A */
    P14_6_AMUXB                     =  5,       /* Analog mux bus B */
    P14_6_TCPWM0_LINE11             =  8,       /* Digital Active - tcpwm[0].line[11]:0 */
    P14_6_TCPWM0_LINE_COMPL10       =  9,       /* Digital Active - tcpwm[0].line_compl[10]:0 */
    P14_6_TCPWM0_TR_ONE_CNT_IN30    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[30]:0 */
    P14_6_LCD_SEG10                 = 12,       /* Digital Deep Sleep - lcd.seg[10]:0 */
    P14_6_LCD_COM10                 = 13,       /* Digital Deep Sleep - lcd.com[10]:0 */
    P14_6_SCB0_SPI_SELECT3          = 14,       /* Digital Deep Sleep - scb[0].spi_select3:0 */
    P14_6_SG0_SG_TONE3              = 21,       /* Digital Active - sg[0].sg_tone[3]:1 */
    P14_6_SCB11_I2C_SDA             = 24,       /* Digital Active - scb[11].i2c_sda:1 */

    /* P14.7 */
    P14_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_7_AMUXA                     =  4,       /* Analog mux bus A */
    P14_7_AMUXB                     =  5,       /* Analog mux bus B */
    P14_7_TCPWM0_LINE12             =  8,       /* Digital Active - tcpwm[0].line[12]:0 */
    P14_7_TCPWM0_LINE_COMPL11       =  9,       /* Digital Active - tcpwm[0].line_compl[11]:0 */
    P14_7_LCD_SEG11                 = 12,       /* Digital Deep Sleep - lcd.seg[11]:0 */
    P14_7_LCD_COM11                 = 13,       /* Digital Deep Sleep - lcd.com[11]:0 */
    P14_7_SG0_SG_AMPL3              = 21,       /* Digital Active - sg[0].sg_ampl[3]:1 */
    P14_7_SCB11_I2C_SCL             = 24,       /* Digital Active - scb[11].i2c_scl:1 */

    /* P15.0 */
    P15_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_0_AMUXA                     =  4,       /* Analog mux bus A */
    P15_0_AMUXB                     =  5,       /* Analog mux bus B */
    P15_0_TCPWM0_LINE13             =  8,       /* Digital Active - tcpwm[0].line[13]:0 */
    P15_0_TCPWM0_LINE_COMPL12       =  9,       /* Digital Active - tcpwm[0].line_compl[12]:0 */
    P15_0_LCD_SEG12                 = 12,       /* Digital Deep Sleep - lcd.seg[12]:0 */
    P15_0_LCD_COM12                 = 13,       /* Digital Deep Sleep - lcd.com[12]:0 */
    P15_0_TDM0_TDM_TX_MCK1          = 16,       /* Digital Active - tdm[0].tdm_tx_mck[1]:1 */
    P15_0_TDM0_TDM_RX_MCK0          = 17,       /* Digital Active - tdm[0].tdm_rx_mck[0]:1 */
    P15_0_PWM0_PWM_LINE1_P1         = 20,       /* Digital Active - pwm[0].pwm_line1_p[1]:1 */
    P15_0_SG0_SG_MCK3               = 21,       /* Digital Active - sg[0].sg_mck[3]:1 */
    P15_0_SCB3_SPI_CLK              = 22,       /* Digital Active - scb[3].spi_clk:0 */
    P15_0_SCB3_UART_RX              = 23,       /* Digital Active - scb[3].uart_rx:0 */
    P15_0_SCB3_I2C_SDA              = 24,       /* Digital Active - scb[3].i2c_sda:0 */

    /* P15.1 */
    P15_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_1_AMUXA                     =  4,       /* Analog mux bus A */
    P15_1_AMUXB                     =  5,       /* Analog mux bus B */
    P15_1_TCPWM0_LINE518            =  8,       /* Digital Active - tcpwm[0].line[518]:1 */
    P15_1_TCPWM0_LINE_COMPL13       =  9,       /* Digital Active - tcpwm[0].line_compl[13]:0 */
    P15_1_LCD_SEG13                 = 12,       /* Digital Deep Sleep - lcd.seg[13]:0 */
    P15_1_LCD_COM13                 = 13,       /* Digital Deep Sleep - lcd.com[13]:0 */
    P15_1_TDM0_TDM_TX_SCK1          = 16,       /* Digital Active - tdm[0].tdm_tx_sck[1]:1 */
    P15_1_TDM0_TDM_RX_SCK0          = 17,       /* Digital Active - tdm[0].tdm_rx_sck[0]:1 */
    P15_1_PWM0_PWM_LINE1_N1         = 20,       /* Digital Active - pwm[0].pwm_line1_n[1]:1 */
    P15_1_SCB3_SPI_MOSI             = 22,       /* Digital Active - scb[3].spi_mosi:0 */
    P15_1_SCB3_UART_TX              = 23,       /* Digital Active - scb[3].uart_tx:0 */
    P15_1_SCB3_I2C_SCL              = 24,       /* Digital Active - scb[3].i2c_scl:0 */

    /* P15.2 */
    P15_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_2_AMUXA                     =  4,       /* Analog mux bus A */
    P15_2_AMUXB                     =  5,       /* Analog mux bus B */
    P15_2_TCPWM0_LINE519            =  8,       /* Digital Active - tcpwm[0].line[519]:1 */
    P15_2_TCPWM0_LINE_COMPL518      =  9,       /* Digital Active - tcpwm[0].line_compl[518]:1 */
    P15_2_LCD_SEG14                 = 12,       /* Digital Deep Sleep - lcd.seg[14]:0 */
    P15_2_LCD_COM14                 = 13,       /* Digital Deep Sleep - lcd.com[14]:0 */
    P15_2_TDM0_TDM_TX_FSYNC1        = 16,       /* Digital Active - tdm[0].tdm_tx_fsync[1]:1 */
    P15_2_TDM0_TDM_RX_FSYNC0        = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[0]:1 */
    P15_2_PWM0_PWM_LINE2_P1         = 20,       /* Digital Active - pwm[0].pwm_line2_p[1]:1 */
    P15_2_SCB3_SPI_MISO             = 22,       /* Digital Active - scb[3].spi_miso:0 */
    P15_2_SCB3_UART_RTS             = 23,       /* Digital Active - scb[3].uart_rts:0 */

    /* P15.3 */
    P15_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_3_AMUXA                     =  4,       /* Analog mux bus A */
    P15_3_AMUXB                     =  5,       /* Analog mux bus B */
    P15_3_TCPWM0_LINE14             =  8,       /* Digital Active - tcpwm[0].line[14]:0 */
    P15_3_TCPWM0_LINE_COMPL519      =  9,       /* Digital Active - tcpwm[0].line_compl[519]:1 */
    P15_3_TCPWM0_TR_ONE_CNT_IN518   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[518]:1 */
    P15_3_LCD_SEG15                 = 12,       /* Digital Deep Sleep - lcd.seg[15]:0 */
    P15_3_LCD_COM15                 = 13,       /* Digital Deep Sleep - lcd.com[15]:0 */
    P15_3_TDM0_TDM_TX_SD1           = 16,       /* Digital Active - tdm[0].tdm_tx_sd[1]:1 */
    P15_3_TDM0_TDM_RX_SD0           = 17,       /* Digital Active - tdm[0].tdm_rx_sd[0]:1 */
    P15_3_PWM0_PWM_LINE2_N1         = 20,       /* Digital Active - pwm[0].pwm_line2_n[1]:1 */
    P15_3_SCB3_SPI_SELECT0          = 22,       /* Digital Active - scb[3].spi_select0:0 */
    P15_3_SCB3_UART_CTS             = 23,       /* Digital Active - scb[3].uart_cts:0 */

    /* P15.4 */
    P15_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_4_AMUXA                     =  4,       /* Analog mux bus A */
    P15_4_AMUXB                     =  5,       /* Analog mux bus B */
    P15_4_TCPWM0_LINE15             =  8,       /* Digital Active - tcpwm[0].line[15]:0 */
    P15_4_TCPWM0_LINE_COMPL14       =  9,       /* Digital Active - tcpwm[0].line_compl[14]:0 */
    P15_4_TCPWM0_TR_ONE_CNT_IN519   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[519]:1 */
    P15_4_LCD_SEG16                 = 12,       /* Digital Deep Sleep - lcd.seg[16]:0 */
    P15_4_LCD_COM16                 = 13,       /* Digital Deep Sleep - lcd.com[16]:0 */
    P15_4_SCB3_SPI_SELECT1          = 22,       /* Digital Active - scb[3].spi_select1:0 */
    P15_4_PERI_TR_IO_INPUT22        = 25,       /* Digital Active - peri.tr_io_input[22]:0 */

    /* P15.5 */
    P15_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_5_AMUXA                     =  4,       /* Analog mux bus A */
    P15_5_AMUXB                     =  5,       /* Analog mux bus B */
    P15_5_TCPWM0_LINE16             =  8,       /* Digital Active - tcpwm[0].line[16]:0 */
    P15_5_TCPWM0_LINE_COMPL15       =  9,       /* Digital Active - tcpwm[0].line_compl[15]:0 */
    P15_5_LCD_SEG17                 = 12,       /* Digital Deep Sleep - lcd.seg[17]:0 */
    P15_5_LCD_COM17                 = 13,       /* Digital Deep Sleep - lcd.com[17]:0 */
    P15_5_SG0_SG_TONE4              = 21,       /* Digital Active - sg[0].sg_tone[4]:1 */
    P15_5_PERI_TR_IO_INPUT23        = 25,       /* Digital Active - peri.tr_io_input[23]:0 */

    /* P15.6 */
    P15_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_6_AMUXA                     =  4,       /* Analog mux bus A */
    P15_6_AMUXB                     =  5,       /* Analog mux bus B */
    P15_6_TCPWM0_LINE17             =  8,       /* Digital Active - tcpwm[0].line[17]:0 */
    P15_6_TCPWM0_LINE_COMPL16       =  9,       /* Digital Active - tcpwm[0].line_compl[16]:0 */
    P15_6_LCD_SEG18                 = 12,       /* Digital Deep Sleep - lcd.seg[18]:0 */
    P15_6_LCD_COM18                 = 13,       /* Digital Deep Sleep - lcd.com[18]:0 */
    P15_6_SG0_SG_AMPL4              = 21,       /* Digital Active - sg[0].sg_ampl[4]:1 */
    P15_6_PERI_TR_IO_INPUT24        = 25,       /* Digital Active - peri.tr_io_input[24]:0 */

    /* P15.7 */
    P15_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_7_AMUXA                     =  4,       /* Analog mux bus A */
    P15_7_AMUXB                     =  5,       /* Analog mux bus B */
    P15_7_TCPWM0_LINE18             =  8,       /* Digital Active - tcpwm[0].line[18]:0 */
    P15_7_TCPWM0_LINE_COMPL17       =  9,       /* Digital Active - tcpwm[0].line_compl[17]:0 */
    P15_7_LCD_SEG19                 = 12,       /* Digital Deep Sleep - lcd.seg[19]:0 */
    P15_7_LCD_COM19                 = 13,       /* Digital Deep Sleep - lcd.com[19]:0 */
    P15_7_SG0_SG_MCK4               = 21,       /* Digital Active - sg[0].sg_mck[4]:1 */
    P15_7_PERI_TR_IO_INPUT25        = 25,       /* Digital Active - peri.tr_io_input[25]:0 */

    /* P16.0 */
    P16_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_0_AMUXA                     =  4,       /* Analog mux bus A */
    P16_0_AMUXB                     =  5,       /* Analog mux bus B */
    P16_0_TCPWM0_LINE19             =  8,       /* Digital Active - tcpwm[0].line[19]:0 */
    P16_0_TCPWM0_LINE_COMPL33       =  9,       /* Digital Active - tcpwm[0].line_compl[33]:0 */
    P16_0_LCD_SEG20                 = 12,       /* Digital Deep Sleep - lcd.seg[20]:0 */
    P16_0_LCD_COM20                 = 13,       /* Digital Deep Sleep - lcd.com[20]:0 */
    P16_0_PWM0_PWM_LINE1_P0         = 20,       /* Digital Active - pwm[0].pwm_line1_p[0]:0 */
    P16_0_SCB4_SPI_CLK              = 22,       /* Digital Active - scb[4].spi_clk:0 */
    P16_0_SCB4_UART_RX              = 23,       /* Digital Active - scb[4].uart_rx:0 */
    P16_0_SCB4_I2C_SDA              = 24,       /* Digital Active - scb[4].i2c_sda:0 */

    /* P16.1 */
    P16_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_1_AMUXA                     =  4,       /* Analog mux bus A */
    P16_1_AMUXB                     =  5,       /* Analog mux bus B */
    P16_1_TCPWM0_LINE520            =  8,       /* Digital Active - tcpwm[0].line[520]:1 */
    P16_1_TCPWM0_LINE_COMPL19       =  9,       /* Digital Active - tcpwm[0].line_compl[19]:0 */
    P16_1_LCD_SEG21                 = 12,       /* Digital Deep Sleep - lcd.seg[21]:0 */
    P16_1_LCD_COM21                 = 13,       /* Digital Deep Sleep - lcd.com[21]:0 */
    P16_1_PWM0_PWM_LINE1_N0         = 20,       /* Digital Active - pwm[0].pwm_line1_n[0]:0 */
    P16_1_SCB4_SPI_MOSI             = 22,       /* Digital Active - scb[4].spi_mosi:0 */
    P16_1_SCB4_UART_TX              = 23,       /* Digital Active - scb[4].uart_tx:0 */
    P16_1_SCB4_I2C_SCL              = 24,       /* Digital Active - scb[4].i2c_scl:0 */

    /* P16.2 */
    P16_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_2_AMUXA                     =  4,       /* Analog mux bus A */
    P16_2_AMUXB                     =  5,       /* Analog mux bus B */
    P16_2_TCPWM0_LINE521            =  8,       /* Digital Active - tcpwm[0].line[521]:1 */
    P16_2_TCPWM0_LINE_COMPL520      =  9,       /* Digital Active - tcpwm[0].line_compl[520]:1 */
    P16_2_LCD_SEG22                 = 12,       /* Digital Deep Sleep - lcd.seg[22]:0 */
    P16_2_LCD_COM22                 = 13,       /* Digital Deep Sleep - lcd.com[22]:0 */
    P16_2_PWM0_PWM_LINE2_P0         = 20,       /* Digital Active - pwm[0].pwm_line2_p[0]:0 */
    P16_2_SCB4_SPI_MISO             = 22,       /* Digital Active - scb[4].spi_miso:0 */
    P16_2_SCB4_UART_RTS             = 23,       /* Digital Active - scb[4].uart_rts:0 */

    /* P16.3 */
    P16_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_3_AMUXA                     =  4,       /* Analog mux bus A */
    P16_3_AMUXB                     =  5,       /* Analog mux bus B */
    P16_3_TCPWM0_LINE20             =  8,       /* Digital Active - tcpwm[0].line[20]:0 */
    P16_3_TCPWM0_LINE_COMPL521      =  9,       /* Digital Active - tcpwm[0].line_compl[521]:1 */
    P16_3_TCPWM0_TR_ONE_CNT_IN520   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[520]:1 */
    P16_3_LCD_SEG23                 = 12,       /* Digital Deep Sleep - lcd.seg[23]:0 */
    P16_3_LCD_COM23                 = 13,       /* Digital Deep Sleep - lcd.com[23]:0 */
    P16_3_PWM0_PWM_LINE2_N0         = 20,       /* Digital Active - pwm[0].pwm_line2_n[0]:0 */
    P16_3_SCB4_SPI_SELECT0          = 22,       /* Digital Active - scb[4].spi_select0:0 */
    P16_3_SCB4_UART_CTS             = 23,       /* Digital Active - scb[4].uart_cts:0 */

    /* P16.4 */
    P16_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_4_AMUXA                     =  4,       /* Analog mux bus A */
    P16_4_AMUXB                     =  5,       /* Analog mux bus B */
    P16_4_TCPWM0_LINE21             =  8,       /* Digital Active - tcpwm[0].line[21]:0 */
    P16_4_TCPWM0_LINE_COMPL20       =  9,       /* Digital Active - tcpwm[0].line_compl[20]:0 */
    P16_4_TCPWM0_TR_ONE_CNT_IN521   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[521]:1 */
    P16_4_LCD_SEG24                 = 12,       /* Digital Deep Sleep - lcd.seg[24]:0 */
    P16_4_LCD_COM24                 = 13,       /* Digital Deep Sleep - lcd.com[24]:0 */
    P16_4_PWM0_PWM_MCK0             = 20,       /* Digital Active - pwm[0].pwm_mck[0]:0 */
    P16_4_SG0_SG_MCK3               = 21,       /* Digital Active - sg[0].sg_mck[3]:0 */
    P16_4_SCB4_SPI_SELECT1          = 22,       /* Digital Active - scb[4].spi_select1:0 */

    /* P16.5 */
    P16_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_5_AMUXA                     =  4,       /* Analog mux bus A */
    P16_5_AMUXB                     =  5,       /* Analog mux bus B */
    P16_5_TCPWM0_LINE22             =  8,       /* Digital Active - tcpwm[0].line[22]:0 */
    P16_5_TCPWM0_LINE_COMPL21       =  9,       /* Digital Active - tcpwm[0].line_compl[21]:0 */
    P16_5_LCD_SEG25                 = 12,       /* Digital Deep Sleep - lcd.seg[25]:0 */
    P16_5_LCD_COM25                 = 13,       /* Digital Deep Sleep - lcd.com[25]:0 */
    P16_5_SG0_SG_MCK4               = 21,       /* Digital Active - sg[0].sg_mck[4]:0 */

    /* P17.0 */
    P17_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_0_AMUXA                     =  4,       /* Analog mux bus A */
    P17_0_AMUXB                     =  5,       /* Analog mux bus B */
    P17_0_TCPWM0_LINE23             =  8,       /* Digital Active - tcpwm[0].line[23]:0 */
    P17_0_TCPWM0_LINE_COMPL22       =  9,       /* Digital Active - tcpwm[0].line_compl[22]:0 */
    P17_0_LCD_SEG26                 = 12,       /* Digital Deep Sleep - lcd.seg[26]:0 */
    P17_0_LCD_COM26                 = 13,       /* Digital Deep Sleep - lcd.com[26]:0 */
    P17_0_PWM0_PWM_LINE1_P1         = 20,       /* Digital Active - pwm[0].pwm_line1_p[1]:0 */
    P17_0_SCB5_SPI_CLK              = 22,       /* Digital Active - scb[5].spi_clk:0 */
    P17_0_SCB5_UART_RX              = 23,       /* Digital Active - scb[5].uart_rx:0 */
    P17_0_SCB5_I2C_SDA              = 24,       /* Digital Active - scb[5].i2c_sda:0 */

    /* P17.1 */
    P17_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_1_AMUXA                     =  4,       /* Analog mux bus A */
    P17_1_AMUXB                     =  5,       /* Analog mux bus B */
    P17_1_TCPWM0_LINE24             =  8,       /* Digital Active - tcpwm[0].line[24]:0 */
    P17_1_TCPWM0_LINE_COMPL23       =  9,       /* Digital Active - tcpwm[0].line_compl[23]:0 */
    P17_1_TCPWM0_TR_ONE_CNT_IN20    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[20]:0 */
    P17_1_LCD_SEG27                 = 12,       /* Digital Deep Sleep - lcd.seg[27]:0 */
    P17_1_LCD_COM27                 = 13,       /* Digital Deep Sleep - lcd.com[27]:0 */
    P17_1_PWM0_PWM_LINE1_N1         = 20,       /* Digital Active - pwm[0].pwm_line1_n[1]:0 */
    P17_1_SCB5_SPI_MOSI             = 22,       /* Digital Active - scb[5].spi_mosi:0 */
    P17_1_SCB5_UART_TX              = 23,       /* Digital Active - scb[5].uart_tx:0 */
    P17_1_SCB5_I2C_SCL              = 24,       /* Digital Active - scb[5].i2c_scl:0 */

    /* P17.2 */
    P17_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_2_AMUXA                     =  4,       /* Analog mux bus A */
    P17_2_AMUXB                     =  5,       /* Analog mux bus B */
    P17_2_TCPWM0_LINE25             =  8,       /* Digital Active - tcpwm[0].line[25]:0 */
    P17_2_TCPWM0_LINE_COMPL24       =  9,       /* Digital Active - tcpwm[0].line_compl[24]:0 */
    P17_2_TCPWM0_TR_ONE_CNT_IN21    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[21]:0 */
    P17_2_LCD_SEG28                 = 12,       /* Digital Deep Sleep - lcd.seg[28]:0 */
    P17_2_LCD_COM28                 = 13,       /* Digital Deep Sleep - lcd.com[28]:0 */
    P17_2_PWM0_PWM_LINE2_P1         = 20,       /* Digital Active - pwm[0].pwm_line2_p[1]:0 */
    P17_2_SCB5_SPI_MISO             = 22,       /* Digital Active - scb[5].spi_miso:0 */
    P17_2_SCB5_UART_RTS             = 23,       /* Digital Active - scb[5].uart_rts:0 */

    /* P17.3 */
    P17_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_3_AMUXA                     =  4,       /* Analog mux bus A */
    P17_3_AMUXB                     =  5,       /* Analog mux bus B */
    P17_3_TCPWM0_LINE26             =  8,       /* Digital Active - tcpwm[0].line[26]:0 */
    P17_3_TCPWM0_LINE_COMPL25       =  9,       /* Digital Active - tcpwm[0].line_compl[25]:0 */
    P17_3_TCPWM0_TR_ONE_CNT_IN22    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[22]:0 */
    P17_3_LCD_SEG29                 = 12,       /* Digital Deep Sleep - lcd.seg[29]:0 */
    P17_3_LCD_COM29                 = 13,       /* Digital Deep Sleep - lcd.com[29]:0 */
    P17_3_PWM0_PWM_LINE2_N1         = 20,       /* Digital Active - pwm[0].pwm_line2_n[1]:0 */
    P17_3_SCB5_SPI_SELECT0          = 22,       /* Digital Active - scb[5].spi_select0:0 */
    P17_3_SCB5_UART_CTS             = 23,       /* Digital Active - scb[5].uart_cts:0 */
    P17_3_PERI_TR_IO_INPUT26        = 25,       /* Digital Active - peri.tr_io_input[26]:0 */

    /* P17.4 */
    P17_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_4_AMUXA                     =  4,       /* Analog mux bus A */
    P17_4_AMUXB                     =  5,       /* Analog mux bus B */
    P17_4_TCPWM0_LINE27             =  8,       /* Digital Active - tcpwm[0].line[27]:0 */
    P17_4_TCPWM0_LINE_COMPL26       =  9,       /* Digital Active - tcpwm[0].line_compl[26]:0 */
    P17_4_TCPWM0_TR_ONE_CNT_IN23    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[23]:0 */
    P17_4_LCD_SEG30                 = 12,       /* Digital Deep Sleep - lcd.seg[30]:0 */
    P17_4_LCD_COM30                 = 13,       /* Digital Deep Sleep - lcd.com[30]:0 */
    P17_4_PWM0_PWM_MCK1             = 20,       /* Digital Active - pwm[0].pwm_mck[1]:0 */
    P17_4_SG0_SG_TONE3              = 21,       /* Digital Active - sg[0].sg_tone[3]:0 */
    P17_4_SCB5_SPI_SELECT1          = 22,       /* Digital Active - scb[5].spi_select1:0 */
    P17_4_PERI_TR_IO_INPUT27        = 25,       /* Digital Active - peri.tr_io_input[27]:0 */

    /* P17.5 */
    P17_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_5_AMUXA                     =  4,       /* Analog mux bus A */
    P17_5_AMUXB                     =  5,       /* Analog mux bus B */
    P17_5_TCPWM0_LINE28             =  8,       /* Digital Active - tcpwm[0].line[28]:0 */
    P17_5_TCPWM0_LINE_COMPL27       =  9,       /* Digital Active - tcpwm[0].line_compl[27]:0 */
    P17_5_TCPWM0_TR_ONE_CNT_IN24    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[24]:0 */
    P17_5_LCD_SEG31                 = 12,       /* Digital Deep Sleep - lcd.seg[31]:0 */
    P17_5_LCD_COM31                 = 13,       /* Digital Deep Sleep - lcd.com[31]:0 */
    P17_5_SG0_SG_AMPL3              = 21,       /* Digital Active - sg[0].sg_ampl[3]:0 */

    /* P17.6 */
    P17_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_6_AMUXA                     =  4,       /* Analog mux bus A */
    P17_6_AMUXB                     =  5,       /* Analog mux bus B */
    P17_6_TCPWM0_LINE29             =  8,       /* Digital Active - tcpwm[0].line[29]:0 */
    P17_6_TCPWM0_LINE_COMPL28       =  9,       /* Digital Active - tcpwm[0].line_compl[28]:0 */
    P17_6_LCD_SEG32                 = 12,       /* Digital Deep Sleep - lcd.seg[32]:0 */
    P17_6_LCD_COM32                 = 13,       /* Digital Deep Sleep - lcd.com[32]:0 */
    P17_6_SG0_SG_TONE4              = 21,       /* Digital Active - sg[0].sg_tone[4]:0 */

    /* P17.7 */
    P17_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_7_AMUXA                     =  4,       /* Analog mux bus A */
    P17_7_AMUXB                     =  5,       /* Analog mux bus B */
    P17_7_TCPWM0_LINE30             =  8,       /* Digital Active - tcpwm[0].line[30]:0 */
    P17_7_TCPWM0_LINE_COMPL29       =  9,       /* Digital Active - tcpwm[0].line_compl[29]:0 */
    P17_7_LCD_SEG33                 = 12,       /* Digital Deep Sleep - lcd.seg[33]:0 */
    P17_7_LCD_COM33                 = 13,       /* Digital Deep Sleep - lcd.com[33]:0 */
    P17_7_SG0_SG_AMPL4              = 21,       /* Digital Active - sg[0].sg_ampl[4]:0 */

    /* P18.0 */
    P18_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_0_AMUXA                     =  4,       /* Analog mux bus A */
    P18_0_AMUXB                     =  5,       /* Analog mux bus B */
    P18_0_TCPWM0_LINE31             =  8,       /* Digital Active - tcpwm[0].line[31]:0 */
    P18_0_TCPWM0_LINE_COMPL30       =  9,       /* Digital Active - tcpwm[0].line_compl[30]:0 */
    P18_0_LCD_SEG34                 = 12,       /* Digital Deep Sleep - lcd.seg[34]:0 */
    P18_0_LCD_COM34                 = 13,       /* Digital Deep Sleep - lcd.com[34]:0 */
    P18_0_CANFD0_TTCAN_TX1          = 18,       /* Digital Active - canfd[0].ttcan_tx[1]:1 */
    P18_0_SCB6_SPI_CLK              = 22,       /* Digital Active - scb[6].spi_clk:0 */
    P18_0_SCB6_UART_RX              = 23,       /* Digital Active - scb[6].uart_rx:0 */
    P18_0_SCB6_I2C_SDA              = 24,       /* Digital Active - scb[6].i2c_sda:0 */

    /* P18.1 */
    P18_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_1_AMUXA                     =  4,       /* Analog mux bus A */
    P18_1_AMUXB                     =  5,       /* Analog mux bus B */
    P18_1_TCPWM0_LINE32             =  8,       /* Digital Active - tcpwm[0].line[32]:0 */
    P18_1_TCPWM0_LINE_COMPL31       =  9,       /* Digital Active - tcpwm[0].line_compl[31]:0 */
    P18_1_LCD_SEG35                 = 12,       /* Digital Deep Sleep - lcd.seg[35]:0 */
    P18_1_LCD_COM35                 = 13,       /* Digital Deep Sleep - lcd.com[35]:0 */
    P18_1_CANFD0_TTCAN_RX1          = 18,       /* Digital Active - canfd[0].ttcan_rx[1]:1 */
    P18_1_SCB6_SPI_MOSI             = 22,       /* Digital Active - scb[6].spi_mosi:0 */
    P18_1_SCB6_UART_TX              = 23,       /* Digital Active - scb[6].uart_tx:0 */
    P18_1_SCB6_I2C_SCL              = 24,       /* Digital Active - scb[6].i2c_scl:0 */

    /* P18.2 */
    P18_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_2_AMUXA                     =  4,       /* Analog mux bus A */
    P18_2_AMUXB                     =  5,       /* Analog mux bus B */
    P18_2_TCPWM0_LINE33             =  8,       /* Digital Active - tcpwm[0].line[33]:0 */
    P18_2_TCPWM0_LINE_COMPL32       =  9,       /* Digital Active - tcpwm[0].line_compl[32]:0 */
    P18_2_LCD_SEG21                 = 12,       /* Digital Deep Sleep - lcd.seg[21]:1 */
    P18_2_LCD_COM21                 = 13,       /* Digital Deep Sleep - lcd.com[21]:1 */
    P18_2_LIN0_LIN_TX1              = 16,       /* Digital Active - lin[0].lin_tx[1]:2 */
    P18_2_CXPI0_CXPI_TX1            = 17,       /* Digital Active - cxpi[0].cxpi_tx[1]:2 */
    P18_2_CANFD0_TTCAN_TX0          = 18,       /* Digital Active - canfd[0].ttcan_tx[0]:1 */
    P18_2_SCB6_SPI_MISO             = 22,       /* Digital Active - scb[6].spi_miso:0 */
    P18_2_SCB6_UART_RTS             = 23,       /* Digital Active - scb[6].uart_rts:0 */

    /* P18.3 */
    P18_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_3_AMUXA                     =  4,       /* Analog mux bus A */
    P18_3_AMUXB                     =  5,       /* Analog mux bus B */
    P18_3_TCPWM0_LINE12             =  8,       /* Digital Active - tcpwm[0].line[12]:1 */
    P18_3_TCPWM0_LINE_COMPL23       =  9,       /* Digital Active - tcpwm[0].line_compl[23]:1 */
    P18_3_TCPWM0_TR_ONE_CNT_IN20    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[20]:1 */
    P18_3_LCD_SEG22                 = 12,       /* Digital Deep Sleep - lcd.seg[22]:1 */
    P18_3_LCD_COM22                 = 13,       /* Digital Deep Sleep - lcd.com[22]:1 */
    P18_3_LIN0_LIN_RX1              = 16,       /* Digital Active - lin[0].lin_rx[1]:2 */
    P18_3_CXPI0_CXPI_RX1            = 17,       /* Digital Active - cxpi[0].cxpi_rx[1]:2 */
    P18_3_CANFD0_TTCAN_RX0          = 18,       /* Digital Active - canfd[0].ttcan_rx[0]:1 */
    P18_3_SCB6_SPI_SELECT0          = 22,       /* Digital Active - scb[6].spi_select0:0 */
    P18_3_SCB6_UART_CTS             = 23,       /* Digital Active - scb[6].uart_cts:0 */

    /* P18.4 */
    P18_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_4_AMUXA                     =  4,       /* Analog mux bus A */
    P18_4_AMUXB                     =  5,       /* Analog mux bus B */
    P18_4_TCPWM0_LINE13             =  8,       /* Digital Active - tcpwm[0].line[13]:1 */
    P18_4_TCPWM0_LINE_COMPL12       =  9,       /* Digital Active - tcpwm[0].line_compl[12]:1 */
    P18_4_TCPWM0_TR_ONE_CNT_IN21    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[21]:1 */
    P18_4_LCD_SEG23                 = 12,       /* Digital Deep Sleep - lcd.seg[23]:1 */
    P18_4_LCD_COM23                 = 13,       /* Digital Deep Sleep - lcd.com[23]:1 */
    P18_4_LIN0_LIN_EN1              = 16,       /* Digital Active - lin[0].lin_en[1]:2 */
    P18_4_CXPI0_CXPI_EN1            = 17,       /* Digital Active - cxpi[0].cxpi_en[1]:2 */
    P18_4_SCB6_SPI_SELECT1          = 22,       /* Digital Active - scb[6].spi_select1:0 */
    P18_4_PERI_TR_IO_INPUT28        = 25,       /* Digital Active - peri.tr_io_input[28]:0 */

    /* P18.5 */
    P18_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_5_AMUXA                     =  4,       /* Analog mux bus A */
    P18_5_AMUXB                     =  5,       /* Analog mux bus B */
    P18_5_TCPWM0_LINE14             =  8,       /* Digital Active - tcpwm[0].line[14]:1 */
    P18_5_TCPWM0_LINE_COMPL13       =  9,       /* Digital Active - tcpwm[0].line_compl[13]:1 */
    P18_5_LCD_SEG24                 = 12,       /* Digital Deep Sleep - lcd.seg[24]:1 */
    P18_5_LCD_COM24                 = 13,       /* Digital Deep Sleep - lcd.com[24]:1 */
    P18_5_PERI_TR_IO_INPUT29        = 25,       /* Digital Active - peri.tr_io_input[29]:0 */

    /* P18.6 */
    P18_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_6_AMUXA                     =  4,       /* Analog mux bus A */
    P18_6_AMUXB                     =  5,       /* Analog mux bus B */
    P18_6_TCPWM0_LINE15             =  8,       /* Digital Active - tcpwm[0].line[15]:1 */
    P18_6_TCPWM0_LINE_COMPL14       =  9,       /* Digital Active - tcpwm[0].line_compl[14]:1 */
    P18_6_TCPWM0_TR_ONE_CNT_IN22    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[22]:1 */
    P18_6_PERI_TR_IO_INPUT30        = 25,       /* Digital Active - peri.tr_io_input[30]:0 */

    /* P18.7 */
    P18_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_7_AMUXA                     =  4,       /* Analog mux bus A */
    P18_7_AMUXB                     =  5,       /* Analog mux bus B */
    P18_7_TCPWM0_LINE16             =  8,       /* Digital Active - tcpwm[0].line[16]:1 */
    P18_7_TCPWM0_LINE_COMPL15       =  9,       /* Digital Active - tcpwm[0].line_compl[15]:1 */
    P18_7_TCPWM0_TR_ONE_CNT_IN23    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[23]:1 */
    P18_7_LCD_SEG27                 = 12,       /* Digital Deep Sleep - lcd.seg[27]:1 */
    P18_7_LCD_COM27                 = 13,       /* Digital Deep Sleep - lcd.com[27]:1 */
    P18_7_PERI_TR_IO_INPUT31        = 25,       /* Digital Active - peri.tr_io_input[31]:0 */

    /* P19.0 */
    P19_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_0_AMUXA                     =  4,       /* Analog mux bus A */
    P19_0_AMUXB                     =  5,       /* Analog mux bus B */
    P19_0_TCPWM0_LINE17             =  8,       /* Digital Active - tcpwm[0].line[17]:1 */
    P19_0_TCPWM0_LINE_COMPL16       =  9,       /* Digital Active - tcpwm[0].line_compl[16]:1 */
    P19_0_LCD_SEG25                 = 12,       /* Digital Deep Sleep - lcd.seg[25]:1 */
    P19_0_LCD_COM25                 = 13,       /* Digital Deep Sleep - lcd.com[25]:1 */
    P19_0_LIN0_LIN_TX0              = 16,       /* Digital Active - lin[0].lin_tx[0]:1 */
    P19_0_CXPI0_CXPI_TX0            = 17,       /* Digital Active - cxpi[0].cxpi_tx[0]:1 */
    P19_0_CANFD1_TTCAN_TX1          = 18,       /* Digital Active - canfd[1].ttcan_tx[1]:1 */
    P19_0_SCB6_SPI_CLK              = 22,       /* Digital Active - scb[6].spi_clk:1 */
    P19_0_SCB6_UART_RX              = 23,       /* Digital Active - scb[6].uart_rx:1 */
    P19_0_SCB6_I2C_SDA              = 24,       /* Digital Active - scb[6].i2c_sda:1 */
    P19_0_CPUSS_CLK_FM_PUMP         = 26,       /* Digital Active - cpuss.clk_fm_pump */
    P19_0_CPUSS_FAULT_OUT0          = 27,       /* Digital Active - cpuss.fault_out[0]:1 */

    /* P19.1 */
    P19_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_1_AMUXA                     =  4,       /* Analog mux bus A */
    P19_1_AMUXB                     =  5,       /* Analog mux bus B */
    P19_1_TCPWM0_LINE18             =  8,       /* Digital Active - tcpwm[0].line[18]:1 */
    P19_1_TCPWM0_LINE_COMPL17       =  9,       /* Digital Active - tcpwm[0].line_compl[17]:1 */
    P19_1_LCD_SEG28                 = 12,       /* Digital Deep Sleep - lcd.seg[28]:1 */
    P19_1_LCD_COM28                 = 13,       /* Digital Deep Sleep - lcd.com[28]:1 */
    P19_1_LIN0_LIN_RX0              = 16,       /* Digital Active - lin[0].lin_rx[0]:1 */
    P19_1_CXPI0_CXPI_RX0            = 17,       /* Digital Active - cxpi[0].cxpi_rx[0]:1 */
    P19_1_CANFD1_TTCAN_RX1          = 18,       /* Digital Active - canfd[1].ttcan_rx[1]:1 */
    P19_1_SCB6_SPI_MOSI             = 22,       /* Digital Active - scb[6].spi_mosi:1 */
    P19_1_SCB6_UART_TX              = 23,       /* Digital Active - scb[6].uart_tx:1 */
    P19_1_SCB6_I2C_SCL              = 24,       /* Digital Active - scb[6].i2c_scl:1 */
    P19_1_CPUSS_FAULT_OUT1          = 27,       /* Digital Active - cpuss.fault_out[1]:1 */

    /* P19.2 */
    P19_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_2_AMUXA                     =  4,       /* Analog mux bus A */
    P19_2_AMUXB                     =  5,       /* Analog mux bus B */
    P19_2_TCPWM0_LINE19             =  8,       /* Digital Active - tcpwm[0].line[19]:1 */
    P19_2_TCPWM0_LINE_COMPL18       =  9,       /* Digital Active - tcpwm[0].line_compl[18]:1 */
    P19_2_TCPWM0_TR_ONE_CNT_IN31    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[31]:0 */
    P19_2_LCD_SEG29                 = 12,       /* Digital Deep Sleep - lcd.seg[29]:1 */
    P19_2_LCD_COM29                 = 13,       /* Digital Deep Sleep - lcd.com[29]:1 */
    P19_2_LIN0_LIN_EN0              = 16,       /* Digital Active - lin[0].lin_en[0]:1 */
    P19_2_CXPI0_CXPI_EN0            = 17,       /* Digital Active - cxpi[0].cxpi_en[0]:1 */
    P19_2_CANFD1_TTCAN_TX0          = 18,       /* Digital Active - canfd[1].ttcan_tx[0]:1 */
    P19_2_SCB6_SPI_MISO             = 22,       /* Digital Active - scb[6].spi_miso:1 */
    P19_2_SCB6_UART_RTS             = 23,       /* Digital Active - scb[6].uart_rts:1 */
    P19_2_CPUSS_FAULT_OUT2          = 27,       /* Digital Active - cpuss.fault_out[2]:1 */

    /* P19.3 */
    P19_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_3_AMUXA                     =  4,       /* Analog mux bus A */
    P19_3_AMUXB                     =  5,       /* Analog mux bus B */
    P19_3_TCPWM0_LINE20             =  8,       /* Digital Active - tcpwm[0].line[20]:1 */
    P19_3_TCPWM0_LINE_COMPL19       =  9,       /* Digital Active - tcpwm[0].line_compl[19]:1 */
    P19_3_TCPWM0_TR_ONE_CNT_IN32    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[32]:0 */
    P19_3_LCD_SEG32                 = 12,       /* Digital Deep Sleep - lcd.seg[32]:1 */
    P19_3_LCD_COM32                 = 13,       /* Digital Deep Sleep - lcd.com[32]:1 */
    P19_3_CANFD1_TTCAN_RX0          = 18,       /* Digital Active - canfd[1].ttcan_rx[0]:1 */
    P19_3_SCB6_SPI_SELECT0          = 22,       /* Digital Active - scb[6].spi_select0:1 */
    P19_3_SCB6_UART_CTS             = 23,       /* Digital Active - scb[6].uart_cts:1 */
    P19_3_CPUSS_FAULT_OUT3          = 27,       /* Digital Active - cpuss.fault_out[3]:1 */

    /* P19.4 */
    P19_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_4_AMUXA                     =  4,       /* Analog mux bus A */
    P19_4_AMUXB                     =  5,       /* Analog mux bus B */
    P19_4_TCPWM0_LINE21             =  8,       /* Digital Active - tcpwm[0].line[21]:1 */
    P19_4_TCPWM0_LINE_COMPL20       =  9,       /* Digital Active - tcpwm[0].line_compl[20]:1 */
    P19_4_TCPWM0_TR_ONE_CNT_IN33    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[33]:0 */
    P19_4_LCD_SEG33                 = 12,       /* Digital Deep Sleep - lcd.seg[33]:1 */
    P19_4_LCD_COM33                 = 13,       /* Digital Deep Sleep - lcd.com[33]:1 */
    P19_4_SCB6_SPI_SELECT1          = 22,       /* Digital Active - scb[6].spi_select1:1 */

    /* P19.5 */
    P19_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_5_AMUXA                     =  4,       /* Analog mux bus A */
    P19_5_AMUXB                     =  5,       /* Analog mux bus B */
    P19_5_TCPWM0_LINE22             =  8,       /* Digital Active - tcpwm[0].line[22]:1 */
    P19_5_TCPWM0_LINE_COMPL21       =  9,       /* Digital Active - tcpwm[0].line_compl[21]:1 */
    P19_5_LCD_SEG30                 = 12,       /* Digital Deep Sleep - lcd.seg[30]:1 */
    P19_5_LCD_COM30                 = 13,       /* Digital Deep Sleep - lcd.com[30]:1 */

    /* P19.6 */
    P19_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_6_AMUXA                     =  4,       /* Analog mux bus A */
    P19_6_AMUXB                     =  5,       /* Analog mux bus B */
    P19_6_TCPWM0_LINE23             =  8,       /* Digital Active - tcpwm[0].line[23]:1 */
    P19_6_TCPWM0_LINE_COMPL22       =  9,       /* Digital Active - tcpwm[0].line_compl[22]:1 */
    P19_6_LCD_SEG31                 = 12,       /* Digital Deep Sleep - lcd.seg[31]:1 */
    P19_6_LCD_COM31                 = 13        /* Digital Deep Sleep - lcd.com[31]:1 */
} en_hsiom_sel_t;

#endif /* _GPIO_CYT2CL_176_LQFP_H_ */


/* [] END OF FILE */
