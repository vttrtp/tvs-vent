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
//----- TVS_ComEntity.cpp : Implementation of CTVS_ComEntity
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "TVS_ComEntity.h"

//----- CTVS_ComEntity
//-----------------------------------------------------------------------------
STDMETHODIMP CTVS_ComEntity::InterfaceSupportsErrorInfo (REFIID riid) {
	static const IID * arr [] ={
		&IID_ITVS_ComEntity
	} ;

	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
//IAcadBaseObjectImpl
HRESULT CTVS_ComEntity::CreateNewObject (AcDbObjectId &objId, AcDbObjectId &ownerId, TCHAR *keyName) {
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
STDMETHODIMP CTVS_ComEntity::ForceDbResident (VARIANT_BOOL *forceDbResident) {
	if ( forceDbResident == NULL )
		return (E_POINTER) ;
	//----- Return ACAX_VARIANT_TRUE if the object must be database resident to be functional
	*forceDbResident =ACAX_VARIANT_FALSE ;
	return (S_OK) ;
}

STDMETHODIMP CTVS_ComEntity::CreateObject (AcDbObjectId ownerId /*=AcDbObjectId::kNull*/, TCHAR *keyName /*=NULL*/) {
	try {
		Acad::ErrorStatus es ;
		AcDbObjectPointer<TVS_Entity> obj ;
		if ( (es =obj.create ()) != Acad::eOk )
			throw es ;

		obj->setDatabaseDefaults (ownerId.database ()) ;

		TVS_Entity *pTmp =NULL ;
		obj.release (pTmp) ;

		SetObject ((AcDbObject *&)pTmp) ;
	} catch ( const Acad::ErrorStatus ) {
		return (Error (L"Failed to create TVS_Entity", IID_ITVS_ComEntity, E_FAIL)) ;
	}
	return (S_OK) ;
}

STDMETHODIMP CTVS_ComEntity::AddToDb (AcDbObjectId &objId, AcDbObjectId ownerId /*=AcDbObjectId::kNull*/, TCHAR *keyName /*=NULL*/) {
	try {
		AcAxDocLock docLock (ownerId) ;

		Acad::ErrorStatus es ;
		AcAxObjectRefPtr<TVS_Entity> obj (&m_objRef, AcDb::kForRead) ;

		//----- Entities can be owned by block table records only
		AcDbBlockTableRecordPointer pBlockTableRecord (ownerId, AcDb::kForWrite, true) ;
		if ( (es =pBlockTableRecord.openStatus ()) != Acad::eOk )
			throw es ;

		if ( (es =pBlockTableRecord->appendAcDbEntity (objId, obj.object ())) != Acad::eOk )
			throw es ;
	} catch( const Acad::ErrorStatus ) {
		return (Error(L"Failed to add TVS_Entity to database", IID_ITVS_ComEntity, E_FAIL)) ;
	}
	return (SetObjectId (objId)) ;
}


