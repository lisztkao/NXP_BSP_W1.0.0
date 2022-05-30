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

/*
These values were obtained by experiments 
*/
#define USB_TYPE_C_SOURCE_DEFAULT     1         /* USB 2.0 - 500 mA, USB 3.1 - 900 mA */
#define USB_TYPE_C_SOURCE_1500_MA     2         /* Type C 1.5 A */
#define USB_TYPE_C_SOURCE_3000_MA     0         /* Type C 3.0 A */

/*
USB Type-C Spec R1.2 - March 2016
4.5.1.4 USB Type-C Port Power Roles and Role Swapping Mechanisms
USB Type-C ports on products (USB hosts, USB devices, USB chargers, etc.) can be generally characterized as implementing one of seven power role behavioral models:
*/
#define USB_TYPE_C_POWER_ROLE_SRC_ONLY        0         /* Source-only */
#define USB_TYPE_C_POWER_ROLE_SRC             1         /* Source (Default) – strong preference toward being a Source but subsequently capable of becoming a Sink using USB PD swap mechanisms. */
#define USB_TYPE_C_POWER_ROLE_SNK_ONLY        2         /* Sink-only */
#define USB_TYPE_C_POWER_ROLE_SNK             3         /* (Default) – strong preference toward being a Sink but subsequently capable of becoming a Source using USB PD swap mechanisms. */
#define USB_TYPE_C_POWER_ROLE_DRP             4         /* DRP: Toggling (Source/Sink) */
#define USB_TYPE_C_POWER_ROLE_DRP_SRC_DEV     5         /* DRP: Sourcing Device */
#define USB_TYPE_C_POWER_ROLE_DRP_SNK_HOST    6         /* DRP: Sinking Host */

/*
TCPCI Spec Rev 1.0 - October 2015
4.4.8.1 DEVICE_CAPABILITIES (Required)
B7..5 Roles Supported
    000b: USB Type-C Port Manager can configure the Port as Source only or Sink only (not DRP)
    001b: Source only
    010b: Sink only
    011b: Sink with accessory support
    100b: DRP only
    101b: Source, Sink, DRP, Adapter/Cable all supported
    110b: Source, Sink, DRP
    111b: Not valid
*/
#define USB_TYPE_C_ROLE_SRC_ONLY_OR_SNK_ONLY      0
#define USB_TYPE_C_ROLE_SRC_ONLY                  1
#define USB_TYPE_C_ROLE_SNK_ONLY                  2
#define USB_TYPE_C_ROLE_SNK_WITH_ACCESSORY        3
#define USB_TYPE_C_ROLE_DRP_ONLY                  4
#define USB_TYPE_C_ROLE_SRC_SNK_DRP_AC            5
#define USB_TYPE_C_ROLE_SRC_SNK_DRP               6

/*
Probably acoording to https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_power_role:
*/
#define USB_TYPE_C_POWER_MODE_SINK     1         /* Sink-only – for this mode, the port exclusively behaves as a Sink. */
#define USB_TYPE_C_POWER_MODE_SOURCE   2         /* Source-only – for this mode, the port exclusively behaves as a Source */
#define USB_TYPE_C_POWER_MODE_DRP      3         /* Dual-Role-Power (DRP) – for this mode, the port can behave either as a Source or Sink */


/* USB_PD_R2_0 V1.3
Sink Fixed Supply Power Data Object
*/
#define PD_SNK_FX_DRP_MASK             0x20000000
#define PD_SNK_FX_DRP_SHIFT            29
#define PD_SNK_FX_HC_MASK              0x10000000
#define PD_SNK_FX_HC_SHIFT             28
#define PD_SNK_FX_UC_PWR_MASK          0x08000000
#define PD_SNK_FX_UC_PWR_SHIFT         27
#define PD_SNK_FX_USB_CC_MASK          0x04000000
#define PD_SNK_FX_USB_CC_SHIFT         26
#define PD_SNK_FX_DRD_MASK             0x02000000
#define PD_SNK_FX_DRD_SHIFT            25
#define PD_SNK_FX_U_MASK               0x000FFC00
#define PD_SNK_FX_U_SHIFT              10
#define PD_SNK_FX_I_MASK               0x000003FF
#define PD_SNK_FX_I_SHIFT              0

