/***************************************************************************//**
* \file cyt2b7_config.h
*
* \brief
* CYT2B7 device configuration header
*
* \note
* Generator version: 1.4.0.1239
* Database revision: TVIIBE1M_RevB_WW1836
*
********************************************************************************
* \copyright
* Copyright 2016-2019, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYT2B7_CONFIG_H_
#define _CYT2B7_CONFIG_H_

/* Clock Connections */
typedef enum
{
    PCLK_CPUSS_CLOCK_TRACE_IN       = 0x0000u,  /* cpuss.clock_trace_in */
    PCLK_SMARTIO12_CLOCK            = 0x0001u,  /* smartio[12].clock */
    PCLK_SMARTIO13_CLOCK            = 0x0002u,  /* smartio[13].clock */
    PCLK_SMARTIO14_CLOCK            = 0x0003u,  /* smartio[14].clock */
    PCLK_SMARTIO15_CLOCK            = 0x0004u,  /* smartio[15].clock */
    PCLK_SMARTIO17_CLOCK            = 0x0005u,  /* smartio[17].clock */
    PCLK_CANFD0_CLOCK_CAN0          = 0x0006u,  /* canfd[0].clock_can[0] */
    PCLK_CANFD0_CLOCK_CAN1          = 0x0007u,  /* canfd[0].clock_can[1] */
    PCLK_CANFD0_CLOCK_CAN2          = 0x0008u,  /* canfd[0].clock_can[2] */
    PCLK_CANFD1_CLOCK_CAN0          = 0x0009u,  /* canfd[1].clock_can[0] */
    PCLK_CANFD1_CLOCK_CAN1          = 0x000Au,  /* canfd[1].clock_can[1] */
    PCLK_CANFD1_CLOCK_CAN2          = 0x000Bu,  /* canfd[1].clock_can[2] */
    PCLK_LIN0_CLOCK_CH_EN0          = 0x000Cu,  /* lin[0].clock_ch_en[0] */
    PCLK_LIN0_CLOCK_CH_EN1          = 0x000Du,  /* lin[0].clock_ch_en[1] */
    PCLK_LIN0_CLOCK_CH_EN2          = 0x000Eu,  /* lin[0].clock_ch_en[2] */
    PCLK_LIN0_CLOCK_CH_EN3          = 0x000Fu,  /* lin[0].clock_ch_en[3] */
    PCLK_LIN0_CLOCK_CH_EN4          = 0x0010u,  /* lin[0].clock_ch_en[4] */
    PCLK_LIN0_CLOCK_CH_EN5          = 0x0011u,  /* lin[0].clock_ch_en[5] */
    PCLK_LIN0_CLOCK_CH_EN6          = 0x0012u,  /* lin[0].clock_ch_en[6] */
    PCLK_LIN0_CLOCK_CH_EN7          = 0x0013u,  /* lin[0].clock_ch_en[7] */
    PCLK_SCB0_CLOCK                 = 0x0014u,  /* scb[0].clock */
    PCLK_SCB1_CLOCK                 = 0x0015u,  /* scb[1].clock */
    PCLK_SCB2_CLOCK                 = 0x0016u,  /* scb[2].clock */
    PCLK_SCB3_CLOCK                 = 0x0017u,  /* scb[3].clock */
    PCLK_SCB4_CLOCK                 = 0x0018u,  /* scb[4].clock */
    PCLK_SCB5_CLOCK                 = 0x0019u,  /* scb[5].clock */
    PCLK_SCB6_CLOCK                 = 0x001Au,  /* scb[6].clock */
    PCLK_SCB7_CLOCK                 = 0x001Bu,  /* scb[7].clock */
    PCLK_PASS0_CLOCK_SAR0           = 0x001Cu,  /* pass[0].clock_sar[0] */
    PCLK_PASS0_CLOCK_SAR1           = 0x001Du,  /* pass[0].clock_sar[1] */
    PCLK_PASS0_CLOCK_SAR2           = 0x001Eu,  /* pass[0].clock_sar[2] */
    PCLK_TCPWM0_CLOCKS0             = 0x001Fu,  /* tcpwm[0].clocks[0] */
    PCLK_TCPWM0_CLOCKS1             = 0x0020u,  /* tcpwm[0].clocks[1] */
    PCLK_TCPWM0_CLOCKS2             = 0x0021u,  /* tcpwm[0].clocks[2] */
    PCLK_TCPWM0_CLOCKS3             = 0x0022u,  /* tcpwm[0].clocks[3] */
    PCLK_TCPWM0_CLOCKS4             = 0x0023u,  /* tcpwm[0].clocks[4] */
    PCLK_TCPWM0_CLOCKS5             = 0x0024u,  /* tcpwm[0].clocks[5] */
    PCLK_TCPWM0_CLOCKS6             = 0x0025u,  /* tcpwm[0].clocks[6] */
    PCLK_TCPWM0_CLOCKS7             = 0x0026u,  /* tcpwm[0].clocks[7] */
    PCLK_TCPWM0_CLOCKS8             = 0x0027u,  /* tcpwm[0].clocks[8] */
    PCLK_TCPWM0_CLOCKS9             = 0x0028u,  /* tcpwm[0].clocks[9] */
    PCLK_TCPWM0_CLOCKS10            = 0x0029u,  /* tcpwm[0].clocks[10] */
    PCLK_TCPWM0_CLOCKS11            = 0x002Au,  /* tcpwm[0].clocks[11] */
    PCLK_TCPWM0_CLOCKS12            = 0x002Bu,  /* tcpwm[0].clocks[12] */
    PCLK_TCPWM0_CLOCKS13            = 0x002Cu,  /* tcpwm[0].clocks[13] */
    PCLK_TCPWM0_CLOCKS14            = 0x002Du,  /* tcpwm[0].clocks[14] */
    PCLK_TCPWM0_CLOCKS15            = 0x002Eu,  /* tcpwm[0].clocks[15] */
    PCLK_TCPWM0_CLOCKS16            = 0x002Fu,  /* tcpwm[0].clocks[16] */
    PCLK_TCPWM0_CLOCKS17            = 0x0030u,  /* tcpwm[0].clocks[17] */
    PCLK_TCPWM0_CLOCKS18            = 0x0031u,  /* tcpwm[0].clocks[18] */
    PCLK_TCPWM0_CLOCKS19            = 0x0032u,  /* tcpwm[0].clocks[19] */
    PCLK_TCPWM0_CLOCKS20            = 0x0033u,  /* tcpwm[0].clocks[20] */
    PCLK_TCPWM0_CLOCKS21            = 0x0034u,  /* tcpwm[0].clocks[21] */
    PCLK_TCPWM0_CLOCKS22            = 0x0035u,  /* tcpwm[0].clocks[22] */
    PCLK_TCPWM0_CLOCKS23            = 0x0036u,  /* tcpwm[0].clocks[23] */
    PCLK_TCPWM0_CLOCKS24            = 0x0037u,  /* tcpwm[0].clocks[24] */
    PCLK_TCPWM0_CLOCKS25            = 0x0038u,  /* tcpwm[0].clocks[25] */
    PCLK_TCPWM0_CLOCKS26            = 0x0039u,  /* tcpwm[0].clocks[26] */
    PCLK_TCPWM0_CLOCKS27            = 0x003Au,  /* tcpwm[0].clocks[27] */
    PCLK_TCPWM0_CLOCKS28            = 0x003Bu,  /* tcpwm[0].clocks[28] */
    PCLK_TCPWM0_CLOCKS29            = 0x003Cu,  /* tcpwm[0].clocks[29] */
    PCLK_TCPWM0_CLOCKS30            = 0x003Du,  /* tcpwm[0].clocks[30] */
    PCLK_TCPWM0_CLOCKS31            = 0x003Eu,  /* tcpwm[0].clocks[31] */
    PCLK_TCPWM0_CLOCKS32            = 0x003Fu,  /* tcpwm[0].clocks[32] */
    PCLK_TCPWM0_CLOCKS33            = 0x0040u,  /* tcpwm[0].clocks[33] */
    PCLK_TCPWM0_CLOCKS34            = 0x0041u,  /* tcpwm[0].clocks[34] */
    PCLK_TCPWM0_CLOCKS35            = 0x0042u,  /* tcpwm[0].clocks[35] */
    PCLK_TCPWM0_CLOCKS36            = 0x0043u,  /* tcpwm[0].clocks[36] */
    PCLK_TCPWM0_CLOCKS37            = 0x0044u,  /* tcpwm[0].clocks[37] */
    PCLK_TCPWM0_CLOCKS38            = 0x0045u,  /* tcpwm[0].clocks[38] */
    PCLK_TCPWM0_CLOCKS39            = 0x0046u,  /* tcpwm[0].clocks[39] */
    PCLK_TCPWM0_CLOCKS40            = 0x0047u,  /* tcpwm[0].clocks[40] */
    PCLK_TCPWM0_CLOCKS41            = 0x0048u,  /* tcpwm[0].clocks[41] */
    PCLK_TCPWM0_CLOCKS42            = 0x0049u,  /* tcpwm[0].clocks[42] */
    PCLK_TCPWM0_CLOCKS43            = 0x004Au,  /* tcpwm[0].clocks[43] */
    PCLK_TCPWM0_CLOCKS44            = 0x004Bu,  /* tcpwm[0].clocks[44] */
    PCLK_TCPWM0_CLOCKS45            = 0x004Cu,  /* tcpwm[0].clocks[45] */
    PCLK_TCPWM0_CLOCKS46            = 0x004Du,  /* tcpwm[0].clocks[46] */
    PCLK_TCPWM0_CLOCKS47            = 0x004Eu,  /* tcpwm[0].clocks[47] */
    PCLK_TCPWM0_CLOCKS48            = 0x004Fu,  /* tcpwm[0].clocks[48] */
    PCLK_TCPWM0_CLOCKS49            = 0x0050u,  /* tcpwm[0].clocks[49] */
    PCLK_TCPWM0_CLOCKS50            = 0x0051u,  /* tcpwm[0].clocks[50] */
    PCLK_TCPWM0_CLOCKS51            = 0x0052u,  /* tcpwm[0].clocks[51] */
    PCLK_TCPWM0_CLOCKS52            = 0x0053u,  /* tcpwm[0].clocks[52] */
    PCLK_TCPWM0_CLOCKS53            = 0x0054u,  /* tcpwm[0].clocks[53] */
    PCLK_TCPWM0_CLOCKS54            = 0x0055u,  /* tcpwm[0].clocks[54] */
    PCLK_TCPWM0_CLOCKS55            = 0x0056u,  /* tcpwm[0].clocks[55] */
    PCLK_TCPWM0_CLOCKS56            = 0x0057u,  /* tcpwm[0].clocks[56] */
    PCLK_TCPWM0_CLOCKS57            = 0x0058u,  /* tcpwm[0].clocks[57] */
    PCLK_TCPWM0_CLOCKS58            = 0x0059u,  /* tcpwm[0].clocks[58] */
    PCLK_TCPWM0_CLOCKS59            = 0x005Au,  /* tcpwm[0].clocks[59] */
    PCLK_TCPWM0_CLOCKS60            = 0x005Bu,  /* tcpwm[0].clocks[60] */
    PCLK_TCPWM0_CLOCKS61            = 0x005Cu,  /* tcpwm[0].clocks[61] */
    PCLK_TCPWM0_CLOCKS62            = 0x005Du,  /* tcpwm[0].clocks[62] */
    PCLK_TCPWM0_CLOCKS256           = 0x005Eu,  /* tcpwm[0].clocks[256] */
    PCLK_TCPWM0_CLOCKS257           = 0x005Fu,  /* tcpwm[0].clocks[257] */
    PCLK_TCPWM0_CLOCKS258           = 0x0060u,  /* tcpwm[0].clocks[258] */
    PCLK_TCPWM0_CLOCKS259           = 0x0061u,  /* tcpwm[0].clocks[259] */
    PCLK_TCPWM0_CLOCKS260           = 0x0062u,  /* tcpwm[0].clocks[260] */
    PCLK_TCPWM0_CLOCKS261           = 0x0063u,  /* tcpwm[0].clocks[261] */
    PCLK_TCPWM0_CLOCKS262           = 0x0064u,  /* tcpwm[0].clocks[262] */
    PCLK_TCPWM0_CLOCKS263           = 0x0065u,  /* tcpwm[0].clocks[263] */
    PCLK_TCPWM0_CLOCKS264           = 0x0066u,  /* tcpwm[0].clocks[264] */
    PCLK_TCPWM0_CLOCKS265           = 0x0067u,  /* tcpwm[0].clocks[265] */
    PCLK_TCPWM0_CLOCKS266           = 0x0068u,  /* tcpwm[0].clocks[266] */
    PCLK_TCPWM0_CLOCKS267           = 0x0069u,  /* tcpwm[0].clocks[267] */
    PCLK_TCPWM0_CLOCKS512           = 0x006Au,  /* tcpwm[0].clocks[512] */
    PCLK_TCPWM0_CLOCKS513           = 0x006Bu,  /* tcpwm[0].clocks[513] */
    PCLK_TCPWM0_CLOCKS514           = 0x006Cu,  /* tcpwm[0].clocks[514] */
    PCLK_TCPWM0_CLOCKS515           = 0x006Du   /* tcpwm[0].clocks[515] */
} en_clk_dst_t;

/* Trigger Group */
/* This section contains the enums related to the Trigger multiplexer (TrigMux) driver. 
* The constants are divided into four types because each signal of the TrigMux driver has a path
* through two multiplexers: the reduction multiplexer and the distribution multiplexer. This 
* requires two calls for Cy_TrigMux_Connect() function. The first call - for the reduction 
* multiplexer, the second call - for the distribution multiplexer.
*
* The four types of inputs/output parameters:
* 1) Parameters for reduction multiplexer's inputs (input signals of TrigMux)
* 2) Parameters for reduction multiplexer's outputs (intermediate signals);
* 3) Parameters for distribution multiplexer's inputs (intermediate signals);
* 4) Parameters for distribution multiplexer's outputs (output signals of TrigMux).
*
* The Cy_TrigMux_Connect() inTrig parameter can have 1) and 3) types parameters. The outTrig 
* parameter can have 2) and 4) types parameters.
* The names of the constants for these parameters have the following format:
*
* 1) For reduction multiplexer's inputs:
* TRIG<REDMULT>_IN_<IPSOURCE><IPNUM>
* <REDMULT> the reduction multiplexer number;
* <IPSOURCE> - the name of the IP block which is the source of the signal;
* <IPNUM> - the source signal number in the IP block.
*
* Example:
* TRIG11_IN_TCPWM0_TR_OVERFLOW3 - the TCPWM0 tr_overflow[3] input of reduction multiplexer#11.
* 
* 2) For reduction multiplexer's outputs:
* TRIG<REDMULT>_OUT_TR_GROUP<DISTMULT >_INPUT<DISTMULTINPUT>
* <REDMULT> - the reduction multiplexer number;
* <DISTMULT> - the distribution multiplexer number;
* <DISTMULTINPUT> - the input number of the distribution multiplexer.
*
* Example:
* TRIG11_OUT_TR_GROUP0_INPUT23 - Input#23 of the distribution multiplexer#0 is the destination 
* of the reduction multiplexer#11.
*
* 3) For distribution multiplexer's inputs:
* TRIG<DISTMULT>_IN_TR_GROUP<REDMULT >_OUTPUT<REDMULTOUTPUT>
* <REDMULT> - the reduction multiplexer number;
* <DISTMULT> - the distribution multiplexer number;
* <REDMULTOUTPUT> - the output number of the reduction multiplexer;
*
* Example:
* TRIG0_IN_TR_GROUP11_OUTPUT15 - Output#15 of the reduction multiplexer#11 is the source of the 
* distribution multiplexer#0.
* 
* 4) For distribution multiplexer's outputs:
* TRIG<DISTMULT>_OUT_<IPDEST><IPNUM>
* <REDMULT> - the distribution multiplexer number;
* <IPDEST> - the name of the IP block which is the destination of the signal;
* <IPNUM> - the input signal number in the IP block.
*
* Example:
* TRIG0_OUT_CPUSS_DW0_TR_IN3 - the DW0 tr_out[3] ouput of the distribution multiplexer 0.*/
/* Trigger Group Inputs */
/* Trigger Input Group 0 - P-DMA0 Request Assignments */
typedef enum
{
    TRIG_IN_MUX_0_PDMA0_TR_OUT0     = 0x00000001u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT1     = 0x00000002u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT2     = 0x00000003u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT3     = 0x00000004u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT4     = 0x00000005u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT5     = 0x00000006u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT6     = 0x00000007u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT7     = 0x00000008u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT8     = 0x00000009u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT9     = 0x0000000Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT10    = 0x0000000Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT11    = 0x0000000Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT12    = 0x0000000Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT13    = 0x0000000Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT14    = 0x0000000Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT15    = 0x00000010u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT0     = 0x00000011u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT1     = 0x00000012u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT2     = 0x00000013u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT3     = 0x00000014u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT4     = 0x00000015u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT5     = 0x00000016u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT6     = 0x00000017u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT7     = 0x00000018u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_0_MDMA_TR_OUT0      = 0x00000019u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_0_MDMA_TR_OUT1      = 0x0000001Au, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_0_MDMA_TR_OUT2      = 0x0000001Bu, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_0_MDMA_TR_OUT3      = 0x0000001Cu, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_0_FAULT_TR_OUT0     = 0x0000001Du, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_0_FAULT_TR_OUT1     = 0x0000001Eu, /* cpuss.tr_fault[1] */
    TRIG_IN_MUX_0_FAULT_TR_OUT2     = 0x0000001Fu, /* cpuss.tr_fault[2] */
    TRIG_IN_MUX_0_FAULT_TR_OUT3     = 0x00000020u, /* cpuss.tr_fault[3] */
    TRIG_IN_MUX_0_CTI_TR_OUT0       = 0x00000021u, /* cpuss.cti_tr_out[0] */
    TRIG_IN_MUX_0_CTI_TR_OUT1       = 0x00000022u, /* cpuss.cti_tr_out[1] */
    TRIG_IN_MUX_0_EVTGEN_TR_OUT3    = 0x00000023u, /* evtgen[0].tr_out[3] */
    TRIG_IN_MUX_0_EVTGEN_TR_OUT4    = 0x00000024u, /* evtgen[0].tr_out[4] */
    TRIG_IN_MUX_0_EVTGEN_TR_OUT5    = 0x00000025u, /* evtgen[0].tr_out[5] */
    TRIG_IN_MUX_0_EVTGEN_TR_OUT6    = 0x00000026u, /* evtgen[0].tr_out[6] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT0   = 0x00000027u, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT1   = 0x00000028u, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT2   = 0x00000029u, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT3   = 0x0000002Au, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT4   = 0x0000002Bu, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT5   = 0x0000002Cu, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT6   = 0x0000002Du, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT7   = 0x0000002Eu, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT8   = 0x0000002Fu, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT9   = 0x00000030u, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT10  = 0x00000031u, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT11  = 0x00000032u, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT12  = 0x00000033u, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT13  = 0x00000034u, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT14  = 0x00000035u, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT15  = 0x00000036u /* peri.tr_io_input[15] */
} en_trig_input_pdma0_tr_t;

/* Trigger Input Group 1 - P-DMA1 Request Assignments */
typedef enum
{
    TRIG_IN_MUX_1_PDMA0_TR_OUT0     = 0x00000101u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT1     = 0x00000102u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT2     = 0x00000103u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT3     = 0x00000104u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT4     = 0x00000105u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT5     = 0x00000106u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT6     = 0x00000107u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT7     = 0x00000108u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT8     = 0x00000109u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT9     = 0x0000010Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT10    = 0x0000010Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT11    = 0x0000010Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT12    = 0x0000010Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT13    = 0x0000010Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT14    = 0x0000010Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT15    = 0x00000110u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT0     = 0x00000111u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT1     = 0x00000112u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT2     = 0x00000113u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT3     = 0x00000114u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT4     = 0x00000115u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT5     = 0x00000116u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT6     = 0x00000117u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT7     = 0x00000118u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_1_MDMA_TR_OUT0      = 0x00000119u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_1_MDMA_TR_OUT1      = 0x0000011Au, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_1_MDMA_TR_OUT2      = 0x0000011Bu, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_1_MDMA_TR_OUT3      = 0x0000011Cu, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_1_FAULT_TR_OUT0     = 0x0000011Du, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_1_FAULT_TR_OUT1     = 0x0000011Eu, /* cpuss.tr_fault[1] */
    TRIG_IN_MUX_1_FAULT_TR_OUT2     = 0x0000011Fu, /* cpuss.tr_fault[2] */
    TRIG_IN_MUX_1_FAULT_TR_OUT3     = 0x00000120u, /* cpuss.tr_fault[3] */
    TRIG_IN_MUX_1_CTI_TR_OUT0       = 0x00000121u, /* cpuss.cti_tr_out[0] */
    TRIG_IN_MUX_1_CTI_TR_OUT1       = 0x00000122u, /* cpuss.cti_tr_out[1] */
    TRIG_IN_MUX_1_EVTGEN_TR_OUT7    = 0x00000123u, /* evtgen[0].tr_out[7] */
    TRIG_IN_MUX_1_EVTGEN_TR_OUT8    = 0x00000124u, /* evtgen[0].tr_out[8] */
    TRIG_IN_MUX_1_EVTGEN_TR_OUT9    = 0x00000125u, /* evtgen[0].tr_out[9] */
    TRIG_IN_MUX_1_EVTGEN_TR_OUT10   = 0x00000126u, /* evtgen[0].tr_out[10] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT16  = 0x00000127u, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT17  = 0x00000128u, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT18  = 0x00000129u, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT19  = 0x0000012Au, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT20  = 0x0000012Bu, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT21  = 0x0000012Cu, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT22  = 0x0000012Du, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT23  = 0x0000012Eu, /* peri.tr_io_input[23] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT24  = 0x0000012Fu, /* peri.tr_io_input[24] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT25  = 0x00000130u, /* peri.tr_io_input[25] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT26  = 0x00000131u, /* peri.tr_io_input[26] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT27  = 0x00000132u, /* peri.tr_io_input[27] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT28  = 0x00000133u, /* peri.tr_io_input[28] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT29  = 0x00000134u, /* peri.tr_io_input[29] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT30  = 0x00000135u, /* peri.tr_io_input[30] */
    TRIG_IN_MUX_1_HSIOM_IO_INPUT31  = 0x00000136u, /* peri.tr_io_input[31] */
    TRIG_IN_MUX_1_PASS_GEN_TR_OUT0  = 0x00000137u, /* pass[0].tr_sar_gen_out[0] */
    TRIG_IN_MUX_1_PASS_GEN_TR_OUT1  = 0x00000138u, /* pass[0].tr_sar_gen_out[1] */
    TRIG_IN_MUX_1_PASS_GEN_TR_OUT2  = 0x00000139u, /* pass[0].tr_sar_gen_out[2] */
    TRIG_IN_MUX_1_PASS_GEN_TR_OUT3  = 0x0000013Au, /* pass[0].tr_sar_gen_out[3] */
    TRIG_IN_MUX_1_PASS_GEN_TR_OUT4  = 0x0000013Bu, /* pass[0].tr_sar_gen_out[4] */
    TRIG_IN_MUX_1_PASS_GEN_TR_OUT5  = 0x0000013Cu /* pass[0].tr_sar_gen_out[5] */
} en_trig_input_pdma1_tr_t;

/* Trigger Input Group 2 - DMA Request Assignments */
typedef enum
{
    TRIG_IN_MUX_2_MDMA_TR_OUT0      = 0x00000201u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_2_MDMA_TR_OUT1      = 0x00000202u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_2_MDMA_TR_OUT2      = 0x00000203u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_2_MDMA_TR_OUT3      = 0x00000204u /* cpuss.dmac_tr_out[3] */
} en_trig_input_mdma_t;

