/*++
Copyright (c) Microsoft Corporation. All rights reserved.
Copyright 2020 NXP

Module Name:
    imxthermalclient.cpp

Abstract:
    The module implements a imx8M thermal client.
--*/

//-------------------------------------------------------------------- Includes
#pragma hdrstop

#include "imxthermalclient.hpp"
#include "imxthermalclienthw.h"

#include <acpiioct.h>
#include "acpiutil.hpp"

#include "trace.h"
#include "imxthermalclient.tmh"

//------------------------------------------------------------------ Prototypes

DRIVER_INITIALIZE DriverEntry;

EVT_WDF_DRIVER_DEVICE_ADD           TcDriverDeviceAdd;
EVT_WDF_OBJECT_CONTEXT_CLEANUP      EvtDriverContextCleanup;
EVT_WDF_DEVICE_PREPARE_HARDWARE     TcPrepareHardware;
EVT_WDF_DEVICE_RELEASE_HARDWARE     TcReleaseHardware;

DEVICE_ACTIVE_COOLING               TcEngageActiveCooling;
DEVICE_PASSIVE_COOLING              TcEngagePassiveCooling;

NTSTATUS TcGetMcuFrequency(WDFDEVICE WdfDevice, PULONG Frequency);
NTSTATUS TcSetMcuFrequency(WDFDEVICE WdfDevice, PULONG Frequency);

//------------------------------------------------------------------- Functions

IMXTC_INIT_SEGMENT_BEGIN;
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
NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{

    WDF_OBJECT_ATTRIBUTES DriverAttributes;
    WDF_DRIVER_CONFIG DriverConfig;
    NTSTATUS Status;

    // Initialize logging
    WPP_INIT_TRACING(DriverObject, RegistryPath);
    RECORDER_CONFIGURE_PARAMS recorderConfigureParams;
    RECORDER_CONFIGURE_PARAMS_INIT(&recorderConfigureParams);
    WppRecorderConfigure(&recorderConfigureParams);
#if DBG
    WPP_RECORDER_LEVEL_FILTER(IMXTC_TRACING_DEFAULT) = TRUE;
#endif // DBG

    WDF_DRIVER_CONFIG_INIT(&DriverConfig, TcDriverDeviceAdd);

    // Initialize attributes and a context area for the driver object.
    WDF_OBJECT_ATTRIBUTES_INIT(&DriverAttributes);
    DriverAttributes.SynchronizationScope = WdfSynchronizationScopeNone;
    DriverAttributes.EvtCleanupCallback = EvtDriverContextCleanup;

    // Create the driver object
    Status = WdfDriverCreate(DriverObject,
                             RegistryPath,
                             &DriverAttributes,
                             &DriverConfig,
                             WDF_NO_HANDLE);

    if (!NT_SUCCESS(Status)) {
        IMXTC_LOG_ERROR("WdfDriverCreate() Failed. Status 0x%x", Status);
        WPP_CLEANUP(WdfDriverWdmGetDriverObject((WDFDRIVER)DriverObject));
        goto DriverEntryEnd;
    }

DriverEntryEnd:
    IMXTC_LOG_TRACE("Exit (status = %!STATUS!)", Status);
    return Status;
}

IMXTC_INIT_SEGMENT_END;

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

