/*
* Copyright 2018-2020 NXP
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


#include "imx_tcpci.h"

/*
This files contains functions used for debug purposes only and is for debugging only.
Do not use any of these functions in production code!
*/

#if (TCPCI_TRACE == TCPCI_TRACE_WPP) || (TCPCI_TRACE == TCPCI_TRACE_DBG_PRINT_EX)


#if (TCPCI_TRACE == TCPCI_TRACE_WPP)
#include "imx_tcpci_trace.tmh"
#endif

#if (TCPCI_TRACE == TCPCI_TRACE_DBG_PRINT_EX)
LARGE_INTEGER        DriverStartTime;
#endif

void        TCPC_PHY_DumpTxBuffer(_In_reads_bytes_(Length) UCMTCPCI_PORT_CONTROLLER_TRANSMIT_BUFFER *pBuffer, _In_ ULONG Length, _In_ char* Caller);

#pragma warning(disable:4100)

#undef MAKECASE
#undef MAKECASE1
#undef MAKEDEFAULT
#define MAKECASE(Value) case Value:  return #Value;
#define MAKECASE1(Value,Name) case Value:  return #Name;
#define MAKEDEFAULT(Message) default: return"!!! "Message" name unknown !!!";

const char* Dbg_GetIOCTLName(ULONG i) {
    switch (i) {
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_GET_STATUS)
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_GET_CONTROL)
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_CONTROL)
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT)
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_BUFFER)
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_RECEIVE_DETECT)
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_CONFIG_STANDARD_OUTPUT)
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_COMMAND)
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_MESSAGE_HEADER_INFO)
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_ALTERNATE_MODE_ENTERED)
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_ALTERNATE_MODE_EXITED)
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_CONFIGURED)
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_HPD_STATUS_CHANGED)
        MAKECASE(IOCTL_UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_DISPLAY_OUT_STATUS_CHANGED)
        MAKEDEFAULT("Unknown IOCTL")
    }
}


const char* Dbg_GetRegName(UINT32 i) {
    switch (i) {
        MAKECASE(TCPC_PHY_EXTENDED_STATUS_MASK)
        MAKECASE(TCPC_PHY_ALERT_EXTENDED_MASK)
        MAKECASE(TCPC_PHY_CONFIG_STANDARD_OUTPUT)
        MAKECASE(TCPC_PHY_TCPC_CONTROL)
        MAKECASE(TCPC_PHY_ROLE_CONTROL)
        MAKECASE(TCPC_PHY_FAULT_CONTROL)
        MAKECASE(TCPC_PHY_POWER_CONTROL)
        MAKECASE(TCPC_PHY_CC_STATUS)
        MAKECASE(TCPC_PHY_EXTENDED_STATUS)
        MAKECASE(TCPC_PHY_ALERT_EXTENDED)
        MAKECASE(TCPC_PHY_CFG_EXT_1)
        MAKECASE(TCPC_PHY_GENERIC_TIMER)
        MAKECASE(TCPC_PHY_RX_BUF_BYTE_X)
        MAKECASE(TCPC_PHY_TX_BUF_BYTE_X)
        MAKECASE(TCPC_PHY_VBUS_VOLTAGE)
        MAKECASE(TCPC_PHY_VBUS_SINK_DISCONNECT_THRESHOLD)
        MAKECASE(TCPC_PHY_VBUS_STOP_DISCHARGE_THRESHOLD)
        MAKECASE(TCPC_PHY_VBUS_VOLTAGE_ALARM_HI_CFG)
        MAKECASE(TCPC_PHY_VBUS_VOLTAGE_ALARM_LO_CFG)
        MAKECASE(TCPC_PHY_VBUS_HV_TARGET)
        MAKECASE(TCPC_PHY_EXT_CFG_ID)
        MAKECASE(TCPC_PHY_EXT_ALERT)
        MAKECASE(TCPC_PHY_EXT_ALERT_MASK)
        MAKECASE(TCPC_PHY_EXT_CONFIG)
        MAKECASE(TCPC_PHY_EXT_FAULT_CONFIG)
        MAKECASE(TCPC_PHY_EXT_CONTROL)
        MAKECASE(TCPC_PHY_EXT_STATUS)
        MAKECASE(TCPC_PHY_EXT_GPIO_CONFIG)
        MAKECASE(TCPC_PHY_EXT_GPIO_CONTROL)
        MAKECASE(TCPC_PHY_EXT_GPIO_ALERT_CONFIG)
        MAKECASE(TCPC_PHY_EXT_GPIO_STATUS)
        MAKECASE(TCPC_PHY_SOURCE_HIGH_VOLTAGE_MB4B_TIME)
        MAKECASE(TCPC_PHY_ADC_FILTER_CONTROL_1)
        MAKECASE(TCPC_PHY_ADC_FILTER_CONTROL_2)
        MAKECASE(TCPC_PHY_VCON_CONFIG)
        MAKECASE(TCPC_PHY_VCON_FAULT_DEBOUNCE)
        MAKECASE(TCPC_PHY_VCON_FAULT_RECOVERY)
        MAKECASE(TCPC_PHY_VCON_FAULT_ATTEMPTS)
        MAKEDEFAULT("Unknown reg name")
    }
}

#define PD_CTRL_MSG_GoodCRC                  0x01
#define PD_CTRL_MSG_GotoMin                  0x02
#define PD_CTRL_MSG_Accept                   0x03
#define PD_CTRL_MSG_Reject                   0x04
#define PD_CTRL_MSG_Ping                     0x05
#define PD_CTRL_MSG_PS_RDY                   0x06
#define PD_CTRL_MSG_Get_Source_Cap           0x07
#define PD_CTRL_MSG_Get_Sink_Cap             0x08
#define PD_CTRL_MSG_DR_Swap                  0x09
#define PD_CTRL_MSG_PR_Swap                  0x0A
#define PD_CTRL_MSG_VCONN_Swap               0x0B
#define PD_CTRL_MSG_Wait                     0x0C
#define PD_CTRL_MSG_Soft_Reset               0x0D
#define PD_CTRL_MSG_Data_Reset               0x0E
#define PD_CTRL_MSG_Data_Reset_Complete      0x0F
#define PD_CTRL_MSG_Not_Supported            0x10
#define PD_CTRL_MSG_Get_Source_Cap_Extended  0x11
#define PD_CTRL_MSG_Get_Status               0x12
#define PD_CTRL_MSG_FR_Swap                  0x13
#define PD_CTRL_MSG_Get_PPS_Status           0x14
#define PD_CTRL_MSG_Get_Country_Codes        0x15
#define PD_CTRL_MSG_Get_Sink_Cap_Extended    0x16

#define PD_DATA_MSG_Source_Capabilities      0x01
#define PD_DATA_MSG_Request                  0x02
#define PD_DATA_MSG_BIST                     0x03
#define PD_DATA_MSG_Sink_Capabilities        0x04
#define PD_DATA_MSG_Battery_Status           0x05
#define PD_DATA_MSG_Alert                    0x06
#define PD_DATA_MSG_Get_Country_Info         0x07
#define PD_DATA_MSG_Enter_USB                0x08
#define PD_DATA_MSG_Vendor_Defined           0x0F

#define TCPC_GetMsgType(_MsgType_) (_MsgType_ == 0)? "SOP":(_MsgType_ == 1)? "SOP'":(_MsgType_ == 2)? "SOP''":(_MsgType_ == 3)? "BDG'":(_MsgType_ == 4)? "BGB''":(_MsgType_ == 5)? "HardRts":(_MsgType_ == 6)? "CableRst":"BIST"

const char* Dbg_GetPDCtrlMsgName(UINT32 i) {
    switch (i) {
        MAKECASE1(PD_CTRL_MSG_GoodCRC                  , "GoodCRC");
        MAKECASE1(PD_CTRL_MSG_GotoMin                  , "GotoMin");
        MAKECASE1(PD_CTRL_MSG_Accept                   , "Accept");
        MAKECASE1(PD_CTRL_MSG_Reject                   , "Reject");
        MAKECASE1(PD_CTRL_MSG_Ping                     , "Ping");
        MAKECASE1(PD_CTRL_MSG_PS_RDY                   , "PS_RDY");
        MAKECASE1(PD_CTRL_MSG_Get_Source_Cap           , "Get_Source_Cap");
        MAKECASE1(PD_CTRL_MSG_Get_Sink_Cap             , "Get_Sink_Cap");
        MAKECASE1(PD_CTRL_MSG_DR_Swap                  , "DR_Swap");
        MAKECASE1(PD_CTRL_MSG_PR_Swap                  , "PR_Swap");
        MAKECASE1(PD_CTRL_MSG_VCONN_Swap               , "VCONN_Swap");
        MAKECASE1(PD_CTRL_MSG_Wait                     , "Wait");
        MAKECASE1(PD_CTRL_MSG_Soft_Reset               , "Soft_Reset");
        MAKECASE1(PD_CTRL_MSG_Data_Reset               , "Data_Reset");
        MAKECASE1(PD_CTRL_MSG_Data_Reset_Complete      , "Data_Reset_Complete");
        MAKECASE1(PD_CTRL_MSG_Not_Supported            , "Not_Supported");
        MAKECASE1(PD_CTRL_MSG_Get_Source_Cap_Extended  , "Get_Source_Cap_Extended");
        MAKECASE1(PD_CTRL_MSG_Get_Status               , "Get_Status");
        MAKECASE1(PD_CTRL_MSG_FR_Swap                  , "FR_Swap");
        MAKECASE1(PD_CTRL_MSG_Get_PPS_Status           , "Get_PPS_Status");
        MAKECASE1(PD_CTRL_MSG_Get_Country_Codes        , "Get_Country_Codes");
        MAKECASE1(PD_CTRL_MSG_Get_Sink_Cap_Extended    , "Get_Sink_Cap_Extended"); 
        MAKEDEFAULT("CtrlMsg");
    }
}

