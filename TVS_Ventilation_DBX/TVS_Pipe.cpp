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
//----- TVS_Pipe.cpp : Implementation of TVS_Pipe
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "TVS_Pipe.h"
#include "TVS_Ventilation_DBX_i.h"
#include<vector>
//-----------------------------------------------------------------------------
Adesk::UInt32 TVS_Pipe::kCurrentVersionNumber =TVS_Version ;

//-----------------------------------------------------------------------------
ACRX_DXF_DEFINE_MEMBERS (
	TVS_Pipe, TVS_Entity,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, 
	AcDbProxyEntity::kNoOperation, TVS_PIPE,
TVSTVS_VENTILATION_DBXAPP
|Product Desc:     A description for your object
|Company:          Your company name
|WEB Address:      Your company WEB site address
)



appDataType TVS_Pipe::msAppData;
bool		TVS_Pipe::mbHover;
AcDbObjectId TVS_Pipe::mentId;



//-----------------------------------------------------------------------------
TVS_Pipe::TVS_Pipe () : TVS_Entity () {
}

TVS_Pipe::~TVS_Pipe () {
	ClearEntitylist();
}

int TVS_Pipe::gripNumber;
AcDbObjectId TVS_Pipe::entId;

void TVS_Pipe::GetParamsForDraw( AcDbObjectId &pEntId, int &pGripNumber )
{
	

		pEntId=entId;
 		pGripNumber=gripNumber;


	
}



//-----------------------------------------------------------------------------
//----- AcDbObject protocols
//- Dwg Filing protocol
Acad::ErrorStatus TVS_Pipe::dwgOutFields (AcDbDwgFiler *pFiler) const {
	assertReadEnabled () ;
	//----- Save parent class information first.
	Acad::ErrorStatus es =AcDbCurve::dwgOutFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be saved first
	if ( (es =pFiler->writeUInt32 (TVS_Pipe::kCurrentVersionNumber)) != Acad::eOk )
		return (es) ;
	//----- Output params
	//.....
	
	pFiler->writeItem (FirstPoint) ;
	pFiler->writeItem (LastPoint) ;
	pFiler->writeItem (SizeA) ;
	pFiler->writeItem (SizeB) ;
	pFiler->writeItem (This1D) ;
	pFiler->writeItem (ThisRound) ;
	pFiler->writeItem (Flow) ;
	pFiler->writeItem (Direct) ;
	pFiler->writeItem (Elev) ;
	pFiler->writeItem (Wipeout) ;
	pFiler->writeItem (Param) ;
	pFiler->writeItem (Grani) ;
	pFiler->writeItem (ElevUp) ;
	pFiler->writeItem (ElevDown) ;
	pFiler->writeItem (IsPipe) ;
	pFiler->writeItem (Form) ;
	pFiler->writeItem (WipeoutLength) ;
	pFiler->writeItem (DuctType) ;
	writeConnectors(pFiler);

	return (pFiler->filerStatus ()) ;
}

Acad::ErrorStatus TVS_Pipe::dwgInFields (AcDbDwgFiler *pFiler) {
	assertWriteEnabled () ;
	//----- Read parent class information first.
	Acad::ErrorStatus es =AcDbCurve::dwgInFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be read first
	Adesk::UInt32 version =TVS_Version ;
	if ( (es =pFiler->readUInt32 (&version)) != Acad::eOk )
		return (es) ;
	if ( version > TVS_Pipe::kCurrentVersionNumber )
		return (Acad::eMakeMeProxy) ;
	//- Uncomment the 2 following lines if your current object implementation cannot
	//- support previous version of that object.
	//if ( version < TVS_Pipe::kCurrentVersionNumber )
	//	return (Acad::eMakeMeProxy) ;
	//----- Read params
	//.....
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&FirstPoint) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&LastPoint) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&SizeA) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&SizeB) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&This1D) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&ThisRound) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Flow) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Direct) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Elev) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Wipeout) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Param) ;
	if ( version >= 3 /*&& version <= endVersion*/ ) pFiler->readItem (&Grani) ;
	if ( version >= 4 /*&& version <= endVersion*/ ) pFiler->readItem (&ElevUp) ;
	if ( version >= 4 /*&& version <= endVersion*/ ) pFiler->readItem (&ElevDown) ;
	if ( version >= 5 /*&& version <= endVersion*/ ) pFiler->readItem (&IsPipe) ;
	if ( version >= 21 /*&& version <= endVersion*/ ) pFiler->readItem (&Form) ;
	if ( version >= 23 /*&& version <= endVersion*/ ) pFiler->readItem (&WipeoutLength) ;	else WipeoutLength=50;
	if ( version >= 24 /*&& version <= endVersion*/ ) pFiler->readItem (&DuctType) ;	else DuctType=0;
	if ( version >= 23 /*&& version <= endVersion*/ ) pFiler->readItem (&WipeoutLength) ;	else WipeoutLength=50;
	if ( version >= 24 /*&& version <= endVersion*/ ) pFiler->readItem (&DuctType) ;	else DuctType=0;
	readConnectors(pFiler,version);

	return (pFiler->filerStatus ()) ;
}

//- SubXXX() methods (self notification)
Acad::ErrorStatus TVS_Pipe::subOpen (AcDb::OpenMode mode) {
	return (AcDbCurve::subOpen (mode)) ;
}



Acad::ErrorStatus TVS_Pipe::subCancel () {
	return (AcDbCurve::subCancel ()) ;
}

Acad::ErrorStatus TVS_Pipe::subClose () {
	return (AcDbCurve::subClose ()) ;
}

