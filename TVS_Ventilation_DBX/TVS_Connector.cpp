#include "stdafx.h"
#include "TVS_Connector.h"


TVS_Connector::TVS_Connector(void)
{
}


TVS_Connector::~TVS_Connector(void)
{
}

void TVS_Connector::write(AcDbDwgFiler *pFiler) const
{	
	Acad::ErrorStatus st1 = pFiler->writeItem(cTypeCurrent);
	Acad::ErrorStatus st2 = pFiler->writeItem(cTypeAnother);
	Acad::ErrorStatus st3 = pFiler->writeItem(point);
	Acad::ErrorStatus st4 = pFiler->writeItem((AcDbHardPointerId)connectionID);
}

void TVS_Connector::read(AcDbDwgFiler *pFiler, const int version)
{
	if (version>=30)
	{
		pFiler->readItem(&cTypeCurrent);
		pFiler->readItem(&cTypeAnother);
		pFiler->readItem(&point);
		pFiler->readItem(&(AcDbHardPointerId)connectionID);
	}
}



