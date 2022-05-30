/*
* This file is derived from Microsoft example available on https://github.com/microsoft/Windows-driver-samples/blob/master/usb/UcmTcpciCxClientSample
* Original file licensing:
* Copyright (c) 2015 Microsoft
* SPDX-License-Identifier: MS-PL
* NXP modifications are licensed under the same license
* Copyright 2020 NXP
*
*/

#include "imx_tcpci.h"
#if (TCPCI_TRACE == TCPCI_TRACE_WPP)
#include "imx_tcpci_i2c.tmh"
#endif

#ifdef ALLOC_PRAGMA
#pragma alloc_text (PAGE, IO_Initialize)
#pragma alloc_text (PAGE, I2C_Open)
#pragma alloc_text (PAGE, I2C_Close)

#pragma alloc_text (PAGE, GPIO_Open)
#pragma alloc_text (PAGE, GPIO_Close)
#endif

/*++
Routine Description:
    Initialize the I2C and GPIO resources that provides a communications channel to the port controller hardware.
Arguments:
    pDevContext         - Context for a framework device.
    ResourcesRaw        - Handle to a framework resource-list object that identifies the raw hardware resources that the Plug and Play manager has assigned to the device.
    ResourcesTranslated - Handle to a framework resource-list object that identifies the translated hardware resources that the Plug and Play manager has assigned to the device.
Return Value:  NTSTATUS
--*/
NTSTATUS IO_Initialize(_In_ PDEV_CONTEXT pDevContext, _In_ WDFCMRESLIST hResourcesRaw, _In_ WDFCMRESLIST hResourcesTranslated) {
    NTSTATUS                        ntStatus = STATUS_SUCCESS;
    WDFINTERRUPT                    AlertInterrupt;
    WDF_INTERRUPT_CONFIG            interruptConfig;
    PCM_PARTIAL_RESOURCE_DESCRIPTOR descriptor = nullptr;
    ULONG                           interruptIndex = 0;
    BOOLEAN                         connFound = FALSE;
    BOOLEAN                         interruptFound = FALSE;
    ULONG                           resourceCount;
    int                             pinCount = 0;
    int                             i2cCount = 0;

    DBG_I2C_METHOD_BEG();
    PAGED_CODE();
    UNREFERENCED_PARAMETER(hResourcesRaw);
    /* Check for I2C and Interrupt resources from the resources that PnP manager has allocated to our device. */
    resourceCount = WdfCmResourceListGetCount(hResourcesTranslated);
    for (ULONG i = 0; i < resourceCount; i++) {
        descriptor = WdfCmResourceListGetDescriptor(hResourcesTranslated, i);
        switch (descriptor->Type) {
            case CmResourceTypeConnection:  /* Check for I2C resource */
                if (descriptor->u.Connection.Class == CM_RESOURCE_CONNECTION_CLASS_SERIAL && descriptor->u.Connection.Type == CM_RESOURCE_CONNECTION_TYPE_SERIAL_I2C) {
                    if (++i2cCount == 1) {
                        pDevContext->I2C_ConnectionId.LowPart  = descriptor->u.Connection.IdLowPart;
                        pDevContext->I2C_ConnectionId.HighPart = descriptor->u.Connection.IdHighPart;
                        connFound = TRUE;
                    }
                    DBG_DEV_PRINT_INFO("I2C resource found with connection id: 0x%llx", pDevContext->I2C_ConnectionId.QuadPart);
                }
                if ((descriptor->u.Connection.Class == CM_RESOURCE_CONNECTION_CLASS_GPIO) && (descriptor->u.Connection.Type == CM_RESOURCE_CONNECTION_TYPE_GPIO_IO)) {
                    if (++pinCount == 2) {
                        pDevContext->GPIO_ConnectionId.LowPart  = descriptor->u.Connection.IdLowPart;
                        pDevContext->GPIO_ConnectionId.HighPart = descriptor->u.Connection.IdHighPart;
                        DBG_DEV_PRINT_INFO("USB Type-C SuperSpeed switch pin resource found with connection id: 0x%llx", pDevContext->GPIO_ConnectionId.QuadPart);
                    }
                }
                break;
            case CmResourceTypeInterrupt:   /* We've found an interrupt resource. */
                interruptFound = TRUE;
                interruptIndex = i;
                DBG_DEV_PRINT_INFO("Interrupt resource found at index: %lu", interruptIndex);
                break;
            default:            
                break;                       /* We don't care about other descriptors. */
        }
    }    
    do {
        if (!connFound) {                    /* Fail if either connection or interrupt resource was not found. */
            ntStatus = STATUS_INSUFFICIENT_RESOURCES;
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "Failed finding required I2C resource.");
            break;
        }
        if (!interruptFound) {
            ntStatus = STATUS_INSUFFICIENT_RESOURCES;
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "Failed finding required interrupt resource.");
            break;
        }
        /* The alerts from the port controller hardware will be handled in a passive ISR. */
        /* The ISR performs hardware read and write operations which block until the hardware access is complete. Waiting is unacceptable at DIRQL, so we perform our ISR at PASSIVE_LEVEL. */
        WDF_INTERRUPT_CONFIG_INIT(&interruptConfig, OnInterruptPassiveIsr, NULL);
        interruptConfig.PassiveHandling     = TRUE;
        interruptConfig.InterruptTranslated = WdfCmResourceListGetDescriptor(hResourcesTranslated, interruptIndex);
        interruptConfig.InterruptRaw        = WdfCmResourceListGetDescriptor(hResourcesRaw, interruptIndex);
        if (!NT_SUCCESS(ntStatus = WdfInterruptCreate(pDevContext->Device, &interruptConfig, WDF_NO_OBJECT_ATTRIBUTES, &AlertInterrupt))) {
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "WdfInterruptCreate() failed.");
            break;
        }
    } while (0);
    DBG_I2C_METHOD_END_WITH_STATUS(ntStatus);
    return ntStatus;
}