/* Trigger Input Group 3 - Dedicated mux for counter to P-DMA0 triggers */
typedef enum
{
    TRIG_IN_MUX_3_TCPWM_32_TR_OUT00 = 0x00000301u, /* tcpwm[0].tr_out0[512] */
    TRIG_IN_MUX_3_TCPWM_32_TR_OUT01 = 0x00000302u, /* tcpwm[0].tr_out0[513] */
    TRIG_IN_MUX_3_TCPWM_32_TR_OUT02 = 0x00000303u, /* tcpwm[0].tr_out0[514] */
    TRIG_IN_MUX_3_TCPWM_32_TR_OUT03 = 0x00000304u, /* tcpwm[0].tr_out0[515] */
    TRIG_IN_MUX_3_TCPWM_16M_TR_OUT00 = 0x00000305u, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_3_TCPWM_16M_TR_OUT01 = 0x00000306u, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_3_TCPWM_16M_TR_OUT02 = 0x00000307u, /* tcpwm[0].tr_out0[258] */
    TRIG_IN_MUX_3_TCPWM_16M_TR_OUT03 = 0x00000308u, /* tcpwm[0].tr_out0[259] */
    TRIG_IN_MUX_3_TCPWM_16M_TR_OUT04 = 0x00000309u, /* tcpwm[0].tr_out0[260] */
    TRIG_IN_MUX_3_TCPWM_16M_TR_OUT05 = 0x0000030Au, /* tcpwm[0].tr_out0[261] */
    TRIG_IN_MUX_3_TCPWM_16M_TR_OUT06 = 0x0000030Bu, /* tcpwm[0].tr_out0[262] */
    TRIG_IN_MUX_3_TCPWM_16M_TR_OUT07 = 0x0000030Cu, /* tcpwm[0].tr_out0[263] */
    TRIG_IN_MUX_3_TCPWM_16M_TR_OUT08 = 0x0000030Du, /* tcpwm[0].tr_out0[264] */
    TRIG_IN_MUX_3_TCPWM_16M_TR_OUT09 = 0x0000030Eu, /* tcpwm[0].tr_out0[265] */
    TRIG_IN_MUX_3_TCPWM_16M_TR_OUT010 = 0x0000030Fu, /* tcpwm[0].tr_out0[266] */
    TRIG_IN_MUX_3_TCPWM_16M_TR_OUT011 = 0x00000310u, /* tcpwm[0].tr_out0[267] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT00 = 0x00000311u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT01 = 0x00000312u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT02 = 0x00000313u, /* tcpwm[0].tr_out0[2] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT03 = 0x00000314u, /* tcpwm[0].tr_out0[3] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT04 = 0x00000315u, /* tcpwm[0].tr_out0[4] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT05 = 0x00000316u, /* tcpwm[0].tr_out0[5] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT06 = 0x00000317u, /* tcpwm[0].tr_out0[6] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT07 = 0x00000318u, /* tcpwm[0].tr_out0[7] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT08 = 0x00000319u, /* tcpwm[0].tr_out0[8] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT09 = 0x0000031Au, /* tcpwm[0].tr_out0[9] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT010 = 0x0000031Bu, /* tcpwm[0].tr_out0[10] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT011 = 0x0000031Cu, /* tcpwm[0].tr_out0[11] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT012 = 0x0000031Du, /* tcpwm[0].tr_out0[12] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT013 = 0x0000031Eu, /* tcpwm[0].tr_out0[13] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT014 = 0x0000031Fu, /* tcpwm[0].tr_out0[14] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT015 = 0x00000320u, /* tcpwm[0].tr_out0[15] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT016 = 0x00000321u, /* tcpwm[0].tr_out0[16] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT017 = 0x00000322u, /* tcpwm[0].tr_out0[17] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT018 = 0x00000323u, /* tcpwm[0].tr_out0[18] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT019 = 0x00000324u, /* tcpwm[0].tr_out0[19] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT020 = 0x00000325u, /* tcpwm[0].tr_out0[20] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT021 = 0x00000326u, /* tcpwm[0].tr_out0[21] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT022 = 0x00000327u, /* tcpwm[0].tr_out0[22] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT023 = 0x00000328u, /* tcpwm[0].tr_out0[23] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT024 = 0x00000329u, /* tcpwm[0].tr_out0[24] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT025 = 0x0000032Au, /* tcpwm[0].tr_out0[25] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT026 = 0x0000032Bu, /* tcpwm[0].tr_out0[26] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT027 = 0x0000032Cu, /* tcpwm[0].tr_out0[27] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT028 = 0x0000032Du, /* tcpwm[0].tr_out0[28] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT029 = 0x0000032Eu, /* tcpwm[0].tr_out0[29] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT030 = 0x0000032Fu, /* tcpwm[0].tr_out0[30] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT031 = 0x00000330u, /* tcpwm[0].tr_out0[31] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT032 = 0x00000331u, /* tcpwm[0].tr_out0[32] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT033 = 0x00000332u, /* tcpwm[0].tr_out0[33] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT034 = 0x00000333u, /* tcpwm[0].tr_out0[34] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT035 = 0x00000334u, /* tcpwm[0].tr_out0[35] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT036 = 0x00000335u, /* tcpwm[0].tr_out0[36] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT037 = 0x00000336u, /* tcpwm[0].tr_out0[37] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT038 = 0x00000337u, /* tcpwm[0].tr_out0[38] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT039 = 0x00000338u, /* tcpwm[0].tr_out0[39] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT040 = 0x00000339u, /* tcpwm[0].tr_out0[40] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT041 = 0x0000033Au, /* tcpwm[0].tr_out0[41] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT042 = 0x0000033Bu, /* tcpwm[0].tr_out0[42] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT043 = 0x0000033Cu, /* tcpwm[0].tr_out0[43] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT044 = 0x0000033Du, /* tcpwm[0].tr_out0[44] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT045 = 0x0000033Eu, /* tcpwm[0].tr_out0[45] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT046 = 0x0000033Fu, /* tcpwm[0].tr_out0[46] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT047 = 0x00000340u, /* tcpwm[0].tr_out0[47] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT048 = 0x00000341u, /* tcpwm[0].tr_out0[48] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT049 = 0x00000342u, /* tcpwm[0].tr_out0[49] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT050 = 0x00000343u, /* tcpwm[0].tr_out0[50] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT051 = 0x00000344u, /* tcpwm[0].tr_out0[51] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT052 = 0x00000345u, /* tcpwm[0].tr_out0[52] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT053 = 0x00000346u, /* tcpwm[0].tr_out0[53] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT054 = 0x00000347u, /* tcpwm[0].tr_out0[54] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT055 = 0x00000348u, /* tcpwm[0].tr_out0[55] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT056 = 0x00000349u, /* tcpwm[0].tr_out0[56] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT057 = 0x0000034Au, /* tcpwm[0].tr_out0[57] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT058 = 0x0000034Bu, /* tcpwm[0].tr_out0[58] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT059 = 0x0000034Cu, /* tcpwm[0].tr_out0[59] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT060 = 0x0000034Du, /* tcpwm[0].tr_out0[60] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT061 = 0x0000034Eu, /* tcpwm[0].tr_out0[61] */
    TRIG_IN_MUX_3_TCPWM_16_TR_OUT062 = 0x0000034Fu, /* tcpwm[0].tr_out0[62] */
    TRIG_IN_MUX_3_CAN0_TT_TR_OUT0   = 0x00000350u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_3_CAN0_TT_TR_OUT1   = 0x00000351u, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_3_CAN0_TT_TR_OUT2   = 0x00000352u, /* canfd[0].tr_tmp_rtp_out[2] */
    TRIG_IN_MUX_3_CAN1_TT_TR_OUT0   = 0x00000353u, /* canfd[1].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_3_CAN1_TT_TR_OUT1   = 0x00000354u, /* canfd[1].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_3_CAN1_TT_TR_OUT2   = 0x00000355u /* canfd[1].tr_tmp_rtp_out[2] */
} en_trig_input_tcpwm_to_pdma0_t;

/* Trigger Input Group 4 - Reduces tcpwm output triggers to 16 signals, to allow chaining TCPWMs */
typedef enum
{
    TRIG_IN_MUX_4_TCPWM_32_TR_OUT00 = 0x00000401u, /* tcpwm[0].tr_out0[512] */
    TRIG_IN_MUX_4_TCPWM_32_TR_OUT01 = 0x00000402u, /* tcpwm[0].tr_out0[513] */
    TRIG_IN_MUX_4_TCPWM_32_TR_OUT02 = 0x00000403u, /* tcpwm[0].tr_out0[514] */
    TRIG_IN_MUX_4_TCPWM_32_TR_OUT03 = 0x00000404u, /* tcpwm[0].tr_out0[515] */
    TRIG_IN_MUX_4_TCPWM_16M_TR_OUT00 = 0x00000405u, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_4_TCPWM_16M_TR_OUT01 = 0x00000406u, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_4_TCPWM_16M_TR_OUT02 = 0x00000407u, /* tcpwm[0].tr_out0[258] */
    TRIG_IN_MUX_4_TCPWM_16M_TR_OUT03 = 0x00000408u, /* tcpwm[0].tr_out0[259] */
    TRIG_IN_MUX_4_TCPWM_16M_TR_OUT04 = 0x00000409u, /* tcpwm[0].tr_out0[260] */
    TRIG_IN_MUX_4_TCPWM_16M_TR_OUT05 = 0x0000040Au, /* tcpwm[0].tr_out0[261] */
    TRIG_IN_MUX_4_TCPWM_16M_TR_OUT06 = 0x0000040Bu, /* tcpwm[0].tr_out0[262] */
    TRIG_IN_MUX_4_TCPWM_16M_TR_OUT07 = 0x0000040Cu, /* tcpwm[0].tr_out0[263] */
    TRIG_IN_MUX_4_TCPWM_16M_TR_OUT08 = 0x0000040Du, /* tcpwm[0].tr_out0[264] */
    TRIG_IN_MUX_4_TCPWM_16M_TR_OUT09 = 0x0000040Eu, /* tcpwm[0].tr_out0[265] */
    TRIG_IN_MUX_4_TCPWM_16M_TR_OUT010 = 0x0000040Fu, /* tcpwm[0].tr_out0[266] */
    TRIG_IN_MUX_4_TCPWM_16M_TR_OUT011 = 0x00000410u, /* tcpwm[0].tr_out0[267] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT00 = 0x00000411u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT01 = 0x00000412u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT02 = 0x00000413u, /* tcpwm[0].tr_out0[2] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT03 = 0x00000414u, /* tcpwm[0].tr_out0[3] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT04 = 0x00000415u, /* tcpwm[0].tr_out0[4] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT05 = 0x00000416u, /* tcpwm[0].tr_out0[5] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT06 = 0x00000417u, /* tcpwm[0].tr_out0[6] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT07 = 0x00000418u, /* tcpwm[0].tr_out0[7] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT08 = 0x00000419u, /* tcpwm[0].tr_out0[8] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT09 = 0x0000041Au, /* tcpwm[0].tr_out0[9] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT010 = 0x0000041Bu, /* tcpwm[0].tr_out0[10] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT011 = 0x0000041Cu, /* tcpwm[0].tr_out0[11] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT012 = 0x0000041Du, /* tcpwm[0].tr_out0[12] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT013 = 0x0000041Eu, /* tcpwm[0].tr_out0[13] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT014 = 0x0000041Fu, /* tcpwm[0].tr_out0[14] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT015 = 0x00000420u, /* tcpwm[0].tr_out0[15] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT016 = 0x00000421u, /* tcpwm[0].tr_out0[16] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT017 = 0x00000422u, /* tcpwm[0].tr_out0[17] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT018 = 0x00000423u, /* tcpwm[0].tr_out0[18] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT019 = 0x00000424u, /* tcpwm[0].tr_out0[19] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT020 = 0x00000425u, /* tcpwm[0].tr_out0[20] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT021 = 0x00000426u, /* tcpwm[0].tr_out0[21] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT022 = 0x00000427u, /* tcpwm[0].tr_out0[22] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT023 = 0x00000428u, /* tcpwm[0].tr_out0[23] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT024 = 0x00000429u, /* tcpwm[0].tr_out0[24] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT025 = 0x0000042Au, /* tcpwm[0].tr_out0[25] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT026 = 0x0000042Bu, /* tcpwm[0].tr_out0[26] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT027 = 0x0000042Cu, /* tcpwm[0].tr_out0[27] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT028 = 0x0000042Du, /* tcpwm[0].tr_out0[28] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT029 = 0x0000042Eu, /* tcpwm[0].tr_out0[29] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT030 = 0x0000042Fu, /* tcpwm[0].tr_out0[30] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT031 = 0x00000430u, /* tcpwm[0].tr_out0[31] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT032 = 0x00000431u, /* tcpwm[0].tr_out0[32] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT033 = 0x00000432u, /* tcpwm[0].tr_out0[33] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT034 = 0x00000433u, /* tcpwm[0].tr_out0[34] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT035 = 0x00000434u, /* tcpwm[0].tr_out0[35] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT036 = 0x00000435u, /* tcpwm[0].tr_out0[36] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT037 = 0x00000436u, /* tcpwm[0].tr_out0[37] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT038 = 0x00000437u, /* tcpwm[0].tr_out0[38] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT039 = 0x00000438u, /* tcpwm[0].tr_out0[39] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT040 = 0x00000439u, /* tcpwm[0].tr_out0[40] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT041 = 0x0000043Au, /* tcpwm[0].tr_out0[41] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT042 = 0x0000043Bu, /* tcpwm[0].tr_out0[42] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT043 = 0x0000043Cu, /* tcpwm[0].tr_out0[43] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT044 = 0x0000043Du, /* tcpwm[0].tr_out0[44] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT045 = 0x0000043Eu, /* tcpwm[0].tr_out0[45] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT046 = 0x0000043Fu, /* tcpwm[0].tr_out0[46] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT047 = 0x00000440u, /* tcpwm[0].tr_out0[47] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT048 = 0x00000441u, /* tcpwm[0].tr_out0[48] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT049 = 0x00000442u, /* tcpwm[0].tr_out0[49] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT050 = 0x00000443u, /* tcpwm[0].tr_out0[50] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT051 = 0x00000444u, /* tcpwm[0].tr_out0[51] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT052 = 0x00000445u, /* tcpwm[0].tr_out0[52] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT053 = 0x00000446u, /* tcpwm[0].tr_out0[53] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT054 = 0x00000447u, /* tcpwm[0].tr_out0[54] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT055 = 0x00000448u, /* tcpwm[0].tr_out0[55] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT056 = 0x00000449u, /* tcpwm[0].tr_out0[56] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT057 = 0x0000044Au, /* tcpwm[0].tr_out0[57] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT058 = 0x0000044Bu, /* tcpwm[0].tr_out0[58] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT059 = 0x0000044Cu, /* tcpwm[0].tr_out0[59] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT060 = 0x0000044Du, /* tcpwm[0].tr_out0[60] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT061 = 0x0000044Eu, /* tcpwm[0].tr_out0[61] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT062 = 0x0000044Fu, /* tcpwm[0].tr_out0[62] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT10 = 0x00000450u, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT11 = 0x00000451u, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT12 = 0x00000452u, /* tcpwm[0].tr_out1[2] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT13 = 0x00000453u, /* tcpwm[0].tr_out1[3] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT14 = 0x00000454u, /* tcpwm[0].tr_out1[4] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT15 = 0x00000455u, /* tcpwm[0].tr_out1[5] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT16 = 0x00000456u, /* tcpwm[0].tr_out1[6] */
    TRIG_IN_MUX_4_TCPWM_16_TR_OUT17 = 0x00000457u, /* tcpwm[0].tr_out1[7] */
    TRIG_IN_MUX_4_CAN0_TT_TR_OUT0   = 0x00000458u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_4_CAN0_TT_TR_OUT1   = 0x00000459u, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_4_CAN0_TT_TR_OUT2   = 0x0000045Au, /* canfd[0].tr_tmp_rtp_out[2] */
    TRIG_IN_MUX_4_CAN1_TT_TR_OUT0   = 0x0000045Bu, /* canfd[1].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_4_CAN1_TT_TR_OUT1   = 0x0000045Cu, /* canfd[1].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_4_CAN1_TT_TR_OUT2   = 0x0000045Du /* canfd[1].tr_tmp_rtp_out[2] */
} en_trig_input_tcpwm_out_t;

/* Trigger Input Group 5 - TCPWM trigger inputs */
typedef enum
{
    TRIG_IN_MUX_5_PDMA0_TR_OUT0     = 0x00000501u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT1     = 0x00000502u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT2     = 0x00000503u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT3     = 0x00000504u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT4     = 0x00000505u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT5     = 0x00000506u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT6     = 0x00000507u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT7     = 0x00000508u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT8     = 0x00000509u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT9     = 0x0000050Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT10    = 0x0000050Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT11    = 0x0000050Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT12    = 0x0000050Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT13    = 0x0000050Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT14    = 0x0000050Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT15    = 0x00000510u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT0     = 0x00000511u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT1     = 0x00000512u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT2     = 0x00000513u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT3     = 0x00000514u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT4     = 0x00000515u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT5     = 0x00000516u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT6     = 0x00000517u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT7     = 0x00000518u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_5_MDMA_TR_OUT0      = 0x00000519u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_5_MDMA_TR_OUT1      = 0x0000051Au, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_5_MDMA_TR_OUT2      = 0x0000051Bu, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_5_MDMA_TR_OUT3      = 0x0000051Cu, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_5_CTI_TR_OUT0       = 0x0000051Du, /* cpuss.cti_tr_out[0] */
    TRIG_IN_MUX_5_CTI_TR_OUT1       = 0x0000051Eu, /* cpuss.cti_tr_out[1] */
    TRIG_IN_MUX_5_FAULT_TR_OUT0     = 0x0000051Fu, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_5_FAULT_TR_OUT1     = 0x00000520u, /* cpuss.tr_fault[1] */
    TRIG_IN_MUX_5_FAULT_TR_OUT2     = 0x00000521u, /* cpuss.tr_fault[2] */
    TRIG_IN_MUX_5_FAULT_TR_OUT3     = 0x00000522u, /* cpuss.tr_fault[3] */
    TRIG_IN_MUX_5_PASS_GEN_TR_OUT0  = 0x00000523u, /* pass[0].tr_sar_gen_out[0] */
    TRIG_IN_MUX_5_PASS_GEN_TR_OUT1  = 0x00000524u, /* pass[0].tr_sar_gen_out[1] */
    TRIG_IN_MUX_5_PASS_GEN_TR_OUT2  = 0x00000525u, /* pass[0].tr_sar_gen_out[2] */
    TRIG_IN_MUX_5_PASS_GEN_TR_OUT3  = 0x00000526u, /* pass[0].tr_sar_gen_out[3] */
    TRIG_IN_MUX_5_PASS_GEN_TR_OUT4  = 0x00000527u, /* pass[0].tr_sar_gen_out[4] */
    TRIG_IN_MUX_5_PASS_GEN_TR_OUT5  = 0x00000528u, /* pass[0].tr_sar_gen_out[5] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT0   = 0x00000529u, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT1   = 0x0000052Au, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT2   = 0x0000052Bu, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT3   = 0x0000052Cu, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT4   = 0x0000052Du, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT5   = 0x0000052Eu, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT6   = 0x0000052Fu, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT7   = 0x00000530u, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT8   = 0x00000531u, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT9   = 0x00000532u, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT10  = 0x00000533u, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT11  = 0x00000534u, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT12  = 0x00000535u, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT13  = 0x00000536u, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT14  = 0x00000537u, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT15  = 0x00000538u, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT16  = 0x00000539u, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT17  = 0x0000053Au, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT18  = 0x0000053Bu, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT19  = 0x0000053Cu, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT20  = 0x0000053Du, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT21  = 0x0000053Eu, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT22  = 0x0000053Fu, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT23  = 0x00000540u, /* peri.tr_io_input[23] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT24  = 0x00000541u, /* peri.tr_io_input[24] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT25  = 0x00000542u, /* peri.tr_io_input[25] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT26  = 0x00000543u, /* peri.tr_io_input[26] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT27  = 0x00000544u, /* peri.tr_io_input[27] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT28  = 0x00000545u, /* peri.tr_io_input[28] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT29  = 0x00000546u, /* peri.tr_io_input[29] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT30  = 0x00000547u, /* peri.tr_io_input[30] */
    TRIG_IN_MUX_5_HSIOM_IO_INPUT31  = 0x00000548u, /* peri.tr_io_input[31] */
    TRIG_IN_MUX_5_SCB_TX_TR_OUT0    = 0x00000549u, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_5_SCB_RX_TR_OUT0    = 0x0000054Au, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT0 = 0x0000054Bu, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_SCB_TX_TR_OUT1    = 0x0000054Cu, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_5_SCB_RX_TR_OUT1    = 0x0000054Du, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT1 = 0x0000054Eu, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_SCB_TX_TR_OUT2    = 0x0000054Fu, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_5_SCB_RX_TR_OUT2    = 0x00000550u, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT2 = 0x00000551u, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_SCB_TX_TR_OUT3    = 0x00000552u, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_5_SCB_RX_TR_OUT3    = 0x00000553u, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT3 = 0x00000554u, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_SCB_TX_TR_OUT4    = 0x00000555u, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_5_SCB_RX_TR_OUT4    = 0x00000556u, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT4 = 0x00000557u, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_SCB_TX_TR_OUT5    = 0x00000558u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_5_SCB_RX_TR_OUT5    = 0x00000559u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT5 = 0x0000055Au, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_SCB_TX_TR_OUT6    = 0x0000055Bu, /* scb[6].tr_tx_req */
    TRIG_IN_MUX_5_SCB_RX_TR_OUT6    = 0x0000055Cu, /* scb[6].tr_rx_req */
    TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT6 = 0x0000055Du, /* scb[6].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_SCB_TX_TR_OUT7    = 0x0000055Eu, /* scb[7].tr_tx_req */
    TRIG_IN_MUX_5_SCB_RX_TR_OUT7    = 0x0000055Fu, /* scb[7].tr_rx_req */
    TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT7 = 0x00000560u, /* scb[7].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_CAN0_DBG_TR_OUT0  = 0x00000561u, /* canfd[0].tr_dbg_dma_req[0] */
    TRIG_IN_MUX_5_CAN0_DBG_TR_OUT1  = 0x00000562u, /* canfd[0].tr_dbg_dma_req[1] */
    TRIG_IN_MUX_5_CAN0_DBG_TR_OUT2  = 0x00000563u, /* canfd[0].tr_dbg_dma_req[2] */
    TRIG_IN_MUX_5_CAN0_FIFO0_TR_OUT0 = 0x00000564u, /* canfd[0].tr_fifo0[0] */
    TRIG_IN_MUX_5_CAN0_FIFO0_TR_OUT1 = 0x00000565u, /* canfd[0].tr_fifo0[1] */
    TRIG_IN_MUX_5_CAN0_FIFO0_TR_OUT2 = 0x00000566u, /* canfd[0].tr_fifo0[2] */
    TRIG_IN_MUX_5_CAN0_FIFO1_TR_OUT0 = 0x00000567u, /* canfd[0].tr_fifo1[0] */
    TRIG_IN_MUX_5_CAN0_FIFO1_TR_OUT1 = 0x00000568u, /* canfd[0].tr_fifo1[1] */
    TRIG_IN_MUX_5_CAN0_FIFO1_TR_OUT2 = 0x00000569u, /* canfd[0].tr_fifo1[2] */
    TRIG_IN_MUX_5_CAN1_DBG_TR_OUT0  = 0x0000056Au, /* canfd[1].tr_dbg_dma_req[0] */
    TRIG_IN_MUX_5_CAN1_DBG_TR_OUT1  = 0x0000056Bu, /* canfd[1].tr_dbg_dma_req[1] */
    TRIG_IN_MUX_5_CAN1_DBG_TR_OUT2  = 0x0000056Cu, /* canfd[1].tr_dbg_dma_req[2] */
    TRIG_IN_MUX_5_CAN1_FIFO0_TR_OUT0 = 0x0000056Du, /* canfd[1].tr_fifo0[0] */
    TRIG_IN_MUX_5_CAN1_FIFO0_TR_OUT1 = 0x0000056Eu, /* canfd[1].tr_fifo0[1] */
    TRIG_IN_MUX_5_CAN1_FIFO0_TR_OUT2 = 0x0000056Fu, /* canfd[1].tr_fifo0[2] */
    TRIG_IN_MUX_5_CAN1_FIFO1_TR_OUT0 = 0x00000570u, /* canfd[1].tr_fifo1[0] */
    TRIG_IN_MUX_5_CAN1_FIFO1_TR_OUT1 = 0x00000571u, /* canfd[1].tr_fifo1[1] */
    TRIG_IN_MUX_5_CAN1_FIFO1_TR_OUT2 = 0x00000572u, /* canfd[1].tr_fifo1[2] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT3    = 0x00000573u, /* evtgen[0].tr_out[3] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT4    = 0x00000574u, /* evtgen[0].tr_out[4] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT5    = 0x00000575u, /* evtgen[0].tr_out[5] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT6    = 0x00000576u, /* evtgen[0].tr_out[6] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT7    = 0x00000577u, /* evtgen[0].tr_out[7] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT8    = 0x00000578u, /* evtgen[0].tr_out[8] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT9    = 0x00000579u, /* evtgen[0].tr_out[9] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT10   = 0x0000057Au /* evtgen[0].tr_out[10] */
} en_trig_input_tcpwm_in_t;

