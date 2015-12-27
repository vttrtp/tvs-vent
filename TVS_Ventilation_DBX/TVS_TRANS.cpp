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
//----- TVS_TRANS.cpp : Implementation of TVS_TRANS
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "TVS_TRANS.h"
#include "TVS_Ventilation_DBX_i.h"
//-----------------------------------------------------------------------------
Adesk::UInt32 TVS_TRANS::kCurrentVersionNumber =TVS_Version ;

//-----------------------------------------------------------------------------
ACRX_DXF_DEFINE_MEMBERS (
	TVS_TRANS, TVS_Entity,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, 
	AcDbProxyEntity::kNoOperation, TVS_TRANS,
	TVSTVS_VENTILATION_DBXAPP
	|Product Desc:     A description for your object
	|Company:          Your company name
	|WEB Address:      Your company WEB site address
	)

	//-----------------------------------------------------------------------------
	TVS_TRANS::TVS_TRANS () : TVS_Entity () {
}

TVS_TRANS::~TVS_TRANS () {
}
Acad::ErrorStatus TVS_TRANS::subGetClassID (CLSID *pClsid) const {
	assertReadEnabled () ;

	*pClsid=CLSID_ComTrans;

	return (Acad::eOk) ;
}
//-----------------------------------------------------------------------------
//----- AcDbObject protocols
//- Dwg Filing protocol
Acad::ErrorStatus TVS_TRANS::dwgOutFields (AcDbDwgFiler *pFiler) const {
	assertReadEnabled () ;
	//----- Save parent class information first.
	Acad::ErrorStatus es =AcDbCurve::dwgOutFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be saved first
	if ( (es =pFiler->writeUInt32 (TVS_TRANS::kCurrentVersionNumber)) != Acad::eOk )
		return (es) ;
	//----- Output params
	//.....
	pFiler->writeItem (SizeAp1) ;
	pFiler->writeItem (SizeBp1) ;
	pFiler->writeItem (SizeAp2) ;
	pFiler->writeItem (SizeBp2) ;
	pFiler->writeItem (LengthTr) ;
	pFiler->writeItem (VectTr) ;
	pFiler->writeItem (FirstPoint) ;
	pFiler->writeItem (ThisRoundp1) ;
	pFiler->writeItem (ThisRoundp2) ;
	pFiler->writeItem (TransType) ;
	pFiler->writeItem (This1D) ;
	pFiler->writeItem (Flow) ;
	pFiler->writeItem (Direct) ;
	pFiler->writeItem (Elev) ;
	pFiler->writeItem (Wipeout) ;
	pFiler->writeItem (Param) ;
	pFiler->writeItem (IsPipe) ;
	pFiler->writeItem (Form) ;
	pFiler->writeItem (WipeoutLength) ;
	//pFiler->writeString (Tag1) ;
	//pFiler->writeString (Tag2) ;

	return (pFiler->filerStatus ()) ;
}

Acad::ErrorStatus TVS_TRANS::dwgInFields (AcDbDwgFiler *pFiler) {
	assertWriteEnabled () ;
	//----- Read parent class information first.
	Acad::ErrorStatus es =AcDbCurve::dwgInFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be read first
	Adesk::UInt32 version =TVS_Version ;
	if ( (es =pFiler->readUInt32 (&version)) != Acad::eOk )
		return (es) ;
	if ( version > TVS_TRANS::kCurrentVersionNumber )
		return (Acad::eMakeMeProxy) ;
	//- Uncomment the 2 following lines if your current object implementation cannot
	//- support previous version of that object.
	//if ( version < TVS_TRANS::kCurrentVersionNumber )
	//	return (Acad::eMakeMeProxy) ;
	//----- Read params
	//.....
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&SizeAp1) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&SizeBp1) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&SizeAp2) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&SizeBp2) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&LengthTr) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&VectTr) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&FirstPoint) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&ThisRoundp1) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&ThisRoundp2) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&TransType) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&This1D) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Flow) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Direct) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Elev) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Wipeout) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Param) ;
	if ( version >= 5 /*&& version <= endVersion*/ ) pFiler->readItem (&IsPipe) ;
	if ( version >= 21 /*&& version <= endVersion*/ ) pFiler->readItem (&Form) ;
	if ( version >= 23 /*&& version <= endVersion*/ ) pFiler->readItem (&WipeoutLength) ;	else WipeoutLength=50;

	//acutDelString(Tag1);
	//acutDelString(Tag2);
	//if ( version >= 5 /*&& version <= endVersion*/ ) pFiler->readString(&Tag1) ;
	//if ( version >= 5 /*&& version <= endVersion*/ ) pFiler->readString(&Tag2) ;


	return (pFiler->filerStatus ()) ;
}

