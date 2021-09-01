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

/*
cpuss.mpu_vio[0]	        "CM0+ MPU/SMPU violation.
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
                            DATA1[31]: '0' MPU violation; '1': SMPU violation."
cpuss.mpu_vio[1]	        CRYPTO MPU/SMPU violation. See MPU_0 description.
cpuss.mpu_vio[2]	        DW0 MPU/SMPU violation. See MPU_0 description.
cpuss.mpu_vio[3]	        DW1 MPU/SMPU violation. See MPU_0 description.
cpuss.mpu_vio[4]	        DMAC MPU/SMPU violation. See MPU_0 description
cpuss.mpu_vio[15]	        Test Controller MPU/SMPU violation. See MPU_0 description.
cpuss.mpu_vio[16]	        CM4 system bus AHB-Lite interface MPU violaton. See MPU_0 description.
cpuss.mpu_vio[17]	        CM4 code bus AHB-Lite interface MPU violation for non flash controller accesses. See MPU_0 description.
cpuss.mpu_vio[18]	        CM4 code bus AHB-Lite interface MPU violation for flash controller accesses. See MPU_0 description.
                            peri.peri_c_ecc	"Peri protection SRAM correctable ECC violation
                            DATA0[10:0]: Violating address.
                            DATA1[7:0]: Syndrome of SRAM word."
peri.peri_nc_ecc	        Peri protection SRAM non-correctable ECC violation. See PERI_ECC description.
peri.ms_vio[0]	            "CM0+ Peripheral Master Interface PPU violation
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
                            DATA1[31:28]: ""0"": master interface, PPU violation, ""1': timeout detected, ""2"": bus error, other: undefined."
peri.ms_vio[1]	            CM4 Peripheral Master Interface PPU violation. See MS_PPU_0 description.
peri.ms_vio[2]	            DW0 Peripheral Master Interface PPU violation. See MS_PPU_0 description.
peri.ms_vio[3]	            DW1 Peripheral Master Interface PPU violation. See MS_PPU_0 description.
peri.group_vio[0]	        "Peripheral group #0 violation
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
                            DATA1[31:28]: ""0"": decoder or peripheral bus error, other: undefined."
peri.group_vio[1]	        Peripheral group #1 violation. See GROUP_FAULT_0 description.
peri.group_vio[2]	        Peripheral group #2 violation. See GROUP_FAULT_0 description.
peri.group_vio[3]	        Peripheral group #3 violation. See GROUP_FAULT_0 description.
peri.group_vio[4]	        Peripheral group #4 violation. See GROUP_FAULT_0 description.
peri.group_vio[5]	        Peripheral group #5 violation. See GROUP_FAULT_0 description.
peri.group_vio[6]	        Peripheral group #6 violation. See GROUP_FAULT_0 description.
peri.group_vio[8]	        Peripheral group #8 violation. See GROUP_FAULT_0 description.
peri.group_vio[9]	        Peripheral group #9 violation. See GROUP_FAULT_0 description.
cpuss.flashc_main_bus_err	"Flash controller main flash bus error
                            FAULT_DATA0[26:0]: Violating address. Append 5'b00010 as most significant bits to derive 32-bit system address.
                            FAULT_DATA1[11:8]: Master identifier. "
cpuss.flashc_main_c_ecc	    "Flash controller main flash correctable ECC violation
                            DATA[26:0]: Violating address.  Append 5'b00010 as most significant bits to derive 32-bit system address.
                            DATA1[7:0]: Syndrome of 64-bit word (at address offset 0x00).
                            DATA1[15:8]: Syndrome of 64-bit word (at address offset 0x08).
                            DATA1[23:16]: Syndrome of 64-bit word (at address offset 0x10).
                            DATA1[31:24]: Syndrome of 64-bit word (at address offset 0x18)."
cpuss.flashc_main_nc_ecc	Flash controller main flash non-correctable ECC violation. See FLASHC_MAIN_C_ECC description.
cpuss.flashc_work_bus_err	"Flash controller work flash bus error
                            FAULT_DATA0[26:0]: Violating address. Append 5'b00010 as most significant bits to derive 32-bit system address.
                            FAULT_DATA1[11:8]: Master identifier. "
cpuss.flashc_work_c_ecc	    "Flash controller work flash correctable ECC violation
                            DATA0[26:0]: Violating address.  Append 5'b00010 as most significant bits to derive 32-bit system address.
                            DATA1[6:0]: Syndrome of 32-bit word."
cpuss.flashc_work_nc_ecc	Flash controller work flash non-correctable ECC violation. See FLASHC_WORK_C_ECC description.
cpuss.flashc_cm0_ca_c_ecc	"Flash controller CM0+ cache correctable ECC violation
                            DATA0[26:0]: Violating address.
                            DATA1[6:0]: Syndrome of 32-bit SRAM word (at address offset 0x0).
                            DATA1[14:8]: Syndrome of 32-bit SRAM word (at address offset 0x4).
                            DATA1[22:16]: Syndrome of 32-bit SRAM word (at address offset 0x8).
                            DATA1[30:24]: Syndrome of 32-bit SRAM word (at address offset 0xc)."
cpuss.flashc_cm0_ca_nc_ecc	Flash controller CM0+ cache non-correctable ECC violation. See FLASHC_CM0_CA_C_ECC description.
cpuss.flashc_cm4_ca_c_ecc	Flash controller CM4 cache correctable ECC violation. See FLASHC_CM0_CA_C_ECC description.
cpuss.flashc_cm4_ca_nc_ecc	Flash controller CM4 cache non-correctable ECC violation. See FLASHC_CM0_CA_C_ECC description.
cpuss.ramc0_c_ecc	        "System memory controller 0 correctable ECC violation
                            DATA0[31:0]: Violating address.
                            DATA1[6:0]: Syndrome of 32-bit SRAM code word."
cpuss.ramc0_nc_ecc	        System memory controller 0 non-correctable ECC violation. See RAMC0_C_ECC description.
cpuss.ramc1_c_ecc	        System memory controller 1 correctable ECC violation. See RAMC0_C_ECC description.
cpuss.ramc1_nc_ecc	        System memory controller 1 non-correctable ECC violation. See RAMC0_C_ECC description.
cpuss.crypto_c_ecc	        "Crypto memory correctable ECC violation
                            DATA0[31:0]: Violating address.
                            DATA1[6:0]:   Syndrome of Least Significant 32-bit SRAM.
                            DATA1[14:8]: Syndrome of Most Significant 32-bit SRAM."
cpuss.crypto_nc_ecc	        Crypto memory non-correctable ECC violation. See CRYPTO_C_ECC description.
cpuss.dw0_c_ecc	            "Datawire0 memory correctable ECC violation
                            DATA0[11:0]: Violating DW SRAM address (word address, assuming byte addressable).
                            DATA1[6:0]: Syndrome of 32-bit SRAM code word."
cpuss.dw0_nc_ecc	        Datawire0 memory non-correctable ECC violation. See DW0_C_ECC description.
cpuss.dw1_c_ecc	            Datawire1 memory correctable ECC violation. See DW0_C_ECC description.
cpuss.dw1_nc_ecc	        Datawire1 memory non-correctable ECC violation. See DW0_C_ECC description.
cpuss.fm_sram_c_ecc	        "Flash code storage sram memory correctable ECC violation
                            DATA0[15:0]: Address location in the eCT Flash SRAM.
                            DATA1[6:0]: Syndrome of 32-bit SRAM word."
cpuss.fm_sram_nc_ecc	    Flash code storage sram memory non-correctable ECC violation. See FM_SRAM_C_ECC description.
canfd[0].can_c_ecc	        "CAN0 message buffer correctable ECC violation
                            DATA0[15:0]: Violating address.
                            DATA0[22:16]: ECC violating data[38:32] from MRAM.
                            DATA0[27:24]: Master ID: 0-7 = CAN channel ID within cluster, 8 = AHB I/F
                            DATA1[31:0]: ECC violating data[31:0] from MRAM."
canfd[0].can_nc_ecc	        "CAN0 message buffer non-correctable ECC violation
                            DATA0[15:0]: Violating address.
                            DATA0[22:16]: ECC violating data[38:32] from MRAM (not for Address Error).
                            DATA0[27:24]: Master ID: 0-7 = CAN channel ID within cluster, 8 = AHB I/F
                            DATA0[30]: Write access, only possible for Address Error 
                            DATA0[31]: Address Error: a CAN channel did an MRAM access above MRAM_SIZE
                            DATA1[31:0]: ECC violating data[31:0] from MRAM (not for Address Error)."
canfd[1].can_c_ecc	        CAN1 message buffer correctable ECC violation. See CAN0_C_ECC description.
canfd[1].can_nc_ecc	        CAN1 message buffer non-correctable ECC violation. See CAN0_NC_ECC description.
srss.fault_csv	            "Consolidated fault output for clock supervisors. Multiple CSV can detect a violation at the same time.
                            DATA0[15:0]: CSV violation occurred on corresponding CLK_HF* root clock
                            DATA0[24]: CSV violation occurred on reference clock for CLK_HF CSVs
                            DATA0[25]: CSV violation occurred on CLK_LF
                            DATA0[26]: CSV violation occurred on CLK_ILO0
                            DATA0[27]: CSV violation occurred on CLK_BAK"
srss.fault_ssv	            "Consolidated fault output for supply supervisors. Multiple counters can detect a violation at the same time.
                            DATA0[0]: BOD detected on VDDA
                            DATA0[1]: OVD detected on VDDA
                            DATA0[16]: violation detected on LVD/HVD #1 
                            DATA0[17]: violation detected on LVD/HVD #2"
srss.fault_mcwdt0	        "Fault output for MCWDT0 (all sub-counters). Multiple counters can detect a violation at the same time.
                            DATA0[0]: MCWDT subcounter 0 LOWER_LIMIT
                            DATA0[1]: MCWDT subcounter 0 UPPER_LIMIT
                            DATA0[2]: MCWDT subcounter 1 LOWER_LIMIT
                            DATA0[3]: MCWDT subcounter 1 UPPER_LIMIT"
srss.fault_mcwdt1	        Fault output for MCWDT1 (all sub-counters). See SRSS_MCWDT0 description.
*/

