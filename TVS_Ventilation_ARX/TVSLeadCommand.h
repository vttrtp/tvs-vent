#pragma once
#include "tvs_command.h"
#include "MLeaderSettings.h"
class TVS_Lead_Command :
	public TVS_Command
{
public:
	TVS_Lead_Command(void);
	virtual ~TVS_Lead_Command(void);
	
	bool GetAtt(AcDbBlockReference* pBr, const CString& tag, CString& valueStr);
	bool GetStringProperty(AcDbEntity* pEnt, CString &stringText);

	bool GetEntityStringProperty(TVS_Entity* pEnt, CString &stringText);
	bool GetEntityStringPropertyByName(TVS_Entity* pEnt, const CString &stringTemplate, CString &stringText);

	bool GetBlockStringProperty(AcDbBlockReference* pBr, CString &stringText);
	bool GetBlockStringPropertyByName(AcDbBlockReference* pBr, const CString &stringTemplate, CString &stringText);

	void createMLeader(const CString &message, const AcGePoint3d &ptStart, const AcGePoint3d &ptEnd);
	void ShowLeadDlg();

	virtual void execute(void);
};

