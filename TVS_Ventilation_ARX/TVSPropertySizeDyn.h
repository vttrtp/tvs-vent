#pragma once
#include "resource.h"
#include "TVSPropertDynBase.h"
#include "TVS_Ventilation_ARX_i.h"



//----- CTVSPropertySizeDyn
class ATL_NO_VTABLE CTVSPropertySizeDyn :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTVSPropertySizeDyn, &CLSID_TVSPropertySizeDyn>,
	public ISupportErrorInfo,
	public IDispatchImpl<ITVSPropertySizeDyn, &IID_ITVSPropertySizeDyn, &LIBID_TVSTVS_Ventilation_ARXLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ICategorizeProperties,
	public IDynamicProperty2,
	public TVSPropertyDynBase
{
public:
	CTVSPropertySizeDyn() {
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_TVSPROPERTYSizeDYN)

	BEGIN_COM_MAP(CTVSPropertySizeDyn)
		COM_INTERFACE_ENTRY(ITVSPropertySizeDyn)
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
	//ITVSPropertySizeDyn

};

OBJECT_ENTRY_AUTO(__uuidof(TVSPropertySizeDyn), CTVSPropertySizeDyn)
//OPM_DYNPROP_OBJECT_ENTRY_AUTO(CTVSPropertySizeDyn, AcDbObject)
