
#include "StdAfx.h"
#include "SPEC.h"

#include <cmath>
#include<iostream>
using namespace std;

#define None 0
#define PipeRound 1
#define PipeRect 2
#define TapRound 3
#define TapRect 4
#define Trans 5
#define Wye 6
#define TypeInt 0
#define TypeDouble1 1
#define TypeDouble2 2

#pragma once

void SPEC::setAcharType(int val)
{
	switch (val)
	{
	case TypeInt:
		wcscpy_s(achartype,_T("%d"));
	case TypeDouble1:
		wcscpy_s(achartype,_T("%10.1f "));
	case TypeDouble2:
		wcscpy_s(achartype,_T("%10.2f "));
	default:
		wcscpy_s(achartype,_T(""));
	}
}

SPEC::SPEC(void)
{
	wcscpy_s(d,_T("%%c"));
	wcscpy_s(grad,_T("%%d"));
}

SPEC::~SPEC(void)
{
}


void SPEC::setParam1(double param,int type)
{
	param1=param;
	param1Type=type;
}

void SPEC::setParam2(double param,int type)
{
	param2=param;
	param2Type=type;
}

bool SPEC::add(AcDbEntity * pEnt)
{
	TVS_Pipe * pPipe;
	TVS_TAP * pTap;
	TVS_WYE * pWye;
	TVS_TRANS * pTrans;
	TVS_Entity *Ent;
	status=None;
	SizeA=0;
	SizeB=0;
	SizeA2=0;
	SizeA3=0;
	Swectangle=0;
	Length=0;
	Area=0;



	if (acdbOpenAcDbEntity(pEnt,pEnt->id(),AcDb::kForRead)==eOk)
	{
		if(Ent = TVS_Entity::cast(pEnt))
		{


#pragma region Pipe
			if(pPipe = TVS_Pipe::cast(pEnt))
			{

				SizeA=pPipe->get_SizeA();
				SizeB=pPipe->get_SizeB();
				Length=pPipe->get_Length();
				setUnit1(_T("м"));
				setUnit2(_T("м2"));
				if (pPipe->DuctType==DuctTypeFlex)
				{
					status=PipeRound;
					setName(_T("Воздуховод гибкий"));
					setLable(d);
					appendLable(SizeA);
					Area=Length*M_PI*SizeA/1000000;
					setParam1(Length/1000, TypeDouble1);
					setParam2(Area, TypeDouble2);
				}
				else
				{
					if (SizeB==0) 
					{
						status=PipeRound;
						setName(_T("Воздуховод круглый"));
						setLable(d);
						appendLable(SizeA);
						Area=Length*M_PI*SizeA/1000000;

					}
					else 
					{ 
						status=PipeRect;
						setName(_T("Воздуховод прямоугольный"));
						if (SizeB>SizeA)
						{
							SizeB=pPipe->SizeA;
							SizeA=pPipe->SizeB;
						}
						setLable(max(SizeA,SizeB));
						appendLable(_T("x"));
						appendLable(min(SizeA,SizeB));
						Area=Length*(SizeB+SizeA)*2/1000000;
					}
					setParam1(Length/1000, TypeDouble1);
					setParam2(Area, TypeDouble2);
				}
			}
#pragma endregion

#pragma region Tap
			if(pTap = TVS_TAP::cast(pEnt))
			{




				if (pTap->DuctType==DuctTypeFlex)
				{
					SizeA=pTap->get_SizeA();
					SizeB=pTap->get_SizeB();

					setUnit1(_T("м"));
					setUnit2(_T("м2"));

					status=PipeRound;
					setName(_T("Воздуховод гибкий"));
					setLable(d);
					appendLable(SizeA);
					Length=M_PI*pTap->Radius*pTap->Swectangle/2/M_PI/1000;
					Area=Length*M_PI*SizeA/1000;

					setParam1(Length, TypeDouble1);
					setParam2(Area, TypeDouble2);
				}
				else
				{
					Swectangle=5*floor((pTap->Swectangle+(2*M_PI/180))/5*180/M_PI);

					
					SizeA=pTap->get_SizeA();
					SizeB=pTap->get_SizeB();

					setUnit1(_T("шт"));
					setUnit2(_T("м2"));

					if (SizeB==0) 
					{
						status=TapRound;
						setName(_T("Отвод круглый"));
						setLable(d);
						appendLable(SizeA);
						Area=M_PI*2*SizeA*pTap->Radius/1000000*pTap->Swectangle;
						if ((pTap->RadiusTypeRound==TypeRoundTap_TapSection)&&(SizeA<=355))
						{
							Area=Area+M_PI*SizeA*2/10000;
						}

					}
					else 
					{ 
						if (pTap->Form == Form_Direct)
						{
					
							SizeA=pTap->get_SizeA();
							SizeB=pTap->get_SizeB();
						}else{
						
							SizeB=pTap->get_SizeA();
							SizeA=pTap->get_SizeB();
						}
						status=TapRect;
						setName(_T("Отвод прямоугольный"));
						setLable(SizeA);
						appendLable(_T("x"));
						appendLable(SizeB);
						Area=(pTap->Swectangle)/(2*M_PI) 
							*(2*(M_PI*(pTap->Radius+pTap->SizeA)*(pTap->Radius+pTap->SizeA)/1000000
							-M_PI*(pTap->Radius)*(pTap->Radius)/1000000) 
							+2*M_PI*(pTap->SizeA+pTap->Radius)/1000*pTap->SizeB/1000
							+2*M_PI*(pTap->Radius)/1000*pTap->SizeB/1000);
					}
					appendLable(_T("("));
					appendLable(Swectangle);
					appendLable(grad);
					appendLable(_T(")"));
					setParam1(1, TypeDouble1);
					setParam2(Area, TypeDouble2);
				}
			}
#pragma endregion
#pragma region Wye
			if(pWye = TVS_WYE::cast(pEnt))
			{
				status=Wye;
				SizeA=pWye->get_SizeApr();
				SizeB=pWye->get_SizeBpr();
				SizeA2=pWye->get_SizeAotv();
				SizeA3=pWye->get_SizeBotv();
				Swectangle=pWye->LengthPl;
				setUnit1(_T("шт"));
				setUnit2(_T("м2"));

				if (SizeB==0) 
				{
					setName(_T("Тройник"));
					setLable(d);
					appendLable(SizeA);
					Area=(SizeA2+pWye->LengthPl*2)*M_PI*SizeA/1000000;
				}
				else 
				{ 
					setName(_T("Тройник"));
					setLable(SizeA);
					appendLable(_T("x"));
					appendLable(SizeB);
					Area=(SizeA2+pWye->LengthPl*2)*(SizeA+SizeB)/500000; 
				}
				appendLable(_T("-"));
				if (SizeA3==0) 
				{
					appendLable(d);
					appendLable(SizeA2);
					Area=Area+(pWye->LengthPl)*M_PI*SizeA2/1000000-sCircle(SizeA2/1000);
				}
				else 
				{ 
					setName(_T("Тройник"));
					appendLable(SizeA2);
					appendLable(_T("x"));
					appendLable(SizeA3);
					Area=Area+(pWye->LengthPl)*(SizeA2+SizeA3)/500000-SizeA2*SizeA3/1000000; 
				}

				appendLable(_T(" (L="));
				appendLable(pWye->LengthPl);
				appendLable(_T(" мм)"));
				setParam1(1, TypeDouble1);
				setParam2(Area, TypeDouble2);
			}
#pragma endregion
#pragma region Trans
			if(pTrans = TVS_TRANS::cast(pEnt))
			{
				status=Trans;
				Swectangle=pTrans->LengthTr;
				SizeA=pTrans->get_SizeAp1();
				SizeB=pTrans->get_SizeBp1();
				SizeA2=pTrans->get_SizeAp2();
				SizeA3=pTrans->get_SizeBp2();
				if (SizeB==0)
				{
					if (SizeA3==0)
					{
						if (SizeA<SizeA2)
						{
							SizeA=pTrans->get_SizeAp2();
							SizeB=pTrans->get_SizeBp2();
							SizeA2=pTrans->get_SizeAp1();
							SizeA3=pTrans->get_SizeBp1();
						}
					}
				}
				else
				{
					if ((SizeA3==0)||(SizeA<SizeA2))
					{

						SizeA=pTrans->get_SizeAp2();
						SizeB=pTrans->get_SizeBp2();
						SizeA2=pTrans->get_SizeAp1();
						SizeA3=pTrans->get_SizeBp1();
					}

				}

				setUnit1(_T("шт"));
				setUnit2(_T("м2"));
				double radp1, radp2;
				if (SizeB==0) 
				{
					setName(_T("Переход"));
					setLable(d);
					appendLable(SizeA);
					radp1=SizeA/2;
				}
				else 
				{ 
					setName(_T("Переход"));
					setLable(SizeA);
					appendLable(_T("x"));
					appendLable(SizeB);
					radp1=(SizeB+SizeA)/(M_PI);
				}
				appendLable(_T("-"));
				if (SizeA3==0) 
				{
					appendLable(d);
					appendLable(SizeA2);
					radp2=SizeA2/2;

				}
				else 
				{ 

					appendLable(SizeA2);
					appendLable(_T("x"));
					appendLable(SizeA3);
					radp2=(SizeA2+SizeA3)/(M_PI);

				}
				double dobr=sqrt(pow(radp1-radp2,2)+pow(pTrans->LengthTr,2));
				Area=M_PI*(radp1+radp2)*dobr/1000000;
				appendLable(_T(" (L="));
				appendLable(pTrans->LengthTr);
				appendLable(_T(" мм)"));
				setParam1(1, TypeDouble1);
				setParam2(Area, TypeDouble2);
			}
#pragma endregion
			//if (status!=None) printResult();


			pEnt->close();
			return true;
		}
		pEnt->close();	
	}

	else return false;
}

