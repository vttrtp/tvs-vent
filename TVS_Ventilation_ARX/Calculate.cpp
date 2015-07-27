#include "stdafx.h"
#include "Calculate.h"
#include "Constants.h"

TVS_Calculate::TVS_Calculate(void)
{
}


TVS_Calculate::~TVS_Calculate(void)
{
}

double TVS_Calculate::getI(double &SizeA, double &SizeB, double &Flow)
{
	double v,S,L,dekv,Pd,Re,Lambda;
	bool ThisRound;
	if ((SizeA==0) || (Flow==0))
		return 0;
	Flow=abs(Flow);
	ThisRound=roundCheck(SizeA,SizeB);
	if (ThisRound==true)
	{
		S=SizeA*SizeA*M_PI/4/1000/1000;
		L=Flow/3600;
		dekv=SizeA/1000;
	} 
	else
	{
		S=SizeA*SizeB/1000/1000;
		L=Flow/3600;
		dekv=2*SizeA*SizeB/(SizeA+SizeB)/1000;
	}
	v=L/S;
	Pd=1.2*v*v/2;
	Re=v*dekv/0.000014;
	Lambda=0.11*pow((0.1/dekv/1000+68/Re),0.25);
	return (Pd*Lambda/dekv);
}

double TVS_Calculate::getdP(double &SizeA, double &SizeB, double &Flow, double &Length)
{
	double v,S,L,dekv,Pd,Re,Lambda,i;
	bool ThisRound;
	Flow=abs(Flow);
	Length=abs(Length);
	if ((SizeA==0) || (Flow==0) || (Length==0))
		return 0;
	ThisRound=roundCheck(SizeA,SizeB);
	if (ThisRound==true)
	{
		S=SizeA*SizeA*M_PI/4/1000/1000;
		L=Flow/3600;
		dekv=SizeA/1000;
	} 
	else
	{
		S=SizeA*SizeB/1000/1000;
		L=Flow/3600;
		dekv=2*SizeA*SizeB/(SizeA+SizeB)/1000;
	}
	v=L/S;
	Pd=1.2*v*v/2;
	Re=v*dekv/0.000014;
	Lambda=0.11*pow((0.1/dekv/1000+68/Re),0.25);
	i=Pd*Lambda/dekv;
	return (i*Length/1000);
	
}

double TVS_Calculate::getSpeed(double &SizeA, double &SizeB, double &Flow)
{

	double Speed;
	bool ThisRound;
	ThisRound=roundCheck(SizeA,SizeB);
	if ((SizeA==0) || (Flow==0))
		return 0;
	if (ThisRound==true)
	{
		Speed=Flow/(3600*3.14*((SizeA)/1000)*((SizeA)/1000)/4);

	}
	else
	{
		Speed=Flow/(3600*(SizeA/1000)*(SizeB/1000));

	}
	return Speed;

}

double TVS_Calculate::getFlow(double &SizeA, double &SizeB, double &Speed)
{
	double pflow;
	bool ThisRound;
	if ((SizeA==0) || (Speed==0))
		return 0;
	
	ThisRound=roundCheck(SizeA,SizeB);

	if (ThisRound==true)
	{
		pflow=Speed*(3600*3.14*((SizeA)/1000)*((SizeA)/1000)/4);

	}
	else
	{
		pflow=Speed*(3600*(SizeA/1000)*(SizeB/1000));

	}
return pflow;
}

bool TVS_Calculate::roundCheck(double &SizeA, double &SizeB)
{
	if (SizeB==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