const char* Dbg_GetPDDataMsgName(UINT32 i) {
    switch (i) {
        MAKECASE1(PD_DATA_MSG_Source_Capabilities      , "Source_Capabilities");
        MAKECASE1(PD_DATA_MSG_Request                  , "Request");
        MAKECASE1(PD_DATA_MSG_BIST                     , "BIST");
        MAKECASE1(PD_DATA_MSG_Sink_Capabilities        , "Sink_Capabilities");  
        MAKECASE1(PD_DATA_MSG_Battery_Status           , "Battery_Status");     
        MAKECASE1(PD_DATA_MSG_Alert                    , "Alert");              
        MAKECASE1(PD_DATA_MSG_Get_Country_Info         , "Get_Country_Info");   
        MAKECASE1(PD_DATA_MSG_Enter_USB                , "Enter_USB");          
        MAKECASE1(PD_DATA_MSG_Vendor_Defined           , "Vendor_Defined");     
        MAKEDEFAULT("DataMsg");
    }
}

/*
* PD_MESSAGE_HEADER register bits definition *
*/
typedef union PD_MESSAGE_HEADER_union_t {
    UINT16 R;
    struct {
        UINT16 MSG_TYPE                         :  5;  /* SOP* Message Type. */
        UINT16 PORT_DATA_ROLE                   :  1;  /* SOP only Port Data Role */
        UINT16 PD_SPEC_REV                      :  2;  /* SOP* Specification Revision */
        UINT16 PORT_POWER_ROLE                  :  1;  /* SOP only Port Power Role */
        UINT16 MSG_ID                           :  3;  /* SOP* MessageID */
        UINT16 NUM_OF_DATA                      :  3;  /* SOP* Number of Data Objects */
        UINT16 EXT_SECTION                      :  1;  /* SOP* Extended */
    } SOP_PORT;
    struct {
        UINT16 MSG_TYPE                         :  5;  /* SOP* Message Type. */
        UINT16 RESERVED                         :  1;  /* Reserved */
        UINT16 PD_SPEC_REV                      :  2;  /* SOP* Specification Revision */
        UINT16 CABLE_PLUG                       :  1;  /* SOP’/SOP’’ Cable Plug Section */
        UINT16 MSG_ID                           :  3;  /* SOP* MessageID */
        UINT16 NUM_OF_DATA                      :  3;  /* SOP* Number of Data Objects */
        UINT16 EXT_SECTION                      :  1;  /* SOP* Extended */
    } SOP_CABLE;
} PD_MESSAGE_HEADER_t;


typedef struct PD_MESSAGE_struct_t {
    PD_MESSAGE_HEADER_t MsgHeadr;
    UINT8               DataObjects[28];
} PD_MESSAGE_t;

/*
* PD_DATA_MESSAGE_CAPABILITIES register bits definition *
*/
typedef union PD_DATA_MSG_CAP_DO_union_t {
    UINT32 R;
    struct {
        UINT32 MAX_C_10_MA                      :  10; /* Maximum Current in 10mA units */
        UINT32 VLTG_50_MV                       :  10; /* Voltage in 50mV units */
        UINT32 PEAK_CURRENT                     :  2;  /* Peak Current */
        UINT32 RESEREVED                        :  2;  /* Reserved – Shall be set to zero. */
        UINT32 UNCHNKD_EX_MSG                   :  1;  /* Unchunked Extended Messages Supported */
        UINT32 DRD                              :  1;  /* Dual-Role Data */
        UINT32 USB_DATA_CAP                     :  1;  /* USB Communications Capable */
        UINT32 UNCNS_PWR                        :  1;  /* Unconstrained Power */
        UINT32 USB_SUSP                         :  1;  /* USB Suspend Supported */
        UINT32 DRP                              :  1;  /* Dual-Role Power */
        UINT32 TYPE                             :  2;  /* Power supply type - Fixed supply */
    } PDO_FPS;
    struct {
        /* TODO  */
        UINT32 TYPE                             :  2;  /* Power supply type - Fixed supply */
    } APDO;
} PD_DATA_MSG_CAP_DO_t;

/*
* PD_DATA_MESSAGE_REQUEST register bits definition *
*/
typedef union PD_DATA_MSG_REQ_DO_union_t {
    UINT32 R;
    struct {
        UINT32 MAX_OP_CUR_10_MA                 :  10; /* Maximum Operating Current 10mA units */
        UINT32 OP_CUR_10_MA                     :  10; /* Operating current in 10mA units */
        UINT32 RESEREVED_20                     :  3;  /* Reserved – Shall be set to zero. */
        UINT32 UNCHNKD_EX_MSG                   :  1;  /* Unchunked Extended Messages Supported */
        UINT32 NO_USB_SUSP                      :  1;  /* No USB Suspend */
        UINT32 USB_DATA_CAP                     :  1;  /* USB Communications Capable */
        UINT32 CAP_MSMTCH                       :  1;  /* Capability Mismatch */
        UINT32 GB_FLG                           :  1;  /* GiveBack flag */
        UINT32 POSITION                         :  3;  /* Object position */
        UINT32 RESERVED_31                      :  1;  /* Reserved */
    } RDO_FPS;
} PD_DATA_MSG_REQ_DO_t;


void TCPC_PHY_DumpCapabilities(PD_DATA_MSG_CAP_DO_t Cap, const char* Caller) {
    switch (Cap.PDO_FPS.TYPE) {
        case 0:
            DBG_TCPCI_MSG_DUMP("\n\r"
                "Fixed Supply PDO - Source: 0x%08X\n\r"
                "       Dual-Role Power:             %d\n\r"
                "       USB Suspend:                 %d\n\r"
                "       Unconstrained Power:         %d\n\r"
                "       USB Communications Capable:  %d\n\r"
                "       Dual-Role Data:              %d\n\r"
                "       Unchunked Extended Messages: %d\n\r"
                "       Peak Current:                %d\n\r"
                "       Voltage[mV]:                 %d\n\r"
                "       Max. Current[mA]:            %d",
                Cap.R, Cap.PDO_FPS.DRP, Cap.PDO_FPS.USB_SUSP, Cap.PDO_FPS.UNCNS_PWR, Cap.PDO_FPS.USB_DATA_CAP, Cap.PDO_FPS.DRD, Cap.PDO_FPS.UNCHNKD_EX_MSG, Cap.PDO_FPS.PEAK_CURRENT, Cap.PDO_FPS.VLTG_50_MV*50, Cap.PDO_FPS.MAX_C_10_MA*10);
            break;
        default:
            break;
    }
}
void TCPC_PHY_DumpRequest(PD_DATA_MSG_REQ_DO_t Req, const char* Caller) {
    DBG_TCPCI_MSG_DUMP("\n\r"
         "Fixed and Variable Request Data Object: 0x%08X\n\r"
         "       Object position:             %d\n\r"
         "       GiveBack flag:               %d\n\r"
         "       Capability Mismatch:         %d\n\r"
         "       USB Communications Capable:  %d\n\r"
         "       No USB Suspend:              %d\n\r"
         "       Unchunked Extended Messages: %d\n\r"
         "       Operating current[ma]:       %d\n\r"
         "       Max. operationg Current[mA]: %d",
         Req.R, Req.RDO_FPS.POSITION, Req.RDO_FPS.GB_FLG, Req.RDO_FPS.CAP_MSMTCH, Req.RDO_FPS.USB_DATA_CAP, Req.RDO_FPS.NO_USB_SUSP, Req.RDO_FPS.UNCHNKD_EX_MSG, Req.RDO_FPS.OP_CUR_10_MA*10, Req.RDO_FPS.MAX_OP_CUR_10_MA*10);
}

