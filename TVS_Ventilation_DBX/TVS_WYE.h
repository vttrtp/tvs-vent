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
//----- TVS_WYE.h : Declaration of the TVS_WYE
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

#include "TVS_Entity.h"
//-----------------------------------------------------------------------------
class DLLIMPEXP TVS_WYE : public TVS_Entity {

public:
	ACRX_DECLARE_MEMBERS(TVS_WYE) ;

protected:
	static Adesk::UInt32 kCurrentVersionNumber ;

public:
	TVS_WYE () ;
	virtual ~TVS_WYE () ;

	//----- AcDbObject protocols
	//- Dwg Filing protocol
	virtual Acad::ErrorStatus dwgOutFields (AcDbDwgFiler *pFiler) const ;
	virtual Acad::ErrorStatus dwgInFields (AcDbDwgFiler *pFiler) ;

	//- Persistent reactor callbacks
	virtual void openedForModify (const AcDbObject *pDbObj) ;
	virtual void cancelled (const AcDbObject *pDbObj) ;
	virtual void objectClosed (const AcDbObjectId objId) ;
	virtual void goodbye (const AcDbObject *pDbObj) ;
	virtual void copied (const AcDbObject *pDbObj, const AcDbObject *pNewObj) ;
	virtual void erased (const AcDbObject *pDbObj, Adesk::Boolean bErasing =true) ;
	virtual void modified (const AcDbObject *pDbObj) ;
	virtual void modifiedGraphics (const AcDbEntity *pDbEnt) ;
	virtual void modifiedXData (const AcDbObject *pDbObj) ;
	virtual void subObjModified (const AcDbObject *pMainbObj, const AcDbObject *pSubObj) ;
	virtual void modifyUndone (const AcDbObject *pDbObj) ;
	virtual void reappended (const AcDbObject *pDbObj) ;
	virtual void unappended (const AcDbObject *pDbObj) ;

	//----- AcDbEntity protocols
	//- Graphics protocol
protected:
	virtual Adesk::Boolean subWorldDraw (AcGiWorldDraw *mode) ;
	virtual Adesk::UInt32 subSetAttributes (AcGiDrawableTraits *traits) ;

	//- Osnap points protocol
public:
	virtual Acad::ErrorStatus subGetOsnapPoints (
		AcDb::OsnapMode osnapMode,
		Adesk::GsMarker gsSelectionMark,
		const AcGePoint3d &pickPoint,
		const AcGePoint3d &lastPoint,
		const AcGeMatrix3d &viewXform,
		AcGePoint3dArray &snapPoints,
		AcDbIntArray &geomIds) const ;
	virtual Acad::ErrorStatus subGetOsnapPoints (
		AcDb::OsnapMode osnapMode,
		Adesk::GsMarker gsSelectionMark,
		const AcGePoint3d &pickPoint,
		const AcGePoint3d &lastPoint,
		const AcGeMatrix3d &viewXform,
		AcGePoint3dArray &snapPoints,
		AcDbIntArray &geomIds,
		const AcGeMatrix3d &insertionMat) const ;

	//- Grip points protocol
	virtual Acad::ErrorStatus subGetGripPoints (AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds) const ;
	virtual Acad::ErrorStatus subMoveGripPointsAt (const AcDbIntArray &indices, const AcGeVector3d &offset) ;
	virtual Acad::ErrorStatus subGetGripPoints (
		AcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, 
		const AcGeVector3d &curViewDir, const int bitflags) const ;
	virtual Acad::ErrorStatus subMoveGripPointsAt (const AcDbVoidPtrArray &gripAppData, const AcGeVector3d &offset, const int bitflags) ;

