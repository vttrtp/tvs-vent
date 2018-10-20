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

// acdbRegApp(L"Position");
// resbuf *rb = acutBuildList(AcDb::kDxfRegAppName, L"Position",
// 	AcDb::kDxfXdAsciiString, tvsProperty.position.GetString(),
// 	AcDb::kDwgNull);
// bool ret = setXdataBuf(objectId, rb);
//  	acutRelRb(rb);
// 
// 	acdbRegApp(L"name");
// 	 rb = acutBuildList(AcDb::kDxfRegAppName, L"name",
// 		AcDb::kDxfXdAsciiString, tvsProperty.name.GetString(),
// 		AcDb::kDwgNull);
// 	setXdataBuf(objectId, rb);
// 	acutRelRb(rb);
// 
// 
// 	acdbRegApp(L"type");
// 	rb = acutBuildList(AcDb::kDxfRegAppName, L"type",
// 		AcDb::kDxfXdAsciiString, tvsProperty.type.GetString(),
// 		AcDb::kDwgNull);
// 	setXdataBuf(objectId, rb);
// 	acutRelRb(rb);
// 
// 	acdbRegApp(L"size");
// 	rb = acutBuildList(AcDb::kDxfRegAppName, L"size",
// 		AcDb::kDxfXdAsciiString, tvsProperty.size.GetString(),
// 		AcDb::kDwgNull);
// 	setXdataBuf(objectId, rb);
// 	acutRelRb(rb);
// 
// 	acdbRegApp(L"article");
// 	rb = acutBuildList(AcDb::kDxfRegAppName, L"article",
// 		AcDb::kDxfXdAsciiString, tvsProperty.article.GetString(),
// 		AcDb::kDwgNull);
// 	setXdataBuf(objectId, rb);
// 	acutRelRb(rb);
// 
// 	acdbRegApp(L"manufacturer");
// 	rb = acutBuildList(AcDb::kDxfRegAppName, L"manufacturer",
// 		AcDb::kDxfXdAsciiString, tvsProperty.manufacturer.GetString(),
// 		AcDb::kDwgNull);
// 	setXdataBuf(objectId, rb);
// 	acutRelRb(rb);
// 
// 	acdbRegApp(L"units");
// 	rb = acutBuildList(AcDb::kDxfRegAppName, L"units",
// 		AcDb::kDxfXdAsciiString, tvsProperty.units.GetString(),
// 		AcDb::kDwgNull);
// 	setXdataBuf(objectId, rb);
// 	acutRelRb(rb);
// 
// 	acdbRegApp(L"count");
// 	rb = acutBuildList(AcDb::kDxfRegAppName, L"count",
// 		AcDb::kDxfXdReal, tvsProperty.count,
// 		AcDb::kDwgNull);
// 	setXdataBuf(objectId, rb);
// 	acutRelRb(rb);
// 
// 	acdbRegApp(L"mass");
// 	rb = acutBuildList(AcDb::kDxfRegAppName, L"mass",
// 		AcDb::kDxfXdReal, tvsProperty.mass,
// 		AcDb::kDwgNull);
// 	setXdataBuf(objectId, rb);
// 	acutRelRb(rb);
// 
// 	acdbRegApp(L"note");
// 	rb = acutBuildList(AcDb::kDxfRegAppName, L"note",
// 		AcDb::kDxfXdAsciiString, tvsProperty.note,
// 		AcDb::kDwgNull);
// 	setXdataBuf(objectId, rb);
	
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
