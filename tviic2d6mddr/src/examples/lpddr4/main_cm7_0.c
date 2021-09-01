/***************************************************************************//**
* \file main_cm7_0.c
*
* \brief
* Main file for CM7 #0
*
********************************************************************************
* \copyright
* Copyright 2016-2019, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
/* select the Dolphin Releases which is the base for your IP header file*/
#define DOTP26 26
//#define DOTP31 31
#define HEADER_FILE_RELEASE DOTP26 // current version is DOTP26



/******************************************************************************/
/*                              INIT TYPE Definintion                         */
/******************************************************************************/
#define INIT_WITH_TRAINING          0   
#define INIT_WITHOUT_TRAINING       1

/* 
    macro to set the LPDDR4 Controller initialization
    for PSVP: 
            #define INIT_TYPE       INIT_WITH_TRAINING 

    for FCV or SOC both versions are possible. 
    When set to #define INIT_TYPE   INIT_WITHOUT_TRAINING
    the PTSRxx register in the lpddr_config structure must be set with training 
    data matching  user hardware as these values are used to load known 
    training values to the phy for initialization
*/
#define INIT_TYPE   INIT_WITH_TRAINING
//#define INIT_TYPE   INIT_WITHOUT_TRAINING

// define Timer-ID for cyclic MR4 reading / DQS2DQ check for retrain
#define MR4_DQS2DQ_TIMER_ID 0

/******************************************************************************/
/*                              USED INIT DATA Definintion                    */
/******************************************************************************/
#define USE_CYPRESS_CFG1        1     //lpddr4_cfg1.h  refer lpddr4 config file content.xlsx
#define USE_CYPRESS_CFG3        3     //lpddr4_cfg3.h  refer lpddr4 config file content.xlsx
#define USE_CYPRESS_CFG3_ECC    5     //same as lpddr4_cfg3.h with ECC enabled
#define USE_CYPRESS_CFG7        7    //lpddr4_cfg7.h refer lpddr4 config file content.xlsx
#define USE_CYPRESS_CFG8        8    //lpddr4_cfg8.h refer lpddr4 config file content.xlsx

/* select the configuration to use for LPDDR Controlller initialization */
#define USED_INIT_DATA      USE_CYPRESS_CFG1


#include "cy_project.h"
#include "cy_device_headers.h"
#include "drivers/lpddr4/cy_lpddr4.h"
#include "basic_tests.h"


/** Interrupt Configuration for catching LPDDR4 Faults*/
cy_stc_sysint_irq_t irq_cfg = 
{
    .sysIntSrc  = cpuss_interrupts_fault_0_IRQn,
    .intIdx     = CPUIntIdx2_IRQn,
    .isEnabled  = true,
};



