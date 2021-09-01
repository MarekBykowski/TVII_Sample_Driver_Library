/***************************************************************************//**
* \file cy_axidma.h
* \version 1.0
*
* \brief
* The header file of the AXI-DMA driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_axidma AXI DMA (AXI-DMA)
* \{
* Configures an AXI-DMA controller, its channel(s) and its descriptor(s).
*
* The AXI-DMA component can be used in any project that needs to transfer data
* without CPU intervention, based on a software trigger or hardware trigger signal
* from another component.
*
* A device may support more than one AXI-DMA hardware block. Each block has a set of 
* registers, and a base hardware address. Each block also supports multiple channels. 
* Many API functions for the AXI-DMA driver require the base hardware address and the 
* channel number. Ensure that you use the correct hardware address for the AXI-DMA block in use.
* 
* Features:
* * Devices support one AXI-DMA hardware block
* * Each AXI-DMA block supports up to 8 AXI-DMA channels
* * Supports channel descriptors in SRAM
* * Four Priority Levels for each channel
* * Different transfer types
* * Configurable source and destination addresses
*
* \section group_axidma_configuration Configuration Considerations
*
* To set up a AXI-DMA driver you initialize a descriptor,
* intialize and enable a channel, and enable the AXI-DMA block.
* 
* To set up the descriptor, provide the configuration parameters for the 
* descriptor in the \ref cy_stc_axidma_descr_config_t structure. Then call the 
* \ref Cy_AXIDMA_Descr_Init function to initialize the descriptor in SRAM. You can 
* modify the source and destination addresses dynamically by calling 
* \ref Cy_AXIDMA_Descr_SetSrcAddr and \ref Cy_AXIDMA_Descr_SetDestAddr.
* 
* To set up the AXI-DMA channel, provide a filled \ref cy_stc_axidma_chnl_config_t 
* structure. Call the \ref Cy_AXIDMA_Chnl_Init function, specifying the channel
* number. Use \ref Cy_AXIDMA_Chnl_Enable to enable the configured AXI-DMA channel.
*
* Call \ref Cy_AXIDMA_Chnl_Enable for each AXI-DMA channel in use.
*
* <B>NOTE:</B> Even if a AXI-DMA channel is enabled, it is not operational until 
* the AXI-DMA block is enabled using function \ref Cy_AXIDMA_Enable.\n
* <B>NOTE:</B> If the AXI-DMA descriptor is configured to generate an interrupt, 
* the interrupt must be enabled using the \ref Cy_AXIDMA_Chnl_SetInterruptMask 
* function for each AXI-DMA channel.
* 
* \section group_axidma_more_information More Information.
*
* See the AXI-DMA Component datasheet.
* See also the AXI-DMA chapter of the device technical reference manual (TRM).
*
*
* \section group_axidma_changelog Changelog
*
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*

* \defgroup group_axidma_macro Macro
* \{
*   \defgroup group_axidma_common_macro_AXIDMAIntrCauses AXI-DMA Interrupt Causes
* \}
*
* \defgroup group_axidma_functions Functions
* \defgroup group_axidma_data_structures Data structures
* \defgroup group_axidma_enums Enumerated types
*/

#if !defined(CY_AXIDMA_H)
#define CY_AXIDMA_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "syslib/cy_syslib.h"
#include "cy_device_headers.h"


#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
 * Macro definitions                                                          *
 ******************************************************************************/

/**
* \addtogroup group_axidma_macro
* \{
*/

/** Driver major version */
#define CY_AXIDMA_DRV_VERSION_MAJOR       1
/** Driver minor version */
#define CY_AXIDMA_DRV_VERSION_MINOR       0
    
#define CY_AXIDMA_ID                      (CY_PDL_DRV_ID(0x13u)) /**< AXI-DMA PDL ID */
#define CY_AXIDMA_ID_ERROR                (uint32_t)( CY_AXIDMA_ID | CY_PDL_STATUS_ERROR)   /**< Return prefix for AXI-DMA driver function error return values */


