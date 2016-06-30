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
//----- TVS_WYE.cpp : Implementation of TVS_WYE
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "TVS_WYE.h"
#include "TVS_Ventilation_DBX_i.h"
//-----------------------------------------------------------------------------
Adesk::UInt32 TVS_WYE::kCurrentVersionNumber =TVS_Version ;

//-----------------------------------------------------------------------------
ACRX_DXF_DEFINE_MEMBERS (
	TVS_WYE, TVS_Entity,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, 
	AcDbProxyEntity::kNoOperation, TVS_WYE,
TVSTVS_VENTILATION_DBXAPP
|Product Desc:     A description for your object
|Company:          Your company name
|WEB Address:      Your company WEB site address
)

//-----------------------------------------------------------------------------
TVS_WYE::TVS_WYE () : TVS_Entity () {
}

TVS_WYE::~TVS_WYE () {
}
Acad::ErrorStatus TVS_WYE::subGetClassID (CLSID *pClsid) const {
	assertReadEnabled () ;
	*pClsid=CLSID_ComWye;

	return (Acad::eOk) ;
}
//-----------------------------------------------------------------------------
//----- AcDbObject protocols
//- Dwg Filing protocol
Acad::ErrorStatus TVS_WYE::dwgOutFields (AcDbDwgFiler *pFiler) const {
	assertReadEnabled () ;
	//----- Save parent class information first.
	Acad::ErrorStatus es =AcDbCurve::dwgOutFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be saved first
	if ( (es =pFiler->writeUInt32 (TVS_WYE::kCurrentVersionNumber)) != Acad::eOk )
		return (es) ;
	//----- Output params
	//.....
	pFiler->writeItem (SizeApr) ;
	pFiler->writeItem (SizeBpr) ;
	pFiler->writeItem (SizeAotv) ;
	pFiler->writeItem (SizeBotv) ;
	pFiler->writeItem (LengthPl) ;
	pFiler->writeItem (Vectpr) ;
	pFiler->writeItem (Vectotv) ;
	pFiler->writeItem (Basepoint) ;
	pFiler->writeItem (ThisRoundpr) ;
	pFiler->writeItem (ThisRoundotv) ;
	pFiler->writeItem (This1D) ;
	pFiler->writeItem (Flow) ;
	pFiler->writeItem (Direct) ;
	pFiler->writeItem (Elev) ;
	pFiler->writeItem (Wipeout) ;
	pFiler->writeItem (Param) ;
	pFiler->writeItem (IsPipe) ;
	pFiler->writeItem (Form) ;
	pFiler->writeItem (WipeoutLength) ;
	pFiler->writeItem (DuctType) ;;
	return (pFiler->filerStatus ()) ;
}

Acad::ErrorStatus TVS_WYE::dwgInFields (AcDbDwgFiler *pFiler) {
	assertWriteEnabled () ;
	//----- Read parent class information first.
	Acad::ErrorStatus es =AcDbCurve::dwgInFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be read first
	Adesk::UInt32 version =TVS_Version ;
	if ( (es =pFiler->readUInt32 (&version)) != Acad::eOk )
		return (es) ;
	if ( version > TVS_WYE::kCurrentVersionNumber )
		return (Acad::eMakeMeProxy) ;
	//- Uncomment the 2 following lines if your current object implementation cannot
	//- support previous version of that object.
	//if ( version < TVS_WYE::kCurrentVersionNumber )
	//	return (Acad::eMakeMeProxy) ;
	//----- Read params
	//.....
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&SizeApr) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&SizeBpr) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&SizeAotv) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&SizeBotv) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&LengthPl) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&Vectpr) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&Vectotv) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&Basepoint);
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&ThisRoundpr) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&ThisRoundotv) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&This1D) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Flow) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Direct) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Elev) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Wipeout) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Param) ;
	if ( version >= 5 /*&& version <= endVersion*/ ) pFiler->readItem (&IsPipe) ;
	if ( version >= 21 /*&& version <= endVersion*/ ) pFiler->readItem (&Form) ;
	if ( version >= 23 /*&& version <= endVersion*/ ) pFiler->readItem (&WipeoutLength) ;	else WipeoutLength=50;
		
	if ( version >= 24 /*&& version <= endVersion*/ ) pFiler->readItem (&DuctType) ;	else DuctType=0;

	return (pFiler->filerStatus ()) ;
}

//- Persistent reactor callbacks
void TVS_WYE::openedForModify (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::openedForModify (pDbObj) ;
}

void TVS_WYE::cancelled (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::cancelled (pDbObj) ;
}

void TVS_WYE::objectClosed (const AcDbObjectId objId) {
	assertReadEnabled () ;
	AcDbCurve::objectClosed (objId) ;
}