//- Persistent reactor callbacks
void TVS_TRANS::openedForModify (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::openedForModify (pDbObj) ;
}

void TVS_TRANS::cancelled (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::cancelled (pDbObj) ;
}

void TVS_TRANS::objectClosed (const AcDbObjectId objId) {
	assertReadEnabled () ;
	AcDbCurve::objectClosed (objId) ;
}

void TVS_TRANS::goodbye (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::goodbye (pDbObj) ;
}

void TVS_TRANS::copied (const AcDbObject *pDbObj, const AcDbObject *pNewObj) {
	assertReadEnabled () ;
	AcDbCurve::copied (pDbObj, pNewObj) ;
}

void TVS_TRANS::erased (const AcDbObject *pDbObj, Adesk::Boolean bErasing) {
	assertReadEnabled () ;
	AcDbCurve::erased (pDbObj, bErasing) ;
}

void TVS_TRANS::modified (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modified (pDbObj) ;
}

void TVS_TRANS::modifiedGraphics (const AcDbEntity *pDbEnt) {
	assertReadEnabled () ;
	AcDbCurve::modifiedGraphics (pDbEnt) ;
}

void TVS_TRANS::modifiedXData (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modifiedXData (pDbObj) ;
}

void TVS_TRANS::subObjModified (const AcDbObject *pMainbObj, const AcDbObject *pSubObj) {
	assertReadEnabled () ;
	AcDbCurve::subObjModified (pMainbObj, pSubObj) ;
}

void TVS_TRANS::modifyUndone (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modifyUndone (pDbObj) ;
}

void TVS_TRANS::reappended (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::reappended (pDbObj) ;
}

void TVS_TRANS::unappended (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::unappended (pDbObj) ;
}

