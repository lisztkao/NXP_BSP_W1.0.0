// Copyright (c) Microsoft Corporation. All rights reserved.
// Copyright 2020, 2022 NXP
// Licensed under the MIT License.
//
// Module Name:
//    imxtmu.h
// Abstract:
//    This is the header file for the TMU sensor driver.
//

#ifndef __IMXTMU_H__
#define __IMXTMU_H__

#pragma once

#include <ntddk.h>
#include <wdf.h>
#include <ntstrsafe.h>
#include <initguid.h>
#include <wdmguid.h>
#include <poclass.h>
#include "imxtmuhw.h"

#define KELVIN273   273

typedef struct _FDO_DATA_ {
    WDFQUEUE    PendingRequestQueue;
    WDFSPINLOCK QueueLock;
    WDFWORKITEM InterruptWorker;
    WDFINTERRUPT WdfInterrupt;
    WDFDEVICE WdfDevice;

    PHYSICAL_ADDRESS RegistersPhysicalAddress;
    ULONG RegistersIoSize;
    IMXTMU_REGISTERS *RegistersPtr;
} FDO_DATA, *PFDO_DATA;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(FDO_DATA, GetDeviceExtension);

typedef struct {
    LARGE_INTEGER ExpirationTime;
    ULONG HighTemperature;
    ULONG LowTemperature;
} READ_REQUEST_CONTEXT, *PREAD_REQUEST_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE(READ_REQUEST_CONTEXT);

#endif