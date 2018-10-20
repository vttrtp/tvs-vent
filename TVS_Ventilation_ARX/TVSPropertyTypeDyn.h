#pragma once
#include "resource.h"
#include "TVSPropertDynBase.h"
#include "TVS_Ventilation_ARX_i.h"



//----- CTVSPropertyTypeDyn
class ATL_NO_VTABLE CTVSPropertyTypeDyn :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTVSPropertyTypeDyn, &CLSID_TVSPropertyTypeDyn>,
	public ISupportErrorInfo,
	public IDispatchImpl<ITVSPropertyTypeDyn, &IID_ITVSPropertyTypeDyn, &LIBID_TVSTVS_Ventilation_ARXLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ICategorizeProperties,
	public IDynamicProperty2,
	public TVSPropertyDynBase
{
public:
	CTVSPropertyTypeDyn() {
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_TVSPROPERTYTypeDYN)

	BEGIN_COM_MAP(CTVSPropertyTypeDyn)
		COM_INTERFACE_ENTRY(ITVSPropertyTypeDyn)
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
	//ITVSPropertyTypeDyn

};

OBJECT_ENTRY_AUTO(__uuidof(TVSPropertyTypeDyn), CTVSPropertyTypeDyn)
OPM_DYNPROP_OBJECT_ENTRY_AUTO(CTVSPropertyTypeDyn, AcDbObject)