void SPEC::setName(const ACHAR * pName)
{
	wcscpy_s(name,pName);
}

void SPEC::setLable(const ACHAR * pAchar)
{
	wcscpy_s(lable,pAchar);
}


void SPEC::setLable(double val)
{
	acdbRToS(val,2,2,lable);
	
}

void SPEC::appendLable( const ACHAR * pAchar )
{
	wcscat_s(lable,pAchar);
}


void SPEC::appendLable( double par )
{
	ACHAR buffer [512] ;
	acdbRToS(par,2,2,buffer);
	wcscat_s(lable,buffer);
}

void SPEC::setUnit1(const ACHAR * pAchar)
{
	wcscpy_s(unit1,pAchar);
}

void SPEC::setUnit2(const ACHAR * pAchar)
{
	wcscpy_s(unit2,pAchar);
}


void SPEC::printResult()
{
	setParamChars();
	acutPrintf(_T("\n%s %s  %s  %s  %s  %s"), name,lable,param1char, unit1, param2char, unit2);
	// 	acutPrintf(_T("%s "),param1char);
	// 	acutPrintf(_T("%s "),unit1);
	// 	acutPrintf(_T("%s "),param2char);
	// 	acutPrintf(_T("%s"),unit2);




}


void SPEC::printResultChar()
{
	setParamChars();
	acutPrintf(_T("\n%s %s  %s  %s  %s  %s  %s  %s  %s"),sPos, sName,sTypeSize,sManufacture,sArticle, sUnit, param1char, sMass,sCommit);
}