//- Persistent reactor callbacks
void TVS_Pipe::openedForModify (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::openedForModify (pDbObj) ;
}

void TVS_Pipe::cancelled (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::cancelled (pDbObj) ;
}

void TVS_Pipe::objectClosed (const AcDbObjectId objId) {
	assertReadEnabled () ;
	AcDbCurve::objectClosed (objId) ;
}

void TVS_Pipe::goodbye (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::goodbye (pDbObj) ;
}

void TVS_Pipe::copied (const AcDbObject *pDbObj, const AcDbObject *pNewObj) {
	assertReadEnabled () ;
	AcDbCurve::copied (pDbObj, pNewObj) ;
}

void TVS_Pipe::erased (const AcDbObject *pDbObj, Adesk::Boolean bErasing) {
	assertReadEnabled () ;
	AcDbCurve::erased (pDbObj, bErasing) ;
}

void TVS_Pipe::modified (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modified (pDbObj) ;
}

void TVS_Pipe::modifiedGraphics (const AcDbEntity *pDbEnt) {
	assertReadEnabled () ;
	AcDbCurve::modifiedGraphics (pDbEnt) ;
}

void TVS_Pipe::modifiedXData (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modifiedXData (pDbObj) ;
}

void TVS_Pipe::subObjModified (const AcDbObject *pMainbObj, const AcDbObject *pSubObj) {
	assertReadEnabled () ;
	AcDbCurve::subObjModified (pMainbObj, pSubObj) ;
}

void TVS_Pipe::modifyUndone (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modifyUndone (pDbObj) ;
}

void TVS_Pipe::reappended (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::reappended (pDbObj) ;
}

void TVS_Pipe::unappended (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::unappended (pDbObj) ;
}


