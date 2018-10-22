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
//----- TVS_TAP.cpp : Implementation of TVS_TAP
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "TVS_TAP.h"
#include "TVS_Ventilation_DBX_i.h"
//-----------------------------------------------------------------------------
Adesk::UInt32 TVS_TAP::kCurrentVersionNumber =TVS_Version ;

//-----------------------------------------------------------------------------
ACRX_DXF_DEFINE_MEMBERS (
	TVS_TAP, TVS_Entity,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, 
	AcDbProxyEntity::kNoOperation, TVS_TAP,
	TVSTVS_VENTILATION_DBXAPP
	|Product Desc:     A description for your object
	|Company:          Your company name
	|WEB Address:      Your company WEB site address
	)

	//-----------------------------------------------------------------------------
	TVS_TAP::TVS_TAP () : TVS_Entity () {
}

TVS_TAP::~TVS_TAP () {
}


void TVS_TAP::getSizeString(CString &sizeStr,const bool &sortSize/*=false*/)
{
	if (SizeB==0)
	{
		sizeStr.Format(L"%%%%C%g", SizeA);
		return;
	}
	if (sortSize){
		sizeStr.Format(L"%gx%g", min(SizeA,SizeB),max(SizeA,SizeB));
		return;
	}else{
		sizeStr.Format(L"%gx%g", SizeA,SizeB);
	}
}

Acad::ErrorStatus TVS_TAP::subGetClassID (CLSID *pClsid) const {
	assertReadEnabled () ;
	*pClsid=CLSID_Com_TAP;

	return (Acad::eOk) ;
	//return (AcDbEntity::subGetClassID (pClsid)) ;
}
//-----------------------------------------------------------------------------
//----- AcDbObject protocols
//- Dwg Filing protocol
Acad::ErrorStatus TVS_TAP::dwgOutFields (AcDbDwgFiler *pFiler) const {
	assertReadEnabled () ;
	//----- Save parent class information first.
	Acad::ErrorStatus es =AcDbCurve::dwgOutFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be saved first
	if ( (es =pFiler->writeUInt32 (TVS_TAP::kCurrentVersionNumber)) != Acad::eOk )
		return (es) ;
	//----- Output params
	//.....


	pFiler->writeItem (CenterPoint) ;
	pFiler->writeItem (Radius) ;
	pFiler->writeItem (SizeA) ;
	pFiler->writeItem (SizeB) ;
	pFiler->writeItem (Normvector) ;
	pFiler->writeItem (Startvector) ;
	pFiler->writeItem (Swectangle) ;
	pFiler->writeItem (ThisRound) ;
	pFiler->writeItem (This1D) ;
	pFiler->writeItem (Flow) ;
	writeInt(pFiler,Direct); //int
	pFiler->writeItem (Elev) ;
	pFiler->writeItem (Wipeout) ; 
	writeInt(pFiler,Param);  //int
	pFiler->writeItem (IsPipe) ;
	pFiler->writeItem (Form) ;
	pFiler->writeItem (TypeRoundTap) ;
	pFiler->writeItem (RadiusTypeRound) ;
	pFiler->writeItem (RadiusTypeRect) ;
	pFiler->writeItem (RadiusVariableParameter) ;
	pFiler->writeItem (RadiusConst) ;
	pFiler->writeItem (MiddlePoint) ;
	pFiler->writeItem (WipeoutLength) ;
	writeInt(pFiler,DuctType);  //int
	return (pFiler->filerStatus ()) ;

}

Acad::ErrorStatus TVS_TAP::dwgInFields (AcDbDwgFiler *pFiler) {

	assertWriteEnabled () ;
	//----- Read parent class information first.
	Acad::ErrorStatus es =AcDbCurve::dwgInFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be read first
	Adesk::UInt32 version =TVS_Version ;
	if ( (es =pFiler->readUInt32 (&version)) != Acad::eOk )
		return (es) ;
	if ( version > TVS_TAP::kCurrentVersionNumber )
		return (Acad::eMakeMeProxy) ;
	//- Uncomment the 2 following lines if your current object implementation cannot
	//- support previous version of that object.
	//if ( version < TVS_TAP::kCurrentVersionNumber )
	//	return (Acad::eMakeMeProxy) ;
	//----- Read params
	//.....

	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&CenterPoint) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&Radius) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&SizeA) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&SizeB) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&Normvector) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&Startvector) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&Swectangle) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&ThisRound) ;
	if ( version >= 1 /*&& version <= endVersion*/ ) pFiler->readItem (&This1D) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Flow) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) readInt(pFiler,Direct,version); //int
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Elev) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) pFiler->readItem (&Wipeout) ;
	if ( version >= 2 /*&& version <= endVersion*/ ) readInt(pFiler,Param,version); //int
	if ( version >= 5 /*&& version <= endVersion*/ ) pFiler->readItem (&IsPipe) ;
	if ( version >= 21 /*&& version <= endVersion*/ ) pFiler->readItem (&Form) ;
	if ( version >= 21 /*&& version <= endVersion*/ ) pFiler->readItem (&TypeRoundTap) ;
	if ( version >= 21 /*&& version <= endVersion*/ ) pFiler->readItem (&RadiusTypeRound) ;
	if ( version >= 21 /*&& version <= endVersion*/ ) pFiler->readItem (&RadiusTypeRect) ;
	if ( version >= 21 /*&& version <= endVersion*/ ) pFiler->readItem (&RadiusVariableParameter) ;
	if ( version >= 21 /*&& version <= endVersion*/ ) pFiler->readItem (&RadiusConst) ;
	if ( version >= 22 /*&& version <= endVersion*/ ) pFiler->readItem (&MiddlePoint) ;
	if ( version >= 23 /*&& version <= endVersion*/ ) pFiler->readItem (&WipeoutLength) ;	else WipeoutLength=50;
	if ( version < 22 /*&& version <= endVersion*/ )
	{
		checkRadiusTypeRect();
		checkRadiusTypeRound();
		checkForm();
		checkTypeRoundTap();
		setRadius();

		ListOfEntity.removeAll();
		double  Lx, Ly,Nx, Ny;
		 //change in future
		Nx=Startvector.x;
		Ny=Startvector.y;
		Lx=Nx;
		Ly=Ny;
		AcGeVector3d vectr; 
		vectr.x = 0.0; vectr.y = 0.0; vectr.z = 1.0; 
		startangle=acos((1*Lx+0)/sqrt(Lx*Lx+Ly*Ly));
		if (Ny<0)
		{
			startangle=2*M_PI-startangle;
		}

		chekMiddlePoint();
	}
	if ( version >= 24 /*&& version <= endVersion*/ ) readInt(pFiler,DuctType,version); //int ;	else DuctType=0;

	//acutDelString(Tag1);
	//acutDelString(Tag2);
	//if ( version >= 5 /*&& version <= endVersion*/ ) pFiler->readString(&Tag1) ;
	//if ( version >= 5 /*&& version <= endVersion*/ ) pFiler->readString(&Tag2) ;
	return (pFiler->filerStatus ()) ;
}

//- Persistent reactor callbacks
void TVS_TAP::openedForModify (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::openedForModify (pDbObj) ;
}

void TVS_TAP::cancelled (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::cancelled (pDbObj) ;
}

void TVS_TAP::objectClosed (const AcDbObjectId objId) {
	assertReadEnabled () ;
	AcDbCurve::objectClosed (objId) ;
}

void TVS_TAP::goodbye (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::goodbye (pDbObj) ;
}

void TVS_TAP::copied (const AcDbObject *pDbObj, const AcDbObject *pNewObj) {
	assertReadEnabled () ;
	AcDbCurve::copied (pDbObj, pNewObj) ;
}

void TVS_TAP::erased (const AcDbObject *pDbObj, Adesk::Boolean bErasing) {
	assertReadEnabled () ;
	AcDbCurve::erased (pDbObj, bErasing) ;
}

void TVS_TAP::modified (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modified (pDbObj) ;
}

void TVS_TAP::modifiedGraphics (const AcDbEntity *pDbEnt) {
	assertReadEnabled () ;
	AcDbCurve::modifiedGraphics (pDbEnt) ;
}

void TVS_TAP::modifiedXData (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modifiedXData (pDbObj) ;
}

void TVS_TAP::subObjModified (const AcDbObject *pMainbObj, const AcDbObject *pSubObj) {
	assertReadEnabled () ;
	AcDbCurve::subObjModified (pMainbObj, pSubObj) ;
}

void TVS_TAP::modifyUndone (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::modifyUndone (pDbObj) ;
}

void TVS_TAP::reappended (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::reappended (pDbObj) ;
}

void TVS_TAP::unappended (const AcDbObject *pDbObj) {
	assertReadEnabled () ;
	AcDbCurve::unappended (pDbObj) ;
}