/******************** adjusment for outdated header *********************/
//manually adjust the lpddr config.As we are missing the updated headers .We
//need to adjust some registers manually as soon as updated cyip_lpddr4.h is 
//available this code can be deleted.
void ApplyMissingHeaderFileChanges(cy_stc_lpddr4_config_t * config)
{
#if(HEADER_FILE_RELEASE <= DOTP26)
   	uint32_t tempu32REG ;
    /* for the new Bitfields in DMCTL */ 
    tempu32REG = config->unDMCTL.u32Register;
    //[12:11]dram_chan_en=2b11 + [20:13]rd_req_min=8b00001000 +[28:21]wr_req_min=2b00001001
    config->unDMCTL.u32Register=(tempu32REG | (0x3<<11) | (0x8<<13) | (0x9<<21));
    #if(USED_INIT_DATA == USE_CYPRESS_CFG1)
        /* for the new Bitfields in RTCFG0_Tx x=0,1,2,3 */
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT0.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT0.u32Register=(tempu32REG | (1<<25) | (1<<24));
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT1.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT1.u32Register=(tempu32REG | (1<<25) | (1<<24));
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT2.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT2.u32Register=(tempu32REG | (1<<25) | (1<<24));
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT3.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT3.u32Register=(tempu32REG  | (1<<25)  | (1<<24));
    #elif((USED_INIT_DATA == USE_CYPRESS_CFG3)||(USED_INIT_DATA == USE_CYPRESS_CFG3_ECC))
        /* for the new Bitfields in RTCFG0_Tx x=0,1,2,3 */
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT0.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT0.u32Register=(tempu32REG | (1<<25) | (1<<24));
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT1.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT1.u32Register=(tempu32REG | (1<<25) | (1<<24));
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT2.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT2.u32Register=(tempu32REG | (1<<25) | (1<<24));
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT3.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT3.u32Register=(tempu32REG  | (1<<24));
    #elif(USED_INIT_DATA == USE_CYPRESS_CFG7)
        /* for the new Bitfields in RTCFG0_Tx x=0,1,2,3 */
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT0.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT0.u32Register=(tempu32REG | (1<<25) | (1<<24));
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT1.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT1.u32Register=(tempu32REG | (1<<25));
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT2.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT2.u32Register=(tempu32REG | (1<<25));
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT3.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT3.u32Register=(tempu32REG  | (1<<24));
    #elif(USED_INIT_DATA == USE_CYPRESS_CFG8)
        /* for the new Bitfields in RTCFG0_Tx x=0,1,2,3 */
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT0.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT0.u32Register=(tempu32REG | (1<<25) | (1<<24));
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT1.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT1.u32Register=(tempu32REG | (1<<25) | (1<<24));
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT2.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT2.u32Register=(tempu32REG | (1<<25) | (1<<24));
        //RTCFG0_RT0 [24]ARQ_LAHEAD_EN  [25]AWQ_LAHEAD_EN
        tempu32REG = config->unRTCFG0_RT3.u32Register;
        //clr the bits 24 and 25
        tempu32REG = tempu32REG & (~((1<<25) | (1<<24)));
        config->unRTCFG0_RT3.u32Register=(tempu32REG | (1<<24));
    #else
        #error Config Data in #USED_INIT_DATA not specified
    #endif 
#endif
/******************** end of adjustment for outdated header ******************/
}



void Cy_LPDDR4_CorrectSECECCFaults()
{
    // /* locals to read the ECC Fault information*/
    // un_LPDDR4_LPDDR4_CORE_INECCSTT0_t unINECCSTT0;
    // un_LPDDR4_LPDDR4_CORE_INECCSTT1_t unINECCSTT1;
    // un_LPDDR4_LPDDR4_CORE_INECCSTT2_t unINECCSTT2;
    // un_LPDDR4_LPDDR4_CORE_INECCSTT3_t unINECCSTT3;
    // un_LPDDR4_LPDDR4_CORE_INECCSTT4_t unINECCSTT4;

    // un_LPDDR4_LPDDR4_CORE_INECCSTT0_t unINECCSTT0_1;
    // un_LPDDR4_LPDDR4_CORE_INECCSTT1_t unINECCSTT1_1;
    // un_LPDDR4_LPDDR4_CORE_INECCSTT2_t unINECCSTT2_1;
    // un_LPDDR4_LPDDR4_CORE_INECCSTT3_t unINECCSTT3_1;
    // un_LPDDR4_LPDDR4_CORE_INECCSTT4_t unINECCSTT4_1;
    // /*Read the ECC Status Registers*/
    // unINECCSTT4.u32Register=LPDDR40->LPDDR4_CORE.unINECCSTT4.u32Register;
    // unINECCSTT0.u32Register=LPDDR40->LPDDR4_CORE.unINECCSTT0.u32Register;
    // unINECCSTT1.u32Register=LPDDR40->LPDDR4_CORE.unINECCSTT1.u32Register;
    // unINECCSTT2.u32Register=LPDDR40->LPDDR4_CORE.unINECCSTT2.u32Register;
    // unINECCSTT3.u32Register=LPDDR40->LPDDR4_CORE.unINECCSTT3.u32Register;

    // unINECCSTT4_1.u32Register=LPDDR40->LPDDR4_CORE.unINECCSTT4.u32Register;
    // unINECCSTT0_1.u32Register=LPDDR40->LPDDR4_CORE.unINECCSTT0.u32Register;
    // unINECCSTT1_1.u32Register=LPDDR40->LPDDR4_CORE.unINECCSTT1.u32Register;
    // unINECCSTT2_1.u32Register=LPDDR40->LPDDR4_CORE.unINECCSTT2.u32Register;
    // unINECCSTT3_1.u32Register=LPDDR40->LPDDR4_CORE.unINECCSTT3.u32Register;


    /*to be continued*/

}

