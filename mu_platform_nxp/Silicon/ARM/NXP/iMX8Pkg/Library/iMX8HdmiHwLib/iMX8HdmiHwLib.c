/** @file

  Copyright (c) 2017, Linaro, Ltd. All rights reserved.
  Copyright 2020 NXP

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <Base.h>
#include <Uefi/UefiBaseType.h>
#include <Library/DebugLib.h>
#include <Library/LcdPlatformLib.h>
#include <Library/IoLib.h>

#include "iMX8HdmiCdn.h"
#include "iMX8.h"

/** Return bits per pixel information for a mode number.

  @param[in]  ModeNumber          Mode Number.

  @param[out] Bpp                 Pointer to bits per pixel information.

  @retval EFI_SUCCESS             Bits per pixel information for the requested
                                  mode returned successfully.
  @retval EFI_INVALID_PARAMETER   Requested mode not found.
**/
EFI_STATUS
LcdGetBpp (
  IN  UINT32     ModeNumber,
  OUT LCD_BPP  * Bpp
  )
{
  if (ModeNumber >= 1) {
    // Check valid ModeNumber and Bpp.
    return EFI_INVALID_PARAMETER;
  }

  ASSERT (Bpp != NULL);

  *Bpp = LCD_BITS_PER_PIXEL_24;

  return EFI_SUCCESS;
}

/**
  Check for presence of display

  @retval EFI_SUCCESS            Platform implements display.
  @retval EFI_NOT_FOUND          Display not found on the platform.

**/
EFI_STATUS
LcdDisplayDetect (
  VOID
  )
{
  return EFI_SUCCESS;
}

/**
  Initialize display.

  @param  FrameBaseAddress       Address of the frame buffer.
  @retval EFI_SUCCESS            Display initialization success.
  @retval !(EFI_SUCCESS)         Display initialization failure.

**/
EFI_STATUS
LcdInitialize (
  EFI_PHYSICAL_ADDRESS  FrameBaseAddress
  )
{
  // Configure new FrameBuffer address to CHAN1_DPR register
  *((volatile UINT32 *)(ARM_DC_MSTx_REG_REGISTER_PHYSICAL + 0x180C0UL)) = FrameBaseAddress;
  return EFI_SUCCESS;
}


/** Return total number of modes supported.

  Note: Valid mode numbers are 0 to MaxMode - 1
  See Section 12.9 of the UEFI Specification 2.7

  @retval UINT32             Zero number of modes supported
                             in a NULL library implementation.
**/
UINT32
LcdGetVideoModesCnt (
  VOID
  )
{
  return 1;
}

/** 
  Return information for the requested mode number.

  @param[in]  ModeNumber          Mode Number.

  @param[out] Info                Pointer for returned mode information
                                  (on success).

  @retval EFI_SUCCESS             Mode information for the requested mode
                                  returned successfully.
  @retval EFI_INVALID_PARAMETER   Requested mode not found.
**/
EFI_STATUS
LcdQueryMode (
  IN  UINT32                                  ModeNumber,
  OUT EFI_GRAPHICS_OUTPUT_MODE_INFORMATION  * Info
  )
{
  if (ModeNumber >= 1 ){
    return EFI_INVALID_PARAMETER;
  }

  ASSERT (Info != NULL);

  Info->Version = 0;

#if defined(CPU_IMX8MQ)
  Info->HorizontalResolution = HD720_H_RES_PIXELS;
  Info->VerticalResolution = HD720_V_RES_PIXELS;
  Info->PixelsPerScanLine = HD720_H_RES_PIXELS;
#else
#error "Unknown CPU family"
#endif

  Info->PixelFormat = PixelBlueGreenRedReserved8BitPerColor;

  return EFI_SUCCESS;
}

/**
  Set requested mode of the display.

  @param  ModeNumber             Display mode number.
  @retval EFI_SUCCESS            Display set mode success.
  @retval EFI_DEVICE_ERROR       If mode not found/supported.

**/
EFI_STATUS
LcdSetMode (
  IN UINT32  ModeNumber
  )
{
  // Enable HDMI
  HdmiCdnOn();

  return EFI_SUCCESS;
}

/**
  De-initializes the display.
**/
VOID
LcdShutdown (
  VOID
  )
{
}
