/***************************************************************************//**
* \file main_cm7_0.c
*
* \version 1.0
*
* \brief Main example file for CM7
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
    #define USER_LED_PORT           CY_LED8_PORT
    #define USER_LED_PIN            CY_LED8_PIN
    #define USER_LED_PIN_MUX        CY_LED8_PIN_MUX
#else
    #define USER_LED_PORT           CY_USER_LED2_PORT
    #define USER_LED_PIN            CY_USER_LED2_PIN
    #define USER_LED_PIN_MUX        CY_USER_LED2_PIN_MUX 
#endif


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

static const cy_stc_sysint_irq_t irq_cfg = 
{
    .sysIntSrc  = videoss_0_interrupt_mipicsi_IRQn,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = true
};

static uint32_t bitErrStatus, irqErrStatus;
uint32_t *refVramAddr = (uint32_t*) 0x24000000;


static void Cy_Mipicsi2_InterruptHandler(void)
{
    uint32_t maskedIntrStatus;
    
    maskedIntrStatus = Cy_Mipicsi2_GetInterruptStatus(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorCrc);
    if(maskedIntrStatus != 0)
    {
        Cy_Mipicsi2_ClearInterrupt(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorCrc);
    }
    
    maskedIntrStatus = Cy_Mipicsi2_GetInterruptStatus(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccSingle);
    if(maskedIntrStatus != 0)
    {
        Cy_Mipicsi2_ClearInterrupt(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccSingle);
    }
    
    maskedIntrStatus = Cy_Mipicsi2_GetInterruptStatus(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccDouble);
    if(maskedIntrStatus != 0)
    {
        Cy_Mipicsi2_ClearInterrupt(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccDouble);
    }
}

static void Cy_Mipicsi2_SetInterrupt(void)
{
    /* Initialize MipiCsi interrupts */
    CY_ASSERT(Cy_SysInt_InitIRQ(&irq_cfg) == CY_SYSINT_SUCCESS); //GFX_2D
    
    /* Set Handlers */
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, Cy_Mipicsi2_InterruptHandler);

    /* Set Prio/Enable IRQ */
    NVIC_SetPriority(CPUIntIdx3_IRQn, 3);
    NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);
}

