#pragma once
#include "StdAfx.h"
#include "resource.h"
#include "../GridCtrl_src/GridCtrl.h"
// ���������� ���� BLKMNGRDLG

class BLKMNGRDLG : public CDialog
{
	DECLARE_DYNAMIC(BLKMNGRDLG)

public:
	BLKMNGRDLG(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~BLKMNGRDLG();

// ������ ����������� ����
	enum { IDD = IDD_BLOCKMNGRDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CGridCtrl mGrid;
};
