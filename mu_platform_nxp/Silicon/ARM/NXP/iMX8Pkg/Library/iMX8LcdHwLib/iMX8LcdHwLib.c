/** @file

  Copyright (c) 2020, Linaro, Ltd. All rights reserved.
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
#include <LcdPlatformLib.h>
#include <Library/MemoryAllocationLib.h>

#include <iMXDisplay.h>
#include <iMXI2cLib.h>
#include "adv7535.h"
#include "Lcdif.h"
#include "MipiDsi.h"
#include "iMX8.h"

/* EDID macros */
#define BASIC_EDID_STRUCTURE_LENGTH       128

#define EDID_MANUFACTURER_ID_REG_OFFSET   8
#define EDID_MANUFACTURER_ID_REG_MASK     0xFFFF

#define EDID_VERSION_REG_OFFSET           18
#define EDID_REVISION_REG_OFFSET          19

#define EDID_NUM_OF_EXTENSIONS_REG_OFFSET 126

#define SHORT_VIDEO_BLOCK                 0x02

/* Preferred timing mode read from EDID */
IMX_DISPLAY_TIMING PreferredTiming;
/* Count of the read modes */
int videoModesCnt = 0;

/* Display interfaces */
typedef enum {
 imxNativeHdmi = 0,
 imxMipiDsi = 1,
 imxInterfaceUnknown,
} imxDisplayInterfaceType;

/* Get display interface type defined in *.dsc file */
imxDisplayInterfaceType displayInterface = FixedPcdGet32(PcdDisplayInterface);
/* Type of MIPI DSI converter */
imxMipiDsiToHdmiConverter MipiDsiConverter = transmitterUnknown;

/* ******************************* Low level functions ******************************* */
/**
  Dump preferred timing mode read from EDID
  @param  DtdOffset                Display timing descriptor offset.
  @param  Timing                   Display timing mode.
**/
static VOID
LcdDumpDisplayTiming (
  IN uint32_t            DtdOffset,
  IN IMX_DISPLAY_TIMING *Timing
  )
{
  DEBUG ((DEBUG_INFO, "*************************************************\n"));
  DEBUG ((DEBUG_INFO, "* DTD(0x%02X)\n",DtdOffset));
  DEBUG ((DEBUG_INFO, "*************************************************\n"));
  DEBUG ((DEBUG_INFO, "Timing->PixelClock =      %d\n",    Timing->PixelClock));
  DEBUG ((DEBUG_INFO, "Timing->HActive =         %d\n",    Timing->HActive));
  DEBUG ((DEBUG_INFO, "Timing->HBlank =          %d\n",    Timing->HBlank));
  DEBUG ((DEBUG_INFO, "Timing->VActive =         %d\n",    Timing->VActive));
  DEBUG ((DEBUG_INFO, "Timing->VBlank =          %d\n",    Timing->VBlank));
  DEBUG ((DEBUG_INFO, "Timing->HSync =           %d\n",    Timing->HSync));
  DEBUG ((DEBUG_INFO, "Timing->VSync =           %d\n",    Timing->VSync));
  DEBUG ((DEBUG_INFO, "Timing->HSyncOffset =     %d\n",    Timing->HSyncOffset));
  DEBUG ((DEBUG_INFO, "Timing->VSyncOffset =     %d\n",    Timing->VSyncOffset));
  DEBUG ((DEBUG_INFO, "Timing->HImageSize =      %d\n",    Timing->HImageSize));
  DEBUG ((DEBUG_INFO, "Timing->VImageSize =      %d\n",    Timing->VImageSize));
  DEBUG ((DEBUG_INFO, "Timing->HBorder =         %d\n",    Timing->HBorder));
  DEBUG ((DEBUG_INFO, "Timing->VBorder =         %d\n",    Timing->VBorder));
  DEBUG ((DEBUG_INFO, "Timing->EdidFlags =       0x%0X\n", Timing->EdidFlags));
  DEBUG ((DEBUG_INFO, "Timing->Flags =           0x%0X\n", Timing->Flags));
  DEBUG ((DEBUG_INFO, "Timing->PixelRepetition = %d\n",    Timing->PixelRepetition));
  DEBUG ((DEBUG_INFO, "Timing->Bpp =             %d\n",    Timing->Bpp));
  DEBUG ((DEBUG_INFO, "Timing->PixelFormat =     %d\n",    Timing->PixelFormat));
}

