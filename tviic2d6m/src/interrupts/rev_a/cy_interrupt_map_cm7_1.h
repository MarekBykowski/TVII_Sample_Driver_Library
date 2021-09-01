/***************************************************************************//**
* \file cy_interrupt_map_cm7_1.h
*
* \brief
* Provides the table with system interrupt handlers defines.
*
* \note
* Generator version: 1.4.0.1252
* Database revision: TVIIC2D6M_CFR
*
********************************************************************************
* \copyright
* Copyright 2016-2019, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CY_INTERRUPT_MAP_CM7_1_H_
#define _CY_INTERRUPT_MAP_CM7_1_H_

#include <stddef.h>
#include "syslib/cy_syslib.h"
#include "cy_device_headers.h"

#ifndef INTERRUPTS_IRQ_DEFAULT_HANDLER
    #define INTERRUPTS_IRQ_DEFAULT_HANDLER 0xFFFFFFFF
#endif

#define CY_LINK_SYSTEM_IRQ_TABLE_TO_RAM

#define  NC_HANDLER                                    INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQxx - generic "not connected" handler

#define  CPUSS_INTERRUPTS_IPC_0_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ0                   
#define  CPUSS_INTERRUPTS_IPC_1_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ1                   
#define  CPUSS_INTERRUPTS_IPC_2_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ2                   
#define  CPUSS_INTERRUPTS_IPC_3_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ3                   
#define  CPUSS_INTERRUPTS_IPC_4_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ4                   
#define  CPUSS_INTERRUPTS_IPC_5_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ5                   
#define  CPUSS_INTERRUPTS_IPC_6_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ6                   
#define  CPUSS_INTERRUPTS_IPC_7_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ7                   
#define  CPUSS_INTERRUPTS_FAULT_0_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ8                   
#define  CPUSS_INTERRUPTS_FAULT_1_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ9                   
#define  CPUSS_INTERRUPTS_FAULT_2_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ10                  
#define  CPUSS_INTERRUPTS_FAULT_3_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ11                  
#define  SRSS_INTERRUPT_BACKUP_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ12                  
#define  SRSS_INTERRUPT_MCWDT_0_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ13                  
#define  SRSS_INTERRUPT_MCWDT_1_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ14                  
#define  SRSS_INTERRUPT_MCWDT_2_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ15                  
#define  SRSS_INTERRUPT_WDT_HANDLER                    INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ17                  
#define  SRSS_INTERRUPT_HANDLER                        INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ18                  
#define  EVTGEN_0_INTERRUPT_DPSLP_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ19                  
#define  SCB_0_INTERRUPT_HANDLER                       INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ20                  
#define  IOSS_INTERRUPT_VDD_HANDLER                    INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ22                  
#define  IOSS_INTERRUPT_GPIO_DPSLP_HANDLER             INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ23                  
#define  IOSS_INTERRUPTS_GPIO_DPSLP_0_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ24                  
#define  IOSS_INTERRUPTS_GPIO_DPSLP_1_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ25                  
#define  IOSS_INTERRUPTS_GPIO_DPSLP_2_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ26                  
#define  IOSS_INTERRUPTS_GPIO_DPSLP_3_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ27                  
#define  IOSS_INTERRUPTS_GPIO_DPSLP_4_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ28                  
#define  IOSS_INTERRUPTS_GPIO_DPSLP_5_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ29                  
#define  IOSS_INTERRUPTS_GPIO_DPSLP_6_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ30                  
#define  IOSS_INTERRUPTS_GPIO_DPSLP_7_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ31                  
#define  IOSS_INTERRUPTS_GPIO_DPSLP_8_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ32                  
#define  IOSS_INTERRUPTS_GPIO_DPSLP_9_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ33                  
#define  IOSS_INTERRUPTS_GPIO_DPSLP_10_HANDLER         INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ34                  
#define  IOSS_INTERRUPTS_GPIO_DPSLP_11_HANDLER         INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ35                  
#define  IOSS_INTERRUPTS_GPIO_DPSLP_12_HANDLER         INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ36                  
#define  IOSS_INTERRUPT_GPIO_ACT_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ50                  
#define  IOSS_INTERRUPTS_GPIO_ACT_13_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ53                  
#define  IOSS_INTERRUPTS_GPIO_ACT_14_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ54                  
#define  IOSS_INTERRUPTS_GPIO_ACT_15_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ55                  
#define  IOSS_INTERRUPTS_GPIO_ACT_16_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ56                  
#define  IOSS_INTERRUPTS_GPIO_ACT_17_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ57                  
#define  IOSS_INTERRUPTS_GPIO_ACT_18_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ58                  
#define  IOSS_INTERRUPTS_GPIO_ACT_19_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ59                  
#define  IOSS_INTERRUPTS_GPIO_ACT_20_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ60                  
#define  IOSS_INTERRUPTS_GPIO_ACT_21_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ61                  
#define  IOSS_INTERRUPTS_GPIO_ACT_22_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ62                  
#define  IOSS_INTERRUPTS_GPIO_ACT_23_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ63                  
#define  IOSS_INTERRUPTS_GPIO_ACT_24_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ64                  
#define  IOSS_INTERRUPTS_GPIO_ACT_25_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ65                  
#define  IOSS_INTERRUPTS_GPIO_ACT_26_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ66                  
#define  IOSS_INTERRUPTS_GPIO_ACT_27_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ67                  
#define  IOSS_INTERRUPTS_GPIO_ACT_28_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ68                  
#define  CPUSS_INTERRUPT_CRYPTO_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ70                  
#define  CPUSS_INTERRUPT_FM_HANDLER                    INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ71                  
#define  CPUSS_INTERRUPTS_CM7_0_FP_HANDLER             INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ72                  
#define  CPUSS_INTERRUPTS_CM7_1_FP_HANDLER             INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ73                  
#define  CPUSS_INTERRUPTS_CM0_CTI_0_HANDLER            INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ74                  
#define  CPUSS_INTERRUPTS_CM0_CTI_1_HANDLER            INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ75                  
#define  CPUSS_INTERRUPTS_CM7_0_CTI_0_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ76                  
#define  CPUSS_INTERRUPTS_CM7_0_CTI_1_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ77                  
#define  CPUSS_INTERRUPTS_CM7_1_CTI_0_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ78                  
#define  CPUSS_INTERRUPTS_CM7_1_CTI_1_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ79                  
#define  EVTGEN_0_INTERRUPT_HANDLER                    INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ80                  
#define  SMIF_0_INTERRUPT_HANDLER                      INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ81                  
#define  SMIF_1_INTERRUPT_HANDLER                      INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ82                  
#define  ETH_0_INTERRUPT_ETH_0_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ83                  
#define  ETH_0_INTERRUPT_ETH_1_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ84                  
#define  ETH_0_INTERRUPT_ETH_2_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ85                  
#define  CANFD_0_INTERRUPT0_HANDLER                    INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ86                  
#define  CANFD_0_INTERRUPT1_HANDLER                    INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ87                  
#define  CANFD_1_INTERRUPT0_HANDLER                    INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ88                  
#define  CANFD_1_INTERRUPT1_HANDLER                    INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ89                  
#define  CANFD_0_INTERRUPTS0_0_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ90                  
#define  CANFD_0_INTERRUPTS0_1_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ91                  
#define  CANFD_0_INTERRUPTS1_0_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ96                  
#define  CANFD_0_INTERRUPTS1_1_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ97                  
#define  CANFD_1_INTERRUPTS0_0_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ102                 
#define  CANFD_1_INTERRUPTS0_1_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ103                 
#define  CANFD_1_INTERRUPTS1_0_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ108                 
#define  CANFD_1_INTERRUPTS1_1_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ109                 
#define  LIN_0_INTERRUPTS_0_HANDLER                    INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ114                 
#define  LIN_0_INTERRUPTS_1_HANDLER                    INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ115                 
#define  CXPI_0_INTERRUPTS_0_HANDLER                   INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ130                 
#define  CXPI_0_INTERRUPTS_1_HANDLER                   INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ131                 
#define  SCB_1_INTERRUPT_HANDLER                       INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ135                 
#define  SCB_2_INTERRUPT_HANDLER                       INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ136                 
#define  SCB_3_INTERRUPT_HANDLER                       INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ137                 
#define  SCB_4_INTERRUPT_HANDLER                       INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ138                 
#define  SCB_5_INTERRUPT_HANDLER                       INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ139                 
#define  SCB_6_INTERRUPT_HANDLER                       INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ140                 
#define  SCB_7_INTERRUPT_HANDLER                       INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ141                 
#define  SCB_8_INTERRUPT_HANDLER                       INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ142                 
#define  SCB_9_INTERRUPT_HANDLER                       INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ143                 
#define  SCB_10_INTERRUPT_HANDLER                      INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ144                 
#define  SCB_11_INTERRUPT_HANDLER                      INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ145                 
#define  VIDEOSS_0_INTERRUPT_GFX2D_HANDLER             INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ150                 
#define  VIDEOSS_0_INTERRUPT_MIPICSI_HANDLER           INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ151                 
#define  VIDEOSS_0_INTERRUPT_VIDEOIO0_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ152                 
#define  VIDEOSS_0_INTERRUPT_VIDEOIO1_HANDLER          INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ153                 
#define  VIDEOSS_0_INTERRUPT_VIDEOIO0_SAFETY_HANDLER   INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ154                 
#define  VIDEOSS_0_INTERRUPT_VIDEOIO1_SAFETY_HANDLER   INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ155                 
#define  PASS_0_INTERRUPTS_SAR_0_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ160                 
#define  PASS_0_INTERRUPTS_SAR_1_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ161                 
#define  PASS_0_INTERRUPTS_SAR_2_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ162                 
#define  PASS_0_INTERRUPTS_SAR_3_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ163                 
#define  PASS_0_INTERRUPTS_SAR_4_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ164                 
#define  PASS_0_INTERRUPTS_SAR_5_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ165                 
#define  PASS_0_INTERRUPTS_SAR_6_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ166                 
#define  PASS_0_INTERRUPTS_SAR_7_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ167                 
#define  PASS_0_INTERRUPTS_SAR_8_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ168                 
#define  PASS_0_INTERRUPTS_SAR_9_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ169                 
#define  PASS_0_INTERRUPTS_SAR_10_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ170                 
#define  PASS_0_INTERRUPTS_SAR_11_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ171                 
#define  PASS_0_INTERRUPTS_SAR_12_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ172                 
#define  PASS_0_INTERRUPTS_SAR_13_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ173                 
#define  PASS_0_INTERRUPTS_SAR_14_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ174                 
#define  PASS_0_INTERRUPTS_SAR_15_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ175                 
#define  PASS_0_INTERRUPTS_SAR_16_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ176                 
#define  PASS_0_INTERRUPTS_SAR_17_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ177                 
#define  PASS_0_INTERRUPTS_SAR_18_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ178                 
#define  PASS_0_INTERRUPTS_SAR_19_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ179                 
#define  PASS_0_INTERRUPTS_SAR_20_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ180                 
#define  PASS_0_INTERRUPTS_SAR_21_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ181                 
#define  PASS_0_INTERRUPTS_SAR_22_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ182                 
#define  PASS_0_INTERRUPTS_SAR_23_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ183                 
#define  PASS_0_INTERRUPTS_SAR_24_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ184                 
#define  PASS_0_INTERRUPTS_SAR_25_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ185                 
#define  PASS_0_INTERRUPTS_SAR_26_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ186                 
#define  PASS_0_INTERRUPTS_SAR_27_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ187                 
#define  PASS_0_INTERRUPTS_SAR_28_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ188                 
#define  PASS_0_INTERRUPTS_SAR_29_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ189                 
#define  PASS_0_INTERRUPTS_SAR_30_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ190                 
#define  PASS_0_INTERRUPTS_SAR_31_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ191                 
#define  CPUSS_INTERRUPTS_DMAC_0_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ288                 
#define  CPUSS_INTERRUPTS_DMAC_1_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ289                 
#define  CPUSS_INTERRUPTS_DMAC_2_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ290                 
#define  CPUSS_INTERRUPTS_DMAC_3_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ291                 
#define  CPUSS_INTERRUPTS_DMAC_4_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ292                 
#define  CPUSS_INTERRUPTS_DMAC_5_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ293                 
#define  CPUSS_INTERRUPTS_DMAC_6_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ294                 
#define  CPUSS_INTERRUPTS_DMAC_7_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ295                 
#define  CPUSS_INTERRUPTS_DW0_0_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ296                 
#define  CPUSS_INTERRUPTS_DW0_1_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ297                 
#define  CPUSS_INTERRUPTS_DW0_2_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ298                 
#define  CPUSS_INTERRUPTS_DW0_3_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ299                 
#define  CPUSS_INTERRUPTS_DW0_4_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ300                 
#define  CPUSS_INTERRUPTS_DW0_5_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ301                 
#define  CPUSS_INTERRUPTS_DW0_6_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ302                 
#define  CPUSS_INTERRUPTS_DW0_7_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ303                 
#define  CPUSS_INTERRUPTS_DW0_8_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ304                 
#define  CPUSS_INTERRUPTS_DW0_9_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ305                 
#define  CPUSS_INTERRUPTS_DW0_10_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ306                 
#define  CPUSS_INTERRUPTS_DW0_11_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ307                 
#define  CPUSS_INTERRUPTS_DW0_12_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ308                 
#define  CPUSS_INTERRUPTS_DW0_13_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ309                 
#define  CPUSS_INTERRUPTS_DW0_14_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ310                 
#define  CPUSS_INTERRUPTS_DW0_15_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ311                 
#define  CPUSS_INTERRUPTS_DW0_16_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ312                 
#define  CPUSS_INTERRUPTS_DW0_17_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ313                 
#define  CPUSS_INTERRUPTS_DW0_18_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ314                 
#define  CPUSS_INTERRUPTS_DW0_19_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ315                 
#define  CPUSS_INTERRUPTS_DW0_20_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ316                 
#define  CPUSS_INTERRUPTS_DW0_21_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ317                 
#define  CPUSS_INTERRUPTS_DW0_22_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ318                 
#define  CPUSS_INTERRUPTS_DW0_23_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ319                 
#define  CPUSS_INTERRUPTS_DW0_24_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ320                 
#define  CPUSS_INTERRUPTS_DW0_25_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ321                 
#define  CPUSS_INTERRUPTS_DW0_26_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ322                 
#define  CPUSS_INTERRUPTS_DW0_27_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ323                 
#define  CPUSS_INTERRUPTS_DW0_28_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ324                 
#define  CPUSS_INTERRUPTS_DW0_29_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ325                 
#define  CPUSS_INTERRUPTS_DW0_30_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ326                 
#define  CPUSS_INTERRUPTS_DW0_31_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ327                 
#define  CPUSS_INTERRUPTS_DW0_32_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ328                 
#define  CPUSS_INTERRUPTS_DW0_33_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ329                 
#define  CPUSS_INTERRUPTS_DW0_34_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ330                 
#define  CPUSS_INTERRUPTS_DW0_35_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ331                 
#define  CPUSS_INTERRUPTS_DW0_36_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ332                 
#define  CPUSS_INTERRUPTS_DW0_37_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ333                 
#define  CPUSS_INTERRUPTS_DW0_38_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ334                 
#define  CPUSS_INTERRUPTS_DW0_39_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ335                 
#define  CPUSS_INTERRUPTS_DW0_40_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ336                 
#define  CPUSS_INTERRUPTS_DW0_41_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ337                 
#define  CPUSS_INTERRUPTS_DW0_42_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ338                 
#define  CPUSS_INTERRUPTS_DW0_43_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ339                 
#define  CPUSS_INTERRUPTS_DW0_44_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ340                 
#define  CPUSS_INTERRUPTS_DW0_45_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ341                 
#define  CPUSS_INTERRUPTS_DW0_46_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ342                 
#define  CPUSS_INTERRUPTS_DW0_47_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ343                 
#define  CPUSS_INTERRUPTS_DW0_48_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ344                 
#define  CPUSS_INTERRUPTS_DW0_49_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ345                 
#define  CPUSS_INTERRUPTS_DW0_50_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ346                 
#define  CPUSS_INTERRUPTS_DW0_51_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ347                 
#define  CPUSS_INTERRUPTS_DW0_52_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ348                 
#define  CPUSS_INTERRUPTS_DW0_53_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ349                 
#define  CPUSS_INTERRUPTS_DW0_54_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ350                 
#define  CPUSS_INTERRUPTS_DW0_55_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ351                 
#define  CPUSS_INTERRUPTS_DW0_56_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ352                 
#define  CPUSS_INTERRUPTS_DW0_57_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ353                 
#define  CPUSS_INTERRUPTS_DW0_58_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ354                 
#define  CPUSS_INTERRUPTS_DW0_59_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ355                 
#define  CPUSS_INTERRUPTS_DW0_60_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ356                 
#define  CPUSS_INTERRUPTS_DW0_61_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ357                 
#define  CPUSS_INTERRUPTS_DW0_62_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ358                 
#define  CPUSS_INTERRUPTS_DW0_63_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ359                 
#define  CPUSS_INTERRUPTS_DW0_64_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ360                 
#define  CPUSS_INTERRUPTS_DW0_65_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ361                 
#define  CPUSS_INTERRUPTS_DW0_66_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ362                 
#define  CPUSS_INTERRUPTS_DW0_67_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ363                 
#define  CPUSS_INTERRUPTS_DW0_68_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ364                 
#define  CPUSS_INTERRUPTS_DW0_69_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ365                 
#define  CPUSS_INTERRUPTS_DW0_70_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ366                 
#define  CPUSS_INTERRUPTS_DW0_71_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ367                 
#define  CPUSS_INTERRUPTS_DW0_72_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ368                 
#define  CPUSS_INTERRUPTS_DW0_73_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ369                 
#define  CPUSS_INTERRUPTS_DW0_74_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ370                 
#define  CPUSS_INTERRUPTS_DW0_75_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ371                 
#define  CPUSS_INTERRUPTS_DW1_0_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ424                 
#define  CPUSS_INTERRUPTS_DW1_1_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ425                 
#define  CPUSS_INTERRUPTS_DW1_2_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ426                 
#define  CPUSS_INTERRUPTS_DW1_3_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ427                 
#define  CPUSS_INTERRUPTS_DW1_4_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ428                 
#define  CPUSS_INTERRUPTS_DW1_5_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ429                 
#define  CPUSS_INTERRUPTS_DW1_6_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ430                 
#define  CPUSS_INTERRUPTS_DW1_7_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ431                 
#define  CPUSS_INTERRUPTS_DW1_8_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ432                 
#define  CPUSS_INTERRUPTS_DW1_9_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ433                 
#define  CPUSS_INTERRUPTS_DW1_10_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ434                 
#define  CPUSS_INTERRUPTS_DW1_11_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ435                 
#define  CPUSS_INTERRUPTS_DW1_12_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ436                 
#define  CPUSS_INTERRUPTS_DW1_13_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ437                 
#define  CPUSS_INTERRUPTS_DW1_14_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ438                 
#define  CPUSS_INTERRUPTS_DW1_15_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ439                 
#define  CPUSS_INTERRUPTS_DW1_16_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ440                 
#define  CPUSS_INTERRUPTS_DW1_17_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ441                 
#define  CPUSS_INTERRUPTS_DW1_18_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ442                 
#define  CPUSS_INTERRUPTS_DW1_19_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ443                 
#define  CPUSS_INTERRUPTS_DW1_20_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ444                 
#define  CPUSS_INTERRUPTS_DW1_21_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ445                 
#define  CPUSS_INTERRUPTS_DW1_22_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ446                 
#define  CPUSS_INTERRUPTS_DW1_23_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ447                 
#define  CPUSS_INTERRUPTS_DW1_24_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ448                 
#define  CPUSS_INTERRUPTS_DW1_25_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ449                 
#define  CPUSS_INTERRUPTS_DW1_26_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ450                 
#define  CPUSS_INTERRUPTS_DW1_27_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ451                 
#define  CPUSS_INTERRUPTS_DW1_28_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ452                 
#define  CPUSS_INTERRUPTS_DW1_29_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ453                 
#define  CPUSS_INTERRUPTS_DW1_30_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ454                 
#define  CPUSS_INTERRUPTS_DW1_31_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ455                 
#define  CPUSS_INTERRUPTS_DW1_32_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ456                 
#define  CPUSS_INTERRUPTS_DW1_33_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ457                 
#define  CPUSS_INTERRUPTS_DW1_34_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ458                 
#define  CPUSS_INTERRUPTS_DW1_35_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ459                 
#define  CPUSS_INTERRUPTS_DW1_36_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ460                 
#define  CPUSS_INTERRUPTS_DW1_37_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ461                 
#define  CPUSS_INTERRUPTS_DW1_38_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ462                 
#define  CPUSS_INTERRUPTS_DW1_39_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ463                 
#define  CPUSS_INTERRUPTS_DW1_40_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ464                 
#define  CPUSS_INTERRUPTS_DW1_41_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ465                 
#define  CPUSS_INTERRUPTS_DW1_42_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ466                 
#define  CPUSS_INTERRUPTS_DW1_43_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ467                 
#define  CPUSS_INTERRUPTS_DW1_44_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ468                 
#define  CPUSS_INTERRUPTS_DW1_45_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ469                 
#define  CPUSS_INTERRUPTS_DW1_46_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ470                 
#define  CPUSS_INTERRUPTS_DW1_47_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ471                 
#define  CPUSS_INTERRUPTS_DW1_48_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ472                 
#define  CPUSS_INTERRUPTS_DW1_49_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ473                 
#define  CPUSS_INTERRUPTS_DW1_50_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ474                 
#define  CPUSS_INTERRUPTS_DW1_51_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ475                 
#define  CPUSS_INTERRUPTS_DW1_52_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ476                 
#define  CPUSS_INTERRUPTS_DW1_53_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ477                 
#define  CPUSS_INTERRUPTS_DW1_54_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ478                 
#define  CPUSS_INTERRUPTS_DW1_55_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ479                 
#define  CPUSS_INTERRUPTS_DW1_56_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ480                 
#define  CPUSS_INTERRUPTS_DW1_57_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ481                 
#define  CPUSS_INTERRUPTS_DW1_58_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ482                 
#define  CPUSS_INTERRUPTS_DW1_59_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ483                 
#define  CPUSS_INTERRUPTS_DW1_60_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ484                 
#define  CPUSS_INTERRUPTS_DW1_61_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ485                 
#define  CPUSS_INTERRUPTS_DW1_62_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ486                 
#define  CPUSS_INTERRUPTS_DW1_63_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ487                 
#define  CPUSS_INTERRUPTS_DW1_64_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ488                 
#define  CPUSS_INTERRUPTS_DW1_65_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ489                 
#define  CPUSS_INTERRUPTS_DW1_66_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ490                 
#define  CPUSS_INTERRUPTS_DW1_67_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ491                 
#define  CPUSS_INTERRUPTS_DW1_68_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ492                 
#define  CPUSS_INTERRUPTS_DW1_69_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ493                 
#define  CPUSS_INTERRUPTS_DW1_70_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ494                 
#define  CPUSS_INTERRUPTS_DW1_71_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ495                 
#define  CPUSS_INTERRUPTS_DW1_72_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ496                 
#define  CPUSS_INTERRUPTS_DW1_73_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ497                 
#define  CPUSS_INTERRUPTS_DW1_74_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ498                 
#define  CPUSS_INTERRUPTS_DW1_75_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ499                 
#define  CPUSS_INTERRUPTS_DW1_76_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ500                 
#define  CPUSS_INTERRUPTS_DW1_77_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ501                 
#define  CPUSS_INTERRUPTS_DW1_78_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ502                 
#define  CPUSS_INTERRUPTS_DW1_79_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ503                 
#define  CPUSS_INTERRUPTS_DW1_80_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ504                 
#define  CPUSS_INTERRUPTS_DW1_81_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ505                 
#define  CPUSS_INTERRUPTS_DW1_82_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ506                 
#define  CPUSS_INTERRUPTS_DW1_83_HANDLER               INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ507                 
#define  TCPWM_0_INTERRUPTS_0_HANDLER                  INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ552                 
#define  TCPWM_0_INTERRUPTS_1_HANDLER                  INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ553                 
#define  TCPWM_0_INTERRUPTS_2_HANDLER                  INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ554                 
#define  TCPWM_0_INTERRUPTS_3_HANDLER                  INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ555                 
#define  TCPWM_0_INTERRUPTS_4_HANDLER                  INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ556                 
#define  TCPWM_0_INTERRUPTS_5_HANDLER                  INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ557                 
#define  TCPWM_0_INTERRUPTS_6_HANDLER                  INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ558                 
#define  TCPWM_0_INTERRUPTS_7_HANDLER                  INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ559                 
#define  TCPWM_0_INTERRUPTS_8_HANDLER                  INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ560                 
#define  TCPWM_0_INTERRUPTS_9_HANDLER                  INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ561                 
#define  TCPWM_0_INTERRUPTS_10_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ562                 
#define  TCPWM_0_INTERRUPTS_11_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ563                 
#define  TCPWM_0_INTERRUPTS_12_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ564                 
#define  TCPWM_0_INTERRUPTS_13_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ565                 
#define  TCPWM_0_INTERRUPTS_14_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ566                 
#define  TCPWM_0_INTERRUPTS_15_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ567                 
#define  TCPWM_0_INTERRUPTS_16_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ568                 
#define  TCPWM_0_INTERRUPTS_17_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ569                 
#define  TCPWM_0_INTERRUPTS_18_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ570                 
#define  TCPWM_0_INTERRUPTS_19_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ571                 
#define  TCPWM_0_INTERRUPTS_20_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ572                 
#define  TCPWM_0_INTERRUPTS_21_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ573                 
#define  TCPWM_0_INTERRUPTS_22_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ574                 
#define  TCPWM_0_INTERRUPTS_23_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ575                 
#define  TCPWM_0_INTERRUPTS_24_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ576                 
#define  TCPWM_0_INTERRUPTS_25_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ577                 
#define  TCPWM_0_INTERRUPTS_26_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ578                 
#define  TCPWM_0_INTERRUPTS_27_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ579                 
#define  TCPWM_0_INTERRUPTS_28_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ580                 
#define  TCPWM_0_INTERRUPTS_29_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ581                 
#define  TCPWM_0_INTERRUPTS_30_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ582                 
#define  TCPWM_0_INTERRUPTS_31_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ583                 
#define  TCPWM_0_INTERRUPTS_32_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ584                 
#define  TCPWM_0_INTERRUPTS_33_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ585                 
#define  TCPWM_0_INTERRUPTS_34_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ586                 
#define  TCPWM_0_INTERRUPTS_35_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ587                 
#define  TCPWM_0_INTERRUPTS_36_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ588                 
#define  TCPWM_0_INTERRUPTS_37_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ589                 
#define  TCPWM_0_INTERRUPTS_256_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ616                 
#define  TCPWM_0_INTERRUPTS_257_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ617                 
#define  TCPWM_0_INTERRUPTS_258_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ618                 
#define  TCPWM_0_INTERRUPTS_259_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ619                 
#define  TCPWM_0_INTERRUPTS_260_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ620                 
#define  TCPWM_0_INTERRUPTS_261_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ621                 
#define  TCPWM_0_INTERRUPTS_262_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ622                 
#define  TCPWM_0_INTERRUPTS_263_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ623                 
#define  TCPWM_0_INTERRUPTS_264_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ624                 
#define  TCPWM_0_INTERRUPTS_265_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ625                 
#define  TCPWM_0_INTERRUPTS_266_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ626                 
#define  TCPWM_0_INTERRUPTS_267_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ627                 
#define  TCPWM_0_INTERRUPTS_512_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ680                 
#define  TCPWM_0_INTERRUPTS_513_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ681                 
#define  TCPWM_0_INTERRUPTS_514_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ682                 
#define  TCPWM_0_INTERRUPTS_515_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ683                 
#define  TCPWM_0_INTERRUPTS_516_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ684                 
#define  TCPWM_0_INTERRUPTS_517_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ685                 
#define  TCPWM_0_INTERRUPTS_518_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ686                 
#define  TCPWM_0_INTERRUPTS_519_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ687                 
#define  TCPWM_0_INTERRUPTS_520_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ688                 
#define  TCPWM_0_INTERRUPTS_521_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ689                 
#define  TCPWM_0_INTERRUPTS_522_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ690                 
#define  TCPWM_0_INTERRUPTS_523_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ691                 
#define  TCPWM_0_INTERRUPTS_524_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ692                 
#define  TCPWM_0_INTERRUPTS_525_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ693                 
#define  TCPWM_0_INTERRUPTS_526_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ694                 
#define  TCPWM_0_INTERRUPTS_527_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ695                 
#define  TCPWM_0_INTERRUPTS_528_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ696                 
#define  TCPWM_0_INTERRUPTS_529_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ697                 
#define  TCPWM_0_INTERRUPTS_530_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ698                 
#define  TCPWM_0_INTERRUPTS_531_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ699                 
#define  TCPWM_0_INTERRUPTS_532_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ700                 
#define  TCPWM_0_INTERRUPTS_533_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ701                 
#define  TCPWM_0_INTERRUPTS_534_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ702                 
#define  TCPWM_0_INTERRUPTS_535_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ703                 
#define  TCPWM_0_INTERRUPTS_536_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ704                 
#define  TCPWM_0_INTERRUPTS_537_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ705                 
#define  TCPWM_0_INTERRUPTS_538_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ706                 
#define  TCPWM_0_INTERRUPTS_539_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ707                 
#define  TCPWM_0_INTERRUPTS_540_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ708                 
#define  TCPWM_0_INTERRUPTS_541_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ709                 
#define  TCPWM_0_INTERRUPTS_542_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ710                 
#define  TCPWM_0_INTERRUPTS_543_HANDLER                INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ711                 
#define  I2S_0_INTERRUPTS_TX_0_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ744                 
#define  I2S_0_INTERRUPTS_RX_0_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ745                 
#define  I2S_0_INTERRUPTS_TX_1_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ746                 
#define  I2S_0_INTERRUPTS_RX_1_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ747                 
#define  I2S_0_INTERRUPTS_TX_2_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ748                 
#define  I2S_0_INTERRUPTS_RX_2_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ749                 
#define  I2S_0_INTERRUPTS_TX_3_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ750                 
#define  I2S_0_INTERRUPTS_RX_3_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ751                 
#define  TDM_0_INTERRUPTS_TX_0_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ752                 
#define  TDM_0_INTERRUPTS_RX_0_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ753                 
#define  TDM_0_INTERRUPTS_TX_1_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ754                 
#define  TDM_0_INTERRUPTS_RX_1_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ755                 
#define  TDM_0_INTERRUPTS_TX_2_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ756                 
#define  TDM_0_INTERRUPTS_RX_2_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ757                 
#define  TDM_0_INTERRUPTS_TX_3_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ758                 
#define  TDM_0_INTERRUPTS_RX_3_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ759                 
#define  SG_0_INTERRUPTS_0_HANDLER                     INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ760                 
#define  SG_0_INTERRUPTS_1_HANDLER                     INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ761                 
#define  SG_0_INTERRUPTS_2_HANDLER                     INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ762                 
#define  SG_0_INTERRUPTS_3_HANDLER                     INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ763                 
#define  SG_0_INTERRUPTS_4_HANDLER                     INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ764                 
#define  PWM_0_INTERRUPTS_0_HANDLER                    INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ768                 
#define  PWM_0_INTERRUPTS_1_HANDLER                    INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ769                 
#define  DAC_0_INTERRUPT_HANDLER                       INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ776                 
#define  MIXER_0_INTERRUPT_DST_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ780                 
#define  MIXER_0_INTERRUPTS_SRC_0_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ781                 
#define  MIXER_0_INTERRUPTS_SRC_1_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ782                 
#define  MIXER_0_INTERRUPTS_SRC_2_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ783                 
#define  MIXER_0_INTERRUPTS_SRC_3_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ784                 
#define  MIXER_0_INTERRUPTS_SRC_4_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ785                 
#define  MIXER_1_INTERRUPT_DST_HANDLER                 INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ789                 
#define  MIXER_1_INTERRUPTS_SRC_0_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ790                 
#define  MIXER_1_INTERRUPTS_SRC_1_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ791                 
#define  MIXER_1_INTERRUPTS_SRC_2_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ792                 
#define  MIXER_1_INTERRUPTS_SRC_3_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ793                 
#define  MIXER_1_INTERRUPTS_SRC_4_HANDLER              INTERRUPTS_IRQ_DEFAULT_HANDLER          // IRQ794                 

#undef INTERRUPTS_IRQ_DEFAULT_HANDLER
#define INTERRUPTS_IRQ_DEFAULT_HANDLER 0xFFFFFFFF

/* suppress warning "zero used for undefined preprocessing identifier" */
#ifdef __ghs__
    #pragma ghs nowarning 193
