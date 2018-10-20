#pragma once
#include "arxHeaders.h"

class XRecordXdataHelper
{
public:
	XRecordXdataHelper();

	template<typename T>
	bool setXdataParameter(const AcDbObjectId &objectId, const ACHAR * paramName, const int &parameterType, const T &parameter);

	template<typename T> bool
		setXrecordParameter(const AcDbObjectId &objectId, const ACHAR * paramName, const int &parameterType, const T &parameter);

	//setbuffer
	bool setXdataBuf(const AcDbObjectId &objectId,const resbuf *rb);
	bool setXrecordBuf(const AcDbObjectId &objectId, const ACHAR * paramName, const  resbuf *rb);

	bool getStringXdata(const AcDbObjectId &objectId, const ACHAR * paramName, CString &value);
	bool removeXdata(const AcDbObjectId &objectId, const ACHAR * paramName);
	bool removeXrecord(const AcDbObjectId &objectId, const ACHAR * paramName);

	bool getObjectIdXrecord(const AcDbObjectId &objectId, const ACHAR * paramName, AcDbObjectId &objId);

	bool getXDataResbuf(const AcDbObjectId &objectId, const ACHAR * paramName, resbuf *&rb);

	bool getXDataResbuf(const AcDbObjectPointer<AcDbObject> &pObject, const ACHAR * paramName, resbuf *&rb);
	bool getXRecordResbuf(const AcDbObjectId &objectId, const ACHAR * paramName, resbuf *&rb);

	//process subdata
	resbuf* findSubXdata(int tag, resbuf* xdata);
	bool setSubXString(const AcDbObjectId &objectId, const ACHAR * appName, int tag, const CString &parameter);
	bool setSubXReal(const AcDbObjectId &objectId, const ACHAR * appName, int tag, const double &parameter);

	bool getSubXReal(const AcDbObjectId &objectId, const ACHAR * appName, int tag, double &parameter);
	bool getSubXString(const AcDbObjectId &objectId, const ACHAR * appName, int tag, CString &parameter);
	
	virtual ~XRecordXdataHelper();
};

template<typename T>
bool XRecordXdataHelper::setXdataParameter(const AcDbObjectId &objectId, const ACHAR * paramName, const int &parameterType, const T &parameter)
{
	//add resbuf to xdata
	resbuf *rb = acutBuildList(AcDb::kDxfRegAppName, paramName, parameterType, parameter, AcDb::kDwgNull);
	bool ret = setXdataBuf(objectId,rb);
	acutRelRb(rb);
	return ret;
}

template<typename T>
bool XRecordXdataHelper::setXrecordParameter(const AcDbObjectId &objectId, const ACHAR * paramName, const int &parameterType, const T &parameter)
{
	//add resbuf to xrecord
	resbuf * rb = acutBuildList(parameterType, parameter, 0);
	bool ret = setXrecordBuf(objectId, paramName, rb);
	acutRelRb(rb);
	return ret;
}


