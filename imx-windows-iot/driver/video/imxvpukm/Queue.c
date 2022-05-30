/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License.

Module Name:

    queue.c

Abstract:

    This file contains the queue entry points and callbacks.

Environment:

    Kernel-mode Driver Framework

--*/

#include "imxvpu_driver.h"
#include "Queue.tmh"

IMXVPU_PAGED_SEGMENT_BEGIN

// size of IMX8M VPU register blocks
static const int vpuDecSize[] = { MAX_REGS_G1, MAX_REGS_G2 };

NTSTATUS ClientTypeToCoreId(ULONG ClientType, ULONG * CoreId)
{
    NTSTATUS Status = STATUS_SUCCESS;

    switch (ClientType)
    {
    case DWL_CLIENT_TYPE_H264_DEC:
    case DWL_CLIENT_TYPE_VP8_DEC:
    case DWL_CLIENT_TYPE_MPEG2_DEC:
    case DWL_CLIENT_TYPE_MPEG4_DEC:
        *CoreId = 0;
        break;

    case DWL_CLIENT_TYPE_HEVC_DEC:
    case DWL_CLIENT_TYPE_VP9_DEC:
        *CoreId = 1;
        break;

    default:
        Status = STATUS_UNSUCCESSFUL;  //unknown client type
        break;
    }

    return Status;
}


NTSTATUS AllocEntry(VpuAlloc **alloc) {
    NTSTATUS Status = STATUS_SUCCESS;

    /* Allocate internal memory for mem     * This is used only localy in km driver to keep info about granted memory.
     * VpuAlloc is an elist.alloc entry!
ntry in memList.
     */
    (*alloc) = (VpuAlloc *)ExAllocatePoolWithTag(NonPagedPoolNx, sizeof(VpuAlloc), VPU_KM_ALLOC_TAG_WDF);
    if ((*alloc) == NULL) // check alloc status
    {
        TraceEvents(TRACE_LEVEL_ERROR, IMXVPU_DRIVER_TRACE, "Out of memory");
        Status = STATUS_INSUFFICIENT_RESOURCES;
        return Status;
    }

    memset(*alloc, 0, sizeof(VpuAlloc));

    return Status;
}

NTSTATUS AllocMDL(VpuAlloc **alloc, ULONG size, ULONG cacheType) {

    NTSTATUS Status = STATUS_SUCCESS;
    static const PHYSICAL_ADDRESS zero = { 0,0 };           // this is required by MmAllocatePagesForMdlEx
    static const PHYSICAL_ADDRESS high = { 0xffffffff, 0 }; // this is required by MmAllocatePagesForMdlEx

    // Allocate
    // Memory Description List
    (*alloc)->mdl = MmAllocatePagesForMdlEx(zero, high, zero, size, cacheType, MM_ALLOCATE_FULLY_REQUIRED | MM_ALLOCATE_REQUIRE_CONTIGUOUS_CHUNKS);
    if ((*alloc)->mdl == NULL) {
        TraceEvents(TRACE_LEVEL_ERROR, IMXVPU_DRIVER_TRACE, "Out of memory");
        Status = STATUS_INSUFFICIENT_RESOURCES;
    }
    return Status;
}

NTSTATUS MapMDL(VpuAlloc **alloc, ULONG cacheType) {
    NTSTATUS Status = STATUS_SUCCESS;

    try {
        (*alloc)->virtAddr = MmMapLockedPagesSpecifyCache((*alloc)->mdl, UserMode, cacheType, NULL, FALSE, NormalPagePriority | MdlMappingNoExecute);
    } except(EXCEPTION_EXECUTE_HANDLER) {
        IMXVPU_LOG_LOW_MEMORY("MmMapLockedPagesSpecifyCache(...) failed. (vpuRam = 0x%p)", (*alloc)->virtAddr);
        Status = STATUS_INSUFFICIENT_RESOURCES;
        return Status;
    }
    return Status;
}


NTSTATUS PrepareVpuBuffer(VpuAlloc **alloc, ULONG size, ULONG cacheType)
{
    NTSTATUS Status = STATUS_SUCCESS;

    Status = AllocEntry(alloc);
    if (!NT_SUCCESS(Status)) {
        return Status;
    }

    Status = AllocMDL(alloc, size, cacheType);
    if (!NT_SUCCESS(Status)) {
        ExFreePoolWithTag(*alloc, VPU_KM_ALLOC_TAG_WDF); //Free entry
        *alloc = NULL;
        return Status;
    }
    return Status;
}

NTSTATUS AllocVpuBuffer(VpuAlloc **alloc, ULONG size, ULONG cacheType, WDFFILEOBJECT file)
{
    NTSTATUS Status = STATUS_SUCCESS;
     Status = MapMDL(alloc, cacheType);
    if (!NT_SUCCESS(Status)) {
        return Status;
    }

    // TODO; perhaps reuse devContextPtr->memList head to hold vpu information.
    PHYSICAL_ADDRESS physAddr = MmGetPhysicalAddress((*alloc)->virtAddr); // get PHY memory
    (*alloc)->physAddr = physAddr.QuadPart;

    (*alloc)->file = file;
    (void)size;
    (*alloc)->occupied = ONE_TIME_MEM;

    return Status;
}

