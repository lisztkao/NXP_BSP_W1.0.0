/** @file
*
*  Copyright (c) 2018 Microsoft Corporation. All rights reserved.
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

#include <IndustryStandard/Pci.h>

#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/TimerLib.h>

#include <Protocol/PciIo.h>
#include <Protocol/PciRootBridgeIo.h>

#include <iMX8.h>
#include <iMXGpio.h> 
#include <iMX8PciExpress.h>
#if defined(CPU_IMX8MQ)
  #include <iMX8MQPciExpress.h>
#endif

/* Definition type of PCIe device data structure */
typedef struct _PCIE_DEVICE_DATA {
  BOOLEAN               PcieEnable;
  UINT32                PcieIndex;
  BOOLEAN               PcieInternalRefClock;
  UINT32                PcieMaxLinkSpeed;
  PCIE_MemMapPtr        PcieMemMap;
  PCIE_PHY_MemMapPtr    PciePhyMemMap;
  UINT64                PcieHostConfigBaseReg;
  UINT64                PcieDeviceConfig0BaseReg;
  UINT64                PcieDeviceConfig1BaseReg;
  UINTN                 MaxScanBusNumber;
  UINTN                 MaxBusNumber;
  PCI_RESOURCE          PcieResource;           /* PCIe memory resources */
  /*
   * Internal Address Translation Unit configuration table. Map the Pcie device
   * configuration baesd on configuration. Pci IO space is not supported on
   * Windows. Memory space segment is just mapped back to the same address.
   *
   * The following table is used to setup basic translation setting on various
   * ATU (Address Translation Unit). The ATU is responsible to retranslate
   * address for inbound and outbound message.
   *
   * Address match mode address translation is based on the following formula :
   *    Address = Address - Base Address + Target Address
   *
   * There really isnt a need to retranslate the address for iMX6 however proceed
   * the program the ATU to for configuration and memory message. */
  IATU_SETTINGS         iAtuSettings[3];
  /* GPIO nRESET PAD configuration */
  UINT32                PcieResetGpio;
  UINT32                PcieResetGpioBankNumber;
  UINT32                PcieResetGpioIoNumber;
} PCIE_DEVICE_DATA, *pPCIE_DEVICE_DATA;

/* Intitlize PCIe device data structure */
PCIE_DEVICE_DATA PcieDeviceData[] = {
  {
    .PcieEnable    = FixedPcdGet32(PcdPcie1Enable),
    .PcieIndex     = 0,
    .PcieInternalRefClock = FixedPcdGet32(PcdPcie1InternalRefClock),
    .PcieMaxLinkSpeed = FixedPcdGet32(PcdPcie1MaxLinkSpeed),
#if defined(CPU_IMX8MM)
    .PcieMemMap    = PCIE1_BASE_PTR,
    .PciePhyMemMap = PCIE_PHY_BASE_PTR,
#elif defined(CPU_IMX8MQ)
    .PcieMemMap    = PCIE0_BASE_PTR,
    .PciePhyMemMap = PCIE_PHY0_BASE_PTR,
#endif
    .PcieHostConfigBaseReg = PCIE1_HOST_CONFIG_BASE_REG,
    .PcieDeviceConfig0BaseReg = PCIE1_DEVICE_CONFIG0_BASE_REG,
    .PcieDeviceConfig1BaseReg = PCIE1_DEVICE_CONFIG1_BASE_REG,
#if FixedPcdGet32(PcdPcie1SwitchSupport)
    .MaxBusNumber = ((PCIE1_DEVICE_CONFIG1_SIZE >> 20) - 1),
#else
    .MaxBusNumber = 1,
#endif
    .PcieResource = // Memory resource
                    {
                      PCIE1_DEVICE_MEMORY_SPACE_BASE,
                      PCIE1_DEVICE_MEMORY_SPACE_SIZE,
                      PCIE1_DEVICE_MEMORY_SPACE_BASE,
                    },
    .iAtuSettings = {
                      // Configuration 0 message
                      {
                        .RegionDirection = OUTBOUND,
                        .RegionIndex = 0,
                        .Type = CFG0_TYPE,
                        .LowerBaseAddr = PCIE1_DEVICE_CONFIG0_BASE_REG,
                        .UpperBaseAddr = 0,
                        .LimitAddr = (PCIE1_DEVICE_CONFIG0_BASE_REG + PCIE1_DEVICE_CONFIG0_SIZE - 1),
                        .LowerTargetAddr = 0,
                        .UpperTargetAddr = 0,
                        .State = REGION_ENABLE,
                      },
                      // Configuration 1 message
                      {
                        .RegionDirection = OUTBOUND,
                        .RegionIndex = 1,
                        .Type = CFG1_TYPE,
                        .LowerBaseAddr = 0,
                        .UpperBaseAddr = 0,
                        .LimitAddr = (PCIE1_DEVICE_CONFIG1_BASE_REG + PCIE1_DEVICE_CONFIG1_SIZE - 1),
                        .LowerTargetAddr = 0,
                        .UpperTargetAddr = 0,
#if FixedPcdGet32(PcdPcie1SwitchSupport)
                        .State = REGION_CFG_SHIFT_ENABLE,
#else
                        .State = REGION_DISABLE,
#endif
                      },
                      // Memory message
                      {
                        .RegionDirection = OUTBOUND,
                        .RegionIndex = 2,
                        .Type = MEMORY_TYPE,
                        .LowerBaseAddr = PCIE1_DEVICE_MEMORY_SPACE_BASE,
                        .UpperBaseAddr = 0,
                        .LimitAddr = (PCIE1_DEVICE_MEMORY_SPACE_BASE + PCIE1_DEVICE_MEMORY_SPACE_SIZE - 1),
                        .LowerTargetAddr = PCIE1_DEVICE_MEMORY_SPACE_BASE,
                        .UpperTargetAddr = 0,
                        .State = REGION_ENABLE,
                      },
                    },
    .PcieResetGpio = FixedPcdGet32 (PcdPcie1ResetGpio),
    .PcieResetGpioBankNumber = FixedPcdGet32 (PcdPcie1ResetGpioBankNumber),
    .PcieResetGpioIoNumber = FixedPcdGet32 (PcdPcie1ResetGpioIoNumber),
  },
#if defined(CPU_IMX8MQ)
  {
    .PcieEnable    = FixedPcdGet32(PcdPcie2Enable),
    .PcieIndex     = 1,
    .PcieInternalRefClock = FixedPcdGet32 (PcdPcie2InternalRefClock),
    .PcieMaxLinkSpeed = FixedPcdGet32(PcdPcie2MaxLinkSpeed),
    .PcieMemMap    = PCIE1_BASE_PTR,
    .PciePhyMemMap = PCIE_PHY1_BASE_PTR,
    .PcieHostConfigBaseReg = PCIE2_HOST_CONFIG_BASE_REG,
    .PcieDeviceConfig0BaseReg = PCIE2_DEVICE_CONFIG0_BASE_REG,
    .PcieDeviceConfig1BaseReg = PCIE2_DEVICE_CONFIG1_BASE_REG,
#if FixedPcdGet32(PcdPcie2SwitchSupport)
    .MaxBusNumber = ((PCIE2_DEVICE_CONFIG1_SIZE >> 20) - 1),
#else
    .MaxBusNumber = 1,
#endif
    .PcieResource = // Memory resource
                    {
                      PCIE2_DEVICE_MEMORY_SPACE_BASE,
                      PCIE2_DEVICE_MEMORY_SPACE_SIZE,
                      PCIE2_DEVICE_MEMORY_SPACE_BASE,
                    },
    .iAtuSettings = {
                      // Configuration 0 message
                      {
                        .RegionDirection = OUTBOUND,
                        .RegionIndex = 0,
                        .Type = CFG0_TYPE,
                        .LowerBaseAddr = PCIE2_DEVICE_CONFIG0_BASE_REG,
                        .UpperBaseAddr = 0,
                        .LimitAddr = (PCIE2_DEVICE_CONFIG0_BASE_REG + PCIE2_DEVICE_CONFIG0_SIZE - 1),
                        .LowerTargetAddr = 0,
                        .UpperTargetAddr = 0,
                        .State = REGION_ENABLE,
                      },
                      // Configuration 1 message
                      {
                        .RegionDirection = OUTBOUND,
                        .RegionIndex = 1,
                        .Type = CFG1_TYPE,
                        .LowerBaseAddr = 0,
                        .UpperBaseAddr = 0,
                        .LimitAddr = (PCIE2_DEVICE_CONFIG1_BASE_REG + PCIE2_DEVICE_CONFIG1_SIZE - 1),
                        .LowerTargetAddr = 0,
                        .UpperTargetAddr = 0,
#if FixedPcdGet32(PcdPcie2SwitchSupport)
                        .State = REGION_CFG_SHIFT_ENABLE,
#else
                        .State = REGION_DISABLE,
#endif
                      },
                      // Memory message
                      {
                        .RegionDirection = OUTBOUND,
                        .RegionIndex = 2,
                        .Type = MEMORY_TYPE,
                        .LowerBaseAddr = PCIE2_DEVICE_MEMORY_SPACE_BASE,
                        .UpperBaseAddr = 0,
                        .LimitAddr = (PCIE2_DEVICE_MEMORY_SPACE_BASE + PCIE2_DEVICE_MEMORY_SPACE_SIZE - 1),
                        .LowerTargetAddr = PCIE2_DEVICE_MEMORY_SPACE_BASE,
                        .UpperTargetAddr = 0,
                        .State = REGION_ENABLE,
                      },
                    },
    .PcieResetGpio = FixedPcdGet32 (PcdPcie2ResetGpio),
    .PcieResetGpioBankNumber = FixedPcdGet32 (PcdPcie2ResetGpioBankNumber),
    .PcieResetGpioIoNumber = FixedPcdGet32 (PcdPcie2ResetGpioIoNumber),
  }
#endif
};