//-----------------------------------------------------------------------------
//----- AcDbEntity protocols
Adesk::Boolean TVS_TRANS::subWorldDraw (AcGiWorldDraw *mode) {
	assertReadEnabled () ;
		ListOfEntity.removeAll();
		ListOfWipeout.removeAll();
	bool tt=false;
	AcGeVector3d vec=AcGeVector3d(VectTr.y,-VectTr.x,VectTr.z);
	vec.normalize();
	double prirost=200;
	LengthTr=VectTr.length();
	LastPoint=AcGePoint3d(FirstPoint.x+VectTr.x,
		FirstPoint.y+VectTr.y,
		FirstPoint.z);	
	if (TransType==2)
	{
		if (SizeAp1>SizeAp2) LastPoint=AcGePoint3d(vec.x*abs(SizeAp1/2-SizeAp2/2)+LastPoint.x,
			vec.y*abs(SizeAp1/2-SizeAp2/2)+LastPoint.y,
			LastPoint.z);

		else LastPoint=AcGePoint3d(-vec.x*abs(SizeAp1/2-SizeAp2/2)+LastPoint.x,
			-vec.y*abs(SizeAp1/2-SizeAp2/2)+LastPoint.y,
			LastPoint.z);

		tt=true;
	}

	if (TransType==3)
	{

		if (SizeAp1<SizeAp2) LastPoint=AcGePoint3d(vec.x*abs(SizeAp1/2-SizeAp2/2)+LastPoint.x,
			vec.y*abs(SizeAp1/2-SizeAp2/2)+LastPoint.y,
			LastPoint.z);

		else LastPoint=AcGePoint3d(-vec.x*abs(SizeAp1/2-SizeAp2/2)+LastPoint.x,
			-vec.y*abs(SizeAp1/2-SizeAp2/2)+LastPoint.y,
			LastPoint.z);
		tt=true;
	}

	if (tt==false)
	{

		LastPoint=AcGePoint3d(FirstPoint.x+VectTr.x,
			FirstPoint.y+VectTr.y,
			FirstPoint.z);
	}



	if (Wipeout==true) //wipe
	{
		




		AcGePoint2d p[2];
		p[0]=AcGePoint2d(FirstPoint.x,FirstPoint.y);
		p[1]=AcGePoint2d(LastPoint.x,LastPoint.y);




		AcDbPolyline *pLn=new AcDbPolyline(2);




		

		setWipeoutProperty(mode,pLn);
		pLn->addVertexAt(0,p[0],0,SizeAp1+WipeoutLength*2,SizeAp2+WipeoutLength*2);
		pLn->addVertexAt(1,p[1]);

	}//wipe





	if (This1D==false)
	{
		Gimme4PipePoints(FirstPoint,LastPoint);






		AcGePoint3d mass[4];
		mass[0]=A;
		mass[1]=B;
		mass[2]=C;
		mass[3]=D;
		AcDbPolyline*pl2=new AcDbPolyline;
		for (int i=0;i<4; i++)
		{
			pl2->addVertexAt(i,AcGePoint2d(mass[i].x,mass[i].y));
		}
		pl2->setClosed(true);
		setMainProperty(pl2);


		if ((ThisRoundp1==true)&&(ThisRoundp2==true))
		{
		
			AcDbLine*pl1=new AcDbLine(FirstPoint,LastPoint);
			setCenterProperty(pl1);
		}

		if ((ThisRoundp1==true)&&(ThisRoundp2==false))

		{
			AcDbPolyline*pl2=new AcDbPolyline;
		
			AcGePoint3d mass3[3];
			mass3[0]=B;
			mass3[1]=FirstPoint;
			mass3[2]=C;
			for (int i=0;i<3; i++)
			{
			pl2->addVertexAt(i,AcGePoint2d(mass3[i].x,mass3[i].y));
			}
		
	setCenterProperty(pl2);
		}
		if ((ThisRoundp1==false)&&(ThisRoundp2==true))
		{
			AcDbPolyline*pl2=new AcDbPolyline;
			AcGePoint3d mass4[3];
			mass4[0]=A;
			mass4[1]=LastPoint;
			mass4[2]=D;
			for (int i=0;i<3; i++)
			{
				pl2->addVertexAt(i,AcGePoint2d(mass4[i].x,mass4[i].y));
			}
			setCenterProperty(pl2);
		}

	} 
	else
	{

		double  Lx=VectTr.x;

		double  Ly=VectTr.y;


		double startangle=acos((1*Lx+0)/sqrt(Lx*Lx+Ly*Ly));
		if (Ly<0)
		{
			startangle=2*M_PI-startangle;
		}




		double check;
		if(SizeAp2<SizeAp1)
		{


			AcGePoint3d pA =AcGePoint3d(FirstPoint.x,
				prirost/2+FirstPoint.y,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);
			AcGePoint3d pB =AcGePoint3d(FirstPoint.x+prirost,
				FirstPoint.y,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);
			AcGePoint3d pC =AcGePoint3d(FirstPoint.x,
				FirstPoint.y-prirost/2,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);

			AcGePoint3d pD =AcGePoint3d(FirstPoint.x+LengthTr,
				FirstPoint.y,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);
		
			AcGePoint3d mass5[5];
			mass5[0]=pB;
			mass5[1]=pC;
			mass5[2]=pA;
			mass5[3]=pB;
			mass5[4]=pD;
			AcDbPolyline*pl2=new AcDbPolyline;
			for (int i=0;i<5; i++)
			{
				pl2->addVertexAt(i,AcGePoint2d(mass5[i].x,mass5[i].y));
			}
			setMainProperty(pl2);


		}


		else
		{

			AcGePoint3d pA =AcGePoint3d(FirstPoint.x+LengthTr,
				prirost/2+FirstPoint.y,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);
			AcGePoint3d pB =AcGePoint3d(FirstPoint.x-prirost+LengthTr,
				FirstPoint.y,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);
			AcGePoint3d pC =AcGePoint3d(FirstPoint.x+LengthTr,
				FirstPoint.y-prirost/2,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);
			AcGePoint3d pD =AcGePoint3d(FirstPoint.x,
				FirstPoint.y,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);

			AcGePoint3d mass5[5];
			mass5[0]=pB;
			mass5[1]=pC;
			mass5[2]=pA;
			mass5[3]=pB;
			mass5[4]=pD;
			AcDbPolyline*pl2=new AcDbPolyline;
			for (int i=0;i<5; i++)
			{
				pl2->addVertexAt(i,AcGePoint2d(mass5[i].x,mass5[i].y));
			}
			setMainProperty(pl2);

		}
	}




	for each (AcDbEntity * var in ListOfWipeout)
	{
		mode->geometry().draw(var);
	}


	for each (AcDbEntity * var in ListOfEntity)
	{
		mode->geometry().draw(var);
	}

	return Adesk::kTrue;
}


