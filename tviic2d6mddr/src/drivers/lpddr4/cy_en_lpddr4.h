/***************************************************************************
* \file cy_en_lpddr4.h
* \version 1.0
*
* Provides the enumerated type definitions for the API declaration of the lpddr4 controller driver.
* This file was automatically created by mxs40elpddr4.xlsm on 04.05.2021 10:12:27 with the following latest Dolphin register import:
* C:\svn\chips\trunk\s40\MXS40\Platform\mxs40elpddr4\Dolphin\fromDolphin\Releases\210428_dynamo_cypress_rev0p0p31\reg_block_def_lpdd4.xlsx
*
********************************************************************************
* \copyright
* Copyright 2021, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(__CY_EN_LPDDR4_H__)
#define __CY_EN_LPDDR4_H__

// /* Frequency Set Point coding according to JESD209-4: */
// typedef enum {
//     CY_LPDDR4_FSP_FSP0 = 0, /**< Frequency Set Point 0 */
//     CY_LPDDR4_FSP_FSP1 = 1 /**< Frequency Set Point 1 */
// } cy_en_lpddr4_fsp_t;


/* Burst Length values according to JESD209-4: */
typedef enum {
    CY_LPDDR4_BL_16 = 0x0, /**< Burst Length = 16 Sequential (default) */
    CY_LPDDR4_BL_32 = 0x1, /**< Burst Length = 32 Sequential */
    CY_LPDDR4_BL_OTF = 0x2 /**< Burst Length = 16 or 32 Sequential (on-the-fly) */
} cy_en_lpddr4_bl_t;


/* Data Mask Disable values according to JESD209-4:
 */
typedef enum {
    CY_LPDDR4_DMD_ENABLED = 0x0, /**< Data Mask Operation Enabled (default) */
    CY_LPDDR4_DMD_DISABLED = 0x1 /**< Data Mask Operation Disabled */
} cy_en_lpddr4_dmd_t;


/* Selects how many copies of drivers are turned on. Number of drivers:  */
typedef enum {
    CY_LPDDR4_DRVSEL_DRV1 = 0x0, /**< 1 driver */
    CY_LPDDR4_DRVSEL_DRV2 = 0x1, /**< 2 drivers */
    CY_LPDDR4_DRVSEL_DRV3 = 0x2, /**< 3 drivers */
    CY_LPDDR4_DRVSEL_DRV4 = 0x3, /**< 4 drivers */
    CY_LPDDR4_DRVSEL_DRV5 = 0x4, /**< 5 drivers */
    CY_LPDDR4_DRVSEL_DRV6 = 0x5, /**< 6 drivers */
    CY_LPDDR4_DRVSEL_DRV7 = 0x6, /**< 7 drivers */
    CY_LPDDR4_DRVSEL_DRV8 = 0x7 /**< 8 drivers */
} cy_en_lpddr4_drvsel_t;


/* Enable/disable coding: */
typedef enum {
    CY_LPDDR4_ENDIS_ENABLE = 0, /**< Enable this feature */
    CY_LPDDR4_ENDIS_DISABLE = 1 /**< Disable this feature */
} cy_en_lpddr4_endis_t;


/* Driver output enable */
typedef enum {
    CY_LPDDR4_FENA_RCV_DRV_TRISTATE = 0, /**< Driver in tristate */
    CY_LPDDR4_FENA_RCV_DRV_ENABLE = 1 /**< Driver enabled */
} cy_en_lpddr4_fena_rcv_t;


/* Write Recovery values according to JESD209-4:
 */
typedef enum {
    CY_LPDDR4_NWR_NWR6 = 0x0, /**< nWR = 6 (default) */
    CY_LPDDR4_NWR_NWR10 = 0x1, /**< nWR = 10 */
    CY_LPDDR4_NWR_NWR16 = 0x2, /**< nWR = 16 */
    CY_LPDDR4_NWR_NWR20 = 0x3, /**< nWR = 20 */
    CY_LPDDR4_NWR_NWR24 = 0x4, /**< nWR = 24 */
    CY_LPDDR4_NWR_NWR30 = 0x5, /**< nWR = 30 */
    CY_LPDDR4_NWR_NWR34 = 0x6, /**< nWR = 34 */
    CY_LPDDR4_NWR_NWR40 = 0x7 /**< nWR = 40 */
} cy_en_lpddr4_nwr_t;


