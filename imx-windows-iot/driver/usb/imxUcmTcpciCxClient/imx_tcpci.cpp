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
#include "imx_tcpci.tmh"
#endif

#ifdef ALLOC_PRAGMA
#pragma alloc_text (INIT, DriverEntry)
#pragma alloc_text (PAGE, EvtDriverContextCleanup)
#pragma alloc_text (PAGE, EvtDeviceAdd)
#pragma alloc_text (PAGE, EvtPrepareHardware)
#pragma alloc_text (PAGE, EvtDeviceD0Entry)
#pragma alloc_text (PAGE, EvtReleaseHardware)
#pragma alloc_text (PAGE, OnInterruptPassiveIsr)

#endif

/*++
Routine Description:
    DriverEntry initializes the driver and is the first routine called by the system after the driver is loaded. DriverEntry specifies the other entry
    points in the function driver, such as EvtDevice and DriverUnload.
Parameters Description:
    DriverObject - represents the instance of the function driver that is loaded into memory. DriverEntry must initialize members of DriverObject before it
                   returns to the caller. DriverObject is allocated by the system before the driver is loaded, and it is released by the system after the system unloads
                   the function driver from memory.
    RegistryPath - represents the driver specific path in the Registry. The function driver can use the path to store driver related data between
                   reboots. The path does not store hardware instance specific data.
Return Value:
    NTSTATUS
--*/
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT  pDriverObject, _In_ PUNICODE_STRING pRegistryPath) {
    NTSTATUS               ntStatus=STATUS_SUCCESS;
    WDF_DRIVER_CONFIG      Config;
    WDF_OBJECT_ATTRIBUTES  Attributes;

    WDF_OBJECT_ATTRIBUTES_INIT(&Attributes);
    /* Initialize WPP Tracing */
    WPP_INIT_TRACING(pDriverObject, pRegistryPath);
    DBG_DRV_METHOD_BEG_WITH_PARAMS("Driver: 0x%016p, '%S'", pDriverObject, ((PUNICODE_STRING)pRegistryPath)->Buffer);
    DBG_DRV_PRINT_VERBOSE("***********************************************************************************");
#ifdef __DATE__
    DBG_DRV_PRINT_VERBOSE("*** NXP USB TCPC driver, date: %s %s                             ***", __DATE__, __TIME__);
#else
    DBG_DRV_PRINT_VERBOSE("*** NXP USB TCPC driver                                          ***");
#endif
    DBG_DRV_PRINT_VERBOSE("***********************************************************************************");
    Attributes.EvtCleanupCallback = EvtDriverContextCleanup;
    WDF_DRIVER_CONFIG_INIT(&Config, EvtDeviceAdd);
    if (!NT_SUCCESS(ntStatus = WdfDriverCreate(pDriverObject, pRegistryPath, &Attributes, &Config, WDF_NO_HANDLE))) {
        DBG_PRINT_ERROR_WITH_STATUS(ntStatus,"WdfDriverCreate() failed.");
        WPP_CLEANUP(pDriverObject);
    }
    DBG_DRV_METHOD_END_WITH_STATUS(ntStatus);
    return ntStatus;
}

/*++
Routine Description:
    Free all the resources allocated in DriverEntry.
Arguments:
    DriverObject - handle to a WDF Driver object.
--*/
VOID EvtDriverContextCleanup(_In_ WDFOBJECT hDriverObject) {
    UNREFERENCED_PARAMETER(hDriverObject);
    _IRQL_limited_to_(PASSIVE_LEVEL);
    DBG_DRV_METHOD_BEG();
    PAGED_CODE();
    /* Stop WPP Tracing */
    DBG_DRV_METHOD_END();
    WPP_CLEANUP(WdfDriverWdmGetDriverObject((WDFDRIVER)hDriverObject));
}

/*++
Routine Description:
    It is called by the framework in response to AddDevice call from the PnP manager. We create and initialize a device object to represent a new instance of the device.
Arguments:
    Driver     - Handle to a framework driver object created in DriverEntry
    DeviceInit - Pointer to a framework-allocated WDFDEVICE_INIT structure.
Return Value:
    NTSTATUS
--*/
NTSTATUS EvtDeviceAdd(_In_ WDFDRIVER hDriver, _Inout_ PWDFDEVICE_INIT pDeviceInit) {
    NTSTATUS                     ntStatus;
    WDFDEVICE                    hDevice;
    PDEV_CONTEXT                 pDevContext;
    UCMTCPCI_DEVICE_CONFIG       Config;
    WDF_PNPPOWER_EVENT_CALLBACKS PnpPowerCallbacks;
    WDF_OBJECT_ATTRIBUTES        Attributes;
    
    DBG_DEV_METHOD_BEG();
    UNREFERENCED_PARAMETER(hDriver);
    PAGED_CODE();
    do {
        WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&Attributes, DEV_CONTEXT);
        WDF_PNPPOWER_EVENT_CALLBACKS_INIT(&PnpPowerCallbacks);
        PnpPowerCallbacks.EvtDevicePrepareHardware = EvtPrepareHardware;
        PnpPowerCallbacks.EvtDeviceReleaseHardware = EvtReleaseHardware;
        PnpPowerCallbacks.EvtDeviceD0Entry         = EvtDeviceD0Entry;
        WdfDeviceInitSetPnpPowerEventCallbacks(pDeviceInit, &PnpPowerCallbacks);
        if (!NT_SUCCESS(ntStatus = UcmTcpciDeviceInitInitialize(pDeviceInit))) {
            DBG_PRINT_ERROR_WITH_STATUS(ntStatus, "[PWDFDEVICE_INIT: 0x%p] UcmTcpciDeviceInitInitialize failed", pDeviceInit);
            break;
        }
        if (!NT_SUCCESS(ntStatus = WdfDeviceCreate(&pDeviceInit, &Attributes, &hDevice))) {
            DBG_PRINT_ERROR_WITH_STATUS(ntStatus, "[PWDFDEVICE_INIT: 0x%p] WdfDeviceCreate failed", pDeviceInit);
            break;
        }
        pDevContext = DeviceGetContext(hDevice);
        pDevContext->Device  = hDevice;                                                /* Save the device handle in the context. */        
        UCMTCPCI_DEVICE_CONFIG_INIT(&Config);
        if (!NT_SUCCESS(ntStatus = UcmTcpciDeviceInitialize(hDevice, &Config))) {      /* Register this device with UcmTcpciCx. */
            DBG_PRINT_ERROR_WITH_STATUS(ntStatus, "[WDFDEVICE: 0x%p] UcmTcpciDeviceInitialize failed", hDevice);
            break;
        }
    } while (0);
    DBG_DEV_METHOD_END_WITH_STATUS(ntStatus);
    return ntStatus;
}