void TVS_WYE::goodbye (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::goodbye (pDbObj) ;
}

void TVS_WYE::copied (const AcDbObject *pDbObj, const AcDbObject *pNewObj) {
	assertReadEnabled () ;
	AcDbCurve::copied (pDbObj, pNewObj) ;
}

void TVS_WYE::erased (const AcDbObject *pDbObj, Adesk::Boolean bErasing) {
	assertReadEnabled () ;
	AcDbCurve::erased (pDbObj, bErasing) ;
}

void TVS_WYE::modified (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modified (pDbObj) ;
}

void TVS_WYE::modifiedGraphics (const AcDbEntity *pDbEnt) {
	assertReadEnabled () ;
	AcDbCurve::modifiedGraphics (pDbEnt) ;
}

void TVS_WYE::modifiedXData (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modifiedXData (pDbObj) ;
}

void TVS_WYE::subObjModified (const AcDbObject *pMainbObj, const AcDbObject *pSubObj) {
	assertReadEnabled () ;
	AcDbCurve::subObjModified (pMainbObj, pSubObj) ;
}

void TVS_WYE::modifyUndone (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modifyUndone (pDbObj) ;
}

void TVS_WYE::reappended (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::reappended (pDbObj) ;
}

void TVS_WYE::unappended (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::unappended (pDbObj) ;
}

