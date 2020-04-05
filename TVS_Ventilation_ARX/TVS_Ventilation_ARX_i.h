

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun Apr 05 20:33:43 2020
 */
/* Compiler settings for TVS_Ventilation_ARX.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __TVS_Ventilation_ARX_i_h__
#define __TVS_Ventilation_ARX_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMLeaderDynProp_FWD_DEFINED__
#define __IMLeaderDynProp_FWD_DEFINED__
typedef interface IMLeaderDynProp IMLeaderDynProp;

#endif 	/* __IMLeaderDynProp_FWD_DEFINED__ */


#ifndef __ITVSPropertyPositionDyn_FWD_DEFINED__
#define __ITVSPropertyPositionDyn_FWD_DEFINED__
typedef interface ITVSPropertyPositionDyn ITVSPropertyPositionDyn;

#endif 	/* __ITVSPropertyPositionDyn_FWD_DEFINED__ */


#ifndef __ITVSPropertyNameDyn_FWD_DEFINED__
#define __ITVSPropertyNameDyn_FWD_DEFINED__
typedef interface ITVSPropertyNameDyn ITVSPropertyNameDyn;

#endif 	/* __ITVSPropertyNameDyn_FWD_DEFINED__ */


#ifndef __ITVSPropertyTypeDyn_FWD_DEFINED__
#define __ITVSPropertyTypeDyn_FWD_DEFINED__
typedef interface ITVSPropertyTypeDyn ITVSPropertyTypeDyn;

#endif 	/* __ITVSPropertyTypeDyn_FWD_DEFINED__ */


#ifndef __ITVSPropertySizeDyn_FWD_DEFINED__
#define __ITVSPropertySizeDyn_FWD_DEFINED__
typedef interface ITVSPropertySizeDyn ITVSPropertySizeDyn;

#endif 	/* __ITVSPropertySizeDyn_FWD_DEFINED__ */


#ifndef __ITVSPropertyArticleDyn_FWD_DEFINED__
#define __ITVSPropertyArticleDyn_FWD_DEFINED__
typedef interface ITVSPropertyArticleDyn ITVSPropertyArticleDyn;

#endif 	/* __ITVSPropertyArticleDyn_FWD_DEFINED__ */


#ifndef __ITVSPropertyManufacturerDyn_FWD_DEFINED__
#define __ITVSPropertyManufacturerDyn_FWD_DEFINED__
typedef interface ITVSPropertyManufacturerDyn ITVSPropertyManufacturerDyn;

#endif 	/* __ITVSPropertyManufacturerDyn_FWD_DEFINED__ */


#ifndef __ITVSPropertyUnitsDyn_FWD_DEFINED__
#define __ITVSPropertyUnitsDyn_FWD_DEFINED__
typedef interface ITVSPropertyUnitsDyn ITVSPropertyUnitsDyn;

#endif 	/* __ITVSPropertyUnitsDyn_FWD_DEFINED__ */


#ifndef __ITVSPropertyCountDyn_FWD_DEFINED__
#define __ITVSPropertyCountDyn_FWD_DEFINED__
typedef interface ITVSPropertyCountDyn ITVSPropertyCountDyn;

#endif 	/* __ITVSPropertyCountDyn_FWD_DEFINED__ */


#ifndef __ITVSPropertyMassDyn_FWD_DEFINED__
#define __ITVSPropertyMassDyn_FWD_DEFINED__
typedef interface ITVSPropertyMassDyn ITVSPropertyMassDyn;

#endif 	/* __ITVSPropertyMassDyn_FWD_DEFINED__ */


#ifndef __ITVSPropertyNoteDyn_FWD_DEFINED__
#define __ITVSPropertyNoteDyn_FWD_DEFINED__
typedef interface ITVSPropertyNoteDyn ITVSPropertyNoteDyn;

#endif 	/* __ITVSPropertyNoteDyn_FWD_DEFINED__ */


#ifndef __MLeaderDynProp_FWD_DEFINED__
#define __MLeaderDynProp_FWD_DEFINED__

#ifdef __cplusplus
typedef class MLeaderDynProp MLeaderDynProp;
#else
typedef struct MLeaderDynProp MLeaderDynProp;
#endif /* __cplusplus */

