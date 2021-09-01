/***************************************************************************//**
* \file cy_pwm.h
* \version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
* 
* The header file of the PWM driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2018, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_pwm Audio Pulse Width Modulation (PWM)
* \{
* A PWM interface drives PWM output lines and their complementary output lines. 
* Typically, the PWM destinations are E-bridges or H-bridges which drive low cost 
* speakers. The IP processes pulse code modulated (PCM) input signals into pulse width
* modulated (PWM) output signals..
*
* Features:
* * Programmable interface clock.
* * Programmable doubling mode.
* * Programmable gain.
* * Programmable pulse width modulation.
* * Programmable PCM sample formatting (8, 10, 12, 14, 16, 18, 20, 24, 32 bits).
* * 64 entry TX FIFO with interrupt and Datawire trigger support.
*
* \section group_pwm_configuration_considerations Configuration Considerations
*
* To set up an PWM, provide the configuration parameters in the
* \ref cy_stc_pwm_config_t structure. 
*
* \section group_pwm_more_information More Information
* See: the the PWM chapter of the device technical reference manual (TRM);
*      PWM Component datasheet;
*
* \section group_pwm_changelog Changelog
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
* \defgroup group_pwm_macros Macros
* \defgroup group_pwm_functions Functions
*   \{
*       \defgroup group_pwm_functions_syspm_callback  Low Power Callback
*   \}
* \defgroup group_pwm_data_structures Data Structures
* \defgroup group_pwm_enums Enumerated Types
*/

#if !defined CY_PWM_H
#define CY_PWM_H

#include <stddef.h>
#include <stdbool.h>
#include "syslib/cy_syslib.h"
#include "syspm/cy_syspm.h"

#ifdef CY_IP_MXPWM

