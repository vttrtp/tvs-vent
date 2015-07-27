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
//----- PipeSizeDiallog.cpp : Implementation of PipeSizeDiallog
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "Resource.h"
#include "PipeSizeDiallog.h"

//-----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC (PipeSizeDiallog, CAdUiBaseDialog)

BEGIN_MESSAGE_MAP(PipeSizeDiallog, CAdUiBaseDialog)
	ON_MESSAGE(WM_ACAD_KEEPFOCUS, OnAcadKeepFocus)
	ON_BN_CLICKED(IDOK, &PipeSizeDiallog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &PipeSizeDiallog::OnBnClickedCancel)
END_MESSAGE_MAP()

//-----------------------------------------------------------------------------
PipeSizeDiallog::PipeSizeDiallog (CWnd *pParent /*=NULL*/, HINSTANCE hInstance /*=NULL*/) : CAdUiBaseDialog (PipeSizeDiallog::IDD, pParent, hInstance) , SizeA(0)
	, SizeB(0)
{
}

//-----------------------------------------------------------------------------
void PipeSizeDiallog::DoDataExchange (CDataExchange *pDX) {
	CAdUiBaseDialog::DoDataExchange (pDX) ;
	DDX_Text(pDX, IDC_EDIT1 , SizeA);
	DDX_Text(pDX, IDC_EDIT2, SizeB);
}

//-----------------------------------------------------------------------------
//----- Needed for modeless dialogs to keep focus.
//----- Return FALSE to not keep the focus, return TRUE to keep the focus
LRESULT PipeSizeDiallog::OnAcadKeepFocus (WPARAM, LPARAM) {
	return (TRUE) ;
}


void PipeSizeDiallog::OnBnClickedOk()
{
	this->OnOK();
	// TODO: добавьте свой код обработчика уведомлений
}


void PipeSizeDiallog::OnBnClickedCancel()
{
	this->OnCancel();
	// TODO: добавьте свой код обработчика уведомлений
}