// Pcie read and write function
EFI_STATUS
PciePciWrite (
               IN EFI_PCI_IO_PROTOCOL_WIDTH Width,
               IN UINTN Address,
               IN UINTN Count,
               IN VOID *Buffer
             );

EFI_STATUS PciePciRead (
                        IN EFI_PCI_IO_PROTOCOL_WIDTH Width,
                        IN UINTN Address,
                        IN UINTN Count,
                        IN VOID *Buffer
                       );

VOID PcieSetupiAtu (
                     IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr,
                     IN  IATU_SETTINGS    *SettingsPtr
                   )
{
  UINT32 i, val32;
  PCIE_MemMapPtr iATU_PTR = (PCIE_MemMapPtr)(PcieDeviceDataPtr->PcieHostConfigBaseReg +
                             (0x200 * SettingsPtr->RegionIndex));

  ASSERT (SettingsPtr->RegionIndex < MAX_iATU_REGION);

  // only OUTBOUND configuration supported currently
  ASSERT (SettingsPtr->RegionDirection == OUTBOUND);
  if (SettingsPtr->RegionDirection == OUTBOUND) {
    /* Disable region address translation */
    PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_REG(iATU_PTR) = 0x00;

    /* Set start address of the address region to be translated - PCI side */
    PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_REG(iATU_PTR) =
                  SettingsPtr->LimitAddr;
    PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_REG(iATU_PTR) =
                  SettingsPtr->LowerTargetAddr;
    PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_REG(iATU_PTR) =
                  SettingsPtr->UpperTargetAddr;
    /* Set start address of the address region to be translated - CPU side */
    PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_REG(iATU_PTR) =
                  SettingsPtr->LowerBaseAddr;
    PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_REG(iATU_PTR) =
                  SettingsPtr->UpperBaseAddr;

    /* Set TLP type */
    PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_REG(iATU_PTR) =
                  SettingsPtr->Type;
    /* Enable region address translation */
    PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_REG(iATU_PTR) = SettingsPtr->State;

    /* Wait for iATU enable */
    for (i = 0; i < 100; i++) {
      val32 = PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_REG(iATU_PTR);
      if (val32 & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_REGION_EN_MASK) {
        break;
      }
    }
  }
}

VOID PcieSetupiAtuSettings (
                            IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr
                           )
{
  UINT32 i;

  // Initialize internal Address Translation Unit based on settings specify
  // in iAtuSettings table.
  for (i = 0; i < ARRAYSIZE (PcieDeviceDataPtr->iAtuSettings); ++i) {
    PcieSetupiAtu (PcieDeviceDataPtr, &PcieDeviceDataPtr->iAtuSettings[i]);
  }

  return;
}

EFI_STATUS PcieSetPhyState (
                             IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr,
                             IN  BOOLEAN          State
                           )
{
#if defined(CPU_IMX8MM)
  UINT32        val32, Idx;
#endif
  SRC_MemMapPtr SrcBasePtr = ((PcieDeviceDataPtr->PcieIndex == 0) ? SRC_BASE_PTR :
                             (SRC_MemMapPtr)((UINT64)SRC_BASE_PTR + 0x1C));
  UINT32        IomuxGprIdx = ((PcieDeviceDataPtr->PcieIndex == 0) ? 14 : 16); /* Use GPR14 for PCIe0, GPR16 for PCIe1 */

  if (State == TRUE) {
    /* Enable ref. clock */
    IOMUXC_GPR_GPR_REG(IOMUXC_GPR_BASE_PTR, IomuxGprIdx) &=
                                ~(IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_MASK);
    IOMUXC_GPR_GPR_REG(IOMUXC_GPR_BASE_PTR, IomuxGprIdx) |=
                                IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_EN_MASK;
    /* Wait to clock stabilize */
    MicroSecondDelay(10000);
    /* Deassert PCIe core reset */
    SRC_PCIEPHY_RCR_REG(SrcBasePtr) = ((SRC_PCIEPHY_RCR_REG(SrcBasePtr) & ~(0x04)) |
                                        SRC_PCIEPHY_RCR_DOM_EN_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN3_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN2_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN1_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN0_MASK);
    SRC_PCIEPHY_RCR_REG(SrcBasePtr) = ((SRC_PCIEPHY_RCR_REG(SrcBasePtr) & ~(0x02)) |
                                        SRC_PCIEPHY_RCR_DOM_EN_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN3_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN2_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN1_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN0_MASK);
#if defined(CPU_IMX8MM)
    /* Wait for PHy PLL lock done */
    for (Idx = 0; Idx < 100; Idx++) {
      val32 = PCIE_PHY_CMN_REG075;
      if (val32 == (PCIE_PHY_CMN_REG075_ANA_PLL_LOCK_DONE_MASK | PCIE_PHY_CMN_REG075_ANA_PLL_AFC_DONE_MASK)) {
          break;
      }
      MicroSecondDelay(10000);
    }
    if (val32 != (PCIE_PHY_CMN_REG075_ANA_PLL_LOCK_DONE_MASK | PCIE_PHY_CMN_REG075_ANA_PLL_AFC_DONE_MASK)) {
      PCIE_ERROR("%s: PCIe%d PHy PLL is not locked!\n", __func__, PcieDeviceDataPtr->PcieIndex);
      return EFI_DEVICE_ERROR;
    }
#endif
    SRC_PCIEPHY_RCR_REG(SrcBasePtr) |= SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_CLK_REQ_MASK;
    SRC_PCIEPHY_RCR_REG(SrcBasePtr) = ((SRC_PCIEPHY_RCR_REG(SrcBasePtr) & ~(SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_EN_MASK)) |
                                        SRC_PCIEPHY_RCR_DOM_EN_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN3_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN2_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN1_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN0_MASK);
  } else {
    /* Assert PCIe core reset */
    SRC_PCIEPHY_RCR_REG(SrcBasePtr) |= (0x04 |
                                        SRC_PCIEPHY_RCR_DOM_EN_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN3_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN2_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN1_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN0_MASK);
    SRC_PCIEPHY_RCR_REG(SrcBasePtr) |= (0x02 |
                                        SRC_PCIEPHY_RCR_DOM_EN_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN3_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN2_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN1_MASK |
                                        SRC_PCIEPHY_RCR_DOMAIN0_MASK);
  }

  return EFI_SUCCESS;
}

