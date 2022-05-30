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

#ifndef _LCDIF_H_
#define _LCDIF_H_

#include <stdint.h>
#include <stdbool.h>
#include <iMX8.h>
#include <iMXDisplay.h>

VOID LcdifReset(VOID);
EFI_STATUS LcdifEnable(bool Enable);
VOID LcdifInit(uintptr_t FrameBuffer);
EFI_STATUS LcdifSetTimingMode(IMX_DISPLAY_TIMING* Timing);
VOID LcdifDump(VOID);

#endif  /* _LCDIF_H_ */