//- Automation support
Acad::ErrorStatus TVS_Pipe::subGetClassID (CLSID *pClsid) const {
	//assertReadEnabled () ;
	*pClsid=CLSID_ComPipe;

	return (Acad::eOk) ;
	//return (AcDbEntity::subGetClassID (pClsid)) ;
}
//-----------------------------------------------------------------------------
//----- AcDbEntity protocols
Adesk::Boolean TVS_Pipe::subWorldDraw (AcGiWorldDraw *mode) {
	assertReadEnabled () ;
	ClearEntitylist();
	Length=(sqrt((FirstPoint.x-LastPoint.x)*(FirstPoint.x-LastPoint.x)+
		(FirstPoint.y-LastPoint.y)*
		(FirstPoint.y-LastPoint.y)));
	if (SizeB==0) ThisRound=true;
	else ThisRound=false;

	if (Wipeout==true)
	{

		AcGePoint2d p[2];
		p[0]=AcGePoint2d(FirstPoint.x,FirstPoint.y);
		p[1]=AcGePoint2d(LastPoint.x,LastPoint.y);


		AcDbPolyline*wPline=new AcDbPolyline(2);

		wPline->addVertexAt(0,p[0]);
		wPline->addVertexAt(1,p[1]);

setWipeoutProperty(mode,wPline);

	}

	if (This1D==false)
	{

		Gimme4PipePoints();

		if (Grani==true)
		{
			AcDbLine	*Line1 = new AcDbLine(A,D);
			AcDbLine	*Line2 = new AcDbLine(B,C);
			setMainProperty(Line1); setMainProperty(Line2);
		}
	

		
		AcDbLine	*Line1 = new AcDbLine(A,B);
		AcDbLine	*Line2 = new AcDbLine(D,C);
		if (DuctType==DuctTypeStill) {setMainProperty(Line1); setMainProperty(Line2);}
		if (DuctType==DuctTypeFlex) {setZigzagProperty(Line1); setZigzagProperty(Line2);}
		

		


		if (ThisRound==true)
		{

			AcDbLine*cLine = new AcDbLine(FirstPoint,LastPoint);
			setCenterProperty(cLine);
			
		}

	}


	else
	{
		AcGePoint3d L1[2];
		L1[0]=FirstPoint;
		L1[1]=LastPoint;
		AcDbLine * pLine=new AcDbLine(FirstPoint,LastPoint);
		if (DuctType==DuctTypeStill) {setMainProperty(pLine); }
		if (DuctType==DuctTypeFlex) {setZigzagProperty(pLine); }
		
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


Adesk::UInt32 TVS_Pipe::subSetAttributes (AcGiDrawableTraits *traits) {
	assertReadEnabled () ;
	return (AcDbCurve::subSetAttributes (traits)) ;
}

	//- Osnap points protocol
Acad::ErrorStatus TVS_Pipe::subGetOsnapPoints (
	AcDb::OsnapMode osnapMode,
	Adesk::GsMarker gsSelectionMark,
	const AcGePoint3d &pickPoint,
	const AcGePoint3d &lastPoint,
	const AcGeMatrix3d &viewXform,
	AcGePoint3dArray &snapPoints,
	AcDbIntArray &geomIds) const
{
	assertReadEnabled () ;

// 	AcGeLine3d line1, line2, line3; 
// 	line1.set(A,B); 
// 	line2.set(C,D); 
// 	line3.set(FirstPoint,LastPoint); 
// 
// 	switch (osnapMode) {
// 
// 	case AcDb::kOsModeEnd:
// 		snapPoints.append(FirstPoint);
// 		snapPoints.append(LastPoint);
// 		if (This1D==false)
// 		{
// 
// 			snapPoints.append(A);
// 			snapPoints.append(B);
// 			snapPoints.append(C);
// 			snapPoints.append(D);
// 		}
// 		break;
// 
// 	case AcDb::kOsModeMid:
// 		//	snapPoints.append(FirstPoint);
// 
// 		snapPoints.append(AcGePoint3d((FirstPoint.x+LastPoint.x)/2,
// 			(FirstPoint.y+LastPoint.y)/2,
// 			(FirstPoint.z+LastPoint.z)/2));
// 		if (This1D==false)
// 		{
// 			snapPoints.append(AcGePoint3d((A.x+B.x)/2,
// 				(A.y+B.y)/2,
// 				(A.z+B.z)/2));
// 			snapPoints.append(AcGePoint3d((C.x+D.x)/2,
// 				(C.y+D.y)/2,
// 				(C.z+D.z)/2));
// 
// 		}
// 
// 		break;
// 		//case AcDb::kOsModeEnd: 
// 		//	AcGeLine3d line1, line2; 
// 		//	line1.set(A,B); 
// 		//	line2.set(C,D); 
// 		//	snapPoints.append(line1.closestPointTo(pickPoint)); 
// 		//	snapPoints.append(line2.closestPointTo(pickPoint)); 
// 		//	break; 
// 
// 	case AcDb::kOsModeNear: 
// 		snapPoints.append(line3.closestPointTo(pickPoint));
// 		if (This1D==false)
// 		{
// 			snapPoints.append(line1.closestPointTo(pickPoint)); 
// 			snapPoints.append(line2.closestPointTo(pickPoint));
// 
// 		}
// 		break; 
// 
// 	case AcDb::kOsModePerp: 
// 
// 		snapPoints.append(line3.closestPointTo(lastPoint));
// 
// 		if (This1D==false)
// 		{
// 			snapPoints.append(line1.closestPointTo(lastPoint));
// 			snapPoints.append(line2.closestPointTo(lastPoint));
// 		}
// 		break; 
// 
// 		//case AcDb::kOsModeCen:
// 		//snapPoints.append(AcGePoint3d(LastPoint.x+(FirstPoint.x-LastPoint.x)/2,
// 		//	LastPoint.y+(FirstPoint.y-LastPoint.y)/2,0));
// 
// 		//snapPoints.append(A);
// 		//snapPoints.append(B);
// 		//snapPoints.append(C);
// 		//snapPoints.append(D);
// 
// 		//break;
// 		//case AcDb::kOsModeTan:
// 		//snapPoints.append(FirstPoint);
// 		//snapPoints.append(LastPoint);
// 		//snapPoints.append(A);
// 		//snapPoints.append(B);
// 		//snapPoints.append(C);
// 		//snapPoints.append(D);
// 
// 		//break;
// 
// 		//case AcDb::kOsModeMid:
// 		//	snapPoints.append(m_PtA+((m_PtAB-m_PtA).length()/2.0)*((m_PtAB-m_PtA).normalize()));
// 		//snapPoints.append(m_PtAB+((m_PtB-m_PtAB).length()/2.0)*((m_PtB-m_PtAB).normalize()));
// 		//snapPoints.append(m_PtB+((m_PtBA-m_PtB).length()/2.0)*((m_PtBA-m_PtB).normalize()));
// 		//snapPoints.append(m_PtBA+((m_PtA-m_PtBA).length()/2.0)*((m_PtA-m_PtBA).normalize()));
// 		//break;
// 
// 		//case AcDb::kOsModeCen:
// 		//snapPoints.append(AcGePoint3d((m_PtB.x+m_PtA.x)/2.0,
// 		//(m_PtB.y+m_PtA.y)/2.0, m_PtA.z));
// 		//break;
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
// switch (osnapMode) {
// 
// case AcDb::kOsModeEnd:
// 	snapPoints.append(FirstPoint);
// 	snapPoints.append(LastPoint);
// 	break;
// default:break;
// }

AcDbLine * pLine=new AcDbLine(FirstPoint,LastPoint);
	er=pLine->getOsnapPoints(osnapMode,gsSelectionMark,pickPoint,
	lastPoint,viewXform,snapPoints,geomIds);
	return (Acad::eOk);
}

Acad::ErrorStatus TVS_Pipe::subGetOsnapPoints (
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
Acad::ErrorStatus TVS_Pipe::subGetGripPoints (
	AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds
) const {
	assertReadEnabled () ;

	gripPoints.append(FirstPoint);
	gripPoints.append(LastPoint);
	gripPoints.append((AcGePoint3d (FirstPoint.x+LastPoint.x, 
		FirstPoint.y+LastPoint.y,FirstPoint.z+LastPoint.z))/2);
// 
// 
// 
// 	


	


	//----- This method is never called unless you return eNotImplemented 
	//----- from the new getGripPoints() method below (which is the default implementation)
	return (Acad::eOk);
	//return (AcDbEntity::subGetGripPoints (gripPoints, osnapModes, geomIds)) ;
}

void TVS_Pipe::SetParamsForDraw( AcDbObjectId pEntId, int pGripNumber )
{
	entId=pEntId;
	gripNumber=pGripNumber;
}

Acad::ErrorStatus TVS_Pipe::subMoveGripPointsAt (const AcDbIntArray &indices, const AcGeVector3d &offset) {
	assertWriteEnabled () ;
	//----- This method is never called unless you return eNotImplemented 
	//----- from the new moveGripPointsAt() method below (which is the default implementation)
	for(int i=0; i<indices.length(); i++)
	{
		int idx = indices.at(i);
		// For FP and center point

		if (idx==0 || idx==2) FirstPoint += offset;
		// For LP and center point
		if (idx==1 || idx==2) LastPoint += offset;

	}
	return (Acad::eOk);
	return (AcDbCurve::subMoveGripPointsAt (indices, offset)) ;
}





// appDataType::iterator 
// 	TVS_Pipe::putAppData()
// {
// 	if(msAppData.empty())
// 	{
// 		msAppData.reserve(GripCount);
// 		TSTDSTRING sAppData[GripCount]=
// 		{
// 			_T("Center")
// 		};
// 
// 		for(int i=0;i<GripCount;i++)
// 		{
// 			msAppData.push_back(sAppData[i]);
// 		}
// 	}
// 	return msAppData.begin();
// 
// }

Acad::ErrorStatus TVS_Pipe::subGetGripPoints (
	AcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, 
	const AcGeVector3d &curViewDir, const int bitflags
) const {
	//assertReadEnabled () ;

	//appDataType::iterator appIter = putAppData();
	int appIter=0;
	AcDbGripData* gpd=new AcDbGripData();
	//appDataType appIter;
	//All the GripData pointer are deallocated automatically
	AcDbGripData *pFirst = new AcDbGripData();

	AcDbGripData *pMid = new AcDbGripData();

	AcDbGripData *pEnd = new AcDbGripData();

	double k=1+10*curViewUnitSize / Length;



 //	pCenterCoordGrip->setToolTipFunc(GripCback::GripToolTipFunc);
	
  	//pCenterCoordGrip->setHotGripFunc(GripCback::hotGripfunc);

 // 	pCenterCoordGrip->setHoverFunc(GripCback::hoverGripfunc);
 // 	pCenterCoordGrip->setGripOpStatFunc(GripCback::OpStatusfunc);
 	//pCenterCoordGrip->setWorldDraw(GripCback::WorldDrawfunc);
 //	pCenterCoordGrip->setRtClk(GripCback::Rtclkfunc);
  //	pCenterCoordGrip->setGripOpStatFunc(GripCback::OpStatusfunc);


	AcDbGripData *pFirstGrip = new AcDbGripData();

	pFirstGrip->setGripPoint((AcGePoint3d ((1-k)*FirstPoint.x+k*LastPoint.x, 
		(1-k)*FirstPoint.y+k*LastPoint.y,(1-k)*FirstPoint.z+k*LastPoint.z)));
	pFirstGrip->setAppData((void*)101);
	pFirstGrip->setHotGripFunc(GripCback::hotGripfunc);
	pFirstGrip->setWorldDraw(GripCback::WorldDrawfunc);
	grips.append(pFirstGrip);	

	AcDbGripData *pLastGrip = new AcDbGripData();

	pLastGrip->setGripPoint((AcGePoint3d ((1-k)*LastPoint.x+k*FirstPoint.x, 
		(1-k)*LastPoint.y+k*FirstPoint.y,(1-k)*LastPoint.z+k*FirstPoint.z)));
	pLastGrip->setAppData((void*)102);
	pLastGrip->setHotGripFunc(GripCback::hotGripfunc);
	pLastGrip->setWorldDraw(GripCback::WorldDrawfunc);
	grips.append(pLastGrip);	


	pFirst->setGripPoint(FirstPoint);
	pFirst->setAppData((void*)appIter);
	grips.append(pFirst);
	appIter++;

	pEnd->setGripPoint(LastPoint);
		pEnd->setAppData((void*)appIter);
	grips.append(pEnd);
	appIter++;

	pMid->setGripPoint(((AcGePoint3d (FirstPoint.x+LastPoint.x, 
		FirstPoint.y+LastPoint.y,FirstPoint.z+LastPoint.z))/2));
		pMid->setAppData((void*)appIter);
	grips.append(pMid);
	appIter++;
	return Acad::eOk;
	//----- If you return eNotImplemented here, that will force AutoCAD to call
	//----- the older getGripPoints() implementation. The call below may return
	//----- eNotImplemented depending of your base class.
	//return (AcDbCurve::subGetGripPoints (grips, curViewUnitSize, gripSize, curViewDir, bitflags)) ;
}
// void TVS_Pipe::SetParamsForDraw(AcDbObjectId pEntId, int pGripNumber)
// {
// 	entId=pEntId;
// 	gripNumber=pGripNumber;
// 
// }
Acad::ErrorStatus TVS_Pipe::subMoveGripPointsAt (
	const AcDbVoidPtrArray &gripAppData, const AcGeVector3d &offset,
	const int bitflags
) {
	assertWriteEnabled () ;

	//----- If you return eNotImplemented here, that will force AutoCAD to call
	//----- the older getGripPoints() implementation. The call below may return
	//----- eNotImplemented depending of your base class.
	for(int i=0; i<gripAppData.length(); i++)
	{

		int idx = (int)gripAppData.at(i);
		// For FP and center point


		if (idx==0 || idx==2) FirstPoint += offset;
		// For LP and center point
		if (idx==1 || idx==2) LastPoint += offset;

		if (idx == 2)
		{
			int conStart;
			if (getConnectorByIndex(conPipeStart,conStart))
			{
				correctAnother(connectors[conStart],offset);
			}
			
			int conEnd;
			if (getConnectorByIndex(conPipeStart,conEnd))
			{
				correctAnother(connectors[conEnd],offset);
			}
		

		}
	}return eOk;
	return (AcDbCurve::subMoveGripPointsAt (gripAppData, offset, bitflags)) ;
}

//-----------------------------------------------------------------------------
//----- AcDbCurve protocols
//- Curve property tests.
Adesk::Boolean TVS_Pipe::isClosed () const {
	assertReadEnabled () ;
	return (AcDbCurve::isClosed ()) ;
}

Adesk::Boolean TVS_Pipe::isPeriodic () const {
	assertReadEnabled () ;
	return (AcDbCurve::isPeriodic ()) ;
}
      
//- Get planar and start/end geometric properties.
Acad::ErrorStatus TVS_Pipe::getStartParam (double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getStartParam (param)) ;
}

Acad::ErrorStatus TVS_Pipe::getEndParam (double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getEndParam (param)) ;
}

Acad::ErrorStatus TVS_Pipe::getStartPoint (AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getStartPoint (point)) ;
}

