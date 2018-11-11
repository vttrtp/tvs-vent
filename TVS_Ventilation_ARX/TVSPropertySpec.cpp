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
	
	if(a.tvsPropery.isTvsEnt!= b.tvsPropery.isTvsEnt)	return (a.tvsPropery.isTvsEnt < b.tvsPropery.isTvsEnt);

	if (a.tvsPropery.position.Compare(b.tvsPropery.position) != 0)	return (a.tvsPropery.position.Compare(b.tvsPropery.position)> 0);
	if (a.tvsPropery.name.Compare(b.tvsPropery.name)!= 0) return (a.tvsPropery.name.Compare(b.tvsPropery.name)> 0);
 	if (a.tvsPropery.type.Compare(b.tvsPropery.type) != 0) return (a.tvsPropery.type.Compare(b.tvsPropery.type)> 0);
 	if (a.tvsPropery.size.Compare(b.tvsPropery.size) != 0) return (a.tvsPropery.size.Compare(b.tvsPropery.size)> 0);
	if (a.tvsPropery.article.Compare(b.tvsPropery.article) != 0) return (a.tvsPropery.article.Compare(b.tvsPropery.article)> 0);
	if (a.tvsPropery.manufacturer.Compare(b.tvsPropery.manufacturer) != 0) return (a.tvsPropery.manufacturer.Compare(b.tvsPropery.manufacturer)> 0);
	if (a.tvsPropery.units.Compare(b.tvsPropery.units) != 0) return (a.tvsPropery.units.Compare(b.tvsPropery.units)> 0);
	if (a.tvsPropery.mass != b.tvsPropery.mass) return (a.tvsPropery.mass > b.tvsPropery.mass);
	if (a.tvsPropery.note.Compare(b.tvsPropery.note)!= 0) return (a.tvsPropery.note.Compare(b.tvsPropery.note)> 0);
	return false;
}

void TVSPropertySpec::sort()
{
	rows.sort([](const TVSPropertySpecRow &a, const TVSPropertySpecRow &b) {
		return !compareRows(a, b);
	});
}
