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

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "cy_project.h"
#include "cy_device_headers.h"

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

/* Local Definision */
#define E_UART_RECV_THRESHOLD    8
#define E_UART_RING_BUF_SIZE     512
#define E_UART_USER_BUF_SIZE     512
#define E_UART_RX_INTR_FACTER     (                              \
                                 CY_SCB_UART_RX_TRIGGER      |   \
                               /*CY_SCB_UART_RX_NOT_EMPTY    | */\
                               /*CY_SCB_UART_RX_FULL         | */\
                                 CY_SCB_UART_RX_OVERFLOW     |   \
                                 CY_SCB_UART_RX_UNDERFLOW    |   \
                                 CY_SCB_UART_RX_ERR_FRAME    |   \
                                 CY_SCB_UART_RX_ERR_PARITY   |   \
                                 CY_SCB_UART_RX_BREAK_DETECT |   \
                                 0                               \
                                )
#define E_UART_TX_INTR_FACTER     (                              \
                                 CY_SCB_UART_TX_TRIGGER      |   \
                               /*CY_SCB_UART_TX_NOT_FULL     | */\
                               /*CY_SCB_UART_TX_EMPTY        | */\
                                 CY_SCB_UART_TX_OVERFLOW     |   \
                               /*CY_SCB_UART_TX_UNDERFLOW    | */\
                                 CY_SCB_UART_TX_DONE         |   \
                               /*CY_SCB_UART_TX_NACK         | */\
                               /*CY_SCB_UART_TX_ARB_LOST     | */\
                                 0                               \
                                )
                                

/* Local Functions Declaration */
void Log_Time(void);

/* SCB - UART Configuration */
cy_stc_scb_uart_context_t   g_stc_uart_context;
cy_stc_scb_uart_config_t    g_stc_uart_config = 
{
    .uartMode                   = CY_SCB_UART_STANDARD,
    .oversample                 = 1,
    .dataWidth                  = 8,
    .enableMsbFirst             = false,
    .stopBits                   = CY_SCB_UART_STOP_BITS_1,
    .parity                     = CY_SCB_UART_PARITY_NONE,
    .enableInputFilter          = false,
    .dropOnParityError          = false,
    .dropOnFrameError           = false,
    .enableMutliProcessorMode   = false,
    .receiverAddress            = 0,
    .receiverAddressMask        = 0,
    .acceptAddrInFifo           = false,
    .irdaInvertRx               = false,
    .irdaEnableLowPowerReceiver = false,
    .smartCardRetryOnNack       = false,
    .enableCts                  = false,
    .ctsPolarity                = CY_SCB_UART_ACTIVE_LOW,
    .rtsRxFifoLevel             = 0,
    .rtsPolarity                = CY_SCB_UART_ACTIVE_LOW,
    .breakWidth                 = 0,
    .rxFifoTriggerLevel         = 0,
    .rxFifoIntEnableMask        = E_UART_RX_INTR_FACTER,
    .txFifoTriggerLevel         = 0,
    .txFifoIntEnableMask        = E_UART_TX_INTR_FACTER
};

/* Local Variables */
uint8_t     g_uart_out_data[128];                       // TX Buffer for Terminal Print
uint8_t     g_uart_in_data[128];                        // RX Buffer
uint8_t     g_uart_rx_ring[E_UART_RING_BUF_SIZE] = {0}; // RX Ring Buffer
uint8_t     g_uart_user_buf[E_UART_USER_BUF_SIZE];      // User Buffer for coping from Ring Buffer



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

cy_stc_rtc_alarm_t const alarm = 
{
  .sec            =   5u,
  .sec_en         =   CY_RTC_ALARM_ENABLE,
  .min            =   00u,
  .min_en         =   CY_RTC_ALARM_DISABLE,
  .hour           =   00u,
  .hour_en        =   CY_RTC_ALARM_DISABLE,
  .dayOfWeek      =   01u,
  .dayOfWeek_en   =   CY_RTC_ALARM_DISABLE,
  .date           =   01u,
  .date_en        =   CY_RTC_ALARM_DISABLE,
  .month          =   01u,
  .month_en       =   CY_RTC_ALARM_DISABLE,
  .alm_en         =   CY_RTC_ALARM_ENABLE
};