/*++
Routine Description:
    A driver's EvtDevicePrepareHardware event callback function performs any operations that are needed to make a device accessible to the driver.
Arguments:
    hDevice             - Handle to a framework device object.
    ResourcesRaw        - Handle to a framework resource-list object that identifies the raw hardware resources that the Plug and Play manager has assigned to the device.
    ResourcesTranslated - Handle to a framework resource-list object that identifies the translated hardware resources that the Plug and Play manager has assigned to the device.
Return Value:
    NTSTATUS
--*/
NTSTATUS EvtPrepareHardware(_In_ WDFDEVICE hDevice, _In_ WDFCMRESLIST hResourcesRaw, _In_ WDFCMRESLIST hResourcesTranslated) {
    NTSTATUS     ntStatus;
    PDEV_CONTEXT pDevContext;

    DBG_DEV_METHOD_BEG();
    PAGED_CODE();
    pDevContext = DeviceGetContext(hDevice);
    KeInitializeEvent(&pDevContext->IoctlAndIsrSyncEvent, NotificationEvent, FALSE);
    do {
        if (!NT_SUCCESS(ntStatus = IO_Initialize(pDevContext, hResourcesRaw, hResourcesTranslated))) {  /* Initialize the I2C communication channel to read from/write to the hardware. */
            break;
        }
        if (!NT_SUCCESS(ntStatus = I2C_Open(pDevContext))) {
            break;
        }
        if (!NT_SUCCESS(ntStatus = GPIO_Open(pDevContext))) {
            break;
        }
    } while (0);
    DBG_DEV_METHOD_END_WITH_STATUS(ntStatus);
    return ntStatus;
}

/*++
Routine Description:
    This routine reads basic information from TCCI controller and starts TCPC stack.
Arguments:
    hDevice       - Handle to a framework device object.
    PreviousState - Previous state (not used).
Return Value:
    NTSTATUS
--*/
NTSTATUS EvtDeviceD0Entry(_In_ WDFDEVICE hDevice, _In_ WDF_POWER_DEVICE_STATE PreviousState) {
    NTSTATUS                                ntStatus;
    PDEV_CONTEXT                            pDevContext;
    UCMTCPCIPORTCONTROLLER                  hPortController = WDF_NO_HANDLE;
    WDFQUEUE                                hQueue;
    WDF_IO_QUEUE_CONFIG                     QueueConfig;
    UCMTCPCI_PORT_CONTROLLER_CONFIG         Config;
    UCMTCPCI_PORT_CONTROLLER_IDENTIFICATION Ident;
    UCMTCPCI_PORT_CONTROLLER_CAPABILITIES   Capabilities;
    TCPC_PHY_FAULT_STATUS_t                 FaultStatus;
    TCPC_PHY_ALERT_t                        Alert;
    I2C_IO_CMD_t                            I2C_Cmd;

    DBG_DEV_METHOD_BEG();
    UNREFERENCED_PARAMETER(PreviousState);
    PAGED_CODE();
    pDevContext = DeviceGetContext(hDevice);
    UCMTCPCI_PORT_CONTROLLER_IDENTIFICATION_INIT(&Ident);
    UCMTCPCI_PORT_CONTROLLER_CAPABILITIES_INIT(&Capabilities);
    I2C_IO_CMD_t  DevCapabilities_I2C_IO_Cmds[] = {
        {&Ident.ProductId,                           IMX_EvtDeviceD0Entry_DevCapabilities, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_PRODUCT_ID)},
        {&Ident.DeviceId,                            IMX_EvtDeviceD0Entry_DevCapabilities, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_DEVICE_ID)},
        {&Ident.TypeCRevisionInBcd,                  IMX_EvtDeviceD0Entry_DevCapabilities, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_USBTYPEC_REV)},
        {&Ident.PDRevisionAndVersionInBcd,           IMX_EvtDeviceD0Entry_DevCapabilities, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_USBPD_REV_VER)},
        {&Ident.PDInterfaceRevisionAndVersionInBcd,  IMX_EvtDeviceD0Entry_DevCapabilities, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_PD_INTERFACE_REV)},
        {&Capabilities.DeviceCapabilities1,          IMX_EvtDeviceD0Entry_DevCapabilities, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_DEV_CAP_1)},
        {&Capabilities.DeviceCapabilities2,          IMX_EvtDeviceD0Entry_DevCapabilities, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_DEV_CAP_2)},
        {&Capabilities.StandardInputCapabilities,    IMX_EvtDeviceD0Entry_DevCapabilities, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_STD_INPUT_CAP)},
        {&Capabilities.StandardOutputCapabilities,   IMX_EvtDeviceD0Entry_DevCapabilities, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_STD_OUTPUT_CAP) | I2C_IO_CMD_LAST_CMD}
    };       
    do {
        RdRegSync(TCPC_PHY_ALERT, &Alert, IMX_EvtDeviceD0Entry);
        if (Alert.B.FAULT) {
            RdRegSync(TCPC_PHY_FAULT_STATUS, &FaultStatus, IMX_EvtDeviceD0Entry);
            if (FaultStatus.B.ALL_REGISTERS_RESET_TO_DEFAULT) {
                /* After Power-on reset the FAULT_STATUS.ALL_REGISTERS_RESET_TO_DEFAULT is set */
                FaultStatus.R = TCPC_PHY_FAULT_STATUS_MASK_ALLREGISTERSRESETTODEFAULT_INT_MASK_MASK;
                WrRegSync(TCPC_PHY_FAULT_STATUS, FaultStatus.R, IMX_EvtDeviceD0Entry);   /* Clear Register reset to defulut bit */
                Alert.R = TCPC_PHY_ALERT_FAULT_MASK;
                WrRegSync(TCPC_PHY_ALERT, Alert.R, IMX_EvtDeviceD0Entry);                /* Clear fault bit */
            }
        }
        TCPC_PHY_ReadAllRegs(pDevContext,__FUNCTION__);
        if (!NT_SUCCESS(ntStatus = I2C_RegsIo(pDevContext, DevCapabilities_I2C_IO_Cmds))) {
            DBG_DEV_PRINT_ERROR_WITH_STATUS(ntStatus, "Get TCPC controller DevCapabilities() failed.");
        }
        Capabilities.IsPowerDeliveryCapable = TRUE;
        UCMTCPCI_PORT_CONTROLLER_CONFIG_INIT(&Config, &Ident, &Capabilities);
        /* Create a UCMTCPCIPORTCONTROLLER framework object. */
        if (!NT_SUCCESS(ntStatus = UcmTcpciPortControllerCreate(hDevice, &Config, WDF_NO_OBJECT_ATTRIBUTES, &hPortController))) {
            DBG_DEV_PRINT_ERROR_WITH_STATUS(ntStatus, "[WDFDEVICE: 0x%p] UcmTcpciPortControllerCreate failed.", hDevice);
            break;
        }
        pDevContext = DeviceGetContext(hDevice);                            /* Save the UCMTCPCIPORTCONTROLLER in our device context. */
        pDevContext->PortController = hPortController;  
        /* Set the hardware request queue for our device. A single I/O Queue is configured for sequential request processing, and a driver context memory allocation is created to hold our structure QUEUE_CONTEXT. */
        WDF_IO_QUEUE_CONFIG_INIT(&QueueConfig, WdfIoQueueDispatchSequential);
        QueueConfig.EvtIoDeviceControl = EvtIoDeviceControl;
        QueueConfig.EvtIoStop          = EvtIoStop;
        if (!NT_SUCCESS(ntStatus = WdfIoQueueCreate(hDevice, &QueueConfig, WDF_NO_OBJECT_ATTRIBUTES, &hQueue))) {  /* Create the hardware request queue. */
            DBG_DEV_PRINT_ERROR_WITH_STATUS(ntStatus, "WdfIoQueueCreate failed.");
            break;
        }
        UcmTcpciPortControllerSetHardwareRequestQueue(pDevContext->PortController, hQueue);                        /* Set this queue as the one to which UcmTcpciCx will forward its hardware requests. */
        /* Direct UcmTcpciCx to start the port controller. At this point, UcmTcpciCx will assume control of USB Type-C and Power Delivery. */
        /* After the port controller is started, UcmTcpciCx may start putting requests into the hardware request queue. */
        if (!NT_SUCCESS(ntStatus = UcmTcpciPortControllerStart(hPortController))) {
            DBG_DEV_PRINT_ERROR_WITH_STATUS(ntStatus, "[UCMTCPCIPORTCONTROLLER: 0x%p] UcmTcpciPortControllerStart failed.", hPortController);
            break;
        }
    } while (0);
    if (!NT_SUCCESS(ntStatus) && (hPortController != WDF_NO_HANDLE)) {
        WdfObjectDelete(hPortController);
        pDevContext->PortController = WDF_NO_HANDLE;
    }
    DBG_DEV_METHOD_END_WITH_STATUS(ntStatus);
    return ntStatus;
}

