#ifndef __DP83848Q_Q1_REG__
#define __DP83848Q_Q1_REG__

/* BMCR */
typedef struct
{
    uint16_t u7RESERVED                  : 7; /* RESERVED: Writes ignored, read as 0. */
    uint16_t u1COLLISION_TEST            : 1; /* 1 = Collision test enabled.
                                                 0 = Normal operation.
                                                 When set, this bit will cause the COL signal to be asserted in response to the assertion
                                                 of TX_EN within 512-bit times. The COL signal will be de-asserted within 4-bit times in
                                                 response to the de-assertion of TX_EN. */
    uint16_t u1DUPLEX_MODE               : 1; /* When auto-negotiation is disabled writing to this bit allows the port Duplex capability to
                                                 be selected.
                                                 1 = Full Duplex operation.
                                                 0 = Half Duplex operation. */
    uint16_t u1RESTART_AUTO_NEGOTIATION  : 1; /* 1 = Restart Auto-Negotiation. Re-initiates the Auto-Negotiation process. If Auto-
                                                 Negotiation is disabled (bit 12 = 0), this bit is ignored. This bit is self-clearing and will
                                                 return a value of 1 until Auto-Negotiation is initiated, whereupon it will self-clear.
                                                 Operation of the Auto-Negotiation process is not affected by the management entity
                                                 clearing this bit.
                                                 0 = Normal operation. */
    uint16_t u1ISOLATE                   : 1; /* 1 = Isolates the Port from the MII with the exception of the serial management.
                                                 0 = Normal operation. */
    uint16_t u1POWER_DOWN                : 1; /* 1 = Power down.
                                                 0 = Normal operation.
                                                 Setting this bit powers down the PHY. Only the register block is enabled during a power
                                                 down condition. */
    uint16_t u1AUTO_NEGOTIATION_ENABLE   : 1; /* Strap controls initial value at reset.
                                                 1 = Auto-Negotiation Enabled - bits 8 and 13 of this register are ignored when this bit is set.
                                                 0 = Auto-Negotiation Disabled - bits 8 and 13 determine the port speed and duplex mode. */
    uint16_t u1SPEED_SELECTION           : 1; /* When auto-negotiation is disabled writing to this bit allows the port speed to be selected.
                                                 1 = 100 Mb/s.
                                                 0 = 10 Mb/s. */
    uint16_t u1LOOPBACK                  : 1; /* 1 = Loopback enabled.
                                                 0 = Normal operation.
                                                 The loopback function enables MII transmit data to be routed to the MII receive data path.
                                                 Setting this bit may cause the descrambler to lose synchronization and produce a 500
                                                 s Ågdead timeÅh before any valid data will appear at the MII receive outputs. */
    uint16_t u1RESET                     : 1; /* 1 = Initiate software Reset / Reset in Process.
                                                 0 = Normal operation.
                                                 This bit, which is self-clearing, returns a value of one until the reset process is complete.
                                                 The configuration is re-strapped. */
} stc_dp83848q_q1_bmcr_t;


typedef union
{
    stc_dp83848q_q1_bmcr_t f;
    uint16_t u16;
} un_dp83848q_q1_bmcr_t;


/* BMSR */
typedef struct
{
    uint16_t u1EXTENDED_CAPABILITY        : 1; /* 1 = Extended register capabilities.
                                                  0 = Basic register set capabilities only. */
    uint16_t u1JABBER_DETECT              : 1; /* This bit only has meaning in 10 Mb/s mode.
                                                  1 = Jabber condition detected.
                                                  0 = No Jabber.
                                                  This bit is implemented with a latching function, such that the occurrence of a jabber
                                                  condition causes it to set until it is cleared by a read to this register by the management
                                                  interface or by a reset. */
    uint16_t u1LINK_STATUS                : 1; /* 1 = Valid link established (for either 10 or 100 Mb/s operation).
                                                  0 = Link not established.
                                                  The criteria for link validity is implementation specific. The occurrence of a link failure
                                                  condition will causes the Link Status bit to clear. Once cleared, this bit may only be set by
                                                  establishing a good link condition and a read via the management interface. */
    uint16_t u1AUTO_NEGOTIATION_ABILITY   : 1; /* 1 = Device is able to perform Auto-Negotiation.
                                                  0 = Device is not able to perform Auto-Negotiation. */
    uint16_t u1REMOTE_FAULT               : 1; /* 1 = Remote Fault condition detected (cleared on read or by reset). Fault criteria:
                                                  Notification from Link Partner of Remote Fault.
                                                  0 = No remote fault condition detected. */
    uint16_t u1AUTO_NEGOTIATION_COMPLETE  : 1; /* 1 = Auto-Negotiation process complete.
                                                  0 = Auto-Negotiation process not complete. */
    uint16_t u1MF_PREAMBLE_SUPPRESSION    : 1; /* 1 = Device able to perform management transaction with preamble suppressed, 32-bits of
                                                  preamble needed only once after reset, invalid opcode or invalid turnaround.
                                                  0 = Normal management operation. */
    uint16_t u4RESERVED                   : 4; /* Write as 0, read as 0. */
    uint16_t u1_10BASE_T_HALF_DUPLEX      : 1; /* Half Duplex Capable:
                                                  1 = Device able to perform 10BASE-T in half duplex mode. */
    uint16_t u1_10BASE_T_FULL_DUPLEX      : 1; /* 10BASE-T Full Duplex Capable:
                                                  1 = Device able to perform 10BASE-T in full duplex mode. */
    uint16_t u1_100BASE_TX_HALF_DUPLEX    : 1; /* 100BASE-TX Half Duplex Capable:
                                                  1 = Device able to perform 100BASE-TX in half duplex mode. */
    uint16_t u1_100BASE_TX_FULL_DUPLEX    : 1; /* 100BASE-TX Full Duplex Capable:
                                                  1 = Device able to perform 100BASE-TX in full duplex mode. */
    uint16_t u1_100BASE_T4                : 1; /* 100BASE-T4 Capable:
                                                  0 = Device not able to perform 100BASE-T4 mode. */
} stc_dp83848q_q1_bmsr_t;


