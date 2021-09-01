/* __DISCLAIMER_START__                                                      */
/******************************************************************************
* (c) 2014-2017, Cypress Semiconductor Corporation
* or a subsidiary of Cypress Semiconductor Corporation. All rights
* reserved.
*
* This software, including source code, documentation and related
* materials ( "Software" ), is owned by Cypress Semiconductor
* Corporation or one of its subsidiaries ( "Cypress" ) and is protected by
* and subject to worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ( "EULA" ).
*
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the
* Software source code solely for use in connection with Cypress' s
* integrated circuit products. Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO
* WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING,
* BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE. Cypress reserves the right to make
* changes to the Software without notice. Cypress does not assume any
* liability arising out of the application or use of the Software or any
* product or circuit described in the Software. Cypress does not
* authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ( "High Risk Product" ). By
* including Cypress' s product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
******************************************************************************/
/* __DISCLAIMER_END__                                                        */
/*****************************************************************************/

// Check that necessary definitions are available

#if (!defined(_LINK_flash_)) && (!defined(_LINK_sram_))
  #error "Link location not defined or not supported!"
#endif

#if (!defined(_CORE_cm0plus_)) && (!defined(_CORE_cm4_))
  #error "Target core not defined or not supported!"
#endif

#if (!defined(CY_MCU_rev_a)) && (!defined(CY_MCU_rev_b)) && (!defined(CY_MCU_rev_c)) && (!defined(CY_MCU_rev_d))
  #error "MCU revision is not defined or not supported!"
#endif


//=======================================================================================
// Description of special symbols
//=======================================================================================
// sram_private_for_srom:
//     The SROM code needs an area for private data during system call processing. It will
//     not be accessible by user software in protection state NORMAL and beyond.
//     So it needs to be excluded from the total SRAM available to the user. The location of
//     this RAM depends on the MCU revision.
// 
// sram_used_by_boot_base:
//     Cypress (ROM and Flash) boot firmware needs an area in SRAM (e.g. for stack). This may cause issues in case of
//     RAM build configurations when code/const sections are loaded there by the debugger, but may get overwritten
//     if reset is triggered by the debug script later on. So in case of RAM build configurations the linker should
//     check if the area of ROM type sections overlaps the boot area.
// 
// sram_can_lin_boot_reserve:
//     Cypress CAN/LIN Bootloader is entered only if several conditions apply (refer Architecture TRM, "Flash Boot" chapter).
//     It will then use an area of SRAM for its data.
//     This may cause issues in case of RAM build configurations when code/const sections are loaded there by the debugger,
//     but may get overwritten if reset is triggered by the debug script later on. Therefore, this area shall be reserved.
//
// ecc_init_width:
//     Defines the most restrictive native ECC width (in bytes) of all "normal" memories (SRAM, DTCM, ITCM) in any
//     Traveo II derivate in order to keep the startup code dealing with ECC initialization generic


//=======================================================================================
// Following symbol and memory area definitions are used by linker_directives.ld
//=======================================================================================

DEFAULTS
{
    // Constants
    code_flash_total_size      = 1088K
    sram_total_size            = 128K
    sram_base                  = 0x08000000
    sram_used_by_boot_base     = sram_base + sram_total_size - 6K
    sram_private_for_srom      = 2K
    cm0plus_intvec_alignment   = 256   // CPU specific vector table alignment requirement
    cm4_intvec_alignment       = 1024  // CPU specific vector table alignment requirement
    ecc_init_width             = 8     
    
  #if defined(_LINK_sram_)
    sram_can_lin_boot_reserve  = 512
  #else
    sram_can_lin_boot_reserve  = 0
  #endif

  #if defined(CY_MCU_rev_a) || defined(CY_MCU_rev_b) || defined(CY_MCU_rev_c)
    sram_user_start_offset     = 0                     + sram_can_lin_boot_reserve
    sram_user_end_offset       = sram_total_size       - sram_private_for_srom
  #else
    sram_user_start_offset     = sram_private_for_srom + sram_can_lin_boot_reserve
    sram_user_end_offset       = sram_total_size       - 0
  #endif
  
    //===================================================================================
    //                              USER CONFIGURATION
    //===================================================================================
  
    // Specify how much SRAM and CODE_FLASH shall be used by CM0+ application,
    // the rest of the memory will be automatically assigned to CM4 application
    cm0plus_sram_reserve       = 64K - sram_user_start_offset
    cm0plus_code_flash_reserve = 544K
    
    //-----------------------------------------------------------------------------------

    // Specify stack and heap sizes for CM0+ and CM4 application independently
    cm0plus_heap_reserve       = 512
    cm0plus_stack_reserve      = 1K
    cm4_heap_reserve           = 512
    cm4_stack_reserve          = 1K    
    
    //===================================================================================
     
    
    // Calculation of SRAM distribution among all cores
    cm0plus_sram_offset        = sram_user_start_offset
    cm4_sram_offset            = cm0plus_sram_offset  + cm0plus_sram_reserve
    cm4_sram_reserve           = sram_user_end_offset - cm4_sram_offset
    
    // Calculation of CODE_FLASH distribution among all cores
    cm0plus_code_flash_offset  = 0
    cm4_code_flash_offset      = cm0plus_code_flash_offset + cm0plus_code_flash_reserve
    cm4_code_flash_reserve     = code_flash_total_size     - cm4_code_flash_offset
        

    // Map core dependent definition to generic name for memory and section definition
  #if defined(_CORE_cm0plus_)
    heap_reserve               = cm0plus_heap_reserve
    stack_reserve              = (cm0plus_stack_reserve + (ecc_init_width - 1)) & (~((ecc_init_width - 1))) // Ensure that stack size is an integer multiple of ECC init width (round up)
    sram_offset                = cm0plus_sram_offset  
    sram_reserve               = cm0plus_sram_reserve 
    code_flash_offset          = cm0plus_code_flash_offset  
    code_flash_reserve         = cm0plus_code_flash_reserve
    intvec_alignment           = cm0plus_intvec_alignment
    
  #else // CM4
    heap_reserve               = cm4_heap_reserve
    stack_reserve              = (cm4_stack_reserve + (ecc_init_width - 1)) & (~((ecc_init_width - 1))) // Ensure that stack size is an integer multiple of ECC init width (round up)
    sram_offset                = cm4_sram_offset  
    sram_reserve               = cm4_sram_reserve 
    code_flash_offset          = cm4_code_flash_offset  
    code_flash_reserve         = cm4_code_flash_reserve
    intvec_alignment           = cm4_intvec_alignment

  #endif

}


MEMORY
{
    SRAM                 : ORIGIN = sram_base  + sram_offset,       LENGTH = sram_reserve
    CODE_FLASH           : ORIGIN = 0x10000000 + code_flash_offset, LENGTH = code_flash_reserve
    WORK_FLASH           : ORIGIN = 0x14000000,                     LENGTH = 0x00018000         //   96 KB
    SFLASH               : ORIGIN = 0x17000000,                     LENGTH = 0x00008000         //   32 KB
    SFLASH_ALT           : ORIGIN = 0x17800000,                     LENGTH = 0x00008000         //   32 KB
}

