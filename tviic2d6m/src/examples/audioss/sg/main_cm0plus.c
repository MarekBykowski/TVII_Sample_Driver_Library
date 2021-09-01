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

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "cy_project.h"
#include "cy_device_headers.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/
// Check BSP for port details


static cy_stc_gpio_pin_config_t SG_port_pin_cfg =
{
    .outVal   = 0,
    .intEdge  = 0,
    .intMask  = 0,
    .vtrip    = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn   = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel  = 0,
    .vohSel   = 0,
};

cy_stc_sysint_irq_t sg_irq_cfg =
{
    .sysIntSrc  = CY_AUDIOSS_SG0_IRQ_IRQN,
    .intIdx     = CPUIntIdx4_IRQn,
    .isEnabled  = true,
};

cy_stc_sg_config_t  sgInitConfig =
{
    .clkDiv        = 0, // 24MHz clock
    .clkSel        = CY_SG_SEL_SRSS_CLK0,
    .format        = CY_SG_SEPARATE,    // CY_SG_SEPARATE: for separate volume and frequency format (two signals)
                                        // CY_SG_COMBINED: for combined volume and frequency format (one signal on Tone port).
};

cy_sg_segment_t  sgContext;

cy_stc_sg_segment_t  userData[] = 
{   /* Set timePeriod, timeNR, tonePeriod, toneHigh, amplPeriod, amplHigh, stepSize, stepValid for each segment. */
    {.timePeriod = 255/255, .timeNR = 0, .tonePeriod = 255, .toneHigh = 255/2, .amplPeriod = 255, .amplHigh = 255, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/254, .timeNR = 0, .tonePeriod = 254, .toneHigh = 254/2, .amplPeriod = 255, .amplHigh = 254, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/253, .timeNR = 0, .tonePeriod = 253, .toneHigh = 253/2, .amplPeriod = 255, .amplHigh = 253, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/252, .timeNR = 0, .tonePeriod = 252, .toneHigh = 252/2, .amplPeriod = 255, .amplHigh = 252, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/251, .timeNR = 0, .tonePeriod = 251, .toneHigh = 251/2, .amplPeriod = 255, .amplHigh = 251, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/250, .timeNR = 0, .tonePeriod = 250, .toneHigh = 250/2, .amplPeriod = 255, .amplHigh = 250, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/249, .timeNR = 0, .tonePeriod = 249, .toneHigh = 249/2, .amplPeriod = 255, .amplHigh = 249, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/248, .timeNR = 0, .tonePeriod = 248, .toneHigh = 248/2, .amplPeriod = 255, .amplHigh = 248, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/247, .timeNR = 0, .tonePeriod = 247, .toneHigh = 247/2, .amplPeriod = 255, .amplHigh = 247, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/246, .timeNR = 0, .tonePeriod = 246, .toneHigh = 246/2, .amplPeriod = 255, .amplHigh = 246, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/245, .timeNR = 0, .tonePeriod = 245, .toneHigh = 245/2, .amplPeriod = 255, .amplHigh = 245, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/244, .timeNR = 0, .tonePeriod = 244, .toneHigh = 244/2, .amplPeriod = 255, .amplHigh = 244, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/243, .timeNR = 0, .tonePeriod = 243, .toneHigh = 243/2, .amplPeriod = 255, .amplHigh = 243, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/242, .timeNR = 0, .tonePeriod = 242, .toneHigh = 242/2, .amplPeriod = 255, .amplHigh = 242, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/241, .timeNR = 0, .tonePeriod = 241, .toneHigh = 241/2, .amplPeriod = 255, .amplHigh = 241, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/240, .timeNR = 0, .tonePeriod = 240, .toneHigh = 240/2, .amplPeriod = 255, .amplHigh = 240, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/239, .timeNR = 0, .tonePeriod = 239, .toneHigh = 239/2, .amplPeriod = 255, .amplHigh = 239, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/238, .timeNR = 0, .tonePeriod = 238, .toneHigh = 238/2, .amplPeriod = 255, .amplHigh = 238, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/237, .timeNR = 0, .tonePeriod = 237, .toneHigh = 237/2, .amplPeriod = 255, .amplHigh = 237, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/236, .timeNR = 0, .tonePeriod = 236, .toneHigh = 236/2, .amplPeriod = 255, .amplHigh = 236, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/235, .timeNR = 0, .tonePeriod = 235, .toneHigh = 235/2, .amplPeriod = 255, .amplHigh = 235, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/234, .timeNR = 0, .tonePeriod = 234, .toneHigh = 234/2, .amplPeriod = 255, .amplHigh = 234, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/233, .timeNR = 0, .tonePeriod = 233, .toneHigh = 233/2, .amplPeriod = 255, .amplHigh = 233, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/232, .timeNR = 0, .tonePeriod = 232, .toneHigh = 232/2, .amplPeriod = 255, .amplHigh = 232, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/231, .timeNR = 0, .tonePeriod = 231, .toneHigh = 231/2, .amplPeriod = 255, .amplHigh = 231, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/230, .timeNR = 0, .tonePeriod = 230, .toneHigh = 230/2, .amplPeriod = 255, .amplHigh = 230, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/229, .timeNR = 0, .tonePeriod = 229, .toneHigh = 229/2, .amplPeriod = 255, .amplHigh = 229, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/228, .timeNR = 0, .tonePeriod = 228, .toneHigh = 228/2, .amplPeriod = 255, .amplHigh = 228, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/227, .timeNR = 0, .tonePeriod = 227, .toneHigh = 227/2, .amplPeriod = 255, .amplHigh = 227, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/226, .timeNR = 0, .tonePeriod = 226, .toneHigh = 226/2, .amplPeriod = 255, .amplHigh = 226, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/225, .timeNR = 0, .tonePeriod = 225, .toneHigh = 225/2, .amplPeriod = 255, .amplHigh = 225, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/224, .timeNR = 0, .tonePeriod = 224, .toneHigh = 224/2, .amplPeriod = 255, .amplHigh = 224, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/223, .timeNR = 0, .tonePeriod = 223, .toneHigh = 223/2, .amplPeriod = 255, .amplHigh = 223, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/222, .timeNR = 0, .tonePeriod = 222, .toneHigh = 222/2, .amplPeriod = 255, .amplHigh = 222, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/221, .timeNR = 0, .tonePeriod = 221, .toneHigh = 221/2, .amplPeriod = 255, .amplHigh = 221, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/220, .timeNR = 0, .tonePeriod = 220, .toneHigh = 220/2, .amplPeriod = 255, .amplHigh = 220, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/219, .timeNR = 0, .tonePeriod = 219, .toneHigh = 219/2, .amplPeriod = 255, .amplHigh = 219, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/218, .timeNR = 0, .tonePeriod = 218, .toneHigh = 218/2, .amplPeriod = 255, .amplHigh = 218, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/217, .timeNR = 0, .tonePeriod = 217, .toneHigh = 217/2, .amplPeriod = 255, .amplHigh = 217, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/216, .timeNR = 0, .tonePeriod = 216, .toneHigh = 216/2, .amplPeriod = 255, .amplHigh = 216, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/215, .timeNR = 0, .tonePeriod = 215, .toneHigh = 215/2, .amplPeriod = 255, .amplHigh = 215, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/214, .timeNR = 0, .tonePeriod = 214, .toneHigh = 214/2, .amplPeriod = 255, .amplHigh = 214, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/213, .timeNR = 0, .tonePeriod = 213, .toneHigh = 213/2, .amplPeriod = 255, .amplHigh = 213, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/212, .timeNR = 0, .tonePeriod = 212, .toneHigh = 212/2, .amplPeriod = 255, .amplHigh = 212, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/211, .timeNR = 0, .tonePeriod = 211, .toneHigh = 211/2, .amplPeriod = 255, .amplHigh = 211, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/210, .timeNR = 0, .tonePeriod = 210, .toneHigh = 210/2, .amplPeriod = 255, .amplHigh = 210, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/209, .timeNR = 0, .tonePeriod = 209, .toneHigh = 209/2, .amplPeriod = 255, .amplHigh = 209, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/208, .timeNR = 0, .tonePeriod = 208, .toneHigh = 208/2, .amplPeriod = 255, .amplHigh = 208, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/207, .timeNR = 0, .tonePeriod = 207, .toneHigh = 207/2, .amplPeriod = 255, .amplHigh = 207, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/206, .timeNR = 0, .tonePeriod = 206, .toneHigh = 206/2, .amplPeriod = 255, .amplHigh = 206, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/205, .timeNR = 0, .tonePeriod = 205, .toneHigh = 205/2, .amplPeriod = 255, .amplHigh = 205, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/204, .timeNR = 0, .tonePeriod = 204, .toneHigh = 204/2, .amplPeriod = 255, .amplHigh = 204, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/203, .timeNR = 0, .tonePeriod = 203, .toneHigh = 203/2, .amplPeriod = 255, .amplHigh = 203, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/202, .timeNR = 0, .tonePeriod = 202, .toneHigh = 202/2, .amplPeriod = 255, .amplHigh = 202, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/201, .timeNR = 0, .tonePeriod = 201, .toneHigh = 201/2, .amplPeriod = 255, .amplHigh = 201, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/200, .timeNR = 0, .tonePeriod = 200, .toneHigh = 200/2, .amplPeriod = 255, .amplHigh = 200, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/199, .timeNR = 0, .tonePeriod = 199, .toneHigh = 199/2, .amplPeriod = 255, .amplHigh = 199, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/198, .timeNR = 0, .tonePeriod = 198, .toneHigh = 198/2, .amplPeriod = 255, .amplHigh = 198, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/197, .timeNR = 0, .tonePeriod = 197, .toneHigh = 197/2, .amplPeriod = 255, .amplHigh = 197, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/196, .timeNR = 0, .tonePeriod = 196, .toneHigh = 196/2, .amplPeriod = 255, .amplHigh = 196, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/195, .timeNR = 0, .tonePeriod = 195, .toneHigh = 195/2, .amplPeriod = 255, .amplHigh = 195, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/194, .timeNR = 0, .tonePeriod = 194, .toneHigh = 194/2, .amplPeriod = 255, .amplHigh = 194, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/193, .timeNR = 0, .tonePeriod = 193, .toneHigh = 193/2, .amplPeriod = 255, .amplHigh = 193, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/192, .timeNR = 0, .tonePeriod = 192, .toneHigh = 192/2, .amplPeriod = 255, .amplHigh = 192, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/191, .timeNR = 0, .tonePeriod = 191, .toneHigh = 191/2, .amplPeriod = 255, .amplHigh = 191, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/190, .timeNR = 0, .tonePeriod = 190, .toneHigh = 190/2, .amplPeriod = 255, .amplHigh = 190, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/189, .timeNR = 0, .tonePeriod = 189, .toneHigh = 189/2, .amplPeriod = 255, .amplHigh = 189, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/188, .timeNR = 0, .tonePeriod = 188, .toneHigh = 188/2, .amplPeriod = 255, .amplHigh = 188, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/187, .timeNR = 0, .tonePeriod = 187, .toneHigh = 187/2, .amplPeriod = 255, .amplHigh = 187, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/186, .timeNR = 0, .tonePeriod = 186, .toneHigh = 186/2, .amplPeriod = 255, .amplHigh = 186, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/185, .timeNR = 0, .tonePeriod = 185, .toneHigh = 185/2, .amplPeriod = 255, .amplHigh = 185, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/184, .timeNR = 0, .tonePeriod = 184, .toneHigh = 184/2, .amplPeriod = 255, .amplHigh = 184, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/183, .timeNR = 0, .tonePeriod = 183, .toneHigh = 183/2, .amplPeriod = 255, .amplHigh = 183, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/182, .timeNR = 0, .tonePeriod = 182, .toneHigh = 182/2, .amplPeriod = 255, .amplHigh = 182, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/181, .timeNR = 0, .tonePeriod = 181, .toneHigh = 181/2, .amplPeriod = 255, .amplHigh = 181, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/180, .timeNR = 0, .tonePeriod = 180, .toneHigh = 180/2, .amplPeriod = 255, .amplHigh = 180, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/179, .timeNR = 0, .tonePeriod = 179, .toneHigh = 179/2, .amplPeriod = 255, .amplHigh = 179, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/178, .timeNR = 0, .tonePeriod = 178, .toneHigh = 178/2, .amplPeriod = 255, .amplHigh = 178, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/177, .timeNR = 0, .tonePeriod = 177, .toneHigh = 177/2, .amplPeriod = 255, .amplHigh = 177, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/176, .timeNR = 0, .tonePeriod = 176, .toneHigh = 176/2, .amplPeriod = 255, .amplHigh = 176, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/175, .timeNR = 0, .tonePeriod = 175, .toneHigh = 175/2, .amplPeriod = 255, .amplHigh = 175, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/174, .timeNR = 0, .tonePeriod = 174, .toneHigh = 174/2, .amplPeriod = 255, .amplHigh = 174, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/173, .timeNR = 0, .tonePeriod = 173, .toneHigh = 173/2, .amplPeriod = 255, .amplHigh = 173, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/172, .timeNR = 0, .tonePeriod = 172, .toneHigh = 172/2, .amplPeriod = 255, .amplHigh = 172, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/171, .timeNR = 0, .tonePeriod = 171, .toneHigh = 171/2, .amplPeriod = 255, .amplHigh = 171, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/170, .timeNR = 0, .tonePeriod = 170, .toneHigh = 170/2, .amplPeriod = 255, .amplHigh = 170, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/169, .timeNR = 0, .tonePeriod = 169, .toneHigh = 169/2, .amplPeriod = 255, .amplHigh = 169, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/168, .timeNR = 0, .tonePeriod = 168, .toneHigh = 168/2, .amplPeriod = 255, .amplHigh = 168, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/167, .timeNR = 0, .tonePeriod = 167, .toneHigh = 167/2, .amplPeriod = 255, .amplHigh = 167, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/166, .timeNR = 0, .tonePeriod = 166, .toneHigh = 166/2, .amplPeriod = 255, .amplHigh = 166, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/165, .timeNR = 0, .tonePeriod = 165, .toneHigh = 165/2, .amplPeriod = 255, .amplHigh = 165, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/164, .timeNR = 0, .tonePeriod = 164, .toneHigh = 164/2, .amplPeriod = 255, .amplHigh = 164, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/163, .timeNR = 0, .tonePeriod = 163, .toneHigh = 163/2, .amplPeriod = 255, .amplHigh = 163, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/162, .timeNR = 0, .tonePeriod = 162, .toneHigh = 162/2, .amplPeriod = 255, .amplHigh = 162, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/161, .timeNR = 0, .tonePeriod = 161, .toneHigh = 161/2, .amplPeriod = 255, .amplHigh = 161, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/160, .timeNR = 0, .tonePeriod = 160, .toneHigh = 160/2, .amplPeriod = 255, .amplHigh = 160, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/159, .timeNR = 0, .tonePeriod = 159, .toneHigh = 159/2, .amplPeriod = 255, .amplHigh = 159, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/158, .timeNR = 0, .tonePeriod = 158, .toneHigh = 158/2, .amplPeriod = 255, .amplHigh = 158, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/157, .timeNR = 0, .tonePeriod = 157, .toneHigh = 157/2, .amplPeriod = 255, .amplHigh = 157, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/156, .timeNR = 0, .tonePeriod = 156, .toneHigh = 156/2, .amplPeriod = 255, .amplHigh = 156, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/155, .timeNR = 0, .tonePeriod = 155, .toneHigh = 155/2, .amplPeriod = 255, .amplHigh = 155, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/154, .timeNR = 0, .tonePeriod = 154, .toneHigh = 154/2, .amplPeriod = 255, .amplHigh = 154, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/153, .timeNR = 0, .tonePeriod = 153, .toneHigh = 153/2, .amplPeriod = 255, .amplHigh = 153, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/152, .timeNR = 0, .tonePeriod = 152, .toneHigh = 152/2, .amplPeriod = 255, .amplHigh = 152, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/151, .timeNR = 0, .tonePeriod = 151, .toneHigh = 151/2, .amplPeriod = 255, .amplHigh = 151, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/150, .timeNR = 0, .tonePeriod = 150, .toneHigh = 150/2, .amplPeriod = 255, .amplHigh = 150, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/149, .timeNR = 0, .tonePeriod = 149, .toneHigh = 149/2, .amplPeriod = 255, .amplHigh = 149, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/148, .timeNR = 0, .tonePeriod = 148, .toneHigh = 148/2, .amplPeriod = 255, .amplHigh = 148, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/147, .timeNR = 0, .tonePeriod = 147, .toneHigh = 147/2, .amplPeriod = 255, .amplHigh = 147, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/146, .timeNR = 0, .tonePeriod = 146, .toneHigh = 146/2, .amplPeriod = 255, .amplHigh = 146, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/145, .timeNR = 0, .tonePeriod = 145, .toneHigh = 145/2, .amplPeriod = 255, .amplHigh = 145, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/144, .timeNR = 0, .tonePeriod = 144, .toneHigh = 144/2, .amplPeriod = 255, .amplHigh = 144, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/143, .timeNR = 0, .tonePeriod = 143, .toneHigh = 143/2, .amplPeriod = 255, .amplHigh = 143, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/142, .timeNR = 0, .tonePeriod = 142, .toneHigh = 142/2, .amplPeriod = 255, .amplHigh = 142, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/141, .timeNR = 0, .tonePeriod = 141, .toneHigh = 141/2, .amplPeriod = 255, .amplHigh = 141, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/140, .timeNR = 0, .tonePeriod = 140, .toneHigh = 140/2, .amplPeriod = 255, .amplHigh = 140, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/139, .timeNR = 0, .tonePeriod = 139, .toneHigh = 139/2, .amplPeriod = 255, .amplHigh = 139, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/138, .timeNR = 0, .tonePeriod = 138, .toneHigh = 138/2, .amplPeriod = 255, .amplHigh = 138, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/137, .timeNR = 0, .tonePeriod = 137, .toneHigh = 137/2, .amplPeriod = 255, .amplHigh = 137, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/136, .timeNR = 0, .tonePeriod = 136, .toneHigh = 136/2, .amplPeriod = 255, .amplHigh = 136, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/135, .timeNR = 0, .tonePeriod = 135, .toneHigh = 135/2, .amplPeriod = 255, .amplHigh = 135, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/134, .timeNR = 0, .tonePeriod = 134, .toneHigh = 134/2, .amplPeriod = 255, .amplHigh = 134, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/133, .timeNR = 0, .tonePeriod = 133, .toneHigh = 133/2, .amplPeriod = 255, .amplHigh = 133, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/132, .timeNR = 0, .tonePeriod = 132, .toneHigh = 132/2, .amplPeriod = 255, .amplHigh = 132, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/131, .timeNR = 0, .tonePeriod = 131, .toneHigh = 131/2, .amplPeriod = 255, .amplHigh = 131, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/130, .timeNR = 0, .tonePeriod = 130, .toneHigh = 130/2, .amplPeriod = 255, .amplHigh = 130, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/129, .timeNR = 0, .tonePeriod = 129, .toneHigh = 129/2, .amplPeriod = 255, .amplHigh = 129, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/128, .timeNR = 0, .tonePeriod = 128, .toneHigh = 128/2, .amplPeriod = 255, .amplHigh = 128, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/127, .timeNR = 0, .tonePeriod = 127, .toneHigh = 127/2, .amplPeriod = 255, .amplHigh = 127, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/126, .timeNR = 0, .tonePeriod = 126, .toneHigh = 126/2, .amplPeriod = 255, .amplHigh = 126, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/125, .timeNR = 0, .tonePeriod = 125, .toneHigh = 125/2, .amplPeriod = 255, .amplHigh = 125, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/124, .timeNR = 0, .tonePeriod = 124, .toneHigh = 124/2, .amplPeriod = 255, .amplHigh = 124, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/123, .timeNR = 0, .tonePeriod = 123, .toneHigh = 123/2, .amplPeriod = 255, .amplHigh = 123, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/122, .timeNR = 0, .tonePeriod = 122, .toneHigh = 122/2, .amplPeriod = 255, .amplHigh = 122, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/121, .timeNR = 0, .tonePeriod = 121, .toneHigh = 121/2, .amplPeriod = 255, .amplHigh = 121, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/120, .timeNR = 0, .tonePeriod = 120, .toneHigh = 120/2, .amplPeriod = 255, .amplHigh = 120, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/119, .timeNR = 0, .tonePeriod = 119, .toneHigh = 119/2, .amplPeriod = 255, .amplHigh = 119, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/118, .timeNR = 0, .tonePeriod = 118, .toneHigh = 118/2, .amplPeriod = 255, .amplHigh = 118, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/117, .timeNR = 0, .tonePeriod = 117, .toneHigh = 117/2, .amplPeriod = 255, .amplHigh = 117, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/116, .timeNR = 0, .tonePeriod = 116, .toneHigh = 116/2, .amplPeriod = 255, .amplHigh = 116, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/115, .timeNR = 0, .tonePeriod = 115, .toneHigh = 115/2, .amplPeriod = 255, .amplHigh = 115, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/114, .timeNR = 0, .tonePeriod = 114, .toneHigh = 114/2, .amplPeriod = 255, .amplHigh = 114, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/113, .timeNR = 0, .tonePeriod = 113, .toneHigh = 113/2, .amplPeriod = 255, .amplHigh = 113, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/112, .timeNR = 0, .tonePeriod = 112, .toneHigh = 112/2, .amplPeriod = 255, .amplHigh = 112, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/111, .timeNR = 0, .tonePeriod = 111, .toneHigh = 111/2, .amplPeriod = 255, .amplHigh = 111, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/110, .timeNR = 0, .tonePeriod = 110, .toneHigh = 110/2, .amplPeriod = 255, .amplHigh = 110, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/109, .timeNR = 0, .tonePeriod = 109, .toneHigh = 109/2, .amplPeriod = 255, .amplHigh = 109, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/108, .timeNR = 0, .tonePeriod = 108, .toneHigh = 108/2, .amplPeriod = 255, .amplHigh = 108, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/107, .timeNR = 0, .tonePeriod = 107, .toneHigh = 107/2, .amplPeriod = 255, .amplHigh = 107, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/106, .timeNR = 0, .tonePeriod = 106, .toneHigh = 106/2, .amplPeriod = 255, .amplHigh = 106, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/105, .timeNR = 0, .tonePeriod = 105, .toneHigh = 105/2, .amplPeriod = 255, .amplHigh = 105, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/104, .timeNR = 0, .tonePeriod = 104, .toneHigh = 104/2, .amplPeriod = 255, .amplHigh = 104, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/103, .timeNR = 0, .tonePeriod = 103, .toneHigh = 103/2, .amplPeriod = 255, .amplHigh = 103, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/102, .timeNR = 0, .tonePeriod = 102, .toneHigh = 102/2, .amplPeriod = 255, .amplHigh = 102, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/101, .timeNR = 0, .tonePeriod = 101, .toneHigh = 101/2, .amplPeriod = 255, .amplHigh = 101, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/100, .timeNR = 0, .tonePeriod = 100, .toneHigh = 100/2, .amplPeriod = 255, .amplHigh = 100, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/99, .timeNR = 0, .tonePeriod = 99, .toneHigh = 99/2, .amplPeriod = 255, .amplHigh = 99, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/98, .timeNR = 0, .tonePeriod = 98, .toneHigh = 98/2, .amplPeriod = 255, .amplHigh = 98, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/97, .timeNR = 0, .tonePeriod = 97, .toneHigh = 97/2, .amplPeriod = 255, .amplHigh = 97, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/96, .timeNR = 0, .tonePeriod = 96, .toneHigh = 96/2, .amplPeriod = 255, .amplHigh = 96, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/95, .timeNR = 0, .tonePeriod = 95, .toneHigh = 95/2, .amplPeriod = 255, .amplHigh = 95, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/94, .timeNR = 0, .tonePeriod = 94, .toneHigh = 94/2, .amplPeriod = 255, .amplHigh = 94, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/93, .timeNR = 0, .tonePeriod = 93, .toneHigh = 93/2, .amplPeriod = 255, .amplHigh = 93, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/92, .timeNR = 0, .tonePeriod = 92, .toneHigh = 92/2, .amplPeriod = 255, .amplHigh = 92, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/91, .timeNR = 0, .tonePeriod = 91, .toneHigh = 91/2, .amplPeriod = 255, .amplHigh = 91, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/90, .timeNR = 0, .tonePeriod = 90, .toneHigh = 90/2, .amplPeriod = 255, .amplHigh = 90, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/89, .timeNR = 0, .tonePeriod = 89, .toneHigh = 89/2, .amplPeriod = 255, .amplHigh = 89, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/88, .timeNR = 0, .tonePeriod = 88, .toneHigh = 88/2, .amplPeriod = 255, .amplHigh = 88, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/87, .timeNR = 0, .tonePeriod = 87, .toneHigh = 87/2, .amplPeriod = 255, .amplHigh = 87, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/86, .timeNR = 0, .tonePeriod = 86, .toneHigh = 86/2, .amplPeriod = 255, .amplHigh = 86, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/85, .timeNR = 0, .tonePeriod = 85, .toneHigh = 85/2, .amplPeriod = 255, .amplHigh = 85, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/84, .timeNR = 0, .tonePeriod = 84, .toneHigh = 84/2, .amplPeriod = 255, .amplHigh = 84, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/83, .timeNR = 0, .tonePeriod = 83, .toneHigh = 83/2, .amplPeriod = 255, .amplHigh = 83, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/82, .timeNR = 0, .tonePeriod = 82, .toneHigh = 82/2, .amplPeriod = 255, .amplHigh = 82, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/81, .timeNR = 0, .tonePeriod = 81, .toneHigh = 81/2, .amplPeriod = 255, .amplHigh = 81, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/80, .timeNR = 0, .tonePeriod = 80, .toneHigh = 80/2, .amplPeriod = 255, .amplHigh = 80, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/79, .timeNR = 0, .tonePeriod = 79, .toneHigh = 79/2, .amplPeriod = 255, .amplHigh = 79, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/78, .timeNR = 0, .tonePeriod = 78, .toneHigh = 78/2, .amplPeriod = 255, .amplHigh = 78, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/77, .timeNR = 0, .tonePeriod = 77, .toneHigh = 77/2, .amplPeriod = 255, .amplHigh = 77, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/76, .timeNR = 0, .tonePeriod = 76, .toneHigh = 76/2, .amplPeriod = 255, .amplHigh = 76, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/75, .timeNR = 0, .tonePeriod = 75, .toneHigh = 75/2, .amplPeriod = 255, .amplHigh = 75, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/74, .timeNR = 0, .tonePeriod = 74, .toneHigh = 74/2, .amplPeriod = 255, .amplHigh = 74, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/73, .timeNR = 0, .tonePeriod = 73, .toneHigh = 73/2, .amplPeriod = 255, .amplHigh = 73, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/72, .timeNR = 0, .tonePeriod = 72, .toneHigh = 72/2, .amplPeriod = 255, .amplHigh = 72, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/71, .timeNR = 0, .tonePeriod = 71, .toneHigh = 71/2, .amplPeriod = 255, .amplHigh = 71, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/70, .timeNR = 0, .tonePeriod = 70, .toneHigh = 70/2, .amplPeriod = 255, .amplHigh = 70, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/69, .timeNR = 0, .tonePeriod = 69, .toneHigh = 69/2, .amplPeriod = 255, .amplHigh = 69, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/68, .timeNR = 0, .tonePeriod = 68, .toneHigh = 68/2, .amplPeriod = 255, .amplHigh = 68, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/67, .timeNR = 0, .tonePeriod = 67, .toneHigh = 67/2, .amplPeriod = 255, .amplHigh = 67, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/66, .timeNR = 0, .tonePeriod = 66, .toneHigh = 66/2, .amplPeriod = 255, .amplHigh = 66, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/65, .timeNR = 0, .tonePeriod = 65, .toneHigh = 65/2, .amplPeriod = 255, .amplHigh = 65, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/64, .timeNR = 0, .tonePeriod = 64, .toneHigh = 64/2, .amplPeriod = 255, .amplHigh = 64, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/63, .timeNR = 0, .tonePeriod = 63, .toneHigh = 63/2, .amplPeriod = 255, .amplHigh = 63, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/62, .timeNR = 0, .tonePeriod = 62, .toneHigh = 62/2, .amplPeriod = 255, .amplHigh = 62, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/61, .timeNR = 0, .tonePeriod = 61, .toneHigh = 61/2, .amplPeriod = 255, .amplHigh = 61, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/60, .timeNR = 0, .tonePeriod = 60, .toneHigh = 60/2, .amplPeriod = 255, .amplHigh = 60, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/59, .timeNR = 0, .tonePeriod = 59, .toneHigh = 59/2, .amplPeriod = 255, .amplHigh = 59, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/58, .timeNR = 0, .tonePeriod = 58, .toneHigh = 58/2, .amplPeriod = 255, .amplHigh = 58, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/57, .timeNR = 0, .tonePeriod = 57, .toneHigh = 57/2, .amplPeriod = 255, .amplHigh = 57, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/56, .timeNR = 0, .tonePeriod = 56, .toneHigh = 56/2, .amplPeriod = 255, .amplHigh = 56, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/55, .timeNR = 0, .tonePeriod = 55, .toneHigh = 55/2, .amplPeriod = 255, .amplHigh = 55, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/54, .timeNR = 0, .tonePeriod = 54, .toneHigh = 54/2, .amplPeriod = 255, .amplHigh = 54, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/53, .timeNR = 0, .tonePeriod = 53, .toneHigh = 53/2, .amplPeriod = 255, .amplHigh = 53, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/52, .timeNR = 0, .tonePeriod = 52, .toneHigh = 52/2, .amplPeriod = 255, .amplHigh = 52, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/51, .timeNR = 0, .tonePeriod = 51, .toneHigh = 51/2, .amplPeriod = 255, .amplHigh = 51, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/50, .timeNR = 0, .tonePeriod = 50, .toneHigh = 50/2, .amplPeriod = 255, .amplHigh = 50, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/49, .timeNR = 0, .tonePeriod = 49, .toneHigh = 49/2, .amplPeriod = 255, .amplHigh = 49, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/48, .timeNR = 0, .tonePeriod = 48, .toneHigh = 48/2, .amplPeriod = 255, .amplHigh = 48, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/47, .timeNR = 0, .tonePeriod = 47, .toneHigh = 47/2, .amplPeriod = 255, .amplHigh = 47, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/46, .timeNR = 0, .tonePeriod = 46, .toneHigh = 46/2, .amplPeriod = 255, .amplHigh = 46, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/45, .timeNR = 0, .tonePeriod = 45, .toneHigh = 45/2, .amplPeriod = 255, .amplHigh = 45, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/44, .timeNR = 0, .tonePeriod = 44, .toneHigh = 44/2, .amplPeriod = 255, .amplHigh = 44, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/43, .timeNR = 0, .tonePeriod = 43, .toneHigh = 43/2, .amplPeriod = 255, .amplHigh = 43, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/42, .timeNR = 0, .tonePeriod = 42, .toneHigh = 42/2, .amplPeriod = 255, .amplHigh = 42, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/41, .timeNR = 0, .tonePeriod = 41, .toneHigh = 41/2, .amplPeriod = 255, .amplHigh = 41, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/40, .timeNR = 0, .tonePeriod = 40, .toneHigh = 40/2, .amplPeriod = 255, .amplHigh = 40, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/39, .timeNR = 0, .tonePeriod = 39, .toneHigh = 39/2, .amplPeriod = 255, .amplHigh = 39, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/38, .timeNR = 0, .tonePeriod = 38, .toneHigh = 38/2, .amplPeriod = 255, .amplHigh = 38, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/37, .timeNR = 0, .tonePeriod = 37, .toneHigh = 37/2, .amplPeriod = 255, .amplHigh = 37, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/36, .timeNR = 0, .tonePeriod = 36, .toneHigh = 36/2, .amplPeriod = 255, .amplHigh = 36, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/35, .timeNR = 0, .tonePeriod = 35, .toneHigh = 35/2, .amplPeriod = 255, .amplHigh = 35, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/34, .timeNR = 0, .tonePeriod = 34, .toneHigh = 34/2, .amplPeriod = 255, .amplHigh = 34, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/33, .timeNR = 0, .tonePeriod = 33, .toneHigh = 33/2, .amplPeriod = 255, .amplHigh = 33, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/32, .timeNR = 0, .tonePeriod = 32, .toneHigh = 32/2, .amplPeriod = 255, .amplHigh = 32, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/31, .timeNR = 0, .tonePeriod = 31, .toneHigh = 31/2, .amplPeriod = 255, .amplHigh = 31, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/30, .timeNR = 0, .tonePeriod = 30, .toneHigh = 30/2, .amplPeriod = 255, .amplHigh = 30, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/29, .timeNR = 0, .tonePeriod = 29, .toneHigh = 29/2, .amplPeriod = 255, .amplHigh = 29, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/28, .timeNR = 0, .tonePeriod = 28, .toneHigh = 28/2, .amplPeriod = 255, .amplHigh = 28, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/27, .timeNR = 0, .tonePeriod = 27, .toneHigh = 27/2, .amplPeriod = 255, .amplHigh = 27, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/26, .timeNR = 0, .tonePeriod = 26, .toneHigh = 26/2, .amplPeriod = 255, .amplHigh = 26, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/25, .timeNR = 0, .tonePeriod = 25, .toneHigh = 25/2, .amplPeriod = 255, .amplHigh = 25, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/24, .timeNR = 0, .tonePeriod = 24, .toneHigh = 24/2, .amplPeriod = 255, .amplHigh = 24, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/23, .timeNR = 0, .tonePeriod = 23, .toneHigh = 23/2, .amplPeriod = 255, .amplHigh = 23, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/22, .timeNR = 0, .tonePeriod = 22, .toneHigh = 22/2, .amplPeriod = 255, .amplHigh = 22, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/21, .timeNR = 0, .tonePeriod = 21, .toneHigh = 21/2, .amplPeriod = 255, .amplHigh = 21, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/20, .timeNR = 0, .tonePeriod = 20, .toneHigh = 20/2, .amplPeriod = 255, .amplHigh = 20, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/19, .timeNR = 0, .tonePeriod = 19, .toneHigh = 19/2, .amplPeriod = 255, .amplHigh = 19, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/18, .timeNR = 0, .tonePeriod = 18, .toneHigh = 18/2, .amplPeriod = 255, .amplHigh = 18, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/17, .timeNR = 0, .tonePeriod = 17, .toneHigh = 17/2, .amplPeriod = 255, .amplHigh = 17, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/16, .timeNR = 0, .tonePeriod = 16, .toneHigh = 16/2, .amplPeriod = 255, .amplHigh = 16, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/15, .timeNR = 0, .tonePeriod = 15, .toneHigh = 15/2, .amplPeriod = 255, .amplHigh = 15, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/14, .timeNR = 0, .tonePeriod = 14, .toneHigh = 14/2, .amplPeriod = 255, .amplHigh = 14, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/13, .timeNR = 0, .tonePeriod = 13, .toneHigh = 13/2, .amplPeriod = 255, .amplHigh = 13, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/12, .timeNR = 0, .tonePeriod = 12, .toneHigh = 12/2, .amplPeriod = 255, .amplHigh = 12, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/11, .timeNR = 0, .tonePeriod = 11, .toneHigh = 11/2, .amplPeriod = 255, .amplHigh = 11, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/10, .timeNR = 0, .tonePeriod = 10, .toneHigh = 10/2, .amplPeriod = 255, .amplHigh = 10, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/9, .timeNR = 0, .tonePeriod = 9, .toneHigh = 9/2, .amplPeriod = 255, .amplHigh = 9, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/8, .timeNR = 0, .tonePeriod = 8, .toneHigh = 8/2, .amplPeriod = 255, .amplHigh = 8, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/7, .timeNR = 0, .tonePeriod = 7, .toneHigh = 7/2, .amplPeriod = 255, .amplHigh = 7, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/6, .timeNR = 0, .tonePeriod = 6, .toneHigh = 6/2, .amplPeriod = 255, .amplHigh = 6, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/5, .timeNR = 0, .tonePeriod = 5, .toneHigh = 5/2, .amplPeriod = 255, .amplHigh = 5, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/4, .timeNR = 0, .tonePeriod = 4, .toneHigh = 4/2, .amplPeriod = 255, .amplHigh = 4, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/3, .timeNR = 0, .tonePeriod = 3, .toneHigh = 3/2, .amplPeriod = 255, .amplHigh = 3, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/2, .timeNR = 0, .tonePeriod = 2, .toneHigh = 2/2, .amplPeriod = 255, .amplHigh = 2, .stepSize = 0, .stepValid = 1},
    {.timePeriod = 255/1, .timeNR = 0, .tonePeriod = 1, .toneHigh = 1/2, .amplPeriod = 255, .amplHigh = 1, .stepSize = 0, .stepValid = 1},
};
#define SIZE_OF_SEGMENT (sizeof(userData)/sizeof(cy_stc_sg_segment_t))