/*++
Routine Description:
    This event is invoked for a power-managed queue before the hDevice leaves the working state (D0).
Arguments:
    Queue       - Handle to the framework queue object that is associated with the I/O request.
    Request     - Handle to a framework request object.
    ActionFlags - A bitwise OR of one or more WDF_REQUEST_STOP_ACTION_FLAGS-typed flags that identify the reason that the callback function is being called and whether the request is cancelable.
--*/
VOID EvtIoStop(_In_ WDFQUEUE hQueue, _In_ WDFREQUEST hRequest, _In_ ULONG ActionFlags) {
    WDFDEVICE    hDevice;
    PDEV_CONTEXT pDevContext;

    DBG_IOCTL_METHOD_BEG();
    UNREFERENCED_PARAMETER(ActionFlags);
    UNREFERENCED_PARAMETER(hRequest);
    hDevice = WdfIoQueueGetDevice(hQueue);
    pDevContext = DeviceGetContext(hDevice);
    if (pDevContext->IOCTL_hRequest != WDF_NO_HANDLE) {          /* Try to cancel the I2C WDFREQUESTs. */
        DBG_PRINT_ERROR("[WDFREQUEST: 0x%p] Attempting to cancel.", pDevContext->IOCTL_hRequest);
        WdfRequestCancelSentRequest(pDevContext->IOCTL_hRequest);
    }
    DBG_IOCTL_METHOD_END();
}

/*++
Routine Description:
    A driver's EvtDeviceReleaseHardware event callback function performs operations that are needed when a device is no longer accessible.
Arguments:
    hDevice             - Handle to a framework device object.
    ResourcesTranslated - Handle to a resource list object that identifies the translated hardware resources that the Plug and Play manager has assigned to the device.
Return Value:
    NTSTATUS
--*/
NTSTATUS EvtReleaseHardware(_In_ WDFDEVICE hDevice, _In_ WDFCMRESLIST hResourcesTranslated) {
    NTSTATUS     ntStatus = STATUS_SUCCESS;
    PDEV_CONTEXT pDevContext;

    DBG_DEV_METHOD_BEG();
    UNREFERENCED_PARAMETER(hResourcesTranslated);
    PAGED_CODE();
    pDevContext = DeviceGetContext(hDevice);
    if (pDevContext->PortController != WDF_NO_HANDLE)  {        
        UcmTcpciPortControllerStop(pDevContext->PortController);   /* Direct UcmTcpciCx to stop the port controller and then delete the backing object. */
        WdfObjectDelete(pDevContext->PortController);
        pDevContext->PortController = WDF_NO_HANDLE;
    }    
    I2C_Close(pDevContext);                                         /* Close the I2C controller. */
    GPIO_Close(pDevContext);                                        /* Close the GPIO controller. */
    DBG_DEV_METHOD_END_WITH_STATUS(ntStatus);
    return ntStatus;
}