Adesk::UInt32 TVS_TRANS::subSetAttributes (AcGiDrawableTraits *traits) {
	assertReadEnabled () ;
	return (AcDbCurve::subSetAttributes (traits)) ;
}

//- Osnap points protocol
Acad::ErrorStatus TVS_TRANS::subGetOsnapPoints (
	AcDb::OsnapMode osnapMode,
	Adesk::GsMarker gsSelectionMark,
	const AcGePoint3d &pickPoint,
	const AcGePoint3d &lastPoint,
	const AcGeMatrix3d &viewXform,
	AcGePoint3dArray &snapPoints,
	AcDbIntArray &geomIds) const
{
	assertReadEnabled () ;
// 	AcGeLine3d line1,line2;
// 	line1.set(B,C); 
// 	line2.set(D,A); 
// 	switch (osnapMode) {
// 
// 	case AcDb::kOsModeEnd:
// 		snapPoints.append(FirstPoint);
// 		snapPoints.append(A);
// 		snapPoints.append(B);
// 		snapPoints.append(LastPoint);
// 		snapPoints.append(C);
// 		snapPoints.append(D);
// 
// 		break;
// 
// 	case AcDb::kOsModePerp: 
// 
// 		snapPoints.append(line1.closestPointTo(lastPoint));
// 		snapPoints.append(line2.closestPointTo(lastPoint));
// 		break;
// 	}


	Acad::ErrorStatus er;
	for each (AcDbEntity * var in ListOfEntity)
	{

		er=var->getOsnapPoints(osnapMode,gsSelectionMark,pickPoint,
			lastPoint,viewXform,snapPoints,geomIds);
		if (er!=Acad::eOk)
			return er;
	}
	return (Acad::eOk);
}

Acad::ErrorStatus TVS_TRANS::subGetOsnapPoints (
	AcDb::OsnapMode osnapMode,
	Adesk::GsMarker gsSelectionMark,
	const AcGePoint3d &pickPoint,
	const AcGePoint3d &lastPoint,
	const AcGeMatrix3d &viewXform,
	AcGePoint3dArray &snapPoints,
	AcDbIntArray &geomIds,
	const AcGeMatrix3d &insertionMat) const
{
	assertReadEnabled () ;
	return (AcDbCurve::subGetOsnapPoints (osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds, insertionMat)) ;
}

//- Grip points protocol
Acad::ErrorStatus TVS_TRANS::subGetGripPoints (
	AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds
	) const {
		assertReadEnabled () ;

		gripPoints.append(FirstPoint);
		gripPoints.append(LastPoint);


		//----- This method is never called unless you return eNotImplemented 
		//----- from the new getGripPoints() method below (which is the default implementation)
		return (Acad::eOk);
}

Acad::ErrorStatus TVS_TRANS::subMoveGripPointsAt (const AcDbIntArray &indices, const AcGeVector3d &offset) {
	assertWriteEnabled () ;
	assertWriteEnabled () ;
	//----- This method is never called unless you return eNotImplemented 
	//----- from the new moveGripPointsAt() method below (which is the default implementation)
	for(int i=0; i<indices.length(); i++)
	{
		int idx = indices.at(i);
		// For FP and center point

		if (idx==0 || idx==2) FirstPoint += offset;
		// For LP and center point
		if (idx==1 || idx==2) VectTr=AcGeVector3d(VectTr.x+offset.x,
			VectTr.y+offset.y,
			VectTr.z);

	}
	return (Acad::eOk);
}

Acad::ErrorStatus TVS_TRANS::subGetGripPoints (
	AcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, 
	const AcGeVector3d &curViewDir, const int bitflags
	) const {
		assertReadEnabled () ;

		//----- If you return eNotImplemented here, that will force AutoCAD to call
		//----- the older getGripPoints() implementation. The call below may return
		//----- eNotImplemented depending of your base class.
		return (AcDbCurve::subGetGripPoints (grips, curViewUnitSize, gripSize, curViewDir, bitflags)) ;
}