// int SPEC::toInt( const ACHAR * pAchar )
// {
// 
// }


const ACHAR * SPEC::toChar( double val )
{
	const ACHAR* str=new ACHAR[512];
	ACHAR  buffer[512];
	acdbRToS(val,2,2,buffer);
	str=buffer;
	return buffer;
}


void SPEC::setParamChars()
{
	acdbRToS(param1,2,param1Type,param1char);
	acdbRToS(param2,2,param2Type,param2char);
	acdbRToS(param1,2,param1Type,sValue);
}


double SPEC::sCircle(double diam)
{
	return M_PI*diam*diam/4;
}

double SPEC::lCircle(double diam)
{
	return M_PI*diam;
}

bool SPEC::GetAtt(AcDbEntity* pEnt, ACHAR* tag, ACHAR  *pVal)
{

	AcDbDatabase *pCurDb;
	AcDbBlockTable* pBlkTbl;
	AcDbBlockTableRecord* pBlkRec;
	AcDbObjectId attId;
	Acad::ErrorStatus es;
	AcDbBlockReference * br;
	AcDbAttributeDefinition* pAttDef;
	// location of the AttributeDefinition in the
	// block definition
	ACHAR* pName;


	if (acdbOpenAcDbEntity(pEnt,pEnt->id(),AcDb::kForWrite)==eOk)

	{
		if ( (br = AcDbBlockReference::cast(pEnt)) != NULL )
		{	



			AcDbObjectIterator *pAttrIter = br->attributeIterator();
			if (pAttrIter) {
				for (pAttrIter->start();!pAttrIter->done();pAttrIter->step()) {
					AcDbObjectId objAttrId = pAttrIter->objectId();
					AcDbObjectPointer<AcDbAttribute> pAttr(objAttrId,AcDb::kForRead);

					if ((es = pAttr.openStatus()) == Acad::eOk) {
						//
						// Здесь можно получить информацию об атрибуте
						//

						if (wcscmp(tag,pAttr->tagConst())==0) {
							//	pAttDef->close();
							pAttr->close();
							pEnt->close();
							//acutPrintf(_T("\nАтрибут: Tag=%s Value=%s "),
							//	LPCTSTR(pAttr->tagConst()),LPCTSTR(pAttr->textStringConst()));

							wcscpy_s(pVal,512,pAttr->textStringConst());
							return true;
						}

						pAttr->close();
					} else {
						acutPrintf(_T("\nНе удалось открыть атрибут блока! Ошибка: %s", LPCTSTR(acadErrorStatusText(es))));
					}
				}
			}
		}
		pEnt->close();
	}












	return false;

}
bool SPEC::addBlock(AcDbEntity * pEnt)
{

	if(GetAtt(pEnt,TagName,sName)&&GetAtt(pEnt,TagSize,sSize)&&GetAtt(pEnt,TagType,sType))
	{
		wcscpy_s(sPos,_T(""));
		//wcscpy_s(sName,_T(""));
		wcscpy_s(sTypeSize,_T(""));
		wcscpy_s(sArticle,_T(""));
		wcscpy_s(sManufacture,_T(""));
		wcscpy_s(sUnit,_T("шт"));
		wcscpy_s(sValue,_T(""));
		wcscpy_s(sMass,_T(""));
		wcscpy_s(sCommit,_T(""));

		if (wcscmp(sType,_T(""))!=0) wcscpy_s(sTypeSize,sType);
		if ((wcscmp(sType,_T(""))!=0)&&(wcscmp(sSize,_T(""))!=0)) wcscat_s(sTypeSize,_T("-"));
		if (wcscmp(sSize,_T(""))!=0) wcscat_s(sTypeSize,sSize);

		GetAtt(pEnt,TagPos,sPos);
		GetAtt(pEnt,TagManufacture,sManufacture);
		GetAtt(pEnt,TagMass,sMass);
		GetAtt(pEnt,TagArticle,sArticle);
		GetAtt(pEnt,TagCommit,sCommit);
		setParam1(1, TypeInt);
		setParam2(0, TypeInt);
		if ((wcscmp(sPos,_T(""))==0)&&
			(wcscmp(sName,_T(""))==0)&&
			(wcscmp(sTypeSize,_T(""))==0)&&
			(wcscmp(sArticle,_T(""))==0)&&
			(wcscmp(sManufacture,_T(""))==0)&&
			(wcscmp(sMass,_T(""))==0)&&
			(wcscmp(sCommit,_T(""))==0)
			) getBlockName(pEnt,sName);
		sEnt=pEnt;
		entityList.append(sEnt);
		return true;
	}
	else return false;
}


