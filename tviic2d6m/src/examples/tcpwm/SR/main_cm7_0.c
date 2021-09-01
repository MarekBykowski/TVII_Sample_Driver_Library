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

/* Using Shift Register (SR) function of TCPWM, this example copies signal to
   the Line input into PWM output.
   This example uses three ports. One is GPIP output for generating signal to
   be copied from. The second is PWM which will output copied signal.
   And the other is TCPWM Line input to receive GPIO output.
   To make sure the functionality of this example, please connect GPIO output
   and TCPWM Line input ports are seeing CPU board specification you are using.
   After starting this program, please check the output of PWM output using
   an oscilloscope to see the signal has same figure as GPIO output.
   */

#define TCPWMx_GRPx_CNTx_PWM_SR           TCPWM0_GRP0_CNT21
#define PCLK_TCPWMx_CLOCKSx_PWM_SR        PCLK_TCPWM0_CLOCKS21
#define TCPWMx_PERI_CLK_DIVIDER_NO_PWM_SR 0

#define TCPWMx_LINEx_PORT                 GPIO_PRT7
#define TCPWMx_LINEx_PIN                  1u
#define TCPWMx_LINEx_MUX                  P7_1_TCPWM0_LINE21

#define TR_ONE_CNT_NR_USE                 0u // only 0 is applied

// TR_ONE_CNT_INx: x = (256 * GrpNum * 1) + (CntNum * 1) + TR_ONE_CNT_NR_USE
#define TCPWMx_LINEx_IN_PORT              GPIO_PRT6
#define TCPWMx_LINEx_IN_PIN               1u
#define TCPWMx_LINEx_IN_MUX               P6_1_TCPWM0_TR_ONE_CNT_IN21

#define GPIO_TOBE_COPYED_PORT             GPIO_PRT6
#define GPIO_TOBE_COPYED_PIN              3u
#define GPIO_TOBE_COPYED_MUX              P6_3_GPIO

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

cy_stc_gpio_pin_config_t gpio_port_pin_cfg = 
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = GPIO_TOBE_COPYED_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

cy_stc_gpio_pin_config_t pwm_line_out_pin_cfg = 
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = TCPWMx_LINEx_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

cy_stc_gpio_pin_config_t pwm_line_in_pin_cfg = 
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom     = TCPWMx_LINEx_IN_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

cy_stc_tcpwm_sr_config_t const MyPWM_config =
{
    .clockPrescaler     = CY_TCPWM_SR_PRESCALER_DIVBY_1,
    .debug_pause        = false,
    .runMode            = CY_TCPWM_COUNTER_CONTINUOUS,
    .period             = 0x0000ul,
    .period_buff        = 0x0001ul,
    .compare0           = 0x0001ul,
    .compare1           = 0x0001ul,
    .enableCompare0Swap = false,
    .enableCompare1Swap = false,
    .interruptSources   = 0ul,
    .SerialInInputMode  = 3ul, // level detect
    .SerialInInput      = TR_ONE_CNT_NR_USE+2ul, // 0: always "0". 1: always "1". x (above 2): tr_one_cnt_in[offset+x]
    .reloadInputMode    = 3ul,
    .reloadInput        = 0ul,
    .startInputMode     = 3ul,
    .startInput         = 0ul,
    .stopInputMode      = 3ul,
    .stopInput          = 0ul,
    .shiftInputMode     = 3ul,
    .shiftInput         = 1ul,
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
    /* Assign a programmable divider  for TCPWM0_GRPx_CNTx_PWM_SR */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWMx_CLOCKSx_PWM_SR, CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM_SR);
    /* Sets the 16-bit divider */
    Cy_SysClk_PeriphSetDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_SR), CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM_SR, (divNum-1ul));
    /* Enable the divider */
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(PCLK_TCPWMx_CLOCKSx_PWM_SR), CY_SYSCLK_DIV_16_BIT, TCPWMx_PERI_CLK_DIVIDER_NO_PWM_SR);

    /*----------------------------------------*/
    /* Port Configuration for TCPWM PR, GPIO  */
    /*----------------------------------------*/
    Cy_GPIO_Pin_Init(GPIO_TOBE_COPYED_PORT, GPIO_TOBE_COPYED_PIN, &gpio_port_pin_cfg);
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_PORT, TCPWMx_LINEx_PIN, &pwm_line_out_pin_cfg);
    Cy_GPIO_Pin_Init(TCPWMx_LINEx_IN_PORT, TCPWMx_LINEx_IN_PIN, &pwm_line_in_pin_cfg);
    
    /* Initialize TCPWM0_GRPx_CNTx_PWM_SR & Enable */
    Cy_Tcpwm_Sr_Init(TCPWMx_GRPx_CNTx_PWM_SR, &MyPWM_config);
    Cy_Tcpwm_Sr_Enable(TCPWMx_GRPx_CNTx_PWM_SR);
    Cy_Tcpwm_TriggerStart(TCPWMx_GRPx_CNTx_PWM_SR);

    for(;;)
    {
        Cy_GPIO_Inv(GPIO_TOBE_COPYED_PORT, GPIO_TOBE_COPYED_PIN);

        Cy_SysTick_DelayInUs(1000ul);
    }
}

/* [] END OF FILE */