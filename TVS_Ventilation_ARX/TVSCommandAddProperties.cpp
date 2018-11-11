#include "stdafx.h"
#include "TVSCommandAddProperties.h"
#include "TVSController.h"

TVSCommandAddProperties::TVSCommandAddProperties()
{
}


TVSCommandAddProperties::~TVSCommandAddProperties()
{
}

void TVSCommandAddProperties::processId(const AcDbObjectId &objId)
{
	acutPrintf(L"hello");
	TVSController::get()->tvsPropertyController.addProperty(objId);
}

// void TVSCommandAddProperties::execute(void)
// {
// 	ads_name sset;
// 
// 	if (acedSSGet(_T(""), NULL, NULL, NULL, sset) != RTNORM)
// 		return;
// 
// 	Int32 len;
// 	ads_name  eName;
// 	AcDbObjectId mLeaderId;
// 	AcDbObjectId objectId;
// 	MleaderController mlctrl;
// 	acedSSLength(sset, &len);
// 	for (Int32 i = 0; i < len; i++)
// 	{
// 		if (NULL != (acedSSName(sset, i, eName)))
// 		{
// 
// 			acdbGetObjectId(mLeaderId, eName);
// 			mlctrl.recalculateMleader(mLeaderId);
// 			acutPrintf(L"objId\%ld\n", mLeaderId);
// 		}
// 	}
// }