//-----------------------------------------------------------------------------
//----- AcDbEntity protocols
Adesk::Boolean TVS_TAP::subWorldDraw (AcGiWorldDraw *mode) {

	assertReadEnabled () ;

	setRadius();

	ClearEntitylist();
	double  Lx, Ly,Nx, Ny;
	
	Nx=Startvector.x;
	Ny=Startvector.y;
	Lx=Nx;
	Ly=Ny;
	AcGeVector3d vectr; 
	vectr.x = 0.0; vectr.y = 0.0; vectr.z = 1.0; 
	startangle=acos((1*Lx+0)/sqrt(Lx*Lx+Ly*Ly));
	if (Ny<0)
	{
		startangle=2*M_PI-startangle;
	}


	

		CenterPoint=AcGePoint3d(MiddlePoint.x-(Radius+SizeA/2)/cos(Swectangle/2)*cos(startangle+Swectangle/2),
		MiddlePoint.y-(Radius+SizeA/2)/cos(Swectangle/2)*sin(startangle+Swectangle/2),
		MiddlePoint.z
		);



#pragma region FlexDuct
if (DuctType==DuctTypeFlex)
{
	if (Form==Form_Direct)
	{
		
		A=AcGePoint3d((Radius+SizeA)*cos(startangle)+CenterPoint.x,
			(Radius+SizeA)*sin(startangle)+CenterPoint.y,
			CenterPoint.z
			);

		B=AcGePoint3d((Radius+SizeA)*cos(startangle+Swectangle)+CenterPoint.x,
			(Radius+SizeA)*sin(startangle+Swectangle)+CenterPoint.y,
			CenterPoint.z
			);
		C=AcGePoint3d((Radius)*cos(startangle+Swectangle)+CenterPoint.x,
			(Radius)*sin(startangle+Swectangle)+CenterPoint.y,
			CenterPoint.z
			);
		D=AcGePoint3d((Radius)*cos(startangle)+CenterPoint.x,
			(Radius)*sin(startangle)+CenterPoint.y,
			CenterPoint.z
			);


		MA=AcGePoint3d((Radius+SizeA/2)*cos(startangle)+CenterPoint.x,
			(Radius+SizeA/2)*sin(startangle)+CenterPoint.y,
			CenterPoint.z
			);
		MC=AcGePoint3d((Radius+SizeA/2)*cos(startangle+Swectangle)+CenterPoint.x,
			(Radius+SizeA/2)*sin(startangle+Swectangle)+CenterPoint.y,
			CenterPoint.z
			);

		L1[0]=A;
		L1[1]=D;
		L2[0]=B;
		L2[1]=C;

		if (Wipeout==true)
		{





			AcGePoint2d p[2];
			p[0]=AcGePoint2d(MA.x,MA.y);
			p[1]=AcGePoint2d(MC.x,MC.y);

			AcDbPolyline *pLn = new AcDbPolyline(2);



			pLn->addVertexAt(0,p[0],tan(Swectangle/4));
			pLn->addVertexAt(1,p[1],tan(Swectangle/4));

			setWipeoutProperty(mode,pLn);



		}///////

		if (This1D==true)
		{

			AcDbArc *arcie1=new AcDbArc(CenterPoint,Normvector,Radius+SizeA/2,startangle,startangle+Swectangle);
			setZigzagProperty(arcie1);


		}
		else
		{



			AcDbArc *arcie1= new AcDbArc(CenterPoint,Normvector,Radius+SizeA,startangle,startangle+Swectangle);
			AcDbArc *arcie2= new AcDbArc(CenterPoint,Normvector,Radius,startangle,startangle+Swectangle);
				AcDbArc *arcie3= new AcDbArc(CenterPoint,Normvector,Radius+SizeA/2,startangle,startangle+Swectangle);
			AcDbLine*pLine1 = new AcDbLine(this->A,this->D);
			AcDbLine*pLine2 = new AcDbLine(this->B,this->C);




			setZigzagProperty(arcie1);
			setZigzagProperty(arcie2);
			setCenterProperty(arcie3);
// 			setMainProperty(pLine1);
// 			setMainProperty(pLine2);








		}
	}

	////Updown
	else
	{


		MA=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
			CenterPoint.y,
			CenterPoint.z
			).rotateBy(startangle,vectr,CenterPoint);
		MC=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
			(SizeA/2+Radius)*sin(Swectangle)+CenterPoint.y,
			CenterPoint.z
			).rotateBy(startangle,vectr,CenterPoint);




		AcGePoint3d t1=AcGePoint3d(Radius+SizeA+CenterPoint.x,
			CenterPoint.y,
			CenterPoint.z
			).rotateBy(startangle,vectr,CenterPoint);

		AcGePoint3d t2=AcGePoint3d(Radius+SizeA+CenterPoint.x,
			CenterPoint.y+(Radius+SizeA/2)*sin(Swectangle),
			CenterPoint.z
			).rotateBy(startangle,vectr,CenterPoint);
		AcGePoint3d t3=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
			CenterPoint.y+(Radius+SizeA)*sin(Swectangle),
			CenterPoint.z
			).rotateBy(startangle,vectr,CenterPoint);
		AcGePoint3d t4=AcGePoint3d(Radius+CenterPoint.x,
			CenterPoint.y+(Radius+SizeA/2)*sin(Swectangle),
			CenterPoint.z
			).rotateBy(startangle,vectr,CenterPoint);
		AcGePoint3d t5=AcGePoint3d(Radius+CenterPoint.x,
			CenterPoint.y,
			CenterPoint.z
			).rotateBy(startangle,vectr,CenterPoint);

		AcGePoint3d mm=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
			(SizeA/2+Radius)*sin(Swectangle)+CenterPoint.y,
			CenterPoint.z
			);

		AcGePoint3d p1=AcGePoint3d(mm.x+SizeA/2+Otstup,
			mm.y,
			mm.z
			);

		AcGePoint3d p2=AcGePoint3d(mm.x,
			mm.y+(Radius+SizeA)*sin(Swectangle)-(Radius+SizeA/2)*sin(Swectangle)+Otstup,
			mm.z
			);
		AcGePoint3d p3=AcGePoint3d(mm.x-SizeA/2-Otstup,
			mm.y,
			mm.z
			);
		AcGePoint3d p4=AcGePoint3d(mm.x,
			mm.y-(Radius+SizeA)*sin(Swectangle)+(Radius+SizeA/2)*sin(Swectangle)-Otstup,
			mm.z
			);
		AcGePoint3d p5=AcGePoint3d(mm.x,
			CenterPoint.y,
			mm.z
			);



		AcDbEllipse* el=new AcDbEllipse(mm,AcGeVector3d(0,0,1),AcGeVector3d(SizeA/2,0,0),((Radius+SizeA)*sin(Swectangle)-(Radius+SizeA/2)*sin(Swectangle))/(SizeA/2),0,M_PI);
		AcDbEllipse* el2=new AcDbEllipse(mm,AcGeVector3d(0,0,1),AcGeVector3d(SizeA/2,0,0),((Radius+SizeA)*sin(Swectangle)-(Radius+SizeA/2)*sin(Swectangle))/(SizeA/2),M_PI,0);
		AcDbEllipse* el3;
		double radiusparam;
		double radius2=(Radius+SizeA)*sin(Swectangle)-(Radius+SizeA/2)*sin(Swectangle);
		if (radius2<=SizeA*3/8)
		{
			el3=new AcDbEllipse(mm,AcGeVector3d(0,0,1),AcGeVector3d(SizeA*3/8,0,0),radius2/(SizeA*3/8),M_PI*3/2,M_PI/2);
		}
		else
		{
			el3=new AcDbEllipse(mm,AcGeVector3d(0,0,1),AcGeVector3d(0,radius2,0),(SizeA*3/8)/radius2,M_PI,0);
		}



		AcDbLine*pLine1 = new AcDbLine(p1,p3);
		AcDbLine*pLine2 = new AcDbLine(p2,p5);

		AcDbLine*pLn1 = new AcDbLine(t2,t1);
		AcDbLine*pLn2 = new AcDbLine(t5,t4);
// 				AcDbPolyline*pLn = new AcDbPolyline();
// 		pLn->addVertexAt(0,AcGePoint2d(t2.x,t2.y));
// 		pLn->addVertexAt(1,AcGePoint2d(t1.x,t1.y));
// 		pLn->addVertexAt(2,AcGePoint2d(t5.x,t5.y));
// 		pLn->addVertexAt(3,AcGePoint2d(t4.x,t4.y));


		AcGeMatrix3d mat; 
		mat.setToRotation(startangle,AcGeVector3d(0,0,1),CenterPoint); 


		el->transformBy(mat);
		el2->transformBy(mat);
		el3->transformBy(mat);
		pLine1->transformBy(mat);
		pLine2->transformBy(mat);

		if (Wipeout==true)
		{
			AcDbPolyline*pLn = new AcDbPolyline();
			pLn->addVertexAt(0,AcGePoint2d(MA.x,MA.y));
			pLn->addVertexAt(1,AcGePoint2d(t3.x,t3.y));
			setWipeoutProperty(mode,pLn);

		}

		if (This1D==true)
		{
			AcDbLine*pLine1 = new AcDbLine(MA,mm.rotateBy(startangle,vectr,CenterPoint));
			setZigzagProperty(pLine1);
			AcDbCircle *crcl = new AcDbCircle(MC,AcGeVector3d(0,0,1),50);
			setMainProperty(crcl);
		}

		else 
		{
			double l1=(double) 89.5*M_PI/180, l2=90.5*(double)M_PI/180;
			if (Form==Form_Up)
			{

				if ((Swectangle> l1) && (Swectangle< l2))
				{

					setMainProperty(el);
					setMainProperty(el2);
					setMainProperty(el3);
					setCenterProperty(pLine1);
					setCenterProperty(pLine2);
					setZigzagProperty(pLn1);
					setZigzagProperty(pLn2);

				}
				else
				{

					setHideProperty(el);
					setMainProperty(el2);
					setCenterProperty(pLine1);
					setCenterProperty(pLine2);
					setZigzagProperty(pLn1);
					setZigzagProperty(pLn2);

				}
			}
			else
			{
				if ((Swectangle> l1) && (Swectangle< l2))
				{

					setMainProperty(el);
					setHideProperty(el2);
					setCenterProperty(el3);
					setCenterProperty(pLine1);
					setCenterProperty(pLine2);
					setZigzagProperty(pLn1);
					setZigzagProperty(pLn2);


				}
				else
				{

					setMainProperty(el);
					setHideProperty(el2);
					setCenterProperty(pLine1);
					setCenterProperty(pLine2);
					setZigzagProperty(pLn1);
					setZigzagProperty(pLn2);

				}
			}




		}





	}

}

#pragma endregion Flexduct

#pragma region Duct Type Still

