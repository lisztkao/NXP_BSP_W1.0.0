// Copyright (c) Microsoft Corporation. All rights reserved.
// Copyright 2020, 2022 NXP
// Licensed under the MIT License.
//
// Module Name:
//    imxtmu.c
// Abstract:
//    The module implements a sensor device.
//

#include <initguid.h>
#include <ntddk.h>
#include <wdf.h>
#include <ntddser.h>
#include <devpkey.h>
#include <acpiioct.h>
#include "acpiutil.hpp"

#include "precomp.h"

#include "imxtmu.hpp"
#include "imxtmuhw.h"

#include "trace.h"
#include "imxtmu.tmh"

// {FCB15302-14A9-4bf8-8A0B-888E0D33BEDE}
DEFINE_GUID(GUID_TEMPERATURE_SENSOR,
    0xfcb15302, 0x14a9, 0x4bf8, 0x8a, 0xb, 0x88, 0x8e, 0xd, 0x33, 0xbe, 0xde);

extern "C" DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD                   SensorDriverDeviceAdd;
EVT_WDF_OBJECT_CONTEXT_CLEANUP              EvtDriverContextCleanup;
EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL          SensorIoDeviceControl;
EVT_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL SensorIoInternalDeviceControl;
EVT_WDF_IO_QUEUE_IO_STOP                    SensorQueueIoStop;
EVT_WDF_TIMER                               SensorExpiredRequestTimer;


_IRQL_requires_(PASSIVE_LEVEL)
VOID
SensorAddReadRequest(
    _In_ WDFDEVICE Device,
    _In_ WDFREQUEST ReadRequest
);

_IRQL_requires_(DISPATCH_LEVEL)
NTSTATUS
SensorScanPendingQueue(
    _In_ WDFDEVICE Device
);

_IRQL_requires_(DISPATCH_LEVEL)
VOID
SensorCheckQueuedRequest(
    _In_ WDFDEVICE Device,
    _In_ ULONG Temperature,
    _Inout_ PULONG LowerBound,
    _Inout_ PULONG UpperBound,
    _In_ WDFREQUEST Request
);

_IRQL_requires_(DISPATCH_LEVEL)
BOOLEAN
SensorAreConstraintsSatisfied(
    _In_ ULONG Temperature,
    _In_ ULONG LowerBound,
    _In_ ULONG UpperBound,
    _In_ LARGE_INTEGER DueTime);

BOOLEAN
SensorTemperatureIsr(
    WDFINTERRUPT WdfInterrupt,
    ULONG /*MessageID*/
);

// Programming interface
VOID
SensorSetInterruptThresholds(
    _In_ WDFDEVICE Device,
    _In_ ULONG LowerBound,
    _In_ ULONG UpperBound
);

LONG
SensorReadTemperature(
    _In_ WDFDEVICE Device
);

// Internal routines
EVT_WDF_INTERRUPT_ISR SensorTemperatureIsr;
EVT_WDF_INTERRUPT_DPC SensorTemperatureDpc;
EVT_WDF_DEVICE_PREPARE_HARDWARE SensorPrepareHardware;
EVT_WDF_DEVICE_RELEASE_HARDWARE SensorReleaseHardware;

/*++
Routine Description:
    Driver ISR
Parameters Description:
    WdfInterrupt - Driver interrupt handle
    MessageID - Unused parameter
Return Value:
    NTSTATUS.
--*/
_Use_decl_annotations_
BOOLEAN
SensorTemperatureIsr (
    WDFINTERRUPT WdfInterrupt,
    ULONG MessageID
    )
{
    PFDO_DATA devExt = GetDeviceExtension(WdfInterruptGetDevice(WdfInterrupt));
    volatile IMXTMU_REGISTERS *registersPtr = devExt->RegistersPtr;

    UNREFERENCED_PARAMETER(MessageID);

    if (registersPtr->TIDR) {
        // Disable interrupts. It will be re-enabled later on-demand.
        registersPtr->TIER = 0;
        // Clear status bits.
        registersPtr->TIDR = IMX_TMU_TIDR_ATCTE_MASK | IMX_TMU_TIDR_ATTE_MASK | IMX_TMU_TIDR_ITTE_MASK;
        // Continue in DPC...
        WdfInterruptQueueDpcForIsr(WdfInterrupt);
        return TRUE;
    }

    return FALSE;
}

/*++
Routine Description:
    Driver DPC
Parameters Description:
    WdfInterrupt - Driver interrupt handle
    AssociatedWdfObject - Unused parameter
--*/
_Use_decl_annotations_
VOID
SensorTemperatureDpc (
    WDFINTERRUPT WdfInterrupt,
    WDFOBJECT AssociatedWdfObject
    )
{
    PFDO_DATA devExt = GetDeviceExtension(WdfInterruptGetDevice(WdfInterrupt));

    UNREFERENCED_PARAMETER(AssociatedWdfObject);

    WdfSpinLockAcquire(devExt->QueueLock);
    SensorScanPendingQueue(devExt->WdfDevice);
    WdfSpinLockRelease(devExt->QueueLock);
}

