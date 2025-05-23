// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- TVS_Entity.h : Declaration of the TVS_Entity
//-----------------------------------------------------------------------------
#pragma once

#ifdef TVS_VENTILATION_DBX_MODULE
#define DLLIMPEXP __declspec(dllexport)
#else
//----- Note: we don't use __declspec(dllimport) here, because of the
//----- "local vtable" problem with msvc. If you use __declspec(dllimport),
//----- then, when a client dll does a new on the class, the object's
//----- vtable pointer points to a vtable allocated in that client
//----- dll. If the client dll then passes the object to another dll,
//----- and the client dll is then unloaded, the vtable becomes invalid
//----- and any virtual calls on the object will access invalid memory.
//-----
//----- By not using __declspec(dllimport), we guarantee that the
//----- vtable is allocated in the server dll during the ctor and the
//----- client dll does not overwrite the vtable pointer after calling
//----- the ctor. And, since we expect the server dll to remain in
//----- memory indefinitely, there is no problem with vtables unexpectedly
//----- going away.
#define DLLIMPEXP
#endif

//-----------------------------------------------------------------------------
#include <acedads.h>
#include <acedCmdNF.h>
#include "dbcurve.h"
#define TVS_Version 32
#define M_PI 3.14159265358979323846
#define DuctTypeStill 0
#define DuctTypeFlex 1
#include <ObjBase.h>
#include <InitGuid.h>
#include "dbmain.h"
#include "rxmfcapi.h"
#include <vector>
#include "GripImp.h"
#include "TVS_Connector.h"
#include <iostream>
#include "commonDef.h"

#include <algorithm>
using namespace std;


//-----------------------------------------------------------------------------

class DLLIMPEXP TVS_Entity : public AcDbCurve {

public:
	ACRX_DECLARE_MEMBERS(TVS_Entity);

protected:
	static Adesk::UInt32 kCurrentVersionNumber;

public:
	TVS_Entity();
	virtual ~TVS_Entity();

	//----- AcDbObject protocols
	//- Dwg Filing protocol
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler *pFiler) const;
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler *pFiler);

	//- SubXXX() methods (self notification)
	virtual Acad::ErrorStatus subOpen(AcDb::OpenMode mode);
	//virtual Acad::ErrorStatus subErase (Adesk::Boolean erasing) ;
	virtual Acad::ErrorStatus subCancel();
	virtual Acad::ErrorStatus subClose();

	//- Persistent reactor callbacks
	virtual void openedForModify(const AcDbObject *pDbObj);
	virtual void cancelled(const AcDbObject *pDbObj);
	virtual void objectClosed(const AcDbObjectId objId);
	virtual void goodbye(const AcDbObject *pDbObj);
	virtual void copied(const AcDbObject *pDbObj, const AcDbObject *pNewObj);
	virtual void erased(const AcDbObject *pDbObj, Adesk::Boolean bErasing = true);
	virtual void modified(const AcDbObject *pDbObj);
	virtual void modifiedGraphics(const AcDbEntity *pDbEnt);
	virtual void modifiedXData(const AcDbObject *pDbObj);
	virtual void subObjModified(const AcDbObject *pMainbObj, const AcDbObject *pSubObj);
	virtual void modifyUndone(const AcDbObject *pDbObj);
	virtual void reappended(const AcDbObject *pDbObj);
	virtual void unappended(const AcDbObject *pDbObj);

	//----- AcDbEntity protocols
	//- Graphics protocol
protected:
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw *mode);
	virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits *traits);

	//- Osnap points protocol
