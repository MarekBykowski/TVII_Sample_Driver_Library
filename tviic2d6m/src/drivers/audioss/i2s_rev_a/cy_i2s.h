/***************************************************************************//**
* \file cy_i2s.h
* \version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
* 
* The header file of the I2S driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2018, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_i2s Inter-IC Sound (I2S)
* \{
* The I2S driver provides a function API to manage Inter-IC Sound. I2S is used 
* to send digital audio streaming data to external I2S devices, such as audio 
* codecs or simple DACs. It can also receive digital audio streaming data.
*
* Features:
* * An industry standard NXP I2S interface.
* * Supports master/slave TX/RX operation.
* * Programmable Channel/Word Lengths.
* * Supports External Clock operation.
*
* The I2S bus is an industry standard. The hardware interface was 
* developed by Philips Semiconductors (now NXP Semiconductors). 
*
* \section group_i2s_configuration_considerations Configuration Considerations
*
* To set up an I2S, provide the configuration parameters in the
* \ref cy_stc_i2s_config_t structure. 
* 
* For example, for Tx configuration, set txEnabled to true, configure
* txDmaTrigger (depending on whether DMA is going to be used or not), set
* extClk (if an external clock is used), provide clkDiv, txMasterMode,
* txFormat, txChannel0 and txChannel1 (only 2 is supported in I2S and Left Justified modes)
* , txChannelLength, txWordLength, either txSckoInversion or txSckiInversion (based on txMasterMode setting),
* txFifoTriggerLevel (when the Trig interrupt will be used) and txOverheadValue
* (only when the word length is less than channel length).
* A similar setup is for the Rx configuration.
*
* To initialize the I2S block, call the \ref Cy_I2S_Init function, providing the
* filled \ref cy_stc_i2s_config_t structure.
* Before starting the transmission, clear the FIFO \ref Cy_I2S_ClearTxFifo, then
* fill the first Tx data frame by calling \ref Cy_I2S_WriteTxData once for each
* channel (e.g. twice for I2S mode with only two channels) with zero data. Then
* call the \ref Cy_I2S_EnableTx itself.
* For the reception the sequence is the same except for filling the first data
* frame, just RX FIFO clearing is enough.
*
* For example:
* \snippet i2s/i2s_v2_0_sut_00.cydsn/main_cm4.c snippet_Cy_I2S_Init
* 
* If you use a DMA, the DMA channel should be previously configured. The I2S interrupts 
* (if applicable) can be enabled by calling \ref Cy_I2S_SetInterruptMask.
*
* For example, if the trigger interrupt is used, during operation the ISR
* should call the \ref Cy_I2S_WriteTxData as many times as required for your 
* FIFO payload, but not more than the FIFO size. Then call \ref Cy_I2S_ClearInterrupt 
* with appropriate parameters.
*
* The I2S/Left Justified data formats always contains two data channels.
* They are ordered one-by-one in the FIFOs, left always goes first.
* So in case of mono audio stream transmission, each sample can be put twice
* into the TX FIFO (in this case both channels will sound the same),
* or combined with zeroes: sample1-zero-sample2-zero (in this case only the
* left channel will finally sound, for right-only case zero should go first).
* The TDM frame word order in FIFOs is similar, one-by-one.
* 
* If a DMA is used and the DMA channel is properly configured - no CPU activity
* (or any application code) is needed for I2S operation.
*
* The I2S frame appears as:
* \image html i2s_frame.png
* This is an example for the channel length = 32. A similar is for all the rest
* channel lengths, with one limitation: the word length could be less or equal
* to the channel length. See the device Technical Reference Manual (TRM)
* for more details.
*
* \section group_i2s_more_information More Information
* See: the the I2S chapter of the device technical reference manual (TRM);
*      I2S_PDL Component datasheet;
*      CE218636 - PSOC 6 MCU INTER-IC SOUND (I2S) EXAMPLE.
*
* \section group_i2s_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>2.10</td>
*     <td>Flattened the driver source code organization into the single
*         source directory and the single include directory
*     </td>
*     <td>Simplified the driver library directory structure</td>
*   </tr>
*   <tr>
*     <td>2.0.1</td>
*     <td>Added Low Power Callback section</td>
*     <td>Documentation update and clarification</td>
*   </tr>
*   <tr>
*     <td>2.0</td>
*     <td>The slave operation is added, Left Justified and TDM modes are added</td>
*     <td></td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_i2s_macros Macros
* \defgroup group_i2s_functions Functions
*   \{
*       \defgroup group_i2s_functions_syspm_callback  Low Power Callback
*   \}
* \defgroup group_i2s_data_structures Data Structures
* \defgroup group_i2s_enums Enumerated Types
*/

#if !defined CY_I2S_H
#define CY_I2S_H

#include <stddef.h>
#include <stdbool.h>
#include "syslib/cy_syslib.h"
#include "syspm/cy_syspm.h"

#ifdef CY_IP_MXI2S