if (DuctType==DuctTypeStill)
{


	if (ThisRound==false)

	{



			A=AcGePoint3d((Radius+SizeA)*cos(startangle)+CenterPoint.x,
				(Radius+SizeA)*sin(startangle)+CenterPoint.y,
				CenterPoint.z
				);

			B=AcGePoint3d((Radius+SizeA)*cos(startangle+Swectangle)+CenterPoint.x,
				(Radius+SizeA)*sin(startangle+Swectangle)+CenterPoint.y,
				CenterPoint.z
				);
			C=AcGePoint3d((Radius)*cos(startangle+Swectangle)+CenterPoint.x,
				(Radius)*sin(startangle+Swectangle)+CenterPoint.y,
				CenterPoint.z
				);
			D=AcGePoint3d((Radius)*cos(startangle)+CenterPoint.x,
				(Radius)*sin(startangle)+CenterPoint.y,
				CenterPoint.z
				);
			

			MA=AcGePoint3d((Radius+SizeA/2)*cos(startangle)+CenterPoint.x,
				(Radius+SizeA/2)*sin(startangle)+CenterPoint.y,
				CenterPoint.z
				);
			MC=AcGePoint3d((Radius+SizeA/2)*cos(startangle+Swectangle)+CenterPoint.x,
				(Radius+SizeA/2)*sin(startangle+Swectangle)+CenterPoint.y,
				CenterPoint.z
				);

			L1[0]=A;
			L1[1]=D;
			L2[0]=B;
			L2[1]=C;



#pragma region	form Direct
			if (Form==Form_Direct) 

			{

			///////Wipeout
			if (Wipeout==true)
			{
				




				AcGePoint2d p[2];
				p[0]=AcGePoint2d(MA.x,MA.y);
				p[1]=AcGePoint2d(MC.x,MC.y);

				AcDbPolyline *pLn = new AcDbPolyline(2);



				pLn->addVertexAt(0,p[0],tan(Swectangle/4));
				pLn->addVertexAt(1,p[1],tan(Swectangle/4));
			
			setWipeoutProperty(mode,pLn);
		


			}///////

			if (This1D==true)
			{

				AcDbArc *arcie1=new AcDbArc(CenterPoint,Normvector,Radius+SizeA/2,startangle,startangle+Swectangle);
				setMainProperty(arcie1);
			

			}
			else
			{



				AcDbArc *arcie1= new AcDbArc(CenterPoint,Normvector,Radius+SizeA,startangle,startangle+Swectangle);
				AcDbArc *arcie2= new AcDbArc(CenterPoint,Normvector,Radius,startangle,startangle+Swectangle);
				AcDbLine*pLine1 = new AcDbLine(this->A,this->D);
				AcDbLine*pLine2 = new AcDbLine(this->B,this->C);




					setMainProperty(arcie1);
					setMainProperty(arcie2);
					setMainProperty(pLine1);
					setMainProperty(pLine2);




			



			}


		}
#pragma endregion


#pragma region	form Updown
			else

			{
				
				CenterPoint=AcGePoint3d(MiddlePoint.x-SizeA/2-Radius,
					MiddlePoint.y-(SizeB/2+Radius)*sin(Swectangle),
					MiddlePoint.z
					);
				
				A=AcGePoint3d(Radius+SizeA+CenterPoint.x,
					CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,MiddlePoint);

				
				D=AcGePoint3d(Radius+CenterPoint.x,
					CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,MiddlePoint);

				MA=AcGePoint3d((Radius+SizeA/2)+CenterPoint.x,
					CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,MiddlePoint);
				MC=AcGePoint3d((Radius+SizeA/2)+CenterPoint.x,
					(Radius+SizeB/2)*sin(Swectangle)+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,MiddlePoint);

			

				t1=AcGePoint3d((Radius+SizeA)+CenterPoint.x,
					(Radius)*sin(Swectangle)+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,MiddlePoint);
				t2=AcGePoint3d((Radius+SizeA)+CenterPoint.x,
					(Radius+SizeB)*sin(Swectangle)+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,MiddlePoint);
				
				t3=AcGePoint3d(Radius+CenterPoint.x,
					(Radius+SizeB)*sin(Swectangle)+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,MiddlePoint);
				t4=AcGePoint3d(Radius+CenterPoint.x,
					(Radius)*sin(Swectangle)+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,MiddlePoint);
				AcGePoint3d tm1=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
					CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,MiddlePoint);
				AcGePoint3d tm2=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
					(Radius+SizeB)*sin(Swectangle)+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,MiddlePoint);
				AcGePoint3d mm=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
					(Radius+SizeB/2)*sin(Swectangle)+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,MiddlePoint);
				AcGePoint3d mm14=AcGePoint3d(Radius+SizeA*3/4+CenterPoint.x,
					(Radius+SizeB*1/4)*sin(Swectangle)+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,MiddlePoint);
			
			
				AcGeVector3d vectr; 
					vectr.x = 0.0; vectr.y = 0.0; vectr.z = 1.0; 
		
			
				updownarraybase[0]=t2;
				updownarraybase[1]=A;
				updownarraybase[2]=D;
				updownarraybase[3]=t3;

				hideline[0]=t1;
				hideline[1]=t4;
				AcGePoint2d p[2];
				p[0]=AcGePoint2d(tm1.x,tm1.y);
				p[1]=AcGePoint2d(tm2.x,tm2.y);




				///////Wipeout
				if (Wipeout==true)
				{





				

					AcDbPolyline *pLn = new AcDbPolyline(2);



					pLn->addVertexAt(0,p[0]);
					pLn->addVertexAt(1,p[1]);

					setWipeoutProperty(mode,pLn);
				


				}///////

				if (This1D==true)
				{

					AcDbPolyline *pLn = new AcDbPolyline(2);
				

					pLn->addVertexAt(0,AcGePoint2d(MA.x,MA.y));
					pLn->addVertexAt(1,AcGePoint2d(MC.x,MC.y));

					setMainProperty(pLn);
					AcDbCircle *crcl = new AcDbCircle(MC,AcGeVector3d(0,0,1),50);
					setMainProperty(crcl);

				}
				else
				{



					AcDbPolyline*pLn=new AcDbPolyline;
					AcDbPolyline*pLn2=new AcDbPolyline;
					AcDbLine*pLine1 = new AcDbLine(this->hideline[0],this->hideline[1]);
				
					for (int i=0;i<4; i++)
					{
			
						pLn->addVertexAt(i,AcGePoint2d(this->updownarraybase[i].x,this->updownarraybase[i].y));
					}
					
					pLn2->addVertexAt(0,AcGePoint2d(t2.x,t2.y));
					pLn2->addVertexAt(0,AcGePoint2d(mm14.x,mm14.y));
					pLn2->addVertexAt(0,AcGePoint2d(t4.x,t4.y));
					




						double l1=(double) 89.5*M_PI/180, l2=90.5*(double)M_PI/180;
						if (Form==Form_Up)
						{

							if ((Swectangle> l1) && (Swectangle< l2))
							{

								setMainProperty(pLn2);
								setMainProperty(pLine1);
								pLn->setClosed(true);


							}
							else
							{

								AcDbLine*pLine3 = new AcDbLine(t3,t2);
								setHideProperty(pLine3);
								setMainProperty(pLine1);

							}
						}
						else
						{
							if ((Swectangle> l1) && (Swectangle< l2))
							{
								pLn->setClosed(true);
								setHideProperty(pLn2);
								setHideProperty(pLine1);


							}
							else
							{
								AcDbLine*pLine3 = new AcDbLine(t3,t2);
								setMainProperty(pLine3);
								setHideProperty(pLine1);

							}
						}













					
					setMainProperty(pLn);
			
				


			




				}


			}
