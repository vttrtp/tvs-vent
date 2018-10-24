#include "stdafx.h"
#include "TVSCommandPropertyManager.h"
#include "MleaderController.h"
#include "TVSPropertySpec.h"
#include "DLGTVSPropertyManager.h"

TVSCommandPropertyManager::TVSCommandPropertyManager()
{
}


TVSCommandPropertyManager::~TVSCommandPropertyManager()
{
}

void TVSCommandPropertyManager::execute(void)
{
	ads_name sset;

	if (acedSSGet(_T(""), NULL, NULL, NULL, sset) != RTNORM)
		return;
	TVSPropertySpec spec;
	spec.processSetOfObjects(sset);
	spec.sort();
	acutPrintf(L"rows %d", spec.rows.size());
	if (spec.rows.size() > 0) {
		DLGTVSPropertyManager dg;
		dg.propertySpec = spec;
		dg.DoModal();
	}
}