void SG_UserInterruptHandler(void)
{
    uint32_t    maskedIntrStatus;
    
    maskedIntrStatus = Cy_SG_GetInterruptStatusMasked(CY_AUDIOSS_SG0_TYPE);
    
    if((maskedIntrStatus & CY_SG_INTR_TX_COMPLETE) != 0)
    {
        {  
            Cy_SG_PushSegment(CY_AUDIOSS_SG0_TYPE, userData, &sgContext);
        }
    }
     Cy_SG_ClearInterrupt(CY_AUDIOSS_SG0_TYPE, maskedIntrStatus);
}

int main(void)
{
    SystemInit();
    
    __enable_irq(); /* Enable global interrupts. */
    
    // CY_AUDIOSS_SG0_TYPE; /* Uncomment this to check registers when debug */
    
    /**************************************************/
    /*******    Clock divider setting       ***********/
    /**************************************************/
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_5); /* Enable hfclk5 for Audio */
    Cy_SysClk_HfClockSetSource(CY_SYSCLK_HFCLK_5, CY_SYSCLK_HFCLK_IN_CLKPATH1);
    Cy_SysClk_HfClockSetDivider(CY_SYSCLK_HFCLK_5, CY_SYSCLK_HFCLK_NO_DIVIDE);
    
    /**************************************/
    /* Port Setting for SG transmission   */
    /**************************************/
    SG_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF; 
    SG_port_pin_cfg.hsiom = CY_AUDIOSS_SG0_AMPL_PIN_MUX; 
    Cy_GPIO_Pin_Init(CY_AUDIOSS_SG0_AMPL_PORT, CY_AUDIOSS_SG0_AMPL_PIN, &SG_port_pin_cfg); 
    
    SG_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    SG_port_pin_cfg.hsiom = CY_AUDIOSS_SG0_TONE_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_AUDIOSS_SG0_TONE_PORT, CY_AUDIOSS_SG0_TONE_PIN, &SG_port_pin_cfg);
    
    /*******************************************/
    /* Interrupt setting for SG                */
    /*******************************************/
    Cy_SysInt_InitIRQ(&sg_irq_cfg);
    Cy_SysInt_SetSystemIrqVector(sg_irq_cfg.sysIntSrc, SG_UserInterruptHandler);
    NVIC_SetPriority(CPUIntIdx4_IRQn, 0);
    NVIC_EnableIRQ(CPUIntIdx4_IRQn); 
    
    /********************************************/
    /* Settings for SG channel 1                */
    /********************************************/
    
    Cy_SG_DeInit(CY_AUDIOSS_SG0_TYPE);
    Cy_SG_Init(CY_AUDIOSS_SG0_TYPE, &sgInitConfig);
    Cy_SG_EnableSource(CY_AUDIOSS_SG0_TYPE);
    Cy_SG_SetInterruptMask(CY_AUDIOSS_SG0_TYPE, CY_SG_INTR_TX_COMPLETE);
    Cy_SG_StartSegment(CY_AUDIOSS_SG0_TYPE, userData, SIZE_OF_SEGMENT, &sgContext);
    
    for(;;);
}
    