#ifdef __cplusplus
extern "C" {
#endif

/** \addtogroup group_pwm_macros
* \{
*/

/** The driver major version */
#define CY_PWM_DRV_VERSION_MAJOR       `$CY_MAJOR_VERSION`

/** The driver minor version */
#define CY_PWM_DRV_VERSION_MINOR       `$CY_MINOR_VERSION`

/** The PWM driver identifier */
#define CY_PWM_ID                      (CY_PDL_DRV_ID(0x21U))


/**
* \defgroup group_pwm_macros_intrerrupt_masks Interrupt Masks
* \{
*/

/** Bit 0: Less entries in the TX FIFO than specified by Trigger Level. */
#define CY_PWM_INTR_TX_FIFO_TRIGGER     (PWM_TX_INTR_TX_FIFO_TRIGGER_Msk)
/** Bit 1: Attempt to write to a full TX FIFO. */
#define CY_PWM_INTR_TX_FIFO_OVERFLOW	(PWM_TX_INTR_TX_FIFO_OVERFLOW_Msk)
/** Bit 2: Attempt to read from an empty TX FIFO. */
#define CY_PWM_INTR_TX_FIFO_UNDERFLOW	(PWM_TX_INTR_TX_FIFO_UNDERFLOW_Msk)
/** Bit 8: Interface frequency is higher than PCM sample frequency. */
#define CY_PWM_INTR_TX_IF_UNDERFLOW 	(PWM_TX_INTR_TX_IF_UNDERFLOW_Msk)

/** \} group_pwm_macros_intrerrupt_masks */


/**
* \addtogroup group_pwm_enums
* \{
*/

/**
* PWM status definitions.
*/

typedef enum 
{
    CY_PWM_SUCCESS   = 0x00UL,                                  /**< Successful. */
    CY_PWM_BAD_PARAM = CY_PWM_ID | CY_PDL_STATUS_ERROR | 0x01UL /**< One or more invalid parameters. */
} cy_en_pwm_tx_status_t;

typedef enum
{
    CY_PWM_WORD_LEN8 	= 0U, /**< Channel/word length:  8 bit. */
    CY_PWM_WORD_LEN10	= 1U, /**< Channel/Word length: 10 bit. */
    CY_PWM_WORD_LEN12	= 2U, /**< Channel/Word length: 12 bit. */
    CY_PWM_WORD_LEN14	= 3U, /**< Channel/Word length: 14 bit. */
    CY_PWM_WORD_LEN16	= 4U, /**< Channel/Word length: 16 bit. */
    CY_PWM_WORD_LEN18	= 5U, /**< Channel/Word length: 18 bit. */
    CY_PWM_WORD_LEN20	= 6U, /**< Channel/Word length: 20 bit. */
    CY_PWM_WORD_LEN24	= 7U, /**< Channel/Word length: 24 bit. */
    CY_PWM_WORD_LEN32	= 8U  /**< Channel/Word length: 32 bit. */
} cy_en_pwm_tx_ws_t;

typedef enum
{
    CY_PWM_TX_E_BRIDGE	= 0U,	/**< E-bridge format line1 p/n will be used. */
    CY_PWM_TX_H_BRIDGE	= 1U,	/**< H-bridge format line1 p/n and line2 p/n will be used. */
} cy_en_pwm_tx_format_t;

typedef enum
{
    CY_PWM_SEL_SRSS_CLK0        = 0U, /**< Interface clock is selected as clk_if_srss[0]. */
    CY_PWM_SEL_SRSS_CLK1	= 1U, /**< Interface clock is selected as clk_if_srss[1]. */
    CY_PWM_SEL_SRSS_CLK2	= 2U, /**< Interface clock is selected as clk_if_srss[2]. */
    CY_PWM_SEL_SRSS_CLK3	= 3U, /**< Interface clock is selected as clk_if_srss[3]. */
    CY_PWM_SEL_PWM_MCK_IN	= 4U, /**< Interface clock is selected as pwm_mck_in. */
} cy_en_pwm_tx_clock_sel_t;

typedef enum
{											/**< Line1_p, Line1_n, Line2_p and Line2_n output signal. */
    CY_PWM_LINE1_P_OUT_LINE1_N_OUT_LINE2_P_OUT_LINE2_N_OUT                      =  0U,	/**< 	0	0	0	0			  */
    CY_PWM_LINE1_P_INV_OUT_LINE1_N_OUT_LINE2_P_OUT_LINE2_N_OUT			=  1U,	/**< 	1	0	0	0			  */
    CY_PWM_LINE1_P_OUT_LINE1_N_INV_OUT_LINE2_P_OUT_LINE2_N_OUT			=  2U,	/**< 	0	1	0	0			  */
    CY_PWM_LINE1_P_INV_OUT_LINE1_N_INV_OUT_LINE2_P_OUT_LINE2_N_OUT		=  3U,	/**< 	1	1	0	0			  */
    CY_PWM_LINE1_P_OUT_LINE1_N_OUT_LINE2_P_INV_OUT_LINE2_N_OUT			=  4U,	/**< 	0	0	1	0			  */
    CY_PWM_LINE1_P_INV_OUT_LINE1_N_OUT_LINE2_P_INV_OUT_LINE2_N_OUT		=  5U,	/**< 	1	0	1	0			  */
    CY_PWM_LINE1_P_OUT_LINE1_N_INV_OUT_LINE2_P_INV_OUT_LINE2_N_OUT		=  6U,	/**< 	1	1	1	0			  */
    CY_PWM_LINE1_P_INV_OUT_LINE1_N_INV_OUT_LINE2_P_INV_OUT_LINE2_N_OUT		=  7U,	/**< 	1	1	1	0			  */
    CY_PWM_LINE1_P_OUT_LINE1_N_OUT_LINE2_P_OUT_LINE2_N_INV_OUT			=  8U,	/**< 	0	0	0	1			  */
    CY_PWM_LINE1_P_INV_OUT_LINE1_N_OUT_LINE2_P_OUT_LINE2_N_INV_OUT		=  9U,	/**< 	1	0	0	1			  */
    CY_PWM_LINE1_P_OUT_LINE1_N_INV_OUT_LINE2_P_OUT_LINE2_N_INV_OUT		= 10U,	/**< 	0	1	0	1			  */
    CY_PWM_LINE1_P_INV_OUT_LINE1_N_INV_OUT_LINE2_P_OUT_LINE2_N_INV_OUT		= 11U,	/**< 	1	1	0	1			  */
    CY_PWM_LINE1_P_OUT_LINE1_N_OUT_LINE2_P_INV_OUT_LINE2_N_INV_OUT		= 12U,	/**< 	0	0	1	1			  */
    CY_PWM_LINE1_P_INV_OUT_LINE1_N_OUT_LINE2_P_INV_OUT_LINE2_N_INV_OUT		= 13U,	/**< 	1	0	1	1			  */
    CY_PWM_LINE1_P_OUT_LINE1_N_INV_OUT_LINE2_P_INV_OUT_LINE2_N_INV_OUT		= 14U,	/**< 	0	1	1	1			  */
    CY_PWM_LINE1_P_INV_OUT_LINE1_N_INV_OUT_LINE2_P_INV_OUT_LINE2_N_INV_OUT	= 15U,	/**< 	1	1	1	1			  */
} cy_en_pwm_tx_line_polarity_t;

typedef enum
{
    CY_PWM_TX_DOUBLE_REPETITION	= 0U,	/**< An additional sample is created by repeating each TX FIFO data sample. */
    CY_PWM_TX_DOUBLE_AVERAGING	= 1U,	/**< An additional sample is calculated by averaging two consecutive TX FIFO data samples. */
} cy_en_pwm_tx_double_mode_t;


typedef enum
{
    CY_PWM_TX_CH_DISABLE	= 0u,	/**< PWM transmitter channel disable. */
    CY_PWM_TX_CH0_ENABLE	= 1U,	/**< PWM transmitter channel 0 enable. */
    CY_PWM_TX_CH1_ENABLE	= 2U,	/**< PWM transmitter channel 1 enable. */
    CY_PWM_TX_CH0_CH1_ENABLE	= 3U,	/**< PWM transmitter channel 0 and 1 enable. */
} cy_en_pwm_tx_ch_enable_t;

/** \} group_pwm_enums */

/**
* \addtogroup group_pwm_data_structures
* \{
*/

/**
* PWM initialization configuration.
*/
typedef struct
{
    bool				txEnabled;		/**< Enables the PWM TX component: 'false': disabled. 'true': enabled. */
    cy_en_pwm_tx_ws_t			txWordSize;		/**< TX word length, see #cy_en_pwm_tx_ws_t. */
    uint8_t				txClkDiv;		/**< CLK_SEL divider value is +1, 1: 1/2, 2: 1/3, 3: 1/4, ..., 255: 1/256. */
    cy_en_pwm_tx_clock_sel_t		txClkSel;		/**< Clock selection value, see #cy_en_pwm_tx_clock_sel_t. */
    cy_en_pwm_tx_line_polarity_t        txLineOutPolarity;	/**< PWM out signal polarity 0: as it 1: inverted, see #cy_en_pwm_tx_line_polarity_t. */
    bool				txDoublerEnabled;	/**< Enables the double TX mode: 'false': disabled. 'true': enabled. */
    cy_en_pwm_tx_double_mode_t		txDoublerMode;		/**< Check for the doubler FIFO mode, see #cy_en_pwm_tx_double_mode_t. */
    uint8_t				txGainCode;		/**< TX gain control value is 0: digital mute, 1: -114dB, 2: -113dB, 115: 0dB(same signal), ..., 127: 12dB(max). */
    cy_en_pwm_tx_format_t		txFormat;		/**< TX output format, see: #cy_en_pwm_tx_format_t. */
    uint8_t				txGainScale;		/**< Scaling id performed as gain correction of PCM signal, 0 to 15(max). */
    uint16_t				pwmMinValue;		/**< Minimum PWM clip value range from 0 to 65535(max), default: 0. */
    uint16_t				pwmMaxValue;		/**< Maximum PWM clip value range from 0 to 65535(max), default: 65535. */
    uint16_t				pwmPeriod;		/**< Period in PWM interface clock cycles, range from 0 to 65535(max), default: 65535. */
    uint16_t				pwmOffset;		/**< Offset is typical half of the period from 0 to 65535(max), default: 32768. */
    uint16_t				pwmDeadTime;		/**< Dead time in PWM interface clock cycles, range from 0 to 65535(max), default: 0. */
    uint8_t               		txFifoTriggerLevel;	/**< TX FIFO trigger level (0, 1, ..., 63). */
} cy_stc_pwm_tx_config_t;


/**
 * The PWM backup structure type to be used for the SysPm callback.
 * \ref Cy_PWM_DeepSleepCallback context definition.
 *
 * \cond Also can be used for other purposes to store the current Tx/Rx
 * operation state and interrupt settings - the factors that are usually
 * changed on the fly. \endcond
 */
typedef struct
{
    uint32_t enableTxState;     /**< Stores the PWM->TX state */
    uint32_t interruptTxMask;   /**< Stores the PWM->TX interrupt mask */
} cy_stc_pwm_tx_context_t;

/** \} group_pwm_data_structures */

/** \cond INTERNAL */
/******************************************************************************
 * Local definitions
*******************************************************************************/

#define CY_PWM_TX_INTR_MASK				(CY_PWM_INTR_TX_FIFO_TRIGGER	| \
                                                        CY_PWM_INTR_TX_FIFO_OVERFLOW	| \
			                                CY_PWM_INTR_TX_FIFO_UNDERFLOW	| \
			                                CY_PWM_INTR_TX_IF_UNDERFLOW)

