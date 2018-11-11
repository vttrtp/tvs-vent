#include "stdafx.h"
#include "TVSAttrtibutesController.h"
#include "Settings.h"
#include "TVSController.h"

TVSAttrtibutesController::TVSAttrtibutesController()
{
}


TVSAttrtibutesController::~TVSAttrtibutesController()
{
}

bool TVSAttrtibutesController::CheckAtt(const ACHAR* pName,const ACHAR* tag)
{
	AcDbDatabase *pCurDb;
	AcDbBlockTable* pBlkTbl;
	AcDbBlockTableRecord* pBlkRec;
	AcDbObjectId attId;
	Acad::ErrorStatus es;

	AcDbAttributeDefinition* pAttDef;

	pCurDb = acdbHostApplicationServices()->workingDatabase();
	es = pCurDb->getBlockTable(pBlkTbl, AcDb::kForRead);
	if (!pBlkTbl->has(pName))
	{
		acutPrintf(L"\nBlock definition TEST does not exist");
		pBlkTbl->close();
		return false;
	}
	es = pBlkTbl->getAt(pName, pBlkRec, AcDb::kForWrite);
	// create a AttributeDefinition
	AcDbBlockTableRecordIterator *pIterBTR = NULL;
	if ((es = pBlkRec->newIterator(pIterBTR)) == Acad::eOk) {
		for (; !pIterBTR->done(); pIterBTR->step()) {
			AcDbObjectId objSubId;
			if ((es = pIterBTR->getEntityId(objSubId)) == Acad::eOk) {
				AcDbObjectPointer<AcDbEntity> pSubEnt(objSubId, AcDb::kForRead);
				if ((es = pSubEnt.openStatus()) == Acad::eOk) {
					//
					// Здесь можно работать с примитивами в блоке
					//
					//buf=pSubEnt->isA()->name();
					//		 											acutPrintf(_T("\nПримитив: %s"),LPCTSTR(pSubEnt->isA()->name()));
					AcDbAttributeDefinition *pAttdef = AcDbAttributeDefinition::cast(pSubEnt.object());

					if (pAttdef) {
						// Если это определение атрибута сделаем отдельную обработку
						if (wcscmp(tag, pAttdef->tagConst()) == 0) {
							//	pAttDef->close();
							pBlkRec->close();
							pBlkTbl->close();
							return false;
						}
					}
				}
				else {
					acutPrintf(_T("\nНе удалось открыть примитив в блоке! Ошибка: %s",
						LPCTSTR(acadErrorStatusText(es))));
				}
			}
			else {
				acutPrintf(_T("\nНе удалось получить AcDbObjectId примитва в блоке! Ошибка: %s",
					LPCTSTR(acadErrorStatusText(es))));
			}
		}
	}
	else {
		acutPrintf(_T("\nНе удалось создать итератор для записи таблицы блоков! Ошибка: %s", LPCTSTR(acadErrorStatusText(es))));
	}

	//pAttDef->close();
	pBlkRec->close();
	pBlkTbl->close();
	return true;
}

void TVSAttrtibutesController::AddNewAtt(const ACHAR* pName, const ACHAR* tag)
{
	AcDbDatabase *pCurDb;
	AcDbBlockTable* pBlkTbl;
	AcDbBlockTableRecord* pBlkRec;
	AcDbObjectId attId;
	Acad::ErrorStatus es;

	AcDbAttributeDefinition* pAttDef;
	// location of the AttributeDefinition in the
	// block definition
	AcGePoint3d attLoc(1.2, -0.5, 0);

	// specify the text,tag and prompt
	ACHAR text[] = { L"" };

	ACHAR prompt[] = { L"Введите значение" };

	pCurDb =
		acdbHostApplicationServices()->workingDatabase();

	es =
		pCurDb->getBlockTable(pBlkTbl, AcDb::kForRead);

	if (!pBlkTbl->has(pName))
	{
		acutPrintf(L"\nBlock definition TEST does not exist");
		pBlkTbl->close();
		return;

	}

	es = pBlkTbl->getAt(pName, pBlkRec, AcDb::kForWrite);
	// create a AttributeDefinition
	pAttDef = new AcDbAttributeDefinition(attLoc, text,
		tag, prompt);
	pAttDef->setInvisible(true);
	pAttDef->setLockPositionInBlock(true);
	// append the AttributeDefinition to the definition
	es = pBlkRec->appendAcDbEntity(attId, pAttDef);

	pAttDef->close();
	pBlkRec->close();
	pBlkTbl->close();
	//delete pAttDef;
}