bool SPEC::setAtribToEnt(AcDbEntity* pEnt, ACHAR* tag, ACHAR  *pVal)
{


		Acad::ErrorStatus es;


		AcDbObjectPointer<AcDbBlockReference> pBlkRef(pEnt->id(),AcDb::kForWrite);
		if ((es = pBlkRef.openStatus()) != Acad::eOk) {
			acutPrintf(_T("\nОшибка открытия BlockReference: %s"), acadErrorStatusText(es)); return false;
		}
		AcDbObjectIterator *pAttrIter = pBlkRef->attributeIterator();
		if (pAttrIter) {
			for (pAttrIter->start();!pAttrIter->done();pAttrIter->step()) {
				AcDbObjectId objAttrId = pAttrIter->objectId();
				AcDbObjectPointer<AcDbAttribute> pAttr(objAttrId,AcDb::kForWrite);

				if ((es = pAttr.openStatus()) == Acad::eOk) {
					//
					// Здесь можно получить информацию об атрибуте
					//

					if (wcscmp(tag,pAttr->tagConst())==0) {


						pAttr->setTextString(pVal);
						return true;
					}

				} else {
					acutPrintf(_T("\nНе удалось открыть атрибут блока! Ошибка: %s", LPCTSTR(acadErrorStatusText(es))));
				}
			}
		}

	}



bool SPEC::setAtribListToEnt()
{
	for each (AcDbEntity* pEnt in entityList)
	{
		setAtribToEnt(pEnt, TagPos, sPos);
		setAtribToEnt(pEnt, TagName, sName);
		setAtribToEnt(pEnt, TagType, sType);
		setAtribToEnt(pEnt, TagSize, sSize);
		setAtribToEnt(pEnt, TagArticle, sArticle);
		setAtribToEnt(pEnt, TagManufacture, sManufacture);
		setAtribToEnt(pEnt, TagMass, sMass);
		setAtribToEnt(pEnt, TagCommit, sCommit);
	}
	return true;
}

bool SPEC::getBlockName(AcDbEntity* pEnt , ACHAR *pName)
{

	Acad::ErrorStatus es;


	AcDbObjectPointer<AcDbBlockReference> pBlkRef(pEnt->id(),AcDb::kForRead);
	if ((es = pBlkRef.openStatus()) != Acad::eOk) {
		acutPrintf(_T("\nОшибка открытия BlockReference: %s"), acadErrorStatusText(es)); return false;
	}
	AcDbBlockTableRecordPointer pBTR(pBlkRef->blockTableRecord(),AcDb::kForRead);
	if ((es = pBTR.openStatus()) != Acad::eOk) {
		acutPrintf(_T("\nОшибка открытия BlockTableRecord: %s"), acadErrorStatusText(es)); return false;
	}
	const ACHAR* sBTRName = NULL; pBTR->getName(sBTRName); 
	if (sBTRName) wcscpy_s(pName,512,sBTRName);

	
	///DynBlock

	


	AcDbDynBlockReference dynblkRef(pEnt->id());
	if (!dynblkRef.isDynamicBlock()) {

		acutPrintf(_T("\nЭто не динамический блок!")); return true;

	}

	AcDbBlockTableRecordPointer pDynBTR(dynblkRef.dynamicBlockTableRecord(),AcDb::kForRead);

	if ((es = pDynBTR.openStatus()) != Acad::eOk) {

		acutPrintf(_T("\nОшибка открытия Dyn BlockTableRecord: %s"), acadErrorStatusText(es)); return true;

	}

	const ACHAR* sDynBTRName = NULL; pDynBTR->getName(sDynBTRName); 

	if (sDynBTRName) wcscpy_s(pName,512,sDynBTRName);







	return true;
}


void SPEC:: add(double pSizeA,
				double pSizeB,
				bool pThisRect,
				double pLength,
				double pSwectangle,
				double pSizeA2,
				double pSizeA3
				)
{
	SizeA=pSizeA;
	SizeB=pSizeB;
	ThisRect=pThisRect;
	Length=pLength;
	SizeA2=pSizeA2;
	SizeA3=pSizeA3;
	Swectangle=pSwectangle;
	Area=0;

}


SPEClist::SPEClist(void)
{

}

SPEClist::~SPEClist(void)
{

}


void SPEClist::append(SPEC line)
{
	// 	acutPrintf(_T("\n123"));
	// 	print();
	if (specList.logicalLength()==0)
	{
		specList.append(line);
		return;
	}

	length=specList.logicalLength();
	int i = 0;
	while (i<length)
	{
		int currentStatus=checkRelevations(specList[i],line);
		if (currentStatus==Equal)
		{
			specList[i].param1=specList[i].param1+line.param1;
			specList[i].param2=specList[i].param2+line.param2;
			specList[i].entityList.append(line.sEnt);
			return;
		}

		if (currentStatus==Larger)
		{
			specList.insertAt(i,line);
			return;
		}
		i++;
	}
	specList.append(line);
}