/**
* \addtogroup group_axidma_common_macro_AXIDMAIntrCauses
* \{
*/
#define CY_AXIDMA_INTRCAUSE_NO_INTR                (0x00u) /**< No interrupt                         */
#define CY_AXIDMA_INTRCAUSE_COMPLETION             (0x01u) /**< Completion                           */
#define CY_AXIDMA_INTRCAUSE_SRC_BUS_ERROR          (0x02u) /**< Source bus error                     */
#define CY_AXIDMA_INTRCAUSE_DST_BUS_ERROR          (0x04u) /**< Destination bus error                */
#define CY_AXIDMA_INTRCAUSE_INVALID_DESCR          (0x08u) /**< Descriptor type is invalid           */
#define CY_AXIDMA_INTRCAUSE_CURR_PTR_NULL          (0x20u) /**< Current descripror pointer is NULL   */
#define CY_AXIDMA_INTRCAUSE_ACTIVE_CH_DISABLED     (0x40u) /**< Active channel is disabled           */
#define CY_AXIDMA_INTRCAUSE_DESCR_BUS_ERROR        (0x80u) /**< Descriptor bus error                 */
/** \} group_axidma_common_macro_AXIDMAIntrCauses */



/** For performance reasons AXI DMAC always fetches 10 words independent of the actual descriptor type.
    This might cause problems if a 1D descriptor is located at the end of a memory or protection region.
    Following macro can be used to safely instantiate a given number of 1D descriptors with enough reserved space at the end.  */
#define CY_AXIDMA_SAFELY_INSTANTIATE_1D_MEMCOPY_DESCRIPTORS(storage_class,base_name,nr_of_desc)                            \
            storage_class struct                                                                                           \
            {                                                                                                              \
                cy_stc_axidma_1d_memcopy_descr_t descriptors[nr_of_desc];                                                  \
                uint32_t                         u32UnusedButAccessed[4];                                                  \
            } base_name ## _struct;                                                                                        \
            storage_class cy_stc_axidma_1d_memcopy_descr_t * base_name = &base_name ## _struct.descriptors[0];

/** For performance reasons AXI DMAC always fetches 10 words independent of the actual descriptor type.
    This might cause problems if a 2D descriptor is located at the end of a memory or protection region.
    Following macro can be used to safely instantiate a given number of 2D descriptors with enough reserved space at the end.  */
#define CY_AXIDMA_SAFELY_INSTANTIATE_2D_MEMCOPY_DESCRIPTORS(storage_class,base_name,nr_of_desc)                            \
            storage_class struct                                                                                           \
            {                                                                                                              \
                cy_stc_axidma_2d_memcopy_descr_t descriptors[nr_of_desc];                                                  \
                uint32_t                         u32UnusedButAccessed[2];                                                  \
            } base_name ## _struct;                                                                                        \
            storage_class cy_stc_axidma_2d_memcopy_descr_t * base_name = &base_name ## _struct.descriptors[0];

/** Returns the address of a descriptor that has been generated by above CY_AXIDMA_SAFELY_INSTANTIATE_xD_MEMCOPY_DESCRIPTORS macros.
    These macros hide the instantantion and just create a pointer to the first descriptor, but the value of the pointer cannot be used
    during link/compile-time to initialize e.g. #AXIDMA_Descriptor member of #cy_stc_axidma_chnl_config_t struct.
    Therefore, the following macro can be used and it expects the same base_name that has been used during instantion of the 
    descriptors by using CY_AXIDMA_SAFELY_INSTANTIATE_xD_MEMCOPY_DESCRIPTORS macros
     */
#define CY_AXIDMA_GET_BUILD_TIME_BASE_ADDRESS_OF_DESCRIPTOR(base_name,desc_index)          (&base_name ## _struct.descriptors[desc_index])

/** \} group_axidma_macro */


/**
* \addtogroup group_axidma_enums
* \{
*/

/** Contains the options for the descriptor type */
typedef enum  {
    CY_AXIDMA_1D_MEMCOPY_TRANSFER = 0,        /**< 1D Memory copy transfer */
    CY_AXIDMA_2D_MEMCOPY_TRANSFER,            /**< 2D Memory copy transfer */
    CY_AXIDMA_3D_MEMCOPY_TRANSFER,            /**< 3D Memory copy transfer */
} cy_en_axidma_descrtype_t;