#endif 	/* __MLeaderDynProp_FWD_DEFINED__ */


#ifndef __TVSPropertyPositionDyn_FWD_DEFINED__
#define __TVSPropertyPositionDyn_FWD_DEFINED__

#ifdef __cplusplus
typedef class TVSPropertyPositionDyn TVSPropertyPositionDyn;
#else
typedef struct TVSPropertyPositionDyn TVSPropertyPositionDyn;
#endif /* __cplusplus */

#endif 	/* __TVSPropertyPositionDyn_FWD_DEFINED__ */


#ifndef __TVSPropertyNameDyn_FWD_DEFINED__
#define __TVSPropertyNameDyn_FWD_DEFINED__

#ifdef __cplusplus
typedef class TVSPropertyNameDyn TVSPropertyNameDyn;
#else
typedef struct TVSPropertyNameDyn TVSPropertyNameDyn;
#endif /* __cplusplus */

#endif 	/* __TVSPropertyNameDyn_FWD_DEFINED__ */


#ifndef __TVSPropertyTypeDyn_FWD_DEFINED__
#define __TVSPropertyTypeDyn_FWD_DEFINED__

#ifdef __cplusplus
typedef class TVSPropertyTypeDyn TVSPropertyTypeDyn;
#else
typedef struct TVSPropertyTypeDyn TVSPropertyTypeDyn;
#endif /* __cplusplus */

#endif 	/* __TVSPropertyTypeDyn_FWD_DEFINED__ */


#ifndef __TVSPropertySizeDyn_FWD_DEFINED__
#define __TVSPropertySizeDyn_FWD_DEFINED__

#ifdef __cplusplus
typedef class TVSPropertySizeDyn TVSPropertySizeDyn;
#else
typedef struct TVSPropertySizeDyn TVSPropertySizeDyn;
#endif /* __cplusplus */

#endif 	/* __TVSPropertySizeDyn_FWD_DEFINED__ */


#ifndef __TVSPropertyArticleDyn_FWD_DEFINED__
#define __TVSPropertyArticleDyn_FWD_DEFINED__

#ifdef __cplusplus
typedef class TVSPropertyArticleDyn TVSPropertyArticleDyn;
#else
typedef struct TVSPropertyArticleDyn TVSPropertyArticleDyn;
#endif /* __cplusplus */

#endif 	/* __TVSPropertyArticleDyn_FWD_DEFINED__ */


#ifndef __TVSPropertyManufacturerDyn_FWD_DEFINED__
#define __TVSPropertyManufacturerDyn_FWD_DEFINED__

#ifdef __cplusplus
typedef class TVSPropertyManufacturerDyn TVSPropertyManufacturerDyn;
#else
typedef struct TVSPropertyManufacturerDyn TVSPropertyManufacturerDyn;
#endif /* __cplusplus */

#endif 	/* __TVSPropertyManufacturerDyn_FWD_DEFINED__ */


#ifndef __TVSPropertyUnitsDyn_FWD_DEFINED__
#define __TVSPropertyUnitsDyn_FWD_DEFINED__

#ifdef __cplusplus
typedef class TVSPropertyUnitsDyn TVSPropertyUnitsDyn;
#else
typedef struct TVSPropertyUnitsDyn TVSPropertyUnitsDyn;
#endif /* __cplusplus */

#endif 	/* __TVSPropertyUnitsDyn_FWD_DEFINED__ */


#ifndef __TVSPropertyCountDyn_FWD_DEFINED__
#define __TVSPropertyCountDyn_FWD_DEFINED__

#ifdef __cplusplus
typedef class TVSPropertyCountDyn TVSPropertyCountDyn;
#else
typedef struct TVSPropertyCountDyn TVSPropertyCountDyn;
#endif /* __cplusplus */

#endif 	/* __TVSPropertyCountDyn_FWD_DEFINED__ */


#ifndef __TVSPropertyMassDyn_FWD_DEFINED__
#define __TVSPropertyMassDyn_FWD_DEFINED__

