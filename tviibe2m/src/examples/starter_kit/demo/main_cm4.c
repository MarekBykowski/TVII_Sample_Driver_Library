/***************************************************************************//**
* \file main_cm4.c
*
* \version 1.0
*
* \brief Main example file for CM4
*
********************************************************************************
* \copyright
* Copyright 2016-2020, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <stdio.h>

#include "cy_project.h"
#include "cy_device_headers.h"
#include "scenario.h"
#include "semihosting/cy_semihosting.h"

#define TERMINAL_UART           CY_USB_SCB_TYPE
#define TERM_CTRL_PLUS_C        (0x03ul)


                                
typedef enum 
{
    MODE_NEUTRAL     = 0,
    MODE_ADC_CONTROL = 1,
    MODE_INTRRUPT    = 2,
    MODE_TCPWM       = 3,
    MODE_CANFD_NODE0 = 4,
    MODE_CANFD_NODE1 = 5,
    MODE_INVALID,
} en_lowcost_app_mode;

#define MODE_NUM MODE_INVALID

/****************************************/
/********** Neutral functions ***********/
/****************************************/
#define USER_LED_PORT           CY_LED0_PORT
#define USER_LED_PIN            CY_LED0_PIN
#define USER_LED_PIN_MUX        CY_LED0_PIN_MUX 

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =
{
    .outVal    = 0x00,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = USER_LED_PIN_MUX,
    .intEdge   = 0,
    .intMask   = 0,
    .vtrip     = 0,
    .slewRate  = 0,
    .driveSel  = 0,
    .vregEn    = 0,
    .ibufMode  = 0,
    .vtripSel  = 0,
    .vrefSel   = 0,
    .vohSel    = 0,
};

void BeginningNeutral(void)
{
    printf(
        "\nPlease Select Function below!\n"
        "1. ADC control\n"
        "2. Interrupt\n"
        "3. TCPWM control\n"
        "4. CAN FD Tx/Rx (Node 0)\n"
        "5. CAN FD Tx/Rx (Node 1)\n"
        "   * After slecting function, Push Ctrl+C to get back here\n"
        ">>"
    );

    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);

    return;
}

void MainNeutral(void)
{
    Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
    Cy_SysTick_DelayInUs(50000);
    return;
}

void EndingNeutral(void)
{
    Cy_GPIO_Port_Deinit(USER_LED_PORT);
    return;
}

void NextModeFromNeutral(uint8_t recievedData)
{
    switch(recievedData)
    {
    case '1':
        SetNextMode(MODE_ADC_CONTROL);
    break;
    case '2':
        SetNextMode(MODE_INTRRUPT);
    break;
    case '3':
        SetNextMode(MODE_TCPWM);
    break;
    case '4':
        SetNextMode(MODE_CANFD_NODE0);
    break;
    case '5':
        SetNextMode(MODE_CANFD_NODE1);
    break;
    default:
        // Do nothing
    break;
    }
    return;
}

/******* End of Neutral functions *******/

/****************************************/
/**********   ADC functions   ***********/
/****************************************/
#if defined (REV_A0)
    // SAR reference
    #define BB_POTI_ANALOG_MACRO       SAR0
    #define BB_POTI_ANALOG_CHANNEL_NR  CY_ADC_PIN_ADDRESS_AN0
    #define BB_POTI_ANALOG_PCLK        PCLK_PASS_CLOCK_SAR0
    /* TCPWM_LINE0 */
    #define TCPWM_LINEx_PORT                GPIO_PRT7
    #define TCPWM_LINEx_PIN                 (1u)
    #define TCPWM_LINEx_MUX                 P7_1_TCPWM_LINE15
#else // REV_B0
    #define BB_POTI_ANALOG_MACRO       CY_ADC_POT_MACRO
    #define BB_POTI_ANALOG_CHANNEL_NR  CY_ADC_POT_IN_NO
    #define BB_POTI_ANALOG_PCLK        CY_ADC_POT_PCLK
    /* TCPWM_LINE0 */
    #define TCPWM_LINEx_PORT                GPIO_PRT12
    #define TCPWM_LINEx_PIN                 (2u)
    #define TCPWM_LINEx_MUX                 P12_2_TCPWM0_LINE38
#endif

const cy_stc_adc_config_t adcConfig =
{
    .preconditionTime    = 0u,
    .powerupTime         = 0u,
    .enableIdlePowerDown = false,
    .msbStretchMode      = CY_ADC_MSB_STRETCH_MODE_1CYCLE,
    .enableHalfLsbConv   = 0u,
    .sarMuxEnable        = true,
    .adcEnable           = true,
    .sarIpEnable         = true,
};

