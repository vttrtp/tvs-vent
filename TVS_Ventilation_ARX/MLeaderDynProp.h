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
//----- MLeaderDynProp.h : Declaration of the CMLeaderDynProp
//-----------------------------------------------------------------------------
#pragma once
#include "Resource.h"

#include "TVS_Ventilation_ARX_i.h"



//----- CMLeaderDynProp
class ATL_NO_VTABLE CMLeaderDynProp :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMLeaderDynProp, &CLSID_MLeaderDynProp>,
	public ISupportErrorInfo,
	public IDispatchImpl<IMLeaderDynProp, &IID_IMLeaderDynProp, &LIBID_TVSTVS_Ventilation_ARXLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ICategorizeProperties,
	public IDynamicProperty2
{
public:
	CMLeaderDynProp() {
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_MLEADERDYNPROP)

	BEGIN_COM_MAP(CMLeaderDynProp)
		COM_INTERFACE_ENTRY(IMLeaderDynProp)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(ICategorizeProperties)
		COM_INTERFACE_ENTRY(IDynamicProperty2)
	END_COM_MAP()

	//----- ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct() {
		return (S_OK);
	}

	void FinalRelease() {
	}

	IDynamicPropertyNotify2 *m_pNotify;

public:

	//IDynamicProperty2
	STDMETHOD(GetGUID)(GUID* propGUID);
	STDMETHOD(GetDisplayName)(BSTR* bstrName);
	STDMETHOD(IsPropertyEnabled)(IUnknown *pUnk, BOOL* pbEnabled);
	STDMETHOD(IsPropertyReadOnly)(BOOL* pbReadonly);
	STDMETHOD(GetDescription)(BSTR* bstrName);
	STDMETHOD(GetCurrentValueName)(BSTR* pbstrName);
	STDMETHOD(GetCurrentValueType)(VARTYPE* pVarType);
	STDMETHOD(GetCurrentValueData)(IUnknown *pUnk, VARIANT* pvarData);
	STDMETHOD(SetCurrentValueData)(IUnknown *pUnk, const VARIANT varData);
	STDMETHOD(Connect)(IDynamicPropertyNotify2* pSink);
	STDMETHOD(Disconnect)();
	//ICategorizePropery
	STDMETHOD(MapPropertyToCategory)(DISPID dispid, PROPCAT* ppropcat);
	STDMETHOD(GetCategoryName)(PROPCAT propcat, LCID lcid, BSTR* pbstrName);
	//IMLeaderDynProp
	AcString sFormat;
	_variant_t l_sel;
};

OBJECT_ENTRY_AUTO(__uuidof(MLeaderDynProp), CMLeaderDynProp)
OPM_DYNPROP_OBJECT_ENTRY_AUTO(CMLeaderDynProp, AcDbMLeader)
