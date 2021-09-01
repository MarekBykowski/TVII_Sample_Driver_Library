/*******************************************************************************
* \file cy_dac.h
* \version 1.0
*
* Provides an API declaration of the audio dac driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_audiodac Audio DAC (DAC)
* \{
* This driver provides global DAC defines and API function definitions.
*
* \defgroup group_audiodac_macros Macro
* \defgroup group_audiodac_functions Functions
* \defgroup group_audiodac_data_structures Data structures
* \defgroup group_audiodac_enums Enumerated types
*/

#if !defined(__CY_AUDIODAC_H__)
#define __CY_AUDIODAC_H__

#include "cy_device_headers.h"
#include "syslib/cy_syslib.h"
#include <stdbool.h>

#ifdef CY_IP_MXS40EAUDIODAC

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
* \addtogroup group_audiodac_macros
* \{
*/

/** Driver major version */
#define CY_CPU_DRV_VERSION_MAJOR   1
/** Driver minor version */
#define CY_CPU_DRV_VERSION_MINOR   0
/** The Audio DAC driver identifier */
#define CY_AUDIODAC_ID                                  (CY_PDL_DRV_ID(0x23U))
  
/** \} group_audiodac_macros */

/**
* \addtogroup group_audiodac_enums
* \{
*/

/* Audio Dac Interface Clock Selection */
typedef enum
{
    CY_AUDIODAC_CLK_SEL_SRSS	        = 0u,	/**< Audio Dac Clock Select SRSS Internal */
    CY_AUDIODAC_CLK_SEL_IFC_OFF         = 1U,	/**< 1/3/5/6/7 Audio Dac Clock Select Interface Off */
    CY_AUDIODAC_CLK_SEL_DAC_MCK         = 4U,	/**< Audio Dac Clock Select DAC Master Clock */
} cy_en_audiodac_clk_sel_t;

/* Audio Dac Sample Frequency Selection */
typedef enum
{
    CY_AUDIODAC_FS_SEL_RESERVED	        = 0u,	/**< Audio Dac Sample Frequency RESERVED */
    CY_AUDIODAC_FS_SEL_256FS_128OSR     = 1U,	/**< Audio Dac Sample Frequency Clock 256 FS, Oversampling Rate 128 */
    CY_AUDIODAC_FS_SEL_256FS_256OSR     = 2U,	/**< Audio Dac Sample Frequency Clock 256 FS, Oversampling Rate 256 */
    CY_AUDIODAC_FS_SEL_512FS_512OSR     = 3U,	/**< Audio Dac Sample Frequency Clock 512 FS, Oversampling Rate 512 */
} cy_en_audiodac_sample_freq_sel_t;

/* Audio Dac Channel */
typedef enum
{
    CY_AUDIODAC_CHANNEL_LEFT            = 0u,	/**< AUDIO DAC Channel Left */
    CY_AUDIODAC_CHANNEL_RIGHT	        = 1U,	/**< AUDIO DAC Channel Right */
} cy_en_audiodac_channel_t;

/* Audio Dac Interrupt Sources */
typedef enum
{
    CY_AUDIODAC_FIFO_TRIGGER            =  0u,	/**< Audio Dac Fifo Trigger interrupt */
    CY_AUDIODAC_FIFO_OVERFLOW	        =  1U,	/**< Audio Dac Fifo Overflow interrupt */
    CY_AUDIODAC_FIFO_UNDERFLOW	        =  2U,	/**< Audio Dac Fifo Underflow interrupt */
    CY_AUDIODAC_FAST_RAMP_COMPLETE      = 16U,	/**< Audio Dac Fast Ramp Complete interrupt */
    CY_AUDIODAC_RAMP_COMPLETE	        = 17U,	/**< Audio Dac Ramp Complete interrupt */
} cy_stc_audiodac_int_src_t;

/* Audio Dac channel data select 
   Specifies selection of the channel's 16-bit PCM data from the source FIFO data[31:0] */
typedef enum
{
    CY_AUDIODAC_SRC_DATA_LOW            = 0u,	/**< Audio Dac source data from data[15:0] (default setting) */
    CY_AUDIODAC_SRC_DATA_HIGH	        = 1U,	/**< Audio Dac source data from data[31:16] */
} cy_en_audiodac_data_t;

/**
* Audio DAC status definitions.
*/
typedef enum 
{
    CY_AUDIODAC_SUCCESS   = 0x00UL,                                  /**< Successful. */
    CY_AUDIODAC_BAD_PARAM = CY_AUDIODAC_ID | CY_PDL_STATUS_ERROR | 0x01UL /**< One or more invalid parameters. */
} cy_en_audiodac_status_t;

/** \} group_audiodac_enums */

/**
* \addtogroup group_audiodac_data_structures
* \{
*/

/**
* Audio DAC initialization configuration.
*/
typedef struct
{
    uint8_t                             clkDiv;                 /**< Interface clock divider (legal range [0, 255]). The DAC system clock clk_dac is defined as clk_if / (CLOCK_DIV + 1) */
    cy_en_audiodac_clk_sel_t            clkSel;                 /**< Interface clock clk_if selection */
    cy_en_audiodac_sample_freq_sel_t    sampFreq;               /**< Sample frequency select */
    uint16_t                            count;                  /**< Count for 1ms with clk_timer */
    uint8_t                             fastRampCount;          /**< Fast Ramp count in ms */
    uint8_t                             compRampCount;          /**< Complete Ramp count in ms */
    uint8_t                             trgLevel;               /**< Trigger level */
} cy_stc_audiodac_config_t;

/** \} group_audiodac_data_structures */

/**
* \addtogroup group_audiodac_functions
* \{
*/

//****************************************************************************//
// Global initialization functions                                            
//****************************************************************************//
cy_en_audiodac_status_t Cy_AudioDac_Init(volatile stc_DAC_t * base, cy_stc_audiodac_config_t const * config);
void Cy_AudioDac_DeInit(volatile stc_DAC_t * base);

//****************************************************************************//
// Audio DAC Control and Status
//****************************************************************************//
__STATIC_INLINE void Cy_AudioDac_ModuleEnable(volatile stc_DAC_t * base);
__STATIC_INLINE void Cy_AudioDac_ModuleDisable(volatile stc_DAC_t * base);

__STATIC_INLINE void Cy_AudioDac_ClockDivider(volatile stc_DAC_t * base, uint8_t clkDiv);
__STATIC_INLINE void Cy_AudioDac_ClockSelect(volatile stc_DAC_t * base, cy_en_audiodac_clk_sel_t clkSel);
__STATIC_INLINE void Cy_AudioDac_SampleFreqSelect(volatile stc_DAC_t * base, cy_en_audiodac_sample_freq_sel_t freqSel);
__STATIC_INLINE void Cy_AudioDac_LeftDataNoChange(volatile stc_DAC_t * base);
__STATIC_INLINE void Cy_AudioDac_LeftDataInvert(volatile stc_DAC_t * base);
__STATIC_INLINE void Cy_AudioDac_RightDataNoChange(volatile stc_DAC_t * base);
__STATIC_INLINE void Cy_AudioDac_RightDataInvert(volatile stc_DAC_t * base);
__STATIC_INLINE void Cy_AudioDac_DataSelect(volatile stc_DAC_t * base, cy_en_audiodac_channel_t channel, cy_en_audiodac_data_t data);
__STATIC_INLINE void Cy_AudioDac_SwOverrideForFastRampEnable(volatile stc_DAC_t * base);
__STATIC_INLINE void Cy_AudioDac_SwOverrideForFastRampDisable(volatile stc_DAC_t * base);
__STATIC_INLINE void Cy_AudioDac_Enable(volatile stc_DAC_t * base);
__STATIC_INLINE void Cy_AudioDac_Disable(volatile stc_DAC_t * base);

__STATIC_INLINE void Cy_AudioDac_CountUpdate(volatile stc_DAC_t * base, uint16_t count);
__STATIC_INLINE void Cy_AudioDac_FastRampCountUpdate(volatile stc_DAC_t * base, uint8_t count);
__STATIC_INLINE void Cy_AudioDac_CompleteRampCountUpdate(volatile stc_DAC_t * base, uint8_t count);

__STATIC_INLINE bool Cy_AudioDac_IsDacBusy(volatile stc_DAC_t * base);
__STATIC_INLINE bool Cy_AudioDac_IsFastRampDone(volatile stc_DAC_t * base);
__STATIC_INLINE bool Cy_AudioDac_IsCompleteRampDone(volatile stc_DAC_t * base);

__STATIC_INLINE void Cy_AudioDac_FifoTriggerLevel(volatile stc_DAC_t * base, uint8_t level);
__STATIC_INLINE void Cy_AudioDac_Mute(volatile stc_DAC_t * base);
__STATIC_INLINE void Cy_AudioDac_Unmute(volatile stc_DAC_t * base);
__STATIC_INLINE void Cy_AudioDac_Activate(volatile stc_DAC_t * base);
__STATIC_INLINE void Cy_AudioDac_Deactivate(volatile stc_DAC_t * base);

__STATIC_INLINE uint8_t Cy_AudioDac_GetUsedFifoEntries(volatile stc_DAC_t * base);
__STATIC_INLINE uint8_t Cy_AudioDac_GetFifoReadPtr(volatile stc_DAC_t * base);
__STATIC_INLINE uint8_t Cy_AudioDac_GetFifoWritePtr(volatile stc_DAC_t * base);

__STATIC_INLINE void Cy_AudioDac_FifoWriteData(volatile stc_DAC_t * base, uint32_t data);

__STATIC_INLINE void Cy_AudioDac_ClearInterrupt(volatile stc_DAC_t * base, cy_stc_audiodac_int_src_t intSrc);
__STATIC_INLINE void Cy_AudioDac_SetInterrupt(volatile stc_DAC_t * base, cy_stc_audiodac_int_src_t intSrc);
__STATIC_INLINE void Cy_AudioDac_ClearInterruptMask(volatile stc_DAC_t * base, cy_stc_audiodac_int_src_t intSrc);
__STATIC_INLINE void Cy_AudioDac_SetInterruptMask(volatile stc_DAC_t * base, cy_stc_audiodac_int_src_t intSrc);

//****************************************************************************//
// Audio DAC Control and Status
//****************************************************************************//

/*! \fn Cy_AudioDac_ModuleEnable
    \brief Audio DAC module Enable
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_ModuleEnable(volatile stc_DAC_t * base)
{
    base->unCTL.stcField.u1ENABLED = true;
}

/*! \fn Cy_AudioDac_ModuleDisable
    \brief Audio DAC module Disable
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_ModuleDisable(volatile stc_DAC_t * base)
{
    base->unCTL.stcField.u1ENABLED = false;
}

/*! \fn Cy_AudioDac_ClockDivider
    \brief Audio DAC Transmit Clock divider slection
    \param audio dac instance base
    \param Clock divider value [1...255] 0->DIV_BY_1, 255->DIV_BY_256
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_ClockDivider(volatile stc_DAC_t * base, uint8_t clkDiv)
{
    base->unIF_CTL.stcField.u8CLOCK_DIV = clkDiv;
}

/*! \fn Cy_AudioDac_ClockSelect
    \brief Audio DAC Transmit Clock Select
    \param audio dac instance base
    \param clkSel based on cy_en_audiodac_clk_sel_t
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_ClockSelect(volatile stc_DAC_t * base, cy_en_audiodac_clk_sel_t clkSel)
{
    base->unIF_CTL.stcField.u3CLOCK_SEL = clkSel;
}

/*! \fn Cy_AudioDac_SampleFreqSelect
    \brief Audio DAC Sampling Frequency Select
    \param audio dac instance base
    \param freqSel based on cy_en_audiodac_sample_freq_sel_t
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_SampleFreqSelect(volatile stc_DAC_t * base, cy_en_audiodac_sample_freq_sel_t freqSel)
{
    base->unIF_CTL.stcField.u2FS_SEL = freqSel;
}

/*! \fn Cy_AudioDac_LeftDataNoChange
    \brief Audio DAC no change in left data
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_LeftDataNoChange(volatile stc_DAC_t * base)
{
    base->unIF_CTL.stcField.u1LDATA_POLARITY = false;
}

/*! \fn Cy_AudioDac_LeftDataInvert
    \brief Audio DAC invert left data (2's complement)
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_LeftDataInvert(volatile stc_DAC_t * base)
{
    base->unIF_CTL.stcField.u1LDATA_POLARITY = true;
}

/*! \fn Cy_AudioDac_RightDataNoChange
    \brief Audio DAC no change in right data
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_RightDataNoChange(volatile stc_DAC_t * base)
{
    base->unIF_CTL.stcField.u1RDATA_POLARITY = false;
}

/*! \fn Cy_AudioDac_RightDataInvert
    \brief Audio DAC invert right data (2's complement)
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_RightDataInvert(volatile stc_DAC_t * base)
{
    base->unIF_CTL.stcField.u1RDATA_POLARITY = true;
}

/*! \fn Cy_AudioDac_DataSelect
    \brief Channel data selection, specifies selection of the channel's 16-biut PCM data from source FIFO data[31:0]
    \param mixer instance base
    \param channel based on cy_en_audiodac_channel_t
    \param data based on cy_en_audiodac_data_t
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_DataSelect(volatile stc_DAC_t * base, cy_en_audiodac_channel_t channel, cy_en_audiodac_data_t data)
{
    switch(channel)
    {
    case CY_AUDIODAC_CHANNEL_LEFT:
      base->unIF_CTL.stcField.u1LDATA_SEL = data;
      break;
    case CY_AUDIODAC_CHANNEL_RIGHT:
      base->unIF_CTL.stcField.u1RDATA_SEL = data;
      break;
    default:
      break;    
    }
}

/*! \fn Cy_AudioDac_SwOverrideForFastRampEnable
    \brief Audio DAC SW Override Fast Ramp enable
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_SwOverrideForFastRampEnable(volatile stc_DAC_t * base)
{
    base->unIF_CTL.stcField.u1SW_OVERRIDE_FAST_RAMP_EN = true;
}

/*! \fn Cy_AudioDac_SwOverrideForFastRampDisable
    \brief Audio DAC SW Override Fast Ramp disable
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_SwOverrideForFastRampDisable(volatile stc_DAC_t * base)
{
    base->unIF_CTL.stcField.u1SW_OVERRIDE_FAST_RAMP_EN = false;
}

/*! \fn Cy_AudioDac_Enable
    \brief Audio DAC analog enable
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_Enable(volatile stc_DAC_t * base)
{
    base->unIF_CTL.stcField.u1DAC_EN = true;
}

/*! \fn Cy_AudioDac_Disable
    \brief Audio DAC analog disable
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_Disable(volatile stc_DAC_t * base)
{
    base->unIF_CTL.stcField.u1DAC_EN = false;
}

/*! \fn Cy_AudioDac_CountUpdate
    \brief Count for 1ms with clk_timer
    \param audio dac instance base
    \param count, Specifies the number of counts to achieve 1ms based on clk_timer
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_CountUpdate(volatile stc_DAC_t * base, uint16_t count)
{
    base->unCOUNT.stcField.u16COUNT_1MS = count;
}

/*! \fn Cy_AudioDac_FastRampCountUpdate
    \brief Fast Ramp count in ms
    \param audio dac instance base
    \param count, Specifies the number of counts in ms for the fast ramp circuit
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_FastRampCountUpdate(volatile stc_DAC_t * base, uint8_t count)
{
    base->unCOUNT.stcField.u8FAST_RAMP_COUNT_IN_MS = count;
}

/*! \fn Cy_AudioDac_CompleteRampCountUpdate
    \brief Complete Ramp count in ms
    \param audio dac instance base
    \param count, Specifies the number of counts in ms for the complete ramp circuit
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_CompleteRampCountUpdate(volatile stc_DAC_t * base, uint8_t count)
{
    base->unCOUNT.stcField.u8COMP_RAMP_COUNT_IN_MS = count;
}

/*! \fn Cy_AudioDac_IsDacBusy
    \brief Is Audio DAC idle or busy
    \param audio dac instance base
    \return 0 -> DAC is idle, 1 -> Indicates that FS_SEL is in the middle of synchronizing to clk_if domain
*/
__STATIC_INLINE bool Cy_AudioDac_IsDacBusy(volatile stc_DAC_t * base)
{
    return(base->unSTATUS.stcField.u1DAC_BUSY);
}

/*! \fn Cy_AudioDac_IsFastRampDone
    \brief Is Audio DAC fast ramp, complete or not
    \param audio dac instance base
    \return 0 -> Fast ramping is not complete, 1 -> Fast ramp circuit is complete. The fast ramp circuit is deemed complete based on time specified in FAST_RAMP_COUNT_IN_MS
*/
__STATIC_INLINE bool Cy_AudioDac_IsFastRampDone(volatile stc_DAC_t * base)
{
    return(base->unSTATUS.stcField.u1FAST_RAMP_DONE);
}

/*! \fn Cy_AudioDac_IsCompleteRampDone
    \brief Is Audio DAC complete ramp, complete or not
    \param audio dac instance base
    \return 0 -> complete ramping is not complete, 1 -> Complete Ramp is complete. The ramping of the circuit is deemed complete based on time specified in COMP_RAMP_COUNT_IN_MS
*/
__STATIC_INLINE bool Cy_AudioDac_IsCompleteRampDone(volatile stc_DAC_t * base)
{
    return(base->unSTATUS.stcField.u1COMP_RAMP_DONE);
}

/*! \fn Cy_AudioDac_FifoTriggerLevel
    \brief Audio DAC FIFO trigger level. When the source FIFO has less entries than the number of this field, a transmitter trigger event is generated
    \param audio dac instance base
    \param level (6-bit value) (INTR_TX.FIFO_TRIGGER = (# FIFO entries < TRIGGER_LEVEL))
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_FifoTriggerLevel(volatile stc_DAC_t * base, uint8_t level)
{
    base->unTX_FIFO_CTL.stcField.u6TRIGGER_LEVEL = (level & 0x3F);
}

/*! \fn Cy_AudioDac_Mute
    \brief Audio Dac mute, HW uses a constant PCM data value of "0"
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_Mute(volatile stc_DAC_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1MUTE = true;
}

/*! \fn Cy_AudioDac_Unmute
    \brief Audio Dac unmute, HW uses TX FIFO data.
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_Unmute(volatile stc_DAC_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1MUTE = false;
}

/*! \fn Cy_AudioDac_Activate
    \brief Audio Dac FIFO_UNDERFLOW interrupt may be activated
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_Activate(volatile stc_DAC_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1ACTIVE = true;
}

/*! \fn Cy_AudioDac_Deactivate
    \brief Audio Dac FIFO_UNDERFLOW interrupt cause will not be activated
    \param audio dac instance base
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_Deactivate(volatile stc_DAC_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1ACTIVE = false;
}

/*! \fn Cy_AudioDac_GetUsedFifoEntries
    \brief Number of used/occupied entries in the source FIFO. The field value is in the range [0, 64]. 
    \brief When "0", the FIFO is empty. When "64", the FIFO is full.
    \param audio dac instance base
    \return uint8_t value
*/
__STATIC_INLINE uint8_t Cy_AudioDac_GetUsedFifoEntries(volatile stc_DAC_t * base)
{
    return (base->unTX_FIFO_STATUS.stcField.u7USED);
}

/*! \fn Cy_AudioDac_GetFifoReadPtr
    \brief TX FIFO read pointer: FIFO location from which a data is read.
    \param audio dac instance base
    \return uint8_t read pointer value
*/
__STATIC_INLINE uint8_t Cy_AudioDac_GetFifoReadPtr(volatile stc_DAC_t * base)
{
    return (uint8_t)(base->unTX_FIFO_STATUS.stcField.u6RD_PTR);
}

/*! \fn Cy_AudioDac_GetFifoWritePtr
    \brief TX FIFO write pointer: FIFO location at which a new data is written by the hardware.
    \param audio dac instance base
    \return uint8_t write pointer value
*/
__STATIC_INLINE uint8_t Cy_AudioDac_GetFifoWritePtr(volatile stc_DAC_t * base)
{
    return (uint8_t)(base->unTX_FIFO_STATUS.stcField.u6WR_PTR);
}

/*! \fn Cy_AudioDac_FifoWriteData
    \brief Data (PCM sample pair of two 16-bit samples) written to the top TX FIFO entry (data[31:0] = DATA[31:0]). 
    \brief Typically, DATA[15:0] is used for channel right and DATA[31:16] is used for channel left. Writing adds the data to 
    \brief the TX FIFO; i.e. behavior is similar to that of a PUSH operation
    \param audio dac instance base
    \param 32-bit data
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_FifoWriteData(volatile stc_DAC_t * base, uint32_t data)
{
    base->unTX_FIFO_WR.stcField.u32DATA  = data;
}

/*! \fn Cy_AudioDac_ClearInterrupt
    \brief Tx interrupt clear (HW sets and SW clears)
    \param audio dac instance base
    \param intSrc based on cy_stc_audiodac_int_src_t
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_ClearInterrupt(volatile stc_DAC_t * base, cy_stc_audiodac_int_src_t intSrc)
{
    switch(intSrc)
    {
    case CY_AUDIODAC_FIFO_TRIGGER:
        // HW sets this field to '1', when a TX trigger is generated
        base->unINTR_TX.stcField.u1FIFO_TRIGGER = true;
        break;
    case CY_AUDIODAC_FIFO_OVERFLOW:
        // HW sets this field to '1', when writing to a full TX FIFO (SRC_FIFO_STATUS.USED is "128")
        base->unINTR_TX.stcField.u1FIFO_OVERFLOW = true;
        break;
    case CY_AUDIODAC_FIFO_UNDERFLOW:
        // HW sets this field to '1', when reading from an empty TX FIFO
        base->unINTR_TX.stcField.u1FIFO_UNDERFLOW = true;
        break;
    case CY_AUDIODAC_FAST_RAMP_COMPLETE:
        // HW sets this field to '1', when fast ramping of the DAC circuit is complete
        base->unINTR_TX.stcField.u1FAST_RAMP_COMPLETE = true;
        break;
    case CY_AUDIODAC_RAMP_COMPLETE:
        // HW sets this field to '1', when ramping of the DAC circuit is complete
        base->unINTR_TX.stcField.u1RAMP_COMPLETE = true;
        break;
    default:      
        break;
    }
}

/*! \fn Cy_AudioDac_SetInterrupt
    \brief Tx interrupt set (Write this field with '1' to set corresponding INTR_TX field)
    \param audio dac instance base
    \param intSrc based on cy_stc_audiodac_int_src_t
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_SetInterrupt(volatile stc_DAC_t * base, cy_stc_audiodac_int_src_t intSrc)
{
    switch(intSrc)
    {
    case CY_AUDIODAC_FIFO_TRIGGER:
        // HW sets this field to '1', when a TX trigger is generated
        base->unINTR_TX_SET.stcField.u1FIFO_TRIGGER = true;
        break;
    case CY_AUDIODAC_FIFO_OVERFLOW:
        // HW sets this field to '1', when writing to a full TX FIFO (SRC_FIFO_STATUS.USED is "128")
        base->unINTR_TX_SET.stcField.u1FIFO_OVERFLOW = true;
        break;
    case CY_AUDIODAC_FIFO_UNDERFLOW:
        // HW sets this field to '1', when reading from an empty TX FIFO
        base->unINTR_TX_SET.stcField.u1FIFO_UNDERFLOW = true;
        break;
    case CY_AUDIODAC_FAST_RAMP_COMPLETE:
        // HW sets this field to '1', when fast ramping of the DAC circuit is complete
        base->unINTR_TX_SET.stcField.u1FAST_RAMP_COMPLETE = true;
        break;
    case CY_AUDIODAC_RAMP_COMPLETE:
        // HW sets this field to '1', when ramping of the DAC circuit is complete
        base->unINTR_TX_SET.stcField.u1RAMP_COMPLETE = true;
        break;
    default:      
        break;
    }
}

/*! \fn Cy_AudioDac_ClearInterruptMask
    \brief Tx interrupt clear Mask for corresponding field in INTR_TX register.
    \param audio dac instance base
    \param intSrc based on cy_stc_audiodac_int_src_t
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_ClearInterruptMask(volatile stc_DAC_t * base, cy_stc_audiodac_int_src_t intSrc)
{
    switch(intSrc)
    {
    case CY_AUDIODAC_FIFO_TRIGGER:
        // HW sets this field to '1', when a TX trigger is generated
        base->unINTR_TX_MASK.stcField.u1FIFO_TRIGGER = false;
        break;
    case CY_AUDIODAC_FIFO_OVERFLOW:
        // HW sets this field to '1', when writing to a full TX FIFO (SRC_FIFO_STATUS.USED is "128")
        base->unINTR_TX_MASK.stcField.u1FIFO_OVERFLOW = false;
        break;
    case CY_AUDIODAC_FIFO_UNDERFLOW:
        // HW sets this field to '1', when reading from an empty TX FIFO
        base->unINTR_TX_MASK.stcField.u1FIFO_UNDERFLOW = false;
        break;
    case CY_AUDIODAC_FAST_RAMP_COMPLETE:
        // HW sets this field to '1', when fast ramping of the DAC circuit is complete
        base->unINTR_TX_MASK.stcField.u1FAST_RAMP_COMPLETE = false;
        break;
    case CY_AUDIODAC_RAMP_COMPLETE:
        // HW sets this field to '1', when ramping of the DAC circuit is complete
        base->unINTR_TX_MASK.stcField.u1RAMP_COMPLETE = false;
        break;
    default:      
        break;
    }
}

/*! \fn Cy_AudioDac_SetInterruptMask
    \brief Tx interrupt set Mask for corresponding field in INTR_TX register.
    \param audio dac instance base
    \param intSrc based on cy_stc_audiodac_int_src_t
    \return none
*/
__STATIC_INLINE void Cy_AudioDac_SetInterruptMask(volatile stc_DAC_t * base, cy_stc_audiodac_int_src_t intSrc)
{
    switch(intSrc)
    {
    case CY_AUDIODAC_FIFO_TRIGGER:
        // HW sets this field to '1', when a TX trigger is generated
        base->unINTR_TX_MASK.stcField.u1FIFO_TRIGGER = true;
        break;
    case CY_AUDIODAC_FIFO_OVERFLOW:
        // HW sets this field to '1', when writing to a full TX FIFO (SRC_FIFO_STATUS.USED is "128")
        base->unINTR_TX_MASK.stcField.u1FIFO_OVERFLOW = true;
        break;
    case CY_AUDIODAC_FIFO_UNDERFLOW:
        // HW sets this field to '1', when reading from an empty TX FIFO
        base->unINTR_TX_MASK.stcField.u1FIFO_UNDERFLOW = true;
        break;
    case CY_AUDIODAC_FAST_RAMP_COMPLETE:
        // HW sets this field to '1', when fast ramping of the DAC circuit is complete
        base->unINTR_TX_MASK.stcField.u1FAST_RAMP_COMPLETE = true;
        break;
    case CY_AUDIODAC_RAMP_COMPLETE:
        // HW sets this field to '1', when ramping of the DAC circuit is complete
        base->unINTR_TX_MASK.stcField.u1RAMP_COMPLETE = true;
        break;
    default:      
        break;
    }
}

/** \} group_audiodac_functions */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* CY_IP_MXS40EAUDIODAC */

#endif /* __CY_AUDIODAC_H__ */

/** \} group_audiodac */


/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