Acad::ErrorStatus TVS_Pipe::getEndPoint (AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getEndPoint (point)) ;
}

//- Conversions to/from parametric/world/distance.
Acad::ErrorStatus TVS_Pipe::getPointAtParam (double param, AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getPointAtParam (param, point)) ;
}

Acad::ErrorStatus TVS_Pipe::getParamAtPoint (const AcGePoint3d &point, double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getParamAtPoint (point, param)) ;
}

Acad::ErrorStatus TVS_Pipe::getDistAtParam (double param, double &dist) const {
	assertReadEnabled () ;
	return (AcDbCurve::getDistAtParam (param, dist)) ;
}

Acad::ErrorStatus TVS_Pipe::getParamAtDist (double dist, double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getParamAtDist (dist, param)) ;
}

Acad::ErrorStatus TVS_Pipe::getDistAtPoint (const AcGePoint3d &point , double &dist) const {
	assertReadEnabled () ;
	return (AcDbCurve::getDistAtPoint (point, dist)) ;
}

Acad::ErrorStatus TVS_Pipe::getPointAtDist (double dist, AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getPointAtDist (dist, point)) ;
}

//- Derivative information.
// Acad::ErrorStatus TVS_Pipe::getFirstDeriv (double param, AcGeVector3d &firstDeriv) const {
// 	assertReadEnabled () ;
// 	return (AcDbCurve::getFirstDeriv (param, firstDeriv)) ;
// }

