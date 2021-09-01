/***************************************************************************//**
* \file cy_interrupt_map.c
*
* \brief
* Provides the table with system interrupt handlers
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

#include "syslib/cy_syslib.h"
#include "sysint/cy_sysint.h"


#if CY_CPU_CORTEX_M0P
    #include "cy_interrupt_map_cm0plus.h"
#else
    #if defined (CY_CORE_CM7_0)
        #include "cy_interrupt_map_cm7_0.h"
    #elif defined (CY_CORE_CM7_1)
        #include "cy_interrupt_map_cm7_1.h"
    #else
        #error "No core selected"
    #endif
#endif

extern void Cy_DefaultUserHandler(void);


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//! DO NOT EDIT THIS TABLE DIRECTLY BUT USE THE CORE SPECIFIC HEADER FILE (cy_interrupt_map_<core>.h !
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

/** Table of all user specific IRQ vectors */

#ifndef CY_LINK_SYSTEM_IRQ_TABLE_TO_RAM
const
#endif
       cy_systemIntr_Handler Cy_SystemIrqUserTable[] =
{
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_IPC_0_HANDLER,               // IRQ0                   
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_IPC_1_HANDLER,               // IRQ1                   
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_IPC_2_HANDLER,               // IRQ2                   
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_IPC_3_HANDLER,               // IRQ3                   
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_IPC_4_HANDLER,               // IRQ4                   
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_IPC_5_HANDLER,               // IRQ5                   
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_IPC_6_HANDLER,               // IRQ6                   
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_IPC_7_HANDLER,               // IRQ7                   
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_FAULT_0_HANDLER,             // IRQ8                   
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_FAULT_1_HANDLER,             // IRQ9                   
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_FAULT_2_HANDLER,             // IRQ10                  
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_FAULT_3_HANDLER,             // IRQ11                  
     (cy_systemIntr_Handler) SRSS_INTERRUPT_BACKUP_HANDLER,                // IRQ12                  
     (cy_systemIntr_Handler) SRSS_INTERRUPT_MCWDT_0_HANDLER,               // IRQ13                  
     (cy_systemIntr_Handler) SRSS_INTERRUPT_MCWDT_1_HANDLER,               // IRQ14                  
     (cy_systemIntr_Handler) SRSS_INTERRUPT_MCWDT_2_HANDLER,               // IRQ15                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ16                  
     (cy_systemIntr_Handler) SRSS_INTERRUPT_WDT_HANDLER,                   // IRQ17                  
     (cy_systemIntr_Handler) SRSS_INTERRUPT_HANDLER,                       // IRQ18                  
     (cy_systemIntr_Handler) EVTGEN_0_INTERRUPT_DPSLP_HANDLER,             // IRQ19                  
     (cy_systemIntr_Handler) SCB_0_INTERRUPT_HANDLER,                      // IRQ20                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ21                  
     (cy_systemIntr_Handler) IOSS_INTERRUPT_VDD_HANDLER,                   // IRQ22                  
     (cy_systemIntr_Handler) IOSS_INTERRUPT_GPIO_DPSLP_HANDLER,            // IRQ23                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_DPSLP_0_HANDLER,         // IRQ24                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_DPSLP_1_HANDLER,         // IRQ25                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_DPSLP_2_HANDLER,         // IRQ26                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_DPSLP_3_HANDLER,         // IRQ27                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_DPSLP_4_HANDLER,         // IRQ28                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_DPSLP_5_HANDLER,         // IRQ29                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_DPSLP_6_HANDLER,         // IRQ30                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_DPSLP_7_HANDLER,         // IRQ31                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_DPSLP_8_HANDLER,         // IRQ32                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_DPSLP_9_HANDLER,         // IRQ33                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_DPSLP_10_HANDLER,        // IRQ34                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_DPSLP_11_HANDLER,        // IRQ35                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_DPSLP_12_HANDLER,        // IRQ36                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ37                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ38                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ39                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ40                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ41                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ42                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ43                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ44                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ45                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ46                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ47                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ48                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ49                  
     (cy_systemIntr_Handler) IOSS_INTERRUPT_GPIO_ACT_HANDLER,              // IRQ50                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ51                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ52                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_13_HANDLER,          // IRQ53                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_14_HANDLER,          // IRQ54                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_15_HANDLER,          // IRQ55                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_16_HANDLER,          // IRQ56                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_17_HANDLER,          // IRQ57                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_18_HANDLER,          // IRQ58                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_19_HANDLER,          // IRQ59                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_20_HANDLER,          // IRQ60                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_21_HANDLER,          // IRQ61                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_22_HANDLER,          // IRQ62                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_23_HANDLER,          // IRQ63                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_24_HANDLER,          // IRQ64                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_25_HANDLER,          // IRQ65                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_26_HANDLER,          // IRQ66                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_27_HANDLER,          // IRQ67                  
     (cy_systemIntr_Handler) IOSS_INTERRUPTS_GPIO_ACT_28_HANDLER,          // IRQ68                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ69                  
     (cy_systemIntr_Handler) CPUSS_INTERRUPT_CRYPTO_HANDLER,               // IRQ70                  
     (cy_systemIntr_Handler) CPUSS_INTERRUPT_FM_HANDLER,                   // IRQ71                  
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_CM7_0_FP_HANDLER,            // IRQ72                  
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_CM7_1_FP_HANDLER,            // IRQ73                  
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_CM0_CTI_0_HANDLER,           // IRQ74                  
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_CM0_CTI_1_HANDLER,           // IRQ75                  
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_CM7_0_CTI_0_HANDLER,         // IRQ76                  
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_CM7_0_CTI_1_HANDLER,         // IRQ77                  
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_CM7_1_CTI_0_HANDLER,         // IRQ78                  
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_CM7_1_CTI_1_HANDLER,         // IRQ79                  
     (cy_systemIntr_Handler) EVTGEN_0_INTERRUPT_HANDLER,                   // IRQ80                  
     (cy_systemIntr_Handler) SMIF_0_INTERRUPT_HANDLER,                     // IRQ81                  
     (cy_systemIntr_Handler) SMIF_1_INTERRUPT_HANDLER,                     // IRQ82                  
     (cy_systemIntr_Handler) ETH_0_INTERRUPT_ETH_0_HANDLER,                // IRQ83                  
     (cy_systemIntr_Handler) ETH_0_INTERRUPT_ETH_1_HANDLER,                // IRQ84                  
     (cy_systemIntr_Handler) ETH_0_INTERRUPT_ETH_2_HANDLER,                // IRQ85                  
     (cy_systemIntr_Handler) CANFD_0_INTERRUPT0_HANDLER,                   // IRQ86                  
     (cy_systemIntr_Handler) CANFD_0_INTERRUPT1_HANDLER,                   // IRQ87                  
     (cy_systemIntr_Handler) CANFD_1_INTERRUPT0_HANDLER,                   // IRQ88                  
     (cy_systemIntr_Handler) CANFD_1_INTERRUPT1_HANDLER,                   // IRQ89                  
     (cy_systemIntr_Handler) CANFD_0_INTERRUPTS0_0_HANDLER,                // IRQ90                  
     (cy_systemIntr_Handler) CANFD_0_INTERRUPTS0_1_HANDLER,                // IRQ91                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ92                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ93                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ94                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ95                  
     (cy_systemIntr_Handler) CANFD_0_INTERRUPTS1_0_HANDLER,                // IRQ96                  
     (cy_systemIntr_Handler) CANFD_0_INTERRUPTS1_1_HANDLER,                // IRQ97                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ98                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ99                  
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ100                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ101                 
     (cy_systemIntr_Handler) CANFD_1_INTERRUPTS0_0_HANDLER,                // IRQ102                 
     (cy_systemIntr_Handler) CANFD_1_INTERRUPTS0_1_HANDLER,                // IRQ103                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ104                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ105                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ106                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ107                 
     (cy_systemIntr_Handler) CANFD_1_INTERRUPTS1_0_HANDLER,                // IRQ108                 
     (cy_systemIntr_Handler) CANFD_1_INTERRUPTS1_1_HANDLER,                // IRQ109                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ110                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ111                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ112                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ113                 
     (cy_systemIntr_Handler) LIN_0_INTERRUPTS_0_HANDLER,                   // IRQ114                 
     (cy_systemIntr_Handler) LIN_0_INTERRUPTS_1_HANDLER,                   // IRQ115                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ116                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ117                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ118                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ119                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ120                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ121                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ122                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ123                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ124                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ125                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ126                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ127                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ128                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ129                 
     (cy_systemIntr_Handler) CXPI_0_INTERRUPTS_0_HANDLER,                  // IRQ130                 
     (cy_systemIntr_Handler) CXPI_0_INTERRUPTS_1_HANDLER,                  // IRQ131                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ132                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ133                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ134                 
     (cy_systemIntr_Handler) SCB_1_INTERRUPT_HANDLER,                      // IRQ135                 
     (cy_systemIntr_Handler) SCB_2_INTERRUPT_HANDLER,                      // IRQ136                 
     (cy_systemIntr_Handler) SCB_3_INTERRUPT_HANDLER,                      // IRQ137                 
     (cy_systemIntr_Handler) SCB_4_INTERRUPT_HANDLER,                      // IRQ138                 
     (cy_systemIntr_Handler) SCB_5_INTERRUPT_HANDLER,                      // IRQ139                 
     (cy_systemIntr_Handler) SCB_6_INTERRUPT_HANDLER,                      // IRQ140                 
     (cy_systemIntr_Handler) SCB_7_INTERRUPT_HANDLER,                      // IRQ141                 
     (cy_systemIntr_Handler) SCB_8_INTERRUPT_HANDLER,                      // IRQ142                 
     (cy_systemIntr_Handler) SCB_9_INTERRUPT_HANDLER,                      // IRQ143                 
     (cy_systemIntr_Handler) SCB_10_INTERRUPT_HANDLER,                     // IRQ144                 
     (cy_systemIntr_Handler) SCB_11_INTERRUPT_HANDLER,                     // IRQ145                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ146                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ147                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ148                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ149                 
     (cy_systemIntr_Handler) VIDEOSS_0_INTERRUPT_GFX2D_HANDLER,            // IRQ150                 
     (cy_systemIntr_Handler) VIDEOSS_0_INTERRUPT_MIPICSI_HANDLER,          // IRQ151                 
     (cy_systemIntr_Handler) VIDEOSS_0_INTERRUPT_VIDEOIO0_HANDLER,         // IRQ152                 
     (cy_systemIntr_Handler) VIDEOSS_0_INTERRUPT_VIDEOIO1_HANDLER,         // IRQ153                 
     (cy_systemIntr_Handler) VIDEOSS_0_INTERRUPT_VIDEOIO0_SAFETY_HANDLER,  // IRQ154                 
     (cy_systemIntr_Handler) VIDEOSS_0_INTERRUPT_VIDEOIO1_SAFETY_HANDLER,  // IRQ155                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ156                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ157                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ158                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ159                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_0_HANDLER,              // IRQ160                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_1_HANDLER,              // IRQ161                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_2_HANDLER,              // IRQ162                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_3_HANDLER,              // IRQ163                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_4_HANDLER,              // IRQ164                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_5_HANDLER,              // IRQ165                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_6_HANDLER,              // IRQ166                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_7_HANDLER,              // IRQ167                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_8_HANDLER,              // IRQ168                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_9_HANDLER,              // IRQ169                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_10_HANDLER,             // IRQ170                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_11_HANDLER,             // IRQ171                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_12_HANDLER,             // IRQ172                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_13_HANDLER,             // IRQ173                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_14_HANDLER,             // IRQ174                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_15_HANDLER,             // IRQ175                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_16_HANDLER,             // IRQ176                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_17_HANDLER,             // IRQ177                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_18_HANDLER,             // IRQ178                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_19_HANDLER,             // IRQ179                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_20_HANDLER,             // IRQ180                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_21_HANDLER,             // IRQ181                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_22_HANDLER,             // IRQ182                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_23_HANDLER,             // IRQ183                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_24_HANDLER,             // IRQ184                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_25_HANDLER,             // IRQ185                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_26_HANDLER,             // IRQ186                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_27_HANDLER,             // IRQ187                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_28_HANDLER,             // IRQ188                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_29_HANDLER,             // IRQ189                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_30_HANDLER,             // IRQ190                 
     (cy_systemIntr_Handler) PASS_0_INTERRUPTS_SAR_31_HANDLER,             // IRQ191                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ192                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ193                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ194                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ195                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ196                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ197                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ198                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ199                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ200                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ201                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ202                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ203                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ204                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ205                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ206                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ207                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ208                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ209                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ210                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ211                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ212                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ213                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ214                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ215                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ216                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ217                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ218                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ219                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ220                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ221                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ222                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ223                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ224                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ225                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ226                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ227                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ228                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ229                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ230                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ231                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ232                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ233                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ234                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ235                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ236                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ237                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ238                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ239                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ240                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ241                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ242                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ243                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ244                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ245                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ246                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ247                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ248                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ249                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ250                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ251                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ252                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ253                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ254                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ255                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ256                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ257                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ258                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ259                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ260                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ261                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ262                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ263                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ264                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ265                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ266                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ267                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ268                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ269                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ270                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ271                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ272                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ273                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ274                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ275                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ276                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ277                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ278                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ279                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ280                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ281                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ282                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ283                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ284                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ285                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ286                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ287                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DMAC_0_HANDLER,              // IRQ288                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DMAC_1_HANDLER,              // IRQ289                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DMAC_2_HANDLER,              // IRQ290                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DMAC_3_HANDLER,              // IRQ291                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DMAC_4_HANDLER,              // IRQ292                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DMAC_5_HANDLER,              // IRQ293                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DMAC_6_HANDLER,              // IRQ294                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DMAC_7_HANDLER,              // IRQ295                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_0_HANDLER,               // IRQ296                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_1_HANDLER,               // IRQ297                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_2_HANDLER,               // IRQ298                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_3_HANDLER,               // IRQ299                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_4_HANDLER,               // IRQ300                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_5_HANDLER,               // IRQ301                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_6_HANDLER,               // IRQ302                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_7_HANDLER,               // IRQ303                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_8_HANDLER,               // IRQ304                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_9_HANDLER,               // IRQ305                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_10_HANDLER,              // IRQ306                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_11_HANDLER,              // IRQ307                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_12_HANDLER,              // IRQ308                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_13_HANDLER,              // IRQ309                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_14_HANDLER,              // IRQ310                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_15_HANDLER,              // IRQ311                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_16_HANDLER,              // IRQ312                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_17_HANDLER,              // IRQ313                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_18_HANDLER,              // IRQ314                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_19_HANDLER,              // IRQ315                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_20_HANDLER,              // IRQ316                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_21_HANDLER,              // IRQ317                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_22_HANDLER,              // IRQ318                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_23_HANDLER,              // IRQ319                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_24_HANDLER,              // IRQ320                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_25_HANDLER,              // IRQ321                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_26_HANDLER,              // IRQ322                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_27_HANDLER,              // IRQ323                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_28_HANDLER,              // IRQ324                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_29_HANDLER,              // IRQ325                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_30_HANDLER,              // IRQ326                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_31_HANDLER,              // IRQ327                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_32_HANDLER,              // IRQ328                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_33_HANDLER,              // IRQ329                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_34_HANDLER,              // IRQ330                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_35_HANDLER,              // IRQ331                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_36_HANDLER,              // IRQ332                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_37_HANDLER,              // IRQ333                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_38_HANDLER,              // IRQ334                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_39_HANDLER,              // IRQ335                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_40_HANDLER,              // IRQ336                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_41_HANDLER,              // IRQ337                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_42_HANDLER,              // IRQ338                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_43_HANDLER,              // IRQ339                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_44_HANDLER,              // IRQ340                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_45_HANDLER,              // IRQ341                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_46_HANDLER,              // IRQ342                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_47_HANDLER,              // IRQ343                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_48_HANDLER,              // IRQ344                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_49_HANDLER,              // IRQ345                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_50_HANDLER,              // IRQ346                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_51_HANDLER,              // IRQ347                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_52_HANDLER,              // IRQ348                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_53_HANDLER,              // IRQ349                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_54_HANDLER,              // IRQ350                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_55_HANDLER,              // IRQ351                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_56_HANDLER,              // IRQ352                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_57_HANDLER,              // IRQ353                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_58_HANDLER,              // IRQ354                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_59_HANDLER,              // IRQ355                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_60_HANDLER,              // IRQ356                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_61_HANDLER,              // IRQ357                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_62_HANDLER,              // IRQ358                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_63_HANDLER,              // IRQ359                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_64_HANDLER,              // IRQ360                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_65_HANDLER,              // IRQ361                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_66_HANDLER,              // IRQ362                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_67_HANDLER,              // IRQ363                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_68_HANDLER,              // IRQ364                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_69_HANDLER,              // IRQ365                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_70_HANDLER,              // IRQ366                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_71_HANDLER,              // IRQ367                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_72_HANDLER,              // IRQ368                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_73_HANDLER,              // IRQ369                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_74_HANDLER,              // IRQ370                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW0_75_HANDLER,              // IRQ371                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ372                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ373                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ374                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ375                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ376                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ377                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ378                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ379                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ380                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ381                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ382                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ383                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ384                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ385                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ386                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ387                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ388                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ389                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ390                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ391                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ392                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ393                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ394                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ395                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ396                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ397                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ398                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ399                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ400                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ401                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ402                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ403                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ404                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ405                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ406                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ407                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ408                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ409                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ410                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ411                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ412                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ413                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ414                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ415                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ416                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ417                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ418                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ419                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ420                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ421                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ422                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ423                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_0_HANDLER,               // IRQ424                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_1_HANDLER,               // IRQ425                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_2_HANDLER,               // IRQ426                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_3_HANDLER,               // IRQ427                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_4_HANDLER,               // IRQ428                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_5_HANDLER,               // IRQ429                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_6_HANDLER,               // IRQ430                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_7_HANDLER,               // IRQ431                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_8_HANDLER,               // IRQ432                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_9_HANDLER,               // IRQ433                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_10_HANDLER,              // IRQ434                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_11_HANDLER,              // IRQ435                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_12_HANDLER,              // IRQ436                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_13_HANDLER,              // IRQ437                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_14_HANDLER,              // IRQ438                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_15_HANDLER,              // IRQ439                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_16_HANDLER,              // IRQ440                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_17_HANDLER,              // IRQ441                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_18_HANDLER,              // IRQ442                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_19_HANDLER,              // IRQ443                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_20_HANDLER,              // IRQ444                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_21_HANDLER,              // IRQ445                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_22_HANDLER,              // IRQ446                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_23_HANDLER,              // IRQ447                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_24_HANDLER,              // IRQ448                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_25_HANDLER,              // IRQ449                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_26_HANDLER,              // IRQ450                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_27_HANDLER,              // IRQ451                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_28_HANDLER,              // IRQ452                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_29_HANDLER,              // IRQ453                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_30_HANDLER,              // IRQ454                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_31_HANDLER,              // IRQ455                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_32_HANDLER,              // IRQ456                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_33_HANDLER,              // IRQ457                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_34_HANDLER,              // IRQ458                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_35_HANDLER,              // IRQ459                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_36_HANDLER,              // IRQ460                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_37_HANDLER,              // IRQ461                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_38_HANDLER,              // IRQ462                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_39_HANDLER,              // IRQ463                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_40_HANDLER,              // IRQ464                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_41_HANDLER,              // IRQ465                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_42_HANDLER,              // IRQ466                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_43_HANDLER,              // IRQ467                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_44_HANDLER,              // IRQ468                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_45_HANDLER,              // IRQ469                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_46_HANDLER,              // IRQ470                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_47_HANDLER,              // IRQ471                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_48_HANDLER,              // IRQ472                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_49_HANDLER,              // IRQ473                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_50_HANDLER,              // IRQ474                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_51_HANDLER,              // IRQ475                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_52_HANDLER,              // IRQ476                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_53_HANDLER,              // IRQ477                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_54_HANDLER,              // IRQ478                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_55_HANDLER,              // IRQ479                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_56_HANDLER,              // IRQ480                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_57_HANDLER,              // IRQ481                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_58_HANDLER,              // IRQ482                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_59_HANDLER,              // IRQ483                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_60_HANDLER,              // IRQ484                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_61_HANDLER,              // IRQ485                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_62_HANDLER,              // IRQ486                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_63_HANDLER,              // IRQ487                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_64_HANDLER,              // IRQ488                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_65_HANDLER,              // IRQ489                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_66_HANDLER,              // IRQ490                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_67_HANDLER,              // IRQ491                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_68_HANDLER,              // IRQ492                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_69_HANDLER,              // IRQ493                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_70_HANDLER,              // IRQ494                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_71_HANDLER,              // IRQ495                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_72_HANDLER,              // IRQ496                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_73_HANDLER,              // IRQ497                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_74_HANDLER,              // IRQ498                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_75_HANDLER,              // IRQ499                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_76_HANDLER,              // IRQ500                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_77_HANDLER,              // IRQ501                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_78_HANDLER,              // IRQ502                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_79_HANDLER,              // IRQ503                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_80_HANDLER,              // IRQ504                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_81_HANDLER,              // IRQ505                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_82_HANDLER,              // IRQ506                 
     (cy_systemIntr_Handler) CPUSS_INTERRUPTS_DW1_83_HANDLER,              // IRQ507                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ508                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ509                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ510                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ511                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ512                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ513                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ514                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ515                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ516                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ517                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ518                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ519                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ520                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ521                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ522                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ523                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ524                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ525                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ526                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ527                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ528                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ529                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ530                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ531                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ532                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ533                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ534                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ535                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ536                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ537                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ538                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ539                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ540                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ541                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ542                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ543                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ544                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ545                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ546                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ547                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ548                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ549                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ550                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ551                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_0_HANDLER,                 // IRQ552                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_1_HANDLER,                 // IRQ553                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_2_HANDLER,                 // IRQ554                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_3_HANDLER,                 // IRQ555                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_4_HANDLER,                 // IRQ556                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_5_HANDLER,                 // IRQ557                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_6_HANDLER,                 // IRQ558                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_7_HANDLER,                 // IRQ559                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_8_HANDLER,                 // IRQ560                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_9_HANDLER,                 // IRQ561                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_10_HANDLER,                // IRQ562                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_11_HANDLER,                // IRQ563                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_12_HANDLER,                // IRQ564                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_13_HANDLER,                // IRQ565                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_14_HANDLER,                // IRQ566                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_15_HANDLER,                // IRQ567                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_16_HANDLER,                // IRQ568                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_17_HANDLER,                // IRQ569                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_18_HANDLER,                // IRQ570                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_19_HANDLER,                // IRQ571                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_20_HANDLER,                // IRQ572                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_21_HANDLER,                // IRQ573                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_22_HANDLER,                // IRQ574                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_23_HANDLER,                // IRQ575                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_24_HANDLER,                // IRQ576                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_25_HANDLER,                // IRQ577                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_26_HANDLER,                // IRQ578                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_27_HANDLER,                // IRQ579                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_28_HANDLER,                // IRQ580                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_29_HANDLER,                // IRQ581                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_30_HANDLER,                // IRQ582                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_31_HANDLER,                // IRQ583                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_32_HANDLER,                // IRQ584                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_33_HANDLER,                // IRQ585                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_34_HANDLER,                // IRQ586                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_35_HANDLER,                // IRQ587                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_36_HANDLER,                // IRQ588                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_37_HANDLER,                // IRQ589                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ590                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ591                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ592                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ593                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ594                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ595                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ596                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ597                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ598                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ599                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ600                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ601                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ602                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ603                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ604                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ605                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ606                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ607                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ608                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ609                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ610                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ611                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ612                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ613                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ614                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ615                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_256_HANDLER,               // IRQ616                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_257_HANDLER,               // IRQ617                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_258_HANDLER,               // IRQ618                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_259_HANDLER,               // IRQ619                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_260_HANDLER,               // IRQ620                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_261_HANDLER,               // IRQ621                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_262_HANDLER,               // IRQ622                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_263_HANDLER,               // IRQ623                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_264_HANDLER,               // IRQ624                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_265_HANDLER,               // IRQ625                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_266_HANDLER,               // IRQ626                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_267_HANDLER,               // IRQ627                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ628                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ629                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ630                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ631                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ632                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ633                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ634                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ635                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ636                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ637                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ638                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ639                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ640                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ641                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ642                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ643                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ644                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ645                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ646                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ647                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ648                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ649                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ650                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ651                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ652                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ653                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ654                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ655                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ656                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ657                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ658                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ659                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ660                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ661                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ662                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ663                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ664                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ665                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ666                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ667                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ668                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ669                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ670                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ671                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ672                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ673                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ674                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ675                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ676                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ677                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ678                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ679                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_512_HANDLER,               // IRQ680                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_513_HANDLER,               // IRQ681                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_514_HANDLER,               // IRQ682                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_515_HANDLER,               // IRQ683                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_516_HANDLER,               // IRQ684                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_517_HANDLER,               // IRQ685                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_518_HANDLER,               // IRQ686                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_519_HANDLER,               // IRQ687                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_520_HANDLER,               // IRQ688                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_521_HANDLER,               // IRQ689                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_522_HANDLER,               // IRQ690                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_523_HANDLER,               // IRQ691                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_524_HANDLER,               // IRQ692                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_525_HANDLER,               // IRQ693                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_526_HANDLER,               // IRQ694                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_527_HANDLER,               // IRQ695                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_528_HANDLER,               // IRQ696                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_529_HANDLER,               // IRQ697                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_530_HANDLER,               // IRQ698                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_531_HANDLER,               // IRQ699                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_532_HANDLER,               // IRQ700                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_533_HANDLER,               // IRQ701                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_534_HANDLER,               // IRQ702                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_535_HANDLER,               // IRQ703                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_536_HANDLER,               // IRQ704                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_537_HANDLER,               // IRQ705                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_538_HANDLER,               // IRQ706                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_539_HANDLER,               // IRQ707                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_540_HANDLER,               // IRQ708                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_541_HANDLER,               // IRQ709                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_542_HANDLER,               // IRQ710                 
     (cy_systemIntr_Handler) TCPWM_0_INTERRUPTS_543_HANDLER,               // IRQ711
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ712                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ713                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ714                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ715                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ716                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ717                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ718                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ719                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ720                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ721                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ722                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ723                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ724                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ725                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ726                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ727                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ728                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ729                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ730                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ731                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ732                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ733                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ734                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ735                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ736                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ737                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ738                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ739                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ740                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ741                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ742                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ743                 
     (cy_systemIntr_Handler) I2S_0_INTERRUPTS_TX_0_HANDLER,                // IRQ744                 
     (cy_systemIntr_Handler) I2S_0_INTERRUPTS_RX_0_HANDLER,                // IRQ745                 
     (cy_systemIntr_Handler) I2S_0_INTERRUPTS_TX_1_HANDLER,                // IRQ746                 
     (cy_systemIntr_Handler) I2S_0_INTERRUPTS_RX_1_HANDLER,                // IRQ747                 
     (cy_systemIntr_Handler) I2S_0_INTERRUPTS_TX_2_HANDLER,                // IRQ748                 
     (cy_systemIntr_Handler) I2S_0_INTERRUPTS_RX_2_HANDLER,                // IRQ749                 
     (cy_systemIntr_Handler) I2S_0_INTERRUPTS_TX_3_HANDLER,                // IRQ750                 
     (cy_systemIntr_Handler) I2S_0_INTERRUPTS_RX_3_HANDLER,                // IRQ751                 
     (cy_systemIntr_Handler) TDM_0_INTERRUPTS_TX_0_HANDLER,                // IRQ752                 
     (cy_systemIntr_Handler) TDM_0_INTERRUPTS_RX_0_HANDLER,                // IRQ753                 
     (cy_systemIntr_Handler) TDM_0_INTERRUPTS_TX_1_HANDLER,                // IRQ754                 
     (cy_systemIntr_Handler) TDM_0_INTERRUPTS_RX_1_HANDLER,                // IRQ755                 
     (cy_systemIntr_Handler) TDM_0_INTERRUPTS_TX_2_HANDLER,                // IRQ756                 
     (cy_systemIntr_Handler) TDM_0_INTERRUPTS_RX_2_HANDLER,                // IRQ757                 
     (cy_systemIntr_Handler) TDM_0_INTERRUPTS_TX_3_HANDLER,                // IRQ758                 
     (cy_systemIntr_Handler) TDM_0_INTERRUPTS_RX_3_HANDLER,                // IRQ759                 
     (cy_systemIntr_Handler) SG_0_INTERRUPTS_0_HANDLER,                    // IRQ760                 
     (cy_systemIntr_Handler) SG_0_INTERRUPTS_1_HANDLER,                    // IRQ761                 
     (cy_systemIntr_Handler) SG_0_INTERRUPTS_2_HANDLER,                    // IRQ762                 
     (cy_systemIntr_Handler) SG_0_INTERRUPTS_3_HANDLER,                    // IRQ763                 
     (cy_systemIntr_Handler) SG_0_INTERRUPTS_4_HANDLER,                    // IRQ764                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ765                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ766                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ767                 
     (cy_systemIntr_Handler) PWM_0_INTERRUPTS_0_HANDLER,                   // IRQ768                 
     (cy_systemIntr_Handler) PWM_0_INTERRUPTS_1_HANDLER,                   // IRQ769                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ770                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ771                
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ772                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ773                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ774                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ775                 
     (cy_systemIntr_Handler) DAC_0_INTERRUPT_HANDLER,                      // IRQ776                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ777                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ778                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ779                 
     (cy_systemIntr_Handler) MIXER_0_INTERRUPT_DST_HANDLER,                // IRQ780                 
     (cy_systemIntr_Handler) MIXER_0_INTERRUPTS_SRC_0_HANDLER,             // IRQ781                 
     (cy_systemIntr_Handler) MIXER_0_INTERRUPTS_SRC_1_HANDLER,             // IRQ782                 
     (cy_systemIntr_Handler) MIXER_0_INTERRUPTS_SRC_2_HANDLER,             // IRQ783                 
     (cy_systemIntr_Handler) MIXER_0_INTERRUPTS_SRC_3_HANDLER,             // IRQ784                 
     (cy_systemIntr_Handler) MIXER_0_INTERRUPTS_SRC_4_HANDLER,             // IRQ785                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ786                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ787                 
     (cy_systemIntr_Handler) NC_HANDLER,                                   // IRQ788                 
     (cy_systemIntr_Handler) MIXER_1_INTERRUPT_DST_HANDLER,                // IRQ789                 
     (cy_systemIntr_Handler) MIXER_1_INTERRUPTS_SRC_0_HANDLER,             // IRQ790                 
     (cy_systemIntr_Handler) MIXER_1_INTERRUPTS_SRC_1_HANDLER,             // IRQ791                 
     (cy_systemIntr_Handler) MIXER_1_INTERRUPTS_SRC_2_HANDLER,             // IRQ792                 
     (cy_systemIntr_Handler) MIXER_1_INTERRUPTS_SRC_3_HANDLER,             // IRQ793                 
     (cy_systemIntr_Handler) MIXER_1_INTERRUPTS_SRC_4_HANDLER,             // IRQ794                 
};

