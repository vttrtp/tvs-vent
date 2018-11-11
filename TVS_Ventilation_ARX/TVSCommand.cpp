#include "stdafx.h"
#include "TVSCommand.h"


TVSCommand::TVSCommand(void)
{
}


TVSCommand::~TVSCommand(void)
{
}

void TVSCommand::processId(const AcDbObjectId &objId)
{

}

void TVSCommand::execute(void)
{
	ads_name sset;

	if (acedSSGet(_T(""), NULL, NULL, NULL, sset) != RTNORM)
		return;

	Int32 len;
	ads_name  eName;
	AcDbObjectId objectId;
	acedSSLength(sset, &len);
	for (Int32 i = 0; i < len; i++)
	{
		if (NULL != (acedSSName(sset, i, eName)))
		{

			if (acdbGetObjectId(objectId, eName) == Acad::eOk) {
				processId(objectId);
			}
		}
	}
}
