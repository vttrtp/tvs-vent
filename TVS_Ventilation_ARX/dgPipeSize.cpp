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
//----- dgPipeSize.cpp : Implementation of dgPipeSize
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "Resource.h"
#include "dgPipeSize.h"

//-----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC(dgPipeSize, CAdUiBaseDialog)

BEGIN_MESSAGE_MAP(dgPipeSize, CAdUiBaseDialog)
	ON_MESSAGE(WM_ACAD_KEEPFOCUS, OnAcadKeepFocus)
	//		ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDOK, &dgPipeSize::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &dgPipeSize::OnBnClickedCancel)

	ON_EN_CHANGE(IDC_SizeA, &dgPipeSize::ChangeSizeA)
	ON_EN_CHANGE(IDC_SizeB, &dgPipeSize::ChangeSizeA)
	//ON_EN_CHANGE(IDC_SizeA2, &dgPipeSize::ChangeSizeA2)
	//ON_EN_CHANGE(IDC_SizeB2, &dgPipeSize::ChangeSizeB2)
	ON_EN_CHANGE(IDC_Flow, &dgPipeSize::ChangeSizeA)
	ON_EN_CHANGE(IDC_Speed, &dgPipeSize::ChangeSpeed)
	ON_BN_CLICKED(IDC_ElevUp, &dgPipeSize::SetElevUp)
	ON_BN_CLICKED(IDC_ElevMid, &dgPipeSize::SetElevMid)
	ON_BN_CLICKED(IDC_ElevDown, &dgPipeSize::SetElevDown)
	ON_BN_CLICKED(IDC_Wipeout, &dgPipeSize::ChangeWipe)
	ON_BN_CLICKED(IDC_Grani, &dgPipeSize::ChangeGrani)
	ON_BN_CLICKED(IDC_1D, &dgPipeSize::ChangeD1)
	//ON_BN_CLICKED(IDC_TapDown, &dgPipeSize::SetForm_Down)
	//ON_BN_CLICKED(IDC_TapMid, &dgPipeSize::SetFForm_Direct)
	//ON_BN_CLICKED(IDC_TapUp, &dgPipeSize::SetForm_Up)

	ON_BN_CLICKED(IDC_TapRadiusRoundConst, &dgPipeSize::SetRadiusTypeRound_RadiusConstant)
	ON_BN_CLICKED(IDC_TapRadiusRoundVariable, &dgPipeSize::SetRadiusTypeRound_RadiusVariable)
	ON_BN_CLICKED(IDC_TapRadiusRoundSpecific, &dgPipeSize::SetRadiusTypeRound_RadiusSpecific)

	ON_BN_CLICKED(IDC_TapRadiusRectConst, &dgPipeSize::SetRadiusTypeRect_RadiusConstant)
	ON_BN_CLICKED(IDC_TapRadiusRectVariable, &dgPipeSize::SetRadiusTypeRect_RadiusVariable)

	ON_BN_CLICKED(IDC_DuctFlex, &dgPipeSize::ChangeDuctFlex)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()

//-----------------------------------------------------------------------------
dgPipeSize::dgPipeSize(CWnd *pParent /*=NULL*/, HINSTANCE hInstance /*=NULL*/) : CAdUiBaseDialog(dgPipeSize::IDD, pParent, hInstance), SizeA(0)
, SizeB(0)
{
}