EFI_STATUS PcieSetupInitSetting (
                                 IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr
                                )
{
  EFI_STATUS            Status;
  UINT32                val32, Idx;
  UINT32                shift_offset = ((PcieDeviceDataPtr->PcieIndex == 0) ? 0 : 12);

  /* Disable the PHY first */
  Status = PcieSetPhyState (PcieDeviceDataPtr, FALSE);
  if (EFI_ERROR (Status)) {
    PCIE_ERROR("Failed to disable Pcie PHY\n");
    goto Exit;
  }

  GPC_PGC_CPU_0_1_MAPPING |= (GPC_PGC_CPU_0_1_MAPPING_PCIE_A53_DOMAIN_MASK << shift_offset);

  /* Power up PCIe domain */
  GPC_PU_PGC_SW_PUP_REQ |= (GPC_PU_PGC_SW_PUP_REQ_PCIE_SW_PUP_REQ_MASK << shift_offset);
  for (Idx = 0; Idx < 100; Idx++) {
    val32 = GPC_PU_PGC_SW_PUP_REQ;
    if ((val32 & (GPC_PU_PGC_SW_PUP_REQ_PCIE_SW_PUP_REQ_MASK << shift_offset)) == 0U) {
      break;
    }
    MicroSecondDelay(1000);
  }
  if ((val32 & (GPC_PU_PGC_SW_PUP_REQ_PCIE_SW_PUP_REQ_MASK << shift_offset)) != 0U) {
    PCIE_ERROR("%s: PCIe%d PHy power up failed!", __func__, PcieDeviceDataPtr->PcieIndex);
    Status = EFI_DEVICE_ERROR;
    goto Exit;
  }

  if (PcieDeviceDataPtr->PcieInternalRefClock) {
    PCIE_INFO("PCIe%d configured with internal reference clock.\n", PcieDeviceDataPtr->PcieIndex);
#if defined(CPU_IMX8MM)
    IOMUXC_GPR_GPR14 &= ~(IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_I_AUX_EN_OVERRIDE_EN_MASK);
    /* Selects reference clock from SOC PLL (pll_refclk_from_syspll) */
    IOMUXC_GPR_GPR14 = ((IOMUXC_GPR_GPR14 & ~(IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_PLL_REF_CLK_SEL_MASK)) |
                        IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_PLL_REF_CLK_SEL(0x03));
    IOMUXC_GPR_GPR14 |= IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_AUX_EN_MASK;
    IOMUXC_GPR_GPR14 &= ~(IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_POWER_OFF_MASK);
    IOMUXC_GPR_GPR14 &= ~(IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_SSC_EN_MASK);
    /* Use internal reference clock (PLL) */
    IOMUXC_GPR_GPR14 = ((IOMUXC_GPR_GPR14 & ~(IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_PLL_REF_CLK_SEL_MASK)) |
                        IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_PLL_REF_CLK_SEL(0x03));
    MicroSecondDelay(1000);
    /* Configure PHy */
    /* Reference clock bypass (for MPHY) */
    PCIE_PHY_CMN_REG062 = PCIE_PHY_CMN_REG062_ANA_PLL_CLK_OUT_TO_EXT_IO_SEL_MASK;
    PCIE_PHY_CMN_REG064 = (PCIE_PHY_CMN_REG064_ANA_AUX_RX_TX_SEL_MASK |
                          PCIE_PHY_CMN_REG064_ANA_AUX_RX_TERM_GND_EN_MASK |
                          PCIE_PHY_CMN_REG064_ANA_AUX_TX_TERM(0x04));
    /* PHy block reset */
    IOMUXC_GPR_GPR14 |= IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_CMN_RSTN_MASK;
#elif defined(CPU_IMX8MQ)
    /* Configure PCIe reference clock to 100MHz */
    CCM_ANALOG_PLLOUT_MONITOR_CFG = ((CCM_ANALOG_PLLOUT_MONITOR_CFG &
                                    ~(CCM_ANALOG_PLLOUT_MONITOR_CFG_PLLOUT_MONITOR_CLK_SEL_MASK)) |
                                    CCM_ANALOG_PLLOUT_MONITOR_CFG_PLLOUT_MONITOR_CLK_SEL(11));
    /* Set PCIE_REF_CLK to 100MHz => SYS_PLL1 / 8 = 100MHz */
    CCM_ANALOG_SCCG_PLLOUT_DIV_CFG = (CCM_ANALOG_SCCG_PLLOUT_DIV_CFG & ~(CCM_ANALOG_SCCG_PLLOUT_DIV_CFG_SYSTEM_PLL1_DIV_VAL_MASK)) |
                                     CCM_ANALOG_SCCG_PLLOUT_DIV_CFG_SYSTEM_PLL1_DIV_VAL(0x07);
    /* Enable clock monitor output clock gating */
    CCM_ANALOG_PLLOUT_MONITOR_CFG |= CCM_ANALOG_PLLOUT_MONITOR_CFG_PLLOUT_MONITOR_CKE_MASK;

#endif
  } else {
    PCIE_INFO("PCIe%d configured with external reference clock.\n", PcieDeviceDataPtr->PcieIndex);
#if defined(CPU_IMX8MM)
    IOMUXC_GPR_GPR14 &= ~(IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_I_AUX_EN_OVERRIDE_EN_MASK);
    /* Selects reference clock from SOC PLL (pll_refclk_from_syspll) */
    IOMUXC_GPR_GPR14 |= IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_PLL_REF_CLK_SEL(0x03);
    IOMUXC_GPR_GPR14 |= IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_AUX_EN_MASK;
    IOMUXC_GPR_GPR14 &= ~(IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_POWER_OFF_MASK);
    IOMUXC_GPR_GPR14 &= ~(IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_SSC_EN_MASK);
    /* Use external reference clock */
    IOMUXC_GPR_GPR14 = ((IOMUXC_GPR_GPR14 & ~(IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_PLL_REF_CLK_SEL_MASK)) |
                        IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_PLL_REF_CLK_SEL(0x02));
    MicroSecondDelay(1000);
    /* PCIe PHy block reset */
    IOMUXC_GPR_GPR14 |= IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_CMN_RSTN_MASK;
#elif defined(CPU_IMX8MQ)
#endif
  }
#if defined(CPU_IMX8MM)
  /* Configure the PCIe_PHy - TRSV register */
  /* Set TX driver de-emphasis level for GEN1 speed */
  PCIE_PHY_TRSV_REG005 = PCIE_PHY_TRSV_REG005_LN0_TX_DRV_POST_LVL_CTRL_G1(45);
  /* Set TX driver de-emphasis level for GEN2 speed */
  PCIE_PHY_TRSV_REG006 = PCIE_PHY_TRSV_REG006_LN0_TX_DRV_POST_LVL_CTRL_G2(15);
  /* Set PCIe to RootComplex mode */
  IOMUXC_GPR_GPR12 = (IOMUXC_GPR_GPR12 & ~(IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DEVICE_TYPE_MASK)) |
                     IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DEVICE_TYPE(0x04);
#elif defined(CPU_IMX8MQ)
  /* Set PCIe to RootComplex mode */
  if (PcieDeviceDataPtr->PcieIndex == 0) {
    IOMUXC_GPR_GPR12 = (IOMUXC_GPR_GPR12 & ~(IOMUXC_GPR_GPR_PCIE1_CTRL_DEVICE_TYPE_MASK)) |
                       IOMUXC_GPR_GPR_PCIE1_CTRL_DEVICE_TYPE(0x04);
  } else {
    IOMUXC_GPR_GPR12 = (IOMUXC_GPR_GPR12 & ~(IOMUXC_GPR_GPR_PCIE2_CTRL_DEVICE_TYPE_MASK)) |
                       IOMUXC_GPR_GPR_PCIE2_CTRL_DEVICE_TYPE(0x04);
  }
#endif
  Status = EFI_SUCCESS;

Exit:
  return Status;
}