/** Contains the options for the interrupt-type parameter of the descriptor */
typedef enum  {
    CY_AXIDMA_INTR_M_LOOP_CMPLT = 0,          /**< Triggers on every memory copy loop completion          */
    CY_AXIDMA_INTR_X_LOOP_CMPLT,              /**< Triggers on every X loop transfer completion           */
    CY_AXIDMA_INTR_DESCR_CMPLT,               /**< Triggers on descriptor completion                      */
    CY_AXIDMA_INTR_DESCRCHAIN_CMPLT           /**< Triggers on completion of the entire descriptor chain  */
} cy_en_axidma_inttype_t;

/** This enum has the options for the trigger-out-type parameter of the descriptor */
typedef enum  {
    CY_AXIDMA_TRIGOUT_M_LOOP_CMPLT = 0,       /**< Triggers on every memory copy loop completion          */
    CY_AXIDMA_TRIGOUT_X_LOOP_CMPLT,           /**< Triggers on every X loop transfer completion           */
    CY_AXIDMA_TRIGOUT_DESCR_CMPLT,            /**< Triggers on descriptor completion                      */
    CY_AXIDMA_TRIGOUT_DESCRCHAIN_CMPLT        /**< Triggers on completion of the entire descriptor chain  */
} cy_en_axidma_trigouttype_t;

/** This enum has the options for the trigger-in-type parameter of the descriptor */
typedef enum cy_en_axidma_trigintype_t {
    CY_AXIDMA_TRIGIN_M_LOOP = 0,              /**< One M loop transfer per trigger            */
    CY_AXIDMA_TRIGIN_X_LOOP,                  /**< One X loop transfer per trigger            */
    CY_AXIDMA_TRIGIN_DESCR,                   /**< The entire descriptor transfer per trigger */
    CY_AXIDMA_TRIGIN_DESCRCHAIN               /**< The entire descriptor chain per trigger    */
} cy_en_axidma_trigintype_t;

/** This enum has the options for trigger deactivation */
typedef enum  {
    CY_AXIDMA_TRIG_DEACT_NO_WAIT = 0,         /**< Don't wait (pulse-sensitive triggers!)  */
    CY_AXIDMA_TRIG_DEACT_4CYC,                /**< Wait for up to  4 CLK_SLOW cycles  */
    CY_AXIDMA_TRIG_DEACT_16CYC,               /**< Wait for up to 16 CLK_SLOW cycles  */
    CY_AXIDMA_TRIG_DEACT_WAIT_INDEFINITELY    /**< Wait indefinitely  */
} cy_en_axidma_trig_deact_t;

/** This enum has the return values of the AXI-DMA driver */
typedef enum 
{
    CY_AXIDMA_SUCCESS                  = 0x00ul,                       /**< Success */
    CY_AXIDMA_INVALID_INPUT_PARAMETERS = ( CY_AXIDMA_ID_ERROR + 1ul),  /**< Input parameters passed to AXI-DMA API are not valid */
    CY_AXIDMA_ERR_UNC                  = ( CY_AXIDMA_ID_ERROR + 0xFul),/**< Unknown error */
} cy_en_axidma_status_t;

/** \} group_axidma_enums */



/**
* \addtogroup group_axidma_data_structures
* \{
*/

/** 1D Descriptor in memory that will be accessed by the DMA engine, must be 64-bit aligned --> compiler attribute is used */
typedef struct {
  un_AXI_DMAC_CH_DESCR_CTL_t       unAXIDMA_DESCR_CTL   __ALIGNED(8);
  uint32_t                         u32AXIDMA_DESCR_SRC;
  uint32_t                         u32AXIDMA_DESCR_DST;
  un_AXI_DMAC_CH_DESCR_M_SIZE_t    unAXIDMA_DESCR_M_SIZE;
  uint32_t                         u32AXIDMA_DESCR_NEXT_PTR;
  uint32_t                         u32UnusedButAccessed;
} cy_stc_axidma_1d_memcopy_descr_t;

