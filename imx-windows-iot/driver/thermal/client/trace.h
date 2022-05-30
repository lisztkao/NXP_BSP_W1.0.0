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
// Tracing GUID - {452C6E6D-5089-46A7-8440-A21E7FEA6575}
//
#define WPP_CONTROL_GUIDS \
    WPP_DEFINE_CONTROL_GUID(IMXTC, (452C6E6D,5089,46A7,8440,A21E7FEA6575), \
        WPP_DEFINE_BIT(IMXTC_TRACING_DEFAULT) \
    )

// begin_wpp config
//
// FUNC IMXTC_LOG_ERROR{LEVEL=TRACE_LEVEL_ERROR, FLAGS=IMXTC_TRACING_DEFAULT}(MSG, ...);
// USEPREFIX (IMXTC_LOG_ERROR, "%!STDPREFIX! [%s @ %u] ERROR: ", __FILE__, __LINE__);
//
// FUNC IMXTC_LOG_LOW_MEMORY{LEVEL=TRACE_LEVEL_ERROR, FLAGS=IMXTC_TRACING_DEFAULT}(MSG, ...);
// USEPREFIX (IMXTC_LOG_LOW_MEMORY, "%!STDPREFIX! [%s @ %u] LOW MEMORY: ", __FILE__, __LINE__);
//
// FUNC IMXTC_LOG_WARNING{LEVEL=TRACE_LEVEL_WARNING, FLAGS=IMXTC_TRACING_DEFAULT}(MSG, ...);
// USEPREFIX (IMXTC_LOG_WARNING, "%!STDPREFIX! [%s @ %u] WARNING: ", __FILE__, __LINE__);
//
// FUNC IMXTC_LOG_INFORMATION{LEVEL=TRACE_LEVEL_INFORMATION, FLAGS=IMXTC_TRACING_DEFAULT}(MSG, ...);
// USEPREFIX (IMXTC_LOG_INFORMATION, "%!STDPREFIX! [%s @ %u] INFO: ", __FILE__, __LINE__);
//
// FUNC IMXTC_LOG_TRACE{LEVEL=TRACE_LEVEL_VERBOSE, FLAGS=IMXTC_TRACING_DEFAULT}(MSG, ...);
// USEPREFIX (IMXTC_LOG_TRACE, "%!STDPREFIX! [%s @ %u] TRACE: %s(): ", __FILE__, __LINE__, __FUNCTION__);
//
// end_wpp

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // _TRACE_H_