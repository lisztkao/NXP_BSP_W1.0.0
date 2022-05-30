/*
* Copyright 2020 NXP
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
* 
* * Redistributions of source code must retain the above copyright notice, this list
*   of conditions and the following disclaimer.
* 
* * Redistributions in binary form must reproduce the above copyright notice, this
*   list of conditions and the following disclaimer in the documentation and/or
*   other materials provided with the distribution.
* 
* * Neither the name of the copyright holder nor the names of its
*   contributors may be used to endorse or promote products derived from this
*   software without specific prior written permission.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
*/


#ifndef trace_H_
#define trace_H_

#pragma once

// TCPCI_TRACE_OFF          - no no debug messages are added to the driver binary.
// TCPCI_TRACE_WPP          - WPP is used to log debug messages.
//      How to start:         !wmitrace.start USB_Type_C
//                            !wmitrace.enable USB_Type_C {1EF2B8BC-ACB0-4EB5-BB72-2735C0C96C1D} -level 0xff -flag 0xFFFF
//                            !wmitrace.logdump USB_Type_C
//                              if -kd is specified as a last parametr in the !wmitrace.start command messages are printed to the "windbg command" window and !wmitrace.logdump is not needed. Note: This option inserts time delays and can cause TCPC/PD protocol timeouts.
//                              See flags definition in "imx_tcpci_trace.h" for messages filtering. To see only TCPI registers access set -flag 0x01
// TCPCI_TRACE_DBG_PRINT_EX - Messages are printed to the "windbg command" window. Note: This option inserts time delays and can cause TCPC/PC protocol timeouts.
//                              Uncomment #define(s) in the second part of "imx_tcpci_trace.h" to print reqested messages.

#define TCPCI_TRACE_OFF             0
#define TCPCI_TRACE_WPP             1
#define TCPCI_TRACE_DBG_PRINT_EX    2

// Uncomment one of the next define to enable debug message printing. If both of them are commented out, no debug messages are added to the driver binary.
//#define TCPCI_TRACE                 TCPCI_TRACE_WPP
//#define TCPCI_TRACE                 TCPCI_TRACE_DBG_PRINT_EX

#ifndef TCPCI_TRACE
#define TCPCI_TRACE                 1
#endif

#define IMX_IOCTL_GET_STATUS                               0x00
#define IMX_IOCTL_GET_CONTROL                              0x01
#define IMX_IOCTL_SET_CONTROL                              0x02
#define IMX_IOCTL_SET_TRANSMIT                             0x03
#define IMX_IOCTL_SET_TRANSMIT_BUFFER                      0x04
#define IMX_IOCTL_SET_RECEIVE_DETECT                       0x05
#define IMX_IOCTL_SET_CONFIG_STANDARD_OUTPUT               0x06
#define IMX_IOCTL_SET_COMMAND                              0x07
#define IMX_IOCTL_SET_MESSAGE_HEADER_INFO                  0x08
#define IMX_IOCTL_ALTERNATE_MODE_ENTERED                   0x09
#define IMX_IOCTL_ALTERNATE_MODE_EXITED                    0x0A
#define IMX_IOCTL_DISPLAYPORT_CONFIGURED                   0x0B
#define IMX_IOCTL_DISPLAYPORT_HPD_STATUS_CHANGED           0x0C
#define IMX_IOCTL_DISPLAYPORT_DISPLAY_OUT_STATUS_CHANGED   0x0D

#define IMX_EvtDeviceD0Entry                               0x0E
#define IMX_EvtDeviceD0Entry_DevCapabilities               0x0F
#define IMX_EvtDeviceD0Entry_ReadAllRegs                   0x10
#define IMX_ISR                                            0x11


#if (TCPCI_TRACE == TCPCI_TRACE_WPP)


#define I2C_READ  0
#define I2C_WRITE 1

typedef struct _DEV_CONTEXT DEV_CONTEXT, *PDEV_CONTEXT;
typedef struct TCPC_PHY_struct_t TCPC_PHY_t;

EXTERN_C_START
void        TCPC_PHY_DumpReg(const char *CallerName, TCPC_PHY_t *pRegs, UINT32 RegAddress, UINT32 params, ULONG Length);
void        TCPC_PHY_ReadAllRegs(PDEV_CONTEXT pDevContext, char *Caller);
const char* Dbg_GetIOCTLName(ULONG i);
const char* Dbg_GetI2CIOSrcName(ULONG i);
const char* Dbg_GetIOCTLShortName(ULONG i);
EXTERN_C_END