const cy_stc_adc_channel_config_t adcChannelConfig =
{
    .triggerSelection          = CY_ADC_TRIGGER_OFF,
    .channelPriority           = 0,
    .preenptionType            = CY_ADC_PREEMPTION_FINISH_RESUME,
    .isGroupEnd                = true,
    .doneLevel                 = CY_ADC_DONE_LEVEL_PULSE,
    .pinAddress                = BB_POTI_ANALOG_CHANNEL_NR,
    .portAddress               = CY_ADC_PORT_ADDRESS_SARMUX0,
    .extMuxSelect              = 0,
    .extMuxEnable              = true,
    .preconditionMode          = CY_ADC_PRECONDITION_MODE_OFF,
    .overlapDiagMode           = CY_ADC_OVERLAP_DIAG_MODE_OFF,
    .sampleTime                = 60,
    .calibrationValueSelect    = CY_ADC_CALIBRATION_VALUE_REGULAR,
    .postProcessingMode        = CY_ADC_POST_PROCESSING_MODE_NONE,
    .resultAlignment           = CY_ADC_RESULT_ALIGNMENT_RIGHT,
    .signExtention             = CY_ADC_SIGN_EXTENTION_UNSIGNED,
    .averageCount              = 0,
    .rightShift                = 0,
    .rangeDetectionMode        = CY_ADC_RANGE_DETECTION_MODE_INSIDE_RANGE,
    .rangeDetectionLoThreshold = 0x0000,
    .rangeDetectionHiThreshold = 0x0FFF,
    .mask.grpDone              = true,
    .mask.grpCancelled         = false,
    .mask.grpOverflow          = false,
    .mask.chRange              = false,
    .mask.chPulse              = false,
    .mask.chOverflow           = false,
};

#define ADC_16BIT_DIVIDER_NUM (0u)
void BeginningAdcControl(void)
{
    printf(
      "ADC control selected!\n"
      "Monitoring the Voltage of Volume SW:         "
    );

    Cy_SysClk_PeriphAssignDivider(BB_POTI_ANALOG_PCLK, CY_SYSCLK_DIV_16_BIT, ADC_16BIT_DIVIDER_NUM);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, ADC_16BIT_DIVIDER_NUM, 5u);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, ADC_16BIT_DIVIDER_NUM);

    Cy_Adc_Init(BB_POTI_ANALOG_MACRO, &adcConfig);
    Cy_Adc_Channel_Init(&BB_POTI_ANALOG_MACRO->CH[0], &adcChannelConfig);
    Cy_Adc_Channel_Enable(&BB_POTI_ANALOG_MACRO->CH[0]);

    return;
}

void MainAdcControl(void)
{
    cy_stc_adc_interrupt_source_t intrSource = { false };
    uint16_t resultBuff;
    cy_stc_adc_ch_status_t statusBuff;
    char stringBuf[9];

    /* Issue SW trigger */
    Cy_Adc_Channel_SoftwareTrigger(&BB_POTI_ANALOG_MACRO->CH[0]);

    // Wait for completion
    while(intrSource.grpDone == false)
    {
        Cy_Adc_Channel_GetInterruptMaskedStatus(&BB_POTI_ANALOG_MACRO->CH[0], &intrSource);
    }

    Cy_Adc_Channel_GetResult(&BB_POTI_ANALOG_MACRO->CH[0], &resultBuff, &statusBuff);

    // Clear the flag
    Cy_Adc_Channel_ClearInterruptStatus(&BB_POTI_ANALOG_MACRO->CH[0], &intrSource);

    float voltage = 5.0 * (float)resultBuff / 4095.0;
    snprintf(stringBuf, 5, "%04f", voltage);
    strcat(stringBuf," [V]");
    printf("\b\b\b\b\b\b\b\b");
    printf(stringBuf);

    Cy_SysTick_DelayInUs(50000);

    return;
}

void EndingAdcControl(void)
{
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, ADC_16BIT_DIVIDER_NUM);

    Cy_Adc_DeInit(BB_POTI_ANALOG_MACRO);
    Cy_Adc_Channel_Disable(&BB_POTI_ANALOG_MACRO->CH[0]);
    Cy_Adc_Channel_DeInit(&BB_POTI_ANALOG_MACRO->CH[0]);
    printf("\n");

    return;
}

void NextModeFromAdcControl(uint8_t recievedData)
{
    switch(recievedData)
    {
    case TERM_CTRL_PLUS_C:
        SetNextMode(MODE_NEUTRAL);
    break;
    default:
        // Do nothing
    break;
    }
    return;
}

/*******  End of ADC functions   *******/


/****************************************/
/********* Interrupt functions **********/
/****************************************/
#define CY_USER_BUTTON_PORT  CY_CB_BUTTON_PORT
#define CY_USER_BUTTON_PIN   CY_CB_BUTTON_PIN
#define CY_USER_BUTTON_MUX   CY_CB_BUTTON_PIN_MUX
#define CY_USER_BUTTON_INTR  CY_CB_BUTTON_IRQN