/** 2D Descriptor in memory that will be accessed by the DMA engine, must be 64-bit aligned --> compiler attribute is used */
typedef struct {
  un_AXI_DMAC_CH_DESCR_CTL_t       unAXIDMA_DESCR_CTL   __ALIGNED(8);
  uint32_t                         u32AXIDMA_DESCR_SRC;
  uint32_t                         u32AXIDMA_DESCR_DST;
  un_AXI_DMAC_CH_DESCR_M_SIZE_t    unAXIDMA_DESCR_M_SIZE;
  un_AXI_DMAC_CH_DESCR_X_SIZE_t    unAXIDMA_DESCR_X_SIZE;
  un_AXI_DMAC_CH_DESCR_X_INCR_t    unAXIDMA_DESCR_X_INCR;
  uint32_t                         u32AXIDMA_DESCR_NEXT_PTR;
  uint32_t                         u32UnusedButAccessed;
} cy_stc_axidma_2d_memcopy_descr_t;

/** 3D Descriptor in memory that will be accessed by the DMA engine, must be 64-bit aligned --> compiler attribute is used */
typedef struct {
  un_AXI_DMAC_CH_DESCR_CTL_t       unAXIDMA_DESCR_CTL   __ALIGNED(8);
  uint32_t                         u32AXIDMA_DESCR_SRC;
  uint32_t                         u32AXIDMA_DESCR_DST;
  un_AXI_DMAC_CH_DESCR_M_SIZE_t    unAXIDMA_DESCR_M_SIZE;
  un_AXI_DMAC_CH_DESCR_X_SIZE_t    unAXIDMA_DESCR_X_SIZE;
  un_AXI_DMAC_CH_DESCR_X_INCR_t    unAXIDMA_DESCR_X_INCR;
  un_AXI_DMAC_CH_DESCR_Y_SIZE_t    unAXIDMA_DESCR_Y_SIZE;
  un_AXI_DMAC_CH_DESCR_Y_INCR_t    unAXIDMA_DESCR_Y_INCR;
  uint32_t                         u32AXIDMA_DESCR_NEXT_PTR;
  uint32_t                         u32UnusedButAccessed;
} cy_stc_axidma_3d_memcopy_descr_t;


/**
* This structure is a configuration structure pre-initialized by the user and
* passed as a parameter to the Cy_AXIDMA_InitDescr(). This structure has all the parameters
* of the descriptor as separate parameters. Some of these parameters are represented in the
* stc_Descr_t data structure as bit fields.
*/
typedef struct {
    cy_en_axidma_trig_deact_t  deact;              /**< Specifies whether the AXI-DMA controller should wait for the input trigger to be deactivated */
    cy_en_axidma_inttype_t     intrType;           /**< Sets the event that triggers an interrupt, see \ref cy_en_axidma_inttype_t     */
    cy_en_axidma_trigouttype_t trigoutType;        /**< Sets the event that triggers an output,    see \ref cy_en_axidma_trigouttype_t */
    cy_en_axidma_trigintype_t  triginType;         /**< Sets what type of transfer is triggered,   see \ref cy_en_axidma_trigintype_t  */
    bool                       disableChAtCmplt;   /**< Specifies if the channel is enabled or disabled on completion of descriptor see \ref cy_en_axidma_chdesccmpl_t */
    bool                       dataPrefetch;       /**< Enabling/disabling of source data prefetch */
    cy_en_axidma_descrtype_t   descrType;          /**< The type of the descriptor                 see \ref cy_en_axidma_descrtype_t*/
    void*                      srcAddr;            /**< The source address of the transfer      */
    void*                      dstAddr;            /**< The destination address of the transfer */
    uint32_t                   mCount;             /**< The number of bytes transfers in an M-loop                          */
    int16_t                    srcXincr;           /**< The address increment of the source after each X-loop transfer      */
    int16_t                    dstXincr;           /**< The address increment of the destination after each X-loop transfer */
    uint32_t                   xCount;             /**< The number of transfers in an X-loop                                */
    int16_t                    srcYincr;           /**< The address increment of the source after each Y-loop transfer      */
    int16_t                    dstYincr;           /**< The address increment of the destination after each Y-loop transfer */
    uint32_t                   yCount;             /**< The number of transfers in the Y-loop */
    void*                      descrNext;          /**< The next descriptor to chain after completion, a NULL value will signify no chaining */
} cy_stc_axidma_descr_config_t;