// Tracing GUID - 1EF2B8BC-ACB0-4EB5-BB72-2735C0C96C1D
#define WPP_CONTROL_GUIDS                                                          \
    WPP_DEFINE_CONTROL_GUID(                                                       \
        UcmTcpciCxClientSampleTraceGuid, (1EF2B8BC,ACB0,4EB5,BB72,2735C0C96C1D),   \
        WPP_DEFINE_BIT(TRACE_ERROR)                       /* bit 0 = 0x00000001 */ \
        WPP_DEFINE_BIT(TRACE_CONFIG)                      /* bit 1 = 0x00000002 */ \
        WPP_DEFINE_BIT(TRACE_TCPCI_REG)                   /* bit 2 = 0x00000004 */ \
        WPP_DEFINE_BIT(TRACE_TCPCI_MSG)                   /* bit 3 = 0x00000008 */ \
        WPP_DEFINE_BIT(TRACE_IOCTL_CMD)                   /* bit 4 = 0x00000010 */ \
        WPP_DEFINE_BIT(TRACE_DRIVER)                      /* bit 5 = 0x00000020 */ \
        WPP_DEFINE_BIT(TRACE_DEVICE)                      /* bit 6 = 0x00000040 */ \
        WPP_DEFINE_BIT(TRACE_IOCTL)                       /* bit 7 = 0x00000080 */ \
        WPP_DEFINE_BIT(TRACE_I2C)                         /* bit 8 = 0x00000100 */ \
    )

#define WPP_LEVEL_FLAGS_LOGGER(lvl, flags)             WPP_LEVEL_LOGGER (flags)
#define WPP_LEVEL_FLAGS_ENABLED(lvl, flags)           (WPP_LEVEL_ENABLED(flags) && WPP_CONTROL(WPP_BIT_ ## flags).Level >= lvl)

#define WPP_LEVEL_FLAGS_EXP_LOGGER(lvl, flags, EXP)    WPP_LEVEL_LOGGER (flags)
#define WPP_LEVEL_FLAGS_EXP_ENABLED(lvl, flags, EXP)  (WPP_LEVEL_ENABLED(flags) && WPP_CONTROL(WPP_BIT_ ## flags).Level >= lvl)