/*++
Routine Description:
    This routine opens a handle to the GPIO pin.
Arguments:
    pDevContext - A pointer to the device context
Return Value:
    NTSTATUS
--*/
NTSTATUS GPIO_Open(_In_ PDEV_CONTEXT pDevContext) {
    NTSTATUS                        ntStatus;
    WDF_IO_TARGET_OPEN_PARAMS       OpenParams;
    WDF_OBJECT_ATTRIBUTES           Attributes;
    DECLARE_UNICODE_STRING_SIZE(usDevicePath, RESOURCE_HUB_PATH_SIZE);      /* Create the device path using the connection ID. */

    DBG_I2C_METHOD_BEG();
    PAGED_CODE();
    do {
        if (pDevContext->GPIO_ConnectionId.QuadPart == 0) {
            DBG_CONFIG_DUMP("No GPIO found");
            ntStatus = STATUS_SUCCESS;
            break;
        }
        RESOURCE_HUB_CREATE_PATH_FROM_ID(&usDevicePath, pDevContext->GPIO_ConnectionId.LowPart, pDevContext->GPIO_ConnectionId.HighPart);
        DBG_CONFIG_DUMP("Opening handle to GPIO target via %wZ", &usDevicePath);
        if (!NT_SUCCESS(ntStatus = WdfIoTargetCreate(pDevContext->Device, WDF_NO_OBJECT_ATTRIBUTES, &pDevContext->GPIO_hTarget))) {
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "GPIO - WdfIoTargetCreate() failed.");
            break;
        }
        /* Open a handle to the controller. */
        WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME(&OpenParams, &usDevicePath, GENERIC_WRITE);
        if (!NT_SUCCESS(ntStatus = WdfIoTargetOpen(pDevContext->GPIO_hTarget, &OpenParams))) {
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "GPIO - WdfIoTargetOpen() failed.");
            break;
        }
        WDF_OBJECT_ATTRIBUTES_INIT(&Attributes);
        Attributes.ParentObject = pDevContext->GPIO_hTarget;
        if (!NT_SUCCESS(ntStatus = WdfRequestCreate(&Attributes, pDevContext->GPIO_hTarget, &pDevContext->GPIO_hRequest))) {
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "GPIO - WdfRequestCreate() failed.");
            break;
        }
        WDF_OBJECT_ATTRIBUTES_INIT(&Attributes);
        Attributes.ParentObject = pDevContext->GPIO_hRequest;
        if (!NT_SUCCESS(ntStatus = WdfMemoryCreatePreallocated(&Attributes, &pDevContext->GPIO_IO_Data, sizeof(pDevContext->GPIO_IO_Data), &pDevContext->GPIO_hMemory))) {
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "GPIO - WdfMemoryCreatePreallocated() failed.");
            break;
        }
    } while (0);
    DBG_I2C_METHOD_END_WITH_STATUS(ntStatus);
    return ntStatus;
}

