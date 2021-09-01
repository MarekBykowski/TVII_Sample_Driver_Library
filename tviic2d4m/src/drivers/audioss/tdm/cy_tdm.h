/*******************************************************************************
* \file tdm.h
* \version 1.0
*
* Provides an API declaration of the audio tdm driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_tdm Audio Time-division multiplexing (TDM)
* \{
* This driver provides global TDM defines and API function definitions.
* A single interface consists of a TDM transmitter and a TDM receiver. 
* Transmitter and receiver can function simultaneously. 
* Both transmitter and receiver support master and slave functionality
*
* \defgroup group_tdm_macros Macro
* \defgroup group_tdm_functions Functions
* \defgroup group_tdm_data_structures Data structures
* \defgroup group_tdm_enums Enumerated types
*/

#if !defined CY_TDM_H
#define CY_TDM_H

#include <stddef.h>
#include <stdbool.h>
#include "syslib/cy_syslib.h"
#include "syspm/cy_syspm.h"


#ifdef CY_IP_MXTDM

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/***
* \addtogroup group_tdm_macros
* \{
*/

/** Driver major version */
#define CY_CPU_DRV_VERSION_MAJOR   1
/** Driver minor version */
#define CY_CPU_DRV_VERSION_MINOR   0
/** The TDM driver identifier */
#define CY_TDM_ID                                  CY_PDL_DRV_ID(0x24u)    // TODO: CY_PDL_DRV_ID for EtherIf
/** \} group_tdm_macros */
/**
* \defgroup group_i2s_macros_intrerrupt_masks Interrupt Masks
* \{
*/

/** Bit 0: Less entries in the TX FIFO than specified by Trigger Level. */
#define CY_TDM_INTR_TX_FIFO_TRIGGER         (TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_FIFO_TRIGGER_Msk)
/** Bit 1: Attempt to write to a full TX FIFO. */
#define CY_TDM_INTR_TX_FIFO_OVERFLOW        (TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_FIFO_OVERFLOW_Msk)
/** Bit 2: Attempt to read from an empty TX FIFO. */
#define CY_TDM_INTR_TX_FIFO_UNDERFLOW       (TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_FIFO_UNDERFLOW_Msk)
/** Bit 8: Interface frequency is higher than PCM sample frequency. */
#define CY_TDM_INTR_TX_IF_UNDERFLOW         (TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_IF_UNDERFLOW_Msk)

/** Bit 0: Less entries in the RX FIFO than specified by Trigger Level. */
#define CY_TDM_INTR_RX_FIFO_TRIGGER         (TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_FIFO_TRIGGER_Msk)
/** Bit 1: Attempt to write to a full RX FIFO. */
#define CY_TDM_INTR_RX_FIFO_OVERFLOW        (TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_FIFO_OVERFLOW_Msk)
/** Bit 2: Attempt to read from an empty RX FIFO. */
#define CY_TDM_INTR_RX_FIFO_UNDERFLOW       (TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_FIFO_UNDERFLOW_Msk)
/** Bit 8: Interface frequency is higher than PCM sample frequency. */
#define CY_TDM_INTR_RX_IF_UNDERFLOW         (TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_IF_OVERFLOW_Msk)

/** \} group_i2s_macros_intrerrupt_masks */

/**
* \addtogroup group_tdm_enums
* \{
*/

typedef enum
{
    CY_TDM_SIZE_8           = 0U, /**< PCM word size:8bit.  */
    CY_TDM_SIZE_10          = 1U, /**< PCM word size:10bit. */
    CY_TDM_SIZE_12          = 2U, /**< PCM word size:12bit. */
    CY_TDM_SIZE_14          = 3U, /**< PCM word size:14bit. */
    CY_TDM_SIZE_16          = 4U, /**< PCM word size:16bit. */
    CY_TDM_SIZE_18          = 5U, /**< PCM word size:18bit. */
    CY_TDM_SIZE_20          = 6U, /**< PCM word size:20bit. */
    CY_TDM_SIZE_24          = 7U, /**< PCM word size:24bit. */
    CY_TDM_SIZE_32          = 8U, /**< PCM word size:32bit. */
} cy_en_tdm_ws_t;

typedef enum
{
    CY_TDM_LEFT_DELATED     = 0, /**< Format is left aligned and delayed. */
    CY_TDM_LEFT             = 1, /**< Format is left aligned. */
    CY_TDM_RIGHT_DELATED    = 2, /**< Format is right aligned and delayed. */
    CY_TDM_RIGHT            = 3, /**< Format is right aligned. */
} cy_en_tdm_format_t;

typedef enum
{
    CY_TDM_DEVICE_SLAVE     = 0U, /**< Device is configured as slave. */
    CY_TDM_DEVICE_MASTER    = 1U, /**< Device is configured as master. */
} cy_en_tdm_device_cfg_t;

typedef enum
{
    CY_ZERO_EXTEND      = 0U,
    CY_SIGN_EXTEND      = 1U,
} cy_en_tdm_word_extend_cfg_t;