#endif
#ifdef __ICCARM__
    #pragma diag_suppress=Pe193
#endif

#if (NC_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                              // IRQxx - generic "not connected" handler                  
     extern void NC_HANDLER(void);                                                   
#endif

#if (CPUSS_INTERRUPTS_IPC_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ0                   
     extern void CPUSS_INTERRUPTS_IPC_0_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_IPC_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ1                   
     extern void CPUSS_INTERRUPTS_IPC_1_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_IPC_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ2                   
     extern void CPUSS_INTERRUPTS_IPC_2_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_IPC_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ3                   
     extern void CPUSS_INTERRUPTS_IPC_3_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_IPC_4_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ4                   
     extern void CPUSS_INTERRUPTS_IPC_4_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_IPC_5_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ5                   
     extern void CPUSS_INTERRUPTS_IPC_5_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_IPC_6_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ6                   
     extern void CPUSS_INTERRUPTS_IPC_6_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_IPC_7_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ7                   
     extern void CPUSS_INTERRUPTS_IPC_7_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_FAULT_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ8                   
     extern void CPUSS_INTERRUPTS_FAULT_0_HANDLER(void);                             
#endif
#if (CPUSS_INTERRUPTS_FAULT_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ9                   
     extern void CPUSS_INTERRUPTS_FAULT_1_HANDLER(void);                             