Acad::ErrorStatus TVS_TRANS::subMoveGripPointsAt (
	const AcDbVoidPtrArray &gripAppData, const AcGeVector3d &offset,
	const int bitflags
	) {
		assertWriteEnabled () ;

		//----- If you return eNotImplemented here, that will force AutoCAD to call
		//----- the older getGripPoints() implementation. The call below may return
		//----- eNotImplemented depending of your base class.
		return (AcDbCurve::subMoveGripPointsAt (gripAppData, offset, bitflags)) ;
}

//-----------------------------------------------------------------------------
//----- AcDbCurve protocols
//- Curve property tests.
Adesk::Boolean TVS_TRANS::isClosed () const {
	assertReadEnabled () ;
	return (AcDbCurve::isClosed ()) ;
}

Adesk::Boolean TVS_TRANS::isPeriodic () const {
	assertReadEnabled () ;
	return (AcDbCurve::isPeriodic ()) ;
}

//- Get planar and start/end geometric properties.
Acad::ErrorStatus TVS_TRANS::getStartParam (double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getStartParam (param)) ;
}

Acad::ErrorStatus TVS_TRANS::getEndParam (double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getEndParam (param)) ;
}

Acad::ErrorStatus TVS_TRANS::getStartPoint (AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getStartPoint (point)) ;
}

Acad::ErrorStatus TVS_TRANS::getEndPoint (AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getEndPoint (point)) ;
}

//- Conversions to/from parametric/world/distance.
Acad::ErrorStatus TVS_TRANS::getPointAtParam (double param, AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getPointAtParam (param, point)) ;
}

Acad::ErrorStatus TVS_TRANS::getParamAtPoint (const AcGePoint3d &point, double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getParamAtPoint (point, param)) ;
}

Acad::ErrorStatus TVS_TRANS::getDistAtParam (double param, double &dist) const {
	assertReadEnabled () ;
	return (AcDbCurve::getDistAtParam (param, dist)) ;
}

Acad::ErrorStatus TVS_TRANS::getParamAtDist (double dist, double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getParamAtDist (dist, param)) ;
}

Acad::ErrorStatus TVS_TRANS::getDistAtPoint (const AcGePoint3d &point , double &dist) const {
	assertReadEnabled () ;
	return (AcDbCurve::getDistAtPoint (point, dist)) ;
}

Acad::ErrorStatus TVS_TRANS::getPointAtDist (double dist, AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getPointAtDist (dist, point)) ;
}

//- Derivative information.
Acad::ErrorStatus TVS_TRANS::getFirstDeriv (double param, AcGeVector3d &firstDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getFirstDeriv (param, firstDeriv)) ;
}

Acad::ErrorStatus TVS_TRANS::getFirstDeriv  (const AcGePoint3d &point, AcGeVector3d &firstDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getFirstDeriv (point, firstDeriv)) ;
}

Acad::ErrorStatus TVS_TRANS::getSecondDeriv (double param, AcGeVector3d &secDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSecondDeriv (param, secDeriv)) ;
}

Acad::ErrorStatus TVS_TRANS::getSecondDeriv (const AcGePoint3d &point, AcGeVector3d &secDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSecondDeriv (point, secDeriv)) ;
}

//- Closest point on curve.
Acad::ErrorStatus TVS_TRANS::getClosestPointTo (const AcGePoint3d &givenPnt, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const {
	assertReadEnabled () ;
	return (AcDbCurve::getClosestPointTo (givenPnt, pointOnCurve, extend)) ;
}

Acad::ErrorStatus TVS_TRANS::getClosestPointTo (const AcGePoint3d &givenPnt, const AcGeVector3d &direction, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const {
	assertReadEnabled () ;
	return (AcDbCurve::getClosestPointTo (givenPnt, direction, pointOnCurve, extend)) ;
}

//- Get a projected copy of the curve.
Acad::ErrorStatus TVS_TRANS::getOrthoProjectedCurve (const AcGePlane &plane, AcDbCurve *&projCrv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOrthoProjectedCurve (plane, projCrv)) ;
}

Acad::ErrorStatus TVS_TRANS::getProjectedCurve (const AcGePlane &plane, const AcGeVector3d &projDir, AcDbCurve *&projCrv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getProjectedCurve (plane, projDir, projCrv)) ;
}

//- Get offset, spline and split copies of the curve.
Acad::ErrorStatus TVS_TRANS::getOffsetCurves (double offsetDist, AcDbVoidPtrArray &offsetCurves) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOffsetCurves (offsetDist, offsetCurves)) ;
}