#ifdef __cplusplus
extern "C" {
#endif

/** \addtogroup group_i2s_macros
* \{
*/

/** The driver major version */
#define CY_I2S_DRV_VERSION_MAJOR       `$CY_MAJOR_VERSION`

/** The driver minor version */
#define CY_I2S_DRV_VERSION_MINOR       `$CY_MINOR_VERSION`

/** The I2S driver identifier */
#define CY_I2S_ID                      (CY_PDL_DRV_ID(0x20U))


/**
* \defgroup group_i2s_macros_intrerrupt_masks Interrupt Masks
* \{
*/

/** Bit 0: Less entries in the TX FIFO than specified by Trigger Level. */
#define CY_I2S_INTR_TX_FIFO_TRIGGER     (I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_FIFO_TRIGGER_Msk)
/** Bit 1: Attempt to write to a full TX FIFO. */
#define CY_I2S_INTR_TX_FIFO_OVERFLOW	(I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_FIFO_OVERFLOW_Msk)
/** Bit 2: Attempt to read from an empty TX FIFO. */
#define CY_I2S_INTR_TX_FIFO_UNDERFLOW	(I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_FIFO_UNDERFLOW_Msk)
/** Bit 8: Interface frequency is higher than PCM sample frequency. */
#define CY_I2S_INTR_TX_IF_UNDERFLOW 	(I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_IF_UNDERFLOW_Msk)

/** Bit 0: Less entries in the RX FIFO than specified by Trigger Level. */
#define CY_I2S_INTR_RX_FIFO_TRIGGER	(I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_FIFO_TRIGGER_Msk)
/** Bit 1: Attempt to write to a full RX FIFO. */
#define CY_I2S_INTR_RX_FIFO_OVERFLOW	(I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_FIFO_OVERFLOW_Msk)
/** Bit 2: Attempt to read from an empty RX FIFO. */
#define CY_I2S_INTR_RX_FIFO_UNDERFLOW	(I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_FIFO_UNDERFLOW_Msk)
/** Bit 8: Interface frequency is higher than PCM sample frequency. */
#define CY_I2S_INTR_RX_IF_UNDERFLOW 	(I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_IF_OVERFLOW_Msk)

/** \} group_i2s_macros_intrerrupt_masks */


/**
* \addtogroup group_i2s_enums
* \{
*/

/**
* I2S status definitions.
*/

typedef enum 
{
    CY_I2S_SUCCESS   = 0x00UL,                                  /**< Successful. */
    CY_I2S_BAD_PARAM = CY_I2S_ID | CY_PDL_STATUS_ERROR | 0x01UL /**< One or more invalid parameters. */
} cy_en_i2s_status_t;

/**
* I2S channel/word length.
*/
typedef enum
{
    CY_I2S_LEN8         = 0U, /**< Channel/word length:  8 bit. */
    CY_I2S_LEN10        = 1U, /**< Channel/Word length: 10 bit. */
    CY_I2S_LEN12        = 2U, /**< Channel/Word length: 12 bit. */
    CY_I2S_LEN14        = 3U, /**< Channel/Word length: 14 bit. */
    CY_I2S_LEN16        = 4U, /**< Channel/Word length: 16 bit. */
    CY_I2S_LEN18        = 5U, /**< Channel/Word length: 18 bit. */
    CY_I2S_LEN20        = 6U, /**< Channel/Word length: 20 bit. */
    CY_I2S_LEN24        = 7U, /**< Channel/Word length: 24 bit. */
    CY_I2S_LEN32        = 8U  /**< Channel/Word length: 32 bit. */
} cy_en_i2s_ws_t;

typedef enum
{
    CY_I2S_LEFT_DELAYED	= 0U, /**< Format is left aligned and delayed. */
    CY_I2S_LEFT		= 1U, /**< Format is left aligned. */
    CY_I2S_RIGHT_DELAYED= 2U, /**< Format is right aligned and delayed. */
    CY_I2S_RIGHT	= 3U, /**< Format is right aligned. */
} cy_en_i2s_format_t;

typedef enum
{
    CY_I2S_DEVICE_SLAVE	= 0U, /**< Device is configured as slave. */
    CY_I2S_DEVICE_MASTER= 1U, /**< Device is configured as master. */
} cy_en_i2s_device_cfg_t;

typedef enum
{
    CY_I2S_SEL_SRSS_CLK0	= 0U, /**< Interface clock is selected as clk_if_srss[0]. */
    CY_I2S_SEL_SRSS_CLK1	= 1U, /**< Interface clock is selected as clk_if_srss[1]. */
    CY_I2S_SEL_SRSS_CLK2	= 2U, /**< Interface clock is selected as clk_if_srss[2]. */
    CY_I2S_SEL_SRSS_CLK3	= 3U, /**< Interface clock is selected as clk_if_srss[3]. */
    CY_I2S_SEL_RX_MCLK_IN	= 4U, /**< Interface clock is selected as i2s_rx_mclk_in. */
} cy_en_i2s_clock_sel_t;

/** \} group_i2s_enums */

/**
* \addtogroup group_i2s_data_structures
* \{
*/

/**
* I2S initialization configuration.
*/
typedef struct
{
    bool		  txEnabled;            /**< Enables the I2S TX component: 'false': disabled. 'true': enabled. */
    bool		  txMasterMode;         /**< 'false': TX in slave mode, 'true': TX in master mode. */
    cy_en_i2s_format_t	  txFormat;		/**< TX data format, see: #cy_en_i2s_format_t. */
    cy_en_i2s_ws_t        txWordSize;       	/**< TX word length, see #cy_en_i2s_len_t, must be less or equal to txChannelLength. */
    uint8_t		  txClkDiv;             /**< CLK_SEL divider: 1: Bypass, 2: 1/2, 3: 1/3, ..., 255: 1/255. */
    cy_en_i2s_clock_sel_t txClkSel;             /**< 'false': internal clock, 'true': external clock. */
    uint8_t		  txSckPolarity;	/**< TX clock polarity, 0 for as is and 1 for inverted. */
    uint8_t		  txWsPolarity;		/**< TX word select polarity, 0 for as is and 1 for inverted. */
    bool       		  txChannel0Enable;     /**< TX channel 0 enable. */
    bool       		  txChannel1Enable;     /**< TX channel 1 enable. */
    uint8_t		  txChannelSize;    	/**< TX channel length, 0 to 31, the value of this parameter is ignored in TDM modes, the real
                                                      channel length is 32 bit in these modes. */
    uint8_t               txFifoTriggerLevel;   /**< TX FIFO interrupt trigger level (0, 1, ..., 63). */

    bool		  rxEnabled;            /**< Enables the I2S RX component: 'false': disabled. 'true': enabled. */
    bool                  rxMasterMode;         /**< 'false': RX in slave mode, 'true': RX in master mode. */
    cy_en_i2s_format_t	  rxFormat;		/**< TX data format, see: #cy_en_i2s_format_t. */
    cy_en_i2s_ws_t        rxWordSize;       	/**< RX word length, see #cy_en_i2s_len_t, must be less or equal to rxChannelLength. */
    bool                  rxSignExtension;      /**< RX value sign extension (when the word length is less than 32 bits),
                                                      'false': all MSB are filled by zeroes, 'true': all MSB are filled by the original sign bit value. */
    uint8_t		  rxClkDiv;             /**< CLK_SEL divider: 1: Bypass, 2: 1/2, 3: 1/3, ..., 255: 1/255. */
    cy_en_i2s_clock_sel_t rxClkSel;             /**< 'false': internal clock, 'true': external clock. */
    bool		  rxSckPolarity;	/**< RX clock polarity, 0 for as is and 1 for inverted. */
    bool		  rxWsPolarity;		/**< RX word select polarity, 0 for as is and 1 for inverted. */
    bool		  rxLateSampleDelay;	/**< Rx sampling can be delayed by half of the cycle based on the SCK_POLARITY.*/
    bool       		  rxChannel0Enable;     /**< RX channel 0 enable. */
    bool       		  rxChannel1Enable;     /**< RX channel 1 enable. */
    uint8_t		  rxChannelSize;    	/**< RX channel length, see #cy_en_i2s_len_t, the value of this parameter is ignored in TDM modes, the real
                                                      channel length is 32 bit in these modes. */
    uint8_t               rxFifoTriggerLevel;   /**< RX FIFO interrupt trigger level (0, 1, ..., (63 - (number of channels))). */
} cy_stc_i2s_config_t;


/**
 * The I2S backup structure type to be used for the SysPm callback.
 * \ref Cy_I2S_DeepSleepCallback context definition.
 *
 * \cond Also can be used for other purposes to store the current Tx/Rx
 * operation state and interrupt settings - the factors that are usually
 * changed on the fly. \endcond
 */
typedef struct
{
    uint32_t enableTxState;             /**< Stores the I2S->TX state */
    uint32_t enableRxState;             /**< Stores the I2S->RX state */
    uint32_t interruptTxMask;           /**< Stores the I2S->TX interrupt mask */
    uint32_t interruptRxMask;           /**< Stores the I2S->RX interrupt mask */
} cy_stc_i2s_context_t;

/** \} group_i2s_data_structures */

/** \cond INTERNAL */
/******************************************************************************
 * Local definitions
*******************************************************************************/

#define CY_I2S_INTR_TX_MASK         	        (CY_I2S_INTR_TX_FIFO_TRIGGER	| \
                                                CY_I2S_INTR_TX_FIFO_OVERFLOW	| \
                                                CY_I2S_INTR_TX_FIFO_UNDERFLOW	| \
                                                CY_I2S_INTR_TX_IF_UNDERFLOW)

