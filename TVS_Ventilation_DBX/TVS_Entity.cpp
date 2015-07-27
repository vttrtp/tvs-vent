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
//----- TVS_Entity.cpp : Implementation of TVS_Entity
//-----------------------------------------------------------------------------

#include "StdAfx.h"
#include "TVS_Entity.h"

//-----------------------------------------------------------------------------
Adesk::UInt32 TVS_Entity::kCurrentVersionNumber =TVS_Version ;

//-----------------------------------------------------------------------------
ACRX_DXF_DEFINE_MEMBERS (
	TVS_Entity, AcDbCurve,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, 
	AcDbProxyEntity::kNoOperation, TVS_ENTITY,
TVSTVS_VENTILATION_DBXAPP
|Product Desc:     A description for your object
|Company:          Your company name
|WEB Address:      Your company WEB site address
)

//-----------------------------------------------------------------------------
TVS_Entity::TVS_Entity () : AcDbCurve () {
}

TVS_Entity::~TVS_Entity () {
}

//-----------------------------------------------------------------------------
//----- AcDbObject protocols
//- Dwg Filing protocol
Acad::ErrorStatus TVS_Entity::dwgOutFields (AcDbDwgFiler *pFiler) const {
	assertReadEnabled () ;
	//----- Save parent class information first.
	Acad::ErrorStatus es =AcDbCurve::dwgOutFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be saved first
	if ( (es =pFiler->writeUInt32 (TVS_Entity::kCurrentVersionNumber)) != Acad::eOk )
		return (es) ;
	//----- Output params
	//.....

	return (pFiler->filerStatus ()) ;
}

Acad::ErrorStatus TVS_Entity::dwgInFields (AcDbDwgFiler *pFiler) {
	assertWriteEnabled () ;
	//----- Read parent class information first.
	Acad::ErrorStatus es =AcDbCurve::dwgInFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be read first
	Adesk::UInt32 version =TVS_Version ;
	if ( (es =pFiler->readUInt32 (&version)) != Acad::eOk )
		return (es) ;
	if ( version > TVS_Entity::kCurrentVersionNumber )
		return (Acad::eMakeMeProxy) ;
	//- Uncomment the 2 following lines if your current object implementation cannot
	//- support previous version of that object.
	//if ( version < TVS_Entity::kCurrentVersionNumber )
	//	return (Acad::eMakeMeProxy) ;
	//----- Read params
	//.....

	return (pFiler->filerStatus ()) ;
}

//- SubXXX() methods (self notification)
Acad::ErrorStatus TVS_Entity::subOpen (AcDb::OpenMode mode) {
	return (AcDbCurve::subOpen (mode)) ;
}

Acad::ErrorStatus TVS_Entity::subErase (Adesk::Boolean erasing) {
	return (AcDbCurve::subErase (erasing)) ;
}

Acad::ErrorStatus TVS_Entity::subCancel () {
	return (AcDbCurve::subCancel ()) ;
}

Acad::ErrorStatus TVS_Entity::subClose () {
	return (AcDbCurve::subClose ()) ;
}

//- Persistent reactor callbacks
void TVS_Entity::openedForModify (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::openedForModify (pDbObj) ;
}

void TVS_Entity::cancelled (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::cancelled (pDbObj) ;
}

void TVS_Entity::objectClosed (const AcDbObjectId objId) {
	assertReadEnabled () ;
	AcDbCurve::objectClosed (objId) ;
}

void TVS_Entity::goodbye (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::goodbye (pDbObj) ;
}

void TVS_Entity::copied (const AcDbObject *pDbObj, const AcDbObject *pNewObj) {
	assertReadEnabled () ;
	AcDbCurve::copied (pDbObj, pNewObj) ;
}

void TVS_Entity::erased (const AcDbObject *pDbObj, Adesk::Boolean bErasing) {
	assertReadEnabled () ;
	AcDbCurve::erased (pDbObj, bErasing) ;
}

void TVS_Entity::modified (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modified (pDbObj) ;
}

void TVS_Entity::modifiedGraphics (const AcDbEntity *pDbEnt) {
	assertReadEnabled () ;
	AcDbCurve::modifiedGraphics (pDbEnt) ;
}

void TVS_Entity::modifiedXData (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modifiedXData (pDbObj) ;
}

void TVS_Entity::subObjModified (const AcDbObject *pMainbObj, const AcDbObject *pSubObj) {
	assertReadEnabled () ;
	AcDbCurve::subObjModified (pMainbObj, pSubObj) ;
}