cy_stc_gpio_pin_config_t user_button_port_pin_cfg = 
{
    .outVal    = 0x00,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom     = CY_USER_BUTTON_MUX,
    .intEdge   = CY_GPIO_INTR_BOTH,
    .intMask   = 1,
    .vtrip     = 0,
    .slewRate  = 0,
    .driveSel  = 0,
    .vregEn    = 0,
    .ibufMode  = 0,
    .vtripSel  = 0,
    .vrefSel   = 0,
    .vohSel    = 0,
};

cy_stc_sysint_irq_t button_irq_cfg =
{
    /* Setup GPIO for BUTTON1/2 interrupt */
    .sysIntSrc  = CY_USER_BUTTON_INTR,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = false,
};

void ButtonInterHandler(void)
{
    uint32_t intStatus;
    static char message[128] = "                ";

    intStatus = Cy_GPIO_GetInterruptStatusMasked(CY_USER_BUTTON_PORT, CY_USER_BUTTON_PIN);
    if (intStatus != 0uL)
    {
        if(Cy_GPIO_Read(CY_USER_BUTTON_PORT, CY_USER_BUTTON_PIN) == 1u)
        {
            strcat(message,"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
                                       "Button released!");
        }
        else
        {
            strcat(message,"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
                                       "Button pushed!  ");
        }
        printf(message);
        printf(""); // Wait above message being output
        strcpy(message, "");
    }
    Cy_GPIO_ClearInterrupt(CY_USER_BUTTON_PORT, CY_USER_BUTTON_PIN);

}
void BeginningInterrupt(void)
{

    printf("Interrupt selected\n"
                               "Monitoring the button interrupt: " );

    NVIC_EnableIRQ(button_irq_cfg.intIdx);
    Cy_SysInt_EnableIRQ(button_irq_cfg.sysIntSrc);
    Cy_GPIO_Pin_Init(CY_USER_BUTTON_PORT, CY_USER_BUTTON_PIN, &user_button_port_pin_cfg);

    return;
}

void MainInterrupt(void)
{

    // Do nothing
    return;
}

void EndingInterrupt(void)
{
    Cy_GPIO_Port_Deinit(CY_USER_BUTTON_PORT);
    Cy_SysInt_DisableIRQ(button_irq_cfg.sysIntSrc);
    NVIC_DisableIRQ(button_irq_cfg.intIdx);
    printf("\n");
    return;
}

void NextModeFromInterrupt(uint8_t recievedData)
{
    switch(recievedData)
    {
    case TERM_CTRL_PLUS_C:
        SetNextMode(MODE_NEUTRAL);
    break;
    default:
        // Do nothing
    break;
    }
    return;
}

/***  End of Interrupt functions   ****/


/****************************************/
/**********  TCPWM functions  ***********/
/****************************************/
/* PWM PR Mode Configuration def */
#define TCPWM0_GRPx_CNTx_PWM            TCPWM0_GRP0_CNT38
#define PCLK_TCPWM0_CLOCKSx_PWM         PCLK_TCPWM0_CLOCKS38
#define TCPWM_PERI_CLK_DIVIDER_NO_PWM   1u



cy_stc_gpio_pin_config_t pin_cfg1 = 
{
    .outVal    = 0x01u,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom     = TCPWM_LINEx_MUX ,
    .intEdge   = 0u,
    .intMask   = 0u,
    .vtrip     = 0u,
    .slewRate  = 0u,
    .driveSel  = 0u,
    .vregEn    = 0u,
    .ibufMode  = 0u,
    .vtripSel  = 0u,
    .vrefSel   = 0u,
    .vohSel    = 0u,
};

#define PWM_CLEAR_VALUE (1000 - 1)   // 1,000,000Hz / 1000 = 1,000Hz (PWM frequency)
cy_stc_tcpwm_pwm_config_t const MyPWM_config =
{
    .pwmMode            = CY_TCPWM_PWM_MODE_PWM,
    .countDirection     = 0, // Count UP
    .clockPrescaler     = CY_TCPWM_PWM_PRESCALER_DIVBY_2, // 2,000,000 / 2 = 1,000,000Hz
    .debug_pause        = 0uL,
    .Cc0MatchMode       = CY_TCPWM_PWM_TR_CTRL2_CLEAR,
    .OverflowMode       = CY_TCPWM_PWM_TR_CTRL2_SET,
    .UnderflowMode      = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .Cc1MatchMode       = CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE,
    .deadTime           = 0uL,
    .deadTimeComp       = 0uL,
    .runMode            = CY_TCPWM_PWM_CONTINUOUS,
    .period             = PWM_CLEAR_VALUE,
    .period_buff        = 0,
    .enablePeriodSwap   = false,
    .compare0           = 500,                           // 500 / 1000 = 0.5 (PWM duty)
    .compare1           = 0,
    .enableCompare0Swap = true,
    .enableCompare1Swap = false,
    .interruptSources   = 0uL,
    .invertPWMOut       = 0uL,
    .invertPWMOutN      = 0uL,
    .killMode           = CY_TCPWM_PWM_STOP_ON_KILL,
    .switchInputMode    = 3uL,
    .switchInput        = 0uL,
    .reloadInputMode    = 3uL,
    .reloadInput        = 0uL,
    .startInputMode     = 3uL,
    .startInput         = 0uL,
    .kill0InputMode     = 3uL,
    .kill0Input         = 0uL,
    .kill1InputMode     = 3uL,
    .kill1Input         = 0uL,
    .countInputMode     = 3uL,
    .countInput         = 1uL,
};