#pragma endregion

	} 



	else //ThisRound==true
	{




#pragma region Radius specific
			if (RadiusTypeRound==RadiusTypeRound_RadiusSpecific)
			{




				double flanez=0;


				if(SizeA<630)
				{
					flanez=45;
				}
				AcGePoint3d pM16,pM25;
				double bigRl=atan(flanez/(Radius+SizeA));
				double smallRl=atan(flanez/(Radius));
				double midRl=atan(flanez/(Radius+SizeA/2));
				double smallRAD=sqrt(flanez*flanez+(Radius)*(Radius));
				double bigRAD=sqrt(flanez*flanez+(Radius+SizeA)*(Radius+SizeA));
				double MidRad=sqrt(flanez*flanez+(Radius+SizeA/2)*(Radius+SizeA/2));
				

				double alpha;
#pragma region	form Direct
				if (Form==Form_Direct) 
				{
				if (Swectangle>(M_PI/4+0.01))
				{
					//segments=3;
					alpha=Swectangle/4;


					pMass[0]=AcGePoint3d((bigRAD)*cos(startangle+Swectangle+bigRl)+CenterPoint.x,
						(bigRAD)*sin(startangle+Swectangle+bigRl)+CenterPoint.y,
						CenterPoint.z
						);

					pMass[1]=AcGePoint3d((Radius+SizeA)/cos(alpha)*cos(startangle+3*alpha)+CenterPoint.x,
						(Radius+SizeA)/cos(alpha)*sin(startangle+3*alpha)+CenterPoint.y,
						CenterPoint.z
						);
					pMass[2]=AcGePoint3d((Radius+SizeA)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
						(Radius+SizeA)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y,
						CenterPoint.z
						);
					pMass[3]=AcGePoint3d((bigRAD)*cos(startangle-bigRl)+CenterPoint.x,
						(bigRAD)*sin(startangle-bigRl)+CenterPoint.y,
						CenterPoint.z
						);
					pMass[4]=AcGePoint3d((smallRAD)*cos(startangle-smallRl)+CenterPoint.x,
						(smallRAD)*sin(startangle-smallRl)+CenterPoint.y,
						CenterPoint.z
						);
					pMass[5]=AcGePoint3d((Radius)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
						(Radius)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y,
						CenterPoint.z
						);
					pMass[6]=AcGePoint3d((Radius)/cos(alpha)*cos(startangle+3*alpha)+CenterPoint.x,
						(Radius)/cos(alpha)*sin(startangle+3*alpha)+CenterPoint.y,
						CenterPoint.z
						);

					pMass[7]=AcGePoint3d((smallRAD)*cos(startangle+Swectangle+smallRl)+CenterPoint.x,
						(smallRAD)*sin(startangle+Swectangle+smallRl)+CenterPoint.y,
						CenterPoint.z
						);
					pM25=AcGePoint3d((Radius+SizeA/2)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
						(Radius+SizeA/2)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y,
						CenterPoint.z
						);
					pM16=AcGePoint3d((Radius+SizeA/2)/cos(alpha)*cos(startangle+alpha*3)+CenterPoint.x,
						(Radius+SizeA/2)/cos(alpha)*sin(startangle+alpha*3)+CenterPoint.y,
						CenterPoint.z
						);
			

					MA=AcGePoint3d((MidRad)*cos(startangle+Swectangle+midRl)+CenterPoint.x,
						(MidRad)*sin(startangle+Swectangle+midRl)+CenterPoint.y,
						CenterPoint.z
						);
					MC=AcGePoint3d((MidRad)*cos(startangle-midRl)+CenterPoint.x,
						(MidRad)*sin(startangle-midRl)+CenterPoint.y,
						CenterPoint.z
						);



					if (Wipeout==true) //wipe
					{
						


						AcGePoint2d p[4];
						p[0]=AcGePoint2d(MA.x,MA.y);
						p[1]=AcGePoint2d((Radius+SizeA/2)/cos(alpha)*cos(startangle+3*alpha)+CenterPoint.x,
							(Radius+SizeA/2)/cos(alpha)*sin(startangle+3*alpha)+CenterPoint.y
							);
						p[2]=AcGePoint2d((Radius+SizeA/2)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
							(Radius+SizeA/2)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y
							);
						p[3]=AcGePoint2d(MC.x,MC.y);



						AcDbPolyline*	pLn=new AcDbPolyline(4);




						for (int i=0;i<4; i++)
						{
							pLn->addVertexAt(i,p[i]);
						}
						setWipeoutProperty(mode,pLn);



					

					}//wipe



					if (This1D==false)
					{


						AcDbPolyline* pLine1 = new AcDbPolyline(8);
						AcDbPolyline* pLine2 = new AcDbPolyline(4);

						pMassO[0]=MA;
						pMassO[1]=pM16;
						pMassO[2]=pM25;
						pMassO[3]=MC;


						pLine1->setClosed(true);

						AcGePoint2d pointieM[8];
						for (int i=0;i<8; i++)
						{
							pointieM[i]=AcGePoint2d(this->pMass[i].x,this->pMass[i].y);
							pLine1->addVertexAt(i,pointieM[i]);
						}

						AcGePoint2d pointieO[4];
						for (int i=0;i<4; i++)
						{
							pointieO[i]=AcGePoint2d(this->pMassO[i].x,this->pMassO[i].y);
							pLine2->addVertexAt(i,pointieO[i]);
						}

						AcDbLine* pLine3 = new AcDbLine(this->pMass[1],this->pMass[6]);


						AcDbLine* pLine4 = new AcDbLine(this->pMass[2],this->pMass[5]);


						setMainProperty(pLine1);
						setCenterProperty(pLine2);
						setMainProperty(pLine3);
						setMainProperty(pLine4);

			


					}
					else
					{


						pMassO[0]=MA;
						pMassO[1]=pM16;
						pMassO[2]=pM25;
						pMassO[3]=MC;


						AcDbPolyline* pLine2 = new AcDbPolyline(4);

						AcGePoint2d pointieO[4];
						for (int i=0;i<4; i++)
						{
							pointieO[i]=AcGePoint2d(this->pMassO[i].x,this->pMassO[i].y);
							pLine2->addVertexAt(i,pointieO[i]);
						}

						setMainProperty(pLine2);

					
					}

				}
				else
				{
					//segments=2;
					alpha=Swectangle/2;


					pMass45[0]=AcGePoint3d((bigRAD)*cos(startangle+Swectangle+bigRl)+CenterPoint.x,
						(bigRAD)*sin(startangle+Swectangle+bigRl)+CenterPoint.y,
						CenterPoint.z
						);

					pMass45[1]=AcGePoint3d((Radius+SizeA)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
						(Radius+SizeA)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y,
						CenterPoint.z
						);

					pMass45[2]=AcGePoint3d((bigRAD)*cos(startangle-bigRl)+CenterPoint.x,
						(bigRAD)*sin(startangle-bigRl)+CenterPoint.y,
						CenterPoint.z
						);
					pMass45[3]=AcGePoint3d((smallRAD)*cos(startangle-smallRl)+CenterPoint.x,
						(smallRAD)*sin(startangle-smallRl)+CenterPoint.y,
						CenterPoint.z
						);
					pMass45[4]=AcGePoint3d((Radius)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
						(Radius)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y,
						CenterPoint.z
						);


					pMass45[5]=AcGePoint3d((smallRAD)*cos(startangle+Swectangle+smallRl)+CenterPoint.x,
						(smallRAD)*sin(startangle+Swectangle+smallRl)+CenterPoint.y,
						CenterPoint.z
						);
					pM16=AcGePoint3d((Radius+SizeA/2)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
						(Radius+SizeA/2)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y,
						CenterPoint.z
						);
					

					MA=AcGePoint3d((MidRad)*cos(startangle+Swectangle+midRl)+CenterPoint.x,
						(MidRad)*sin(startangle+Swectangle+midRl)+CenterPoint.y,
						CenterPoint.z
						);
					MC=AcGePoint3d((MidRad)*cos(startangle-midRl)+CenterPoint.x,
						(MidRad)*sin(startangle-midRl)+CenterPoint.y,
						CenterPoint.z
						);

					pMassO45[0]=MA;
					pMassO45[1]=pM16;
					pMassO45[2]=MC;

					if (Wipeout==true) //wipe
					{
						



						AcGePoint2d p[3];
						p[0]=AcGePoint2d(MA.x,MA.y);
						p[1]=AcGePoint2d(MiddlePoint.x,MiddlePoint.y);
						p[2]=AcGePoint2d(MC.x,MC.y);



						AcDbPolyline *pLn=new AcDbPolyline(3);




						for (int i=0;i<3; i++)
						{
							pLn->addVertexAt(i,p[i]);
						}
					
						setWipeoutProperty(mode,pLn);
						


					}//wipe




					if (This1D==false)
					{



						AcDbPolyline* pLine1 = new AcDbPolyline(6);
						AcDbPolyline* pLine2 = new AcDbPolyline(3);
						pLine1->setClosed(true);
						AcGePoint2d pointieM[6];


						for (int i=0;i<6; i++)
						{
							pointieM[i]=AcGePoint2d(this->pMass45[i].x,this->pMass45[i].y);
							pLine1->addVertexAt(i,pointieM[i]);
						}

						AcGePoint2d pointieO[3];
						for (int i=0;i<3; i++)
						{
							pointieO[i]=AcGePoint2d(this->pMassO45[i].x,this->pMassO45[i].y);
							pLine2->addVertexAt(i,pointieO[i]);
						}

						AcDbLine* pLine3 = new AcDbLine(this->pMass45[1],this->pMass45[4]);
						setMainProperty(pLine1);	
						setCenterProperty(pLine2);
						setMainProperty(pLine3);

				



					}
					else
					{


						AcDbPolyline* pLine2 = new AcDbPolyline(3);
						AcGePoint2d pointieO[3];
						for (int i=0;i<3; i++)
						{
							pointieO[i]=AcGePoint2d(this->pMassO45[i].x,this->pMassO45[i].y);
							pLine2->addVertexAt(i,pointieO[i]);
						}

						setMainProperty(pLine2)		;



					}

				}








			}
#pragma endregion

#pragma region	form Updown
			else
			{

				MA=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
					-flanez+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);
				MC=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
					(MidRad)*sin(Swectangle+midRl)+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);
				

				AcGePoint3d t1=AcGePoint3d(Radius+SizeA+CenterPoint.x,
					-flanez+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);
				AcGePoint3d t2=AcGePoint3d(Radius+SizeA+CenterPoint.x,
					(MidRad)*sin(Swectangle+midRl)+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);
				AcGePoint3d t3=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
					(bigRAD)*sin(Swectangle+bigRl)+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);

				AcGePoint3d t4=AcGePoint3d(Radius+CenterPoint.x,
					(MidRad)*sin(Swectangle+midRl)+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);
				AcGePoint3d t5=AcGePoint3d(Radius+CenterPoint.x,
					-flanez+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);
				AcGePoint3d t6=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
					(smallRAD)*sin(Swectangle+smallRl)+CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);

				AcGePoint3d mm=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
					(MidRad)*sin(Swectangle+midRl)+CenterPoint.y,
					CenterPoint.z
					);
					AcGePoint3d p1=AcGePoint3d(mm.x+SizeA/2+Otstup,
					mm.y,
					mm.z
					);

					AcGePoint3d p2=AcGePoint3d(mm.x,
						mm.y+(bigRAD)*sin(Swectangle+bigRl)-(MidRad)*sin(Swectangle+midRl)+Otstup,
						mm.z
						);
					AcGePoint3d p3=AcGePoint3d(mm.x-SizeA/2-Otstup,
						mm.y,
						mm.z
						);
					AcGePoint3d p4=AcGePoint3d(mm.x,
						mm.y-(bigRAD)*sin(Swectangle+bigRl)+(MidRad)*sin(Swectangle+midRl)-Otstup,
						mm.z
						);
					AcGePoint3d p5=AcGePoint3d(mm.x,
						CenterPoint.y-flanez,
						mm.z
						);


					AcDbEllipse* el=new AcDbEllipse(mm,AcGeVector3d(0,0,1),AcGeVector3d(SizeA/2,0,0),((bigRAD)*sin(Swectangle+bigRl)-(MidRad)*sin(Swectangle+midRl))/(SizeA/2),0,M_PI);
					AcDbEllipse* el2=new AcDbEllipse(mm,AcGeVector3d(0,0,1),AcGeVector3d(SizeA/2,0,0),((bigRAD)*sin(Swectangle+bigRl)-(MidRad)*sin(Swectangle+midRl))/(SizeA/2),M_PI,0);
					AcDbEllipse* el3;
					double radiusparam;
					double radius2=(bigRAD)*sin(Swectangle+bigRl)-(MidRad)*sin(Swectangle+midRl);
					if (radius2<=SizeA*3/8)
					{
						el3=new AcDbEllipse(mm,AcGeVector3d(0,0,1),AcGeVector3d(SizeA*3/8,0,0),radius2/(SizeA*3/8),M_PI*3/2,M_PI/2);
					}
					else
					{
						 el3=new AcDbEllipse(mm,AcGeVector3d(0,0,1),AcGeVector3d(0,radius2,0),(SizeA*3/8)/radius2,M_PI,0);
					}
					
					AcDbLine*pLine1 = new AcDbLine(p1,p3);
					AcDbLine*pLine2 = new AcDbLine(p2,p5);
					AcDbPolyline*pLn = new AcDbPolyline();
					pLn->addVertexAt(0,AcGePoint2d(t2.x,t2.y));
					pLn->addVertexAt(1,AcGePoint2d(t1.x,t1.y));
					pLn->addVertexAt(2,AcGePoint2d(t5.x,t5.y));
					pLn->addVertexAt(3,AcGePoint2d(t4.x,t4.y));
					

					AcGeMatrix3d mat; 
					mat.setToRotation(startangle,AcGeVector3d(0,0,1),CenterPoint); 


					el->transformBy(mat);
					el2->transformBy(mat);
					el3->transformBy(mat);
					pLine1->transformBy(mat);
					pLine2->transformBy(mat);
				
					if (Wipeout==true)
					{
						AcDbPolyline*pLn = new AcDbPolyline();
						pLn->addVertexAt(0,AcGePoint2d(MA.x,MA.y));
						pLn->addVertexAt(1,AcGePoint2d(t3.x,t3.y));
						setWipeoutProperty(mode,pLn);
					
					}

					if (This1D==true)
					{
						AcDbLine*pLine1 = new AcDbLine(MA,mm.rotateBy(startangle,vectr,CenterPoint));
						setMainProperty(pLine1);
						AcDbCircle *crcl = new AcDbCircle(MC,AcGeVector3d(0,0,1),50);
						setMainProperty(crcl);
					}

					else 
					{
						double l1=(double) 89.5*M_PI/180, l2=90.5*(double)M_PI/180;
					if (Form==Form_Up)
					{
						
						if ((Swectangle> l1) && (Swectangle< l2))
						{
						
						setMainProperty(el);
						setMainProperty(el2);
						setMainProperty(el3);
						setCenterProperty(pLine1);
						setCenterProperty(pLine2);
						setMainProperty(pLn);
						}
						else
						{
							setHideProperty(el);
							setMainProperty(el2);
							//setMainProperty(el3);
							setCenterProperty(pLine1);
							setCenterProperty(pLine2);
							setMainProperty(pLn);
						}
					}
					else
					{
						if ((Swectangle> l1) && (Swectangle< l2))
						{
						setMainProperty(el);
						setHideProperty(el2);
						setHideProperty(el3);
						setCenterProperty(pLine1);
						setCenterProperty(pLine2);
						setMainProperty(pLn);
						}
						else
						{
							setMainProperty(el);
							setHideProperty(el2);
							//setHideProperty(el3);
							setCenterProperty(pLine1);
							setCenterProperty(pLine2);
							setMainProperty(pLn);
						}
					}
					
					

				
					}
					

			}
#pragma endregion

		}
		
#pragma endregion



