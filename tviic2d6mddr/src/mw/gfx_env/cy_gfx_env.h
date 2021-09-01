/***************************************************************************//**
* \file cy_gfx_env.h
* \version 1.1
*
* \brief
* Provides an API declaration of the Graphics Environment (GfxEnv) middleware driver
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_gfxenv Middleware GFX Environment (MW GfxEnv)
* \{
* The GfxEnv middleware provides an API to setup the environment for GFX application.
*
* \defgroup group_gfxenv_macros Macro
* \defgroup group_gfxenv_functions Functions
* \defgroup group_gfxenv_data_structures Data structures
* \defgroup group_gfxenv_enums Enumerated Types
*/


#if !defined(CY_GFXENV_H)
#define CY_GFXENV_H

#include <stddef.h>
#include <stdbool.h>
#include "smif_mem/cy_smif_hb_flash.h"


#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_gfxenv_macros
* \{
*/
// Button IDs (button driver is initialized by GfxEnv, application can use button driver with these IDs)
#define CY_GFXENV_BUTTON_ID_AB_CB    0x00  // Button on PSVP adapter board (AB) or later CPU board (CB)
#define CY_GFXENV_BUTTON_ID_CEB      0x01  // Button on Cluster Extension Board (CEB)
#define CY_GFXENV_BUTTON_ID_BB_1     0x11  // Button on Base Board (BB)
#define CY_GFXENV_BUTTON_ID_BB_2     0x12  // Button on Base Board (BB)
#define CY_GFXENV_BUTTON_ID_BB_3     0x13  // Button on Base Board (BB)
#define CY_GFXENV_BUTTON_ID_BB_4     0x14  // Button on Base Board (BB)
#define CY_GFXENV_BUTTON_ID_BB_5     0x15  // Button on Base Board (BB)

#define CY_GFXENV_BUTTON_ID_WAKE     0x20  // Button "WAKE" (or CENTER) on CPU Board
#define CY_GFXENV_BUTTON_ID_LEFT     0x21  // Button "LEFT" on CPU Board
#define CY_GFXENV_BUTTON_ID_RIGHT    0x22  // Button "RIGHT" on CPU Board
#define CY_GFXENV_BUTTON_ID_UP       0x23  // Button "UP" on CPU Board
#define CY_GFXENV_BUTTON_ID_DOWN     0x24  // Button "DOWN" on CPU Board


/**
* Number of SMIF "instances" or "cores" (depending on IP revision) (or in other words: the number of the architecural units that comprise the SMIF DEVICEs)
*/
#if (CY_IP_MXSMIF_VERSION >= 4)
    #define CY_GFXENV_NR_OF_SMIF                  (CY_IP_MXSMIF_INSTANCES * 2) // new SMIF architecture: Instance -> n Cores -> m Devices/Core (n, m := 2 for all current devices with this IP version)
#else
    #define CY_GFXENV_NR_OF_SMIF                  (CY_IP_MXSMIF_INSTANCES)     // old SMIF architecture: Instance -> m Devices/Instance (m := 2 for all current devices with this IP version)
#endif
        
/**
* Number of DEVICES per SMIF "instance" or "core" (depending on IP revision)
*/
#define CY_GFXENV_NR_OF_DEVICES_PER_SMIF          CY_SMIF_DRV_SMIF0_DEVICE_NR

/**
* MPU region number which is used temporarily during SMIF init if feature enabled (use last region with highest priority)
*/
#if CY_CPU_CORTEX_M0P
    #define CY_GFXENV_SMIF_TEMP_MPU_REGION        7
#else
    #define CY_GFXENV_SMIF_TEMP_MPU_REGION        15
#endif

/**
* SCB Instance used for semihosting
*/
#define CY_GFXENV_SEMIHOSTING_SCB                 CY_USB_SCB_TYPE

/**
* Optional watchdog handler function used during semihosting (e.g. blocking reads!)
*/
#define CY_GFXENV_SEMIHOSTING_WDG_HANDLER         NULL  // or function of type cy_sw_tmr_wdg_handle_callout_t

/** \} group_gfxenv_macros */


/***************************************
*       Enumeration
***************************************/

/**
* \addtogroup group_gfxenv_enums
* \{
*/

/**
* Function return values
*/
typedef enum
{
    CY_GFXENV_SUCCESS                     = 0x00u,   /**< Returned successful */
    CY_GFXENV_ERROR                       = 0x01u,   /**< General error */
    CY_GFXENV_ERROR_BAD_PARAM             = 0x02u,   /**< Bad parameter was passed */
    CY_GFXENV_ERROR_HYPERMEM_REG_READBACK = 0x03u,   /**< Reading back of I/O register in Hyper memory and comparing with written value failed */
    CY_GFXENV_ERROR_DELAY_CALIBRATION     = 0x04u,   /**< SMIF delay calibration failed */
} cy_gfxenv_en_result_t;

/**
* Display type presets
*/
typedef enum
{
    CY_GFXENV_DISP_TYPE_NONE = 0,              /**< No display */
    CY_GFXENV_DISP_TYPE_480_272_60_TTL,        /**< Display with resolution  480x272, refresh rate 60 Hz, RGB TTL interface */
    CY_GFXENV_DISP_TYPE_640_480_60_TTL,        /**< Display with resolution  640x480, refresh rate 60 Hz, RGB TTL interface */
    CY_GFXENV_DISP_TYPE_800_480_60_TTL,        /**< Display with resolution  800x480, refresh rate 60 Hz, RGB TTL interface */
    CY_GFXENV_DISP_TYPE_800_480_60_FPD_JEIDA,  /**< Display with resolution  800x480, refresh rate 60 Hz, FPD-Link interface, signal mapping according to JEIDA standard */
    CY_GFXENV_DISP_TYPE_800_480_60_FPD_VESA,   /**< Display with resolution  800x480, refresh rate 60 Hz, FPD-Link interface, signal mapping according to VESA standard */
    CY_GFXENV_DISP_TYPE_1280_768_60_FPD_VESA,  /**< Display with resolution 1280x768, refresh rate 60 Hz, FPD-Link interface, signal mapping according to VESA standard */
    CY_GFXENV_DISP_TYPE_1600_480_60_FPD_VESA,  /**< Display with resolution 1600x480, refresh rate 60 Hz, FPD-Link interface, signal mapping according to VESA standard */

} cy_gfxenv_en_disp_type_t;

/** \} group_gfxenv_enums */


/***************************************
*       Configuration Structure
***************************************/

/**
* \addtogroup group_gfxenv_data_structures
* \{
*/


/**
* Controls which port functions shall be initialized
*/
typedef struct
{
    bool  bInitDisplay0Ttl;       /**< Select whether port pins with Display #0 TTL signals shall be initialized */
    bool  bInitDisplay1Ttl;       /**< Select whether port pins with Display #1 TTL signals shall be initialized */
    bool  bInitCapture0Ttl;       /**< Select whether port pins with Capture #0 TTL signals shall be initialized */
    bool  bInitSmif0;             /**< Select whether port pins with SMIF #0 signals shall be initialized */
    bool  bInitSmif1;             /**< Select whether port pins with SMIF #1 signals shall be initialized */
    bool  bInitBacklightDisp0;    /**< Select whether port pins with backlight control signals for Display #0 shall be initialized (see schematics, typically only needed if PWM control is required) */
    bool  bInitBacklightDisp1;    /**< Select whether port pins with backlight control signals for Display #1 shall be initialized (see schematics, typically only needed if PWM control is required) */
    bool  bInitBacklightFpdLink0; /**< Select whether port pins with backlight control signals for Display #0 FPD-Link shall be initialized (see schematics, typically only needed if PWM control is required) */
    bool  bInitBacklightFpdLink1; /**< Select whether port pins with backlight control signals for Display #1 FPD-Link shall be initialized (see schematics, typically only needed if PWM control is required) */
    bool  bInitButtonGpios;       /**< Select whether port pins connected the buttons shall be initialized */
} cy_gfxenv_stc_init_portpins_t;


/**
* Controls SMIF_DEVICE HyperBus initialization
*/
typedef struct
{
    uint32_t              u32BaseAddress;            /**< Base address to be used for memory mapping this device (must be part of the corresponding total SMIFn_XIP address space and aligned to the size) */
    uint16_t              u16SizeMegaBytes;          /**< Configure how many megabytes shall be reserved in memory map for this device (Minimum value: 1 MB, use power of 2) */
    cy_smif_hb_memtype_t  enExtMemType;              /**< Select the type of the connected memory */
    int32_t               i32CalibrationDataOffset;  /**< Offset address where the calibration data pattern is located in the memory or where it shall be written/programmed to. Resulting address must be 16-byte aligned! 
                                                          Positive values: u32BaseAddress + i32CalibrationDataOffset; Negative Values: u32BaseAddress + (u16SizeMegaBytes * 1024 * 1024) - i32CalibrationDataOffset   */
    bool                  bEraseIfNecessary;         /**< In case of HyperFlash allows the driver to erase the sector where the calibration data should be located if the actual content is not blank or does not match the pattern. Don'T care for HyperRAM */
    bool                  bUseDifferentialClock;     /**< Select whether the connected memory will be configured to expect a differential clock input */
} cy_gfxenv_stc_smif_device_cfg_t;


/**
* Controls SMIF HyperBus initialization
*/
typedef struct
{
    uint8_t                            u8SmifExtClockMhz;                                  /**< Specify the SMIF clock frequency (chip external) that shall be applied for this SMIF.
                                                                                                IMPORTANT: The ratio of all defined SMIF frequencies needs to be 1, 2, 4 or 8 (or 1, 0.5, 0.25, 0.125 respectively) */
    cy_gfxenv_stc_smif_device_cfg_t *  apstcDevUsrCfg[CY_GFXENV_NR_OF_DEVICES_PER_SMIF];   /**< Select which SMIF_DEVICE instances shall be initialized by providing a pointer to the SMIF device cfg struct or NULL */
} cy_gfxenv_stc_smif_cfg_t;


/**
* Controls external memory initialization
*/
typedef struct
{    
    bool                        bInitMpuTemporarily;                  /**< Select whether GfxEnv shall temporarily configure an MPU region covering SMIF0+1 XIP space during the initialization phase */
    uint8_t                     u8MpuRegionTemp;                      /**< Specify which MPU region to use if #bInitMpuTemporarily is set to 'true' */
    cy_gfxenv_stc_smif_cfg_t *  apstcInitSmif[CY_GFXENV_NR_OF_SMIF];  /**< Select which SMIF instances shall be initialized by providing a pointer to the SMIF cfg struct or NULL */
} cy_gfxenv_stc_init_extmem_t;


/**
* Controls button initialization
*/
typedef struct
{
    uint8_t               u8CySwTimerId;  /**< Select which SW Timer ID shall be used by the Button driver for its periodic processing (e.g. debouncing and callout) */
    cy_button_callback_t  pfnCallback;    /**< User function that will be called by button driver when a button state changes */
} cy_gfxenv_stc_init_buttons_t;


/**
* Initialization configuration structure for the GFX environment
*/
typedef struct
{
    bool                             bInitSwTimer;      /**< Select whether SW Timer module shall be initialized */
    bool                             bInitSemihosting;  /**< Select whether semihosting (including clock and port pins) shall be initialized */
    cy_gfxenv_stc_init_portpins_t *  pstcInitPortPins;  /**< Select whether port pins shall be initialized by providing a pointer to the port pin cfg struct or NULL */
    cy_gfxenv_stc_init_extmem_t *    pstcInitExtMem;    /**< Select whether ext memories shall be initialized by providing a pointer to the ext mem cfg struct or NULL */
    cy_gfxenv_stc_init_buttons_t *   pstcInitButtons;   /**< Select whether button driver shall be initialized by providing a pointer to the button cfg struct or NULL */
} cy_gfxenv_stc_cfg_t;



/** \} group_gfxenv_data_structures */


/***************************************
*       Function Prototypes
***************************************/

/**
* \addtogroup group_gfxenv_functions
* \{
*/

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
cy_gfxenv_en_result_t Cy_GfxEnv_Init(const cy_gfxenv_stc_cfg_t * pstcGfxEnvCfg);

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
cy_gfxenv_en_result_t Cy_GfxEnv_FastInit(uint8_t u8Smif0ExtClockMhz, uint8_t u8Smif1ExtClockMhz, cy_button_callback_t pfnButtonCallback);


/*******************************************************************************
* Function Name: Cy_GfxEnv_EnableTestImage
****************************************************************************//**
*
* \brief  Enables the output of test images on the 2 display links
*
* \param  enDisp0Type : The display type to be setup for display link #0
* \param  enDisp1Type : The display type to be setup for display link #1
*
* \return cy_gfxenv_en_result_t
*
*******************************************************************************/
cy_gfxenv_en_result_t Cy_GfxEnv_EnableTestImage(cy_gfxenv_en_disp_type_t enDisp0Type, cy_gfxenv_en_disp_type_t enDisp1Type);



/** \} group_gfxenv_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_GFXENV_H */

/** \} group_gfxenv */

/* [] END OF FILE */
