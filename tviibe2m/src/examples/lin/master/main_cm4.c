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

#include "cy_project.h"
#include "cy_device_headers.h"

  
#if (CY_USE_PSVP == 1)  
    #define SYSTICK_RELOAD_VAL   2400000UL
#else  
    #define SYSTICK_RELOAD_VAL   8000000UL
#endif 

/* Port configuration */
typedef struct
{
    volatile stc_GPIO_PRT_t* portReg;
    uint8_t pinNum;
    cy_stc_gpio_pin_config_t cfg;
}stc_pin_config;

/* Master state type */
typedef enum
{
    LIN_STATE_IDLE,
    LIN_STATE_TX_HEADER,
    LIN_STATE_TX_HEADER_TX_RESPONSE,
    LIN_STATE_TX_HEADER_RX_RESPONSE
}en_lin_master_state_t;

/* LIN message direction type */
typedef enum
{
    LIN_TX_HEADER,
    LIN_RX_RESPONSE,
    LIN_TX_RESPONSE,
}lin_response_direction;

/* LIN message type configuration */
typedef struct
{
    uint8_t id;
    lin_response_direction responseDirection;
    en_lin_checksum_type_t checksumType;
    uint8_t dataLength;
    uint8_t dataBuffer[CY_LIN_DATA_LENGTH_MAX];
} lin_message_context;

/* LIN port configuration */
static const stc_pin_config lin_pin_cfg[] =
{
    /* LIN RX */
    {
        .portReg = CY_LINCH0_RX_PORT, 
        .pinNum  = CY_LINCH0_RX_PIN,
        {
            .outVal = 0,
            .driveMode = CY_GPIO_DM_HIGHZ,
            .hsiom = CY_LINCH0_RX_PIN_MUX,
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
        }
    },
    /* LIN TX */
    {
        .portReg = CY_LINCH0_TX_PORT, 
        .pinNum  = CY_LINCH0_TX_PIN,
        {
            .outVal = 1,
            .driveMode = CY_GPIO_DM_STRONG,
            .hsiom = CY_LINCH0_TX_PIN_MUX ,
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
        }
    }
};

lin_message_context msgContext[] =
{
    {0x01, LIN_RX_RESPONSE, LinChecksumTypeExtended, 8u,},
    {0x02, LIN_TX_RESPONSE, LinChecksumTypeExtended, 8u,},
    {0x10, LIN_RX_RESPONSE, LinChecksumTypeExtended, 1u,},
    {0x11, LIN_TX_RESPONSE, LinChecksumTypeExtended, 1u,},
    {0x20, LIN_TX_HEADER, LinChecksumTypeExtended, 8u,},
};

en_lin_master_state_t lin_state;
uint8_t scheduleIdx;

static void PortInit(void);
static void LIN0_TickHandler(void);
void LIN0_IntHandler(void);
static void SchedulerInit(void);

/*
 * This example is usage for master node.
 * Use 20kbps as a baudrate.
 * This example does:
 *      - Send total 5 IDs. Each ID is sent at per tick.
 *      - Master to Slave response data is copied from slave response.
 *        Slave response (ID=0x01, 0x10) are copied to Master response data (ID=0x02, 0x11)
 * For using message definition, please refer msgContext array.
 */
int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    /* LIN baudrate setting */
    {
        /* Note:
         * LIN IP does oversampling and oversampling count is fixed 16.
         * Therefore LIN baudrate = LIN input clock / 16.
         */
        Cy_SysClk_PeriphAssignDivider(CY_LINCH0_PCLK, CY_SYSCLK_DIV_16_BIT, 0u);
      #if (CY_USE_PSVP == 1)  
        Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0u, 75u);
      #else  
        Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0u, 259u); // 80 MHz / 260 / 16 (oversampling) = 19231 Hz
      #endif 
        Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 0u);
    }

    /* Initialize port settings */
    PortInit();

    /* Register LIN interrupt handler and enable interrupt */
    {
        cy_stc_sysint_irq_t irq_cfg;
        irq_cfg = (cy_stc_sysint_irq_t){
            .sysIntSrc  = CY_LINCH0_IRQN,
            .intIdx     = CPUIntIdx3_IRQn,
            .isEnabled  = true,
        };
        Cy_SysInt_InitIRQ(&irq_cfg);
		Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, LIN0_IntHandler);
        NVIC_SetPriority(CPUIntIdx3_IRQn, 0);
        NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
        NVIC_EnableIRQ(CPUIntIdx3_IRQn);
    }

    /* Initialize LIN */
    {
        stc_lin_config_t config =
        {
            .bMasterMode = true,
            .bLinTransceiverAutoEnable = true,
            .u8BreakFieldLength = 13u,
            .enBreakDelimiterLength = LinBreakDelimiterLength1bits,
            .enStopBit = LinOneStopBit,
            .bFilterEnable = true
        };
        Cy_Lin_Init(CY_LINCH0_TYPE, &config);
        lin_state = LIN_STATE_IDLE;
    }
    
    /* Start scheduling */
    SchedulerInit();

    for(;;)
    {
        /* Do nothing, all operations are handled at IRQ handler */
    }
}

/* Initialize LIN regarding pins */
static void PortInit(void)
{
    for (uint8_t i = 0; i < (sizeof(lin_pin_cfg) / sizeof(lin_pin_cfg[0])); i++)
    {
        Cy_GPIO_Pin_Init(lin_pin_cfg[i].portReg, lin_pin_cfg[i].pinNum, &lin_pin_cfg[i].cfg);
    }
}

