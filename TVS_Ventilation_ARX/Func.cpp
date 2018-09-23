#pragma once;
#include "StdAfx.h"
#include "Func.h"




void func::consoleprint( double It,const ACHAR*format)
{
	ACHAR buffer[512];
	acdbRToS(It,2,2,buffer);
	acutPrintf(format);
	acutPrintf(buffer);

}

void func::consoleprint(AcGePoint3d pPointi,const ACHAR*format)
{
	ACHAR buffer[512];
	double coordinate;
	acutPrintf(format);

	coordinate=pPointi.x;
	acdbRToS(coordinate,2,2,buffer);
	acutPrintf(_T(" X=%s"),buffer);


	coordinate=pPointi.y;
	acdbRToS(coordinate,2,2,buffer);
	acutPrintf(_T(" Y=%s"),buffer);


	coordinate=pPointi.z;
	acdbRToS(coordinate,2,2,buffer);
	acutPrintf(_T(" Z=%s"),buffer);


}

void func::Givecenterpoint (AcGePoint3d &n1,
							AcGePoint3d &n2,
							AcGePoint3d &n3,
							double &pRadius,
							AcGePoint3d &midp,
							double &pAngle,
							AcGeVector3d &pStartvector)
{


	AcGePoint3d R1,R2,R3,R4,
		B1,B2,B3,B4,
		S1,S2,F1,F2,
		Norm1,Norm2;
	double npRadius;
	npRadius=-pRadius;
	AcGeVector3d finishvector;
	fourpoints(n1,n2,R1,R2,B2,B1,pRadius);
	fourpoints(n2,n3,R3,R4,B4,B3,pRadius);

	if(intersection(R1,R2,R3,R4,midp)==true)
	{
		//acutPrintf(_T("\n1"));
		S1=R2; F1=B2; 
		S2=R3; F2=B3;
	}

	if(intersection(B1,B2,B3,B4,midp)==true)
	{
		//acutPrintf(_T("\n4"));
		S1=B2; F1=R2; 
		S2=B3; F2=R3;
	}


	Norm1=AcGePoint3d(F1.x-S1.x,
		F1.y-S1.y,
		0);
	Norm2=AcGePoint3d(F2.x-S2.x,
		F2.y-S2.y,
		0);
	//consoleprint(Norm1,_T("\nПервая точка"));
	//consoleprint(Norm2,_T("\nВторая точка"));
	pStartvector=AcGeVector3d(Norm1.x,Norm1.y,0);
	finishvector=AcGeVector3d(Norm2.x,Norm2.y,0);

	pAngle=angle(Norm1,Norm2);

	//consoleprint(pAngle,_T("\nУгол"));
	Givestartvector(pStartvector,finishvector,pAngle);
	//pStartvector.normalize();
	midp=n2;
	//consoleprint(pAngle,_T("\nУгол"));







	// 	AcGeVector3d pfinishvector;
	// 	pfinishvector=AcGeVector3d(n3.x-n2.x,n3.y-n2.y,n3.z-n2.z);
	// 	pStartvector=AcGeVector3d(n2.x-n1.x,n2.y-n1.y,n2.z-n1.z);
	// 	midp=n2;
	// 	
	// 	pfinishvector.normalize();
	// 	pStartvector.normalize();
	// 	pAngle=pStartvector.angleTo(pfinishvector);



}
AcGePoint3d func::dist(AcGePoint3d &pF,
					   AcGePoint3d &pN, 
					   double &pR)
{

	double x1, xR, y1, yR;
	x1=pN.x-pF.x;
	y1=pN.y-pF.y;
	yR=pR*x1/sqrt(x1*x1+y1*y1);
	xR=pR*y1/sqrt(x1*x1+y1*y1);
	return (AcGePoint3d(xR,yR,0));
}

AcGePoint3d func::summ (AcGePoint3d &pA,AcGePoint3d &pB)
{

	return AcGePoint3d(pA.x+pB.x,
		pA.y+pB.y,
		pA.z+pB.z
		);
}
bool func::intersection (AcGePoint3d &p1,
						 AcGePoint3d &p2,
						 AcGePoint3d &p3,
						 AcGePoint3d &p4,
						 AcGePoint3d &MID)
{

	AcGePoint3d MIDI;
	//acutPrintf(_T("\ninterseption_begin"));
	//consoleprint(p1,_T("\np1: "));
	//consoleprint(p2,_T("\np2: "));
	//consoleprint(p3,_T("\np3: "));
	//consoleprint(p4,_T("\np4: "));
	AcGeLine3d line1(p1,p2),line2(p3,p4) ;
	line1.intersectWith(line2,MIDI);
	double d = (p1.x - p2.x) * (p4.y - p3.y) - (p1.y - p2.y) * (p4.x - p3.x);
	double da= (p1.x - p3.x) * (p4.y - p3.y) - (p1.y - p3.y) * (p4.x - p3.x);
	double db = (p1.x - p2.x) * (p1.y - p3.y) - (p1.y - p2.y) * (p1.x - p3.x);

	double ta = da / d;
	double tb = db / d;

	if (ta >= 0 && ta <= 1 && tb >= 0 && tb <= 1)
	{
		double dx = p1.x + ta * (p2.x - p1.x);
		double dy = p1.y + ta * (p2.y - p1.y);

		MID=MIDI;
		return true;
		//acutPrintf(_T("\ninterseption_ok"));
	}






	//acutPrintf(_T("\ninterseption_no"));
	return false;
}

void func::fourpoints(AcGePoint3d &FirstPoint,
					  AcGePoint3d &LastPoint,
					  AcGePoint3d &p1,
					  AcGePoint3d &p2,
					  AcGePoint3d &p3,
					  AcGePoint3d &p4,
					  double &Radius)
{
	double X1,X2,Y1,Y2,PipeLength;
	X1=LastPoint.x-FirstPoint.x;
	Y1=LastPoint.y-FirstPoint.y;
	PipeLength=sqrt(X1*X1+Y1*Y1);
	X2=Y1*Radius/PipeLength;
	Y2=X1*Radius/PipeLength;
	p1=AcGePoint3d(FirstPoint.x-X2,FirstPoint.y+Y2,FirstPoint.z);
	p2=AcGePoint3d(LastPoint.x-X2,LastPoint.y+Y2,FirstPoint.z);
	p3=AcGePoint3d(LastPoint.x+X2,LastPoint.y-Y2,FirstPoint.z);
	p4=AcGePoint3d(FirstPoint.x+X2,FirstPoint.y-Y2,FirstPoint.z);
}

double func::angle(AcGePoint3d &pt1,AcGePoint3d &pt2,AcGePoint3d &basepoint)
{
	double x1, x2, y1, y2, angle1; 
	x1=pt1.x-basepoint.x;
	x2=pt2.x-basepoint.x;
	y1=pt1.y-basepoint.y;
	y2=pt2.y-basepoint.y;
	angle1=acos((x1*x2+y1*y2)/sqrt(x1*x1+y1*y1)/sqrt(x2*x2+y2*y2));
	return angle1;
}
void func::Givestartvector (AcGeVector3d &Starvector,AcGeVector3d &v2, double &pangle)
{
	double x1, x2, y1, y2, angle1,angle2; 
	double pi =  3.14159265359;

	AcGePoint3d pt1,pt2, np=AcGePoint3d(1,0,0);
	x1=Starvector.x;
	x2=v2.x;
	y1=Starvector.y;
	y2=v2.y;
	pt1=AcGePoint3d(x1,y1,0);
	pt2=AcGePoint3d(x2,y2,0);
	angle1=angle(np,pt1);
	if (Starvector.y<0)
	{
		angle1=2*pi-angle1;
	}
	angle2=angle(np,pt2);
	if (v2.y<0)
	{
		angle2=2*pi-angle2;
	};
	//consoleprint(pt1,_T("\nstartvector :"));
	//consoleprint(pt2,_T("\nvector2 :"));
	if ((angle2>angle1)&&((angle2-angle1)>pi))
	{Starvector=v2;}

	if ((angle2<angle1)&&((angle1-angle2)<pi))
	{Starvector=v2;}
	//consoleprint(angle1,_T("\nУгол 1:"));
	//consoleprint(angle2,_T("\nУгол 2:"));
	pt1=AcGePoint3d(Starvector.x,Starvector.y,0);
	//consoleprint(pt1,_T("\nstartvector :"));
}
bool func::correctpipes(AcGePoint3d &A,
						AcGePoint3d &B,
						AcGePoint3d &C,
						double &pangle,
						double &pSizeA,
						double &pRadius,
						AcGePoint3d &lastpipi,
						bool &pThisRound)
{
	AcGePoint3d pB1,pB2;
	double plength1,plength2,negatvel;
	double flanez=0;
	if ((pThisRound==true)&&(pSizeA<630))
	{
		flanez=45;
	}
	plength1=length2p(A,B);
	plength2=length2p(B,C);

	negatvel=(pSizeA/2+pRadius)*tan(pangle/2)+flanez;

	if((plength1>negatvel)&&(plength2>negatvel))
	{
		pB1=shortlength(A,B,negatvel);

		lastpipi=pB1;



		//consoleprint(pipi->LastPoint,_T("\npipi->LastPoint: "));


		B=shortlength(C,B,negatvel);
		return true;
	}

	else
	{
		return false;
	}


}
double func::length2p(AcGePoint3d A,
					  AcGePoint3d B
					  )
{
	double x1,y1;
	x1=A.x-B.x;
	y1=A.y-B.y;
	return (sqrt(x1*x1+y1*y1));


}
AcGePoint3d func::shortlength(AcGePoint3d &A,
							  AcGePoint3d &B,
							  double thislegth
							  )
{
	double x1,y1, R;
	AcGePoint3d Bi;
	x1=B.x-A.x;
	y1=B.y-A.y;
	R=length2p(A,B);
	x1=x1*(R-thislegth)/R;
	y1=y1*(R-thislegth)/R;
	Bi=AcGePoint3d(x1+A.x,y1+A.y,A.z);
	return Bi;
}






void func::startdraw ()
{


}

AcGePoint3d func::AddSpecLine(AcGePoint3d cent,
							  const ACHAR*t1,
							  const ACHAR*t2,
							  const ACHAR*t3,
							  const ACHAR*t4,
							  const ACHAR*t5)
{
	AcGePoint3d pos1, pos2, pos3,pos4,pos5;
	pos1=AcGePoint3d(cent.x+300,cent.y+50,cent.z);
	pos2=AcGePoint3d(cent.x+300+5500,cent.y+50,cent.z);
	pos3=AcGePoint3d(cent.x+300+6400,cent.y+50,cent.z);
	pos4=AcGePoint3d(cent.x+300+7500,cent.y+50,cent.z);
	pos5=AcGePoint3d(cent.x+300+8400,cent.y+50,cent.z);

	AcDbDatabase *db=acdbHostApplicationServices()->workingDatabase();

	AcDbObjectId tId=db->textstyle();
	///
	AcDbText *text1 = new AcDbText (pos1, t1,tId,250,0 );

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable,
		AcDb::kForRead);

	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId retId = AcDbObjectId::kNull;
	pBlockTableRecord->appendAcDbEntity(retId, text1);
	pBlockTableRecord->close();
	text1->close();
	//
	if ((wcscmp(t2,_T(""))!=0))
	{

		AcDbText *text2 = new AcDbText (pos2, t2,tId,250,0 );


		acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable,
			AcDb::kForRead);


		pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,AcDb::kForWrite);
		pBlockTable->close();


		pBlockTableRecord->appendAcDbEntity(retId, text2);
		pBlockTableRecord->close();
		text2->close();
	}
	//
	//
	if ((wcscmp(t3,_T(""))!=0))
	{
		AcDbText *text3 = new AcDbText (pos3, t3,tId,250,0 );


		acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable,
			AcDb::kForRead);


		pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,AcDb::kForWrite);
		pBlockTable->close();


		pBlockTableRecord->appendAcDbEntity(retId, text3);
		pBlockTableRecord->close();
		text3->close();
	}


	//
	if ((wcscmp(t4,_T(""))!=0))
	{
		AcDbText *text4 = new AcDbText (pos4, t4,tId,250,0 );


		acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable,
			AcDb::kForRead);


		pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,AcDb::kForWrite);
		pBlockTable->close();


		pBlockTableRecord->appendAcDbEntity(retId, text4);
		pBlockTableRecord->close();
		text4->close();
	}

	if ((wcscmp(t5,_T(""))!=0))
	{
		AcDbText *text5 = new AcDbText (pos5, t5,tId,250,0 );


		acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable,
			AcDb::kForRead);


		pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,AcDb::kForWrite);
		pBlockTable->close();


		pBlockTableRecord->appendAcDbEntity(retId, text5);
		pBlockTableRecord->close();
		text5->close();
	}
	//
	return (AcGePoint3d(cent.x,cent.y-800,cent.z));

}