IMXTC_PAGED_SEGMENT_BEGIN;
/*++
Routine Description:
    EvtDriverDeviceAdd is called by the framework in response to AddDevice
    call from the PnP manager.
Arguments:
    Driver - Supplies a handle to the WDF Driver object.
    DeviceInit - Supplies a pointer to a framework-allocated WDFDEVICE_INIT
        structure.
Return Value:
    NTSTATUS
--*/
NTSTATUS TcDriverDeviceAdd(WDFDRIVER Driver, PWDFDEVICE_INIT DeviceInit)
{

    PFDO_DATA DevExt;
    WDF_OBJECT_ATTRIBUTES DeviceAttributes;
    WDFDEVICE DeviceHandle;
    WDF_QUERY_INTERFACE_CONFIG QueryInterfaceConfig;
    WDF_PNPPOWER_EVENT_CALLBACKS PnpPowerCallbacks;
    NTSTATUS Status;
    THERMAL_DEVICE_INTERFACE ThermalDeviceInterface;

    UNREFERENCED_PARAMETER(Driver);

    IMXTC_LOG_TRACE("Enter");
    PAGED_CODE();

    // Initialize attributes and a context area for the device object.
    WDF_OBJECT_ATTRIBUTES_INIT(&DeviceAttributes);
    WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE(&DeviceAttributes, FDO_DATA);

    // Initailize power callbacks
    WDF_PNPPOWER_EVENT_CALLBACKS_INIT(&PnpPowerCallbacks);
    PnpPowerCallbacks.EvtDevicePrepareHardware = TcPrepareHardware;
    PnpPowerCallbacks.EvtDeviceReleaseHardware = TcReleaseHardware;

    WdfDeviceInitSetPnpPowerEventCallbacks(DeviceInit, &PnpPowerCallbacks);

    // Create a framework device object.  This call will in turn create
    // a WDM device object, attach to the lower stack, and set the
    // appropriate flags and attributes.
    Status = WdfDeviceCreate(&DeviceInit, &DeviceAttributes, &DeviceHandle);
    if (!NT_SUCCESS(Status)) {
        IMXTC_LOG_ERROR("WdfDeviceCreate() Failed. 0x%x", Status);
        goto DriverDeviceAddEnd;
    }

    // Create a driver interface for this device to advertise the thermal
    // cooling interface.
    RtlZeroMemory(&ThermalDeviceInterface, sizeof(ThermalDeviceInterface));

    ThermalDeviceInterface.Size =
        sizeof(ThermalDeviceInterface);

    ThermalDeviceInterface.Version = 1;

    ThermalDeviceInterface.Context = DeviceHandle;
    ThermalDeviceInterface.InterfaceReference =
        WdfDeviceInterfaceReferenceNoOp;

    ThermalDeviceInterface.InterfaceDereference =
        WdfDeviceInterfaceDereferenceNoOp;

    ThermalDeviceInterface.Flags = ThermalDeviceFlagPassiveCooling;

    ThermalDeviceInterface.ActiveCooling = NULL;
    ThermalDeviceInterface.PassiveCooling = TcEngagePassiveCooling;

    WDF_QUERY_INTERFACE_CONFIG_INIT(&QueryInterfaceConfig,
                                    (PINTERFACE) &ThermalDeviceInterface,
                                    &GUID_THERMAL_COOLING_INTERFACE,
                                    NULL);

    Status = WdfDeviceAddQueryInterface(DeviceHandle, &QueryInterfaceConfig);
    if (!NT_SUCCESS(Status)) {
        IMXTC_LOG_ERROR("WdfDeviceAddQueryInterface() Failed. 0x%x", Status);
        goto DriverDeviceAddEnd;
    }

    Status = WdfDeviceCreateDeviceInterface(DeviceHandle,
                                            &GUID_DEVINTERFACE_THERMAL_COOLING,
                                            NULL);

    if (!NT_SUCCESS(Status)) {
        IMXTC_LOG_ERROR("WdfDeviceCreateDeviceInterface() Failed. 0x%x", Status);
        goto DriverDeviceAddEnd;
    }

    // Finish initializing the device context area.
    DevExt = GetDeviceExtension(DeviceHandle);
    DevExt->ThermalLevel = 100UL;

    // Initialize PLL configuration structures
    DevExt->PllType = TC_UNKNOWN_PLL_TYPE;
    DevExt->PllFeature.PllMaxFrequencyHz = 0;
    DevExt->PllFeature.PllMinFrequencyHz = 0;
    DevExt->PllFeature.PllReferenceFrequencyHz = 0;
    DevExt->McuOppTableRecords = 0;

DriverDeviceAddEnd:
    IMXTC_LOG_TRACE("Exit (status = %!STATUS!)", Status);
    return Status;
}
IMXTC_PAGED_SEGMENT_END;

IMXTC_PAGED_SEGMENT_BEGIN;
/*++
Routine Description:
    TcEngagePassiveCooling is called by the device's clients to set the
    device's passive cooling state.
Arguments:
    Context - Supplies a handle to the target device.
    Percentage - Supplies the new thermal level in percent.
Return Value:
    None
--*/
VOID TcEngagePassiveCooling(_Inout_opt_ PVOID Context, _In_ ULONG Percentage)
{
    PFDO_DATA DevExt;
    ULONG PreviousThermalLevel, Frequency;
    NTSTATUS Status;

    IMXTC_LOG_TRACE("Enter");
    PAGED_CODE();

    _Analysis_assume_(Context != NULL);
    NT_ASSERT(Context != NULL);
    DevExt = GetDeviceExtension((WDFDEVICE)Context);

    PreviousThermalLevel = DevExt->ThermalLevel;
    DevExt->ThermalLevel = Percentage;

    IMXTC_LOG_TRACE("Thermal level was %lu, now %lu.",
                    PreviousThermalLevel,
                    Percentage);
    Frequency = ((DevExt->McuBootFrequencyHz / 100) * Percentage);
    Status = TcSetMcuFrequency((WDFDEVICE)Context, &Frequency);

    IMXTC_LOG_TRACE("Exit (status = %!STATUS!)", Status);
}
IMXTC_PAGED_SEGMENT_END;