void BeginningTcpwm(void)
{
    printf("Controling brightness of the LED by the volume SW");

    /***********************/
    /**** TCPWM Setting ****/
    /***********************/
    /* Assign a programmable divider  for TCPWM0_GRPx_CNTx_PWM_PR */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKSx_PWM, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM);
    Cy_SysClk_PeriphSetDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM, 39u); // Divider 39 --> 80MHz / (39+1) = 2MHz
    Cy_SysClk_PeriphEnableDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM);

    Cy_GPIO_Pin_Init(TCPWM_LINEx_PORT, TCPWM_LINEx_PIN, &pin_cfg1);

    /* Initialize TCPWM0_GRPx_CNTx_PWM_PR as PWM-PR Mode & Enable */
    Cy_Tcpwm_Pwm_Init(TCPWM0_GRPx_CNTx_PWM, &MyPWM_config);
    Cy_Tcpwm_Pwm_Enable(TCPWM0_GRPx_CNTx_PWM);
    Cy_Tcpwm_TriggerStart(TCPWM0_GRPx_CNTx_PWM);

    /***********************/
    /****  ADC Setting  ****/
    /***********************/
    Cy_SysClk_PeriphAssignDivider(BB_POTI_ANALOG_PCLK, CY_SYSCLK_DIV_16_BIT, ADC_16BIT_DIVIDER_NUM);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, ADC_16BIT_DIVIDER_NUM, 5u);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, ADC_16BIT_DIVIDER_NUM);

    Cy_Adc_Init(BB_POTI_ANALOG_MACRO, &adcConfig);
    Cy_Adc_Channel_Init(&BB_POTI_ANALOG_MACRO->CH[0], &adcChannelConfig);
    Cy_Adc_Channel_Enable(&BB_POTI_ANALOG_MACRO->CH[0]);


    return;
}

void MainTcpwm(void)
{
    uint32_t nextComp0;
    cy_stc_adc_interrupt_source_t intrSource = { false };
    uint16_t resultBuff;
    cy_stc_adc_ch_status_t statusBuff;

    /* Issue SW trigger */
    Cy_Adc_Channel_SoftwareTrigger(&BB_POTI_ANALOG_MACRO->CH[0]);

    // Wait for completion
    while(intrSource.grpDone == false)
    {
        Cy_Adc_Channel_GetInterruptMaskedStatus(&BB_POTI_ANALOG_MACRO->CH[0], &intrSource);
    }

    Cy_Adc_Channel_GetResult(&BB_POTI_ANALOG_MACRO->CH[0], &resultBuff, &statusBuff);

    // Clear the flag
    Cy_Adc_Channel_ClearInterruptStatus(&BB_POTI_ANALOG_MACRO->CH[0], &intrSource);

    nextComp0 = (PWM_CLEAR_VALUE * resultBuff) / 0x0FFF;
    Cy_Tcpwm_Pwm_SetCompare0_Buff(TCPWM0_GRPx_CNTx_PWM, nextComp0);
    Cy_Tcpwm_TriggerCapture0(TCPWM0_GRPx_CNTx_PWM); // Note!!: Capture0 trigger becomes switch event!!
    return;
}

void EndingTcpwm(void)
{

    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_PWM);
    Cy_Tcpwm_Pwm_Disable(TCPWM0_GRPx_CNTx_PWM);
    Cy_Tcpwm_Pwm_DeInit(TCPWM0_GRPx_CNTx_PWM);

    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, ADC_16BIT_DIVIDER_NUM);
    Cy_Adc_DeInit(BB_POTI_ANALOG_MACRO);
    Cy_Adc_Channel_Disable(&BB_POTI_ANALOG_MACRO->CH[0]);
    Cy_Adc_Channel_DeInit(&BB_POTI_ANALOG_MACRO->CH[0]);
    printf("\n");
    return;
}

void NextModeFromTcpwm(uint8_t recievedData)
{
    switch(recievedData)
    {
    case TERM_CTRL_PLUS_C:
        SetNextMode(MODE_NEUTRAL);
    break;
    default:
        // Do nothing
    break;
    }
    return;
}

/******* End of TCPWM functions  *******/

/****************************************/
/********* CANFD Tx functions ***********/
/****************************************/


// If you use Canoe to check CANFD function, please set USER_TOOL_VECTOR_CANOE as "1"
#define USER_TOOL_VECTOR_CANOE 1

