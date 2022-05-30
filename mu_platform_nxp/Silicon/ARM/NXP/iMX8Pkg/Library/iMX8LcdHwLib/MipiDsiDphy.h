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

#ifndef _MIPI_DSI_DPHY_H_
#define _MIPI_DSI_DPHY_H_

#include <stdint.h>

/* DPHY timing parameters structure */
struct DSI_DPHY_TIMING {
    uint32_t tmgBitClkMHZ;
    uint32_t tmgClkPrepare;
    uint32_t tmgClkZero;
    uint32_t tmgClkPost;
    uint32_t tmgClkTrail;
    uint32_t tmgHsPrepare;
    uint32_t tmgHsZero;
    uint32_t tmgHsTrail;
    uint32_t tmgLpx;
    uint32_t tmgHsExit;
};

/* Initialization macro for DPHY timing structure */
#define DSI_DPHY_TIMING(bitclk, clkprepare, clkzero, clkpost, clktrail, \
                       hsprepare, hszero, hstrail, lpx, hsexit) \
    .tmgBitClkMHZ = bitclk, \
    .tmgClkPrepare = clkprepare, \
    .tmgClkZero = clkzero, \
    .tmgClkPost = clkpost, \
    .tmgClkTrail = clktrail, \
    .tmgHsPrepare = hsprepare, \
    .tmgHsZero = hszero, \
    .tmgHsTrail = hstrail, \
    .tmgLpx = lpx, \
    .tmgHsExit = hsexit

#endif  /* _MIPI_DSI_DPHY_H_ */