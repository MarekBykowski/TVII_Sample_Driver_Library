/***************************************************************************//**
* \file cy_sysflt_config.h
* \version 1.0
*
* \brief
* Provides an API declaration of the Sysfault driver
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_sysflt System Fault (SysFlt)
* \{
* The SysFault driver provides an API to configure the fault reporting structure.
*
* \section group_sysflt_more_information More Information
*
* Refer to the technical reference manual (TRM) and the device datasheet.
* 
* \defgroup group_sysflt_enums Enumerated Types
*/


#if !defined(CY_SYSFLT_CONFIG_H)
#define CY_SYSFLT_CONFIG_H

#if defined(__cplusplus)
extern "C" {
#endif





/***************************************
*       Enumeration
***************************************/

/**
* \addtogroup group_sysflt_enums
* \{
*/

/**
* SysFlt Driver errors
*/
typedef enum 
{
    CY_SYSFLT_MPU_0                  =     0,    /**< CM0+ MPU/SMPU violation. */
    CY_SYSFLT_MPU_1                  =     1,    /**< CRYPTO MPU/SMPU violation. */
    CY_SYSFLT_MPU_2                  =     2,    /**< DW0 MPU/SMPU violation. */
    CY_SYSFLT_MPU_3                  =     3,    /**< DW1 MPU/SMPU violation. */
    CY_SYSFLT_MPU_4                  =     4,    /**< Bus master #4 MPU/SMPU violation (when used). */
    CY_SYSFLT_MPU_5                  =     5,    /**< Bus master #5 MPU/SMPU violation (when used). */
    CY_SYSFLT_MPU_9                  =     9,    /**< Bus master #9 MPU/SMPU violation (when used). */
    CY_SYSFLT_MPU_10                 =    10,    /**< Bus master #10 MPU/SMPU violation (when used). */
    CY_SYSFLT_MPU_13                 =    13,    /**< Bus master #13 MPU/SMPU violation (when used). */
    CY_SYSFLT_MPU_14                 =    14,    /**< Bus master #14 MPU/SMPU violation (when used). */
    CY_SYSFLT_MPU_15                 =    15,    /**< Bus master #15 MPU/SMPU violation (when used). */
    CY_SYSFLT_CM7_1_TCM_C_ECC	     =    16,	 /**< Correctable ECC error in CM7_1 TCM memory. See CM7_0_TCM_C_ECC description. */
    CY_SYSFLT_CM7_1_TCM_NC_ECC	     =    17,	 /**< Non Correctable ECC error in CM7_1 TCM memory. See CM7_0_TCM_C_ECC description. */
    CY_SYSFLT_CM7_0_CACHE_C_ECC	     =    18,	 /**< Correctable ECC error in CM7_0 Cache memories
                                                      DATA0[16:2]: location information: Tag/Data SRAM, Way, Index and  line Offset, see CM7 UGRM IEBR0/DEBR0 description for details. 
                                                      DATA0[31]: 0=Instruction cache, 1= Data cache */
    CY_SYSFLT_CM7_0_CACHE_NC_ECC     =    19,	 /**< Non Correctable ECC error in CM7_0 Cache memories. See CM7_0_CACHE_C_ECC descripption */
    CY_SYSFLT_CM7_1_CACHE_C_ECC	     =    20,	 /**< Correctable ECC error in CM7_1 Cache memories
                                                      DATA0[16:2]: location information: Tag/Data SRAM, Way, Index and  line Offset, see CM7 UGRM IEBR0/DEBR0 description for details. 
                                                      DATA0[31]: 0=Instruction cache, 1= Data cache */
    CY_SYSFLT_CM7_1_CACHE_NC_ECC     =    21,	 /**< Non Correctable ECC error in CM7_1 Cache memories. See CM7_1_CACHE_C_ECC descripption */    
    CY_SYSFLT_MS_PPU_4               =    25,    /**< Peripheral interconnect, master interface 4 PPU. See MS_PPU_0 description. */
    CY_SYSFLT_PERI_ECC               =    26,    /**< Peri protection SRAM correctable ECC violation */
    CY_SYSFLT_PERI_NC_ECC            =    27,    /**< Peri protection SRAM non-correctable ECC violation. */
    CY_SYSFLT_MS_PPU_0               =    28,    /**< CM0+ Peripheral Master Interface PPU violation.*/
    CY_SYSFLT_MS_PPU_1               =    29,    /**< CM7_0 Peripheral Master Interface PPU violation. */
    CY_SYSFLT_MS_PPU_2               =    30,    /**< CM7_1 Peripheral Master Interface PPU violation. */
    CY_SYSFLT_MS_PPU_3               =    31,    /**< DW0 Peripheral Master Interface PPU violation. */
    CY_SYSFLT_GROUP_FAULT_0          =    32,    /**< Peripheral group #0 PPU violation*/
    CY_SYSFLT_GROUP_FAULT_1          =    33,    /**< Peripheral group #1 PPU violation */
    CY_SYSFLT_GROUP_FAULT_2          =    34,    /**< Peripheral group #2 PPU violation */
    CY_SYSFLT_GROUP_FAULT_3          =    35,    /**< Peripheral group #3 PPU violation */
    CY_SYSFLT_GROUP_FAULT_4          =    36,    /**< Peripheral group #4 PPU violation */
    CY_SYSFLT_GROUP_FAULT_5          =    37,    /**< Peripheral group #5 PPU violation */
    CY_SYSFLT_GROUP_FAULT_6          =    38,    /**< Peripheral group #6 PPU violation */
    CY_SYSFLT_GROUP_FAULT_8          =    40,    /**< Peripheral group #8 PPU violation*/
    CY_SYSFLT_GROUP_FAULT_9          =    41,    /**< Peripheral group #9 PPU violation */
    CY_SYSFLT_FLASHC_MAIN_BUS_ERROR  =    48,    /**< Flash controller main flash bus error */
    CY_SYSFLT_FLASHC_MAIN_C_ECC      =    49,    /**< Flash controller main flash cache correctable ECC violation */
    CY_SYSFLT_FLASHC_MAIN_NC_ECC     =    50,    /**< Flash controller main flash cache non-correctable ECC violation */
    CY_SYSFLT_FLASHC_WORK_BUS_ERROR  =    51,    /**< Flash controller work flash bus error */
    CY_SYSFLT_FLASHC_WORK_C_ECC      =    52,    /**< Flash controller work flash cache correctable ECC violation */
    CY_SYSFLT_FLASHC_WORK_NC_ECC     =    53,    /**< Flash controller work flash cache non-correctable ECC violation */
    CY_SYSFLT_FLASHC_CM0_CA_C_ECC    =    54,    /**< Flash controller CM0+ cache correctable ECC violation */
    CY_SYSFLT_FLASHC_CM0_CA_NC_ECC   =    55,    /**< Flash controller CM0+ cache non-correctable ECC violation */
    CY_SYSFLT_CM7_0_TCM_C_ECC 	     =    56,    /**< Correctable ECC error in CM7_0 TCM memory, DATA0[23:2]: Violating address. DATA1[7:0]: Syndrome of code word (at address offset 0x0).
												      DATA1[31:30]: 0= ITCM, 2=D0TCM, 3=D1TCM */
    CY_SYSFLT_CM7_0_TCM_NC_ECC       =    57,    /**< Non Correctable ECC error in CM7_0 TCM memory. See CM7_0_TCM_C_ECC description. */
    CY_SYSFLT_RAMC0_C_ECC            =    58,    /**< System SRAM 0 correctable ECC error: DATA0[31:0]: Violating address. DATA1[6:0]: Syndrome of 32-bit SRAM code word. */
    CY_SYSFLT_RAMC0_NC_ECC           =    59,    /**< System memory controller 0 non-correctable ECC violation */
    CY_SYSFLT_RAMC1_C_ECC            =    60,    /**< System memory controller 1 correctable ECC violation */
    CY_SYSFLT_RAMC1_NC_ECC           =    61,    /**< System memory controller 1 non-correctable ECC violation */
    CY_SYSFLT_RAMC2_C_ECC            =    62,    /**< System memory controller 1 correctable ECC violation */
    CY_SYSFLT_RAMC2_NC_ECC           =    63,    /**< System memory controller 1 non-correctable ECC violation */
    CY_SYSFLT_CRYPTO_C_ECC           =    64,    /**< Crypto memory correctable ECC violation */
    CY_SYSFLT_CRYPTO_NC_ECC          =    65,    /**< Crypto memory non-correctable ECC violation */
    CY_SYSFLT_DW0_C_ECC              =    70,    /**< DataWire 0 SRAM 1 correctable ECC error: DATA0[11:0]: Violating DW SRAM address (word address, assuming byte addressible).
													  DATA1[6:0]: Syndrome of 32-bit SRAM code word. */
    CY_SYSFLT_DW0_NC_ECC             =    71,    /**< Datawire0 memory non-correctable ECC violation */
    CY_SYSFLT_DW1_C_ECC              =    72,    /**< Datawire1 memory correctable ECC violation */
    CY_SYSFLT_DW1_NC_ECC             =    73,    /**< Datawire1 memory non-correctable ECC violation */
    CY_SYSFLT_FM_SRAM_C_ECC	     =    74,    /**< Flash code storage sram memory correctable ECC violation */
    CY_SYSFLT_FM_SRAM_NC_ECC         =    75,    /**< Flash code storage sram memory non-correctable ECC violation */
    CY_SYSFLT_CAN0_C_ECC             =    80,    /**< CANFD0 message buffer correctable ECC violation */
    CY_SYSFLT_CAN0_NC_ECC            =    81,    /**< CANFD0 message buffer non-correctable ECC violation */
    CY_SYSFLT_CAN1_C_ECC             =    82,    /**< CANFD1 message buffer correctable ECC violation */
    CY_SYSFLT_CAN1_NC_ECC            =    83,    /**< CANFD1 message buffer non-correctable ECC violation */
    CY_SYSFLT_SRSS_CSV               =    90,    /**< SRSS Clock SuperVisor (CSV) violation detected. Multiple CSV can detect a violation at the same time.
													  DATA0[15:0]: clk_hf* root CSV violation flags.
													  DATA0[24]: clk_ref CSV violation flag (reference clock for clk_hf CSVs)
													  DATA0[25]: clk_lf CSV violation flag
													  DATA0[26]: clk_hvilo CSV violation flag */
    CY_SYSFLT_SRSS_SSV               =    91,    /**< SRSS Clock SuperVisor (CSV) violation detected. Multiple CSV can detect a violation at the same time.
													  DATA0[0]: BOD on VDDA
													  DATA[1]: OVD on VDDA
													  DATA[16]: LVD/HVD #1
													  DATA0[17]: LVD/HVD #2 */
    CY_SYSFLT_SRSS_MCWDT0            =    92,    /**< Fault output for MCWDT0 (all sub-counters) */
    CY_SYSFLT_SRSS_MCWDT1            =    93,    /**< Fault output for MCWDT1 (all sub-counters) */
    CY_SYSFLT_SRSS_MCWDT2            =    94,    /**< Fault output for MCWDT1 (all sub-counters) */
    CY_SYSFLT_NO_FAULT,
} cy_en_sysflt_source_t;


#if defined(__cplusplus)
}
#endif

#endif /* CY_SYSFLT_CONFIG_H */

/** \} group_sysflt */

/* [] END OF FILE */