// begin_wpp config
//
// FUNC DBG_PRINT_ERROR{LEVEL=TRACE_LEVEL_ERROR, FLAGS=TRACE_ERROR}(MSG, ...);
// FUNC DBG_PRINT_ERROR_WITH_STATUS{LEVEL=TRACE_LEVEL_ERROR, FLAGS=TRACE_ERROR}(EXP, MSG, ...);
//
// FUNC DBG_CONFIG_DUMP{LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_CONFIG}(MSG, ...);
//
// FUNC DBG_TCPCI_REG_DUMP{LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_TCPCI_REG}(MSG, ...);
//
// FUNC DBG_TCPCI_MSG_DUMP{LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_TCPCI_MSG}(MSG, ...);
//
// FUNC DBG_IOCTL_CMD_DUMP{LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_IOCTL_CMD}(MSG, ...);
//
// USEPREFIX(DBG_DRV_METHOD_BEG,              "%!STDPREFIX!+++%!FUNC!(");
// USEPREFIX(DBG_DRV_METHOD_BEG_WITH_PARAMS,  "%!STDPREFIX!+++%!FUNC!(");
// USEPREFIX(DBG_DRV_METHOD_END,              "%!STDPREFIX!---%!FUNC!(");
// USEPREFIX(DBG_DRV_METHOD_END_WITH_PARAMS,  "%!STDPREFIX!---%!FUNC!(");
// USEPREFIX(DBG_DRV_METHOD_END_WITH_STATUS,  "%!STDPREFIX!---%!FUNC!(");
// USEPREFIX(DBG_DRV_PRINT_ERROR,             "%!STDPREFIX!!!!%!FUNC!");
// USEPREFIX(DBG_DRV_PRINT_ERROR_WITH_STATUS, "%!STDPREFIX!!!!%!FUNC!");
// USEPREFIX(DBG_DRV_PRINT_WARNING,           "%!STDPREFIX!   %!FUNC!");
// USEPREFIX(DBG_DRV_PRINT_INFO,              "%!STDPREFIX!   %!FUNC!");
// USEPREFIX(DBG_DRV_PRINT_VERBOSE,           "%!STDPREFIX!   %!FUNC!");
// USESUFFIX(DBG_DRV_METHOD_BEG,              ")");
// USESUFFIX(DBG_DRV_METHOD_BEG_WITH_PARAMS,  ")");
// USESUFFIX(DBG_DRV_METHOD_END,              ")");
// USESUFFIX(DBG_DRV_METHOD_END_WITH_PARAMS,  ")");
// USESUFFIX(DBG_DRV_METHOD_END_WITH_STATUS,  ") [%!STATUS!]", EXP);
// USESUFFIX(DBG_DRV_PRINT_ERROR_WITH_STATUS, " [%!STATUS!] !!!", EXP);
// FUNC      DBG_DRV_METHOD_BEG{              LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_DRIVER}(...);
// FUNC      DBG_DRV_METHOD_BEG_WITH_PARAMS{  LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_DRIVER}(MSG, ...);
// FUNC      DBG_DRV_METHOD_END{              LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_DRIVER}(...);
// FUNC      DBG_DRV_METHOD_END_WITH_PARAMS{  LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_DRIVER}(MSG, ...);
// FUNC      DBG_DRV_METHOD_END_WITH_STATUS{  LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_DRIVER}(EXP);
// FUNC      DBG_DRV_PRINT_ERROR{             LEVEL=TRACE_LEVEL_ERROR,       FLAGS=TRACE_DRIVER}(MSG, ...);
// FUNC      DBG_DRV_PRINT_ERROR_WITH_STATUS{ LEVEL=TRACE_LEVEL_ERROR,       FLAGS=TRACE_DRIVER}(EXP, MSG, ...);
// FUNC      DBG_DRV_PRINT_WARNING{           LEVEL=TRACE_LEVEL_WARNING,     FLAGS=TRACE_DRIVER}(MSG, ...);
// FUNC      DBG_DRV_PRINT_INFO{              LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_DRIVER}(MSG, ...);
// FUNC      DBG_DRV_PRINT_VERBOSE{           LEVEL=TRACE_LEVEL_VERBOSE,     FLAGS=TRACE_DRIVER}(MSG, ...);
//
// USEPREFIX(DBG_DEV_METHOD_BEG,              "%!STDPREFIX!+++%!FUNC!(");
// USEPREFIX(DBG_DEV_METHOD_BEG_WITH_PARAMS,  "%!STDPREFIX!+++%!FUNC!(");
// USEPREFIX(DBG_DEV_METHOD_END,              "%!STDPREFIX!---%!FUNC!(");
// USEPREFIX(DBG_DEV_METHOD_END_WITH_PARAMS,  "%!STDPREFIX!---%!FUNC!(");
// USEPREFIX(DBG_DEV_METHOD_END_WITH_STATUS,  "%!STDPREFIX!---%!FUNC!(");
// USEPREFIX(DBG_DEV_PRINT_ERROR,             "%!STDPREFIX!!!!%!FUNC!");
// USEPREFIX(DBG_DEV_PRINT_ERROR_WITH_STATUS, "%!STDPREFIX!!!!%!FUNC!");
// USEPREFIX(DBG_DEV_PRINT_WARNING,           "%!STDPREFIX!   %!FUNC!");
// USEPREFIX(DBG_DEV_PRINT_INFO,              "%!STDPREFIX!   %!FUNC!");
// USEPREFIX(DBG_DEV_PRINT_VERBOSE,           "%!STDPREFIX!   %!FUNC!");
// USESUFFIX(DBG_DEV_METHOD_BEG,              ")");
// USESUFFIX(DBG_DEV_METHOD_BEG_WITH_PARAMS,  ")");
// USESUFFIX(DBG_DEV_METHOD_END,              ")");
// USESUFFIX(DBG_DEV_METHOD_END_WITH_PARAMS,  ")");
// USESUFFIX(DBG_DEV_METHOD_END_WITH_STATUS,  ") [%!STATUS!]", EXP);
// USESUFFIX(DBG_DEV_PRINT_ERROR_WITH_STATUS, " [%!STATUS!] !!!", EXP);
// FUNC      DBG_DEV_METHOD_BEG{              LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_DEVICE}(...);
// FUNC      DBG_DEV_METHOD_BEG_WITH_PARAMS{  LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_DEVICE}(MSG, ...);
// FUNC      DBG_DEV_METHOD_END{              LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_DEVICE}(...);
// FUNC      DBG_DEV_METHOD_END_WITH_PARAMS{  LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_DEVICE}(MSG, ...);
// FUNC      DBG_DEV_METHOD_END_WITH_STATUS{  LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_DEVICE}(EXP);
// FUNC      DBG_DEV_PRINT_ERROR{             LEVEL=TRACE_LEVEL_ERROR,       FLAGS=TRACE_DEVICE}(MSG, ...);
// FUNC      DBG_DEV_PRINT_ERROR_WITH_STATUS{ LEVEL=TRACE_LEVEL_ERROR,       FLAGS=TRACE_DEVICE}(EXP, MSG, ...);
// FUNC      DBG_DEV_PRINT_WARNING{           LEVEL=TRACE_LEVEL_WARNING,     FLAGS=TRACE_DEVICE}(MSG, ...);
// FUNC      DBG_DEV_PRINT_INFO{              LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_DEVICE}(MSG, ...);
// FUNC      DBG_DEV_PRINT_VERBOSE{           LEVEL=TRACE_LEVEL_VERBOSE,     FLAGS=TRACE_DEVICE}(MSG, ...);
//
// USEPREFIX(DBG_IOCTL_METHOD_BEG,              "%!STDPREFIX!+++%!FUNC!(");
// USEPREFIX(DBG_IOCTL_METHOD_BEG_WITH_PARAMS,  "%!STDPREFIX!+++%!FUNC!(");
// USEPREFIX(DBG_IOCTL_METHOD_END,              "%!STDPREFIX!---%!FUNC!(");
// USEPREFIX(DBG_IOCTL_METHOD_END_WITH_PARAMS,  "%!STDPREFIX!---%!FUNC!(");
// USEPREFIX(DBG_IOCTL_METHOD_END_WITH_STATUS,  "%!STDPREFIX!---%!FUNC!(");
// USEPREFIX(DBG_IOCTL_PRINT_ERROR,             "%!STDPREFIX!!!!%!FUNC!");
// USEPREFIX(DBG_IOCTL_PRINT_ERROR_WITH_STATUS, "%!STDPREFIX!!!!%!FUNC!");
// USEPREFIX(DBG_IOCTL_PRINT_WARNING,           "%!STDPREFIX!   %!FUNC!");
// USEPREFIX(DBG_IOCTL_PRINT_INFO,              "%!STDPREFIX!   %!FUNC!");
// USEPREFIX(DBG_IOCTL_PRINT_VERBOSE,           "%!STDPREFIX!   %!FUNC!");
// USESUFFIX(DBG_IOCTL_METHOD_BEG,              ")");
// USESUFFIX(DBG_IOCTL_METHOD_BEG_WITH_PARAMS,  ")");
// USESUFFIX(DBG_IOCTL_METHOD_END,              ")");
// USESUFFIX(DBG_IOCTL_METHOD_END_WITH_PARAMS,  ")");
// USESUFFIX(DBG_IOCTL_METHOD_END_WITH_STATUS,  ") [%!STATUS!]", EXP);
// USESUFFIX(DBG_IOCTL_PRINT_ERROR_WITH_STATUS, " [%!STATUS!] !!!", EXP);
// FUNC      DBG_IOCTL_METHOD_BEG{              LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_IOCTL}(...);
// FUNC      DBG_IOCTL_METHOD_BEG_WITH_PARAMS{  LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_IOCTL}(MSG, ...);
// FUNC      DBG_IOCTL_METHOD_END{              LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_IOCTL}(...);
// FUNC      DBG_IOCTL_METHOD_END_WITH_PARAMS{  LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_IOCTL}(MSG, ...);
// FUNC      DBG_IOCTL_METHOD_END_WITH_STATUS{  LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_IOCTL}(EXP);
// FUNC      DBG_IOCTL_PRINT_ERROR{             LEVEL=TRACE_LEVEL_ERROR,       FLAGS=TRACE_IOCTL}(MSG, ...);
// FUNC      DBG_IOCTL_PRINT_ERROR_WITH_STATUS{ LEVEL=TRACE_LEVEL_ERROR,       FLAGS=TRACE_IOCTL}(EXP, MSG, ...);
// FUNC      DBG_IOCTL_PRINT_WARNING{           LEVEL=TRACE_LEVEL_WARNING,     FLAGS=TRACE_IOCTL}(MSG, ...);
// FUNC      DBG_IOCTL_PRINT_INFO{              LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_IOCTL}(MSG, ...);
// FUNC      DBG_IOCTL_PRINT_VERBOSE{           LEVEL=TRACE_LEVEL_VERBOSE,     FLAGS=TRACE_IOCTL}(MSG, ...);
//
// USEPREFIX(DBG_I2C_METHOD_BEG,              "%!STDPREFIX!+++%!FUNC!(");
// USEPREFIX(DBG_I2C_METHOD_BEG_WITH_PARAMS,  "%!STDPREFIX!+++%!FUNC!(");
// USEPREFIX(DBG_I2C_METHOD_END,              "%!STDPREFIX!---%!FUNC!(");
// USEPREFIX(DBG_I2C_METHOD_END_WITH_PARAMS,  "%!STDPREFIX!---%!FUNC!(");
// USEPREFIX(DBG_I2C_METHOD_END_WITH_STATUS,  "%!STDPREFIX!---%!FUNC!(");
// USEPREFIX(DBG_I2C_PRINT_ERROR,             "%!STDPREFIX!!!!%!FUNC!");
// USEPREFIX(DBG_I2C_PRINT_ERROR_WITH_STATUS, "%!STDPREFIX!!!!%!FUNC!");
// USEPREFIX(DBG_I2C_PRINT_WARNING,           "%!STDPREFIX!   %!FUNC!");
// USEPREFIX(DBG_I2C_PRINT_INFO,              "%!STDPREFIX!   %!FUNC!");
// USEPREFIX(DBG_I2C_PRINT_VERBOSE,           "%!STDPREFIX!   %!FUNC!");
// USESUFFIX(DBG_I2C_METHOD_BEG,              ")");
// USESUFFIX(DBG_I2C_METHOD_BEG_WITH_PARAMS,  ")");
// USESUFFIX(DBG_I2C_METHOD_END,              ")");
// USESUFFIX(DBG_I2C_METHOD_END_WITH_PARAMS,  ")");
// USESUFFIX(DBG_I2C_METHOD_END_WITH_STATUS,  ") [%!STATUS!]", EXP);
// USESUFFIX(DBG_I2C_PRINT_ERROR_WITH_STATUS, " [%!STATUS!] !!!", EXP);
// FUNC      DBG_I2C_METHOD_BEG{              LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_I2C}(...);
// FUNC      DBG_I2C_METHOD_BEG_WITH_PARAMS{  LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_I2C}(MSG, ...);
// FUNC      DBG_I2C_METHOD_END{              LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_I2C}(...);
// FUNC      DBG_I2C_METHOD_END_WITH_PARAMS{  LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_I2C}(MSG, ...);
// FUNC      DBG_I2C_METHOD_END_WITH_STATUS{  LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_I2C}(EXP);
// FUNC      DBG_I2C_PRINT_ERROR{             LEVEL=TRACE_LEVEL_ERROR,       FLAGS=TRACE_I2C}(MSG, ...);
// FUNC      DBG_I2C_PRINT_ERROR_WITH_STATUS{ LEVEL=TRACE_LEVEL_ERROR,       FLAGS=TRACE_I2C}(EXP, MSG, ...);
// FUNC      DBG_I2C_PRINT_WARNING{           LEVEL=TRACE_LEVEL_WARNING,     FLAGS=TRACE_I2C}(MSG, ...);
// FUNC      DBG_I2C_PRINT_INFO{              LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=TRACE_I2C}(MSG, ...);
// FUNC      DBG_I2C_PRINT_VERBOSE{           LEVEL=TRACE_LEVEL_VERBOSE,     FLAGS=TRACE_I2C}(MSG, ...);
//
// end_wpp