void TCPC_PHY_DumpDataMsg(PD_MESSAGE_t *pMsg, const char* Caller) {
    PD_MESSAGE_HEADER_t MsgHeadr = pMsg->MsgHeadr;
    
    switch (MsgHeadr.SOP_PORT.MSG_TYPE) {
        case PD_DATA_MSG_Source_Capabilities:
            for (int i = 0; i < MsgHeadr.SOP_PORT.NUM_OF_DATA; i++) {
                TCPC_PHY_DumpCapabilities(((PD_DATA_MSG_CAP_DO_t *)(VOID*)((UINT8 *)pMsg+2))[i], Caller);
            }
            break;
        case PD_DATA_MSG_Request:
            for (int i = 0; i < MsgHeadr.SOP_PORT.NUM_OF_DATA; i++) {
                TCPC_PHY_DumpRequest(((PD_DATA_MSG_REQ_DO_t *)(VOID*)((UINT8 *)pMsg+2))[i], Caller);
            }
            break;
        case PD_DATA_MSG_BIST:
            break;
        case PD_DATA_MSG_Sink_Capabilities:
            for (int i = 0; i < MsgHeadr.SOP_PORT.NUM_OF_DATA; i++) {
                TCPC_PHY_DumpCapabilities(((PD_DATA_MSG_CAP_DO_t *)(VOID*)((UINT8 *)pMsg+2))[i], Caller);
            }
            break;
        case PD_DATA_MSG_Alert:
            break;
        case PD_DATA_MSG_Get_Country_Info:
            break;
        case PD_DATA_MSG_Enter_USB:
            break;
        case PD_DATA_MSG_Vendor_Defined:
            break;
        default:
            break;
    }

}


void TCPC_PHY_DumpTxBuffer(_In_reads_bytes_(Length) UCMTCPCI_PORT_CONTROLLER_TRANSMIT_BUFFER *pBuffer, _In_ const char* Caller) {
    PD_MESSAGE_HEADER_t MsgHdr;

    if (pBuffer) {    
        MsgHdr = *(PD_MESSAGE_HEADER_t*)&pBuffer->Header;
        if (MsgHdr.SOP_PORT.NUM_OF_DATA == 0) {
            /* Controll message */
            DBG_TCPCI_REG_DUMP("%-30s TxMsg: Header: 0x%04X, ID: %d, Control message: %s", Caller, MsgHdr.R, MsgHdr.SOP_PORT.MSG_ID ,Dbg_GetPDCtrlMsgName(MsgHdr.SOP_PORT.MSG_TYPE));
        } else {
            /* Data message */
            DBG_TCPCI_REG_DUMP("%-30s TxMsg: Header: 0x%04X, ID: %d, Data message: %s, Data object: %d", Caller, MsgHdr.R, MsgHdr.SOP_PORT.MSG_ID, Dbg_GetPDDataMsgName(MsgHdr.SOP_PORT.MSG_TYPE), MsgHdr.SOP_PORT.NUM_OF_DATA);
            TCPC_PHY_DumpDataMsg((PD_MESSAGE_t *)&pBuffer->Header, Caller);
        }
    }
}

void TCPC_PHY_DumpRxBuffer(_In_ UCMTCPCI_PORT_CONTROLLER_RECEIVE_BUFFER *pBuffer, _In_ const char* Caller) {
    PD_MESSAGE_HEADER_t MsgHdr;

    if (pBuffer) {    
        MsgHdr = *(PD_MESSAGE_HEADER_t*)&pBuffer->Header;
        if (MsgHdr.SOP_PORT.NUM_OF_DATA == 0) {
            /* Controll message */
            DBG_TCPCI_REG_DUMP("%-30s RxMsg: %s, Header: 0x%04X, ID: %d, Control message: %s", Caller, TCPC_GetMsgType(pBuffer->ReceivedFrameType), MsgHdr.R, MsgHdr.SOP_PORT.MSG_ID, Dbg_GetPDCtrlMsgName(MsgHdr.SOP_PORT.MSG_TYPE));
        } else {
            /* Data message */
            DBG_TCPCI_REG_DUMP("%-30s RxMsg: %s, Header: 0x%04X, ID: %d, Data message: %s, Data object: %d", Caller, TCPC_GetMsgType(pBuffer->ReceivedFrameType), MsgHdr.R, MsgHdr.SOP_PORT.MSG_ID, Dbg_GetPDDataMsgName(MsgHdr.SOP_PORT.MSG_TYPE), MsgHdr.SOP_PORT.NUM_OF_DATA);
            TCPC_PHY_DumpDataMsg((PD_MESSAGE_t *)&pBuffer->Header, Caller);
        }
    }
}

#define MAXSTRINGLEN 512
#define AppendStr(_Str_) strncat(Buffer, _Str_, ((sizeof(_Str_) < MAXSTRINGLEN-strlen(Buffer)? sizeof(_Str_) : MAXSTRINGLEN-strlen(Buffer))))

void TCPC_PHY_DumpAlert(TCPC_PHY_ALERT_t ALERT, UINT32 params, const char *Caller){

    char  Buffer[512] = "";
    Buffer[0]=0;
        if (ALERT.B.VENDOR_DEFINED_ALERT)            AppendStr(" Alrt=1");
        if (ALERT.B.ALERT_EXTENDED)                  AppendStr(" AlrtExt=1");
        if (ALERT.B.EXTENDED_STATUS)                 AppendStr(" ExStat=1");
        if (ALERT.B.BEGINNING_SOP_MESSAGE_STATUS)    AppendStr(" BegMsg=1");
        if (ALERT.B.VBUS_SINK_DISCONNECT_DETECTED)   AppendStr(" SnkDscn=1");
        if (ALERT.B.RX_BUFFER_OVERFLOW)              AppendStr(" BufOvrfl=1");
        if (ALERT.B.FAULT)                           AppendStr(" Flt=1");
        if (ALERT.B.VBUS_VOLTAGE_ALARM_LO)           AppendStr(" VLow=1");
        if (ALERT.B.VBUS_VOLTAGE_ALARM_HI)           AppendStr(" VHigh=1");
        if (ALERT.B.TRANSMIT_SOP_MESSAGE_SUCCESSFUL) AppendStr(" TxSucc=1");
        if (ALERT.B.TRANSMIT_SOP_MESSAGE_DISCARDED)  AppendStr(" TxDisc=1");
        if (ALERT.B.TRANSMIT_SOP_MESSAGE_FAILED)     AppendStr(" TxFaild=1");
        if (ALERT.B.RECEIVED_HARD_RESET)             AppendStr(" HrdRst=1");
        if (ALERT.B.RECEIVED_SOP_MESSAGE_STATUS)     AppendStr(" RxMsg=1");
        if (ALERT.B.POWER_STATUS)                    AppendStr(" PS=1");
        if (ALERT.B.CC_STATUS)                       AppendStr(" CS=1");
        DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value: 0x%04X (%s )", Caller, params?"Wr":"Rd", "ALERT", TCPC_PHY_ALERT, ALERT.R, Buffer);
}

void TCPC_PHY_DumpFaultStatus(TCPC_PHY_FAULT_STATUS_t FAULT_STATUS, UINT32 params, const char *Caller){

    char  Buffer[512] = "";
    Buffer[0]=0;
    if (FAULT_STATUS.B.ALL_REGISTERS_RESET_TO_DEFAULT)      AppendStr(" RST_TO_DEFAULT=1");
    if (FAULT_STATUS.B.FORCE_OFF_VBUS)                      AppendStr(" FORCE_OFF_VBUS=1");
    if (FAULT_STATUS.B.AUTO_DISCHARGE_FAILED)               AppendStr(" AUTO_DISCHARGE_FAILED=1");
    if (FAULT_STATUS.B.FORCE_DISCHARGE_FAILED)              AppendStr(" CS=FORCE_DISCHARGE_FAILED=1");
    if (FAULT_STATUS.B.INTERNAL_OR_EXTERNAL_VBUS_OCP_FAULT) AppendStr(" IN_OR_EXT_VBUS_OCP_FAULT=1");
    if (FAULT_STATUS.B.INTERNAL_OR_EXTERNAL_VBUS_OVP_FAULT) AppendStr(" IN_OR_EXT_VBUS_OVP_FAULT=1");
    if (FAULT_STATUS.B.VCONN_OVER_CURRENT_FAULT)            AppendStr(" VCONN_OVER_CURRENT_FAULT");
    if (FAULT_STATUS.B.I2C_INTERFACE_ERROR)                 AppendStr(" I2C_INTERFACE_ERROR");
        DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (%s )", Caller, params?"Wr":"Rd", "FAULT_STAT", TCPC_PHY_FAULT_STATUS, FAULT_STATUS.R, Buffer);
}

