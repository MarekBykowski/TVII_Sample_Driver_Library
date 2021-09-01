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

/* JPEG decode only supports in Si Rev.B */
#ifdef CY_MCU_rev_b
    #define JPEG_DECODER_PRESENT        1
#else
    #define JPEG_DECODER_PRESENT        0
#endif 

/* Macro for user LED definition */
#if (CY_USE_PSVP == 1)
    #define USER_LED_PORT               CY_AB_LED_PORT
    #define USER_LED_PIN                CY_AB_LED_PIN
    #define USER_LED_PIN_MUX            CY_AB_LED_PIN_MUX
    // The core frequency is 24MHz. 1200000 / 24MHz = 0.05[s]
    #define USER_LED_TOGGLE_DELAY       1200000 
#else
    #define USER_LED_PORT               CY_USER_LED1_PORT
    #define USER_LED_PIN                CY_USER_LED1_PIN
    #define USER_LED_PIN_MUX            CY_USER_LED1_PIN_MUX 
    // The core frequency is 80MHz. 4000000 / 80MHz = 0.05[s]
    #define USER_LED_TOGGLE_DELAY       4000000 
#endif

/* Macro for compression decompression data size */
#define EDATA_SIZE                      96          // 12 x 8 bytes, captured from vmxjpegdec test result (mvc axi tx logs)
#define PDATA_OFFSET                    64          // since [5:0] is ignored when setting to storeaddres, set (&PDATA + PDATA_OFFSET) to stoeaddress to avoid setting unmapped area.
#define PDATA_SIZE                      (1024 + PDATA_OFFSET)   // bytes, should be enough greater than EDATA_SIZE + PDATA_OFFSET if stride applied cases


