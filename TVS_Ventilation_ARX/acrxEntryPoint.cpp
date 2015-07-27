// (C) Copyright 2002-2012 by Autodesk, Inc. 
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
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#pragma once
#include "StdAfx.h"
#include "resource.h"
#include "Func.h"
#include "tdbl.h"
#include "dbmleader.h"
#include "PipeSizeDiallog.h"
//-----------------------------------------------------------------------------
#define szRDS _RXST("TVS")
#define dCONTINUE 0
#define dCONNECT 1
#define dSIZE 2

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CTVS_Ventilation_ARXApp : public AcRxArxApp {

public:
	CTVS_Ventilation_ARXApp () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		// TODO: Load dependencies here
		tdbl *pdbl=new tdbl;
		pdbl->InitApplication();
		delete pdbl;
		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;
		
		// TODO: Add your initialization code here

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;

		// TODO: Unload dependencies here

		return (retCode) ;
	}

	virtual void RegisterServerComponents () {
	}
	
	// The ACED_ARXCOMMAND_ENTRY_AUTO macro can be applied to any static member 
	// function of the CTVS_Ventilation_ARXApp class.
	// The function should take no arguments and return nothing.
	//
	// NOTE: ACED_ARXCOMMAND_ENTRY_AUTO has overloads where you can provide resourceid and
	// have arguments to define context and command mechanism.
	
	// ACED_ARXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext)
	// ACED_ARXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext)
	// only differs that it creates a localized name using a string in the resource file
	//   locCmdId - resource ID for localized command

	// Modal Command with localized name
	// ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, TVSMyGroup, MyCommand, MyCommandLocal, ACRX_CMD_MODAL)
	static void TVSMyGroupMyCommand () {
		// Put your command code here

	}

	// Modal Command with pickfirst selection
	// ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, TVSMyGroup, MyPickFirst, MyPickFirstLocal, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET)
	static void TVSMyGroupMyPickFirst () {
		ads_name result ;
		int iRet =acedSSGet (ACRX_T("_I"), NULL, NULL, NULL, result) ;
		if ( iRet == RTNORM )
		{
			

			// There are selected entities
			// Put your command using pickfirst set code here
		}
		else
		{
			// There are no selected entities
			// Put your command code here
		}
	}

	// Application Session Command with localized name
	// ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, TVSMyGroup, MySessionCmd, MySessionCmdLocal, ACRX_CMD_MODAL | ACRX_CMD_SESSION)
	static void TVSMyGroupMySessionCmd () {
		// Put your command code here
	}

	// The ACED_ADSFUNCTION_ENTRY_AUTO / ACED_ADSCOMMAND_ENTRY_AUTO macros can be applied to any static member 
	// function of the CTVS_Ventilation_ARXApp class.
	// The function may or may not take arguments and have to return RTNORM, RTERROR, RTCAN, RTFAIL, RTREJ to AutoCAD, but use
	// acedRetNil, acedRetT, acedRetVoid, acedRetInt, acedRetReal, acedRetStr, acedRetPoint, acedRetName, acedRetList, acedRetVal to return
	// a value to the Lisp interpreter.
	//
	// NOTE: ACED_ADSFUNCTION_ENTRY_AUTO / ACED_ADSCOMMAND_ENTRY_AUTO has overloads where you can provide resourceid.
	
	//- ACED_ADSFUNCTION_ENTRY_AUTO(classname, name, regFunc) - this example
	//- ACED_ADSSYMBOL_ENTRYBYID_AUTO(classname, name, nameId, regFunc) - only differs that it creates a localized name using a string in the resource file
	//- ACED_ADSCOMMAND_ENTRY_AUTO(classname, name, regFunc) - a Lisp command (prefix C:)
	//- ACED_ADSCOMMAND_ENTRYBYID_AUTO(classname, name, nameId, regFunc) - only differs that it creates a localized name using a string in the resource file

	// Lisp Function is similar to ARX Command but it creates a lisp 
	// callable function. Many return types are supported not just string
	// or integer.
	// ACED_ADSFUNCTION_ENTRY_AUTO(CTVS_Ventilation_ARXApp, MyLispFunction, false)
	static int ads_MyLispFunction () {
		//struct resbuf *args =acedGetArgs () ;
		
		// Put your command code here

		//acutRelRb (args) ;
		
		// Return a value to the AutoCAD Lisp Interpreter
		// acedRetNil, acedRetT, acedRetVoid, acedRetInt, acedRetReal, acedRetStr, acedRetPoint, acedRetName, acedRetList, acedRetVal

		return (RTNORM) ;
	}
	

	
	static bool changesize ()
	{

	//	ads_real sa,sb;
			double a,b;
// 			a=globSizeA;
// 			b=globSizeB;
// 		if (acedGetReal(_T("\nВведите Ширину:"),&sa) != RTNORM)
// 		{
// 			return false;}
// 
// 		if (acedGetReal(_T("\nВведите Высоту:"),&sb) != RTNORM)
// 		{
// 			return false;}
// 		globSizeA=sa;
// 		globSizeB=sb;
// 		if (globSizeB==0) globRound=true;
// 		else globRound=false;
		
		PipeSizeDiallog r;
		a=r.SizeA=globSizeA;
	b=r.SizeB=globSizeB;
	r.DoModal();
		globSizeA=r.SizeA;
		globSizeB=r.SizeB;
		//a=150;
		//	b=150;
		if (globSizeB==0) globRound=true;
		else globRound=false;
		if (a==globSizeA && b==globSizeB)
			return false; 
		else
			return true;
	}




	static void nextpipe(AcGePoint3d &A1,
		AcGePoint3d &A2,
		AcGePoint3d &A3,
		TVS_Pipe *&pipi,
		ads_point &pt1
		)
	{
		//acutPrintf(_T("Чурчу се ок"));

		double tapradius, radius, pSwectangle;
		AcGePoint3d pCenterpoint;
		AcGePoint3d lastpipi;
		TVS_Pipe pipie;
		TVS_TAP * pTap;
		AcGeVector3d pnormvect=AcGeVector3d(0,0,1);
		AcGeVector3d pstartvect;
		AcDbObjectId id;
		ads_name eName;
		AcDbEntity *pEnt;
		AcGeVector3d vect1,vect2,vect22;
		vect1=AcGeVector3d(A2.x-A1.x,
			A2.y-A1.y,
			A2.z-A1.z);
		vect2=AcGeVector3d(A3.x-A2.x,
			A3.y-A2.y,
			A3.z-A2.z);
		vect22=AcGeVector3d(-A3.x+A2.x,
			-A3.y+A2.y,
			-A3.z+A2.z);
		vect1.normalize();
		vect2.normalize();
		vect22.normalize();
		if ((vect1!=vect2)&&(vect1!=vect22))
		{

			

			pTap=drawTapDirect(A1,A2,A3);
			double delta=length2p(pTap->MA,pTap->MiddlePoint);
			AcGePoint3d A2a=shortlength(A1,A2,delta);
			AcGePoint3d A2b=shortlength(A3,A2,delta);
			if ((length2p(A1,A2)>=delta)&&(length2p(A2,A3)>=delta))
			{
			
				id=pipi->id();
				acdbGetAdsName(eName,id);
				acdbGetObjectId(id,eName);
				acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite);
				pipi->assertWriteEnabled();
				pipi->LastPoint=A2a;
				pipi->close();
				pipi=pipie.add_new(A2b,A3,globSizeA,globSizeB,false,globRound);
				A1=A2;
				A2=A3;

				pt1[0]=A2.x;
				pt1[1]=A2.y;
				pt1[2]=A2.z;

			}
			else
			{
				
				AcDbEntity* pnt;
				acdbOpenAcDbEntity(pnt,pTap->id(),AcDb::kForWrite);
				pTap->erase();
				pTap->close();
				
			}
		}
		else
		{


			id=pipi->id();
			acdbGetAdsName(eName,id);
			acdbGetObjectId(id,eName);
			acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite);
			pipi->assertWriteEnabled();
			pipi->setLastpoint(A3);
			pipi->close();

			A2=A3;

			pt1[0]=A2.x;
			pt1[1]=A2.y;
			pt1[2]=A2.z;


		}

	}


	static void connect2(
		TVS_Pipe *&pipi1
		)

	{

		TVS_Pipe *pipi2;
		bool ft=false;
		bool lt=false;
		int stat;
		ads_point pt1;
		AcDbObjectId id;
		ads_name eName,vozd;
		AcDbEntity *pEnt,*pEnt2;
		while (ft==false)
		{
			while (lt==false)
			{
				stat=acedEntSel (_T("\nВыберете воздуховод:"), vozd,pt1);

				switch (stat)
				{
				case RTNORM:
					lt=true;
					break;
				case RTCAN:
					return;
					break;
				}
			}

			if (acdbGetObjectId(id,vozd)==eOk)
			{

				acdbGetObjectId(id,vozd);

				{if (id!=AcDbObjectId::kNull)
				{
					if (acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite)==eOk)
					{if ( (pipi2 = TVS_Pipe::cast(pEnt)) != NULL )
					{	

						ft=true;

					}
					}

					else {
						consoleprint(0,_T("\nОбьект заблокирован"));

						return;
					}
					pEnt->close();	
				}
				}


			}
		}
		pEnt2=AcDbEntity::cast(pipi1);
		pCon(pEnt2,pEnt);

	}

	static void addtrans(double &pSizeAp1,
		double &pSizeBp1,
		double &pSizeAp2,
		double &pSizeBp2,
		AcGePoint3d &A1,
		AcGePoint3d &A2,
		AcGePoint3d &A3,
		TVS_Pipe *&pipi,
		ads_point &pt1
		)
	{

		TVS_TRANS transie;
		double pLengthTr=300;
		AcGeVector3d Vect=AcGeVector3d(pipi->LastPoint.x-pipi->FirstPoint.x,
			pipi->LastPoint.y-pipi->FirstPoint.y,
			pipi->LastPoint.z-pipi->FirstPoint.z);
		AcGeVector3d pVectTr;
		AcGePoint3d pFirstPoint=pipi->LastPoint;
		pVectTr=Vect.normalize()*pLengthTr;

		double pThisRoundp1,
			pThisRoundp2,
			pTransType=ftTransType,
			pThis1D=false;

		if (pSizeBp1==0) pThisRoundp1=true;
		else pThisRoundp1=false;

		if (pSizeBp2==0) pThisRoundp2=true;
		else pThisRoundp2=false;

		transie.add_new(pSizeAp1,
			pSizeBp1,
			pSizeAp2,
			pSizeBp2,
			pLengthTr,
			pVectTr,
			pFirstPoint,
			pThisRoundp1,
			pThisRoundp2,
			pTransType,
			pThis1D);

		pFirstPoint=AcGePoint3d(pFirstPoint.x+pLengthTr*Vect.x,
			pFirstPoint.y+pLengthTr*Vect.y,
			pFirstPoint.z+pLengthTr*Vect.z
			);
		AcGePoint3d pLastPoint=AcGePoint3d(pFirstPoint.x+100*Vect.x,
			pFirstPoint.y+100*Vect.y,
			pFirstPoint.z+100*Vect.z
			);

		bool pThis1d=false;

		pipi=pipi->add_new(pFirstPoint,
			pLastPoint,
			pSizeAp2,
			pSizeBp2,
			pThis1d,
			pThisRoundp2);

		A1=A2;
		A2=pLastPoint;
		pt1[0]=A2.x;
		pt1[1]=A2.y;
		pt1[2]=A2.z;
	}




	// ----- Ventilation_ARX.TVS_PIPE command
	static void Ventilation_ARXTVS_PIPE(void)
	{

		ads_point pt1,pt2;
		int reg;
		int Astat;
		int Astat2=false;
		ACHAR  resultss [512];
		ACHAR  resultnil [512];
		AcDbEntity* pEnt;

		while (Astat2==false)
		{
			Astat2=true;
			acedInitGet(RSG_NONULL, _T("Размер Р h"));
			Astat=acedGetPoint(NULL,_T("\nУкажите первую точку или [Размер]:"),pt1) ;
			switch (Astat)
			{
			case RTCAN:
				return;
				break;
			case RTKWORD:
				acedGetInput(resultss);
				break;
			}

			if ((wcscmp(resultss,_T("Размер"))==0)||(wcscmp(resultss,_T("Р"))==0)||(wcscmp(resultss,_T("h"))==0))
			{
				reg=dSIZE;
				changesize();
				Astat2=false;
				acdbRToS(0,2,2,resultss);
			}

		}

		Astat2=false;
		while (Astat2==false)
		{
			Astat2=true;
			acedInitGet(RSG_NONULL, _T("Размер Р h Z я"));
			Astat=acedGetPoint(pt1,_T("\nУкажите следущую точку или [Размер]/[Z]:"),pt2) ;
			switch (Astat)
			{
			case RTCAN:
				return;
				break;
			case RTKWORD:
				acedGetInput(resultss);
				break;
			}

			if ((wcscmp(resultss,_T("Размер"))==0)||(wcscmp(resultss,_T("Р"))==0)||(wcscmp(resultss,_T("h"))==0))
			{
				reg=dSIZE;
				changesize();
				Astat2=false;
				acdbRToS(0,2,2,resultss);
			}

			if ((wcscmp(resultss,_T("Z"))==0)||(wcscmp(resultss,_T("я"))==0))
			{
				reg=dSIZE;
				setZ();
				Astat2=false;
				acdbRToS(0,2,2,resultss);
			}

		}

		AcGePoint3d A1=asPnt3d(pt1);
		AcGePoint3d A2=asPnt3d(pt2);
		TVS_Pipe *pipi;
		TVS_Pipe pipie;


		pipi=pipie.add_new(A1,A2,globSizeA,globSizeB,false,globRound);

		if (acdbOpenAcDbEntity(pEnt,pipi->id(),AcDb::kForWrite)==eOk)
		{		
			pipi->close();
		}
		else
		{
			acutPrintf(_T("\nСлой блокирован"));
			return;
		}


		AcGeVector3d pnormvect=AcGeVector3d(0,0,1);
		pt1[0]=A2.x;
		pt1[1]=A2.y;
		pt1[2]=A2.z;

		////////////
		AcGePoint3d A3;
		double oldsizeA, oldsizeB, oldRound;
		for (; ;)
		{


			acedInitGet(RSG_NONULL, _T("Размер Р Соеденить с h c"));
			Astat=acedGetPoint(pt1,_T("\nУкажите следующую точку или [Размер/Соеденить]:"),pt2) ;
			switch (Astat)
			{
			case RTCAN:
				return;
				break;
			case RTKWORD:
				acedGetInput(resultss);
				break;
			case RTNORM:
				A3=asPnt3d(pt2);
				nextpipe(A1,A2,A3,pipi,pt1);

			}


			if ((wcscmp(resultss,_T("Размер"))==0)||(wcscmp(resultss,_T("Р"))==0)||(wcscmp(resultss,_T("h"))==0))
			{
				reg=dSIZE;
				oldsizeA=globSizeA;
				oldsizeB=globSizeB;
				oldRound=globRound;
				if (changesize()==true)
				{
					addtrans(oldsizeA,oldsizeB,globSizeA,globSizeB,A1,A2,A3,pipi,pt1);
				}
				Astat2=false;
				acdbRToS(0,2,2,resultss);
			}
			if ((wcscmp(resultss,_T("Соеденить"))==0)||(wcscmp(resultss,_T("с"))==0)||(wcscmp(resultss,_T("c"))==0))
			{
				reg=dCONNECT;
				connect2(pipi);
				return;
			}







		}





		// Add your code for command TVSTVS_Vent_ARX.TVS_Pipe here
	}


	// - Ventilation_ARX.TVS_TRANS command (do not rename)
	static void Ventilation_ARXTVS_TRANS(void)
	{

		ads_point pt1,pt2;
		double pSizeAp1=500;
		double pSizeBp1=0;
		double pSizeAp2=300;
		double pSizeBp2=0;
		double pLengthTr=300;
		AcGeVector3d pVectTr=AcGeVector3d(1,1,0);
		AcGePoint3d pFirstPoint;
		AcGePoint3d pLastPoint;

		bool pThisRoundp1=false;
		bool pThisRoundp2=false;
		int pTransType=3;
		bool pThis1D=false;
		TVS_TRANS transie;

		if (acedGetPoint(NULL,_T("Set the first point:\n"),pt1) != RTNORM)
			return;
		if (acedGetPoint(pt1,_T("Set the second point:\n"),pt2) != RTNORM)
			return;
		pFirstPoint=asPnt3d(pt1);
		pLastPoint=asPnt3d(pt2);
		pVectTr=AcGeVector3d(pLastPoint.x-pFirstPoint.x,
			pLastPoint.y-pFirstPoint.y,
			pFirstPoint.z 
			);

		transie.add_new(pSizeAp1,
			pSizeBp1,
			pSizeAp2,
			pSizeBp2,
			pLengthTr,
			pVectTr,
			pFirstPoint,
			pThisRoundp1,
			pThisRoundp2,
			pTransType,
			pThis1D);



		// Add your code for command Ventilation_ARX.TVS_TRANS here
	}

	// - Ventilation_ARX.TVS_WYE command (do not rename)
	static void Ventilation_ARXTVS_WYE(void)
	{

		ads_point pt1;
		TVS_WYE wyeie;
		ads_real aSizeAotv,aSizeApr;
		double pSizeApr=200;
		double pSizeBpr=0;
		double pSizeAotv=100;
		double pSizeBotv=0;
		double pLengthPl=150;
		AcGeVector3d pVectpr=AcGeVector3d(1,0,0);
		AcGeVector3d pVectotv=AcGeVector3d(0,1,0);
		AcGePoint3d pBasepoint;
		bool pThisRoundpr=true;
		bool pThisRoundotv=true;
		bool pThis1D=false;

		if (acedGetPoint(NULL,_T("Set the first point:\n"),pt1) != RTNORM)
			return;
		if ( acedGetReal(_T("\nВведите ширину прохода: "),&aSizeApr)!= RTNORM)
			return;
		pSizeApr=aSizeApr;
		if ( acedGetReal(_T("\nВведите ширину ответвления: "),&aSizeAotv)!= RTNORM)
			return;
		pSizeAotv=aSizeAotv;

		pBasepoint=asPnt3d(pt1);
		wyeie.add_new(pSizeApr,
			pSizeBpr,
			pSizeAotv,
			pSizeBotv,
			pLengthPl,
			pVectpr,
			pVectotv,
			pBasepoint,
			pThisRoundpr,
			pThisRoundotv,
			pThis1D);
		wyeie.add_new(pSizeApr,
			pSizeBpr,
			pSizeAotv,
			pSizeBotv,
			pLengthPl,
			pVectpr,
			pVectotv,
			pBasepoint,
			pThisRoundpr,
			false,
			pThis1D);
		wyeie.add_new(pSizeApr,
			pSizeBpr,
			pSizeAotv,
			pSizeBotv,
			pLengthPl,
			pVectpr,
			pVectotv,
			pBasepoint,
			false,
			false,
			pThis1D);
		wyeie.add_new(pSizeApr,
			pSizeBpr,
			pSizeAotv,
			pSizeBotv,
			pLengthPl,
			pVectpr,
			pVectotv,
			pBasepoint,
			false,
			true,
			pThis1D);
		// Add your code for command Ventilation_ARX.TVS_WYE here
	}

	// - Ventilation_ARX.TVS_CONNECT command (do not rename)
	static void Ventilation_ARXTVS_CONNECT(void)
	{
		// Add your code for command Ventilation_ARX.TVS_CONNECT here

		double Lx,Ly, startangle;
		ads_name vozd1,vozd2, eName;
		ACHAR handle[17];
		ads_point pt1,pt2;
		ads_real sise=0;
		AcDbEntity *pEnt1,*pEnt2 = NULL;
		AcDbObjectId id;
		TVS_WYE wyie;
		TVS_TAP * Tapie;
		TVS_Pipe * Pipi1,*Pipi2;
		double NewSiseA, NewRadius;
		resbuf *rb = NULL;
		bool ft=false;
		while (ft==false)
		{

			if (acedEntSel (_T("\nВыберете 1-ый воздуховод:"), vozd1,pt1)== RTCAN)
				return;



			if (acdbGetObjectId(id,vozd1)==eOk)
			{

				acdbGetObjectId(id,vozd1);

				{if (id!=AcDbObjectId::kNull)
				{
					if (acdbOpenAcDbEntity(pEnt1,id,AcDb::kForWrite)==eOk)
					{if ( (Pipi1 = TVS_Pipe::cast(pEnt1)) != NULL )
					{	
						//acutPrintf(_T("\nPipe 1...ок"));
						ft=true;

					}
					}

					else {
						acutPrintf(_T("\nОбьект заблокирован"));

						return;
					}
					pEnt1->close();	
				}
				}


			}
		}
		ft=false;
		while (ft==false)
		{
			if (acedEntSel (_T("\nВыберете 2-ый воздуховод:"), vozd2,pt2)== RTCAN)
				return;

			if (acdbGetObjectId(id,vozd2)==eOk)
			{

				acdbGetObjectId(id,vozd2);

				{if (id!=AcDbObjectId::kNull)
				{
					if (acdbOpenAcDbEntity(pEnt2,id,AcDb::kForWrite)==eOk)
					{if ( (Pipi2 = TVS_Pipe::cast(pEnt2)) != NULL )
					{	
						if (Pipi1!=Pipi2)
						{
							//acutPrintf(_T("\nPipe 2...ок"));
							ft=true;
						}
						else
						{
							acutPrintf(_T("\nВыбоан тот же воздуховод"));

						}

					}
					}

					else {
						acutPrintf(_T("\nОбьект заблокирован"));

						return;
					}

					pEnt2->close();	
				}
				}


			}


		}

		pCon(pEnt1,pEnt2);
	}


	// - Ventilation_ARX.TVS_DUCT command (do not rename)
	static void Ventilation_ARXTVS_DUCT(void)
	{


		// Add your code for command TVSTVS_Vent_ARX.MyCommand1 here

		//AcGePoint3d * gg=new AcGePoint3d;
		double Pi=3.14159265358979323846;
		AcDbEntity *pEnt;
		ads_point pt1,pt2,pt3;
		TVS_Pipe *pipi;
		TVS_Pipe pipie;
		TVS_TAP tapie;
		ads_real sa,sb;
		AcDbObjectId id = AcDbObjectId::kNull;
		ads_name eName;
		double pSizeA=250, pSizeB=0, X1, X2, Y1, Y2,pSwectangle,radius=150, tapradius;
		AcGePoint3d A1, A2, A3, pCenterpoint,lastpipi;
		AcGeVector3d pnormvect, pstartvect;
		bool pThisRound=false;

		if (acedGetReal(_T("\nВведите ширину:"),&sa) != RTNORM)
		{
			return;}
		if (acedGetReal(_T("\nВведите высоту:"),&sb) != RTNORM)
		{
			return;}
		pSizeA=sa;
		pSizeB=sb;



		if (acedGetPoint(NULL,_T("\nУкажите первую точку: "),pt1) != RTNORM)
			return;
		A1=asPnt3d(pt1);
		if (acedGetPoint(pt1,_T("\nУкажите следующую точку: "),pt2) != RTNORM)
			return;
		A2=asPnt3d(pt2);
		pipi=pipie.add_new(A1,A2,pSizeA,pSizeB,false,pThisRound);

		pnormvect=AcGeVector3d(0,0,1);
		pt1[0]=A2.x;
		pt1[1]=A2.y;
		pt1[2]=A2.z;


		///////////
		for (; ;)
		{
			if (acedGetPoint(pt1,_T("\nУкажите следующую точку: "),pt2) != RTNORM)
				return;
			A3=asPnt3d(pt2);
			if	(pThisRound==true)
			{
				if (pSizeA<355)
				{
					tapradius=pSizeA+pSizeA/2;
					radius=pSizeA;
				} 
				else
				{
					tapradius=pSizeA/2+pSizeA/2;
					radius=pSizeA/2;
				}
			}
			else
			{
				tapradius=radius+pSizeA/2;
			}
			Givecenterpoint(A1,A2,A3,tapradius,pCenterpoint,pSwectangle,pstartvect);
			if (correctpipes(A1,A2,A3,pSwectangle,pSizeA,radius,lastpipi,pThisRound)==true)
			{
				tapie.add_new(pSizeA,pSizeB,radius,pnormvect,pstartvect,pCenterpoint,pSwectangle,false,pThisRound);
				drawTapDirect(A1,A2,A3);
				id=pipi->id();
				acdbGetAdsName(eName,id);
				//acdbEntDel(ename);
				//pipi=pipie.add_new(A1,lastpipi,pSizeA,pSizeB);
				acdbGetObjectId(id,eName);
				acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite);
				pipi->assertWriteEnabled();
				pipi->LastPoint=lastpipi;
				pipi->close();
				pipi=pipie.add_new(A2,A3,pSizeA,pSizeB,false,pThisRound);
				A1=A2;
				A2=A3;

				pt1[0]=A2.x;
				pt1[1]=A2.y;
				pt1[2]=A2.z;

			}

			//pstartvect= AcGeVector3d(1,0,0);
			//pSwectangle=1.7;















		}
		// Add your code for command Ventilation_ARX.TVS_DUCT here
	}

	// - Ventilation_ARX.TVS_1D2D command (do not rename)
	static void Ventilation_ARXTVS_1D2D(void)
	{


		ads_name sset, eName;
		ACHAR  resultss [512];
		ACHAR  results1 [512]=_T("2");
		ACHAR  results2 [512]=_T("2d");

		ads_point pt1,pt2;
		ads_real sise=0;
		AcDbEntity *pEnt = NULL;
		AcDbObjectId id;
		TVS_Pipe * Pipi;
		TVS_TAP * Tapie;
		TVS_WYE* Wyeie;
		TVS_TRANS * Transie;

		double NewSiseA;
		bool p1d;
		resbuf *rb = NULL;

		if ( acedSSGet(_T(""), NULL, NULL, NULL, sset)!= RTNORM)
			return;
		acedInitGet(RSG_NOZERO, _T("1 2 1d 2d"));
		if ( acedGetKword(_T("\nПреобразовать в [1d/2d]<2d>:"),  resultss)!= RTNORM)
			return;

		if (wcscmp(resultss,results1)==0||wcscmp(resultss,results2)==0)
		{
			p1d=false;
		}
		else
		{
			p1d=true;
		}



		long len = 0;

		acedSSLength(sset, &len);
		//consoleprint(double(len),_T("\nL: "));
		for (long i = 0; i < len; i++)
		{             


			if (NULL != (acedSSName(sset,i,eName)))
			{

				//consoleprint(double(i),_T("\nd"));


				acdbGetObjectId(id,eName);
				if (id!=AcDbObjectId::kNull)
				{
					if (acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite)==eOk)
					{


						if ( (Pipi = TVS_Pipe::cast(pEnt)) != NULL )
						{	
							Pipi->assertWriteEnabled();


							Pipi->This1D=p1d;

						}

						if ( (Tapie = TVS_TAP::cast(pEnt)) != NULL )
						{	
							Tapie->assertWriteEnabled();
							Tapie->This1D=p1d;

						}

						if ( (Wyeie = TVS_WYE::cast(pEnt)) != NULL )
						{	
							Wyeie->assertWriteEnabled();
							Wyeie->This1D=p1d;

						}

						if ( (Transie = TVS_TRANS::cast(pEnt)) != NULL )
						{	
							Transie->assertWriteEnabled();
							Transie->This1D=p1d;

						}


						pEnt->close();
					}

				}
			}


		}
		// Add your code for command Ventilation_ARX.TVS_1D2D here
	}

	// - Ventilation_ARX.TVS_SPEC command (do not rename)
	static void Ventilation_ARXTVS_SPEC(void)
	{
		ads_name sset, eName;
		AcGeDoubleArray PipPar;
		AcGeDoubleArray PipArr;
		AcGeDoubleArray PipArrRound;
		AcGeDoubleArray PipArrRect;
		AcArray <SPEC> VRnd;
		AcArray <SPEC> VRct;
		AcArray <SPEC> TRct;
		AcArray <SPEC> TRnd;

		AcArray <SPEC> WPRctORct;
		AcArray <SPEC> WPRctORnd;
		AcArray <SPEC> WPRndORct;
		AcArray <SPEC> WPRndORnd;


		AcArray <SPEC> TRctRct;
		AcArray <SPEC> TRndRct;
		AcArray <SPEC> TRndRnd;
		double sA, sB, sWa,sA2,sB2, drad, prad, prad2;


		SPEC spc;
		PipPar.setLogicalLength(3);
		ads_point pt1,pt2;
		ads_real sise=0;
		AcDbEntity *pEnt = NULL;
		AcDbObjectId id;
		TVS_Pipe * Pipi;
		TVS_TAP * Tapie;
		TVS_WYE* Wyeie;
		TVS_TRANS * Transie;

		double NewSiseA;
		bool p1d;
		resbuf *rb = NULL;

		if ( acedSSGet(_T(""), NULL, NULL, NULL, sset)!= RTNORM)
			return;

		AcGePoint3d pb=AcGePoint3d(0,0,0);
		if(acedGetPoint(NULL,_T("\nУкажите точку вставки спецификации:"),pt1)!=RTNORM )
			return;
		pb=asPnt3d(pt1);
		long len = 0;

		acedSSLength(sset, &len);
		//consoleprint(double(len),_T("\nL: "));
		for (long i = 0; i < len; i++)
		{             


			if (NULL != (acedSSName(sset,i,eName)))
			{

				//consoleprint(double(i),_T("\nd"));


				acdbGetObjectId(id,eName);
				if (id!=AcDbObjectId::kNull)
				{
					acdbOpenAcDbEntity(pEnt,id,AcDb::kForRead);
					if ( (Pipi = TVS_Pipe::cast(pEnt)) != NULL )
					{	
						if (Pipi->ThisRound==true)
						{
							if (Pipi->SizeA>Pipi->SizeB)
							{
								sA=Pipi->SizeA;
								sB=Pipi->SizeB;
							} 
							else
							{
								sA=Pipi->SizeB;
								sB=Pipi->SizeA;
							}
							spc.add(sA,
								sB,
								true,
								Pipi->Length);
							VRnd.append(spc);
						}
						else
						{
							if (Pipi->SizeA>Pipi->SizeB)
							{
								sA=Pipi->SizeA;
								sB=Pipi->SizeB;
							} 
							else
							{
								sA=Pipi->SizeB;
								sB=Pipi->SizeA;
							}

							spc.add(sA,
								sB,
								false,
								Pipi->Length);
							VRct.append(spc);
						}




					}

					if ( (Tapie = TVS_TAP::cast(pEnt)) != NULL )
					{	

						if (Tapie->ThisRound==true)
						{


							sA=Tapie->SizeA;
							sB=Tapie->SizeB;
							sWa=5*floor((Tapie->Swectangle+(2*M_PI/180))/5*180/M_PI);
							//consoleprint(sWa,_T("\nSWA:"));
							//consoleprint(Tapie->Swectangle,_T("\nTapie->Swectangle:"));
							spc.add(sA,
								sB,
								true,
								1,
								sWa);

							if (Tapie->Swectangle>(M_PI/4+0.01))


								spc.Length2= M_PI*(length2p(Tapie->pMass[0],Tapie->pMass[1])*2+length2p(Tapie->pMass[5],Tapie->pMass[6]))*Tapie->SizeA/1000000;


							else

								spc.Length2= M_PI*(length2p(Tapie->pMass45[0],Tapie->pMass45[1])+length2p(Tapie->pMass45[3],Tapie->pMass45[4]))*Tapie->SizeA/1000000;

							TRnd.append(spc);
						}
						else
						{

							sA=Tapie->SizeA;
							sB=Tapie->SizeB;

							sWa=5*floor(((Tapie->Swectangle)+(2*M_PI/180))/5*180/M_PI);
							//consoleprint(sWa,_T("\nSWA:"));
							//consoleprint(Tapie->Swectangle,_T("\nTapie->Swectangle:"));
							//consoleprint((180*M_PI/100),_T("\n(180*M_PI/100):"));

							spc.add(sA,
								sB,
								false,
								1,
								sWa);

							spc.Length2= (Tapie->Swectangle)/(2*M_PI) 
								*(2*(M_PI*(Tapie->Radius+Tapie->SizeA)*(Tapie->Radius+Tapie->SizeA)/1000000
								-M_PI*(Tapie->Radius)*(Tapie->Radius)/1000000) 
								+2*M_PI*(Tapie->SizeA+Tapie->Radius)/1000*Tapie->SizeB/1000
								+2*M_PI*(Tapie->Radius)/1000*Tapie->SizeB/1000);
							//  							consoleprint(spc.Length2,_T("\nspc.Length2"));
							//  							consoleprint((Tapie->Swectangle)/(2*M_PI),_T("\n(Tapie->Swectangle)/(2*M_PI)"));
							//  							consoleprint(M_PI*(Tapie->Radius+Tapie->SizeA)*(Tapie->Radius+Tapie->SizeA)/4000000,_T("\nM_PI*(Tapie->Radius+Tapie->SizeA)*(Tapie->Radius+Tapie->SizeA)/4000000 "));
							//  							consoleprint(M_PI*(Tapie->Radius)*(Tapie->Radius)/4000000 ,_T("\nM_PI*(Tapie->Radius)*(Tapie->Radius)/4000000 "));
							//  							consoleprint(M_PI*(Tapie->SizeA+Tapie->Radius)/1000*Tapie->SizeB/1000,_T("\nM_PI*(Tapie->SizeA+Tapie->Radius)/1000*Tapie->SizeB/1000 "));
							//  							consoleprint(M_PI*(Tapie->Radius)/1000*Tapie->SizeB/1000,_T("\nM_PI*(Tapie->Radius)/1000*Tapie->SizeB/1000 "));
							// 

							TRct.append(spc);
						}

					}

					if ( (Wyeie = TVS_WYE::cast(pEnt)) != NULL )
					{	

						sA=Wyeie->SizeApr;
						sB=Wyeie->SizeBpr;
						sA2=Wyeie->SizeAotv;
						sB2=Wyeie->SizeBotv;


						if ((Wyeie->ThisRoundpr==true)&&(Wyeie->ThisRoundotv==true))
						{

							spc.add(sA,
								sB,
								false,
								1,
								Wyeie->LengthPl,
								sA2,
								sB2);
							if (sA>=sA2)
							{
								drad=sA/2-sqrt((sA/2)*(sA/2)-(sA2/2)*(sA2/2));

							}
							else
								drad=sA/2;
							spc.Length2=(sA2+Wyeie->LengthPl*2)*M_PI*sA/1000000 ///цилиндр прохода
								+(Wyeie->LengthPl+drad)*M_PI*sA2/1000000 ;  ///цилиндр отвода
							WPRndORnd.append(spc);
						}

						if ((Wyeie->ThisRoundpr==true)&&(Wyeie->ThisRoundotv==false))
						{

							spc.add(sA,
								sB,
								false,
								1,
								Wyeie->LengthPl,
								sA2,
								sB2);

							if (sA>=sB2)
							{
								drad=sA/2-sqrt((sA/2)*(sA/2)-(sB2/2)*(sB2/2));

							}
							else
								drad=sA/2;

							spc.Length2=(sA2+Wyeie->LengthPl*2)*M_PI*sA/1000000 ///цилиндр прохода
								+(Wyeie->LengthPl+drad)*(sB2+sA2)/500000;   ///призма отвода
							WPRndORct.append(spc);
						}

						if ((Wyeie->ThisRoundpr==false)&&(Wyeie->ThisRoundotv==false))
						{

							spc.add(sA,
								sB,
								false,
								1,
								Wyeie->LengthPl,
								sA2,
								sB2);

							spc.Length2=(sA2+Wyeie->LengthPl*2)*(sB+sA)/500000 ///призма прохода
								+(Wyeie->LengthPl)*(sB2+sA2)/500000;   ///призма отвода
							WPRctORct.append(spc);
						}

						if ((Wyeie->ThisRoundpr==false)&&(Wyeie->ThisRoundotv==true))
						{

							spc.add(sA,
								sB,
								false,
								1,
								Wyeie->LengthPl,
								sA2,
								sB2);

							spc.Length2=(sA2+Wyeie->LengthPl*2)*(sB+sA)/500000 ///призма прохода
								+(Wyeie->LengthPl)*M_PI*sA2/1000000;  ///цилиндр отвода
							WPRctORnd.append(spc);
						}



					}

					if ( (Transie = TVS_TRANS::cast(pEnt)) != NULL )
					{	

						sA=Transie->SizeAp1;
						sB=Transie->SizeBp1;
						sA2=Transie->SizeAp2;
						sB2=Transie->SizeBp2;

						//круглый круглый
						if ((Transie->ThisRoundp1==true)&&(Transie->ThisRoundp2==true))
						{

							if (Transie->SizeAp1>Transie->SizeAp2)
							{
								sA=Transie->SizeAp1;
								sB=Transie->SizeBp1;
								sA2=Transie->SizeAp2;
								sB2=Transie->SizeBp2;
							}

							else
							{
								sA=Transie->SizeAp2;
								sB=Transie->SizeBp2;
								sA2=Transie->SizeAp1;
								sB2=Transie->SizeBp1;
							}

							spc.add(sA,
								sB,
								false,
								1,
								Transie->LengthTr,
								sA2,
								sB2);

							drad=sqrt(Transie->LengthTr*Transie->LengthTr+(sA/2-sA2/2)*(sA/2-sA2/2))/1000;
							spc.Length2=drad*M_PI*(sA/2+sA2/2)/1000;
							TRndRnd.append(spc);
						}



						//круглый прямоугольн
						if ((Transie->ThisRoundp1==true)&&(Transie->ThisRoundp2==false))
						{

							if (Transie->SizeAp2>Transie->SizeBp2)
							{
								sA=Transie->SizeAp1;
								sB=Transie->SizeBp1;
								sA2=Transie->SizeAp2;
								sB2=Transie->SizeBp2;
							}

							else
							{
								sA=Transie->SizeAp1;
								sB=Transie->SizeBp1;
								sA2=Transie->SizeBp2;
								sB2=Transie->SizeAp2;
							}

							spc.add(sA,
								sB,
								false,
								1,
								Transie->LengthTr,
								sA2,
								sB2);
							prad=(sA2+sB2)/M_PI;
							drad=sqrt(Transie->LengthTr*Transie->LengthTr+(sA/2-prad)*(sA/2-prad))/1000;
							spc.Length2=drad*M_PI*(sA/2+prad)/1000;
							TRndRct.append(spc);
						}


						// прямоугольн круглый
						if ((Transie->ThisRoundp1==false)&&(Transie->ThisRoundp2==true))
						{

							if (Transie->SizeAp1>Transie->SizeBp1)
							{
								sA=Transie->SizeAp2;
								sB=Transie->SizeBp2;
								sA2=Transie->SizeAp1;
								sB2=Transie->SizeBp1;
							}

							else
							{
								sA=Transie->SizeAp2;
								sB=Transie->SizeBp2;
								sA2=Transie->SizeBp1;
								sB2=Transie->SizeAp1;
							}

							spc.add(sA,
								sB,
								false,
								1,
								Transie->LengthTr,
								sA2,
								sB2);
							prad=(sA2+sB2)/M_PI;
							drad=sqrt(Transie->LengthTr*Transie->LengthTr+(sA/2-prad)*(sA/2-prad))/1000;
							spc.Length2=drad*M_PI*(sA/2+prad)/1000;
							TRndRct.append(spc);
						}

						// прямоугольн прямоугольн
						if ((Transie->ThisRoundp1==false)&&(Transie->ThisRoundp2==false))
						{

							if (Transie->SizeAp1>Transie->SizeBp1)
							{


								if (Transie->SizeAp1>Transie->SizeAp2)
								{

									sA=Transie->SizeAp1;
									sB=Transie->SizeBp1;
									sA2=Transie->SizeAp2;
									sB2=Transie->SizeBp2;
								}
								else
								{
									if (Transie->SizeAp2>Transie->SizeBp2)
									{
										sA=Transie->SizeAp2;
										sB=Transie->SizeBp2;
										sA2=Transie->SizeAp1;
										sB2=Transie->SizeBp1;
									} 
									else
									{
										sA=Transie->SizeBp2;
										sB=Transie->SizeAp2;
										sA2=Transie->SizeBp1;
										sB2=Transie->SizeAp1;
									}
								}
							}

							else
							{
								if (Transie->SizeBp1>Transie->SizeBp2)
								{
									sA=Transie->SizeBp1;
									sB=Transie->SizeAp1;
									sA2=Transie->SizeBp2;
									sB2=Transie->SizeAp2;
								} 
								else
								{
									if (Transie->SizeBp2>Transie->SizeAp2)
									{
										sA=Transie->SizeBp2;
										sB=Transie->SizeAp2;
										sA2=Transie->SizeBp1;
										sB2=Transie->SizeAp1;
									} 
									else
									{
										sA=Transie->SizeAp2;
										sB=Transie->SizeBp2;
										sA2=Transie->SizeAp1;
										sB2=Transie->SizeBp1;
									}
								}		




							}

							spc.add(sA,
								sB,
								false,
								1,
								Transie->LengthTr,
								sA2,
								sB2);
							prad=(sA2+sB2)/M_PI;
							prad2=(sA+sB)/M_PI;
							drad=sqrt(Transie->LengthTr*Transie->LengthTr+(prad2-prad)*(prad2-prad))/1000;
							spc.Length2=drad*M_PI*(prad2+prad)/1000;
							TRctRct.append(spc);
						}

					}


					pEnt->close();

				}
			}


		}




		double buf1,buf2,buf3,buf4;
		long j;

		//Подсчет прямоугольных воздуховодов (переменная VRct)
		long lenP=VRct.logicalLength();
		if (lenP>0)
		{

			for (long i=0;i<lenP;i++)

				for (long j = i+1; j < lenP; j++)

					if ((VRct[i].SizeA>VRct[j].SizeA)||((VRct[i].SizeA==VRct[j].SizeA)&&(VRct[i].SizeB>VRct[j].SizeB)))
					{
						buf1 = VRct[i].SizeA;
						buf2 = VRct[i].SizeB;
						buf3 = VRct[i].Length;

						VRct[i].SizeA=VRct[j].SizeA;
						VRct[i].SizeB=VRct[j].SizeB;
						VRct[i].Length=VRct[j].Length;

						VRct[j].SizeA=buf1;
						VRct[j].SizeB=buf2;
						VRct[j].Length=buf3;
					}

					AcArray<SPEC> VRct2;
					VRct2.append(VRct[0]);
					j=0;
					for (long i=1;i<lenP;i++)

					{
						if ((VRct2[j].SizeA==VRct[i].SizeA)&&(VRct2[j].SizeB==VRct[i].SizeB))

							VRct2[j].Length=VRct2[j].Length+VRct[i].Length;


						else 
						{
							VRct2.append(VRct[i]);
							j++;

						}

					}
					VRct=VRct2;
					lenP=VRct.logicalLength();

		}








		//Подсчет круглых воздуховодов воздуховодов (переменная VRnd)

		lenP=VRnd.logicalLength();
		if (lenP>0)
		{

			for (long i=0;i<lenP;i++)

				for (long j = i+1; j < lenP; j++)

					if (VRnd[i].SizeA>VRnd[j].SizeA)
					{
						buf1 = VRnd[i].SizeA;
						buf2 = VRnd[i].SizeB;
						buf3 = VRnd[i].Length;

						VRnd[i].SizeA=VRnd[j].SizeA;
						VRnd[i].SizeB=VRnd[j].SizeB;
						VRnd[i].Length=VRnd[j].Length;

						VRnd[j].SizeA=buf1;
						VRnd[j].SizeB=buf2;
						VRnd[j].Length=buf3;
					}

					AcArray<SPEC> VRnd2;
					VRnd2.append(VRnd[0]);
					j=0;
					for (long i=1;i<lenP;i++)

					{
						if ((VRnd2[j].SizeA==VRnd[i].SizeA)&&(VRnd2[j].SizeB==VRnd[i].SizeB))

							VRnd2[j].Length=VRnd2[j].Length+VRnd[i].Length;

						else 
						{
							VRnd2.append(VRnd[i]);
							j++;
						}

					}
					VRnd=VRnd2;
					lenP=VRnd.logicalLength();




		}


		//Подсчет прямоугольных отводов (переменная TRct)
		lenP=TRct.logicalLength();
		if (lenP>0)
		{

			for (long i=0;i<lenP;i++)

				for (long j = i+1; j < lenP; j++)

					if ((TRct[i].Swectangle>TRct[j].Swectangle)||
						((TRct[i].Swectangle==TRct[j].Swectangle)&&
						((TRct[i].SizeA>TRct[j].SizeA)||((TRct[i].SizeA==TRct[j].SizeA)&&(TRct[i].SizeB>TRct[j].SizeB)))))
					{
						buf1 = TRct[i].SizeA;
						buf2 = TRct[i].SizeB;
						buf3 = TRct[i].Swectangle;
						buf4 = TRct[i].Length2;

						TRct[i].SizeA=TRct[j].SizeA;
						TRct[i].SizeB=TRct[j].SizeB;
						TRct[i].Swectangle=TRct[j].Swectangle;
						TRct[i].Length2=TRct[j].Length2;

						TRct[j].SizeA=buf1;
						TRct[j].SizeB=buf2;
						TRct[j].Swectangle=buf3;
						TRct[j].Length2=buf4;

					}

					AcArray<SPEC> TRct2;
					TRct2.append(TRct[0]);
					j=0;
					for (long i=1;i<lenP;i++)

					{
						if ((TRct2[j].SizeA==TRct[i].SizeA)&&(TRct2[j].SizeB==TRct[i].SizeB)&&(TRct2[j].Swectangle==TRct[i].Swectangle))

							TRct2[j].Length=TRct2[j].Length+TRct[i].Length;

						else 
						{
							TRct2.append(TRct[i]);
							j++;
						}

					}
					TRct=TRct2;
					lenP=TRct.logicalLength();



		}



		//Подсчет круглых отводов (переменная TRnd)
		lenP=TRnd.logicalLength();
		if (lenP>0)
		{

			for (long i=0;i<lenP;i++)

				for (long j = i+1; j < lenP; j++)

					if ((TRnd[i].Swectangle>TRnd[j].Swectangle)||
						((TRnd[i].Swectangle==TRnd[j].Swectangle)&&
						((TRnd[i].SizeA>TRnd[j].SizeA)||((TRnd[i].SizeA==TRnd[j].SizeA)&&(TRnd[i].SizeB>TRnd[j].SizeB)))))
					{
						buf1 = TRnd[i].SizeA;
						buf2 = TRnd[i].SizeB;
						buf3 = TRnd[i].Swectangle;
						buf4 = TRnd[i].Length2;



						TRnd[i].SizeA=TRnd[j].SizeA;
						TRnd[i].SizeB=TRnd[j].SizeB;
						TRnd[i].Swectangle=TRnd[j].Swectangle;
						TRnd[i].Length2=TRnd[j].Length2;

						TRnd[j].SizeA=buf1;
						TRnd[j].SizeB=buf2;
						TRnd[j].Swectangle=buf3;
						TRnd[j].Length2=buf4;
					}

					AcArray<SPEC> TRnd2;
					TRnd2.append(TRnd[0]);
					j=0;
					for (long i=1;i<lenP;i++)

					{
						if ((TRnd2[j].SizeA==TRnd[i].SizeA)&&(TRnd2[j].SizeB==TRnd[i].SizeB)&&(TRnd2[j].Swectangle==TRnd[i].Swectangle))

							TRnd2[j].Length=TRnd2[j].Length+TRnd[i].Length;

						else 
						{
							TRnd2.append(TRnd[i]);
							j++;
						}

					}
					TRnd=TRnd2;
					lenP=TRnd.logicalLength();



		}




		SPEC buff;

		//Подсчет тройников прям прям (переменная WPRctORct)
		lenP=WPRctORct.logicalLength();
		if (lenP>0)
		{

			for (long i=0;i<lenP;i++)

				for (long j = i+1; j < lenP; j++)

					if ((WPRctORct[i].Swectangle>WPRctORct[j].Swectangle)||
						((WPRctORct[i].Swectangle==WPRctORct[j].Swectangle)&&
						((WPRctORct[i].SizeA>WPRctORct[j].SizeA)||
						((WPRctORct[i].SizeA==WPRctORct[j].SizeA)&&
						((WPRctORct[i].SizeB>WPRctORct[j].SizeB)||
						((WPRctORct[i].SizeB==WPRctORct[j].SizeB)&&
						((WPRctORct[i].SizeA2>WPRctORct[j].SizeA2)||
						((WPRctORct[i].SizeA2==WPRctORct[j].SizeA2)&&
						((WPRctORct[i].SizeA3>WPRctORct[j].SizeA3)
						)
						)
						)
						)
						)
						)
						)
						)	
						)
					{


						buff=WPRctORct[i];
						WPRctORct[i]=WPRctORct[j];
						WPRctORct[j]=buff;



					}

					AcArray<SPEC> WPRctORct2;
					WPRctORct2.append(WPRctORct[0]);
					j=0;
					for (long i=1;i<lenP;i++)

					{
						if ((WPRctORct2[j].Swectangle==WPRctORct[i].Swectangle)&&
							(WPRctORct2[j].SizeA==WPRctORct[i].SizeA)&&
							(WPRctORct2[j].SizeB==WPRctORct[i].SizeB)&&
							(WPRctORct2[j].SizeA2==WPRctORct[i].SizeA2)&&
							(WPRctORct2[j].SizeA3==WPRctORct[i].SizeA3)

							)

							WPRctORct2[j].Length=WPRctORct2[j].Length+WPRctORct[i].Length;

						else 
						{
							WPRctORct2.append(WPRctORct[i]);
							j++;
						}

					}
					WPRctORct=WPRctORct2;
					lenP=WPRctORct.logicalLength();



		}





		//Подсчет тройников прям кругл (переменная WPRctORnd)
		lenP=WPRctORnd.logicalLength();
		if (lenP>0)
		{

			for (long i=0;i<lenP;i++)

				for (long j = i+1; j < lenP; j++)

					if ((WPRctORnd[i].Swectangle>WPRctORnd[j].Swectangle)||
						((WPRctORnd[i].Swectangle==WPRctORnd[j].Swectangle)&&
						((WPRctORnd[i].SizeA>WPRctORnd[j].SizeA)||
						((WPRctORnd[i].SizeA==WPRctORnd[j].SizeA)&&
						((WPRctORnd[i].SizeB>WPRctORnd[j].SizeB)||
						((WPRctORnd[i].SizeB==WPRctORnd[j].SizeB)&&
						((WPRctORnd[i].SizeA2>WPRctORnd[j].SizeA2)||
						((WPRctORnd[i].SizeA2==WPRctORnd[j].SizeA2)&&
						((WPRctORnd[i].SizeA3>WPRctORnd[j].SizeA3)
						)
						)
						)
						)
						)
						)
						)
						)	
						)
					{


						buff=WPRctORnd[i];
						WPRctORnd[i]=WPRctORnd[j];
						WPRctORnd[j]=buff;



					}

					AcArray<SPEC> WPRctORnd2;
					WPRctORnd2.append(WPRctORnd[0]);
					j=0;
					for (long i=1;i<lenP;i++)

					{
						if ((WPRctORnd2[j].Swectangle==WPRctORnd[i].Swectangle)&&
							(WPRctORnd2[j].SizeA==WPRctORnd[i].SizeA)&&
							(WPRctORnd2[j].SizeB==WPRctORnd[i].SizeB)&&
							(WPRctORnd2[j].SizeA2==WPRctORnd[i].SizeA2)&&
							(WPRctORnd2[j].SizeA3==WPRctORnd[i].SizeA3)

							)

							WPRctORnd2[j].Length=WPRctORnd2[j].Length+WPRctORnd[i].Length;

						else 
						{
							WPRctORnd2.append(WPRctORnd[i]);
							j++;
						}

					}
					WPRctORnd=WPRctORnd2;
					lenP=WPRctORnd.logicalLength();



		}


		//Подсчет тройников кругл кругл (переменная WPRndORnd)
		lenP=WPRndORnd.logicalLength();
		if (lenP>0)
		{

			for (long i=0;i<lenP;i++)

				for (long j = i+1; j < lenP; j++)

					if ((WPRndORnd[i].Swectangle>WPRndORnd[j].Swectangle)||
						((WPRndORnd[i].Swectangle==WPRndORnd[j].Swectangle)&&
						((WPRndORnd[i].SizeA>WPRndORnd[j].SizeA)||
						((WPRndORnd[i].SizeA==WPRndORnd[j].SizeA)&&
						((WPRndORnd[i].SizeB>WPRndORnd[j].SizeB)||
						((WPRndORnd[i].SizeB==WPRndORnd[j].SizeB)&&
						((WPRndORnd[i].SizeA2>WPRndORnd[j].SizeA2)||
						((WPRndORnd[i].SizeA2==WPRndORnd[j].SizeA2)&&
						((WPRndORnd[i].SizeA3>WPRndORnd[j].SizeA3)
						)
						)
						)
						)
						)
						)
						)
						)	
						)
					{


						buff=WPRndORnd[i];
						WPRndORnd[i]=WPRndORnd[j];
						WPRndORnd[j]=buff;



					}

					AcArray<SPEC> WPRndORnd2;
					WPRndORnd2.append(WPRndORnd[0]);
					j=0;
					for (long i=1;i<lenP;i++)

					{
						if ((WPRndORnd2[j].Swectangle==WPRndORnd[i].Swectangle)&&
							(WPRndORnd2[j].SizeA==WPRndORnd[i].SizeA)&&
							(WPRndORnd2[j].SizeB==WPRndORnd[i].SizeB)&&
							(WPRndORnd2[j].SizeA2==WPRndORnd[i].SizeA2)&&
							(WPRndORnd2[j].SizeA3==WPRndORnd[i].SizeA3)

							)

							WPRndORnd2[j].Length=WPRndORnd2[j].Length+WPRndORnd[i].Length;

						else 
						{
							WPRndORnd2.append(WPRndORnd[i]);
							j++;
						}

					}
					WPRndORnd=WPRndORnd2;
					lenP=WPRndORnd.logicalLength();



		}


		//Подсчет тройников кругл прям  (переменная WPRndORct)
		lenP=WPRndORct.logicalLength();
		if (lenP>0)
		{

			for (long i=0;i<lenP;i++)

				for (long j = i+1; j < lenP; j++)

					if ((WPRndORct[i].Swectangle>WPRndORct[j].Swectangle)||
						((WPRndORct[i].Swectangle==WPRndORct[j].Swectangle)&&
						((WPRndORct[i].SizeA>WPRndORct[j].SizeA)||
						((WPRndORct[i].SizeA==WPRndORct[j].SizeA)&&
						((WPRndORct[i].SizeB>WPRndORct[j].SizeB)||
						((WPRndORct[i].SizeB==WPRndORct[j].SizeB)&&
						((WPRndORct[i].SizeA2>WPRndORct[j].SizeA2)||
						((WPRndORct[i].SizeA2==WPRndORct[j].SizeA2)&&
						((WPRndORct[i].SizeA3>WPRndORct[j].SizeA3)
						)
						)
						)
						)
						)
						)
						)
						)	
						)
					{


						buff=WPRndORct[i];
						WPRndORct[i]=WPRndORct[j];
						WPRndORct[j]=buff;



					}

					AcArray<SPEC> WPRndORct2;
					WPRndORct2.append(WPRndORct[0]);
					j=0;
					for (long i=1;i<lenP;i++)

					{
						if ((WPRndORct2[j].Swectangle==WPRndORct[i].Swectangle)&&
							(WPRndORct2[j].SizeA==WPRndORct[i].SizeA)&&
							(WPRndORct2[j].SizeB==WPRndORct[i].SizeB)&&
							(WPRndORct2[j].SizeA2==WPRndORct[i].SizeA2)&&
							(WPRndORct2[j].SizeA3==WPRndORct[i].SizeA3)

							)

							WPRndORct2[j].Length=WPRndORct2[j].Length+WPRndORct[i].Length;

						else 
						{
							WPRndORct2.append(WPRndORct[i]);
							j++;
						}

					}
					WPRndORct=WPRndORct2;
					lenP=WPRndORct.logicalLength();



		}




		//Подсчет переход кругл кругл (переменная TRndRnd)
		lenP=TRndRnd.logicalLength();
		if (lenP>0)
		{

			for (long i=0;i<lenP;i++)

				for (long j = i+1; j < lenP; j++)

					if ((TRndRnd[i].Swectangle>TRndRnd[j].Swectangle)||
						((TRndRnd[i].Swectangle==TRndRnd[j].Swectangle)&&
						((TRndRnd[i].SizeA>TRndRnd[j].SizeA)||
						((TRndRnd[i].SizeA==TRndRnd[j].SizeA)&&
						((TRndRnd[i].SizeB>TRndRnd[j].SizeB)||
						((TRndRnd[i].SizeB==TRndRnd[j].SizeB)&&
						((TRndRnd[i].SizeA2>TRndRnd[j].SizeA2)||
						((TRndRnd[i].SizeA2==TRndRnd[j].SizeA2)&&
						((TRndRnd[i].SizeA3>TRndRnd[j].SizeA3)
						)
						)
						)
						)
						)
						)
						)
						)	
						)
					{


						buff=TRndRnd[i];
						TRndRnd[i]=TRndRnd[j];
						TRndRnd[j]=buff;



					}

					AcArray<SPEC> TRndRnd2;
					TRndRnd2.append(TRndRnd[0]);
					j=0;
					for (long i=1;i<lenP;i++)

					{
						if ((TRndRnd2[j].Swectangle==TRndRnd[i].Swectangle)&&
							(TRndRnd2[j].SizeA==TRndRnd[i].SizeA)&&
							(TRndRnd2[j].SizeB==TRndRnd[i].SizeB)&&
							(TRndRnd2[j].SizeA2==TRndRnd[i].SizeA2)&&
							(TRndRnd2[j].SizeA3==TRndRnd[i].SizeA3)

							)

							TRndRnd2[j].Length=TRndRnd2[j].Length+TRndRnd[i].Length;

						else 
						{
							TRndRnd2.append(TRndRnd[i]);
							j++;
						}

					}
					TRndRnd=TRndRnd2;
					lenP=TRndRnd.logicalLength();



		}



		//Подсчет переход кругл прям(переменная TRndRct)
		lenP=TRndRct.logicalLength();
		if (lenP>0)
		{

			for (long i=0;i<lenP;i++)

				for (long j = i+1; j < lenP; j++)

					if ((TRndRct[i].Swectangle>TRndRct[j].Swectangle)||
						((TRndRct[i].Swectangle==TRndRct[j].Swectangle)&&
						((TRndRct[i].SizeA>TRndRct[j].SizeA)||
						((TRndRct[i].SizeA==TRndRct[j].SizeA)&&
						((TRndRct[i].SizeB>TRndRct[j].SizeB)||
						((TRndRct[i].SizeB==TRndRct[j].SizeB)&&
						((TRndRct[i].SizeA2>TRndRct[j].SizeA2)||
						((TRndRct[i].SizeA2==TRndRct[j].SizeA2)&&
						((TRndRct[i].SizeA3>TRndRct[j].SizeA3)
						)
						)
						)
						)
						)
						)
						)
						)	
						)
					{


						buff=TRndRct[i];
						TRndRct[i]=TRndRct[j];
						TRndRct[j]=buff;



					}

					AcArray<SPEC> TRndRct2;
					TRndRct2.append(TRndRct[0]);
					j=0;
					for (long i=1;i<lenP;i++)

					{
						if ((TRndRct2[j].Swectangle==TRndRct[i].Swectangle)&&
							(TRndRct2[j].SizeA==TRndRct[i].SizeA)&&
							(TRndRct2[j].SizeB==TRndRct[i].SizeB)&&
							(TRndRct2[j].SizeA2==TRndRct[i].SizeA2)&&
							(TRndRct2[j].SizeA3==TRndRct[i].SizeA3)

							)

							TRndRct2[j].Length=TRndRct2[j].Length+TRndRct[i].Length;

						else 
						{
							TRndRct2.append(TRndRct[i]);
							j++;
						}

					}
					TRndRct=TRndRct2;
					lenP=TRndRct.logicalLength();



		}



		//Подсчет переход прям прям(переменная TRctRct)
		lenP=TRctRct.logicalLength();
		if (lenP>0)
		{

			for (long i=0;i<lenP;i++)

				for (long j = i+1; j < lenP; j++)

					if ((TRctRct[i].Swectangle>TRctRct[j].Swectangle)||
						((TRctRct[i].Swectangle==TRctRct[j].Swectangle)&&
						((TRctRct[i].SizeA>TRctRct[j].SizeA)||
						((TRctRct[i].SizeA==TRctRct[j].SizeA)&&
						((TRctRct[i].SizeB>TRctRct[j].SizeB)||
						((TRctRct[i].SizeB==TRctRct[j].SizeB)&&
						((TRctRct[i].SizeA2>TRctRct[j].SizeA2)||
						((TRctRct[i].SizeA2==TRctRct[j].SizeA2)&&
						((TRctRct[i].SizeA3>TRctRct[j].SizeA3)
						)
						)
						)
						)
						)
						)
						)
						)	
						)
					{


						buff=TRctRct[i];
						TRctRct[i]=TRctRct[j];
						TRctRct[j]=buff;



					}

					AcArray<SPEC> TRctRct2;
					TRctRct2.append(TRctRct[0]);
					j=0;
					for (long i=1;i<lenP;i++)

					{
						if ((TRctRct2[j].Swectangle==TRctRct[i].Swectangle)&&
							(TRctRct2[j].SizeA==TRctRct[i].SizeA)&&
							(TRctRct2[j].SizeB==TRctRct[i].SizeB)&&
							(TRctRct2[j].SizeA2==TRctRct[i].SizeA2)&&
							(TRctRct2[j].SizeA3==TRctRct[i].SizeA3)

							)

							TRctRct2[j].Length=TRctRct2[j].Length+TRctRct[i].Length;

						else 
						{
							TRctRct2.append(TRctRct[i]);
							j++;
						}

					}
					TRctRct=TRctRct2;
					lenP=TRctRct.logicalLength();



		}



		//отрисовка спец
		ACHAR buffer[512], buffer1[512], buffer2[512] ;

		double pArea=0;
		double pSumArea=0;




		if ((VRct.logicalLength()>0)||
			(VRnd.logicalLength()>0)	
			)
		{
			pb=AddSpecLine(pb,_T("Воздуховоды:"));
		}



		if (VRnd.logicalLength()!=0)
		{
			//отрисовка круглых

			for (long i=0;i<VRnd.logicalLength();i++)
			{
				//подщет площади
				VRnd[i].Area=ceil(VRnd[i].Length/1000)*M_PI*VRnd[i].SizeA/1000;
				pArea=VRnd[i].Area+pArea;
				//


				wcscpy_s(buffer1,_T("%%C"));
				acdbRToS(VRnd[i].SizeA,2,2,buffer);
				wcscat_s(buffer1,buffer);
				acdbRToS(ceil(VRnd[i].Length/100)/10,2,1,buffer2);
				acdbRToS(VRnd[i].Area,2,2,buffer);
				pb=AddSpecLine(pb,buffer1,_T("м"),buffer2,_T("м2"),buffer);

			}
			//acdbRToS(pArea,2,2,buffer);
			//pb=AddSpecLine(pb,_T("Всего:"),_T(""),_T(""),_T("м2"),buffer);
			//pSumArea=pSumArea+pArea;
			//pArea=0;
		}



		//отрисовка прямоугольных
		if (VRct.logicalLength()!=0)
		{
			/*pb=AddSpecLine(pb,_T("Прямоугольные воздуховоды:"));*/
			for (long i=0;i<VRct.logicalLength();i++)
			{
				//подщет площади
				VRct[i].Area=ceil(VRct[i].Length/1000)*2*(VRct[i].SizeA+VRct[i].SizeB)/1000;
				pArea=VRct[i].Area+pArea;
				//	
				acdbRToS(VRct[i].SizeA,2,2,buffer1);
				acdbRToS(VRct[i].SizeB,2,2,buffer);
				wcscat_s(buffer1,_T("x"));
				wcscat_s(buffer1,buffer);
				acdbRToS(ceil(VRct[i].Length/100)/10,2,1,buffer2);
				acdbRToS(VRct[i].Area,2,2,buffer);
				pb=AddSpecLine(pb,buffer1,_T("м"),buffer2,_T("м2"),buffer);

			}

		}



		if ((VRct.logicalLength()>0)||
			(VRnd.logicalLength()>0)	
			)
		{
			acdbRToS(pArea,2,2,buffer);
			pb=AddSpecLine(pb,_T("Всего:"),_T(""),_T(""),_T("м2"),buffer);
			pSumArea=pSumArea+pArea;
			pArea=0;
		}


		/////отводы

		if ((TRct.logicalLength()>0)||
			(TRnd.logicalLength()>0)	
			)
		{
			pb=AddSpecLine(pb,_T("Отводы:"));
		}



		double pl1,pl2;
		//отрисовка круглых отводов
		if (TRnd.logicalLength()!=0)
		{

			for (long i=0;i<TRnd.logicalLength();i++)
			{
				//подщет площади


				TRnd[i].Area=ceil(TRnd[i].Length)*TRnd[i].Length2;
				pArea=TRnd[i].Area+pArea;

				//


				wcscpy_s(buffer1,_T("%%C"));
				acdbRToS(TRnd[i].SizeA,2,2,buffer);
				wcscat_s(buffer1,buffer);

				acdbRToS(TRnd[i].Swectangle,2,2,buffer);
				wcscat_s(buffer1,_T(" ("));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T("%%d)"));

				acdbRToS(ceil(TRnd[i].Length),2,2,buffer2);
				acdbRToS(TRnd[i].Area,2,2,buffer);
				pb=AddSpecLine(pb,buffer1,_T("шт"),buffer2,_T("м2"),buffer);

			}

		}




		//отрисовка прямоугольных отводов
		if (TRct.logicalLength()!=0)
		{
			//pb=AddSpecLine(pb,_T("Прямоугольные отводы:"));
			for (long i=0;i<TRct.logicalLength();i++)
			{

				//подщет площади


				TRct[i].Area=ceil(TRct[i].Length)*TRct[i].Length2;
				pArea=TRct[i].Area+pArea;

				//

				acdbRToS(TRct[i].SizeA,2,2,buffer1);
				acdbRToS(TRct[i].SizeB,2,2,buffer);
				wcscat_s(buffer1,_T("x"));
				wcscat_s(buffer1,buffer);
				acdbRToS(TRct[i].Swectangle,2,2,buffer);
				wcscat_s(buffer1,_T(" ("));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T("%%d)"));

				acdbRToS(ceil(TRct[i].Length),2,2,buffer2);
				acdbRToS(TRct[i].Area,2,2,buffer);
				pb=AddSpecLine(pb,buffer1,_T("шт"),buffer2,_T("м2"),buffer);

			}

		}


		if ((TRct.logicalLength()>0)||
			(TRnd.logicalLength()>0)	
			)
		{
			acdbRToS(pArea,2,2,buffer);
			pb=AddSpecLine(pb,_T("Всего:"),_T(""),_T(""),_T("м2"),buffer);
			pSumArea=pSumArea+pArea;
			pArea=0;
		}




		/////тройники


		if ((WPRctORct.logicalLength()>0)||
			(WPRctORnd.logicalLength()>0)||
			(WPRndORct.logicalLength()>0)||
			(WPRndORnd.logicalLength()>0)
			)
		{
			pb=AddSpecLine(pb,_T("Тройники:"));
		}





		//отрисовка тройника  кругл кругл
		if (WPRndORnd.logicalLength()!=0)
		{

			for (long i=0;i<WPRndORnd.logicalLength();i++)
			{

				//подщет площади


				WPRndORnd[i].Area=ceil(WPRndORnd[i].Length)*WPRndORnd[i].Length2;
				pArea=WPRndORnd[i].Area+pArea;

				//
				wcscpy_s(buffer1,_T("%%c"));
				acdbRToS(WPRndORnd[i].SizeA,2,2,buffer2);
				wcscat_s(buffer1,buffer2);


				wcscat_s(buffer1,_T("x%%c"));
				acdbRToS(WPRndORnd[i].SizeA2,2,2,buffer2);
				wcscat_s(buffer1,buffer2);




				acdbRToS(WPRndORnd[i].Swectangle,2,2,buffer);
				wcscat_s(buffer1,_T(" (L="));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T("мм)"));

				acdbRToS(ceil(WPRndORnd[i].Length),2,2,buffer2);
				acdbRToS(WPRndORnd[i].Area,2,2,buffer);
				pb=AddSpecLine(pb,buffer1,_T("шт"),buffer2,_T("м2"),buffer);

			}
			/*	acdbRToS(pArea,2,2,buffer);
			pb=AddSpecLine(pb,_T("Всего:"),_T(""),_T(""),_T("м2"),buffer);
			pSumArea=pSumArea+pArea;
			pArea=0;*/



		}



		//отрисовка тройника  кругл прям
		if (WPRndORct.logicalLength()!=0)
		{
			//pb=AddSpecLine(pb,_T("Тройник кругл-прям:"));
			for (long i=0;i<WPRndORct.logicalLength();i++)
			{

				//подщет площади


				WPRndORct[i].Area=ceil(WPRndORct[i].Length)*WPRndORct[i].Length2;
				pArea=WPRndORct[i].Area+pArea;

				//
				wcscpy_s(buffer1,_T("%%c"));
				acdbRToS(WPRndORct[i].SizeA,2,2,buffer2);
				wcscat_s(buffer1,buffer2);


				wcscat_s(buffer1,_T("x("));
				acdbRToS(WPRndORct[i].SizeA2,2,2,buffer2);
				wcscat_s(buffer1,buffer2);
				acdbRToS(WPRndORct[i].SizeA3,2,2,buffer);
				wcscat_s(buffer1,_T("x"));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T(")"));




				acdbRToS(WPRndORct[i].Swectangle,2,2,buffer);
				wcscat_s(buffer1,_T(" (L="));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T("мм)"));

				acdbRToS(ceil(WPRndORct[i].Length),2,2,buffer2);
				acdbRToS(WPRndORct[i].Area,2,2,buffer);
				pb=AddSpecLine(pb,buffer1,_T("шт"),buffer2,_T("м2"),buffer);

			}
			/*	acdbRToS(pArea,2,2,buffer);
			pb=AddSpecLine(pb,_T("Всего:"),_T(""),_T(""),_T("м2"),buffer);
			pSumArea=pSumArea+pArea;
			pArea=0;*/



		}







		//отрисовка тройника  прям кругл
		if (WPRctORnd.logicalLength()!=0)
		{
			//pb=AddSpecLine(pb,_T("Тройник прям-кругл:"));
			for (long i=0;i<WPRctORnd.logicalLength();i++)
			{

				//подщет площади


				WPRctORnd[i].Area=ceil(WPRctORnd[i].Length)*WPRctORnd[i].Length2;
				pArea=WPRctORnd[i].Area+pArea;

				//
				wcscpy_s(buffer1,_T("("));
				acdbRToS(WPRctORnd[i].SizeA,2,2,buffer2);
				wcscat_s(buffer1,buffer2);
				acdbRToS(WPRctORnd[i].SizeB,2,2,buffer);
				wcscat_s(buffer1,_T("x"));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T(")"));


				wcscat_s(buffer1,_T("x%%c"));
				acdbRToS(WPRctORnd[i].SizeA2,2,2,buffer2);
				wcscat_s(buffer1,buffer2);




				acdbRToS(WPRctORnd[i].Swectangle,2,2,buffer);
				wcscat_s(buffer1,_T(" (L="));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T("мм)"));

				acdbRToS(ceil(WPRctORnd[i].Length),2,2,buffer2);
				acdbRToS(WPRctORnd[i].Area,2,2,buffer);
				pb=AddSpecLine(pb,buffer1,_T("шт"),buffer2,_T("м2"),buffer);

			}
			// 			acdbRToS(pArea,2,2,buffer);
			// 			pb=AddSpecLine(pb,_T("Всего:"),_T(""),_T(""),_T("м2"),buffer);
			// 			pSumArea=pSumArea+pArea;
			// 			pArea=0;



		}

		//отрисовка тройника прям прям 
		if (WPRctORct.logicalLength()!=0)
		{
			//pb=AddSpecLine(pb,_T("Тройник Прям-Прям:"));
			for (long i=0;i<WPRctORct.logicalLength();i++)
			{

				//подщет площади


				WPRctORct[i].Area=ceil(WPRctORct[i].Length)*WPRctORct[i].Length2;
				pArea=WPRctORct[i].Area+pArea;

				//
				wcscpy_s(buffer1,_T("("));
				acdbRToS(WPRctORct[i].SizeA,2,2,buffer2);
				wcscat_s(buffer1,buffer2);
				acdbRToS(WPRctORct[i].SizeB,2,2,buffer);
				wcscat_s(buffer1,_T("x"));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T(")"));

				wcscat_s(buffer1,_T("x("));
				acdbRToS(WPRctORct[i].SizeA2,2,2,buffer2);
				wcscat_s(buffer1,buffer2);
				acdbRToS(WPRctORct[i].SizeA3,2,2,buffer);
				wcscat_s(buffer1,_T("x"));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T(")"));



				acdbRToS(WPRctORct[i].Swectangle,2,2,buffer);
				wcscat_s(buffer1,_T(" (L="));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T("мм)"));

				acdbRToS(ceil(WPRctORct[i].Length),2,2,buffer2);
				acdbRToS(WPRctORct[i].Area,2,2,buffer);
				pb=AddSpecLine(pb,buffer1,_T("шт"),buffer2,_T("м2"),buffer);

			}




		}

		if ((WPRctORct.logicalLength()>0)||
			(WPRctORnd.logicalLength()>0)||
			(WPRndORct.logicalLength()>0)||
			(WPRndORnd.logicalLength()>0)
			)
		{
			acdbRToS(pArea,2,2,buffer);
			pb=AddSpecLine(pb,_T("Всего:"),_T(""),_T(""),_T("м2"),buffer);
			pSumArea=pSumArea+pArea;
			pArea=0;
		}








		//переходы

		if ((TRndRnd.logicalLength()>0)||
			(TRndRct.logicalLength()>0)||
			(TRctRct.logicalLength()>0)
			)
		{
			pb=AddSpecLine(pb,_T("Переходы:"));
		}

		//отрисовка перехода  кругл кругл
		if (TRndRnd.logicalLength()!=0)
		{

			for (long i=0;i<TRndRnd.logicalLength();i++)
			{

				//подщет площади


				TRndRnd[i].Area=ceil(TRndRnd[i].Length)*TRndRnd[i].Length2;
				pArea=TRndRnd[i].Area+pArea;

				//
				wcscpy_s(buffer1,_T("%%c"));
				acdbRToS(TRndRnd[i].SizeA,2,2,buffer2);
				wcscat_s(buffer1,buffer2);


				wcscat_s(buffer1,_T("x%%c"));
				acdbRToS(TRndRnd[i].SizeA2,2,2,buffer2);
				wcscat_s(buffer1,buffer2);




				acdbRToS(TRndRnd[i].Swectangle,2,2,buffer);
				wcscat_s(buffer1,_T(" (L="));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T("мм)"));

				acdbRToS(ceil(TRndRnd[i].Length),2,2,buffer2);
				acdbRToS(TRndRnd[i].Area,2,2,buffer);
				pb=AddSpecLine(pb,buffer1,_T("шт"),buffer2,_T("м2"),buffer);

			}
			/*	acdbRToS(pArea,2,2,buffer);
			pb=AddSpecLine(pb,_T("Всего:"),_T(""),_T(""),_T("м2"),buffer);
			pSumArea=pSumArea+pArea;
			pArea=0;*/

		}
		//отрисовка перехода  кругл прям
		if (TRndRct.logicalLength()!=0)
		{
			//pb=AddSpecLine(pb,_T("Тройник кругл-прям:"));
			for (long i=0;i<TRndRct.logicalLength();i++)
			{

				//подщет площади


				TRndRct[i].Area=ceil(TRndRct[i].Length)*TRndRct[i].Length2;
				pArea=TRndRct[i].Area+pArea;

				//
				wcscpy_s(buffer1,_T("%%c"));
				acdbRToS(TRndRct[i].SizeA,2,2,buffer2);
				wcscat_s(buffer1,buffer2);


				wcscat_s(buffer1,_T("x("));
				acdbRToS(TRndRct[i].SizeA2,2,2,buffer2);
				wcscat_s(buffer1,buffer2);
				acdbRToS(TRndRct[i].SizeA3,2,2,buffer);
				wcscat_s(buffer1,_T("x"));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T(")"));




				acdbRToS(TRndRct[i].Swectangle,2,2,buffer);
				wcscat_s(buffer1,_T(" (L="));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T("мм)"));

				acdbRToS(ceil(TRndRct[i].Length),2,2,buffer2);
				acdbRToS(TRndRct[i].Area,2,2,buffer);
				pb=AddSpecLine(pb,buffer1,_T("шт"),buffer2,_T("м2"),buffer);

			}
			/*	acdbRToS(pArea,2,2,buffer);
			pb=AddSpecLine(pb,_T("Всего:"),_T(""),_T(""),_T("м2"),buffer);
			pSumArea=pSumArea+pArea;
			pArea=0;*/



		}



		//отрисовка перехода прям прям 
		if (TRctRct.logicalLength()!=0)
		{
			//pb=AddSpecLine(pb,_T("Тройник Прям-Прям:"));
			for (long i=0;i<TRctRct.logicalLength();i++)
			{

				//подщет площади


				TRctRct[i].Area=ceil(TRctRct[i].Length)*TRctRct[i].Length2;
				pArea=TRctRct[i].Area+pArea;

				//
				wcscpy_s(buffer1,_T("("));
				acdbRToS(TRctRct[i].SizeA,2,2,buffer2);
				wcscat_s(buffer1,buffer2);
				acdbRToS(TRctRct[i].SizeB,2,2,buffer);
				wcscat_s(buffer1,_T("x"));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T(")"));

				wcscat_s(buffer1,_T("x("));
				acdbRToS(TRctRct[i].SizeA2,2,2,buffer2);
				wcscat_s(buffer1,buffer2);
				acdbRToS(TRctRct[i].SizeA3,2,2,buffer);
				wcscat_s(buffer1,_T("x"));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T(")"));



				acdbRToS(TRctRct[i].Swectangle,2,2,buffer);
				wcscat_s(buffer1,_T(" (L="));
				wcscat_s(buffer1,buffer);
				wcscat_s(buffer1,_T("мм)"));

				acdbRToS(ceil(TRctRct[i].Length),2,2,buffer2);
				acdbRToS(TRctRct[i].Area,2,2,buffer);
				pb=AddSpecLine(pb,buffer1,_T("шт"),buffer2,_T("м2"),buffer);

			}




		}






		if ((TRndRnd.logicalLength()>0)||
			(TRndRct.logicalLength()>0)||
			(TRctRct.logicalLength()>0)
			)
		{
			acdbRToS(pArea,2,2,buffer);
			pb=AddSpecLine(pb,_T("Всего:"),_T(""),_T(""),_T("м2"),buffer);
			pSumArea=pSumArea+pArea;
			pArea=0;
		}


		//общее количество
		acdbRToS(pSumArea,2,2,buffer);
		pb=AddSpecLine(pb,_T("Общее количество:"),_T(""),_T(""),_T("м2"),buffer);


	} 




	// - Ventilation_ARX.TVS_Show command (do not rename)
	static void Ventilation_ARXTVS_Show(void)
	{

		acutRelRb(acutBuildList(RTSTR,_T("(TVS_TEST2)"),RTNONE,RTNONE));
		//acedCommand(RTSTR,_T("(TVS_TEST2)"),RTNONE,RTNONE);
		// Add your code for command Ventilation_ARX.TVS_Show here
	}

	// - Ventilation_ARX.TVS_CUT command (do not rename)
	static void Ventilation_ARXTVS_CUT(void)
	{
		AcGePoint3d pCut;
		double Lx,Ly, startangle;
		ads_name vozd1,vozd2, eName;
		ACHAR handle[17];
		ads_point pt1,pt2;
		ads_real sise=0;
		AcDbEntity *pEnt1,*pEnt2 = NULL;
		AcDbObjectId id;
		TVS_WYE wyie;
		TVS_TAP * Tapie;
		TVS_Pipe * Pipi1,*Pipi2;
		double NewSiseA, NewRadius;
		resbuf *rb = NULL;
		AcGeLine3d Line;
		bool ft=false, s2=false;
		AcCmColor pColor;
		AcDb::LineWeight pWeight;
		AcDbObjectId pLayer;
		AcDbObjectId pLineType;

		while (ft==false)
		{

			if (acedEntSel (_T("\nВыберете воздуховод:"), vozd1,pt1)== RTCAN)
				return;

			pCut=asPnt3d(pt1);

			if (acdbGetObjectId(id,vozd1)==eOk)
			{

				acdbGetObjectId(id,vozd1);

				{if (id!=AcDbObjectId::kNull)
				{
					if (acdbOpenAcDbEntity(pEnt1,id,AcDb::kForWrite)==eOk)
					{if ( (Pipi1 = TVS_Pipe::cast(pEnt1)) != NULL )
					{	
						Line.set(Pipi1->FirstPoint,Pipi1->LastPoint);
						pCut=Line.closestPointTo(pCut);


						if ((length2p(pCut,Pipi1->FirstPoint)<=(Pipi1->Length-1))
							&&(length2p(pCut,Pipi1->LastPoint)<=(Pipi1->Length-1)))
						{


							Pipi2=Pipi1->add_new(pCut,
								Pipi1->LastPoint,
								Pipi1->SizeA,
								Pipi1->SizeB,
								Pipi1->This1D,
								Pipi1->ThisRound
								);
							Pipi1->put_Lastpoint(pCut);
							s2=true	;
							pColor=Pipi1->color();
							pWeight=Pipi1->lineWeight();
							pLayer=Pipi1->layerId();
							pLineType=Pipi1->linetypeId();
						}
						Pipi1->close();

						if (s2==true)
						{

							if (acdbOpenAcDbEntity(pEnt2,Pipi2->id(),AcDb::kForWrite)==eOk)
							{	




								Pipi2->setColor(pColor);
								Pipi2->setLineWeight(pWeight);
								Pipi2->setLayer(pLayer);
								Pipi2->setLinetype(pLineType);

								Pipi2->put_Wipeout(Pipi1->Wipeout);
								Pipi2->close();

							}


							s2=false;
							ft=true;
						}


					}
					}

					else {
						acutPrintf(_T("\nОбьект заблокирован"));


					}

				}
				}


			}
		}



		// Add your code for command Ventilation_ARX.TVS_CUT here
	}

	// - Ventilation_ARX.TVS_Change command (do not rename)





	static void Ventilation_ARXTVS_Change(void)
	{

		ads_name sset;

		if ( acedSSGet(_T(""), NULL, NULL, NULL, sset)!= RTNORM)
			return;




		Change(sset);







		// Add your code for command Ventilation_ARX.TVS_Change here
	}






	static Acad::ErrorStatus postToDatabase(AcDbVoidPtrArray eSet)
	{
		Acad::ErrorStatus es;
		AcDbBlockTable *pBtbl;
		AcDbBlockTableRecord *pBtblr;
		es =acdbHostApplicationServices()->workingDatabase()
			->getSymbolTable(pBtbl, AcDb::kForRead);
		if (es != Acad::eOk)
		{
			acutPrintf(L"\nFailed to open block table");
			return es;
		}
		es=pBtbl->getAt(ACDB_MODEL_SPACE, pBtblr,AcDb::kForWrite);
		if (es != Acad::eOk)
		{
			acutPrintf(L"\nFailed to open block table record");
			es =pBtbl->close();
			if (es != Acad::eOk)
			{
				acutPrintf(L"\nFailed to close block table");
			}
			return es;
		}

		es =pBtbl->close();
		if (es != Acad::eOk)
		{
			acutPrintf(L"\nFailed to close block table");
			return es;
		}

		for(int i=0; i < eSet.length(); i++)
		{
			AcDbObjectId ObjId;
			AcDbEntity *pNewEnt=AcDbEntity::cast((AcRxObject*)eSet[i]);
			es=pBtblr->appendAcDbEntity(ObjId, pNewEnt);
			if (es != Acad::eOk)
			{
				acutPrintf(L"\nFailed to append entity");
			}

			es=pNewEnt->close();
			if (es != Acad::eOk)
			{
				acutPrintf(L"\nFailed to close entity");
			}
		}

		es=pBtblr->close();
		if (es != Acad::eOk)
		{
			acutPrintf(L"\nFailed to close block table record");
		}
		return es;
	}






	// - Ventilation_ARX.TVS_ERASE command (do not rename)
	static void Ventilation_ARXTVS_ERASE(void)
	{

		ads_name sset, eName;
		ACHAR  resultss [512];
		ACHAR  results1 [512]=_T("2");
		ACHAR  results2 [512]=_T("2d");

		ads_point pt1,pt2;
		ads_real sise=0;
		AcDbEntity *pEnt = NULL;
		AcDbObjectId id;
		TVS_Pipe * Pipi;
		TVS_TAP * Tapie;
		TVS_WYE* Wyeie;
		TVS_TRANS * Transie;

		double NewSiseA;
		bool p1d;
		resbuf *rb = NULL;

		if ( acedSSGet(_T(""), NULL, NULL, NULL, sset)!= RTNORM)
			return;



		long len = 0;

		acedSSLength(sset, &len);
		//consoleprint(double(len),_T("\nL: "));
		for (long i = 0; i < len; i++)
		{             


			if (NULL != (acedSSName(sset,i,eName)))
			{

				//consoleprint(double(i),_T("\nd"));


				acdbGetObjectId(id,eName);

				bool g=false;
				if (id!=AcDbObjectId::kNull)
				{
					if (acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite)==eOk)
					{


						if ( (Pipi = TVS_Pipe::cast(pEnt)) != NULL )
						{	

							AcDbVoidPtrArray eSet;
							Acad::ErrorStatus es=pEnt->explode(eSet);
							pEnt->close();

							//delete the original entity
							acdbEntDel(eName);

							// Add the new entities to the db
							es=postToDatabase(eSet);
							g=true;
						}

						if ( (Tapie = TVS_TAP::cast(pEnt)) != NULL )
						{	
							AcDbVoidPtrArray eSet;
							Acad::ErrorStatus es=pEnt->explode(eSet);
							pEnt->close();

							//delete the original entity
							acdbEntDel(eName);

							// Add the new entities to the db
							es=postToDatabase(eSet);
							g=true;
						}

						if ( (Wyeie = TVS_WYE::cast(pEnt)) != NULL )
						{	
							AcDbVoidPtrArray eSet;
							Acad::ErrorStatus es=pEnt->explode(eSet);
							pEnt->close();

							//delete the original entity
							acdbEntDel(eName);

							// Add the new entities to the db
							es=postToDatabase(eSet);
							g=true;
						}

						if ( (Transie = TVS_TRANS::cast(pEnt)) != NULL )
						{	
							AcDbVoidPtrArray eSet;
							Acad::ErrorStatus es=pEnt->explode(eSet);
							pEnt->close();

							//delete the original entity
							acdbEntDel(eName);

							// Add the new entities to the db
							es=postToDatabase(eSet);
							g=true;
						}


						if (g==false)pEnt->close();
						g=false;
					}

				}
			}


		}
		// Add your code for command Ventilation_ARX.TVS_1D2D here






		// Add your code for command Ventilation_ARX.TVS_ERASE here
	}

	static void Ventilation_ARXTVS_LEAD(void)
	{

int pstatus;
		double SizeA,SizeB,Flow,SizeA2, SizeB2;
		AcGePoint3d pCut;
		double Lx,Ly, startangle;
		ads_name vozd1,vozd2, eName;
		ACHAR handle[17];
		ads_point pt1,pt2;
		ads_real sise=0;
		AcDbEntity *pEnt1,*pEnt2 = NULL;
		AcDbObjectId id;
		TVS_WYE *wyie;
		TVS_TAP * Tapie;
		TVS_Pipe * Pipi1,*Pipi2;
		TVS_TRANS * Transie;
		double NewSiseA, NewRadius;
		resbuf *rb = NULL;
		AcGeLine3d Line;
		bool ft=false, s2=false;
		AcCmColor pColor;
		AcDb::LineWeight pWeight;
		AcDbObjectId pLayer;
		AcDbObjectId pLineType;


		int Astat;
		bool  Astat2=false;
		ACHAR resultss[512],resultss2[512];
		while (ft==false)
		{

			Astat2=false;
			while (Astat2==false)
			{
				Astat2=true;
				acedInitGet(RSG_NONULL, _T("Формат Ф a"));
				Astat=acedEntSel (_T("\nВыберете воздуховод или [Формат]: "), vozd1,pt1) ;
				switch (Astat)
				{
				case RTCAN:
					return;
					break;
				case RTKWORD:
					acedGetInput(resultss);
					break;
				}

				if (Astat==RTKWORD)
				{
					acedInitGet(RSG_NONULL, _T("Да Нет д н y n l"));
					if (acedGetKword(_T("\nУказывать расход? [Да/Нет]: "), resultss2)== RTCAN)
						return;

					if ((wcscmp(resultss2,_T("Да"))==0)||(wcscmp(resultss2,_T("д"))==0)||(wcscmp(resultss2,_T("y"))==0)||(wcscmp(resultss2,_T("l"))==0))

						globalMlead=2;
					else globalMlead=1;
					Astat2=false;
					Astat=0;
					wcscpy_s(resultss,_T(""));
				}

			}




			pCut=asPnt3d(pt1);

			if (acdbGetObjectId(id,vozd1)==eOk)
			{
				{if (id!=AcDbObjectId::kNull)
				{
					if (acdbOpenAcDbEntity(pEnt1,id,AcDb::kForWrite)==eOk)
					
					{
						if ( (Pipi1 = TVS_Pipe::cast(pEnt1)) != NULL )
						{	
						Line.set(Pipi1->FirstPoint,Pipi1->LastPoint);
						pCut=Line.closestPointTo(pCut);
						SizeA=Pipi1->SizeA;
						SizeB=Pipi1->SizeB;
						Flow=Pipi1->Flow;
						ft=true;
						pstatus=1;
						}

						if ( (Tapie = TVS_TAP::cast(pEnt1)) != NULL )
						{	
							//Line.set(Tapie->MC,Tapie->LastPoint);
							//pCut=Line.closestPointTo(pCut);
pCut=Tapie->MiddlePoint;
							SizeA=Tapie->SizeA;
							SizeB=Tapie->SizeB;
							Flow=Tapie->Flow;
							ft=true;
							pstatus=2;
						}

						if ( (wyie = TVS_WYE::cast(pEnt1)) != NULL )
						{	
							Line.set(wyie->pA1,wyie->pA3);
							pCut=Line.closestPointTo(pCut);
							SizeA=wyie->SizeApr;
							SizeB=wyie->SizeBpr;
							SizeA2=wyie->SizeAotv;
							SizeB2=wyie->SizeBotv;
							Flow=wyie->LengthPl;
							ft=true;
							pstatus=3;
						}

						if ( (Transie = TVS_TRANS::cast(pEnt1)) != NULL )
						{	
							Line.set(Transie->FirstPoint,Transie->LastPoint);
							pCut=Line.closestPointTo(pCut);
							SizeA=Transie->get_SizeAp1();
							SizeB=Transie->SizeBp1;
							SizeA2=Transie->SizeAp2;
							SizeB2=Transie->SizeBp2;
							Flow=Transie->LengthTr;
							ft=true;
							pstatus=4;
						}


					pEnt1->close();
					}


					else {
						acutPrintf(_T("\nОбьект заблокирован"));


					}

				}
				}


			}
		}








		pt1[0]=pCut.x;
		pt1[1]=pCut.y;
		pt1[2]=pCut.z;
		if(acedGetPoint(pt1,_T("\nУкажите 2 точку:"),pt2)==RTCAN)
			return;



		///////Текст
		AcDbMText *mText=new AcDbMText();
		ACHAR buffer[512], buffer1[512], buffer2[512] ;
if (pstatus==1||pstatus==2)
{

		if (globalMlead==1)
		{
			if (SizeB==0)
			{

				wcscpy_s(buffer1,_T("%%C"));
				acdbRToS(SizeA,2,2,buffer);
				wcscat_s(buffer1,buffer);
			}
			else
			{
				acdbRToS(SizeA,2,2,buffer1);
				wcscat_s(buffer1,_T("x"));
				acdbRToS(SizeB,2,2,buffer);
				wcscat_s(buffer1,buffer);
			}
		}

		if (globalMlead==2)
		{
			if (SizeB==0)
			{

				wcscpy_s(buffer1,_T("%%C"));
				acdbRToS(SizeA,2,2,buffer);
				wcscat_s(buffer1,buffer);
			}
			else
			{
				acdbRToS(SizeA,2,2,buffer1);
				wcscat_s(buffer1,_T("x"));
				acdbRToS(SizeB,2,2,buffer);
				wcscat_s(buffer1,buffer);
			}

			wcscat_s(buffer1,_T("\\PL"));
			acdbRToS(Flow,2,2,buffer);
			wcscat_s(buffer1,buffer);
		}


}
if (pstatus==3||pstatus==4)
{

	if (SizeB==0)
	{

		wcscpy_s(buffer1,_T("%%C"));
		acdbRToS(SizeA,2,2,buffer);
		wcscat_s(buffer1,buffer);
		wcscat_s(buffer1,_T("x"));
	}
	else
	{
		wcscpy_s(buffer1,_T("("));
		acdbRToS(SizeA,2,2,buffer);
		wcscat_s(buffer1,buffer);
		wcscat_s(buffer1,_T("x"));
		acdbRToS(SizeB,2,2,buffer);
		wcscat_s(buffer1,buffer);
		wcscat_s(buffer1,_T(")x"));
	}

	if (SizeB2==0)
	{

		wcscat_s(buffer1,_T("%%C"));
		acdbRToS(SizeA2,2,2,buffer);
		wcscat_s(buffer1,buffer);
	}
	else
	{
		wcscat_s(buffer1,_T("("));
		acdbRToS(SizeA2,2,2,buffer);
		wcscat_s(buffer1,buffer);
		wcscat_s(buffer1,_T("x"));
		acdbRToS(SizeB2,2,2,buffer);
		wcscat_s(buffer1,buffer);
		wcscat_s(buffer1,_T(")"));
	}

}



		AcDb::LineWeight lw;
		double texth,textw;
		AcDbDatabase *db=acdbHostApplicationServices()->workingDatabase();
		AcGePoint3d ptEnd1=asPnt3d(pt2);
		AcGeVector3d vec;
		AcGePoint3d ptStart(pCut);
		if (ptStart.x<ptEnd1.x)
		{
			vec=AcGeVector3d(0,1,0);
			//mText->setAttachment(AcDbMText::kBottomLeft);
		}
		else
		{
			vec=AcGeVector3d(0,-1,0);
			//mText->setAttachment(AcDbMText::kBottomRight);
		}




		mText->setContents(buffer1);

		//mText->getColumnHeight(0,texth);
		//mText->getColumnWidth(textw);
		mText->setLocation(ptEnd1);
		mText->setColor(pEnt1->color());
		mText->setLineWeight(AcDb::kLnWt025);

//мультивыноска
		AcDbMLeader *pEnt=new AcDbMLeader();
		
		pEnt->setLineWeight(AcDb::kLnWt025);
		pEnt->setColor(pEnt1->color());
		
		//pEnt->setTextLocation(ptEnd1);
		int i;
		// 		AcGePoint3d ptEnd1(AcGePoint3d(pCut.x+500,
		// 		pCut.y+500, pCut.z));

		
		pEnt->setContentType(AcDbMLeaderStyle::kMTextContent);
		pEnt->addLeader(i);
		pEnt->addLeaderLine(ptStart,i);
		pEnt->addLastVertex(i,ptEnd1);
		//pEnt->setEnableDogleg(false);
		//pEnt->setDoglegLength(10);
		//pEnt->setDoglegDirection(i,vec);
		pEnt->setMText(mText);
		//pEnt->setBlockConnectionType(AcDbMLeaderStyle::kConnectBase);
		////////////////////////////////////////////////////////////////

		//		......Got the inserted content block and arrow block for the Mleader

		///////////////////////////////////////////////////////////////// 
		// 			pEnt->setArrowSymbolId(arrowDefId);   // 'arrowDefId' inputs the ID of  arrow block to be inserted
		// 		pEnt->setBlockContentId(blkDefId);       // 'blkDefId' inputs the ID of  content block to be inserted

		PostToModelSpace(pEnt);
		//PostToModelSpace(mText);

		if (acdbOpenAcDbEntity(pEnt1,pEnt->id(),AcDb::kForWrite)==eOk)	
		{
			
			pEnt->setLastVertex(i,ptEnd1);
			// 		pEnt->mtext()->setColor(db->cecolor());
			// 		
			// 		pEnt->getLeaderLineWeight(i,lw);
			// 		pEnt->mtext()->setLineWeight(lw);
			// 		pEnt->setColor(db->cecolor());
			pEnt->close();

		}

	

		return static void();
	}

	static void setZ()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}



} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CTVS_Ventilation_ARXApp)
	ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, Ventilation_ARX, TVS_PIPE, TVS_PIPE, ACRX_CMD_TRANSPARENT, NULL)
	ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, Ventilation_ARX, TVS_TRANS, TVS_TRANS, ACRX_CMD_TRANSPARENT, NULL)
	ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, Ventilation_ARX, TVS_WYE, TVS_WYE, ACRX_CMD_TRANSPARENT, NULL)
	ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, Ventilation_ARX, TVS_CONNECT, TVS_CONNECT, ACRX_CMD_TRANSPARENT | ACRX_CMD_USEPICKSET, NULL)
	ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, Ventilation_ARX, TVS_DUCT, TVS_DUCT, ACRX_CMD_TRANSPARENT, NULL)
	ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, Ventilation_ARX, TVS_1D2D, TVS_1D2D, ACRX_CMD_TRANSPARENT | ACRX_CMD_USEPICKSET, NULL)
	ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, Ventilation_ARX, TVS_SPEC, TVS_SPEC, ACRX_CMD_TRANSPARENT | ACRX_CMD_USEPICKSET, NULL)

	ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, Ventilation_ARX, TVS_Show, TVS_Show, ACRX_CMD_TRANSPARENT, NULL)
	ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, Ventilation_ARX, TVS_CUT, TVS_CUT, ACRX_CMD_TRANSPARENT, NULL)
	ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, Ventilation_ARX, TVS_Change, TVS_Change, ACRX_CMD_TRANSPARENT | ACRX_CMD_USEPICKSET, NULL)
	ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, Ventilation_ARX, TVS_ERASE, TVS_ERASE, ACRX_CMD_TRANSPARENT | ACRX_CMD_USEPICKSET, NULL)
	ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, Ventilation_ARX, TVS_LEAD, TVS_LEAD, ACRX_CMD_TRANSPARENT, NULL)

ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, TVSMyGroup, MyCommand, MyCommandLocal, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, TVSMyGroup, MyPickFirst, MyPickFirstLocal, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CTVS_Ventilation_ARXApp, TVSMyGroup, MySessionCmd, MySessionCmdLocal, ACRX_CMD_MODAL | ACRX_CMD_SESSION, NULL)
ACED_ADSSYMBOL_ENTRY_AUTO(CTVS_Ventilation_ARXApp, MyLispFunction, false)

