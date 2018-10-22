#include "StdAfx.h"
#include "TVSPropertyCountDyn.h"
#include "TVSController.h"


//----- CTVSPropertyCountDyn
STDMETHODIMP CTVSPropertyCountDyn::InterfaceSupportsErrorInfo(REFIID riid) {
	static const IID* arr [] ={
		&IID_ITVSPropertyCountDyn
	} ;

	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//----- IDynamicProperty
STDMETHODIMP CTVSPropertyCountDyn::GetGUID (GUID *pPropGUID) {
	if ( pPropGUID == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	memcpy (pPropGUID, &CLSID_TVSPropertyCountDyn, sizeof(GUID)) ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyCountDyn::GetDisplayName (BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pBstrName =::SysAllocString (CTVSProperty_count) ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyCountDyn::IsPropertyEnabled (IUnknown *pUnk, BOOL *pbEnabled) {
	if ( pUnk == NULL )
		return (E_INVALIDARG) ;
	if ( pbEnabled == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pbEnabled = checkEnabled();

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyCountDyn::IsPropertyReadOnly (BOOL *pbReadOnly) {
	if ( pbReadOnly == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pbReadOnly =FALSE ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyCountDyn::GetDescription (BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pBstrName =::SysAllocString (L"Description for My Property (CTVSPropertyCountDyn)") ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyCountDyn::GetCurrentValueName (BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here

	//return (S_OK) ; //----- If you do anything in there
	return (E_NOTIMPL) ;
}

STDMETHODIMP CTVSPropertyCountDyn::GetCurrentValueType (VARTYPE *pVarType) {
	if ( pVarType == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pVarType = VT_R8;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyCountDyn::GetCurrentValueData (IUnknown *pUnk, VARIANT *pVarData) {
	if ( pUnk == NULL )
		return (E_INVALIDARG) ;
	if ( pVarData == NULL )
		return (E_POINTER) ;
	


	AcDbObjectId objId;
	{
		CComQIPtr<IAcadBaseObject> pObj(pUnk);
		pObj->GetObjectId(&objId);
	}
	

	::VariantInit(pVarData);
	V_VT(pVarData) = VT_R8;

	double retValue;

	AcAxDocLock docLoc(acdbCurDwg());
	if (TVSController::get()->tvsPropertyController.getCount(objId, retValue)) {
		V_R8(pVarData) = retValue;
	}
	
	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyCountDyn::SetCurrentValueData (IUnknown *pUnk, const VARIANT varData) {
	if ( pUnk == NULL )
		return (E_INVALIDARG) ;
	
	AcDbObjectId objId;
	{
		CComQIPtr<IAcadBaseObject> pObj(pUnk);
		pObj->GetObjectId(&objId);
	}
	AcAxDocLock docLoc(acdbCurDwg());
	TVSController::get()->tvsPropertyController.setCount(objId, V_R8(&varData));

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyCountDyn::Connect (IDynamicPropertyNotify2 *pSink) {
	if ( pSink == NULL )
		return (E_POINTER) ;
	m_pNotify =pSink ;
	m_pNotify->AddRef () ;
	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyCountDyn::Disconnect () {
	if ( m_pNotify ) {
		m_pNotify->Release () ;
		m_pNotify= NULL ;
	}
	return (S_OK) ;
}



//----- ICategorizePropertes
STDMETHODIMP CTVSPropertyCountDyn::MapPropertyToCategory (DISPID dispid, PROPCAT *pPropCat) {
	if ( pPropCat == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pPropCat =0 ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyCountDyn::GetCategoryName (PROPCAT propcat, LCID lcid, BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the 3 lines below)
	if ( propcat != 0 )
		return (E_INVALIDARG) ;
	*pBstrName =::SysAllocString (CTVSPropertyCategoryName) ;

	return (S_OK) ;
}
