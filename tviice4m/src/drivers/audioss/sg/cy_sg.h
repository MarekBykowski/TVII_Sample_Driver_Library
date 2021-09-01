/***************************************************************************//**
* \file cy_sg.h
* \version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
* 
* Provides an API declaration of the SG driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2018, Cypress Semiconductor Corporation. All rights reserved.
* Copyright 2016-2019, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_sg Audio Sound Generator (SG)
* \{
* A sound generator produces PWM tone (frequency) and amplitude (volume) signals
* (the sound generator does not produce PCM signals).
*
* Features:
* * PWM modulated (amplitude, tone) sound generation.
* * ÅDouble buffered segment structure control.
* * Separate volume and frequency control (two signals) and
* * combined volume-frequency control (one signal) formats.
* * Programmable interface clock.
*
* \section group_sg_configuration_considerations Configuration Considerations
*
* To set up an SG, provide the configuration parameters in the
* \ref cy_stc_sg_config_t structure. 
*
* \section group_sg_more_information More Information
* See: the SG chapter of the device technical reference manual (TRM);
*      PG Component datasheet;
*
* \defgroup group_sg_macros Macro
* \defgroup group_sg_functions Functions
* \defgroup group_sg_data_structures Data structures
* \defgroup group_sg_enums Enumerated types
*/

#if !defined CY_SG_H
#define CY_SG_H

#include <stddef.h>
#include <stdbool.h>
#include "syslib/cy_syslib.h"
#include "syspm/cy_syspm.h"


#ifdef CY_IP_MXSG

#ifdef __cplusplus
extern "C" {
#endif

/** \addtogroup group_sg_macros
* \{
*/

/** The driver major version */
#define CY_SG_DRV_VERSION_MAJOR       `$CY_MAJOR_VERSION`

/** The driver minor version */
#define CY_SG_DRV_VERSION_MINOR       `$CY_MINOR_VERSION`

/** The SG driver identifier */
#define CY_SG_ID                      (CY_PDL_DRV_ID(0x25U))


/**
* \defgroup group_sg_macros_intrerrupt_masks Interrupt Masks
* \{
*/

/** Bit 0: Completion of a segment descriptor. */
#define CY_SG_INTR_TX_COMPLETE       (SG_SG_STRUCT_INTR_TX_COMPLETE_Msk)
/** Bit 2: Set when new segment structure in not valid/available. */
#define CY_SG_INTR_TX_UNDERFLOW	     (SG_SG_STRUCT_INTR_TX_UNDERFLOW_Msk)
/** Bit 8: Interface frequency is higher than PCM sample frequency. */
#define CY_SG_INTR_TX_IF_UNDERFLOW   (SG_SG_STRUCT_INTR_TX_IF_UNDERFLOW_Msk)

/** \} group_sg_macros_intrerrupt_masks */

/**
* \addtogroup group_sg_enums
* \{
*/

/**
* SG status definitions.
*/

typedef enum 
{
    CY_SG_SUCCESS    = 0x00UL,                                   /*< Successful. */
    CY_SG_BAD_PARAM  = CY_SG_ID | CY_PDL_STATUS_ERROR | 0x01UL,  /*< One or more invalid parameters. */
    CY_SG_BAD_STATUS = CY_SG_ID | CY_PDL_STATUS_ERROR | 0x02UL,  /*< The SG APIs receive wrong parameters. */
} cy_en_sg_status_t;

typedef enum
{
    CY_SG_SEPARATE    = 0U,    /**< Output format is separately driven amplitude signal and tone signal (two signals). */
    CY_SG_COMBINED    = 1U,    /**< Output format is the logical AND of the amplitude signal and tone signal (one signals). */
} cy_en_sg_format_t;

typedef enum
{
    CY_SG_SEL_SRSS_CLK0 = 0U, /**< Interface clock is selected as clk_if_srss[0]. */
    CY_SG_SEL_SRSS_CLK1 = 1U, /**< Interface clock is selected as clk_if_srss[1]. */
    CY_SG_SEL_SRSS_CLK2 = 2U, /**< Interface clock is selected as clk_if_srss[2]. */
    CY_SG_SEL_SRSS_CLK3 = 3U, /**< Interface clock is selected as clk_if_srss[3]. */
    CY_SG_SEL_SG_MCK_IN = 4U, /**< Interface clock is selected as sg_mck_in. */
} cy_en_sg_clock_sel_t;
/** \} group_sg_enums */

/**
* \addtogroup group_sg_data_structures
* \{
*/
/**
* SG initialization configuration.
*/
typedef struct
{
    uint8_t                      clkDiv;         /**< CLK_SEL divider value is +1, 1: 1/2, 2: 1/3, 3: 1/4, ..., 255: 1/256. */
    cy_en_sg_clock_sel_t         clkSel;            /**< Clock selection value, see #cy_en_sg_clock_sel_t. */
    cy_en_sg_format_t            format;            /**< Output format, see: #cy_en_sg_format_t. */
} cy_stc_sg_config_t;

typedef struct
{
    uint8_t            timePeriod;     /*Time period in tone periods. */
    uint8_t            timeNR;         /*Segment in time periods. */
    uint8_t            tonePeriod;     /*Tone period in amplitude periods. */
    uint8_t            toneHigh;       /*High/'1' time of the generated tone PWM signals. */
    uint16_t           amplPeriod;     /*Amplitude period in interface clock "clk_pwm" cycles. */
    uint16_t           amplHigh;       /*High/'1' time of the generated amplitude PWM waveform. */
    uint16_t           stepSize;       /*Amplitude step size of the generated PWM waveform. */
    bool               stepValid;      /*Validity or invalidity of segment structure. */
} cy_stc_sg_segment_t;

typedef struct
{
    uint32_t              size;              /* Size of the segment structures. */
    uint32_t              currentPosition;   /* How far the sound generation has complete. */
    cy_stc_sg_segment_t   *topSegment;       /* Address of the top segment. */
    bool                  finishFlag;        /* Flag which indicates all data transmission is finished. */
} cy_sg_segment_t;


/** \} group_sg_data_structures */

/** \cond INTERNAL */
/******************************************************************************
 * Local definitions
*******************************************************************************/

#define CY_SG_INTR_TX_MASK            (CY_SG_INTR_TX_COMPLETE    | \
                                                CY_SG_INTR_TX_UNDERFLOW | \
                                                CY_SG_INTR_TX_IF_UNDERFLOW)