#elif (TCPCI_TRACE == TCPCI_TRACE_DBG_PRINT_EX)


#define I2C_READ  0
#define I2C_WRITE 1

#define WPP_INIT_TRACING(...)  KeQuerySystemTimePrecise(&DriverStartTime);
#define WPP_CLEANUP(...)

extern LARGE_INTEGER        DriverStartTime;

static inline LONG GetTime() {
    LARGE_INTEGER  CurrentSystemTime;
    KeQuerySystemTimePrecise(&CurrentSystemTime);
    return (LONG)((CurrentSystemTime.QuadPart - DriverStartTime.QuadPart)/10000);
}

typedef struct _DEV_CONTEXT DEV_CONTEXT, *PDEV_CONTEXT;
typedef struct TCPC_PHY_struct_t TCPC_PHY_t;

EXTERN_C_START
void        TCPC_PHY_DumpReg(const char *CallerName, TCPC_PHY_t *pRegs, UINT32 RegAddress, UINT32 params, ULONG Length);
void        TCPC_PHY_ReadAllRegs(PDEV_CONTEXT pDevContext, char *Caller);
const char* Dbg_GetIOCTLName(ULONG i);
const char* Dbg_GetIOCTLShortName(ULONG i);
const char* Dbg_GetI2CIOSrcName(ULONG i);
EXTERN_C_END

