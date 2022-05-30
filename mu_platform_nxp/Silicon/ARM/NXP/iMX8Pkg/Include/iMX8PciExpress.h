/** @file
*
*  Copyright (c) Microsoft Corporation. All rights reserved.
*  Copyright 2019-2020 NXP
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/

#pragma once

#ifndef ARRAYSIZE
#define ARRAYSIZE(__array__) (sizeof((__array__))/sizeof((__array__[0])))
#endif

// Set to 1 for PCIe driver debug print enable
#define PCIE_DEBUG              0

#if PCIE_DEBUG
  #define PCIE_DEBUG_PRINT(TYPE,OUT,...) DebugPrint(TYPE, "iMX8PCIe: " OUT, ##__VA_ARGS__)
#else
  #define PCIE_DEBUG_PRINT(TYPE,OUT,...)
#endif

// Print macro
#define PCIE_INIT(PRINT_OUT, ...) \
    PCIE_DEBUG_PRINT(DEBUG_INIT, PRINT_OUT, ##__VA_ARGS__)
#define PCIE_INFO(PRINT_OUT, ...) \
    PCIE_DEBUG_PRINT(DEBUG_INFO, PRINT_OUT, ##__VA_ARGS__)
#define PCIE_WARNING(PRINT_OUT, ...) \
    PCIE_DEBUG_PRINT(DEBUG_WARN, PRINT_OUT, ##__VA_ARGS__)
#define PCIE_ERROR(PRINT_OUT, ...) \
    PCIE_DEBUG_PRINT(DEBUG_ERROR, PRINT_OUT, ##__VA_ARGS__)

// PCIe related base address
#define PCIE1_HOST_CONFIG_BASE_REG       FixedPcdGet64(PcdPcie1ControlBaseAddress)
#define PCIE1_DEVICE_MEMORY_SPACE_BASE   FixedPcdGet64(PcdPcie1DeviceMemoryBase)
#define PCIE1_DEVICE_MEMORY_SPACE_SIZE   FixedPcdGet64(PcdPcie1DeviceMemorySize)
#define PCIE1_DEVICE_CONFIG0_BASE_REG    FixedPcdGet64(PcdPcie1DeviceConfig0Base)
#define PCIE1_DEVICE_CONFIG0_SIZE        FixedPcdGet64(PcdPcie1DeviceConfig0Size)
#define PCIE1_DEVICE_CONFIG1_BASE_REG    FixedPcdGet64(PcdPcie1DeviceConfig1Base)
#define PCIE1_DEVICE_CONFIG1_SIZE        FixedPcdGet64(PcdPcie1DeviceConfig1Size)
#define PCIE2_HOST_CONFIG_BASE_REG       FixedPcdGet64(PcdPcie2ControlBaseAddress)
#define PCIE2_DEVICE_MEMORY_SPACE_BASE   FixedPcdGet64(PcdPcie2DeviceMemoryBase)
#define PCIE2_DEVICE_MEMORY_SPACE_SIZE   FixedPcdGet64(PcdPcie2DeviceMemorySize)
#define PCIE2_DEVICE_CONFIG0_BASE_REG    FixedPcdGet64(PcdPcie2DeviceConfig0Base)
#define PCIE2_DEVICE_CONFIG0_SIZE        FixedPcdGet64(PcdPcie2DeviceConfig0Size)
#define PCIE2_DEVICE_CONFIG1_BASE_REG    FixedPcdGet64(PcdPcie2DeviceConfig1Base)
#define PCIE2_DEVICE_CONFIG1_SIZE        FixedPcdGet64(PcdPcie2DeviceConfig1Size)

#pragma pack(push, 1)

typedef struct {
  UINT64 Base;
  UINT64 Size;
  UINT64 Curr;
} PCI_RESOURCE;

// Debug register related bits
#define PCIE_PL_DEBUG1_PHY_LINK_UP          (1 << 4)
#define PCIE_PL_DEBUG1_LINK_IN_TRAINING     (1 << 29)

// Address Translation Unit related definition
#define MAX_iATU_REGION          4

typedef enum _REGION_DIRECTION {
  OUTBOUND,
  INBOUND,
} REGION_DIRECTION;

typedef enum _TLP_TYPE {
  MEMORY_TYPE,
  MEMORY_LOCK_TYPE,
  IO_TYPE,
  CFG0_TYPE = 4,
  CFG1_TYPE = 5,
} TLP_TYPE;

typedef enum _REGION_STATE {
  REGION_DISABLE = 0,
  REGION_ENABLE = 0x80000000,
  REGION_CFG_SHIFT_ENABLE = 0x90000000,
} REGION_STATE;

typedef struct _IATU_SETTINGS {
  UINT32 RegionDirection;
  UINT32 RegionIndex;
  TLP_TYPE Type;
  UINT32 LowerBaseAddr;
  UINT32 UpperBaseAddr;
  UINT32 LimitAddr;
  UINT32 LowerTargetAddr;
  UINT32 UpperTargetAddr;
  UINT32 State;
} IATU_SETTINGS, *PIATU_SETTINGS;

#pragma pack(pop)