Acad::ErrorStatus TVS_TRANS::getOffsetCurvesGivenPlaneNormal (const AcGeVector3d &normal, double offsetDist, AcDbVoidPtrArray &offsetCurves) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOffsetCurvesGivenPlaneNormal (normal, offsetDist, offsetCurves)) ;
}

Acad::ErrorStatus TVS_TRANS::getSpline (AcDbSpline *&spline) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSpline (spline)) ;
}

Acad::ErrorStatus TVS_TRANS::getSplitCurves (const AcGeDoubleArray &params, AcDbVoidPtrArray &curveSegments) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSplitCurves (params, curveSegments)) ;
}

Acad::ErrorStatus TVS_TRANS::getSplitCurves (const AcGePoint3dArray &points, AcDbVoidPtrArray &curveSegments) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSplitCurves (points, curveSegments)) ;
}

//- Extend the curve.
Acad::ErrorStatus TVS_TRANS::extend (double newParam) {
	assertReadEnabled () ;
	return (AcDbCurve::extend (newParam)) ;
}

Acad::ErrorStatus TVS_TRANS::extend (Adesk::Boolean extendStart, const AcGePoint3d &toPoint) {
	assertReadEnabled () ;
	return (AcDbCurve::extend (extendStart, toPoint)) ;
}

//- Area calculation.
Acad::ErrorStatus TVS_TRANS::getArea (double &area) const {
	assertReadEnabled () ;
	return (AcDbCurve::getArea (area)) ;
}

