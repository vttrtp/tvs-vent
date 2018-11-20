#pragma once
#include "adui.h"
#include "afxwin.h"
#include "Resource.h"

class dgSpecProperty : public CAdUiBaseDialog {
	DECLARE_DYNAMIC(dgSpecProperty)

public:
	dgSpecProperty(CWnd *pParent = NULL, HINSTANCE hInstance = NULL);

	enum {
		IDD = IDD_SPECPROPS
	};

protected:
	virtual void DoDataExchange(CDataExchange *pDX);
	afx_msg LRESULT OnAcadKeepFocus(WPARAM, LPARAM);

	DECLARE_MESSAGE_MAP()
public:
	CString specProps;
	CString instructionMessage;
};