// void func::TVS_CS (AcDbEntity *pEnt)
// 
// {
// 
// 	TVS_Pipe *pPipe;
// 	AcApDocument *pDoc=acDocManager->curDocument();
// 	acDocManager->lockDocument(pDoc,AcAp::kWrite);
// 	if ( (pPipe = TVS_Pipe::cast(pEnt)) != NULL )
// 	{
// 		
// 		
// 		if(pPipe->upgradeOpen()!=Acad::eOk)
// 		{
// 			acutPrintf(_T("Не могу открыть"));
// 			return;
// 		} 
// 			
// 			
// 			
// 			double a,b;
// 			TVS_MFK_PipeEdit r;
// 			a=r.SizeA=pPipe->SizeA;
// 			b=r.SizeB=pPipe->SizeB;
// 			r.DoModal();
// 			pPipe->put_SizeA(r.SizeA);
// 			pPipe->put_SizeB(r.SizeB);
// 			
// 			pPipe->close();
// 		}
// 		acDocManager->unlockDocument(pDoc);
// 	}


// void func::TVS_PEdit (AcDbEntity *pEnt)
// 
// {
// 	
// 	TVS_Pipe *pPipe;
// 	TVS_TRANS *pTrans;
// 	TVS_WYE *pWye;
// 	TVS_TAP *pTap;
// 	AcApDocument *pDoc=acDocManager->curDocument();
// 	acDocManager->lockDocument(pDoc,AcAp::kWrite);
// 	if ( (pPipe = TVS_Pipe::cast(pEnt)) != NULL )
// 	{
// 
// 
// 		if(pPipe->upgradeOpen()!=Acad::eOk)
// 		{
// 			acutPrintf(_T("Не могу открыть"));
// 			return;
// 		} 
// 
// acDocManager->unlockDocument(pDoc);	
// 
// 		double a,b,dP,i,v,flow,Length;
// 		bool d1;
// 		DgPEdit r;
// 		a=r.SizeA=pPipe->SizeA;
// 		b=r.SizeB=pPipe->SizeB;
// 		flow=r.Flow=pPipe->Flow;
// 		d1=r.D1=pPipe->This1D;
// 		Length=r.Length=pPipe->Length;
// 		r.Wipe=pPipe->Wipeout;
// 		r.Grani=pPipe->Grani;
// 		r.Elev=pPipe->Elev;
// 		r.ElevUp=pPipe->ElevUp;
// 		r.ElevDown=pPipe->ElevDown;
// 		r.Raschet2();
// 
// 		{
// 
// 		
// 	CAcModuleResourceOverride resourceOverride;
// 		r.DoModal();
// 		}
// 		pPipe->put_SizeA(r.SizeA);
// 		pPipe->put_SizeB(r.SizeB);
// 		pPipe->put_This1D(r.D1);
// 		pPipe->put_Flow(r.Flow);
// 		pPipe->put_Wipeout(r.Wipe);
// 		pPipe->put_Grani(r.Grani);
// 		
// 		pPipe->put_ElevUp(r.ElevUp);
// 		pPipe->put_ElevDown(r.ElevDown);
// 		pPipe->put_Elevation(r.Elev);
// 
// 
// 		if (r.SizeB==0) pPipe->put_ThisRound(true);
// 		else pPipe->put_ThisRound(false);
// 		
// 		pPipe->close();
// 	}
// 
// 	if ( (pTap = TVS_TAP::cast(pEnt)) != NULL )
// 	{
// 
// 
// 		if(pTap->upgradeOpen()!=Acad::eOk)
// 		{
// 			acutPrintf(_T("Не могу открыть"));
// 			return;
// 		} 
// 
// //acutPrintf(_T("\nYo"));
// 
// 
// 		pTap->close();
// 	}
// 
// 	if ( (pTrans = TVS_TRANS::cast(pEnt)) != NULL )
// 	{
// 
// 
// 		if(pTrans->upgradeOpen()!=Acad::eOk)
// 		{
// 			acutPrintf(_T("Не могу открыть"));
// 			return;
// 		} 
// 
// //acutPrintf(_T("\nYo"));
// 
// 
// 		pTrans->close();
// 	}
// 
// 
// 	if ( (pWye = TVS_WYE::cast(pEnt)) != NULL )
// 	{
// 
// 
// 		if(pWye->upgradeOpen()!=Acad::eOk)
// 		{
// 			acutPrintf(_T("Не могу открыть"));
// 			return;
// 		} 
// 
// //acutPrintf(_T("\nYo"));
// 
// 
// 		pWye->close();
// 	}
// 
// 
// 
// 
// 
// 	acDocManager->unlockDocument(pDoc);
// 
// }

