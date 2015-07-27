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
//----- TVS_ComEntity.h : Declaration of the CTVS_ComEntity
//-----------------------------------------------------------------------------
#pragma once
#include "resource.h"
#include "..//TVS_Ventilation_DBX/TVS_Entity.h"
#include "..//TVS_Ventilation_DBX/TVS_Ventilation_DBX_i.h"
#define DISPID_A  0x01


//----- CTVS_ComEntity
class ATL_NO_VTABLE CTVS_ComEntity : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTVS_ComEntity, &CLSID_TVS_ComEntity>,
	public ISupportErrorInfo,
	public IAcadEntityDispatchImpl<CTVS_ComEntity, &CLSID_TVS_ComEntity, ITVS_ComEntity, &IID_ITVS_ComEntity, &LIBID_TVSTVS_Ventilation_DBXLib>
	//- Please do not remove the following line. It is here to make the Visual Studio ATL Wizards
	//- running properly. The class will not compile but is required by Visual Studio to recognize
	//-	this class as being an ATL class
	//- Uncomment the following line when you want to use the ATL Wizards to add a member or method
	//- to its interface.
	//,public IDispatchImpl<Ighfghgfh, &IID_IIghfghgfh, &LIBID_adskArxProject1Lib>
{
public:
	CTVS_ComEntity () {
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_TVS_COMENTITY)

	BEGIN_COM_MAP(CTVS_ComEntity)
		COM_INTERFACE_ENTRY(ITVS_ComEntity)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
		COM_INTERFACE_ENTRY(IAcadBaseObject)
		COM_INTERFACE_ENTRY(IAcadBaseObject2)
		COM_INTERFACE_ENTRY(IAcadObject)
		COM_INTERFACE_ENTRY(IAcadEntity)
		COM_INTERFACE_ENTRY(IRetrieveApplication)
	END_COM_MAP()

	//----- ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct () {
		return (S_OK) ;
	}
	
	void FinalRelease () {
	}

	//IAcadBaseObjectImpl
	virtual HRESULT CreateNewObject (AcDbObjectId &objId, AcDbObjectId &ownerId, TCHAR *keyName);
	//IAcadBaseObject2Impl
	STDMETHOD(ForceDbResident)(VARIANT_BOOL *forceDbResident) ;
	STDMETHOD(CreateObject)(AcDbObjectId ownerId =AcDbObjectId::kNull, TCHAR *keyName =NULL);
	STDMETHOD(AddToDb)(AcDbObjectId &objId, AcDbObjectId ownerId =AcDbObjectId::kNull, TCHAR *keyName =NULL);

public:
	//ITVS_ComEntity

} ;

OBJECT_ENTRY_AUTO(__uuidof(TVS_ComEntity), CTVS_ComEntity)