/* Output Driver Disable. When set to 1, the corresponding output is forced to high-Z. */
typedef enum {
    CY_LPDDR4_ODIS_NORMAL = 0, /**< Normal operation */
    CY_LPDDR4_ODIS_FORCE_HIZ = 1 /**< Forced to high-Z */
} cy_en_lpddr4_odis_t;


/* On Die Termination (ODT) values according to JESD209-4:
 */
typedef enum {
    CY_LPDDR4_ODT_DISABLED = 0x0, /**< Disable (Default) */
    CY_LPDDR4_ODT_RZQ_DIV_1 = 0x1, /**< RZQ/1 */
    CY_LPDDR4_ODT_RZQ_DIV_2 = 0x2, /**< RZQ/2 */
    CY_LPDDR4_ODT_RZQ_DIV_3 = 0x3, /**< RZQ/3 */
    CY_LPDDR4_ODT_RZQ_DIV_4 = 0x4, /**< RZQ/4 */
    CY_LPDDR4_ODT_RZQ_DIV_5 = 0x5, /**< RZQ/5 */
    CY_LPDDR4_ODT_RZQ_DIV_6 = 0x6 /**< RZQ/6 */
} cy_en_lpddr4_odt_t;


/* Command/Address bus ODT termination disable. Values according to JESD209-4:
 */
typedef enum {
    CY_LPDDR4_ODTDCA_ODT_CA_PAD = 0x0, /**< ODT-CA Obeys ODT_CA bond pad (default) */
    CY_LPDDR4_ODTDCA_ODT_CA_DISABLED = 0x1 /**< ODT-CA Disabled */
} cy_en_lpddr4_odtdca_t;


/* ODT Enable for non-terminating rank. Values according to JESD209-4:
 */
typedef enum {
    CY_LPDDR4_ODTE_OVERRIDE_DISABLED = 0x0, /**< ODT-CK Over-ride Disabled (Default) */
    CY_LPDDR4_ODTE_OVERRIDE_ENABLED = 0x1 /**< ODT-CK Over-ride Enabled */
} cy_en_lpddr4_odte_t;


/* Enable/disable coding: */
typedef enum {
    CY_LPDDR4_ONOFF_DISABLE = 0, /**< Disable this feature */
    CY_LPDDR4_ONOFF_ENABLE = 1 /**< Enable this feature */
} cy_en_lpddr4_onoff_t;


/* Pull-Down Drive Strength values according to JESD209-4:
 */
typedef enum {
    CY_LPDDR4_PDDS_RFU = 0x0, /**< RFU */
    CY_LPDDR4_PDDS_RZQ_DIV_1 = 0x1, /**< RZQ/1 */
    CY_LPDDR4_PDDS_RZQ_DIV_2 = 0x2, /**< RZQ/2 */
    CY_LPDDR4_PDDS_RZQ_DIV_3 = 0x3, /**< RZQ/3 */
    CY_LPDDR4_PDDS_RZQ_DIV_4 = 0x4, /**< RZQ/4 */
    CY_LPDDR4_PDDS_RZQ_DIV_5 = 0x5, /**< RZQ/5 */
    CY_LPDDR4_PDDS_RZQ_DIV_6 = 0x6, /**< RZQ/6 (default) */
    CY_LPDDR4_PDDS_RESERVED = 0x7 /**< Reserved */
} cy_en_lpddr4_pdds_t;


/* Pull-up Calibration point values according to JESD209-4:
 */
typedef enum {
    CY_LPDDR4_PUCAL_VDDQ_DIV_2P5 = 0x0, /**< VDDQ/2.5 */
    CY_LPDDR4_PUCAL_VDDQ_DIV_3 = 0x1 /**< VDDQ/3 (default) */
} cy_en_lpddr4_pucal_t;


/* Read Preamble values according to JESD209-4:
 */
typedef enum {
    CY_LPDDR4_RPRE_RD_PREAMBLE_STATIC = 0x0, /**< RD Pre-amble = Static (default) */
    CY_LPDDR4_RPRE_RD_PREAMBLE_TOGGLE = 0x1 /**< RD Pre-amble = Toggle */
} cy_en_lpddr4_rpre_t;


/* Read Postamble values according to JESD209-4:
 */
