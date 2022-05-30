/*
** ###################################################################
**     Processors:          MIMX8MM6CVTKZ
**                          MIMX8MM6DVTLZ
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    MX8MMRM, Rev.0, 02/2019
**     Version:             rev. 4.0, 2019-02-18
**     Build:               b190228
**
**     Abstract:
**         This header file implements peripheral memory map for MIMX8MM6_ca53
**         processor.
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2019 NXP
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**
** ###################################################################
*/

/*!
 * This header file implements peripheral memory map for MIMX8MQ_ca53 processor.
 */

/*! @name GPR12 - General Purpose Register 12 */
/*! @{ */
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DEVICE_TYPE_MASK (0xF000U)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DEVICE_TYPE_SHIFT (12U)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DEVICE_TYPE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DEVICE_TYPE_SHIFT)) & IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DEVICE_TYPE_MASK)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_STATUS_BUS_SELECT_MASK (0x1E0000U)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_STATUS_BUS_SELECT_SHIFT (17U)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_STATUS_BUS_SELECT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_STATUS_BUS_SELECT_SHIFT)) & IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_STATUS_BUS_SELECT_MASK)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_CTRL_BUS_MASK (0x600000U)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_CTRL_BUS_SHIFT (21U)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_CTRL_BUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_CTRL_BUS_SHIFT)) & IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_CTRL_BUS_MASK)
/*! @} */

/*! @name GPR14 - General Purpose Register 14 */
/*! @{ */
#define IOMUXC_GPR_GPR14_GPR_PCIE1_APP_CLK_PM_EN_MASK   (0x01U << 8)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_APP_CLK_PM_EN_SHIFT  (8U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_REF_USE_PAD_MASK     (0x01U << 9)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_REF_USE_PAD_SHIFT    (9U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_EN_MASK    (0x01U << 10)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_EN_SHIFT   (10U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_MASK       (0x01U << 11)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_SHIFT      (11U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_VREG_BYPASS_MASK     (0x01U << 12)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_VREG_BYPASS_SHIFT    (12U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_TX_VBOOST_LVL_MASK    (0x07U << 13)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_TX_VBOOST_LVL_SHIFT   (13U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_TX_VBOOST_LVL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_TX_VBOOST_LVL_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_TX_VBOOST_LVL_MASK)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_TX0_TERM_OFFSET_MASK  (0x1FU << 16)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_TX0_TERM_OFFSET_SHIFT (16U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_TX0_TERM_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_TX0_TERM_OFFSET_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_TX0_TERM_OFFSET_MASK)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_RX0_EQ_MASK       (0x07U << 21)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_RX0_EQ_SHIFT      (21U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_RX0_EQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_RX0_EQ_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_RX0_EQ_MASK)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_LOS_LEVEL_MASK    (0x1FU << 24)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_LOS_LEVEL_SHIFT   (24U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_LOS_LEVEL(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_LOS_LEVEL_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_LOS_LEVEL_MASK)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_LOS_BIAS_MASK     (0x07U << 29)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_LOS_BIAS_SHIFT    (29U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_LOS_BIAS(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_LOS_BIAS_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_LOS_BIAS_MASK)
/*! @} */

/* ----------------------------------------------------------------------------
   -- PCIE
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCIE_Peripheral PCIE
 * @{
 */

/** PCIE - Peripheral register structure */
typedef struct PCIE_MemMap {
  uint32_t TYPE1_DEV_ID_VEND_ID_REG;               /**< Device ID and Vendor ID Register., offset: 0x0 */
  uint32_t TYPE1_STATUS_COMMAND_REG;               /**< Status and Command Register., offset: 0x4 */
  uint32_t TYPE1_CLASS_CODE_REV_ID_REG;            /**< Class Code and Revision ID Register., offset: 0x8 */
  uint32_t TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG; /**< BIST, Header Type, Latency Timer, and Cache Line Size Register., offset: 0xC */
  uint8_t RESERVED_0[8];
  uint32_t SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG; /**< Secondary Latency Timer, Subordinate Bus Number, Secondary Bus Number, and Primary Bus Number Register., offset: 0x18 */
  uint32_t SEC_STAT_IO_LIMIT_IO_BASE_REG;          /**< Secondary Status, and I/O Limit and Base Register., offset: 0x1C */
  uint32_t MEM_LIMIT_MEM_BASE_REG;                 /**< Memory Limit and Base Register., offset: 0x20 */
  uint32_t PREF_MEM_LIMIT_PREF_MEM_BASE_REG;       /**< Prefetchable Memory Limit and Base Register., offset: 0x24 */
  uint32_t PREF_BASE_UPPER_REG;                    /**< Prefetchable Base Upper 32 Bits Register., offset: 0x28 */
  uint32_t PREF_LIMIT_UPPER_REG;                   /**< Prefetchable Limit Upper 32 Bits Register., offset: 0x2C */
  uint32_t IO_LIMIT_UPPER_IO_BASE_UPPER_REG;       /**< I/O Limit and Base Upper 16 Bits Register., offset: 0x30 */
  uint32_t TYPE1_CAP_PTR_REG;                      /**< Capabilities Pointer Register., offset: 0x34 */
  uint32_t TYPE1_EXP_ROM_BASE_REG;                 /**< Expansion ROM Base Address Register., offset: 0x38 */
  uint32_t BRIDGE_CTRL_INT_PIN_INT_LINE_REG;       /**< Bridge Control, Interrupt Pin, and Interrupt Line Register., offset: 0x3C */
  uint32_t CAP_ID_NXT_PTR_REG;                     /**< Power Management Capabilities Register., offset: 0x40 */
  uint32_t CON_STATUS_REG;                         /**< Power Management Control and Status Register., offset: 0x44 */
  uint8_t RESERVED_1[8];
  uint32_t PCI_MSI_CAP_ID_NEXT_CTRL_REG;           /**< MSI Capability ID, Next Pointer, Capability/Control Registers., offset: 0x50 */
  uint32_t MSI_CAP_OFF_04H_REG;                    /**< MSI Message Lower Address Register., offset: 0x54 */
  uint32_t MSI_CAP_OFF_08H_REG;                    /**< For a 32 bit MSI Message, this register contains Data., offset: 0x58 */
  uint32_t MSI_CAP_OFF_0CH_REG;                    /**< For a 64 bit MSI Message, this register contains Data., offset: 0x5C */
  uint32_t MSI_CAP_OFF_10H_REG;                    /**< Used for MSI when Vector Masking Capable., offset: 0x60 */
  uint32_t MSI_CAP_OFF_14H_REG;                    /**< Used for MSI 64 bit messaging when Vector Masking Capable., offset: 0x64 */
  uint8_t RESERVED_2[8];
  uint32_t PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG; /**< PCI Express Capabilities, ID, Next Pointer Register., offset: 0x70 */
  uint32_t DEVICE_CAPABILITIES_REG;                /**< Device Capabilities Register., offset: 0x74 */
  uint32_t DEVICE_CONTROL_DEVICE_STATUS;           /**< Device Control and Status Register., offset: 0x78 */
  uint32_t LINK_CAPABILITIES_REG;                  /**< Link Capabilities Register., offset: 0x7C */
  uint32_t LINK_CONTROL_LINK_STATUS_REG;           /**< Link Control and Status Register., offset: 0x80 */
  uint32_t SLOT_CAPABILITIES_REG;                  /**< Slot Capabilities Register., offset: 0x84 */
  uint32_t SLOT_CONTROL_SLOT_STATUS;               /**< Slot Control and Status Register., offset: 0x88 */
  uint32_t ROOT_CONTROL_ROOT_CAPABILITIES_REG;     /**< Root Control and Capabilities Register., offset: 0x8C */
  uint32_t ROOT_STATUS_REG;                        /**< Root Status Register., offset: 0x90 */
  uint32_t DEVICE_CAPABILITIES2_REG;               /**< Device Capabilities 2 Register., offset: 0x94 */
  uint32_t DEVICE_CONTROL2_DEVICE_STATUS2_REG;     /**< Device Control 2 and Status 2 Register., offset: 0x98 */
  uint32_t LINK_CAPABILITIES2_REG;                 /**< Link Capabilities 2 Register., offset: 0x9C */
  uint32_t LINK_CONTROL2_LINK_STATUS2_REG;         /**< Link Control 2 and Status 2 Register., offset: 0xA0 */
  uint8_t RESERVED_3[92];
  uint32_t AER_EXT_CAP_HDR_OFF;                    /**< Advanced Error Reporting Extended Capability Header., offset: 0x100 */
  uint32_t UNCORR_ERR_STATUS_OFF;                  /**< Uncorrectable Error Status Register., offset: 0x104 */
  uint32_t UNCORR_ERR_MASK_OFF;                    /**< Uncorrectable Error Mask Register., offset: 0x108 */
  uint32_t UNCORR_ERR_SEV_OFF;                     /**< Uncorrectable Error Severity Register., offset: 0x10C */
  uint32_t CORR_ERR_STATUS_OFF;                    /**< Correctable Error Status Register., offset: 0x110 */
  uint32_t CORR_ERR_MASK_OFF;                      /**< Correctable Error Mask Register., offset: 0x114 */
  uint32_t ADV_ERR_CAP_CTRL_OFF;                   /**< Advanced Error Capabilities and Control Register., offset: 0x118 */
  uint32_t HDR_LOG_0_OFF;                          /**< Header Log Register 0., offset: 0x11C */
  uint32_t HDR_LOG_1_OFF;                          /**< Header Log Register 1., offset: 0x120 */
  uint32_t HDR_LOG_2_OFF;                          /**< Header Log Register 2., offset: 0x124 */
  uint32_t HDR_LOG_3_OFF;                          /**< Header Log Register 3., offset: 0x128 */
  uint32_t ROOT_ERR_CMD_OFF;                       /**< Root Error Command Register., offset: 0x12C */
  uint32_t ROOT_ERR_STATUS_OFF;                    /**< Root Error Status Register., offset: 0x130 */
  uint32_t ERR_SRC_ID_OFF;                         /**< Error Source Identification Register., offset: 0x134 */
  uint32_t TLP_PREFIX_LOG_1_OFF;                   /**< TLP Prefix Log Register 1., offset: 0x138 */
  uint32_t TLP_PREFIX_LOG_2_OFF;                   /**< TLP Prefix Log Register 2., offset: 0x13C */
  uint32_t TLP_PREFIX_LOG_3_OFF;                   /**< TLP Prefix Log Register 3., offset: 0x140 */
  uint32_t TLP_PREFIX_LOG_4_OFF;                   /**< TLP Prefix Log Register 4., offset: 0x144 */
  uint32_t L1SUB_CAP_HEADER_REG;                   /**< L1 Substates Extended Capability Header., offset: 0x148 */
  uint32_t L1SUB_CAPABILITY_REG;                   /**< L1 Substates Capability Register., offset: 0x14C */
  uint32_t L1SUB_CONTROL1_REG;                     /**< L1 Substates Control 1 Register., offset: 0x150 */
  uint32_t L1SUB_CONTROL2_REG;                     /**< L1 Substates Control 2 Register., offset: 0x154 */
  uint8_t RESERVED_4[1448];
  uint32_t ACK_LATENCY_TIMER_OFF;                  /**< Ack Latency Timer and Replay Timer Register., offset: 0x700 */
  uint32_t VENDOR_SPEC_DLLP_OFF;                   /**< Vendor Specific DLLP Register., offset: 0x704 */
  uint32_t PORT_FORCE_OFF;                         /**< Port Force Link Register., offset: 0x708 */
  uint32_t ACK_F_ASPM_CTRL_OFF;                    /**< Ack Frequency and L0-L1 ASPM Control Register., offset: 0x70C */
  uint32_t PORT_LINK_CTRL_OFF;                     /**< Port Link Control Register., offset: 0x710 */
  uint32_t LANE_SKEW_OFF;                          /**< Lane Skew Register., offset: 0x714 */
  uint32_t TIMER_CTRL_MAX_FUNC_NUM_OFF;            /**< Timer Control and Max Function Number Register., offset: 0x718 */
  uint32_t SYMBOL_TIMER_FILTER_1_OFF;              /**< Symbol Timer Register and Filter Mask 1 Register., offset: 0x71C */
  uint32_t FILTER_MASK_2_OFF;                      /**< Filter Mask 2 Register., offset: 0x720 */
  uint32_t AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF; /**< AMBA Multiple Outbound Decomposed NP SubRequests Control Register., offset: 0x724 */
  uint32_t PL_DEBUG0_OFF;                          /**< Debug Register 0, offset: 0x728 */
  uint32_t PL_DEBUG1_OFF;                          /**< Debug Register 1, offset: 0x72C */
  uint32_t TX_P_FC_CREDIT_STATUS_OFF;              /**< Transmit Posted FC Credit Status, offset: 0x730 */
  uint32_t TX_NP_FC_CREDIT_STATUS_OFF;             /**< Transmit Non-Posted FC Credit Status, offset: 0x734 */
  uint32_t TX_CPL_FC_CREDIT_STATUS_OFF;            /**< Transmit Completion FC Credit Status, offset: 0x738 */
  uint32_t QUEUE_STATUS_OFF;                       /**< Queue Status, offset: 0x73C */
  uint32_t VC_TX_ARBI_1_OFF;                       /**< VC Transmit Arbitration Register 1, offset: 0x740 */
  uint32_t VC_TX_ARBI_2_OFF;                       /**< VC Transmit Arbitration Register 2, offset: 0x744 */
  uint32_t VC0_P_RX_Q_CTRL_OFF;                    /**< Segmented-Buffer VC0 Posted Receive Queue Control., offset: 0x748 */
  uint32_t VC0_NP_RX_Q_CTRL_OFF;                   /**< Segmented-Buffer VC0 Non-Posted Receive Queue Control., offset: 0x74C */
  uint32_t VC0_CPL_RX_Q_CTRL_OFF;                  /**< Segmented-Buffer VC0 Completion Receive Queue Control., offset: 0x750 */
  uint8_t RESERVED_5[184];
  uint32_t GEN2_CTRL_OFF;                          /**< Link Width and Speed Change Control Register., offset: 0x80C */
  uint32_t PHY_STATUS_OFF;                         /**< PHY Status Register., offset: 0x810 */
  uint32_t PHY_CONTROL_OFF;                        /**< PHY Control Register., offset: 0x814 */
  uint8_t RESERVED_6[4];
  uint32_t TRGT_MAP_CTRL_OFF;                      /**< Programmable Target Map Control Register., offset: 0x81C */
  uint32_t MSI_CTRL_ADDR_OFF;                      /**< Integrated MSI Reception Module (iMRM) Address Register., offset: 0x820 */
  uint32_t MSI_CTRL_UPPER_ADDR_OFF;                /**< Integrated MSI Reception Module Upper Address Register., offset: 0x824 */
  uint32_t MSI_CTRL_INT_0_EN_OFF;                  /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x828 */
  uint32_t MSI_CTRL_INT_0_MASK_OFF;                /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x82C */
  uint32_t MSI_CTRL_INT_0_STATUS_OFF;              /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x830 */
  uint32_t MSI_CTRL_INT_1_EN_OFF;                  /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x834 */
  uint32_t MSI_CTRL_INT_1_MASK_OFF;                /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x838 */
  uint32_t MSI_CTRL_INT_1_STATUS_OFF;              /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x83C */
  uint32_t MSI_CTRL_INT_2_EN_OFF;                  /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x840 */
  uint32_t MSI_CTRL_INT_2_MASK_OFF;                /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x844 */
  uint32_t MSI_CTRL_INT_2_STATUS_OFF;              /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x848 */
  uint32_t MSI_CTRL_INT_3_EN_OFF;                  /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x84C */
  uint32_t MSI_CTRL_INT_3_MASK_OFF;                /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x850 */
  uint32_t MSI_CTRL_INT_3_STATUS_OFF;              /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x854 */
  uint32_t MSI_CTRL_INT_4_EN_OFF;                  /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x858 */
  uint32_t MSI_CTRL_INT_4_MASK_OFF;                /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x85C */
  uint32_t MSI_CTRL_INT_4_STATUS_OFF;              /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x860 */
  uint32_t MSI_CTRL_INT_5_EN_OFF;                  /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x864 */
  uint32_t MSI_CTRL_INT_5_MASK_OFF;                /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x868 */
  uint32_t MSI_CTRL_INT_5_STATUS_OFF;              /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x86C */
  uint32_t MSI_CTRL_INT_6_EN_OFF;                  /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x870 */
  uint32_t MSI_CTRL_INT_6_MASK_OFF;                /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x874 */
  uint32_t MSI_CTRL_INT_6_STATUS_OFF;              /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x878 */
  uint32_t MSI_CTRL_INT_7_EN_OFF;                  /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x87C */
  uint32_t MSI_CTRL_INT_7_MASK_OFF;                /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x880 */
  uint32_t MSI_CTRL_INT_7_STATUS_OFF;              /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x884 */
  uint32_t MSI_GPIO_IO_OFF;                        /**< Integrated MSI Reception Module General Purpose IO Register., offset: 0x888 */
  uint32_t CLOCK_GATING_CTRL_OFF;                  /**< RADM clock gating enable control register., offset: 0x88C */
  uint8_t RESERVED_7[36];
  uint32_t ORDER_RULE_CTRL_OFF;                    /**< Order Rule Control Register., offset: 0x8B4 */
  uint32_t PIPE_LOOPBACK_CONTROL_OFF;              /**< PIPE Loopback Control Register., offset: 0x8B8 */
  uint32_t MISC_CONTROL_1_OFF;                     /**< DBI Read-Only Write Enable Register., offset: 0x8BC */
  uint32_t MULTI_LANE_CONTROL_OFF;                 /**< UpConfigure Multi-lane Control Register., offset: 0x8C0 */
  uint32_t PHY_INTEROP_CTRL_OFF;                   /**< PHY Interoperability Control Register., offset: 0x8C4 */
  uint32_t TRGT_CPL_LUT_DELETE_ENTRY_OFF;          /**< TRGT_CPL_LUT Delete Entry Control register., offset: 0x8C8 */
  uint32_t LINK_FLUSH_CONTROL_OFF;                 /**< Link Reset Request Flush Control Register., offset: 0x8CC */
  uint32_t AMBA_ERROR_RESPONSE_DEFAULT_OFF;        /**< AXI Bridge Slave Error Response Register., offset: 0x8D0 */
  uint32_t AMBA_LINK_TIMEOUT_OFF;                  /**< Link Down AXI Bridge Slave Timeout Register., offset: 0x8D4 */
  uint32_t AMBA_ORDERING_CTRL_OFF;                 /**< AMBA Ordering Control., offset: 0x8D8 */
  uint8_t RESERVED_8[4];
  uint32_t COHERENCY_CONTROL_1_OFF;                /**< ACE Cache Coherency Control Register 1, offset: 0x8E0 */
  uint32_t COHERENCY_CONTROL_2_OFF;                /**< ACE Cache Coherency Control Register 2, offset: 0x8E4 */
  uint32_t COHERENCY_CONTROL_3_OFF;                /**< ACE Cache Coherency Control Register 3, offset: 0x8E8 */
  uint8_t RESERVED_9[4];
  uint32_t AXI_MSTR_MSG_ADDR_LOW_OFF;              /**< Lower 20 bits of the programmable AXI address where Messages coming from wire are mapped to., offset: 0x8F0 */
  uint32_t AXI_MSTR_MSG_ADDR_HIGH_OFF;             /**< Upper 32 bits of the programmable AXI address where Messages coming from wire are mapped to., offset: 0x8F4 */
  uint32_t PCIE_VERSION_NUMBER_OFF;                /**< PCIe Controller IIP Release Version Number., offset: 0x8F8 */
  uint32_t PCIE_VERSION_TYPE_OFF;                  /**< PCIe Controller IIP Release Version Type., offset: 0x8FC */
  uint8_t RESERVED_10[576];
  uint32_t AUX_CLK_FREQ_OFF;                       /**< Auxiliary Clock Frequency Control Register., offset: 0xB40 */
  uint32_t L1_SUBSTATES_OFF;                       /**< L1 Substates Timing Register., offset: 0xB44 */
  uint8_t RESERVED_11[3142840];
  uint32_t IATU_REGION_CTRL_1_OFF_OUTBOUND_0;      /**< iATU Region Control 1 Register., offset: 0x300000 */
  uint32_t IATU_REGION_CTRL_2_OFF_OUTBOUND_0;      /**< iATU Region Control 2 Register., offset: 0x300004 */
  uint32_t IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0;      /**< iATU Lower Base Address Register., offset: 0x300008 */
  uint32_t IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0;    /**< iATU Upper Base Address Register., offset: 0x30000C */
  uint32_t IATU_LIMIT_ADDR_OFF_OUTBOUND_0;         /**< iATU Limit Address Register., offset: 0x300010 */
  uint32_t IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0;    /**< iATU Lower Target Address Register., offset: 0x300014 */
  uint32_t IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0;  /**< iATU Upper Target Address Register., offset: 0x300018 */
  uint8_t RESERVED_12[228];
  uint32_t IATU_REGION_CTRL_1_OFF_INBOUND_0;       /**< iATU Region Control 1 Register., offset: 0x300100 */
  uint32_t IATU_REGION_CTRL_2_OFF_INBOUND_0;       /**< iATU Region Control 2 Register., offset: 0x300104 */
  uint32_t IATU_LWR_BASE_ADDR_OFF_INBOUND_0;       /**< iATU Lower Base Address Register., offset: 0x300108 */
  uint32_t IATU_UPPER_BASE_ADDR_OFF_INBOUND_0;     /**< iATU Upper Base Address Register., offset: 0x30010C */
  uint32_t IATU_LIMIT_ADDR_OFF_INBOUND_0;          /**< iATU Limit Address Register., offset: 0x300110 */
  uint32_t IATU_LWR_TARGET_ADDR_OFF_INBOUND_0;     /**< iATU Lower Target Address Register., offset: 0x300114 */
  uint8_t RESERVED_13[232];
  uint32_t IATU_REGION_CTRL_1_OFF_OUTBOUND_1;      /**< iATU Region Control 1 Register., offset: 0x300200 */
  uint32_t IATU_REGION_CTRL_2_OFF_OUTBOUND_1;      /**< iATU Region Control 2 Register., offset: 0x300204 */
  uint32_t IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1;      /**< iATU Lower Base Address Register., offset: 0x300208 */
  uint32_t IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1;    /**< iATU Upper Base Address Register., offset: 0x30020C */
  uint32_t IATU_LIMIT_ADDR_OFF_OUTBOUND_1;         /**< iATU Limit Address Register., offset: 0x300210 */
  uint32_t IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1;    /**< iATU Lower Target Address Register., offset: 0x300214 */
  uint32_t IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1;  /**< iATU Upper Target Address Register., offset: 0x300218 */
  uint8_t RESERVED_14[228];
  uint32_t IATU_REGION_CTRL_1_OFF_INBOUND_1;       /**< iATU Region Control 1 Register., offset: 0x300300 */
  uint32_t IATU_REGION_CTRL_2_OFF_INBOUND_1;       /**< iATU Region Control 2 Register., offset: 0x300304 */
  uint32_t IATU_LWR_BASE_ADDR_OFF_INBOUND_1;       /**< iATU Lower Base Address Register., offset: 0x300308 */
  uint32_t IATU_UPPER_BASE_ADDR_OFF_INBOUND_1;     /**< iATU Upper Base Address Register., offset: 0x30030C */
  uint32_t IATU_LIMIT_ADDR_OFF_INBOUND_1;          /**< iATU Limit Address Register., offset: 0x300310 */
  uint32_t IATU_LWR_TARGET_ADDR_OFF_INBOUND_1;     /**< iATU Lower Target Address Register., offset: 0x300314 */
  uint8_t RESERVED_15[232];
  uint32_t IATU_REGION_CTRL_1_OFF_OUTBOUND_2;      /**< iATU Region Control 1 Register., offset: 0x300400 */
  uint32_t IATU_REGION_CTRL_2_OFF_OUTBOUND_2;      /**< iATU Region Control 2 Register., offset: 0x300404 */
  uint32_t IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2;      /**< iATU Lower Base Address Register., offset: 0x300408 */
  uint32_t IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2;    /**< iATU Upper Base Address Register., offset: 0x30040C */
  uint32_t IATU_LIMIT_ADDR_OFF_OUTBOUND_2;         /**< iATU Limit Address Register., offset: 0x300410 */
  uint32_t IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2;    /**< iATU Lower Target Address Register., offset: 0x300414 */
  uint32_t IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2;  /**< iATU Upper Target Address Register., offset: 0x300418 */
  uint8_t RESERVED_16[228];
  uint32_t IATU_REGION_CTRL_1_OFF_INBOUND_2;       /**< iATU Region Control 1 Register., offset: 0x300500 */
  uint32_t IATU_REGION_CTRL_2_OFF_INBOUND_2;       /**< iATU Region Control 2 Register., offset: 0x300504 */
  uint32_t IATU_LWR_BASE_ADDR_OFF_INBOUND_2;       /**< iATU Lower Base Address Register., offset: 0x300508 */
  uint32_t IATU_UPPER_BASE_ADDR_OFF_INBOUND_2;     /**< iATU Upper Base Address Register., offset: 0x30050C */
  uint32_t IATU_LIMIT_ADDR_OFF_INBOUND_2;          /**< iATU Limit Address Register., offset: 0x300510 */
  uint32_t IATU_LWR_TARGET_ADDR_OFF_INBOUND_2;     /**< iATU Lower Target Address Register., offset: 0x300514 */
  uint8_t RESERVED_17[232];
  uint32_t IATU_REGION_CTRL_1_OFF_OUTBOUND_3;      /**< iATU Region Control 1 Register., offset: 0x300600 */
  uint32_t IATU_REGION_CTRL_2_OFF_OUTBOUND_3;      /**< iATU Region Control 2 Register., offset: 0x300604 */
  uint32_t IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3;      /**< iATU Lower Base Address Register., offset: 0x300608 */
  uint32_t IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3;    /**< iATU Upper Base Address Register., offset: 0x30060C */
  uint32_t IATU_LIMIT_ADDR_OFF_OUTBOUND_3;         /**< iATU Limit Address Register., offset: 0x300610 */
  uint32_t IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3;    /**< iATU Lower Target Address Register., offset: 0x300614 */
  uint32_t IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3;  /**< iATU Upper Target Address Register., offset: 0x300618 */
  uint8_t RESERVED_18[228];
  uint32_t IATU_REGION_CTRL_1_OFF_INBOUND_3;       /**< iATU Region Control 1 Register., offset: 0x300700 */
  uint32_t IATU_REGION_CTRL_2_OFF_INBOUND_3;       /**< iATU Region Control 2 Register., offset: 0x300704 */
  uint32_t IATU_LWR_BASE_ADDR_OFF_INBOUND_3;       /**< iATU Lower Base Address Register., offset: 0x300708 */
  uint32_t IATU_UPPER_BASE_ADDR_OFF_INBOUND_3;     /**< iATU Upper Base Address Register., offset: 0x30070C */
  uint32_t IATU_LIMIT_ADDR_OFF_INBOUND_3;          /**< iATU Limit Address Register., offset: 0x300710 */
  uint32_t IATU_LWR_TARGET_ADDR_OFF_INBOUND_3;     /**< iATU Lower Target Address Register., offset: 0x300714 */
  uint8_t RESERVED_19[522472];
  uint32_t DMA_CTRL_DATA_ARB_PRIOR_OFF;            /**< DMA Arbitration Scheme for TRGT1 Interface., offset: 0x380000 */
  uint8_t RESERVED_20[4];
  uint32_t DMA_CTRL_OFF;                           /**< DMA Number of Channels Register., offset: 0x380008 */
  uint32_t DMA_WRITE_ENGINE_EN_OFF;                /**< DMA Write Engine Enable Register., offset: 0x38000C */
  uint32_t DMA_WRITE_DOORBELL_OFF;                 /**< DMA Write Doorbell Register., offset: 0x380010 */
  uint8_t RESERVED_21[4];
  uint32_t DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF;   /**< DMA Write Engine Channel Arbitration Weight Low Register., offset: 0x380018 */
  uint32_t DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF;  /**< DMA Write Engine Channel Arbitration Weight High Register., offset: 0x38001C */
  uint8_t RESERVED_22[12];
  uint32_t DMA_READ_ENGINE_EN_OFF;                 /**< DMA Read Engine Enable Register., offset: 0x38002C */
  uint32_t DMA_READ_DOORBELL_OFF;                  /**< DMA Read Doorbell Register., offset: 0x380030 */
  uint8_t RESERVED_23[4];
  uint32_t DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF;    /**< DMA Read Engine Channel Arbitration Weight Low Register., offset: 0x380038 */
  uint32_t DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF;   /**< DMA Read Engine Channel Arbitration Weight High Register., offset: 0x38003C */
  uint8_t RESERVED_24[12];
  uint32_t DMA_WRITE_INT_STATUS_OFF;               /**< DMA Write Interrupt Status Register., offset: 0x38004C */
  uint8_t RESERVED_25[4];
  uint32_t DMA_WRITE_INT_MASK_OFF;                 /**< DMA Write Interrupt Mask Register., offset: 0x380054 */
  uint32_t DMA_WRITE_INT_CLEAR_OFF;                /**< DMA Write Interrupt Clear Register., offset: 0x380058 */
  uint32_t DMA_WRITE_ERR_STATUS_OFF;               /**< DMA Write Error Status Register, offset: 0x38005C */
  uint32_t DMA_WRITE_DONE_IMWR_LOW_OFF;            /**< DMA Write Done IMWr Address Low Register., offset: 0x380060 */
  uint32_t DMA_WRITE_DONE_IMWR_HIGH_OFF;           /**< DMA Write Done IMWr Interrupt Address High Register., offset: 0x380064 */
  uint32_t DMA_WRITE_ABORT_IMWR_LOW_OFF;           /**< DMA Write Abort IMWr Address Low Register., offset: 0x380068 */
  uint32_t DMA_WRITE_ABORT_IMWR_HIGH_OFF;          /**< DMA Write Abort IMWr Address High Register., offset: 0x38006C */
  uint32_t DMA_WRITE_CH01_IMWR_DATA_OFF;           /**< DMA Write Channel 1 and 0 IMWr Data Register., offset: 0x380070 */
  uint32_t DMA_WRITE_CH23_IMWR_DATA_OFF;           /**< DMA Write Channel 3 and 2 IMWr Data Register., offset: 0x380074 */
  uint32_t DMA_WRITE_CH45_IMWR_DATA_OFF;           /**< DMA Write Channel 5 and 4 IMWr Data Register., offset: 0x380078 */
  uint32_t DMA_WRITE_CH67_IMWR_DATA_OFF;           /**< DMA Write Channel 7 and 6 IMWr Data Register., offset: 0x38007C */
  uint8_t RESERVED_26[16];
  uint32_t DMA_WRITE_LINKED_LIST_ERR_EN_OFF;       /**< DMA Write Linked List Error Enable Register., offset: 0x380090 */
  uint8_t RESERVED_27[12];
  uint32_t DMA_READ_INT_STATUS_OFF;                /**< DMA Read Interrupt Status Register., offset: 0x3800A0 */
  uint8_t RESERVED_28[4];
  uint32_t DMA_READ_INT_MASK_OFF;                  /**< DMA Read Interrupt Mask Register., offset: 0x3800A8 */
  uint32_t DMA_READ_INT_CLEAR_OFF;                 /**< DMA Read Interrupt Clear Register., offset: 0x3800AC */
  uint8_t RESERVED_29[4];
  uint32_t DMA_READ_ERR_STATUS_LOW_OFF;            /**< DMA Read Error Status Low Register., offset: 0x3800B4 */
  uint32_t DMA_READ_ERR_STATUS_HIGH_OFF;           /**< DMA Read Error Status High Register., offset: 0x3800B8 */
  uint8_t RESERVED_30[8];
  uint32_t DMA_READ_LINKED_LIST_ERR_EN_OFF;        /**< DMA Read Linked List Error Enable Register., offset: 0x3800C4 */
  uint8_t RESERVED_31[4];
  uint32_t DMA_READ_DONE_IMWR_LOW_OFF;             /**< DMA Read Done IMWr Address Low Register., offset: 0x3800CC */
  uint32_t DMA_READ_DONE_IMWR_HIGH_OFF;            /**< DMA Read Done IMWr Address High Register., offset: 0x3800D0 */
  uint32_t DMA_READ_ABORT_IMWR_LOW_OFF;            /**< DMA Read Abort IMWr Address Low Register., offset: 0x3800D4 */
  uint32_t DMA_READ_ABORT_IMWR_HIGH_OFF;           /**< DMA Read Abort IMWr Address High Register., offset: 0x3800D8 */
  uint32_t DMA_READ_CH01_IMWR_DATA_OFF;            /**< DMA Read Channel 1 and 0 IMWr Data Register., offset: 0x3800DC */
  uint32_t DMA_READ_CH23_IMWR_DATA_OFF;            /**< DMA Read Channel 3 and 2 IMWr Data Register., offset: 0x3800E0 */
  uint32_t DMA_READ_CH45_IMWR_DATA_OFF;            /**< DMA Read Channel 5 and 4 IMWr Data Register., offset: 0x3800E4 */
  uint32_t DMA_READ_CH67_IMWR_DATA_OFF;            /**< DMA Read Channel 7 and 6 IMWr Data Register., offset: 0x3800E8 */
  uint8_t RESERVED_32[276];
  uint32_t DMA_CH_CONTROL1_OFF_WRCH_0;             /**< DMA Write Channel Control 1 Register., offset: 0x380200 */
  uint8_t RESERVED_33[4];
  uint32_t DMA_TRANSFER_SIZE_OFF_WRCH_0;           /**< DMA Write Transfer Size Register., offset: 0x380208 */
  uint32_t DMA_SAR_LOW_OFF_WRCH_0;                 /**< DMA Write SAR Low Register., offset: 0x38020C */
  uint32_t DMA_SAR_HIGH_OFF_WRCH_0;                /**< DMA Write SAR High Register., offset: 0x380210 */
  uint32_t DMA_DAR_LOW_OFF_WRCH_0;                 /**< DMA Write DAR Low Register., offset: 0x380214 */
  uint32_t DMA_DAR_HIGH_OFF_WRCH_0;                /**< DMA Write DAR High Register., offset: 0x380218 */
  uint32_t DMA_LLP_LOW_OFF_WRCH_0;                 /**< DMA Write Linked List Pointer Low Register., offset: 0x38021C */
  uint32_t DMA_LLP_HIGH_OFF_WRCH_0;                /**< DMA Write Linked List Pointer High Register., offset: 0x380220 */
  uint8_t RESERVED_34[220];
  uint32_t DMA_CH_CONTROL1_OFF_RDCH_0;             /**< DMA Read Channel Control 1 Register., offset: 0x380300 */
  uint8_t RESERVED_35[4];
  uint32_t DMA_TRANSFER_SIZE_OFF_RDCH_0;           /**< DMA Read Transfer Size Register., offset: 0x380308 */
  uint32_t DMA_SAR_LOW_OFF_RDCH_0;                 /**< DMA Read SAR Low Register., offset: 0x38030C */
  uint32_t DMA_SAR_HIGH_OFF_RDCH_0;                /**< DMA Read SAR High Register., offset: 0x380310 */
  uint32_t DMA_DAR_LOW_OFF_RDCH_0;                 /**< DMA Read DAR Low Register., offset: 0x380314 */
  uint32_t DMA_DAR_HIGH_OFF_RDCH_0;                /**< DMA Read DAR High Register., offset: 0x380318 */
  uint32_t DMA_LLP_LOW_OFF_RDCH_0;                 /**< DMA Read Linked List Pointer Low Register., offset: 0x38031C */
  uint32_t DMA_LLP_HIGH_OFF_RDCH_0;                /**< DMA Read Linked List Pointer High Register., offset: 0x380320 */
} volatile *PCIE_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PCIE - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCIE_Register_Accessor_Macros PCIE - Register accessor macros
 * @{
 */


/* PCIE - Register accessors */
#define PCIE_TYPE1_DEV_ID_VEND_ID_REG_REG(base)  ((base)->TYPE1_DEV_ID_VEND_ID_REG)
#define PCIE_TYPE1_STATUS_COMMAND_REG_REG(base)  ((base)->TYPE1_STATUS_COMMAND_REG)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_REG(base) ((base)->TYPE1_CLASS_CODE_REV_ID_REG)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_REG(base) ((base)->TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_REG(base) ((base)->SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_REG(base) ((base)->SEC_STAT_IO_LIMIT_IO_BASE_REG)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_REG(base)    ((base)->MEM_LIMIT_MEM_BASE_REG)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_REG(base) ((base)->PREF_MEM_LIMIT_PREF_MEM_BASE_REG)
#define PCIE_PREF_BASE_UPPER_REG_REG(base)       ((base)->PREF_BASE_UPPER_REG)
#define PCIE_PREF_LIMIT_UPPER_REG_REG(base)      ((base)->PREF_LIMIT_UPPER_REG)
#define PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_REG(base) ((base)->IO_LIMIT_UPPER_IO_BASE_UPPER_REG)
#define PCIE_TYPE1_CAP_PTR_REG_REG(base)         ((base)->TYPE1_CAP_PTR_REG)
#define PCIE_TYPE1_EXP_ROM_BASE_REG_REG(base)    ((base)->TYPE1_EXP_ROM_BASE_REG)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_REG(base) ((base)->BRIDGE_CTRL_INT_PIN_INT_LINE_REG)
#define PCIE_CAP_ID_NXT_PTR_REG_REG(base)        ((base)->CAP_ID_NXT_PTR_REG)
#define PCIE_CON_STATUS_REG_REG(base)            ((base)->CON_STATUS_REG)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_REG(base) ((base)->PCI_MSI_CAP_ID_NEXT_CTRL_REG)
#define PCIE_MSI_CAP_OFF_04H_REG_REG(base)       ((base)->MSI_CAP_OFF_04H_REG)
#define PCIE_MSI_CAP_OFF_08H_REG_REG(base)       ((base)->MSI_CAP_OFF_08H_REG)
#define PCIE_MSI_CAP_OFF_0CH_REG_REG(base)       ((base)->MSI_CAP_OFF_0CH_REG)
#define PCIE_MSI_CAP_OFF_10H_REG_REG(base)       ((base)->MSI_CAP_OFF_10H_REG)
#define PCIE_MSI_CAP_OFF_14H_REG_REG(base)       ((base)->MSI_CAP_OFF_14H_REG)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_REG(base) ((base)->PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG)
#define PCIE_DEVICE_CAPABILITIES_REG_REG(base)   ((base)->DEVICE_CAPABILITIES_REG)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_REG(base) ((base)->DEVICE_CONTROL_DEVICE_STATUS)
#define PCIE_LINK_CAPABILITIES_REG_REG(base)     ((base)->LINK_CAPABILITIES_REG)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_REG(base) ((base)->LINK_CONTROL_LINK_STATUS_REG)
#define PCIE_SLOT_CAPABILITIES_REG_REG(base)     ((base)->SLOT_CAPABILITIES_REG)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_REG(base)  ((base)->SLOT_CONTROL_SLOT_STATUS)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_REG(base) ((base)->ROOT_CONTROL_ROOT_CAPABILITIES_REG)
#define PCIE_ROOT_STATUS_REG_REG(base)           ((base)->ROOT_STATUS_REG)
#define PCIE_DEVICE_CAPABILITIES2_REG_REG(base)  ((base)->DEVICE_CAPABILITIES2_REG)
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_REG(base) ((base)->DEVICE_CONTROL2_DEVICE_STATUS2_REG)
#define PCIE_LINK_CAPABILITIES2_REG_REG(base)    ((base)->LINK_CAPABILITIES2_REG)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_REG(base) ((base)->LINK_CONTROL2_LINK_STATUS2_REG)
#define PCIE_AER_EXT_CAP_HDR_OFF_REG(base)       ((base)->AER_EXT_CAP_HDR_OFF)
#define PCIE_UNCORR_ERR_STATUS_OFF_REG(base)     ((base)->UNCORR_ERR_STATUS_OFF)
#define PCIE_UNCORR_ERR_MASK_OFF_REG(base)       ((base)->UNCORR_ERR_MASK_OFF)
#define PCIE_UNCORR_ERR_SEV_OFF_REG(base)        ((base)->UNCORR_ERR_SEV_OFF)
#define PCIE_CORR_ERR_STATUS_OFF_REG(base)       ((base)->CORR_ERR_STATUS_OFF)
#define PCIE_CORR_ERR_MASK_OFF_REG(base)         ((base)->CORR_ERR_MASK_OFF)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_REG(base)      ((base)->ADV_ERR_CAP_CTRL_OFF)
#define PCIE_HDR_LOG_0_OFF_REG(base)             ((base)->HDR_LOG_0_OFF)
#define PCIE_HDR_LOG_1_OFF_REG(base)             ((base)->HDR_LOG_1_OFF)
#define PCIE_HDR_LOG_2_OFF_REG(base)             ((base)->HDR_LOG_2_OFF)
#define PCIE_HDR_LOG_3_OFF_REG(base)             ((base)->HDR_LOG_3_OFF)
#define PCIE_ROOT_ERR_CMD_OFF_REG(base)          ((base)->ROOT_ERR_CMD_OFF)
#define PCIE_ROOT_ERR_STATUS_OFF_REG(base)       ((base)->ROOT_ERR_STATUS_OFF)
#define PCIE_ERR_SRC_ID_OFF_REG(base)            ((base)->ERR_SRC_ID_OFF)
#define PCIE_TLP_PREFIX_LOG_1_OFF_REG(base)      ((base)->TLP_PREFIX_LOG_1_OFF)
#define PCIE_TLP_PREFIX_LOG_2_OFF_REG(base)      ((base)->TLP_PREFIX_LOG_2_OFF)
#define PCIE_TLP_PREFIX_LOG_3_OFF_REG(base)      ((base)->TLP_PREFIX_LOG_3_OFF)
#define PCIE_TLP_PREFIX_LOG_4_OFF_REG(base)      ((base)->TLP_PREFIX_LOG_4_OFF)
#define PCIE_L1SUB_CAP_HEADER_REG_REG(base)      ((base)->L1SUB_CAP_HEADER_REG)
#define PCIE_L1SUB_CAPABILITY_REG_REG(base)      ((base)->L1SUB_CAPABILITY_REG)
#define PCIE_L1SUB_CONTROL1_REG_REG(base)        ((base)->L1SUB_CONTROL1_REG)
#define PCIE_L1SUB_CONTROL2_REG_REG(base)        ((base)->L1SUB_CONTROL2_REG)
#define PCIE_ACK_LATENCY_TIMER_OFF_REG(base)     ((base)->ACK_LATENCY_TIMER_OFF)
#define PCIE_VENDOR_SPEC_DLLP_OFF_REG(base)      ((base)->VENDOR_SPEC_DLLP_OFF)
#define PCIE_PORT_FORCE_OFF_REG(base)            ((base)->PORT_FORCE_OFF)
#define PCIE_ACK_F_ASPM_CTRL_OFF_REG(base)       ((base)->ACK_F_ASPM_CTRL_OFF)
#define PCIE_PORT_LINK_CTRL_OFF_REG(base)        ((base)->PORT_LINK_CTRL_OFF)
#define PCIE_LANE_SKEW_OFF_REG(base)             ((base)->LANE_SKEW_OFF)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_REG(base) ((base)->TIMER_CTRL_MAX_FUNC_NUM_OFF)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_REG(base) ((base)->SYMBOL_TIMER_FILTER_1_OFF)
#define PCIE_FILTER_MASK_2_OFF_REG(base)         ((base)->FILTER_MASK_2_OFF)
#define PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_REG(base) ((base)->AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF)
#define PCIE_PL_DEBUG0_OFF_REG(base)             ((base)->PL_DEBUG0_OFF)
#define PCIE_PL_DEBUG1_OFF_REG(base)             ((base)->PL_DEBUG1_OFF)
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_REG(base) ((base)->TX_P_FC_CREDIT_STATUS_OFF)
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_REG(base) ((base)->TX_NP_FC_CREDIT_STATUS_OFF)
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_REG(base) ((base)->TX_CPL_FC_CREDIT_STATUS_OFF)
#define PCIE_QUEUE_STATUS_OFF_REG(base)          ((base)->QUEUE_STATUS_OFF)
#define PCIE_VC_TX_ARBI_1_OFF_REG(base)          ((base)->VC_TX_ARBI_1_OFF)
#define PCIE_VC_TX_ARBI_2_OFF_REG(base)          ((base)->VC_TX_ARBI_2_OFF)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_REG(base)       ((base)->VC0_P_RX_Q_CTRL_OFF)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_REG(base)      ((base)->VC0_NP_RX_Q_CTRL_OFF)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_REG(base)     ((base)->VC0_CPL_RX_Q_CTRL_OFF)
#define PCIE_GEN2_CTRL_OFF_REG(base)             ((base)->GEN2_CTRL_OFF)
#define PCIE_PHY_STATUS_OFF_REG(base)            ((base)->PHY_STATUS_OFF)
#define PCIE_PHY_CONTROL_OFF_REG(base)           ((base)->PHY_CONTROL_OFF)
#define PCIE_TRGT_MAP_CTRL_OFF_REG(base)         ((base)->TRGT_MAP_CTRL_OFF)
#define PCIE_MSI_CTRL_ADDR_OFF_REG(base)         ((base)->MSI_CTRL_ADDR_OFF)
#define PCIE_MSI_CTRL_UPPER_ADDR_OFF_REG(base)   ((base)->MSI_CTRL_UPPER_ADDR_OFF)
#define PCIE_MSI_CTRL_INT_0_EN_OFF_REG(base)     ((base)->MSI_CTRL_INT_0_EN_OFF)
#define PCIE_MSI_CTRL_INT_0_MASK_OFF_REG(base)   ((base)->MSI_CTRL_INT_0_MASK_OFF)
#define PCIE_MSI_CTRL_INT_0_STATUS_OFF_REG(base) ((base)->MSI_CTRL_INT_0_STATUS_OFF)
#define PCIE_MSI_CTRL_INT_1_EN_OFF_REG(base)     ((base)->MSI_CTRL_INT_1_EN_OFF)
#define PCIE_MSI_CTRL_INT_1_MASK_OFF_REG(base)   ((base)->MSI_CTRL_INT_1_MASK_OFF)
#define PCIE_MSI_CTRL_INT_1_STATUS_OFF_REG(base) ((base)->MSI_CTRL_INT_1_STATUS_OFF)
#define PCIE_MSI_CTRL_INT_2_EN_OFF_REG(base)     ((base)->MSI_CTRL_INT_2_EN_OFF)
#define PCIE_MSI_CTRL_INT_2_MASK_OFF_REG(base)   ((base)->MSI_CTRL_INT_2_MASK_OFF)
#define PCIE_MSI_CTRL_INT_2_STATUS_OFF_REG(base) ((base)->MSI_CTRL_INT_2_STATUS_OFF)
#define PCIE_MSI_CTRL_INT_3_EN_OFF_REG(base)     ((base)->MSI_CTRL_INT_3_EN_OFF)
#define PCIE_MSI_CTRL_INT_3_MASK_OFF_REG(base)   ((base)->MSI_CTRL_INT_3_MASK_OFF)
#define PCIE_MSI_CTRL_INT_3_STATUS_OFF_REG(base) ((base)->MSI_CTRL_INT_3_STATUS_OFF)
#define PCIE_MSI_CTRL_INT_4_EN_OFF_REG(base)     ((base)->MSI_CTRL_INT_4_EN_OFF)
#define PCIE_MSI_CTRL_INT_4_MASK_OFF_REG(base)   ((base)->MSI_CTRL_INT_4_MASK_OFF)
#define PCIE_MSI_CTRL_INT_4_STATUS_OFF_REG(base) ((base)->MSI_CTRL_INT_4_STATUS_OFF)
#define PCIE_MSI_CTRL_INT_5_EN_OFF_REG(base)     ((base)->MSI_CTRL_INT_5_EN_OFF)
#define PCIE_MSI_CTRL_INT_5_MASK_OFF_REG(base)   ((base)->MSI_CTRL_INT_5_MASK_OFF)
#define PCIE_MSI_CTRL_INT_5_STATUS_OFF_REG(base) ((base)->MSI_CTRL_INT_5_STATUS_OFF)
#define PCIE_MSI_CTRL_INT_6_EN_OFF_REG(base)     ((base)->MSI_CTRL_INT_6_EN_OFF)
#define PCIE_MSI_CTRL_INT_6_MASK_OFF_REG(base)   ((base)->MSI_CTRL_INT_6_MASK_OFF)
#define PCIE_MSI_CTRL_INT_6_STATUS_OFF_REG(base) ((base)->MSI_CTRL_INT_6_STATUS_OFF)
#define PCIE_MSI_CTRL_INT_7_EN_OFF_REG(base)     ((base)->MSI_CTRL_INT_7_EN_OFF)
#define PCIE_MSI_CTRL_INT_7_MASK_OFF_REG(base)   ((base)->MSI_CTRL_INT_7_MASK_OFF)
#define PCIE_MSI_CTRL_INT_7_STATUS_OFF_REG(base) ((base)->MSI_CTRL_INT_7_STATUS_OFF)
#define PCIE_MSI_GPIO_IO_OFF_REG(base)           ((base)->MSI_GPIO_IO_OFF)
#define PCIE_CLOCK_GATING_CTRL_OFF_REG(base)     ((base)->CLOCK_GATING_CTRL_OFF)
#define PCIE_ORDER_RULE_CTRL_OFF_REG(base)       ((base)->ORDER_RULE_CTRL_OFF)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_REG(base) ((base)->PIPE_LOOPBACK_CONTROL_OFF)
#define PCIE_MISC_CONTROL_1_OFF_REG(base)        ((base)->MISC_CONTROL_1_OFF)
#define PCIE_MULTI_LANE_CONTROL_OFF_REG(base)    ((base)->MULTI_LANE_CONTROL_OFF)
#define PCIE_PHY_INTEROP_CTRL_OFF_REG(base)      ((base)->PHY_INTEROP_CTRL_OFF)
#define PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_REG(base) ((base)->TRGT_CPL_LUT_DELETE_ENTRY_OFF)
#define PCIE_LINK_FLUSH_CONTROL_OFF_REG(base)    ((base)->LINK_FLUSH_CONTROL_OFF)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_REG(base) ((base)->AMBA_ERROR_RESPONSE_DEFAULT_OFF)
#define PCIE_AMBA_LINK_TIMEOUT_OFF_REG(base)     ((base)->AMBA_LINK_TIMEOUT_OFF)
#define PCIE_AMBA_ORDERING_CTRL_OFF_REG(base)    ((base)->AMBA_ORDERING_CTRL_OFF)
#define PCIE_COHERENCY_CONTROL_1_OFF_REG(base)   ((base)->COHERENCY_CONTROL_1_OFF)
#define PCIE_COHERENCY_CONTROL_2_OFF_REG(base)   ((base)->COHERENCY_CONTROL_2_OFF)
#define PCIE_COHERENCY_CONTROL_3_OFF_REG(base)   ((base)->COHERENCY_CONTROL_3_OFF)
#define PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_REG(base) ((base)->AXI_MSTR_MSG_ADDR_LOW_OFF)
#define PCIE_AXI_MSTR_MSG_ADDR_HIGH_OFF_REG(base) ((base)->AXI_MSTR_MSG_ADDR_HIGH_OFF)
#define PCIE_PCIE_VERSION_NUMBER_OFF_REG(base)   ((base)->PCIE_VERSION_NUMBER_OFF)
#define PCIE_PCIE_VERSION_TYPE_OFF_REG(base)     ((base)->PCIE_VERSION_TYPE_OFF)
#define PCIE_AUX_CLK_FREQ_OFF_REG(base)          ((base)->AUX_CLK_FREQ_OFF)
#define PCIE_L1_SUBSTATES_OFF_REG(base)          ((base)->L1_SUBSTATES_OFF)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_REG(base) ((base)->IATU_REGION_CTRL_1_OFF_OUTBOUND_0)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_REG(base) ((base)->IATU_REGION_CTRL_2_OFF_OUTBOUND_0)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_REG(base) ((base)->IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_REG(base) ((base)->IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_REG(base) ((base)->IATU_LIMIT_ADDR_OFF_OUTBOUND_0)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_REG(base) ((base)->IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_REG(base) ((base)->IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_REG(base) ((base)->IATU_REGION_CTRL_1_OFF_INBOUND_0)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_REG(base) ((base)->IATU_REGION_CTRL_2_OFF_INBOUND_0)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_REG(base) ((base)->IATU_LWR_BASE_ADDR_OFF_INBOUND_0)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_0_REG(base) ((base)->IATU_UPPER_BASE_ADDR_OFF_INBOUND_0)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_REG(base) ((base)->IATU_LIMIT_ADDR_OFF_INBOUND_0)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_REG(base) ((base)->IATU_LWR_TARGET_ADDR_OFF_INBOUND_0)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_REG(base) ((base)->IATU_REGION_CTRL_1_OFF_OUTBOUND_1)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_REG(base) ((base)->IATU_REGION_CTRL_2_OFF_OUTBOUND_1)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_REG(base) ((base)->IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1_REG(base) ((base)->IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_REG(base) ((base)->IATU_LIMIT_ADDR_OFF_OUTBOUND_1)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1_REG(base) ((base)->IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1_REG(base) ((base)->IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_REG(base) ((base)->IATU_REGION_CTRL_1_OFF_INBOUND_1)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_REG(base) ((base)->IATU_REGION_CTRL_2_OFF_INBOUND_1)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_REG(base) ((base)->IATU_LWR_BASE_ADDR_OFF_INBOUND_1)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_1_REG(base) ((base)->IATU_UPPER_BASE_ADDR_OFF_INBOUND_1)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_REG(base) ((base)->IATU_LIMIT_ADDR_OFF_INBOUND_1)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_REG(base) ((base)->IATU_LWR_TARGET_ADDR_OFF_INBOUND_1)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_REG(base) ((base)->IATU_REGION_CTRL_1_OFF_OUTBOUND_2)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_REG(base) ((base)->IATU_REGION_CTRL_2_OFF_OUTBOUND_2)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_REG(base) ((base)->IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2_REG(base) ((base)->IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_REG(base) ((base)->IATU_LIMIT_ADDR_OFF_OUTBOUND_2)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2_REG(base) ((base)->IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2_REG(base) ((base)->IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_REG(base) ((base)->IATU_REGION_CTRL_1_OFF_INBOUND_2)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_REG(base) ((base)->IATU_REGION_CTRL_2_OFF_INBOUND_2)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_REG(base) ((base)->IATU_LWR_BASE_ADDR_OFF_INBOUND_2)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_2_REG(base) ((base)->IATU_UPPER_BASE_ADDR_OFF_INBOUND_2)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_REG(base) ((base)->IATU_LIMIT_ADDR_OFF_INBOUND_2)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_REG(base) ((base)->IATU_LWR_TARGET_ADDR_OFF_INBOUND_2)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_REG(base) ((base)->IATU_REGION_CTRL_1_OFF_OUTBOUND_3)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_REG(base) ((base)->IATU_REGION_CTRL_2_OFF_OUTBOUND_3)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_REG(base) ((base)->IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3_REG(base) ((base)->IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_REG(base) ((base)->IATU_LIMIT_ADDR_OFF_OUTBOUND_3)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3_REG(base) ((base)->IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3_REG(base) ((base)->IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_REG(base) ((base)->IATU_REGION_CTRL_1_OFF_INBOUND_3)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_REG(base) ((base)->IATU_REGION_CTRL_2_OFF_INBOUND_3)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_REG(base) ((base)->IATU_LWR_BASE_ADDR_OFF_INBOUND_3)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_3_REG(base) ((base)->IATU_UPPER_BASE_ADDR_OFF_INBOUND_3)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_REG(base) ((base)->IATU_LIMIT_ADDR_OFF_INBOUND_3)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_REG(base) ((base)->IATU_LWR_TARGET_ADDR_OFF_INBOUND_3)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_REG(base) ((base)->DMA_CTRL_DATA_ARB_PRIOR_OFF)
#define PCIE_DMA_CTRL_OFF_REG(base)              ((base)->DMA_CTRL_OFF)
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_REG(base)   ((base)->DMA_WRITE_ENGINE_EN_OFF)
#define PCIE_DMA_WRITE_DOORBELL_OFF_REG(base)    ((base)->DMA_WRITE_DOORBELL_OFF)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_REG(base) ((base)->DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_REG(base) ((base)->DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF)
#define PCIE_DMA_READ_ENGINE_EN_OFF_REG(base)    ((base)->DMA_READ_ENGINE_EN_OFF)
#define PCIE_DMA_READ_DOORBELL_OFF_REG(base)     ((base)->DMA_READ_DOORBELL_OFF)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_REG(base) ((base)->DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_REG(base) ((base)->DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_REG(base)  ((base)->DMA_WRITE_INT_STATUS_OFF)
#define PCIE_DMA_WRITE_INT_MASK_OFF_REG(base)    ((base)->DMA_WRITE_INT_MASK_OFF)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_REG(base)   ((base)->DMA_WRITE_INT_CLEAR_OFF)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_REG(base)  ((base)->DMA_WRITE_ERR_STATUS_OFF)
#define PCIE_DMA_WRITE_DONE_IMWR_LOW_OFF_REG(base) ((base)->DMA_WRITE_DONE_IMWR_LOW_OFF)
#define PCIE_DMA_WRITE_DONE_IMWR_HIGH_OFF_REG(base) ((base)->DMA_WRITE_DONE_IMWR_HIGH_OFF)
#define PCIE_DMA_WRITE_ABORT_IMWR_LOW_OFF_REG(base) ((base)->DMA_WRITE_ABORT_IMWR_LOW_OFF)
#define PCIE_DMA_WRITE_ABORT_IMWR_HIGH_OFF_REG(base) ((base)->DMA_WRITE_ABORT_IMWR_HIGH_OFF)
#define PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_REG(base) ((base)->DMA_WRITE_CH01_IMWR_DATA_OFF)
#define PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_REG(base) ((base)->DMA_WRITE_CH23_IMWR_DATA_OFF)
#define PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_REG(base) ((base)->DMA_WRITE_CH45_IMWR_DATA_OFF)
#define PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_REG(base) ((base)->DMA_WRITE_CH67_IMWR_DATA_OFF)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_REG(base) ((base)->DMA_WRITE_LINKED_LIST_ERR_EN_OFF)
#define PCIE_DMA_READ_INT_STATUS_OFF_REG(base)   ((base)->DMA_READ_INT_STATUS_OFF)
#define PCIE_DMA_READ_INT_MASK_OFF_REG(base)     ((base)->DMA_READ_INT_MASK_OFF)
#define PCIE_DMA_READ_INT_CLEAR_OFF_REG(base)    ((base)->DMA_READ_INT_CLEAR_OFF)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_REG(base) ((base)->DMA_READ_ERR_STATUS_LOW_OFF)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_REG(base) ((base)->DMA_READ_ERR_STATUS_HIGH_OFF)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_REG(base) ((base)->DMA_READ_LINKED_LIST_ERR_EN_OFF)
#define PCIE_DMA_READ_DONE_IMWR_LOW_OFF_REG(base) ((base)->DMA_READ_DONE_IMWR_LOW_OFF)
#define PCIE_DMA_READ_DONE_IMWR_HIGH_OFF_REG(base) ((base)->DMA_READ_DONE_IMWR_HIGH_OFF)
#define PCIE_DMA_READ_ABORT_IMWR_LOW_OFF_REG(base) ((base)->DMA_READ_ABORT_IMWR_LOW_OFF)
#define PCIE_DMA_READ_ABORT_IMWR_HIGH_OFF_REG(base) ((base)->DMA_READ_ABORT_IMWR_HIGH_OFF)
#define PCIE_DMA_READ_CH01_IMWR_DATA_OFF_REG(base) ((base)->DMA_READ_CH01_IMWR_DATA_OFF)
#define PCIE_DMA_READ_CH23_IMWR_DATA_OFF_REG(base) ((base)->DMA_READ_CH23_IMWR_DATA_OFF)
#define PCIE_DMA_READ_CH45_IMWR_DATA_OFF_REG(base) ((base)->DMA_READ_CH45_IMWR_DATA_OFF)
#define PCIE_DMA_READ_CH67_IMWR_DATA_OFF_REG(base) ((base)->DMA_READ_CH67_IMWR_DATA_OFF)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_REG(base) ((base)->DMA_CH_CONTROL1_OFF_WRCH_0)
#define PCIE_DMA_TRANSFER_SIZE_OFF_WRCH_0_REG(base) ((base)->DMA_TRANSFER_SIZE_OFF_WRCH_0)
#define PCIE_DMA_SAR_LOW_OFF_WRCH_0_REG(base)    ((base)->DMA_SAR_LOW_OFF_WRCH_0)
#define PCIE_DMA_SAR_HIGH_OFF_WRCH_0_REG(base)   ((base)->DMA_SAR_HIGH_OFF_WRCH_0)
#define PCIE_DMA_DAR_LOW_OFF_WRCH_0_REG(base)    ((base)->DMA_DAR_LOW_OFF_WRCH_0)
#define PCIE_DMA_DAR_HIGH_OFF_WRCH_0_REG(base)   ((base)->DMA_DAR_HIGH_OFF_WRCH_0)
#define PCIE_DMA_LLP_LOW_OFF_WRCH_0_REG(base)    ((base)->DMA_LLP_LOW_OFF_WRCH_0)
#define PCIE_DMA_LLP_HIGH_OFF_WRCH_0_REG(base)   ((base)->DMA_LLP_HIGH_OFF_WRCH_0)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_REG(base) ((base)->DMA_CH_CONTROL1_OFF_RDCH_0)
#define PCIE_DMA_TRANSFER_SIZE_OFF_RDCH_0_REG(base) ((base)->DMA_TRANSFER_SIZE_OFF_RDCH_0)
#define PCIE_DMA_SAR_LOW_OFF_RDCH_0_REG(base)    ((base)->DMA_SAR_LOW_OFF_RDCH_0)
#define PCIE_DMA_SAR_HIGH_OFF_RDCH_0_REG(base)   ((base)->DMA_SAR_HIGH_OFF_RDCH_0)
#define PCIE_DMA_DAR_LOW_OFF_RDCH_0_REG(base)    ((base)->DMA_DAR_LOW_OFF_RDCH_0)
#define PCIE_DMA_DAR_HIGH_OFF_RDCH_0_REG(base)   ((base)->DMA_DAR_HIGH_OFF_RDCH_0)
#define PCIE_DMA_LLP_LOW_OFF_RDCH_0_REG(base)    ((base)->DMA_LLP_LOW_OFF_RDCH_0)
#define PCIE_DMA_LLP_HIGH_OFF_RDCH_0_REG(base)   ((base)->DMA_LLP_HIGH_OFF_RDCH_0)

/*!
 * @}
 */ /* end of group PCIE_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PCIE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCIE_Register_Masks PCIE Register Masks
 * @{
 */

/*! @name TYPE1_DEV_ID_VEND_ID_REG - Device ID and Vendor ID Register. */
/*! @{ */
#define PCIE_TYPE1_DEV_ID_VEND_ID_REG_VENDOR_ID_MASK (0xFFFFU)
#define PCIE_TYPE1_DEV_ID_VEND_ID_REG_VENDOR_ID_SHIFT (0U)
#define PCIE_TYPE1_DEV_ID_VEND_ID_REG_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_DEV_ID_VEND_ID_REG_VENDOR_ID_SHIFT)) & PCIE_TYPE1_DEV_ID_VEND_ID_REG_VENDOR_ID_MASK)
#define PCIE_TYPE1_DEV_ID_VEND_ID_REG_DEVICE_ID_MASK (0xFFFF0000U)
#define PCIE_TYPE1_DEV_ID_VEND_ID_REG_DEVICE_ID_SHIFT (16U)
#define PCIE_TYPE1_DEV_ID_VEND_ID_REG_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_DEV_ID_VEND_ID_REG_DEVICE_ID_SHIFT)) & PCIE_TYPE1_DEV_ID_VEND_ID_REG_DEVICE_ID_MASK)
/*! @} */

/*! @name TYPE1_STATUS_COMMAND_REG - Status and Command Register. */
/*! @{ */
#define PCIE_TYPE1_STATUS_COMMAND_REG_IO_EN_MASK (0x1U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_IO_EN_SHIFT (0U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_MSE_MASK   (0x2U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_MSE_SHIFT  (1U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_BME_MASK   (0x4U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_BME_SHIFT  (2U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_SCO_MASK   (0x8U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_SCO_SHIFT  (3U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_MWI_EN_MASK (0x10U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_MWI_EN_SHIFT (4U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_VGAPS_MASK (0x20U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_VGAPS_SHIFT (5U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_PERREN_MASK (0x40U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_PERREN_SHIFT (6U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_IDSEL_MASK (0x80U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_IDSEL_SHIFT (7U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_SERREN_MASK (0x100U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_SERREN_SHIFT (8U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_9_MASK (0x200U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_9_SHIFT (9U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_INT_EN_MASK (0x400U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_INT_EN_SHIFT (10U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RESERV_MASK (0xF800U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RESERV_SHIFT (11U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RESERV(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_RESERV_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_RESERV_MASK)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_17_MASK (0x60000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_17_SHIFT (17U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_17(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_17_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_17_MASK)
#define PCIE_TYPE1_STATUS_COMMAND_REG_INT_STATUS_MASK (0x80000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_INT_STATUS_SHIFT (19U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_CAP_LIST_MASK (0x100000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_CAP_LIST_SHIFT (20U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_FAST_66MHZ_CAP_MASK (0x200000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_FAST_66MHZ_CAP_SHIFT (21U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_22_MASK (0x400000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_22_SHIFT (22U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_FAST_B2B_CAP_MASK (0x800000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_FAST_B2B_CAP_SHIFT (23U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_MASTER_DPE_MASK (0x1000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_MASTER_DPE_SHIFT (24U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_DEV_SEL_TIMING_MASK (0x6000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_DEV_SEL_TIMING_SHIFT (25U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_DEV_SEL_TIMING(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_DEV_SEL_TIMING_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_DEV_SEL_TIMING_MASK)
#define PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_TARGET_ABORT_MASK (0x8000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_TARGET_ABORT_SHIFT (27U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_TARGET_ABORT_MASK (0x10000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_TARGET_ABORT_SHIFT (28U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_MASTER_ABORT_MASK (0x20000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_MASTER_ABORT_SHIFT (29U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_SYS_ERROR_MASK (0x40000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_SYS_ERROR_SHIFT (30U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_DETECTED_PARITY_ERROR_MASK (0x80000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_DETECTED_PARITY_ERROR_SHIFT (31U)
/*! @} */

/*! @name TYPE1_CLASS_CODE_REV_ID_REG - Class Code and Revision ID Register. */
/*! @{ */
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_REVISION_ID_MASK (0xFFU)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_REVISION_ID_SHIFT (0U)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_REVISION_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_CLASS_CODE_REV_ID_REG_REVISION_ID_SHIFT)) & PCIE_TYPE1_CLASS_CODE_REV_ID_REG_REVISION_ID_MASK)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_PROGRAM_INTERFACE_MASK (0xFF00U)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_PROGRAM_INTERFACE_SHIFT (8U)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_PROGRAM_INTERFACE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_CLASS_CODE_REV_ID_REG_PROGRAM_INTERFACE_SHIFT)) & PCIE_TYPE1_CLASS_CODE_REV_ID_REG_PROGRAM_INTERFACE_MASK)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_SUBCLASS_CODE_MASK (0xFF0000U)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_SUBCLASS_CODE_SHIFT (16U)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_SUBCLASS_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_CLASS_CODE_REV_ID_REG_SUBCLASS_CODE_SHIFT)) & PCIE_TYPE1_CLASS_CODE_REV_ID_REG_SUBCLASS_CODE_MASK)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_BASE_CLASS_CODE_MASK (0xFF000000U)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_BASE_CLASS_CODE_SHIFT (24U)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_BASE_CLASS_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_CLASS_CODE_REV_ID_REG_BASE_CLASS_CODE_SHIFT)) & PCIE_TYPE1_CLASS_CODE_REV_ID_REG_BASE_CLASS_CODE_MASK)
/*! @} */

/*! @name TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG - BIST, Header Type, Latency Timer, and Cache Line Size Register. */
/*! @{ */
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_CACHE_LINE_SIZE_MASK (0xFFU)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_CACHE_LINE_SIZE_SHIFT (0U)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_CACHE_LINE_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_CACHE_LINE_SIZE_SHIFT)) & PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_CACHE_LINE_SIZE_MASK)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_LATENCY_MASTER_TIMER_MASK (0xFF00U)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_LATENCY_MASTER_TIMER_SHIFT (8U)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_LATENCY_MASTER_TIMER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_LATENCY_MASTER_TIMER_SHIFT)) & PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_LATENCY_MASTER_TIMER_MASK)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_HEADER_TYPE_MASK (0x7F0000U)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_HEADER_TYPE_SHIFT (16U)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_HEADER_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_HEADER_TYPE_SHIFT)) & PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_HEADER_TYPE_MASK)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_MULTI_FUNC_MASK (0x800000U)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_MULTI_FUNC_SHIFT (23U)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_BIST_MASK (0xFF000000U)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_BIST_SHIFT (24U)
#define PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_BIST(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_BIST_SHIFT)) & PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_BIST_MASK)
/*! @} */

/*! @name SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG - Secondary Latency Timer, Subordinate Bus Number, Secondary Bus Number, and Primary Bus Number Register. */
/*! @{ */
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_PRIM_BUS_MASK (0xFFU)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_PRIM_BUS_SHIFT (0U)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_PRIM_BUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_PRIM_BUS_SHIFT)) & PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_PRIM_BUS_MASK)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_BUS_MASK (0xFF00U)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_BUS_SHIFT (8U)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_BUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_BUS_SHIFT)) & PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_BUS_MASK)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SUB_BUS_MASK (0xFF0000U)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SUB_BUS_SHIFT (16U)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SUB_BUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SUB_BUS_SHIFT)) & PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SUB_BUS_MASK)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_LAT_TIMER_MASK (0xFF000000U)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_LAT_TIMER_SHIFT (24U)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_LAT_TIMER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_LAT_TIMER_SHIFT)) & PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_LAT_TIMER_MASK)
/*! @} */

/*! @name SEC_STAT_IO_LIMIT_IO_BASE_REG - Secondary Status, and I/O Limit and Base Register. */
/*! @{ */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE_MASK (0x1U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE_SHIFT (0U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV_MASK (0xEU)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV_SHIFT (1U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV_MASK)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_BASE_MASK (0xF0U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_BASE_SHIFT (4U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_BASE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_BASE_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_BASE_MASK)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE_BIT8_MASK (0x100U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE_BIT8_SHIFT (8U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV1_MASK (0xE00U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV1_SHIFT (9U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV1_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV1_MASK)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_LIMIT_MASK (0xF000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_LIMIT_SHIFT (12U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_LIMIT_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_LIMIT_MASK)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RESERV_MASK (0x7F0000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RESERV_SHIFT (16U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RESERV(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RESERV_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RESERV_MASK)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_23_MASK (0x800000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_23_SHIFT (23U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_MDPE_MASK (0x1000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_MDPE_SHIFT (24U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_25_MASK (0x6000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_25_SHIFT (25U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_25(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_25_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_25_MASK)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_SIG_TRGT_ABRT_MASK (0x8000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_SIG_TRGT_ABRT_SHIFT (27U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_TRGT_ABRT_MASK (0x10000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_TRGT_ABRT_SHIFT (28U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_MSTR_ABRT_MASK (0x20000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_MSTR_ABRT_SHIFT (29U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_SYS_ERR_MASK (0x40000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_SYS_ERR_SHIFT (30U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_DPE_MASK (0x80000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_DPE_SHIFT (31U)
/*! @} */

/*! @name MEM_LIMIT_MEM_BASE_REG - Memory Limit and Base Register. */
/*! @{ */
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_RESERV_MASK (0xFU)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_RESERV_SHIFT (0U)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_RESERV(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_RESERV_SHIFT)) & PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_RESERV_MASK)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_MASK (0xFFF0U)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_SHIFT (4U)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_SHIFT)) & PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_MASK)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_RESERV_MASK (0xF0000U)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_RESERV_SHIFT (16U)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_RESERV(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_RESERV_SHIFT)) & PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_RESERV_MASK)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_MASK (0xFFF00000U)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_SHIFT (20U)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_SHIFT)) & PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_MASK)
/*! @} */

/*! @name PREF_MEM_LIMIT_PREF_MEM_BASE_REG - Prefetchable Memory Limit and Base Register. */
/*! @{ */
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_DECODE_MASK (0x1U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_DECODE_SHIFT (0U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV_MASK (0xEU)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV_SHIFT (1U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV_SHIFT)) & PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV_MASK)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_BASE_MASK (0xFFF0U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_BASE_SHIFT (4U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_BASE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_BASE_SHIFT)) & PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_BASE_MASK)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_DECODE_MASK (0x10000U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_DECODE_SHIFT (16U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV1_MASK (0xE0000U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV1_SHIFT (17U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV1_SHIFT)) & PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV1_MASK)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_MASK (0xFFF00000U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_SHIFT (20U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_SHIFT)) & PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_MASK)
/*! @} */

/*! @name PREF_BASE_UPPER_REG - Prefetchable Base Upper 32 Bits Register. */
/*! @{ */
#define PCIE_PREF_BASE_UPPER_REG_PREF_MEM_BASE_UPPER_MASK (0xFFFFFFFFU)
#define PCIE_PREF_BASE_UPPER_REG_PREF_MEM_BASE_UPPER_SHIFT (0U)
#define PCIE_PREF_BASE_UPPER_REG_PREF_MEM_BASE_UPPER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_BASE_UPPER_REG_PREF_MEM_BASE_UPPER_SHIFT)) & PCIE_PREF_BASE_UPPER_REG_PREF_MEM_BASE_UPPER_MASK)
/*! @} */

/*! @name PREF_LIMIT_UPPER_REG - Prefetchable Limit Upper 32 Bits Register. */
/*! @{ */
#define PCIE_PREF_LIMIT_UPPER_REG_PREF_MEM_LIMIT_UPPER_MASK (0xFFFFFFFFU)
#define PCIE_PREF_LIMIT_UPPER_REG_PREF_MEM_LIMIT_UPPER_SHIFT (0U)
#define PCIE_PREF_LIMIT_UPPER_REG_PREF_MEM_LIMIT_UPPER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_LIMIT_UPPER_REG_PREF_MEM_LIMIT_UPPER_SHIFT)) & PCIE_PREF_LIMIT_UPPER_REG_PREF_MEM_LIMIT_UPPER_MASK)
/*! @} */

/*! @name IO_LIMIT_UPPER_IO_BASE_UPPER_REG - I/O Limit and Base Upper 16 Bits Register. */
/*! @{ */
#define PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_BASE_UPPER_MASK (0xFFFFU)
#define PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_BASE_UPPER_SHIFT (0U)
#define PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_BASE_UPPER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_BASE_UPPER_SHIFT)) & PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_BASE_UPPER_MASK)
#define PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_LIMIT_UPPER_MASK (0xFFFF0000U)
#define PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_LIMIT_UPPER_SHIFT (16U)
#define PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_LIMIT_UPPER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_LIMIT_UPPER_SHIFT)) & PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_LIMIT_UPPER_MASK)
/*! @} */

/*! @name TYPE1_CAP_PTR_REG - Capabilities Pointer Register. */
/*! @{ */
#define PCIE_TYPE1_CAP_PTR_REG_CAP_POINTER_MASK  (0xFFU)
#define PCIE_TYPE1_CAP_PTR_REG_CAP_POINTER_SHIFT (0U)
#define PCIE_TYPE1_CAP_PTR_REG_CAP_POINTER(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_CAP_PTR_REG_CAP_POINTER_SHIFT)) & PCIE_TYPE1_CAP_PTR_REG_CAP_POINTER_MASK)
#define PCIE_TYPE1_CAP_PTR_REG_RSVDP_8_MASK      (0xFFFFFF00U)
#define PCIE_TYPE1_CAP_PTR_REG_RSVDP_8_SHIFT     (8U)
#define PCIE_TYPE1_CAP_PTR_REG_RSVDP_8(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_CAP_PTR_REG_RSVDP_8_SHIFT)) & PCIE_TYPE1_CAP_PTR_REG_RSVDP_8_MASK)
/*! @} */

/*! @name TYPE1_EXP_ROM_BASE_REG - Expansion ROM Base Address Register. */
/*! @{ */
#define PCIE_TYPE1_EXP_ROM_BASE_REG_ROM_BAR_ENABLE_MASK (0x1U)
#define PCIE_TYPE1_EXP_ROM_BASE_REG_ROM_BAR_ENABLE_SHIFT (0U)
#define PCIE_TYPE1_EXP_ROM_BASE_REG_RSVDP_1_MASK (0x7FEU)
#define PCIE_TYPE1_EXP_ROM_BASE_REG_RSVDP_1_SHIFT (1U)
#define PCIE_TYPE1_EXP_ROM_BASE_REG_RSVDP_1(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_EXP_ROM_BASE_REG_RSVDP_1_SHIFT)) & PCIE_TYPE1_EXP_ROM_BASE_REG_RSVDP_1_MASK)
#define PCIE_TYPE1_EXP_ROM_BASE_REG_EXP_ROM_BASE_ADDRESS_MASK (0xFFFFF800U)
#define PCIE_TYPE1_EXP_ROM_BASE_REG_EXP_ROM_BASE_ADDRESS_SHIFT (11U)
#define PCIE_TYPE1_EXP_ROM_BASE_REG_EXP_ROM_BASE_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_EXP_ROM_BASE_REG_EXP_ROM_BASE_ADDRESS_SHIFT)) & PCIE_TYPE1_EXP_ROM_BASE_REG_EXP_ROM_BASE_ADDRESS_MASK)
/*! @} */

/*! @name BRIDGE_CTRL_INT_PIN_INT_LINE_REG - Bridge Control, Interrupt Pin, and Interrupt Line Register. */
/*! @{ */
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_LINE_MASK (0xFFU)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_LINE_SHIFT (0U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_LINE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_LINE_SHIFT)) & PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_LINE_MASK)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_PIN_MASK (0xFF00U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_PIN_SHIFT (8U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_PIN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_PIN_SHIFT)) & PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_PIN_MASK)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_PERE_MASK (0x10000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_PERE_SHIFT (16U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SERR_EN_MASK (0x20000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SERR_EN_SHIFT (17U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_ISA_EN_MASK (0x40000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_ISA_EN_SHIFT (18U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_EN_MASK (0x80000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_EN_SHIFT (19U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_16B_DEC_MASK (0x100000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_16B_DEC_SHIFT (20U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_MSTR_ABORT_MODE_MASK (0x200000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_MSTR_ABORT_MODE_SHIFT (21U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SBR_MASK (0x400000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SBR_SHIFT (22U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_BRIDGE_CTRL_RESERV_MASK (0xFF800000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_BRIDGE_CTRL_RESERV_SHIFT (23U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_BRIDGE_CTRL_RESERV(x) (((uint32_t)(((uint32_t)(x)) << PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_BRIDGE_CTRL_RESERV_SHIFT)) & PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_BRIDGE_CTRL_RESERV_MASK)
/*! @} */

/*! @name CAP_ID_NXT_PTR_REG - Power Management Capabilities Register. */
/*! @{ */
#define PCIE_CAP_ID_NXT_PTR_REG_PM_CAP_ID_MASK   (0xFFU)
#define PCIE_CAP_ID_NXT_PTR_REG_PM_CAP_ID_SHIFT  (0U)
#define PCIE_CAP_ID_NXT_PTR_REG_PM_CAP_ID(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_PM_CAP_ID_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_PM_CAP_ID_MASK)
#define PCIE_CAP_ID_NXT_PTR_REG_PM_NEXT_POINTER_MASK (0xFF00U)
#define PCIE_CAP_ID_NXT_PTR_REG_PM_NEXT_POINTER_SHIFT (8U)
#define PCIE_CAP_ID_NXT_PTR_REG_PM_NEXT_POINTER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_PM_NEXT_POINTER_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_PM_NEXT_POINTER_MASK)
#define PCIE_CAP_ID_NXT_PTR_REG_PM_SPEC_VER_MASK (0x70000U)
#define PCIE_CAP_ID_NXT_PTR_REG_PM_SPEC_VER_SHIFT (16U)
#define PCIE_CAP_ID_NXT_PTR_REG_PM_SPEC_VER(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_PM_SPEC_VER_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_PM_SPEC_VER_MASK)
#define PCIE_CAP_ID_NXT_PTR_REG_PME_CLK_MASK     (0x80000U)
#define PCIE_CAP_ID_NXT_PTR_REG_PME_CLK_SHIFT    (19U)
#define PCIE_CAP_ID_NXT_PTR_REG_DSI_MASK         (0x200000U)
#define PCIE_CAP_ID_NXT_PTR_REG_DSI_SHIFT        (21U)
#define PCIE_CAP_ID_NXT_PTR_REG_AUX_CURR_MASK    (0x1C00000U)
#define PCIE_CAP_ID_NXT_PTR_REG_AUX_CURR_SHIFT   (22U)
#define PCIE_CAP_ID_NXT_PTR_REG_AUX_CURR(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_AUX_CURR_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_AUX_CURR_MASK)
#define PCIE_CAP_ID_NXT_PTR_REG_D1_SUPPORT_MASK  (0x2000000U)
#define PCIE_CAP_ID_NXT_PTR_REG_D1_SUPPORT_SHIFT (25U)
#define PCIE_CAP_ID_NXT_PTR_REG_D2_SUPPORT_MASK  (0x4000000U)
#define PCIE_CAP_ID_NXT_PTR_REG_D2_SUPPORT_SHIFT (26U)
#define PCIE_CAP_ID_NXT_PTR_REG_PME_SUPPORT_MASK (0xF8000000U)
#define PCIE_CAP_ID_NXT_PTR_REG_PME_SUPPORT_SHIFT (27U)
#define PCIE_CAP_ID_NXT_PTR_REG_PME_SUPPORT(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_PME_SUPPORT_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_PME_SUPPORT_MASK)
/*! @} */

/*! @name CON_STATUS_REG - Power Management Control and Status Register. */
/*! @{ */
#define PCIE_CON_STATUS_REG_POWER_STATE_MASK     (0x3U)
#define PCIE_CON_STATUS_REG_POWER_STATE_SHIFT    (0U)
#define PCIE_CON_STATUS_REG_POWER_STATE(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_POWER_STATE_SHIFT)) & PCIE_CON_STATUS_REG_POWER_STATE_MASK)
#define PCIE_CON_STATUS_REG_RSVDP_2_MASK         (0x4U)
#define PCIE_CON_STATUS_REG_RSVDP_2_SHIFT        (2U)
#define PCIE_CON_STATUS_REG_NO_SOFT_RST_MASK     (0x8U)
#define PCIE_CON_STATUS_REG_NO_SOFT_RST_SHIFT    (3U)
#define PCIE_CON_STATUS_REG_RSVDP_4_MASK         (0xF0U)
#define PCIE_CON_STATUS_REG_RSVDP_4_SHIFT        (4U)
#define PCIE_CON_STATUS_REG_RSVDP_4(x)           (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_RSVDP_4_SHIFT)) & PCIE_CON_STATUS_REG_RSVDP_4_MASK)
#define PCIE_CON_STATUS_REG_PME_ENABLE_MASK      (0x100U)
#define PCIE_CON_STATUS_REG_PME_ENABLE_SHIFT     (8U)
#define PCIE_CON_STATUS_REG_DATA_SELECT_MASK     (0x1E00U)
#define PCIE_CON_STATUS_REG_DATA_SELECT_SHIFT    (9U)
#define PCIE_CON_STATUS_REG_DATA_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_DATA_SELECT_SHIFT)) & PCIE_CON_STATUS_REG_DATA_SELECT_MASK)
#define PCIE_CON_STATUS_REG_DATA_SCALE_MASK      (0x6000U)
#define PCIE_CON_STATUS_REG_DATA_SCALE_SHIFT     (13U)
#define PCIE_CON_STATUS_REG_DATA_SCALE(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_DATA_SCALE_SHIFT)) & PCIE_CON_STATUS_REG_DATA_SCALE_MASK)
#define PCIE_CON_STATUS_REG_PME_STATUS_MASK      (0x8000U)
#define PCIE_CON_STATUS_REG_PME_STATUS_SHIFT     (15U)
#define PCIE_CON_STATUS_REG_RSVDP_16_MASK        (0x3F0000U)
#define PCIE_CON_STATUS_REG_RSVDP_16_SHIFT       (16U)
#define PCIE_CON_STATUS_REG_RSVDP_16(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_RSVDP_16_SHIFT)) & PCIE_CON_STATUS_REG_RSVDP_16_MASK)
#define PCIE_CON_STATUS_REG_B2_B3_SUPPORT_MASK   (0x400000U)
#define PCIE_CON_STATUS_REG_B2_B3_SUPPORT_SHIFT  (22U)
#define PCIE_CON_STATUS_REG_BUS_PWR_CLK_CON_EN_MASK (0x800000U)
#define PCIE_CON_STATUS_REG_BUS_PWR_CLK_CON_EN_SHIFT (23U)
#define PCIE_CON_STATUS_REG_DATA_REG_ADD_INFO_MASK (0xFF000000U)
#define PCIE_CON_STATUS_REG_DATA_REG_ADD_INFO_SHIFT (24U)
#define PCIE_CON_STATUS_REG_DATA_REG_ADD_INFO(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_DATA_REG_ADD_INFO_SHIFT)) & PCIE_CON_STATUS_REG_DATA_REG_ADD_INFO_MASK)
/*! @} */

/*! @name PCI_MSI_CAP_ID_NEXT_CTRL_REG - MSI Capability ID, Next Pointer, Capability/Control Registers. */
/*! @{ */
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_ID_MASK (0xFFU)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_ID_SHIFT (0U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_ID_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_ID_MASK)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_NEXT_OFFSET_MASK (0xFF00U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_NEXT_OFFSET_SHIFT (8U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_NEXT_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_NEXT_OFFSET_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_NEXT_OFFSET_MASK)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_ENABLE_MASK (0x10000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_ENABLE_SHIFT (16U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_CAP_MASK (0xE0000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_CAP_SHIFT (17U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_CAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_CAP_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_CAP_MASK)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_EN_MASK (0x700000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_EN_SHIFT (20U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_EN_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_EN_MASK)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_64_BIT_ADDR_CAP_MASK (0x800000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_64_BIT_ADDR_CAP_SHIFT (23U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_PVM_SUPPORT_MASK (0x1000000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_PVM_SUPPORT_SHIFT (24U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_CAP_MASK (0x2000000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_CAP_SHIFT (25U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_EN_MASK (0x4000000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_EN_SHIFT (26U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_RSVDP_27_MASK (0xF8000000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_RSVDP_27_SHIFT (27U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_RSVDP_27(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_RSVDP_27_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_RSVDP_27_MASK)
/*! @} */

/*! @name MSI_CAP_OFF_04H_REG - MSI Message Lower Address Register. */
/*! @{ */
#define PCIE_MSI_CAP_OFF_04H_REG_RSVDP_0_MASK    (0x3U)
#define PCIE_MSI_CAP_OFF_04H_REG_RSVDP_0_SHIFT   (0U)
#define PCIE_MSI_CAP_OFF_04H_REG_RSVDP_0(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_04H_REG_RSVDP_0_SHIFT)) & PCIE_MSI_CAP_OFF_04H_REG_RSVDP_0_MASK)
#define PCIE_MSI_CAP_OFF_04H_REG_PCI_MSI_CAP_OFF_04H_MASK (0xFFFFFFFCU)
#define PCIE_MSI_CAP_OFF_04H_REG_PCI_MSI_CAP_OFF_04H_SHIFT (2U)
#define PCIE_MSI_CAP_OFF_04H_REG_PCI_MSI_CAP_OFF_04H(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_04H_REG_PCI_MSI_CAP_OFF_04H_SHIFT)) & PCIE_MSI_CAP_OFF_04H_REG_PCI_MSI_CAP_OFF_04H_MASK)
/*! @} */

/*! @name MSI_CAP_OFF_08H_REG - For a 32 bit MSI Message, this register contains Data. */
/*! @{ */
#define PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_08H_MASK (0xFFFFU)
#define PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_08H_SHIFT (0U)
#define PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_08H(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_08H_SHIFT)) & PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_08H_MASK)
#define PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_0AH_MASK (0xFFFF0000U)
#define PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_0AH_SHIFT (16U)
#define PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_0AH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_0AH_SHIFT)) & PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_0AH_MASK)
/*! @} */

/*! @name MSI_CAP_OFF_0CH_REG - For a 64 bit MSI Message, this register contains Data. */
/*! @{ */
#define PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0CH_MASK (0xFFFFU)
#define PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0CH_SHIFT (0U)
#define PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0CH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0CH_SHIFT)) & PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0CH_MASK)
#define PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0EH_MASK (0xFFFF0000U)
#define PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0EH_SHIFT (16U)
#define PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0EH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0EH_SHIFT)) & PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0EH_MASK)
/*! @} */

/*! @name MSI_CAP_OFF_10H_REG - Used for MSI when Vector Masking Capable. */
/*! @{ */
#define PCIE_MSI_CAP_OFF_10H_REG_PCI_MSI_CAP_OFF_10H_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CAP_OFF_10H_REG_PCI_MSI_CAP_OFF_10H_SHIFT (0U)
#define PCIE_MSI_CAP_OFF_10H_REG_PCI_MSI_CAP_OFF_10H(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_10H_REG_PCI_MSI_CAP_OFF_10H_SHIFT)) & PCIE_MSI_CAP_OFF_10H_REG_PCI_MSI_CAP_OFF_10H_MASK)
/*! @} */

/*! @name MSI_CAP_OFF_14H_REG - Used for MSI 64 bit messaging when Vector Masking Capable. */
/*! @{ */
#define PCIE_MSI_CAP_OFF_14H_REG_PCI_MSI_CAP_OFF_14H_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CAP_OFF_14H_REG_PCI_MSI_CAP_OFF_14H_SHIFT (0U)
#define PCIE_MSI_CAP_OFF_14H_REG_PCI_MSI_CAP_OFF_14H(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_14H_REG_PCI_MSI_CAP_OFF_14H_SHIFT)) & PCIE_MSI_CAP_OFF_14H_REG_PCI_MSI_CAP_OFF_14H_MASK)
/*! @} */

/*! @name PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG - PCI Express Capabilities, ID, Next Pointer Register. */
/*! @{ */
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_ID_MASK (0xFFU)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_ID_SHIFT (0U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_ID_SHIFT)) & PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_ID_MASK)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_NEXT_PTR_MASK (0xFF00U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_NEXT_PTR_SHIFT (8U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_NEXT_PTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_NEXT_PTR_SHIFT)) & PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_NEXT_PTR_MASK)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_REG_MASK (0xF0000U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_REG_SHIFT (16U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_REG_SHIFT)) & PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_REG_MASK)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_DEV_PORT_TYPE_MASK (0xF00000U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_DEV_PORT_TYPE_SHIFT (20U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_DEV_PORT_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_DEV_PORT_TYPE_SHIFT)) & PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_DEV_PORT_TYPE_MASK)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_SLOT_IMP_MASK (0x1000000U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_SLOT_IMP_SHIFT (24U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_INT_MSG_NUM_MASK (0x3E000000U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_INT_MSG_NUM_SHIFT (25U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_INT_MSG_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_INT_MSG_NUM_SHIFT)) & PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_INT_MSG_NUM_MASK)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVD_MASK (0x40000000U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVD_SHIFT (30U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVDP_31_MASK (0x80000000U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVDP_31_SHIFT (31U)
/*! @} */

/*! @name DEVICE_CAPABILITIES_REG - Device Capabilities Register. */
/*! @{ */
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_MAX_PAYLOAD_SIZE_MASK (0x7U)
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_MAX_PAYLOAD_SIZE_SHIFT (0U)
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_MAX_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_MAX_PAYLOAD_SIZE_SHIFT)) & PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_MAX_PAYLOAD_SIZE_MASK)
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_PHANTOM_FUNC_SUPPORT_MASK (0x18U)
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_PHANTOM_FUNC_SUPPORT_SHIFT (3U)
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_PHANTOM_FUNC_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_PHANTOM_FUNC_SUPPORT_SHIFT)) & PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_PHANTOM_FUNC_SUPPORT_MASK)
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_EXT_TAG_SUPP_MASK (0x20U)
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_EXT_TAG_SUPP_SHIFT (5U)
#define PCIE_DEVICE_CAPABILITIES_REG_RSVDP_6_MASK (0x7FC0U)
#define PCIE_DEVICE_CAPABILITIES_REG_RSVDP_6_SHIFT (6U)
#define PCIE_DEVICE_CAPABILITIES_REG_RSVDP_6(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES_REG_RSVDP_6_SHIFT)) & PCIE_DEVICE_CAPABILITIES_REG_RSVDP_6_MASK)
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_ROLE_BASED_ERR_REPORT_MASK (0x8000U)
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_ROLE_BASED_ERR_REPORT_SHIFT (15U)
#define PCIE_DEVICE_CAPABILITIES_REG_RSVDP_16_MASK (0xFFFF0000U)
#define PCIE_DEVICE_CAPABILITIES_REG_RSVDP_16_SHIFT (16U)
#define PCIE_DEVICE_CAPABILITIES_REG_RSVDP_16(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES_REG_RSVDP_16_SHIFT)) & PCIE_DEVICE_CAPABILITIES_REG_RSVDP_16_MASK)
/*! @} */

/*! @name DEVICE_CONTROL_DEVICE_STATUS - Device Control and Status Register. */
/*! @{ */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_REPORT_EN_MASK (0x1U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_REPORT_EN_SHIFT (0U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_REPORT_EN_MASK (0x2U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_REPORT_EN_SHIFT (1U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_REPORT_EN_MASK (0x4U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_REPORT_EN_SHIFT (2U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORT_REQ_REP_EN_MASK (0x8U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORT_REQ_REP_EN_SHIFT (3U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_REL_ORDER_MASK (0x10U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_REL_ORDER_SHIFT (4U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_PAYLOAD_SIZE_CS_MASK (0xE0U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_PAYLOAD_SIZE_CS_SHIFT (5U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_PAYLOAD_SIZE_CS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_PAYLOAD_SIZE_CS_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_PAYLOAD_SIZE_CS_MASK)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EXT_TAG_EN_MASK (0x100U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EXT_TAG_EN_SHIFT (8U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_PHANTOM_FUNC_EN_MASK (0x200U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_PHANTOM_FUNC_EN_SHIFT (9U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_PM_EN_MASK (0x400U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_PM_EN_SHIFT (10U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_NO_SNOOP_MASK (0x800U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_NO_SNOOP_SHIFT (11U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_READ_REQ_SIZE_MASK (0x7000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_READ_REQ_SIZE_SHIFT (12U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_READ_REQ_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_READ_REQ_SIZE_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_READ_REQ_SIZE_MASK)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_INITIATE_FLR_MASK (0x8000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_INITIATE_FLR_SHIFT (15U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_DETECTED_MASK (0x10000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_DETECTED_SHIFT (16U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_DETECTED_MASK (0x20000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_DETECTED_SHIFT (17U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_DETECTED_MASK (0x40000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_DETECTED_SHIFT (18U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORTED_REQ_DETECTED_MASK (0x80000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORTED_REQ_DETECTED_SHIFT (19U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_DETECTED_MASK (0x100000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_DETECTED_SHIFT (20U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_TRANS_PENDING_MASK (0x200000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_TRANS_PENDING_SHIFT (21U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_RSVDP_22_MASK (0xFFC00000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_RSVDP_22_SHIFT (22U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_RSVDP_22(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_RSVDP_22_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_RSVDP_22_MASK)
/*! @} */

/*! @name LINK_CAPABILITIES_REG - Link Capabilities Register. */
/*! @{ */
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED_MASK (0xFU)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED_SHIFT (0U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED_MASK)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_WIDTH_MASK (0x3F0U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_WIDTH_SHIFT (4U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_WIDTH_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_WIDTH_MASK)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT_MASK (0xC00U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT_SHIFT (10U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT_MASK)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L0S_EXIT_LATENCY_MASK (0x7000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L0S_EXIT_LATENCY_SHIFT (12U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L0S_EXIT_LATENCY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L0S_EXIT_LATENCY_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L0S_EXIT_LATENCY_MASK)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L1_EXIT_LATENCY_MASK (0x38000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L1_EXIT_LATENCY_SHIFT (15U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L1_EXIT_LATENCY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L1_EXIT_LATENCY_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L1_EXIT_LATENCY_MASK)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_CLOCK_POWER_MAN_MASK (0x40000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_CLOCK_POWER_MAN_SHIFT (18U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_SURPRISE_DOWN_ERR_REP_CAP_MASK (0x80000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_SURPRISE_DOWN_ERR_REP_CAP_SHIFT (19U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_DLL_ACTIVE_REP_CAP_MASK (0x100000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_DLL_ACTIVE_REP_CAP_SHIFT (20U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_LINK_BW_NOT_CAP_MASK (0x200000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_LINK_BW_NOT_CAP_SHIFT (21U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ASPM_OPT_COMPLIANCE_MASK (0x400000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ASPM_OPT_COMPLIANCE_SHIFT (22U)
#define PCIE_LINK_CAPABILITIES_REG_RSVDP_23_MASK (0x800000U)
#define PCIE_LINK_CAPABILITIES_REG_RSVDP_23_SHIFT (23U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_PORT_NUM_MASK (0xFF000000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_PORT_NUM_SHIFT (24U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_PORT_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_PORT_NUM_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_PORT_NUM_MASK)
/*! @} */

/*! @name LINK_CONTROL_LINK_STATUS_REG - Link Control and Status Register. */
/*! @{ */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL_MASK (0x3U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL_SHIFT (0U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL_MASK)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_2_MASK (0x4U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_2_SHIFT (2U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RCB_MASK (0x8U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RCB_SHIFT (3U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_DISABLE_MASK (0x10U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_DISABLE_SHIFT (4U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RETRAIN_LINK_MASK (0x20U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RETRAIN_LINK_SHIFT (5U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_COMMON_CLK_CONFIG_MASK (0x40U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_COMMON_CLK_CONFIG_SHIFT (6U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EXTENDED_SYNCH_MASK (0x80U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EXTENDED_SYNCH_SHIFT (7U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EN_CLK_POWER_MAN_MASK (0x100U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EN_CLK_POWER_MAN_SHIFT (8U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_HW_AUTO_WIDTH_DISABLE_MASK (0x200U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_HW_AUTO_WIDTH_DISABLE_SHIFT (9U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_INT_EN_MASK (0x400U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_INT_EN_SHIFT (10U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_INT_EN_MASK (0x800U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_INT_EN_SHIFT (11U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_12_MASK (0x3000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_12_SHIFT (12U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_12(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_12_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_12_MASK)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DRS_SIGNALING_CONTROL_MASK (0xC000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DRS_SIGNALING_CONTROL_SHIFT (14U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DRS_SIGNALING_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DRS_SIGNALING_CONTROL_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DRS_SIGNALING_CONTROL_MASK)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED_MASK (0xF0000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED_SHIFT (16U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED_MASK)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_NEGO_LINK_WIDTH_MASK (0x3F00000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_NEGO_LINK_WIDTH_SHIFT (20U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_NEGO_LINK_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_NEGO_LINK_WIDTH_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_NEGO_LINK_WIDTH_MASK)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_26_MASK (0x4000000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_26_SHIFT (26U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_TRAINING_MASK (0x8000000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_TRAINING_SHIFT (27U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_SLOT_CLK_CONFIG_MASK (0x10000000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_SLOT_CLK_CONFIG_SHIFT (28U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DLL_ACTIVE_MASK (0x20000000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DLL_ACTIVE_SHIFT (29U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_STATUS_MASK (0x40000000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_STATUS_SHIFT (30U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_STATUS_MASK (0x80000000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_STATUS_SHIFT (31U)
/*! @} */

/*! @name SLOT_CAPABILITIES_REG - Slot Capabilities Register. */
/*! @{ */
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR_BUTTON_MASK (0x1U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR_BUTTON_SHIFT (0U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_CONTROLLER_MASK (0x2U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_CONTROLLER_SHIFT (1U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_MRL_SENSOR_MASK (0x4U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_MRL_SENSOR_SHIFT (2U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR_MASK (0x8U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR_SHIFT (3U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_INDICATOR_MASK (0x10U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_INDICATOR_SHIFT (4U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_SURPRISE_MASK (0x20U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_SURPRISE_SHIFT (5U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_CAPABLE_MASK (0x40U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_CAPABLE_SHIFT (6U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_VALUE_MASK (0x7F80U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_VALUE_SHIFT (7U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_VALUE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_VALUE_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_VALUE_MASK)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_SCALE_MASK (0x18000U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_SCALE_SHIFT (15U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_SCALE_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_SCALE_MASK)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ELECTROMECH_INTERLOCK_MASK (0x20000U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ELECTROMECH_INTERLOCK_SHIFT (17U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_NO_CMD_CPL_SUPPORT_MASK (0x40000U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_NO_CMD_CPL_SUPPORT_SHIFT (18U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_PHY_SLOT_NUM_MASK (0xFFF80000U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_PHY_SLOT_NUM_SHIFT (19U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_PHY_SLOT_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_PHY_SLOT_NUM_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_PHY_SLOT_NUM_MASK)
/*! @} */

/*! @name SLOT_CONTROL_SLOT_STATUS - Slot Control and Status Register. */
/*! @{ */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED_EN_MASK (0x1U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED_EN_SHIFT (0U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED_EN_MASK (0x2U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED_EN_SHIFT (1U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED_EN_MASK (0x4U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED_EN_SHIFT (2U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_CHANGE_EN_MASK (0x8U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_CHANGE_EN_SHIFT (3U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPL_INT_EN_MASK (0x10U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPL_INT_EN_SHIFT (4U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_HOT_PLUG_INT_EN_MASK (0x20U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_HOT_PLUG_INT_EN_SHIFT (5U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_INDICATOR_CTRL_MASK (0xC0U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_INDICATOR_CTRL_SHIFT (6U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_INDICATOR_CTRL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_INDICATOR_CTRL_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_INDICATOR_CTRL_MASK)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_INDICATOR_CTRL_MASK (0x300U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_INDICATOR_CTRL_SHIFT (8U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_INDICATOR_CTRL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_INDICATOR_CTRL_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_INDICATOR_CTRL_MASK)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_CONTROLLER_CTRL_MASK (0x400U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_CONTROLLER_CTRL_SHIFT (10U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_CTRL_MASK (0x800U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_CTRL_SHIFT (11U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED_EN_MASK (0x1000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED_EN_SHIFT (12U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_13_MASK (0xE000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_13_SHIFT (13U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_13(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_13_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_13_MASK)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED_MASK (0x10000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED_SHIFT (16U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED_MASK (0x20000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED_SHIFT (17U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED_MASK (0x40000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED_SHIFT (18U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECTED_CHANGED_MASK (0x80000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECTED_CHANGED_SHIFT (19U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPLD_MASK (0x100000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPLD_SHIFT (20U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_STATE_MASK (0x200000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_STATE_SHIFT (21U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_STATE_MASK (0x400000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_STATE_SHIFT (22U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_STATUS_MASK (0x800000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_STATUS_SHIFT (23U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED_MASK (0x1000000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED_SHIFT (24U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_25_MASK (0xFE000000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_25_SHIFT (25U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_25(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_25_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_25_MASK)
/*! @} */

/*! @name ROOT_CONTROL_ROOT_CAPABILITIES_REG - Root Control and Capabilities Register. */
/*! @{ */
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_CORR_ERR_EN_MASK (0x1U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_CORR_ERR_EN_SHIFT (0U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_NON_FATAL_ERR_EN_MASK (0x2U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_NON_FATAL_ERR_EN_SHIFT (1U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_FATAL_ERR_EN_MASK (0x4U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_FATAL_ERR_EN_SHIFT (2U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_PME_INT_EN_MASK (0x8U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_PME_INT_EN_SHIFT (3U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY_EN_MASK (0x10U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY_EN_SHIFT (4U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_5_MASK (0xFFE0U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_5_SHIFT (5U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_5(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_5_SHIFT)) & PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_5_MASK)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY_MASK (0x10000U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY_SHIFT (16U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_17_MASK (0xFFFE0000U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_17_SHIFT (17U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_17(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_17_SHIFT)) & PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_17_MASK)
/*! @} */

/*! @name ROOT_STATUS_REG - Root Status Register. */
/*! @{ */
#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_REQ_ID_MASK (0xFFFFU)
#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_REQ_ID_SHIFT (0U)
#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_REQ_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_REQ_ID_SHIFT)) & PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_REQ_ID_MASK)
#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_STATUS_MASK (0x10000U)
#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_STATUS_SHIFT (16U)
#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_PENDING_MASK (0x20000U)
#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_PENDING_SHIFT (17U)
#define PCIE_ROOT_STATUS_REG_RSVDP_18_MASK       (0xFFFC0000U)
#define PCIE_ROOT_STATUS_REG_RSVDP_18_SHIFT      (18U)
#define PCIE_ROOT_STATUS_REG_RSVDP_18(x)         (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_STATUS_REG_RSVDP_18_SHIFT)) & PCIE_ROOT_STATUS_REG_RSVDP_18_MASK)
/*! @} */

/*! @name DEVICE_CAPABILITIES2_REG - Device Capabilities 2 Register. */
/*! @{ */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_RANGE_MASK (0xFU)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_RANGE_SHIFT (0U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_RANGE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_RANGE_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_RANGE_MASK)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_SUPPORT_MASK (0x10U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_SUPPORT_SHIFT (4U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_MASK (0x20U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_SHIFT (5U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ATOMIC_ROUTING_SUPP_MASK (0x40U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ATOMIC_ROUTING_SUPP_SHIFT (6U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_32_ATOMIC_CPL_SUPP_MASK (0x80U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_32_ATOMIC_CPL_SUPP_SHIFT (7U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_64_ATOMIC_CPL_SUPP_MASK (0x100U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_64_ATOMIC_CPL_SUPP_SHIFT (8U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_128_CAS_CPL_SUPP_MASK (0x200U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_128_CAS_CPL_SUPP_SHIFT (9U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_NO_RO_EN_PR2PR_PAR_MASK (0x400U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_NO_RO_EN_PR2PR_PAR_SHIFT (10U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_LTR_SUPP_MASK (0x800U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_LTR_SUPP_SHIFT (11U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_0_MASK (0x1000U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_0_SHIFT (12U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_1_MASK (0x2000U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_1_SHIFT (13U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_COMP_SUPPORT_MASK (0x10000U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_COMP_SUPPORT_SHIFT (16U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_REQ_SUPPORT_MASK (0x20000U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_REQ_SUPPORT_SHIFT (17U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_OBFF_SUPPORT_MASK (0xC0000U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_OBFF_SUPPORT_SHIFT (18U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_OBFF_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_OBFF_SUPPORT_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_OBFF_SUPPORT_MASK)
#define PCIE_DEVICE_CAPABILITIES2_REG_RSVDP_24_MASK (0x7F000000U)
#define PCIE_DEVICE_CAPABILITIES2_REG_RSVDP_24_SHIFT (24U)
#define PCIE_DEVICE_CAPABILITIES2_REG_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_RSVDP_24_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_RSVDP_24_MASK)
/*! @} */

/*! @name DEVICE_CONTROL2_DEVICE_STATUS2_REG - Device Control 2 and Status 2 Register. */
/*! @{ */
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_VALUE_MASK (0xFU)
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_VALUE_SHIFT (0U)
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_VALUE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_VALUE_SHIFT)) & PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_VALUE_MASK)
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_MASK (0x10U)
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_SHIFT (4U)
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_CS_MASK (0x20U)
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_CS_SHIFT (5U)
/*! @} */

/*! @name LINK_CAPABILITIES2_REG - Link Capabilities 2 Register. */
/*! @{ */
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_0_MASK (0x1U)
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_0_SHIFT (0U)
#define PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR_MASK (0xFEU)
#define PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR_SHIFT (1U)
#define PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR_SHIFT)) & PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR_MASK)
#define PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_CROSS_LINK_SUPPORT_MASK (0x100U)
#define PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_CROSS_LINK_SUPPORT_SHIFT (8U)
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_9_MASK (0x7FFE00U)
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_9_SHIFT (9U)
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_9(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES2_REG_RSVDP_9_SHIFT)) & PCIE_LINK_CAPABILITIES2_REG_RSVDP_9_MASK)
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_25_MASK (0x7E000000U)
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_25_SHIFT (25U)
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_25(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES2_REG_RSVDP_25_SHIFT)) & PCIE_LINK_CAPABILITIES2_REG_RSVDP_25_MASK)
/*! @} */

/*! @name LINK_CONTROL2_LINK_STATUS2_REG - Link Control 2 and Status 2 Register. */
/*! @{ */
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TARGET_LINK_SPEED_MASK (0xFU)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TARGET_LINK_SPEED_SHIFT (0U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TARGET_LINK_SPEED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TARGET_LINK_SPEED_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TARGET_LINK_SPEED_MASK)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_COMPLIANCE_MASK (0x10U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_COMPLIANCE_SHIFT (4U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_HW_AUTO_SPEED_DISABLE_MASK (0x20U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_HW_AUTO_SPEED_DISABLE_SHIFT (5U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_SEL_DEEMPHASIS_MASK (0x40U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_SEL_DEEMPHASIS_SHIFT (6U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TX_MARGIN_MASK (0x380U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TX_MARGIN_SHIFT (7U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TX_MARGIN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TX_MARGIN_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TX_MARGIN_MASK)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_MODIFIED_COMPLIANCE_MASK (0x400U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_MODIFIED_COMPLIANCE_SHIFT (10U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_SOS_MASK (0x800U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_SOS_SHIFT (11U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_PRESET_MASK (0xF000U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_PRESET_SHIFT (12U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_PRESET(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_PRESET_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_PRESET_MASK)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_CURR_DEEMPHASIS_MASK (0x10000U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_CURR_DEEMPHASIS_SHIFT (16U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_RSVDP_26_MASK (0xC000000U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_RSVDP_26_SHIFT (26U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_RSVDP_26(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_RSVDP_26_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_RSVDP_26_MASK)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DOWNSTREAM_COMPO_PRESENCE_MASK (0x70000000U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DOWNSTREAM_COMPO_PRESENCE_SHIFT (28U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DOWNSTREAM_COMPO_PRESENCE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DOWNSTREAM_COMPO_PRESENCE_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DOWNSTREAM_COMPO_PRESENCE_MASK)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DRS_MESSAGE_RECEIVED_MASK (0x80000000U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DRS_MESSAGE_RECEIVED_SHIFT (31U)
/*! @} */

/*! @name AER_EXT_CAP_HDR_OFF - Advanced Error Reporting Extended Capability Header. */
/*! @{ */
#define PCIE_AER_EXT_CAP_HDR_OFF_CAP_ID_MASK     (0xFFFFU)
#define PCIE_AER_EXT_CAP_HDR_OFF_CAP_ID_SHIFT    (0U)
#define PCIE_AER_EXT_CAP_HDR_OFF_CAP_ID(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_AER_EXT_CAP_HDR_OFF_CAP_ID_SHIFT)) & PCIE_AER_EXT_CAP_HDR_OFF_CAP_ID_MASK)
#define PCIE_AER_EXT_CAP_HDR_OFF_CAP_VERSION_MASK (0xF0000U)
#define PCIE_AER_EXT_CAP_HDR_OFF_CAP_VERSION_SHIFT (16U)
#define PCIE_AER_EXT_CAP_HDR_OFF_CAP_VERSION(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_AER_EXT_CAP_HDR_OFF_CAP_VERSION_SHIFT)) & PCIE_AER_EXT_CAP_HDR_OFF_CAP_VERSION_MASK)
#define PCIE_AER_EXT_CAP_HDR_OFF_NEXT_OFFSET_MASK (0xFFF00000U)
#define PCIE_AER_EXT_CAP_HDR_OFF_NEXT_OFFSET_SHIFT (20U)
#define PCIE_AER_EXT_CAP_HDR_OFF_NEXT_OFFSET(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_AER_EXT_CAP_HDR_OFF_NEXT_OFFSET_SHIFT)) & PCIE_AER_EXT_CAP_HDR_OFF_NEXT_OFFSET_MASK)
/*! @} */

/*! @name UNCORR_ERR_STATUS_OFF - Uncorrectable Error Status Register. */
/*! @{ */
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_0_MASK  (0xFU)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_0_SHIFT (0U)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_0(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_0_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_0_MASK)
#define PCIE_UNCORR_ERR_STATUS_OFF_DL_PROTOCOL_ERR_STATUS_MASK (0x10U)
#define PCIE_UNCORR_ERR_STATUS_OFF_DL_PROTOCOL_ERR_STATUS_SHIFT (4U)
#define PCIE_UNCORR_ERR_STATUS_OFF_SURPRISE_DOWN_ERR_STATUS_MASK (0x20U)
#define PCIE_UNCORR_ERR_STATUS_OFF_SURPRISE_DOWN_ERR_STATUS_SHIFT (5U)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_6_MASK  (0xFC0U)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_6_SHIFT (6U)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_6(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_6_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_6_MASK)
#define PCIE_UNCORR_ERR_STATUS_OFF_POIS_TLP_ERR_STATUS_MASK (0x1000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_POIS_TLP_ERR_STATUS_SHIFT (12U)
#define PCIE_UNCORR_ERR_STATUS_OFF_FC_PROTOCOL_ERR_STATUS_MASK (0x2000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_FC_PROTOCOL_ERR_STATUS_SHIFT (13U)
#define PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_TIMEOUT_ERR_STATUS_MASK (0x4000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_TIMEOUT_ERR_STATUS_SHIFT (14U)
#define PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_ABORT_ERR_STATUS_MASK (0x8000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_ABORT_ERR_STATUS_SHIFT (15U)
#define PCIE_UNCORR_ERR_STATUS_OFF_UNEXP_CMPLT_ERR_STATUS_MASK (0x10000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_UNEXP_CMPLT_ERR_STATUS_SHIFT (16U)
#define PCIE_UNCORR_ERR_STATUS_OFF_REC_OVERFLOW_ERR_STATUS_MASK (0x20000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_REC_OVERFLOW_ERR_STATUS_SHIFT (17U)
#define PCIE_UNCORR_ERR_STATUS_OFF_MALF_TLP_ERR_STATUS_MASK (0x40000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_MALF_TLP_ERR_STATUS_SHIFT (18U)
#define PCIE_UNCORR_ERR_STATUS_OFF_ECRC_ERR_STATUS_MASK (0x80000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_ECRC_ERR_STATUS_SHIFT (19U)
#define PCIE_UNCORR_ERR_STATUS_OFF_UNSUPPORTED_REQ_ERR_STATUS_MASK (0x100000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_UNSUPPORTED_REQ_ERR_STATUS_SHIFT (20U)
#define PCIE_UNCORR_ERR_STATUS_OFF_INTERNAL_ERR_STATUS_MASK (0x400000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_INTERNAL_ERR_STATUS_SHIFT (22U)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_23_MASK (0x800000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_23_SHIFT (23U)
#define PCIE_UNCORR_ERR_STATUS_OFF_TLP_PRFX_BLOCKED_ERR_STATUS_MASK (0x2000000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_TLP_PRFX_BLOCKED_ERR_STATUS_SHIFT (25U)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_26_MASK (0xFC000000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_26_SHIFT (26U)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_26(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_26_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_26_MASK)
/*! @} */

/*! @name UNCORR_ERR_MASK_OFF - Uncorrectable Error Mask Register. */
/*! @{ */
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_0_MASK    (0xFU)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_0_SHIFT   (0U)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_0(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_RSVDP_0_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_RSVDP_0_MASK)
#define PCIE_UNCORR_ERR_MASK_OFF_DL_PROTOCOL_ERR_MASK_MASK (0x10U)
#define PCIE_UNCORR_ERR_MASK_OFF_DL_PROTOCOL_ERR_MASK_SHIFT (4U)
#define PCIE_UNCORR_ERR_MASK_OFF_SURPRISE_DOWN_ERR_MASK_MASK (0x20U)
#define PCIE_UNCORR_ERR_MASK_OFF_SURPRISE_DOWN_ERR_MASK_SHIFT (5U)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_6_MASK    (0xFC0U)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_6_SHIFT   (6U)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_6(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_RSVDP_6_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_RSVDP_6_MASK)
#define PCIE_UNCORR_ERR_MASK_OFF_POIS_TLP_ERR_MASK_MASK (0x1000U)
#define PCIE_UNCORR_ERR_MASK_OFF_POIS_TLP_ERR_MASK_SHIFT (12U)
#define PCIE_UNCORR_ERR_MASK_OFF_FC_PROTOCOL_ERR_MASK_MASK (0x2000U)
#define PCIE_UNCORR_ERR_MASK_OFF_FC_PROTOCOL_ERR_MASK_SHIFT (13U)
#define PCIE_UNCORR_ERR_MASK_OFF_CMPLT_TIMEOUT_ERR_MASK_MASK (0x4000U)
#define PCIE_UNCORR_ERR_MASK_OFF_CMPLT_TIMEOUT_ERR_MASK_SHIFT (14U)
#define PCIE_UNCORR_ERR_MASK_OFF_CMPLT_ABORT_ERR_MASK_MASK (0x8000U)
#define PCIE_UNCORR_ERR_MASK_OFF_CMPLT_ABORT_ERR_MASK_SHIFT (15U)
#define PCIE_UNCORR_ERR_MASK_OFF_UNEXP_CMPLT_ERR_MASK_MASK (0x10000U)
#define PCIE_UNCORR_ERR_MASK_OFF_UNEXP_CMPLT_ERR_MASK_SHIFT (16U)
#define PCIE_UNCORR_ERR_MASK_OFF_REC_OVERFLOW_ERR_MASK_MASK (0x20000U)
#define PCIE_UNCORR_ERR_MASK_OFF_REC_OVERFLOW_ERR_MASK_SHIFT (17U)
#define PCIE_UNCORR_ERR_MASK_OFF_MALF_TLP_ERR_MASK_MASK (0x40000U)
#define PCIE_UNCORR_ERR_MASK_OFF_MALF_TLP_ERR_MASK_SHIFT (18U)
#define PCIE_UNCORR_ERR_MASK_OFF_ECRC_ERR_MASK_MASK (0x80000U)
#define PCIE_UNCORR_ERR_MASK_OFF_ECRC_ERR_MASK_SHIFT (19U)
#define PCIE_UNCORR_ERR_MASK_OFF_UNSUPPORTED_REQ_ERR_MASK_MASK (0x100000U)
#define PCIE_UNCORR_ERR_MASK_OFF_UNSUPPORTED_REQ_ERR_MASK_SHIFT (20U)
#define PCIE_UNCORR_ERR_MASK_OFF_INTERNAL_ERR_MASK_MASK (0x400000U)
#define PCIE_UNCORR_ERR_MASK_OFF_INTERNAL_ERR_MASK_SHIFT (22U)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_23_MASK   (0x800000U)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_23_SHIFT  (23U)
#define PCIE_UNCORR_ERR_MASK_OFF_ATOMIC_EGRESS_BLOCKED_ERR_MASK_MASK (0x1000000U)
#define PCIE_UNCORR_ERR_MASK_OFF_ATOMIC_EGRESS_BLOCKED_ERR_MASK_SHIFT (24U)
#define PCIE_UNCORR_ERR_MASK_OFF_TLP_PRFX_BLOCKED_ERR_MASK_MASK (0x2000000U)
#define PCIE_UNCORR_ERR_MASK_OFF_TLP_PRFX_BLOCKED_ERR_MASK_SHIFT (25U)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_26_MASK   (0xFC000000U)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_26_SHIFT  (26U)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_26(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_RSVDP_26_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_RSVDP_26_MASK)
/*! @} */

/*! @name UNCORR_ERR_SEV_OFF - Uncorrectable Error Severity Register. */
/*! @{ */
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_0_MASK     (0xFU)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_0_SHIFT    (0U)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_0(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_RSVDP_0_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_RSVDP_0_MASK)
#define PCIE_UNCORR_ERR_SEV_OFF_DL_PROTOCOL_ERR_SEVERITY_MASK (0x10U)
#define PCIE_UNCORR_ERR_SEV_OFF_DL_PROTOCOL_ERR_SEVERITY_SHIFT (4U)
#define PCIE_UNCORR_ERR_SEV_OFF_SURPRISE_DOWN_ERR_SVRITY_MASK (0x20U)
#define PCIE_UNCORR_ERR_SEV_OFF_SURPRISE_DOWN_ERR_SVRITY_SHIFT (5U)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_6_MASK     (0xFC0U)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_6_SHIFT    (6U)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_6(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_RSVDP_6_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_RSVDP_6_MASK)
#define PCIE_UNCORR_ERR_SEV_OFF_POIS_TLP_ERR_SEVERITY_MASK (0x1000U)
#define PCIE_UNCORR_ERR_SEV_OFF_POIS_TLP_ERR_SEVERITY_SHIFT (12U)
#define PCIE_UNCORR_ERR_SEV_OFF_FC_PROTOCOL_ERR_SEVERITY_MASK (0x2000U)
#define PCIE_UNCORR_ERR_SEV_OFF_FC_PROTOCOL_ERR_SEVERITY_SHIFT (13U)
#define PCIE_UNCORR_ERR_SEV_OFF_CMPLT_TIMEOUT_ERR_SEVERITY_MASK (0x4000U)
#define PCIE_UNCORR_ERR_SEV_OFF_CMPLT_TIMEOUT_ERR_SEVERITY_SHIFT (14U)
#define PCIE_UNCORR_ERR_SEV_OFF_CMPLT_ABORT_ERR_SEVERITY_MASK (0x8000U)
#define PCIE_UNCORR_ERR_SEV_OFF_CMPLT_ABORT_ERR_SEVERITY_SHIFT (15U)
#define PCIE_UNCORR_ERR_SEV_OFF_UNEXP_CMPLT_ERR_SEVERITY_MASK (0x10000U)
#define PCIE_UNCORR_ERR_SEV_OFF_UNEXP_CMPLT_ERR_SEVERITY_SHIFT (16U)
#define PCIE_UNCORR_ERR_SEV_OFF_REC_OVERFLOW_ERR_SEVERITY_MASK (0x20000U)
#define PCIE_UNCORR_ERR_SEV_OFF_REC_OVERFLOW_ERR_SEVERITY_SHIFT (17U)
#define PCIE_UNCORR_ERR_SEV_OFF_MALF_TLP_ERR_SEVERITY_MASK (0x40000U)
#define PCIE_UNCORR_ERR_SEV_OFF_MALF_TLP_ERR_SEVERITY_SHIFT (18U)
#define PCIE_UNCORR_ERR_SEV_OFF_ECRC_ERR_SEVERITY_MASK (0x80000U)
#define PCIE_UNCORR_ERR_SEV_OFF_ECRC_ERR_SEVERITY_SHIFT (19U)
#define PCIE_UNCORR_ERR_SEV_OFF_UNSUPPORTED_REQ_ERR_SEVERITY_MASK (0x100000U)
#define PCIE_UNCORR_ERR_SEV_OFF_UNSUPPORTED_REQ_ERR_SEVERITY_SHIFT (20U)
#define PCIE_UNCORR_ERR_SEV_OFF_INTERNAL_ERR_SEVERITY_MASK (0x400000U)
#define PCIE_UNCORR_ERR_SEV_OFF_INTERNAL_ERR_SEVERITY_SHIFT (22U)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_23_MASK    (0x800000U)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_23_SHIFT   (23U)
#define PCIE_UNCORR_ERR_SEV_OFF_ATOMIC_EGRESS_BLOCKED_ERR_SEVERITY_MASK (0x1000000U)
#define PCIE_UNCORR_ERR_SEV_OFF_ATOMIC_EGRESS_BLOCKED_ERR_SEVERITY_SHIFT (24U)
#define PCIE_UNCORR_ERR_SEV_OFF_TLP_PRFX_BLOCKED_ERR_SEVERITY_MASK (0x2000000U)
#define PCIE_UNCORR_ERR_SEV_OFF_TLP_PRFX_BLOCKED_ERR_SEVERITY_SHIFT (25U)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_26_MASK    (0xFC000000U)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_26_SHIFT   (26U)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_26(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_RSVDP_26_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_RSVDP_26_MASK)
/*! @} */

/*! @name CORR_ERR_STATUS_OFF - Correctable Error Status Register. */
/*! @{ */
#define PCIE_CORR_ERR_STATUS_OFF_RX_ERR_STATUS_MASK (0x1U)
#define PCIE_CORR_ERR_STATUS_OFF_RX_ERR_STATUS_SHIFT (0U)
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_1_MASK    (0x3EU)
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_1_SHIFT   (1U)
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_1(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_RSVDP_1_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_RSVDP_1_MASK)
#define PCIE_CORR_ERR_STATUS_OFF_BAD_TLP_STATUS_MASK (0x40U)
#define PCIE_CORR_ERR_STATUS_OFF_BAD_TLP_STATUS_SHIFT (6U)
#define PCIE_CORR_ERR_STATUS_OFF_BAD_DLLP_STATUS_MASK (0x80U)
#define PCIE_CORR_ERR_STATUS_OFF_BAD_DLLP_STATUS_SHIFT (7U)
#define PCIE_CORR_ERR_STATUS_OFF_REPLAY_NO_ROLEOVER_STATUS_MASK (0x100U)
#define PCIE_CORR_ERR_STATUS_OFF_REPLAY_NO_ROLEOVER_STATUS_SHIFT (8U)
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_9_MASK    (0xE00U)
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_9_SHIFT   (9U)
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_9(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_RSVDP_9_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_RSVDP_9_MASK)
#define PCIE_CORR_ERR_STATUS_OFF_RPL_TIMER_TIMEOUT_STATUS_MASK (0x1000U)
#define PCIE_CORR_ERR_STATUS_OFF_RPL_TIMER_TIMEOUT_STATUS_SHIFT (12U)
#define PCIE_CORR_ERR_STATUS_OFF_ADVISORY_NON_FATAL_ERR_STATUS_MASK (0x2000U)
#define PCIE_CORR_ERR_STATUS_OFF_ADVISORY_NON_FATAL_ERR_STATUS_SHIFT (13U)
#define PCIE_CORR_ERR_STATUS_OFF_CORRECTED_INT_ERR_STATUS_MASK (0x4000U)
#define PCIE_CORR_ERR_STATUS_OFF_CORRECTED_INT_ERR_STATUS_SHIFT (14U)
#define PCIE_CORR_ERR_STATUS_OFF_HEADER_LOG_OVERFLOW_STATUS_MASK (0x8000U)
#define PCIE_CORR_ERR_STATUS_OFF_HEADER_LOG_OVERFLOW_STATUS_SHIFT (15U)
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_16_MASK   (0xFFFF0000U)
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_16_SHIFT  (16U)
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_16(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_RSVDP_16_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_RSVDP_16_MASK)
/*! @} */

/*! @name CORR_ERR_MASK_OFF - Correctable Error Mask Register. */
/*! @{ */
#define PCIE_CORR_ERR_MASK_OFF_RX_ERR_MASK_MASK  (0x1U)
#define PCIE_CORR_ERR_MASK_OFF_RX_ERR_MASK_SHIFT (0U)
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_1_MASK      (0x3EU)
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_1_SHIFT     (1U)
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_1(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_RSVDP_1_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_RSVDP_1_MASK)
#define PCIE_CORR_ERR_MASK_OFF_BAD_TLP_MASK_MASK (0x40U)
#define PCIE_CORR_ERR_MASK_OFF_BAD_TLP_MASK_SHIFT (6U)
#define PCIE_CORR_ERR_MASK_OFF_BAD_DLLP_MASK_MASK (0x80U)
#define PCIE_CORR_ERR_MASK_OFF_BAD_DLLP_MASK_SHIFT (7U)
#define PCIE_CORR_ERR_MASK_OFF_REPLAY_NO_ROLEOVER_MASK_MASK (0x100U)
#define PCIE_CORR_ERR_MASK_OFF_REPLAY_NO_ROLEOVER_MASK_SHIFT (8U)
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_9_MASK      (0xE00U)
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_9_SHIFT     (9U)
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_9(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_RSVDP_9_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_RSVDP_9_MASK)
#define PCIE_CORR_ERR_MASK_OFF_RPL_TIMER_TIMEOUT_MASK_MASK (0x1000U)
#define PCIE_CORR_ERR_MASK_OFF_RPL_TIMER_TIMEOUT_MASK_SHIFT (12U)
#define PCIE_CORR_ERR_MASK_OFF_ADVISORY_NON_FATAL_ERR_MASK_MASK (0x2000U)
#define PCIE_CORR_ERR_MASK_OFF_ADVISORY_NON_FATAL_ERR_MASK_SHIFT (13U)
#define PCIE_CORR_ERR_MASK_OFF_CORRECTED_INT_ERR_MASK_MASK (0x4000U)
#define PCIE_CORR_ERR_MASK_OFF_CORRECTED_INT_ERR_MASK_SHIFT (14U)
#define PCIE_CORR_ERR_MASK_OFF_HEADER_LOG_OVERFLOW_MASK_MASK (0x8000U)
#define PCIE_CORR_ERR_MASK_OFF_HEADER_LOG_OVERFLOW_MASK_SHIFT (15U)
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_16_MASK     (0xFFFF0000U)
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_16_SHIFT    (16U)
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_16(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_RSVDP_16_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_RSVDP_16_MASK)
/*! @} */

/*! @name ADV_ERR_CAP_CTRL_OFF - Advanced Error Capabilities and Control Register. */
/*! @{ */
#define PCIE_ADV_ERR_CAP_CTRL_OFF_FIRST_ERR_POINTER_MASK (0x1FU)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_FIRST_ERR_POINTER_SHIFT (0U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_FIRST_ERR_POINTER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ADV_ERR_CAP_CTRL_OFF_FIRST_ERR_POINTER_SHIFT)) & PCIE_ADV_ERR_CAP_CTRL_OFF_FIRST_ERR_POINTER_MASK)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_CAP_MASK (0x20U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_CAP_SHIFT (5U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_EN_MASK (0x40U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_EN_SHIFT (6U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_CAP_MASK (0x80U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_CAP_SHIFT (7U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_EN_MASK (0x100U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_EN_SHIFT (8U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_CAP_MASK (0x200U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_CAP_SHIFT (9U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_EN_MASK (0x400U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_EN_SHIFT (10U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_RSVDP_12_MASK  (0xFFFFF000U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_RSVDP_12_SHIFT (12U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_RSVDP_12(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_ADV_ERR_CAP_CTRL_OFF_RSVDP_12_SHIFT)) & PCIE_ADV_ERR_CAP_CTRL_OFF_RSVDP_12_MASK)
/*! @} */

/*! @name HDR_LOG_0_OFF - Header Log Register 0. */
/*! @{ */
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FIRST_BYTE_MASK (0xFFU)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FIRST_BYTE_SHIFT (0U)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FIRST_BYTE_SHIFT)) & PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FIRST_BYTE_MASK)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_SECOND_BYTE_SHIFT (8U)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_0_OFF_FIRST_DWORD_SECOND_BYTE_SHIFT)) & PCIE_HDR_LOG_0_OFF_FIRST_DWORD_SECOND_BYTE_MASK)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_THIRD_BYTE_SHIFT (16U)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_0_OFF_FIRST_DWORD_THIRD_BYTE_SHIFT)) & PCIE_HDR_LOG_0_OFF_FIRST_DWORD_THIRD_BYTE_MASK)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FOURTH_BYTE_SHIFT (24U)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FOURTH_BYTE_SHIFT)) & PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FOURTH_BYTE_MASK)
/*! @} */

/*! @name HDR_LOG_1_OFF - Header Log Register 1. */
/*! @{ */
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FIRST_BYTE_MASK (0xFFU)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FIRST_BYTE_SHIFT (0U)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FIRST_BYTE_SHIFT)) & PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FIRST_BYTE_MASK)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_SECOND_BYTE_SHIFT (8U)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_1_OFF_SECOND_DWORD_SECOND_BYTE_SHIFT)) & PCIE_HDR_LOG_1_OFF_SECOND_DWORD_SECOND_BYTE_MASK)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_THIRD_BYTE_SHIFT (16U)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_1_OFF_SECOND_DWORD_THIRD_BYTE_SHIFT)) & PCIE_HDR_LOG_1_OFF_SECOND_DWORD_THIRD_BYTE_MASK)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FOURTH_BYTE_SHIFT (24U)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FOURTH_BYTE_SHIFT)) & PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FOURTH_BYTE_MASK)
/*! @} */

/*! @name HDR_LOG_2_OFF - Header Log Register 2. */
/*! @{ */
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FIRST_BYTE_MASK (0xFFU)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FIRST_BYTE_SHIFT (0U)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FIRST_BYTE_SHIFT)) & PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FIRST_BYTE_MASK)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_SECOND_BYTE_SHIFT (8U)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_2_OFF_THIRD_DWORD_SECOND_BYTE_SHIFT)) & PCIE_HDR_LOG_2_OFF_THIRD_DWORD_SECOND_BYTE_MASK)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_THIRD_BYTE_SHIFT (16U)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_2_OFF_THIRD_DWORD_THIRD_BYTE_SHIFT)) & PCIE_HDR_LOG_2_OFF_THIRD_DWORD_THIRD_BYTE_MASK)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FOURTH_BYTE_SHIFT (24U)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FOURTH_BYTE_SHIFT)) & PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FOURTH_BYTE_MASK)
/*! @} */

/*! @name HDR_LOG_3_OFF - Header Log Register 3. */
/*! @{ */
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FIRST_BYTE_MASK (0xFFU)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FIRST_BYTE_SHIFT (0U)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FIRST_BYTE_SHIFT)) & PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FIRST_BYTE_MASK)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_SECOND_BYTE_SHIFT (8U)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_SECOND_BYTE_SHIFT)) & PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_SECOND_BYTE_MASK)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_THIRD_BYTE_SHIFT (16U)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_THIRD_BYTE_SHIFT)) & PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_THIRD_BYTE_MASK)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FOURTH_BYTE_SHIFT (24U)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FOURTH_BYTE_SHIFT)) & PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FOURTH_BYTE_MASK)
/*! @} */

/*! @name ROOT_ERR_CMD_OFF - Root Error Command Register. */
/*! @{ */
#define PCIE_ROOT_ERR_CMD_OFF_CORR_ERR_REPORTING_EN_MASK (0x1U)
#define PCIE_ROOT_ERR_CMD_OFF_CORR_ERR_REPORTING_EN_SHIFT (0U)
#define PCIE_ROOT_ERR_CMD_OFF_NON_FATAL_ERR_REPORTING_EN_MASK (0x2U)
#define PCIE_ROOT_ERR_CMD_OFF_NON_FATAL_ERR_REPORTING_EN_SHIFT (1U)
#define PCIE_ROOT_ERR_CMD_OFF_FATAL_ERR_REPORTING_EN_MASK (0x4U)
#define PCIE_ROOT_ERR_CMD_OFF_FATAL_ERR_REPORTING_EN_SHIFT (2U)
#define PCIE_ROOT_ERR_CMD_OFF_RSVDP_3_MASK       (0xFFFFFFF8U)
#define PCIE_ROOT_ERR_CMD_OFF_RSVDP_3_SHIFT      (3U)
#define PCIE_ROOT_ERR_CMD_OFF_RSVDP_3(x)         (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_CMD_OFF_RSVDP_3_SHIFT)) & PCIE_ROOT_ERR_CMD_OFF_RSVDP_3_MASK)
/*! @} */

/*! @name ROOT_ERR_STATUS_OFF - Root Error Status Register. */
/*! @{ */
#define PCIE_ROOT_ERR_STATUS_OFF_ERR_COR_RX_MASK (0x1U)
#define PCIE_ROOT_ERR_STATUS_OFF_ERR_COR_RX_SHIFT (0U)
#define PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_COR_RX_MASK (0x2U)
#define PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_COR_RX_SHIFT (1U)
#define PCIE_ROOT_ERR_STATUS_OFF_ERR_FATAL_NON_FATAL_RX_MASK (0x4U)
#define PCIE_ROOT_ERR_STATUS_OFF_ERR_FATAL_NON_FATAL_RX_SHIFT (2U)
#define PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_FATAL_NON_FATAL_RX_MASK (0x8U)
#define PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_FATAL_NON_FATAL_RX_SHIFT (3U)
#define PCIE_ROOT_ERR_STATUS_OFF_FIRST_UNCORR_FATAL_MASK (0x10U)
#define PCIE_ROOT_ERR_STATUS_OFF_FIRST_UNCORR_FATAL_SHIFT (4U)
#define PCIE_ROOT_ERR_STATUS_OFF_NON_FATAL_ERR_MSG_RX_MASK (0x20U)
#define PCIE_ROOT_ERR_STATUS_OFF_NON_FATAL_ERR_MSG_RX_SHIFT (5U)
#define PCIE_ROOT_ERR_STATUS_OFF_FATAL_ERR_MSG_RX_MASK (0x40U)
#define PCIE_ROOT_ERR_STATUS_OFF_FATAL_ERR_MSG_RX_SHIFT (6U)
#define PCIE_ROOT_ERR_STATUS_OFF_RSVDP_7_MASK    (0x7FFFF80U)
#define PCIE_ROOT_ERR_STATUS_OFF_RSVDP_7_SHIFT   (7U)
#define PCIE_ROOT_ERR_STATUS_OFF_RSVDP_7(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_STATUS_OFF_RSVDP_7_SHIFT)) & PCIE_ROOT_ERR_STATUS_OFF_RSVDP_7_MASK)
#define PCIE_ROOT_ERR_STATUS_OFF_ADV_ERR_INT_MSG_NUM_MASK (0xF8000000U)
#define PCIE_ROOT_ERR_STATUS_OFF_ADV_ERR_INT_MSG_NUM_SHIFT (27U)
#define PCIE_ROOT_ERR_STATUS_OFF_ADV_ERR_INT_MSG_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_STATUS_OFF_ADV_ERR_INT_MSG_NUM_SHIFT)) & PCIE_ROOT_ERR_STATUS_OFF_ADV_ERR_INT_MSG_NUM_MASK)
/*! @} */

/*! @name ERR_SRC_ID_OFF - Error Source Identification Register. */
/*! @{ */
#define PCIE_ERR_SRC_ID_OFF_ERR_COR_SOURCE_ID_MASK (0xFFFFU)
#define PCIE_ERR_SRC_ID_OFF_ERR_COR_SOURCE_ID_SHIFT (0U)
#define PCIE_ERR_SRC_ID_OFF_ERR_COR_SOURCE_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ERR_SRC_ID_OFF_ERR_COR_SOURCE_ID_SHIFT)) & PCIE_ERR_SRC_ID_OFF_ERR_COR_SOURCE_ID_MASK)
#define PCIE_ERR_SRC_ID_OFF_ERR_FATAL_NON_FATAL_SOURCE_ID_MASK (0xFFFF0000U)
#define PCIE_ERR_SRC_ID_OFF_ERR_FATAL_NON_FATAL_SOURCE_ID_SHIFT (16U)
#define PCIE_ERR_SRC_ID_OFF_ERR_FATAL_NON_FATAL_SOURCE_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ERR_SRC_ID_OFF_ERR_FATAL_NON_FATAL_SOURCE_ID_SHIFT)) & PCIE_ERR_SRC_ID_OFF_ERR_FATAL_NON_FATAL_SOURCE_ID_MASK)
/*! @} */

/*! @name TLP_PREFIX_LOG_1_OFF - TLP Prefix Log Register 1. */
/*! @{ */
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FIRST_BYTE_MASK (0xFFU)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FIRST_BYTE_SHIFT (0U)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FIRST_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FIRST_BYTE_MASK)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_SECOND_BYTE_SHIFT (8U)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_SECOND_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_SECOND_BYTE_MASK)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_THIRD_BYTE_SHIFT (16U)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_THIRD_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_THIRD_BYTE_MASK)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FOURTH_BYTE_SHIFT (24U)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FOURTH_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FOURTH_BYTE_MASK)
/*! @} */

/*! @name TLP_PREFIX_LOG_2_OFF - TLP Prefix Log Register 2. */
/*! @{ */
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FIRST_BYTE_MASK (0xFFU)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FIRST_BYTE_SHIFT (0U)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FIRST_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FIRST_BYTE_MASK)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_SECOND_BYTE_SHIFT (8U)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_SECOND_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_SECOND_BYTE_MASK)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_THIRD_BYTE_SHIFT (16U)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_THIRD_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_THIRD_BYTE_MASK)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FOURTH_BYTE_SHIFT (24U)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FOURTH_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FOURTH_BYTE_MASK)
/*! @} */

/*! @name TLP_PREFIX_LOG_3_OFF - TLP Prefix Log Register 3. */
/*! @{ */
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FIRST_BYTE_MASK (0xFFU)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FIRST_BYTE_SHIFT (0U)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FIRST_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FIRST_BYTE_MASK)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_SECOND_BYTE_SHIFT (8U)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_SECOND_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_SECOND_BYTE_MASK)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_THIRD_BYTE_SHIFT (16U)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_THIRD_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_THIRD_BYTE_MASK)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FOURTH_BYTE_SHIFT (24U)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FOURTH_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FOURTH_BYTE_MASK)
/*! @} */

/*! @name TLP_PREFIX_LOG_4_OFF - TLP Prefix Log Register 4. */
/*! @{ */
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FIRST_BYTE_MASK (0xFFU)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FIRST_BYTE_SHIFT (0U)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FIRST_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FIRST_BYTE_MASK)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_SECOND_BYTE_SHIFT (8U)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_SECOND_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_SECOND_BYTE_MASK)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_THIRD_BYTE_SHIFT (16U)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_THIRD_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_THIRD_BYTE_MASK)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FOURTH_BYTE_SHIFT (24U)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FOURTH_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FOURTH_BYTE_MASK)
/*! @} */

/*! @name L1SUB_CAP_HEADER_REG - L1 Substates Extended Capability Header. */
/*! @{ */
#define PCIE_L1SUB_CAP_HEADER_REG_EXTENDED_CAP_ID_MASK (0xFFFFU)
#define PCIE_L1SUB_CAP_HEADER_REG_EXTENDED_CAP_ID_SHIFT (0U)
#define PCIE_L1SUB_CAP_HEADER_REG_EXTENDED_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAP_HEADER_REG_EXTENDED_CAP_ID_SHIFT)) & PCIE_L1SUB_CAP_HEADER_REG_EXTENDED_CAP_ID_MASK)
#define PCIE_L1SUB_CAP_HEADER_REG_CAP_VERSION_MASK (0xF0000U)
#define PCIE_L1SUB_CAP_HEADER_REG_CAP_VERSION_SHIFT (16U)
#define PCIE_L1SUB_CAP_HEADER_REG_CAP_VERSION(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAP_HEADER_REG_CAP_VERSION_SHIFT)) & PCIE_L1SUB_CAP_HEADER_REG_CAP_VERSION_MASK)
#define PCIE_L1SUB_CAP_HEADER_REG_NEXT_OFFSET_MASK (0xFFF00000U)
#define PCIE_L1SUB_CAP_HEADER_REG_NEXT_OFFSET_SHIFT (20U)
#define PCIE_L1SUB_CAP_HEADER_REG_NEXT_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAP_HEADER_REG_NEXT_OFFSET_SHIFT)) & PCIE_L1SUB_CAP_HEADER_REG_NEXT_OFFSET_MASK)
/*! @} */

/*! @name L1SUB_CAPABILITY_REG - L1 Substates Capability Register. */
/*! @{ */
#define PCIE_L1SUB_CAPABILITY_REG_L1_2_PCIPM_SUPPORT_MASK (0x1U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_2_PCIPM_SUPPORT_SHIFT (0U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_1_PCIPM_SUPPORT_MASK (0x2U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_1_PCIPM_SUPPORT_SHIFT (1U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_2_ASPM_SUPPORT_MASK (0x4U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_2_ASPM_SUPPORT_SHIFT (2U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_1_ASPM_SUPPORT_MASK (0x8U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_1_ASPM_SUPPORT_SHIFT (3U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_PMSUB_SUPPORT_MASK (0x10U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_PMSUB_SUPPORT_SHIFT (4U)
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_5_MASK   (0xE0U)
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_5_SHIFT  (5U)
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_5(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_RSVDP_5_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_RSVDP_5_MASK)
#define PCIE_L1SUB_CAPABILITY_REG_COMM_MODE_SUPPORT_MASK (0xFF00U)
#define PCIE_L1SUB_CAPABILITY_REG_COMM_MODE_SUPPORT_SHIFT (8U)
#define PCIE_L1SUB_CAPABILITY_REG_COMM_MODE_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_COMM_MODE_SUPPORT_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_COMM_MODE_SUPPORT_MASK)
#define PCIE_L1SUB_CAPABILITY_REG_PWR_ON_SCALE_SUPPORT_MASK (0x30000U)
#define PCIE_L1SUB_CAPABILITY_REG_PWR_ON_SCALE_SUPPORT_SHIFT (16U)
#define PCIE_L1SUB_CAPABILITY_REG_PWR_ON_SCALE_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_PWR_ON_SCALE_SUPPORT_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_PWR_ON_SCALE_SUPPORT_MASK)
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_18_MASK  (0x40000U)
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_18_SHIFT (18U)
#define PCIE_L1SUB_CAPABILITY_REG_PWR_ON_VALUE_SUPPORT_MASK (0xF80000U)
#define PCIE_L1SUB_CAPABILITY_REG_PWR_ON_VALUE_SUPPORT_SHIFT (19U)
#define PCIE_L1SUB_CAPABILITY_REG_PWR_ON_VALUE_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_PWR_ON_VALUE_SUPPORT_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_PWR_ON_VALUE_SUPPORT_MASK)
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_24_MASK  (0xFF000000U)
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_24_SHIFT (24U)
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_24(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_RSVDP_24_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_RSVDP_24_MASK)
/*! @} */

/*! @name L1SUB_CONTROL1_REG - L1 Substates Control 1 Register. */
/*! @{ */
#define PCIE_L1SUB_CONTROL1_REG_L1_2_PCIPM_EN_MASK (0x1U)
#define PCIE_L1SUB_CONTROL1_REG_L1_2_PCIPM_EN_SHIFT (0U)
#define PCIE_L1SUB_CONTROL1_REG_L1_1_PCIPM_EN_MASK (0x2U)
#define PCIE_L1SUB_CONTROL1_REG_L1_1_PCIPM_EN_SHIFT (1U)
#define PCIE_L1SUB_CONTROL1_REG_L1_2_ASPM_EN_MASK (0x4U)
#define PCIE_L1SUB_CONTROL1_REG_L1_2_ASPM_EN_SHIFT (2U)
#define PCIE_L1SUB_CONTROL1_REG_L1_1_ASPM_EN_MASK (0x8U)
#define PCIE_L1SUB_CONTROL1_REG_L1_1_ASPM_EN_SHIFT (3U)
#define PCIE_L1SUB_CONTROL1_REG_RSVDP_4_MASK     (0xF0U)
#define PCIE_L1SUB_CONTROL1_REG_RSVDP_4_SHIFT    (4U)
#define PCIE_L1SUB_CONTROL1_REG_RSVDP_4(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_RSVDP_4_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_RSVDP_4_MASK)
#define PCIE_L1SUB_CONTROL1_REG_T_COMMON_MODE_MASK (0xFF00U)
#define PCIE_L1SUB_CONTROL1_REG_T_COMMON_MODE_SHIFT (8U)
#define PCIE_L1SUB_CONTROL1_REG_T_COMMON_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_T_COMMON_MODE_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_T_COMMON_MODE_MASK)
#define PCIE_L1SUB_CONTROL1_REG_L1_2_TH_VAL_MASK (0x3FF0000U)
#define PCIE_L1SUB_CONTROL1_REG_L1_2_TH_VAL_SHIFT (16U)
#define PCIE_L1SUB_CONTROL1_REG_L1_2_TH_VAL(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_L1_2_TH_VAL_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_L1_2_TH_VAL_MASK)
#define PCIE_L1SUB_CONTROL1_REG_RSVDP_26_MASK    (0x1C000000U)
#define PCIE_L1SUB_CONTROL1_REG_RSVDP_26_SHIFT   (26U)
#define PCIE_L1SUB_CONTROL1_REG_RSVDP_26(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_RSVDP_26_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_RSVDP_26_MASK)
#define PCIE_L1SUB_CONTROL1_REG_L1_2_TH_SCA_MASK (0xE0000000U)
#define PCIE_L1SUB_CONTROL1_REG_L1_2_TH_SCA_SHIFT (29U)
#define PCIE_L1SUB_CONTROL1_REG_L1_2_TH_SCA(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_L1_2_TH_SCA_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_L1_2_TH_SCA_MASK)
/*! @} */

/*! @name L1SUB_CONTROL2_REG - L1 Substates Control 2 Register. */
/*! @{ */
#define PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_SCALE_MASK (0x3U)
#define PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_SCALE_SHIFT (0U)
#define PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_SCALE_SHIFT)) & PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_SCALE_MASK)
#define PCIE_L1SUB_CONTROL2_REG_RSVDP_2_MASK     (0x4U)
#define PCIE_L1SUB_CONTROL2_REG_RSVDP_2_SHIFT    (2U)
#define PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_VALUE_MASK (0xF8U)
#define PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_VALUE_SHIFT (3U)
#define PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_VALUE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_VALUE_SHIFT)) & PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_VALUE_MASK)
#define PCIE_L1SUB_CONTROL2_REG_RSVDP_8_MASK     (0xFFFFFF00U)
#define PCIE_L1SUB_CONTROL2_REG_RSVDP_8_SHIFT    (8U)
#define PCIE_L1SUB_CONTROL2_REG_RSVDP_8(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL2_REG_RSVDP_8_SHIFT)) & PCIE_L1SUB_CONTROL2_REG_RSVDP_8_MASK)
/*! @} */

/*! @name ACK_LATENCY_TIMER_OFF - Ack Latency Timer and Replay Timer Register. */
/*! @{ */
#define PCIE_ACK_LATENCY_TIMER_OFF_ROUND_TRIP_LATENCY_TIME_LIMIT_MASK (0xFFFFU)
#define PCIE_ACK_LATENCY_TIMER_OFF_ROUND_TRIP_LATENCY_TIME_LIMIT_SHIFT (0U)
#define PCIE_ACK_LATENCY_TIMER_OFF_ROUND_TRIP_LATENCY_TIME_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_LATENCY_TIMER_OFF_ROUND_TRIP_LATENCY_TIME_LIMIT_SHIFT)) & PCIE_ACK_LATENCY_TIMER_OFF_ROUND_TRIP_LATENCY_TIME_LIMIT_MASK)
#define PCIE_ACK_LATENCY_TIMER_OFF_REPLAY_TIME_LIMIT_MASK (0xFFFF0000U)
#define PCIE_ACK_LATENCY_TIMER_OFF_REPLAY_TIME_LIMIT_SHIFT (16U)
#define PCIE_ACK_LATENCY_TIMER_OFF_REPLAY_TIME_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_LATENCY_TIMER_OFF_REPLAY_TIME_LIMIT_SHIFT)) & PCIE_ACK_LATENCY_TIMER_OFF_REPLAY_TIME_LIMIT_MASK)
/*! @} */

/*! @name VENDOR_SPEC_DLLP_OFF - Vendor Specific DLLP Register. */
/*! @{ */
#define PCIE_VENDOR_SPEC_DLLP_OFF_VENDOR_SPEC_DLLP_MASK (0xFFFFFFFFU)
#define PCIE_VENDOR_SPEC_DLLP_OFF_VENDOR_SPEC_DLLP_SHIFT (0U)
#define PCIE_VENDOR_SPEC_DLLP_OFF_VENDOR_SPEC_DLLP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VENDOR_SPEC_DLLP_OFF_VENDOR_SPEC_DLLP_SHIFT)) & PCIE_VENDOR_SPEC_DLLP_OFF_VENDOR_SPEC_DLLP_MASK)
/*! @} */

/*! @name PORT_FORCE_OFF - Port Force Link Register. */
/*! @{ */
#define PCIE_PORT_FORCE_OFF_LINK_NUM_MASK        (0xFFU)
#define PCIE_PORT_FORCE_OFF_LINK_NUM_SHIFT       (0U)
#define PCIE_PORT_FORCE_OFF_LINK_NUM(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_FORCE_OFF_LINK_NUM_SHIFT)) & PCIE_PORT_FORCE_OFF_LINK_NUM_MASK)
#define PCIE_PORT_FORCE_OFF_FORCED_LTSSM_MASK    (0xF00U)
#define PCIE_PORT_FORCE_OFF_FORCED_LTSSM_SHIFT   (8U)
#define PCIE_PORT_FORCE_OFF_FORCED_LTSSM(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_FORCE_OFF_FORCED_LTSSM_SHIFT)) & PCIE_PORT_FORCE_OFF_FORCED_LTSSM_MASK)
#define PCIE_PORT_FORCE_OFF_RSVDP_12_MASK        (0x7000U)
#define PCIE_PORT_FORCE_OFF_RSVDP_12_SHIFT       (12U)
#define PCIE_PORT_FORCE_OFF_RSVDP_12(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_FORCE_OFF_RSVDP_12_SHIFT)) & PCIE_PORT_FORCE_OFF_RSVDP_12_MASK)
#define PCIE_PORT_FORCE_OFF_FORCE_EN_MASK        (0x8000U)
#define PCIE_PORT_FORCE_OFF_FORCE_EN_SHIFT       (15U)
#define PCIE_PORT_FORCE_OFF_LINK_STATE_MASK      (0x3F0000U)
#define PCIE_PORT_FORCE_OFF_LINK_STATE_SHIFT     (16U)
#define PCIE_PORT_FORCE_OFF_LINK_STATE(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_FORCE_OFF_LINK_STATE_SHIFT)) & PCIE_PORT_FORCE_OFF_LINK_STATE_MASK)
#define PCIE_PORT_FORCE_OFF_RSVDP_22_MASK        (0x400000U)
#define PCIE_PORT_FORCE_OFF_RSVDP_22_SHIFT       (22U)
#define PCIE_PORT_FORCE_OFF_DO_DESKEW_FOR_SRIS_MASK (0x800000U)
#define PCIE_PORT_FORCE_OFF_DO_DESKEW_FOR_SRIS_SHIFT (23U)
#define PCIE_PORT_FORCE_OFF_RSVDP_24_MASK        (0xFF000000U)
#define PCIE_PORT_FORCE_OFF_RSVDP_24_SHIFT       (24U)
#define PCIE_PORT_FORCE_OFF_RSVDP_24(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_FORCE_OFF_RSVDP_24_SHIFT)) & PCIE_PORT_FORCE_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name ACK_F_ASPM_CTRL_OFF - Ack Frequency and L0-L1 ASPM Control Register. */
/*! @{ */
#define PCIE_ACK_F_ASPM_CTRL_OFF_ACK_FREQ_MASK   (0xFFU)
#define PCIE_ACK_F_ASPM_CTRL_OFF_ACK_FREQ_SHIFT  (0U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_ACK_FREQ(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_F_ASPM_CTRL_OFF_ACK_FREQ_SHIFT)) & PCIE_ACK_F_ASPM_CTRL_OFF_ACK_FREQ_MASK)
#define PCIE_ACK_F_ASPM_CTRL_OFF_ACK_N_FTS_MASK  (0xFF00U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_ACK_N_FTS_SHIFT (8U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_ACK_N_FTS(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_F_ASPM_CTRL_OFF_ACK_N_FTS_SHIFT)) & PCIE_ACK_F_ASPM_CTRL_OFF_ACK_N_FTS_MASK)
#define PCIE_ACK_F_ASPM_CTRL_OFF_COMMON_CLK_N_FTS_MASK (0xFF0000U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_COMMON_CLK_N_FTS_SHIFT (16U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_COMMON_CLK_N_FTS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_F_ASPM_CTRL_OFF_COMMON_CLK_N_FTS_SHIFT)) & PCIE_ACK_F_ASPM_CTRL_OFF_COMMON_CLK_N_FTS_MASK)
#define PCIE_ACK_F_ASPM_CTRL_OFF_L0S_ENTRANCE_LATENCY_MASK (0x7000000U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_L0S_ENTRANCE_LATENCY_SHIFT (24U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_L0S_ENTRANCE_LATENCY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_F_ASPM_CTRL_OFF_L0S_ENTRANCE_LATENCY_SHIFT)) & PCIE_ACK_F_ASPM_CTRL_OFF_L0S_ENTRANCE_LATENCY_MASK)
#define PCIE_ACK_F_ASPM_CTRL_OFF_L1_ENTRANCE_LATENCY_MASK (0x38000000U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_L1_ENTRANCE_LATENCY_SHIFT (27U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_L1_ENTRANCE_LATENCY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_F_ASPM_CTRL_OFF_L1_ENTRANCE_LATENCY_SHIFT)) & PCIE_ACK_F_ASPM_CTRL_OFF_L1_ENTRANCE_LATENCY_MASK)
#define PCIE_ACK_F_ASPM_CTRL_OFF_ENTER_ASPM_MASK (0x40000000U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_ENTER_ASPM_SHIFT (30U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_RSVDP_31_MASK   (0x80000000U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_RSVDP_31_SHIFT  (31U)
/*! @} */

/*! @name PORT_LINK_CTRL_OFF - Port Link Control Register. */
/*! @{ */
#define PCIE_PORT_LINK_CTRL_OFF_VENDOR_SPECIFIC_DLLP_REQ_MASK (0x1U)
#define PCIE_PORT_LINK_CTRL_OFF_VENDOR_SPECIFIC_DLLP_REQ_SHIFT (0U)
#define PCIE_PORT_LINK_CTRL_OFF_SCRAMBLE_DISABLE_MASK (0x2U)
#define PCIE_PORT_LINK_CTRL_OFF_SCRAMBLE_DISABLE_SHIFT (1U)
#define PCIE_PORT_LINK_CTRL_OFF_LOOPBACK_ENABLE_MASK (0x4U)
#define PCIE_PORT_LINK_CTRL_OFF_LOOPBACK_ENABLE_SHIFT (2U)
#define PCIE_PORT_LINK_CTRL_OFF_RESET_ASSERT_MASK (0x8U)
#define PCIE_PORT_LINK_CTRL_OFF_RESET_ASSERT_SHIFT (3U)
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_4_MASK     (0x10U)
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_4_SHIFT    (4U)
#define PCIE_PORT_LINK_CTRL_OFF_DLL_LINK_EN_MASK (0x20U)
#define PCIE_PORT_LINK_CTRL_OFF_DLL_LINK_EN_SHIFT (5U)
#define PCIE_PORT_LINK_CTRL_OFF_LINK_DISABLE_MASK (0x40U)
#define PCIE_PORT_LINK_CTRL_OFF_LINK_DISABLE_SHIFT (6U)
#define PCIE_PORT_LINK_CTRL_OFF_FAST_LINK_MODE_MASK (0x80U)
#define PCIE_PORT_LINK_CTRL_OFF_FAST_LINK_MODE_SHIFT (7U)
#define PCIE_PORT_LINK_CTRL_OFF_LINK_RATE_MASK   (0xF00U)
#define PCIE_PORT_LINK_CTRL_OFF_LINK_RATE_SHIFT  (8U)
#define PCIE_PORT_LINK_CTRL_OFF_LINK_RATE(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_LINK_RATE_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_LINK_RATE_MASK)
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_12_MASK    (0xF000U)
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_12_SHIFT   (12U)
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_12(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_RSVDP_12_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_RSVDP_12_MASK)
#define PCIE_PORT_LINK_CTRL_OFF_LINK_CAPABLE_MASK (0x3F0000U)
#define PCIE_PORT_LINK_CTRL_OFF_LINK_CAPABLE_SHIFT (16U)
#define PCIE_PORT_LINK_CTRL_OFF_LINK_CAPABLE(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_LINK_CAPABLE_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_LINK_CAPABLE_MASK)
#define PCIE_PORT_LINK_CTRL_OFF_BEACON_ENABLE_MASK (0x1000000U)
#define PCIE_PORT_LINK_CTRL_OFF_BEACON_ENABLE_SHIFT (24U)
#define PCIE_PORT_LINK_CTRL_OFF_CORRUPT_LCRC_ENABLE_MASK (0x2000000U)
#define PCIE_PORT_LINK_CTRL_OFF_CORRUPT_LCRC_ENABLE_SHIFT (25U)
#define PCIE_PORT_LINK_CTRL_OFF_EXTENDED_SYNCH_MASK (0x4000000U)
#define PCIE_PORT_LINK_CTRL_OFF_EXTENDED_SYNCH_SHIFT (26U)
#define PCIE_PORT_LINK_CTRL_OFF_TRANSMIT_LANE_REVERSALE_ENABLE_MASK (0x8000000U)
#define PCIE_PORT_LINK_CTRL_OFF_TRANSMIT_LANE_REVERSALE_ENABLE_SHIFT (27U)
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_28_MASK    (0xF0000000U)
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_28_SHIFT   (28U)
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_28(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_RSVDP_28_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_RSVDP_28_MASK)
/*! @} */

/*! @name LANE_SKEW_OFF - Lane Skew Register. */
/*! @{ */
#define PCIE_LANE_SKEW_OFF_INSERT_LANE_SKEW_MASK (0xFFFFFFU)
#define PCIE_LANE_SKEW_OFF_INSERT_LANE_SKEW_SHIFT (0U)
#define PCIE_LANE_SKEW_OFF_INSERT_LANE_SKEW(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_LANE_SKEW_OFF_INSERT_LANE_SKEW_SHIFT)) & PCIE_LANE_SKEW_OFF_INSERT_LANE_SKEW_MASK)
#define PCIE_LANE_SKEW_OFF_FLOW_CTRL_DISABLE_MASK (0x1000000U)
#define PCIE_LANE_SKEW_OFF_FLOW_CTRL_DISABLE_SHIFT (24U)
#define PCIE_LANE_SKEW_OFF_ACK_NAK_DISABLE_MASK  (0x2000000U)
#define PCIE_LANE_SKEW_OFF_ACK_NAK_DISABLE_SHIFT (25U)
#define PCIE_LANE_SKEW_OFF_GEN34_ELASTIC_BUFFER_MODE_MASK (0x4000000U)
#define PCIE_LANE_SKEW_OFF_GEN34_ELASTIC_BUFFER_MODE_SHIFT (26U)
#define PCIE_LANE_SKEW_OFF_IMPLEMENT_NUM_LANES_MASK (0x78000000U)
#define PCIE_LANE_SKEW_OFF_IMPLEMENT_NUM_LANES_SHIFT (27U)
#define PCIE_LANE_SKEW_OFF_IMPLEMENT_NUM_LANES(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LANE_SKEW_OFF_IMPLEMENT_NUM_LANES_SHIFT)) & PCIE_LANE_SKEW_OFF_IMPLEMENT_NUM_LANES_MASK)
#define PCIE_LANE_SKEW_OFF_DISABLE_LANE_TO_LANE_DESKEW_MASK (0x80000000U)
#define PCIE_LANE_SKEW_OFF_DISABLE_LANE_TO_LANE_DESKEW_SHIFT (31U)
/*! @} */

/*! @name TIMER_CTRL_MAX_FUNC_NUM_OFF - Timer Control and Max Function Number Register. */
/*! @{ */
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_MAX_FUNC_NUM_MASK (0xFFU)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_MAX_FUNC_NUM_SHIFT (0U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_MAX_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_MAX_FUNC_NUM_SHIFT)) & PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_MAX_FUNC_NUM_MASK)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_8_MASK (0x3F00U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_8_SHIFT (8U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_8(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_8_SHIFT)) & PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_8_MASK)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_REPLAY_TIMER_MASK (0x7C000U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_REPLAY_TIMER_SHIFT (14U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_REPLAY_TIMER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_REPLAY_TIMER_SHIFT)) & PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_REPLAY_TIMER_MASK)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_ACK_NAK_MASK (0xF80000U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_ACK_NAK_SHIFT (19U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_ACK_NAK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_ACK_NAK_SHIFT)) & PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_ACK_NAK_MASK)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_UPDATE_FREQ_TIMER_MASK (0x1F000000U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_UPDATE_FREQ_TIMER_SHIFT (24U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_UPDATE_FREQ_TIMER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_UPDATE_FREQ_TIMER_SHIFT)) & PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_UPDATE_FREQ_TIMER_MASK)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_FAST_LINK_SCALING_FACTOR_MASK (0x60000000U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_FAST_LINK_SCALING_FACTOR_SHIFT (29U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_FAST_LINK_SCALING_FACTOR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_FAST_LINK_SCALING_FACTOR_SHIFT)) & PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_FAST_LINK_SCALING_FACTOR_MASK)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_31_MASK (0x80000000U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_31_SHIFT (31U)
/*! @} */

/*! @name SYMBOL_TIMER_FILTER_1_OFF - Symbol Timer Register and Filter Mask 1 Register. */
/*! @{ */
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_SKP_INT_VAL_MASK (0x7FFU)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_SKP_INT_VAL_SHIFT (0U)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_SKP_INT_VAL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SYMBOL_TIMER_FILTER_1_OFF_SKP_INT_VAL_SHIFT)) & PCIE_SYMBOL_TIMER_FILTER_1_OFF_SKP_INT_VAL_MASK)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_EIDLE_TIMER_MASK (0x7800U)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_EIDLE_TIMER_SHIFT (11U)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_EIDLE_TIMER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SYMBOL_TIMER_FILTER_1_OFF_EIDLE_TIMER_SHIFT)) & PCIE_SYMBOL_TIMER_FILTER_1_OFF_EIDLE_TIMER_MASK)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_DISABLE_FC_WD_TIMER_MASK (0x8000U)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_DISABLE_FC_WD_TIMER_SHIFT (15U)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_MASK_RADM_1_MASK (0xFFFF0000U)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_MASK_RADM_1_SHIFT (16U)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_MASK_RADM_1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SYMBOL_TIMER_FILTER_1_OFF_MASK_RADM_1_SHIFT)) & PCIE_SYMBOL_TIMER_FILTER_1_OFF_MASK_RADM_1_MASK)
/*! @} */

/*! @name FILTER_MASK_2_OFF - Filter Mask 2 Register. */
/*! @{ */
#define PCIE_FILTER_MASK_2_OFF_MASK_RADM_2_MASK  (0xFFFFFFFFU)
#define PCIE_FILTER_MASK_2_OFF_MASK_RADM_2_SHIFT (0U)
#define PCIE_FILTER_MASK_2_OFF_MASK_RADM_2(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_FILTER_MASK_2_OFF_MASK_RADM_2_SHIFT)) & PCIE_FILTER_MASK_2_OFF_MASK_RADM_2_MASK)
/*! @} */

/*! @name AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF - AMBA Multiple Outbound Decomposed NP SubRequests Control Register. */
/*! @{ */
#define PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_OB_RD_SPLIT_BURST_EN_MASK (0x1U)
#define PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_OB_RD_SPLIT_BURST_EN_SHIFT (0U)
#define PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RSVDP_1_MASK (0xFFFFFFFEU)
#define PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RSVDP_1_SHIFT (1U)
#define PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RSVDP_1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RSVDP_1_SHIFT)) & PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RSVDP_1_MASK)
/*! @} */

/*! @name PL_DEBUG0_OFF - Debug Register 0 */
/*! @{ */
#define PCIE_PL_DEBUG0_OFF_DEB_REG_0_MASK        (0xFFFFFFFFU)
#define PCIE_PL_DEBUG0_OFF_DEB_REG_0_SHIFT       (0U)
#define PCIE_PL_DEBUG0_OFF_DEB_REG_0(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_PL_DEBUG0_OFF_DEB_REG_0_SHIFT)) & PCIE_PL_DEBUG0_OFF_DEB_REG_0_MASK)
/*! @} */

/*! @name PL_DEBUG1_OFF - Debug Register 1 */
/*! @{ */
#define PCIE_PL_DEBUG1_OFF_DEB_REG_1_MASK        (0xFFFFFFFFU)
#define PCIE_PL_DEBUG1_OFF_DEB_REG_1_SHIFT       (0U)
#define PCIE_PL_DEBUG1_OFF_DEB_REG_1(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_PL_DEBUG1_OFF_DEB_REG_1_SHIFT)) & PCIE_PL_DEBUG1_OFF_DEB_REG_1_MASK)
/*! @} */

/*! @name TX_P_FC_CREDIT_STATUS_OFF - Transmit Posted FC Credit Status */
/*! @{ */
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_DATA_FC_CREDIT_MASK (0xFFFU)
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_DATA_FC_CREDIT_SHIFT (0U)
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_DATA_FC_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_DATA_FC_CREDIT_SHIFT)) & PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_DATA_FC_CREDIT_MASK)
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_HEADER_FC_CREDIT_MASK (0xFF000U)
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_HEADER_FC_CREDIT_SHIFT (12U)
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_HEADER_FC_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_HEADER_FC_CREDIT_SHIFT)) & PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_HEADER_FC_CREDIT_MASK)
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_RSVDP_20_SHIFT (20U)
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_P_FC_CREDIT_STATUS_OFF_RSVDP_20_SHIFT)) & PCIE_TX_P_FC_CREDIT_STATUS_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name TX_NP_FC_CREDIT_STATUS_OFF - Transmit Non-Posted FC Credit Status */
/*! @{ */
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_DATA_FC_CREDIT_MASK (0xFFFU)
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_DATA_FC_CREDIT_SHIFT (0U)
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_DATA_FC_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_DATA_FC_CREDIT_SHIFT)) & PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_DATA_FC_CREDIT_MASK)
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_HEADER_FC_CREDIT_MASK (0xFF000U)
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_HEADER_FC_CREDIT_SHIFT (12U)
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_HEADER_FC_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_HEADER_FC_CREDIT_SHIFT)) & PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_HEADER_FC_CREDIT_MASK)
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_RSVDP_20_SHIFT (20U)
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_NP_FC_CREDIT_STATUS_OFF_RSVDP_20_SHIFT)) & PCIE_TX_NP_FC_CREDIT_STATUS_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name TX_CPL_FC_CREDIT_STATUS_OFF - Transmit Completion FC Credit Status */
/*! @{ */
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_DATA_FC_CREDIT_MASK (0xFFFU)
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_DATA_FC_CREDIT_SHIFT (0U)
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_DATA_FC_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_DATA_FC_CREDIT_SHIFT)) & PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_DATA_FC_CREDIT_MASK)
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_HEADER_FC_CREDIT_MASK (0xFF000U)
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_HEADER_FC_CREDIT_SHIFT (12U)
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_HEADER_FC_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_HEADER_FC_CREDIT_SHIFT)) & PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_HEADER_FC_CREDIT_MASK)
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_RSVDP_20_SHIFT (20U)
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_RSVDP_20_SHIFT)) & PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name QUEUE_STATUS_OFF - Queue Status */
/*! @{ */
#define PCIE_QUEUE_STATUS_OFF_RX_TLP_FC_CREDIT_NON_RETURN_MASK (0x1U)
#define PCIE_QUEUE_STATUS_OFF_RX_TLP_FC_CREDIT_NON_RETURN_SHIFT (0U)
#define PCIE_QUEUE_STATUS_OFF_TX_RETRY_BUFFER_NE_MASK (0x2U)
#define PCIE_QUEUE_STATUS_OFF_TX_RETRY_BUFFER_NE_SHIFT (1U)
#define PCIE_QUEUE_STATUS_OFF_RX_QUEUE_NON_EMPTY_MASK (0x4U)
#define PCIE_QUEUE_STATUS_OFF_RX_QUEUE_NON_EMPTY_SHIFT (2U)
#define PCIE_QUEUE_STATUS_OFF_RX_QUEUE_OVERFLOW_MASK (0x8U)
#define PCIE_QUEUE_STATUS_OFF_RX_QUEUE_OVERFLOW_SHIFT (3U)
#define PCIE_QUEUE_STATUS_OFF_RSVDP_4_MASK       (0x1FF0U)
#define PCIE_QUEUE_STATUS_OFF_RSVDP_4_SHIFT      (4U)
#define PCIE_QUEUE_STATUS_OFF_RSVDP_4(x)         (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_RSVDP_4_SHIFT)) & PCIE_QUEUE_STATUS_OFF_RSVDP_4_MASK)
#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_NON_EMPTY_MASK (0x2000U)
#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_NON_EMPTY_SHIFT (13U)
#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_WRITE_ERR_MASK (0x4000U)
#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_WRITE_ERR_SHIFT (14U)
#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_READ_ERR_MASK (0x8000U)
#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_READ_ERR_SHIFT (15U)
#define PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_MASK (0x1FFF0000U)
#define PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_SHIFT (16U)
#define PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_SHIFT)) & PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_MASK)
#define PCIE_QUEUE_STATUS_OFF_RSVDP_29_MASK      (0x60000000U)
#define PCIE_QUEUE_STATUS_OFF_RSVDP_29_SHIFT     (29U)
#define PCIE_QUEUE_STATUS_OFF_RSVDP_29(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_RSVDP_29_SHIFT)) & PCIE_QUEUE_STATUS_OFF_RSVDP_29_MASK)
#define PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_EN_MASK (0x80000000U)
#define PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_EN_SHIFT (31U)
/*! @} */

/*! @name VC_TX_ARBI_1_OFF - VC Transmit Arbitration Register 1 */
/*! @{ */
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_0_MASK (0xFFU)
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_0_SHIFT (0U)
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_0(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_0_SHIFT)) & PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_0_MASK)
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_1_MASK (0xFF00U)
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_1_SHIFT (8U)
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_1_SHIFT)) & PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_1_MASK)
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_2_MASK (0xFF0000U)
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_2_SHIFT (16U)
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_2(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_2_SHIFT)) & PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_2_MASK)
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_3_MASK (0xFF000000U)
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_3_SHIFT (24U)
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_3(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_3_SHIFT)) & PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_3_MASK)
/*! @} */

/*! @name VC_TX_ARBI_2_OFF - VC Transmit Arbitration Register 2 */
/*! @{ */
#define PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_4_MASK (0xFFU)
#define PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_4_SHIFT (0U)
#define PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_4(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_4_SHIFT)) & PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_4_MASK)
#define PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_5_MASK (0xFF00U)
#define PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_5_SHIFT (8U)
#define PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_5(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_5_SHIFT)) & PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_5_MASK)
#define PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_6_MASK (0xFF0000U)
#define PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_6_SHIFT (16U)
#define PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_6(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_6_SHIFT)) & PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_6_MASK)
#define PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_7_MASK (0xFF000000U)
#define PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_7_SHIFT (24U)
#define PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_7(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_7_SHIFT)) & PCIE_VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_7_MASK)
/*! @} */

/*! @name VC0_P_RX_Q_CTRL_OFF - Segmented-Buffer VC0 Posted Receive Queue Control. */
/*! @{ */
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_CREDIT_MASK (0xFFFU)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_CREDIT_SHIFT (0U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_CREDIT_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_CREDIT_MASK)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HEADER_CREDIT_MASK (0xFF000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HEADER_CREDIT_SHIFT (12U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HEADER_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HEADER_CREDIT_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HEADER_CREDIT_MASK)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED4_MASK  (0x100000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED4_SHIFT (20U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_TLP_Q_MODE_MASK (0xE00000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_TLP_Q_MODE_SHIFT (21U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_TLP_Q_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_TLP_Q_MODE_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_TLP_Q_MODE_MASK)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HDR_SCALE_MASK (0x3000000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HDR_SCALE_SHIFT (24U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HDR_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HDR_SCALE_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HDR_SCALE_MASK)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_SCALE_MASK (0xC000000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_SCALE_SHIFT (26U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_SCALE_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_SCALE_MASK)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED5_MASK  (0x30000000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED5_SHIFT (28U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED5(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED5_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED5_MASK)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_TLP_TYPE_ORDERING_VC0_MASK (0x40000000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_TLP_TYPE_ORDERING_VC0_SHIFT (30U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC_ORDERING_RX_Q_MASK (0x80000000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC_ORDERING_RX_Q_SHIFT (31U)
/*! @} */

/*! @name VC0_NP_RX_Q_CTRL_OFF - Segmented-Buffer VC0 Non-Posted Receive Queue Control. */
/*! @{ */
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_CREDIT_MASK (0xFFFU)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_CREDIT_SHIFT (0U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_CREDIT_SHIFT)) & PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_CREDIT_MASK)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HEADER_CREDIT_MASK (0xFF000U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HEADER_CREDIT_SHIFT (12U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HEADER_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HEADER_CREDIT_SHIFT)) & PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HEADER_CREDIT_MASK)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED6_MASK (0x100000U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED6_SHIFT (20U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_TLP_Q_MODE_MASK (0xE00000U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_TLP_Q_MODE_SHIFT (21U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_TLP_Q_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_TLP_Q_MODE_SHIFT)) & PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_TLP_Q_MODE_MASK)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HDR_SCALE_MASK (0x3000000U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HDR_SCALE_SHIFT (24U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HDR_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HDR_SCALE_SHIFT)) & PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HDR_SCALE_MASK)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_SCALE_MASK (0xC000000U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_SCALE_SHIFT (26U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_SCALE_SHIFT)) & PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_SCALE_MASK)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED7_MASK (0xF0000000U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED7_SHIFT (28U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED7(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED7_SHIFT)) & PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED7_MASK)
/*! @} */

/*! @name VC0_CPL_RX_Q_CTRL_OFF - Segmented-Buffer VC0 Completion Receive Queue Control. */
/*! @{ */
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_CREDIT_MASK (0xFFFU)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_CREDIT_SHIFT (0U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_CREDIT_SHIFT)) & PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_CREDIT_MASK)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HEADER_CREDIT_MASK (0xFF000U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HEADER_CREDIT_SHIFT (12U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HEADER_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HEADER_CREDIT_SHIFT)) & PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HEADER_CREDIT_MASK)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED8_MASK (0x100000U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED8_SHIFT (20U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_TLP_Q_MODE_MASK (0xE00000U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_TLP_Q_MODE_SHIFT (21U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_TLP_Q_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_TLP_Q_MODE_SHIFT)) & PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_TLP_Q_MODE_MASK)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HDR_SCALE_MASK (0x3000000U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HDR_SCALE_SHIFT (24U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HDR_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HDR_SCALE_SHIFT)) & PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HDR_SCALE_MASK)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_SCALE_MASK (0xC000000U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_SCALE_SHIFT (26U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_SCALE_SHIFT)) & PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_SCALE_MASK)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED9_MASK (0xF0000000U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED9_SHIFT (28U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED9(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED9_SHIFT)) & PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED9_MASK)
/*! @} */

/*! @name GEN2_CTRL_OFF - Link Width and Speed Change Control Register. */
/*! @{ */
#define PCIE_GEN2_CTRL_OFF_FAST_TRAINING_SEQ_MASK (0xFFU)
#define PCIE_GEN2_CTRL_OFF_FAST_TRAINING_SEQ_SHIFT (0U)
#define PCIE_GEN2_CTRL_OFF_FAST_TRAINING_SEQ(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_FAST_TRAINING_SEQ_SHIFT)) & PCIE_GEN2_CTRL_OFF_FAST_TRAINING_SEQ_MASK)
#define PCIE_GEN2_CTRL_OFF_NUM_OF_LANES_MASK     (0x1F00U)
#define PCIE_GEN2_CTRL_OFF_NUM_OF_LANES_SHIFT    (8U)
#define PCIE_GEN2_CTRL_OFF_NUM_OF_LANES(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_NUM_OF_LANES_SHIFT)) & PCIE_GEN2_CTRL_OFF_NUM_OF_LANES_MASK)
#define PCIE_GEN2_CTRL_OFF_PRE_DET_LANE_MASK     (0xE000U)
#define PCIE_GEN2_CTRL_OFF_PRE_DET_LANE_SHIFT    (13U)
#define PCIE_GEN2_CTRL_OFF_PRE_DET_LANE(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_PRE_DET_LANE_SHIFT)) & PCIE_GEN2_CTRL_OFF_PRE_DET_LANE_MASK)
#define PCIE_GEN2_CTRL_OFF_AUTO_LANE_FLIP_CTRL_EN_MASK (0x10000U)
#define PCIE_GEN2_CTRL_OFF_AUTO_LANE_FLIP_CTRL_EN_SHIFT (16U)
#define PCIE_GEN2_CTRL_OFF_DIRECT_SPEED_CHANGE_MASK (0x20000U)
#define PCIE_GEN2_CTRL_OFF_DIRECT_SPEED_CHANGE_SHIFT (17U)
#define PCIE_GEN2_CTRL_OFF_CONFIG_PHY_TX_CHANGE_MASK (0x40000U)
#define PCIE_GEN2_CTRL_OFF_CONFIG_PHY_TX_CHANGE_SHIFT (18U)
#define PCIE_GEN2_CTRL_OFF_CONFIG_TX_COMP_RX_MASK (0x80000U)
#define PCIE_GEN2_CTRL_OFF_CONFIG_TX_COMP_RX_SHIFT (19U)
#define PCIE_GEN2_CTRL_OFF_SEL_DEEMPHASIS_MASK   (0x100000U)
#define PCIE_GEN2_CTRL_OFF_SEL_DEEMPHASIS_SHIFT  (20U)
#define PCIE_GEN2_CTRL_OFF_GEN1_EI_INFERENCE_MASK (0x200000U)
#define PCIE_GEN2_CTRL_OFF_GEN1_EI_INFERENCE_SHIFT (21U)
#define PCIE_GEN2_CTRL_OFF_RSVDP_22_MASK         (0xFFC00000U)
#define PCIE_GEN2_CTRL_OFF_RSVDP_22_SHIFT        (22U)
#define PCIE_GEN2_CTRL_OFF_RSVDP_22(x)           (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_RSVDP_22_SHIFT)) & PCIE_GEN2_CTRL_OFF_RSVDP_22_MASK)
/*! @} */

/*! @name PHY_STATUS_OFF - PHY Status Register. */
/*! @{ */
#define PCIE_PHY_STATUS_OFF_PHY_STATUS_MASK      (0xFFFFFFFFU)
#define PCIE_PHY_STATUS_OFF_PHY_STATUS_SHIFT     (0U)
#define PCIE_PHY_STATUS_OFF_PHY_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_PHY_STATUS_OFF_PHY_STATUS_SHIFT)) & PCIE_PHY_STATUS_OFF_PHY_STATUS_MASK)
/*! @} */

/*! @name PHY_CONTROL_OFF - PHY Control Register. */
/*! @{ */
#define PCIE_PHY_CONTROL_OFF_PHY_CONTROL_MASK    (0xFFFFFFFFU)
#define PCIE_PHY_CONTROL_OFF_PHY_CONTROL_SHIFT   (0U)
#define PCIE_PHY_CONTROL_OFF_PHY_CONTROL(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_PHY_CONTROL_OFF_PHY_CONTROL_SHIFT)) & PCIE_PHY_CONTROL_OFF_PHY_CONTROL_MASK)
/*! @} */

/*! @name TRGT_MAP_CTRL_OFF - Programmable Target Map Control Register. */
/*! @{ */
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_PF_MASK (0x3FU)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_PF_SHIFT (0U)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_PF(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_PF_SHIFT)) & PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_PF_MASK)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_ROM_MASK (0x40U)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_ROM_SHIFT (6U)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_13_15_MASK (0xE000U)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_13_15_SHIFT (13U)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_13_15(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_13_15_SHIFT)) & PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_13_15_MASK)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_INDEX_MASK (0x1F0000U)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_INDEX_SHIFT (16U)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_INDEX(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_INDEX_SHIFT)) & PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_INDEX_MASK)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_21_31_MASK (0xFFE00000U)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_21_31_SHIFT (21U)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_21_31(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_21_31_SHIFT)) & PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_21_31_MASK)
/*! @} */

/*! @name MSI_CTRL_ADDR_OFF - Integrated MSI Reception Module (iMRM) Address Register. */
/*! @{ */
#define PCIE_MSI_CTRL_ADDR_OFF_MSI_CTRL_ADDR_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_ADDR_OFF_MSI_CTRL_ADDR_SHIFT (0U)
#define PCIE_MSI_CTRL_ADDR_OFF_MSI_CTRL_ADDR(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_ADDR_OFF_MSI_CTRL_ADDR_SHIFT)) & PCIE_MSI_CTRL_ADDR_OFF_MSI_CTRL_ADDR_MASK)
/*! @} */

/*! @name MSI_CTRL_UPPER_ADDR_OFF - Integrated MSI Reception Module Upper Address Register. */
/*! @{ */
#define PCIE_MSI_CTRL_UPPER_ADDR_OFF_MSI_CTRL_UPPER_ADDR_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_UPPER_ADDR_OFF_MSI_CTRL_UPPER_ADDR_SHIFT (0U)
#define PCIE_MSI_CTRL_UPPER_ADDR_OFF_MSI_CTRL_UPPER_ADDR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_UPPER_ADDR_OFF_MSI_CTRL_UPPER_ADDR_SHIFT)) & PCIE_MSI_CTRL_UPPER_ADDR_OFF_MSI_CTRL_UPPER_ADDR_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_0_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_0_EN_OFF_MSI_CTRL_INT_0_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_0_EN_OFF_MSI_CTRL_INT_0_EN_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_0_EN_OFF_MSI_CTRL_INT_0_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_0_EN_OFF_MSI_CTRL_INT_0_EN_SHIFT)) & PCIE_MSI_CTRL_INT_0_EN_OFF_MSI_CTRL_INT_0_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_0_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_0_MASK_OFF_MSI_CTRL_INT_0_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_0_MASK_OFF_MSI_CTRL_INT_0_MASK_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_0_MASK_OFF_MSI_CTRL_INT_0_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_0_MASK_OFF_MSI_CTRL_INT_0_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_0_MASK_OFF_MSI_CTRL_INT_0_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_0_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_0_STATUS_OFF_MSI_CTRL_INT_0_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_0_STATUS_OFF_MSI_CTRL_INT_0_STATUS_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_0_STATUS_OFF_MSI_CTRL_INT_0_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_0_STATUS_OFF_MSI_CTRL_INT_0_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_0_STATUS_OFF_MSI_CTRL_INT_0_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_1_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_1_EN_OFF_MSI_CTRL_INT_1_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_1_EN_OFF_MSI_CTRL_INT_1_EN_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_1_EN_OFF_MSI_CTRL_INT_1_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_1_EN_OFF_MSI_CTRL_INT_1_EN_SHIFT)) & PCIE_MSI_CTRL_INT_1_EN_OFF_MSI_CTRL_INT_1_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_1_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_1_MASK_OFF_MSI_CTRL_INT_1_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_1_MASK_OFF_MSI_CTRL_INT_1_MASK_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_1_MASK_OFF_MSI_CTRL_INT_1_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_1_MASK_OFF_MSI_CTRL_INT_1_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_1_MASK_OFF_MSI_CTRL_INT_1_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_1_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_1_STATUS_OFF_MSI_CTRL_INT_1_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_1_STATUS_OFF_MSI_CTRL_INT_1_STATUS_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_1_STATUS_OFF_MSI_CTRL_INT_1_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_1_STATUS_OFF_MSI_CTRL_INT_1_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_1_STATUS_OFF_MSI_CTRL_INT_1_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_2_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_2_EN_OFF_MSI_CTRL_INT_2_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_2_EN_OFF_MSI_CTRL_INT_2_EN_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_2_EN_OFF_MSI_CTRL_INT_2_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_2_EN_OFF_MSI_CTRL_INT_2_EN_SHIFT)) & PCIE_MSI_CTRL_INT_2_EN_OFF_MSI_CTRL_INT_2_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_2_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_2_MASK_OFF_MSI_CTRL_INT_2_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_2_MASK_OFF_MSI_CTRL_INT_2_MASK_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_2_MASK_OFF_MSI_CTRL_INT_2_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_2_MASK_OFF_MSI_CTRL_INT_2_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_2_MASK_OFF_MSI_CTRL_INT_2_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_2_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_2_STATUS_OFF_MSI_CTRL_INT_2_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_2_STATUS_OFF_MSI_CTRL_INT_2_STATUS_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_2_STATUS_OFF_MSI_CTRL_INT_2_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_2_STATUS_OFF_MSI_CTRL_INT_2_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_2_STATUS_OFF_MSI_CTRL_INT_2_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_3_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_3_EN_OFF_MSI_CTRL_INT_3_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_3_EN_OFF_MSI_CTRL_INT_3_EN_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_3_EN_OFF_MSI_CTRL_INT_3_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_3_EN_OFF_MSI_CTRL_INT_3_EN_SHIFT)) & PCIE_MSI_CTRL_INT_3_EN_OFF_MSI_CTRL_INT_3_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_3_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_3_MASK_OFF_MSI_CTRL_INT_3_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_3_MASK_OFF_MSI_CTRL_INT_3_MASK_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_3_MASK_OFF_MSI_CTRL_INT_3_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_3_MASK_OFF_MSI_CTRL_INT_3_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_3_MASK_OFF_MSI_CTRL_INT_3_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_3_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_3_STATUS_OFF_MSI_CTRL_INT_3_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_3_STATUS_OFF_MSI_CTRL_INT_3_STATUS_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_3_STATUS_OFF_MSI_CTRL_INT_3_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_3_STATUS_OFF_MSI_CTRL_INT_3_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_3_STATUS_OFF_MSI_CTRL_INT_3_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_4_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_4_EN_OFF_MSI_CTRL_INT_4_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_4_EN_OFF_MSI_CTRL_INT_4_EN_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_4_EN_OFF_MSI_CTRL_INT_4_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_4_EN_OFF_MSI_CTRL_INT_4_EN_SHIFT)) & PCIE_MSI_CTRL_INT_4_EN_OFF_MSI_CTRL_INT_4_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_4_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_4_MASK_OFF_MSI_CTRL_INT_4_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_4_MASK_OFF_MSI_CTRL_INT_4_MASK_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_4_MASK_OFF_MSI_CTRL_INT_4_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_4_MASK_OFF_MSI_CTRL_INT_4_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_4_MASK_OFF_MSI_CTRL_INT_4_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_4_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_4_STATUS_OFF_MSI_CTRL_INT_4_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_4_STATUS_OFF_MSI_CTRL_INT_4_STATUS_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_4_STATUS_OFF_MSI_CTRL_INT_4_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_4_STATUS_OFF_MSI_CTRL_INT_4_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_4_STATUS_OFF_MSI_CTRL_INT_4_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_5_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_5_EN_OFF_MSI_CTRL_INT_5_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_5_EN_OFF_MSI_CTRL_INT_5_EN_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_5_EN_OFF_MSI_CTRL_INT_5_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_5_EN_OFF_MSI_CTRL_INT_5_EN_SHIFT)) & PCIE_MSI_CTRL_INT_5_EN_OFF_MSI_CTRL_INT_5_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_5_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_5_MASK_OFF_MSI_CTRL_INT_5_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_5_MASK_OFF_MSI_CTRL_INT_5_MASK_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_5_MASK_OFF_MSI_CTRL_INT_5_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_5_MASK_OFF_MSI_CTRL_INT_5_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_5_MASK_OFF_MSI_CTRL_INT_5_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_5_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_5_STATUS_OFF_MSI_CTRL_INT_5_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_5_STATUS_OFF_MSI_CTRL_INT_5_STATUS_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_5_STATUS_OFF_MSI_CTRL_INT_5_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_5_STATUS_OFF_MSI_CTRL_INT_5_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_5_STATUS_OFF_MSI_CTRL_INT_5_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_6_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_6_EN_OFF_MSI_CTRL_INT_6_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_6_EN_OFF_MSI_CTRL_INT_6_EN_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_6_EN_OFF_MSI_CTRL_INT_6_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_6_EN_OFF_MSI_CTRL_INT_6_EN_SHIFT)) & PCIE_MSI_CTRL_INT_6_EN_OFF_MSI_CTRL_INT_6_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_6_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_6_MASK_OFF_MSI_CTRL_INT_6_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_6_MASK_OFF_MSI_CTRL_INT_6_MASK_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_6_MASK_OFF_MSI_CTRL_INT_6_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_6_MASK_OFF_MSI_CTRL_INT_6_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_6_MASK_OFF_MSI_CTRL_INT_6_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_6_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_6_STATUS_OFF_MSI_CTRL_INT_6_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_6_STATUS_OFF_MSI_CTRL_INT_6_STATUS_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_6_STATUS_OFF_MSI_CTRL_INT_6_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_6_STATUS_OFF_MSI_CTRL_INT_6_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_6_STATUS_OFF_MSI_CTRL_INT_6_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_7_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_7_EN_OFF_MSI_CTRL_INT_7_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_7_EN_OFF_MSI_CTRL_INT_7_EN_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_7_EN_OFF_MSI_CTRL_INT_7_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_7_EN_OFF_MSI_CTRL_INT_7_EN_SHIFT)) & PCIE_MSI_CTRL_INT_7_EN_OFF_MSI_CTRL_INT_7_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_7_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_7_MASK_OFF_MSI_CTRL_INT_7_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_7_MASK_OFF_MSI_CTRL_INT_7_MASK_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_7_MASK_OFF_MSI_CTRL_INT_7_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_7_MASK_OFF_MSI_CTRL_INT_7_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_7_MASK_OFF_MSI_CTRL_INT_7_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_7_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */
#define PCIE_MSI_CTRL_INT_7_STATUS_OFF_MSI_CTRL_INT_7_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_7_STATUS_OFF_MSI_CTRL_INT_7_STATUS_SHIFT (0U)
#define PCIE_MSI_CTRL_INT_7_STATUS_OFF_MSI_CTRL_INT_7_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_7_STATUS_OFF_MSI_CTRL_INT_7_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_7_STATUS_OFF_MSI_CTRL_INT_7_STATUS_MASK)
/*! @} */

/*! @name MSI_GPIO_IO_OFF - Integrated MSI Reception Module General Purpose IO Register. */
/*! @{ */
#define PCIE_MSI_GPIO_IO_OFF_MSI_GPIO_REG_MASK   (0xFFFFFFFFU)
#define PCIE_MSI_GPIO_IO_OFF_MSI_GPIO_REG_SHIFT  (0U)
#define PCIE_MSI_GPIO_IO_OFF_MSI_GPIO_REG(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_GPIO_IO_OFF_MSI_GPIO_REG_SHIFT)) & PCIE_MSI_GPIO_IO_OFF_MSI_GPIO_REG_MASK)
/*! @} */

/*! @name CLOCK_GATING_CTRL_OFF - RADM clock gating enable control register. */
/*! @{ */
#define PCIE_CLOCK_GATING_CTRL_OFF_RADM_CLK_GATING_EN_MASK (0x1U)
#define PCIE_CLOCK_GATING_CTRL_OFF_RADM_CLK_GATING_EN_SHIFT (0U)
#define PCIE_CLOCK_GATING_CTRL_OFF_RSVDP_1_MASK  (0xFFFFFFFEU)
#define PCIE_CLOCK_GATING_CTRL_OFF_RSVDP_1_SHIFT (1U)
#define PCIE_CLOCK_GATING_CTRL_OFF_RSVDP_1(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_CLOCK_GATING_CTRL_OFF_RSVDP_1_SHIFT)) & PCIE_CLOCK_GATING_CTRL_OFF_RSVDP_1_MASK)
/*! @} */

/*! @name ORDER_RULE_CTRL_OFF - Order Rule Control Register. */
/*! @{ */
#define PCIE_ORDER_RULE_CTRL_OFF_NP_PASS_P_MASK  (0xFFU)
#define PCIE_ORDER_RULE_CTRL_OFF_NP_PASS_P_SHIFT (0U)
#define PCIE_ORDER_RULE_CTRL_OFF_NP_PASS_P(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_ORDER_RULE_CTRL_OFF_NP_PASS_P_SHIFT)) & PCIE_ORDER_RULE_CTRL_OFF_NP_PASS_P_MASK)
#define PCIE_ORDER_RULE_CTRL_OFF_CPL_PASS_P_MASK (0xFF00U)
#define PCIE_ORDER_RULE_CTRL_OFF_CPL_PASS_P_SHIFT (8U)
#define PCIE_ORDER_RULE_CTRL_OFF_CPL_PASS_P(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_ORDER_RULE_CTRL_OFF_CPL_PASS_P_SHIFT)) & PCIE_ORDER_RULE_CTRL_OFF_CPL_PASS_P_MASK)
#define PCIE_ORDER_RULE_CTRL_OFF_RSVDP_16_MASK   (0xFFFF0000U)
#define PCIE_ORDER_RULE_CTRL_OFF_RSVDP_16_SHIFT  (16U)
#define PCIE_ORDER_RULE_CTRL_OFF_RSVDP_16(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_ORDER_RULE_CTRL_OFF_RSVDP_16_SHIFT)) & PCIE_ORDER_RULE_CTRL_OFF_RSVDP_16_MASK)
/*! @} */

/*! @name PIPE_LOOPBACK_CONTROL_OFF - PIPE Loopback Control Register. */
/*! @{ */
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_LPBK_RXVALID_MASK (0xFFFFU)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_LPBK_RXVALID_SHIFT (0U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_LPBK_RXVALID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PIPE_LOOPBACK_CONTROL_OFF_LPBK_RXVALID_SHIFT)) & PCIE_PIPE_LOOPBACK_CONTROL_OFF_LPBK_RXVALID_MASK)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_LANE_MASK (0x3F0000U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_LANE_SHIFT (16U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_LANE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_LANE_SHIFT)) & PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_LANE_MASK)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_22_MASK (0xC00000U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_22_SHIFT (22U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_22(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_22_SHIFT)) & PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_22_MASK)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_VALUE_MASK (0x7000000U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_VALUE_SHIFT (24U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_VALUE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_VALUE_SHIFT)) & PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_VALUE_MASK)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_27_MASK (0x78000000U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_27_SHIFT (27U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_27(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_27_SHIFT)) & PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_27_MASK)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_PIPE_LOOPBACK_MASK (0x80000000U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_PIPE_LOOPBACK_SHIFT (31U)
/*! @} */

/*! @name MISC_CONTROL_1_OFF - DBI Read-Only Write Enable Register. */
/*! @{ */
#define PCIE_MISC_CONTROL_1_OFF_DBI_RO_WR_EN_MASK (0x1U)
#define PCIE_MISC_CONTROL_1_OFF_DBI_RO_WR_EN_SHIFT (0U)
#define PCIE_MISC_CONTROL_1_OFF_DEFAULT_TARGET_MASK (0x2U)
#define PCIE_MISC_CONTROL_1_OFF_DEFAULT_TARGET_SHIFT (1U)
#define PCIE_MISC_CONTROL_1_OFF_UR_CA_MASK_4_TRGT1_MASK (0x4U)
#define PCIE_MISC_CONTROL_1_OFF_UR_CA_MASK_4_TRGT1_SHIFT (2U)
#define PCIE_MISC_CONTROL_1_OFF_SIMPLIFIED_REPLAY_TIMER_MASK (0x8U)
#define PCIE_MISC_CONTROL_1_OFF_SIMPLIFIED_REPLAY_TIMER_SHIFT (3U)
#define PCIE_MISC_CONTROL_1_OFF_ARI_DEVICE_NUMBER_MASK (0x20U)
#define PCIE_MISC_CONTROL_1_OFF_ARI_DEVICE_NUMBER_SHIFT (5U)
#define PCIE_MISC_CONTROL_1_OFF_RSVDP_6_MASK     (0xFFFFFFC0U)
#define PCIE_MISC_CONTROL_1_OFF_RSVDP_6_SHIFT    (6U)
#define PCIE_MISC_CONTROL_1_OFF_RSVDP_6(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_MISC_CONTROL_1_OFF_RSVDP_6_SHIFT)) & PCIE_MISC_CONTROL_1_OFF_RSVDP_6_MASK)
/*! @} */

/*! @name MULTI_LANE_CONTROL_OFF - UpConfigure Multi-lane Control Register. */
/*! @{ */
#define PCIE_MULTI_LANE_CONTROL_OFF_TARGET_LINK_WIDTH_MASK (0x3FU)
#define PCIE_MULTI_LANE_CONTROL_OFF_TARGET_LINK_WIDTH_SHIFT (0U)
#define PCIE_MULTI_LANE_CONTROL_OFF_TARGET_LINK_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MULTI_LANE_CONTROL_OFF_TARGET_LINK_WIDTH_SHIFT)) & PCIE_MULTI_LANE_CONTROL_OFF_TARGET_LINK_WIDTH_MASK)
#define PCIE_MULTI_LANE_CONTROL_OFF_DIRECT_LINK_WIDTH_CHANGE_MASK (0x40U)
#define PCIE_MULTI_LANE_CONTROL_OFF_DIRECT_LINK_WIDTH_CHANGE_SHIFT (6U)
#define PCIE_MULTI_LANE_CONTROL_OFF_UPCONFIGURE_SUPPORT_MASK (0x80U)
#define PCIE_MULTI_LANE_CONTROL_OFF_UPCONFIGURE_SUPPORT_SHIFT (7U)
#define PCIE_MULTI_LANE_CONTROL_OFF_RSVDP_8_MASK (0xFFFFFF00U)
#define PCIE_MULTI_LANE_CONTROL_OFF_RSVDP_8_SHIFT (8U)
#define PCIE_MULTI_LANE_CONTROL_OFF_RSVDP_8(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_MULTI_LANE_CONTROL_OFF_RSVDP_8_SHIFT)) & PCIE_MULTI_LANE_CONTROL_OFF_RSVDP_8_MASK)
/*! @} */

/*! @name PHY_INTEROP_CTRL_OFF - PHY Interoperability Control Register. */
/*! @{ */
#define PCIE_PHY_INTEROP_CTRL_OFF_RXSTANDBY_CONTROL_MASK (0x7FU)
#define PCIE_PHY_INTEROP_CTRL_OFF_RXSTANDBY_CONTROL_SHIFT (0U)
#define PCIE_PHY_INTEROP_CTRL_OFF_RXSTANDBY_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PHY_INTEROP_CTRL_OFF_RXSTANDBY_CONTROL_SHIFT)) & PCIE_PHY_INTEROP_CTRL_OFF_RXSTANDBY_CONTROL_MASK)
#define PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_7_MASK   (0x80U)
#define PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_7_SHIFT  (7U)
#define PCIE_PHY_INTEROP_CTRL_OFF_L1SUB_EXIT_MODE_MASK (0x100U)
#define PCIE_PHY_INTEROP_CTRL_OFF_L1SUB_EXIT_MODE_SHIFT (8U)
#define PCIE_PHY_INTEROP_CTRL_OFF_L1_NOWAIT_P1_MASK (0x200U)
#define PCIE_PHY_INTEROP_CTRL_OFF_L1_NOWAIT_P1_SHIFT (9U)
#define PCIE_PHY_INTEROP_CTRL_OFF_L1_CLK_SEL_MASK (0x400U)
#define PCIE_PHY_INTEROP_CTRL_OFF_L1_CLK_SEL_SHIFT (10U)
#define PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_11_MASK  (0xFFFFF800U)
#define PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_11_SHIFT (11U)
#define PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_11(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_11_SHIFT)) & PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_11_MASK)
/*! @} */

/*! @name TRGT_CPL_LUT_DELETE_ENTRY_OFF - TRGT_CPL_LUT Delete Entry Control register. */
/*! @{ */
#define PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_LOOK_UP_ID_MASK (0x7FFFFFFFU)
#define PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_LOOK_UP_ID_SHIFT (0U)
#define PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_LOOK_UP_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_LOOK_UP_ID_SHIFT)) & PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_LOOK_UP_ID_MASK)
#define PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_DELETE_EN_MASK (0x80000000U)
#define PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_DELETE_EN_SHIFT (31U)
/*! @} */

/*! @name LINK_FLUSH_CONTROL_OFF - Link Reset Request Flush Control Register. */
/*! @{ */
#define PCIE_LINK_FLUSH_CONTROL_OFF_AUTO_FLUSH_EN_MASK (0x1U)
#define PCIE_LINK_FLUSH_CONTROL_OFF_AUTO_FLUSH_EN_SHIFT (0U)
#define PCIE_LINK_FLUSH_CONTROL_OFF_RSVDP_1_MASK (0xFFFFFEU)
#define PCIE_LINK_FLUSH_CONTROL_OFF_RSVDP_1_SHIFT (1U)
#define PCIE_LINK_FLUSH_CONTROL_OFF_RSVDP_1(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_FLUSH_CONTROL_OFF_RSVDP_1_SHIFT)) & PCIE_LINK_FLUSH_CONTROL_OFF_RSVDP_1_MASK)
#define PCIE_LINK_FLUSH_CONTROL_OFF_RSVD_I_8_MASK (0xFF000000U)
#define PCIE_LINK_FLUSH_CONTROL_OFF_RSVD_I_8_SHIFT (24U)
#define PCIE_LINK_FLUSH_CONTROL_OFF_RSVD_I_8(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_FLUSH_CONTROL_OFF_RSVD_I_8_SHIFT)) & PCIE_LINK_FLUSH_CONTROL_OFF_RSVD_I_8_MASK)
/*! @} */

/*! @name AMBA_ERROR_RESPONSE_DEFAULT_OFF - AXI Bridge Slave Error Response Register. */
/*! @{ */
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_GLOBAL_MASK (0x1U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_GLOBAL_SHIFT (0U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_1_MASK (0x2U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_1_SHIFT (1U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_VENDORID_MASK (0x4U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_VENDORID_SHIFT (2U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_CRS_MASK (0x18U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_CRS_SHIFT (3U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_CRS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_CRS_SHIFT)) & PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_CRS_MASK)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_5_MASK (0x3E0U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_5_SHIFT (5U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_5(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_5_SHIFT)) & PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_5_MASK)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_MAP_MASK (0xFC00U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_MAP_SHIFT (10U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_MAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_MAP_SHIFT)) & PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_MAP_MASK)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_16_MASK (0xFFFF0000U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_16_SHIFT (16U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_16(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_16_SHIFT)) & PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_16_MASK)
/*! @} */

/*! @name AMBA_LINK_TIMEOUT_OFF - Link Down AXI Bridge Slave Timeout Register. */
/*! @{ */
#define PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_PERIOD_DEFAULT_MASK (0xFFU)
#define PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_PERIOD_DEFAULT_SHIFT (0U)
#define PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_PERIOD_DEFAULT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_PERIOD_DEFAULT_SHIFT)) & PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_PERIOD_DEFAULT_MASK)
#define PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_ENABLE_DEFAULT_MASK (0x100U)
#define PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_ENABLE_DEFAULT_SHIFT (8U)
#define PCIE_AMBA_LINK_TIMEOUT_OFF_RSVDP_9_MASK  (0xFFFFFE00U)
#define PCIE_AMBA_LINK_TIMEOUT_OFF_RSVDP_9_SHIFT (9U)
#define PCIE_AMBA_LINK_TIMEOUT_OFF_RSVDP_9(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_LINK_TIMEOUT_OFF_RSVDP_9_SHIFT)) & PCIE_AMBA_LINK_TIMEOUT_OFF_RSVDP_9_MASK)
/*! @} */

/*! @name AMBA_ORDERING_CTRL_OFF - AMBA Ordering Control. */
/*! @{ */
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_0_MASK (0x1U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_0_SHIFT (0U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_SNP_EN_MASK (0x2U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_SNP_EN_SHIFT (1U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_2_MASK (0x4U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_2_SHIFT (2U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ORDR_P_EVENT_SEL_MASK (0x18U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ORDR_P_EVENT_SEL_SHIFT (3U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ORDR_P_EVENT_SEL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ORDR_P_EVENT_SEL_SHIFT)) & PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ORDR_P_EVENT_SEL_MASK)
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_5_MASK (0x60U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_5_SHIFT (5U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_5(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_5_SHIFT)) & PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_5_MASK)
#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ZEROLREAD_FW_MASK (0x80U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ZEROLREAD_FW_SHIFT (7U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_8_MASK (0xFFFFFF00U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_8_SHIFT (8U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_8(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_8_SHIFT)) & PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_8_MASK)
/*! @} */

/*! @name COHERENCY_CONTROL_1_OFF - ACE Cache Coherency Control Register 1 */
/*! @{ */
#define PCIE_COHERENCY_CONTROL_1_OFF_CFG_MEMTYPE_VALUE_MASK (0x1U)
#define PCIE_COHERENCY_CONTROL_1_OFF_CFG_MEMTYPE_VALUE_SHIFT (0U)
#define PCIE_COHERENCY_CONTROL_1_OFF_RSVDP_1_MASK (0x2U)
#define PCIE_COHERENCY_CONTROL_1_OFF_RSVDP_1_SHIFT (1U)
#define PCIE_COHERENCY_CONTROL_1_OFF_CFG_MEMTYPE_BOUNDARY_LOW_ADDR_MASK (0xFFFFFFFCU)
#define PCIE_COHERENCY_CONTROL_1_OFF_CFG_MEMTYPE_BOUNDARY_LOW_ADDR_SHIFT (2U)
#define PCIE_COHERENCY_CONTROL_1_OFF_CFG_MEMTYPE_BOUNDARY_LOW_ADDR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_COHERENCY_CONTROL_1_OFF_CFG_MEMTYPE_BOUNDARY_LOW_ADDR_SHIFT)) & PCIE_COHERENCY_CONTROL_1_OFF_CFG_MEMTYPE_BOUNDARY_LOW_ADDR_MASK)
/*! @} */

/*! @name COHERENCY_CONTROL_2_OFF - ACE Cache Coherency Control Register 2 */
/*! @{ */
#define PCIE_COHERENCY_CONTROL_2_OFF_CFG_MEMTYPE_BOUNDARY_HIGH_ADDR_MASK (0xFFFFFFFFU)
#define PCIE_COHERENCY_CONTROL_2_OFF_CFG_MEMTYPE_BOUNDARY_HIGH_ADDR_SHIFT (0U)
#define PCIE_COHERENCY_CONTROL_2_OFF_CFG_MEMTYPE_BOUNDARY_HIGH_ADDR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_COHERENCY_CONTROL_2_OFF_CFG_MEMTYPE_BOUNDARY_HIGH_ADDR_SHIFT)) & PCIE_COHERENCY_CONTROL_2_OFF_CFG_MEMTYPE_BOUNDARY_HIGH_ADDR_MASK)
/*! @} */

/*! @name COHERENCY_CONTROL_3_OFF - ACE Cache Coherency Control Register 3 */
/*! @{ */
#define PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_MODE_MASK (0x78U)
#define PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_MODE_SHIFT (3U)
#define PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_MODE_SHIFT)) & PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_MODE_MASK)
#define PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_MODE_MASK (0x7800U)
#define PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_MODE_SHIFT (11U)
#define PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_MODE_SHIFT)) & PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_MODE_MASK)
#define PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_VALUE_MASK (0x780000U)
#define PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_VALUE_SHIFT (19U)
#define PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_VALUE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_VALUE_SHIFT)) & PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_VALUE_MASK)
#define PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_VALUE_MASK (0x78000000U)
#define PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_VALUE_SHIFT (27U)
#define PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_VALUE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_VALUE_SHIFT)) & PCIE_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_VALUE_MASK)
/*! @} */

/*! @name AXI_MSTR_MSG_ADDR_LOW_OFF - Lower 20 bits of the programmable AXI address where Messages coming from wire are mapped to. */
/*! @{ */
#define PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_RESERVED_MASK (0xFFFU)
#define PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_RESERVED_SHIFT (0U)
#define PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_RESERVED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_RESERVED_SHIFT)) & PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_RESERVED_MASK)
#define PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_MASK (0xFFFFF000U)
#define PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_SHIFT (12U)
#define PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_SHIFT)) & PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_MASK)
/*! @} */

/*! @name AXI_MSTR_MSG_ADDR_HIGH_OFF - Upper 32 bits of the programmable AXI address where Messages coming from wire are mapped to. */
/*! @{ */
#define PCIE_AXI_MSTR_MSG_ADDR_HIGH_OFF_CFG_AXIMSTR_MSG_ADDR_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_AXI_MSTR_MSG_ADDR_HIGH_OFF_CFG_AXIMSTR_MSG_ADDR_HIGH_SHIFT (0U)
#define PCIE_AXI_MSTR_MSG_ADDR_HIGH_OFF_CFG_AXIMSTR_MSG_ADDR_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AXI_MSTR_MSG_ADDR_HIGH_OFF_CFG_AXIMSTR_MSG_ADDR_HIGH_SHIFT)) & PCIE_AXI_MSTR_MSG_ADDR_HIGH_OFF_CFG_AXIMSTR_MSG_ADDR_HIGH_MASK)
/*! @} */

/*! @name PCIE_VERSION_NUMBER_OFF - PCIe Controller IIP Release Version Number. */
/*! @{ */
#define PCIE_PCIE_VERSION_NUMBER_OFF_VERSION_NUMBER_MASK (0xFFFFFFFFU)
#define PCIE_PCIE_VERSION_NUMBER_OFF_VERSION_NUMBER_SHIFT (0U)
#define PCIE_PCIE_VERSION_NUMBER_OFF_VERSION_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_VERSION_NUMBER_OFF_VERSION_NUMBER_SHIFT)) & PCIE_PCIE_VERSION_NUMBER_OFF_VERSION_NUMBER_MASK)
/*! @} */

/*! @name PCIE_VERSION_TYPE_OFF - PCIe Controller IIP Release Version Type. */
/*! @{ */
#define PCIE_PCIE_VERSION_TYPE_OFF_VERSION_TYPE_MASK (0xFFFFFFFFU)
#define PCIE_PCIE_VERSION_TYPE_OFF_VERSION_TYPE_SHIFT (0U)
#define PCIE_PCIE_VERSION_TYPE_OFF_VERSION_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_VERSION_TYPE_OFF_VERSION_TYPE_SHIFT)) & PCIE_PCIE_VERSION_TYPE_OFF_VERSION_TYPE_MASK)
/*! @} */

/*! @name AUX_CLK_FREQ_OFF - Auxiliary Clock Frequency Control Register. */
/*! @{ */
#define PCIE_AUX_CLK_FREQ_OFF_AUX_CLK_FREQ_MASK  (0x3FFU)
#define PCIE_AUX_CLK_FREQ_OFF_AUX_CLK_FREQ_SHIFT (0U)
#define PCIE_AUX_CLK_FREQ_OFF_AUX_CLK_FREQ(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_AUX_CLK_FREQ_OFF_AUX_CLK_FREQ_SHIFT)) & PCIE_AUX_CLK_FREQ_OFF_AUX_CLK_FREQ_MASK)
#define PCIE_AUX_CLK_FREQ_OFF_RSVDP_10_MASK      (0xFFFFFC00U)
#define PCIE_AUX_CLK_FREQ_OFF_RSVDP_10_SHIFT     (10U)
#define PCIE_AUX_CLK_FREQ_OFF_RSVDP_10(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_AUX_CLK_FREQ_OFF_RSVDP_10_SHIFT)) & PCIE_AUX_CLK_FREQ_OFF_RSVDP_10_MASK)
/*! @} */

/*! @name L1_SUBSTATES_OFF - L1 Substates Timing Register. */
/*! @{ */
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_POWER_OFF_MASK (0x3U)
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_POWER_OFF_SHIFT (0U)
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_POWER_OFF(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1_SUBSTATES_OFF_L1SUB_T_POWER_OFF_SHIFT)) & PCIE_L1_SUBSTATES_OFF_L1SUB_T_POWER_OFF_MASK)
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_L1_2_MASK  (0x3CU)
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_L1_2_SHIFT (2U)
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_L1_2(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_L1_SUBSTATES_OFF_L1SUB_T_L1_2_SHIFT)) & PCIE_L1_SUBSTATES_OFF_L1SUB_T_L1_2_MASK)
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_PCLKACK_MASK (0xC0U)
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_PCLKACK_SHIFT (6U)
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_PCLKACK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1_SUBSTATES_OFF_L1SUB_T_PCLKACK_SHIFT)) & PCIE_L1_SUBSTATES_OFF_L1SUB_T_PCLKACK_MASK)
#define PCIE_L1_SUBSTATES_OFF_RSVDP_8_MASK       (0xFFFFFF00U)
#define PCIE_L1_SUBSTATES_OFF_RSVDP_8_SHIFT      (8U)
#define PCIE_L1_SUBSTATES_OFF_RSVDP_8(x)         (((uint32_t)(((uint32_t)(x)) << PCIE_L1_SUBSTATES_OFF_RSVDP_8_SHIFT)) & PCIE_L1_SUBSTATES_OFF_RSVDP_8_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_OUTBOUND_0 - iATU Region Control 1 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TYPE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TYPE_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TC_SHIFT (5U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TC_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TD_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_ATTR_SHIFT (9U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_ATTR_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_INCREASE_REGION_SIZE_SHIFT (13U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_CTRL_1_FUNC_NUM_SHIFT (20U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_OUTBOUND_0 - iATU Region Control 2 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_MSG_CODE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_MSG_CODE_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_MASK (0xFF00U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_SUBSTITUTE_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_SUBSTITUTE_EN_SHIFT (16U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_FUNC_BYPASS_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_FUNC_BYPASS_SHIFT (19U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_SNP_MASK (0x100000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_SNP_SHIFT (20U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INHIBIT_PAYLOAD_MASK (0x400000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INHIBIT_PAYLOAD_SHIFT (22U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_HEADER_SUBSTITUTE_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_HEADER_SUBSTITUTE_EN_SHIFT (23U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_DMA_BYPASS_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_DMA_BYPASS_SHIFT (27U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_CFG_SHIFT_MODE_SHIFT (28U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INVERT_MODE_SHIFT (29U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_REGION_EN_SHIFT (31U)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0 - iATU Lower Base Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_HW_SHIFT (0U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_HW_MASK)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_RW_SHIFT (16U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0 - iATU Upper Base Address Register. */
/*! @{ */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_UPPER_BASE_RW_SHIFT (0U)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_OUTBOUND_0 - iATU Limit Address Register. */
/*! @{ */
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_HW_SHIFT (0U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_HW_MASK)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_RW_SHIFT (16U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0 - iATU Lower Target Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_LWR_TARGET_RW_OUTBOUND_MASK (0xFFFFFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_LWR_TARGET_RW_OUTBOUND_SHIFT (0U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_LWR_TARGET_RW_OUTBOUND(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_LWR_TARGET_RW_OUTBOUND_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_LWR_TARGET_RW_OUTBOUND_MASK)
/*! @} */

/*! @name IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0 - iATU Upper Target Address Register. */
/*! @{ */
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_UPPER_TARGET_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_UPPER_TARGET_RW_SHIFT (0U)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_UPPER_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_UPPER_TARGET_RW_SHIFT)) & PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_UPPER_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_INBOUND_0 - iATU Region Control 1 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TYPE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TYPE_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TC_SHIFT (5U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TC_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TD_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_ATTR_SHIFT (9U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_ATTR_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_INCREASE_REGION_SIZE_SHIFT (13U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_CTRL_1_FUNC_NUM_SHIFT (20U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_INBOUND_0 - iATU Region Control 2 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_BAR_NUM_MASK (0x700U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_BAR_NUM_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_BAR_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_BAR_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_BAR_NUM_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_TYPE_MATCH_MODE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_TYPE_MATCH_MODE_SHIFT (13U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TC_MATCH_EN_MASK (0x4000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TC_MATCH_EN_SHIFT (14U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TD_MATCH_EN_MASK (0x8000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TD_MATCH_EN_SHIFT (15U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_ATTR_MATCH_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_ATTR_MATCH_EN_SHIFT (16U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUNC_NUM_MATCH_EN_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUNC_NUM_MATCH_EN_SHIFT (19U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_MATCH_EN_MASK (0x200000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_MATCH_EN_SHIFT (21U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_SINGLE_ADDR_LOC_TRANS_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_SINGLE_ADDR_LOC_TRANS_EN_SHIFT (23U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_RESPONSE_CODE_MASK (0x3000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_RESPONSE_CODE_SHIFT (24U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_RESPONSE_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_RESPONSE_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_RESPONSE_CODE_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUZZY_TYPE_MATCH_CODE_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUZZY_TYPE_MATCH_CODE_SHIFT (27U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_CFG_SHIFT_MODE_SHIFT (28U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_INVERT_MODE_SHIFT (29U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MATCH_MODE_MASK (0x40000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MATCH_MODE_SHIFT (30U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_REGION_EN_SHIFT (31U)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_INBOUND_0 - iATU Lower Base Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_HW_SHIFT (0U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_HW_MASK)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_RW_SHIFT (16U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_INBOUND_0 - iATU Upper Base Address Register. */
/*! @{ */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_0_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_0_UPPER_BASE_RW_SHIFT (0U)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_0_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_0_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_0_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_INBOUND_0 - iATU Limit Address Register. */
/*! @{ */
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_HW_SHIFT (0U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_HW_MASK)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_RW_SHIFT (16U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_INBOUND_0 - iATU Lower Target Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_HW_SHIFT (0U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_HW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_HW_MASK)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_RW_SHIFT (16U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_RW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_OUTBOUND_1 - iATU Region Control 1 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TYPE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TYPE_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TC_SHIFT (5U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TC_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TD_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_ATTR_SHIFT (9U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_ATTR_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_INCREASE_REGION_SIZE_SHIFT (13U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_CTRL_1_FUNC_NUM_SHIFT (20U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_OUTBOUND_1 - iATU Region Control 2 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_MSG_CODE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_MSG_CODE_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_MASK (0xFF00U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_SUBSTITUTE_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_SUBSTITUTE_EN_SHIFT (16U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_FUNC_BYPASS_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_FUNC_BYPASS_SHIFT (19U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_SNP_MASK (0x100000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_SNP_SHIFT (20U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INHIBIT_PAYLOAD_MASK (0x400000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INHIBIT_PAYLOAD_SHIFT (22U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_HEADER_SUBSTITUTE_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_HEADER_SUBSTITUTE_EN_SHIFT (23U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_DMA_BYPASS_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_DMA_BYPASS_SHIFT (27U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_CFG_SHIFT_MODE_SHIFT (28U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INVERT_MODE_SHIFT (29U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_REGION_EN_SHIFT (31U)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1 - iATU Lower Base Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_HW_SHIFT (0U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_HW_MASK)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_RW_SHIFT (16U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1 - iATU Upper Base Address Register. */
/*! @{ */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1_UPPER_BASE_RW_SHIFT (0U)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_OUTBOUND_1 - iATU Limit Address Register. */
/*! @{ */
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_HW_SHIFT (0U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_HW_MASK)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_RW_SHIFT (16U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1 - iATU Lower Target Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1_LWR_TARGET_RW_OUTBOUND_MASK (0xFFFFFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1_LWR_TARGET_RW_OUTBOUND_SHIFT (0U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1_LWR_TARGET_RW_OUTBOUND(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1_LWR_TARGET_RW_OUTBOUND_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1_LWR_TARGET_RW_OUTBOUND_MASK)
/*! @} */

/*! @name IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1 - iATU Upper Target Address Register. */
/*! @{ */
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1_UPPER_TARGET_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1_UPPER_TARGET_RW_SHIFT (0U)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1_UPPER_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1_UPPER_TARGET_RW_SHIFT)) & PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1_UPPER_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_INBOUND_1 - iATU Region Control 1 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TYPE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TYPE_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TC_SHIFT (5U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TC_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TD_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_ATTR_SHIFT (9U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_ATTR_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_INCREASE_REGION_SIZE_SHIFT (13U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_CTRL_1_FUNC_NUM_SHIFT (20U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_INBOUND_1 - iATU Region Control 2 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_BAR_NUM_MASK (0x700U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_BAR_NUM_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_BAR_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_BAR_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_BAR_NUM_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_TYPE_MATCH_MODE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_TYPE_MATCH_MODE_SHIFT (13U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TC_MATCH_EN_MASK (0x4000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TC_MATCH_EN_SHIFT (14U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TD_MATCH_EN_MASK (0x8000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TD_MATCH_EN_SHIFT (15U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_ATTR_MATCH_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_ATTR_MATCH_EN_SHIFT (16U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUNC_NUM_MATCH_EN_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUNC_NUM_MATCH_EN_SHIFT (19U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_MATCH_EN_MASK (0x200000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_MATCH_EN_SHIFT (21U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_SINGLE_ADDR_LOC_TRANS_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_SINGLE_ADDR_LOC_TRANS_EN_SHIFT (23U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_RESPONSE_CODE_MASK (0x3000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_RESPONSE_CODE_SHIFT (24U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_RESPONSE_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_RESPONSE_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_RESPONSE_CODE_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUZZY_TYPE_MATCH_CODE_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUZZY_TYPE_MATCH_CODE_SHIFT (27U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_CFG_SHIFT_MODE_SHIFT (28U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_INVERT_MODE_SHIFT (29U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MATCH_MODE_MASK (0x40000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MATCH_MODE_SHIFT (30U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_REGION_EN_SHIFT (31U)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_INBOUND_1 - iATU Lower Base Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_HW_SHIFT (0U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_HW_MASK)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_RW_SHIFT (16U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_INBOUND_1 - iATU Upper Base Address Register. */
/*! @{ */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_1_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_1_UPPER_BASE_RW_SHIFT (0U)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_1_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_1_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_1_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_INBOUND_1 - iATU Limit Address Register. */
/*! @{ */
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_HW_SHIFT (0U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_HW_MASK)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_RW_SHIFT (16U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_INBOUND_1 - iATU Lower Target Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_HW_SHIFT (0U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_HW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_HW_MASK)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_RW_SHIFT (16U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_RW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_OUTBOUND_2 - iATU Region Control 1 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TYPE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TYPE_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TC_SHIFT (5U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TC_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TD_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_ATTR_SHIFT (9U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_ATTR_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_INCREASE_REGION_SIZE_SHIFT (13U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_CTRL_1_FUNC_NUM_SHIFT (20U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_OUTBOUND_2 - iATU Region Control 2 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_MSG_CODE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_MSG_CODE_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_MASK (0xFF00U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_SUBSTITUTE_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_SUBSTITUTE_EN_SHIFT (16U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_FUNC_BYPASS_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_FUNC_BYPASS_SHIFT (19U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_SNP_MASK (0x100000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_SNP_SHIFT (20U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INHIBIT_PAYLOAD_MASK (0x400000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INHIBIT_PAYLOAD_SHIFT (22U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_HEADER_SUBSTITUTE_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_HEADER_SUBSTITUTE_EN_SHIFT (23U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_DMA_BYPASS_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_DMA_BYPASS_SHIFT (27U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_CFG_SHIFT_MODE_SHIFT (28U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INVERT_MODE_SHIFT (29U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_REGION_EN_SHIFT (31U)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2 - iATU Lower Base Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_HW_SHIFT (0U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_HW_MASK)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_RW_SHIFT (16U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2 - iATU Upper Base Address Register. */
/*! @{ */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2_UPPER_BASE_RW_SHIFT (0U)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_OUTBOUND_2 - iATU Limit Address Register. */
/*! @{ */
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_HW_SHIFT (0U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_HW_MASK)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_RW_SHIFT (16U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2 - iATU Lower Target Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2_LWR_TARGET_RW_OUTBOUND_MASK (0xFFFFFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2_LWR_TARGET_RW_OUTBOUND_SHIFT (0U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2_LWR_TARGET_RW_OUTBOUND(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2_LWR_TARGET_RW_OUTBOUND_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2_LWR_TARGET_RW_OUTBOUND_MASK)
/*! @} */

/*! @name IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2 - iATU Upper Target Address Register. */
/*! @{ */
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2_UPPER_TARGET_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2_UPPER_TARGET_RW_SHIFT (0U)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2_UPPER_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2_UPPER_TARGET_RW_SHIFT)) & PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2_UPPER_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_INBOUND_2 - iATU Region Control 1 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TYPE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TYPE_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TC_SHIFT (5U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TC_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TD_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_ATTR_SHIFT (9U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_ATTR_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_INCREASE_REGION_SIZE_SHIFT (13U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_CTRL_1_FUNC_NUM_SHIFT (20U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_INBOUND_2 - iATU Region Control 2 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_BAR_NUM_MASK (0x700U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_BAR_NUM_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_BAR_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_BAR_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_BAR_NUM_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_TYPE_MATCH_MODE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_TYPE_MATCH_MODE_SHIFT (13U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TC_MATCH_EN_MASK (0x4000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TC_MATCH_EN_SHIFT (14U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TD_MATCH_EN_MASK (0x8000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TD_MATCH_EN_SHIFT (15U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_ATTR_MATCH_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_ATTR_MATCH_EN_SHIFT (16U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUNC_NUM_MATCH_EN_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUNC_NUM_MATCH_EN_SHIFT (19U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_MATCH_EN_MASK (0x200000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_MATCH_EN_SHIFT (21U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_SINGLE_ADDR_LOC_TRANS_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_SINGLE_ADDR_LOC_TRANS_EN_SHIFT (23U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_RESPONSE_CODE_MASK (0x3000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_RESPONSE_CODE_SHIFT (24U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_RESPONSE_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_RESPONSE_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_RESPONSE_CODE_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUZZY_TYPE_MATCH_CODE_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUZZY_TYPE_MATCH_CODE_SHIFT (27U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_CFG_SHIFT_MODE_SHIFT (28U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_INVERT_MODE_SHIFT (29U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MATCH_MODE_MASK (0x40000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MATCH_MODE_SHIFT (30U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_REGION_EN_SHIFT (31U)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_INBOUND_2 - iATU Lower Base Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_HW_SHIFT (0U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_HW_MASK)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_RW_SHIFT (16U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_INBOUND_2 - iATU Upper Base Address Register. */
/*! @{ */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_2_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_2_UPPER_BASE_RW_SHIFT (0U)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_2_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_2_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_2_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_INBOUND_2 - iATU Limit Address Register. */
/*! @{ */
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_HW_SHIFT (0U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_HW_MASK)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_RW_SHIFT (16U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_INBOUND_2 - iATU Lower Target Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_HW_SHIFT (0U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_HW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_HW_MASK)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_RW_SHIFT (16U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_RW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_OUTBOUND_3 - iATU Region Control 1 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TYPE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TYPE_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TC_SHIFT (5U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TC_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TD_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_ATTR_SHIFT (9U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_ATTR_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_INCREASE_REGION_SIZE_SHIFT (13U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_CTRL_1_FUNC_NUM_SHIFT (20U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_OUTBOUND_3 - iATU Region Control 2 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_MSG_CODE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_MSG_CODE_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_MASK (0xFF00U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_SUBSTITUTE_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_SUBSTITUTE_EN_SHIFT (16U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_FUNC_BYPASS_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_FUNC_BYPASS_SHIFT (19U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_SNP_MASK (0x100000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_SNP_SHIFT (20U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INHIBIT_PAYLOAD_MASK (0x400000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INHIBIT_PAYLOAD_SHIFT (22U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_HEADER_SUBSTITUTE_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_HEADER_SUBSTITUTE_EN_SHIFT (23U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_DMA_BYPASS_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_DMA_BYPASS_SHIFT (27U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_CFG_SHIFT_MODE_SHIFT (28U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INVERT_MODE_SHIFT (29U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_REGION_EN_SHIFT (31U)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3 - iATU Lower Base Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_HW_SHIFT (0U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_HW_MASK)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_RW_SHIFT (16U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3 - iATU Upper Base Address Register. */
/*! @{ */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3_UPPER_BASE_RW_SHIFT (0U)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_OUTBOUND_3 - iATU Limit Address Register. */
/*! @{ */
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_HW_SHIFT (0U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_HW_MASK)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_RW_SHIFT (16U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3 - iATU Lower Target Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3_LWR_TARGET_RW_OUTBOUND_MASK (0xFFFFFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3_LWR_TARGET_RW_OUTBOUND_SHIFT (0U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3_LWR_TARGET_RW_OUTBOUND(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3_LWR_TARGET_RW_OUTBOUND_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3_LWR_TARGET_RW_OUTBOUND_MASK)
/*! @} */

/*! @name IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3 - iATU Upper Target Address Register. */
/*! @{ */
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3_UPPER_TARGET_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3_UPPER_TARGET_RW_SHIFT (0U)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3_UPPER_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3_UPPER_TARGET_RW_SHIFT)) & PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3_UPPER_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_INBOUND_3 - iATU Region Control 1 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TYPE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TYPE_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TC_SHIFT (5U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TC_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TD_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_ATTR_SHIFT (9U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_ATTR_MASK)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_INCREASE_REGION_SIZE_SHIFT (13U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_CTRL_1_FUNC_NUM_SHIFT (20U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_INBOUND_3 - iATU Region Control 2 Register. */
/*! @{ */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_SHIFT (0U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_BAR_NUM_MASK (0x700U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_BAR_NUM_SHIFT (8U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_BAR_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_BAR_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_BAR_NUM_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_TYPE_MATCH_MODE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_TYPE_MATCH_MODE_SHIFT (13U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TC_MATCH_EN_MASK (0x4000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TC_MATCH_EN_SHIFT (14U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TD_MATCH_EN_MASK (0x8000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TD_MATCH_EN_SHIFT (15U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_ATTR_MATCH_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_ATTR_MATCH_EN_SHIFT (16U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUNC_NUM_MATCH_EN_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUNC_NUM_MATCH_EN_SHIFT (19U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_MATCH_EN_MASK (0x200000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_MATCH_EN_SHIFT (21U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_SINGLE_ADDR_LOC_TRANS_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_SINGLE_ADDR_LOC_TRANS_EN_SHIFT (23U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_RESPONSE_CODE_MASK (0x3000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_RESPONSE_CODE_SHIFT (24U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_RESPONSE_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_RESPONSE_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_RESPONSE_CODE_MASK)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUZZY_TYPE_MATCH_CODE_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUZZY_TYPE_MATCH_CODE_SHIFT (27U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_CFG_SHIFT_MODE_SHIFT (28U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_INVERT_MODE_SHIFT (29U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MATCH_MODE_MASK (0x40000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MATCH_MODE_SHIFT (30U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_REGION_EN_SHIFT (31U)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_INBOUND_3 - iATU Lower Base Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_HW_SHIFT (0U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_HW_MASK)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_RW_SHIFT (16U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_INBOUND_3 - iATU Upper Base Address Register. */
/*! @{ */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_3_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_3_UPPER_BASE_RW_SHIFT (0U)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_3_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_3_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_3_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_INBOUND_3 - iATU Limit Address Register. */
/*! @{ */
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_HW_SHIFT (0U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_HW_MASK)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_RW_SHIFT (16U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_INBOUND_3 - iATU Lower Target Address Register. */
/*! @{ */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_HW_SHIFT (0U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_HW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_HW_MASK)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_RW_SHIFT (16U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_RW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_RW_MASK)
/*! @} */

/*! @name DMA_CTRL_DATA_ARB_PRIOR_OFF - DMA Arbitration Scheme for TRGT1 Interface. */
/*! @{ */
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RTRGT1_WEIGHT_MASK (0x7U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RTRGT1_WEIGHT_SHIFT (0U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RTRGT1_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RTRGT1_WEIGHT_SHIFT)) & PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RTRGT1_WEIGHT_MASK)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_WR_CTRL_TRGT_WEIGHT_MASK (0x38U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_WR_CTRL_TRGT_WEIGHT_SHIFT (3U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_WR_CTRL_TRGT_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_WR_CTRL_TRGT_WEIGHT_SHIFT)) & PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_WR_CTRL_TRGT_WEIGHT_MASK)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RD_CTRL_TRGT_WEIGHT_MASK (0x1C0U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RD_CTRL_TRGT_WEIGHT_SHIFT (6U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RD_CTRL_TRGT_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RD_CTRL_TRGT_WEIGHT_SHIFT)) & PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RD_CTRL_TRGT_WEIGHT_MASK)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RDBUFF_TRGT_WEIGHT_MASK (0xE00U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RDBUFF_TRGT_WEIGHT_SHIFT (9U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RDBUFF_TRGT_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RDBUFF_TRGT_WEIGHT_SHIFT)) & PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RDBUFF_TRGT_WEIGHT_MASK)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RSVDP_12_MASK (0xFFFFF000U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RSVDP_12_SHIFT (12U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RSVDP_12(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RSVDP_12_SHIFT)) & PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RSVDP_12_MASK)
/*! @} */

/*! @name DMA_CTRL_OFF - DMA Number of Channels Register. */
/*! @{ */
#define PCIE_DMA_CTRL_OFF_NUM_DMA_WR_CHAN_MASK   (0xFU)
#define PCIE_DMA_CTRL_OFF_NUM_DMA_WR_CHAN_SHIFT  (0U)
#define PCIE_DMA_CTRL_OFF_NUM_DMA_WR_CHAN(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_OFF_NUM_DMA_WR_CHAN_SHIFT)) & PCIE_DMA_CTRL_OFF_NUM_DMA_WR_CHAN_MASK)
#define PCIE_DMA_CTRL_OFF_RSVDP_4_MASK           (0xFFF0U)
#define PCIE_DMA_CTRL_OFF_RSVDP_4_SHIFT          (4U)
#define PCIE_DMA_CTRL_OFF_RSVDP_4(x)             (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_OFF_RSVDP_4_SHIFT)) & PCIE_DMA_CTRL_OFF_RSVDP_4_MASK)
#define PCIE_DMA_CTRL_OFF_NUM_DMA_RD_CHAN_MASK   (0xF0000U)
#define PCIE_DMA_CTRL_OFF_NUM_DMA_RD_CHAN_SHIFT  (16U)
#define PCIE_DMA_CTRL_OFF_NUM_DMA_RD_CHAN(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_OFF_NUM_DMA_RD_CHAN_SHIFT)) & PCIE_DMA_CTRL_OFF_NUM_DMA_RD_CHAN_MASK)
#define PCIE_DMA_CTRL_OFF_RSVDP_20_MASK          (0xF00000U)
#define PCIE_DMA_CTRL_OFF_RSVDP_20_SHIFT         (20U)
#define PCIE_DMA_CTRL_OFF_RSVDP_20(x)            (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_OFF_RSVDP_20_SHIFT)) & PCIE_DMA_CTRL_OFF_RSVDP_20_MASK)
#define PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_WR_MASK  (0x1000000U)
#define PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_WR_SHIFT (24U)
#define PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_RD_MASK  (0x2000000U)
#define PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_RD_SHIFT (25U)
#define PCIE_DMA_CTRL_OFF_RSVDP_26_MASK          (0xFC000000U)
#define PCIE_DMA_CTRL_OFF_RSVDP_26_SHIFT         (26U)
#define PCIE_DMA_CTRL_OFF_RSVDP_26(x)            (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_OFF_RSVDP_26_SHIFT)) & PCIE_DMA_CTRL_OFF_RSVDP_26_MASK)
/*! @} */

/*! @name DMA_WRITE_ENGINE_EN_OFF - DMA Write Engine Enable Register. */
/*! @{ */
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_DMA_WRITE_ENGINE_MASK (0x1U)
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_DMA_WRITE_ENGINE_SHIFT (0U)
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_1_MASK (0xFFFEU)
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_1_SHIFT (1U)
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_1(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_1_SHIFT)) & PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_1_MASK)
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_24_SHIFT (24U)
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_WRITE_DOORBELL_OFF - DMA Write Doorbell Register. */
/*! @{ */
#define PCIE_DMA_WRITE_DOORBELL_OFF_WR_DOORBELL_NUM_MASK (0x7U)
#define PCIE_DMA_WRITE_DOORBELL_OFF_WR_DOORBELL_NUM_SHIFT (0U)
#define PCIE_DMA_WRITE_DOORBELL_OFF_WR_DOORBELL_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_DOORBELL_OFF_WR_DOORBELL_NUM_SHIFT)) & PCIE_DMA_WRITE_DOORBELL_OFF_WR_DOORBELL_NUM_MASK)
#define PCIE_DMA_WRITE_DOORBELL_OFF_RSVDP_3_MASK (0x7FFFFFF8U)
#define PCIE_DMA_WRITE_DOORBELL_OFF_RSVDP_3_SHIFT (3U)
#define PCIE_DMA_WRITE_DOORBELL_OFF_RSVDP_3(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_DOORBELL_OFF_RSVDP_3_SHIFT)) & PCIE_DMA_WRITE_DOORBELL_OFF_RSVDP_3_MASK)
#define PCIE_DMA_WRITE_DOORBELL_OFF_WR_STOP_MASK (0x80000000U)
#define PCIE_DMA_WRITE_DOORBELL_OFF_WR_STOP_SHIFT (31U)
/*! @} */

/*! @name DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF - DMA Write Engine Channel Arbitration Weight Low Register. */
/*! @{ */
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL0_WEIGHT_MASK (0x1FU)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL0_WEIGHT_SHIFT (0U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL0_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL0_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL0_WEIGHT_MASK)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL1_WEIGHT_MASK (0x3E0U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL1_WEIGHT_SHIFT (5U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL1_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL1_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL1_WEIGHT_MASK)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL2_WEIGHT_MASK (0x7C00U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL2_WEIGHT_SHIFT (10U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL2_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL2_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL2_WEIGHT_MASK)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL3_WEIGHT_MASK (0xF8000U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL3_WEIGHT_SHIFT (15U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL3_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL3_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL3_WEIGHT_MASK)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_SHIFT (20U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF - DMA Write Engine Channel Arbitration Weight High Register. */
/*! @{ */
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL4_WEIGHT_MASK (0x1FU)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL4_WEIGHT_SHIFT (0U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL4_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL4_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL4_WEIGHT_MASK)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL5_WEIGHT_MASK (0x3E0U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL5_WEIGHT_SHIFT (5U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL5_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL5_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL5_WEIGHT_MASK)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL6_WEIGHT_MASK (0x7C00U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL6_WEIGHT_SHIFT (10U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL6_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL6_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL6_WEIGHT_MASK)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL7_WEIGHT_MASK (0xF8000U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL7_WEIGHT_SHIFT (15U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL7_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL7_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL7_WEIGHT_MASK)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_SHIFT (20U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name DMA_READ_ENGINE_EN_OFF - DMA Read Engine Enable Register. */
/*! @{ */
#define PCIE_DMA_READ_ENGINE_EN_OFF_DMA_READ_ENGINE_MASK (0x1U)
#define PCIE_DMA_READ_ENGINE_EN_OFF_DMA_READ_ENGINE_SHIFT (0U)
#define PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_1_MASK (0xFFFEU)
#define PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_1_SHIFT (1U)
#define PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_1(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_1_SHIFT)) & PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_1_MASK)
#define PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_24_SHIFT (24U)
#define PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_24(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_DOORBELL_OFF - DMA Read Doorbell Register. */
/*! @{ */
#define PCIE_DMA_READ_DOORBELL_OFF_RD_DOORBELL_NUM_MASK (0x7U)
#define PCIE_DMA_READ_DOORBELL_OFF_RD_DOORBELL_NUM_SHIFT (0U)
#define PCIE_DMA_READ_DOORBELL_OFF_RD_DOORBELL_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_DOORBELL_OFF_RD_DOORBELL_NUM_SHIFT)) & PCIE_DMA_READ_DOORBELL_OFF_RD_DOORBELL_NUM_MASK)
#define PCIE_DMA_READ_DOORBELL_OFF_RSVDP_3_MASK  (0x7FFFFFF8U)
#define PCIE_DMA_READ_DOORBELL_OFF_RSVDP_3_SHIFT (3U)
#define PCIE_DMA_READ_DOORBELL_OFF_RSVDP_3(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_DOORBELL_OFF_RSVDP_3_SHIFT)) & PCIE_DMA_READ_DOORBELL_OFF_RSVDP_3_MASK)
#define PCIE_DMA_READ_DOORBELL_OFF_RD_STOP_MASK  (0x80000000U)
#define PCIE_DMA_READ_DOORBELL_OFF_RD_STOP_SHIFT (31U)
/*! @} */

/*! @name DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF - DMA Read Engine Channel Arbitration Weight Low Register. */
/*! @{ */
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL0_WEIGHT_MASK (0x1FU)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL0_WEIGHT_SHIFT (0U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL0_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL0_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL0_WEIGHT_MASK)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL1_WEIGHT_MASK (0x3E0U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL1_WEIGHT_SHIFT (5U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL1_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL1_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL1_WEIGHT_MASK)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL2_WEIGHT_MASK (0x7C00U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL2_WEIGHT_SHIFT (10U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL2_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL2_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL2_WEIGHT_MASK)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL3_WEIGHT_MASK (0xF8000U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL3_WEIGHT_SHIFT (15U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL3_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL3_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL3_WEIGHT_MASK)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_SHIFT (20U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF - DMA Read Engine Channel Arbitration Weight High Register. */
/*! @{ */
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL4_WEIGHT_MASK (0x1FU)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL4_WEIGHT_SHIFT (0U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL4_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL4_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL4_WEIGHT_MASK)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL5_WEIGHT_MASK (0x3E0U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL5_WEIGHT_SHIFT (5U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL5_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL5_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL5_WEIGHT_MASK)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL6_WEIGHT_MASK (0x7C00U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL6_WEIGHT_SHIFT (10U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL6_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL6_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL6_WEIGHT_MASK)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL7_WEIGHT_MASK (0xF8000U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL7_WEIGHT_SHIFT (15U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL7_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL7_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL7_WEIGHT_MASK)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_SHIFT (20U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name DMA_WRITE_INT_STATUS_OFF - DMA Write Interrupt Status Register. */
/*! @{ */
#define PCIE_DMA_WRITE_INT_STATUS_OFF_WR_DONE_INT_STATUS_MASK (0xFFU)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_WR_DONE_INT_STATUS_SHIFT (0U)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_WR_DONE_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_STATUS_OFF_WR_DONE_INT_STATUS_SHIFT)) & PCIE_DMA_WRITE_INT_STATUS_OFF_WR_DONE_INT_STATUS_MASK)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_8_SHIFT (8U)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_8(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_8_MASK)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_WR_ABORT_INT_STATUS_MASK (0xFF0000U)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_WR_ABORT_INT_STATUS_SHIFT (16U)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_WR_ABORT_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_STATUS_OFF_WR_ABORT_INT_STATUS_SHIFT)) & PCIE_DMA_WRITE_INT_STATUS_OFF_WR_ABORT_INT_STATUS_MASK)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_24_SHIFT (24U)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_WRITE_INT_MASK_OFF - DMA Write Interrupt Mask Register. */
/*! @{ */
#define PCIE_DMA_WRITE_INT_MASK_OFF_WR_DONE_INT_MASK_MASK (0x1U)
#define PCIE_DMA_WRITE_INT_MASK_OFF_WR_DONE_INT_MASK_SHIFT (0U)
#define PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_8_SHIFT (8U)
#define PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_8(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_8_MASK)
#define PCIE_DMA_WRITE_INT_MASK_OFF_WR_ABORT_INT_MASK_MASK (0x10000U)
#define PCIE_DMA_WRITE_INT_MASK_OFF_WR_ABORT_INT_MASK_SHIFT (16U)
#define PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_24_SHIFT (24U)
#define PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_24(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_WRITE_INT_CLEAR_OFF - DMA Write Interrupt Clear Register. */
/*! @{ */
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_DONE_INT_CLEAR_MASK (0x1U)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_DONE_INT_CLEAR_SHIFT (0U)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_8_SHIFT (8U)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_8(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_8_MASK)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_ABORT_INT_CLEAR_MASK (0x10000U)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_ABORT_INT_CLEAR_SHIFT (16U)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_24_SHIFT (24U)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_WRITE_ERR_STATUS_OFF - DMA Write Error Status Register */
/*! @{ */
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_APP_READ_ERR_DETECT_MASK (0xFFU)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_APP_READ_ERR_DETECT_SHIFT (0U)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_APP_READ_ERR_DETECT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ERR_STATUS_OFF_APP_READ_ERR_DETECT_SHIFT)) & PCIE_DMA_WRITE_ERR_STATUS_OFF_APP_READ_ERR_DETECT_MASK)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_8_SHIFT (8U)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_8(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_8_MASK)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_LINKLIST_ELEMENT_FETCH_ERR_DETECT_MASK (0xFF0000U)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_LINKLIST_ELEMENT_FETCH_ERR_DETECT_SHIFT (16U)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_LINKLIST_ELEMENT_FETCH_ERR_DETECT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ERR_STATUS_OFF_LINKLIST_ELEMENT_FETCH_ERR_DETECT_SHIFT)) & PCIE_DMA_WRITE_ERR_STATUS_OFF_LINKLIST_ELEMENT_FETCH_ERR_DETECT_MASK)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_24_SHIFT (24U)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_WRITE_DONE_IMWR_LOW_OFF - DMA Write Done IMWr Address Low Register. */
/*! @{ */
#define PCIE_DMA_WRITE_DONE_IMWR_LOW_OFF_DMA_WRITE_DONE_LOW_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_WRITE_DONE_IMWR_LOW_OFF_DMA_WRITE_DONE_LOW_REG_SHIFT (0U)
#define PCIE_DMA_WRITE_DONE_IMWR_LOW_OFF_DMA_WRITE_DONE_LOW_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_DONE_IMWR_LOW_OFF_DMA_WRITE_DONE_LOW_REG_SHIFT)) & PCIE_DMA_WRITE_DONE_IMWR_LOW_OFF_DMA_WRITE_DONE_LOW_REG_MASK)
/*! @} */

/*! @name DMA_WRITE_DONE_IMWR_HIGH_OFF - DMA Write Done IMWr Interrupt Address High Register. */
/*! @{ */
#define PCIE_DMA_WRITE_DONE_IMWR_HIGH_OFF_DMA_WRITE_DONE_HIGH_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_WRITE_DONE_IMWR_HIGH_OFF_DMA_WRITE_DONE_HIGH_REG_SHIFT (0U)
#define PCIE_DMA_WRITE_DONE_IMWR_HIGH_OFF_DMA_WRITE_DONE_HIGH_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_DONE_IMWR_HIGH_OFF_DMA_WRITE_DONE_HIGH_REG_SHIFT)) & PCIE_DMA_WRITE_DONE_IMWR_HIGH_OFF_DMA_WRITE_DONE_HIGH_REG_MASK)
/*! @} */

/*! @name DMA_WRITE_ABORT_IMWR_LOW_OFF - DMA Write Abort IMWr Address Low Register. */
/*! @{ */
#define PCIE_DMA_WRITE_ABORT_IMWR_LOW_OFF_DMA_WRITE_ABORT_LOW_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_WRITE_ABORT_IMWR_LOW_OFF_DMA_WRITE_ABORT_LOW_REG_SHIFT (0U)
#define PCIE_DMA_WRITE_ABORT_IMWR_LOW_OFF_DMA_WRITE_ABORT_LOW_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ABORT_IMWR_LOW_OFF_DMA_WRITE_ABORT_LOW_REG_SHIFT)) & PCIE_DMA_WRITE_ABORT_IMWR_LOW_OFF_DMA_WRITE_ABORT_LOW_REG_MASK)
/*! @} */

/*! @name DMA_WRITE_ABORT_IMWR_HIGH_OFF - DMA Write Abort IMWr Address High Register. */
/*! @{ */
#define PCIE_DMA_WRITE_ABORT_IMWR_HIGH_OFF_DMA_WRITE_ABORT_HIGH_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_WRITE_ABORT_IMWR_HIGH_OFF_DMA_WRITE_ABORT_HIGH_REG_SHIFT (0U)
#define PCIE_DMA_WRITE_ABORT_IMWR_HIGH_OFF_DMA_WRITE_ABORT_HIGH_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ABORT_IMWR_HIGH_OFF_DMA_WRITE_ABORT_HIGH_REG_SHIFT)) & PCIE_DMA_WRITE_ABORT_IMWR_HIGH_OFF_DMA_WRITE_ABORT_HIGH_REG_MASK)
/*! @} */

/*! @name DMA_WRITE_CH01_IMWR_DATA_OFF - DMA Write Channel 1 and 0 IMWr Data Register. */
/*! @{ */
#define PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_0_DATA_MASK (0xFFFFU)
#define PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_0_DATA_SHIFT (0U)
#define PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_0_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_0_DATA_SHIFT)) & PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_0_DATA_MASK)
#define PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_1_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_1_DATA_SHIFT (16U)
#define PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_1_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_1_DATA_SHIFT)) & PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_1_DATA_MASK)
/*! @} */

/*! @name DMA_WRITE_CH23_IMWR_DATA_OFF - DMA Write Channel 3 and 2 IMWr Data Register. */
/*! @{ */
#define PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_2_DATA_MASK (0xFFFFU)
#define PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_2_DATA_SHIFT (0U)
#define PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_2_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_2_DATA_SHIFT)) & PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_2_DATA_MASK)
#define PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_3_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_3_DATA_SHIFT (16U)
#define PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_3_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_3_DATA_SHIFT)) & PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_3_DATA_MASK)
/*! @} */

/*! @name DMA_WRITE_CH45_IMWR_DATA_OFF - DMA Write Channel 5 and 4 IMWr Data Register. */
/*! @{ */
#define PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_4_DATA_MASK (0xFFFFU)
#define PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_4_DATA_SHIFT (0U)
#define PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_4_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_4_DATA_SHIFT)) & PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_4_DATA_MASK)
#define PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_5_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_5_DATA_SHIFT (16U)
#define PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_5_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_5_DATA_SHIFT)) & PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_5_DATA_MASK)
/*! @} */

/*! @name DMA_WRITE_CH67_IMWR_DATA_OFF - DMA Write Channel 7 and 6 IMWr Data Register. */
/*! @{ */
#define PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_6_DATA_MASK (0xFFFFU)
#define PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_6_DATA_SHIFT (0U)
#define PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_6_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_6_DATA_SHIFT)) & PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_6_DATA_MASK)
#define PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_7_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_7_DATA_SHIFT (16U)
#define PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_7_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_7_DATA_SHIFT)) & PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_7_DATA_MASK)
/*! @} */

/*! @name DMA_WRITE_LINKED_LIST_ERR_EN_OFF - DMA Write Linked List Error Enable Register. */
/*! @{ */
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLRAIE_MASK (0x1U)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLRAIE_SHIFT (0U)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_8_SHIFT (8U)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_8(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_8_MASK)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLLAIE_MASK (0x10000U)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLLAIE_SHIFT (16U)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_24_SHIFT (24U)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_INT_STATUS_OFF - DMA Read Interrupt Status Register. */
/*! @{ */
#define PCIE_DMA_READ_INT_STATUS_OFF_RD_DONE_INT_STATUS_MASK (0xFFU)
#define PCIE_DMA_READ_INT_STATUS_OFF_RD_DONE_INT_STATUS_SHIFT (0U)
#define PCIE_DMA_READ_INT_STATUS_OFF_RD_DONE_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_STATUS_OFF_RD_DONE_INT_STATUS_SHIFT)) & PCIE_DMA_READ_INT_STATUS_OFF_RD_DONE_INT_STATUS_MASK)
#define PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_8_SHIFT (8U)
#define PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_8(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_8_MASK)
#define PCIE_DMA_READ_INT_STATUS_OFF_RD_ABORT_INT_STATUS_MASK (0xFF0000U)
#define PCIE_DMA_READ_INT_STATUS_OFF_RD_ABORT_INT_STATUS_SHIFT (16U)
#define PCIE_DMA_READ_INT_STATUS_OFF_RD_ABORT_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_STATUS_OFF_RD_ABORT_INT_STATUS_SHIFT)) & PCIE_DMA_READ_INT_STATUS_OFF_RD_ABORT_INT_STATUS_MASK)
#define PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_24_SHIFT (24U)
#define PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_INT_MASK_OFF - DMA Read Interrupt Mask Register. */
/*! @{ */
#define PCIE_DMA_READ_INT_MASK_OFF_RD_DONE_INT_MASK_MASK (0x1U)
#define PCIE_DMA_READ_INT_MASK_OFF_RD_DONE_INT_MASK_SHIFT (0U)
#define PCIE_DMA_READ_INT_MASK_OFF_RSVDP_8_MASK  (0xFF00U)
#define PCIE_DMA_READ_INT_MASK_OFF_RSVDP_8_SHIFT (8U)
#define PCIE_DMA_READ_INT_MASK_OFF_RSVDP_8(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_MASK_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_READ_INT_MASK_OFF_RSVDP_8_MASK)
#define PCIE_DMA_READ_INT_MASK_OFF_RD_ABORT_INT_MASK_MASK (0x10000U)
#define PCIE_DMA_READ_INT_MASK_OFF_RD_ABORT_INT_MASK_SHIFT (16U)
#define PCIE_DMA_READ_INT_MASK_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_READ_INT_MASK_OFF_RSVDP_24_SHIFT (24U)
#define PCIE_DMA_READ_INT_MASK_OFF_RSVDP_24(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_MASK_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_READ_INT_MASK_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_INT_CLEAR_OFF - DMA Read Interrupt Clear Register. */
/*! @{ */
#define PCIE_DMA_READ_INT_CLEAR_OFF_RD_DONE_INT_CLEAR_MASK (0xFFU)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RD_DONE_INT_CLEAR_SHIFT (0U)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RD_DONE_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_CLEAR_OFF_RD_DONE_INT_CLEAR_SHIFT)) & PCIE_DMA_READ_INT_CLEAR_OFF_RD_DONE_INT_CLEAR_MASK)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_8_SHIFT (8U)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_8(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_8_MASK)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RD_ABORT_INT_CLEAR_MASK (0xFF0000U)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RD_ABORT_INT_CLEAR_SHIFT (16U)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RD_ABORT_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_CLEAR_OFF_RD_ABORT_INT_CLEAR_SHIFT)) & PCIE_DMA_READ_INT_CLEAR_OFF_RD_ABORT_INT_CLEAR_MASK)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_24_SHIFT (24U)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_24(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_ERR_STATUS_LOW_OFF - DMA Read Error Status Low Register. */
/*! @{ */
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_APP_WR_ERR_DETECT_MASK (0xFFU)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_APP_WR_ERR_DETECT_SHIFT (0U)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_APP_WR_ERR_DETECT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_LOW_OFF_APP_WR_ERR_DETECT_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_LOW_OFF_APP_WR_ERR_DETECT_MASK)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_8_SHIFT (8U)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_8(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_8_MASK)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_LINK_LIST_ELEMENT_FETCH_ERR_DETECT_MASK (0xFF0000U)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_LINK_LIST_ELEMENT_FETCH_ERR_DETECT_SHIFT (16U)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_LINK_LIST_ELEMENT_FETCH_ERR_DETECT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_LOW_OFF_LINK_LIST_ELEMENT_FETCH_ERR_DETECT_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_LOW_OFF_LINK_LIST_ELEMENT_FETCH_ERR_DETECT_MASK)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_24_SHIFT (24U)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_ERR_STATUS_HIGH_OFF - DMA Read Error Status High Register. */
/*! @{ */
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_UNSUPPORTED_REQ_MASK (0xFFU)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_UNSUPPORTED_REQ_SHIFT (0U)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_UNSUPPORTED_REQ(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_UNSUPPORTED_REQ_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_UNSUPPORTED_REQ_MASK)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_ABORT_MASK (0xFF00U)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_ABORT_SHIFT (8U)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_ABORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_ABORT_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_ABORT_MASK)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_TIMEOUT_MASK (0xFF0000U)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_TIMEOUT_SHIFT (16U)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_TIMEOUT_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_TIMEOUT_MASK)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_DATA_POISIONING_MASK (0xFF000000U)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_DATA_POISIONING_SHIFT (24U)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_DATA_POISIONING(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_DATA_POISIONING_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_DATA_POISIONING_MASK)
/*! @} */

/*! @name DMA_READ_LINKED_LIST_ERR_EN_OFF - DMA Read Linked List Error Enable Register. */
/*! @{ */
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLRAIE_MASK (0x1U)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLRAIE_SHIFT (0U)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_8_SHIFT (8U)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_8(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_8_MASK)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLLAIE_MASK (0x10000U)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLLAIE_SHIFT (16U)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_24_SHIFT (24U)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_DONE_IMWR_LOW_OFF - DMA Read Done IMWr Address Low Register. */
/*! @{ */
#define PCIE_DMA_READ_DONE_IMWR_LOW_OFF_DMA_READ_DONE_LOW_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_READ_DONE_IMWR_LOW_OFF_DMA_READ_DONE_LOW_REG_SHIFT (0U)
#define PCIE_DMA_READ_DONE_IMWR_LOW_OFF_DMA_READ_DONE_LOW_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_DONE_IMWR_LOW_OFF_DMA_READ_DONE_LOW_REG_SHIFT)) & PCIE_DMA_READ_DONE_IMWR_LOW_OFF_DMA_READ_DONE_LOW_REG_MASK)
/*! @} */

/*! @name DMA_READ_DONE_IMWR_HIGH_OFF - DMA Read Done IMWr Address High Register. */
/*! @{ */
#define PCIE_DMA_READ_DONE_IMWR_HIGH_OFF_DMA_READ_DONE_HIGH_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_READ_DONE_IMWR_HIGH_OFF_DMA_READ_DONE_HIGH_REG_SHIFT (0U)
#define PCIE_DMA_READ_DONE_IMWR_HIGH_OFF_DMA_READ_DONE_HIGH_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_DONE_IMWR_HIGH_OFF_DMA_READ_DONE_HIGH_REG_SHIFT)) & PCIE_DMA_READ_DONE_IMWR_HIGH_OFF_DMA_READ_DONE_HIGH_REG_MASK)
/*! @} */

/*! @name DMA_READ_ABORT_IMWR_LOW_OFF - DMA Read Abort IMWr Address Low Register. */
/*! @{ */
#define PCIE_DMA_READ_ABORT_IMWR_LOW_OFF_DMA_READ_ABORT_LOW_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_READ_ABORT_IMWR_LOW_OFF_DMA_READ_ABORT_LOW_REG_SHIFT (0U)
#define PCIE_DMA_READ_ABORT_IMWR_LOW_OFF_DMA_READ_ABORT_LOW_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ABORT_IMWR_LOW_OFF_DMA_READ_ABORT_LOW_REG_SHIFT)) & PCIE_DMA_READ_ABORT_IMWR_LOW_OFF_DMA_READ_ABORT_LOW_REG_MASK)
/*! @} */

/*! @name DMA_READ_ABORT_IMWR_HIGH_OFF - DMA Read Abort IMWr Address High Register. */
/*! @{ */
#define PCIE_DMA_READ_ABORT_IMWR_HIGH_OFF_DMA_READ_ABORT_HIGH_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_READ_ABORT_IMWR_HIGH_OFF_DMA_READ_ABORT_HIGH_REG_SHIFT (0U)
#define PCIE_DMA_READ_ABORT_IMWR_HIGH_OFF_DMA_READ_ABORT_HIGH_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ABORT_IMWR_HIGH_OFF_DMA_READ_ABORT_HIGH_REG_SHIFT)) & PCIE_DMA_READ_ABORT_IMWR_HIGH_OFF_DMA_READ_ABORT_HIGH_REG_MASK)
/*! @} */

/*! @name DMA_READ_CH01_IMWR_DATA_OFF - DMA Read Channel 1 and 0 IMWr Data Register. */
/*! @{ */
#define PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_0_DATA_MASK (0xFFFFU)
#define PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_0_DATA_SHIFT (0U)
#define PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_0_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_0_DATA_SHIFT)) & PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_0_DATA_MASK)
#define PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_1_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_1_DATA_SHIFT (16U)
#define PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_1_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_1_DATA_SHIFT)) & PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_1_DATA_MASK)
/*! @} */

/*! @name DMA_READ_CH23_IMWR_DATA_OFF - DMA Read Channel 3 and 2 IMWr Data Register. */
/*! @{ */
#define PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_2_DATA_MASK (0xFFFFU)
#define PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_2_DATA_SHIFT (0U)
#define PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_2_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_2_DATA_SHIFT)) & PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_2_DATA_MASK)
#define PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_3_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_3_DATA_SHIFT (16U)
#define PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_3_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_3_DATA_SHIFT)) & PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_3_DATA_MASK)
/*! @} */

/*! @name DMA_READ_CH45_IMWR_DATA_OFF - DMA Read Channel 5 and 4 IMWr Data Register. */
/*! @{ */
#define PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_4_DATA_MASK (0xFFFFU)
#define PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_4_DATA_SHIFT (0U)
#define PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_4_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_4_DATA_SHIFT)) & PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_4_DATA_MASK)
#define PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_5_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_5_DATA_SHIFT (16U)
#define PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_5_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_5_DATA_SHIFT)) & PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_5_DATA_MASK)
/*! @} */

/*! @name DMA_READ_CH67_IMWR_DATA_OFF - DMA Read Channel 7 and 6 IMWr Data Register. */
/*! @{ */
#define PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_6_DATA_MASK (0xFFFFU)
#define PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_6_DATA_SHIFT (0U)
#define PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_6_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_6_DATA_SHIFT)) & PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_6_DATA_MASK)
#define PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_7_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_7_DATA_SHIFT (16U)
#define PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_7_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_7_DATA_SHIFT)) & PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_7_DATA_MASK)
/*! @} */

/*! @name DMA_CH_CONTROL1_OFF_WRCH_0 - DMA Write Channel Control 1 Register. */
/*! @{ */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CB_MASK  (0x1U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CB_SHIFT (0U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_TCB_MASK (0x2U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_TCB_SHIFT (1U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLP_MASK (0x4U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLP_SHIFT (2U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LIE_MASK (0x8U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LIE_SHIFT (3U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_RIE_MASK (0x10U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_RIE_SHIFT (4U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CS_MASK  (0x60U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CS_SHIFT (5U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CS(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CS_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CS_MASK)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED0_MASK (0x80U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED0_SHIFT (7U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CCS_MASK (0x100U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CCS_SHIFT (8U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLE_MASK (0x200U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLE_SHIFT (9U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED1_MASK (0xC00U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED1_SHIFT (10U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED1_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED1_MASK)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_FUNC_NUM_MASK (0x1F000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_FUNC_NUM_SHIFT (12U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_FUNC_NUM_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_FUNC_NUM_MASK)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED2_MASK (0x7E0000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED2_SHIFT (17U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED2(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED2_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED2_MASK)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_DST_MASK (0x800000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_DST_SHIFT (23U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_SRC_MASK (0x1000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_SRC_SHIFT (24U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RO_MASK (0x2000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RO_SHIFT (25U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED5_MASK (0x4000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED5_SHIFT (26U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TC_MASK (0x38000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TC_SHIFT (27U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TC_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TC_MASK)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_AT_MASK (0xC0000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_AT_SHIFT (30U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_AT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_AT_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_AT_MASK)
/*! @} */

/*! @name DMA_TRANSFER_SIZE_OFF_WRCH_0 - DMA Write Transfer Size Register. */
/*! @{ */
#define PCIE_DMA_TRANSFER_SIZE_OFF_WRCH_0_DMA_TRANSFER_SIZE_MASK (0xFFFFFFFFU)
#define PCIE_DMA_TRANSFER_SIZE_OFF_WRCH_0_DMA_TRANSFER_SIZE_SHIFT (0U)
#define PCIE_DMA_TRANSFER_SIZE_OFF_WRCH_0_DMA_TRANSFER_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_TRANSFER_SIZE_OFF_WRCH_0_DMA_TRANSFER_SIZE_SHIFT)) & PCIE_DMA_TRANSFER_SIZE_OFF_WRCH_0_DMA_TRANSFER_SIZE_MASK)
/*! @} */

/*! @name DMA_SAR_LOW_OFF_WRCH_0 - DMA Write SAR Low Register. */
/*! @{ */
#define PCIE_DMA_SAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW_MASK (0xFFFFFFFFU)
#define PCIE_DMA_SAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW_SHIFT (0U)
#define PCIE_DMA_SAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_SAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW_SHIFT)) & PCIE_DMA_SAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW_MASK)
/*! @} */

/*! @name DMA_SAR_HIGH_OFF_WRCH_0 - DMA Write SAR High Register. */
/*! @{ */
#define PCIE_DMA_SAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_DMA_SAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH_SHIFT (0U)
#define PCIE_DMA_SAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_SAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH_SHIFT)) & PCIE_DMA_SAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH_MASK)
/*! @} */

/*! @name DMA_DAR_LOW_OFF_WRCH_0 - DMA Write DAR Low Register. */
/*! @{ */
#define PCIE_DMA_DAR_LOW_OFF_WRCH_0_DST_ADDR_REG_LOW_MASK (0xFFFFFFFFU)
#define PCIE_DMA_DAR_LOW_OFF_WRCH_0_DST_ADDR_REG_LOW_SHIFT (0U)
#define PCIE_DMA_DAR_LOW_OFF_WRCH_0_DST_ADDR_REG_LOW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_DAR_LOW_OFF_WRCH_0_DST_ADDR_REG_LOW_SHIFT)) & PCIE_DMA_DAR_LOW_OFF_WRCH_0_DST_ADDR_REG_LOW_MASK)
/*! @} */

/*! @name DMA_DAR_HIGH_OFF_WRCH_0 - DMA Write DAR High Register. */
/*! @{ */
#define PCIE_DMA_DAR_HIGH_OFF_WRCH_0_DST_ADDR_REG_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_DMA_DAR_HIGH_OFF_WRCH_0_DST_ADDR_REG_HIGH_SHIFT (0U)
#define PCIE_DMA_DAR_HIGH_OFF_WRCH_0_DST_ADDR_REG_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_DAR_HIGH_OFF_WRCH_0_DST_ADDR_REG_HIGH_SHIFT)) & PCIE_DMA_DAR_HIGH_OFF_WRCH_0_DST_ADDR_REG_HIGH_MASK)
/*! @} */

/*! @name DMA_LLP_LOW_OFF_WRCH_0 - DMA Write Linked List Pointer Low Register. */
/*! @{ */
#define PCIE_DMA_LLP_LOW_OFF_WRCH_0_LLP_LOW_MASK (0xFFFFFFFFU)
#define PCIE_DMA_LLP_LOW_OFF_WRCH_0_LLP_LOW_SHIFT (0U)
#define PCIE_DMA_LLP_LOW_OFF_WRCH_0_LLP_LOW(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_LLP_LOW_OFF_WRCH_0_LLP_LOW_SHIFT)) & PCIE_DMA_LLP_LOW_OFF_WRCH_0_LLP_LOW_MASK)
/*! @} */

/*! @name DMA_LLP_HIGH_OFF_WRCH_0 - DMA Write Linked List Pointer High Register. */
/*! @{ */
#define PCIE_DMA_LLP_HIGH_OFF_WRCH_0_LLP_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_DMA_LLP_HIGH_OFF_WRCH_0_LLP_HIGH_SHIFT (0U)
#define PCIE_DMA_LLP_HIGH_OFF_WRCH_0_LLP_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_LLP_HIGH_OFF_WRCH_0_LLP_HIGH_SHIFT)) & PCIE_DMA_LLP_HIGH_OFF_WRCH_0_LLP_HIGH_MASK)
/*! @} */

/*! @name DMA_CH_CONTROL1_OFF_RDCH_0 - DMA Read Channel Control 1 Register. */
/*! @{ */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CB_MASK  (0x1U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CB_SHIFT (0U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_TCB_MASK (0x2U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_TCB_SHIFT (1U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLP_MASK (0x4U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLP_SHIFT (2U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LIE_MASK (0x8U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LIE_SHIFT (3U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_RIE_MASK (0x10U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_RIE_SHIFT (4U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CS_MASK  (0x60U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CS_SHIFT (5U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CS(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CS_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CS_MASK)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED0_MASK (0x80U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED0_SHIFT (7U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CCS_MASK (0x100U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CCS_SHIFT (8U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLE_MASK (0x200U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLE_SHIFT (9U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED1_MASK (0xC00U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED1_SHIFT (10U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED1_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED1_MASK)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_FUNC_NUM_MASK (0x1F000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_FUNC_NUM_SHIFT (12U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_FUNC_NUM_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_FUNC_NUM_MASK)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED2_MASK (0x7E0000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED2_SHIFT (17U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED2(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED2_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED2_MASK)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_DST_MASK (0x800000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_DST_SHIFT (23U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_SRC_MASK (0x1000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_SRC_SHIFT (24U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RO_MASK (0x2000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RO_SHIFT (25U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED5_MASK (0x4000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED5_SHIFT (26U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_TC_MASK (0x38000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_TC_SHIFT (27U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_TC_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_TC_MASK)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_AT_MASK (0xC0000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_AT_SHIFT (30U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_AT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_AT_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_AT_MASK)
/*! @} */

/*! @name DMA_TRANSFER_SIZE_OFF_RDCH_0 - DMA Read Transfer Size Register. */
/*! @{ */
#define PCIE_DMA_TRANSFER_SIZE_OFF_RDCH_0_DMA_TRANSFER_SIZE_MASK (0xFFFFFFFFU)
#define PCIE_DMA_TRANSFER_SIZE_OFF_RDCH_0_DMA_TRANSFER_SIZE_SHIFT (0U)
#define PCIE_DMA_TRANSFER_SIZE_OFF_RDCH_0_DMA_TRANSFER_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_TRANSFER_SIZE_OFF_RDCH_0_DMA_TRANSFER_SIZE_SHIFT)) & PCIE_DMA_TRANSFER_SIZE_OFF_RDCH_0_DMA_TRANSFER_SIZE_MASK)
/*! @} */

/*! @name DMA_SAR_LOW_OFF_RDCH_0 - DMA Read SAR Low Register. */
/*! @{ */
#define PCIE_DMA_SAR_LOW_OFF_RDCH_0_SRC_ADDR_REG_LOW_MASK (0xFFFFFFFFU)
#define PCIE_DMA_SAR_LOW_OFF_RDCH_0_SRC_ADDR_REG_LOW_SHIFT (0U)
#define PCIE_DMA_SAR_LOW_OFF_RDCH_0_SRC_ADDR_REG_LOW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_SAR_LOW_OFF_RDCH_0_SRC_ADDR_REG_LOW_SHIFT)) & PCIE_DMA_SAR_LOW_OFF_RDCH_0_SRC_ADDR_REG_LOW_MASK)
/*! @} */

/*! @name DMA_SAR_HIGH_OFF_RDCH_0 - DMA Read SAR High Register. */
/*! @{ */
#define PCIE_DMA_SAR_HIGH_OFF_RDCH_0_SRC_ADDR_REG_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_DMA_SAR_HIGH_OFF_RDCH_0_SRC_ADDR_REG_HIGH_SHIFT (0U)
#define PCIE_DMA_SAR_HIGH_OFF_RDCH_0_SRC_ADDR_REG_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_SAR_HIGH_OFF_RDCH_0_SRC_ADDR_REG_HIGH_SHIFT)) & PCIE_DMA_SAR_HIGH_OFF_RDCH_0_SRC_ADDR_REG_HIGH_MASK)
/*! @} */

/*! @name DMA_DAR_LOW_OFF_RDCH_0 - DMA Read DAR Low Register. */
/*! @{ */
#define PCIE_DMA_DAR_LOW_OFF_RDCH_0_DST_ADDR_REG_LOW_MASK (0xFFFFFFFFU)
#define PCIE_DMA_DAR_LOW_OFF_RDCH_0_DST_ADDR_REG_LOW_SHIFT (0U)
#define PCIE_DMA_DAR_LOW_OFF_RDCH_0_DST_ADDR_REG_LOW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_DAR_LOW_OFF_RDCH_0_DST_ADDR_REG_LOW_SHIFT)) & PCIE_DMA_DAR_LOW_OFF_RDCH_0_DST_ADDR_REG_LOW_MASK)
/*! @} */

/*! @name DMA_DAR_HIGH_OFF_RDCH_0 - DMA Read DAR High Register. */
/*! @{ */
#define PCIE_DMA_DAR_HIGH_OFF_RDCH_0_DST_ADDR_REG_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_DMA_DAR_HIGH_OFF_RDCH_0_DST_ADDR_REG_HIGH_SHIFT (0U)
#define PCIE_DMA_DAR_HIGH_OFF_RDCH_0_DST_ADDR_REG_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_DAR_HIGH_OFF_RDCH_0_DST_ADDR_REG_HIGH_SHIFT)) & PCIE_DMA_DAR_HIGH_OFF_RDCH_0_DST_ADDR_REG_HIGH_MASK)
/*! @} */

/*! @name DMA_LLP_LOW_OFF_RDCH_0 - DMA Read Linked List Pointer Low Register. */
/*! @{ */
#define PCIE_DMA_LLP_LOW_OFF_RDCH_0_LLP_LOW_MASK (0xFFFFFFFFU)
#define PCIE_DMA_LLP_LOW_OFF_RDCH_0_LLP_LOW_SHIFT (0U)
#define PCIE_DMA_LLP_LOW_OFF_RDCH_0_LLP_LOW(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_LLP_LOW_OFF_RDCH_0_LLP_LOW_SHIFT)) & PCIE_DMA_LLP_LOW_OFF_RDCH_0_LLP_LOW_MASK)
/*! @} */

/*! @name DMA_LLP_HIGH_OFF_RDCH_0 - DMA Read Linked List Pointer High Register. */
/*! @{ */
#define PCIE_DMA_LLP_HIGH_OFF_RDCH_0_LLP_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_DMA_LLP_HIGH_OFF_RDCH_0_LLP_HIGH_SHIFT (0U)
#define PCIE_DMA_LLP_HIGH_OFF_RDCH_0_LLP_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_LLP_HIGH_OFF_RDCH_0_LLP_HIGH_SHIFT)) & PCIE_DMA_LLP_HIGH_OFF_RDCH_0_LLP_HIGH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCIE_Register_Masks */


/* PCIE - Peripheral instance base addresses */
/** Peripheral PCIE0 base pointer */
#define PCIE0_BASE_PTR                           ((PCIE_MemMapPtr)0x33800000u)
/** Peripheral PCIE1 base pointer */
#define PCIE1_BASE_PTR                           ((PCIE_MemMapPtr)0x33C00000u)

/* ----------------------------------------------------------------------------
   -- PCIE - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCIE_Register_Accessor_Macros PCIE - Register accessor macros
 * @{
 */


/* PCIE - Register instance definitions */
/* PCIE1 */
#define PCIE1_TYPE1_DEV_ID_VEND_ID_REG           PCIE_TYPE1_DEV_ID_VEND_ID_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_TYPE1_STATUS_COMMAND_REG           PCIE_TYPE1_STATUS_COMMAND_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_TYPE1_CLASS_CODE_REV_ID_REG        PCIE_TYPE1_CLASS_CODE_REV_ID_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG PCIE_TYPE1_BIST_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_SEC_STAT_IO_LIMIT_IO_BASE_REG      PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_MEM_LIMIT_MEM_BASE_REG             PCIE_MEM_LIMIT_MEM_BASE_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_PREF_MEM_LIMIT_PREF_MEM_BASE_REG   PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_PREF_BASE_UPPER_REG                PCIE_PREF_BASE_UPPER_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_PREF_LIMIT_UPPER_REG               PCIE_PREF_LIMIT_UPPER_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_IO_LIMIT_UPPER_IO_BASE_UPPER_REG   PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_TYPE1_CAP_PTR_REG                  PCIE_TYPE1_CAP_PTR_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_TYPE1_EXP_ROM_BASE_REG             PCIE_TYPE1_EXP_ROM_BASE_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_BRIDGE_CTRL_INT_PIN_INT_LINE_REG   PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_CAP_ID_NXT_PTR_REG                 PCIE_CAP_ID_NXT_PTR_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_CON_STATUS_REG                     PCIE_CON_STATUS_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_PCI_MSI_CAP_ID_NEXT_CTRL_REG       PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CAP_OFF_04H_REG                PCIE_MSI_CAP_OFF_04H_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CAP_OFF_08H_REG                PCIE_MSI_CAP_OFF_08H_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CAP_OFF_0CH_REG                PCIE_MSI_CAP_OFF_0CH_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CAP_OFF_10H_REG                PCIE_MSI_CAP_OFF_10H_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CAP_OFF_14H_REG                PCIE_MSI_CAP_OFF_14H_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_DEVICE_CAPABILITIES_REG            PCIE_DEVICE_CAPABILITIES_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_DEVICE_CONTROL_DEVICE_STATUS       PCIE_DEVICE_CONTROL_DEVICE_STATUS_REG(PCIE1_BASE_PTR)
#define PCIE1_LINK_CAPABILITIES_REG              PCIE_LINK_CAPABILITIES_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_LINK_CONTROL_LINK_STATUS_REG       PCIE_LINK_CONTROL_LINK_STATUS_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_SLOT_CAPABILITIES_REG              PCIE_SLOT_CAPABILITIES_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_SLOT_CONTROL_SLOT_STATUS           PCIE_SLOT_CONTROL_SLOT_STATUS_REG(PCIE1_BASE_PTR)
#define PCIE1_ROOT_CONTROL_ROOT_CAPABILITIES_REG PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_ROOT_STATUS_REG                    PCIE_ROOT_STATUS_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_DEVICE_CAPABILITIES2_REG           PCIE_DEVICE_CAPABILITIES2_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_DEVICE_CONTROL2_DEVICE_STATUS2_REG PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_LINK_CAPABILITIES2_REG             PCIE_LINK_CAPABILITIES2_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_LINK_CONTROL2_LINK_STATUS2_REG     PCIE_LINK_CONTROL2_LINK_STATUS2_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_AER_EXT_CAP_HDR_OFF                PCIE_AER_EXT_CAP_HDR_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_UNCORR_ERR_STATUS_OFF              PCIE_UNCORR_ERR_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_UNCORR_ERR_MASK_OFF                PCIE_UNCORR_ERR_MASK_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_UNCORR_ERR_SEV_OFF                 PCIE_UNCORR_ERR_SEV_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_CORR_ERR_STATUS_OFF                PCIE_CORR_ERR_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_CORR_ERR_MASK_OFF                  PCIE_CORR_ERR_MASK_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_ADV_ERR_CAP_CTRL_OFF               PCIE_ADV_ERR_CAP_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_HDR_LOG_0_OFF                      PCIE_HDR_LOG_0_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_HDR_LOG_1_OFF                      PCIE_HDR_LOG_1_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_HDR_LOG_2_OFF                      PCIE_HDR_LOG_2_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_HDR_LOG_3_OFF                      PCIE_HDR_LOG_3_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_ROOT_ERR_CMD_OFF                   PCIE_ROOT_ERR_CMD_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_ROOT_ERR_STATUS_OFF                PCIE_ROOT_ERR_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_ERR_SRC_ID_OFF                     PCIE_ERR_SRC_ID_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_TLP_PREFIX_LOG_1_OFF               PCIE_TLP_PREFIX_LOG_1_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_TLP_PREFIX_LOG_2_OFF               PCIE_TLP_PREFIX_LOG_2_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_TLP_PREFIX_LOG_3_OFF               PCIE_TLP_PREFIX_LOG_3_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_TLP_PREFIX_LOG_4_OFF               PCIE_TLP_PREFIX_LOG_4_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_L1SUB_CAP_HEADER_REG               PCIE_L1SUB_CAP_HEADER_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_L1SUB_CAPABILITY_REG               PCIE_L1SUB_CAPABILITY_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_L1SUB_CONTROL1_REG                 PCIE_L1SUB_CONTROL1_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_L1SUB_CONTROL2_REG                 PCIE_L1SUB_CONTROL2_REG_REG(PCIE1_BASE_PTR)
#define PCIE1_ACK_LATENCY_TIMER_OFF              PCIE_ACK_LATENCY_TIMER_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_VENDOR_SPEC_DLLP_OFF               PCIE_VENDOR_SPEC_DLLP_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_PORT_FORCE_OFF                     PCIE_PORT_FORCE_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_ACK_F_ASPM_CTRL_OFF                PCIE_ACK_F_ASPM_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_PORT_LINK_CTRL_OFF                 PCIE_PORT_LINK_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_LANE_SKEW_OFF                      PCIE_LANE_SKEW_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_TIMER_CTRL_MAX_FUNC_NUM_OFF        PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_SYMBOL_TIMER_FILTER_1_OFF          PCIE_SYMBOL_TIMER_FILTER_1_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_FILTER_MASK_2_OFF                  PCIE_FILTER_MASK_2_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_PL_DEBUG0_OFF                      PCIE_PL_DEBUG0_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_PL_DEBUG1_OFF                      PCIE_PL_DEBUG1_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_TX_P_FC_CREDIT_STATUS_OFF          PCIE_TX_P_FC_CREDIT_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_TX_NP_FC_CREDIT_STATUS_OFF         PCIE_TX_NP_FC_CREDIT_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_TX_CPL_FC_CREDIT_STATUS_OFF        PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_QUEUE_STATUS_OFF                   PCIE_QUEUE_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_VC_TX_ARBI_1_OFF                   PCIE_VC_TX_ARBI_1_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_VC_TX_ARBI_2_OFF                   PCIE_VC_TX_ARBI_2_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_VC0_P_RX_Q_CTRL_OFF                PCIE_VC0_P_RX_Q_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_VC0_NP_RX_Q_CTRL_OFF               PCIE_VC0_NP_RX_Q_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_VC0_CPL_RX_Q_CTRL_OFF              PCIE_VC0_CPL_RX_Q_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_GEN2_CTRL_OFF                      PCIE_GEN2_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_PHY_STATUS_OFF                     PCIE_PHY_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_PHY_CONTROL_OFF                    PCIE_PHY_CONTROL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_TRGT_MAP_CTRL_OFF                  PCIE_TRGT_MAP_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_ADDR_OFF                  PCIE_MSI_CTRL_ADDR_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_UPPER_ADDR_OFF            PCIE_MSI_CTRL_UPPER_ADDR_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_0_EN_OFF              PCIE_MSI_CTRL_INT_0_EN_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_0_MASK_OFF            PCIE_MSI_CTRL_INT_0_MASK_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_0_STATUS_OFF          PCIE_MSI_CTRL_INT_0_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_1_EN_OFF              PCIE_MSI_CTRL_INT_1_EN_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_1_MASK_OFF            PCIE_MSI_CTRL_INT_1_MASK_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_1_STATUS_OFF          PCIE_MSI_CTRL_INT_1_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_2_EN_OFF              PCIE_MSI_CTRL_INT_2_EN_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_2_MASK_OFF            PCIE_MSI_CTRL_INT_2_MASK_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_2_STATUS_OFF          PCIE_MSI_CTRL_INT_2_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_3_EN_OFF              PCIE_MSI_CTRL_INT_3_EN_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_3_MASK_OFF            PCIE_MSI_CTRL_INT_3_MASK_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_3_STATUS_OFF          PCIE_MSI_CTRL_INT_3_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_4_EN_OFF              PCIE_MSI_CTRL_INT_4_EN_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_4_MASK_OFF            PCIE_MSI_CTRL_INT_4_MASK_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_4_STATUS_OFF          PCIE_MSI_CTRL_INT_4_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_5_EN_OFF              PCIE_MSI_CTRL_INT_5_EN_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_5_MASK_OFF            PCIE_MSI_CTRL_INT_5_MASK_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_5_STATUS_OFF          PCIE_MSI_CTRL_INT_5_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_6_EN_OFF              PCIE_MSI_CTRL_INT_6_EN_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_6_MASK_OFF            PCIE_MSI_CTRL_INT_6_MASK_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_6_STATUS_OFF          PCIE_MSI_CTRL_INT_6_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_7_EN_OFF              PCIE_MSI_CTRL_INT_7_EN_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_7_MASK_OFF            PCIE_MSI_CTRL_INT_7_MASK_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_CTRL_INT_7_STATUS_OFF          PCIE_MSI_CTRL_INT_7_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MSI_GPIO_IO_OFF                    PCIE_MSI_GPIO_IO_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_CLOCK_GATING_CTRL_OFF              PCIE_CLOCK_GATING_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_ORDER_RULE_CTRL_OFF                PCIE_ORDER_RULE_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_PIPE_LOOPBACK_CONTROL_OFF          PCIE_PIPE_LOOPBACK_CONTROL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MISC_CONTROL_1_OFF                 PCIE_MISC_CONTROL_1_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_MULTI_LANE_CONTROL_OFF             PCIE_MULTI_LANE_CONTROL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_PHY_INTEROP_CTRL_OFF               PCIE_PHY_INTEROP_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_TRGT_CPL_LUT_DELETE_ENTRY_OFF      PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_LINK_FLUSH_CONTROL_OFF             PCIE_LINK_FLUSH_CONTROL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_AMBA_ERROR_RESPONSE_DEFAULT_OFF    PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_AMBA_LINK_TIMEOUT_OFF              PCIE_AMBA_LINK_TIMEOUT_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_AMBA_ORDERING_CTRL_OFF             PCIE_AMBA_ORDERING_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_COHERENCY_CONTROL_1_OFF            PCIE_COHERENCY_CONTROL_1_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_COHERENCY_CONTROL_2_OFF            PCIE_COHERENCY_CONTROL_2_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_COHERENCY_CONTROL_3_OFF            PCIE_COHERENCY_CONTROL_3_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_AXI_MSTR_MSG_ADDR_LOW_OFF          PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_AXI_MSTR_MSG_ADDR_HIGH_OFF         PCIE_AXI_MSTR_MSG_ADDR_HIGH_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_PCIE_VERSION_NUMBER_OFF            PCIE_PCIE_VERSION_NUMBER_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_PCIE_VERSION_TYPE_OFF              PCIE_PCIE_VERSION_TYPE_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_AUX_CLK_FREQ_OFF                   PCIE_AUX_CLK_FREQ_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_L1_SUBSTATES_OFF                   PCIE_L1_SUBSTATES_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_1_OFF_OUTBOUND_0  PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_2_OFF_OUTBOUND_0  PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0  PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0 PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LIMIT_ADDR_OFF_OUTBOUND_0     PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0 PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0 PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_1_OFF_INBOUND_0   PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_2_OFF_INBOUND_0   PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_BASE_ADDR_OFF_INBOUND_0   PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_UPPER_BASE_ADDR_OFF_INBOUND_0 PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_0_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LIMIT_ADDR_OFF_INBOUND_0      PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0 PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_1_OFF_OUTBOUND_1  PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_2_OFF_OUTBOUND_1  PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1  PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1 PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LIMIT_ADDR_OFF_OUTBOUND_1     PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1 PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1 PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_1_OFF_INBOUND_1   PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_2_OFF_INBOUND_1   PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_BASE_ADDR_OFF_INBOUND_1   PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_UPPER_BASE_ADDR_OFF_INBOUND_1 PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_1_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LIMIT_ADDR_OFF_INBOUND_1      PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1 PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_1_OFF_OUTBOUND_2  PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_2_OFF_OUTBOUND_2  PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2  PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2 PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LIMIT_ADDR_OFF_OUTBOUND_2     PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2 PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2 PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_1_OFF_INBOUND_2   PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_2_OFF_INBOUND_2   PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_BASE_ADDR_OFF_INBOUND_2   PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_UPPER_BASE_ADDR_OFF_INBOUND_2 PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_2_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LIMIT_ADDR_OFF_INBOUND_2      PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2 PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_1_OFF_OUTBOUND_3  PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_2_OFF_OUTBOUND_3  PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3  PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3 PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LIMIT_ADDR_OFF_OUTBOUND_3     PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3 PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3 PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_1_OFF_INBOUND_3   PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_REGION_CTRL_2_OFF_INBOUND_3   PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_BASE_ADDR_OFF_INBOUND_3   PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_UPPER_BASE_ADDR_OFF_INBOUND_3 PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_3_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LIMIT_ADDR_OFF_INBOUND_3      PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_REG(PCIE1_BASE_PTR)
#define PCIE1_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3 PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_CTRL_DATA_ARB_PRIOR_OFF        PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_CTRL_OFF                       PCIE_DMA_CTRL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_ENGINE_EN_OFF            PCIE_DMA_WRITE_ENGINE_EN_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_DOORBELL_OFF             PCIE_DMA_WRITE_DOORBELL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_ENGINE_EN_OFF             PCIE_DMA_READ_ENGINE_EN_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_DOORBELL_OFF              PCIE_DMA_READ_DOORBELL_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_INT_STATUS_OFF           PCIE_DMA_WRITE_INT_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_INT_MASK_OFF             PCIE_DMA_WRITE_INT_MASK_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_INT_CLEAR_OFF            PCIE_DMA_WRITE_INT_CLEAR_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_ERR_STATUS_OFF           PCIE_DMA_WRITE_ERR_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_DONE_IMWR_LOW_OFF        PCIE_DMA_WRITE_DONE_IMWR_LOW_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_DONE_IMWR_HIGH_OFF       PCIE_DMA_WRITE_DONE_IMWR_HIGH_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_ABORT_IMWR_LOW_OFF       PCIE_DMA_WRITE_ABORT_IMWR_LOW_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_ABORT_IMWR_HIGH_OFF      PCIE_DMA_WRITE_ABORT_IMWR_HIGH_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_CH01_IMWR_DATA_OFF       PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_CH23_IMWR_DATA_OFF       PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_CH45_IMWR_DATA_OFF       PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_CH67_IMWR_DATA_OFF       PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_WRITE_LINKED_LIST_ERR_EN_OFF   PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_INT_STATUS_OFF            PCIE_DMA_READ_INT_STATUS_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_INT_MASK_OFF              PCIE_DMA_READ_INT_MASK_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_INT_CLEAR_OFF             PCIE_DMA_READ_INT_CLEAR_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_ERR_STATUS_LOW_OFF        PCIE_DMA_READ_ERR_STATUS_LOW_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_ERR_STATUS_HIGH_OFF       PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_LINKED_LIST_ERR_EN_OFF    PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_DONE_IMWR_LOW_OFF         PCIE_DMA_READ_DONE_IMWR_LOW_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_DONE_IMWR_HIGH_OFF        PCIE_DMA_READ_DONE_IMWR_HIGH_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_ABORT_IMWR_LOW_OFF        PCIE_DMA_READ_ABORT_IMWR_LOW_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_ABORT_IMWR_HIGH_OFF       PCIE_DMA_READ_ABORT_IMWR_HIGH_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_CH01_IMWR_DATA_OFF        PCIE_DMA_READ_CH01_IMWR_DATA_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_CH23_IMWR_DATA_OFF        PCIE_DMA_READ_CH23_IMWR_DATA_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_CH45_IMWR_DATA_OFF        PCIE_DMA_READ_CH45_IMWR_DATA_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_READ_CH67_IMWR_DATA_OFF        PCIE_DMA_READ_CH67_IMWR_DATA_OFF_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_CH_CONTROL1_OFF_WRCH_0         PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_TRANSFER_SIZE_OFF_WRCH_0       PCIE_DMA_TRANSFER_SIZE_OFF_WRCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_SAR_LOW_OFF_WRCH_0             PCIE_DMA_SAR_LOW_OFF_WRCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_SAR_HIGH_OFF_WRCH_0            PCIE_DMA_SAR_HIGH_OFF_WRCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_DAR_LOW_OFF_WRCH_0             PCIE_DMA_DAR_LOW_OFF_WRCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_DAR_HIGH_OFF_WRCH_0            PCIE_DMA_DAR_HIGH_OFF_WRCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_LLP_LOW_OFF_WRCH_0             PCIE_DMA_LLP_LOW_OFF_WRCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_LLP_HIGH_OFF_WRCH_0            PCIE_DMA_LLP_HIGH_OFF_WRCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_CH_CONTROL1_OFF_RDCH_0         PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_TRANSFER_SIZE_OFF_RDCH_0       PCIE_DMA_TRANSFER_SIZE_OFF_RDCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_SAR_LOW_OFF_RDCH_0             PCIE_DMA_SAR_LOW_OFF_RDCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_SAR_HIGH_OFF_RDCH_0            PCIE_DMA_SAR_HIGH_OFF_RDCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_DAR_LOW_OFF_RDCH_0             PCIE_DMA_DAR_LOW_OFF_RDCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_DAR_HIGH_OFF_RDCH_0            PCIE_DMA_DAR_HIGH_OFF_RDCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_LLP_LOW_OFF_RDCH_0             PCIE_DMA_LLP_LOW_OFF_RDCH_0_REG(PCIE1_BASE_PTR)
#define PCIE1_DMA_LLP_HIGH_OFF_RDCH_0            PCIE_DMA_LLP_HIGH_OFF_RDCH_0_REG(PCIE1_BASE_PTR)

/*!
 * @}
 */ /* end of group PCIE_Register_Accessor_Macros */

 /* ----------------------------------------------------------------------------
   -- PCIE_PHY
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCIE_PHY_Peripheral PCIE_PHY
 * @{
 */

/** PCIE_PHY - Peripheral register structure */
typedef struct PCIE_PHY_MemMap {
  uint8_t CMN_REG000;                              /**< , offset: 0x0 */
  uint8_t RESERVED_0[3];
  uint8_t CMN_REG001;                              /**< , offset: 0x4 */
  uint8_t RESERVED_1[3];
  uint8_t CMN_REG002;                              /**< , offset: 0x8 */
  uint8_t RESERVED_2[3];
  uint8_t CMN_REG003;                              /**< , offset: 0xC */
  uint8_t RESERVED_3[3];
  uint8_t CMN_REG004;                              /**< , offset: 0x10 */
  uint8_t RESERVED_4[3];
  uint8_t CMN_REG005;                              /**< , offset: 0x14 */
  uint8_t RESERVED_5[3];
  uint8_t CMN_REG006;                              /**< , offset: 0x18 */
  uint8_t RESERVED_6[3];
  uint8_t CMN_REG007;                              /**< , offset: 0x1C */
  uint8_t RESERVED_7[3];
  uint8_t CMN_REG008;                              /**< , offset: 0x20 */
  uint8_t RESERVED_8[3];
  uint8_t CMN_REG009;                              /**< , offset: 0x24 */
  uint8_t RESERVED_9[3];
  uint8_t CMN_REG00A;                              /**< , offset: 0x28 */
  uint8_t RESERVED_10[3];
  uint8_t CMN_REG00B;                              /**< , offset: 0x2C */
  uint8_t RESERVED_11[3];
  uint8_t CMN_REG00C;                              /**< , offset: 0x30 */
  uint8_t RESERVED_12[3];
  uint8_t CMN_REG00D;                              /**< , offset: 0x34 */
  uint8_t RESERVED_13[3];
  uint8_t CMN_REG00E;                              /**< , offset: 0x38 */
  uint8_t RESERVED_14[3];
  uint8_t CMN_REG00F;                              /**< , offset: 0x3C */
  uint8_t RESERVED_15[3];
  uint8_t CMN_REG010;                              /**< , offset: 0x40 */
  uint8_t RESERVED_16[3];
  uint8_t CMN_REG011;                              /**< , offset: 0x44 */
  uint8_t RESERVED_17[3];
  uint8_t CMN_REG012;                              /**< , offset: 0x48 */
  uint8_t RESERVED_18[3];
  uint8_t CMN_REG013;                              /**< , offset: 0x4C */
  uint8_t RESERVED_19[3];
  uint8_t CMN_REG014;                              /**< , offset: 0x50 */
  uint8_t RESERVED_20[3];
  uint8_t CMN_REG015;                              /**< , offset: 0x54 */
  uint8_t RESERVED_21[3];
  uint8_t CMN_REG016;                              /**< , offset: 0x58 */
  uint8_t RESERVED_22[3];
  uint8_t CMN_REG017;                              /**< , offset: 0x5C */
  uint8_t RESERVED_23[3];
  uint8_t CMN_REG018;                              /**< , offset: 0x60 */
  uint8_t RESERVED_24[3];
  uint8_t CMN_REG019;                              /**< , offset: 0x64 */
  uint8_t RESERVED_25[3];
  uint8_t CMN_REG01A;                              /**< , offset: 0x68 */
  uint8_t RESERVED_26[3];
  uint8_t CMN_REG01B;                              /**< , offset: 0x6C */
  uint8_t RESERVED_27[3];
  uint8_t CMN_REG01C;                              /**< , offset: 0x70 */
  uint8_t RESERVED_28[3];
  uint8_t CMN_REG01D;                              /**< , offset: 0x74 */
  uint8_t RESERVED_29[3];
  uint8_t CMN_REG01E;                              /**< , offset: 0x78 */
  uint8_t RESERVED_30[3];
  uint8_t CMN_REG01F;                              /**< , offset: 0x7C */
  uint8_t RESERVED_31[3];
  uint8_t CMN_REG020;                              /**< , offset: 0x80 */
  uint8_t RESERVED_32[3];
  uint8_t CMN_REG021;                              /**< , offset: 0x84 */
  uint8_t RESERVED_33[3];
  uint8_t CMN_REG022;                              /**< , offset: 0x88 */
  uint8_t RESERVED_34[3];
  uint8_t CMN_REG023;                              /**< , offset: 0x8C */
  uint8_t RESERVED_35[3];
  uint8_t CMN_REG024;                              /**< , offset: 0x90 */
  uint8_t RESERVED_36[3];
  uint8_t CMN_REG025;                              /**< , offset: 0x94 */
  uint8_t RESERVED_37[3];
  uint8_t CMN_REG026;                              /**< , offset: 0x98 */
  uint8_t RESERVED_38[3];
  uint8_t CMN_REG027;                              /**< , offset: 0x9C */
  uint8_t RESERVED_39[3];
  uint8_t CMN_REG028;                              /**< , offset: 0xA0 */
  uint8_t RESERVED_40[3];
  uint8_t CMN_REG029;                              /**< , offset: 0xA4 */
  uint8_t RESERVED_41[3];
  uint8_t CMN_REG02A;                              /**< , offset: 0xA8 */
  uint8_t RESERVED_42[3];
  uint8_t CMN_REG02B;                              /**< , offset: 0xAC */
  uint8_t RESERVED_43[3];
  uint8_t CMN_REG02C;                              /**< , offset: 0xB0 */
  uint8_t RESERVED_44[3];
  uint8_t CMN_REG02D;                              /**< , offset: 0xB4 */
  uint8_t RESERVED_45[3];
  uint8_t CMN_REG02E;                              /**< , offset: 0xB8 */
  uint8_t RESERVED_46[3];
  uint8_t CMN_REG02F;                              /**< , offset: 0xBC */
  uint8_t RESERVED_47[3];
  uint8_t CMN_REG030;                              /**< , offset: 0xC0 */
  uint8_t RESERVED_48[3];
  uint8_t CMN_REG031;                              /**< , offset: 0xC4 */
  uint8_t RESERVED_49[3];
  uint8_t CMN_REG032;                              /**< , offset: 0xC8 */
  uint8_t RESERVED_50[3];
  uint8_t CMN_REG033;                              /**< , offset: 0xCC */
  uint8_t RESERVED_51[3];
  uint8_t CMN_REG034;                              /**< , offset: 0xD0 */
  uint8_t RESERVED_52[3];
  uint8_t CMN_REG035;                              /**< , offset: 0xD4 */
  uint8_t RESERVED_53[3];
  uint8_t CMN_REG036;                              /**< , offset: 0xD8 */
  uint8_t RESERVED_54[3];
  uint8_t CMN_REG037;                              /**< , offset: 0xDC */
  uint8_t RESERVED_55[3];
  uint8_t CMN_REG038;                              /**< , offset: 0xE0 */
  uint8_t RESERVED_56[3];
  uint8_t CMN_REG039;                              /**< , offset: 0xE4 */
  uint8_t RESERVED_57[3];
  uint8_t CMN_REG03A;                              /**< , offset: 0xE8 */
  uint8_t RESERVED_58[3];
  uint8_t CMN_REG03B;                              /**< , offset: 0xEC */
  uint8_t RESERVED_59[3];
  uint8_t CMN_REG03C;                              /**< , offset: 0xF0 */
  uint8_t RESERVED_60[3];
  uint8_t CMN_REG03D;                              /**< , offset: 0xF4 */
  uint8_t RESERVED_61[3];
  uint8_t CMN_REG03E;                              /**< , offset: 0xF8 */
  uint8_t RESERVED_62[3];
  uint8_t CMN_REG03F;                              /**< , offset: 0xFC */
  uint8_t RESERVED_63[3];
  uint8_t CMN_REG040;                              /**< , offset: 0x100 */
  uint8_t RESERVED_64[3];
  uint8_t CMN_REG041;                              /**< , offset: 0x104 */
  uint8_t RESERVED_65[3];
  uint8_t CMN_REG042;                              /**< , offset: 0x108 */
  uint8_t RESERVED_66[3];
  uint8_t CMN_REG043;                              /**< , offset: 0x10C */
  uint8_t RESERVED_67[3];
  uint8_t CMN_REG044;                              /**< , offset: 0x110 */
  uint8_t RESERVED_68[3];
  uint8_t CMN_REG045;                              /**< , offset: 0x114 */
  uint8_t RESERVED_69[3];
  uint8_t CMN_REG046;                              /**< , offset: 0x118 */
  uint8_t RESERVED_70[3];
  uint8_t CMN_REG047;                              /**< , offset: 0x11C */
  uint8_t RESERVED_71[3];
  uint8_t CMN_REG048;                              /**< , offset: 0x120 */
  uint8_t RESERVED_72[3];
  uint8_t CMN_REG049;                              /**< , offset: 0x124 */
  uint8_t RESERVED_73[3];
  uint8_t CMN_REG04A;                              /**< , offset: 0x128 */
  uint8_t RESERVED_74[3];
  uint8_t CMN_REG04B;                              /**< , offset: 0x12C */
  uint8_t RESERVED_75[3];
  uint8_t CMN_REG04C;                              /**< , offset: 0x130 */
  uint8_t RESERVED_76[3];
  uint8_t CMN_REG04D;                              /**< , offset: 0x134 */
  uint8_t RESERVED_77[3];
  uint8_t CMN_REG04E;                              /**< , offset: 0x138 */
  uint8_t RESERVED_78[3];
  uint8_t CMN_REG04F;                              /**< , offset: 0x13C */
  uint8_t RESERVED_79[3];
  uint8_t CMN_REG050;                              /**< , offset: 0x140 */
  uint8_t RESERVED_80[3];
  uint8_t CMN_REG051;                              /**< , offset: 0x144 */
  uint8_t RESERVED_81[3];
  uint8_t CMN_REG052;                              /**< , offset: 0x148 */
  uint8_t RESERVED_82[3];
  uint8_t CMN_REG053;                              /**< , offset: 0x14C */
  uint8_t RESERVED_83[3];
  uint8_t CMN_REG054;                              /**< , offset: 0x150 */
  uint8_t RESERVED_84[3];
  uint8_t CMN_REG055;                              /**< , offset: 0x154 */
  uint8_t RESERVED_85[3];
  uint8_t CMN_REG056;                              /**< , offset: 0x158 */
  uint8_t RESERVED_86[3];
  uint8_t CMN_REG057;                              /**< , offset: 0x15C */
  uint8_t RESERVED_87[3];
  uint8_t CMN_REG058;                              /**< , offset: 0x160 */
  uint8_t RESERVED_88[3];
  uint8_t CMN_REG059;                              /**< , offset: 0x164 */
  uint8_t RESERVED_89[3];
  uint8_t CMN_REG05A;                              /**< , offset: 0x168 */
  uint8_t RESERVED_90[3];
  uint8_t CMN_REG05B;                              /**< , offset: 0x16C */
  uint8_t RESERVED_91[3];
  uint8_t CMN_REG05C;                              /**< , offset: 0x170 */
  uint8_t RESERVED_92[3];
  uint8_t CMN_REG05D;                              /**< , offset: 0x174 */
  uint8_t RESERVED_93[3];
  uint8_t CMN_REG05E;                              /**< , offset: 0x178 */
  uint8_t RESERVED_94[3];
  uint8_t CMN_REG05F;                              /**< , offset: 0x17C */
  uint8_t RESERVED_95[3];
  uint8_t CMN_REG060;                              /**< , offset: 0x180 */
  uint8_t RESERVED_96[3];
  uint8_t CMN_REG061;                              /**< , offset: 0x184 */
  uint8_t RESERVED_97[3];
  uint8_t CMN_REG062;                              /**< , offset: 0x188 */
  uint8_t RESERVED_98[3];
  uint8_t CMN_REG063;                              /**< , offset: 0x18C */
  uint8_t RESERVED_99[3];
  uint8_t CMN_REG064;                              /**< , offset: 0x190 */
  uint8_t RESERVED_100[3];
  uint8_t CMN_REG065;                              /**< , offset: 0x194 */
  uint8_t RESERVED_101[3];
  uint8_t CMN_REG066;                              /**< , offset: 0x198 */
  uint8_t RESERVED_102[3];
  uint8_t CMN_REG067;                              /**< , offset: 0x19C */
  uint8_t RESERVED_103[3];
  uint8_t CMN_REG068;                              /**< , offset: 0x1A0 */
  uint8_t RESERVED_104[3];
  uint8_t CMN_REG069;                              /**< , offset: 0x1A4 */
  uint8_t RESERVED_105[3];
  uint8_t CMN_REG06A;                              /**< , offset: 0x1A8 */
  uint8_t RESERVED_106[3];
  uint8_t CMN_REG06B;                              /**< , offset: 0x1AC */
  uint8_t RESERVED_107[3];
  uint8_t CMN_REG06C;                              /**< , offset: 0x1B0 */
  uint8_t RESERVED_108[3];
  uint8_t CMN_REG06D;                              /**< , offset: 0x1B4 */
  uint8_t RESERVED_109[3];
  uint8_t CMN_REG06E;                              /**< , offset: 0x1B8 */
  uint8_t RESERVED_110[3];
  uint8_t CMN_REG06F;                              /**< , offset: 0x1BC */
  uint8_t RESERVED_111[3];
  uint8_t CMN_REG070;                              /**< , offset: 0x1C0 */
  uint8_t RESERVED_112[3];
  uint8_t CMN_REG071;                              /**< , offset: 0x1C4 */
  uint8_t RESERVED_113[3];
  uint8_t CMN_REG072;                              /**< , offset: 0x1C8 */
  uint8_t RESERVED_114[3];
  uint8_t CMN_REG073;                              /**< , offset: 0x1CC */
  uint8_t RESERVED_115[3];
  uint8_t CMN_REG074;                              /**< , offset: 0x1D0 */
  uint8_t RESERVED_116[3];
  uint8_t CMN_REG075;                              /**< , offset: 0x1D4 */
  uint8_t RESERVED_117[43];
  uint8_t CMN_REG076;                              /**< , offset: 0x200 */
  uint8_t RESERVED_118[3];
  uint8_t CMN_REG077;                              /**< , offset: 0x204 */
  uint8_t RESERVED_119[3];
  uint8_t CMN_REG078;                              /**< , offset: 0x208 */
  uint8_t RESERVED_120[3];
  uint8_t CMN_REG079;                              /**< , offset: 0x20C */
  uint8_t RESERVED_121[3];
  uint8_t CMN_REG080;                              /**< , offset: 0x210 */
  uint8_t RESERVED_122[3];
  uint8_t CMN_REG081;                              /**< , offset: 0x214 */
  uint8_t RESERVED_123[3];
  uint8_t CMN_REG082;                              /**< , offset: 0x218 */
  uint8_t RESERVED_124[487];
  uint8_t TRSV_REG000;                             /**< , offset: 0x400 */
  uint8_t RESERVED_125[3];
  uint8_t TRSV_REG001;                             /**< , offset: 0x404 */
  uint8_t RESERVED_126[3];
  uint8_t TRSV_REG002;                             /**< , offset: 0x408 */
  uint8_t RESERVED_127[3];
  uint8_t TRSV_REG003;                             /**< , offset: 0x40C */
  uint8_t RESERVED_128[3];
  uint8_t TRSV_REG004;                             /**< , offset: 0x410 */
  uint8_t RESERVED_129[3];
  uint8_t TRSV_REG005;                             /**< , offset: 0x414 */
  uint8_t RESERVED_130[3];
  uint8_t TRSV_REG006;                             /**< , offset: 0x418 */
  uint8_t RESERVED_131[3];
  uint8_t TRSV_REG007;                             /**< , offset: 0x41C */
  uint8_t RESERVED_132[3];
  uint8_t TRSV_REG008;                             /**< , offset: 0x420 */
  uint8_t RESERVED_133[3];
  uint8_t TRSV_REG009;                             /**< , offset: 0x424 */
  uint8_t RESERVED_134[3];
  uint8_t TRSV_REG00A;                             /**< , offset: 0x428 */
  uint8_t RESERVED_135[3];
  uint8_t TRSV_REG00B;                             /**< , offset: 0x42C */
  uint8_t RESERVED_136[3];
  uint8_t TRSV_REG00C;                             /**< , offset: 0x430 */
  uint8_t RESERVED_137[3];
  uint8_t TRSV_REG00D;                             /**< , offset: 0x434 */
  uint8_t RESERVED_138[3];
  uint8_t TRSV_REG00E;                             /**< , offset: 0x438 */
  uint8_t RESERVED_139[3];
  uint8_t TRSV_REG00F;                             /**< , offset: 0x43C */
  uint8_t RESERVED_140[3];
  uint8_t TRSV_REG010;                             /**< , offset: 0x440 */
  uint8_t RESERVED_141[3];
  uint8_t TRSV_REG011;                             /**< , offset: 0x444 */
  uint8_t RESERVED_142[3];
  uint8_t TRSV_REG012;                             /**< , offset: 0x448 */
  uint8_t RESERVED_143[3];
  uint8_t TRSV_REG013;                             /**< , offset: 0x44C */
  uint8_t RESERVED_144[3];
  uint8_t TRSV_REG014;                             /**< , offset: 0x450 */
  uint8_t RESERVED_145[3];
  uint8_t TRSV_REG015;                             /**< , offset: 0x454 */
  uint8_t RESERVED_146[3];
  uint8_t TRSV_REG016;                             /**< , offset: 0x458 */
  uint8_t RESERVED_147[3];
  uint8_t TRSV_REG017;                             /**< , offset: 0x45C */
  uint8_t RESERVED_148[3];
  uint8_t TRSV_REG018;                             /**< , offset: 0x460 */
  uint8_t RESERVED_149[3];
  uint8_t TRSV_REG019;                             /**< , offset: 0x464 */
  uint8_t RESERVED_150[3];
  uint8_t TRSV_REG01A;                             /**< , offset: 0x468 */
  uint8_t RESERVED_151[3];
  uint8_t TRSV_REG01B;                             /**< , offset: 0x46C */
  uint8_t RESERVED_152[3];
  uint8_t TRSV_REG01C;                             /**< , offset: 0x470 */
  uint8_t RESERVED_153[3];
  uint8_t TRSV_REG01D;                             /**< , offset: 0x474 */
  uint8_t RESERVED_154[3];
  uint8_t TRSV_REG01E;                             /**< , offset: 0x478 */
  uint8_t RESERVED_155[3];
  uint8_t TRSV_REG01F;                             /**< , offset: 0x47C */
  uint8_t RESERVED_156[3];
  uint8_t TRSV_REG020;                             /**< , offset: 0x480 */
  uint8_t RESERVED_157[3];
  uint8_t TRSV_REG021;                             /**< , offset: 0x484 */
  uint8_t RESERVED_158[3];
  uint8_t TRSV_REG022;                             /**< , offset: 0x488 */
  uint8_t RESERVED_159[3];
  uint8_t TRSV_REG023;                             /**< , offset: 0x48C */
  uint8_t RESERVED_160[3];
  uint8_t TRSV_REG024;                             /**< , offset: 0x490 */
  uint8_t RESERVED_161[3];
  uint8_t TRSV_REG025;                             /**< , offset: 0x494 */
  uint8_t RESERVED_162[3];
  uint8_t TRSV_REG026;                             /**< , offset: 0x498 */
  uint8_t RESERVED_163[3];
  uint8_t TRSV_REG027;                             /**< , offset: 0x49C */
  uint8_t RESERVED_164[3];
  uint8_t TRSV_REG028;                             /**< , offset: 0x4A0 */
  uint8_t RESERVED_165[3];
  uint8_t TRSV_REG029;                             /**< , offset: 0x4A4 */
  uint8_t RESERVED_166[3];
  uint8_t TRSV_REG02A;                             /**< , offset: 0x4A8 */
  uint8_t RESERVED_167[3];
  uint8_t TRSV_REG02B;                             /**< , offset: 0x4AC */
  uint8_t RESERVED_168[3];
  uint8_t TRSV_REG02C;                             /**< , offset: 0x4B0 */
  uint8_t RESERVED_169[3];
  uint8_t TRSV_REG02D;                             /**< , offset: 0x4B4 */
  uint8_t RESERVED_170[3];
  uint8_t TRSV_REG02E;                             /**< , offset: 0x4B8 */
  uint8_t RESERVED_171[3];
  uint8_t TRSV_REG02F;                             /**< , offset: 0x4BC */
  uint8_t RESERVED_172[3];
  uint8_t TRSV_REG030;                             /**< , offset: 0x4C0 */
  uint8_t RESERVED_173[3];
  uint8_t TRSV_REG031;                             /**< , offset: 0x4C4 */
  uint8_t RESERVED_174[3];
  uint8_t TRSV_REG032;                             /**< , offset: 0x4C8 */
  uint8_t RESERVED_175[3];
  uint8_t TRSV_REG033;                             /**< , offset: 0x4CC */
  uint8_t RESERVED_176[3];
  uint8_t TRSV_REG034;                             /**< , offset: 0x4D0 */
  uint8_t RESERVED_177[3];
  uint8_t TRSV_REG035;                             /**< , offset: 0x4D4 */
  uint8_t RESERVED_178[3];
  uint8_t TRSV_REG036;                             /**< , offset: 0x4D8 */
  uint8_t RESERVED_179[3];
  uint8_t TRSV_REG037;                             /**< , offset: 0x4DC */
  uint8_t RESERVED_180[3];
  uint8_t TRSV_REG038;                             /**< , offset: 0x4E0 */
  uint8_t RESERVED_181[3];
  uint8_t TRSV_REG039;                             /**< , offset: 0x4E4 */
  uint8_t RESERVED_182[3];
  uint8_t TRSV_REG03A;                             /**< , offset: 0x4E8 */
  uint8_t RESERVED_183[3];
  uint8_t TRSV_REG03B;                             /**< , offset: 0x4EC */
  uint8_t RESERVED_184[3];
  uint8_t TRSV_REG03C;                             /**< , offset: 0x4F0 */
  uint8_t RESERVED_185[3];
  uint8_t TRSV_REG03D;                             /**< , offset: 0x4F4 */
  uint8_t RESERVED_186[3];
  uint8_t TRSV_REG03E;                             /**< , offset: 0x4F8 */
  uint8_t RESERVED_187[3];
  uint8_t TRSV_REG03F;                             /**< , offset: 0x4FC */
  uint8_t RESERVED_188[3];
  uint8_t TRSV_REG040;                             /**< , offset: 0x500 */
  uint8_t RESERVED_189[3];
  uint8_t TRSV_REG041;                             /**< , offset: 0x504 */
  uint8_t RESERVED_190[3];
  uint8_t TRSV_REG042;                             /**< , offset: 0x508 */
  uint8_t RESERVED_191[3];
  uint8_t TRSV_REG043;                             /**< , offset: 0x50C */
  uint8_t RESERVED_192[3];
  uint8_t TRSV_REG044;                             /**< , offset: 0x510 */
  uint8_t RESERVED_193[3];
  uint8_t TRSV_REG045;                             /**< , offset: 0x514 */
  uint8_t RESERVED_194[3];
  uint8_t TRSV_REG046;                             /**< , offset: 0x518 */
  uint8_t RESERVED_195[3];
  uint8_t TRSV_REG047;                             /**< , offset: 0x51C */
  uint8_t RESERVED_196[3];
  uint8_t TRSV_REG048;                             /**< , offset: 0x520 */
  uint8_t RESERVED_197[3];
  uint8_t TRSV_REG049;                             /**< , offset: 0x524 */
  uint8_t RESERVED_198[3];
  uint8_t TRSV_REG04A;                             /**< , offset: 0x528 */
  uint8_t RESERVED_199[3];
  uint8_t TRSV_REG04B;                             /**< , offset: 0x52C */
  uint8_t RESERVED_200[3];
  uint8_t TRSV_REG04C;                             /**< , offset: 0x530 */
  uint8_t RESERVED_201[3];
  uint8_t TRSV_REG04D;                             /**< , offset: 0x534 */
  uint8_t RESERVED_202[3];
  uint8_t TRSV_REG04E;                             /**< , offset: 0x538 */
  uint8_t RESERVED_203[3];
  uint8_t TRSV_REG04F;                             /**< , offset: 0x53C */
  uint8_t RESERVED_204[3];
  uint8_t TRSV_REG050;                             /**< , offset: 0x540 */
  uint8_t RESERVED_205[3];
  uint8_t TRSV_REG051;                             /**< , offset: 0x544 */
  uint8_t RESERVED_206[3];
  uint8_t TRSV_REG052;                             /**< , offset: 0x548 */
  uint8_t RESERVED_207[3];
  uint8_t TRSV_REG053;                             /**< , offset: 0x54C */
  uint8_t RESERVED_208[3];
  uint8_t TRSV_REG054;                             /**< , offset: 0x550 */
  uint8_t RESERVED_209[3];
  uint8_t TRSV_REG055;                             /**< , offset: 0x554 */
  uint8_t RESERVED_210[3];
  uint8_t TRSV_REG056;                             /**< , offset: 0x558 */
  uint8_t RESERVED_211[3];
  uint8_t TRSV_REG057;                             /**< , offset: 0x55C */
  uint8_t RESERVED_212[3];
  uint8_t TRSV_REG058;                             /**< , offset: 0x560 */
  uint8_t RESERVED_213[3];
  uint8_t TRSV_REG059;                             /**< , offset: 0x564 */
  uint8_t RESERVED_214[3];
  uint8_t TRSV_REG05A;                             /**< , offset: 0x568 */
  uint8_t RESERVED_215[3];
  uint8_t TRSV_REG05B;                             /**< , offset: 0x56C */
  uint8_t RESERVED_216[3];
  uint8_t TRSV_REG05C;                             /**< , offset: 0x570 */
  uint8_t RESERVED_217[3];
  uint8_t TRSV_REG05D;                             /**< , offset: 0x574 */
  uint8_t RESERVED_218[3];
  uint8_t TRSV_REG05E;                             /**< , offset: 0x578 */
  uint8_t RESERVED_219[3];
  uint8_t TRSV_REG05F;                             /**< , offset: 0x57C */
  uint8_t RESERVED_220[3];
  uint8_t TRSV_REG060;                             /**< , offset: 0x580 */
  uint8_t RESERVED_221[3];
  uint8_t TRSV_REG061;                             /**< , offset: 0x584 */
  uint8_t RESERVED_222[3];
  uint8_t TRSV_REG062;                             /**< , offset: 0x588 */
  uint8_t RESERVED_223[3];
  uint8_t TRSV_REG063;                             /**< , offset: 0x58C */
  uint8_t RESERVED_224[3];
  uint8_t TRSV_REG064;                             /**< , offset: 0x590 */
  uint8_t RESERVED_225[3];
  uint8_t TRSV_REG065;                             /**< , offset: 0x594 */
  uint8_t RESERVED_226[3];
  uint8_t TRSV_REG066;                             /**< , offset: 0x598 */
  uint8_t RESERVED_227[3];
  uint8_t TRSV_REG067;                             /**< , offset: 0x59C */
  uint8_t RESERVED_228[3];
  uint8_t TRSV_REG068;                             /**< , offset: 0x5A0 */
  uint8_t RESERVED_229[3];
  uint8_t TRSV_REG069;                             /**< , offset: 0x5A4 */
  uint8_t RESERVED_230[3];
  uint8_t TRSV_REG06A;                             /**< , offset: 0x5A8 */
  uint8_t RESERVED_231[3];
  uint8_t TRSV_REG06B;                             /**< , offset: 0x5AC */
  uint8_t RESERVED_232[3];
  uint8_t TRSV_REG06C;                             /**< , offset: 0x5B0 */
  uint8_t RESERVED_233[3];
  uint8_t TRSV_REG06D;                             /**< , offset: 0x5B4 */
  uint8_t RESERVED_234[3];
  uint8_t TRSV_REG06E;                             /**< , offset: 0x5B8 */
  uint8_t RESERVED_235[3];
  uint8_t TRSV_REG06F;                             /**< , offset: 0x5BC */
  uint8_t RESERVED_236[3];
  uint8_t TRSV_REG070;                             /**< , offset: 0x5C0 */
  uint8_t RESERVED_237[3];
  uint8_t TRSV_REG071;                             /**< , offset: 0x5C4 */
  uint8_t RESERVED_238[3];
  uint8_t TRSV_REG072;                             /**< , offset: 0x5C8 */
  uint8_t RESERVED_239[3];
  uint8_t TRSV_REG073;                             /**< , offset: 0x5CC */
  uint8_t RESERVED_240[3];
  uint8_t TRSV_REG074;                             /**< , offset: 0x5D0 */
  uint8_t RESERVED_241[3];
  uint8_t TRSV_REG075;                             /**< , offset: 0x5D4 */
  uint8_t RESERVED_242[3];
  uint8_t TRSV_REG076;                             /**< , offset: 0x5D8 */
  uint8_t RESERVED_243[3];
  uint8_t TRSV_REG077;                             /**< , offset: 0x5DC */
  uint8_t RESERVED_244[3];
  uint8_t TRSV_REG078;                             /**< , offset: 0x5E0 */
  uint8_t RESERVED_245[3];
  uint8_t TRSV_REG079;                             /**< , offset: 0x5E4 */
  uint8_t RESERVED_246[3];
  uint8_t TRSV_REG07A;                             /**< , offset: 0x5E8 */
  uint8_t RESERVED_247[3];
  uint8_t TRSV_REG07B;                             /**< , offset: 0x5EC */
  uint8_t RESERVED_248[3];
  uint8_t TRSV_REG07C;                             /**< , offset: 0x5F0 */
  uint8_t RESERVED_249[3];
  uint8_t TRSV_REG07D;                             /**< , offset: 0x5F4 */
  uint8_t RESERVED_250[3];
  uint8_t TRSV_REG07E;                             /**< , offset: 0x5F8 */
  uint8_t RESERVED_251[3];
  uint8_t TRSV_REG07F;                             /**< , offset: 0x5FC */
  uint8_t RESERVED_252[3];
  uint8_t TRSV_REG080;                             /**< , offset: 0x600 */
  uint8_t RESERVED_253[3];
  uint8_t TRSV_REG081;                             /**< , offset: 0x604 */
  uint8_t RESERVED_254[3];
  uint8_t TRSV_REG082;                             /**< , offset: 0x608 */
  uint8_t RESERVED_255[3];
  uint8_t TRSV_REG083;                             /**< , offset: 0x60C */
  uint8_t RESERVED_256[3];
  uint8_t TRSV_REG084;                             /**< , offset: 0x610 */
  uint8_t RESERVED_257[3];
  uint8_t TRSV_REG085;                             /**< , offset: 0x614 */
  uint8_t RESERVED_258[3];
  uint8_t TRSV_REG086;                             /**< , offset: 0x618 */
  uint8_t RESERVED_259[3];
  uint8_t TRSV_REG087;                             /**< , offset: 0x61C */
  uint8_t RESERVED_260[3];
  uint8_t TRSV_REG088;                             /**< , offset: 0x620 */
  uint8_t RESERVED_261[3];
  uint8_t TRSV_REG089;                             /**< , offset: 0x624 */
  uint8_t RESERVED_262[3];
  uint8_t TRSV_REG08A;                             /**< , offset: 0x628 */
  uint8_t RESERVED_263[3];
  uint8_t TRSV_REG08B;                             /**< , offset: 0x62C */
  uint8_t RESERVED_264[3];
  uint8_t TRSV_REG08C;                             /**< , offset: 0x630 */
  uint8_t RESERVED_265[3];
  uint8_t TRSV_REG08D;                             /**< , offset: 0x634 */
  uint8_t RESERVED_266[3];
  uint8_t TRSV_REG08E;                             /**< , offset: 0x638 */
  uint8_t RESERVED_267[3];
  uint8_t TRSV_REG08F;                             /**< , offset: 0x63C */
  uint8_t RESERVED_268[3];
  uint8_t TRSV_REG090;                             /**< , offset: 0x640 */
  uint8_t RESERVED_269[3];
  uint8_t TRSV_REG091;                             /**< , offset: 0x644 */
  uint8_t RESERVED_270[3];
  uint8_t TRSV_REG092;                             /**< , offset: 0x648 */
  uint8_t RESERVED_271[3];
  uint8_t TRSV_REG093;                             /**< , offset: 0x64C */
  uint8_t RESERVED_272[3];
  uint8_t TRSV_REG094;                             /**< , offset: 0x650 */
  uint8_t RESERVED_273[3];
  uint8_t TRSV_REG095;                             /**< , offset: 0x654 */
  uint8_t RESERVED_274[3];
  uint8_t TRSV_REG096;                             /**< , offset: 0x658 */
  uint8_t RESERVED_275[3];
  uint8_t TRSV_REG097;                             /**< , offset: 0x65C */
  uint8_t RESERVED_276[3];
  uint8_t TRSV_REG098;                             /**< , offset: 0x660 */
  uint8_t RESERVED_277[3];
  uint8_t TRSV_REG099;                             /**< , offset: 0x664 */
  uint8_t RESERVED_278[3];
  uint8_t TRSV_REG09A;                             /**< , offset: 0x668 */
  uint8_t RESERVED_279[3];
  uint8_t TRSV_REG09B;                             /**< , offset: 0x66C */
  uint8_t RESERVED_280[3];
  uint8_t TRSV_REG09C;                             /**< , offset: 0x670 */
  uint8_t RESERVED_281[3];
  uint8_t TRSV_REG09D;                             /**< , offset: 0x674 */
  uint8_t RESERVED_282[3];
  uint8_t TRSV_REG09E;                             /**< , offset: 0x678 */
  uint8_t RESERVED_283[3];
  uint8_t TRSV_REG09F;                             /**< , offset: 0x67C */
  uint8_t RESERVED_284[3];
  uint8_t TRSV_REG0A0;                             /**< , offset: 0x680 */
  uint8_t RESERVED_285[3];
  uint8_t TRSV_REG0A1;                             /**< , offset: 0x684 */
  uint8_t RESERVED_286[3];
  uint8_t TRSV_REG0A2;                             /**< , offset: 0x688 */
  uint8_t RESERVED_287[3];
  uint8_t TRSV_REG0A3;                             /**< , offset: 0x68C */
  uint8_t RESERVED_288[3];
  uint8_t TRSV_REG0A4;                             /**< , offset: 0x690 */
  uint8_t RESERVED_289[3];
  uint8_t TRSV_REG0A5;                             /**< , offset: 0x694 */
  uint8_t RESERVED_290[3];
  uint8_t TRSV_REG0A6;                             /**< , offset: 0x698 */
  uint8_t RESERVED_291[3];
  uint8_t TRSV_REG0A7;                             /**< , offset: 0x69C */
  uint8_t RESERVED_292[3];
  uint8_t TRSV_REG0A8;                             /**< , offset: 0x6A0 */
  uint8_t RESERVED_293[3];
  uint8_t TRSV_REG0A9;                             /**< , offset: 0x6A4 */
  uint8_t RESERVED_294[3];
  uint8_t TRSV_REG0AA;                             /**< , offset: 0x6A8 */
  uint8_t RESERVED_295[3];
  uint8_t TRSV_REG0AB;                             /**< , offset: 0x6AC */
  uint8_t RESERVED_296[3];
  uint8_t TRSV_REG0AC;                             /**< , offset: 0x6B0 */
  uint8_t RESERVED_297[3];
  uint8_t TRSV_REG0AD;                             /**< , offset: 0x6B4 */
  uint8_t RESERVED_298[3];
  uint8_t TRSV_REG0AE;                             /**< , offset: 0x6B8 */
  uint8_t RESERVED_299[3];
  uint8_t TRSV_REG0AF;                             /**< , offset: 0x6BC */
  uint8_t RESERVED_300[3];
  uint8_t TRSV_REG0B0;                             /**< , offset: 0x6C0 */
  uint8_t RESERVED_301[3];
  uint8_t TRSV_REG0B1;                             /**< , offset: 0x6C4 */
  uint8_t RESERVED_302[3];
  uint8_t TRSV_REG0B2;                             /**< , offset: 0x6C8 */
  uint8_t RESERVED_303[3];
  uint8_t TRSV_REG0B3;                             /**< , offset: 0x6CC */
  uint8_t RESERVED_304[3];
  uint8_t TRSV_REG0B4;                             /**< , offset: 0x6D0 */
  uint8_t RESERVED_305[3];
  uint8_t TRSV_REG0B5;                             /**< , offset: 0x6D4 */
  uint8_t RESERVED_306[3];
  uint8_t TRSV_REG0B6;                             /**< , offset: 0x6D8 */
  uint8_t RESERVED_307[3];
  uint8_t TRSV_REG0B7;                             /**< , offset: 0x6DC */
  uint8_t RESERVED_308[3];
  uint8_t TRSV_REG0B8;                             /**< , offset: 0x6E0 */
  uint8_t RESERVED_309[3];
  uint8_t TRSV_REG0B9;                             /**< , offset: 0x6E4 */
  uint8_t RESERVED_310[3];
  uint8_t TRSV_REG0BA;                             /**< , offset: 0x6E8 */
  uint8_t RESERVED_311[3];
  uint8_t TRSV_REG0BB;                             /**< , offset: 0x6EC */
  uint8_t RESERVED_312[3];
  uint8_t TRSV_REG0BC;                             /**< , offset: 0x6F0 */
  uint8_t RESERVED_313[3];
  uint8_t TRSV_REG0BD;                             /**< , offset: 0x6F4 */
  uint8_t RESERVED_314[3];
  uint8_t TRSV_REG0BE;                             /**< , offset: 0x6F8 */
  uint8_t RESERVED_315[3];
  uint8_t TRSV_REG0BF;                             /**< , offset: 0x6FC */
  uint8_t RESERVED_316[3];
  uint8_t TRSV_REG0C0;                             /**< , offset: 0x700 */
  uint8_t RESERVED_317[3];
  uint8_t TRSV_REG0C1;                             /**< , offset: 0x704 */
  uint8_t RESERVED_318[3];
  uint8_t TRSV_REG0C2;                             /**< , offset: 0x708 */
  uint8_t RESERVED_319[3];
  uint8_t TRSV_REG0C3;                             /**< , offset: 0x70C */
  uint8_t RESERVED_320[3];
  uint8_t TRSV_REG0C4;                             /**< , offset: 0x710 */
  uint8_t RESERVED_321[3];
  uint8_t TRSV_REG0C5;                             /**< , offset: 0x714 */
  uint8_t RESERVED_322[3];
  uint8_t TRSV_REG0C6;                             /**< , offset: 0x718 */
  uint8_t RESERVED_323[3];
  uint8_t TRSV_REG0C7;                             /**< , offset: 0x71C */
  uint8_t RESERVED_324[3];
  uint8_t TRSV_REG0C8;                             /**< , offset: 0x720 */
  uint8_t RESERVED_325[3];
  uint8_t TRSV_REG0C9;                             /**< , offset: 0x724 */
  uint8_t RESERVED_326[3];
  uint8_t TRSV_REG0CA;                             /**< , offset: 0x728 */
  uint8_t RESERVED_327[3];
  uint8_t TRSV_REG0CB;                             /**< , offset: 0x72C */
  uint8_t RESERVED_328[3];
  uint8_t TRSV_REG0CC;                             /**< , offset: 0x730 */
  uint8_t RESERVED_329[3];
  uint8_t TRSV_REG0CD;                             /**< , offset: 0x734 */
  uint8_t RESERVED_330[3];
  uint8_t TRSV_REG0CE;                             /**< , offset: 0x738 */
  uint8_t RESERVED_331[3];
  uint8_t TRSV_REG0CF;                             /**< , offset: 0x73C */
  uint8_t RESERVED_332[3];
  uint8_t TRSV_REG0D0;                             /**< , offset: 0x740 */
  uint8_t RESERVED_333[3];
  uint8_t TRSV_REG0D1;                             /**< , offset: 0x744 */
  uint8_t RESERVED_334[3];
  uint8_t TRSV_REG0D2;                             /**< , offset: 0x748 */
  uint8_t RESERVED_335[3];
  uint8_t TRSV_REG0D3;                             /**< , offset: 0x74C */
  uint8_t RESERVED_336[3];
  uint8_t TRSV_REG0D4;                             /**< , offset: 0x750 */
  uint8_t RESERVED_337[3];
  uint8_t TRSV_REG0D5;                             /**< , offset: 0x754 */
  uint8_t RESERVED_338[3];
  uint8_t TRSV_REG0D6;                             /**< , offset: 0x758 */
  uint8_t RESERVED_339[3];
  uint8_t TRSV_REG0D7;                             /**< , offset: 0x75C */
  uint8_t RESERVED_340[3];
  uint8_t TRSV_REG0D8;                             /**< , offset: 0x760 */
  uint8_t RESERVED_341[3];
  uint8_t TRSV_REG0D9;                             /**< , offset: 0x764 */
  uint8_t RESERVED_342[3];
  uint8_t TRSV_REG0DA;                             /**< , offset: 0x768 */
  uint8_t RESERVED_343[3];
  uint8_t TRSV_REG0DB;                             /**< , offset: 0x76C */
  uint8_t RESERVED_344[3];
  uint8_t TRSV_REG0DC;                             /**< , offset: 0x770 */
  uint8_t RESERVED_345[3];
  uint8_t TRSV_REG0DD;                             /**< , offset: 0x774 */
  uint8_t RESERVED_346[3];
  uint8_t TRSV_REG0DE;                             /**< , offset: 0x778 */
  uint8_t RESERVED_347[3];
  uint8_t TRSV_REG0DF;                             /**< , offset: 0x77C */
  uint8_t RESERVED_348[3];
  uint8_t TRSV_REG0E0;                             /**< , offset: 0x780 */
  uint8_t RESERVED_349[3];
  uint8_t TRSV_REG0E1;                             /**< , offset: 0x784 */
  uint8_t RESERVED_350[3];
  uint8_t TRSV_REG0E2;                             /**< , offset: 0x788 */
  uint8_t RESERVED_351[3];
  uint8_t TRSV_REG0E3;                             /**< , offset: 0x78C */
  uint8_t RESERVED_352[3];
  uint8_t TRSV_REG0E4;                             /**< , offset: 0x790 */
  uint8_t RESERVED_353[3];
  uint8_t TRSV_REG0E5;                             /**< , offset: 0x794 */
  uint8_t RESERVED_354[3];
  uint8_t TRSV_REG0E6;                             /**< , offset: 0x798 */
  uint8_t RESERVED_355[3];
  uint8_t TRSV_REG0E7;                             /**< , offset: 0x79C */
  uint8_t RESERVED_356[3];
  uint8_t TRSV_REG0E8;                             /**< , offset: 0x7A0 */
  uint8_t RESERVED_357[3];
  uint8_t TRSV_REG0E9;                             /**< , offset: 0x7A4 */
  uint8_t RESERVED_358[3];
  uint8_t TRSV_REG0EA;                             /**< , offset: 0x7A8 */
  uint8_t RESERVED_359[3];
  uint8_t TRSV_REG0EB;                             /**< , offset: 0x7AC */
  uint8_t RESERVED_360[3];
  uint8_t TRSV_REG0EC;                             /**< , offset: 0x7B0 */
  uint8_t RESERVED_361[3];
  uint8_t TRSV_REG0ED;                             /**< , offset: 0x7B4 */
  uint8_t RESERVED_362[3];
  uint8_t TRSV_REG0EE;                             /**< , offset: 0x7B8 */
  uint8_t RESERVED_363[3];
  uint8_t TRSV_REG0EF;                             /**< , offset: 0x7BC */
  uint8_t RESERVED_364[3];
  uint8_t TRSV_REG0F0;                             /**< , offset: 0x7C0 */
  uint8_t RESERVED_365[3];
  uint8_t TRSV_REG0F1;                             /**< , offset: 0x7C4 */
  uint8_t RESERVED_366[3];
  uint8_t TRSV_REG0F2;                             /**< , offset: 0x7C8 */
  uint8_t RESERVED_367[3];
  uint8_t TRSV_REG0F3;                             /**< , offset: 0x7CC */
  uint8_t RESERVED_368[3];
  uint8_t TRSV_REG0F4;                             /**< , offset: 0x7D0 */
  uint8_t RESERVED_369[3];
  uint8_t TRSV_REG0F5;                             /**< , offset: 0x7D4 */
  uint8_t RESERVED_370[3];
  uint8_t TRSV_REG0F6;                             /**< , offset: 0x7D8 */
  uint8_t RESERVED_371[3];
  uint8_t TRSV_REG0F7;                             /**< , offset: 0x7DC */
  uint8_t RESERVED_372[3];
  uint8_t TRSV_REG0F8;                             /**< , offset: 0x7E0 */
  uint8_t RESERVED_373[3];
  uint8_t TRSV_REG0F9;                             /**< , offset: 0x7E4 */
  uint8_t RESERVED_374[3];
  uint8_t TRSV_REG0FA;                             /**< , offset: 0x7E8 */
  uint8_t RESERVED_375[3];
  uint8_t TRSV_REG0FB;                             /**< , offset: 0x7EC */
  uint8_t RESERVED_376[3];
  uint8_t TRSV_REG0FC;                             /**< , offset: 0x7F0 */
  uint8_t RESERVED_377[3];
  uint8_t TRSV_REG0FD;                             /**< , offset: 0x7F4 */
  uint8_t RESERVED_378[3];
  uint8_t TRSV_REG0FE;                             /**< , offset: 0x7F8 */
  uint8_t RESERVED_379[3];
  uint8_t TRSV_REG0FF;                             /**< , offset: 0x7FC */
} volatile *PCIE_PHY_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PCIE_PHY - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCIE_PHY_Register_Accessor_Macros PCIE_PHY - Register accessor macros
 * @{
 */

/* PCIE_PHY - Register accessors */
#define PCIE_PHY_CMN_REG000_REG(base)            ((base)->CMN_REG000)
#define PCIE_PHY_CMN_REG001_REG(base)            ((base)->CMN_REG001)
#define PCIE_PHY_CMN_REG002_REG(base)            ((base)->CMN_REG002)
#define PCIE_PHY_CMN_REG003_REG(base)            ((base)->CMN_REG003)
#define PCIE_PHY_CMN_REG004_REG(base)            ((base)->CMN_REG004)
#define PCIE_PHY_CMN_REG005_REG(base)            ((base)->CMN_REG005)
#define PCIE_PHY_CMN_REG006_REG(base)            ((base)->CMN_REG006)
#define PCIE_PHY_CMN_REG007_REG(base)            ((base)->CMN_REG007)
#define PCIE_PHY_CMN_REG008_REG(base)            ((base)->CMN_REG008)
#define PCIE_PHY_CMN_REG009_REG(base)            ((base)->CMN_REG009)
#define PCIE_PHY_CMN_REG00A_REG(base)            ((base)->CMN_REG00A)
#define PCIE_PHY_CMN_REG00B_REG(base)            ((base)->CMN_REG00B)
#define PCIE_PHY_CMN_REG00C_REG(base)            ((base)->CMN_REG00C)
#define PCIE_PHY_CMN_REG00D_REG(base)            ((base)->CMN_REG00D)
#define PCIE_PHY_CMN_REG00E_REG(base)            ((base)->CMN_REG00E)
#define PCIE_PHY_CMN_REG00F_REG(base)            ((base)->CMN_REG00F)
#define PCIE_PHY_CMN_REG010_REG(base)            ((base)->CMN_REG010)
#define PCIE_PHY_CMN_REG011_REG(base)            ((base)->CMN_REG011)
#define PCIE_PHY_CMN_REG012_REG(base)            ((base)->CMN_REG012)
#define PCIE_PHY_CMN_REG013_REG(base)            ((base)->CMN_REG013)
#define PCIE_PHY_CMN_REG014_REG(base)            ((base)->CMN_REG014)
#define PCIE_PHY_CMN_REG015_REG(base)            ((base)->CMN_REG015)
#define PCIE_PHY_CMN_REG016_REG(base)            ((base)->CMN_REG016)
#define PCIE_PHY_CMN_REG017_REG(base)            ((base)->CMN_REG017)
#define PCIE_PHY_CMN_REG018_REG(base)            ((base)->CMN_REG018)
#define PCIE_PHY_CMN_REG019_REG(base)            ((base)->CMN_REG019)
#define PCIE_PHY_CMN_REG01A_REG(base)            ((base)->CMN_REG01A)
#define PCIE_PHY_CMN_REG01B_REG(base)            ((base)->CMN_REG01B)
#define PCIE_PHY_CMN_REG01C_REG(base)            ((base)->CMN_REG01C)
#define PCIE_PHY_CMN_REG01D_REG(base)            ((base)->CMN_REG01D)
#define PCIE_PHY_CMN_REG01E_REG(base)            ((base)->CMN_REG01E)
#define PCIE_PHY_CMN_REG01F_REG(base)            ((base)->CMN_REG01F)
#define PCIE_PHY_CMN_REG020_REG(base)            ((base)->CMN_REG020)
#define PCIE_PHY_CMN_REG021_REG(base)            ((base)->CMN_REG021)
#define PCIE_PHY_CMN_REG022_REG(base)            ((base)->CMN_REG022)
#define PCIE_PHY_CMN_REG023_REG(base)            ((base)->CMN_REG023)
#define PCIE_PHY_CMN_REG024_REG(base)            ((base)->CMN_REG024)
#define PCIE_PHY_CMN_REG025_REG(base)            ((base)->CMN_REG025)
#define PCIE_PHY_CMN_REG026_REG(base)            ((base)->CMN_REG026)
#define PCIE_PHY_CMN_REG027_REG(base)            ((base)->CMN_REG027)
#define PCIE_PHY_CMN_REG028_REG(base)            ((base)->CMN_REG028)
#define PCIE_PHY_CMN_REG029_REG(base)            ((base)->CMN_REG029)
#define PCIE_PHY_CMN_REG02A_REG(base)            ((base)->CMN_REG02A)
#define PCIE_PHY_CMN_REG02B_REG(base)            ((base)->CMN_REG02B)
#define PCIE_PHY_CMN_REG02C_REG(base)            ((base)->CMN_REG02C)
#define PCIE_PHY_CMN_REG02D_REG(base)            ((base)->CMN_REG02D)
#define PCIE_PHY_CMN_REG02E_REG(base)            ((base)->CMN_REG02E)
#define PCIE_PHY_CMN_REG02F_REG(base)            ((base)->CMN_REG02F)
#define PCIE_PHY_CMN_REG030_REG(base)            ((base)->CMN_REG030)
#define PCIE_PHY_CMN_REG031_REG(base)            ((base)->CMN_REG031)
#define PCIE_PHY_CMN_REG032_REG(base)            ((base)->CMN_REG032)
#define PCIE_PHY_CMN_REG033_REG(base)            ((base)->CMN_REG033)
#define PCIE_PHY_CMN_REG034_REG(base)            ((base)->CMN_REG034)
#define PCIE_PHY_CMN_REG035_REG(base)            ((base)->CMN_REG035)
#define PCIE_PHY_CMN_REG036_REG(base)            ((base)->CMN_REG036)
#define PCIE_PHY_CMN_REG037_REG(base)            ((base)->CMN_REG037)
#define PCIE_PHY_CMN_REG038_REG(base)            ((base)->CMN_REG038)
#define PCIE_PHY_CMN_REG039_REG(base)            ((base)->CMN_REG039)
#define PCIE_PHY_CMN_REG03A_REG(base)            ((base)->CMN_REG03A)
#define PCIE_PHY_CMN_REG03B_REG(base)            ((base)->CMN_REG03B)
#define PCIE_PHY_CMN_REG03C_REG(base)            ((base)->CMN_REG03C)
#define PCIE_PHY_CMN_REG03D_REG(base)            ((base)->CMN_REG03D)
#define PCIE_PHY_CMN_REG03E_REG(base)            ((base)->CMN_REG03E)
#define PCIE_PHY_CMN_REG03F_REG(base)            ((base)->CMN_REG03F)
#define PCIE_PHY_CMN_REG040_REG(base)            ((base)->CMN_REG040)
#define PCIE_PHY_CMN_REG041_REG(base)            ((base)->CMN_REG041)
#define PCIE_PHY_CMN_REG042_REG(base)            ((base)->CMN_REG042)
#define PCIE_PHY_CMN_REG043_REG(base)            ((base)->CMN_REG043)
#define PCIE_PHY_CMN_REG044_REG(base)            ((base)->CMN_REG044)
#define PCIE_PHY_CMN_REG045_REG(base)            ((base)->CMN_REG045)
#define PCIE_PHY_CMN_REG046_REG(base)            ((base)->CMN_REG046)
#define PCIE_PHY_CMN_REG047_REG(base)            ((base)->CMN_REG047)
#define PCIE_PHY_CMN_REG048_REG(base)            ((base)->CMN_REG048)
#define PCIE_PHY_CMN_REG049_REG(base)            ((base)->CMN_REG049)
#define PCIE_PHY_CMN_REG04A_REG(base)            ((base)->CMN_REG04A)
#define PCIE_PHY_CMN_REG04B_REG(base)            ((base)->CMN_REG04B)
#define PCIE_PHY_CMN_REG04C_REG(base)            ((base)->CMN_REG04C)
#define PCIE_PHY_CMN_REG04D_REG(base)            ((base)->CMN_REG04D)
#define PCIE_PHY_CMN_REG04E_REG(base)            ((base)->CMN_REG04E)
#define PCIE_PHY_CMN_REG04F_REG(base)            ((base)->CMN_REG04F)
#define PCIE_PHY_CMN_REG050_REG(base)            ((base)->CMN_REG050)
#define PCIE_PHY_CMN_REG051_REG(base)            ((base)->CMN_REG051)
#define PCIE_PHY_CMN_REG052_REG(base)            ((base)->CMN_REG052)
#define PCIE_PHY_CMN_REG053_REG(base)            ((base)->CMN_REG053)
#define PCIE_PHY_CMN_REG054_REG(base)            ((base)->CMN_REG054)
#define PCIE_PHY_CMN_REG055_REG(base)            ((base)->CMN_REG055)
#define PCIE_PHY_CMN_REG056_REG(base)            ((base)->CMN_REG056)
#define PCIE_PHY_CMN_REG057_REG(base)            ((base)->CMN_REG057)
#define PCIE_PHY_CMN_REG058_REG(base)            ((base)->CMN_REG058)
#define PCIE_PHY_CMN_REG059_REG(base)            ((base)->CMN_REG059)
#define PCIE_PHY_CMN_REG05A_REG(base)            ((base)->CMN_REG05A)
#define PCIE_PHY_CMN_REG05B_REG(base)            ((base)->CMN_REG05B)
#define PCIE_PHY_CMN_REG05C_REG(base)            ((base)->CMN_REG05C)
#define PCIE_PHY_CMN_REG05D_REG(base)            ((base)->CMN_REG05D)
#define PCIE_PHY_CMN_REG05E_REG(base)            ((base)->CMN_REG05E)
#define PCIE_PHY_CMN_REG05F_REG(base)            ((base)->CMN_REG05F)
#define PCIE_PHY_CMN_REG060_REG(base)            ((base)->CMN_REG060)
#define PCIE_PHY_CMN_REG061_REG(base)            ((base)->CMN_REG061)
#define PCIE_PHY_CMN_REG062_REG(base)            ((base)->CMN_REG062)
#define PCIE_PHY_CMN_REG063_REG(base)            ((base)->CMN_REG063)
#define PCIE_PHY_CMN_REG064_REG(base)            ((base)->CMN_REG064)
#define PCIE_PHY_CMN_REG065_REG(base)            ((base)->CMN_REG065)
#define PCIE_PHY_CMN_REG066_REG(base)            ((base)->CMN_REG066)
#define PCIE_PHY_CMN_REG067_REG(base)            ((base)->CMN_REG067)
#define PCIE_PHY_CMN_REG068_REG(base)            ((base)->CMN_REG068)
#define PCIE_PHY_CMN_REG069_REG(base)            ((base)->CMN_REG069)
#define PCIE_PHY_CMN_REG06A_REG(base)            ((base)->CMN_REG06A)
#define PCIE_PHY_CMN_REG06B_REG(base)            ((base)->CMN_REG06B)
#define PCIE_PHY_CMN_REG06C_REG(base)            ((base)->CMN_REG06C)
#define PCIE_PHY_CMN_REG06D_REG(base)            ((base)->CMN_REG06D)
#define PCIE_PHY_CMN_REG06E_REG(base)            ((base)->CMN_REG06E)
#define PCIE_PHY_CMN_REG06F_REG(base)            ((base)->CMN_REG06F)
#define PCIE_PHY_CMN_REG070_REG(base)            ((base)->CMN_REG070)
#define PCIE_PHY_CMN_REG071_REG(base)            ((base)->CMN_REG071)
#define PCIE_PHY_CMN_REG072_REG(base)            ((base)->CMN_REG072)
#define PCIE_PHY_CMN_REG073_REG(base)            ((base)->CMN_REG073)
#define PCIE_PHY_CMN_REG074_REG(base)            ((base)->CMN_REG074)
#define PCIE_PHY_CMN_REG075_REG(base)            ((base)->CMN_REG075)
#define PCIE_PHY_CMN_REG076_REG(base)            ((base)->CMN_REG076)
#define PCIE_PHY_CMN_REG077_REG(base)            ((base)->CMN_REG077)
#define PCIE_PHY_CMN_REG078_REG(base)            ((base)->CMN_REG078)
#define PCIE_PHY_CMN_REG079_REG(base)            ((base)->CMN_REG079)
#define PCIE_PHY_CMN_REG080_REG(base)            ((base)->CMN_REG080)
#define PCIE_PHY_CMN_REG081_REG(base)            ((base)->CMN_REG081)
#define PCIE_PHY_CMN_REG082_REG(base)            ((base)->CMN_REG082)
#define PCIE_PHY_TRSV_REG000_REG(base)           ((base)->TRSV_REG000)
#define PCIE_PHY_TRSV_REG001_REG(base)           ((base)->TRSV_REG001)
#define PCIE_PHY_TRSV_REG002_REG(base)           ((base)->TRSV_REG002)
#define PCIE_PHY_TRSV_REG003_REG(base)           ((base)->TRSV_REG003)
#define PCIE_PHY_TRSV_REG004_REG(base)           ((base)->TRSV_REG004)
#define PCIE_PHY_TRSV_REG005_REG(base)           ((base)->TRSV_REG005)
#define PCIE_PHY_TRSV_REG006_REG(base)           ((base)->TRSV_REG006)
#define PCIE_PHY_TRSV_REG007_REG(base)           ((base)->TRSV_REG007)
#define PCIE_PHY_TRSV_REG008_REG(base)           ((base)->TRSV_REG008)
#define PCIE_PHY_TRSV_REG009_REG(base)           ((base)->TRSV_REG009)
#define PCIE_PHY_TRSV_REG00A_REG(base)           ((base)->TRSV_REG00A)
#define PCIE_PHY_TRSV_REG00B_REG(base)           ((base)->TRSV_REG00B)
#define PCIE_PHY_TRSV_REG00C_REG(base)           ((base)->TRSV_REG00C)
#define PCIE_PHY_TRSV_REG00D_REG(base)           ((base)->TRSV_REG00D)
#define PCIE_PHY_TRSV_REG00E_REG(base)           ((base)->TRSV_REG00E)
#define PCIE_PHY_TRSV_REG00F_REG(base)           ((base)->TRSV_REG00F)
#define PCIE_PHY_TRSV_REG010_REG(base)           ((base)->TRSV_REG010)
#define PCIE_PHY_TRSV_REG011_REG(base)           ((base)->TRSV_REG011)
#define PCIE_PHY_TRSV_REG012_REG(base)           ((base)->TRSV_REG012)
#define PCIE_PHY_TRSV_REG013_REG(base)           ((base)->TRSV_REG013)
#define PCIE_PHY_TRSV_REG014_REG(base)           ((base)->TRSV_REG014)
#define PCIE_PHY_TRSV_REG015_REG(base)           ((base)->TRSV_REG015)
#define PCIE_PHY_TRSV_REG016_REG(base)           ((base)->TRSV_REG016)
#define PCIE_PHY_TRSV_REG017_REG(base)           ((base)->TRSV_REG017)
#define PCIE_PHY_TRSV_REG018_REG(base)           ((base)->TRSV_REG018)
#define PCIE_PHY_TRSV_REG019_REG(base)           ((base)->TRSV_REG019)
#define PCIE_PHY_TRSV_REG01A_REG(base)           ((base)->TRSV_REG01A)
#define PCIE_PHY_TRSV_REG01B_REG(base)           ((base)->TRSV_REG01B)
#define PCIE_PHY_TRSV_REG01C_REG(base)           ((base)->TRSV_REG01C)
#define PCIE_PHY_TRSV_REG01D_REG(base)           ((base)->TRSV_REG01D)
#define PCIE_PHY_TRSV_REG01E_REG(base)           ((base)->TRSV_REG01E)
#define PCIE_PHY_TRSV_REG01F_REG(base)           ((base)->TRSV_REG01F)
#define PCIE_PHY_TRSV_REG020_REG(base)           ((base)->TRSV_REG020)
#define PCIE_PHY_TRSV_REG021_REG(base)           ((base)->TRSV_REG021)
#define PCIE_PHY_TRSV_REG022_REG(base)           ((base)->TRSV_REG022)
#define PCIE_PHY_TRSV_REG023_REG(base)           ((base)->TRSV_REG023)
#define PCIE_PHY_TRSV_REG024_REG(base)           ((base)->TRSV_REG024)
#define PCIE_PHY_TRSV_REG025_REG(base)           ((base)->TRSV_REG025)
#define PCIE_PHY_TRSV_REG026_REG(base)           ((base)->TRSV_REG026)
#define PCIE_PHY_TRSV_REG027_REG(base)           ((base)->TRSV_REG027)
#define PCIE_PHY_TRSV_REG028_REG(base)           ((base)->TRSV_REG028)
#define PCIE_PHY_TRSV_REG029_REG(base)           ((base)->TRSV_REG029)
#define PCIE_PHY_TRSV_REG02A_REG(base)           ((base)->TRSV_REG02A)
#define PCIE_PHY_TRSV_REG02B_REG(base)           ((base)->TRSV_REG02B)
#define PCIE_PHY_TRSV_REG02C_REG(base)           ((base)->TRSV_REG02C)
#define PCIE_PHY_TRSV_REG02D_REG(base)           ((base)->TRSV_REG02D)
#define PCIE_PHY_TRSV_REG02E_REG(base)           ((base)->TRSV_REG02E)
#define PCIE_PHY_TRSV_REG02F_REG(base)           ((base)->TRSV_REG02F)
#define PCIE_PHY_TRSV_REG030_REG(base)           ((base)->TRSV_REG030)
#define PCIE_PHY_TRSV_REG031_REG(base)           ((base)->TRSV_REG031)
#define PCIE_PHY_TRSV_REG032_REG(base)           ((base)->TRSV_REG032)
#define PCIE_PHY_TRSV_REG033_REG(base)           ((base)->TRSV_REG033)
#define PCIE_PHY_TRSV_REG034_REG(base)           ((base)->TRSV_REG034)
#define PCIE_PHY_TRSV_REG035_REG(base)           ((base)->TRSV_REG035)
#define PCIE_PHY_TRSV_REG036_REG(base)           ((base)->TRSV_REG036)
#define PCIE_PHY_TRSV_REG037_REG(base)           ((base)->TRSV_REG037)
#define PCIE_PHY_TRSV_REG038_REG(base)           ((base)->TRSV_REG038)
#define PCIE_PHY_TRSV_REG039_REG(base)           ((base)->TRSV_REG039)
#define PCIE_PHY_TRSV_REG03A_REG(base)           ((base)->TRSV_REG03A)
#define PCIE_PHY_TRSV_REG03B_REG(base)           ((base)->TRSV_REG03B)
#define PCIE_PHY_TRSV_REG03C_REG(base)           ((base)->TRSV_REG03C)
#define PCIE_PHY_TRSV_REG03D_REG(base)           ((base)->TRSV_REG03D)
#define PCIE_PHY_TRSV_REG03E_REG(base)           ((base)->TRSV_REG03E)
#define PCIE_PHY_TRSV_REG03F_REG(base)           ((base)->TRSV_REG03F)
#define PCIE_PHY_TRSV_REG040_REG(base)           ((base)->TRSV_REG040)
#define PCIE_PHY_TRSV_REG041_REG(base)           ((base)->TRSV_REG041)
#define PCIE_PHY_TRSV_REG042_REG(base)           ((base)->TRSV_REG042)
#define PCIE_PHY_TRSV_REG043_REG(base)           ((base)->TRSV_REG043)
#define PCIE_PHY_TRSV_REG044_REG(base)           ((base)->TRSV_REG044)
#define PCIE_PHY_TRSV_REG045_REG(base)           ((base)->TRSV_REG045)
#define PCIE_PHY_TRSV_REG046_REG(base)           ((base)->TRSV_REG046)
#define PCIE_PHY_TRSV_REG047_REG(base)           ((base)->TRSV_REG047)
#define PCIE_PHY_TRSV_REG048_REG(base)           ((base)->TRSV_REG048)
#define PCIE_PHY_TRSV_REG049_REG(base)           ((base)->TRSV_REG049)
#define PCIE_PHY_TRSV_REG04A_REG(base)           ((base)->TRSV_REG04A)
#define PCIE_PHY_TRSV_REG04B_REG(base)           ((base)->TRSV_REG04B)
#define PCIE_PHY_TRSV_REG04C_REG(base)           ((base)->TRSV_REG04C)
#define PCIE_PHY_TRSV_REG04D_REG(base)           ((base)->TRSV_REG04D)
#define PCIE_PHY_TRSV_REG04E_REG(base)           ((base)->TRSV_REG04E)
#define PCIE_PHY_TRSV_REG04F_REG(base)           ((base)->TRSV_REG04F)
#define PCIE_PHY_TRSV_REG050_REG(base)           ((base)->TRSV_REG050)
#define PCIE_PHY_TRSV_REG051_REG(base)           ((base)->TRSV_REG051)
#define PCIE_PHY_TRSV_REG052_REG(base)           ((base)->TRSV_REG052)
#define PCIE_PHY_TRSV_REG053_REG(base)           ((base)->TRSV_REG053)
#define PCIE_PHY_TRSV_REG054_REG(base)           ((base)->TRSV_REG054)
#define PCIE_PHY_TRSV_REG055_REG(base)           ((base)->TRSV_REG055)
#define PCIE_PHY_TRSV_REG056_REG(base)           ((base)->TRSV_REG056)
#define PCIE_PHY_TRSV_REG057_REG(base)           ((base)->TRSV_REG057)
#define PCIE_PHY_TRSV_REG058_REG(base)           ((base)->TRSV_REG058)
#define PCIE_PHY_TRSV_REG059_REG(base)           ((base)->TRSV_REG059)
#define PCIE_PHY_TRSV_REG05A_REG(base)           ((base)->TRSV_REG05A)
#define PCIE_PHY_TRSV_REG05B_REG(base)           ((base)->TRSV_REG05B)
#define PCIE_PHY_TRSV_REG05C_REG(base)           ((base)->TRSV_REG05C)
#define PCIE_PHY_TRSV_REG05D_REG(base)           ((base)->TRSV_REG05D)
#define PCIE_PHY_TRSV_REG05E_REG(base)           ((base)->TRSV_REG05E)
#define PCIE_PHY_TRSV_REG05F_REG(base)           ((base)->TRSV_REG05F)
#define PCIE_PHY_TRSV_REG060_REG(base)           ((base)->TRSV_REG060)
#define PCIE_PHY_TRSV_REG061_REG(base)           ((base)->TRSV_REG061)
#define PCIE_PHY_TRSV_REG062_REG(base)           ((base)->TRSV_REG062)
#define PCIE_PHY_TRSV_REG063_REG(base)           ((base)->TRSV_REG063)
#define PCIE_PHY_TRSV_REG064_REG(base)           ((base)->TRSV_REG064)
#define PCIE_PHY_TRSV_REG065_REG(base)           ((base)->TRSV_REG065)
#define PCIE_PHY_TRSV_REG066_REG(base)           ((base)->TRSV_REG066)
#define PCIE_PHY_TRSV_REG067_REG(base)           ((base)->TRSV_REG067)
#define PCIE_PHY_TRSV_REG068_REG(base)           ((base)->TRSV_REG068)
#define PCIE_PHY_TRSV_REG069_REG(base)           ((base)->TRSV_REG069)
#define PCIE_PHY_TRSV_REG06A_REG(base)           ((base)->TRSV_REG06A)
#define PCIE_PHY_TRSV_REG06B_REG(base)           ((base)->TRSV_REG06B)
#define PCIE_PHY_TRSV_REG06C_REG(base)           ((base)->TRSV_REG06C)
#define PCIE_PHY_TRSV_REG06D_REG(base)           ((base)->TRSV_REG06D)
#define PCIE_PHY_TRSV_REG06E_REG(base)           ((base)->TRSV_REG06E)
#define PCIE_PHY_TRSV_REG06F_REG(base)           ((base)->TRSV_REG06F)
#define PCIE_PHY_TRSV_REG070_REG(base)           ((base)->TRSV_REG070)
#define PCIE_PHY_TRSV_REG071_REG(base)           ((base)->TRSV_REG071)
#define PCIE_PHY_TRSV_REG072_REG(base)           ((base)->TRSV_REG072)
#define PCIE_PHY_TRSV_REG073_REG(base)           ((base)->TRSV_REG073)
#define PCIE_PHY_TRSV_REG074_REG(base)           ((base)->TRSV_REG074)
#define PCIE_PHY_TRSV_REG075_REG(base)           ((base)->TRSV_REG075)
#define PCIE_PHY_TRSV_REG076_REG(base)           ((base)->TRSV_REG076)
#define PCIE_PHY_TRSV_REG077_REG(base)           ((base)->TRSV_REG077)
#define PCIE_PHY_TRSV_REG078_REG(base)           ((base)->TRSV_REG078)
#define PCIE_PHY_TRSV_REG079_REG(base)           ((base)->TRSV_REG079)
#define PCIE_PHY_TRSV_REG07A_REG(base)           ((base)->TRSV_REG07A)
#define PCIE_PHY_TRSV_REG07B_REG(base)           ((base)->TRSV_REG07B)
#define PCIE_PHY_TRSV_REG07C_REG(base)           ((base)->TRSV_REG07C)
#define PCIE_PHY_TRSV_REG07D_REG(base)           ((base)->TRSV_REG07D)
#define PCIE_PHY_TRSV_REG07E_REG(base)           ((base)->TRSV_REG07E)
#define PCIE_PHY_TRSV_REG07F_REG(base)           ((base)->TRSV_REG07F)
#define PCIE_PHY_TRSV_REG080_REG(base)           ((base)->TRSV_REG080)
#define PCIE_PHY_TRSV_REG081_REG(base)           ((base)->TRSV_REG081)
#define PCIE_PHY_TRSV_REG082_REG(base)           ((base)->TRSV_REG082)
#define PCIE_PHY_TRSV_REG083_REG(base)           ((base)->TRSV_REG083)
#define PCIE_PHY_TRSV_REG084_REG(base)           ((base)->TRSV_REG084)
#define PCIE_PHY_TRSV_REG085_REG(base)           ((base)->TRSV_REG085)
#define PCIE_PHY_TRSV_REG086_REG(base)           ((base)->TRSV_REG086)
#define PCIE_PHY_TRSV_REG087_REG(base)           ((base)->TRSV_REG087)
#define PCIE_PHY_TRSV_REG088_REG(base)           ((base)->TRSV_REG088)
#define PCIE_PHY_TRSV_REG089_REG(base)           ((base)->TRSV_REG089)
#define PCIE_PHY_TRSV_REG08A_REG(base)           ((base)->TRSV_REG08A)
#define PCIE_PHY_TRSV_REG08B_REG(base)           ((base)->TRSV_REG08B)
#define PCIE_PHY_TRSV_REG08C_REG(base)           ((base)->TRSV_REG08C)
#define PCIE_PHY_TRSV_REG08D_REG(base)           ((base)->TRSV_REG08D)
#define PCIE_PHY_TRSV_REG08E_REG(base)           ((base)->TRSV_REG08E)
#define PCIE_PHY_TRSV_REG08F_REG(base)           ((base)->TRSV_REG08F)
#define PCIE_PHY_TRSV_REG090_REG(base)           ((base)->TRSV_REG090)
#define PCIE_PHY_TRSV_REG091_REG(base)           ((base)->TRSV_REG091)
#define PCIE_PHY_TRSV_REG092_REG(base)           ((base)->TRSV_REG092)
#define PCIE_PHY_TRSV_REG093_REG(base)           ((base)->TRSV_REG093)
#define PCIE_PHY_TRSV_REG094_REG(base)           ((base)->TRSV_REG094)
#define PCIE_PHY_TRSV_REG095_REG(base)           ((base)->TRSV_REG095)
#define PCIE_PHY_TRSV_REG096_REG(base)           ((base)->TRSV_REG096)
#define PCIE_PHY_TRSV_REG097_REG(base)           ((base)->TRSV_REG097)
#define PCIE_PHY_TRSV_REG098_REG(base)           ((base)->TRSV_REG098)
#define PCIE_PHY_TRSV_REG099_REG(base)           ((base)->TRSV_REG099)
#define PCIE_PHY_TRSV_REG09A_REG(base)           ((base)->TRSV_REG09A)
#define PCIE_PHY_TRSV_REG09B_REG(base)           ((base)->TRSV_REG09B)
#define PCIE_PHY_TRSV_REG09C_REG(base)           ((base)->TRSV_REG09C)
#define PCIE_PHY_TRSV_REG09D_REG(base)           ((base)->TRSV_REG09D)
#define PCIE_PHY_TRSV_REG09E_REG(base)           ((base)->TRSV_REG09E)
#define PCIE_PHY_TRSV_REG09F_REG(base)           ((base)->TRSV_REG09F)
#define PCIE_PHY_TRSV_REG0A0_REG(base)           ((base)->TRSV_REG0A0)
#define PCIE_PHY_TRSV_REG0A1_REG(base)           ((base)->TRSV_REG0A1)
#define PCIE_PHY_TRSV_REG0A2_REG(base)           ((base)->TRSV_REG0A2)
#define PCIE_PHY_TRSV_REG0A3_REG(base)           ((base)->TRSV_REG0A3)
#define PCIE_PHY_TRSV_REG0A4_REG(base)           ((base)->TRSV_REG0A4)
#define PCIE_PHY_TRSV_REG0A5_REG(base)           ((base)->TRSV_REG0A5)
#define PCIE_PHY_TRSV_REG0A6_REG(base)           ((base)->TRSV_REG0A6)
#define PCIE_PHY_TRSV_REG0A7_REG(base)           ((base)->TRSV_REG0A7)
#define PCIE_PHY_TRSV_REG0A8_REG(base)           ((base)->TRSV_REG0A8)
#define PCIE_PHY_TRSV_REG0A9_REG(base)           ((base)->TRSV_REG0A9)
#define PCIE_PHY_TRSV_REG0AA_REG(base)           ((base)->TRSV_REG0AA)
#define PCIE_PHY_TRSV_REG0AB_REG(base)           ((base)->TRSV_REG0AB)
#define PCIE_PHY_TRSV_REG0AC_REG(base)           ((base)->TRSV_REG0AC)
#define PCIE_PHY_TRSV_REG0AD_REG(base)           ((base)->TRSV_REG0AD)
#define PCIE_PHY_TRSV_REG0AE_REG(base)           ((base)->TRSV_REG0AE)
#define PCIE_PHY_TRSV_REG0AF_REG(base)           ((base)->TRSV_REG0AF)
#define PCIE_PHY_TRSV_REG0B0_REG(base)           ((base)->TRSV_REG0B0)
#define PCIE_PHY_TRSV_REG0B1_REG(base)           ((base)->TRSV_REG0B1)
#define PCIE_PHY_TRSV_REG0B2_REG(base)           ((base)->TRSV_REG0B2)
#define PCIE_PHY_TRSV_REG0B3_REG(base)           ((base)->TRSV_REG0B3)
#define PCIE_PHY_TRSV_REG0B4_REG(base)           ((base)->TRSV_REG0B4)
#define PCIE_PHY_TRSV_REG0B5_REG(base)           ((base)->TRSV_REG0B5)
#define PCIE_PHY_TRSV_REG0B6_REG(base)           ((base)->TRSV_REG0B6)
#define PCIE_PHY_TRSV_REG0B7_REG(base)           ((base)->TRSV_REG0B7)
#define PCIE_PHY_TRSV_REG0B8_REG(base)           ((base)->TRSV_REG0B8)
#define PCIE_PHY_TRSV_REG0B9_REG(base)           ((base)->TRSV_REG0B9)
#define PCIE_PHY_TRSV_REG0BA_REG(base)           ((base)->TRSV_REG0BA)
#define PCIE_PHY_TRSV_REG0BB_REG(base)           ((base)->TRSV_REG0BB)
#define PCIE_PHY_TRSV_REG0BC_REG(base)           ((base)->TRSV_REG0BC)
#define PCIE_PHY_TRSV_REG0BD_REG(base)           ((base)->TRSV_REG0BD)
#define PCIE_PHY_TRSV_REG0BE_REG(base)           ((base)->TRSV_REG0BE)
#define PCIE_PHY_TRSV_REG0BF_REG(base)           ((base)->TRSV_REG0BF)
#define PCIE_PHY_TRSV_REG0C0_REG(base)           ((base)->TRSV_REG0C0)
#define PCIE_PHY_TRSV_REG0C1_REG(base)           ((base)->TRSV_REG0C1)
#define PCIE_PHY_TRSV_REG0C2_REG(base)           ((base)->TRSV_REG0C2)
#define PCIE_PHY_TRSV_REG0C3_REG(base)           ((base)->TRSV_REG0C3)
#define PCIE_PHY_TRSV_REG0C4_REG(base)           ((base)->TRSV_REG0C4)
#define PCIE_PHY_TRSV_REG0C5_REG(base)           ((base)->TRSV_REG0C5)
#define PCIE_PHY_TRSV_REG0C6_REG(base)           ((base)->TRSV_REG0C6)
#define PCIE_PHY_TRSV_REG0C7_REG(base)           ((base)->TRSV_REG0C7)
#define PCIE_PHY_TRSV_REG0C8_REG(base)           ((base)->TRSV_REG0C8)
#define PCIE_PHY_TRSV_REG0C9_REG(base)           ((base)->TRSV_REG0C9)
#define PCIE_PHY_TRSV_REG0CA_REG(base)           ((base)->TRSV_REG0CA)
#define PCIE_PHY_TRSV_REG0CB_REG(base)           ((base)->TRSV_REG0CB)
#define PCIE_PHY_TRSV_REG0CC_REG(base)           ((base)->TRSV_REG0CC)
#define PCIE_PHY_TRSV_REG0CD_REG(base)           ((base)->TRSV_REG0CD)
#define PCIE_PHY_TRSV_REG0CE_REG(base)           ((base)->TRSV_REG0CE)
#define PCIE_PHY_TRSV_REG0CF_REG(base)           ((base)->TRSV_REG0CF)
#define PCIE_PHY_TRSV_REG0D0_REG(base)           ((base)->TRSV_REG0D0)
#define PCIE_PHY_TRSV_REG0D1_REG(base)           ((base)->TRSV_REG0D1)
#define PCIE_PHY_TRSV_REG0D2_REG(base)           ((base)->TRSV_REG0D2)
#define PCIE_PHY_TRSV_REG0D3_REG(base)           ((base)->TRSV_REG0D3)
#define PCIE_PHY_TRSV_REG0D4_REG(base)           ((base)->TRSV_REG0D4)
#define PCIE_PHY_TRSV_REG0D5_REG(base)           ((base)->TRSV_REG0D5)
#define PCIE_PHY_TRSV_REG0D6_REG(base)           ((base)->TRSV_REG0D6)
#define PCIE_PHY_TRSV_REG0D7_REG(base)           ((base)->TRSV_REG0D7)
#define PCIE_PHY_TRSV_REG0D8_REG(base)           ((base)->TRSV_REG0D8)
#define PCIE_PHY_TRSV_REG0D9_REG(base)           ((base)->TRSV_REG0D9)
#define PCIE_PHY_TRSV_REG0DA_REG(base)           ((base)->TRSV_REG0DA)
#define PCIE_PHY_TRSV_REG0DB_REG(base)           ((base)->TRSV_REG0DB)
#define PCIE_PHY_TRSV_REG0DC_REG(base)           ((base)->TRSV_REG0DC)
#define PCIE_PHY_TRSV_REG0DD_REG(base)           ((base)->TRSV_REG0DD)
#define PCIE_PHY_TRSV_REG0DE_REG(base)           ((base)->TRSV_REG0DE)
#define PCIE_PHY_TRSV_REG0DF_REG(base)           ((base)->TRSV_REG0DF)
#define PCIE_PHY_TRSV_REG0E0_REG(base)           ((base)->TRSV_REG0E0)
#define PCIE_PHY_TRSV_REG0E1_REG(base)           ((base)->TRSV_REG0E1)
#define PCIE_PHY_TRSV_REG0E2_REG(base)           ((base)->TRSV_REG0E2)
#define PCIE_PHY_TRSV_REG0E3_REG(base)           ((base)->TRSV_REG0E3)
#define PCIE_PHY_TRSV_REG0E4_REG(base)           ((base)->TRSV_REG0E4)
#define PCIE_PHY_TRSV_REG0E5_REG(base)           ((base)->TRSV_REG0E5)
#define PCIE_PHY_TRSV_REG0E6_REG(base)           ((base)->TRSV_REG0E6)
#define PCIE_PHY_TRSV_REG0E7_REG(base)           ((base)->TRSV_REG0E7)
#define PCIE_PHY_TRSV_REG0E8_REG(base)           ((base)->TRSV_REG0E8)
#define PCIE_PHY_TRSV_REG0E9_REG(base)           ((base)->TRSV_REG0E9)
#define PCIE_PHY_TRSV_REG0EA_REG(base)           ((base)->TRSV_REG0EA)
#define PCIE_PHY_TRSV_REG0EB_REG(base)           ((base)->TRSV_REG0EB)
#define PCIE_PHY_TRSV_REG0EC_REG(base)           ((base)->TRSV_REG0EC)
#define PCIE_PHY_TRSV_REG0ED_REG(base)           ((base)->TRSV_REG0ED)
#define PCIE_PHY_TRSV_REG0EE_REG(base)           ((base)->TRSV_REG0EE)
#define PCIE_PHY_TRSV_REG0EF_REG(base)           ((base)->TRSV_REG0EF)
#define PCIE_PHY_TRSV_REG0F0_REG(base)           ((base)->TRSV_REG0F0)
#define PCIE_PHY_TRSV_REG0F1_REG(base)           ((base)->TRSV_REG0F1)
#define PCIE_PHY_TRSV_REG0F2_REG(base)           ((base)->TRSV_REG0F2)
#define PCIE_PHY_TRSV_REG0F3_REG(base)           ((base)->TRSV_REG0F3)
#define PCIE_PHY_TRSV_REG0F4_REG(base)           ((base)->TRSV_REG0F4)
#define PCIE_PHY_TRSV_REG0F5_REG(base)           ((base)->TRSV_REG0F5)
#define PCIE_PHY_TRSV_REG0F6_REG(base)           ((base)->TRSV_REG0F6)
#define PCIE_PHY_TRSV_REG0F7_REG(base)           ((base)->TRSV_REG0F7)
#define PCIE_PHY_TRSV_REG0F8_REG(base)           ((base)->TRSV_REG0F8)
#define PCIE_PHY_TRSV_REG0F9_REG(base)           ((base)->TRSV_REG0F9)
#define PCIE_PHY_TRSV_REG0FA_REG(base)           ((base)->TRSV_REG0FA)
#define PCIE_PHY_TRSV_REG0FB_REG(base)           ((base)->TRSV_REG0FB)
#define PCIE_PHY_TRSV_REG0FC_REG(base)           ((base)->TRSV_REG0FC)
#define PCIE_PHY_TRSV_REG0FD_REG(base)           ((base)->TRSV_REG0FD)
#define PCIE_PHY_TRSV_REG0FE_REG(base)           ((base)->TRSV_REG0FE)
#define PCIE_PHY_TRSV_REG0FF_REG(base)           ((base)->TRSV_REG0FF)
/*!
 * @}
 */ /* end of group PCIE_PHY_Register_Accessor_Macros */
/* ----------------------------------------------------------------------------
   -- PCIE_PHY Register Masks
   ---------------------------------------------------------------------------- */
/*!
 * @addtogroup PCIE_PHY_Register_Masks PCIE_PHY Register Masks
 * @{
 */
/*! @name CMN_REG000 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG000_BGR_LPF_BYPASS_MASK  (0x1U)
#define PCIE_PHY_CMN_REG000_BGR_LPF_BYPASS_SHIFT (0U)
#define PCIE_PHY_CMN_REG000_OVRD_BGR_LPF_BYPASS_MASK (0x2U)
#define PCIE_PHY_CMN_REG000_OVRD_BGR_LPF_BYPASS_SHIFT (1U)
#define PCIE_PHY_CMN_REG000_BGR_EN_MASK          (0x4U)
#define PCIE_PHY_CMN_REG000_BGR_EN_SHIFT         (2U)
#define PCIE_PHY_CMN_REG000_OVRD_BGR_EN_MASK     (0x8U)
#define PCIE_PHY_CMN_REG000_OVRD_BGR_EN_SHIFT    (3U)
/*! @} */
/*! @name CMN_REG001 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG001_ANA_BGR_LADDER_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG001_ANA_BGR_LADDER_EN_SHIFT (0U)
#define PCIE_PHY_CMN_REG001_ANA_BGR_CLK_EN_MASK  (0x2U)
#define PCIE_PHY_CMN_REG001_ANA_BGR_CLK_EN_SHIFT (1U)
#define PCIE_PHY_CMN_REG001_ANA_BGR_820M_SEL_MASK (0x7CU)
#define PCIE_PHY_CMN_REG001_ANA_BGR_820M_SEL_SHIFT (2U)
#define PCIE_PHY_CMN_REG001_ANA_BGR_820M_SEL(x)  (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG001_ANA_BGR_820M_SEL_SHIFT)) & PCIE_PHY_CMN_REG001_ANA_BGR_820M_SEL_MASK)
/*! @} */
/*! @name CMN_REG002 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG002_BIAS_RCAL_EN_MASK    (0x1U)
#define PCIE_PHY_CMN_REG002_BIAS_RCAL_EN_SHIFT   (0U)
#define PCIE_PHY_CMN_REG002_OVRD_BIAS_RCAL_EN_MASK (0x2U)
#define PCIE_PHY_CMN_REG002_OVRD_BIAS_RCAL_EN_SHIFT (1U)
#define PCIE_PHY_CMN_REG002_BIAS_EN_MASK         (0x4U)
#define PCIE_PHY_CMN_REG002_BIAS_EN_SHIFT        (2U)
#define PCIE_PHY_CMN_REG002_OVRD_BIAS_EN_MASK    (0x8U)
#define PCIE_PHY_CMN_REG002_OVRD_BIAS_EN_SHIFT   (3U)
#define PCIE_PHY_CMN_REG002_ANA_BGR_ATB_SEL_MASK (0x10U)
#define PCIE_PHY_CMN_REG002_ANA_BGR_ATB_SEL_SHIFT (4U)
#define PCIE_PHY_CMN_REG002_ANA_BGR_LADDER_SEL_MASK (0xE0U)
#define PCIE_PHY_CMN_REG002_ANA_BGR_LADDER_SEL_SHIFT (5U)
#define PCIE_PHY_CMN_REG002_ANA_BGR_LADDER_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG002_ANA_BGR_LADDER_SEL_SHIFT)) & PCIE_PHY_CMN_REG002_ANA_BGR_LADDER_SEL_MASK)
/*! @} */
/*! @name CMN_REG003 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG003_ANA_BIAS_TX_RCAL_IREXT_CTRL_MASK (0x3U)
#define PCIE_PHY_CMN_REG003_ANA_BIAS_TX_RCAL_IREXT_CTRL_SHIFT (0U)
#define PCIE_PHY_CMN_REG003_ANA_BIAS_TX_RCAL_IREXT_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG003_ANA_BIAS_TX_RCAL_IREXT_CTRL_SHIFT)) & PCIE_PHY_CMN_REG003_ANA_BIAS_TX_RCAL_IREXT_CTRL_MASK)
#define PCIE_PHY_CMN_REG003_ANA_BIAS_RX_RCAL_IREXT_CTRL_MASK (0xCU)
#define PCIE_PHY_CMN_REG003_ANA_BIAS_RX_RCAL_IREXT_CTRL_SHIFT (2U)
#define PCIE_PHY_CMN_REG003_ANA_BIAS_RX_RCAL_IREXT_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG003_ANA_BIAS_RX_RCAL_IREXT_CTRL_SHIFT)) & PCIE_PHY_CMN_REG003_ANA_BIAS_RX_RCAL_IREXT_CTRL_MASK)
#define PCIE_PHY_CMN_REG003_ANA_BIAS_IREXT_CTRL_MASK (0x30U)
#define PCIE_PHY_CMN_REG003_ANA_BIAS_IREXT_CTRL_SHIFT (4U)
#define PCIE_PHY_CMN_REG003_ANA_BIAS_IREXT_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG003_ANA_BIAS_IREXT_CTRL_SHIFT)) & PCIE_PHY_CMN_REG003_ANA_BIAS_IREXT_CTRL_MASK)
/*! @} */
/*! @name CMN_REG004 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG004_PLL_EN_MASK          (0x1U)
#define PCIE_PHY_CMN_REG004_PLL_EN_SHIFT         (0U)
#define PCIE_PHY_CMN_REG004_OVRD_PLL_EN_MASK     (0x2U)
#define PCIE_PHY_CMN_REG004_OVRD_PLL_EN_SHIFT    (1U)
/*! @} */
/*! @name CMN_REG005 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG005_PLL_AFC_RSTN_MASK    (0x1U)
#define PCIE_PHY_CMN_REG005_PLL_AFC_RSTN_SHIFT   (0U)
#define PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_RSTN_MASK (0x2U)
#define PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_RSTN_SHIFT (1U)
#define PCIE_PHY_CMN_REG005_PLL_AFC_INIT_RSTN_MASK (0x4U)
#define PCIE_PHY_CMN_REG005_PLL_AFC_INIT_RSTN_SHIFT (2U)
#define PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_INIT_RSTN_MASK (0x8U)
#define PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_INIT_RSTN_SHIFT (3U)
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G4_MASK (0x10U)
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G4_SHIFT (4U)
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G3_MASK (0x20U)
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G3_SHIFT (5U)
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G2_MASK (0x40U)
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G2_SHIFT (6U)
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G1_MASK (0x80U)
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G1_SHIFT (7U)
/*! @} */
/*! @name CMN_REG006 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_MAN_LC_CODE_SEL_MASK (0x3U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_MAN_LC_CODE_SEL_SHIFT (0U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_MAN_LC_CODE_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG006_ANA_PLL_AFC_MAN_LC_CODE_SEL_SHIFT)) & PCIE_PHY_CMN_REG006_ANA_PLL_AFC_MAN_LC_CODE_SEL_MASK)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_FROM_PRE_CODE_MASK (0x4U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_FROM_PRE_CODE_SHIFT (2U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_EN_MASK  (0x8U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_EN_SHIFT (3U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CODE_FORCE_MASK (0x10U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CODE_FORCE_SHIFT (4U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CLK_DIV2_EN_MASK (0x20U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CLK_DIV2_EN_SHIFT (5U)
/*! @} */
/*! @name CMN_REG007 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG007_ANA_PLL_AFC_STB_NUM_MASK (0xFU)
#define PCIE_PHY_CMN_REG007_ANA_PLL_AFC_STB_NUM_SHIFT (0U)
#define PCIE_PHY_CMN_REG007_ANA_PLL_AFC_STB_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG007_ANA_PLL_AFC_STB_NUM_SHIFT)) & PCIE_PHY_CMN_REG007_ANA_PLL_AFC_STB_NUM_MASK)
#define PCIE_PHY_CMN_REG007_ANA_PLL_AFC_MAN_RING_CODE_SEL_MASK (0xF0U)
#define PCIE_PHY_CMN_REG007_ANA_PLL_AFC_MAN_RING_CODE_SEL_SHIFT (4U)
#define PCIE_PHY_CMN_REG007_ANA_PLL_AFC_MAN_RING_CODE_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG007_ANA_PLL_AFC_MAN_RING_CODE_SEL_SHIFT)) & PCIE_PHY_CMN_REG007_ANA_PLL_AFC_MAN_RING_CODE_SEL_MASK)
/*! @} */
/*! @name CMN_REG008 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG008_ANA_PLL_AFC_VCI_FORCE_MASK (0x1U)
#define PCIE_PHY_CMN_REG008_ANA_PLL_AFC_VCI_FORCE_SHIFT (0U)
#define PCIE_PHY_CMN_REG008_ANA_PLL_AFC_TOL_NUM_MASK (0x1EU)
#define PCIE_PHY_CMN_REG008_ANA_PLL_AFC_TOL_NUM_SHIFT (1U)
#define PCIE_PHY_CMN_REG008_ANA_PLL_AFC_TOL_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG008_ANA_PLL_AFC_TOL_NUM_SHIFT)) & PCIE_PHY_CMN_REG008_ANA_PLL_AFC_TOL_NUM_MASK)
/*! @} */
/*! @name CMN_REG009 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_WAIT_NUM_MASK (0x7U)
#define PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_WAIT_NUM_SHIFT (0U)
#define PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_WAIT_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_WAIT_NUM_SHIFT)) & PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_WAIT_NUM_MASK)
#define PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_RUN_NUM_MASK (0xF8U)
#define PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_RUN_NUM_SHIFT (3U)
#define PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_RUN_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_RUN_NUM_SHIFT)) & PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_RUN_NUM_MASK)
/*! @} */
/*! @name CMN_REG00A -  */
/*! @{ */
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_MAN_GM_SEL_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_MAN_GM_SEL_EN_SHIFT (0U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_GM_ADD_MASK (0x6U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_GM_ADD_SHIFT (1U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_GM_ADD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_GM_ADD_SHIFT)) & PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_GM_ADD_MASK)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_FROM_MAX_GM_MASK (0x8U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_FROM_MAX_GM_SHIFT (3U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_COMP_EN_MASK (0x10U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_COMP_EN_SHIFT (4U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AFC_VCO_START_CRITERION_MASK (0xE0U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AFC_VCO_START_CRITERION_SHIFT (5U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AFC_VCO_START_CRITERION(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00A_ANA_PLL_AFC_VCO_START_CRITERION_SHIFT)) & PCIE_PHY_CMN_REG00A_ANA_PLL_AFC_VCO_START_CRITERION_MASK)
/*! @} */
/*! @name CMN_REG00B -  */
/*! @{ */
#define PCIE_PHY_CMN_REG00B_ANA_PLL_AGMC_MAN_GM_SEL_MASK (0xFU)
#define PCIE_PHY_CMN_REG00B_ANA_PLL_AGMC_MAN_GM_SEL_SHIFT (0U)
#define PCIE_PHY_CMN_REG00B_ANA_PLL_AGMC_MAN_GM_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00B_ANA_PLL_AGMC_MAN_GM_SEL_SHIFT)) & PCIE_PHY_CMN_REG00B_ANA_PLL_AGMC_MAN_GM_SEL_MASK)
/*! @} */
/*! @name CMN_REG00C -  */
/*! @{ */
#define PCIE_PHY_CMN_REG00C_PLL_AGMC_TG_CODE_G1_MASK (0xFFU)
#define PCIE_PHY_CMN_REG00C_PLL_AGMC_TG_CODE_G1_SHIFT (0U)
#define PCIE_PHY_CMN_REG00C_PLL_AGMC_TG_CODE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00C_PLL_AGMC_TG_CODE_G1_SHIFT)) & PCIE_PHY_CMN_REG00C_PLL_AGMC_TG_CODE_G1_MASK)
/*! @} */
/*! @name CMN_REG00D -  */
/*! @{ */
#define PCIE_PHY_CMN_REG00D_PLL_AGMC_TG_CODE_G2_MASK (0xFFU)
#define PCIE_PHY_CMN_REG00D_PLL_AGMC_TG_CODE_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG00D_PLL_AGMC_TG_CODE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00D_PLL_AGMC_TG_CODE_G2_SHIFT)) & PCIE_PHY_CMN_REG00D_PLL_AGMC_TG_CODE_G2_MASK)
/*! @} */
/*! @name CMN_REG00E -  */
/*! @{ */
#define PCIE_PHY_CMN_REG00E_PLL_AGMC_TG_CODE_G3_MASK (0xFFU)
#define PCIE_PHY_CMN_REG00E_PLL_AGMC_TG_CODE_G3_SHIFT (0U)
#define PCIE_PHY_CMN_REG00E_PLL_AGMC_TG_CODE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00E_PLL_AGMC_TG_CODE_G3_SHIFT)) & PCIE_PHY_CMN_REG00E_PLL_AGMC_TG_CODE_G3_MASK)
/*! @} */
/*! @name CMN_REG00F -  */
/*! @{ */
#define PCIE_PHY_CMN_REG00F_PLL_AGMC_TG_CODE_G4_MASK (0xFFU)
#define PCIE_PHY_CMN_REG00F_PLL_AGMC_TG_CODE_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG00F_PLL_AGMC_TG_CODE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00F_PLL_AGMC_TG_CODE_G4_SHIFT)) & PCIE_PHY_CMN_REG00F_PLL_AGMC_TG_CODE_G4_MASK)
/*! @} */
/*! @name CMN_REG010 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G2_MASK (0x7U)
#define PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G2_SHIFT)) & PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G2_MASK)
#define PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G1_MASK (0x38U)
#define PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G1_SHIFT (3U)
#define PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G1_SHIFT)) & PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G1_MASK)
/*! @} */
/*! @name CMN_REG011 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G4_MASK (0x7U)
#define PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G4_SHIFT)) & PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G4_MASK)
#define PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G3_MASK (0x38U)
#define PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G3_SHIFT (3U)
#define PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G3_SHIFT)) & PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G3_MASK)
/*! @} */
/*! @name CMN_REG012 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G2_MASK (0x7U)
#define PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G2_SHIFT)) & PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G2_MASK)
#define PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G1_MASK (0x38U)
#define PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G1_SHIFT (3U)
#define PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G1_SHIFT)) & PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G1_MASK)
/*! @} */
/*! @name CMN_REG013 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G4_MASK (0x7U)
#define PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G4_SHIFT)) & PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G4_MASK)
#define PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G3_MASK (0x38U)
#define PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G3_SHIFT (3U)
#define PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G3_SHIFT)) & PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G3_MASK)
/*! @} */
/*! @name CMN_REG014 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G2_MASK (0xFU)
#define PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G2_SHIFT)) & PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G2_MASK)
#define PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G1_MASK (0xF0U)
#define PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G1_SHIFT (4U)
#define PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G1_SHIFT)) & PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G1_MASK)
/*! @} */
/*! @name CMN_REG015 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G4_MASK (0xFU)
#define PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G4_SHIFT)) & PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G4_MASK)
#define PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G3_MASK (0xF0U)
#define PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G3_SHIFT (4U)
#define PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G3_SHIFT)) & PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G3_MASK)
/*! @} */
/*! @name CMN_REG016 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G2_MASK (0xFU)
#define PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G2_SHIFT)) & PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G2_MASK)
#define PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G1_MASK (0xF0U)
#define PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G1_SHIFT (4U)
#define PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G1_SHIFT)) & PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G1_MASK)
/*! @} */
/*! @name CMN_REG017 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G4_MASK (0xFU)
#define PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G4_SHIFT)) & PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G4_MASK)
#define PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G3_MASK (0xF0U)
#define PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G3_SHIFT (4U)
#define PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G3_SHIFT)) & PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G3_MASK)
/*! @} */
/*! @name CMN_REG018 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_VREF_SEL_MASK (0x7U)
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_VREF_SEL_SHIFT (0U)
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_VREF_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_VREF_SEL_SHIFT)) & PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_VREF_SEL_MASK)
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_CTRL_MASK (0x8U)
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_CTRL_SHIFT (3U)
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_CAP_OFFSET_SEL_MASK (0x70U)
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_CAP_OFFSET_SEL_SHIFT (4U)
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_CAP_OFFSET_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_CAP_OFFSET_SEL_SHIFT)) & PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_CAP_OFFSET_SEL_MASK)
/*! @} */
/*! @name CMN_REG019 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_R_SEL_MASK (0x7U)
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_R_SEL_SHIFT (0U)
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_R_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_R_SEL_SHIFT)) & PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_R_SEL_MASK)
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREF_BYPASS_MASK (0x8U)
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREF_BYPASS_SHIFT (3U)
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_I_CTRL_MASK (0x30U)
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_I_CTRL_SHIFT (4U)
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_I_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_I_CTRL_SHIFT)) & PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_I_CTRL_MASK)
/*! @} */
/*! @name CMN_REG01A -  */
/*! @{ */
#define PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G2_MASK (0x7U)
#define PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G2_SHIFT)) & PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G2_MASK)
#define PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G1_MASK (0x38U)
#define PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G1_SHIFT (3U)
#define PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G1_SHIFT)) & PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G1_MASK)
/*! @} */
/*! @name CMN_REG01B -  */
/*! @{ */
#define PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G4_MASK (0x7U)
#define PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G4_SHIFT)) & PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G4_MASK)
#define PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G3_MASK (0x38U)
#define PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G3_SHIFT (3U)
#define PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G3_SHIFT)) & PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G3_MASK)
/*! @} */
/*! @name CMN_REG01C -  */
/*! @{ */
#define PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G2_MASK (0x7U)
#define PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G2_SHIFT)) & PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G2_MASK)
#define PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G1_MASK (0x38U)
#define PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G1_SHIFT (3U)
#define PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G1_SHIFT)) & PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G1_MASK)
/*! @} */
/*! @name CMN_REG01D -  */
/*! @{ */
#define PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G4_MASK (0x7U)
#define PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G4_SHIFT)) & PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G4_MASK)
#define PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G3_MASK (0x38U)
#define PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G3_SHIFT (3U)
#define PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G3_SHIFT)) & PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G3_MASK)
/*! @} */
/*! @name CMN_REG01E -  */
/*! @{ */
#define PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G2_MASK (0xFU)
#define PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G2_SHIFT)) & PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G2_MASK)
#define PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G1_MASK (0xF0U)
#define PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G1_SHIFT (4U)
#define PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G1_SHIFT)) & PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G1_MASK)
/*! @} */
/*! @name CMN_REG01F -  */
/*! @{ */
#define PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G4_MASK (0xFU)
#define PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G4_SHIFT)) & PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G4_MASK)
#define PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G3_MASK (0xF0U)
#define PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G3_SHIFT (4U)
#define PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G3_SHIFT)) & PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G3_MASK)
/*! @} */
/*! @name CMN_REG020 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G2_MASK (0xFU)
#define PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G2_SHIFT)) & PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G2_MASK)
#define PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G1_MASK (0xF0U)
#define PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G1_SHIFT (4U)
#define PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G1_SHIFT)) & PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G1_MASK)
/*! @} */
/*! @name CMN_REG021 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G4_MASK (0xFU)
#define PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G4_SHIFT)) & PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G4_MASK)
#define PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G3_MASK (0xF0U)
#define PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G3_SHIFT (4U)
#define PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G3_SHIFT)) & PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G3_MASK)
/*! @} */
/*! @name CMN_REG022 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_IQ_DIV_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_IQ_DIV_EN_SHIFT (0U)
#define PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_DCC_EN_MASK (0x1EU)
#define PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_DCC_EN_SHIFT (1U)
#define PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_DCC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_DCC_EN_SHIFT)) & PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_DCC_EN_MASK)
/*! @} */
/*! @name CMN_REG023 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_TEST_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_TEST_EN_SHIFT (0U)
#define PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_SEL_MASK (0xEU)
#define PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_SEL_SHIFT (1U)
#define PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_SEL_SHIFT)) & PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_SEL_MASK)
#define PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_FINE_MASK (0x30U)
#define PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_FINE_SHIFT (4U)
#define PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_FINE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_FINE_SHIFT)) & PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_FINE_MASK)
#define PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_COARSE_MASK (0xC0U)
#define PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_COARSE_SHIFT (6U)
#define PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_COARSE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_COARSE_SHIFT)) & PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_COARSE_MASK)
/*! @} */
/*! @name CMN_REG024 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG024_ANA_PLL_EOM_PH_FINE_STEP_MASK (0x1U)
#define PCIE_PHY_CMN_REG024_ANA_PLL_EOM_PH_FINE_STEP_SHIFT (0U)
#define PCIE_PHY_CMN_REG024_ANA_PLL_ATB_SEL_MASK (0xFEU)
#define PCIE_PHY_CMN_REG024_ANA_PLL_ATB_SEL_SHIFT (1U)
#define PCIE_PHY_CMN_REG024_ANA_PLL_ATB_SEL(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG024_ANA_PLL_ATB_SEL_SHIFT)) & PCIE_PHY_CMN_REG024_ANA_PLL_ATB_SEL_MASK)
/*! @} */
/*! @name CMN_REG025 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG025_ANA_PLL_FLD_FAST_BYPASS_MASK (0x1U)
#define PCIE_PHY_CMN_REG025_ANA_PLL_FLD_FAST_BYPASS_SHIFT (0U)
#define PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_SEL_MASK (0x1EU)
#define PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_SEL_SHIFT (1U)
#define PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_SEL_SHIFT)) & PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_SEL_MASK)
#define PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_FIX_MASK (0x20U)
#define PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_FIX_SHIFT (5U)
/*! @} */
/*! @name CMN_REG026 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG026_ANA_PLL_FLD_LOCK_TOL_NUM_MASK (0x1FU)
#define PCIE_PHY_CMN_REG026_ANA_PLL_FLD_LOCK_TOL_NUM_SHIFT (0U)
#define PCIE_PHY_CMN_REG026_ANA_PLL_FLD_LOCK_TOL_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG026_ANA_PLL_FLD_LOCK_TOL_NUM_SHIFT)) & PCIE_PHY_CMN_REG026_ANA_PLL_FLD_LOCK_TOL_NUM_MASK)
#define PCIE_PHY_CMN_REG026_ANA_PLL_FLD_FAST_SETTLE_NUM_MASK (0xE0U)
#define PCIE_PHY_CMN_REG026_ANA_PLL_FLD_FAST_SETTLE_NUM_SHIFT (5U)
#define PCIE_PHY_CMN_REG026_ANA_PLL_FLD_FAST_SETTLE_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG026_ANA_PLL_FLD_FAST_SETTLE_NUM_SHIFT)) & PCIE_PHY_CMN_REG026_ANA_PLL_FLD_FAST_SETTLE_NUM_MASK)
/*! @} */
/*! @name CMN_REG027 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG027_ANA_PLL_FLD_SLOW_BYPASS_MASK (0x1U)
#define PCIE_PHY_CMN_REG027_ANA_PLL_FLD_SLOW_BYPASS_SHIFT (0U)
#define PCIE_PHY_CMN_REG027_ANA_PLL_FLD_NON_CONTINUOUS_MODE_MASK (0x2U)
#define PCIE_PHY_CMN_REG027_ANA_PLL_FLD_NON_CONTINUOUS_MODE_SHIFT (1U)
/*! @} */
/*! @name CMN_REG028 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G4_MASK    (0x1U)
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G4_SHIFT   (0U)
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G3_MASK    (0x2U)
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G3_SHIFT   (1U)
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G2_MASK    (0x4U)
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G2_SHIFT   (2U)
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G1_MASK    (0x8U)
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G1_SHIFT   (3U)
/*! @} */
/*! @name CMN_REG029 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG029_PLL_PI_STR_G2_MASK   (0xFU)
#define PCIE_PHY_CMN_REG029_PLL_PI_STR_G2_SHIFT  (0U)
#define PCIE_PHY_CMN_REG029_PLL_PI_STR_G2(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG029_PLL_PI_STR_G2_SHIFT)) & PCIE_PHY_CMN_REG029_PLL_PI_STR_G2_MASK)
#define PCIE_PHY_CMN_REG029_PLL_PI_STR_G1_MASK   (0xF0U)
#define PCIE_PHY_CMN_REG029_PLL_PI_STR_G1_SHIFT  (4U)
#define PCIE_PHY_CMN_REG029_PLL_PI_STR_G1(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG029_PLL_PI_STR_G1_SHIFT)) & PCIE_PHY_CMN_REG029_PLL_PI_STR_G1_MASK)
/*! @} */
/*! @name CMN_REG02A -  */
/*! @{ */
#define PCIE_PHY_CMN_REG02A_PLL_PI_STR_G4_MASK   (0xFU)
#define PCIE_PHY_CMN_REG02A_PLL_PI_STR_G4_SHIFT  (0U)
#define PCIE_PHY_CMN_REG02A_PLL_PI_STR_G4(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02A_PLL_PI_STR_G4_SHIFT)) & PCIE_PHY_CMN_REG02A_PLL_PI_STR_G4_MASK)
#define PCIE_PHY_CMN_REG02A_PLL_PI_STR_G3_MASK   (0xF0U)
#define PCIE_PHY_CMN_REG02A_PLL_PI_STR_G3_SHIFT  (4U)
#define PCIE_PHY_CMN_REG02A_PLL_PI_STR_G3(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02A_PLL_PI_STR_G3_SHIFT)) & PCIE_PHY_CMN_REG02A_PLL_PI_STR_G3_MASK)
/*! @} */
/*! @name CMN_REG02B -  */
/*! @{ */
#define PCIE_PHY_CMN_REG02B_PLL_PMS_PDIV_RSTN_MASK (0x1U)
#define PCIE_PHY_CMN_REG02B_PLL_PMS_PDIV_RSTN_SHIFT (0U)
#define PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_PDIV_RSTN_MASK (0x2U)
#define PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_PDIV_RSTN_SHIFT (1U)
#define PCIE_PHY_CMN_REG02B_PLL_PMS_MDIV_RSTN_MASK (0x4U)
#define PCIE_PHY_CMN_REG02B_PLL_PMS_MDIV_RSTN_SHIFT (2U)
#define PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_MDIV_RSTN_MASK (0x8U)
#define PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_MDIV_RSTN_SHIFT (3U)
/*! @} */
/*! @name CMN_REG02C -  */
/*! @{ */
#define PCIE_PHY_CMN_REG02C_PLL_PMS_MDIV_AFC_G1_MASK (0xFFU)
#define PCIE_PHY_CMN_REG02C_PLL_PMS_MDIV_AFC_G1_SHIFT (0U)
#define PCIE_PHY_CMN_REG02C_PLL_PMS_MDIV_AFC_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02C_PLL_PMS_MDIV_AFC_G1_SHIFT)) & PCIE_PHY_CMN_REG02C_PLL_PMS_MDIV_AFC_G1_MASK)
/*! @} */
/*! @name CMN_REG02D -  */
/*! @{ */
#define PCIE_PHY_CMN_REG02D_PLL_PMS_MDIV_AFC_G2_MASK (0xFFU)
#define PCIE_PHY_CMN_REG02D_PLL_PMS_MDIV_AFC_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG02D_PLL_PMS_MDIV_AFC_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02D_PLL_PMS_MDIV_AFC_G2_SHIFT)) & PCIE_PHY_CMN_REG02D_PLL_PMS_MDIV_AFC_G2_MASK)
/*! @} */
/*! @name CMN_REG02E -  */
/*! @{ */
#define PCIE_PHY_CMN_REG02E_PLL_PMS_MDIV_AFC_G3_MASK (0xFFU)
#define PCIE_PHY_CMN_REG02E_PLL_PMS_MDIV_AFC_G3_SHIFT (0U)
#define PCIE_PHY_CMN_REG02E_PLL_PMS_MDIV_AFC_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02E_PLL_PMS_MDIV_AFC_G3_SHIFT)) & PCIE_PHY_CMN_REG02E_PLL_PMS_MDIV_AFC_G3_MASK)
/*! @} */
/*! @name CMN_REG02F -  */
/*! @{ */
#define PCIE_PHY_CMN_REG02F_PLL_PMS_MDIV_AFC_G4_MASK (0xFFU)
#define PCIE_PHY_CMN_REG02F_PLL_PMS_MDIV_AFC_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG02F_PLL_PMS_MDIV_AFC_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02F_PLL_PMS_MDIV_AFC_G4_SHIFT)) & PCIE_PHY_CMN_REG02F_PLL_PMS_MDIV_AFC_G4_MASK)
/*! @} */
/*! @name CMN_REG030 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG030_PLL_PMS_MDIV_G1_MASK (0xFFU)
#define PCIE_PHY_CMN_REG030_PLL_PMS_MDIV_G1_SHIFT (0U)
#define PCIE_PHY_CMN_REG030_PLL_PMS_MDIV_G1(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG030_PLL_PMS_MDIV_G1_SHIFT)) & PCIE_PHY_CMN_REG030_PLL_PMS_MDIV_G1_MASK)
/*! @} */
/*! @name CMN_REG031 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG031_PLL_PMS_MDIV_G2_MASK (0xFFU)
#define PCIE_PHY_CMN_REG031_PLL_PMS_MDIV_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG031_PLL_PMS_MDIV_G2(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG031_PLL_PMS_MDIV_G2_SHIFT)) & PCIE_PHY_CMN_REG031_PLL_PMS_MDIV_G2_MASK)
/*! @} */
/*! @name CMN_REG032 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG032_PLL_PMS_MDIV_G3_MASK (0xFFU)
#define PCIE_PHY_CMN_REG032_PLL_PMS_MDIV_G3_SHIFT (0U)
#define PCIE_PHY_CMN_REG032_PLL_PMS_MDIV_G3(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG032_PLL_PMS_MDIV_G3_SHIFT)) & PCIE_PHY_CMN_REG032_PLL_PMS_MDIV_G3_MASK)
/*! @} */
/*! @name CMN_REG033 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG033_PLL_PMS_MDIV_G4_MASK (0xFFU)
#define PCIE_PHY_CMN_REG033_PLL_PMS_MDIV_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG033_PLL_PMS_MDIV_G4(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG033_PLL_PMS_MDIV_G4_SHIFT)) & PCIE_PHY_CMN_REG033_PLL_PMS_MDIV_G4_MASK)
/*! @} */
/*! @name CMN_REG034 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG034_ANA_PLL_PMS_PDIV_MASK (0xFU)
#define PCIE_PHY_CMN_REG034_ANA_PLL_PMS_PDIV_SHIFT (0U)
#define PCIE_PHY_CMN_REG034_ANA_PLL_PMS_PDIV(x)  (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG034_ANA_PLL_PMS_PDIV_SHIFT)) & PCIE_PHY_CMN_REG034_ANA_PLL_PMS_PDIV_MASK)
#define PCIE_PHY_CMN_REG034_ANA_PLL_PMS_MDIV_X2_EN_MASK (0x10U)
#define PCIE_PHY_CMN_REG034_ANA_PLL_PMS_MDIV_X2_EN_SHIFT (4U)
/*! @} */
/*! @name CMN_REG035 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG035_ANA_PLL_PMS_REFDIV_MASK (0xFU)
#define PCIE_PHY_CMN_REG035_ANA_PLL_PMS_REFDIV_SHIFT (0U)
#define PCIE_PHY_CMN_REG035_ANA_PLL_PMS_REFDIV(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG035_ANA_PLL_PMS_REFDIV_SHIFT)) & PCIE_PHY_CMN_REG035_ANA_PLL_PMS_REFDIV_MASK)
/*! @} */
/*! @name CMN_REG036 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G2_MASK (0xFU)
#define PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G2(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G2_SHIFT)) & PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G2_MASK)
#define PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G1_MASK (0xF0U)
#define PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G1_SHIFT (4U)
#define PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G1(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G1_SHIFT)) & PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G1_MASK)
/*! @} */
/*! @name CMN_REG037 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G4_MASK (0xFU)
#define PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G4(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G4_SHIFT)) & PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G4_MASK)
#define PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G3_MASK (0xF0U)
#define PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G3_SHIFT (4U)
#define PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G3(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G3_SHIFT)) & PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G3_MASK)
/*! @} */
/*! @name CMN_REG038 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_EN_SHIFT (0U)
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_DIV_SEL_MASK (0x6U)
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_DIV_SEL_SHIFT (1U)
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_DIV_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_DIV_SEL_SHIFT)) & PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_DIV_SEL_MASK)
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_BYPASS_CLK_SEL_MASK (0x18U)
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_BYPASS_CLK_SEL_SHIFT (3U)
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_BYPASS_CLK_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG038_ANA_PLL_REF_BYPASS_CLK_SEL_SHIFT)) & PCIE_PHY_CMN_REG038_ANA_PLL_REF_BYPASS_CLK_SEL_MASK)
#define PCIE_PHY_CMN_REG038_PLL_REF_CHOPPER_CLK_DIV_RSTN_MASK (0x20U)
#define PCIE_PHY_CMN_REG038_PLL_REF_CHOPPER_CLK_DIV_RSTN_SHIFT (5U)
#define PCIE_PHY_CMN_REG038_OVRD_PLL_REF_CHOPPER_CLK_DIV_RSTN_MASK (0x40U)
#define PCIE_PHY_CMN_REG038_OVRD_PLL_REF_CHOPPER_CLK_DIV_RSTN_SHIFT (6U)
/*! @} */
/*! @name CMN_REG039 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG039_ANA_PLL_REF_DIG_CLK_SEL_MASK (0x1U)
#define PCIE_PHY_CMN_REG039_ANA_PLL_REF_DIG_CLK_SEL_SHIFT (0U)
#define PCIE_PHY_CMN_REG039_PLL_REF_CLK_SEL_MASK (0x6U)
#define PCIE_PHY_CMN_REG039_PLL_REF_CLK_SEL_SHIFT (1U)
#define PCIE_PHY_CMN_REG039_PLL_REF_CLK_SEL(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG039_PLL_REF_CLK_SEL_SHIFT)) & PCIE_PHY_CMN_REG039_PLL_REF_CLK_SEL_MASK)
#define PCIE_PHY_CMN_REG039_OVRD_PLL_REF_CLK_SEL_MASK (0x8U)
#define PCIE_PHY_CMN_REG039_OVRD_PLL_REF_CLK_SEL_SHIFT (3U)
/*! @} */
/*! @name CMN_REG03A -  */
/*! @{ */
#define PCIE_PHY_CMN_REG03A_PLL_SDM_RSTN_MASK    (0x1U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_RSTN_SHIFT   (0U)
#define PCIE_PHY_CMN_REG03A_OVRD_PLL_SDM_RSTN_MASK (0x2U)
#define PCIE_PHY_CMN_REG03A_OVRD_PLL_SDM_RSTN_SHIFT (1U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G4_MASK   (0x4U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G4_SHIFT  (2U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G3_MASK   (0x8U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G3_SHIFT  (3U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G2_MASK   (0x10U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G2_SHIFT  (4U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G1_MASK   (0x20U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G1_SHIFT  (5U)
/*! @} */
/*! @name CMN_REG03B -  */
/*! @{ */
#define PCIE_PHY_CMN_REG03B_PLL_SDC_RSTN_MASK    (0x1U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_RSTN_SHIFT   (0U)
#define PCIE_PHY_CMN_REG03B_OVRD_PLL_SDC_RSTN_MASK (0x2U)
#define PCIE_PHY_CMN_REG03B_OVRD_PLL_SDC_RSTN_SHIFT (1U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G4_MASK (0x4U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G4_SHIFT (2U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G3_MASK (0x8U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G3_SHIFT (3U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G2_MASK (0x10U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G2_SHIFT (4U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G1_MASK (0x20U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G1_SHIFT (5U)
/*! @} */
/*! @name CMN_REG03C -  */
/*! @{ */
#define PCIE_PHY_CMN_REG03C_PLL_SDM_DENOMINATOR_G1_MASK (0xFFU)
#define PCIE_PHY_CMN_REG03C_PLL_SDM_DENOMINATOR_G1_SHIFT (0U)
#define PCIE_PHY_CMN_REG03C_PLL_SDM_DENOMINATOR_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03C_PLL_SDM_DENOMINATOR_G1_SHIFT)) & PCIE_PHY_CMN_REG03C_PLL_SDM_DENOMINATOR_G1_MASK)
/*! @} */
/*! @name CMN_REG03D -  */
/*! @{ */
#define PCIE_PHY_CMN_REG03D_PLL_SDM_DENOMINATOR_G2_MASK (0xFFU)
#define PCIE_PHY_CMN_REG03D_PLL_SDM_DENOMINATOR_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG03D_PLL_SDM_DENOMINATOR_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03D_PLL_SDM_DENOMINATOR_G2_SHIFT)) & PCIE_PHY_CMN_REG03D_PLL_SDM_DENOMINATOR_G2_MASK)
/*! @} */
/*! @name CMN_REG03E -  */
/*! @{ */
#define PCIE_PHY_CMN_REG03E_PLL_SDM_DENOMINATOR_G3_MASK (0xFFU)
#define PCIE_PHY_CMN_REG03E_PLL_SDM_DENOMINATOR_G3_SHIFT (0U)
#define PCIE_PHY_CMN_REG03E_PLL_SDM_DENOMINATOR_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03E_PLL_SDM_DENOMINATOR_G3_SHIFT)) & PCIE_PHY_CMN_REG03E_PLL_SDM_DENOMINATOR_G3_MASK)
/*! @} */
/*! @name CMN_REG03F -  */
/*! @{ */
#define PCIE_PHY_CMN_REG03F_PLL_SDM_DENOMINATOR_G4_MASK (0xFFU)
#define PCIE_PHY_CMN_REG03F_PLL_SDM_DENOMINATOR_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG03F_PLL_SDM_DENOMINATOR_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03F_PLL_SDM_DENOMINATOR_G4_SHIFT)) & PCIE_PHY_CMN_REG03F_PLL_SDM_DENOMINATOR_G4_MASK)
/*! @} */
/*! @name CMN_REG040 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G4_MASK (0x1U)
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G3_MASK (0x2U)
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G3_SHIFT (1U)
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G2_MASK (0x4U)
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G2_SHIFT (2U)
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G1_MASK (0x8U)
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G1_SHIFT (3U)
/*! @} */
/*! @name CMN_REG041 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG041_PLL_SDM_NUMERATOR_G1_MASK (0xFFU)
#define PCIE_PHY_CMN_REG041_PLL_SDM_NUMERATOR_G1_SHIFT (0U)
#define PCIE_PHY_CMN_REG041_PLL_SDM_NUMERATOR_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG041_PLL_SDM_NUMERATOR_G1_SHIFT)) & PCIE_PHY_CMN_REG041_PLL_SDM_NUMERATOR_G1_MASK)
/*! @} */
/*! @name CMN_REG042 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG042_PLL_SDM_NUMERATOR_G2_MASK (0xFFU)
#define PCIE_PHY_CMN_REG042_PLL_SDM_NUMERATOR_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG042_PLL_SDM_NUMERATOR_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG042_PLL_SDM_NUMERATOR_G2_SHIFT)) & PCIE_PHY_CMN_REG042_PLL_SDM_NUMERATOR_G2_MASK)
/*! @} */
/*! @name CMN_REG043 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG043_PLL_SDM_NUMERATOR_G3_MASK (0xFFU)
#define PCIE_PHY_CMN_REG043_PLL_SDM_NUMERATOR_G3_SHIFT (0U)
#define PCIE_PHY_CMN_REG043_PLL_SDM_NUMERATOR_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG043_PLL_SDM_NUMERATOR_G3_SHIFT)) & PCIE_PHY_CMN_REG043_PLL_SDM_NUMERATOR_G3_MASK)
/*! @} */
/*! @name CMN_REG044 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG044_PLL_SDM_NUMERATOR_G4_MASK (0xFFU)
#define PCIE_PHY_CMN_REG044_PLL_SDM_NUMERATOR_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG044_PLL_SDM_NUMERATOR_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG044_PLL_SDM_NUMERATOR_G4_SHIFT)) & PCIE_PHY_CMN_REG044_PLL_SDM_NUMERATOR_G4_MASK)
/*! @} */
/*! @name CMN_REG045 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G4_MASK (0x1U)
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G3_MASK (0x2U)
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G3_SHIFT (1U)
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G2_MASK (0x4U)
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G2_SHIFT (2U)
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G1_MASK (0x8U)
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G1_SHIFT (3U)
/*! @} */
/*! @name CMN_REG046 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G4_MASK (0x3U)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G4_SHIFT)) & PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G4_MASK)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G3_MASK (0xCU)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G3_SHIFT (2U)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G3_SHIFT)) & PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G3_MASK)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G2_MASK (0x30U)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G2_SHIFT (4U)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G2_SHIFT)) & PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G2_MASK)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G1_MASK (0xC0U)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G1_SHIFT (6U)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G1_SHIFT)) & PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G1_MASK)
/*! @} */
/*! @name CMN_REG047 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG047_PLL_SDC_N_G2_MASK    (0x7U)
#define PCIE_PHY_CMN_REG047_PLL_SDC_N_G2_SHIFT   (0U)
#define PCIE_PHY_CMN_REG047_PLL_SDC_N_G2(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG047_PLL_SDC_N_G2_SHIFT)) & PCIE_PHY_CMN_REG047_PLL_SDC_N_G2_MASK)
#define PCIE_PHY_CMN_REG047_PLL_SDC_N_G1_MASK    (0x38U)
#define PCIE_PHY_CMN_REG047_PLL_SDC_N_G1_SHIFT   (3U)
#define PCIE_PHY_CMN_REG047_PLL_SDC_N_G1(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG047_PLL_SDC_N_G1_SHIFT)) & PCIE_PHY_CMN_REG047_PLL_SDC_N_G1_MASK)
/*! @} */
/*! @name CMN_REG048 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG048_PLL_SDC_N_G4_MASK    (0x7U)
#define PCIE_PHY_CMN_REG048_PLL_SDC_N_G4_SHIFT   (0U)
#define PCIE_PHY_CMN_REG048_PLL_SDC_N_G4(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG048_PLL_SDC_N_G4_SHIFT)) & PCIE_PHY_CMN_REG048_PLL_SDC_N_G4_MASK)
#define PCIE_PHY_CMN_REG048_PLL_SDC_N_G3_MASK    (0x38U)
#define PCIE_PHY_CMN_REG048_PLL_SDC_N_G3_SHIFT   (3U)
#define PCIE_PHY_CMN_REG048_PLL_SDC_N_G3(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG048_PLL_SDC_N_G3_SHIFT)) & PCIE_PHY_CMN_REG048_PLL_SDC_N_G3_MASK)
/*! @} */
/*! @name CMN_REG049 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G4_MASK   (0x1U)
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G4_SHIFT  (0U)
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G3_MASK   (0x2U)
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G3_SHIFT  (1U)
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G2_MASK   (0x4U)
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G2_SHIFT  (2U)
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G1_MASK   (0x8U)
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G1_SHIFT  (3U)
/*! @} */
/*! @name CMN_REG04A -  */
/*! @{ */
#define PCIE_PHY_CMN_REG04A_PLL_SDC_NUMERATOR_G1_MASK (0x3FU)
#define PCIE_PHY_CMN_REG04A_PLL_SDC_NUMERATOR_G1_SHIFT (0U)
#define PCIE_PHY_CMN_REG04A_PLL_SDC_NUMERATOR_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG04A_PLL_SDC_NUMERATOR_G1_SHIFT)) & PCIE_PHY_CMN_REG04A_PLL_SDC_NUMERATOR_G1_MASK)
/*! @} */
/*! @name CMN_REG04B -  */
/*! @{ */
#define PCIE_PHY_CMN_REG04B_PLL_SDC_NUMERATOR_G2_MASK (0x3FU)
#define PCIE_PHY_CMN_REG04B_PLL_SDC_NUMERATOR_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG04B_PLL_SDC_NUMERATOR_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG04B_PLL_SDC_NUMERATOR_G2_SHIFT)) & PCIE_PHY_CMN_REG04B_PLL_SDC_NUMERATOR_G2_MASK)
/*! @} */
/*! @name CMN_REG04C -  */
/*! @{ */
#define PCIE_PHY_CMN_REG04C_PLL_SDC_NUMERATOR_G3_MASK (0x3FU)
#define PCIE_PHY_CMN_REG04C_PLL_SDC_NUMERATOR_G3_SHIFT (0U)
#define PCIE_PHY_CMN_REG04C_PLL_SDC_NUMERATOR_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG04C_PLL_SDC_NUMERATOR_G3_SHIFT)) & PCIE_PHY_CMN_REG04C_PLL_SDC_NUMERATOR_G3_MASK)
/*! @} */
/*! @name CMN_REG04D -  */
/*! @{ */
#define PCIE_PHY_CMN_REG04D_PLL_SDC_NUMERATOR_G4_MASK (0x3FU)
#define PCIE_PHY_CMN_REG04D_PLL_SDC_NUMERATOR_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG04D_PLL_SDC_NUMERATOR_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG04D_PLL_SDC_NUMERATOR_G4_SHIFT)) & PCIE_PHY_CMN_REG04D_PLL_SDC_NUMERATOR_G4_MASK)
/*! @} */
/*! @name CMN_REG04E -  */
/*! @{ */
#define PCIE_PHY_CMN_REG04E_PLL_SDC_DENOMINATOR_G1_MASK (0x3FU)
#define PCIE_PHY_CMN_REG04E_PLL_SDC_DENOMINATOR_G1_SHIFT (0U)
#define PCIE_PHY_CMN_REG04E_PLL_SDC_DENOMINATOR_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG04E_PLL_SDC_DENOMINATOR_G1_SHIFT)) & PCIE_PHY_CMN_REG04E_PLL_SDC_DENOMINATOR_G1_MASK)
/*! @} */
/*! @name CMN_REG04F -  */
/*! @{ */
#define PCIE_PHY_CMN_REG04F_PLL_SDC_DENOMINATOR_G2_MASK (0x3FU)
#define PCIE_PHY_CMN_REG04F_PLL_SDC_DENOMINATOR_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG04F_PLL_SDC_DENOMINATOR_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG04F_PLL_SDC_DENOMINATOR_G2_SHIFT)) & PCIE_PHY_CMN_REG04F_PLL_SDC_DENOMINATOR_G2_MASK)
/*! @} */
/*! @name CMN_REG050 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG050_PLL_SDC_DENOMINATOR_G3_MASK (0x3FU)
#define PCIE_PHY_CMN_REG050_PLL_SDC_DENOMINATOR_G3_SHIFT (0U)
#define PCIE_PHY_CMN_REG050_PLL_SDC_DENOMINATOR_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG050_PLL_SDC_DENOMINATOR_G3_SHIFT)) & PCIE_PHY_CMN_REG050_PLL_SDC_DENOMINATOR_G3_MASK)
/*! @} */
/*! @name CMN_REG051 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG051_ANA_PLL_SDC_MC_VALUE_SEL_MASK (0x1U)
#define PCIE_PHY_CMN_REG051_ANA_PLL_SDC_MC_VALUE_SEL_SHIFT (0U)
#define PCIE_PHY_CMN_REG051_PLL_SDC_DENOMINATOR_G4_MASK (0x7EU)
#define PCIE_PHY_CMN_REG051_PLL_SDC_DENOMINATOR_G4_SHIFT (1U)
#define PCIE_PHY_CMN_REG051_PLL_SDC_DENOMINATOR_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG051_PLL_SDC_DENOMINATOR_G4_SHIFT)) & PCIE_PHY_CMN_REG051_PLL_SDC_DENOMINATOR_G4_MASK)
/*! @} */
/*! @name CMN_REG052 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG052_PLL_SSC_EN_MASK      (0x1U)
#define PCIE_PHY_CMN_REG052_PLL_SSC_EN_SHIFT     (0U)
#define PCIE_PHY_CMN_REG052_OVRD_PLL_SSC_EN_MASK (0x2U)
#define PCIE_PHY_CMN_REG052_OVRD_PLL_SSC_EN_SHIFT (1U)
/*! @} */
/*! @name CMN_REG053 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG053_PLL_SSC_FM_DEVIATION_G1_MASK (0x3FU)
#define PCIE_PHY_CMN_REG053_PLL_SSC_FM_DEVIATION_G1_SHIFT (0U)
#define PCIE_PHY_CMN_REG053_PLL_SSC_FM_DEVIATION_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG053_PLL_SSC_FM_DEVIATION_G1_SHIFT)) & PCIE_PHY_CMN_REG053_PLL_SSC_FM_DEVIATION_G1_MASK)
/*! @} */
/*! @name CMN_REG054 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG054_PLL_SSC_FM_DEVIATION_G2_MASK (0x3FU)
#define PCIE_PHY_CMN_REG054_PLL_SSC_FM_DEVIATION_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG054_PLL_SSC_FM_DEVIATION_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG054_PLL_SSC_FM_DEVIATION_G2_SHIFT)) & PCIE_PHY_CMN_REG054_PLL_SSC_FM_DEVIATION_G2_MASK)
/*! @} */
/*! @name CMN_REG055 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG055_PLL_SSC_FM_DEVIATION_G3_MASK (0x3FU)
#define PCIE_PHY_CMN_REG055_PLL_SSC_FM_DEVIATION_G3_SHIFT (0U)
#define PCIE_PHY_CMN_REG055_PLL_SSC_FM_DEVIATION_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG055_PLL_SSC_FM_DEVIATION_G3_SHIFT)) & PCIE_PHY_CMN_REG055_PLL_SSC_FM_DEVIATION_G3_MASK)
/*! @} */
/*! @name CMN_REG056 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG056_PLL_SSC_FM_DEVIATION_G4_MASK (0x3FU)
#define PCIE_PHY_CMN_REG056_PLL_SSC_FM_DEVIATION_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG056_PLL_SSC_FM_DEVIATION_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG056_PLL_SSC_FM_DEVIATION_G4_SHIFT)) & PCIE_PHY_CMN_REG056_PLL_SSC_FM_DEVIATION_G4_MASK)
/*! @} */
/*! @name CMN_REG057 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG057_PLL_SSC_FM_FREQ_G1_MASK (0x1FU)
#define PCIE_PHY_CMN_REG057_PLL_SSC_FM_FREQ_G1_SHIFT (0U)
#define PCIE_PHY_CMN_REG057_PLL_SSC_FM_FREQ_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG057_PLL_SSC_FM_FREQ_G1_SHIFT)) & PCIE_PHY_CMN_REG057_PLL_SSC_FM_FREQ_G1_MASK)
/*! @} */
/*! @name CMN_REG058 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG058_PLL_SSC_FM_FREQ_G2_MASK (0x1FU)
#define PCIE_PHY_CMN_REG058_PLL_SSC_FM_FREQ_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG058_PLL_SSC_FM_FREQ_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG058_PLL_SSC_FM_FREQ_G2_SHIFT)) & PCIE_PHY_CMN_REG058_PLL_SSC_FM_FREQ_G2_MASK)
/*! @} */
/*! @name CMN_REG059 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG059_PLL_SSC_FM_FREQ_G3_MASK (0x1FU)
#define PCIE_PHY_CMN_REG059_PLL_SSC_FM_FREQ_G3_SHIFT (0U)
#define PCIE_PHY_CMN_REG059_PLL_SSC_FM_FREQ_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG059_PLL_SSC_FM_FREQ_G3_SHIFT)) & PCIE_PHY_CMN_REG059_PLL_SSC_FM_FREQ_G3_MASK)
/*! @} */
/*! @name CMN_REG05A -  */
/*! @{ */
#define PCIE_PHY_CMN_REG05A_PLL_SSC_FM_FREQ_G4_MASK (0x1FU)
#define PCIE_PHY_CMN_REG05A_PLL_SSC_FM_FREQ_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG05A_PLL_SSC_FM_FREQ_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05A_PLL_SSC_FM_FREQ_G4_SHIFT)) & PCIE_PHY_CMN_REG05A_PLL_SSC_FM_FREQ_G4_MASK)
/*! @} */
/*! @name CMN_REG05B -  */
/*! @{ */
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G4_MASK (0x3U)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G4_SHIFT)) & PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G4_MASK)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G3_MASK (0xCU)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G3_SHIFT (2U)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G3_SHIFT)) & PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G3_MASK)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G2_MASK (0x30U)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G2_SHIFT (4U)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G2_SHIFT)) & PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G2_MASK)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G1_MASK (0xC0U)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G1_SHIFT (6U)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G1_SHIFT)) & PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G1_MASK)
/*! @} */
/*! @name CMN_REG05C -  */
/*! @{ */
#define PCIE_PHY_CMN_REG05C_PLL_CD_TX_SER_RSTN_MASK (0x1U)
#define PCIE_PHY_CMN_REG05C_PLL_CD_TX_SER_RSTN_SHIFT (0U)
#define PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_TX_SER_RSTN_MASK (0x2U)
#define PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_TX_SER_RSTN_SHIFT (1U)
#define PCIE_PHY_CMN_REG05C_PLL_CD_CLK_EN_MASK   (0x4U)
#define PCIE_PHY_CMN_REG05C_PLL_CD_CLK_EN_SHIFT  (2U)
#define PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_CLK_EN_MASK (0x8U)
#define PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_CLK_EN_SHIFT (3U)
#define PCIE_PHY_CMN_REG05C_ANA_PLL_SSC_CLK_DIV_SEL_MASK (0xF0U)
#define PCIE_PHY_CMN_REG05C_ANA_PLL_SSC_CLK_DIV_SEL_SHIFT (4U)
#define PCIE_PHY_CMN_REG05C_ANA_PLL_SSC_CLK_DIV_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05C_ANA_PLL_SSC_CLK_DIV_SEL_SHIFT)) & PCIE_PHY_CMN_REG05C_ANA_PLL_SSC_CLK_DIV_SEL_MASK)
/*! @} */
/*! @name CMN_REG05D -  */
/*! @{ */
#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_EAST_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_EAST_EN_SHIFT (0U)
#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_WEST_EN_MASK (0x2U)
#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_WEST_EN_SHIFT (1U)
#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_INV_MASK (0x4U)
#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_INV_SHIFT (2U)
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G4_MASK (0x8U)
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G4_SHIFT (3U)
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G3_MASK (0x10U)
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G3_SHIFT (4U)
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G2_MASK (0x20U)
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G2_SHIFT (5U)
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G1_MASK (0x40U)
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G1_SHIFT (6U)
/*! @} */
/*! @name CMN_REG05E -  */
/*! @{ */
#define PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SEL_MASK (0x3U)
#define PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SEL_SHIFT (0U)
#define PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SEL_SHIFT)) & PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SEL_MASK)
#define PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SYNC_EN_MASK (0x4U)
#define PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SYNC_EN_SHIFT (2U)
#define PCIE_PHY_CMN_REG05E_PLL_BEACON_LFPS_OUT_EN_MASK (0x8U)
#define PCIE_PHY_CMN_REG05E_PLL_BEACON_LFPS_OUT_EN_SHIFT (3U)
#define PCIE_PHY_CMN_REG05E_OVRD_PLL_BEACON_LFPS_OUT_EN_MASK (0x10U)
#define PCIE_PHY_CMN_REG05E_OVRD_PLL_BEACON_LFPS_OUT_EN_SHIFT (4U)
/*! @} */
/*! @name CMN_REG05F -  */
/*! @{ */
#define PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G2_MASK (0xFU)
#define PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G2_SHIFT (0U)
#define PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G2_SHIFT)) & PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G2_MASK)
#define PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G1_MASK (0xF0U)
#define PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G1_SHIFT (4U)
#define PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G1_SHIFT)) & PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G1_MASK)
/*! @} */
/*! @name CMN_REG060 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G4_MASK (0xFU)
#define PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G4_SHIFT (0U)
#define PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G4_SHIFT)) & PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G4_MASK)
#define PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G3_MASK (0xF0U)
#define PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G3_SHIFT (4U)
#define PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G3_SHIFT)) & PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G3_MASK)
/*! @} */
/*! @name CMN_REG061 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG061_ANA_PLL_CLK_OUT_TO_EXT_IO_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG061_ANA_PLL_CLK_OUT_TO_EXT_IO_EN_SHIFT (0U)
#define PCIE_PHY_CMN_REG061_PLL_MISC_OSC_RSTN_MASK (0x2U)
#define PCIE_PHY_CMN_REG061_PLL_MISC_OSC_RSTN_SHIFT (1U)
#define PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_RSTN_MASK (0x4U)
#define PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_RSTN_SHIFT (2U)
#define PCIE_PHY_CMN_REG061_PLL_MISC_OSC_FREQ_SEL_MASK (0x78U)
#define PCIE_PHY_CMN_REG061_PLL_MISC_OSC_FREQ_SEL_SHIFT (3U)
#define PCIE_PHY_CMN_REG061_PLL_MISC_OSC_FREQ_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG061_PLL_MISC_OSC_FREQ_SEL_SHIFT)) & PCIE_PHY_CMN_REG061_PLL_MISC_OSC_FREQ_SEL_MASK)
#define PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_FREQ_SEL_MASK (0x80U)
#define PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_FREQ_SEL_SHIFT (7U)
/*! @} */
/*! @name CMN_REG062 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_SEL_MASK (0x3U)
#define PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_SEL_SHIFT (0U)
#define PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_SEL_SHIFT)) & PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_SEL_MASK)
#define PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_EN_MASK (0x4U)
#define PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_EN_SHIFT (2U)
#define PCIE_PHY_CMN_REG062_ANA_PLL_CLK_OUT_TO_EXT_IO_SEL_MASK (0x8U)
#define PCIE_PHY_CMN_REG062_ANA_PLL_CLK_OUT_TO_EXT_IO_SEL_SHIFT (3U)
/*! @} */
/*! @name CMN_REG063 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG063_ANA_PLL_RESERVED_MASK (0x3FU)
#define PCIE_PHY_CMN_REG063_ANA_PLL_RESERVED_SHIFT (0U)
#define PCIE_PHY_CMN_REG063_ANA_PLL_RESERVED(x)  (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG063_ANA_PLL_RESERVED_SHIFT)) & PCIE_PHY_CMN_REG063_ANA_PLL_RESERVED_MASK)
#define PCIE_PHY_CMN_REG063_AUX_PLL_REFCLK_SEL_MASK (0xC0U)
#define PCIE_PHY_CMN_REG063_AUX_PLL_REFCLK_SEL_SHIFT (6U)
#define PCIE_PHY_CMN_REG063_AUX_PLL_REFCLK_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG063_AUX_PLL_REFCLK_SEL_SHIFT)) & PCIE_PHY_CMN_REG063_AUX_PLL_REFCLK_SEL_MASK)
/*! @} */
/*! @name CMN_REG064 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG064_ANA_AUX_TX_TERM_MASK (0x7U)
#define PCIE_PHY_CMN_REG064_ANA_AUX_TX_TERM_SHIFT (0U)
#define PCIE_PHY_CMN_REG064_ANA_AUX_TX_TERM(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG064_ANA_AUX_TX_TERM_SHIFT)) & PCIE_PHY_CMN_REG064_ANA_AUX_TX_TERM_MASK)
#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_TERM_GND_EN_MASK (0x8U)
#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_TERM_GND_EN_SHIFT (3U)
#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_CAP_BYPASS_MASK (0x10U)
#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_CAP_BYPASS_SHIFT (4U)
#define PCIE_PHY_CMN_REG064_AUX_EN_MASK          (0x20U)
#define PCIE_PHY_CMN_REG064_AUX_EN_SHIFT         (5U)
#define PCIE_PHY_CMN_REG064_OVRD_AUX_EN_MASK     (0x40U)
#define PCIE_PHY_CMN_REG064_OVRD_AUX_EN_SHIFT    (6U)
#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_TX_SEL_MASK (0x80U)
#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_TX_SEL_SHIFT (7U)
/*! @} */
/*! @name CMN_REG065 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG065_ANA_AUX_TX_LVL_CTRL_MASK (0xFU)
#define PCIE_PHY_CMN_REG065_ANA_AUX_TX_LVL_CTRL_SHIFT (0U)
#define PCIE_PHY_CMN_REG065_ANA_AUX_TX_LVL_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG065_ANA_AUX_TX_LVL_CTRL_SHIFT)) & PCIE_PHY_CMN_REG065_ANA_AUX_TX_LVL_CTRL_MASK)
#define PCIE_PHY_CMN_REG065_ANA_AUX_RX_TERM_MASK (0xF0U)
#define PCIE_PHY_CMN_REG065_ANA_AUX_RX_TERM_SHIFT (4U)
#define PCIE_PHY_CMN_REG065_ANA_AUX_RX_TERM(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG065_ANA_AUX_RX_TERM_SHIFT)) & PCIE_PHY_CMN_REG065_ANA_AUX_RX_TERM_MASK)
/*! @} */
/*! @name CMN_REG066 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_HYS_CTRL_MASK (0x7U)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_HYS_CTRL_SHIFT (0U)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_HYS_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG066_ANA_AUX_RX_HYS_CTRL_SHIFT)) & PCIE_PHY_CMN_REG066_ANA_AUX_RX_HYS_CTRL_MASK)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_FINE_CTRL_MASK (0x18U)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_FINE_CTRL_SHIFT (3U)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_FINE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_FINE_CTRL_SHIFT)) & PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_FINE_CTRL_MASK)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_COARSE_CTRL_MASK (0x60U)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_COARSE_CTRL_SHIFT (5U)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_COARSE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_COARSE_CTRL_SHIFT)) & PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_COARSE_CTRL_MASK)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_SEL_MASK (0x80U)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_SEL_SHIFT (7U)
/*! @} */
/*! @name CMN_REG067 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG067_ANA_AUX_RESERVED_MASK (0xFFU)
#define PCIE_PHY_CMN_REG067_ANA_AUX_RESERVED_SHIFT (0U)
#define PCIE_PHY_CMN_REG067_ANA_AUX_RESERVED(x)  (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG067_ANA_AUX_RESERVED_SHIFT)) & PCIE_PHY_CMN_REG067_ANA_AUX_RESERVED_MASK)
/*! @} */
/*! @name CMN_REG068 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG068_PLL_LOCK_DONE_MASK   (0x1U)
#define PCIE_PHY_CMN_REG068_PLL_LOCK_DONE_SHIFT  (0U)
#define PCIE_PHY_CMN_REG068_OVRD_PLL_LOCK_DONE_MASK (0x2U)
#define PCIE_PHY_CMN_REG068_OVRD_PLL_LOCK_DONE_SHIFT (1U)
#define PCIE_PHY_CMN_REG068_PLL_AFC_DONE_MASK    (0x4U)
#define PCIE_PHY_CMN_REG068_PLL_AFC_DONE_SHIFT   (2U)
#define PCIE_PHY_CMN_REG068_OVRD_PLL_AFC_DONE_MASK (0x8U)
#define PCIE_PHY_CMN_REG068_OVRD_PLL_AFC_DONE_SHIFT (3U)
#define PCIE_PHY_CMN_REG068_BGR_SET_DONE_MASK    (0x10U)
#define PCIE_PHY_CMN_REG068_BGR_SET_DONE_SHIFT   (4U)
#define PCIE_PHY_CMN_REG068_OVRD_BGR_SET_DONE_MASK (0x20U)
#define PCIE_PHY_CMN_REG068_OVRD_BGR_SET_DONE_SHIFT (5U)
/*! @} */
/*! @name CMN_REG069 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG069_PLL_FINE_TUNE_START_MASK (0x1U)
#define PCIE_PHY_CMN_REG069_PLL_FINE_TUNE_START_SHIFT (0U)
#define PCIE_PHY_CMN_REG069_OVRD_PLL_FINE_TUNE_START_MASK (0x2U)
#define PCIE_PHY_CMN_REG069_OVRD_PLL_FINE_TUNE_START_SHIFT (1U)
#define PCIE_PHY_CMN_REG069_HIGH_SPEED_MASK      (0x4U)
#define PCIE_PHY_CMN_REG069_HIGH_SPEED_SHIFT     (2U)
#define PCIE_PHY_CMN_REG069_OVRD_HIGH_SPEED_MASK (0x8U)
#define PCIE_PHY_CMN_REG069_OVRD_HIGH_SPEED_SHIFT (3U)
#define PCIE_PHY_CMN_REG069_PHY_MODE_MASK        (0x30U)
#define PCIE_PHY_CMN_REG069_PHY_MODE_SHIFT       (4U)
#define PCIE_PHY_CMN_REG069_PHY_MODE(x)          (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG069_PHY_MODE_SHIFT)) & PCIE_PHY_CMN_REG069_PHY_MODE_MASK)
#define PCIE_PHY_CMN_REG069_OVRD_PHY_MODE_MASK   (0x40U)
#define PCIE_PHY_CMN_REG069_OVRD_PHY_MODE_SHIFT  (6U)
/*! @} */
/*! @name CMN_REG06A -  */
/*! @{ */
#define PCIE_PHY_CMN_REG06A_TG_BGR_FAST_PULSE_TIME_MASK (0xFU)
#define PCIE_PHY_CMN_REG06A_TG_BGR_FAST_PULSE_TIME_SHIFT (0U)
#define PCIE_PHY_CMN_REG06A_TG_BGR_FAST_PULSE_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06A_TG_BGR_FAST_PULSE_TIME_SHIFT)) & PCIE_PHY_CMN_REG06A_TG_BGR_FAST_PULSE_TIME_MASK)
#define PCIE_PHY_CMN_REG06A_CMN_TIMER_SEL_MASK   (0x10U)
#define PCIE_PHY_CMN_REG06A_CMN_TIMER_SEL_SHIFT  (4U)
#define PCIE_PHY_CMN_REG06A_CMN_RATE_MASK        (0x60U)
#define PCIE_PHY_CMN_REG06A_CMN_RATE_SHIFT       (5U)
#define PCIE_PHY_CMN_REG06A_CMN_RATE(x)          (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06A_CMN_RATE_SHIFT)) & PCIE_PHY_CMN_REG06A_CMN_RATE_MASK)
#define PCIE_PHY_CMN_REG06A_OVRD_CMN_RATE_MASK   (0x80U)
#define PCIE_PHY_CMN_REG06A_OVRD_CMN_RATE_SHIFT  (7U)
/*! @} */
/*! @name CMN_REG06B -  */
/*! @{ */
#define PCIE_PHY_CMN_REG06B_TG_PLL_SDM_RSTN_DELAY_TIME_MASK (0x7U)
#define PCIE_PHY_CMN_REG06B_TG_PLL_SDM_RSTN_DELAY_TIME_SHIFT (0U)
#define PCIE_PHY_CMN_REG06B_TG_PLL_SDM_RSTN_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06B_TG_PLL_SDM_RSTN_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06B_TG_PLL_SDM_RSTN_DELAY_TIME_MASK)
#define PCIE_PHY_CMN_REG06B_TG_BGR_SET_DELAY_TIME_MASK (0x38U)
#define PCIE_PHY_CMN_REG06B_TG_BGR_SET_DELAY_TIME_SHIFT (3U)
#define PCIE_PHY_CMN_REG06B_TG_BGR_SET_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06B_TG_BGR_SET_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06B_TG_BGR_SET_DELAY_TIME_MASK)
/*! @} */
/*! @name CMN_REG06C -  */
/*! @{ */
#define PCIE_PHY_CMN_REG06C_TG_PLL_FINE_LOCK_DELAY_TIME_MASK (0x7U)
#define PCIE_PHY_CMN_REG06C_TG_PLL_FINE_LOCK_DELAY_TIME_SHIFT (0U)
#define PCIE_PHY_CMN_REG06C_TG_PLL_FINE_LOCK_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06C_TG_PLL_FINE_LOCK_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06C_TG_PLL_FINE_LOCK_DELAY_TIME_MASK)
#define PCIE_PHY_CMN_REG06C_TG_PLL_AFC_RSTN_DELAY_TIME_MASK (0x38U)
#define PCIE_PHY_CMN_REG06C_TG_PLL_AFC_RSTN_DELAY_TIME_SHIFT (3U)
#define PCIE_PHY_CMN_REG06C_TG_PLL_AFC_RSTN_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06C_TG_PLL_AFC_RSTN_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06C_TG_PLL_AFC_RSTN_DELAY_TIME_MASK)
/*! @} */
/*! @name CMN_REG06D -  */
/*! @{ */
#define PCIE_PHY_CMN_REG06D_TG_PLL_SDC_RSTN_DELAY_TIME_MASK (0x7U)
#define PCIE_PHY_CMN_REG06D_TG_PLL_SDC_RSTN_DELAY_TIME_SHIFT (0U)
#define PCIE_PHY_CMN_REG06D_TG_PLL_SDC_RSTN_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06D_TG_PLL_SDC_RSTN_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06D_TG_PLL_SDC_RSTN_DELAY_TIME_MASK)
#define PCIE_PHY_CMN_REG06D_TG_PLL_SSC_EN_DELAY_TIME_MASK (0x38U)
#define PCIE_PHY_CMN_REG06D_TG_PLL_SSC_EN_DELAY_TIME_SHIFT (3U)
#define PCIE_PHY_CMN_REG06D_TG_PLL_SSC_EN_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06D_TG_PLL_SSC_EN_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06D_TG_PLL_SSC_EN_DELAY_TIME_MASK)
/*! @} */
/*! @name CMN_REG06E -  */
/*! @{ */
#define PCIE_PHY_CMN_REG06E_TG_PLL_CD_TX_SER_RSTN_DELAY_TIME_MASK (0x7U)
#define PCIE_PHY_CMN_REG06E_TG_PLL_CD_TX_SER_RSTN_DELAY_TIME_SHIFT (0U)
#define PCIE_PHY_CMN_REG06E_TG_PLL_CD_TX_SER_RSTN_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06E_TG_PLL_CD_TX_SER_RSTN_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06E_TG_PLL_CD_TX_SER_RSTN_DELAY_TIME_MASK)
/*! @} */
/*! @name CMN_REG06F -  */
/*! @{ */
#define PCIE_PHY_CMN_REG06F_DTB_SEL_MASK         (0xFFU)
#define PCIE_PHY_CMN_REG06F_DTB_SEL_SHIFT        (0U)
#define PCIE_PHY_CMN_REG06F_DTB_SEL(x)           (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06F_DTB_SEL_SHIFT)) & PCIE_PHY_CMN_REG06F_DTB_SEL_MASK)
/*! @} */
/*! @name CMN_REG070 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG070_ANA_PLL_AFC_RING_CODE_MON_MASK (0xFU)
#define PCIE_PHY_CMN_REG070_ANA_PLL_AFC_RING_CODE_MON_SHIFT (0U)
#define PCIE_PHY_CMN_REG070_ANA_PLL_AFC_RING_CODE_MON(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG070_ANA_PLL_AFC_RING_CODE_MON_SHIFT)) & PCIE_PHY_CMN_REG070_ANA_PLL_AFC_RING_CODE_MON_MASK)
#define PCIE_PHY_CMN_REG070_ANA_PLL_AFC_LC_CODE_MON_MASK (0x30U)
#define PCIE_PHY_CMN_REG070_ANA_PLL_AFC_LC_CODE_MON_SHIFT (4U)
#define PCIE_PHY_CMN_REG070_ANA_PLL_AFC_LC_CODE_MON(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG070_ANA_PLL_AFC_LC_CODE_MON_SHIFT)) & PCIE_PHY_CMN_REG070_ANA_PLL_AFC_LC_CODE_MON_MASK)
/*! @} */
/*! @name CMN_REG071 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG071_ANA_PLL_AGMC_CODE_MON_MASK (0xFU)
#define PCIE_PHY_CMN_REG071_ANA_PLL_AGMC_CODE_MON_SHIFT (0U)
#define PCIE_PHY_CMN_REG071_ANA_PLL_AGMC_CODE_MON(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG071_ANA_PLL_AGMC_CODE_MON_SHIFT)) & PCIE_PHY_CMN_REG071_ANA_PLL_AGMC_CODE_MON_MASK)
/*! @} */
/*! @name CMN_REG072 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG072_MON_CMN_STATE_MASK   (0x1FU)
#define PCIE_PHY_CMN_REG072_MON_CMN_STATE_SHIFT  (0U)
#define PCIE_PHY_CMN_REG072_MON_CMN_STATE(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG072_MON_CMN_STATE_SHIFT)) & PCIE_PHY_CMN_REG072_MON_CMN_STATE_MASK)
/*! @} */
/*! @name CMN_REG073 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG073_MON_CMN_TIME__14_8_MASK (0x7FU)
#define PCIE_PHY_CMN_REG073_MON_CMN_TIME__14_8_SHIFT (0U)
#define PCIE_PHY_CMN_REG073_MON_CMN_TIME__14_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG073_MON_CMN_TIME__14_8_SHIFT)) & PCIE_PHY_CMN_REG073_MON_CMN_TIME__14_8_MASK)
/*! @} */
/*! @name CMN_REG074 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG074_MON_CMN_TIME__7_0_MASK (0xFFU)
#define PCIE_PHY_CMN_REG074_MON_CMN_TIME__7_0_SHIFT (0U)
#define PCIE_PHY_CMN_REG074_MON_CMN_TIME__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG074_MON_CMN_TIME__7_0_SHIFT)) & PCIE_PHY_CMN_REG074_MON_CMN_TIME__7_0_MASK)
/*! @} */
/*! @name CMN_REG075 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG075_ANA_PLL_AFC_DONE_MASK (0x1U)
#define PCIE_PHY_CMN_REG075_ANA_PLL_AFC_DONE_SHIFT (0U)
#define PCIE_PHY_CMN_REG075_ANA_PLL_LOCK_DONE_MASK (0x2U)
#define PCIE_PHY_CMN_REG075_ANA_PLL_LOCK_DONE_SHIFT (1U)
/*! @} */
/*! @name CMN_REG076 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG076_LANE0_RESET_MUX_SEL_MASK (0x3U)
#define PCIE_PHY_CMN_REG076_LANE0_RESET_MUX_SEL_SHIFT (0U)
#define PCIE_PHY_CMN_REG076_LANE0_RESET_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG076_LANE0_RESET_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG076_LANE0_RESET_MUX_SEL_MASK)
#define PCIE_PHY_CMN_REG076_LANE1_RESET_MUX_SEL_MASK (0xCU)
#define PCIE_PHY_CMN_REG076_LANE1_RESET_MUX_SEL_SHIFT (2U)
#define PCIE_PHY_CMN_REG076_LANE1_RESET_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG076_LANE1_RESET_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG076_LANE1_RESET_MUX_SEL_MASK)
#define PCIE_PHY_CMN_REG076_LANE2_RESET_MUX_SEL_MASK (0x30U)
#define PCIE_PHY_CMN_REG076_LANE2_RESET_MUX_SEL_SHIFT (4U)
#define PCIE_PHY_CMN_REG076_LANE2_RESET_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG076_LANE2_RESET_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG076_LANE2_RESET_MUX_SEL_MASK)
#define PCIE_PHY_CMN_REG076_LANE3_RESET_MUX_SEL_MASK (0xC0U)
#define PCIE_PHY_CMN_REG076_LANE3_RESET_MUX_SEL_SHIFT (6U)
#define PCIE_PHY_CMN_REG076_LANE3_RESET_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG076_LANE3_RESET_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG076_LANE3_RESET_MUX_SEL_MASK)
/*! @} */
/*! @name CMN_REG077 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG077_LANE0_SW_RESET_MASK  (0x1U)
#define PCIE_PHY_CMN_REG077_LANE0_SW_RESET_SHIFT (0U)
#define PCIE_PHY_CMN_REG077_LANE1_SW_RESET_MASK  (0x2U)
#define PCIE_PHY_CMN_REG077_LANE1_SW_RESET_SHIFT (1U)
#define PCIE_PHY_CMN_REG077_LANE2_SW_RESET_MASK  (0x4U)
#define PCIE_PHY_CMN_REG077_LANE2_SW_RESET_SHIFT (2U)
#define PCIE_PHY_CMN_REG077_LANE3_SW_RESET_MASK  (0x8U)
#define PCIE_PHY_CMN_REG077_LANE3_SW_RESET_SHIFT (3U)
#define PCIE_PHY_CMN_REG077_CMN_SW_RESET_MASK    (0x10U)
#define PCIE_PHY_CMN_REG077_CMN_SW_RESET_SHIFT   (4U)
/*! @} */
/*! @name CMN_REG078 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG078_LANE0_TX_DATA_CLK_MUX_SEL_MASK (0x3U)
#define PCIE_PHY_CMN_REG078_LANE0_TX_DATA_CLK_MUX_SEL_SHIFT (0U)
#define PCIE_PHY_CMN_REG078_LANE0_TX_DATA_CLK_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG078_LANE0_TX_DATA_CLK_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG078_LANE0_TX_DATA_CLK_MUX_SEL_MASK)
#define PCIE_PHY_CMN_REG078_LANE1_TX_DATA_CLK_MUX_SEL_MASK (0xCU)
#define PCIE_PHY_CMN_REG078_LANE1_TX_DATA_CLK_MUX_SEL_SHIFT (2U)
#define PCIE_PHY_CMN_REG078_LANE1_TX_DATA_CLK_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG078_LANE1_TX_DATA_CLK_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG078_LANE1_TX_DATA_CLK_MUX_SEL_MASK)
#define PCIE_PHY_CMN_REG078_LANE2_TX_DATA_CLK_MUX_SEL_MASK (0x30U)
#define PCIE_PHY_CMN_REG078_LANE2_TX_DATA_CLK_MUX_SEL_SHIFT (4U)
#define PCIE_PHY_CMN_REG078_LANE2_TX_DATA_CLK_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG078_LANE2_TX_DATA_CLK_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG078_LANE2_TX_DATA_CLK_MUX_SEL_MASK)
#define PCIE_PHY_CMN_REG078_LANE3_TX_DATA_CLK_MUX_SEL_MASK (0xC0U)
#define PCIE_PHY_CMN_REG078_LANE3_TX_DATA_CLK_MUX_SEL_SHIFT (6U)
#define PCIE_PHY_CMN_REG078_LANE3_TX_DATA_CLK_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG078_LANE3_TX_DATA_CLK_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG078_LANE3_TX_DATA_CLK_MUX_SEL_MASK)
/*! @} */
/*! @name CMN_REG079 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG079_CMN_RESET_CONTROL_MASK (0x1U)
#define PCIE_PHY_CMN_REG079_CMN_RESET_CONTROL_SHIFT (0U)
/*! @} */
/*! @name CMN_REG080 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG080_RATE_CHANGE_DELAY_MASK (0xFFU)
#define PCIE_PHY_CMN_REG080_RATE_CHANGE_DELAY_SHIFT (0U)
#define PCIE_PHY_CMN_REG080_RATE_CHANGE_DELAY(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG080_RATE_CHANGE_DELAY_SHIFT)) & PCIE_PHY_CMN_REG080_RATE_CHANGE_DELAY_MASK)
/*! @} */
/*! @name CMN_REG081 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG081_RX_EFOM_ERROR_TH_7_0_MASK (0xFFU)
#define PCIE_PHY_CMN_REG081_RX_EFOM_ERROR_TH_7_0_SHIFT (0U)
#define PCIE_PHY_CMN_REG081_RX_EFOM_ERROR_TH_7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG081_RX_EFOM_ERROR_TH_7_0_SHIFT)) & PCIE_PHY_CMN_REG081_RX_EFOM_ERROR_TH_7_0_MASK)
/*! @} */
/*! @name CMN_REG082 -  */
/*! @{ */
#define PCIE_PHY_CMN_REG082_RX_EFOM_ERROR_TH_9_8_MASK (0x3U)
#define PCIE_PHY_CMN_REG082_RX_EFOM_ERROR_TH_9_8_SHIFT (0U)
#define PCIE_PHY_CMN_REG082_RX_EFOM_ERROR_TH_9_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG082_RX_EFOM_ERROR_TH_9_8_SHIFT)) & PCIE_PHY_CMN_REG082_RX_EFOM_ERROR_TH_9_8_MASK)
/*! @} */
/*! @name TRSV_REG000 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EI_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EI_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EI_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EI_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_CM_KEEPER_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_CM_KEEPER_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_CM_KEEPER_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_CM_KEEPER_EN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_BEACON_LFPS_OUT_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_BEACON_LFPS_OUT_EN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_BEACON_LFPS_OUT_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_BEACON_LFPS_OUT_EN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EN_MASK  (0x40U)
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EN_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG001 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG001_LN0_TX_DRV_LVL_CTRL_G1_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG001_LN0_TX_DRV_LVL_CTRL_G1_SHIFT (0U)
#define PCIE_PHY_TRSV_REG001_LN0_TX_DRV_LVL_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG001_LN0_TX_DRV_LVL_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG001_LN0_TX_DRV_LVL_CTRL_G1_MASK)
#define PCIE_PHY_TRSV_REG001_LN0_OVRD_TX_DRV_LVL_CTRL_MASK (0x20U)
#define PCIE_PHY_TRSV_REG001_LN0_OVRD_TX_DRV_LVL_CTRL_SHIFT (5U)
/*! @} */
/*! @name TRSV_REG002 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG002_LN0_TX_DRV_LVL_CTRL_G2_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG002_LN0_TX_DRV_LVL_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG002_LN0_TX_DRV_LVL_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG002_LN0_TX_DRV_LVL_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG002_LN0_TX_DRV_LVL_CTRL_G2_MASK)
/*! @} */
/*! @name TRSV_REG003 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG003_LN0_TX_DRV_LVL_CTRL_G3_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG003_LN0_TX_DRV_LVL_CTRL_G3_SHIFT (0U)
#define PCIE_PHY_TRSV_REG003_LN0_TX_DRV_LVL_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG003_LN0_TX_DRV_LVL_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG003_LN0_TX_DRV_LVL_CTRL_G3_MASK)
/*! @} */
/*! @name TRSV_REG004 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG004_LN0_TX_DRV_LVL_CTRL_G4_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG004_LN0_TX_DRV_LVL_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG004_LN0_TX_DRV_LVL_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG004_LN0_TX_DRV_LVL_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG004_LN0_TX_DRV_LVL_CTRL_G4_MASK)
/*! @} */
/*! @name TRSV_REG005 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG005_LN0_TX_DRV_POST_LVL_CTRL_G1_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG005_LN0_TX_DRV_POST_LVL_CTRL_G1_SHIFT (0U)
#define PCIE_PHY_TRSV_REG005_LN0_TX_DRV_POST_LVL_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG005_LN0_TX_DRV_POST_LVL_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG005_LN0_TX_DRV_POST_LVL_CTRL_G1_MASK)
#define PCIE_PHY_TRSV_REG005_LN0_OVRD_TX_DRV_POST_LVL_CTRL_MASK (0x20U)
#define PCIE_PHY_TRSV_REG005_LN0_OVRD_TX_DRV_POST_LVL_CTRL_SHIFT (5U)
/*! @} */
/*! @name TRSV_REG006 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG006_LN0_TX_DRV_POST_LVL_CTRL_G2_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG006_LN0_TX_DRV_POST_LVL_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG006_LN0_TX_DRV_POST_LVL_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG006_LN0_TX_DRV_POST_LVL_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG006_LN0_TX_DRV_POST_LVL_CTRL_G2_MASK)
/*! @} */
/*! @name TRSV_REG007 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG007_LN0_TX_DRV_POST_LVL_CTRL_G3_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG007_LN0_TX_DRV_POST_LVL_CTRL_G3_SHIFT (0U)
#define PCIE_PHY_TRSV_REG007_LN0_TX_DRV_POST_LVL_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG007_LN0_TX_DRV_POST_LVL_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG007_LN0_TX_DRV_POST_LVL_CTRL_G3_MASK)
/*! @} */
/*! @name TRSV_REG008 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG008_LN0_TX_DRV_POST_LVL_CTRL_G4_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG008_LN0_TX_DRV_POST_LVL_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG008_LN0_TX_DRV_POST_LVL_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG008_LN0_TX_DRV_POST_LVL_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG008_LN0_TX_DRV_POST_LVL_CTRL_G4_MASK)
/*! @} */
/*! @name TRSV_REG009 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG009_LN0_TX_DRV_PRE_LVL_CTRL_G1_MASK (0xFU)
#define PCIE_PHY_TRSV_REG009_LN0_TX_DRV_PRE_LVL_CTRL_G1_SHIFT (0U)
#define PCIE_PHY_TRSV_REG009_LN0_TX_DRV_PRE_LVL_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG009_LN0_TX_DRV_PRE_LVL_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG009_LN0_TX_DRV_PRE_LVL_CTRL_G1_MASK)
#define PCIE_PHY_TRSV_REG009_LN0_OVRD_TX_DRV_PRE_LVL_CTRL_MASK (0x10U)
#define PCIE_PHY_TRSV_REG009_LN0_OVRD_TX_DRV_PRE_LVL_CTRL_SHIFT (4U)
/*! @} */
/*! @name TRSV_REG00A -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G3_MASK (0xFU)
#define PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G3_SHIFT (0U)
#define PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G3_MASK)
#define PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G2_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G2_SHIFT (4U)
#define PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G2_MASK)
/*! @} */
/*! @name TRSV_REG00B -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_IDRV_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_IDRV_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG00B_LN0_OVRD_TX_DRV_IDRV_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG00B_LN0_OVRD_TX_DRV_IDRV_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG00B_LN0_ANA_TX_DRV_BEACON_LFPS_SYNC_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG00B_LN0_ANA_TX_DRV_BEACON_LFPS_SYNC_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_PRE_LVL_CTRL_G4_MASK (0x78U)
#define PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_PRE_LVL_CTRL_G4_SHIFT (3U)
#define PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_PRE_LVL_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_PRE_LVL_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_PRE_LVL_CTRL_G4_MASK)
/*! @} */
/*! @name TRSV_REG00C -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_ACCDRV_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_ACCDRV_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_VREF_SEL_MASK (0x2U)
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_VREF_SEL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IUP_CTRL_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IUP_CTRL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IUP_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IUP_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IUP_CTRL_MASK)
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IDN_CTRL_MASK (0xE0U)
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IDN_CTRL_SHIFT (5U)
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IDN_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IDN_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IDN_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG00D -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG00D_LN0_RX_VALID_RSTN_DELAY_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG00D_LN0_RX_VALID_RSTN_DELAY_SHIFT (0U)
#define PCIE_PHY_TRSV_REG00D_LN0_RX_VALID_RSTN_DELAY(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00D_LN0_RX_VALID_RSTN_DELAY_SHIFT)) & PCIE_PHY_TRSV_REG00D_LN0_RX_VALID_RSTN_DELAY_MASK)
/*! @} */
/*! @name TRSV_REG00E -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G4_MASK (0x3U)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G4_SHIFT)) & PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G4_MASK)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G3_MASK (0xCU)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G3_SHIFT (2U)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G3_SHIFT)) & PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G3_MASK)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G2_MASK (0x30U)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G2_SHIFT (4U)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G2_SHIFT)) & PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G2_MASK)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G1_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G1_SHIFT (6U)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G1_SHIFT)) & PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G1_MASK)
/*! @} */
/*! @name TRSV_REG00F -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_PLL_REF_MON_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_PLL_REF_MON_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_HSCLK_MON_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_HSCLK_MON_EN_SHIFT (1U)
/*! @} */
/*! @name TRSV_REG010 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G2_MASK)
#define PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G1_MASK)
/*! @} */
/*! @name TRSV_REG011 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G4_MASK)
#define PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G3_MASK)
/*! @} */
/*! @name TRSV_REG012 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG012_LN0_ANA_TX_JEQ_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG012_LN0_ANA_TX_JEQ_EN_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG013 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G2_MASK)
#define PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G1_MASK)
/*! @} */
/*! @name TRSV_REG014 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G4_MASK)
#define PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G3_MASK)
/*! @} */
/*! @name TRSV_REG015 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G2_MASK)
#define PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G1_MASK)
/*! @} */
/*! @name TRSV_REG016 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G4_MASK)
#define PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G3_MASK)
/*! @} */
/*! @name TRSV_REG017 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG017_LN0_ANA_TX_RCAL_IRMRES_CTRL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG017_LN0_ANA_TX_RCAL_IRMRES_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG017_LN0_ANA_TX_RCAL_IRMRES_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG017_LN0_ANA_TX_RCAL_IRMRES_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG017_LN0_ANA_TX_RCAL_IRMRES_CTRL_MASK)
#define PCIE_PHY_TRSV_REG017_LN0_TX_RCAL_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG017_LN0_TX_RCAL_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG017_LN0_OVRD_TX_RCAL_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG017_LN0_OVRD_TX_RCAL_EN_SHIFT (3U)
/*! @} */
/*! @name TRSV_REG018 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG018_LN0_TX_RXD_EN_MASK  (0x1U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RXD_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RXD_COMP_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RXD_COMP_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_COMP_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_COMP_EN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G4_MASK (0x10U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G4_SHIFT (4U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G3_MASK (0x20U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G3_SHIFT (5U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G2_MASK (0x40U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G2_SHIFT (6U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G1_MASK (0x80U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G1_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG019 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG019_LN0_ANA_TX_RXD_COMP_I_CTRL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG019_LN0_ANA_TX_RXD_COMP_I_CTRL_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG01A -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_DATA_RSTN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_DATA_RSTN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG01A_LN0_OVRD_TX_SER_DATA_RSTN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG01A_LN0_OVRD_TX_SER_DATA_RSTN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G4_MASK (0x4U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G4_SHIFT (2U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G3_MASK (0x8U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G3_SHIFT (3U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G2_MASK (0x10U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G2_SHIFT (4U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G1_MASK (0x20U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G1_SHIFT (5U)
/*! @} */
/*! @name TRSV_REG01B -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_SER_TXCLK_INV_MASK (0x1U)
#define PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_SER_TXCLK_INV_SHIFT (0U)
#define PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_CDR_CLK_MON_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_CDR_CLK_MON_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_CLK_RSTN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_CLK_RSTN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG01B_LN0_OVRD_TX_SER_CLK_RSTN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG01B_LN0_OVRD_TX_SER_CLK_RSTN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G4_MASK (0x10U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G4_SHIFT (4U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G3_MASK (0x20U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G3_SHIFT (5U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G2_MASK (0x40U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G2_SHIFT (6U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G1_MASK (0x80U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G1_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG01C -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_SEL_MASK (0x3EU)
#define PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_SEL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_SEL_SHIFT)) & PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_SEL_MASK)
/*! @} */
/*! @name TRSV_REG01D -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SRLB_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SRLB_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_LLB_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_LLB_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SLB_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SLB_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_BIAS_RMRES_CTRL_MASK (0x38U)
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_BIAS_RMRES_CTRL_SHIFT (3U)
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_BIAS_RMRES_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_BIAS_RMRES_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_BIAS_RMRES_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG01E -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG01E_LN0_ANA_TX_RESERVED_MASK (0xFU)
#define PCIE_PHY_TRSV_REG01E_LN0_ANA_TX_RESERVED_SHIFT (0U)
#define PCIE_PHY_TRSV_REG01E_LN0_ANA_TX_RESERVED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01E_LN0_ANA_TX_RESERVED_SHIFT)) & PCIE_PHY_TRSV_REG01E_LN0_ANA_TX_RESERVED_MASK)
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G4_MASK (0x10U)
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G4_SHIFT (4U)
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G3_MASK (0x20U)
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G3_SHIFT (5U)
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G2_MASK (0x40U)
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G2_SHIFT (6U)
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G1_MASK (0x80U)
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G1_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG01F -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_MODE_CTRL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_MODE_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_MODE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_MODE_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_MODE_CTRL_MASK)
#define PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_MODE_CTRL_MASK (0x4U)
#define PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_MODE_CTRL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_EN_MASK  (0x8U)
#define PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_EN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_EN_SHIFT (4U)
/*! @} */
/*! @name TRSV_REG020 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G2_SHIFT)) & PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G2_MASK)
#define PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G1_SHIFT)) & PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G1_MASK)
/*! @} */
/*! @name TRSV_REG021 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G4_SHIFT)) & PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G4_MASK)
#define PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G3_SHIFT)) & PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G3_MASK)
/*! @} */
/*! @name TRSV_REG022 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G2_SHIFT)) & PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G2_MASK)
#define PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G1_SHIFT)) & PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G1_MASK)
/*! @} */
/*! @name TRSV_REG023 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G4_SHIFT)) & PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G4_MASK)
#define PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G3_SHIFT)) & PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G3_MASK)
/*! @} */
/*! @name TRSV_REG024 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G2_SHIFT)) & PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G2_MASK)
#define PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G1_SHIFT)) & PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G1_MASK)
/*! @} */
/*! @name TRSV_REG025 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G4_SHIFT)) & PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G4_MASK)
#define PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G3_SHIFT)) & PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G3_MASK)
/*! @} */
/*! @name TRSV_REG026 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G2_SHIFT)) & PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G2_MASK)
#define PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G1_SHIFT)) & PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G1_MASK)
/*! @} */
/*! @name TRSV_REG027 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G4_SHIFT)) & PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G4_MASK)
#define PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G3_SHIFT)) & PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G3_MASK)
/*! @} */
/*! @name TRSV_REG028 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_VCI_FORCE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_VCI_FORCE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_TEST_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_TEST_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_DES_RXCLK_INV_MASK (0x8U)
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_DES_RXCLK_INV_SHIFT (3U)
#define PCIE_PHY_TRSV_REG028_LN0_RX_CDR_BW_CTRL_MASK (0x10U)
#define PCIE_PHY_TRSV_REG028_LN0_RX_CDR_BW_CTRL_SHIFT (4U)
#define PCIE_PHY_TRSV_REG028_LN0_OVRD_RX_CDR_BW_CTRL_MASK (0x20U)
#define PCIE_PHY_TRSV_REG028_LN0_OVRD_RX_CDR_BW_CTRL_SHIFT (5U)
/*! @} */
/*! @name TRSV_REG029 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_E_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_E_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_CTRL_MASK (0xEU)
#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_CTRL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_CTRL_MASK)
#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_AFC_VCI_SUPPLY_SEL_MASK (0x10U)
#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_AFC_VCI_SUPPLY_SEL_SHIFT (4U)
/*! @} */
/*! @name TRSV_REG02A -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_VCO_STARTUP_MASK (0x1U)
#define PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_VCO_STARTUP_SHIFT (0U)
#define PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_VCO_STARTUP_MASK (0x2U)
#define PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_VCO_STARTUP_SHIFT (1U)
#define PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_FBB_CAL_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_FBB_CAL_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_FBB_CAL_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_FBB_CAL_EN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_LPF_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_LPF_EN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_IN_SEL_MASK (0x20U)
#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_IN_SEL_SHIFT (5U)
#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_O_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_O_EN_SHIFT (6U)
/*! @} */
/*! @name TRSV_REG02B -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG02B_LN0_ANA_RX_CDR_VCO_BBCAP_DN_CTRL_MASK (0xFU)
#define PCIE_PHY_TRSV_REG02B_LN0_ANA_RX_CDR_VCO_BBCAP_DN_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG02B_LN0_ANA_RX_CDR_VCO_BBCAP_DN_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02B_LN0_ANA_RX_CDR_VCO_BBCAP_DN_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG02B_LN0_ANA_RX_CDR_VCO_BBCAP_DN_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG02C -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G4_MASK (0x1U)
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G3_MASK (0x2U)
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G3_SHIFT (1U)
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G2_MASK (0x4U)
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G2_SHIFT (2U)
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G1_MASK (0x8U)
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G1_SHIFT (3U)
/*! @} */
/*! @name TRSV_REG02D -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G2_MASK (0x7U)
#define PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G2_SHIFT)) & PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G2_MASK)
#define PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G1_MASK (0x38U)
#define PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G1_SHIFT (3U)
#define PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G1_SHIFT)) & PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G1_MASK)
/*! @} */
/*! @name TRSV_REG02E -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CTLE_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CTLE_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG02E_LN0_OVRD_RX_CTLE_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG02E_LN0_OVRD_RX_CTLE_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G4_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G4_SHIFT (2U)
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G4_SHIFT)) & PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G4_MASK)
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G3_MASK (0xE0U)
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G3_SHIFT (5U)
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G3_SHIFT)) & PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G3_MASK)
/*! @} */
/*! @name TRSV_REG02F -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G4_MASK (0x1U)
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G3_MASK (0x2U)
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G3_SHIFT (1U)
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G2_MASK (0x4U)
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G2_SHIFT (2U)
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G1_MASK (0x8U)
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G1_SHIFT (3U)
/*! @} */
/*! @name TRSV_REG030 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG030_LN0_RX_CTLE_ITAIL_CTRL_G1_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG030_LN0_RX_CTLE_ITAIL_CTRL_G1_SHIFT (0U)
#define PCIE_PHY_TRSV_REG030_LN0_RX_CTLE_ITAIL_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG030_LN0_RX_CTLE_ITAIL_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG030_LN0_RX_CTLE_ITAIL_CTRL_G1_MASK)
/*! @} */
/*! @name TRSV_REG031 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG031_LN0_RX_CTLE_ITAIL_CTRL_G2_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG031_LN0_RX_CTLE_ITAIL_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG031_LN0_RX_CTLE_ITAIL_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG031_LN0_RX_CTLE_ITAIL_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG031_LN0_RX_CTLE_ITAIL_CTRL_G2_MASK)
/*! @} */
/*! @name TRSV_REG032 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG032_LN0_RX_CTLE_ITAIL_CTRL_G3_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG032_LN0_RX_CTLE_ITAIL_CTRL_G3_SHIFT (0U)
#define PCIE_PHY_TRSV_REG032_LN0_RX_CTLE_ITAIL_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG032_LN0_RX_CTLE_ITAIL_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG032_LN0_RX_CTLE_ITAIL_CTRL_G3_MASK)
/*! @} */
/*! @name TRSV_REG033 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG033_LN0_RX_CTLE_ITAIL_CTRL_G4_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG033_LN0_RX_CTLE_ITAIL_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG033_LN0_RX_CTLE_ITAIL_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG033_LN0_RX_CTLE_ITAIL_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG033_LN0_RX_CTLE_ITAIL_CTRL_G4_MASK)
/*! @} */
/*! @name TRSV_REG034 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG034_LN0_RX_CTLE_OC_CODE_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG034_LN0_RX_CTLE_OC_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG034_LN0_RX_CTLE_OC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG034_LN0_RX_CTLE_OC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG034_LN0_RX_CTLE_OC_CODE_MASK)
#define PCIE_PHY_TRSV_REG034_LN0_OVRD_RX_CTLE_OC_CODE_MASK (0x80U)
#define PCIE_PHY_TRSV_REG034_LN0_OVRD_RX_CTLE_OC_CODE_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG035 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG035_LN0_RX_CTLE_OC_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG035_LN0_RX_CTLE_OC_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG035_LN0_OVRD_RX_CTLE_OC_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG035_LN0_OVRD_RX_CTLE_OC_EN_SHIFT (1U)
/*! @} */
/*! @name TRSV_REG036 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G4_MASK (0x1U)
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G3_MASK (0x2U)
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G3_SHIFT (1U)
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G2_MASK (0x4U)
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G2_SHIFT (2U)
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G1_MASK (0x8U)
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G1_SHIFT (3U)
/*! @} */
/*! @name TRSV_REG037 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG037_LN0_RX_CTLE_RL_CTRL_G1_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG037_LN0_RX_CTLE_RL_CTRL_G1_SHIFT (0U)
#define PCIE_PHY_TRSV_REG037_LN0_RX_CTLE_RL_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG037_LN0_RX_CTLE_RL_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG037_LN0_RX_CTLE_RL_CTRL_G1_MASK)
/*! @} */
/*! @name TRSV_REG038 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG038_LN0_RX_CTLE_RL_CTRL_G2_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG038_LN0_RX_CTLE_RL_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG038_LN0_RX_CTLE_RL_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG038_LN0_RX_CTLE_RL_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG038_LN0_RX_CTLE_RL_CTRL_G2_MASK)
/*! @} */
/*! @name TRSV_REG039 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG039_LN0_RX_CTLE_RL_CTRL_G3_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG039_LN0_RX_CTLE_RL_CTRL_G3_SHIFT (0U)
#define PCIE_PHY_TRSV_REG039_LN0_RX_CTLE_RL_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG039_LN0_RX_CTLE_RL_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG039_LN0_RX_CTLE_RL_CTRL_G3_MASK)
/*! @} */
/*! @name TRSV_REG03A -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG03A_LN0_RX_CTLE_RL_CTRL_G4_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG03A_LN0_RX_CTLE_RL_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG03A_LN0_RX_CTLE_RL_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03A_LN0_RX_CTLE_RL_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG03A_LN0_RX_CTLE_RL_CTRL_G4_MASK)
/*! @} */
/*! @name TRSV_REG03B -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG03B_LN0_RX_CTLE_RS1_CTRL_G1_MASK (0xFU)
#define PCIE_PHY_TRSV_REG03B_LN0_RX_CTLE_RS1_CTRL_G1_SHIFT (0U)
#define PCIE_PHY_TRSV_REG03B_LN0_RX_CTLE_RS1_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03B_LN0_RX_CTLE_RS1_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG03B_LN0_RX_CTLE_RS1_CTRL_G1_MASK)
#define PCIE_PHY_TRSV_REG03B_LN0_OVRD_RX_CTLE_RS1_CTRL_MASK (0x10U)
#define PCIE_PHY_TRSV_REG03B_LN0_OVRD_RX_CTLE_RS1_CTRL_SHIFT (4U)
/*! @} */
/*! @name TRSV_REG03C -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G3_MASK (0xFU)
#define PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G3_SHIFT (0U)
#define PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G3_MASK)
#define PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G2_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G2_SHIFT (4U)
#define PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G2_MASK)
/*! @} */
/*! @name TRSV_REG03D -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG03D_LN0_RX_CTLE_RS1_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG03D_LN0_RX_CTLE_RS1_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG03D_LN0_RX_CTLE_RS1_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03D_LN0_RX_CTLE_RS1_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG03D_LN0_RX_CTLE_RS1_CTRL_G4_MASK)
/*! @} */
/*! @name TRSV_REG03E -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG03E_LN0_RX_CTLE_RS2_CTRL_G1_MASK (0xFU)
#define PCIE_PHY_TRSV_REG03E_LN0_RX_CTLE_RS2_CTRL_G1_SHIFT (0U)
#define PCIE_PHY_TRSV_REG03E_LN0_RX_CTLE_RS2_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03E_LN0_RX_CTLE_RS2_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG03E_LN0_RX_CTLE_RS2_CTRL_G1_MASK)
#define PCIE_PHY_TRSV_REG03E_LN0_OVRD_RX_CTLE_RS2_CTRL_MASK (0x10U)
#define PCIE_PHY_TRSV_REG03E_LN0_OVRD_RX_CTLE_RS2_CTRL_SHIFT (4U)
/*! @} */
/*! @name TRSV_REG03F -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G3_MASK (0xFU)
#define PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G3_SHIFT (0U)
#define PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G3_MASK)
#define PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G2_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G2_SHIFT (4U)
#define PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G2_MASK)
/*! @} */
/*! @name TRSV_REG040 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG040_LN0_RX_CTLE_RS2_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG040_LN0_RX_CTLE_RS2_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG040_LN0_RX_CTLE_RS2_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG040_LN0_RX_CTLE_RS2_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG040_LN0_RX_CTLE_RS2_CTRL_G4_MASK)
/*! @} */
/*! @name TRSV_REG041 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G4_MASK (0x1U)
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G3_MASK (0x2U)
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G3_SHIFT (1U)
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G2_MASK (0x4U)
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G2_SHIFT (2U)
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G1_MASK (0x8U)
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G1_SHIFT (3U)
/*! @} */
/*! @name TRSV_REG042 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G2_MASK)
#define PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G1_MASK)
/*! @} */
/*! @name TRSV_REG043 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G4_MASK)
#define PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G3_MASK)
/*! @} */
/*! @name TRSV_REG044 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G4_MASK (0x3U)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G4_SHIFT)) & PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G4_MASK)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G3_MASK (0xCU)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G3_SHIFT (2U)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G3_SHIFT)) & PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G3_MASK)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G2_MASK (0x30U)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G2_SHIFT (4U)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G2_SHIFT)) & PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G2_MASK)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G1_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G1_SHIFT (6U)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G1_SHIFT)) & PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G1_MASK)
/*! @} */
/*! @name TRSV_REG045 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG045_LN0_ANA_RX_CTLE_IBLEED_CTRL_MASK (0x7U)
#define PCIE_PHY_TRSV_REG045_LN0_ANA_RX_CTLE_IBLEED_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG045_LN0_ANA_RX_CTLE_IBLEED_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG045_LN0_ANA_RX_CTLE_IBLEED_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG045_LN0_ANA_RX_CTLE_IBLEED_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG046 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G2_SHIFT)) & PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G2_MASK)
#define PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G1_SHIFT)) & PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G1_MASK)
/*! @} */
/*! @name TRSV_REG047 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G4_SHIFT)) & PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G4_MASK)
#define PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G3_SHIFT)) & PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G3_MASK)
/*! @} */
/*! @name TRSV_REG048 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G2_MASK)
#define PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G1_MASK)
/*! @} */
/*! @name TRSV_REG049 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G4_MASK)
#define PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G3_MASK)
/*! @} */
/*! @name TRSV_REG04A -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG04A_LN0_ANA_RX_CTLE_VCM_SEL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG04A_LN0_ANA_RX_CTLE_VCM_SEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG04A_LN0_ANA_RX_CTLE_VCM_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04A_LN0_ANA_RX_CTLE_VCM_SEL_SHIFT)) & PCIE_PHY_TRSV_REG04A_LN0_ANA_RX_CTLE_VCM_SEL_MASK)
/*! @} */
/*! @name TRSV_REG04B -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G4_MASK (0x3U)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G4_MASK)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G3_MASK (0xCU)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G3_SHIFT (2U)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G3_MASK)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G2_MASK (0x30U)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G2_SHIFT (4U)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G2_MASK)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G1_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G1_SHIFT (6U)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G1_MASK)
/*! @} */
/*! @name TRSV_REG04C -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G2_MASK (0x7U)
#define PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G2_MASK)
#define PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G1_MASK (0x38U)
#define PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G1_SHIFT (3U)
#define PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G1_MASK)
/*! @} */
/*! @name TRSV_REG04D -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G4_MASK (0x7U)
#define PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G4_MASK)
#define PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G3_MASK (0x38U)
#define PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G3_SHIFT (3U)
#define PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G3_MASK)
/*! @} */
/*! @name TRSV_REG04E -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G4_MASK (0x3U)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G4_MASK)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G3_MASK (0xCU)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G3_SHIFT (2U)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G3_MASK)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G2_MASK (0x30U)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G2_SHIFT (4U)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G2_MASK)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G1_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G1_SHIFT (6U)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G1_MASK)
/*! @} */
/*! @name TRSV_REG04F -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_PTAT_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_PTAT_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VREG_SEL_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VREG_SEL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VREG_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VREG_SEL_SHIFT)) & PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VREG_SEL_MASK)
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VGA_CTRL_MASK (0xE0U)
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VGA_CTRL_SHIFT (5U)
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VGA_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VGA_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VGA_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG050 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG050_LN0_RX_DES_DATA_CLEAR_MASK (0x1U)
#define PCIE_PHY_TRSV_REG050_LN0_RX_DES_DATA_CLEAR_SHIFT (0U)
#define PCIE_PHY_TRSV_REG050_LN0_OVRD_RX_DES_DATA_CLEAR_MASK (0x2U)
#define PCIE_PHY_TRSV_REG050_LN0_OVRD_RX_DES_DATA_CLEAR_SHIFT (1U)
#define PCIE_PHY_TRSV_REG050_LN0_ANA_RX_CTLE_RESERVED_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG050_LN0_ANA_RX_CTLE_RESERVED_SHIFT (2U)
#define PCIE_PHY_TRSV_REG050_LN0_ANA_RX_CTLE_RESERVED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG050_LN0_ANA_RX_CTLE_RESERVED_SHIFT)) & PCIE_PHY_TRSV_REG050_LN0_ANA_RX_CTLE_RESERVED_MASK)
/*! @} */
/*! @name TRSV_REG051 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G4_MASK (0x3U)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G4_SHIFT)) & PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G4_MASK)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G3_MASK (0xCU)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G3_SHIFT (2U)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G3_SHIFT)) & PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G3_MASK)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G2_MASK (0x30U)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G2_SHIFT (4U)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G2_SHIFT)) & PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G2_MASK)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G1_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G1_SHIFT (6U)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G1_SHIFT)) & PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G1_MASK)
/*! @} */
/*! @name TRSV_REG052 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG052_LN0_ANA_RX_DES_DATA_CLEAR_DELAY_SEL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG052_LN0_ANA_RX_DES_DATA_CLEAR_DELAY_SEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG052_LN0_ANA_RX_DES_DATA_CLEAR_DELAY_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG052_LN0_ANA_RX_DES_DATA_CLEAR_DELAY_SEL_SHIFT)) & PCIE_PHY_TRSV_REG052_LN0_ANA_RX_DES_DATA_CLEAR_DELAY_SEL_MASK)
#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_RSTN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_RSTN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_RSTN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_RSTN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_NON_DATA_SEL_MASK (0x10U)
#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_NON_DATA_SEL_SHIFT (4U)
#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_NON_DATA_SEL_MASK (0x20U)
#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_NON_DATA_SEL_SHIFT (5U)
#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_EN_MASK  (0x40U)
#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_EN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_EN_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG053 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG053_LN0_ANA_RX_DFE_EOM_PI_DIV_SEL_MASK (0x7U)
#define PCIE_PHY_TRSV_REG053_LN0_ANA_RX_DFE_EOM_PI_DIV_SEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG053_LN0_ANA_RX_DFE_EOM_PI_DIV_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG053_LN0_ANA_RX_DFE_EOM_PI_DIV_SEL_SHIFT)) & PCIE_PHY_TRSV_REG053_LN0_ANA_RX_DFE_EOM_PI_DIV_SEL_MASK)
#define PCIE_PHY_TRSV_REG053_LN0_RX_DFE_EOM_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG053_LN0_RX_DFE_EOM_EN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_EOM_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_EOM_EN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG053_LN0_RX_DFE_ADAP_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG053_LN0_RX_DFE_ADAP_EN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_ADAP_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_ADAP_EN_SHIFT (6U)
/*! @} */
/*! @name TRSV_REG054 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG054_LN0_ANA_RX_DFE_EOM_PI_STR_CTRL_MASK (0xFU)
#define PCIE_PHY_TRSV_REG054_LN0_ANA_RX_DFE_EOM_PI_STR_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG054_LN0_ANA_RX_DFE_EOM_PI_STR_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG054_LN0_ANA_RX_DFE_EOM_PI_STR_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG054_LN0_ANA_RX_DFE_EOM_PI_STR_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG055 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG055_LN0_RX_DFE_OC_ADDER_EVEN_CODE_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG055_LN0_RX_DFE_OC_ADDER_EVEN_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG055_LN0_RX_DFE_OC_ADDER_EVEN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG055_LN0_RX_DFE_OC_ADDER_EVEN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG055_LN0_RX_DFE_OC_ADDER_EVEN_CODE_MASK)
#define PCIE_PHY_TRSV_REG055_LN0_OVRD_RX_DFE_OC_ADDER_EVEN_CODE_MASK (0x80U)
#define PCIE_PHY_TRSV_REG055_LN0_OVRD_RX_DFE_OC_ADDER_EVEN_CODE_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG056 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG056_LN0_RX_DFE_OC_ADDER_ODD_CODE_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG056_LN0_RX_DFE_OC_ADDER_ODD_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG056_LN0_RX_DFE_OC_ADDER_ODD_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG056_LN0_RX_DFE_OC_ADDER_ODD_CODE_SHIFT)) & PCIE_PHY_TRSV_REG056_LN0_RX_DFE_OC_ADDER_ODD_CODE_MASK)
#define PCIE_PHY_TRSV_REG056_LN0_OVRD_RX_DFE_OC_ADDER_ODD_CODE_MASK (0x80U)
#define PCIE_PHY_TRSV_REG056_LN0_OVRD_RX_DFE_OC_ADDER_ODD_CODE_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG057 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_EDGE_EVEN_CODE_MASK (0x7U)
#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_EDGE_EVEN_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_EDGE_EVEN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_EDGE_EVEN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_EDGE_EVEN_CODE_MASK)
#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_EDGE_EVEN_CODE_MASK (0x8U)
#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_EDGE_EVEN_CODE_SHIFT (3U)
#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_ODD_CODE_MASK (0x10U)
#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_ODD_CODE_SHIFT (4U)
#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_ODD_CODE_MASK (0x20U)
#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_ODD_CODE_SHIFT (5U)
#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_EVEN_CODE_MASK (0x40U)
#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_EVEN_CODE_SHIFT (6U)
#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_EVEN_CODE_MASK (0x80U)
#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_EVEN_CODE_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG058 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_ERR_EVEN_CODE_MASK (0x7U)
#define PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_ERR_EVEN_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_ERR_EVEN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_ERR_EVEN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_ERR_EVEN_CODE_MASK)
#define PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_ERR_EVEN_CODE_MASK (0x8U)
#define PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_ERR_EVEN_CODE_SHIFT (3U)
#define PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_EDGE_ODD_CODE_MASK (0x70U)
#define PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_EDGE_ODD_CODE_SHIFT (4U)
#define PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_EDGE_ODD_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_EDGE_ODD_CODE_SHIFT)) & PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_EDGE_ODD_CODE_MASK)
#define PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_EDGE_ODD_CODE_MASK (0x80U)
#define PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_EDGE_ODD_CODE_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG059 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_DAC_ERR_ODD_CODE_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_DAC_ERR_ODD_CODE_SHIFT (2U)
#define PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_DAC_ERR_ODD_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_DAC_ERR_ODD_CODE_SHIFT)) & PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_DAC_ERR_ODD_CODE_MASK)
#define PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_DAC_ERR_ODD_CODE_MASK (0x20U)
#define PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_DAC_ERR_ODD_CODE_SHIFT (5U)
/*! @} */
/*! @name TRSV_REG05A -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG05A_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG05A_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG05A_LN0_OVRD_RX_DFE_OC_SA_EDGE_EVEN_CODE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG05A_LN0_OVRD_RX_DFE_OC_SA_EDGE_EVEN_CODE_SHIFT (1U)
/*! @} */
/*! @name TRSV_REG05B -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG05B_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG05B_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG05B_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG05B_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__7_0_SHIFT)) & PCIE_PHY_TRSV_REG05B_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__7_0_MASK)
/*! @} */
/*! @name TRSV_REG05C -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG05C_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG05C_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG05C_LN0_OVRD_RX_DFE_OC_SA_EDGE_ODD_CODE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG05C_LN0_OVRD_RX_DFE_OC_SA_EDGE_ODD_CODE_SHIFT (1U)
/*! @} */
/*! @name TRSV_REG05D -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG05D_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG05D_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG05D_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG05D_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__7_0_SHIFT)) & PCIE_PHY_TRSV_REG05D_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__7_0_MASK)
/*! @} */
/*! @name TRSV_REG05E -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG05E_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG05E_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG05E_LN0_OVRD_RX_DFE_OC_SA_ERR_EVEN_CODE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG05E_LN0_OVRD_RX_DFE_OC_SA_ERR_EVEN_CODE_SHIFT (1U)
/*! @} */
/*! @name TRSV_REG05F -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG05F_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG05F_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG05F_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG05F_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__7_0_SHIFT)) & PCIE_PHY_TRSV_REG05F_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__7_0_MASK)
/*! @} */
/*! @name TRSV_REG060 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG060_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG060_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG060_LN0_OVRD_RX_DFE_OC_SA_ERR_ODD_CODE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG060_LN0_OVRD_RX_DFE_OC_SA_ERR_ODD_CODE_SHIFT (1U)
/*! @} */
/*! @name TRSV_REG061 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG061_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG061_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG061_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG061_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__7_0_SHIFT)) & PCIE_PHY_TRSV_REG061_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__7_0_MASK)
/*! @} */
/*! @name TRSV_REG062 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_ERR_OC_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_ERR_OC_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_ERR_OC_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_ERR_OC_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_EDGE_OC_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_EDGE_OC_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_EDGE_OC_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_EDGE_OC_EN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_ODD_OC_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_ODD_OC_EN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_ODD_OC_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_ODD_OC_EN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_EVEN_OC_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_EVEN_OC_EN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_EVEN_OC_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_EVEN_OC_EN_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG063 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG063_LN0_RX_DFE_VREF_CTRL__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG063_LN0_RX_DFE_VREF_CTRL__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG063_LN0_OVRD_RX_DFE_VREF_CTRL_MASK (0x2U)
#define PCIE_PHY_TRSV_REG063_LN0_OVRD_RX_DFE_VREF_CTRL_SHIFT (1U)
/*! @} */
/*! @name TRSV_REG064 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG064_LN0_RX_DFE_VREF_CTRL__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG064_LN0_RX_DFE_VREF_CTRL__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG064_LN0_RX_DFE_VREF_CTRL__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG064_LN0_RX_DFE_VREF_CTRL__7_0_SHIFT)) & PCIE_PHY_TRSV_REG064_LN0_RX_DFE_VREF_CTRL__7_0_MASK)
/*! @} */
/*! @name TRSV_REG065 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_VREG_SEL_MASK (0xFU)
#define PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_VREG_SEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_VREG_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_VREG_SEL_SHIFT)) & PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_VREG_SEL_MASK)
#define PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_ADDER_BLEED_CTRL_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_ADDER_BLEED_CTRL_SHIFT (4U)
#define PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_ADDER_BLEED_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_ADDER_BLEED_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_ADDER_BLEED_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG066 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG066_LN0_RX_RCAL_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG066_LN0_RX_RCAL_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG066_LN0_OVRD_RX_RCAL_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG066_LN0_OVRD_RX_RCAL_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_EOM_CLK_SEL_MASK (0x4U)
#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_EOM_CLK_SEL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_VCM_CTRL_MASK (0x38U)
#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_VCM_CTRL_SHIFT (3U)
#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_VCM_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_VCM_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_VCM_CTRL_MASK)
#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_OUT_PULLUP_MASK (0x40U)
#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_OUT_PULLUP_SHIFT (6U)
/*! @} */
/*! @name TRSV_REG067 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG067_LN0_RX_RTERM_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG067_LN0_RX_RTERM_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RTERM_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RTERM_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG067_LN0_ANA_RX_RCAL_IRMRES_CTRL_MASK (0xCU)
#define PCIE_PHY_TRSV_REG067_LN0_ANA_RX_RCAL_IRMRES_CTRL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG067_LN0_ANA_RX_RCAL_IRMRES_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG067_LN0_ANA_RX_RCAL_IRMRES_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG067_LN0_ANA_RX_RCAL_IRMRES_CTRL_MASK)
#define PCIE_PHY_TRSV_REG067_LN0_RX_RCAL_BIAS_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG067_LN0_RX_RCAL_BIAS_EN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RCAL_BIAS_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RCAL_BIAS_EN_SHIFT (5U)
/*! @} */
/*! @name TRSV_REG068 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_SW_CTRL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_SW_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_SW_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_SW_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_SW_CTRL_MASK)
#define PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_ITAIL_CTRL_MASK (0xCU)
#define PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_ITAIL_CTRL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_ITAIL_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_ITAIL_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_ITAIL_CTRL_MASK)
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G4_MASK (0x10U)
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G4_SHIFT (4U)
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G3_MASK (0x20U)
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G3_SHIFT (5U)
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G2_MASK (0x40U)
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G2_SHIFT (6U)
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G1_MASK (0x80U)
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G1_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG069 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSP_CTRL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSP_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSN_CTRL_MASK (0x2U)
#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSN_CTRL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_INCM_VCM_CTRL_MASK (0xCU)
#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_INCM_VCM_CTRL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_INCM_VCM_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_INCM_VCM_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_INCM_VCM_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG06A -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G4_MASK (0x1U)
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G3_MASK (0x2U)
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G3_SHIFT (1U)
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G2_MASK (0x4U)
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G2_SHIFT (2U)
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G1_MASK (0x8U)
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G1_SHIFT (3U)
#define PCIE_PHY_TRSV_REG06A_LN0_OVRD_RX_RTERM_CM_PULLDN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG06A_LN0_OVRD_RX_RTERM_CM_PULLDN_SHIFT (4U)
/*! @} */
/*! @name TRSV_REG06B -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG06B_LN0_ANA_RX_SQ_VREF_820M_LPF_BYPASS_MASK (0x1U)
#define PCIE_PHY_TRSV_REG06B_LN0_ANA_RX_SQ_VREF_820M_LPF_BYPASS_SHIFT (0U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_SQ_BMR_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_SQ_BMR_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_SQ_BMR_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_SQ_BMR_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G4_MASK (0x8U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G4_SHIFT (3U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G3_MASK (0x10U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G2_MASK (0x20U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G2_SHIFT (5U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G1_MASK (0x40U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G1_SHIFT (6U)
#define PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_RTERM_VCM_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_RTERM_VCM_EN_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG06C -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQHS_DIFN_OC_CODE_SIGN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQHS_DIFN_OC_CODE_SIGN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_DIFN_OC_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_DIFN_OC_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_DIFN_OC_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_DIFN_OC_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_EN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_EN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQ_VREF_820M_SEL_MASK (0x60U)
#define PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQ_VREF_820M_SEL_SHIFT (5U)
#define PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQ_VREF_820M_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQ_VREF_820M_SEL_SHIFT)) & PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQ_VREF_820M_SEL_MASK)
/*! @} */
/*! @name TRSV_REG06D -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFP_OC_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFP_OC_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFP_OC_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFP_OC_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG06D_LN0_ANA_RX_SQHS_DIFN_SKEWBUF_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG06D_LN0_ANA_RX_SQHS_DIFN_SKEWBUF_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFN_OC_CODE_MASK (0x78U)
#define PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFN_OC_CODE_SHIFT (3U)
#define PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFN_OC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFN_OC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFN_OC_CODE_MASK)
#define PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFN_OC_CODE_MASK (0x80U)
#define PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFN_OC_CODE_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG06E -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_SKEW_DEFAULT_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_SKEW_DEFAULT_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_SKEWBUF_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_SKEWBUF_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG06E_LN0_RX_SQHS_DIFP_OC_CODE_MASK (0x3CU)
#define PCIE_PHY_TRSV_REG06E_LN0_RX_SQHS_DIFP_OC_CODE_SHIFT (2U)
#define PCIE_PHY_TRSV_REG06E_LN0_RX_SQHS_DIFP_OC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06E_LN0_RX_SQHS_DIFP_OC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG06E_LN0_RX_SQHS_DIFP_OC_CODE_MASK)
#define PCIE_PHY_TRSV_REG06E_LN0_OVRD_RX_SQHS_DIFP_OC_CODE_MASK (0x40U)
#define PCIE_PHY_TRSV_REG06E_LN0_OVRD_RX_SQHS_DIFP_OC_CODE_SHIFT (6U)
#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_OC_CODE_SIGN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_OC_CODE_SIGN_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG06F -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_VREF_SUPPLY_SEL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_VREF_SUPPLY_SEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_BW_CTRL_MASK (0x6U)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_BW_CTRL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_BW_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_BW_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_BW_CTRL_MASK)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_FILTER_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_FILTER_EN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_TH_CTRL_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_TH_CTRL_SHIFT (4U)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_TH_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_TH_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_TH_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG070 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFN_TH_CTRL_MASK (0x7U)
#define PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFN_TH_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFN_TH_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFN_TH_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFN_TH_CTRL_MASK)
#define PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFP_FAST_ANA_SEL_MASK (0x8U)
#define PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFP_FAST_ANA_SEL_SHIFT (3U)
#define PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFP_DET_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFP_DET_EN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFP_DET_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFP_DET_EN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFN_DET_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFN_DET_EN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFN_DET_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFN_DET_EN_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG071 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_SCL2CMOS_I_CTRL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_SCL2CMOS_I_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_SCL2CMOS_I_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_SCL2CMOS_I_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_SCL2CMOS_I_CTRL_MASK)
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_IN_LPF_CTRL_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_IN_LPF_CTRL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_IN_LPF_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_IN_LPF_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_IN_LPF_CTRL_MASK)
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_DIFP_TH_CTRL_MASK (0xE0U)
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_DIFP_TH_CTRL_SHIFT (5U)
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_DIFP_TH_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_DIFP_TH_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_DIFP_TH_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG072 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_AFC_RSTN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_AFC_RSTN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_AFC_RSTN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_AFC_RSTN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_RSTN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_RSTN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_RSTN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_RSTN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_CNT_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_CNT_EN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_CNT_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_CNT_EN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_OSC_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_OSC_EN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_OSC_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_OSC_EN_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG073 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG073_LN0_ANA_RX_PWM_DIV_RATIO_MASK (0x7U)
#define PCIE_PHY_TRSV_REG073_LN0_ANA_RX_PWM_DIV_RATIO_SHIFT (0U)
#define PCIE_PHY_TRSV_REG073_LN0_ANA_RX_PWM_DIV_RATIO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG073_LN0_ANA_RX_PWM_DIV_RATIO_SHIFT)) & PCIE_PHY_TRSV_REG073_LN0_ANA_RX_PWM_DIV_RATIO_MASK)
#define PCIE_PHY_TRSV_REG073_LN0_RX_PWM_AFC_DONE_MASK (0x8U)
#define PCIE_PHY_TRSV_REG073_LN0_RX_PWM_AFC_DONE_SHIFT (3U)
#define PCIE_PHY_TRSV_REG073_LN0_OVRD_RX_PWM_AFC_DONE_MASK (0x10U)
#define PCIE_PHY_TRSV_REG073_LN0_OVRD_RX_PWM_AFC_DONE_SHIFT (4U)
/*! @} */
/*! @name TRSV_REG074 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG074_LN0_ANA_RX_PWM_OC_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG074_LN0_ANA_RX_PWM_OC_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG074_LN0_RX_PWM_OSC_CODE_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG074_LN0_RX_PWM_OSC_CODE_SHIFT (1U)
#define PCIE_PHY_TRSV_REG074_LN0_RX_PWM_OSC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG074_LN0_RX_PWM_OSC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG074_LN0_RX_PWM_OSC_CODE_MASK)
#define PCIE_PHY_TRSV_REG074_LN0_OVRD_RX_PWM_OSC_CODE_MASK (0x20U)
#define PCIE_PHY_TRSV_REG074_LN0_OVRD_RX_PWM_OSC_CODE_SHIFT (5U)
/*! @} */
/*! @name TRSV_REG075 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG075_LN0_ANA_RX_LFPS_LOSS_DET_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG075_LN0_ANA_RX_LFPS_LOSS_DET_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG075_LN0_RX_LFPS_DET_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG075_LN0_RX_LFPS_DET_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG075_LN0_OVRD_RX_LFPS_DET_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG075_LN0_OVRD_RX_LFPS_DET_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG075_LN0_ANA_RX_PWM_OC_CODE_MASK (0x78U)
#define PCIE_PHY_TRSV_REG075_LN0_ANA_RX_PWM_OC_CODE_SHIFT (3U)
#define PCIE_PHY_TRSV_REG075_LN0_ANA_RX_PWM_OC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG075_LN0_ANA_RX_PWM_OC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG075_LN0_ANA_RX_PWM_OC_CODE_MASK)
/*! @} */
/*! @name TRSV_REG076 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SRLB_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SRLB_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_LLB_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_LLB_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SLB_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SLB_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_BIAS_RMRES_CTRL_MASK (0x38U)
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_BIAS_RMRES_CTRL_SHIFT (3U)
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_BIAS_RMRES_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG076_LN0_ANA_RX_BIAS_RMRES_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG076_LN0_ANA_RX_BIAS_RMRES_CTRL_MASK)
#define PCIE_PHY_TRSV_REG076_LN0_RX_BIAS_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG076_LN0_RX_BIAS_EN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG076_LN0_OVRD_RX_BIAS_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG076_LN0_OVRD_RX_BIAS_EN_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG077 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ITAIL_CTRL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ITAIL_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ITAIL_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ITAIL_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ITAIL_CTRL_MASK)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_DUTY_CTRL_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_DUTY_CTRL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_DUTY_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_DUTY_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_DUTY_CTRL_MASK)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ACCAP_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ACCAP_EN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_DATA_EDGE_SEL_MASK (0x40U)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_DATA_EDGE_SEL_SHIFT (6U)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_EVEN_ODD_SEL_MASK (0x80U)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_EVEN_ODD_SEL_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG078 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_ATB_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_ATB_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_CDR_CLK_MON_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_CDR_CLK_MON_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_LLB_RLOAD_CTRL_MASK (0x4U)
#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_LLB_RLOAD_CTRL_SHIFT (2U)
/*! @} */
/*! @name TRSV_REG079 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG079_LN0_ANA_RX_ATB_SEL_MASK (0x3FU)
#define PCIE_PHY_TRSV_REG079_LN0_ANA_RX_ATB_SEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG079_LN0_ANA_RX_ATB_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG079_LN0_ANA_RX_ATB_SEL_SHIFT)) & PCIE_PHY_TRSV_REG079_LN0_ANA_RX_ATB_SEL_MASK)
/*! @} */
/*! @name TRSV_REG07A -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG07A_LN0_ANA_RX_RESERVED_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG07A_LN0_ANA_RX_RESERVED_SHIFT (0U)
#define PCIE_PHY_TRSV_REG07A_LN0_ANA_RX_RESERVED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07A_LN0_ANA_RX_RESERVED_SHIFT)) & PCIE_PHY_TRSV_REG07A_LN0_ANA_RX_RESERVED_MASK)
/*! @} */
/*! @name TRSV_REG07B -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_EN_MASK   (0x1U)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_EN_SHIFT  (0U)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TOL_MASK  (0x6U)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TOL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TOL(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TOL_SHIFT)) & PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TOL_MASK)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_CNT_SEL_MASK (0x18U)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_CNT_SEL_SHIFT (3U)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_CNT_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07B_LN0_RX_OC_CNT_SEL_SHIFT)) & PCIE_PHY_TRSV_REG07B_LN0_RX_OC_CNT_SEL_MASK)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TRIAL_CNT_MASK (0xE0U)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TRIAL_CNT_SHIFT (5U)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TRIAL_CNT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TRIAL_CNT_SHIFT)) & PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TRIAL_CNT_MASK)
/*! @} */
/*! @name TRSV_REG07C -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_FINAL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_FINAL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_ODD_FINAL_MASK (0x2U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_ODD_FINAL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_EVEN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_EVEN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_ODD_MASK (0x8U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_ODD_SHIFT (3U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_EVEN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_EVEN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_ODD_MASK (0x20U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_ODD_SHIFT (5U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_UPD_CNT_SEL_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_UPD_CNT_SEL_SHIFT (6U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_UPD_CNT_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07C_LN0_RX_OC_UPD_CNT_SEL_SHIFT)) & PCIE_PHY_TRSV_REG07C_LN0_RX_OC_UPD_CNT_SEL_MASK)
/*! @} */
/*! @name TRSV_REG07D -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_DONE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_DONE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG07D_LN0_OVRD_RX_OC_DONE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG07D_LN0_OVRD_RX_OC_DONE_SHIFT (1U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_ALL_RATE_MODE_MASK (0x4U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_ALL_RATE_MODE_SHIFT (2U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_CTLE_MASK (0x8U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_CTLE_SHIFT (3U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFP_MASK (0x10U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFP_SHIFT (4U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_INIT_MASK (0x40U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_INIT_SHIFT (6U)
/*! @} */
/*! @name TRSV_REG07E -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG07E_LN0_RX_SSLMS_C0_INIT_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG07E_LN0_RX_SSLMS_C0_INIT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG07E_LN0_RX_SSLMS_C0_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07E_LN0_RX_SSLMS_C0_INIT_SHIFT)) & PCIE_PHY_TRSV_REG07E_LN0_RX_SSLMS_C0_INIT_MASK)
/*! @} */
/*! @name TRSV_REG07F -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C2_SGN_INIT_MASK (0x1U)
#define PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C2_SGN_INIT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C1_INIT_MASK (0x7EU)
#define PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C1_INIT_SHIFT (1U)
#define PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C1_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C1_INIT_SHIFT)) & PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C1_INIT_MASK)
/*! @} */
/*! @name TRSV_REG080 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C3_SGN_INIT_MASK (0x1U)
#define PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C3_SGN_INIT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C2_INIT_MASK (0x3EU)
#define PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C2_INIT_SHIFT (1U)
#define PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C2_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C2_INIT_SHIFT)) & PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C2_INIT_MASK)
/*! @} */
/*! @name TRSV_REG081 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C4_SGN_INIT_MASK (0x1U)
#define PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C4_SGN_INIT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C3_INIT_MASK (0x3EU)
#define PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C3_INIT_SHIFT (1U)
#define PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C3_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C3_INIT_SHIFT)) & PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C3_INIT_MASK)
/*! @} */
/*! @name TRSV_REG082 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C5_SGN_INIT_MASK (0x1U)
#define PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C5_SGN_INIT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C4_INIT_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C4_INIT_SHIFT (1U)
#define PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C4_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C4_INIT_SHIFT)) & PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C4_INIT_MASK)
/*! @} */
/*! @name TRSV_REG083 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C1_ADAP_SPEED_MASK (0x3U)
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C1_ADAP_SPEED_SHIFT (0U)
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C1_ADAP_SPEED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C1_ADAP_SPEED_SHIFT)) & PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C1_ADAP_SPEED_MASK)
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C0_ADAP_SPEED_MASK (0xCU)
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C0_ADAP_SPEED_SHIFT (2U)
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C0_ADAP_SPEED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C0_ADAP_SPEED_SHIFT)) & PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C0_ADAP_SPEED_MASK)
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C5_INIT_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C5_INIT_SHIFT (4U)
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C5_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C5_INIT_SHIFT)) & PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C5_INIT_MASK)
/*! @} */
/*! @name TRSV_REG084 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_GAIN_MASK (0x3U)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_GAIN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_GAIN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_GAIN_SHIFT)) & PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_GAIN_MASK)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C1_ADAP_GAIN_MASK (0xCU)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C1_ADAP_GAIN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C1_ADAP_GAIN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C1_ADAP_GAIN_SHIFT)) & PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C1_ADAP_GAIN_MASK)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C0_ADAP_GAIN_MASK (0x30U)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C0_ADAP_GAIN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C0_ADAP_GAIN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C0_ADAP_GAIN_SHIFT)) & PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C0_ADAP_GAIN_MASK)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_SPEED_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_SPEED_SHIFT (6U)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_SPEED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_SPEED_SHIFT)) & PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_SPEED_MASK)
/*! @} */
/*! @name TRSV_REG085 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_TOL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_TOL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_TOL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_TOL_SHIFT)) & PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_TOL_MASK)
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_STAB_MASK (0xCU)
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_STAB_SHIFT (2U)
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_STAB(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_STAB_SHIFT)) & PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_STAB_MASK)
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_STAB_CONT_MASK (0x10U)
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_STAB_CONT_SHIFT (4U)
/*! @} */
/*! @name TRSV_REG086 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_CONT_MASK (0x1U)
#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_CONT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_CHK_MASK (0x2U)
#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_CHK_SHIFT (1U)
#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_SEL_MASK (0xFCU)
#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_SEL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_SEL_SHIFT)) & PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_SEL_MASK)
/*! @} */
/*! @name TRSV_REG087 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_HOLD_MASK (0x1U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_HOLD_SHIFT (0U)
#define PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_HOLD_MASK (0x2U)
#define PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_HOLD_SHIFT (1U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_EN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_RSTN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_RSTN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_EN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_SEL_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_SEL_SHIFT (6U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_SEL_SHIFT)) & PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_SEL_MASK)
/*! @} */
/*! @name TRSV_REG088 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG088_LN0_RX_CDR_PMS_M_G1__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG088_LN0_RX_CDR_PMS_M_G1__8_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG089 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG089_LN0_RX_CDR_PMS_M_G1__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG089_LN0_RX_CDR_PMS_M_G1__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG089_LN0_RX_CDR_PMS_M_G1__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG089_LN0_RX_CDR_PMS_M_G1__7_0_SHIFT)) & PCIE_PHY_TRSV_REG089_LN0_RX_CDR_PMS_M_G1__7_0_MASK)
/*! @} */
/*! @name TRSV_REG08A -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG08A_LN0_RX_CDR_PMS_M_G2__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG08A_LN0_RX_CDR_PMS_M_G2__8_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG08B -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG08B_LN0_RX_CDR_PMS_M_G2__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG08B_LN0_RX_CDR_PMS_M_G2__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG08B_LN0_RX_CDR_PMS_M_G2__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG08B_LN0_RX_CDR_PMS_M_G2__7_0_SHIFT)) & PCIE_PHY_TRSV_REG08B_LN0_RX_CDR_PMS_M_G2__7_0_MASK)
/*! @} */
/*! @name TRSV_REG08C -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG08C_LN0_RX_CDR_PMS_M_G3__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG08C_LN0_RX_CDR_PMS_M_G3__8_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG08D -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG08D_LN0_RX_CDR_PMS_M_G3__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG08D_LN0_RX_CDR_PMS_M_G3__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG08D_LN0_RX_CDR_PMS_M_G3__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG08D_LN0_RX_CDR_PMS_M_G3__7_0_SHIFT)) & PCIE_PHY_TRSV_REG08D_LN0_RX_CDR_PMS_M_G3__7_0_MASK)
/*! @} */
/*! @name TRSV_REG08E -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG08E_LN0_RX_CDR_PMS_M_G4__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG08E_LN0_RX_CDR_PMS_M_G4__8_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG08F -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG08F_LN0_RX_CDR_PMS_M_G4__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG08F_LN0_RX_CDR_PMS_M_G4__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG08F_LN0_RX_CDR_PMS_M_G4__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG08F_LN0_RX_CDR_PMS_M_G4__7_0_SHIFT)) & PCIE_PHY_TRSV_REG08F_LN0_RX_CDR_PMS_M_G4__7_0_MASK)
/*! @} */
/*! @name TRSV_REG090 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_STB_NUM_MASK (0xFU)
#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_STB_NUM_SHIFT (0U)
#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_STB_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_STB_NUM_SHIFT)) & PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_STB_NUM_MASK)
#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_INIT_RSTN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_INIT_RSTN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_INIT_RSTN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_INIT_RSTN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_RSTN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_RSTN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_RSTN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_RSTN_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG091 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG091_LN0_RX_CDR_AFC_TOL_MASK (0xFU)
#define PCIE_PHY_TRSV_REG091_LN0_RX_CDR_AFC_TOL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG091_LN0_RX_CDR_AFC_TOL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG091_LN0_RX_CDR_AFC_TOL_SHIFT)) & PCIE_PHY_TRSV_REG091_LN0_RX_CDR_AFC_TOL_MASK)
/*! @} */
/*! @name TRSV_REG092 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG092_LN0_RX_CDR_AFC_VCO_CNT_RUN_NO_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG092_LN0_RX_CDR_AFC_VCO_CNT_RUN_NO_SHIFT (0U)
#define PCIE_PHY_TRSV_REG092_LN0_RX_CDR_AFC_VCO_CNT_RUN_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG092_LN0_RX_CDR_AFC_VCO_CNT_RUN_NO_SHIFT)) & PCIE_PHY_TRSV_REG092_LN0_RX_CDR_AFC_VCO_CNT_RUN_NO_MASK)
/*! @} */
/*! @name TRSV_REG093 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_FIX_CODE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_FIX_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_VCO_CNT_WAIT_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_VCO_CNT_WAIT_SHIFT (1U)
#define PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_VCO_CNT_WAIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_VCO_CNT_WAIT_SHIFT)) & PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_VCO_CNT_WAIT_MASK)
/*! @} */
/*! @name TRSV_REG094 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_MAN_BSEL_TIME_MASK (0x1U)
#define PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_MAN_BSEL_TIME_SHIFT (0U)
#define PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_PRESET_VCO_CNT_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_PRESET_VCO_CNT_SHIFT (1U)
#define PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_PRESET_VCO_CNT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_PRESET_VCO_CNT_SHIFT)) & PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_PRESET_VCO_CNT_MASK)
/*! @} */
/*! @name TRSV_REG095 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_BSEL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_BSEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_MAN_BSEL_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_MAN_BSEL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_MAN_BSEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_MAN_BSEL_SHIFT)) & PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_MAN_BSEL_MASK)
/*! @} */
/*! @name TRSV_REG096 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG096_LN0_RX_CDR_FBB_VCO_CNT_RUN_NO_MASK (0x3FU)
#define PCIE_PHY_TRSV_REG096_LN0_RX_CDR_FBB_VCO_CNT_RUN_NO_SHIFT (0U)
#define PCIE_PHY_TRSV_REG096_LN0_RX_CDR_FBB_VCO_CNT_RUN_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG096_LN0_RX_CDR_FBB_VCO_CNT_RUN_NO_SHIFT)) & PCIE_PHY_TRSV_REG096_LN0_RX_CDR_FBB_VCO_CNT_RUN_NO_MASK)
/*! @} */
/*! @name TRSV_REG097 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_MAN_SEL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_MAN_SEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_VCO_CNT_WAIT_NO_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_VCO_CNT_WAIT_NO_SHIFT (1U)
#define PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_VCO_CNT_WAIT_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_VCO_CNT_WAIT_NO_SHIFT)) & PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_VCO_CNT_WAIT_NO_MASK)
/*! @} */
/*! @name TRSV_REG098 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG098_LN0_RX_CDR_FBB_MAN_CODE_UPDC_MASK (0xFU)
#define PCIE_PHY_TRSV_REG098_LN0_RX_CDR_FBB_MAN_CODE_UPDC_SHIFT (0U)
#define PCIE_PHY_TRSV_REG098_LN0_RX_CDR_FBB_MAN_CODE_UPDC(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG098_LN0_RX_CDR_FBB_MAN_CODE_UPDC_SHIFT)) & PCIE_PHY_TRSV_REG098_LN0_RX_CDR_FBB_MAN_CODE_UPDC_MASK)
/*! @} */
/*! @name TRSV_REG099 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG099_LN0_RX_CDR_FBB_DELTA_CNT_MASK (0x3FU)
#define PCIE_PHY_TRSV_REG099_LN0_RX_CDR_FBB_DELTA_CNT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG099_LN0_RX_CDR_FBB_DELTA_CNT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG099_LN0_RX_CDR_FBB_DELTA_CNT_SHIFT)) & PCIE_PHY_TRSV_REG099_LN0_RX_CDR_FBB_DELTA_CNT_MASK)
/*! @} */
/*! @name TRSV_REG09A -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G2_MASK)
#define PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G1_MASK)
/*! @} */
/*! @name TRSV_REG09B -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G4_MASK)
#define PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G3_MASK)
/*! @} */
/*! @name TRSV_REG09C -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G2_MASK)
#define PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G1_MASK)
/*! @} */
/*! @name TRSV_REG09D -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G4_MASK)
#define PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G3_MASK)
/*! @} */
/*! @name TRSV_REG09E -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G2_MASK)
#define PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G1_MASK)
/*! @} */
/*! @name TRSV_REG09F -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G4_MASK)
#define PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G3_MASK)
/*! @} */
/*! @name TRSV_REG0A0 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G2_SHIFT)) & PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G2_MASK)
#define PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G1_SHIFT)) & PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G1_MASK)
/*! @} */
/*! @name TRSV_REG0A1 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G4_SHIFT)) & PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G4_MASK)
#define PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G3_SHIFT)) & PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G3_MASK)
/*! @} */
/*! @name TRSV_REG0A2 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G2_SHIFT)) & PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G2_MASK)
#define PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G1_SHIFT)) & PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G1_MASK)
/*! @} */
/*! @name TRSV_REG0A3 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G4_SHIFT)) & PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G4_MASK)
#define PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G3_SHIFT)) & PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G3_MASK)
/*! @} */
/*! @name TRSV_REG0A4 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G2_SHIFT)) & PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G2_MASK)
#define PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G1_SHIFT)) & PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G1_MASK)
/*! @} */
/*! @name TRSV_REG0A5 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G4_SHIFT)) & PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G4_MASK)
#define PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G3_SHIFT)) & PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G3_MASK)
/*! @} */
/*! @name TRSV_REG0A6 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0A6_LN0_RX_CDR_PLL_VCO_CNT_RUN_NO_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG0A6_LN0_RX_CDR_PLL_VCO_CNT_RUN_NO_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A6_LN0_RX_CDR_PLL_VCO_CNT_RUN_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A6_LN0_RX_CDR_PLL_VCO_CNT_RUN_NO_SHIFT)) & PCIE_PHY_TRSV_REG0A6_LN0_RX_CDR_PLL_VCO_CNT_RUN_NO_MASK)
/*! @} */
/*! @name TRSV_REG0A7 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0A7_LN0_RX_CDR_PLL_VCO_CNT_WAIT_NO_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A7_LN0_RX_CDR_PLL_VCO_CNT_WAIT_NO_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A7_LN0_RX_CDR_PLL_VCO_CNT_WAIT_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A7_LN0_RX_CDR_PLL_VCO_CNT_WAIT_NO_SHIFT)) & PCIE_PHY_TRSV_REG0A7_LN0_RX_CDR_PLL_VCO_CNT_WAIT_NO_MASK)
/*! @} */
/*! @name TRSV_REG0A8 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_RESTART_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_RESTART_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_ENTRY_SRC_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_ENTRY_SRC_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_LOCK_PPM_SET_MASK (0x7CU)
#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_LOCK_PPM_SET_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_LOCK_PPM_SET(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_LOCK_PPM_SET_SHIFT)) & PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_LOCK_PPM_SET_MASK)
/*! @} */
/*! @name TRSV_REG0A9 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0A9_LN0_RX_CDR_CK_VCO_CNT_RUN_NO_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG0A9_LN0_RX_CDR_CK_VCO_CNT_RUN_NO_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A9_LN0_RX_CDR_CK_VCO_CNT_RUN_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A9_LN0_RX_CDR_CK_VCO_CNT_RUN_NO_SHIFT)) & PCIE_PHY_TRSV_REG0A9_LN0_RX_CDR_CK_VCO_CNT_RUN_NO_MASK)
/*! @} */
/*! @name TRSV_REG0AA -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_LOCK_SETTLE_NO_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_LOCK_SETTLE_NO_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_LOCK_SETTLE_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_LOCK_SETTLE_NO_SHIFT)) & PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_LOCK_SETTLE_NO_MASK)
#define PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_CK_VCO_CNT_WAIT_NO_MASK (0x78U)
#define PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_CK_VCO_CNT_WAIT_NO_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_CK_VCO_CNT_WAIT_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_CK_VCO_CNT_WAIT_NO_SHIFT)) & PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_CK_VCO_CNT_WAIT_NO_MASK)
/*! @} */
/*! @name TRSV_REG0AB -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CAL_DONE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CAL_DONE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0AB_LN0_OVRD_RX_CDR_CAL_DONE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0AB_LN0_OVRD_RX_CDR_CAL_DONE_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CK_LOCK_PPM_SET_MASK (0x7CU)
#define PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CK_LOCK_PPM_SET_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CK_LOCK_PPM_SET(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CK_LOCK_PPM_SET_SHIFT)) & PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CK_LOCK_PPM_SET_MASK)
/*! @} */
/*! @name TRSV_REG0AC -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0AC_LN0_RX_PWM_TG_OSC_CNT_MIN_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0AC_LN0_RX_PWM_TG_OSC_CNT_MIN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0AC_LN0_RX_PWM_TG_OSC_CNT_MIN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AC_LN0_RX_PWM_TG_OSC_CNT_MIN_SHIFT)) & PCIE_PHY_TRSV_REG0AC_LN0_RX_PWM_TG_OSC_CNT_MIN_MASK)
/*! @} */
/*! @name TRSV_REG0AD -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0AD_LN0_RX_PWM_TG_OSC_CNT_MAX_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0AD_LN0_RX_PWM_TG_OSC_CNT_MAX_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0AD_LN0_RX_PWM_TG_OSC_CNT_MAX(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AD_LN0_RX_PWM_TG_OSC_CNT_MAX_SHIFT)) & PCIE_PHY_TRSV_REG0AD_LN0_RX_PWM_TG_OSC_CNT_MAX_MASK)
/*! @} */
/*! @name TRSV_REG0AE -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_STB_NUM_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_STB_NUM_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_STB_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_STB_NUM_SHIFT)) & PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_STB_NUM_MASK)
#define PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_TOL_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_TOL_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_TOL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_TOL_SHIFT)) & PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_TOL_MASK)
/*! @} */
/*! @name TRSV_REG0AF -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0AF_LN0_RX_PWM_AFC_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0AF_LN0_RX_PWM_AFC_EN_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG0B0 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0B0_LN0_OVRD_RX_EFOM_FEEDBACK_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0B0_LN0_OVRD_RX_EFOM_FEEDBACK_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG0B1 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0B1_LN0_RX_EFOM_FEEDBACK__15_8_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0B1_LN0_RX_EFOM_FEEDBACK__15_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B1_LN0_RX_EFOM_FEEDBACK__15_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B1_LN0_RX_EFOM_FEEDBACK__15_8_SHIFT)) & PCIE_PHY_TRSV_REG0B1_LN0_RX_EFOM_FEEDBACK__15_8_MASK)
/*! @} */
/*! @name TRSV_REG0B2 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0B2_LN0_RX_EFOM_FEEDBACK__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0B2_LN0_RX_EFOM_FEEDBACK__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B2_LN0_RX_EFOM_FEEDBACK__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B2_LN0_RX_EFOM_FEEDBACK__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0B2_LN0_RX_EFOM_FEEDBACK__7_0_MASK)
/*! @} */
/*! @name TRSV_REG0B3 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_START_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_START_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_START_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_START_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_MODE_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_MODE_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_MODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_MODE_SHIFT)) & PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_MODE_MASK)
#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_DONE_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_DONE_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_DONE_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_DONE_SHIFT (6U)
/*! @} */
/*! @name TRSV_REG0B4 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_V_WEIGHT_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_V_WEIGHT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_V_WEIGHT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_V_WEIGHT_SHIFT)) & PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_V_WEIGHT_MASK)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_H_WEIGHT_MASK (0xCU)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_H_WEIGHT_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_H_WEIGHT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_H_WEIGHT_SHIFT)) & PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_H_WEIGHT_MASK)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_START_SSM_DISABLE_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_START_SSM_DISABLE_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_VREF_RESOL_MASK (0xE0U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_VREF_RESOL_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_VREF_RESOL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_VREF_RESOL_SHIFT)) & PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_VREF_RESOL_MASK)
/*! @} */
/*! @name TRSV_REG0B5 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_RSTN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_RSTN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_BIT_WIDTH_SEL_MASK (0xCU)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_BIT_WIDTH_SEL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_BIT_WIDTH_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_BIT_WIDTH_SEL_SHIFT)) & PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_BIT_WIDTH_SEL_MASK)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_SETTLE_TIME_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_SETTLE_TIME_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_SETTLE_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_SETTLE_TIME_SHIFT)) & PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_SETTLE_TIME_MASK)
/*! @} */
/*! @name TRSV_REG0B6 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0B6_LN0_RX_EFOM_NUM_OF_SAMPLE__13_8_MASK (0x3FU)
#define PCIE_PHY_TRSV_REG0B6_LN0_RX_EFOM_NUM_OF_SAMPLE__13_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B6_LN0_RX_EFOM_NUM_OF_SAMPLE__13_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B6_LN0_RX_EFOM_NUM_OF_SAMPLE__13_8_SHIFT)) & PCIE_PHY_TRSV_REG0B6_LN0_RX_EFOM_NUM_OF_SAMPLE__13_8_MASK)
/*! @} */
/*! @name TRSV_REG0B7 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0B7_LN0_RX_EFOM_NUM_OF_SAMPLE__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0B7_LN0_RX_EFOM_NUM_OF_SAMPLE__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B7_LN0_RX_EFOM_NUM_OF_SAMPLE__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B7_LN0_RX_EFOM_NUM_OF_SAMPLE__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0B7_LN0_RX_EFOM_NUM_OF_SAMPLE__7_0_MASK)
/*! @} */
/*! @name TRSV_REG0B8 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_OUT_WIDTH_SEL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_OUT_WIDTH_SEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_TRIAL_NUM_MASK (0xEU)
#define PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_TRIAL_NUM_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_TRIAL_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_TRIAL_NUM_SHIFT)) & PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_TRIAL_NUM_MASK)
/*! @} */
/*! @name TRSV_REG0B9 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0B9_LN0_RX_EFOM_DFE_VREF_CTRL_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0B9_LN0_RX_EFOM_DFE_VREF_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B9_LN0_RX_EFOM_DFE_VREF_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B9_LN0_RX_EFOM_DFE_VREF_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG0B9_LN0_RX_EFOM_DFE_VREF_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG0BA -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0BA_LN0_RX_EFOM_EOM_PH_SEL_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG0BA_LN0_RX_EFOM_EOM_PH_SEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0BA_LN0_RX_EFOM_EOM_PH_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BA_LN0_RX_EFOM_EOM_PH_SEL_SHIFT)) & PCIE_PHY_TRSV_REG0BA_LN0_RX_EFOM_EOM_PH_SEL_MASK)
/*! @} */
/*! @name TRSV_REG0BB -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0BB_LN0_RETIMEDLB_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0BB_LN0_RETIMEDLB_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0BB_LN0_NEARLB_EN_MASK  (0x2U)
#define PCIE_PHY_TRSV_REG0BB_LN0_NEARLB_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DB_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DB_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DA_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DA_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS_ERR_CHK_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS_ERR_CHK_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_RSTN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_RSTN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG0BB_LN0_OVRD_TXD_DESKEW_RSTN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0BB_LN0_OVRD_TXD_DESKEW_RSTN_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG0BC -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_FLIP_BYTE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_FLIP_BYTE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_LOCK_NUM_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_LOCK_NUM_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_LOCK_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BC_LN0_RXD_LOCK_NUM_SHIFT)) & PCIE_PHY_TRSV_REG0BC_LN0_RXD_LOCK_NUM_MASK)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_WORD_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_WORD_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_HOLD_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_HOLD_SHIFT (6U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_EN_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG0BD -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_DN_OPT_CODE_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_DN_OPT_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_DN_OPT_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_DN_OPT_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_DN_OPT_CODE_MASK)
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_UP_OPT_CODE_MASK (0xCU)
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_UP_OPT_CODE_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_UP_OPT_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_UP_OPT_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_UP_OPT_CODE_MASK)
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_RSTN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_RSTN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0BD_LN0_OVRD_TX_RCAL_RSTN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0BD_LN0_OVRD_TX_RCAL_RSTN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0BD_LN0_RXD_POLARITY_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0BD_LN0_RXD_POLARITY_SHIFT (6U)
#define PCIE_PHY_TRSV_REG0BD_LN0_RXD_FLIP_BIT_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0BD_LN0_RXD_FLIP_BIT_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG0BE -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_DN_CODE_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_DN_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_DN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_DN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_DN_CODE_MASK)
#define PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_UP_CODE_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_UP_CODE_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_UP_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_UP_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_UP_CODE_MASK)
/*! @} */
/*! @name TRSV_REG0BF -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_OPT_CODE_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_OPT_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_OPT_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_OPT_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_OPT_CODE_MASK)
#define PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_RSTN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_RSTN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_RX_RCAL_RSTN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_RX_RCAL_RSTN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_DONE_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_DONE_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_DONE_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_DONE_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_COMP_OUT_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_COMP_OUT_SHIFT (6U)
#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_COMP_OUT_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_COMP_OUT_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG0C0 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_DONE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_DONE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_DONE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_DONE_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_COMP_OUT_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_COMP_OUT_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_COMP_OUT_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_COMP_OUT_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RTERM_CTRL_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RTERM_CTRL_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RTERM_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C0_LN0_RX_RTERM_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG0C0_LN0_RX_RTERM_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG0C1 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_PRBS_MODE_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_PRBS_MODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_PRBS_MODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C1_LN0_BIST_PRBS_MODE_SHIFT)) & PCIE_PHY_TRSV_REG0C1_LN0_BIST_PRBS_MODE_MASK)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_SEED_SEL_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_SEED_SEL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_SEED_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C1_LN0_BIST_SEED_SEL_SHIFT)) & PCIE_PHY_TRSV_REG0C1_LN0_BIST_SEED_SEL_MASK)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_COMDET_NUM_MASK (0x60U)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_COMDET_NUM_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_COMDET_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C1_LN0_BIST_COMDET_NUM_SHIFT)) & PCIE_PHY_TRSV_REG0C1_LN0_BIST_COMDET_NUM_MASK)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_AUTO_RUN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_AUTO_RUN_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG0C2 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_START_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_START_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_ERRINJ_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_ERRINJ_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_START_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_START_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_HOLD_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_HOLD_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_EN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_DATA_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_DATA_EN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_EN_MASK    (0x80U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_EN_SHIFT   (7U)
/*! @} */
/*! @name TRSV_REG0C3 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0C3_LN0_BIST_USER_PAT_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0C3_LN0_BIST_USER_PAT_EN_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG0C4 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0C4_LN0_BIST_USER_PAT__79_72_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0C4_LN0_BIST_USER_PAT__79_72_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C4_LN0_BIST_USER_PAT__79_72(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C4_LN0_BIST_USER_PAT__79_72_SHIFT)) & PCIE_PHY_TRSV_REG0C4_LN0_BIST_USER_PAT__79_72_MASK)
/*! @} */
/*! @name TRSV_REG0C5 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0C5_LN0_BIST_USER_PAT__71_64_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0C5_LN0_BIST_USER_PAT__71_64_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C5_LN0_BIST_USER_PAT__71_64(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C5_LN0_BIST_USER_PAT__71_64_SHIFT)) & PCIE_PHY_TRSV_REG0C5_LN0_BIST_USER_PAT__71_64_MASK)
/*! @} */
/*! @name TRSV_REG0C6 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0C6_LN0_BIST_USER_PAT__63_56_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0C6_LN0_BIST_USER_PAT__63_56_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C6_LN0_BIST_USER_PAT__63_56(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C6_LN0_BIST_USER_PAT__63_56_SHIFT)) & PCIE_PHY_TRSV_REG0C6_LN0_BIST_USER_PAT__63_56_MASK)
/*! @} */
/*! @name TRSV_REG0C7 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0C7_LN0_BIST_USER_PAT__55_48_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0C7_LN0_BIST_USER_PAT__55_48_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C7_LN0_BIST_USER_PAT__55_48(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C7_LN0_BIST_USER_PAT__55_48_SHIFT)) & PCIE_PHY_TRSV_REG0C7_LN0_BIST_USER_PAT__55_48_MASK)
/*! @} */
/*! @name TRSV_REG0C8 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0C8_LN0_BIST_USER_PAT__47_40_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0C8_LN0_BIST_USER_PAT__47_40_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C8_LN0_BIST_USER_PAT__47_40(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C8_LN0_BIST_USER_PAT__47_40_SHIFT)) & PCIE_PHY_TRSV_REG0C8_LN0_BIST_USER_PAT__47_40_MASK)
/*! @} */
/*! @name TRSV_REG0C9 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0C9_LN0_BIST_USER_PAT__39_32_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0C9_LN0_BIST_USER_PAT__39_32_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C9_LN0_BIST_USER_PAT__39_32(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C9_LN0_BIST_USER_PAT__39_32_SHIFT)) & PCIE_PHY_TRSV_REG0C9_LN0_BIST_USER_PAT__39_32_MASK)
/*! @} */
/*! @name TRSV_REG0CA -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0CA_LN0_BIST_USER_PAT__31_24_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0CA_LN0_BIST_USER_PAT__31_24_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0CA_LN0_BIST_USER_PAT__31_24(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CA_LN0_BIST_USER_PAT__31_24_SHIFT)) & PCIE_PHY_TRSV_REG0CA_LN0_BIST_USER_PAT__31_24_MASK)
/*! @} */
/*! @name TRSV_REG0CB -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0CB_LN0_BIST_USER_PAT__23_16_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0CB_LN0_BIST_USER_PAT__23_16_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0CB_LN0_BIST_USER_PAT__23_16(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CB_LN0_BIST_USER_PAT__23_16_SHIFT)) & PCIE_PHY_TRSV_REG0CB_LN0_BIST_USER_PAT__23_16_MASK)
/*! @} */
/*! @name TRSV_REG0CC -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0CC_LN0_BIST_USER_PAT__15_8_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0CC_LN0_BIST_USER_PAT__15_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0CC_LN0_BIST_USER_PAT__15_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CC_LN0_BIST_USER_PAT__15_8_SHIFT)) & PCIE_PHY_TRSV_REG0CC_LN0_BIST_USER_PAT__15_8_MASK)
/*! @} */
/*! @name TRSV_REG0CD -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0CD_LN0_BIST_USER_PAT__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0CD_LN0_BIST_USER_PAT__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0CD_LN0_BIST_USER_PAT__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CD_LN0_BIST_USER_PAT__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0CD_LN0_BIST_USER_PAT__7_0_MASK)
/*! @} */
/*! @name TRSV_REG0CE -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0CE_LN0_LANE_MODE_MASK  (0x1U)
#define PCIE_PHY_TRSV_REG0CE_LN0_LANE_MODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0CE_LN0_TG_RX_SIGVAL_LPF_DELAY_TIME_MASK (0xEU)
#define PCIE_PHY_TRSV_REG0CE_LN0_TG_RX_SIGVAL_LPF_DELAY_TIME_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0CE_LN0_TG_RX_SIGVAL_LPF_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CE_LN0_TG_RX_SIGVAL_LPF_DELAY_TIME_SHIFT)) & PCIE_PHY_TRSV_REG0CE_LN0_TG_RX_SIGVAL_LPF_DELAY_TIME_MASK)
#define PCIE_PHY_TRSV_REG0CE_LN0_RX_SIGVAL_LPF_BYPASS_MASK (0x30U)
#define PCIE_PHY_TRSV_REG0CE_LN0_RX_SIGVAL_LPF_BYPASS_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0CE_LN0_RX_SIGVAL_LPF_BYPASS(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CE_LN0_RX_SIGVAL_LPF_BYPASS_SHIFT)) & PCIE_PHY_TRSV_REG0CE_LN0_RX_SIGVAL_LPF_BYPASS_MASK)
/*! @} */
/*! @name TRSV_REG0CF -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_INV_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_INV_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_SRC_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_SRC_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_TX_CLK_SRC_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_TX_CLK_SRC_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0CF_LN0_LANE_TIMER_SEL_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0CF_LN0_LANE_TIMER_SEL_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0CF_LN0_LANE_RATE_MASK  (0x30U)
#define PCIE_PHY_TRSV_REG0CF_LN0_LANE_RATE_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0CF_LN0_LANE_RATE(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CF_LN0_LANE_RATE_SHIFT)) & PCIE_PHY_TRSV_REG0CF_LN0_LANE_RATE_MASK)
#define PCIE_PHY_TRSV_REG0CF_LN0_OVRD_LANE_RATE_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0CF_LN0_OVRD_LANE_RATE_SHIFT (6U)
/*! @} */
/*! @name TRSV_REG0D0 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_TX_RXD_DETECTED_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_TX_RXD_DETECTED_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_TX_RXD_DETECTED_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_TX_RXD_DETECTED_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_LFPS_DET_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_LFPS_DET_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_LFPS_DET_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_LFPS_DET_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_DATA_CLEAR_SRC_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_DATA_CLEAR_SRC_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_SQHS_SIGVAL_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_SQHS_SIGVAL_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_SQHS_SIGVAL_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_SQHS_SIGVAL_SHIFT (6U)
/*! @} */
/*! @name TRSV_REG0D1 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0D1_LN0_TG_RCAL_RSTN_DELAY_TIME_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0D1_LN0_TG_RCAL_RSTN_DELAY_TIME_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D1_LN0_TG_RCAL_RSTN_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D1_LN0_TG_RCAL_RSTN_DELAY_TIME_SHIFT)) & PCIE_PHY_TRSV_REG0D1_LN0_TG_RCAL_RSTN_DELAY_TIME_MASK)
#define PCIE_PHY_TRSV_REG0D1_LN0_TG_CDR_BW_CTRL_DELAY_TIME_MASK (0x38U)
#define PCIE_PHY_TRSV_REG0D1_LN0_TG_CDR_BW_CTRL_DELAY_TIME_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0D1_LN0_TG_CDR_BW_CTRL_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D1_LN0_TG_CDR_BW_CTRL_DELAY_TIME_SHIFT)) & PCIE_PHY_TRSV_REG0D1_LN0_TG_CDR_BW_CTRL_DELAY_TIME_MASK)
#define PCIE_PHY_TRSV_REG0D1_LN0_MISC_RX_VALID_RSTN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0D1_LN0_MISC_RX_VALID_RSTN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG0D1_LN0_OVRD_MISC_RX_VALID_RSTN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0D1_LN0_OVRD_MISC_RX_VALID_RSTN_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG0D2 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0D2_LN0_TG_RXD_COMP_DELAY_TIME_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0D2_LN0_TG_RXD_COMP_DELAY_TIME_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D2_LN0_TG_RXD_COMP_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D2_LN0_TG_RXD_COMP_DELAY_TIME_SHIFT)) & PCIE_PHY_TRSV_REG0D2_LN0_TG_RXD_COMP_DELAY_TIME_MASK)
/*! @} */
/*! @name TRSV_REG0D3 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0D3_LN0_MON_LANE_STATE_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0D3_LN0_MON_LANE_STATE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D3_LN0_MON_LANE_STATE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D3_LN0_MON_LANE_STATE_SHIFT)) & PCIE_PHY_TRSV_REG0D3_LN0_MON_LANE_STATE_MASK)
#define PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFP_DET_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFP_DET_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFN_DET_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFN_DET_SHIFT (5U)
/*! @} */
/*! @name TRSV_REG0D4 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0D4_LN0_MON_CDR_STATE_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0D4_LN0_MON_CDR_STATE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D4_LN0_MON_CDR_STATE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D4_LN0_MON_CDR_STATE_SHIFT)) & PCIE_PHY_TRSV_REG0D4_LN0_MON_CDR_STATE_MASK)
/*! @} */
/*! @name TRSV_REG0D5 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0D5_LN0_MON_LANE_TIME__14_8_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG0D5_LN0_MON_LANE_TIME__14_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D5_LN0_MON_LANE_TIME__14_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D5_LN0_MON_LANE_TIME__14_8_SHIFT)) & PCIE_PHY_TRSV_REG0D5_LN0_MON_LANE_TIME__14_8_MASK)
/*! @} */
/*! @name TRSV_REG0D6 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0D6_LN0_MON_LANE_TIME__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0D6_LN0_MON_LANE_TIME__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D6_LN0_MON_LANE_TIME__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D6_LN0_MON_LANE_TIME__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0D6_LN0_MON_LANE_TIME__7_0_MASK)
/*! @} */
/*! @name TRSV_REG0D7 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_FBB_FINE_CTRL_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_FBB_FINE_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_FBB_FINE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_FBB_FINE_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_FBB_FINE_CTRL_MASK)
#define PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_AFC_SEL_LOGIC_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_AFC_SEL_LOGIC_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_AFC_SEL_LOGIC(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_AFC_SEL_LOGIC_SHIFT)) & PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_AFC_SEL_LOGIC_MASK)
/*! @} */
/*! @name TRSV_REG0D8 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_PLL_MODE_CTRL_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_PLL_MODE_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_PLL_MODE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_PLL_MODE_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_PLL_MODE_CTRL_MASK)
#define PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_COARSE_CTRL_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_COARSE_CTRL_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_COARSE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_COARSE_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_COARSE_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG0D9 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0D9_LN0_MON_RX_CDR_MODE_CTRL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0D9_LN0_MON_RX_CDR_MODE_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D9_LN0_MON_RX_CDR_MODE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D9_LN0_MON_RX_CDR_MODE_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG0D9_LN0_MON_RX_CDR_MODE_CTRL_MASK)
/*! @} */
/*! @name TRSV_REG0DA -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0DA_LN0_MON_RX_OC_DFE_ADDER_EVEN_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG0DA_LN0_MON_RX_OC_DFE_ADDER_EVEN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0DA_LN0_MON_RX_OC_DFE_ADDER_EVEN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0DA_LN0_MON_RX_OC_DFE_ADDER_EVEN_SHIFT)) & PCIE_PHY_TRSV_REG0DA_LN0_MON_RX_OC_DFE_ADDER_EVEN_MASK)
/*! @} */
/*! @name TRSV_REG0DB -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_DAC_ADDER_EVEN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_DAC_ADDER_EVEN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_ADDER_ODD_MASK (0xFEU)
#define PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_ADDER_ODD_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_ADDER_ODD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_ADDER_ODD_SHIFT)) & PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_ADDER_ODD_MASK)
/*! @} */
/*! @name TRSV_REG0DC -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0DC_LN0_MON_RX_OC_DFE_DAC_ADDER_ODD_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0DC_LN0_MON_RX_OC_DFE_DAC_ADDER_ODD_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG0DD -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0DD_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0DD_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__8_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG0DE -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0DE_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0DE_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0DE_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0DE_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0DE_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__7_0_MASK)
/*! @} */
/*! @name TRSV_REG0DF -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0DF_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0DF_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__8_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG0E0 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0E0_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0E0_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E0_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E0_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0E0_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__7_0_MASK)
/*! @} */
/*! @name TRSV_REG0E1 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_EVEN_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_EVEN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_EVEN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_EVEN_SHIFT)) & PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_EVEN_MASK)
#define PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_ODD_MASK (0x38U)
#define PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_ODD_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_ODD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_ODD_SHIFT)) & PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_ODD_MASK)
/*! @} */
/*! @name TRSV_REG0E2 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0E2_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0E2_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__8_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG0E3 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0E3_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0E3_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E3_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E3_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0E3_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__7_0_MASK)
/*! @} */
/*! @name TRSV_REG0E4 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0E4_LN0_MON_RX_OC_DFE_SA_ERR_ODD__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0E4_LN0_MON_RX_OC_DFE_SA_ERR_ODD__8_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG0E5 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0E5_LN0_MON_RX_OC_DFE_SA_ERR_ODD__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0E5_LN0_MON_RX_OC_DFE_SA_ERR_ODD__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E5_LN0_MON_RX_OC_DFE_SA_ERR_ODD__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E5_LN0_MON_RX_OC_DFE_SA_ERR_ODD__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0E5_LN0_MON_RX_OC_DFE_SA_ERR_ODD__7_0_MASK)
/*! @} */
/*! @name TRSV_REG0E6 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_ODD_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_ODD_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_ODD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_ODD_SHIFT)) & PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_ODD_MASK)
#define PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_EVEN_MASK (0x38U)
#define PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_EVEN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_EVEN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_EVEN_SHIFT)) & PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_EVEN_MASK)
/*! @} */
/*! @name TRSV_REG0E7 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0E7_LN0_MON_RX_OC_CTLE_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG0E7_LN0_MON_RX_OC_CTLE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E7_LN0_MON_RX_OC_CTLE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E7_LN0_MON_RX_OC_CTLE_SHIFT)) & PCIE_PHY_TRSV_REG0E7_LN0_MON_RX_OC_CTLE_MASK)
/*! @} */
/*! @name TRSV_REG0E8 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFP_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFP_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFP(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFP_SHIFT)) & PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFP_MASK)
#define PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFN_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFN_SHIFT)) & PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFN_MASK)
/*! @} */
/*! @name TRSV_REG0E9 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0E9_LN0_MON_RX_OC_CAL_DONE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0E9_LN0_MON_RX_OC_CAL_DONE_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG0EA -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0EA_LN0_MON_RX_OC_FAIL__9_8_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0EA_LN0_MON_RX_OC_FAIL__9_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0EA_LN0_MON_RX_OC_FAIL__9_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0EA_LN0_MON_RX_OC_FAIL__9_8_SHIFT)) & PCIE_PHY_TRSV_REG0EA_LN0_MON_RX_OC_FAIL__9_8_MASK)
/*! @} */
/*! @name TRSV_REG0EB -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0EB_LN0_MON_RX_OC_FAIL__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0EB_LN0_MON_RX_OC_FAIL__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0EB_LN0_MON_RX_OC_FAIL__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0EB_LN0_MON_RX_OC_FAIL__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0EB_LN0_MON_RX_OC_FAIL__7_0_MASK)
/*! @} */
/*! @name TRSV_REG0EC -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0EC_LN0_MON_RX_SSLMS_C0__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0EC_LN0_MON_RX_SSLMS_C0__8_SHIFT (0U)
/*! @} */
/*! @name TRSV_REG0ED -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0ED_LN0_MON_RX_SSLMS_C0__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0ED_LN0_MON_RX_SSLMS_C0__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0ED_LN0_MON_RX_SSLMS_C0__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0ED_LN0_MON_RX_SSLMS_C0__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0ED_LN0_MON_RX_SSLMS_C0__7_0_MASK)
/*! @} */
/*! @name TRSV_REG0EE -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C2_SGN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C2_SGN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C1_MASK (0xFEU)
#define PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C1_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C1_SHIFT)) & PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C1_MASK)
/*! @} */
/*! @name TRSV_REG0EF -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C3_SGN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C3_SGN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C2_MASK (0x3EU)
#define PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C2_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C2_SHIFT)) & PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C2_MASK)
/*! @} */
/*! @name TRSV_REG0F0 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C4_SGN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C4_SGN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C3_MASK (0x3EU)
#define PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C3_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C3_SHIFT)) & PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C3_MASK)
/*! @} */
/*! @name TRSV_REG0F1 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C5_SGN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C5_SGN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C4_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C4_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C4_SHIFT)) & PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C4_MASK)
/*! @} */
/*! @name TRSV_REG0F2 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_EFOM_DONE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_EFOM_DONE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_ADAP_DONE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_ADAP_DONE_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_C5_MASK (0x3CU)
#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_C5_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_C5(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_C5_SHIFT)) & PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_C5_MASK)
/*! @} */
/*! @name TRSV_REG0F3 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0F3_LN0_MON_RX_EFOM_ERR_CNT__13_8_MASK (0x3FU)
#define PCIE_PHY_TRSV_REG0F3_LN0_MON_RX_EFOM_ERR_CNT__13_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F3_LN0_MON_RX_EFOM_ERR_CNT__13_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F3_LN0_MON_RX_EFOM_ERR_CNT__13_8_SHIFT)) & PCIE_PHY_TRSV_REG0F3_LN0_MON_RX_EFOM_ERR_CNT__13_8_MASK)
/*! @} */
/*! @name TRSV_REG0F4 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0F4_LN0_MON_RX_EFOM_ERR_CNT__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0F4_LN0_MON_RX_EFOM_ERR_CNT__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F4_LN0_MON_RX_EFOM_ERR_CNT__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F4_LN0_MON_RX_EFOM_ERR_CNT__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0F4_LN0_MON_RX_EFOM_ERR_CNT__7_0_MASK)
/*! @} */
/*! @name TRSV_REG0F5 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0F5_LN0_MON_RX_EFOM_FEEDBACK__15_8_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0F5_LN0_MON_RX_EFOM_FEEDBACK__15_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F5_LN0_MON_RX_EFOM_FEEDBACK__15_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F5_LN0_MON_RX_EFOM_FEEDBACK__15_8_SHIFT)) & PCIE_PHY_TRSV_REG0F5_LN0_MON_RX_EFOM_FEEDBACK__15_8_MASK)
/*! @} */
/*! @name TRSV_REG0F6 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0F6_LN0_MON_RX_EFOM_FEEDBACK__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0F6_LN0_MON_RX_EFOM_FEEDBACK__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F6_LN0_MON_RX_EFOM_FEEDBACK__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F6_LN0_MON_RX_EFOM_FEEDBACK__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0F6_LN0_MON_RX_EFOM_FEEDBACK__7_0_MASK)
/*! @} */
/*! @name TRSV_REG0F7 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_DONE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_DONE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_TUNE_CODE_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_TUNE_CODE_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_TUNE_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_TUNE_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_TUNE_CODE_MASK)
/*! @} */
/*! @name TRSV_REG0F8 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_REPEAT_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_REPEAT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_FAIL_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_FAIL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_DONE_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_DONE_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_DONE_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_DONE_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_TUNE_CODE_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_TUNE_CODE_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_TUNE_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_TUNE_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_TUNE_CODE_MASK)
/*! @} */
/*! @name TRSV_REG0F9 -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0F9_LN0_MON_RX_PWM_AFC_CODE_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0F9_LN0_MON_RX_PWM_AFC_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F9_LN0_MON_RX_PWM_AFC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F9_LN0_MON_RX_PWM_AFC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0F9_LN0_MON_RX_PWM_AFC_CODE_MASK)
/*! @} */
/*! @name TRSV_REG0FA -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_START_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_START_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_ERRINJ_TEST_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_ERRINJ_TEST_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_TEST_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_TEST_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_LOCK_DONE_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_LOCK_DONE_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_FLD_PLL_MODE_DONE_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_FLD_PLL_MODE_DONE_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_CAL_DONE_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_CAL_DONE_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_AFC_DONE_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_AFC_DONE_SHIFT (6U)
/*! @} */
/*! @name TRSV_REG0FB -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0FB_LN0_MON_BIST_EOUT_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0FB_LN0_MON_BIST_EOUT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0FB_LN0_MON_BIST_EOUT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FB_LN0_MON_BIST_EOUT_SHIFT)) & PCIE_PHY_TRSV_REG0FB_LN0_MON_BIST_EOUT_MASK)
/*! @} */
/*! @name TRSV_REG0FC -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G2_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G2_MASK)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G2_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G2_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G1_MASK (0x70U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G1_MASK)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G1_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G1_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG0FD -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G4_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G4_MASK)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G4_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G4_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G3_MASK (0x70U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G3_MASK)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G3_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G3_SHIFT (7U)
/*! @} */
/*! @name TRSV_REG0FE -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G2_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G2_SHIFT)) & PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G2_MASK)
#define PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G1_MASK (0x70U)
#define PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G1_SHIFT)) & PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G1_MASK)
/*! @} */
/*! @name TRSV_REG0FF -  */
/*! @{ */
#define PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G4_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G4_SHIFT)) & PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G4_MASK)
#define PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G3_MASK (0x70U)
#define PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G3_SHIFT)) & PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCIE_PHY_Register_Masks */

/* PCIE_PHY - Peripheral instance base addresses */
/** Peripheral PCIE_PHY0 base pointer */
#define PCIE_PHY0_BASE_PTR                       ((PCIE_PHY_MemMapPtr)0x1FF00000u)
/** Peripheral PCIE_PHY1 base pointer */
#define PCIE_PHY1_BASE_PTR                       ((PCIE_PHY_MemMapPtr)0x27F00000u)


#define IOMUXC_GPR_GPR14_PCIE1_CLKREQ_B_OVERRIDE_MASK (0x800U)
