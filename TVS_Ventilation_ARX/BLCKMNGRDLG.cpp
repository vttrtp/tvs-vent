// BLCKMNGRDLG.cpp: файл реализации
//

#include "stdafx.h"
#include "BLCKMNGRDLG.h"
#include "afxdialogex.h"





#include "NewCellTypes/GridURLCell.h"
#include "NewCellTypes/GridCellCombo.h"
#include "NewCellTypes/GridCellCheck.h"
#include "NewCellTypes/GridCellNumeric.h"
#include "NewCellTypes/GridCellDateTime.h"

// #ifdef _DEBUG
// #define new DEBUG_NEW
// #undef THIS_FILE
// static char THIS_FILE[] = __FILE__;
// #endif
// 
// #if defined(_WIN32_WCE) && (_WIN32_WCE <= 0x200)
// #define MF_DISABLED 0
// #define DT_END_ELLIPSIS 0
// #endif

// диалоговое окно BLCKMNGRDLG



IMPLEMENT_DYNAMIC(BLCKMNGRDLG, CAdUiBaseDialog)
BEGIN_MESSAGE_MAP(BLCKMNGRDLG, CAdUiBaseDialog)
	ON_MESSAGE(WM_ACAD_KEEPFOCUS, OnAcadKeepFocus)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()



	BLCKMNGRDLG::BLCKMNGRDLG(CWnd *pParent /*=NULL*/, HINSTANCE hInstance /*=NULL*/) : CAdUiBaseDialog (BLCKMNGRDLG::IDD, pParent, hInstance) 

{
}

BLCKMNGRDLG::~BLCKMNGRDLG()
{
}

void BLCKMNGRDLG::DoDataExchange(CDataExchange* pDX)
{
	CAdUiBaseDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRID, mGrid);
}

// обработчики сообщений BLCKMNGRDLG
LRESULT BLCKMNGRDLG::OnAcadKeepFocus (WPARAM, LPARAM) {

	return (TRUE) ;
}
void BLCKMNGRDLG::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CAdUiBaseDialog::OnShowWindow(bShow, nStatus);

// 	// Add "About..." menu item to system menu.
// 
// 	// IDM_ABOUTBOX must be in the system command range.
// 	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
// 	ASSERT(IDM_ABOUTBOX < 0xF000);
// 
// #ifndef _WIN32_WCE
// 	CMenu* pSysMenu = GetSystemMenu(FALSE);
// 
// 	if (pSysMenu != NULL)
// 	{
// 		CString strAboutMenu;
// 		strAboutMenu.LoadString(IDS_ABOUTBOX);
// 		if (!strAboutMenu.IsEmpty())
// 		{
// 			pSysMenu->AppendMenu(MF_SEPARATOR);
// 			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
// 		}
// 	}
// #else - pulled this since it was causing some probs in CE 3.0 (Bjoern Ruff)
// 	//    CSize ScreenSize;
// 	//    ::SetWindowPos(m_hWnd, HWND_TOP,0,0, 
// 	//                 GetSystemMetrics(SM_CXSCREEN), 
// 	//                 GetSystemMetrics(SM_CYSCREEN) - 32, // 32 = kludge value
// 	//                 SWP_SHOWWINDOW);
// #endif

	int mUnit=50;
	mGrid.SetRowCount(blckList.specList.length()+1);
	mGrid.SetColumnCount(11);
	mGrid.SetColumnWidth(0,mUnit/2);
	mGrid.SetColumnWidth(1,mUnit);
	mGrid.SetColumnWidth(2,mUnit*7);
	mGrid.SetColumnWidth(3,mUnit*2);
	mGrid.SetColumnWidth(4,mUnit*2);
	mGrid.SetColumnWidth(5,mUnit*2);
	mGrid.SetColumnWidth(6,mUnit);
	mGrid.SetColumnWidth(7,mUnit);
	mGrid.SetColumnWidth(8,mUnit);
	mGrid.SetColumnWidth(9,mUnit);
	mGrid.SetColumnWidth(10,mUnit);

	mGrid.SetItemText(0,0,_T("№"));
	mGrid.SetItemText(0,1,_T("Поз."));
	mGrid.SetItemText(0,2,_T("Наименование"));
	mGrid.SetItemText(0,3,_T("Тип"));
	mGrid.SetItemText(0,4,_T("Размер"));
	mGrid.SetItemText(0,5,_T("Артикул"));
	mGrid.SetItemText(0,6,_T("Изготовитель"));
	mGrid.SetItemText(0,7,_T("Еденица"));
	mGrid.SetItemText(0,8,_T("Кол-во"));
	mGrid.SetItemText(0,9,_T("Масса"));
	mGrid.SetItemText(0,10,_T("Примечание"));
	//mGrid.EnableDragAndDrop(TRUE);
	//mGrid.GetDefaultCell(FALSE, FALSE)->SetBackClr(RGB(0xFF, 0xFF, 0xE0));
	//mGrid.AutoSize();
	// 
	//mGrid.SetCompareFunction(CGridCtrl::pfnCellNumericCompare);

	//mGrid.SetItemState(2,2, mGrid.GetItemState(2,2) | GVIS_READONLY);
	mGrid.SetRowResize(0);
	mGrid.SetFixedRowCount(1);
	mGrid.SetFixedColumnCount(1);

	for (int i=0; i<blckList.specList.length();i++)
	{
		int num=i+1;
		
		CString anum;
		anum.Format(L"%i", num);
		blckList.specList[i].setParamChars();
		mGrid.SetItemText(i+1,0,anum);
		mGrid.SetItemText(i+1,1,blckList.specList[i].sPos);
		mGrid.SetItemText(i+1,2,blckList.specList[i].sName);
		mGrid.SetItemText(i+1,3,blckList.specList[i].sType);
		mGrid.SetItemText(i+1,4,blckList.specList[i].sSize);
		mGrid.SetItemText(i+1,5,blckList.specList[i].sArticle);
		mGrid.SetItemText(i+1,6,blckList.specList[i].sManufacture);
		mGrid.SetItemText(i+1,7,blckList.specList[i].sUnit);
		mGrid.SetItemText(i+1,8,blckList.specList[i].param1char);
		mGrid.SetItemText(i+1,9,blckList.specList[i].sMass);
		mGrid.SetItemText(i+1,10,blckList.specList[i].sCommit);
	}
	return;  // return TRUE  unless you set the focus to a control
}