typedef enum {
    CY_LPDDR4_RPST_RD_POSTAMBLE_0P5 = 0x0, /**< RD Post-amble = 0.5*tCK (default) */
    CY_LPDDR4_RPST_RD_POSTAMBLE_1P5 = 0x1 /**< RD Post-amble = 1.5*tCK */
} cy_en_lpddr4_rpst_t;


/* Refresh Rate Option values according to JESD209-4:
 */
typedef enum {
    CY_LPDDR4_RRO_DISABLE_RR4X2X = 0x0, /**< Disable codes 001 (Refresh Rate x 4) and 010 (Refresh Rate x 2) in MR4 OP[2:0] */
    CY_LPDDR4_RRO_ENABLE_ALL = 0x1 /**< Enable all codes in MR4 OP[2:0] */
} cy_en_lpddr4_rro_t;


/* Selects whether to use external AXI QoS field or internal combination of static and dynamic priority. */
typedef enum {
    CY_LPDDR4_RTCFG0_EXT_PRIO_STATIC_DYNAMIC = 0, /**< Internal Static or Dynamic Priority used */
    CY_LPDDR4_RTCFG0_EXT_PRIO_AXI_QOS = 1 /**< AXI QoS used */
} cy_en_lpddr4_rtcfg0_ext_prio_t;


/* Masked Write Support. */
typedef enum {
    CY_LPDDR4_RTCFG0_MWRITE_DISABLE = 0, /**< Masked Write Support enabled */
    CY_LPDDR4_RTCFG0_MWRITE_ENABLE = 1 /**< Masked Write Support enabled */
} cy_en_lpddr4_rtcfg0_mwrite_t;


/* RTT impedance when rtt_en=1. Values according to JESD209-4: */
typedef enum {
    CY_LPDDR4_RTT_SEL_RTT240 = 0x1, /**< RTT = 240Ohm */
    CY_LPDDR4_RTT_SEL_RTT120 = 0x2, /**< RTT = 120Ohm */
    CY_LPDDR4_RTT_SEL_RTT80 = 0x3, /**< RTT = 80Ohm */
    CY_LPDDR4_RTT_SEL_RTT60 = 0x4, /**< RTT = 60Ohm */
    CY_LPDDR4_RTT_SEL_RTT48 = 0x5, /**< RTT = 48Ohm */
    CY_LPDDR4_RTT_SEL_RTT40 = 0x6 /**< RTT = 40Ohm */
} cy_en_lpddr4_rtt_sel_t;


/* Controller ODT values according to JESD209-4:
 */
typedef enum {
    CY_LPDDR4_SOCODT_DISABLE = 0x0, /**< Disable (Default) */
    CY_LPDDR4_SOCODT_RZQ_DIV_1 = 0x1, /**< RZQ/1 */
    CY_LPDDR4_SOCODT_RZQ_DIV_2 = 0x2, /**< RZQ/2 */
    CY_LPDDR4_SOCODT_RZQ_DIV_3 = 0x3, /**< RZQ/3 */
    CY_LPDDR4_SOCODT_RZQ_DIV_4 = 0x4, /**< RZQ/4 */
    CY_LPDDR4_SOCODT_RZQ_DIV_5 = 0x5, /**< RZQ/5 */
    CY_LPDDR4_SOCODT_RZQ_DIV_6 = 0x6, /**< RZQ/6 */
    CY_LPDDR4_SOCODT_RFU = 0x7 /**< RFU */
} cy_en_lpddr4_socodt_t;


/* VREF Current Generator values according to JESD209-4:
 */
typedef enum {
    CY_LPDDR4_VRCG_NORMAL = 0x0, /**< Normal Operation (default) */
    CY_LPDDR4_VRCG_VREF_FAST = 0x1 /**< VREF Fast Response (high current) mode */
} cy_en_lpddr4_vrcg_t;


/* VREF Range according to JESD209-4: */
typedef enum {
    CY_LPDDR4_VREF_RANGE_RANGE0 = 0x0, /**< Range[0] enabled */
    CY_LPDDR4_VREF_RANGE_RANGE1 = 0x1 /**< Range[1] enabled */
} cy_en_lpddr4_vref_range_t;


/* Write Latency Set values according to JESD209-4: */
typedef enum {
    CY_LPDDR4_WLS_WL_SET_A = 0x0, /**< WL Set "A" (default) */
    CY_LPDDR4_WLS_WL_SET_B = 0x1 /**< WL Set "B" */
} cy_en_lpddr4_wls_t;


