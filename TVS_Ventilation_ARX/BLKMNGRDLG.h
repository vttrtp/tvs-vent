#pragma once
#include "StdAfx.h"
#include "resource.h"
#include "../GridCtrl_src/GridCtrl.h"
// диалоговое окно BLKMNGRDLG

class BLKMNGRDLG : public CDialog
{
	DECLARE_DYNAMIC(BLKMNGRDLG)

public:
	BLKMNGRDLG(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~BLKMNGRDLG();

// Данные диалогового окна
	enum { IDD = IDD_BLOCKMNGRDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CGridCtrl mGrid;
};