#define PRINT
#ifdef PRINT
#define DBG_PRINT_ERROR(_format_str_,...)                      DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s: "_format_str_"\n"          ,GetTime() ,KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__VA_ARGS__)
#define DBG_PRINT_ERROR_WITH_STATUS(_status_,_format_str_,...) DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s: "_format_str_" [0x%.8X]\n" ,GetTime() ,KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__VA_ARGS__,_status_)
#else // PRINT
#define DBG_PRINT_ERROR(...)
#define DBG_PRINT_ERROR_WITH_STATUS(...)
#endif // PRINT

#define CONFIG
#ifdef CONFIG
#define DBG_CONFIG_DUMP(_format_str_,...) DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s: "_format_str_"\n"          ,GetTime() ,KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__VA_ARGS__)
#else // CONFIG
#define DBG_CONFIG_DUMP(...)
#endif // CONFIG

#define TCPCI_REG
#ifdef TCPCI_REG
#define DBG_TCPCI_REG_DUMP(_format_str_,...) DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s: "_format_str_"\n"          ,GetTime() ,KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__VA_ARGS__)
#else // TCPCI_REG
#define DBG_TCPCI_REG_DUMP(...)
#endif // TCPCI_REG

#define TCPCI_MSG
#ifdef TCPCI_MSG
#define DBG_TCPCI_MSG_DUMP(_format_str_,...) DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s: "_format_str_"\n"          ,GetTime() ,KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__VA_ARGS__)
#else // TCPCI_MSG
#define DBG_TCPCI_MSG_DUMP(...)
#endif // TCPCI_MSG

