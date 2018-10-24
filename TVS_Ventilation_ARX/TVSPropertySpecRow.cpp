#include "stdafx.h"
#include "TVSPropertySpecRow.h"


TVSPropertySpecRow::TVSPropertySpecRow()
{
}


TVSPropertySpecRow::TVSPropertySpecRow(const TVSProperty &props, const AcDbObjectId &objId)
{
	tvsPropery = props;
	objectIds.push_back(objId);
}

TVSPropertySpecRow::~TVSPropertySpecRow()
{
}