/*++
Routine Description:
    This routine opens a handle to the I2C controller and prepares structures for I2C transfers.
Arguments:
    pDevContext - A pointer to the device context
Return Value:
    NTSTATUS
--*/
NTSTATUS I2C_Open(_In_ PDEV_CONTEXT pDevContext) {
    NTSTATUS                  ntStatus;
    WDF_IO_TARGET_OPEN_PARAMS OpenParams;
    WDF_OBJECT_ATTRIBUTES     RequestAttributes;
    DBG_I2C_METHOD_BEG();
    PAGED_CODE();
    /* Create the device path using the connection ID. */
    DECLARE_UNICODE_STRING_SIZE(usDevicePath, RESOURCE_HUB_PATH_SIZE);
    do {
        RESOURCE_HUB_CREATE_PATH_FROM_ID(&usDevicePath, pDevContext->I2C_ConnectionId.LowPart, pDevContext->I2C_ConnectionId.HighPart);
        DBG_CONFIG_DUMP("Opening handle to I2C target via %wZ", &usDevicePath);
        if (!NT_SUCCESS(ntStatus = WdfIoTargetCreate(pDevContext->Device, WDF_NO_OBJECT_ATTRIBUTES, &pDevContext->I2C_hTarget))) {
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "WdfIoTargetCreate failed");
            break;
        }
        /* Open a handle to the I2C controller. */
        WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME(&OpenParams, &usDevicePath, (GENERIC_READ | GENERIC_WRITE));
        OpenParams.ShareAccess       = 0;
        OpenParams.CreateDisposition = FILE_OPEN;
        OpenParams.FileAttributes    = FILE_ATTRIBUTE_NORMAL;
        if (!NT_SUCCESS(ntStatus = WdfIoTargetOpen(pDevContext->I2C_hTarget, &OpenParams))) {
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "Failed to open I2C I/O target.");
            break;
        }
        WDF_OBJECT_ATTRIBUTES_INIT(&RequestAttributes);
        RequestAttributes.ParentObject = pDevContext->I2C_hTarget;
        if (!NT_SUCCESS(ntStatus = WdfRequestCreate(&RequestAttributes, pDevContext->I2C_hTarget, &pDevContext->I2C_hRequest))) {
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "WdfRequestCreate failed.");
            break;
        }
        /* Create a WDFMEMORY object. Do call WdfMemoryAssignBuffer before use it. */
        if (!NT_SUCCESS(ntStatus = WdfMemoryCreatePreallocated(WDF_NO_OBJECT_ATTRIBUTES, static_cast<PVOID>(&ntStatus), sizeof(ntStatus), &pDevContext->I2C_hRxMemory))) {
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "WdfMemoryCreatePreallocated failed.");
            break;
        }
        if (!NT_SUCCESS(ntStatus = WdfMemoryCreatePreallocated(WDF_NO_OBJECT_ATTRIBUTES, static_cast<PVOID>(&ntStatus), sizeof(ntStatus), &pDevContext->I2C_hTxMemory))) {
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "WdfMemoryCreatePreallocated failed.");
            break;
        }
        SPB_TRANSFER_LIST_INIT(&(pDevContext->I2C_RxTrList.List), 2);
        pDevContext->I2C_RxTrList.List.Transfers[0] = SPB_TRANSFER_LIST_ENTRY_INIT_SIMPLE(SpbTransferDirectionToDevice,   0, &pDevContext->I2C_Buffer.I2C_Cmd.Cmd.RegAddress, 1);
        pDevContext->I2C_RxTrList.List.Transfers[1] = SPB_TRANSFER_LIST_ENTRY_INIT_SIMPLE(SpbTransferDirectionFromDevice, 0, &pDevContext->I2C_Buffer.I2C_Cmd.Cmd.RegValue, 0);
        if (!NT_SUCCESS(ntStatus = WdfMemoryAssignBuffer(pDevContext->I2C_hRxMemory, static_cast<PVOID>(&pDevContext->I2C_RxTrList), sizeof(pDevContext->I2C_RxTrList)))) {
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "WdfMemoryAssignBuffer failed.");
            break;
        }
        SPB_TRANSFER_LIST_INIT(&(pDevContext->I2C_TxTrList), 1);
        pDevContext->I2C_TxTrList.Transfers[0] = SPB_TRANSFER_LIST_ENTRY_INIT_SIMPLE(SpbTransferDirectionToDevice, 0, &pDevContext->I2C_Buffer.I2C_Cmd.Cmd.RegAddress, 1);
        if (!NT_SUCCESS(ntStatus = WdfMemoryAssignBuffer(pDevContext->I2C_hTxMemory, static_cast<PVOID>(&pDevContext->I2C_TxTrList), sizeof(pDevContext->I2C_TxTrList)))) {
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "WdfMemoryAssignBuffer failed.");
            break;
        }
        WDF_REQUEST_SEND_OPTIONS_INIT(&pDevContext->I2C_ReqSendOptions, WDF_REQUEST_SEND_OPTION_SYNCHRONOUS);
        WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT(&pDevContext->I2C_ReqSendOptions, WDF_REL_TIMEOUT_IN_MS(I2C_SYNCHRONOUS_TIMEOUT_MS));        
        WDF_REQUEST_REUSE_PARAMS_INIT(&pDevContext->I2C_WdfRequestReuseParams, WDF_REQUEST_REUSE_NO_FLAGS, STATUS_SUCCESS);

    } while (0);
    DBG_I2C_METHOD_END_WITH_STATUS(ntStatus);
    return ntStatus;
}