void TVS_Entity::modifyUndone (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modifyUndone (pDbObj) ;
}

void TVS_Entity::reappended (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::reappended (pDbObj) ;
}

void TVS_Entity::unappended (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::unappended (pDbObj) ;
}

//-----------------------------------------------------------------------------
//----- AcDbEntity protocols
Adesk::Boolean TVS_Entity::subWorldDraw (AcGiWorldDraw *mode) {
	assertReadEnabled () ;
	return (AcDbCurve::subWorldDraw (mode)) ;
}


Adesk::UInt32 TVS_Entity::subSetAttributes (AcGiDrawableTraits *traits) {
	assertReadEnabled () ;
	return (AcDbCurve::subSetAttributes (traits)) ;
}

	//- Osnap points protocol
Acad::ErrorStatus TVS_Entity::subGetOsnapPoints (
	AcDb::OsnapMode osnapMode,
	Adesk::GsMarker gsSelectionMark,
	const AcGePoint3d &pickPoint,
	const AcGePoint3d &lastPoint,
	const AcGeMatrix3d &viewXform,
	AcGePoint3dArray &snapPoints,
	AcDbIntArray &geomIds) const
{
	assertReadEnabled () ;
	return (AcDbCurve::subGetOsnapPoints (osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds)) ;
}

Acad::ErrorStatus TVS_Entity::subGetOsnapPoints (
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
Acad::ErrorStatus TVS_Entity::subGetGripPoints (
	AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds
) const {
	assertReadEnabled () ;
	//----- This method is never called unless you return eNotImplemented 
	//----- from the new getGripPoints() method below (which is the default implementation)

	return (AcDbCurve::subGetGripPoints (gripPoints, osnapModes, geomIds)) ;
}

Acad::ErrorStatus TVS_Entity::subMoveGripPointsAt (const AcDbIntArray &indices, const AcGeVector3d &offset) {
	assertWriteEnabled () ;
	//----- This method is never called unless you return eNotImplemented 
	//----- from the new moveGripPointsAt() method below (which is the default implementation)

	return (AcDbCurve::subMoveGripPointsAt (indices, offset)) ;
}

Acad::ErrorStatus TVS_Entity::subGetGripPoints (
	AcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, 
	const AcGeVector3d &curViewDir, const int bitflags
) const {
	assertReadEnabled () ;

	//----- If you return eNotImplemented here, that will force AutoCAD to call
	//----- the older getGripPoints() implementation. The call below may return
	//----- eNotImplemented depending of your base class.
	return (AcDbCurve::subGetGripPoints (grips, curViewUnitSize, gripSize, curViewDir, bitflags)) ;
}

Acad::ErrorStatus TVS_Entity::subMoveGripPointsAt (
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
Adesk::Boolean TVS_Entity::isClosed () const {
	assertReadEnabled () ;
	return (AcDbCurve::isClosed ()) ;
}

Adesk::Boolean TVS_Entity::isPeriodic () const {
	assertReadEnabled () ;
	return (AcDbCurve::isPeriodic ()) ;
}
      
//- Get planar and start/end geometric properties.
Acad::ErrorStatus TVS_Entity::getStartParam (double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getStartParam (param)) ;
}

Acad::ErrorStatus TVS_Entity::getEndParam (double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getEndParam (param)) ;
}

Acad::ErrorStatus TVS_Entity::getStartPoint (AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getStartPoint (point)) ;
}

Acad::ErrorStatus TVS_Entity::getEndPoint (AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getEndPoint (point)) ;
}

//- Conversions to/from parametric/world/distance.
Acad::ErrorStatus TVS_Entity::getPointAtParam (double param, AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getPointAtParam (param, point)) ;
}

Acad::ErrorStatus TVS_Entity::getParamAtPoint (const AcGePoint3d &point, double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getParamAtPoint (point, param)) ;
}

Acad::ErrorStatus TVS_Entity::getDistAtParam (double param, double &dist) const {
	assertReadEnabled () ;
	return (AcDbCurve::getDistAtParam (param, dist)) ;
}

Acad::ErrorStatus TVS_Entity::getParamAtDist (double dist, double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getParamAtDist (dist, param)) ;
}

Acad::ErrorStatus TVS_Entity::getDistAtPoint (const AcGePoint3d &point , double &dist) const {
	assertReadEnabled () ;
	return (AcDbCurve::getDistAtPoint (point, dist)) ;
}

Acad::ErrorStatus TVS_Entity::getPointAtDist (double dist, AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getPointAtDist (dist, point)) ;
}

