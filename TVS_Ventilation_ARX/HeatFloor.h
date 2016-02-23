#pragma once
#include "StdAfx.h"







class HFPoint
{
public:
	HFPoint(void);
	~HFPoint(void);
	//AcGePoint3dArray points;



};

class HeatFloor
{
public:
	AcArray <HFPoint> HFPoints;

		bool pt_in_polygon(const AcGePoint3d &test,const AcGePoint3dArray &polygon);
	HeatFloor(void);
	~HeatFloor(void);
};