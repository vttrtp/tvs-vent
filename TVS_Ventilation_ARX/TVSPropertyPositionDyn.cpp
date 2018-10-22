#include "StdAfx.h"
#include "TVSPropertyPositionDyn.h"
#include "TVSController.h"


//----- CTVSPropertyPositionDyn
STDMETHODIMP CTVSPropertyPositionDyn::InterfaceSupportsErrorInfo(REFIID riid) {
	static const IID* arr [] ={
		&IID_ITVSPropertyPositionDyn
	} ;

	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//----- IDynamicProperty
STDMETHODIMP CTVSPropertyPositionDyn::GetGUID (GUID *pPropGUID) {
	if ( pPropGUID == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	memcpy (pPropGUID, &CLSID_TVSPropertyPositionDyn, sizeof(GUID)) ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyPositionDyn::GetDisplayName (BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pBstrName =::SysAllocString (CTVSProperty_position) ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyPositionDyn::IsPropertyEnabled (IUnknown *pUnk, BOOL *pbEnabled) {
	if ( pUnk == NULL )
		return (E_INVALIDARG) ;
	if ( pbEnabled == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pbEnabled = checkEnabled();

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyPositionDyn::IsPropertyReadOnly (BOOL *pbReadOnly) {
	if ( pbReadOnly == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pbReadOnly =FALSE ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyPositionDyn::GetDescription (BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pBstrName =::SysAllocString (L"Description for My Property (CTVSPropertyPositionDyn)") ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyPositionDyn::GetCurrentValueName (BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here

	//return (S_OK) ; //----- If you do anything in there
	return (E_NOTIMPL) ;
}

STDMETHODIMP CTVSPropertyPositionDyn::GetCurrentValueType (VARTYPE *pVarType) {
	if ( pVarType == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pVarType = VT_BSTR; 

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyPositionDyn::GetCurrentValueData (IUnknown *pUnk, VARIANT *pVarData) {
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
	V_VT(pVarData) = VT_BSTR;

	CString retValue;

	AcAxDocLock docLoc(acdbCurDwg());
	if (TVSController::get()->tvsPropertyController.getPosition(objId, retValue)) {
		V_BSTR(pVarData) = retValue.AllocSysString();
	}

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyPositionDyn::SetCurrentValueData (IUnknown *pUnk, const VARIANT varData) {
	if ( pUnk == NULL )
		return (E_INVALIDARG) ;
	
	AcDbObjectId objId;
	{
		CComQIPtr<IAcadBaseObject> pObj(pUnk);
		pObj->GetObjectId(&objId);
	}
	AcAxDocLock docLoc(acdbCurDwg());
	TVSController::get()->tvsPropertyController.setPosition(objId, CString(V_BSTR(&varData)));

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyPositionDyn::Connect (IDynamicPropertyNotify2 *pSink) {
	if ( pSink == NULL )
		return (E_POINTER) ;
	m_pNotify =pSink ;
	m_pNotify->AddRef () ;
	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyPositionDyn::Disconnect () {
	if ( m_pNotify ) {
		m_pNotify->Release () ;
		m_pNotify= NULL ;
	}
	return (S_OK) ;
}



//----- ICategorizePropertes
STDMETHODIMP CTVSPropertyPositionDyn::MapPropertyToCategory (DISPID dispid, PROPCAT *pPropCat) {
	if ( pPropCat == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pPropCat =0 ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyPositionDyn::GetCategoryName (PROPCAT propcat, LCID lcid, BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the 3 lines below)
	if ( propcat != 0 )
		return (E_INVALIDARG) ;
	*pBstrName =::SysAllocString (CTVSPropertyCategoryName) ;

	return (S_OK) ;
}
