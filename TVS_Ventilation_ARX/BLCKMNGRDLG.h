#pragma once
#include "adui.h"
#include "afxwin.h"
#include "../GridCtrl_src/GridCtrl.h"
#include "resource.h"
#include "stdafx.h"
#include "SPEC.h"
//#include "GridCtrlDemo.h"



// ���������� ���� BLCKMNGRDLG

class BLCKMNGRDLG : public CAdUiBaseDialog {
	DECLARE_DYNAMIC(BLCKMNGRDLG)

public:
	BLCKMNGRDLG(CWnd *pParent =NULL, HINSTANCE hInstance =NULL) ;;   // ����������� �����������
	virtual ~BLCKMNGRDLG();

// ������ ����������� ����
	enum { IDD = IDD_BLCKMNGRDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	
afx_msg	LRESULT OnAcadKeepFocus (WPARAM, LPARAM);

DECLARE_MESSAGE_MAP()
public:
	CGridCtrl mGrid;
	afx_msg 	void OnShowWindow(BOOL bShow, UINT nStatus);
	SpecWithAttrlist blckList;
};
