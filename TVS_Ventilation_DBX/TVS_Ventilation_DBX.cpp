// (C) Copyright 2002-2012 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//- TVS_Ventilation_DBX.cpp : Initialization functions
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"
#include <initguid.h>
#include "TVS_Ventilation_DBX_i.h"
#include <afxdllx.h>
#include "TVS_Ventilation_DBX_i.c"
#include "axdb_i.c"


//-----------------------------------------------------------------------------
class CTVS_Ventilation_DBXModule : public CAtlDllModuleT<CTVS_Ventilation_DBXModule> {

public :
	DECLARE_LIBID(LIBID_TVSTVS_Ventilation_DBXLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TVS_VENTILATION_DBX, "{C8CDD260-E2DF-4F05-951F-9617FDFE2FB9}")
} ;

CTVS_Ventilation_DBXModule _AtlModule ;

//-----------------------------------------------------------------------------
//- Define the sole extension module object.
AC_IMPLEMENT_EXTENSION_MODULE(TVS_Ventilation_DBXDLL)
//- Now you can use the CAcModuleResourceOverride class in
//- your application to switch to the correct resource instance.
//- Please see the ObjectARX Documentation for more details

//-----------------------------------------------------------------------------
//- DLL Entry Point
extern "C"
BOOL WINAPI DllMain (HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved) {
	//- Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved) ;

	if ( dwReason == DLL_PROCESS_ATTACH ) {
        _hdllInstance =hInstance ;
		TVS_Ventilation_DBXDLL.AttachInstance (hInstance) ;
	} else if ( dwReason == DLL_PROCESS_DETACH ) {
		TVS_Ventilation_DBXDLL.DetachInstance () ;
	}
	return (_AtlModule.DllMain (dwReason, lpReserved)) ; 
}

//-----------------------------------------------------------------------------
//- Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow (void) {
	HRESULT hr =(_AtlModule.GetLockCount () == 0 ? S_OK : S_FALSE) ;
	return (hr) ;
}

//-----------------------------------------------------------------------------
//- Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject (REFCLSID rclsid, REFIID riid, LPVOID *ppv) {
	return (_AtlModule.GetClassObject (rclsid, riid, ppv)) ;
}

//-----------------------------------------------------------------------------
//- DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer (void) {
	//- Registers object, typelib and all interfaces in typelib
	return (_AtlModule.RegisterServer (TRUE)) ;
}

//-----------------------------------------------------------------------------
//- DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer (void) {
	return (_AtlModule.UnregisterServer (TRUE)) ;
}

//-----------------------------------------------------------------------------
#ifndef _WIN64
#pragma comment(linker, "/EXPORT:DllCanUnloadNow=_DllCanUnloadNow@0,PRIVATE")
#pragma comment(linker, "/EXPORT:DllGetClassObject=_DllGetClassObject@12,PRIVATE")
#pragma comment(linker, "/EXPORT:DllRegisterServer=_DllRegisterServer@0,PRIVATE")
#pragma comment(linker, "/EXPORT:DllUnregisterServer=_DllUnregisterServer@0,PRIVATE")
#else
#pragma comment(linker, "/EXPORT:DllCanUnloadNow=DllCanUnloadNow,PRIVATE")
#pragma comment(linker, "/EXPORT:DllGetClassObject=DllGetClassObject,PRIVATE")
#pragma comment(linker, "/EXPORT:DllRegisterServer=DllRegisterServer,PRIVATE")
#pragma comment(linker, "/EXPORT:DllUnregisterServer=DllUnregisterServer,PRIVATE")
#endif