IMX_TMU_INIT_SEGMENT_BEGIN;
/*++
Routine Description:
    DriverEntry initializes the driver and is the first routine called by the
    system after the driver is loaded. DriverEntry configures and creates a WDF
    driver object.
Parameters Description:
    DriverObject - Supplies a pointer to the driver object.
    RegistryPath - Supplies a pointer to a unicode string representing the path
        to the driver-specific key in the registry.
Return Value:
    NTSTATUS.
--*/
NTSTATUS
DriverEntry (
    PDRIVER_OBJECT DriverObject,
    PUNICODE_STRING RegistryPath
    )
{
    WDF_OBJECT_ATTRIBUTES driverAttributes;
    WDF_DRIVER_CONFIG driverConfig;
    NTSTATUS status;

    UNREFERENCED_PARAMETER(RegistryPath);

    // Initialize logging
    WPP_INIT_TRACING(DriverObject, RegistryPath);
    RECORDER_CONFIGURE_PARAMS recorderConfigureParams;
    RECORDER_CONFIGURE_PARAMS_INIT(&recorderConfigureParams);
    WppRecorderConfigure(&recorderConfigureParams);
#if DBG
        WPP_RECORDER_LEVEL_FILTER(IMXTMU_TRACING_DEFAULT) = TRUE;
#endif // SENSOR_DBG

    IMXTMU_LOG_TRACE("Enter");

    WDF_DRIVER_CONFIG_INIT(&driverConfig, SensorDriverDeviceAdd);
    // Initialize attributes and a context area for the driver object.
    WDF_OBJECT_ATTRIBUTES_INIT(&driverAttributes);
    driverAttributes.SynchronizationScope = WdfSynchronizationScopeNone;
    driverAttributes.EvtCleanupCallback = EvtDriverContextCleanup;
    // Create the driver object
    status = WdfDriverCreate(DriverObject, RegistryPath, &driverAttributes, &driverConfig, WDF_NO_HANDLE);

    if (!NT_SUCCESS(status)) {
        IMXTMU_LOG_ERROR("WdfDriverCreate() Failed. Status 0x%x\n", status);
        WPP_CLEANUP(WdfDriverWdmGetDriverObject((WDFDRIVER)DriverObject));
        goto DriverEntryEnd;
    }

DriverEntryEnd:
    IMXTMU_LOG_TRACE("Exit 0x%x", status);
    return status;
}
IMX_TMU_INIT_SEGMENT_END;

/*++
Routine Description:
    Free all the resources allocated in DriverEntry.
Arguments:
    DriverObject - handle to a WDF Driver object.
--*/
VOID EvtDriverContextCleanup(_In_ WDFOBJECT DriverObject) {
    UNREFERENCED_PARAMETER(DriverObject);
    /* Stop WPP Tracing */
    WPP_CLEANUP(WdfDriverWdmGetDriverObject((WDFDRIVER)DriverObject));
}

IMX_TMU_PAGED_SEGMENT_BEGIN;
/*++
Routine Description:
    EvtDriverDeviceAdd is called by the framework in response to AddDevice call
    from the PnP manager.
Arguments:
    Driver - Supplies a handle to the WDF Driver object.
    DeviceInit - Supplies a pointer to a framework-allocated WDFDEVICE_INIT
        structure.
Return Value:
    NTSTATUS
--*/
NTSTATUS
SensorDriverDeviceAdd (
    WDFDRIVER Driver,
    PWDFDEVICE_INIT DeviceInit
    )
{
    WDF_OBJECT_ATTRIBUTES deviceAttributes;
    WDFDEVICE deviceHandle;
    PFDO_DATA devExt;
    WDF_IO_QUEUE_CONFIG pendingRequestQueueConfig;
    WDF_PNPPOWER_EVENT_CALLBACKS pnpPowerCallbacks;
    WDFQUEUE queue;
    WDF_IO_QUEUE_CONFIG queueConfig;
    NTSTATUS status;

    UNREFERENCED_PARAMETER(Driver);
    IMXTMU_LOG_TRACE("Enter");
    PAGED_CODE();

    // Initialize attributes and a context area for the device object.
    WDF_OBJECT_ATTRIBUTES_INIT(&deviceAttributes);
    WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE(&deviceAttributes, FDO_DATA);

    // Initailize power callbacks
    WDF_PNPPOWER_EVENT_CALLBACKS_INIT(&pnpPowerCallbacks);
    pnpPowerCallbacks.EvtDevicePrepareHardware = SensorPrepareHardware;
    pnpPowerCallbacks.EvtDeviceReleaseHardware = SensorReleaseHardware;
    WdfDeviceInitSetPnpPowerEventCallbacks(DeviceInit, &pnpPowerCallbacks);

    // Create a framework device object.  This call will in turn create
    // a WDM device object, attach to the lower stack, and set the
    // appropriate flags and attributes.
    status = WdfDeviceCreate(&DeviceInit, &deviceAttributes, &deviceHandle);
    if (!NT_SUCCESS(status)) {
        IMXTMU_LOG_ERROR("WdfDeviceCreate() Failed. 0x%x\n", status);
        goto DriverDeviceAddEnd;
    }
    devExt = GetDeviceExtension(deviceHandle);
    devExt->WdfDevice = deviceHandle;

    // Create an interrupt object with an associated context.
    WDF_INTERRUPT_CONFIG interruptConfig;
    WDF_INTERRUPT_CONFIG_INIT(&interruptConfig, SensorTemperatureIsr, SensorTemperatureDpc);
    WDFINTERRUPT wdfInterrupt;
    status = WdfInterruptCreate(deviceHandle, &interruptConfig, &deviceAttributes, &wdfInterrupt);
    if (!NT_SUCCESS(status)) {
        IMXTMU_LOG_ERROR("WdfInterruptCreate() Failed. 0x%x\n", status);
        goto DriverDeviceAddEnd;
    }
    devExt->WdfInterrupt = wdfInterrupt;

    // Configure a default queue for IO requests. This queue processes requests
    // to read the sensor state.
    WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(&queueConfig, WdfIoQueueDispatchParallel);
    queueConfig.EvtIoDeviceControl = SensorIoDeviceControl;
    // The system uses IoInternalDeviceControl requests to communicate with the
    // ACPI driver on the device stack. For proper operation of thermal zones,
    // these requests must be forwarded unless the driver knows how to handle
    // them.
    queueConfig.EvtIoInternalDeviceControl = SensorIoInternalDeviceControl;
    status = WdfIoQueueCreate(deviceHandle, &queueConfig, WDF_NO_OBJECT_ATTRIBUTES, &queue);
    if (!NT_SUCCESS(status)) {
        IMXTMU_LOG_ERROR("WdfIoQueueCreate() (Default) Failed.  0x%x\n", status);

        goto DriverDeviceAddEnd;
    }
    // Configure a manual dispatch queue for pending requests. This queue
    // stores requests to read the sensor state which can't be retired
    // immediately.
    WDF_IO_QUEUE_CONFIG_INIT(&pendingRequestQueueConfig, WdfIoQueueDispatchManual);
    status = WdfIoQueueCreate(deviceHandle, &pendingRequestQueueConfig, WDF_NO_OBJECT_ATTRIBUTES, &devExt->PendingRequestQueue);
    pendingRequestQueueConfig.EvtIoStop = SensorQueueIoStop;
    if (!NT_SUCCESS(status)) {
        IMXTMU_LOG_ERROR("WdfIoQueueCreate() (Pending) Failed. 0x%x\n", status);
        goto DriverDeviceAddEnd;
    }

    // Create the request queue lock.
    status = WdfSpinLockCreate(NULL, &devExt->QueueLock);
    if (!NT_SUCCESS(status)) {
        IMXTMU_LOG_ERROR("WdfWaitLockCreate() Failed. Status 0x%x\n", status);
        goto DriverDeviceAddEnd;
    }

DriverDeviceAddEnd:
    IMXTMU_LOG_TRACE("Exit 0x%x", status);
    return status;
}
IMX_TMU_PAGED_SEGMENT_END;