// -----------------------------------------------------------------------------
Acad::ErrorStatus TVS_TRANS::subExplode(AcDbVoidPtrArray & entitySet) const
{
	assertReadEnabled();




	if (This1D==false)
	{

		AcGePoint3d pMass[4];

		AcDbPolyline* pLine1 = new AcDbPolyline(4);



		AcGePoint2d mass[4];

		mass[0]=AcGePoint2d(A.x,A.y);
		mass[1]=AcGePoint2d(B.x,B.y);
		mass[2]=AcGePoint2d(C.x,C.y);
		mass[3]=AcGePoint2d(D.x,D.y);
		for (int i=0;i<4; i++)
		{
			pLine1->addVertexAt(i,mass[i]);
		}

		pLine1->setLineWeight(this->lineWeight());
		pLine1->setLayer(this->layerId());
		pLine1->setColor(this->color());
		pLine1->setLinetype(this->linetypeId());
		pLine1->setClosed(true);
		pLine1->setLinetypeScale(this->linetypeScale());
		entitySet.append(pLine1);



		if ((ThisRoundp1==true)&&(ThisRoundp2==true))
		{
			AcDbLine* pLine2 = new AcDbLine;
			pLine2->setStartPoint(FirstPoint);
			pLine2->setEndPoint(LastPoint);
			AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
			AcDbLinetypeTable *pLtTable;
			AcDbObjectId ltId;
			pDb->getSymbolTable(pLtTable, AcDb::kForRead);
			pLtTable->getAt(_T("tvs_centerline"), ltId);
			pLtTable->close();
			pLine2->setLineWeight(AcDb::LineWeight(15));
			pLine2->setLayer(this->layerId());
			pLine2->setLinetype(ltId);
			pLine2->setColor(this->color());
			entitySet.append(pLine2);




		}

		if ((ThisRoundp1==true)&&(ThisRoundp2==false))

		{
			AcDbPolyline* pLine3 = new AcDbPolyline(3);
			AcGePoint2d mass3[3];
			mass3[0]=AcGePoint2d(B.x,B.y);
			mass3[1]=AcGePoint2d(FirstPoint.x,FirstPoint.y);
			mass3[2]=AcGePoint2d(C.x,C.y);
			for (int i=0;i<3; i++)
			{
				pLine3->addVertexAt(i,mass3[i]);
			}

			pLine3->setLineWeight(AcDb::LineWeight(15));
			pLine3->setLayer(this->layerId());
			pLine3->setColor(this->color());
			pLine3->setLinetype(this->linetypeId());
			pLine3->setLinetypeScale(this->linetypeScale());
			entitySet.append(pLine3);
		}
		if ((ThisRoundp1==false)&&(ThisRoundp2==true))
		{
			AcDbPolyline* pLine4 = new AcDbPolyline(3);
			AcGePoint2d mass4[3];
			mass4[0]=AcGePoint2d(A.x,A.y);
			mass4[1]=AcGePoint2d(LastPoint.x,LastPoint.y);
			mass4[2]=AcGePoint2d(D.x,D.y);
			for (int i=0;i<3; i++)
			{
				pLine4->addVertexAt(i,mass4[i]);
			}

			pLine4->setLineWeight(AcDb::LineWeight(15));
			pLine4->setLayer(this->layerId());
			pLine4->setColor(this->color());
			pLine4->setLinetype(this->linetypeId());
			entitySet.append(pLine4);
		}

	} 
	else
	{

		double prirost=200;
		double  Lx=VectTr.x;

		double  Ly=VectTr.y;


		double startangle=acos((1*Lx+0)/sqrt(Lx*Lx+Ly*Ly));
		if (Ly<0)
		{
			startangle=2*M_PI-startangle;
		}



		AcGePoint3d mass5[5];
		double check;
		if(SizeAp2<SizeAp1)
		{


			AcGePoint3d pA =AcGePoint3d(FirstPoint.x,
				prirost/2+FirstPoint.y,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);
			AcGePoint3d pB =AcGePoint3d(FirstPoint.x+prirost,
				FirstPoint.y,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);
			AcGePoint3d pC =AcGePoint3d(FirstPoint.x,
				FirstPoint.y-prirost/2,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);

			AcGePoint3d pD =AcGePoint3d(FirstPoint.x+LengthTr,
				FirstPoint.y,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);


			mass5[0]=pB;
			mass5[1]=pC;
			mass5[2]=pA;
			mass5[3]=pB;
			mass5[4]=pD;


		}


		else
		{

			AcGePoint3d pA =AcGePoint3d(FirstPoint.x+LengthTr,
				prirost/2+FirstPoint.y,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);
			AcGePoint3d pB =AcGePoint3d(FirstPoint.x-prirost+LengthTr,
				FirstPoint.y,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);
			AcGePoint3d pC =AcGePoint3d(FirstPoint.x+LengthTr,
				FirstPoint.y-prirost/2,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);
			AcGePoint3d pD =AcGePoint3d(FirstPoint.x,
				FirstPoint.y,
				FirstPoint.z).rotateBy(startangle,AcGeVector3d(0,0,1),FirstPoint);


			mass5[0]=pB;
			mass5[1]=pC;
			mass5[2]=pA;
			mass5[3]=pB;
			mass5[4]=pD;


		}

		AcDbPolyline* pLine5=new AcDbPolyline;


		for (int i=0;i<5; i++)
		{
			pLine5->addVertexAt(i,AcGePoint2d(mass5[i].x,mass5[i].y));
		}

		pLine5->setLineWeight(this->lineWeight());
		pLine5->setLayer(this->layerId());
		pLine5->setColor(this->color());
		pLine5->setLinetype(this->linetypeId());
		pLine5->setClosed(false);
		pLine5->setLinetypeScale(this->linetypeScale());
		entitySet.append(pLine5);


	}












return Acad::eOk;
}

