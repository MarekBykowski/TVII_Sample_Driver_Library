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

#define DIM(X) (sizeof(X) / sizeof(X[0]))

/* User setting value */
#if(CY_USE_PSVP == 1)
#define PERI_CLOCK_FREQ 24000000ul /* Please set peri clock frequency value */
#else
#define PERI_CLOCK_FREQ 80000000ul /* Please set peri clock frequency value */
#endif

#if(CY_USE_PSVP == 1)
#define SYSTICK_RELOAD_VAL 240000000UL
#else
#define SYSTICK_RELOAD_VAL 800000000UL
#endif

#define CXPI_BAUDRATE 20000ul   /* Please set baudrate value of CXPI you want */
#define CXPI_OVERSAMPLING 400ul /* The CXPI channel implementation uses a fixed oversampling factor of 400 */

#define CXPI_CH_INSTANCE CY_CXPICH3_TYPE
#define CXPI_CH_IRQ CY_CXPICH3_IRQN
#define CXPI_CH_CLK CY_CXPICH3_PCLK

#define CY_CXPICH_RX_PORT CY_CXPICH3_RX_PORT
#define CY_CXPICH_RX_PIN CY_CXPICH3_RX_PIN
#define CY_CXPICH_RX_PIN_MUX CY_CXPICH3_RX_PIN_MUX

#define CY_CXPICH_TX_PORT CY_CXPICH3_TX_PORT
#define CY_CXPICH_TX_PIN CY_CXPICH3_TX_PIN
#define CY_CXPICH_TX_PIN_MUX CY_CXPICH3_TX_PIN_MUX

#define CY_CXPICH_EN_PORT CY_CXPICH3_EN_PORT
#define CY_CXPICH_EN_PIN CY_CXPICH3_EN_PIN
#define CY_CXPICH_EN_PIN_MUX CY_CXPICH3_EN_PIN_MUX

static void CxpiPortInit(void);
static void CxpiClockInit(void);
static void CxpiIrqInit(void);
static void CxpiSchedulerInit(void);


void ButtonIntHandler(void);
void CxpiInterruptHandler(void);
void CxpiScheduleHandler(void);

void CxpiNotifyError(uint32_t error);
void CxpiNotifyReceivedPID(uint8_t ID);
void CxpipNotifyReceivedResponse(cxpi_frame_context_t *pReceivedFrame);
void CxpipNotifyArbitrationLost(void);

/* Port configuration */
typedef struct {
    volatile stc_GPIO_PRT_t* portReg;
    uint8_t pinNum;
    cy_stc_gpio_pin_config_t cfg;
} stc_pin_config;

/* cxpi port configuration */
static const stc_pin_config cxpi_pin_cfg[] = {
    /* CXPI RX */
    {.portReg = CY_CXPICH_RX_PORT,
        .pinNum = CY_CXPICH_RX_PIN,
        {
            .outVal = 0,
            .driveMode = CY_GPIO_DM_HIGHZ,
            .hsiom = CY_CXPICH_RX_PIN_MUX,
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
        } },
    /* CXPI TX */
    {.portReg = CY_CXPICH_TX_PORT,
        .pinNum = CY_CXPICH_TX_PIN,
        {
            .outVal = 1,
            .driveMode = CY_GPIO_DM_STRONG,
            .hsiom = CY_CXPICH_TX_PIN_MUX,
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
        } },
    /* CXPI EN */
    {.portReg = CY_CXPICH_EN_PORT,
        .pinNum = CY_CXPICH_EN_PIN,
        {
            .outVal = 1,
            .driveMode = CY_GPIO_DM_STRONG,
            .hsiom = CY_CXPICH_EN_PIN_MUX,
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
        } },
};

cy_stc_gpio_pin_config_t user_button_port_pin_cfg = {
    .outVal = 0x00,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .intEdge = CY_GPIO_INTR_FALLING,
    .intMask = 1,
    .vtrip = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel = 0,
    .vohSel = 0,
};

uint8_t AcceptPIDList[3] = {0x6D /* receive PID then transmit responseList[0]*/,
                            0x7D /* receive PID then transmit responseList[1]*/, 
                            0x67 /* receive both PID and response*/};

cxpi_frame_context_t scheduledFrameCtx[] = {
    {
        .id = 0x0A,
    },
    {
        .id = 0x4A,
        .response =
        {.frameIF =
            {
                .datalength = 8u,
                .SleepInd = 0x1u,
                .WakeupInd = 0x1u,
                .counter = 0x03u,
            },
        }
    },
    {
        .id = 0x0F,
    },
    {
        .id = 0x4F,
        .response =
        {.frameIF =
            {
                .datalength = 16u,
                .SleepInd = 0x1u,
                .WakeupInd = 0x1u,
                .counter = 0x03u,
            },
        }
    },
};