/*++
Routine Description:
    This routine is called when the framework is stopping the request's I/O queue.
Arguments:
    Queue - Supplies handle to the framework queue object that is associated
            with the I/O request.
    Request - Supplies handle to a framework request object.
    ActionFlags - Supplies the reason that the callback is being called.
Return Value:
    None.
--*/
VOID
SensorQueueIoStop (
    WDFQUEUE Queue,
    WDFREQUEST Request,
    ULONG ActionFlags
    )
{
    NTSTATUS status;

    UNREFERENCED_PARAMETER(Queue);

    IMXTMU_LOG_INFORMATION("SensorQueueIoStop: 0x%p\n", WdfIoQueueGetDevice(Queue));

    if (ActionFlags & WdfRequestStopRequestCancelable) {
        status = WdfRequestUnmarkCancelable(Request);
        if (status == STATUS_CANCELLED) {
            goto SensorQueueIoStopEnd;
        }
        NT_ASSERT(NT_SUCCESS(status));
    }
    WdfRequestStopAcknowledge(Request, FALSE);

SensorQueueIoStopEnd:
    return;
}

IMX_TMU_NONPAGED_SEGMENT_BEGIN;
/*++
Routine Description:
    Handles requests to read or write the simulated device state.
Arguments:
    Queue - Supplies a handle to the framework queue object that is associated
        with the I/O request.
    Request - Supplies a handle to a framework request object. This one
        represents the IRP_MJ_DEVICE_CONTROL IRP received by the framework.
    OutputBufferLength - Supplies the length, in bytes, of the request's output
        buffer, if an output buffer is available.
    InputBufferLength - Supplies the length, in bytes, of the request's input
        buffer, if an input buffer is available.
    IoControlCode - Supplies the Driver-defined or system-defined I/O control
        code (IOCtl) that is associated with the request.
Return Value:
   VOID
--*/
VOID
SensorIoDeviceControl (
    WDFQUEUE Queue,
    WDFREQUEST Request,
    size_t OutputBufferLength,
    size_t InputBufferLength,
    ULONG IoControlCode
    )
{
    ULONG bytesReturned;
    WDFDEVICE device;
    BOOLEAN result;
    WDF_REQUEST_SEND_OPTIONS requestSendOptions;
    NTSTATUS status;

    UNREFERENCED_PARAMETER(InputBufferLength);
    UNREFERENCED_PARAMETER(OutputBufferLength);

    device = WdfIoQueueGetDevice(Queue);

    bytesReturned = 0;
    switch (IoControlCode) {
    case IOCTL_THERMAL_READ_TEMPERATURE:
        // This call will either complete the request or put it in the pending queue.
        IMXTMU_LOG_INFORMATION("SensorIoDeviceControl IOCTL_THERMAL_READ_TEMPERATURE: 0x%p", device);
        SensorAddReadRequest(device, Request);
        break;
    default:
        // Unrecognized IOCtls must be forwarded down the stack.
        WDF_REQUEST_SEND_OPTIONS_INIT(&requestSendOptions, WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET);
        WdfRequestFormatRequestUsingCurrentType(Request);
        result = WdfRequestSend(Request, WdfDeviceGetIoTarget(device), &requestSendOptions);
        if (result == FALSE) {
            status = WdfRequestGetStatus(Request);
            IMXTMU_LOG_WARNING("WdfRequestSend() Failed. Request Status = 0x%x\n", status);
            WdfRequestComplete(Request, status);
        }
        break;
    }
}
IMX_TMU_NONPAGED_SEGMENT_END;