#ifdef CY_LINK_SYSTEM_IRQ_TABLE_TO_RAM
    cy_systemIntr_Handler * Cy_SysInt_SystemIrqUserTableRamPointer = Cy_SystemIrqUserTable;
#endif 


void Cy_DefaultUserHandler(void)
{
    // This IRQ occurred because CPU attempted to call IRQ that has not been mapped to user function
    while(1);
}


void CpuUserInt0_Handler(void)
{
    un_CPUSS_CM0_INT0_STATUS_t system_int_status = {0};

#if CY_CPU_CORTEX_M0P
    system_int_status.u32Register = CPUSS->unCM0_INT0_STATUS.u32Register;
#else
    #if defined (CY_CORE_CM7_0)
        system_int_status.u32Register = CPUSS->unCM7_0_INT_STATUS[CPUIntIdx0_IRQn].u32Register;        
    #elif defined (CY_CORE_CM7_1)
        system_int_status.u32Register = CPUSS->unCM7_1_INT_STATUS[CPUIntIdx0_IRQn].u32Register;
    #endif
#endif

    if(system_int_status.stcField.u1SYSTEM_INT_VALID)
    {
       Cy_SystemIrqUserTable[system_int_status.stcField.u10SYSTEM_INT_IDX](); // jump to system interrupt handler
    }
    else
    {
          // Triggered by SW or due to SW clear error (SW cleared a peripheral 
          // interrupt flag but didn't clear the Pending flag at NVIC)
    }
    
    NVIC_ClearPendingIRQ(CPUIntIdx0_IRQn);
}


