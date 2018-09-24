#include "stdafx.h"
#include "TVSLeadCommand.h"
#include "SPEC.h"
#include <dbmleader.h>
#include "Func.h"
#include "mLeadPropertyDg.h"

using namespace func;

TVS_Lead_Command::TVS_Lead_Command(void)
{

}


TVS_Lead_Command::~TVS_Lead_Command(void)
{
}


bool TVS_Lead_Command::GetAtt(AcDbBlockReference* pBr, const CString& tag, CString& valueStr)
{
	Acad::ErrorStatus es;

	AcDbObjectIterator *pAttrIter = pBr->attributeIterator();
	if (!pAttrIter) return false;
	for (pAttrIter->start();!pAttrIter->done();pAttrIter->step()) {
		AcDbObjectId objAttrId = pAttrIter->objectId();
		AcDbObjectPointer<AcDbAttribute> pAttr(objAttrId,AcDb::kForRead);

		if ((es = pAttr.openStatus()) != Acad::eOk) continue;

		if (tag == pAttr->tagConst()) {
			valueStr.SetString(pAttr->textStringConst());
			return true;
		}
	}
	return false;
}


bool TVS_Lead_Command::GetStringProperty(AcDbEntity* pEnt, CString &stringText)
{
	TVS_Entity *ent;
	if ((ent = TVS_Entity::cast(pEnt)) != NULL) {
		return GetEntityStringProperty(ent,stringText);
	};
	
	AcDbBlockReference * br;
	if (( br= AcDbBlockReference::cast(pEnt)) != NULL ){
		return GetBlockStringProperty(br,stringText);
	};

}

bool TVS_Lead_Command::GetEntityStringProperty(TVS_Entity* pEnt, CString &stringText)
{
	CString templateText = Settings::get()->mLeader.pipeLeader;
	CString curTemp;
	bool inTemp=false;
	int length = templateText.GetLength();
	for (int i=0 ;i<length;i++)
	{
		if(templateText[i] == L'['){
			curTemp = L"";
			inTemp=true;
			continue;
		}

		if(templateText[i] == L']'){
			CString strVal;
			GetEntityStringPropertyByName( pEnt,curTemp, strVal);
			stringText+=strVal;
			curTemp = L"";
			inTemp=false;
			continue;
		}
		if(inTemp) {
			curTemp+=templateText[i];

		}else{
			stringText+=templateText[i];
		}
	}

	return true;
}

bool TVS_Lead_Command::GetEntityStringPropertyByName(TVS_Entity* pEnt, const CString &stringTemplate, CString &stringText)
{

	if(stringTemplate==L"N")
	{
		ACHAR * layerName = pEnt->layer();
		stringText = layerName;
	}else if(stringTemplate==L"L"){
		stringText.Format(L"%d",pEnt->get_Flow());
	}else if(stringTemplate==L"V"){
		//stringText.Format(L"%d",pEnt->get_Speed());
	}else if(stringTemplate==L"D"){
		pEnt->getSizeString(stringText);
	}else if(stringTemplate==L"P"){
		//pEnt->getSizeString(stringText);
	}

	return true;
}

bool TVS_Lead_Command::GetBlockStringProperty(AcDbBlockReference* pBr, CString &stringText)
{
	CString templateText = Settings::get()->mLeader.blockLeader;
		
	CString curTemp;
	bool inTemp=false;
	int length = templateText.GetLength();
	for (int i=0 ;i<length;i++)
	{
		if(templateText[i] == L'['){
			curTemp = L"";
			inTemp=true;
			continue;
		}

		if(templateText[i] == L']'){
			CString strVal;
			GetBlockStringPropertyByName( pBr,curTemp, strVal);
			stringText+=strVal;
			curTemp = L"";
			inTemp=false;
			continue;
		}
		if(inTemp) {
			curTemp+=templateText[i];
		
		}else{
		stringText+=templateText[i];
		}
		
		
	}

	return true;
}

bool TVS_Lead_Command::GetBlockStringPropertyByName(AcDbBlockReference* pBr, const CString &stringTemplate, CString &stringText)
{
	if(stringTemplate==L"N")
	{
		ACHAR * layerName = pBr->layer();
		stringText = layerName;
		return true;
	}else if(stringTemplate==L"BN"){
		AcDbObjectPointer<AcDbBlockTableRecord> pBTR(pBr->blockTableRecord(),AcDb::kForRead);
		ACHAR * pName;
		pBTR->getName(pName);
		stringText = pName;
		return true;
	}else {
		return  GetAtt(pBr,stringTemplate,stringText);
	}
}