IMXTC_PAGED_SEGMENT_BEGIN;
NTSTATUS TcGetMcuFrequency(WDFDEVICE WdfDevice, PULONG Frequency)
{
    PAGED_CODE();
    PFDO_DATA DevExt = NULL;
    volatile IMX8MQ_CCM_ANALOG_REGISTERS *CcmRegistersPtr;
    UINT32 val_cfg0, val_cfg1, val_frac_pllout;
    UINT64 refclk_div, out_div, frac_div, int_div, pllout_div;

    IMXTC_LOG_TRACE("Enter");

    DevExt = GetDeviceExtension(WdfDevice);
    NT_ASSERT(DevExt != NULL);

    CcmRegistersPtr = (volatile IMX8MQ_CCM_ANALOG_REGISTERS *)DevExt->RegistersPtr;

    val_cfg0 = CcmRegistersPtr->ARM_PLL_CFG0;
    val_cfg1 = CcmRegistersPtr->ARM_PLL_CFG1;
    val_frac_pllout = CcmRegistersPtr->FRAC_PLLOUT_DIV_CFG;

    if (val_cfg0 & IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_BYPASS_MASK) {
        *Frequency = DevExt->PllFeature.PllReferenceFrequencyHz;
    } else {
        refclk_div = ((val_cfg0 & IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_DIV_VAL_MASK) >>
            IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_DIV_VAL_SHIFT) + 1;
        out_div = ((val_cfg0 & IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_OUTPUT_DIV_VAL_MASK) >>
            IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_OUTPUT_DIV_VAL_SHIFT) + 1;
        frac_div = ((val_cfg1 & IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_FRAC_DIV_CTL_MASK) >>
            IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_FRAC_DIV_CTL_SHIFT);
        int_div = ((val_cfg1 & IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_INT_DIV_CTL_MASK) >>
            IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_INT_DIV_CTL_SHIFT) + 1;
        pllout_div = ((val_frac_pllout & CCM_ANALOG_FRAC_PLLOUT_DIV_CFG_ARM_PLL_DIV_VAL_MASK) >>
            CCM_ANALOG_FRAC_PLLOUT_DIV_CFG_ARM_PLL_DIV_VAL_SHIFT) + 1;

        *Frequency = static_cast<ULONG>((((DevExt->PllFeature.PllReferenceFrequencyHz * 8ULL) /
            refclk_div) * ((int_div * 0x1000000ULL) + frac_div) /
            (out_div * 2)) / (pllout_div * 0x1000000ULL));
    }
    IMXTC_LOG_TRACE("Cortex-Ax is running on %lu kHz", *Frequency/1000);
    IMXTC_LOG_TRACE("Exit (status = %!STATUS!)", STATUS_SUCCESS);
    return STATUS_SUCCESS;
}
IMXTC_PAGED_SEGMENT_END;

