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
//----- MLeaderDynProp.cpp : Implementation of CMLeaderDynProp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "MLeaderDynProp.h"
#include "MLeaderSettings.h"

UINT GetEntitiesCount(VARIANT *l_selection) 
{
  UINT l_dim = ::SafeArrayGetDim(V_ARRAY(l_selection));
  if (l_dim != 1) return 0;
  LONG l_lbound = 0, l_ubound = 0;
  ::SafeArrayGetLBound(V_ARRAY(l_selection), 1, &l_lbound);  
  ::SafeArrayGetUBound(V_ARRAY(l_selection), 1, &l_ubound);
  return (l_ubound - l_lbound + 1);
}

AcString GetFormatString(VARIANT *l_selection)
{
  HRESULT l_hr;
  AcString res;
  try
  {
    UINT l_dim = ::SafeArrayGetDim(V_ARRAY(l_selection));
    if (l_dim == 1)
    {
      LONG l_lbound = 0, l_ubound = 0;
      ::SafeArrayGetLBound(V_ARRAY(l_selection), 1, &l_lbound);  ::SafeArrayGetUBound(V_ARRAY(l_selection), 1, &l_ubound);
      IUnknown *l_unkn = 0;
      for (LONG l_idx = l_lbound; l_idx <= l_ubound; l_idx++)
      {
        l_hr = ::SafeArrayGetElement(V_ARRAY(l_selection), &l_idx, &l_unkn);

        if (SUCCEEDED(l_hr))
        {
          if (l_unkn != NULL)
          {
            IAcadObject *l_base = 0;
            if (!SUCCEEDED(l_unkn->QueryInterface(IID_IAcadObject, (void **)&l_base)))
            {
              continue;
            }
            AcDbObjectId  l_oid;
            LONG_PTR l_long = 0;
            if (SUCCEEDED(l_base->get_ObjectID(&l_long)))
            {
              l_oid.setFromOldId(l_long);
            }
            l_base->Release(); // <------ Release before calculation !!!
            if (l_oid.isValid())
            {
              AcDbObjectPointer<AcDbMLeader> pMleader(l_oid, AcDb::kForRead);
              if (pMleader.openStatus() == Acad::eOk)
              {
                resbuf *rb = pMleader->xData(MLeaderFormat);
                for (resbuf *rbnext = rb; rbnext != NULL; rbnext = rbnext->rbnext)
                {
                  if (rbnext->restype == 1000)
                  {
                    if (res.isEmpty())  {
                      res = rbnext->resval.rstring;
					 
                    }
                    else if (res.compare(rbnext->resval.rstring))
                    {
                      res = _T("*** Разные ***");
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  catch (...)
  {
  }
  return res;

}

void PutFormatString(VARIANT *l_selection, AcString res)
{
  AcAxDocLock docLoc(acdbCurDwg());
  // Нужно бы проверить, но мы просто регистрируем
  //acdbRegApp(_T("MyMLeaderXdata"));
  HRESULT l_hr;
  try
  {
    UINT l_dim = ::SafeArrayGetDim(V_ARRAY(l_selection));
    if (l_dim == 1)
    {
      LONG l_lbound = 0, l_ubound = 0;
      ::SafeArrayGetLBound(V_ARRAY(l_selection), 1, &l_lbound);  ::SafeArrayGetUBound(V_ARRAY(l_selection), 1, &l_ubound);
      IUnknown *l_unkn = 0;
      for (LONG l_idx = l_lbound; l_idx <= l_ubound; l_idx++)
      {
        l_hr = ::SafeArrayGetElement(V_ARRAY(l_selection), &l_idx, &l_unkn);

        if (SUCCEEDED(l_hr))
        {
          if (l_unkn != NULL)
          {
            IAcadObject *l_base = 0;
            if (!SUCCEEDED(l_unkn->QueryInterface(IID_IAcadObject, (void **)&l_base)))
            {
              continue;
            }
            AcDbObjectId  l_oid;
            LONG_PTR l_long = 0;
            if (SUCCEEDED(l_base->get_ObjectID(&l_long)))
            {
              l_oid.setFromOldId(l_long);
            }
            l_base->Release(); // <------ Release before calculation !!!
            if (l_oid.isValid())
            {
              AcDbObjectPointer<AcDbMLeader> pMleader(l_oid, AcDb::kForWrite);
              if (pMleader.openStatus() == Acad::eOk)
              {
                resbuf *rb = acutBuildList(1001, MLeaderFormat, 1000, res.kTCharPtr(), 0);
                pMleader->setXData(rb); acutRelRb(rb);
              }
            }
          }
        }
      }
    }
  }
  catch (...)
  {
  }
}


//----- CMLeaderDynProp
STDMETHODIMP CMLeaderDynProp::InterfaceSupportsErrorInfo(REFIID riid) {
	static const IID* arr [] ={
		&IID_IMLeaderDynProp
	} ;

	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//----- IDynamicProperty
STDMETHODIMP CMLeaderDynProp::GetGUID (GUID *pPropGUID) {
	if ( pPropGUID == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	memcpy (pPropGUID, &CLSID_MLeaderDynProp, sizeof(GUID)) ;

	return (S_OK) ;
}

STDMETHODIMP CMLeaderDynProp::GetDisplayName (BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pBstrName =::SysAllocString (L"Текстовый формат") ;

	return (S_OK) ;
}

STDMETHODIMP CMLeaderDynProp::IsPropertyEnabled (IUnknown *pUnk, BOOL *pbEnabled) {
	if ( pUnk == NULL )
		return (E_INVALIDARG) ;
	
	
	if ( pbEnabled == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pbEnabled =TRUE ;

	return (S_OK) ;
}

STDMETHODIMP CMLeaderDynProp::IsPropertyReadOnly (BOOL *pbReadOnly) {
	if ( pbReadOnly == NULL )
		return (E_POINTER) ;

	*pbReadOnly = FALSE ;

	return (S_OK) ;
}

STDMETHODIMP CMLeaderDynProp::GetDescription (BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pBstrName =::SysAllocString (L"Текстовый формат выносок") ;

	return (S_OK) ;
}

STDMETHODIMP CMLeaderDynProp::GetCurrentValueName (BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here

	//return (S_OK) ; //----- If you do anything in there
	return (E_NOTIMPL) ;
}

STDMETHODIMP CMLeaderDynProp::GetCurrentValueType (VARTYPE *pVarType) {
	if ( pVarType == NULL )
		return (E_POINTER) ;
  *pVarType = VT_BSTR; // Строковое значение
	return (S_OK) ;
} 

STDMETHODIMP CMLeaderDynProp::GetCurrentValueData (IUnknown *pUnk, VARIANT *pVarData) {
	if ( pUnk == NULL )
		return (E_INVALIDARG) ;
	if ( pVarData == NULL )
		return (E_POINTER) ;
	::VariantInit (pVarData) ;
  V_VT(pVarData) = VT_BSTR;
  CString v; v.Format(_T("%s"), sFormat.kTCharPtr());
  V_BSTR(pVarData) = v.AllocSysString(); // Возвращаем строку формата

	return (S_OK) ;
}

STDMETHODIMP CMLeaderDynProp::SetCurrentValueData (IUnknown *pUnk, const VARIANT varData) {
	if ( pUnk == NULL )
		return (E_INVALIDARG) ;
	// TODO: add your code here
  sFormat = V_BSTR(&varData);
  PutFormatString(&l_sel, sFormat);
  
	return (S_OK) ;
}

STDMETHODIMP CMLeaderDynProp::Connect (IDynamicPropertyNotify2 *pSink) {
  if (pSink == NULL)
    return (E_POINTER);
  m_pNotify = pSink;
  m_pNotify->AddRef();
  if (SUCCEEDED(m_pNotify->GetCurrentSelectionSet(&l_sel)))
  {
    sFormat = GetFormatString(&l_sel);
  }
  return (S_OK);
}

STDMETHODIMP CMLeaderDynProp::Disconnect () {
	if ( m_pNotify ) {
		m_pNotify->Release () ;
		m_pNotify= NULL ;
	}
	return (S_OK) ;
}



//----- ICategorizePropertes
STDMETHODIMP CMLeaderDynProp::MapPropertyToCategory (DISPID dispid, PROPCAT *pPropCat) {
	if ( pPropCat == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the line below)
	*pPropCat =0 ;

	return (S_OK) ;
}

STDMETHODIMP CMLeaderDynProp::GetCategoryName (PROPCAT propcat, LCID lcid, BSTR *pBstrName) {
	if ( pBstrName == NULL )
		return (E_POINTER) ;
	// TODO: add your code here (and comment the 3 lines below)
	if ( propcat != 0 )
		return (E_INVALIDARG) ;
	*pBstrName =::SysAllocString (L"TVS_Property") ;
  	return (S_OK) ;
}