/* Non-zero default values for TX_IF_CTL register */
#define CY_PWM_TX_IF_CTL_CLOCK_DIV_DEFAULT		(0x7U)		/**< Default clock is divide/8. */
#define CY_PWM_TX_IF_CTL_CLOCK_SEL_DEFAULT		(0x7U)		/**< Default clock is selected as clk_if_srss[0], later it will be off */
#define CY_PWM_TX_IF_CTL_DEFAULT			(_VAL2FLD(PWM_TX_IF_CTL_CLOCK_DIV, CY_PWM_TX_IF_CTL_CLOCK_DIV_DEFAULT)	| \
							_VAL2FLD(PWM_TX_IF_CTL_CLOCK_SEL, CY_PWM_TX_IF_CTL_CLOCK_SEL_DEFAULT))

/* Non-zero default values for GAIN_CTL register */
#define CY_PWM_TX_GAIN_CTL_CODE_DEFAULT			(0x73U)		/**< Default gain is +115(0dB). */
#define CY_PWM_TX_GAIN_CTL_DEFAULT			(_VAL2FLD(PWM_TX_GAIN_CTL_CODE, CY_PWM_TX_GAIN_CTL_CODE_DEFAULT))

/* Non-zero default values for PWM_CTL0 register */
#define CY_PWM_TX_PWM_CTL0_SCALE_DEFAULT		(0x8U)		/**< Default scale is +8. */
#define CY_PWM_TX_PWM_CTL0_DEFAULT			(_VAL2FLD(PWM_TX_PWM_CTL0_SCALE, CY_PWM_TX_PWM_CTL0_SCALE_DEFAULT))

