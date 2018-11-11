#pragma once
#include "adui.h"
#include "afxwin.h"
#include "Resource.h"

class dgMLeadProperty : public CAdUiBaseDialog {
	DECLARE_DYNAMIC (dgMLeadProperty)

public:
	dgMLeadProperty (CWnd *pParent =NULL, HINSTANCE hInstance =NULL) ;

	enum { IDD = IDD_MLEADERPROP} ;

protected:
	virtual void DoDataExchange (CDataExchange *pDX) ;
	afx_msg LRESULT OnAcadKeepFocus (WPARAM, LPARAM) ;

	DECLARE_MESSAGE_MAP()
public:

} ;
