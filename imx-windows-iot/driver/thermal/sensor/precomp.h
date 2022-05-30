// Copyright (c) Microsoft Corporation. All rights reserved.
// Copyright 2020 NXP
// Licensed under the MIT License.

#include <Ntddk.h>

#define IMX_TMU_NONPAGED_SEGMENT_BEGIN \
    __pragma(code_seg(push)) \
    //__pragma(code_seg(.text))

#define IMX_TMU_NONPAGED_SEGMENT_END \
    __pragma(code_seg(pop))

#define IMX_TMU_PAGED_SEGMENT_BEGIN \
    __pragma(code_seg(push)) \
    __pragma(code_seg("PAGE"))

#define IMX_TMU_PAGED_SEGMENT_END \
    __pragma(code_seg(pop))

#define IMX_TMU_INIT_SEGMENT_BEGIN \
    __pragma(code_seg(push)) \
    __pragma(code_seg("INIT"))

#define IMX_TMU_INIT_SEGMENT_END \
    __pragma(code_seg(pop))