bool TVSAttrtibutesController::getBlockName(const AcDbObjectId &objId, CString &blockName)
{
	Acad::ErrorStatus es;
	AcDbObjectPointer<AcDbBlockReference> pBlkRef(objId, AcDb::kForRead);
	if ((es = pBlkRef.openStatus()) != Acad::eOk) {
		acutPrintf(_T("\nОшибка открытия BlockReference: %s"), acadErrorStatusText(es)); return false;
	}
	AcDbBlockTableRecordPointer pBTR(pBlkRef->blockTableRecord(), AcDb::kForRead);
	if ((es = pBTR.openStatus()) != Acad::eOk) {
		acutPrintf(_T("\nОшибка открытия BlockTableRecord: %s"), acadErrorStatusText(es)); return false;
	}
	const ACHAR* sBTRName = NULL; 
	pBTR->getName(sBTRName);
	blockName = sBTRName;
	return true;
}

bool TVSAttrtibutesController::convertAttributesToProperties(const AcDbObjectId & objId)
{
	
	{
		AcDbObjectPointer<AcDbBlockReference> pBlkRef(objId, AcDb::kForWrite);
		if (pBlkRef.openStatus() != Acad::eOk) {
			return false;
		}
	}

	CString valueStr;
	if (GetAtt(objId, TagPos, valueStr)&&valueStr!=L"") {
		TVSController::get()->tvsPropertyController.setPosition(objId,valueStr);
	}

	if (GetAtt(objId, TagName, valueStr) && valueStr != L"") {
		TVSController::get()->tvsPropertyController.setName(objId, valueStr);

		TVSController::get()->tvsPropertyController.setCount(objId, 1);
		TVSController::get()->tvsPropertyController.setUnits(objId, CCommonCount_Unit);
	}


	if (GetAtt(objId, TagType, valueStr) && valueStr != L"") {
		TVSController::get()->tvsPropertyController.setType(objId, valueStr);
	}

	if (GetAtt(objId, TagSize, valueStr) && valueStr != L"") {
		TVSController::get()->tvsPropertyController.setSize(objId, valueStr);
	}

	if (GetAtt(objId, TagArticle, valueStr) && valueStr != L"") {
		TVSController::get()->tvsPropertyController.setArticle(objId, valueStr);
	}

	if (GetAtt(objId, TagManufacture, valueStr) && valueStr != L"") {
		TVSController::get()->tvsPropertyController.setManufacturer(objId, valueStr);
	}

	if (GetAtt(objId, TagMass, valueStr) && valueStr != L"") {
		TVSController::get()->tvsPropertyController.setMass(objId, _tstof(valueStr));
	}

	if (GetAtt(objId, TagCommit, valueStr) && valueStr != L"") {
		TVSController::get()->tvsPropertyController.setNote(objId, valueStr);
	}

	return true;
}

bool TVSAttrtibutesController::removeAttributes(const AcDbObjectId & objId)
{

	{
		AcDbObjectPointer<AcDbBlockReference> pBlkRef(objId, AcDb::kForWrite);
		if (pBlkRef.openStatus() != Acad::eOk) {
			return false;
		}
	}

	CString valueStr;
	if (GetAtt(objId, TagPos, valueStr)) {
		RemoveAttr(objId, TagPos);
	}

	if (GetAtt(objId, TagName, valueStr)) {
		RemoveAttr(objId, TagName);
	}


	if (GetAtt(objId, TagType, valueStr)) {
		RemoveAttr(objId, TagType);
	}

	if (GetAtt(objId, TagSize, valueStr)) {
		RemoveAttr(objId, TagSize);
	}

	if (GetAtt(objId, TagArticle, valueStr)) {
		RemoveAttr(objId, TagArticle);
	}

	if (GetAtt(objId, TagManufacture, valueStr)) {
		RemoveAttr(objId, TagManufacture);
	}

	if (GetAtt(objId, TagMass, valueStr)) {
		RemoveAttr(objId, TagMass);
	}

	if (GetAtt(objId, TagCommit, valueStr)) {
		RemoveAttr(objId, TagCommit);
	}

	return true;
}
bool TVSAttrtibutesController::GetAtt(const AcDbObjectId &objId, const CString& tag, CString& valueStr)
{
	AcDbObjectPointer<AcDbBlockReference> pBlkRef(objId, AcDb::kForRead);
	if (pBlkRef.openStatus() != Acad::eOk) {
		return false;
	}

	Acad::ErrorStatus es;

	AcDbObjectIterator *pAttrIter = pBlkRef->attributeIterator();
	if (!pAttrIter) return false;
	for (pAttrIter->start(); !pAttrIter->done(); pAttrIter->step()) {
		AcDbObjectId objAttrId = pAttrIter->objectId();
		AcDbObjectPointer<AcDbAttribute> pAttr(objAttrId, AcDb::kForRead);

		if ((es = pAttr.openStatus()) != Acad::eOk) continue;

		if (tag == pAttr->tagConst()) {
			valueStr.SetString(pAttr->textStringConst());
			return true;
		}
	}
	return false;
}

