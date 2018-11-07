#include "StdAfx.h"
#include "resource.h"
#include "Func.h"
#include "tdbl.h"
#include "dbmleader.h"
#include "dgPipeSize.h"
#include "dgChangeZ.h"
#include "MSExcel.h"	
#include "HeatFloor.h"
#include <mmsystem.h>

//#import "acax20ENU.tlb" 
#include <rxmfcapi.h>
#include <axpnt3d.h>

void HeatFloor::drawHFLoop()
{

if (polySet.logicalLength()>0)
{
	for each (AcDbPolyline * var in polySet)
	{
		var->setClosed(true);
		drawEntity(var);
	}
}
}


void HeatFloor::getOffset(AcDbPolyline *pLine)
{

	AcDbVoidPtrArray offset;
	AcDbPolyline *pln=0;
	polySet.removeAll();
	getMaxStep(pLine);
	int idx=curStep/step;
	pln=pLine;
	for (int i=0;i<idx;i++)
	{
		indexofrecursion++;
		if(getInsideOffset(pln,offset)==false) return;
		//acutPrintf(_T("\n иру: %d"),getInsideOffset(pLine,offset));
		if(getMaxOffset(offset,pln)==false) return;

		polySet.append(pln);
		}


	
}
















void HeatFloor::drawOffset(AcDbPolyline *pLine)
{
	
	AcDbVoidPtrArray arr;
	pLine->getOffsetCurves(200,arr);
	
	indexofrecursion++;
		if(indexofrecursion>5000) return;
	for (long i=0;i<arr.logicalLength();i++)
	{
		AcDbPolyline *pPoly = NULL;
	
	pPoly = (AcDbPolyline*)(arr[i]);

	AcDbText pText;
	
	for (int j=0;j<pPoly->numVerts();j++)
	{
		AcDbText *pText=new AcDbText;
		ACHAR cNum[512];
		acdbRToS(j,2,0,cNum);
		pText->setTextString(cNum);
		pText->setHeight(50);
		AcGePoint2d pos;
		pPoly->getPointAt(j,pos);
		pText->setPosition(AcGePoint3d(pos.x,pos.y,0));
		drawEntity(pText);
	}
	 
	pPoly->setColorIndex(std::rand() % 255);
	func::drawEntity(pPoly);
	drawOffset(pPoly);
	}
}

void HeatFloor::GetParallelLinesAPredeterminedDistance( AcGePoint3d const &L1S,AcGePoint3d const &L1E, double const &distance,AcGePoint3d &L2S,AcGePoint3d &L2E,AcGePoint3d &L3S,AcGePoint3d &L3E )
{
// 	double X1,X2,Y1,Y2;
// 	X1=L1E.x-L1S.x;
// 	Y1=L1E.y-L1S.y;
// 	double Length=L1S.distanceTo(L1E);
// 	X2=Y1*distance/Length;
// 	Y2=X1*distance/Length;
// 	L2S=AcGePoint3d(L1S.x-X2,L1S.y+Y2,L1S.z);
// 	L2E=AcGePoint3d(L1E.x-X2,L1E.y+Y2,L1S.z);
// 	L3E=AcGePoint3d(L1E.x+X2,L1E.y-Y2,L1S.z);
// 	L3S=AcGePoint3d(L1S.x+X2,L1S.y-Y2,L1S.z);
	AcGeVector3d vect = AcGeVector3d(L1E.x-L1S.x,L1E.y-L1S.y,0);
	vect.normalize();
	AcGeVector3d vectRight,vectLeft;
	vect=vect*distance;
	vectRight=vect.rotateBy(M_PI/2,AcGeVector3d(0,0,1));
	vectLeft=vect.rotateBy(M_PI,AcGeVector3d(0,0,1));
	 	L2S=AcGePoint3d(L1S.x+vectRight.x,L1S.y+vectRight.y,L1S.z);
	 	L2E=AcGePoint3d(L1E.x+vectRight.x,L1E.y+vectRight.y,L1S.z);
		L3S=AcGePoint3d(L1S.x+vectLeft.x,L1S.y+vectLeft.y,L1S.z);
		L3E=AcGePoint3d(L1E.x+vectLeft.x,L1E.y+vectLeft.y,L1S.z);
}



