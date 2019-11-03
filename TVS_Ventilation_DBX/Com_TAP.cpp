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
//----- Com_TAP.cpp : Implementation of CCom_TAP
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "Com_TAP.h"

//----- CCom_TAP
//-----------------------------------------------------------------------------
STDMETHODIMP CCom_TAP::InterfaceSupportsErrorInfo (REFIID riid) {
	static const IID * arr [] ={
		&IID_ICom_TAP
	} ;

	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
//IAcadBaseObjectImpl
HRESULT CCom_TAP::CreateNewObject (AcDbObjectId &objId, AcDbObjectId &ownerId, TCHAR *keyName) {
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
STDMETHODIMP CCom_TAP::ForceDbResident (VARIANT_BOOL *forceDbResident) {
	if ( forceDbResident == NULL )
		return (E_POINTER) ;
	//----- Return ACAX_VARIANT_TRUE if the object must be database resident to be functional
	*forceDbResident =ACAX_VARIANT_FALSE ;
	return (S_OK) ;
}

STDMETHODIMP CCom_TAP::CreateObject (AcDbObjectId ownerId /*=AcDbObjectId::kNull*/, TCHAR *keyName /*=NULL*/) {
	try {
		Acad::ErrorStatus es ;
		AcDbObjectPointer<TVS_TAP> obj ;
		if ( (es =obj.create ()) != Acad::eOk )
			throw es ;

		obj->setDatabaseDefaults (ownerId.database ()) ;

		TVS_TAP *pTmp =NULL ;
		obj.release (pTmp) ;

		SetObject ((AcDbObject *&)pTmp) ;
	} catch ( const Acad::ErrorStatus ) {
		return (Error (L"Failed to create TVS_TAP", IID_ICom_TAP, E_FAIL)) ;
	}
	return (S_OK) ;
}

STDMETHODIMP CCom_TAP::AddToDb (AcDbObjectId &objId, AcDbObjectId ownerId /*=AcDbObjectId::kNull*/, TCHAR *keyName /*=NULL*/) {
	try {
		AcAxDocLock docLock (ownerId) ;

		Acad::ErrorStatus es ;
		AcAxObjectRefPtr<TVS_TAP> obj (&m_objRef, AcDb::kForRead) ;

		//----- Entities can be owned by block table records only
		AcDbBlockTableRecordPointer pBlockTableRecord (ownerId, AcDb::kForWrite, true) ;
		if ( (es =pBlockTableRecord.openStatus ()) != Acad::eOk )
			throw es ;

		if ( (es =pBlockTableRecord->appendAcDbEntity (objId, obj.object ())) != Acad::eOk )
			throw es ;
	} catch( const Acad::ErrorStatus ) {
		return (Error(L"Failed to add TVS_TAP to database", IID_ICom_TAP, E_FAIL)) ;
	}
	return (SetObjectId (objId)) ;
}

//IOPMPropertyExpander
STDMETHODIMP CCom_TAP::GetElementValue (DISPID dispID, DWORD dwCookie, VARIANT *pVarOut) {
	if ( pVarOut == NULL )
		return (E_POINTER) ;
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}

STDMETHODIMP CCom_TAP::SetElementValue (DISPID dispID, DWORD dwCookie, VARIANT VarIn) {
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}

STDMETHODIMP CCom_TAP::GetElementStrings (DISPID dispID, OPMLPOLESTR __RPC_FAR *pCaStringsOut, OPMDWORD __RPC_FAR *pCaCookiesOut) {
	if ( pCaStringsOut == NULL || pCaCookiesOut == NULL )
		return (E_POINTER) ;
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}

STDMETHODIMP CCom_TAP::GetElementGrouping (DISPID dispID, short *groupingNumber) {
	if ( groupingNumber == NULL )
		return (E_POINTER) ;
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}

STDMETHODIMP CCom_TAP::GetGroupCount (DISPID dispID, long *nGroupCnt) {
	if ( nGroupCnt == NULL )
		return (E_POINTER) ;
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}

STDMETHODIMP CCom_TAP::GetDisplayName (DISPID dispId, BSTR *propName) 
{ 
	if (tryToSetCommonDisplayName(dispId,propName)){
		return S_OK; 
	}
	switch (dispId) 
	{ 
		// стандартное 
	case (0x401): 
		*propName  = ::SysAllocString(_T("Отвод")); 
		break; 

	case (DISPID_A): 
		*propName  = ::SysAllocString(L"Dпр"); 
		break; 

	case (DISPID_SizeB): 
		*propName  = ::SysAllocString(L"Hпр"); 
		break; 
	case (DISPID_Flow): 
		*propName  = ::SysAllocString(L"L="); 
		break; 
	case (DISPID_Speed): 
		*propName  = ::SysAllocString(L"v="); 
		break; 


		//case (DISPID_Length): 
		//	*propName  = ::SysAllocString(L"Длина"); 
		//	break; 
	case (DISPID_1D2D): 
		*propName  = ::SysAllocString(L"1D"); 
		break; 
	case (DISPID_Rotation): 
		*propName  = ::SysAllocString(L"Угол"); 
		break; 
	case (DISPID_Angle): 
		*propName  = ::SysAllocString(L"Угол отвода"); 
		break; 
	case (DISPID_Wipeout): 
		*propName  = ::SysAllocString(L"Маскировка"); 
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


STDMETHODIMP CCom_TAP::get_Dpr(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          


	*pVal = pSq->get_SizeA();

	return S_OK;
}

STDMETHODIMP CCom_TAP::put_Dpr(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	pSq->TVS_TAP::put_SizeA(newVal);
	Fire_Notification(DISPID_A);

	return S_OK;
}

STDMETHODIMP CCom_TAP::get_SizeB(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	double size;
	size = pSq->get_SizeB();
	*pVal = size;

	return S_OK;
}

STDMETHODIMP CCom_TAP::put_SizeB(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   

	pSq->TVS_TAP::put_SizeB(newVal);
	Fire_Notification(DISPID_SizeB);

	return S_OK;
}
STDMETHODIMP CCom_TAP::get_Speed(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	double speed,pflow;
	pflow=pSq->Flow;
	if (*pVal>0)
	{
		if (pSq->get_ThisRound()==true)
		{
			speed=pflow/(3600*3.14*(pSq->SizeA/1000)*(pSq->SizeA/1000)/4);

		}
		else
		{
			speed=pflow/(3600*(pSq->SizeA/1000)*(pSq->SizeB/1000));
		}
	}
	else speed=0;
	*pVal =speed;

	return S_OK;
}

STDMETHODIMP CCom_TAP::put_Speed(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	double speed,pflow;
	speed=newVal;


	if ((pSq->get_ThisRound())==true)
	{
		pflow=speed*(3600*3.14*((pSq->SizeA)/1000)*((pSq->SizeA)/1000)/4);

	}
	else
	{
		pflow=speed*(3600*(pSq->SizeA/1000)*(pSq->SizeB/1000));

	}


	pSq->put_Flow(pflow);



	Fire_Notification(DISPID_Speed);

	return S_OK;
}
STDMETHODIMP CCom_TAP::get_Flow(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	*pVal = pSq->Flow;

	return S_OK;
}

STDMETHODIMP CCom_TAP::put_Flow(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          






	pSq->put_Flow(newVal);



	Fire_Notification(DISPID_Flow);

	return S_OK;
}
STDMETHODIMP CCom_TAP::get__1D2D(int  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          


	if ((pSq->This1D)==false) *pVal=0 ;
	else *pVal=1 ;




	return S_OK;
}

STDMETHODIMP CCom_TAP::put__1D2D(int  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	if (newVal==0) pSq->put_This1D(false);
	else pSq->put_This1D(true);


	Fire_Notification(DISPID_1D2D);

	return S_OK;
}

STDMETHODIMP CCom_TAP::get_Rotation(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	double  Lx, Ly;

	Lx=pSq->Startvector.x;
	Ly=pSq->Startvector.y;


	double startangle=acos((1*Lx+0)/sqrt(Lx*Lx+Ly*Ly));
	if (Ly<0)
	{
		startangle=2*M_PI-startangle;
	}


	*pVal = startangle*180/M_PI;

	return S_OK;
}

STDMETHODIMP CCom_TAP::put_Rotation(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	pSq->put_Startvector(AcGeVector3d(cos(newVal/180*M_PI),sin(newVal/180*M_PI),pSq->Startvector.z));



	Fire_Notification(DISPID_Rotation);

	return S_OK;
}

STDMETHODIMP CCom_TAP::get_Angle(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	double angler;
	angler=pSq->Swectangle*180/M_PI;
	*pVal = angler;

	return S_OK;
}

STDMETHODIMP CCom_TAP::put_Angle(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          







	pSq->put_Swectangle(newVal*M_PI/180);



	Fire_Notification(DISPID_Angle);

	return S_OK;
}



STDMETHODIMP CCom_TAP::get_Wipeout(int  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          


	if ((pSq->Wipeout)==false) *pVal=0 ;
	else *pVal=1 ;




	return S_OK;
}

STDMETHODIMP CCom_TAP::put_Wipeout(int  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	if (newVal==0) pSq->put_Wipeout(false);
	else pSq->put_Wipeout(true);


	Fire_Notification(DISPID_Wipeout);

	return S_OK;
}

STDMETHODIMP CCom_TAP::get_Elev(double  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	*pVal=pSq->Elev;




	return S_OK;
}

STDMETHODIMP CCom_TAP::put_Elev(double  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	pSq->put_Elevation(newVal);


	Fire_Notification(DISPID_Elev);

	return S_OK;
}

// STDMETHODIMP CCom_TAP::get_Tag1(BSTR  *pVal)
// {
// 	// TODO: Add your implementation code here
// 	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForRead);
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
// STDMETHODIMP CCom_TAP::put_Tag1(BSTR  newVal)
// {
// 	// TODO: Add your implementation code here
// 	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
// 	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
// 		return E_ACCESSDENIED;
// 	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForWrite);
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
// STDMETHODIMP CCom_TAP::get_Tag2(BSTR  *pVal)
// {
// 	// TODO: Add your implementation code here
// 	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForRead);
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
// STDMETHODIMP CCom_TAP::put_Tag2(BSTR  newVal)
// {
// 	// TODO: Add your implementation code here
// 	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
// 	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
// 		return E_ACCESSDENIED;
// 	AcAxObjectRefPtr<TVS_TAP> pSq(&m_objRef, AcDb::kForWrite);
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