void CpuUserInt1_Handler(void)
{
    un_CPUSS_CM0_INT1_STATUS_t system_int_status = {0};

#if CY_CPU_CORTEX_M0P
    system_int_status.u32Register = CPUSS->unCM0_INT1_STATUS.u32Register;
#else
    #if defined (CY_CORE_CM7_0)
        system_int_status.u32Register = CPUSS->unCM7_0_INT_STATUS[CPUIntIdx1_IRQn].u32Register;        
    #elif defined (CY_CORE_CM7_1)
        system_int_status.u32Register = CPUSS->unCM7_1_INT_STATUS[CPUIntIdx1_IRQn].u32Register;
    #endif
#endif

    if(system_int_status.stcField.u1SYSTEM_INT_VALID)
    {
       Cy_SystemIrqUserTable[system_int_status.stcField.u10SYSTEM_INT_IDX](); // jump to system interrupt handler
    }
    else
    {
          // Triggered by SW or due to SW clear error (SW cleared a peripheral 
          // interrupt flag but didn't clear the Pending flag at NVIC)
    }
    
    NVIC_ClearPendingIRQ(CPUIntIdx1_IRQn);
}


void CpuUserInt2_Handler(void)
{
    un_CPUSS_CM0_INT2_STATUS_t system_int_status = {0};

#if CY_CPU_CORTEX_M0P
    system_int_status.u32Register = CPUSS->unCM0_INT2_STATUS.u32Register;
#else
    #if defined (CY_CORE_CM7_0)
        system_int_status.u32Register = CPUSS->unCM7_0_INT_STATUS[CPUIntIdx2_IRQn].u32Register;        
    #elif defined (CY_CORE_CM7_1)
        system_int_status.u32Register = CPUSS->unCM7_1_INT_STATUS[CPUIntIdx2_IRQn].u32Register;
    #endif
#endif

    if(system_int_status.stcField.u1SYSTEM_INT_VALID)
    {
       Cy_SystemIrqUserTable[system_int_status.stcField.u10SYSTEM_INT_IDX](); // jump to system interrupt handler
    }
    else
    {
          // Triggered by SW or due to SW clear error (SW cleared a peripheral 
          // interrupt flag but didn't clear the Pending flag at NVIC)
    }
    
    NVIC_ClearPendingIRQ(CPUIntIdx2_IRQn);
}