#endif
#if (CPUSS_INTERRUPTS_FAULT_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ10                  
     extern void CPUSS_INTERRUPTS_FAULT_2_HANDLER(void);                             
#endif
#if (CPUSS_INTERRUPTS_FAULT_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ11                  
     extern void CPUSS_INTERRUPTS_FAULT_3_HANDLER(void);                             
#endif
#if (SRSS_INTERRUPT_BACKUP_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ12                  
     extern void SRSS_INTERRUPT_BACKUP_HANDLER(void);                                
#endif
#if (SRSS_INTERRUPT_MCWDT_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ13                  
     extern void SRSS_INTERRUPT_MCWDT_0_HANDLER(void);                               
#endif
#if (SRSS_INTERRUPT_MCWDT_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ14                  
     extern void SRSS_INTERRUPT_MCWDT_1_HANDLER(void);                               
#endif
#if (SRSS_INTERRUPT_MCWDT_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ15                  
     extern void SRSS_INTERRUPT_MCWDT_2_HANDLER(void);                               
#endif
#if (SRSS_INTERRUPT_WDT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)              // IRQ17                  
     extern void SRSS_INTERRUPT_WDT_HANDLER(void);                                   
#endif
#if (SRSS_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                  // IRQ18                  
     extern void SRSS_INTERRUPT_HANDLER(void);                                       