//#define IOCTL_CMD
#ifdef IOCTL_CMD
#define DBG_IOCTL_CMD_DUMP(_format_str_,...) DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s: "_format_str_"\n"          ,GetTime() ,KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__VA_ARGS__)
#else // IOCTL_CMD
#define DBG_IOCTL_CMD_DUMP(...)
#endif // IOCTL_CMD

//#define DRV
#ifdef DRV
#define DBG_DRV_METHOD_BEG()                                        DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:+++%s()\n"                      ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__)
#define DBG_DRV_METHOD_BEG_WITH_PARAMS(_format_str_,...)            DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:+++%s("_format_str_")\n"        ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_DRV_METHOD_END()                                        DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:---%s()\n"                      ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__)
#define DBG_DRV_METHOD_END_WITH_PARAMS(_format_str_,...)            DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:---%s("_format_str_")\n"        ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_DRV_METHOD_END_WITH_STATUS(_status_)                    DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:---%s() [0x%.8X]\n"             ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,_status_)
#define DBG_DRV_PRINT_ERROR(_format_str_,...)                       DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:!!!%s"_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_DRV_PRINT_ERROR_WITH_STATUS(_status_, _format_str_,...) DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:!!!%s"_format_str_" [0x%.8X]\n" ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__,_status_)
#define DBG_DRV_PRINT_WARNING(_format_str_,...)                     DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:   %s"_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_DRV_PRINT_VERBOSE(_format_str_,...)                     DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:   %s"_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_DRV_PRINT_INFO(_format_str_,...)                        DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:   %s"_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#else // DRV
#define DBG_DRV_METHOD_BEG(...)
#define DBG_DRV_METHOD_BEG_WITH_PARAMS(...)
#define DBG_DRV_METHOD_END(...)
#define DBG_DRV_METHOD_END_WITH_PARAMS(...)
#define DBG_DRV_METHOD_END_WITH_STATUS(...)
#define DBG_DRV_PRINT_ERROR(...)
#define DBG_DRV_PRINT_ERROR_WITH_STATUS(...)
#define DBG_DRV_PRINT_WARNING(...)
#define DBG_DRV_PRINT_VERBOSE(...)
#define DBG_DRV_PRINT_INFO(...)
#endif // DRV