typedef union
{
    stc_dp83848q_q1_bmsr_t f;
    uint16_t u16;
} un_dp83848q_q1_bmsr_t;


/* PHYIDR1 */
typedef struct
{
    uint16_t u16OUI_MSB  : 16; /* Most Significant Bits: Bits 3 to 18 of the OUI (080017h) are stored in bits 15 to 0 of this register. The most significant two bits of the OUI are ignored (the IEEE
                                  standard refers to these as bits 1 and 2). */
} stc_dp83848q_q1_phyidr1_t;


typedef union
{
    stc_dp83848q_q1_phyidr1_t f;
    uint16_t u16;
} un_dp83848q_q1_phyidr1_t;


/* PHYIDR2 */
typedef struct
{
    uint16_t u4MDL_REV   : 4; /* Model Revision Number:
                                 Four bits of the vendor model revision number are mapped from bits 3 to 0 (most
                                 significant bit to bit 3). This field will be incremented for all major device changes. */
    uint16_t u6VNDR_MDL  : 6; /* Vendor Model Number:
                                 The six bits of vendor model number are mapped from bits 9 to 4 (most significant bit to
                                 bit 9).<00 1010> */
    uint16_t u6OUI_LSB   : 6; /* Least Significant Bits:
                                 Bits 19 to 24 of the OUI (080017h) are mapped from bits 15 to 10 of this register
                                 respectively. */
} stc_dp83848q_q1_phyidr2_t;


typedef union
{
    stc_dp83848q_q1_phyidr2_t f;
    uint16_t u16;
} un_dp83848q_q1_phyidr2_t;


/* ANAR */
typedef struct
{
    uint16_t u5SELECTOR   : 5; /* Protocol Selection Bits:
                                  These bits contain the binary encoded protocol selector supported by this port.
                                  <00001> indicates that this device supports IEEE 802.3u. */
    uint16_t u1_10        : 1; /* Support:
                                  1 = 10BASE-T is supported by the local device.
                                  0 = 10BASE-T not supported. */
    uint16_t u1_10_FD     : 1; /* 10BASE-T Full Duplex Support:
                                  1 = 10BASE-T Full Duplex is supported by the local device.
                                  0 = 10BASE-T Full Duplex not supported. */
    uint16_t u1TX         : 1; /* 100BASE-TX Support:
                                  1 = 100BASE-TX is supported by the local device.
                                  0 = 100BASE-TX not supported. */
    uint16_t u1TX_FD      : 1; /* 100BASE-TX Full Duplex Support:
                                  1 = 100BASE-TX Full Duplex is supported by the local device.
                                  0 = 100BASE-TX Full Duplex not supported. */
    uint16_t u1T4         : 1; /* 100BASE-T4 Support:
                                  1= 100BASE-T4 is supported by the local device.
                                  0 = 100BASE-T4 not supported. */
    uint16_t u1PAUSE      : 1; /* PAUSE Support for Full Duplex Links:
                                  The PAUSE bit indicates that the device is capable of providing the symmetric PAUSE
                                  functions as defined in Annex 31B.
                                  Encoding and resolution of PAUSE bits is defined in IEEE 802.3 Annex 28B, Tables
                                  28B-2 and 28B-3, respectively. Pause resolution status is reported in PHYCR[13:12].
                                  1 = Advertise that the DTE (MAC) has implemented both the optional MAC control
                                  sublayer and the pause function as specified in clause 31 and annex 31B of 802.3u.
                                  0= No MAC based full duplex flow control. */
    uint16_t u1ASM_DIR    : 1; /* Asymmetric PAUSE Support for Full Duplex Links:
                                  The ASM_DIR bit indicates that asymmetric PAUSE is supported.
                                  Encoding and resolution of PAUSE bits is defined in IEEE 802.3 Annex 28B, Tables
                                  28B-2 and 28B-3, respectively. Pause resolution status is reported in PHYCR[13:12].
                                  1 = Advertise that the DTE (MAC) has implemented both the optional MAC control
                                  sublayer and the pause function as specified in clause 31 and annex 31B of 802.3u.
                                  0= No MAC based full duplex flow control. */
    uint16_t u1RESERVED1  : 1; /* RESERVED for Future IEEE use: Write as 0, Read as 0 */
    uint16_t u1RF         : 1; /* Remote Fault:
                                  1 = Advertises that this device has detected a Remote Fault.
                                  0 = No Remote Fault detected. */
    uint16_t u1RESERVED0  : 1; /* RESERVED by IEEE: Writes ignored, read as 0. */
    uint16_t u1NP         : 1; /* Next Page Indication:
                                  0 = Next Page Transfer not desired.
                                  1 = Next Page Transfer desired. */
} stc_dp83848q_q1_anar_t;


typedef union
{
    stc_dp83848q_q1_anar_t f;
    uint16_t u16;
} un_dp83848q_q1_anar_t;


