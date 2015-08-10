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
//----- hangeZdg.cpp : Implementation of changeZdg
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"
#include "hangeZdg.h"

//-----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC (changeZdg, CAdUiBaseDialog)

BEGIN_MESSAGE_MAP(changeZdg, CAdUiBaseDialog)
	ON_MESSAGE(WM_ACAD_KEEPFOCUS, OnAcadKeepFocus)
END_MESSAGE_MAP()

//-----------------------------------------------------------------------------
changeZdg::changeZdg (CWnd *pParent /*=NULL*/, HINSTANCE hInstance /*=NULL*/) : CAdUiBaseDialog (changeZdg::IDD, pParent, hInstance) {
}

//-----------------------------------------------------------------------------
void changeZdg::DoDataExchange (CDataExchange *pDX) {
	CAdUiBaseDialog::DoDataExchange (pDX) ;
	DDX_Text(pDX, IDC_StartZ, startZ);
	DDX_Text(pDX, IDC_NextZ, nextZ);
	DDX_Text(pDX, IDC_Axis, Axis);
}

//-----------------------------------------------------------------------------
//----- Needed for modeless dialogs to keep focus.
//----- Return FALSE to not keep the focus, return TRUE to keep the focus
LRESULT changeZdg::OnAcadKeepFocus (WPARAM, LPARAM) {
	return (TRUE) ;
}
