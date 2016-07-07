// BLKMNGRDLG.cpp: файл реализации
//

#include "stdafx.h"
#include "BLKMNGRDLG.h"
#include "afxdialogex.h"


// диалоговое окно BLKMNGRDLG

IMPLEMENT_DYNAMIC(BLKMNGRDLG, CDialog)

BLKMNGRDLG::BLKMNGRDLG(CWnd* pParent /*=NULL*/)
	: CDialog(BLKMNGRDLG::IDD, pParent)
{

}

BLKMNGRDLG::~BLKMNGRDLG()
{
}

void BLKMNGRDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM1, mGrid);
}


BEGIN_MESSAGE_MAP(BLKMNGRDLG, CDialog)
END_MESSAGE_MAP()


// обработчики сообщений BLKMNGRDLG
