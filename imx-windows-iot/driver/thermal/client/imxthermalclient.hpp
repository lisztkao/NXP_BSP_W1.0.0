/*++
Copyright (c) Microsoft Corporation. All rights reserved.
Copyright 2020 NXP

Module Name:
    imxthermalclient.hpp

Abstract:
    This is the header file for the imx8M thermal client driver
--*/

#ifndef _IMXTC_HPP_
#define _IMXTC_HPP_

//--------------------------------------------------------------------- Pragmas

#pragma once

//-------------------------------------------------------------------- Includes

#include <ntddk.h>
#include <wdf.h>
#include <ntstrsafe.h>
#include <initguid.h>
#include <wdmguid.h>
#include <poclass.h>
#include <gpio.h>
#define RESHUB_USE_HELPER_ROUTINES
#include <reshub.h>

//----------------------------------------------------------------- Definitions

#define TC_MCU_OPP_TABLE_MAX_RECORDS    16

#define IMXTC_PAGED_SEGMENT_BEGIN \
    __pragma(code_seg(push)) \
    __pragma(code_seg("PAGE"))

#define IMXTC_PAGED_SEGMENT_END \
    __pragma(code_seg(pop))

#define IMXTC_INIT_SEGMENT_BEGIN \
    __pragma(code_seg(push)) \
    __pragma(code_seg("INIT"))

#define IMXTC_INIT_SEGMENT_END \
    __pragma(code_seg(pop))

enum TC_PLL_TYPE {
    TC_IMX8MQ_FRAC_PLL = 0x00,
    TC_UNKNOWN_PLL_TYPE = 0xFF
};

const CHAR* TC_PLL_NAMES[] = {
    "imx8mqFracPll"
};

typedef struct {
    ULONG               PllMinFrequencyHz;
    ULONG               PllMaxFrequencyHz;
    ULONG               PllReferenceFrequencyHz;
} TC_PLL_FEATURE;

typedef struct {
    ULONG               CoreFrequencyHz;
    ULONG               CorePower_uV;
} TC_MCU_OPP_TABLE;

typedef struct {
    LARGE_INTEGER       GpioConnectionId;
    WDFIOTARGET         hGPIOIoTarget;
    WDFREQUEST          hGPIOIoctlRequest;               // Request that we recieved from I/O queue.
    WDFMEMORY           hGPIOWdfMemory;
    UINT8               GPIOIoctlData;
    WDF_REQUEST_SEND_OPTIONS GPIOWfdReqSendOptions;
} TC_GPIO_PIN;

typedef struct {
    ULONG               ThermalLevel;
    PHYSICAL_ADDRESS    RegistersPhysicalAddress;
    SIZE_T              RegistersPhysicalSize;
    volatile VOID       *RegistersPtr;

    ULONG               McuBootFrequencyHz;

    TC_PLL_FEATURE      PllFeature;
    TC_PLL_TYPE         PllType;

    TC_MCU_OPP_TABLE    McuOppTable[TC_MCU_OPP_TABLE_MAX_RECORDS];
    ULONG               McuOppTableRecords;

    TC_GPIO_PIN         GpioPin;
} FDO_DATA, *PFDO_DATA;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(FDO_DATA, GetDeviceExtension);

extern "C" DRIVER_INITIALIZE DriverEntry;
#endif