/* Trigger Input Group 6 - PASS trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_6_PDMA0_TR_OUT0     = 0x00000601u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT1     = 0x00000602u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT2     = 0x00000603u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT3     = 0x00000604u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT4     = 0x00000605u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT5     = 0x00000606u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT6     = 0x00000607u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT7     = 0x00000608u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT8     = 0x00000609u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT9     = 0x0000060Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT10    = 0x0000060Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT11    = 0x0000060Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT12    = 0x0000060Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT13    = 0x0000060Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT14    = 0x0000060Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT15    = 0x00000610u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_6_CTI_TR_OUT0       = 0x00000611u, /* cpuss.cti_tr_out[0] */
    TRIG_IN_MUX_6_CTI_TR_OUT1       = 0x00000612u, /* cpuss.cti_tr_out[1] */
    TRIG_IN_MUX_6_FAULT_TR_OUT0     = 0x00000613u, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_6_FAULT_TR_OUT1     = 0x00000614u, /* cpuss.tr_fault[1] */
    TRIG_IN_MUX_6_FAULT_TR_OUT2     = 0x00000615u, /* cpuss.tr_fault[2] */
    TRIG_IN_MUX_6_FAULT_TR_OUT3     = 0x00000616u, /* cpuss.tr_fault[3] */
    TRIG_IN_MUX_6_EVTGEN_TR_OUT0    = 0x00000617u, /* evtgen[0].tr_out[0] */
    TRIG_IN_MUX_6_EVTGEN_TR_OUT1    = 0x00000618u, /* evtgen[0].tr_out[1] */
    TRIG_IN_MUX_6_EVTGEN_TR_OUT2    = 0x00000619u, /* evtgen[0].tr_out[2] */
    TRIG_IN_MUX_6_PASS_GEN_TR_OUT0  = 0x0000061Au, /* pass[0].tr_sar_gen_out[0] */
    TRIG_IN_MUX_6_PASS_GEN_TR_OUT1  = 0x0000061Bu, /* pass[0].tr_sar_gen_out[1] */
    TRIG_IN_MUX_6_PASS_GEN_TR_OUT2  = 0x0000061Cu, /* pass[0].tr_sar_gen_out[2] */
    TRIG_IN_MUX_6_PASS_GEN_TR_OUT3  = 0x0000061Du, /* pass[0].tr_sar_gen_out[3] */
    TRIG_IN_MUX_6_PASS_GEN_TR_OUT4  = 0x0000061Eu, /* pass[0].tr_sar_gen_out[4] */
    TRIG_IN_MUX_6_PASS_GEN_TR_OUT5  = 0x0000061Fu, /* pass[0].tr_sar_gen_out[5] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT0   = 0x00000620u, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT1   = 0x00000621u, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT2   = 0x00000622u, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT3   = 0x00000623u, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT4   = 0x00000624u, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT5   = 0x00000625u, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT6   = 0x00000626u, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT7   = 0x00000627u, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT8   = 0x00000628u, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT9   = 0x00000629u, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT10  = 0x0000062Au, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT11  = 0x0000062Bu, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT12  = 0x0000062Cu, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT13  = 0x0000062Du, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT14  = 0x0000062Eu, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT15  = 0x0000062Fu, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT16  = 0x00000630u, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT17  = 0x00000631u, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT18  = 0x00000632u, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT19  = 0x00000633u, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT20  = 0x00000634u, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT21  = 0x00000635u, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT22  = 0x00000636u, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT23  = 0x00000637u, /* peri.tr_io_input[23] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT24  = 0x00000638u, /* peri.tr_io_input[24] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT25  = 0x00000639u, /* peri.tr_io_input[25] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT26  = 0x0000063Au, /* peri.tr_io_input[26] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT27  = 0x0000063Bu, /* peri.tr_io_input[27] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT28  = 0x0000063Cu, /* peri.tr_io_input[28] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT29  = 0x0000063Du, /* peri.tr_io_input[29] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT30  = 0x0000063Eu, /* peri.tr_io_input[30] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT31  = 0x0000063Fu, /* peri.tr_io_input[31] */
    TRIG_IN_MUX_6_TCPWM_32_TR_OUT10 = 0x00000640u, /* tcpwm[0].tr_out1[512] */
    TRIG_IN_MUX_6_TCPWM_32_TR_OUT11 = 0x00000641u, /* tcpwm[0].tr_out1[513] */
    TRIG_IN_MUX_6_TCPWM_32_TR_OUT12 = 0x00000642u, /* tcpwm[0].tr_out1[514] */
    TRIG_IN_MUX_6_TCPWM_32_TR_OUT13 = 0x00000643u, /* tcpwm[0].tr_out1[515] */
    TRIG_IN_MUX_6_TCPWM_16M_TR_OUT10 = 0x00000644u, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_MUX_6_TCPWM_16M_TR_OUT11 = 0x00000645u, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_MUX_6_TCPWM_16M_TR_OUT12 = 0x00000646u, /* tcpwm[0].tr_out1[258] */
    TRIG_IN_MUX_6_TCPWM_16M_TR_OUT13 = 0x00000647u, /* tcpwm[0].tr_out1[259] */
    TRIG_IN_MUX_6_TCPWM_16M_TR_OUT14 = 0x00000648u, /* tcpwm[0].tr_out1[260] */
    TRIG_IN_MUX_6_TCPWM_16M_TR_OUT15 = 0x00000649u, /* tcpwm[0].tr_out1[261] */
    TRIG_IN_MUX_6_TCPWM_16M_TR_OUT16 = 0x0000064Au, /* tcpwm[0].tr_out1[262] */
    TRIG_IN_MUX_6_TCPWM_16M_TR_OUT17 = 0x0000064Bu, /* tcpwm[0].tr_out1[263] */
    TRIG_IN_MUX_6_TCPWM_16M_TR_OUT18 = 0x0000064Cu, /* tcpwm[0].tr_out1[264] */
    TRIG_IN_MUX_6_TCPWM_16M_TR_OUT19 = 0x0000064Du, /* tcpwm[0].tr_out1[265] */
    TRIG_IN_MUX_6_TCPWM_16M_TR_OUT110 = 0x0000064Eu, /* tcpwm[0].tr_out1[266] */
    TRIG_IN_MUX_6_TCPWM_16M_TR_OUT111 = 0x0000064Fu /* tcpwm[0].tr_out1[267] */
} en_trig_input_pass_t;

/* Trigger Input Group 7 - CAN TT Synchronization triggers */
typedef enum
{
    TRIG_IN_MUX_7_CAN0_TT_TR_OUT0   = 0x00000701u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_7_CAN0_TT_TR_OUT1   = 0x00000702u, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_7_CAN0_TT_TR_OUT2   = 0x00000703u, /* canfd[0].tr_tmp_rtp_out[2] */
    TRIG_IN_MUX_7_CAN1_TT_TR_OUT0   = 0x00000704u, /* canfd[1].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_7_CAN1_TT_TR_OUT1   = 0x00000705u, /* canfd[1].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_7_CAN1_TT_TR_OUT2   = 0x00000706u /* canfd[1].tr_tmp_rtp_out[2] */
} en_trig_input_cantt_t;

/* Trigger Input Group 8 - 2nd level MUX using input from MUX_9/10 */
typedef enum
{
    TRIG_IN_MUX_8_TR_GROUP9_OUTPUT0 = 0x00000801u, /* tr_group[9].output[0] */
    TRIG_IN_MUX_8_TR_GROUP9_OUTPUT1 = 0x00000802u, /* tr_group[9].output[1] */
    TRIG_IN_MUX_8_TR_GROUP9_OUTPUT2 = 0x00000803u, /* tr_group[9].output[2] */
    TRIG_IN_MUX_8_TR_GROUP9_OUTPUT3 = 0x00000804u, /* tr_group[9].output[3] */
    TRIG_IN_MUX_8_TR_GROUP9_OUTPUT4 = 0x00000805u, /* tr_group[9].output[4] */
    TRIG_IN_MUX_8_TR_GROUP10_OUTPUT0 = 0x00000806u, /* tr_group[10].output[0] */
    TRIG_IN_MUX_8_TR_GROUP10_OUTPUT1 = 0x00000807u, /* tr_group[10].output[1] */
    TRIG_IN_MUX_8_TR_GROUP10_OUTPUT2 = 0x00000808u, /* tr_group[10].output[2] */
    TRIG_IN_MUX_8_TR_GROUP10_OUTPUT3 = 0x00000809u, /* tr_group[10].output[3] */
    TRIG_IN_MUX_8_TR_GROUP10_OUTPUT4 = 0x0000080Au /* tr_group[10].output[4] */
} en_trig_input_debugmain_t;

/* Trigger Input Group 9 - Makes half of all possible triggers visible as I/O signals for debug purposes, or to build external circuitry */
typedef enum
{
    TRIG_IN_MUX_9_PDMA0_TR_OUT0     = 0x00000901u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT1     = 0x00000902u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT2     = 0x00000903u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT3     = 0x00000904u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT4     = 0x00000905u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT5     = 0x00000906u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT6     = 0x00000907u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT7     = 0x00000908u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT8     = 0x00000909u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT9     = 0x0000090Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT10    = 0x0000090Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT11    = 0x0000090Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT12    = 0x0000090Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT13    = 0x0000090Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT14    = 0x0000090Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT15    = 0x00000910u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT16    = 0x00000911u, /* cpuss.dw0_tr_out[16] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT17    = 0x00000912u, /* cpuss.dw0_tr_out[17] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT18    = 0x00000913u, /* cpuss.dw0_tr_out[18] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT19    = 0x00000914u, /* cpuss.dw0_tr_out[19] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT20    = 0x00000915u, /* cpuss.dw0_tr_out[20] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT21    = 0x00000916u, /* cpuss.dw0_tr_out[21] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT22    = 0x00000917u, /* cpuss.dw0_tr_out[22] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT23    = 0x00000918u, /* cpuss.dw0_tr_out[23] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT24    = 0x00000919u, /* cpuss.dw0_tr_out[24] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT25    = 0x0000091Au, /* cpuss.dw0_tr_out[25] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT26    = 0x0000091Bu, /* cpuss.dw0_tr_out[26] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT27    = 0x0000091Cu, /* cpuss.dw0_tr_out[27] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT28    = 0x0000091Du, /* cpuss.dw0_tr_out[28] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT29    = 0x0000091Eu, /* cpuss.dw0_tr_out[29] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT30    = 0x0000091Fu, /* cpuss.dw0_tr_out[30] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT31    = 0x00000920u, /* cpuss.dw0_tr_out[31] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT32    = 0x00000921u, /* cpuss.dw0_tr_out[32] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT33    = 0x00000922u, /* cpuss.dw0_tr_out[33] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT34    = 0x00000923u, /* cpuss.dw0_tr_out[34] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT35    = 0x00000924u, /* cpuss.dw0_tr_out[35] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT36    = 0x00000925u, /* cpuss.dw0_tr_out[36] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT37    = 0x00000926u, /* cpuss.dw0_tr_out[37] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT38    = 0x00000927u, /* cpuss.dw0_tr_out[38] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT39    = 0x00000928u, /* cpuss.dw0_tr_out[39] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT40    = 0x00000929u, /* cpuss.dw0_tr_out[40] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT41    = 0x0000092Au, /* cpuss.dw0_tr_out[41] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT42    = 0x0000092Bu, /* cpuss.dw0_tr_out[42] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT43    = 0x0000092Cu, /* cpuss.dw0_tr_out[43] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT44    = 0x0000092Du, /* cpuss.dw0_tr_out[44] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT45    = 0x0000092Eu, /* cpuss.dw0_tr_out[45] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT46    = 0x0000092Fu, /* cpuss.dw0_tr_out[46] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT47    = 0x00000930u, /* cpuss.dw0_tr_out[47] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT48    = 0x00000931u, /* cpuss.dw0_tr_out[48] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT49    = 0x00000932u, /* cpuss.dw0_tr_out[49] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT50    = 0x00000933u, /* cpuss.dw0_tr_out[50] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT51    = 0x00000934u, /* cpuss.dw0_tr_out[51] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT52    = 0x00000935u, /* cpuss.dw0_tr_out[52] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT53    = 0x00000936u, /* cpuss.dw0_tr_out[53] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT54    = 0x00000937u, /* cpuss.dw0_tr_out[54] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT55    = 0x00000938u, /* cpuss.dw0_tr_out[55] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT56    = 0x00000939u, /* cpuss.dw0_tr_out[56] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT57    = 0x0000093Au, /* cpuss.dw0_tr_out[57] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT58    = 0x0000093Bu, /* cpuss.dw0_tr_out[58] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT59    = 0x0000093Cu, /* cpuss.dw0_tr_out[59] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT60    = 0x0000093Du, /* cpuss.dw0_tr_out[60] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT61    = 0x0000093Eu, /* cpuss.dw0_tr_out[61] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT62    = 0x0000093Fu, /* cpuss.dw0_tr_out[62] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT63    = 0x00000940u, /* cpuss.dw0_tr_out[63] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT64    = 0x00000941u, /* cpuss.dw0_tr_out[64] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT65    = 0x00000942u, /* cpuss.dw0_tr_out[65] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT66    = 0x00000943u, /* cpuss.dw0_tr_out[66] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT67    = 0x00000944u, /* cpuss.dw0_tr_out[67] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT68    = 0x00000945u, /* cpuss.dw0_tr_out[68] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT69    = 0x00000946u, /* cpuss.dw0_tr_out[69] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT70    = 0x00000947u, /* cpuss.dw0_tr_out[70] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT71    = 0x00000948u, /* cpuss.dw0_tr_out[71] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT72    = 0x00000949u, /* cpuss.dw0_tr_out[72] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT73    = 0x0000094Au, /* cpuss.dw0_tr_out[73] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT74    = 0x0000094Bu, /* cpuss.dw0_tr_out[74] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT75    = 0x0000094Cu, /* cpuss.dw0_tr_out[75] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT76    = 0x0000094Du, /* cpuss.dw0_tr_out[76] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT77    = 0x0000094Eu, /* cpuss.dw0_tr_out[77] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT78    = 0x0000094Fu, /* cpuss.dw0_tr_out[78] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT79    = 0x00000950u, /* cpuss.dw0_tr_out[79] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT80    = 0x00000951u, /* cpuss.dw0_tr_out[80] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT81    = 0x00000952u, /* cpuss.dw0_tr_out[81] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT82    = 0x00000953u, /* cpuss.dw0_tr_out[82] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT83    = 0x00000954u, /* cpuss.dw0_tr_out[83] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT84    = 0x00000955u, /* cpuss.dw0_tr_out[84] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT85    = 0x00000956u, /* cpuss.dw0_tr_out[85] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT86    = 0x00000957u, /* cpuss.dw0_tr_out[86] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT87    = 0x00000958u, /* cpuss.dw0_tr_out[87] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT88    = 0x00000959u, /* cpuss.dw0_tr_out[88] */
    TRIG_IN_MUX_9_SCB_TX_TR_OUT0    = 0x0000095Au, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_9_SCB_TX_TR_OUT1    = 0x0000095Bu, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_9_SCB_TX_TR_OUT2    = 0x0000095Cu, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_9_SCB_TX_TR_OUT3    = 0x0000095Du, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_9_SCB_TX_TR_OUT4    = 0x0000095Eu, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_9_SCB_TX_TR_OUT5    = 0x0000095Fu, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_9_SCB_TX_TR_OUT6    = 0x00000960u, /* scb[6].tr_tx_req */
    TRIG_IN_MUX_9_SCB_TX_TR_OUT7    = 0x00000961u, /* scb[7].tr_tx_req */
    TRIG_IN_MUX_9_SCB_RX_TR_OUT0    = 0x00000962u, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_9_SCB_RX_TR_OUT1    = 0x00000963u, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_9_SCB_RX_TR_OUT2    = 0x00000964u, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_9_SCB_RX_TR_OUT3    = 0x00000965u, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_9_SCB_RX_TR_OUT4    = 0x00000966u, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_9_SCB_RX_TR_OUT5    = 0x00000967u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_9_SCB_RX_TR_OUT6    = 0x00000968u, /* scb[6].tr_rx_req */
    TRIG_IN_MUX_9_SCB_RX_TR_OUT7    = 0x00000969u, /* scb[7].tr_rx_req */
    TRIG_IN_MUX_9_SCB_I2C_SCL_TR_OUT0 = 0x0000096Au, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_9_SCB_I2C_SCL_TR_OUT1 = 0x0000096Bu, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_9_SCB_I2C_SCL_TR_OUT2 = 0x0000096Cu, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_9_SCB_I2C_SCL_TR_OUT3 = 0x0000096Du, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_9_SCB_I2C_SCL_TR_OUT4 = 0x0000096Eu, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_9_SCB_I2C_SCL_TR_OUT5 = 0x0000096Fu, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_9_SCB_I2C_SCL_TR_OUT6 = 0x00000970u, /* scb[6].tr_i2c_scl_filtered */
    TRIG_IN_MUX_9_SCB_I2C_SCL_TR_OUT7 = 0x00000971u, /* scb[7].tr_i2c_scl_filtered */
    TRIG_IN_MUX_9_CAN0_DBG_TR_OUT0  = 0x00000972u, /* canfd[0].tr_dbg_dma_req[0] */
    TRIG_IN_MUX_9_CAN0_DBG_TR_OUT1  = 0x00000973u, /* canfd[0].tr_dbg_dma_req[1] */
    TRIG_IN_MUX_9_CAN0_DBG_TR_OUT2  = 0x00000974u, /* canfd[0].tr_dbg_dma_req[2] */
    TRIG_IN_MUX_9_CAN0_FIFO0_TR_OUT0 = 0x00000975u, /* canfd[0].tr_fifo0[0] */
    TRIG_IN_MUX_9_CAN0_FIFO0_TR_OUT1 = 0x00000976u, /* canfd[0].tr_fifo0[1] */
    TRIG_IN_MUX_9_CAN0_FIFO0_TR_OUT2 = 0x00000977u, /* canfd[0].tr_fifo0[2] */
    TRIG_IN_MUX_9_CAN0_FIFO1_TR_OUT0 = 0x00000978u, /* canfd[0].tr_fifo1[0] */
    TRIG_IN_MUX_9_CAN0_FIFO1_TR_OUT1 = 0x00000979u, /* canfd[0].tr_fifo1[1] */
    TRIG_IN_MUX_9_CAN0_FIFO1_TR_OUT2 = 0x0000097Au, /* canfd[0].tr_fifo1[2] */
    TRIG_IN_MUX_9_CAN0_TT_TR_OUT0   = 0x0000097Bu, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_9_CAN0_TT_TR_OUT1   = 0x0000097Cu, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_9_CAN0_TT_TR_OUT2   = 0x0000097Du, /* canfd[0].tr_tmp_rtp_out[2] */
    TRIG_IN_MUX_9_CAN1_DBG_TR_OUT0  = 0x0000097Eu, /* canfd[1].tr_dbg_dma_req[0] */
    TRIG_IN_MUX_9_CAN1_DBG_TR_OUT1  = 0x0000097Fu, /* canfd[1].tr_dbg_dma_req[1] */
    TRIG_IN_MUX_9_CAN1_DBG_TR_OUT2  = 0x00000980u, /* canfd[1].tr_dbg_dma_req[2] */
    TRIG_IN_MUX_9_CAN1_FIFO0_TR_OUT0 = 0x00000981u, /* canfd[1].tr_fifo0[0] */
    TRIG_IN_MUX_9_CAN1_FIFO0_TR_OUT1 = 0x00000982u, /* canfd[1].tr_fifo0[1] */
    TRIG_IN_MUX_9_CAN1_FIFO0_TR_OUT2 = 0x00000983u, /* canfd[1].tr_fifo0[2] */
    TRIG_IN_MUX_9_CAN1_FIFO1_TR_OUT0 = 0x00000984u, /* canfd[1].tr_fifo1[0] */
    TRIG_IN_MUX_9_CAN1_FIFO1_TR_OUT1 = 0x00000985u, /* canfd[1].tr_fifo1[1] */
    TRIG_IN_MUX_9_CAN1_FIFO1_TR_OUT2 = 0x00000986u, /* canfd[1].tr_fifo1[2] */
    TRIG_IN_MUX_9_CAN1_TT_TR_OUT0   = 0x00000987u, /* canfd[1].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_9_CAN1_TT_TR_OUT1   = 0x00000988u, /* canfd[1].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_9_CAN1_TT_TR_OUT2   = 0x00000989u, /* canfd[1].tr_tmp_rtp_out[2] */
    TRIG_IN_MUX_9_CTI_TR_OUT0       = 0x0000098Au, /* cpuss.cti_tr_out[0] */
    TRIG_IN_MUX_9_CTI_TR_OUT1       = 0x0000098Bu, /* cpuss.cti_tr_out[1] */
    TRIG_IN_MUX_9_FAULT_TR_OUT0     = 0x0000098Cu, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_9_FAULT_TR_OUT1     = 0x0000098Du, /* cpuss.tr_fault[1] */
    TRIG_IN_MUX_9_FAULT_TR_OUT2     = 0x0000098Eu, /* cpuss.tr_fault[2] */
    TRIG_IN_MUX_9_FAULT_TR_OUT3     = 0x0000098Fu, /* cpuss.tr_fault[3] */
    TRIG_IN_MUX_9_TCPWM_32_TR_OUT00 = 0x00000990u, /* tcpwm[0].tr_out0[512] */
    TRIG_IN_MUX_9_TCPWM_32_TR_OUT01 = 0x00000991u, /* tcpwm[0].tr_out0[513] */
    TRIG_IN_MUX_9_TCPWM_32_TR_OUT02 = 0x00000992u, /* tcpwm[0].tr_out0[514] */
    TRIG_IN_MUX_9_TCPWM_32_TR_OUT03 = 0x00000993u, /* tcpwm[0].tr_out0[515] */
    TRIG_IN_MUX_9_TCPWM_16M_TR_OUT00 = 0x00000994u, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_9_TCPWM_16M_TR_OUT01 = 0x00000995u, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_9_TCPWM_16M_TR_OUT02 = 0x00000996u, /* tcpwm[0].tr_out0[258] */
    TRIG_IN_MUX_9_TCPWM_16M_TR_OUT03 = 0x00000997u, /* tcpwm[0].tr_out0[259] */
    TRIG_IN_MUX_9_TCPWM_16M_TR_OUT04 = 0x00000998u, /* tcpwm[0].tr_out0[260] */
    TRIG_IN_MUX_9_TCPWM_16M_TR_OUT05 = 0x00000999u, /* tcpwm[0].tr_out0[261] */
    TRIG_IN_MUX_9_TCPWM_16M_TR_OUT06 = 0x0000099Au, /* tcpwm[0].tr_out0[262] */
    TRIG_IN_MUX_9_TCPWM_16M_TR_OUT07 = 0x0000099Bu, /* tcpwm[0].tr_out0[263] */
    TRIG_IN_MUX_9_TCPWM_16M_TR_OUT08 = 0x0000099Cu, /* tcpwm[0].tr_out0[264] */
    TRIG_IN_MUX_9_TCPWM_16M_TR_OUT09 = 0x0000099Du, /* tcpwm[0].tr_out0[265] */
    TRIG_IN_MUX_9_TCPWM_16M_TR_OUT010 = 0x0000099Eu, /* tcpwm[0].tr_out0[266] */
    TRIG_IN_MUX_9_TCPWM_16M_TR_OUT011 = 0x0000099Fu, /* tcpwm[0].tr_out0[267] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT00 = 0x000009A0u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT01 = 0x000009A1u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT02 = 0x000009A2u, /* tcpwm[0].tr_out0[2] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT03 = 0x000009A3u, /* tcpwm[0].tr_out0[3] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT04 = 0x000009A4u, /* tcpwm[0].tr_out0[4] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT05 = 0x000009A5u, /* tcpwm[0].tr_out0[5] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT06 = 0x000009A6u, /* tcpwm[0].tr_out0[6] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT07 = 0x000009A7u, /* tcpwm[0].tr_out0[7] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT08 = 0x000009A8u, /* tcpwm[0].tr_out0[8] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT09 = 0x000009A9u, /* tcpwm[0].tr_out0[9] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT010 = 0x000009AAu, /* tcpwm[0].tr_out0[10] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT011 = 0x000009ABu, /* tcpwm[0].tr_out0[11] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT012 = 0x000009ACu, /* tcpwm[0].tr_out0[12] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT013 = 0x000009ADu, /* tcpwm[0].tr_out0[13] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT014 = 0x000009AEu, /* tcpwm[0].tr_out0[14] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT015 = 0x000009AFu, /* tcpwm[0].tr_out0[15] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT016 = 0x000009B0u, /* tcpwm[0].tr_out0[16] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT017 = 0x000009B1u, /* tcpwm[0].tr_out0[17] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT018 = 0x000009B2u, /* tcpwm[0].tr_out0[18] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT019 = 0x000009B3u, /* tcpwm[0].tr_out0[19] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT020 = 0x000009B4u, /* tcpwm[0].tr_out0[20] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT021 = 0x000009B5u, /* tcpwm[0].tr_out0[21] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT022 = 0x000009B6u, /* tcpwm[0].tr_out0[22] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT023 = 0x000009B7u, /* tcpwm[0].tr_out0[23] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT024 = 0x000009B8u, /* tcpwm[0].tr_out0[24] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT025 = 0x000009B9u, /* tcpwm[0].tr_out0[25] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT026 = 0x000009BAu, /* tcpwm[0].tr_out0[26] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT027 = 0x000009BBu, /* tcpwm[0].tr_out0[27] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT028 = 0x000009BCu, /* tcpwm[0].tr_out0[28] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT029 = 0x000009BDu, /* tcpwm[0].tr_out0[29] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT030 = 0x000009BEu, /* tcpwm[0].tr_out0[30] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT031 = 0x000009BFu, /* tcpwm[0].tr_out0[31] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT032 = 0x000009C0u, /* tcpwm[0].tr_out0[32] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT033 = 0x000009C1u, /* tcpwm[0].tr_out0[33] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT034 = 0x000009C2u, /* tcpwm[0].tr_out0[34] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT035 = 0x000009C3u, /* tcpwm[0].tr_out0[35] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT036 = 0x000009C4u, /* tcpwm[0].tr_out0[36] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT037 = 0x000009C5u, /* tcpwm[0].tr_out0[37] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT038 = 0x000009C6u, /* tcpwm[0].tr_out0[38] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT039 = 0x000009C7u, /* tcpwm[0].tr_out0[39] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT040 = 0x000009C8u, /* tcpwm[0].tr_out0[40] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT041 = 0x000009C9u, /* tcpwm[0].tr_out0[41] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT042 = 0x000009CAu, /* tcpwm[0].tr_out0[42] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT043 = 0x000009CBu, /* tcpwm[0].tr_out0[43] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT044 = 0x000009CCu, /* tcpwm[0].tr_out0[44] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT045 = 0x000009CDu, /* tcpwm[0].tr_out0[45] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT046 = 0x000009CEu, /* tcpwm[0].tr_out0[46] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT047 = 0x000009CFu, /* tcpwm[0].tr_out0[47] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT048 = 0x000009D0u, /* tcpwm[0].tr_out0[48] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT049 = 0x000009D1u, /* tcpwm[0].tr_out0[49] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT050 = 0x000009D2u, /* tcpwm[0].tr_out0[50] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT051 = 0x000009D3u, /* tcpwm[0].tr_out0[51] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT052 = 0x000009D4u, /* tcpwm[0].tr_out0[52] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT053 = 0x000009D5u, /* tcpwm[0].tr_out0[53] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT054 = 0x000009D6u, /* tcpwm[0].tr_out0[54] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT055 = 0x000009D7u, /* tcpwm[0].tr_out0[55] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT056 = 0x000009D8u, /* tcpwm[0].tr_out0[56] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT057 = 0x000009D9u, /* tcpwm[0].tr_out0[57] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT058 = 0x000009DAu, /* tcpwm[0].tr_out0[58] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT059 = 0x000009DBu, /* tcpwm[0].tr_out0[59] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT060 = 0x000009DCu, /* tcpwm[0].tr_out0[60] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT061 = 0x000009DDu, /* tcpwm[0].tr_out0[61] */
    TRIG_IN_MUX_9_TCPWM_16_TR_OUT062 = 0x000009DEu /* tcpwm[0].tr_out0[62] */
} en_trig_input_debugreduction1_t;

