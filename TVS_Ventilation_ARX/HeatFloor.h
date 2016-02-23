#pragma once
#include "StdAfx.h"

class HeatFloor
{
public:
	AcArray <HFPoint> HFPoints;
	HeatFloor(void);
	~HeatFloor(void);
};

class HFPoint
{
public:
	HFPoint();
	~HFPoint();
	AcGePoint3dArray points;

private:

};

