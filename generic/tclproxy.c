#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#include <tcl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <proxy.h>
#include "tclproxy.h"

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#define NS "libproxy"

static int
Proxy_Cmd(
    ClientData dummy,   /* Not used. */
    Tcl_Interp *interp,     /* Current interpreter */
    int objc,           /* Number of arguments */
    Tcl_Obj *const objv[]   /* Argument strings */
    )
{
    pxProxyFactory *pf = NULL;
    char **proxies = NULL;
    char *url_string = NULL;
    int url_len = 0;
    int index = 0;
    Tcl_Obj *pResultStr = NULL;

    if( objc != 2){
        Tcl_WrongNumArgs(interp, 1, objv, "url");
        return TCL_ERROR;
    }

    url_string = (char *) Tcl_GetStringFromObj(objv[1], &url_len);
    if( !url_string || url_len < 1 ){
        return TCL_ERROR;
    }

    if (!(pf = px_proxy_factory_new()))
    {
        return TCL_ERROR;
    }

    proxies = px_proxy_factory_get_proxies(pf, url_string);

    pResultStr = Tcl_NewListObj(0, NULL);
    for (index = 0; proxies[index]; index++) {
        Tcl_ListObjAppendElement(interp, pResultStr,
            Tcl_NewStringObj(proxies[index], strlen(proxies[index])));
        if (proxies[index]) free(proxies[index]);
    }

    if(proxies) free(proxies);
    px_proxy_factory_free(pf);

    Tcl_SetObjResult(interp, pResultStr);
    return TCL_OK;
}


/*
 *----------------------------------------------------------------------
 *
 * Libproxy_Init --
 *
 *  Initialize the new package.
 *
 * Results:
 *  A standard Tcl result
 *
 * Side effects:
 *  The Libproxy package is created.
 *
 *----------------------------------------------------------------------
 */

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

DLLEXPORT int
Libproxy_Init(Tcl_Interp *interp)
{
    Tcl_Namespace *nsPtr; /* pointer to hold our own new namespace */

    if (Tcl_InitStubs(interp, "8.6", 0) == NULL) {
        return TCL_ERROR;
    }

    if (Tcl_PkgProvide(interp, PACKAGE_NAME, PACKAGE_VERSION) != TCL_OK) {
        return TCL_ERROR;
    }

    /*
     * Create the namespace.
     */
    nsPtr = Tcl_CreateNamespace(interp, NS, NULL, NULL);
    if (nsPtr == NULL) {
        return TCL_ERROR;
    }

    Tcl_CreateObjCommand(interp, "::libproxy::proxies", (Tcl_ObjCmdProc *) Proxy_Cmd,
        (ClientData)NULL, (Tcl_CmdDeleteProc *)NULL);

    return TCL_OK;
}
#ifdef __cplusplus
}
#endif  /* __cplusplus */