/* Non-zero default values for PWM_CTL1 register */
#define CY_PWM_TX_PWM_CTL1_MAX_DEFAULT			(0xFFFF)	/**< Default max value is 65535. */
#define CY_PWM_TX_PWM_CTL1_DEFAULT						(_VAL2FLD(PWM_TX_PWM_CTL1_MAX, CY_PWM_TX_PWM_CTL1_MAX_DEFAULT))

/* Non-zero default values for PWM_CTL2 register */
#define CY_PWM_TX_PWM_CTL2_PERIOD_DEFAULT		(0xFFFF)	/**< Default period is 65535. */
#define CY_PWM_TX_PWM_CTL2_OFFSET_DEFAULT		(0x8000)	/**< Default offset is 32768. */
#define CY_PWM_TX_PWM_CTL2_DEFAULT			(_VAL2FLD(PWM_TX_PWM_CTL2_PERIOD, CY_PWM_TX_PWM_CTL2_PERIOD_DEFAULT)	| \
							_VAL2FLD(PWM_TX_PWM_CTL2_OFFSET, CY_PWM_TX_PWM_CTL2_OFFSET_DEFAULT))

/* Macros for conditions used by CY_ASSERT calls */
#define CY_PWM_IS_CLK_DIV_VALID(clkDiv)			(clkDiv < 0x100)
#define CY_PWM_IS_GAIN_CODE_VALID(gain)			(gain <= 0x7F)
#define CY_PWM_IS_GAIN_SCALE_VALID(scale)		(scale <= 0x0F)
#define CY_PWM_IS_CLIP_VALUE_VALID(min, max)            (max <= 0xFFFF)
#define CY_PWM_IS_PERIOD_VALID(period, offset)		(offset <= 0x8000)
#define CY_PWM_IS_TRIG_LEVEL_VALID(trigLevel) 		((trigLevel) <= 63)
#define CY_PWM_IS_FIFO_STATUS_VALID(len, usedStatus)    ((len <= 64) && ((64-usedStatus)>len))