/* Trigger Input Group 10 - Makes all possible triggers visible as I/O signals for debug purposes, or to build external circuitry */
typedef enum
{
    TRIG_IN_MUX_10_PDMA1_TR_OUT0    = 0x00000A01u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT1    = 0x00000A02u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT2    = 0x00000A03u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT3    = 0x00000A04u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT4    = 0x00000A05u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT5    = 0x00000A06u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT6    = 0x00000A07u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT7    = 0x00000A08u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT8    = 0x00000A09u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT9    = 0x00000A0Au, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT10   = 0x00000A0Bu, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT11   = 0x00000A0Cu, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT12   = 0x00000A0Du, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT13   = 0x00000A0Eu, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT14   = 0x00000A0Fu, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT15   = 0x00000A10u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT16   = 0x00000A11u, /* cpuss.dw1_tr_out[16] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT17   = 0x00000A12u, /* cpuss.dw1_tr_out[17] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT18   = 0x00000A13u, /* cpuss.dw1_tr_out[18] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT19   = 0x00000A14u, /* cpuss.dw1_tr_out[19] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT20   = 0x00000A15u, /* cpuss.dw1_tr_out[20] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT21   = 0x00000A16u, /* cpuss.dw1_tr_out[21] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT22   = 0x00000A17u, /* cpuss.dw1_tr_out[22] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT23   = 0x00000A18u, /* cpuss.dw1_tr_out[23] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT24   = 0x00000A19u, /* cpuss.dw1_tr_out[24] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT25   = 0x00000A1Au, /* cpuss.dw1_tr_out[25] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT26   = 0x00000A1Bu, /* cpuss.dw1_tr_out[26] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT27   = 0x00000A1Cu, /* cpuss.dw1_tr_out[27] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT28   = 0x00000A1Du, /* cpuss.dw1_tr_out[28] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT29   = 0x00000A1Eu, /* cpuss.dw1_tr_out[29] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT30   = 0x00000A1Fu, /* cpuss.dw1_tr_out[30] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT31   = 0x00000A20u, /* cpuss.dw1_tr_out[31] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT32   = 0x00000A21u, /* cpuss.dw1_tr_out[32] */
    TRIG_IN_MUX_10_MDMA_TR_OUT0     = 0x00000A22u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_10_MDMA_TR_OUT1     = 0x00000A23u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_10_MDMA_TR_OUT2     = 0x00000A24u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_10_MDMA_TR_OUT3     = 0x00000A25u, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_10_TCPWM_32_TR_OUT10 = 0x00000A26u, /* tcpwm[0].tr_out1[512] */
    TRIG_IN_MUX_10_TCPWM_32_TR_OUT11 = 0x00000A27u, /* tcpwm[0].tr_out1[513] */
    TRIG_IN_MUX_10_TCPWM_32_TR_OUT12 = 0x00000A28u, /* tcpwm[0].tr_out1[514] */
    TRIG_IN_MUX_10_TCPWM_32_TR_OUT13 = 0x00000A29u, /* tcpwm[0].tr_out1[515] */
    TRIG_IN_MUX_10_TCPWM_16M_TR_OUT10 = 0x00000A2Au, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_MUX_10_TCPWM_16M_TR_OUT11 = 0x00000A2Bu, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_MUX_10_TCPWM_16M_TR_OUT12 = 0x00000A2Cu, /* tcpwm[0].tr_out1[258] */
    TRIG_IN_MUX_10_TCPWM_16M_TR_OUT13 = 0x00000A2Du, /* tcpwm[0].tr_out1[259] */
    TRIG_IN_MUX_10_TCPWM_16M_TR_OUT14 = 0x00000A2Eu, /* tcpwm[0].tr_out1[260] */
    TRIG_IN_MUX_10_TCPWM_16M_TR_OUT15 = 0x00000A2Fu, /* tcpwm[0].tr_out1[261] */
    TRIG_IN_MUX_10_TCPWM_16M_TR_OUT16 = 0x00000A30u, /* tcpwm[0].tr_out1[262] */
    TRIG_IN_MUX_10_TCPWM_16M_TR_OUT17 = 0x00000A31u, /* tcpwm[0].tr_out1[263] */
    TRIG_IN_MUX_10_TCPWM_16M_TR_OUT18 = 0x00000A32u, /* tcpwm[0].tr_out1[264] */
    TRIG_IN_MUX_10_TCPWM_16M_TR_OUT19 = 0x00000A33u, /* tcpwm[0].tr_out1[265] */
    TRIG_IN_MUX_10_TCPWM_16M_TR_OUT110 = 0x00000A34u, /* tcpwm[0].tr_out1[266] */
    TRIG_IN_MUX_10_TCPWM_16M_TR_OUT111 = 0x00000A35u, /* tcpwm[0].tr_out1[267] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT10 = 0x00000A36u, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT11 = 0x00000A37u, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT12 = 0x00000A38u, /* tcpwm[0].tr_out1[2] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT13 = 0x00000A39u, /* tcpwm[0].tr_out1[3] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT14 = 0x00000A3Au, /* tcpwm[0].tr_out1[4] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT15 = 0x00000A3Bu, /* tcpwm[0].tr_out1[5] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT16 = 0x00000A3Cu, /* tcpwm[0].tr_out1[6] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT17 = 0x00000A3Du, /* tcpwm[0].tr_out1[7] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT18 = 0x00000A3Eu, /* tcpwm[0].tr_out1[8] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT19 = 0x00000A3Fu, /* tcpwm[0].tr_out1[9] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT110 = 0x00000A40u, /* tcpwm[0].tr_out1[10] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT111 = 0x00000A41u, /* tcpwm[0].tr_out1[11] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT112 = 0x00000A42u, /* tcpwm[0].tr_out1[12] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT113 = 0x00000A43u, /* tcpwm[0].tr_out1[13] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT114 = 0x00000A44u, /* tcpwm[0].tr_out1[14] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT115 = 0x00000A45u, /* tcpwm[0].tr_out1[15] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT116 = 0x00000A46u, /* tcpwm[0].tr_out1[16] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT117 = 0x00000A47u, /* tcpwm[0].tr_out1[17] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT118 = 0x00000A48u, /* tcpwm[0].tr_out1[18] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT119 = 0x00000A49u, /* tcpwm[0].tr_out1[19] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT120 = 0x00000A4Au, /* tcpwm[0].tr_out1[20] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT121 = 0x00000A4Bu, /* tcpwm[0].tr_out1[21] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT122 = 0x00000A4Cu, /* tcpwm[0].tr_out1[22] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT123 = 0x00000A4Du, /* tcpwm[0].tr_out1[23] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT124 = 0x00000A4Eu, /* tcpwm[0].tr_out1[24] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT125 = 0x00000A4Fu, /* tcpwm[0].tr_out1[25] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT126 = 0x00000A50u, /* tcpwm[0].tr_out1[26] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT127 = 0x00000A51u, /* tcpwm[0].tr_out1[27] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT128 = 0x00000A52u, /* tcpwm[0].tr_out1[28] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT129 = 0x00000A53u, /* tcpwm[0].tr_out1[29] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT130 = 0x00000A54u, /* tcpwm[0].tr_out1[30] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT131 = 0x00000A55u, /* tcpwm[0].tr_out1[31] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT132 = 0x00000A56u, /* tcpwm[0].tr_out1[32] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT133 = 0x00000A57u, /* tcpwm[0].tr_out1[33] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT134 = 0x00000A58u, /* tcpwm[0].tr_out1[34] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT135 = 0x00000A59u, /* tcpwm[0].tr_out1[35] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT136 = 0x00000A5Au, /* tcpwm[0].tr_out1[36] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT137 = 0x00000A5Bu, /* tcpwm[0].tr_out1[37] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT138 = 0x00000A5Cu, /* tcpwm[0].tr_out1[38] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT139 = 0x00000A5Du, /* tcpwm[0].tr_out1[39] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT140 = 0x00000A5Eu, /* tcpwm[0].tr_out1[40] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT141 = 0x00000A5Fu, /* tcpwm[0].tr_out1[41] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT142 = 0x00000A60u, /* tcpwm[0].tr_out1[42] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT143 = 0x00000A61u, /* tcpwm[0].tr_out1[43] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT144 = 0x00000A62u, /* tcpwm[0].tr_out1[44] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT145 = 0x00000A63u, /* tcpwm[0].tr_out1[45] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT146 = 0x00000A64u, /* tcpwm[0].tr_out1[46] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT147 = 0x00000A65u, /* tcpwm[0].tr_out1[47] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT148 = 0x00000A66u, /* tcpwm[0].tr_out1[48] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT149 = 0x00000A67u, /* tcpwm[0].tr_out1[49] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT150 = 0x00000A68u, /* tcpwm[0].tr_out1[50] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT151 = 0x00000A69u, /* tcpwm[0].tr_out1[51] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT152 = 0x00000A6Au, /* tcpwm[0].tr_out1[52] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT153 = 0x00000A6Bu, /* tcpwm[0].tr_out1[53] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT154 = 0x00000A6Cu, /* tcpwm[0].tr_out1[54] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT155 = 0x00000A6Du, /* tcpwm[0].tr_out1[55] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT156 = 0x00000A6Eu, /* tcpwm[0].tr_out1[56] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT157 = 0x00000A6Fu, /* tcpwm[0].tr_out1[57] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT158 = 0x00000A70u, /* tcpwm[0].tr_out1[58] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT159 = 0x00000A71u, /* tcpwm[0].tr_out1[59] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT160 = 0x00000A72u, /* tcpwm[0].tr_out1[60] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT161 = 0x00000A73u, /* tcpwm[0].tr_out1[61] */
    TRIG_IN_MUX_10_TCPWM_16_TR_OUT162 = 0x00000A74u, /* tcpwm[0].tr_out1[62] */
    TRIG_IN_MUX_10_PASS_GEN_TR_OUT0 = 0x00000A75u, /* pass[0].tr_sar_gen_out[0] */
    TRIG_IN_MUX_10_PASS_GEN_TR_OUT1 = 0x00000A76u, /* pass[0].tr_sar_gen_out[1] */
    TRIG_IN_MUX_10_PASS_GEN_TR_OUT2 = 0x00000A77u, /* pass[0].tr_sar_gen_out[2] */
    TRIG_IN_MUX_10_PASS_GEN_TR_OUT3 = 0x00000A78u, /* pass[0].tr_sar_gen_out[3] */
    TRIG_IN_MUX_10_PASS_GEN_TR_OUT4 = 0x00000A79u, /* pass[0].tr_sar_gen_out[4] */
    TRIG_IN_MUX_10_PASS_GEN_TR_OUT5 = 0x00000A7Au, /* pass[0].tr_sar_gen_out[5] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT0   = 0x00000A7Bu, /* evtgen[0].tr_out[0] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT1   = 0x00000A7Cu, /* evtgen[0].tr_out[1] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT2   = 0x00000A7Du, /* evtgen[0].tr_out[2] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT3   = 0x00000A7Eu, /* evtgen[0].tr_out[3] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT4   = 0x00000A7Fu, /* evtgen[0].tr_out[4] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT5   = 0x00000A80u, /* evtgen[0].tr_out[5] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT6   = 0x00000A81u, /* evtgen[0].tr_out[6] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT7   = 0x00000A82u, /* evtgen[0].tr_out[7] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT8   = 0x00000A83u, /* evtgen[0].tr_out[8] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT9   = 0x00000A84u, /* evtgen[0].tr_out[9] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT10  = 0x00000A85u /* evtgen[0].tr_out[10] */
} en_trig_input_debugreduction2_t;

/* Trigger Input Group 0 - TCPWM to LIN (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_0_TCPWM_TO_LIN_TR3 = 0x00001000u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_1TO1_0_TCPWM_TO_LIN_TR4 = 0x00001001u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_1TO1_0_TCPWM_TO_LIN_TR5 = 0x00001002u, /* tcpwm[0].tr_out0[2] */
    TRIG_IN_1TO1_0_TCPWM_TO_LIN_TR6 = 0x00001003u, /* tcpwm[0].tr_out0[3] */
    TRIG_IN_1TO1_0_TCPWM_TO_LIN_TR7 = 0x00001004u, /* tcpwm[0].tr_out0[4] */
    TRIG_IN_1TO1_0_TCPWM_TO_LIN_TR8 = 0x00001005u, /* tcpwm[0].tr_out0[5] */
    TRIG_IN_1TO1_0_TCPWM_TO_LIN_TR9 = 0x00001006u, /* tcpwm[0].tr_out0[6] */
    TRIG_IN_1TO1_0_TCPWM_TO_LIN_TR10 = 0x00001007u /* tcpwm[0].tr_out0[7] */
} en_trig_input_1to1_tcpwm_to_lin_t;

/* Trigger Input Group 1 - PWM Group 0 to PASS direct connect (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR0 = 0x00001100u, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR1 = 0x00001101u, /* tcpwm[0].tr_out1[259] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR2 = 0x00001102u, /* tcpwm[0].tr_out1[262] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR3 = 0x00001103u, /* tcpwm[0].tr_out1[265] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR4 = 0x00001104u, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR5 = 0x00001105u, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR6 = 0x00001106u, /* tcpwm[0].tr_out1[2] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR7 = 0x00001107u, /* tcpwm[0].tr_out1[3] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR8 = 0x00001108u, /* tcpwm[0].tr_out1[4] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR9 = 0x00001109u, /* tcpwm[0].tr_out1[5] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR10 = 0x0000110Au, /* tcpwm[0].tr_out1[6] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR11 = 0x0000110Bu, /* tcpwm[0].tr_out1[7] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR12 = 0x0000110Cu, /* tcpwm[0].tr_out1[8] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR13 = 0x0000110Du, /* tcpwm[0].tr_out1[9] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR14 = 0x0000110Eu, /* tcpwm[0].tr_out1[10] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR15 = 0x0000110Fu, /* tcpwm[0].tr_out1[11] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR16 = 0x00001110u, /* tcpwm[0].tr_out1[12] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR17 = 0x00001111u, /* tcpwm[0].tr_out1[13] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR18 = 0x00001112u, /* tcpwm[0].tr_out1[14] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR19 = 0x00001113u, /* tcpwm[0].tr_out1[15] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR20 = 0x00001114u, /* tcpwm[0].tr_out1[16] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR21 = 0x00001115u, /* tcpwm[0].tr_out1[17] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR22 = 0x00001116u, /* tcpwm[0].tr_out1[18] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR23 = 0x00001117u, /* tcpwm[0].tr_out1[19] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR32 = 0x00001118u, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR33 = 0x00001119u, /* tcpwm[0].tr_out1[260] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR34 = 0x0000111Au, /* tcpwm[0].tr_out1[263] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR35 = 0x0000111Bu, /* tcpwm[0].tr_out1[266] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR36 = 0x0000111Cu, /* tcpwm[0].tr_out1[20] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR37 = 0x0000111Du, /* tcpwm[0].tr_out1[21] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR38 = 0x0000111Eu, /* tcpwm[0].tr_out1[22] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR39 = 0x0000111Fu, /* tcpwm[0].tr_out1[23] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR40 = 0x00001120u, /* tcpwm[0].tr_out1[24] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR41 = 0x00001121u, /* tcpwm[0].tr_out1[25] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR42 = 0x00001122u, /* tcpwm[0].tr_out1[26] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR43 = 0x00001123u, /* tcpwm[0].tr_out1[27] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR44 = 0x00001124u, /* tcpwm[0].tr_out1[28] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR45 = 0x00001125u, /* tcpwm[0].tr_out1[29] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR46 = 0x00001126u, /* tcpwm[0].tr_out1[30] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR47 = 0x00001127u, /* tcpwm[0].tr_out1[31] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR48 = 0x00001128u, /* tcpwm[0].tr_out1[32] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR49 = 0x00001129u, /* tcpwm[0].tr_out1[33] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR50 = 0x0000112Au, /* tcpwm[0].tr_out1[34] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR51 = 0x0000112Bu, /* tcpwm[0].tr_out1[35] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR52 = 0x0000112Cu, /* tcpwm[0].tr_out1[36] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR53 = 0x0000112Du, /* tcpwm[0].tr_out1[37] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR54 = 0x0000112Eu, /* tcpwm[0].tr_out1[38] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR55 = 0x0000112Fu, /* tcpwm[0].tr_out1[39] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR56 = 0x00001130u, /* tcpwm[0].tr_out1[40] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR57 = 0x00001131u, /* tcpwm[0].tr_out1[41] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR58 = 0x00001132u, /* tcpwm[0].tr_out1[42] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR59 = 0x00001133u, /* tcpwm[0].tr_out1[43] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR60 = 0x00001134u, /* tcpwm[0].tr_out1[44] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR61 = 0x00001135u, /* tcpwm[0].tr_out1[45] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR62 = 0x00001136u, /* tcpwm[0].tr_out1[46] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR63 = 0x00001137u, /* tcpwm[0].tr_out1[47] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR64 = 0x00001138u, /* tcpwm[0].tr_out1[258] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR65 = 0x00001139u, /* tcpwm[0].tr_out1[261] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR66 = 0x0000113Au, /* tcpwm[0].tr_out1[264] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR67 = 0x0000113Bu, /* tcpwm[0].tr_out1[267] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR68 = 0x0000113Cu, /* tcpwm[0].tr_out1[48] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR69 = 0x0000113Du, /* tcpwm[0].tr_out1[49] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR70 = 0x0000113Eu, /* tcpwm[0].tr_out1[50] */
    TRIG_IN_1TO1_1_TCPWM_TO_PASS_CH_TR71 = 0x0000113Fu /* tcpwm[0].tr_out1[51] */
} en_trig_input_1to1_pwm0_to_pass_t;