#define CANFD_8_BIT_DIVDER_NUM (0u)

void CanfdInterruptHandler(void);
void CAN_RxMsgCallback(bool bRxFifoMsg, uint8_t u8MsgBufOrRxFifoNum, cy_stc_canfd_msg_t* pstcCanFDmsg);
void CAN_RxFifoWithTopCallback(uint8_t u8FifoNum, uint8_t u8BufferSizeInWord, uint32_t* pu32RxBuf);

/* CAN configuration */
static const cy_stc_id_filter_t stdIdFilter[] = 
{
    CANFD_CONFIG_STD_ID_FILTER_CLASSIC_RXBUFF(0x010u, 0u),      /* ID=0x010, store into RX buffer Idx0 */
    CANFD_CONFIG_STD_ID_FILTER_CLASSIC_RXBUFF(0x010u, 0u),      /* ID=0x011, store into RX buffer Idx0 */
};

cy_stc_canfd_config_t const canCfg = 
{
    .txCallback     = NULL, // Unused.
    .rxCallback     = CAN_RxMsgCallback,
    .rxFifoWithTopCallback = NULL, //CAN_RxFifoWithTopCallback,
    .statusCallback = NULL, // Un-supported now
    .errorCallback  = NULL, // Un-supported now

    .canFDMode      = true, // Use CANFD mode
    // 40 MHz
    .bitrate        =       // Nominal bit rate settings (sampling point = 75%)
    {
        .prescaler      = 20 - 1u,  // cclk/20, When using 250kbps, 1bit = 8tq
        .timeSegment1   = 5u - 1u,  // tseg1 = 5tq
        .timeSegment2   = 2u - 1u,  // tseg2 = 2tq
        .syncJumpWidth  = 2u - 1u,  // sjw   = 2tq
    },
    
    .fastBitrate    =       // Fast bit rate settings (sampling point = 75%)
    {
        .prescaler      = 10u - 1u,  // cclk/10, When using 500kbps, 1bit = 8tq
        .timeSegment1   = 5u - 1u,  // tseg1 = 5tq,
        .timeSegment2   = 2u - 1u,  // tseg2 = 2tq
        .syncJumpWidth  = 2u - 1u,  // sjw   = 2tq
    },
    .tdcConfig      =       // Transceiver delay compensation, unused.
    {
        .tdcEnabled     = false,
        .tdcOffset      = 0,
        .tdcFilterWindow= 0,
    },
    .sidFilterConfig    =   // Standard ID filter
    {
        .numberOfSIDFilters = sizeof(stdIdFilter) / sizeof(stdIdFilter[0]),
        .sidFilter          = stdIdFilter,
    },
    .extidFilterConfig  =   // Extended ID filter
    {
        .numberOfEXTIDFilters   = 0,
        .extidFilter            = NULL,
        .extIDANDMask           = 0x1fffffff,   // No pre filtering.
    },
    .globalFilterConfig =   // Global filter
    {
        .nonMatchingFramesStandard = CY_CANFD_ACCEPT_IN_RXFIFO_0,  // Reject none match IDs
        .nonMatchingFramesExtended = CY_CANFD_ACCEPT_IN_RXFIFO_1,  // Reject none match IDs
        .rejectRemoteFramesStandard = true, // No remote frame
        .rejectRemoteFramesExtended = true, // No remote frame
    },
    .rxBufferDataSize = CY_CANFD_BUFFER_DATA_SIZE_64,
    .rxFifo1DataSize  = CY_CANFD_BUFFER_DATA_SIZE_64,
    .rxFifo0DataSize  = CY_CANFD_BUFFER_DATA_SIZE_64,
    .txBufferDataSize = CY_CANFD_BUFFER_DATA_SIZE_64,
    .rxFifo0Config    = // RX FIFO0, unused.
    {
        .mode = CY_CANFD_FIFO_MODE_BLOCKING,
        .watermark = 10u,
        .numberOfFifoElements = 8u,
        .topPointerLogicEnabled = false,
    },
    .rxFifo1Config    = // RX FIFO1, unused.
    {
        .mode = CY_CANFD_FIFO_MODE_BLOCKING,
        .watermark = 10u,
        .numberOfFifoElements = 8u,
        .topPointerLogicEnabled = false, // true,
    },
    .noOfRxBuffers  = 4u,
    .noOfTxBuffers  = 4u,
};

static const cy_stc_gpio_pin_config_t canPinRx =
{
    .outVal    = 0,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom     = CY_CANFD0_RX_MUX,
    .intEdge   = 0,
    .intMask   = 0,
    .vtrip     = 0,
    .slewRate  = 0,
    .driveSel  = 0,
    .vregEn    = 0,
    .ibufMode  = 0,
    .vtripSel  = 0,
    .vrefSel   = 0,
    .vohSel    = 0,
};