/*++
Routine Description:
    Per the TCPCI spec, the port controller hardware will drive the Alert pin high when a hardware event occurs. This routine services such a hardware interrupt at PASSIVE_LEVEL.
    The routine determines if an interrupt is an alert from the port controller hardware; if so, it completes processing of the alert.
Arguments:
    Interrupt: A handle to a framework interrupt object.
    MessageID: If the device is using message-signaled interrupts (MSIs), this parameter is the message number that identifies the device's hardware interrupt message. Otherwise, this value is 0.
Return Value:
    TRUE if the function services the hardware interrupt. Otherwise, this function must return FALSE.
--*/
BOOLEAN OnInterruptPassiveIsr(_In_ WDFINTERRUPT hPortControllerInterrupt, _In_ ULONG MessageID) {
    UNREFERENCED_PARAMETER(MessageID);
    PAGED_CODE();

    NTSTATUS                                ntStatus;
    PDEV_CONTEXT                            pDevContext;
    TCPC_PHY_ALERT_t                        AlertRegister;
    BOOLEAN                                 interruptRecognized = FALSE;
    int                                     NumAlertReports = 0;
    size_t                                  NumAlertsInReport;
    UCMTCPCI_PORT_CONTROLLER_ALERT_DATA     alertData;
    UCMTCPCI_PORT_CONTROLLER_RECEIVE_BUFFER receiveBuffer;
    UCMTCPCI_PORT_CONTROLLER_ALERT_DATA     hardwareAlerts[ISR_MAX_ALERTS_TO_REPORT];  /* UcmTcpciCx expects the information on all of the alerts firing presently. */
    I2C_IO_CMD_t                            I2C_Cmd;
    LONG                                    IoctlAndIsrSyncCounter;

    pDevContext = DeviceGetContext(WdfInterruptGetDevice(hPortControllerInterrupt));

    DBG_IOCTL_METHOD_BEG_WITH_PARAMS("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    /* Process the alerts as long as there are bits set in the alert register. Set a maximum number of alerts to process in this loop. If the hardware is messed up and we're unable */
    /* to quiesce the interrupt by writing to the alert register, then we don't want to be stuck in an infinite loop. */
    if ((IoctlAndIsrSyncCounter=InterlockedIncrement(&pDevContext->IoctlAndIsrSyncCounter)) != 1) {
        DBG_IOCTL_CMD_DUMP("ISR: InterlockedIncrement(&pDevContext->I2C_Lock) = %d, waiting for event", IoctlAndIsrSyncCounter);
        ntStatus = KeWaitForSingleObject(&pDevContext->IoctlAndIsrSyncEvent, Executive, KernelMode, FALSE, NULL);
        KeClearEvent(&pDevContext->IoctlAndIsrSyncEvent);
        DBG_IOCTL_CMD_DUMP("ISR: waiting for DEVICE LOCK done");
    } else {
        DBG_IOCTL_CMD_DUMP("ISR: InterlockedIncrement(&pDevContext->I2C_Lock) = 1");
    }
    while (NumAlertReports <= ISR_MAX_ALERTS_TO_PROCESS) {
        if (!NT_SUCCESS(ntStatus = RdRegSync(TCPC_PHY_ALERT, &AlertRegister, IMX_ISR))) break;
        if (AlertRegister.R == 0) {         /* If there are no bits set in the alert register, we should not service this interrupt. */
            break;
        }      
        interruptRecognized = TRUE;         /* Since there are bits set in the alert register, we can safely assume that the interrupt is ours to process. */
        NumAlertsInReport = 0;
        do {
            if (AlertRegister.B.CC_STATUS == 1) {
                DBG_IOCTL_PRINT_INFO("CCStatus == 1");
                UCMTCPCI_PORT_CONTROLLER_ALERT_DATA_INIT(&alertData);
                alertData.AlertType = UcmTcpciPortControllerAlertCCStatus;
                /* We must read the CC status register and send the contents to UcmTcpciCx along with the CC status alert. */
                if (!NT_SUCCESS(ntStatus = RdRegSync(TCPC_PHY_CC_STATUS, &alertData.CCStatus, IMX_ISR))) break;
                hardwareAlerts[NumAlertsInReport] = alertData;
                ++NumAlertsInReport;
            }
            if (AlertRegister.B.POWER_STATUS == 1) {
                DBG_IOCTL_PRINT_INFO("PowerStatus == 1");
                UCMTCPCI_PORT_CONTROLLER_ALERT_DATA_INIT(&alertData);
                alertData.AlertType = UcmTcpciPortControllerAlertPowerStatus;
                /* We must read the power status register and send the contents to UcmTcpciCx along with the power status alert. */
                if (!NT_SUCCESS(ntStatus = RdRegSync(TCPC_PHY_POWER_STATUS, &alertData.PowerStatus, IMX_ISR))) break;
                hardwareAlerts[NumAlertsInReport] = alertData;
                ++NumAlertsInReport;
            }
            if (AlertRegister.B.FAULT == 1) {
                DBG_IOCTL_PRINT_INFO("Fault == 1");
                UCMTCPCI_PORT_CONTROLLER_ALERT_DATA_INIT(&alertData);
                alertData.AlertType = UcmTcpciPortControllerAlertFault;
                /* We must read the fault status register and send the contents to UcmTcpciCx along with the fault alert. */
                if (!NT_SUCCESS(ntStatus = RdRegSync(TCPC_PHY_FAULT_STATUS, &alertData.FaultStatus, IMX_ISR))) break;
                hardwareAlerts[NumAlertsInReport] = alertData;
                ++NumAlertsInReport;
                /* Clear FAULT_STATUS Register. */
                /* Mask reserved bit 7 in TCPCI Rev 1.0 Ver 1.0 only, see spec section 4.4.6.3 */
                alertData.FaultStatus.AsUInt8 &= 0x7F;
                if (!NT_SUCCESS(ntStatus = WrRegSync(TCPC_PHY_FAULT_STATUS, alertData.FaultStatus.AsUInt8, IMX_ISR))) break;
            }
            if (AlertRegister.B.RECEIVED_SOP_MESSAGE_STATUS == 1) {
                DBG_IOCTL_PRINT_INFO("ReceiveSOPMessageStatus == 1");
                UCMTCPCI_PORT_CONTROLLER_ALERT_DATA_INIT(&alertData);
                alertData.AlertType = UcmTcpciPortControllerAlertReceiveSOPMessageStatus;
                /* We must read the receive buffer register and send the contents to UcmTcpciCx along with the receive SOP alert. */
                if (!NT_SUCCESS(ntStatus = RdBufSync(TCPC_PHY_RX_BUF_BYTE_X, &receiveBuffer, sizeof(receiveBuffer), IMX_ISR))) break;
                alertData.ReceiveBuffer = &receiveBuffer;
                hardwareAlerts[NumAlertsInReport] = alertData;
                ++NumAlertsInReport;
            }
            /* The remainder of the alert types do not require us to provide any extra information to UcmTcpciCx. */
            if (AlertRegister.B.RECEIVED_HARD_RESET == 1) {
                DBG_IOCTL_PRINT_INFO("ReceivedHardReset == 1");
                UCMTCPCI_PORT_CONTROLLER_ALERT_DATA_INIT(&alertData);
                alertData.AlertType = UcmTcpciPortControllerAlertReceivedHardReset;
                hardwareAlerts[NumAlertsInReport] = alertData;
                ++NumAlertsInReport;
            }
            if (AlertRegister.B.RX_BUFFER_OVERFLOW == 1) {
                DBG_IOCTL_PRINT_INFO("RxBufferOverflow == 1");
                UCMTCPCI_PORT_CONTROLLER_ALERT_DATA_INIT(&alertData);
                alertData.AlertType = UcmTcpciPortControllerAlertRxBufferOverflow;
                hardwareAlerts[NumAlertsInReport] = alertData;
                ++NumAlertsInReport;
            }
            if (AlertRegister.B.TRANSMIT_SOP_MESSAGE_DISCARDED == 1) {
                DBG_IOCTL_PRINT_INFO("TransmitSOPMessageDiscarded == 1");
                UCMTCPCI_PORT_CONTROLLER_ALERT_DATA_INIT(&alertData);
                alertData.AlertType = UcmTcpciPortControllerAlertTransmitSOPMessageDiscarded;
                hardwareAlerts[NumAlertsInReport] = alertData;
                ++NumAlertsInReport;
            }
            if (AlertRegister.B.TRANSMIT_SOP_MESSAGE_FAILED == 1) {
                DBG_IOCTL_PRINT_INFO("TransmitSOPMessageFailed == 1");
                UCMTCPCI_PORT_CONTROLLER_ALERT_DATA_INIT(&alertData);
                alertData.AlertType = UcmTcpciPortControllerAlertTransmitSOPMessageFailed;
                hardwareAlerts[NumAlertsInReport] = alertData;
                ++NumAlertsInReport;
            }
            if (AlertRegister.B.TRANSMIT_SOP_MESSAGE_SUCCESSFUL == 1) {
                DBG_IOCTL_PRINT_INFO("TransmitSOPMessageSuccessful == 1");
                UCMTCPCI_PORT_CONTROLLER_ALERT_DATA_INIT(&alertData);
                alertData.AlertType = UcmTcpciPortControllerAlertTransmitSOPMessageSuccessful;
                hardwareAlerts[NumAlertsInReport] = alertData;
                ++NumAlertsInReport;
            }
            if (AlertRegister.B.VBUS_SINK_DISCONNECT_DETECTED == 1) {
                DBG_IOCTL_PRINT_INFO("VbusSinkDisconnectDetected == 1");
                UCMTCPCI_PORT_CONTROLLER_ALERT_DATA_INIT(&alertData);
                alertData.AlertType = UcmTcpciPortControllerAlertVbusSinkDisconnectDetected;
                hardwareAlerts[NumAlertsInReport] = alertData;
                ++NumAlertsInReport;
            }
            if (AlertRegister.B.VBUS_VOLTAGE_ALARM_HI == 1) {
                DBG_IOCTL_PRINT_INFO("VbusVoltageAlarmHi == 1");
                UCMTCPCI_PORT_CONTROLLER_ALERT_DATA_INIT(&alertData);
                alertData.AlertType = UcmTcpciPortControllerAlertVbusVoltageAlarmHi;
                hardwareAlerts[NumAlertsInReport] = alertData;
                ++NumAlertsInReport;
            }
            if (AlertRegister.B.VBUS_VOLTAGE_ALARM_LO == 1) {
                DBG_IOCTL_PRINT_INFO("VbusVoltageAlarmLo == 1");
                UCMTCPCI_PORT_CONTROLLER_ALERT_DATA_INIT(&alertData);
                alertData.AlertType = UcmTcpciPortControllerAlertVbusVoltageAlarmLo;
                hardwareAlerts[NumAlertsInReport] = alertData;
                ++NumAlertsInReport;
            }
            if (AlertRegister.B.EXTENDED_STATUS == 1) {
                DBG_IOCTL_PRINT_INFO("ExtendedStatus == 1");
                if (!NT_SUCCESS(ntStatus = RdRegSync(TCPC_PHY_EXTENDED_STATUS, NULL, IMX_ISR))) break;
            }
            if (!NT_SUCCESS(ntStatus = WrRegSync(TCPC_PHY_ALERT, AlertRegister.R, IMX_ISR))) break;
        } while (0);
        if (NT_SUCCESS(ntStatus)) {  
            if (NumAlertsInReport) {
                DBG_IOCTL_PRINT_INFO("!!!!!!!!! ->> UcmTcpciPortControllerAlert +++ !!!!!!!!! ");
                UcmTcpciPortControllerAlert(pDevContext->PortController, hardwareAlerts, NumAlertsInReport);  
                DBG_IOCTL_PRINT_INFO("!!!!!!!!! <<- UcmTcpciPortControllerAlert --- !!!!!!!!! ");
            }
        } else {
            break;
        }
        ++NumAlertReports;
    }
    if ((IoctlAndIsrSyncCounter=InterlockedDecrement(&pDevContext->IoctlAndIsrSyncCounter)) != 0) {
        DBG_IOCTL_CMD_DUMP("ISR: InterlockedDecrement(&InterlockedDecrement->I2C_Lock) = %d", IoctlAndIsrSyncCounter);
        pDevContext->I2C_pCurrentCmd = pDevContext->IOCTL_I2CCmds;
        ntStatus = I2C_PrepareI2CRequest(pDevContext, *pDevContext->I2C_pCurrentCmd);
    } else {
        DBG_IOCTL_CMD_DUMP("ISR: InterlockedDecrement(&InterlockedDecrement->I2C_Lock) = %d", IoctlAndIsrSyncCounter);
    }
    DBG_IOCTL_METHOD_END_WITH_PARAMS("interruptRecognized = %d -----------------------------------", interruptRecognized);
    return interruptRecognized;
}

/*++
Routine Description:
    This event is invoked when the framework receives IRP_MJ_DEVICE_CONTROL request.
Arguments:
    hQueue             - Handle to the framework queue object that is associated with the I/O request.
    hRequest           - Handle to a framework request object.
    OutputBufferLength - Size of the output buffer in bytes
    InputBufferLength  - Size of the input buffer in bytes
    IoControlCode      - I/O control code.
--*/
VOID EvtIoDeviceControl(_In_ WDFQUEUE hQueue, _In_ WDFREQUEST hRequest, _In_ size_t OutputBufferLength, _In_ size_t InputBufferLength, _In_ ULONG IoControlCode) {
    DEV_CONTEXT    *pDevContext;
    NTSTATUS        ntStatus = STATUS_SUCCESS;
    VOID           *pBuffer;
    I2C_IO_CMD_t   *pI2CIOCmd;
    
    DBG_IOCTL_METHOD_BEG_WITH_PARAMS("%s", Dbg_GetIOCTLName(IoControlCode));
    UNREFERENCED_PARAMETER(InputBufferLength);
    UNREFERENCED_PARAMETER(OutputBufferLength);
    pDevContext = DeviceGetContext(WdfIoQueueGetDevice(hQueue));
    ASSERT(pDevContext->IOCTL_hRequest == WDF_NO_HANDLE);          /* Only one IOCTL request is allowed */
    pI2CIOCmd = pDevContext->IOCTL_I2CCmds;
    DBG_IOCTL_CMD_DUMP("+++ WDFREQUEST: 0x%p, Ioctl:%s", hRequest, Dbg_GetIOCTLName(IoControlCode));
    switch (IoControlCode) {
        case IOCTL_UCMTCPCI_PORT_CONTROLLER_GET_STATUS:
            if (NT_SUCCESS(ntStatus = WdfRequestRetrieveOutputBuffer(hRequest, sizeof(UCMTCPCI_PORT_CONTROLLER_GET_STATUS_OUT_PARAMS), &pBuffer, NULL))) {
                pI2CIOCmd[0] = {&((UCMTCPCI_PORT_CONTROLLER_GET_STATUS_OUT_PARAMS *)pBuffer)->CCStatus,    IMX_IOCTL_GET_STATUS, I2C_IO_CMD_RD_REG_IOCTL(TCPC_PHY_CC_STATUS)};
                pI2CIOCmd[1] = {&((UCMTCPCI_PORT_CONTROLLER_GET_STATUS_OUT_PARAMS *)pBuffer)->PowerStatus, IMX_IOCTL_GET_STATUS, I2C_IO_CMD_RD_REG_IOCTL(TCPC_PHY_POWER_STATUS)};
                pI2CIOCmd[2] = {&((UCMTCPCI_PORT_CONTROLLER_GET_STATUS_OUT_PARAMS *)pBuffer)->FaultStatus, IMX_IOCTL_GET_STATUS, I2C_IO_CMD_RD_REG_IOCTL(TCPC_PHY_FAULT_STATUS) | I2C_IO_CMD_LAST_CMD};
            }
            break;
        case IOCTL_UCMTCPCI_PORT_CONTROLLER_GET_CONTROL:
            if (NT_SUCCESS(ntStatus = WdfRequestRetrieveOutputBuffer(hRequest, sizeof(UCMTCPCI_PORT_CONTROLLER_GET_CONTROL_OUT_PARAMS), &pBuffer, NULL))) {
                pI2CIOCmd[0] =  {&((UCMTCPCI_PORT_CONTROLLER_GET_CONTROL_OUT_PARAMS *)pBuffer)->TCPCControl,  IMX_IOCTL_GET_CONTROL, I2C_IO_CMD_RD_REG_IOCTL(TCPC_PHY_TCPC_CONTROL)};
                pI2CIOCmd[1] =  {&((UCMTCPCI_PORT_CONTROLLER_GET_CONTROL_OUT_PARAMS *)pBuffer)->RoleControl,  IMX_IOCTL_GET_CONTROL, I2C_IO_CMD_RD_REG_IOCTL(TCPC_PHY_ROLE_CONTROL)};
                pI2CIOCmd[2] =  {&((UCMTCPCI_PORT_CONTROLLER_GET_CONTROL_OUT_PARAMS *)pBuffer)->FaultControl, IMX_IOCTL_GET_CONTROL, I2C_IO_CMD_RD_REG_IOCTL(TCPC_PHY_FAULT_CONTROL)};
                pI2CIOCmd[3] =  {&((UCMTCPCI_PORT_CONTROLLER_GET_CONTROL_OUT_PARAMS *)pBuffer)->PowerControl, IMX_IOCTL_GET_CONTROL, I2C_IO_CMD_RD_REG_IOCTL(TCPC_PHY_POWER_CONTROL) | I2C_IO_CMD_LAST_CMD};
            }
            break;
        case IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_CONTROL:
            if (NT_SUCCESS(ntStatus = WdfRequestRetrieveInputBuffer(hRequest, sizeof(UCMTCPCI_PORT_CONTROLLER_SET_CONTROL_IN_PARAMS), &pBuffer, NULL))) {
                switch (((UCMTCPCI_PORT_CONTROLLER_SET_CONTROL_IN_PARAMS *)pBuffer)->ControlType) {
                    case UcmTcpciPortControllerTcpcControl:    /* TCPC_CONTROL - First write */
                        if (pDevContext->GPIO_hTarget != WDF_NO_HANDLE) {
                             GPIO_PlugOrientation_Set(pDevContext, *(TCPC_PHY_TCPC_CONTROL_t *)(&((UCMTCPCI_PORT_CONTROLLER_SET_CONTROL_IN_PARAMS *)pBuffer)->TCPCControl));
                        }
                        pI2CIOCmd[0] = {NULL, IMX_IOCTL_SET_CONTROL, I2C_IO_CMD_WR_REG_IOCTL(TCPC_PHY_TCPC_CONTROL, ((UCMTCPCI_PORT_CONTROLLER_SET_CONTROL_IN_PARAMS *)pBuffer)->TCPCControl.AsUInt8) | I2C_IO_CMD_LAST_CMD};
                        break;
                    case UcmTcpciPortControllerRoleControl: {    /* ROLE_CONTROL - Second write */ 
#ifdef BUG_FIX_RC_CC 
                        TCPC_PHY_t *pPhyRegs = &pDevContext->TCPI_PhyRegs;
                        TCPC_PHY_ROLE_CONTROL_t                     RoleControl = *(TCPC_PHY_ROLE_CONTROL_t*)&((UCMTCPCI_PORT_CONTROLLER_SET_CONTROL_IN_PARAMS *)pBuffer)->RoleControl;
                        if (pPhyRegs->POWER_CONTROL.B.ENABLE_VCONN) {
                            if (pPhyRegs->TCPC_CONTROL.B.PLUG_ORIENTATION) { /* PC.VCON = 1 & TC.PlugOrient = 1 (VCON to CC1) */
                                if (RoleControl.B.CC1 != 0x03) {             /* PC.VCON = 1 & TC.PlugOrient = 1 &RC.CC1 != Open */
                                    RoleControl.B.CC1 = 0x03;                /* RC.CC1 = Open */
                                    DBG_PRINT_ERROR("ERROR BUG FIX!!! PC.VCON = 1 & TC.PlugOrient = CC1 & RC.CC1 != Open. Change RC.CC1 to Open(0x03)");
                                }   
                            } else {                                         /* PC.VCON = 1 & TC.PlugOrient = 0 (VCON to CC2) */
                                if (RoleControl.B.CC2 != 0x03) {             /* PC.VCON = 1 & TC.PlugOrient = 0 &RC.CC2 != Open */
                                    RoleControl.B.CC2 = 0x03;                /* RC.CC1 = Open */
                                    DBG_PRINT_ERROR("ERROR BUG FIX!!! PC.VCON = 1 & TC.PlugOrient = CC2 & RC.CC2 != Open. Change RC.CC2 to Open(0x03)");
                                }   
                            }
                        }
                        pI2CIOCmd[0] = {NULL, IMX_IOCTL_SET_CONTROL, I2C_IO_CMD_WR_REG_IOCTL(TCPC_PHY_ROLE_CONTROL, RoleControl.R) | I2C_IO_CMD_LAST_CMD};
#else
                        pI2CIOCmd[0] = {NULL, IMX_IOCTL_SET_CONTROL, I2C_IO_CMD_WR_REG_IOCTL(TCPC_PHY_ROLE_CONTROL, ((UCMTCPCI_PORT_CONTROLLER_SET_CONTROL_IN_PARAMS *)pBuffer)->RoleControl.AsUInt8) | I2C_IO_CMD_LAST_CMD};
#endif
                        break;
                    }
                    case UcmTcpciPortControllerPowerControl: { /* POWER_CONTROL - Third write */
#ifdef BUG_FIX_RC_CC 
                        int i = 0;
                        TCPC_PHY_t *pPhyRegs = &pDevContext->TCPI_PhyRegs;
                        if (((UCMTCPCI_PORT_CONTROLLER_SET_CONTROL_IN_PARAMS *)pBuffer)->PowerControl.EnableVconn) {
                            if (pPhyRegs->TCPC_CONTROL.B.PLUG_ORIENTATION) { /* PC.VCON = 1 & TC.PlugOrient = 1 (VCON to CC1) */
                                if (pPhyRegs->ROLE_CONTROL.B.CC1 != 0x03) {  /* PC.VCON = 1 & TC.PlugOrient = 1 &RC.CC1 != Open */
                                    pPhyRegs->ROLE_CONTROL.B.CC1 = 0x03;     /* RC.CC1 = Open */
                                    DBG_PRINT_ERROR("ERROR BUG FIX!!! PC.VCON = 1 & TC.PlugOrient = CC1 & RC.CC1 != Open. Before writing to PC change RC.CC1 to Open(0x03)");
                                    pI2CIOCmd[0] = {NULL,  IMX_IOCTL_SET_CONTROL, I2C_IO_CMD_WR_REG_IOCTL(TCPC_PHY_ROLE_CONTROL, pPhyRegs->ROLE_CONTROL.R)};
                                        i++;
                                }   
                            } else {                                         /* PC.VCON = 1 & TC.PlugOrient = 0 (VCON to CC2) */
                                if (pPhyRegs->ROLE_CONTROL.B.CC2 != 0x03) {  /* PC.VCON = 1 & TC.PlugOrient = 0 &RC.CC2 != Open */
                                    pPhyRegs->ROLE_CONTROL.B.CC2 = 0x03;     /* RC.CC1 = Open */
                                    DBG_PRINT_ERROR("ERROR BUG FIX!!! PC.VCON = 1 & TC.PlugOrient = CC2 & RC.CC2 != Open. Before writing to PC change RC.CC2 to Open(0x03)");
                                    pI2CIOCmd[0] = {NULL,  IMX_IOCTL_SET_CONTROL, I2C_IO_CMD_WR_REG_IOCTL(TCPC_PHY_ROLE_CONTROL, pPhyRegs->ROLE_CONTROL.R)};
                                        i++;
                                }   
                            }
                        }
                        pI2CIOCmd[i] = {NULL, IMX_IOCTL_SET_CONTROL, I2C_IO_CMD_WR_REG_IOCTL(TCPC_PHY_POWER_CONTROL, ((UCMTCPCI_PORT_CONTROLLER_SET_CONTROL_IN_PARAMS *)pBuffer)->PowerControl.AsUInt8) | I2C_IO_CMD_LAST_CMD};
#else
                        pI2CIOCmd[0] = {NULL, IMX_IOCTL_SET_CONTROL, I2C_IO_CMD_WR_REG_IOCTL(TCPC_PHY_POWER_CONTROL, ((UCMTCPCI_PORT_CONTROLLER_SET_CONTROL_IN_PARAMS *)pBuffer)->PowerControl.AsUInt8) | I2C_IO_CMD_LAST_CMD};
#endif
                        break;
                    }
                    case UcmTcpciPortControllerFaultControl:
                        pI2CIOCmd[0] = {NULL, IMX_IOCTL_SET_CONTROL, I2C_IO_CMD_WR_REG_IOCTL(TCPC_PHY_FAULT_CONTROL, ((UCMTCPCI_PORT_CONTROLLER_SET_CONTROL_IN_PARAMS *)pBuffer)->FaultControl.AsUInt8) | I2C_IO_CMD_LAST_CMD};
                        break;
                    default:
                        DBG_IOCTL_PRINT_ERROR("Invalid control register type.");
                        ntStatus = STATUS_INVALID_DEVICE_REQUEST;
                }
            }
            break;
        case IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT:
            if (NT_SUCCESS(ntStatus = WdfRequestRetrieveInputBuffer(hRequest, sizeof(UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_IN_PARAMS), &pBuffer, NULL)))
                pI2CIOCmd[0] = {NULL, IMX_IOCTL_SET_TRANSMIT, I2C_IO_CMD_WR_REG_IOCTL(TCPC_PHY_TRANSMIT, ((UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_IN_PARAMS *)pBuffer)->Transmit.AsUInt8) | I2C_IO_CMD_LAST_CMD};
            break;
        case IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_BUFFER:
            if (NT_SUCCESS(ntStatus = WdfRequestRetrieveInputBuffer(hRequest, sizeof(UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_BUFFER_IN_PARAMS), &pBuffer, NULL))) 
                if ((((UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_BUFFER_IN_PARAMS *)pBuffer)->TransmitBuffer.TransmitByteCount + sizeof(((UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_BUFFER_IN_PARAMS *)pBuffer)->TransmitBuffer.TransmitByteCount)) > TCPCI_I2C_DATA_BUFFER_SIZE) {
                    ntStatus = STATUS_INVALID_BUFFER_SIZE;
                } else {
                    pI2CIOCmd[0] = {&((UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_BUFFER_IN_PARAMS *)pBuffer)->TransmitBuffer, IMX_IOCTL_SET_TRANSMIT_BUFFER, I2C_IO_CMD_WR_BUF_IOCTL(TCPC_PHY_TX_BUF_BYTE_X, ((UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_BUFFER_IN_PARAMS *)pBuffer)->TransmitBuffer.TransmitByteCount + sizeof(((UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_BUFFER_IN_PARAMS *)pBuffer)->TransmitBuffer.TransmitByteCount)) | I2C_IO_CMD_LAST_CMD};
                }
            break;
        case IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_RECEIVE_DETECT:
            if (NT_SUCCESS(ntStatus = WdfRequestRetrieveInputBuffer(hRequest, sizeof(UCMTCPCI_PORT_CONTROLLER_SET_RECEIVE_DETECT_IN_PARAMS), &pBuffer, NULL)))
                pI2CIOCmd[0] = {NULL, IMX_IOCTL_SET_RECEIVE_DETECT, I2C_IO_CMD_WR_REG_IOCTL(TCPC_PHY_RECEIVE_DETECT, ((UCMTCPCI_PORT_CONTROLLER_SET_RECEIVE_DETECT_IN_PARAMS *)pBuffer)->ReceiveDetect.AsUInt8) | I2C_IO_CMD_LAST_CMD};
            break;
        case IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_CONFIG_STANDARD_OUTPUT:
            if (NT_SUCCESS(ntStatus = WdfRequestRetrieveInputBuffer(hRequest, sizeof(UCMTCPCI_PORT_CONTROLLER_SET_CONFIG_STANDARD_OUTPUT_IN_PARAMS), &pBuffer, NULL)))
                pI2CIOCmd[0] = {NULL, IMX_IOCTL_SET_CONFIG_STANDARD_OUTPUT, I2C_IO_CMD_WR_REG_IOCTL(TCPC_PHY_CONFIG_STANDARD_OUTPUT, ((UCMTCPCI_PORT_CONTROLLER_SET_CONFIG_STANDARD_OUTPUT_IN_PARAMS *)pBuffer)->ConfigStandardOutput.AsUInt8) | I2C_IO_CMD_LAST_CMD};
            break;
        case IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_COMMAND:
            if (NT_SUCCESS(ntStatus = WdfRequestRetrieveInputBuffer(hRequest, sizeof(UCMTCPCI_PORT_CONTROLLER_SET_COMMAND_IN_PARAMS), &pBuffer, NULL)))
                pI2CIOCmd[0] = {NULL, IMX_IOCTL_SET_COMMAND, I2C_IO_CMD_WR_REG_IOCTL(TCPC_PHY_COMMAND, ((UCMTCPCI_PORT_CONTROLLER_SET_COMMAND_IN_PARAMS *)pBuffer)->Command) | I2C_IO_CMD_LAST_CMD};
            break;
        case IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_MESSAGE_HEADER_INFO:
            if (NT_SUCCESS(ntStatus = WdfRequestRetrieveInputBuffer(hRequest, sizeof(UCMTCPCI_PORT_CONTROLLER_SET_MESSAGE_HEADER_INFO_IN_PARAMS), &pBuffer, NULL)))
                pI2CIOCmd[0] = {NULL, IMX_IOCTL_SET_MESSAGE_HEADER_INFO,  I2C_IO_CMD_WR_REG_IOCTL(TCPC_PHY_MESSAGE_HEADER_INFO, ((UCMTCPCI_PORT_CONTROLLER_SET_MESSAGE_HEADER_INFO_IN_PARAMS *)pBuffer)->MessageHeaderInfo.AsUInt8) | I2C_IO_CMD_LAST_CMD};
            break;
        default:
            DBG_IOCTL_PRINT_ERROR("Received unexpected IoControlCode 0x%08X, %s", IoControlCode, Dbg_GetIOCTLName(IoControlCode));
            ntStatus = STATUS_NOT_SUPPORTED;
    }
    if (NT_SUCCESS(ntStatus)) {
        pDevContext->IOCTL_hRequest   = hRequest;
        pDevContext->IOCTL_BufferSize = 0;
        I2C_IOCTL(pDevContext, pDevContext->IOCTL_I2CCmds);
    } else {
        DBG_IOCTL_CMD_DUMP("--- WDFREQUEST: 0x%p, Ioctl:%s, ntStatus: 0x%08X", hRequest, Dbg_GetIOCTLName(IoControlCode), ntStatus);
        WdfRequestComplete(hRequest, ntStatus);
    }
    DBG_IOCTL_METHOD_END_WITH_PARAMS("%s", Dbg_GetIOCTLName(IoControlCode));
}