/* ANLPAR */
typedef struct
{
    uint16_t u5SELECTOR   : 5; /* Protocol Selection Bits:
                                  Link Partners binary encoded protocol selector. */
    uint16_t u1_10        : 1; /* 10BASE-T Support:
                                  1 = 10BASE-T is supported by the Link Partner.
                                  0 = 10BASE-T not supported by the Link Partner. */
    uint16_t u1_10_FD     : 1; /* 10BASE-T Full Duplex Support:
                                  1 = 10BASE-T Full Duplex is supported by the Link Partner.
                                  0 = 10BASE-T Full Duplex not supported by the Link Partner. */
    uint16_t u1TX         : 1; /* 100BASE-TX Support:
                                  1 = 100BASE-TX is supported by the Link Partner.
                                  0 = 100BASE-TX not supported by the Link Partner. */
    uint16_t u1TX_FD      : 1; /* 100BASE-TX Full Duplex Support:
                                  1 = 100BASE-TX Full Duplex is supported by the Link Partner.
                                  0 = 100BASE-TX Full Duplex not supported by the Link Partner. */
    uint16_t u1T4         : 1; /* 100BASE-T4 Support:
                                  1 = 100BASE-T4 is supported by the Link Partner.
                                  0 = 100BASE-T4 not supported by the Link Partner. */
    uint16_t u1PAUSE      : 1; /* PAUSE:
                                  1 = Pause function is supported by the Link Partner.
                                  0 = Pause function is not supported by the Link Partner. */
    uint16_t u1ASM_DIR    : 1; /* ASYMMETRIC PAUSE:
                                  1 = Asymmetric pause is supported by the Link Partner.
                                  0 = Asymmetric pause is not supported by the Link Partner. */
    uint16_t u1RESERVED0  : 1; /* RESERVED for Future IEEE use:Write as 0, read as 0. */
    uint16_t u1RF         : 1; /* Remote Fault:
                                  1 = Remote Fault indicated by Link Partner.
                                  0 = No Remote Fault indicated by Link Partner. */
    uint16_t u1ACK        : 1; /* Acknowledge:
                                  1 = Link Partner acknowledges reception of the ability data word.
                                  0 = Not acknowledged.
                                  The Auto-Negotiation state machine will automatically control the this bit based on the
                                  incoming FLP bursts. */
    uint16_t u1NP         : 1; /* Next Page Indication:
                                  0 = Link Partner does not desire Next Page Transfer.
                                  1 = Link Partner desires Next Page Transfer. */
} stc_dp83848q_q1_anlpar_t;


typedef union
{
    stc_dp83848q_q1_anlpar_t f;
    uint16_t u16;
} un_dp83848q_q1_anlpar_t;


/* ANLPARNP */
typedef struct
{
    uint16_t u11CODE    : 11; /* This field represents the code field of the next page transmission. If the MP bit is set
                                 (bit 13 of this register), then the code shall be interpreted as a Message Page, as
                                 defined in annex 28C of Clause 28. Otherwise, the code shall be interpreted as an
                                 Unformatted Page, and the interpretation is application specific. */
    uint16_t u1TOGGLE  : 1; /* Toggle:
                               1 = Previous value of the transmitted Link Code word equalled 0.
                               0 = Previous value of the transmitted Link Code word equalled 1. */
    uint16_t u1ACK2    : 1; /* Acknowledge 2:
                               1 = Link Partner does have the ability to comply to next page message.
                               0 = Link Partner does not have the ability to comply to next page message. */
    uint16_t u1MP      : 1; /* Message Page:
                               1 = Message Page.
                               0 = Unformatted Page. */
    uint16_t u1ACK     : 1; /* Acknowledge:
                               1 = Link Partner acknowledges reception of the ability data word.
                               0 = Not acknowledged.
                               The Auto-Negotiation state machine will automatically control the this bit based on the
                               incoming FLP bursts. Software should not attempt to write to this bit. */
    uint16_t u1NP      : 1; /* Next Page Indication:
                               1 = Link Partner desires Next Page Transfer.
                               0 = Link Partner does not desire Next Page Transfer. */
} stc_dp83848q_q1_anlparnp_t;


typedef union
{
    stc_dp83848q_q1_anlparnp_t f;
    uint16_t u16;
} un_dp83848q_q1_anlparnp_t;


/* ANER */
typedef struct
{
    uint16_t u1LP_AN_ABLE  : 1; /* Link Partner Auto-Negotiation Able:
                                   1 = indicates that the Link Partner supports Auto-Negotiation.
                                   0 = indicates that the Link Partner does not support Auto-Negotiation. */
    uint16_t u1PAGE_RX     : 1; /* Link Code Word Page Received:
                                   1 = Link Code Word has been received, cleared on a read.
                                   0 = Link Code Word has not been received. */
    uint16_t u1NP_ABLE     : 1; /* Next Page Able:
                                   1 = Indicates local device is able to send additional Next Pages. */
    uint16_t u1LP_NP_ABLE  : 1; /* Link Partner Next Page Able:
                                   1 = Link Partner does support Next Page.
                                   0 = Link Partner does not support Next Page. */
    uint16_t u1PDF         : 1; /* Parallel Detection Fault:
                                   1 = A fault has been detected via the Parallel Detection function.
                                   0 = A fault has not been detected. */
    uint16_t u11RESERVED    : 11; /* RESERVED: Writes ignored, read as 0. */
} stc_dp83848q_q1_aner_t;


