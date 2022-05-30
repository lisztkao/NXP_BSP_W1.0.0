/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License.

Module Name:

    device.h

Abstract:

    This file contains the device definitions.

Environment:

    Kernel-mode Driver Framework
--*/

#include "public.h"

EXTERN_C_START

//
// Defines
//
#define REUSABLE_MEM_BLOCKS_MAX  2
#define VPU_MEM_ALIGN            0x1000
#define VPU_BITS_BUF_SIZE        (16*1024*1024)//bitstream buffer size : big enough contain two big frames
#define STREAM_BUFF_CACHE_TYPE   MmWriteCombined

//
// Memory occupation enum
//
enum occupation {
    ONE_TIME_MEM = 0,
    REUSABLE,
    OCCUPIED
};

//
// Memory allocation list
//
typedef struct _VpuAlloc {
    struct _VpuAlloc *next;
    void * virtAddr;
    intptr_t physAddr;
    PMDL mdl;
    WDFFILEOBJECT file;
    ULONG occupied;
} VpuAlloc;

//
// The device context performs the same job as
// a WDM device extension in the driver frameworks
//
typedef struct {
    WDFDEVICE WdfDevice;
    IMXVPU_REGISTERS* RegistersPtr;
    ULONG RegistersLen;
    PMDL MdlRegisters;  // MDL of VPU registers
    VpuAlloc memList;   // list of allocated memory blocks
    ULONG memCounter;   // counter of allocated reusable memory blocks
    VpuAlloc **preallocated_mem;
    WDFFILEOBJECT vpuOwner[2]; // current owner of VPU device
    WDFQUEUE waitQueue[2]; // Operations waiting for VPU access

//  WDFINTERRUPT WdfInterrupt;
//  WDFREQUEST CurrentRequest;
//  WDFSTRING DeviceInterfaceSymlinkName;
//  UNICODE_STRING DeviceInterfaceSymlinkNameWsz;

    //
    // HW State
    //

    FAST_MUTEX Mutex;       // mutex to guard memList
    WDFWAITLOCK ControllerLock;     // A lock to protect the vpu

} IMXVPU_DEVICE_CONTEXT; // struct IMXVPU_DEVICE_CONTEXT

//
// This macro will generate an inline function called DeviceGetContext
// which will be used to get a pointer to the device context memory
// in a type safe manner.
//
WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(IMXVPU_DEVICE_CONTEXT, DeviceGetContext);

//
// Function to initialize the device and its callbacks
//
NTSTATUS
OnCreateDevice(
    _Inout_ PWDFDEVICE_INIT DeviceInit
    );

EXTERN_C_END