cy_str_rtc_dst_t const RTC_dstConfig;

cy_stc_gpio_pin_config_t user_led0_port_pin_cfg =             
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

cy_stc_gpio_pin_config_t user_led1_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED2_PIN_MUX,                           
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
    /* Clear any pending interrupts */
    Cy_Rtc_ClearInterrupt(CY_RTC_INTR_ALARM1);
    Cy_GPIO_Inv(USER_LED2_PORT, USER_LED2_PIN);
}

int main(void)
{
    SystemInit();
    
    __enable_irq(); /* Enable global interrupts. */
    
    /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR); 
    
    /* Check the IO status. If current status is frozen, unfreeze the system. */
    if(Cy_SysPm_GetIoFreezeStatus())
    {   /* Unfreeze the system */
        Cy_SysPm_IoUnfreeze();
    }
    else
    {
        /* Do nothing */    
    }

    Cy_GPIO_Pin_Init(USER_LED1_PORT, USER_LED1_PIN, &user_led0_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_LED2_PORT, USER_LED2_PIN, &user_led1_port_pin_cfg);
    
    /* Initializing console uart interface */
    Cy_Semihosting_InitAll(CY_USB_SCB_TYPE, 115200, NULL, false);
    
    /* Opening UART Comment */
    printf("\n\rHibernet wakeup..\n\r");
    
    // Initialize all SYSTEM_INT_STRUCTS with port16 handler while it is not working yet to cover potential issues in interrupt wiring
    cy_stc_sysint_irq_t irq_cfg;

    // Overwrite with TCPWM0 setting
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
    
    /* Set the ILO_0 as the clock source to the RTC block */
    // Cy_Rtc_clock_source(CY_RTC_CLK_SRC_ILO_0); 
    
    Cy_SysClk_WcoEnable(10000);
    Cy_Rtc_SelectFrequencyPrescaler(CY_RTC_FREQ_WCO_32768_HZ);
    Cy_Rtc_clock_source(CY_RTC_CLK_SRC_WCO);
    
    /* Wait for alarm to be set */ 
    while(Cy_Rtc_Init(&RTC_config) != CY_RET_SUCCESS);   

   /* Clear any pending interrupts */
    Cy_Rtc_ClearInterrupt(CY_RTC_INTR_ALARM1);
        
    /*Configures the source (Alarm1) that trigger the interrupts */
    Cy_Rtc_SetInterruptMask(CY_RTC_INTR_ALARM1);
         
    /* Wait for alarm to be set */
    while(Cy_Rtc_SetAlarmDateAndTime(&alarm,CY_RTC_ALARM_1) != CY_RET_SUCCESS);  
    
    /* Check RTC time */
    printf("Start Time\t:");
    Log_Time();

    // Toggle an LED for sometime
    for(uint16_t i=0; i<200; i++)
    {
        /* Turn on LED for to some time to indicate the hibernate mode. */
        Cy_SysTick_DelayInUs(50000);
        Cy_GPIO_Inv(USER_LED1_PORT, USER_LED1_PIN);
    }
    
    /* Enable wake up source */
    Cy_SysPm_SetHibWakeupSource(CY_SYSPM_HIBALARM);
    
    /* Check RTC time */
    printf("Sleep Time\t:");
    Log_Time();
    
    /* Jump to Hibernate Mode */
    Cy_SysPm_Hibernate();
    
    for(;;)
    {   
        
    }
}

void Log_Time(void)
{
    cy_stc_rtc_config_t CurrentdateTime;
    Cy_Rtc_GetDateAndTime(&CurrentdateTime);
    printf(" %d:%d:%d\n\r", CurrentdateTime.hour, CurrentdateTime.min, CurrentdateTime.sec);
}


/* [] END OF FILE */