#pragma region TYpe Constant Variable
		if (RadiusTypeRound==RadiusTypeRound_RadiusConstant||RadiusTypeRound==RadiusTypeRound_RadiusVariable)
		{




		


	
#pragma region	form Direct
			if (Form==Form_Direct) 
			{
				
				A=AcGePoint3d(CenterPoint.x+Radius+SizeA,
					CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);

				B=AcGePoint3d(CenterPoint.x+(Radius+SizeA)*cos(Swectangle),
					CenterPoint.y+(Radius+SizeA)*sin(Swectangle),
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);

				C=AcGePoint3d(CenterPoint.x+(Radius)*cos(Swectangle),
					CenterPoint.y+(Radius)*sin(Swectangle),
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);

				D=AcGePoint3d(CenterPoint.x+Radius,
					CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);

				MA=AcGePoint3d(CenterPoint.x+(Radius+SizeA/2),
					CenterPoint.y,
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);

				MC=AcGePoint3d(CenterPoint.x+(Radius+SizeA/2)*cos(Swectangle),
					CenterPoint.y+(Radius+SizeA/2)*sin(Swectangle),
					CenterPoint.z
					).rotateBy(startangle,vectr,CenterPoint);

				





					if (Wipeout==true) //wipe
					{


					

						AcDbPolyline *pLn = new AcDbPolyline(2);



						pLn->addVertexAt(0,AcGePoint2d(MA.x,MA.y),tan(Swectangle/4));
						pLn->addVertexAt(1,AcGePoint2d(MC.x,MC.y),tan(Swectangle/4));

						setWipeoutProperty(mode,pLn);
					
					}//wipe



					if (This1D==false)
					{






						AcDbArc *arcie1= new AcDbArc(CenterPoint,Normvector,Radius+SizeA,startangle,startangle+Swectangle);
						AcDbArc *arcie3= new AcDbArc(CenterPoint,Normvector,Radius+SizeA/2,startangle,startangle+Swectangle);
						AcDbArc *arcie2= new AcDbArc(CenterPoint,Normvector,Radius,startangle,startangle+Swectangle);
						AcDbLine*pLine1 = new AcDbLine(this->A,this->D);
						AcDbLine*pLine2 = new AcDbLine(this->B,this->C);






						setMainProperty(pLine1);
						setMainProperty(pLine2);
						setMainProperty(arcie1);
						setMainProperty(arcie2);
						setCenterProperty(arcie3);
						

					


					}
					else
					{

						AcDbArc *arcie3= new AcDbArc(CenterPoint,Normvector,Radius+SizeA/2,startangle,startangle+Swectangle);
					setMainProperty(arcie3);
					
					}

				}

#pragma endregion

				else
				{
				

					MA=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
						CenterPoint.y,
						CenterPoint.z
						).rotateBy(startangle,vectr,CenterPoint);
					MC=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
						(SizeA/2+Radius)*sin(Swectangle)+CenterPoint.y,
						CenterPoint.z
						).rotateBy(startangle,vectr,CenterPoint);
					
		


					AcGePoint3d t1=AcGePoint3d(Radius+SizeA+CenterPoint.x,
						CenterPoint.y,
						CenterPoint.z
						).rotateBy(startangle,vectr,CenterPoint);
					
					AcGePoint3d t2=AcGePoint3d(Radius+SizeA+CenterPoint.x,
						CenterPoint.y+(Radius+SizeA/2)*sin(Swectangle),
						CenterPoint.z
						).rotateBy(startangle,vectr,CenterPoint);
					AcGePoint3d t3=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
						CenterPoint.y+(Radius+SizeA)*sin(Swectangle),
						CenterPoint.z
						).rotateBy(startangle,vectr,CenterPoint);
					AcGePoint3d t4=AcGePoint3d(Radius+CenterPoint.x,
						CenterPoint.y+(Radius+SizeA/2)*sin(Swectangle),
						CenterPoint.z
						).rotateBy(startangle,vectr,CenterPoint);
					AcGePoint3d t5=AcGePoint3d(Radius+CenterPoint.x,
						CenterPoint.y,
						CenterPoint.z
						).rotateBy(startangle,vectr,CenterPoint);

					AcGePoint3d mm=AcGePoint3d(Radius+SizeA/2+CenterPoint.x,
						(SizeA/2+Radius)*sin(Swectangle)+CenterPoint.y,
						CenterPoint.z
						);

					AcGePoint3d p1=AcGePoint3d(mm.x+SizeA/2+Otstup,
						mm.y,
						mm.z
						);

					AcGePoint3d p2=AcGePoint3d(mm.x,
						mm.y+(Radius+SizeA)*sin(Swectangle)-(Radius+SizeA/2)*sin(Swectangle)+Otstup,
						mm.z
						);
					AcGePoint3d p3=AcGePoint3d(mm.x-SizeA/2-Otstup,
						mm.y,
						mm.z
						);
					AcGePoint3d p4=AcGePoint3d(mm.x,
						mm.y-(Radius+SizeA)*sin(Swectangle)+(Radius+SizeA/2)*sin(Swectangle)-Otstup,
						mm.z
						);
					AcGePoint3d p5=AcGePoint3d(mm.x,
						CenterPoint.y,
						mm.z
						);



					AcDbEllipse* el=new AcDbEllipse(mm,AcGeVector3d(0,0,1),AcGeVector3d(SizeA/2,0,0),((Radius+SizeA)*sin(Swectangle)-(Radius+SizeA/2)*sin(Swectangle))/(SizeA/2),0,M_PI);
					AcDbEllipse* el2=new AcDbEllipse(mm,AcGeVector3d(0,0,1),AcGeVector3d(SizeA/2,0,0),((Radius+SizeA)*sin(Swectangle)-(Radius+SizeA/2)*sin(Swectangle))/(SizeA/2),M_PI,0);
					AcDbEllipse* el3;
					double radiusparam;
					double radius2=(Radius+SizeA)*sin(Swectangle)-(Radius+SizeA/2)*sin(Swectangle);
					if (radius2<=SizeA*3/8)
					{
						el3=new AcDbEllipse(mm,AcGeVector3d(0,0,1),AcGeVector3d(SizeA*3/8,0,0),radius2/(SizeA*3/8),M_PI*3/2,M_PI/2);
					}
					else
					{
						el3=new AcDbEllipse(mm,AcGeVector3d(0,0,1),AcGeVector3d(0,radius2,0),(SizeA*3/8)/radius2,M_PI,0);
					}



					AcDbLine*pLine1 = new AcDbLine(p1,p3);
					AcDbLine*pLine2 = new AcDbLine(p2,p5);
					AcDbPolyline*pLn = new AcDbPolyline();
					pLn->addVertexAt(0,AcGePoint2d(t2.x,t2.y));
					pLn->addVertexAt(1,AcGePoint2d(t1.x,t1.y));
					pLn->addVertexAt(2,AcGePoint2d(t5.x,t5.y));
					pLn->addVertexAt(3,AcGePoint2d(t4.x,t4.y));


					AcGeMatrix3d mat; 
					mat.setToRotation(startangle,AcGeVector3d(0,0,1),CenterPoint); 


					el->transformBy(mat);
					el2->transformBy(mat);
					el3->transformBy(mat);
					pLine1->transformBy(mat);
					pLine2->transformBy(mat);

					if (Wipeout==true)
					{
						AcDbPolyline*pLn = new AcDbPolyline();
						pLn->addVertexAt(0,AcGePoint2d(MA.x,MA.y));
						pLn->addVertexAt(1,AcGePoint2d(t3.x,t3.y));
						setWipeoutProperty(mode,pLn);
						
					}

					if (This1D==true)
					{
						AcDbLine*pLine1 = new AcDbLine(MA,mm.rotateBy(startangle,vectr,CenterPoint));
						setMainProperty(pLine1);
						AcDbCircle *crcl = new AcDbCircle(MC,AcGeVector3d(0,0,1),50);
						setMainProperty(crcl);
					}

					else 
					{
						double l1=(double) 89.5*M_PI/180, l2=90.5*(double)M_PI/180;
						if (Form==Form_Up)
						{
							
							if ((Swectangle> l1) && (Swectangle< l2))
							{
							
								setMainProperty(el);
								setMainProperty(el2);
								setMainProperty(el3);
								setCenterProperty(pLine1);
								setCenterProperty(pLine2);
								setMainProperty(pLn);
							
							
							}
							else
							{

								setHideProperty(el);
								setMainProperty(el2);
								setCenterProperty(pLine1);
								setCenterProperty(pLine2);
								setMainProperty(pLn);
							
							}
						}
						else
						{
							if ((Swectangle> l1) && (Swectangle< l2))
							{

								setMainProperty(el);
								setHideProperty(el2);
								setCenterProperty(el3);
								setCenterProperty(pLine1);
								setCenterProperty(pLine2);
								setMainProperty(pLn);
							

							}
							else
							{

								setMainProperty(el);
								setHideProperty(el2);
								setCenterProperty(pLine1);
								setCenterProperty(pLine2);
								setMainProperty(pLn);
							
							}
						}



					
					}








































			}

			}
#pragma endregion




}
	}

#pragma endregion Duct type still


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


Adesk::UInt32 TVS_TAP::subSetAttributes (AcGiDrawableTraits *traits) {
	assertReadEnabled () ;
	return (AcDbCurve::subSetAttributes (traits)) ;
}

//- Osnap points protocol
Acad::ErrorStatus TVS_TAP::subGetOsnapPoints (
	AcDb::OsnapMode osnapMode,
	Adesk::GsMarker gsSelectionMark,
	const AcGePoint3d &pickPoint,
	const AcGePoint3d &lastPoint,
	const AcGeMatrix3d &viewXform,
	AcGePoint3dArray &snapPoints,
	AcDbIntArray &geomIds) const
{
	assertReadEnabled () ;

	//AcGeLine3d line1,line2;
	//line1.set(B,C); 
	//line2.set(D,A); 
			Acad::ErrorStatus er;
// 	switch (osnapMode) {
// 
// 	case AcDb::kOsModeEnd:
// 		int ind;
// 		AcDbPolyline * pLn;
// 		Acad::ErrorStatus er;
// 		for each (AcDbEntity * var in ListOfEntity)
// 		{
// // 			if ( (pLn = AcDbPolyline::cast(var)) != NULL )
// // 			{
// // 				ind=pLn->numVerts();
// // 				for (int i=0;i<ind;i++)
// // 				{
// // 					AcGePoint2d curpnt;
// // 					pLn->getPointAt(i,curpnt);
// // 					snapPoints.append(AcGePoint3d(curpnt.x,curpnt.y,0));
// // 				}
// // 			}
// 
// 			er=var->getOsnapPoints(osnapMode,gsSelectionMark,pickPoint,
// 				lastPoint,viewXform,snapPoints,geomIds);
// 			if (er!=Acad::eOk)
// 				return er;
// 		}
// // snapPoints.append(MA);
// // 
// // snapPoints.append(MC);
// // snapPoints.append(MiddlePoint);
// 
// 		break;
// 		/*
// 		case AcDb::kOsModeCen:
// 		snapPoints.append(MA);
// 
// 		snapPoints.append(MC);
// 
// 
// 		break;
// 		*/
// 
// 	case AcDb::kOsModePerp: 
// 
// // 		snapPoints.append(line1.closestPointTo(lastPoint));
// // 		snapPoints.append(line2.closestPointTo(lastPoint));
// 		break;
// 	}


	for each (AcDbEntity * var in ListOfEntity)
	{
		// 			if ( (pLn = AcDbPolyline::cast(var)) != NULL )
		// 			{
		// 				ind=pLn->numVerts();
		// 				for (int i=0;i<ind;i++)
		// 				{
		// 					AcGePoint2d curpnt;
		// 					pLn->getPointAt(i,curpnt);
		// 					snapPoints.append(AcGePoint3d(curpnt.x,curpnt.y,0));
		// 				}
		// 			}

		er=var->getOsnapPoints(osnapMode,gsSelectionMark,pickPoint,
			lastPoint,viewXform,snapPoints,geomIds);
		if (er!=Acad::eOk)
			return er;
	}
	return (Acad::eOk);
}

