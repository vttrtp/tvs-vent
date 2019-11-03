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
	TVSSpecTable table;
	acedInitGet(RSG_NONULL, _T("Настройки Н н Y y"));
	int status = 0;

	while (status != RTNORM) {
		status = acedGetPoint(NULL, _T("\nУкажите точку вставки спецификации или [Настройки]:"), pt1);
		switch (status)
		{
		case RTCAN:
			return;
			break;
		case RTKWORD:
			table.showPropsDlg();
			break;
		}
	}

	TVSPropertySpec spec;
	spec.processSetOfObjects(sset);
	spec.sort();
	
	table.loadColumnsFromSettings();
	table.buildDataFromSpec(spec);
	table.toSimpleTable(asPnt3d(pt1));
}