/**
  Read display EDID.

  @param  edid                   Buffer for EDID data.
  @retval EFI_SUCCESS            Platform implements display.
  @retval EFI_NOT_FOUND          Display not found on the platform.

**/
static EFI_STATUS
LcdReadEdid (
  OUT uint8_t *edid,
  IN uint32_t offset,
  IN uint32_t length
  )
{
  EFI_STATUS status = EFI_SUCCESS;

  if(displayInterface == imxMipiDsi) {
    if(MipiDsiConverter == ADV7535) {
      /* For now read only standard EDID structure , ignore EDID extensions */
      status = Adv7535ReadEdid(edid, offset, length);
    }
  }

  return status;
}

/* ******************************* High level functions ******************************* */
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
  EFI_STATUS         status;
  uint8_t           *edid;
  int                edid_extensions = 0;

  /* Search for one of supported MIPI_DSI to HDMI transceiver */ 
  if (displayInterface == imxMipiDsi) {
    if (MipiDsiConverter == transmitterUnknown) {
      do {
        /* Search for ADV7535 */
        status = Adv7535Discover();
        if (status == EFI_SUCCESS) {
          DEBUG((DEBUG_INFO, "ADV7535 search SUCCEDED\n"));
          MipiDsiConverter = ADV7535;
          break;
        }
        /* Add new decoder here */
      } while(0);
    }
    DEBUG((DEBUG_INFO, "MIPI_DSI to HDMI transmitter: %d\n", MipiDsiConverter));
    if(MipiDsiConverter == transmitterUnknown) {
      DEBUG((DEBUG_ERROR, "No MIPI_DSI to HDMI transmitter detected.\n"));
      return EFI_NOT_FOUND;
    }
  }

  /* Allocate memory for EDID structure */
  edid = AllocatePool(BASIC_EDID_STRUCTURE_LENGTH + 1);

  /* Read EDID */
  status = LcdReadEdid(edid, 0, BASIC_EDID_STRUCTURE_LENGTH);
  if (EFI_ERROR(status)) {
    DEBUG((DEBUG_ERROR, "Unable to read EDID\n"));
    goto End;
  }

  /* Ignore extensions */
  edid_extensions = edid[126];
  DEBUG((DEBUG_ERROR, "EDID Version: %d.%d\n",edid[EDID_VERSION_REG_OFFSET],edid[EDID_REVISION_REG_OFFSET]));
  DEBUG((DEBUG_INFO, "EDID Num of Extensions: %d\n", edid_extensions));


  /* Validate EDID data to */
  status = ImxValidateEdidData(edid);
  if (EFI_ERROR(status)) {
    DEBUG((DEBUG_ERROR, "EDID data not valid\n"));
    goto End;
  }

  /* Read first DTD, which is the most preferred */
  for (int dtd_idx = IMX_EDID_DTD_1_OFFSET; dtd_idx <= IMX_EDID_DTD_1_OFFSET; dtd_idx += IMX_EDID_DTD_SIZE) {
    /* Convert EDID data into internal format */
    status = ImxConvertDTDToDisplayTiming((IMX_DETAILED_TIMING_DESCRIPTOR *)&edid[dtd_idx],
                                        &PreferredTiming);
    if (status != EFI_SUCCESS) {
      DEBUG((DEBUG_ERROR, "Conversion to display timing failed\n"));
      goto End;
    }
    videoModesCnt++;
    /* BPP is fixed to 24 (8 bits per color component) */
    PreferredTiming.Bpp = 24;
    LcdDumpDisplayTiming(dtd_idx, &PreferredTiming);
  }