/*++
Description:
    The system uses IoInternalDeviceControl requests to communicate with the
    ACPI driver on the device stack. For proper operation of thermal zones,
    these requests must be forwarded unless the driver knows how to handle
    them.
--*/
VOID
SensorIoInternalDeviceControl (
    WDFQUEUE Queue,
    WDFREQUEST Request,
    size_t OutputBufferLength,
    size_t InputBufferLength,
    ULONG IoControlCode
    )
{
    WDF_REQUEST_SEND_OPTIONS requestSendOptions;
    BOOLEAN retVal;
    NTSTATUS status;

    UNREFERENCED_PARAMETER(OutputBufferLength);
    UNREFERENCED_PARAMETER(InputBufferLength);
    UNREFERENCED_PARAMETER(IoControlCode);

    IMXTMU_LOG_TRACE("Enter");

    WdfRequestFormatRequestUsingCurrentType(Request);
    WDF_REQUEST_SEND_OPTIONS_INIT(&requestSendOptions, WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET);
    retVal = WdfRequestSend(Request, WdfDeviceGetIoTarget(WdfIoQueueGetDevice(Queue)), &requestSendOptions);
    if (retVal == FALSE) {
        status = WdfRequestGetStatus(Request);
        IMXTMU_LOG_WARNING("WdfRequestSend() Failed. Request Status=0x%x", status);
        WdfRequestComplete(Request, status);
    }

    IMXTMU_LOG_TRACE("Exit");
}