static const cy_stc_gpio_pin_config_t canPinTx =
{
    .outVal    = 1,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom     = CY_CANFD0_TX_MUX,
    .intEdge   = 0,
    .intMask   = 0,
    .vtrip     = 0,
    .slewRate  = 0,
    .driveSel  = 0,
    .vregEn    = 0,
    .ibufMode  = 0,
    .vtripSel  = 0,
    .vrefSel   = 0,
    .vohSel    = 0,
};

#if USER_TOOL_VECTOR_CANOE == 1
static void SetISOFormat(cy_pstc_canfd_type_t canfd)
{
    /* Now a ch configured as CANFD is working. */
    canfd->M_TTCAN.unCCCR.stcField.u1INIT = 1;
    while(canfd->M_TTCAN.unCCCR.stcField.u1INIT != 1);
        /* Cancel protection by setting CCE */
    canfd->M_TTCAN.unCCCR.stcField.u1CCE = 1;
    canfd->M_TTCAN.unCCCR.stcField.u1NISO = 1;

    canfd->M_TTCAN.unCCCR.stcField.u1INIT = 0;
    while(canfd->M_TTCAN.unCCCR.stcField.u1INIT != 0);
}
#endif

cy_stc_sysint_irq_t const canfdIrqCfg =
{
    .sysIntSrc  = CY_CANFD0_IRQN,
    .intIdx     = CPUIntIdx4_IRQn,
    .isEnabled  = false,
};

/* CANFD reception callback */
cy_stc_canfd_msg_t recievedCanFDmsg = { 0 };
cy_stc_canfd_msg_t transmitCanFDmsg = 
{
    .canFDFormat               = true,
    .idConfig.extended         = false,
    .idConfig.identifier       = 0x011,
    .dataConfig.dataLengthCode = 15,
    .dataConfig.data[0]        = 0x00000000,
    .dataConfig.data[1]        = 0x70190819,
    .dataConfig.data[2]        = 0x33332222,
    .dataConfig.data[3]        = 0x33332222,
    .dataConfig.data[4]        = 0x55554444,
    .dataConfig.data[5]        = 0x77776666,
    .dataConfig.data[6]        = 0x99998888,
    .dataConfig.data[7]        = 0xBBBBAAAA,
    .dataConfig.data[8]        = 0xDDDDCCCC,
    .dataConfig.data[9]        = 0xFFFFEEEE,
    .dataConfig.data[10]       = 0x78563412,
    .dataConfig.data[11]       = 0x00000000,
    .dataConfig.data[12]       = 0x11111111,
    .dataConfig.data[13]       = 0x22222222,
    .dataConfig.data[14]       = 0x33333333,
    .dataConfig.data[15]       = 0x44444444,
};

void CAN_RxMsgCallback(bool bRxFifoMsg, uint8_t u8MsgBufOrRxFifoNum, cy_stc_canfd_msg_t* pstcCanFDmsg)
{
    /* Copy the recieved structure */
    recievedCanFDmsg = *pstcCanFDmsg;
}

void CAN_RxFifoWithTopCallback(uint8_t u8FifoNum, uint8_t   u8BufferSizeInWord, uint32_t* pu32RxBuf)
{
    /*TODO*/
}

/* CANFD intrerrupt handler */
void CanfdInterruptHandler(void)
{
    /* Just invoking */
    Cy_CANFD_IrqHandler(CY_CANFD0_TYPE);
}

volatile uint32_t readPSR;
void BeginningCanfd(void)
{
    printf(
      "CAN FD Tx/Rx mode selected!\n"
    );
    printf("");

    /***********************/
    /****  ADC Setting  ****/
    /***********************/
    Cy_SysClk_PeriphAssignDivider(BB_POTI_ANALOG_PCLK, CY_SYSCLK_DIV_16_BIT, ADC_16BIT_DIVIDER_NUM);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, ADC_16BIT_DIVIDER_NUM, 5u);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, ADC_16BIT_DIVIDER_NUM);

    Cy_Adc_Init(BB_POTI_ANALOG_MACRO, &adcConfig);
    Cy_Adc_Channel_Init(&BB_POTI_ANALOG_MACRO->CH[0], &adcChannelConfig);
    Cy_Adc_Channel_Enable(&BB_POTI_ANALOG_MACRO->CH[0]);

    /***********************/
    /**** CANFD Setting ****/
    /***********************/
    Cy_SysClk_PeriphAssignDivider(CY_CANFD0_PCLK, CY_SYSCLK_DIV_8_BIT, CANFD_8_BIT_DIVDER_NUM);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, CANFD_8_BIT_DIVDER_NUM, 1u); // 80 / 2 = 40 MHz
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_8_BIT, CANFD_8_BIT_DIVDER_NUM);

    Cy_GPIO_Pin_Init(CY_CANFD0_RX_PORT, CY_CANFD0_RX_PIN, &canPinRx);
    Cy_GPIO_Pin_Init(CY_CANFD0_TX_PORT, CY_CANFD0_TX_PIN, &canPinTx);

    NVIC_EnableIRQ(canfdIrqCfg.intIdx);
    Cy_SysInt_EnableIRQ(canfdIrqCfg.sysIntSrc);

    Cy_CANFD_Init(CY_CANFD0_TYPE, &canCfg);

