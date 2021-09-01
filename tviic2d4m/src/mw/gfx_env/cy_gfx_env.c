/***************************************************************************//**
* \file cy_gfx_env.c
* \version 1.1
*
* \brief
* Provides an API implementation of the Graphics Environment (GfxEnv) middleware driver
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
#include "cy_gfx_env.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*****************************************************************************
* Local pre-processor symbols/macros ('define')
*****************************************************************************/

#define DISP0_CLK_PLL_MIN_HZ                      110000000UL
#define DISP0_CLK_PLL_MAX_HZ                      220000000UL
#define DISP1_CLK_PLL_MIN_HZ                      110000000UL
#define DISP1_CLK_PLL_MAX_HZ                      200000000UL  // 220 max if a PLL400M would be used

#define VIDEOSS_FIXED_DISP_CLK_DIV                2  // Fixed "divide-by-2" in the display clock path
#define CLK_PATH_DISP0_CLK                        5  // PLL400M #4
#define CLK_PATH_DISP1_CLK                        8  // PLL200M #2
#define CLK_PATH_SMIF_CLK                         3  // PLL400M #2
#define CLK_DIV_TO_REG_VAL(div)                   (((div) == 8) ? 3 : ((div) == 4) ? 2 : ((div) == 2) ? 1 : 0)

// Macros needed to generate the VIDEOSS TCON mapping values
//----
#define R(bit)                                    ((bit) +  0)
#define G(bit)                                    ((bit) +  8)
#define B(bit)                                    ((bit) + 16)
#define HSYNC                                     (24)
#define VSYNC                                     (25)
#define DEN                                       (26)
#define RES                                       (27)
#define MAP_VALUE(n0,n1,n2,n3)                    (((n3)<<24) + ((n2)<<16) + ((n1)<<8) +(n0))

#define MAP_INDEX_JEIDA                           0
#define MAP_INDEX_VESA                            1
//----

//====================================================================
// SMIF and HyperBus related macros

#define GFXENV_SMIF_EXT_CLOCK_MAX_MHZ             200  // Traveo II platform max. frequency, individual derivates may have a lower max. freq, please refer datasheet
#define GFXENV_SMIF_SAFE_EXT_CLOCK_MHZ            32
#define GFXENV_SMIF_TIMEOUT                       1000
#define GFXENV_HYPERFLASH_INITIAL_LATENCY         CY_SMIF_HB_LC16
#define GFXENV_HYPERRAM_INITIAL_LATENCY           CY_SMIF_HB_LC7
#define GFXENV_HYPERRAM_MAX_CS_LOW_NS             1000UL          // t_CMS in nanoseconds

//====================================================================

/*****************************************************************************
* Global variable definitions (declared in header file with 'extern')
*****************************************************************************/

/*****************************************************************************
* Local type definitions ('typedef')
*****************************************************************************/

/*****************************************************************************
 ** \brief Port pin group enumeration type
 *****************************************************************************/
typedef enum
{
    Display0,
    Display1,
    Capture0,
    Smif0,
    Smif1,
    BlDisp0,
    BlDisp1,
    BlFpd0,
    BlFpd1,
    Button,
} en_portpin_group_t;

/*****************************************************************************
 ** \brief Port pin configuration type
 *****************************************************************************/
typedef struct
{
    en_portpin_group_t          enGroup;
    volatile stc_GPIO_PRT_t*    pstcPort;
    uint8_t                     u8Pin;
    en_hsiom_sel_t              enMuxCfg;
    uint8_t                     u8DriveMode;
    uint8_t                     u8GpioOutVal;
} stc_portpin_cfg_t;

/*****************************************************************************
 ** \brief Display presets type
 *****************************************************************************/
typedef struct
{
    uint16_t  u16HorizontalActive;
    uint16_t  u16HorizontalTotal;
    uint16_t  u16VerticalActive;
    uint16_t  u16VerticalTotal;
    uint8_t   u8RefreshRateHz;
    bool      bUseFpd;
    uint8_t   u8MapIndex;
} stc_display_presets_t;

/*****************************************************************************
 ** \brief Holds some config and status values for a SMIF instance with its
 **        devices that need to be preserved across some function calls
 *****************************************************************************/
typedef struct
{
    volatile cy_stc_smif_reg_device_t * pstcDevRegBase;
    cy_stc_smif_context_t *             pstcCorrespondingSmifCtx;
    cy_stc_device_hb_config_t *         pstcSmifHbDrvCfg;
    uint8_t                             u8SmifExtClockMhz;
    cy_en_smif_hb_latency_code_t        enOptimalLatency;
    uint32_t                            u32CalibrationDataOffsetFromBase;
    bool                                bCalibrationPossible;
    cy_en_smif_delay_line_t             enDelayLineSelected;
    uint8_t                             u8DelayTapSelected;
} stc_smif_device_cfg_internal_t;

/*****************************************************************************
 ** \brief Holds some config and status values for a SMIF instance with its
 **        devices that need to be preserved across function calls
 *****************************************************************************/
typedef struct
{
    volatile cy_stc_smif_reg_t *    pstcSmifRegBase;
    stc_smif_device_cfg_internal_t  astcDevIntCfg[CY_GFXENV_NR_OF_DEVICES_PER_SMIF];
    cy_stc_smif_context_t           stcSmifCtx;
    cy_en_hf_clk_dividers_t         enHfClockDivider;
} stc_smif_cfg_internal_t;



/*****************************************************************************
* Local variable definitions ('static')
*****************************************************************************/

/*****************************************************************************
 ** \brief Display presets
 *****************************************************************************/
static const stc_display_presets_t m_astcDispPresets[] =
{
    { 0 }, // dummy for "CY_GFXENV_DISP_TYPE_NONE"
    { .u16HorizontalActive =  480, .u16HorizontalTotal =  592, .u16VerticalActive = 272, .u16VerticalTotal = 286, .u8RefreshRateHz = 60, .bUseFpd = false },
    { .u16HorizontalActive =  640, .u16HorizontalTotal =  800, .u16VerticalActive = 480, .u16VerticalTotal = 500, .u8RefreshRateHz = 60, .bUseFpd = false },
    { .u16HorizontalActive =  800, .u16HorizontalTotal =  992, .u16VerticalActive = 480, .u16VerticalTotal = 500, .u8RefreshRateHz = 60, .bUseFpd = false },
    { .u16HorizontalActive =  800, .u16HorizontalTotal =  992, .u16VerticalActive = 480, .u16VerticalTotal = 500, .u8RefreshRateHz = 60, .bUseFpd = true, .u8MapIndex = MAP_INDEX_JEIDA },
    { .u16HorizontalActive =  800, .u16HorizontalTotal =  992, .u16VerticalActive = 480, .u16VerticalTotal = 500, .u8RefreshRateHz = 60, .bUseFpd = true, .u8MapIndex = MAP_INDEX_VESA  },
    { .u16HorizontalActive = 1280, .u16HorizontalTotal = 1440, .u16VerticalActive = 768, .u16VerticalTotal = 790, .u8RefreshRateHz = 60, .bUseFpd = true, .u8MapIndex = MAP_INDEX_VESA },
    { .u16HorizontalActive = 1600, .u16HorizontalTotal = 1660, .u16VerticalActive = 480, .u16VerticalTotal = 528, .u8RefreshRateHz = 60, .bUseFpd = true, .u8MapIndex = MAP_INDEX_VESA },

};

/*****************************************************************************
 ** \brief FPD/LVDS Signal Mapping
 *****************************************************************************/
static const uint32_t m_aau32FpdMapping[7][2] =
{
//                    JEIDA standard                             VESA standard
//                +0     +1     +2     +3                    +0     +1     +2     +3
    { MAP_VALUE( G(2),  R(7),  R(6),  R(5)  ),   MAP_VALUE( G(0),  R(5),  R(4),  R(3)  ) },  // <-- Value for register MAPBIT3_0
    { MAP_VALUE( R(4),  R(3),  R(2),  B(3)  ),   MAP_VALUE( R(2),  R(1),  R(0),  B(1)  ) },  // <-- Value for register MAPBIT7_4
    { MAP_VALUE( B(2),  G(7),  G(6),  G(5)  ),   MAP_VALUE( B(0),  G(5),  G(4),  G(3)  ) },  // <-- Value for register MAPBIT11_8
    { MAP_VALUE( G(4),  G(3),  DEN,   VSYNC ),   MAP_VALUE( G(2),  G(1),  DEN,   VSYNC ) },  // <-- Value for register MAPBIT15_12
    { MAP_VALUE( HSYNC, B(7),  B(6),  B(5)  ),   MAP_VALUE( HSYNC, B(5),  B(4),  B(3)  ) },  // <-- Value for register MAPBIT19_16
    { MAP_VALUE( B(4),  RES,   B(1),  B(0)  ),   MAP_VALUE( B(2),  RES,   B(7),  B(6)  ) },  // <-- Value for register MAPBIT23_20
    { MAP_VALUE( G(1),  G(0),  R(1),  R(0)  ),   MAP_VALUE( G(7),  G(6),  R(7),  R(6)  ) },  // <-- Value for register MAPBIT27_24
};

/*****************************************************************************
 ** \brief Port pin configuration
 *****************************************************************************/