#define CY_PWM_IS_TX_INTR_MASK_VALID(interrupt)		(0UL == ((interrupt) & ((uint32_t) ~CY_PWM_TX_INTR_MASK)))

#define CY_PWM_IS_WORD_LEN_VALID(length)		((CY_PWM_WORD_LEN8 == (length))	|| \
                                                        (CY_PWM_WORD_LEN10 == (length))	|| \
                                                        (CY_PWM_WORD_LEN12 == (length))	|| \
                                                        (CY_PWM_WORD_LEN14 == (length))	|| \
                                                        (CY_PWM_WORD_LEN16 == (length))	|| \
                                                        (CY_PWM_WORD_LEN18 == (length))	|| \
                                                        (CY_PWM_WORD_LEN20 == (length))	|| \
                                                        (CY_PWM_WORD_LEN24 == (length))	|| \
                                                        (CY_PWM_WORD_LEN32 == (length)))

#define CY_PWM_IS_CLOCK_VALID(clock_sel)		((CY_PWM_SEL_SRSS_CLK0 == (clock_sel))	|| \
                                                        (CY_PWM_SEL_SRSS_CLK1  == (clock_sel))	|| \
                                                        (CY_PWM_SEL_SRSS_CLK2  == (clock_sel))	|| \
                                                        (CY_PWM_SEL_SRSS_CLK3  == (clock_sel))	|| \
                                                        (CY_PWM_SEL_PWM_MCK_IN == (clock_sel)))

#define CY_PWM_IS_TX_LINE_POL_VALID(pol)		((CY_PWM_LINE1_P_OUT_LINE1_N_OUT_LINE2_P_OUT_LINE2_N_OUT 		== (pol))	|| \
                                                        (CY_PWM_LINE1_P_INV_OUT_LINE1_N_OUT_LINE2_P_OUT_LINE2_N_OUT 		== (pol))	|| \
                                                        (CY_PWM_LINE1_P_OUT_LINE1_N_INV_OUT_LINE2_P_OUT_LINE2_N_OUT 		== (pol))	|| \
                                                        (CY_PWM_LINE1_P_INV_OUT_LINE1_N_INV_OUT_LINE2_P_OUT_LINE2_N_OUT 	== (pol))	|| \
                                                        (CY_PWM_LINE1_P_OUT_LINE1_N_OUT_LINE2_P_INV_OUT_LINE2_N_OUT 		== (pol))	|| \
                                                        (CY_PWM_LINE1_P_INV_OUT_LINE1_N_OUT_LINE2_P_OUT_LINE2_N_OUT 		== (pol))	|| \
                                                        (CY_PWM_LINE1_P_OUT_LINE1_N_INV_OUT_LINE2_P_INV_OUT_LINE2_N_OUT 	== (pol))	|| \
                                                        (CY_PWM_LINE1_P_INV_OUT_LINE1_N_INV_OUT_LINE2_P_INV_OUT_LINE2_N_OUT 	== (pol))	|| \
                                                        (CY_PWM_LINE1_P_OUT_LINE1_N_OUT_LINE2_P_OUT_LINE2_N_INV_OUT 		== (pol))	|| \
                                                        (CY_PWM_LINE1_P_INV_OUT_LINE1_N_OUT_LINE2_P_OUT_LINE2_N_INV_OUT 	== (pol))	|| \
                                                        (CY_PWM_LINE1_P_OUT_LINE1_N_INV_OUT_LINE2_P_OUT_LINE2_N_INV_OUT 	== (pol))	|| \
                                                        (CY_PWM_LINE1_P_INV_OUT_LINE1_N_INV_OUT_LINE2_P_OUT_LINE2_N_INV_OUT 	== (pol))	|| \
                                                        (CY_PWM_LINE1_P_OUT_LINE1_N_OUT_LINE2_P_INV_OUT_LINE2_N_INV_OUT 	== (pol))	|| \
                                                        (CY_PWM_LINE1_P_INV_OUT_LINE1_N_OUT_LINE2_P_INV_OUT_LINE2_N_INV_OUT 	== (pol))	|| \
                                                        (CY_PWM_LINE1_P_OUT_LINE1_N_INV_OUT_LINE2_P_INV_OUT_LINE2_N_INV_OUT 	== (pol))	|| \
                                                        (CY_PWM_LINE1_P_INV_OUT_LINE1_N_INV_OUT_LINE2_P_INV_OUT_LINE2_N_INV_OUT == (pol)))