void FreeVpuBuffer(VpuAlloc *buffer)
{
    if (buffer == NULL) {
        return;
    }
    // free allocated resources
    if (buffer->mdl != NULL) {
        if (buffer->virtAddr != NULL) {
            MmUnmapLockedPages(buffer->virtAddr, buffer->mdl);
        }
    }

    if (buffer->physAddr != 0) {
        MmFreePagesFromMdl(buffer->mdl);
        ExFreePool(buffer->mdl);
    }
    buffer->mdl = NULL;
    buffer->next = NULL;
    buffer->physAddr = 0;
    buffer->virtAddr = NULL;
    buffer->file = NULL;
    ExFreePoolWithTag(buffer, VPU_KM_ALLOC_TAG_WDF);
}

void * MapUserModeAddressRegisters(WDFREQUEST Request)
{
    PMDL mdl;
    IMXVPU_DEVICE_CONTEXT *deviceContextPtr;
    WDFDEVICE device;
    VpuAlloc *alloc = NULL;
    VpuAlloc *ptr;
    WDFFILEOBJECT file;
    void *virtualAddress = NULL;

    file = WdfRequestGetFileObject(Request);
    device = WdfFileObjectGetDevice(file);
    deviceContextPtr = DeviceGetContext(device);

    NT_ASSERT(deviceContextPtr->MdlRegisters != NULL);
    mdl = deviceContextPtr->MdlRegisters;

    ExAcquireFastMutex(&deviceContextPtr->Mutex);
    ptr = deviceContextPtr->memList.next;
    while (ptr != NULL)
    {
        if ((ptr->physAddr == 0) &&
            (ptr->file == file))
        {
            break;
        }
        ptr = ptr->next;
    }
    ExReleaseFastMutex(&deviceContextPtr->Mutex);
    
    // TODO: need to handle if file handle is closed while another thread maps VPU registers?
    if (ptr != NULL)
    {
        virtualAddress = ptr->virtAddr;
        goto end;
    }

    alloc = (VpuAlloc *)ExAllocatePoolWithTag(NonPagedPoolNx, sizeof(VpuAlloc), VPU_KM_ALLOC_TAG_WDF);
    if (alloc == NULL)
    {
        TraceEvents(TRACE_LEVEL_ERROR, IMXVPU_DRIVER_TRACE, "Out of memory");
        goto end;
    }

    try {
        virtualAddress = MmMapLockedPagesSpecifyCache(mdl, UserMode, MmNonCached, NULL, FALSE, NormalPagePriority | MdlMappingNoExecute);
    } except(EXCEPTION_EXECUTE_HANDLER) {
        ULONG status = GetExceptionCode();
        TraceEvents(TRACE_LEVEL_ERROR,
            IMXVPU_QUEUE_TRACE,
            "%!FUNC! MmMapLockedPagesSpecifyCache threw an exception.  Request 0x%p status %!STATUS!",
            Request, status);
        goto end;
    }

    alloc->mdl = mdl;
    alloc->virtAddr = virtualAddress;
    alloc->physAddr = 0;
    alloc->file = file;

    ExAcquireFastMutex(&deviceContextPtr->Mutex);
    alloc->next = deviceContextPtr->memList.next;
    deviceContextPtr->memList.next = alloc;
    alloc = NULL;
    ExReleaseFastMutex(&deviceContextPtr->Mutex);

end:
    if (alloc != NULL)
    {
        ExFreePoolWithTag(alloc, VPU_KM_ALLOC_TAG_WDF);
        alloc = NULL;
    }

    return virtualAddress;
}

NTSTATUS
VpuCacheOperation(
    _In_ WDFREQUEST Request,
    _In_ IMXVPU_DEVICE_CONTEXT *deviceContextPtr,
    _In_ ULONG IoControlCode,
    _In_ size_t OutputBufferLength,
    _In_ size_t InputBufferLength)
{
    NTSTATUS Status;
    PVOID *ppInputMemory;
    size_t BufferSize;
    BOOLEAN ReadOperation;

    if (InputBufferLength != sizeof(PVOID) || OutputBufferLength != 0)
    {
        Status = STATUS_INVALID_PARAMETER;
        goto end;
    }

    switch (IoControlCode)
    {
    case IOCTL_VPU_CACHE_INVALIDATE:
        ReadOperation = TRUE;
        break;

    case IOCTL_VPU_CACHE_FLUSH:
        ReadOperation = FALSE;
        break;

    default:
        NT_ASSERT(FALSE);
        Status = STATUS_INVALID_PARAMETER;
        goto end;
    }

    Status = WdfRequestRetrieveInputBuffer(
        Request,
        sizeof(PVOID),
        (PVOID*)&ppInputMemory,
        &BufferSize);
    if (!NT_SUCCESS(Status)) {
        goto end;
    }
    if (BufferSize != sizeof(PVOID))
    {
        Status = STATUS_INVALID_PARAMETER;
        goto end;
    }

    if (ppInputMemory == NULL)
    {
        Status = STATUS_INVALID_ADDRESS;
        goto end;
    }

    // search for allocated memory block
    VpuAlloc *ptr;
    int found = FALSE;

    ExAcquireFastMutex(&deviceContextPtr->Mutex);

    // search in preallocated memory
    for (int i = 0; i < REUSABLE_MEM_BLOCKS_MAX; i++) {
        ptr = deviceContextPtr->preallocated_mem[i];
        if ((ptr->virtAddr == *ppInputMemory) && (ptr->mdl != NULL)) {
            // flush/invalidate data cache for entry (DMA = TRUE)
            KeFlushIoBuffers(ptr->mdl, ReadOperation, TRUE);
            found = TRUE;
            break;
        }
    }

    if (!found) {
        ptr = deviceContextPtr->memList.next;
        while (ptr != NULL) {
            if ((ptr->virtAddr == *ppInputMemory) && (ptr->mdl != NULL)) {
                // flush/invalidate data cache for entry (DMA = TRUE)
                KeFlushIoBuffers(ptr->mdl, ReadOperation, TRUE);
                break;
            }
            ptr = ptr->next;
        }
    }
    ExReleaseFastMutex(&deviceContextPtr->Mutex);

    if (ptr == NULL)
    {
        TraceEvents(TRACE_LEVEL_ERROR, IMXVPU_QUEUE_TRACE, "memory block %p not found in list", *ppInputMemory);
        Status = STATUS_INVALID_ADDRESS;
        goto end;
    }

    Status = STATUS_SUCCESS;

end:
    return Status;
}

