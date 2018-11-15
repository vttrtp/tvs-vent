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
	static TVSPropertyController* get();


	bool getStringValueOfAnyPropertyByName(const AcDbObjectId &objectId, const CString &prop, CString &val);
	//ProcessProperty
	virtual bool registerApp();
	bool setProperty(const AcDbObjectId &objectId, const TVSProperty &tvsProperty);
	bool checkProperty(const AcDbObjectId &objectId);
	bool addProperty(const AcDbObjectId &objectId);
	bool getProperty(const AcDbObjectId &objectId, TVSProperty &tvsProperty);
	bool removeProperty(const AcDbObjectId &objectId);

	//properties:
	//position
	bool setPosition(const AcDbObjectId &objectId, const CString &val);
	bool getPosition(const AcDbObjectId &objectId, CString &val);

	//name
	bool setName(const AcDbObjectId &objectId, const CString &val);
	bool getName(const AcDbObjectId &objectId, CString &val);

	//type
	bool setType(const AcDbObjectId &objectId, const CString &val);
	bool getType(const AcDbObjectId &objectId, CString &val);

	//size
	bool setSize(const AcDbObjectId &objectId, const CString &val);
	bool getSize(const AcDbObjectId &objectId, CString &val);

	//article
	bool setArticle(const AcDbObjectId &objectId, const CString &val);
	bool getArticle(const AcDbObjectId &objectId, CString &val);

	//manufacturer
	bool setManufacturer(const AcDbObjectId &objectId, const CString &val);
	bool getManufaturer(const AcDbObjectId &objectId, CString &val);

	//units
	bool setUnits(const AcDbObjectId &objectId, const CString &val);
	bool getUnits(const AcDbObjectId &objectId, CString &val);

	//count
	bool setCount(const AcDbObjectId &objectId, const double &val);
	bool getCount(const AcDbObjectId &objectId, double &val);

	//mass
	bool setMass(const AcDbObjectId &objectId, const double &val);
	bool getMass(const AcDbObjectId &objectId, double &val);

	//note
	bool setNote(const AcDbObjectId &objectId, const CString &val);
	bool getNote(const AcDbObjectId &objectId, CString &val);


};