//
//void func::Change (ads_name &sset)
//{
//
//
//
//
//	ads_name  eName;
//	ACHAR  resultss [512];
//	ACHAR  results1 [512]=_T("2");
//	ACHAR  results2 [512]=_T("2d");
//
//	ads_point pt1,pt2;
//	ads_real sise=0;
//	AcDbEntity *pEnt = NULL;
//	AcDbObjectId id;
//	TVS_Pipe * Pipi;
//	TVS_TAP * Tapie;
//	TVS_WYE* Wyeie;
//	TVS_TRANS * Transie;
//
//	double NewSiseA;
//	bool p1d;
//	resbuf *rb = NULL;
//
//
//
//
//
//	long len = 0;
//
//	acedSSLength(sset, &len);
//	//проверяем элементы и извлекаем данные
//	bool firstPipe=false;
//	bool firstTap=false;
//	bool firstTrans=false;
//	bool firstWye=false;
//
//	bool vSizeA=false;
//	bool vSizeB=false;
//	bool vFlow=false;
//	bool vSizeA2=false;
//	bool vSizeB2=false;
//	bool vLengthTr=false;
//	bool vLengthW=false;
//	bool vWipe=false;
//	bool vGrani=false;
//	bool vD1=false;
//	bool vElev=false;
//
//
//
//	bool fSizeA=true;
//	bool fSizeB=true;
//	bool fFlow=true;
//	bool fSizeA2=true;
//	bool fSizeB2=true;
//	bool fLengthTr=true;
//	bool fLengthW=true;
//	bool fWipe=true;
//	bool fGrani=true;
//	bool fD1=true;
//	bool fElev=true;
//
//
//	double SizeA=0;
//	double SizeB=0;
//	double Flow=0;
//	double SizeA2=0;
//	double SizeB2=0;
//	double LengthTr=0;
//	double LengthW=0;
//	bool Wipe=false;
//	bool Grani=false;
//	bool D1=false;
//	double Elev=0;
//
//
//	CString sSizeA;
//	CString sSizeB;
//	CString sFlow;
//	CString sSizeA2;
//	CString sSizeB2;
//	CString sLengthTr;
//	CString sLengthW;
//	CString sElev;
//
//	BOOL sWipe;
//	BOOL sGrani;
//	BOOL sD1;
//
//
//
//	for (long i = 0; i < len; i++)
//	{             
//
//
//		if (NULL != (acedSSName(sset,i,eName)))
//		{
//
//			//consoleprint(double(i),_T("\nd"));
//
//
//			acdbGetObjectId(id,eName);
//
//			if (id!=AcDbObjectId::kNull)
//			{
//				if (acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite)==eOk)
//				{
//
//
//
//
//					if ( (Pipi = TVS_Pipe::cast(pEnt)) != NULL )
//					{	
//
//						if (firstPipe==false) firstPipe=true;
//
//						rprov(vSizeA,fSizeA,Pipi->SizeA,SizeA);
//						rprov(vSizeB,fSizeB,Pipi->SizeB,SizeB);
//						rprov(vFlow,fFlow,Pipi->Flow,Flow);
//						rprov(vGrani,fGrani,Pipi->Grani,Grani);
//						rprov(vD1,fD1,Pipi->This1D,D1);
//						rprov(vWipe,fWipe,Pipi->Wipeout,Wipe);
//						rprov(vElev,fElev,Pipi->Elev,Elev);
//
//
//					}
//
//					if ( (Tapie = TVS_TAP::cast(pEnt)) != NULL )
//					{	
//						if (firstTap==false) firstTap=true;
//
//						rprov(vSizeA,fSizeA,Tapie->SizeA,SizeA);
//						rprov(vSizeB,fSizeB,Tapie->SizeB,SizeB);
//
//						rprov(vD1,fD1,Tapie->This1D,D1);
//						rprov(vWipe,fWipe,Tapie->Wipeout,Wipe);
//						rprov(vElev,fElev,Tapie->Elev,Elev);
//
//					}
//
//					if ( (Wyeie = TVS_WYE::cast(pEnt)) != NULL )
//					{	
//						if (firstWye==false) firstWye=true;
//
//						rprov(vSizeA,fSizeA,Wyeie->SizeApr,SizeA);
//						rprov(vSizeB,fSizeB,Wyeie->SizeBpr,SizeB);
//						rprov(vSizeA2,fSizeA2,Wyeie->SizeAotv,SizeA2);
//						rprov(vSizeB2,fSizeB2,Wyeie->SizeBotv,SizeB2);
//						rprov(vLengthW,fLengthW,Wyeie->LengthPl,LengthW);
//
//						rprov(vD1,fD1,Wyeie->This1D,D1);
//						rprov(vWipe,fWipe,Wyeie->Wipeout,Wipe);
//						rprov(vElev,fElev,Wyeie->Elev,Elev);
//
//					}
//
//					if ( (Transie = TVS_TRANS::cast(pEnt)) != NULL )
//					{	
//						if (firstTrans==false) firstTrans=true;
//
//						rprov(vSizeA,fSizeA,Transie->SizeAp1,SizeA);
//						rprov(vSizeB,fSizeB,Transie->SizeBp1,SizeB);
//						rprov(vSizeA2,fSizeA2,Transie->SizeAp2,SizeA2);
//						rprov(vSizeB2,fSizeB2,Transie->SizeBp2,SizeB2);
//						rprov(vLengthTr,fLengthTr,Transie->LengthTr,LengthTr);
//
//						rprov(vD1,fD1,Transie->This1D,D1);
//						rprov(vWipe,fWipe,Transie->Wipeout,Wipe);
//
//						rprov(vElev,fElev,Transie->Elev,Elev);
//
//					}
//
//
//					pEnt->close();
//				}
//			}
//		}
//
//	}
//
//
//
//
//
//
//
//
//	strfil(SizeA,vSizeA,sSizeA);
//	strfil(SizeB,vSizeB,sSizeB);
//	strfil(SizeA2,vSizeA2,sSizeA2);
//	strfil(SizeB2,vSizeB2,sSizeB2);
//	strfil(Flow,vFlow,sFlow);
//	strfil(LengthTr,vLengthTr,sLengthTr);
//	strfil(LengthW,vLengthW,sLengthW);
//	strfil(Elev,vElev,sElev);
//	strfil(Wipe,vWipe,sWipe);
//	strfil(Grani,vGrani,sGrani);
//	strfil(D1,vD1,sD1);
//
//	BOOL ElevationMid=1;
//	BOOL ElevationUp=0;
//	BOOL ElevationDown=0;
//
//
//
//
//	dgAllEdit dg;
//	dg.SizeA=sSizeA;
//	dg.SizeB=sSizeB;
//	dg.SizeA2=sSizeA2;
//	dg.SizeB2=sSizeB2;
//	dg.Flow=sFlow;
//	dg.LengthTr=sLengthTr;
//	dg.LengthW=sLengthW;
//	dg.Tpipe=firstPipe;
//	dg.Twye=firstWye;
//	dg.Ttrans=firstTrans;
//	dg.Ttap=firstTap;
//	dg.Wipe=sWipe;
//	dg.Grani=sGrani;
//	dg.D1=sD1;
//	dg.ElevMid=ElevationMid;
//	dg.Elev=sElev;
//
//	if (firstPipe==false
//		&&firstTap==false
//		&&firstTrans==false
//		&&firstWye==false)
//	{
//		acutPrintf(_T("\nНичего не выбрано"));
//		return;
//	}
//	{
//
//		CAcModuleResourceOverride resourceOverride;
//		dg.DoModal();
//
//	}
//
//
//	bool cSizeA=true;
//	bool cSizeB=true;
//	bool cFlow=true;
//	bool cSizeA2=true;
//	bool cSizeB2=true;
//	bool cLengthTr=true;
//	bool cLengthW=true;
//	bool cWipe=true;
//	bool cGrani=true;
//	bool cD1=true;
//	bool cElev=true;
//
//	sequal(SizeA,sSizeA,dg.SizeA,cSizeA);
//	sequal(SizeB,sSizeB,dg.SizeB,cSizeB);
//	sequal(Flow,sFlow,dg.Flow,cFlow);
//	sequal(SizeA2,sSizeA2,dg.SizeA2,cSizeA2);
//	sequal(SizeB2,sSizeB2,dg.SizeB2,cSizeB2);
//	sequal(LengthTr,sLengthTr,dg.LengthTr,cLengthTr);
//	sequal(LengthW,sLengthW,dg.LengthW,cLengthW);
//	sequal(Elev,sElev,dg.Elev,cElev);
//	sequal(Wipe,sWipe,dg.Wipe,cWipe);
//	sequal(Grani,sGrani,dg.Grani,cGrani);
//	sequal(D1,sD1,dg.D1,cD1);
//
//
//
//	///определение выравнивания
//	int Emode=0;//по центру
//	if (dg.ElevUp==1)//по верху
//	{
//		Emode=1;
//	}
//
//	if (dg.ElevDown==1)//по низу
//	{
//		Emode=2;
//	}
//
//	for (long i = 0; i < len; i++)
//	{             
//
//
//		if (NULL != (acedSSName(sset,i,eName)))
//		{
//
//			//consoleprint(double(i),_T("\nd"));
//
//
//			acdbGetObjectId(id,eName);
//			if (id!=AcDbObjectId::kNull)
//			{
//				if (acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite)==eOk)
//				{
//
//
//
//
//
//					if ( (Pipi = TVS_Pipe::cast(pEnt)) != NULL )
//					{	
//
//
//						///
//						if (cSizeA==false) Pipi->put_SizeA(SizeA);
//						if (cSizeB==false) Pipi->put_SizeB(SizeB);
//						if (cFlow==false) Pipi->put_Flow(Flow);
//						if (cGrani==false) Pipi->put_Grani(Grani);
//						if (cD1==false) Pipi->put_This1D(D1);
//						if (cWipe==false) Pipi->put_Wipeout(Wipe);
//						if (cElev==false) Pipi->put_Elevation(getElev(Elev,Emode,Pipi->SizeA,Pipi->SizeB));
//						//
//
//
//					}
//
//					if ( (Tapie = TVS_TAP::cast(pEnt)) != NULL )
//					{	
//
//
//						///
//						if (cSizeA==false) Tapie->put_SizeA(SizeA);
//						if (cSizeB==false) Tapie->put_SizeB(SizeB);
//						if (cFlow==false) Tapie->put_Flow(Flow);
//
//						if (cD1==false) Tapie->put_This1D(D1);
//						if (cWipe==false) Tapie->put_Wipeout(Wipe);
//						if (cElev==false) Tapie->put_Elevation(getElev(Elev,Emode,Tapie->SizeA,Tapie->SizeB));
//						//
//
//					}
//
//					if ( (Wyeie = TVS_WYE::cast(pEnt)) != NULL )
//					{	
//
//
//						///
//						if (cSizeA==false) Wyeie->put_SizeApr(SizeA);
//						if (cSizeB==false) Wyeie->put_SizeBpr(SizeB);
//						if (cSizeA2==false) Wyeie->put_SizeAotv(SizeA2);
//						if (cSizeB2==false) Wyeie->put_SizeBotv(SizeB2);
//						if (cLengthW==false) Wyeie->put_Length(LengthW);
//						//if (cFlow==false) Tapie->put_Flow(Flow);
//
//						if (cD1==false) Wyeie->put_This1D(D1);
//						if (cWipe==false) Wyeie->put_Wipeout(Wipe);
//						if (cElev==false) Wyeie->put_Elevation(getElev(Elev,Emode,Wyeie->SizeApr,Wyeie->SizeBpr));
//						//
//
//
//					}
//
//					if ( (Transie = TVS_TRANS::cast(pEnt)) != NULL )
//					{	
//						///
//						if (cSizeA==false) Transie->put_SizeAp1(SizeA);
//						if (cSizeB==false) Transie->put_SizeBp1(SizeB);
//						if (cSizeA2==false) Transie->put_SizeAp2(SizeA2);
//						if (cSizeB2==false) Transie->put_SizeBp2(SizeB2);
//						if (cLengthTr==false) Transie->put_Length(LengthTr);
//						//if (cFlow==false) Tapie->put_Flow(Flow);
//
//						if (cD1==false) Transie->put_This1D(D1);
//						if (cWipe==false) Transie->put_Wipeout(Wipe);
//						if (cElev==false) Transie->put_Elevation(getElev(Elev,Emode,Transie->SizeAp1,Transie->SizeBp1));
//						//
//
//
//
//					}
//
//
//					pEnt->close();
//				}
//			}
//		}
//
//	}
//
//}
//


