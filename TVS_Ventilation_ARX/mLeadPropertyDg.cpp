#include "StdAfx.h"
#include "mLeadPropertyDg.h"
#include "Settings.h"

//-----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC (mLeadPropertyDg, CAdUiBaseDialog)

BEGIN_MESSAGE_MAP(mLeadPropertyDg, CAdUiBaseDialog)
	ON_MESSAGE(WM_ACAD_KEEPFOCUS, OnAcadKeepFocus)
END_MESSAGE_MAP()

//-----------------------------------------------------------------------------
mLeadPropertyDg::mLeadPropertyDg (CWnd *pParent /*=NULL*/, HINSTANCE hInstance /*=NULL*/) : CAdUiBaseDialog (mLeadPropertyDg::IDD, pParent, hInstance)
{

}


//-----------------------------------------------------------------------------
void mLeadPropertyDg::DoDataExchange (CDataExchange *pDX) {
	CAdUiBaseDialog::DoDataExchange (pDX) ;
	Settings *settings = Settings::get();

	DDX_Text(pDX, IDC_EDIT3, settings->mLeader.instructionMessage);
	DDX_Text(pDX, IDC_EDIT1, settings->mLeader.pipeLeader);
	DDX_Text(pDX, IDC_EDIT2, settings->mLeader.blockLeader);
}

//-----------------------------------------------------------------------------
//----- Needed for modeless dialogs to keep focus.
//----- Return FALSE to not keep the focus, return TRUE to keep the focus
LRESULT mLeadPropertyDg::OnAcadKeepFocus (WPARAM, LPARAM) {
	return (TRUE) ;
}