/*++
Routine Description:
    Checks whether a request can be retired.
Arguments:
    Temperature - Supplies the device's current temperature.
    LowerBound - Supplies the request's lower temperature bound.
    UpperBound - Supplies the request's upper temperature bound.
    DueTime - Supplies when the request expires.
Return Value:
    TRUE - The request is retireable.
    FALSE - The request is not retireable.
--*/
_IRQL_requires_(DISPATCH_LEVEL)
BOOLEAN
SensorAreConstraintsSatisfied (
    ULONG Temperature,
    ULONG LowerBound,
    ULONG UpperBound,
    LARGE_INTEGER DueTime
    )
{
    LARGE_INTEGER currentTime;

    if ((Temperature <= LowerBound) || (Temperature >= UpperBound)) {
        return TRUE;
    }
    // Negative due times are meaningless, except for the special value -1,
    // which represents no timeout.
    if (DueTime.QuadPart < 0) {
        return FALSE;
    }
    KeQuerySystemTime(&currentTime);
    if ((currentTime.QuadPart - DueTime.QuadPart) >= 0) {
        // This request expired in the past.
        return TRUE;
    }

    return FALSE;
}
IMX_TMU_NONPAGED_SEGMENT_BEGIN;
/*++
Routine Description:
    Handles IOCTL_THERMAL_READ_TEMPERATURE. If the request can be satisfied,
    it is completed immediately. Else, adds request to pending request queue.
Arguments:
    Device - Supplies a handle to the device that received the request.
    ReadRequest - Supplies a handle to the request.
--*/
_IRQL_requires_(PASSIVE_LEVEL)
VOID
SensorAddReadRequest (
    WDFDEVICE Device,
    WDFREQUEST ReadRequest
    )
{
    ULONG bytesReturned;
    PREAD_REQUEST_CONTEXT context;
    WDF_OBJECT_ATTRIBUTES contextAttributes;
    PFDO_DATA devExt;
    LARGE_INTEGER expirationTime;
    size_t length;
    BOOLEAN lockHeld;
    PULONG requestTemperature;
    NTSTATUS status;
    LONG temperature;
    WDFTIMER timer;
    WDF_OBJECT_ATTRIBUTES timerAttributes;
    WDF_TIMER_CONFIG timerConfig;
    PTHERMAL_WAIT_READ thermalWaitRead;
    volatile IMXTMU_REGISTERS *registersPtr;

    IMXTMU_LOG_TRACE("Enter");

    devExt = GetDeviceExtension(Device);
    registersPtr = devExt->RegistersPtr;
    bytesReturned = 0;
    lockHeld = FALSE;

    // Disable interrupts
    registersPtr->TIER = 0;

    status = WdfRequestRetrieveInputBuffer(ReadRequest, sizeof(THERMAL_WAIT_READ), (PVOID*)&thermalWaitRead, &length);

    if (!NT_SUCCESS(status) || length != sizeof(THERMAL_WAIT_READ)) {
        // This request is malformed, bail.
        WdfRequestCompleteWithInformation(ReadRequest, status, bytesReturned);
        goto AddReadRequestEnd;
    }


    TIME_FIELDS timeFields;
    LARGE_INTEGER printTime;
    KeQuerySystemTime(&printTime);
    RtlTimeToTimeFields(&printTime, &timeFields);

    IMXTMU_LOG_INFORMATION("###Time. %d:%d:%d:%d", timeFields.Hour, timeFields.Minute, timeFields.Second, timeFields.Milliseconds);
    IMXTMU_LOG_INFORMATION("###ThermalWaitRead->Timeout 0x%x", thermalWaitRead->Timeout);
    IMXTMU_LOG_INFORMATION("###ThermalWaitRead->LowTemperature %d", thermalWaitRead->LowTemperature);
    IMXTMU_LOG_INFORMATION("###ThermalWaitRead->HighTemperature %d", thermalWaitRead->HighTemperature);

    if (thermalWaitRead->Timeout != -1 /* INFINITE */) {
        // Estimate the system time this request will expire at.
        KeQuerySystemTime(&expirationTime);
        expirationTime.QuadPart += thermalWaitRead->Timeout * 10000;
    } else {
        // Value which indicates the request never expires.
        expirationTime.QuadPart = -1LL /* INFINITE */;
    }
    // Handle the immediate timeout case in the fast path.
    temperature = SensorReadTemperature(Device);
    if (temperature == -1) {
        status = STATUS_UNEXPECTED_IO_ERROR;
        WdfRequestCompleteWithInformation(ReadRequest, status, bytesReturned);
        goto AddReadRequestEnd;
    }
    if (SensorAreConstraintsSatisfied(temperature, thermalWaitRead->LowTemperature, thermalWaitRead->HighTemperature, expirationTime)) {
        status = WdfRequestRetrieveOutputBuffer(ReadRequest, sizeof(ULONG), (PVOID*)&requestTemperature, &length);
        if (NT_SUCCESS(status) && length == sizeof(ULONG)) {
            *requestTemperature = temperature;
            bytesReturned = sizeof(ULONG);
        } else {
            status = STATUS_INVALID_PARAMETER;
            IMXTMU_LOG_ERROR("WdfRequestRetrieveOutputBuffer() Failed. 0x%x", status);
        }
        WdfRequestCompleteWithInformation(ReadRequest, status, bytesReturned);
    } else {
        WdfSpinLockAcquire(devExt->QueueLock);
        lockHeld = TRUE;
        // Create a context to store request-specific information.
        WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&contextAttributes, READ_REQUEST_CONTEXT);
        status = WdfObjectAllocateContext(ReadRequest, &contextAttributes, (PVOID*)&context);
        if (!NT_SUCCESS(status)) {
            IMXTMU_LOG_ERROR("WdfObjectAllocateContext() Failed. 0x%x", status);

            WdfRequestCompleteWithInformation(ReadRequest, status, bytesReturned);
            goto AddReadRequestEnd;
        }
        context->ExpirationTime.QuadPart = expirationTime.QuadPart;
        context->LowTemperature = thermalWaitRead->LowTemperature;
        context->HighTemperature = thermalWaitRead->HighTemperature;

        if (context->ExpirationTime.QuadPart != -1LL /* INFINITE */) {
            // This request eventually expires, create a timer to complete it.
            WDF_TIMER_CONFIG_INIT(&timerConfig, SensorExpiredRequestTimer);
            WDF_OBJECT_ATTRIBUTES_INIT(&timerAttributes);
            timerAttributes.ExecutionLevel = WdfExecutionLevelPassive;
            timerAttributes.SynchronizationScope = WdfSynchronizationScopeNone;
            timerAttributes.ParentObject = Device;
            status = WdfTimerCreate(&timerConfig, &timerAttributes, &timer);

            if (!NT_SUCCESS(status)) {
                IMXTMU_LOG_ERROR("WdfTimerCreate() Failed. 0x%x", status);
                WdfRequestCompleteWithInformation(ReadRequest, status, bytesReturned);
                goto AddReadRequestEnd;
            }
            WdfTimerStart(timer, WDF_REL_TIMEOUT_IN_MS(thermalWaitRead->Timeout));
        }

        status = WdfRequestForwardToIoQueue(ReadRequest, devExt->PendingRequestQueue);

        if (!NT_SUCCESS(status)) {
            IMXTMU_LOG_ERROR("WdfRequestForwardToIoQueue() Failed. 0x%x", status);
            WdfRequestCompleteWithInformation(ReadRequest, status, bytesReturned);
            goto AddReadRequestEnd;
        }
        // Force a rescan of the queue to update the interrupt thresholds.
        SensorScanPendingQueue(Device);
    }

AddReadRequestEnd:

    if (lockHeld == TRUE) {
        WdfSpinLockRelease(devExt->QueueLock);
    }

    IMXTMU_LOG_TRACE("Exit 0x%x", status);
}
IMX_TMU_NONPAGED_SEGMENT_END;

