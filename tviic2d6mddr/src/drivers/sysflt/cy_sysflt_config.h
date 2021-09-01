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
    CY_SYSFLT_CPUSS_MPU_VIO_0                 = 0x0000u,    /**< CM0+ MPU/SMPU violation. */
    CY_SYSFLT_CPUSS_MPU_VIO_1                 = 0x0001u,    /**< CRYPTO MPU/SMPU violation. */
    CY_SYSFLT_CPUSS_MPU_VIO_2                 = 0x0002u,    /**< DW0 MPU/SMPU violation. */
    CY_SYSFLT_CPUSS_MPU_VIO_3                 = 0x0003u,    /**< DW1 MPU/SMPU violation. */
    CY_SYSFLT_CPUSS_MPU_VIO_4                 = 0x0004u,    /**< DMAC SMPU violation - See MPU_0 description */
    CY_SYSFLT_CPUSS_MPU_VIO_5                 = 0x0005u,    /**< Bus master #5 MPU/SMPU violation (when used). */
    CY_SYSFLT_CPUSS_MPU_VIO_9                 = 0x0009u,    /**< ETH0 MPU/SMPU violation - See MPU_0 description */
    CY_SYSFLT_CPUSS_MPU_VIO_11                = 0x000Bu,    /**< AXI_DMAC SMPU violation - See MPU_0 description */
    CY_SYSFLT_CPUSS_MPU_VIO_12                = 0x000Cu,    /**< VIDEOSS MPU/SMPU violation - See MPU_0 description */
    CY_SYSFLT_CPUSS_MPU_VIO_13                = 0x000Du,    /**< CM7_1 SMPU violation - See MPU_0 description */
    CY_SYSFLT_CPUSS_MPU_VIO_14                = 0x000Eu,    /**< CM7_0 SMPU violation - See MPU_0 description */
    CY_SYSFLT_CPUSS_MPU_VIO_15                = 0x000Fu,    /**< Test Controller MPU/SMPU violation - See MPU_0 description */
    CY_SYSFLT_CPUSS_CM7_0_CACHE_C_ECC         = 0x0010u,    /**< Correctable ECC error in CM7_0 Cache memories
                                                                    DATA0[16:2]: location information: Tag/Data SRAM, Way, Index and  line Offset, see CM7 UGRM IEBR0/DEBR0 description for details. 
                                                                    DATA0[31]: 0=Instruction cache, 1= Data cache */
    CY_SYSFLT_CPUSS_CM7_0_CACHE_NC_ECC        = 0x0011u,    /**< Non Correctable ECC error in CM7_0 Cache memories. See CM7_0_CACHE_C_ECC descripption */
    CY_SYSFLT_CPUSS_CM7_0_TCM_C_ECC           = 0x0012u,    /**< Correctable ECC error in CM7_0 TCM memory, DATA0[23:2]: Violating address. DATA1[7:0]: Syndrome of                                                             code word (at address offset 0x0).
                                                                    DATA1[31:30]: 0= ITCM, 2=D0TCM, 3=D1TCM */
    CY_SYSFLT_CPUSS_CM7_0_TCM_NC_ECC          = 0x0013u,    /**< Non Correctable ECC error in CM7_0 TCM memory. See CM7_0_TCM_C_ECC description. */
    CY_SYSFLT_CPUSS_CM7_1_CACHE_C_ECC         = 0x0014u,    /**< Correctable ECC error in CM7_1 Cache memories. See CM7_0_CACHE_C_ECC description. */
    CY_SYSFLT_CPUSS_CM7_1_CACHE_NC_ECC        = 0x0015u,    /**< Non Correctable ECC error in CM7_1 Cache memories. See CM7_0_CACHE_C_ECC description. */
    CY_SYSFLT_CPUSS_CM7_1_TCM_C_ECC           = 0x0016u,    /**< Correctable ECC error in CM7_1 TCM memory. See CM7_0_TCM_C_ECC description. */
    CY_SYSFLT_CPUSS_CM7_1_TCM_NC_ECC          = 0x0017u,    /**< Non Correctable ECC error in CM7_1 TCM memory. See CM7_0_TCM_C_ECC description. */
    CY_SYSFLT_PERI_PERI_C_ECC                 = 0x0018u,    /**< Peri protection SRAM correctable ECC violation
                                                                    DATA0[10:0]: Violating address.
                                                                    DATA1[7:0]: Syndrome of SRAM word. */
    CY_SYSFLT_PERI_PERI_NC_ECC                = 0x0019u,    /**< Peri protection SRAM non-correctable ECC violation */
    CY_SYSFLT_PERI_MS_VIO_0                   = 0x001Au,    /**< CM0+ Peripheral Master Interface PPU violation
                                                                    DATA0[31:0]: Violating address.
                                                                    DATA1[0]: User read.
                                                                    DATA1[1]: User write.
                                                                    DATA1[2]: User execute.
                                                                    DATA1[3]: Privileged read.
                                                                    DATA1[4]: Privileged write.
                                                                    DATA1[5]: Privileged execute.
                                                                    DATA1[6]: Non-secure.
                                                                    DATA1[11:8]: Master identifier.
                                                                    DATA1[15:12]: Protection context identifier.
                                                                    DATA1[31:28]: "0": master interface, PPU violation, "1': timeout detected, "2": bus error, other: undefined. */
    CY_SYSFLT_PERI_MS_VIO_1                   = 0x001Bu,    /**< CM7_0 Peripheral Master Interface PPU violation.  See MS_PPU_0 description. */
    CY_SYSFLT_PERI_MS_VIO_2                   = 0x001Cu,    /**< CM7_1 Peripheral Master Interface PPU violation.  See MS_PPU_0 description. */
    CY_SYSFLT_PERI_MS_VIO_3                   = 0x001Du,    /**< DW0 Peripheral Master Interface PPU violation.  See MS_PPU_0 description. */
    CY_SYSFLT_PERI_MS_VIO_4                   = 0x001Eu,    /**< DW1 Peripheral Master Interface PPU violation.  See MS_PPU_0 description. */
    CY_SYSFLT_PERI_GROUP_VIO_0                = 0x0020u,    /**< Peripheral group #0 PPU violation.  
                                                                    DATA0[31:0]: Violating address.
                                                                    DATA1[0]: User read.
                                                                    DATA1[1]: User write.
                                                                    DATA1[2]: User execute.
                                                                    DATA1[3]: Privileged read.
                                                                    DATA1[4]: Privileged write.
                                                                    DATA1[5]: Privileged execute.
                                                                    DATA1[6]: Non-secure.
                                                                    DATA1[11:8]: Master identifier.
                                                                    DATA1[15:12]: Protection context identifier.
                                                                    DATA1[31:28]: "0": decoder or peripheral bus error, other: undefined. */
    CY_SYSFLT_PERI_GROUP_VIO_1                = 0x0021u,    /**< Peripheral group #1 PPU violation. See GROUP_FAULT_0 description. */
    CY_SYSFLT_PERI_GROUP_VIO_2                = 0x0022u,    /**< Peripheral group #2 PPU violation. See GROUP_FAULT_0 description. */
    CY_SYSFLT_PERI_GROUP_VIO_3                = 0x0023u,    /**< Peripheral group #3 PPU violation. See GROUP_FAULT_0 description. */
    CY_SYSFLT_PERI_GROUP_VIO_4                = 0x0024u,    /**< Peripheral group #4 PPU violation. See GROUP_FAULT_0 description. */
    CY_SYSFLT_PERI_GROUP_VIO_5                = 0x0025u,    /**< Peripheral group #5 PPU violation. See GROUP_FAULT_0 description. */
    CY_SYSFLT_PERI_GROUP_VIO_6                = 0x0026u,    /**< Peripheral group #6 PPU violation. See GROUP_FAULT_0 description. */
    CY_SYSFLT_PERI_GROUP_VIO_8                = 0x0028u,    /**< Peripheral group #8 PPU violation. See GROUP_FAULT_0 description. */
    CY_SYSFLT_PERI_GROUP_VIO_9                = 0x0029u,    /**< Peripheral group #9 PPU violation. See GROUP_FAULT_0 description. */
    CY_SYSFLT_PERI_GROUP_VIO_10               = 0x002Au,    /**< Peripheral group #10 PPU violation. See GROUP_FAULT_0 description. */
    CY_SYSFLT_CPUSS_FLASHC_MAIN_BUS_ERR       = 0x0030u,    /**< Flash controller main flash bus error
                                                                    FAULT_DATA0[26:0]: Violating address. Append 5'b00010 as most significant bits to derive 32-bit system address.
                                                                    FAULT_DATA1[11:8]: Master identifier. */
    CY_SYSFLT_CPUSS_FLASHC_MAIN_C_ECC         = 0x0031u,    /**< Flash controller main flash cache correctable ECC violation
                                                                    DATA[26:0]: Violating address. Append 5'b00010 as most significant bits to derive 32-bit system address.
                                                                    DATA1[7:0]: Syndrome of 64-bit word (at address offset 0x00).
                                                                    DATA1[15:8]: Syndrome of 64-bit word (at address offset 0x08).
                                                                    DATA1[23:16]: Syndrome of 64-bit word (at address offset 0x10).
                                                                    DATA1[31:24]: Syndrome of 64-bit word (at address offset 0x18). */
    CY_SYSFLT_CPUSS_FLASHC_MAIN_NC_ECC        = 0x0032u,    /**< Flash controller main flash cache non-correctable ECC violation.  
                                                                    See FLASHC_MAIN_C_ECC description. */
    CY_SYSFLT_CPUSS_FLASHC_WORK_BUS_ERR       = 0x0033u,    /**< Flash controller work flash bus error. See FLASHC_MAIN_BUS_ERROR description. */
    CY_SYSFLT_CPUSS_FLASHC_WORK_C_ECC         = 0x0034u,    /**< Flash controller work flash cache correctable ECC violation.
                                                                    DATA0[26:0]: Violating address. Append 5'b00010 as most significant bits to derive 32-bit system address.
                                                                    DATA1[6:0]: Syndrome of 32-bit word. */
    CY_SYSFLT_CPUSS_FLASHC_WORK_NC_ECC        = 0x0035u,    /**< Flash controller work flash cache non-correctable ECC violation. See FLASHC_WORK_C_ECC description. */
    CY_SYSFLT_CPUSS_FLASHC_CM0_CA_C_ECC       = 0x0036u,    /**< Flash controller CM0+ cache correctable ECC violation.
                                                                    DATA0[26:0]: Violating address.
                                                                    DATA1[6:0]: Syndrome of 32-bit SRAM word (at address offset 0x0).
                                                                    DATA1[14:8]: Syndrome of 32-bit SRAM word (at address offset 0x4).
                                                                    DATA1[22:16]: Syndrome of 32-bit SRAM word (at address offset 0x8).
                                                                    DATA1[30:24]: Syndrome of 32-bit SRAM word (at address offset 0xc). */
    CY_SYSFLT_CPUSS_FLASHC_CM0_CA_NC_ECC      = 0x0037u,    /**< Flash controller CM0+ cache non-correctable ECC violation. See FLASHC_CM0_CA_C_ECC description. */
    CY_SYSFLT_CPUSS_FM_SRAM_C_ECC             = 0x0038u,    /**< Flash code storage sram memory correctable ECC violation:
                                                                    DATA0[15:0]: Address location in the eCT Flash SRAM.
                                                                    DATA1[6:0]: Syndrome of 32-bit SRAM word. */
    CY_SYSFLT_CPUSS_FM_SRAM_NC_ECC            = 0x0039u,    /**< Flash code storage sram memory non-correctable ECC violation: See FM_SRAM_C_ECC description. */
    CY_SYSFLT_CPUSS_RAMC0_C_ECC               = 0x003Au,    /**< System memory controller 0 correctable ECC violation:
                                                                    DATA0[31:0]: Violating address.
                                                                    DATA1[6:0]: Syndrome of 32-bit SRAM code word. */
    CY_SYSFLT_CPUSS_RAMC0_NC_ECC              = 0x003Bu,    /**< System memory controller 0 non-correctable ECC violation.  See RAMC0_C_ECC description. */
    CY_SYSFLT_CPUSS_RAMC1_C_ECC               = 0x003Cu,    /**< System memory controller 1 correctable ECC violation.  See RAMC0_C_ECC description. */
    CY_SYSFLT_CPUSS_RAMC1_NC_ECC              = 0x003Du,    /**< System memory controller 1 non-correctable ECC violation.  See RAMC0_C_ECC description. */
    CY_SYSFLT_CPUSS_RAMC2_C_ECC               = 0x003Eu,    /**< System memory controller 2 correctable ECC violation.  See RAMC0_C_ECC description. */
    CY_SYSFLT_CPUSS_RAMC2_NC_ECC              = 0x003Fu,    /**< System memory controller 2 non-correctable ECC violation.  See RAMC0_C_ECC description. */
    CY_SYSFLT_CPUSS_CRYPTO_C_ECC              = 0x0040u,    /**< Crypto memory correctable ECC violation.
                                                                    DATA0[31:0]: Violating address.
                                                                    DATA1[6:0]:   Syndrome of Least Significant 32-bit SRAM.
                                                                    DATA1[14:8]: Syndrome of Most Significant 32-bit SRAM. */
    CY_SYSFLT_CPUSS_CRYPTO_NC_ECC             = 0x0041u,    /**< Crypto memory non-correctable ECC violation */
    CY_SYSFLT_CPUSS_DW0_C_ECC                 = 0x0042u,    /**< Datawire0 memory correctable ECC violation:
                                                                    DATA0[11:0]: Violating DW SRAM address (word address, assuming byte addressable).
                                                                    DATA1[6:0]: Syndrome of 32-bit SRAM code word. */
    CY_SYSFLT_CPUSS_DW0_NC_ECC                = 0x0043u,    /**< Datawire0 memory non-correctable ECC violation. See DW0_C_ECC description. */
    CY_SYSFLT_CPUSS_DW1_C_ECC                 = 0x0044u,    /**< Datawire1 memory correctable ECC violation. See DW0_C_ECC description. */
    CY_SYSFLT_CPUSS_DW1_NC_ECC                = 0x0045u,    /**< Datawire1 memory non-correctable ECC violation. See DW0_C_ECC description. */
    CY_SYSFLT_CANFD_0_CAN_C_ECC               = 0x0046u,    /**< CAN0 message buffer correctable ECC violation:
                                                                    DATA0[15:0]: Violating address.
                                                                    DATA0[22:16]: ECC violating data[38:32] from MRAM.
                                                                    DATA0[27:24]: Master ID: 0-7 = CAN channel ID within mxttcanfd cluster, 8 = AHB I/F */
    CY_SYSFLT_CANFD_0_CAN_NC_ECC              = 0x0047u,    /**< CAN0 message buffer non-correctable ECC violation:
                                                                    DATA0[15:0]: Violating address.
                                                                    DATA0[22:16]: ECC violating data[38:32] from MRAM (not for Address Error).
                                                                    DATA0[27:24]: Master ID: 0-7 = CAN channel ID within mxttcanfd cluster, 8 = AHB I/F
                                                                    DATA0[30]: Write access, only possible for Address Error 
                                                                    DATA0[31]: Address Error: a CAN channel did an MRAM access above MRAM_SIZE */
    CY_SYSFLT_CANFD_1_CAN_C_ECC               = 0x0048u,    /**< CAN1 message buffer correctable ECC violation. See CAN0_C_ECC description. */
    CY_SYSFLT_CANFD_1_CAN_NC_ECC              = 0x0049u,    /**< CAN1 message buffer non-correctable ECC violation. See CAN0_NC_ECC description. */
    CY_SYSFLT_LPDDR4_0_LPDDR4_FATAL_FAULT     = 0x0050u,    /**< LPDDR4 fatal fault
                                                                    DATA0[0]: 0: non-correctable ECC fault  1: PLL unlock fault
                                                                    DATA0[31:1]: ""0"". Reserved */
    CY_SYSFLT_LPDDR4_0_LPDDR4_NONFATAL_FAULT  = 0x0051u,    /**< LPDDR4 correctable ECC fault
                                                                    DATA0[0]: 0: State Machine fault  1: correctable ECC fault
                                                                    DATA0[31:1]: ""0"". Reserved */
    CY_SYSFLT_LPDDR4_0_EMPU_VIDEOSS_RD_VIO_0  = 0x0052u,    /**< LPDDR4 read violation VIDEOSS AXI interface 0.  
                                                                    DATA0[31:0]: Violating address.
                                                                    DATA1[0]: User read.
                                                                    DATA1[1]: User write.
                                                                    DATA1[2]: User execute.
                                                                    DATA1[3]: Privileged read.
                                                                    DATA1[4]: Privileged write.
                                                                    DATA1[5]: Privileged execute.
                                                                    DATA1[6]: Non-secure.
                                                                    DATA1[11:8]: Master identifier.
                                                                    DATA1[15:12]: Protection context identifier.
                                                                    DATA1[30:28]: ""0"". Reserved
                                                                    DATA1[31]: Violation type:  1: smpu  0: mpu */
    CY_SYSFLT_LPDDR4_0_EMPU_VIDEOSS_RD_VIO_1  = 0x0053u,    /**< LPDDR4 read violation VIDEOSS AXI interface 1.
                                                                    DATA0[31:0]: Violating address.
                                                                    DATA1: see description above at LPDDR4_EMPU_VIDEOSS_RD_VIO0 */
    CY_SYSFLT_LPDDR4_0_EMPU_VIDEOSS_RD_VIO_2  = 0x0054u,    /**< LPDDR4 read violation VIDEOSS AXI interface 2.
                                                                    DATA0[31:0]: Violating address.
                                                                    DATA1: see description above at LPDDR4_EMPU_VIDEOSS_RD_VIO0 */
    CY_SYSFLT_LPDDR4_0_EMPU_CPUSS_RD_VIO      = 0x0055u,    /**< LPDDR4 read violation CPUSS AXI interface.
                                                                    DATA0[31:0]: Violating address.
                                                                    DATA1: see description above at LPDDR4_EMPU_VIDEOSS_RD_VIO0 */
    CY_SYSFLT_LPDDR4_0_EMPU_VIDEOSS_WR_VIO_0  = 0x0056u,    /**< LPDDR4 write violation VIDEOSS AXI interface 0.
                                                                    DATA0[31:0]: Violating address.
                                                                    DATA1: see description above at LPDDR4_EMPU_VIDEOSS_RD_VIO0 */
    CY_SYSFLT_LPDDR4_0_EMPU_VIDEOSS_WR_VIO_1  = 0x0057u,    /**< LPDDR4 write violation VIDEOSS AXI interface 1.
                                                                    DATA0[31:0]: Violating address.
                                                                    DATA1: see description above at LPDDR4_EMPU_VIDEOSS_RD_VIO0 */
    CY_SYSFLT_LPDDR4_0_EMPU_VIDEOSS_WR_VIO_2  = 0x0058u,    /**< LPDDR4 write violation VIDEOSS AXI interface 2.
                                                                    DATA0[31:0]: Violating address.
                                                                    DATA1: see description above at LPDDR4_EMPU_VIDEOSS_RD_VIO0 */
    CY_SYSFLT_LPDDR4_0_EMPU_CPUSS_WR_VIO      = 0x0059u,    /**< LPDDR4 write violation CPUSS AXI interface.
                                                                    DATA0[31:0]: Violating address.
                                                                    DATA1: see description above at LPDDR4_EMPU_VIDEOSS_RD_VIO0 */
    CY_SYSFLT_SRSS_FAULT_CSV                  = 0x005Au,    /**< Consolidated fault output for clock supervisors.  
                                                                    Multiple CSV can detect a violation at the same time.
                                                                    DATA0[15:0]: clk_hf* root CSV violation flags.
                                                                    DATA0[24]: clk_ref CSV violation flag (reference clock for clk_hf CSVs)
                                                                    DATA0[25]: clk_lf CSV violation flag
                                                                    DATA0[26]: clk_hvilo CSV violation flag */
    CY_SYSFLT_SRSS_FAULT_SSV                  = 0x005Bu,    /**< Consolidated fault output for supply supervisors. 
                                                                    Multiple CSV can detect a violation at the same time.
                                                                    DATA0[0]: BOD on VDDA
                                                                    DATA[1]: OVD on VDDA
                                                                    DATA[16]: LVD/HVD #1
                                                                    DATA0[17]: LVD/HVD #2 */
    CY_SYSFLT_SRSS_FAULT_MCWDT0               = 0x005Cu,    /**< Fault output for MCWDT0 (all sub-counters) Multiple counters can detect a violation at the same time.
                                                                    DATA0[0]: MCWDT subcounter 0 LOWER_LIMIT
                                                                    DATA0[1]: MCWDT subcounter 0 UPPER_LIMIT
                                                                    DATA0[2]: MCWDT subcounter 1 LOWER_LIMIT
                                                                    DATA0[3]: MCWDT subcounter 1 UPPER_LIMIT */
    CY_SYSFLT_SRSS_FAULT_MCWDT1               = 0x005Du,    /**< Fault output for MCWDT1 (all sub-counters). See SRSS_MCWDT0 description. */
    CY_SYSFLT_SRSS_FAULT_MCWDT2               = 0x005Eu,    /**< Fault output for MCWDT2 (all sub-counters). See SRSS_MCWDT0 description. */
    CY_SYSFLT_NO_FAULT,
} cy_en_sysflt_source_t;


#if defined(__cplusplus)
}
#endif

#endif /* CY_SYSFLT_CONFIG_H */

/** \} group_sysflt */

/* [] END OF FILE */