typedef union
{
    stc_dp83848q_q1_aner_t f;
    uint16_t u16;
} un_dp83848q_q1_aner_t;


/* ANNPTR */
typedef struct
{
    uint16_t u11CODE      : 11; /* Code:
                                   This field represents the code field of the next page transmission. If the MP bit is
                                   set (bit 13 of this register), then the code shall be interpreted as a "Message
                                   PageÅh, as defined in annex 28C of IEEE 802.3u. Otherwise, the code shall be
                                   interpreted as an "Unformatted PageÅh, and the interpretation is application
                                   specific.
                                   The default value of the CODE represents a Null Page as defined in Annex 28C
                                   of IEEE 802.3u. */
    uint16_t u1TOG_TX    : 1; /* Toggle:
                                 1 = Value of toggle bit in previously transmitted Link Code Word was 0.
                                 0 = Value of toggle bit in previously transmitted Link Code Word was 1.
                                 Toggle is used by the Arbitration function within Auto-Negotiation to ensure
                                 synchronization with the Link Partner during Next Page exchange. This bit shall
                                 always take the opposite value of the Toggle bit in the previously exchanged Link
                                 Code Word. */
    uint16_t u1ACK2      : 1; /* Acknowledge2:
                                 1 = Will comply with message.
                                 0 = Cannot comply with message.
                                 Acknowledge2 is used by the next page function to indicate that Local Device has
                                 the ability to comply with the message received. */
    uint16_t u1MP        : 1; /* Message Page:
                                 1 = Message Page.
                                 0 = Unformatted Page. */
    uint16_t u1RESERVED  : 1; /* RESERVED: Writes ignored, read as 0. */
    uint16_t u1NP        : 1; /* Next Page Indication:
                                 0 = No other Next Page Transfer desired.
                                 1 = Another Next Page desired. */
} stc_dp83848q_q1_annptr_t;


typedef union
{
    stc_dp83848q_q1_annptr_t f;
    uint16_t u16;
} un_dp83848q_q1_annptr_t;


/* PHYSTS */
typedef struct
{
    uint16_t u1LINK_STATUS                : 1; /* Link Status:
                                                  This bit is a duplicate of the Link Status bit in the BMSR register, except that it
                                                  will not be cleared upon a read of the PHYSTS register.
                                                  1 = Valid link established (for either 10 or 100 Mb/s operation).
                                                  0 = Link not established. */
    uint16_t u1SPEED_STATUS               : 1; /* Speed10:
                                                  This bit indicates the status of the speed and is determined from Auto-
                                                  Negotiation or Forced Modes.
                                                  1 = 10 Mb/s mode.
                                                  0 = 100 Mb/s mode.
                                                  Note: This bit is only valid if Auto-Negotiation is enabled and complete and
                                                  there is a valid link or if Auto-Negotiation is disabled and there is a valid link. */
    uint16_t u1DUPLEX_STATUS              : 1; /* Duplex:
                                                  This bit indicates duplex status and is determined from Auto-Negotiation or
                                                  Forced Modes.
                                                  1 = Full duplex mode.
                                                  0 = Half duplex mode.
                                                  Note: This bit is only valid if Auto-Negotiation is enabled and complete and
                                                  there is a valid link or if Auto-Negotiation is disabled and there is a valid link. */
    uint16_t u1LOOPBACK_STATUS            : 1; /* Loopback:
                                                  1 = Loopback enabled.
                                                  0 = Normal operation. */
    uint16_t u1AUTO_NEG_COMPLETE          : 1; /* Auto-Negotiation Complete:
                                                  1 = Auto-Negotiation complete.
                                                  0 = Auto-Negotiation not complete. */
    uint16_t u1JABBER_DETECT              : 1; /* Jabber Detect: This bit only has meaning in 10 Mb/s mode.
                                                  This bit is a duplicate of the Jabber Detect bit in the BMSR register, except that
                                                  it is not cleared upon a read of the PHYSTS register.
                                                  1 = Jabber condition detected.
                                                  0 = No Jabber. */
    uint16_t u1REMOTE_FAULT               : 1; /* Remote Fault:
                                                  1 = Remote Fault condition detected (cleared on read of BMSR (address 01h)
                                                  register or by reset). Fault criteria: notification from Link Partner of Remote
                                                  Fault via Auto-Negotiation.
                                                  0 = No remote fault condition detected. */
    uint16_t u1RESERVED1                  : 1; /* RESERVED: Writes ignored, read as 0. */
    uint16_t u1PAGE_RECEIVED              : 1; /* Link Code Word Page Received:
                                                  This is a duplicate of the Page Received bit in the ANER register, but this bit
                                                  will not be cleared upon a read of the PHYSTS register.
                                                  1 = A new Link Code Word Page has been received. Cleared on read of the
                                                  ANER (address 06h, bit 1).
                                                  0 = Link Code Word Page has not been received. */
    uint16_t u1DESCRAMBLER_LOCK           : 1; /* 100Base-TX Descrambler Lock from PMD. */
    uint16_t u1SIGNAL_DETECT              : 1; /* 100Base-TX qualified Signal Detect from PMA:
                                                  This is the SD that goes into the link monitor. It is the AND of raw SD and
                                                  descrambler lock, when address 16h, bit 8 (page 0) is set. When this bit is
                                                  cleared, it will be equivalent to the raw SD from the PMD. */
    uint16_t u1FALSE_CARRIER_SENSE_LATCH  : 1; /* False Carrier Sense Latch:
                                                  This bit will be cleared upon a read of the FCSR register.
                                                  1 = False Carrier event has occurred since last read of FCSCR (address 14h).
                                                  0 = No False Carrier event has occurred. */
    uint16_t u1POLARITY_STATUS            : 1; /* Polarity Status:
                                                  This bit is a duplication of bit 4 in the 10BTSCR register. This bit will be cleared
                                                  upon a read of the 10BTSCR register, but not upon a read of the PHYSTS
                                                  register.
                                                  1 = Inverted Polarity detected.
                                                  0 = Correct Polarity detected. */
    uint16_t u1RECEIVE_ERROR_LATCH        : 1; /* Receive Error Latch:
                                                  This bit will be cleared upon a read of the RECR register.
                                                  1 = Receive error event has occurred since last read of RXERCNT (address 15h, Page 0).
                                                  0 = No receive error event has occurred. */
    uint16_t u1MDIX_MODE                  : 1; /* MDIX mode as reported by the Auto-Negotiation logic:
                                                  This bit will be affected by the settings of the MDIX_EN and FORCE_MDIX bits
                                                  in the PHYCR register. When MDIX is enabled, but not forced, this bit will
                                                  update dynamically as the Auto-MDIX algorithm swaps between MDI and MDIX
                                                  configurations.
                                                  1 = MDI pairs swapped (Receive on TPTD pair, Transmit on TPRD pair)
                                                  0 = MDI pairs normal (Receive on TRD pair, Transmit on TPTD pair) */
    uint16_t u1RESERVED                   : 1; /* RESERVED: Writes ignored, read as 0. */
} stc_dp83848q_q1_physts_t;