//-----------------------------------------------------------------------------
void dgPipeSize::DoDataExchange(CDataExchange *pDX) {
	CAdUiBaseDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SizeA, fSizeA);
	DDX_Control(pDX, IDC_SizeB, fSizeB);
	DDX_Control(pDX, IDC_Flow, fFlow);
	//DDX_Control(pDX, IDC_SizeA2, fSizeA2);
	//DDX_Control(pDX, IDC_SizeB2, fSizeB2);
	DDX_Control(pDX, IDC_TransLength, fLengthTr);
	DDX_Control(pDX, IDC_LengthWye, fLengthW);
	DDX_Control(pDX, IDCANCEL, F);
	DDX_Control(pDX, IDC_Wipeout, fWipeout);
	DDX_Control(pDX, IDC_Grani, fGrani);
	DDX_Control(pDX, IDC_1D, fD1);
	DDX_Control(pDX, IDC_ElevVal, fElevation);
	DDX_Control(pDX, IDC_ElevUp, fElevUp);
	DDX_Control(pDX, IDC_ElevMid, fElevMid);
	DDX_Control(pDX, IDC_ElevDown, fElevDown);
	DDX_Control(pDX, IDC_Speed, fSpeed);
	DDX_Control(pDX, IDC_i, fI);
	//DDX_Control(pDX, IDC_dP, fDp);

	DDX_Control(pDX, IDC_TapRadiusRectVariable, fTapRadiusRectVariable);
	DDX_Control(pDX, IDC_TapRadiusRectConst, fTapRadiusRectConst);
	DDX_Control(pDX, IDC_TapRadiusRoundVariable, fTapRadiusRoundVariable);
	DDX_Control(pDX, IDC_TapRadiusRoundConst, fTapRadiusRoundConst);
	DDX_Control(pDX, IDC_TapRadiusRoundSpecific, fTapRadiusRoundSpecific);
	//DDX_Control(pDX, IDC_TapUp, fTapUp);
	//DDX_Control(pDX, IDC_TapMid, fTapMid);
	//DDX_Control(pDX, IDC_TapDown, fTapDown);
	//DDX_Control(pDX, IDC_Swectangle, fSwectangle);
	DDX_Control(pDX, IDC_TapRadiusVariableParameter, fTapRadiusVariableParameter);
	DDX_Control(pDX, IDC_TapRadiusConst, fTapRadiusConst);



	DDX_Text(pDX, IDC_SizeA, SizeA);
	DDX_Text(pDX, IDC_SizeB, SizeB);
	DDX_Text(pDX, IDC_Flow, Flow);
	//DDX_Text(pDX, IDC_SizeA2, SizeA2);
	//DDX_Text(pDX, IDC_SizeB2, SizeB2);
	DDX_Text(pDX, IDC_TransLength, LengthTr);
	DDX_Text(pDX, IDC_LengthWye, LengthW);
	DDX_Text(pDX, IDC_ElevVal, Elev);
	DDX_Text(pDX, IDC_Speed, Speed);
	DDX_Text(pDX, IDC_i, I);
	//DDX_Text(pDX, IDC_dP, Dp);

	//DDX_Text(pDX, IDC_Swectangle, Swectangle);
	DDX_Text(pDX, IDC_TapRadiusVariableParameter, TapRadiusVariableParameter);
	DDX_Text(pDX, IDC_TapRadiusConst, TapRadiusConst);





	DDX_Check(pDX, IDC_Wipeout, Wipe);
	DDX_Check(pDX, IDC_Grani, Grani);
	DDX_Check(pDX, IDC_1D, D1);
	DDX_Check(pDX, IDC_ElevUp, ElevUp);
	DDX_Check(pDX, IDC_ElevMid, ElevMid);
	DDX_Check(pDX, IDC_ElevDown, ElevDown);

	DDX_Check(pDX, IDC_Wipeout, Wipe);
	DDX_Check(pDX, IDC_Grani, Grani);
	DDX_Check(pDX, IDC_1D, D1);
	DDX_Check(pDX, IDC_ElevUp, ElevUp);
	DDX_Check(pDX, IDC_ElevMid, ElevMid);
	DDX_Check(pDX, IDC_ElevDown, ElevDown);

	DDX_Check(pDX, IDC_TapRadiusRectVariable, TapRadiusRectVariable);
	DDX_Check(pDX, IDC_TapRadiusRectConst, TapRadiusRectConst);
	DDX_Check(pDX, IDC_TapRadiusRoundVariable, TapRadiusRoundVariable);
	DDX_Check(pDX, IDC_TapRadiusRoundConst, TapRadiusRoundConst);
	DDX_Check(pDX, IDC_TapRadiusRoundSpecific, TapRadiusRoundSpecific);


	DDX_Control(pDX, IDC_WipeoutLength, fWipeoutLength);
	DDX_Text(pDX, IDC_WipeoutLength, WipeoutLength);


	DDX_Control(pDX, IDC_DuctFlex, fDuctFlex);
	DDX_Check(pDX, IDC_DuctFlex, DuctFlex);
	//DDX_Check(pDX, IDC_TapUp, TapUp);
	//DDX_Check(pDX, IDC_TapMid, TapMid);
	//DDX_Check(pDX, IDC_TapDown, TapDown);
}

