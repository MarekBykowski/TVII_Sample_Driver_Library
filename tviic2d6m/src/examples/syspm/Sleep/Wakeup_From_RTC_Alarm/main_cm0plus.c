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
    #define USER_LED1_PORT           CY_LED0_PORT
    #define USER_LED1_PIN            CY_LED0_PIN
    #define USER_LED1_PIN_MUX        CY_LED0_PIN_MUX

    #define USER_LED2_PORT           CY_LED1_PORT
    #define USER_LED2_PIN            CY_LED1_PIN
    #define USER_LED2_PIN_MUX        CY_LED1_PIN_MUX
#else
    #define USER_LED1_PORT           CY_USER_LED1_PORT
    #define USER_LED1_PIN            CY_USER_LED1_PIN
    #define USER_LED1_PIN_MUX        CY_USER_LED1_PIN_MUX

    #define USER_LED2_PORT           CY_USER_LED2_PORT
    #define USER_LED2_PIN            CY_USER_LED2_PIN
    #define USER_LED2_PIN_MUX        CY_USER_LED2_PIN_MUX
#endif

/*******************************************************************************
*    Parameters definitions
*******************************************************************************/

/* Date Format setting constants */
#define RTC_MM_DD_YYYY                (0u)
#define RTC_DD_MM_YYYY                (1u)
#define RTC_YYYY_MM_DD                (2u)

/* Initial Time and Date definitions */
#define RTC_INITIAL_DATE_SEC          (0u)
#define RTC_INITIAL_DATE_MIN          (0u)
#define RTC_INITIAL_DATE_HOUR         (12u)
#define RTC_INITIAL_DATE_HOUR_FORMAT  (CY_RTC_24_HOURS)
#define RTC_INITIAL_DATE_DOW          (1u)
#define RTC_INITIAL_DATE_DOM          (4u)
#define RTC_INITIAL_DATE_MONTH        (9u)
#define RTC_INITIAL_DATE_YEAR         (17u)

/** The instance-specific configuration structure. This should be used in the 
*  associated RTC_Init() function.
*/
cy_stc_rtc_config_t const RTC_config =
{
    /* Initiate time and date */
    .sec       = RTC_INITIAL_DATE_SEC,
    .min       = RTC_INITIAL_DATE_MIN,
    .hour      = RTC_INITIAL_DATE_HOUR,
    .hrMode    = RTC_INITIAL_DATE_HOUR_FORMAT,
    .dayOfWeek = RTC_INITIAL_DATE_DOW,
    .date      = RTC_INITIAL_DATE_DOM,
    .month     = RTC_INITIAL_DATE_MONTH,
    .year      = RTC_INITIAL_DATE_YEAR,
};

cy_stc_rtc_alarm_t alarm = 
{
  .sec            =   5u,
  .sec_en          =   CY_RTC_ALARM_ENABLE,
  .min            =   00u,
  .min_en          =   CY_RTC_ALARM_DISABLE,
  .hour           =   00u,
  .hour_en         =   CY_RTC_ALARM_DISABLE,
  .dayOfWeek      =   01u,
  .dayOfWeek_en    =   CY_RTC_ALARM_DISABLE,
  .date           =   01u,
  .date_en         =   CY_RTC_ALARM_DISABLE,
  .month          =   01u,
  .month_en        =   CY_RTC_ALARM_DISABLE,
  .alm_en          =   CY_RTC_ALARM_ENABLE
};

cy_str_rtc_dst_t const RTC_dstConfig;

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED1_PIN_MUX,                           
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

/** RTC_rtcDstStatus variable which is for DST feature and is 
*  called in Cy_RTC_Interrupt() PDL driver function. This variable is 
*  defined as true if DST is enabled and as false if DST is disabled
*/
bool RTC_rtcDstStatus = false;

void RTC_Handler(void)
{
    Cy_Rtc_Interrupt(&RTC_dstConfig, RTC_rtcDstStatus);              
}

void Cy_Rtc_Alarm1Interrupt(void)
{   
    alarm.sec = (alarm.sec + 2) % 60u;

    /* Wait for alarm to be set */
    while(Cy_Rtc_SetAlarmDateAndTime(&alarm,CY_RTC_ALARM_1) != CY_RET_SUCCESS);

    /* Clear any pending interrupts */
    Cy_Rtc_ClearInterrupt(CY_RTC_INTR_ALARM1);

    Cy_GPIO_Inv(USER_LED1_PORT, USER_LED1_PIN);  
}

int main(void)
{
    SystemInit();

    /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR);

    uint8_t flag = 0; 
    uint8_t count = 0;
         
    __enable_irq(); /* Enable global interrupts. */
    
    Cy_GPIO_Pin_Init(USER_LED1_PORT, USER_LED1_PIN, &user_led_port_pin_cfg);
    user_led_port_pin_cfg.hsiom = USER_LED2_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_LED2_PORT, USER_LED2_PIN, &user_led_port_pin_cfg);
    
    cy_stc_sysint_irq_t irq_cfg;

    irq_cfg = (cy_stc_sysint_irq_t)
    {
        .sysIntSrc  = srss_interrupt_backup_IRQn,
        .intIdx     = CPUIntIdx2_IRQn,  
        .isEnabled  = true,         
     };
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, RTC_Handler);

    NVIC_SetPriority(CPUIntIdx2_IRQn, 3);
    NVIC_ClearPendingIRQ(CPUIntIdx2_IRQn);
    NVIC_EnableIRQ(CPUIntIdx2_IRQn);
    BACKUP->unCTL.u32Register =0x0000200;
    
    /* Wait for alarm to be set */
    while(Cy_Rtc_Init(&RTC_config) != CY_RET_SUCCESS);   

    /* Clear any pending interrupts */
    Cy_Rtc_ClearInterrupt(CY_RTC_INTR_ALARM1);
        
    /*Configures the source (Alarm1) that trigger the interrupts */
    Cy_Rtc_SetInterruptMask(CY_RTC_INTR_ALARM1);
         
    /* Wait for alarm to be set */
    while(Cy_Rtc_SetAlarmDateAndTime(&alarm,CY_RTC_ALARM_1) != CY_RET_SUCCESS);  
    
    Cy_SysPm_Sleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
    
    for(;;)
    {
        Cy_SysTick_DelayInUs(50000);
        Cy_GPIO_Inv(USER_LED2_PORT, USER_LED2_PIN);
        
        count++;
        if (count >10)
        {
            count = 0;
            Cy_SysPm_Sleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
        }
    }
}

/* [] END OF FILE */