typedef union
{
    stc_dp83848q_q1_physts_t f;
    uint16_t u16;
} un_dp83848q_q1_physts_t;


/* FCSCR */
typedef struct
{
    uint16_t u8FCSCNT    : 8; /* False Carrier Event Counter:
                                 This 8-bit counter increments on every false carrier event. This counter sticks when
                                 it reaches its max count (FFh). */
    uint16_t u8RESERVED  : 8; /* RESERVED: Writes ignored, read as 0 */
} stc_dp83848q_q1_fcscr_t;


typedef union
{
    stc_dp83848q_q1_fcscr_t f;
    uint16_t u16;
} un_dp83848q_q1_fcscr_t;


/* RECR */
typedef struct
{
    uint16_t u8RXERCNT   : 8; /* RX_ER Counter:
                                 When a valid carrier is present and there is at least one occurrence of an invalid
                                 data symbol, this 8-bit counter increments for each receive error detected. This
                                 event can increment only once per valid carrier event. If a collision is present, the
                                 attribute will not increment. The counter sticks when it reaches its max count.
                                  */
    uint16_t u8RESERVED  : 8; /* RESERVED: Writes ignored, read as 0. */
} stc_dp83848q_q1_recr_t;


typedef union
{
    stc_dp83848q_q1_recr_t f;
    uint16_t u16;
} un_dp83848q_q1_recr_t;


/* PCSR */
typedef struct
{
    uint16_t                 : 2; /* reserved */
    uint16_t u1NRZI_BYPASS   : 1; /* NRZI Bypass Enable:
                                     1 = NRZI Bypass Enabled.
                                     0 = NRZI Bypass Disabled. */
    uint16_t                 : 2; /* reserved */
    uint16_t u1FORCE_100_OK  : 1; /* Force 100 Mb/s Good Link:
                                     1 = Forces 100 Mb/s Good Link.
                                     0 = Normal 100 Mb/s operation. */
    uint16_t                 : 1; /* reserved */
    uint16_t u1DESC_TIME     : 1; /* Descrambler Timeout:
                                     Increase the descrambler timeout. When set this should allow the device to receive
                                     larger packets (>9k bytes) without loss of synchronization.
                                     1 = 2ms.
                                     0 = 722us (per ANSI X3.263: 1995 (TP-PMD) 7.2.3.3e). */
    uint16_t u1SD_OPTION     : 1; /* Signal Detect Option:
                                     1 = Default operation. Link will be asserted following detection of valid signal level
                                     and Descrambler Lock. Link will be maintained as long as signal level is valid. A loss
                                     of Descrambler Lock will not cause Link Status to drop.
                                     0 = Modified signal detect algorithm. Link will be asserted following detection of valid
                                     signal level and Descrambler Lock. Link will be maintained as long as signal level is
                                     valid and Descrambler remains locked. */
    uint16_t u1SD_FORCE_PMA  : 1; /* Signal Detect Force PMA:
                                     1 = Forces Signal Detection in PMA.
                                     0 = Normal SD operation. */
    uint16_t u1TQ_EN         : 1; /* 100Mbs True Quiet Mode Enable:
                                     1 = Transmit True Quiet Mode.
                                     0 = Normal Transmit Mode. */
    uint16_t u1FREE_CLK      : 1; /* Receive Clock */
    uint16_t u4RESERVED0     : 4; /* RESERVED: Writes ignored, read as 0. */
} stc_dp83848q_q1_pcsr_t;


typedef union
{
    stc_dp83848q_q1_pcsr_t f;
    uint16_t u16;
} un_dp83848q_q1_pcsr_t;