#define PD_SNK_FX(DRP, HC, UC_PWR, USB_CC, DRD, U_mv, I_ma) (((DRP        << PD_SNK_FX_DRP_SHIFT)    & PD_SNK_FX_DRP_MASK)    | \
                                                             ((HC         << PD_SNK_FX_HC_SHIFT)     & PD_SNK_FX_HC_MASK)     | \
                                                             ((UC_PWR     << PD_SNK_FX_UC_PWR_SHIFT) & PD_SNK_FX_UC_PWR_MASK) | \
                                                             ((USB_CC     << PD_SNK_FX_USB_CC_SHIFT) & PD_SNK_FX_USB_CC_MASK) | \
                                                             ((DRD        << PD_SNK_FX_DRD_SHIFT)    & PD_SNK_FX_DRD_MASK)    | \
                                                             (((U_mv/50)  << PD_SNK_FX_U_SHIFT)      & PD_SNK_FX_U_MASK)      | \
                                                             (((I_ma/10)  << PD_SNK_FX_I_SHIFT)      & PD_SNK_FX_I_MASK))
                             
/* USB_PD_R2_0 V1.3
6.4.1.2.3 Source Fixed Supply Power Data Object
*/
                   
#define PD_SRC_FX_DRP_MASK            0x20000000
#define PD_SRC_FX_DRP_SHIFT           29
#define PD_SRC_FX_USB_SUSP_MASK       0x10000000
#define PD_SRC_FX_USB_SUSP_SHIFT      28
#define PD_SRC_FX_UC_PWR_MASK         0x08000000
#define PD_SRC_FX_UC_PWR_SHIFT        27
#define PD_SRC_FX_USB_CC_MASK         0x04000000
#define PD_SRC_FX_USB_CC_SHIFT        26
#define PD_SRC_FX_DRD_MASK            0x02000000
#define PD_SRC_FX_DRD_SHIFT           25
#define PD_SRC_FX_UEM_MASK            0x01000000
#define PD_SRC_FX_UEM_SHIFT           24
#define PD_SRC_FX_PK_MASK             0x01300000
#define PD_SRC_FX_PK_SHIFT            20
#define PD_SRC_FX_U_MASK              0x000FFC00
#define PD_SRC_FX_U_SHIFT             10
#define PD_SRC_FX_I_MASK              0x000003FF
#define PD_SRC_FX_I_SHIFT             0

#define PD_SRC_FX(DRP, USB_SUSP, UC_PWR, USB_CC, DRD, UEM, PK, U_mv, I_ma) (((DRP        << PD_SRC_FX_DRP_SHIFT)      & PD_SRC_FX_DRP_MASK)      | \
                                                                            ((USB_SUSP   << PD_SRC_FX_USB_SUSP_SHIFT) & PD_SRC_FX_USB_SUSP_MASK) | \
                                                                            ((UC_PWR     << PD_SRC_FX_UC_PWR_SHIFT)   & PD_SRC_FX_UC_PWR_MASK)   | \
                                                                            ((USB_CC     << PD_SRC_FX_USB_CC_SHIFT)   & PD_SRC_FX_USB_CC_MASK)   | \
                                                                            ((DRD        << PD_SRC_FX_DRD_SHIFT)      & PD_SRC_FX_DRD_MASK)      | \
                                                                            ((UEM        << PD_SRC_FX_UEM_SHIFT)      & PD_SRC_FX_UEM_MASK)      | \
                                                                            ((PK         << PD_SRC_FX_PK_SHIFT)       & PD_SRC_FX_PK_MASK)       | \
                                                                            (((U_mv/50)  << PD_SRC_FX_U_SHIFT)        & PD_SRC_FX_U_MASK)        | \
                                                                            (((I_ma/10)  << PD_SRC_FX_I_SHIFT)        & PD_SRC_FX_I_MASK))

          