End:
  FreePool(edid);
  return status;
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
  /* Reset MIPI-DSI & LCDIF */
  MipiDsiReset();
  LcdifReset();

  /* Basic LCDIF config */
  LcdifInit(FrameBaseAddress);
  
  return EFI_SUCCESS;
}

/** Return information for the requested mode number.

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
  if (ModeNumber >= videoModesCnt){
    return EFI_INVALID_PARAMETER;
  }

  ASSERT (Info != NULL);

  Info->Version = 0;

  Info->HorizontalResolution = PreferredTiming.HActive;
  Info->VerticalResolution = PreferredTiming.VActive;;
  Info->PixelsPerScanLine = PreferredTiming.HActive;

  Info->PixelFormat = PixelBlueGreenRedReserved8BitPerColor;

  return EFI_SUCCESS;
}

/** Return total number of modes supported.

  Note: Valid mode numbers are 0 to MaxMode - 1
  See Section 12.9 of the UEFI Specification 2.7

  @retval UINT32             Number of video modes.
**/
UINT32
LcdGetVideoModesCnt (VOID)
{
  return videoModesCnt;
}

/** Return bits per pixel information for a mode number.

  @param  ModeNumber          Mode Number.
  @param Bpp                 Pointer to bits per pixel information.

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
  EFI_STATUS status;

  if (ModeNumber >= videoModesCnt) {
     status = EFI_INVALID_PARAMETER;
     goto End;
  }
  ASSERT (Bpp != NULL);

  switch (PreferredTiming.Bpp) {
    case 24U:
      *Bpp = LCD_BITS_PER_PIXEL_24;
      break;
    default:
      DEBUG ((DEBUG_ERROR, "LcdGetBpp() - Unsupported bpp\n"));
      status = EFI_INVALID_PARAMETER;
      break;
  }

End:
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
  IN  UINT32     ModeNumber
  )
{
  EFI_STATUS status;
  IMX_DISPLAY_TIMING *Timing = &PreferredTiming;
  
  if (ModeNumber >= videoModesCnt) {
    return EFI_INVALID_PARAMETER;
  }

  /* Mipi DSI set timing mode */
  if ((status = MipiDsiConfig(Timing,MipiDsiConverter)) != EFI_SUCCESS) {
    DEBUG ((DEBUG_ERROR, "MIPI DSI config failed, status=%d\n", status));
    goto End;
  }
  if (displayInterface == imxMipiDsi) {
    if (MipiDsiConverter == ADV7535) {
      /* ADV7535 set timing mode */
      if ((status = Adv7535SetMode(Timing)) != EFI_SUCCESS) {
        DEBUG ((DEBUG_ERROR, "ADV7535 config failed, status=%d\n", status));
        goto End;
      }
    }
  }

  /* LCDIF set timing mode */
  if ((status = LcdifSetTimingMode(Timing)) != EFI_SUCCESS) {
    DEBUG ((DEBUG_ERROR, "LCDIF config failed, status=%d\n", status));
    goto End;
  }

  /* Enable LCDIF */
  if ((status = LcdifEnable(TRUE)) != EFI_SUCCESS) {
    DEBUG ((DEBUG_ERROR, "LCDIF enable failed, status=%d\n", status));
    goto End;
  }
#if 0
  LcdifDump();
  MipiDsiDump();
#endif
  End:
    return status;
}

/**
  De-initializes the display.
**/
EFI_STATUS
LcdShutdown (
  VOID
  )
{
  EFI_STATUS status = EFI_SUCCESS;

  /* Disable LCDIF */
  if ((status = LcdifEnable(FALSE)) != EFI_SUCCESS) {
    DEBUG ((DEBUG_ERROR, "LCDIF disable failed, status=%d\n", status));
  }
  return status;
}
