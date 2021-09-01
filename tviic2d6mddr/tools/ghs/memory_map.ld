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

// Only 1 MB of non-contiguous flash memory is available in PSVP and we use following hard-coded assignment for now
// IMPORTANT: only change the "code_flash" related definitions below if you know what you are doing
// CM0+  :: 0x10000000 to 0x1003ffff (256 KB)
// CM7_0 :: 0x10040000 to 0x1007ffff (256 KB)
// CM7_1 :: 0x102f8000 to 0x10377fff (512 KB) 
// In addition there are 2x 64 KB (0x105F0000-0x105fffff, 0x10610000-0x1061ffff) small sectors available, but will not be used by linker file.

// Please note:
// The whole SRAM area of this device consists of several SRAM areas (SRAM0, 1, ...) each having
// its own SRAM controller. Please check the device datasheet for the exact memory to SRAM controller distribution.
// For achieving the best CM7 performance it is recommended - if possible - to ensure that data with temporal
// locality (e.g. data belonging to one task) does not span multiple SRAM controllers. Otherwise a stalling of AXI
// transactions may occur, if they are originating from the same CM7 AXI transaction ID to different SRAM controllers.


// Check that necessary definitions are available

#if (!defined(_LINK_flash_)) && (!defined(_LINK_sram_))
  #error "Link location not defined or not supported!"
#endif

#if (!defined(_CORE_cm0plus_)) && (!defined(_CORE_cm7_0_)) && (!defined(_CORE_cm7_1_))
  #error "Target core not defined or not supported!"
#endif


//=======================================================================================
// Description of special symbols
//=======================================================================================
// sram_private_for_srom:
//     The SROM code needs an area for private data during system call processing. It will
//     not be accessible by user software in protection state NORMAL and beyond.
//     So it needs to be excluded from the total SRAM available to the user.
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
    code_flash_total_size      = 6336K // no need to adapt for PSVP, only used by silicon #else below
    sram_total_size            = 640K
    sram_base                  = 0x28000000
    sram_used_by_boot_base     = sram_base + sram_total_size - 6K
    sram_private_for_srom      = 2K
    cm0plus_intvec_alignment   = 256   // CPU specific vector table alignment requirement
    cm7_intvec_alignment       = 128   // CPU specific vector table alignment requirement
    ecc_init_width             = 8     
    
  #if defined(_LINK_sram_)
    sram_can_lin_boot_reserve  = 512
  #else
    sram_can_lin_boot_reserve  = 0
  #endif

    sram_user_start_offset     = sram_private_for_srom + sram_can_lin_boot_reserve
    sram_user_end_offset       = sram_total_size       - 0
  
    //===================================================================================
    //                              USER CONFIGURATION
    //===================================================================================
  
    // Specify how much SRAM and CODE_FLASH shall be used by CM0+ application and CM7_0 application,
    // the rest of the memory will be automatically assigned to CM7_1 application
    cm0plus_sram_reserve       =  128K - sram_user_start_offset
    cm7_0_sram_reserve         =  256K
    
  #if CY_USE_PSVP == 1
    // PSVP
    cm0plus_code_flash_reserve =  256K  // <- hardcoded for PSVP
    cm7_0_code_flash_reserve   =  256K  // <- hardcoded for PSVP
  #else
    // Silicon
    cm0plus_code_flash_reserve = 1024K;
    cm7_0_code_flash_reserve   = 3072K;
  #endif
    
    //-----------------------------------------------------------------------------------

    // Specify stack and heap sizes for CM0+, CM7_0 and CM7_1 application independently
    cm0plus_heap_reserve       = 1K
    cm0plus_stack_reserve      = 1K
    cm7_0_heap_reserve         = 1K
    cm7_0_stack_reserve        = 1K
    cm7_1_heap_reserve         = 1K
    cm7_1_stack_reserve        = 1K
    
    //===================================================================================
     
    
    // Calculation of SRAM distribution among all cores
    cm0plus_sram_offset        = sram_user_start_offset
    cm7_0_sram_offset          = cm0plus_sram_offset  + cm0plus_sram_reserve
    cm7_1_sram_offset          = cm7_0_sram_offset    + cm7_0_sram_reserve
    cm7_1_sram_reserve         = sram_user_end_offset - cm7_1_sram_offset
    
    // Calculation of CODE_FLASH distribution among all cores
    cm0plus_code_flash_offset  = 0
    cm7_0_code_flash_offset    = cm0plus_code_flash_offset + cm0plus_code_flash_reserve
  #if CY_USE_PSVP == 1
    cm7_1_code_flash_offset    = 0x002f8000 // <- hardcoded for PSVP
    cm7_1_code_flash_reserve   = 512K       // <- hardcoded for PSVP
  #else
    cm7_1_code_flash_offset    = cm7_0_code_flash_offset + cm7_0_code_flash_reserve
    cm7_1_code_flash_reserve   = code_flash_total_size   - cm7_1_code_flash_offset
  #endif    

    // Map core dependent definition to generic name for memory and section definition
  #if defined(_CORE_cm0plus_)
    self_itcm_size             = 0
    self_dtcm_size             = 0    
    heap_reserve               = cm0plus_heap_reserve
    stack_reserve              = (cm0plus_stack_reserve + (ecc_init_width - 1)) & (~((ecc_init_width - 1))) // Ensure that stack size is an integer multiple of ECC init width (round up)
    sram_offset                = cm0plus_sram_offset  
    sram_reserve               = cm0plus_sram_reserve 
    code_flash_offset          = cm0plus_code_flash_offset  
    code_flash_reserve         = cm0plus_code_flash_reserve
    intvec_alignment           = cm0plus_intvec_alignment
    
  #elif defined(_CORE_cm7_0_)
    self_itcm_size             = 64K
    self_dtcm_size             = 64K    
    heap_reserve               = cm7_0_heap_reserve
    stack_reserve              = (cm7_0_stack_reserve + (ecc_init_width - 1)) & (~((ecc_init_width - 1))) // Ensure that stack size is an integer multiple of ECC init width (round up)
    sram_offset                = cm7_0_sram_offset  
    sram_reserve               = cm7_0_sram_reserve 
    code_flash_offset          = cm7_0_code_flash_offset  
    code_flash_reserve         = cm7_0_code_flash_reserve
    intvec_alignment           = cm7_intvec_alignment
    
  #elif defined(_CORE_cm7_1_)
    self_itcm_size             = 64K
    self_dtcm_size             = 64K    
    heap_reserve               = cm7_1_heap_reserve
    stack_reserve              = (cm7_1_stack_reserve + (ecc_init_width - 1)) & (~((ecc_init_width - 1))) // Ensure that stack size is an integer multiple of ECC init width (round up)
    sram_offset                = cm7_1_sram_offset  
    sram_reserve               = cm7_1_sram_reserve 
    code_flash_offset          = cm7_1_code_flash_offset  
    code_flash_reserve         = cm7_1_code_flash_reserve
    intvec_alignment           = cm7_intvec_alignment
  #endif

}


