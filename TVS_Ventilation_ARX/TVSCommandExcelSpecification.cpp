#include "stdafx.h"
#include "TVSCommandExcelSpecification.h"
#include "TVSPropertySpec.h"
#include "TVSSpecTable.h"

TVSCommandExcelSpecification::TVSCommandExcelSpecification()
{
}

TVSCommandExcelSpecification::~TVSCommandExcelSpecification()
{
}

void TVSCommandExcelSpecification::execute(void)
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

	TVSPropertySpec spec;
	spec.processSetOfObjects(sset);
	spec.sort();
	TVSSpecTable table;
	table.loadColumnsFromSettings();
	table.buildDataFromSpec(spec);
	table.toExcel();
}