// Acad::ErrorStatus TVS_Pipe::getFirstDeriv  (const AcGePoint3d &point, AcGeVector3d &firstDeriv) const {
// 	assertReadEnabled () ;
// 	return (AcDbCurve::getFirstDeriv (point, firstDeriv)) ;
// }

Acad::ErrorStatus TVS_Pipe::getSecondDeriv (double param, AcGeVector3d &secDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSecondDeriv (param, secDeriv)) ;
}

Acad::ErrorStatus TVS_Pipe::getSecondDeriv (const AcGePoint3d &point, AcGeVector3d &secDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSecondDeriv (point, secDeriv)) ;
}

//- Closest point on curve.
Acad::ErrorStatus TVS_Pipe::getClosestPointTo (const AcGePoint3d &givenPnt, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const {
	assertReadEnabled () ;
	return (AcDbCurve::getClosestPointTo (givenPnt, pointOnCurve, extend)) ;
}

Acad::ErrorStatus TVS_Pipe::getClosestPointTo (const AcGePoint3d &givenPnt, const AcGeVector3d &direction, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const {
	assertReadEnabled () ;
	return (AcDbCurve::getClosestPointTo (givenPnt, direction, pointOnCurve, extend)) ;
}

//- Get a projected copy of the curve.
Acad::ErrorStatus TVS_Pipe::getOrthoProjectedCurve (const AcGePlane &plane, AcDbCurve *&projCrv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOrthoProjectedCurve (plane, projCrv)) ;
}

Acad::ErrorStatus TVS_Pipe::getProjectedCurve (const AcGePlane &plane, const AcGeVector3d &projDir, AcDbCurve *&projCrv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getProjectedCurve (plane, projDir, projCrv)) ;
}

//- Get offset, spline and split copies of the curve.
Acad::ErrorStatus TVS_Pipe::getOffsetCurves (double offsetDist, AcDbVoidPtrArray &offsetCurves) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOffsetCurves (offsetDist, offsetCurves)) ;
}

Acad::ErrorStatus TVS_Pipe::getOffsetCurvesGivenPlaneNormal (const AcGeVector3d &normal, double offsetDist, AcDbVoidPtrArray &offsetCurves) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOffsetCurvesGivenPlaneNormal (normal, offsetDist, offsetCurves)) ;
}

Acad::ErrorStatus TVS_Pipe::getSpline (AcDbSpline *&spline) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSpline (spline)) ;
}

Acad::ErrorStatus TVS_Pipe::getSplitCurves (const AcGeDoubleArray &params, AcDbVoidPtrArray &curveSegments) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSplitCurves (params, curveSegments)) ;
}

Acad::ErrorStatus TVS_Pipe::getSplitCurves (const AcGePoint3dArray &points, AcDbVoidPtrArray &curveSegments) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSplitCurves (points, curveSegments)) ;
}

//- Extend the curve.
Acad::ErrorStatus TVS_Pipe::extend (double newParam) {
	assertReadEnabled () ;
	return (AcDbCurve::extend (newParam)) ;
}

Acad::ErrorStatus TVS_Pipe::extend (Adesk::Boolean extendStart, const AcGePoint3d &toPoint) {
	assertReadEnabled () ;
	return (AcDbCurve::extend (extendStart, toPoint)) ;
}

//- Area calculation.
Acad::ErrorStatus TVS_Pipe::getArea (double &area) const {
	assertReadEnabled () ;
	return (AcDbCurve::getArea (area)) ;
}




AcGePoint3d TVS_Pipe::get_FirstPoint(void) const
{
	assertReadEnabled () ;
	return (FirstPoint) ;
}

