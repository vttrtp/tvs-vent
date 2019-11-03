#pragma once
#include "arxHeaders.h"
#include "TVS_Entity.h"
#define MLeaderID _T("TVS_MLeaderID")
#define MLeaderFormat _T("TVS_MLeaderFormat")
class MLeaderSettings
{
public:
	MLeaderSettings(void) {
		instructionMessage = L"\
[L]-Расход м3/ч\r\n\
[V]-Скорость м/с\r\n\
[D]-Размер мм\r\n\
[P]-Потери давления P\r\n\
[BN]-Имя блока P\r\n\
[N]-Имя слоя\r\n\
[Название Атрибута]-Значение\r\n\ Аттрибута (Для блоков)\r\n\
";
		pipeLeader = L"[D]";
		blockLeader = L"[Тип]-[Размер]";

	};

	CString & getFormatForEntity(const AcDbObjectId &id) {

		AcDbObjectPointer<AcDbEntity>pEnt(id, AcDb::kForRead);
		TVS_Entity * ent;
		if ((ent = TVS_Entity::cast(pEnt)) != NULL)
			return pipeLeader;

		return blockLeader;
	}
	virtual ~MLeaderSettings(void) {};
	CString  instructionMessage;
	CString  pipeLeader;
	CString  blockLeader;
};
