/*
* This file is derived from Microsoft example available on https://github.com/microsoft/Windows-driver-samples/blob/master/usb/UcmTcpciCxClientSample
* Original file licensing:
* Copyright (c) 2015 Microsoft
* SPDX-License-Identifier: MS-PL
* NXP modifications are licensed under the same license
* Copyright 2020 NXP
*
*/

#include <ntddk.h>
#include <wdf.h>
#include <initguid.h>
#include <wdmguid.h>
#define RESHUB_USE_HELPER_ROUTINES
#include <reshub.h>
#include <spb.h>
#include <UcmTcpciCx.h>
#include <gpio.h>

#include "imx_tcpci_trace.h"
#include "imx_tcpci_phy_io_map.h"
#include "imx_tcpci_i2c.h"


/* Timeout in milliseconds for synchronous I2C reads/writes. */
/* The I2C specification does not specify a timeout. 300 ms was chosen arbitrarily. */
#define I2C_SYNCHRONOUS_TIMEOUT_MS 300

/* Max. count of alerts reported in one call of UcmTcpciPortControllerAlert(). */
#define ISR_MAX_ALERTS_TO_REPORT    12

/* Max. count of alerts handles in one call of ISR. */
#define ISR_MAX_ALERTS_TO_PROCESS   10

/* Max, size of I2C buffer for one I2C IO operation. */
#define TCPCI_I2C_DATA_BUFFER_SIZE  50

/* Upper layer drivers incorrectly sets RC.CCx bits if VCON is enabled during device connection. */
/* Comment out this macro to disable RC.CCx bug fix. */
#define BUG_FIX_RC_CC


typedef struct _DEV_CONTEXT {
    WDFDEVICE                         Device;                                       /* Device handle                                                           */
    UCMTCPCIPORTCONTROLLER            PortController;                               /* Port controller handle                                                  */
    WDFIOTARGET                       I2C_hTarget;                                  /* I2C target handle                                                       */
    LARGE_INTEGER                     I2C_ConnectionId;                             /* I2C connection ID                                                       */
    WDFIOTARGET                       GPIO_hTarget;                                 /* GCPIO target handle                                                     */
    LARGE_INTEGER                     GPIO_ConnectionId;                            /* GPIO connection ID                                                      */
    WDFREQUEST                        GPIO_hRequest;                                /* GPIO request handle                                                     */
    WDFMEMORY                         GPIO_hMemory;                                 /* GPIO data buffer memory handle                                          */
    UINT8                             GPIO_IO_Data;                                 /* GPIO I/O data buffer                                                    */
    TCPC_PHY_t                        TCPI_PhyRegs;                                 /* Local copy TCPCI registers                                              */
    KEVENT                            IoctlAndIsrSyncEvent;                         /* Event for IOCTL and ISR TCPCI register access synchronization           */
    volatile LONG                     IoctlAndIsrSyncCounter;                       /* Counter for IOCTL and ISR TCPCI register access synchronization         */
    WDFREQUEST                        IOCTL_hRequest;                               /* Handle of current IOCTL request                                         */
    unsigned int                      IOCTL_BufferSize;                             /* Counter of bytes already send/received by I2C for current IOCTL request */
    I2C_IO_CMD_t                      IOCTL_I2CCmds[4];                             /* I2C I/O command sequence for assynchronous IOCTL request                */
    WDF_REQUEST_SEND_OPTIONS          I2C_ReqSendOptions;                           /* Synchronnous I2C IO request options                                     */
    WDF_REQUEST_REUSE_PARAMS          I2C_WdfRequestReuseParams;                    /* I2C request reuse params                                                */
    WDFREQUEST                        I2C_hRequest;                                 /* I2C request handle                                                      */
    WDFMEMORY                         I2C_hRxMemory;                                /* I2C Rx memory handle                                                    */
    WDFMEMORY                         I2C_hTxMemory;                                /* I2C Tx memory handle                                                    */
    SPB_TRANSFER_LIST_AND_ENTRIES(2)  I2C_RxTrList;                                 /* I2C Rx transfer list                                                    */
    SPB_TRANSFER_LIST                 I2C_TxTrList;                                 /* I2C Tx transfer list                                                    */
    I2C_IO_CMD_t                     *I2C_pCurrentCmd;                              /* Pointer to the current I2C I/O command                                  */
    struct _I2C_BUFFER_t {                                                          
        I2C_IO_CMD_t                  I2C_Cmd;                                      /* Current I2C I/O command                                                 */
        UINT8                         I2C_IO_Data[TCPCI_I2C_DATA_BUFFER_SIZE - 2];  /* I2C I/O data buffer                                                     */
    } I2C_Buffer;
} DEV_CONTEXT, *PDEV_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEV_CONTEXT, DeviceGetContext)

EXTERN_C_START

DRIVER_INITIALIZE                  DriverEntry;
EVT_WDF_OBJECT_CONTEXT_CLEANUP     EvtDriverContextCleanup;                                  
EVT_WDF_DRIVER_DEVICE_ADD          EvtDeviceAdd;
EVT_WDF_DEVICE_PREPARE_HARDWARE    EvtPrepareHardware;
EVT_WDF_DEVICE_D0_ENTRY            EvtDeviceD0Entry;
EVT_WDF_DEVICE_RELEASE_HARDWARE    EvtReleaseHardware;
EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL EvtIoDeviceControl;
EVT_WDF_IO_QUEUE_IO_STOP           EvtIoStop;
EVT_WDF_INTERRUPT_ISR              OnInterruptPassiveIsr;

EXTERN_C_END