/*++
Routine Description:
    This routine closes a handle to the I2C controller.
Arguments:
    pDevContext - a pointer to the device context.
--*/
void I2C_Close(_In_ PDEV_CONTEXT pDevContext) {
    DBG_I2C_METHOD_BEG();
    PAGED_CODE();
    if (pDevContext->I2C_hTarget != WDF_NO_HANDLE) {
        DBG_I2C_PRINT_INFO("Closing handle to I2C target");
        WdfIoTargetClose(pDevContext->I2C_hTarget);
    }
    DBG_I2C_METHOD_END();
}

/*++
Routine Description:
    This routine closes a handle to the GPIO pin.
Arguments:
    pDevContext - a pointer to the device context.
--*/
void GPIO_Close(_In_ PDEV_CONTEXT pDevContext) {
    DBG_I2C_METHOD_BEG();
    PAGED_CODE();
    if (pDevContext->GPIO_hTarget != WDF_NO_HANDLE) {
        DBG_I2C_PRINT_INFO("Closing handle to I2C target");
        WdfIoTargetClose(pDevContext->GPIO_hTarget);
    }
    DBG_I2C_METHOD_END();
}

/*++
Routine Description:
    This routine sets plug orientation GPIO according to value in input parametr.
Arguments:
    pDevContext  - Pointer to the device context.
    TCPC_CONTROL - Value vritten to the TCPC_CONTROL register.
Return Value:
    NTSTATUS
--*/
NTSTATUS GPIO_PlugOrientation_Set(_In_ PDEV_CONTEXT pDevContext, TCPC_PHY_TCPC_CONTROL_t TCPC_CONTROL) {
    NTSTATUS  ntStatus = STATUS_SUCCESS;

    DBG_I2C_METHOD_BEG();
    do {
        if (TCPC_CONTROL.B.PLUG_ORIENTATION) {
            pDevContext->GPIO_IO_Data = 0x00;
        } else {
            pDevContext->GPIO_IO_Data = 0x01;
        }
        DBG_TCPCI_REG_DUMP("GPIO_PlugOrientation_Set - Setting Plug Orientation GPIO pin, value = %d", pDevContext->GPIO_IO_Data);
        if (!NT_SUCCESS(ntStatus = WdfIoTargetFormatRequestForIoctl(pDevContext->GPIO_hTarget, pDevContext->GPIO_hRequest, IOCTL_GPIO_WRITE_PINS, pDevContext->GPIO_hMemory, 0, pDevContext->GPIO_hMemory, 0))) {
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "GPIO - WdfIoTargetFormatRequestForIoctl() failed.");
            break;
        }
        /* Send the request to the GPIO Target. */
        if (WdfRequestSend(pDevContext->GPIO_hRequest, pDevContext->GPIO_hTarget, NULL) == FALSE) {
            ntStatus = WdfRequestGetStatus(pDevContext->GPIO_hRequest);
            DBG_I2C_PRINT_ERROR_WITH_STATUS(ntStatus, "[WDFREQUEST: 0x%p] WdfRequestSend for GPIO write failed.", pDevContext->GPIO_hRequest);
            break;
        }
    } while (0);
    DBG_I2C_METHOD_END_WITH_STATUS(ntStatus);
    return ntStatus;
}