#endif
#if (EVTGEN_0_INTERRUPT_DPSLP_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ19                  
     extern void EVTGEN_0_INTERRUPT_DPSLP_HANDLER(void);                             
#endif
#if (SCB_0_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                 // IRQ20                  
     extern void SCB_0_INTERRUPT_HANDLER(void);                                      
#endif
#if (IOSS_INTERRUPT_VDD_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)              // IRQ22                  
     extern void IOSS_INTERRUPT_VDD_HANDLER(void);                                   
#endif
#if (IOSS_INTERRUPT_GPIO_DPSLP_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)       // IRQ23                  
     extern void IOSS_INTERRUPT_GPIO_DPSLP_HANDLER(void);                            
#endif
#if (IOSS_INTERRUPTS_GPIO_DPSLP_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ24                  
     extern void IOSS_INTERRUPTS_GPIO_DPSLP_0_HANDLER(void);                         
#endif
#if (IOSS_INTERRUPTS_GPIO_DPSLP_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ25                  
     extern void IOSS_INTERRUPTS_GPIO_DPSLP_1_HANDLER(void);                         
#endif
#if (IOSS_INTERRUPTS_GPIO_DPSLP_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ26                  
     extern void IOSS_INTERRUPTS_GPIO_DPSLP_2_HANDLER(void);                         
#endif
#if (IOSS_INTERRUPTS_GPIO_DPSLP_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ27                  
     extern void IOSS_INTERRUPTS_GPIO_DPSLP_3_HANDLER(void);                         
#endif
#if (IOSS_INTERRUPTS_GPIO_DPSLP_4_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ28                  
     extern void IOSS_INTERRUPTS_GPIO_DPSLP_4_HANDLER(void);                         
#endif
#if (IOSS_INTERRUPTS_GPIO_DPSLP_5_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ29                  
     extern void IOSS_INTERRUPTS_GPIO_DPSLP_5_HANDLER(void);                         
#endif
#if (IOSS_INTERRUPTS_GPIO_DPSLP_6_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ30                  
     extern void IOSS_INTERRUPTS_GPIO_DPSLP_6_HANDLER(void);                         
#endif
#if (IOSS_INTERRUPTS_GPIO_DPSLP_7_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ31                  
     extern void IOSS_INTERRUPTS_GPIO_DPSLP_7_HANDLER(void);                         
#endif
#if (IOSS_INTERRUPTS_GPIO_DPSLP_8_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ32                  
     extern void IOSS_INTERRUPTS_GPIO_DPSLP_8_HANDLER(void);                         
#endif
#if (IOSS_INTERRUPTS_GPIO_DPSLP_9_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ33                  
     extern void IOSS_INTERRUPTS_GPIO_DPSLP_9_HANDLER(void);                         
#endif
#if (IOSS_INTERRUPTS_GPIO_DPSLP_10_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)   // IRQ34                  
     extern void IOSS_INTERRUPTS_GPIO_DPSLP_10_HANDLER(void);                        
#endif
#if (IOSS_INTERRUPTS_GPIO_DPSLP_11_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)   // IRQ35                  
     extern void IOSS_INTERRUPTS_GPIO_DPSLP_11_HANDLER(void);                        
#endif
#if (IOSS_INTERRUPTS_GPIO_DPSLP_12_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)   // IRQ36                  
     extern void IOSS_INTERRUPTS_GPIO_DPSLP_12_HANDLER(void);                        
#endif
#if (IOSS_INTERRUPT_GPIO_ACT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ50                  
     extern void IOSS_INTERRUPT_GPIO_ACT_HANDLER(void);                              
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_13_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ53                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_13_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_14_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ54                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_14_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_15_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ55                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_15_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_16_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ56                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_16_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_17_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ57                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_17_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_18_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ58                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_18_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_19_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ59                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_19_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_20_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ60                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_20_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_21_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ61                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_21_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_22_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ62                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_22_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_23_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ63                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_23_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_24_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ64                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_24_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_25_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ65                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_25_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_26_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ66                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_26_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_27_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ67                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_27_HANDLER(void);                          
#endif
#if (IOSS_INTERRUPTS_GPIO_ACT_28_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ68                  
     extern void IOSS_INTERRUPTS_GPIO_ACT_28_HANDLER(void);                          
#endif
#if (CPUSS_INTERRUPT_CRYPTO_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ70                  
     extern void CPUSS_INTERRUPT_CRYPTO_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPT_FM_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)              // IRQ71                  
     extern void CPUSS_INTERRUPT_FM_HANDLER(void);                                   
#endif
#if (CPUSS_INTERRUPTS_CM7_0_FP_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)       // IRQ72                  
     extern void CPUSS_INTERRUPTS_CM7_0_FP_HANDLER(void);                            
#endif
#if (CPUSS_INTERRUPTS_CM7_1_FP_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)       // IRQ73                  
     extern void CPUSS_INTERRUPTS_CM7_1_FP_HANDLER(void);                            
