/***************************************************************************//**
* \file tcpwm_counter.h
* \version 1.0
*
* \brief
* The header file of the TCPWM Timer Counter driver.
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_COUNTER_H)
#define CY_TCPWM_COUNTER_H

#include "cy_tcpwm.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_tcpwm
* \{
*/

/**
* \addtogroup group_tcpwm_data_structures
* \{
*/

/** Counter Timer configuration structure */
typedef struct cy_stc_tcpwm_counter_config
{
    uint32_t period;             /**< Sets the period of the counter */
    uint32_t clockPrescaler;     /**< Sets the clock prescaler inside the TCWPM block see \ref group_tcpwm_counter_clk_prescalers */
    uint32_t runMode;            /**< Sets the Counter Timer Run mode see \ref group_tcpwm_counter_run_modes */
    uint32_t countDirection;     /**< Sets the counter direction see \ref group_tcpwm_counter_direction */
    bool     debug_pause;        /**< If enabled, the counter pauses in debug mode else it kept on running   >*/
    uint8_t  CompareOrCapture;   /**< The counter can either compare or capture a value see \ref group_tcpwm_counter_compare_capture */
    uint32_t compare0;           /**< Sets the value for Compare0 */
    uint32_t compare0_buff;      /**< Sets the value for Compare0_buff */
    bool     enableCompare0Swap; /**< If enabled, the compare values are swapped each time the comparison is true */
    uint32_t interruptSources;   /**< Enabled an interrupt on the terminal count, capture or compare, see \ref group_tcpwm_interrupt_sources */
    uint32_t capture0InputMode;  /**< Configures how the capture input behaves see \ref group_tcpwm_input_modes */
    uint32_t capture0Input;      /**< Selects which input the capture uses, should be b/w 0x00 to 0xff */
    uint32_t compare1;           /**< Sets the value for Compare1 (Compare 1 will be active only for Group1 counters) */
    uint32_t compare1_buff;      /**< Sets the value for Compare1_buff (Compare 1 will be active only for Group1 counters) */
    bool     enableCompare1Swap; /**< If enabled, the compare1 values are swapped each time the comparison is true */
    uint32_t capture1InputMode;  /**< Configures how the capture input behaves see \ref group_tcpwm_input_modes */
    uint32_t capture1Input;      /**< Selects which input the capture uses, should be b/w 0x00 to 0xff */
    uint32_t reloadInputMode;    /**< Configures how the reload input behaves see \ref group_tcpwm_input_modes */
    uint32_t reloadInput;        /**< Selects which input the reload uses, should be b/w 0x00 to 0xff */
    uint32_t startInputMode;     /**< Configures how the start input behaves see \ref group_tcpwm_input_modes */
    uint32_t startInput;         /**< Selects which input the start uses, should be b/w 0x00 to 0xff */
    uint32_t stopInputMode;      /**< Configures how the stop input behaves see \ref group_tcpwm_input_modes */
    uint32_t stopInput;          /**< Selects which input the stop uses, should be b/w 0x00 to 0xff */
    uint32_t countInputMode;     /**< Configures how the count input behaves see \ref group_tcpwm_input_modes */
    uint32_t countInput;         /**< Selects which input the count uses, should be b/w 0x00 to 0xff */
    uint32_t trigger1;           /**<selection of the events for the output trigger0 generations, see group_tcpwm_counter_clk_output_trigger*/
    uint32_t trigger2;           /**<selection of the events for the output trigger0 generations, see group_tcpwm_counter_clk_output_trigger */
}cy_stc_tcpwm_counter_config_t;
/** \} group_tcpwm_data_structures */


/**
* \addtogroup group_tcpwm_macro
* \{
* \defgroup group_tcpwm_counter_run_modes Counter Run Modes
* \{
* Run modes for the counter timer.
*/
#define CY_TCPWM_COUNTER_ONESHOT    (1u) /**< Counter runs once and then stops */
#define CY_TCPWM_COUNTER_CONTINUOUS (0u) /**< Counter runs forever */
/** \} group_tcpwm_counter_run_modes */

/** \defgroup group_tcpwm_counter_direction Counter Direction
* The counter directions.
* \{
*/
#define CY_TCPWM_COUNTER_COUNT_UP       (0u) /**< Counter counts up */
#define CY_TCPWM_COUNTER_COUNT_DOWN     (1u) /**< Counter counts down */
#define CY_TCPWM_COUNTER_COUNT_UP_DOWN0 (2u) /**< Counter counts up and down terminal count only occurs on underflow */
#define CY_TCPWM_COUNTER_COUNT_UP_DOWN1 (3u) /**< Counter counts up and down terminal count occurs on both overflow and underflow */
/** \} group_tcpwm_counter_direction */