#define CY_PWM_IS_DOUBLE_MODE_VALID(mode)		((CY_PWM_TX_DOUBLE_REPETITION == (mode))	|| \
							(CY_PWM_TX_DOUBLE_AVERAGING == (mode)))

#define CY_PWM_IS_FORMAT_VALID(format)			((CY_PWM_TX_E_BRIDGE == (format))	|| \
							(CY_PWM_TX_H_BRIDGE == (format)))

/** \endcond */


/**
* \addtogroup group_pwm_functions
* \{
*/

cy_en_pwm_tx_status_t	Cy_Pwm_Tx_Init(volatile stc_PWM_TX_t * base, cy_stc_pwm_tx_config_t const * config);
void                    Cy_Pwm_Tx_DeInit(volatile stc_PWM_TX_t * base);

cy_en_pwm_tx_status_t   Cy_Pwm_Tx_Enable(volatile stc_PWM_TX_t * base);
void                    Cy_Pwm_Tx_Disable(volatile stc_PWM_TX_t * base);

/** \addtogroup group_pwm_functions_syspm_callback
* The driver supports SysPm callback for Deep Sleep transition.
* \{
*/
cy_en_syspm_status_t	Cy_Pwm_Tx_DeepSleepCallback(cy_stc_syspm_callback_params_t * callbackParams);
/** \} */

__STATIC_INLINE uint32_t Cy_Pwm_Tx_GetCurrentState(volatile stc_PWM_TX_t * base);

__STATIC_INLINE void	 Cy_Pwm_Tx_WriteData(volatile stc_PWM_TX_t * base, uint32_t data);
__STATIC_INLINE void	 Cy_Pwm_Tx_FreezeFifo(volatile stc_PWM_TX_t * base);
__STATIC_INLINE void	 Cy_Pwm_Tx_UnfreezeFifo(volatile stc_PWM_TX_t * base);
__STATIC_INLINE void	 Cy_Pwm_Tx_MuteFifo(volatile stc_PWM_TX_t * base);
__STATIC_INLINE void	 Cy_Pwm_Tx_UnmuteFifo(volatile stc_PWM_TX_t * base);
__STATIC_INLINE uint8_t  Cy_Pwm_Tx_GetNumInFifo(volatile stc_PWM_TX_t * base);
__STATIC_INLINE uint8_t	 Cy_Pwm_Tx_GetReadPointer(volatile stc_PWM_TX_t * base);
__STATIC_INLINE uint8_t	 Cy_Pwm_Tx_GetWritePointer(volatile stc_PWM_TX_t * base);

