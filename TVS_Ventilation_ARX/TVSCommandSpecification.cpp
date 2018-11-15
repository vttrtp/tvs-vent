#include "stdafx.h"
#include "TVSCommandSpecification.h"
#include "TVSPropertySpec.h"
#include "TVSSpecTable.h"
TVSCommandSpecification::TVSCommandSpecification()
{
}

TVSCommandSpecification::~TVSCommandSpecification()
{
}

void TVSCommandSpecification::execute(void)
{
	ads_name sset;
	if (acedSSGet(_T(""), NULL, NULL, NULL, sset) != RTNORM)
		return;

	Int32 len;
	acedSSLength(sset, &len);
	if (len == 0)
	{
		return;
	}

	ads_point pt1;
	if (acedGetPoint(NULL, _T("\nУкажите точку вставки спецификации:"), pt1) != RTNORM)
		return;

	TVSPropertySpec spec;
	spec.processSetOfObjects(sset);
	spec.sort();
	TVSSpecTable table;
	table.loadColumnsFromSettings();
	table.buildDataFromSpec(spec);
	table.toSimpleTable(asPnt3d(pt1));
}