#endif
#if (CPUSS_INTERRUPTS_CM0_CTI_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)      // IRQ74                  
     extern void CPUSS_INTERRUPTS_CM0_CTI_0_HANDLER(void);                           
#endif
#if (CPUSS_INTERRUPTS_CM0_CTI_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)      // IRQ75                  
     extern void CPUSS_INTERRUPTS_CM0_CTI_1_HANDLER(void);                           
#endif
#if (CPUSS_INTERRUPTS_CM7_0_CTI_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ76                  
     extern void CPUSS_INTERRUPTS_CM7_0_CTI_0_HANDLER(void);                         
#endif
#if (CPUSS_INTERRUPTS_CM7_0_CTI_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ77                  
     extern void CPUSS_INTERRUPTS_CM7_0_CTI_1_HANDLER(void);                         
#endif
#if (CPUSS_INTERRUPTS_CM7_1_CTI_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ78                  
     extern void CPUSS_INTERRUPTS_CM7_1_CTI_0_HANDLER(void);                         
#endif
#if (CPUSS_INTERRUPTS_CM7_1_CTI_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ79                  
     extern void CPUSS_INTERRUPTS_CM7_1_CTI_1_HANDLER(void);                         
#endif
#if (EVTGEN_0_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)              // IRQ80                  
     extern void EVTGEN_0_INTERRUPT_HANDLER(void);                                   
#endif
#if (SMIF_0_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                // IRQ81                  
     extern void SMIF_0_INTERRUPT_HANDLER(void);                                     
#endif
#if (SMIF_1_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                // IRQ82                  
     extern void SMIF_1_INTERRUPT_HANDLER(void);                                     
#endif
#if (ETH_0_INTERRUPT_ETH_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ83                  
     extern void ETH_0_INTERRUPT_ETH_0_HANDLER(void);                                
#endif
#if (ETH_0_INTERRUPT_ETH_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ84                  
     extern void ETH_0_INTERRUPT_ETH_1_HANDLER(void);                                
#endif
#if (ETH_0_INTERRUPT_ETH_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ85                  
     extern void ETH_0_INTERRUPT_ETH_2_HANDLER(void);                                
#endif
#if (CANFD_0_INTERRUPT0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)              // IRQ86                  
     extern void CANFD_0_INTERRUPT0_HANDLER(void);                                   
#endif
#if (CANFD_0_INTERRUPT1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)              // IRQ87                  
     extern void CANFD_0_INTERRUPT1_HANDLER(void);                                   
#endif
#if (CANFD_1_INTERRUPT0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)              // IRQ88                  
     extern void CANFD_1_INTERRUPT0_HANDLER(void);                                   
#endif
#if (CANFD_1_INTERRUPT1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)              // IRQ89                  
     extern void CANFD_1_INTERRUPT1_HANDLER(void);                                   
#endif
#if (CANFD_0_INTERRUPTS0_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ90                  
     extern void CANFD_0_INTERRUPTS0_0_HANDLER(void);                                
#endif
#if (CANFD_0_INTERRUPTS0_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ91                  
     extern void CANFD_0_INTERRUPTS0_1_HANDLER(void);                                
#endif
#if (CANFD_0_INTERRUPTS1_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ96                  
     extern void CANFD_0_INTERRUPTS1_0_HANDLER(void);                                
#endif
#if (CANFD_0_INTERRUPTS1_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ97                  
     extern void CANFD_0_INTERRUPTS1_1_HANDLER(void);                                
#endif
#if (CANFD_1_INTERRUPTS0_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ102                 
     extern void CANFD_1_INTERRUPTS0_0_HANDLER(void);                                
#endif
#if (CANFD_1_INTERRUPTS0_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ103                 
     extern void CANFD_1_INTERRUPTS0_1_HANDLER(void);                                
#endif
#if (CANFD_1_INTERRUPTS1_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ108                 
     extern void CANFD_1_INTERRUPTS1_0_HANDLER(void);                                
#endif
#if (CANFD_1_INTERRUPTS1_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ109                 
     extern void CANFD_1_INTERRUPTS1_1_HANDLER(void);                                
#endif
#if (LIN_0_INTERRUPTS_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)              // IRQ114                 
     extern void LIN_0_INTERRUPTS_0_HANDLER(void);                                   
#endif
#if (LIN_0_INTERRUPTS_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)              // IRQ115                 
     extern void LIN_0_INTERRUPTS_1_HANDLER(void);                                   
#endif
#if (CXPI_0_INTERRUPTS_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)             // IRQ130                 
     extern void CXPI_0_INTERRUPTS_0_HANDLER(void);                                  
#endif
#if (CXPI_0_INTERRUPTS_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)             // IRQ131                 
     extern void CXPI_0_INTERRUPTS_1_HANDLER(void);                                  
#endif
#if (SCB_1_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                 // IRQ135                 
     extern void SCB_1_INTERRUPT_HANDLER(void);                                      
#endif
#if (SCB_2_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                 // IRQ136                 
     extern void SCB_2_INTERRUPT_HANDLER(void);                                      
#endif
#if (SCB_3_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                 // IRQ137                 
     extern void SCB_3_INTERRUPT_HANDLER(void);                                      
#endif
#if (SCB_4_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                 // IRQ138                 
     extern void SCB_4_INTERRUPT_HANDLER(void);                                      
#endif
#if (SCB_5_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                 // IRQ139                 
     extern void SCB_5_INTERRUPT_HANDLER(void);                                      
#endif
#if (SCB_6_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                 // IRQ140                 
     extern void SCB_6_INTERRUPT_HANDLER(void);                                      
#endif
#if (SCB_7_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                 // IRQ141                 
     extern void SCB_7_INTERRUPT_HANDLER(void);                                      
#endif
#if (SCB_8_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                 // IRQ142                 
     extern void SCB_8_INTERRUPT_HANDLER(void);                                      
#endif
#if (SCB_9_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                 // IRQ143                 
     extern void SCB_9_INTERRUPT_HANDLER(void);                                      
#endif
#if (SCB_10_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                // IRQ144                 
     extern void SCB_10_INTERRUPT_HANDLER(void);                                     
#endif
#if (SCB_11_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                // IRQ145                 
     extern void SCB_11_INTERRUPT_HANDLER(void);                                     
#endif
#if (VIDEOSS_0_INTERRUPT_GFX2D_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)       // IRQ150                 
     extern void VIDEOSS_0_INTERRUPT_GFX2D_HANDLER(void);                            
#endif
#if (VIDEOSS_0_INTERRUPT_MIPICSI_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)     // IRQ151                 
     extern void VIDEOSS_0_INTERRUPT_MIPICSI_HANDLER(void);                          
#endif
#if (VIDEOSS_0_INTERRUPT_VIDEOIO0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ152                 
     extern void VIDEOSS_0_INTERRUPT_VIDEOIO0_HANDLER(void);                         
#endif
#if (VIDEOSS_0_INTERRUPT_VIDEOIO1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)    // IRQ153                 
     extern void VIDEOSS_0_INTERRUPT_VIDEOIO1_HANDLER(void);                         
#endif
#if (VIDEOSS_0_INTERRUPT_VIDEOIO0_SAFETY_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER) // IRQ154                 
     extern void VIDEOSS_0_INTERRUPT_VIDEOIO0_SAFETY_HANDLER(void);                  
#endif
#if (VIDEOSS_0_INTERRUPT_VIDEOIO1_SAFETY_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER) // IRQ155                 
     extern void VIDEOSS_0_INTERRUPT_VIDEOIO1_SAFETY_HANDLER(void);                  
#endif
#if (PASS_0_INTERRUPTS_SAR_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ160                 
     extern void PASS_0_INTERRUPTS_SAR_0_HANDLER(void);                              
#endif
#if (PASS_0_INTERRUPTS_SAR_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ161                 
     extern void PASS_0_INTERRUPTS_SAR_1_HANDLER(void);                              
#endif
#if (PASS_0_INTERRUPTS_SAR_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ162                 
     extern void PASS_0_INTERRUPTS_SAR_2_HANDLER(void);                              
#endif
#if (PASS_0_INTERRUPTS_SAR_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ163                 
     extern void PASS_0_INTERRUPTS_SAR_3_HANDLER(void);                              
#endif
#if (PASS_0_INTERRUPTS_SAR_4_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ164                 
     extern void PASS_0_INTERRUPTS_SAR_4_HANDLER(void);                              
#endif
#if (PASS_0_INTERRUPTS_SAR_5_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ165                 
     extern void PASS_0_INTERRUPTS_SAR_5_HANDLER(void);                              
#endif
#if (PASS_0_INTERRUPTS_SAR_6_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ166                 
     extern void PASS_0_INTERRUPTS_SAR_6_HANDLER(void);                              
#endif
#if (PASS_0_INTERRUPTS_SAR_7_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ167                 
     extern void PASS_0_INTERRUPTS_SAR_7_HANDLER(void);                              
#endif
#if (PASS_0_INTERRUPTS_SAR_8_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ168                 
     extern void PASS_0_INTERRUPTS_SAR_8_HANDLER(void);                              
#endif
#if (PASS_0_INTERRUPTS_SAR_9_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ169                 
     extern void PASS_0_INTERRUPTS_SAR_9_HANDLER(void);                              
