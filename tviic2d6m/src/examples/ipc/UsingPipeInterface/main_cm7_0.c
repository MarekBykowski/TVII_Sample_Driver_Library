/***************************************************************************//**
* \file main_cm7_0.c
*
* \version 1.0
*
* \brief Main example file for CM7_0
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

#if (EXAMPLE_CONFIG_SELECTED == EXAMPLE_CONFIG__CM0P_TO_CM7_0) || (EXAMPLE_CONFIG_SELECTED == EXAMPLE_CONFIG__CM7_1_TO_CM7_0)


#if (CY_USE_PSVP == 1)
    #define USER_LED1_PORT           CY_LED7_PORT
    #define USER_LED1_PIN            CY_LED7_PIN
    #define USER_LED1_PIN_MUX        CY_LED7_PIN_MUX

    #define USER_LED2_PORT           CY_LED8_PORT
    #define USER_LED2_PIN            CY_LED8_PIN
    #define USER_LED2_PIN_MUX        CY_LED8_PIN_MUX
    
    #define USER_LED3_PORT           CY_LED9_PORT
    #define USER_LED3_PIN            CY_LED9_PIN
    #define USER_LED3_PIN_MUX        CY_LED9_PIN_MUX
#else
    #define USER_LED1_PORT           CY_USER_LED1_PORT
    #define USER_LED1_PIN            CY_USER_LED1_PIN
    #define USER_LED1_PIN_MUX        CY_USER_LED1_PIN_MUX

    #define USER_LED2_PORT           CY_USER_LED2_PORT
    #define USER_LED2_PIN            CY_USER_LED2_PIN
    #define USER_LED2_PIN_MUX        CY_USER_LED2_PIN_MUX
    
    #define USER_LED3_PORT           CY_USER_LED3_PORT
    #define USER_LED3_PIN            CY_USER_LED3_PIN
    #define USER_LED3_PIN_MUX        CY_USER_LED3_PIN_MUX
#endif

cy_stc_gpio_pin_config_t user_led1_port_pin_cfg =             
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

cy_stc_gpio_pin_config_t user_led2_port_pin_cfg =             
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

cy_stc_gpio_pin_config_t user_led3_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED3_PIN_MUX,                           
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
        case 0:
            Cy_GPIO_Write(USER_LED1_PORT, USER_LED1_PIN,    1); //Led 0 On 
            Cy_GPIO_Write(USER_LED2_PORT, USER_LED2_PIN,    0); //Led 1 Off
            Cy_GPIO_Write(USER_LED3_PORT, USER_LED3_PIN,    0); //Led 2 Off
            break;
        case 1:
            Cy_GPIO_Write(USER_LED1_PORT, USER_LED1_PIN,    0); //Led 0 Off 
            Cy_GPIO_Write(USER_LED2_PORT, USER_LED2_PIN,    1); //Led 1 On
            Cy_GPIO_Write(USER_LED3_PORT, USER_LED3_PIN,    0); //Led 2 Off
            break;
        case 2:
            Cy_GPIO_Write(USER_LED1_PORT, USER_LED1_PIN,    0); //Led 0 Off 
            Cy_GPIO_Write(USER_LED2_PORT, USER_LED2_PIN,    0); //Led 1 Off
            Cy_GPIO_Write(USER_LED3_PORT, USER_LED3_PIN,    1); //Led 2 On
            break;
        case 3:
            Cy_GPIO_Write(USER_LED1_PORT, USER_LED1_PIN,    1); //Led 0 On 
            Cy_GPIO_Write(USER_LED2_PORT, USER_LED2_PIN,    0); //Led 1 Off
            Cy_GPIO_Write(USER_LED3_PORT, USER_LED3_PIN,    1); //Led 2 On
            break;
        case 4:
            Cy_GPIO_Write(USER_LED1_PORT, USER_LED1_PIN,    1); //Led 0 On 
            Cy_GPIO_Write(USER_LED2_PORT, USER_LED2_PIN,    1); //Led 1 On
            Cy_GPIO_Write(USER_LED3_PORT, USER_LED3_PIN,    0); //Led 2 Off
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

#endif

int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
  #if (EXAMPLE_CONFIG_SELECTED == EXAMPLE_CONFIG__CM0P_TO_CM7_0) || (EXAMPLE_CONFIG_SELECTED == EXAMPLE_CONFIG__CM7_1_TO_CM7_0)
      
    Cy_GPIO_Pin_Init(USER_LED1_PORT, USER_LED1_PIN, &user_led1_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_LED2_PORT, USER_LED2_PIN, &user_led2_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_LED3_PORT, USER_LED3_PIN, &user_led3_port_pin_cfg);

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
    
  #endif

    for(;;)
    {
        /* Do nothing here */
        /* When data comes from the other core, ReceivedCallback is invoked. */
    }
}



/* [] END OF FILE */
