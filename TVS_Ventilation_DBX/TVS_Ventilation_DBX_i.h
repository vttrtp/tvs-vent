

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Tue Dec 22 13:26:09 2015
 */
/* Compiler settings for TVS_Ventilation_DBX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
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
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __TVS_Ventilation_DBX_i_h__
#define __TVS_Ventilation_DBX_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITVS_ComEntity_FWD_DEFINED__
#define __ITVS_ComEntity_FWD_DEFINED__
typedef interface ITVS_ComEntity ITVS_ComEntity;

#endif 	/* __ITVS_ComEntity_FWD_DEFINED__ */


#ifndef __TVS_ComEntity_FWD_DEFINED__
#define __TVS_ComEntity_FWD_DEFINED__

#ifdef __cplusplus
typedef class TVS_ComEntity TVS_ComEntity;
#else
typedef struct TVS_ComEntity TVS_ComEntity;
#endif /* __cplusplus */

#endif 	/* __TVS_ComEntity_FWD_DEFINED__ */


#ifndef __IComPipe_FWD_DEFINED__
#define __IComPipe_FWD_DEFINED__
typedef interface IComPipe IComPipe;

#endif 	/* __IComPipe_FWD_DEFINED__ */


#ifndef __ComPipe_FWD_DEFINED__
#define __ComPipe_FWD_DEFINED__

#ifdef __cplusplus
typedef class ComPipe ComPipe;
#else
typedef struct ComPipe ComPipe;
#endif /* __cplusplus */

#endif 	/* __ComPipe_FWD_DEFINED__ */


#ifndef __ICom_TAP_FWD_DEFINED__
#define __ICom_TAP_FWD_DEFINED__
typedef interface ICom_TAP ICom_TAP;

#endif 	/* __ICom_TAP_FWD_DEFINED__ */


#ifndef __Com_TAP_FWD_DEFINED__
#define __Com_TAP_FWD_DEFINED__

#ifdef __cplusplus
typedef class Com_TAP Com_TAP;
#else
typedef struct Com_TAP Com_TAP;
#endif /* __cplusplus */

#endif 	/* __Com_TAP_FWD_DEFINED__ */


#ifndef __IComTrans_FWD_DEFINED__
#define __IComTrans_FWD_DEFINED__
typedef interface IComTrans IComTrans;

#endif 	/* __IComTrans_FWD_DEFINED__ */


#ifndef __ComTrans_FWD_DEFINED__
#define __ComTrans_FWD_DEFINED__

#ifdef __cplusplus
typedef class ComTrans ComTrans;
#else
typedef struct ComTrans ComTrans;
#endif /* __cplusplus */

#endif 	/* __ComTrans_FWD_DEFINED__ */


#ifndef __IComWye_FWD_DEFINED__
#define __IComWye_FWD_DEFINED__
typedef interface IComWye IComWye;

#endif 	/* __IComWye_FWD_DEFINED__ */


#ifndef __ComWye_FWD_DEFINED__
#define __ComWye_FWD_DEFINED__

#ifdef __cplusplus
typedef class ComWye ComWye;
#else
typedef struct ComWye ComWye;
#endif /* __cplusplus */

#endif 	/* __ComWye_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __TVSTVS_Ventilation_DBXLib_LIBRARY_DEFINED__
#define __TVSTVS_Ventilation_DBXLib_LIBRARY_DEFINED__

/* library TVSTVS_Ventilation_DBXLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TVSTVS_Ventilation_DBXLib;

#ifndef __ITVS_ComEntity_INTERFACE_DEFINED__
#define __ITVS_ComEntity_INTERFACE_DEFINED__

/* interface ITVS_ComEntity */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITVS_ComEntity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D18FCCA1-82A4-4305-AC38-9E572137F808")
    ITVS_ComEntity : public IAcadEntity
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITVS_ComEntityVtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITVS_ComEntity * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ BSTR AppName,
            /* [out][idldescattr] */ VARIANT *XDataType,
            /* [out][idldescattr] */ VARIANT *XDataValue,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ VARIANT XDataType,
            /* [in][idldescattr] */ VARIANT XDataValue,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ LONG_PTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ IAcadDatabase **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ IAcadDictionary **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ LONG_PTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ IAcadAcCmColor **retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ IAcadAcCmColor *noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ ACAD_NOUNITS *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ ACAD_NOUNITS noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ signed INT NumberOfObjects,
            /* [in][idldescattr] */ double AngleToFill,
            /* [in][idldescattr] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ signed INT NumberOfRows,
            /* [in][idldescattr] */ signed INT NumberOfColumns,
            /* [in][idldescattr] */ signed INT NumberOfLevels,
            /* [in][idldescattr] */ double DistBetweenRows,
            /* [in][idldescattr] */ double DistBetweenCols,
            /* [in][idldescattr] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ BOOLEAN HighlightFlag,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ VARIANT FromPoint,
            /* [in][idldescattr] */ VARIANT ToPoint,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ VARIANT BasePoint,
            /* [in][idldescattr] */ double RotationAngle,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [in][idldescattr] */ double RotationAngle,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [in][idldescattr] */ VARIANT point3,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ VARIANT BasePoint,
            /* [in][idldescattr] */ double ScaleFactor,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ VARIANT TransformationMatrix,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            ITVS_ComEntity * This,
            /* [out][idldescattr] */ VARIANT *MinPoint,
            /* [out][idldescattr] */ VARIANT *MaxPoint,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ IDispatch *IntersectObject,
            /* [in][idldescattr] */ enum AcExtendOption option,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ ACAD_LWEIGHT *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ ACAD_LWEIGHT noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ IAcadHyperlinks **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ signed long *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_color )( 
            ITVS_ComEntity * This,
            /* [retval][out] */ ACAD_COLOR *retval);
        
        /* [id][propput][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_color )( 
            ITVS_ComEntity * This,
            /* [in][idldescattr] */ ACAD_COLOR noname,
            /* [retval][out] */ void *retval);
        
        END_INTERFACE
    } ITVS_ComEntityVtbl;

    interface ITVS_ComEntity
    {
        CONST_VTBL struct ITVS_ComEntityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITVS_ComEntity_QueryInterface(This,riid,ppvObj,retval)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval) ) 

#define ITVS_ComEntity_AddRef(This,retval)	\
    ( (This)->lpVtbl -> AddRef(This,retval) ) 

#define ITVS_ComEntity_Release(This,retval)	\
    ( (This)->lpVtbl -> Release(This,retval) ) 

#define ITVS_ComEntity_GetTypeInfoCount(This,pctinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval) ) 

#define ITVS_ComEntity_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval) ) 

#define ITVS_ComEntity_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval) ) 

#define ITVS_ComEntity_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    ( (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval) ) 

#define ITVS_ComEntity_get_Handle(This,retval)	\
    ( (This)->lpVtbl -> get_Handle(This,retval) ) 

#define ITVS_ComEntity_get_ObjectName(This,retval)	\
    ( (This)->lpVtbl -> get_ObjectName(This,retval) ) 

#define ITVS_ComEntity_GetXData(This,AppName,XDataType,XDataValue,retval)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue,retval) ) 

#define ITVS_ComEntity_SetXData(This,XDataType,XDataValue,retval)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue,retval) ) 

#define ITVS_ComEntity_Delete(This,retval)	\
    ( (This)->lpVtbl -> Delete(This,retval) ) 

#define ITVS_ComEntity_get_ObjectID(This,retval)	\
    ( (This)->lpVtbl -> get_ObjectID(This,retval) ) 

#define ITVS_ComEntity_get_Application(This,retval)	\
    ( (This)->lpVtbl -> get_Application(This,retval) ) 

#define ITVS_ComEntity_get_Database(This,retval)	\
    ( (This)->lpVtbl -> get_Database(This,retval) ) 

#define ITVS_ComEntity_get_HasExtensionDictionary(This,retval)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,retval) ) 

#define ITVS_ComEntity_GetExtensionDictionary(This,retval)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,retval) ) 

#define ITVS_ComEntity_get_OwnerID(This,retval)	\
    ( (This)->lpVtbl -> get_OwnerID(This,retval) ) 

#define ITVS_ComEntity_get_Document(This,retval)	\
    ( (This)->lpVtbl -> get_Document(This,retval) ) 

#define ITVS_ComEntity_Erase(This,retval)	\
    ( (This)->lpVtbl -> Erase(This,retval) ) 

#define ITVS_ComEntity_get_TrueColor(This,retval)	\
    ( (This)->lpVtbl -> get_TrueColor(This,retval) ) 

#define ITVS_ComEntity_put_TrueColor(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TrueColor(This,noname,retval) ) 

