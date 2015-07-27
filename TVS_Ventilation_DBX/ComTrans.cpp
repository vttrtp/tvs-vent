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
//----- ComTrans.cpp : Implementation of CComTrans
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "ComTrans.h"

//----- CComTrans
//-----------------------------------------------------------------------------
STDMETHODIMP CComTrans::InterfaceSupportsErrorInfo (REFIID riid) {
	static const IID * arr [] ={
		&IID_IComTrans
	} ;

	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
//IAcadBaseObjectImpl
HRESULT CComTrans::CreateNewObject (AcDbObjectId &objId, AcDbObjectId &ownerId, TCHAR *keyName) {
	try {
		HRESULT hr ;
		if ( FAILED(hr =CreateObject (ownerId, keyName)) )
			throw hr ;
		if ( FAILED(hr =AddToDb (objId, ownerId, keyName)) )
			throw hr ;
	} catch( HRESULT hr ) {
		return (hr) ;
	}
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
//IAcadBaseObject2Impl
STDMETHODIMP CComTrans::ForceDbResident (VARIANT_BOOL *forceDbResident) {
	if ( forceDbResident == NULL )
		return (E_POINTER) ;
	//----- Return ACAX_VARIANT_TRUE if the object must be database resident to be functional
	*forceDbResident =ACAX_VARIANT_FALSE ;
	return (S_OK) ;
}

STDMETHODIMP CComTrans::CreateObject (AcDbObjectId ownerId /*=AcDbObjectId::kNull*/, TCHAR *keyName /*=NULL*/) {
	try {
		Acad::ErrorStatus es ;
		AcDbObjectPointer<TVS_TRANS> obj ;
		if ( (es =obj.create ()) != Acad::eOk )
			throw es ;

		obj->setDatabaseDefaults (ownerId.database ()) ;

		TVS_TRANS *pTmp =NULL ;
		obj.release (pTmp) ;

		SetObject ((AcDbObject *&)pTmp) ;
	} catch ( const Acad::ErrorStatus ) {
		return (Error (L"Failed to create TVS_TRANS", IID_IComTrans, E_FAIL)) ;
	}
	return (S_OK) ;
}

STDMETHODIMP CComTrans::AddToDb (AcDbObjectId &objId, AcDbObjectId ownerId /*=AcDbObjectId::kNull*/, TCHAR *keyName /*=NULL*/) {
	try {
		AcAxDocLock docLock (ownerId) ;

		Acad::ErrorStatus es ;
		AcAxObjectRefPtr<TVS_TRANS> obj (&m_objRef, AcDb::kForRead) ;

		//----- Entities can be owned by block table records only
		AcDbBlockTableRecordPointer pBlockTableRecord (ownerId, AcDb::kForWrite, true) ;
		if ( (es =pBlockTableRecord.openStatus ()) != Acad::eOk )
			throw es ;

		if ( (es =pBlockTableRecord->appendAcDbEntity (objId, obj.object ())) != Acad::eOk )
			throw es ;
	} catch( const Acad::ErrorStatus ) {
		return (Error(L"Failed to add TVS_TRANS to database", IID_IComTrans, E_FAIL)) ;
	}
	return (SetObjectId (objId)) ;
}

//IOPMPropertyExpander
STDMETHODIMP CComTrans::GetElementValue (DISPID dispID, DWORD dwCookie, VARIANT *pVarOut) {
	if ( pVarOut == NULL )
		return (E_POINTER) ;
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}

STDMETHODIMP CComTrans::SetElementValue (DISPID dispID, DWORD dwCookie, VARIANT VarIn) {
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}

STDMETHODIMP CComTrans::GetElementStrings (DISPID dispID, OPMLPOLESTR __RPC_FAR *pCaStringsOut, OPMDWORD __RPC_FAR *pCaCookiesOut) {
	if ( pCaStringsOut == NULL || pCaCookiesOut == NULL )
		return (E_POINTER) ;
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}

STDMETHODIMP CComTrans::GetElementGrouping (DISPID dispID, short *groupingNumber) {
	if ( groupingNumber == NULL )
		return (E_POINTER) ;
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}

STDMETHODIMP CComTrans::GetGroupCount (DISPID dispID, long *nGroupCnt) {
	if ( nGroupCnt == NULL )
		return (E_POINTER) ;
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}

STDMETHODIMP CComTrans::GetDisplayName (DISPID dispId, BSTR *propName) 
{ 
	switch (dispId) 
	{ 
		// стандартное 
	case (0x401): 
		*propName  = ::SysAllocString(_T("Переход")); 
		break; 

	case (0x516): 
		*propName  = ::SysAllocString(_T("Цвет")); 
		break; 

	case (0x501): 
		*propName  = ::SysAllocString(_T("Слой")); 
		break; 

	case (0x502): 
		*propName  = ::SysAllocString(_T("Тип линий")); 
		break; 

	case (0x503): 
		*propName  = ::SysAllocString(_T("Масштаб типа линий")); 
		break; 

	case (0x513): 
		*propName  = ::SysAllocString(_T("Стиль печати")); 
		break; 

	case (0x514): 
		*propName  = ::SysAllocString(_T("Вес линий")); 
		break; 

	case (0x515): 
		*propName  = ::SysAllocString(_T("Гиперссылка")); 
		break; 

	case (0x577): 
		*propName  = ::SysAllocString(_T("Материал")); 
		break; 
		// моё 


	case (DISPID_A): 
		*propName  = ::SysAllocString(L"Dпр"); 
		break; 

	case (DISPID_SizeB): 
		*propName  = ::SysAllocString(L"Hпр"); 
		break; 
	case (DISPID_A2): 
		*propName  = ::SysAllocString(L"Dпр2"); 
		break; 

	case (DISPID_SizeB2): 
		*propName  = ::SysAllocString(L"Hпр2"); 
		break; 

		//case (DISPID_Flow): 
		//	*propName  = ::SysAllocString(L"L="); 
		//	break; 
		//case (DISPID_Speed): 
		//	*propName  = ::SysAllocString(L"v="); 
		//	break; 




	case (DISPID_Length): 
		*propName  = ::SysAllocString(L"Длина"); 
		break; 
	case (DISPID_1D2D): 
		*propName  = ::SysAllocString(L"1D"); 
		break; 
	case (DISPID_Rotation): 
		*propName  = ::SysAllocString(L"Угол"); 
		break; 

	case (DISPID_Wipeout): 
		*propName  = ::SysAllocString(L"Маскировка"); 
		break; 
	case (DISPID_TransType): 
		*propName  = ::SysAllocString(L"Тип"); 
		break; 
	case (DISPID_Elev): 
		*propName  = ::SysAllocString(L"Отм. Центр"); 
		break; 
	case (DISPID_Tag1): 
		*propName  = ::SysAllocString(L"Тэг 1"); 
		break;
	case (DISPID_Tag2): 
		*propName  = ::SysAllocString(L"Тэг 2"); 
		break;
	} 
	return S_OK; 
}    

STDMETHODIMP CComTrans::get_Dpr(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	double size;
	size = pSq->SizeAp1;
	*pVal = size;

	return S_OK;
}

STDMETHODIMP CComTrans::put_Dpr(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	pSq->put_SizeAp1(newVal);
	Fire_Notification(DISPID_A);

	return S_OK;
}

STDMETHODIMP CComTrans::get_SizeB(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	double size;
	size = pSq->SizeBp1;
	*pVal = size;

	return S_OK;
}

STDMETHODIMP CComTrans::put_SizeB(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          


	pSq->put_SizeBp1(newVal);
	Fire_Notification(DISPID_SizeB);

	return S_OK;
}



STDMETHODIMP CComTrans::get_Dpr2(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	double size;
	size = pSq->SizeAp2;
	*pVal = size;

	return S_OK;
}

STDMETHODIMP CComTrans::put_Dpr2(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	pSq->put_SizeAp2(newVal);
	Fire_Notification(DISPID_A2);

	return S_OK;
}

STDMETHODIMP CComTrans::get_SizeB2(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	double size;
	size = pSq->SizeBp2;
	*pVal = size;

	return S_OK;
}

STDMETHODIMP CComTrans::put_SizeB2(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          


	pSq->put_SizeBp2(newVal);
	Fire_Notification(DISPID_SizeB2);

	return S_OK;
}



STDMETHODIMP CComTrans::get_Length(double  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	*pVal=pSq->LengthTr ;




	return S_OK;
}

STDMETHODIMP CComTrans::put_Length(double  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	pSq->put_Length(newVal);


	Fire_Notification(DISPID_Length);

	return S_OK;
}

STDMETHODIMP CComTrans::get__1D2D(int  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          


	if ((pSq->This1D)==false) *pVal=0 ;
	else *pVal=1 ;




	return S_OK;
}

STDMETHODIMP CComTrans::put__1D2D(int  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	if (newVal==0) pSq->put_This1D(false);
	else pSq->put_This1D(true);


	Fire_Notification(DISPID_1D2D);

	return S_OK;
}

STDMETHODIMP CComTrans::get_Rotation(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          





	double  Lx=pSq->VectTr.x;

	double  Ly=pSq->VectTr.y;


	double startangle=acos((1*Lx+0)/sqrt(Lx*Lx+Ly*Ly));
	if (Ly<0)
	{
		startangle=2*M_PI-startangle;
	}


	*pVal = startangle*180/M_PI;

	return S_OK;
}

STDMETHODIMP CComTrans::put_Rotation(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	pSq->put_VectTr(AcGeVector3d(cos(newVal/180*M_PI)*pSq->LengthTr,sin(newVal/180*M_PI)*pSq->LengthTr,pSq->FirstPoint.z));



	Fire_Notification(DISPID_Rotation);

	return S_OK;
}

STDMETHODIMP CComTrans::get_Wipeout(int  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          


	if ((pSq->Wipeout)==false) *pVal=0 ;
	else *pVal=1 ;




	return S_OK;
}

STDMETHODIMP CComTrans::put_Wipeout(int  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	if (newVal==0) pSq->put_Wipeout(false);
	else pSq->put_Wipeout(true);


	Fire_Notification(DISPID_Wipeout);

	return S_OK;
}

STDMETHODIMP CComTrans::get_TransType(int  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          


	if ((pSq->TransType)==2) *pVal=2 ;
	else{
		if ((pSq->TransType)==3) *pVal=3 ;
		else *pVal=1 ;
	}




	return S_OK;
}

STDMETHODIMP CComTrans::put_TransType(int  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	if (newVal==2) pSq->put_Type(2);
	else{
		if ((newVal)==3) pSq->put_Type(3);
		else pSq->put_Type(1);
	}


	Fire_Notification(DISPID_TransType);

	return S_OK;



}

STDMETHODIMP CComTrans::get_Elev(double  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	*pVal=pSq->Elev;




	return S_OK;
}

STDMETHODIMP CComTrans::put_Elev(double  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	pSq->put_Elevation(newVal);


	Fire_Notification(DISPID_Elev);

	return S_OK;
}

// STDMETHODIMP CComTrans::get_Tag1(BSTR  *pVal)
// {
// 	// TODO: Add your implementation code here
// 	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForRead);
// 	if (pSq.openStatus() != Acad::eOk)
// 		return E_ACCESSDENIED;          
// 
// 
// 	USES_CONVERSION;
// 	*pVal=SysAllocString(CT2W(pSq->Tag1));
// 
// 
// 
// 
// 	return S_OK;
// }
// 
// STDMETHODIMP CComTrans::put_Tag1(BSTR  newVal)
// {
// 	// TODO: Add your implementation code here
// 	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
// 	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
// 		return E_ACCESSDENIED;
// 	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForWrite);
// 	if (pSq.openStatus() != Acad::eOk)
// 		return E_ACCESSDENIED;   
// 
// 	USES_CONVERSION;
// 	pSq->put_Tag1(W2T(newVal));
// 
// 
// 	Fire_Notification(DISPID_Tag1);
// 
// 	return S_OK;
// }
// 
// 
// STDMETHODIMP CComTrans::get_Tag2(BSTR  *pVal)
// {
// 	// TODO: Add your implementation code here
// 	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForRead);
// 	if (pSq.openStatus() != Acad::eOk)
// 		return E_ACCESSDENIED;          
// 
// 
// 	USES_CONVERSION;
// 	*pVal=SysAllocString(CT2W(pSq->Tag2));
// 
// 
// 
// 
// 	return S_OK;
// }
// 
// STDMETHODIMP CComTrans::put_Tag2(BSTR  newVal)
// {
// 	// TODO: Add your implementation code here
// 	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
// 	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
// 		return E_ACCESSDENIED;
// 	AcAxObjectRefPtr<TVS_TRANS> pSq(&m_objRef, AcDb::kForWrite);
// 	if (pSq.openStatus() != Acad::eOk)
// 		return E_ACCESSDENIED;   
// 
// 	USES_CONVERSION;
// 	pSq->put_Tag2(W2T(newVal));
// 
// 
// 	Fire_Notification(DISPID_Tag2);
// 
// 	return S_OK;
// }