//#define DEV
#ifdef DEV
#define DBG_DEV_METHOD_BEG()                                        DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:+++%s()\n"                      ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__)
#define DBG_DEV_METHOD_BEG_WITH_PARAMS(_format_str_,...)            DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:+++%s("_format_str_")\n"        ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_DEV_METHOD_END()                                        DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:---%s()\n"                      ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__)
#define DBG_DEV_METHOD_END_WITH_PARAMS(_format_str_,...)            DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:---%s("_format_str_")\n"        ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_DEV_METHOD_END_WITH_STATUS(_status_)                    DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:---%s() [0x%.8X]\n"             ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,_status_)
#define DBG_DEV_PRINT_ERROR(_format_str_,...)                       DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:!!!%s"_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_DEV_PRINT_ERROR_WITH_STATUS(_status_, _format_str_,...) DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:!!!%s"_format_str_" [0x%.8X]\n" ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__,_status_)
#define DBG_DEV_PRINT_WARNING(_format_str_,...)                     DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:   %s"_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_DEV_PRINT_VERBOSE(_format_str_,...)                     DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:   %s"_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_DEV_PRINT_INFO(_format_str_,...)                        DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:   %s"_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#else // DEV
#define DBG_DEV_METHOD_BEG(...)
#define DBG_DEV_METHOD_BEG_WITH_PARAMS(...)
#define DBG_DEV_METHOD_END(...)
#define DBG_DEV_METHOD_END_WITH_PARAMS(...)
#define DBG_DEV_METHOD_END_WITH_STATUS(...)
#define DBG_DEV_PRINT_ERROR(...)
#define DBG_DEV_PRINT_ERROR_WITH_STATUS(...)
#define DBG_DEV_PRINT_WARNING(...)
#define DBG_DEV_PRINT_VERBOSE(...)
#define DBG_DEV_PRINT_INFO(...)
#endif // DEV

//#define IOCTL
#ifdef IOCTL
#define DBG_IOCTL_METHOD_BEG()                                        DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:+++%s()\n"                      ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__)
#define DBG_IOCTL_METHOD_BEG_WITH_PARAMS(_format_str_,...)            DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:+++%s("_format_str_")\n"        ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_IOCTL_METHOD_END()                                        DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:---%s()\n"                      ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__)
#define DBG_IOCTL_METHOD_END_WITH_PARAMS(_format_str_,...)            DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:---%s("_format_str_")\n"        ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_IOCTL_METHOD_END_WITH_STATUS(_status_)                    DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:---%s() [0x%.8X]\n"             ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,_status_)
#define DBG_IOCTL_PRINT_ERROR(_format_str_,...)                       DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:!!!%s"_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_IOCTL_PRINT_ERROR_WITH_STATUS(_status_, _format_str_,...) DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:!!!%s"_format_str_" [0x%.8X]\n" ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__,_status_)
#define DBG_IOCTL_PRINT_WARNING(_format_str_,...)                     DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:   %s"_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_IOCTL_PRINT_VERBOSE(_format_str_,...)                     DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:   %s"_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_IOCTL_PRINT_INFO(_format_str_,...)                        DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:   %s"_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#else // IOCTL
#define DBG_IOCTL_METHOD_BEG(...)
#define DBG_IOCTL_METHOD_BEG_WITH_PARAMS(...)
#define DBG_IOCTL_METHOD_END(...)
#define DBG_IOCTL_METHOD_END_WITH_PARAMS(...)
#define DBG_IOCTL_METHOD_END_WITH_STATUS(...)
#define DBG_IOCTL_PRINT_ERROR(...)
#define DBG_IOCTL_PRINT_ERROR_WITH_STATUS(...)
#define DBG_IOCTL_PRINT_WARNING(...)
#define DBG_IOCTL_PRINT_VERBOSE(...)
#define DBG_IOCTL_PRINT_INFO(...)
#endif // IOCTL

//#define I2C
#ifdef I2C
#define DBG_I2C_METHOD_BEG()                                        DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:+++%s()\n"                      ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__)
#define DBG_I2C_METHOD_BEG_WITH_PARAMS(_format_str_,...)            DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:+++%s("_format_str_")\n"        ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_I2C_METHOD_END()                                        DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:---%s()\n"                      ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__)
#define DBG_I2C_METHOD_END_WITH_PARAMS(_format_str_,...)            DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:---%s("_format_str_")\n"        ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_I2C_METHOD_END_WITH_STATUS(_status_)                    DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:---%s() [0x%.8X]\n"             ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,_status_)
#define DBG_I2C_PRINT_ERROR(_format_str_,...)                       DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:!!!%s() "_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_I2C_PRINT_ERROR_WITH_STATUS(_status_, _format_str_,...) DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:!!!%s() "_format_str_" [0x%.8X]\n" ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__,_status_)
#define DBG_I2C_PRINT_WARNING(_format_str_,...)                     DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:   %s() "_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_I2C_PRINT_VERBOSE(_format_str_,...)                     DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:   %s() "_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#define DBG_I2C_PRINT_INFO(_format_str_,...)                        DbgPrintEx(DPFLTR_IHVDRIVER_ID,0xFFFFFFFE,"%08d C%d D%d %s:   %s() "_format_str_"\n"          ,GetTime(),KeGetCurrentProcessorNumber(),KeGetCurrentIrql(),"TCPCIDrv",__FUNCTION__,__VA_ARGS__)
#else // I2C
#define DBG_I2C_METHOD_BEG(...)
#define DBG_I2C_METHOD_BEG_WITH_PARAMS(...)
#define DBG_I2C_METHOD_END(...)
#define DBG_I2C_METHOD_END_WITH_PARAMS(...)
#define DBG_I2C_METHOD_END_WITH_STATUS(...)
#define DBG_I2C_PRINT_ERROR(...)
#define DBG_I2C_PRINT_ERROR_WITH_STATUS(...)
#define DBG_I2C_PRINT_WARNING(...)
#define DBG_I2C_PRINT_VERBOSE(...)
#define DBG_I2C_PRINT_INFO(...)
#endif // I2C