int SPEClist::checkRelevations(SPEC param1, SPEC param2)
{
	double parameters1[6],parameters2[6];;
	parameters1[0]=param1.status;
	parameters2[0]=param2.status;

	parameters1[1]=param1.SizeA;
	parameters2[1]=param2.SizeA;

	parameters1[2]=param1.SizeB;
	parameters2[2]=param2.SizeB;

	parameters1[3]=param1.SizeA2;
	parameters2[3]=param2.SizeA2;

	parameters1[4]=param1.SizeA3;
	parameters2[4]=param2.SizeA3;

	parameters1[5]=param1.Swectangle;
	parameters2[5]=param2.Swectangle;
	int i=0;

	while (i<6)
	{
		if (parameters1[i]<parameters2[i])
		{
			return Less;
		}
		if (parameters1[i]>parameters2[i])
		{
			return Larger;
		}
		i++;
	}


	return Equal;

}

void SPEClist::print()
{
	length=specList.logicalLength();
	for (int i=0; i<length;i++)
	{
		specList[i].printResult();
	}
}





void SPEClist::printSPDSForm(AcGePoint3d &cent)
{
	//int columnswidth[9]={2000,13000,6000,3500,4500,2000,2000,2500,4000};
	int columnswidth[10]={0, 2000,15000,21000,24500,29000,31000,33000,35500,39500};
	int columndistanse[6]={2000,15000,29000,31000,33000,35500};
	int rowhight=800;
	int otstupX=100;
	int otstupY=150;
	int length = specList.logicalLength();
	AcGePoint3d curcnt, pos1, pos2, pos3,pos4,pos5,pos6,pos7;
	curcnt=cent;



	//zagolovok
	pos1=AcGePoint3d(curcnt.x+columndistanse[0]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos2=AcGePoint3d(curcnt.x+columndistanse[1]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos3=AcGePoint3d(curcnt.x+columndistanse[2]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos4=AcGePoint3d(curcnt.x+columndistanse[3]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos5=AcGePoint3d(curcnt.x+columndistanse[4]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos6=AcGePoint3d(curcnt.x+columndistanse[5]+otstupX,curcnt.y+otstupY,curcnt.z);
	printText(pos1,_T("Наименование"));
	printText(pos2,_T("Размер"));
	printText(pos3,_T("Единица"));
	printText(pos4,_T("Кол-во"));
	printText(pos5,_T("Единица2"));
	printText(pos6,_T("Кол-во"));
	curcnt=AcGePoint3d(curcnt.x,curcnt.y-rowhight,curcnt.z);

	//print all table text
	for (int i =0; i<length;i++)
	{
		pos1=AcGePoint3d(curcnt.x+columndistanse[0]+otstupX,curcnt.y+otstupY,curcnt.z);
		pos2=AcGePoint3d(curcnt.x+columndistanse[1]+otstupX,curcnt.y+otstupY,curcnt.z);
		pos3=AcGePoint3d(curcnt.x+columndistanse[2]+otstupX,curcnt.y+otstupY,curcnt.z);
		pos4=AcGePoint3d(curcnt.x+columndistanse[3]+otstupX,curcnt.y+otstupY,curcnt.z);
		pos5=AcGePoint3d(curcnt.x+columndistanse[4]+otstupX,curcnt.y+otstupY,curcnt.z);
		pos6=AcGePoint3d(curcnt.x+columndistanse[5]+otstupX,curcnt.y+otstupY,curcnt.z);
		specList[i].setParamChars();
		printText(pos1,specList[i].name);
		printText(pos2,specList[i].lable);
		printText(pos3,specList[i].unit1);
		printText(pos4,specList[i].param1char);
		printText(pos5,specList[i].unit2);
		printText(pos6,specList[i].param2char);
		curcnt=AcGePoint3d(curcnt.x,curcnt.y-rowhight,curcnt.z);
	}

	/// total
	double summlenght=0, summArea=0;
	ACHAR  sA[512];

	for (int i =0; i<length;i++)
	{
		//summlenght+=specList[i].param1;
		summArea+=specList[i].param2;
	}
	acdbRToS(summArea,2,2,sA);
	//pos1=AcGePoint3d(curcnt.x+columndistanse[0]+otstupX,curcnt.y+otstupY,curcnt.z);
	//pos2=AcGePoint3d(curcnt.x+columndistanse[1]+otstupX,curcnt.y+otstupY,curcnt.z);
	//pos3=AcGePoint3d(curcnt.x+columndistanse[2]+otstupX,curcnt.y+otstupY,curcnt.z);
	//pos4=AcGePoint3d(curcnt.x+columndistanse[3]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos5=AcGePoint3d(curcnt.x+columndistanse[4]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos6=AcGePoint3d(curcnt.x+columndistanse[5]+otstupX,curcnt.y+otstupY,curcnt.z);
	printText(pos5,_T("Итого:"));
	//printText(pos2,_T("Размер"));
	//printText(pos3,_T("Единица"));
	//printText(pos4,_T("Кол-во"));
	//printText(pos5,_T("Единица2"));
	printText(pos6,sA);
	curcnt=AcGePoint3d(curcnt.x,curcnt.y-rowhight,curcnt.z);

	///print table

	double TableLenght=39500;
	double Hight=length*800;
	//vertical Lines

	AcGePoint3d start,end;
	for each (int c in columnswidth)
	{
		start=AcGePoint3d(cent.x+c,cent.y+rowhight,cent.z);
		end=AcGePoint3d(cent.x+c,cent.y-rowhight*(length+1),cent.z);
		printLine(start,end);
	}
	//horizontal Lines

	for (int i =-1; i<length+2;i++)
	{
		start=AcGePoint3d(cent.x,cent.y-rowhight*i,cent.z);
		end=AcGePoint3d(cent.x+TableLenght,cent.y-rowhight*i,cent.z);
		printLine(start,end);
	}
	cent=AcGePoint3d(cent.x,cent.y-rowhight*(length+3),cent.z);
	print();
	acutPrintf(_T("\nИтого м2: %s"),sA);
}

void SPEClist::printText( AcGePoint3d cent, const ACHAR * pAchar )
{
	AcDbDatabase *db=acdbHostApplicationServices()->workingDatabase();

	AcDbObjectId tId=db->textstyle();
	///
	AcDbText *text1 = new AcDbText (cent, pAchar,tId,250,0 );

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

}

void SPEClist::printLine( AcGePoint3d start, AcGePoint3d end )
{
	AcDbDatabase *db=acdbHostApplicationServices()->workingDatabase();

	AcDbObjectId tId=db->textstyle();
	///
	AcDbLine *pEnt = new AcDbLine (start,end);

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable,
		AcDb::kForRead);

	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,AcDb::kForWrite);
	pBlockTable->close();
	pEnt->setLineWeight(AcDb::kLnWt015);
	AcDbObjectId retId = AcDbObjectId::kNull;
	pBlockTableRecord->appendAcDbEntity(retId, pEnt);
	pBlockTableRecord->close();
	pEnt->close();
	//
}


bool SPEClist::printToExel(CMSExcel* m_msExcel,long &idx)
{
	


	
	int length = specList.logicalLength();
	ACHAR*col1={L"A"};
	ACHAR*col2={L"B"};
	ACHAR*col3={L"C"};
	ACHAR*col4={L"D"};
	ACHAR*col5={L"E"};
	ACHAR*col6={L"F"};
	ACHAR*col7={L"G"};
	ACHAR*col8={L"H"};
	ACHAR*col9={L"I"};

	//m_msExcel->SetExcelCellFormat(L"A1:i20000",L"Text");



	m_msExcel->printExelText(col2,idx,_T("Наименование"));
	m_msExcel->printExelText(col3,idx,_T("Размер"));
	m_msExcel->printExelText(col6,idx,_T("Единица"));
	m_msExcel->printExelText(col7,idx,_T("Кол-во"));
	m_msExcel->printExelText(col8,idx,_T("Единица2"));
	m_msExcel->printExelText(col9,idx,_T("Кол-во"));


 acedSetStatusBarProgressMeter(_T("Экспорт данных в Excel"),0,length);
	idx++;
	//print all table text
	for (int i =0; i<length;i++)
	{

		 acedSetStatusBarProgressMeterPos( i);
		specList[i].setParamChars();

		m_msExcel->printExelText(col2,idx,specList[i].name);
		m_msExcel->printExelText(col3,idx,specList[i].lable);
		m_msExcel->printExelText(col6,idx,specList[i].unit1);
		m_msExcel->printExelText(col7,idx,specList[i].param1char);
		m_msExcel->printExelText(col8,idx,specList[i].unit2);
		m_msExcel->printExelText(col9,idx,specList[i].param2char);



		idx++;
	}
		acedRestoreStatusBar();

	/// total
	double summlenght=0, summArea=0;
	ACHAR  sA[512];

	for (int i =0; i<length;i++)
	{
		//summlenght+=specList[i].param1;
		summArea+=specList[i].param2;
	}
	acdbRToS(summArea,2,2,sA);

	m_msExcel->printExelText(col8,idx,_T("Итого:"));
	m_msExcel->printExelText(col9,idx,sA);

	idx++;

	return true;
}





SpecWithAttrlist::SpecWithAttrlist(void)
{

}

SpecWithAttrlist::~SpecWithAttrlist(void)
{

}



int SpecWithAttrlist::checkRelevations(SPEC param1, SPEC param2)
{
	int ret;
	ret=checkCharRelevations(param1.sPos,param2.sPos);
	if(ret==Equal) ret=checkCharRelevations(param1.sName,param2.sName);
	if(ret==Equal) ret=checkCharRelevations(param1.sType,param2.sType);
	if(ret==Equal) ret=checkCharRelevations(param1.sSize,param2.sSize);
	if(ret==Equal) ret=checkCharRelevations(param1.sArticle,param2.sArticle);
	if(ret==Equal) ret=checkCharRelevations(param1.sManufacture,param2.sManufacture);
	if(ret==Equal) ret=checkCharRelevations(param1.sMass,param2.sMass);
	if(ret==Equal) ret=checkCharRelevations(param1.sCommit,param2.sCommit);
	return ret;
}

int SpecWithAttrlist::checkCharRelevations(ACHAR * param1, ACHAR * param2)
{
	if(wcscmp(param1,param2)<0) return Less;
	if(wcscmp(param1,param2)==0) return Equal;
	if(wcscmp(param1,param2)>0) return Larger;
}

void SpecWithAttrlist::printSPDSForm(AcGePoint3d &cent)
{

	//int columnswidth[9]={2000,13000,6000,3500,4500,2000,2000,2500,4000};
	int columnswidth[10]={0, 2000,15000,21000,24500,29000,31000,33000,35500,39500};
	int columndistanse[9]={0,2000,15000,21000,24500,29000,31000,33000,35500};
	int rowhight=800;
	int otstupX=100;
	int otstupY=150;
	int length = specList.logicalLength();
	AcGePoint3d curcnt, pos1, pos2, pos3,pos4,pos5,pos6,pos7,pos8,pos9;
	curcnt=cent;



	//zagolovok
	pos1=AcGePoint3d(curcnt.x+columndistanse[0]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos2=AcGePoint3d(curcnt.x+columndistanse[1]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos3=AcGePoint3d(curcnt.x+columndistanse[2]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos4=AcGePoint3d(curcnt.x+columndistanse[3]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos5=AcGePoint3d(curcnt.x+columndistanse[4]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos6=AcGePoint3d(curcnt.x+columndistanse[5]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos7=AcGePoint3d(curcnt.x+columndistanse[6]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos8=AcGePoint3d(curcnt.x+columndistanse[7]+otstupX,curcnt.y+otstupY,curcnt.z);
	pos9=AcGePoint3d(curcnt.x+columndistanse[8]+otstupX,curcnt.y+otstupY,curcnt.z);
	printText(pos1,_T("Позиция"));
	printText(pos2,_T("Наименование"));
	printText(pos3,_T("Типоразмер"));
	printText(pos4,_T("Артикул"));
	printText(pos5,_T("Изготовитель"));
	printText(pos6,_T("Единица"));
	printText(pos7,_T("Кол-во"));
	printText(pos8,_T("Масса"));
	printText(pos9,_T("Примечание"));
	curcnt=AcGePoint3d(curcnt.x,curcnt.y-rowhight,curcnt.z);

	//print all table text
	for (int i =0; i<length;i++)
	{

		pos1=AcGePoint3d(curcnt.x+columndistanse[0]+otstupX,curcnt.y+otstupY,curcnt.z);
		pos2=AcGePoint3d(curcnt.x+columndistanse[1]+otstupX,curcnt.y+otstupY,curcnt.z);
		pos3=AcGePoint3d(curcnt.x+columndistanse[2]+otstupX,curcnt.y+otstupY,curcnt.z);
		pos4=AcGePoint3d(curcnt.x+columndistanse[3]+otstupX,curcnt.y+otstupY,curcnt.z);
		pos5=AcGePoint3d(curcnt.x+columndistanse[4]+otstupX,curcnt.y+otstupY,curcnt.z);
		pos6=AcGePoint3d(curcnt.x+columndistanse[5]+otstupX,curcnt.y+otstupY,curcnt.z);
		pos7=AcGePoint3d(curcnt.x+columndistanse[6]+otstupX,curcnt.y+otstupY,curcnt.z);
		pos8=AcGePoint3d(curcnt.x+columndistanse[7]+otstupX,curcnt.y+otstupY,curcnt.z);
		pos9=AcGePoint3d(curcnt.x+columndistanse[8]+otstupX,curcnt.y+otstupY,curcnt.z);
		//specList[i].setParamChars();
		//printText(pos1,specList[i].name);
		specList[i].setParamChars();
		if(wcscmp(specList[i].sPos,_T(""))!=0) printText(pos1,specList[i].sPos);
		if(wcscmp(specList[i].sName,_T(""))!=0) printText(pos2,specList[i].sName);
		if(wcscmp(specList[i].sTypeSize,_T(""))!=0) printText(pos3,specList[i].sTypeSize);
		if(wcscmp(specList[i].sArticle,_T(""))!=0) printText(pos4,specList[i].sArticle);
		if(wcscmp(specList[i].sManufacture,_T(""))!=0) printText(pos5,specList[i].sManufacture);
		if(wcscmp(specList[i].sUnit,_T(""))!=0) printText(pos6,specList[i].sUnit);

		printText(pos7,specList[i].param1char);
		if(wcscmp(specList[i].sMass,_T(""))!=0) printText(pos8,specList[i].sMass);
		if(wcscmp(specList[i].sCommit,_T(""))!=0) printText(pos9,specList[i].sCommit);
		curcnt=AcGePoint3d(curcnt.x,curcnt.y-rowhight,curcnt.z);
	}

	// 		/// total
	// 		double summlenght=0, summArea=0;
	// 		ACHAR  sA[512];
	// 
	// 		for (int i =0; i<length;i++)
	// 		{
	// 			//summlenght+=specList[i].param1;
	// 			summArea+=specList[i].param2;
	// 		}
	// 		acdbRToS(summArea,2,2,sA);
	// 		//pos1=AcGePoint3d(curcnt.x+columndistanse[0]+otstupX,curcnt.y+otstupY,curcnt.z);
	// 		//pos2=AcGePoint3d(curcnt.x+columndistanse[1]+otstupX,curcnt.y+otstupY,curcnt.z);
	// 		//pos3=AcGePoint3d(curcnt.x+columndistanse[2]+otstupX,curcnt.y+otstupY,curcnt.z);
	// 		//pos4=AcGePoint3d(curcnt.x+columndistanse[3]+otstupX,curcnt.y+otstupY,curcnt.z);
	// 		pos5=AcGePoint3d(curcnt.x+columndistanse[4]+otstupX,curcnt.y+otstupY,curcnt.z);
	// 		pos6=AcGePoint3d(curcnt.x+columndistanse[5]+otstupX,curcnt.y+otstupY,curcnt.z);
	// 		printText(pos5,_T("Итого:"));
	// 		//printText(pos2,_T("Размер"));
	// 		//printText(pos3,_T("Единица"));
	// 		//printText(pos4,_T("Кол-во"));
	// 		//printText(pos5,_T("Единица2"));
	// 		printText(pos6,sA);
	// 		curcnt=AcGePoint3d(curcnt.x,curcnt.y-rowhight,curcnt.z);

	///print table

	double TableLenght=39500;
	double Hight=length*800;
	//vertical Lines

	AcGePoint3d start,end;
	for each (int c in columnswidth)
	{
		start=AcGePoint3d(cent.x+c,cent.y+rowhight,cent.z);
		end=AcGePoint3d(cent.x+c,cent.y-rowhight*(length+1),cent.z);
		printLine(start,end);
	}
	//horizontal Lines

	for (int i =-1; i<length+2;i++)
	{
		start=AcGePoint3d(cent.x,cent.y-rowhight*i,cent.z);
		end=AcGePoint3d(cent.x+TableLenght,cent.y-rowhight*i,cent.z);
		printLine(start,end);
	}
	cent=AcGePoint3d(cent.x,cent.y-rowhight*(length+3),cent.z);
	print();
	//acutPrintf(_T("\nИтого м2: %s"),sA);
}


bool SpecWithAttrlist::printToExel(CMSExcel* m_msExcel,long &idx)
{

	ACHAR*col1={L"A"};
	ACHAR*col2={L"B"};
	ACHAR*col3={L"C"};
	ACHAR*col4={L"D"};
	ACHAR*col5={L"E"};
	ACHAR*col6={L"F"};
	ACHAR*col7={L"G"};
	ACHAR*col8={L"H"};
	ACHAR*col9={L"I"};

	
	int length = specList.logicalLength();


	m_msExcel->printExelText(col1,idx,_T("Позиция"));
	m_msExcel->printExelText(col2,idx,_T("Наименование"));
	m_msExcel->printExelText(col3,idx,_T("Типоразмер"));
	m_msExcel->printExelText(col4,idx,_T("Артикул"));
	m_msExcel->printExelText(col5,idx,_T("Изготовитель"));
	m_msExcel->printExelText(col6,idx,_T("Единица"));
	m_msExcel->printExelText(col7,idx,_T("Кол-во"));
	m_msExcel->printExelText(col8,idx,_T("Масса"));
	m_msExcel->printExelText(col9,idx,_T("Примечание"));

	int status;
	 acedSetStatusBarProgressMeter(_T("Экспорт данных в Excel"),0,length);
	 
	idx++;
	//print all table text
	for (int i =0; i<length;i++)
	{

		specList[i].setParamChars();

		
	
	 acedSetStatusBarProgressMeterPos( i);
	
		if(wcscmp(specList[i].sPos,_T(""))!=0) m_msExcel->printExelText(col1,idx,specList[i].sPos);
		if(wcscmp(specList[i].sName,_T(""))!=0) m_msExcel->printExelText(col2,idx,specList[i].sName);
		if(wcscmp(specList[i].sTypeSize,_T(""))!=0) m_msExcel->printExelText(col3,idx,specList[i].sTypeSize);
		if(wcscmp(specList[i].sArticle,_T(""))!=0) m_msExcel->printExelText(col4,idx,specList[i].sArticle);
		if(wcscmp(specList[i].sManufacture,_T(""))!=0) m_msExcel->printExelText(col5,idx,specList[i].sManufacture);
		if(wcscmp(specList[i].sUnit,_T(""))!=0) m_msExcel->printExelText(col6,idx,specList[i].sUnit);
		if(wcscmp(specList[i].param1char,_T(""))!=0) m_msExcel->printExelText(col7,idx,specList[i].param1char);
		if(wcscmp(specList[i].sMass,_T(""))!=0) m_msExcel->printExelText(col8,idx,specList[i].sMass);
		if(wcscmp(specList[i].sCommit,_T(""))!=0) m_msExcel->printExelText(col9,idx,specList[i].sCommit);



		idx++;
	}


	acedRestoreStatusBar();

	idx++;

	return true;
}

void SpecWithAttrlist::print()
{
	length=specList.logicalLength();
	for (int i=0; i<length;i++)
	{
		specList[i].printResultChar();
	}
}