#define CY_I2S_INTR_RX_MASK         	        (CY_I2S_INTR_RX_FIFO_TRIGGER	| \
                                                CY_I2S_INTR_RX_FIFO_OVERFLOW	| \
                                                CY_I2S_INTR_RX_FIFO_UNDERFLOW	| \
                                                CY_I2S_INTR_RX_IF_UNDERFLOW)

/* Non-zero default values for TX_CTL register */
#define CY_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_MS_DEFAULT	        (0x1U)	/**< Default mode is selected as master */

#define CY_I2S_TX_CTL_DEFAULT 		        (_VAL2FLD(I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_MS, CY_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_MS_DEFAULT))


/* Non-zero default values for TX_IF_CTL register */
#define CY_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CLOCK_DIV_DEFAULT	(0x7U)	/**< Default clock is clk_if/(CLOCK_DIV+1) */
#define CY_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CLOCK_SEL_DEFAULT	(0x7U)	/**< Default clock is selected as clk_if_srss[0], later it will be off */
#define CY_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CH_SIZE_DEFAULT 	(0x1FU)	/**< Default channel size is 32 bits */

#define CY_I2S_TX_IF_CTL_DEFAULT 	        (_VAL2FLD(I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CLOCK_DIV, CY_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CLOCK_DIV_DEFAULT)	| \
                                                _VAL2FLD(I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CLOCK_SEL, CY_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CLOCK_SEL_DEFAULT)	| \
                                                _VAL2FLD(I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CH_SIZE, CY_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CH_SIZE_DEFAULT))
        
