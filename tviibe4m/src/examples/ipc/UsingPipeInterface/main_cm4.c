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
#include "example_config.h"


cy_stc_gpio_pin_config_t user_led6_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = CY_LED6_PIN_MUX,                           
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

cy_stc_gpio_pin_config_t user_led7_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = CY_LED7_PIN_MUX,                           
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

cy_stc_gpio_pin_config_t user_led8_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = CY_LED8_PIN_MUX,                           
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

cy_stc_gpio_pin_config_t user_led9_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = CY_LED9_PIN_MUX,                           
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

typedef struct
{
    uint32_t clientId;  /* PIPE I/F internal use area. Must be first element of the structure. */
    uint32_t LedData;
} custom_data_t;

custom_data_t pipeData;

/* Call when the other end point send the data to this end point */
void ReceivedCallback(uint32_t *msgPtr)
{
    /* New data comes */
    custom_data_t * data = (custom_data_t *)msgPtr;
    pipeData.LedData = data->LedData;
    switch(pipeData.LedData)
    {
        case 0u:    /* OFF OFF OFF OFF */
            Cy_GPIO_Write(CY_LED6_PORT, CY_LED6_PIN, 0u);
            Cy_GPIO_Write(CY_LED7_PORT, CY_LED7_PIN, 0u);
            Cy_GPIO_Write(CY_LED8_PORT, CY_LED8_PIN, 0u);
            Cy_GPIO_Write(CY_LED9_PORT, CY_LED9_PIN, 0u);
            break;
        case 1u:    /* ON OFF OFF OFF */
            Cy_GPIO_Write(CY_LED6_PORT, CY_LED6_PIN, 1u);
            Cy_GPIO_Write(CY_LED7_PORT, CY_LED7_PIN, 0u);
            Cy_GPIO_Write(CY_LED8_PORT, CY_LED8_PIN, 0u);
            Cy_GPIO_Write(CY_LED9_PORT, CY_LED9_PIN, 0u);
            break;
        case 2u:    /* OFF ON OFF OFF */
            Cy_GPIO_Write(CY_LED6_PORT, CY_LED6_PIN, 0u);
            Cy_GPIO_Write(CY_LED7_PORT, CY_LED7_PIN, 1u);
            Cy_GPIO_Write(CY_LED8_PORT, CY_LED8_PIN, 0u);
            Cy_GPIO_Write(CY_LED9_PORT, CY_LED9_PIN, 0u);
            break;
        case 3u:    /* OFF OFF ON OFF */
            Cy_GPIO_Write(CY_LED6_PORT, CY_LED6_PIN, 0u);
            Cy_GPIO_Write(CY_LED7_PORT, CY_LED7_PIN, 0u);
            Cy_GPIO_Write(CY_LED8_PORT, CY_LED8_PIN, 1u);
            Cy_GPIO_Write(CY_LED9_PORT, CY_LED9_PIN, 0u);
            break;
        case 4u:    /* OFF OFF OFF ON */
            Cy_GPIO_Write(CY_LED6_PORT, CY_LED6_PIN, 0u);
            Cy_GPIO_Write(CY_LED7_PORT, CY_LED7_PIN, 0u);
            Cy_GPIO_Write(CY_LED8_PORT, CY_LED8_PIN, 0u);
            Cy_GPIO_Write(CY_LED9_PORT, CY_LED9_PIN, 1u);
            break;
        default:
            break;
    }
}


cy_stc_ipc_pipe_config_t pipeConfig = 
{
    .epIndexForThisCpu = EP_INDEX_THIS_CPU,
    .epConfigData      = CY_IPC_PIPE_ENDPOINTS_DEFAULT_CONFIG,
};


int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(CY_LED6_PORT, CY_LED6_PIN, &user_led6_port_pin_cfg);
    Cy_GPIO_Pin_Init(CY_LED7_PORT, CY_LED7_PIN, &user_led7_port_pin_cfg);
    Cy_GPIO_Pin_Init(CY_LED8_PORT, CY_LED8_PIN, &user_led8_port_pin_cfg);
    Cy_GPIO_Pin_Init(CY_LED9_PORT, CY_LED9_PIN, &user_led9_port_pin_cfg);

    /* Initialize PIPE */
    Cy_IPC_Pipe_Init(&pipeConfig);

    /* Register data received callback */
    Cy_IPC_Pipe_RegisterCallback
    (
        ReceivedCallback,
        0x01u  /* Accept Client ID = 0x01 */
    );

    /* Already registered the handler to the system interrup structure.
     * So just enable corresponding IRQ channel.
     */
    NVIC_ClearPendingIRQ(pipeConfig.epConfigData[EP_INDEX_THIS_CPU].ipcCpuIntIdx);
    NVIC_EnableIRQ(pipeConfig.epConfigData[EP_INDEX_THIS_CPU].ipcCpuIntIdx);

    for(;;)
    {
        /* Do nothing here */
        /* When data comes from the other core, ReceivedCallback is invoked. */
    }
}



/* [] END OF FILE */
