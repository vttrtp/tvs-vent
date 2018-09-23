#pragma once
#include "adui.h"
#include "afxwin.h"
#include "Resource.h"

class mLeadPropertyDg : public CAdUiBaseDialog {
	DECLARE_DYNAMIC (mLeadPropertyDg)

public:
	mLeadPropertyDg (CWnd *pParent =NULL, HINSTANCE hInstance =NULL) ;

	enum { IDD = IDD_MLEADERPROP} ;

protected:
	virtual void DoDataExchange (CDataExchange *pDX) ;
	afx_msg LRESULT OnAcadKeepFocus (WPARAM, LPARAM) ;

	DECLARE_MESSAGE_MAP()
public:

} ;