IMXTC_PAGED_SEGMENT_BEGIN;
NTSTATUS TcSetImx8MqArmFracFrequency(WDFDEVICE WdfDevice, PULONG Frequency)
{
    PAGED_CODE();
    PFDO_DATA   DevExt = NULL;

    volatile IMX8MQ_CCM_ANALOG_REGISTERS *CcmRegistersPtr;
    ULONG       CalcPllFrequency, CalcPllOutDiv;
    UINT32      RefClk, IntDiv;
    UINT64      FracDiv;
    NTSTATUS    Status = STATUS_DEVICE_CONFIGURATION_ERROR;

    IMXTC_LOG_TRACE("Enter");
    DevExt = GetDeviceExtension(WdfDevice);
    NT_ASSERT(DevExt != NULL);

    CcmRegistersPtr = (volatile IMX8MQ_CCM_ANALOG_REGISTERS *)DevExt->RegistersPtr;

    if (*Frequency <= DevExt->PllFeature.PllReferenceFrequencyHz) {
        // Bypass ARM_PLL = Cortex-Ax cores run on PllRefClk value
        CcmRegistersPtr->ARM_PLL_CFG0 |= IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_BYPASS_MASK;
        *Frequency = DevExt->PllFeature.PllReferenceFrequencyHz;
        IMXTC_LOG_INFORMATION("Cortex-Ax clock: %lu;", *Frequency);
        Status = STATUS_SUCCESS;
    }
    else {
        for (CalcPllOutDiv = 1; CalcPllOutDiv < 33; CalcPllOutDiv++) {
            CalcPllFrequency = *Frequency * CalcPllOutDiv;
            // Check if ARM_PLL clock output s in allowed range
            if ((CalcPllFrequency >= DevExt->PllFeature.PllMinFrequencyHz) &&
                (CalcPllFrequency <= DevExt->PllFeature.PllMaxFrequencyHz)) {
                RefClk = (DevExt->PllFeature.PllReferenceFrequencyHz /
                    (((CcmRegistersPtr->ARM_PLL_CFG0 & IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_DIV_VAL_MASK) >>
                        IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_DIV_VAL_SHIFT) + 1)) * 8;
                CalcPllFrequency *= 2;
                IntDiv = CalcPllFrequency / RefClk;
                FracDiv = (UINT64)(CalcPllFrequency - IntDiv * RefClk) * (1UL << 24);
                FracDiv /= RefClk;

                IMXTC_LOG_INFORMATION("Cortex-Ax clock: %lu; PLL: %lu; PLL_DIV %lu; IntDiv %lu; FracDiv %llu",
                                *Frequency, CalcPllFrequency / 2, CalcPllOutDiv, IntDiv - 1, FracDiv);
                CcmRegistersPtr->ARM_PLL_CFG1 = (CcmRegistersPtr->ARM_PLL_CFG1 &
                    ~(IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_FRAC_DIV_CTL_MASK |
                        IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_INT_DIV_CTL_MASK)) |
                        (IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_FRAC_DIV_CTL((UINT32)FracDiv) |
                            IMX8MQ_CCM_ANALOG_ARM_PLL_CFG1_PLL_INT_DIV_CTL(IntDiv - 1));
                // Configure ARM_PLL out divider
                CcmRegistersPtr->ARM_PLL_CFG0 = (CcmRegistersPtr->ARM_PLL_CFG0 &
                    ~(IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_OUTPUT_DIV_VAL_MASK)) |
                    IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_OUTPUT_DIV_VAL(CalcPllOutDiv - 1);
                // Reload FracDivCtl & IntDivClt values
                CcmRegistersPtr->ARM_PLL_CFG0 |= IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_NEWDIV_VAL_MASK;
                // Wait for PLL ACK for new configuration
                LARGE_INTEGER waitTillTimeStamp, currentTimeStamp;
                KeQueryTickCount(&waitTillTimeStamp);
                waitTillTimeStamp.QuadPart += ((2UL * KeQueryTimeIncrement()) / 10000UL); // Wait 2ms max.
                do {
                    if ((CcmRegistersPtr->ARM_PLL_CFG0 & IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_NEWDIV_ACK_MASK) != 0U) {
                        Status = STATUS_SUCCESS;
                        break;
                    }
                    KeQueryTickCount(&currentTimeStamp);
                    if (currentTimeStamp.QuadPart >= waitTillTimeStamp.QuadPart) {
                        break;
                    }
                } while (1);
                CcmRegistersPtr->ARM_PLL_CFG0 &= ~(IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_NEWDIV_VAL_MASK);
                if (Status == STATUS_SUCCESS) {
                    // Disable ARM_PLL bypass
                    CcmRegistersPtr->ARM_PLL_CFG0 &= ~(IMX8MQ_CCM_ANALOG_ARM_PLL_CFG0_PLL_OUTPUT_DIV_VAL_MASK);
                }
                break;
            }
        }
    }
    IMXTC_LOG_TRACE("Exit (status = %!STATUS!)", Status);
    return Status;
}
IMXTC_PAGED_SEGMENT_END;