bool TVSAttrtibutesController::RemoveAttr(const AcDbObjectId &objId, const CString& tag)
{
	CString pName;
	getBlockName(objId, pName);

	AcDbDatabase *pCurDb;
	AcDbBlockTable* pBlkTbl;
	AcDbBlockTableRecord* pBlkRec;
	AcDbObjectId attId;
	Acad::ErrorStatus es;

	AcDbAttributeDefinition* pAttDef;

	pCurDb = acdbHostApplicationServices()->workingDatabase();
	es = pCurDb->getBlockTable(pBlkTbl, AcDb::kForRead);
	if (!pBlkTbl->has(pName))
	{
		acutPrintf(L"\nBlock definition TEST does not exist");
		pBlkTbl->close();
		return false;
	}
	es = pBlkTbl->getAt(pName, pBlkRec, AcDb::kForWrite);
	// create a AttributeDefinition
	AcDbBlockTableRecordIterator *pIterBTR = NULL;
	if ((es = pBlkRec->newIterator(pIterBTR)) == Acad::eOk) {
		for (; !pIterBTR->done(); pIterBTR->step()) {
			AcDbObjectId objSubId;
			if ((es = pIterBTR->getEntityId(objSubId)) == Acad::eOk) {
				AcDbObjectPointer<AcDbEntity> pSubEnt(objSubId, AcDb::kForWrite);
				if ((es = pSubEnt.openStatus()) == Acad::eOk) {
					//
					// Здесь можно работать с примитивами в блоке
					//
					//buf=pSubEnt->isA()->name();
					//		 											acutPrintf(_T("\nПримитив: %s"),LPCTSTR(pSubEnt->isA()->name()));
					AcDbAttributeDefinition *pAttdef = AcDbAttributeDefinition::cast(pSubEnt.object());
					if (pAttdef) {
						// Если это определение атрибута сделаем отдельную обработку
						if (tag==pAttdef->tagConst()) {
							pAttdef->erase();
							pBlkRec->close();
							pBlkTbl->close();
						}
					}
				}
				else {
					acutPrintf(_T("\nНе удалось открыть примитив в блоке! Ошибка: %s",
						LPCTSTR(acadErrorStatusText(es))));
				}
			}
			else {
				acutPrintf(_T("\nНе удалось получить AcDbObjectId примитва в блоке! Ошибка: %s",
					LPCTSTR(acadErrorStatusText(es))));
			}
		}
	}
	else {
		acutPrintf(_T("\nНе удалось создать итератор для записи таблицы блоков! Ошибка: %s", LPCTSTR(acadErrorStatusText(es))));
	}

	//pAttDef->close();
	pBlkRec->close();
	pBlkTbl->close();

	AcDbObjectPointer<AcDbBlockReference> pBlkRef(objId, AcDb::kForRead);
	if (pBlkRef.openStatus() != Acad::eOk) {
		return false;
	}

	//Acad::ErrorStatus es;
	AcDbObjectIterator *pAttrIter = pBlkRef->attributeIterator();
	if (!pAttrIter) return false;
	for (pAttrIter->start(); !pAttrIter->done(); pAttrIter->step()) {
		AcDbObjectId objAttrId = pAttrIter->objectId();
		AcDbObjectPointer<AcDbAttribute> pAttr(objAttrId, AcDb::kForWrite);

		if ((es = pAttr.openStatus()) != Acad::eOk) continue;

		if (tag == pAttr->tagConst()) {
			pAttr->erase();
			return true;
		}
	}
	return true;
}