void func::Change (ads_name &sset)
{



	AcDbEntity * pEnt;
	ads_name  eName;
	ACHAR  resultss [512];
	ACHAR  results1 [512]=_T("2");
	ACHAR  results2 [512]=_T("2d");

	ads_point pt1,pt2;
	ads_real sise=0;

	AcDbObjectId id;
	TVS_Pipe * Pipi;
	TVS_TAP * Tapie;
	TVS_WYE* Wyeie;
	TVS_TRANS * Transie;

	double NewSiseA;
	bool p1d;
	resbuf *rb = NULL;





	Int32 len = 0;


	//проверяем элементы и извлекаем данные
	bool firstPipe=false;
	bool firstTap=false;
	bool firstTrans=false;
	bool firstWye=false;

	bool vSizeA=false;
	bool vSizeB=false;
	bool vFlow=false;
	bool vSizeA2=false;
	bool vSizeB2=false;
	bool vLengthTr=false;
	bool vLengthW=false;
	bool vWipe=false;
	bool vGrani=false;
	bool vD1=false;
	bool vElev=false;

	bool vTapForm=false;
	bool vTypeRoundTap=false;
	bool vRadiusTypeRound=false;
	bool vRadiusTypeRect=false;
	bool vTapRadiusVariableParameter=false;
	bool vTapRadiusConst=false;
	bool vSwectangle=false;



	bool fSizeA=true;
	bool fSizeB=true;
	bool fFlow=true;
	bool fSizeA2=true;
	bool fSizeB2=true;
	bool fLengthTr=true;
	bool fLengthW=true;
	bool fWipe=true;
	bool fGrani=true;
	bool fD1=true;
	bool fElev=true;

	bool fTapForm=true;
	bool fTypeRoundTap=true;
	bool fRadiusTypeRound=true;
	bool fRadiusTypeRect=true;
	bool fTapRadiusVariableParameter=true;
	bool fTapRadiusConst=true;
	bool fSwectangle=true;


	double SizeA=0;
	double SizeB=0;
	double Flow=0;
	double SizeA2=0;
	double SizeB2=0;
	double LengthTr=0;
	double LengthW=0;
	bool Wipe=false;
	bool Grani=false;
	bool D1=false;
	double Elev=0;

	double TapForm=0;
	double TypeRoundTap=0;
	double RadiusTypeRound=0;
	double RadiusTypeRect=0;
	double TapRadiusVariableParameter=0;
	double TapRadiusConst=0;
	double Swectangle=0;


	CString sSizeA;
	CString sSizeB;
	CString sFlow;
	CString sSizeA2;
	CString sSizeB2;
	CString sLengthTr;
	CString sLengthW;
	CString sElev;

	CString sTapForm;
	CString sTypeRoundTap;
	CString sRadiusTypeRound;
	CString sRadiusTypeRect;
	CString sTapRadiusVariableParameter;
	CString sTapRadiusConst;
	CString  sSwectangle;

	BOOL sWipe;
	BOOL sGrani;
	BOOL sD1;



bool vWipeoutLength=false;
bool fWipeoutLength=true;
double WipeoutLength=0;
CString  sWipeoutLength;


bool vDuctFlex=false;
bool fDuctFlex=true;
bool DuctFlex=0;
BOOL  sDuctFlex;

TVS_Entity* tvsEnt;


acedSSLength(sset, &len);
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


					if ( (tvsEnt = TVS_Entity::cast(pEnt)) != NULL )
					{	

						

						rprov(vWipeoutLength,fWipeoutLength,tvsEnt->WipeoutLength,WipeoutLength);
					rprov(vDuctFlex,fDuctFlex,tvsEnt->isDuctFlex(),DuctFlex);


					}

					if ( (Pipi = TVS_Pipe::cast(pEnt)) != NULL )
					{	

						if (firstPipe==false) firstPipe=true;

						rprov(vSizeA,fSizeA,Pipi->SizeA,SizeA);
						rprov(vSizeB,fSizeB,Pipi->SizeB,SizeB);
						rprov(vFlow,fFlow,Pipi->Flow,Flow);
						rprov(vGrani,fGrani,Pipi->Grani,Grani);
						rprov(vD1,fD1,Pipi->This1D,D1);
						rprov(vWipe,fWipe,Pipi->Wipeout,Wipe);
						rprov(vElev,fElev,Pipi->Elev,Elev);


					}

					if ( (Tapie = TVS_TAP::cast(pEnt)) != NULL )
					{	
						if (firstTap==false) firstTap=true;

						rprov(vSizeA,fSizeA,Tapie->SizeA,SizeA);
						rprov(vSizeB,fSizeB,Tapie->SizeB,SizeB);

						rprov(vD1,fD1,Tapie->This1D,D1);
						rprov(vWipe,fWipe,Tapie->Wipeout,Wipe);
						rprov(vElev,fElev,Tapie->Elev,Elev);

						rprov(vTapForm,fTapForm,Tapie->Form,TapForm);
						rprov(vTypeRoundTap,fTypeRoundTap,Tapie->TypeRoundTap,TypeRoundTap);
						rprov(vRadiusTypeRound,fRadiusTypeRound,Tapie->RadiusTypeRound,RadiusTypeRound);
						rprov(vRadiusTypeRect,fRadiusTypeRect,Tapie->RadiusTypeRect,RadiusTypeRect);
						rprov(vTapRadiusVariableParameter,fTapRadiusVariableParameter,Tapie->RadiusVariableParameter,TapRadiusVariableParameter);
						rprov(vTapRadiusConst,fTapRadiusConst,Tapie->RadiusConst,TapRadiusConst);
						rprov(vSwectangle,fSwectangle,Tapie->Swectangle,Swectangle);



					}

					if ( (Wyeie = TVS_WYE::cast(pEnt)) != NULL )
					{	
						if (firstWye==false) firstWye=true;

						rprov(vSizeA,fSizeA,Wyeie->SizeApr,SizeA);
						rprov(vSizeB,fSizeB,Wyeie->SizeBpr,SizeB);
						rprov(vSizeA2,fSizeA2,Wyeie->SizeAotv,SizeA2);
						rprov(vSizeB2,fSizeB2,Wyeie->SizeBotv,SizeB2);
						rprov(vLengthW,fLengthW,Wyeie->LengthPl,LengthW);

						rprov(vD1,fD1,Wyeie->This1D,D1);
						rprov(vWipe,fWipe,Wyeie->Wipeout,Wipe);
						rprov(vElev,fElev,Wyeie->Elev,Elev);

					}

					if ( (Transie = TVS_TRANS::cast(pEnt)) != NULL )
					{	
						if (firstTrans==false) firstTrans=true;

						rprov(vSizeA,fSizeA,Transie->SizeAp1,SizeA);
						rprov(vSizeB,fSizeB,Transie->SizeBp1,SizeB);
						rprov(vSizeA2,fSizeA2,Transie->SizeAp2,SizeA2);
						rprov(vSizeB2,fSizeB2,Transie->SizeBp2,SizeB2);
						rprov(vLengthTr,fLengthTr,Transie->LengthTr,LengthTr);

						rprov(vD1,fD1,Transie->This1D,D1);
						rprov(vWipe,fWipe,Transie->Wipeout,Wipe);

						rprov(vElev,fElev,Transie->Elev,Elev);

					}


					pEnt->close();
				}
			}
		}
	}





	dgAllEdit dg;



	strfil(SizeA,vSizeA,sSizeA);
	strfil(SizeB,vSizeB,sSizeB);
	strfil(SizeA2,vSizeA2,sSizeA2);
	strfil(SizeB2,vSizeB2,sSizeB2);
	strfil(Flow,vFlow,sFlow);
	strfil(LengthTr,vLengthTr,sLengthTr);
	strfil(LengthW,vLengthW,sLengthW);
	strfil(Elev,vElev,sElev);
	strfil(Wipe,vWipe,sWipe);
	strfil(Grani,vGrani,sGrani);
	strfil(D1,vD1,sD1);

	strfil(TapForm,vTapForm,sTapForm);
	strfil(TypeRoundTap,vTypeRoundTap,sTypeRoundTap);
	strfil(RadiusTypeRound,vRadiusTypeRound,sRadiusTypeRound);
	strfil(RadiusTypeRect,vRadiusTypeRect,sRadiusTypeRect);
	strfil(TapRadiusVariableParameter,vTapRadiusVariableParameter,sTapRadiusVariableParameter);
	strfil(TapRadiusConst,vTapRadiusConst,sTapRadiusConst);
	strfil(Swectangle,vSwectangle,sSwectangle);





	BOOL ElevationMid=1;
	BOOL ElevationUp=0;
	BOOL ElevationDown=0;




	
	dg.SizeA=sSizeA;
	dg.SizeB=sSizeB;
	dg.SizeA2=sSizeA2;
	dg.SizeB2=sSizeB2;
	dg.Flow=sFlow;
	dg.LengthTr=sLengthTr;
	dg.LengthW=sLengthW;
	dg.Tpipe=firstPipe;
	dg.Twye=firstWye;
	dg.Ttrans=firstTrans;
	dg.Ttap=firstTap;
	dg.Wipe=sWipe;
	dg.Grani=sGrani;
	dg.D1=sD1;
	dg.ElevMid=ElevationMid;
	dg.Elev=sElev;

	dg.TapForm=sTapForm;
	dg.TypeRoundTap=sTypeRoundTap;
	dg.RadiusTypeRound=sRadiusTypeRound;
	dg.RadiusTypeRect=sRadiusTypeRect;
	dg.TapRadiusVariableParameter=sTapRadiusVariableParameter;
	dg.TapRadiusConst=sTapRadiusConst;
	dg.Swectangle=sSwectangle;


	strfil(WipeoutLength,vWipeoutLength,sWipeoutLength);
	dg.WipeoutLength=sWipeoutLength;

		strfil(DuctFlex,vDuctFlex,sDuctFlex);
	dg.DuctFlex=sDuctFlex;

	if (firstPipe==false
		&&firstTap==false
		&&firstTrans==false
		&&firstWye==false)
	{
		acutPrintf(_T("\nНичего не выбрано"));
		return;
	}
	{

		CAcModuleResourceOverride resourceOverride;
		dg.DoModal();

	}


	bool cSizeA=true;
	bool cSizeB=true;
	bool cFlow=true;
	bool cSizeA2=true;
	bool cSizeB2=true;
	bool cLengthTr=true;
	bool cLengthW=true;
	bool cWipe=true;
	bool cGrani=true;
	bool cD1=true;
	bool cElev=true;

	bool cTapForm=true;
	bool cTypeRoundTap=true;
	bool cRadiusTypeRound=true;
	bool cRadiusTypeRect=true;
	bool cTapRadiusVariableParameter=true;
	bool cTapRadiusConst=true;
	bool cSwectangle=true;



	sequal(SizeA,sSizeA,dg.SizeA,cSizeA);
	sequal(SizeB,sSizeB,dg.SizeB,cSizeB);
	sequal(Flow,sFlow,dg.Flow,cFlow);
	sequal(SizeA2,sSizeA2,dg.SizeA2,cSizeA2);
	sequal(SizeB2,sSizeB2,dg.SizeB2,cSizeB2);
	sequal(LengthTr,sLengthTr,dg.LengthTr,cLengthTr);
	sequal(LengthW,sLengthW,dg.LengthW,cLengthW);
	sequal(Elev,sElev,dg.Elev,cElev);
	sequal(Wipe,sWipe,dg.Wipe,cWipe);
	sequal(Grani,sGrani,dg.Grani,cGrani);
	sequal(D1,sD1,dg.D1,cD1);

	sequal(TapForm,sTapForm,dg.TapForm,cTapForm);
	sequal(TypeRoundTap,sTypeRoundTap,dg.TypeRoundTap,cTypeRoundTap);
	sequal(RadiusTypeRound,sRadiusTypeRound,dg.RadiusTypeRound,cRadiusTypeRound);
	sequal(RadiusTypeRect,sRadiusTypeRect,dg.RadiusTypeRect,cRadiusTypeRect);
	sequal(TapRadiusVariableParameter,sTapRadiusVariableParameter,dg.TapRadiusVariableParameter,cTapRadiusVariableParameter);
	sequal(TapRadiusConst,sTapRadiusConst,dg.TapRadiusConst,cTapRadiusConst);
	sequal(Swectangle,sSwectangle,dg.Swectangle,cSwectangle);


	bool cWipeoutLength=true;
	sequal(WipeoutLength,sWipeoutLength,dg.WipeoutLength,cWipeoutLength);

	bool cDuctFlex=true;
	sequal(DuctFlex,sDuctFlex,dg.DuctFlex,cDuctFlex);
	///определение выравнивания
	int Emode=0;//по центру
	if (dg.ElevUp==1)//по верху
	{
		Emode=1;
	}

	if (dg.ElevDown==1)//по низу
	{
		Emode=2;
	}



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




					if ( (tvsEnt = TVS_Entity::cast(pEnt)) != NULL )
					{	



						if (cWipeoutLength==false) tvsEnt->put_WipeoutLength(WipeoutLength);
							if (cDuctFlex==false) tvsEnt->setFlex(DuctFlex);


					}


					if ( (Pipi = TVS_Pipe::cast(pEnt)) != NULL )
					{	


						///
						if (cSizeA==false) Pipi->put_SizeA(SizeA);
						if (cSizeB==false) Pipi->put_SizeB(SizeB);
						if (cFlow==false) Pipi->put_Flow(Flow);
						if (cGrani==false) Pipi->put_Grani(Grani);
						if (cD1==false) Pipi->put_This1D(D1);
						if (cWipe==false) Pipi->put_Wipeout(Wipe);
						if (cElev==false) Pipi->put_Elevation(getElev(Elev,Emode,Pipi->SizeA,Pipi->SizeB));
						//


					}

					if ( (Tapie = TVS_TAP::cast(pEnt)) != NULL )
					{	


						///
						if (cSizeA==false) Tapie->put_SizeA(SizeA);
						if (cSizeB==false) Tapie->put_SizeB(SizeB);
						if (cFlow==false) Tapie->put_Flow(Flow);

						if (cD1==false) Tapie->put_This1D(D1);
						if (cWipe==false) Tapie->put_Wipeout(Wipe);
						if (cElev==false) Tapie->put_Elevation(getElev(Elev,Emode,Tapie->SizeA,Tapie->SizeB));
						//


						if (cTapForm==false) Tapie->put_Form(TapForm);
						if (cTypeRoundTap==false) Tapie->put_TypeRoundTap(TypeRoundTap);
						if (cRadiusTypeRound==false) Tapie->put_RadiusTypeRound(RadiusTypeRound);
						if (cRadiusTypeRect==false) Tapie->put_RadiusTypeRect(RadiusTypeRect);
						if (cTapRadiusVariableParameter==false) Tapie->put_RadiusVariableParameter(TapRadiusVariableParameter);
						if (cTapRadiusConst==false) Tapie->put_RadiusConst(TapRadiusConst);
						if (cSwectangle==false) Tapie->put_Swectangle(Swectangle);

					}

					if ( (Wyeie = TVS_WYE::cast(pEnt)) != NULL )
					{	


						///
						if (cSizeA==false) Wyeie->put_SizeApr(SizeA);
						if (cSizeB==false) Wyeie->put_SizeBpr(SizeB);
						if (cSizeA2==false) Wyeie->put_SizeAotv(SizeA2);
						if (cSizeB2==false) Wyeie->put_SizeBotv(SizeB2);
						if (cLengthW==false) Wyeie->put_Length(LengthW);
						//if (cFlow==false) Tapie->put_Flow(Flow);

						if (cD1==false) Wyeie->put_This1D(D1);
						if (cWipe==false) Wyeie->put_Wipeout(Wipe);
						if (cElev==false) Wyeie->put_Elevation(getElev(Elev,Emode,Wyeie->SizeApr,Wyeie->SizeBpr));
						//


					}

					if ( (Transie = TVS_TRANS::cast(pEnt)) != NULL )
					{	
						///
						if (cSizeA==false) Transie->put_SizeAp1(SizeA);
						if (cSizeB==false) Transie->put_SizeBp1(SizeB);
						if (cSizeA2==false) Transie->put_SizeAp2(SizeA2);
						if (cSizeB2==false) Transie->put_SizeBp2(SizeB2);
						if (cLengthTr==false) Transie->put_Length(LengthTr);
						//if (cFlow==false) Tapie->put_Flow(Flow);

						if (cD1==false) Transie->put_This1D(D1);
						if (cWipe==false) Transie->put_Wipeout(Wipe);
						if (cElev==false) Transie->put_Elevation(getElev(Elev,Emode,Transie->SizeAp1,Transie->SizeBp1));
						//



					}


					pEnt->close();
				}
			}
		}
	}
}