IMXTC_PAGED_SEGMENT_BEGIN;
NTSTATUS TcSetMcuVoltage(WDFDEVICE WdfDevice, ULONG Voltage)
{
    PAGED_CODE();
    PFDO_DATA DevExt = NULL;
    NTSTATUS  Status = STATUS_SUCCESS;

    IMXTC_LOG_TRACE("Enter");
    DevExt = GetDeviceExtension(WdfDevice);
    NT_ASSERT(DevExt != NULL);

    if (DevExt->GpioPin.hGPIOIoTarget != WDF_NO_HANDLE) {
        IMXTC_LOG_INFORMATION("Set Cortex-Ax core voltage: %d uV", Voltage);
        if (Voltage >= 1000000UL) {
            DevExt->GpioPin.GPIOIoctlData = 0x00;
        }
        else {
            DevExt->GpioPin.GPIOIoctlData = 0x01;
        }
        do {
            IMXTC_LOG_INFORMATION("GPIO pin, value = %d", DevExt->GpioPin.GPIOIoctlData);
            if (!NT_SUCCESS(Status = WdfIoTargetFormatRequestForIoctl(
                DevExt->GpioPin.hGPIOIoTarget,
                DevExt->GpioPin.hGPIOIoctlRequest,
                IOCTL_GPIO_WRITE_PINS,
                DevExt->GpioPin.hGPIOWdfMemory,
                0,
                DevExt->GpioPin.hGPIOWdfMemory, 0))) {
                IMXTC_LOG_ERROR("GPIO - WdfIoTargetFormatRequestForIoctl() failed - STATUS = 0x%08X", Status);
                break;
            }
            // Send the request to the GPIO Target.
            if (WdfRequestSend(DevExt->GpioPin.hGPIOIoctlRequest, DevExt->GpioPin.hGPIOIoTarget,
                &DevExt->GpioPin.GPIOWfdReqSendOptions) == FALSE) {
                Status = WdfRequestGetStatus(DevExt->GpioPin.hGPIOIoctlRequest);
                IMXTC_LOG_ERROR("[WDFREQUEST: 0x%p] WdfRequestSend for GPIO write failed with ntStatus 0x%08X",
                                DevExt->GpioPin.hGPIOIoctlRequest, Status);
                break;
            }
        } while (0);
    }

    IMXTC_LOG_TRACE("Exit (status = %!STATUS!)", Status);
    return Status;
}

IMXTC_PAGED_SEGMENT_BEGIN;
NTSTATUS TcSetMcuFrequency(WDFDEVICE WdfDevice, PULONG Frequency)
{
    PAGED_CODE();
    PFDO_DATA   DevExt = NULL;
    NTSTATUS    Status = STATUS_DEVICE_CONFIGURATION_ERROR;

    IMXTC_LOG_TRACE("Enter");
    DevExt = GetDeviceExtension(WdfDevice);
    NT_ASSERT(DevExt != NULL);

    if (DevExt->PllType == TC_IMX8MQ_FRAC_PLL) {
        Status = TcSetImx8MqArmFracFrequency(WdfDevice, Frequency);
    }

    if ((Status == STATUS_SUCCESS) && (DevExt->McuOppTableRecords > 0)) {
        do {
            // Configure cores power supply
            UINT32 OppIndex;
            ULONG  Voltage_uV = DevExt->McuOppTable[0].CorePower_uV;
            for (OppIndex = 0; OppIndex < DevExt->McuOppTableRecords; OppIndex++) {
                if (*Frequency > DevExt->McuOppTable[OppIndex].CoreFrequencyHz) {
                    Voltage_uV = DevExt->McuOppTable[OppIndex].CorePower_uV;
                }
            }
            Status = TcSetMcuVoltage(WdfDevice, Voltage_uV);
        } while (0);
    }
    IMXTC_LOG_TRACE("Exit (status = %!STATUS!)", Status);
    return Status;
}
IMXTC_PAGED_SEGMENT_END;