cxpi_frame_context_t eventFrameCtx[] = {
    {
        .id = 0x4D,
        .response =
        {.frameIF =
            {
                .datalength = 8u,
                .SleepInd = 0x1u,
                .WakeupInd = 0x1u,
                .counter = 0x03u,
            },
            .dataBuffer = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 }
        }
    },
    {
        .id = 0x5D,
        .response =
        {.frameIF =
            {
                .datalength = 24u,
                .SleepInd = 0x1u,
                .WakeupInd = 0x1u,
                .counter = 0x03u,
            },
            .dataBuffer = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                            0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
                            0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28 }
        }
    }
};

cxpi_response_t reponseList[] = {
    {.frameIF =
            {
                .datalength = 8u,
                .SleepInd = 0x1u,
                .WakeupInd = 0x1u,
                .counter = 0x03u,
            },
        .dataBuffer = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 }
     },
     {.frameIF =
            {
                .datalength = 24u,
                .SleepInd = 0x1u,
                .WakeupInd = 0x1u,
                .counter = 0x03u,
            },
        .dataBuffer = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 
                        0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 
                        0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28 }
     },
              
};

stc_cxpi_config_t stcCxpiConfig = {
    .stcCxpiChCtl0Config =
        {
            .enMode = CXPI_PWM_Mode,
            .bCxpiTransceiverAutoEnable = true,
            .bRxPIDZeroAutoCheckEnable = false,
            .u8IFS = 19u,
            .u8IBS = 3u,
            .enBitErrorIgnore = MESSAGE_TRANFER_NOT_ABORTED,
            .enCxpiMasterMode = CXPI_MASTER_MODE,
        },
    .stcCxpiChCtl1Config =
        {
            .u16TLow1 = 99, 
            .u16TLow0 = 180,
            .u16TOffset = 120,
        },
    .stcCxpiChCtl2Config =
        {
            .u8TimeoutLength = 9u,
            .enTimeoutSel = CxpiTimeoutCheckHdrRes,
        },
    .numberOfAcceptedPID = DIM(AcceptPIDList),
    .pAcceptedPIDList = AcceptPIDList,
    .maximumRetries = 1,
    .pNotifyTrasmittedWakeupPulse = NULL,
    .pNotifyRXFallingEdgeDetected = NULL,
    .pNotifyError = &CxpiNotifyError,
    .pNotifySentPTYPE = NULL,
    .pNotifyReceivedPTYPE = NULL,
    .pNotifyReceivedPID = &CxpiNotifyReceivedPID,
    .pNotifyReceivedResponse = &CxpipNotifyReceivedResponse,
    .pNotifyArbitrationLost = &CxpipNotifyArbitrationLost,
};

stc_CXPI_context_t cxpiCtx;

void ButtonIntHandler(void)
{
    uint32_t intStatus;

    intStatus = Cy_GPIO_GetInterruptStatusMasked(CY_BUTTON1_PORT, CY_BUTTON1_PIN);
    if(intStatus != 0uL) {
        /* If button 1 falling edge detected */
        Cy_GPIO_ClearInterrupt(CY_BUTTON1_PORT, CY_BUTTON1_PIN);
        Cy_CXPI_SendPID(CXPI_CH_INSTANCE, &cxpiCtx, eventFrameCtx[0].id, true,&eventFrameCtx[0].response, true);
    }
}

int main(void)
{
    SystemInit();

    __enable_irq();

    /* Enable CM4. CY_CORTEX_M4_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR);

    Cy_CXPI_Disable(CXPI_CH_INSTANCE);

    /* Initialize CXPI clock */
    CxpiClockInit();
    /* Initialize CXPI interrupt request */
    CxpiIrqInit();
    /* Initialize CXPI port */
    CxpiPortInit();
    
    /* Initialize CXPI channel */
    Cy_CXPI_Init(CXPI_CH_INSTANCE, &stcCxpiConfig,&cxpiCtx);
    Cy_CXPI_Enable(CXPI_CH_INSTANCE);
    
    Cy_CXPI_SetMode(CXPI_CH_INSTANCE, &cxpiCtx, CXPI_STANDBY_MODE);
    Cy_CXPI_SetMode(CXPI_CH_INSTANCE, &cxpiCtx, CXPI_NORMAL_MODE);
    
    /* Initialize schedule */
    CxpiSchedulerInit();

    for(;;) {
    }
}

static void CxpiPortInit(void)
{
    uint32_t k = 0;
    for(k = 0; k < DIM(cxpi_pin_cfg); k++) {
        Cy_GPIO_Pin_Init(cxpi_pin_cfg[k].portReg, cxpi_pin_cfg[k].pinNum, &cxpi_pin_cfg[k].cfg);
    }
    user_button_port_pin_cfg.hsiom = CY_BUTTON1_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_BUTTON1_PORT, CY_BUTTON1_PIN, &user_button_port_pin_cfg);
    user_button_port_pin_cfg.hsiom = CY_BUTTON2_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_BUTTON2_PORT, CY_BUTTON2_PIN, &user_button_port_pin_cfg);
}