void func::Change (AcDbEntity *pEnt)
{




	ads_name  eName;
	ACHAR  resultss [512];
	ACHAR  results1 [512]=_T("2");
	ACHAR  results2 [512]=_T("2d");

	ads_point pt1,pt2;
	ads_real sise=0;

	AcDbObjectId id;
	TVS_Pipe * Pipi;
	TVS_TAP * Tapie;
	TVS_WYE* Wyeie;
	TVS_TRANS * Transie;

	double NewSiseA;
	bool p1d;
	resbuf *rb = NULL;





	long len = 0;


	//проверяем элементы и извлекаем данные
	bool firstPipe=false;
	bool firstTap=false;
	bool firstTrans=false;
	bool firstWye=false;

	bool vSizeA=false;
	bool vSizeB=false;
	bool vFlow=false;
	bool vSizeA2=false;
	bool vSizeB2=false;
	bool vLengthTr=false;
	bool vLengthW=false;
	bool vWipe=false;
	bool vGrani=false;
	bool vD1=false;
	bool vElev=false;

	bool vTapForm=false;
	bool vTypeRoundTap=false;
	bool vRadiusTypeRound=false;
	bool vRadiusTypeRect=false;
	bool vTapRadiusVariableParameter=false;
	bool vTapRadiusConst=false;
	bool vSwectangle=false;



	bool fSizeA=true;
	bool fSizeB=true;
	bool fFlow=true;
	bool fSizeA2=true;
	bool fSizeB2=true;
	bool fLengthTr=true;
	bool fLengthW=true;
	bool fWipe=true;
	bool fGrani=true;
	bool fD1=true;
	bool fElev=true;

	bool fTapForm=true;
	bool fTypeRoundTap=true;
	bool fRadiusTypeRound=true;
	bool fRadiusTypeRect=true;
	bool fTapRadiusVariableParameter=true;
	bool fTapRadiusConst=true;
	bool fSwectangle=true;


	double SizeA=0;
	double SizeB=0;
	double Flow=0;
	double SizeA2=0;
	double SizeB2=0;
	double LengthTr=0;
	double LengthW=0;
	bool Wipe=false;
	bool Grani=false;
	bool D1=false;
	double Elev=0;

	double TapForm=0;
	double TypeRoundTap=0;
	double RadiusTypeRound=0;
	double RadiusTypeRect=0;
	double TapRadiusVariableParameter=0;
	double TapRadiusConst=0;
	double Swectangle=0;


	CString sSizeA;
	CString sSizeB;
	CString sFlow;
	CString sSizeA2;
	CString sSizeB2;
	CString sLengthTr;
	CString sLengthW;
	CString sElev;

	CString sTapForm;
	CString sTypeRoundTap;
	CString sRadiusTypeRound;
	CString sRadiusTypeRect;
	CString sTapRadiusVariableParameter;
	CString sTapRadiusConst;
	CString  sSwectangle;

	BOOL sWipe;
	BOOL sGrani;
	BOOL sD1;





	bool vWipeoutLength=false;
	bool fWipeoutLength=true;
	double WipeoutLength=0;
	CString  sWipeoutLength;


	bool vDuctFlex=false;
	bool fDuctFlex=true;
	bool DuctFlex=0;
	BOOL  sDuctFlex;

	TVS_Entity* tvsEnt;

	if ( (tvsEnt = TVS_Entity::cast(pEnt)) != NULL )
	{	



		rprov(vWipeoutLength,fWipeoutLength,tvsEnt->WipeoutLength,WipeoutLength);

		rprov(vDuctFlex,fDuctFlex,tvsEnt->isDuctFlex(),DuctFlex);

	}



	if ( (Pipi = TVS_Pipe::cast(pEnt)) != NULL )
	{	

		if (firstPipe==false) firstPipe=true;

		rprov(vSizeA,fSizeA,Pipi->SizeA,SizeA);
		rprov(vSizeB,fSizeB,Pipi->SizeB,SizeB);
		rprov(vFlow,fFlow,Pipi->Flow,Flow);
		rprov(vGrani,fGrani,Pipi->Grani,Grani);
		rprov(vD1,fD1,Pipi->This1D,D1);
		rprov(vWipe,fWipe,Pipi->Wipeout,Wipe);
		rprov(vElev,fElev,Pipi->Elev,Elev);


	}

	if ( (Tapie = TVS_TAP::cast(pEnt)) != NULL )
	{	
		if (firstTap==false) firstTap=true;

		rprov(vSizeA,fSizeA,Tapie->SizeA,SizeA);
		rprov(vSizeB,fSizeB,Tapie->SizeB,SizeB);

		rprov(vD1,fD1,Tapie->This1D,D1);
		rprov(vWipe,fWipe,Tapie->Wipeout,Wipe);
		rprov(vElev,fElev,Tapie->Elev,Elev);

		rprov(vTapForm,fTapForm,Tapie->Form,TapForm);
		rprov(vTypeRoundTap,fTypeRoundTap,Tapie->TypeRoundTap,TypeRoundTap);
		rprov(vRadiusTypeRound,fRadiusTypeRound,Tapie->RadiusTypeRound,RadiusTypeRound);
		rprov(vRadiusTypeRect,fRadiusTypeRect,Tapie->RadiusTypeRect,RadiusTypeRect);
		rprov(vTapRadiusVariableParameter,fTapRadiusVariableParameter,Tapie->RadiusVariableParameter,TapRadiusVariableParameter);
		rprov(vTapRadiusConst,fTapRadiusConst,Tapie->RadiusConst,TapRadiusConst);
		rprov(vSwectangle,fSwectangle,Tapie->Swectangle,Swectangle);



	}

	if ( (Wyeie = TVS_WYE::cast(pEnt)) != NULL )
	{	
		if (firstWye==false) firstWye=true;

		rprov(vSizeA,fSizeA,Wyeie->SizeApr,SizeA);
		rprov(vSizeB,fSizeB,Wyeie->SizeBpr,SizeB);
		rprov(vSizeA2,fSizeA2,Wyeie->SizeAotv,SizeA2);
		rprov(vSizeB2,fSizeB2,Wyeie->SizeBotv,SizeB2);
		rprov(vLengthW,fLengthW,Wyeie->LengthPl,LengthW);

		rprov(vD1,fD1,Wyeie->This1D,D1);
		rprov(vWipe,fWipe,Wyeie->Wipeout,Wipe);
		rprov(vElev,fElev,Wyeie->Elev,Elev);

	}

	if ( (Transie = TVS_TRANS::cast(pEnt)) != NULL )
	{	
		if (firstTrans==false) firstTrans=true;

		rprov(vSizeA,fSizeA,Transie->SizeAp1,SizeA);
		rprov(vSizeB,fSizeB,Transie->SizeBp1,SizeB);
		rprov(vSizeA2,fSizeA2,Transie->SizeAp2,SizeA2);
		rprov(vSizeB2,fSizeB2,Transie->SizeBp2,SizeB2);
		rprov(vLengthTr,fLengthTr,Transie->LengthTr,LengthTr);

		rprov(vD1,fD1,Transie->This1D,D1);
		rprov(vWipe,fWipe,Transie->Wipeout,Wipe);

		rprov(vElev,fElev,Transie->Elev,Elev);

	}










	dgAllEdit dg;


	strfil(SizeA,vSizeA,sSizeA);
	strfil(SizeB,vSizeB,sSizeB);
	strfil(SizeA2,vSizeA2,sSizeA2);
	strfil(SizeB2,vSizeB2,sSizeB2);
	strfil(Flow,vFlow,sFlow);
	strfil(LengthTr,vLengthTr,sLengthTr);
	strfil(LengthW,vLengthW,sLengthW);
	strfil(Elev,vElev,sElev);
	strfil(Wipe,vWipe,sWipe);
	strfil(Grani,vGrani,sGrani);
	strfil(D1,vD1,sD1);

	strfil(TapForm,vTapForm,sTapForm);
	strfil(TypeRoundTap,vTypeRoundTap,sTypeRoundTap);
	strfil(RadiusTypeRound,vRadiusTypeRound,sRadiusTypeRound);
	strfil(RadiusTypeRect,vRadiusTypeRect,sRadiusTypeRect);
	strfil(TapRadiusVariableParameter,vTapRadiusVariableParameter,sTapRadiusVariableParameter);
	strfil(TapRadiusConst,vTapRadiusConst,sTapRadiusConst);
	strfil(Swectangle,vSwectangle,sSwectangle);





	BOOL ElevationMid=1;
	BOOL ElevationUp=0;
	BOOL ElevationDown=0;




	
	dg.SizeA=sSizeA;
	dg.SizeB=sSizeB;
	dg.SizeA2=sSizeA2;
	dg.SizeB2=sSizeB2;
	dg.Flow=sFlow;
	dg.LengthTr=sLengthTr;
	dg.LengthW=sLengthW;
	dg.Tpipe=firstPipe;
	dg.Twye=firstWye;
	dg.Ttrans=firstTrans;
	dg.Ttap=firstTap;
	dg.Wipe=sWipe;
	dg.Grani=sGrani;
	dg.D1=sD1;
	dg.ElevMid=ElevationMid;
	dg.Elev=sElev;

	dg.TapForm=sTapForm;
	dg.TypeRoundTap=sTypeRoundTap;
	dg.RadiusTypeRound=sRadiusTypeRound;
	dg.RadiusTypeRect=sRadiusTypeRect;
	dg.TapRadiusVariableParameter=sTapRadiusVariableParameter;
	dg.TapRadiusConst=sTapRadiusConst;
	dg.Swectangle=sSwectangle;

	strfil(WipeoutLength,vWipeoutLength,sWipeoutLength);
	dg.WipeoutLength=sWipeoutLength;

	strfil(DuctFlex,vDuctFlex,sDuctFlex);
	dg.DuctFlex=sDuctFlex;

	if (firstPipe==false
		&&firstTap==false
		&&firstTrans==false
		&&firstWye==false)
	{
		acutPrintf(_T("\nНичего не выбрано"));
		return;
	}
	{

		CAcModuleResourceOverride resourceOverride;
		dg.DoModal();

	}


	bool cSizeA=true;
	bool cSizeB=true;
	bool cFlow=true;
	bool cSizeA2=true;
	bool cSizeB2=true;
	bool cLengthTr=true;
	bool cLengthW=true;
	bool cWipe=true;
	bool cGrani=true;
	bool cD1=true;
	bool cElev=true;

	bool cTapForm=true;
	bool cTypeRoundTap=true;
	bool cRadiusTypeRound=true;
	bool cRadiusTypeRect=true;
	bool cTapRadiusVariableParameter=true;
	bool cTapRadiusConst=true;
	bool cSwectangle=true;



	sequal(SizeA,sSizeA,dg.SizeA,cSizeA);
	sequal(SizeB,sSizeB,dg.SizeB,cSizeB);
	sequal(Flow,sFlow,dg.Flow,cFlow);
	sequal(SizeA2,sSizeA2,dg.SizeA2,cSizeA2);
	sequal(SizeB2,sSizeB2,dg.SizeB2,cSizeB2);
	sequal(LengthTr,sLengthTr,dg.LengthTr,cLengthTr);
	sequal(LengthW,sLengthW,dg.LengthW,cLengthW);
	sequal(Elev,sElev,dg.Elev,cElev);
	sequal(Wipe,sWipe,dg.Wipe,cWipe);
	sequal(Grani,sGrani,dg.Grani,cGrani);
	sequal(D1,sD1,dg.D1,cD1);

	sequal(TapForm,sTapForm,dg.TapForm,cTapForm);
	sequal(TypeRoundTap,sTypeRoundTap,dg.TypeRoundTap,cTypeRoundTap);
	sequal(RadiusTypeRound,sRadiusTypeRound,dg.RadiusTypeRound,cRadiusTypeRound);
	sequal(RadiusTypeRect,sRadiusTypeRect,dg.RadiusTypeRect,cRadiusTypeRect);
	sequal(TapRadiusVariableParameter,sTapRadiusVariableParameter,dg.TapRadiusVariableParameter,cTapRadiusVariableParameter);
	sequal(TapRadiusConst,sTapRadiusConst,dg.TapRadiusConst,cTapRadiusConst);
	sequal(Swectangle,sSwectangle,dg.Swectangle,cSwectangle);

	///определение выравнивания
	int Emode=0;//по центру
	if (dg.ElevUp==1)//по верху
	{
		Emode=1;
	}

	if (dg.ElevDown==1)//по низу
	{
		Emode=2;
	}



	bool cWipeoutLength=true;
	sequal(WipeoutLength,sWipeoutLength,dg.WipeoutLength,cWipeoutLength);

	bool cDuctFlex=true;
	sequal(DuctFlex,sDuctFlex,dg.DuctFlex,cDuctFlex);


	if(pEnt->upgradeOpen()==Acad::eOk)
	{



		if ( (tvsEnt = TVS_Entity::cast(pEnt)) != NULL )
		{	



			if (cWipeoutLength==false) tvsEnt->put_WipeoutLength(WipeoutLength);

			if (cDuctFlex==false) tvsEnt->setFlex(DuctFlex);

		}



		if ( (Pipi = TVS_Pipe::cast(pEnt)) != NULL )
		{	


			///
			if (cSizeA==false) Pipi->put_SizeA(SizeA);
			if (cSizeB==false) Pipi->put_SizeB(SizeB);
			if (cFlow==false) Pipi->put_Flow(Flow);
			if (cGrani==false) Pipi->put_Grani(Grani);
			if (cD1==false) Pipi->put_This1D(D1);
			if (cWipe==false) Pipi->put_Wipeout(Wipe);
			if (cElev==false) Pipi->put_Elevation(getElev(Elev,Emode,Pipi->SizeA,Pipi->SizeB));
			//


		}

		if ( (Tapie = TVS_TAP::cast(pEnt)) != NULL )
		{	


			///
			if (cSizeA==false) Tapie->put_SizeA(SizeA);
			if (cSizeB==false) Tapie->put_SizeB(SizeB);
			if (cFlow==false) Tapie->put_Flow(Flow);

			if (cD1==false) Tapie->put_This1D(D1);
			if (cWipe==false) Tapie->put_Wipeout(Wipe);
			if (cElev==false) Tapie->put_Elevation(getElev(Elev,Emode,Tapie->SizeA,Tapie->SizeB));
			//


			if (cTapForm==false) Tapie->put_Form(TapForm);
			if (cTypeRoundTap==false) Tapie->put_TypeRoundTap(TypeRoundTap);
			if (cRadiusTypeRound==false) Tapie->put_RadiusTypeRound(RadiusTypeRound);
			if (cRadiusTypeRect==false) Tapie->put_RadiusTypeRect(RadiusTypeRect);
			if (cTapRadiusVariableParameter==false) Tapie->put_RadiusVariableParameter(TapRadiusVariableParameter);
			if (cTapRadiusConst==false) Tapie->put_RadiusConst(TapRadiusConst);
			if (cSwectangle==false) Tapie->put_Swectangle(Swectangle);

		}

		if ( (Wyeie = TVS_WYE::cast(pEnt)) != NULL )
		{	


			///
			if (cSizeA==false) Wyeie->put_SizeApr(SizeA);
			if (cSizeB==false) Wyeie->put_SizeBpr(SizeB);
			if (cSizeA2==false) Wyeie->put_SizeAotv(SizeA2);
			if (cSizeB2==false) Wyeie->put_SizeBotv(SizeB2);
			if (cLengthW==false) Wyeie->put_Length(LengthW);
			//if (cFlow==false) Tapie->put_Flow(Flow);

			if (cD1==false) Wyeie->put_This1D(D1);
			if (cWipe==false) Wyeie->put_Wipeout(Wipe);
			if (cElev==false) Wyeie->put_Elevation(getElev(Elev,Emode,Wyeie->SizeApr,Wyeie->SizeBpr));
			//


		}

		if ( (Transie = TVS_TRANS::cast(pEnt)) != NULL )
		{	
			///
			if (cSizeA==false) Transie->put_SizeAp1(SizeA);
			if (cSizeB==false) Transie->put_SizeBp1(SizeB);
			if (cSizeA2==false) Transie->put_SizeAp2(SizeA2);
			if (cSizeB2==false) Transie->put_SizeBp2(SizeB2);
			if (cLengthTr==false) Transie->put_Length(LengthTr);
			//if (cFlow==false) Tapie->put_Flow(Flow);

			if (cD1==false) Transie->put_This1D(D1);
			if (cWipe==false) Transie->put_Wipeout(Wipe);
			if (cElev==false) Transie->put_Elevation(getElev(Elev,Emode,Transie->SizeAp1,Transie->SizeBp1));
			//



		}


		pEnt->close();
	}
}