NTSTATUS
VpuDecoderReserve(
    _In_ WDFREQUEST Request,
    _In_ IMXVPU_DEVICE_CONTEXT *deviceContextPtr,
    _In_ size_t OutputBufferLength,
    _In_ size_t InputBufferLength,
    _In_ ULONG *BytesWritten)
{
    NTSTATUS Status;
    ULONG *pInputMemory;
    ULONG *pOutputMemory;
    ULONG CoreId;
    size_t BufferSize;

    if (InputBufferLength != sizeof(ULONG) || OutputBufferLength != sizeof(ULONG))
    {
        Status = STATUS_INVALID_PARAMETER;
        goto end;
    }

    Status = WdfRequestRetrieveInputBuffer(
        Request,
        sizeof(ULONG),
        (PVOID*)&pInputMemory,
        &BufferSize);
    if (!NT_SUCCESS(Status)) {
        goto end;
    }
    if (BufferSize != sizeof(ULONG))
    {
        Status = STATUS_INVALID_PARAMETER;
        goto end;
    }

    Status = WdfRequestRetrieveOutputBuffer(Request,
        sizeof(ULONG),
        (PVOID*)&pOutputMemory,
        &BufferSize);
    if (!NT_SUCCESS(Status)) {
        goto end;
    }

    if (BufferSize != sizeof(ULONG))
    {
        Status = STATUS_INVALID_PARAMETER;
        goto end;
    }

    Status = ClientTypeToCoreId(*pInputMemory, &CoreId);
    if (!NT_SUCCESS(Status)) {
        goto end;
    }

    if (CoreId >= IMXVPU_CORE_COUNT)
    {
        Status = STATUS_INVALID_PARAMETER;
        goto end;
    }

    *pOutputMemory = CoreId;
    *BytesWritten = sizeof(ULONG);

    // See if queue has waiting entries and queue Request if already locked
    ExAcquireFastMutex(&deviceContextPtr->Mutex);

    if (deviceContextPtr->vpuOwner[CoreId] != NULL)
    {
        TraceEvents(TRACE_LEVEL_INFORMATION, IMXVPU_QUEUE_TRACE, "%!FUNC! CoreId %d is already locked by file 0x%p, queueing reservation request",
            CoreId, deviceContextPtr->vpuOwner[CoreId]);
        Status = WdfRequestForwardToIoQueue(Request, deviceContextPtr->waitQueue[CoreId]);
        if (!NT_SUCCESS(Status))
        {
            TraceEvents(TRACE_LEVEL_ERROR, IMXVPU_QUEUE_TRACE, "%!FUNC! WdfRequestForwardToIoQueue failed. CoreId %d Request 0x%p status %!STATUS!",
                CoreId, Request, Status);
        }
        else
        {
            Status = STATUS_WAIT_1;
        }
    }
    else
    {
        deviceContextPtr->vpuOwner[CoreId] = WdfRequestGetFileObject(Request);
        TraceEvents(TRACE_LEVEL_INFORMATION, IMXVPU_QUEUE_TRACE, "%!FUNC! Locking CoreId %d to file 0x%p",
            CoreId, deviceContextPtr->vpuOwner[CoreId]);

        Status = STATUS_SUCCESS;
    }
    ExReleaseFastMutex(&deviceContextPtr->Mutex);

end:
    return Status;
}

NTSTATUS UnlockVpu(
    _In_ IMXVPU_DEVICE_CONTEXT *deviceContextPtr,
    _In_ ULONG CoreId,
    _In_ WDFFILEOBJECT File
)
{
    NTSTATUS Status = STATUS_SUCCESS;

    if (deviceContextPtr->vpuOwner[CoreId] != File)
    {
        Status = STATUS_INVALID_LOCK_SEQUENCE;
    }
    else
    {
        WDFREQUEST waitingRequest = NULL;
        WDFFILEOBJECT waitingFile = NULL;
        ULONG hwStatus;

        hwStatus = READ_REGISTER_NOFENCE_ULONG(
                    (ULONG *)deviceContextPtr->RegistersPtr + ((0x10000 / sizeof(ULONG)) * CoreId) + HANTRODEC_IRQ_STAT_DEC_OFF);

        /* make sure HW is disabled */
        if (hwStatus & HANTRODEC_DEC_E) {
            TraceEvents(TRACE_LEVEL_INFORMATION, IMXVPU_QUEUE_TRACE, "%!FUNC! Decoder %d is still enabled on unlock",
                CoreId);

            // TODO: wait for HW to deassert enabled flag or timeout before disabling device
            WRITE_REGISTER_NOFENCE_ULONG(
                (ULONG *)deviceContextPtr->RegistersPtr + ((0x10000 / sizeof(ULONG)) * CoreId) + HANTRODEC_IRQ_STAT_DEC_OFF,
                0x00);
        }

        Status = WdfIoQueueRetrieveNextRequest(deviceContextPtr->waitQueue[CoreId], &waitingRequest);
        if (Status == STATUS_NO_MORE_ENTRIES)
        {
            NT_ASSERT(waitingRequest == NULL);
            TraceEvents(TRACE_LEVEL_INFORMATION, IMXVPU_QUEUE_TRACE, "%!FUNC! Core %d unlocked by file 0x%p.",
                CoreId, File);
            deviceContextPtr->vpuOwner[CoreId] = NULL;
            Status = STATUS_SUCCESS;
        }
        else if (waitingRequest != NULL)
        {
            waitingFile = WdfRequestGetFileObject(waitingRequest);
            NT_ASSERT(waitingFile != NULL);
            TraceEvents(TRACE_LEVEL_INFORMATION, IMXVPU_QUEUE_TRACE, "%!FUNC! Transfering ownership of Core %d to file 0x%p.",
                CoreId, waitingFile);
            deviceContextPtr->vpuOwner[CoreId] = waitingFile;

            // Finish waitingRequest
            WdfRequestCompleteWithInformation(waitingRequest, STATUS_SUCCESS, sizeof(ULONG));
            Status = STATUS_SUCCESS;
        }
    }

    return Status;
}