EFI_STATUS PcieSetClockGate (
                             IN  UINT32  State
                            )
{

  return EFI_SUCCESS;
}

EFI_STATUS PcieVerifyClocks (VOID)
{
  return EFI_SUCCESS;
}

VOID PcieEnablePerstLine (IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr)
{
  // Enable board specific PERST line if one is defined
  if (PcieDeviceDataPtr->PcieResetGpio) {
    ImxGpioWrite (
      PcieDeviceDataPtr->PcieResetGpioBankNumber,
      PcieDeviceDataPtr->PcieResetGpioIoNumber,
      IMX_GPIO_HIGH);
    gBS->Stall (20000);
  }
}

EFI_STATUS PcieSetupPciBridge (IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr)
{
  UINT8 classCode[0];

  // Setup the bridge class
  classCode[0] = PCI_IF_BRIDGE_P2P;
  classCode[1] = PCI_CLASS_BRIDGE_P2P;
  classCode[2] = PCI_CLASS_BRIDGE;

  return PciePciWrite(
           EfiPciIoWidthUint8,
           PcieDeviceDataPtr->PcieHostConfigBaseReg + PCI_CLASSCODE_OFFSET,
           3,
           classCode);
}

EFI_STATUS PcieSetLinkStatus (
                              IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr,
                              IN  BOOLEAN   State
                             )
{
  SRC_MemMapPtr SrcMemPtr = (SRC_MemMapPtr)((UINT64)SRC_BASE_PTR + (0x01C * PcieDeviceDataPtr->PcieIndex));

  if (State == TRUE) {
    SRC_PCIEPHY_RCR_REG(SrcMemPtr) |= (SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_EN_MASK);  // Enable link
  } else {
    SRC_PCIEPHY_RCR_REG(SrcMemPtr) &= ~(SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_EN_MASK); // Disable link
  }

  return EFI_SUCCESS;
}

BOOLEAN PcieIsLinkUp (IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr)
{
  return (PCIE_PL_DEBUG1_OFF_REG(PcieDeviceDataPtr->PcieMemMap) & (0x01 << 4)) ? TRUE : FALSE;
}

EFI_STATUS PcieWaitForLink (IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr)
{
  UINT32    Counter;
  BOOLEAN   LinkStatus;

  Counter = 200;
  LinkStatus = PcieIsLinkUp(PcieDeviceDataPtr);

  // To optimize boot time, consider lowering timeout value
  while (LinkStatus == FALSE && Counter > 0) {
    --Counter;
    gBS->Stall (1000);
    LinkStatus = PcieIsLinkUp(PcieDeviceDataPtr);
  }

  return (LinkStatus) ? EFI_SUCCESS : EFI_DEVICE_ERROR;
}

EFI_STATUS PcieGetAlignAddress (
                                IN  UINTN   Address,
                                IN  UINTN   AlignmentSize,
                                OUT UINTN   *AlignAddress
                               )
{
  EFI_STATUS Status;

  *AlignAddress = 0;
  if ((AlignmentSize & (AlignmentSize - 1)) != 0) {
    Status = EFI_INVALID_PARAMETER;
    goto Exit;
  }

  // Even though we do not add a (AlignmentSize + 1) to the incoming address
  // we would still align to the upper boundary as bit [19:00] is assumed to
  // be 0x000FFFFF per Pcie spec.
  *AlignAddress = (Address) & ~(AlignmentSize - 1);
  Status = EFI_SUCCESS;

Exit:
  return Status;
}

#define EFI_PCI_ADDRESS_SHIFT(bus, dev, func, reg) ((((UINTN) bus) << 20) | (((UINTN) dev) << 15) | (((UINTN) func) << 8))

EFI_STATUS PcieGetPciConfigAddress (
                                    IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr,
                                    IN  UINTN            BusNumber,
                                    IN  UINTN            DevNumber,
                                    IN  UINTN            FuncNumber,
                                    IN  UINTN            Register,
                                    OUT UINTN            *Address
                                   )
{
  UINT64      Offset;
  EFI_STATUS  Status;

  // For now only support bus 0 and bus 1 with one device in each bus
  if (BusNumber == 0 && DevNumber == 0) {
    Offset = EFI_PCI_ADDRESS (BusNumber, DevNumber, FuncNumber, Register);
    *Address = PcieDeviceDataPtr->PcieHostConfigBaseReg + Offset;
    Status = EFI_SUCCESS;
  } else if (BusNumber == 1 && DevNumber == 0) {
    Offset = EFI_PCI_ADDRESS (BusNumber, DevNumber, FuncNumber, Register);
    Offset -= EFI_PCI_ADDRESS (1, 0, FuncNumber, 0);
    *Address = PcieDeviceDataPtr->PcieDeviceConfig0BaseReg + Offset;
    Status = EFI_SUCCESS;
  } else if ((BusNumber >= 2) && (BusNumber <= PcieDeviceDataPtr->MaxBusNumber)) {
    Offset = EFI_PCI_ADDRESS_SHIFT (BusNumber, DevNumber, FuncNumber, Register);
    *Address = PcieDeviceDataPtr->PcieDeviceConfig1BaseReg + Offset;
    Status = EFI_SUCCESS;
  } else {
    *Address = 0;
    Status = EFI_INVALID_PARAMETER;
  }

  return Status;
}

