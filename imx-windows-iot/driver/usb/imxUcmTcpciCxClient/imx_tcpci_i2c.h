/*
* This file is derived from Microsoft example available on https://github.com/microsoft/Windows-driver-samples/blob/master/usb/UcmTcpciCxClientSample
* Original file licensing:
* Copyright (c) 2015 Microsoft
* SPDX-License-Identifier: MS-PL
* NXP modifications are licensed under the same license
* Copyright 2020 NXP
*
*/

#pragma once

#define I2C_IO_CMD_DIR_MASK          0x00000001
#define I2C_IO_CMD_DIR_SHIFT         0
        
#define I2C_IO_CMD_REG_SIZE_MASK     0x00000006
#define I2C_IO_CMD_REG_SIZE_SHIFT    1

#define I2C_IO_CMD_REG_LAST_MASK     0x00000008
#define I2C_IO_CMD_REG_LAST_SHIFT    3

#define I2C_IO_CMD_REG_SYNC_MASK     0x00000010
#define I2C_IO_CMD_REG_SYNC_SHIFT    4

#define I2C_IO_CMD_IOCTL_MASK        0x00000020
#define I2C_IO_CMD_IOCTL_SHIFT       5

#define I2C_IO_CMD_ADDRESS_MASK      0x0000FF00
#define I2C_IO_CMD_ADDRESS_SHIFT     8

#define I2C_IO_CMD_VAL8_MASK         0x00FF0000
#define I2C_IO_CMD_VAL8_SHIFT        16
                                 
#define I2C_IO_CMD_VAL16_MASK        0xFFFF0000
#define I2C_IO_CMD_VAL16_SHIFT       16

       
#define I2C_IO_CMD_DIR_RD  1UL
#define I2C_IO_CMD_DIR_WR  0UL

#define I2C_IO_CMD_SIZE_X   0UL
#define I2C_IO_CMD_SIZE_1   1UL
#define I2C_IO_CMD_SIZE_2   2UL

#define I2C_IO_CMD_LAST_CMD  I2C_IO_CMD_REG_LAST_MASK