//void func::Change (AcDbEntity *pEnt)
//{
//
//
//	ads_name  eName,sset;
//	ACHAR  resultss [512];
//	ACHAR  results1 [512]=_T("2");
//	ACHAR  results2 [512]=_T("2d");
//
//	ads_point pt1,pt2;
//	ads_real sise=0;
//	//AcDbEntity *pEnt = NULL;
//	AcDbObjectId id;
//	TVS_Pipe * Pipi;
//	TVS_TAP * Tapie;
//	TVS_WYE* Wyeie;
//	TVS_TRANS * Transie;
//
//	double NewSiseA;
//	bool p1d;
//	resbuf *rb = NULL;
//
//
//
//
//
//	long len = 0;
//
//	acedSSLength(sset, &len);
//	//проверяем элементы и извлекаем данные
//	bool firstPipe=false;
//	bool firstTap=false;
//	bool firstTrans=false;
//	bool firstWye=false;
//
//	bool vSizeA=false;
//	bool vSizeB=false;
//	bool vFlow=false;
//	bool vSizeA2=false;
//	bool vSizeB2=false;
//	bool vLengthTr=false;
//	bool vLengthW=false;
//	bool vWipe=false;
//	bool vGrani=false;
//	bool vD1=false;
//	bool vElev=false;
//	
//
//
//	bool fSizeA=true;
//	bool fSizeB=true;
//	bool fFlow=true;
//	bool fSizeA2=true;
//	bool fSizeB2=true;
//	bool fLengthTr=true;
//	bool fLengthW=true;
//	bool fWipe=true;
//	bool fGrani=true;
//	bool fD1=true;
//	bool fElev=true;
//
//
//	double SizeA=0;
//	double SizeB=0;
//	double Flow=0;
//	double SizeA2=0;
//	double SizeB2=0;
//	double LengthTr=0;
//	double LengthW=0;
//	bool Wipe=false;
//	bool Grani=false;
//	bool D1=false;
//	double Elev=0;
//
//
//	CString sSizeA;
//	CString sSizeB;
//	CString sFlow;
//	CString sSizeA2;
//	CString sSizeB2;
//	CString sLengthTr;
//	CString sLengthW;
//	CString sElev;
//
//	
//			
//
//			
//				
//
//
//					if ( (Pipi = TVS_Pipe::cast(pEnt)) != NULL )
//					{	
//
//						if (firstPipe==false) firstPipe=true;
//
//						rprov(vSizeA,fSizeA,Pipi->SizeA,SizeA);
//						rprov(vSizeB,fSizeB,Pipi->SizeB,SizeB);
//						rprov(vFlow,fFlow,Pipi->Flow,Flow);
//						rprov(vGrani,fGrani,Pipi->Grani,Grani);
//						rprov(vD1,fD1,Pipi->This1D,D1);
//						rprov(vWipe,fWipe,Pipi->Wipeout,Wipe);
//						rprov(vElev,fElev,Pipi->Elev,Elev);
//
//
//					}
//
//					if ( (Tapie = TVS_TAP::cast(pEnt)) != NULL )
//					{	
//						if (firstTap==false) firstTap=true;
//
//						rprov(vSizeA,fSizeA,Tapie->SizeA,SizeA);
//						rprov(vSizeB,fSizeB,Tapie->SizeB,SizeB);
//
//						rprov(vD1,fD1,Tapie->This1D,D1);
//						rprov(vWipe,fWipe,Tapie->Wipeout,Wipe);
//						rprov(vElev,fElev,Tapie->Elev,Elev);
//
//					}
//
//					if ( (Wyeie = TVS_WYE::cast(pEnt)) != NULL )
//					{	
//						if (firstWye==false) firstWye=true;
//
//						rprov(vSizeA,fSizeA,Wyeie->SizeApr,SizeA);
//						rprov(vSizeB,fSizeB,Wyeie->SizeBpr,SizeB);
//						rprov(vSizeA2,fSizeA2,Wyeie->SizeAotv,SizeA2);
//						rprov(vSizeB2,fSizeB2,Wyeie->SizeBotv,SizeB2);
//						rprov(vLengthW,fLengthW,Wyeie->LengthPl,LengthW);
//
//						rprov(vD1,fD1,Wyeie->This1D,D1);
//						rprov(vWipe,fWipe,Wyeie->Wipeout,Wipe);
//						rprov(vElev,fElev,Wyeie->Elev,Elev);
//
//					}
//
//					if ( (Transie = TVS_TRANS::cast(pEnt)) != NULL )
//					{	
//						if (firstTrans==false) firstTrans=true;
//
//						rprov(vSizeA,fSizeA,Transie->SizeAp1,SizeA);
//						rprov(vSizeB,fSizeB,Transie->SizeBp1,SizeB);
//						rprov(vSizeA2,fSizeA2,Transie->SizeAp2,SizeA2);
//						rprov(vSizeB2,fSizeB2,Transie->SizeBp2,SizeB2);
//						rprov(vLengthTr,fLengthTr,Transie->LengthTr,LengthTr);
//
//						rprov(vD1,fD1,Transie->This1D,D1);
//						rprov(vWipe,fWipe,Transie->Wipeout,Wipe);
//
//						rprov(vElev,fElev,Transie->Elev,Elev);
//
//					}
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
//
//	
//
//	strfil(SizeA,vSizeA,sSizeA);
//	strfil(SizeB,vSizeB,sSizeB);
//	strfil(SizeA2,vSizeA2,sSizeA2);
//	strfil(SizeB2,vSizeB2,sSizeB2);
//	strfil(Flow,vFlow,sFlow);
//	strfil(LengthTr,vLengthTr,sLengthTr);
//	strfil(LengthW,vLengthW,sLengthW);
//	strfil(Elev,vElev,sElev);
//
//	BOOL GraniOn=false;
//	BOOL GraniOff=false;
//	BOOL D1On=false;
//	BOOL D1Off=false;
//	BOOL WipeOn=false;
//	BOOL WipeOff=false;
//	BOOL mid=true;
//	BOOL up=false;
//	BOOL down=false;
//
//
//	if (fWipe==false)
//	{
//		if (vWipe==false)
//		{
//			if (Wipe==false)WipeOff=true;
//			else WipeOn=true;
//		}
//	}
//
//	if (fD1==false)
//	{
//		if (vD1==false)
//		{
//			if (D1==false)D1Off=true;
//			else D1On=true;
//		}
//	}
//
//	if (fGrani==false)
//	{
//		if (vGrani==false)
//		{
//			if (Grani==false)GraniOff=true;
//			else GraniOn=true;
//		}
//	}
//
//
//	dgAllEdit dg;
//	dg.SizeA=sSizeA;
//	dg.SizeB=sSizeB;
//	dg.SizeA2=sSizeA2;
//	dg.SizeB2=sSizeB2;
//	dg.Flow=sFlow;
//	dg.LengthTr=sLengthTr;
//	dg.LengthW=sLengthW;
//	dg.Tpipe=firstPipe;
//	dg.Twye=firstWye;
//	dg.Ttrans=firstTrans;
//	dg.Ttap=firstTap;
//	dg.WipeOn=WipeOn;
//	dg.WipeOff=WipeOff;
//	dg.GraniOn=GraniOn;
//	dg.GraniOff=GraniOff;
//	dg.D1On=D1On;
//	dg.D1Off=D1Off;
//	dg.MidE=mid;
//	dg.Elev=sElev;
//
//	if (firstPipe==false
//		&&firstTap==false
//		&&firstTrans==false
//		&&firstWye==false)
//	{
//		acutPrintf(_T("\nНичего не выбрано"));
//		return;
//	}
//	{
//
//	CAcModuleResourceOverride resourceOverride;
//	dg.DoModal();
//	 
//	}
//
//
//	bool cSizeA=true;
//	bool cSizeB=true;
//	bool cFlow=true;
//	bool cSizeA2=true;
//	bool cSizeB2=true;
//	bool cLengthTr=true;
//	bool cLengthW=true;
//	bool cWipe=true;
//	bool cGrani=true;
//	bool cD1=true;
//	bool cElev=true;
//
//	sequal(SizeA,sSizeA,dg.SizeA,cSizeA);
//	sequal(SizeB,sSizeB,dg.SizeB,cSizeB);
//	sequal(Flow,sFlow,dg.Flow,cFlow);
//	sequal(SizeA2,sSizeA2,dg.SizeA2,cSizeA2);
//	sequal(SizeB2,sSizeB2,dg.SizeB2,cSizeB2);
//	sequal(LengthTr,sLengthTr,dg.LengthTr,cLengthTr);
//	sequal(LengthW,sLengthW,dg.LengthW,cLengthW);
//	sequal(Elev,sElev,dg.Elev,cElev);
//
//	if ((WipeOn==dg.WipeOn)&&(WipeOff==dg.WipeOff))
//	{
//		cWipe=true;
//	}
//
//	else
//	{
//		Wipe=dg.WipeOn;
//		cWipe=false;
//	}
//
//	if ((GraniOn==dg.GraniOn)&&(GraniOff==dg.GraniOff))
//	{
//		cGrani=true;
//	}
//
//	else
//	{
//		Grani=dg.GraniOn;
//		cGrani=false;
//	}
//
//	if ((D1On==dg.D1On)&&(D1Off==dg.D1Off))
//	{
//		cD1=true;
//	}
//
//	else
//	{
//		D1=dg.D1On;
//		cD1=false;
//	}
//
//
/////определение выравнивания
//	int Emode=0;//по центру
//if (dg.Up==1)//по верху
//{
//Emode=1;
//}
//
//if (dg.Down==1)//по низу
//{
//	Emode=2;
//}
//
//	/////присваивание
//
//	if(pEnt->upgradeOpen()==Acad::eOk)
//	{
//				
//
//
//					if ( (Pipi = TVS_Pipe::cast(pEnt)) != NULL )
//					{	
//
//
//						///
//						if (cSizeA==false) Pipi->put_SizeA(SizeA);
//						if (cSizeB==false) Pipi->put_SizeB(SizeB);
//						if (cFlow==false) Pipi->put_Flow(Flow);
//						if (cGrani==false) Pipi->put_Grani(Grani);
//						if (cD1==false) Pipi->put_This1D(D1);
//						if (cWipe==false) Pipi->put_Wipeout(Wipe);
//if (cElev==false) Pipi->put_Elevation(getElev(Elev,Emode,Pipi->SizeA,Pipi->SizeB));
//						//
//
//
//					}
//
//					if ( (Tapie = TVS_TAP::cast(pEnt)) != NULL )
//					{	
//
//
//						///
//						if (cSizeA==false) Tapie->put_SizeA(SizeA);
//						if (cSizeB==false) Tapie->put_SizeB(SizeB);
//						if (cFlow==false) Tapie->put_Flow(Flow);
//
//						if (cD1==false) Tapie->put_This1D(D1);
//						if (cWipe==false) Tapie->put_Wipeout(Wipe);
//if (cElev==false) Tapie->put_Elevation(getElev(Elev,Emode,Tapie->SizeA,Tapie->SizeB));
//						//
//
//					}
//
//					if ( (Wyeie = TVS_WYE::cast(pEnt)) != NULL )
//					{	
//
//
//						///
//						if (cSizeA==false) Wyeie->put_SizeApr(SizeA);
//						if (cSizeB==false) Wyeie->put_SizeBpr(SizeB);
//						if (cSizeA2==false) Wyeie->put_SizeAotv(SizeA2);
//						if (cSizeB2==false) Wyeie->put_SizeBotv(SizeB2);
//						if (cLengthW==false) Wyeie->put_Length(LengthW);
//						//if (cFlow==false) Tapie->put_Flow(Flow);
//
//						if (cD1==false) Wyeie->put_This1D(D1);
//						if (cWipe==false) Wyeie->put_Wipeout(Wipe);
//if (cElev==false) Wyeie->put_Elevation(getElev(Elev,Emode,Wyeie->SizeApr,Wyeie->SizeBpr));
//						//
//
//
//					}
//
//					if ( (Transie = TVS_TRANS::cast(pEnt)) != NULL )
//					{	
//						///
//						if (cSizeA==false) Transie->put_SizeAp1(SizeA);
//						if (cSizeB==false) Transie->put_SizeBp1(SizeB);
//						if (cSizeA2==false) Transie->put_SizeAp2(SizeA2);
//						if (cSizeB2==false) Transie->put_SizeBp2(SizeB2);
//						if (cLengthTr==false) Transie->put_Length(LengthTr);
//						//if (cFlow==false) Tapie->put_Flow(Flow);
//
//						if (cD1==false) Transie->put_This1D(D1);
//						if (cWipe==false) Transie->put_Wipeout(Wipe);
//if (cElev==false) Transie->put_Elevation(getElev(Elev,Emode,Transie->SizeAp1,Transie->SizeBp1));
//						//
//
//
//
//					}
//
//
//					pEnt->close();
//				}
//
//	
//}