#endif
#if (PASS_0_INTERRUPTS_SAR_10_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ170                 
     extern void PASS_0_INTERRUPTS_SAR_10_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_11_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ171                 
     extern void PASS_0_INTERRUPTS_SAR_11_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_12_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ172                 
     extern void PASS_0_INTERRUPTS_SAR_12_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_13_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ173                 
     extern void PASS_0_INTERRUPTS_SAR_13_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_14_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ174                 
     extern void PASS_0_INTERRUPTS_SAR_14_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_15_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ175                 
     extern void PASS_0_INTERRUPTS_SAR_15_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_16_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ176                 
     extern void PASS_0_INTERRUPTS_SAR_16_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_17_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ177                 
     extern void PASS_0_INTERRUPTS_SAR_17_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_18_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ178                 
     extern void PASS_0_INTERRUPTS_SAR_18_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_19_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ179                 
     extern void PASS_0_INTERRUPTS_SAR_19_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_20_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ180                 
     extern void PASS_0_INTERRUPTS_SAR_20_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_21_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ181                 
     extern void PASS_0_INTERRUPTS_SAR_21_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_22_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ182                 
     extern void PASS_0_INTERRUPTS_SAR_22_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_23_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ183                 
     extern void PASS_0_INTERRUPTS_SAR_23_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_24_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ184                 
     extern void PASS_0_INTERRUPTS_SAR_24_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_25_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ185                 
     extern void PASS_0_INTERRUPTS_SAR_25_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_26_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ186                 
     extern void PASS_0_INTERRUPTS_SAR_26_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_27_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ187                 
     extern void PASS_0_INTERRUPTS_SAR_27_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_28_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ188                 
     extern void PASS_0_INTERRUPTS_SAR_28_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_29_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ189                 
     extern void PASS_0_INTERRUPTS_SAR_29_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_30_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ190                 
     extern void PASS_0_INTERRUPTS_SAR_30_HANDLER(void);                             
#endif
#if (PASS_0_INTERRUPTS_SAR_31_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ191                 
     extern void PASS_0_INTERRUPTS_SAR_31_HANDLER(void);                             
#endif
#if (CPUSS_INTERRUPTS_DMAC_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ288                 
     extern void CPUSS_INTERRUPTS_DMAC_0_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DMAC_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ289                 
     extern void CPUSS_INTERRUPTS_DMAC_1_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DMAC_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ290                 
     extern void CPUSS_INTERRUPTS_DMAC_2_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DMAC_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ291                 
     extern void CPUSS_INTERRUPTS_DMAC_3_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DMAC_4_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ292                 
     extern void CPUSS_INTERRUPTS_DMAC_4_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DMAC_5_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ293                 
     extern void CPUSS_INTERRUPTS_DMAC_5_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DMAC_6_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ294                 
     extern void CPUSS_INTERRUPTS_DMAC_6_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DMAC_7_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ295                 
     extern void CPUSS_INTERRUPTS_DMAC_7_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ296                 
     extern void CPUSS_INTERRUPTS_DW0_0_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW0_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ297                 
     extern void CPUSS_INTERRUPTS_DW0_1_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW0_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ298                 
     extern void CPUSS_INTERRUPTS_DW0_2_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW0_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ299                 
     extern void CPUSS_INTERRUPTS_DW0_3_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW0_4_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ300                 
     extern void CPUSS_INTERRUPTS_DW0_4_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW0_5_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ301                 
     extern void CPUSS_INTERRUPTS_DW0_5_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW0_6_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ302                 
     extern void CPUSS_INTERRUPTS_DW0_6_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW0_7_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ303                 
     extern void CPUSS_INTERRUPTS_DW0_7_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW0_8_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ304                 
     extern void CPUSS_INTERRUPTS_DW0_8_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW0_9_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ305                 
     extern void CPUSS_INTERRUPTS_DW0_9_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW0_10_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ306                 
     extern void CPUSS_INTERRUPTS_DW0_10_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_11_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ307                 
     extern void CPUSS_INTERRUPTS_DW0_11_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_12_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ308                 
     extern void CPUSS_INTERRUPTS_DW0_12_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_13_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ309                 
     extern void CPUSS_INTERRUPTS_DW0_13_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_14_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ310                 
     extern void CPUSS_INTERRUPTS_DW0_14_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_15_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ311                 
     extern void CPUSS_INTERRUPTS_DW0_15_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_16_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ312                 
     extern void CPUSS_INTERRUPTS_DW0_16_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_17_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ313                 
     extern void CPUSS_INTERRUPTS_DW0_17_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_18_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ314                 
     extern void CPUSS_INTERRUPTS_DW0_18_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_19_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ315                 
     extern void CPUSS_INTERRUPTS_DW0_19_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_20_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ316                 
     extern void CPUSS_INTERRUPTS_DW0_20_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_21_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ317                 
     extern void CPUSS_INTERRUPTS_DW0_21_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_22_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ318                 
     extern void CPUSS_INTERRUPTS_DW0_22_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_23_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ319                 
     extern void CPUSS_INTERRUPTS_DW0_23_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_24_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ320                 
     extern void CPUSS_INTERRUPTS_DW0_24_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_25_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ321                 
     extern void CPUSS_INTERRUPTS_DW0_25_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_26_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ322                 
     extern void CPUSS_INTERRUPTS_DW0_26_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_27_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ323                 
     extern void CPUSS_INTERRUPTS_DW0_27_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_28_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ324                 
     extern void CPUSS_INTERRUPTS_DW0_28_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_29_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ325                 
     extern void CPUSS_INTERRUPTS_DW0_29_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_30_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ326                 
     extern void CPUSS_INTERRUPTS_DW0_30_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_31_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ327                 
     extern void CPUSS_INTERRUPTS_DW0_31_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_32_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ328                 
     extern void CPUSS_INTERRUPTS_DW0_32_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_33_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ329                 
     extern void CPUSS_INTERRUPTS_DW0_33_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_34_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ330                 
     extern void CPUSS_INTERRUPTS_DW0_34_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_35_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ331                 
     extern void CPUSS_INTERRUPTS_DW0_35_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_36_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ332                 
     extern void CPUSS_INTERRUPTS_DW0_36_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_37_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ333                 
     extern void CPUSS_INTERRUPTS_DW0_37_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_38_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ334                 
     extern void CPUSS_INTERRUPTS_DW0_38_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_39_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ335                 
     extern void CPUSS_INTERRUPTS_DW0_39_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_40_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ336                 
     extern void CPUSS_INTERRUPTS_DW0_40_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_41_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ337                 
     extern void CPUSS_INTERRUPTS_DW0_41_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_42_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ338                 
     extern void CPUSS_INTERRUPTS_DW0_42_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_43_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ339                 
     extern void CPUSS_INTERRUPTS_DW0_43_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_44_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ340                 
     extern void CPUSS_INTERRUPTS_DW0_44_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_45_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ341                 
     extern void CPUSS_INTERRUPTS_DW0_45_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_46_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ342                 
     extern void CPUSS_INTERRUPTS_DW0_46_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_47_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ343                 
     extern void CPUSS_INTERRUPTS_DW0_47_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_48_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ344                 
     extern void CPUSS_INTERRUPTS_DW0_48_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_49_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ345                 
     extern void CPUSS_INTERRUPTS_DW0_49_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_50_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ346                 
     extern void CPUSS_INTERRUPTS_DW0_50_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_51_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ347                 
     extern void CPUSS_INTERRUPTS_DW0_51_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_52_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ348                 
     extern void CPUSS_INTERRUPTS_DW0_52_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_53_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ349                 
     extern void CPUSS_INTERRUPTS_DW0_53_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_54_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ350                 
     extern void CPUSS_INTERRUPTS_DW0_54_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_55_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ351                 
     extern void CPUSS_INTERRUPTS_DW0_55_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_56_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ352                 
     extern void CPUSS_INTERRUPTS_DW0_56_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_57_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ353                 
     extern void CPUSS_INTERRUPTS_DW0_57_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_58_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ354                 
     extern void CPUSS_INTERRUPTS_DW0_58_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_59_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ355                 
     extern void CPUSS_INTERRUPTS_DW0_59_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_60_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ356                 
     extern void CPUSS_INTERRUPTS_DW0_60_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_61_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ357                 
     extern void CPUSS_INTERRUPTS_DW0_61_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_62_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ358                 
     extern void CPUSS_INTERRUPTS_DW0_62_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_63_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ359                 
     extern void CPUSS_INTERRUPTS_DW0_63_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_64_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ360                 
     extern void CPUSS_INTERRUPTS_DW0_64_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_65_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ361                 
     extern void CPUSS_INTERRUPTS_DW0_65_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_66_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ362                 
     extern void CPUSS_INTERRUPTS_DW0_66_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_67_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ363                 
     extern void CPUSS_INTERRUPTS_DW0_67_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_68_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ364                 
     extern void CPUSS_INTERRUPTS_DW0_68_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_69_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ365                 
     extern void CPUSS_INTERRUPTS_DW0_69_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_70_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ366                 
     extern void CPUSS_INTERRUPTS_DW0_70_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_71_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ367                 
     extern void CPUSS_INTERRUPTS_DW0_71_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_72_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ368                 
     extern void CPUSS_INTERRUPTS_DW0_72_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_73_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ369                 
     extern void CPUSS_INTERRUPTS_DW0_73_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_74_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ370                 
     extern void CPUSS_INTERRUPTS_DW0_74_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW0_75_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ371                 
     extern void CPUSS_INTERRUPTS_DW0_75_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ424                 
     extern void CPUSS_INTERRUPTS_DW1_0_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW1_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ425                 
     extern void CPUSS_INTERRUPTS_DW1_1_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW1_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ426                 
     extern void CPUSS_INTERRUPTS_DW1_2_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW1_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ427                 
     extern void CPUSS_INTERRUPTS_DW1_3_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW1_4_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ428                 
     extern void CPUSS_INTERRUPTS_DW1_4_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW1_5_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ429                 
     extern void CPUSS_INTERRUPTS_DW1_5_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW1_6_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ430                 
     extern void CPUSS_INTERRUPTS_DW1_6_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW1_7_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ431                 
     extern void CPUSS_INTERRUPTS_DW1_7_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW1_8_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ432                 
     extern void CPUSS_INTERRUPTS_DW1_8_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW1_9_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ433                 
     extern void CPUSS_INTERRUPTS_DW1_9_HANDLER(void);                               