void TCPC_PHY_DumpReg(const char *CallerName, TCPC_PHY_t *pRegs, UINT32 RegAddress, UINT32 params, ULONG Length) {
    char *pStr;
    DEV_CONTEXT *pDevContext = (DEV_CONTEXT*)((char*)pRegs-offsetof(DEV_CONTEXT,TCPI_PhyRegs));
    switch (RegAddress) {
        case TCPC_PHY_VENDOR_ID:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value: 0x%04X (Vendor: %s)", CallerName, params?"Wr":"Rd", "VENDOR_ID", TCPC_PHY_VENDOR_ID, pRegs->VENDOR_ID.R,
                 (pRegs->VENDOR_ID.R == 0x1FC9)? "NXP":"Unknown");
                break;           
        case TCPC_PHY_PRODUCT_ID:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value: 0x%04X (Product ID: %s)", CallerName, params?"Wr":"Rd", "PRODUCT_ID", TCPC_PHY_PRODUCT_ID, pRegs->PRODUCT_ID.R,
                (pRegs->PRODUCT_ID.R == 0x5110)? "PTN5110":"Unknown");
            break;           
        case TCPC_PHY_DEVICE_ID:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value: 0x%04X (Device ID: 0x%04X)", CallerName, params?"Wr":"Rd", "DEVICE_ID", TCPC_PHY_DEVICE_ID, pRegs->DEVICE_ID.R,
                pRegs->DEVICE_ID.R);
            break;           
        case TCPC_PHY_USBTYPEC_REV:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value: 0x%04X (USB Type C rev. %d.%d)", CallerName, params?"Wr":"Rd", "USBTYPEC_REV", TCPC_PHY_USBTYPEC_REV, pRegs->USBTYPEC_REV.R,
                 (pRegs->USBTYPEC_REV.R >> 4) & 0x000F, (pRegs->USBTYPEC_REV.R >> 0) & 0x000F);
                break;           
        case TCPC_PHY_USBPD_REV_VER:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value: 0x%04X (USB PD rev. %d.%d, ver. %d.%d)", CallerName, params?"Wr":"Rd", "USBPD_REV_VER", TCPC_PHY_USBPD_REV_VER, pRegs->USBPD_REV_VER.R,
                (pRegs->USBPD_REV_VER.R >> 12) & 0x000F, (pRegs->USBPD_REV_VER.R >> 8) & 0x000F, (pRegs->USBPD_REV_VER.R >> 4) & 0x000F, (pRegs->USBPD_REV_VER.R >> 0) & 0x000F);
            break;           
        case TCPC_PHY_PD_INTERFACE_REV:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value: 0x%04X (USB TCPIC rev. %d.%d, ver. %d.%d)", CallerName, params?"Wr":"Rd", "PD_INTERFACE_REV", TCPC_PHY_PD_INTERFACE_REV, pRegs->PD_INTERFACE_REV.R,
                (pRegs->PD_INTERFACE_REV.R >> 12) & 0x000F, (pRegs->PD_INTERFACE_REV.R >> 8) & 0x000F, (pRegs->PD_INTERFACE_REV.R >> 4) & 0x000F, (pRegs->PD_INTERFACE_REV.R >> 0) & 0x000F);
            break;           
        case TCPC_PHY_ALERT:
            TCPC_PHY_DumpAlert(pRegs->ALERT, params, CallerName);
            break;           
        case TCPC_PHY_ALERT_MASK:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value: 0x%04X (VDA=%d, AlrtExt=%d, ES=%d, BegMsg=%d, VbusSnkDcn=%d, RxBufOvf=%d, Flt=%d, VbusLo=%d, VbusHi=%d, TxMsgSucc=%d, TxMsgDacrd=%d, TxMsgFld=%d, HrdRst=%d, RxMsg=%d, PS=%d, CC=%d)", CallerName, params?"Wr":"Rd", "ALERT_MASK", TCPC_PHY_ALERT_MASK, pRegs->ALERT_MASK.R,
                pRegs->ALERT_MASK.B.VENDOR_DEFINED_ALERT_INT_MASK,
                pRegs->ALERT_MASK.B.ALERT_EXTENDED_INT_MASK,
                pRegs->ALERT_MASK.B.EXTENDED_STATUS_INT_MASK,
                pRegs->ALERT_MASK.B.BEGINNING_SOP_MESSAGE_STATUS_INT_MASK,
                pRegs->ALERT_MASK.B.VBUS_SINK_DISCONNECT_DETECTED_INT_MASK,
                pRegs->ALERT_MASK.B.RX_BUFFER_OVERFLOW_INT_MASK,
                pRegs->ALERT_MASK.B.FAULT_INT_MASK,
                pRegs->ALERT_MASK.B.VBUS_VOLTAGE_ALARM_LO_INT_MASK,
                pRegs->ALERT_MASK.B.VBUS_VOLTAGE_ALARM_HI_INT_MASK,
                pRegs->ALERT_MASK.B.TRANSMIT_SOP_MESSAGE_SUCCESSFUL_INT_MASK,
                pRegs->ALERT_MASK.B.TRANSMIT_SOP_MESSAGE_DISCARDED_INT_MASK,
                pRegs->ALERT_MASK.B.TRANSMIT_SOP_MESSAGE_FAILED_INT_MASK,
                pRegs->ALERT_MASK.B.RECEIVED_HARD_RESET_INT_MASK,
                pRegs->ALERT_MASK.B.RECEIVED_SOP_MESSAGE_STATUS_INT_MASK,
                pRegs->ALERT_MASK.B.POWER_STATUS_INT_MASK,
                pRegs->ALERT_MASK.B.CC_STATUS_INT_MASK
            );
            break;           
        case TCPC_PHY_POWER_STATUS:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (DbgAccConctd=%d, TCPCInit=%d, SrcHiVltg=%d, SrcVBus=%d, VbusDetEn=%d, VBusPrsnt=%d, VConnPrsnt=%d, SnkVBus=%d)", CallerName, params?"Wr":"Rd", "POWER_STATUS", TCPC_PHY_POWER_STATUS, pRegs->POWER_STATUS.R,
                pRegs->POWER_STATUS.B.DEBUG_ACCESSORY_CONNECTED,
                pRegs->POWER_STATUS.B.TCPC_INITIALIZATION_STATUS,
                pRegs->POWER_STATUS.B.SOURCING_HIGH_VOLTAGE,
                pRegs->POWER_STATUS.B.SOURCING_VBUS,
                pRegs->POWER_STATUS.B.VBUS_DETECTION_ENABLED,
                pRegs->POWER_STATUS.B.VBUS_PRESENT,
                pRegs->POWER_STATUS.B.VCONN_PRESENT,
                pRegs->POWER_STATUS.B.SINKING_VBUS
            );
            break;
        case TCPC_PHY_POWER_STATUS_MASK:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (DbgAccConctd=%d, TCPCInit=%d, SrcHiVltg=%d, SrcVBus=%d, VbusDetEn=%d, VBusPrsnt=%d, VConnPrsnt=%d, SnkVBus=%d)", CallerName, params?"Wr":"Rd", "POWER_STATUS_MASK", TCPC_PHY_POWER_STATUS_MASK, pRegs->POWER_STATUS_MASK.R,
                pRegs->POWER_STATUS_MASK.B.DEBUG_ACCESSORY_CONNECTED_STATUS_INT_MASK,
                pRegs->POWER_STATUS_MASK.B.TCPC_INITIALIZATION_STATUS_INT_MASK,
                pRegs->POWER_STATUS_MASK.B.SOURCING_HIGH_VOLTAGE_STATUS_INT_MASK,
                pRegs->POWER_STATUS_MASK.B.SOURCING_VBUS_STATUS_INT_MASK,
                pRegs->POWER_STATUS_MASK.B.VBUS_DETECTION_STATUS_INT_MASK,
                pRegs->POWER_STATUS_MASK.B.VBUS_PRESENT_STATUS_INT_MASK,
                pRegs->POWER_STATUS_MASK.B.VCONN_PRESENT_STATUS_INT_MASK,
                pRegs->POWER_STATUS_MASK.B.SINKING_VBUS_STATUS_INT_MASK
            );
            break;
        case TCPC_PHY_FAULT_STATUS:
            TCPC_PHY_DumpFaultStatus(pRegs->FAULT_STATUS, params, CallerName);
            break;
        case TCPC_PHY_FAULT_STATUS_MASK:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (AllRegDefault=%d, ForceOffVBus=%d, AutoDschrgFailed=%d, ForceDschrgFailed=%d, VBusOCPFault=%d, VBusOVPFault=%d, VConnOCPFailed=%d, I2CErr=%d)", CallerName, params?"Wr":"Rd", "FAULT_STATUS_MASK", TCPC_PHY_FAULT_STATUS_MASK, pRegs->FAULT_STATUS_MASK.R,
                pRegs->FAULT_STATUS_MASK.B.ALLREGISTERSRESETTODEFAULT_INT_MASK,
                pRegs->FAULT_STATUS_MASK.B.FORCE_OFF_VBUS_INT_MASK,
                pRegs->FAULT_STATUS_MASK.B.AUTO_DISCHARGE_FAILED_INT_MASK,
                pRegs->FAULT_STATUS_MASK.B.FORCE_DISCHARGE_FAILED_INT_MASK,
                pRegs->FAULT_STATUS_MASK.B.INTERNAL_OR_EXTERNAL_OCP_VBUS_OVER_CURRENT_PROTECTION_FAULT_INT_MASK,
                pRegs->FAULT_STATUS_MASK.B.INTERNAL_OR_EXTERNAL_OVP_VBUS_OVER_VOLTAGE_PROTECTION_FAULT_INT_MASK,
                pRegs->FAULT_STATUS_MASK.B.VCONN_OVER_CURRENT_FAULT_INT_MASK,
                pRegs->FAULT_STATUS_MASK.B.I2C_INTERFACE_ERROR_INT_MASK
            );
            break;
        case TCPC_PHY_CONFIG_STANDARD_OUTPUT:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (HiImpdOuts=%d, DbgAccCncted#=%d, AudAccCncted#=%d, ActCblCncted=%d, MUXCtrl=%s, ConnPrsnt=%d, ConOrnt=%s)", CallerName, params?"Wr":"Rd", "CONFIG_STANDARD_OUTPUT", TCPC_PHY_CONFIG_STANDARD_OUTPUT, pRegs->CONFIG_STANDARD_OUTPUT.R,
                pRegs->CONFIG_STANDARD_OUTPUT.B.HIGH_IMPEDANCE_OUTPUTS,
                pRegs->CONFIG_STANDARD_OUTPUT.B.DEBUG_ACCESSORY_CONNECTED,
                pRegs->CONFIG_STANDARD_OUTPUT.B.AUDIO_ACCESSORY_CONNECTED,
                pRegs->CONFIG_STANDARD_OUTPUT.B.ACTIVE_CABLE_CONNECTED,
                pRegs->CONFIG_STANDARD_OUTPUT.B.MUX_CONTROL== 0?"No conn":pRegs->CONFIG_STANDARD_OUTPUT.B.MUX_CONTROL==1? "USB3.1 Conctd":pRegs->CONFIG_STANDARD_OUTPUT.B.MUX_CONTROL==2?"DP AltMode – 4 lanes":"USB3.1 + Display Port Lanes 0 & 1",
                pRegs->CONFIG_STANDARD_OUTPUT.B.CONNECTION_PRESENT,
                pRegs->CONFIG_STANDARD_OUTPUT.B.CONNECTOR_ORIENTATION==0?"VCONN to CC2":"VCONN to CC1"
            );
            break;
        case TCPC_PHY_TCPC_CONTROL:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (EnSMBusPEC=%d, EnL4CAlrt=%d, EnWDT=%d, DbgAccCtrl=%s, I2CClkStrch %s, BIST=%d, PlgOrnt=%s)", CallerName, params?"Wr":"Rd", "TCPC_CONTROL", TCPC_PHY_TCPC_CONTROL, pRegs->TCPC_CONTROL.R,
                pRegs->TCPC_CONTROL.B.ENABLE_SMBUS_PEC,
                pRegs->TCPC_CONTROL.B.ENABLE_LOOKING4CONNECTION_ALERT,
                pRegs->TCPC_CONTROL.B.ENABLE_WATCHDOG_TIMER,
                (pRegs->TCPC_CONTROL.B.DEBUG_ACCESSORY_CONTROL == 0)? "by TCPC":"by TCPM",
                (pRegs->TCPC_CONTROL.B.I2C_CLOCK_STRETCHING_CONTROL == 0)? "Dis":(pRegs->TCPC_CONTROL.B.I2C_CLOCK_STRETCHING_CONTROL == 1)? "Rsvd":(pRegs->TCPC_CONTROL.B.I2C_CLOCK_STRETCHING_CONTROL == 2)? "En":"En in no alrt pin",
                pRegs->TCPC_CONTROL.B.BIST_TEST_MODE,
                (pRegs->TCPC_CONTROL.B.PLUG_ORIENTATION == 0)? "VCONN to CC2":"VCONN to CC1"
            );
            break;
        case TCPC_PHY_ROLE_CONTROL:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (DRP=%s, RP_VALUE=%s, CC2=%s, CC1=%s)", CallerName, params?"Wr":"Rd", "ROLE_CONTROL", TCPC_PHY_ROLE_CONTROL, pRegs->ROLE_CONTROL.R,
                (pRegs->ROLE_CONTROL.B.DRP == 0)? "Dis":"En",
                (pRegs->ROLE_CONTROL.B.RP_VALUE == 0)? "Rp default":(pRegs->ROLE_CONTROL.B.RP_VALUE == 1)? "Rp 1.5A":(pRegs->ROLE_CONTROL.B.RP_VALUE == 2)? "Rp 3.0A":"Reserved",
                (pRegs->ROLE_CONTROL.B.CC2 == 0)? "Ra":(pRegs->ROLE_CONTROL.B.CC2 == 1)? "Rp":(pRegs->ROLE_CONTROL.B.CC2 == 2)? "Rd":"Open",
                (pRegs->ROLE_CONTROL.B.CC1 == 0)? "Ra":(pRegs->ROLE_CONTROL.B.CC1 == 1)? "Rp":(pRegs->ROLE_CONTROL.B.CC1 == 2)? "Rd":"Open"
            );
            break;
        case TCPC_PHY_FAULT_CONTROL:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (ForceOffVBUSSigDis=%d, VBUSDschrgFltDetctTimerDis=%d, IntOrExtOCPDis=%d, IntOrExtOVPDis=%d, VConnOVCDis=%d)", CallerName, params?"Wr":"Rd", "FAULT_CONTROL", TCPC_PHY_FAULT_CONTROL, pRegs->FAULT_CONTROL.R,
                pRegs->FAULT_CONTROL.B.FORCE_OFF_VBUS,
                pRegs->FAULT_CONTROL.B.VBUS_DISCHARGE_FAULT_DETECTION_TIMER,
                pRegs->FAULT_CONTROL.B.INTERNAL_OR_EXTERNAL_VBUS_OCP_FAULT,
                pRegs->FAULT_CONTROL.B.INTERNAL_OR_EXTERNAL_VBUS_OVP_FAULT,
                pRegs->FAULT_CONTROL.B.VCONN_OVER_CURRENT_FAULT
            );
            break;
        case TCPC_PHY_POWER_CONTROL:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (FRSEn=%d, VbusVltgMonDis=%d, VltgAlarmDis=%d, AutoDischrgVbusOnDiscnEn=%d, BldDichrgEn=%d, ForceDischrg=%d, VconPrwSupp=%d, VconEn=%d)", CallerName, params?"Wr":"Rd", "POWER_CONTROL", TCPC_PHY_POWER_CONTROL, pRegs->POWER_CONTROL.R,
                pRegs->POWER_CONTROL.B.FAST_ROLE_SWAP_ENABLE,
                pRegs->POWER_CONTROL.B.VBUS_VOLTAGE_MONITOR,
                pRegs->POWER_CONTROL.B.DISABLE_VOLTAGE_ALARMS,
                pRegs->POWER_CONTROL.B.AUTO_DISCHARGE_DISCONNECT,
                pRegs->POWER_CONTROL.B.ENABLE_BLEED_DISCHARGE,
                pRegs->POWER_CONTROL.B.FORCE_DISCHARGE,
                pRegs->POWER_CONTROL.B.VCONN_POWER_SUPPORTED,
                pRegs->POWER_CONTROL.B.ENABLE_VCONN
            );
            break;
        case TCPC_PHY_CC_STATUS:
            if (pRegs->CC_STATUS.B.LOOKING4CONNECTION) {
                DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (L4C=%s, CN_RES=%s, CC2=%s, CC1=%s)", CallerName, params?"Wr":"Rd", "CC_STATUS", TCPC_PHY_CC_STATUS, pRegs->CC_STATUS.R,
                    (pRegs->CC_STATUS.B.LOOKING4CONNECTION == 0)? "No":"Yes",
                    (pRegs->CC_STATUS.B.CONNECTRESULT == 0)? "presenting Rp":"presenting Rd",
                    (pRegs->CC_STATUS.B.CC2_STATE == 0)? "Open":"ERROR, must be zero!",
                    (pRegs->CC_STATUS.B.CC1_STATE == 0)? "Open":"ERROR, must be zero!");
            } else {
                if (pRegs->POWER_CONTROL.B.ENABLE_VCONN == 1) {
                    if (pRegs->TCPC_CONTROL.B.PLUG_ORIENTATION ==0) {
                        DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (L4C=%s, CN_RES=%s, CC2=%s, CC1=%s)", CallerName, params?"Wr":"Rd", "CC_STATUS", TCPC_PHY_CC_STATUS, pRegs->CC_STATUS.R,
                            (pRegs->CC_STATUS.B.LOOKING4CONNECTION == 0)? "No":"Yes",
                            (pRegs->CC_STATUS.B.CONNECTRESULT == 0)? "presenting Rp":"presenting Rd",
                            (pRegs->CC_STATUS.B.CC2_STATE == 0)? "Open":"ERROR, must be zero!",
                            ((pRegs->ROLE_CONTROL.B.CC1 == 1) || (pRegs->CC_STATUS.B.CONNECTRESULT == 0))?
                              (pRegs->CC_STATUS.B.CC1_STATE == 0)? "SRC.Open":(pRegs->CC_STATUS.B.CC1_STATE == 1)? "SRC.Ra":(pRegs->CC_STATUS.B.CC1_STATE == 2)? "SRC.Rd":"rsvd":
                            ((pRegs->ROLE_CONTROL.B.CC1 == 2) || (pRegs->CC_STATUS.B.CONNECTRESULT == 1))?
                                (pRegs->CC_STATUS.B.CC1_STATE == 0)? "SNK.Open":(pRegs->CC_STATUS.B.CC1_STATE == 1)? "SNK.Default":(pRegs->CC_STATUS.B.CC1_STATE == 2)? "SNK.Power1.5":"SNK.Power3.0":
                            (pRegs->CC_STATUS.B.CC1_STATE == 0)? "Open":"ERROR, must be zero!");
                    } else {
                        DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (L4C=%s, CN_RES=%s, CC2=%s, CC1=%s)", CallerName, params?"Wr":"Rd", "CC_STATUS", TCPC_PHY_CC_STATUS, pRegs->CC_STATUS.R,
                            (pRegs->CC_STATUS.B.LOOKING4CONNECTION == 0)? "No":"Yes",
                            (pRegs->CC_STATUS.B.CONNECTRESULT == 0)? "presenting Rp":"presenting Rd",
                            ((pRegs->ROLE_CONTROL.B.CC2 == 1) || (pRegs->CC_STATUS.B.CONNECTRESULT == 0))?
                              (pRegs->CC_STATUS.B.CC2_STATE == 0)? "SRC.Open":(pRegs->CC_STATUS.B.CC2_STATE == 1)? "SRC.Ra":(pRegs->CC_STATUS.B.CC2_STATE == 2)? "SRC.Rd":"rsvd":
                            ((pRegs->ROLE_CONTROL.B.CC2 == 2) || (pRegs->CC_STATUS.B.CONNECTRESULT == 1))?
                                (pRegs->CC_STATUS.B.CC2_STATE == 0)? "SNK.Open":(pRegs->CC_STATUS.B.CC2_STATE == 1)? "SNK.Default":(pRegs->CC_STATUS.B.CC2_STATE == 2)? "SNK.Power1.5":"SNK.Power3.0":
                            (pRegs->CC_STATUS.B.CC2_STATE == 0)? "Open":"ERROR, must be zero!",
                            (pRegs->CC_STATUS.B.CC1_STATE == 0)? "Open":"ERROR, must be zero!");
                    }
                } else {
                    DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (L4C=%s, CN_RES=%s, CC2=%s, CC1=%s)", CallerName, params?"Wr":"Rd", "CC_STATUS", TCPC_PHY_CC_STATUS, pRegs->CC_STATUS.R,
                        (pRegs->CC_STATUS.B.LOOKING4CONNECTION == 0)? "No":"Yes",
                        (pRegs->CC_STATUS.B.CONNECTRESULT == 0)? "presenting Rp":"presenting Rd",
                        ((pRegs->ROLE_CONTROL.B.CC2 == 1) || (pRegs->CC_STATUS.B.CONNECTRESULT == 0))?
                          (pRegs->CC_STATUS.B.CC2_STATE == 0)? "SRC.Open":(pRegs->CC_STATUS.B.CC2_STATE == 1)? "SRC.Ra":(pRegs->CC_STATUS.B.CC2_STATE == 2)? "SRC.Rd":"rsvd":
                        ((pRegs->ROLE_CONTROL.B.CC2 == 2) || (pRegs->CC_STATUS.B.CONNECTRESULT == 1))?
                            (pRegs->CC_STATUS.B.CC2_STATE == 0)? "SNK.Open":(pRegs->CC_STATUS.B.CC2_STATE == 1)? "SNK.Default":(pRegs->CC_STATUS.B.CC2_STATE == 2)? "SNK.Power1.5":"SNK.Power3.0":
                        (pRegs->CC_STATUS.B.CC2_STATE == 0)? "Open":"ERROR, must be zero!",
                        ((pRegs->ROLE_CONTROL.B.CC1 == 1) || (pRegs->CC_STATUS.B.CONNECTRESULT == 0))?
                          (pRegs->CC_STATUS.B.CC1_STATE == 0)? "SRC.Open":(pRegs->CC_STATUS.B.CC1_STATE == 1)? "SRC.Ra":(pRegs->CC_STATUS.B.CC1_STATE == 2)? "SRC.Rd":"rsvd":
                        ((pRegs->ROLE_CONTROL.B.CC1 == 2) || (pRegs->CC_STATUS.B.CONNECTRESULT == 1))?
                            (pRegs->CC_STATUS.B.CC1_STATE == 0)? "SNK.Open":(pRegs->CC_STATUS.B.CC1_STATE == 1)? "SNK.Default":(pRegs->CC_STATUS.B.CC1_STATE == 2)? "SNK.Power1.5":"SNK.Power3.0":
                        (pRegs->CC_STATUS.B.CC1_STATE == 0)? "Open":"ERROR, must be zero!");
                }
            }
            break;
        case TCPC_PHY_COMMAND:
            switch (pRegs->COMMAND.R) {                
                case TCPC_PHY_COMMAND_CMD_WAKEI2C:                         pStr = "WAKEI2C";                     break;
                case TCPC_PHY_COMMAND_CMD_DISABLE_VBUS_DETECT:             pStr = "DISABLE_VBUS_DETECT";         break;
                case TCPC_PHY_COMMAND_CMD_ENABLE_VBUS_DETECT:              pStr = "ENABLE_VBUS_DETECT";          break;
                case TCPC_PHY_COMMAND_CMD_DISABLE_SINK_VBUS:               pStr = "DISABLE_SINK_VBUS";           break;
                case TCPC_PHY_COMMAND_CMD_SINK_VBUS:                       pStr = "SINK_VBUS";                   break;
                case TCPC_PHY_COMMAND_CMD_DISABLE_SOURCE_VBUS:             pStr = "DISABLE_SOURCE_VBUS";         break;
                case TCPC_PHY_COMMAND_CMD_SOURCE_VBUS_DEFAULT_VOLTAGE:     pStr = "SOURCE_VBUS_DEFAULT_VOLTAGE"; break;
                case TCPC_PHY_COMMAND_CMD_SOURCE_VBUS_HIGH_VOLTAGE:        pStr = "SOURCE_VBUS_HIGH_VOLTAGE";    break;
                case TCPC_PHY_COMMAND_CMD_LOOK_4_CONNECTION:               pStr = "LOOK_4_CONNECTION";           break;
                case TCPC_PHY_COMMAND_CMD_RX_ONE_MORE:                     pStr = "RX_ONE_MORE";                 break;
                case TCPC_PHY_COMMAND_CMD_SEND_FRSWAP_SIGNAL:              pStr = "SEND_FRSWAP_SIGNAL";          break;
                case TCPC_PHY_COMMAND_CMD_RESET_TRANSMIT_BUFFER:           pStr = "RESET_TRANSMIT_BUFFER";       break;        
                case TCPC_PHY_COMMAND_CMD_RESET_RECEIVE_BUFFER:            pStr = "RESET_RECEIVE_BUFFER";        break;
                case TCPC_PHY_COMMAND_CMD_I2C_IDLE:                        pStr = "I2C_IDLE";                    break;
                default:
                    pStr = "Unknown command"; break;
            }
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (%s)", CallerName, params?"Wr":"Rd", "COMMAND", TCPC_PHY_COMMAND, pRegs->COMMAND.R, pStr);
            break;            
        case TCPC_PHY_DEV_CAP_1:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value: 0x%04X (VbusHVT=%d, VbusOCP=%d, VbusOVP=%d, BldDischrg=%d, ForceDischrg=%d, VbusMeasrmnt=%d, SrcRes=%s, Roles=%s, SopDbg=%d, SrcVcon=%d, SnkVbus=%d, SrcHiVbus=%d, SrcVbus=%d)", CallerName, params?"Wr":"Rd", "DEV_CAP_1", TCPC_PHY_DEV_CAP_1, pRegs->DEV_CAP_1.R,
                pRegs->DEV_CAP_1.B.VBUS_HIGH_VOLTAGE_TARGET,
                pRegs->DEV_CAP_1.B.VBUS_OCP_REPORTING,
                pRegs->DEV_CAP_1.B.VBUS_OVP_REPORTING,
                pRegs->DEV_CAP_1.B.BLEED_DISCHARGE,
                pRegs->DEV_CAP_1.B.FORCE_DISCHARGE,
                pRegs->DEV_CAP_1.B.VBUS_MEAS_AND_ALARM_CAPABLE,
                pRegs->DEV_CAP_1.B.SRC_RES==0?"Rp def":pRegs->DEV_CAP_1.B.SRC_RES==1?"Rp 1.5A def":pRegs->DEV_CAP_1.B.SRC_RES==2?"Rp 1.5A 3.0 def":"Rsvd",
                pRegs->DEV_CAP_1.B.PWR_ROLES==0?"Src/Snk by TCPM":pRegs->DEV_CAP_1.B.PWR_ROLES==1?"Src":pRegs->DEV_CAP_1.B.PWR_ROLES==2?"Snk":pRegs->DEV_CAP_1.B.PWR_ROLES == 3?"Snk with acc":pRegs->DEV_CAP_1.B.PWR_ROLES==4?"DRP":pRegs->DEV_CAP_1.B.PWR_ROLES==5?"Src, Snk, DRP Adapter/Cable":pRegs->DEV_CAP_1.B.PWR_ROLES==6?"Src, Snk, DRP":"Rsvd",
                pRegs->DEV_CAP_1.B.SOP_DBG_SOP_DBG_SUPPORT,
                pRegs->DEV_CAP_1.B.SOURCE_VCONN,
                pRegs->DEV_CAP_1.B.SINK_VBUS,
                pRegs->DEV_CAP_1.B.SOURCE_HIGH_VOLTAGE_VBUS,
                pRegs->DEV_CAP_1.B.SOURCE_VBUS
                );
            break;
        case TCPC_PHY_DEV_CAP_2:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value: 0x%04X (GenTimer=%d, LongMsg=%d, SMBusPEC=%d, SrcFRSwp=%d, SnkFRSwp=%d, WDT=%d, SnkDiscnDet=%d, StopDischThrld=%d, VBUSVltgAlarmLSB=%s, VCONNPwrSup=%s, VCONOvcFltCapbl=%d", CallerName, params?"Wr":"Rd", "DEV_CAP_2", TCPC_PHY_DEV_CAP_2, pRegs->DEV_CAP_2.R,
                pRegs->DEV_CAP_2.B.GENERIC_TIMER,
                pRegs->DEV_CAP_2.B.LONG_MESSAGE,
                pRegs->DEV_CAP_2.B.SMBUS_PEC,
                pRegs->DEV_CAP_2.B.SOURCE_FR_SWAP,
                pRegs->DEV_CAP_2.B.SINK_FR_SWAP,
                pRegs->DEV_CAP_2.B.WATCHDOG_TIMER,
                pRegs->DEV_CAP_2.B.SINK_DISCONNECT_DETECTION,
                pRegs->DEV_CAP_2.B.STOP_DISCHARGE_THRESHOLD,
                pRegs->DEV_CAP_2.B.VBUS_VOLTAGE_ALARM_LSB==0?"25mV":pRegs->DEV_CAP_2.B.VBUS_VOLTAGE_ALARM_LSB==1?"50mV":pRegs->DEV_CAP_2.B.VBUS_VOLTAGE_ALARM_LSB==2?"100mV":"Reserved",
                pRegs->DEV_CAP_2.B.VCONN_POWER_SUPPORTED==0?"1W":pRegs->DEV_CAP_2.B.VCONN_POWER_SUPPORTED==1?"1.5W":pRegs->DEV_CAP_2.B.VCONN_POWER_SUPPORTED==2?"2W":pRegs->DEV_CAP_2.B.VCONN_POWER_SUPPORTED==3?"3W":pRegs->DEV_CAP_2.B.VCONN_POWER_SUPPORTED==4?"4W":pRegs->DEV_CAP_2.B.VCONN_POWER_SUPPORTED==5?"5W":pRegs->DEV_CAP_2.B.VCONN_POWER_SUPPORTED==6?"6W":"Reserved",
                pRegs->DEV_CAP_2.B.VCONN_OVERCURRENT_FAULT_CAPABLE
                );
            break;
        case TCPC_PHY_STD_INPUT_CAP:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (SrcFstRolSwp=%s, VBUSExtOvrVltgFlt=%d, VBUSExtOvrCrntFlt=%d, ForceOffVBUS=%d)", CallerName, params?"Wr":"Rd", "STD_INPUT_CAP", TCPC_PHY_STD_INPUT_CAP, pRegs->STD_INPUT_CAP.R,
                pRegs->STD_INPUT_CAP.B.SOURCE_FAST_ROLE_SWAP==0?"no":pRegs->STD_INPUT_CAP.B.SOURCE_FAST_ROLE_SWAP==1?"input":pRegs->STD_INPUT_CAP.B.SOURCE_FAST_ROLE_SWAP==2?"In/Out":"Reserved",
                pRegs->STD_INPUT_CAP.B.VBUS_EXTERNAL_OVER_VOLTAGE_FAULT,
                pRegs->STD_INPUT_CAP.B.VBUS_EXTERNAL_OVER_CURRENT_FAULT,
                pRegs->STD_INPUT_CAP.B.FORCE_OFF_VBUS
            );
            break;
        case TCPC_PHY_STD_OUTPUT_CAP:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (VBUSSnkDscnDtctIndic=%d, DbgAccIndic=%d, VBUSPrsntMon=%d, AudioAdptAccIndic=%d, ActCbleIndic=%d, MUXCfgCtrl=%d, ConnectionPrsnt=%d, ConnectorOrient=%d)", CallerName, params?"Wr":"Rd", "STD_OUTPUT_CAP", TCPC_PHY_STD_OUTPUT_CAP, pRegs->STD_OUTPUT_CAP.R,
                pRegs->STD_OUTPUT_CAP.B.VBUS_SINK_DISCONNECT_DETECT_INDICATOR,
                pRegs->STD_OUTPUT_CAP.B.DEBUG_ACCESSORY_INDICATOR,
                pRegs->STD_OUTPUT_CAP.B.VBUS_PRESENT_MONITOR,
                pRegs->STD_OUTPUT_CAP.B.AUDIO_ADAPTER_ACCESSORY_INDICATOR,
                pRegs->STD_OUTPUT_CAP.B.ACTIVE_CABLE_INDICATOR,
                pRegs->STD_OUTPUT_CAP.B.MUX_CONFIGURATION_CONTROL,
                pRegs->STD_OUTPUT_CAP.B.CONNECTION_PRESENT,
                pRegs->STD_OUTPUT_CAP.B.CONNECTOR_ORIENTATION
            );
            break;
        case TCPC_PHY_MESSAGE_HEADER_INFO:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (CablePlug=%s, DataRole=%s, PDSpecRev=%s, PowerRole=%s)", CallerName, params?"Wr":"Rd", "MESSAGE_HEADER_INFO", TCPC_PHY_MESSAGE_HEADER_INFO, pRegs->MESSAGE_HEADER_INFO.R,
                (pRegs->MESSAGE_HEADER_INFO.B.CABLE_PLUG == 0)? "SRC/SNK/DRP":"Cable",
                (pRegs->MESSAGE_HEADER_INFO.B.DATA_ROLE== 0)? "UFP":"DFP",
                (pRegs->MESSAGE_HEADER_INFO.B.USB_PD_SPEC_REV == 0)? "1.0":(pRegs->MESSAGE_HEADER_INFO.B.USB_PD_SPEC_REV == 1)? "2.0'":(pRegs->MESSAGE_HEADER_INFO.B.USB_PD_SPEC_REV == 2)? "3.0":"Rsvd",
                (pRegs->MESSAGE_HEADER_INFO.B.POWER_ROLE== 0)? "SNK":"SRC"
                );
            break;
        case TCPC_PHY_RECEIVE_DETECT:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (EnCblRst=%d, EnHrdRst=%d, EnDBG''=%d, EnDBG'=%d, EnSOP''=%d, EnSOP'=%d, EnSOP=%d)", CallerName, params?"Wr":"Rd", "RECEIVE_DETECT", TCPC_PHY_RECEIVE_DETECT, pRegs->RECEIVE_DETECT.R,
                pRegs->RECEIVE_DETECT.B.ENABLE_CABLE_RESET,
                pRegs->RECEIVE_DETECT.B.ENABLE_HARD_RESET,
                pRegs->RECEIVE_DETECT.B.ENABLE_SOP_DBG_2_MESSAGE,
                pRegs->RECEIVE_DETECT.B.ENABLE_SOP_DBG_1_MESSAGE,
                pRegs->RECEIVE_DETECT.B.ENABLE_SOP_2_MESSAGE,
                pRegs->RECEIVE_DETECT.B.ENABLE_SOP_1_MESSAGE,
                pRegs->RECEIVE_DETECT.B.ENABLE_SOP_MESSAGE
                );
            break;
        case TCPC_PHY_TRANSMIT:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (RetryCnt=%d, Msg=%s)", CallerName, params?"Wr":"Rd", "TRANSMIT", TCPC_PHY_TRANSMIT, pRegs->TRANSMIT.R,
                pRegs->TRANSMIT.B.RETRY_COUNTER,
                TCPC_GetMsgType(pRegs->TRANSMIT.B.MESSAGE)
            );
            break;
        case TCPC_PHY_EXT_CONTROL:
            DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X (BleedDischargeStrength=%d, VCONN Force Discharge=%s)", CallerName, params?"Wr":"Rd", "EXT_CONTROL", TCPC_PHY_EXT_CONTROL, pRegs->EXT_CONTROL.R,
                pRegs->EXT_CONTROL.B.BLEED_DISCHARGE_STRENGTH,
                (pRegs->EXT_CONTROL.B.VCONN_FORCE_DISCHARGE == 0)? "dis":"ena"
            );
            break;
        case TCPC_PHY_TX_BUF_BYTE_X:
            TCPC_PHY_DumpTxBuffer((UCMTCPCI_PORT_CONTROLLER_TRANSMIT_BUFFER*)((void*)&pDevContext->I2C_Buffer.I2C_Cmd.Cmd.RegValue), CallerName);
            break;
        case TCPC_PHY_RX_BUF_BYTE_X:
            TCPC_PHY_DumpRxBuffer((UCMTCPCI_PORT_CONTROLLER_RECEIVE_BUFFER *)(void*)pDevContext->I2C_Buffer.I2C_Cmd.pBuffer, CallerName);
            break;
        default:
            if (Length == 1) {
                DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value:   0x%02X", CallerName, params?"Wr":"Rd", Dbg_GetRegName(RegAddress), RegAddress, *(UINT8*)&(((UINT8*)pRegs)[RegAddress]));
            } else if (Length == 2) {
                DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value: 0x%04X", CallerName, params?"Wr":"Rd", Dbg_GetRegName(RegAddress), RegAddress, *(UINT16*)&(((UINT8*)pRegs)[RegAddress]));
            } else {
                DBG_TCPCI_REG_DUMP("%-30s Reg%s: %-39s(0x%02X), Value: XXX,, Length: %d", CallerName, params?"Wr":"Rd", Dbg_GetRegName(RegAddress), RegAddress, Length);
            }
            break;
    }
}