/* RBR */
typedef struct
{
    uint16_t u2ELAST_BUF    : 2; /* Elasticity Buffer:
                                    This field controls the Receive Elasticity Buffer which allows for frequency variation
                                    tolerance between the 50 MHz RMII clock and the recovered data. The following
                                    values indicate the tolerance in bits for a single packet. The minimum setting
                                    allows for standard Ethernet frame sizes at +/-50ppm accuracy for both RMII and
                                    Receive clocks. For greater frequency tolerance the packet lengths may be scaled
                                    (i.e. for +/-100ppm, the packet lenths need to be divided by 2).
                                    00 = 14 bit tolerance (up to 16800 byte packets)
                                    01 = 2bit tolerance (up to 2400 byte packets)
                                    10 = 6bit tolerance (up to 7200 byte packets)
                                    11 = 10 bit tolerance (up to 12000 byte packets) */
    uint16_t u1RX_UNF_STS   : 1; /* RX FIFO Under Flow Status:
                                    0 = Normal.
                                    1 = Underflow detected. */
    uint16_t u1RX_OVF_STS   : 1; /* RX FIFO Over Flow Status:
                                    0 = Normal.
                                    1 = Overflow detected. */
    uint16_t u1RMII_REV1_0  : 1; /* Reduced MII Revision 1.0:
                                    0 = (RMII revision 1.2) CRS_DV will toggle at the end of a packet to indicate
                                    deassertion of CRS.
                                    1 = (RMII revision 1.0) CRS_DV will remain asserted until final data is transferred.
                                    CRS_DV will not toggle at the end of a packet. */
    uint16_t u1RMII_MODE    : 1; /* Reduced MII Mode:
                                    0 = Standard MII Mode.
                                    1 = Reduced MII Mode. */
    uint16_t                : 10; /* reserved */
} stc_dp83848q_q1_rbr_t;


typedef union
{
    stc_dp83848q_q1_rbr_t f;
    uint16_t u16;
} un_dp83848q_q1_rbr_t;


/* LEDCR */
typedef struct
{
    uint16_t               : 1; /* reserved */
    uint16_t u1LNKLED      : 1; /* Value to force on LED_LINK output. */
    uint16_t               : 2; /* reserved */
    uint16_t u1DRV_LNKLED  : 1; /* 1 = Drive value of LNKLED bit onto LED_LINK output.
                                   0 = Normal operation. */
    uint16_t               : 11; /* reserved */
} stc_dp83848q_q1_ledcr_t;


typedef union
{
    stc_dp83848q_q1_ledcr_t f;
    uint16_t u16;
} un_dp83848q_q1_ledcr_t;


/* PHYCR */
typedef struct
{
    uint16_t u5PHYADDR      : 5; /* PHY Address: PHY address for port. */
    uint16_t u1LED_CFG      : 1; /* LED Configuration
                                    LED_CFG Mode Description
                                    1 Mode 1
                                    0 Mode 2
                                    In Mode 1, LED is configured as follows:
                                    LED_LINK = ON for Good Link, OFF for No Link
                                    In Mode 2, LED is configured as follows:
                                    LED_LINK = ON for good Link, BLINK for Activity */
    uint16_t                : 1; /* reserved */
    uint16_t u1BP_STRETCH   : 1; /* Bypass LED Stretching:
                                    This will bypass the LED stretching and the LED will reflect the internal
                                    value.
                                    1 = Bypass LED stretching.
                                    0 = Normal operation. */
    uint16_t u1BIST_START   : 1; /* BIST Start:
                                    1 = BIST start.
                                    0 = BIST stop. */
    uint16_t u1BIST_STATUS  : 1; /* BIST Test Status:
                                    1 = BIST pass.
                                    0 = BIST fail. Latched, cleared when BIST is stopped.
                                    For a count number of BIST errors, see the BIST Error Count in the
                                    Table 5-26. */
    uint16_t u1PSR_15       : 1; /* BIST Sequence select:
                                    1 = PSR15 selected.
                                    0 = PSR9 selected. */
    uint16_t u1BIST_FE      : 1; /* BIST Force Error:
                                    1 = Force BIST Error.
                                    0 = Normal operation.
                                    This bit forces a single error, and is self clearing. */
    uint16_t u1PAUSE_TX     : 1; /* Pause Transmit Negotiated:
                                    Indicates that pause transmit should be enabled in the MAC. Based on
                                    ANAR[11:10] and ANLPAR[11:10] settings.
                                    This function shall be enabled according to IEEE 802.3 Annex 28B Table
                                    28B-3, Pause Resolution, only if the Auto-Negotiated Highest Common
                                    Denominator is a full duplex technology. */
    uint16_t u1PAUSE_RX     : 1; /* Pause Receive Negotiated:
                                    Indicates that pause receive should be enabled in the MAC. Based on ANAR[11:10] and ANLPAR[11:10] settings.
                                    This function shall be enabled according to IEEE 802.3 Annex 28B Table
                                    28B-3, ÅgPause ResolutionÅh, only if the Auto-Negotiated Highest Common
                                    Denominator is a full duplex technology.
                                     */
    uint16_t u1FORCE_MDIX   : 1; /* Force MDIX:
                                    1 = Force MDI pairs to cross.
                                    (Receive on TPTD pair, Transmit on TPRD pair)
                                    0 = Normal operation. */
    uint16_t u1MDIX_EN      : 1; /* Auto-MDIX Enable:
                                    1 = Enable Auto-neg Auto-MDIX capability.
                                    0 = Disable Auto-neg Auto-MDIX capability.
                                    The Auto-MDIX algorithm requires that the Auto-Negotiation Enable bit in
                                    the BMCR register to be set. If Auto-Negotiation is not enabled, Auto-
                                    MDIX should be disabled as well. */
} stc_dp83848q_q1_phycr_t;