typedef enum
{
    CY_TDM_SEL_SRSS_CLK0    = 0U, /**< Interface clock is selected as clk_if_srss[0]. */
    CY_TDM_SEL_SRSS_CLK1    = 1U, /**< Interface clock is selected as clk_if_srss[1]. */
    CY_TDM_SEL_SRSS_CLK2    = 2U, /**< Interface clock is selected as clk_if_srss[2]. */
    CY_TDM_SEL_SRSS_CLK3    = 3U, /**< Interface clock is selected as clk_if_srss[3]. */
    CY_TDM_SEL_TX_MCLK_IN   = 4U, /**< Interface clock is selected as tdm_tx_mclk_in. */
} cy_en_tdm_clock_sel_t;

typedef enum 
{
    CY_TDM_CLK              = 0U, 
    CY_TDM_CLK_INVERTED     = 1U,
} cy_en_tdm_sckpolarity_t;

typedef enum 
{
    CY_TDM_SIGN             = 0U, 
    CY_TDM_SIGN_INVERTED    = 1U,
} cy_en_tdm_fsyncpolarity_t;

typedef enum 
{
    CY_TDM_BIT_PERIOD       = 0U, 
    CY_TDM_CH_PERIOD        = 1U,
} cy_en_tdm_fsyncformat_t;

/**
* TDM status definitions.
*/
typedef enum 
{
    CY_TDM_SUCCESS          = 0x00UL, /**< Successful. */
    CY_TDM_BAD_PARAM        = 0x01UL, /**< One or more invalid parameters. */
} cy_en_tdm_status_t;

typedef enum 
{
    CY_TDM_OK                = 0x00UL,      /*<Successful. */
    CY_TDM_BAD               = 0x01UL,      /*<NG.  */
} cy_en_tdm_source_status_t;

/** \} group_audiodac_enums */

/**
* \addtogroup group_tdm_data_structures
* \{
*/

//TDM Initialization configuration.
typedef struct
{
    bool                        txEnable;               /**<  Enable TDM TX : true: "Enable" false: "Disable" */
    cy_en_tdm_device_cfg_t      txMasterMode;           /**<  see #cy_en_tdm_device_cfg_t */
    cy_en_tdm_ws_t              txWordSize;             /**<  TX word length, see #cy_en_i2s_len_t. Channel size must be greater or equal to the word size.*/
    cy_en_tdm_format_t          txFormat;               /**<  TX data format, see: #cy_en_tdm_format_t. */
    uint16_t                    txClkDiv;               /**<  CLOCK_DIV should be set to an odd value ({1, 3, 5, …, 255}), to ensure a 50/50% duty cycle  clock. */
                                                        /**<  Only for Master Mode */
    cy_en_tdm_clock_sel_t       txClkSel;               /**<  Interface clock "clk_if" selection, see#cy_en_tdm_clock_sel_t. */
    cy_en_tdm_sckpolarity_t     txSckPolarity;          /**<  TX clock polarity, 0 for as is and 1 for inverted. */
    cy_en_tdm_fsyncpolarity_t   txFsyncPolarity;        /**<  Channel synchronization polarity:'false':used "as is". 'true': inverted. */
    cy_en_tdm_fsyncformat_t     txFsyncFormat;          /**<  Channel synchronization pulse format: */
                                                        /**<  '1': Duration of a single bit period.'0': Duration of the first channel.*/
    uint8_t                     txChannelNUM;           /**<  Number of channels in the frame: */
                                                        /**<  "0": Undefined/illegal."1": 2 channels."2": 3 channels...."31":32 channels.*/
                                                        /**<  Note: the field value chould be less than CH_NR (the number of support channels). */
                                                        /**<  Note: the TX_CH_CTL.CH_EN fields can be used to enable/disable indvidual channels. */
    uint8_t                     txChannelSize;          /**<  Channel size:"0": 1 bit."1": 2 bits.…"31": 32 bits. */
                                                        /**<  Note: channel size must be greater or equal to the word size. */
    bool                        txTestMode;             /**<  Test mode enable.'false': Disabled. Functional mode. */
                                                        /**<  'true': Enabled. Test mode (intended to be used with (slave transmitter, master receiver) configuration). */
                                                        /**<  Note: TX_TEST_CTL.ENABLED and RX_TEST_CTL.ENABLED should not be set to '1' simultaneously. */
    uint8_t                    txFIFOTriggerLevel;      /**<  Trigger level. When the TX FIFO has less entries than the number of this field, a transmitter trigger event is generated. */
    uint32_t                   txChEN;                  /**<  Channel enable. */                                                        
}cy_stc_tdm_config_tx_t;