#if USER_TOOL_VECTOR_CANOE == 1
    SetISOFormat(CY_CANFD0_TYPE);
#endif

    return;
}

void BeginningCanfdNode0(void)
{
    BeginningCanfd();
    printf(
      "Please set the function of the counterpart as CAN FD Tx/Rx Node0!\n"
    );
    return;
}

void BeginningCanfdNode1(void)
{
    BeginningCanfd();
    printf(
      "Please set the function of the counterpart as CAN FD Tx/Rx Node1!\n"
    );

    return;
}

void MainCanfd(uint16_t id)
{
    cy_stc_adc_interrupt_source_t intrSource = { false };
    uint16_t resultBuff;
    cy_stc_adc_ch_status_t statusBuff;
    char message[128];
    char messageTemp[32];

    /* Issue SW trigger */
    Cy_Adc_Channel_SoftwareTrigger(&BB_POTI_ANALOG_MACRO->CH[0]);

    // Wait for completion
    while(intrSource.grpDone == false)
    {
        Cy_Adc_Channel_GetInterruptMaskedStatus(&BB_POTI_ANALOG_MACRO->CH[0], &intrSource);
    }

    Cy_Adc_Channel_GetResult(&BB_POTI_ANALOG_MACRO->CH[0], &resultBuff, &statusBuff);

    // Clear the flag
    Cy_Adc_Channel_ClearInterruptStatus(&BB_POTI_ANALOG_MACRO->CH[0], &intrSource);

    transmitCanFDmsg.dataConfig.data[0] = resultBuff;
    transmitCanFDmsg.idConfig.identifier = id;
    cy_en_canfd_status_t status;
    status = Cy_CANFD_UpdateAndTransmitMsgBuffer(CY_CANFD0_TYPE, 0, &transmitCanFDmsg);
    if(status != CY_CANFD_SUCCESS)
    {
        resultBuff = 0ul;
    }
    else
    {
//        while(CANFD0_CH0_M_TTCAN->unIR.stcField.u1TC == 0);
        /* CAN FD message succesfully transmitted. */
        /* Clear the Transmission completed flag */
//        CANFD0_CH0_M_TTCAN->unIR.stcField.u1TC = 1UL;
    }

    snprintf(message,     31, "Transmitted data: 0x%08X  ", resultBuff);
    snprintf(messageTemp, 31, "Recieved data   : 0x%08X  ", recievedCanFDmsg.dataConfig.data[0]);
    strcat(message, messageTemp);
    strcat(message, "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    printf(message);

    Cy_SysTick_DelayInUs(50000);

    return;
}

void MainCanfdNode0(void)
{
    MainCanfd(0x10);
}

void MainCanfdNode1(void)
{
    MainCanfd(0x11);
}

void EndingCanfd(void)
{
    // The UART uses these ports.
//    Cy_GPIO_Port_Deinit(CY_CANFD_RX_PORT);
//    Cy_GPIO_Port_Deinit(CY_CANFD_TX_PORT);

    Cy_SysInt_DisableIRQ(canfdIrqCfg.sysIntSrc);
    NVIC_DisableIRQ(canfdIrqCfg.intIdx);

    Cy_CANFD_DeInit(CY_CANFD0_TYPE);
    recievedCanFDmsg.dataConfig.data[0] = 0ul;
    CANFD0_CH0_M_TTCAN->unIR.u32Register = 0xFFFFFFFFul;
    (void)CANFD0_CH0_M_TTCAN->unPSR.u32Register;
    (void)CANFD0_CH0_M_TTCAN->unECR.u32Register;

    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_8_BIT, CANFD_8_BIT_DIVDER_NUM);


    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, ADC_16BIT_DIVIDER_NUM);
    Cy_Adc_DeInit(BB_POTI_ANALOG_MACRO);
    Cy_Adc_Channel_Disable(&BB_POTI_ANALOG_MACRO->CH[0]);
    Cy_Adc_Channel_DeInit(&BB_POTI_ANALOG_MACRO->CH[0]);

    printf("\n");

    return;
}

void NextModeCanfd(uint8_t recievedData)
{
    switch(recievedData)
    {
    case TERM_CTRL_PLUS_C:
        SetNextMode(MODE_NEUTRAL);
    break;
    default:
        // Do nothing
    break;
    }
    return;
}

/***** End of CANFD functions  *****/

/****************************************/
/*********  Invalid functions ***********/
/****************************************/
void BeginningInvalid(void)
{
    return;
}

void MainInvalid(void)
{
    // Do nothing
    return;
}

void EndingInvalid(void)
{
    printf("Welcome!\n");
    return;
}