/**
* SysFlt Driver errors
*/
typedef enum 
{
    CY_SYSFLT_CPUSS_MPU_VIO_0                 = 0x0000u,
    CY_SYSFLT_CPUSS_MPU_VIO_1                 = 0x0001u,
    CY_SYSFLT_CPUSS_MPU_VIO_2                 = 0x0002u,
    CY_SYSFLT_CPUSS_MPU_VIO_3                 = 0x0003u,
    CY_SYSFLT_CPUSS_MPU_VIO_4                 = 0x0004u,
    CY_SYSFLT_CPUSS_MPU_VIO_15                = 0x000Fu,
    CY_SYSFLT_CPUSS_MPU_VIO_16                = 0x0010u,
    CY_SYSFLT_CPUSS_MPU_VIO_17                = 0x0011u,
    CY_SYSFLT_CPUSS_MPU_VIO_18                = 0x0012u,
    CY_SYSFLT_PERI_PERI_C_ECC                 = 0x001Au,
    CY_SYSFLT_PERI_PERI_NC_ECC                = 0x001Bu,
    CY_SYSFLT_PERI_MS_VIO_0                   = 0x001Cu,
    CY_SYSFLT_PERI_MS_VIO_1                   = 0x001Du,
    CY_SYSFLT_PERI_MS_VIO_2                   = 0x001Eu,
    CY_SYSFLT_PERI_MS_VIO_3                   = 0x001Fu,
    CY_SYSFLT_PERI_GROUP_VIO_0                = 0x0020u,
    CY_SYSFLT_PERI_GROUP_VIO_1                = 0x0021u,
    CY_SYSFLT_PERI_GROUP_VIO_2                = 0x0022u,
    CY_SYSFLT_PERI_GROUP_VIO_3                = 0x0023u,
    CY_SYSFLT_PERI_GROUP_VIO_4                = 0x0024u,
    CY_SYSFLT_PERI_GROUP_VIO_5                = 0x0025u,
    CY_SYSFLT_PERI_GROUP_VIO_6                = 0x0026u,
    CY_SYSFLT_PERI_GROUP_VIO_8                = 0x0028u,
    CY_SYSFLT_PERI_GROUP_VIO_9                = 0x0029u,
    CY_SYSFLT_CPUSS_FLASHC_MAIN_BUS_ERR       = 0x0030u,
    CY_SYSFLT_CPUSS_FLASHC_MAIN_C_ECC         = 0x0031u,
    CY_SYSFLT_CPUSS_FLASHC_MAIN_NC_ECC        = 0x0032u,
    CY_SYSFLT_CPUSS_FLASHC_WORK_BUS_ERR       = 0x0033u,
    CY_SYSFLT_CPUSS_FLASHC_WORK_C_ECC         = 0x0034u,
    CY_SYSFLT_CPUSS_FLASHC_WORK_NC_ECC        = 0x0035u,
    CY_SYSFLT_CPUSS_FLASHC_CM0_CA_C_ECC       = 0x0036u,
    CY_SYSFLT_CPUSS_FLASHC_CM0_CA_NC_ECC      = 0x0037u,
    CY_SYSFLT_CPUSS_FLASHC_CM4_CA_C_ECC       = 0x0038u,
    CY_SYSFLT_CPUSS_FLASHC_CM4_CA_NC_ECC      = 0x0039u,
    CY_SYSFLT_CPUSS_RAMC0_C_ECC               = 0x003Au,
    CY_SYSFLT_CPUSS_RAMC0_NC_ECC              = 0x003Bu,
    CY_SYSFLT_CPUSS_RAMC1_C_ECC               = 0x003Cu,
    CY_SYSFLT_CPUSS_RAMC1_NC_ECC              = 0x003Du,
    CY_SYSFLT_CPUSS_CRYPTO_C_ECC              = 0x0040u,
    CY_SYSFLT_CPUSS_CRYPTO_NC_ECC             = 0x0041u,
    CY_SYSFLT_CPUSS_DW0_C_ECC                 = 0x0046u,
    CY_SYSFLT_CPUSS_DW0_NC_ECC                = 0x0047u,
    CY_SYSFLT_CPUSS_DW1_C_ECC                 = 0x0048u,
    CY_SYSFLT_CPUSS_DW1_NC_ECC                = 0x0049u,
    CY_SYSFLT_CPUSS_FM_SRAM_C_ECC             = 0x004Au,
    CY_SYSFLT_CPUSS_FM_SRAM_NC_ECC            = 0x004Bu,
    CY_SYSFLT_CANFD_0_CAN_C_ECC               = 0x0050u,
    CY_SYSFLT_CANFD_0_CAN_NC_ECC              = 0x0051u,
    CY_SYSFLT_CANFD_1_CAN_C_ECC               = 0x0052u,
    CY_SYSFLT_CANFD_1_CAN_NC_ECC              = 0x0053u,
    CY_SYSFLT_SRSS_FAULT_CSV                  = 0x005Au,
    CY_SYSFLT_SRSS_FAULT_SSV                  = 0x005Bu,
    CY_SYSFLT_SRSS_FAULT_MCWDT0               = 0x005Cu,
    CY_SYSFLT_SRSS_FAULT_MCWDT1               = 0x005Du,
    CY_SYSFLT_NO_FAULT,
} cy_en_sysflt_source_t;


#if defined(__cplusplus)
}
#endif

#endif /* CY_SYSFLT_CONFIG_H */

/** \} group_sysflt */

/* [] END OF FILE */