bool HeatFloor::getSimilarInsideFigureAtDistance( const AcGePoint3dArray  &arr,double const &distance,AcGePoint3dArray &result )
{
	if (arr.logicalLength()<3) return false;

	AcGePoint3d L1S,L1E,L2S,L2E,L3S,L3E,intersectPoint;
	AcGeLine3d leftLine1, leftLine2,rightLine1, rightLine2,startLine,endLine;
	L1S=arr.at(arr.logicalLength()-1);
	startLine=AcGeLine3d(arr.at(arr.logicalLength()-1),arr.at(0));
	AcGeLine3d curLine;
		
		
// 		AcGePoint3d midPnt2,midPnt3;
// 		getMidPoint(L2S,L2E,midPnt2);
// 		getMidPoint(L3S,L3E,midPnt3);



	AcGePoint3dArray leftarr;
		AcGePoint3dArray  rightarr,insidearr;
		
		
		for (long i=0;i<arr.logicalLength();i++)
		{

			L1E=arr.at(i);

			GetParallelLinesAPredeterminedDistance(L1S,L1E, distance,L2S,L2E,L3S,L3E );
			rightLine1=AcGeLine3d(L2S,L2E);
			leftLine1=AcGeLine3d(L3S,L3E);
			L1S=arr.at(i);
			if (i!=(arr.logicalLength()-1)) L1E=arr.at(i+1);
			else L1E=arr.at(0);
			GetParallelLinesAPredeterminedDistance(L1S,L1E, distance,L2S,L2E,L3S,L3E );
			endLine=AcGeLine3d(L1S,L1E);
		
			rightLine2=AcGeLine3d(L2S,L2E);
			leftLine2=AcGeLine3d(L3S,L3E);
			if (rightLine1.intersectWith(rightLine2,intersectPoint)) {rightarr.append(intersectPoint); if(pt_in_polygon(intersectPoint,arr)) insidearr.append(intersectPoint);}
			if (leftLine1.intersectWith(leftLine2,intersectPoint)) {leftarr.append(intersectPoint);  if(pt_in_polygon(intersectPoint,arr)) insidearr.append(intersectPoint);}
		}

			AcGePoint3d tmp;
	AcDbPolyline *plineright=new AcDbPolyline;
	plineright->setClosed(true);
	for (long i=0;i<(rightarr.logicalLength());i++)
	{
		tmp=rightarr.at(i);
	plineright->addVertexAt(i,AcGePoint2d(tmp.x,tmp.y));
	}
	
	
	AcDbPolyline *plineleft=new AcDbPolyline;
	plineleft->setClosed(true);
	for (long i=0;i<(leftarr.logicalLength());i++)
	{
		tmp=leftarr.at(i);
		plineleft->addVertexAt(i,AcGePoint2d(tmp.x,tmp.y));
	}
	double area1,area2;
	plineright->getArea(area1);
	plineleft->getArea(area2);
	if (area2>area1) func::drawEntity(plineright);
	else func::drawEntity(plineleft);
	
	AcDbPolyline *plineinside=new AcDbPolyline;
	plineinside->setClosed(true);
	plineinside->setColorIndex(1);
	for (long i=0;i<(insidearr.logicalLength());i++)
	{
		tmp=insidearr.at(i);
		plineinside->addVertexAt(i,AcGePoint2d(tmp.x,tmp.y));
	}

	func::drawEntity(plineinside);
}

void HeatFloor::getMidPoint( AcGePoint3d const &pt1,AcGePoint3d const &pt2,AcGePoint3d &midPnt )
{
	midPnt=AcGePoint3d((pt1.x+pt2.x)/2,(pt1.y+pt2.y)/2,pt1.z);
}