/*******************************************************************************
 * Fault Handler for FAULT_STRUCT0   
 * **************************************************************************//*
 *
 *  LPDDR4 faults are mapped to Fault Structure 0
 *  In this Fault Handler the actions in case of fault can be handled
 * 
 ******************************************************************************/
void irqFaultReport0Handler(void)
{
    cy_en_sysflt_source_t status;

    uint32_t fltData = 0;
    status = Cy_SysFlt_GetErrorSource(FAULT_STRUCT0);

    if(status != CY_SYSFLT_NO_FAULT)
    {
        /* LPDDR4 FATAL Fault */
        if(status == CY_SYSFLT_LPDDR4_0_LPDDR4_FATAL_FAULT) 
        {
            /*update the controller running status as faults are stopping the controller*/
            Cy_Lpddr_SyncContextOnFault();
            //add some usefull code for fatal fault handling 
            fltData = Cy_SysFlt_GetData0(FAULT_STRUCT0);
            __NOP();
            CY_ASSERT(0);
            
        }
        /* LPDDR4 none fatal Fault */
        if(status == CY_SYSFLT_LPDDR4_0_LPDDR4_NONFATAL_FAULT) 
        {   
            //add some usefull code for none fatal fault handling 
            fltData = Cy_SysFlt_GetData0(FAULT_STRUCT0);
            switch(fltData)
            {
                /* State Maschine Error */
                case 0: 
                        /*add something usefull here*/
                        Cy_Lpddr_ClearGCFSM_DMCFG();
                        break;
            
                /* correctable ECC Fault */
                case 1:
                        /*add error correction*/ 
                        Cy_LPDDR4_CorrectSECECCFaults();
                        break;
            }
        }
    }
}