typedef struct
{
    bool                        rxEnable;               /**<  Enable TDM RX : true: "Enable" false: "Disable" */
    cy_en_tdm_device_cfg_t      rxMasterMode;           /**<  see#cy_en_tdm_device_cfg_t */
    cy_en_tdm_ws_t              rxWordSize;             /**<  RX word length, see #cy_en_i2s_len_t. Channel size must be greater or equal to the word size.*/
    cy_en_tdm_word_extend_cfg_t rxSignExtend;           /**<  Word extension */
    cy_en_tdm_format_t          rxFormat;               /**<  RX data format, see: #cy_en_tdm_format_t. */
    uint16_t                    rxClkDiv;               /**<  CLOCK_DIV should be set to an odd value ({1, 3, 5, …, 255}), to ensure a 50/50% duty cycle  clock.*/ 
                                                        /**<  Only for Master Mode */
    cy_en_tdm_clock_sel_t       rxClkSel;               /**<  Interface clock "clk_if" selection, see#cy_en_tdm_clock_sel_t. */
    cy_en_tdm_sckpolarity_t     rxSckPolarity;          /**<  RX clock polarity, 0 for as is and 1 for inverted. */
    cy_en_tdm_fsyncpolarity_t   rxFsyncPolarity;        /**<  Channel synchronization polarity:'false':used "as is". 'true': inverted. */
    bool                        rxLateSample;           /**<  Interface late sample sample delay. */
                                                        /**<  Slave configuration: "false": Sample PCM bit value on rising edge or falling edge of receiver "rx_sck_in  */
                                                        /**<                       "true" : Sample PCM bit value on falling edge or rising edge of receiver "rx_sck_in" (half a cycle delay). */
                                                        /**<  Master configuratio: "false": Sample PCM bit value on rising edge or falling edge of receiver "rx_sck_out". */
                                                        /**<                       "ture" : Sample PCM bit value on falling edge or rising edge of receiver "rx_sck_out" (half a cycle delay). */
                                                        /**<  RISING = 0  FALLING = 1 */
    cy_en_tdm_fsyncformat_t     rxFsyncFormat;          /**<  Channel synchronization pulse format: */
                                                        /**<  'false': Duration of a single bit period.'true': Duration of the first channel.*/
    uint8_t                     rxChannelNUM;           /**<  Number of channels in the frame: */
                                                        /**<  "0": Undefined/illegal."1": 2 channels."2": 3 channels...."31":32 channels.*/
                                                        /**<  Note: the field value chould be less than CH_NR (the number of support channels). */
                                                        /**<  Note: the TX_CH_CTL.CH_EN fields can be used to enable/disable indvidual channels. */
    uint8_t                     rxChannelSize;          /**<  Channel size:"0": 1 bit."1": 2 bits.…"31": 32 bits. */
                                                        /**<  Note: channel size must be greater or equal to the word size. */
    uint32_t                    rxChEN;                 /**<  Channel enable. */  
    bool                        rxTestMode;             /**<  Test mode enable.'false': Disabled. Functional mode. */
                                                        /**<  'true': Enabled. Test mode (intended to be used with (master transmitter, slave receiver) configuration). */
                                                        /**<  Note: TX_TEST_CTL.ENABLED and RX_TEST_CTL.ENABLED should not be set to '1' simultaneously. */
    uint8_t                     rxFIFOTriggerLevel;     /**<  Trigger level. When the TX FIFO has less entries than the number of this field, a transmitter trigger event is generated. */
} cy_stc_tdm_config_rx_t;

typedef struct
{
    cy_stc_tdm_config_tx_t tx_config;
    cy_stc_tdm_config_rx_t rx_config;
}cy_stc_tdm_config_t;

/** \} group_tdm_data_structures */

/** \cond INTERNAL */
/*******************************************************************************/
/*                               Local definitions                             */
/********************************************************************************/

#define CY_TDM_INTR_TX_MASK            (CY_TDM_INTR_TX_FIFO_TRIGGER     |\
                                        CY_TDM_INTR_TX_FIFO_OVERFLOW    |\
                                        CY_TDM_INTR_TX_FIFO_UNDERFLOW   |\
                                        CY_TDM_INTR_TX_IF_UNDERFLOW)
                                        
                                        
#define CY_TDM_INTR_RX_MASK            (CY_TDM_INTR_RX_FIFO_TRIGGER     |\
                                        CY_TDM_INTR_RX_FIFO_OVERFLOW    |\
                                        CY_TDM_INTR_RX_FIFO_UNDERFLOW   |\
                                        CY_TDM_INTR_RX_IF_UNDERFLOW)


/* Non-zero default values for TX_CTL register */
#define CY_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_MS_DEFAULT               (0x1U)  /**<  Default mode is selected as master */

#define CY_TDM_TX_CTL_DEFAULT                                           (_VAL2FLD(TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_MS, CY_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_MS_DEFAULT))

/* Non-zero default values for TX_IF_CTL register */
#define CY_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CLOCK_DIV_DEFAULT     (0x7U)  /**< Default clock is clk_if/(CLOCK_DIV+1) */
#define CY_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CLOCK_SEL_DEFAULT     (0x7U)  /**< Default clock is selected as clk_if_srss[0], later it will be off */
#define CY_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CH_SIZE_DEFAULT       (0x1FU) /**< Default channel size is 32 bits */

