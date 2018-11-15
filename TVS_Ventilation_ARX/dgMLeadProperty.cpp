#include "StdAfx.h"
#include "dgMLeadProperty.h"
#include "Settings.h"

//-----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC(dgMLeadProperty, CAdUiBaseDialog)

BEGIN_MESSAGE_MAP(dgMLeadProperty, CAdUiBaseDialog)
	ON_MESSAGE(WM_ACAD_KEEPFOCUS, OnAcadKeepFocus)
END_MESSAGE_MAP()

//-----------------------------------------------------------------------------
dgMLeadProperty::dgMLeadProperty(CWnd *pParent /*=NULL*/, HINSTANCE hInstance /*=NULL*/) : CAdUiBaseDialog(dgMLeadProperty::IDD, pParent, hInstance)
{

}


//-----------------------------------------------------------------------------
void dgMLeadProperty::DoDataExchange(CDataExchange *pDX) {
	CAdUiBaseDialog::DoDataExchange(pDX);
	Settings *settings = Settings::get();

	DDX_Text(pDX, IDC_EDIT3, settings->mLeader.instructionMessage);
	DDX_Text(pDX, IDC_EDIT1, settings->mLeader.pipeLeader);
	DDX_Text(pDX, IDC_EDIT2, settings->mLeader.blockLeader);
}

//-----------------------------------------------------------------------------
//----- Needed for modeless dialogs to keep focus.
//----- Return FALSE to not keep the focus, return TRUE to keep the focus
LRESULT dgMLeadProperty::OnAcadKeepFocus(WPARAM, LPARAM) {
	return (TRUE);
}