/*++
Routine Description:
    EvtIoDeviceControl() IOCTL completition routine.
Arguments:
    pDevContext  - Pointer to the device context.
    I2C_Cmd      - Current I2C command.
    ntStatus     - ntStatus passed to WdfRequestComplete() method. 
--*/
void IOCTL_CompleteRequest(_In_ DEV_CONTEXT *pDevContext, _In_ I2C_IO_CMD_t I2C_Cmd, _In_ NTSTATUS ntStatus) {
    WDFREQUEST  IOCTL_hRequest = pDevContext->IOCTL_hRequest;
    LONG        IoctlAndIsrSyncCounter;

    ASSERT(IOCTL_hRequest != WDF_NO_HANDLE);
    pDevContext->IOCTL_hRequest = WDF_NO_HANDLE;
    if (I2C_Cmd.Cmd.Read) {
        WdfRequestSetInformation(IOCTL_hRequest, (ULONG_PTR)pDevContext->IOCTL_BufferSize);
        DBG_IOCTL_CMD_DUMP("--- WDFREQUEST: 0x%p, Ioctl:%s, Size: %d, ntStatus: 0x%08X", IOCTL_hRequest, Dbg_GetI2CIOSrcName(I2C_Cmd.IOSrcIdx), pDevContext->IOCTL_BufferSize, ntStatus);
    } else {
        DBG_IOCTL_CMD_DUMP("--- WDFREQUEST: 0x%p, Ioctl:%s, ntStatus: 0x%08X", IOCTL_hRequest, Dbg_GetI2CIOSrcName(I2C_Cmd.IOSrcIdx), ntStatus);
    }
    if ((IoctlAndIsrSyncCounter=InterlockedDecrement(&pDevContext->IoctlAndIsrSyncCounter)) == 1) {    /* Passive ISR pending? */
        DBG_IOCTL_CMD_DUMP("IOCTL_DONE: ISR peding Setting event ...");             
        KeSetEvent(&pDevContext->IoctlAndIsrSyncEvent, 0, FALSE);                                      /* Wake up passive ISR */
    }
    DBG_IOCTL_CMD_DUMP("IOCTL_DONE: InterlockedDecrement(&InterlockedDecrement->I2C_Lock) = %d", IoctlAndIsrSyncCounter);
    WdfRequestComplete(IOCTL_hRequest, ntStatus);             /*  Complete Io request */
}

