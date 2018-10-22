#include "stdafx.h"
#include "TVSPropertyController.h"


TVSPropertyController::TVSPropertyController()
{
}


TVSPropertyController::~TVSPropertyController()
{
}

bool TVSPropertyController::registerApp()
{
	acdbRegApp(CTVSProperty);
	return true;
}

bool TVSPropertyController::setProperty(const AcDbObjectId &objectId, const TVSProperty &tvsProperty)
{
	acdbRegApp(CTVSProperty);
	resbuf *rb = acutBuildList(AcDb::kDxfRegAppName, CTVSProperty, 

		AcDb::kDxfXdInteger16, CTVSProperty_Number_position,
		AcDb::kDxfXdAsciiString, tvsProperty.position.GetString(),

		AcDb::kDxfXdInteger16, CTVSProperty_Number_name,
 		AcDb::kDxfXdAsciiString, tvsProperty.name.GetString(),

		AcDb::kDxfXdInteger16, CTVSProperty_Number_type,
 		AcDb::kDxfXdAsciiString, tvsProperty.type.GetString(),

		AcDb::kDxfXdInteger16, CTVSProperty_Number_size,
 		AcDb::kDxfXdAsciiString, tvsProperty.size.GetString(),

		AcDb::kDxfXdInteger16, CTVSProperty_Number_article,
 		AcDb::kDxfXdAsciiString, tvsProperty.article.GetString(),

		AcDb::kDxfXdInteger16, CTVSProperty_Number_manufacturer,
 		AcDb::kDxfXdAsciiString, tvsProperty.manufacturer.GetString(),

		AcDb::kDxfXdInteger16, CTVSProperty_Number_units,
 		AcDb::kDxfXdAsciiString, tvsProperty.units.GetString(),

		AcDb::kDxfXdInteger16, CTVSProperty_Number_count,
 		AcDb::kDxfXdReal, tvsProperty.count,

		AcDb::kDxfXdInteger16, CTVSProperty_Number_mass,
 		AcDb::kDxfXdReal, tvsProperty.mass,

		AcDb::kDxfXdInteger16, CTVSProperty_Number_note,
 		AcDb::kDxfXdAsciiString, tvsProperty.note.GetString(),

		AcDb::kDwgNull);

	bool ret = setXdataBuf(objectId,  rb);
	acutRelRb(rb);


	return ret;
}

bool TVSPropertyController::checkProperty(const AcDbObjectId &objectId) {
	{
		AcDbObjectPointer<AcDbObject> pObj(objectId, AcDb::kForRead);
		if (pObj.openStatus() != Acad::eOk) return false;

		TVS_Entity * ent;
		if ((ent = TVS_Entity::cast(pObj)) != NULL) {
			return true;
		}
	}

	return checkXdataApp(objectId, CTVSProperty);
}

bool TVSPropertyController::addProperty(const AcDbObjectId &objectId) {
	if (!checkProperty(objectId))
	{
		return addXdataApp(objectId, CTVSProperty);
	}
	else {
		return false;
	}
}

bool TVSPropertyController:: getProperty(const AcDbObjectId &objectId, TVSProperty &tvsProperty)
{
	getPosition(objectId, tvsProperty.position);
	getName(objectId, tvsProperty.name);
	getType(objectId, tvsProperty.type);
	getSize(objectId, tvsProperty.size);
	getArticle(objectId, tvsProperty.article);
	getManufaturer(objectId, tvsProperty.manufacturer);
	getMass(objectId, tvsProperty.mass);
	getUnits(objectId, tvsProperty.units);
	getCount(objectId, tvsProperty.count);
	getNote(objectId, tvsProperty.note);
	return true;
}

bool TVSPropertyController::removeProperty(const AcDbObjectId &objectId)
{
	return removeXdata(objectId, CTVSProperty);
}

bool TVSPropertyController::setPosition(const AcDbObjectId &objectId, const CString &val)
{
	return setSubXString(objectId, CTVSProperty, CTVSProperty_Number_position, val);
}

bool TVSPropertyController::getPosition(const AcDbObjectId &objectId, CString &val)
{
	return  getSubXString(objectId, CTVSProperty, CTVSProperty_Number_position, val);
}

bool TVSPropertyController::setName(const AcDbObjectId &objectId, const CString &val)
{
	AcDbObjectPointer<AcDbObject> pObj(objectId, AcDb::kForWrite);
	if (pObj.openStatus() != Acad::eOk) return false;

	TVS_Entity * ent;
	if ((ent = TVS_Entity::cast(pObj)) != NULL) {
		return true;
	}
	else {
		return setSubXString(pObj, CTVSProperty, CTVSProperty_Number_name, val);
	}
}

bool TVSPropertyController::getName(const AcDbObjectId &objectId, CString &val)
{
	AcDbObjectPointer<AcDbObject> pObj(objectId, AcDb::kForRead);
	if (pObj.openStatus() != Acad::eOk) return false;

	TVS_Entity * ent;
	if ((ent = TVS_Entity::cast(pObj)) != NULL) {
		ent->getName(val);
		return true;
	}
	else {
		return getSubXString(pObj, CTVSProperty, CTVSProperty_Number_name, val);
	}
}