Acad::ErrorStatus TVS_TAP::subGetOsnapPoints (
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
Acad::ErrorStatus TVS_TAP::subGetGripPoints (
	AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds
	) const {
		assertReadEnabled () ;
		//----- This method is never called unless you return eNotImplemented 
		//----- from the new getGripPoints() method below (which is the default implementation)
		//gripPoints.append(CenterPoint);
		
		gripPoints.append(MA);
		gripPoints.append(MC);
		
		if (Form==Form_Direct)
		{
			gripPoints.append(MiddlePoint);
		}
		//gripPoints.append(D);
		return (Acad::eOk);
}

Acad::ErrorStatus TVS_TAP::subMoveGripPointsAt (const AcDbIntArray &indices, const AcGeVector3d &offset) {
	//----- This method is never called unless you return eNotImplemented 
	//----- from the new moveGripPointsAt() method below (which is the default implementation)
	assertWriteEnabled();
	double Pi=3.14159265358979323846;
	for(int i=0; i<indices.length(); i++)
	{
		int idx = indices.at(i);
		// For FP and center point

		if (idx>=0) MiddlePoint += offset;


		//if (idx==1) 

		//{
		//	double x1, y1, x2, y2, startangle;
		//	AcGeVector3d vect;
		//	x1=offset.x;
		//	y1=offset.y;
		//	
		//	vect=AcGeVector3d(x1,y1,0);
		//		Startvector=vect.normalize();
		//	
		//}





		//if (idx==2) 

		//		{
		//double x1, y1, x2, y2, startangle;
		//x1=offset.x;
		//y1=offset.y;
		//startangle=acos((1*x1+0)/sqrt(x1*x1+y1*y1));
		//if (y1<0)
		//{
		//	startangle=2*Pi-startangle;
		//	
		//}
		//Swectangle=Swectangle+startangle;
		//		}
		//		
		//
	}
	return (Acad::eOk);
}

Acad::ErrorStatus TVS_TAP::subGetGripPoints (
	AcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, 
	const AcGeVector3d &curViewDir, const int bitflags
	) const {
		assertReadEnabled () ;

		//----- If you return eNotImplemented here, that will force AutoCAD to call
		//----- the older getGripPoints() implementation. The call below may return
		//----- eNotImplemented depending of your base class.
		return (AcDbCurve::subGetGripPoints (grips, curViewUnitSize, gripSize, curViewDir, bitflags)) ;
}

Acad::ErrorStatus TVS_TAP::subMoveGripPointsAt (
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
Adesk::Boolean TVS_TAP::isClosed () const {
	assertReadEnabled () ;
	return (AcDbCurve::isClosed ()) ;
}

Adesk::Boolean TVS_TAP::isPeriodic () const {
	assertReadEnabled () ;
	return (AcDbCurve::isPeriodic ()) ;
}

//- Get planar and start/end geometric properties.
Acad::ErrorStatus TVS_TAP::getStartParam (double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getStartParam (param)) ;
}

Acad::ErrorStatus TVS_TAP::getEndParam (double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getEndParam (param)) ;
}

Acad::ErrorStatus TVS_TAP::getStartPoint (AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getStartPoint (point)) ;
}

Acad::ErrorStatus TVS_TAP::getEndPoint (AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getEndPoint (point)) ;
}

//- Conversions to/from parametric/world/distance.
Acad::ErrorStatus TVS_TAP::getPointAtParam (double param, AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getPointAtParam (param, point)) ;
}

Acad::ErrorStatus TVS_TAP::getParamAtPoint (const AcGePoint3d &point, double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getParamAtPoint (point, param)) ;
}

Acad::ErrorStatus TVS_TAP::getDistAtParam (double param, double &dist) const {
	assertReadEnabled () ;
	return (AcDbCurve::getDistAtParam (param, dist)) ;
}

Acad::ErrorStatus TVS_TAP::getParamAtDist (double dist, double &param) const {
	assertReadEnabled () ;
	return (AcDbCurve::getParamAtDist (dist, param)) ;
}

Acad::ErrorStatus TVS_TAP::getDistAtPoint (const AcGePoint3d &point , double &dist) const {
	assertReadEnabled () ;
	return (AcDbCurve::getDistAtPoint (point, dist)) ;
}

Acad::ErrorStatus TVS_TAP::getPointAtDist (double dist, AcGePoint3d &point) const {
	assertReadEnabled () ;
	return (AcDbCurve::getPointAtDist (dist, point)) ;
}

//- Derivative information.
Acad::ErrorStatus TVS_TAP::getFirstDeriv (double param, AcGeVector3d &firstDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getFirstDeriv (param, firstDeriv)) ;
}

Acad::ErrorStatus TVS_TAP::getFirstDeriv  (const AcGePoint3d &point, AcGeVector3d &firstDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getFirstDeriv (point, firstDeriv)) ;
}

Acad::ErrorStatus TVS_TAP::getSecondDeriv (double param, AcGeVector3d &secDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSecondDeriv (param, secDeriv)) ;
}

Acad::ErrorStatus TVS_TAP::getSecondDeriv (const AcGePoint3d &point, AcGeVector3d &secDeriv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSecondDeriv (point, secDeriv)) ;
}

//- Closest point on curve.
Acad::ErrorStatus TVS_TAP::getClosestPointTo (const AcGePoint3d &givenPnt, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const {
	assertReadEnabled () ;
	return (AcDbCurve::getClosestPointTo (givenPnt, pointOnCurve, extend)) ;
}

Acad::ErrorStatus TVS_TAP::getClosestPointTo (const AcGePoint3d &givenPnt, const AcGeVector3d &direction, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const {
	assertReadEnabled () ;
	return (AcDbCurve::getClosestPointTo (givenPnt, direction, pointOnCurve, extend)) ;
}

//- Get a projected copy of the curve.
Acad::ErrorStatus TVS_TAP::getOrthoProjectedCurve (const AcGePlane &plane, AcDbCurve *&projCrv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOrthoProjectedCurve (plane, projCrv)) ;
}

Acad::ErrorStatus TVS_TAP::getProjectedCurve (const AcGePlane &plane, const AcGeVector3d &projDir, AcDbCurve *&projCrv) const {
	assertReadEnabled () ;
	return (AcDbCurve::getProjectedCurve (plane, projDir, projCrv)) ;
}

//- Get offset, spline and split copies of the curve.
Acad::ErrorStatus TVS_TAP::getOffsetCurves (double offsetDist, AcDbVoidPtrArray &offsetCurves) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOffsetCurves (offsetDist, offsetCurves)) ;
}

Acad::ErrorStatus TVS_TAP::getOffsetCurvesGivenPlaneNormal (const AcGeVector3d &normal, double offsetDist, AcDbVoidPtrArray &offsetCurves) const {
	assertReadEnabled () ;
	return (AcDbCurve::getOffsetCurvesGivenPlaneNormal (normal, offsetDist, offsetCurves)) ;
}

Acad::ErrorStatus TVS_TAP::getSpline (AcDbSpline *&spline) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSpline (spline)) ;
}

Acad::ErrorStatus TVS_TAP::getSplitCurves (const AcGeDoubleArray &params, AcDbVoidPtrArray &curveSegments) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSplitCurves (params, curveSegments)) ;
}

Acad::ErrorStatus TVS_TAP::getSplitCurves (const AcGePoint3dArray &points, AcDbVoidPtrArray &curveSegments) const {
	assertReadEnabled () ;
	return (AcDbCurve::getSplitCurves (points, curveSegments)) ;
}

//- Extend the curve.
Acad::ErrorStatus TVS_TAP::extend (double newParam) {
	assertReadEnabled () ;
	return (AcDbCurve::extend (newParam)) ;
}

Acad::ErrorStatus TVS_TAP::extend (Adesk::Boolean extendStart, const AcGePoint3d &toPoint) {
	assertReadEnabled () ;
	return (AcDbCurve::extend (extendStart, toPoint)) ;
}

//- Area calculation.
Acad::ErrorStatus TVS_TAP::getArea (double &area) const {
	assertReadEnabled () ;
	return (AcDbCurve::getArea (area)) ;
}

void TVS_TAP::getName(CString &unit)
{
	unit = CCommonTapName;
}

///////////////////









TVS_TAP *TVS_TAP::add_new( double &pSizeA,
						  double &pSizeB,
						  double &pRadius,
						  AcGeVector3d &pNormvector,
						  AcGeVector3d &pStartvector,
						  AcGePoint3d &pMiddlePolint,
						  double &pSwectangle,
						  bool pThis1D,
						  bool pThisRound)
{
	TVS_TAP *pEnt = new TVS_TAP();
	pEnt->Normvector=pNormvector;
	pEnt->SizeA=pSizeA;
	pEnt->SizeB=pSizeB;
	//pTAP->Radius=pRadius;
	pEnt->Startvector=pStartvector;
	pEnt->MiddlePoint=pMiddlePolint;
	pEnt->Swectangle=pSwectangle;
	pEnt->ThisRound=pThisRound;
	pEnt->This1D=pThis1D;
	pEnt->Flow=0;
	pEnt->Direct=0;
	pEnt->Elev=0;
	pEnt->Wipeout=false;
	pEnt->Param=0;
	pEnt->IsPipe=false;
	pEnt->Form=1;
	pEnt->TypeRoundTap=TypeRoundTap_TapSection;
	pEnt->RadiusTypeRect=RadiusTypeRect_RadiusConstant;
	pEnt->RadiusTypeRound=RadiusTypeRound_RadiusSpecific;
	pEnt->RadiusVariableParameter=1;
	pEnt->RadiusConst=150;
	pEnt->Form=Form_Direct;
	pEnt->setNewParameters();

	if (pThisRound==true)
	{
		if (pSizeA<355)
		{
			pEnt->Radius=pSizeA;
		}
		else
		{
			pEnt->Radius=pSizeA/2;
		}
	}
	else
	{
		pEnt->Radius=pRadius;
	}
	// Post to Database
	pEnt->setLinetypeScale(acdbHostApplicationServices()->workingDatabase()->celtscale());
	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable,
		AcDb::kForRead);

	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId retId = AcDbObjectId::kNull;
	pBlockTableRecord->appendAcDbEntity(retId, pEnt);
	pBlockTableRecord->close();
	pEnt->close();
	return pEnt;
}




// -----------------------------------------------------------------------------
Acad::ErrorStatus TVS_TAP::subTransformBy(const AcGeMatrix3d & xform)
{
	assertWriteEnabled () ;
	Acad::ErrorStatus retCode =AcDbEntity::subTransformBy (xform) ;
	MiddlePoint.transformBy(xform);
	Startvector.transformBy(xform);
	return (Acad::eOk);
}


// -----------------------------------------------------------------------------
Acad::ErrorStatus TVS_TAP::subExplode(AcDbVoidPtrArray & entitySet) const
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











double TVS_TAP::get_SizeA(void) const
{
	assertReadEnabled () ;
	return (SizeA) ;
}

Acad::ErrorStatus TVS_TAP::put_SizeA(double newVal)
{
	assertWriteEnabled () ;


	SizeA =newVal ;
	return (Acad::eOk) ;
}
double TVS_TAP::get_SizeB(void) const
{
	assertReadEnabled () ;
	return (SizeB) ;
}