MEMORY
{
    SELF_ITCM            : ORIGIN = 0x00000000,                     LENGTH = self_itcm_size
    CODE_FLASH           : ORIGIN = 0x10000000 + code_flash_offset, LENGTH = code_flash_reserve
    WORK_FLASH           : ORIGIN = 0x14000000,                     LENGTH = 0x00040000         //  256 KB
    SFLASH               : ORIGIN = 0x17000000,                     LENGTH = 0x00008000         //   32 KB
    SFLASH_ALT           : ORIGIN = 0x17800000,                     LENGTH = 0x00008000         //   32 KB
    SELF_DTCM            : ORIGIN = 0x20000000,                     LENGTH = self_dtcm_size
    VRAM                 : ORIGIN = 0x24000000,                     LENGTH = 0x00400000         // 4096 KB
    SRAM                 : ORIGIN = sram_base  + sram_offset,       LENGTH = sram_reserve
    CM7_0_ITCM           : ORIGIN = 0x48000000,                     LENGTH = 0x00010000         //   64 KB
    CM7_0_DTCM           : ORIGIN = 0x48010000,                     LENGTH = 0x00010000         //   64 KB
    CM7_1_ITCM           : ORIGIN = 0x48100000,                     LENGTH = 0x00010000         //   64 KB
    CM7_1_DTCM           : ORIGIN = 0x48110000,                     LENGTH = 0x00010000         //   64 KB
    SMIF0_DEV0_MEMMAPPED : ORIGIN = 0x60000000,                     LENGTH = 0x10000000         //  256 MB
    SMIF0_DEV1_MEMMAPPED : ORIGIN = 0x70000000,                     LENGTH = 0x10000000         //  256 MB
    LPDDR4_RAM           : ORIGIN = 0x80000000,                     LENGTH = 0x40000000         // 1024 MB
    SMIF1_DEV0_MEMMAPPED : ORIGIN = 0xc0000000,                     LENGTH = 0x10000000         //  256 MB
    SMIF1_DEV1_MEMMAPPED : ORIGIN = 0xd0000000,                     LENGTH = 0x10000000         //  256 MB
}

// Note: The SMIFx_DEVy_MEMMAPPED size is not fixed within a SMIFx instance and can be changed according to the actual SMIF user configuration.
//       This linker file just evenly distributes the available memory to all SMIF devices.