/*++
Routine Description:
    This method is called after each I2C IO transfer is done. It updates read buffers and starts new I2C IO trensfer.
Arguments:
    pDevContext  - Pointer to the device context.
    ntStatus     - ntStatus passed to WdfRequestComplete() method. 
--*/
void UpdateRegsAndBuffer(_In_ DEV_CONTEXT *pDevContext, _In_ NTSTATUS  ntStatus) {
    I2C_IO_CMD_t    I2C_Cmd  = pDevContext->I2C_Buffer.I2C_Cmd;
    unsigned int DataSize;

    if (!NT_SUCCESS(ntStatus)) {
        I2C_Cmd.Cmd.LastCmd = 1;   
    } else {
        if (I2C_Cmd.Cmd.RegSize == 1) {
            /* Copy value read from/written to 1 byte size register to the local copy of register. */
            ((UINT8*)(&pDevContext->TCPI_PhyRegs))[I2C_Cmd.Cmd.RegAddress] = *(UINT8*)(&pDevContext->I2C_Buffer.I2C_Cmd.Cmd.RegValue);                   
            if (I2C_Cmd.pBuffer) {
                ((UINT8*)(I2C_Cmd.pBuffer))[0] = *(UINT8*)(&pDevContext->I2C_Buffer.I2C_Cmd.Cmd.RegValue);
            }
            DataSize = 1U;
        } else if (I2C_Cmd.Cmd.RegSize == 2) {
            /* Copy value read from/written to 2 bytes size register to the local copy of register. */
            *(UINT16*)&(((UINT8*)(&pDevContext->TCPI_PhyRegs))[I2C_Cmd.Cmd.RegAddress]) = *(UINT16*)(&pDevContext->I2C_Buffer.I2C_Cmd.Cmd.RegValue);
            if (I2C_Cmd.pBuffer) {
                ((UINT16*)(I2C_Cmd.pBuffer))[0] = *(UINT16*)(&pDevContext->I2C_Buffer.I2C_Cmd.Cmd.RegValue);
            }
            DataSize = 2U;
        } else {
            if (I2C_Cmd.pBuffer) {
                RtlCopyMemory(I2C_Cmd.pBuffer, ((UINT8 *)&pDevContext->I2C_Buffer.I2C_Cmd.Cmd.RegValue), (UINT8)I2C_Cmd.Cmd.BufferSize + 1);
            }
            DataSize = I2C_Cmd.Cmd.BufferSize;
        }  
        if (I2C_Cmd.Cmd.Ioctl) {
            pDevContext->IOCTL_BufferSize += DataSize;                     /* For each IOCTL request update handled data counter.                          */
        }
        TCPC_PHY_DumpReg(Dbg_GetI2CIOSrcName(I2C_Cmd.IOSrcIdx), &pDevContext->TCPI_PhyRegs, I2C_Cmd.Cmd.RegAddress, !I2C_Cmd.Cmd.Read, DataSize);
    }
    if (I2C_Cmd.Cmd.LastCmd) {                                             /* If this I2C I/O command is the last I2C I/O command in the I2C I/O sequence, */                               
        if (I2C_Cmd.Cmd.Ioctl) {                                           /* and this sequece is for a IOCTL request,                                     */
            IOCTL_CompleteRequest(pDevContext, I2C_Cmd, ntStatus);         /* Complete this IOCTL request.                                                 */
        } 
    } else {                                                               /* If this I2C I/O command is not the last I2C command in the I2C I/O sequence, */
        pDevContext->I2C_pCurrentCmd++;                                    /* update the pointer to poit to the new I2C I/O command                        */
        I2C_PrepareI2CRequest(pDevContext, *pDevContext->I2C_pCurrentCmd); /* and start this new command.                                                  */
    }
}

/*++
Routine Description:
    This method is called after assynchronnous I2C IO transfer is done.
--*/
VOID I2C_OnI2CRequestCompletion(_In_ WDFREQUEST hRequest, _In_ WDFIOTARGET Target, _In_ PWDF_REQUEST_COMPLETION_PARAMS Params, _In_ WDFCONTEXT Context) {
    UNREFERENCED_PARAMETER(Target);
    UNREFERENCED_PARAMETER(hRequest);

    DBG_I2C_METHOD_BEG();
    DBG_I2C_PRINT_VERBOSE("Asynchronnous I2C IO Request done");
    UpdateRegsAndBuffer((PDEV_CONTEXT)Context, Params->IoStatus.Status);
    DBG_I2C_METHOD_END();
}

