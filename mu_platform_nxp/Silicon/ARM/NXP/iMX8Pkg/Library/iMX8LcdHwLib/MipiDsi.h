/** @file
*
*  Copyright 2020 NXP
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/

#ifndef _MIPI_DSI_H_
#define _MIPI_DSI_H_

#include <stdint.h>
#include <stdbool.h>
#include <iMX8.h>
#include <iMXDisplay.h>

/* Fixed clock rates and limits */
#define DSI_MAX_ESC_CLOCK_KHZ         20000
#define DSI_MAX_HS_BIT_CLOCK_KHZ      2100000
#define DSI_MIN_HS_BIT_CLOCK_KHZ      80000
#define DSI_MIN_PLL_FVCO_HZ           1050000000UL
#define DSI_MAX_PLL_FVCO_HZ           2100000000UL
#define DSI_MIN_PLL_P                 1U
#define DSI_MAX_PLL_P                 4U
#define DSI_MIN_PLL_S                 0U
#define DSI_MAX_PLL_S                 5U
#define DSI_MIN_PLL_M                 64UL
#define DSI_MAX_PLL_M                 1023UL

#define DSI_HFP_PKT_OVERHEAD          6U
#define DSI_HBP_PKT_OVERHEAD          6U
#define DSI_HSA_PKT_OVERHEAD          6U

/* Subparts of PMS field in DSI_PLLCTRL */
#define DSI_PLLCTRL_P_SHIFT           (13)
#define DSI_PLLCTRL_P_MASK            (0x7FU << DSI_PLLCTRL_P_SHIFT)
#define DSI_PLLCTRL_P(v)              (((v) << DSI_PLLCTRL_P_SHIFT) & DSI_PLLCTRL_P_MASK)
#define DSI_PLLCTRL_M_SHIFT           (3)
#define DSI_PLLCTRL_M_MASK            (0x3FFU << DSI_PLLCTRL_M_SHIFT)
#define DSI_PLLCTRL_M(v)              (((v) << DSI_PLLCTRL_M_SHIFT) & DSI_PLLCTRL_M_MASK)
#define DSI_PLLCTRL_S_SHIFT           (0)
#define DSI_PLLCTRL_S_MASK            (0x7U << DSI_PLLCTRL_S_SHIFT)
#define DSI_PLLCTRL_S(v)              (((v) << DSI_PLLCTRL_S_SHIFT) & DSI_PLLCTRL_S_MASK)

#define CCM_TARGET_ROOT_PRE_MAX_DIV   8U
#define CCM_TARGET_ROOT_POST_MAX_DIV  64U
#define CCM_PLL_LOCK_TIMEOUT          10000U

/* List of supported MIPI DSI to HDMI converters */
typedef enum {
 ADV7535 = 0,
 transmitterUnknown,
} imxMipiDsiToHdmiConverter;

/* Video PLL parameters */
struct videoPllRateTable {
    uint32_t pixClockRate;
    uint32_t pllRate;
    uint32_t pdiv;
    uint32_t mdiv;
    uint32_t sdiv;
    uint32_t kdiv;
    uint32_t dsiPhyRefRate;
};

/* Initialization macro for Video PLL structure above */
#define PLL_RATE(pix_clock_val, rate_val, m_val, p_val, s_val, k_val, ref_rate_val) \
{ \
    .pixClockRate = (pix_clock_val), \
    .pllRate = (rate_val), \
    .mdiv = (m_val), \
    .pdiv = (p_val), \
    .sdiv = (s_val), \
    .kdiv = (k_val), \
    .dsiPhyRefRate = (ref_rate_val), \
}

/* MIPI DSI timing parameters */
struct dsiHblankPar {
    uint32_t hactive;
    uint32_t vactive;
    uint32_t refresh;
    uint32_t hfpWC;
    uint32_t hbpWC;
    uint32_t hsaWC;
    uint32_t lanes;
};

/* Initialization macro for MIPI DSI timing parameters structure above */
#define DSI_HBLANK_PARAM(hact, vact, rfrsh, hfp, hbp, hsa, num) \
    .hactive  = (hact), \
    .vactive  = (vact), \
    .refresh  = (rfrsh), \
    .hfpWC    = (hfp), \
    .hbpWC    = (hbp), \
    .hsaWC    = (hsa), \
    .lanes    = (num)

VOID CcmClockDump(VOID);
VOID MipiDsiReset(VOID);
EFI_STATUS MipiDsiConfig(IMX_DISPLAY_TIMING* Timing, imxMipiDsiToHdmiConverter MipiDsiConvertor);
VOID MipiDsiDump(VOID);

#endif  /* _MIPI_DSI_H_ */