/* Initialize SysTick for scheduler */
static void SchedulerInit(void)
{
    Cy_SysTick_Init(CY_SYSTICK_CLOCK_SOURCE_CLK_CPU, SYSTICK_RELOAD_VAL);
    Cy_SysTick_SetCallback(0, LIN0_TickHandler);
    Cy_SysTick_Enable();
}

/* Master schedule handler */
static void LIN0_TickHandler(void)
{
    /* Disable the channel for clearing pending status */
    Cy_Lin_Disable(CY_LINCH0_TYPE);
    /* Re-enable the channel */
    Cy_Lin_Enable(CY_LINCH0_TYPE);

    switch(msgContext[scheduleIdx].responseDirection)
    {
    case LIN_TX_RESPONSE:
        /* Response Direction = Master to Slave */
        Cy_Lin_SetDataLength(CY_LINCH0_TYPE, msgContext[scheduleIdx].dataLength);
        Cy_Lin_SetChecksumType(CY_LINCH0_TYPE, msgContext[scheduleIdx].checksumType);
        Cy_Lin_SetHeader(CY_LINCH0_TYPE, msgContext[scheduleIdx].id);
        Cy_Lin_WriteData(CY_LINCH0_TYPE, msgContext[scheduleIdx].dataBuffer, msgContext[scheduleIdx].dataLength);
        Cy_Lin_SetInterruptMask(CY_LINCH0_TYPE, CY_LIN_INTR_TX_RESPONSE_DONE | CY_LIN_INTR_ALL_ERROR_MASK_MASTER);
        lin_state = LIN_STATE_TX_HEADER_TX_RESPONSE;
        Cy_Lin_SetCmd(CY_LINCH0_TYPE, CY_LIN_CMD_TX_HEADER_TX_RESPONSE);
        break;
    case LIN_RX_RESPONSE:
        /* Response Direction = Slave to Master */
        Cy_Lin_SetDataLength(CY_LINCH0_TYPE, msgContext[scheduleIdx].dataLength);
        Cy_Lin_SetChecksumType(CY_LINCH0_TYPE, msgContext[scheduleIdx].checksumType);
        Cy_Lin_SetHeader(CY_LINCH0_TYPE, msgContext[scheduleIdx].id);
        Cy_Lin_SetInterruptMask(CY_LINCH0_TYPE, CY_LIN_INTR_RX_RESPONSE_DONE | CY_LIN_INTR_ALL_ERROR_MASK_MASTER);
        lin_state = LIN_STATE_TX_HEADER_RX_RESPONSE;
        Cy_Lin_SetCmd(CY_LINCH0_TYPE, CY_LIN_CMD_TX_HEADER_RX_RESPONSE);
        break;
    case LIN_TX_HEADER:
        /* Response Direction = Slave to Slave  */
        Cy_Lin_SetHeader(CY_LINCH0_TYPE, msgContext[scheduleIdx].id);
        Cy_Lin_SetInterruptMask(CY_LINCH0_TYPE, CY_LIN_INTR_TX_HEADER_DONE | CY_LIN_INTR_ALL_ERROR_MASK_MASTER);
        lin_state = LIN_STATE_TX_HEADER;
        Cy_Lin_SetCmd(CY_LINCH0_TYPE, CY_LIN_CMD_TX_HEADER);
        break;
    default:
        break;
    }
    scheduleIdx = (scheduleIdx + 1) % (sizeof(msgContext) / sizeof(msgContext[0]));
}

/* LIN0 IRQ Handler */
void LIN0_IntHandler(void)
{
    uint32_t maskStatus;
    cy_en_lin_status_t apiResponse;

    Cy_Lin_GetInterruptMaskedStatus(CY_LINCH0_TYPE, &maskStatus);
    Cy_Lin_ClearInterrupt(CY_LINCH0_TYPE, maskStatus);    /* Clear all accepted interrupt. */
    Cy_Lin_SetInterruptMask(CY_LINCH0_TYPE, 0uL);         /* Disable all interrupt. */

    if ((maskStatus & CY_LIN_INTR_ALL_ERROR_MASK_MASTER) != 0u)
    {
        /* There are some error */
        /* Handle error if needed. */

        /* Wait for next tick. */
        lin_state = LIN_STATE_IDLE;

        /* Disable the channel to reset LIN status */
        Cy_Lin_Disable(CY_LINCH0_TYPE);
        /* Re-enable the channel */
        Cy_Lin_Enable(CY_LINCH0_TYPE);
    }
    else
    {
        switch(lin_state)
        {
        case LIN_STATE_TX_HEADER:
            /* Tx header complete with no error */
            break;
        case LIN_STATE_TX_HEADER_TX_RESPONSE:
            /* Tx response complete with no error */
            break;
        case LIN_STATE_TX_HEADER_RX_RESPONSE:
            /* Tx header and rx response complete with no error */
            while(1)
            {
                apiResponse = Cy_Lin_ReadData(CY_LINCH0_TYPE, msgContext[scheduleIdx].dataBuffer);
                if(apiResponse == CY_LIN_SUCCESS)
                {
                    break;
                }
            }

            /* For testing
             * Set rx data to tx data. Rx ID + 1 => Tx ID
             */
            memcpy(msgContext[scheduleIdx + 1].dataBuffer, msgContext[scheduleIdx].dataBuffer, CY_LIN_DATA_LENGTH_MAX);
            break;
        default:
            break;
        }
        /* Wait for next tick. */
        lin_state = LIN_STATE_IDLE;
    }
}


/* [] END OF FILE */

