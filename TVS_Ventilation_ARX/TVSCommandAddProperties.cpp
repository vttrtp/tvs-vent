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