int main(void)
{
    SystemInit();

    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache
    
    __enable_irq();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);

    /* Initialize mipi sensor interface */
    Cy_Mipi_Image_Sensor_DeInit();
    Cy_Mipi_Image_Sensor_Init();
    
    /* To initialize videoss clock */
    Cy_GfxEnv_FastInit(false, false, NULL);
    
    /* Setup VideoSS ip for VRAM config */
    CY_SET_REG32(0x40A00000UL, 0x80000000);     // CYREG_VIDEOSS0_VIDEOSSCFG_IPCTRL                                     -> VideoSS ip enable
    CY_SET_REG32(0x40AA0000UL, 0x80000000);     // CYREG_VIDEOSS0_DISENGCFG0_CTL                                        ->
    CY_SET_REG32(0x40AA4000UL, 0x80000000);     // CYREG_VIDEOSS0_DISENGCFG1_CTL
    CY_SET_REG32(0x40A00004UL, 0x00000000);     // CYREG_VIDEOSS0_VIDEOSSCFG_IPCTRLGFX2D
    CY_SET_REG32(0x40A80010UL, 0x00ffffff);     // CYREG_VIDEOSS0_VIDEOIOCFG_INTR_VIDEOIO0_MASK
    CY_SET_REG32(0x40A80014UL, 0x0fffffff);     // CYREG_VIDEOSS0_VIDEOIOCFG_INTR_VIDEOIO1_MASK
    CY_SET_REG32(0x40A80000UL, 0x00ffffff);     // CYREG_VIDEOSS0_VIDEOIOCFG_INTR_VIDEOIO0
    CY_SET_REG32(0x40A80004UL, 0x0fffffff);     // CYREG_VIDEOSS0_VIDEOIOCFG_INTR_VIDEOIO1
    CY_SET_REG32(0x40A80030UL, 0x00ffffff);     // CYREG_VIDEOSS0_VIDEOIOCFG_INTR_VIDEOIO0_SAFETY_MASK
    CY_SET_REG32(0x40A80034UL, 0x0fffffff);     // CYREG_VIDEOSS0_VIDEOIOCFG_INTR_VIDEOIO1_SAFETY_MASK
    CY_SET_REG32(0x40A80020UL, 0x00ffffff);     // CYREG_VIDEOSS0_VIDEOIOCFG_INTR_VIDEOIO0_SAFETY
    CY_SET_REG32(0x40A80024UL, 0x0fffffff);     // CYREG_VIDEOSS0_VIDEOIOCFG_INTR_VIDEOIO1_SAFETY
    CY_SET_REG32(0x40A91040UL, 0x00800010);     // CYREG_VIDEOSS0_COMPENGCFG_EXTDST0_STATIC
    CY_SET_REG32(0x40A910E0UL, 0x00800010);     // CYREG_VIDEOSS0_COMPENGCFG_EXTDST1_STATIC
    CY_SET_REG32(0x40A910A0UL, 0x00800010);     // CYREG_VIDEOSS0_COMPENGCFG_EXTDST4_STATIC
    CY_SET_REG32(0x40A91120UL, 0x00800010);     // CYREG_VIDEOSS0_COMPENGCFG_EXTDST5_STATIC
    CY_SET_REG32(0x40A91160UL, 0x00800010);     // CYREG_VIDEOSS0_COMPENGCFG_STORE4_STATIC
    CY_SET_REG32(0x40A91044UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_EXTDST0_DYNAMIC
    CY_SET_REG32(0x40A910E4UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_EXTDST1_DYNAMIC
    CY_SET_REG32(0x40A910A4UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_EXTDST4_DYNAMIC
    CY_SET_REG32(0x40A91124UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_EXTDST5_DYNAMIC
    CY_SET_REG32(0x40A91164UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_STORE4_DYNAMIC
    CY_SET_REG32(0x40A91240UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_FETCHDECODE0_DYNAMIC
    CY_SET_REG32(0x40A911A0UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_FETCHDECODE4_DYNAMIC
    CY_SET_REG32(0x40A91200UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_FETCHWARP1_DYNAMIC
    CY_SET_REG32(0x40A91260UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_GAMMACOR4_DYNAMIC
    CY_SET_REG32(0x40A91270UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_MATRIX4_DYNAMIC
    CY_SET_REG32(0x40A91290UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_HISTOGRAM4_DYNAMIC
    CY_SET_REG32(0x40A91280UL, 0x01000000);     // CYREG_VIDEOSS0_COMPENGCFG_GPSCALER4_DYNAMIC
    CY_SET_REG32(0x40A912A0UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_LAYERBLEND1_DYNAMIC
    CY_SET_REG32(0x40A912C0UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_LAYERBLEND2_DYNAMIC
    CY_SET_REG32(0x40A912E0UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_LAYERBLEND3_DYNAMIC
    CY_SET_REG32(0x40A91300UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_LAYERBLEND4_DYNAMIC
    CY_SET_REG32(0x40A91320UL, 0x00000000);     // CYREG_VIDEOSS0_COMPENGCFG_LAYERBLEND5_DYNAMIC
    CY_SET_REG32(0x40A91040UL, 0x00800010);     // CYREG_VIDEOSS0_COMPENGCFG_EXTDST0_STATIC
    CY_SET_REG32(0x40A910E0UL, 0x00800010);     // CYREG_VIDEOSS0_COMPENGCFG_EXTDST1_STATIC
    CY_SET_REG32(0x40A910A0UL, 0x00800010);     // CYREG_VIDEOSS0_COMPENGCFG_EXTDST4_STATIC
    CY_SET_REG32(0x40A91120UL, 0x00800010);     // CYREG_VIDEOSS0_COMPENGCFG_EXTDST5_STATI
    CY_SET_REG32(0x40A91160UL, 0x00800000);     // CYREG_VIDEOSS0_COMPENGCFG_STORE4_STATIC
    CY_SET_REG32(0x40A92C00UL, 0x00000000);     // CYREG_VIDEOSS0_EXTDST4_STATICCONTROL
    CY_SET_REG32(0x40A94400UL, 0x00000000);     // CYREG_VIDEOSS0_STORE4_STATICCONTROL
    CY_SET_REG32(0x40A81400UL, 0x00000003);     // CYREG_VIDEOSS0_FRAMECAP_CAPTUREMODE
    CY_SET_REG32(0x40A81420UL, 0x00000000);     // CYREG_VIDEOSS0_FRAMECAP_CSVR
    CY_SET_REG32(0x40A8140CUL, 0x00000000);     // CYREG_VIDEOSS0_FRAMECAP_MDR
    CY_SET_REG32(0x40A8141CUL, 0x00000001);     // CYREG_VIDEOSS0_FRAMECAP_SCR
    CY_SET_REG32(0x40A81408UL, 0x00000000);     // CYREG_VIDEOSS0_FRAMECAP_SPR
    CY_SET_REG32(0x40A81410UL, 0x01df027f);     // CYREG_VIDEOSS0_FRAMECAP_FDR                      -> 640 x 480
    CY_SET_REG32(0x40A81414UL, 0x01df0000);     // CYREG_VIDEOSS0_FRAMECAP_FDR1                     -> 480
    CY_SET_REG32(0x40A81418UL, 0x00000000);     // CYREG_VIDEOSS0_FRAMECAP_KDR
    CY_SET_REG32(0x40A00010UL, 0x00000010);     // CYREG_VIDEOSS0_VIDEOSSCFG_CLKDSP0CFG
    CY_SET_REG32(0x40A00014UL, 0x00000010);     // CYREG_VIDEOSS0_VIDEOSSCFG_CLKDSP1CFG
    CY_SET_REG32(0x40A00018UL, 0x00000001);     // CYREG_VIDEOSS0_VIDEOSSCFG_CAP0CFG
    
    /* Initialize mipi interface */
    Cy_Mipicsi2_SetInterrupt();
    Cy_Mipicsi2_FastInit(VIDEOSS0_MIPICSI0);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorCrc, true);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccSingle, true);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccDouble, true);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqStatusUlpsActiveChange, true);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqStatusUlpsMarkActiveChange, true);
    
    /* Setup VideoSS ip for VRAM config */
    CY_SET_REG32(0x40A80010UL, 0x00077000);     // CYREG_VIDEOSS0_VIDEOIOCFG_INTR_VIDEOIO0_MASK
    CY_SET_REG32(0x40A80014UL, 0x00000000);     // CYREG_VIDEOSS0_VIDEOIOCFG_INTR_VIDEOIO1_MASK
    CY_SET_REG32(0x40A80030UL, 0x00077000);     // CYREG_VIDEOSS0_VIDEOIOCFG_INTR_VIDEOIO0_SAFETY_MASK
    CY_SET_REG32(0x40A80034UL, 0x00000000);     // CYREG_VIDEOSS0_VIDEOIOCFG_INTR_VIDEOIO1_SAFETY_MASK
    CY_SET_REG32(0x40A91164UL, 0x00000009);     // CYREG_VIDEOSS0_COMPENGCFG_STORE4_DYNAMIC
    CY_SET_REG32(0x40A912A0UL, 0x00001403);     // CYREG_VIDEOSS0_COMPENGCFG_LAYERBLEND1_DYNAMIC
    CY_SET_REG32(0x40A912C0UL, 0x00001113);     // CYREG_VIDEOSS0_COMPENGCFG_LAYERBLEND2_DYNAMIC
    CY_SET_REG32(0x40A912E0UL, 0x00000e07);     // CYREG_VIDEOSS0_COMPENGCFG_LAYERBLEND3_DYNAMIC
    CY_SET_REG32(0x40A91300UL, 0x00000e01);     // CYREG_VIDEOSS0_COMPENGCFG_LAYERBLEND4_DYNAMIC
    CY_SET_REG32(0x40A91320UL, 0x00000014);     // CYREG_VIDEOSS0_COMPENGCFG_LAYERBLEND5_DYNAMIC
    CY_SET_REG32(0x40A94004UL, 0x00000000);     // CYREG_VIDEOSS0_EXTSRC4_CLIPWINDOWOFFSET
    CY_SET_REG32(0x40A94008UL, 0x00000000);     // CYREG_VIDEOSS0_EXTSRC4_CLIPWINDOWDIMENSION
    CY_SET_REG32(0x40A9400CUL, 0x08080808);     // CYREG_VIDEOSS0_EXTSRC4_COLORCOMPONENTBITS
    CY_SET_REG32(0x40A94010UL, 0x00081018);     // CYREG_VIDEOSS0_EXTSRC4_COLORCOMPONENTSHIFT
    CY_SET_REG32(0x40A94014UL, 0x00000000);     // CYREG_VIDEOSS0_EXTSRC4_CONSTANTCOLOR
    CY_SET_REG32(0x40A94018UL, 0x00001000);     // CYREG_VIDEOSS0_EXTSRC4_CONTROL                       -> GAMMA APPLY ENABLED
    CY_SET_REG32(0x40A9401CUL, 0x00000000);     // CYREG_VIDEOSS0_EXTSRC4_CONTROLTRIGGER
    CY_SET_REG32(0x40A94408UL, 0x00000000);     // CYREG_VIDEOSS0_STORE4_RINGBUFSTARTADDR
    CY_SET_REG32(0x40A9440CUL, 0x00000000);     // CYREG_VIDEOSS0_STORE4_RINGBUFWRAPADDR
    CY_SET_REG32(0x40A94410UL, 0x24000000);     // CYREG_VIDEOSS0_STORE4_BASEADDRESS
    CY_SET_REG32(0x40A94414UL, 0x200009ff);     // CYREG_VIDEOSS0_STORE4_DESTINATIONBUFFERATTRIBUTES    -> stride = 640 x 4 bytes
    CY_SET_REG32(0x40A94418UL, 0x3fff3fff);     // CYREG_VIDEOSS0_STORE4_DESTINATIONBUFFERDIMENSION
    CY_SET_REG32(0x40A9441CUL, 0x00000000);     // CYREG_VIDEOSS0_STORE4_FRAMEOFFSET
    CY_SET_REG32(0x40A94420UL, 0x08080808);     // CYREG_VIDEOSS0_STORE4_COLORCOMPONENTBITS
    CY_SET_REG32(0x40A94424UL, 0x00081018);     // CYREG_VIDEOSS0_STORE4_COLORCOMPONENTSHIFT
    CY_SET_REG32(0x40A94428UL, 0x00000000);     // CYREG_VIDEOSS0_STORE4_CONTROL
    CY_SET_REG32(0x40A94404UL, 0x00000400);     // CYREG_VIDEOSS0_STORE4_BURSTBUFFERMANAGEMENT
    CY_SET_REG32(0x40A9442CUL, 0x88880001);     // CYREG_VIDEOSS0_STORE4_ENCODECONTROL
    CY_SET_REG32(0x40A94430UL, 0x00000000);     // CYREG_VIDEOSS0_STORE4_DESTINATIONBUFFERLENGTH
    CY_SET_REG32(0x40A94434UL, 0x00000001);     // CYREG_VIDEOSS0_STORE4_START
    CY_SET_REG32(0x40A81404UL, 0x00000001);     // CYREG_VIDEOSS0_FRAMECAP_CTR

    /* Initialize VRAM */
    for(uint32_t i=0; i<0x4B000; i++)
    {
        *refVramAddr++ = 0x00000000;
    }
    
    /* Wakeup the image sensor for stream */
    Cy_Mipi_Image_Sensor_Wakeup();
    
    for(;;)
    {
        bitErrStatus = CY_GET_REG32(0x40AD0210);        // Check for bit error status register
        irqErrStatus = CY_GET_REG32(0x40AD0214);        // Check for irq status register
        if((bitErrStatus == 0) && (irqErrStatus == 0))
        {
            // Check the VRAM content at address 0x24000000
            Cy_SysTick_DelayInUs(50000);
            Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
        }
    }
}


/* [] END OF FILE */