/* Write Preamble values according to JESD209-4:
0B: Reserved
 */
typedef enum {
    CY_LPDDR4_WPRE_WR_PREAMBLE_2 = 0x1 /**< WR Pre-amble = 2*tCK */
} cy_en_lpddr4_wpre_t;


/* Write post-amble values according to JESD209-4:
 */
typedef enum {
    CY_LPDDR4_WPST_WR_POSTAMBLE_0P5 = 0x0, /**< WR Post-amble = 0.5*tCK (default) */
    CY_LPDDR4_WPST_WR_POSTAMBLE_1P5 = 0x1 /**< WR Post-amble = 1.5*tCK (Vendor specific function) */
} cy_en_lpddr4_wpst_t;


/* Channel coding: */
typedef enum {
    CY_LPDDR4_CHAN_SEL_A = 0x1, /**< Channel A */
    CY_LPDDR4_CHAN_SEL_B = 0x2, /**< Channel B */
    CY_LPDDR4_CHAN_SEL_AB = 0x3 /**< Both Channels */
} cy_en_lpddr4_chan_sel_t;


/* UCI register: Enumeration type for field CMD_OP */
typedef enum {
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_STOP = 0x0, /**< Stop Normal Operation */
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_RUN = 0x1, /**< Start Normal Operation */
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_SRE = 0x2, /**< Self-Refresh Mode Entry */
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_SRX = 0x3, /**< Self-Refresh Mode Exit */
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_PDE = 0x4, /**< Power-Down Mode Entry */
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_PDX = 0x5, /**< Power-Down Mode Exit */
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_ZQRS = 0x6, /**< ZQ Calibration Reset */
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_MRR = 0x7, /**< Mode Register Read */
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_MRW = 0x8, /**< Mode Register Write */
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_BIST = 0x9, /**< BIST */
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_ZQSTART = 0xA, /**< ZQSTART */
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_ZQLAT = 0xB, /**< ZQLAT */
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_DQSOSC_START = 0xC, /**< Start DQS Oscillator */
    CY_LPDDR4_UCI_CMD_OP_USER_CMD_DQSOSC_STOP = 0xD /**< Stop DQS Oscillator */
} cy_en_lpddr4_uci_cmd_op_t;


/* DMCTL register: Enumeration type for field DDRT */
typedef enum {
    CY_LPDDR4_DMCTL_DDRT_LPDDR4 = 0x7 /**< LPDDR4 */
} cy_en_lpddr4_dmctl_ddrt_t;


/* DMCTL register: Enumeration type for field DFI_FREQ_RATIO */
typedef enum {
    CY_LPDDR4_DMCTL_DFI_FREQ_RATIO_DIV_4 = 0x2 /**< Controller to PHY frequency ratio is 1:4. */
} cy_en_lpddr4_dmctl_dfi_freq_ratio_t;


/* DMCTL register: Enumeration type for field DRAM_BANK_EN */
typedef enum {
    CY_LPDDR4_DMCTL_DRAM_BANK_EN_BANKS4 = 0x1, /**< 4 banks */
    CY_LPDDR4_DMCTL_DRAM_BANK_EN_BANKS8 = 0x3 /**< 8 banks */
} cy_en_lpddr4_dmctl_dram_bank_en_t;


/* DMCTL register: Enumeration type for field SWITCH_CLOSE */
typedef enum {
    CY_LPDDR4_DMCTL_SWITCH_CLOSE_DONT_CLOSE_ON_RW_CHG = 0, /**< Do not close an open page when Read/Write direction changes on the same page. */
    CY_LPDDR4_DMCTL_SWITCH_CLOSE_DO_CLOSE_ON_RW_CHG = 1 /**< Close an open page when Read/Write direction changes on the same page. */
} cy_en_lpddr4_dmctl_switch_close_t;


/* DMCTL register: Enumeration type for field BANK_POLICY */
typedef enum {
    CY_LPDDR4_DMCTL_BANK_POLICY_CLOSE_PAGE = 0, /**< Close Page Policy */
    CY_LPDDR4_DMCTL_BANK_POLICY_OPEN_PAGE = 1 /**< Open page policy */
} cy_en_lpddr4_dmctl_bank_policy_t;