//-----------------------------------------------------------------------------
//----- AcDbEntity protocols
Adesk::Boolean TVS_WYE::subWorldDraw (AcGiWorldDraw *mode) {
	assertReadEnabled () ;
		ListOfEntity.removeAll();
		ListOfWipeout.removeAll();
	AcGePoint3d massforarray[2];
	AcGePoint3d massforarray2[8];



	Gimme7Points();
	if (Wipeout==true) //wipe
	{
	




		AcGePoint2d p[2];
		p[0]=AcGePoint2d(pA1.x,pA1.y);
		p[1]=AcGePoint2d(pA3.x,pA3.y);




		AcDbPolyline *pLn=new AcDbPolyline(2);





		pLn->addVertexAt(0,p[0]);
		pLn->addVertexAt(1,p[1]);

		setWipeoutProperty(mode,pLn);
	if (This1D==false) pLn->setConstantWidth(SizeApr+WipeoutLength*2);





		AcDbPolyline *pLn2=new AcDbPolyline(2);

	

		AcGePoint2d p2[2];
		p2[0]=AcGePoint2d(pMa.x,pMa.y);
		p2[1]=AcGePoint2d(pA5.x,pA5.y);

		pLn2->addVertexAt(0,p2[0]);
		pLn2->addVertexAt(1,p2[1]);

	setWipeoutProperty(mode,pLn2);
		if (This1D==false) pLn2->setConstantWidth(SizeAotv+WipeoutLength*2);





		

	}//wipe








	if (This1D==false)
	{









		massforarray2[0]=pA;
		massforarray2[1]=pB;
		massforarray2[2]=pC;
		massforarray2[3]=pD;
		massforarray2[4]=pE;
		massforarray2[5]=pF;
		massforarray2[6]=pG;
		massforarray2[7]=pH;

		AcDbPolyline*pLn=new AcDbPolyline;
		for (int i=0;i<8; i++)
		{
			pLn->addVertexAt(i,AcGePoint2d(massforarray2[i].x,massforarray2[i].y));
		}
		pLn->setClosed(true);
		setMainProperty(pLn);
		if (ThisRoundpr==true)//начало dпр-круглый
		{

			if (ThisRoundotv==true)//начало отв-круглый
			{
				AcGeVector3d normaleleps=AcGeVector3d(0,0,1);
				double startangle ,angle1,angle2;
				if(SizeApr==SizeAotv)
				{
					AcGePoint3d mass33[3];
					mass33[0]=pG;
					mass33[1]=Basepoint;
					mass33[2]=pD;
					AcDbPolyline*pLn2=new AcDbPolyline;
					for (int i=0;i<3; i++)
					{
						pLn2->addVertexAt(i,AcGePoint2d(mass33[i].x,mass33[i].y));
					}
					setMainProperty(pLn2);

				}
				else
				{
					double angle3;
					if (Vectpr.y>=0)
					{
						
						startangle=acos(Vectpr.x);
						
					} 
					else
					{

						startangle=M_PI*2-acos(Vectpr.x);
						
					
					}

					if ((Vectotv.x*Vectpr.y-Vectotv.y*Vectpr.x)<0)
					{
						angle1=M_PI;
						angle2=0;
					}
					else
					{
					angle1=0;
					angle2=M_PI;
					}
					double radiusratio=(SizeApr-sqrt(SizeApr*SizeApr-SizeAotv*SizeAotv))/SizeAotv;

					AcDbEllipse* el=new AcDbEllipse(pMa,AcGeVector3d(0,0,1),AcGeVector3d(SizeAotv/2,0,0),radiusratio,angle1,angle2);
					AcGeMatrix3d mat; 
					
					mat.setToRotation(startangle,AcGeVector3d(0,0,1),pMa); 
					el->transformBy(mat);
					setMainProperty(el);
	
				}
			
		
				massforarray[0]=pA1;
				massforarray[1]=pA3;
				AcDbLine *pLn1=new AcDbLine (massforarray[0],massforarray[1]);
				setCenterProperty(pLn1);

				massforarray[0]=Basepoint;
				massforarray[1]=pA5;
				AcDbLine * pLn2=new AcDbLine (massforarray[0],massforarray[1]);
				setCenterProperty(pLn2);
			} //конец отв-круглый
			else//начало пр-кругл отв-прямоуг
			{
				AcGePoint3d mass4[4];
				mass4[0]=pG;
				mass4[1]=pB1;
				mass4[2]=pB2;
				mass4[3]=pD;

				AcDbPolyline*pLn2=new AcDbPolyline;
				for (int i=0;i<4; i++)
				{
					pLn2->addVertexAt(i,AcGePoint2d(mass4[i].x,mass4[i].y));
				}
				setMainProperty(pLn2);

				

				massforarray[0]=pA1;
				massforarray[1]=pA3;
				AcDbLine * pLn3=new AcDbLine (massforarray[0],massforarray[1]);
				setCenterProperty(pLn3);
			}//конец пр-кругл отв-прямоуг


		} //конец dпр-круглый
		else//начало пр-прямоуг
		{
			massforarray[0]=pG;
			massforarray[1]=pD;
			AcDbLine * pLn2=new AcDbLine (massforarray[0],massforarray[1]);
			setMainProperty(pLn2);
			if (ThisRoundotv==true)
			{


				
				

				massforarray[0]=pMa;
				massforarray[1]=pA5;
				AcDbLine * pLn3=new AcDbLine (massforarray[0],massforarray[1]);
				setCenterProperty(pLn3);;
			}//конец пр-пр отв-кругл

		}//конец пр-прямоуг


	} //конец 2d
	else
	{

		massforarray[0]=pA1;
		massforarray[1]=pA3;
		AcDbLine * pLn4=new AcDbLine (massforarray[0],massforarray[1]);
		setMainProperty(pLn4);
		massforarray[0]=Basepoint;
		massforarray[1]=pA5;
		AcDbLine * pLn5=new AcDbLine (massforarray[0],massforarray[1]);
		setMainProperty(pLn5);

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


Adesk::UInt32 TVS_WYE::subSetAttributes (AcGiDrawableTraits *traits) {
	assertReadEnabled () ;
	return (AcDbCurve::subSetAttributes (traits)) ;
}

	//- Osnap points protocol
Acad::ErrorStatus TVS_WYE::subGetOsnapPoints (
	AcDb::OsnapMode osnapMode,
	Adesk::GsMarker gsSelectionMark,
	const AcGePoint3d &pickPoint,
	const AcGePoint3d &lastPoint,
	const AcGeMatrix3d &viewXform,
	AcGePoint3dArray &snapPoints,
	AcDbIntArray &geomIds) const
{
	assertReadEnabled () ;
// 	AcGeLine3d line1,line2, line3;
// 	line1.set(pA,pH); 
// 	line2.set(pB,pC); 
// 	line3.set(pE,pF); 
// 
// 	switch (osnapMode) {
// 
// 	case AcDb::kOsModeEnd:
// 		snapPoints.append(pA);
// 		snapPoints.append(pB);
// 		snapPoints.append(pC);
// 		snapPoints.append(pE);
// 		snapPoints.append(pF);
// 		snapPoints.append(pH);
// 		snapPoints.append(pA1);
// 		snapPoints.append(pA2);
// 		snapPoints.append(pA3);
// 		snapPoints.append(pA5);
// 
// 
// 		break;
// 
// 	case AcDb::kOsModePerp: 
// 
// 		snapPoints.append(line1.closestPointTo(lastPoint));
// 		snapPoints.append(line2.closestPointTo(lastPoint));
// 		snapPoints.append(line3.closestPointTo(lastPoint));
// 
// 		break;
// 
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

Acad::ErrorStatus TVS_WYE::subGetOsnapPoints (
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
Acad::ErrorStatus TVS_WYE::subGetGripPoints (
	AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds
) const {
	assertReadEnabled () ;

	gripPoints.append(Basepoint);
	gripPoints.append(pA1);
	gripPoints.append(pA3);
	gripPoints.append(pA5);


	//----- This method is never called unless you return eNotImplemented 
	//----- from the new getGripPoints() method below (which is the default implementation)
	return (Acad::eOk);
}

Acad::ErrorStatus TVS_WYE::subMoveGripPointsAt (const AcDbIntArray &indices, const AcGeVector3d &offset) {
	assertWriteEnabled () ;
	//----- This method is never called unless you return eNotImplemented 
	//----- from the new moveGripPointsAt() method below (which is the default implementation)
	for(int i=0; i<indices.length(); i++)
	{
		int idx = indices.at(i);
		// For FP and center point

		if (idx==0 || idx==2|| idx==1 || idx==3) Basepoint += offset;



	}
	return (Acad::eOk);
}

Acad::ErrorStatus TVS_WYE::subGetGripPoints (
	AcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, 
	const AcGeVector3d &curViewDir, const int bitflags
) const {
	assertReadEnabled () ;

	//----- If you return eNotImplemented here, that will force AutoCAD to call
	//----- the older getGripPoints() implementation. The call below may return
	//----- eNotImplemented depending of your base class.
	return (AcDbCurve::subGetGripPoints (grips, curViewUnitSize, gripSize, curViewDir, bitflags)) ;
}

Acad::ErrorStatus TVS_WYE::subMoveGripPointsAt (
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
Adesk::Boolean TVS_WYE::isClosed () const {
	assertReadEnabled () ;
	return (AcDbCurve::isClosed ()) ;
}

Adesk::Boolean TVS_WYE::isPeriodic () const {
	assertReadEnabled () ;
	return (AcDbCurve::isPeriodic ()) ;
}
      
//- Get planar and start/end geometric properties.
Acad::ErrorStatus TVS_WYE::getStartParam (double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getStartParam (param)) ;
}

Acad::ErrorStatus TVS_WYE::getEndParam (double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getEndParam (param)) ;
}

Acad::ErrorStatus TVS_WYE::getStartPoint (AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getStartPoint (point)) ;
}

Acad::ErrorStatus TVS_WYE::getEndPoint (AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getEndPoint (point)) ;
}

//- Conversions to/from parametric/world/distance.
Acad::ErrorStatus TVS_WYE::getPointAtParam (double param, AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getPointAtParam (param, point)) ;
}

