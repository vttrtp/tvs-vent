
#include "StdAfx.h"
#include "SPEC.h"
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
		if (pPipe->This1D) 
			{
				setName(_T("Воздуховод круглый"));
				setLable()
				Area=Length*M_PI*SizeA;
			}
		else 
			{ 
			setName(_T("Воздуховод прямоугольный"));
			Area=Length*SizeB*SizeA;
			}
		}
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

void SPEC::setUnit(const ACHAR * pAchar)
{
	wcscpy_s(unit,pAchar);
}

void SPEC::setUnit2(const ACHAR * pAchar)
{
	wcscpy_s(unit2,pAchar);
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

