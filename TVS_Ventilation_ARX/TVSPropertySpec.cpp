#include "stdafx.h"
#include "TVSPropertySpec.h"
#include "TVSController.h"

TVSPropertySpec::TVSPropertySpec()
{
}


TVSPropertySpec::~TVSPropertySpec()
{
}

bool TVSPropertySpec::processSetOfObjects(ads_name &sset)
{
	Adesk::Int32 len;
	acedSSLength(sset, &len);

	ads_name eName;
	AcDbObjectId objId;

	for (long i = 0; i < len; i++)
	{
		if (NULL != (acedSSName(sset, i, eName)))
		{
			acdbGetObjectId(objId, eName);
			if (objId != AcDbObjectId::kNull)
			{
				addObject(objId);
			}
		}
	}
	return true;
}

void TVSPropertySpec::addObject(AcDbObjectId &objId)
{
	TVSProperty props;
	if (TVSController::get()->tvsPropertyController.getProperty(objId, props)) {
		addRow(props, objId);
	}
}



void TVSPropertySpec::addRow(const TVSProperty &props, const AcDbObjectId &objId)
{
	for (auto &row : rows)
	{
		if (row.tvsPropery.position == props.position &&
			row.tvsPropery.name == props.name &&
			row.tvsPropery.type == props.type &&
			row.tvsPropery.size == props.size  &&
			row.tvsPropery.article == props.article &&
			row.tvsPropery.manufacturer == props.manufacturer &&
			row.tvsPropery.units == props.units &&
			row.tvsPropery.mass == props.mass &&
			row.tvsPropery.note == props.note 
			)
		{
			row.tvsPropery.count += props.count;
			row.objectIds.push_back(objId);
			return;
		}
	}
	TVSPropertySpecRow row(props, objId);
	rows.push_back(row);
}

bool compareRows(const TVSPropertySpecRow &a, const TVSPropertySpecRow &b)
{
	if (a.tvsPropery.position < b.tvsPropery.position)	return true;
	if (a.tvsPropery.name < b.tvsPropery.name) return true;
	if (a.tvsPropery.type < b.tvsPropery.type) return true;
	if (a.tvsPropery.size < b.tvsPropery.size) return true;
	if (a.tvsPropery.article < b.tvsPropery.article) return true;
	if (a.tvsPropery.manufacturer < b.tvsPropery.manufacturer) return true;
	if (a.tvsPropery.units < b.tvsPropery.units) return true;
	if (a.tvsPropery.mass < b.tvsPropery.mass) return true;
	if (a.tvsPropery.note < b.tvsPropery.note) return true;
	return false;
}

void TVSPropertySpec::sort()
{
	rows.sort([](const TVSPropertySpecRow &a, const TVSPropertySpecRow &b) {
		return compareRows(a, b);
	});
}