Acad::ErrorStatus TVS_WYE::getParamAtPoint (const AcGePoint3d &point, double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getParamAtPoint (point, param)) ;
}

Acad::ErrorStatus TVS_WYE::getDistAtParam (double param, double &dist) const {
	assertReadEnabled () ;
	return (AcDbCurve::getDistAtParam (param, dist)) ;
}

Acad::ErrorStatus TVS_WYE::getParamAtDist (double dist, double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getParamAtDist (dist, param)) ;
}

Acad::ErrorStatus TVS_WYE::getDistAtPoint (const AcGePoint3d &point , double &dist) const {
	assertReadEnabled () ;
	return (AcDbCurve::getDistAtPoint (point, dist)) ;
}

Acad::ErrorStatus TVS_WYE::getPointAtDist (double dist, AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getPointAtDist (dist, point)) ;
}

//- Derivative information.
Acad::ErrorStatus TVS_WYE::getFirstDeriv (double param, AcGeVector3d &firstDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getFirstDeriv (param, firstDeriv)) ;
}

Acad::ErrorStatus TVS_WYE::getFirstDeriv  (const AcGePoint3d &point, AcGeVector3d &firstDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getFirstDeriv (point, firstDeriv)) ;
}

Acad::ErrorStatus TVS_WYE::getSecondDeriv (double param, AcGeVector3d &secDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSecondDeriv (param, secDeriv)) ;
}

Acad::ErrorStatus TVS_WYE::getSecondDeriv (const AcGePoint3d &point, AcGeVector3d &secDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSecondDeriv (point, secDeriv)) ;
}

//- Closest point on curve.
Acad::ErrorStatus TVS_WYE::getClosestPointTo (const AcGePoint3d &givenPnt, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const {
	assertReadEnabled () ;
	return (AcDbCurve::getClosestPointTo (givenPnt, pointOnCurve, extend)) ;
}

Acad::ErrorStatus TVS_WYE::getClosestPointTo (const AcGePoint3d &givenPnt, const AcGeVector3d &direction, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const {
	assertReadEnabled () ;
	return (AcDbCurve::getClosestPointTo (givenPnt, direction, pointOnCurve, extend)) ;
}

//- Get a projected copy of the curve.
Acad::ErrorStatus TVS_WYE::getOrthoProjectedCurve (const AcGePlane &plane, AcDbCurve *&projCrv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOrthoProjectedCurve (plane, projCrv)) ;
}

Acad::ErrorStatus TVS_WYE::getProjectedCurve (const AcGePlane &plane, const AcGeVector3d &projDir, AcDbCurve *&projCrv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getProjectedCurve (plane, projDir, projCrv)) ;
}

