
#include "StdAfx.h"
#include "SPEC.h"
#include <cmath>
#include<iostream>
using namespace std;
#define d "%%c"
#define None 0
#define Pipe 1
#define Tap 2
#define Trans 3
#define Wye 4
#define TypeInt 0
#define TypeDouble1 1
#define TypeDouble2 2
#define Less 0
#define Equal 1
#define Larger 2
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
	status=None;
	SizeA=0;
	SizeB=0;
	SizeA2=0;
	SizeA3=0;
	Swectangle=0;
	
	
		#pragma region Pipe
	if (acdbOpenAcDbEntity(pEnt,pEnt->id(),AcDb::kForRead)==eOk)
	{
		if(pPipe = TVS_Pipe::cast(pEnt))
		{
			status=Pipe;
			SizeA=pPipe->get_SizeA();
			SizeB=pPipe->get_SizeB();
			Length=pPipe->get_Length();
			setUnit1(_T("м"));
			setUnit2(_T("м2"));

		if (SizeB==0) 
			{
				setName(_T("Воздуховод круглый"));
				setLable(_T(d));
				appendLable(SizeA);
				Area=Length*M_PI*SizeA/1000000;
					
			}
		else 
			{ 
			setName(_T("Воздуховод прямоугольный"));
			setLable(max(SizeA,SizeB));
			appendLable(_T("x"));
			appendLable(min(SizeA,SizeB));
			Area=Length*(SizeB+SizeA)*2/1000000;
			}
		setParam1(Length/1000, TypeDouble1);
		setParam2(Area, TypeDouble2);
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
				setLable(_T(d));
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
				appendLable(_T(d));
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
				setLable(_T(d));
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
				appendLable(_T(d));
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
		if (status!=None) printResult();
		pEnt->close();
		return true;
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

// int SPEC::toInt( const ACHAR * pAchar )
// {
// 
// }


const ACHAR * SPEC::toChar( double val )
{
	const ACHAR* str=new ACHAR[512];
	 ACHAR buffer[512];
acdbRToS(val,2,2,buffer);
str=buffer;
return buffer;
}


void SPEC::setParamChars()
{
	acdbRToS(param1,2,param1Type,param1char);
	acdbRToS(param2,2,param2Type,param2char);
}


double SPEC::sCircle(double diam)
{
	return M_PI*diam*diam/4;
}

double SPEC::lCircle(double diam)
{
	return M_PI*diam;
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
	if (specList.length()==0)
	{
		specList.append(line);
	}
	for (int i=0; i<specList.length();i++)
	{
		if (line.status,specList[i].status)
	}
	
}

int SPEClist::checkRelevations(SPEC param1, SPEC param2)
{
	if (param1.status==param2.status)
	{
		if (param1.SizeA==param2.SizeA)
		{
			if (param1.SizeB==param2.SizeB)
			{

			}
		}
	}
	if (param1>param2)
	{
		return Larger;
	}
	
		return Less;
	
}