typedef union
{
    stc_dp83848q_q1_phycr_t f;
    uint16_t u16;
} un_dp83848q_q1_phycr_t;


/* _10BTSCR */
typedef struct
{
    uint16_t u1JABBER_DIS       : 1; /* Jabber Disable:
                                        Applicable only in 10BASE-T.
                                        1 = Jabber function disabled.
                                        0 = Jabber function enabled. */
    uint16_t u1HEARTBEAT_DIS    : 1; /* Heartbeat Disable: This bit only has influence in half-duplex 10Mb mode.
                                        1 = Heartbeat function disabled.
                                        0 = Heartbeat function enabled.
                                        When the device is operating at 100Mb or configured for full duplex
                                        operation, this bit will be ignored - the heartbeat function is disabled. */
    uint16_t                    : 2; /* reserved */
    uint16_t u1POLARITY         : 1; /* 10Mb Polarity Status:
                                        This bit is a duplication of bit 12 in the PHYSTS register. Both bits will be cleared
                                        upon a read of 10BTSCR register, but not upon a read of the PHYSTS register.
                                        1 = Inverted Polarity detected.
                                        0 = Correct Polarity detected. */
    uint16_t                    : 1; /* reserved */
    uint16_t u1FORCE_LINK_10    : 1; /* Force 10Mb Good Link:
                                        1 = Forced Good 10Mb Link.
                                        0 = Normal Link Status. */
    uint16_t u1LP_DIS           : 1; /* Normal Link Pulse Disable:
                                        1 = Transmission of NLPs is disabled.
                                        0 = Transmission of NLPs is enabled. */
    uint16_t u1LOOPBACK_10_DIS  : 1; /* 10Base-T Loopback Disable:
                                        In half-duplex mode, default 10BASE-T operation loops Transmit data to the
                                        Receive data in addition to transmitting the data on the physical medium. This is
                                        for consistency with earlier 10BASE2 and 10BASE5 implementations which used
                                        a shared medium. Setting this bit disables the loopback function.
                                        This bit does not affect loopback due to setting BMCR[14]. */
    uint16_t u3SQUELCH          : 3; /* Squelch Configuration:
                                        Used to set the Squelch ON threshold for the receiver.
                                        Default Squelch ON is 330mV peak. */
    uint16_t                    : 4; /* reserved */
} stc_dp83848q_q1__10btscr_t;


typedef union
{
    stc_dp83848q_q1__10btscr_t f;
    uint16_t u16;
} un_dp83848q_q1__10btscr_t;


/* CDCTRL1 */
typedef struct
{
    uint16_t u2CDPATTSEL         : 2; /* CD Pattern Select[1:0]:
                                         If CDPATTEN_10 = 1:
                                         00 = Data, EOP0 sequence.
                                         01 = Data, EOP1 sequence.
                                         10 = NLPs.
                                         11 = Constant Manchester 1s (10 MHz sine wave) for harmonic distortion testing. */
    uint16_t u1_10MEG_PATT_GAP   : 1; /* Defines gap between data or NLP test sequences:
                                         1 = 15 s.
                                         0 = 10 s. */
    uint16_t                     : 1; /* reserved */
    uint16_t u1CDPATTEN_10       : 1; /* CD Pattern Enable for 10Mb:
                                         1 = Enabled.
                                         0 = Disabled. */
    uint16_t u1BIST_CONT_MODE    : 1; /* Packet BIST Continuous Mode:
                                         Allows continuous pseudo random data transmission without any break
                                         in transmission. This can be used for transmit VOD testing. This is used
                                         in conjunction with the BIST controls in the PHYCR Register (19h). For
                                         10Mb operation, jabber function must be disabled, bit 0 of the 10BTSCR
                                         (1Ah), JABBER_DIS = 1. */
    uint16_t                     : 2; /* reserved */
    uint16_t u8BIST_ERROR_COUNT  : 8; /* BIST ERROR Counter:
                                         Counts number of errored data nibbles during Packet BIST. This value
                                         will reset when Packet BIST is restarted. The counter sticks when it
                                         reaches its max count. */
} stc_dp83848q_q1_cdctrl1_t;


typedef union
{
    stc_dp83848q_q1_cdctrl1_t f;
    uint16_t u16;
} un_dp83848q_q1_cdctrl1_t;


