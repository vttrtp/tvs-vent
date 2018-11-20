#include "StdAfx.h"
#include "dgSpecProperty.h"
#include "Settings.h"
//-----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC(dgSpecProperty, CAdUiBaseDialog)

BEGIN_MESSAGE_MAP(dgSpecProperty, CAdUiBaseDialog)
	ON_MESSAGE(WM_ACAD_KEEPFOCUS, OnAcadKeepFocus)
END_MESSAGE_MAP()

//-----------------------------------------------------------------------------
dgSpecProperty::dgSpecProperty(CWnd *pParent /*=NULL*/, HINSTANCE hInstance /*=NULL*/) : CAdUiBaseDialog(dgSpecProperty::IDD, pParent, hInstance)
{

}


//-----------------------------------------------------------------------------
void dgSpecProperty::DoDataExchange(CDataExchange *pDX) {
	CAdUiBaseDialog::DoDataExchange(pDX);
	Settings *settings = Settings::get();
	DDX_Text(pDX, IDC_EDIT3, instructionMessage);
	DDX_Text(pDX, IDC_EDIT1, specProps);
}

//-----------------------------------------------------------------------------
//----- Needed for modeless dialogs to keep focus.
//----- Return FALSE to not keep the focus, return TRUE to keep the focus
LRESULT dgSpecProperty::OnAcadKeepFocus(WPARAM, LPARAM) {
	return (TRUE);
}