//-----------------------------------------------------------------------------
//----- Needed for modeless dialogs to keep focus.
//----- Return FALSE to not keep the focus, return TRUE to keep the focus
LRESULT dgPipeSize::OnAcadKeepFocus(WPARAM, LPARAM) {

	return (TRUE);
}





void dgPipeSize::OnBnClickedOk()
{


	if (TapRadiusRoundConst == TRUE)
	{
		RadiusTypeRound = RadiusTypeRound_RadiusConstant;
	}

	if (TapRadiusRoundVariable == TRUE)
	{
		RadiusTypeRound = RadiusTypeRound_RadiusVariable;
	}

	if (TapRadiusRoundSpecific == TRUE)
	{
		RadiusTypeRound = RadiusTypeRound_RadiusSpecific;
	}

	if (TapRadiusRectConst == TRUE)
	{
		RadiusTypeRect = RadiusTypeRect_RadiusConstant;
	}

	if (TapRadiusRectVariable == TRUE)
	{
		RadiusTypeRect = RadiusTypeRect_RadiusVariable;
	}




	this->OnOK();
	// TODO: добавьте свой код обработчика уведомлений
	// TODO: добавьте свой код обработчика уведомлений
}


void dgPipeSize::OnBnClickedCancel()
{
	this->OnCancel();
	// TODO: добавьте свой код обработчика уведомлений
}



void dgPipeSize::ChangeSizeA()
{

	double pSpeed, pFlow, pI, pDp, pSizeA, pSizeB;
	CString zSizeA, zSizeB, zFlow, zSpeed, zI;
	fSizeB.GetWindowTextW(zSizeB);
	fSizeA.GetWindowTextW(zSizeA);
	fFlow.GetWindowTextW(zFlow);

	pSizeA = _wtof(zSizeA);
	pSizeB = _wtof(zSizeB);
	pFlow = _wtof(zFlow);
	pSpeed = TVS_Calculate::getSpeed(pSizeA, pSizeB, pFlow);
	pI = TVS_Calculate::getI(pSizeA, pSizeB, pFlow);
	//pDp=TVS_Calculate::getdP(pSizeA,pSizeB,pFlow);
	zSpeed.Format(L"%g", pSpeed);
	zI.Format(L"%g", pI);
	fSpeed.SetWindowTextW(zSpeed);
	fI.SetWindowTextW(zI);





}

void dgPipeSize::ChangeSpeed()
{

	// 	double pSpeed, pFlow, pI, pDp, pSizeA, pSizeB;
	// 	CString zSizeA,zSizeB,zFlow,zSpeed,zI;
	// 	fSizeB.GetWindowTextW(zSizeB);
	// 	fSizeA.GetWindowTextW(zSizeA);
	// 	fSpeed.GetWindowTextW(zSpeed);
	// 
	// 	pSizeA=_wtof(zSizeA);
	// 	pSizeB=_wtof(zSizeB);
	// 	pSpeed=_wtof(zSpeed);
	// 	pFlow=TVS_Calculate::getFlow(pSizeA,pSizeB,pSpeed);
	// 	pI=TVS_Calculate::getI(pSizeA,pSizeB,pFlow);
	// 
	// 	zFlow.Format(L"%g", pFlow);
	// 	zI.Format(L"%g", pI);
	// 	fFlow.SetWindowTextW(zFlow);
	// 	fI.SetWindowTextW(zI);





}


void dgPipeSize::SetElevUp()
{

	fElevUp.SetCheck(1);
	fElevMid.SetCheck(0);
	fElevDown.SetCheck(0);




	// TODO: добавьте свой код обработчика уведомлений
}

void dgPipeSize::SetElevMid()
{


	fElevUp.SetCheck(0);
	fElevMid.SetCheck(1);
	fElevDown.SetCheck(0);
	// TODO: добавьте свой код обработчика уведомлений
}