EFI_STATUS PciePciRead (
                        IN  EFI_PCI_IO_PROTOCOL_WIDTH   Width,
                        IN  UINTN                       Address,
                        IN  UINTN                       Count,
                        OUT VOID                        *Buffer
                       )
{
  UINT8       *pDest;
  EFI_STATUS  Status;
  UINTN       Stride;

  pDest = (UINT8 *)Buffer;
  Width = (EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH) (Width & 0x03);
  Stride = (UINTN)1 << Width;

  switch (Width) {
  case EfiPciWidthUint8:
    for (; Count > 0; --Count, pDest += Stride, Address += Stride) {
      *pDest = MmioRead8 (Address);
    }
    Status = EFI_SUCCESS;
    break;
  case EfiPciWidthUint16:
    for (; Count > 0; --Count, pDest += Stride, Address += Stride) {
      *((UINT16 *)pDest) = MmioRead16 (Address);
    }
    Status = EFI_SUCCESS;
    break;
  case EfiPciWidthUint32:
    for (; Count > 0; --Count, pDest += Stride, Address += Stride) {
      *((UINT32 *)pDest) = MmioRead32 (Address);
    }
    Status = EFI_SUCCESS;
    break;
  default:
    Status = EFI_INVALID_PARAMETER;
    goto Exit;
  }

Exit:
  return Status;
}

EFI_STATUS PciePciWrite (
                         IN  EFI_PCI_IO_PROTOCOL_WIDTH   Width,
                         IN  UINTN                       Address,
                         IN  UINTN                       Count,
                         IN  VOID                        *Buffer
                        )
{
  UINT8       *pSrc;
  EFI_STATUS  Status;
  UINTN       Stride;

  pSrc = (UINT8 *)Buffer;
  Width = (EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH) (Width & 0x03);
  Stride = (UINTN)1 << Width;

  switch (Width) {
  case EfiPciWidthUint8:
    for (; Count > 0; --Count, pSrc += Stride, Address += Stride) {
      MmioWrite8 (Address, *pSrc);
    }
    Status = EFI_SUCCESS;
    break;
  case EfiPciWidthUint16:
    for (; Count > 0; --Count, pSrc += Stride, Address += Stride) {
      MmioWrite16 (Address, *((UINT16 *)pSrc));
    }
    Status = EFI_SUCCESS;
    break;
  case EfiPciWidthUint32:
    for (; Count > 0; --Count, pSrc += Stride, Address += Stride) {
      MmioWrite32 (Address, *((UINT32 *)pSrc));
    }
    Status = EFI_SUCCESS;
    break;
  default:
    Status = EFI_INVALID_PARAMETER;
    goto Exit;
  }

Exit:
  return Status;
}

EFI_STATUS PcieDevicePresent (
                              IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr,
                              OUT PCI_TYPE00       *PciDevice,
                              IN  UINTN            Bus,
                              IN  UINTN            Device,
                              IN  UINTN            Func
                             )
{
  UINTN       Address;
  EFI_STATUS  Status;

  // Create Pci address map in terms of Bus, Device, and Func
  Status = PcieGetPciConfigAddress (PcieDeviceDataPtr, Bus, Device, Func, 0, &Address);
  if (EFI_ERROR (Status)) {
    Status = EFI_NOT_FOUND;
    goto Exit;
  }

  // Read the Vendor ID register
  Status = PciePciRead (
             EfiPciWidthUint32,
             Address,
             1,
             PciDevice);
  if (!EFI_ERROR (Status) && (PciDevice->Hdr).VendorId != 0xffff) {
    // Read the entire config header for the device
    Status = PciePciRead (
               EfiPciWidthUint32,
               Address,
               sizeof (PCI_TYPE00) / sizeof (UINT32),
               PciDevice);
    if (EFI_ERROR (Status)) {
      PCIE_ERROR("Failed to read Pci config space\n");
    }
  } else {
    PCIE_INFO("No Pcie device found\n");
    Status = EFI_NOT_FOUND;
  }

Exit:
  return Status;
}

EFI_STATUS
  PcieGetMemoryBarResource (
                            IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr,
                            IN  UINTN            BarSize,
                            IN  UINTN            *BarAddress,
                            IN  BOOLEAN          IsBridgeDevice
                           )
{
  EFI_STATUS  Status;

  if (BarSize > PcieDeviceDataPtr->PcieResource.Size) {
    PCIE_ERROR("Insufficient Pcie memory for 0x%08x (Current size 0x%08x)\n",
               BarSize,
               PcieDeviceDataPtr->PcieResource.Size);
    Status = EFI_OUT_OF_RESOURCES;
    goto Exit;
  }

  *BarAddress = PcieDeviceDataPtr->PcieResource.Curr;

  if (IsBridgeDevice == FALSE) {
    PcieDeviceDataPtr->PcieResource.Curr += BarSize;
    PcieDeviceDataPtr->PcieResource.Size -= BarSize;

    PCIE_INFO("Allocating memory resource 0x%08x size 0x%08x\n",
               *BarAddress,
               BarSize);
  }

  PCIE_INFO("Current memory resource 0x%08x Size 0x%08x\n",
             PcieDeviceDataPtr->PcieResource.Curr,
             PcieDeviceDataPtr->PcieResource.Size);

  Status = EFI_SUCCESS;

Exit:
  return Status;
}