/*++
Routine Description:
    This routine scans the device's pending queue for retirable requests.
    N.B. This routine requires the Lock be held.
Arguments:
    Device - Supplies a handle to the device.
--*/
_IRQL_requires_(DISPATCH_LEVEL)
NTSTATUS
SensorScanPendingQueue (
    WDFDEVICE Device
    )
{
    WDFREQUEST currentRequest;
    PFDO_DATA devExt;
    WDFREQUEST lastRequest;
    ULONG lowerBound;
    ULONG upperBound;
    LONG temperature = 0;
    NTSTATUS status;

    IMXTMU_LOG_TRACE("Enter");

    devExt = GetDeviceExtension(Device);
    status = STATUS_SUCCESS;
    lastRequest = NULL;
    currentRequest = NULL;
    temperature = SensorReadTemperature(Device);

    if (temperature == -1) {
        return STATUS_UNEXPECTED_IO_ERROR;
    }
    // Prime the walk by finding the first request present. If there are no
    // requests, bail out immediately.
    lowerBound = 0;
    upperBound = (ULONG)-1;
    status = WdfIoQueueFindRequest(devExt->PendingRequestQueue, NULL, NULL, NULL, &currentRequest);
    IMXTMU_LOG_INFORMATION("WdfIoQueueFindRequest status: 0x%x \n", status);
    // Due to a technical limitation in SDV analysis engine, the following
    // analysis assume has to be inserted to supress a false defect for
    // the wdfioqueueretrievefoundrequest rule.
    _Analysis_assume_(status == STATUS_NOT_FOUND);
    while (NT_SUCCESS(status)) {
        // Walk past the current request. By walking past the current request
        // before checking it, the walk doesn't have to restart every time a
        // request is satisfied and removed form the queue.
        lastRequest = currentRequest;
        status = WdfIoQueueFindRequest(devExt->PendingRequestQueue, lastRequest, NULL, NULL, &currentRequest);
        // Process the last request.
        SensorCheckQueuedRequest(Device, temperature, &lowerBound, &upperBound, lastRequest);
        WdfObjectDereference(lastRequest);
        if (status == STATUS_NOT_FOUND) {
            // LastRequest unexpectedly disappeared from the queue. Start over.
            lowerBound = 0;
            upperBound = (ULONG)-1;
            status = WdfIoQueueFindRequest(devExt->PendingRequestQueue, NULL, NULL, NULL, &currentRequest);
        }
    }

    IMXTMU_LOG_TRACE("Exit 0x%x", status);

    return status;
}

/*++
Routine Description:
    Examines a request and performs one of the following actions:
      Retires the request if it is satisfied (the sensor temperature has
      exceeded the bounds specified in the request)
      Retires the request if it is expired (the timer due time is in the past)
      Tightens the upper and lower bounds if the request remains in the queue.
Arguments:
    Device - Supplies a handle to the device which owns this request.
    Temperature - Supplies the current thermal zone temperature.
    LowerBound - Supplies the lower bound threshold to adjust.
    UpperBound - Supplies the upper bound threshold to adjust.
    Request - Supplies a handle to the request.
--*/
_IRQL_requires_(DISPATCH_LEVEL)
VOID
SensorCheckQueuedRequest (
    WDFDEVICE Device,
    ULONG Temperature,
    PULONG LowerBound,
    PULONG UpperBound,
    WDFREQUEST Request
    )
{
    ULONG bytesReturned;
    LARGE_INTEGER currentTime;
    PFDO_DATA devExt;
    size_t length;
    PREAD_REQUEST_CONTEXT context;
    WDFREQUEST retrievedRequest;
    PULONG requestTemperature;
    NTSTATUS status;

    IMXTMU_LOG_TRACE("Enter");

    KeQuerySystemTime(&currentTime);
    devExt = GetDeviceExtension(Device);
    context = WdfObjectGetTypedContext(Request, READ_REQUEST_CONTEXT);
    retrievedRequest = NULL;

    // Complete the request if:
    // 1. The temperature has exceeded one of the request thresholds.
    // 2. The request timeout is in the past (but not negative).
    if (SensorAreConstraintsSatisfied(Temperature, context->LowTemperature, context->HighTemperature, context->ExpirationTime)) {
        status = WdfIoQueueRetrieveFoundRequest(devExt->PendingRequestQueue, Request, &retrievedRequest);
        if (!NT_SUCCESS(status)) {
            IMXTMU_LOG_ERROR("WdfIoQueueRetrieveFoundRequest() Failed. 0x%x \n", status);
            // Bail, likely because the request disappeared from the queue.
            goto CheckQueuedRequestEnd;
        }
        status = WdfRequestRetrieveOutputBuffer(retrievedRequest, sizeof(ULONG), (PVOID*)&requestTemperature, &length);
        if (NT_SUCCESS(status) && (length == sizeof(ULONG))) {
            *requestTemperature = Temperature;
            bytesReturned = sizeof(ULONG);
        }
        else {
            // The request's return buffer is malformed.
            bytesReturned = 0;
            status = STATUS_INVALID_PARAMETER;
            IMXTMU_LOG_ERROR("WdfRequestRetrieveOutputBuffer() Failed. 0x%x \n", status);
        }
        WdfRequestCompleteWithInformation(retrievedRequest, status, bytesReturned);
    }
    else {
        // The request will remain in the queue. Update the bounds accordingly.
        if (*LowerBound < context->LowTemperature) {
            *LowerBound = context->LowTemperature;
        }
        if (*UpperBound > context->HighTemperature) {
            *UpperBound = context->HighTemperature;
        }
        SensorSetInterruptThresholds(Device, *LowerBound, *UpperBound);
    }

CheckQueuedRequestEnd:
    IMXTMU_LOG_TRACE("Exit");
    return;
}

