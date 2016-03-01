#pragma once
#include "Resource.h"
#include "dbmain.h"
#include "rxmfcapi.h"
#include <vector>
using namespace std;
#include "StdAfx.h"
#include "Func.h"





class HFPoint
{
public:
	HFPoint(void);
	~HFPoint(void);
//	AcGePoint3dArray points;



};

class HeatFloor
{
public:
	int indexofrecursion;
	int indexofrecursion2;
	int indexofrecursion3;
	AcDbPolyline * loop;
	AcGePoint3d startPoint;
	AcDbPolyline * contour;
	double step;
	AcArray<AcDbPolyline* > polySet;
	void setPolySet();
	void setContour(AcDbPolyline*pln);
	void setStartPoint(const AcGePoint3d &pnt);
	HeatFloor(void);
	~HeatFloor(void);
	AcArray <HFPoint> HFPoints;
	void drawHFLoop();
	void getOffset(AcDbPolyline *pLine);
	void drawOffset(AcDbPolyline *pLine);
	void GetParallelLinesAPredeterminedDistance(AcGePoint3d const &L1S,AcGePoint3d const &L1E, double const &distance,AcGePoint3d &L2S,AcGePoint3d &L2E,AcGePoint3d &L3S,AcGePoint3d &L3E);
	bool getSimilarInsideFigureAtDistance(const AcGePoint3dArray  &arr,double const &distance,AcGePoint3dArray &result);
    void getMidPoint(AcGePoint3d const &pt1,AcGePoint3d const &pt2,AcGePoint3d &midPnt);
	bool pt_in_polygon(const AcGePoint3d &test,const AcGePoint3dArray &polygon);

private:
	
	int getInsideOffset( AcDbPolyline* offset, AcDbVoidPtrArray &result);
	bool getMaxOffset( AcDbVoidPtrArray offset, AcDbPolyline * &result);
};