//- Get offset, spline and split copies of the curve.
Acad::ErrorStatus TVS_WYE::getOffsetCurves (double offsetDist, AcDbVoidPtrArray &offsetCurves) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOffsetCurves (offsetDist, offsetCurves)) ;
}

Acad::ErrorStatus TVS_WYE::getOffsetCurvesGivenPlaneNormal (const AcGeVector3d &normal, double offsetDist, AcDbVoidPtrArray &offsetCurves) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOffsetCurvesGivenPlaneNormal (normal, offsetDist, offsetCurves)) ;
}

Acad::ErrorStatus TVS_WYE::getSpline (AcDbSpline *&spline) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSpline (spline)) ;
}

Acad::ErrorStatus TVS_WYE::getSplitCurves (const AcGeDoubleArray &params, AcDbVoidPtrArray &curveSegments) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSplitCurves (params, curveSegments)) ;
}

Acad::ErrorStatus TVS_WYE::getSplitCurves (const AcGePoint3dArray &points, AcDbVoidPtrArray &curveSegments) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSplitCurves (points, curveSegments)) ;
}

//- Extend the curve.
Acad::ErrorStatus TVS_WYE::extend (double newParam) {
	assertReadEnabled () ;
	return (AcDbCurve::extend (newParam)) ;
}

Acad::ErrorStatus TVS_WYE::extend (Adesk::Boolean extendStart, const AcGePoint3d &toPoint) {
	assertReadEnabled () ;
	return (AcDbCurve::extend (extendStart, toPoint)) ;
}

//- Area calculation.
Acad::ErrorStatus TVS_WYE::getArea (double &area) const {
	assertReadEnabled () ;
	return (AcDbCurve::getArea (area)) ;
}





////////



// -----------------------------------------------------------------------------
Acad::ErrorStatus TVS_WYE::subTransformBy(const AcGeMatrix3d & xform)
{
	Acad::ErrorStatus retCode =AcDbEntity::subTransformBy (xform) ;
	assertWriteEnabled () ;
	Basepoint.transformBy(xform);
	Vectpr.transformBy(xform);
	Vectotv.transformBy(xform);


	return (Acad::eOk);
}