Acad::ErrorStatus TVS_TAP::put_SizeB(double newVal)
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

double TVS_TAP::get_Swectangle(void) const
{
	assertReadEnabled () ;
	return (Swectangle) ;
}

Acad::ErrorStatus TVS_TAP::put_Swectangle(double newVal)
{
	assertWriteEnabled () ;
	Swectangle =newVal ;
	return (Acad::eOk) ;
}
AcGeVector3d TVS_TAP::get_Startvector(void) const
{
	assertReadEnabled () ;
	return (Startvector) ;
}

Acad::ErrorStatus TVS_TAP::put_Startvector(AcGeVector3d newVal)
{
	assertWriteEnabled () ;
	Startvector =newVal ;
	return (Acad::eOk) ;
}

AcGePoint3d TVS_TAP::get_Centerpoint(void) const
{
	assertReadEnabled () ;
	return (MiddlePoint) ;
}

Acad::ErrorStatus TVS_TAP::put_Centerpoint(AcGePoint3d newVal)
{
	assertWriteEnabled () ;
	MiddlePoint=newVal ;
	return (Acad::eOk) ;
}

void TVS_TAP::DrawformUpdown()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void TVS_TAP::DrawDirect()
{
	// 	double Pi=3.14159265358979323846;
	// 	double  Lx, Ly,Nx, Ny;
	// 
	// 	Nx=Startvector.x;
	// 	Ny=Startvector.y;
	// 	Lx=Nx;
	// 	Ly=Ny;
	// 
	// 	startangle=acos((1*Lx+0)/sqrt(Lx*Lx+Ly*Ly));
	// 	if (Ny<0)
	// 	{
	// 		startangle=2*Pi-startangle;
	// 	}
	// 
	// 	if (ThisRound==false)
	// 	{
	// 		Radius=150;
	// 
	// 
	// 		A=AcGePoint3d((Radius+SizeA)*cos(startangle)+CenterPoint.x,
	// 			(Radius+SizeA)*sin(startangle)+CenterPoint.y,
	// 			CenterPoint.z
	// 			);
	// 
	// 		B=AcGePoint3d((Radius+SizeA)*cos(startangle+Swectangle)+CenterPoint.x,
	// 			(Radius+SizeA)*sin(startangle+Swectangle)+CenterPoint.y,
	// 			CenterPoint.z
	// 			);
	// 		C=AcGePoint3d((Radius)*cos(startangle+Swectangle)+CenterPoint.x,
	// 			(Radius)*sin(startangle+Swectangle)+CenterPoint.y,
	// 			CenterPoint.z
	// 			);
	// 		D=AcGePoint3d((Radius)*cos(startangle)+CenterPoint.x,
	// 			(Radius)*sin(startangle)+CenterPoint.y,
	// 			CenterPoint.z
	// 			);
	// 		MiddlePoint=AcGePoint3d((Radius+SizeA/2)/cos(Swectangle/2)*cos(startangle+Swectangle/2)+CenterPoint.x,
	// 			(Radius+SizeA/2)/cos(Swectangle/2)*sin(startangle+Swectangle/2)+CenterPoint.y,
	// 			CenterPoint.z
	// 			);
	// 
	// 		MA=AcGePoint3d((Radius+SizeA/2)*cos(startangle)+CenterPoint.x,
	// 			(Radius+SizeA/2)*sin(startangle)+CenterPoint.y,
	// 			CenterPoint.z
	// 			);
	// 		MC=AcGePoint3d((Radius+SizeA/2)*cos(startangle+Swectangle)+CenterPoint.x,
	// 			(Radius+SizeA/2)*sin(startangle+Swectangle)+CenterPoint.y,
	// 			CenterPoint.z
	// 			);
	// 
	// 		L1[0]=A;
	// 		L1[1]=D;
	// 		L2[0]=B;
	// 		L2[1]=C;
	// 
	// 		///////Wipeout
	// 		if (Wipeout==true)
	// 		{
	// 			AcCmColor backcolor;
	// 			get_WipeoutColor(mode,backcolor);
	// 
	// 
	// 
	// 
	// 			AcGePoint2d p[2];
	// 			p[0]=AcGePoint2d(MA.x,MA.y);
	// 			p[1]=AcGePoint2d(MC.x,MC.y);
	// 			AcDbPolyline *pLn=new AcDbPolyline(2);
	// 
	// 
	// 
	// 			pLn->addVertexAt(0,p[0],tan(Swectangle/4));
	// 			pLn->addVertexAt(1,p[1],tan(Swectangle/4));
	// 			pLn->setColor(backcolor);
	// 			if (This1D==false) pLn->setConstantWidth(SizeA+200);
	// 			else pLn->setConstantWidth(200);
	// 			mode->geometry().draw(pLn);	
	// 			delete pLn;
	// 			AcCmEntityColor col;
	// 			col=color().entityColor();
	// 			mode->subEntityTraits().setTrueColor(col);
	// 		}///////
	// 
	// 		if (This1D==true)
	// 		{
	// 			mode->geometry().circularArc(CenterPoint,Radius+SizeA/2,Normvector,Startvector,Swectangle);
	// 
	// 
	// 
	// 		}
	// 		else
	// 		{
	// 
	// 
	// 
	// 			mode->geometry().polyline(2,L1);
	// 			mode->geometry().polyline(2,L2);
	// 			mode->geometry().circularArc(CenterPoint,Radius+SizeA,Normvector,Startvector,Swectangle);
	// 			mode->geometry().circularArc(CenterPoint,Radius,Normvector,Startvector,Swectangle);
	// 
	// 
	// 
	// 		}
	// 	}
	// 	else
	// 	{
	// 		if (SizeA<355)
	// 		{
	// 			Radius=SizeA;
	// 		}
	// 		else 
	// 		{
	// 			Radius=SizeA/2;
	// 		}
	// 
	// 		double flanez=0;
	// 
	// 
	// 		if(SizeA<630)
	// 		{
	// 			flanez=45;
	// 		}
	// 		AcGePoint3d pM16,pM25;
	// 		double bigRl=atan(flanez/(Radius+SizeA));
	// 		double smallRl=atan(flanez/(Radius));
	// 		double midRl=atan(flanez/(Radius+SizeA/2));
	// 		double smallRAD=sqrt(flanez*flanez+(Radius)*(Radius));
	// 		double bigRAD=sqrt(flanez*flanez+(Radius+SizeA)*(Radius+SizeA));
	// 		double MidRad=sqrt(flanez*flanez+(Radius+SizeA/2)*(Radius+SizeA/2));
	// 
	// 
	// 		double alpha;
	// 		if (Swectangle>(Pi/4+0.01))
	// 		{
	// 			//segments=3;
	// 			alpha=Swectangle/4;
	// 
	// 
	// 			pMass[0]=AcGePoint3d((bigRAD)*cos(startangle+Swectangle+bigRl)+CenterPoint.x,
	// 				(bigRAD)*sin(startangle+Swectangle+bigRl)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 
	// 			pMass[1]=AcGePoint3d((Radius+SizeA)/cos(alpha)*cos(startangle+3*alpha)+CenterPoint.x,
	// 				(Radius+SizeA)/cos(alpha)*sin(startangle+3*alpha)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			pMass[2]=AcGePoint3d((Radius+SizeA)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
	// 				(Radius+SizeA)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			pMass[3]=AcGePoint3d((bigRAD)*cos(startangle-bigRl)+CenterPoint.x,
	// 				(bigRAD)*sin(startangle-bigRl)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			pMass[4]=AcGePoint3d((smallRAD)*cos(startangle-smallRl)+CenterPoint.x,
	// 				(smallRAD)*sin(startangle-smallRl)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			pMass[5]=AcGePoint3d((Radius)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
	// 				(Radius)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			pMass[6]=AcGePoint3d((Radius)/cos(alpha)*cos(startangle+3*alpha)+CenterPoint.x,
	// 				(Radius)/cos(alpha)*sin(startangle+3*alpha)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 
	// 			pMass[7]=AcGePoint3d((smallRAD)*cos(startangle+Swectangle+smallRl)+CenterPoint.x,
	// 				(smallRAD)*sin(startangle+Swectangle+smallRl)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			pM25=AcGePoint3d((Radius+SizeA/2)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
	// 				(Radius+SizeA/2)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			pM16=AcGePoint3d((Radius+SizeA/2)/cos(alpha)*cos(startangle+alpha*3)+CenterPoint.x,
	// 				(Radius+SizeA/2)/cos(alpha)*sin(startangle+alpha*3)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			MiddlePoint=AcGePoint3d((Radius+SizeA/2)/cos(Swectangle/2)*cos(startangle+Swectangle/2)+CenterPoint.x,
	// 				(Radius+SizeA/2)/cos(Swectangle/2)*sin(startangle+Swectangle/2)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 
	// 			MA=AcGePoint3d((MidRad)*cos(startangle+Swectangle+midRl)+CenterPoint.x,
	// 				(MidRad)*sin(startangle+Swectangle+midRl)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			MC=AcGePoint3d((MidRad)*cos(startangle-midRl)+CenterPoint.x,
	// 				(MidRad)*sin(startangle-midRl)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 
	// 
	// 
	// 			if (Wipeout==true) //wipe
	// 			{
	// 				AcCmColor backcolor;
	// 				get_WipeoutColor(mode,backcolor);
	// 
	// 
	// 				AcGePoint2d p[4];
	// 				p[0]=AcGePoint2d(MA.x,MA.y);
	// 				p[1]=AcGePoint2d((Radius+SizeA/2)/cos(alpha)*cos(startangle+3*alpha)+CenterPoint.x,
	// 					(Radius+SizeA/2)/cos(alpha)*sin(startangle+3*alpha)+CenterPoint.y
	// 					);
	// 				p[2]=AcGePoint2d((Radius+SizeA/2)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
	// 					(Radius+SizeA/2)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y
	// 					);
	// 				p[3]=AcGePoint2d(MC.x,MC.y);
	// 
	// 
	// 
	// 				AcDbPolyline *pLn=new AcDbPolyline(4);
	// 
	// 
	// 
	// 
	// 				for (int i=0;i<4; i++)
	// 				{
	// 					pLn->addVertexAt(i,p[i]);
	// 				}
	// 				pLn->setColor(backcolor);
	// 				if (This1D==false) pLn->setConstantWidth(SizeA+200);
	// 				else pLn->setConstantWidth(200);
	// 				mode->geometry().draw(pLn);	
	// 				delete pLn;
	// 				AcCmEntityColor col;
	// 				col=color().entityColor();
	// 				mode->subEntityTraits().setTrueColor(col);
	// 
	// 			}//wipe
	// 
	// 
	// 
	// 			if (This1D==false)
	// 			{
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 				mode->geometry().polygon(8,pMass);
	// 
	// 				L1[0]=pMass[1];
	// 				L1[1]=pMass[6];
	// 				mode->geometry().polyline(2,L1);
	// 				L1[0]=pMass[2];
	// 				L1[1]=pMass[5];
	// 				mode->geometry().polyline(2,L1);
	// 
	// 				AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
	// 				AcDbLinetypeTable *pLtTable;
	// 				AcDbObjectId ltId;
	// 				pDb->getSymbolTable(pLtTable, AcDb::kForRead);
	// 				pLtTable->getAt(_T("tvs_centerline"), ltId);
	// 				mode->subEntityTraits().setLineType(ltId);
	// 				mode->subEntityTraits().setLineWeight(AcDb::LineWeight(15));
	// 				pLtTable->close();
	// 
	// 				pMassO[0]=MA;
	// 				pMassO[1]=pM16;
	// 				pMassO[2]=pM25;
	// 				pMassO[3]=MC;
	// 				mode->geometry().polyline(4,pMassO);
	// 
	// 			}
	// 			else
	// 			{
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 				pMassO[0]=MA;
	// 				pMassO[1]=pM16;
	// 				pMassO[2]=pM25;
	// 				pMassO[3]=MC;
	// 				mode->geometry().polyline(4,pMassO);
	// 			}
	// 
	// 		}
	// 		else
	// 		{
	// 			//segments=2;
	// 			alpha=Swectangle/2;
	// 
	// 
	// 			pMass45[0]=AcGePoint3d((bigRAD)*cos(startangle+Swectangle+bigRl)+CenterPoint.x,
	// 				(bigRAD)*sin(startangle+Swectangle+bigRl)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 
	// 			pMass45[1]=AcGePoint3d((Radius+SizeA)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
	// 				(Radius+SizeA)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 
	// 			pMass45[2]=AcGePoint3d((bigRAD)*cos(startangle-bigRl)+CenterPoint.x,
	// 				(bigRAD)*sin(startangle-bigRl)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			pMass45[3]=AcGePoint3d((smallRAD)*cos(startangle-smallRl)+CenterPoint.x,
	// 				(smallRAD)*sin(startangle-smallRl)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			pMass45[4]=AcGePoint3d((Radius)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
	// 				(Radius)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 
	// 
	// 			pMass45[5]=AcGePoint3d((smallRAD)*cos(startangle+Swectangle+smallRl)+CenterPoint.x,
	// 				(smallRAD)*sin(startangle+Swectangle+smallRl)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			pM16=AcGePoint3d((Radius+SizeA/2)/cos(alpha)*cos(startangle+alpha)+CenterPoint.x,
	// 				(Radius+SizeA/2)/cos(alpha)*sin(startangle+alpha)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			MiddlePoint=AcGePoint3d((Radius+SizeA/2)/cos(Swectangle/2)*cos(startangle+Swectangle/2)+CenterPoint.x,
	// 				(Radius+SizeA/2)/cos(Swectangle/2)*sin(startangle+Swectangle/2)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 
	// 			MA=AcGePoint3d((MidRad)*cos(startangle+Swectangle+midRl)+CenterPoint.x,
	// 				(MidRad)*sin(startangle+Swectangle+midRl)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 			MC=AcGePoint3d((MidRad)*cos(startangle-midRl)+CenterPoint.x,
	// 				(MidRad)*sin(startangle-midRl)+CenterPoint.y,
	// 				CenterPoint.z
	// 				);
	// 
	// 			if (Wipeout==true) //wipe
	// 			{
	// 				AcCmColor backcolor;
	// 				get_WipeoutColor(mode,backcolor);
	// 
	// 
	// 
	// 				AcGePoint2d p[3];
	// 				p[0]=AcGePoint2d(MA.x,MA.y);
	// 				p[1]=AcGePoint2d(MiddlePoint.x,MiddlePoint.y);
	// 				p[2]=AcGePoint2d(MC.x,MC.y);
	// 
	// 
	// 
	// 				AcDbPolyline *pLn=new AcDbPolyline(3);
	// 
	// 
	// 
	// 
	// 				for (int i=0;i<3; i++)
	// 				{
	// 					pLn->addVertexAt(i,p[i]);
	// 				}
	// 				pLn->setColor(backcolor);
	// 				if (This1D==false) pLn->setConstantWidth(SizeA+200);
	// 				else pLn->setConstantWidth(200);
	// 				mode->geometry().draw(pLn);	
	// 				delete pLn;
	// 				AcCmEntityColor col;
	// 				col=color().entityColor();
	// 				mode->subEntityTraits().setTrueColor(col);
	// 
	// 			}//wipe
	// 
	// 
	// 
	// 
	// 			if (This1D==false)
	// 			{
	// 
	// 
	// 
	// 				mode->geometry().polygon(6,pMass45);
	// 
	// 				L1[0]=pMass45[1];
	// 				L1[1]=pMass45[4];
	// 				mode->geometry().polyline(2,L1);
	// 				AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
	// 				AcDbLinetypeTable *pLtTable;
	// 				AcDbObjectId ltId;
	// 				pDb->getSymbolTable(pLtTable, AcDb::kForRead);
	// 				pLtTable->getAt(_T("tvs_centerline"), ltId);
	// 				mode->subEntityTraits().setLineType(ltId);
	// 				mode->subEntityTraits().setLineWeight(AcDb::LineWeight(15));
	// 				pLtTable->close();
	// 
	// 				pMassO45[0]=MA;
	// 				pMassO45[1]=pM16;
	// 				pMassO45[2]=MC;
	// 				mode->geometry().polyline(3,pMassO45);
	// 
	// 			}
	// 			else
	// 			{
	// 
	// 
	// 
	// 
	// 
	// 				pMassO45[0]=MA;
	// 				pMassO45[1]=pM16;
	// 				pMassO45[2]=MC;
	// 				mode->geometry().polyline(3,pMassO45);
	// 			}
	// 
	// 		}
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 	}
}
int TVS_TAP::get_TypeRoundTap(void) const
{
	assertReadEnabled () ;
	return (TypeRoundTap);

}
Acad::ErrorStatus TVS_TAP::put_TypeRoundTap(int newVal)
{
	assertWriteEnabled () ;
	TypeRoundTap =newVal ;
	return (Acad::eOk) ;
}
int TVS_TAP::get_RadiusTypeRound(void) const
{
	assertReadEnabled () ;
	return RadiusTypeRound;

}
Acad::ErrorStatus TVS_TAP::put_RadiusTypeRound(int newVal)
{
	assertWriteEnabled () ;
	RadiusTypeRound =newVal ;
	return (Acad::eOk) ;
}
Acad::ErrorStatus TVS_TAP::put_Radius(double newVal)
{
	assertWriteEnabled () ;
	Radius =newVal ;
	return (Acad::eOk) ;
}