/*++
Routine Description:
    This routine is invoked when a request timer expires. A scan of the pending
    queue to complete expired and satisfied requests is initiated.
Arguments:
    Timer - Supplies a handle to the timer which expired.
--*/
_Use_decl_annotations_
VOID
SensorExpiredRequestTimer (
    WDFTIMER Timer
    )
{
    PFDO_DATA devExt;
    WDFDEVICE device;

    IMXTMU_LOG_TRACE("Enter");

    device = (WDFDEVICE)WdfTimerGetParentObject(Timer);
    devExt = GetDeviceExtension(device);
    WdfSpinLockAcquire(devExt->QueueLock);
    SensorScanPendingQueue(device);
    WdfSpinLockRelease(devExt->QueueLock);

    IMXTMU_LOG_TRACE("Exit");
}

/*++
  Routine Description:
    This routine maps the hardware resources to the
    controller register structure.
  Arguments:
    WdfDevice - a handle to the framework device object
    FxResourcesRaw - list of translated hardware resources that
        the PnP manager has assigned to the device
    FxResourcesTranslated - list of raw hardware resources that
        the PnP manager has assigned to the device
  Return Value:
    Status
--*/
_Use_decl_annotations_
NTSTATUS
SensorPrepareHardware (
    WDFDEVICE WdfDevice,
    WDFCMRESLIST FxResourcesRaw,
    WDFCMRESLIST FxResourcesTranslated
    )
{
    ULONG resourceCount = 0;
    PCM_PARTIAL_RESOURCE_DESCRIPTOR res;
    NTSTATUS status = STATUS_SUCCESS;
    NTSTATUS calStatus = STATUS_SUCCESS;
    PFDO_DATA devExt = NULL;
    ULONG numIntResourcesFound = 0;
    ULONG numMemResourcesFound = 0;
    volatile IMXTMU_REGISTERS *registersPtr;

    UNREFERENCED_PARAMETER(FxResourcesRaw);
    IMXTMU_LOG_TRACE("Enter");

    devExt = GetDeviceExtension(WdfDevice);
    NT_ASSERT(devExt != NULL);

    resourceCount = WdfCmResourceListGetCount(FxResourcesTranslated);

    for (ULONG i = 0; i < resourceCount; i++) {
        res = WdfCmResourceListGetDescriptor(FxResourcesTranslated, i);
        switch (res->Type) {
        case CmResourceTypeMemory:
            ++numMemResourcesFound;
            if (numMemResourcesFound > 1) {
                IMXTMU_LOG_ERROR("Unexpected additional memory resource!");
                return STATUS_DEVICE_CONFIGURATION_ERROR;
            }
            // Save the physical address
            devExt->RegistersPhysicalAddress = res->u.Memory.Start;
            devExt->RegistersIoSize = res->u.Memory.Length;
            // Get IO space mapping
            devExt->RegistersPtr = (IMXTMU_REGISTERS*)MmMapIoSpaceEx(devExt->RegistersPhysicalAddress,
                                                                     devExt->RegistersIoSize,
                                                                     PAGE_NOCACHE | PAGE_READWRITE);
            break;
        case CmResourceTypeInterrupt:
            ++numIntResourcesFound;
            if (numIntResourcesFound > 1) {
                IMXTMU_LOG_ERROR("Unexpected additional interrupt resource %lu, expected 1!", numIntResourcesFound);
                return STATUS_DEVICE_CONFIGURATION_ERROR;
            }
            break;

        default:
            // unknown resource will result in an error condition.
            break;
        }
    } // end FOR loop for resources

    // Make sure we got everything we need...
    if (numMemResourcesFound != 1) {
        IMXTMU_LOG_ERROR("Invalid or no memory resource!");
        return STATUS_DEVICE_CONFIGURATION_ERROR;
    }
    if (numIntResourcesFound != 1) {
        IMXTMU_LOG_ERROR("Invalid or not interrupt resource!");
        return STATUS_DEVICE_CONFIGURATION_ERROR;
    }

    ACPI_EVAL_OUTPUT_BUFFER UNALIGNED* dsdBufferPtr = nullptr;
    status = AcpiQueryDsd(WdfDeviceWdmGetPhysicalDevice(WdfDevice), &dsdBufferPtr);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    const ACPI_METHOD_ARGUMENT UNALIGNED* devicePropertiesPkgPtr;
    status = AcpiParseDsdAsDeviceProperties(dsdBufferPtr, &devicePropertiesPkgPtr);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    const ACPI_METHOD_ARGUMENT UNALIGNED* currentPairEntryPtr = nullptr;
    const ACPI_METHOD_ARGUMENT UNALIGNED* currentArgumentPtr = nullptr;

    status = AcpiDevicePropertiesQueryValue(devicePropertiesPkgPtr, "calibration", &currentPairEntryPtr);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    UINT32 range[4] = {0};
    AcpiDevicePropertiesQueryIntegerArrayValue(devicePropertiesPkgPtr, "range", &range[0], 4);

    registersPtr = devExt->RegistersPtr;

    // HW sensor initialization
    registersPtr->TMR = 0;
    // Disable interrupts
    registersPtr->TIER = 0;
    // Set default value for update interval
    registersPtr->TMTMIR = IMX_TMU_TMTMIR_TMI_VAL_DFLT;

    // Initialize temperature range registers
    registersPtr->TTR0CR = range[0];
    registersPtr->TTR1CR = range[1];
    registersPtr->TTR2CR = range[2];
    registersPtr->TTR3CR = range[3];

    while (calStatus == STATUS_SUCCESS) {
        UINT32 calibration[2] = {0};
        calStatus = AcpiDevicePropertiesQueryIntegerValueArray(currentPairEntryPtr, &calibration[0], 2, &currentArgumentPtr);
        if (calStatus == STATUS_SUCCESS) {
            registersPtr->TTCFGR = calibration[0];
            registersPtr->TSCFGR = calibration[1];
        } else {
            break;
        }
    }

    // Clear flags
    registersPtr->TIDR = IMX_TMU_TIDR_ATCTE_MASK | IMX_TMU_TIDR_ATTE_MASK | IMX_TMU_TIDR_ITTE_MASK;
    // Enable TMU with measurement of the processor temperature
    registersPtr->TMR = IMX_TMU_TMR_ME_MASK | IMX_TMU_TMR_ALPF_MASK | IMX_TMU_TMR_MSITE_VAL_ARM;

    IMXTMU_LOG_TRACE("Exit 0x%x", status);

    return status;
}