EFI_STATUS
PcieParseAssignBar (
  IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr,
  IN  UINTN            BaseAddress,
  IN  UINTN            MaxBarIndex,
  IN  BOOLEAN          IsBridgeDevice
  )
{
  UINT32        AllOne32;
  UINT32        AllZero;
  UINTN         BarIndex;
  UINTN         BarOffset;
  UINTN         BarSize;
  UINT32        Originalvalue;
  UINTN         ResourceAddress;
  UINT32        ResponseValue;
  EFI_STATUS    Status;

  AllZero = 0;
  AllOne32 = MAX_UINT32;
  for (BarOffset = 0x10, BarIndex = 0;
       BarOffset <= 0x24 && BarIndex < MaxBarIndex;
       BarOffset += sizeof (UINT32), ++BarIndex) {

    Status = PciePciRead(
               EfiPciWidthUint32,
               BaseAddress + BarOffset,
               1,
               &Originalvalue);
    ASSERT_EFI_ERROR(Status);

    Status = PciePciWrite(
               EfiPciIoWidthUint32,
               BaseAddress + BarOffset,
               1,
               &AllOne32);
    ASSERT_EFI_ERROR(Status);

    Status = PciePciRead(
               EfiPciWidthUint32,
               BaseAddress + BarOffset,
               1,
               &ResponseValue);
    ASSERT_EFI_ERROR(Status);

    // No support for IO memory
    // Refer : Pci Local Bus Specification (6.2.5.1)
    if ((ResponseValue & 0x01) == 0x01) {
      Status = PciePciWrite(
                 EfiPciIoWidthUint32,
                 BaseAddress + BarOffset,
                 1,
                 &Originalvalue);
      ASSERT_EFI_ERROR(Status);
      continue;
    }

    // No support for prefetch memory
    if (((ResponseValue & 0x01) == 0x00) &&
        ((ResponseValue & 0x08) == 0x08)) {
      Status = PciePciWrite(
                 EfiPciIoWidthUint32,
                 BaseAddress + BarOffset,
                 1,
                 &Originalvalue);
      ASSERT_EFI_ERROR(Status);
      continue;
    }

    BarSize = (UINTN)((~(ResponseValue & 0xFFFFFFF0)) + 1);

    Status = PcieGetMemoryBarResource (
               PcieDeviceDataPtr,
               BarSize,
               &ResourceAddress,
               IsBridgeDevice);
    if (EFI_ERROR(Status)) {
      PCIE_ERROR("Failed to acquire BAR resource\n");
      goto Exit;
    }

    Status = PciePciWrite (
               EfiPciIoWidthUint32,
               BaseAddress + BarOffset,
               1,
               &ResourceAddress);
    ASSERT_EFI_ERROR(Status);

    // The subsequent BAR is the upper 32 bit address
    if (((ResponseValue & 0x04) == 0x04) &&
        (BarIndex + 1) < MaxBarIndex) {
      BarOffset += sizeof (UINT32);
      ++BarIndex;

      Status = PciePciWrite(
                 EfiPciIoWidthUint32,
                 BaseAddress + BarOffset,
                 1,
                 &AllZero);
      ASSERT_EFI_ERROR(Status);

      continue;
    }
  }

  Status = EFI_SUCCESS;

Exit:
  return Status;
}

EFI_STATUS PcieConfigureDevice (
                                IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr,
                                IN  PCI_TYPE00       PciDevice,
                                IN  UINTN            BusNumber,
                                IN  UINTN            DevNumber,
                                IN  UINTN            FuncNumber
                               )
{
  UINT32      AllZero;
  UINTN       BaseAddress;
  UINT8       FixedCacheLineSize;
  UINT16      PciCommand;
  EFI_STATUS  Status;

  AllZero = 0;

  PCIE_INFO(
    "Configuring B:%02d D:%02d F:%02d\n",
    BusNumber,
    DevNumber,
    FuncNumber);

  Status = PcieGetPciConfigAddress (
             PcieDeviceDataPtr,
             BusNumber,
             DevNumber,
             FuncNumber,
             0,
             &BaseAddress);
  ASSERT_EFI_ERROR(Status);

  // Use a fixed cacheline size
  FixedCacheLineSize = 0x10;

  Status = PciePciWrite (
             EfiPciIoWidthUint8,
             BaseAddress + PCI_CACHELINE_SIZE_OFFSET,
             1,
             &FixedCacheLineSize);
  ASSERT_EFI_ERROR(Status);

  if (IS_PCI_BRIDGE (&PciDevice)) {
    PCIE_INFO("Pci Bridge\n");
    // Pcie initialization sequence, referenced from
    // InitializePpb in MdeModulePkg/Bus/Pci/PciBusDxe
    // No support for IO and prefetch memory
    Status = PciePciWrite (
               EfiPciIoWidthUint8,
               BaseAddress + 0x1C,
               1,
               &AllZero);
    ASSERT_EFI_ERROR(Status);

    Status = PciePciWrite (
               EfiPciIoWidthUint8,
               BaseAddress + 0x1D,
               1,
               &AllZero);

    Status = PciePciWrite (
               EfiPciIoWidthUint16,
               BaseAddress + 0x24,
               1,
               &AllZero);
    ASSERT_EFI_ERROR(Status);

    Status = PciePciWrite (
               EfiPciIoWidthUint16,
               BaseAddress + 0x26,
               1,
               &AllZero);
    ASSERT_EFI_ERROR(Status);

    Status = PciePciWrite (
               EfiPciIoWidthUint32,
               BaseAddress + 0x28,
               1,
               &AllZero);
    ASSERT_EFI_ERROR(Status);

    Status = PciePciWrite (
               EfiPciIoWidthUint32,
               BaseAddress + 0x2C,
               1,
               &AllZero);
    ASSERT_EFI_ERROR(Status);

    Status = PciePciWrite (
               EfiPciIoWidthUint16,
               BaseAddress + 0x30,
               1,
               &AllZero);
    ASSERT_EFI_ERROR(Status);

    Status = PciePciWrite (
               EfiPciIoWidthUint16,
               BaseAddress + 0x32,
               1,
               &AllZero);
    ASSERT_EFI_ERROR(Status);

    // Type 1 bridge only has 2 BAR register
    Status = PcieParseAssignBar (
               PcieDeviceDataPtr,
               BaseAddress,
               2,
               TRUE);
    if (EFI_ERROR (Status)) {
      PCIE_ERROR("Failed to assign resource to Pci bridge\n");
      goto Exit;
    }
  } else {
    // Device specific configuration should be implemented here
    PCIE_INFO("Pci device\n");

    Status = PcieParseAssignBar (
               PcieDeviceDataPtr,
               BaseAddress,
               PCI_MAX_BAR,
               FALSE);
    if (EFI_ERROR (Status)) {
      PCIE_ERROR("Failed to assign resource to Pci device\n");
      goto Exit;
    }
  }

  Status = PciePciRead (
             EfiPciIoWidthUint16,
             BaseAddress + PCI_COMMAND_OFFSET,
             1,
             &PciCommand);
  ASSERT_EFI_ERROR(Status);

  PciCommand |=
    (EFI_PCI_COMMAND_MEMORY_SPACE | EFI_PCI_COMMAND_BUS_MASTER);

  Status = PciePciWrite (
             EfiPciIoWidthUint16,
             BaseAddress + PCI_COMMAND_OFFSET,
             1,
             &PciCommand);
  ASSERT_EFI_ERROR(Status);

  Status = EFI_SUCCESS;

Exit:
  return Status;
}