bool HeatFloor::pt_in_polygon( const AcGePoint3d &test,const AcGePoint3dArray &polygon )
{

	static const int q_patt[2][2]= { {0,1}, {3,2} };

	if (polygon.logicalLength()<3) return false;

	
	AcGePoint3d pred_pt=polygon.at(polygon.logicalLength()-1); 
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

bool HeatFloor::getInsideOffset(AcDbPolyline* offset, AcDbVoidPtrArray &result)
{
	indexofrecursion1++;
	AcDbVoidPtrArray rightArrS, leftArrS;
	double pStep=curStep+step;
	Acad::ErrorStatus er,el;
	er=offset->getOffsetCurves(step,rightArrS);
	el=offset->getOffsetCurves(-step,leftArrS);

		AcDbVoidPtrArray rightArr, leftArr;
		
		er=offset->getOffsetCurves(pStep,rightArr);
		el=offset->getOffsetCurves(-pStep,leftArr);
		if ((rightArr.logicalLength()==0)&&(leftArr.logicalLength()==0)) return false;
		if (rightArr.logicalLength()==0){ result= rightArrS; return true;};
		if (leftArr.logicalLength()==0){ result= leftArrS; return true;};
		
	
	return -1;
}

bool HeatFloor::getMaxOffset( AcDbVoidPtrArray offset, AcDbPolyline * &result)
{
	

	if (offset.logicalLength()==0) return false;
	AcDbVoidPtrArray rightArr, leftArr;

	AcDbPolyline *pPoly = NULL;
indexofrecursion2++;
	for (long i=0;i<offset.logicalLength();i++)
	{
		indexofrecursion3++;

		pPoly = (AcDbPolyline*)(offset[i]);
		pPoly->getOffsetCurves((curStep-step),leftArr);
		pPoly->getOffsetCurves(-(curStep-step),rightArr);

		if ((rightArr.logicalLength()>0)&&(leftArr.logicalLength()>0))
		{
			curStep-=step;result=pPoly; return true;
		}

	}
	

}

bool HeatFloor::getMaxStep(const AcDbPolyline* offset)
{
	

	
	AcDbVoidPtrArray rightArrS, leftArrS;
	double pStep=step;
	Acad::ErrorStatus er,el;
	er=offset->getOffsetCurves(pStep,rightArrS);
	el=offset->getOffsetCurves(-pStep,leftArrS);

	for (int i=0; i<10000;i++)
	{
		AcDbVoidPtrArray rightArr, leftArr;
		indexofrecursion2++;
		er=offset->getOffsetCurves(pStep,rightArr);
		el=offset->getOffsetCurves(-pStep,leftArr);
		if ((rightArr.logicalLength()==0)&&(leftArr.logicalLength()==0)) return false;
		if (rightArr.logicalLength()==0){curStep=i*step; return true;};
		if (leftArr.logicalLength()==0){curStep=i*step;  return true;};
		pStep+=step;
	}



	return false;


}

void HeatFloor::setPolySet()
{
	/*AcArray<AcArray<AcDbPolyline >> polyTree;
	indexofrecursion=0;

	AcDbVoidPtrArray arr;
	contour->getOffsetCurves(step,arr);
	

	indexofrecursion++;
	if(indexofrecursion>5000) return;
	for (long i=0;i<arr.logicalLength();i++)
	{
		AcDbPolyline *pPoly = NULL;

		pPoly = (AcDbPolyline*)(arr[i]);

		AcDbText pText;

		for (int j=0;j<pPoly->numVerts();j++)
		{
			AcDbText *pText=new AcDbText;
			ACHAR cNum[512];
			acdbRToS(j,2,0,cNum);
			pText->setTextString(cNum);
			pText->setHeight(50);
			AcGePoint2d pos;
			pPoly->getPointAt(j,pos);
			pText->setPosition(AcGePoint3d(pos.x,pos.y,0));
			drawEntity(pText);
		}
}*/

	
}

void HeatFloor::setContour( AcDbPolyline*pln)
{
	contour=pln;
}

void HeatFloor::setStartPoint(const AcGePoint3d &pnt)
{
	contour->getClosestPointTo(pnt,startPoint);

}

HeatFloor::HeatFloor(void)
{
	indexofrecursion=0;
	indexofrecursion1=0;
	indexofrecursion2=0;
	indexofrecursion3=0;
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



