
#include "StdAfx.h"
#include "SPEC.h"
#pragma once
SPEC::SPEC(void)
{
}

SPEC::~SPEC(void)
{
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