EFI_STATUS 
PcieSimpleScanBusAndAssignResource (
                                    IN  PCIE_DEVICE_DATA *PcieDeviceDataPtr,
                                    IN  UINTN            BusNumber
                                   )
{
  UINTN         BridgeMemory;
  UINTN         BridgeMemoryBase;
  UINTN         BridgeMemoryLimit;
  UINTN         BusBaseRegisterAddress;
  UINT16        BusRegister;
  UINTN         DevNumber;
  UINTN         FunctionNumber;
  PCI_TYPE00    PciDevice;
  UINTN         ResourceAddress;
  EFI_STATUS    Status;
  UINT8         SubBus;

  for (DevNumber = 0; DevNumber <= PCI_MAX_DEVICE; ++DevNumber) {
    for (FunctionNumber = 0; FunctionNumber <= PCI_MAX_FUNC; ++FunctionNumber) {
      PCIE_INFO("Scanning device B: %02d D: %02d F: %02d\n",
                BusNumber,
                DevNumber,
                FunctionNumber);

      Status = PcieDevicePresent(
                 PcieDeviceDataPtr,
                 &PciDevice,
                 BusNumber,
                 DevNumber,
                 FunctionNumber);
      if (Status == EFI_NOT_FOUND) {
        PCIE_INFO("No Pci device found\n");
        if (DevNumber > 0) {
          Status = EFI_SUCCESS;
          goto Exit;
        } else {
          FunctionNumber = PCI_MAX_FUNC;          // Force continue to next device.
          continue;
        }
      } else if (EFI_ERROR (Status)) {
        PCIE_ERROR("Error detecting Pci device\n");
        goto Exit;
      }

      Status = PcieConfigureDevice(
                 PcieDeviceDataPtr,
                 PciDevice,
                 BusNumber,
                 DevNumber,
                 FunctionNumber);
      if (EFI_ERROR(Status)) {
        PCIE_ERROR(
          "Failed to configure device B:%02d D:%02d F:%02d\n",
          BusNumber,
          DevNumber,
          FunctionNumber);
        continue;
      }

      if (IS_PCI_BRIDGE (&PciDevice)) {
        BusRegister = (UINT16) (((PcieDeviceDataPtr->MaxScanBusNumber + 1) << 8) | (UINT16)BusNumber);
        Status = PcieGetPciConfigAddress(
                   PcieDeviceDataPtr,
                   BusNumber,
                   DevNumber,
                   FunctionNumber,
                   0,
                   &BusBaseRegisterAddress);

        ASSERT_EFI_ERROR(Status);

        Status = PciePciWrite(
                   EfiPciWidthUint16,
                   BusBaseRegisterAddress + PCI_BRIDGE_PRIMARY_BUS_REGISTER_OFFSET,
                   1,
                   &BusRegister);
        if (EFI_ERROR(Status)) {
          PCIE_ERROR("Failed to update bridge bus number %d\n", BusNumber);
          continue;
        }

        // Temporarily set maximum subordinate bus number, although for now
        // only support 2 buses.
        SubBus = 0xFF;
        Status = PciePciWrite(
                   EfiPciWidthUint8,
                   BusBaseRegisterAddress + PCI_BRIDGE_SUBORDINATE_BUS_REGISTER_OFFSET,
                   1,
                   &SubBus);
        if (EFI_ERROR(Status)) {
          PCIE_ERROR("Failed to update bridge bus number %d\n", BusNumber);
          continue;
        }

        // Setup the memory base.
        Status = PcieGetMemoryBarResource(
                   PcieDeviceDataPtr,
                   0,
                   &BridgeMemoryBase,
                   TRUE);
        if (EFI_ERROR(Status)) {
          PCIE_ERROR("Failed to acquire BAR resource\n");
          goto Exit;
        }

        BridgeMemory = (BridgeMemoryBase >> 16) & 0xFFF0;

        Status = PciePciWrite(
                   EfiPciIoWidthUint32,
                   BusBaseRegisterAddress + 0x20,
                   1,
                   &BridgeMemory);
        ASSERT_EFI_ERROR(Status);

        PcieDeviceDataPtr->MaxScanBusNumber = PcieDeviceDataPtr->MaxScanBusNumber + 1;

        Status = PcieSimpleScanBusAndAssignResource(
                   PcieDeviceDataPtr,
                   PcieDeviceDataPtr->MaxScanBusNumber);
        if (EFI_ERROR(Status)) {
          PCIE_ERROR("Failed to scan new bus %d\n", PcieDeviceDataPtr->MaxScanBusNumber);
          continue;
        }

        // Setup the memory limit.
        Status = PcieGetMemoryBarResource(
                   PcieDeviceDataPtr,
                   0,
                   &ResourceAddress,
                   TRUE);
        if (EFI_ERROR(Status)) {
          PCIE_ERROR("Failed to acquire BAR resource\n");
          goto Exit;
        }

        ASSERT(BridgeMemoryBase != ResourceAddress);

        // Per spec align address has to be 1MB boundary
        PcieGetAlignAddress(
          ResourceAddress,
          0x00100000,
          &BridgeMemoryLimit);
        ASSERT_EFI_ERROR(Status);

        BridgeMemory |= BridgeMemoryLimit;

        Status = PciePciWrite(
                   EfiPciIoWidthUint32,
                   BusBaseRegisterAddress + 0x20,
                   1,
                   &BridgeMemory);
        ASSERT_EFI_ERROR(Status);

        SubBus = PcieDeviceDataPtr->MaxScanBusNumber;
        Status = PciePciWrite(
                   EfiPciWidthUint8,
                   BusBaseRegisterAddress +
                   PCI_BRIDGE_SUBORDINATE_BUS_REGISTER_OFFSET,
                   1,
                   &SubBus);
        if (EFI_ERROR(Status)) {
          PCIE_ERROR(
            "Failed to update subordinate bus number %d\n",
            BusNumber);
          continue;
        }

        // Claim any memory that is used for padding
        Status = PcieGetMemoryBarResource(
                   PcieDeviceDataPtr,
                   (BridgeMemoryLimit + 0x00100000) - ResourceAddress,
                   &ResourceAddress,
                   FALSE);
        if (EFI_ERROR(Status)) {
          PCIE_ERROR("Failed to realign resource\n");
          goto Exit;
        }
      }

      // Skip sub functions, this is not a multi function device
      if ((FunctionNumber == 0) && !IS_PCI_MULTI_FUNC(&PciDevice)) {
        FunctionNumber = PCI_MAX_FUNC;
      }
    }
  }

Exit:
  return Status;
}

