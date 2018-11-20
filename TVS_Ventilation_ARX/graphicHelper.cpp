#include "stdafx.h"
#include "graphicHelper.h"

void graphicHelper::drawText(AcGePoint3d cent, const ACHAR * pAchar)
{
	AcDbDatabase *db = acdbHostApplicationServices()->workingDatabase();

	AcDbObjectId tId = db->textstyle();
	///
	AcDbText *text1 = new AcDbText(cent, pAchar, tId, 250, 0);

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable,
		AcDb::kForRead);

	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId retId = AcDbObjectId::kNull;
	pBlockTableRecord->appendAcDbEntity(retId, text1);
	pBlockTableRecord->close();
	text1->close();
	//
}

void graphicHelper::drawLine(AcGePoint3d start, AcGePoint3d end)
{
	AcDbDatabase *db = acdbHostApplicationServices()->workingDatabase();

	AcDbObjectId tId = db->textstyle();
	///
	AcDbLine *pEnt = new AcDbLine(start, end);

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable,
		AcDb::kForRead);

	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite);
	pBlockTable->close();
	pEnt->setLineWeight(AcDb::kLnWt015);
	AcDbObjectId retId = AcDbObjectId::kNull;
	pBlockTableRecord->appendAcDbEntity(retId, pEnt);
	pBlockTableRecord->close();
	pEnt->close();
	//
}