NTSTATUS
VpuDecoderRelease(
    _In_ WDFREQUEST Request,
    _In_ IMXVPU_DEVICE_CONTEXT *deviceContextPtr,
    _In_ size_t OutputBufferLength,
    _In_ size_t InputBufferLength)
{
    NTSTATUS Status;
    ULONG *pInputMemory;
    ULONG CoreId;
    size_t BufferSize;
    WDFFILEOBJECT File;

    if (InputBufferLength != sizeof(ULONG) || OutputBufferLength != 0)
    {
        Status = STATUS_INVALID_PARAMETER;
        goto end;
    }

    Status = WdfRequestRetrieveInputBuffer(
        Request,
        sizeof(ULONG),
        (PVOID*)&pInputMemory,
        &BufferSize);
    if (!NT_SUCCESS(Status)) {
        goto end;
    }
    if (BufferSize != sizeof(ULONG))
    {
        Status = STATUS_INVALID_PARAMETER;
        goto end;
    }

    CoreId = *pInputMemory;
    if (CoreId >= IMXVPU_CORE_COUNT)
    {
        Status = STATUS_INVALID_PARAMETER;
        goto end;
    }

    File = WdfRequestGetFileObject(Request);

    // Unlock queue if owned and release next wait request
    ExAcquireFastMutex(&deviceContextPtr->Mutex);
    if (deviceContextPtr->vpuOwner[CoreId] != File)
    {
        TraceEvents(TRACE_LEVEL_INFORMATION, IMXVPU_QUEUE_TRACE, "%!FUNC! Core %d is not locked by file 0x%p, failing request. Current owner 0x%p",
            CoreId, File, deviceContextPtr->vpuOwner[CoreId]);
        Status = STATUS_INVALID_LOCK_SEQUENCE;
    }
    else
    {
        Status = UnlockVpu(deviceContextPtr, CoreId, File);
    }
    ExReleaseFastMutex(&deviceContextPtr->Mutex);

end:
    return Status;
}

NTSTATUS
OnQueueInitialize(
    _In_ WDFDEVICE Device
    )
/*++

Routine Description:

     The I/O dispatch callbacks for the frameworks device object
     are configured in this function.

     A single default I/O Queue is configured for parallel request
     processing, and a driver context memory allocation is created
     to hold our structure QUEUE_CONTEXT.

Arguments:

    Device - Handle to a framework device object.

Return Value:

    VOID

--*/
{
    WDFQUEUE queue;
    NTSTATUS status;
    WDF_IO_QUEUE_CONFIG queueConfig;

    PAGED_CODE();

    //
    // Configure a default queue so that requests that are not
    // configure-fowarded using WdfDeviceConfigureRequestDispatching to goto
    // other queues get dispatched here.
    //
    WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(
         &queueConfig,
        WdfIoQueueDispatchParallel
        );

    queueConfig.EvtIoDeviceControl = OnIoDeviceControl;
    queueConfig.EvtIoStop = OnIoStop;

    status = WdfIoQueueCreate(
                 Device,
                 &queueConfig,
                 WDF_NO_OBJECT_ATTRIBUTES,
                 &queue
                 );

    if(!NT_SUCCESS(status)) {
        TraceEvents(TRACE_LEVEL_ERROR, IMXVPU_DRIVER_TRACE, "WdfIoQueueCreate failed %!STATUS!", status);
        return status;
    }

    return status;
}