double TVS_TAP::get_radius(void) const
{
	assertReadEnabled () ;
	return (Radius) ;
}

void TVS_TAP::setRadius()
{
	if (DuctType==DuctTypeFlex)
	{
		Radius=SizeA*RadiusVariableParameter;
		return;
	}
	if (ThisRound==true)
	{
		switch ((int)RadiusTypeRound)
		{
		case RadiusTypeRound_RadiusConstant:
			Radius=RadiusConst;
			return;
		case RadiusTypeRound_RadiusSpecific:
			if (SizeA<355)
			{
				Radius=SizeA;
			}
			else Radius=SizeA/2;
			return;
		case RadiusTypeRound_RadiusVariable:
			Radius=SizeA*RadiusVariableParameter;
			return;

		default:
			return;
		}
	}
	else
	{
		switch ((int)RadiusTypeRect)
		{
		case RadiusTypeRect_RadiusConstant:
			Radius=RadiusConst;
			return;
		case RadiusTypeRect_RadiusSpecific:
			if (SizeA<355)
			{
				Radius=SizeA;
			}
			else Radius=SizeA/2;
			return;
		case RadiusTypeRect_RadiusVariable:
			Radius=SizeA*RadiusVariableParameter;
			return;

		default:
			return;
		}
	}




}

int TVS_TAP::get_Form(void) const
{
	return(Form);
}

Acad::ErrorStatus TVS_TAP::put_Form(int newVal)
{
	assertWriteEnabled () ;
	Form =newVal ;
	return (Acad::eOk) ;
}

void TVS_TAP::checkRadiusTypeRound()
{

	switch ((int)RadiusTypeRound)
	{ case RadiusTypeRound_RadiusConstant:
	return;
	case RadiusTypeRound_RadiusVariable:
		return;
	case RadiusTypeRound_RadiusSpecific:
		return;
	default:
		RadiusTypeRound=RadiusTypeRound_RadiusSpecific;
		RadiusConst=150;
		return;
	}

}

void TVS_TAP::checkRadiusTypeRect()
{

	switch ((int)RadiusTypeRect)
	{ case RadiusTypeRect_RadiusConstant:
	return;
	case RadiusTypeRect_RadiusVariable:
		return;
	case RadiusTypeRect_RadiusSpecific:
		return;
	default:
		RadiusTypeRect=RadiusTypeRect_RadiusConstant;
		RadiusConst=150;
		return;
	}

}

void TVS_TAP::checkTypeRoundTap()
{

	switch ((int)TypeRoundTap)
	{ case TypeRoundTap_TapSection:
	return;
	case TypeRoundTap_TapRound:
		return;
	default:
		TypeRoundTap=TypeRoundTap_TapSection;
		return;
	}


}
void TVS_TAP::checkForm()
{

	switch ((int)Form)
	{ case Form_Direct:
	return;
	case Form_Down:
		return;
	case Form_Up:
		return;
	default:
		Form=Form_Direct;
		return;
	}


}

int TVS_TAP::get_RadiusTypeRect(void) const
{
	return(RadiusTypeRect);
}

Acad::ErrorStatus TVS_TAP::put_RadiusTypeRect(int newVal)
{
	assertWriteEnabled () ;
	RadiusTypeRect =newVal ;
	return (Acad::eOk) ;
}


int TVS_TAP::get_RadiusVariableParameter(void) const
{
	return(RadiusVariableParameter);
}

void TVS_TAP::setFlex( const bool &isFlex )
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

Acad::ErrorStatus TVS_TAP::put_RadiusVariableParameter(double newVal)
{
	assertWriteEnabled () ;
	RadiusVariableParameter =newVal ;
	return (Acad::eOk) ;
}


int TVS_TAP::get_RadiusConst(void) const
{
	return(RadiusConst);
}

Acad::ErrorStatus TVS_TAP::put_RadiusConst(double newVal)
{
	assertWriteEnabled () ;
	RadiusConst =newVal ;
	return (Acad::eOk) ;
}

void TVS_TAP::chekMiddlePoint()
{
	if (MiddlePoint==AcGePoint3d(0,0,0))
	{
	
	
	
			MiddlePoint=AcGePoint3d((Radius+SizeA/2)/cos(Swectangle/2)*cos(startangle+Swectangle/2)+CenterPoint.x,
				(Radius+SizeA/2)/cos(Swectangle/2)*sin(startangle+Swectangle/2)+CenterPoint.y,
				CenterPoint.z
				);
	}

	return;
}

void TVS_TAP::setDuctType(int pDuctType)
{
	assertWriteEnabled();
	DuctType=pDuctType;
}

