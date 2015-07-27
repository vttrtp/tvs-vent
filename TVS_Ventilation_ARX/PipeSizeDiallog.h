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
//----- PipeSizeDiallog.h : Declaration of the PipeSizeDiallog
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
#include "adui.h"
#include "afxwin.h"
#include "Resource.h"
#include "Calculate.h"
#define RadiusTypeRound_RadiusVariable 3
#define RadiusTypeRound_RadiusConstant 2
#define RadiusTypeRound_RadiusSpecific 1

#define RadiusTypeRect_RadiusVariable 2
#define RadiusTypeRect_RadiusConstant 1
#define RadiusTypeRect_RadiusSpecific 3

#define TypeRoundTap_TapSection 1
#define TypeRoundTap_TapRound 2


#define Form_Direct 1
#define Form_Up 2
#define Form_Down 3

#define IDC_SizeA 1001
#define IDC_SizeB 1002
#define IDC_SizeA2 1003
#define IDC_SizeB2 1004
#define IDC_Flow 1005
#define IDC_Speed 1006
#define IDC_dP 1007
#define IDC_i 1008
#define IDC_LevelUp 1013
#define IDC_LevelCenter 1014
#define IDC_LevelDown 1015
#define IDC_LengthWye 1017
#define IDC_TransLength 1023
#define IDC_Wipeout 1020
#define IDC_Grani 1021
#define IDC_1D 1022
#define IDC_ElevVal 1014
#define IDC_ElevUp 1027
#define IDC_ElevMid 1028
#define IDC_ElevDown 1029

#define IDC_TapRadiusRectVariable 1036
#define IDC_TapRadiusRectConst 1037
#define IDC_TapRadiusRoundVariable 1038
#define IDC_TapRadiusRoundConst 1039
#define IDC_TapRadiusRoundSpecific 1040
#define IDC_TapRadiusVariableParameter 1018
#define IDC_TapRadiusConst 1019
#define IDC_TapUp 1034
#define IDC_TapMid 1035
#define IDC_TapDown 1030
#define IDC_Swectangle 1013
//-----------------------------------------------------------------------------
class PipeSizeDiallog : public CAdUiBaseDialog {
	DECLARE_DYNAMIC (PipeSizeDiallog)

public:
	PipeSizeDiallog (CWnd *pParent =NULL, HINSTANCE hInstance =NULL) ;

	enum { IDD = IDD_PIPESIZEDIALLOG} ;

protected:
	virtual void DoDataExchange (CDataExchange *pDX) ;
	afx_msg LRESULT OnAcadKeepFocus (WPARAM, LPARAM) ;

	DECLARE_MESSAGE_MAP()
public:
	
public:
	CEdit fSizeA;
	CEdit fSizeB;
	CEdit fFlow;
	CEdit fSizeA2;
	CEdit fSizeB2;
	CEdit fLengthTr;
	CEdit fLengthW;
	CEdit fElevation;
	CEdit fSpeed;
	CEdit fI;
	CEdit fDp;
	CEdit fTapRadiusVariableParameter;
	CEdit fTapRadiusConst;
	CEdit fSwectangle;

	CButton fWipeout;;
	CButton fGrani;
	CButton fD1;
	CButton fElevUp;
	CButton fElevMid;
	CButton fElevDown;
	CButton F;

	CButton fTapRadiusRectVariable;
	CButton fTapRadiusRectConst;
	CButton fTapRadiusRoundVariable;
	CButton fTapRadiusRoundConst;
	CButton fTapRadiusRoundSpecific;
	CButton fTapUp;
	CButton fTapMid;
	CButton fTapDown;





	double SizeA;
	double SizeB;
	double Flow;
	double Speed;
	double I;
	double Dp;



	double SizeA2;
	double SizeB2;
	double LengthTr;
	double LengthW;
	double Elev;

	double TapForm;
	double TypeRoundTap;
	double RadiusTypeRound;
	double RadiusTypeRect;
	double TapRadiusVariableParameter;
	double TapRadiusConst;
	double Swectangle;

	BOOL Wipe;
	BOOL Grani;
	BOOL D1;
	BOOL ElevMid;
	BOOL ElevDown;
	BOOL ElevUp;


	BOOL TapRadiusRectVariable;
	BOOL TapRadiusRectConst;
	BOOL TapRadiusRoundVariable;
	BOOL TapRadiusRoundConst;
	BOOL TapRadiusRoundSpecific;
	BOOL TapUp;
	BOOL TapMid;
	BOOL TapDown;




	BOOL bSizeA;
	BOOL bSizeB;
	BOOL bFlow;
	BOOL bSizeA2;
	BOOL bSizeB2;
	BOOL bLengthTr;
	BOOL bLengthW;
	BOOL bWipe;
	BOOL bGrani;
	BOOL bD1;


	bool Tpipe;
	bool Twye;
	bool Ttrans;
	bool Ttap;
	int won, woff,gon,goff,d1on,d1off;


	int iTapForm;
	int iTypeRoundTap;
	int iRadiusTypeRound;
	int iRadiusTypeRect;





	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();


	afx_msg void ChangeSizeA();
	afx_msg void ChangeSizeB();
	afx_msg void ChangeSizeA2();
	afx_msg void ChangeSizeB2();
	afx_msg void ChangeFlow();
	afx_msg void ChangeSpeed();
	afx_msg void SetElevUp();
	afx_msg void SetElevMid();
	afx_msg void SetElevDown();
	void change_BOOL(BOOL &var, CButton &but);
	afx_msg void ChangeWipe();
	afx_msg void ChangeGrani();
	afx_msg void ChangeD1();

	afx_msg void SetForm_Up();
	afx_msg void SetForm_Down();
	afx_msg void SetFForm_Direct();

	afx_msg void SetRadiusTypeRound_RadiusSpecific();
	afx_msg void SetRadiusTypeRound_RadiusConstant();
	afx_msg void SetRadiusTypeRound_RadiusVariable();


	afx_msg void SetRadiusTypeRect_RadiusConstant();
	afx_msg void SetRadiusTypeRect_RadiusVariable();



} ;