bool TVSPropertyController::setType(const AcDbObjectId &objectId, const CString &val)
{
	return setSubXString(objectId, CTVSProperty, CTVSProperty_Number_type, val);
}

bool TVSPropertyController::getType(const AcDbObjectId &objectId, CString &val)
{
	return getSubXString(objectId, CTVSProperty, CTVSProperty_Number_type, val);
}

bool TVSPropertyController::setSize(const AcDbObjectId &objectId, const CString &val)
{
	AcDbObjectPointer<AcDbObject> pObj(objectId, AcDb::kForWrite);
	if (pObj.openStatus() != Acad::eOk) return false;

	TVS_Entity * ent;
	if ((ent = TVS_Entity::cast(pObj)) != NULL) {
		return true;
	}
	else {
		return setSubXString(pObj, CTVSProperty, CTVSProperty_Number_size, val);
	}
}

bool TVSPropertyController::getSize(const AcDbObjectId &objectId, CString &val)
{
	AcDbObjectPointer<AcDbObject> pObj(objectId, AcDb::kForWrite);
	if (pObj.openStatus() != Acad::eOk) return false;

	TVS_Entity * ent;
	if ((ent = TVS_Entity::cast(pObj)) != NULL) {
		ent->getSizeString(val);
		return	true;
	}
	else {
		return getSubXString(pObj, CTVSProperty, CTVSProperty_Number_size, val);
	}
}

bool TVSPropertyController::setArticle(const AcDbObjectId &objectId, const CString &val)
{
	return setSubXString(objectId, CTVSProperty, CTVSProperty_Number_article, val);
}

bool TVSPropertyController::getArticle(const AcDbObjectId &objectId, CString &val)
{
	return getSubXString(objectId, CTVSProperty, CTVSProperty_Number_article, val);
}

bool TVSPropertyController::setManufacturer(const AcDbObjectId &objectId, const CString &val)
{
	return setSubXString(objectId, CTVSProperty, CTVSProperty_Number_manufacturer, val);
}

bool TVSPropertyController::getManufaturer(const AcDbObjectId &objectId, CString &val)
{
	return getSubXString(objectId, CTVSProperty, CTVSProperty_Number_manufacturer, val);
}

bool TVSPropertyController::setUnits(const AcDbObjectId &objectId, const CString &val)
{
	AcDbObjectPointer<AcDbObject> pObj(objectId, AcDb::kForWrite);
	if (pObj.openStatus() != Acad::eOk) return false;

	TVS_Entity * ent;
	if ((ent = TVS_Entity::cast(pObj)) != NULL) {
		return true;
	}
	else {
		return setSubXString(pObj, CTVSProperty, CTVSProperty_Number_units, val);
	}
	
}

bool TVSPropertyController::getUnits(const AcDbObjectId &objectId, CString &val)
{
	AcDbObjectPointer<AcDbObject> pObj(objectId, AcDb::kForWrite);
	if (pObj.openStatus() != Acad::eOk) return false;

	TVS_Entity * ent;
	if ((ent = TVS_Entity::cast(pObj)) != NULL) {
		ent->getCountUnit(val);
		return true;
	}
	else {
		return getSubXString(pObj, CTVSProperty, CTVSProperty_Number_units, val);
	}
	
}

bool TVSPropertyController::setCount(const AcDbObjectId &objectId, const double &val)
{
	AcDbObjectPointer<AcDbObject> pObj(objectId, AcDb::kForWrite);
	if (pObj.openStatus() != Acad::eOk) return false;

	TVS_Entity * ent;
	if ((ent = TVS_Entity::cast(pObj)) != NULL) {
		return true;
	}
	else {
		return setSubXReal(pObj, CTVSProperty, CTVSProperty_Number_count, val);
	}
}

bool TVSPropertyController::getCount(const AcDbObjectId &objectId, double &val)
{
	AcDbObjectPointer<AcDbObject> pObj(objectId, AcDb::kForWrite);
	if (pObj.openStatus() != Acad::eOk) return false;

	TVS_Entity * ent;
	if ((ent = TVS_Entity::cast(pObj)) != NULL) {
		ent->getCount(val);
		return true;
	}
	else {
		return getSubXReal(pObj, CTVSProperty, CTVSProperty_Number_count, val);
	}
}

bool TVSPropertyController::setMass(const AcDbObjectId &objectId, const double &val)
{
	return setSubXReal(objectId, CTVSProperty, CTVSProperty_Number_mass, val);
}

bool TVSPropertyController::getMass(const AcDbObjectId &objectId, double &val)
{
	return getSubXReal(objectId, CTVSProperty, CTVSProperty_Number_mass, val);
	
}

bool TVSPropertyController::setNote(const AcDbObjectId &objectId, const CString &val)
{
	return setSubXString(objectId, CTVSProperty, CTVSProperty_Number_note, val);
}

bool TVSPropertyController::getNote(const AcDbObjectId &objectId, CString &val)
{
	return getSubXString(objectId, CTVSProperty, CTVSProperty_Number_note, val);
	
}
