#include "stdafx.h"
#include "TVSCommandAttributesToProperties.h"
#include "TVSAttrtibutesController.h"

TVSCommandAttributesToProperties::TVSCommandAttributesToProperties()
{
}


TVSCommandAttributesToProperties::~TVSCommandAttributesToProperties()
{
}

void TVSCommandAttributesToProperties::execute(void)
{
	ads_name sset;

	acedSSGet(L"X", NULL, NULL, NULL, sset);

	Int32 len;
	ads_name  eName;
	AcDbObjectId objectId;

	acedSSLength(sset, &len);
	for (Int32 i = 0; i < len; i++)
	{
		if (NULL != (acedSSName(sset, i, eName)))
		{
			if (acdbGetObjectId(objectId, eName) == Acad::eOk) {
				TVSAttrtibutesController ctrl;
				ctrl.convertAttributesToProperties(objectId);
			}
		}
	}

	for (Int32 i = 0; i < len; i++)
	{
		if (NULL != (acedSSName(sset, i, eName)))
		{
			if (acdbGetObjectId(objectId, eName) == Acad::eOk) {
				TVSAttrtibutesController ctrl;
				ctrl.removeAttributes(objectId);
			}
		}
	}
}