#define  GET_REGISTER(RegName) {TCPC_PHY_##RegName, (PVOID)&pDevContext->TCPI_PhyRegs.##RegName##, sizeof(TCPC_PHY_##RegName##_t)}

void TCPC_PHY_ReadAllRegs(PDEV_CONTEXT pDevContext, char *Caller) {
    I2C_IO_CMD_t  ReadAllRegs_I2CIOCmd[] = {
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_VENDOR_ID)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_DEVICE_ID)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_USBTYPEC_REV)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_USBPD_REV_VER)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_PD_INTERFACE_REV)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_ALERT)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_ALERT_MASK)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_POWER_STATUS_MASK)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_FAULT_STATUS_MASK)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_EXTENDED_STATUS_MASK)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_ALERT_EXTENDED_MASK)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_CONFIG_STANDARD_OUTPUT)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_TCPC_CONTROL)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_ROLE_CONTROL)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_FAULT_CONTROL)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_POWER_CONTROL)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_CC_STATUS)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_POWER_STATUS)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_FAULT_STATUS)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_EXTENDED_STATUS)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_ALERT_EXTENDED)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_COMMAND)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_DEV_CAP_1)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_DEV_CAP_2)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_STD_INPUT_CAP)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_STD_OUTPUT_CAP)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_CFG_EXT_1)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_GENERIC_TIMER)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_MESSAGE_HEADER_INFO)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_RECEIVE_DETECT)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_RX_BUF_BYTE_X)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_TRANSMIT)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_TX_BUF_BYTE_X)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_VBUS_VOLTAGE)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_VBUS_SINK_DISCONNECT_THRESHOLD)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_VBUS_STOP_DISCHARGE_THRESHOLD)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_VBUS_VOLTAGE_ALARM_HI_CFG)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_VBUS_VOLTAGE_ALARM_LO_CFG)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_VBUS_HV_TARGET)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_EXT_CFG_ID)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_EXT_ALERT)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_EXT_ALERT_MASK)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_EXT_CONFIG)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_EXT_FAULT_CONFIG)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_EXT_CONTROL)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_EXT_STATUS)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_EXT_GPIO_CONFIG)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_EXT_GPIO_CONTROL)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_EXT_GPIO_ALERT_CONFIG)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_EXT_GPIO_STATUS)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_SOURCE_HIGH_VOLTAGE_MB4B_TIME)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_ADC_FILTER_CONTROL_1)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_ADC_FILTER_CONTROL_2)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_VCON_CONFIG)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_VCON_FAULT_DEBOUNCE)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_VCON_FAULT_RECOVERY)},
        {NULL, IMX_EvtDeviceD0Entry_ReadAllRegs, I2C_IO_CMD_RD_REG_SYNC(TCPC_PHY_VCON_FAULT_ATTEMPTS) | I2C_IO_CMD_LAST_CMD}
    };
    I2C_RegsIo(pDevContext, &ReadAllRegs_I2CIOCmd[0]);
}