// -----------------------------------------------------------------------------
Acad::ErrorStatus TVS_TRANS::subTransformBy(const AcGeMatrix3d & xform)
{
	assertWriteEnabled () ;
	FirstPoint.transformBy(xform);
	LastPoint.transformBy(xform);
	VectTr.transformBy(xform);
	return (Acad::eOk);
}
TVS_TRANS *TVS_TRANS::add_new(
	double &pSizeAp1,
	double &pSizeBp1,
	double &pSizeAp2,
	double &pSizeBp2,
	double &pLengthTr,
	AcGeVector3d &pVectTr,
	AcGePoint3d &pFirstPoint,
	bool pThisRoundp1,
	bool pThisRoundp2,
	int pTransType,
	bool pThis1D
	)
{

	TVS_TRANS *pEnt = new TVS_TRANS();
	pEnt->SizeAp1=pSizeAp1;
	pEnt->SizeBp1=pSizeBp1;
	pEnt->SizeAp2=pSizeAp2;
	pEnt->SizeBp2=pSizeBp2;
	pEnt->LengthTr=pLengthTr;
	pEnt->VectTr=pVectTr;
	pEnt->FirstPoint=pFirstPoint;
	pEnt->ThisRoundp1=pThisRoundp1;
	pEnt->ThisRoundp2=pThisRoundp2;
	pEnt->TransType=pTransType;
	pEnt->This1D=pThis1D;
	pEnt->Flow=0;
	pEnt->Direct=0;
	pEnt->Elev=0;
	pEnt->Wipeout=false;
	pEnt->Param=0;
	pEnt->IsPipe=false;
	pEnt->Form=0;

	AcDbBlockTable *pBlockTable;
	pEnt->setLinetypeScale(acdbHostApplicationServices()->workingDatabase()->celtscale());
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable,
		AcDb::kForRead);

	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId retId = AcDbObjectId::kNull;
	pBlockTableRecord->appendAcDbEntity(retId, pEnt );
	pBlockTableRecord->close();
	pEnt ->close();
	return pEnt ;
}
void TVS_TRANS::Gimme4PipePoints (AcGePoint3d &m1,
								  AcGePoint3d &m2)
{

	double X1,X2,Y1,Y2,xv,yv;
	xv=VectTr.x;
	yv=VectTr.y;
	LengthTr=sqrt(xv*xv+yv*yv);
	X1=yv*SizeAp1/LengthTr/2;
	Y1=xv*SizeAp1/LengthTr/2;
	X2=yv*SizeAp2/LengthTr/2;
	Y2=xv*SizeAp2/LengthTr/2;
	A=AcGePoint3d(m1.x-X1,m1.y+Y1,m1.z);
	B=AcGePoint3d(m2.x-X2,m2.y+Y2,m2.z);
	C=AcGePoint3d(m2.x+X2,m2.y-Y2,m2.z);
	D=AcGePoint3d(m1.x+X1,m1.y-Y1,m1.z);
}


double TVS_TRANS::get_Length(void) const
{
	assertReadEnabled () ;
	return (LengthTr) ;
}

Acad::ErrorStatus TVS_TRANS::put_Length(double newVal)
{
	assertWriteEnabled () ;
	AcGeVector3d normi=VectTr;
	normi.normalize();

	VectTr=AcGeVector3d(normi.x*newVal,normi.y*newVal,VectTr.z);
	LengthTr=newVal;
	return (Acad::eOk) ;
}




double TVS_TRANS::get_SizeAp1(void) const
{
	assertReadEnabled () ;
	return (SizeAp1) ;
}

Acad::ErrorStatus TVS_TRANS::put_SizeAp1(double newVal)
{
	assertWriteEnabled () ;
	SizeAp1 =newVal ;
	return (Acad::eOk) ;
}
double TVS_TRANS::get_SizeBp1(void) const
{
	assertReadEnabled () ;
	return (SizeBp1) ;
}

Acad::ErrorStatus TVS_TRANS::put_SizeBp1(double newVal)
{
	assertWriteEnabled () ;
	SizeBp1 =newVal ;
	if (newVal==0)ThisRoundp1=true;
	else ThisRoundp1=false;
	return (Acad::eOk) ;
}





double TVS_TRANS::get_SizeAp2(void) const
{
	assertReadEnabled () ;
	return (SizeAp2) ;
}

Acad::ErrorStatus TVS_TRANS::put_SizeAp2(double newVal)
{
	assertWriteEnabled () ;
	SizeAp2 =newVal ;
	return (Acad::eOk) ;
}
double TVS_TRANS::get_SizeBp2(void) const
{
	assertReadEnabled () ;
	return (SizeBp2) ;
}

Acad::ErrorStatus TVS_TRANS::put_SizeBp2(double newVal)
{
	assertWriteEnabled () ;
	SizeBp2 =newVal ;
	if (newVal==0)ThisRoundp2=true;
	else ThisRoundp2=false;
	return (Acad::eOk) ;
}





AcGeVector3d TVS_TRANS::get_VectTr(void) const
{
	assertReadEnabled () ;
	return (VectTr) ;
}

Acad::ErrorStatus TVS_TRANS::put_VectTr(AcGeVector3d newVal)
{
	assertWriteEnabled () ;
	VectTr =newVal ;
	return (Acad::eOk) ;
}


int TVS_TRANS::get_Type(void) const
{
	assertReadEnabled () ;
	return (TransType) ;
}

Acad::ErrorStatus TVS_TRANS::put_Type(int newVal)
{
	assertWriteEnabled () ;
	TransType=newVal ;
	return (Acad::eOk) ;
}