/* Trigger Input Group 2 - PASS to DW0 direct connect (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA00 = 0x00001200u, /* pass[0].tr_sar_ch_done[0] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA01 = 0x00001201u, /* pass[0].tr_sar_ch_done[1] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA02 = 0x00001202u, /* pass[0].tr_sar_ch_done[2] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA03 = 0x00001203u, /* pass[0].tr_sar_ch_done[3] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA04 = 0x00001204u, /* pass[0].tr_sar_ch_done[4] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA05 = 0x00001205u, /* pass[0].tr_sar_ch_done[5] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA06 = 0x00001206u, /* pass[0].tr_sar_ch_done[6] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA07 = 0x00001207u, /* pass[0].tr_sar_ch_done[7] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA08 = 0x00001208u, /* pass[0].tr_sar_ch_done[8] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA09 = 0x00001209u, /* pass[0].tr_sar_ch_done[9] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA010 = 0x0000120Au, /* pass[0].tr_sar_ch_done[10] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA011 = 0x0000120Bu, /* pass[0].tr_sar_ch_done[11] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA012 = 0x0000120Cu, /* pass[0].tr_sar_ch_done[12] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA013 = 0x0000120Du, /* pass[0].tr_sar_ch_done[13] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA014 = 0x0000120Eu, /* pass[0].tr_sar_ch_done[14] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA015 = 0x0000120Fu, /* pass[0].tr_sar_ch_done[15] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA016 = 0x00001210u, /* pass[0].tr_sar_ch_done[16] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA017 = 0x00001211u, /* pass[0].tr_sar_ch_done[17] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA018 = 0x00001212u, /* pass[0].tr_sar_ch_done[18] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA019 = 0x00001213u, /* pass[0].tr_sar_ch_done[19] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA020 = 0x00001214u, /* pass[0].tr_sar_ch_done[20] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA021 = 0x00001215u, /* pass[0].tr_sar_ch_done[21] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA022 = 0x00001216u, /* pass[0].tr_sar_ch_done[22] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA023 = 0x00001217u, /* pass[0].tr_sar_ch_done[23] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA032 = 0x00001218u, /* pass[0].tr_sar_ch_done[32] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA033 = 0x00001219u, /* pass[0].tr_sar_ch_done[33] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA034 = 0x0000121Au, /* pass[0].tr_sar_ch_done[34] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA035 = 0x0000121Bu, /* pass[0].tr_sar_ch_done[35] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA036 = 0x0000121Cu, /* pass[0].tr_sar_ch_done[36] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA037 = 0x0000121Du, /* pass[0].tr_sar_ch_done[37] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA038 = 0x0000121Eu, /* pass[0].tr_sar_ch_done[38] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA039 = 0x0000121Fu, /* pass[0].tr_sar_ch_done[39] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA040 = 0x00001220u, /* pass[0].tr_sar_ch_done[40] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA041 = 0x00001221u, /* pass[0].tr_sar_ch_done[41] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA042 = 0x00001222u, /* pass[0].tr_sar_ch_done[42] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA043 = 0x00001223u, /* pass[0].tr_sar_ch_done[43] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA044 = 0x00001224u, /* pass[0].tr_sar_ch_done[44] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA045 = 0x00001225u, /* pass[0].tr_sar_ch_done[45] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA046 = 0x00001226u, /* pass[0].tr_sar_ch_done[46] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA047 = 0x00001227u, /* pass[0].tr_sar_ch_done[47] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA048 = 0x00001228u, /* pass[0].tr_sar_ch_done[48] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA049 = 0x00001229u, /* pass[0].tr_sar_ch_done[49] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA050 = 0x0000122Au, /* pass[0].tr_sar_ch_done[50] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA051 = 0x0000122Bu, /* pass[0].tr_sar_ch_done[51] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA052 = 0x0000122Cu, /* pass[0].tr_sar_ch_done[52] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA053 = 0x0000122Du, /* pass[0].tr_sar_ch_done[53] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA054 = 0x0000122Eu, /* pass[0].tr_sar_ch_done[54] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA055 = 0x0000122Fu, /* pass[0].tr_sar_ch_done[55] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA056 = 0x00001230u, /* pass[0].tr_sar_ch_done[56] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA057 = 0x00001231u, /* pass[0].tr_sar_ch_done[57] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA058 = 0x00001232u, /* pass[0].tr_sar_ch_done[58] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA059 = 0x00001233u, /* pass[0].tr_sar_ch_done[59] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA060 = 0x00001234u, /* pass[0].tr_sar_ch_done[60] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA061 = 0x00001235u, /* pass[0].tr_sar_ch_done[61] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA062 = 0x00001236u, /* pass[0].tr_sar_ch_done[62] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA063 = 0x00001237u, /* pass[0].tr_sar_ch_done[63] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA064 = 0x00001238u, /* pass[0].tr_sar_ch_done[64] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA065 = 0x00001239u, /* pass[0].tr_sar_ch_done[65] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA066 = 0x0000123Au, /* pass[0].tr_sar_ch_done[66] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA067 = 0x0000123Bu, /* pass[0].tr_sar_ch_done[67] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA068 = 0x0000123Cu, /* pass[0].tr_sar_ch_done[68] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA069 = 0x0000123Du, /* pass[0].tr_sar_ch_done[69] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA070 = 0x0000123Eu, /* pass[0].tr_sar_ch_done[70] */
    TRIG_IN_1TO1_2_PASS_CH_DONE_TO_PDMA071 = 0x0000123Fu /* pass[0].tr_sar_ch_done[71] */
} en_trig_input_1to1_pass_to_dw0_t;

/* Trigger Input Group 3 - PASS to PWM direct connect (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL0 = 0x00001300u, /* pass[0].tr_sar_ch_rangevio[0] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL1 = 0x00001301u, /* pass[0].tr_sar_ch_rangevio[1] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL2 = 0x00001302u, /* pass[0].tr_sar_ch_rangevio[2] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL3 = 0x00001303u, /* pass[0].tr_sar_ch_rangevio[3] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL4 = 0x00001304u, /* pass[0].tr_sar_ch_rangevio[4] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL5 = 0x00001305u, /* pass[0].tr_sar_ch_rangevio[5] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL6 = 0x00001306u, /* pass[0].tr_sar_ch_rangevio[6] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL7 = 0x00001307u, /* pass[0].tr_sar_ch_rangevio[7] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL8 = 0x00001308u, /* pass[0].tr_sar_ch_rangevio[8] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL9 = 0x00001309u, /* pass[0].tr_sar_ch_rangevio[9] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL10 = 0x0000130Au, /* pass[0].tr_sar_ch_rangevio[10] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL11 = 0x0000130Bu, /* pass[0].tr_sar_ch_rangevio[11] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL12 = 0x0000130Cu, /* pass[0].tr_sar_ch_rangevio[12] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL13 = 0x0000130Du, /* pass[0].tr_sar_ch_rangevio[13] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL14 = 0x0000130Eu, /* pass[0].tr_sar_ch_rangevio[14] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL15 = 0x0000130Fu, /* pass[0].tr_sar_ch_rangevio[15] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL16 = 0x00001310u, /* pass[0].tr_sar_ch_rangevio[16] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL17 = 0x00001311u, /* pass[0].tr_sar_ch_rangevio[17] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL18 = 0x00001312u, /* pass[0].tr_sar_ch_rangevio[18] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL19 = 0x00001313u, /* pass[0].tr_sar_ch_rangevio[19] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL20 = 0x00001314u, /* pass[0].tr_sar_ch_rangevio[20] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL21 = 0x00001315u, /* pass[0].tr_sar_ch_rangevio[21] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL22 = 0x00001316u, /* pass[0].tr_sar_ch_rangevio[22] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL23 = 0x00001317u, /* pass[0].tr_sar_ch_rangevio[23] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL24 = 0x00001318u, /* pass[0].tr_sar_ch_rangevio[32] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL25 = 0x00001319u, /* pass[0].tr_sar_ch_rangevio[33] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL26 = 0x0000131Au, /* pass[0].tr_sar_ch_rangevio[34] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL27 = 0x0000131Bu, /* pass[0].tr_sar_ch_rangevio[35] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL28 = 0x0000131Cu, /* pass[0].tr_sar_ch_rangevio[36] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL29 = 0x0000131Du, /* pass[0].tr_sar_ch_rangevio[37] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL30 = 0x0000131Eu, /* pass[0].tr_sar_ch_rangevio[38] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL31 = 0x0000131Fu, /* pass[0].tr_sar_ch_rangevio[39] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL32 = 0x00001320u, /* pass[0].tr_sar_ch_rangevio[40] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL33 = 0x00001321u, /* pass[0].tr_sar_ch_rangevio[41] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL34 = 0x00001322u, /* pass[0].tr_sar_ch_rangevio[42] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL35 = 0x00001323u, /* pass[0].tr_sar_ch_rangevio[43] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL36 = 0x00001324u, /* pass[0].tr_sar_ch_rangevio[44] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL37 = 0x00001325u, /* pass[0].tr_sar_ch_rangevio[45] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL38 = 0x00001326u, /* pass[0].tr_sar_ch_rangevio[46] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL39 = 0x00001327u, /* pass[0].tr_sar_ch_rangevio[47] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL40 = 0x00001328u, /* pass[0].tr_sar_ch_rangevio[48] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL41 = 0x00001329u, /* pass[0].tr_sar_ch_rangevio[49] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL42 = 0x0000132Au, /* pass[0].tr_sar_ch_rangevio[50] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL43 = 0x0000132Bu, /* pass[0].tr_sar_ch_rangevio[51] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL44 = 0x0000132Cu, /* pass[0].tr_sar_ch_rangevio[52] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL45 = 0x0000132Du, /* pass[0].tr_sar_ch_rangevio[53] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL46 = 0x0000132Eu, /* pass[0].tr_sar_ch_rangevio[54] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL47 = 0x0000132Fu, /* pass[0].tr_sar_ch_rangevio[55] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL48 = 0x00001330u, /* pass[0].tr_sar_ch_rangevio[56] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL49 = 0x00001331u, /* pass[0].tr_sar_ch_rangevio[57] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL50 = 0x00001332u, /* pass[0].tr_sar_ch_rangevio[58] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL51 = 0x00001333u, /* pass[0].tr_sar_ch_rangevio[59] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL52 = 0x00001334u, /* pass[0].tr_sar_ch_rangevio[60] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL53 = 0x00001335u, /* pass[0].tr_sar_ch_rangevio[61] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL54 = 0x00001336u, /* pass[0].tr_sar_ch_rangevio[62] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL55 = 0x00001337u, /* pass[0].tr_sar_ch_rangevio[63] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL56 = 0x00001338u, /* pass[0].tr_sar_ch_rangevio[64] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL57 = 0x00001339u, /* pass[0].tr_sar_ch_rangevio[65] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL58 = 0x0000133Au, /* pass[0].tr_sar_ch_rangevio[66] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL59 = 0x0000133Bu, /* pass[0].tr_sar_ch_rangevio[67] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL60 = 0x0000133Cu, /* pass[0].tr_sar_ch_rangevio[68] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL61 = 0x0000133Du, /* pass[0].tr_sar_ch_rangevio[69] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL62 = 0x0000133Eu, /* pass[0].tr_sar_ch_rangevio[70] */
    TRIG_IN_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL63 = 0x0000133Fu /* pass[0].tr_sar_ch_rangevio[71] */
} en_trig_input_1to1_pass_to_pwm_t;

/* Trigger Input Group 4 - CAN DW0 Triggers (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_4_CAN0_DBG_TO_PDMA0_0 = 0x00001400u, /* canfd[0].tr_dbg_dma_req[0] */
    TRIG_IN_1TO1_4_CAN0_FIFO0_TO_PDMA0_0 = 0x00001401u, /* canfd[0].tr_fifo0[0] */
    TRIG_IN_1TO1_4_CAN0_FIFO1_TO_PDMA0_0 = 0x00001402u, /* canfd[0].tr_fifo1[0] */
    TRIG_IN_1TO1_4_CAN0_DBG_TO_PDMA0_1 = 0x00001403u, /* canfd[0].tr_dbg_dma_req[1] */
    TRIG_IN_1TO1_4_CAN0_FIFO0_TO_PDMA0_1 = 0x00001404u, /* canfd[0].tr_fifo0[1] */
    TRIG_IN_1TO1_4_CAN0_FIFO1_TO_PDMA0_1 = 0x00001405u, /* canfd[0].tr_fifo1[1] */
    TRIG_IN_1TO1_4_CAN0_DBG_TO_PDMA0_2 = 0x00001406u, /* canfd[0].tr_dbg_dma_req[2] */
    TRIG_IN_1TO1_4_CAN0_FIFO0_TO_PDMA0_2 = 0x00001407u, /* canfd[0].tr_fifo0[2] */
    TRIG_IN_1TO1_4_CAN0_FIFO1_TO_PDMA0_2 = 0x00001408u /* canfd[0].tr_fifo1[2] */
} en_trig_input_1to1_can0_dw_tr_t;

/* Trigger Input Group 5 - CAN DW1 triggers (on DW1 to share BW) (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_5_CAN1_DBG_TO_PDMA1_0 = 0x00001500u, /* canfd[1].tr_dbg_dma_req[0] */
    TRIG_IN_1TO1_5_CAN1_FIFO0_TO_PDMA1_0 = 0x00001501u, /* canfd[1].tr_fifo0[0] */
    TRIG_IN_1TO1_5_CAN1_FIFO1_TO_PDMA1_0 = 0x00001502u, /* canfd[1].tr_fifo1[0] */
    TRIG_IN_1TO1_5_CAN1_DBG_TO_PDMA1_1 = 0x00001503u, /* canfd[1].tr_dbg_dma_req[1] */
    TRIG_IN_1TO1_5_CAN1_FIFO0_TO_PDMA1_1 = 0x00001504u, /* canfd[1].tr_fifo0[1] */
    TRIG_IN_1TO1_5_CAN1_FIFO1_TO_PDMA1_1 = 0x00001505u, /* canfd[1].tr_fifo1[1] */
    TRIG_IN_1TO1_5_CAN1_DBG_TO_PDMA1_2 = 0x00001506u, /* canfd[1].tr_dbg_dma_req[2] */
    TRIG_IN_1TO1_5_CAN1_FIFO0_TO_PDMA1_2 = 0x00001507u, /* canfd[1].tr_fifo0[2] */
    TRIG_IN_1TO1_5_CAN1_FIFO1_TO_PDMA1_2 = 0x00001508u /* canfd[1].tr_fifo1[2] */
} en_trig_input_1to1_can1_dw_tr_t;

/* Trigger Input Group 6 - Acknowledge dma request triggers from DW0 to CAN (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_6_PDMA0_ACK_TO_CAN0_0 = 0x00001600u, /* cpuss.dw0_tr_out[16] */
    TRIG_IN_1TO1_6_PDMA0_ACK_TO_CAN0_1 = 0x00001601u, /* cpuss.dw0_tr_out[19] */
    TRIG_IN_1TO1_6_PDMA0_ACK_TO_CAN0_2 = 0x00001602u /* cpuss.dw0_tr_out[22] */
} en_trig_input_1to1_can0_dw_ack_t;

/* Trigger Input Group 7 - Acknowledge dma request triggers from DW1 to CAN (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_7_PDMA1_ACK_TO_CAN1_0 = 0x00001700u, /* cpuss.dw1_tr_out[24] */
    TRIG_IN_1TO1_7_PDMA1_ACK_TO_CAN1_1 = 0x00001701u, /* cpuss.dw1_tr_out[27] */
    TRIG_IN_1TO1_7_PDMA1_ACK_TO_CAN1_2 = 0x00001702u /* cpuss.dw1_tr_out[30] */
} en_trig_input_1to1_can1_dw_ack_t;

/* Trigger Input Group 8 - SCB DW Triggers (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_8_SCB_TX_TO_PDMA10 = 0x00001800u, /* scb[0].tr_tx_req */
    TRIG_IN_1TO1_8_SCB_RX_TO_PDMA10 = 0x00001801u, /* scb[0].tr_rx_req */
    TRIG_IN_1TO1_8_SCB_TX_TO_PDMA11 = 0x00001802u, /* scb[1].tr_tx_req */
    TRIG_IN_1TO1_8_SCB_RX_TO_PDMA11 = 0x00001803u, /* scb[1].tr_rx_req */
    TRIG_IN_1TO1_8_SCB_TX_TO_PDMA12 = 0x00001804u, /* scb[2].tr_tx_req */
    TRIG_IN_1TO1_8_SCB_RX_TO_PDMA12 = 0x00001805u, /* scb[2].tr_rx_req */
    TRIG_IN_1TO1_8_SCB_TX_TO_PDMA13 = 0x00001806u, /* scb[3].tr_tx_req */
    TRIG_IN_1TO1_8_SCB_RX_TO_PDMA13 = 0x00001807u, /* scb[3].tr_rx_req */
    TRIG_IN_1TO1_8_SCB_TX_TO_PDMA14 = 0x00001808u, /* scb[4].tr_tx_req */
    TRIG_IN_1TO1_8_SCB_RX_TO_PDMA14 = 0x00001809u, /* scb[4].tr_rx_req */
    TRIG_IN_1TO1_8_SCB_TX_TO_PDMA15 = 0x0000180Au, /* scb[5].tr_tx_req */
    TRIG_IN_1TO1_8_SCB_RX_TO_PDMA15 = 0x0000180Bu, /* scb[5].tr_rx_req */
    TRIG_IN_1TO1_8_SCB_TX_TO_PDMA16 = 0x0000180Cu, /* scb[6].tr_tx_req */
    TRIG_IN_1TO1_8_SCB_RX_TO_PDMA16 = 0x0000180Du, /* scb[6].tr_rx_req */
    TRIG_IN_1TO1_8_SCB_TX_TO_PDMA17 = 0x0000180Eu, /* scb[7].tr_tx_req */
    TRIG_IN_1TO1_8_SCB_RX_TO_PDMA17 = 0x0000180Fu /* scb[7].tr_rx_req */
} en_trig_input_1to1_scb_dw_tr_t;

/* Trigger Group Outputs */
/* Trigger Output Group 0 - P-DMA0 Request Assignments */
typedef enum
{
    TRIG_OUT_MUX_0_PDMA0_TR_IN0     = 0x40000000u, /* cpuss.dw0_tr_in[0] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN1     = 0x40000001u, /* cpuss.dw0_tr_in[1] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN2     = 0x40000002u, /* cpuss.dw0_tr_in[2] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN3     = 0x40000003u, /* cpuss.dw0_tr_in[3] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN4     = 0x40000004u, /* cpuss.dw0_tr_in[4] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN5     = 0x40000005u, /* cpuss.dw0_tr_in[5] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN6     = 0x40000006u, /* cpuss.dw0_tr_in[6] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN7     = 0x40000007u /* cpuss.dw0_tr_in[7] */
} en_trig_output_pdma0_tr_t;

/* Trigger Output Group 1 - P-DMA1 Request Assignments */
typedef enum
{
    TRIG_OUT_MUX_1_PDMA1_TR_IN0     = 0x40000100u, /* cpuss.dw1_tr_in[0] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN1     = 0x40000101u, /* cpuss.dw1_tr_in[1] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN2     = 0x40000102u, /* cpuss.dw1_tr_in[2] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN3     = 0x40000103u, /* cpuss.dw1_tr_in[3] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN4     = 0x40000104u, /* cpuss.dw1_tr_in[4] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN5     = 0x40000105u, /* cpuss.dw1_tr_in[5] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN6     = 0x40000106u, /* cpuss.dw1_tr_in[6] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN7     = 0x40000107u /* cpuss.dw1_tr_in[7] */
} en_trig_output_pdma1_tr_t;

/* Trigger Output Group 2 - DMA Request Assignments */
typedef enum
{
    TRIG_OUT_MUX_2_MDMA_TR_IN0      = 0x40000200u, /* cpuss.dmac_tr_in[0] */
    TRIG_OUT_MUX_2_MDMA_TR_IN1      = 0x40000201u, /* cpuss.dmac_tr_in[1] */
    TRIG_OUT_MUX_2_MDMA_TR_IN2      = 0x40000202u, /* cpuss.dmac_tr_in[2] */
    TRIG_OUT_MUX_2_MDMA_TR_IN3      = 0x40000203u /* cpuss.dmac_tr_in[3] */
} en_trig_output_mdma_t;

/* Trigger Output Group 3 - Dedicated mux for counter to P-DMA0 triggers */
typedef enum
{
    TRIG_OUT_MUX_3_PDMA0_TR_IN8     = 0x40000300u, /* cpuss.dw0_tr_in[8] */
    TRIG_OUT_MUX_3_PDMA0_TR_IN9     = 0x40000301u, /* cpuss.dw0_tr_in[9] */
    TRIG_OUT_MUX_3_PDMA0_TR_IN10    = 0x40000302u, /* cpuss.dw0_tr_in[10] */
    TRIG_OUT_MUX_3_PDMA0_TR_IN11    = 0x40000303u, /* cpuss.dw0_tr_in[11] */
    TRIG_OUT_MUX_3_PDMA0_TR_IN12    = 0x40000304u, /* cpuss.dw0_tr_in[12] */
    TRIG_OUT_MUX_3_PDMA0_TR_IN13    = 0x40000305u, /* cpuss.dw0_tr_in[13] */
    TRIG_OUT_MUX_3_PDMA0_TR_IN14    = 0x40000306u, /* cpuss.dw0_tr_in[14] */
    TRIG_OUT_MUX_3_PDMA0_TR_IN15    = 0x40000307u /* cpuss.dw0_tr_in[15] */
} en_trig_output_tcpwm_to_pdma0_t;

/* Trigger Output Group 4 - Reduces tcpwm output triggers to 16 signals, to allow chaining TCPWMs */
typedef enum
{
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN0 = 0x40000400u, /* tcpwm[0].tr_all_cnt_in[0] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN1 = 0x40000401u, /* tcpwm[0].tr_all_cnt_in[1] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN2 = 0x40000402u, /* tcpwm[0].tr_all_cnt_in[2] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN3 = 0x40000403u, /* tcpwm[0].tr_all_cnt_in[3] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN4 = 0x40000404u, /* tcpwm[0].tr_all_cnt_in[4] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN5 = 0x40000405u, /* tcpwm[0].tr_all_cnt_in[5] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN6 = 0x40000406u, /* tcpwm[0].tr_all_cnt_in[6] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN7 = 0x40000407u, /* tcpwm[0].tr_all_cnt_in[7] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN8 = 0x40000408u, /* tcpwm[0].tr_all_cnt_in[8] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN9 = 0x40000409u, /* tcpwm[0].tr_all_cnt_in[9] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN10 = 0x4000040Au, /* tcpwm[0].tr_all_cnt_in[10] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN11 = 0x4000040Bu, /* tcpwm[0].tr_all_cnt_in[11] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN12 = 0x4000040Cu, /* tcpwm[0].tr_all_cnt_in[12] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN13 = 0x4000040Du, /* tcpwm[0].tr_all_cnt_in[13] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN14 = 0x4000040Eu, /* tcpwm[0].tr_all_cnt_in[14] */
    TRIG_OUT_MUX_4_TCPWM_ALL_CNT_TR_IN15 = 0x4000040Fu /* tcpwm[0].tr_all_cnt_in[15] */
} en_trig_output_tcpwm_out_t;

/* Trigger Output Group 5 - TCPWM trigger inputs */
typedef enum
{
    TRIG_OUT_MUX_5_TCPWM_ALL_CNT_TR_IN16 = 0x40000500u, /* tcpwm[0].tr_all_cnt_in[16] */
    TRIG_OUT_MUX_5_TCPWM_ALL_CNT_TR_IN17 = 0x40000501u, /* tcpwm[0].tr_all_cnt_in[17] */
    TRIG_OUT_MUX_5_TCPWM_ALL_CNT_TR_IN18 = 0x40000502u, /* tcpwm[0].tr_all_cnt_in[18] */
    TRIG_OUT_MUX_5_TCPWM_ALL_CNT_TR_IN19 = 0x40000503u, /* tcpwm[0].tr_all_cnt_in[19] */
    TRIG_OUT_MUX_5_TCPWM_ALL_CNT_TR_IN20 = 0x40000504u, /* tcpwm[0].tr_all_cnt_in[20] */
    TRIG_OUT_MUX_5_TCPWM_ALL_CNT_TR_IN21 = 0x40000505u, /* tcpwm[0].tr_all_cnt_in[21] */
    TRIG_OUT_MUX_5_TCPWM_ALL_CNT_TR_IN22 = 0x40000506u, /* tcpwm[0].tr_all_cnt_in[22] */
    TRIG_OUT_MUX_5_TCPWM_ALL_CNT_TR_IN23 = 0x40000507u, /* tcpwm[0].tr_all_cnt_in[23] */
    TRIG_OUT_MUX_5_TCPWM_ALL_CNT_TR_IN24 = 0x40000508u, /* tcpwm[0].tr_all_cnt_in[24] */
    TRIG_OUT_MUX_5_TCPWM_ALL_CNT_TR_IN25 = 0x40000509u, /* tcpwm[0].tr_all_cnt_in[25] */
    TRIG_OUT_MUX_5_TCPWM_ALL_CNT_TR_IN26 = 0x4000050Au /* tcpwm[0].tr_all_cnt_in[26] */
} en_trig_output_tcpwm_in_t;

