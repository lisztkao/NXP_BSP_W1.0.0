/** @file

  Copyright 2020 NXP

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef ADV7535_H_
#define ADV7535_H_

#define ADV7535_REG_CHIP_REVISION                   0x0
#define ADV7535_REG_CHIP_REVISION_VALUE             0x14

#define ADV7535_REG_COL_SPACE                       0x16
#define ADV7535_REG_COL_SPACE__FIXED                0x20

#define ADV7535_REG_SYNC_POL_DE_EN                  0x17
#define ADV7535_REG_SYNC_POL_DE_EN__VSYNC_HIGH      0x00
#define ADV7535_REG_SYNC_POL_DE_EN__VSYNC_LOW       0x40
#define ADV7535_REG_SYNC_POL_DE_EN__HSYNC_HIGH      0x00
#define ADV7535_REG_SYNC_POL_DE_EN__HSYNC_LOW       0x20
#define ADV7535_REG_SYNC_POL_DE_EN__DE_DISABLE      0x00
#define ADV7535_REG_SYNC_POL_DE_EN__DE_ENABLE       0x01

#define ADV7535_REG_PACKET                          0x40
#define ADV7535_REG_PACKET__GC_PKT_EN               0x80
#define ADV7535_REG_PACKET__SPD_PKT_EN              0x40
#define ADV7535_REG_PACKET__MPEG_PKT_EN             0x20
#define ADV7535_REG_PACKET__ACP_PKT_EN              0x10
#define ADV7535_REG_PACKET__ISRC_PKT_EN             0x08
#define ADV7535_REG_PACKET__GM_PKT_EN               0x04
#define ADV7535_REG_PACKET__SPARE_PKT1_EN           0x02
#define ADV7535_REG_PACKET__SPARE_PKT0_EN           0x01

#define ADV7535_REG_PD_RESET                        0x41
#define ADV7535_REG_PD_RESET__POWER_DOWN            0x40
#define ADV7535_REG_PD_RESET__POWER_UP              0x00
#define ADV7535_REG_PD_RESET__RESET_ENABLED         0x20
#define ADV7535_REG_PD_RESET__RESET_DISABLED        0x00
#define ADV7535_REG_PD_RESET__FIXED                 0x10

#define ADV7535_REG_EDID_ADDR                       0x43

#define ADV7535_REG_PACKET2                         0x44
#define ADV7535_REG_PACKET2__NCTS_PKT_EN            0x40
#define ADV7535_REG_PACKET2__AUD_SAMP_PKT_EN        0x20
#define ADV7535_REG_PACKET2__AVIIF_PKT_EN           0x10
#define ADV7535_REG_PACKET2__AUDIOIF_PKT_EN         0x08
#define ADV7535_REG_PACKET2__FIXED                  0x01

#define ADV7535_REG_DOWN_DITHER                     0x49
#define ADV7535_REG_DOWN_DITHER__S0_AD              0x00
#define ADV7535_REG_DOWN_DITHER__S0_ROUNDUP         0x40
#define ADV7535_REG_DOWN_DITHER__S0_ROUNDDOWN       0x80
#define ADV7535_REG_DOWN_DITHER__S0_NORMROUND       0xC0
#define ADV7535_REG_DOWN_DITHER__S1_AD              0x00
#define ADV7535_REG_DOWN_DITHER__S1_ROUNDUP         0x10
#define ADV7535_REG_DOWN_DITHER__S1_ROUNDDOWN       0x20
#define ADV7535_REG_DOWN_DITHER__S1_NORMROUND       0x30
#define ADV7535_REG_DOWN_DITHER__S2_AD              0x00
#define ADV7535_REG_DOWN_DITHER__S2_ROUNDUP         0x04
#define ADV7535_REG_DOWN_DITHER__S2_ROUNDDOWN       0x08
#define ADV7535_REG_DOWN_DITHER__S2_NORMROUND       0x0C
#define ADV7535_REG_DOWN_DITHER__COL_DEP_8          0x00
#define ADV7535_REG_DOWN_DITHER__COL_DEP_10         0x01
#define ADV7535_REG_DOWN_DITHER__COL_DEP_12         0x02

#define ADV7535_REG_INFOFRM_0X4A                    0x4A
#define ADV7535_REG_INFOFRM_0X4A__AUTO_CHKSUM_EN    0x80
#define ADV7535_REG_INFOFRM_0X4A__AUTO_CHKSUM_DIS   0x00
#define ADV7535_REG_INFOFRM_0X4A__AVI_UPDATE        0x40
#define ADV7535_REG_INFOFRM_0X4A__AUDIO_UPDATE      0x20
#define ADV7535_REG_INFOFRM_0X4A__GCP_UPDATE        0x10
#define ADV7535_REG_INFOFRM_0X4A__NOLOW_RFRESH      0x00
#define ADV7535_REG_INFOFRM_0X4A__LOW_RFRESH_24     0x04
#define ADV7535_REG_INFOFRM_0X4A__LOW_RFRESH_25     0x08
#define ADV7535_REG_INFOFRM_0X4A__LOW_RFRESH_30     0x0C

#define ADV7535_REG_COL_DEP_DOWN                    0x4C
#define ADV7535_REG_COL_DEP_DOWN__NOCOL             0x00
#define ADV7535_REG_COL_DEP_DOWN__24BPP             0x04
#define ADV7535_REG_COL_DEP_DOWN__30BPP             0x05
#define ADV7535_REG_COL_DEP_DOWN__36BPP             0x06

#define ADV7535_REG_AVI_INFOFRM_0X55                0x55
#define ADV7535_REG_AVI_INFOFRM_0X55__Y1Y0_RGB      0x00
#define ADV7535_REG_AVI_INFOFRM_0X55__Y1Y0_422      0x20
#define ADV7535_REG_AVI_INFOFRM_0X55__Y1Y0_444      0x40
#define ADV7535_REG_AVI_INFOFRM_0X55__ACTIVE_VAL    0x10
#define ADV7535_REG_AVI_INFOFRM_0X55__NO_DATA       0x00
#define ADV7535_REG_AVI_INFOFRM_0X55__B1B0_NOBAR    0x00
#define ADV7535_REG_AVI_INFOFRM_0X55__B1B0_VBAR     0x04
#define ADV7535_REG_AVI_INFOFRM_0X55__B1B0_HBAR     0x08
#define ADV7535_REG_AVI_INFOFRM_0X55__B1B0_HVBAR    0x0C
#define ADV7535_REG_AVI_INFOFRM_0X55__S1S0_NOINFO   0x00
#define ADV7535_REG_AVI_INFOFRM_0X55__S1S0_TV       0x01
#define ADV7535_REG_AVI_INFOFRM_0X55__S1S0_PC       0x02

#define ADV7535_REG_AVI_INFOFRM_0X56                0x56
#define ADV7535_REG_AVI_INFOFRM_0X56__C1C0_NODATA   0x00
#define ADV7535_REG_AVI_INFOFRM_0X56__C1C0_ITU601   0x40
#define ADV7535_REG_AVI_INFOFRM_0X56__C1C0_ITU709   0x80
#define ADV7535_REG_AVI_INFOFRM_0X56__M1M0_NODATA   0x00
#define ADV7535_REG_AVI_INFOFRM_0X56__M1M0_4_3      0x10
#define ADV7535_REG_AVI_INFOFRM_0X56__M1M0_16_9     0x20
#define ADV7535_REG_AVI_INFOFRM_0X56__R_NDEF        0x00
#define ADV7535_REG_AVI_INFOFRM_0X56__R_SAME        0x08
#define ADV7535_REG_AVI_INFOFRM_0X56__R_4_3         0x09
#define ADV7535_REG_AVI_INFOFRM_0X56__R_16_9        0x0A
#define ADV7535_REG_AVI_INFOFRM_0X56__R_14_9        0x0B

#define ADV7535_REG_INT                             0x96
#define ADV7535_REG_INT__HPD                        0x80
#define ADV7535_REG_INT__RX_SENSE                   0x40
#define ADV7535_REG_INT__VSYNC                      0x20
#define ADV7535_REG_INT__AUDIO_FIFO_FULL            0x10
#define ADV7535_REG_INT__EDID_READY                 0x04
#define ADV7535_REG_INT__HDCP_AUTHENTICATED         0x02
#define ADV7535_REG_INT__RI_READY                   0x01

#define ADV7535_REG_MAIN_FIXED_0X9A                 0x9A
#define ADV7535_REG_MAIN_FIXED_0X9A__FIXED          0xE0

#define ADV7535_REG_HDCP_VOUT_SEL                   0xAF
#define ADV7535_REG_HDCP_VOUT_SEL__DVI              0x00
#define ADV7535_REG_HDCP_VOUT_SEL__HDMI             0x02
#define ADV7535_REG_HDCP_VOUT_SEL__HDCP_EN          0x80
#define ADV7535_REG_HDCP_VOUT_SEL__HDCP_DIS         0x00
#define ADV7535_REG_HDCP_VOUT_SEL__HDCP_FRM_EN      0x10
#define ADV7535_REG_HDCP_VOUT_SEL__HDCP_FRM_DIS     0x00
#define ADV7535_REG_HDCP_VOUT_SEL__FIXED            0x04

#define ADV7535_REG_HDCP_RI                         0xBA
#define ADV7535_REG_HDCP_RI__FIXED                  0x70

#define ADV7535_REG_EDID_SEGMENT		            0xC4

#define ADV7535_REG_HDCP_STATE                      0xC8
#define ADV7535_REG_HDCP_STATE__IN_RESET            0x00
#define ADV7535_REG_HDCP_STATE__EDID_READ           0x01
#define ADV7535_REG_HDCP_STATE__IDLE                0x02
#define ADV7535_REG_HDCP_STATE__HDCP_INIT           0x03
#define ADV7535_REG_HDCP_STATE__HDCP_ENABLED        0x04
#define ADV7535_REG_HDCP_STATE__HDCP_REPEATER       0x05

#define ADV7535_REG_EDID                            0xC9
#define ADV7535_REG_EDID__REREAD                    0x10
#define ADV7535_REG_EDID__TRIES_3                   0x03

#define ADV7535_REG_HPD_OVERRIDE                    0xD6
#define ADV7535_REG_HPD_OVERRIDE__ENABLE            0x48
#define ADV7535_REG_HPD_OVERRIDE__DISABLE           0x08

#define ADV7535_REG_MAIN_FIXED_0XDE                 0xDE
#define ADV7535_REG_MAIN_FIXED_0XDE__FIXED          0x82

#define ADV7535_REG_DSI_CEC_ADDR                    0xE1

#define ADV7535_REG_DSI_CEC_PD                      0xE2
#define ADV7535_REG_DSI_CEC_PD__POWER_UP            0x00
#define ADV7535_REG_DSI_CEC_PD__RESET               0x01

#define ADV7535_REG_V1P8                            0xE4
#define ADV7535_REG_V1P8__FIXED                     0x40

#define ADV7535_REG_MAIN_FIXED_0XE5                 0xE5
#define ADV7535_REG_MAIN_FIXED_0XE5__FIXED          0x80

#define ADV7535_REG_HDMI_LPOSC                      0x03
#define ADV7535_REG_HDMI_LPOSC__HDMI_OUT_EN         0x80
#define ADV7535_REG_HDMI_LPOSC__HDMI_OUT_DIS        0x00
#define ADV7535_REG_HDMI_LPOSC__LPOSC_PWRDOWN       0x02
#define ADV7535_REG_HDMI_LPOSC__LPOSC_PWRUP         0x00
#define ADV7535_REG_HDMI_LPOSC__FIXED               0x09

#define ADV7535_REG_CECDSI_FIXED_0X15               0x15
#define ADV7535_REG_CECDSI_FIXED_0X15__FIXED        0xD0

#define ADV7535_REG_PIX_CLK_DIV                     0x16
#define ADV7535_REG_PIX_CLK_DIV__MANUAL             0x04
#define ADV7535_REG_PIX_CLK_DIV__AUTO               0x00
#define ADV7535_REG_PIX_CLK_DIV__VALUE(x)           ((x) << 3)

#define ADV7535_REG_CECDSI_FIXED_0X17               0x17
#define ADV7535_REG_CECDSI_FIXED_0X17__FIXED        0xD0

#define ADV7535_REG_NUM_DSI_DATA_LANES              0x1C
#define ADV7535_REG_NUM_DSI_DATA_LANES__VALUE(x)    ((x) << 4)
#define ADV7535_REG_NUM_DSI_DATA_LANES__ONE         0x10
#define ADV7535_REG_NUM_DSI_DATA_LANES__TWO         0x20
#define ADV7535_REG_NUM_DSI_DATA_LANES__THREE       0x30
#define ADV7535_REG_NUM_DSI_DATA_LANES__FOUR        0x40

#define ADV7535_REG_CECDSI_FIXED_0X24               0x24
#define ADV7535_REG_CECDSI_FIXED_0X24__FIXED        0x20

#define ADV7535_REG_TIMING_GEN                      0x27
#define ADV7535_REG_TIMING_GEN__ENABLE              0x80
#define ADV7535_REG_TIMING_GEN__DISABLE             0x00
#define ADV7535_REG_TIMING_GEN__RESET_EN            0x40
#define ADV7535_REG_TIMING_GEN__RESET_DIS           0x00
#define ADV7535_REG_TIMING_GEN__FIXED               0x0B

#define ADV7535_REG_TG_FRM_WIDTH_HIGH               0x28
#define ADV7535_REG_TG_FRM_WIDTH_LOW                0x29

#define ADV7535_REG_TG_HSYNC_HIGH                   0x2A
#define ADV7535_REG_TG_HSYNC_LOW                    0x2B
#define ADV7535_REG_TG_HFP_HIGH                     0x2C
#define ADV7535_REG_TG_HFP_LOW                      0x2D
#define ADV7535_REG_TG_HBP_HIGH                     0x2E
#define ADV7535_REG_TG_HBP_LOW                      0x2F
#define ADV7535_REG_TG_FRM_HEIGHT_HIGH              0x30
#define ADV7535_REG_TG_FRM_HEIGHT_LOW               0x31
#define ADV7535_REG_TG_VSYNC_HIGH                   0x32
#define ADV7535_REG_TG_VSYNC_LOW                    0x33
#define ADV7535_REG_TG_VFP_HIGH                     0x34
#define ADV7535_REG_TG_VFP_LOW                      0x35
#define ADV7535_REG_TG_VBP_HIGH                     0x36
#define ADV7535_REG_TG_VBP_LOW                      0x37
#define ADV7535_REG_TG__HIGH_VAL(x)                 ((uint8_t)((x) >> 4))
#define ADV7535_REG_TG__LOW_VAL(x)                  ((uint8_t)((x) << 4))

#define ADV7535_REG_DSI_STATUS                      0x38
#define ADV7535_REG_DSI_STATUS__STATUS_CLR          0x80

#define ADV7535_REG_PATTERN_GEN                     0x55
#define ADV7535_REG_PATTERN_GEN__ENABLE             0x80
#define ADV7535_REG_PATTERN_GEN__DISABLE            0x00
#define ADV7535_REG_PATTERN_GEN__SEL_COL_BAR        0x00
#define ADV7535_REG_PATTERN_GEN__SEL_RAMP           0x20
#define ADV7535_REG_PATTERN_GEN__CLK_DSI            0x00
#define ADV7535_REG_PATTERN_GEN__CLK_CEC            0x10
#define ADV7535_REG_PATTERN_GEN__PROGRESSIVE        0x00
#define ADV7535_REG_PATTERN_GEN__INTERLACED         0x08

#define ADV7535_REG_CECDSI_FIXED_0X57               0x57
#define ADV7535_REG_CECDSI_FIXED_0X57__FIXED        0x11

#define ADV7535_REG_CEC_CLK_PWR                     0xBE
#define ADV7535_REG_CEC_CLK_PWR__CLKDIV(x)          ((uint8_t)(((x)-1) << 2))
#define ADV7535_REG_CEC_CLK_PWR__PWR_DOWN           0x00
#define ADV7535_REG_CEC_CLK_PWR__PWR_ACTIVE         0x01
#define ADV7535_REG_CEC_CLK_PWR__PWR_HPD            0x02

/* IIC address used to access ADV7535 main bank registers */
#define ADV7535_MAIN_IIC_SLAVE_ADDR                 (0x7A >> 1)

EFI_STATUS Adv7535Discover();
EFI_STATUS Adv7535ReadEdid(OUT uint8_t *edid, IN uint32_t offset, IN uint32_t length);
EFI_STATUS Adv7535SetMode(IN IMX_DISPLAY_TIMING *PreferredTiming);
EFI_STATUS Adv7535DumpRegister(IN IMX_I2C_CONTEXT *i2cConfig, IN uint8_t reg, IN char* reg_name);
EFI_STATUS ADV7535Dump();

#endif /* ADV7535_H_ */