// -----------------------------------------------------------------------------
Acad::ErrorStatus TVS_WYE::subExplode(AcDbVoidPtrArray & entitySet) const
{
	assertReadEnabled();

	AcGePoint2d massforarray[2];
	AcGePoint2d massforarray2[8];
	if (This1D==false)
	{

		massforarray2[0]=AcGePoint2d(pA.x,pA.y);
		massforarray2[1]=AcGePoint2d(pB.x,pB.y);
		massforarray2[2]=AcGePoint2d(pC.x,pC.y);
		massforarray2[3]=AcGePoint2d(pD.x,pD.y);
		massforarray2[4]=AcGePoint2d(pE.x,pE.y);
		massforarray2[5]=AcGePoint2d(pF.x,pF.y);
		massforarray2[6]=AcGePoint2d(pG.x,pG.y);
		massforarray2[7]=AcGePoint2d(pH.x,pH.y);
		AcDbPolyline* pLine1 = new AcDbPolyline(8);
		for (int i=0;i<8; i++)
		{
			pLine1->addVertexAt(i,massforarray2[i]);
		}

		pLine1->setLineWeight(this->lineWeight());
		pLine1->setLayer(this->layerId());
		pLine1->setColor(this->color());
		pLine1->setLinetype(this->linetypeId());
		pLine1->setLinetypeScale(this->linetypeScale());
		pLine1->setClosed(true);
		entitySet.append(pLine1);



		if (ThisRoundpr==true)//начало dпр-круглый
		{

			if (ThisRoundotv==true)//начало отв-круглый
			{
				AcGeVector3d normaleleps=AcGeVector3d(0,0,1);
				double startangle,angle1,angle2;
				if(SizeApr==SizeAotv)
				{
					AcGePoint2d mass33[3];
					mass33[0]=AcGePoint2d(pG.x,pG.y);
					mass33[1]=AcGePoint2d(Basepoint.x,Basepoint.y);
					mass33[2]=AcGePoint2d(pD.x,pD.y);

					AcDbPolyline* pLine33 = new AcDbPolyline(3);
					for (int i=0;i<3; i++)
					{
						pLine33->addVertexAt(i,mass33[i]);
					}

					pLine33->setLineWeight(this->lineWeight());
					pLine33->setLayer(this->layerId());
					pLine33->setColor(this->color());
					pLine33->setLinetype(this->linetypeId());
					pLine33->setLinetypeScale(this->linetypeScale());
					entitySet.append(pLine33);



				}
				else
				{
					if (Vectotv.y>=0)
					{
						startangle=acos(Vectotv.x)+M_PI/2;
						angle1=0;
						angle2=M_PI;
					} 
					else
					{

						startangle=-acos(Vectotv.x)+M_PI/2;
						angle1=0;
						angle2=M_PI;
					}


					double radiusratio=(SizeApr/2-sqrt(SizeApr*SizeApr-SizeAotv*SizeAotv)/2)/(SizeAotv/2);
					AcDbEllipse* elllipse= new AcDbEllipse;
					AcGeVector3d majorvect=AcGeVector3d(cos(startangle)*SizeAotv/2,sin(startangle)*SizeAotv/2,0);






					elllipse->set(pMa,normaleleps,
						majorvect,
						radiusratio, 
						angle1,
						angle2);
					//elllipse->setStartParam(SizeAotv/2);
					//elllipse->setEndParam(SizeApr/2-sqrt(SizeApr*SizeApr-SizeAotv*SizeAotv)/2);
					elllipse->setLineWeight(this->lineWeight());
					elllipse->setLayer(this->layerId());
					elllipse->setColor(this->color());
					elllipse->setLinetype(this->linetypeId());
					elllipse->setLinetypeScale(this->linetypeScale());
					entitySet.append(elllipse);
				}
				AcDbLine* pLine22 = new AcDbLine;
				pLine22->setStartPoint(pA1);
				pLine22->setEndPoint(pA3);
				AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
				AcDbLinetypeTable *pLtTable;
				AcDbObjectId ltId;
				pDb->getSymbolTable(pLtTable, AcDb::kForRead);
				pLtTable->getAt(_T("tvs_centerline"), ltId);
				pLtTable->close();
				pLine22->setLineWeight(AcDb::LineWeight(15));
				pLine22->setLayer(this->layerId());
				pLine22->setLinetype(ltId);
				pLine22->setColor(this->color());
				entitySet.append(pLine22);



				AcDbLine* pLine3 = new AcDbLine;
				pLine3->setStartPoint(Basepoint);
				pLine3->setEndPoint(pA5);
				pLine3->setLineWeight(AcDb::LineWeight(15));
				pLine3->setLayer(this->layerId());
				pLine3->setLinetype(ltId);
				pLine3->setColor(this->color());
				entitySet.append(pLine3);


			} //конец отв-круглый
			else//начало пр-кругл отв-прямоуг
			{
				AcGePoint2d mass4[4];
				mass4[0]=AcGePoint2d(pG.x,pG.y);
				mass4[1]=AcGePoint2d(pB1.x,pB1.y);
				mass4[2]=AcGePoint2d(pB2.x,pB2.y);
				mass4[3]=AcGePoint2d(pD.x,pD.y);
				AcDbPolyline* pLine4 = new AcDbPolyline(4);
				for (int i=0;i<4; i++)
				{
					pLine4->addVertexAt(i,mass4[i]);
				}

				pLine4->setLineWeight(this->lineWeight());
				pLine4->setLayer(this->layerId());
				pLine4->setColor(this->color());
				pLine4->setLinetype(this->linetypeId());
				pLine4->setLinetypeScale(this->linetypeScale());
				entitySet.append(pLine4);



				AcDbLine* pLine5 = new AcDbLine;
				pLine5->setStartPoint(pA3);
				pLine5->setEndPoint(pA1);
				AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
				AcDbLinetypeTable *pLtTable;
				AcDbObjectId ltId;
				pDb->getSymbolTable(pLtTable, AcDb::kForRead);
				pLtTable->getAt(_T("tvs_centerline"), ltId);
				pLtTable->close();
				pLine5->setLineWeight(AcDb::LineWeight(15));
				pLine5->setLayer(this->layerId());
				pLine5->setLinetype(ltId);
				pLine5->setColor(this->color());
				entitySet.append(pLine5);



			}//конец пр-кругл отв-прямоуг


		} //конец dпр-круглый
		else//начало пр-прямоуг
		{
			AcDbLine* pLine6 = new AcDbLine;
			pLine6->setStartPoint(pG);
			pLine6->setEndPoint(pD);
			AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
			//AcDbLinetypeTable *pLtTable;
			AcDbObjectId ltId;
			pLine6->setLineWeight(this->lineWeight());
			pLine6->setLayer(this->layerId());
			pLine6->setColor(this->color());
			pLine6->setLinetype(this->linetypeId());
			pLine6->setLinetypeScale(this->linetypeScale());
			entitySet.append(pLine6);





			if (ThisRoundotv==true)
			{



				AcDbLine* pLine7 = new AcDbLine;
				pLine7->setStartPoint(pMa);
				pLine7->setEndPoint(pA5);
				AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
				AcDbLinetypeTable *pLtTable;
				AcDbObjectId ltId;
				pDb->getSymbolTable(pLtTable, AcDb::kForRead);
				pLtTable->getAt(_T("tvs_centerline"), ltId);
				pLtTable->close();
				pLine7->setLineWeight(AcDb::LineWeight(15));
				pLine7->setLayer(this->layerId());
				pLine7->setLinetype(ltId);
				pLine7->setColor(this->color());
				entitySet.append(pLine7);



			}//конец пр-пр отв-кругл

		}//конец пр-прямоуг


	} //конец 2d
	else
	{
		AcDbLine* pLine8 = new AcDbLine;
		pLine8->setStartPoint(pA1);
		pLine8->setEndPoint(pA3);
		pLine8->setLineWeight(this->lineWeight());
		pLine8->setLayer(this->layerId());
		pLine8->setColor(this->color());
		pLine8->setLinetype(this->linetypeId());
		pLine8->setLinetypeScale(this->linetypeScale());
		entitySet.append(pLine8);



		AcDbLine* pLine9 = new AcDbLine;
		pLine9->setStartPoint(Basepoint);
		pLine9->setEndPoint(pA5);
		pLine9->setLineWeight(this->lineWeight());
		pLine9->setLayer(this->layerId());
		pLine9->setColor(this->color());
		pLine9->setLinetype(this->linetypeId());
		pLine9->setLinetypeScale(this->linetypeScale());
		entitySet.append(pLine9);


	}




	return Acad::eOk;

}
TVS_WYE *TVS_WYE::add_new(
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
	bool pThis1D
	)
{


	TVS_WYE *pEnt = new TVS_WYE();
	pEnt->SizeApr=pSizeApr;
	pEnt->SizeBpr=pSizeBpr;
	pEnt->SizeAotv=pSizeAotv;
	pEnt->SizeBotv=pSizeBotv;
	pEnt->LengthPl=pLengthPl;
	pEnt->Vectpr=pVectpr;
	pEnt->Vectotv=pVectotv;
	pEnt->Basepoint=pBasepoint;
	pEnt->ThisRoundpr=pThisRoundpr;
	pEnt->ThisRoundotv=pThisRoundotv;
	pEnt->This1D=pThis1D;
	pEnt->Flow=0;
	pEnt->Direct=0;
	pEnt->Elev=0;
	pEnt->Wipeout=false;
	pEnt->Param=0;
	pEnt->IsPipe=false;
	pEnt->Form=0;
	pEnt->setNewParameters();
	pEnt->setLinetypeScale(acdbHostApplicationServices()->workingDatabase()->celtscale());

	AcDbBlockTable *pBlockTable;
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
void TVS_WYE::Gimme7Points()
{	  
	double plengtpr;
	plengtpr=LengthPl*2+SizeAotv;
	Vectotv.normalize();
	Vectpr.normalize();
	pA1=AcGePoint3d(Basepoint.x-Vectpr.x*plengtpr/2,
		Basepoint.y-Vectpr.y*plengtpr/2,
		Basepoint.z
		);
	pA2=AcGePoint3d(Basepoint.x-Vectotv.x*SizeApr/2,
		Basepoint.y-Vectotv.y*SizeApr/2,
		Basepoint.z
		);
	pA3=AcGePoint3d(Basepoint.x+Vectpr.x*plengtpr/2,
		Basepoint.y+Vectpr.y*plengtpr/2,
		Basepoint.z
		);
	pA5=AcGePoint3d(Basepoint.x+Vectotv.x*(SizeApr/2+LengthPl),
		Basepoint.y+Vectotv.y*(SizeApr/2+LengthPl),
		Basepoint.z
		);
	pA=AcGePoint3d(pA1.x-Vectotv.x*SizeApr/2,
		pA1.y-Vectotv.y*SizeApr/2,
		Basepoint.z
		);
	pH=AcGePoint3d(pA1.x+Vectotv.x*SizeApr/2,
		pA1.y+Vectotv.y*SizeApr/2,
		Basepoint.z
		);
	pB=AcGePoint3d(pA3.x-Vectotv.x*SizeApr/2,
		pA3.y-Vectotv.y*SizeApr/2,
		Basepoint.z
		);
	pC=AcGePoint3d(pA3.x+Vectotv.x*SizeApr/2,
		pA3.y+Vectotv.y*SizeApr/2,
		Basepoint.z
		);
	pD=AcGePoint3d(Basepoint.x+Vectotv.x*SizeApr/2+Vectpr.x*SizeAotv/2,
		Basepoint.y+Vectotv.y*SizeApr/2+Vectpr.y*SizeAotv/2,
		Basepoint.z
		);
	pE=AcGePoint3d((Basepoint.x+Vectotv.x*(SizeApr/2+LengthPl)+Vectpr.x*SizeAotv/2),
		Basepoint.y+Vectotv.y*(SizeApr/2+LengthPl)+Vectpr.y*SizeAotv/2,
		Basepoint.z
		);

	pF=AcGePoint3d(Basepoint.x+Vectotv.x*(SizeApr/2+LengthPl)-Vectpr.x*SizeAotv/2,
		Basepoint.y+Vectotv.y*(SizeApr/2+LengthPl)-Vectpr.y*SizeAotv/2,
		Basepoint.z
		);
	pG=AcGePoint3d(Basepoint.x+Vectotv.x*SizeApr/2-Vectpr.x*SizeAotv/2,
		Basepoint.y+Vectotv.y*SizeApr/2-Vectpr.y*SizeAotv/2,
		Basepoint.z
		);
	pMa=AcGePoint3d(Basepoint.x+Vectotv.x*(SizeApr/2),
		Basepoint.y+Vectotv.y*(SizeApr/2),
		Basepoint.z
		);
	pB1=AcGePoint3d(Basepoint.x-Vectpr.x*SizeAotv/2+Vectotv.x*(sqrt(SizeApr*SizeApr-SizeBotv*SizeBotv)/2),
		Basepoint.y-Vectpr.y*SizeAotv/2+Vectotv.y*(sqrt(SizeApr*SizeApr-SizeBotv*SizeBotv)/2),
		Basepoint.z
		);
	pB2=AcGePoint3d(Basepoint.x+Vectpr.x*SizeAotv/2+Vectotv.x*(sqrt(SizeApr*SizeApr-SizeBotv*SizeBotv)/2),
		Basepoint.y+Vectpr.y*SizeAotv/2+Vectotv.y*(sqrt(SizeApr*SizeApr-SizeBotv*SizeBotv)/2),
		Basepoint.z
		);
}


double TVS_WYE::get_Length(void) const
{
	assertReadEnabled () ;
	return (LengthPl) ;
}

Acad::ErrorStatus TVS_WYE::put_Length(double newVal)
{
	assertWriteEnabled () ;
	LengthPl =newVal ;
	return (Acad::eOk) ;
}




double TVS_WYE::get_SizeApr(void) const
{
	assertReadEnabled () ;
	return (SizeApr) ;
}

Acad::ErrorStatus TVS_WYE::put_SizeApr(double newVal)
{
	assertWriteEnabled () ;
	SizeApr =newVal ;
	return (Acad::eOk) ;
}
double TVS_WYE::get_SizeBpr(void) const
{
	assertReadEnabled () ;
	return (SizeBpr) ;
}

Acad::ErrorStatus TVS_WYE::put_SizeBpr(double newVal)
{
	assertWriteEnabled () ;
	SizeBpr =newVal ;
	if (newVal==0) ThisRoundpr=true;
	else ThisRoundpr=false;
	return (Acad::eOk) ;
}





double TVS_WYE::get_SizeAotv(void) const
{
	assertReadEnabled () ;
	return (SizeAotv) ;
}

Acad::ErrorStatus TVS_WYE::put_SizeAotv(double newVal)
{
	assertWriteEnabled () ;
	SizeAotv =newVal ;
	return (Acad::eOk) ;
}
double TVS_WYE::get_SizeBotv(void) const
{
	assertReadEnabled () ;
	return (SizeBotv) ;

}

Acad::ErrorStatus TVS_WYE::put_SizeBotv(double newVal)
{
	assertWriteEnabled () ;
	SizeBotv =newVal ;
	if (newVal==0) ThisRoundotv=true;
	else ThisRoundotv=false;
	return (Acad::eOk) ;
}





AcGeVector3d TVS_WYE::get_Vectpr(void) const
{
	assertReadEnabled () ;
	return (Vectpr) ;
}

Acad::ErrorStatus TVS_WYE::put_Vectpr(AcGeVector3d newVal)
{
	assertWriteEnabled () ;
	Vectpr =newVal ;
	return (Acad::eOk) ;
}

AcGeVector3d TVS_WYE::get_Vectotv(void) const
{
	assertReadEnabled () ;
	return (Vectotv) ;
}

Acad::ErrorStatus TVS_WYE::put_Vectotv(AcGeVector3d newVal)
{
	assertWriteEnabled () ;
	Vectotv =newVal ;
	return (Acad::eOk) ;
}

void TVS_WYE::setFlex( const bool &isFlex )
{
	assertWriteEnabled();
	if (isFlex)
	{
		put_SizeB(0);
	}

}

void TVS_WYE::setDuctType( int pDuctType )
{
	if (pDuctType==DuctTypeFlex)
	{
		DuctType=DuctTypeStill;
	}
}

