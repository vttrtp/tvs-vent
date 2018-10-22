#include "StdAfx.h"
#include "TVSPropertyArticleDyn.h"
#include "TVSController.h"


//----- CTVSPropertyArticleDyn
STDMETHODIMP CTVSPropertyArticleDyn::InterfaceSupportsErrorInfo(REFIID riid) {
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
STDMETHODIMP CTVSPropertyArticleDyn::GetGUID (GUID *pPropGUID) {
	if ( pPropGUID == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	memcpy (pPropGUID, &CLSID_TVSPropertyArticleDyn, sizeof(GUID)) ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyArticleDyn::GetDisplayName (BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pBstrName =::SysAllocString (CTVSProperty_article) ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyArticleDyn::IsPropertyEnabled (IUnknown *pUnk, BOOL *pbEnabled) {
	if ( pUnk == NULL )
		return (E_INVALIDARG) ;
	if ( pbEnabled == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pbEnabled = checkEnabled();

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyArticleDyn::IsPropertyReadOnly (BOOL *pbReadOnly) {
	if ( pbReadOnly == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pbReadOnly =FALSE ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyArticleDyn::GetDescription (BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pBstrName =::SysAllocString (L"Description for My Property (CTVSPropertyZArticleDyn)") ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyArticleDyn::GetCurrentValueName (BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here

	//return (S_OK) ; //----- If you do anything in there
	return (E_NOTIMPL) ;
}

STDMETHODIMP CTVSPropertyArticleDyn::GetCurrentValueType (VARTYPE *pVarType) {
	if ( pVarType == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pVarType = VT_BSTR; 

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyArticleDyn::GetCurrentValueData (IUnknown *pUnk, VARIANT *pVarData) {
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
	if (TVSController::get()->tvsPropertyController.getArticle(objId, retValue)){
		V_BSTR(pVarData) = retValue.AllocSysString();
	}

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyArticleDyn::SetCurrentValueData (IUnknown *pUnk, const VARIANT varData) {
	if ( pUnk == NULL )
		return (E_INVALIDARG) ;
	
	AcDbObjectId objId;
	{
		CComQIPtr<IAcadBaseObject> pObj(pUnk);
		pObj->GetObjectId(&objId);
	}
	AcAxDocLock docLoc(acdbCurDwg());
	TVSController::get()->tvsPropertyController.setArticle(objId,CString(V_BSTR(&varData)));

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyArticleDyn::Connect (IDynamicPropertyNotify2 *pSink) {
	if ( pSink == NULL )
		return (E_POINTER) ;
	m_pNotify =pSink ;
	m_pNotify->AddRef () ;
	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyArticleDyn::Disconnect () {
	if ( m_pNotify ) {
		m_pNotify->Release () ;
		m_pNotify= NULL ;
	}
	return (S_OK) ;
}



//----- ICategorizePropertes
STDMETHODIMP CTVSPropertyArticleDyn::MapPropertyToCategory (DISPID dispid, PROPCAT *pPropCat) {
	if ( pPropCat == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pPropCat =0 ;

	return (S_OK) ;
}

STDMETHODIMP CTVSPropertyArticleDyn::GetCategoryName (PROPCAT propcat, LCID lcid, BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the 3 lines below)
	if ( propcat != 0 )
		return (E_INVALIDARG) ;
	*pBstrName =::SysAllocString (CTVSPropertyCategoryName) ;

	return (S_OK) ;
}