static const stc_portpin_cfg_t m_astcPortPinCfg[] =
{
//============================================================================================================================================================================================
#ifdef CY_BSP_HDR_DISP0_TTL_AVAILABLE
    { .enGroup = Display0, .pstcPort = CY_DISP0_CLK_PORT,        .u8Pin = CY_DISP0_CLK_PIN,        .enMuxCfg = CY_DISP0_CLK_PIN_MUX,        .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_CTRL0_PORT,      .u8Pin = CY_DISP0_CTRL0_PIN,      .enMuxCfg = CY_DISP0_CTRL0_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_CTRL1_PORT,      .u8Pin = CY_DISP0_CTRL1_PIN,      .enMuxCfg = CY_DISP0_CTRL1_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_CTRL2_PORT,      .u8Pin = CY_DISP0_CTRL2_PIN,      .enMuxCfg = CY_DISP0_CTRL2_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A0_0_PORT,  .u8Pin = CY_DISP0_DATA_A0_0_PIN,  .enMuxCfg = CY_DISP0_DATA_A0_0_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A0_1_PORT,  .u8Pin = CY_DISP0_DATA_A0_1_PIN,  .enMuxCfg = CY_DISP0_DATA_A0_1_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A0_2_PORT,  .u8Pin = CY_DISP0_DATA_A0_2_PIN,  .enMuxCfg = CY_DISP0_DATA_A0_2_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A0_3_PORT,  .u8Pin = CY_DISP0_DATA_A0_3_PIN,  .enMuxCfg = CY_DISP0_DATA_A0_3_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A0_4_PORT,  .u8Pin = CY_DISP0_DATA_A0_4_PIN,  .enMuxCfg = CY_DISP0_DATA_A0_4_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A0_5_PORT,  .u8Pin = CY_DISP0_DATA_A0_5_PIN,  .enMuxCfg = CY_DISP0_DATA_A0_5_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A0_6_PORT,  .u8Pin = CY_DISP0_DATA_A0_6_PIN,  .enMuxCfg = CY_DISP0_DATA_A0_6_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A0_7_PORT,  .u8Pin = CY_DISP0_DATA_A0_7_PIN,  .enMuxCfg = CY_DISP0_DATA_A0_7_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A0_8_PORT,  .u8Pin = CY_DISP0_DATA_A0_8_PIN,  .enMuxCfg = CY_DISP0_DATA_A0_8_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A0_9_PORT,  .u8Pin = CY_DISP0_DATA_A0_9_PIN,  .enMuxCfg = CY_DISP0_DATA_A0_9_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A0_10_PORT, .u8Pin = CY_DISP0_DATA_A0_10_PIN, .enMuxCfg = CY_DISP0_DATA_A0_10_PIN_MUX, .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A0_11_PORT, .u8Pin = CY_DISP0_DATA_A0_11_PIN, .enMuxCfg = CY_DISP0_DATA_A0_11_PIN_MUX, .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A1_0_PORT,  .u8Pin = CY_DISP0_DATA_A1_0_PIN,  .enMuxCfg = CY_DISP0_DATA_A1_0_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A1_1_PORT,  .u8Pin = CY_DISP0_DATA_A1_1_PIN,  .enMuxCfg = CY_DISP0_DATA_A1_1_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A1_2_PORT,  .u8Pin = CY_DISP0_DATA_A1_2_PIN,  .enMuxCfg = CY_DISP0_DATA_A1_2_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A1_3_PORT,  .u8Pin = CY_DISP0_DATA_A1_3_PIN,  .enMuxCfg = CY_DISP0_DATA_A1_3_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A1_4_PORT,  .u8Pin = CY_DISP0_DATA_A1_4_PIN,  .enMuxCfg = CY_DISP0_DATA_A1_4_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A1_5_PORT,  .u8Pin = CY_DISP0_DATA_A1_5_PIN,  .enMuxCfg = CY_DISP0_DATA_A1_5_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A1_6_PORT,  .u8Pin = CY_DISP0_DATA_A1_6_PIN,  .enMuxCfg = CY_DISP0_DATA_A1_6_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A1_7_PORT,  .u8Pin = CY_DISP0_DATA_A1_7_PIN,  .enMuxCfg = CY_DISP0_DATA_A1_7_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A1_8_PORT,  .u8Pin = CY_DISP0_DATA_A1_8_PIN,  .enMuxCfg = CY_DISP0_DATA_A1_8_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A1_9_PORT,  .u8Pin = CY_DISP0_DATA_A1_9_PIN,  .enMuxCfg = CY_DISP0_DATA_A1_9_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A1_10_PORT, .u8Pin = CY_DISP0_DATA_A1_10_PIN, .enMuxCfg = CY_DISP0_DATA_A1_10_PIN_MUX, .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display0, .pstcPort = CY_DISP0_DATA_A1_11_PORT, .u8Pin = CY_DISP0_DATA_A1_11_PIN, .enMuxCfg = CY_DISP0_DATA_A1_11_PIN_MUX, .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
#endif
//============================================================================================================================================================================================
#ifdef CY_BSP_HDR_DISP1_TTL_AVAILABLE
    { .enGroup = Display1, .pstcPort = CY_DISP1_CLK_PORT,        .u8Pin = CY_DISP1_CLK_PIN,        .enMuxCfg = CY_DISP1_CLK_PIN_MUX,        .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_CTRL0_PORT,      .u8Pin = CY_DISP1_CTRL0_PIN,      .enMuxCfg = CY_DISP1_CTRL0_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_CTRL1_PORT,      .u8Pin = CY_DISP1_CTRL1_PIN,      .enMuxCfg = CY_DISP1_CTRL1_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_CTRL2_PORT,      .u8Pin = CY_DISP1_CTRL2_PIN,      .enMuxCfg = CY_DISP1_CTRL2_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A0_0_PORT,  .u8Pin = CY_DISP1_DATA_A0_0_PIN,  .enMuxCfg = CY_DISP1_DATA_A0_0_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A0_1_PORT,  .u8Pin = CY_DISP1_DATA_A0_1_PIN,  .enMuxCfg = CY_DISP1_DATA_A0_1_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A0_2_PORT,  .u8Pin = CY_DISP1_DATA_A0_2_PIN,  .enMuxCfg = CY_DISP1_DATA_A0_2_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A0_3_PORT,  .u8Pin = CY_DISP1_DATA_A0_3_PIN,  .enMuxCfg = CY_DISP1_DATA_A0_3_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A0_4_PORT,  .u8Pin = CY_DISP1_DATA_A0_4_PIN,  .enMuxCfg = CY_DISP1_DATA_A0_4_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A0_5_PORT,  .u8Pin = CY_DISP1_DATA_A0_5_PIN,  .enMuxCfg = CY_DISP1_DATA_A0_5_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A0_6_PORT,  .u8Pin = CY_DISP1_DATA_A0_6_PIN,  .enMuxCfg = CY_DISP1_DATA_A0_6_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A0_7_PORT,  .u8Pin = CY_DISP1_DATA_A0_7_PIN,  .enMuxCfg = CY_DISP1_DATA_A0_7_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A0_8_PORT,  .u8Pin = CY_DISP1_DATA_A0_8_PIN,  .enMuxCfg = CY_DISP1_DATA_A0_8_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A0_9_PORT,  .u8Pin = CY_DISP1_DATA_A0_9_PIN,  .enMuxCfg = CY_DISP1_DATA_A0_9_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A0_10_PORT, .u8Pin = CY_DISP1_DATA_A0_10_PIN, .enMuxCfg = CY_DISP1_DATA_A0_10_PIN_MUX, .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A0_11_PORT, .u8Pin = CY_DISP1_DATA_A0_11_PIN, .enMuxCfg = CY_DISP1_DATA_A0_11_PIN_MUX, .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A1_0_PORT,  .u8Pin = CY_DISP1_DATA_A1_0_PIN,  .enMuxCfg = CY_DISP1_DATA_A1_0_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A1_1_PORT,  .u8Pin = CY_DISP1_DATA_A1_1_PIN,  .enMuxCfg = CY_DISP1_DATA_A1_1_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A1_2_PORT,  .u8Pin = CY_DISP1_DATA_A1_2_PIN,  .enMuxCfg = CY_DISP1_DATA_A1_2_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A1_3_PORT,  .u8Pin = CY_DISP1_DATA_A1_3_PIN,  .enMuxCfg = CY_DISP1_DATA_A1_3_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A1_4_PORT,  .u8Pin = CY_DISP1_DATA_A1_4_PIN,  .enMuxCfg = CY_DISP1_DATA_A1_4_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A1_5_PORT,  .u8Pin = CY_DISP1_DATA_A1_5_PIN,  .enMuxCfg = CY_DISP1_DATA_A1_5_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A1_6_PORT,  .u8Pin = CY_DISP1_DATA_A1_6_PIN,  .enMuxCfg = CY_DISP1_DATA_A1_6_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A1_7_PORT,  .u8Pin = CY_DISP1_DATA_A1_7_PIN,  .enMuxCfg = CY_DISP1_DATA_A1_7_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A1_8_PORT,  .u8Pin = CY_DISP1_DATA_A1_8_PIN,  .enMuxCfg = CY_DISP1_DATA_A1_8_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A1_9_PORT,  .u8Pin = CY_DISP1_DATA_A1_9_PIN,  .enMuxCfg = CY_DISP1_DATA_A1_9_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A1_10_PORT, .u8Pin = CY_DISP1_DATA_A1_10_PIN, .enMuxCfg = CY_DISP1_DATA_A1_10_PIN_MUX, .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Display1, .pstcPort = CY_DISP1_DATA_A1_11_PORT, .u8Pin = CY_DISP1_DATA_A1_11_PIN, .enMuxCfg = CY_DISP1_DATA_A1_11_PIN_MUX, .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
#endif
//============================================================================================================================================================================================
#ifdef CY_BSP_HDR_CAP0_TTL_AVAILABLE
    { .enGroup = Capture0, .pstcPort = CY_CAP0_CLK_PORT,         .u8Pin = CY_CAP0_CLK_PIN,         .enMuxCfg = CY_CAP0_CLK_PIN_MUX,         .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA0_PORT,       .u8Pin = CY_CAP0_DATA0_PIN,       .enMuxCfg = CY_CAP0_DATA0_PIN_MUX,       .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA1_PORT,       .u8Pin = CY_CAP0_DATA1_PIN,       .enMuxCfg = CY_CAP0_DATA1_PIN_MUX,       .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA2_PORT,       .u8Pin = CY_CAP0_DATA2_PIN,       .enMuxCfg = CY_CAP0_DATA2_PIN_MUX,       .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA3_PORT,       .u8Pin = CY_CAP0_DATA3_PIN,       .enMuxCfg = CY_CAP0_DATA3_PIN_MUX,       .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA4_PORT,       .u8Pin = CY_CAP0_DATA4_PIN,       .enMuxCfg = CY_CAP0_DATA4_PIN_MUX,       .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA5_PORT,       .u8Pin = CY_CAP0_DATA5_PIN,       .enMuxCfg = CY_CAP0_DATA5_PIN_MUX,       .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA6_PORT,       .u8Pin = CY_CAP0_DATA6_PIN,       .enMuxCfg = CY_CAP0_DATA6_PIN_MUX,       .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA7_PORT,       .u8Pin = CY_CAP0_DATA7_PIN,       .enMuxCfg = CY_CAP0_DATA7_PIN_MUX,       .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA8_PORT,       .u8Pin = CY_CAP0_DATA8_PIN,       .enMuxCfg = CY_CAP0_DATA8_PIN_MUX,       .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA9_PORT,       .u8Pin = CY_CAP0_DATA9_PIN,       .enMuxCfg = CY_CAP0_DATA9_PIN_MUX,       .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA10_PORT,      .u8Pin = CY_CAP0_DATA10_PIN,      .enMuxCfg = CY_CAP0_DATA10_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA11_PORT,      .u8Pin = CY_CAP0_DATA11_PIN,      .enMuxCfg = CY_CAP0_DATA11_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA12_PORT,      .u8Pin = CY_CAP0_DATA12_PIN,      .enMuxCfg = CY_CAP0_DATA12_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA13_PORT,      .u8Pin = CY_CAP0_DATA13_PIN,      .enMuxCfg = CY_CAP0_DATA13_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA14_PORT,      .u8Pin = CY_CAP0_DATA14_PIN,      .enMuxCfg = CY_CAP0_DATA14_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA15_PORT,      .u8Pin = CY_CAP0_DATA15_PIN,      .enMuxCfg = CY_CAP0_DATA15_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA16_PORT,      .u8Pin = CY_CAP0_DATA16_PIN,      .enMuxCfg = CY_CAP0_DATA16_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA17_PORT,      .u8Pin = CY_CAP0_DATA17_PIN,      .enMuxCfg = CY_CAP0_DATA17_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA18_PORT,      .u8Pin = CY_CAP0_DATA18_PIN,      .enMuxCfg = CY_CAP0_DATA18_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA19_PORT,      .u8Pin = CY_CAP0_DATA19_PIN,      .enMuxCfg = CY_CAP0_DATA19_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA20_PORT,      .u8Pin = CY_CAP0_DATA20_PIN,      .enMuxCfg = CY_CAP0_DATA20_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA21_PORT,      .u8Pin = CY_CAP0_DATA21_PIN,      .enMuxCfg = CY_CAP0_DATA21_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA22_PORT,      .u8Pin = CY_CAP0_DATA22_PIN,      .enMuxCfg = CY_CAP0_DATA22_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA23_PORT,      .u8Pin = CY_CAP0_DATA23_PIN,      .enMuxCfg = CY_CAP0_DATA23_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA24_PORT,      .u8Pin = CY_CAP0_DATA24_PIN,      .enMuxCfg = CY_CAP0_DATA24_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA25_PORT,      .u8Pin = CY_CAP0_DATA25_PIN,      .enMuxCfg = CY_CAP0_DATA25_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Capture0, .pstcPort = CY_CAP0_DATA26_PORT,      .u8Pin = CY_CAP0_DATA26_PIN,      .enMuxCfg = CY_CAP0_DATA26_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
#endif
//============================================================================================================================================================================================
#ifdef CY_BSP_HDR_SMIF0_AVAILABLE
  #ifdef CY_SMIF0_CLK_INV_PORT // inverted clock is not available on PSVP (and hence would not be defined in BSP header)
    { .enGroup = Smif0,    .pstcPort = CY_SMIF0_CLK_INV_PORT,    .u8Pin = CY_SMIF0_CLK_INV_PIN,    .enMuxCfg = CY_SMIF0_CLK_INV_PIN_MUX,    .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
  #endif
    { .enGroup = Smif0,    .pstcPort = CY_SMIF0_CLK_PORT,        .u8Pin = CY_SMIF0_CLK_PIN,        .enMuxCfg = CY_SMIF0_CLK_PIN_MUX,        .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif0,    .pstcPort = CY_SMIF0_RWDS_PORT,       .u8Pin = CY_SMIF0_RWDS_PIN,       .enMuxCfg = CY_SMIF0_RWDS_PIN_MUX,       .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif0,    .pstcPort = CY_SMIF0_SELECT0_PORT,    .u8Pin = CY_SMIF0_SELECT0_PIN,    .enMuxCfg = CY_SMIF0_SELECT0_PIN_MUX,    .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif0,    .pstcPort = CY_SMIF0_SELECT1_PORT,    .u8Pin = CY_SMIF0_SELECT1_PIN,    .enMuxCfg = CY_SMIF0_SELECT1_PIN_MUX,    .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif0,    .pstcPort = CY_SMIF0_DATA0_PORT,      .u8Pin = CY_SMIF0_DATA0_PIN,      .enMuxCfg = CY_SMIF0_DATA0_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif0,    .pstcPort = CY_SMIF0_DATA1_PORT,      .u8Pin = CY_SMIF0_DATA1_PIN,      .enMuxCfg = CY_SMIF0_DATA1_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif0,    .pstcPort = CY_SMIF0_DATA2_PORT,      .u8Pin = CY_SMIF0_DATA2_PIN,      .enMuxCfg = CY_SMIF0_DATA2_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif0,    .pstcPort = CY_SMIF0_DATA3_PORT,      .u8Pin = CY_SMIF0_DATA3_PIN,      .enMuxCfg = CY_SMIF0_DATA3_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif0,    .pstcPort = CY_SMIF0_DATA4_PORT,      .u8Pin = CY_SMIF0_DATA4_PIN,      .enMuxCfg = CY_SMIF0_DATA4_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif0,    .pstcPort = CY_SMIF0_DATA5_PORT,      .u8Pin = CY_SMIF0_DATA5_PIN,      .enMuxCfg = CY_SMIF0_DATA5_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif0,    .pstcPort = CY_SMIF0_DATA6_PORT,      .u8Pin = CY_SMIF0_DATA6_PIN,      .enMuxCfg = CY_SMIF0_DATA6_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif0,    .pstcPort = CY_SMIF0_DATA7_PORT,      .u8Pin = CY_SMIF0_DATA7_PIN,      .enMuxCfg = CY_SMIF0_DATA7_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
#endif
//============================================================================================================================================================================================
#ifdef CY_BSP_HDR_SMIF1_AVAILABLE
  #ifdef CY_SMIF1_CLK_INV_PORT // inverted clock is not available on PSVP (and hence would not be defined in BSP header)
    { .enGroup = Smif1,    .pstcPort = CY_SMIF1_CLK_INV_PORT,    .u8Pin = CY_SMIF1_CLK_INV_PIN,    .enMuxCfg = CY_SMIF1_CLK_INV_PIN_MUX,    .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
  #endif
    { .enGroup = Smif1,    .pstcPort = CY_SMIF1_CLK_PORT,        .u8Pin = CY_SMIF1_CLK_PIN,        .enMuxCfg = CY_SMIF1_CLK_PIN_MUX,        .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif1,    .pstcPort = CY_SMIF1_RWDS_PORT,       .u8Pin = CY_SMIF1_RWDS_PIN,       .enMuxCfg = CY_SMIF1_RWDS_PIN_MUX,       .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif1,    .pstcPort = CY_SMIF1_SELECT0_PORT,    .u8Pin = CY_SMIF1_SELECT0_PIN,    .enMuxCfg = CY_SMIF1_SELECT0_PIN_MUX,    .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif1,    .pstcPort = CY_SMIF1_SELECT1_PORT,    .u8Pin = CY_SMIF1_SELECT1_PIN,    .enMuxCfg = CY_SMIF1_SELECT1_PIN_MUX,    .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif1,    .pstcPort = CY_SMIF1_DATA0_PORT,      .u8Pin = CY_SMIF1_DATA0_PIN,      .enMuxCfg = CY_SMIF1_DATA0_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif1,    .pstcPort = CY_SMIF1_DATA1_PORT,      .u8Pin = CY_SMIF1_DATA1_PIN,      .enMuxCfg = CY_SMIF1_DATA1_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif1,    .pstcPort = CY_SMIF1_DATA2_PORT,      .u8Pin = CY_SMIF1_DATA2_PIN,      .enMuxCfg = CY_SMIF1_DATA2_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif1,    .pstcPort = CY_SMIF1_DATA3_PORT,      .u8Pin = CY_SMIF1_DATA3_PIN,      .enMuxCfg = CY_SMIF1_DATA3_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif1,    .pstcPort = CY_SMIF1_DATA4_PORT,      .u8Pin = CY_SMIF1_DATA4_PIN,      .enMuxCfg = CY_SMIF1_DATA4_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif1,    .pstcPort = CY_SMIF1_DATA5_PORT,      .u8Pin = CY_SMIF1_DATA5_PIN,      .enMuxCfg = CY_SMIF1_DATA5_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif1,    .pstcPort = CY_SMIF1_DATA6_PORT,      .u8Pin = CY_SMIF1_DATA6_PIN,      .enMuxCfg = CY_SMIF1_DATA6_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
    { .enGroup = Smif1,    .pstcPort = CY_SMIF1_DATA7_PORT,      .u8Pin = CY_SMIF1_DATA7_PIN,      .enMuxCfg = CY_SMIF1_DATA7_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 0 },
#endif
//============================================================================================================================================================================================
  #ifdef CY_BL_DISP0_EN_PORT
    { .enGroup = BlDisp0,  .pstcPort = CY_BL_DISP0_EN_PORT,      .u8Pin = CY_BL_DISP0_EN_PIN,      .enMuxCfg = CY_BL_DISP0_EN_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 1 }, // NA
  #endif
  #ifdef CY_BL_DISP0_PWM_PORT
    { .enGroup = BlDisp0,  .pstcPort = CY_BL_DISP0_PWM_PORT,     .u8Pin = CY_BL_DISP0_PWM_PIN,     .enMuxCfg = CY_BL_DISP0_PWM_PIN_MUX,     .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 1 },
  #endif
  #ifdef CY_FPDLINK0_BL_EN_PORT
    { .enGroup = BlFpd0,   .pstcPort = CY_FPDLINK0_BL_EN_PORT,   .u8Pin = CY_FPDLINK0_BL_EN_PIN,   .enMuxCfg = CY_FPDLINK0_BL_EN_PIN_MUX,   .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 1 },
  #endif
  #ifdef CY_FPDLINK0_BL_PWM_PORT
    { .enGroup = BlFpd0,   .pstcPort = CY_FPDLINK0_BL_PWM_PORT,  .u8Pin = CY_FPDLINK0_BL_PWM_PIN,  .enMuxCfg = CY_FPDLINK0_BL_PWM_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 1 },
  #endif
//============================================================================================================================================================================================
  #ifdef CY_BL_DISP1_EN_PORT
    { .enGroup = BlDisp1,  .pstcPort = CY_BL_DISP1_EN_PORT,      .u8Pin = CY_BL_DISP1_EN_PIN,      .enMuxCfg = CY_BL_DISP1_EN_PIN_MUX,      .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 1 }, // NA
  #endif
  #ifdef CY_BL_DISP1_PWM_PORT
    { .enGroup = BlDisp1,  .pstcPort = CY_BL_DISP1_PWM_PORT,     .u8Pin = CY_BL_DISP1_PWM_PIN,     .enMuxCfg = CY_BL_DISP1_PWM_PIN_MUX,     .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 1 },
  #endif
  #ifdef CY_FPDLINK1_BL_EN_PORT
    { .enGroup = BlFpd1,   .pstcPort = CY_FPDLINK1_BL_EN_PORT,   .u8Pin = CY_FPDLINK1_BL_EN_PIN,   .enMuxCfg = CY_FPDLINK1_BL_EN_PIN_MUX,   .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 1 },
  #endif
  #ifdef CY_FPDLINK1_BL_PWM_PORT
    { .enGroup = BlFpd1,   .pstcPort = CY_FPDLINK1_BL_PWM_PORT,  .u8Pin = CY_FPDLINK1_BL_PWM_PIN,  .enMuxCfg = CY_FPDLINK1_BL_PWM_PIN_MUX,  .u8DriveMode = CY_GPIO_DM_STRONG, .u8GpioOutVal = 1 },
  #endif
//============================================================================================================================================================================================
#if (CY_USE_PSVP == 0)  // --> Button availability may differ depending on used target board, so check whether button is defined in BSP header
  #ifdef CY_USER_BUTTON_WAKE_PORT
    { .enGroup = Button,   .pstcPort = CY_USER_BUTTON_WAKE_PORT, .u8Pin = CY_USER_BUTTON_WAKE_PIN, .enMuxCfg = CY_USER_BUTTON_WAKE_PIN_MUX, .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
  #endif
  #ifdef CY_USER_BUTTON_LEFT_PORT
    { .enGroup = Button,   .pstcPort = CY_USER_BUTTON_LEFT_PORT, .u8Pin = CY_USER_BUTTON_LEFT_PIN, .enMuxCfg = CY_USER_BUTTON_LEFT_PIN_MUX, .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
  #endif
  #ifdef CY_USER_BUTTON_RIGHT_PORT
    { .enGroup = Button,   .pstcPort = CY_USER_BUTTON_RIGHT_PORT,.u8Pin = CY_USER_BUTTON_RIGHT_PIN,.enMuxCfg = CY_USER_BUTTON_RIGHT_PIN_MUX,.u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
  #endif
  #ifdef CY_USER_BUTTON_UP_PORT
    { .enGroup = Button,   .pstcPort = CY_USER_BUTTON_UP_PORT,   .u8Pin = CY_USER_BUTTON_UP_PIN,   .enMuxCfg = CY_USER_BUTTON_UP_PIN_MUX,   .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
  #endif
  #ifdef CY_USER_BUTTON_DOWN_PORT
    { .enGroup = Button,   .pstcPort = CY_USER_BUTTON_DOWN_PORT, .u8Pin = CY_USER_BUTTON_DOWN_PIN, .enMuxCfg = CY_USER_BUTTON_DOWN_PIN_MUX, .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
  #endif
#else
    { .enGroup = Button,   .pstcPort = CY_AB_BUTTON_PORT,        .u8Pin = CY_AB_BUTTON_PIN,        .enMuxCfg = CY_AB_BUTTON_PIN_MUX,        .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Button,   .pstcPort = CY_CEB_BUTTON_PORT,       .u8Pin = CY_CEB_BUTTON_PIN,       .enMuxCfg = CY_CEB_BUTTON_PIN_MUX,       .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Button,   .pstcPort = CY_BUTTON1_PORT,          .u8Pin = CY_BUTTON1_PIN,          .enMuxCfg = CY_BUTTON1_PIN_MUX,          .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Button,   .pstcPort = CY_BUTTON2_PORT,          .u8Pin = CY_BUTTON2_PIN,          .enMuxCfg = CY_BUTTON2_PIN_MUX,          .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Button,   .pstcPort = CY_BUTTON3_PORT,          .u8Pin = CY_BUTTON3_PIN,          .enMuxCfg = CY_BUTTON3_PIN_MUX,          .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Button,   .pstcPort = CY_BUTTON4_PORT,          .u8Pin = CY_BUTTON4_PIN,          .enMuxCfg = CY_BUTTON4_PIN_MUX,          .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
    { .enGroup = Button,   .pstcPort = CY_BUTTON5_PORT,          .u8Pin = CY_BUTTON5_PIN,          .enMuxCfg = CY_BUTTON5_PIN_MUX,          .u8DriveMode = CY_GPIO_DM_HIGHZ,  .u8GpioOutVal = 0 },
#endif
//============================================================================================================================================================================================
};

/*****************************************************************************
 ** \brief Button definition
 *****************************************************************************/
static const cy_button_stc_definition_t m_astcButtonDef[] =
{
#if (CY_USE_PSVP == 0)  // --> Button availability may differ depending on used target board, so check whether button is defined in BSP header
  #ifdef CY_USER_BUTTON_WAKE_PORT
    { .pstcPort = CY_USER_BUTTON_WAKE_PORT,     .u8Pin = CY_USER_BUTTON_WAKE_PIN,       .u8ButtonId = CY_GFXENV_BUTTON_ID_WAKE  },
  #endif
  #ifdef CY_USER_BUTTON_LEFT_PORT
    { .pstcPort = CY_USER_BUTTON_LEFT_PORT,     .u8Pin = CY_USER_BUTTON_LEFT_PIN,       .u8ButtonId = CY_GFXENV_BUTTON_ID_LEFT  },
  #endif
  #ifdef CY_USER_BUTTON_RIGHT_PORT
    { .pstcPort = CY_USER_BUTTON_RIGHT_PORT,    .u8Pin = CY_USER_BUTTON_RIGHT_PIN,      .u8ButtonId = CY_GFXENV_BUTTON_ID_RIGHT },
  #endif
  #ifdef CY_USER_BUTTON_UP_PORT
    { .pstcPort = CY_USER_BUTTON_UP_PORT,       .u8Pin = CY_USER_BUTTON_UP_PIN,         .u8ButtonId = CY_GFXENV_BUTTON_ID_UP    },
  #endif
  #ifdef CY_USER_BUTTON_DOWN_PORT
    { .pstcPort = CY_USER_BUTTON_DOWN_PORT,     .u8Pin = CY_USER_BUTTON_DOWN_PIN,       .u8ButtonId = CY_GFXENV_BUTTON_ID_DOWN  },
  #endif
#else
    { .pstcPort = CY_AB_BUTTON_PORT,            .u8Pin = CY_AB_BUTTON_PIN,              .u8ButtonId = CY_GFXENV_BUTTON_ID_AB_CB },
    { .pstcPort = CY_CEB_BUTTON_PORT,           .u8Pin = CY_CEB_BUTTON_PIN,             .u8ButtonId = CY_GFXENV_BUTTON_ID_CEB   },
    { .pstcPort = CY_BUTTON1_PORT,              .u8Pin = CY_BUTTON1_PIN,                .u8ButtonId = CY_GFXENV_BUTTON_ID_BB_1  },
    { .pstcPort = CY_BUTTON2_PORT,              .u8Pin = CY_BUTTON2_PIN,                .u8ButtonId = CY_GFXENV_BUTTON_ID_BB_2  },
    { .pstcPort = CY_BUTTON3_PORT,              .u8Pin = CY_BUTTON3_PIN,                .u8ButtonId = CY_GFXENV_BUTTON_ID_BB_3  },
    { .pstcPort = CY_BUTTON4_PORT,              .u8Pin = CY_BUTTON4_PIN,                .u8ButtonId = CY_GFXENV_BUTTON_ID_BB_4  },
    { .pstcPort = CY_BUTTON5_PORT,              .u8Pin = CY_BUTTON5_PIN,                .u8ButtonId = CY_GFXENV_BUTTON_ID_BB_5  },
#endif
};


/*****************************************************************************
 ** \brief Hold GfxEnv driver internal config/status of all SMIFs and SMIF_DEVICEs
 *****************************************************************************/
static stc_smif_cfg_internal_t m_astcSmifIntCfg[CY_GFXENV_NR_OF_SMIF];

/*****************************************************************************
 ** \brief Returns the corresponding HF clock when indexed by the SMIF instance number
 *****************************************************************************/
#if (CY_USE_PSVP == 0)
static const cy_en_hfclk_t  m_aenLutSmifInstanceToHfClock[CY_GFXENV_NR_OF_SMIF] = { 
                                                                                    #if CY_GFXENV_NR_OF_SMIF >= 1
                                                                                      CY_SYSCLK_HFCLK_8,
                                                                                    #endif
                                                                                    #if CY_GFXENV_NR_OF_SMIF >= 2
                                                                                      CY_SYSCLK_HFCLK_9,
                                                                                    #endif
                                                                                  };
#endif

/*****************************************************************************
 ** \brief Generic SMIF configuration
 *****************************************************************************/
static const cy_stc_smif_config_t m_stcGenericSmifCfg =
{
    .txClk         = CY_SMIF_INV_FOR_DDR,
    .rxClk         = CY_SMIF_INV_RWDS,
    .dlpAuto       = CY_SMIF_DLP_UPDATE_MANUAL,
    .capDelay      = CY_SMIF_CAPTURE_DELAY_0_CYCLE,
    .delaySel      = CY_SMIF_1_SEN_SEL_PER_TAP,
    .deselectDelay = CY_SMIF_MIN_DESELECT_2_CLK,     // Should work at max. freq for any S26K/S26H/S27K device type (though it might not be optimal for slower frequencies)
    .setupDelay    = CY_SMIF_SETUP_1_CLK_PULUS_MIN,  // Should work at max. freq for any S26K/S26H/S27K device type (though it might not be optimal for slower frequencies)
    .holdDelay     = CY_SMIF_HOLD_1_CLK_PULUS_MIN,   // Should work at max. freq for any S26K/S26H/S27K device type (though it might not be optimal for slower frequencies)
    .mode          = CY_SMIF_MEMORY,
    .blockEvent    = CY_SMIF_BUS_ERROR,
};

/*****************************************************************************
 ** \brief Generic SMIF HyperFlash Device Configuration
 *****************************************************************************/
static cy_stc_device_hb_config_t m_stcSmifDevHyperFlashCfg =
{
    .xipReadCmd         = CY_SMIF_HB_READ_CONTINUOUS_BURST,
    .xipWriteCmd        = CY_SMIF_HB_WRITE_CONTINUOUS_BURST,
    .mergeEnable        = true,
    .mergeTimeout       = CY_SMIF_MER_TIMEOUT_4096_CYCLE,
    .totalTimeoutEnable = false,                             // HyperFlash does not have a total timeout constraint
    .totalTimeout       = 0,
    .addr               = 0,                                 // <- updated during runtime as per user configuration!
    .size               = CY_SMIF_DEVICE_64M_BYTE,           // <- updated during runtime as per user configuration!
    .lc_hb              = GFXENV_HYPERFLASH_INITIAL_LATENCY, // <- updated during runtime for optimal value
    .hbDevType          = CY_SMIF_HB_FLASH,
};

/*****************************************************************************
 ** \brief Generic SMIF HyperRam Device Configuration
 *****************************************************************************/
static cy_stc_device_hb_config_t m_stcSmifDevHyperRamCfg =
{
    .xipReadCmd         = CY_SMIF_HB_READ_CONTINUOUS_BURST,
    .xipWriteCmd        = CY_SMIF_HB_WRITE_CONTINUOUS_BURST,
    .mergeEnable        = true,
    .mergeTimeout       = CY_SMIF_MER_TIMEOUT_256_CYCLE,
    .totalTimeoutEnable = true,                            // HyperRAM has a total timeout constraint based on the maximum CS low time according its datasheet
    .totalTimeout       = 0,                               // <- updated during runtime for optimal value
    .addr               = 0,                               // <- updated during runtime as per user configuration!
    .size               = CY_SMIF_DEVICE_8M_BYTE,          // <- updated during runtime as per user configuration!
    .lc_hb              = GFXENV_HYPERRAM_INITIAL_LATENCY, // <- updated during runtime for optimal value
    .hbDevType          = CY_SMIF_HB_SRAM,
};

/*****************************************************************************
 ** \brief Global MPU Control Bit Settings during SMIF initialization
 *****************************************************************************/
static cy_stc_mpu_global_ctrl_bits_t m_stcMpuGlobalCtrlBits =
{
    .mpuGlobalEnable = CY_MPU_GLOBAL_ENABLE,
    .privDefMapEn    = CY_MPU_USE_DEFAULT_MAP_AS_BG,
    .faultNmiEn      = CY_MPU_ENABLED_DURING_FAULT_NMI,
};
static cy_stc_mpu_global_ctrl_bits_t m_stcMpuGlobalCtrlBitsBackup;

/*****************************************************************************
 ** \brief MPU Region Settings during SMIF initialization
 *****************************************************************************/
static cy_stc_mpu_region_cfg_t m_stcSmifMpuRegion =
{
    .addr         = 0,               // Region will cover 0x60000000 - 0x9fffffff
    .size         = CY_MPU_SIZE_4GB, // Region will cover 0x60000000 - 0x9fffffff
    .srd          = 0xe7,            // Region will cover 0x60000000 - 0x9fffffff
    .permission   = CY_MPU_ACCESS_P_FULL_ACCESS,
    .attribute    = CY_MPU_ATTR_SHR_DEV,
    .execute      = CY_MPU_INST_ACCESS_EN,
    .enable       = CY_MPU_ENABLE,
};
static cy_stc_mpu_region_cfg_t m_stcSmifMpuRegionBackup;


/*****************************************************************************
* Local function prototypes ('static')
*****************************************************************************/
static void                   InitPortPins              (const cy_gfxenv_stc_init_portpins_t * pstcPortInitCfg);
#if (CY_USE_PSVP == 0)
static cy_gfxenv_en_result_t  ChangeSmifExtClock        (uint8_t u8SmifExtClkMhz);
#endif
static cy_gfxenv_en_result_t  InitExtMem                (const cy_gfxenv_stc_init_extmem_t * pstcExtMemCfg);
static cy_gfxenv_en_result_t  InitSmifAtSafeFreq        (stc_smif_cfg_internal_t *        pstcSmifIntCfg, const cy_gfxenv_stc_smif_cfg_t *        pstcSmifUsrCfg);
static cy_gfxenv_en_result_t  InitSmifDeviceAtSafeFreq  (stc_smif_device_cfg_internal_t * pstcDevIntCfg,  const cy_gfxenv_stc_smif_device_cfg_t * pstcDevUsrCfg);
#if (CY_USE_PSVP == 0)
static cy_gfxenv_en_result_t  InitSmifAtTargetFreq      (stc_smif_cfg_internal_t *        pstcSmifIntCfg, const cy_gfxenv_stc_smif_cfg_t *        pstcSmifUsrCfg);
static cy_gfxenv_en_result_t  InitSmifDeviceAtTargetFreq(stc_smif_device_cfg_internal_t * pstcDevIntCfg,  const cy_gfxenv_stc_smif_device_cfg_t * pstcDevUsrCfg);
#endif
static cy_gfxenv_en_result_t  ConfigureHyperFlash       (stc_smif_device_cfg_internal_t * pstcDevIntCfg,  const cy_gfxenv_stc_smif_device_cfg_t * pstcDevUsrCfg);
static cy_gfxenv_en_result_t  ConfigureHyperRam         (stc_smif_device_cfg_internal_t * pstcDevIntCfg,  const cy_gfxenv_stc_smif_device_cfg_t * pstcDevUsrCfg);


/*****************************************************************************
* Function implementation - global ('extern') and local ('static')
*****************************************************************************/

/*******************************************************************************
* Function Name: Cy_GfxEnv_Init
****************************************************************************//**
*
* \brief  Initializes the GFX environment
*
* \param  pstcGfxEnvCfg : The pointer to the init configuration struct
*
* \return cy_gfxenv_en_result_t
*
*******************************************************************************/
cy_gfxenv_en_result_t Cy_GfxEnv_Init(const cy_gfxenv_stc_cfg_t *pstcGfxEnvCfg)
{
    // Initialize port pins if requested by user configuration
    if(pstcGfxEnvCfg->pstcInitPortPins != NULL)
    {
        InitPortPins(pstcGfxEnvCfg->pstcInitPortPins);
    }

    // Initialize software timer module if requested by user configuration
    if(pstcGfxEnvCfg->bInitSwTimer != false)
    {
        Cy_SwTmr_Init();
    }

    // Initialize semihosting (low level I/O) together with required clock and port pin setup if requested by user configuration
    if(pstcGfxEnvCfg->bInitSemihosting != false)
    {
        if(Cy_Semihosting_InitAll(CY_GFXENV_SEMIHOSTING_SCB, 115200UL, CY_GFXENV_SEMIHOSTING_WDG_HANDLER, false) != CY_SEMIHOSTING_SUCCESS)
        {
            return CY_GFXENV_ERROR;
        }
    }

    // Initialize button module if requested by user configuration
    if(pstcGfxEnvCfg->pstcInitButtons != NULL)
    {
        cy_gfxenv_stc_init_buttons_t * pstcCfg = pstcGfxEnvCfg->pstcInitButtons;

        if(Cy_Button_Init(&m_astcButtonDef[0], CY_GET_ARRAY_LEN(m_astcButtonDef), pstcCfg->pfnCallback, pstcCfg->u8CySwTimerId) != CY_BUTTON_SUCCESS)
        {
            return CY_GFXENV_ERROR;
        }
    }

    // Initialize external memories if requested by user configuration
    if(pstcGfxEnvCfg->pstcInitExtMem != NULL)
    {
        cy_gfxenv_en_result_t enExtMemInitRetVal;

        // Temporarily configure an MPU region to make SMIF XIP address space "Device Shareable"
        // which is needed for reliable access of I/O registers in HyperBus memories
        if(pstcGfxEnvCfg->pstcInitExtMem->bInitMpuTemporarily != false)
        {
            Cy_MPU_GetGlobalControlBits(&m_stcMpuGlobalCtrlBitsBackup);
            Cy_MPU_Disable();
            Cy_MPU_GetRegion(&m_stcSmifMpuRegionBackup, pstcGfxEnvCfg->pstcInitExtMem->u8MpuRegionTemp);
            Cy_MPU_SetRegion(&m_stcSmifMpuRegion,       pstcGfxEnvCfg->pstcInitExtMem->u8MpuRegionTemp);
            Cy_MPU_SetGlobalControlBits(&m_stcMpuGlobalCtrlBits);
        }

        enExtMemInitRetVal = InitExtMem(pstcGfxEnvCfg->pstcInitExtMem);

        // Restore MPU Settings
        if(pstcGfxEnvCfg->pstcInitExtMem->bInitMpuTemporarily != false)
        {
            Cy_MPU_Disable();
            Cy_MPU_SetRegion(&m_stcSmifMpuRegionBackup, pstcGfxEnvCfg->pstcInitExtMem->u8MpuRegionTemp);
            Cy_MPU_SetGlobalControlBits(&m_stcMpuGlobalCtrlBitsBackup);
        }

        if(enExtMemInitRetVal != CY_GFXENV_SUCCESS)
        {
            return enExtMemInitRetVal;
        }
    }

    return CY_GFXENV_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_GfxEnv_FastInit
****************************************************************************//**
*
* \brief  Initializes the GFX environment with most commonly used settings.
*         Only a limited number of parameters can be configured, e.g.
*         whether SMIF instances and connected memories are initialized
*         because this would stuck execution if memory is not connected or in
*         case of signal problems.
*
* \warning u8Smif0ExtClockMhz and u8Smif1ExtClockMhz ratio needs to be 1, 2, 4 or 8 
*          (or 1, 0.5, 0.25, 0.125 respectively) at the moment, because by default
*          the SMIF HF clocks use the same source PLL and hence only the HF clock
*          dividers can be used
*
* \param  u8Smif0ExtClockMhz : SMIF0 external clock frequency,
*                              if value == 0, SMIF0 will not be initialized
* \param  u8Smif1ExtClockMhz : SMIF1 external clock frequency,
*                              if value == 0, SMIF1 will not be initialized
* \param  pfnButtonCallback  : Callback from button handler, can be NULL (then
*                              button driver and port pins are not initialized)
*
* \return cy_gfxenv_en_result_t
*
*******************************************************************************/
cy_gfxenv_en_result_t Cy_GfxEnv_FastInit(uint8_t u8Smif0ExtClockMhz, uint8_t u8Smif1ExtClockMhz, cy_button_callback_t pfnButtonCallback)
{
    cy_gfxenv_stc_cfg_t stcGfxEnvCfg =
    {
        .bInitSwTimer         = true,
        .bInitSemihosting     = true,
        .pstcInitPortPins     = &(cy_gfxenv_stc_init_portpins_t)
                                {
                                  #if (CY_USE_PSVP == 0)
                                    .bInitDisplay0Ttl       = false, // usually the FPD-Link is used on silicon
                                  #else
                                    .bInitDisplay0Ttl       = true,  // FPD-Link #0 is not available on PSVP
                                  #endif
                                  #if (CY_USE_PSVP == 0) && defined(VIDEOSS0_FPDLINK1)
                                    .bInitDisplay1Ttl       = false, // usually the FPD-Link is used on silicon (if it is available)
                                  #else
                                    .bInitDisplay1Ttl       = true,  // FPD-Link #1 is not available on PSVP or on silicon for this device
                                  #endif
                                    .bInitCapture0Ttl       = false,
                                    .bInitSmif0             = true,  // might be overriden by function parameter u8Smif0ExtClockMhz
                                    .bInitSmif1             = true,  // might be overriden by function parameter u8Smif1ExtClockMhz
                                    .bInitBacklightDisp0    = false, // backlights are enabled by jumper setting on CY boards, would only be needed for PWM dimming
                                    .bInitBacklightDisp1    = false, // backlights are enabled by jumper setting on CY boards, would only be needed for PWM dimming
                                    .bInitBacklightFpdLink0 = false, // backlights are enabled by jumper setting on CY boards, would only be needed for PWM dimming
                                    .bInitBacklightFpdLink1 = false, // backlights are enabled by jumper setting on CY boards, would only be needed for PWM dimming
                                    .bInitButtonGpios       = true,
                                },
        .pstcInitExtMem       = &(cy_gfxenv_stc_init_extmem_t)
                                {
                                    .bInitMpuTemporarily = true,
                                    .u8MpuRegionTemp     = CY_GFXENV_SMIF_TEMP_MPU_REGION,
                                    .apstcInitSmif       = {
                                                                &(cy_gfxenv_stc_smif_cfg_t)
                                                                {
                                                                    .u8SmifExtClockMhz = 0, // updated by function parameter
                                                                    .apstcDevUsrCfg    = {
                                                                                             &(cy_gfxenv_stc_smif_device_cfg_t)
                                                                                             {
                                                                                                 .u32BaseAddress           = 0x60000000,
                                                                                                 .u16SizeMegaBytes         = 64,
                                                                                                 .enExtMemType             = CY_SMIF_HB_MEMTYPE_HYPERFLASH_S26H,
                                                                                                 .i32CalibrationDataOffset = -16, // use last 16 byte of memory
                                                                                                 .bEraseIfNecessary        = true,
                                                                                               #if defined(tviic2d6m) || defined(tviic2d6mddr)
                                                                                                 .bUseDifferentialClock    = true,
                                                                                               #elif defined(tviic2d4m)
                                                                                                 .bUseDifferentialClock    = false,
                                                                                               #endif
                                                                                             },
                                                                                             NULL,/*&(cy_gfxenv_stc_smif_device_cfg_t)
                                                                                             {
                                                                                                 .u32BaseAddress           = 0x70000000,
                                                                                                 .u16SizeMegaBytes         = 8,
                                                                                                 .enExtMemType             = CY_SMIF_HB_MEMTYPE_HYPERRAM_S27KXXXX2,
                                                                                                 .i32CalibrationDataOffset = 0,
                                                                                                 .bEraseIfNecessary        = false, // don't care for RAM
                                                                                               #if defined(tviic2d6m) || defined(tviic2d6mddr)
                                                                                                 .bUseDifferentialClock    = true,
                                                                                               #elif defined(tviic2d4m)
                                                                                                 .bUseDifferentialClock    = false,
                                                                                               #endif
                                                                                             },*/
                                                                                         },
                                                                }, 
                                                                &(cy_gfxenv_stc_smif_cfg_t)
                                                                {
                                                                    .u8SmifExtClockMhz = 0, // updated by function parameter
                                                                    .apstcDevUsrCfg    = {
                                                                                             NULL,/*&(cy_gfxenv_stc_smif_device_cfg_t)
                                                                                             {
                                                                                                 .u32BaseAddress           = 0x80000000,
                                                                                                 .u16SizeMegaBytes         = 64,
                                                                                                 .enExtMemType             = CY_SMIF_HB_MEMTYPE_HYPERFLASH_S26H,
                                                                                                 .i32CalibrationDataOffset = 0,
                                                                                                 .bEraseIfNecessary        = true,
                                                                                               #if defined(tviic2d6m) || defined(tviic2d6mddr)
                                                                                                 .bUseDifferentialClock    = true,
                                                                                               #elif defined(tviic2d4m)
                                                                                                 .bUseDifferentialClock    = false,
                                                                                               #endif
                                                                                             },*/
                                                                                             &(cy_gfxenv_stc_smif_device_cfg_t)
                                                                                             {
                                                                                                 .u32BaseAddress           = 0x90000000,
                                                                                                 .u16SizeMegaBytes         = 8,
                                                                                                 .enExtMemType             = CY_SMIF_HB_MEMTYPE_HYPERRAM_S27KXXXX2,
                                                                                                 .i32CalibrationDataOffset = -16, // use last 16 byte of memory
                                                                                                 .bEraseIfNecessary        = false, // don't care for RAM
                                                                                               #if defined(tviic2d6m) || defined(tviic2d6mddr)
                                                                                                 .bUseDifferentialClock    = true,
                                                                                               #elif defined(tviic2d4m)
                                                                                                 .bUseDifferentialClock    = false,
                                                                                               #endif
                                                                                             },
                                                                                         },
                                                                },
                                                            },
                                },
        .pstcInitButtons      = &(cy_gfxenv_stc_init_buttons_t)
                                {
                                    .u8CySwTimerId = (CY_SWTMR_MAX_TIMERS - 1), // use last timer
                                    .pfnCallback   = NULL,
                                },

    };

    // Disable SMIF clock, port and memory initialization if not requested by user, otherwise update the frequency with value from user
    if(u8Smif0ExtClockMhz == 0)
    {
        stcGfxEnvCfg.pstcInitPortPins->bInitSmif0 = false;
        stcGfxEnvCfg.pstcInitExtMem->apstcInitSmif[0] = NULL;
    }
    else
    {
        stcGfxEnvCfg.pstcInitExtMem->apstcInitSmif[0]->u8SmifExtClockMhz = u8Smif0ExtClockMhz;
    }
    if(u8Smif1ExtClockMhz == 0)
    {
        stcGfxEnvCfg.pstcInitPortPins->bInitSmif1 = false;
        stcGfxEnvCfg.pstcInitExtMem->apstcInitSmif[1] = NULL;
    }    
    else
    {
        stcGfxEnvCfg.pstcInitExtMem->apstcInitSmif[1]->u8SmifExtClockMhz = u8Smif1ExtClockMhz;
    }
    if((u8Smif0ExtClockMhz == 0) && (u8Smif1ExtClockMhz == 0))
    {
        stcGfxEnvCfg.pstcInitExtMem = NULL;
    }

    // Disable button driver and corresponding port pin initialization if user does not provide callback
    if(pfnButtonCallback == NULL)
    {
        stcGfxEnvCfg.pstcInitButtons = NULL;
    }
    else
    {
        stcGfxEnvCfg.pstcInitButtons->pfnCallback = pfnButtonCallback;
    }

    return Cy_GfxEnv_Init(&stcGfxEnvCfg);
}


/*******************************************************************************
* Function Name: Cy_GfxEnv_EnableTestImage
****************************************************************************//**
*
* \brief  Enables the output of test images on the 2 display links.
*         Prior initialization (e.g. Cy_GfxEnv_Init or Cy_GfxEnv_FastInit APIs)
*         may be necessary before calling this function.
*
* \param  enDisp0Type : The display type to be setup for display link #0
* \param  enDisp1Type : The display type to be setup for display link #1
*
* \return cy_gfxenv_en_result_t
*
*******************************************************************************/
cy_gfxenv_en_result_t Cy_GfxEnv_EnableTestImage(cy_gfxenv_en_disp_type_t enDisp0Type, cy_gfxenv_en_disp_type_t enDisp1Type)
{
    cy_gfxenv_en_result_t enRetVal = CY_GFXENV_SUCCESS;
    uint8_t u8Disp0ClkPllDiv;
    uint8_t u8Disp1ClkPllDiv;

  #ifdef CYREG_VIDEOSS0_VIDEOSSCFG_DSP0_CTL
    // Set global Enable bit for DSP0 domain
    VIDEOSS0_SUBSS0_VIDEOSSCFG->unDSP0_CTL.stcField.u1DSP0_ENABLED = 1;
  #endif
  #ifdef CYREG_VIDEOSS0_VIDEOSSCFG_DSP1_CTL
    // Set global Enable bit for DSP1 domain
    VIDEOSS0_SUBSS0_VIDEOSSCFG->unDSP1_CTL.stcField.u1DSP1_ENABLED = 1;
  #endif    


  #if (CY_USE_PSVP == 0)

    cy_en_sysclk_status_t enSysClkRetVal;
    uint32_t u32Disp0PixelClkHz;
    uint32_t u32Disp1PixelClkHz;
    uint32_t u32Disp0ClkPllHz;
    uint32_t u32Disp1ClkPllHz;
    uint32_t disp0PllInputFreq;
    uint32_t disp1PllInputFreq;

    if((enDisp0Type == CY_GFXENV_DISP_TYPE_NONE) && (enDisp1Type == CY_GFXENV_DISP_TYPE_NONE))
    {
        return CY_GFXENV_ERROR_BAD_PARAM; // at least one display must be selected
    }

    if(enDisp0Type != CY_GFXENV_DISP_TYPE_NONE)
    {

        u32Disp0PixelClkHz = (uint32_t) m_astcDispPresets[enDisp0Type].u16HorizontalTotal *
                             (uint32_t) m_astcDispPresets[enDisp0Type].u16VerticalTotal   *
                             (uint32_t) m_astcDispPresets[enDisp0Type].u8RefreshRateHz;

        // Search the necessary PLL frequency and divider
        for(u8Disp0ClkPllDiv = 1; u8Disp0ClkPllDiv <= 8; u8Disp0ClkPllDiv *= 2)
        {
            u32Disp0ClkPllHz = u32Disp0PixelClkHz * VIDEOSS_FIXED_DISP_CLK_DIV * u8Disp0ClkPllDiv;
            if((u32Disp0ClkPllHz >= DISP0_CLK_PLL_MIN_HZ) && (u32Disp0ClkPllHz <= DISP0_CLK_PLL_MAX_HZ))
            {
                break;
            }
        }

        if(u8Disp0ClkPllDiv > 8)
        {
            return CY_GFXENV_ERROR_BAD_PARAM; // suitable divider not found
        }

        enSysClkRetVal = Cy_SysClk_Pll400MDisable(CLK_PATH_DISP0_CLK);
        CY_ASSERT(enSysClkRetVal == CY_SYSCLK_SUCCESS);
        enSysClkRetVal = Cy_SysClk_GetPllInputFrequency(CLK_PATH_DISP0_CLK - 1, &disp0PllInputFreq);
        CY_ASSERT(enSysClkRetVal == CY_SYSCLK_SUCCESS);

        cy_stc_pll_400M_config_t stcPllCfg =
        {
            .inputFreq    = disp0PllInputFreq,
            .outputFreq   = u32Disp0ClkPllHz,
            .outputMode   = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
            .fracEn       = true,
            .fracDitherEn = true,
            .sscgEn       = true,
            .sscgDitherEn = true,
            .sscgDepth    = CY_SYSCLK_SSCG_DEPTH_MINUS_2_0,
            .sscgRate     = CY_SYSCLK_SSCG_RATE_DIV_512,
        };
        enSysClkRetVal = Cy_SysClk_Pll400MConfigure(CLK_PATH_DISP0_CLK, &stcPllCfg);
        CY_ASSERT(enSysClkRetVal == CY_SYSCLK_SUCCESS);
        enSysClkRetVal = Cy_SysClk_Pll400MEnable(CLK_PATH_DISP0_CLK, 10000);
        CY_ASSERT(enSysClkRetVal == CY_SYSCLK_SUCCESS);
    }

    if(enDisp1Type != CY_GFXENV_DISP_TYPE_NONE)
    {

        u32Disp1PixelClkHz = (uint32_t) m_astcDispPresets[enDisp1Type].u16HorizontalTotal *
                             (uint32_t) m_astcDispPresets[enDisp1Type].u16VerticalTotal   *
                             (uint32_t) m_astcDispPresets[enDisp1Type].u8RefreshRateHz;

        // Search the necessary PLL frequency and divider
        for(u8Disp1ClkPllDiv = 1; u8Disp1ClkPllDiv <= 8; u8Disp1ClkPllDiv *= 2)
        {
            u32Disp1ClkPllHz = u32Disp1PixelClkHz * VIDEOSS_FIXED_DISP_CLK_DIV * u8Disp1ClkPllDiv;
            if((u32Disp1ClkPllHz >= DISP1_CLK_PLL_MIN_HZ) && (u32Disp1ClkPllHz <= DISP1_CLK_PLL_MAX_HZ))
            {
                break;
            }
        }

        if(u8Disp1ClkPllDiv > 8)
        {
            return CY_GFXENV_ERROR_BAD_PARAM; // suitable divider not found
        }

        enSysClkRetVal = Cy_SysClk_PllDisable(CLK_PATH_DISP1_CLK);
        CY_ASSERT(enSysClkRetVal == CY_SYSCLK_SUCCESS);
        enSysClkRetVal = Cy_SysClk_GetPllInputFrequency(CLK_PATH_DISP1_CLK - 1, &disp1PllInputFreq);
        CY_ASSERT(enSysClkRetVal == CY_SYSCLK_SUCCESS);

        cy_stc_pll_config_t stcPllCfg =
        {
            .inputFreq    = disp1PllInputFreq,
            .outputFreq   = u32Disp1ClkPllHz,
            .outputMode   = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
            .lfMode       = false,
        };
        enSysClkRetVal = Cy_SysClk_PllConfigure(CLK_PATH_DISP1_CLK, &stcPllCfg);
        CY_ASSERT(enSysClkRetVal == CY_SYSCLK_SUCCESS);
        enSysClkRetVal = Cy_SysClk_PllEnable(CLK_PATH_DISP1_CLK, 10000);
        CY_ASSERT(enSysClkRetVal == CY_SYSCLK_SUCCESS);
    }



  #else
    // PSVP

    if((m_astcDispPresets[enDisp0Type].bUseFpd != false) || (m_astcDispPresets[enDisp1Type].bUseFpd != false))
    {
        return CY_GFXENV_ERROR_BAD_PARAM; // no FPD Link on PSVP
    }
    u8Disp0ClkPllDiv = 1;
    u8Disp1ClkPllDiv = 1;

  #endif

    if(enDisp0Type != CY_GFXENV_DISP_TYPE_NONE)
    {
        if(m_astcDispPresets[enDisp0Type].bUseFpd != false)
        {
            uint8_t u8MapIndex = m_astcDispPresets[enDisp0Type].u8MapIndex;
            VIDEOSS0_VIDEOIO0_DISENG00_TCON0->unMAPBIT3_0.u32Register   = m_aau32FpdMapping[0][u8MapIndex];
            VIDEOSS0_VIDEOIO0_DISENG00_TCON0->unMAPBIT7_4.u32Register   = m_aau32FpdMapping[1][u8MapIndex];
            VIDEOSS0_VIDEOIO0_DISENG00_TCON0->unMAPBIT11_8.u32Register  = m_aau32FpdMapping[2][u8MapIndex];
            VIDEOSS0_VIDEOIO0_DISENG00_TCON0->unMAPBIT15_12.u32Register = m_aau32FpdMapping[3][u8MapIndex];
            VIDEOSS0_VIDEOIO0_DISENG00_TCON0->unMAPBIT19_16.u32Register = m_aau32FpdMapping[4][u8MapIndex];
            VIDEOSS0_VIDEOIO0_DISENG00_TCON0->unMAPBIT23_20.u32Register = m_aau32FpdMapping[5][u8MapIndex];
            VIDEOSS0_VIDEOIO0_DISENG00_TCON0->unMAPBIT27_24.u32Register = m_aau32FpdMapping[6][u8MapIndex];

            VIDEOSS0_VIDEOIO0_DISENG00_DISENGCFG0->unCTL.stcField.u1DSPCLKDIVIDE = 1; // needed ???

            VIDEOSS0_VIDEOIO0_DISENG00_TCON0->unTCON_CTRL.u32Register = 0;
            VIDEOSS0_VIDEOIO0_DISENG00_TCON0->unTCON_CTRL.stcField.u1BYPASS = 1;
            VIDEOSS0_VIDEOIO0_DISENG00_TCON0->unTCON_CTRL.stcField.u1ENLVDS = 1;

            if(Cy_Fpdlink_FastInit(Fpdlink0, (cy_fpdlink_en_pll_out_div_t) CLK_DIV_TO_REG_VAL(u8Disp0ClkPllDiv)) != CY_FPDLINK_SUCCESS)
            {
                enRetVal = CY_GFXENV_ERROR;
            }
        }

        VIDEOSS0_SUBSS0_VIDEOSSCFG->unCLKDSP0CFG.stcField.u2DIVVAL0       = CLK_DIV_TO_REG_VAL(u8Disp0ClkPllDiv);
        VIDEOSS0_SUBSS0_VIDEOSSCFG->unCLKDSP0CFG.stcField.u1TTLCLKINV0    = 0;

        VIDEOSS0_VIDEOIO0_DISENG00_FRAMEGEN0->unHTCFG1.stcField.u14HACT   = m_astcDispPresets[enDisp0Type].u16HorizontalActive;
        VIDEOSS0_VIDEOIO0_DISENG00_FRAMEGEN0->unHTCFG1.stcField.u14HTOTAL = m_astcDispPresets[enDisp0Type].u16HorizontalTotal;

        VIDEOSS0_VIDEOIO0_DISENG00_FRAMEGEN0->unVTCFG1.stcField.u14VACT   = m_astcDispPresets[enDisp0Type].u16VerticalActive;
        VIDEOSS0_VIDEOIO0_DISENG00_FRAMEGEN0->unVTCFG1.stcField.u14VTOTAL = m_astcDispPresets[enDisp0Type].u16VerticalTotal;

        VIDEOSS0_VIDEOIO0_DISENG00_FRAMEGEN0->unFGENABLE.stcField.u1FGEN  = 1;
    }

    if(enDisp1Type != CY_GFXENV_DISP_TYPE_NONE)
    {
        if(m_astcDispPresets[enDisp1Type].bUseFpd != false)
        {
          #ifdef VIDEOSS0_FPDLINK1          
            uint8_t u8MapIndex = m_astcDispPresets[enDisp1Type].u8MapIndex;
            VIDEOSS0_VIDEOIO0_DISENG10_TCON1->unMAPBIT3_0.u32Register   = m_aau32FpdMapping[0][u8MapIndex];
            VIDEOSS0_VIDEOIO0_DISENG10_TCON1->unMAPBIT7_4.u32Register   = m_aau32FpdMapping[1][u8MapIndex];
            VIDEOSS0_VIDEOIO0_DISENG10_TCON1->unMAPBIT11_8.u32Register  = m_aau32FpdMapping[2][u8MapIndex];
            VIDEOSS0_VIDEOIO0_DISENG10_TCON1->unMAPBIT15_12.u32Register = m_aau32FpdMapping[3][u8MapIndex];
            VIDEOSS0_VIDEOIO0_DISENG10_TCON1->unMAPBIT19_16.u32Register = m_aau32FpdMapping[4][u8MapIndex];
            VIDEOSS0_VIDEOIO0_DISENG10_TCON1->unMAPBIT23_20.u32Register = m_aau32FpdMapping[5][u8MapIndex];
            VIDEOSS0_VIDEOIO0_DISENG10_TCON1->unMAPBIT27_24.u32Register = m_aau32FpdMapping[6][u8MapIndex];

            VIDEOSS0_VIDEOIO0_DISENG10_DISENGCFG1->unCTL.stcField.u1DSPCLKDIVIDE = 1; // needed ???

            VIDEOSS0_VIDEOIO0_DISENG10_TCON1->unTCON_CTRL.u32Register = 0;
            VIDEOSS0_VIDEOIO0_DISENG10_TCON1->unTCON_CTRL.stcField.u1BYPASS = 1;
            VIDEOSS0_VIDEOIO0_DISENG10_TCON1->unTCON_CTRL.stcField.u1ENLVDS = 1;

            if(Cy_Fpdlink_FastInit(Fpdlink1, (cy_fpdlink_en_pll_out_div_t) CLK_DIV_TO_REG_VAL(u8Disp1ClkPllDiv)) != CY_FPDLINK_SUCCESS)
            {
                enRetVal = CY_GFXENV_ERROR;
            }            
          #else              
            enRetVal = CY_GFXENV_ERROR_BAD_PARAM;            
          #endif
        }

        VIDEOSS0_SUBSS0_VIDEOSSCFG->unCLKDSP1CFG.stcField.u2DIVVAL1       = CLK_DIV_TO_REG_VAL(u8Disp1ClkPllDiv);
        VIDEOSS0_SUBSS0_VIDEOSSCFG->unCLKDSP1CFG.stcField.u1TTLCLKINV1    = 0;

        VIDEOSS0_VIDEOIO0_DISENG10_FRAMEGEN1->unHTCFG1.stcField.u14HACT   = m_astcDispPresets[enDisp1Type].u16HorizontalActive;
        VIDEOSS0_VIDEOIO0_DISENG10_FRAMEGEN1->unHTCFG1.stcField.u14HTOTAL = m_astcDispPresets[enDisp1Type].u16HorizontalTotal;

        VIDEOSS0_VIDEOIO0_DISENG10_FRAMEGEN1->unVTCFG1.stcField.u14VACT   = m_astcDispPresets[enDisp1Type].u16VerticalActive;
        VIDEOSS0_VIDEOIO0_DISENG10_FRAMEGEN1->unVTCFG1.stcField.u14VTOTAL = m_astcDispPresets[enDisp1Type].u16VerticalTotal;

        VIDEOSS0_VIDEOIO0_DISENG10_FRAMEGEN1->unFGENABLE.stcField.u1FGEN  = 1;
    }

    return enRetVal;
}


/*******************************************************************************
* Function Name: InitPortPins
****************************************************************************//**
*
* \brief  Initializes all port pins that shall be configured according to user
*         configuration.
*
* \param  pstcCfg : Pointer to to port pin config struct member of GFX Env
*                   config struct
*
*******************************************************************************/
static void InitPortPins(const cy_gfxenv_stc_init_portpins_t * pstcPortInitCfg)
{
    for(uint16_t u16Index = 0; u16Index < CY_GET_ARRAY_LEN(m_astcPortPinCfg); u16Index++)
    {
        const stc_portpin_cfg_t * pstcCurPortPin = &m_astcPortPinCfg[u16Index];

        // Skip this loop iteration if the current port pin cfg belongs to a group that shall not be initialized
        switch(pstcCurPortPin->enGroup)
        {
            case Display0:
                if(pstcPortInitCfg->bInitDisplay0Ttl == false)
                {
                    continue;
                }
                break;
            case Display1:
                if(pstcPortInitCfg->bInitDisplay1Ttl == false)
                {
                    continue;
                }
                break;
            case Capture0:
                if(pstcPortInitCfg->bInitCapture0Ttl == false)
                {
                    continue;
                }
                break;
            case Smif0:
                if(pstcPortInitCfg->bInitSmif0 == false)
                {
                    continue;
                }
                break;
            case Smif1:
                if(pstcPortInitCfg->bInitSmif1 == false)
                {
                    continue;
                }
                break;
            case BlDisp0:
                if(pstcPortInitCfg->bInitBacklightDisp0 == false)
                {
                    continue;
                }
                break;
            case BlDisp1:
                if(pstcPortInitCfg->bInitBacklightDisp1 == false)
                {
                    continue;
                }
                break;
            case BlFpd0:
                if(pstcPortInitCfg->bInitBacklightFpdLink0 == false)
                {
                    continue;
                }
                break;
            case BlFpd1:
              #ifdef VIDEOSS0_FPDLINK1
                if(pstcPortInitCfg->bInitBacklightFpdLink1 == false)
                {
                    continue;
                }
                break;
              #else
                continue;
              #endif
            case Button:
                if(pstcPortInitCfg->bInitButtonGpios == false)
                {
                    continue;
                }
                break;
            default:
                break;
        }

        // If more detailed port pin settings need to be made (e.g. input trip point, slew rate, drive strength)
        // the implementation must be changed to use Cy_GPIO_Pin_Init API
        Cy_GPIO_Pin_FastInit( pstcCurPortPin->pstcPort,
                              pstcCurPortPin->u8Pin,
                              pstcCurPortPin->u8DriveMode,
                              pstcCurPortPin->u8GpioOutVal,
                              pstcCurPortPin->enMuxCfg      );

    }
}


#if (CY_USE_PSVP == 0)
/*******************************************************************************
* Function Name: ChangeSmifExtClock
****************************************************************************//**
*
* \brief  Changes the current SMIF clock (during initialization it may be required
* to run a slower frequency first before switching to the final frequency for 
* delay calibration)
*
* \param  u8SmifExtClkMhz : SMIF frequency that shall be output at the clock pin
*                           (i.e. internal frequency will be twice as high)
*
*******************************************************************************/
static cy_gfxenv_en_result_t ChangeSmifExtClock(uint8_t u8SmifExtClkMhz)
{
    uint32_t smifPllInputFreq;
    cy_en_sysclk_status_t enSysClkRetVal;

    enSysClkRetVal = Cy_SysClk_Pll400MDisable(CLK_PATH_SMIF_CLK);
    CY_ASSERT(enSysClkRetVal == CY_SYSCLK_SUCCESS);
    enSysClkRetVal = Cy_SysClk_GetPllInputFrequency(CLK_PATH_SMIF_CLK - 1, &smifPllInputFreq);
    CY_ASSERT(enSysClkRetVal == CY_SYSCLK_SUCCESS);

    cy_stc_pll_400M_config_t stcPllCfg =
    {
        .inputFreq    = smifPllInputFreq,
        .outputFreq   = 2UL * u8SmifExtClkMhz * 1000000UL, // twice the clock is needed internally in the SMIF IP
        .outputMode   = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
        .fracEn       = false,
        .fracDitherEn = false,
        .sscgEn       = false,
        .sscgDitherEn = false,
        .sscgDepth    = CY_SYSCLK_SSCG_DEPTH_MINUS_2_0,
        .sscgRate     = CY_SYSCLK_SSCG_RATE_DIV_512,
    };
    enSysClkRetVal = Cy_SysClk_Pll400MConfigure(CLK_PATH_SMIF_CLK, &stcPllCfg);
    CY_ASSERT(enSysClkRetVal == CY_SYSCLK_SUCCESS);
    enSysClkRetVal = Cy_SysClk_Pll400MEnable(CLK_PATH_SMIF_CLK, 10000);
    CY_ASSERT(enSysClkRetVal == CY_SYSCLK_SUCCESS);

    return CY_GFXENV_SUCCESS;
}
#endif


/*******************************************************************************
* Function Name: InitExtMem
****************************************************************************//**
*
* \brief  Initializes all SMIF instances and connected memories that shall be
*         configured according to user configuration.
*
* \param  pstcExtMemCfg : Pointer to to ExtMem config struct member of GFX Env
*                         config struct
*
* \return cy_gfxenv_en_result_t
*
*******************************************************************************/
static cy_gfxenv_en_result_t InitExtMem(const cy_gfxenv_stc_init_extmem_t * pstcExtMemCfg)
{
    cy_gfxenv_en_result_t enRetVal = CY_GFXENV_SUCCESS;
    uint8_t u8MaxClkMhz = 0;
    uint8_t u8Smif;

    //------------------------------------------------------------------------------------------------------------------------
    // Check clock constraints

    // 1) Find highest SMIF clock
    for(u8Smif = 0; u8Smif < CY_GFXENV_NR_OF_SMIF; u8Smif++)
    {
        if((pstcExtMemCfg->apstcInitSmif[u8Smif] != NULL) && (pstcExtMemCfg->apstcInitSmif[u8Smif]->u8SmifExtClockMhz > u8MaxClkMhz))
        {
            u8MaxClkMhz = pstcExtMemCfg->apstcInitSmif[u8Smif]->u8SmifExtClockMhz;
        }
    }
    if(u8MaxClkMhz > GFXENV_SMIF_EXT_CLOCK_MAX_MHZ)
    {
        return CY_GFXENV_ERROR_BAD_PARAM;
    }

    // 2) Check if all SMIF clocks can be derived from highest SMIF clock by applying a divider 1, 2, 4 or 8 and remember divider
    for(u8Smif = 0; u8Smif < CY_GFXENV_NR_OF_SMIF; u8Smif++)
    {
        if(pstcExtMemCfg->apstcInitSmif[u8Smif] != NULL)
        {
            if((u8MaxClkMhz % pstcExtMemCfg->apstcInitSmif[u8Smif]->u8SmifExtClockMhz) != 0)
            {
                return CY_GFXENV_ERROR_BAD_PARAM;
            }

            uint8_t u8ClkDiv = u8MaxClkMhz / pstcExtMemCfg->apstcInitSmif[u8Smif]->u8SmifExtClockMhz;
            cy_en_hf_clk_dividers_t enHfClkDiv;
            switch(u8ClkDiv)
            {
                case 1:
                    enHfClkDiv = CY_SYSCLK_HFCLK_NO_DIVIDE;
                    break;
                case 2:
                    enHfClkDiv = CY_SYSCLK_HFCLK_DIVIDE_BY_2;
                    break;
                case 4:
                    enHfClkDiv = CY_SYSCLK_HFCLK_DIVIDE_BY_4;
                    break;
                case 8:
                    enHfClkDiv = CY_SYSCLK_HFCLK_DIVIDE_BY_8;
                    break;
                default:
                    return CY_GFXENV_ERROR_BAD_PARAM;
            }
            m_astcSmifIntCfg[u8Smif].enHfClockDivider = enHfClkDiv;
        }
    }

    //------------------------------------------------------------------------------------------------------------------------
    // Initialization steps at "safe" SMIF clock frequency

  #if (CY_USE_PSVP == 0)
    ChangeSmifExtClock(GFXENV_SMIF_SAFE_EXT_CLOCK_MHZ);
  #endif

    for(u8Smif = 0; u8Smif < CY_GFXENV_NR_OF_SMIF; u8Smif++)
    {
        if(pstcExtMemCfg->apstcInitSmif[u8Smif] != NULL)
        {
            m_astcSmifIntCfg[u8Smif].pstcSmifRegBase = (volatile cy_stc_smif_reg_t *) ((uint32_t) SMIF0 + (u8Smif * SMIF_SECTION_SIZE));

            enRetVal = InitSmifAtSafeFreq(&m_astcSmifIntCfg[u8Smif], pstcExtMemCfg->apstcInitSmif[u8Smif]);
            if(enRetVal != CY_GFXENV_SUCCESS)
            {
                return enRetVal;
            }
        }
    }

    //------------------------------------------------------------------------------------------------------------------------
    // Initialization steps at target SMIF clock frequency

  #if (CY_USE_PSVP == 0)

    cy_en_sysclk_status_t enSysClkRetVal;

    ChangeSmifExtClock(u8MaxClkMhz);

    for(u8Smif = 0; u8Smif < CY_GFXENV_NR_OF_SMIF; u8Smif++)
    {
        enSysClkRetVal = Cy_SysClk_HfClockSetDivider(m_aenLutSmifInstanceToHfClock[u8Smif], m_astcSmifIntCfg[u8Smif].enHfClockDivider);
        CY_ASSERT(enSysClkRetVal == CY_SYSCLK_SUCCESS);

        if(pstcExtMemCfg->apstcInitSmif[u8Smif] != NULL)
        {
            enRetVal = InitSmifAtTargetFreq(&m_astcSmifIntCfg[u8Smif], pstcExtMemCfg->apstcInitSmif[u8Smif]);
            if(enRetVal != CY_GFXENV_SUCCESS)
            {
                return enRetVal;
            }
        }
    }  

  #endif

    return CY_GFXENV_SUCCESS;
}


/*******************************************************************************
* Function Name: InitSmifAtSafeFreq
****************************************************************************//**
*
* \brief  Does the necessary initialization of an SMIF instance before calling
*         the SMIF device specific initialization function.
*         All this is done at a "safe" frequency that should not cause any
*         signal issues or require non-default access cycles
*
* \param  pstcSmifIntCfg : Pointer to internal SMIF config
* \param  pstcSmifUsrCfg : Pointer to user SMIF config
*
* \return cy_gfxenv_en_result_t
*
*******************************************************************************/
static cy_gfxenv_en_result_t InitSmifAtSafeFreq(stc_smif_cfg_internal_t * pstcSmifIntCfg, const cy_gfxenv_stc_smif_cfg_t * pstcSmifUsrCfg)
{
    cy_gfxenv_en_result_t enRetVal = CY_GFXENV_SUCCESS;
    uint8_t u8Dev;

    //-------------------------------------------------------------------------------------------
    for(u8Dev = 0; u8Dev < CY_GFXENV_NR_OF_DEVICES_PER_SMIF; u8Dev++)
    {
        // Update some internal variables
        pstcSmifIntCfg->astcDevIntCfg[u8Dev].pstcDevRegBase           = Cy_SMIF_GetDeviceBasePtrFromSmifBasePtrAndDeviceNumber(pstcSmifIntCfg->pstcSmifRegBase, u8Dev);
        pstcSmifIntCfg->astcDevIntCfg[u8Dev].u8SmifExtClockMhz        = pstcSmifUsrCfg->u8SmifExtClockMhz;
        pstcSmifIntCfg->astcDevIntCfg[u8Dev].pstcCorrespondingSmifCtx = &pstcSmifIntCfg->stcSmifCtx;

        // Transition connected S26H memories into HyperFlash interface mode (Cy_SMIF_SEMP_EnableHyperBusInterface will init/de-init SMIF, so we do this before actual SMIF init)
        if ((pstcSmifUsrCfg->apstcDevUsrCfg[u8Dev] != NULL) && (pstcSmifUsrCfg->apstcDevUsrCfg[u8Dev]->enExtMemType == CY_SMIF_HB_MEMTYPE_HYPERFLASH_S26H))
        {
            // Try to enable HyperBus interface mode in case the connected flash is of type S26H
            Cy_SMIF_SEMP_EnableHyperBusInterface(pstcSmifIntCfg->pstcSmifRegBase, Cy_SMIF_GetSlaveSelectFromDeviceNumber(u8Dev));
        }
    }
    //-------------------------------------------------------------------------------------------

    pstcSmifIntCfg->stcSmifCtx = (cy_stc_smif_context_t) { 0 };
    if(Cy_SMIF_Init(pstcSmifIntCfg->pstcSmifRegBase, &m_stcGenericSmifCfg, GFXENV_SMIF_TIMEOUT, &pstcSmifIntCfg->stcSmifCtx) != CY_SMIF_SUCCESS)
    {
        return CY_GFXENV_ERROR;
    }

    // Set a delay based on the safe clock that is currently present (no calibration done, just use some nominal calculated values)
    uint8_t u8CalculatedTap;
    Cy_SMIF_SetDelayLineForFreq(pstcSmifIntCfg->pstcSmifRegBase, GFXENV_SMIF_SAFE_EXT_CLOCK_MHZ, true, &u8CalculatedTap);
    for(u8Dev = 0; u8Dev < CY_GFXENV_NR_OF_DEVICES_PER_SMIF; u8Dev++)
    {
        if(pstcSmifUsrCfg->apstcDevUsrCfg[u8Dev] != NULL)
        {            
            Cy_SMIF_Set_DelayTapSel(pstcSmifIntCfg->astcDevIntCfg[u8Dev].pstcDevRegBase, u8CalculatedTap);
        }
    }

    // Cache and prefetching for the clk_slow port (CM0+, DMA, Crypto, ...) needs to be disabled during initialization (e.g. due to flash command sequences -> status polling)
    Cy_SMIF_CacheDisable   (pstcSmifIntCfg->pstcSmifRegBase, CY_SMIF_CACHE_SLOW);
    Cy_SMIF_CacheInvalidate(pstcSmifIntCfg->pstcSmifRegBase, CY_SMIF_CACHE_SLOW);

    Cy_SMIF_Enable(pstcSmifIntCfg->pstcSmifRegBase, &pstcSmifIntCfg->stcSmifCtx);

    for(u8Dev = 0; u8Dev < CY_GFXENV_NR_OF_DEVICES_PER_SMIF; u8Dev++)
    {
        // Initialize all devices enabled by the user
        if(pstcSmifUsrCfg->apstcDevUsrCfg[u8Dev] != NULL)
        {
            enRetVal = InitSmifDeviceAtSafeFreq(&pstcSmifIntCfg->astcDevIntCfg[u8Dev], pstcSmifUsrCfg->apstcDevUsrCfg[u8Dev]);
            if(enRetVal != CY_GFXENV_SUCCESS)
            {
                return enRetVal;
            }
        }
    }

    return CY_GFXENV_SUCCESS;
}


/*******************************************************************************
* Function Name: InitSmifDeviceAtSafeFreq
****************************************************************************//**
*
* \brief  Initializes a SMIF device instance and configures I/O registers
*         in the connected memory device. All this is done at a "safe" frequency
*         that should not cause any signal issues or require non-default access cycles
*
* \param  pstcDevIntCfg : Pointer to internal device config
* \param  pstcDevUsrCfg : Pointer to user device config
*
* \return cy_gfxenv_en_result_t
*
*******************************************************************************/
static cy_gfxenv_en_result_t InitSmifDeviceAtSafeFreq(stc_smif_device_cfg_internal_t * pstcDevIntCfg,  const cy_gfxenv_stc_smif_device_cfg_t * pstcDevUsrCfg)
{
    cy_gfxenv_en_result_t (*pfnConfigureHyperMemory)(stc_smif_device_cfg_internal_t *,  const cy_gfxenv_stc_smif_device_cfg_t *);
    cy_gfxenv_en_result_t enRetVal      = CY_GFXENV_SUCCESS;
    uint8_t               u8ExtClkMhz   = pstcDevIntCfg->u8SmifExtClockMhz;
    bool                  bIsHyperFlash = CY_SMIF_HB_IS_HYPERFLASH(pstcDevUsrCfg->enExtMemType) ? true : false;



    // Convert size to register bit field value (refer register TRM for definition of the SizeMask field)
    uint32_t u32SizeBytes = pstcDevUsrCfg->u16SizeMegaBytes * 1024UL * 1024UL;
    uint32_t u32SizeMask = ~(u32SizeBytes - 1UL);

    // Check that region size is aligned to its base address
    if((pstcDevUsrCfg->u32BaseAddress % u32SizeBytes) != 0)
    {
        return CY_GFXENV_ERROR_BAD_PARAM;
    }

    // The optimal access latency is frequency and device dependent, so get the optimal latency for the current device
    if(Cy_SMIF_HB_GetOptimalLatencyCode(u8ExtClkMhz, pstcDevUsrCfg->enExtMemType, &pstcDevIntCfg->enOptimalLatency) != CY_SMIF_SUCCESS)
    {
        return CY_GFXENV_ERROR_BAD_PARAM;
    }

    // Update pointer with device type dependent config settings before calling actual device init function
    pstcDevIntCfg->pstcSmifHbDrvCfg = (bIsHyperFlash == true) ? &m_stcSmifDevHyperFlashCfg : &m_stcSmifDevHyperRamCfg;

    // Calculate offset from base from the signed user config value
    pstcDevIntCfg->u32CalibrationDataOffsetFromBase = (pstcDevUsrCfg->i32CalibrationDataOffset < 0) ? pstcDevUsrCfg->i32CalibrationDataOffset + u32SizeBytes :
                                                                                                      pstcDevUsrCfg->i32CalibrationDataOffset;

    // Update the generic configuration struct with device specific settings
    pstcDevIntCfg->pstcSmifHbDrvCfg->addr = pstcDevUsrCfg->u32BaseAddress;
    pstcDevIntCfg->pstcSmifHbDrvCfg->size = (cy_en_device_size_t) u32SizeMask;

    if(bIsHyperFlash == false)
    {                
        uint32_t u32ClkMemFreqHz;        
        Cy_SysClk_GetClkMemFrequency(&u32ClkMemFreqHz);
        uint32_t u32TimeoutCycles = Cy_SMIF_HB_CalculateTotalTimeoutCyclesForHyperRAM(GFXENV_HYPERRAM_MAX_CS_LOW_NS, u32ClkMemFreqHz / 1000000UL, u8ExtClkMhz);
        // Update the generic configuration struct with device specific settings
        pstcDevIntCfg->pstcSmifHbDrvCfg->totalTimeout = u32TimeoutCycles;

        pfnConfigureHyperMemory = ConfigureHyperRam;
    }
    else
    {
        pfnConfigureHyperMemory = ConfigureHyperFlash;
    }

    // Initial SMIF device (e.g. setup XIP read/write sequences, and other XIP related settings)
    if(Cy_SMIF_InitDeviceHyperBus(pstcDevIntCfg->pstcDevRegBase, pstcDevIntCfg->pstcSmifHbDrvCfg) != CY_SMIF_SUCCESS)
    {
        return CY_GFXENV_ERROR;
    }

    // Ensure merging is disabled for now, because it can interfere with flash command sequences like writing to consecutive addresses in the write buffer. Can be re-enabled post-init.
    Cy_SMIF_DeviceTransferMergingDisable(pstcDevIntCfg->pstcDevRegBase);

    // Access and configure the I/O registers in the actual memory device (e.g. optimize access latency, enable differential clock, ...)
    enRetVal = pfnConfigureHyperMemory(pstcDevIntCfg, pstcDevUsrCfg);
    if(enRetVal != CY_GFXENV_SUCCESS)
    {
        return enRetVal;
    }

    // Check whether calibration data pattern is existing or try to prepare it (by writing/programming) and remember result
    pstcDevIntCfg->bCalibrationPossible = Cy_SMIF_HB_CheckOrPrepareCalibrationDataPattern(   pstcDevIntCfg->pstcDevRegBase,
                                                                                             (bIsHyperFlash == true) ? CY_SMIF_HB_FLASH : CY_SMIF_HB_SRAM,
                                                                                             pstcDevUsrCfg->u32BaseAddress + pstcDevIntCfg->u32CalibrationDataOffsetFromBase,
                                                                                             pstcDevUsrCfg->bEraseIfNecessary );

    return CY_GFXENV_SUCCESS;
}


#if (CY_USE_PSVP == 0)
/*******************************************************************************
* Function Name: InitSmifAtTargetFreq
****************************************************************************//**
*
* \brief  Does the necessary initialization steps of a SMIF instance that need to be
*         executed at the desired target frequency (e.g. signal delay calibration)
*
* \param  pstcSmifIntCfg : Pointer to internal SMIF config
* \param  pstcSmifUsrCfg : Pointer to user SMIF config
*
* \return cy_gfxenv_en_result_t
*
*******************************************************************************/
static cy_gfxenv_en_result_t InitSmifAtTargetFreq(stc_smif_cfg_internal_t * pstcSmifIntCfg, const cy_gfxenv_stc_smif_cfg_t * pstcSmifUsrCfg)
{
    cy_gfxenv_en_result_t enRetVal = CY_GFXENV_SUCCESS;
    uint8_t u8Dev;

    if(Cy_SMIF_SetDelayLineForFreq(pstcSmifIntCfg->pstcSmifRegBase, pstcSmifUsrCfg->u8SmifExtClockMhz, true, NULL) != CY_SMIF_SUCCESS)
    {
        return CY_GFXENV_ERROR;
    }

    for(u8Dev = 0; u8Dev < CY_GFXENV_NR_OF_DEVICES_PER_SMIF; u8Dev++)
    {
        // Initialize all devices enabled by the user
        if(pstcSmifUsrCfg->apstcDevUsrCfg[u8Dev] != NULL)
        {
            enRetVal = InitSmifDeviceAtTargetFreq(&pstcSmifIntCfg->astcDevIntCfg[u8Dev], pstcSmifUsrCfg->apstcDevUsrCfg[u8Dev]);
            if(enRetVal != CY_GFXENV_SUCCESS)
            {
                return enRetVal;
            }
        }
    }

    // Enable cache and prefetching for the clk_slow port (CM0+, DMA, Crypto, ...)
    Cy_SMIF_CacheEnable           (pstcSmifIntCfg->pstcSmifRegBase, CY_SMIF_CACHE_SLOW);
    Cy_SMIF_CachePrefetchingEnable(pstcSmifIntCfg->pstcSmifRegBase, CY_SMIF_CACHE_SLOW);

    return CY_GFXENV_SUCCESS;
}


/*******************************************************************************
* Function Name: InitSmifDeviceAtTargetFreq
****************************************************************************//**
*
* \brief  Does the necessary initialization steps of a SMIF_DEVICE instance that
*         need to be  executed at the desired target frequency (e.g. signal
*         delay calibration)
*
* \param  pstcDevIntCfg : Pointer to internal device config
* \param  pstcDevUsrCfg : Pointer to user device config
*
* \return cy_gfxenv_en_result_t
*
*******************************************************************************/
static cy_gfxenv_en_result_t InitSmifDeviceAtTargetFreq(stc_smif_device_cfg_internal_t * pstcDevIntCfg,  const cy_gfxenv_stc_smif_device_cfg_t * pstcDevUsrCfg)
{
    cy_gfxenv_en_result_t enRetVal = CY_GFXENV_SUCCESS;

    if(pstcDevIntCfg->bCalibrationPossible == true)
    {
        // Execute a calibration for this device
        if(Cy_SMIF_HB_CalibrateDelay(  pstcDevIntCfg->pstcDevRegBase,
                                       pstcDevIntCfg->enOptimalLatency,
                                       pstcDevIntCfg->u32CalibrationDataOffsetFromBase,
                                       pstcDevIntCfg->pstcCorrespondingSmifCtx,          
                                       false                                             )  != CY_SMIF_SUCCESS )
                                       
        {
            enRetVal = CY_GFXENV_ERROR_DELAY_CALIBRATION;
        }

        // Remember applied settings for diagnostic purposes
        pstcDevIntCfg->enDelayLineSelected = Cy_SMIF_Get_DelayLineSel(Cy_SMIF_GetSmifBasePtrFromAnySmifPtr(pstcDevIntCfg->pstcDevRegBase));
        pstcDevIntCfg->u8DelayTapSelected  = Cy_SMIF_Get_DelayTapSel(pstcDevIntCfg->pstcDevRegBase);
    }

    // As the last step, enable tarnsfer merging if it had been enabled in the config for this device
    // (Note: merging was explicitly disabled during initialization to avoid potential problem with flash command sequences)
    if(pstcDevIntCfg->pstcSmifHbDrvCfg->mergeEnable == true)
    {
        Cy_SMIF_DeviceTransferMergingEnable(pstcDevIntCfg->pstcDevRegBase, pstcDevIntCfg->pstcSmifHbDrvCfg->mergeTimeout);
    }

    return enRetVal;
}
#endif

/*******************************************************************************
* Function Name: ConfigureHyperFlash
****************************************************************************//**
*
* \brief  Configures the I/O register(s) in a connected HyperFlash device
*
* \param  pstcDevIntCfg : Pointer to internal device config
* \param  pstcDevUsrCfg : Pointer to user device config
*
* \return cy_gfxenv_en_result_t
*
*******************************************************************************/
static cy_gfxenv_en_result_t ConfigureHyperFlash(stc_smif_device_cfg_internal_t * pstcDevIntCfg,  const cy_gfxenv_stc_smif_device_cfg_t * pstcDevUsrCfg)
{
    cy_un_h_flash_cfg1_reg_t  unHyperFlashVolatileCfgReg;
    cy_un_h_flash_cfg1_reg_t  unHyperFlashVolatileCfgRegReadBack;
    cy_un_h_flash_cfg2_reg_t  unHyperFlashVolatileCfgReg2;
    cy_un_h_flash_cfg2_reg_t  unHyperFlashVolatileCfgReg2ReadBack;
    CY_SMIF_FLASHDATA *       pHyperFlashBaseAddress = (CY_SMIF_FLASHDATA *) pstcDevUsrCfg->u32BaseAddress;
    bool                      bCfgReg2Available = false;

    // Different default values and device dependent config bits are handled below
    switch(pstcDevUsrCfg->enExtMemType)
    {
        case CY_SMIF_HB_MEMTYPE_HYPERFLASH_S26K:
            unHyperFlashVolatileCfgReg.u16 = CFG_REG1_DEFAULT_S26K;

            // --- Following settings are default, uncomment and change value if required ---
            // unHyperFlashVolatileCfgReg.fld.driveStrength    = CY_SMIF_HB_S26K_DRV_27_20_OHMS;
            break;
        case CY_SMIF_HB_MEMTYPE_HYPERFLASH_S26H:
            unHyperFlashVolatileCfgReg.u16 = CFG_REG1_DEFAULT_S26H;

            // --- Following settings are default, uncomment and change value if required ---
            // unHyperFlashVolatileCfgReg.fld.driveStrength    = CY_SMIF_HB_S26H_DRV_30_OHMS;
            // unHyperFlashVolatileCfgReg.fld.deepSleepPowMode = CY_SMIF_HB_STANBY_MODE_AFTER_POR;
            break;
        default:
            return CY_GFXENV_ERROR_BAD_PARAM;
    }
    
    unHyperFlashVolatileCfgReg.fld.readLatency       = pstcDevIntCfg->enOptimalLatency;

    // --- Following settings are default, uncomment and change value if required ---
    // unHyperFlashVolatileCfgReg.fld.burstLength       = CY_SMIF_HB_WRAP_BURST_LEN_32;
    // unHyperFlashVolatileCfgReg.fld.RDS_stallControll = CY_SMIF_HB_DS_STALL_ON_ERR;
    // unHyperFlashVolatileCfgReg.fld.sectorMapping     = CY_SMIF_HB_UN_SECT_LOWEST_ADDR;
    // unHyperFlashVolatileCfgReg.fld.SSR_freeze        = CY_SMIF_HB_SSR_UNLOCKED;
    // unHyperFlashVolatileCfgReg.fld.VCR_freeze        = CY_SMIF_HB_CONFIG_REG_UNLOCKED;


    // S26H has an additional config register
    if(pstcDevUsrCfg->enExtMemType == CY_SMIF_HB_MEMTYPE_HYPERFLASH_S26H)
    {
        bCfgReg2Available = true;

        unHyperFlashVolatileCfgReg2.u16                  = CFG_REG2_DEFAULT_S26H;

      #if (CY_USE_PSVP == 0) // PSVP does not support differential clock
        if(pstcDevUsrCfg->bUseDifferentialClock == true)
        {
            unHyperFlashVolatileCfgReg2.fld.masterClkSel     = CY_SMIF_HB_MASTER_CLK_DIFFERENTIAL; // Default: CY_SMIF_HB_MASTER_CLK_SINGLE_ENDED
        }
      #endif

        // --- Following settings are default, uncomment and change value if required ---
        // unHyperFlashVolatileCfgReg2.fld.split4KBSector   = CY_SMIF_HB_4KB_SECTORS_SPLIT;
        // unHyperFlashVolatileCfgReg2.fld.hybridBurstSel   = CY_SMIF_HB_HYBRID_BURST_DISABLED;
        // unHyperFlashVolatileCfgReg2.fld.eccErrorSel      = CY_SMIF_HB_1_2BIT_ECC_ERR_PROCESSED;
        // unHyperFlashVolatileCfgReg2.fld.addrTrapEccSel   = CY_SMIF_HB_2BIT_ERR_ADDR_TRAPED;
        // unHyperFlashVolatileCfgReg2.fld.doubleLatencySel = CY_SMIF_HB_SINGLE_LATENCY;
    }

    // Write config registers, then read back and compare
    CY_SMIF_HbFlash_LoadVolatileConfigReg (pHyperFlashBaseAddress, unHyperFlashVolatileCfgReg.u16);
    if(bCfgReg2Available == true)
    {
        CY_SMIF_HbFlash_LoadVolatileConfigReg2(pHyperFlashBaseAddress, unHyperFlashVolatileCfgReg2.u16);
    }

    // Update SMIF device with new latency settings (otherwise read communication with Hyper Device may fail now)
    Cy_SMIF_HB_SetDummyCycles(pstcDevIntCfg->pstcDevRegBase, CY_SMIF_HB_FLASH, pstcDevIntCfg->enOptimalLatency);

    unHyperFlashVolatileCfgRegReadBack.u16 = CY_SMIF_HbFlash_ReadVolatileConfigReg(pHyperFlashBaseAddress);
    if(unHyperFlashVolatileCfgRegReadBack.u16 != unHyperFlashVolatileCfgReg.u16)
    {
        return CY_GFXENV_ERROR_HYPERMEM_REG_READBACK;
    }

    if(bCfgReg2Available == true)
    {
        // Write config register, then read back and compare
        unHyperFlashVolatileCfgReg2ReadBack.u16 = CY_SMIF_HbFlash_ReadVolatileConfigReg2(pHyperFlashBaseAddress);
        if(unHyperFlashVolatileCfgReg2ReadBack.u16 != unHyperFlashVolatileCfgReg2.u16)
        {
            return CY_GFXENV_ERROR_HYPERMEM_REG_READBACK;
        }
    }

    return CY_GFXENV_SUCCESS;
}

/*******************************************************************************
* Function Name: ConfigureHyperRam
****************************************************************************//**
*
* \brief  Configures the I/O registers in a connected HyperRAM device
*
* \param  pstcDevIntCfg : Pointer to internal device config
* \param  pstcDevUsrCfg : Pointer to user device config
*
* \return cy_gfxenv_en_result_t
*
*******************************************************************************/
static cy_gfxenv_en_result_t ConfigureHyperRam(stc_smif_device_cfg_internal_t * pstcDevIntCfg,  const cy_gfxenv_stc_smif_device_cfg_t * pstcDevUsrCfg)
{
    cy_un_h_ram_cfg0_reg_t unHyperRamVolatileCfgReg0;
    cy_un_h_ram_cfg0_reg_t unHyperRamVolatileCfgReg0ReadBack;
    cy_un_h_ram_cfg1_reg_t unHyperRamVolatileCfgReg1;
    cy_un_h_ram_cfg1_reg_t unHyperRamVolatileCfgReg1ReadBack;
    uint16_t               u16CfgReg1Mask;

    // Different default values and device dependent config bits are handled below
    switch(pstcDevUsrCfg->enExtMemType)
    {
        case CY_SMIF_HB_MEMTYPE_HYPERRAM_S27KXXXX1:
            u16CfgReg1Mask                = CY_SMIF_CFG_REG1_MASK_WRITABLE_BITS_S27KXXXX1;
            unHyperRamVolatileCfgReg0.u16 = CY_SMIF_CFG_REG0_DEFAULT_S27KXXXX1;
            unHyperRamVolatileCfgReg1.u16 = CY_SMIF_CFG_REG1_DEFAULT_S27KXXXX1;

            // --- Following settings are default, uncomment and change value if required ---
            // unHyperRamVolatileCfgReg1.fldUnion.s27kxxxx1.dstbRefreshIntvl = CY_SMIF_H_RAM_DEFAULT_INTVL;
            break;
        case CY_SMIF_HB_MEMTYPE_HYPERRAM_S27KXXXX2:
            u16CfgReg1Mask                = CY_SMIF_CFG_REG1_MASK_WRITABLE_BITS_S27KXXXX2;
            unHyperRamVolatileCfgReg0.u16 = CY_SMIF_CFG_REG0_DEFAULT_S27KXXXX2;
            unHyperRamVolatileCfgReg1.u16 = CY_SMIF_CFG_REG1_DEFAULT_S27KXXXX2;

          #if (CY_USE_PSVP == 0) // PSVP does not support differential clock
            if(pstcDevUsrCfg->bUseDifferentialClock == true)
            {
                unHyperRamVolatileCfgReg1.fldUnion.s27kxxxx2.masterClkSel   = CY_SMIF_H_RAM_MASTER_CLK_DIFFERENTIAL; // Default: CY_SMIF_H_RAM_MASTER_CLK_SINGLE_ENDED
            }
          #endif
            // --- Following settings are default, uncomment and change value if required ---
            // unHyperRamVolatileCfgReg1.fldUnion.s27kxxxx2.partialRefresh = CY_SMIF_H_RAM_REFRESH_ARRAY_FULL;
            // unHyperRamVolatileCfgReg1.fldUnion.s27kxxxx2.hybridSleep    = CY_SMIF_H_RAM_HYBRID_SLEEP_DISABLED;
            break;
        default:
            return CY_GFXENV_ERROR_BAD_PARAM;
    }

    unHyperRamVolatileCfgReg0.fld.readLatency   = pstcDevIntCfg->enOptimalLatency;    
    // unHyperRamVolatileCfgReg0.fld.varLatency    = CY_SMIF_H_RAM_VAR_LATENCY; // Default: CY_SMIF_H_RAM_FIXED_LATENCY // TODO/FIX: Calibration may fail if variable latency is enabled

    // --- Following settings are default, uncomment and change value if required ---
    // unHyperRamVolatileCfgReg0.fld.driveStrength = CY_SMIF_H_RAM_DRV_34_OHMS;
    // unHyperRamVolatileCfgReg0.fld.burstLength   = CY_SMIF_H_RAM_BURST_LEN_32;
    // unHyperRamVolatileCfgReg0.fld.hyBurstEn     = CY_SMIF_H_RAM_HY_BURST_DISABLE;
    // unHyperRamVolatileCfgReg0.fld.deepPowerDown = CY_SMIF_H_RAM_NORMAL_OP;

    // Write config registers
    CY_SMIF_WriteHYPERRAM_REG(pstcDevIntCfg->pstcDevRegBase, CY_SMIF_CFG_REG0_ADDR_S27K, unHyperRamVolatileCfgReg0.u16);
    CY_SMIF_WriteHYPERRAM_REG(pstcDevIntCfg->pstcDevRegBase, CY_SMIF_CFG_REG1_ADDR_S27K, unHyperRamVolatileCfgReg1.u16);

    // Update SMIF device with new latency settings (otherwise read communication with Hyper Device may fail now)
    Cy_SMIF_HB_SetDummyCycles(pstcDevIntCfg->pstcDevRegBase, CY_SMIF_HB_SRAM, pstcDevIntCfg->enOptimalLatency);

    // Readback registers and compare
    CY_SMIF_ReadHYPERRAM_REG(pstcDevIntCfg->pstcDevRegBase,  CY_SMIF_CFG_REG0_ADDR_S27K, &unHyperRamVolatileCfgReg0ReadBack.u16);
    CY_SMIF_ReadHYPERRAM_REG(pstcDevIntCfg->pstcDevRegBase,  CY_SMIF_CFG_REG1_ADDR_S27K, &unHyperRamVolatileCfgReg1ReadBack.u16);

    if(  (unHyperRamVolatileCfgReg0ReadBack.u16                   !=  unHyperRamVolatileCfgReg0.u16)                   ||
        ((unHyperRamVolatileCfgReg1ReadBack.u16 & u16CfgReg1Mask) != (unHyperRamVolatileCfgReg1.u16 & u16CfgReg1Mask))    )
    {
        return CY_GFXENV_ERROR_HYPERMEM_REG_READBACK;
    }

    return CY_GFXENV_SUCCESS;
}

#if defined(__cplusplus)
}
#endif


/* [] END OF FILE */
