// (C) Copyright 2002-2007 by Autodesk, Inc. 
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
//----- ComTrans.h : Declaration of the CComTrans
//-----------------------------------------------------------------------------
#pragma once
#include "resource.h"

#include "TVS_TRANS.h"
#include "TVS_ComEntity.h"



#define DISPID_A  0x01
#define DISPID_SizeB  0x02
//#define DISPID_Flow  0x03
//#define DISPID_Speed  0x04
#define DISPID_A2  0x03
#define DISPID_SizeB2  0x04
#define DISPID_Length  0x05
#define DISPID_Rotation  0x06
#define DISPID_1D2D  0x07
#define DISPID_Wipeout 0x08
#define DISPID_TransType 0x09
#define DISPID_Elev 0x0A
#define DISPID_Tag1 0x0B
#define DISPID_Tag2 0x0C
//----- CComTrans
class ATL_NO_VTABLE CComTrans : 
		public CTVS_ComEntity,
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CComTrans, &CLSID_ComTrans>,
	public ISupportErrorInfo,
	public IOPMPropertyExtensionImpl<CComTrans>,
	public IOPMPropertyExpander,
	public IAcadEntityDispatchImpl<CComTrans, &CLSID_ComTrans, IComTrans, &IID_IComTrans, &LIBID_TVSTVS_Ventilation_DBXLib>
	//- Please do not remove the following line. It is here to make the Visual Studio ATL Wizards
	//- running properly. The class will not compile but is required by Visual Studio to recognize
	//-	this class as being an ATL class
	//- Uncomment the following line when you want to use the ATL Wizards to add a member or method
	//- to its interface.
	//,public IDispatchImpl<Ighfghgfh, &IID_IIghfghgfh, &LIBID_adskArxProject1Lib>
{
public:
	CComTrans () {
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_COMTRANS)

	BEGIN_COM_MAP(CComTrans)
		COM_INTERFACE_ENTRY(IComTrans)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
		COM_INTERFACE_ENTRY(IOPMPropertyExtension)
		COM_INTERFACE_ENTRY(ICategorizeProperties)
		COM_INTERFACE_ENTRY(IPerPropertyBrowsing)
		COM_INTERFACE_ENTRY(IOPMPropertyExpander)
		COM_INTERFACE_ENTRY(IAcadBaseObject)
		COM_INTERFACE_ENTRY(IAcadBaseObject2)
		COM_INTERFACE_ENTRY(IAcadObject)
		COM_INTERFACE_ENTRY(IAcadEntity)
		COM_INTERFACE_ENTRY(IRetrieveApplication)
	END_COM_MAP()

	//----- ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct () {
		return (S_OK) ;
	}

	void FinalRelease () {
	}

	//IAcadBaseObjectImpl
	virtual HRESULT CreateNewObject (AcDbObjectId &objId, AcDbObjectId &ownerId, TCHAR *keyName);
	//IAcadBaseObject2Impl
	STDMETHOD(ForceDbResident)(VARIANT_BOOL *forceDbResident) ;
	STDMETHOD(CreateObject)(AcDbObjectId ownerId =AcDbObjectId::kNull, TCHAR *keyName =NULL);
	STDMETHOD(AddToDb)(AcDbObjectId &objId, AcDbObjectId ownerId =AcDbObjectId::kNull, TCHAR *keyName =NULL);

	//IOPMPropertyExtension
	BEGIN_OPMPROP_MAP()

		OPMPROP_ENTRY(0, DISPID_A, PROPCAT_Data, \
		0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, DISPID_Length, PROPCAT_Data, \
		0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, DISPID_1D2D, PROPCAT_Data, \
		0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, DISPID_SizeB, PROPCAT_Data, \
		0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		//OPMPROP_ENTRY(0, DISPID_Speed, PROPCAT_Data, \
		//0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		//OPMPROP_ENTRY(0, DISPID_Flow, PROPCAT_Data, \
		//0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, DISPID_Rotation, PROPCAT_Data, \
		0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")

		OPMPROP_ENTRY(0, DISPID_A2, PROPCAT_Data, \
		0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, DISPID_SizeB2, PROPCAT_Data, \
		0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, DISPID_Wipeout, PROPCAT_Data, \
		0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, DISPID_TransType, PROPCAT_Data, \
		0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, DISPID_Elev, PROPCAT_Data, \
		0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, DISPID_Tag1, PROPCAT_Data, \
		0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, DISPID_Tag2, PROPCAT_Data, \
		0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")

		//----- Use the OPMPROP_ENTRY/OPMPROP_CAT_ENTRY macros for each of your properties
	END_OPMPROP_MAP()
	//IOPMPropertyExtensionImpl
	virtual HINSTANCE GetResourceInstance () { return (_hdllInstance) ; }

	//IOPMPropertyExpander
	STDMETHOD(GetElementValue)(/*[in]*/DISPID dispID, /*[in]*/DWORD dwCookie, /*[out]*/VARIANT *pVarOut);
	STDMETHOD(SetElementValue)(/*[in]*/DISPID dispID, /*[in]*/DWORD dwCookie, /*[in]*/VARIANT VarIn);
	STDMETHOD(GetElementStrings)(/*[in]*/DISPID dispID, /*[out]*/OPMLPOLESTR __RPC_FAR *pCaStringsOut, /*[out]*/OPMDWORD __RPC_FAR *pCaCookiesOut);
	STDMETHOD(GetElementGrouping)(/*[in]*/DISPID dispID, /*[out]*/short *groupingNumber);
	STDMETHOD(GetGroupCount)(/*[in]*/DISPID dispID, /*[out]*/long *nGroupCnt);



public:
	//IComTrans
	STDMETHOD(GetDisplayName) (DISPID dispId, BSTR *propName); // это в h-файл враппера 

	STDMETHOD(get_Dpr)(/*[out, retval]*/ double  *pVal);
	STDMETHOD(put_Dpr)(/*[in]*/ double newVal);
	STDMETHOD(get_SizeB)(/*[out, retval]*/ double  *pVal);
	STDMETHOD(put_SizeB)(/*[in]*/ double newVal);
	//STDMETHOD(get_Speed)(/*[out, retval]*/ double  *pVal);
	//STDMETHOD(put_Speed)(/*[in]*/ double newVal);
	//STDMETHOD(get_Flow)(/*[out, retval]*/ double  *pVal);
	//STDMETHOD(put_Flow)(/*[in]*/ double newVal);
	STDMETHOD(get_Dpr2)(/*[out, retval]*/ double  *pVal);
	STDMETHOD(put_Dpr2)(/*[in]*/ double newVal);
	STDMETHOD(get_SizeB2)(/*[out, retval]*/ double  *pVal);
	STDMETHOD(put_SizeB2)(/*[in]*/ double newVal);

	STDMETHOD(get_Length)(/*[out, retval]*/ double   *pVal);
	STDMETHOD(put_Length)(/*[in]*/ double  newVal);
	STDMETHOD(get__1D2D)(/*[out, retval]*/ int   *pVal);
	STDMETHOD(put__1D2D)(/*[in]*/ int  newVal);

	STDMETHOD(get_Rotation)(/*[out, retval]*/ double  *pVal);
	STDMETHOD(put_Rotation)(/*[in]*/ double  newVal);

	STDMETHOD(get_Wipeout)(/*[out, retval]*/ int  *pVal);
	STDMETHOD(put_Wipeout)(/*[in]*/ int  newVal);

	STDMETHOD(get_TransType)(/*[out, retval]*/ int  *pVal);
	STDMETHOD(put_TransType)(/*[in]*/ int  newVal);
	STDMETHOD(get_Elev)(/*[out, retval]*/ double  *pVal);
	STDMETHOD(put_Elev)(/*[in]*/ double  newVal);
// 	STDMETHOD(get_Tag1)(/*[out, retval]*/ BSTR *pVal);
// 	STDMETHOD(put_Tag1)(/*[in]*/ BSTR  newVal);
// 	STDMETHOD(get_Tag2)(/*[out, retval]*/ BSTR *pVal);
// 	STDMETHOD(put_Tag2)(/*[in]*/ BSTR  newVal);
} ;

OBJECT_ENTRY_AUTO(__uuidof(ComTrans), CComTrans)