void func::rprov (bool &variableconst, 
				  bool &firstvariable,
				  double &objectvar,
				  double &myvar)

{


	if (objectvar!=myvar) 
	{
		if (firstvariable==true)
		{
			myvar=objectvar;
		}
		else variableconst=true;
	}

	firstvariable=false;

}

void func::rprov (bool &variableconst, 
				  bool &firstvariable,
				  int &objectvar,
				  int &myvar)

{


	if (objectvar!=myvar) 
	{
		if (firstvariable==true)
		{
			myvar=objectvar;
		}
		else variableconst=true;
	}

	firstvariable=false;

}


void func::rprov (bool &variableconst, 
				  bool &firstvariable,
				  const bool  &objectvar,
				  bool &myvar)

{


	if (objectvar!=myvar) 
		if (objectvar!=myvar) 
		{
			if (firstvariable==true)
			{
				myvar=objectvar;
			}
			else variableconst=true;
		}

		firstvariable=false;

}

void func::getdouble( CString &svar, double dvar )
{
	svar.Format(L"%.2f", dvar);
}
void func::getint( CString &svar, int dvar )
{
	svar.Format(L"%d", dvar);
}

void func::strfil (double &myvar,
				   bool &variableconst,
				   CString &stringconst
				   )
{
	if (variableconst==true)
		stringconst=CString("Разные");
	else 
	{
		double pnum=myvar;
		CString stringvar;
		getdouble(stringvar,pnum);
		 int y = (int)pnum;
		if ((pnum-y)==0)
		{
			getint(stringconst,myvar);
			double g =1;
		
		}
		else stringconst.Format(L"%.2f\n", myvar);
	}
		
	double g =1;
}

void func::strfil (int &myvar,
				   bool &variableconst,
				   CString &stringconst
				   )
{
	if (variableconst==true)
		stringconst=CString("Разные");
	else stringconst.Format(L"%i", myvar);

}

void func::strfil (bool &myvar,
				   bool &variableconst,
				   BOOL &stringconst
				   )
{
	if (variableconst==true)
		stringconst=2;
	else stringconst=myvar;

}

void func::sequal(double &var,
				  CString &Svar1,//начальный
				  CString &Svar2,//конечный
				  bool &equ
				  )
{

	CString s;
	const wchar_t *wch;
	char *ch;
	int z;
	size_t sizeb,
		cnv;
	wch=Svar2.GetBuffer();
	sizeb=(Svar2.GetLength()+1)*2;
	ch=new char[sizeb];
	wcstombs_s(&cnv,ch,sizeb,wch,sizeb);
	double dbl=atof(ch);


	delete[] ch;


	if (Svar1==Svar2)
	{
		equ=true;

	}

	else
	{
		var=dbl;
		equ=false;
	}


}

void func::sequal(int &var,
				  CString &Svar1,//начальный
				  CString &Svar2,//конечный
				  bool &equ
				  )
{

	CString s;
	const wchar_t *wch;
	char *ch;
	int z;
	size_t sizeb,
		cnv;
	wch=Svar2.GetBuffer();
	sizeb=(Svar2.GetLength()+1)*2;
	ch=new char[sizeb];
	wcstombs_s(&cnv,ch,sizeb,wch,sizeb);
	int dbl=atoi(ch);


	delete[] ch;


	if (Svar1==Svar2)
	{
		equ=true;

	}

	else
	{
		var=dbl;
		equ=false;
	}


}

void func::sequal(bool &var,
				  BOOL &Svar1,
				  BOOL &Svar2,
				  bool &equ
				  )
{




	if (Svar1==Svar2)
	{
		equ=true;

	}

	else
	{
		var=Svar2;
		equ=false;
	}


}



void func::PostToModelSpace(AcDbEntity *pEnt)

{
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

}