#define ITVS_ComEntity_get_Layer(This,retval)	\
    ( (This)->lpVtbl -> get_Layer(This,retval) ) 

#define ITVS_ComEntity_put_Layer(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Layer(This,noname,retval) ) 

#define ITVS_ComEntity_get_Linetype(This,retval)	\
    ( (This)->lpVtbl -> get_Linetype(This,retval) ) 

#define ITVS_ComEntity_put_Linetype(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Linetype(This,noname,retval) ) 

#define ITVS_ComEntity_get_LinetypeScale(This,retval)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,retval) ) 

#define ITVS_ComEntity_put_LinetypeScale(This,noname,retval)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,noname,retval) ) 

#define ITVS_ComEntity_get_Visible(This,retval)	\
    ( (This)->lpVtbl -> get_Visible(This,retval) ) 

#define ITVS_ComEntity_put_Visible(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Visible(This,noname,retval) ) 

#define ITVS_ComEntity_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,retval)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,retval) ) 

#define ITVS_ComEntity_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,retval)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,retval) ) 

#define ITVS_ComEntity_Highlight(This,HighlightFlag,retval)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag,retval) ) 

#define ITVS_ComEntity_Copy(This,retval)	\
    ( (This)->lpVtbl -> Copy(This,retval) ) 

#define ITVS_ComEntity_Move(This,FromPoint,ToPoint,retval)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint,retval) ) 

#define ITVS_ComEntity_Rotate(This,BasePoint,RotationAngle,retval)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle,retval) ) 

#define ITVS_ComEntity_Rotate3D(This,Point1,Point2,RotationAngle,retval)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle,retval) ) 

#define ITVS_ComEntity_Mirror(This,Point1,Point2,retval)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,retval) ) 

#define ITVS_ComEntity_Mirror3D(This,Point1,Point2,point3,retval)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,retval) ) 

#define ITVS_ComEntity_ScaleEntity(This,BasePoint,ScaleFactor,retval)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor,retval) ) 

#define ITVS_ComEntity_TransformBy(This,TransformationMatrix,retval)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix,retval) ) 

#define ITVS_ComEntity_Update(This,retval)	\
    ( (This)->lpVtbl -> Update(This,retval) ) 

#define ITVS_ComEntity_GetBoundingBox(This,MinPoint,MaxPoint,retval)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint,retval) ) 

#define ITVS_ComEntity_IntersectWith(This,IntersectObject,option,retval)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,retval) ) 

#define ITVS_ComEntity_get_PlotStyleName(This,retval)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,retval) ) 

#define ITVS_ComEntity_put_PlotStyleName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,noname,retval) ) 

#define ITVS_ComEntity_get_Lineweight(This,retval)	\
    ( (This)->lpVtbl -> get_Lineweight(This,retval) ) 

#define ITVS_ComEntity_put_Lineweight(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Lineweight(This,noname,retval) ) 

#define ITVS_ComEntity_get_EntityTransparency(This,retval)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,retval) ) 

#define ITVS_ComEntity_put_EntityTransparency(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,noname,retval) ) 

#define ITVS_ComEntity_get_Hyperlinks(This,retval)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,retval) ) 

#define ITVS_ComEntity_get_Material(This,retval)	\
    ( (This)->lpVtbl -> get_Material(This,retval) ) 

#define ITVS_ComEntity_put_Material(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Material(This,noname,retval) ) 

#define ITVS_ComEntity_get_EntityName(This,retval)	\
    ( (This)->lpVtbl -> get_EntityName(This,retval) ) 

#define ITVS_ComEntity_get_EntityType(This,retval)	\
    ( (This)->lpVtbl -> get_EntityType(This,retval) ) 

#define ITVS_ComEntity_get_color(This,retval)	\
    ( (This)->lpVtbl -> get_color(This,retval) ) 

