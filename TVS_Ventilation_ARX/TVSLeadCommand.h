#pragma once
#include "tvs_command.h"
#include "MLeaderSettings.h"
class TVS_Lead_Command :
	public TVS_Command
{
public:
	TVS_Lead_Command(void);
	virtual ~TVS_Lead_Command(void);

	void createMLeader(const CString &message, const AcGePoint3d &ptStart, const AcGePoint3d &ptEnd, const AcDbObjectId &id);
	void ShowLeadDlg();

	virtual void execute(void);
};