//- Derivative information.
Acad::ErrorStatus TVS_Entity::getFirstDeriv (double param, AcGeVector3d &firstDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getFirstDeriv (param, firstDeriv)) ;
}

Acad::ErrorStatus TVS_Entity::getFirstDeriv  (const AcGePoint3d &point, AcGeVector3d &firstDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getFirstDeriv (point, firstDeriv)) ;
}

Acad::ErrorStatus TVS_Entity::getSecondDeriv (double param, AcGeVector3d &secDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSecondDeriv (param, secDeriv)) ;
}

Acad::ErrorStatus TVS_Entity::getSecondDeriv (const AcGePoint3d &point, AcGeVector3d &secDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSecondDeriv (point, secDeriv)) ;
}

//- Closest point on curve.
Acad::ErrorStatus TVS_Entity::getClosestPointTo (const AcGePoint3d &givenPnt, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const {
	assertReadEnabled () ;
	return (AcDbCurve::getClosestPointTo (givenPnt, pointOnCurve, extend)) ;
}

Acad::ErrorStatus TVS_Entity::getClosestPointTo (const AcGePoint3d &givenPnt, const AcGeVector3d &direction, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const {
	assertReadEnabled () ;
	return (AcDbCurve::getClosestPointTo (givenPnt, direction, pointOnCurve, extend)) ;
}

//- Get a projected copy of the curve.
Acad::ErrorStatus TVS_Entity::getOrthoProjectedCurve (const AcGePlane &plane, AcDbCurve *&projCrv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOrthoProjectedCurve (plane, projCrv)) ;
}

Acad::ErrorStatus TVS_Entity::getProjectedCurve (const AcGePlane &plane, const AcGeVector3d &projDir, AcDbCurve *&projCrv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getProjectedCurve (plane, projDir, projCrv)) ;
}

//- Get offset, spline and split copies of the curve.
Acad::ErrorStatus TVS_Entity::getOffsetCurves (double offsetDist, AcDbVoidPtrArray &offsetCurves) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOffsetCurves (offsetDist, offsetCurves)) ;
}

Acad::ErrorStatus TVS_Entity::getOffsetCurvesGivenPlaneNormal (const AcGeVector3d &normal, double offsetDist, AcDbVoidPtrArray &offsetCurves) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOffsetCurvesGivenPlaneNormal (normal, offsetDist, offsetCurves)) ;
}

Acad::ErrorStatus TVS_Entity::getSpline (AcDbSpline *&spline) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSpline (spline)) ;
}

Acad::ErrorStatus TVS_Entity::getSplitCurves (const AcGeDoubleArray &params, AcDbVoidPtrArray &curveSegments) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSplitCurves (params, curveSegments)) ;
}

Acad::ErrorStatus TVS_Entity::getSplitCurves (const AcGePoint3dArray &points, AcDbVoidPtrArray &curveSegments) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSplitCurves (points, curveSegments)) ;
}

//- Extend the curve.
Acad::ErrorStatus TVS_Entity::extend (double newParam) {
	assertReadEnabled () ;
	return (AcDbCurve::extend (newParam)) ;
}

Acad::ErrorStatus TVS_Entity::extend (Adesk::Boolean extendStart, const AcGePoint3d &toPoint) {
	assertReadEnabled () ;
	return (AcDbCurve::extend (extendStart, toPoint)) ;
}

//- Area calculation.
Acad::ErrorStatus TVS_Entity::getArea (double &area) const {
	assertReadEnabled () ;
	return (AcDbCurve::getArea (area)) ;
}

////////!!!!!!!!!!







double TVS_Entity::get_Axis(void) const
{
	assertReadEnabled () ;
	return (Axis) ;
}

Acad::ErrorStatus TVS_Entity::put_Axis(double newVal)
{
	assertWriteEnabled () ;
	Axis =newVal ;
	return (Acad::eOk) ;
}





double TVS_Entity::get_SizeA(void) const
{
	assertReadEnabled () ;
	return (SizeA) ;
}

Acad::ErrorStatus TVS_Entity::put_SizeA(double newVal)
{
	assertWriteEnabled () ;
	SizeA =newVal ;
	put_Elevation(Elev);
	return (Acad::eOk) ;
}
double TVS_Entity::get_SizeB(void) const
{
	assertReadEnabled () ;
	return (SizeB) ;
}

Acad::ErrorStatus TVS_Entity::put_SizeB(double newVal)
{
	assertWriteEnabled () ;
	SizeB =newVal ;
	if (newVal==0) ThisRound=true;
	else ThisRound=false;
	put_Elevation(Elev);
	return (Acad::eOk) ;
}