	//----- AcDbCurve protocols
	//- Curve property tests.
	virtual Adesk::Boolean isClosed () const ;
	virtual Adesk::Boolean isPeriodic () const ;
	//- Get planar and start/end geometric properties.
	virtual Acad::ErrorStatus getStartParam (double &param) const ;
	virtual Acad::ErrorStatus getEndParam (double &param) const ;
	virtual Acad::ErrorStatus getStartPoint (AcGePoint3d &point) const ;
	virtual Acad::ErrorStatus getEndPoint (AcGePoint3d &point) const ;
	//- Conversions to/from parametric/world/distance.
	virtual Acad::ErrorStatus getPointAtParam (double param, AcGePoint3d &point) const ;
	virtual Acad::ErrorStatus getParamAtPoint (const AcGePoint3d &point, double &param) const ;
	virtual Acad::ErrorStatus getDistAtParam (double param, double &dist) const ;
	virtual Acad::ErrorStatus getParamAtDist (double dist, double &param) const ;
	virtual Acad::ErrorStatus getDistAtPoint (const AcGePoint3d &point , double &dist) const ;
	virtual Acad::ErrorStatus getPointAtDist (double dist, AcGePoint3d &point) const ;
	//- Derivative information.
	virtual Acad::ErrorStatus getFirstDeriv (double param, AcGeVector3d &firstDeriv) const ;
	virtual Acad::ErrorStatus getFirstDeriv  (const AcGePoint3d &point, AcGeVector3d &firstDeriv) const ;
	virtual Acad::ErrorStatus getSecondDeriv (double param, AcGeVector3d &secDeriv) const ;
	virtual Acad::ErrorStatus getSecondDeriv (const AcGePoint3d &point, AcGeVector3d &secDeriv) const ;
	//- Closest point on curve.
	virtual Acad::ErrorStatus getClosestPointTo (const AcGePoint3d &givenPnt, AcGePoint3d &pointOnCurve, Adesk::Boolean extend =Adesk::kFalse) const ;
	virtual Acad::ErrorStatus getClosestPointTo (const AcGePoint3d &givenPnt, const AcGeVector3d &direction, AcGePoint3d &pointOnCurve, Adesk::Boolean extend =Adesk::kFalse) const ;
	//- Get a projected copy of the curve.
	virtual Acad::ErrorStatus getOrthoProjectedCurve (const AcGePlane &plane, AcDbCurve *&projCrv) const ;
	virtual Acad::ErrorStatus getProjectedCurve (const AcGePlane &plane, const AcGeVector3d &projDir, AcDbCurve *&projCrv) const ;
	//- Get offset, spline and split copies of the curve.
	virtual Acad::ErrorStatus getOffsetCurves (double offsetDist, AcDbVoidPtrArray &offsetCurves) const ;
	virtual Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal (const AcGeVector3d &normal, double offsetDist, AcDbVoidPtrArray &offsetCurves) const ;
	virtual Acad::ErrorStatus getSpline (AcDbSpline *&spline) const ;
	virtual Acad::ErrorStatus getSplitCurves (const AcGeDoubleArray &params, AcDbVoidPtrArray &curveSegments) const ;
	virtual Acad::ErrorStatus getSplitCurves (const AcGePoint3dArray &points, AcDbVoidPtrArray &curveSegments) const ;
	//- Extend the curve.
	virtual Acad::ErrorStatus extend (double newParam) ;
	virtual Acad::ErrorStatus extend (Adesk::Boolean extendStart, const AcGePoint3d &toPoint) ;
	//- Area calculation.
	virtual Acad::ErrorStatus getArea (double &area) const ;



//////////
	double SizeApr;
	double SizeBpr;
	double SizeAotv;
	double SizeBotv;
	double LengthPl;
	double angleW;
	AcGeVector3d Vectpr;
	AcGeVector3d Vectotv;
	AcGePoint3d Basepoint;
	AcGePoint3d pA,pB,pC,pD,pE,pF,pG,pH,pA1,pA2,pA3,pA4,pA5,pMa,pB1,pB2;
	bool ThisRoundpr;
	bool ThisRoundotv;
	

	static TVS_WYE *add_new(
		double &pSizeApr,
		double &pSizeBpr,
		double &pSizeAotv,
		double &pSizeBotv,
		double &pLengthPl,
		AcGeVector3d &pVectpr,
		AcGeVector3d &pVectotv,
		AcGePoint3d &pBasepoint,
		bool pThisRoundpr,
		bool pThisRoundotv,
		bool pThis1D=false
		);
	void Gimme7Points();



	double get_Length(void) const;
	Acad::ErrorStatus put_Length(double newVal);
	double get_SizeApr(void) const;
	Acad::ErrorStatus put_SizeApr(double newVal);
	double get_SizeBpr(void) const;
	Acad::ErrorStatus put_SizeBpr(double newVal);
	double get_SizeAotv(void) const;
	Acad::ErrorStatus put_SizeAotv(double newVal);
	double get_SizeBotv(void) const;
	Acad::ErrorStatus put_SizeBotv(double newVal);
	AcGeVector3d get_Vectpr(void) const;
	Acad::ErrorStatus put_Vectpr(AcGeVector3d newVal);
	AcGeVector3d get_Vectotv(void) const;
	Acad::ErrorStatus put_Vectotv(AcGeVector3d newVal);

	void setFlex(const bool &isFlex);
	void setStill();
	void setDuctType(int pDuctType);

protected:
	// -----------------------------------------------------------------------------
	virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d & xform);
	// -----------------------------------------------------------------------------
	virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray & entitySet) const;
	Acad::ErrorStatus subGetClassID (CLSID *pClsid) const;




} ;

#ifdef TVS_VENTILATION_DBX_MODULE
ACDB_REGISTER_OBJECT_ENTRY_AUTO(TVS_WYE)
#endif
