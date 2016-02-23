#pragma once
#include "stdafx.h"
#include "HeatFloor.h"


bool HeatFloor::pt_in_polygon( const AcGePoint3d &test,const AcGePoint3dArray &polygon )
{

	static const int q_patt[2][2]= { {0,1}, {3,2} };

	if (polygon.logicalLength()<3) return false;

	
	AcGePoint3d pred_pt=polygon.at(0); 
	pred_pt.x-=test.x;
	pred_pt.y-=test.y;

	int pred_q=q_patt[pred_pt.y<0][pred_pt.x<0];

	int w=0;

	for each (AcGePoint3d cur_pt in polygon)

	{
		

		cur_pt.x-=test.x;
		cur_pt.y-=test.y;

		int q=q_patt[cur_pt.y<0][cur_pt.x<0];

		switch (q-pred_q)
		{
		case -3:++w;break;
		case 3:--w;break;
		case -2:if(pred_pt.x*cur_pt.y>=pred_pt.y*cur_pt.x) ++w;break;
		case 2:if(!(pred_pt.x*cur_pt.y>=pred_pt.y*cur_pt.x)) --w;break;
		}

		pred_pt = cur_pt;
		pred_q = q;

	}

	return w!=0;
}

HeatFloor::HeatFloor(void)
{
}


HeatFloor::~HeatFloor(void)
{
}

HFPoint::HFPoint(void)
{
}

HFPoint::~HFPoint(void)
{
}



