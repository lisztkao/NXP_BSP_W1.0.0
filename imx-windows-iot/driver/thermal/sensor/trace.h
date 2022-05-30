// Copyright (c) Microsoft Corporation. All rights reserved.
// Copyright 2020 NXP
// Licensed under the MIT License.

#ifndef _TRACE_H_
#define _TRACE_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//
// Defining control guids, including this is required to happen before
// including the tmh file (if the WppRecorder API is used)
//
#include <WppRecorder.h>

//
// Tracing GUID - {493ACFC6-D20C-4712-8836-A77D51FEEC3E}
//
#define WPP_CONTROL_GUIDS \
    WPP_DEFINE_CONTROL_GUID(IMXTMU, (493ACFC6,D20C,4712,8836,A77D51FEEC3E), \
        WPP_DEFINE_BIT(IMXTMU_TRACING_DEFAULT) \
    )

// begin_wpp config
//
// USEPREFIX (IMXTMU_LOG_ERROR, "%!STDPREFIX! [%s @ %u] ERROR :", __FILE__, __LINE__);
// FUNC IMXTMU_LOG_ERROR{LEVEL=TRACE_LEVEL_ERROR, FLAGS=IMXTMU_TRACING_DEFAULT}(MSG, ...);
//
// USEPREFIX (IMXTMU_LOG_LOW_MEMORY, "%!STDPREFIX! [%s @ %u] LOW MEMORY :", __FILE__, __LINE__);
// FUNC IMXTMU_LOG_LOW_MEMORY{LEVEL=TRACE_LEVEL_ERROR, FLAGS=IMXTMU_TRACING_DEFAULT}(MSG, ...);
//
// USEPREFIX (IMXTMU_LOG_WARNING, "%!STDPREFIX! [%s @ %u] WARNING :", __FILE__, __LINE__);
// FUNC IMXTMU_LOG_WARNING{LEVEL=TRACE_LEVEL_WARNING, FLAGS=IMXTMU_TRACING_DEFAULT}(MSG, ...);
//
// USEPREFIX (IMXTMU_LOG_INFORMATION, "%!STDPREFIX! [%s @ %u] INFO :", __FILE__, __LINE__);
// FUNC IMXTMU_LOG_INFORMATION{LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=IMXTMU_TRACING_DEFAULT}(MSG, ...);
//
// USEPREFIX (IMXTMU_LOG_TRACE, "%!STDPREFIX! [%s @ %u] TRACE :", __FILE__, __LINE__);
// FUNC IMXTMU_LOG_TRACE{LEVEL=TRACE_LEVEL_VERBOSE, FLAGS=IMXTMU_TRACING_DEFAULT}(MSG, ...);
//
// end_wpp

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // _TRACE_H_