/* Non-zero default values for RX_CTL register */
#define CY_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_WORD_SIGN_EXTEND_DEFAULT	(0x1U)	/**< Default rx data word with sign extension */

#define CY_I2S_RX_CTL_DEFAULT 		        (_VAL2FLD(I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_WORD_SIGN_EXTEND, CY_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_WORD_SIGN_EXTEND_DEFAULT))


/* Non-zero default values for TX_IF_CTL register */
#define CY_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CLOCK_DIV_DEFAULT	(0x7U)	/**< Default clock is clk_if/(CLOCK_DIV+1) */
#define CY_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CLOCK_SEL_DEFAULT	(0x7U)	/**< Default clock is selected as clk_if_srss[0], later it will be off */
#define CY_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CH_SIZE_DEFAULT	(0x1FU)	/**< Default channel size is 32 bits */

#define CY_I2S_RX_IF_CTL_DEFAULT 	        (_VAL2FLD(I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CH_SIZE, CY_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CLOCK_DIV_DEFAULT)	| \
                                                _VAL2FLD(I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CLOCK_SEL, CY_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CLOCK_SEL_DEFAULT)	| \
                                                _VAL2FLD(I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CH_SIZE, CY_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CH_SIZE_DEFAULT))


/* Macros for conditions used by CY_ASSERT calls */
#define CY_I2S_IS_WORD_LEN_VALID(length)        ((CY_I2S_LEN8 == (length))	|| \
						(CY_I2S_LEN10 == (length))	|| \
						(CY_I2S_LEN12 == (length))	|| \
						(CY_I2S_LEN14 == (length))	|| \
	                                        (CY_I2S_LEN16 == (length))	|| \
	                                        (CY_I2S_LEN18 == (length))	|| \
	                                        (CY_I2S_LEN20 == (length))	|| \
	                                        (CY_I2S_LEN24 == (length))	|| \
	                                        (CY_I2S_LEN32 == (length)))

#define CY_I2S_IS_FORMAT_VALID(format)		((CY_I2S_LEFT_DELAYED == (format))	|| \
						(CY_I2S_LEFT == (format))		|| \
						(CY_I2S_RIGHT_DELAYED == (format))	|| \
						(CY_I2S_RIGHT == (format)))

#define CY_I2S_IS_DEVICE_CFG_VALID(cfg)		((CY_I2S_DEVICE_SLAVE == (cfg))	|| \
						(CY_I2S_DEVICE_MASTER == (cfg)))

#define CY_I2S_IS_CLOCK_VALID(clock_sel)	((CY_I2S_SEL_SRSS_CLK0 == (clock_sel))	|| \
						(CY_I2S_SEL_SRSS_CLK1 == (clock_sel))	|| \
						(CY_I2S_SEL_SRSS_CLK2 == (clock_sel))	|| \
						(CY_I2S_SEL_SRSS_CLK3 == (clock_sel))	|| \
						(CY_I2S_SEL_RX_MCLK_IN == (clock_sel)))


#define CY_I2S_IS_CLK_DIV_VALID(clkDiv)		((clkDiv) <= 255U)
#define CY_I2S_IS_CHANNEL_SIZE_VALID(size)	((size) <= 31UL)
#define CY_I2S_IS_TRIG_LEVEL_VALID(trigLevel) 	((trigLevel) <= 63)

#define CY_I2S_IS_TX_INTR_MASK_VALID(interrupt)	(0UL == ((interrupt) & ((uint32_t) ~CY_I2S_INTR_TX_MASK)))
#define CY_I2S_IS_RX_INTR_MASK_VALID(interrupt)	(0UL == ((interrupt) & ((uint32_t) ~CY_I2S_INTR_RX_MASK)))

#define CY_I2S_IS_CHAN_WORD_VALID(channel,word)	((CY_I2S_IS_CHANNEL_SIZE_VALID(channel))        && \
                                                (CY_I2S_IS_WORD_LEN_VALID(word))		&& \
                                                ((channel) >= (word)))