Acad::ErrorStatus TVS_Pipe::put_FirstPoint(AcGePoint3d newVal)
{
	assertWriteEnabled () ;
	FirstPoint =newVal ;
	return (Acad::eOk) ;
}



bool TVS_Pipe::correctConnector(const int &index,const AcGeVector3d &offset)
{
	TVS_Connector conStart;
	int ind;
	if(getConnectorByIndex(conPipeStart,ind))
	{
		conStart = connectors[ind];
	}
	TVS_Connector conEnd;
		if(getConnectorByIndex(conPipeEnd,ind))
		{
			conEnd = connectors[ind];
		}
	AcGeVector3d anotherOffset;

	anotherOffset = offset.orthoProject(((FirstPoint-LastPoint).normalize()));

	FirstPoint+=offset;
	LastPoint+=anotherOffset;
	if (index == conPipeStart)
	{
		correctAnother(conEnd,anotherOffset);
	}

	if (index == conPipeEnd)
	{
		correctAnother(conStart,anotherOffset);
	}
	conStart.point = FirstPoint;
	conEnd.point = LastPoint;
		return true;
}

void TVS_Pipe::Gimme4PipePoints ()
{
	double X1,X2,Y1,Y2;
	X1=LastPoint.x-FirstPoint.x;
	Y1=LastPoint.y-FirstPoint.y;

	X2=Y1*SizeA/Length/2;
	Y2=X1*SizeA/Length/2;
	A=AcGePoint3d(FirstPoint.x-X2,FirstPoint.y+Y2,FirstPoint.z);
	B=AcGePoint3d(LastPoint.x-X2,LastPoint.y+Y2,FirstPoint.z);
	C=AcGePoint3d(LastPoint.x+X2,LastPoint.y-Y2,FirstPoint.z);
	D=AcGePoint3d(FirstPoint.x+X2,FirstPoint.y-Y2,FirstPoint.z);

}

void TVS_Pipe::Gimme4PipePointsWipe ()
{
	double X1,X2,Y1,Y2;
	X1=LastPoint.x-FirstPoint.x;
	Y1=LastPoint.y-FirstPoint.y;

	X2=Y1*(SizeA+200)/Length/2;
	Y2=X1*(SizeA+200)/Length/2;
	//AW=AcGePoint3d(FirstPoint.x-X2,FirstPoint.y+Y2,FirstPoint.z);
	//BW=AcGePoint3d(LastPoint.x-X2,LastPoint.y+Y2,FirstPoint.z);
	//CW=AcGePoint3d(LastPoint.x+X2,LastPoint.y-Y2,FirstPoint.z);
	//DW=AcGePoint3d(FirstPoint.x+X2,FirstPoint.y-Y2,FirstPoint.z);
	AW=AcGePoint2d(FirstPoint.x-X2,FirstPoint.y+Y2);
	BW=AcGePoint2d(LastPoint.x-X2,LastPoint.y+Y2);
	CW=AcGePoint2d(LastPoint.x+X2,LastPoint.y-Y2);
	DW=AcGePoint2d(FirstPoint.x+X2,FirstPoint.y-Y2);
}

TVS_Pipe* TVS_Pipe::add_new(AcGePoint3d &pFirstPoint,
							AcGePoint3d &pLastPoint,
							double &pSizeA,
							double &pSizeB,
							bool pThis1d,
							bool pThisRound
							)
{
	TVS_Pipe *pEnt = new TVS_Pipe();
	pEnt->FirstPoint=pFirstPoint;
	pEnt->LastPoint=pLastPoint;
	pEnt->SizeA=pSizeA;
	pEnt->SizeB=pSizeB;
	pEnt->This1D=pThis1d;
	pEnt->ThisRound=pThisRound;
	pEnt->Flow=0;
	pEnt->Direct=0;
	pEnt->Elev=0;
	pEnt->Wipeout=false;
	pEnt->Param=0;
	pEnt->Grani=false;
	pEnt->ElevDown=0;
	pEnt->ElevUp=0;
	pEnt->IsPipe=false;
	pEnt->Form=0;
	pEnt->setNewParameters();
	//TCHAR * pPipe->Tag2=new TCHAR

	//pPipe->Tag2=ACRX_T("");
	pEnt->setLinetypeScale(acdbHostApplicationServices()->workingDatabase()->celtscale());
	//pPipe->ShowText=pShowText;
	//pPipe->SetText();
	// Post to Database
	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable,
		AcDb::kForRead);

	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId retId = AcDbObjectId::kNull;
	pBlockTableRecord->appendAcDbEntity(retId, pEnt);
	pBlockTableRecord->close();

	TVS_Connector conStart;
	conStart.connectionID = NULL;
	conStart.cTypeCurrent = conPipeStart;

	TVS_Connector conEnd;
	conEnd.connectionID = NULL;
	conEnd.cTypeCurrent = conPipeEnd;
	pEnt->connectors.resize(2);
	pEnt->connectors[0] = conStart;
	pEnt->connectors[1] = conEnd;

	pEnt->close();
	return pEnt;
}





// -----------------------------------------------------------------------------
Acad::ErrorStatus TVS_Pipe::subTransformBy(const AcGeMatrix3d & xform)
{
	assertWriteEnabled () ;

	FirstPoint.transformBy(xform);
	LastPoint.transformBy(xform);
	return (Acad::eOk);
}
void TVS_Pipe::setLastpoint (AcGePoint3d pLastpoint)
{
	LastPoint=pLastpoint;
}



void TVS_Pipe::setDuctType(int pDuctType)
{
	assertWriteEnabled();
	DuctType=pDuctType;
}