#define ITVS_ComEntity_put_color(This,noname,retval)	\
    ( (This)->lpVtbl -> put_color(This,noname,retval) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITVS_ComEntity_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TVS_ComEntity;

#ifdef __cplusplus

class DECLSPEC_UUID("C760D18C-F1EF-41B0-B0F3-D701645C7BDF")
TVS_ComEntity;
#endif

#ifndef __IComPipe_INTERFACE_DEFINED__
#define __IComPipe_INTERFACE_DEFINED__

/* interface IComPipe */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IComPipe;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B1C8DAB6-AFEC-4403-8CDA-7A5ABF82AE44")
    IComPipe : public IAcadEntity
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Dpr( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Dpr( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SizeB( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SizeB( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Flow( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Flow( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Speed( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Speed( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Length( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rotation( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Rotation( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__1D2D( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put__1D2D( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Parami( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Parami( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParamdP( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ParamdP( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Wipeout( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Wipeout( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Grani( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Grani( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ElevUp( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ElevUp( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Elev( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Elev( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ElevDown( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ElevDown( 
            /* [in] */ double newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IComPipeVtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComPipe * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            IComPipe * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            IComPipe * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IComPipe * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IComPipe * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IComPipe * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IComPipe * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IComPipe * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IComPipe * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IComPipe * This,
            /* [in][idldescattr] */ BSTR AppName,
            /* [out][idldescattr] */ VARIANT *XDataType,
            /* [out][idldescattr] */ VARIANT *XDataValue,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IComPipe * This,
            /* [in][idldescattr] */ VARIANT XDataType,
            /* [in][idldescattr] */ VARIANT XDataValue,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IComPipe * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IComPipe * This,
            /* [retval][out] */ LONG_PTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IComPipe * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IComPipe * This,
            /* [retval][out] */ IAcadDatabase **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IComPipe * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IComPipe * This,
            /* [retval][out] */ IAcadDictionary **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IComPipe * This,
            /* [retval][out] */ LONG_PTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IComPipe * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IComPipe * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IComPipe * This,
            /* [retval][out] */ IAcadAcCmColor **retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IComPipe * This,
            /* [in][idldescattr] */ IAcadAcCmColor *noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IComPipe * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IComPipe * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IComPipe * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IComPipe * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IComPipe * This,
            /* [retval][out] */ ACAD_NOUNITS *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IComPipe * This,
            /* [in][idldescattr] */ ACAD_NOUNITS noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IComPipe * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IComPipe * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IComPipe * This,
            /* [in][idldescattr] */ signed INT NumberOfObjects,
            /* [in][idldescattr] */ double AngleToFill,
            /* [in][idldescattr] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IComPipe * This,
            /* [in][idldescattr] */ signed INT NumberOfRows,
            /* [in][idldescattr] */ signed INT NumberOfColumns,
            /* [in][idldescattr] */ signed INT NumberOfLevels,
            /* [in][idldescattr] */ double DistBetweenRows,
            /* [in][idldescattr] */ double DistBetweenCols,
            /* [in][idldescattr] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IComPipe * This,
            /* [in][idldescattr] */ BOOLEAN HighlightFlag,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IComPipe * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IComPipe * This,
            /* [in][idldescattr] */ VARIANT FromPoint,
            /* [in][idldescattr] */ VARIANT ToPoint,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IComPipe * This,
            /* [in][idldescattr] */ VARIANT BasePoint,
            /* [in][idldescattr] */ double RotationAngle,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IComPipe * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [in][idldescattr] */ double RotationAngle,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IComPipe * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IComPipe * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [in][idldescattr] */ VARIANT point3,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IComPipe * This,
            /* [in][idldescattr] */ VARIANT BasePoint,
            /* [in][idldescattr] */ double ScaleFactor,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IComPipe * This,
            /* [in][idldescattr] */ VARIANT TransformationMatrix,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IComPipe * This,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IComPipe * This,
            /* [out][idldescattr] */ VARIANT *MinPoint,
            /* [out][idldescattr] */ VARIANT *MaxPoint,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IComPipe * This,
            /* [in][idldescattr] */ IDispatch *IntersectObject,
            /* [in][idldescattr] */ enum AcExtendOption option,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IComPipe * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IComPipe * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IComPipe * This,
            /* [retval][out] */ ACAD_LWEIGHT *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IComPipe * This,
            /* [in][idldescattr] */ ACAD_LWEIGHT noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IComPipe * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IComPipe * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IComPipe * This,
            /* [retval][out] */ IAcadHyperlinks **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IComPipe * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IComPipe * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IComPipe * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IComPipe * This,
            /* [retval][out] */ signed long *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_color )( 
            IComPipe * This,
            /* [retval][out] */ ACAD_COLOR *retval);
        
        /* [id][propput][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_color )( 
            IComPipe * This,
            /* [in][idldescattr] */ ACAD_COLOR noname,
            /* [retval][out] */ void *retval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dpr )( 
            IComPipe * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Dpr )( 
            IComPipe * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SizeB )( 
            IComPipe * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SizeB )( 
            IComPipe * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flow )( 
            IComPipe * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flow )( 
            IComPipe * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Speed )( 
            IComPipe * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Speed )( 
            IComPipe * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IComPipe * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Length )( 
            IComPipe * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rotation )( 
            IComPipe * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rotation )( 
            IComPipe * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__1D2D )( 
            IComPipe * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put__1D2D )( 
            IComPipe * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parami )( 
            IComPipe * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Parami )( 
            IComPipe * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParamdP )( 
            IComPipe * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ParamdP )( 
            IComPipe * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Wipeout )( 
            IComPipe * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Wipeout )( 
            IComPipe * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Grani )( 
            IComPipe * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Grani )( 
            IComPipe * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ElevUp )( 
            IComPipe * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ElevUp )( 
            IComPipe * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Elev )( 
            IComPipe * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Elev )( 
            IComPipe * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ElevDown )( 
            IComPipe * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ElevDown )( 
            IComPipe * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } IComPipeVtbl;

    interface IComPipe
    {
        CONST_VTBL struct IComPipeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComPipe_QueryInterface(This,riid,ppvObj,retval)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval) ) 

#define IComPipe_AddRef(This,retval)	\
    ( (This)->lpVtbl -> AddRef(This,retval) ) 

#define IComPipe_Release(This,retval)	\
    ( (This)->lpVtbl -> Release(This,retval) ) 

#define IComPipe_GetTypeInfoCount(This,pctinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval) ) 

#define IComPipe_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval) ) 

#define IComPipe_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval) ) 

#define IComPipe_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    ( (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval) ) 

#define IComPipe_get_Handle(This,retval)	\
    ( (This)->lpVtbl -> get_Handle(This,retval) ) 

#define IComPipe_get_ObjectName(This,retval)	\
    ( (This)->lpVtbl -> get_ObjectName(This,retval) ) 

#define IComPipe_GetXData(This,AppName,XDataType,XDataValue,retval)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue,retval) ) 

#define IComPipe_SetXData(This,XDataType,XDataValue,retval)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue,retval) ) 

#define IComPipe_Delete(This,retval)	\
    ( (This)->lpVtbl -> Delete(This,retval) ) 

#define IComPipe_get_ObjectID(This,retval)	\
    ( (This)->lpVtbl -> get_ObjectID(This,retval) ) 

#define IComPipe_get_Application(This,retval)	\
    ( (This)->lpVtbl -> get_Application(This,retval) ) 

#define IComPipe_get_Database(This,retval)	\
    ( (This)->lpVtbl -> get_Database(This,retval) ) 

#define IComPipe_get_HasExtensionDictionary(This,retval)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,retval) ) 

#define IComPipe_GetExtensionDictionary(This,retval)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,retval) ) 

#define IComPipe_get_OwnerID(This,retval)	\
    ( (This)->lpVtbl -> get_OwnerID(This,retval) ) 

#define IComPipe_get_Document(This,retval)	\
    ( (This)->lpVtbl -> get_Document(This,retval) ) 

#define IComPipe_Erase(This,retval)	\
    ( (This)->lpVtbl -> Erase(This,retval) ) 

#define IComPipe_get_TrueColor(This,retval)	\
    ( (This)->lpVtbl -> get_TrueColor(This,retval) ) 

#define IComPipe_put_TrueColor(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TrueColor(This,noname,retval) ) 

#define IComPipe_get_Layer(This,retval)	\
    ( (This)->lpVtbl -> get_Layer(This,retval) ) 

#define IComPipe_put_Layer(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Layer(This,noname,retval) ) 

#define IComPipe_get_Linetype(This,retval)	\
    ( (This)->lpVtbl -> get_Linetype(This,retval) ) 

#define IComPipe_put_Linetype(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Linetype(This,noname,retval) ) 

#define IComPipe_get_LinetypeScale(This,retval)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,retval) ) 

#define IComPipe_put_LinetypeScale(This,noname,retval)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,noname,retval) ) 

#define IComPipe_get_Visible(This,retval)	\
    ( (This)->lpVtbl -> get_Visible(This,retval) ) 

#define IComPipe_put_Visible(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Visible(This,noname,retval) ) 

#define IComPipe_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,retval)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,retval) ) 

#define IComPipe_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,retval)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,retval) ) 

#define IComPipe_Highlight(This,HighlightFlag,retval)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag,retval) ) 

#define IComPipe_Copy(This,retval)	\
    ( (This)->lpVtbl -> Copy(This,retval) ) 

#define IComPipe_Move(This,FromPoint,ToPoint,retval)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint,retval) ) 

#define IComPipe_Rotate(This,BasePoint,RotationAngle,retval)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle,retval) ) 

#define IComPipe_Rotate3D(This,Point1,Point2,RotationAngle,retval)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle,retval) ) 

#define IComPipe_Mirror(This,Point1,Point2,retval)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,retval) ) 

#define IComPipe_Mirror3D(This,Point1,Point2,point3,retval)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,retval) ) 

#define IComPipe_ScaleEntity(This,BasePoint,ScaleFactor,retval)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor,retval) ) 

#define IComPipe_TransformBy(This,TransformationMatrix,retval)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix,retval) ) 

#define IComPipe_Update(This,retval)	\
    ( (This)->lpVtbl -> Update(This,retval) ) 

#define IComPipe_GetBoundingBox(This,MinPoint,MaxPoint,retval)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint,retval) ) 

#define IComPipe_IntersectWith(This,IntersectObject,option,retval)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,retval) ) 

#define IComPipe_get_PlotStyleName(This,retval)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,retval) ) 

#define IComPipe_put_PlotStyleName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,noname,retval) ) 

#define IComPipe_get_Lineweight(This,retval)	\
    ( (This)->lpVtbl -> get_Lineweight(This,retval) ) 

#define IComPipe_put_Lineweight(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Lineweight(This,noname,retval) ) 

#define IComPipe_get_EntityTransparency(This,retval)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,retval) ) 

#define IComPipe_put_EntityTransparency(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,noname,retval) ) 

#define IComPipe_get_Hyperlinks(This,retval)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,retval) ) 

#define IComPipe_get_Material(This,retval)	\
    ( (This)->lpVtbl -> get_Material(This,retval) ) 

#define IComPipe_put_Material(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Material(This,noname,retval) ) 

#define IComPipe_get_EntityName(This,retval)	\
    ( (This)->lpVtbl -> get_EntityName(This,retval) ) 

#define IComPipe_get_EntityType(This,retval)	\
    ( (This)->lpVtbl -> get_EntityType(This,retval) ) 

#define IComPipe_get_color(This,retval)	\
    ( (This)->lpVtbl -> get_color(This,retval) ) 

#define IComPipe_put_color(This,noname,retval)	\
    ( (This)->lpVtbl -> put_color(This,noname,retval) ) 


#define IComPipe_get_Dpr(This,pVal)	\
    ( (This)->lpVtbl -> get_Dpr(This,pVal) ) 

#define IComPipe_put_Dpr(This,newVal)	\
    ( (This)->lpVtbl -> put_Dpr(This,newVal) ) 

#define IComPipe_get_SizeB(This,pVal)	\
    ( (This)->lpVtbl -> get_SizeB(This,pVal) ) 

#define IComPipe_put_SizeB(This,newVal)	\
    ( (This)->lpVtbl -> put_SizeB(This,newVal) ) 

#define IComPipe_get_Flow(This,pVal)	\
    ( (This)->lpVtbl -> get_Flow(This,pVal) ) 

#define IComPipe_put_Flow(This,newVal)	\
    ( (This)->lpVtbl -> put_Flow(This,newVal) ) 

#define IComPipe_get_Speed(This,pVal)	\
    ( (This)->lpVtbl -> get_Speed(This,pVal) ) 

#define IComPipe_put_Speed(This,newVal)	\
    ( (This)->lpVtbl -> put_Speed(This,newVal) ) 

#define IComPipe_get_Length(This,pVal)	\
    ( (This)->lpVtbl -> get_Length(This,pVal) ) 

#define IComPipe_put_Length(This,newVal)	\
    ( (This)->lpVtbl -> put_Length(This,newVal) ) 

#define IComPipe_get_Rotation(This,pVal)	\
    ( (This)->lpVtbl -> get_Rotation(This,pVal) ) 

#define IComPipe_put_Rotation(This,newVal)	\
    ( (This)->lpVtbl -> put_Rotation(This,newVal) ) 

#define IComPipe_get__1D2D(This,pVal)	\
    ( (This)->lpVtbl -> get__1D2D(This,pVal) ) 

#define IComPipe_put__1D2D(This,newVal)	\
    ( (This)->lpVtbl -> put__1D2D(This,newVal) ) 

#define IComPipe_get_Parami(This,pVal)	\
    ( (This)->lpVtbl -> get_Parami(This,pVal) ) 

#define IComPipe_put_Parami(This,newVal)	\
    ( (This)->lpVtbl -> put_Parami(This,newVal) ) 

#define IComPipe_get_ParamdP(This,pVal)	\
    ( (This)->lpVtbl -> get_ParamdP(This,pVal) ) 

#define IComPipe_put_ParamdP(This,newVal)	\
    ( (This)->lpVtbl -> put_ParamdP(This,newVal) ) 

#define IComPipe_get_Wipeout(This,pVal)	\
    ( (This)->lpVtbl -> get_Wipeout(This,pVal) ) 

#define IComPipe_put_Wipeout(This,newVal)	\
    ( (This)->lpVtbl -> put_Wipeout(This,newVal) ) 

#define IComPipe_get_Grani(This,pVal)	\
    ( (This)->lpVtbl -> get_Grani(This,pVal) ) 

#define IComPipe_put_Grani(This,newVal)	\
    ( (This)->lpVtbl -> put_Grani(This,newVal) ) 

#define IComPipe_get_ElevUp(This,pVal)	\
    ( (This)->lpVtbl -> get_ElevUp(This,pVal) ) 

#define IComPipe_put_ElevUp(This,newVal)	\
    ( (This)->lpVtbl -> put_ElevUp(This,newVal) ) 

#define IComPipe_get_Elev(This,pVal)	\
    ( (This)->lpVtbl -> get_Elev(This,pVal) ) 

#define IComPipe_put_Elev(This,newVal)	\
    ( (This)->lpVtbl -> put_Elev(This,newVal) ) 

#define IComPipe_get_ElevDown(This,pVal)	\
    ( (This)->lpVtbl -> get_ElevDown(This,pVal) ) 

#define IComPipe_put_ElevDown(This,newVal)	\
    ( (This)->lpVtbl -> put_ElevDown(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComPipe_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ComPipe;

#ifdef __cplusplus

class DECLSPEC_UUID("DA323AD7-6658-44BB-9D63-FB5558F85CB7")
ComPipe;
#endif

#ifndef __ICom_TAP_INTERFACE_DEFINED__
#define __ICom_TAP_INTERFACE_DEFINED__

/* interface ICom_TAP */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICom_TAP;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B6CE202D-92D8-4A2E-907A-CBFCAE4244F3")
    ICom_TAP : public IAcadEntity
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Dpr( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Dpr( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SizeB( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SizeB( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Flow( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Flow( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Speed( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Speed( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Angle( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Angle( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rotation( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Rotation( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__1D2D( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put__1D2D( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Wipeout( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Wipeout( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Elev( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Elev( 
            /* [in] */ double newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICom_TAPVtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            ICom_TAP * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            ICom_TAP * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICom_TAP * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            ICom_TAP * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            ICom_TAP * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ BSTR AppName,
            /* [out][idldescattr] */ VARIANT *XDataType,
            /* [out][idldescattr] */ VARIANT *XDataValue,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ VARIANT XDataType,
            /* [in][idldescattr] */ VARIANT XDataValue,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            ICom_TAP * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            ICom_TAP * This,
            /* [retval][out] */ LONG_PTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            ICom_TAP * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            ICom_TAP * This,
            /* [retval][out] */ IAcadDatabase **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            ICom_TAP * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            ICom_TAP * This,
            /* [retval][out] */ IAcadDictionary **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            ICom_TAP * This,
            /* [retval][out] */ LONG_PTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            ICom_TAP * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            ICom_TAP * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            ICom_TAP * This,
            /* [retval][out] */ IAcadAcCmColor **retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ IAcadAcCmColor *noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            ICom_TAP * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            ICom_TAP * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            ICom_TAP * This,
            /* [retval][out] */ ACAD_NOUNITS *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ ACAD_NOUNITS noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            ICom_TAP * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ signed INT NumberOfObjects,
            /* [in][idldescattr] */ double AngleToFill,
            /* [in][idldescattr] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ signed INT NumberOfRows,
            /* [in][idldescattr] */ signed INT NumberOfColumns,
            /* [in][idldescattr] */ signed INT NumberOfLevels,
            /* [in][idldescattr] */ double DistBetweenRows,
            /* [in][idldescattr] */ double DistBetweenCols,
            /* [in][idldescattr] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ BOOLEAN HighlightFlag,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            ICom_TAP * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ VARIANT FromPoint,
            /* [in][idldescattr] */ VARIANT ToPoint,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ VARIANT BasePoint,
            /* [in][idldescattr] */ double RotationAngle,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [in][idldescattr] */ double RotationAngle,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [in][idldescattr] */ VARIANT point3,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ VARIANT BasePoint,
            /* [in][idldescattr] */ double ScaleFactor,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ VARIANT TransformationMatrix,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            ICom_TAP * This,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            ICom_TAP * This,
            /* [out][idldescattr] */ VARIANT *MinPoint,
            /* [out][idldescattr] */ VARIANT *MaxPoint,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ IDispatch *IntersectObject,
            /* [in][idldescattr] */ enum AcExtendOption option,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            ICom_TAP * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            ICom_TAP * This,
            /* [retval][out] */ ACAD_LWEIGHT *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ ACAD_LWEIGHT noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            ICom_TAP * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            ICom_TAP * This,
            /* [retval][out] */ IAcadHyperlinks **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            ICom_TAP * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            ICom_TAP * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            ICom_TAP * This,
            /* [retval][out] */ signed long *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_color )( 
            ICom_TAP * This,
            /* [retval][out] */ ACAD_COLOR *retval);
        
        /* [id][propput][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_color )( 
            ICom_TAP * This,
            /* [in][idldescattr] */ ACAD_COLOR noname,
            /* [retval][out] */ void *retval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dpr )( 
            ICom_TAP * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Dpr )( 
            ICom_TAP * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SizeB )( 
            ICom_TAP * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SizeB )( 
            ICom_TAP * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flow )( 
            ICom_TAP * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flow )( 
            ICom_TAP * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Speed )( 
            ICom_TAP * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Speed )( 
            ICom_TAP * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Angle )( 
            ICom_TAP * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Angle )( 
            ICom_TAP * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rotation )( 
            ICom_TAP * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rotation )( 
            ICom_TAP * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__1D2D )( 
            ICom_TAP * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put__1D2D )( 
            ICom_TAP * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Wipeout )( 
            ICom_TAP * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Wipeout )( 
            ICom_TAP * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Elev )( 
            ICom_TAP * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Elev )( 
            ICom_TAP * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } ICom_TAPVtbl;

    interface ICom_TAP
    {
        CONST_VTBL struct ICom_TAPVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICom_TAP_QueryInterface(This,riid,ppvObj,retval)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval) ) 

#define ICom_TAP_AddRef(This,retval)	\
    ( (This)->lpVtbl -> AddRef(This,retval) ) 

#define ICom_TAP_Release(This,retval)	\
    ( (This)->lpVtbl -> Release(This,retval) ) 

#define ICom_TAP_GetTypeInfoCount(This,pctinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval) ) 

#define ICom_TAP_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval) ) 

#define ICom_TAP_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval) ) 

#define ICom_TAP_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    ( (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval) ) 

#define ICom_TAP_get_Handle(This,retval)	\
    ( (This)->lpVtbl -> get_Handle(This,retval) ) 

#define ICom_TAP_get_ObjectName(This,retval)	\
    ( (This)->lpVtbl -> get_ObjectName(This,retval) ) 

#define ICom_TAP_GetXData(This,AppName,XDataType,XDataValue,retval)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue,retval) ) 

#define ICom_TAP_SetXData(This,XDataType,XDataValue,retval)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue,retval) ) 

#define ICom_TAP_Delete(This,retval)	\
    ( (This)->lpVtbl -> Delete(This,retval) ) 

#define ICom_TAP_get_ObjectID(This,retval)	\
    ( (This)->lpVtbl -> get_ObjectID(This,retval) ) 

#define ICom_TAP_get_Application(This,retval)	\
    ( (This)->lpVtbl -> get_Application(This,retval) ) 

#define ICom_TAP_get_Database(This,retval)	\
    ( (This)->lpVtbl -> get_Database(This,retval) ) 

#define ICom_TAP_get_HasExtensionDictionary(This,retval)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,retval) ) 

#define ICom_TAP_GetExtensionDictionary(This,retval)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,retval) ) 

#define ICom_TAP_get_OwnerID(This,retval)	\
    ( (This)->lpVtbl -> get_OwnerID(This,retval) ) 

#define ICom_TAP_get_Document(This,retval)	\
    ( (This)->lpVtbl -> get_Document(This,retval) ) 

#define ICom_TAP_Erase(This,retval)	\
    ( (This)->lpVtbl -> Erase(This,retval) ) 

#define ICom_TAP_get_TrueColor(This,retval)	\
    ( (This)->lpVtbl -> get_TrueColor(This,retval) ) 

#define ICom_TAP_put_TrueColor(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TrueColor(This,noname,retval) ) 

#define ICom_TAP_get_Layer(This,retval)	\
    ( (This)->lpVtbl -> get_Layer(This,retval) ) 

#define ICom_TAP_put_Layer(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Layer(This,noname,retval) ) 

#define ICom_TAP_get_Linetype(This,retval)	\
    ( (This)->lpVtbl -> get_Linetype(This,retval) ) 

#define ICom_TAP_put_Linetype(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Linetype(This,noname,retval) ) 

#define ICom_TAP_get_LinetypeScale(This,retval)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,retval) ) 

#define ICom_TAP_put_LinetypeScale(This,noname,retval)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,noname,retval) ) 

#define ICom_TAP_get_Visible(This,retval)	\
    ( (This)->lpVtbl -> get_Visible(This,retval) ) 

#define ICom_TAP_put_Visible(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Visible(This,noname,retval) ) 

#define ICom_TAP_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,retval)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,retval) ) 

#define ICom_TAP_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,retval)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,retval) ) 

#define ICom_TAP_Highlight(This,HighlightFlag,retval)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag,retval) ) 

#define ICom_TAP_Copy(This,retval)	\
    ( (This)->lpVtbl -> Copy(This,retval) ) 

#define ICom_TAP_Move(This,FromPoint,ToPoint,retval)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint,retval) ) 

#define ICom_TAP_Rotate(This,BasePoint,RotationAngle,retval)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle,retval) ) 

#define ICom_TAP_Rotate3D(This,Point1,Point2,RotationAngle,retval)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle,retval) ) 

#define ICom_TAP_Mirror(This,Point1,Point2,retval)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,retval) ) 

#define ICom_TAP_Mirror3D(This,Point1,Point2,point3,retval)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,retval) ) 

#define ICom_TAP_ScaleEntity(This,BasePoint,ScaleFactor,retval)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor,retval) ) 

#define ICom_TAP_TransformBy(This,TransformationMatrix,retval)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix,retval) ) 

#define ICom_TAP_Update(This,retval)	\
    ( (This)->lpVtbl -> Update(This,retval) ) 

#define ICom_TAP_GetBoundingBox(This,MinPoint,MaxPoint,retval)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint,retval) ) 

#define ICom_TAP_IntersectWith(This,IntersectObject,option,retval)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,retval) ) 

#define ICom_TAP_get_PlotStyleName(This,retval)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,retval) ) 

#define ICom_TAP_put_PlotStyleName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,noname,retval) ) 

#define ICom_TAP_get_Lineweight(This,retval)	\
    ( (This)->lpVtbl -> get_Lineweight(This,retval) ) 

#define ICom_TAP_put_Lineweight(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Lineweight(This,noname,retval) ) 

#define ICom_TAP_get_EntityTransparency(This,retval)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,retval) ) 

#define ICom_TAP_put_EntityTransparency(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,noname,retval) ) 

#define ICom_TAP_get_Hyperlinks(This,retval)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,retval) ) 

#define ICom_TAP_get_Material(This,retval)	\
    ( (This)->lpVtbl -> get_Material(This,retval) ) 

#define ICom_TAP_put_Material(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Material(This,noname,retval) ) 

#define ICom_TAP_get_EntityName(This,retval)	\
    ( (This)->lpVtbl -> get_EntityName(This,retval) ) 

#define ICom_TAP_get_EntityType(This,retval)	\
    ( (This)->lpVtbl -> get_EntityType(This,retval) ) 

#define ICom_TAP_get_color(This,retval)	\
    ( (This)->lpVtbl -> get_color(This,retval) ) 

#define ICom_TAP_put_color(This,noname,retval)	\
    ( (This)->lpVtbl -> put_color(This,noname,retval) ) 


#define ICom_TAP_get_Dpr(This,pVal)	\
    ( (This)->lpVtbl -> get_Dpr(This,pVal) ) 

#define ICom_TAP_put_Dpr(This,newVal)	\
    ( (This)->lpVtbl -> put_Dpr(This,newVal) ) 

#define ICom_TAP_get_SizeB(This,pVal)	\
    ( (This)->lpVtbl -> get_SizeB(This,pVal) ) 

#define ICom_TAP_put_SizeB(This,newVal)	\
    ( (This)->lpVtbl -> put_SizeB(This,newVal) ) 

#define ICom_TAP_get_Flow(This,pVal)	\
    ( (This)->lpVtbl -> get_Flow(This,pVal) ) 

#define ICom_TAP_put_Flow(This,newVal)	\
    ( (This)->lpVtbl -> put_Flow(This,newVal) ) 

#define ICom_TAP_get_Speed(This,pVal)	\
    ( (This)->lpVtbl -> get_Speed(This,pVal) ) 

#define ICom_TAP_put_Speed(This,newVal)	\
    ( (This)->lpVtbl -> put_Speed(This,newVal) ) 

#define ICom_TAP_get_Angle(This,pVal)	\
    ( (This)->lpVtbl -> get_Angle(This,pVal) ) 

#define ICom_TAP_put_Angle(This,newVal)	\
    ( (This)->lpVtbl -> put_Angle(This,newVal) ) 

#define ICom_TAP_get_Rotation(This,pVal)	\
    ( (This)->lpVtbl -> get_Rotation(This,pVal) ) 

#define ICom_TAP_put_Rotation(This,newVal)	\
    ( (This)->lpVtbl -> put_Rotation(This,newVal) ) 

#define ICom_TAP_get__1D2D(This,pVal)	\
    ( (This)->lpVtbl -> get__1D2D(This,pVal) ) 

#define ICom_TAP_put__1D2D(This,newVal)	\
    ( (This)->lpVtbl -> put__1D2D(This,newVal) ) 

#define ICom_TAP_get_Wipeout(This,pVal)	\
    ( (This)->lpVtbl -> get_Wipeout(This,pVal) ) 

#define ICom_TAP_put_Wipeout(This,newVal)	\
    ( (This)->lpVtbl -> put_Wipeout(This,newVal) ) 

#define ICom_TAP_get_Elev(This,pVal)	\
    ( (This)->lpVtbl -> get_Elev(This,pVal) ) 

#define ICom_TAP_put_Elev(This,newVal)	\
    ( (This)->lpVtbl -> put_Elev(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICom_TAP_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Com_TAP;

#ifdef __cplusplus

class DECLSPEC_UUID("BA83A3D8-963F-423E-87FE-F977733B9C5B")
Com_TAP;
#endif

#ifndef __IComTrans_INTERFACE_DEFINED__
#define __IComTrans_INTERFACE_DEFINED__

/* interface IComTrans */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IComTrans;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B22CDDB1-CB06-4A06-8A4D-DA3135CAE57E")
    IComTrans : public IAcadEntity
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Dpr( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Dpr( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SizeB( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SizeB( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Dpr2( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Dpr2( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SizeB2( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SizeB2( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Length( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rotation( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Rotation( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__1D2D( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put__1D2D( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Wipeout( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Wipeout( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TransType( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TransType( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Elev( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Elev( 
            /* [in] */ double newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IComTransVtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComTrans * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            IComTrans * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            IComTrans * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IComTrans * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IComTrans * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IComTrans * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IComTrans * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IComTrans * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IComTrans * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IComTrans * This,
            /* [in][idldescattr] */ BSTR AppName,
            /* [out][idldescattr] */ VARIANT *XDataType,
            /* [out][idldescattr] */ VARIANT *XDataValue,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IComTrans * This,
            /* [in][idldescattr] */ VARIANT XDataType,
            /* [in][idldescattr] */ VARIANT XDataValue,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IComTrans * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IComTrans * This,
            /* [retval][out] */ LONG_PTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IComTrans * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IComTrans * This,
            /* [retval][out] */ IAcadDatabase **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IComTrans * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IComTrans * This,
            /* [retval][out] */ IAcadDictionary **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IComTrans * This,
            /* [retval][out] */ LONG_PTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IComTrans * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IComTrans * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IComTrans * This,
            /* [retval][out] */ IAcadAcCmColor **retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IComTrans * This,
            /* [in][idldescattr] */ IAcadAcCmColor *noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IComTrans * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IComTrans * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IComTrans * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IComTrans * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IComTrans * This,
            /* [retval][out] */ ACAD_NOUNITS *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IComTrans * This,
            /* [in][idldescattr] */ ACAD_NOUNITS noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IComTrans * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IComTrans * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IComTrans * This,
            /* [in][idldescattr] */ signed INT NumberOfObjects,
            /* [in][idldescattr] */ double AngleToFill,
            /* [in][idldescattr] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IComTrans * This,
            /* [in][idldescattr] */ signed INT NumberOfRows,
            /* [in][idldescattr] */ signed INT NumberOfColumns,
            /* [in][idldescattr] */ signed INT NumberOfLevels,
            /* [in][idldescattr] */ double DistBetweenRows,
            /* [in][idldescattr] */ double DistBetweenCols,
            /* [in][idldescattr] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IComTrans * This,
            /* [in][idldescattr] */ BOOLEAN HighlightFlag,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IComTrans * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IComTrans * This,
            /* [in][idldescattr] */ VARIANT FromPoint,
            /* [in][idldescattr] */ VARIANT ToPoint,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IComTrans * This,
            /* [in][idldescattr] */ VARIANT BasePoint,
            /* [in][idldescattr] */ double RotationAngle,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IComTrans * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [in][idldescattr] */ double RotationAngle,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IComTrans * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IComTrans * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [in][idldescattr] */ VARIANT point3,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IComTrans * This,
            /* [in][idldescattr] */ VARIANT BasePoint,
            /* [in][idldescattr] */ double ScaleFactor,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IComTrans * This,
            /* [in][idldescattr] */ VARIANT TransformationMatrix,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IComTrans * This,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IComTrans * This,
            /* [out][idldescattr] */ VARIANT *MinPoint,
            /* [out][idldescattr] */ VARIANT *MaxPoint,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IComTrans * This,
            /* [in][idldescattr] */ IDispatch *IntersectObject,
            /* [in][idldescattr] */ enum AcExtendOption option,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IComTrans * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IComTrans * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IComTrans * This,
            /* [retval][out] */ ACAD_LWEIGHT *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IComTrans * This,
            /* [in][idldescattr] */ ACAD_LWEIGHT noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IComTrans * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IComTrans * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IComTrans * This,
            /* [retval][out] */ IAcadHyperlinks **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IComTrans * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IComTrans * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IComTrans * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IComTrans * This,
            /* [retval][out] */ signed long *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_color )( 
            IComTrans * This,
            /* [retval][out] */ ACAD_COLOR *retval);
        
        /* [id][propput][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_color )( 
            IComTrans * This,
            /* [in][idldescattr] */ ACAD_COLOR noname,
            /* [retval][out] */ void *retval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dpr )( 
            IComTrans * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Dpr )( 
            IComTrans * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SizeB )( 
            IComTrans * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SizeB )( 
            IComTrans * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dpr2 )( 
            IComTrans * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Dpr2 )( 
            IComTrans * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SizeB2 )( 
            IComTrans * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SizeB2 )( 
            IComTrans * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IComTrans * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Length )( 
            IComTrans * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rotation )( 
            IComTrans * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rotation )( 
            IComTrans * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__1D2D )( 
            IComTrans * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put__1D2D )( 
            IComTrans * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Wipeout )( 
            IComTrans * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Wipeout )( 
            IComTrans * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TransType )( 
            IComTrans * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TransType )( 
            IComTrans * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Elev )( 
            IComTrans * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Elev )( 
            IComTrans * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } IComTransVtbl;

    interface IComTrans
    {
        CONST_VTBL struct IComTransVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComTrans_QueryInterface(This,riid,ppvObj,retval)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval) ) 

#define IComTrans_AddRef(This,retval)	\
    ( (This)->lpVtbl -> AddRef(This,retval) ) 

#define IComTrans_Release(This,retval)	\
    ( (This)->lpVtbl -> Release(This,retval) ) 

#define IComTrans_GetTypeInfoCount(This,pctinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval) ) 

#define IComTrans_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval) ) 

#define IComTrans_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval) ) 

#define IComTrans_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    ( (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval) ) 

#define IComTrans_get_Handle(This,retval)	\
    ( (This)->lpVtbl -> get_Handle(This,retval) ) 

#define IComTrans_get_ObjectName(This,retval)	\
    ( (This)->lpVtbl -> get_ObjectName(This,retval) ) 

#define IComTrans_GetXData(This,AppName,XDataType,XDataValue,retval)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue,retval) ) 

#define IComTrans_SetXData(This,XDataType,XDataValue,retval)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue,retval) ) 

#define IComTrans_Delete(This,retval)	\
    ( (This)->lpVtbl -> Delete(This,retval) ) 

#define IComTrans_get_ObjectID(This,retval)	\
    ( (This)->lpVtbl -> get_ObjectID(This,retval) ) 

#define IComTrans_get_Application(This,retval)	\
    ( (This)->lpVtbl -> get_Application(This,retval) ) 

#define IComTrans_get_Database(This,retval)	\
    ( (This)->lpVtbl -> get_Database(This,retval) ) 

#define IComTrans_get_HasExtensionDictionary(This,retval)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,retval) ) 

#define IComTrans_GetExtensionDictionary(This,retval)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,retval) ) 

#define IComTrans_get_OwnerID(This,retval)	\
    ( (This)->lpVtbl -> get_OwnerID(This,retval) ) 

#define IComTrans_get_Document(This,retval)	\
    ( (This)->lpVtbl -> get_Document(This,retval) ) 

#define IComTrans_Erase(This,retval)	\
    ( (This)->lpVtbl -> Erase(This,retval) ) 

#define IComTrans_get_TrueColor(This,retval)	\
    ( (This)->lpVtbl -> get_TrueColor(This,retval) ) 

#define IComTrans_put_TrueColor(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TrueColor(This,noname,retval) ) 

#define IComTrans_get_Layer(This,retval)	\
    ( (This)->lpVtbl -> get_Layer(This,retval) ) 

#define IComTrans_put_Layer(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Layer(This,noname,retval) ) 

#define IComTrans_get_Linetype(This,retval)	\
    ( (This)->lpVtbl -> get_Linetype(This,retval) ) 

#define IComTrans_put_Linetype(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Linetype(This,noname,retval) ) 

#define IComTrans_get_LinetypeScale(This,retval)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,retval) ) 

#define IComTrans_put_LinetypeScale(This,noname,retval)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,noname,retval) ) 

#define IComTrans_get_Visible(This,retval)	\
    ( (This)->lpVtbl -> get_Visible(This,retval) ) 

#define IComTrans_put_Visible(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Visible(This,noname,retval) ) 

#define IComTrans_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,retval)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,retval) ) 

#define IComTrans_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,retval)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,retval) ) 

#define IComTrans_Highlight(This,HighlightFlag,retval)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag,retval) ) 

#define IComTrans_Copy(This,retval)	\
    ( (This)->lpVtbl -> Copy(This,retval) ) 

#define IComTrans_Move(This,FromPoint,ToPoint,retval)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint,retval) ) 

#define IComTrans_Rotate(This,BasePoint,RotationAngle,retval)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle,retval) ) 

#define IComTrans_Rotate3D(This,Point1,Point2,RotationAngle,retval)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle,retval) ) 

#define IComTrans_Mirror(This,Point1,Point2,retval)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,retval) ) 

#define IComTrans_Mirror3D(This,Point1,Point2,point3,retval)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,retval) ) 

#define IComTrans_ScaleEntity(This,BasePoint,ScaleFactor,retval)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor,retval) ) 

#define IComTrans_TransformBy(This,TransformationMatrix,retval)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix,retval) ) 

#define IComTrans_Update(This,retval)	\
    ( (This)->lpVtbl -> Update(This,retval) ) 

#define IComTrans_GetBoundingBox(This,MinPoint,MaxPoint,retval)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint,retval) ) 

#define IComTrans_IntersectWith(This,IntersectObject,option,retval)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,retval) ) 

#define IComTrans_get_PlotStyleName(This,retval)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,retval) ) 

#define IComTrans_put_PlotStyleName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,noname,retval) ) 

#define IComTrans_get_Lineweight(This,retval)	\
    ( (This)->lpVtbl -> get_Lineweight(This,retval) ) 

#define IComTrans_put_Lineweight(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Lineweight(This,noname,retval) ) 

#define IComTrans_get_EntityTransparency(This,retval)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,retval) ) 

#define IComTrans_put_EntityTransparency(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,noname,retval) ) 

#define IComTrans_get_Hyperlinks(This,retval)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,retval) ) 

#define IComTrans_get_Material(This,retval)	\
    ( (This)->lpVtbl -> get_Material(This,retval) ) 

#define IComTrans_put_Material(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Material(This,noname,retval) ) 

#define IComTrans_get_EntityName(This,retval)	\
    ( (This)->lpVtbl -> get_EntityName(This,retval) ) 

#define IComTrans_get_EntityType(This,retval)	\
    ( (This)->lpVtbl -> get_EntityType(This,retval) ) 

#define IComTrans_get_color(This,retval)	\
    ( (This)->lpVtbl -> get_color(This,retval) ) 

#define IComTrans_put_color(This,noname,retval)	\
    ( (This)->lpVtbl -> put_color(This,noname,retval) ) 


#define IComTrans_get_Dpr(This,pVal)	\
    ( (This)->lpVtbl -> get_Dpr(This,pVal) ) 

#define IComTrans_put_Dpr(This,newVal)	\
    ( (This)->lpVtbl -> put_Dpr(This,newVal) ) 

#define IComTrans_get_SizeB(This,pVal)	\
    ( (This)->lpVtbl -> get_SizeB(This,pVal) ) 

#define IComTrans_put_SizeB(This,newVal)	\
    ( (This)->lpVtbl -> put_SizeB(This,newVal) ) 

#define IComTrans_get_Dpr2(This,pVal)	\
    ( (This)->lpVtbl -> get_Dpr2(This,pVal) ) 

#define IComTrans_put_Dpr2(This,newVal)	\
    ( (This)->lpVtbl -> put_Dpr2(This,newVal) ) 

#define IComTrans_get_SizeB2(This,pVal)	\
    ( (This)->lpVtbl -> get_SizeB2(This,pVal) ) 

#define IComTrans_put_SizeB2(This,newVal)	\
    ( (This)->lpVtbl -> put_SizeB2(This,newVal) ) 

#define IComTrans_get_Length(This,pVal)	\
    ( (This)->lpVtbl -> get_Length(This,pVal) ) 

#define IComTrans_put_Length(This,newVal)	\
    ( (This)->lpVtbl -> put_Length(This,newVal) ) 

#define IComTrans_get_Rotation(This,pVal)	\
    ( (This)->lpVtbl -> get_Rotation(This,pVal) ) 

#define IComTrans_put_Rotation(This,newVal)	\
    ( (This)->lpVtbl -> put_Rotation(This,newVal) ) 

#define IComTrans_get__1D2D(This,pVal)	\
    ( (This)->lpVtbl -> get__1D2D(This,pVal) ) 

#define IComTrans_put__1D2D(This,newVal)	\
    ( (This)->lpVtbl -> put__1D2D(This,newVal) ) 

#define IComTrans_get_Wipeout(This,pVal)	\
    ( (This)->lpVtbl -> get_Wipeout(This,pVal) ) 

#define IComTrans_put_Wipeout(This,newVal)	\
    ( (This)->lpVtbl -> put_Wipeout(This,newVal) ) 

#define IComTrans_get_TransType(This,pVal)	\
    ( (This)->lpVtbl -> get_TransType(This,pVal) ) 

#define IComTrans_put_TransType(This,newVal)	\
    ( (This)->lpVtbl -> put_TransType(This,newVal) ) 

#define IComTrans_get_Elev(This,pVal)	\
    ( (This)->lpVtbl -> get_Elev(This,pVal) ) 

#define IComTrans_put_Elev(This,newVal)	\
    ( (This)->lpVtbl -> put_Elev(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComTrans_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ComTrans;

#ifdef __cplusplus

class DECLSPEC_UUID("9C5FB63E-34A2-40DE-97BD-25B449439C7F")
ComTrans;
#endif

#ifndef __IComWye_INTERFACE_DEFINED__
#define __IComWye_INTERFACE_DEFINED__

/* interface IComWye */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IComWye;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("561C4980-5DBB-423C-9191-F184793BFD2E")
    IComWye : public IAcadEntity
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Dpr( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Dpr( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SizeB( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SizeB( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Dpr2( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Dpr2( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SizeB2( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SizeB2( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Length( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rotation( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Rotation( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__1D2D( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put__1D2D( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Wipeout( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Wipeout( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Elev( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Elev( 
            /* [in] */ double newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IComWyeVtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComWye * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            IComWye * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            IComWye * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IComWye * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IComWye * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IComWye * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IComWye * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IComWye * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IComWye * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IComWye * This,
            /* [in][idldescattr] */ BSTR AppName,
            /* [out][idldescattr] */ VARIANT *XDataType,
            /* [out][idldescattr] */ VARIANT *XDataValue,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IComWye * This,
            /* [in][idldescattr] */ VARIANT XDataType,
            /* [in][idldescattr] */ VARIANT XDataValue,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IComWye * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IComWye * This,
            /* [retval][out] */ LONG_PTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IComWye * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IComWye * This,
            /* [retval][out] */ IAcadDatabase **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IComWye * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IComWye * This,
            /* [retval][out] */ IAcadDictionary **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IComWye * This,
            /* [retval][out] */ LONG_PTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IComWye * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IComWye * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IComWye * This,
            /* [retval][out] */ IAcadAcCmColor **retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IComWye * This,
            /* [in][idldescattr] */ IAcadAcCmColor *noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IComWye * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IComWye * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IComWye * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IComWye * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IComWye * This,
            /* [retval][out] */ ACAD_NOUNITS *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IComWye * This,
            /* [in][idldescattr] */ ACAD_NOUNITS noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IComWye * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IComWye * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IComWye * This,
            /* [in][idldescattr] */ signed INT NumberOfObjects,
            /* [in][idldescattr] */ double AngleToFill,
            /* [in][idldescattr] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IComWye * This,
            /* [in][idldescattr] */ signed INT NumberOfRows,
            /* [in][idldescattr] */ signed INT NumberOfColumns,
            /* [in][idldescattr] */ signed INT NumberOfLevels,
            /* [in][idldescattr] */ double DistBetweenRows,
            /* [in][idldescattr] */ double DistBetweenCols,
            /* [in][idldescattr] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IComWye * This,
            /* [in][idldescattr] */ BOOLEAN HighlightFlag,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IComWye * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IComWye * This,
            /* [in][idldescattr] */ VARIANT FromPoint,
            /* [in][idldescattr] */ VARIANT ToPoint,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IComWye * This,
            /* [in][idldescattr] */ VARIANT BasePoint,
            /* [in][idldescattr] */ double RotationAngle,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IComWye * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [in][idldescattr] */ double RotationAngle,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IComWye * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IComWye * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [in][idldescattr] */ VARIANT point3,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IComWye * This,
            /* [in][idldescattr] */ VARIANT BasePoint,
            /* [in][idldescattr] */ double ScaleFactor,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IComWye * This,
            /* [in][idldescattr] */ VARIANT TransformationMatrix,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IComWye * This,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IComWye * This,
            /* [out][idldescattr] */ VARIANT *MinPoint,
            /* [out][idldescattr] */ VARIANT *MaxPoint,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IComWye * This,
            /* [in][idldescattr] */ IDispatch *IntersectObject,
            /* [in][idldescattr] */ enum AcExtendOption option,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IComWye * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IComWye * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IComWye * This,
            /* [retval][out] */ ACAD_LWEIGHT *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IComWye * This,
            /* [in][idldescattr] */ ACAD_LWEIGHT noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IComWye * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IComWye * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IComWye * This,
            /* [retval][out] */ IAcadHyperlinks **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IComWye * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IComWye * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IComWye * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IComWye * This,
            /* [retval][out] */ signed long *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_color )( 
            IComWye * This,
            /* [retval][out] */ ACAD_COLOR *retval);
        
        /* [id][propput][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_color )( 
            IComWye * This,
            /* [in][idldescattr] */ ACAD_COLOR noname,
            /* [retval][out] */ void *retval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dpr )( 
            IComWye * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Dpr )( 
            IComWye * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SizeB )( 
            IComWye * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SizeB )( 
            IComWye * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dpr2 )( 
            IComWye * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Dpr2 )( 
            IComWye * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SizeB2 )( 
            IComWye * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SizeB2 )( 
            IComWye * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IComWye * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Length )( 
            IComWye * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rotation )( 
            IComWye * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rotation )( 
            IComWye * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__1D2D )( 
            IComWye * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put__1D2D )( 
            IComWye * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Wipeout )( 
            IComWye * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Wipeout )( 
            IComWye * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Elev )( 
            IComWye * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Elev )( 
            IComWye * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } IComWyeVtbl;

    interface IComWye
    {
        CONST_VTBL struct IComWyeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComWye_QueryInterface(This,riid,ppvObj,retval)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval) ) 

#define IComWye_AddRef(This,retval)	\
    ( (This)->lpVtbl -> AddRef(This,retval) ) 

#define IComWye_Release(This,retval)	\
    ( (This)->lpVtbl -> Release(This,retval) ) 

#define IComWye_GetTypeInfoCount(This,pctinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval) ) 

#define IComWye_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval) ) 

#define IComWye_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval) ) 

#define IComWye_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    ( (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval) ) 

#define IComWye_get_Handle(This,retval)	\
    ( (This)->lpVtbl -> get_Handle(This,retval) ) 

#define IComWye_get_ObjectName(This,retval)	\
    ( (This)->lpVtbl -> get_ObjectName(This,retval) ) 

#define IComWye_GetXData(This,AppName,XDataType,XDataValue,retval)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue,retval) ) 

#define IComWye_SetXData(This,XDataType,XDataValue,retval)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue,retval) ) 

#define IComWye_Delete(This,retval)	\
    ( (This)->lpVtbl -> Delete(This,retval) ) 

#define IComWye_get_ObjectID(This,retval)	\
    ( (This)->lpVtbl -> get_ObjectID(This,retval) ) 

#define IComWye_get_Application(This,retval)	\
    ( (This)->lpVtbl -> get_Application(This,retval) ) 

#define IComWye_get_Database(This,retval)	\
    ( (This)->lpVtbl -> get_Database(This,retval) ) 

#define IComWye_get_HasExtensionDictionary(This,retval)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,retval) ) 

#define IComWye_GetExtensionDictionary(This,retval)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,retval) ) 

#define IComWye_get_OwnerID(This,retval)	\
    ( (This)->lpVtbl -> get_OwnerID(This,retval) ) 

#define IComWye_get_Document(This,retval)	\
    ( (This)->lpVtbl -> get_Document(This,retval) ) 

#define IComWye_Erase(This,retval)	\
    ( (This)->lpVtbl -> Erase(This,retval) ) 

#define IComWye_get_TrueColor(This,retval)	\
    ( (This)->lpVtbl -> get_TrueColor(This,retval) ) 

#define IComWye_put_TrueColor(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TrueColor(This,noname,retval) ) 

#define IComWye_get_Layer(This,retval)	\
    ( (This)->lpVtbl -> get_Layer(This,retval) ) 

#define IComWye_put_Layer(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Layer(This,noname,retval) ) 

#define IComWye_get_Linetype(This,retval)	\
    ( (This)->lpVtbl -> get_Linetype(This,retval) ) 

#define IComWye_put_Linetype(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Linetype(This,noname,retval) ) 

#define IComWye_get_LinetypeScale(This,retval)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,retval) ) 

#define IComWye_put_LinetypeScale(This,noname,retval)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,noname,retval) ) 

#define IComWye_get_Visible(This,retval)	\
    ( (This)->lpVtbl -> get_Visible(This,retval) ) 

#define IComWye_put_Visible(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Visible(This,noname,retval) ) 

#define IComWye_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,retval)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,retval) ) 

#define IComWye_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,retval)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,retval) ) 

#define IComWye_Highlight(This,HighlightFlag,retval)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag,retval) ) 

#define IComWye_Copy(This,retval)	\
    ( (This)->lpVtbl -> Copy(This,retval) ) 

#define IComWye_Move(This,FromPoint,ToPoint,retval)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint,retval) ) 

#define IComWye_Rotate(This,BasePoint,RotationAngle,retval)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle,retval) ) 

#define IComWye_Rotate3D(This,Point1,Point2,RotationAngle,retval)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle,retval) ) 

#define IComWye_Mirror(This,Point1,Point2,retval)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,retval) ) 

#define IComWye_Mirror3D(This,Point1,Point2,point3,retval)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,retval) ) 

#define IComWye_ScaleEntity(This,BasePoint,ScaleFactor,retval)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor,retval) ) 

#define IComWye_TransformBy(This,TransformationMatrix,retval)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix,retval) ) 

#define IComWye_Update(This,retval)	\
    ( (This)->lpVtbl -> Update(This,retval) ) 

#define IComWye_GetBoundingBox(This,MinPoint,MaxPoint,retval)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint,retval) ) 

#define IComWye_IntersectWith(This,IntersectObject,option,retval)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,retval) ) 

#define IComWye_get_PlotStyleName(This,retval)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,retval) ) 

#define IComWye_put_PlotStyleName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,noname,retval) ) 

#define IComWye_get_Lineweight(This,retval)	\
    ( (This)->lpVtbl -> get_Lineweight(This,retval) ) 

#define IComWye_put_Lineweight(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Lineweight(This,noname,retval) ) 

#define IComWye_get_EntityTransparency(This,retval)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,retval) ) 

#define IComWye_put_EntityTransparency(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,noname,retval) ) 

#define IComWye_get_Hyperlinks(This,retval)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,retval) ) 

#define IComWye_get_Material(This,retval)	\
    ( (This)->lpVtbl -> get_Material(This,retval) ) 

#define IComWye_put_Material(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Material(This,noname,retval) ) 

#define IComWye_get_EntityName(This,retval)	\
    ( (This)->lpVtbl -> get_EntityName(This,retval) ) 

#define IComWye_get_EntityType(This,retval)	\
    ( (This)->lpVtbl -> get_EntityType(This,retval) ) 

#define IComWye_get_color(This,retval)	\
    ( (This)->lpVtbl -> get_color(This,retval) ) 

#define IComWye_put_color(This,noname,retval)	\
    ( (This)->lpVtbl -> put_color(This,noname,retval) ) 


#define IComWye_get_Dpr(This,pVal)	\
    ( (This)->lpVtbl -> get_Dpr(This,pVal) ) 

#define IComWye_put_Dpr(This,newVal)	\
    ( (This)->lpVtbl -> put_Dpr(This,newVal) ) 

#define IComWye_get_SizeB(This,pVal)	\
    ( (This)->lpVtbl -> get_SizeB(This,pVal) ) 

#define IComWye_put_SizeB(This,newVal)	\
    ( (This)->lpVtbl -> put_SizeB(This,newVal) ) 

#define IComWye_get_Dpr2(This,pVal)	\
    ( (This)->lpVtbl -> get_Dpr2(This,pVal) ) 

#define IComWye_put_Dpr2(This,newVal)	\
    ( (This)->lpVtbl -> put_Dpr2(This,newVal) ) 

#define IComWye_get_SizeB2(This,pVal)	\
    ( (This)->lpVtbl -> get_SizeB2(This,pVal) ) 

#define IComWye_put_SizeB2(This,newVal)	\
    ( (This)->lpVtbl -> put_SizeB2(This,newVal) ) 

#define IComWye_get_Length(This,pVal)	\
    ( (This)->lpVtbl -> get_Length(This,pVal) ) 

#define IComWye_put_Length(This,newVal)	\
    ( (This)->lpVtbl -> put_Length(This,newVal) ) 

#define IComWye_get_Rotation(This,pVal)	\
    ( (This)->lpVtbl -> get_Rotation(This,pVal) ) 

#define IComWye_put_Rotation(This,newVal)	\
    ( (This)->lpVtbl -> put_Rotation(This,newVal) ) 

#define IComWye_get__1D2D(This,pVal)	\
    ( (This)->lpVtbl -> get__1D2D(This,pVal) ) 

#define IComWye_put__1D2D(This,newVal)	\
    ( (This)->lpVtbl -> put__1D2D(This,newVal) ) 

#define IComWye_get_Wipeout(This,pVal)	\
    ( (This)->lpVtbl -> get_Wipeout(This,pVal) ) 

#define IComWye_put_Wipeout(This,newVal)	\
    ( (This)->lpVtbl -> put_Wipeout(This,newVal) ) 

#define IComWye_get_Elev(This,pVal)	\
    ( (This)->lpVtbl -> get_Elev(This,pVal) ) 

#define IComWye_put_Elev(This,newVal)	\
    ( (This)->lpVtbl -> put_Elev(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComWye_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ComWye;

#ifdef __cplusplus

class DECLSPEC_UUID("E7A4FCFE-8ED9-4C74-9ACB-776DB31AE4AC")
ComWye;
#endif
#endif /* __TVSTVS_Ventilation_DBXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