NTSTATUS TcPrepareHardware(WDFDEVICE WdfDevice, WDFCMRESLIST FxResourcesRaw, WDFCMRESLIST FxResourcesTranslated)
{
    UNREFERENCED_PARAMETER(FxResourcesRaw);
    PAGED_CODE();

    ULONG resourceCount = 0;
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor;
    NTSTATUS status = STATUS_SUCCESS;
    PFDO_DATA DevExt = NULL;
    ULONG numMemResourcesFound = 0;
    ULONG numGpioResourcesFound = 0;
    DECLARE_UNICODE_STRING_SIZE(usDevicePath, RESOURCE_HUB_PATH_CHARS);
    WDF_IO_TARGET_OPEN_PARAMS       OpenParams;
    WDF_OBJECT_ATTRIBUTES           Attributes;
    ULONG                           Index;

    DevExt = GetDeviceExtension(WdfDevice);
    NT_ASSERT(DevExt != NULL);

    resourceCount = WdfCmResourceListGetCount(FxResourcesTranslated);

    for (ULONG i = 0; i < resourceCount; i++) {
        Descriptor = WdfCmResourceListGetDescriptor(FxResourcesTranslated, i);
        switch (Descriptor->Type) {
        case CmResourceTypeMemory:
            ++numMemResourcesFound;
            if (numMemResourcesFound > 1) {
                IMXTC_LOG_ERROR("Unexpected additional memory resource!");
                return STATUS_DEVICE_CONFIGURATION_ERROR;
            }
            // Save the physical address
            DevExt->RegistersPhysicalAddress = Descriptor->u.Memory.Start;
            DevExt->RegistersPhysicalSize = Descriptor->u.Memory.Length;
            break;

        case CmResourceTypeConnection:
            if ((Descriptor->u.Connection.Class == CM_RESOURCE_CONNECTION_CLASS_FUNCTION_CONFIG) &&
                (Descriptor->u.Connection.Type == CM_RESOURCE_CONNECTION_TYPE_FUNCTION_CONFIG)) {
                // Ignore FunctionConfig resources
                continue;
            }

            if ((Descriptor->u.Connection.Class == CM_RESOURCE_CONNECTION_CLASS_GPIO) &&
                (Descriptor->u.Connection.Type == CM_RESOURCE_CONNECTION_TYPE_GPIO_IO)) {

                DevExt->GpioPin.GpioConnectionId.LowPart = Descriptor->u.Connection.IdLowPart;
                DevExt->GpioPin.GpioConnectionId.HighPart = Descriptor->u.Connection.IdHighPart;
                ++numGpioResourcesFound;
            }
            break;
        default:
            // unknown resource will result in an error condition.
            break;
        }
    } // end FOR loop for resources

    // Make sure we got everything we need...
    if (numMemResourcesFound != 1) {
        IMXTC_LOG_ERROR("Invalid or no memory resource!");
        return STATUS_DEVICE_CONFIGURATION_ERROR;
    }

    const ACPI_METHOD_ARGUMENT UNALIGNED* devicePropertiesPkgLvl0Ptr;
    const ACPI_METHOD_ARGUMENT UNALIGNED* devicePropertiesPkgLvl1Ptr;
    const ACPI_METHOD_ARGUMENT UNALIGNED* devicePropertiesPkgLvl2Ptr;
    DEVICE_OBJECT* pdoPtr = WdfDeviceWdmGetPhysicalDevice(WdfDevice);
    NT_ASSERT(pdoPtr != NULL);
    ACPI_EVAL_OUTPUT_BUFFER *dsdBufferPtr = NULL;
    do {
        status = AcpiQueryDsd(pdoPtr, &dsdBufferPtr);
        if (!NT_SUCCESS(status)) {
            IMXTC_LOG_ERROR("AcpiQueryDsd() failed with error %u", status);
            break;
        }

        status = AcpiParseDsdAsDeviceProperties(dsdBufferPtr, &devicePropertiesPkgLvl0Ptr);
        if (!NT_SUCCESS(status)) {
            IMXTC_LOG_ERROR("AcpiParseDsdAsDeviceProperties() failed with error %u", status);
            break;
        }
        status = AcpiParseDsdAsDeviceProperties(dsdBufferPtr, &devicePropertiesPkgLvl1Ptr);
        if (!NT_SUCCESS(status)) {
            IMXTC_LOG_ERROR("AcpiParseDsdAsDeviceProperties() failed with error  %u", status);
            break;
        }

        if ((status == STATUS_SUCCESS) && (devicePropertiesPkgLvl1Ptr->Type == ACPI_METHOD_ARGUMENT_PACKAGE)) {
            const ACPI_METHOD_ARGUMENT UNALIGNED* currentPairEntryPtr = nullptr;
            CHAR pllTypeNameA[64];
            UINT32 length = 0;

            status = AcpiDevicePropertiesQueryValue(devicePropertiesPkgLvl1Ptr, "ArmPll", &currentPairEntryPtr);
            if (NT_SUCCESS(status)) {
                // Get PLL type
                status = AcpiDevicePropertiesQueryValue(currentPairEntryPtr, "PllType", &devicePropertiesPkgLvl2Ptr);
                if (!(NT_SUCCESS(status))) {
                    IMXTC_LOG_ERROR("Get PllType feature from ACPI failed, status %u", status);
                    break;
                }
                status = AcpiDevicePropertiesQueryStringValue(currentPairEntryPtr,
                                                "PllType",
                                                ARRAYSIZE(pllTypeNameA),
                                                &length,
                                                pllTypeNameA);
                if (!(NT_SUCCESS(status))) {
                    IMXTC_LOG_ERROR("Get PllType feature from ACPI failed, status %u", status);
                    break;
                }
                ANSI_STRING currentKeyNameStr, keyNameStr;
                status = RtlInitAnsiStringEx(&keyNameStr, pllTypeNameA);
                if (!NT_SUCCESS(status)) {
                    break;
                }
                for (Index = 0; Index < (sizeof(TC_PLL_NAMES) / sizeof(CHAR*)); Index++) {
                    status = RtlInitAnsiStringEx(&currentKeyNameStr, TC_PLL_NAMES[Index]);
                    if (!NT_SUCCESS(status)) {
                        break;
                    }
                    if (RtlEqualString(&currentKeyNameStr, &keyNameStr, FALSE)) {
                        DevExt->PllType = (TC_PLL_TYPE)Index;
                        break;
                    }
                }

                // Get PLL reference frequency value from Acpi
                status = AcpiDevicePropertiesQueryIntegerValue(currentPairEntryPtr,
                    "PllRefClock_hz",
                    &DevExt->PllFeature.PllReferenceFrequencyHz);
                if (!(NT_SUCCESS(status))) {
                    IMXTC_LOG_ERROR("Get PllReferenceFrequencyHz feature from ACPI failed, status %u", status);
                    break;
                }
                IMXTC_LOG_TRACE("Value of PllReferenceFrequencyHz feature from ACPI: %u",
                    DevExt->PllFeature.PllReferenceFrequencyHz);

                // Get minimal PLL frequency value from Acpi
                status = AcpiDevicePropertiesQueryIntegerValue(currentPairEntryPtr,
                    "PllFreqMin_hz",
                    &DevExt->PllFeature.PllMinFrequencyHz);
                if (!(NT_SUCCESS(status))) {
                    IMXTC_LOG_ERROR("Get PllFreqMin_hz feature from ACPI failed, status %u", status);
                    break;
                }
                IMXTC_LOG_TRACE("Value of PllFreqMin_hz feature from ACPI: %u",
                    DevExt->PllFeature.PllMinFrequencyHz);

                // Get maximal PLL frequency value from Acpi
                status = AcpiDevicePropertiesQueryIntegerValue(currentPairEntryPtr,
                    "PllFreqMax_hz",
                    &DevExt->PllFeature.PllMaxFrequencyHz);
                if (!(NT_SUCCESS(status))) {
                    IMXTC_LOG_ERROR("Get PllFreqMax_hz feature from ACPI failed, status %u", status);
                    break;
                }
                IMXTC_LOG_TRACE("Value of PllFreqMax_hz feature from ACPI: %u",
                    DevExt->PllFeature.PllMaxFrequencyHz);
            }
            else {
                IMXTC_LOG_ERROR("Get ArmPll features from ACPI failed, status %u", status);
                break;
            }

            // Get Opp table from Acpi
            status = AcpiDevicePropertiesQueryValue(devicePropertiesPkgLvl1Ptr, "CoreOppTable", &currentPairEntryPtr);
            if (NT_SUCCESS(status)) {
                const ACPI_METHOD_ARGUMENT UNALIGNED* OppTablePropertiesPkgPtr = NULL;
                for (Index = 0; Index < TC_MCU_OPP_TABLE_MAX_RECORDS; Index++) {
                    status = AcpiDevicePropertiesQueryIntegerValueArray(currentPairEntryPtr,
                        (UINT32 *)&DevExt->McuOppTable[Index],
                        2,
                        &OppTablePropertiesPkgPtr);
                    if (!NT_SUCCESS(status)) {
                        break;
                    }
                }
                DevExt->McuOppTableRecords = Index;
                status = STATUS_SUCCESS;
            }
        }
    } while (0);
    if (dsdBufferPtr != NULL) {
        ExFreePoolWithTag(dsdBufferPtr, ACPI_TAG_EVAL_OUTPUT_BUFFER);
    }

    // Check parameters
    if (status == STATUS_SUCCESS) {
        if (DevExt->PllType == TC_UNKNOWN_PLL_TYPE) {
            IMXTC_LOG_ERROR("Unknown PLL type detected, add please PllType information to ACPI.");
            status = STATUS_DEVICE_CONFIGURATION_ERROR;
        }
        if (DevExt->PllFeature.PllMaxFrequencyHz == 0) {
            IMXTC_LOG_ERROR("PllMaxFrequencyHz is not initialized, add please PllMaxFrequencyHz information to ACPI.");
            status = STATUS_DEVICE_CONFIGURATION_ERROR;
        }
        if (DevExt->PllFeature.PllReferenceFrequencyHz == 0) {
            IMXTC_LOG_ERROR("PllReferenceFrequencyHz is not initialized, add please PllReferenceFrequencyHz information to ACPI.");
            status = STATUS_DEVICE_CONFIGURATION_ERROR;
        }
    }

    // Open GPIO
    if ((status == STATUS_SUCCESS) && (numGpioResourcesFound > 0)) {
        do {
            if (!NT_SUCCESS(status = WdfIoTargetCreate(
                                        WdfDevice, 
                                        WDF_NO_OBJECT_ATTRIBUTES, 
                                        &DevExt->GpioPin.hGPIOIoTarget))) {
                IMXTC_LOG_ERROR("GPIO - WdfIoTargetCreate() failed - STATUS = 0x%08X", status);
                break;
            }
            // Open a handle to the controller
            RESOURCE_HUB_CREATE_PATH_FROM_ID(&usDevicePath, 
                DevExt->GpioPin.GpioConnectionId.LowPart, 
                DevExt->GpioPin.GpioConnectionId.HighPart);
            WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME(&OpenParams, &usDevicePath, FILE_GENERIC_WRITE);
            OpenParams.ShareAccess = FILE_SHARE_WRITE;
            if (!NT_SUCCESS(status = WdfIoTargetOpen(DevExt->GpioPin.hGPIOIoTarget, &OpenParams))) {
                IMXTC_LOG_ERROR("GPIO - WdfIoTargetOpen() failed - STATUS = 0x%08X", status);
                break;
            }
            WDF_OBJECT_ATTRIBUTES_INIT(&Attributes);
            Attributes.ParentObject = DevExt->GpioPin.hGPIOIoTarget;
            if (!NT_SUCCESS(status = WdfRequestCreate(
                                        &Attributes, 
                                        DevExt->GpioPin.hGPIOIoTarget, 
                                        &DevExt->GpioPin.hGPIOIoctlRequest))) {
                IMXTC_LOG_ERROR("GPIO - WdfRequestCreate() failed - STATUS = 0x%08X", status);
                break;
            }
            WDF_OBJECT_ATTRIBUTES_INIT(&Attributes);
            Attributes.ParentObject = DevExt->GpioPin.hGPIOIoctlRequest;
            if (!NT_SUCCESS(status = WdfMemoryCreatePreallocated(
                                        &Attributes, 
                                        &DevExt->GpioPin.GPIOIoctlData, 
                                        sizeof(DevExt->GpioPin.GPIOIoctlData), 
                                        &DevExt->GpioPin.hGPIOWdfMemory))) {
                IMXTC_LOG_ERROR("GPIO - WdfMemoryCreatePreallocated() failed - STATUS = 0x%08X", status);
                break;
            }
            WDF_REQUEST_SEND_OPTIONS_INIT(&DevExt->GpioPin.GPIOWfdReqSendOptions, WDF_REQUEST_SEND_OPTION_SYNCHRONOUS);
            WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT(&DevExt->GpioPin.GPIOWfdReqSendOptions, WDF_REL_TIMEOUT_IN_MS(10));
        } while (0);
    }

    if (status == STATUS_SUCCESS) {
        // Get IO space mapping
        DevExt->RegistersPtr = (VOID *)MmMapIoSpaceEx(DevExt->RegistersPhysicalAddress,
            DevExt->RegistersPhysicalSize, PAGE_NOCACHE | PAGE_READWRITE);
        if (DevExt->RegistersPtr != NULL) {
            // Get Cortex-Ax boot frequency
            status = TcGetMcuFrequency(WdfDevice, &DevExt->McuBootFrequencyHz);
        }
        else {
            status = STATUS_INSUFFICIENT_RESOURCES;
        }
    }
    return status;
}

NTSTATUS TcReleaseHardware(WDFDEVICE WdfDevice, WDFCMRESLIST ResourcesTranslated)
{
    PAGED_CODE();
    PFDO_DATA DevExt = GetDeviceExtension(WdfDevice);

    NT_ASSERT(DevExt != NULL);

    UNREFERENCED_PARAMETER(ResourcesTranslated);

    // Unmap CCM_ANALOG registers
    if (DevExt->RegistersPtr != nullptr) {
        MmUnmapIoSpace(PVOID(DevExt->RegistersPtr),
            ROUND_TO_PAGES(DevExt->RegistersPhysicalSize)
        );
        DevExt->RegistersPtr = nullptr;
    }
    // Close GPIO
    if (DevExt->GpioPin.hGPIOIoTarget != WDF_NO_HANDLE) {
        WdfIoTargetClose(DevExt->GpioPin.hGPIOIoTarget);
    }
    return STATUS_SUCCESS;
}