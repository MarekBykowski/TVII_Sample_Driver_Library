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
#include "audioss/pwm/cy_pwm.h"


/* PWM port configuration macro */
//------------------------------------------------------------------------------
// Please check the BSP.

/* User led configuration */
//------------------------------------------------------------------------------
cy_stc_gpio_pin_config_t io_port_pin_cfg =
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = CY_USER_LED1_PIN_MUX,                           
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

/* Pwm tx configuration */
//------------------------------------------------------------------------------
cy_stc_pwm_tx_config_t myPwmConfig =
{
    .txEnabled          = true,
    .txWordSize         = CY_PWM_WORD_LEN24,
    .txClkDiv           = 3,
    .txClkSel           = CY_PWM_SEL_SRSS_CLK0,
    .txLineOutPolarity  = CY_PWM_LINE1_P_OUT_LINE1_N_OUT_LINE2_P_OUT_LINE2_N_OUT,
    .txDoublerEnabled   = false,
    .txDoublerMode      = CY_PWM_TX_DOUBLE_REPETITION,
    .txGainCode         = 115,
    .txFormat           = CY_PWM_TX_H_BRIDGE,//CY_PWM_TX_H_BRIDGE,
    .txGainScale        = 0,
    .pwmMinValue        = 0,
    .pwmMaxValue        = 512,
    .pwmPeriod          = 40,
    .pwmOffset          = 0,
    .pwmDeadTime        = 0,
    .txFifoTriggerLevel = 9,
};

/* Audio pwm data array */
//------------------------------------------------------------------------------
static uint32_t pwmData[9] =
{
    0x0000007, 0x0000088, 0xff0fff6, 0x0000007, 0x0000088, 0xff0fff6, 0x0000007, 0x0000088, 0xff0fff6,
};  
#define DATA_NUM_PER_PERIOD     (sizeof(pwmData) / sizeof(uint32_t))


/* Audio pwm interrupt configuration */ 
//------------------------------------------------------------------------------
static const cy_stc_sysint_irq_t irqCfgPwm =
{
    .sysIntSrc  = CY_AUDIOSS_PWM0_IRQN,
    .intIdx     = CPUIntIdx2_IRQn, 
    .isEnabled  = true, 
};

/* Global function declaration */
//------------------------------------------------------------------------------
void InitPwmLines(void);
void TransmitPwmData(void);
void AudioPwmInterruptHandler(void);


/* Audio pwm interrupt handler */
//------------------------------------------------------------------------------
void AudioPwmInterruptHandler(void)
{
    uint32_t maskedIntrStatus;
    
    maskedIntrStatus = Cy_Pwm_Tx_GetInterruptStatusMasked(CY_AUDIOSS_PWM_TYPE);
    if((maskedIntrStatus & CY_PWM_INTR_TX_FIFO_TRIGGER) != 0)
    {
        Cy_Pwm_Tx_ClearInterrupt(CY_AUDIOSS_PWM_TYPE, maskedIntrStatus);
        Cy_SysTick_DelayInUs(50000);
        Cy_SysTick_DelayInUs(50000);
        Cy_SysTick_DelayInUs(50000);
        TransmitPwmData();
    }
}

/* Audio pwm data transmit function */
//------------------------------------------------------------------------------
void TransmitPwmData(void)
{       
    for(uint32_t data_i = 0; data_i <DATA_NUM_PER_PERIOD; data_i++)
    {
        Cy_Pwm_Tx_WriteData(CY_AUDIOSS_PWM_TYPE, pwmData[data_i]);
    }
    //Cy_Pwm_Tx_SetInterruptMask(CY_AUDIOSS_PWM_TYPE, CY_PWM_INTR_TX_FIFO_TRIGGER);
    Cy_Pwm_Tx_SetTriggerInterruptMask(CY_AUDIOSS_PWM_TYPE);
}

/* Initialize Audio pwm io mux */
//------------------------------------------------------------------------------
void InitPwmLines(void)
{   
    // On PSVP : PWM0_LINE1_P0 -- TP357
    io_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    io_port_pin_cfg.hsiom = CY_AUDIOSS_PWM0_L1P1_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_PWM0_L1P1_PORT, CY_AUDIOSS_PWM0_L1P1_PIN, &io_port_pin_cfg);

    // On PSVP : PWM0_LINE1_N0 -- TP240
    io_port_pin_cfg.hsiom = CY_AUDIOSS_PWM0_L1N1_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_PWM0_L1N1_PORT, CY_AUDIOSS_PWM0_L1N1_PIN, &io_port_pin_cfg);

    // On PSVP : PWM0_LINE2_P0 -- TP307
    io_port_pin_cfg.hsiom = CY_AUDIOSS_PWM0_L2P1_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_PWM0_L2P1_PORT, CY_AUDIOSS_PWM0_L2P1_PIN, &io_port_pin_cfg);

    // On PSVP : PWM0_LINE2_N0 -- TP340
    io_port_pin_cfg.hsiom = CY_AUDIOSS_PWM0_L2N1_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_PWM0_L2N1_PORT, CY_AUDIOSS_PWM0_L2N1_PIN, &io_port_pin_cfg);
}

/* Main app function */
//------------------------------------------------------------------------------
int main(void)
{
    /* System initialization */
    SystemInit();
  
    /* Enable irq */
    __enable_irq();
    
    /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    //Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR);
    
    /* Enable system clock */
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_5);
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_6);
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_7);
    
    /* Port setting for pwm channels */
    InitPwmLines();
    
    /* Initialization for pwm */
    Cy_Pwm_Tx_DeInit(CY_AUDIOSS_PWM_TYPE);

    /* Initialize pwm transmittter interface */
    Cy_Pwm_Tx_Init(CY_AUDIOSS_PWM_TYPE, &myPwmConfig);
    
    /* Interrupt setting for Pwm communication */
    Cy_SysInt_InitIRQ(&irqCfgPwm);
    Cy_SysInt_SetSystemIrqVector(irqCfgPwm.sysIntSrc, AudioPwmInterruptHandler);
    NVIC_SetPriority(irqCfgPwm.intIdx, 1);
    NVIC_ClearPendingIRQ(irqCfgPwm.intIdx);
    NVIC_EnableIRQ(irqCfgPwm.intIdx);
    
    /* Dummy data write */
    TransmitPwmData();
    
    /* Enable pwm */
    Cy_Pwm_Tx_Enable(CY_AUDIOSS_PWM_TYPE);

    for(;;)
    {
        /* Toggle user led */
        Cy_SysTick_DelayInUs(50000);
        TransmitPwmData();
    }
}

//------------------------------------------------------------------------------

/* [] END OF FILE */


