/*++
Copyright 2020 NXP

Module Name:
    imxthermalclienthw.h
--*/

#ifndef _IMXTCHW_H_
#define _IMXTCHW_H_

/*!
 * @addtogroup CCM_ANALOG_Peripheral CCM_ANALOG
 * @{
 */

 /** CCM_ANALOG - Peripheral register structure */
typedef struct IMX8MQ_CCM_ANALOG_MemMap {
    UINT32 AUDIO_PLL1_CFG0;                        /**< AUDIO PLL1 Configuration 0 Register, offset: 0x0 */
    UINT32 AUDIO_PLL1_CFG1;                        /**< AUDIO PLL1 Configuration 1 Register, offset: 0x4 */
    UINT32 AUDIO_PLL2_CFG0;                        /**< AUDIO PLL2 Configuration 0 Register, offset: 0x8 */
    UINT32 AUDIO_PLL2_CFG1;                        /**< AUDIO PLL2 Configuration 1 Register, offset: 0xC */
    UINT32 VIDEO_PLL1_CFG0;                        /**< VIDEO PLL Configuration 0 Register, offset: 0x10 */
    UINT32 VIDEO_PLL1_CFG1;                        /**< VIDEO PLL Configuration 1 Register, offset: 0x14 */
    UINT32 GPU_PLL_CFG0;                           /**< GPU PLL Configuration 0 Register, offset: 0x18 */
    UINT32 GPU_PLL_CFG1;                           /**< GPU PLL Configuration 1 Register, offset: 0x1C */
    UINT32 VPU_PLL_CFG0;                           /**< VPU PLL Configuration 0 Register, offset: 0x20 */
    UINT32 VPU_PLL_CFG1;                           /**< VPU PLL Configuration 1 Register, offset: 0x24 */
    UINT32 ARM_PLL_CFG0;                           /**< ARM PLL Configuration 0 Register, offset: 0x28 */
    UINT32 ARM_PLL_CFG1;                           /**< ARM PLL Configuration 1 Register, offset: 0x2C */
    UINT32 SYS_PLL1_CFG0;                          /**< System PLL Configuration 0 Register, offset: 0x30 */
    UINT32 SYS_PLL1_CFG1;                          /**< System_PLL Configuration 1 Register, offset: 0x34 */
    UINT32 SYS_PLL1_CFG2;                          /**< System_PLL Configuration 2 Register, offset: 0x38 */
    UINT32 SYS_PLL2_CFG0;                          /**< System PLL Configuration 0 Register, offset: 0x3C */
    UINT32 SYS_PLL2_CFG1;                          /**< System_PLL Configuration 1 Register, offset: 0x40 */
    UINT32 SYS_PLL2_CFG2;                          /**< System_PLL Configuration 2 Register, offset: 0x44 */
    UINT32 SYS_PLL3_CFG0;                          /**< System PLL Configuration 0 Register, offset: 0x48 */
    UINT32 SYS_PLL3_CFG1;                          /**< System_PLL Configuration 1 Register, offset: 0x4C */
    UINT32 SYS_PLL3_CFG2;                          /**< System_PLL Configuration 2 Register, offset: 0x50 */
    UINT32 VIDEO_PLL2_CFG0;                        /**< VIDEO PLL2 Configuration 0 Register, offset: 0x54 */
    UINT32 VIDEO_PLL2_CFG1;                        /**< VIDEO PLL2 Configuration 1 Register, offset: 0x58 */
    UINT32 VIDEO_PLL2_CFG2;                        /**< VIDEO PLL2 Configuration 2 Register, offset: 0x5C */
    UINT32 DRAM_PLL_CFG0;                          /**< DRAM PLL Configuration 0 Register, offset: 0x60 */
    UINT32 DRAM_PLL_CFG1;                          /**< DRAM PLL Configuration 1 Register, offset: 0x64 */
    UINT32 DRAM_PLL_CFG2;                          /**< DRAM PLL Configuration 2 Register, offset: 0x68 */
    UINT32 DIGPROG;                                /**< DIGPROG Register, offset: 0x6C */
    UINT32 OSC_MISC_CFG;                           /**< Osc Misc Configuration Register, offset: 0x70 */
    UINT32 PLLOUT_MONITOR_CFG;                     /**< PLLOUT Monitor Configuration Register, offset: 0x74 */
    UINT32 FRAC_PLLOUT_DIV_CFG;                    /**< Fractional PLLOUT Divider Configuration Register, offset: 0x78 */
    UINT32 SCCG_PLLOUT_DIV_CFG;                    /**< SCCG PLLOUT Divider Configuration Register, offset: 0x7C */
} IMX8MQ_CCM_ANALOG_REGISTERS, *PIMX8MQ_CCM_ANALOG_REGISTERS;