#define CY_TDM_TX_IF_CTL_DEFAULT               (_VAL2FLD(TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CLOCK_DIV, CY_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CLOCK_DIV_DEFAULT) | \
                                                _VAL2FLD(TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CLOCK_SEL, CY_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CLOCK_SEL_DEFAULT) | \
                                                _VAL2FLD(TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CH_SIZE, CY_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CH_SIZE_DEFAULT))

/* Non-zero default values for RX_CTL register */
#define CY_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_WORD_SIGN_EXTEND_DEFAULT (0x1U)  /**< Default rx data word with sign extension */

#define CY_TDM_RX_CTL_DEFAULT                   (_VAL2FLD(TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_WORD_SIGN_EXTEND, CY_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_WORD_SIGN_EXTEND_DEFAULT))


/* Non-zero default values for RX_IF_CTL register */
#define CY_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CLOCK_DIV_DEFAULT     (0x7U)  /**< Default clock is clk_if/(CLOCK_DIV+1) */
#define CY_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CLOCK_SEL_DEFAULT     (0x7U)  /**< Default clock is selected as clk_if_srss[0], later it will be off */
#define CY_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CH_SIZE_DEFAULT       (0x1FU) /**< Default channel size is 32 bits */

#define CY_TDM_RX_IF_CTL_DEFAULT               (_VAL2FLD(TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CLOCK_DIV, CY_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CLOCK_DIV_DEFAULT) | \
                                                _VAL2FLD(TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CLOCK_SEL, CY_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CLOCK_SEL_DEFAULT) | \
                                                _VAL2FLD(TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CH_SIZE, CY_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CH_SIZE_DEFAULT))

/** \endcond */

/**
* \addtogroup group_tdm_functions
* \{
*/
/*******************************************************************************/
/*                      Global initialization functions                        */
/*******************************************************************************/

cy_en_tdm_status_t Cy_AudioTDM_Init(volatile stc_TDM_TDM_STRUCT_t * base, cy_stc_tdm_config_t const * config);
void Cy_AudioTDM_DeInit(volatile stc_TDM_TDM_STRUCT_t * base);

cy_en_tdm_status_t Cy_AudioTDM_TX_Init(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base, cy_stc_tdm_config_tx_t const * config);
void Cy_AudioTDM_TX_DeInit(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base);

cy_en_tdm_status_t Cy_AudioTDM_RX_Init(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base, cy_stc_tdm_config_rx_t const * config);
void Cy_AudioTDM_RX_DeInit(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);

/*****************************************************************************/
/*                      Audio TDM Control and Status                         */
/*****************************************************************************/

__STATIC_INLINE void        Cy_AudioTDM_TX_Enable(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base); 
__STATIC_INLINE void        Cy_AudioTDM_TX_Disable(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base); 
__STATIC_INLINE void        Cy_AudioTDM_RX_Enable(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base); 
__STATIC_INLINE void        Cy_AudioTDM_RX_Disable(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base); 