/* Trigger Output Group 6 - PASS trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_6_PASS_GEN_TR_IN0  = 0x40000600u, /* pass[0].tr_sar_gen_in[0] */
    TRIG_OUT_MUX_6_PASS_GEN_TR_IN1  = 0x40000601u, /* pass[0].tr_sar_gen_in[1] */
    TRIG_OUT_MUX_6_PASS_GEN_TR_IN2  = 0x40000602u, /* pass[0].tr_sar_gen_in[2] */
    TRIG_OUT_MUX_6_PASS_GEN_TR_IN3  = 0x40000603u, /* pass[0].tr_sar_gen_in[3] */
    TRIG_OUT_MUX_6_PASS_GEN_TR_IN4  = 0x40000604u, /* pass[0].tr_sar_gen_in[4] */
    TRIG_OUT_MUX_6_PASS_GEN_TR_IN5  = 0x40000605u, /* pass[0].tr_sar_gen_in[5] */
    TRIG_OUT_MUX_6_PASS_GEN_TR_IN6  = 0x40000606u, /* pass[0].tr_sar_gen_in[6] */
    TRIG_OUT_MUX_6_PASS_GEN_TR_IN7  = 0x40000607u, /* pass[0].tr_sar_gen_in[7] */
    TRIG_OUT_MUX_6_PASS_GEN_TR_IN8  = 0x40000608u, /* pass[0].tr_sar_gen_in[8] */
    TRIG_OUT_MUX_6_PASS_GEN_TR_IN9  = 0x40000609u, /* pass[0].tr_sar_gen_in[9] */
    TRIG_OUT_MUX_6_PASS_GEN_TR_IN10 = 0x4000060Au, /* pass[0].tr_sar_gen_in[10] */
    TRIG_OUT_MUX_6_PASS_GEN_TR_IN11 = 0x4000060Bu /* pass[0].tr_sar_gen_in[11] */
} en_trig_output_pass_t;

/* Trigger Output Group 7 - CAN TT Synchronization triggers */
typedef enum
{
    TRIG_OUT_MUX_7_CAN0_TT_TR_IN0   = 0x40000700u, /* canfd[0].tr_evt_swt_in[0] */
    TRIG_OUT_MUX_7_CAN0_TT_TR_IN1   = 0x40000701u, /* canfd[0].tr_evt_swt_in[1] */
    TRIG_OUT_MUX_7_CAN0_TT_TR_IN2   = 0x40000702u, /* canfd[0].tr_evt_swt_in[2] */
    TRIG_OUT_MUX_7_CAN1_TT_TR_IN0   = 0x40000703u, /* canfd[1].tr_evt_swt_in[0] */
    TRIG_OUT_MUX_7_CAN1_TT_TR_IN1   = 0x40000704u, /* canfd[1].tr_evt_swt_in[1] */
    TRIG_OUT_MUX_7_CAN1_TT_TR_IN2   = 0x40000705u /* canfd[1].tr_evt_swt_in[2] */
} en_trig_output_cantt_t;

/* Trigger Output Group 8 - 2nd level MUX using input from MUX_9/10 */
typedef enum
{
    TRIG_OUT_MUX_8_HSIOM_IO_OUTPUT0 = 0x40000800u, /* peri.tr_io_output[0] */
    TRIG_OUT_MUX_8_HSIOM_IO_OUTPUT1 = 0x40000801u, /* peri.tr_io_output[1] */
    TRIG_OUT_MUX_8_CTI_TR_IN0       = 0x40000802u, /* cpuss.cti_tr_in[0] */
    TRIG_OUT_MUX_8_CTI_TR_IN1       = 0x40000803u, /* cpuss.cti_tr_in[1] */
    TRIG_OUT_MUX_8_PERI_DEBUG_FREEZE_TR_IN = 0x40000804u, /* peri.tr_dbg_freeze */
    TRIG_OUT_MUX_8_PASS_DEBUG_FREEZE_TR_IN = 0x40000805u, /* pass[0].tr_debug_freeze */
    TRIG_OUT_MUX_8_SRSS_WDT_DEBUG_FREEZE_TR_IN = 0x40000806u, /* srss.tr_debug_freeze_wdt */
    TRIG_OUT_MUX_8_SRSS_MCWDT_DEBUG_FREEZE_TR_IN0 = 0x40000807u, /* srss.tr_debug_freeze_mcwdt[0] */
    TRIG_OUT_MUX_8_SRSS_MCWDT_DEBUG_FREEZE_TR_IN1 = 0x40000808u, /* srss.tr_debug_freeze_mcwdt[1] */
    TRIG_OUT_MUX_8_TCPWM_DEBUG_FREEZE_TR_IN = 0x40000809u /* tcpwm[0].tr_debug_freeze */
} en_trig_output_debugmain_t;

/* Trigger Output Group 9 - Makes half of all possible triggers visible as I/O signals for debug purposes, or to build external circuitry */
typedef enum
{
    TRIG_OUT_MUX_9_TR_GROUP8_INPUT1 = 0x40000900u, /* tr_group[8].input[1] */
    TRIG_OUT_MUX_9_TR_GROUP8_INPUT2 = 0x40000901u, /* tr_group[8].input[2] */
    TRIG_OUT_MUX_9_TR_GROUP8_INPUT3 = 0x40000902u, /* tr_group[8].input[3] */
    TRIG_OUT_MUX_9_TR_GROUP8_INPUT4 = 0x40000903u, /* tr_group[8].input[4] */
    TRIG_OUT_MUX_9_TR_GROUP8_INPUT5 = 0x40000904u /* tr_group[8].input[5] */
} en_trig_output_debugreduction1_t;

/* Trigger Output Group 10 - Makes all possible triggers visible as I/O signals for debug purposes, or to build external circuitry */
typedef enum
{
    TRIG_OUT_MUX_10_TR_GROUP8_INPUT6 = 0x40000A00u, /* tr_group[8].input[6] */
    TRIG_OUT_MUX_10_TR_GROUP8_INPUT7 = 0x40000A01u, /* tr_group[8].input[7] */
    TRIG_OUT_MUX_10_TR_GROUP8_INPUT8 = 0x40000A02u, /* tr_group[8].input[8] */
    TRIG_OUT_MUX_10_TR_GROUP8_INPUT9 = 0x40000A03u, /* tr_group[8].input[9] */
    TRIG_OUT_MUX_10_TR_GROUP8_INPUT10 = 0x40000A04u /* tr_group[8].input[10] */
} en_trig_output_debugreduction2_t;

/* Trigger Output Group 0 - TCPWM to LIN (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_0_TCPWM_TO_LIN_TR3 = 0x40001000u, /* lin[0].tr_cmd_tx_header[0] */
    TRIG_OUT_1TO1_0_TCPWM_TO_LIN_TR4 = 0x40001001u, /* lin[0].tr_cmd_tx_header[1] */
    TRIG_OUT_1TO1_0_TCPWM_TO_LIN_TR5 = 0x40001002u, /* lin[0].tr_cmd_tx_header[2] */
    TRIG_OUT_1TO1_0_TCPWM_TO_LIN_TR6 = 0x40001003u, /* lin[0].tr_cmd_tx_header[3] */
    TRIG_OUT_1TO1_0_TCPWM_TO_LIN_TR7 = 0x40001004u, /* lin[0].tr_cmd_tx_header[4] */
    TRIG_OUT_1TO1_0_TCPWM_TO_LIN_TR8 = 0x40001005u, /* lin[0].tr_cmd_tx_header[5] */
    TRIG_OUT_1TO1_0_TCPWM_TO_LIN_TR9 = 0x40001006u, /* lin[0].tr_cmd_tx_header[6] */
    TRIG_OUT_1TO1_0_TCPWM_TO_LIN_TR10 = 0x40001007u /* lin[0].tr_cmd_tx_header[7] */
} en_trig_output_1to1_tcpwm_to_lin_t;

/* Trigger Output Group 1 - PWM Group 0 to PASS direct connect (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR0 = 0x40001100u, /* pass[0].tr_sar_ch_in[0] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR1 = 0x40001101u, /* pass[0].tr_sar_ch_in[1] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR2 = 0x40001102u, /* pass[0].tr_sar_ch_in[2] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR3 = 0x40001103u, /* pass[0].tr_sar_ch_in[3] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR4 = 0x40001104u, /* pass[0].tr_sar_ch_in[4] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR5 = 0x40001105u, /* pass[0].tr_sar_ch_in[5] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR6 = 0x40001106u, /* pass[0].tr_sar_ch_in[6] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR7 = 0x40001107u, /* pass[0].tr_sar_ch_in[7] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR8 = 0x40001108u, /* pass[0].tr_sar_ch_in[8] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR9 = 0x40001109u, /* pass[0].tr_sar_ch_in[9] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR10 = 0x4000110Au, /* pass[0].tr_sar_ch_in[10] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR11 = 0x4000110Bu, /* pass[0].tr_sar_ch_in[11] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR12 = 0x4000110Cu, /* pass[0].tr_sar_ch_in[12] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR13 = 0x4000110Du, /* pass[0].tr_sar_ch_in[13] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR14 = 0x4000110Eu, /* pass[0].tr_sar_ch_in[14] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR15 = 0x4000110Fu, /* pass[0].tr_sar_ch_in[15] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR16 = 0x40001110u, /* pass[0].tr_sar_ch_in[16] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR17 = 0x40001111u, /* pass[0].tr_sar_ch_in[17] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR18 = 0x40001112u, /* pass[0].tr_sar_ch_in[18] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR19 = 0x40001113u, /* pass[0].tr_sar_ch_in[19] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR20 = 0x40001114u, /* pass[0].tr_sar_ch_in[20] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR21 = 0x40001115u, /* pass[0].tr_sar_ch_in[21] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR22 = 0x40001116u, /* pass[0].tr_sar_ch_in[22] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR23 = 0x40001117u, /* pass[0].tr_sar_ch_in[23] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR32 = 0x40001118u, /* pass[0].tr_sar_ch_in[32] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR33 = 0x40001119u, /* pass[0].tr_sar_ch_in[33] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR34 = 0x4000111Au, /* pass[0].tr_sar_ch_in[34] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR35 = 0x4000111Bu, /* pass[0].tr_sar_ch_in[35] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR36 = 0x4000111Cu, /* pass[0].tr_sar_ch_in[36] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR37 = 0x4000111Du, /* pass[0].tr_sar_ch_in[37] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR38 = 0x4000111Eu, /* pass[0].tr_sar_ch_in[38] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR39 = 0x4000111Fu, /* pass[0].tr_sar_ch_in[39] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR40 = 0x40001120u, /* pass[0].tr_sar_ch_in[40] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR41 = 0x40001121u, /* pass[0].tr_sar_ch_in[41] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR42 = 0x40001122u, /* pass[0].tr_sar_ch_in[42] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR43 = 0x40001123u, /* pass[0].tr_sar_ch_in[43] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR44 = 0x40001124u, /* pass[0].tr_sar_ch_in[44] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR45 = 0x40001125u, /* pass[0].tr_sar_ch_in[45] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR46 = 0x40001126u, /* pass[0].tr_sar_ch_in[46] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR47 = 0x40001127u, /* pass[0].tr_sar_ch_in[47] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR48 = 0x40001128u, /* pass[0].tr_sar_ch_in[48] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR49 = 0x40001129u, /* pass[0].tr_sar_ch_in[49] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR50 = 0x4000112Au, /* pass[0].tr_sar_ch_in[50] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR51 = 0x4000112Bu, /* pass[0].tr_sar_ch_in[51] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR52 = 0x4000112Cu, /* pass[0].tr_sar_ch_in[52] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR53 = 0x4000112Du, /* pass[0].tr_sar_ch_in[53] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR54 = 0x4000112Eu, /* pass[0].tr_sar_ch_in[54] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR55 = 0x4000112Fu, /* pass[0].tr_sar_ch_in[55] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR56 = 0x40001130u, /* pass[0].tr_sar_ch_in[56] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR57 = 0x40001131u, /* pass[0].tr_sar_ch_in[57] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR58 = 0x40001132u, /* pass[0].tr_sar_ch_in[58] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR59 = 0x40001133u, /* pass[0].tr_sar_ch_in[59] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR60 = 0x40001134u, /* pass[0].tr_sar_ch_in[60] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR61 = 0x40001135u, /* pass[0].tr_sar_ch_in[61] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR62 = 0x40001136u, /* pass[0].tr_sar_ch_in[62] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR63 = 0x40001137u, /* pass[0].tr_sar_ch_in[63] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR64 = 0x40001138u, /* pass[0].tr_sar_ch_in[64] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR65 = 0x40001139u, /* pass[0].tr_sar_ch_in[65] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR66 = 0x4000113Au, /* pass[0].tr_sar_ch_in[66] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR67 = 0x4000113Bu, /* pass[0].tr_sar_ch_in[67] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR68 = 0x4000113Cu, /* pass[0].tr_sar_ch_in[68] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR69 = 0x4000113Du, /* pass[0].tr_sar_ch_in[69] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR70 = 0x4000113Eu, /* pass[0].tr_sar_ch_in[70] */
    TRIG_OUT_1TO1_1_TCPWM_TO_PASS_CH_TR71 = 0x4000113Fu /* pass[0].tr_sar_ch_in[71] */
} en_trig_output_1to1_pwm0_to_pass_t;

/* Trigger Output Group 2 - PASS to DW0 direct connect (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA00 = 0x40001200u, /* cpuss.dw0_tr_in[25] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA01 = 0x40001201u, /* cpuss.dw0_tr_in[26] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA02 = 0x40001202u, /* cpuss.dw0_tr_in[27] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA03 = 0x40001203u, /* cpuss.dw0_tr_in[28] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA04 = 0x40001204u, /* cpuss.dw0_tr_in[29] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA05 = 0x40001205u, /* cpuss.dw0_tr_in[30] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA06 = 0x40001206u, /* cpuss.dw0_tr_in[31] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA07 = 0x40001207u, /* cpuss.dw0_tr_in[32] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA08 = 0x40001208u, /* cpuss.dw0_tr_in[33] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA09 = 0x40001209u, /* cpuss.dw0_tr_in[34] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA010 = 0x4000120Au, /* cpuss.dw0_tr_in[35] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA011 = 0x4000120Bu, /* cpuss.dw0_tr_in[36] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA012 = 0x4000120Cu, /* cpuss.dw0_tr_in[37] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA013 = 0x4000120Du, /* cpuss.dw0_tr_in[38] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA014 = 0x4000120Eu, /* cpuss.dw0_tr_in[39] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA015 = 0x4000120Fu, /* cpuss.dw0_tr_in[40] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA016 = 0x40001210u, /* cpuss.dw0_tr_in[41] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA017 = 0x40001211u, /* cpuss.dw0_tr_in[42] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA018 = 0x40001212u, /* cpuss.dw0_tr_in[43] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA019 = 0x40001213u, /* cpuss.dw0_tr_in[44] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA020 = 0x40001214u, /* cpuss.dw0_tr_in[45] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA021 = 0x40001215u, /* cpuss.dw0_tr_in[46] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA022 = 0x40001216u, /* cpuss.dw0_tr_in[47] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA023 = 0x40001217u, /* cpuss.dw0_tr_in[48] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA032 = 0x40001218u, /* cpuss.dw0_tr_in[49] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA033 = 0x40001219u, /* cpuss.dw0_tr_in[50] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA034 = 0x4000121Au, /* cpuss.dw0_tr_in[51] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA035 = 0x4000121Bu, /* cpuss.dw0_tr_in[52] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA036 = 0x4000121Cu, /* cpuss.dw0_tr_in[53] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA037 = 0x4000121Du, /* cpuss.dw0_tr_in[54] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA038 = 0x4000121Eu, /* cpuss.dw0_tr_in[55] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA039 = 0x4000121Fu, /* cpuss.dw0_tr_in[56] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA040 = 0x40001220u, /* cpuss.dw0_tr_in[57] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA041 = 0x40001221u, /* cpuss.dw0_tr_in[58] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA042 = 0x40001222u, /* cpuss.dw0_tr_in[59] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA043 = 0x40001223u, /* cpuss.dw0_tr_in[60] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA044 = 0x40001224u, /* cpuss.dw0_tr_in[61] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA045 = 0x40001225u, /* cpuss.dw0_tr_in[62] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA046 = 0x40001226u, /* cpuss.dw0_tr_in[63] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA047 = 0x40001227u, /* cpuss.dw0_tr_in[64] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA048 = 0x40001228u, /* cpuss.dw0_tr_in[65] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA049 = 0x40001229u, /* cpuss.dw0_tr_in[66] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA050 = 0x4000122Au, /* cpuss.dw0_tr_in[67] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA051 = 0x4000122Bu, /* cpuss.dw0_tr_in[68] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA052 = 0x4000122Cu, /* cpuss.dw0_tr_in[69] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA053 = 0x4000122Du, /* cpuss.dw0_tr_in[70] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA054 = 0x4000122Eu, /* cpuss.dw0_tr_in[71] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA055 = 0x4000122Fu, /* cpuss.dw0_tr_in[72] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA056 = 0x40001230u, /* cpuss.dw0_tr_in[73] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA057 = 0x40001231u, /* cpuss.dw0_tr_in[74] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA058 = 0x40001232u, /* cpuss.dw0_tr_in[75] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA059 = 0x40001233u, /* cpuss.dw0_tr_in[76] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA060 = 0x40001234u, /* cpuss.dw0_tr_in[77] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA061 = 0x40001235u, /* cpuss.dw0_tr_in[78] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA062 = 0x40001236u, /* cpuss.dw0_tr_in[79] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA063 = 0x40001237u, /* cpuss.dw0_tr_in[80] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA064 = 0x40001238u, /* cpuss.dw0_tr_in[81] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA065 = 0x40001239u, /* cpuss.dw0_tr_in[82] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA066 = 0x4000123Au, /* cpuss.dw0_tr_in[83] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA067 = 0x4000123Bu, /* cpuss.dw0_tr_in[84] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA068 = 0x4000123Cu, /* cpuss.dw0_tr_in[85] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA069 = 0x4000123Du, /* cpuss.dw0_tr_in[86] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA070 = 0x4000123Eu, /* cpuss.dw0_tr_in[87] */
    TRIG_OUT_1TO1_2_PASS_CH_DONE_TO_PDMA071 = 0x4000123Fu /* cpuss.dw0_tr_in[88] */
} en_trig_output_1to1_pass_to_dw0_t;

/* Trigger Output Group 3 - PASS to PWM direct connect (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL0 = 0x40001300u, /* tcpwm[0].tr_one_cnt_in[770] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL1 = 0x40001301u, /* tcpwm[0].tr_one_cnt_in[779] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL2 = 0x40001302u, /* tcpwm[0].tr_one_cnt_in[788] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL3 = 0x40001303u, /* tcpwm[0].tr_one_cnt_in[797] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL4 = 0x40001304u, /* tcpwm[0].tr_one_cnt_in[2] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL5 = 0x40001305u, /* tcpwm[0].tr_one_cnt_in[5] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL6 = 0x40001306u, /* tcpwm[0].tr_one_cnt_in[8] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL7 = 0x40001307u, /* tcpwm[0].tr_one_cnt_in[11] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL8 = 0x40001308u, /* tcpwm[0].tr_one_cnt_in[14] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL9 = 0x40001309u, /* tcpwm[0].tr_one_cnt_in[17] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL10 = 0x4000130Au, /* tcpwm[0].tr_one_cnt_in[20] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL11 = 0x4000130Bu, /* tcpwm[0].tr_one_cnt_in[23] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL12 = 0x4000130Cu, /* tcpwm[0].tr_one_cnt_in[26] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL13 = 0x4000130Du, /* tcpwm[0].tr_one_cnt_in[29] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL14 = 0x4000130Eu, /* tcpwm[0].tr_one_cnt_in[32] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL15 = 0x4000130Fu, /* tcpwm[0].tr_one_cnt_in[35] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL16 = 0x40001310u, /* tcpwm[0].tr_one_cnt_in[38] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL17 = 0x40001311u, /* tcpwm[0].tr_one_cnt_in[41] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL18 = 0x40001312u, /* tcpwm[0].tr_one_cnt_in[44] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL19 = 0x40001313u, /* tcpwm[0].tr_one_cnt_in[47] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL20 = 0x40001314u, /* tcpwm[0].tr_one_cnt_in[50] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL21 = 0x40001315u, /* tcpwm[0].tr_one_cnt_in[53] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL22 = 0x40001316u, /* tcpwm[0].tr_one_cnt_in[56] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL23 = 0x40001317u, /* tcpwm[0].tr_one_cnt_in[59] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL24 = 0x40001318u, /* tcpwm[0].tr_one_cnt_in[773] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL25 = 0x40001319u, /* tcpwm[0].tr_one_cnt_in[782] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL26 = 0x4000131Au, /* tcpwm[0].tr_one_cnt_in[791] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL27 = 0x4000131Bu, /* tcpwm[0].tr_one_cnt_in[800] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL28 = 0x4000131Cu, /* tcpwm[0].tr_one_cnt_in[62] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL29 = 0x4000131Du, /* tcpwm[0].tr_one_cnt_in[65] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL30 = 0x4000131Eu, /* tcpwm[0].tr_one_cnt_in[68] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL31 = 0x4000131Fu, /* tcpwm[0].tr_one_cnt_in[71] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL32 = 0x40001320u, /* tcpwm[0].tr_one_cnt_in[74] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL33 = 0x40001321u, /* tcpwm[0].tr_one_cnt_in[77] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL34 = 0x40001322u, /* tcpwm[0].tr_one_cnt_in[80] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL35 = 0x40001323u, /* tcpwm[0].tr_one_cnt_in[83] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL36 = 0x40001324u, /* tcpwm[0].tr_one_cnt_in[86] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL37 = 0x40001325u, /* tcpwm[0].tr_one_cnt_in[89] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL38 = 0x40001326u, /* tcpwm[0].tr_one_cnt_in[92] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL39 = 0x40001327u, /* tcpwm[0].tr_one_cnt_in[95] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL40 = 0x40001328u, /* tcpwm[0].tr_one_cnt_in[98] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL41 = 0x40001329u, /* tcpwm[0].tr_one_cnt_in[101] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL42 = 0x4000132Au, /* tcpwm[0].tr_one_cnt_in[104] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL43 = 0x4000132Bu, /* tcpwm[0].tr_one_cnt_in[107] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL44 = 0x4000132Cu, /* tcpwm[0].tr_one_cnt_in[110] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL45 = 0x4000132Du, /* tcpwm[0].tr_one_cnt_in[113] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL46 = 0x4000132Eu, /* tcpwm[0].tr_one_cnt_in[116] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL47 = 0x4000132Fu, /* tcpwm[0].tr_one_cnt_in[119] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL48 = 0x40001330u, /* tcpwm[0].tr_one_cnt_in[122] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL49 = 0x40001331u, /* tcpwm[0].tr_one_cnt_in[125] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL50 = 0x40001332u, /* tcpwm[0].tr_one_cnt_in[128] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL51 = 0x40001333u, /* tcpwm[0].tr_one_cnt_in[131] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL52 = 0x40001334u, /* tcpwm[0].tr_one_cnt_in[134] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL53 = 0x40001335u, /* tcpwm[0].tr_one_cnt_in[137] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL54 = 0x40001336u, /* tcpwm[0].tr_one_cnt_in[140] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL55 = 0x40001337u, /* tcpwm[0].tr_one_cnt_in[143] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL56 = 0x40001338u, /* tcpwm[0].tr_one_cnt_in[776] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL57 = 0x40001339u, /* tcpwm[0].tr_one_cnt_in[785] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL58 = 0x4000133Au, /* tcpwm[0].tr_one_cnt_in[794] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL59 = 0x4000133Bu, /* tcpwm[0].tr_one_cnt_in[803] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL60 = 0x4000133Cu, /* tcpwm[0].tr_one_cnt_in[146] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL61 = 0x4000133Du, /* tcpwm[0].tr_one_cnt_in[149] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL62 = 0x4000133Eu, /* tcpwm[0].tr_one_cnt_in[152] */
    TRIG_OUT_1TO1_3_PASS_CH_RANGEVIO_TO_PWM_KILL63 = 0x4000133Fu /* tcpwm[0].tr_one_cnt_in[155] */
} en_trig_output_1to1_pass_to_pwm_t;