VOID
OnIoStop(
    _In_ WDFQUEUE Queue,
    _In_ WDFREQUEST Request,
    _In_ ULONG ActionFlags
)
/*++

Routine Description:

    This event is invoked for a power-managed queue before the device leaves the working state (D0).

Arguments:

    Queue -  Handle to the framework queue object that is associated with the
             I/O request.

    Request - Handle to a framework request object.

    ActionFlags - A bitwise OR of one or more WDF_REQUEST_STOP_ACTION_FLAGS-typed flags
                  that identify the reason that the callback function is being called
                  and whether the request is cancelable.

Return Value:

    VOID

--*/
{
    TraceEvents(TRACE_LEVEL_INFORMATION,
        IMXVPU_QUEUE_TRACE,
        "%!FUNC! Queue 0x%p, Request 0x%p ActionFlags %d",
        Queue, Request, ActionFlags);

    //
    // In most cases, the EvtIoStop callback function completes, cancels, or postpones
    // further processing of the I/O request.
    //
    // Typically, the driver uses the following rules:
    //
    // - If the driver owns the I/O request, it calls WdfRequestUnmarkCancelable
    //   (if the request is cancelable) and either calls WdfRequestStopAcknowledge
    //   with a Requeue value of TRUE, or it calls WdfRequestComplete with a
    //   completion status value of STATUS_SUCCESS or STATUS_CANCELLED.
    //
    //   Before it can call these methods safely, the driver must make sure that
    //   its implementation of EvtIoStop has exclusive access to the request.
    //
    //   In order to do that, the driver must synchronize access to the request
    //   to prevent other threads from manipulating the request concurrently.
    //   The synchronization method you choose will depend on your driver's design.
    //
    //   For example, if the request is held in a shared context, the EvtIoStop callback
    //   might acquire an internal driver lock, take the request from the shared context,
    //   and then release the lock. At this point, the EvtIoStop callback owns the request
    //   and can safely complete or requeue the request.
    //
    // - If the driver has forwarded the I/O request to an I/O target, it either calls
    //   WdfRequestCancelSentRequest to attempt to cancel the request, or it postpones
    //   further processing of the request and calls WdfRequestStopAcknowledge with
    //   a Requeue value of FALSE.
    //
    // A driver might choose to take no action in EvtIoStop for requests that are
    // guaranteed to complete in a small amount of time.
    //
    // In this case, the framework waits until the specified request is complete
    // before moving the device (or system) to a lower power state or removing the device.
    // Potentially, this inaction can prevent a system from entering its hibernation state
    // or another low system power state. In extreme cases, it can cause the system
    // to crash with bugcheck code 9F.
    //

    (void)Queue;
    (void)Request;
    (void)ActionFlags;
    return;
}

VOID
OnIoDeviceControl(
    _In_ WDFQUEUE Queue,
    _In_ WDFREQUEST Request,
    _In_ size_t OutputBufferLength,
    _In_ size_t InputBufferLength,
    _In_ ULONG IoControlCode
    )