/*++
Routine Description:
    This method is to starts new I2C IO transfer.
Arguments:
    pDevContext  - Pointer to the device context.
    I2C_Cmd      - I2C IO command to start. 
Return Value:
    NTSTATUS
--*/
NTSTATUS I2C_PrepareI2CRequest(DEV_CONTEXT *pDevContext, I2C_IO_CMD_t I2C_Cmd) {
    NTSTATUS                  ntStatus;
    WDFMEMORY                 hMemory;

    DBG_I2C_METHOD_BEG();
    do {
        pDevContext->I2C_Buffer.I2C_Cmd = I2C_Cmd;                                                                                 /* Copy Cmd DWORD to the I2C data buffer. It sets register address and register data(for reg. write) */
        if (I2C_Cmd.Cmd.Read) {                                                                                                    /* Register/buffer read?                                                                             */
            if (I2C_Cmd.Cmd.RegSize != 0) {                                                                                        /* Register read?                                                                                    */
                pDevContext->I2C_RxTrList.List.Transfers[1].Buffer.Simple.BufferCb = I2C_Cmd.Cmd.RegSize;                          /* Remember register size                                                                            */
            } else {                                                                                                               /* Buffer read                                                                                       */
                ASSERT(I2C_Cmd.Cmd.BufferSize <= TCPCI_I2C_DATA_BUFFER_SIZE);
                pDevContext->I2C_RxTrList.List.Transfers[1].Buffer.Simple.BufferCb = I2C_Cmd.Cmd.BufferSize;                       /* Remember data buffer size                                                                         */
            }
            hMemory = pDevContext->I2C_hRxMemory;                                                                                   /* Use Rx transfer memory descriptor                                                                */
        } else { /* I2C_Cmd.Direction == TCPCI_RW_CMD_DIR_WR */
            if (I2C_Cmd.Cmd.RegSize != 0) {                                                                                        /* Register write?                                                                                   */
                pDevContext->I2C_TxTrList.Transfers[0].Buffer.Simple.BufferCb = I2C_Cmd.Cmd.RegSize + 1;                           /* Remember register size (plus one byte for register address)                                       */
            } else {                                                                                                               /* Buffer write                                                                                      */
                ASSERT(I2C_Cmd.Cmd.BufferSize <= TCPCI_I2C_DATA_BUFFER_SIZE);
                pDevContext->I2C_TxTrList.Transfers[0].Buffer.Simple.BufferCb = I2C_Cmd.Cmd.BufferSize + 1;                        /* Remember data buffer size (plus one byte for register address)                                    */
                RtlCopyMemory(&pDevContext->I2C_Buffer.I2C_Cmd.Cmd.RegValue, I2C_Cmd.pBuffer, I2C_Cmd.Cmd.BufferSize);             /* Copy data to I2C buffer                                                                           */
                pDevContext->I2C_Buffer.I2C_Cmd.pBuffer = NULL;                                                                    /* Do not update buffer on complete                                                                  */
            }
            hMemory = pDevContext->I2C_hTxMemory;                                                                                   /* Use Tx transfer memory descriptor                                                                */
        }
        /* Reuse the preallocated WDFREQUEST for I2C. */
        if (!NT_SUCCESS(ntStatus = WdfRequestReuse(pDevContext->I2C_hRequest, &pDevContext->I2C_WdfRequestReuseParams))) {
            DBG_PRINT_ERROR_WITH_STATUS(ntStatus, "WdfRequestReuse failed.");
            break;
        }
        if (!NT_SUCCESS(ntStatus = WdfIoTargetFormatRequestForIoctl(pDevContext->I2C_hTarget, pDevContext->I2C_hRequest, IOCTL_SPB_EXECUTE_SEQUENCE, hMemory, NULL, NULL, NULL))) {
            DBG_PRINT_ERROR_WITH_STATUS(ntStatus, "WdfIoTargetFormatRequestForIoctl failed.");
            break;
        }    
        if (I2C_Cmd.Cmd.SyncCmd) {
            DBG_I2C_PRINT_VERBOSE("Starting synchronnous I2C IO Request");
            if ((WdfRequestSend(pDevContext->I2C_hRequest, pDevContext->I2C_hTarget, &pDevContext->I2C_ReqSendOptions) == FALSE)) {
                if (!NT_SUCCESS(ntStatus = WdfRequestGetStatus(pDevContext->I2C_hRequest))) {
                    DBG_PRINT_ERROR_WITH_STATUS(ntStatus, "[WDFREQUEST: 0x%p] WdfRequestSend for I2C failed.", pDevContext->I2C_hRequest);
                    break;
                }
            }
            DBG_I2C_PRINT_VERBOSE("Synchronnous I2C IO Request done");
            UpdateRegsAndBuffer(pDevContext, ntStatus);
        } else {
            WdfRequestSetCompletionRoutine(pDevContext->I2C_hRequest, I2C_OnI2CRequestCompletion, pDevContext);
            DBG_I2C_PRINT_VERBOSE("Starting asynchronnous I2C IO Request");
            if (WdfRequestSend(pDevContext->I2C_hRequest, pDevContext->I2C_hTarget, NULL) == FALSE) {
                ntStatus = WdfRequestGetStatus(pDevContext->I2C_hRequest);
                DBG_PRINT_ERROR_WITH_STATUS(ntStatus, "[WDFREQUEST: 0x%p] WdfRequestSend for Async I2C failed.", pDevContext->I2C_hRequest);
                if (I2C_Cmd.Cmd.Ioctl) {                
                    IOCTL_CompleteRequest(pDevContext, I2C_Cmd, ntStatus);
                }
            }
        }
    } while (0);
    DBG_I2C_METHOD_END_WITH_STATUS(ntStatus);
    return ntStatus;
}

