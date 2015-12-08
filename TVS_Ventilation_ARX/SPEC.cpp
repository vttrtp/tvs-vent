
#include "StdAfx.h"
#include "SPEC.h"
#define d "%%c"
#pragma once
SPEC::SPEC(void)
{
}

SPEC::~SPEC(void)
{
}

bool SPEC::add(AcDbEntity * pEnt)
{
	TVS_Pipe * pPipe;
	TVS_TAP * pTap;
	TVS_WYE * pWye;
	TVS_TRANS * pTrans;

	if (acdbOpenAcDbEntity(pEnt,pEnt->id(),AcDb::kForRead)==eOk)
	{
		if(pPipe = TVS_Pipe::cast(pEnt))
		{
			SizeA=pPipe->get_SizeA();
			SizeB=pPipe->get_SizeB();
			Length=pPipe->get_Length();
		if (SizeB==0) 
			{
				setName(_T("Воздуховод круглый"));
				setLable(_T(d));
				appendLable(SizeA);
				Area=Length*M_PI*SizeA/1000000;
				acutPrintf(_T("\n %s"), lable);
			
					acutPrintf(_T("\n Площадь:%10.3f"),Area);
					
			}
		else 
			{ 
			setName(_T("Воздуховод прямоугольный"));
			Area=Length*SizeB*SizeA;
			}
		}
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

void SPEC::setUnit(const ACHAR * pAchar)
{
	wcscpy_s(unit,pAchar);
}

void SPEC::setUnit2(const ACHAR * pAchar)
{
	wcscpy_s(unit2,pAchar);
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