int main(void)
{
    /* variable used for the return value of TestBasicReadWriteAccess() */
    volatile uint32_t errorcnt = 0; 
    /**
    * specifies the system temperature gradient of your system
    * used to calculate the cycle time for reading MR4 and updating 
    * the refresh rate [°C/s] */
    uint32_t temperatureGradient = 10;
    /**
     * system response delay of your system
     * used to calculate the cycle time for reading MR4 and updating 
     * the refresh rate [ms] */
    uint32_t systemResponseDelay = 1;

    /**local variable for the MR4 Read Interval */
    uint32_t mr4ReadInterval=0;
    /* exit condition for the main loop  down below*/
    cy_en_lpddr4_retval_t cancelCondition = CY_LPDDR4_SUCCESS;  

    /* include the lpddr4 config structure declaration and initialization*/
    #if(USED_INIT_DATA == USE_CYPRESS_CFG1)
        #include"lpddr4_cfg1.h"
    #elif(USED_INIT_DATA == USE_CYPRESS_CFG3)
        #include"lpddr4_cfg3.h"
    #elif(USED_INIT_DATA == USE_CYPRESS_CFG7)
        #include"lpddr4_cfg7.h"
    #elif(USED_INIT_DATA == USE_CYPRESS_CFG8)
        #include"lpddr4_cfg8.h"
    #elif(USED_INIT_DATA == USE_CYPRESS_CFG3_ECC)
        #include"lpddr4_cfg3_ecc.h"
    #else
        #error Config Data in #USED_INIT_DATA not specified
    #endif

    ApplyMissingHeaderFileChanges(&lpddr_config);

    SystemInit();
    __enable_irq();
    //Cy_Lpddr_ControllerDisable(LPDDR40);
    /***************************************************************************
                            Fault report settings
    ***************************************************************************/
    /* clear status (typically this process is done by boot code)*/
    Cy_SysFlt_ClearStatus(FAULT_STRUCT0); 
    /* set the Mask bit for LPDDR fatal Fault */
    Cy_SysFlt_SetMaskByIdx(FAULT_STRUCT0, CY_SYSFLT_LPDDR4_0_LPDDR4_FATAL_FAULT);
    /* set the Mask bit for LPDDR none fatal Fault */
    Cy_SysFlt_SetMaskByIdx(FAULT_STRUCT0, CY_SYSFLT_LPDDR4_0_LPDDR4_NONFATAL_FAULT);
    Cy_SysFlt_SetInterruptMask(FAULT_STRUCT0);
    
    /***************************************************************************
                               Interrupt settings
    ***************************************************************************/
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, irqFaultReport0Handler);
    NVIC_SetPriority(irq_cfg.intIdx, 0);
    NVIC_EnableIRQ(irq_cfg.intIdx);


    /* when INIT_TYPE is set to INIT_WITH_TRAINING the LPDDR4 Controller 
    will be initialized and training is performed. 
    On PSVP the function is running trough and function returns 
    CY_LPDDR4_SUCCESS but no real training is performed */

    #if ( INIT_TYPE == INIT_WITH_TRAINING )
        CY_ASSERT(CY_LPDDR4_SUCCESS == Cy_Lpddr_ControllerInit(LPDDR40,&lpddr_config,CY_LPDDR4_INIT_WITH_TRAINING));
    /* when INIT_TYPE is set to INIT_WITHOUT_TRAINING the LPDDR Controller is 
    initializted with values  trained during Full Chip Verification. PTSRx 
    Registers are reloaded and PHY is initialzed using these values. */
    #elif ( INIT_TYPE == INIT_WITHOUT_TRAINING ) 
        CY_ASSERT(CY_LPDDR4_SUCCESS == Cy_Lpddr_ControllerInit(LPDDR40,&lpddr_config,CY_LPDDR4_INIT_WITH_RELOAD));
    #else
        #error Init Type not set
    #endif
    // if ECC is activated init ECC Memory
    #if(USED_INIT_DATA == USE_CYPRESS_CFG3_ECC)
        Cy_LPDDR4_InitECCMemory(LPDDR40);
    #endif

    // Initializes the HW timer used as SW Timer source (SysTick)
    Cy_SwTmr_Init();

    /* calculate the the Intervall for reading the Mode Rgeister 4 as specified in JEDEC209-4B */
    mr4ReadInterval = Cy_Lpddr_CalcMR4ReadInterval(systemResponseDelay,temperatureGradient);

    /*  Start a periodic SW timer with interval calculated above (running from IRQ context) 
        Cy_Lpddr4_MemoryMonitoring is the Callback Function which is 
        performing LPDDR4 housekeeping :
                - read MR4 for temperature Monitoring 
                - refresh interval adjust based on temperature
                - timing derating based based on temperature
                - start DQS Oscillator ( used to detect the need for retraining)
                - read the DQS Oscillator values ( MR18/MR19 )
                - detect need for retrain    */
    Cy_SwTmr_StartHighPrio(MR4_DQS2DQ_TIMER_ID,mr4ReadInterval, true,Cy_Lpddr_MemoryMonitoring);
    //Cy_Lpddr_SetControllerStopped();
    /* write data to memory and read back. 
    if everything worked errocnt should be 0.TestBasicWriteAccess 
    should not be activaterd with ECC active as it does not check for protected regions*/
    #if(USED_INIT_DATA != USE_CYPRESS_CFG3_ECC)
     errorcnt = TestBasicReadWriteAccess(&lpddr_config);
    CY_ASSERT( Copy16KDataToExternalMem(0xff));
    #endif

    //Main Loop starts here 
    while(cancelCondition == CY_LPDDR4_SUCCESS)
    {
        //put your code here
        
        
        
        /*check if retraining is needed*/
        if(true == Cy_Lpddr_CheckForRetraining())
        {
            /* stop the timer for memory monitoring during retraining */
            Cy_SwTmr_Stop(MR4_DQS2DQ_TIMER_ID);
            #if (CY_USE_PSVP == 1)
                /*as real re-training doesn´t work on PSVP 
                reset the retraining request manually */
                Cy_LPDDR4_PSVPFakeTraining();
            #else
                /* on none PSVP HW  perform the real training */
                cancelCondition = Cy_Lpddr_RequestDQS2DQRetrain(LPDDR40);
            #endif
            /* restart the timer for memory monitoring */
            Cy_SwTmr_StartHighPrio(MR4_DQS2DQ_TIMER_ID,mr4ReadInterval, true,Cy_Lpddr_MemoryMonitoring);
        }
    #if(USED_INIT_DATA == USE_CYPRESS_CFG3_ECC)
        // ECC not yet ready
        //Cy_LPDDR4_InjectSECErrorAtAddress(LPDDR40,0x80000005,0x80);
    
    #endif
        

    }
    Cy_Lpddr_ControllerDeInit(LPDDR40);
}

/* [] END OF FILE */
