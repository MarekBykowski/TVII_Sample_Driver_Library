/***************************************************************************//**
* \file main_cm0plus.c
*
* \version 1.0
*
* \brief Main example file for CM0+
*
********************************************************************************
* \copyright
* Copyright 2016-2020, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_project.h"
#include "cy_device_headers.h"

#if (CY_USE_PSVP == 1)
    #define USER_LED_PORT           CY_AB_LED_PORT
    #define USER_LED_PIN            CY_AB_LED_PIN
    #define USER_LED_PIN_MUX        CY_AB_LED_PIN_MUX
#else
    #define USER_LED_PORT           CY_CB_USER_LED1_PORT
    #define USER_LED_PIN            CY_CB_USER_LED1_PIN
    #define USER_LED_PIN_MUX        CY_CB_USER_LED1_PIN_MUX 
#endif

#define RAM_0_ADDRESS                   (0x28000500) 
#define RAM_0_DATA                      (0x5A5A5A5A)
#define RAM_0_CORRECT_PARITY            (0x18)
#define RAM_0_ONEBIT_PARITY             (0x5D)
#define RAM_0_TWOBIT_PARITY             (0x14)
#define RAM_0_C_IDX                     (58)
#define RAM_0_NC_IDX                    (59)
                                     
#define RAM_1_ADDRESS                   (0x28080000)
#define RAM_1_DATA                      (0x12345678)
#define RAM_1_CORRECT_PARITY            (0x4D)
#define RAM_1_ONEBIT_PARITY             (0x0E)
#define RAM_1_TWOBIT_PARITY             (0x48)
#define RAM_1_C_IDX                     (60)
#define RAM_1_NC_IDX                    (61)

#define RAM_2_ADDRESS                   (0x280C0500)
#define RAM_2_DATA                      (0x87654321)
#define RAM_2_CORRECT_PARITY            (0x4D)
#define RAM_2_ONEBIT_PARITY             (0x0E)
#define RAM_2_TWOBIT_PARITY             (0x48)
#define RAM_2_C_IDX                     (62)
#define RAM_2_NC_IDX                    (63)

#define RAM_ADDRESS                     RAM_0_ADDRESS
#define RAM_DATA                        RAM_0_DATA
#define RAM_CORRECT_PARITY              RAM_0_CORRECT_PARITY
#define RAM_ONEBIT_PARITY               RAM_0_ONEBIT_PARITY
#define RAM_TWOBIT_PARITY               RAM_0_TWOBIT_PARITY
#define RAM_C_IDX                       RAM_0_C_IDX
#define RAM_NC_IDX                      RAM_0_NC_IDX

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED_PIN_MUX,                           
    .intEdge = 0,                                  
    .intMask = 0,                                  
    .vtrip = 0,                                    
    .slewRate = 0,                                 
    .driveSel = 0,                                 
    .vregEn = 0,                                   
    .ibufMode = 0,                                 
    .vtripSel = 0,                                 
    .vrefSel = 0,                                  
    .vohSel = 0,                                   
};
  
uint32_t pf_source = 0;
uint32_t fail = 0;

int main(void)
{    
    SystemInit();
    
    __enable_irq(); /* Enable global interrupts. */

    /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
    
    /***************************************************************************
    ###########################     SRAM 0 C_ECC  ##############################
    ***************************************************************************/
    
    {
        Cy_SysFlt_ClearStatus(FAULT_STRUCT0); // clear status (typically this process is done by boot code)
        Cy_SysFlt_SetMaskByIdx(FAULT_STRUCT0, CY_SYSFLT_RAMC0_C_ECC); // enable Fault System SRAM 0 non-correctable ECC error
        Cy_SysFlt_SetInterruptMask(FAULT_STRUCT0);
    }
    
    // VALIDATING FAULT SOURCE, RAM_0_C_IDX
    // SRAM 0 FAULT MASK AND SOURCE CONFIGURATION FOR ONE BIT PARITY
    CPUSS->unRAM0_CTL0.stcField.u1ECC_EN = 1;
    CPUSS->unRAM0_CTL0.stcField.u1ECC_AUTO_CORRECT = 0;
    CPUSS->unRAM0_CTL0.stcField.u1ECC_INJ_EN = 1;
    CPUSS->unRAM0_CTL0.stcField.u1ECC_CHECK_DIS = 0;    
    CPUSS->unECC_CTL.stcField.u24WORD_ADDR = ((RAM_ADDRESS >> 3) & 0x00FFFFFF);
    CPUSS->unECC_CTL.stcField.u8PARITY = RAM_ONEBIT_PARITY;
    
    // SRAM 0 DATA WRITE
    CY_SET_REG32(RAM_ADDRESS, RAM_DATA);    
    // SRAM 0 DATA READ TO CAUSE THE ECC FAULT STARTED
    CY_GET_REG32(RAM_ADDRESS);    
    
    // SRAM 0 DATA READ TO CAUSE THE ECC FAULT    
    // SRAM 0 FAULT MASK AND SOURCE DE-INT FOR ONE BIT    
    CPUSS->unRAM0_CTL0.stcField.u1ECC_EN = 1;
    CPUSS->unRAM0_CTL0.stcField.u1ECC_AUTO_CORRECT = 1;
    CPUSS->unRAM0_CTL0.stcField.u1ECC_INJ_EN = 0;
    CPUSS->unRAM0_CTL0.stcField.u1ECC_CHECK_DIS = 0;    
    
    /***************************************************************************
    ###########################     SRAM 0 NC_ECC  #############################
    ***************************************************************************/
        
    {
        Cy_SysFlt_ClearStatus(FAULT_STRUCT0); // clear status (typically this process is done by boot code)
        Cy_SysFlt_SetMaskByIdx(FAULT_STRUCT0, CY_SYSFLT_RAMC0_NC_ECC); // enable Fault System SRAM 0 non-correctable ECC error
        Cy_SysFlt_SetInterruptMask(FAULT_STRUCT0);
    }
      
    // VALIDATING FAULT SOURCE, RAM_NC_IDX
    // SRAM 0 FAULT MASK AND SOURCE CONFIGURATION FOR TWO BIT   
    CPUSS->unRAM0_CTL0.stcField.u1ECC_EN = 1;
    CPUSS->unRAM0_CTL0.stcField.u1ECC_AUTO_CORRECT = 0;
    CPUSS->unRAM0_CTL0.stcField.u1ECC_INJ_EN = 1;
    CPUSS->unRAM0_CTL0.stcField.u1ECC_CHECK_DIS = 0;
    CPUSS->unECC_CTL.stcField.u24WORD_ADDR = ((RAM_ADDRESS >> 3) & 0x00FFFFFF);
    CPUSS->unECC_CTL.stcField.u8PARITY = RAM_TWOBIT_PARITY;
    
    // SRAM 0 DATA WRITE
    CY_SET_REG32(RAM_ADDRESS, RAM_DATA);    
    // SRAM 0 DATA READ TO CAUSE THE ECC FAULT STARTED
    CY_GET_REG32(RAM_ADDRESS);
    
    // SRAM 0 DATA READ TO CAUSE THE ECC FAULT    
    // SRAM 0 FAULT MASK AND SOURCE DE-INT FOR TWO BIT  
    CPUSS->unRAM0_CTL0.stcField.u1ECC_EN = 1;
    CPUSS->unRAM0_CTL0.stcField.u1ECC_AUTO_CORRECT = 1;
    CPUSS->unRAM0_CTL0.stcField.u1ECC_INJ_EN = 0;
    CPUSS->unRAM0_CTL0.stcField.u1ECC_CHECK_DIS = 0;
            
    for(;;)
    {
        Cy_SysTick_DelayInUs(50000);

        Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
    }
}



/* [] END OF FILE */