void TVS_Lead_Command::createMLeader(const CString &message, const AcGePoint3d &ptStart, const AcGePoint3d &ptEnd)
{

	AcDbMText *mText=new AcDbMText();
	AcGeVector3d vec;
	if (ptStart.x<ptEnd.x)
	{
		vec=AcGeVector3d(0,1,0);
	}
	else
	{
		vec=AcGeVector3d(0,-1,0);
	}

	

	//mText->getColumnHeight(0,texth);
	//mText->getColumnWidth(textw);
	mText->setLocation(ptEnd);

	mText->setColorIndex(AcDb::kByLayer);
	mText->setContents(message.GetString());
	//mText->setLineWeight(AcDb::kLnWt025);

	//мультивыноска
	AcDbMLeader *pEnt=new AcDbMLeader();

	//pEnt->setLineWeight(AcDb::kLnWt025);
	//pEnt->setColor(pEnt1->color());

	int i;
	pEnt->setContentType(AcDbMLeaderStyle::kMTextContent);
	pEnt->addLeader(i);
	pEnt->addLeaderLine(ptStart,i);
	pEnt->addLastVertex(i,ptEnd);
	//pEnt->setEnableDogleg(false);
	//pEnt->setDoglegLength(10);
	//pEnt->setDoglegDirection(i,vec);

	pEnt->setMText(mText);
	
	PostToModelSpace(pEnt);
	//PostToModelSpace(mText);

	AcDbObjectPointer<AcDbMLeader>pEnt1 (pEnt->id(), AcDb::kForWrite);
	if (pEnt1.openStatus () == Acad::eOk)
	{
		pEnt1->setLastVertex(i,ptEnd);
		//pEnt1->mtext()->setColorIndex(-1);
	}
}

void TVS_Lead_Command::ShowLeadDlg()
{
	mLeadPropertyDg dg;
	dg.DoModal();
}

void TVS_Lead_Command::execute(void)
 {
// 	 AllocConsole();
// 	 freopen("CONOUT$", "w", stdout);
	if(!check()) return;
	int pstatus;
	AcGePoint3d pCut;
	ads_name vozd1, eName;
	ACHAR handle[17];
	ads_point pt1,pt2;

	AcDbEntity *pEnt1 = NULL;
	AcDbObjectId id;

	AcGeLine3d Line;
	bool ft=false;

	int Astat;
	bool  Astat2=false;

	CString resultMessage;
	ACHAR resultss[512];
	while (ft==false)
	{

		Astat2=false;
		while (Astat2==false)
		{
			Astat2=true;
			acedInitGet(RSG_NONULL, _T("Настройки Н y"));
			Astat=acedEntSel (_T("\nВыберете Блок или Воздуховод или Настройки  [Н]: "), vozd1,pt1) ;
			switch (Astat)
			{
			case RTCAN:
				return;
				break;
			case RTKWORD:
				acedGetInput(resultss);
				break;
			}

			if (Astat==RTKWORD)
			{
				ShowLeadDlg();
			}

		}

		pCut=asPnt3d(pt1);

		if (acdbGetObjectId(id,vozd1)!=eOk) continue;
		AcDbObjectPointer<AcDbEntity>pEnt1 (id, AcDb::kForRead);
		if (pEnt1.openStatus () == Acad::eOk)
		{
			TVS_Pipe * Pipi1;
			if ((Pipi1 = TVS_Pipe::cast(pEnt1)) != NULL )
			{	
				Line.set(Pipi1->FirstPoint,Pipi1->LastPoint);
				pCut=Line.closestPointTo(pCut);
				ft=true;
				pstatus=1;
			}

			TVS_TAP * Tapie;
			if ( (Tapie = TVS_TAP::cast(pEnt1)) != NULL )
			{	
				pCut=Tapie->MiddlePoint;
				ft=true;
				pstatus=2;
			}

			TVS_WYE *wyie;
			if ( (wyie = TVS_WYE::cast(pEnt1)) != NULL )
			{	
				Line.set(wyie->pA1,wyie->pA3);
				pCut=Line.closestPointTo(pCut);
					
				ft=true;
				pstatus=3;
			}

			TVS_TRANS * Transie;
			if ( (Transie = TVS_TRANS::cast(pEnt1)) != NULL )
			{	
				Line.set(Transie->FirstPoint,Transie->LastPoint);
				pCut=Line.closestPointTo(pCut);
					
				ft=true;
				pstatus=4;
			}
					
			AcDbBlockReference * br;
			if ( ( br= AcDbBlockReference::cast(pEnt1)) != NULL )
			{	
		
				CString atrType;
				if(GetAtt(br,TagType,atrType)&&GetAtt(br,TagSize,atrType))
				{


					pCut=AcGePoint3d(asPnt3d(pt1));
					ft=true;
					pstatus=5;
				}
			}

			if (ft){
				GetStringProperty(pEnt1,resultMessage);
			}

		}


		else {
			acutPrintf(_T("\nОбьект заблокирован"));
		}	
	}

	pt1[0]=pCut.x;
	pt1[1]=pCut.y;
	pt1[2]=pCut.z;
	if(acedGetPoint(pt1,_T("\nУкажите 2 точку:"),pt2)==RTCAN)
		return;
	createMLeader(resultMessage,pCut,asPnt3d(pt2));
	return;
}
