
#include "StdAfx.h"
#include "Func.h"
#define M_PI 3.14159265358979323846
#define dCONTINUE 0
#define dCONNECT 1
#define dSIZE 2
#define dParal 1
#define dPerpend 0
#define dPeresec 2
#define dNeperesec 3
#define dComplanar 4
#define dObshaiztochka 5




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
double func::length2p(AcGePoint3d &A,
					  AcGePoint3d &B
					  )
{
	double x1,y1;
	x1=A.x-B.x;
	y1=A.y-B.y;
	return (sqrt(x1*x1+y1*y1));


}
AcGePoint3d func::shortlength(AcGePoint3d &A,
							  AcGePoint3d &B,
							  double &thislegth
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


void func::pCon (	AcDbEntity *pEnt1,
				 AcDbEntity  *pEnt2
				 )
{
	AcGePoint3d lastpipi;
	AcDbObjectId id;
	double Lx,Ly, startangle;
	ads_name vozd1,vozd2, eName;
	ACHAR handle[17];
	ads_point pt1,pt2;
	ads_real sise=0;
	AcDbEntity *pEnt = NULL;
	AcDbObjectId id1, id2;
	TVS_WYE wyie;
	TVS_TAP * Tapi;
	TVS_TRANS * Transi;
	TVS_WYE * Wyi;
	TVS_Pipe * Pipi1,*Pipi2, *Pip;
	double NewSiseA, NewRadius;
	resbuf *rb = NULL;
	bool ft=false;
	TVS_Pipe pipie;
	TVS_TAP tapie;
	AcGePoint3d kr1,kr2,na1,na2;


	AcCmColor pColor;
	AcDb::LineWeight pWeight;
	AcDbObjectId pLayer;
	AcDbObjectId pLineType;


	///проверка на класс1

	if (acdbOpenAcDbEntity(pEnt1,pEnt1->id(),AcDb::kForWrite)==eOk)
	{if ( (Pipi1 = TVS_Pipe::cast(pEnt1)) != NULL )
	{	

		pColor=Pipi1->color();
		pWeight=Pipi1->lineWeight();
		pLayer=Pipi1->layerId();
		pLineType=Pipi1->linetypeId();

	}}
	else {
		consoleprint(0,_T("\nОбьект заблокирован"));

		return;
	}

	pEnt1->close();	


	///////////оконьчание проверки1


	///проверка на класс1

	if (acdbOpenAcDbEntity(pEnt2,pEnt2->id(),AcDb::kForWrite)==eOk)
	{if ( (Pipi2 = TVS_Pipe::cast(pEnt2)) != NULL )
	{	



	}}
	else {
		consoleprint(0,_T("\nОбьект заблокирован"));

		return;
	}

	pEnt2->close();	


	///////////оконьчание проверки1








	//точка пересечения
	bool b1=false;
	bool b2=false;
	AcGePoint3d p1,p2,p3,p4,midp, pPr1,pOtv1,pX,pX2;
	AcGeVector3d pvectpr,pvectotv;	
	p1=Pipi1->FirstPoint;
	p2=Pipi1->LastPoint;
	p3=Pipi2->FirstPoint;
	p4=Pipi2->LastPoint;
	AcGeLine3d line1(p1,p2),line2(p3,p4) ;
	line1.intersectWith(line2,midp);
	///////
	TVS_Pipe *PipiPr,*PipiOtv;

	double lengthX;
	double pSizeApr=200;
	double pSizeBpr=0;
	double pSizeAotv=100;
	double pSizeBotv=0;
	double pLengthPl=50;
	AcGeVector3d pVectpr=AcGeVector3d(1,0,0);
	AcGeVector3d pVectotv=AcGeVector3d(0,1,0);
	AcGePoint3d pBasepoint=AcGePoint3d(0,0,0);
	bool pThisRoundpr=true;
	bool pThisRoundotv=true;
	bool pThis1D=false;
	AcDbEntity *pEntX;
	int statpersec=-1;
	int statnapr=-1;
	int obshaia=-1;
	AcGeVector3d vect1=AcGeVector3d(p2.x-p1.x,p2.y-p1.y,0);
	AcGeVector3d vect2=AcGeVector3d(p4.x-p3.x,p4.y-p3.y,0);
	AcGePoint3d blig1;

	///проверка на общую точку
	if ((p1==p3)||(p1==p4)||(p2==p3)||(p2==p4))
	{
		obshaia=dObshaiztochka;
		statpersec=dNeperesec;
		//acutPrintf(_T("\nимеют общую точку"));
	}

	/////проверка на перпендикуляпность

	if (abs(vect1.x*vect2.x+vect1.y*vect2.y)<=0.00001)
	{
		statnapr=dPerpend;
		//acutPrintf(_T("\nПерпендикулярны"));
	}
	if (statnapr!=dPerpend)
	{

		double asdf,asdk;
		if (abs(vect2.x)!=0)
		{
			asdf=abs(vect1.x/vect2.x);
		}
		else
		{
			asdf=1;
		}
		//consoleprint(asdf,_T("\nasdf "));
		if (abs(vect2.y)!=0)
		{
			asdk=abs(vect1.y/vect2.y);
		}
		else
		{
			asdk=2;
		}

		//consoleprint(asdk,_T("\nasdk "));
		//проверка на параллельность компланарность
		if ((abs(asdf-asdk)<0.0001)||(abs(vect1.x-vect2.x)<0.0001)||(abs(vect1.y-vect2.y)<0.0001))
		{
			if ( (abs(p1.x-p2.x)<0.0001)||(abs(p1.y-p2.y)<0.0001)    )
			{
				if(((abs(p1.x-p2.x)<0.0001)&&(abs(p1.x-p4.x)<0.0001))||((abs(p1.y-p2.y)<0.0001)&&(abs(p1.y-p4.y)<0.0001)  ))
				{
					statnapr=dComplanar;
					//acutPrintf(_T("\nКомпланарны 1"));

				}
				else 
				{
					statnapr=dParal;
					//acutPrintf(_T("\nПараллельны 1"));
				}
			} 
			else
			{
				double bb1,bb2;
				bb1=p1.y-(p1.y-p2.y)/(p1.x-p2.x)*p1.x;
				bb2=p3.y-(p3.y-p4.y)/(p3.x-p4.x)*p3.x;

				//consoleprint(bb1,_T("\n"));
				//	consoleprint(bb2,_T("\n"));
				if (abs(bb1-bb2)<0.0001)
				{
					statnapr=dComplanar;
					//acutPrintf(_T("\nКомпланарны 2"));
				} 
				else
				{

					statnapr=dParal;
					//acutPrintf(_T("\nПараллельны 2"));
				}
			}
		}

	}
	///для выбор

	double fSizeA=Pipi1->SizeA;
	bool fRound=Pipi1->ThisRound;
	double fSizeB=Pipi1->SizeB;

	double tapradius, radius, pSwectangle;
	AcGeVector3d normvect1=AcGeVector3d(-vect1.y,vect1.x,0);
	AcGePoint3d t2norm=AcGePoint3d(p2.x+normvect1.x,p2.y+normvect1.y,0);
	AcGeLine3d line3=AcGeLine3d(p2,t2norm);
	AcGePoint3d pCenterpoint;
	AcGeVector3d pstartvect;
	AcGeVector3d pnormvect=AcGeVector3d(0,0,1);
	AcGePoint3d impr;



	//выбор (исправление параллельности)
	if (statnapr==dParal)
	{



		line3.intersectWith(line2,midp);
		normvect1=AcGeVector3d(midp.x-p2.x,midp.y-p2.y,0);
		normvect1.normalize();
		if	(fRound==true)
		{
			if (fSizeA<355)
			{
				tapradius=fSizeA+fSizeA/2;
				radius=fSizeA;
			} 
			else
			{
				tapradius=fSizeA/2+fSizeA/2;
				radius=fSizeA/2;
			}
		}
		else
		{
			tapradius=fSizeA/2+150;
			radius=150;
		}

		Givecenterpoint(p1,p2,midp,tapradius,pCenterpoint,pSwectangle,pstartvect);

		if (correctpipes(p1,p2,midp,pSwectangle,fSizeA,radius,lastpipi,fRound)==true)
		{
			Tapi=tapie.add_new(fSizeA,fSizeB,radius,pnormvect,pstartvect,pCenterpoint,pSwectangle,false,fRound);
			///задание слоя
			if (acdbOpenAcDbEntity(pEnt,Tapi->id(),AcDb::kForWrite)==eOk)
			{	
				Tapi->setColor(pColor);
				Tapi->setLineWeight(pWeight);
				Tapi->setLayer(pLayer);
				Tapi->setLinetype(pLineType);
				Tapi->close();


			}



			id=Pipi1->id();
			acdbGetAdsName(eName,id);
			acdbGetObjectId(id,eName);
			acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite);
			Pipi1->assertWriteEnabled();
			Pipi1->put_Lastpoint(lastpipi);
			Pipi1->close();
			impr=AcGePoint3d(midp.x-normvect1.x,midp.y-normvect1.y,0);
			Pipi1=pipie.add_new(p2,impr,fSizeA,fSizeB,false,fRound);
			///задание слоя
			if (acdbOpenAcDbEntity(pEnt,Pipi1->id(),AcDb::kForWrite)==eOk)
			{	
				Pipi1->setColor(pColor);
				Pipi1->setLineWeight(pWeight);
				Pipi1->setLayer(pLayer);
				Pipi1->setLinetype(pLineType);
				Pipi1->close();
			}

			p1=Pipi1->FirstPoint;
			p2=Pipi1->LastPoint;
			line1=AcGeLine3d(p1,p2);
			vect1=AcGeVector3d(p2.x-p1.x,p2.y-p1.y,0);
			statnapr=dPerpend;
		}

	}

	//проверка на пересеч перпендикуляров
	if ((statnapr==dPerpend)&&(obshaia!=dObshaiztochka))
	{
		if(((((p3.x-midp.x)*(midp.x-p4.x))>=0)&&(((p3.y-midp.y)*(midp.y-p4.y))>=0))||((((p1.x-midp.x)*(midp.x-p2.x))>=0)&&(((p1.y-midp.y)*(midp.y-p2.y))>=0)) )
		{
			statpersec=dPeresec;
			//acutPrintf(_T("\nПеперcекаются"));
		}

		else statpersec=dNeperesec;

	}

	//проверка на вставку тройника и исправление 
	// (проверка на пересечение перпендикуляра из крайней точки 1-го возд и второго 
	// если да превращение в перпендикуляр

	if ((statpersec!=dPeresec)&&(statnapr!=dComplanar)&&(statnapr!=dPeresec))
	{

		//acutPrintf(_T("\nПроверка на пересечение"));

		if (length2p(p1,midp)>length2p(p2,midp)) 
		{
			kr1=p2;
			na1=p1;
		}
		else 
		{
			kr1=p1;
			na1=p2;
		}

		if (length2p(p3,midp)>length2p(p4,midp)) 
		{
			kr2=p4;
			na2=p3;
		}
		else 
		{
			kr2=p3;
			na2=p4;
		}

		bool ff=false;

		AcGePoint3d ffmidp;
		AcGeVector3d ffnorm=AcGeVector3d(-(p4.y-p3.y),p4.x-p3.x,0);
		AcGePoint3d fftnorm=AcGePoint3d(kr1.x+ffnorm.x,kr1.y+ffnorm.y,0);
		AcGeLine3d ffline=AcGeLine3d(kr1,fftnorm);
		ffline.intersectWith(line2,ffmidp);



		//проверка на нахождение точки персеч внутри 2 воздуховода
		if((((p3.x-ffmidp.x)*(ffmidp.x-p4.x))>=0)&&(((p3.y-ffmidp.y)*(ffmidp.y-p4.y))>=0))
		{
			//acutPrintf(_T("\nотвод и перпенд"));
			midp=ffmidp;
			line2.intersectWith(ffline,midp);
			normvect1=AcGeVector3d(midp.x-kr1.x,midp.y-kr1.y,0);
			normvect1.normalize();
			if	(fRound==true)
			{
				if (fSizeA<355)
				{
					tapradius=fSizeA+fSizeA/2;
					radius=fSizeA;
				} 
				else
				{
					tapradius=fSizeA/2+fSizeA/2;
					radius=fSizeA/2;
				}
			}
			else
			{
				tapradius=fSizeA/2+150;
				radius=150;
			}

			Givecenterpoint(na1,kr1,midp,tapradius,pCenterpoint,pSwectangle,pstartvect);

			if (correctpipes(na1,kr1,midp,pSwectangle,fSizeA,radius,lastpipi,fRound)==true)
			{
				Tapi=tapie.add_new(fSizeA,fSizeB,radius,pnormvect,pstartvect,pCenterpoint,pSwectangle,false,fRound);
				///задание слоя
				if (acdbOpenAcDbEntity(pEnt,Tapi->id(),AcDb::kForWrite)==eOk)
				{	
					Tapi->setColor(pColor);
					Tapi->setLineWeight(pWeight);
					Tapi->setLayer(pLayer);
					Tapi->setLinetype(pLineType);
					Tapi->close();
				}
				id=Pipi1->id();
				acdbGetAdsName(eName,id);
				acdbGetObjectId(id,eName);
				acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite);
				Pipi1->assertWriteEnabled();
				//consoleprint(na1,_T("\nmidp"));
				//consoleprint(Pipi1->LastPoint,_T("\nmidp"));
				if (na1==Pipi1->FirstPoint)			
					Pipi1->LastPoint=lastpipi;
				else Pipi1->FirstPoint=lastpipi;

				Pipi1->close();
				impr=AcGePoint3d(midp.x-normvect1.x,midp.y-normvect1.y,0);
				Pipi1=pipie.add_new(kr1,impr,fSizeA,fSizeB,false,fRound);
				if (acdbOpenAcDbEntity(pEnt,Pipi1->id(),AcDb::kForWrite)==eOk)
				{	
					Pipi1->setColor(pColor);
					Pipi1->setLineWeight(pWeight);
					Pipi1->setLayer(pLayer);
					Pipi1->setLinetype(pLineType);
					Pipi1->close();
				}
				p1=Pipi1->FirstPoint;
				p2=Pipi1->LastPoint;
				line1=AcGeLine3d(p1,p2);
				vect1=AcGeVector3d(p2.x-p1.x,p2.y-p1.y,0);
				statnapr=dPerpend;
				statpersec=dPeresec;
			}

		}

		else
		{
			//второй вариант
			bool dd=false;
			AcGePoint3d ddmidp;
			AcGeVector3d ddnorm=AcGeVector3d(-(p2.y-p1.y),p2.x-p1.x,0);
			AcGePoint3d ddtnorm=AcGePoint3d(kr2.x+ddnorm.x,kr2.y+ddnorm.y,0);
			AcGeLine3d ddline=AcGeLine3d(kr2,ddtnorm);
			ddline.intersectWith(line1,ddmidp);
			if((((p1.x-ddmidp.x)*(ddmidp.x-p2.x))>=0)&&(((p1.y-ddmidp.y)*(ddmidp.y-p2.y))>=0))
			{
				fSizeA=Pipi2->SizeA;
				fRound=Pipi2->ThisRound;
				fSizeB=Pipi2->SizeB;
				//	acutPrintf(_T("\nотвод и перпенд вар2"));
				midp=ddmidp;
				line1.intersectWith(ddline,midp);
				normvect1=AcGeVector3d(midp.x-kr2.x,midp.y-kr2.y,0);
				normvect1.normalize();
				if	(fRound==true)
				{
					if (fSizeA<355)
					{
						tapradius=fSizeA+fSizeA/2;
						radius=fSizeA;
					} 
					else
					{
						tapradius=fSizeA/2+fSizeA/2;
						radius=fSizeA/2;
					}
				}
				else
				{
					tapradius=fSizeA/2+150;
					radius=150;
				}

				Givecenterpoint(na2,kr2,midp,tapradius,pCenterpoint,pSwectangle,pstartvect);

				if (correctpipes(na2,kr2,midp,pSwectangle,fSizeA,radius,lastpipi,fRound)==true)
				{
					Tapi=tapie.add_new(fSizeA,fSizeB,radius,pnormvect,pstartvect,pCenterpoint,pSwectangle,false,fRound);
					if (acdbOpenAcDbEntity(pEnt,Tapi->id(),AcDb::kForWrite)==eOk)
					{	
						Tapi->setColor(pColor);
						Tapi->setLineWeight(pWeight);
						Tapi->setLayer(pLayer);
						Tapi->setLinetype(pLineType);
						Tapi->close();
					}
					id=Pipi2->id();
					acdbGetAdsName(eName,id);
					acdbGetObjectId(id,eName);
					acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite);
					Pipi2->assertWriteEnabled();
					//consoleprint(na2,_T("\nmidp"));
					//consoleprint(Pipi2->LastPoint,_T("\nmidp"));
					if (na2==Pipi2->FirstPoint)			
						Pipi2->LastPoint=lastpipi;
					else Pipi2->FirstPoint=lastpipi;

					Pipi2->close();
					impr=AcGePoint3d(midp.x-normvect1.x,midp.y-normvect1.y,0);
					Pipi2=pipie.add_new(kr2,impr,fSizeA,fSizeB,false,fRound);
					if (acdbOpenAcDbEntity(pEnt,Pipi2->id(),AcDb::kForWrite)==eOk)
					{	
						Pipi2->setColor(pColor);
						Pipi2->setLineWeight(pWeight);
						Pipi2->setLayer(pLayer);
						Pipi2->setLinetype(pLineType);
						Pipi2->close();
					}
					p3=Pipi2->FirstPoint;
					p4=Pipi2->LastPoint;
					line2=AcGeLine3d(p3,p4);
					vect2=AcGeVector3d(p4.x-p3.x,p4.y-p3.y,0);
					statnapr=dPerpend;
					statpersec=dPeresec;
				}

			} 
			else {
				//acutPrintf(_T("\nНепересекаются"));
				statpersec=dNeperesec;

			}
		}

	}


	//установка перехода

	if ((statpersec!=dPeresec)||(statnapr==dComplanar)||(obshaia==dObshaiztochka))
	{

		if ((Pipi1->SizeA!=Pipi2->SizeA)||(Pipi1->SizeB!=Pipi2->SizeB))
		{
			//acutPrintf(_T("\nСтавлю переход"));




			if (statnapr==dComplanar)
			{
				if(Pipi1->SizeA>Pipi2->SizeA)
				{


					if (length2p(p1,p3)>length2p(p1,p4)) midp=p3;
					else midp=p4;

				}
				else
				{
					if (length2p(p3,p1)>length2p(p3,p2)) midp=p1;
					else midp=p2;
				}
			}
			if (length2p(p1,midp)>length2p(p2,midp)) 
			{
				kr1=p2;
				na1=p1;
			}
			else 
			{
				kr1=p1;
				na1=p2;
			}

			if (length2p(p3,midp)>length2p(p4,midp)) 
			{
				kr2=p4;
				na2=p3;
			}
			else 
			{
				kr2=p3;
				na2=p4;
			}
			TVS_TRANS transie;
			double pSizeAp1;
			double pSizeBp1;
			double pSizeAp2;
			double pSizeBp2;
			if (Pipi1->SizeA>Pipi2->SizeA)
			{


				pSizeAp1=Pipi1->SizeA;
				pSizeBp1=Pipi1->SizeB;
				pSizeAp2=Pipi2->SizeA;
				pSizeBp2=Pipi2->SizeB;



				double pLengthTr=300;
				AcGeVector3d Vect=AcGeVector3d(midp.x-na1.x, midp.y-na1.y,0);
				AcGeVector3d pVectTr;
				AcGePoint3d pFirstPoint=na1;
				pVectTr=Vect.normalize()*pLengthTr;

				double pThisRoundp1,
					pThisRoundp2;
				int pTransType=ftTransType;
				bool pThis1D=false;

				if (pSizeBp1==0) pThisRoundp1=true;
				else pThisRoundp1=false;

				if (pSizeBp2==0) pThisRoundp2=true;
				else pThisRoundp2=false;

				Transi=transie.add_new(pSizeAp1,
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
				if (acdbOpenAcDbEntity(pEnt,Transi->id(),AcDb::kForWrite)==eOk)
				{	
					Transi->setColor(pColor);
					Transi->setLineWeight(pWeight);
					Transi->setLayer(pLayer);
					Transi->setLinetype(pLineType);
					Transi->close();
				}
				pFirstPoint=AcGePoint3d(pFirstPoint.x+pLengthTr*Vect.x,
					pFirstPoint.y+pLengthTr*Vect.y,
					pFirstPoint.z+pLengthTr*Vect.z
					);
				AcGePoint3d pLastPoint=AcGePoint3d(pFirstPoint.x+100*Vect.x,
					pFirstPoint.y+100*Vect.y,
					pFirstPoint.z+100*Vect.z
					);

				bool pThis1d=false;


				id=Pipi1->id();
				acdbGetAdsName(eName,id);
				acdbEntDel(eName);
				Pipi1=Pipi2->add_new(pFirstPoint,
					pLastPoint,
					pSizeAp2,
					pSizeBp2,
					pThis1d,
					pThisRoundp2);
				if (acdbOpenAcDbEntity(pEnt,Pipi1->id(),AcDb::kForWrite)==eOk)
				{	
					Pipi1->setColor(pColor);
					Pipi1->setLineWeight(pWeight);
					Pipi1->setLayer(pLayer);
					Pipi1->setLinetype(pLineType);
					Pipi1->close();
				}
				p1=Pipi1->FirstPoint;
				p2=Pipi1->LastPoint;
				line1=AcGeLine3d(p1,p2);
				vect1=AcGeVector3d(p2.x-p1.x,p2.y-p1.y,0);

			}
			else
			{

				pSizeAp1=Pipi2->SizeA;
				pSizeBp1=Pipi2->SizeB;
				pSizeAp2=Pipi1->SizeA;
				pSizeBp2=Pipi1->SizeB;



				double pLengthTr=300;
				AcGeVector3d Vect=AcGeVector3d(midp.x-na2.x, midp.y-na2.y,0);
				AcGeVector3d pVectTr;
				AcGePoint3d pFirstPoint=na2;
				pVectTr=Vect.normalize()*pLengthTr;

				double pThisRoundp1,
					pThisRoundp2;
				int pTransType=ftTransType;
				bool pThis1D=false;

				if (pSizeBp1==0) pThisRoundp1=true;
				else pThisRoundp1=false;

				if (pSizeBp2==0) pThisRoundp2=true;
				else pThisRoundp2=false;

				Transi=transie.add_new(pSizeAp1,
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

				if (acdbOpenAcDbEntity(pEnt,Transi->id(),AcDb::kForWrite)==eOk)
				{	
					Transi->setColor(pColor);
					Transi->setLineWeight(pWeight);
					Transi->setLayer(pLayer);
					Transi->setLinetype(pLineType);
					Transi->close();
				}
				pFirstPoint=AcGePoint3d(pFirstPoint.x+pLengthTr*Vect.x,
					pFirstPoint.y+pLengthTr*Vect.y,
					pFirstPoint.z+pLengthTr*Vect.z
					);
				AcGePoint3d pLastPoint=AcGePoint3d(pFirstPoint.x+100*Vect.x,
					pFirstPoint.y+100*Vect.y,
					pFirstPoint.z+100*Vect.z
					);

				bool pThis1d=false;
				id=Pipi2->id();

				acdbGetAdsName(eName,id);
				/*acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite);
				Pipi2->assertWriteEnabled();*/
				acdbEntDel(eName);
				Pipi2=Pipi1->add_new(pFirstPoint,
					pLastPoint,
					pSizeAp2,
					pSizeBp2,
					pThis1d,
					pThisRoundp2);

				if (acdbOpenAcDbEntity(pEnt,Pipi2->id(),AcDb::kForWrite)==eOk)
				{	
					Pipi2->setColor(pColor);
					Pipi2->setLineWeight(pWeight);
					Pipi2->setLayer(pLayer);
					Pipi2->setLinetype(pLineType);
					Pipi2->close();
				}
				p3=Pipi2->FirstPoint;
				p4=Pipi2->LastPoint;
				line2=AcGeLine3d(p3,p4);
				vect2=AcGeVector3d(p4.x-p3.x,p4.y-p3.y,0);
			}
		}



	}



	///////////отводы


	if (((statpersec==dNeperesec)||(obshaia==dObshaiztochka))&&(statnapr!=dComplanar))

	{
		//acutPrintf(_T("\nПытаюсь поставить отвод"));
		if (length2p(p1,midp)>length2p(p2,midp)) 
		{
			kr1=p2;
			na1=p1;
		}
		else 
		{
			kr1=p1;
			na1=p2;
		}

		if (length2p(p3,midp)>length2p(p4,midp)) 
		{
			kr2=p4;
			na2=p3;
		}
		else 
		{
			kr2=p3;
			na2=p4;
		}


		vect1=AcGeVector3d(kr1.x-na1.x,
			kr1.y-na1.y,
			kr1.z-na1.z);
		vect2=AcGeVector3d(kr2.x-na2.x,
			kr2.y-na2.y,
			kr2.z-na2.z);
		vect1.normalize();
		vect2.normalize();
		double pSizeAw=Pipi1->SizeA;
		double pSizeBw=Pipi1->SizeB;
		bool pRoundw=Pipi1->ThisRound;

		if (vect1!=vect2)
		{

			if	(pRoundw==true)
			{
				if (pSizeAw<355)
				{
					tapradius=pSizeAw+pSizeAw/2;
					radius=pSizeAw;
				} 
				else
				{
					tapradius=pSizeAw/2+pSizeAw/2;
					radius=pSizeAw/2;
				}
			}
			else
			{
				tapradius=pSizeAw/2+150;
				radius=150;
			}
		}

		Givecenterpoint(na1,midp,na2,tapradius,pCenterpoint,pSwectangle,pstartvect);
		if (correctpipes(na1,midp,na2,pSwectangle,pSizeAw,radius,lastpipi,pRoundw)==true)
		{
			Tapi=tapie.add_new(pSizeAw,pSizeBw,radius,pnormvect,pstartvect,pCenterpoint,pSwectangle,false,pRoundw);
			if (acdbOpenAcDbEntity(pEnt,Tapi->id(),AcDb::kForWrite)==eOk)
			{	
				Tapi->setColor(pColor);
				Tapi->setLineWeight(pWeight);
				Tapi->setLayer(pLayer);
				Tapi->setLinetype(pLineType);
				Tapi->close();
			}
			id=Pipi1->id();
			acdbGetAdsName(eName,id);
			acdbGetObjectId(id,eName);
			acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite);
			Pipi1->assertWriteEnabled();
			if (na1==Pipi1->FirstPoint)			
				Pipi1->LastPoint=lastpipi;
			else Pipi1->FirstPoint=lastpipi;


			Pipi1->close();


			id=Pipi2->id();
			acdbGetAdsName(eName,id);
			acdbGetObjectId(id,eName);
			acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite);
			Pipi2->assertWriteEnabled();
			if (na2==Pipi2->FirstPoint)			
				Pipi2->LastPoint=midp;
			else Pipi2->FirstPoint=midp;

			Pipi2->close();

			//acutPrintf(_T("\nОтвод поставлен"));



		}
		//else acutPrintf(_T("\nНе могу поставить отвод"));





	}





	///////// удлинение компланара


	if (statnapr==dComplanar)
	{
		if (length2p(p1,p3)>length2p(p2,p3)) kr1=p1;
		else kr1=p2;

		if (length2p(p1,p4)>length2p(p1,p3)) kr2=p4;
		else kr2=p3;

		id=Pipi1->id();
		acdbGetAdsName(eName,id);
		acdbGetObjectId(id,eName);
		acdbOpenAcDbEntity(pEnt,id,AcDb::kForWrite);
		Pipi1->assertWriteEnabled();
		if (kr1==Pipi1->FirstPoint)			
			Pipi1->LastPoint=kr2;
		else Pipi1->FirstPoint=kr2;
		Pipi1->close();

		id=Pipi2->id();
		acdbGetAdsName(eName,id);
		acdbEntDel(eName);

	}




	///////тройники
	if ((statpersec==dPeresec)&&(statnapr==dPerpend)&&(obshaia!=dObshaiztochka))
	{
		if((((p1.x-midp.x)*(midp.x-p2.x))>=0)&&(((p1.y-midp.y)*(midp.y-p2.y))>=0)) //p1-проход (тройник)

		{
			PipiPr=Pipi1;
			PipiOtv=Pipi2;
			pSizeApr=PipiPr->SizeA;
			pSizeAotv=PipiOtv->SizeA;
			pSizeBpr=PipiPr->SizeB;
			pSizeBotv=PipiOtv->SizeB;
			pThisRoundpr=PipiPr->ThisRound;
			pThisRoundotv=PipiOtv->ThisRound;

			pVectpr=AcGeVector3d(p2.x-p1.x,p2.y-p1.y,0);


			////////////kraynaja  точка отвода

			if (length2p(midp,p3)<length2p(midp,p4))
			{
				pOtv1=p4;
				pVectotv=AcGeVector3d(p4.x-p3.x,p4.y-p3.y,0);
			}

			else
			{
				pOtv1=p3;
				pVectotv=AcGeVector3d(p3.x-p4.x,p3.y-p4.y,0);
			}
			////////////kraynaja  точка прохода

			if (length2p(midp,p2)<length2p(midp,p1))
			{
				pPr1=p2;

			}

			else
			{
				pPr1=p1;

			}

			if (length2p(midp,pOtv1)<(pLengthPl+pSizeApr/2))	
			{
				//acutPrintf(_T("отвод короткий"));
			}
			else b1=true;
			if ((length2p(midp,p1)<(pLengthPl+pSizeAotv/2))&&(length2p(midp,p2)<(pLengthPl+pSizeAotv/2)))	
			{
				//acutPrintf(_T("проход короткий"));
			}
			else b2=true;

			if ((b1==true)&&(b1==true))
			{
				pBasepoint=midp;
				Wyi=wyie.add_new(pSizeApr,
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

				if (acdbOpenAcDbEntity(pEnt,Wyi->id(),AcDb::kForWrite)==eOk)
				{	
					Wyi->setColor(pColor);
					Wyi->setLineWeight(pWeight);
					Wyi->setLayer(pLayer);
					Wyi->setLinetype(pLineType);
					Wyi->close();
				}

			} 

			////построение прохода
			if (acdbOpenAcDbEntity(pEntX,PipiPr->id(),AcDb::kForWrite)==eOk)
			{if ( (PipiPr = TVS_Pipe::cast(pEntX)) != NULL )
			{	



				pX=midp;
				pX2=PipiPr->LastPoint;
				lengthX=pSizeAotv/2+pLengthPl;
				pX=shortlength(PipiPr->FirstPoint,pX,lengthX);

				PipiPr->put_Lastpoint(pX);
				pX=midp;
				pX=shortlength(pX2,pX,lengthX);
				Pip=PipiPr->add_new(pX2,pX,pSizeApr,pSizeBpr,PipiPr->This1D,PipiPr->ThisRound);

				if (acdbOpenAcDbEntity(pEnt,Pip->id(),AcDb::kForWrite)==eOk)
				{	
					Pip->setColor(pColor);
					Pip->setLineWeight(pWeight);
					Pip->setLayer(pLayer);
					Pip->setLinetype(pLineType);
					Pip->close();
				}



				//acutPrintf(_T("\nПостроение 1"));


			}}
			else {
				consoleprint(0,_T("\nОбьект заблокирован"));

				return;
			}

			pEntX->close();	
			/////построение отвода
			if (acdbOpenAcDbEntity(pEntX,PipiOtv->id(),AcDb::kForWrite)==eOk)
			{if ( (PipiOtv = TVS_Pipe::cast(pEntX)) != NULL )
			{	

				pX=midp;
				lengthX=pSizeApr/2+pLengthPl;
				if(length2p(midp,PipiOtv->LastPoint)>length2p(midp,PipiOtv->FirstPoint))
				{
					pX=shortlength(PipiOtv->FirstPoint,pX,lengthX);
					PipiOtv->put_FirstPoint(pX);
				}
				else 
				{
					pX=shortlength(PipiOtv->LastPoint,pX,lengthX);
					PipiOtv->put_Lastpoint(pX);
				}


				//acutPrintf(_T("\nПостроение 1.2"));

			}}
			else {
				acutPrintf(_T("\nОбьект заблокирован"));

				return;
			}

			pEntX->close();	
			////////









		}


		if((((p3.x-midp.x)*(midp.x-p4.x))>=0)&&(((p3.y-midp.y)*(midp.y-p4.y))>=0)) //p2-проход (тройник)

		{
			PipiPr=Pipi2;
			PipiOtv=Pipi1;
			pSizeApr=PipiPr->SizeA;
			pSizeAotv=PipiOtv->SizeA;
			pSizeBpr=PipiPr->SizeB;
			pSizeBotv=PipiOtv->SizeB;
			pThisRoundpr=PipiPr->ThisRound;
			pThisRoundotv=PipiOtv->ThisRound;

			pVectpr=AcGeVector3d(p4.x-p3.x,p4.y-p3.y,0);


			////////////kraynaja  точка отвода

			if (length2p(midp,p1)<length2p(midp,p2))
			{
				pOtv1=p2;
				pVectotv=AcGeVector3d(p2.x-p1.x,p2.y-p1.y,0);
			}

			else
			{
				pOtv1=p1;
				pVectotv=AcGeVector3d(p1.x-p2.x,p1.y-p2.y,0);
			}
			////////////kraynaja  точка прохода

			if (length2p(midp,p4)<length2p(midp,p3))
			{
				pPr1=p4;

			}

			else
			{
				pPr1=p3;

			}

			if (length2p(midp,pOtv1)<(pLengthPl+pSizeApr/2))	
			{
				acutPrintf(_T("отвод короткий"));
			}
			else b1=true;
			if ((length2p(midp,p3)<(pLengthPl+pSizeAotv/2))&&(length2p(midp,p4)<(pLengthPl+pSizeAotv/2)))	
			{
				acutPrintf(_T("проход короткий"));
			}
			else b2=true;

			if ((b1==true)&&(b1==true))
			{
				pBasepoint=midp;
				Wyi=wyie.add_new(pSizeApr,
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
				if (acdbOpenAcDbEntity(pEnt,Wyi->id(),AcDb::kForWrite)==eOk)
				{	
					Wyi->setColor(pColor);
					Wyi->setLineWeight(pWeight);
					Wyi->setLayer(pLayer);
					Wyi->setLinetype(pLineType);
					Wyi->close();
				}

			} 

			////построение прохода
			if (acdbOpenAcDbEntity(pEntX,PipiPr->id(),AcDb::kForWrite)==eOk)
			{if ( (PipiPr = TVS_Pipe::cast(pEntX)) != NULL )
			{	
				//acutPrintf(_T("\npEntX...ок"));


				pX=midp;
				pX2=PipiPr->LastPoint;
				lengthX=pSizeAotv/2+pLengthPl;
				pX=shortlength(PipiPr->FirstPoint,pX,lengthX);

				PipiPr->put_Lastpoint(pX);
				pX=midp;
				pX=shortlength(pX2,pX,lengthX);
				Pip=PipiPr->add_new(pX2,pX,pSizeApr,pSizeBpr,PipiPr->This1D,PipiPr->ThisRound);
				if (acdbOpenAcDbEntity(pEnt,Pip->id(),AcDb::kForWrite)==eOk)
				{	
					Pip->setColor(pColor);
					Pip->setLineWeight(pWeight);
					Pip->setLayer(pLayer);
					Pip->setLinetype(pLineType);
					Pip->close();
				}

				//	acutPrintf(_T("\nПостроение 2"));


			}}
			else {
				acutPrintf(_T("\nОбьект заблокирован"));

				return;
			}

			pEntX->close();	

			/////построение отвода
			if (acdbOpenAcDbEntity(pEntX,PipiOtv->id(),AcDb::kForWrite)==eOk)
			{if ( (PipiOtv = TVS_Pipe::cast(pEntX)) != NULL )
			{	

				pX=midp;
				lengthX=pSizeApr/2+pLengthPl;
				if(length2p(midp,PipiOtv->LastPoint)>length2p(midp,PipiOtv->FirstPoint))
				{
					pX=shortlength(PipiOtv->FirstPoint,pX,lengthX);
					PipiOtv->put_FirstPoint(pX);
				}
				else 
				{
					pX=shortlength(PipiOtv->LastPoint,pX,lengthX);
					PipiOtv->put_Lastpoint(pX);
				}


				//acutPrintf(_T("\nПостроение 1.2"));

			}}
			else {
				acutPrintf(_T("\nОбьект заблокирован"));

				return;
			}

			pEntX->close();	
			////////

		}




	}
	///////////////////////конец тройники

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


void func::Change (ads_name &sset)
{




	ads_name  eName;
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





	long len = 0;

	acedSSLength(sset, &len);
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


	CString sSizeA;
	CString sSizeB;
	CString sFlow;
	CString sSizeA2;
	CString sSizeB2;
	CString sLengthTr;
	CString sLengthW;
	CString sElev;

	BOOL sWipe;
	BOOL sGrani;
	BOOL sD1;



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

	BOOL ElevationMid=1;
	BOOL ElevationUp=0;
	BOOL ElevationDown=0;




	dgAllEdit dg;
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




	dgAllEdit dg;
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



	if(pEnt->upgradeOpen()==Acad::eOk)
	{







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
				  bool &objectvar,
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


void func::strfil (double &myvar,
				   bool &variableconst,
				   CString &stringconst
				   )
{
	if (variableconst==true)
		stringconst=CString("Разные");
	else stringconst.Format(L"%g", myvar);

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


