#pragma once
#include "TVSProperty.h"
#include "xRecordXdataHelper.h"
#include "TVSPropertySettings.h"

class TVSPropertyController :
	public XRecordXdataHelper
{
public:
	TVSPropertyController();
	virtual ~TVSPropertyController();

	//ProcessProperty
	virtual bool registerApp();
	bool setProperty(const AcDbObjectId &objectId, const TVSProperty &tvsProperty);
	bool getProperty(const AcDbObjectId &objectId, TVSProperty &tvsProperty);
	bool removeProperty(const AcDbObjectId &objectId);

};