/* Reference data for decompression */
const unsigned char JDATA[] = {
    // 4:4:4, width=32, height=1
                                                                      0xff, 0xd8, 0xff, 0xe0, 0x00, // SOI: FFD8
    0x10, 0x4a, 0x46, 0x49, 0x46, 0x00, 0x01, 0x01, 0x01, 0x00, 0x48, 0x00, 0x48, 0x00, 0x00, 0xff,
    0xdb, 0x00, 0x43, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x03, 0x03,
    0x03, 0x03, 0x04, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x06, 0x06, 0x05, 0x06, 0x09, 0x08,
    0x0a, 0x0a, 0x09, 0x08, 0x09, 0x09, 0x0a, 0x0c, 0x0f, 0x0c, 0x0a, 0x0b, 0x0e, 0x0b, 0x09, 0x09,
    0x0d, 0x11, 0x0d, 0x0e, 0x0f, 0x10, 0x10, 0x11, 0x10, 0x0a, 0x0c, 0x12, 0x13, 0x12, 0x10, 0x13,
    0x0f, 0x10, 0x10, 0x10, 0xff, 0xdb, 0x00, 0x43, 0x01, 0x03, 0x03, 0x03, 0x04, 0x03, 0x04, 0x08,
    0x04, 0x04, 0x08, 0x10, 0x0b, 0x09, 0x0b, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xff, 0xc0, 0x00, 0x11, 0x08, 0x00, 0x01,
    0x00, 0x20, 0x03, 0x01, 0x11, 0x00, 0x02, 0x11, 0x01, 0x03, 0x11, 0x01, 0xff, 0xc4, 0x00, 0x1f,
    0x00, 0x00, 0x01, 0x05, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0xff, 0xc4, 0x00,
    0xb5, 0x10, 0x00, 0x02, 0x01, 0x03, 0x03, 0x02, 0x04, 0x03, 0x05, 0x05, 0x04, 0x04, 0x00, 0x00,
    0x01, 0x7d, 0x01, 0x02, 0x03, 0x00, 0x04, 0x11, 0x05, 0x12, 0x21, 0x31, 0x41, 0x06, 0x13, 0x51,
    0x61, 0x07, 0x22, 0x71, 0x14, 0x32, 0x81, 0x91, 0xa1, 0x08, 0x23, 0x42, 0xb1, 0xc1, 0x15, 0x52,
    0xd1, 0xf0, 0x24, 0x33, 0x62, 0x72, 0x82, 0x09, 0x0a, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x25, 0x26,
    0x27, 0x28, 0x29, 0x2a, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x43, 0x44, 0x45, 0x46, 0x47,
    0x48, 0x49, 0x4a, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x63, 0x64, 0x65, 0x66, 0x67,
    0x68, 0x69, 0x6a, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x83, 0x84, 0x85, 0x86, 0x87,
    0x88, 0x89, 0x8a, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0xa2, 0xa3, 0xa4, 0xa5,
    0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xc2, 0xc3,
    0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda,
    0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6,
    0xf7, 0xf8, 0xf9, 0xfa, 0xff, 0xc4, 0x00, 0x1f, 0x01, 0x00, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
    0x07, 0x08, 0x09, 0x0a, 0x0b, 0xff, 0xc4, 0x00, 0xb5, 0x11, 0x00, 0x02, 0x01, 0x02, 0x04, 0x04,
    0x03, 0x04, 0x07, 0x05, 0x04, 0x04, 0x00, 0x01, 0x02, 0x77, 0x00, 0x01, 0x02, 0x03, 0x11, 0x04,
    0x05, 0x21, 0x31, 0x06, 0x12, 0x41, 0x51, 0x07, 0x61, 0x71, 0x13, 0x22, 0x32, 0x81, 0x08, 0x14,
    0x42, 0x91, 0xa1, 0xb1, 0xc1, 0x09, 0x23, 0x33, 0x52, 0xf0, 0x15, 0x62, 0x72, 0xd1, 0x0a, 0x16,
    0x24, 0x34, 0xe1, 0x25, 0xf1, 0x17, 0x18, 0x19, 0x1a, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x35, 0x36,
    0x37, 0x38, 0x39, 0x3a, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x53, 0x54, 0x55, 0x56,
    0x57, 0x58, 0x59, 0x5a, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x73, 0x74, 0x75, 0x76,
    0x77, 0x78, 0x79, 0x7a, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x92, 0x93, 0x94,
    0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xb2,
    0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9,
    0xca, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
    0xe8, 0xe9, 0xea, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xff, 0xda, 0x00, 0x0c, // SOS: FFDA
    0x03, 0x01, 0x00, 0x02, 0x11, 0x03, 0x11, 0x00, 0x3f, 0x00, 0xec, 0xff, 0x00, 0x68, 0x4f, 0xf8,
    0xf0, 0xf1, 0x37, 0xfd, 0x74, 0xf1, 0x07, 0xfe, 0x89, 0x9e, 0xba, 0x78, 0x27, 0xfd, 0xef, 0x1f,
    0xfe, 0x1a, 0x7f, 0x9e, 0x34, 0xf8, 0x4c, 0x8f, 0xed, 0xff, 0x00, 0xd8, 0xcb, 0x0b, 0xff, 0x00,
    0xa9, 0x38, 0xc3, 0xcd, 0x3f, 0x64, 0xff, 0x00, 0xf9, 0x24, 0xb6, 0xff, 0x00, 0xf6, 0x38, 0xdd,
    0x7f, 0xe8, 0xfb, 0x0a, 0xfc, 0xd2, 0x1f, 0xf2, 0x70, 0x30, 0x5f, 0xf5, 0xe2, 0x7f, 0xfa, 0x8f,
    0x50, 0xf4, 0xf8, 0xfb, 0xf8, 0x59, 0x77, 0xfd, 0x81, 0xd5, 0xff, 0x00, 0xd4, 0xe3, 0xd3, 0x7e,
    0x10, 0xff, 0x00, 0xc8, 0xa9, 0xa5, 0xff, 0x00, 0xd8, 0xe9, 0xa1, 0xff, 0x00, 0xe8, 0x77, 0xb5,
    0xfa, 0x46, 0x55, 0xff, 0x00, 0x24, 0xce, 0x0b, 0xfe, 0xdd, 0xff, 0x00, 0xd3, 0x98, 0x73, 0xd4,
    0x8f, 0xfc, 0x96, 0xfc, 0x57, 0xfe, 0x3c, 0x3f, 0xe8, 0x79, 0xb7, 0xc4, 0xcf, 0xf9, 0x16, 0x3c,
    0x25, 0xff, 0x00, 0x61, 0x3b, 0x9f, 0xfd, 0x4a, 0x2e, 0x2b, 0xe2, 0xb8, 0x33, 0xfe, 0x48, 0xbc,
    0xc7, 0xfe, 0xbf, 0xd1, 0xff, 0x00, 0xd4, 0x3a, 0x67, 0xdd, 0xf0, 0xaf, 0xfc, 0x9c, 0x0c, 0x5f,
    0xfd, 0x7a, 0x7f, 0xfa, 0xb0, 0xc3, 0x9f, 0xff, 0xd9 // EOI: FFD9
};

/* Reference data for compression */
const unsigned char EDATA[] = {
//  7     6     5     4     3     2     1     0
    0xE1, 0x7E, 0x83, 0x92, 0x62, 0x2A, 0xA3, 0x7F,
    0x68, 0xAC, 0x39, 0x46, 0x8F, 0xB6, 0xC2, 0x74,
    0x90, 0x53, 0x9D, 0xAD, 0x33, 0x3A, 0x91, 0xAC,
    0x36, 0x71, 0x79, 0x1B, 0x8F, 0x75, 0x41, 0x6B,
    0xDC, 0xC2, 0x3E, 0x6D, 0x90, 0x32, 0x2D, 0xA6,
    0x32, 0x82, 0x78, 0xA8, 0x51, 0xB6, 0x85, 0x51,
    0x6C, 0x4C, 0xC7, 0x67, 0x7A, 0x8C, 0x89, 0x8F,
    0x21, 0x8A, 0xB0, 0x28, 0xEA, 0x7D, 0x8D, 0x7F,
    0x9F, 0xA6, 0x7A, 0x61, 0x77, 0xD7, 0x90, 0x7E,
    0x99, 0x3B, 0xB4, 0x3F, 0x6D, 0x74, 0xDC, 0x1C,
    0x83, 0x86, 0x96, 0x55, 0x6D, 0xC1, 0x3E, 0x75,
    0x83, 0xDF, 0x2C, 0x77, 0x8C, 0x7D, 0x60, 0xCC
};

