#ifndef _LIBPROXY
#define _LIBPROXY

/*
 * For C++ compilers, use extern "C"
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <tcl.h>

/*
 * Only the _Init function is exported.
 */

extern DLLEXPORT int	Libproxy_Init(Tcl_Interp * interp);

/*
 * end block for C++
 */

#ifdef __cplusplus
}
#endif

#endif /* _LIBPROXY */