__STATIC_INLINE void        Cy_AudioTDM_WriteTxData(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base, uint32_t data);
__STATIC_INLINE void        Cy_AudioTDM_ZeroFreezeTxFifo(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_UnfreezeTxFifo(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_MuteTxFifo(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_StartTx(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_StopTx(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_ReplayTxFifo(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base);
__STATIC_INLINE uint8_t     Cy_AudioTDM_GetNumInTxFifo(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base);
__STATIC_INLINE uint8_t     Cy_AudioTDM_GetTxReadPointer(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base); 
__STATIC_INLINE uint8_t     Cy_AudioTDM_GetTxWritePointer(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base); 
__STATIC_INLINE void        Cy_AudioTDM_EnableTxTestMode(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base); 
__STATIC_INLINE void        Cy_AudioTDM_DisableTxTestMode(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base); 

__STATIC_INLINE uint32_t    Cy_AudioTDM_ReadRxData(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_FreezeRxFifo(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_UnfreezeRxFifo(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_StartRx(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_StopRx(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE uint32_t    Cy_AudioTDM_ReadSilentRXFifo(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE uint8_t     Cy_AudioTDM_GetNumInRxFifo(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE uint8_t     Cy_AudioTDM_GetRxReadPointer(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE uint8_t     Cy_AudioTDM_GetRxWritePointer(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_EnableRxTestMode(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_DisableRxTestMode(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);


__STATIC_INLINE void        Cy_AudioTDM_ClearTxInterrupt(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE void        Cy_AudioTDM_SetTxInterrupt(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE uint32_t    Cy_AudioTDM_GetTxInterrupt(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base);
__STATIC_INLINE uint32_t    Cy_AudioTDM_GetTxInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_SetTxInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE uint32_t    Cy_AudioTDM_GetTxInterruptStatusMasked(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_SetTxTriggerInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_ClearTxTriggerInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base);

__STATIC_INLINE void        Cy_AudioTDM_ClearRxInterrupt(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE void        Cy_AudioTDM_SetRxInterrupt(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE uint32_t    Cy_AudioTDM_GetRxInterrupt(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE uint32_t    Cy_AudioTDM_GetRxInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_SetRxInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base, uint32_t interrupt);
__STATIC_INLINE uint32_t    Cy_AudioTDM_GetRxInterruptStatusMasked(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_SetRxTriggerInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);
__STATIC_INLINE void        Cy_AudioTDM_ClearRxTriggerInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base);



/*************************************************************************
* Function Name: Cy_AudioTDM_TX_Enable                               
**************************************************************************
*
* Transmitter (TX) Enable.
*
*  Cy_AudioTDM_Init() or Cy_AudioTDM_Init() must be called before.
*
* \param base The pointer to the TDM-> TX instance address.
*
************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_TX_Enable(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
    base->unTX_CTL.stcField.u1ENABLED = 1u;
}

/***********************************************************************
* Function Name: Cy_AudioTDM_TX_Disable                                 
************************************************************************
* 
* Transmitter(TX) disable.
* 
* \param base The pointer to the TDM->TX instance address.
************************************************************************/

__STATIC_INLINE void Cy_AudioTDM_TX_Disable(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
    base->unTX_CTL.stcField.u1ENABLED = 0u;
}

/************************************************************************
* Function Name: Cy_AudioTDM_RX_Enable                                
*************************************************************************
*
* Receiver(RX) Enable
*
* \parame base The pointer to the  TDM ->RX instance address.
*
************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_RX_Enable(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    base->unRX_CTL.stcField.u1ENABLED = 1u;
}

/*************************************************************************
*Function Name: Cy_AudioTDM_RX_Disable                                   
**************************************************************************
*
* Receiver (RX) Disable
*
* \parame base The point to the TDM->RX instance address.
*
*************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_RX_Disable(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    base->unRX_CTL.stcField.u1ENABLED = 0u;
}

/***************************************************************************
* Function Name: Cy_AudioTDM_WriteTxData                                   
***************************************************************************
*
* Write data to TX FIFO. Increases the TX FIFO level.
*
* \param base The pointer to the TDM->TX instance address.
*
* \param dara Data to be written to the FIFO.
*
****************************************************************************/

__STATIC_INLINE void Cy_AudioTDM_WriteTxData(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base, uint32_t data)
{
    base->unTX_FIFO_WR.stcField.u32DATA = data;
}

/**************************************************************************
* Function Name: Cy_AudioTDM_ZeroFreezeTxFifo                              
***************************************************************************
*
* This functionality is intended for debugging purposes. 
*
* Freezes the TX FIFO.
*
* \param base The pointer to the TDM -> TX instance address.
*
* Function: output data "0".
*
***************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_ZeroFreezeTxFifo(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1REPLAY = 0u;
    base->unTX_FIFO_CTL.stcField.u1FREEZE = 1u;
}

/**************************************************************************
* Function Name: Cy_AudioTDM_UnfreezeTxFifo                                
***************************************************************************
*
* This functionality is intended for debugging purposes. 
*
* Unfreezes the TX FIFO.
*
* \param base The pointer to the TDM -> TX instance address.
*
***************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_UnfreezeTxFifo(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1FREEZE = 0u;
}
 
/*************************************************************************
 Function Name: Cy_AudioTDM_MuteTxFifo                                    
**************************************************************************
*
* Mute the TX FIFO.
*
* HW uses PCM data value of "0".
*
* \param base The pointer to the TDM ->TX instance address.
*
**************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_MuteTxFifo(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
    base->unTX_FIFO_CTL.stcField.u1MUTE = 1u;
}

/*************************************************************************
* Function Name: Cy_AudioTDM_StartTx                                      
**************************************************************************
*
* Transmitter (TX) ON
*
* Start TDM transmission. 
*
* \param base The pointer to the TDM->TX instance address.
*
* \pre Cy_AudioTDM_Init() or Cy_AudioTDM_Init() must be called before.
*
*************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_StartTx(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
     base->unTX_FIFO_CTL.stcField.u1ACTIVE = 1u;
}

/*************************************************************************
* Function Name: Cy_AudioTDM_StopTx                                       
**************************************************************************
*
* Stops TDM transmission.
*
* \param base The pointer to the TDM->TX instance address.
*
**************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_StopTx(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
     base->unTX_FIFO_CTL.stcField.u1ACTIVE = 0u;
}

/*************************************************************************
* Function Name: Cy_AudioTDM_ReplayFreezeTxFifo                           
**************************************************************************
*
* Replay functionality.
*
* HW uses the previous PCM data value.(when FREEZE = 1)
*
* \param base The pointer to the TDM->TX instance address.
*
**************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_ReplayTxFifo(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
     base->unTX_FIFO_CTL.stcField.u1REPLAY = 1u;
     base->unTX_FIFO_CTL.stcField.u1FREEZE = 1u;
}
/**************************************************************************
* Function Name: Cy_AudioTDM_GetNumInTxFifo                                
***************************************************************************
*
* Get the number of used/occupied entries in the TX FIFO.
*
* \param base The pointer to the TDM -> TX instance addredd.
*
* return the value (the number of used/occupied)
*
***************************************************************************/
__STATIC_INLINE uint8_t Cy_AudioTDM_GetNumInTxFifo(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
    return (base->unTX_FIFO_STATUS.stcField.u8USED);
}

/*************************************************************************
*Function Name: Cy_AudioTDM_GetTxReadPointer                              
**************************************************************************
*
* Get the TX FIFO location from which a data is read.
*
* \param base The pointer to the TDM-_TX instance address.
*
* return the location which a data is read.
*
**************************************************************************/
__STATIC_INLINE uint8_t Cy_AudioTDM_GetTxReadPointer(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base) 
{
    return (uint8_t)(base->unTX_FIFO_STATUS.stcField.u7RD_PTR);
}

/**************************************************************************
* Function Name: Cy_AudioTDM_GetTxWritePointer                             
***************************************************************************
*
* Get the TX FIFO location at which new data is written.
*
* \param base The pointer to the TDM->TX instance address.
*
* Return the location (which data is written).
*
****************************************************************************/
__STATIC_INLINE uint8_t Cy_AudioTDM_GetTxWritePointer(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base) 
{
    return (uint8_t)(base->unTX_FIFO_STATUS.stcField.u7WR_PTR);
}
/**************************************************************************
* Function Name: Cy_AudioTDM_EnableTxTestMode                            
***************************************************************************
* Enable Test Mode: Intend to be used with slave tx and master rx configuration.
*
* \param base The pointer to the TDM->TX instance address.
*
* \pre "TX_TEST_CTL.ENABLED" should not be set to '1' simultaneously.
*
* \pre This is  used for deubugging purpose and worked as TX - RX loopback.
*
******************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_EnableTxTestMode(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base) 
{
    base->unTX_TEST_CTL.stcField.u1ENABLED = 1u;
}

/**************************************************************************
* Function Name: Cy_AudioTDM_DisableTxTestMode                            
***************************************************************************
*  Test Mode disable will be used for TX to put it in normal functional mode.
*
* \param base The pointer to the TDM-> TX instance and address.
*
***************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_DisableTxTestMode(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base) 
{
    base->unTX_TEST_CTL.stcField.u1ENABLED = 0u;
}

/**************************************************************************
* Function Name: Cy_AudioTDM_ReadRxData                                   *
***************************************************************************
*
* Reads data from RX FIFO. Decreases the RX FIFO level.
*
* \Note reading removes the data from FIFO and read ptr is incremented.
*
* \param base The pointer to the TDM->RX instance addredd.



***************************************************************************/
__STATIC_INLINE uint32_t Cy_AudioTDM_ReadRxData(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    return (base->unRX_FIFO_RD.stcField.u32DATA);
}

/***************************************************************************
*    Function Name: Cy_AudioTDM_FreezeRxFifo                                
****************************************************************************
*
* This functionality is intend for debugging purposes.
*
* Freeze the RX FIFO.
*
* \param base The pointer to the TDM-RX instance address.
*
* \Note Freeze does not advance the FIFO write pointer.
****************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_FreezeRxFifo(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    base->unRX_FIFO_CTL.stcField.u1FREEZE = 1u;
}
/**************************************************************************
*  Function Name: Cy_AudioTDM_UnfreezeRxFifo                               
***************************************************************************
*
* Unfreeze the RX FIFO. This function is rather for debg purposes.
*
* \param base The pointer to the TDM-> RX instance address.
*
****************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_UnfreezeRxFifo(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    base->unRX_FIFO_CTL.stcField.u1FREEZE = 0u;
}

/**************************************************************************
* Function Name: Cy_AudioTDM_StartRx                                      *
***************************************************************************
*
* Start TDM reception.
*
* \param base The pointer to the TDM->RX instance address.
*
***************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_StartRx(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    base->unRX_FIFO_CTL.stcField.u1ACTIVE = 1u;
}

/**************************************************************************
* Function Name: Cy_AudioTDM_StopRx                                       
***************************************************************************
*
* Stop TDM reception.
*
* \param base The pointer to the TDM ->RX instance address.
*
***************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_StopRx(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    base->unRX_FIFO_CTL.stcField.u1ACTIVE = 0u;
}

/**************************************************************************
* Function Name: Cy_AudioTDM_ReadSilentRXFifo                              
***************************************************************************
*
* Read data from the RX FIFO.
*
* This will not remove the data from the RX FIFO.
*
* \param base The pointer to the TDM-> RX instance address.
*
***************************************************************************/
__STATIC_INLINE uint32_t Cy_AudioTDM_ReadSilentRXFifo(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    return (base->unRX_FIFO_RD_SILENT.stcField.u32DATA);
}
/**************************************************************************
* Function Name: Cy_AudioTDM_GetNumInRxFifo                               *
***************************************************************************
*
* Get the number of used/occupied entries in the RX FIFO.
*
* \param base The pointer to the TDM->RX instance address.
*
* \Note The field value is in the range [0, 128].
*
* \Note When "128", the FIFO is full.
*
***************************************************************************/
__STATIC_INLINE uint8_t Cy_AudioTDM_GetNumInRxFifo(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    return (base->unRX_FIFO_STATUS.stcField.u8USED);
}

/*************************************************************************
* Function Name: Cy_AudioTDM_GetRxReadPointer                            *
**************************************************************************
*
* \Note This functionality is intended for debugging purposes.
*
* Get the RX FIFO location from which a data is read.
*
* \param base The pointer to the TDM->RX instance address.
*
**************************************************************************/
__STATIC_INLINE uint8_t Cy_AudioTDM_GetRxReadPointer(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    return (base->unRX_FIFO_STATUS.stcField.u7RD_PTR);
} 

/**************************************************************************
* Function Name: Cy_AudioTDM_GetRxWritePointer                            *
***************************************************************************
*
* This functionality is intended or debugging purposes.
*
* Get the RX FIFO location from which  a new data is written by the hardware.
*[
* \param base The pointer to to the TDM->RX instance address.
*
***************************************************************************/
__STATIC_INLINE uint8_t Cy_AudioTDM_GetRxWritePointer(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    return (base->unRX_FIFO_STATUS.stcField.u7WR_PTR);
} 

/**************************************************************************
* Function Name: Cy_AudioTDM_EnableRxTestMode                             *
***************************************************************************
*
* Test Mode enable intended to be used with master tx and slave configuraton.
*
* \param base The pointer to the TDM->RX instance address.
*
* This functionality is intended or debugging purposes.  
*          
**************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_EnableRxTestMode(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    base->unRX_TEST_CTL.stcField.u1ENABLED = 1u;
}

/**************************************************************************
* Function Name: Cy_AudioTDM_DisableRxTestMode                            *
***************************************************************************
*
* Test Mode disable intend to be used for RX to put it in normal.
*
* \param base The pointer to the TDM -> RX instance address.
*
* This functionality is intended or debugging purposes. 
*
***************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_DisableRxTestMode(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    base->unRX_TEST_CTL.stcField.u1ENABLED = 0u;
}

/*************************************************************************
* Function Name: Cy_AudioTDM_ClearTxInterrupt                             
**************************************************************************
*
* Clears one or more interrupt factors from the RX interrupt resister.
*
* \param base The pointer to the TDM->TX instance address.
*
* \param interrupt  Interrupt bit mask.
*
**************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_ClearTxInterrupt(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base, uint32_t interrupt)
{
    base->unINTR_TX.u32Register = interrupt;
    (void) base->unINTR_TX.u32Register;
}

/**************************************************************************
* Function Name: Cy_AudioTDM_SetTxInterrupt                                
***************************************************************************
*
* Sets one or more interrupt factors in the TX interrupt register.
*
* \param base The pointer to the TDM->TX instance address.
*
* \param interrupt Interrupt bit mask.
*
**************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_SetTxInterrupt(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base, uint32_t interrupt)
{
    base->unINTR_TX_SET.u32Register = interrupt;
}    

/*******************************************************************************
* Function Name: Cy_AudioTDM_GetTxInterrupt
****************************************************************************//**
*
* Get Tx interrupt status
*
* \param base The pointer to the TDM->TX instance address.
*
* \return The interrupt status.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_AudioTDM_GetTxInterrupt(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
    return (base->unINTR_TX.u32Register);
}

/************************************************************************
* Function Name: Cy_AudioTDM_GetTxInterruptMask                          
*************************************************************************
*
* Return the interrupt mask in the TX interrupt register
*
* \param base The pointer to the TDM->TX instance address.
*
* \return The interrupt bit mask
*
*************************************************************************/
__STATIC_INLINE uint32_t Cy_AudioTDM_GetTxInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
    return(base->unINTR_TX_MASK.u32Register);
}

/**************************************************************************
* Function Name: Cy_AudioTDM_SetTxInterruptMask                            
***************************************************************************
*
* Sets one or more interrupt factor masks in the interrupt mask in the TX interrupt register.
*
* \param base The pointer to the TDM->TX instance address.
*
***************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_SetTxInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base, uint32_t interrupt)
{
    base->unINTR_TX_MASK.u32Register = interrupt;
}

/*************************************************************************
* Function Name: Cy_AudioTDM_GetTxInterruptStatusMasked                   
**************************************************************************
*
* Return the interrupt status masked (a content of the TX_INTR_MASKED register).
*
* \param base The pointer to the TDM->TX instance address.
*
* \return The interrupt bit mask(s).
*
**************************************************************************/
__STATIC_INLINE uint32_t Cy_AudioTDM_GetTxInterruptStatusMasked(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
    return (base->unINTR_TX_MASKED.u32Register);
}

/**************************************************************************
* Function Name: Cy_AudioTDM_SetTxTriggerInterruptMask                     
***************************************************************************
*
* Sets TX Trigger Interrupt Mask.
*
* \param base The pointer to the TDM->TX instance address.
*
***************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_SetTxTriggerInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
    base->unINTR_TX_MASK.stcField.u1FIFO_TRIGGER = 1u;
}

/*************************************************************************
* Function Name: Cy_AudioTDM_ClearTxTriggerInterruptMask                  
**************************************************************************
* 
* Clears TX Trigger Interrupt mask.
*
* \param The pointer to the TDM->TX instance address.
*
**************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_ClearTxTriggerInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t * base)
{
    base->unINTR_TX_MASK.stcField.u1FIFO_TRIGGER = 0u;
}    
/**************************************************************************
 Function Name: Cy_AudioTDM_ClearRxInterrupt                             
***************************************************************************
*
* Clears one or more interrupt factors from the RX interrupt register.
*
* \param base The pointer to the TDM->RX instance address.
*
* \param interrupt Interrut bit masi
**************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_ClearRxInterrupt(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base, uint32_t interrupt)
{
    base->unINTR_RX.u32Register = interrupt;
    (void) base->unINTR_RX.u32Register;
}
    
/***************************************************************************
 Function Name: Cy_AudioTDM_SetRxInterrupt                               
****************************************************************************
*
* Sets one or more interrupt factors in the RX interrupt register.
*
* \param base The pointer to the TDM ->RX instance adress,
*
* \param interrupt Interrupot bit mask.
*
**********************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_SetRxInterrupt(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base, uint32_t interrupt)
{
    base->unINTR_RX.u32Register = interrupt;
}

/*******************************************************************************
* Function Name: Cy_AudioTDM_GetRxInterrupt
****************************************************************************//**
*
* Get Rx interrupt status
*
* \param base The pointer to the TDM->RX instance address.
*
* \return The interrupt status.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_AudioTDM_GetRxInterrupt(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    return (base->unINTR_RX.u32Register);
}

/***************************************************************************
 Function Name: Cy_AudioTDM_GetRxInterruptMask                           
***************************************************************************
*
* Returns the interrupt mask in the RX interrupt register.
*
* \param base The pointer to the TDM ->RX instance adress,
*
* \return Interrupt bit mask.
*
*********************************************************************************/
__STATIC_INLINE uint32_t Cy_AudioTDM_GetRxInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    return (base->unINTR_RX_MASK.u32Register);
}
/*************************************************************************
* Function Name: Cy_AudioTDM_SetRxInterruptMask                           
**************************************************************************
*
* Sets one or more interrupt factor masks in the interrupt mask in the RX interrupt register.
*
* \param base The pointer to the TDM->RX instance address.
*
* \return The interrupt bit mask.
*
******************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_SetRxInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base, uint32_t interrupt)
{
    base->unINTR_RX_MASK.u32Register = interrupt;
}
    
/**************************************************************************
 Function Name: Cy_AudioTDM_GetRxInterruptStatusMasked                  
***************************************************************************
*
* Returns the interrupt mask in the RX interrupt register.
*
* \param base The pointer to the TDM->RX instance address.
*
* \return The interrupt bit mask.
*
*****************************************************************************/
__STATIC_INLINE uint32_t Cy_AudioTDM_GetRxInterruptStatusMasked(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    return (base->unINTR_RX_MASKED.u32Register);
}
/************************************************************************
 Function Name: Cy_AudioTDM_SetRxTriggerInterruptMask                   
*************************************************************************
*
* Sets RX Trigger Interrupt mask.
*
* \param base The pointer to the TDM->RX instance address.
*
**********************************************************************/
__STATIC_INLINE void Cy_AudioTDM_SetRxTriggerInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    base->unINTR_RX_MASK.stcField.u1FIFO_TRIGGER = 1u;
}

/***************************************************************************
* Function Name: Cy_AudioTDM_ClearRxTriggerInterruptMask                  *
***************************************************************************
*
* Clears RX trigger Interrupt mask
*
* \param base The poiner to the TDm ->RX instance address.
*
************************************************************************************/
__STATIC_INLINE void Cy_AudioTDM_ClearRxTriggerInterruptMask(volatile stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t * base)
{
    base->unINTR_RX_MASK.stcField.u1FIFO_TRIGGER = 0u;
}


/** \} group_tdm_functions */

#ifdef __cplusplus
}
#endif

#endif /* CY_IP_MXAUDIOSS */

#endif /* CY_TDM_H */

/** \} group_tdm */

/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
