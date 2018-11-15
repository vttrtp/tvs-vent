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
#include "dgTVSPropertyManager.h"
#include "TVSProperty.h"

//-----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC(dgTVSPropertyManager, CAdUiBaseDialog)

BEGIN_MESSAGE_MAP(dgTVSPropertyManager, CAdUiBaseDialog)
	ON_MESSAGE(WM_ACAD_KEEPFOCUS, OnAcadKeepFocus)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDOK, &dgTVSPropertyManager::OnBnClickedOk)
END_MESSAGE_MAP()

//-----------------------------------------------------------------------------
dgTVSPropertyManager::dgTVSPropertyManager(CWnd *pParent /*=NULL*/, HINSTANCE hInstance /*=NULL*/) : CAdUiBaseDialog(dgTVSPropertyManager::IDD, pParent, hInstance) {
}

//-----------------------------------------------------------------------------
void dgTVSPropertyManager::DoDataExchange(CDataExchange *pDX) {
	CAdUiBaseDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRID, mGrid);
}

//-----------------------------------------------------------------------------
//----- Needed for modeless dialogs to keep focus.
//----- Return FALSE to not keep the focus, return TRUE to keep the focus
LRESULT dgTVSPropertyManager::OnAcadKeepFocus(WPARAM, LPARAM) {
	return (TRUE);
}

CString getString(const double &val) {
	CString str;
	str.Format(L"%g", val);
	return str;
}
CString getString(const size_t &val) {
	CString str;
	str.Format(L"%d", val);
	return str;
}

void dgTVSPropertyManager::OnShowWindow(BOOL bShow, UINT nStatus)
{
	int rowsc = propertySpec.rows.size();
	int wide = 50;
	mGrid.SetFixedColumnCount(1);
	mGrid.SetFixedRowCount(1);
	mGrid.SetRowCount(rowsc + 1);
	mGrid.SetColumnCount(12);
	mGrid.SetColumnWidth(0, wide / 2);
	mGrid.SetColumnWidth(1, wide);
	mGrid.SetColumnWidth(2, wide * 6);
	mGrid.SetColumnWidth(3, wide * 2);
	mGrid.SetColumnWidth(4, wide * 2);
	mGrid.SetColumnWidth(5, wide * 2);
	mGrid.SetColumnWidth(6, wide * 2);
	mGrid.SetColumnWidth(7, wide);
	mGrid.SetColumnWidth(8, wide);
	mGrid.SetColumnWidth(9, wide);
	mGrid.SetColumnWidth(10, wide * 2);
	mGrid.SetColumnWidth(11, wide);

	mGrid.SetItemText(0, 0, _T("№"));
	mGrid.SetItemText(0, 1, CTVSProperty_position);
	mGrid.SetItemText(0, 2, CTVSProperty_name);
	mGrid.SetItemText(0, 3, CTVSProperty_type);
	mGrid.SetItemText(0, 4, CTVSProperty_size);
	mGrid.SetItemText(0, 5, CTVSProperty_article);
	mGrid.SetItemText(0, 6, CTVSProperty_manufacturer);
	mGrid.SetItemText(0, 7, CTVSProperty_units);
	mGrid.SetItemText(0, 8, CTVSProperty_count);
	mGrid.SetItemText(0, 9, CTVSProperty_mass);
	mGrid.SetItemText(0, 10, CTVSProperty_note);
	mGrid.SetItemText(0, 11, L"Выбрано");

	int i = 1;
	for (auto &row : propertySpec.rows)
	{

		ACHAR  num[20];
		acdbRToS(i, 2, 0, num);
		mGrid.SetItemText(i, 0, num);
		mGrid.SetItemText(i, 1, row.tvsPropery.position);
		mGrid.SetItemText(i, 2, row.tvsPropery.name);
		mGrid.SetItemText(i, 3, row.tvsPropery.type);
		mGrid.SetItemText(i, 4, row.tvsPropery.size);
		mGrid.SetItemText(i, 5, row.tvsPropery.article);
		mGrid.SetItemText(i, 6, row.tvsPropery.manufacturer);
		mGrid.SetItemText(i, 7, row.tvsPropery.units);
		mGrid.SetItemText(i, 8, getString(row.tvsPropery.count));
		mGrid.SetItemText(i, 9, getString(row.tvsPropery.mass));
		mGrid.SetItemText(i, 10, row.tvsPropery.note);
		mGrid.SetItemText(i, 11, getString(row.objectIds.size()));
		i++;
	}
}


void dgTVSPropertyManager::OnBnClickedOk()
{
	int i = 1;
	for (auto &row : propertySpec.rows)
	{

		row.setAndRecalculatePosition(mGrid.GetItemText(i, 1));
		row.setAndRecalculateName(mGrid.GetItemText(i, 2));
		row.setAndRecalculateType(mGrid.GetItemText(i, 3));
		row.setAndRecalculateSize(mGrid.GetItemText(i, 4));
		row.setAndRecalculateArticle(mGrid.GetItemText(i, 5));
		row.setAndRecalculateManufacturer(mGrid.GetItemText(i, 6));
		row.setAndRecalculateUnits(mGrid.GetItemText(i, 7));
		row.setAndRecalculateCount(_tstof(mGrid.GetItemText(i, 8)));
		row.setAndRecalculateMass(_tstof(mGrid.GetItemText(i, 9)));
		row.setAndRecalculateNote(mGrid.GetItemText(i, 10));

		i++;
	}
	this->OnOK();
	// TODO: добавьте свой код обработчика уведомлений
}
