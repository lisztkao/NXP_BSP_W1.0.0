// MMFR
#define ENET_MMFR_TA_VALUE                         0x02
#define ENET_MMFR_OP_WRITE                         0x01
#define ENET_MMFR_OP_READ                          0x02
#define ENET_MMFR_ST_VALUE                         0x01

#define ENET_MMFR_ST_MASK                      0xC0000000
#define ENET_MMFR_OP_MASK                      0x30000000
#define ENET_MMFR_PA_MASK                      0x0F800000
#define ENET_MMFR_RA_MASK                      0x007C0000
#define ENET_MMFR_TA_MASK                      0x00030000
#define ENET_MMFR_DATA_MASK                    0x0000FFFF

#define ENET_MMFR_ST_SHIFT                     0x1E
#define ENET_MMFR_OP_SHIFT                     0x1C
#define ENET_MMFR_PA_SHIFT                     0x17
#define ENET_MMFR_RA_SHIFT                     0x12
#define ENET_MMFR_TA_SHIFT                     0x10
#define ENET_MMFR_DATA_SHIFT                   0x00

#define BIT_FIELD_VAL(_bit_field_name,_val_) (((_val_)<<_bit_field_name##_SHIFT) & (_bit_field_name##_MASK))

// MII read/write commands for the external PHY

#define MII_READ_COMMAND(reg)          (BIT_FIELD_VAL(ENET_MMFR_ST, ENET_MMFR_ST_VALUE) |\
                                         BIT_FIELD_VAL(ENET_MMFR_OP, ENET_MMFR_OP_READ) |\
                                         BIT_FIELD_VAL(ENET_MMFR_TA, ENET_MMFR_TA_VALUE) |\
                                         BIT_FIELD_VAL(ENET_MMFR_RA, reg & 0x1F) |\
                                         BIT_FIELD_VAL(ENET_MMFR_DATA, 0x0 & 0xFFFF))

#define MII_WRITE_COMMAND(reg, val)    (BIT_FIELD_VAL(ENET_MMFR_ST, ENET_MMFR_ST_VALUE) |\
                                         BIT_FIELD_VAL(ENET_MMFR_OP, ENET_MMFR_OP_WRITE) |\
                                         BIT_FIELD_VAL(ENET_MMFR_TA, ENET_MMFR_TA_VALUE) |\
                                         BIT_FIELD_VAL(ENET_MMFR_RA, reg & 0x1F) |\
                                         BIT_FIELD_VAL(ENET_MMFR_DATA, val & 0xFFFF))

#define ENET_MII_END                     0

#define MII_REG_C             0x0000  /* Control register offset */
#define MII_REG_S             0x0001  /* Status register offset */
#define MII_REG_PHYID1        0x0002  /* PHY Identifier offset */
#define MII_REG_PHYID2        0x0003  /* PHY Identifier offset */
#define MII_REG_ANA           0x0004  /* Auto-Negotiation advertisement register offset */
#define MII_REG_LPA           0x0005  /* Auto-Negotiation Link Partner ability register offset */
#define MII_REG_ANE           0x0006  /* Auto-Negotiation expansion register offset */
#define MII_REG_ANNPT         0x0007  /* Auto-Negotiation Next Page transmit register offset */
#define MII_REG_ANLPRNP       0x0008  /* Auto-Negotiation Link Partner Received Next Page register offset */
#define MII_REG_BASET_1000_C  0x0009  /* 1000BASE-T Control Registers offset */
#define MII_REG_BASET_1000_S  0x000A  /* 1000BASE-T Status Registers offset */
#define MII_REG_MMD_ACR       0x000D  /* MMD Access Control Register offset */
#define MII_REG_MMD_AADR      0x000E  /* Access Address Data Register offset */
#define MII_REG_ES            0x000F  /* Extended status register offset */

//  Vendor specific PHY registers
#define MII_REG_AR8031_SS                               0x14  // Vendor -- Smart Speed
#define MII_REG_AR8031_DP_ADDR                          0x1D  // Vendor -- Debug Port (Address Offset Set)
#define MII_REG_AR8031_DP_RW                            0x1E  // Vendor -- Debug Port2 (R/W Port)

