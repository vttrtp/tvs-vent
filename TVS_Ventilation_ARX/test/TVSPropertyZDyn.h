#pragma once
#include "resource.h"
#include "TVSPropertyDynBase.h"
#include "TVS_Ventilation_ARX_i.h"



//----- CTVSPropertyZDyn
class ATL_NO_VTABLE CTVSPropertyZDyn :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTVSPropertyZDyn, &CLSID_TVSPropertyZDyn>,
	public ISupportErrorInfo,
	public IDispatchImpl<ITVSPropertyZDyn, &IID_ITVSPropertyZDyn, &LIBID_TVSTVS_Ventilation_ARXLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ICategorizeProperties,
	public IDynamicProperty2,
	public TVSPropertyDynBase
{
public:
	CTVSPropertyZDyn() {
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_TVSPROPERTYPOSITIONDYN)

	BEGIN_COM_MAP(CTVSPropertyZDyn)
		COM_INTERFACE_ENTRY(ITVSPropertyZDyn)
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
	//ITVSPropertyZDyn

};

OBJECT_ENTRY_AUTO(__uuidof(TVSPropertyZDyn), CTVSPropertyZDyn)
OPM_DYNPROP_OBJECT_ENTRY_AUTO(CTVSPropertyZDyn, AcDbObject)