static void CxpiClockInit(void)
{
    struct divBF {
        uint32_t div5bit : 5;
        uint32_t div24bit : 24;
        uint32_t rev : 3;
    };

    union {
        struct divBF bf;
        uint32_t u32;
    } div24_5_Util;

    uint64_t culcDivValueTemp;

    culcDivValueTemp = PERI_CLOCK_FREQ;
    culcDivValueTemp <<= 5;
    culcDivValueTemp /= (CXPI_BAUDRATE * CXPI_OVERSAMPLING);
    div24_5_Util.u32 = (uint32_t)culcDivValueTemp;
    Cy_SysClk_PeriphAssignDivider(CXPI_CH_CLK, CY_SYSCLK_DIV_24_5_BIT, 0u);
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, 0u, div24_5_Util.bf.div24bit - 1, div24_5_Util.bf.div5bit);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_24_5_BIT, 0u);
}

static void CxpiIrqInit(void)
{
    /* Setup the IRQ */
    cy_stc_sysint_irq_t irq_cxpi_cfg = {
        .sysIntSrc = CXPI_CH_IRQ, .intIdx = CPUIntIdx2_IRQn, .isEnabled = true,
    };
    Cy_SysInt_InitIRQ(&irq_cxpi_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cxpi_cfg.sysIntSrc, CxpiInterruptHandler);
    NVIC_SetPriority(CPUIntIdx2_IRQn, 1);
    NVIC_ClearPendingIRQ(CPUIntIdx2_IRQn);
    NVIC_EnableIRQ(CPUIntIdx2_IRQn);

    /* Setup IRQ for BUTTON1,2 interrupt */
    cy_stc_sysint_irq_t irq_sw_cfg = {
        .sysIntSrc = CY_BUTTON1_IRQN, .intIdx = CPUIntIdx3_IRQn, .isEnabled = true,
    };
    Cy_SysInt_InitIRQ(&irq_sw_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_sw_cfg.sysIntSrc, ButtonIntHandler);
    NVIC_SetPriority(CPUIntIdx3_IRQn, 3);
    NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);
}

static void CxpiSchedulerInit(void)
{
    Cy_SysTick_Init(CY_SYSTICK_CLOCK_SOURCE_CLK_CPU, SYSTICK_RELOAD_VAL);
    Cy_SysTick_SetCallback(0, CxpiScheduleHandler);
    Cy_SysTick_Enable();
}

void CxpiScheduleHandler(void)
{
    static uint32_t scheduleIdx = 0u;
    switch (scheduledFrameCtx[scheduleIdx].id){
        case 0x0A:
            Cy_CXPI_SendPID(CXPI_CH_INSTANCE, &cxpiCtx, scheduledFrameCtx[scheduleIdx].id, false,&scheduledFrameCtx[scheduleIdx].response, true);
            break;
        case 0x4A:
            Cy_CXPI_SendPID(CXPI_CH_INSTANCE, &cxpiCtx, scheduledFrameCtx[scheduleIdx].id, true,&scheduledFrameCtx[scheduleIdx].response, true);
            break;
        case 0x0F:
            Cy_CXPI_SendPID(CXPI_CH_INSTANCE, &cxpiCtx, scheduledFrameCtx[scheduleIdx].id, false,&scheduledFrameCtx[scheduleIdx].response, true);
            break;
        case 0x4F:
            Cy_CXPI_SendPID(CXPI_CH_INSTANCE, &cxpiCtx, scheduledFrameCtx[scheduleIdx].id, true,&scheduledFrameCtx[scheduleIdx].response, true);
            break;
    }
    scheduleIdx = (scheduleIdx + 1) % DIM(scheduledFrameCtx);
}

void CxpiNotifyError(uint32_t error){
}

void CxpiNotifyReceivedPID(uint8_t frameID){
  switch (frameID){
    case 0x6D:
        Cy_CXPI_SendResp(CXPI_CH_INSTANCE, &cxpiCtx, &reponseList[0]);
        break;
    case 0x7D:
        Cy_CXPI_SendResp(CXPI_CH_INSTANCE, &cxpiCtx, &reponseList[1]);
        break;
  }
}

void CxpipNotifyReceivedResponse(cxpi_frame_context_t *pReceivedFrame){
    switch (pReceivedFrame->id){
    case 0x0A:
        memcpy(scheduledFrameCtx[1].response.dataBuffer, pReceivedFrame->response.dataBuffer,
            scheduledFrameCtx[1].response.frameIF.datalength);
        break;
    case 0x0F:
        memcpy(scheduledFrameCtx[3].response.dataBuffer, pReceivedFrame->response.dataBuffer,
            scheduledFrameCtx[3].response.frameIF.datalength);
        break;
    case 0x67:
        // send back same data with PID increased by 1
        Cy_CXPI_SendPID(CXPI_CH_INSTANCE, &cxpiCtx, (pReceivedFrame->id) + 1, true, &pReceivedFrame->response, true);
        break;
  }
}

void CxpipNotifyArbitrationLost(){
    //Arbitration lost
}

void CxpiInterruptHandler(void)
{
  Cy_CXPI_Interrupt(CXPI_CH_INSTANCE, &cxpiCtx);
}


/* [] END OF FILE */
