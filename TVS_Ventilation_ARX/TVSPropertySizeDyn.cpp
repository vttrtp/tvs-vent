#include "StdAfx.h"
#include "TVSPropertySizeDyn.h"
#include "TVSController.h"


//----- CTVSPropertySizeDyn
STDMETHODIMP CTVSPropertySizeDyn::InterfaceSupportsErrorInfo(REFIID riid) {
	static const IID* arr[] = {
		&IID_ITVSPropertySizeDyn
	};

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (InlineIsEqualGUID(*arr[i], riid))
			return (S_OK);
	}
	return (S_FALSE);
}

//----- IDynamicProperty
STDMETHODIMP CTVSPropertySizeDyn::GetGUID(GUID *pPropGUID) {
	if (pPropGUID == NULL)
		return (E_POINTER);
	// TODO: add your code here (and comment the line below)
	memcpy(pPropGUID, &CLSID_TVSPropertySizeDyn, sizeof(GUID));

	return (S_OK);
}

STDMETHODIMP CTVSPropertySizeDyn::GetDisplayName(BSTR *pBstrName) {
	if (pBstrName == NULL)
		return (E_POINTER);
	// TODO: add your code here (and comment the line below)
	*pBstrName = ::SysAllocString(CTVSProperty_size);

	return (S_OK);
}

STDMETHODIMP CTVSPropertySizeDyn::IsPropertyEnabled(IUnknown *pUnk, BOOL *pbEnabled) {
	if (pUnk == NULL)
		return (E_INVALIDARG);
	if (pbEnabled == NULL)
		return (E_POINTER);
	// TODO: add your code here (and comment the line below)
	*pbEnabled = checkEnabled(pUnk);

	return (S_OK);
}

STDMETHODIMP CTVSPropertySizeDyn::IsPropertyReadOnly(BOOL *pbReadOnly) {
	if (pbReadOnly == NULL)
		return (E_POINTER);
	// TODO: add your code here (and comment the line below)
	*pbReadOnly = FALSE;

	return (S_OK);
}

STDMETHODIMP CTVSPropertySizeDyn::GetDescription(BSTR *pBstrName) {
	if (pBstrName == NULL)
		return (E_POINTER);
	// TODO: add your code here (and comment the line below)
	*pBstrName = ::SysAllocString(L"Description for My Property (CTVSPropertySizeDyn)");

	return (S_OK);
}

STDMETHODIMP CTVSPropertySizeDyn::GetCurrentValueName(BSTR *pBstrName) {
	if (pBstrName == NULL)
		return (E_POINTER);
	// TODO: add your code here

	//return (S_OK) ; //----- If you do anything in there
	return (E_NOTIMPL);
}

STDMETHODIMP CTVSPropertySizeDyn::GetCurrentValueType(VARTYPE *pVarType) {
	if (pVarType == NULL)
		return (E_POINTER);
	// TODO: add your code here (and comment the line below)
	*pVarType = VT_BSTR;

	return (S_OK);
}

STDMETHODIMP CTVSPropertySizeDyn::GetCurrentValueData(IUnknown *pUnk, VARIANT *pVarData) {
	if (pUnk == NULL)
		return (E_INVALIDARG);
	if (pVarData == NULL)
		return (E_POINTER);

	AcDbObjectId objId;
	{
		CComQIPtr<IAcadBaseObject> pObj(pUnk);
		pObj->GetObjectId(&objId);
	}

	::VariantInit(pVarData);
	V_VT(pVarData) = VT_BSTR;

	CString retValue;

	AcAxDocLock docLoc(acdbCurDwg());
	if (TVSController::get()->tvsPropertyController.getSize(objId, retValue)) {
		V_BSTR(pVarData) = retValue.AllocSysString();
	}

	return (S_OK);
}

STDMETHODIMP CTVSPropertySizeDyn::SetCurrentValueData(IUnknown *pUnk, const VARIANT varData) {
	if (pUnk == NULL)
		return (E_INVALIDARG);

	AcDbObjectId objId;
	{
		CComQIPtr<IAcadBaseObject> pObj(pUnk);
		pObj->GetObjectId(&objId);
	}
	AcAxDocLock docLoc(acdbCurDwg());
	TVSController::get()->tvsPropertyController.setSize(objId, CString(V_BSTR(&varData)));

	return (S_OK);
}

STDMETHODIMP CTVSPropertySizeDyn::Connect(IDynamicPropertyNotify2 *pSink) {
	if (pSink == NULL)
		return (E_POINTER);
	m_pNotify = pSink;
	m_pNotify->AddRef();
	return (S_OK);
}

STDMETHODIMP CTVSPropertySizeDyn::Disconnect() {
	if (m_pNotify) {
		m_pNotify->Release();
		m_pNotify = NULL;
	}
	return (S_OK);
}

//----- ICategorizePropertes
STDMETHODIMP CTVSPropertySizeDyn::MapPropertyToCategory(DISPID dispid, PROPCAT *pPropCat) {
	if (pPropCat == NULL)
		return (E_POINTER);
	// TODO: add your code here (and comment the line below)
	*pPropCat = 0;

	return (S_OK);
}

STDMETHODIMP CTVSPropertySizeDyn::GetCategoryName(PROPCAT propcat, LCID lcid, BSTR *pBstrName) {
	if (pBstrName == NULL)
		return (E_POINTER);
	// TODO: add your code here (and comment the 3 lines below)
	if (propcat != 0)
		return (E_INVALIDARG);
	*pBstrName = ::SysAllocString(CTVSPropertyCategoryName);

	return (S_OK);
}