/** This structure holds the initialization values for the AXI-DMA channel */
typedef struct {
    void*    AXIDMA_Descriptor; /**< The AXI-DMA descriptor associated with the channel being initialized           */
    uint32_t priority;          /**< This parameter specifies the channel's priority                            */
    uint32_t enable;            /**< This parameter specifies if the channel is enabled after initializing      */
} cy_stc_axidma_chnl_config_t;

/** \} group_axidma_data_structures */

/**
* \addtogroup group_axidma_functions
* \{
*/

//IP functions                
void                  Cy_AXIDMA_Enable             (      volatile stc_AXI_DMAC_t* pstcAXIDMA);
void                  Cy_AXIDMA_Disable            (      volatile stc_AXI_DMAC_t* pstcAXIDMA);
uint32_t              Cy_AXIDMA_GetActiveSecChnl   (const volatile stc_AXI_DMAC_t* pstcAXIDMA);
uint32_t              Cy_AXIDMA_GetActiveNonSecChnl(const volatile stc_AXI_DMAC_t* pstcAXIDMA);
                
//Descriptor functions                
cy_en_axidma_status_t Cy_AXIDMA_Descr_Init          (void* descriptor, const cy_stc_axidma_descr_config_t* config);
void                  Cy_AXIDMA_Descr_DeInit        (void* descriptor);
void                  Cy_AXIDMA_Descr_SetNxtDescr   (void* descriptor, const void* nxtDescriptor);
void                  Cy_AXIDMA_Descr_SetSrcAddr    (void* descriptor, const void* srcAddr);
void                  Cy_AXIDMA_Descr_SetDstAddr    (void* descriptor, const void* dstAddr);
void                  Cy_AXIDMA_Descr_SetIntrType   (void* descriptor, cy_en_axidma_inttype_t     interruptType);
void                  Cy_AXIDMA_Descr_SetTrigInType (void* descriptor, cy_en_axidma_trigintype_t  trigInType);
void                  Cy_AXIDMA_Descr_SetTrigOutType(void* descriptor, cy_en_axidma_trigouttype_t trigOutType);

//Channel functions                
cy_en_axidma_status_t Cy_AXIDMA_Chnl_Init                    (      volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum, const cy_stc_axidma_chnl_config_t* chnlConfig);
void                  Cy_AXIDMA_Chnl_DeInit                  (      volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum);
void                  Cy_AXIDMA_Chnl_Enable                  (      volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum);
void                  Cy_AXIDMA_Chnl_Disable                 (      volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum);
void                  Cy_AXIDMA_Chnl_SetDescr                (      volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum, const void* descriptor);
void*                 Cy_AXIDMA_Chnl_GetCurrentDescr         (const volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum);
void                  Cy_AXIDMA_Chnl_SetPriority             (      volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum, uint8_t priority);
uint8_t               Cy_AXIDMA_Chnl_GetPriority             (const volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum);
void                  Cy_AXIDMA_Chnl_SetInterrupt            (      volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum, uint32_t intMask);
void                  Cy_AXIDMA_Chnl_ClearInterrupt          (      volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum, uint32_t intMask);
void                  Cy_AXIDMA_Chnl_SetInterruptMask        (      volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum, uint32_t intMask);
uint32_t              Cy_AXIDMA_Chnl_GetInterruptMask        (const volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum);
uint32_t              Cy_AXIDMA_Chnl_GetInterruptStatusMasked(const volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum);
uint32_t              Cy_AXIDMA_Chnl_GetInterruptStatus      (const volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum);
void                  Cy_AXIDMA_Chnl_SetSwTrigger            (      volatile stc_AXI_DMAC_t* pstcAXIDMA, uint8_t chNum);

/** \} group_axidma_functions */

#if defined(__cplusplus)
}
#endif

#endif  /* (CY_AXIDMA_H) */

/** \} group_axidma */


/* [] END OF FILE */