typedef struct I2C_IO_SOURCE_DESCRIPTION_s {
    char *FullName;
    char *ShortName;
} I2C_IO_SOURCE_DESCRIPTION_t;

I2C_IO_SOURCE_DESCRIPTION_t I2C_IO_SrcDescr[] = {
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_GET_STATUS",                             "GET_STATUS"},                                         /* Idx = 0x00 */
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_GET_CONTROL",                            "GET_CONTROL"},                                        /* Idx = 0x01 */
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_CONTROL",                            "SET_CONTROL"},                                        /* Idx = 0x02 */
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT",                           "SET_TRANSMIT"},                                       /* Idx = 0x03 */
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_BUFFER",                    "SET_TRANSMIT_BUFFER"},                                /* Idx = 0x04 */
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_RECEIVE_DETECT",                     "SET_RECEIVE_DETECT"},                                 /* Idx = 0x05 */
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_CONFIG_STANDARD_OUTPUT",             "SET_CONFIG_STANDARD_OUTPUT"},                         /* Idx = 0x06 */
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_COMMAND",                            "SET_COMMAND"},                                        /* Idx = 0x07 */
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_MESSAGE_HEADER_INFO",                "SET_MESSAGE_HEADER_INFO"},                            /* Idx = 0x08 */
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_ALTERNATE_MODE_ENTERED",                 "ALTERNATE_MODE_ENTERED"},                             /* Idx = 0x09 */
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_ALTERNATE_MODE_EXITED",                  "ALTERNATE_MODE_EXITED"},                              /* Idx = 0x0A */
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_CONFIGURED",                 "DISPLAYPORT_CONFIGURED"},                             /* Idx = 0x0B */
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_HPD_STATUS_CHANGED",         "DISPLAYPORT_HPD_STATUS_CHANGED"},                     /* Idx = 0x0C */
    {"IOCTL_UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_DISPLAY_OUT_STATUS_CHANGED", "DISPLAYPORT_DISPLAY_OUT_STATUS_CHANGED"},             /* Idx = 0x0D */
    {"EvtDeviceD0Entry",                                                      "EvtDeviceD0Entry"},                                   /* Idx = 0x0E */
    {"EvtDeviceD0Entry_DevCapabilities",                                      "EvtDeviceD0Entry_DevCap"},                            /* Idx = 0x0F */
    {"EvtDeviceD0Entry_ReadAllRegs",                                          "EvtDeviceD0Entry_ReadAllRegs"},                       /* Idx = 0x10 */
    {"ISR",                                                                   "ISR"}                                                 /* Idx = 0x11 */
};

const char* Dbg_GetI2CIOSrcName(ULONG i) {
    if (i >= sizeof(I2C_IO_SrcDescr) / sizeof(I2C_IO_SOURCE_DESCRIPTION_t)) {
        DBG_PRINT_ERROR("I21 read/write source index is too big: %d", i);
        return "Index too big";
    }
    return I2C_IO_SrcDescr[i].ShortName;
}
#endif /* DBG_MESSAGE_PRINTING */