/*++

Routine Description:

    This event is invoked when the framework receives IRP_MJ_DEVICE_CONTROL request.

Arguments:

    Queue -  Handle to the framework queue object that is associated with the
             I/O request.

    Request - Handle to a framework request object.

    OutputBufferLength - Size of the output buffer in bytes

    InputBufferLength - Size of the input buffer in bytes

    IoControlCode - I/O control code.

Return Value:

    VOID

--*/
{
    TraceEvents(TRACE_LEVEL_INFORMATION, 
                IMXVPU_QUEUE_TRACE, 
                "%!FUNC! Queue 0x%p, Request 0x%p OutputBufferLength %d InputBufferLength %d IoControlCode %d", 
                Queue, Request, (int) OutputBufferLength, (int) InputBufferLength, IoControlCode);

    WDFDEVICE device;
    IMXVPU_DEVICE_CONTEXT *deviceContextPtr;

    PCHAR Buffer;
    size_t BufferSize;
    ULONG BytesWritten;
    NTSTATUS Status;
    ULONG CoreId;
    VpuAlloc *alloc = NULL;

    PAGED_CODE();

    BytesWritten = 0;

    device = WdfIoQueueGetDevice(Queue);
    deviceContextPtr = DeviceGetContext(device);

    switch (IoControlCode) {
    case IOCTL_VPU_MC_CORES:
        if (InputBufferLength != 0 || OutputBufferLength != sizeof(ULONG))
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        Status = WdfRequestRetrieveOutputBuffer(Request,
            sizeof(ULONG),
            (PVOID*)&Buffer,
            &BufferSize);
        if (!NT_SUCCESS(Status)) {
            goto end;
        }

        (*(ULONG *)Buffer) = IMXVPU_CORE_COUNT;    // two cores - G1, G2.
        BytesWritten = sizeof(ULONG);
        break;

    case IOCTL_VPU_CORE_ID:
        if (InputBufferLength != sizeof(ULONG) || OutputBufferLength != sizeof(ULONG))
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        Status = WdfRequestRetrieveInputBuffer(Request,
            0,
            (PVOID*)&Buffer,
            &BufferSize);
        if (!NT_SUCCESS(Status)) {
            goto end;
        }
        if (BufferSize != sizeof(ULONG))
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        ULONG ClientType = *(ULONG *)Buffer;

        Status = WdfRequestRetrieveOutputBuffer(Request,
            sizeof(ULONG),
            (PVOID*)&Buffer,
            &BufferSize);
        if (!NT_SUCCESS(Status)) {
            goto end;
        }

        Status = ClientTypeToCoreId(ClientType, (ULONG *)Buffer);
        if (NT_SUCCESS(Status)) {
            BytesWritten = sizeof(ULONG);
        }
        break;

    case IOCTL_VPU_ASIC_ID:
        if (InputBufferLength != sizeof(ULONG) || OutputBufferLength != sizeof(ULONG))
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        Status = WdfRequestRetrieveInputBuffer(Request,
            0,
            (PVOID*)&Buffer,
            &BufferSize);
        if (!NT_SUCCESS(Status)) {
            goto end;
        }
        if (BufferSize != sizeof(ULONG))
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        // only support G1 and G2 cores currently
        CoreId = *(ULONG *)Buffer;
        if (CoreId >= IMXVPU_CORE_COUNT) {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        Status = WdfRequestRetrieveOutputBuffer(Request,
            sizeof(ULONG),
            (PVOID*)&Buffer,
            0);
        if (!NT_SUCCESS(Status)) {
            goto end;
        }

        // retrieve SWREG0 of selected core
        *(ULONG *)Buffer = READ_REGISTER_NOFENCE_ULONG((ULONG *)deviceContextPtr->RegistersPtr + ((0x10000 / sizeof(ULONG)) * CoreId));
        BytesWritten = sizeof(ULONG);
        break;

    case IOCTL_VPU_HW_ADDR:
#if 1
        // Don't allow mapping of vpu device memory into user space.
        Status = STATUS_INVALID_DEVICE_REQUEST;
        goto end;
#else
        // drivers pass core id in input buffer.
        if (InputBufferLength != sizeof(ULONG) || OutputBufferLength != sizeof(void *))
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        Status = WdfRequestRetrieveInputBuffer(Request,
            0,
            (PVOID*)&Buffer,
            &BufferSize);
        if (!NT_SUCCESS(Status)) {
            goto end;
        }
        if (BufferSize != sizeof(ULONG))
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        // only support G1 and G2 cores currently
        CoreId = (ULONG)*(ULONG *)Buffer;
        if (CoreId >= IMXVPU_CORE_COUNT) {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        Status = WdfRequestRetrieveOutputBuffer(Request,
            sizeof(void *),
            (PVOID*)&Buffer,
            0);
        if (!NT_SUCCESS(Status)) {
            goto end;
        }

        // return G1 or G2 core - (H264/VP8/PP or HEVC/VP9)
        *(void **)Buffer = ((CHAR *)MapUserModeAddressRegisters(Request) + (0x10000 * CoreId));
        BytesWritten = sizeof(void *);
        break;
#endif

    case IOCTL_VPU_HW_SIZE:
        if (InputBufferLength != sizeof(ULONG) || OutputBufferLength != sizeof(ULONG))
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        Status = WdfRequestRetrieveInputBuffer(Request,
            0,
            (PVOID*)&Buffer,
            &BufferSize);
        if (!NT_SUCCESS(Status)) {
            goto end;
        }
        if (BufferSize != sizeof(ULONG))
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        CoreId = *(ULONG *)Buffer;
        if (CoreId >= IMXVPU_CORE_COUNT) {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        Status = WdfRequestRetrieveOutputBuffer(Request,
            sizeof(ULONG),
            (PVOID*)&Buffer,
            0);
        if (!NT_SUCCESS(Status)) {
            goto end;
        }

        // G1 and G2 cores have different sizes. Client code however ignores the returned size and asserts
        // in debug builds by reading and writing past the length. Return the larger G2 size.
        *(ULONG *)Buffer = MAX_REGS_G2 * sizeof(ULONG);
        BytesWritten = sizeof(ULONG);
        break;

    case IOCTL_VPU_ALLOC_MEM:
        /* S - Check if input-output structure has size */
        if (InputBufferLength != sizeof(IMXVPU_MEMORY) || OutputBufferLength != sizeof(IMXVPU_MEMORY))
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }
        /* E - Check if input-output structure has size */
        /* S - Main body of allocation */
        {
            IMXVPU_MEMORY * pInputSize;      // pointer to input structure
            IMXVPU_MEMORY * pOutputMemory;   // output structure
            WDFFILEOBJECT file;                             // file object - for memlist alloc entry
            MEMORY_CACHING_TYPE cacheType = MmNonCached;    // cache type

            // get file object from WDFREQUEST
            file = WdfRequestGetFileObject(Request);
            // get InputBuffer from WDFREQUEST
            Status = WdfRequestRetrieveInputBuffer(Request,
                0,
                (PVOID*)&pInputSize,
                &BufferSize);
            // Check status of previous call
            if (!NT_SUCCESS(Status)) {
                goto end;
            }
            // Check if received size from previous call is correct
            if (BufferSize != sizeof(IMXVPU_MEMORY))
            {
                Status = STATUS_INVALID_PARAMETER;
                goto end;
            }

            // Check if input PHY and VIRT addresses are NULL!
            if (pInputSize->physAddress != 0 || pInputSize->virtAddress != NULL)
            {
                Status = STATUS_INVALID_ADDRESS;
                goto end;
            }

            // get OutputBuffer from WDFREQUEST
            Status = WdfRequestRetrieveOutputBuffer(Request,
                sizeof(IMXVPU_MEMORY),
                (PVOID*)&pOutputMemory,
                0);

            // Check status of previous call
            if (!NT_SUCCESS(Status)) {
                goto end;
            }

            /* S - allocation of requested memory */
            // allocate contiguous memory for use in user space and also retrieve physical address
            switch (pInputSize->flags)
            {
            case VPU_MEM_CACHED:
                cacheType = MmCached;
                break;
            case VPU_MEM_UNCACHED:
                cacheType = MmNonCached;
                break;
            case VPU_MEM_WRITE_COMBINED:
                cacheType = MmWriteCombined;
                break;
            case VPU_MEM_WC_REUSABLE:
                cacheType = MmWriteCombined;
                break;
            default:
                Status = STATUS_INVALID_PARAMETER;
                goto end;
            }

            ExAcquireFastMutex(&deviceContextPtr->Mutex); // Lock Mutex

            int index = -1;
            /* Find free block if is*/
            for (int i = 0; i < REUSABLE_MEM_BLOCKS_MAX; i++) {
                if (deviceContextPtr->preallocated_mem[i]->occupied != OCCUPIED) {
                    index = i;
                    break;
                }
            }
            if ((pInputSize->flags == VPU_MEM_WC_REUSABLE)
              && (index != -1)
              && (deviceContextPtr->memCounter < REUSABLE_MEM_BLOCKS_MAX)
              && (pInputSize->size <= (VPU_BITS_BUF_SIZE + VPU_MEM_ALIGN)))
            {
                Status = AllocVpuBuffer(&deviceContextPtr->preallocated_mem[index], pInputSize->size, cacheType, file);
                if (Status != STATUS_SUCCESS) {
                    ExReleaseFastMutex(&deviceContextPtr->Mutex); // Unlock Mutex
                    goto end;
                }

                pOutputMemory->physAddress = deviceContextPtr->preallocated_mem[index]->physAddr;
                pOutputMemory->virtAddress = deviceContextPtr->preallocated_mem[index]->virtAddr;
                pOutputMemory->size = pInputSize->size;
                deviceContextPtr->preallocated_mem[index]->occupied = OCCUPIED;
                deviceContextPtr->memCounter++;
                ExReleaseFastMutex(&deviceContextPtr->Mutex); // Unlock Mutex
            }
            else {
                ExReleaseFastMutex(&deviceContextPtr->Mutex); // Unlock Mutex
                /* S - allocation of requested memory */
                Status = PrepareVpuBuffer(&alloc, pInputSize->size, cacheType);
                if (!NT_SUCCESS(Status)) {
                    goto end;
                }
                Status = AllocVpuBuffer(&alloc, pInputSize->size, cacheType, file);
                if (!NT_SUCCESS(Status)) {
                    if (alloc->virtAddr == NULL) {
                        MmFreePagesFromMdl(alloc->mdl);
                        (alloc)->mdl = NULL;
                    }
                    ExFreePoolWithTag(alloc, VPU_KM_ALLOC_TAG_WDF); //Free entry
                    goto end;
                }
                /* E - allocation of requested memory */

                /* S - Fill structure for a client */
                pOutputMemory->physAddress = alloc->physAddr;
                pOutputMemory->virtAddress = alloc->virtAddr;
                pOutputMemory->size = pInputSize->size;
                /* E - Fill structure for a client */

                /* S - Insert entry to MemList*/
                ExAcquireFastMutex(&deviceContextPtr->Mutex); // Lock Mutex
                alloc->next = deviceContextPtr->memList.next;
                deviceContextPtr->memList.next = alloc; // Copy alloc structure to memlist
                ExReleaseFastMutex(&deviceContextPtr->Mutex); // Unlock Mutex
                /* E - Insert entry to MemList*/

                alloc = NULL;
            }
            BytesWritten = sizeof(IMXVPU_MEMORY);
        }
        /* E - Main body of allocation */
        break;

    case IOCTL_VPU_FREE_MEM:


        /* S - Check if input-output structure has correct size */
        if (InputBufferLength != sizeof(IMXVPU_MEMORY) || OutputBufferLength != 0)
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }
        /* E - Check if input-output structure has correct size */

        /* S - Main body of free */
        {
            IMXVPU_MEMORY * pInputMemory; // pointer to input structure
            // get InputBuffer from WDFREQUEST
            Status = WdfRequestRetrieveInputBuffer(Request,
                0,
                (PVOID*)&pInputMemory,
                &BufferSize);
            // Check status of previous call
            if (!NT_SUCCESS(Status)) {
                goto end;
            }
            // Check if received size from previous call is correct

            if (BufferSize != sizeof(IMXVPU_MEMORY))
            {
                Status = STATUS_INVALID_PARAMETER;
                goto end;
            }

            // Check if input PHY and VIRT addresses are NOT NULL!
            if (pInputMemory->physAddress == 0 || pInputMemory->virtAddress == NULL)
            {
                Status = STATUS_INVALID_ADDRESS;
                goto end;
            }

            // Check if memory is _preallocated
            ExAcquireFastMutex(&deviceContextPtr->Mutex); // Lock MemList Mutex
            for (int i = 0; i < REUSABLE_MEM_BLOCKS_MAX; i++) {
                if ((pInputMemory->virtAddress == deviceContextPtr->preallocated_mem[i]->virtAddr)
                    && (pInputMemory->physAddress == deviceContextPtr->preallocated_mem[i]->physAddr)
                    )
                {
                    deviceContextPtr->preallocated_mem[i]->file = NULL;
                    deviceContextPtr->preallocated_mem[i]->occupied = REUSABLE;
                    deviceContextPtr->memCounter--;
                    MmUnmapLockedPages(deviceContextPtr->preallocated_mem[i]->virtAddr, deviceContextPtr->preallocated_mem[i]->mdl);
                    deviceContextPtr->preallocated_mem[i]->virtAddr = NULL;

                    ExReleaseFastMutex(&deviceContextPtr->Mutex); // Unlock MemList Mutex
                    Status = STATUS_SUCCESS;
                    goto end;
                }
            }

            // search for allocated memory block
            VpuAlloc *ptr;   // Entry pointer
            VpuAlloc *prev;  // Previous entry pointer

            prev = &deviceContextPtr->memList;            // assign beggining pointer
            ptr = prev->next;                             // assign next pointe
            while (ptr != NULL) {
                if ((ptr->virtAddr == pInputMemory->virtAddress) && (ptr->physAddr == pInputMemory->physAddress)) {
                    // unlink entry
                    prev->next = ptr->next;
                    ptr->next = NULL;
                    break;
                }
                prev = ptr;
                ptr = ptr->next;
            }
            ExReleaseFastMutex(&deviceContextPtr->Mutex); // Unlock MemList Mutex

            if (ptr == NULL)
            {
                TraceEvents(TRACE_LEVEL_ERROR, IMXVPU_QUEUE_TRACE, "FreeBlock not found");
                Status = STATUS_INVALID_ADDRESS;
                goto end;
            }

            FreeVpuBuffer(ptr); //Free

            Status = STATUS_SUCCESS;
        }
        /* E - Main body of free */
        break;

    case IOCTL_VPU_DEC_PULL_REG:
    {
        IMXVPU_REGISTERS * pInputMemory;
        IMXVPU_REGISTERS * pOutputMemory;
        int regCount;

        if ((InputBufferLength != (2 * sizeof(ULONG))) || OutputBufferLength > sizeof(IMXVPU_REGISTERS))
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        Status = WdfRequestRetrieveInputBuffer(Request,
            sizeof(ULONG) * 2,
            (PVOID*)&pInputMemory,
            &BufferSize);

        if (!NT_SUCCESS(Status)) {
            goto end;
        }

        NT_ASSERT(BufferSize == InputBufferLength);
        if (pInputMemory->coreid >= IMXVPU_CORE_COUNT) {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        if (((pInputMemory->regSize % sizeof(ULONG)) != 0) ||
            (pInputMemory->regSize > (MAX_REGS_G2 * sizeof(ULONG)))) {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        if (OutputBufferLength != (sizeof(ULONG) * 2 + pInputMemory->regSize))
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        Status = WdfRequestRetrieveOutputBuffer(Request,
            OutputBufferLength,
            (PVOID*)&pOutputMemory,
            0);

        if (!NT_SUCCESS(Status)) {
            goto end;
        }

        pOutputMemory->coreid = pInputMemory->coreid;
        pOutputMemory->regSize = pInputMemory->regSize;

        // truncate the number of registers returned if larger than the actual block size
        regCount = pInputMemory->regSize / sizeof(ULONG);
        if (regCount > vpuDecSize[pInputMemory->coreid])
        {
            regCount = vpuDecSize[pInputMemory->coreid];
        }

        for (int i = 0; i < regCount; i++)
        {
            pOutputMemory->regs[i] = READ_REGISTER_NOFENCE_ULONG((ULONG *)deviceContextPtr->RegistersPtr + ((0x10000 / sizeof(ULONG)) * pInputMemory->coreid) + i);
        }
        BytesWritten = sizeof(ULONG) * 2 + pOutputMemory->regSize;
        break;
    }

    case IOCTL_VPU_DEC_PUSH_REG:
    {
        IMXVPU_REGISTERS * pInputMemory;
        int regCount;

        if ((InputBufferLength < (2 * sizeof(ULONG))) || OutputBufferLength != 0)
        {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        Status = WdfRequestRetrieveInputBuffer(Request,
            sizeof(ULONG) * 2,
            (PVOID*)&pInputMemory,
            &BufferSize);

        if (!NT_SUCCESS(Status)) {
            goto end;
        }

        NT_ASSERT(BufferSize == InputBufferLength);
        if (pInputMemory->coreid >= IMXVPU_CORE_COUNT) {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        if ((pInputMemory->regSize % sizeof(ULONG)) != 0) {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        if ((InputBufferLength < (2 * sizeof(ULONG) + pInputMemory->regSize)) ||
            (pInputMemory->regSize < (2 * sizeof(ULONG)))) {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        if (((pInputMemory->regSize % sizeof(ULONG)) != 0) ||
            (pInputMemory->regSize > (MAX_REGS_G2 * sizeof(ULONG)))) {
            Status = STATUS_INVALID_PARAMETER;
            goto end;
        }

        // truncate the number of registers written if larger than the actual block size
        // The G1 block is only 512 bytes long, though the client thinks it's larger and
        // will attempt to write the non-existant PP registers.  On the iMX8M devices, the
        // memory decoding for the block only uses the first 9 address bits so writes past 512 
        // will write to aliased registers.
        regCount = pInputMemory->regSize / sizeof(ULONG);
        if (regCount > vpuDecSize[pInputMemory->coreid])
        {
            regCount = vpuDecSize[pInputMemory->coreid];
        }

        // write all the registers above 2 first
        for (int i = 2; i < regCount; i++)
        {
            WRITE_REGISTER_NOFENCE_ULONG(((ULONG *)deviceContextPtr->RegistersPtr + ((0x10000 / sizeof(ULONG)) * pInputMemory->coreid) + i), pInputMemory->regs[i]);
        }

        // write the status register last since it might trigger the hw
        WRITE_REGISTER_NOFENCE_ULONG(((ULONG *)deviceContextPtr->RegistersPtr + ((0x10000 / sizeof(ULONG)) * pInputMemory->coreid) + 1), pInputMemory->regs[1]);

        break;
    }

    case IOCTL_VPU_CACHE_FLUSH:
    case IOCTL_VPU_CACHE_INVALIDATE:
        Status = VpuCacheOperation(Request, deviceContextPtr, IoControlCode, OutputBufferLength, InputBufferLength);
        break;

    case IOCTL_VPU_DEC_RESERVE:
        Status = VpuDecoderReserve(Request, deviceContextPtr, OutputBufferLength, InputBufferLength, &BytesWritten);
        if (Status == STATUS_WAIT_1)
        {
            // VPU busy, don't complete request
            return;
        }
        break;

    case IOCTL_VPU_DEC_RELEASE:
        Status = VpuDecoderRelease(Request, deviceContextPtr, OutputBufferLength, InputBufferLength);
        break;

    default:
        Status = STATUS_INVALID_DEVICE_REQUEST;
    }

end:
    WdfRequestCompleteWithInformation(Request, Status, BytesWritten);
    return;
}

IMXVPU_PAGED_SEGMENT_END
