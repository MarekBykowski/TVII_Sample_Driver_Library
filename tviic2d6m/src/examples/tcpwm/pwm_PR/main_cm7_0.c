/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "cy_project.h"
#include "cy_device_headers.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/
/*SR Mode Constants*/
#define PERIOD_BUFF             0x3000ul    //Change these values as per 8-bit,12,16,24,32
#define PERIOD_VALUE            0x591Eul    //Change these values as per 8-bit,12,16,24,32
#define INITIAL_COUNTER_VALUE   0xACE1ul
#define CC0_VALUE               0x4000ul    //0x40000000,0x00/*We should change these values to get constant high pulse, constant low, and toggling pulse*/
#define CC1_VALUE               0x7FFFFFul


/* PWM PR Mode Configuration def */

#define TCPWMx_GRPx_CNTx_PWM_PR               TCPWM0_GRP0_CNT23
#define PCLK_TCPWMx_CLOCKSx_PWM_PR            PCLK_TCPWM0_CLOCKS23
#define TCPWMx_PERI_CLK_DIVIDER_NO_PWM_PR     0u

/* TCPWM LINE PORT */
#define TCPWMx_LINEx_PORT                      GPIO_PRT6
#define TCPWMx_LINEx_PIN                       1u
#define TCPWMx_LINEx_MUX                       P6_1_TCPWM0_LINE23

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/


/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/
cy_stc_gpio_pin_config_t pwm_line_out_pin_cfg = 
{
    .outVal    = 1ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = TCPWMx_LINEx_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

cy_stc_tcpwm_pwm_config_t const MyPWM_config =
{
    .pwmMode            = CY_TCPWM_PWM_MODE_PSEUDORANDOM,
    .clockPrescaler     = CY_TCPWM_PWM_PRESCALER_DIVBY_16,
    .debug_pause        = false,
    .Cc0MatchMode       = CY_TCPWM_PWM_TR_CTRL2_CLEAR,
    .OverflowMode       = CY_TCPWM_PWM_TR_CTRL2_SET,
    .UnderflowMode      = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .Cc1MatchMode       = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .runMode            = CY_TCPWM_PWM_CONTINUOUS,
    .deadTime           = 0ul,
    .deadTimeComp       = 0ul,
    .countDirection     = 0ul,
    .period             = PERIOD_VALUE,
    .period_buff        = PERIOD_BUFF,
    .enablePeriodSwap   = false,
    .enableLineSelSwap  = 0ul,
    .compare0           = CC0_VALUE,
    .compare0_buff      = 0ul,
    .enableCompare0Swap = false,
    .compare1           = CC1_VALUE,
    .compare1_buff      = 0ul,
    .enableCompare1Swap = false,
    .interruptSources   = 1ul,
    .invertPWMOut       = 0ul,
    .invertPWMOutN      = 0ul,
    .killMode           = CY_TCPWM_PWM_STOP_ON_KILL,
    .switchInputMode    = 3ul,
    .switchInput        = 0ul,
    .reloadInputMode    = 3ul,
    .reloadInput        = 0ul,
    .startInputMode     = 3ul,
    .startInput         = 0ul,
    .kill0InputMode     = 3ul,
    .kill0Input         = 0ul,
    .kill1InputMode     = 3ul,
    .kill1Input         = 0ul,
    .countInputMode     = 3ul,
    .countInput         = 1ul,
};

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/
int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /*--------------------------------*/
    /* Clock Configuration for TCPWMs */
    /*--------------------------------*/
  #if (CY_USE_PSVP == 1u)
    uint32_t sourceFreq = 24000000ul;
  #else
    uint32_t sourceFreq = 80000000ul;
  #endif
    uint32_t targetFreq = 2000000ul;
    uint32_t divNum = (sourceFreq / targetFreq);
    CY_ASSERT((sourceFreq % targetFreq) == 0ul);

    /* Assign a programmable divider  for TCPWM0_GRPx_CNTx_PWM_PR */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_PR, CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM_PR);
    /* Sets the 16-bit divider */
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_PR), CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM_PR, (divNum-1ul));
    /* Enable the divider */
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_PR), CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM_PR);

    /*------------------------------------------------*/
    /* Port Configuration for TCPWM PR, LEDs (GPIOs)  */
    /*------------------------------------------------*/
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT, TCPWMx_LINEx_PIN, &pwm_line_out_pin_cfg);

    /* Initialize TCPWM0_GRPx_CNTx_PWM_PR as PWM-PR Mode & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWMx_GRPx_CNTx_PWM_PR, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWMx_GRPx_CNTx_PWM_PR);
    Cy_Tcpwm_Pwm_SetCounter(TCPWMx_GRPx_CNTx_PWM_PR, INITIAL_COUNTER_VALUE);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_PR);

    for(;;);
}

/* [] END OF FILE */