public:
	virtual Acad::ErrorStatus subGetOsnapPoints(
		AcDb::OsnapMode osnapMode,
		Adesk::GsMarker gsSelectionMark,
		const AcGePoint3d &pickPoint,
		const AcGePoint3d &lastPoint,
		const AcGeMatrix3d &viewXform,
		AcGePoint3dArray &snapPoints,
		AcDbIntArray &geomIds) const;
	virtual Acad::ErrorStatus subGetOsnapPoints(
		AcDb::OsnapMode osnapMode,
		Adesk::GsMarker gsSelectionMark,
		const AcGePoint3d &pickPoint,
		const AcGePoint3d &lastPoint,
		const AcGeMatrix3d &viewXform,
		AcGePoint3dArray &snapPoints,
		AcDbIntArray &geomIds,
		const AcGeMatrix3d &insertionMat) const;

	//- Grip points protocol
	virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds) const;
	virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray &indices, const AcGeVector3d &offset);
	virtual Acad::ErrorStatus subGetGripPoints(
		AcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize,
		const AcGeVector3d &curViewDir, const int bitflags) const;
	virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray &gripAppData, const AcGeVector3d &offset, const int bitflags);

	virtual double get_Speed();
	//----- AcDbCurve protocols
	//- Curve property tests.
	virtual Adesk::Boolean isClosed() const;
	virtual Adesk::Boolean isPeriodic() const;
	//- Get planar and start/end geometric properties.
	virtual Acad::ErrorStatus getStartParam(double &param) const;
	virtual Acad::ErrorStatus getEndParam(double &param) const;
	virtual Acad::ErrorStatus getStartPoint(AcGePoint3d &point) const;
	virtual Acad::ErrorStatus getEndPoint(AcGePoint3d &point) const;
	//- Conversions to/from parametric/world/distance.
	virtual Acad::ErrorStatus getPointAtParam(double param, AcGePoint3d &point) const;
	virtual Acad::ErrorStatus getParamAtPoint(const AcGePoint3d &point, double &param) const;
	virtual Acad::ErrorStatus getDistAtParam(double param, double &dist) const;
	virtual Acad::ErrorStatus getParamAtDist(double dist, double &param) const;
	virtual Acad::ErrorStatus getDistAtPoint(const AcGePoint3d &point, double &dist) const;
	virtual Acad::ErrorStatus getPointAtDist(double dist, AcGePoint3d &point) const;
	//- Derivative information.
	virtual Acad::ErrorStatus getFirstDeriv(double param, AcGeVector3d &firstDeriv) const;
	virtual Acad::ErrorStatus getFirstDeriv(const AcGePoint3d &point, AcGeVector3d &firstDeriv) const;
	virtual Acad::ErrorStatus getSecondDeriv(double param, AcGeVector3d &secDeriv) const;
	virtual Acad::ErrorStatus getSecondDeriv(const AcGePoint3d &point, AcGeVector3d &secDeriv) const;
	//- Closest point on curve.
	virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d &givenPnt, AcGePoint3d &pointOnCurve, Adesk::Boolean extend = Adesk::kFalse) const;
	virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d &givenPnt, const AcGeVector3d &direction, AcGePoint3d &pointOnCurve, Adesk::Boolean extend = Adesk::kFalse) const;
	//- Get a projected copy of the curve.
	virtual Acad::ErrorStatus getOrthoProjectedCurve(const AcGePlane &plane, AcDbCurve *&projCrv) const;
	virtual Acad::ErrorStatus getProjectedCurve(const AcGePlane &plane, const AcGeVector3d &projDir, AcDbCurve *&projCrv) const;
	//- Get offset, spline and split copies of the curve.
	virtual Acad::ErrorStatus getOffsetCurves(double offsetDist, AcDbVoidPtrArray &offsetCurves) const;
	virtual Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(const AcGeVector3d &normal, double offsetDist, AcDbVoidPtrArray &offsetCurves) const;
	virtual Acad::ErrorStatus getSpline(AcDbSpline *&spline) const;
	virtual Acad::ErrorStatus getSplitCurves(const AcGeDoubleArray &params, AcDbVoidPtrArray &curveSegments) const;
	virtual Acad::ErrorStatus getSplitCurves(const AcGePoint3dArray &points, AcDbVoidPtrArray &curveSegments) const;
	//- Extend the curve.
	virtual Acad::ErrorStatus extend(double newParam);
	virtual Acad::ErrorStatus extend(Adesk::Boolean extendStart, const AcGePoint3d &toPoint);
	//- Area calculation.
	virtual Acad::ErrorStatus getArea(double &area) const;


	// 	virtual Acad::ErrorStatus   subIntersectWith(
	// 		const AcDbEntity*   ent,
	// 		AcDb::Intersect     intType,
	// 		AcGePoint3dArray&      points,
	// 		int                 thisGsMarker  = 0,
	// 		int                 otherGsMarker = 0)
	// 		const;
	// 
	// 	virtual Acad::ErrorStatus   subIntersectWith(
	// 		const AcDbEntity*   ent,
	// 		AcDb::Intersect     intType,
	// 		const AcGePlane&    projPlane,
	// 		AcGePoint3dArray&      points,
	// 		int                 thisGsMarker  = 0,
	// 		int                 otherGsMarker = 0)
	// 		const;


		//////TVS new
		//get Size String
	virtual void getSizeString(CString &size, const bool &sortSize = false) {};

	virtual void getCount(double &count);

	virtual void getCountUnit(CString &unit);
	virtual void getName(CString &unit){};
	////

	void writeInt(AcDbDwgFiler *pFiler, const int &param) const;
	void readInt(AcDbDwgFiler *pFiler, int &param,const int &version);

	public:
	double SizeA;
	double SizeB;
	bool Grani;
	bool IsPipe;
	TCHAR *Tag1;
	TCHAR *Tag2;
	double ElevUp;
	double ElevDown;
	bool ThisRound;
	bool This1D;
	double Flow;
	double Axis;
	int Direct;
	double Elev;
	bool Wipeout;
	int Param;
	bool ShowText;
	int Form;
	int DuctType;
	bool activeStatus;
	AcDbHardPointerId connector1;
	AcDbHardPointerId connector2;
	AcDbHardPointerId connector3;
	vector <AcDbEntity> ListOfEntityAxis;
	vector <AcDbEntity> ListOfEntityBody;
	AcDbVoidPtrArray ListOfEntity;
	AcDbVoidPtrArray ListOfWipeout;
	double WipeoutLength;
	int Type1;
	int Type2;

	bool connectorInteractionStatus;
	Int8 connectorCounts;
	bool getConnectorByIndex(const int &ind, int &indexret);
	virtual bool correctConnector(const int &index,const  AcGeVector3d &offset);
	bool correctAnother(const TVS_Connector& con,const AcGeVector3d& offset);
	vector<TVS_Connector> connectors; 
	void writeConnectors(AcDbDwgFiler *pFiler, const int &version = kCurrentVersionNumber) const;
	void readConnectors(AcDbDwgFiler *pFiler, const int &version = kCurrentVersionNumber);
	public:
	bool get_Grani(void) const;
	Acad::ErrorStatus put_Grani(bool newVal);
	double get_SizeA(void) const;
	Acad::ErrorStatus put_SizeA(double newVal);
	double get_SizeB(void) const;
	Acad::ErrorStatus put_SizeB(double newVal);
	bool get_ThisRound(void) const;
	Acad::ErrorStatus put_ThisRound(bool newVal);
	double get_Length(void) const;
	Acad::ErrorStatus put_Length(double newVal);
	double get_Expend(void) const;
	Acad::ErrorStatus put_Expend(double newVal);
	double get_Axis(void) const;
	Acad::ErrorStatus put_Axis(double newVal);
	double get_Flow(void) const;
	Acad::ErrorStatus put_Flow(double newVal);
	double get_Elevation(void) const;
	Acad::ErrorStatus put_Elevation(double newVal);
	bool get_Wipeout(void) const;
	Acad::ErrorStatus put_Wipeout(bool newVal);
	int get_Param(void) const;
	Acad::ErrorStatus put_Param(int newVal);
	double get_ElevUp(void) const;
	Acad::ErrorStatus put_ElevUp(double newVal);
	double get_ElevDown(void) const;
	Acad::ErrorStatus put_ElevDown(double newVal);
	bool get_IsPipe(void) const;
	Acad::ErrorStatus put_IsPipe(bool newVal);
	TCHAR *get_Tag1(void) const;
	Acad::ErrorStatus put_Tag1(TCHAR *newVal);
	TCHAR *get_Tag2(void) const;
	Acad::ErrorStatus put_Tag2(TCHAR *newVal);
	bool get_This1D(void) const;
	Acad::ErrorStatus put_This1D(bool newVal);
	int get_Direct(void) const;
	Acad::ErrorStatus put_Direct(int newVal);
	void get_WipeoutColor(AcGiWorldDraw *mode, AcCmColor &backcolor) const;
	int get_Form(void) const;
	Acad::ErrorStatus put_Form(int newVal);
	int get_Type1(void) const;
	Acad::ErrorStatus put_Type1(int newVal);
	int get_Type2(void) const;
	Acad::ErrorStatus put_Type2(int newVal);
	
	void setMainProperty(AcDbEntity *pEnt);
	void setCenterProperty(AcDbEntity *pEnt);
	void setWipeoutProperty(AcGiWorldDraw *mode, AcDbPolyline *pEnt);
	void setHideProperty(AcDbEntity *pEnt);
	void setZigzagProperty(AcDbEntity *pEnt);
	void setThinProperty(AcDbEntity *pEnt);
	double get_WipeoutLength(void) const;
	Acad::ErrorStatus put_WipeoutLength(double newVal);
	virtual void setFlex(const bool &isFlex);
	void setStill();
	int getDuctType();
	virtual void setDuctType(int pDuctType);
	void setNewParameters();
	void ClearEntitylist();
	bool isDuctFlex();
} ;

#ifdef TVS_VENTILATION_DBX_MODULE
ACDB_REGISTER_OBJECT_ENTRY_AUTO(TVS_Entity)
#endif