void NextModeFromInvalid(uint8_t recievedData)
{
    switch(recievedData)
    {
    case TERM_CTRL_PLUS_C:
        SetNextMode(MODE_NEUTRAL);
    break;
    default:
        // Do nothing
    break;
    }
    return;
}

/***** End of invalid functions  *****/
typedef void (*ModeControl)(uint8_t);

ModeControl LowCostBoardModeControl[MODE_NUM+1] =
{
    NextModeFromNeutral,
    NextModeFromAdcControl,
    NextModeFromInterrupt,
    NextModeFromTcpwm,
    NextModeCanfd,
    NextModeCanfd,
    NextModeFromInvalid
};


stc_scenario LowCostBoardSenario[MODE_NUM+1] =
{
    {.beginLoutine = BeginningNeutral,    .cyclicLoutine = MainNeutral,    .endLoutine = EndingNeutral},
    {.beginLoutine = BeginningAdcControl, .cyclicLoutine = MainAdcControl, .endLoutine = EndingAdcControl},
    {.beginLoutine = BeginningInterrupt,  .cyclicLoutine = MainInterrupt,  .endLoutine = EndingInterrupt},
    {.beginLoutine = BeginningTcpwm,      .cyclicLoutine = MainTcpwm,      .endLoutine = EndingTcpwm},
    {.beginLoutine = BeginningCanfdNode0, .cyclicLoutine = MainCanfdNode0, .endLoutine = EndingCanfd},
    {.beginLoutine = BeginningCanfdNode1, .cyclicLoutine = MainCanfdNode1, .endLoutine = EndingCanfd},
    {.beginLoutine = BeginningInvalid,    .cyclicLoutine = MainInvalid,    .endLoutine = EndingInvalid},
};

void IpcCallBackCm4(uint32_t data)
{
    LowCostBoardModeControl[GetCurrentMode()](data);
}

void UartInterruptHandler(void)
{
    static uint8_t inData;
    static uint8_t prevData = 0xFF; // invalid data

    uint32_t maskedRx = Cy_SCB_GetRxInterruptStatusMasked(CY_USB_SCB_TYPE);
    uint32_t maskedTx = Cy_SCB_GetTxInterruptStatusMasked(CY_USB_SCB_TYPE);

    if((maskedRx & SCB_INTR_RX_TRIGGER_Msk) != 0UL)
    {
        while(0UL == Cy_SCB_UART_GetArray(CY_USB_SCB_TYPE, &inData, 1));
        if(inData == TERM_CTRL_PLUS_C)
        {
            LowCostBoardModeControl[GetCurrentMode()](inData);
            prevData = 0xFF;
        }
        else if(inData == '\n' || inData == '\r')
        {
            LowCostBoardModeControl[GetCurrentMode()](prevData);
            prevData = 0xFF;
        }
        else if(inData >= '1' && inData <= '5')
        {
            if(GetCurrentMode() == MODE_NEUTRAL)
            {
                Cy_SCB_UART_PutArray(CY_USB_SCB_TYPE, &inData, 1);
                Cy_SCB_UART_PutArray(CY_USB_SCB_TYPE, "\b", 1);
            }
            prevData = inData;
        }
    }

    Cy_SCB_ClearRxInterrupt(CY_USB_SCB_TYPE, maskedRx);
    Cy_SCB_ClearTxInterrupt(CY_USB_SCB_TYPE, maskedTx);
}

cy_stc_sysint_irq_t const uartIrqCfg =
{
    .sysIntSrc  = CY_USB_SCB_UART_IRQN, /* Use interrupt LINE0 */
    .intIdx     = CPUIntIdx5_IRQn,
    .isEnabled  = true,
};

int main(void)
{
    SystemInit();

    __enable_irq();

    Cy_SysInt_InitIRQ(&button_irq_cfg);
    Cy_SysInt_SetSystemIrqVector(button_irq_cfg.sysIntSrc, ButtonInterHandler);
    NVIC_SetPriority(button_irq_cfg.intIdx, 3);

    Cy_SysInt_InitIRQ(&canfdIrqCfg);
    Cy_SysInt_SetSystemIrqVector(canfdIrqCfg.sysIntSrc, CanfdInterruptHandler);
    NVIC_SetPriority(canfdIrqCfg.intIdx, 4);

    Cy_SysInt_InitIRQ(&uartIrqCfg);
    Cy_SysInt_SetSystemIrqVector(uartIrqCfg.sysIntSrc, UartInterruptHandler);
    NVIC_SetPriority(uartIrqCfg.intIdx, 5);
    NVIC_EnableIRQ(uartIrqCfg.intIdx);

    Cy_Semihosting_InitAll(TERMINAL_UART, 115200, NULL, false);

    printf("Welcome!!\n");

    ScenarioInit(MODE_NEUTRAL, MODE_NUM); 
    
    for(;;)
    {
        ScenarioMain(LowCostBoardSenario);
    }
}

/* [] END OF FILE */