/* DMCFG register: Enumeration type for field INT_GC_FSM_CLR */
typedef enum {
    CY_LPDDR4_DMCFG_INT_GC_FSM_CLR_DONT_CLEAR = 0, /**< Don't clear. */
    CY_LPDDR4_DMCFG_INT_GC_FSM_CLR_DO_CLEAR = 1 /**< Clear. Set int_gc_fsm LOW. */
} cy_en_lpddr4_dmcfg_int_gc_fsm_clr_t;


/* POM register: Enumeration type for field POM_FS */
typedef enum {
    CY_LPDDR4_POM_POM_FS_FS0 = 0, /**< Frequency Set Point 0 */
    CY_LPDDR4_POM_POM_FS_FS1 = 1 /**< Frequency Set Point 1 */
} cy_en_lpddr4_pom_pom_fs_t;


/* VTGC register: Enumeration type for field IVREFR */
typedef enum {
    CY_LPDDR4_VTGC_IVREFR_RANGE1 = 1 /**< Always write 1. */
} cy_en_lpddr4_vtgc_ivrefr_t;


/* VTGC register: Enumeration type for field IVREFTS */
typedef enum {
    CY_LPDDR4_VTGC_IVREFTS_STEPS64 = 64 /**< Always write 64. */
} cy_en_lpddr4_vtgc_ivrefts_t;


/* VTGC register: Enumeration type for field IVREFEN */
typedef enum {
    CY_LPDDR4_VTGC_IVREFEN_ENABLE = 1 /**< Always write 1. */
} cy_en_lpddr4_vtgc_ivrefen_t;


/* DQSDQCR register: Enumeration type for field MUPD */
typedef enum {
    CY_LPDDR4_DQSDQCR_MUPD_AUTOMATIC = 0, /**< Automatic update */
    CY_LPDDR4_DQSDQCR_MUPD_MANUAL = 1 /**< Manual update */
} cy_en_lpddr4_dqsdqcr_mupd_t;


/* DQSDQCR register: Enumeration type for field DIR */
typedef enum {
    CY_LPDDR4_DQSDQCR_DIR_DOWN  = 0, /**< DQS2DQ search downwards */
    CY_LPDDR4_DQSDQCR_DIR_UP    = 1 /**< DQS2DQ search upwards */
} cy_en_lpddr4_dqsdqcr_dir_t;


/* DVSTT1 register: Enumeration type for field DVSTT1_DRAM_BL_ENC */
typedef enum {
    CY_LPDDR4_DVSTT1_DVSTT1_DRAM_BL_ENC_16 = 0x0, /**< BL16, */
    CY_LPDDR4_DVSTT1_DVSTT1_DRAM_BL_ENC_32 = 0x3, /**< BL32, */
    CY_LPDDR4_DVSTT1_DVSTT1_DRAM_BL_ENC_OTF = 0x1 /**< BL16 or BL32 On-The-Fly (OTF) */
} cy_en_lpddr4_dvstt1_dvstt1_dram_bl_enc_t;


/* DVSTT1 register: Enumeration type for field DVSTT1_DFI_FREQ_RATIO */
typedef enum {
    CY_LPDDR4_DVSTT1_DVSTT1_DFI_FREQ_RATIO_FREQ_RATIO_DIV4 = 0x2 /**< Always read 2'b10 as frequency ratio controller : PHY is fixed to 1:4 */
} cy_en_lpddr4_dvstt1_dvstt1_dfi_freq_ratio_t;


/* INECCSTT3 register: Enumeration type for field ECC_ERR_BUFF_EMPTY */
typedef enum {
    CY_LPDDR4_INECCSTT3_ECC_ERR_BUFF_EMPTY_NO = 0, /**< The FIFO is not empty, some data errors occur */
    CY_LPDDR4_INECCSTT3_ECC_ERR_BUFF_EMPTY_YES = 1 /**< The FIFO is empty, no error occurs */
} cy_en_lpddr4_ineccstt3_ecc_err_buff_empty_t;


/* INECCSTT3 register: Enumeration type for field ECC_ERR_BUFF_FULL */
typedef enum {
    CY_LPDDR4_INECCSTT3_ECC_ERR_BUFF_FULL_NO = 0, /**< The FIFO is not full */
    CY_LPDDR4_INECCSTT3_ECC_ERR_BUFF_FULL_YES = 1 /**< The FIFO is full, the FIFO cannot collect the information of new errors */
} cy_en_lpddr4_ineccstt3_ecc_err_buff_full_t;

#endif /* __CY_EN_LPDDR4_H__ */
