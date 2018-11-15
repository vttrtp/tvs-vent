#pragma once
#include "arxHeaders.h"
#include "TVS_Entity.h"
#include "xRecordXdataHelper.h"

class MleaderController :
	protected XRecordXdataHelper
{
public:
	MleaderController();
	static MleaderController* get();
	virtual bool registerApp();
	//ObjectId xData
	bool getObjectId(const AcDbObjectId &MLeaderId, AcDbObjectId &objectId);
	bool clearMleader(const AcDbObjectId &MLeaderId);
	bool setObjectId(const AcDbObjectId &MLeaderId, const AcDbObjectId &objectId);

	//Format xData
	bool getFormat(const AcDbObjectId &MLeaderId, CString &format);
	bool setFormat(const AcDbObjectId &MLeaderId, const CString &format);

	//recalculate mleader
	bool recalculateMleader(const AcDbObjectId &MLeaderId);

	//setTextMessage
	bool setTextMessage(const AcDbObjectId &MLeaderId, const CString &textMessage);

	//Mleader get Message by Format
	bool getStringMessage(const AcDbObjectId &ObjectId, const CString &format, CString &message);
	bool GetEntityStringPropertyByName(const AcDbObjectId &objId, const CString &stringTemplate, CString &stringText);
	bool GetBlockStringPropertyByName(const AcDbObjectId &objId, const CString &stringTemplate, CString &stringText);
	bool GetAtt(AcDbBlockReference* pBr, const CString& tag, CString& valueStr);

	~MleaderController();
private:

};