// 
// void func::SetGlobalProperty( TVS_Entity *pEnt )
// {
// 
// 	TVS_Pipe * Pipi;
// 	TVS_TAP * Tapie;
// 	TVS_WYE* Wyeie;
// 	TVS_TRANS * Transie;
// 
// 
// 	if(pEnt->upgradeOpen()==Acad::eOk)
// 	{
// 
// 		pEnt->SizeA=globSizeA;
// 		pEnt->put_SizeB(globSizeB);
// 		pEnt->Wipeout=globalWipeout;
// 		pEnt->Grani=globalGrani;
// 		pEnt->This1D=global1D;
// 		pEnt->Flow=globalFlow;
// 		pEnt->put_Elevation(globalElevMid);
// 
// 
// 
// 
// 
// 
// 		if ( (Pipi = TVS_Pipe::cast(pEnt)) != NULL )
// 		{	
// 
// 
// 			// 			///
// 			// 			if (cSizeA==false) Pipi->put_SizeA(SizeA);
// 			// 			if (cSizeB==false) Pipi->put_SizeB(SizeB);
// 			// 			if (cFlow==false) Pipi->put_Flow(Flow);
// 			// 			if (cGrani==false) Pipi->put_Grani(Grani);
// 			// 			if (cD1==false) Pipi->put_This1D(D1);
// 			// 			if (cWipe==false) Pipi->put_Wipeout(Wipe);
// 			// 			if (cElev==false) Pipi->put_Elevation(getElev(Elev,Emode,Pipi->SizeA,Pipi->SizeB));
// 			//
// 
// 
// 		}
// 
// 		if ( (Tapie = TVS_TAP::cast(pEnt)) != NULL )
// 		{	
// 
// 
// 			// 			///
// 			// 			if (cSizeA==false) Tapie->put_SizeA(SizeA);
// 			// 			if (cSizeB==false) Tapie->put_SizeB(SizeB);
// 			// 			if (cFlow==false) Tapie->put_Flow(Flow);
// 			// 
// 			// 			if (cD1==false) Tapie->put_This1D(D1);
// 			// 			if (cWipe==false) Tapie->put_Wipeout(Wipe);
// 			// 			if (cElev==false) Tapie->put_Elevation(getElev(Elev,Emode,Tapie->SizeA,Tapie->SizeB));
// 			// 			//
// 			// 
// 			// 
// 			// 			if (cTapForm==false) Tapie->put_Form(TapForm);
//  			 			Tapie->put_TypeRoundTap(globalTypeRoundTap);
//  			 			Tapie->put_RadiusTypeRound(globalRadiusTypeRound);
//  			 			Tapie->put_RadiusTypeRect(globalRadiusTypeRect);
//  			 			Tapie->put_RadiusVariableParameter(globalTapRadiusVariableParameter);
//  			 			Tapie->put_RadiusConst(globalTapRadiusConst);
// 			// 			if (cSwectangle==false) Tapie->put_Swectangle(Swectangle);
// 
// 		}
// 
// 		if ( (Wyeie = TVS_WYE::cast(pEnt)) != NULL )
// 		{	
// 
// 
// 			// 			///
// 			// 			if (cSizeA==false) Wyeie->put_SizeApr(SizeA);
// 			// 			if (cSizeB==false) Wyeie->put_SizeBpr(SizeB);
// 			// 			if (cSizeA2==false) Wyeie->put_SizeAotv(SizeA2);
// 			// 			if (cSizeB2==false) Wyeie->put_SizeBotv(SizeB2);
// 			// 			if (cLengthW==false) Wyeie->put_Length(LengthW);
// 			// 			//if (cFlow==false) Tapie->put_Flow(Flow);
// 			// 
// 			// 			if (cD1==false) Wyeie->put_This1D(D1);
// 			// 			if (cWipe==false) Wyeie->put_Wipeout(Wipe);
// 			// 			if (cElev==false) Wyeie->put_Elevation(getElev(Elev,Emode,Wyeie->SizeApr,Wyeie->SizeBpr));
// 			// 			//
// 
// 
// 		}
// 
// 		if ( (Transie = TVS_TRANS::cast(pEnt)) != NULL )
// 		{	
// 			// 			///
// 			// 			if (cSizeA==false) Transie->put_SizeAp1(SizeA);
// 			// 			if (cSizeB==false) Transie->put_SizeBp1(SizeB);
// 			// 			if (cSizeA2==false) Transie->put_SizeAp2(SizeA2);
// 			// 			if (cSizeB2==false) Transie->put_SizeBp2(SizeB2);
// 			// 			if (cLengthTr==false) Transie->put_Length(LengthTr);
// 			// 			//if (cFlow==false) Tapie->put_Flow(Flow);
// 			// 
// 			// 			if (cD1==false) Transie->put_This1D(D1);
// 			// 			if (cWipe==false) Transie->put_Wipeout(Wipe);
// 			// 			if (cElev==false) Transie->put_Elevation(getElev(Elev,Emode,Transie->SizeAp1,Transie->SizeBp1));
// 			// 			//
// 
// 
// 
// 		}
// 
// 		pEnt->draw();
// 		pEnt->close();
// 		
// 	}
// 
// 
// }

double func::getElev(double &Elev,
					 int &EMode,
					 double &SizeA,
					 double &SizeB
					 )

{

	if (EMode==0)
	{
		return (Elev);
	}
	double b, res;
	if (SizeB==0)
	{
		b=SizeA;
	} 
	else
	{
		b=SizeB;
	}


	if (EMode==1)
	{
		res=Elev-b/2;
		return (res);
	}

	else
	{
		res=Elev+b/2;
		return (res);
	}


}

TVS_TAP* func::drawTapDirect(AcGePoint3d t1, AcGePoint3d t2, AcGePoint3d t3)
{



	double pSizeA=globSizeA;
	double pSizeB=globSizeB;
	double pRadius=globalTapRadiusConst;
	AcGeVector3d pNormVect;
	AcGeVector3d pStartVect;
	AcGePoint3d pMidPoint;
	double pSwectangle;
	bool pThisRound=globRound;

	pMidPoint=t2;
	GiveStartvectorAndAngle(t1,t2,t3,pSwectangle,pStartVect);
	pStartVect.normalize();
	pNormVect=AcGeVector3d(0,0,1);
	TVS_TAP* pEnt=TVS_TAP::add_new(pSizeA,pSizeB,pRadius,pNormVect,pStartVect,pMidPoint,pSwectangle,false,pThisRound);
	AcDbObjectId	id=pEnt->id();
	ads_name eName;


	acdbGetAdsName(eName,id);
	acdbGetObjectId(id,eName);
	AcDbEntity* pnt;
	acdbOpenAcDbEntity(pnt,id,AcDb::kForWrite);

	pEnt->assertWriteEnabled();
	pEnt->RadiusConst=(globalTapRadiusConst);
	pEnt->RadiusTypeRound=(globalRadiusTypeRound);
	pEnt->RadiusTypeRect=(globalRadiusTypeRect);
	pEnt->TypeRoundTap=(globalTypeRoundTap);
	pEnt->Form=(globalTapForm);
	pEnt->RadiusVariableParameter=(globalTapRadiusVariableParameter);
	pEnt->RadiusConst=(globalTapRadiusConst);
	pEnt->close();
	pEnt->draw();
	return pEnt;
}






void func::GiveStartvectorAndAngle (AcGePoint3d &n1,
									AcGePoint3d &n2,
									AcGePoint3d &n3,
									double &pAngle,
									AcGeVector3d &pStartvector)
{


	AcGePoint3d R1,R2,R3,R4,
		B1,B2,B3,B4,
		S1,S2,F1,F2,midp,
		Norm1,Norm2;
	double pRadius=10;

	AcGeVector3d finishvector;
	fourpoints(n1,n2,R1,R2,B2,B1,pRadius);
	fourpoints(n2,n3,R3,R4,B4,B3,pRadius);

	if(intersection(R1,R2,R3,R4,midp)==true)
	{
		//acutPrintf(_T("\n1"));
		S1=R2; F1=B2; 
		S2=R3; F2=B3;
	}

	if(intersection(B1,B2,B3,B4,midp)==true)
	{
		//acutPrintf(_T("\n4"));
		S1=B2; F1=R2; 
		S2=B3; F2=R3;
	}


	Norm1=AcGePoint3d(F1.x-S1.x,
		F1.y-S1.y,
		0);
	Norm2=AcGePoint3d(F2.x-S2.x,
		F2.y-S2.y,
		0);
	//consoleprint(Norm1,_T("\nПервая точка"));
	//consoleprint(Norm2,_T("\nВторая точка"));
	pStartvector=AcGeVector3d(Norm1.x,Norm1.y,0);
	finishvector=AcGeVector3d(Norm2.x,Norm2.y,0);

	pAngle=angle(Norm1,Norm2);

	//consoleprint(pAngle,_T("\nУгол"));
	Givestartvector(pStartvector,finishvector,pAngle);
	//pStartvector.normalize();
	midp=n2;
	//consoleprint(pAngle,_T("\nУгол"));







	// 	AcGeVector3d pfinishvector;
	// 	pfinishvector=AcGeVector3d(n3.x-n2.x,n3.y-n2.y,n3.z-n2.z);
	// 	pStartvector=AcGeVector3d(n2.x-n1.x,n2.y-n1.y,n2.z-n1.z);
	// 	midp=n2;
	// 	
	// 	pfinishvector.normalize();
	// 	pStartvector.normalize();
	// 	pAngle=pStartvector.angleTo(pfinishvector);



}





//void func::changesize ()
//{
//
//	ads_real sa,sb;
//
//	if (acedGetReal(_T("\nВведите Ширину:"),&sa) != RTNORM)
//	{
//		return;}
//	
//	if (acedGetReal(_T("\nВведите Высоту:"),&sb) != RTNORM)
//	{
//		return;}
//	globSizeA=sa;
//	globSizeB=sb;
//if (globSizeB==0) globRound=true;
//else globRound=false;
//}

//void func::nextpipe(AcGePoint3d &A1,
//			  AcGePoint3d &A2,
//			  AcGePoint3d &A3,
//			  TVS_Pipe *pipi
//			  )
//{
//	acutPrintf(_T("Чурчу се ок"));
//}


int func::TVSClassCheck (AcDbEntity* pEnt)
{
	if (acdbOpenAcDbEntity(pEnt,pEnt->id(),AcDb::kForWrite)==eOk){
		if ( (pEnt = TVS_Pipe::cast(pEnt)) != NULL )
		{
			pEnt->close();
			return isTVS_Pipe;
		}
		if ( (pEnt = TVS_TAP::cast(pEnt)) != NULL )
		{
			pEnt->close();
			return isTVS_TAP;
		}
		if ( (pEnt = TVS_WYE::cast(pEnt)) != NULL )
		{
			pEnt->close();
			return isTVS_Wye;
		}
		if ( (pEnt = TVS_TRANS::cast(pEnt)) != NULL )
		{
			pEnt->close();
			return isTVS_TRANS;
		}
		pEnt->close();
		return isNoTVS;
	}
	else
	{

		acutPrintf(_T("Объект блокирован"));
		return isBlocked;
	}
}

int func::whyIsGrose( TVS_Entity* pEnt1,TVS_Entity* pEnt2 )
{
	if (pEnt1->SizeA>pEnt2->SizeA) return TVSEnt1isGrose;
	else
	{
		if (pEnt1->SizeA<pEnt2->SizeA) return TVSEnt2isGrose;
		else
		{
			if (pEnt1->SizeB>pEnt2->SizeB) return TVSEnt1isGrose;
			else
			{
				if (pEnt1->SizeB<pEnt2->SizeB) return TVSEnt2isGrose;
				else return TVSEntitiesisSame;

			}
		}
	}

}

void func::drawEntity( AcDbEntity *pEnt )
{
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
	//return pEnt;
}

int func::ActivationErrorMessage()
{
// 	int err;
// 	int start=GetTickCount();
// 	err=protection::licenseCheck();
// 	int endf=GetTickCount();
// 	int delta=endf-start;
// 	//acutPrintf(L"\nStart: %d\nEnd: %d",start,endf);
// 	acutPrintf(L"\nRun time: %d",delta);
// 	if(err!=pError_Ok)
// 	{
// 		string errstr;
// 		errstr=protection::getErrorCode(err);
// 		CString err_list(errstr.c_str());
// 
// 
// 		MessageBox(NULL, conversion::charToWchar(errstr.c_str()),L"Лицензия недействительна", MB_ICONERROR |MB_OK);
// 	
// 
// 		return err;
// 	}
// 	else
// 	{
// 		return pError_Ok;
// 	}
	return 0;
}