void CpuUserInt3_Handler(void)
{
    un_CPUSS_CM0_INT3_STATUS_t system_int_status = {0};

#if CY_CPU_CORTEX_M0P
    system_int_status.u32Register = CPUSS->unCM0_INT3_STATUS.u32Register;
#else
    #if defined (CY_CORE_CM7_0)
        system_int_status.u32Register = CPUSS->unCM7_0_INT_STATUS[CPUIntIdx3_IRQn].u32Register;        
    #elif defined (CY_CORE_CM7_1)
        system_int_status.u32Register = CPUSS->unCM7_1_INT_STATUS[CPUIntIdx3_IRQn].u32Register;
    #endif
#endif

    if(system_int_status.stcField.u1SYSTEM_INT_VALID)
    {
       Cy_SystemIrqUserTable[system_int_status.stcField.u10SYSTEM_INT_IDX](); // jump to system interrupt handler
    }
    else
    {
          // Triggered by SW or due to SW clear error (SW cleared a peripheral 
          // interrupt flag but didn't clear the Pending flag at NVIC)
    }
    
    NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
}


void CpuUserInt4_Handler(void)
{
    un_CPUSS_CM0_INT4_STATUS_t system_int_status = {0};

#if CY_CPU_CORTEX_M0P
    system_int_status.u32Register = CPUSS->unCM0_INT4_STATUS.u32Register;
#else
    #if defined (CY_CORE_CM7_0)
        system_int_status.u32Register = CPUSS->unCM7_0_INT_STATUS[CPUIntIdx4_IRQn].u32Register;        
    #elif defined (CY_CORE_CM7_1)
        system_int_status.u32Register = CPUSS->unCM7_1_INT_STATUS[CPUIntIdx4_IRQn].u32Register;
    #endif
#endif

    if(system_int_status.stcField.u1SYSTEM_INT_VALID)
    {
       Cy_SystemIrqUserTable[system_int_status.stcField.u10SYSTEM_INT_IDX](); // jump to system interrupt handler
    }
    else
    {
          // Triggered by SW or due to SW clear error (SW cleared a peripheral 
          // interrupt flag but didn't clear the Pending flag at NVIC)
    }
    
    NVIC_ClearPendingIRQ(CPUIntIdx4_IRQn);
}