/* Trigger Output Group 4 - CAN DW0 Triggers (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_4_CAN0_DBG_TO_PDMA0_0 = 0x40001400u, /* cpuss.dw0_tr_in[16] */
    TRIG_OUT_1TO1_4_CAN0_FIFO0_TO_PDMA0_0 = 0x40001401u, /* cpuss.dw0_tr_in[17] */
    TRIG_OUT_1TO1_4_CAN0_FIFO1_TO_PDMA0_0 = 0x40001402u, /* cpuss.dw0_tr_in[18] */
    TRIG_OUT_1TO1_4_CAN0_DBG_TO_PDMA0_1 = 0x40001403u, /* cpuss.dw0_tr_in[19] */
    TRIG_OUT_1TO1_4_CAN0_FIFO0_TO_PDMA0_1 = 0x40001404u, /* cpuss.dw0_tr_in[20] */
    TRIG_OUT_1TO1_4_CAN0_FIFO1_TO_PDMA0_1 = 0x40001405u, /* cpuss.dw0_tr_in[21] */
    TRIG_OUT_1TO1_4_CAN0_DBG_TO_PDMA0_2 = 0x40001406u, /* cpuss.dw0_tr_in[22] */
    TRIG_OUT_1TO1_4_CAN0_FIFO0_TO_PDMA0_2 = 0x40001407u, /* cpuss.dw0_tr_in[23] */
    TRIG_OUT_1TO1_4_CAN0_FIFO1_TO_PDMA0_2 = 0x40001408u /* cpuss.dw0_tr_in[24] */
} en_trig_output_1to1_can0_dw_tr_t;

/* Trigger Output Group 5 - CAN DW1 triggers (on DW1 to share BW) (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_5_CAN1_DBG_TO_PDMA1_0 = 0x40001500u, /* cpuss.dw1_tr_in[24] */
    TRIG_OUT_1TO1_5_CAN1_FIFO0_TO_PDMA1_0 = 0x40001501u, /* cpuss.dw1_tr_in[25] */
    TRIG_OUT_1TO1_5_CAN1_FIFO1_TO_PDMA1_0 = 0x40001502u, /* cpuss.dw1_tr_in[26] */
    TRIG_OUT_1TO1_5_CAN1_DBG_TO_PDMA1_1 = 0x40001503u, /* cpuss.dw1_tr_in[27] */
    TRIG_OUT_1TO1_5_CAN1_FIFO0_TO_PDMA1_1 = 0x40001504u, /* cpuss.dw1_tr_in[28] */
    TRIG_OUT_1TO1_5_CAN1_FIFO1_TO_PDMA1_1 = 0x40001505u, /* cpuss.dw1_tr_in[29] */
    TRIG_OUT_1TO1_5_CAN1_DBG_TO_PDMA1_2 = 0x40001506u, /* cpuss.dw1_tr_in[30] */
    TRIG_OUT_1TO1_5_CAN1_FIFO0_TO_PDMA1_2 = 0x40001507u, /* cpuss.dw1_tr_in[31] */
    TRIG_OUT_1TO1_5_CAN1_FIFO1_TO_PDMA1_2 = 0x40001508u /* cpuss.dw1_tr_in[32] */
} en_trig_output_1to1_can1_dw_tr_t;

/* Trigger Output Group 6 - Acknowledge dma request triggers from DW0 to CAN (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_6_PDMA0_ACK_TO_CAN0_0 = 0x40001600u, /* canfd[0].tr_dbg_dma_ack[0] */
    TRIG_OUT_1TO1_6_PDMA0_ACK_TO_CAN0_1 = 0x40001601u, /* canfd[0].tr_dbg_dma_ack[1] */
    TRIG_OUT_1TO1_6_PDMA0_ACK_TO_CAN0_2 = 0x40001602u /* canfd[0].tr_dbg_dma_ack[2] */
} en_trig_output_1to1_can0_dw_ack_t;

/* Trigger Output Group 7 - Acknowledge dma request triggers from DW1 to CAN (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_7_PDMA1_ACK_TO_CAN1_0 = 0x40001700u, /* canfd[1].tr_dbg_dma_ack[0] */
    TRIG_OUT_1TO1_7_PDMA1_ACK_TO_CAN1_1 = 0x40001701u, /* canfd[1].tr_dbg_dma_ack[1] */
    TRIG_OUT_1TO1_7_PDMA1_ACK_TO_CAN1_2 = 0x40001702u /* canfd[1].tr_dbg_dma_ack[2] */
} en_trig_output_1to1_can1_dw_ack_t;

/* Trigger Output Group 8 - SCB DW Triggers (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_8_SCB_TX_TO_PDMA10 = 0x40001800u, /* cpuss.dw1_tr_in[8] */
    TRIG_OUT_1TO1_8_SCB_RX_TO_PDMA10 = 0x40001801u, /* cpuss.dw1_tr_in[9] */
    TRIG_OUT_1TO1_8_SCB_TX_TO_PDMA11 = 0x40001802u, /* cpuss.dw1_tr_in[10] */
    TRIG_OUT_1TO1_8_SCB_RX_TO_PDMA11 = 0x40001803u, /* cpuss.dw1_tr_in[11] */
    TRIG_OUT_1TO1_8_SCB_TX_TO_PDMA12 = 0x40001804u, /* cpuss.dw1_tr_in[12] */
    TRIG_OUT_1TO1_8_SCB_RX_TO_PDMA12 = 0x40001805u, /* cpuss.dw1_tr_in[13] */
    TRIG_OUT_1TO1_8_SCB_TX_TO_PDMA13 = 0x40001806u, /* cpuss.dw1_tr_in[14] */
    TRIG_OUT_1TO1_8_SCB_RX_TO_PDMA13 = 0x40001807u, /* cpuss.dw1_tr_in[15] */
    TRIG_OUT_1TO1_8_SCB_TX_TO_PDMA14 = 0x40001808u, /* cpuss.dw1_tr_in[16] */
    TRIG_OUT_1TO1_8_SCB_RX_TO_PDMA14 = 0x40001809u, /* cpuss.dw1_tr_in[17] */
    TRIG_OUT_1TO1_8_SCB_TX_TO_PDMA15 = 0x4000180Au, /* cpuss.dw1_tr_in[18] */
    TRIG_OUT_1TO1_8_SCB_RX_TO_PDMA15 = 0x4000180Bu, /* cpuss.dw1_tr_in[19] */
    TRIG_OUT_1TO1_8_SCB_TX_TO_PDMA16 = 0x4000180Cu, /* cpuss.dw1_tr_in[20] */
    TRIG_OUT_1TO1_8_SCB_RX_TO_PDMA16 = 0x4000180Du, /* cpuss.dw1_tr_in[21] */
    TRIG_OUT_1TO1_8_SCB_TX_TO_PDMA17 = 0x4000180Eu, /* cpuss.dw1_tr_in[22] */
    TRIG_OUT_1TO1_8_SCB_RX_TO_PDMA17 = 0x4000180Fu /* cpuss.dw1_tr_in[23] */
} en_trig_output_1to1_scb_dw_tr_t;

/* Level or edge detection setting for a trigger mux */
typedef enum
{
    /* The trigger is a simple level output */
    TRIGGER_TYPE_LEVEL = 0u,
    /* The trigger is synchronized to the consumer blocks clock
       and a two cycle pulse is generated on this clock */
    TRIGGER_TYPE_EDGE = 1u
} en_trig_type_t;

/* Trigger Type Defines */
/* TCPWM Trigger Types */
#define TRIGGER_TYPE_TCPWM_TR_DEBUG_FREEZE      TRIGGER_TYPE_LEVEL
/* SCB Trigger Types */
#define TRIGGER_TYPE_SCB_TR_TX_REQ              TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_RX_REQ              TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_I2C_SCL_FILTERED    TRIGGER_TYPE_LEVEL
/* LIN Trigger Types */
#define TRIGGER_TYPE_LIN_TR_CMD_TX_HEADER       TRIGGER_TYPE_EDGE
/* CANFD Trigger Types */
#define TRIGGER_TYPE_CANFD_TR_TMP_RTP_OUT       TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CANFD_TR_DBG_DMA_REQ       TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CANFD_TR_FIFO0             TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CANFD_TR_FIFO1             TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CANFD_TR_EVT_SWT_IN        TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CANFD_TR_DBG_DMA_ACK       TRIGGER_TYPE_EDGE
/* PERI Trigger Types */
#define TRIGGER_TYPE_PERI_TR_IO_INPUT__LEVEL    TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PERI_TR_IO_INPUT__EDGE     TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PERI_TR_IO_OUTPUT__LEVEL   TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PERI_TR_IO_OUTPUT__EDGE    TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PERI_TR_DBG_FREEZE         TRIGGER_TYPE_LEVEL
/* CPUSS Trigger Types */
#define TRIGGER_TYPE_CPUSS_DW0_TR_IN__LEVEL     TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CPUSS_DW0_TR_IN__EDGE      TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW1_TR_IN__LEVEL     TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CPUSS_DW1_TR_IN__EDGE      TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DMAC_TR_IN__LEVEL    TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CPUSS_DMAC_TR_IN__EDGE     TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW0_TR_OUT           TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW1_TR_OUT           TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DMAC_TR_OUT          TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_TR_FAULT             TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_CTI_TR_OUT           TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_CTI_TR_IN            TRIGGER_TYPE_EDGE
/* PASS Trigger Types */
#define TRIGGER_TYPE_PASS_TR_SAR_GEN_OUT__LEVEL TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_SAR_GEN_OUT__EDGE  TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PASS_TR_SAR_GEN_IN__LEVEL  TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_SAR_GEN_IN__EDGE   TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PASS_TR_DEBUG_FREEZE       TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_SAR_CH_IN__LEVEL   TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_SAR_CH_IN__EDGE    TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PASS_TR_SAR_CH_DONE__LEVEL TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_SAR_CH_DONE__EDGE  TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PASS_TR_SAR_CH_RANGEVIO    TRIGGER_TYPE_EDGE
/* SRSS Trigger Types */
#define TRIGGER_TYPE_SRSS_TR_DEBUG_FREEZE_WDT   TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SRSS_TR_DEBUG_FREEZE_MCWDT TRIGGER_TYPE_LEVEL
/* TR_GROUP Trigger Types */
#define TRIGGER_TYPE_TR_GROUP_OUTPUT__LEVEL     TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_TR_GROUP_OUTPUT__EDGE      TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_TR_GROUP_INPUT__LEVEL      TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_TR_GROUP_INPUT__EDGE       TRIGGER_TYPE_EDGE

/* Fault connections */
typedef enum
{
    CPUSS_MPU_VIO_0                 = 0x0000u,
    CPUSS_MPU_VIO_1                 = 0x0001u,
    CPUSS_MPU_VIO_2                 = 0x0002u,
    CPUSS_MPU_VIO_3                 = 0x0003u,
    CPUSS_MPU_VIO_4                 = 0x0004u,
    CPUSS_MPU_VIO_15                = 0x000Fu,
    CPUSS_MPU_VIO_16                = 0x0010u,
    CPUSS_MPU_VIO_17                = 0x0011u,
    CPUSS_MPU_VIO_18                = 0x0012u,
    PERI_PERI_C_ECC                 = 0x001Au,
    PERI_PERI_NC_ECC                = 0x001Bu,
    PERI_MS_VIO_0                   = 0x001Cu,
    PERI_MS_VIO_1                   = 0x001Du,
    PERI_MS_VIO_2                   = 0x001Eu,
    PERI_MS_VIO_3                   = 0x001Fu,
    PERI_GROUP_VIO_0                = 0x0020u,
    PERI_GROUP_VIO_1                = 0x0021u,
    PERI_GROUP_VIO_2                = 0x0022u,
    PERI_GROUP_VIO_3                = 0x0023u,
    PERI_GROUP_VIO_5                = 0x0025u,
    PERI_GROUP_VIO_6                = 0x0026u,
    PERI_GROUP_VIO_9                = 0x0029u,
    CPUSS_FLASHC_MAIN_BUS_ERR       = 0x0030u,
    CPUSS_FLASHC_MAIN_C_ECC         = 0x0031u,
    CPUSS_FLASHC_MAIN_NC_ECC        = 0x0032u,
    CPUSS_FLASHC_WORK_BUS_ERR       = 0x0033u,
    CPUSS_FLASHC_WORK_C_ECC         = 0x0034u,
    CPUSS_FLASHC_WORK_NC_ECC        = 0x0035u,
    CPUSS_FLASHC_CM0_CA_C_ECC       = 0x0036u,
    CPUSS_FLASHC_CM0_CA_NC_ECC      = 0x0037u,
    CPUSS_FLASHC_CM4_CA_C_ECC       = 0x0038u,
    CPUSS_FLASHC_CM4_CA_NC_ECC      = 0x0039u,
    CPUSS_RAMC0_C_ECC               = 0x003Au,
    CPUSS_RAMC0_NC_ECC              = 0x003Bu,
    CPUSS_RAMC1_C_ECC               = 0x003Cu,
    CPUSS_RAMC1_NC_ECC              = 0x003Du,
    CPUSS_CRYPTO_C_ECC              = 0x0040u,
    CPUSS_CRYPTO_NC_ECC             = 0x0041u,
    CPUSS_DW0_C_ECC                 = 0x0046u,
    CPUSS_DW0_NC_ECC                = 0x0047u,
    CPUSS_DW1_C_ECC                 = 0x0048u,
    CPUSS_DW1_NC_ECC                = 0x0049u,
    CPUSS_FM_SRAM_C_ECC             = 0x004Au,
    CPUSS_FM_SRAM_NC_ECC            = 0x004Bu,
    CANFD_0_CAN_C_ECC               = 0x0050u,
    CANFD_0_CAN_NC_ECC              = 0x0051u,
    CANFD_1_CAN_C_ECC               = 0x0052u,
    CANFD_1_CAN_NC_ECC              = 0x0053u,
    SRSS_FAULT_CSV                  = 0x005Au,
    SRSS_FAULT_SSV                  = 0x005Bu,
    SRSS_FAULT_MCWDT0               = 0x005Cu,
    SRSS_FAULT_MCWDT1               = 0x005Du
} en_sysflt_source_t;

/* Bus masters */
typedef enum
{
    CPUSS_MS_ID_CM0                 =  0,
    CPUSS_MS_ID_CRYPTO              =  1,
    CPUSS_MS_ID_DW0                 =  2,
    CPUSS_MS_ID_DW1                 =  3,
    CPUSS_MS_ID_DMAC                =  4,
    CPUSS_MS_ID_SLOW0               =  5,
    CPUSS_MS_ID_SLOW1               =  6,
    CPUSS_MS_ID_CM4                 = 14,
    CPUSS_MS_ID_TC                  = 15
} en_prot_master_t;

/* Parameter Defines */
/* ULP variant. Must be 1 when targeting S40S and 0 otherwise. */
#define SRSS_ULP_VARIANT                0u
/* HT variant. Must be 1 when targeting S40E and 0 otherwise. */
#define SRSS_HT_VARIANT                 1u
/* Number of regulator modules instantiated within SRSS, start with estimate,
   update after CMR feedback */
#define SRSS_NUM_ACTREG_PWRMOD          3u
/* Number of shorting switches between vccd and vccact (target dynamic voltage
   drop < 10mV) */
#define SRSS_NUM_ACTIVE_SWITCH          4u
/* ULP linear regulator system is present */
#define SRSS_ULPLINREG_PRESENT          0u
/* HT linear regulator system is present */
#define SRSS_HTLINREG_PRESENT           1u
/* SIMO buck core regulator is present. Only compatible with ULP linear regulator
   system (ULPLINREG_PRESENT==1). */
#define SRSS_SIMOBUCK_PRESENT           0u
/* Precision ILO (PILO) is present */
#define SRSS_PILO_PRESENT               0u
/* External Crystal Oscillator is present (high frequency) */
#define SRSS_ECO_PRESENT                1u
/* System Buck-Boost is present */
#define SRSS_SYSBB_PRESENT              0u
/* Number of PWR_HIB_DATA registers */
#define SRSS_NUM_HIBDATA                1u
/* Number of clock paths. Must be > 0 */
#define SRSS_NUM_CLKPATH                4u
/* Number of PLLs present. Must be <= NUM_CLKPATH */
#define SRSS_NUM_PLL                    1u
/* Number of HFCLK roots present. Must be > 0 */
#define SRSS_NUM_HFROOT                 3u
/* Number of DSI inputs into clock muxes. This is used for logic optimization. */
#define SRSS_NUM_DSI                    0u
/* Alternate high-frequency clock is present. This is used for logic optimization. */
#define SRSS_ALTHF_PRESENT              0u
/* Alternate low-frequency clock is present. This is used for logic optimization. */
#define SRSS_ALTLF_PRESENT              0u
/* Backup domain is present */
#define SRSS_BACKUP_PRESENT             1u
/* CSV present */
#define SRSS_CSV_PRESENT                1u
/* Number of software watchdog timers. */
#define SRSS_NUM_MCWDT                  2u
/* Use the hardened clkactfllmux block */
#define SRSS_USE_HARD_CLKACTFLLMUX      1u
/* Number of clock paths, including direct paths in hardened clkactfllmux block */
#define SRSS_HARD_CLKPATH               8u
/* Number of clock paths with muxes in hardened clkactfllmux block */
#define SRSS_HARD_CLKPATHMUX            8u
/* Number of HFCLKS present in hardened clkactfllmux block */
#define SRSS_HARD_HFROOT                8u
/* ECO mux is present in hardened clkactfllmux block */
#define SRSS_HARD_ECOMUX_PRESENT        1u
/* ALTHF mux is present in hardened clkactfllmux block */
#define SRSS_HARD_ALTHFMUX_PRESENT      1u
/* POR present. */
#define SRSS_POR_PRESENT                1u
/* Mask of HFCLK root clock supervisors (CSV). For each clock root i, bit[i] of
   mask indicates presence of a CSV. */
#define SRSS_CSV_HF_MASK_HFCSV          7u
/* Separate power supply Vbackup is present (only used when BACKUP_PRESENT==1) */
#define SRSS_BACKUP_VBCK_PRESENT        0u
/* Alarm1 present in RTC */
#define SRSS_BACKUP_ALM1_PRESENT        1u
/* Alarm2 present in RTC */
#define SRSS_BACKUP_ALM2_PRESENT        1u
/* Backup memory is present (only used when BACKUP_PRESENT==1) */
#define SRSS_BACKUP_BMEM_PRESENT        0u
/* Number of Backup registers to include (each is 32b). Only used when
   BACKUP_PRESENT==1. */
#define SRSS_BACKUP_NUM_BREG            4u
/* Number of AMUX splitter cells */
#define IOSS_HSIOM_AMUX_SPLIT_NR        3u
/* Number of HSIOM ports in device (same as GPIO.GPIO_PRT_NR) */
#define IOSS_HSIOM_HSIOM_PORT_NR        24u
/* Number of PWR/GND MONITOR CELLs in the device */
#define IOSS_HSIOM_MONITOR_NR           21u
/* Number of PWR/GND MONITOR CELLs in range 0..31 */
#define IOSS_HSIOM_MONITOR_NR_0_31      21u
/* Number of PWR/GND MONITOR CELLs in range 32..63 */
#define IOSS_HSIOM_MONITOR_NR_32_63     0u
/* Number of PWR/GND MONITOR CELLs in range 64..95 */
#define IOSS_HSIOM_MONITOR_NR_64_95     0u
/* Number of PWR/GND MONITOR CELLs in range 96..127 */
#define IOSS_HSIOM_MONITOR_NR_96_127    0u
/* Indicates the presence of alternate JTAG interface */
#define IOSS_HSIOM_ALTJTAG_PRESENT      1u
/* Number of GPIO ports in range 0..31 */
#define IOSS_GPIO_GPIO_PORT_NR_0_31     24u
/* Number of GPIO ports in range 32..63 */
#define IOSS_GPIO_GPIO_PORT_NR_32_63    0u
/* Number of GPIO ports in range 64..95 */
#define IOSS_GPIO_GPIO_PORT_NR_64_95    0u
/* Number of GPIO ports in range 96..127 */
#define IOSS_GPIO_GPIO_PORT_NR_96_127   0u
/* Number of ports in device */
#define IOSS_GPIO_GPIO_PORT_NR          24u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature (SIO, OVT,
   and ENH cell types) */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO7 0u
/* Mask of SMARTIO instances presence */
#define IOSS_SMARTIO_SMARTIO_MASK       192512u
/* The number of protection contexts ([2, 16]). */
#define PERI_PC_NR                      8u
/* Master interface presence mask (4 bits) */
#define PERI_MS_PRESENT                 15u
/* Protection structures SRAM ECC present or not ('0': no, '1': yes) */
#define PERI_ECC_PRESENT                1u
/* Protection structures SRAM address ECC present or not ('0': no, '1': yes) */
#define PERI_ECC_ADDR_PRESENT           1u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL3_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL4_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL5_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL6_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL7_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL8_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL9_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL10_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL11_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL3_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL4_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL3_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL4_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL5_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL6_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL7_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Number of programmable clocks (outputs) */
#define PERI_CLOCK_NR                   110u
/* Number of 8.0 dividers */
#define PERI_DIV_8_NR                   32u
/* Number of 16.0 dividers */
#define PERI_DIV_16_NR                  16u
/* Number of 16.5 (fractional) dividers */
#define PERI_DIV_16_5_NR                0u
/* Number of 24.5 (fractional) dividers */
#define PERI_DIV_24_5_NR                8u
/* Divider number width: max(1,roundup(log2(max(DIV_*_NR))) */
#define PERI_DIV_ADDR_WIDTH             5u
/* Timeout functionality present ('0': no, '1': yes) */
#define PERI_TIMEOUT_PRESENT            1u
/* Trigger module present (0=No, 1=Yes) */
#define PERI_TR                         1u
/* Number of trigger groups */
#define PERI_TR_GROUP_NR                11u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR0_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR1_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR2_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR3_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR4_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR5_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR6_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR7_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR8_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR9_TR_GROUP_TR_MANIPULATION_PRESENT 0u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR10_TR_GROUP_TR_MANIPULATION_PRESENT 0u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR0_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR1_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR2_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR3_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR4_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR5_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR6_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR7_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR8_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define PERI_MASTER_WIDTH               8u
/* UDB present or not ('0': no, '1': yes) */
#define CPUSS_UDB_PRESENT               0u
/* MBIST MMIO for Synopsys MBIST ('0': no, '1': yes). Set this to '1' only for the
   chips which doesn't use mxdft. */
#define CPUSS_MBIST_MMIO_PRESENT        0u
/* System RAM 0 size in KB */
#define CPUSS_SRAM0_SIZE                64u
/* Number of macros used to implement system RAM 0. Example: 8 if 256 KB system
   SRAM 0 is implemented with 8 32KB macros. */
#define CPUSS_RAMC0_MACRO_NR            2u
/* System RAM 1 present or not ('0': no, '1': yes) */
#define CPUSS_RAMC1_PRESENT             1u
/* System RAM 1 size in KB */
#define CPUSS_SRAM1_SIZE                64u
/* Number of macros used to implement system RAM 1. */
#define CPUSS_RAMC1_MACRO_NR            2u
/* System RAM 2 present or not ('0': no, '1': yes) */
#define CPUSS_RAMC2_PRESENT             0u
/* System RAM 2 size in KB */
#define CPUSS_SRAM2_SIZE                1u
/* Number of macros used to implement System RAM 2. */
#define CPUSS_RAMC2_MACRO_NR            0u
/* System SRAM(s) ECC present or not ('0': no, '1': yes) */
#define CPUSS_RAMC_ECC_PRESENT          1u
/* System SRAM(s) address ECC present or not ('0': no, '1': yes) */
#define CPUSS_RAMC_ECC_ADDR_PRESENT     1u
/* ECC present in either system RAM or interrupt handler (RAMC_ECC_PRESENT) */
#define CPUSS_ECC_PRESENT               1u
/* DataWire SRAMs ECC present or not ('0': no, '1': yes) */
#define CPUSS_DW_ECC_PRESENT            1u
/* DataWire SRAMs address ECC present or not ('0': no, '1': yes) */
#define CPUSS_DW_ECC_ADDR_PRESENT       1u
/* System ROM size in KB */
#define CPUSS_ROM_SIZE                  32u
/* Number of macros used to implement system ROM. Example: 4 if 512 KB system ROM
   is implemented with 4 128KB macros. */
#define CPUSS_ROMC_MACRO_NR             1u
/* Flash memory type ('0' : SONOS, '1': ECT) */
#define CPUSS_FLASHC_ECT                1u
/* Flash main region size in KB */
#define CPUSS_FLASH_SIZE                1024u
/* Flash work region size in KB (EEPROM emulation, data) */
#define CPUSS_WFLASH_SIZE               96u
/* Flash supervisory region size in KB */
#define CPUSS_SFLASH_SIZE               32u
/* Flash data output word size (in Bytes) */
#define CPUSS_FLASHC_MAIN_DATA_WIDTH    32u
/* SONOS Flash RWW present or not ('0': no, '1': yes) When RWW is '0', No special
   sectors present in Flash. Part of main sector 0 is allowcated for Supervisory
   Flash, and no Work Flash present. */