#else // (TCPCI_TRACE == TCPCI_TRACE_DBG_PRINT_EX)


#define WPP_INIT_TRACING(...)
#define WPP_CLEANUP(...)
#define TCPC_PHY_DumpReg(...)
#define TCPC_PHY_ReadAllRegs(...)
#define Dbg_GetI2CIOSrcName(...)

#define DBG_PRINT_ERROR(...)
#define DBG_PRINT_ERROR_WITH_STATUS(...)
#define DBG_CONFIG_DUMP(...)
#define DBG_TCPCI_REG_DUMP(...)
#define DBG_TCPCI_MSG_DUMP(...)
#define DBG_IOCTL_CMD_DUMP(...)
#define DBG_DRV_METHOD_BEG(...)
#define DBG_DRV_METHOD_BEG_WITH_PARAMS(...)
#define DBG_DRV_METHOD_END(...)
#define DBG_DRV_METHOD_END_WITH_PARAMS(...)
#define DBG_DRV_METHOD_END_WITH_STATUS(...)
#define DBG_DRV_PRINT_ERROR(...)
#define DBG_DRV_PRINT_ERROR_WITH_STATUS(...)
#define DBG_DRV_PRINT_WARNING(...)
#define DBG_DRV_PRINT_VERBOSE(...)
#define DBG_DRV_PRINT_INFO(...)

#define DBG_DEV_METHOD_BEG(...)
#define DBG_DEV_METHOD_BEG_WITH_PARAMS(...)
#define DBG_DEV_METHOD_END(...)
#define DBG_DEV_METHOD_END_WITH_PARAMS(...)
#define DBG_DEV_METHOD_END_WITH_STATUS(...)
#define DBG_DEV_PRINT_ERROR(...)
#define DBG_DEV_PRINT_ERROR_WITH_STATUS(...)
#define DBG_DEV_PRINT_WARNING(...)
#define DBG_DEV_PRINT_VERBOSE(...)
#define DBG_DEV_PRINT_INFO(...)

#define DBG_IOCTL_METHOD_BEG(...)
#define DBG_IOCTL_METHOD_BEG_WITH_PARAMS(...)
#define DBG_IOCTL_METHOD_END(...)
#define DBG_IOCTL_METHOD_END_WITH_PARAMS(...)
#define DBG_IOCTL_METHOD_END_WITH_STATUS(...)
#define DBG_IOCTL_PRINT_ERROR(...)
#define DBG_IOCTL_PRINT_ERROR_WITH_STATUS(...)
#define DBG_IOCTL_PRINT_WARNING(...)
#define DBG_IOCTL_PRINT_VERBOSE(...)
#define DBG_IOCTL_PRINT_INFO(...)

#define DBG_I2C_METHOD_BEG(...)
#define DBG_I2C_METHOD_BEG_WITH_PARAMS(...)
#define DBG_I2C_METHOD_END(...)
#define DBG_I2C_METHOD_END_WITH_PARAMS(...)
#define DBG_I2C_METHOD_END_WITH_STATUS(...)
#define DBG_I2C_PRINT_ERROR(...)
#define DBG_I2C_PRINT_ERROR_WITH_STATUS(...)
#define DBG_I2C_PRINT_WARNING(...)
#define DBG_I2C_PRINT_VERBOSE(...)
#define DBG_I2C_PRINT_INFO(...)

#endif //

#endif /* trace_H_ */
