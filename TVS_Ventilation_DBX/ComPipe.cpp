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
//----- ComPipe.cpp : Implementation of CComPipe
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "ComPipe.h"

//----- CComPipe
//-----------------------------------------------------------------------------
STDMETHODIMP CComPipe::InterfaceSupportsErrorInfo (REFIID riid) {
	static const IID * arr [] ={
		&IID_IComPipe
	} ;

	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
//IAcadBaseObjectImpl
HRESULT CComPipe::CreateNewObject (AcDbObjectId &objId, AcDbObjectId &ownerId, TCHAR *keyName) {
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
STDMETHODIMP CComPipe::ForceDbResident (VARIANT_BOOL *forceDbResident) {
	if ( forceDbResident == NULL )
		return (E_POINTER) ;
	//----- Return ACAX_VARIANT_TRUE if the object must be database resident to be functional
	*forceDbResident =ACAX_VARIANT_FALSE ;
	return (S_OK) ;
}

STDMETHODIMP CComPipe::CreateObject (AcDbObjectId ownerId /*=AcDbObjectId::kNull*/, TCHAR *keyName /*=NULL*/) {
	try {
		Acad::ErrorStatus es ;
		AcDbObjectPointer<TVS_Pipe> obj ;
		if ( (es =obj.create ()) != Acad::eOk )
			throw es ;

		obj->setDatabaseDefaults (ownerId.database ()) ;

		TVS_Pipe *pTmp =NULL ;
		obj.release (pTmp) ;

		SetObject ((AcDbObject *&)pTmp) ;
	} catch ( const Acad::ErrorStatus ) {
		return (Error (L"Failed to create TVS_Pipe", IID_IComPipe, E_FAIL)) ;
	}
	return (S_OK) ;
}

STDMETHODIMP CComPipe::AddToDb (AcDbObjectId &objId, AcDbObjectId ownerId /*=AcDbObjectId::kNull*/, TCHAR *keyName /*=NULL*/) {
	try {
		AcAxDocLock docLock (ownerId) ;

		Acad::ErrorStatus es ;
		AcAxObjectRefPtr<TVS_Pipe> obj (&m_objRef, AcDb::kForRead) ;

		//----- Entities can be owned by block table records only
		AcDbBlockTableRecordPointer pBlockTableRecord (ownerId, AcDb::kForWrite, true) ;
		if ( (es =pBlockTableRecord.openStatus ()) != Acad::eOk )
			throw es ;

		if ( (es =pBlockTableRecord->appendAcDbEntity (objId, obj.object ())) != Acad::eOk )
			throw es ;
	} catch( const Acad::ErrorStatus ) {
		return (Error(L"Failed to add TVS_Pipe to database", IID_IComPipe, E_FAIL)) ;
	}
	return (SetObjectId (objId)) ;
}




STDMETHODIMP CComPipe::GetCategoryName(PROPCAT propcat, LCID lcid, BSTR* pbstrName)
{
	switch ( propcat )
	{
	case PROPCAT_Data:
		*pbstrName = ::SysAllocString(L"Face");
		break;

	default:
		return S_FALSE;
	}
	return S_OK;
}

STDMETHODIMP CComPipe::GetDisplayName (DISPID dispId, BSTR *propName) 
{ 
	if (tryToSetCommonDisplayName(dispId,propName)){
		return S_OK; 
	}
	
	switch (dispId) 
	{ 
		// стандартное 
	case (0x401): 
		*propName  = ::SysAllocString(_T("Воздуховод")); 
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




	case (DISPID_Length): 
		*propName  = ::SysAllocString(L"Длина"); 
		break; 
	case (DISPID_1D2D): 
		*propName  = ::SysAllocString(L"1D"); 
		break; 
	case (DISPID_Rotation): 
		*propName  = ::SysAllocString(L"Угол"); 
		break; 
	case (DISPID_i): 
		*propName  = ::SysAllocString(L"i, Па/м"); 
		break; 
	case (DISPID_dP): 
		*propName  = ::SysAllocString(L"dP, Па"); 
		break; 
	case (DISPID_Wipeout): 
		*propName  = ::SysAllocString(L"Маскировка"); 
		break; 

	case (DISPID_Grani): 
		*propName  = ::SysAllocString(L"Грани"); 
		break; 
	case (DISPID_Elev): 
		*propName  = ::SysAllocString(L"Отм. Центр"); 
		break; 
	case (DISPID_ElevUp): 
		*propName  = ::SysAllocString(L"Отм. Верх"); 
		break; 
	case (DISPID_ElevDown): 
		*propName  = ::SysAllocString(L"Отм. Низ"); 
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
//IOPMPropertyExpander
STDMETHODIMP CComPipe::GetElementValue (DISPID dispID, DWORD dwCookie, VARIANT *pVarOut) {
	if (pVarOut == NULL)
		return E_POINTER;

	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	return S_OK;
}

STDMETHODIMP CComPipe::SetElementValue (DISPID dispID, DWORD dwCookie, VARIANT VarIn) {
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          




	return S_OK;
}

STDMETHODIMP CComPipe::GetElementStrings (DISPID dispID, OPMLPOLESTR __RPC_FAR *pCaStringsOut, OPMDWORD __RPC_FAR *pCaCookiesOut) {




	return S_OK;
}

STDMETHODIMP CComPipe::GetElementGrouping (DISPID dispID, short *groupingNumber) {
	if ( groupingNumber == NULL )
		return (E_POINTER) ;
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}

STDMETHODIMP CComPipe::GetGroupCount (DISPID dispID, long *nGroupCnt) {
	if ( nGroupCnt == NULL )
		return (E_POINTER) ;
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}


STDMETHODIMP CComPipe::get_Dpr(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	double size;
	size = pSq->SizeA;
	*pVal = size;

	return S_OK;
}



STDMETHODIMP CComPipe::put_Dpr(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	pSq->put_SizeA(newVal);
	Fire_Notification(DISPID_A);

	return S_OK;
}
STDMETHODIMP CComPipe::get_SizeB(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	double size;
	size = pSq->SizeB;
	*pVal = size;

	return S_OK;
}

STDMETHODIMP CComPipe::put_SizeB(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          
	if (newVal==0)pSq->put_ThisRound(true);
	else pSq->put_ThisRound(false);

	pSq->put_SizeB(newVal);
	Fire_Notification(DISPID_SizeB);

	return S_OK;
}
STDMETHODIMP CComPipe::get_Speed(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	double speed,pflow;
	pflow=pSq->Flow;
	if (pVal>0)
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

STDMETHODIMP CComPipe::put_Speed(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
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
STDMETHODIMP CComPipe::get_Flow(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	*pVal = pSq->Flow;

	return S_OK;
}

STDMETHODIMP CComPipe::put_Flow(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          






	pSq->put_Flow(newVal);



	Fire_Notification(DISPID_Flow);

	return S_OK;
}
STDMETHODIMP CComPipe::get_Length(double  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	*pVal=pSq->Length ;




	return S_OK;
}

STDMETHODIMP CComPipe::put_Length(double  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   





	Fire_Notification(DISPID_Length);

	return S_OK;
}

STDMETHODIMP CComPipe::get__1D2D(int  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          


	if ((pSq->This1D)==false) *pVal=0 ;
	else *pVal=1 ;




	return S_OK;
}

STDMETHODIMP CComPipe::put__1D2D(int  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	if (newVal==0) pSq->put_This1D(false);
	else pSq->put_This1D(true);


	Fire_Notification(DISPID_1D2D);

	return S_OK;
}

STDMETHODIMP CComPipe::get_Rotation(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          





	double  Lx=pSq->LastPoint.x-pSq->FirstPoint.x;

	double  Ly=pSq->LastPoint.y-pSq->FirstPoint.y;


	double startangle=acos((1*Lx+0)/sqrt(Lx*Lx+Ly*Ly));
	if (Ly<0)
	{
		startangle=2*M_PI-startangle;
	}


	*pVal = startangle*180/M_PI;

	return S_OK;
}

STDMETHODIMP CComPipe::put_Rotation(double newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	pSq->put_Lastpoint(AcGePoint3d(pSq->FirstPoint.x+cos(newVal/180*M_PI)*pSq->Length,pSq->FirstPoint.y+sin(newVal/180*M_PI)*pSq->Length,pSq->FirstPoint.z));



	Fire_Notification(DISPID_Rotation);

	return S_OK;
}


STDMETHODIMP CComPipe::get_Parami(double *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          
	double v,S,L,dekv,Pd,Re,Lambda;

	if (pSq->ThisRound==true)
	{
		S=pSq->SizeA*pSq->SizeA*M_PI/4/1000/1000;
		L=pSq->Flow/3600;
		dekv=pSq->SizeA/1000;
	} 
	else
	{
		S=pSq->SizeA*pSq->SizeB/1000/1000;
		L=pSq->Flow/3600;
		dekv=2*pSq->SizeA*pSq->SizeB/(pSq->SizeA+pSq->SizeB)/1000;
	}
	v=L/S;
	Pd=1.2*v*v/2;
	Re=v*dekv/0.000014;
	Lambda=0.11*pow((0.1/dekv/1000+68/Re),0.25);
	*pVal=Pd*Lambda/dekv;

	return S_OK;
}

STDMETHODIMP CComPipe::put_Parami(double  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   





	Fire_Notification(DISPID_i);

	return S_OK;
}

STDMETHODIMP CComPipe::get_ParamdP(double  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          

	double v,S,L,dekv,Pd,Re,Lambda,i;

	if (pSq->ThisRound==true)
	{
		S=pSq->SizeA*pSq->SizeA*M_PI/4/1000/1000;
		L=pSq->Flow/3600;
		dekv=pSq->SizeA/1000;
	} 
	else
	{
		S=pSq->SizeA*pSq->SizeB/1000/1000;
		L=pSq->Flow/3600;
		dekv=2*pSq->SizeA*pSq->SizeB/(pSq->SizeA+pSq->SizeB)/1000;
	}
	v=L/S;
	Pd=1.2*v*v/2;
	Re=v*dekv/0.000014;
	Lambda=0.11*pow((0.1/dekv/1000+68/Re),0.25);
	i=Pd*Lambda/dekv;
	*pVal=i*pSq->Length/1000;
	return S_OK;
}

STDMETHODIMP CComPipe::put_ParamdP(double  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   





	Fire_Notification(DISPID_dP);

	return S_OK;
}


STDMETHODIMP CComPipe::get_Wipeout(int  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          


	if ((pSq->Wipeout)==false) *pVal=0 ;
	else *pVal=1 ;




	return S_OK;
}

STDMETHODIMP CComPipe::put_Wipeout(int  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	if (newVal==0) pSq->put_Wipeout(false);
	else pSq->put_Wipeout(true);


	Fire_Notification(DISPID_Wipeout);

	return S_OK;
}




STDMETHODIMP CComPipe::get_Grani(int  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          


	if ((pSq->Grani)==false) *pVal=0 ;
	else *pVal=1 ;




	return S_OK;
}

STDMETHODIMP CComPipe::put_Grani(int  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	if (newVal==0) pSq->put_Grani(false);
	else pSq->put_Grani(true);


	Fire_Notification(DISPID_Grani);

	return S_OK;
}



STDMETHODIMP CComPipe::get_Elev(double  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	*pVal=pSq->Elev;


	return S_OK;
}

STDMETHODIMP CComPipe::put_Elev(double  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	pSq->put_Elevation(newVal);


	Fire_Notification(DISPID_Elev);

	return S_OK;
}



STDMETHODIMP CComPipe::get_ElevUp(double  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	*pVal=pSq->ElevUp;




	return S_OK;
}

STDMETHODIMP CComPipe::put_ElevUp(double  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	pSq->put_ElevUp(newVal);


	Fire_Notification(DISPID_ElevUp);

	return S_OK;
}



STDMETHODIMP CComPipe::get_ElevDown(double  *pVal)
{
	// TODO: Add your implementation code here
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;          



	*pVal=pSq->ElevDown;




	return S_OK;
}

STDMETHODIMP CComPipe::put_ElevDown(double  newVal)
{
	// TODO: Add your implementation code here
	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
		return E_ACCESSDENIED;
	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
	if (pSq.openStatus() != Acad::eOk)
		return E_ACCESSDENIED;   


	pSq->put_ElevDown(newVal);


	Fire_Notification(DISPID_ElevDown);

	return S_OK;
}



// STDMETHODIMP CComPipe::get_Tag1(BSTR  *pVal)
// {
// 	// TODO: Add your implementation code here
// 	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
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
// STDMETHODIMP CComPipe::put_Tag1(BSTR  newVal)
// {
// 	// TODO: Add your implementation code here
// 	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
// 	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
// 		return E_ACCESSDENIED;
// 	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
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
// STDMETHODIMP CComPipe::get_Tag2(BSTR  *pVal)
// {
// 	// TODO: Add your implementation code here
// 	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForRead);
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
// STDMETHODIMP CComPipe::put_Tag2(BSTR  newVal)
// {
// 	// TODO: Add your implementation code here
// 	AcAxDocLock docLock(m_objRef.objectId(), AcAxDocLock::kNormal);
// 	if(docLock.lockStatus() != Acad::eOk && docLock.lockStatus() != Acad::eNoDatabase)
// 		return E_ACCESSDENIED;
// 	AcAxObjectRefPtr<TVS_Pipe> pSq(&m_objRef, AcDb::kForWrite);
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