void CpuUserInt5_Handler(void)
{
    un_CPUSS_CM0_INT5_STATUS_t system_int_status = {0};

#if CY_CPU_CORTEX_M0P
    system_int_status.u32Register = CPUSS->unCM0_INT5_STATUS.u32Register;
#else
    #if defined (CY_CORE_CM7_0)
        system_int_status.u32Register = CPUSS->unCM7_0_INT_STATUS[CPUIntIdx5_IRQn].u32Register;        
    #elif defined (CY_CORE_CM7_1)
        system_int_status.u32Register = CPUSS->unCM7_1_INT_STATUS[CPUIntIdx5_IRQn].u32Register;
    #endif
#endif

    if(system_int_status.stcField.u1SYSTEM_INT_VALID)
    {
       Cy_SystemIrqUserTable[system_int_status.stcField.u10SYSTEM_INT_IDX](); // jump to system interrupt handler
    }
    else
    {
          // Triggered by SW or due to SW clear error (SW cleared a peripheral 
          // interrupt flag but didn't clear the Pending flag at NVIC)
    }
    
    NVIC_ClearPendingIRQ(CPUIntIdx5_IRQn);
}


void CpuUserInt6_Handler(void)
{
    un_CPUSS_CM0_INT6_STATUS_t system_int_status = {0};

#if CY_CPU_CORTEX_M0P
    system_int_status.u32Register = CPUSS->unCM0_INT6_STATUS.u32Register;
#else
    #if defined (CY_CORE_CM7_0)
        system_int_status.u32Register = CPUSS->unCM7_0_INT_STATUS[CPUIntIdx6_IRQn].u32Register;        
    #elif defined (CY_CORE_CM7_1)
        system_int_status.u32Register = CPUSS->unCM7_1_INT_STATUS[CPUIntIdx6_IRQn].u32Register;
    #endif
#endif

    if(system_int_status.stcField.u1SYSTEM_INT_VALID)
    {
       Cy_SystemIrqUserTable[system_int_status.stcField.u10SYSTEM_INT_IDX](); // jump to system interrupt handler
    }
    else
    {
          // Triggered by SW or due to SW clear error (SW cleared a peripheral 
          // interrupt flag but didn't clear the Pending flag at NVIC)
    }
    
    NVIC_ClearPendingIRQ(CPUIntIdx6_IRQn);
}


void CpuUserInt7_Handler(void)
{
    un_CPUSS_CM0_INT7_STATUS_t system_int_status = {0};

#if CY_CPU_CORTEX_M0P
    system_int_status.u32Register = CPUSS->unCM0_INT7_STATUS.u32Register;
#else
    #if defined (CY_CORE_CM7_0)
        system_int_status.u32Register = CPUSS->unCM7_0_INT_STATUS[CPUIntIdx7_IRQn].u32Register;        
    #elif defined (CY_CORE_CM7_1)
        system_int_status.u32Register = CPUSS->unCM7_1_INT_STATUS[CPUIntIdx7_IRQn].u32Register;
    #endif
#endif

    if(system_int_status.stcField.u1SYSTEM_INT_VALID)
    {
       Cy_SystemIrqUserTable[system_int_status.stcField.u10SYSTEM_INT_IDX](); // jump to system interrupt handler
    }
    else
    {
          // Triggered by SW or due to SW clear error (SW cleared a peripheral 
          // interrupt flag but didn't clear the Pending flag at NVIC)
    }
    
    NVIC_ClearPendingIRQ(CPUIntIdx7_IRQn);
}



/* [] END OF FILE */
