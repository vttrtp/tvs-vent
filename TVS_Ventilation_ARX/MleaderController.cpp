#include "stdafx.h"
#include "MleaderController.h"
#include "MleaderSettings.h"
#include "TVSPropertyController.h"

MleaderController::MleaderController()
{
}

MleaderController m_ctrl;
MleaderController * MleaderController::get()
{
	return &m_ctrl;
}

bool MleaderController::registerApp()
{
	acdbRegApp(MLeaderID);
	acdbRegApp(MLeaderFormat);
	return true;
}

bool MleaderController::getFormat(const AcDbObjectId &MLeaderId, CString &format)
{
	return getStringXdata(MLeaderId, MLeaderFormat, format);
}

bool MleaderController::setFormat(const AcDbObjectId &MLeaderId, const CString &format)
{
	return setXdataParameter(MLeaderId, MLeaderFormat, AcDb::kDxfXdAsciiString, format.GetString());
}

bool MleaderController::checkIfMLead(AcDbObjectId objId)
{
	AcDbObjectPointer<AcDbEntity>pEnt(objId, AcDb::kForRead);
	if (pEnt.openStatus() != Acad::eOk) return false;

	if (AcDbMLeader::cast(pEnt) != NULL) 
	{
		return true;
	}
	else {
		return false;
	}
}

bool MleaderController::setObjectId(const AcDbObjectId &MLeaderId, const AcDbObjectId &objId) {

	ads_name adsName;
	acdbGetAdsName(adsName, objId);
	return setXrecordParameter(MLeaderId, MLeaderID, AcDb::kDxfHardPointerId, adsName);
}

bool MleaderController::getObjectId(const AcDbObjectId &MLeaderId, AcDbObjectId &objId) {

	return getObjectIdXrecord(MLeaderId, MLeaderID, objId);
}

bool MleaderController::clearMleader(const AcDbObjectId &MLeaderId) {
	return true;
}

bool MleaderController::recalculateMleader(const AcDbObjectId &MLeaderId)
{

	AcDbObjectId objectId;
	if (!checkIfMLead(MLeaderId)) {
		return false;
	}
	if (!getObjectId(MLeaderId, objectId)) return false;

	//check if id exists
	if (objectId == NULL) {
		setFormat(MLeaderId, L"");
		return false;
	}

	CString format;
	if (!getFormat(MLeaderId, format)) return false;
	CString message;
	if (!getStringMessage(objectId, format, message))return false;
	return setTextMessage(MLeaderId, message);
}

bool MleaderController::setTextMessage(const AcDbObjectId &MLeaderId, const CString &textMessage)
{
	AcDbObjectPointer<AcDbMLeader>pEnt(MLeaderId, AcDb::kForWrite);
	if (pEnt.openStatus() != Acad::eOk) return false;

	AcDbMText *pMtext = pEnt->mtext();
	if (pMtext) {
		pMtext->setContents(textMessage.GetString());
		pEnt->setMText(pMtext);
		delete pMtext;
	}

	return true;
}

bool MleaderController::getStringMessage(const AcDbObjectId &ObjectId, const CString &format, CString &message)
{

	int entType = 0;

	//check attrib
	bool haveAttrib = TVSPropertyController::get()->checkProperty(ObjectId);

	{
		AcDbObjectPointer<AcDbEntity>pEnt(ObjectId, AcDb::kForRead);

		//check entity
		AcDbBlockReference * br;
		TVS_Entity * ent;
		if ((br = AcDbBlockReference::cast(pEnt)) != NULL)
		{
			entType = 1;
		}
		else if ((ent = TVS_Entity::cast(pEnt)) != NULL)
		{
			entType = 2;
		}
		else if (!haveAttrib)
		{
			return false;
		}
	}

	//parse format
	CString curTemp;
	bool inTemp = false;
	int length = format.GetLength();
	for (int i = 0; i < length; i++)
	{
		if (format[i] == L'[') {
			curTemp = L"";
			inTemp = true;
			continue;
		}

		if (format[i] == L']') {
			CString strVal;
			if (haveAttrib)
			{
				TVSPropertyController::get()->getStringValueOfAnyPropertyByName(ObjectId, curTemp, strVal);
			}
			if (strVal == "") {
				switch (entType) {

				case 1:
					GetBlockStringPropertyByName(ObjectId, curTemp, strVal);
					break;
				case 2:
					GetEntityStringPropertyByName(ObjectId, curTemp, strVal);
					break;
				}
			}

			message += strVal;
			curTemp = L"";
			inTemp = false;
			continue;
		}
		if (inTemp) {
			curTemp += format[i];

		}
		else {
			message += format[i];
		}
	}
	return true;

}

bool MleaderController::GetEntityStringPropertyByName(const AcDbObjectId  &objId, const CString &stringTemplate, CString &stringText)
{
	AcDbObjectPointer<TVS_Entity>pEnt(objId, AcDb::kForRead);
	if (pEnt.openStatus() != Acad::eOk)
	{
		return false;
	}
	if (stringTemplate == L"N")
	{
		ACHAR * layerName = pEnt->layer();
		stringText = layerName;
		return true;
	}
	else if (stringTemplate == L"L") {
		stringText.Format(L"%g", pEnt->get_Flow());
		return true;
	}
	else if (stringTemplate == L"V") {
		stringText.Format(L"%g",pEnt->get_Speed());
		return true;
	}
	else if (stringTemplate == L"D") {
		pEnt->getSizeString(stringText);
		return true;
	}
	else if (stringTemplate == L"P") {
		//pEnt->getSizeString(stringText);
		return true;
	}

	return false;
}

bool MleaderController::GetBlockStringPropertyByName(const AcDbObjectId  &objId, const CString &stringTemplate, CString &stringText)
{
	AcDbObjectPointer<AcDbBlockReference>pBr(objId, AcDb::kForRead);
	if (pBr.openStatus() != Acad::eOk)
	{
		return false;
	}

	if (stringTemplate == L"N")
	{
		ACHAR * layerName = pBr->layer();
		stringText = layerName;
		return true;
	}
	else if (stringTemplate == L"BN") {
		AcDbObjectPointer<AcDbBlockTableRecord> pBTR(pBr->blockTableRecord(), AcDb::kForRead);
		ACHAR * pName;
		pBTR->getName(pName);
		stringText = pName;
		return true;
	}
	else {
		return  GetAtt(pBr, stringTemplate, stringText);
	}
}

MleaderController::~MleaderController()
{
}

bool MleaderController::GetAtt(AcDbBlockReference* pBr, const CString& tag, CString& valueStr)
{
	Acad::ErrorStatus es;

	AcDbObjectIterator *pAttrIter = pBr->attributeIterator();
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
