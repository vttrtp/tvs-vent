#include "stdafx.h"
#include "TVS_Connector.h"
#include <iostream>
using namespace std;
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
	cout<<"write conId: "<<connectionID<<endl;
}

void TVS_Connector::read(AcDbDwgFiler *pFiler, const int version)
{
	
		pFiler->readItem(&cTypeCurrent);
		pFiler->readItem(&cTypeAnother);
		pFiler->readItem(&point);
		AcDbHardPointerId qwe;
		pFiler->readItem(&qwe);
		connectionID = qwe;
		cout<<"read conId: "<<connectionID<<endl;

}