/*! @name ARM_PLL_CFG0 - ARM PLL Configuration 0 Register */
/*! @{ */
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_OUTPUT_DIV_VAL_MASK (0x1FU)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_OUTPUT_DIV_VAL_SHIFT (0U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_OUTPUT_DIV_VAL(x) (((UINT32)(((UINT32)(x)) << IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_OUTPUT_DIV_VAL_SHIFT)) & IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_OUTPUT_DIV_VAL_MASK)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_DIV_VAL_MASK (0x7E0U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_DIV_VAL_SHIFT (5U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_DIV_VAL(x) (((UINT32)(((UINT32)(x)) << IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_DIV_VAL_SHIFT)) & IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_DIV_VAL_MASK)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_NEWDIV_ACK_MASK (0x800U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_NEWDIV_ACK_SHIFT (11U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_NEWDIV_VAL_MASK (0x1000U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_NEWDIV_VAL_SHIFT (12U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_COUNTCLK_SEL_MASK (0x2000U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_COUNTCLK_SEL_SHIFT (13U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_BYPASS_MASK  (0x4000U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_BYPASS_SHIFT (14U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_LOCK_SEL_MASK (0x8000U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_LOCK_SEL_SHIFT (15U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_SEL_MASK (0x30000U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_SEL_SHIFT (16U)
/*! PLL_REFCLK_SEL
 *  0b00..25M_REF_CLK
 *  0b01..27M_REF_CLK
 *  0b10..HDMI_PHY_27M_CLK
 *  0b11..CLK_P_N
 */
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_SEL(x) (((UINT32)(((UINT32)(x)) << IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_SEL_SHIFT)) & IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_SEL_MASK)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_PD_OVERRIDE_MASK (0x40000U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_PD_OVERRIDE_SHIFT (18U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_PD_MASK      (0x80000U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_PD_SHIFT     (19U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_CLKE_OVERRIDE_MASK (0x100000U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_CLKE_OVERRIDE_SHIFT (20U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_CLKE_MASK    (0x200000U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_CLKE_SHIFT   (21U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_LOCK_MASK    (0x80000000U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_LOCK_SHIFT   (31U)
 /*! @} */


 /*! @name ARM_PLL_CFG1 - ARM PLL Configuration 1 Register */
 /*! @{ */
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_INT_DIV_CTL_MASK (0x7FU)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_INT_DIV_CTL_SHIFT (0U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_INT_DIV_CTL(x) (((UINT32)(((UINT32)(x)) << IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_INT_DIV_CTL_SHIFT)) & IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_INT_DIV_CTL_MASK)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_FRAC_DIV_CTL_MASK (0x7FFFFF80U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_FRAC_DIV_CTL_SHIFT (7U)
#define IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_FRAC_DIV_CTL(x) (((UINT32)(((UINT32)(x)) << IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_FRAC_DIV_CTL_SHIFT)) & IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_FRAC_DIV_CTL_MASK)
/*! @} */

/*! @name FRAC_PLLOUT_DIV_CFG - Fractional PLLOUT Divider Configuration Register */
/*! @{ */
#define CCM_ANALOG_FRAC_PLLOUT_DIV_CFG_ARM_PLL_DIV_VAL_MASK (0x700000U)
#define CCM_ANALOG_FRAC_PLLOUT_DIV_CFG_ARM_PLL_DIV_VAL_SHIFT (20U)
/*! @} */

#endif