__STATIC_INLINE void	 Cy_Pwm_Tx_ClearInterrupt(volatile stc_PWM_TX_t * base, uint32_t interrupt);
__STATIC_INLINE void     Cy_Pwm_Tx_SetInterrupt(volatile stc_PWM_TX_t * base, uint32_t interrupt);
__STATIC_INLINE uint32_t Cy_Pwm_Tx_GetInterruptMask(volatile stc_PWM_TX_t * base);
__STATIC_INLINE void     Cy_Pwm_Tx_SetInterruptMask(volatile stc_PWM_TX_t * base, uint32_t interrupt);
__STATIC_INLINE uint32_t Cy_Pwm_Tx_GetInterruptStatusMasked(volatile stc_PWM_TX_t * base);
__STATIC_INLINE void     Cy_Pwm_Tx_SetTriggerInterruptMask(volatile stc_PWM_TX_t * base);
__STATIC_INLINE void     Cy_Pwm_Tx_ClearTriggerInterruptMask(volatile stc_PWM_TX_t * base);


/*******************************************************************************
* Function Name: Cy_Pwm_Tx_GetCurrentState
****************************************************************************//**
*
* Returns the current PWM TX state.
*
* \param base The pointer to the PWM->TX instance address.
*
* \return The current state \ref group_pwm_macros_current_state.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_Pwm_Tx_GetCurrentState(volatile stc_PWM_TX_t * base)
{
    uint32_t retValue = 0;
    volatile stc_PWM_t * pwmBase = PWM0;

    if(base == PWM0_TX0)
    {
    	retValue = (pwmBase->unCTL.stcField.u8ACTIVE) & (0x01);
    }
    else if(base == PWM0_TX1)
    {
    	retValue = (pwmBase->unCTL.stcField.u8ACTIVE) & (0x01 << 1);
    }
    return retValue;
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_WriteData
****************************************************************************//**
*
* Writes data to the TX FIFO. Increases the TX FIFO level.
*
* \param base The pointer to the PWM-TX instance address.
*
* \param data Data to be written to the TX FIFO.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_Pwm_Tx_WriteData(volatile stc_PWM_TX_t * base, uint32_t data)
{
    base->unTX_FIFO_WR.stcField.u32DATA = data;
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_FreezeFifo
****************************************************************************//**
*
* Freezes the TX FIFO. This function is rather for debug purposes.
*
* \param base The pointer to the PWM->TX instance address.
*
* \funcusage
* \
*
* \Note Freeze does not advance the FIFO read pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_Pwm_Tx_FreezeFifo(volatile stc_PWM_TX_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1FREEZE = 1u;
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_UnfreezeFifo
****************************************************************************//**
*
* Unfreezes the TX FIFO. This function is rather for debug purposes.
*
* \param base The pointer to the PWM->TX instance address.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_Pwm_Tx_UnfreezeFifo(volatile stc_PWM_TX_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1FREEZE = 0u;
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_MuteFifo
****************************************************************************//**
*
* Mute the TX FIFO. HW uses a constant data value of 0.
*
* \param base The pointer to the PWM->TX instance address.
*
* \funcusage
* \
*
* \Note Mute does advance the FIFO read pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_Pwm_Tx_MuteFifo(volatile stc_PWM_TX_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1MUTE = 1u;
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_UnmuteFifo
****************************************************************************//**
*
* Unmute the TX FIFO.
*
* \param base The pointer to the PWM->TX instance address.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_Pwm_Tx_UnmuteFifo(volatile stc_PWM_TX_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1MUTE = 0u;
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_GetNumInFifo
****************************************************************************//**
*
* Get the number of used/occupied entries in the TX FIFO.
*
* \param base The pointer to the PWM->TX instance address.
*
* \funcusage
* \
*
* \Note range is 0 to 64(Full).
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_Pwm_Tx_GetNumInFifo(volatile stc_PWM_TX_t * base)
{
    return (base->unTX_FIFO_STATUS.stcField.u7USED);
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_GetReadPointer
****************************************************************************//**
*
* Get the TX FIFO location from which a data is read.
*
* \param base The pointer to the PWM->TX instance address.
*
* \funcusage
* \
*
* \Note this is for dubugging purpose.
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_Pwm_Tx_GetReadPointer(volatile stc_PWM_TX_t * base)
{
    return (uint8_t)(base->unTX_FIFO_STATUS.stcField.u6RD_PTR);
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_GetWritePointer
****************************************************************************//**
*
* Get the TX FIFO location at which new data is written.
*
* \param base The pointer to the PWM->TX instance address.
*
* \funcusage
* \
*
* \Note this is for dubugging purpose.
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_Pwm_Tx_GetWritePointer(volatile stc_PWM_TX_t * base)
{
    return (uint8_t)(base->unTX_FIFO_STATUS.stcField.u6WR_PTR);
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_ClearInterrupt
****************************************************************************//**
*
* Clears one or more interrupt factors from the TX interrupt register.
*
* \param base The pointer to the PWM->TX instance address.
*
* \param interrupt Interrupt bit mask.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_Pwm_Tx_ClearInterrupt(volatile stc_PWM_TX_t * base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_PWM_IS_TX_INTR_MASK_VALID(interrupt));
    base->unINTR_TX.u32Register = interrupt;
    (void) base->unINTR_TX.u32Register;
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_SetInterrupt
****************************************************************************//**
*
* Sets one or more interrupt factors in the TX interrupt register.
*
* \param base The pointer to the PWM->TX instance address.
*
* \param interrupt Interrupt bit mask.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_Pwm_Tx_SetInterrupt(volatile stc_PWM_TX_t * base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_PWM_IS_TX_INTR_MASK_VALID(interrupt));
    base->unINTR_TX_SET.u32Register = interrupt;
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_GetInterruptMask
****************************************************************************//**
*
* Returns the interrupt mask in the TX interrupt register.
*
* \param base The pointer to the PWM->TX instance address.
*
* \return The interrupt bit mask.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_Pwm_Tx_GetInterruptMask(volatile stc_PWM_TX_t * base)
{
    return (base->unINTR_TX_MASK.u32Register);
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_SetInterruptMask
****************************************************************************//**
*
* Sets one or more interrupt factor masks in the interrupt mask in the TX interrupt register.
*
* \param base The pointer to the PWM->TX instance address.
*
* \return The interrupt bit mask.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void Cy_Pwm_Tx_SetInterruptMask(volatile stc_PWM_TX_t * base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_PWM_IS_TX_INTR_MASK_VALID(interrupt));
    base->unINTR_TX_MASK.u32Register = interrupt;
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns the interrupt status masked (a content of the TX_INTR_MASKED register).
*
* \param base The pointer to the PWM instance address.
*
* \return The interrupt bit mask(s).
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_Pwm_Tx_GetInterruptStatusMasked(volatile stc_PWM_TX_t * base)
{
    return (base->unINTR_TX_MASKED.u32Register);
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_SetTriggerInterruptMask
****************************************************************************//**
*
* Sets TX Trigger Interrupt mask.
*
* \param base The pointer to the PWM-TX instance address.
*
* \return None.
*
*******************************************************************************/
__STATIC_INLINE void Cy_Pwm_Tx_SetTriggerInterruptMask(volatile stc_PWM_TX_t * base)
{
    base->unINTR_TX_MASK.stcField.u1FIFO_TRIGGER = 1u;
}

/*******************************************************************************
* Function Name: Cy_Pwm_Tx_ClearTriggerInterruptMask
****************************************************************************//**
*
* Clearss TX Trigger Interrupt mask.
*
* \param base The pointer to the PWM-TX instance address.
*
* \return None.
*
*******************************************************************************/
__STATIC_INLINE void Cy_Pwm_Tx_ClearTriggerInterruptMask(volatile stc_PWM_TX_t * base)
{
    base->unINTR_TX_MASK.stcField.u1FIFO_TRIGGER = 0u;	
}

/** \} group_pwm_functions */

#ifdef __cplusplus
}
#endif

#endif /* CY_IP_MXPWM */

#endif /* CY_PWM_H */

/** \} group_pwm */


/* [] END OF FILE */