#define CPUSS_FLASHC_SONOS_RWW          0u
/* SONOS Flash, number of main sectors. */
#define CPUSS_FLASHC_SONOS_MAIN_SECTORS 0u
/* SONOS Flash, number of rows per main sector. */
#define CPUSS_FLASHC_SONOS_MAIN_ROWS    0u
/* SONOS Flash, number of words per row of main sector. */
#define CPUSS_FLASHC_SONOS_MAIN_WORDS   0u
/* SONOS Flash, number of special sectors. */
#define CPUSS_FLASHC_SONOS_SPL_SECTORS  0u
/* SONOS Flash, number of rows per special sector. */
#define CPUSS_FLASHC_SONOS_SPL_ROWS     0u
/* Flash memory ECC present or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_FLASH_ECC_PRESENT  1u
/* Flash cache SRAM(s) ECC present or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_RAM_ECC_PRESENT    1u
/* Number of external slaves directly connected to slow AHB-Lite infrastructure.
   Maximum nubmer of slave supported is 4. Width of this parameter is 4-bits.
   1-bit mask for each slave indicating present or not. Example: 4'b0011 - slave
   0 and slave 1 are present. Note: The SLOW_SLx_ADDR and SLOW_SLx_MASK
   parameters (for the slaves present) should be derived from the Memory Map. */
#define CPUSS_SLOW_SL_PRESENT           0u
/* Number of external slaves directly connected to fast AHB-Lite infrastructure.
   Maximum nubmer of slave supported is 4. Width of this parameter is 4-bits.
   1-bit mask for each slave indicating present or not. Example: 4'b0011 - slave
   0 and slave 1 are present. Note: The FAST_SLx_ADDR and FAST_SLx_MASK
   parameters (for the slaves present) should be derived from the Memory Map. */
#define CPUSS_FAST_SL_PRESENT           0u
/* Number of external masters driving the slow AHB-Lite infrastructure. Maximum
   number of masters supported is 2. Width of this parameter is 2-bits. 1-bit
   mask for each master indicating present or not. Example: 2'b01 - master 0 is
   present. */
#define CPUSS_SLOW_MS_PRESENT           0u
/* System interrupt functionality present or not ('0': no; '1': yes). Not used for
   CM0+ PCU, which always uses system interrupt functionality. */
#define CPUSS_SYSTEM_IRQ_PRESENT        1u
/* Number of system interrupt inputs to CPUSS */
#define CPUSS_SYSTEM_INT_NR             353u
/* Number of DeepSleep system interrupt inputs to CPUSS */
#define CPUSS_SYSTEM_DPSLP_INT_NR       45u
/* Width of the CM4 interrupt priority bits. Legal range [3,8] Example: 3 = 8
   levels of priority 8 = 256 levels of priority */
#define CPUSS_CM4_LVL_WIDTH             3u
/* CM4 Floating point unit present or not ('0': no, '1': yes) */
#define CPUSS_CM4_FPU_PRESENT           1u
/* Debug level. Legal range [0,3] */
#define CPUSS_DEBUG_LVL                 3u
/* Trace level. Legal range [0,2] Note: CM4 HTM is not supported. Hence vaule 3
   for trace level is not supported in CPUSS. */
#define CPUSS_TRACE_LVL                 2u
/* Embedded Trace Buffer present or not ('0': no, '1': yes) */
#define CPUSS_ETB_PRESENT               1u
/* CM0+ MTB SRAM buffer size in kilobytes. Legal vaules 4, 8 or 16 */
#define CPUSS_MTB_SRAM_SIZE             4u
/* CM4 ETB SRAM buffer size in kilobytes. Legal vaules 4, 8 or 16 */
#define CPUSS_ETB_SRAM_SIZE             8u
/* PTM interface present (0=No, 1=Yes) */
#define CPUSS_PTM_PRESENT               0u
/* Width of the PTM interface in bits ([2,32]) */
#define CPUSS_PTM_WIDTH                 1u
/* Width of the TPIU interface in bits ([1,4]) */
#define CPUSS_TPIU_WIDTH                4u
/* CoreSight Part Identification Number */
#define CPUSS_JEPID                     52u
/* CoreSight Part Identification Number */
#define CPUSS_JEPCONTINUATION           0u
/* CoreSight Part Identification Number */
#define CPUSS_FAMILYID                  257u
/* ROM trim register width (for ARM 3, for Synopsys 5) */
#define CPUSS_ROM_TRIM_WIDTH            3u
/* ROM trim register default (for both ARM and Synopsys 0x0000_0002) */
#define CPUSS_ROM_TRIM_DEFAULT          2u
/* RAM trim register width (for ARM 8, for Synopsys 15) */
#define CPUSS_RAM_TRIM_WIDTH            8u
/* RAM trim register default (for ARM 0x0000_0062 and for Synopsys 0x0000_6012) */
#define CPUSS_RAM_TRIM_DEFAULT          98u
/* Cryptography IP present or not ('0': no, '1': yes) */
#define CPUSS_CRYPTO_PRESENT            1u
/* DataWire and DMAC SW trigger per channel present or not ('0': no, '1': yes) */
#define CPUSS_SW_TR_PRESENT             1u
/* DataWire 0 present or not ('0': no, '1': yes) */
#define CPUSS_DW0_PRESENT               1u
/* Number of DataWire 0 channels ([1, 1024]) */
#define CPUSS_DW0_CH_NR                 89u
/* DataWire 1 present or not ('0': no, '1': yes) */
#define CPUSS_DW1_PRESENT               1u
/* Number of DataWire 1 channels ([1, 1024]) */
#define CPUSS_DW1_CH_NR                 33u
/* DMA controller present or not ('0': no, '1': yes) */
#define CPUSS_DMAC_PRESENT              1u
/* Number of DMA controller channels ([1, 8]) */
#define CPUSS_DMAC_CH_NR                4u
/* Number of Flash BIST_DATA registers */
#define CPUSS_FLASHC_FLASHC_BIST_DATA_NR 8u
/* Page size in # of 32-bit words (1: 4 bytes, 2: 8 bytes, ... */
#define CPUSS_FLASHC_PA_SIZE            128u
/* SONOS Flash is used or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_FLASHC_IS_SONOS    0u
/* eCT Flash is used or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_FLASHC_IS_ECT      1u
/* Cryptography SRAMs ECC present or not ('0': no, '1': yes) */
#define CPUSS_CRYPTO_ECC_PRESENT        1u
/* Cryptography SRAMs address ECC present or not ('0': no, '1': yes) */
#define CPUSS_CRYPTO_ECC_ADDR_PRESENT   1u
/* AES cipher support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_AES                1u
/* (Tripple) DES cipher support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_DES                1u
/* Chacha support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_CHACHA             1u
/* Pseudo random number generation support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_PR                 1u
/* SHA1 hash support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_SHA1               1u
/* SHA2 hash support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_SHA2               1u
/* SHA3 hash support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_SHA3               1u
/* Cyclic Redundancy Check support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_CRC                1u
/* True random number generation support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_TR                 1u
/* Vector unit support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_VU                 1u
/* Galios/Counter Mode (GCM) support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_GCM                1u
/* Number of 32-bit words in the IP internal memory buffer (from the set [64, 128,
   256, 512, 1024, 2048, 4096], to allow for a 256 B, 512 B, 1 kB, 2 kB, 4 kB, 8
   kB and 16 kB memory buffer) */
#define CPUSS_CRYPTO_BUFF_SIZE          2048u
/* Number of fault structures. Legal range [1, 4] */
#define CPUSS_FAULT_FAULT_NR            4u
/* Number of IPC structures. Legal range [1, 16] */
#define CPUSS_IPC_IPC_NR                8u
/* Number of IPC interrupt structures. Legal range [1, 16] */
#define CPUSS_IPC_IPC_IRQ_NR            8u
/* Master 0 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS0_PC_NR_MINUS1 7u
/* Master 1 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS1_PC_NR_MINUS1 0u
/* Master 2 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS2_PC_NR_MINUS1 0u
/* Master 3 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS3_PC_NR_MINUS1 0u
/* Master 4 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS4_PC_NR_MINUS1 0u
/* Master 5 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS5_PC_NR_MINUS1 0u
/* Master 6 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS6_PC_NR_MINUS1 0u
/* Master 7 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS7_PC_NR_MINUS1 0u
/* Master 8 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS8_PC_NR_MINUS1 0u
/* Master 9 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS9_PC_NR_MINUS1 0u
/* Master 10 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS10_PC_NR_MINUS1 0u
/* Master 11 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS11_PC_NR_MINUS1 0u
/* Master 12 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS12_PC_NR_MINUS1 0u
/* Master 13 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS13_PC_NR_MINUS1 0u
/* Master 14 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS14_PC_NR_MINUS1 7u
/* Master 15 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS15_PC_NR_MINUS1 7u
/* Number of SMPU protection structures */
#define CPUSS_PROT_SMPU_STRUCT_NR       16u
/* Number of protection contexts supported minus 1. Legal range [1,16] */
#define CPUSS_SMPU_STRUCT_PC_NR_MINUS1  7u
/* Number of DataWire controllers present (max 2) */
#define CPUSS_DW_NR                     2u
/* DataWire SRAMs ECC present or not ('0': no, '1': yes) */
#define CPUSS_DW_ECC_PRESENT            1u
/* DataWire SW trigger per channel present or not ('0': no, '1': yes) */
#define CPUSS_CH_STRUCT_SW_TR_PRESENT   1u
/* Number of DataWire controllers present (max 2) (same as DW.NR above) */
#define CPUSS_CPUSS_DW_DW_NR            2u
/* Number of channels in each DataWire controller */
#define CPUSS_CPUSS_DW_DW_NR0_DW_CH_NR  89u
/* Width of a channel number in bits */
#define CPUSS_CPUSS_DW_DW_NR0_DW_CH_NR_WIDTH 7u
/* Number of channels in each DataWire controller */
#define CPUSS_CPUSS_DW_DW_NR1_DW_CH_NR  33u
/* Width of a channel number in bits */
#define CPUSS_CPUSS_DW_DW_NR1_DW_CH_NR_WIDTH 6u
/* Number of DMA controller channels ([1, 8]) */
#define CPUSS_DMAC_CH_NR                4u
/* DMAC SW trigger per channel present or not ('0': no, '1': yes) */
#define CPUSS_CH_SW_TR_PRESENT          1u
/* See MMIO2 instantiation or not */
#define CPUSS_CHIP_TOP_PROFILER_PRESENT 0u
/* ETAS Calibration support pin out present (automotive only) */
#define CPUSS_CHIP_TOP_CAL_SUP_NZ_PRESENT 1u
/* TRACE_LVL>0 */
#define CPUSS_CHIP_TOP_TRACE_PRESENT    1u
/* Number of instantiated eFUSE macros (256 bit macros). Legal range [1, 16] */
#define EFUSE_EFUSE_NR                  4u
/* SONOS Flash is used or not ('0': no, '1': yes) */
#define SFLASH_FLASHC_IS_SONOS          0u
/* WOUND_PRESENT or not ('0': no, '1': yes) */
#define SFLASH_WOUND_PRESENT            0u
/* Number of HFCLK roots present. Must be > 0. Must be same as set for SRSS */
#define DFT_NUM_HFROOT                  3u
/* Width of clk_occ_fast output bus (number of external OCCs) */
#define DFT_EXT_OCC                     2u
/* Number of MBIST controllers with corresponding mbist(pg)_done and mbist(pg)_go
   signals. Value defined by CIC during Pass 1 */
#define DFT_MBIST_C_NUM                 6u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB0_DEEPSLEEP                  1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB0_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB0_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB0_I2C_GLITCH                 1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB0_I2C_S_EC                   1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB0_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB0_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB0_I2C_M_S                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB0_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB0_SPI_S                      1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB0_SPI_S_EC                   1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB0_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB0_SPI_EC                     1u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB0_EC                         1u
/* UART support? ('0': no, '1': yes) */
#define SCB0_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB0_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB0_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB0_CMD_RESP                   1u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB0_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB0_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB0_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB0_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB0_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB0_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB0_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB1_DEEPSLEEP                  0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB1_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB1_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB1_I2C_GLITCH                 1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB1_I2C_S_EC                   0u
/* I2C support? (I2C_M | I2C_S) */
#define SCB1_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB1_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB1_I2C_M_S                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB1_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB1_SPI_S                      1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB1_SPI_S_EC                   1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB1_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB1_SPI_EC                     1u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB1_EC                         1u
/* UART support? ('0': no, '1': yes) */
#define SCB1_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB1_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB1_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB1_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB1_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB1_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB1_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB1_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB1_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB1_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB1_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB2_DEEPSLEEP                  0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB2_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB2_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB2_I2C_GLITCH                 1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB2_I2C_S_EC                   0u
/* I2C support? (I2C_M | I2C_S) */
#define SCB2_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB2_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB2_I2C_M_S                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB2_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB2_SPI_S                      1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB2_SPI_S_EC                   1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB2_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB2_SPI_EC                     1u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB2_EC                         1u
/* UART support? ('0': no, '1': yes) */
#define SCB2_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB2_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB2_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB2_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB2_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB2_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB2_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB2_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB2_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB2_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB2_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB3_DEEPSLEEP                  0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB3_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB3_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB3_I2C_GLITCH                 1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB3_I2C_S_EC                   0u
/* I2C support? (I2C_M | I2C_S) */
#define SCB3_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB3_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB3_I2C_M_S                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB3_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB3_SPI_S                      1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB3_SPI_S_EC                   1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB3_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB3_SPI_EC                     1u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB3_EC                         1u
/* UART support? ('0': no, '1': yes) */
#define SCB3_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB3_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB3_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB3_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB3_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB3_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB3_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB3_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB3_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB3_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB3_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB4_DEEPSLEEP                  0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB4_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB4_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB4_I2C_GLITCH                 1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB4_I2C_S_EC                   0u
/* I2C support? (I2C_M | I2C_S) */
#define SCB4_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB4_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB4_I2C_M_S                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB4_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB4_SPI_S                      1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB4_SPI_S_EC                   1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB4_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB4_SPI_EC                     1u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB4_EC                         1u
/* UART support? ('0': no, '1': yes) */
#define SCB4_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB4_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB4_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB4_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB4_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB4_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB4_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB4_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB4_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB4_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB4_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB5_DEEPSLEEP                  0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB5_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB5_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB5_I2C_GLITCH                 1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB5_I2C_S_EC                   0u
/* I2C support? (I2C_M | I2C_S) */
#define SCB5_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB5_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB5_I2C_M_S                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB5_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB5_SPI_S                      1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB5_SPI_S_EC                   1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB5_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB5_SPI_EC                     1u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB5_EC                         1u
/* UART support? ('0': no, '1': yes) */
#define SCB5_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB5_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB5_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB5_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB5_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB5_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB5_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB5_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB5_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB5_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB5_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB6_DEEPSLEEP                  0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB6_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB6_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB6_I2C_GLITCH                 1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB6_I2C_S_EC                   0u
/* I2C support? (I2C_M | I2C_S) */
#define SCB6_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB6_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB6_I2C_M_S                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB6_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB6_SPI_S                      1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB6_SPI_S_EC                   1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB6_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB6_SPI_EC                     1u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB6_EC                         1u
/* UART support? ('0': no, '1': yes) */
#define SCB6_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB6_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB6_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB6_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB6_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB6_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB6_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB6_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB6_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB6_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB6_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB7_DEEPSLEEP                  0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB7_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB7_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB7_I2C_GLITCH                 1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB7_I2C_S_EC                   0u
/* I2C support? (I2C_M | I2C_S) */
#define SCB7_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB7_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB7_I2C_M_S                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB7_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB7_SPI_S                      1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB7_SPI_S_EC                   1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB7_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB7_SPI_EC                     1u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB7_EC                         1u
/* UART support? ('0': no, '1': yes) */
#define SCB7_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB7_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB7_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB7_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB7_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB7_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB7_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB7_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB7_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB7_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB7_CHIP_TOP_I2C_FAST_PLUS     1u
/* Number of input triggers per counter only routed to one counter (0..8) */
#define TCPWM_TR_ONE_CNT_NR             3u
/* Number of input triggers routed to all counters (0..254),
   NR_TR_ONE_CNT+NR_TR_ALL CNT <= 254 */
#define TCPWM_TR_ALL_CNT_NR             27u
/* Number of TCPWM counter groups (1..4) */
#define TCPWM_GRP_NR                    3u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM_GRP_NR0_GRP_GRP_CNT_NR    63u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM_GRP_NR0_CNT_GRP_CNT_WIDTH 16u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM_GRP_NR0_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   group_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR0_CNT_GRP_AMC_PRESENT 0u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM_GRP_NR0_CNT_GRP_SMC_PRESENT 0u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM_GRP_NR1_GRP_GRP_CNT_NR    12u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM_GRP_NR1_CNT_GRP_CNT_WIDTH 16u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM_GRP_NR1_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   group_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR1_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM_GRP_NR1_CNT_GRP_SMC_PRESENT 1u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM_GRP_NR2_GRP_GRP_CNT_NR    4u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM_GRP_NR2_CNT_GRP_CNT_WIDTH 32u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM_GRP_NR2_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   group_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR2_CNT_GRP_AMC_PRESENT 0u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM_GRP_NR2_CNT_GRP_SMC_PRESENT 0u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define TCPWM_MASTER_WIDTH              8u
/* Number of TTCAN instances */
#define CANFD0_CAN_NR                   3u
/* ECC logic present or not */
#define CANFD0_ECC_PRESENT              1u
/* address included in ECC logic or not */
#define CANFD0_ECC_ADDR_PRESENT         1u
/* Time Stamp counter present or not (required for instance 0, otherwise not
   allowed) */
#define CANFD0_TS_PRESENT               1u
/* Message RAM size in KB */
#define CANFD0_MRAM_SIZE                24u
/* Message RAM address width */
#define CANFD0_MRAM_ADDR_WIDTH          13u
/* Number of TTCAN instances */
#define CANFD1_CAN_NR                   3u
/* ECC logic present or not */
#define CANFD1_ECC_PRESENT              1u
/* address included in ECC logic or not */
#define CANFD1_ECC_ADDR_PRESENT         1u
/* Time Stamp counter present or not (required for instance 0, otherwise not
   allowed) */
#define CANFD1_TS_PRESENT               0u
/* Message RAM size in KB */
#define CANFD1_MRAM_SIZE                24u
/* Message RAM address width */
#define CANFD1_MRAM_ADDR_WIDTH          13u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define LIN_MASTER_WIDTH                8u
/* Number of LIN channels ([2, 32]). For test functionality (two channels are
   connected), the minimal number of LIN channels is 2. */
#define LIN_CH_NR                       8u
/* Number of SAR blocks */
#define PASS_SAR_ADC_NR                 3u
/* Number of SAR sequencer channels (per SAR) */
#define PASS_SAR_ADC_NR0_SAR_SAR_CHAN_NR 24u
/* Number of MUX inputs (per SAR), must be 8, 16, 24, or 32 */
#define PASS_SAR_ADC_NR0_SAR_SAR_MUX_IN 24u
/* Number of SAR sequencer channels (per SAR) */
#define PASS_SAR_ADC_NR1_SAR_SAR_CHAN_NR 32u
/* Number of MUX inputs (per SAR), must be 8, 16, 24, or 32 */
#define PASS_SAR_ADC_NR1_SAR_SAR_MUX_IN 32u
/* Number of SAR sequencer channels (per SAR) */
#define PASS_SAR_ADC_NR2_SAR_SAR_CHAN_NR 8u
/* Number of MUX inputs (per SAR), must be 8, 16, 24, or 32 */
#define PASS_SAR_ADC_NR2_SAR_SAR_MUX_IN 8u
/* Parameter that is 1 for ADC0 only if ADC1 exists */
#define PASS_SAR_SAR_ADC0               1u
/* Averaging logic present in SAR */
#define PASS_SAR_SAR_AVERAGE            1u
/* Range detect logic present in SAR */
#define PASS_SAR_SAR_RANGEDET           1u
/* Pulse detect logic present in SAR */
#define PASS_SAR_SAR_PULSEDET           1u
/* Number of comparator structures ([1, 32]) */
#define EVTGEN_COMP_STRUCT_NR           11u

/* MMIO Targets Defines */
#define CY_MMIO_CRYPTO_GROUP_NR         1u
#define CY_MMIO_CRYPTO_SLAVE_NR         0u
#define CY_MMIO_CPUSS_GROUP_NR          2u
#define CY_MMIO_CPUSS_SLAVE_NR          0u
#define CY_MMIO_FAULT_GROUP_NR          2u
#define CY_MMIO_FAULT_SLAVE_NR          1u
#define CY_MMIO_IPC_GROUP_NR            2u
#define CY_MMIO_IPC_SLAVE_NR            2u
#define CY_MMIO_PROT_GROUP_NR           2u
#define CY_MMIO_PROT_SLAVE_NR           3u
#define CY_MMIO_FLASHC_GROUP_NR         2u
#define CY_MMIO_FLASHC_SLAVE_NR         4u
#define CY_MMIO_SRSS_GROUP_NR           2u
#define CY_MMIO_SRSS_SLAVE_NR           5u
#define CY_MMIO_BACKUP_GROUP_NR         2u
#define CY_MMIO_BACKUP_SLAVE_NR         6u
#define CY_MMIO_DW_GROUP_NR             2u
#define CY_MMIO_DW_SLAVE_NR             7u
#define CY_MMIO_DMAC_GROUP_NR           2u
#define CY_MMIO_DMAC_SLAVE_NR           9u
#define CY_MMIO_EFUSE_GROUP_NR          2u
#define CY_MMIO_EFUSE_SLAVE_NR          10u
#define CY_MMIO_DFT_GROUP_NR            2u
#define CY_MMIO_DFT_SLAVE_NR            11u
#define CY_MMIO_HSIOM_GROUP_NR          3u
#define CY_MMIO_HSIOM_SLAVE_NR          0u
#define CY_MMIO_GPIO_GROUP_NR           3u
#define CY_MMIO_GPIO_SLAVE_NR           1u
#define CY_MMIO_SMARTIO_GROUP_NR        3u
#define CY_MMIO_SMARTIO_SLAVE_NR        2u
#define CY_MMIO_TCPWM0_GROUP_NR         3u
#define CY_MMIO_TCPWM0_SLAVE_NR         3u
#define CY_MMIO_EVTGEN0_GROUP_NR        3u
#define CY_MMIO_EVTGEN0_SLAVE_NR        4u
#define CY_MMIO_LIN0_GROUP_NR           5u
#define CY_MMIO_LIN0_SLAVE_NR           0u
#define CY_MMIO_CANFD0_GROUP_NR         5u
#define CY_MMIO_CANFD0_SLAVE_NR         1u
#define CY_MMIO_CANFD1_GROUP_NR         5u
#define CY_MMIO_CANFD1_SLAVE_NR         2u
#define CY_MMIO_SCB0_GROUP_NR           6u
#define CY_MMIO_SCB0_SLAVE_NR           0u
#define CY_MMIO_SCB1_GROUP_NR           6u
#define CY_MMIO_SCB1_SLAVE_NR           1u
#define CY_MMIO_SCB2_GROUP_NR           6u
#define CY_MMIO_SCB2_SLAVE_NR           2u
#define CY_MMIO_SCB3_GROUP_NR           6u
#define CY_MMIO_SCB3_SLAVE_NR           3u
#define CY_MMIO_SCB4_GROUP_NR           6u
#define CY_MMIO_SCB4_SLAVE_NR           4u
#define CY_MMIO_SCB5_GROUP_NR           6u
#define CY_MMIO_SCB5_SLAVE_NR           5u
#define CY_MMIO_SCB6_GROUP_NR           6u
#define CY_MMIO_SCB6_SLAVE_NR           6u
#define CY_MMIO_SCB7_GROUP_NR           6u
#define CY_MMIO_SCB7_SLAVE_NR           7u
#define CY_MMIO_PASS0_GROUP_NR          9u
#define CY_MMIO_PASS0_SLAVE_NR          0u

#endif /* _CYT2B7_CONFIG_H_ */


/* [] END OF FILE */
