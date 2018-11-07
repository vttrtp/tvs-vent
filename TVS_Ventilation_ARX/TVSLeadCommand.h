#pragma once
#include "TVSCommand.h"
#include "MLeaderSettings.h"
class TVSCommandLead :
	public TVSCommand
{
public:
	TVSCommandLead(void);
	virtual ~TVSCommandLead(void);

	void createMLeader(const CString &message, const AcGePoint3d &ptStart, const AcGePoint3d &ptEnd, const AcDbObjectId &id);
	void ShowLeadDlg();

	virtual void execute(void);
};