/*++
  Routine Description:
    This routine unmaps the controller register structure.
  Arguments:
    WdfDevice - a handle to the framework device object
    FxResourcesRaw - list of translated hardware resources that
        the PnP manager has assigned to the device
    FxResourcesTranslated - list of raw hardware resources that
        the PnP manager has assigned to the device
  Return Value:
    Status
--*/
_Use_decl_annotations_
NTSTATUS
SensorReleaseHardware (
    WDFDEVICE WdfDevice,
    WDFCMRESLIST FxResourcesTranslated
)
{
    PFDO_DATA devExt = GetDeviceExtension(WdfDevice);
    NT_ASSERT(devExt != NULL);
    NTSTATUS status = STATUS_SUCCESS;

    UNREFERENCED_PARAMETER(FxResourcesTranslated);
    IMXTMU_LOG_TRACE("Enter");

    if (devExt->RegistersPtr != NULL) {
        MmUnmapIoSpace(devExt->RegistersPtr, devExt->RegistersIoSize);
        devExt->RegistersPtr = NULL;
    };

    IMXTMU_LOG_TRACE("Exit 0x%x", status);

    return status;
}

/*++
Routine Description:
    This routine is invoked to change the thresholds the virtual sensor driver
    uses to compare against for an interrupt to occur.
Arguments:
    Device - Supplies a handle to the device.
    LowerBound - Supplies the temperature below which the device should issue an interrupt.
    UpperBound - Supplies the temperature above which the device should issue an interrupt.
Return Value:
    NTSTATUS
--*/
VOID
SensorSetInterruptThresholds (
    WDFDEVICE Device,
    ULONG LowerBound,
    ULONG UpperBound
    )
{
    PFDO_DATA devExt;
    volatile IMXTMU_REGISTERS *registersPtr;

    UNREFERENCED_PARAMETER(LowerBound);

    devExt = GetDeviceExtension(Device);
    registersPtr = devExt->RegistersPtr;

    // Clear flags
    registersPtr->TIDR = IMX_TMU_TIDR_ATCTE_MASK | IMX_TMU_TIDR_ATTE_MASK | IMX_TMU_TIDR_ITTE_MASK;
    // Set Interrupt threshold to occur
    registersPtr->TMHTITR = (((UpperBound / 10) - KELVIN273) & IMX_TMU_TEMP_MASK) | IMX_TMU_TEMP_EN;
    IMXTMU_LOG_INFORMATION("TMHTITR 0x%x, TSR 0x%x", registersPtr->TMHTITR, registersPtr->TSR);
    // Enable interrupts
    registersPtr->TIER = (IMX_TMU_TIER_ITTEIE_MASK);

    return;
}

/*++
Routine Description:
    This routine is invoked to read the current temperature of the device.
Arguments:
    Device - Supplies a handle to the device.
Return Value:
    Temperature in tenths of degrees Kelvin or -1 if error.
--*/
_Use_decl_annotations_
LONG
SensorReadTemperature (
    WDFDEVICE Device
    )
{
    PFDO_DATA devExt;
    LONG tempInTenthsOfKelvin;
    UINT32 siteTemp;
    volatile IMXTMU_REGISTERS *registersPtr;

    devExt = GetDeviceExtension(Device);
    registersPtr = devExt->RegistersPtr;

    siteTemp = registersPtr->TRITSR0;
    if (siteTemp & IMX_TMU_TEMP_VALID) {
        tempInTenthsOfKelvin = ((siteTemp & IMX_TMU_TEMP_MASK) + KELVIN273) * 10;
        IMXTMU_LOG_TRACE("SensorReadTemperature in tenths of Kelvin %d", tempInTenthsOfKelvin);
    } else {
        tempInTenthsOfKelvin = -1;
        IMXTMU_LOG_ERROR("Error in temperature reading! (TSR value: 0x%x)", registersPtr->TSR);
    }
    return tempInTenthsOfKelvin;
}