#endif
#if (CPUSS_INTERRUPTS_DW1_10_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ434                 
     extern void CPUSS_INTERRUPTS_DW1_10_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_11_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ435                 
     extern void CPUSS_INTERRUPTS_DW1_11_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_12_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ436                 
     extern void CPUSS_INTERRUPTS_DW1_12_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_13_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ437                 
     extern void CPUSS_INTERRUPTS_DW1_13_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_14_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ438                 
     extern void CPUSS_INTERRUPTS_DW1_14_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_15_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ439                 
     extern void CPUSS_INTERRUPTS_DW1_15_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_16_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ440                 
     extern void CPUSS_INTERRUPTS_DW1_16_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_17_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ441                 
     extern void CPUSS_INTERRUPTS_DW1_17_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_18_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ442                 
     extern void CPUSS_INTERRUPTS_DW1_18_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_19_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ443                 
     extern void CPUSS_INTERRUPTS_DW1_19_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_20_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ444                 
     extern void CPUSS_INTERRUPTS_DW1_20_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_21_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ445                 
     extern void CPUSS_INTERRUPTS_DW1_21_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_22_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ446                 
     extern void CPUSS_INTERRUPTS_DW1_22_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_23_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ447                 
     extern void CPUSS_INTERRUPTS_DW1_23_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_24_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ448                 
     extern void CPUSS_INTERRUPTS_DW1_24_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_25_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ449                 
     extern void CPUSS_INTERRUPTS_DW1_25_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_26_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ450                 
     extern void CPUSS_INTERRUPTS_DW1_26_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_27_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ451                 
     extern void CPUSS_INTERRUPTS_DW1_27_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_28_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ452                 
     extern void CPUSS_INTERRUPTS_DW1_28_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_29_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ453                 
     extern void CPUSS_INTERRUPTS_DW1_29_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_30_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ454                 
     extern void CPUSS_INTERRUPTS_DW1_30_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_31_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ455                 
     extern void CPUSS_INTERRUPTS_DW1_31_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_32_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ456                 
     extern void CPUSS_INTERRUPTS_DW1_32_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_33_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ457                 
     extern void CPUSS_INTERRUPTS_DW1_33_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_34_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ458                 
     extern void CPUSS_INTERRUPTS_DW1_34_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_35_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ459                 
     extern void CPUSS_INTERRUPTS_DW1_35_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_36_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ460                 
     extern void CPUSS_INTERRUPTS_DW1_36_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_37_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ461                 
     extern void CPUSS_INTERRUPTS_DW1_37_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_38_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ462                 
     extern void CPUSS_INTERRUPTS_DW1_38_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_39_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ463                 
     extern void CPUSS_INTERRUPTS_DW1_39_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_40_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ464                 
     extern void CPUSS_INTERRUPTS_DW1_40_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_41_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ465                 
     extern void CPUSS_INTERRUPTS_DW1_41_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_42_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ466                 
     extern void CPUSS_INTERRUPTS_DW1_42_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_43_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ467                 
     extern void CPUSS_INTERRUPTS_DW1_43_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_44_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ468                 
     extern void CPUSS_INTERRUPTS_DW1_44_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_45_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ469                 
     extern void CPUSS_INTERRUPTS_DW1_45_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_46_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ470                 
     extern void CPUSS_INTERRUPTS_DW1_46_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_47_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ471                 
     extern void CPUSS_INTERRUPTS_DW1_47_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_48_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ472                 
     extern void CPUSS_INTERRUPTS_DW1_48_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_49_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ473                 
     extern void CPUSS_INTERRUPTS_DW1_49_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_50_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ474                 
     extern void CPUSS_INTERRUPTS_DW1_50_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_51_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ475                 
     extern void CPUSS_INTERRUPTS_DW1_51_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_52_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ476                 
     extern void CPUSS_INTERRUPTS_DW1_52_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_53_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ477                 
     extern void CPUSS_INTERRUPTS_DW1_53_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_54_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ478                 
     extern void CPUSS_INTERRUPTS_DW1_54_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_55_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ479                 
     extern void CPUSS_INTERRUPTS_DW1_55_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_56_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ480                 
     extern void CPUSS_INTERRUPTS_DW1_56_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_57_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ481                 
     extern void CPUSS_INTERRUPTS_DW1_57_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_58_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ482                 
     extern void CPUSS_INTERRUPTS_DW1_58_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_59_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ483                 
     extern void CPUSS_INTERRUPTS_DW1_59_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_60_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ484                 
     extern void CPUSS_INTERRUPTS_DW1_60_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_61_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ485                 
     extern void CPUSS_INTERRUPTS_DW1_61_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_62_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ486                 
     extern void CPUSS_INTERRUPTS_DW1_62_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_63_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ487                 
     extern void CPUSS_INTERRUPTS_DW1_63_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_64_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ488                 
     extern void CPUSS_INTERRUPTS_DW1_64_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_65_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ489                 
     extern void CPUSS_INTERRUPTS_DW1_65_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_66_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ490                 
     extern void CPUSS_INTERRUPTS_DW1_66_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_67_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ491                 
     extern void CPUSS_INTERRUPTS_DW1_67_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_68_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ492                 
     extern void CPUSS_INTERRUPTS_DW1_68_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_69_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ493                 
     extern void CPUSS_INTERRUPTS_DW1_69_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_70_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ494                 
     extern void CPUSS_INTERRUPTS_DW1_70_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_71_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ495                 
     extern void CPUSS_INTERRUPTS_DW1_71_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_72_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ496                 
     extern void CPUSS_INTERRUPTS_DW1_72_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_73_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ497                 
     extern void CPUSS_INTERRUPTS_DW1_73_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_74_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ498                 
     extern void CPUSS_INTERRUPTS_DW1_74_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_75_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ499                 
     extern void CPUSS_INTERRUPTS_DW1_75_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_76_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ500                 
     extern void CPUSS_INTERRUPTS_DW1_76_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_77_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ501                 
     extern void CPUSS_INTERRUPTS_DW1_77_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_78_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ502                 
     extern void CPUSS_INTERRUPTS_DW1_78_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_79_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ503                 
     extern void CPUSS_INTERRUPTS_DW1_79_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_80_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ504                 
     extern void CPUSS_INTERRUPTS_DW1_80_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_81_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ505                 
     extern void CPUSS_INTERRUPTS_DW1_81_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_82_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ506                 
     extern void CPUSS_INTERRUPTS_DW1_82_HANDLER(void);                              
#endif
#if (CPUSS_INTERRUPTS_DW1_83_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)         // IRQ507                 
     extern void CPUSS_INTERRUPTS_DW1_83_HANDLER(void);                              
#endif
#if (TCPWM_0_INTERRUPTS_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)            // IRQ552                 
     extern void TCPWM_0_INTERRUPTS_0_HANDLER(void);                                 
#endif
#if (TCPWM_0_INTERRUPTS_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)            // IRQ553                 
     extern void TCPWM_0_INTERRUPTS_1_HANDLER(void);                                 
#endif
#if (TCPWM_0_INTERRUPTS_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)            // IRQ554                 
     extern void TCPWM_0_INTERRUPTS_2_HANDLER(void);                                 
#endif
#if (TCPWM_0_INTERRUPTS_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)            // IRQ555                 
     extern void TCPWM_0_INTERRUPTS_3_HANDLER(void);                                 
#endif
#if (TCPWM_0_INTERRUPTS_4_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)            // IRQ556                 
     extern void TCPWM_0_INTERRUPTS_4_HANDLER(void);                                 
#endif
#if (TCPWM_0_INTERRUPTS_5_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)            // IRQ557                 
     extern void TCPWM_0_INTERRUPTS_5_HANDLER(void);                                 
#endif
#if (TCPWM_0_INTERRUPTS_6_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)            // IRQ558                 
     extern void TCPWM_0_INTERRUPTS_6_HANDLER(void);                                 
#endif
#if (TCPWM_0_INTERRUPTS_7_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)            // IRQ559                 
     extern void TCPWM_0_INTERRUPTS_7_HANDLER(void);                                 
#endif
#if (TCPWM_0_INTERRUPTS_8_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)            // IRQ560                 
     extern void TCPWM_0_INTERRUPTS_8_HANDLER(void);                                 
#endif
#if (TCPWM_0_INTERRUPTS_9_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)            // IRQ561                 
     extern void TCPWM_0_INTERRUPTS_9_HANDLER(void);                                 
#endif
#if (TCPWM_0_INTERRUPTS_10_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ562                 
     extern void TCPWM_0_INTERRUPTS_10_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_11_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ563                 
     extern void TCPWM_0_INTERRUPTS_11_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_12_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ564                 
     extern void TCPWM_0_INTERRUPTS_12_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_13_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ565                 
     extern void TCPWM_0_INTERRUPTS_13_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_14_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ566                 
     extern void TCPWM_0_INTERRUPTS_14_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_15_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ567                 
     extern void TCPWM_0_INTERRUPTS_15_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_16_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ568                 
     extern void TCPWM_0_INTERRUPTS_16_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_17_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ569                 
     extern void TCPWM_0_INTERRUPTS_17_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_18_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ570                 
     extern void TCPWM_0_INTERRUPTS_18_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_19_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ571                 
     extern void TCPWM_0_INTERRUPTS_19_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_20_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ572                 
     extern void TCPWM_0_INTERRUPTS_20_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_21_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ573                 
     extern void TCPWM_0_INTERRUPTS_21_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_22_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ574                 
     extern void TCPWM_0_INTERRUPTS_22_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_23_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ575                 
     extern void TCPWM_0_INTERRUPTS_23_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_24_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ576                 
     extern void TCPWM_0_INTERRUPTS_24_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_25_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ577                 
     extern void TCPWM_0_INTERRUPTS_25_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_26_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ578                 
     extern void TCPWM_0_INTERRUPTS_26_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_27_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ579                 
     extern void TCPWM_0_INTERRUPTS_27_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_28_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ580                 
     extern void TCPWM_0_INTERRUPTS_28_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_29_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ581                 
     extern void TCPWM_0_INTERRUPTS_29_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_30_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ582                 
     extern void TCPWM_0_INTERRUPTS_30_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_31_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ583                 
     extern void TCPWM_0_INTERRUPTS_31_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_32_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ584                 
     extern void TCPWM_0_INTERRUPTS_32_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_33_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ585                 
     extern void TCPWM_0_INTERRUPTS_33_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_34_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ586                 
     extern void TCPWM_0_INTERRUPTS_34_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_35_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ587                 
     extern void TCPWM_0_INTERRUPTS_35_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_36_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ588                 
     extern void TCPWM_0_INTERRUPTS_36_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_37_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ589                 
     extern void TCPWM_0_INTERRUPTS_37_HANDLER(void);                                