/** \defgroup group_tcpwm_counter_clk_prescalers Counter CLK Prescalers
* \{
* The clock prescaler values.
*/
#define CY_TCPWM_COUNTER_PRESCALER_DIVBY_1   (0u) /**< Divide by 1 */
#define CY_TCPWM_COUNTER_PRESCALER_DIVBY_2   (1u) /**< Divide by 2 */
#define CY_TCPWM_COUNTER_PRESCALER_DIVBY_4   (2u) /**< Divide by 4 */
#define CY_TCPWM_COUNTER_PRESCALER_DIVBY_8   (3u) /**< Divide by 8 */
#define CY_TCPWM_COUNTER_PRESCALER_DIVBY_16  (4u) /**< Divide by 16 */
#define CY_TCPWM_COUNTER_PRESCALER_DIVBY_32  (5u) /**< Divide by 32 */
#define CY_TCPWM_COUNTER_PRESCALER_DIVBY_64  (6u) /**< Divide by 64 */
#define CY_TCPWM_COUNTER_PRESCALER_DIVBY_128 (7u) /**< Divide by 128 */
/** \} group_tcpwm_counter_clk_prescalers */

/** \defgroup group_tcpwm_counter_compare_capture Counter Compare Capture
* \{
* A compare or capture mode.
*/
#define CY_TCPWM_COUNTER_MODE_CAPTURE (2u) /**< Timer/Counter is in Capture Mode */
#define CY_TCPWM_COUNTER_MODE_COMPARE (0u) /**< Timer/Counter is in Compare Mode */
/** \} group_tcpwm_counter_compare_capture */

/** \defgroup group_tcpwm_counter_output_trigger Counter CLK Prescalers
* \{
* The trig_output selection.
*/
#define CY_TCPWM_COUNTER_OVERFLOW       (0u) /**< An overflow event. */
#define CY_TCPWM_COUNTER_UNDERFLOW      (1u) /**< An underflow event. */
#define CY_TCPWM_COUNTER_TERMINAL_COUNT (2u) /**< A terminal count event. */
#define CY_TCPWM_COUNTER_CC0_MATCH      (3u) /**< A cc0_match event. */
#define CY_TCPWM_COUNTER_CC1_MATCH      (4u) /**< A cc1_match event. */
/** \} group_tcpwm_counter_clk_output_trigger */

/** \defgroup group_tcpwm_counter_status Counter Status
* \{
* The counter status.
*/
#define CY_TCPWM_COUNTER_STATUS_DOWN_COUNTING (0x1uL) /**< Timer/Counter is down counting */
#define CY_TCPWM_COUNTER_STATUS_UP_COUNTING   (0x2uL) /**< Timer/Counter is up counting */
/**< Timer/Counter the counter is running */
#define CY_TCPWM_COUNTER_STATUS_COUNTER_RUNNING (TCPWM_CNT_STATUS_RUNNING_Msk)
/** \} group_tcpwm_counter_status */
/** \} group_tcpwm_macro */


/*******************************************************************************
*        Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_tcpwm_functions
* \{
*/

extern uint32_t Cy_Tcpwm_Counter_Init(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM, cy_stc_tcpwm_counter_config_t const *config);
extern void Cy_Tcpwm_Counter_DeInit(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_Enable(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_Disable(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern uint32_t Cy_Tcpwm_Counter_GetStatus(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern uint32_t Cy_Tcpwm_Counter_GetCapture0(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern uint32_t Cy_Tcpwm_Counter_GetCapture1(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern uint32_t Cy_Tcpwm_Counter_GetCapture0Buf(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern uint32_t Cy_Tcpwm_Counter_GetCapture1Buf(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_SetCompare0(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM,  uint32_t compare0);
extern uint32_t Cy_Tcpwm_Counter_GetCompare0(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_SetCompare0_Buff(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM,  uint32_t compare1);
extern uint32_t Cy_Tcpwm_Counter_GetCompare0_Buff(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_SetCompare1(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM,  uint32_t compare0);
extern uint32_t Cy_Tcpwm_Counter_GetCompare1(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_SetCompare1_Buff(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM,  uint32_t compare1);
extern uint32_t Cy_Tcpwm_Counter_GetCompare1_Buff(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_EnableCompare0Swap(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM,  bool enable);
extern void Cy_Tcpwm_Counter_EnableCompare1Swap(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM,  bool enable);
extern void Cy_Tcpwm_Counter_SetCounter(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM,  uint32_t count);
extern uint32_t Cy_Tcpwm_Counter_GetCounter(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_SetPeriod(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM,  uint32_t period);
extern uint32_t Cy_Tcpwm_Counter_GetPeriod(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_SetPeriod_Buff(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM,  uint32_t period);
extern uint32_t Cy_Tcpwm_Counter_GetPeriod_Buff(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_SetTC_IntrMask(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_SetCC0_IntrMask(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_SetCC1_IntrMask(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern uint8_t Cy_Tcpwm_Counter_GetTC_IntrMasked(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern uint8_t Cy_Tcpwm_Counter_GetCC0_IntrMasked(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern uint8_t Cy_Tcpwm_Counter_GetCC1_IntrMasked(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_ClearTC_Intr(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_ClearCC0_Intr(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);
extern void Cy_Tcpwm_Counter_ClearCC1_Intr(volatile stc_TCPWM_GRP_CNT_t *ptscTCPWM);

/** \} group_tcpwm_functions */

/** \} group_tcpwm */

#if defined(__cplusplus)
}
#endif

#endif /* TCPWM_COUNTER_H */


/* [] END OF FILE */