#ifdef __cplusplus
typedef class TVSPropertyMassDyn TVSPropertyMassDyn;
#else
typedef struct TVSPropertyMassDyn TVSPropertyMassDyn;
#endif /* __cplusplus */

#endif 	/* __TVSPropertyMassDyn_FWD_DEFINED__ */


#ifndef __TVSPropertyNoteDyn_FWD_DEFINED__
#define __TVSPropertyNoteDyn_FWD_DEFINED__

#ifdef __cplusplus
typedef class TVSPropertyNoteDyn TVSPropertyNoteDyn;
#else
typedef struct TVSPropertyNoteDyn TVSPropertyNoteDyn;
#endif /* __cplusplus */

#endif 	/* __TVSPropertyNoteDyn_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMLeaderDynProp_INTERFACE_DEFINED__
#define __IMLeaderDynProp_INTERFACE_DEFINED__

/* interface IMLeaderDynProp */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMLeaderDynProp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5040B8FD-1BB3-4F7E-9436-250A358C6270")
    IMLeaderDynProp : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IMLeaderDynPropVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMLeaderDynProp * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMLeaderDynProp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMLeaderDynProp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMLeaderDynProp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMLeaderDynProp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMLeaderDynProp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMLeaderDynProp * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IMLeaderDynPropVtbl;

    interface IMLeaderDynProp
    {
        CONST_VTBL struct IMLeaderDynPropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMLeaderDynProp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMLeaderDynProp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMLeaderDynProp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMLeaderDynProp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMLeaderDynProp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMLeaderDynProp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMLeaderDynProp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMLeaderDynProp_INTERFACE_DEFINED__ */


#ifndef __ITVSPropertyPositionDyn_INTERFACE_DEFINED__
#define __ITVSPropertyPositionDyn_INTERFACE_DEFINED__

/* interface ITVSPropertyPositionDyn */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITVSPropertyPositionDyn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C1E7B1E0-A2BC-4B72-A107-F194C07A2E3D")
    ITVSPropertyPositionDyn : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITVSPropertyPositionDynVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITVSPropertyPositionDyn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITVSPropertyPositionDyn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITVSPropertyPositionDyn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITVSPropertyPositionDyn * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITVSPropertyPositionDyn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITVSPropertyPositionDyn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITVSPropertyPositionDyn * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITVSPropertyPositionDynVtbl;

    interface ITVSPropertyPositionDyn
    {
        CONST_VTBL struct ITVSPropertyPositionDynVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITVSPropertyPositionDyn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITVSPropertyPositionDyn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITVSPropertyPositionDyn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITVSPropertyPositionDyn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITVSPropertyPositionDyn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITVSPropertyPositionDyn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITVSPropertyPositionDyn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITVSPropertyPositionDyn_INTERFACE_DEFINED__ */


#ifndef __ITVSPropertyNameDyn_INTERFACE_DEFINED__
#define __ITVSPropertyNameDyn_INTERFACE_DEFINED__

/* interface ITVSPropertyNameDyn */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITVSPropertyNameDyn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B54DF745-D7FE-472F-B51E-A7712C0C08A0")
    ITVSPropertyNameDyn : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITVSPropertyNameDynVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITVSPropertyNameDyn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITVSPropertyNameDyn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITVSPropertyNameDyn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITVSPropertyNameDyn * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITVSPropertyNameDyn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITVSPropertyNameDyn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITVSPropertyNameDyn * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITVSPropertyNameDynVtbl;

    interface ITVSPropertyNameDyn
    {
        CONST_VTBL struct ITVSPropertyNameDynVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITVSPropertyNameDyn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITVSPropertyNameDyn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITVSPropertyNameDyn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITVSPropertyNameDyn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITVSPropertyNameDyn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITVSPropertyNameDyn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITVSPropertyNameDyn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITVSPropertyNameDyn_INTERFACE_DEFINED__ */


#ifndef __ITVSPropertyTypeDyn_INTERFACE_DEFINED__
#define __ITVSPropertyTypeDyn_INTERFACE_DEFINED__

/* interface ITVSPropertyTypeDyn */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITVSPropertyTypeDyn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("97E60D1A-4D9B-42A0-8528-BF721B7A9641")
    ITVSPropertyTypeDyn : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITVSPropertyTypeDynVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITVSPropertyTypeDyn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITVSPropertyTypeDyn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITVSPropertyTypeDyn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITVSPropertyTypeDyn * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITVSPropertyTypeDyn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITVSPropertyTypeDyn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITVSPropertyTypeDyn * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITVSPropertyTypeDynVtbl;

    interface ITVSPropertyTypeDyn
    {
        CONST_VTBL struct ITVSPropertyTypeDynVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITVSPropertyTypeDyn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITVSPropertyTypeDyn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITVSPropertyTypeDyn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITVSPropertyTypeDyn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITVSPropertyTypeDyn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITVSPropertyTypeDyn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITVSPropertyTypeDyn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITVSPropertyTypeDyn_INTERFACE_DEFINED__ */


#ifndef __ITVSPropertySizeDyn_INTERFACE_DEFINED__
#define __ITVSPropertySizeDyn_INTERFACE_DEFINED__

/* interface ITVSPropertySizeDyn */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITVSPropertySizeDyn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("92F57766-6434-41C6-B1A5-6B5680FBE8B3")
    ITVSPropertySizeDyn : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITVSPropertySizeDynVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITVSPropertySizeDyn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITVSPropertySizeDyn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITVSPropertySizeDyn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITVSPropertySizeDyn * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITVSPropertySizeDyn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITVSPropertySizeDyn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITVSPropertySizeDyn * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITVSPropertySizeDynVtbl;

    interface ITVSPropertySizeDyn
    {
        CONST_VTBL struct ITVSPropertySizeDynVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITVSPropertySizeDyn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITVSPropertySizeDyn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITVSPropertySizeDyn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITVSPropertySizeDyn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITVSPropertySizeDyn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITVSPropertySizeDyn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITVSPropertySizeDyn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITVSPropertySizeDyn_INTERFACE_DEFINED__ */


#ifndef __ITVSPropertyArticleDyn_INTERFACE_DEFINED__
#define __ITVSPropertyArticleDyn_INTERFACE_DEFINED__

/* interface ITVSPropertyArticleDyn */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITVSPropertyArticleDyn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("49512E67-8D16-40AE-BF81-E3A5C4DCF2E6")
    ITVSPropertyArticleDyn : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITVSPropertyArticleDynVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITVSPropertyArticleDyn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITVSPropertyArticleDyn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITVSPropertyArticleDyn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITVSPropertyArticleDyn * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITVSPropertyArticleDyn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITVSPropertyArticleDyn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITVSPropertyArticleDyn * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITVSPropertyArticleDynVtbl;

    interface ITVSPropertyArticleDyn
    {
        CONST_VTBL struct ITVSPropertyArticleDynVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITVSPropertyArticleDyn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITVSPropertyArticleDyn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITVSPropertyArticleDyn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITVSPropertyArticleDyn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITVSPropertyArticleDyn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITVSPropertyArticleDyn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITVSPropertyArticleDyn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITVSPropertyArticleDyn_INTERFACE_DEFINED__ */


#ifndef __ITVSPropertyManufacturerDyn_INTERFACE_DEFINED__
#define __ITVSPropertyManufacturerDyn_INTERFACE_DEFINED__

/* interface ITVSPropertyManufacturerDyn */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITVSPropertyManufacturerDyn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DFFAF303-7CD8-4947-9BA2-133AF19FCF75")
    ITVSPropertyManufacturerDyn : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITVSPropertyManufacturerDynVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITVSPropertyManufacturerDyn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITVSPropertyManufacturerDyn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITVSPropertyManufacturerDyn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITVSPropertyManufacturerDyn * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITVSPropertyManufacturerDyn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITVSPropertyManufacturerDyn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITVSPropertyManufacturerDyn * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITVSPropertyManufacturerDynVtbl;

    interface ITVSPropertyManufacturerDyn
    {
        CONST_VTBL struct ITVSPropertyManufacturerDynVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITVSPropertyManufacturerDyn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITVSPropertyManufacturerDyn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITVSPropertyManufacturerDyn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITVSPropertyManufacturerDyn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITVSPropertyManufacturerDyn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITVSPropertyManufacturerDyn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITVSPropertyManufacturerDyn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITVSPropertyManufacturerDyn_INTERFACE_DEFINED__ */


#ifndef __ITVSPropertyUnitsDyn_INTERFACE_DEFINED__
#define __ITVSPropertyUnitsDyn_INTERFACE_DEFINED__

/* interface ITVSPropertyUnitsDyn */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITVSPropertyUnitsDyn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA57A20D-2149-490E-8513-578A9F7829EA")
    ITVSPropertyUnitsDyn : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITVSPropertyUnitsDynVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITVSPropertyUnitsDyn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITVSPropertyUnitsDyn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITVSPropertyUnitsDyn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITVSPropertyUnitsDyn * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITVSPropertyUnitsDyn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITVSPropertyUnitsDyn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITVSPropertyUnitsDyn * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITVSPropertyUnitsDynVtbl;

    interface ITVSPropertyUnitsDyn
    {
        CONST_VTBL struct ITVSPropertyUnitsDynVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITVSPropertyUnitsDyn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITVSPropertyUnitsDyn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITVSPropertyUnitsDyn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITVSPropertyUnitsDyn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITVSPropertyUnitsDyn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITVSPropertyUnitsDyn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITVSPropertyUnitsDyn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITVSPropertyUnitsDyn_INTERFACE_DEFINED__ */


#ifndef __ITVSPropertyCountDyn_INTERFACE_DEFINED__
#define __ITVSPropertyCountDyn_INTERFACE_DEFINED__

/* interface ITVSPropertyCountDyn */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITVSPropertyCountDyn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CA4EEADD-F396-42A7-94C3-E51F9670337B")
    ITVSPropertyCountDyn : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITVSPropertyCountDynVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITVSPropertyCountDyn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITVSPropertyCountDyn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITVSPropertyCountDyn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITVSPropertyCountDyn * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITVSPropertyCountDyn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITVSPropertyCountDyn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITVSPropertyCountDyn * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITVSPropertyCountDynVtbl;

    interface ITVSPropertyCountDyn
    {
        CONST_VTBL struct ITVSPropertyCountDynVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITVSPropertyCountDyn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITVSPropertyCountDyn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITVSPropertyCountDyn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITVSPropertyCountDyn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITVSPropertyCountDyn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITVSPropertyCountDyn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITVSPropertyCountDyn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITVSPropertyCountDyn_INTERFACE_DEFINED__ */


#ifndef __ITVSPropertyMassDyn_INTERFACE_DEFINED__
#define __ITVSPropertyMassDyn_INTERFACE_DEFINED__

/* interface ITVSPropertyMassDyn */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITVSPropertyMassDyn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("34D404D5-AED0-4A90-B728-260425C08025")
    ITVSPropertyMassDyn : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITVSPropertyMassDynVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITVSPropertyMassDyn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITVSPropertyMassDyn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITVSPropertyMassDyn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITVSPropertyMassDyn * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITVSPropertyMassDyn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITVSPropertyMassDyn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITVSPropertyMassDyn * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITVSPropertyMassDynVtbl;

    interface ITVSPropertyMassDyn
    {
        CONST_VTBL struct ITVSPropertyMassDynVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITVSPropertyMassDyn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITVSPropertyMassDyn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITVSPropertyMassDyn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITVSPropertyMassDyn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITVSPropertyMassDyn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITVSPropertyMassDyn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITVSPropertyMassDyn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITVSPropertyMassDyn_INTERFACE_DEFINED__ */


#ifndef __ITVSPropertyNoteDyn_INTERFACE_DEFINED__
#define __ITVSPropertyNoteDyn_INTERFACE_DEFINED__

/* interface ITVSPropertyNoteDyn */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITVSPropertyNoteDyn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ABBE5C6B-7B53-46C9-ADD0-575D47E0F323")
    ITVSPropertyNoteDyn : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITVSPropertyNoteDynVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITVSPropertyNoteDyn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITVSPropertyNoteDyn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITVSPropertyNoteDyn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITVSPropertyNoteDyn * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITVSPropertyNoteDyn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITVSPropertyNoteDyn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITVSPropertyNoteDyn * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITVSPropertyNoteDynVtbl;

    interface ITVSPropertyNoteDyn
    {
        CONST_VTBL struct ITVSPropertyNoteDynVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITVSPropertyNoteDyn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITVSPropertyNoteDyn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITVSPropertyNoteDyn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITVSPropertyNoteDyn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITVSPropertyNoteDyn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITVSPropertyNoteDyn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITVSPropertyNoteDyn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITVSPropertyNoteDyn_INTERFACE_DEFINED__ */



#ifndef __TVSTVS_Ventilation_ARXLib_LIBRARY_DEFINED__
#define __TVSTVS_Ventilation_ARXLib_LIBRARY_DEFINED__

/* library TVSTVS_Ventilation_ARXLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TVSTVS_Ventilation_ARXLib;

EXTERN_C const CLSID CLSID_MLeaderDynProp;

#ifdef __cplusplus

class DECLSPEC_UUID("122D8C49-9A8C-4239-8C29-007C24EF231A")
MLeaderDynProp;
#endif

EXTERN_C const CLSID CLSID_TVSPropertyPositionDyn;

#ifdef __cplusplus

class DECLSPEC_UUID("9CDF19D2-AEDA-4BCD-BEF0-B54EEC0CB34F")
TVSPropertyPositionDyn;
#endif

EXTERN_C const CLSID CLSID_TVSPropertyNameDyn;

#ifdef __cplusplus

class DECLSPEC_UUID("CFBDD843-ECB7-4759-AE1E-A20209C504B1")
TVSPropertyNameDyn;
#endif

EXTERN_C const CLSID CLSID_TVSPropertyTypeDyn;

#ifdef __cplusplus

class DECLSPEC_UUID("85FBD211-1892-460B-A668-ACABF964C096")
TVSPropertyTypeDyn;
#endif

EXTERN_C const CLSID CLSID_TVSPropertySizeDyn;

#ifdef __cplusplus

class DECLSPEC_UUID("7514E3C8-8DAE-44E2-ACF4-94F5E313D0FB")
TVSPropertySizeDyn;
#endif

EXTERN_C const CLSID CLSID_TVSPropertyArticleDyn;

#ifdef __cplusplus

class DECLSPEC_UUID("731F4CE4-EA83-403A-9E76-91F0A150B9F1")
TVSPropertyArticleDyn;
#endif

EXTERN_C const CLSID CLSID_TVSPropertyManufacturerDyn;

#ifdef __cplusplus

class DECLSPEC_UUID("3D2E7155-ECB6-4754-8C7F-B9C2AD3C4B4B")
TVSPropertyManufacturerDyn;
#endif

EXTERN_C const CLSID CLSID_TVSPropertyUnitsDyn;

#ifdef __cplusplus

class DECLSPEC_UUID("C2B31506-22AC-443A-BAB6-28106E77C186")
TVSPropertyUnitsDyn;
#endif

EXTERN_C const CLSID CLSID_TVSPropertyCountDyn;

#ifdef __cplusplus

class DECLSPEC_UUID("F34FBE1C-6D72-41DA-97A1-10AB8782D477")
TVSPropertyCountDyn;
#endif

EXTERN_C const CLSID CLSID_TVSPropertyMassDyn;

#ifdef __cplusplus

class DECLSPEC_UUID("2E0FDB59-A6B5-450B-AAC1-DF7E235B91EB")
TVSPropertyMassDyn;
#endif

EXTERN_C const CLSID CLSID_TVSPropertyNoteDyn;

#ifdef __cplusplus

class DECLSPEC_UUID("1453F171-05FA-4878-8B2D-E0E0DE6B9CC4")
TVSPropertyNoteDyn;
#endif
#endif /* __TVSTVS_Ventilation_ARXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


