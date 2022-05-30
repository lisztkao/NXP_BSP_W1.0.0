// Copyright (c) Microsoft Corporation. All rights reserved.
// Copyright 2020 NXP
// Licensed under the MIT License.
//
// Module Name:
//
//   imxtmuhw.h
//
// Abstract:
//
//   iMX TMU (IMX8MQ) Hardware Definitions
//

#ifndef __IMXTMUHW_H__
#define __IMXTMUHW_H__

// TMU Registers Layout
typedef struct _IMXTMU_REGISTERS_ {
    UINT32 TMR;               // 0x0
    UINT32 TSR;               // 0x4
    UINT32 TMTMIR;            // 0x8
    UINT32 _reserved0[5];     // 0xC - 1C
    UINT32 TIER;              // 0x20
    UINT32 TIDR;              // 0x24
    UINT32 TISCR;             // 0x28
    UINT32 TICSCR;            // 0x2C
    UINT32 _reserved1[4];     // 0x30 - 3C
    UINT32 TMHTCR;            // 0x40
    UINT32 TMLTCR;            // 0x44
    UINT32 _reserved2[2];     // 0x48 - 0x4C
    UINT32 TMHTITR;           // 0x50
    UINT32 TMHTATR;           // 0x54
    UINT32 TMHTACTR;          // 0x58
    UINT32 _reserved3[9];     // 0x5C - 7C
    UINT32 TTCFGR;            // 0x80
    UINT32 TSCFGR;            // 0x84
    UINT32 _reserved4[30];    // 0x88 - FC
    UINT32 TRITSR0;           // 0x100
    UINT32 TRATSR0;           // 0x104
    UINT32 _reserved26;       // 0x108
    UINT32 _reserved27;       // 0x10C
    UINT32 TRITSR1;           // 0x110
    UINT32 TRATSR1;           // 0x114
    UINT32 _reserved28;       // 0x118
    UINT32 _reserved29;       // 0x11C
    UINT32 TRITSR2;           // 0x120
    UINT32 TRATSR2;           // 0x124
    UINT32 _reserved30[890];  // 0x128 - 0xF0C
    UINT32 TTR0CR;            // 0xF10
    UINT32 TTR1CR;            // 0xF14
    UINT32 TTR2CR;            // 0xF18
    UINT32 TTR3CR;            // 0xF1C
} IMXTMU_REGISTERS, *PIMXTMU_REGISTERS;


// TMU mode register (TMR)
#define IMX_TMU_TMR_ME_SHIFT        31u
#define IMX_TMU_TMR_ME_MASK         (0x1u << 31)
#define IMX_TMU_TMR_ALPF_SHIFT      26u
#define IMX_TMU_TMR_ALPF_MASK       (0x3u << 26)
#define IMX_TMU_TMR_MSITE_SHIFT     13u
#define IMX_TMU_TMR_MSITE_MASK      (0x7u << 13)
#define IMX_TMU_TMR_MSITE_VAL_ARM   0
#define IMX_TMU_TMR_MSITE_VAL_GPU   1
#define IMX_TMU_TMR_MSITE_VAL_VPU   2

// TMU status register (TSR)
#define IMX_TMU_TSR_MIE_SHIFT       30u
#define IMX_TMU_TSR_MIE_MASK        (0x1u << 30)
#define IMX_TMU_TSR_ORL_SHIFT       29u
#define IMX_TMU_TSR_ORL_MASK        (0x1u << 29)
#define IMX_TMU_TSR_ORH_SHIFT       28u
#define IMX_TMU_TSR_ORH_MASK        (0x1u << 28)

// TMU monitor temperature measurement interval register (TMTMIR)
#define IMX_TMU_TMTMIR_TMI_SHIFT    0u
#define IMX_TMU_TMTMIR_TMI_MASK     (0xF << 0)
#define IMX_TMU_TMTMIR_TMI_VAL_DFLT 2

// TMU interrupt enable register (TIER)
#define IMX_TMU_TIER_ITTEIE_SHIFT   31u
#define IMX_TMU_TIER_ITTEIE_MASK    (0x1u << 31)
#define IMX_TMU_TIER_ATTEIE_SHIFT   30u
#define IMX_TMU_TIER_ATTEIE_MASK    (0x1u << 30)
#define IMX_TMU_TIER_ATCTEIE_SHIFT  29u
#define IMX_TMU_TIER_ATCTEIE_MASK   (0x1u << 29)

// TMU interrupt detect register (TIDR)
#define IMX_TMU_TIDR_ITTE_SHIFT         31u
#define IMX_TMU_TIDR_ITTE_MASK          (0x1u << 31)
#define IMX_TMU_TIDR_ATTE_SHIFT         30u
#define IMX_TMU_TIDR_ATTE_MASK          (0x1u << 30)
#define IMX_TMU_TIDR_ATCTE_SHIFT        29u
#define IMX_TMU_TIDR_ATCTE_MASK         (0x1u << 29)

// TMU interrupt site capture register (TISCR)
#define IMX_TMU_TISCR_ITTE_SHIFT        29u
#define IMX_TMU_TISCR_ITTE_MASK         (0x7u << 29)
#define IMX_TMU_TISCR_ASITE_SHIFT       13u
#define IMX_TMU_TISCR_ASITE_MASK        (0x7u << 13)

// TMU interrupt critical site capture register (TICSCR)
#define IMX_TMU_TICSCR_CASITE_SHIFT     13u
#define IMX_TMU_TICSCR_CASITE_MASK      (0x7u << 13)

// TMU monitor high temperature immediate/average/average critical threshold register (TMHTITR/TMHTATR/TMHTACTR)
#define IMX_TMU_TEMP_EN       (0x1 << 31)

// TMU monitor high/low temperature capture register (TMHTCR/TMLTCR)
// TMU report immediate/average temperature site register (TRITSRx)
#define IMX_TMU_TEMP_VALID    (0x1 << 31)
#define IMX_TMU_TEMP_MASK     (0xFFu << 0)

#endif