bool TVS_Entity::get_ThisRound(void) const
{
	assertReadEnabled () ;
	return (ThisRound) ;
}

Acad::ErrorStatus TVS_Entity::put_ThisRound (bool newVal)
{
	assertWriteEnabled () ;
	ThisRound =newVal ;
	return (Acad::eOk) ;
}
bool TVS_Entity::get_This1D(void) const
{
	assertReadEnabled () ;
	return (This1D) ;
}

Acad::ErrorStatus TVS_Entity::put_This1D (bool newVal)
{
	assertWriteEnabled () ;
	This1D =newVal ;
	return (Acad::eOk) ;
}





double TVS_Entity::get_Flow(void) const
{
	assertReadEnabled () ;
	return (Flow) ;
}

Acad::ErrorStatus TVS_Entity::put_Flow(double newVal)
{
	assertWriteEnabled () ;
	Flow =newVal ;
	return (Acad::eOk) ;
}



int TVS_Entity::get_Direct(void) const
{
	assertReadEnabled () ;
	return (Direct) ;
}

Acad::ErrorStatus TVS_Entity::put_Direct(int newVal)
{
	assertWriteEnabled () ;
	Direct =newVal ;
	return (Acad::eOk) ;
}

double TVS_Entity::get_Elevation(void) const
{
	assertReadEnabled () ;
	return (Elev) ;
}

Acad::ErrorStatus TVS_Entity::put_Elevation(double newVal)
{
	assertWriteEnabled () ;
	if (SizeB==0)
	{
		Elev =newVal ;
		ElevUp=newVal+SizeA/2;
		ElevDown=newVal-SizeA/2;
	}
	else
	{
		Elev =newVal ;
		ElevUp=newVal+SizeB/2;
		ElevDown=newVal-SizeB/2;
	}
	return (Acad::eOk) ;
}
bool TVS_Entity::get_Wipeout(void) const
{
	assertReadEnabled () ;
	return (Wipeout) ;
}

Acad::ErrorStatus TVS_Entity::put_Wipeout(bool newVal)
{
	assertWriteEnabled () ;
	Wipeout =newVal ;
	return (Acad::eOk) ;
}

int TVS_Entity::get_Param(void) const
{
	assertReadEnabled () ;
	return (Param) ;
}

Acad::ErrorStatus TVS_Entity::put_Param(int newVal)
{
	assertWriteEnabled () ;
	Param =newVal ;
	return (Acad::eOk) ;
}


//bool TVS_Entity::get_ShowText(void) const
//{
//	assertReadEnabled () ;
//	return (ShowText) ;
//}
//
//Acad::ErrorStatus TVS_Entity::put_ShowText(bool newVal)
//{
//	assertWriteEnabled () ;
//	Wipeout =newVal ;
//	return (Acad::eOk) ;
//}



bool TVS_Entity::get_Grani(void) const
{
	assertReadEnabled () ;
	return (Grani) ;
}

Acad::ErrorStatus TVS_Entity::put_Grani(bool newVal)
{
	assertWriteEnabled () ;
	Grani =newVal ;
	return (Acad::eOk) ;
}






double TVS_Entity::get_ElevUp(void) const
{
	assertReadEnabled () ;
	return (ElevUp) ;
}

Acad::ErrorStatus TVS_Entity::put_ElevUp(double newVal)
{
	assertWriteEnabled () ;
	if (SizeB==0)
	{
		ElevUp =newVal ;
		Elev=newVal-SizeA/2;
		ElevDown=newVal-SizeA;
	}
	else
	{
		ElevUp =newVal ;
		Elev=newVal-SizeB/2;
		ElevDown=newVal-SizeB;
	}
	return (Acad::eOk) ;
}


double TVS_Entity::get_ElevDown(void) const
{
	assertReadEnabled () ;
	return (ElevDown) ;
}

Acad::ErrorStatus TVS_Entity::put_ElevDown(double newVal)
{
	assertWriteEnabled () ;
	if (SizeB==0)
	{
		ElevUp =newVal+SizeA ;
		Elev=newVal+SizeA/2;
		ElevDown=newVal;
	}
	else
	{
		ElevUp =newVal+SizeB ;
		Elev=newVal+SizeB/2;
		ElevDown=newVal;

	}
	return (Acad::eOk) ;
}


TCHAR * TVS_Entity::get_Tag1(void) const
{
	assertReadEnabled () ;
	return (Tag1) ;
}