void dgPipeSize::SetElevDown()
{
	fElevUp.SetCheck(0);
	fElevMid.SetCheck(0);
	fElevDown.SetCheck(1);
	// TODO: добавьте свой код обработчика уведомлений
}




void dgPipeSize::change_BOOL(BOOL &var, CButton &but)
{
	if (var == 1)
	{
		var = 0;
		but.SetCheck(0);

	}
	else
	{
		var = 1;
		but.SetCheck(1);
	}
}

void dgPipeSize::ChangeWipe()
{
	change_BOOL(Wipe, fWipeout);
}

void dgPipeSize::ChangeGrani()
{
	change_BOOL(Grani, fGrani);
}

void dgPipeSize::ChangeD1()
{
	change_BOOL(D1, fD1);
}



void dgPipeSize::SetRadiusTypeRound_RadiusSpecific()
{


	TapRadiusRoundSpecific = true;
	fTapRadiusRoundSpecific.SetCheck(1);


	TapRadiusRoundConst = false;
	fTapRadiusRoundConst.SetCheck(0);


	TapRadiusRoundVariable = false;
	fTapRadiusRoundVariable.SetCheck(0);


}

void dgPipeSize::SetRadiusTypeRound_RadiusConstant()
{
	TapRadiusRoundSpecific = false;
	fTapRadiusRoundSpecific.SetCheck(0);


	TapRadiusRoundConst = true;
	fTapRadiusRoundConst.SetCheck(1);


	TapRadiusRoundVariable = false;
	fTapRadiusRoundVariable.SetCheck(0);
}

void dgPipeSize::SetRadiusTypeRound_RadiusVariable()
{
	TapRadiusRoundSpecific = false;
	fTapRadiusRoundSpecific.SetCheck(0);


	TapRadiusRoundConst = false;
	fTapRadiusRoundConst.SetCheck(0);


	TapRadiusRoundVariable = true;
	fTapRadiusRoundVariable.SetCheck(1);
}

void dgPipeSize::SetRadiusTypeRect_RadiusConstant()
{
	TapRadiusRectConst = true;
	fTapRadiusRectConst.SetCheck(1);


	TapRadiusRectVariable = false;
	fTapRadiusRectVariable.SetCheck(0);


}

void dgPipeSize::SetRadiusTypeRect_RadiusVariable()
{
	TapRadiusRectConst = false;
	fTapRadiusRectConst.SetCheck(0);


	TapRadiusRectVariable = true;
	fTapRadiusRectVariable.SetCheck(1);
}


void dgPipeSize::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CAdUiBaseDialog::OnShowWindow(bShow, nStatus);


	fSizeA.SetFocus();

	SendDlgItemMessage(IDC_SizeA, EM_SETSEL, (WPARAM)0, (LPARAM)-1);






	iTapForm = TapForm;
	iTypeRoundTap = TypeRoundTap;
	iRadiusTypeRound = RadiusTypeRound;
	iRadiusTypeRect = RadiusTypeRect;
	CString var;



	switch (iRadiusTypeRound)
	{
	case RadiusTypeRound_RadiusSpecific:
		TapRadiusRoundSpecific = true;
		fTapRadiusRoundSpecific.SetCheck(1);
		break;
	case RadiusTypeRound_RadiusConstant:
		TapRadiusRoundConst = true;
		fTapRadiusRoundConst.SetCheck(1);
		break;
	case RadiusTypeRound_RadiusVariable:
		TapRadiusRoundVariable = true;
		fTapRadiusRoundVariable.SetCheck(1);
		break;
	default:
		break;
	}

	switch (iRadiusTypeRect)
	{

	case RadiusTypeRect_RadiusConstant:
		TapRadiusRectConst = true;
		fTapRadiusRectConst.SetCheck(1);
		break;
	case RadiusTypeRect_RadiusVariable:
		TapRadiusRectVariable = true;
		fTapRadiusRectVariable.SetCheck(1);
		break;
	default:
		break;





	}


	ChangeSizeA();
	// TODO: добавьте свой код обработчика сообщений
}

void dgPipeSize::ChangeDuctFlex()
{
	//change_BOOL(iDuctFlex,fDuctFlex);

	change_BOOL(DuctFlex, fDuctFlex);
}