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

bool TVSPropertyController::getProperty(const AcDbObjectId &objectId, TVSProperty &tvsProperty)
{

	resbuf *rb;
	int i = 0;
	if (!getXDataResbuf(objectId, CTVSProperty, rb)) return false;
	for (resbuf *rbnext = rb; rbnext != NULL; rbnext = rbnext->rbnext)
	{
		acutPrintf(L"position %d\n", i++);
		if (rbnext->restype == AcDb::kDxfXdAsciiString)
		{
			//value = rbnext->resval.rstring;
			acutRelRb(rb);
			return true;
		}
	}
	acutRelRb(rb);
	return false;
	
	return true;
}

bool TVSPropertyController::removeProperty(const AcDbObjectId &objectId)
{
	return true;
}

bool TVSPropertyController::setPosition(const AcDbObjectId &objectId, const CString &val)
{
	setSubXString(objectId, CTVSProperty, CTVSProperty_Number_position, val);
}

bool TVSPropertyController::getPosition(const AcDbObjectId &objectId, CString val)
{
	getSubXString(objectId, CTVSProperty, CTVSProperty_Number_position, val);
}

bool TVSPropertyController::setName(const AcDbObjectId &objectId, const CString &val)
{

}

bool TVSPropertyController::getName(const AcDbObjectId &objectId, CString val)
{

}

bool TVSPropertyController::setType(const AcDbObjectId &objectId, const CString &val)
{

}

bool TVSPropertyController::getType(const AcDbObjectId &objectId, CString val)
{

}

bool TVSPropertyController::setSize(const AcDbObjectId &objectId, const CString &val)
{

}

bool TVSPropertyController::getSize(const AcDbObjectId &objectId, CString val)
{

}

bool TVSPropertyController::setArticle(const AcDbObjectId &objectId, const CString &val)
{

}

bool TVSPropertyController::getArticle(const AcDbObjectId &objectId, CString val)
{

}

bool TVSPropertyController::setManufacturer(const AcDbObjectId &objectId, const CString &val)
{

}

bool TVSPropertyController::getManufaturer(const AcDbObjectId &objectId, CString val)
{

}

bool TVSPropertyController::setUnits(const AcDbObjectId &objectId, const CString &val)
{

}

bool TVSPropertyController::getUnits(const AcDbObjectId &objectId, CString val)
{

}

bool TVSPropertyController::setCount(const AcDbObjectId &objectId, const double &val)
{

}

bool TVSPropertyController::getCount(const AcDbObjectId &objectId, double val)
{

}

bool TVSPropertyController::setMass(const AcDbObjectId &objectId, const double &val)
{

}

bool TVSPropertyController::getMass(const AcDbObjectId &objectId, double val)
{

}

bool TVSPropertyController::setNote(const AcDbObjectId &objectId, const CString &val)
{

}

bool TVSPropertyController::getNote(const AcDbObjectId &objectId, CString val)
{

}
