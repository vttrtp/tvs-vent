#pragma once
#include "arxHeaders.h"
class TVSAttrtibutesController
{
	

public:
	TVSAttrtibutesController();
	~TVSAttrtibutesController();
	bool CheckAtt(const ACHAR* pName, const ACHAR* tag);
	void AddNewAtt(const ACHAR* pName, const ACHAR* tag);
	bool getBlockName(const AcDbObjectId & objId, CString & blockName);
	bool convertAttributesToProperties(const AcDbObjectId & objId);
	bool removeAttributes(const AcDbObjectId & objId);
	bool GetAtt(const AcDbObjectId &objId, const CString& tag, CString& valueStr);
	bool RemoveAttr(const AcDbObjectId &objId, const CString& tag);
};