#endif
#if (TCPWM_0_INTERRUPTS_256_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ616                 
     extern void TCPWM_0_INTERRUPTS_256_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_257_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ617                 
     extern void TCPWM_0_INTERRUPTS_257_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_258_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ618                 
     extern void TCPWM_0_INTERRUPTS_258_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_259_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ619                 
     extern void TCPWM_0_INTERRUPTS_259_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_260_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ620                 
     extern void TCPWM_0_INTERRUPTS_260_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_261_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ621                 
     extern void TCPWM_0_INTERRUPTS_261_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_262_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ622                 
     extern void TCPWM_0_INTERRUPTS_262_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_263_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ623                 
     extern void TCPWM_0_INTERRUPTS_263_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_264_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ624                 
     extern void TCPWM_0_INTERRUPTS_264_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_265_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ625                 
     extern void TCPWM_0_INTERRUPTS_265_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_266_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ626                 
     extern void TCPWM_0_INTERRUPTS_266_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_267_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ627                 
     extern void TCPWM_0_INTERRUPTS_267_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_512_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ680                 
     extern void TCPWM_0_INTERRUPTS_512_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_513_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ681                 
     extern void TCPWM_0_INTERRUPTS_513_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_514_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ682                 
     extern void TCPWM_0_INTERRUPTS_514_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_515_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ683                 
     extern void TCPWM_0_INTERRUPTS_515_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_516_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ684                 
     extern void TCPWM_0_INTERRUPTS_516_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_517_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ685                 
     extern void TCPWM_0_INTERRUPTS_517_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_518_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ686                 
     extern void TCPWM_0_INTERRUPTS_518_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_519_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ687                 
     extern void TCPWM_0_INTERRUPTS_519_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_520_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ688                 
     extern void TCPWM_0_INTERRUPTS_520_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_521_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ689                 
     extern void TCPWM_0_INTERRUPTS_521_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_522_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ690                 
     extern void TCPWM_0_INTERRUPTS_522_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_523_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ691                 
     extern void TCPWM_0_INTERRUPTS_523_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_524_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ692                 
     extern void TCPWM_0_INTERRUPTS_524_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_525_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ693                 
     extern void TCPWM_0_INTERRUPTS_525_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_526_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ694                 
     extern void TCPWM_0_INTERRUPTS_526_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_527_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ695                 
     extern void TCPWM_0_INTERRUPTS_527_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_528_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ696                 
     extern void TCPWM_0_INTERRUPTS_528_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_529_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ697                 
     extern void TCPWM_0_INTERRUPTS_529_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_530_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ698                 
     extern void TCPWM_0_INTERRUPTS_530_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_531_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ699                 
     extern void TCPWM_0_INTERRUPTS_531_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_532_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ700                 
     extern void TCPWM_0_INTERRUPTS_532_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_533_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ701                 
     extern void TCPWM_0_INTERRUPTS_533_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_534_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ702                 
     extern void TCPWM_0_INTERRUPTS_534_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_535_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ703                 
     extern void TCPWM_0_INTERRUPTS_535_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_536_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ704                 
     extern void TCPWM_0_INTERRUPTS_536_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_537_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ705                 
     extern void TCPWM_0_INTERRUPTS_537_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_538_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ706                 
     extern void TCPWM_0_INTERRUPTS_538_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_539_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ707                 
     extern void TCPWM_0_INTERRUPTS_539_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_540_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ708                 
     extern void TCPWM_0_INTERRUPTS_540_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_541_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ709                 
     extern void TCPWM_0_INTERRUPTS_541_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_542_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ710                 
     extern void TCPWM_0_INTERRUPTS_542_HANDLER(void);                               
#endif
#if (TCPWM_0_INTERRUPTS_543_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)          // IRQ711                 
     extern void TCPWM_0_INTERRUPTS_543_HANDLER(void);                               
#endif
#if (I2S_0_INTERRUPTS_TX_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ744                 
     extern void I2S_0_INTERRUPTS_TX_0_HANDLER(void);                                
#endif
#if (I2S_0_INTERRUPTS_RX_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ745                 
     extern void I2S_0_INTERRUPTS_RX_0_HANDLER(void);                                
#endif
#if (I2S_0_INTERRUPTS_TX_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ746                 
     extern void I2S_0_INTERRUPTS_TX_1_HANDLER(void);                                
#endif
#if (I2S_0_INTERRUPTS_RX_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ747                 
     extern void I2S_0_INTERRUPTS_RX_1_HANDLER(void);                                
#endif
#if (I2S_0_INTERRUPTS_TX_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ748                 
     extern void I2S_0_INTERRUPTS_TX_2_HANDLER(void);                                
#endif
#if (I2S_0_INTERRUPTS_RX_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ749                 
     extern void I2S_0_INTERRUPTS_RX_2_HANDLER(void);                                
#endif
#if (I2S_0_INTERRUPTS_TX_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ750                 
     extern void I2S_0_INTERRUPTS_TX_3_HANDLER(void);                                
#endif
#if (I2S_0_INTERRUPTS_RX_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ751                 
     extern void I2S_0_INTERRUPTS_RX_3_HANDLER(void);                                
#endif
#if (TDM_0_INTERRUPTS_TX_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ752                 
     extern void TDM_0_INTERRUPTS_TX_0_HANDLER(void);                                
#endif
#if (TDM_0_INTERRUPTS_RX_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ753                 
     extern void TDM_0_INTERRUPTS_RX_0_HANDLER(void);                                
#endif
#if (TDM_0_INTERRUPTS_TX_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ754                 
     extern void TDM_0_INTERRUPTS_TX_1_HANDLER(void);                                
#endif
#if (TDM_0_INTERRUPTS_RX_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ755                 
     extern void TDM_0_INTERRUPTS_RX_1_HANDLER(void);                                
#endif
#if (TDM_0_INTERRUPTS_TX_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ756                 
     extern void TDM_0_INTERRUPTS_TX_2_HANDLER(void);                                
#endif
#if (TDM_0_INTERRUPTS_RX_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ757                 
     extern void TDM_0_INTERRUPTS_RX_2_HANDLER(void);                                
#endif
#if (TDM_0_INTERRUPTS_TX_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ758                 
     extern void TDM_0_INTERRUPTS_TX_3_HANDLER(void);                                
#endif
#if (TDM_0_INTERRUPTS_RX_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ759                 
     extern void TDM_0_INTERRUPTS_RX_3_HANDLER(void);                                
#endif
#if (SG_0_INTERRUPTS_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)               // IRQ760                 
     extern void SG_0_INTERRUPTS_0_HANDLER(void);                                    
#endif
#if (SG_0_INTERRUPTS_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)               // IRQ761                 
     extern void SG_0_INTERRUPTS_1_HANDLER(void);                                    
#endif
#if (SG_0_INTERRUPTS_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)               // IRQ762                 
     extern void SG_0_INTERRUPTS_2_HANDLER(void);                                    
#endif
#if (SG_0_INTERRUPTS_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)               // IRQ763                 
     extern void SG_0_INTERRUPTS_3_HANDLER(void);                                    
#endif
#if (SG_0_INTERRUPTS_4_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)               // IRQ764                 
     extern void SG_0_INTERRUPTS_4_HANDLER(void);                                    
#endif
#if (PWM_0_INTERRUPTS_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)              // IRQ768                 
     extern void PWM_0_INTERRUPTS_0_HANDLER(void);                                   
#endif
#if (PWM_0_INTERRUPTS_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)              // IRQ769                 
     extern void PWM_0_INTERRUPTS_1_HANDLER(void);                                   
#endif
#if (DAC_0_INTERRUPT_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)                 // IRQ776                 
     extern void DAC_0_INTERRUPT_HANDLER(void);                                      
#endif
#if (MIXER_0_INTERRUPT_DST_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ780                 
     extern void MIXER_0_INTERRUPT_DST_HANDLER(void);                                
#endif
#if (MIXER_0_INTERRUPTS_SRC_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ781                 
     extern void MIXER_0_INTERRUPTS_SRC_0_HANDLER(void);                             
#endif
#if (MIXER_0_INTERRUPTS_SRC_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ782                 
     extern void MIXER_0_INTERRUPTS_SRC_1_HANDLER(void);                             
#endif
#if (MIXER_0_INTERRUPTS_SRC_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ783                 
     extern void MIXER_0_INTERRUPTS_SRC_2_HANDLER(void);                             
#endif
#if (MIXER_0_INTERRUPTS_SRC_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ784                 
     extern void MIXER_0_INTERRUPTS_SRC_3_HANDLER(void);                             
#endif
#if (MIXER_0_INTERRUPTS_SRC_4_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ785                 
     extern void MIXER_0_INTERRUPTS_SRC_4_HANDLER(void);                             
#endif
#if (MIXER_1_INTERRUPT_DST_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)           // IRQ789                 
     extern void MIXER_1_INTERRUPT_DST_HANDLER(void);                                
#endif
#if (MIXER_1_INTERRUPTS_SRC_0_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ790                 
     extern void MIXER_1_INTERRUPTS_SRC_0_HANDLER(void);                             
#endif
#if (MIXER_1_INTERRUPTS_SRC_1_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ791                 
     extern void MIXER_1_INTERRUPTS_SRC_1_HANDLER(void);                             
#endif
#if (MIXER_1_INTERRUPTS_SRC_2_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ792                 
     extern void MIXER_1_INTERRUPTS_SRC_2_HANDLER(void);                             
#endif
#if (MIXER_1_INTERRUPTS_SRC_3_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ793                 
     extern void MIXER_1_INTERRUPTS_SRC_3_HANDLER(void);                             
#endif
#if (MIXER_1_INTERRUPTS_SRC_4_HANDLER !=  INTERRUPTS_IRQ_DEFAULT_HANDLER)        // IRQ794                 
     extern void MIXER_1_INTERRUPTS_SRC_4_HANDLER(void);                             
#endif

/* re-enable warning "zero used for undefined preprocessing identifier" */
#ifdef __ghs__
    #pragma ghs endnowarning
#endif
#ifdef __ICCARM__
    #pragma diag_default=Pe193
#endif

#endif /* _CY_INTERRUPT_MAP_CM7_1_H_ */


/* [] END OF FILE */