/* Non-zero default values for IF_CTL register */
#define CY_SG_IF_CTL_CLOCK_DIV_DEFAULT    (0x7U)    /**< Default clock is clk_if/(CLOCK_DIV+1) */
#define CY_SG_IF_CTL_CLOCK_SEL_DEFAULT    (0x7U)    /**< Default clock is selected as clk_if_srss[0], later it will be off */
#define CY_SG_IF_CTL_DEFAULT            (_VAL2FLD(SG_SG_STRUCT_IF_CTL_CLOCK_DIV, CY_SG_IF_CTL_CLOCK_DIV_DEFAULT)  | \
                                                _VAL2FLD(SG_SG_STRUCT_IF_CTL_CLOCK_SEL, CY_SG_IF_CTL_CLOCK_SEL_DEFAULT))

/* Macros for conditions used by CY_ASSERT calls */
#define CY_SG_CLK_DIV_VALID(clkDiv)    (clkDiv < 0x100)

#define CY_SG_FORMAT_VALID(format)    ((CY_SG_SEPARATE == (format)) || \
                        (CY_SG_COMBINED == (format)))

#define CY_SG_CLOCK_VALID(clock_sel)        ((CY_SG_SEL_SRSS_CLK0 == (clock_sel))  || \
                        (CY_SG_SEL_SRSS_CLK1 == (clock_sel))    || \
                        (CY_SG_SEL_SRSS_CLK2 == (clock_sel))    || \
                        (CY_SG_SEL_SRSS_CLK3 == (clock_sel))    || \
                        (CY_SG_SEL_SG_MCK_IN == (clock_sel)))

#define CY_SG_INTR_TX_MASK_VALID(interrupt) (0UL == ((interrupt) & ((uint32_t) ~CY_SG_INTR_TX_MASK)))