/* Structure for user led definition */
cy_stc_gpio_pin_config_t user_led_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED_PIN_MUX,                           
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

/* Global variable definition */
uint32_t rdata, pdata_offset;
uint8_t PDATA[PDATA_SIZE];

/* Main function */
int main(void)
{
    SystemInit();
  
    __enable_irq();
    
    /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);
    Cy_SysEnableApplCore(CORE_CM7_1, CY_CORTEX_M7_1_APPL_ADDR);
   
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
    
    
#if (JPEG_DECODER_PRESENT == 1)
    /* Enable JPEG decoder */
    CY_SET_REG32(CYREG_JPEGDEC_CTL, 0x80000000);
    DELAY_CORE_CYCLE(5000);

    /* Set decoder prefetch and store buffer */
    CY_SET_REG32(CYREG_JPEGDEC_HF_AXICTL, 0x00000000);
    CY_SET_REG32(CYREG_JPEGDEC_HF_BURST, 0x00000000);
    CY_SET_REG32(CYREG_JPEGDEC_HF_FETCHBUF0, (uint32_t)&JDATA);                                 // FETCHBASEADDR
    CY_SET_REG32(CYREG_JPEGDEC_HF_FETCHBUF1, 0x00001000);                                       // FETCHLENGTH
    CY_SET_REG32(CYREG_JPEGDEC_HF_STORE0BUF0, (uint32_t)&PDATA + PDATA_OFFSET);                 // STOREBASEADDRESS0
    CY_SET_REG32(CYREG_JPEGDEC_HF_STORE0BUF1, 0x00000080);                                      // STORESTRIDE0: dummy ...not used since using 32x1 jpeg
    CY_SET_REG32(CYREG_JPEGDEC_HF_STORE0BUF2, (uint32_t)&PDATA + PDATA_OFFSET + PDATA_SIZE);    // STORELENGTH0
    CY_SET_REG32(CYREG_JPEGDEC_HF_STORE1BUF0, 0x10000000);                                      // STOREBASEADDRESS1: dummy ...not used since using 4:4:4 (packed)
    CY_SET_REG32(CYREG_JPEGDEC_HF_STORE1BUF1, 0x10000000);                                      // STORESTRIDE1: dummy ...not used since using 4:4:4 (packed)
    CY_SET_REG32(CYREG_JPEGDEC_HF_STORE1BUF2, 0x10000000);                                      // STORELENGTH1: dummy ...not used since using 4:4:4 (packed)
    CY_SET_REG32(CYREG_JPEGDEC_HF_STORECTL, 0x00000000);                                        // no upsampling
    CY_SET_REG32(CYREG_JPEGDEC_DEC_DECODINGOPTION, 0x00000000);                                 // no markerskip, no crop
    CY_SET_REG32(CYREG_JPEGDEC_DEC_INTR_DEC_EN, 0x00000000);                                    // no suspend when marker detected

    rdata = CY_GET_REG32(CYREG_JPEGDEC_HF_FETCHBUF0);
    rdata = CY_GET_REG32(CYREG_JPEGDEC_HF_FETCHBUF1);
    rdata = CY_GET_REG32(CYREG_JPEGDEC_HF_STORE0BUF0);
    rdata = CY_GET_REG32(CYREG_JPEGDEC_HF_STORE0BUF1);
    rdata = CY_GET_REG32(CYREG_JPEGDEC_HF_STORE0BUF2);
    CY_SET_REG32(CYREG_JPEGDEC_HF_INTR_MASK, 0x00000001);

    /* Start IP */
    CY_SET_REG32(CYREG_JPEGDEC_HF_CMD, 0x00000001);
    
    do {
        rdata = CY_GET_REG32(CYREG_JPEGDEC_HF_INTR);
    } while((rdata & 0x00000001) != 0x00000001);    

    /* Check JPED_DEC Data */
    rdata = CY_GET_REG32(CYREG_JPEGDEC_HF_STORE0BUF0);
    pdata_offset = rdata - (uint32_t)&PDATA;

    /* Check compressed data with reference compressed data */
    for(uint16_t i=0; i<EDATA_SIZE; i++)
    {
        if(PDATA[i+pdata_offset] != EDATA[i])
        {
            while(1);
        }
    }
#endif  // #if (JPEG_DECODER_PRESENT = 1)
    
    for(;;)
    {
        /* Delay for 0.05[s] */
        DELAY_CORE_CYCLE(USER_LED_TOGGLE_DELAY);
        Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
    }
}

/* [] END OF FILE */