Acad::ErrorStatus TVS_Entity::put_Tag1(TCHAR * newVal)
{
	assertWriteEnabled () ;
	acutDelString(Tag1);
	Tag1 = NULL;

	if(newVal != NULL)
	{
		acutUpdString(newVal, Tag1);
	}

	return Acad::eOk;
}

TCHAR * TVS_Entity::get_Tag2(void) const
{
	assertReadEnabled () ;
	return (Tag2) ;
}

Acad::ErrorStatus TVS_Entity::put_Tag2(TCHAR * newVal)
{
	assertWriteEnabled () ;
	acutDelString(Tag2);
	Tag2 = NULL;

	if(newVal != NULL)
	{
		acutUpdString(newVal, Tag2);
	}

	return Acad::eOk;
}

void TVS_Entity::get_WipeoutColor(AcGiWorldDraw *mode, AcCmColor &backcolor) const
{
	//////
	AcColorSettings pAcadColors;   
	acedGetCurrentColors(&pAcadColors);   
	UINT32 backcolorDW= pAcadColors.dwGfxModelBkColor;   

	


	///////



	if(!mode->context()->isPlotGeneration()){ 
		   
		backcolor.setColorMethod(AcCmEntityColor::kByColor);
		backcolor.setRGB( GetRValue(backcolorDW),(backcolorDW & 0x00FF0000) >> 16,GetBValue(backcolorDW) ); 

	}else{ 
		
		backcolor.setColorMethod(AcCmEntityColor::kByColor);   
		backcolor.setRGB( GetRValue(backcolorDW),(backcolorDW & 0x00FF0000) >> 16,GetBValue(backcolorDW) ); 
	} 
}

int TVS_Entity::get_Form(void) const
{
	return Form;
}

Acad::ErrorStatus TVS_Entity::put_Form(int newVal)
{
	assertWriteEnabled () ;
	Form=newVal;
	return Acad::eOk;
}

void TVS_Entity::setMainProperty(AcDbEntity *pEnt)
{
	pEnt->setLineWeight(this->lineWeight());
	pEnt->setLayer(this->layerId());
	pEnt->setColor(this->color());
	pEnt->setLinetype(this->linetypeId());
	pEnt->setLinetypeScale(this->linetypeScale());
	ListOfEntity.append(pEnt);
}

void TVS_Entity::setAxisProperty(AcDbEntity *pEnt)
{
	AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
	AcDbLinetypeTable *pLtTable;
	AcDbObjectId ltId;
	pDb->getSymbolTable(pLtTable, AcDb::kForRead);
	pLtTable->getAt(_T("tvs_centerline"), ltId);

	pLtTable->close();
	pEnt->setLineWeight(AcDb::LineWeight(15));
	pEnt->setLayer(this->layerId());
	pEnt->setLinetype(ltId);
	pEnt->setColor(this->color());
	ListOfEntity.append(pEnt);
}

void TVS_Entity::setHideProperty(AcDbEntity *pEnt)
{
	AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
	AcDbLinetypeTable *pLtTable;
	AcDbObjectId ltId;
	pDb->getSymbolTable(pLtTable, AcDb::kForRead);
	pLtTable->getAt(_T("tvs_hidden"), ltId);

	pLtTable->close();
	pEnt->setLineWeight(AcDb::LineWeight(15));
	pEnt->setLayer(this->layerId());
	pEnt->setLinetype(ltId);
	pEnt->setColor(this->color());
	ListOfEntity.append(pEnt);
}

void TVS_Entity::setWipeoutProperty(AcGiWorldDraw *mode, AcDbPolyline *pEnt)
{

	//////
	AcColorSettings pAcadColors;   
	acedGetCurrentColors(&pAcadColors);   
	UINT32 backcolorDW= pAcadColors.dwGfxModelBkColor;   




	///////

	AcCmColor backcolor;

	if(!mode->context()->isPlotGeneration()){ 

		backcolor.setColorMethod(AcCmEntityColor::kByColor);
		backcolor.setRGB( GetRValue(backcolorDW),(backcolorDW & 0x00FF0000) >> 16,GetBValue(backcolorDW) ); 

	}else{ 

		backcolor.setColorMethod(AcCmEntityColor::kByColor);   
		backcolor.setRGB( GetRValue(backcolorDW),(backcolorDW & 0x00FF0000) >> 16,GetBValue(backcolorDW) ); 
	} 

	
	
	pEnt->setColor(backcolor);
	if (This1D==false) pEnt->setConstantWidth(SizeA+WipeoutLength*2);
	else pEnt->setConstantWidth(WipeoutLength*2);
	ListOfEntity.append(pEnt);
}


