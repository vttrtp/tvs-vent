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
//----- BLKMNGRDLG.cpp : Implementation of BLKMNGRDLG
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"
#include "BLCKMNGRDLG.h"

//-----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC (BLCKMNGRDLG, CAdUiBaseDialog)

BEGIN_MESSAGE_MAP(BLCKMNGRDLG, CAdUiBaseDialog)
	ON_MESSAGE(WM_ACAD_KEEPFOCUS, OnAcadKeepFocus)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDOK, &BLCKMNGRDLG::OnBnClickedOk)
END_MESSAGE_MAP()

//-----------------------------------------------------------------------------
BLCKMNGRDLG::BLCKMNGRDLG (CWnd *pParent /*=NULL*/, HINSTANCE hInstance /*=NULL*/) : CAdUiBaseDialog (BLCKMNGRDLG::IDD, pParent, hInstance) {
}

//-----------------------------------------------------------------------------
void BLCKMNGRDLG::DoDataExchange (CDataExchange *pDX) {
	CAdUiBaseDialog::DoDataExchange (pDX) ;
	DDX_Control(pDX, IDC_GRID, mGrid);
}

//-----------------------------------------------------------------------------
//----- Needed for modeless dialogs to keep focus.
//----- Return FALSE to not keep the focus, return TRUE to keep the focus
LRESULT BLCKMNGRDLG::OnAcadKeepFocus (WPARAM, LPARAM) {
	return (TRUE) ;
}

void BLCKMNGRDLG::OnShowWindow(BOOL bShow, UINT nStatus)
{

// 	int width = 800,
// 		height = min((blckList.specList.length()+1)*20+50,800);
// // 	if (GetSystemMetrics(SM_CXSCREEN) > 800)
// // 	{
// // 		width = 1024;
// // 		height = 768;
// // 	}
// // 	if (GetSystemMetrics(SM_CXSCREEN) > 1024)
// // 	{
// // 		width = 1280;
// // 		height = 1024;
// // 	}
// 	MoveWindow((GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2),
// 		(GetSystemMetrics(SM_CYSCREEN) / 2 - height / 2), width, height);





	int wide=50;
	mGrid.SetFixedColumnCount(1);
	mGrid.SetFixedRowCount(1);
	mGrid.SetRowCount(blckList.specList.length()+1);
	mGrid.SetColumnCount(11);
	mGrid.SetColumnWidth(0,wide/2);
	mGrid.SetColumnWidth(1,wide);
	mGrid.SetColumnWidth(2,wide*6);
	mGrid.SetColumnWidth(3,wide*2);
	mGrid.SetColumnWidth(4,wide*2);
	mGrid.SetColumnWidth(5,wide*2);
	mGrid.SetColumnWidth(6,wide*2);
	mGrid.SetColumnWidth(7,wide);
	mGrid.SetColumnWidth(8,wide);
	mGrid.SetColumnWidth(9,wide);
	mGrid.SetColumnWidth(10,wide*2);

	mGrid.SetItemText(0,0, _T("№"));
	mGrid.SetItemText(0,1, _T("Поз"));
	mGrid.SetItemText(0,2, _T("Наименование"));
	mGrid.SetItemText(0,3, _T("Тип"));
	mGrid.SetItemText(0,4, _T("Размер"));
	mGrid.SetItemText(0,5, _T("Артикул"));
	mGrid.SetItemText(0,6, _T("Производитель"));
	mGrid.SetItemText(0,7, _T("Единица"));
	mGrid.SetItemText(0,8, _T("Кол-во"));
	mGrid.SetItemText(0,9, _T("Масса"));
	mGrid.SetItemText(0,10, _T("Примечание"));
	
	for (int i = 0; i < blckList.specList.length(); i++)
	{
		blckList.specList[i].setParamChars();
		ACHAR  num[20];
		acdbRToS(i+1,2,0,num);
		mGrid.SetItemText(i+1,0, num);
		mGrid.SetItemText(i+1,1, blckList.specList[i].sPos);
		mGrid.SetItemText(i+1,2, blckList.specList[i].sName);
		mGrid.SetItemText(i+1,3, blckList.specList[i].sType);
		mGrid.SetItemText(i+1,4, blckList.specList[i].sSize);
		mGrid.SetItemText(i+1,5, blckList.specList[i].sArticle);
		mGrid.SetItemText(i+1,6, blckList.specList[i].sManufacture);
		mGrid.SetItemText(i+1,7, blckList.specList[i].sUnit);
		mGrid.SetItemText(i+1,8, blckList.specList[i].sValue);
		mGrid.SetItemText(i+1,9, blckList.specList[i].sMass);
		mGrid.SetItemText(i+1,10,blckList.specList[i].sCommit);
		mGrid.SetItemState(i+1,7, mGrid.GetItemState(i+1,7) | GVIS_READONLY);
		mGrid.SetItemState(i+1,8, mGrid.GetItemState(i+1,8) | GVIS_READONLY);
		
	}
}


void BLCKMNGRDLG::OnBnClickedOk()
{
	for (int i = 0; i < blckList.specList.length(); i++)
	{

		wcscpy_s(blckList.specList[i].sPos,mGrid.GetItemText(i+1,1));
		wcscpy_s(blckList.specList[i].sName,mGrid.GetItemText(i+1,2));
		wcscpy_s(blckList.specList[i].sType,mGrid.GetItemText(i+1,3));
		wcscpy_s(blckList.specList[i].sSize,mGrid.GetItemText(i+1,4));
		wcscpy_s(blckList.specList[i].sArticle,mGrid.GetItemText(i+1,5));
		wcscpy_s(blckList.specList[i].sManufacture,mGrid.GetItemText(i+1,6));
		wcscpy_s(blckList.specList[i].sMass,mGrid.GetItemText(i+1,9));
		wcscpy_s(blckList.specList[i].sCommit,mGrid.GetItemText(i+1,10));

	}
	this->OnOK();
	// TODO: добавьте свой код обработчика уведомлений
}