Acad::ErrorStatus TVS_Pipe::put_SizeB(double newVal)
{
	assertWriteEnabled () ;


	if (DuctType==DuctTypeStill)
	{

		if((ThisRound==true)&&(newVal!=0))
		{

			ThisRound=false;
			SizeB=newVal;
			return (Acad::eOk) ;

		}

		if((ThisRound==false)&&(newVal==0))
		{

			ThisRound=true;

			SizeB=newVal;
			return (Acad::eOk) ;

		}	




		SizeB =newVal ;

	}
	else
	{
		SizeB=0;
		ThisRound=true;
		SizeB=0;
	}
	return (Acad::eOk) ;
}

AcGePoint3d TVS_Pipe::getPointForSpline( AcGePoint3d &point, AcDbSpline * const &pspline, double const &dist )
{
	AcGeVector3d splinetangent;
	double param;

	pspline->getParamAtPoint(point,param);
	pspline->getFirstDeriv(param,splinetangent);
	splinetangent.normalize();
	splinetangent=splinetangent.rotateBy(M_PI/2,AcGeVector3d(0,0,1));
	splinetangent*=dist;
	return AcGePoint3d(point.x+splinetangent.x,point.y+splinetangent.y,0);
}

AcGePoint3dArray TVS_Pipe::getPointsForSpline( const int &quantity, AcDbSpline * const &pspline, double const &dist )
{
	AcGePoint3dArray arr;
	AcGePoint3d point;
	AcGeVector3d splinetangent;
		double param,splength;
		AcGePoint3d endp;
		pspline->getEndPoint(endp);
		pspline->getDistAtPoint(endp,splength);
		double startpar,endpar,step;
		pspline->getStartParam(startpar);
		pspline->getEndParam(endpar);
	
	for (int i=0;i<=quantity;i++)
	{
		param=(endpar-startpar)*i/quantity;
		//getParamAtDist(splength*i/quantity,param);
		pspline->getFirstDeriv(param,splinetangent);
		splinetangent.normalize();
		splinetangent=splinetangent.rotateBy(M_PI/2,AcGeVector3d(0,0,1));
		splinetangent*=dist;
		pspline->getPointAtParam(param,point);
		arr.append(AcGePoint3d(point.x+splinetangent.x,point.y+splinetangent.y,0));
	}
	return arr;
}

void TVS_Pipe::setFlex( const bool &isFlex )
{
	assertWriteEnabled();
	if (isFlex)
	{
		DuctType=DuctTypeFlex;
		put_SizeB(0);
	}
	else
	{
		DuctType=DuctTypeStill;
		
	}
	
}

// -----------------------------------------------------------------------------
Acad::ErrorStatus TVS_Pipe::subExplode(AcDbVoidPtrArray & entitySet) const
{

	assertReadEnabled();

	
	for each (AcDbEntity* var in ListOfEntity)
	{
		AcDbEntity* clonedEntity = (AcDbEntity*)var->clone();
		if(clonedEntity) entitySet.append(clonedEntity);
		//entitySet.append(var);
	}

	
	return Acad::eOk;

}

double TVS_Pipe::get_Length(void) const
{
	assertReadEnabled () ;
	return (Length) ;
}

AcGePoint3d TVS_Pipe::get_Lastpoint(void) const
{
	assertReadEnabled () ;
	return (LastPoint) ;
}

Acad::ErrorStatus TVS_Pipe::put_Lastpoint(AcGePoint3d newVal)
{
	assertWriteEnabled () ;
	LastPoint =newVal ;
	return (Acad::eOk) ;
}




Adesk::Boolean TVS_FlexDuct::subWorldDraw (AcGiWorldDraw *mode) {
		assertReadEnabled () ;
		AcGePoint3dArray arr, arr1, arr2;
		ListOfEntity.removeAll();
		ListOfWipeout.removeAll();
		arr.append(AcGePoint3d(FirstPoint));
		arr.append(AcGePoint3d(flexmidpoint));
		arr.append(AcGePoint3d(LastPoint));
		AcGeVector3d startvect=AcGeVector3d(1,0,0);
		AcGeVector3d endvect=AcGeVector3d(0,1,0);
		AcDbSpline * pEnt=new AcDbSpline(arr,startvect,endvect);
	
	
		double AParam, midParam, BParam;
		setCenterProperty(pEnt);
			ListOfEntity.append(pEnt);
		mode->geometry().draw(pEnt);


		AcGePoint3d A1, M1, B1, A2, M2, B2;

		/*A1=*/



// 
// 		A1=getPointForSpline(FirstPoint,pEnt,SizeA/2);
// 	
// 		M1=getPointForSpline(flexmidpoint,pEnt,SizeA/2);
// 	
// 		B1=getPointForSpline(LastPoint,pEnt,SizeA/2);
// 	
// 		arr1.append(A1);
// 		arr1.append(M1);
// 		arr1.append(B1);

		arr1=getPointsForSpline(100,pEnt,SizeA/2);
				AcDbSpline * pEnt1=new AcDbSpline(arr1,startvect,endvect);
				setMainProperty(pEnt1);
		ListOfEntity.append(pEnt1);
		mode->geometry().draw(pEnt1);



// 
// 		A2=getPointForSpline(FirstPoint,pEnt,-SizeA/2);
// 
// 		M2=getPointForSpline(flexmidpoint,pEnt,-SizeA/2);
// 
// 		B2=getPointForSpline(LastPoint,pEnt,-SizeA/2);
// 
// 		arr2.append(A2);
// 		arr2.append(M2);
// 		arr2.append(B2);
		arr2=getPointsForSpline(100,pEnt,-SizeA/2);
				AcDbSpline * pEnt2=new AcDbSpline(arr2,startvect,endvect);
		setMainProperty(pEnt2);
		ListOfEntity.append(pEnt2);
		mode->geometry().draw(pEnt2);

		return Adesk::kTrue;
}