/* EDCR */
typedef struct
{
    uint16_t u4ED_DATA_COUNT  : 4; /* Energy Detect Data Threshold:
                                      Threshold to determine the number of energy detect events that should
                                      cause the device to take actions. Intended to allow averaging of noise
                                      that may be on the line. Counter will reset after approximately 2 seconds
                                      without any energy detect data events. */
    uint16_t u4ED_ERR_COUNT   : 4; /* Energy Detect Error Threshold:
                                      Threshold to determine the number of energy detect error events that
                                      should cause the device to take action. Intended to allow averaging of
                                      noise that may be on the line. Counter will reset after approximately 2
                                      seconds without any energy detect data events. */
    uint16_t u1ED_DATA_MET    : 1; /* Energy Detect Data Threshold Met:
                                      The number of data events that occurred met or surpassed the Energy
                                      Detect Data Threshold. This bit is cleared on a read. */
    uint16_t u1ED_ERR_MET     : 1; /* Energy Detect Error Threshold Met:
                                      No action is automatically taken upon receipt of error events. This bit is
                                      informational only and would be cleared on a read. */
    uint16_t u1ED_PWR_STATE   : 1; /* Energy Detect Power State:
                                      Indicates current Energy Detect Power state. When set, Energy Detect is
                                      in the powered up state. When cleared, Energy Detect is in the powered
                                      down state. This bit is invalid when Energy Detect is not enabled. */
    uint16_t u1ED_BURST_DIS   : 1; /* Energy Detect Burst Disable:
                                      Disable bursting of energy detect data pulses. By default, Energy Detect
                                      (ED) transmits a burst of 4 ED data pulses each time the CD is powered
                                      up. When bursting is disabled, only a single ED data pulse will be send
                                      each time the CD is powered up. */
    uint16_t u1ED_MAN         : 1; /* Energy Detect Manual Power Up/Down:
                                      Begin power up/down sequence when this bit is asserted. When set, the
                                      Energy Detect algorithm will initiate a change of Energy Detect state
                                      regardless of threshold (error or data) and timer values. */
    uint16_t u1ED_AUTO_DOWN   : 1; /* Energy Detect Automatic Power Down:
                                      Automatically begin power down sequence when no energy is detected.
                                      Alternatively, device could be powered down using the ED_MAN bit
                                      (EDCR[12]). */
    uint16_t u1ED_AUTO_UP     : 1; /* Energy Detect Automatic Power Up:
                                      Automatically begin power up sequence when Energy Detect Data
                                      Threshold value (EDCR[3:0]) is reached. Alternatively, device could be
                                      powered up manually using the ED_MAN bit (ECDR[12]). */
    uint16_t u1ED_EN          : 1; /* Energy Detect Enable:
                                      Allow Energy Detect Mode.
                                      When Energy Detect is enabled and Auto-Negotiation is disabled via the
                                      BMCR register, Auto-MDIX should be disabled via the PHYCR register. */
} stc_dp83848q_q1_edcr_t;


typedef union
{
    stc_dp83848q_q1_edcr_t f;
    uint16_t u16;
} un_dp83848q_q1_edcr_t;


typedef enum
{
    DP83848Q_Q1_REG_NORMAL_BMCR       = 0x00, // Basic Mode Control Register  \ref un_dp83848q_q1_bmcr_t
    DP83848Q_Q1_REG_NORMAL_BMSR       = 0x01, // Basic Mode Status Register  \ref un_dp83848q_q1_bmsr_t
    DP83848Q_Q1_REG_NORMAL_PHYIDR1    = 0x02, // PHY Identifier Register #1  \ref un_dp83848q_q1_phyidr1_t
    DP83848Q_Q1_REG_NORMAL_PHYIDR2    = 0x03, // PHY Identifier Register #2  \ref un_dp83848q_q1_phyidr2_t
    DP83848Q_Q1_REG_NORMAL_ANAR       = 0x04, // Auto-Negotiation Advertisement Register  \ref un_dp83848q_q1_anar_t
    DP83848Q_Q1_REG_NORMAL_ANLPAR     = 0x05, // Auto-Negotiation Link Partner Ability Register (Base Page)  \ref un_dp83848q_q1_anlpar_t
    DP83848Q_Q1_REG_NORMAL_ANLPARNP   = 0x05, // Auto-Negotiation Link Partner Ability Register (Next Page)  \ref un_dp83848q_q1_anlparnp_t
    DP83848Q_Q1_REG_NORMAL_ANER       = 0x06, // Auto-Negotiation Expansion Register  \ref un_dp83848q_q1_aner_t
    DP83848Q_Q1_REG_NORMAL_ANNPTR     = 0x07, // Auto-Negotiation Next Page TX  \ref un_dp83848q_q1_annptr_t
    DP83848Q_Q1_REG_EXTENDED_PHYSTS   = 0x10, // PHY Status Register  \ref un_dp83848q_q1_physts_t
    DP83848Q_Q1_REG_EXTENDED_FCSCR    = 0x14, // False Carrier Sense Counter Register  \ref un_dp83848q_q1_fcscr_t
    DP83848Q_Q1_REG_EXTENDED_RECR     = 0x15, // Receive Error Counter Register  \ref un_dp83848q_q1_recr_t
    DP83848Q_Q1_REG_EXTENDED_PCSR     = 0x16, // PCS Sub-Layer Configuration and Status Register  \ref un_dp83848q_q1_pcsr_t
    DP83848Q_Q1_REG_EXTENDED_RBR      = 0x17, // RMII and Bypass Register  \ref un_dp83848q_q1_rbr_t
    DP83848Q_Q1_REG_EXTENDED_LEDCR    = 0x18, // LED Direct Control Register  \ref un_dp83848q_q1_ledcr_t
    DP83848Q_Q1_REG_EXTENDED_PHYCR    = 0x19, // PHY Control Register  \ref un_dp83848q_q1_phycr_t
    DP83848Q_Q1_REG_EXTENDED__10BTSCR = 0x1A, // 10Base-T Status/Control Register  \ref un_dp83848q_q1__10btscr_t
    DP83848Q_Q1_REG_EXTENDED_CDCTRL1  = 0x1B, // CD Test Control Register and BIST Extensions Register  \ref un_dp83848q_q1_cdctrl1_t
    DP83848Q_Q1_REG_EXTENDED_EDCR     = 0x1D, // Energy Detect Control Register  \ref un_dp83848q_q1_edcr_t
} en_dp83848q_q1_reg_info_t;

#endif