#define CY_SG_CHANNEL_VALID(channel)        ((CY_SG_CH0 == (channel))    || \
                                        ((CY_SG_CH1 == (channel))    || \
                                        ((CY_SG_CH2 == (channel))    || \
                                        ((CY_SG_CH3 == (channel))    || \
                                        ((CY_SG_CH4 == (channel)))

/** \endcond */


/**
* \addtogroup group_sg_functions
* \{
*/

cy_en_sg_status_t        Cy_SG_Init(volatile stc_SG_SG_STRUCT_t * base, cy_stc_sg_config_t const * config);
void                     Cy_SG_DeInit(volatile stc_SG_SG_STRUCT_t * base);
cy_en_sg_status_t        Cy_SG_StartSegment(volatile stc_SG_SG_STRUCT_t * base, cy_stc_sg_segment_t * InputData, uint32_t Size, cy_sg_segment_t * context);
uint32_t                 Cy_SG_PushSegment(volatile stc_SG_SG_STRUCT_t * base, cy_stc_sg_segment_t * InputData, cy_sg_segment_t * context);

__STATIC_INLINE void     Cy_SG_EnableSource(volatile stc_SG_SG_STRUCT_t * base);
__STATIC_INLINE void     Cy_SG_DisableSource(volatile stc_SG_SG_STRUCT_t * base);
__STATIC_INLINE void     Cy_SG_Active(volatile stc_SG_SG_STRUCT_t * base);
__STATIC_INLINE void     Cy_SG_Inactive(volatile stc_SG_SG_STRUCT_t * base);

__STATIC_INLINE uint32_t Cy_SG_GetInterruptStatus(volatile stc_SG_SG_STRUCT_t * base);
__STATIC_INLINE void     Cy_SG_ClearInterrupt(volatile stc_SG_SG_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE void     Cy_SG_SetInterrupt(volatile stc_SG_SG_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE uint32_t Cy_SG_GetInterruptMask(volatile stc_SG_SG_STRUCT_t * base);
__STATIC_INLINE void     Cy_SG_SetInterruptMask(volatile stc_SG_SG_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE uint32_t Cy_SG_GetInterruptStatusMasked(volatile stc_SG_SG_STRUCT_t * base);

/*******************************************************************************
* Function Name: Cy_SG_EnableSource
****************************************************************************//**
*
* Enables the sound generator.
*
* \param base The pointer to the SG instance address.
*
* \return None.
*
*******************************************************************************/
__STATIC_INLINE void     Cy_SG_EnableSource(volatile stc_SG_SG_STRUCT_t * base)
{
    base->unCTL.stcField.u1ENABLED = 1u;
}

/*******************************************************************************
* Function Name: Cy_SG_DisableSource
****************************************************************************//**
*
* Disables the sound generator.
*
* \param base The pointer to the SG instance address.
*
* \return None.
*
*******************************************************************************/
__STATIC_INLINE void     Cy_SG_DisableSource(volatile stc_SG_SG_STRUCT_t * base)
{
    base->unCTL.stcField.u1ENABLED = 0u;
}

/*******************************************************************************
* Function Name: Cy_SG_Active
****************************************************************************//**
*
* Transmitter on. Starts the sound generation process.
*
* \param base The pointer to the SG instance address.
*
* \return None.
*
*******************************************************************************/
__STATIC_INLINE void     Cy_SG_Active(volatile stc_SG_SG_STRUCT_t * base)
{
    base->unCTL.stcField.u1ACTIVE = 1u;
}

/*******************************************************************************
* Function Name: Cy_SG_Inactive
****************************************************************************//**
*
* Transmitter off. Stops the sound generation process.
*
* \param base The pointer to the SG instance address.
*
* \return None.
*
*******************************************************************************/
__STATIC_INLINE void     Cy_SG_Inactive(volatile stc_SG_SG_STRUCT_t * base)
{
    base->unCTL.stcField.u1ACTIVE = 0u;
}

/*******************************************************************************
* Function Name: Cy_SG_GetInterruptStatus
****************************************************************************//**
*
* Gets an interrupt status (returns a content of the INTR register).
*
* \param base The pointer to the SG instance address.
*
* \return
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SG_GetInterruptStatus(volatile stc_SG_SG_STRUCT_t * base)
{
    return (base->unINTR_TX.u32Register);
}

/*******************************************************************************
* Function Name: Cy_SG_ClearInterrupt
****************************************************************************//**
*
* Clears one or more interrupt factors (sets the INTR register).
*
* \param base The pointer to the SG instance address.
*
* \param interrupt Interrupt bit mask.
*
* \funcusage
* \
*
*******************************************************************************/
__STATIC_INLINE void     Cy_SG_ClearInterrupt(volatile stc_SG_SG_STRUCT_t * base, uint32_t interrupt)
{
    base->unINTR_TX.u32Register = interrupt;
}

/*******************************************************************************
* Function Name: Cy_SG_SetInterrupt
****************************************************************************//**
*
* Sets one or more interrupt factors (sets the INTR_SET register).
*
* \param base The pointer to the SG instance address.
*
* \param interrupt Interrupt bit mask.
*
* \Note This is for debugging purpose.
*
*******************************************************************************/
__STATIC_INLINE void     Cy_SG_SetInterrupt(volatile stc_SG_SG_STRUCT_t * base, uint32_t interrupt)
{
    base->unINTR_TX.u32Register = interrupt;
}
    
/*******************************************************************************
* Function Name: Cy_SG_GetInterruptMask
****************************************************************************//**
*
* Returns the interrupt mask (a content of the INTR_MASK register).
*
* \param base The pointer to the SG instance address.
*
* \return
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SG_GetInterruptMask(volatile stc_SG_SG_STRUCT_t * base)
{
    return (base->unINTR_TX_MASK.u32Register);
}

/*******************************************************************************
* Function Name: Cy_SG_SetInterruptMask
****************************************************************************//**
*
* Sets one or more interrupt factor masks (the INTR_MASK register).
*
* \param base The pointer to the SG instance address.
*
* \param interrupt Interrupt bit mask.
*
* \return None.
*
*******************************************************************************/
__STATIC_INLINE void     Cy_SG_SetInterruptMask(volatile stc_SG_SG_STRUCT_t * base, uint32_t interrupt)
{
    base->unINTR_TX_MASK.u32Register = interrupt;
}

/*******************************************************************************
* Function Name: Cy_SG_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns the interrupt status masked (a content of the INTR_MASKED register).
*
* \param base The pointer to the SG instance address.
*
* \return
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SG_GetInterruptStatusMasked(volatile stc_SG_SG_STRUCT_t * base)
{
    return (base->unINTR_TX_MASKED.u32Register);
}


/** \} group_sg_functions */

#ifdef __cplusplus
}
#endif

#endif /* CY_IP_MXSG */

#endif /* CY_SG_H */

/** \} group_pwm */


/* [] END OF FILE */