/** \endcond */


/**
* \addtogroup group_i2s_functions
* \{
*/

cy_en_i2s_status_t      Cy_I2S_Init(volatile stc_I2S_I2S_STRUCT_t * base, cy_stc_i2s_config_t const * config);
void     		Cy_I2S_DeInit(volatile stc_I2S_I2S_STRUCT_t * base);

cy_en_i2s_status_t	Cy_I2S_Rx_Init(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base, cy_stc_i2s_config_t const * config);
void			Cy_I2S_Rx_DeInit(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);
                
cy_en_i2s_status_t	Cy_I2S_Tx_Init(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base, cy_stc_i2s_config_t const * config);
void			Cy_I2S_Tx_DeInit(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);

/** \addtogroup group_i2s_functions_syspm_callback
* The driver supports SysPm callback for Deep Sleep transition.
* \{
*/
cy_en_syspm_status_t    Cy_I2S_DeepSleepCallback(cy_stc_syspm_callback_params_t * callbackParams);
/** \} */

__STATIC_INLINE void     Cy_I2S_EnableTx(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE void     Cy_I2S_DisableTx(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE uint32_t Cy_I2S_GetTxCurrentState(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE void     Cy_I2S_EnableRx(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);
__STATIC_INLINE void	 Cy_I2S_DisableRx(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);
__STATIC_INLINE uint32_t Cy_I2S_GetRxCurrentState(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);

__STATIC_INLINE void	 Cy_I2S_WriteTxData(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base, uint32_t data);
__STATIC_INLINE void	 Cy_I2S_FreezeTxFifo(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE void	 Cy_I2S_UnfreezeTxFifo(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE void	 Cy_I2S_MuteTxFifo(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE void	 Cy_I2S_UnmuteTxFifo(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE uint8_t  Cy_I2S_GetNumInTxFifo(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE uint8_t	 Cy_I2S_GetTxReadPointer(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE uint8_t	 Cy_I2S_GetTxWritePointer(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE void	 Cy_I2S_EnableTxTestMode(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE void	 Cy_I2S_DisableTxTestMode(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);

__STATIC_INLINE uint32_t Cy_I2S_ReadRxData(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);
__STATIC_INLINE void	 Cy_I2S_FreezeRxFifo(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);
__STATIC_INLINE void	 Cy_I2S_UnfreezeRxFifo(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);
__STATIC_INLINE uint8_t  Cy_I2S_GetNumInRxFifo(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);
__STATIC_INLINE uint8_t	 Cy_I2S_GetRxReadPointer(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);
__STATIC_INLINE uint8_t	 Cy_I2S_GetRxWritePointer(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);
__STATIC_INLINE void	 Cy_I2S_EnableRxTestMode(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);
__STATIC_INLINE void	 Cy_I2S_DisableRxTestMode(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);

__STATIC_INLINE void	 Cy_I2S_ClearTxInterrupt(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE void     Cy_I2S_SetTxInterrupt(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE uint32_t Cy_I2S_GetTxInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE void     Cy_I2S_SetTxInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE uint32_t Cy_I2S_GetTxInterruptStatusMasked(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE void     Cy_I2S_SetTxTriggerInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);
__STATIC_INLINE void     Cy_I2S_ClearTxTriggerInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base);

__STATIC_INLINE void	 Cy_I2S_ClearRxInterrupt(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE void     Cy_I2S_SetRxInterrupt(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE uint32_t Cy_I2S_GetRxInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);
__STATIC_INLINE void     Cy_I2S_SetRxInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE uint32_t Cy_I2S_GetRxInterruptStatusMasked(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);
__STATIC_INLINE void     Cy_I2S_SetRxTriggerInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);
__STATIC_INLINE void     Cy_I2S_ClearRxTriggerInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base);


/*******************************************************************************
* Function Name: Cy_I2S_EnableTx
****************************************************************************//**
*
* Starts an I2S transmission. Interrupts enabling (by the 
* \ref Cy_I2S_SetTxInterruptMask) is required after this function call, in case
* if any I2S interrupts are used in the application.
*
* \pre Cy_I2S_Init() or Cy_I2S_Tx_Init() must be called before.
*
* \param base The pointer to the I2S or I2S->TX instance address.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_EnableTx(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1ACTIVE = 1u;
}

/*******************************************************************************
* Function Name: Cy_I2S_DisableTx
****************************************************************************//**
*
* Stops an I2S transmission. 
*
* \pre TX interrupts disabling (by the \ref Cy_I2S_SetTxInterruptMask) is required
* prior to this function call, in case if any TX I2S interrupts are used.
*
* \param base The pointer to the I2S->Tx instance address.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_DisableTx(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1ACTIVE	= 0u;
}

/*******************************************************************************
* Function Name: Cy_I2S_GetTxCurrentState
****************************************************************************//**
*
* Returns the current I2S TX state (TX/RX running/paused/stopped).
*
* \param base The pointer to the I2S->TX instance address.
*
* \return The current state \ref group_i2s_macros_current_state.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I2S_GetTxCurrentState(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    return (base->unTX_FIFO_CTL.stcField.u1ACTIVE);
}

/*******************************************************************************
* Function Name: Cy_I2S_EnableRx
****************************************************************************//**
*
* Starts an I2S reception. Interrupts enabling (by the 
* \ref Cy_I2S_SetRxInterruptMask) is required after this function call, in case
* if any I2S interrupts are used in the application.
*
* \pre \ref Cy_I2S_Init() or Cy_I2S_Rx_Init() must be called before.
*
* \param base The pointer to the I2S or I2S->Rx instance address.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_EnableRx(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    base->unRX_FIFO_CTL.stcField.u1ACTIVE	= 1u;	
}

/*******************************************************************************
* Function Name: Cy_I2S_EnableRx
****************************************************************************//**
*
* Stops an I2S reception.
*
* \pre RX interrupts disabling (by the \ref Cy_I2S_SetRxInterruptMask) is required
* prior to this function call, in case if any RX I2S interrupts are used.
*
* \param base The pointer to the I2S or I2S-Rx instance address.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_DisableRx(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    base->unRX_FIFO_CTL.stcField.u1ACTIVE	= 0u;
}

/*******************************************************************************
* Function Name: Cy_I2S_GetRxCurrentState
****************************************************************************//**
*
* Returns the current I2S RX state (TX/RX running/paused/stopped).
*
* \param base The pointer to the I2S->RX instance address.
*
* \return The current state \ref group_i2s_macros_current_state.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I2S_GetRxCurrentState(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    return (base->unRX_FIFO_CTL.stcField.u1ACTIVE);
}

/*******************************************************************************
* Function Name: Cy_I2S_WriteTxData
****************************************************************************//**
*
* Writes data to the TX FIFO. Increases the TX FIFO level.
*
* \param base The pointer to the I2S-TX instance address.
*
* \param data Data to be written to the TX FIFO.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_WriteTxData(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base, uint32_t data)
{
    base->unTX_FIFO_WR.stcField.u32DATA = data;
}

/*******************************************************************************
* Function Name: Cy_I2S_FreezeTxFifo
****************************************************************************//**
*
* Freezes the TX FIFO. This function is rather for debug purposes.
*
* \param base The pointer to the I2S->TX instance address.
*
* \funcusage
* \
*
* \Note Freeze does not advance the FIFO read pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_FreezeTxFifo(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1FREEZE = 1u;
}

/*******************************************************************************
* Function Name: Cy_I2S_UnfreezeTxFifo
****************************************************************************//**
*
* Unfreezes the TX FIFO. This function is rather for debug purposes.
*
* \param base The pointer to the I2S->TX instance address.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_UnfreezeTxFifo(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1FREEZE = 0u;
}

/*******************************************************************************
* Function Name: Cy_I2S_MuteTxFifo
****************************************************************************//**
*
* Mute the TX FIFO. HW uses a constant data value of 0.
*
* \param base The pointer to the I2S->TX instance address.
*
* \funcusage
* \
*
* \Note Mute does advance the FIFO read pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_MuteTxFifo(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1MUTE = 1u;
}

/*******************************************************************************
* Function Name: Cy_I2S_UnmuteTxFifo
****************************************************************************//**
*
* Unmute the TX FIFO.
*
* \param base The pointer to the I2S->TX instance address.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_UnmuteTxFifo(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1MUTE = 0u;
}

/*******************************************************************************
* Function Name: Cy_I2S_GetNumInTxFifo
****************************************************************************//**
*
* Get the number of used/occupied entries in the TX FIFO.
*
* \param base The pointer to the I2S->TX instance address.
*
* \funcusage
* \
*
* \Note range is 0 to 64(Full).
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_I2S_GetNumInTxFifo(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    return (base->unTX_FIFO_STATUS.stcField.u7USED);
}

/*******************************************************************************
* Function Name: Cy_I2S_GetTxReadPointer
****************************************************************************//**
*
* Get the TX FIFO location from which a data is read.
*
* \param base The pointer to the I2S->TX instance address.
*
* \funcusage
* \
*
* \Note this is for dubugging purpose.
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_I2S_GetTxReadPointer(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    return (uint8_t)(base->unTX_FIFO_STATUS.stcField.u6RD_PTR);
}

/*******************************************************************************
* Function Name: Cy_I2S_GetTxWritePointer
****************************************************************************//**
*
* Get the TX FIFO location at which new data is written.
*
* \param base The pointer to the I2S->TX instance address.
*
* \funcusage
* \
*
* \Note this is for dubugging purpose.
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_I2S_GetTxWritePointer(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    return (uint8_t)(base->unTX_FIFO_STATUS.stcField.u6WR_PTR);
}

/*******************************************************************************
* Function Name: Cy_I2S_EnableTxTestMode
****************************************************************************//**
*
* Test mode enable intended to be used with slave tx and master rx configuration.
*
* \param base The pointer to the I2S->TX instance address.
*
* \funcusage
* \
*
* \Note this is for dubugging purpose and worked as Tx-Rx loopback.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_EnableTxTestMode(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    base->unTX_TEST_CTL.stcField.u1ENABLED = 1u;
}

/*******************************************************************************
* Function Name: Cy_I2S_DisableTxTestMode
****************************************************************************//**
*
* Test mode disable will be used for TX to put it in normal functional mode.
*
* \param base The pointer to the I2S->TX instance address.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_DisableTxTestMode(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    base->unTX_TEST_CTL.stcField.u1ENABLED = 0u;
}

/*******************************************************************************
* Function Name: Cy_I2S_ReadRxData
****************************************************************************//**
*
* Reads data from the RX FIFO. Decreases the RX FIFO level.
*
* \param base The pointer to the I2S-RX instance address.
*
* \funcusage
* \
*
* \Note reading removes the data from FIFO and read ptr is incremented.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I2S_ReadRxData(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    return (base->unRX_FIFO_RD.stcField.u32DATA);
}

/*******************************************************************************
* Function Name: Cy_I2S_FreezeRxFifo
****************************************************************************//**
*
* Freezes the RX FIFO. This function is rather for debug purposes.
*
* \param base The pointer to the I2S->RX instance address.
*
* \funcusage
* \
*
* \Note Freeze does not advance the FIFO write pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_FreezeRxFifo(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    base->unRX_FIFO_CTL.stcField.u1FREEZE = 1u;
}

/*******************************************************************************
* Function Name: Cy_I2S_UnfreezeRxFifo
****************************************************************************//**
*
* Unfreezes the RX FIFO. This function is rather for debug purposes.
*
* \param base The pointer to the I2S->RX instance address.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_UnfreezeRxFifo(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    base->unRX_FIFO_CTL.stcField.u1FREEZE = 0u;
}

/*******************************************************************************
* Function Name: Cy_I2S_GetNumInRxFifo
****************************************************************************//**
*
* Get the number of used/occupied entries in the RX FIFO.
*
* \param base The pointer to the I2S->RX instance address.
*
* \funcusage
* \
*
* \Note range is 0 to 64(Full).
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_I2S_GetNumInRxFifo(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    return (base->unRX_FIFO_STATUS.stcField.u7USED);
}

/*******************************************************************************
* Function Name: Cy_I2S_GetRxReadPointer
****************************************************************************//**
*
* Get the RX FIFO location from which a data is read.
*
* \param base The pointer to the I2S->RX instance address.
*
* \funcusage
* \
*
* \Note this is for dubugging purpose.
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_I2S_GetRxReadPointer(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    return (uint8_t)(base->unRX_FIFO_STATUS.stcField.u6RD_PTR);
}

/*******************************************************************************
* Function Name: Cy_I2S_GetRxWritePointer
****************************************************************************//**
*
* Get the RX FIFO location at which new data is written.
*
* \param base The pointer to the I2S->RX instance address.
*
* \funcusage
* \
*
* \Note this is for dubugging purpose.
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_I2S_GetRxWritePointer(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    return (uint8_t)(base->unRX_FIFO_STATUS.stcField.u6WR_PTR);
}

/*******************************************************************************
* Function Name: Cy_I2S_EnableRxTestMode
****************************************************************************//**
*
* Test mode enable intended to be used with master tx and slave rx configuration.
*
* \param base The pointer to the I2S->RX instance address.
*
* \funcusage
* \
*
* \Note this is for dubugging purpose and worked as Tx-Rx loopback.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_EnableRxTestMode(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    base->unRX_TEST_CTL.stcField.u1ENABLED = 1u;
}

/*******************************************************************************
* Function Name: Cy_I2S_DisableRxTestMode
****************************************************************************//**
*
* Test mode disable will be used for RX to put it in normal functional mode.
*
* \param base The pointer to the I2S->RX instance address.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_DisableRxTestMode(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    base->unRX_TEST_CTL.stcField.u1ENABLED = 0u;
}

/*******************************************************************************
* Function Name: Cy_I2S_ClearTxInterrupt
****************************************************************************//**
*
* Clears one or more interrupt factors from the TX interrupt register.
*
* \param base The pointer to the I2S->TX instance address.
*
* \param interrupt Interrupt bit mask.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_ClearTxInterrupt(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_I2S_IS_TX_INTR_MASK_VALID(interrupt));
    base->unINTR_TX.u32Register = interrupt;
    (void) base->unINTR_TX.u32Register;
}

/*******************************************************************************
* Function Name: Cy_I2S_SetTxInterrupt
****************************************************************************//**
*
* Sets one or more interrupt factors in the TX interrupt register.
*
* \param base The pointer to the I2S->TX instance address.
*
* \param interrupt Interrupt bit mask.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_SetTxInterrupt(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_I2S_IS_TX_INTR_MASK_VALID(interrupt));
    base->unINTR_TX_SET.u32Register = interrupt;
}

/*******************************************************************************
* Function Name: Cy_I2S_GetTxInterruptMask
****************************************************************************//**
*
* Returns the interrupt mask in the TX interrupt register.
*
* \param base The pointer to the I2S->TX instance address.
*
* \return The interrupt bit mask.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I2S_GetTxInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    return (base->unINTR_TX_MASK.u32Register);
}

/*******************************************************************************
* Function Name: Cy_I2S_SetTxInterruptMask
****************************************************************************//**
*
* Sets one or more interrupt factor masks in the interrupt mask in the TX interrupt register.
*
* \param base The pointer to the I2S->TX instance address.
*
* \return The interrupt bit mask.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_SetTxInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_I2S_IS_TX_INTR_MASK_VALID(interrupt));
    base->unINTR_TX_MASK.u32Register = interrupt;
}

/*******************************************************************************
* Function Name: Cy_I2S_GetTxInterruptStatusMasked
****************************************************************************//**
*
* Returns the interrupt status masked (a content of the TX_INTR_MASKED register).
*
* \param base The pointer to the I2S instance address.
*
* \return The interrupt bit mask(s).
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I2S_GetTxInterruptStatusMasked(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    return (base->unINTR_TX_MASKED.u32Register);
}

/*******************************************************************************
* Function Name: Cy_I2S_SetTxTriggerInterruptMask
****************************************************************************//**
*
* Sets TX Trigger Interrupt mask.
*
* \param base The pointer to the I2S-TX instance address.
*
* \return None.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_SetTxTriggerInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    base->unINTR_TX_MASK.stcField.u1FIFO_TRIGGER = 1u;
}

/*******************************************************************************
* Function Name: Cy_I2S_ClearTxTriggerInterruptMask
****************************************************************************//**
*
* Clearss TX Trigger Interrupt mask.
*
* \param base The pointer to the I2S-TX instance address.
*
* \return None.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_ClearTxTriggerInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t * base)
{
    base->unINTR_TX_MASK.stcField.u1FIFO_TRIGGER = 0u;	
}

/*******************************************************************************
* Function Name: Cy_I2S_ClearRxInterrupt
****************************************************************************//**
*
* Clears one or more interrupt factors from the RX interrupt register.
*
* \param base The pointer to the I2S->RX instance address.
*
* \param interrupt Interrupt bit mask.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_ClearRxInterrupt(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_I2S_IS_RX_INTR_MASK_VALID(interrupt));
    base->unINTR_RX.u32Register = interrupt;
    (void) base->unINTR_RX.u32Register;
}

/*******************************************************************************
* Function Name: Cy_I2S_SetRxInterrupt
****************************************************************************//**
*
* Sets one or more interrupt factors in the RX interrupt register.
*
* \param base The pointer to the I2S->RX instance address.
*
* \param interrupt Interrupt bit mask.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_SetRxInterrupt(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_I2S_IS_RX_INTR_MASK_VALID(interrupt));
    base->unINTR_RX_SET.u32Register = interrupt;
}

/*******************************************************************************
* Function Name: Cy_I2S_GetRxInterruptMask
****************************************************************************//**
*
* Returns the interrupt mask in the RX interrupt register.
*
* \param base The pointer to the I2S->RX instance address.
*
* \return The interrupt bit mask.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I2S_GetRxInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    return (base->unINTR_RX_MASK.u32Register);
}

/*******************************************************************************
* Function Name: Cy_I2S_SetRxInterruptMask
****************************************************************************//**
*
* Sets one or more interrupt factor masks in the interrupt mask in the RX interrupt register.
*
* \param base The pointer to the I2S->RX instance address.
*
* \return The interrupt bit mask.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_SetRxInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_I2S_IS_RX_INTR_MASK_VALID(interrupt));
    base->unINTR_RX_MASK.u32Register = interrupt;
}

/*******************************************************************************
* Function Name: Cy_I2S_GetRxInterruptStatusMasked
****************************************************************************//**
*
* Returns the interrupt status masked (a content of the RX_INTR_MASKED register).
*
* \param base The pointer to the I2S->RX instance address.
*
* \return The interrupt bit mask(s).
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I2S_GetRxInterruptStatusMasked(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    return (base->unINTR_RX_MASKED.u32Register);
}

/*******************************************************************************
* Function Name: Cy_I2S_SetRxTriggerInterruptMask
****************************************************************************//**
*
* Sets RX Trigger Interrupt mask.
*
* \param base The pointer to the I2S->RX instance address.
*
* \return None.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_SetRxTriggerInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    base->unINTR_RX_MASK.stcField.u1FIFO_TRIGGER = 1u;
}

/*******************************************************************************
* Function Name: Cy_I2S_ClearRxTriggerInterruptMask
****************************************************************************//**
*
* Clearss RX Trigger Interrupt mask.
*
* \param base The pointer to the I2S->RX instance address.
*
* \return None.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I2S_ClearRxTriggerInterruptMask(volatile stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t * base)
{
    base->unINTR_RX_MASK.stcField.u1FIFO_TRIGGER = 0u;	
}

/** \} group_i2s_functions */

#ifdef __cplusplus
}
#endif

#endif /* CY_IP_MXAUDIOSS */

#endif /* CY_I2S_H */

/** \} group_i2s */


/* [] END OF FILE */
