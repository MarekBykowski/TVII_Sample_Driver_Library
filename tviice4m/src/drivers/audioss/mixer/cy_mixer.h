/*******************************************************************************
* \file cy_mixer.h
* \version 1.0
*
* Provides an API declaration of the mixer driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_mixer Audio Mixer (Mixer)
* \{
* This driver provides global Mixer defines and API function definitions.
*
* \defgroup group_mixer_macros Macro
* \defgroup group_mixer_functions Functions
* \defgroup group_mixer_data_structures Data structures
* \defgroup group_mixer_enums Enumerated types
*/

#if !defined(__CY_MIXER_H__)
#define __CY_MIXER_H__

#include "cy_device_headers.h"
#include "syslib/cy_syslib.h"
#include <stdbool.h>

#ifdef CY_IP_MXMIXER

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
* \addtogroup group_mixer_macros
* \{
*/

/** Driver major version */
#define CY_CPU_DRV_VERSION_MAJOR   1
/** Driver minor version */
#define CY_CPU_DRV_VERSION_MINOR   0
/** The Mixer driver identifier */
#define CY_MIXER_ID                      (CY_PDL_DRV_ID(0x22U))
  
/** \} group_mixer_macros */

/**
* \addtogroup group_mixer_enums
* \{
*/

  /* Mixer Word Size */
typedef enum
{
    CY_MIXER_TX_WD_SIZE_16BITS	        = 4u,	/**< MIXER transmitter PCM Word Size - always uses 16-bit PCM words. */
} cy_en_mixer_tx_wd_size_t;

/* Mixer TX Format */
typedef enum
{
    CY_MIXER_TX_FMT_LEFT_DELAYED	= 0u,	/**< MIXER transmitter Format left delayed */
    CY_MIXER_TX_FMT_LEFT	        = 1U,	/**< MIXER transmitter Format left */
    CY_MIXER_TX_FMT_RIGHT_DELAYED	= 2U,	/**< MIXER transmitter Format right delayed */
    CY_MIXER_TX_FMT_RIGHT	        = 3U,	/**< MIXER transmitter Format right */
} cy_en_mixer_tx_fmt_t;

/* Mixer TX Mode */
typedef enum
{
    CY_MIXER_TX_MODE_SLAVE	        = 0u,	/**< MIXER transmitter slave mode */
    CY_MIXER_TX_MODE_MASTER	        = 1U,	/**< MIXER transmitter master mode */
} cy_en_mixer_tx_mode_t;

/* Mixer TX Interface Clock Selection */
typedef enum
{
    CY_MIXER_TX_CLK_SEL_SRSS	        = 0u,	/**< MIXER transmitter Clock Select SRSS Internal */
    CY_MIXER_TX_CLK_SEL_MASTER_IFC      = 1U,	/**< MIXER transmitter Clock Select from Master Interface */
} cy_en_mixer_tx_clk_sel_t;

/* Mixer Channel */
typedef enum
{
    CY_MIXER_CHANNEL0	                = 0u,	/**< MIXER Channel 0 */
    CY_MIXER_CHANNEL1	                = 1U,	/**< MIXER Channel 1 */
} cy_en_mixer_channel_t;

/* Mixer Tx Interrupt Sources */
typedef enum
{
    CY_MIXER_TX_FIFO_UNDERFLOW          = 0u,	/**< MIXER Fifo underflow interrupt */
    CY_MIXER_TX_IFC_UNDERFLOW	        = 1U,	/**< MIXER Interface underflow interrupt */
} cy_stc_mixer_tx_int_src_t;

/* Mixer Source Interrupt Sources */
typedef enum
{
    CY_MIXER_SRC_FIFO_TRIGGER           = 0u,	/**< MIXER source Fifo trigger interrupt */
    CY_MIXER_SRC_FIFO_OVERFLOW	        = 1U,	/**< MIXER source Fifo overflow interrupt */
    CY_MIXER_SRC_FADE_OUT	        = 2U,	/**< MIXER source fade out interrupt */
} cy_en_mixer_src_interrupt_t;

/* Mixer Destination Interrupt Sources */
typedef enum
{
    CY_MIXER_DST_FIFO_TRIGGER           = 0u,	/**< MIXER destination Fifo trigger interrupt */
    CY_MIXER_DST_FIFO_OVERFLOW	        = 1U,	/**< MIXER destination Fifo overflow interrupt */
    CY_MIXER_DST_FADE_OUT	        = 2U,	/**< MIXER destination fade out interrupt */
} cy_en_mixer_dst_interrupt_t;

/* Mixer Sample Frequency Upscale Ratio */
typedef enum
{
    CY_MIXER_SRC_FREQ_DOWNSAMPLE_BY_2   = 0u,	/**< MIXER source frequency down sample by 2 */
    CY_MIXER_SRC_FREQ_NO_RESAMPLE       = 1U,	/**< MIXER source frequency no resampling, same */
    CY_MIXER_SRC_FREQ_UPSAMPLE_BY_2     = 2U,	/**< MIXER source frequency up sampling by 2 (0.5) */
    CY_MIXER_SRC_FREQ_UPSAMPLE_BY_3     = 3U,	/**< MIXER source frequency up sampling by 3 */
    CY_MIXER_SRC_FREQ_UPSAMPLE_BY_4     = 4U,	/**< MIXER source frequency up sampling by 4 */
    CY_MIXER_SRC_FREQ_UPSAMPLE_BY_6     = 5U,	/**< MIXER source frequency up sampling by 6 */
    CY_MIXER_SRC_FREQ_UPSAMPLE_BY_8     = 6U,	/**< MIXER source frequency up sampling by 8 */
    CY_MIXER_SRC_FREQ_UPSAMPLE_BY_12    = 7U,	/**< MIXER source frequency up sampling by 12 */
} cy_en_mixer_src_fs_ratio_t;

/* Mixer source channel data select 
   Specifies selection of the channel's 16-bit PCM data from the source FIFO data[31:0] */
typedef enum
{
    CY_MIXER_SRC_DATA_LOW   = 0u, /**< MIXER source data from data[15:0] (default setting) */
    CY_MIXER_SRC_DATA_HIGH  = 1U, /**< MIXER source data from data[31:16] */
    CY_MIXER_SRC_CONSTANT_0 = 2U, /**< MIXER source data is a constant PCM data value of "0", no source FIFO */
} cy_en_mixer_src_data_t;

/* Mixer Fade Code Select */
typedef enum
{
    CY_MIXER_CODE_MUTE  = 0u,   /**< MIXER fade gain code 0 */
    CY_MIXER_CODE_SAME = 115u, /**< MIXER fade gain code 115 */
} cy_en_mixer_fade_code_t;

/**
* Mixer status definitions.
*/

typedef enum 
{
    CY_MIXER_SUCCESS   = 0x00UL,                                  /**< Successful. */
    CY_MIXER_BAD_PARAM = CY_MIXER_ID | CY_PDL_STATUS_ERROR | 0x01UL /**< One or more invalid parameters. */
} cy_en_mixer_status_t;

/** \} group_mixer_enums */

/**
* \addtogroup group_mixer_data_structures
* \{
*/

/**
* Mixer Source initialization configuration.
*/
typedef struct
{
    cy_en_mixer_src_fs_ratio_t fsRatio;  /**< Sample frequency upscale ratio */
    cy_en_mixer_src_data_t     ch0sel;   /**< Channel 0 bit allocation */
    cy_en_mixer_src_data_t     ch1sel;   /**< Channel 0 bit allocation */
    cy_en_mixer_fade_code_t    fadeCode; /**< Initial fade state */
    uint8_t                    gainCode; /**< Gain code in the range [0, 127]. */
    uint8_t                    trgLevel; /**< Trigger level */
} cy_stc_mixer_src_config_t;

/**
* Mixer Destination initialization configuration.
*/
typedef struct
{
    cy_en_mixer_fade_code_t fadeCode; /**< Initial fade state */
    uint8_t                 gainCode; /**< Gain code in the range [0, 127]. */
    uint8_t                 trgLevel; /**< Trigger level */
} cy_stc_mixer_dst_config_t;

/**
* Mixer Transmit initialization configuration.
*/
typedef struct
{
    cy_en_mixer_tx_wd_size_t		wordSize;		/**< PCM Word Size, only 16-bits */
    cy_en_mixer_tx_fmt_t		txFormat;		/**< I2S Format */
    cy_en_mixer_tx_mode_t		txMode;		        /**< Master Mode */
    uint8_t                             clkDiv;                 /**< I2S Interface clock divider [1...255] */
    cy_en_mixer_tx_clk_sel_t            clkSel;                 /**< Clock Select from either SRSS (internal) or Master Ifc */
    bool                                clkPol;                 /**< Clock polarity, as is or inverted */
    bool                                wSelPol;                /**< Word select polarity, as is or inverted */
    cy_en_mixer_channel_t               channel;                /**< Channel selection, channel0 or channel1 */
    uint8_t                             chlSize;                /**< Channel size, [1..32] */
} cy_stc_mixer_tx_config_t;

/** \} group_mixer_data_structures */

/**
* \addtogroup group_mixer_functions
* \{
*/

//****************************************************************************//
// Global initialization functions                                            
//****************************************************************************//
cy_en_mixer_status_t Cy_Mixer_SourceInit(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_stc_mixer_src_config_t const * config);
void Cy_Mixer_SourceDeInit(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
cy_en_mixer_status_t Cy_Mixer_DestinationInit(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, cy_stc_mixer_dst_config_t const * config);
void Cy_Mixer_DestinationDeInit(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);
cy_en_mixer_status_t Cy_Mixer_TransmitInit(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_stc_mixer_tx_config_t const * config);
void Cy_Mixer_TransmitDeInit(volatile stc_MIXER_MIXER_TX_STRUCT_t * base);

extern void Cy_Mixer_SourceStartFadeIn(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, uint32_t pace);
extern bool Cy_Mixer_SourceHasFadeInCompleted(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
extern void Cy_Mixer_SourceStartFadeOut(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, uint32_t pace, bool deact);
extern bool Cy_Mixer_SourceHasFadeOutCompleted(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);

//****************************************************************************//
// Mixer Source Control and Status                                           
//****************************************************************************//
__STATIC_INLINE void Cy_Mixer_Src_SampleFreqRatio(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_src_fs_ratio_t fsRatio);
__STATIC_INLINE void Cy_Mixer_Src_ChannelSelect(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_channel_t channel, cy_en_mixer_src_data_t data);
__STATIC_INLINE void Cy_Mixer_Src_Enable(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Src_Disable(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);

__STATIC_INLINE uint8_t Cy_Mixer_Src_GetCurrentPhase(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);

__STATIC_INLINE void Cy_Mixer_Src_FadeControl(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_fade_code_t fadeCode);

__STATIC_INLINE uint16_t Cy_Mixer_Src_GetCurrentPace(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);

__STATIC_INLINE void Cy_Mixer_Src_FadeInEnable(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Src_FadeInDisable(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Src_FadeOutEnable(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Src_FadeOutDisable(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Src_AutoFadeActivate(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Src_AutoFadeDeactivate(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Src_FadePaceSelect(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, uint16_t pace);

__STATIC_INLINE void Cy_Mixer_Src_GainCodeSelect(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, uint8_t code);

__STATIC_INLINE void Cy_Mixer_Src_FifoTriggerLevel(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, uint8_t level);
__STATIC_INLINE void Cy_Mixer_Src_Mute(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Src_Unmute(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Src_Activate(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Src_Deactivate(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);

__STATIC_INLINE uint8_t Cy_Mixer_Src_GetUsedFifoEntries(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
__STATIC_INLINE uint8_t Cy_Mixer_Src_GetFifoReadPtr(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);
__STATIC_INLINE uint8_t Cy_Mixer_Src_GetFifoWritePtr(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base);

__STATIC_INLINE void Cy_Mixer_Src_FifoWriteData(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, uint32_t data);

__STATIC_INLINE void Cy_Mixer_Src_ClearInterrupt(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_src_interrupt_t intSrc);
__STATIC_INLINE void Cy_Mixer_Src_SetInterrupt(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_src_interrupt_t intSrc);
__STATIC_INLINE void Cy_Mixer_Src_ClearInterruptMask(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_src_interrupt_t intSrc);
__STATIC_INLINE void Cy_Mixer_Src_SetInterruptMask(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_src_interrupt_t intSrc);

//****************************************************************************//
// Mixer Destination Control and Status
//****************************************************************************//
__STATIC_INLINE void Cy_Mixer_Dst_Enable(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Dst_Disable(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);

__STATIC_INLINE void Cy_Mixer_Dst_FadeControl(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, cy_en_mixer_fade_code_t fadeCode);

__STATIC_INLINE uint16_t Cy_Mixer_Dst_GetCurrentPace(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);

__STATIC_INLINE void Cy_Mixer_Dst_FadeInEnable(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Dst_FadeInDisable(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Dst_FadeOutEnable(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Dst_FadeOutDisable(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Dst_AutoFadeActivate(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Dst_AutoFadeDeactivate(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Dst_FadePaceSelect(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, uint16_t pace);

__STATIC_INLINE void Cy_Mixer_Dst_GainCodeSelect(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, uint8_t code);

__STATIC_INLINE void Cy_Mixer_Dst_FifoTriggerLevel(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, uint8_t level);
__STATIC_INLINE void Cy_Mixer_Dst_Mute(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Dst_Unmute(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Dst_Activate(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Dst_Deactivate(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);

__STATIC_INLINE uint8_t Cy_Mixer_Dst_GetUsedFifoEntries(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);
__STATIC_INLINE uint8_t Cy_Mixer_Dst_GetFifoReadPtr(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);
__STATIC_INLINE uint8_t Cy_Mixer_Dst_GetFifoWritePtr(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);

__STATIC_INLINE uint32_t Cy_Mixer_Dst_FifoReadData(volatile stc_MIXER_MIXER_DST_STRUCT_t * base);

__STATIC_INLINE void Cy_Mixer_Dst_ClearInterrupt(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, cy_en_mixer_dst_interrupt_t intSrc);
__STATIC_INLINE void Cy_Mixer_Dst_SetInterrupt(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, cy_en_mixer_dst_interrupt_t intSrc);
__STATIC_INLINE void Cy_Mixer_Dst_ClearInterruptMask(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, cy_en_mixer_dst_interrupt_t intSrc);
__STATIC_INLINE void Cy_Mixer_Dst_SetInterruptMask(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, cy_en_mixer_dst_interrupt_t intSrc);

//****************************************************************************//
// Mixer Tx Control and Status
//****************************************************************************//
__STATIC_INLINE void Cy_Mixer_Tx_Enable(volatile stc_MIXER_MIXER_TX_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Tx_Disable(volatile stc_MIXER_MIXER_TX_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Tx_WordSize(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_en_mixer_tx_wd_size_t wdSize);
__STATIC_INLINE void Cy_Mixer_Tx_Format(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_en_mixer_tx_fmt_t format);
__STATIC_INLINE void Cy_Mixer_Tx_SelectMode(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_en_mixer_tx_mode_t mode);

__STATIC_INLINE void Cy_Mixer_Tx_ClockDivider(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, uint8_t clkDiv);
__STATIC_INLINE void Cy_Mixer_Tx_ClockSelect(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_en_mixer_tx_clk_sel_t clkSel);
__STATIC_INLINE void Cy_Mixer_Tx_ClockPolarity(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, bool polarity);
__STATIC_INLINE void Cy_Mixer_Tx_WordSelectPolarity(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, bool polarity);
__STATIC_INLINE void Cy_Mixer_Tx_ChannelEnable(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_en_mixer_channel_t channel);
__STATIC_INLINE void Cy_Mixer_Tx_ChannelDisable(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_en_mixer_channel_t channel);
__STATIC_INLINE void Cy_Mixer_Tx_ChannelSize(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, uint8_t chSize);

__STATIC_INLINE void Cy_Mixer_Tx_Mute(volatile stc_MIXER_MIXER_TX_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Tx_Unmute(volatile stc_MIXER_MIXER_TX_STRUCT_t * base);
__STATIC_INLINE void Cy_Mixer_Tx_ActivateTransmitter(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, bool state);
__STATIC_INLINE void Cy_Mixer_Tx_Replay(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, bool state);

__STATIC_INLINE void Cy_Mixer_Tx_ClearInterrupt(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_stc_mixer_tx_int_src_t intSrc);
__STATIC_INLINE void Cy_Mixer_Tx_SetInterrupt(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_stc_mixer_tx_int_src_t intSrc);
__STATIC_INLINE void Cy_Mixer_Tx_ClearInterruptMask(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_stc_mixer_tx_int_src_t intSrc);
__STATIC_INLINE void Cy_Mixer_Tx_SetInterruptMask(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_stc_mixer_tx_int_src_t intSrc);

//****************************************************************************//
// Mixer Source Control and Status
//****************************************************************************//

/*! \fn Cy_Mixer_Src_SampleFreqRatio
    \brief Source sample frequency upscale ratio
    \param mixer instance base
    \param fsRatio based on cy_en_mixer_src_fs_ratio_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_SampleFreqRatio(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_src_fs_ratio_t fsRatio)
{
    base->unSRC_CTL.stcField.u3FS_RATIO = fsRatio;
}

/*! \fn Cy_Mixer_Src_ChannelSelect
    \brief Channel selection, specifies selection of the channel's 16-biut PCM data from source FIFO data[31:0]
    \param mixer instance base
    \param data based on cy_en_mixer_src_data_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_ChannelSelect(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_channel_t channel, cy_en_mixer_src_data_t data)
{
    switch(channel)
    {
    case CY_MIXER_CHANNEL0:
      base->unSRC_CTL.stcField.u2CH0_SEL = data;
      break;
    case CY_MIXER_CHANNEL1:
      base->unSRC_CTL.stcField.u2CH1_SEL = data;
      break;
    default:
      break;    
    }
}

/*! \fn Cy_Mixer_Src_Enable
    \brief Mixer source enable
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_Enable(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    base->unSRC_CTL.stcField.u1ENABLED = true;
}

/*! \fn Cy_Mixer_Src_Disable
    \brief Mixer source disable
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_Disable(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    base->unSRC_CTL.stcField.u1ENABLED = false;
}

/*! \fn Cy_Mixer_Src_GetCurrentPhase
    \brief Source current FIR phase value. A upscale ratio of "n" uses a n polyphase FIR filter. 
    \brief The phases are numbered [0, n-1].
    \param mixer instance base
    \return uint8_t 0 or 1 or 11 are valid values
*/
__STATIC_INLINE uint8_t Cy_Mixer_Src_GetCurrentPhase(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    return(base->unSRC_STATUS.stcField.u4PHASE);
}

/*! \fn Cy_Mixer_Src_FadeControl
    \brief Mixer source gain code in the range [0, 115]
    \param mixer instance base
    \param fadeCode based on cy_en_mixer_fade_code_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_FadeControl(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_fade_code_t fadeCode)
{
    base->unSRC_FADE_CTL.stcField.u7CODE = fadeCode;
}

/*! \fn Cy_Mixer_Src_GetCurrentPace
    \brief Current source fading pace counter value. SRC_FADE_CTL.PACE value of "n" reuses a specific fade value "n+1" times.
    \param mixer instance base
    \return none
*/
__STATIC_INLINE uint16_t Cy_Mixer_Src_GetCurrentPace(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    return(base->unSRC_FADE_STATUS.stcField.u10PACE);
}

/*! \fn Cy_Mixer_Src_FadeInEnable
    \brief Mixer source fade in enable (SW sets this field to '1' to start "fade in" functionality. 
    \brief HW clears this field to '0' to indicate that "fade in" has completed)
    FADE_IN and FADE_OUT should be used mutually exclusively. However, if "fade in" is desired while "fading out", SW can set 
    FADE_IN to '1' and clear FADE_OUT to '0'. "Fade in" will commence from the current CODE value. Similarly,  if "fade out" is 
    desired while "fading in", SW can set FADE_OUT to '1' and clear FADE_IN to '0'. "Fade out" will commence from the current CODE value. 
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_FadeInEnable(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    base->unSRC_FADE_CMD.stcField.u1FADE_IN = true;
}

/*! \fn Cy_Mixer_Src_FadeInDisable
    \brief Mixer source fade in disable
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_FadeInDisable(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    base->unSRC_FADE_CMD.stcField.u1FADE_IN = false;
}

/*! \fn Cy_Mixer_Src_FadeOutEnable
    \brief Mixer source fade out enable
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_FadeOutEnable(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    base->unSRC_FADE_CMD.stcField.u1FADE_OUT = true;
}

/*! \fn Cy_Mixer_Src_FadeOutDisable
    \brief Mixer source fade out disable
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_FadeOutDisable(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    base->unSRC_FADE_CMD.stcField.u1FADE_OUT = false;
}

/*! \fn Cy_Mixer_Src_AutoFadeActivate
    \brief Mixer source fade out activated
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_AutoFadeActivate(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    base->unSRC_FADE_CMD.stcField.u1AUTO_DEACTIVATE = false;
}

/*! \fn Cy_Mixer_Src_AutoFadeDeactivate
    \brief Mixer source fade out de-activated
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_AutoFadeDeactivate(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    base->unSRC_FADE_CMD.stcField.u1AUTO_DEACTIVATE = true;
}

/*! \fn Cy_Mixer_Src_FadePaceSelect
    \brief Specifies the pace/speed of source "fade in" and "fade out"
    \param mixer instance base
    \param pace (10-bit value)
           "0": The same CODE value is used (0+1) times, 
           "1": The same CODE value is used (1+1) times.
           ...
           "1023": The same CODE value is used (1023+1) times.
            A fade in from "mute" to 0 dB takes 1024*116 = 118,784 PCM samples. At a PCM sample frequency 
            Fs of 48 kHz, this translates into 118,784/48,000 = 2.474 seconds.
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_FadePaceSelect(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, uint16_t pace)
{
    base->unSRC_FADE_CMD.stcField.u10PACE = (pace & 0x3FF);
}

/*! \fn Cy_Mixer_Src_GainCodeSelect
    \brief Source gain code in the range [0, 127]. Each gain code increment represents 1 dB. Gain code value "0" 
    \brief represents digital mute. Gain code "127" represents a maximum amplification of 12 dB.
    \param mixer instance base
    \param code (7-bit value)
           "0": digital mute. Multiplier value is "0" and "shift" is "26".
           "1": -114 dB. Multiplier value is "134" and "shift" is "26".
           "2": -113 dB. Multiplier value is "150" and "shift" is "26".
           "3": -112 dB. Multiplier value is "169" and "shift" is "26".
           ...
           "115": 0 dB. Multiplier value is "4096" and "shift" is "12". Note that (4096 * x) >> 12 = x; i.e. the PCM value is unaffected.
           ...
           "121": 6 dB. Multiplier value is "8173" and "shift" is "12".
           ...
           "127": 12 dB. Multiplier value is "8153" and "shift" is "11".
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_GainCodeSelect(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, uint8_t code)
{
    base->unSRC_GAIN_CTL.stcField.u7CODE = (code & 0x7F);
}

/*! \fn Cy_Mixer_Src_FifoTriggerLevel
    \brief Source FIFO trigger level. When the source FIFO has less entries than the number of this field, a transmitter trigger event is generated:
    \param mixer instance base
    \param pace (7-bit value) (INTR_SRC.FIFO_TRIGGER = (# FIFO entries < TRIGGER_LEVEL))
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_FifoTriggerLevel(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, uint8_t level)
{
    base->unSRC_FIFO_CTL.stcField.u7TRIGGER_LEVEL = (level & 0x7F);
}

/*! \fn Cy_Mixer_Src_Mute
    \brief Mixer source mute
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_Mute(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    base->unSRC_FIFO_CTL.stcField.u1MUTE = true;
}

/*! \fn Cy_Mixer_Src_Unmute
    \brief Mixer source unmute
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_Unmute(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    base->unSRC_FIFO_CTL.stcField.u1MUTE = false;
}

/*! \fn Cy_Mixer_Src_Activate
    \brief Mixer source activate
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_Activate(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    base->unSRC_FIFO_CTL.stcField.u1ACTIVE = true;
}

/*! \fn Cy_Mixer_Src_Deactivate
    \brief Mixer source de-activate
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_Deactivate(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    base->unSRC_FIFO_CTL.stcField.u1ACTIVE = false;
}

/*! \fn Cy_Mixer_Src_GetUsedFifoEntries
    \brief Number of used/occupied entries in the source FIFO. The field value is in the range [0, 128]. 
    \brief When "0", the FIFO is empty. When "128", the FIFO is full.
    \param mixer instance base
    \return uint8_t value
*/
__STATIC_INLINE uint8_t Cy_Mixer_Src_GetUsedFifoEntries(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    return (base->unSRC_FIFO_STATUS.stcField.u8USED);
}

/*! \fn Cy_Mixer_Src_GetFifoReadPtr
    \brief Source FIFO read pointer: Source FIFO location from which a data is read.
    \param mixer instance base
    \return uint8_t read pointer value
*/
__STATIC_INLINE uint8_t Cy_Mixer_Src_GetFifoReadPtr(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    return (uint8_t)(base->unSRC_FIFO_STATUS.stcField.u7RD_PTR);
}

/*! \fn Cy_Mixer_Src_GetFifoWritePtr
    \brief Source FIFO write pointer: Source FIFO location at which a new data is written by the hardware.
    \param mixer instance base
    \return uint8_t write pointer value
*/
__STATIC_INLINE uint8_t Cy_Mixer_Src_GetFifoWritePtr(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base)
{
    return (uint8_t)(base->unSRC_FIFO_STATUS.stcField.u7WR_PTR);
}

/*! \fn Cy_Mixer_Src_FifoWriteData
    \brief Data (PCM sample pair of two 16-bit samples) written to the top source FIFO entry (data[31:0] = DATA[31:0]). 
    \brief Typically, DATA[15:0] is used for channel 0 and DATA[31:16] is used for channel 1. Writing adds the data to 
    \brief the source FIFO; i.e. behavior is similar to that of a PUSH operation
    \param mixer instance base
    \param 32-bit data
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_FifoWriteData(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, uint32_t data)
{
    base->unSRC_FIFO_WR.stcField.u32DATA  = data;
}

/*! \fn Cy_Mixer_Src_ClearInterrupt
    \brief Source interrupt clear (HW sets and SW clears)
    \param mixer instance base
    \param intSrc based on cy_en_mixer_src_interrupt_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_ClearInterrupt(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_src_interrupt_t intSrc)
{
    switch(intSrc)
    {
    case CY_MIXER_SRC_FIFO_TRIGGER:
        // HW sets this field to '1', when a source trigger is generated. 
        base->unINTR_SRC.stcField.u1FIFO_TRIGGER = true;
        break;
    case CY_MIXER_SRC_FIFO_OVERFLOW:
        // HW sets this field to '1', when writing to a full source FIFO (SRC_FIFO_STATUS.USED is "128").
        base->unINTR_SRC.stcField.u1FIFO_OVERFLOW = true;
        break;
    case CY_MIXER_SRC_FADE_OUT:
        // HW sets this field to '1', when fade out has completed (HW changes SRC_FADE_CMD.FADE_OUT from "0" to "1").
        base->unINTR_SRC.stcField.u1FADED_OUT = true;
        break;
    default:      
        break;
    }
}

/*! \fn Cy_Mixer_Src_SetInterrupt
    \brief Source interrupt set (Write this field with '1' to set corresponding INTR_SRC field)
    \param mixer instance base
    \param intSrc based on cy_en_mixer_src_interrupt_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_SetInterrupt(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_src_interrupt_t intSrc)
{
    switch(intSrc)
    {
    case CY_MIXER_SRC_FIFO_TRIGGER:
        base->unINTR_SRC_SET.stcField.u1FIFO_TRIGGER = true;
        break;
    case CY_MIXER_SRC_FIFO_OVERFLOW:
        base->unINTR_SRC_SET.stcField.u1FIFO_OVERFLOW = true;
        break;
    case CY_MIXER_SRC_FADE_OUT:
        base->unINTR_SRC_SET.stcField.u1FADED_OUT = true;
        break;
    default:      
        break;
    }
}

/*! \fn Cy_Mixer_Src_ClearInterruptMask
    \brief Source interrupt clear Mask for corresponding field in INTR_SRC register.
    \param mixer instance base
    \param intSrc based on cy_en_mixer_src_interrupt_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_ClearInterruptMask(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_src_interrupt_t intSrc)
{
    switch(intSrc)
    {
    case CY_MIXER_SRC_FIFO_TRIGGER:
        base->unINTR_SRC_MASK.stcField.u1FIFO_TRIGGER = false;
        break;
    case CY_MIXER_SRC_FIFO_OVERFLOW:
        base->unINTR_SRC_MASK.stcField.u1FIFO_OVERFLOW = false;
        break;
    case CY_MIXER_SRC_FADE_OUT:
        base->unINTR_SRC_MASK.stcField.u1FADED_OUT = false;
        break;
    default:      
        break;
    }
}

/*! \fn Cy_Mixer_Src_SetInterruptMask
    \brief Source interrupt set Mask for corresponding field in INTR_SRC register.
    \param mixer instance base
    \param intSrc based on cy_en_mixer_src_interrupt_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Src_SetInterruptMask(volatile stc_MIXER_MIXER_SRC_STRUCT_t * base, cy_en_mixer_src_interrupt_t intSrc)
{
    switch(intSrc)
    {
    case CY_MIXER_SRC_FIFO_TRIGGER:
        base->unINTR_SRC_MASK.stcField.u1FIFO_TRIGGER = true;
        break;
    case CY_MIXER_SRC_FIFO_OVERFLOW:
        base->unINTR_SRC_MASK.stcField.u1FIFO_OVERFLOW = true;
        break;
    case CY_MIXER_SRC_FADE_OUT:
        base->unINTR_SRC_MASK.stcField.u1FADED_OUT = true;
        break;
    default:      
        break;
    }
}

//****************************************************************************//
// Mixer Destination Control and Status
//****************************************************************************//

/*! \fn Cy_Mixer_Dst_Enable
    \brief Mixer destination enable
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_Enable(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    base->unDST_CTL.stcField.u1ENABLED = true;
}

/*! \fn Cy_Mixer_Dst_Disable
    \brief Mixer destination disable
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_Disable(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    base->unDST_CTL.stcField.u1ENABLED = false;
}

/*! \fn Cy_Mixer_Dst_FadeControl
    \brief Destination fade control (Gain code in the range [0, 115])
    \param mixer instance base
    \param fadeCode based on cy_en_mixer_fade_code_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_FadeControl(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, cy_en_mixer_fade_code_t fadeCode)
{
    base->unDST_FADE_CTL.stcField.u7CODE = fadeCode;
}

/*! \fn Cy_Mixer_Dst_GetCurrentPace
    \brief Destination current fading pace counter value. DST_FADE_CTL.PACE value of "n" reuses a specific fade value "n+1" times.
    \param mixer instance base
    \return none
*/
__STATIC_INLINE uint16_t Cy_Mixer_Dst_GetCurrentPace(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    return(base->unDST_FADE_STATUS.stcField.u10PACE);
}

/*! \fn Cy_Mixer_Dst_FadeInEnable
    \brief Mixer destination fade in enable (SW sets this field to '1' to start "fade in" functionality. 
    \brief HW clears this field to '0' to indicate that "fade in" has completed)
    FADE_IN and FADE_OUT should be used mutually exclusively. However, if "fade in" is desired while "fading out", SW can set 
    FADE_IN to '1' and clear FADE_OUT to '0'. "Fade in" will commence from the current CODE value. Similarly,  if "fade out" is 
    desired while "fading in", SW can set FADE_OUT to '1' and clear FADE_IN to '0'. "Fade out" will commence from the current CODE value. 
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_FadeInEnable(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    base->unDST_FADE_CMD.stcField.u1FADE_IN = true;
}

/*! \fn Cy_Mixer_Dst_FadeInDisable
    \brief Mixer destination fade in disable
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_FadeInDisable(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    base->unDST_FADE_CMD.stcField.u1FADE_IN = false;
}

/*! \fn Cy_Mixer_Dst_FadeOutEnable
    \brief Mixer destination fade out enable
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_FadeOutEnable(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    base->unDST_FADE_CMD.stcField.u1FADE_OUT = true;
}

/*! \fn Cy_Mixer_Dst_FadeOutDisable
    \brief Mixer destination fade out disable
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_FadeOutDisable(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    base->unDST_FADE_CMD.stcField.u1FADE_OUT = false;
}

/*! \fn Cy_Mixer_Dst_AutoFadeActivate
    \brief Mixer destination fade out activated
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_AutoFadeActivate(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    base->unDST_FADE_CMD.stcField.u1AUTO_DEACTIVATE = false;
}

/*! \fn Cy_Mixer_Dst_AutoFadeDeactivate
    \brief Mixer destination fade out de-activated
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_AutoFadeDeactivate(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    base->unDST_FADE_CMD.stcField.u1AUTO_DEACTIVATE = true;
}

/*! \fn Cy_Mixer_Dst_FadePaceSelect
    \brief Destination fade pace select (Specifies the pace/speed of "fade in" and "fade out")
    \param mixer instance base
    \param pace (10-bit value)
           "0": The same CODE value is used (0+1) times, 
           "1": The same CODE value is used (1+1) times.
           ...
           "1023": The same CODE value is used (1023+1) times.
            A fade in from "mute" to 0 dB takes 1024*116 = 118,784 PCM samples. At a PCM sample frequency 
            Fs of 48 kHz, this translates into 118,784/48,000 = 2.474 seconds.
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_FadePaceSelect(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, uint16_t pace)
{
    base->unDST_FADE_CMD.stcField.u10PACE = (pace & 0x3FF);
}

/*! \fn Cy_Mixer_Dst_GainCodeSelect
    \brief Destination gain code in the range [0, 127]. Each gain code increment represents 1 dB. Gain code value "0" 
    \brief represents digital mute. Gain code "127" represents a maximum amplification of 12 dB.
    \param mixer instance base
    \param code (7-bit value)
           "0": digital mute. Multiplier value is "0" and "shift" is "26".
           "1": -114 dB. Multiplier value is "134" and "shift" is "26".
           "2": -113 dB. Multiplier value is "150" and "shift" is "26".
           "3": -112 dB. Multiplier value is "169" and "shift" is "26".
           ...
           "115": 0 dB. Multiplier value is "4096" and "shift" is "12". Note that (4096 * x) >> 12 = x; i.e. the PCM value is unaffected.
           ...
           "121": 6 dB. Multiplier value is "8173" and "shift" is "12".
           ...
           "127": 12 dB. Multiplier value is "8153" and "shift" is "11".
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_GainCodeSelect(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, uint8_t code)
{
    base->unDST_GAIN_CTL.stcField.u7CODE = code;
}

/*! \fn Cy_Mixer_Dst_FifoTriggerLevel
    \brief Destination FIFO trigger level. When the destination FIFO has less entries than the number of this field, 
    \brief a transmitter trigger event is generated:
    \param mixer instance base
    \param pace (7-bit value) (INTR_SRC.FIFO_TRIGGER = (# FIFO entries < TRIGGER_LEVEL))
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_FifoTriggerLevel(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, uint8_t level)
{
    base->unDST_FIFO_CTL.stcField.u6TRIGGER_LEVEL = (level & 0x3F);
}

/*! \fn Cy_Mixer_Dst_Mute
    \brief Mixer destination mute
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_Mute(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    base->unDST_FIFO_CTL.stcField.u1MUTE = true;
}

/*! \fn Cy_Mixer_Dst_Unmute
    \brief Mixer destination unmute
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_Unmute(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    base->unDST_FIFO_CTL.stcField.u1MUTE = false;
}

/*! \fn Cy_Mixer_Dst_Activate
    \brief Mixer destination activate
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_Activate(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    base->unDST_FIFO_CTL.stcField.u1ACTIVE = true;
}

/*! \fn Cy_Mixer_Dst_Deactivate
    \brief Mixer destination de-activate
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_Deactivate(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    base->unDST_FIFO_CTL.stcField.u1ACTIVE = false;
}

/*! \fn Cy_Mixer_Dst_GetUsedFifoEntries
    \brief Number of used/occupied entries in the destination FIFO. The field value is in the range [0, 128]. 
    \brief When "0", the FIFO is empty. When "128", the FIFO is full.
    \param mixer instance base
    \return uint8_t value
*/
__STATIC_INLINE uint8_t Cy_Mixer_Dst_GetUsedFifoEntries(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    return (base->unDST_FIFO_STATUS.stcField.u7USED);
}

/*! \fn Cy_Mixer_Dst_GetFifoReadPtr
    \brief Destination FIFO read pointer: Destination FIFO location from which a data is read.
    \param mixer instance base
    \return uint8_t read pointer value
*/
__STATIC_INLINE uint8_t Cy_Mixer_Dst_GetFifoReadPtr(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    return (uint8_t)(base->unDST_FIFO_STATUS.stcField.u6RD_PTR);
}

/*! \fn Cy_Mixer_Dst_GetFifoWritePtr
    \brief Destination FIFO write pointer: Destination FIFO location at which a new data is written by the hardware.
    \param mixer instance base
    \return uint8_t write pointer value
*/
__STATIC_INLINE uint8_t Cy_Mixer_Dst_GetFifoWritePtr(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    return (uint8_t)(base->unDST_FIFO_STATUS.stcField.u6WR_PTR);
}

/*! \fn Cy_Mixer_Dst_FifoReadData
    \brief Data (PCM sample pair of two 16-bit samples) read to the top destination FIFO entry (data[31:0] = DATA[31:0]). 
    \brief  Reading removes the data from the destination FIFO; i.e. behavior is similar to that of a POP operation 
    \brief (DST_FIFO_STATUS.RD_PTR is incremented and DST_FIFO_STATUS.USED is decremented).
    \param mixer instance base
    \param 32-bit data
    \return none
*/
__STATIC_INLINE uint32_t Cy_Mixer_Dst_FifoReadData(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    return(base->unDST_FIFO_RD.stcField.u32DATA);
}

/*! \fn Cy_Mixer_Dst_ClearInterrupt
    \brief Destination interrupt clear (HW sets and SW clears)
    \param mixer instance base
    \param intSrc based on cy_en_mixer_dst_interrupt_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_ClearInterrupt(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, cy_en_mixer_dst_interrupt_t intSrc)
{
    switch(intSrc)
    {
    case CY_MIXER_DST_FIFO_TRIGGER:
        base->unINTR_DST.stcField.u1FIFO_TRIGGER = true;
        break;
    case CY_MIXER_DST_FIFO_OVERFLOW:
        base->unINTR_DST.stcField.u1FIFO_UNDERFLOW = true;
        break;
    case CY_MIXER_DST_FADE_OUT:
        base->unINTR_DST.stcField.u1FADED_OUT = true;
        break;
    default:      
        break;
    }
}

/*! \fn Cy_Mixer_Dst_SetInterrupt
    \brief Destination interrupt set (HW sets and SW clears)
    \param mixer instance base
    \param intSrc based on cy_en_mixer_dst_interrupt_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_SetInterrupt(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, cy_en_mixer_dst_interrupt_t intSrc)
{
    switch(intSrc)
    {
    case CY_MIXER_DST_FIFO_TRIGGER:
        base->unINTR_DST_SET.stcField.u1FIFO_TRIGGER = true;
        break;
    case CY_MIXER_DST_FIFO_OVERFLOW:
        base->unINTR_DST_SET.stcField.u1FIFO_UNDERFLOW = true;
        break;
    case CY_MIXER_DST_FADE_OUT:
        base->unINTR_DST_SET.stcField.u1FADED_OUT = true;
        break;
    default:      
        break;
    }
}

/*! \fn Cy_Mixer_Dst_ClearInterruptMask
    \brief Destination interrupt mask clear (HW sets and SW clears)
    \param mixer instance base
    \param intSrc based on cy_en_mixer_dst_interrupt_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_ClearInterruptMask(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, cy_en_mixer_dst_interrupt_t intSrc)
{
    switch(intSrc)
    {
    case CY_MIXER_DST_FIFO_TRIGGER:
        base->unINTR_DST_MASK.stcField.u1FIFO_TRIGGER = false;
        break;
    case CY_MIXER_DST_FIFO_OVERFLOW:
        base->unINTR_DST_MASK.stcField.u1FIFO_UNDERFLOW = false;
        break;
    case CY_MIXER_DST_FADE_OUT:
        base->unINTR_DST_MASK.stcField.u1FADED_OUT = false;
        break;
    default:      
        break;
    }
}	

/*! \fn Cy_Mixer_Dst_SetInterruptMask
    \brief Destination interrupt mask set (HW sets and SW clears)
    \param mixer instance base
    \param intSrc based on cy_en_mixer_dst_interrupt_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Dst_SetInterruptMask(volatile stc_MIXER_MIXER_DST_STRUCT_t * base, cy_en_mixer_dst_interrupt_t intSrc)
{
    switch(intSrc)
    {
    case CY_MIXER_DST_FIFO_TRIGGER:
        base->unINTR_DST_MASK.stcField.u1FIFO_TRIGGER = true;
        break;
    case CY_MIXER_DST_FIFO_OVERFLOW:
        base->unINTR_DST_MASK.stcField.u1FIFO_UNDERFLOW = true;
        break;
    case CY_MIXER_DST_FADE_OUT:
        base->unINTR_DST_MASK.stcField.u1FADED_OUT = true;
        break;
    default:      
        break;
    }
}

__STATIC_INLINE bool Cy_Mixer_Dst_IsTriggerInterrupt(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    return(base->unINTR_DST.stcField.u1FIFO_TRIGGER == 1ul);
}

__STATIC_INLINE bool Cy_Mixer_Dst_IsUnderflowInterrupt(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    return(base->unINTR_DST.stcField.u1FIFO_UNDERFLOW == 1ul);
}

__STATIC_INLINE bool Cy_Mixer_Dst_IsFadeOutInterrupt(volatile stc_MIXER_MIXER_DST_STRUCT_t * base)
{
    return(base->unINTR_DST.stcField.u1FADED_OUT == 1ul);
}

//****************************************************************************//
// Mixer Tx Control and Status
//****************************************************************************//

/*! \fn Cy_Mixer_Tx_Enable
    \brief Enables Mixer Transmit
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_Enable(volatile stc_MIXER_MIXER_TX_STRUCT_t * base)
{
    base->unTX_CTL.stcField.u1ENABLED = true;
}

/*! \fn Cy_Mixer_Tx_Enable
    \brief Enables Mixer Transmit
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_Disable(volatile stc_MIXER_MIXER_TX_STRUCT_t * base)
{
    base->unTX_CTL.stcField.u1ENABLED = false;
}

/*! \fn Cy_Mixer_Tx_WordSize
    \brief Mixer Transmit word size update
    \param mixer instance base
    \param word size based on cy_en_mixer_tx_wd_size_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_WordSize(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_en_mixer_tx_wd_size_t wdSize)
{
    base->unTX_CTL.stcField.u4WORD_SIZE = wdSize;
}

/*! \fn Cy_Mixer_Tx_Format
    \brief Mixer Transmit I2S format
    \param mixer instance base
    \param format based on cy_en_mixer_tx_fmt_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_Format(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_en_mixer_tx_fmt_t format)
{
    base->unTX_CTL.stcField.u2FORMAT = format;
}

/*! \fn Cy_Mixer_Tx_SelectMode
    \brief Mixer Transmit Mode Select
    \param mixer instance base
    \param mode based on cy_en_mixer_tx_mode_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_SelectMode(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_en_mixer_tx_mode_t mode)
{
    base->unTX_CTL.stcField.u1MS = mode;
}

/*! \fn Cy_Mixer_Tx_ClockDivider
    \brief Mixer Transmit Clock divider slection
    \param mixer instance base
    \param Clock divider value [1...255] 0->DIV_BY_1, 255->DIV_BY_256
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_ClockDivider(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, uint8_t clkDiv)
{
    base->unTX_IF_CTL.stcField.u8CLOCK_DIV = clkDiv;
}

/*! \fn Cy_Mixer_Tx_ClockSelect
    \brief Mixer Transmit Clock Select
    \param mixer instance base
    \param clkSel based on cy_en_mixer_tx_clk_sel_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_ClockSelect(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_en_mixer_tx_clk_sel_t clkSel)
{
    base->unTX_IF_CTL.stcField.u3CLOCK_SEL = clkSel;
}

/*! \fn Cy_Mixer_Tx_ClockPolarity
    \brief Sets Mixer transmit clock polarity
    \param mixer instance base
    \param polarity either true (inverted) or false
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_ClockPolarity(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, bool polarity)
{
    base->unTX_IF_CTL.stcField.u1SCK_POLARITY = polarity;
}

/*! \fn Cy_Mixer_Tx_WordSelectPolarity
    \brief Sets Mixer transmit word select polarity
    \param mixer instance base
    \param polarity either true (inverted) or false
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_WordSelectPolarity(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, bool polarity)
{
    base->unTX_IF_CTL.stcField.u1WS_POLARITY = polarity;
}

/*! \fn Cy_Mixer_Tx_ChannelEnable
    \brief Enables the selected Mixer channel
    \param mixer instance base
    \param channel based on cy_en_mixer_channel_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_ChannelEnable(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_en_mixer_channel_t channel)
{
    if(channel == CY_MIXER_CHANNEL0)
    {
        base->unTX_IF_CTL.stcField.u1CH0_EN = true;
    }
    else // (channel == CY_MIXER_CHANNEL1)
    {
        base->unTX_IF_CTL.stcField.u1CH1_EN = true;
    }
}

/*! \fn Cy_Mixer_Tx_ChannelDisable
    \brief Disables the selected Mixer channel
    \param mixer instance base
    \param channel based on cy_en_mixer_channel_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_ChannelDisable(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_en_mixer_channel_t channel)
{
    if(channel == CY_MIXER_CHANNEL0)
    {
        base->unTX_IF_CTL.stcField.u1CH0_EN = false;
    }
    else // (channel == CY_MIXER_CHANNEL1)
    {
        base->unTX_IF_CTL.stcField.u1CH1_EN = false;
    }
}

/*! \fn Cy_Mixer_Tx_ChannelSize
    \brief Mixer Transmit Channel Size
    \param mixer instance base
    \param chSize divider value [1...31] 0->SIZE_1, 31->SIZE_32
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_ChannelSize(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, uint8_t chSize)
{
    base->unTX_IF_CTL.stcField.u5CH_SIZE = (chSize & 0x1F);
}

/*! \fn Cy_Mixer_Tx_Mute
    \brief Mixer Transmit Mute (HW uses a constant PCM data value of "0". Mute does advance the FIFO read pointer.)
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_Mute(volatile stc_MIXER_MIXER_TX_STRUCT_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1MUTE = true;
}

/*! \fn Cy_Mixer_Tx_Unmute
    \brief Mixer Transmit unmute (HW uses destination (TX) FIFO data)
    \param mixer instance base
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_Unmute(volatile stc_MIXER_MIXER_TX_STRUCT_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1MUTE = false;
}

/*! \fn Cy_Mixer_Tx_ActivateTransmitter
    \brief Mixer Activate or Deactivate transmitter
    \param mixer instance base
    \param state true->transmitter on, false->transmitter off
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_ActivateTransmitter(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, bool state)
{
    if(state == true)
    {
        base->unTX_FIFO_CTL.stcField.u1ACTIVE = true;
    }
    else // (state == false)
    {
        base->unTX_FIFO_CTL.stcField.u1ACTIVE = false;
    }
}

/*! \fn Cy_Mixer_Tx_Replay
    \brief Mixer replay control
    \param mixer instance base
    \param state true->replay on, false->replay off
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_Replay(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, bool state)
{
    if(state == true)
    {
        base->unTX_FIFO_CTL.stcField.u1REPLAY = true;
    }
    else // (state == false)
    {
        base->unTX_FIFO_CTL.stcField.u1REPLAY = false;
    }
}
  
/*! \fn Cy_Mixer_Tx_ClearInterrupt
    \brief Mixer Tx Interrupt Clear
    \param mixer instance base
    \param interrupt source based on cy_stc_mixer_tx_int_src_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_ClearInterrupt(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_stc_mixer_tx_int_src_t intSrc)
{
    switch(intSrc)
    {
    case CY_MIXER_TX_FIFO_UNDERFLOW:
        base->unINTR_TX.stcField.u1FIFO_UNDERFLOW = false;
        break;
    case CY_MIXER_TX_IFC_UNDERFLOW:
        base->unINTR_TX.stcField.u1IF_UNDERFLOW = false;
        break;
    default:      
        break;
    }
}

/*! \fn Cy_Mixer_Tx_SetInterrupt
    \brief Mixer Tx Interrupt Set
    \param mixer instance base
    \param interrupt source based on cy_stc_mixer_tx_int_src_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_SetInterrupt(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_stc_mixer_tx_int_src_t intSrc)
{
    switch(intSrc)
    {
    case CY_MIXER_TX_FIFO_UNDERFLOW:
        base->unINTR_TX_SET.stcField.u1FIFO_UNDERFLOW = true;
        break;
    case CY_MIXER_TX_IFC_UNDERFLOW:
        base->unINTR_TX_SET.stcField.u1IF_UNDERFLOW = true;
        break;
    default:      
        break;
    }
}

/*! \fn Cy_Mixer_Tx_ClearInterruptMask
    \brief Mixer Tx Interrupt Mask Clear
    \param mixer instance base
    \param interrupt source based on cy_stc_mixer_tx_int_src_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_ClearInterruptMask(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_stc_mixer_tx_int_src_t intSrc)
{
    switch(intSrc)
    {
    case CY_MIXER_TX_FIFO_UNDERFLOW:
        base->unINTR_TX_MASK.stcField.u1FIFO_UNDERFLOW = false;
        break;
    case CY_MIXER_TX_IFC_UNDERFLOW:
        base->unINTR_TX_MASK.stcField.u1IF_UNDERFLOW = false;
        break;
    default:      
        break;
    }
}

/*! \fn Cy_Mixer_Tx_SetInterruptMask
    \brief Mixer Tx Interrupt Mask Set
    \param mixer instance base
    \param interrupt source based on cy_stc_mixer_tx_int_src_t
    \return none
*/
__STATIC_INLINE void Cy_Mixer_Tx_SetInterruptMask(volatile stc_MIXER_MIXER_TX_STRUCT_t * base, cy_stc_mixer_tx_int_src_t intSrc)
{
    switch(intSrc)
    {
    case CY_MIXER_TX_FIFO_UNDERFLOW:
        base->unINTR_TX_MASK.stcField.u1FIFO_UNDERFLOW = true;
        break;
    case CY_MIXER_TX_IFC_UNDERFLOW:
        base->unINTR_TX_MASK.stcField.u1IF_UNDERFLOW = true;
        break;
    default:      
        break;
    }
}

/** \} group_mixer_functions */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* CY_IP_MXMIXER */

#endif /* __CY_MIXER_H__ */

/** \} group_mixer */


/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
