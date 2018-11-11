#include "stdafx.h"
#include "TVSCommandLeadRecalculate.h"
#include "MleaderController.h"

TVSCommandLeadRecalculate::TVSCommandLeadRecalculate()
{
}


TVSCommandLeadRecalculate::~TVSCommandLeadRecalculate()
{
}

void TVSCommandLeadRecalculate::execute(void)
{
	ads_name sset;

	if (acedSSGet(_T(""), NULL, NULL, NULL, sset) != RTNORM)
		return;

	Int32 len;
	ads_name  eName;
	AcDbObjectId mLeaderId;
	AcDbObjectId objectId;
	MleaderController mlctrl;
	acedSSLength(sset, &len);
	for (Int32 i = 0; i < len; i++)
	{
		if (NULL != (acedSSName(sset, i, eName)))
		{
			
			acdbGetObjectId(mLeaderId, eName);
			mlctrl.recalculateMleader(mLeaderId);
			acutPrintf(L"objId\%ld\n", mLeaderId);
		}
	}
}