/*++
Routine Description:
    This method is to starts new I2C IO command sequence from IOCTL handler.
Arguments:
    pDevContext  - Pointer to the device context.
    I2C_Cmd      - Pointer to the first I2C IO command. 
Return Value:
    NTSTATUS
--*/
NTSTATUS I2C_IOCTL(DEV_CONTEXT *pDevContext, I2C_IO_CMD_t *pI2C_Cmd) {
    NTSTATUS  ntStatus;
    LONG      IoctlAndIsrSyncCounter;
    
    DBG_I2C_METHOD_BEG();
    if ((IoctlAndIsrSyncCounter=InterlockedIncrement(&pDevContext->IoctlAndIsrSyncCounter)) == 1) {
        /* No I2C command is pending, start IOCTL I2C IO seequence */
        DBG_IOCTL_CMD_DUMP("I2C_IOCTL: InterlockedIncrement(&pDevContext->I2C_Lock) = %d", IoctlAndIsrSyncCounter);
        KeClearEvent(&pDevContext->IoctlAndIsrSyncEvent);
        pDevContext->I2C_pCurrentCmd = pI2C_Cmd;
        ntStatus = I2C_PrepareI2CRequest(pDevContext, *pI2C_Cmd);
    } else {
        DBG_IOCTL_CMD_DUMP("I2C_IOCTL: InterlockedIncrement(&pDevContext->I2C_Lock) = %d", IoctlAndIsrSyncCounter);
        ntStatus = STATUS_SUCCESS;
    }
    DBG_I2C_METHOD_END_WITH_STATUS(ntStatus);
    return ntStatus;
}

/*++
Routine Description:
    This method is to starts new I2C IO command sequence.
Arguments:
    pDevContext  - Pointer to the device context.
    I2C_Cmd      - Pointer to the first I2C IO command. 
Return Value:
    NTSTATUS
--*/
NTSTATUS I2C_RegsIo(DEV_CONTEXT *pDevContext, I2C_IO_CMD_t *pI2C_Cmd) {
    NTSTATUS  ntStatus;

    DBG_I2C_METHOD_BEG();
    pDevContext->I2C_pCurrentCmd = pI2C_Cmd;
    ntStatus = I2C_PrepareI2CRequest(pDevContext, *pI2C_Cmd);
    DBG_I2C_METHOD_END_WITH_STATUS(ntStatus);
    return ntStatus;
}