#define I2C_IO_CMD_RD_REG(_RegAddr)             (((I2C_IO_CMD_DIR_RD    << I2C_IO_CMD_DIR_SHIFT )     & I2C_IO_CMD_DIR_MASK)      | \
                                                 ((sizeof(_RegAddr##_t) << I2C_IO_CMD_REG_SIZE_SHIFT) & I2C_IO_CMD_REG_SIZE_MASK) | \
                                                 ((##_RegAddr           << I2C_IO_CMD_ADDRESS_SHIFT)  & I2C_IO_CMD_ADDRESS_MASK)    \
                                                )
#define I2C_IO_CMD_WR_REG(_RegAddr,_RegVal)     (((I2C_IO_CMD_DIR_WR    << I2C_IO_CMD_DIR_SHIFT )     & I2C_IO_CMD_DIR_MASK)      | \
                                                 ((sizeof(_RegAddr##_t) << I2C_IO_CMD_REG_SIZE_SHIFT) & I2C_IO_CMD_REG_SIZE_MASK) | \
                                                 ((_RegAddr             << I2C_IO_CMD_ADDRESS_SHIFT)  & I2C_IO_CMD_ADDRESS_MASK)  | \
                                                 ((_RegVal              << I2C_IO_CMD_VAL8_SHIFT)     & I2C_IO_CMD_VAL16_MASK)     \
                                                )
#define I2C_IO_CMD_WR_BUF(_RegAddr, _BuffSize)  (((I2C_IO_CMD_DIR_WR    << I2C_IO_CMD_DIR_SHIFT )     & I2C_IO_CMD_DIR_MASK)      | \
                                                 ((I2C_IO_CMD_SIZE_X    << I2C_IO_CMD_REG_SIZE_SHIFT) & I2C_IO_CMD_REG_SIZE_MASK) | \
                                                 ((_RegAddr             << I2C_IO_CMD_ADDRESS_SHIFT)  & I2C_IO_CMD_ADDRESS_MASK)  | \
                                                 (((_BuffSize)          << I2C_IO_CMD_VAL8_SHIFT)     & I2C_IO_CMD_VAL16_MASK)      \
                                                )
#define I2C_IO_CMD_RD_BUF(_RegAddr, _BuffSize)  (((I2C_IO_CMD_DIR_RD    << I2C_IO_CMD_DIR_SHIFT )     & I2C_IO_CMD_DIR_MASK)      | \
                                                 ((I2C_IO_CMD_SIZE_X    << I2C_IO_CMD_REG_SIZE_SHIFT) & I2C_IO_CMD_REG_SIZE_MASK) | \
                                                 ((_RegAddr             << I2C_IO_CMD_ADDRESS_SHIFT)  & I2C_IO_CMD_ADDRESS_MASK)  | \
                                                 (((_BuffSize)          << I2C_IO_CMD_VAL8_SHIFT)     & I2C_IO_CMD_VAL16_MASK)      \
                                                )

#define I2C_IO_CMD_RD_REG_SYNC(_RegAddr)             (I2C_IO_CMD_RD_REG(##_RegAddr)            | I2C_IO_CMD_REG_SYNC_MASK)
#define I2C_IO_CMD_RD_BUF_SYNC(_RegAddr, _BuffSize)  (I2C_IO_CMD_RD_BUF(##_RegAddr, _BuffSize) | I2C_IO_CMD_REG_SYNC_MASK)
#define I2C_IO_CMD_WR_REG_SYNC(_RegAddr,_RegVal)     (I2C_IO_CMD_WR_REG(##_RegAddr, _RegVal)   | I2C_IO_CMD_REG_SYNC_MASK)

#define I2C_IO_CMD_RD_REG_IOCTL(_RegAddr)            (I2C_IO_CMD_RD_REG(##_RegAddr)            | I2C_IO_CMD_IOCTL_MASK)
#define I2C_IO_CMD_RD_BUF_IOCTL(_RegAddr, _BuffSize) (I2C_IO_CMD_RD_BUF(##_RegAddr, _BuffSize) | I2C_IO_CMD_IOCTL_MASK)
#define I2C_IO_CMD_WR_REG_IOCTL(_RegAddr,_RegVal)    (I2C_IO_CMD_WR_REG(##_RegAddr, _RegVal)   | I2C_IO_CMD_IOCTL_MASK)
#define I2C_IO_CMD_WR_BUF_IOCTL(_RegAddr, _BuffSize) (I2C_IO_CMD_WR_BUF(##_RegAddr, _BuffSize) | I2C_IO_CMD_IOCTL_MASK)

#define RdRegSync(_RegAddr, _pBuff,  _IOSrcIdx)            I2C_RegsIo(pDevContext, &(I2C_Cmd = {_pBuff, _IOSrcIdx, I2C_IO_CMD_RD_REG(##_RegAddr)            | I2C_IO_CMD_REG_SYNC_MASK | I2C_IO_CMD_LAST_CMD}))
#define RdBufSync(_RegAddr, _pBuff,  _BuffSize, _IOSrcIdx) I2C_RegsIo(pDevContext, &(I2C_Cmd = {_pBuff, _IOSrcIdx, I2C_IO_CMD_RD_BUF(##_RegAddr, _BuffSize) | I2C_IO_CMD_REG_SYNC_MASK | I2C_IO_CMD_LAST_CMD}))
#define WrRegSync(_RegAddr, _RegVal, _IOSrcIdx)            I2C_RegsIo(pDevContext, &(I2C_Cmd = {NULL,   _IOSrcIdx, I2C_IO_CMD_WR_REG(##_RegAddr, _RegVal)   | I2C_IO_CMD_REG_SYNC_MASK | I2C_IO_CMD_LAST_CMD}))


/*
Wr(RegAddr, RegSize, Value)                                                Rd(RegAddr, RegSize, Value)
                                |----------------------------------------|
                                |           pBuffer (8 bytes)            |
                                |----------------------------------------|
                                |          IOSrcIdx (4 bytes)            |
                                |----------------------------------------|
                                |           CmdCode (1 byte)             |
                                |----------------------------------------|
Tx_TrList[0].pBuff -----------> |           RegAddr (1 byte)             | <----- Rx_TrList[0].pBuff, Rx_TrList[0]..Size = 1
Tx_TrList[0].Size = RegSize + 1 |----------------------------------------| 
                  \             | Reg value / Buffer size (low, 1 byte)  | <----- Rx_TrList[1].pBuff, Rx_TrList[1]..Size = RegSize
                   \            |----------------------------------------|                                              /
                    \           | Reg value / Buffer size (high, 1 byte) |                                             /
                     \__________|----------------------------------------|____________________________________________/
*/
typedef struct _DEV_CONTEXT DEV_CONTEXT, *PDEV_CONTEXT;

typedef struct _I2C_IO_CMD_t {
    VOID            *pBuffer; 
    UINT32           IOSrcIdx;
    union {
        UINT32       CmdCode;
        struct {
            UINT8    Read         :   1; /* Bit      0, IO direction, 1 = read, 0 = write                              */
            UINT8    RegSize      :   2; /* Bit      1, Size, 0 = buffer, 1 = one byte, 2 = two bytes, 3 = four bytes  */
            UINT8    LastCmd      :   1; /* Bit      3, 1 = last command in sequence                                   */
            UINT8    SyncCmd      :   1; /* Bit      4, 1 = send synchronously                                         */
            UINT8    Ioctl        :   1; /* Bit      5, 1 = this I/O is part of IOCTL request                          */
            UINT8    Reserved     :   2; /* Bits     7, Reserved                                                       */
            UINT8    RegAddress;         /* Bits  8-15, Register address                                               */
            union {
                UINT16   RegValue;       /* Bit  16-31, Register value LOW or Buffer size LOW                          */
                UINT16   BufferSize;     /* Bit  16-31, Register value HIGH or Buffer size HIGH                        */
            };
        } Cmd;
    };
} I2C_IO_CMD_t;

C_ASSERT(sizeof(I2C_IO_CMD_t) == 16);

EXTERN_C_START

NTSTATUS IO_Initialize            (_In_ PDEV_CONTEXT pDevContext, _In_ WDFCMRESLIST hResourcesRaw, _In_ WDFCMRESLIST hResourcesTranslated);
NTSTATUS GPIO_Open                (_In_ PDEV_CONTEXT pDevContext);
void     GPIO_Close               (_In_ PDEV_CONTEXT pDevContext);
NTSTATUS GPIO_PlugOrientation_Set (_In_ PDEV_CONTEXT pDevContext,  _In_ TCPC_PHY_TCPC_CONTROL_t TCPC_CONTROL);
NTSTATUS I2C_Open                 (_In_ PDEV_CONTEXT pDevContext);
void     I2C_Close                (_In_ PDEV_CONTEXT pDevContext);
NTSTATUS I2C_PrepareI2CRequest    (_In_ DEV_CONTEXT *pDevContext, _In_ I2C_IO_CMD_t I2C_Cmd);
NTSTATUS I2C_RegsIo               (_In_ DEV_CONTEXT *pDevContext, _In_ I2C_IO_CMD_t *pI2C_Cmd);
NTSTATUS I2C_IOCTL                (_In_ DEV_CONTEXT *pDevContext, _In_ I2C_IO_CMD_t *pI2C_Cmd);

EXTERN_C_END