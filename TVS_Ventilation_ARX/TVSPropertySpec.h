#pragma once
#include "TVSProperty.h"
#include "TVSPropertySpecRow.h"

typedef list<TVSPropertySpecRow> TVSPropertySpecRowList;
class TVSPropertySpec
{
public:
	TVSPropertySpec();
	virtual ~TVSPropertySpec();
	TVSPropertySpecRowList rows;
	bool processSetOfObjects(ads_name &sset);
	void addObject(AcDbObjectId &objId);
	void sort();
private:
	void addRow(const TVSProperty &props, const AcDbObjectId &objId);
	
};