EFI_STATUS PcieInitialize (
                           IN  EFI_HANDLE        ImageHandle,
                           IN  EFI_SYSTEM_TABLE  *SystemTablePtr
                          )
{
  PCIE_DEVICE_DATA      *PcieDeviceDataPtr;
  UINT32                val32, Idx, PcieIdx;
  EFI_STATUS            Status;

  for (PcieIdx = 0; PcieIdx < ARRAYSIZE(PcieDeviceData); PcieIdx++) {

    PcieDeviceDataPtr = &PcieDeviceData[PcieIdx];
    if (!(PcieDeviceDataPtr->PcieEnable)) {
      continue;
    }

    Status = PcieSetupInitSetting(PcieDeviceDataPtr);
    if (EFI_ERROR (Status)) {
      // EFI_DEVICE_ERROR indicates that a bootloader has already setup the
      // Pcie controller. In this case just return success immediately
      if (Status == EFI_DEVICE_ERROR) {
        Status = EFI_SUCCESS;
        PCIE_WARNING("Pcie already initialized\n");
        goto Exit;
      }

      PCIE_ERROR("Failed to enable Pcie gates\n");
      goto Exit;
    }

    Status = PcieSetClockGate(1);
    if (EFI_ERROR(Status)) {
      PCIE_ERROR("Failed to enable Pcie gates\n");
      goto Exit;
    }

    Status = PcieVerifyClocks();
    if (EFI_ERROR(Status)) {
      PCIE_ERROR("Failed to verify Pcie clocks, not configured!\n");
      goto Exit;
    }

    Status = PcieSetPhyState(PcieDeviceDataPtr, TRUE);
    if (EFI_ERROR(Status)) {
      PCIE_ERROR("Failed to enable PCIe%d PHY\n", PcieIdx);
      goto Exit;
    }

    // Very important to wait for Pcie PHY to settle here or the controller
    // behaviour becomes unpredictable.
    gBS->Stall(50000);

    PcieEnablePerstLine(PcieDeviceDataPtr);

    /* Set the link_capable to be lane */
    PCIE_PORT_LINK_CTRL_OFF_REG(PcieDeviceDataPtr->PcieMemMap) =
                               ((PCIE_PORT_LINK_CTRL_OFF_REG(PcieDeviceDataPtr->PcieMemMap) &
                               ~(PCIE_PORT_LINK_CTRL_OFF_LINK_CAPABLE_MASK)) |
                               PCIE_PORT_LINK_CTRL_OFF_LINK_CAPABLE(0x01));

    /* Set the number of lanes */
    PCIE_GEN2_CTRL_OFF_REG(PcieDeviceDataPtr->PcieMemMap) =
                          ((PCIE_GEN2_CTRL_OFF_REG(PcieDeviceDataPtr->PcieMemMap) &
                          ~(PCIE_GEN2_CTRL_OFF_NUM_OF_LANES_MASK)) |
                          PCIE_GEN2_CTRL_OFF_NUM_OF_LANES(0x01));

    Status = PcieSetupPciBridge(PcieDeviceDataPtr);
    if (EFI_ERROR(Status)) {
      PCIE_ERROR("Failed to setup PCIe%d bridge\n", PcieIdx);
      goto Exit;
    }

    /* Enable Fast Link Mode - sets all internal timers to "Fast Mode" */
    PCIE_PORT_LINK_CTRL_OFF_REG(PcieDeviceDataPtr->PcieMemMap) &= ~(PCIE_PORT_LINK_CTRL_OFF_FAST_LINK_MODE_MASK);
    /* Configure speed to Gen1 before starting link up */
    PCIE_LINK_CAPABILITIES_REG_REG(PcieDeviceDataPtr->PcieMemMap) =
                                ((PCIE_LINK_CAPABILITIES_REG_REG(PcieDeviceDataPtr->PcieMemMap) &
                                ~(PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED_MASK)) |
                                PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED(0x01));

    Status = PcieSetLinkStatus(PcieDeviceDataPtr, TRUE);
    if (EFI_ERROR(Status)) {
      PCIE_ERROR("PCIe%d failed to enable Pcie link\n", PcieIdx);
      goto Exit;
    }

    Status = PcieWaitForLink(PcieDeviceDataPtr);
    if (EFI_ERROR(Status)) {
      PCIE_ERROR("PCIe%d link never came up.\n", PcieIdx);
      goto Exit;
    }

    if (PcieDeviceDataPtr->PcieMaxLinkSpeed > 1) {
      /* Configure speed Gen after link up */
      PCIE_LINK_CAPABILITIES_REG_REG(PcieDeviceDataPtr->PcieMemMap) =
                                ((PCIE_LINK_CAPABILITIES_REG_REG(PcieDeviceDataPtr->PcieMemMap) &
                                ~(PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED_MASK)) |
                                PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED(PcieDeviceDataPtr->PcieMaxLinkSpeed));
      PCIE_GEN2_CTRL_OFF_REG(PcieDeviceDataPtr->PcieMemMap) |= PCIE_GEN2_CTRL_OFF_DIRECT_SPEED_CHANGE_MASK;
      /* Wait for PCIe link speed change */
      for (Idx = 0; Idx < 100; Idx++) {
        val32 = PCIE_GEN2_CTRL_OFF_REG(PcieDeviceDataPtr->PcieMemMap);
        if ((val32 & PCIE_GEN2_CTRL_OFF_DIRECT_SPEED_CHANGE_MASK) == 0) {
            break;
        }
        MicroSecondDelay(1000);
      }
      if ((val32 & PCIE_GEN2_CTRL_OFF_DIRECT_SPEED_CHANGE_MASK) != 0) {
         PCIE_ERROR("PCIe%d Link speed change failed!\n", PcieIdx);
      }
      Status = PcieWaitForLink (PcieDeviceDataPtr);
      if (EFI_ERROR(Status)) {
        PCIE_ERROR("PCIe%d link never came up.\n", PcieIdx);
        goto Exit;
      }
    }

    PCIE_INFO("PCIe%d Link up, Gen speed: %d\n",
          PcieIdx,
          ((PCIE_LINK_CONTROL_LINK_STATUS_REG_REG(PcieDeviceDataPtr->PcieMemMap) &
          PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED_MASK) >>
          PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED_SHIFT));

    PcieSetupiAtuSettings (PcieDeviceDataPtr);

    // Start PCIe BUS scanning
    Status = PcieSimpleScanBusAndAssignResource (PcieDeviceDataPtr, 0);
    if (EFI_ERROR(Status)) {
      PCIE_ERROR("PcieSimpleScanBusAndAssignResource failed %r\n", Status);
      goto Exit;
    }

#if (PCIE_DEBUG == 1)
    volatile UINT32   *pPrintAddr;
    UINTN             Address;
    UINT32            PrintIndex;
    UINTN             BusNumber;
    UINTN             DevNumber;
    PCI_TYPE00        *PciDevice;

    pPrintAddr = (UINT32 *)PcieDeviceDataPtr->PcieHostConfigBaseReg;

    PCIE_INFO("===============================\n");
    PCIE_INFO("Root Complex Configuration space\n");
    PCIE_INFO("===============================\n");
    for (PrintIndex = 0; PrintIndex < 16; ++PrintIndex) {
      PCIE_INFO("PCI [%02x] 0x%08x 0x%08x 0x%08x 0x%08x\n",
                 PrintIndex * 16,
                 pPrintAddr[0],
                 pPrintAddr[1],
                 pPrintAddr[2],
                 pPrintAddr[3]);

      pPrintAddr += 4;
    }

    for (BusNumber = 1; BusNumber <= PcieDeviceDataPtr->MaxBusNumber; BusNumber++) {
      for (DevNumber = 0; DevNumber <= PCI_MAX_DEVICE; DevNumber++) {
        // Create Pci address map in terms of Bus, Device, and Func
        Status = PcieGetPciConfigAddress (PcieDeviceDataPtr, BusNumber, DevNumber, 0, 0, &Address);
        if (!(EFI_ERROR (Status))) {
          PciDevice = ((PCI_TYPE00 *)Address);
          if ((PciDevice->Hdr.DeviceId != 0xFFFF) && (PciDevice->Hdr.VendorId != 0xFFFF)) {
            pPrintAddr = (UINT32 *)Address;
            PCIE_INFO("===============================\n");
            PCIE_INFO("Device Configuration space 0x%08x\n", pPrintAddr);
            PCIE_INFO("===============================\n");
            for (PrintIndex = 0; PrintIndex < 16; ++PrintIndex) {
              PCIE_INFO("PCI [%02x] 0x%08x 0x%08x 0x%08x 0x%08x\n",
                         PrintIndex * 16,
                         pPrintAddr[0],
                         pPrintAddr[1],
                         pPrintAddr[2],
                         pPrintAddr[3]);
              pPrintAddr += 4;
            }
          }
        }
      }
    }
    PCIE_INFO("===============================\n");
#endif

Exit:

    if (EFI_ERROR(Status)) {
      PCIE_ERROR("Failed to initialize PCIe%d, disabling controller\n", PcieIdx);
      PcieSetLinkStatus(PcieDeviceDataPtr, FALSE);
      PcieSetPhyState(PcieDeviceDataPtr, FALSE);
      PcieSetClockGate(0);
    }
  }
  return Status;
}