Acad::ErrorStatus TVS_FlexDuct::subGetGripPoints( AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds ) const
{
	assertReadEnabled () ;

	gripPoints.append(FirstPoint);
	gripPoints.append(LastPoint);
	gripPoints.append(flexmidpoint);







	return (Acad::eOk);

}

Acad::ErrorStatus TVS_FlexDuct::subGetGripPoints( AcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, const AcGeVector3d &curViewDir, const int bitflags ) const
{
	//assertReadEnabled () ;

	//appDataType::iterator appIter = putAppData();
	int appIter=0;
	AcDbGripData* gpd=new AcDbGripData();
	//appDataType appIter;
	//All the GripData pointer are deallocated automatically
	AcDbGripData *pFirst = new AcDbGripData();

	AcDbGripData *pMid = new AcDbGripData();

	AcDbGripData *pEnd = new AcDbGripData();

	double k=1+10*curViewUnitSize / Length;



	//	pCenterCoordGrip->setToolTipFunc(GripCback::GripToolTipFunc);

	//pCenterCoordGrip->setHotGripFunc(GripCback::hotGripfunc);

	// 	pCenterCoordGrip->setHoverFunc(GripCback::hoverGripfunc);
	// 	pCenterCoordGrip->setGripOpStatFunc(GripCback::OpStatusfunc);
	//pCenterCoordGrip->setWorldDraw(GripCback::WorldDrawfunc);
	//	pCenterCoordGrip->setRtClk(GripCback::Rtclkfunc);
	//	pCenterCoordGrip->setGripOpStatFunc(GripCback::OpStatusfunc);


	AcDbGripData *pFirstGrip = new AcDbGripData();

	pFirstGrip->setGripPoint((AcGePoint3d ((1-k)*FirstPoint.x+k*LastPoint.x, 
		(1-k)*FirstPoint.y+k*LastPoint.y,(1-k)*FirstPoint.z+k*LastPoint.z)));
	pFirstGrip->setAppData((void*)101);
	pFirstGrip->setHotGripFunc(GripCback::hotGripfunc);
	pFirstGrip->setWorldDraw(GripCback::WorldDrawfunc);
	grips.append(pFirstGrip);	

	AcDbGripData *pLastGrip = new AcDbGripData();

	pLastGrip->setGripPoint((AcGePoint3d ((1-k)*LastPoint.x+k*FirstPoint.x, 
		(1-k)*LastPoint.y+k*FirstPoint.y,(1-k)*LastPoint.z+k*FirstPoint.z)));
	pLastGrip->setAppData((void*)102);
	pLastGrip->setHotGripFunc(GripCback::hotGripfunc);
	pLastGrip->setWorldDraw(GripCback::WorldDrawfunc);
	grips.append(pLastGrip);	


	pFirst->setGripPoint(FirstPoint);
	pFirst->setAppData((void*)appIter);
	grips.append(pFirst);
	appIter++;

	pEnd->setGripPoint(LastPoint);
	pEnd->setAppData((void*)appIter);
	grips.append(pEnd);
	appIter++;

	pMid->setGripPoint(flexmidpoint);
	pMid->setAppData((void*)appIter);
	grips.append(pMid);
	appIter++;
	return Acad::eOk;
}

Acad::ErrorStatus TVS_FlexDuct::subMoveGripPointsAt( const AcDbIntArray &indices, const AcGeVector3d &offset )
{
	assertWriteEnabled () ;
	//----- This method is never called unless you return eNotImplemented 
	//----- from the new moveGripPointsAt() method below (which is the default implementation)
	for(int i=0; i<indices.length(); i++)
	{
		int idx = indices.at(i);
		// For FP and center point

		if (idx==0 ) FirstPoint += offset;
		// For LP and center point
		if (idx==1 ) LastPoint += offset;
		if (idx==2) flexmidpoint += offset;

	}
	//return (Acad::eOk);
	return (AcDbCurve::subMoveGripPointsAt (indices, offset)) ;
}

Acad::ErrorStatus TVS_FlexDuct::subMoveGripPointsAt( const AcDbVoidPtrArray &gripAppData, const AcGeVector3d &offset, const int bitflags )
{
	assertWriteEnabled () ;

	//----- If you return eNotImplemented here, that will force AutoCAD to call
	//----- the older getGripPoints() implementation. The call below may return
	//----- eNotImplemented depending of your base class.
	for(int i=0; i<gripAppData.length(); i++)
	{

		int idx = (int)gripAppData.at(i);
		// For FP and center point


		if (idx==0 ) FirstPoint += offset;
		// For LP and center point
		if (idx==1 ) LastPoint += offset;
		if (idx==2 ) flexmidpoint += offset;
	}return eOk;
	return (AcDbCurve::subMoveGripPointsAt (gripAppData, offset, bitflags)) ;
}

void TVS_FlexDuct::addfilerparam( AcDbDwgFiler *pFiler )
{
	pFiler->writeItem (flexmidpoint) ;
}

void TVS_FlexDuct::getfilerparam( AcDbDwgFiler *pFiler )
{
	pFiler->readItem (&flexmidpoint) ;
}

TVS_FlexDuct::TVS_FlexDuct()
{
 flexmidpoint=AcGePoint3d(0,100,0);
}

TVS_FlexDuct::~TVS_FlexDuct()
{

}
