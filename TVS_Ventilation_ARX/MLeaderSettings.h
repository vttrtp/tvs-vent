#pragma once
#include "arxHeaders.h"
#include "TVS_Entity.h"
#define MLeaderID _T("TVS_MLeaderID")
#define MLeaderFormat _T("TVS_MLeaderFormat")
class MLeaderSettings 
{
public:
	MLeaderSettings(void){
		instructionMessage=L"\
[L]-������ �3/�\r\n\
[V]-�������� �/�\r\n\
[D]-������ ��\r\n\
[P]-������ �������� P\r\n\
[BN]-��� ����� P\r\n\
[N]-��� ����\r\n\
[�������� ��������]-��������\r\n\ ��������� (��� ������)\r\n\
";
		pipeLeader =L"[D]";
		blockLeader = L"[���]-[������]";
	
	};

	CString & getFormatForEntity(const AcDbObjectId &id) {

		AcDbObjectPointer<AcDbEntity>pEnt(id, AcDb::kForRead);

		AcDbBlockReference * br;
		if ((br = AcDbBlockReference::cast(pEnt)) != NULL)
			return blockLeader;

		TVS_Entity * ent;
		if ((ent = TVS_Entity::cast(pEnt)) != NULL)
			return pipeLeader;

		return CString(L"");
	}
	virtual ~MLeaderSettings(void){};
	CString  instructionMessage;
	CString  pipeLeader;
	CString  blockLeader;
};