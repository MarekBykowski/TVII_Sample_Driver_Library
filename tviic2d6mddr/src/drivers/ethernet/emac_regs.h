/* Copyright (C) 2016 Cadence Design Systems.  All rights reserved           */
/* THIS FILE IS AUTOMATICALLY GENERATED BY CADENCE BLUEPRINT, DO NOT EDIT    */
/*                                                                           */


#ifndef __REG_EMAC_REGS_H__
#define __REG_EMAC_REGS_H__

#include "emac_regs_macro.h"

#ifndef __REG_EMAC_REGS__
#define __REG_EMAC_REGS__

/**
* \addtogroup group_ethif_data_structures
* \{
*/

struct emac_regs {
  volatile uint32_t network_control;              /*        0x0 - 0x4        */
  volatile uint32_t network_config;               /*        0x4 - 0x8        */
  volatile uint32_t network_status;               /*        0x8 - 0xc        */
  volatile uint32_t user_io_register;             /*        0xc - 0x10       */
  volatile uint32_t dma_config;                   /*       0x10 - 0x14       */
  volatile uint32_t transmit_status;              /*       0x14 - 0x18       */
  volatile uint32_t receive_q_ptr;                /*       0x18 - 0x1c       */
  volatile uint32_t transmit_q_ptr;               /*       0x1c - 0x20       */
  volatile uint32_t receive_status;               /*       0x20 - 0x24       */
  volatile uint32_t int_status;                   /*       0x24 - 0x28       */
  volatile uint32_t int_enable;                   /*       0x28 - 0x2c       */
  volatile uint32_t int_disable;                  /*       0x2c - 0x30       */
  volatile uint32_t int_mask;                     /*       0x30 - 0x34       */
  volatile uint32_t phy_management;               /*       0x34 - 0x38       */
  volatile uint32_t pause_time;                   /*       0x38 - 0x3c       */
  volatile uint32_t tx_pause_quantum;             /*       0x3c - 0x40       */
  volatile uint32_t pbuf_txcutthru;               /*       0x40 - 0x44       */
  volatile uint32_t pbuf_rxcutthru;               /*       0x44 - 0x48       */
  volatile uint32_t jumbo_max_length;             /*       0x48 - 0x4c       */
  volatile uint32_t external_fifo_interface;      /*       0x4c - 0x50       */
  volatile char pad__0[0x4];                      /*       0x50 - 0x54       */
  volatile uint32_t axi_max_pipeline;             /*       0x54 - 0x58       */
  volatile uint32_t rsc_control;                  /*       0x58 - 0x5c       */
  volatile uint32_t int_moderation;               /*       0x5c - 0x60       */
  volatile uint32_t sys_wake_time;                /*       0x60 - 0x64       */
  volatile char pad__1[0x1c];                     /*       0x64 - 0x80       */
  volatile uint32_t hash_bottom;                  /*       0x80 - 0x84       */
  volatile uint32_t hash_top;                     /*       0x84 - 0x88       */
  volatile uint32_t spec_add1_bottom;             /*       0x88 - 0x8c       */
  volatile uint32_t spec_add1_top;                /*       0x8c - 0x90       */
  volatile uint32_t spec_add2_bottom;             /*       0x90 - 0x94       */
  volatile uint32_t spec_add2_top;                /*       0x94 - 0x98       */
  volatile uint32_t spec_add3_bottom;             /*       0x98 - 0x9c       */
  volatile uint32_t spec_add3_top;                /*       0x9c - 0xa0       */
  volatile uint32_t spec_add4_bottom;             /*       0xa0 - 0xa4       */
  volatile uint32_t spec_add4_top;                /*       0xa4 - 0xa8       */
  volatile uint32_t spec_type1;                   /*       0xa8 - 0xac       */
  volatile uint32_t spec_type2;                   /*       0xac - 0xb0       */
  volatile uint32_t spec_type3;                   /*       0xb0 - 0xb4       */
  volatile uint32_t spec_type4;                   /*       0xb4 - 0xb8       */
  volatile uint32_t wol_register;                 /*       0xb8 - 0xbc       */
  volatile uint32_t stretch_ratio;                /*       0xbc - 0xc0       */
  volatile uint32_t stacked_vlan;                 /*       0xc0 - 0xc4       */
  volatile uint32_t tx_pfc_pause;                 /*       0xc4 - 0xc8       */
  volatile uint32_t mask_add1_bottom;             /*       0xc8 - 0xcc       */
  volatile uint32_t mask_add1_top;                /*       0xcc - 0xd0       */
  volatile uint32_t dma_addr_or_mask;             /*       0xd0 - 0xd4       */
  volatile uint32_t rx_ptp_unicast;               /*       0xd4 - 0xd8       */
  volatile uint32_t tx_ptp_unicast;               /*       0xd8 - 0xdc       */
  volatile uint32_t tsu_nsec_cmp;                 /*       0xdc - 0xe0       */
  volatile uint32_t tsu_sec_cmp;                  /*       0xe0 - 0xe4       */
  volatile uint32_t tsu_msb_sec_cmp;              /*       0xe4 - 0xe8       */
  volatile uint32_t tsu_ptp_tx_msb_sec;           /*       0xe8 - 0xec       */
  volatile uint32_t tsu_ptp_rx_msb_sec;           /*       0xec - 0xf0       */
  volatile uint32_t tsu_peer_tx_msb_sec;          /*       0xf0 - 0xf4       */
  volatile uint32_t tsu_peer_rx_msb_sec;          /*       0xf4 - 0xf8       */
  volatile uint32_t dpram_fill_dbg;               /*       0xf8 - 0xfc       */
  volatile uint32_t revision_reg;                 /*       0xfc - 0x100      */
  volatile uint32_t octets_txed_bottom;           /*      0x100 - 0x104      */
  volatile uint32_t octets_txed_top;              /*      0x104 - 0x108      */
  volatile uint32_t frames_txed_ok;               /*      0x108 - 0x10c      */
  volatile uint32_t broadcast_txed;               /*      0x10c - 0x110      */
  volatile uint32_t multicast_txed;               /*      0x110 - 0x114      */
  volatile uint32_t pause_frames_txed;            /*      0x114 - 0x118      */
  volatile uint32_t frames_txed_64;               /*      0x118 - 0x11c      */
  volatile uint32_t frames_txed_65;               /*      0x11c - 0x120      */
  volatile uint32_t frames_txed_128;              /*      0x120 - 0x124      */
  volatile uint32_t frames_txed_256;              /*      0x124 - 0x128      */
  volatile uint32_t frames_txed_512;              /*      0x128 - 0x12c      */
  volatile uint32_t frames_txed_1024;             /*      0x12c - 0x130      */
  volatile uint32_t frames_txed_1519;             /*      0x130 - 0x134      */
  volatile uint32_t tx_underruns;                 /*      0x134 - 0x138      */
  volatile uint32_t single_collisions;            /*      0x138 - 0x13c      */
  volatile uint32_t multiple_collisions;          /*      0x13c - 0x140      */
  volatile uint32_t excessive_collisions;         /*      0x140 - 0x144      */
  volatile uint32_t late_collisions;              /*      0x144 - 0x148      */
  volatile uint32_t deferred_frames;              /*      0x148 - 0x14c      */
  volatile uint32_t crs_errors;                   /*      0x14c - 0x150      */
  volatile uint32_t octets_rxed_bottom;           /*      0x150 - 0x154      */
  volatile uint32_t octets_rxed_top;              /*      0x154 - 0x158      */
  volatile uint32_t frames_rxed_ok;               /*      0x158 - 0x15c      */
  volatile uint32_t broadcast_rxed;               /*      0x15c - 0x160      */
  volatile uint32_t multicast_rxed;               /*      0x160 - 0x164      */
  volatile uint32_t pause_frames_rxed;            /*      0x164 - 0x168      */
  volatile uint32_t frames_rxed_64;               /*      0x168 - 0x16c      */
  volatile uint32_t frames_rxed_65;               /*      0x16c - 0x170      */
  volatile uint32_t frames_rxed_128;              /*      0x170 - 0x174      */
  volatile uint32_t frames_rxed_256;              /*      0x174 - 0x178      */
  volatile uint32_t frames_rxed_512;              /*      0x178 - 0x17c      */
  volatile uint32_t frames_rxed_1024;             /*      0x17c - 0x180      */
  volatile uint32_t frames_rxed_1519;             /*      0x180 - 0x184      */
  volatile uint32_t undersize_frames;             /*      0x184 - 0x188      */
  volatile uint32_t excessive_rx_length;          /*      0x188 - 0x18c      */
  volatile uint32_t rx_jabbers;                   /*      0x18c - 0x190      */
  volatile uint32_t fcs_errors;                   /*      0x190 - 0x194      */
  volatile uint32_t rx_length_errors;             /*      0x194 - 0x198      */
  volatile uint32_t rx_symbol_errors;             /*      0x198 - 0x19c      */
  volatile uint32_t alignment_errors;             /*      0x19c - 0x1a0      */
  volatile uint32_t rx_resource_errors;           /*      0x1a0 - 0x1a4      */
  volatile uint32_t rx_overruns;                  /*      0x1a4 - 0x1a8      */
  volatile uint32_t rx_ip_ck_errors;              /*      0x1a8 - 0x1ac      */
  volatile uint32_t rx_tcp_ck_errors;             /*      0x1ac - 0x1b0      */
  volatile uint32_t rx_udp_ck_errors;             /*      0x1b0 - 0x1b4      */
  volatile uint32_t auto_flushed_pkts;            /*      0x1b4 - 0x1b8      */
  volatile char pad__2[0x4];                      /*      0x1b8 - 0x1bc      */
  volatile uint32_t tsu_timer_incr_sub_nsec;      /*      0x1bc - 0x1c0      */
  volatile uint32_t tsu_timer_msb_sec;            /*      0x1c0 - 0x1c4      */
  volatile uint32_t tsu_strobe_msb_sec;           /*      0x1c4 - 0x1c8      */
  volatile uint32_t tsu_strobe_sec;               /*      0x1c8 - 0x1cc      */
  volatile uint32_t tsu_strobe_nsec;              /*      0x1cc - 0x1d0      */
  volatile uint32_t tsu_timer_sec;                /*      0x1d0 - 0x1d4      */
  volatile uint32_t tsu_timer_nsec;               /*      0x1d4 - 0x1d8      */
  volatile uint32_t tsu_timer_adjust;             /*      0x1d8 - 0x1dc      */
  volatile uint32_t tsu_timer_incr;               /*      0x1dc - 0x1e0      */
  volatile uint32_t tsu_ptp_tx_sec;               /*      0x1e0 - 0x1e4      */
  volatile uint32_t tsu_ptp_tx_nsec;              /*      0x1e4 - 0x1e8      */
  volatile uint32_t tsu_ptp_rx_sec;               /*      0x1e8 - 0x1ec      */
  volatile uint32_t tsu_ptp_rx_nsec;              /*      0x1ec - 0x1f0      */
  volatile uint32_t tsu_peer_tx_sec;              /*      0x1f0 - 0x1f4      */
  volatile uint32_t tsu_peer_tx_nsec;             /*      0x1f4 - 0x1f8      */
  volatile uint32_t tsu_peer_rx_sec;              /*      0x1f8 - 0x1fc      */
  volatile uint32_t tsu_peer_rx_nsec;             /*      0x1fc - 0x200      */
  volatile uint32_t pcs_control;                  /*      0x200 - 0x204      */
  volatile uint32_t pcs_status;                   /*      0x204 - 0x208      */
  volatile char pad__3[0x8];                      /*      0x208 - 0x210      */
  volatile uint32_t pcs_an_adv;                   /*      0x210 - 0x214      */
  volatile uint32_t pcs_an_lp_base;               /*      0x214 - 0x218      */
  volatile uint32_t pcs_an_exp;                   /*      0x218 - 0x21c      */
  volatile uint32_t pcs_an_np_tx;                 /*      0x21c - 0x220      */
  volatile uint32_t pcs_an_lp_np;                 /*      0x220 - 0x224      */
  volatile char pad__4[0x18];                     /*      0x224 - 0x23c      */
  volatile uint32_t pcs_an_ext_status;            /*      0x23c - 0x240      */
  volatile char pad__5[0x20];                     /*      0x240 - 0x260      */
  volatile uint32_t tx_pause_quantum1;            /*      0x260 - 0x264      */
  volatile uint32_t tx_pause_quantum2;            /*      0x264 - 0x268      */
  volatile uint32_t tx_pause_quantum3;            /*      0x268 - 0x26c      */
  volatile char pad__6[0x4];                      /*      0x26c - 0x270      */
  volatile uint32_t rx_lpi;                       /*      0x270 - 0x274      */
  volatile uint32_t rx_lpi_time;                  /*      0x274 - 0x278      */
  volatile uint32_t tx_lpi;                       /*      0x278 - 0x27c      */
  volatile uint32_t tx_lpi_time;                  /*      0x27c - 0x280      */
  volatile uint32_t designcfg_debug1;             /*      0x280 - 0x284      */
  volatile uint32_t designcfg_debug2;             /*      0x284 - 0x288      */
  volatile uint32_t designcfg_debug3;             /*      0x288 - 0x28c      */
  volatile uint32_t designcfg_debug4;             /*      0x28c - 0x290      */
  volatile uint32_t designcfg_debug5;             /*      0x290 - 0x294      */
  volatile uint32_t designcfg_debug6;             /*      0x294 - 0x298      */
  volatile uint32_t designcfg_debug7;             /*      0x298 - 0x29c      */
  volatile uint32_t designcfg_debug8;             /*      0x29c - 0x2a0      */
  volatile uint32_t designcfg_debug9;             /*      0x2a0 - 0x2a4      */
  volatile uint32_t designcfg_debug10;            /*      0x2a4 - 0x2a8      */
  volatile char pad__7[0x58];                     /*      0x2a8 - 0x300      */
  volatile uint32_t spec_add5_bottom;             /*      0x300 - 0x304      */
  volatile uint32_t spec_add5_top;                /*      0x304 - 0x308      */
  volatile uint32_t spec_add6_bottom;             /*      0x308 - 0x30c      */
  volatile uint32_t spec_add6_top;                /*      0x30c - 0x310      */
  volatile uint32_t spec_add7_bottom;             /*      0x310 - 0x314      */
  volatile uint32_t spec_add7_top;                /*      0x314 - 0x318      */
  volatile uint32_t spec_add8_bottom;             /*      0x318 - 0x31c      */
  volatile uint32_t spec_add8_top;                /*      0x31c - 0x320      */
  volatile uint32_t spec_add9_bottom;             /*      0x320 - 0x324      */
  volatile uint32_t spec_add9_top;                /*      0x324 - 0x328      */
  volatile uint32_t spec_add10_bottom;            /*      0x328 - 0x32c      */
  volatile uint32_t spec_add10_top;               /*      0x32c - 0x330      */
  volatile uint32_t spec_add11_bottom;            /*      0x330 - 0x334      */
  volatile uint32_t spec_add11_top;               /*      0x334 - 0x338      */
  volatile uint32_t spec_add12_bottom;            /*      0x338 - 0x33c      */
  volatile uint32_t spec_add12_top;               /*      0x33c - 0x340      */
  volatile uint32_t spec_add13_bottom;            /*      0x340 - 0x344      */
  volatile uint32_t spec_add13_top;               /*      0x344 - 0x348      */
  volatile uint32_t spec_add14_bottom;            /*      0x348 - 0x34c      */
  volatile uint32_t spec_add14_top;               /*      0x34c - 0x350      */
  volatile uint32_t spec_add15_bottom;            /*      0x350 - 0x354      */
  volatile uint32_t spec_add15_top;               /*      0x354 - 0x358      */
  volatile uint32_t spec_add16_bottom;            /*      0x358 - 0x35c      */
  volatile uint32_t spec_add16_top;               /*      0x35c - 0x360      */
  volatile uint32_t spec_add17_bottom;            /*      0x360 - 0x364      */
  volatile uint32_t spec_add17_top;               /*      0x364 - 0x368      */
  volatile uint32_t spec_add18_bottom;            /*      0x368 - 0x36c      */
  volatile uint32_t spec_add18_top;               /*      0x36c - 0x370      */
  volatile uint32_t spec_add19_bottom;            /*      0x370 - 0x374      */
  volatile uint32_t spec_add19_top;               /*      0x374 - 0x378      */
  volatile uint32_t spec_add20_bottom;            /*      0x378 - 0x37c      */
  volatile uint32_t spec_add20_top;               /*      0x37c - 0x380      */
  volatile uint32_t spec_add21_bottom;            /*      0x380 - 0x384      */
  volatile uint32_t spec_add21_top;               /*      0x384 - 0x388      */
  volatile uint32_t spec_add22_bottom;            /*      0x388 - 0x38c      */
  volatile uint32_t spec_add22_top;               /*      0x38c - 0x390      */
  volatile uint32_t spec_add23_bottom;            /*      0x390 - 0x394      */
  volatile uint32_t spec_add23_top;               /*      0x394 - 0x398      */
  volatile uint32_t spec_add24_bottom;            /*      0x398 - 0x39c      */
  volatile uint32_t spec_add24_top;               /*      0x39c - 0x3a0      */
  volatile uint32_t spec_add25_bottom;            /*      0x3a0 - 0x3a4      */
  volatile uint32_t spec_add25_top;               /*      0x3a4 - 0x3a8      */
  volatile uint32_t spec_add26_bottom;            /*      0x3a8 - 0x3ac      */
  volatile uint32_t spec_add26_top;               /*      0x3ac - 0x3b0      */
  volatile uint32_t spec_add27_bottom;            /*      0x3b0 - 0x3b4      */
  volatile uint32_t spec_add27_top;               /*      0x3b4 - 0x3b8      */
  volatile uint32_t spec_add28_bottom;            /*      0x3b8 - 0x3bc      */
  volatile uint32_t spec_add28_top;               /*      0x3bc - 0x3c0      */
  volatile uint32_t spec_add29_bottom;            /*      0x3c0 - 0x3c4      */
  volatile uint32_t spec_add29_top;               /*      0x3c4 - 0x3c8      */
  volatile uint32_t spec_add30_bottom;            /*      0x3c8 - 0x3cc      */
  volatile uint32_t spec_add30_top;               /*      0x3cc - 0x3d0      */
  volatile uint32_t spec_add31_bottom;            /*      0x3d0 - 0x3d4      */
  volatile uint32_t spec_add31_top;               /*      0x3d4 - 0x3d8      */
  volatile uint32_t spec_add32_bottom;            /*      0x3d8 - 0x3dc      */
  volatile uint32_t spec_add32_top;               /*      0x3dc - 0x3e0      */
  volatile uint32_t spec_add33_bottom;            /*      0x3e0 - 0x3e4      */
  volatile uint32_t spec_add33_top;               /*      0x3e4 - 0x3e8      */
  volatile uint32_t spec_add34_bottom;            /*      0x3e8 - 0x3ec      */
  volatile uint32_t spec_add34_top;               /*      0x3ec - 0x3f0      */
  volatile uint32_t spec_add35_bottom;            /*      0x3f0 - 0x3f4      */
  volatile uint32_t spec_add35_top;               /*      0x3f4 - 0x3f8      */
  volatile uint32_t spec_add36_bottom;            /*      0x3f8 - 0x3fc      */
  volatile uint32_t spec_add36_top;               /*      0x3fc - 0x400      */
  volatile uint32_t int_q1_status;                /*      0x400 - 0x404      */
  volatile uint32_t int_q2_status;                /*      0x404 - 0x408      */
  volatile uint32_t int_q3_status;                /*      0x408 - 0x40c      */
  volatile uint32_t int_q4_status;                /*      0x40c - 0x410      */
  volatile uint32_t int_q5_status;                /*      0x410 - 0x414      */
  volatile uint32_t int_q6_status;                /*      0x414 - 0x418      */
  volatile uint32_t int_q7_status;                /*      0x418 - 0x41c      */
  volatile uint32_t int_q8_status;                /*      0x41c - 0x420      */
  volatile uint32_t int_q9_status;                /*      0x420 - 0x424      */
  volatile uint32_t int_q10_status;               /*      0x424 - 0x428      */
  volatile uint32_t int_q11_status;               /*      0x428 - 0x42c      */
  volatile uint32_t int_q12_status;               /*      0x42c - 0x430      */
  volatile uint32_t int_q13_status;               /*      0x430 - 0x434      */
  volatile uint32_t int_q14_status;               /*      0x434 - 0x438      */
  volatile uint32_t int_q15_status;               /*      0x438 - 0x43c      */
  volatile char pad__8[0x4];                      /*      0x43c - 0x440      */
  volatile uint32_t transmit_q1_ptr;              /*      0x440 - 0x444      */
  volatile uint32_t transmit_q2_ptr;              /*      0x444 - 0x448      */
  volatile uint32_t transmit_q3_ptr;              /*      0x448 - 0x44c      */
  volatile uint32_t transmit_q4_ptr;              /*      0x44c - 0x450      */
  volatile uint32_t transmit_q5_ptr;              /*      0x450 - 0x454      */
  volatile uint32_t transmit_q6_ptr;              /*      0x454 - 0x458      */
  volatile uint32_t transmit_q7_ptr;              /*      0x458 - 0x45c      */
  volatile uint32_t transmit_q8_ptr;              /*      0x45c - 0x460      */
  volatile uint32_t transmit_q9_ptr;              /*      0x460 - 0x464      */
  volatile uint32_t transmit_q10_ptr;             /*      0x464 - 0x468      */
  volatile uint32_t transmit_q11_ptr;             /*      0x468 - 0x46c      */
  volatile uint32_t transmit_q12_ptr;             /*      0x46c - 0x470      */
  volatile uint32_t transmit_q13_ptr;             /*      0x470 - 0x474      */
  volatile uint32_t transmit_q14_ptr;             /*      0x474 - 0x478      */
  volatile uint32_t transmit_q15_ptr;             /*      0x478 - 0x47c      */
  volatile char pad__9[0x4];                      /*      0x47c - 0x480      */
  volatile uint32_t receive_q1_ptr;               /*      0x480 - 0x484      */
  volatile uint32_t receive_q2_ptr;               /*      0x484 - 0x488      */
  volatile uint32_t receive_q3_ptr;               /*      0x488 - 0x48c      */
  volatile uint32_t receive_q4_ptr;               /*      0x48c - 0x490      */
  volatile uint32_t receive_q5_ptr;               /*      0x490 - 0x494      */
  volatile uint32_t receive_q6_ptr;               /*      0x494 - 0x498      */
  volatile uint32_t receive_q7_ptr;               /*      0x498 - 0x49c      */
  volatile char pad__10[0x4];                     /*      0x49c - 0x4a0      */
  volatile uint32_t dma_rxbuf_size_q1;            /*      0x4a0 - 0x4a4      */
  volatile uint32_t dma_rxbuf_size_q2;            /*      0x4a4 - 0x4a8      */
  volatile uint32_t dma_rxbuf_size_q3;            /*      0x4a8 - 0x4ac      */
  volatile uint32_t dma_rxbuf_size_q4;            /*      0x4ac - 0x4b0      */
  volatile uint32_t dma_rxbuf_size_q5;            /*      0x4b0 - 0x4b4      */
  volatile uint32_t dma_rxbuf_size_q6;            /*      0x4b4 - 0x4b8      */
  volatile uint32_t dma_rxbuf_size_q7;            /*      0x4b8 - 0x4bc      */
  volatile uint32_t cbs_control;                  /*      0x4bc - 0x4c0      */
  volatile uint32_t cbs_idleslope_q_a;            /*      0x4c0 - 0x4c4      */
  volatile uint32_t cbs_idleslope_q_b;            /*      0x4c4 - 0x4c8      */
  volatile uint32_t upper_tx_q_base_addr;         /*      0x4c8 - 0x4cc      */
  volatile uint32_t tx_bd_control;                /*      0x4cc - 0x4d0      */
  volatile uint32_t rx_bd_control;                /*      0x4d0 - 0x4d4      */
  volatile uint32_t upper_rx_q_base_addr;         /*      0x4d4 - 0x4d8      */
  volatile char pad__11[0x28];                    /*      0x4d8 - 0x500      */
  volatile uint32_t screening_type_1_register_0;  /*      0x500 - 0x504      */
  volatile uint32_t screening_type_1_register_1;  /*      0x504 - 0x508      */
  volatile uint32_t screening_type_1_register_2;  /*      0x508 - 0x50c      */
  volatile uint32_t screening_type_1_register_3;  /*      0x50c - 0x510      */
  volatile uint32_t screening_type_1_register_4;  /*      0x510 - 0x514      */
  volatile uint32_t screening_type_1_register_5;  /*      0x514 - 0x518      */
  volatile uint32_t screening_type_1_register_6;  /*      0x518 - 0x51c      */
  volatile uint32_t screening_type_1_register_7;  /*      0x51c - 0x520      */
  volatile uint32_t screening_type_1_register_8;  /*      0x520 - 0x524      */
  volatile uint32_t screening_type_1_register_9;  /*      0x524 - 0x528      */
  volatile uint32_t screening_type_1_register_10; /*      0x528 - 0x52c      */
  volatile uint32_t screening_type_1_register_11; /*      0x52c - 0x530      */
  volatile uint32_t screening_type_1_register_12; /*      0x530 - 0x534      */
  volatile uint32_t screening_type_1_register_13; /*      0x534 - 0x538      */
  volatile uint32_t screening_type_1_register_14; /*      0x538 - 0x53c      */
  volatile uint32_t screening_type_1_register_15; /*      0x53c - 0x540      */
  volatile uint32_t screening_type_2_register_0;  /*      0x540 - 0x544      */
  volatile uint32_t screening_type_2_register_1;  /*      0x544 - 0x548      */
  volatile uint32_t screening_type_2_register_2;  /*      0x548 - 0x54c      */
  volatile uint32_t screening_type_2_register_3;  /*      0x54c - 0x550      */
  volatile uint32_t screening_type_2_register_4;  /*      0x550 - 0x554      */
  volatile uint32_t screening_type_2_register_5;  /*      0x554 - 0x558      */
  volatile uint32_t screening_type_2_register_6;  /*      0x558 - 0x55c      */
  volatile uint32_t screening_type_2_register_7;  /*      0x55c - 0x560      */
  volatile uint32_t screening_type_2_register_8;  /*      0x560 - 0x564      */
  volatile uint32_t screening_type_2_register_9;  /*      0x564 - 0x568      */
  volatile uint32_t screening_type_2_register_10; /*      0x568 - 0x56c      */
  volatile uint32_t screening_type_2_register_11; /*      0x56c - 0x570      */
  volatile uint32_t screening_type_2_register_12; /*      0x570 - 0x574      */
  volatile uint32_t screening_type_2_register_13; /*      0x574 - 0x578      */
  volatile uint32_t screening_type_2_register_14; /*      0x578 - 0x57c      */
  volatile uint32_t screening_type_2_register_15; /*      0x57c - 0x580      */
  volatile uint32_t tx_sched_ctrl;                /*      0x580 - 0x584      */
  volatile char pad__12[0xc];                     /*      0x584 - 0x590      */
  volatile uint32_t bw_rate_limit_q0to3;          /*      0x590 - 0x594      */
  volatile uint32_t bw_rate_limit_q4to7;          /*      0x594 - 0x598      */
  volatile uint32_t bw_rate_limit_q8to11;         /*      0x598 - 0x59c      */
  volatile uint32_t bw_rate_limit_q12to15;        /*      0x59c - 0x5a0      */
  volatile uint32_t tx_q_seg_alloc_q0to7;         /*      0x5a0 - 0x5a4      */
  volatile uint32_t tx_q_seg_alloc_q8to15;        /*      0x5a4 - 0x5a8      */
  volatile char pad__13[0x18];                    /*      0x5a8 - 0x5c0      */
  volatile uint32_t receive_q8_ptr;               /*      0x5c0 - 0x5c4      */
  volatile uint32_t receive_q9_ptr;               /*      0x5c4 - 0x5c8      */
  volatile uint32_t receive_q10_ptr;              /*      0x5c8 - 0x5cc      */
  volatile uint32_t receive_q11_ptr;              /*      0x5cc - 0x5d0      */
  volatile uint32_t receive_q12_ptr;              /*      0x5d0 - 0x5d4      */
  volatile uint32_t receive_q13_ptr;              /*      0x5d4 - 0x5d8      */
  volatile uint32_t receive_q14_ptr;              /*      0x5d8 - 0x5dc      */
  volatile uint32_t receive_q15_ptr;              /*      0x5dc - 0x5e0      */
  volatile uint32_t dma_rxbuf_size_q8;            /*      0x5e0 - 0x5e4      */
  volatile uint32_t dma_rxbuf_size_q9;            /*      0x5e4 - 0x5e8      */
  volatile uint32_t dma_rxbuf_size_q10;           /*      0x5e8 - 0x5ec      */
  volatile uint32_t dma_rxbuf_size_q11;           /*      0x5ec - 0x5f0      */
  volatile uint32_t dma_rxbuf_size_q12;           /*      0x5f0 - 0x5f4      */
  volatile uint32_t dma_rxbuf_size_q13;           /*      0x5f4 - 0x5f8      */
  volatile uint32_t dma_rxbuf_size_q14;           /*      0x5f8 - 0x5fc      */
  volatile uint32_t dma_rxbuf_size_q15;           /*      0x5fc - 0x600      */
  volatile uint32_t int_q1_enable;                /*      0x600 - 0x604      */
  volatile uint32_t int_q2_enable;                /*      0x604 - 0x608      */
  volatile uint32_t int_q3_enable;                /*      0x608 - 0x60c      */
  volatile uint32_t int_q4_enable;                /*      0x60c - 0x610      */
  volatile uint32_t int_q5_enable;                /*      0x610 - 0x614      */
  volatile uint32_t int_q6_enable;                /*      0x614 - 0x618      */
  volatile uint32_t int_q7_enable;                /*      0x618 - 0x61c      */
  volatile char pad__14[0x4];                     /*      0x61c - 0x620      */
  volatile uint32_t int_q1_disable;               /*      0x620 - 0x624      */
  volatile uint32_t int_q2_disable;               /*      0x624 - 0x628      */
  volatile uint32_t int_q3_disable;               /*      0x628 - 0x62c      */
  volatile uint32_t int_q4_disable;               /*      0x62c - 0x630      */
  volatile uint32_t int_q5_disable;               /*      0x630 - 0x634      */
  volatile uint32_t int_q6_disable;               /*      0x634 - 0x638      */
  volatile uint32_t int_q7_disable;               /*      0x638 - 0x63c      */
  volatile char pad__15[0x4];                     /*      0x63c - 0x640      */
  volatile uint32_t int_q1_mask;                  /*      0x640 - 0x644      */
  volatile uint32_t int_q2_mask;                  /*      0x644 - 0x648      */
  volatile uint32_t int_q3_mask;                  /*      0x648 - 0x64c      */
  volatile uint32_t int_q4_mask;                  /*      0x64c - 0x650      */
  volatile uint32_t int_q5_mask;                  /*      0x650 - 0x654      */
  volatile uint32_t int_q6_mask;                  /*      0x654 - 0x658      */
  volatile uint32_t int_q7_mask;                  /*      0x658 - 0x65c      */
  volatile char pad__16[0x4];                     /*      0x65c - 0x660      */
  volatile uint32_t int_q8_enable;                /*      0x660 - 0x664      */
  volatile uint32_t int_q9_enable;                /*      0x664 - 0x668      */
  volatile uint32_t int_q10_enable;               /*      0x668 - 0x66c      */
  volatile uint32_t int_q11_enable;               /*      0x66c - 0x670      */
  volatile uint32_t int_q12_enable;               /*      0x670 - 0x674      */
  volatile uint32_t int_q13_enable;               /*      0x674 - 0x678      */
  volatile uint32_t int_q14_enable;               /*      0x678 - 0x67c      */
  volatile uint32_t int_q15_enable;               /*      0x67c - 0x680      */
  volatile uint32_t int_q8_disable;               /*      0x680 - 0x684      */
  volatile uint32_t int_q9_disable;               /*      0x684 - 0x688      */
  volatile uint32_t int_q10_disable;              /*      0x688 - 0x68c      */
  volatile uint32_t int_q11_disable;              /*      0x68c - 0x690      */
  volatile uint32_t int_q12_disable;              /*      0x690 - 0x694      */
  volatile uint32_t int_q13_disable;              /*      0x694 - 0x698      */
  volatile uint32_t int_q14_disable;              /*      0x698 - 0x69c      */
  volatile uint32_t int_q15_disable;              /*      0x69c - 0x6a0      */
  volatile uint32_t int_q8_mask;                  /*      0x6a0 - 0x6a4      */
  volatile uint32_t int_q9_mask;                  /*      0x6a4 - 0x6a8      */
  volatile uint32_t int_q10_mask;                 /*      0x6a8 - 0x6ac      */
  volatile uint32_t int_q11_mask;                 /*      0x6ac - 0x6b0      */
  volatile uint32_t int_q12_mask;                 /*      0x6b0 - 0x6b4      */
  volatile uint32_t int_q13_mask;                 /*      0x6b4 - 0x6b8      */
  volatile uint32_t int_q14_mask;                 /*      0x6b8 - 0x6bc      */
  volatile uint32_t int_q15_mask;                 /*      0x6bc - 0x6c0      */
  volatile char pad__17[0x20];                    /*      0x6c0 - 0x6e0      */
  volatile uint32_t screening_type_2_ethertype_reg_0;
                                                  /*      0x6e0 - 0x6e4      */
  volatile uint32_t screening_type_2_ethertype_reg_1;
                                                  /*      0x6e4 - 0x6e8      */
  volatile uint32_t screening_type_2_ethertype_reg_2;
                                                  /*      0x6e8 - 0x6ec      */
  volatile uint32_t screening_type_2_ethertype_reg_3;
                                                  /*      0x6ec - 0x6f0      */
  volatile uint32_t screening_type_2_ethertype_reg_4;
                                                  /*      0x6f0 - 0x6f4      */
  volatile uint32_t screening_type_2_ethertype_reg_5;
                                                  /*      0x6f4 - 0x6f8      */
  volatile uint32_t screening_type_2_ethertype_reg_6;
                                                  /*      0x6f8 - 0x6fc      */
  volatile uint32_t screening_type_2_ethertype_reg_7;
                                                  /*      0x6fc - 0x700      */
  volatile uint32_t type2_compare_0_word_0;       /*      0x700 - 0x704      */
  volatile uint32_t type2_compare_0_word_1;       /*      0x704 - 0x708      */
  volatile uint32_t type2_compare_1_word_0;       /*      0x708 - 0x70c      */
  volatile uint32_t type2_compare_1_word_1;       /*      0x70c - 0x710      */
  volatile uint32_t type2_compare_2_word_0;       /*      0x710 - 0x714      */
  volatile uint32_t type2_compare_2_word_1;       /*      0x714 - 0x718      */
  volatile uint32_t type2_compare_3_word_0;       /*      0x718 - 0x71c      */
  volatile uint32_t type2_compare_3_word_1;       /*      0x71c - 0x720      */
  volatile uint32_t type2_compare_4_word_0;       /*      0x720 - 0x724      */
  volatile uint32_t type2_compare_4_word_1;       /*      0x724 - 0x728      */
  volatile uint32_t type2_compare_5_word_0;       /*      0x728 - 0x72c      */
  volatile uint32_t type2_compare_5_word_1;       /*      0x72c - 0x730      */
  volatile uint32_t type2_compare_6_word_0;       /*      0x730 - 0x734      */
  volatile uint32_t type2_compare_6_word_1;       /*      0x734 - 0x738      */
  volatile uint32_t type2_compare_7_word_0;       /*      0x738 - 0x73c      */
  volatile uint32_t type2_compare_7_word_1;       /*      0x73c - 0x740      */
  volatile uint32_t type2_compare_8_word_0;       /*      0x740 - 0x744      */
  volatile uint32_t type2_compare_8_word_1;       /*      0x744 - 0x748      */
  volatile uint32_t type2_compare_9_word_0;       /*      0x748 - 0x74c      */
  volatile uint32_t type2_compare_9_word_1;       /*      0x74c - 0x750      */
  volatile uint32_t type2_compare_10_word_0;      /*      0x750 - 0x754      */
  volatile uint32_t type2_compare_10_word_1;      /*      0x754 - 0x758      */
  volatile uint32_t type2_compare_11_word_0;      /*      0x758 - 0x75c      */
  volatile uint32_t type2_compare_11_word_1;      /*      0x75c - 0x760      */
  volatile uint32_t type2_compare_12_word_0;      /*      0x760 - 0x764      */
  volatile uint32_t type2_compare_12_word_1;      /*      0x764 - 0x768      */
  volatile uint32_t type2_compare_13_word_0;      /*      0x768 - 0x76c      */
  volatile uint32_t type2_compare_13_word_1;      /*      0x76c - 0x770      */
  volatile uint32_t type2_compare_14_word_0;      /*      0x770 - 0x774      */
  volatile uint32_t type2_compare_14_word_1;      /*      0x774 - 0x778      */
  volatile uint32_t type2_compare_15_word_0;      /*      0x778 - 0x77c      */
  volatile uint32_t type2_compare_15_word_1;      /*      0x77c - 0x780      */
  volatile uint32_t type2_compare_16_word_0;      /*      0x780 - 0x784      */
  volatile uint32_t type2_compare_16_word_1;      /*      0x784 - 0x788      */
  volatile uint32_t type2_compare_17_word_0;      /*      0x788 - 0x78c      */
  volatile uint32_t type2_compare_17_word_1;      /*      0x78c - 0x790      */
  volatile uint32_t type2_compare_18_word_0;      /*      0x790 - 0x794      */
  volatile uint32_t type2_compare_18_word_1;      /*      0x794 - 0x798      */
  volatile uint32_t type2_compare_19_word_0;      /*      0x798 - 0x79c      */
  volatile uint32_t type2_compare_19_word_1;      /*      0x79c - 0x7a0      */
  volatile uint32_t type2_compare_20_word_0;      /*      0x7a0 - 0x7a4      */
  volatile uint32_t type2_compare_20_word_1;      /*      0x7a4 - 0x7a8      */
  volatile uint32_t type2_compare_21_word_0;      /*      0x7a8 - 0x7ac      */
  volatile uint32_t type2_compare_21_word_1;      /*      0x7ac - 0x7b0      */
  volatile uint32_t type2_compare_22_word_0;      /*      0x7b0 - 0x7b4      */
  volatile uint32_t type2_compare_22_word_1;      /*      0x7b4 - 0x7b8      */
  volatile uint32_t type2_compare_23_word_0;      /*      0x7b8 - 0x7bc      */
  volatile uint32_t type2_compare_23_word_1;      /*      0x7bc - 0x7c0      */
  volatile uint32_t type2_compare_24_word_0;      /*      0x7c0 - 0x7c4      */
  volatile uint32_t type2_compare_24_word_1;      /*      0x7c4 - 0x7c8      */
  volatile uint32_t type2_compare_25_word_0;      /*      0x7c8 - 0x7cc      */
  volatile uint32_t type2_compare_25_word_1;      /*      0x7cc - 0x7d0      */
  volatile uint32_t type2_compare_26_word_0;      /*      0x7d0 - 0x7d4      */
  volatile uint32_t type2_compare_26_word_1;      /*      0x7d4 - 0x7d8      */
  volatile uint32_t type2_compare_27_word_0;      /*      0x7d8 - 0x7dc      */
  volatile uint32_t type2_compare_27_word_1;      /*      0x7dc - 0x7e0      */
  volatile uint32_t type2_compare_28_word_0;      /*      0x7e0 - 0x7e4      */
  volatile uint32_t type2_compare_28_word_1;      /*      0x7e4 - 0x7e8      */
  volatile uint32_t type2_compare_29_word_0;      /*      0x7e8 - 0x7ec      */
  volatile uint32_t type2_compare_29_word_1;      /*      0x7ec - 0x7f0      */
  volatile uint32_t type2_compare_30_word_0;      /*      0x7f0 - 0x7f4      */
  volatile uint32_t type2_compare_30_word_1;      /*      0x7f4 - 0x7f8      */
  volatile uint32_t type2_compare_31_word_0;      /*      0x7f8 - 0x7fc      */
  volatile uint32_t type2_compare_31_word_1;      /*      0x7fc - 0x800      */
  volatile uint32_t enst_start_time_q8;           /*      0x800 - 0x804      */
  volatile uint32_t enst_start_time_q9;           /*      0x804 - 0x808      */
  volatile uint32_t enst_start_time_q10;          /*      0x808 - 0x80c      */
  volatile uint32_t enst_start_time_q11;          /*      0x80c - 0x810      */
  volatile uint32_t enst_start_time_q12;          /*      0x810 - 0x814      */
  volatile uint32_t enst_start_time_q13;          /*      0x814 - 0x818      */
  volatile uint32_t enst_start_time_q14;          /*      0x818 - 0x81c      */
  volatile uint32_t enst_start_time_q15;          /*      0x81c - 0x820      */
  volatile uint32_t enst_on_time_q8;              /*      0x820 - 0x824      */
  volatile uint32_t enst_on_time_q9;              /*      0x824 - 0x828      */
  volatile uint32_t enst_on_time_q10;             /*      0x828 - 0x82c      */
  volatile uint32_t enst_on_time_q11;             /*      0x82c - 0x830      */
  volatile uint32_t enst_on_time_q12;             /*      0x830 - 0x834      */
  volatile uint32_t enst_on_time_q13;             /*      0x834 - 0x838      */
  volatile uint32_t enst_on_time_q14;             /*      0x838 - 0x83c      */
  volatile uint32_t enst_on_time_q15;             /*      0x83c - 0x840      */
  volatile uint32_t enst_off_time_q8;             /*      0x840 - 0x844      */
  volatile uint32_t enst_off_time_q9;             /*      0x844 - 0x848      */
  volatile uint32_t enst_off_time_q10;            /*      0x848 - 0x84c      */
  volatile uint32_t enst_off_time_q11;            /*      0x84c - 0x850      */
  volatile uint32_t enst_off_time_q12;            /*      0x850 - 0x854      */
  volatile uint32_t enst_off_time_q13;            /*      0x854 - 0x858      */
  volatile uint32_t enst_off_time_q14;            /*      0x858 - 0x85c      */
  volatile uint32_t enst_off_time_q15;            /*      0x85c - 0x860      */
  volatile char pad__18[0x20];                    /*      0x860 - 0x880      */
  volatile uint32_t enst_control;                 /*      0x880 - 0x884      */
};

/** \} group_ethif_data_structures */

#endif /* __REG_EMAC_REGS__ */

#endif /* __REG_EMAC_REGS_H__ */