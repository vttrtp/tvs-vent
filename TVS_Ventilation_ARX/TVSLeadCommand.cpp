#include "stdafx.h"
#include "TVSLeadCommand.h"
#include "SPEC.h"
#include <dbmleader.h>
#include "Func.h"
#include "dgMLeadProperty.h"
#include "MleaderController.h"
#include "TVSController.h"
using namespace func;

TVSCommandLead::TVSCommandLead(void)
{

}


TVSCommandLead::~TVSCommandLead(void)
{
}





void TVSCommandLead::createMLeader(const CString &message, const AcGePoint3d &ptStart, const AcGePoint3d &ptEnd, const AcDbObjectId &id)
{

	AcDbMText *mText = new AcDbMText();
	AcGeVector3d vec;
	if (ptStart.x < ptEnd.x)
	{
		vec = AcGeVector3d(0, 1, 0);
	}
	else
	{
		vec = AcGeVector3d(0, -1, 0);
	}



	//mText->getColumnHeight(0,texth);
	//mText->getColumnWidth(textw);
	mText->setLocation(ptEnd);

	mText->setColorIndex(AcDb::kByLayer);
	mText->setContents(message.GetString());
	//mText->setLineWeight(AcDb::kLnWt025);

	//мультивыноска
	AcDbMLeader *pEnt = new AcDbMLeader();

	//pEnt->setLineWeight(AcDb::kLnWt025);
	//pEnt->setColor(pEnt1->color());

	int i;
	pEnt->setContentType(AcDbMLeaderStyle::kMTextContent);
	pEnt->addLeader(i);
	pEnt->addLeaderLine(ptStart, i);
	pEnt->addLastVertex(i, ptEnd);
	//pEnt->setEnableDogleg(false);
	//pEnt->setDoglegLength(10);
	//pEnt->setDoglegDirection(i,vec);

	pEnt->setMText(mText);

	PostToModelSpace(pEnt);
	//PostToModelSpace(mText);
	{
		AcDbObjectPointer<AcDbMLeader>pEnt1(pEnt->id(), AcDb::kForWrite);
		if (pEnt1.openStatus() == Acad::eOk)
		{
			pEnt1->setLastVertex(i, ptEnd);
			//pEnt1->mtext()->setColorIndex(-1);
		}

	}

	//set xDataProperty
	MleaderController ctrl;
	ctrl.setObjectId(pEnt->id(), id);
	ctrl.setFormat(pEnt->id(), Settings::get()->mLeader.getFormatForEntity(id).GetString());

	//test
	AcDbObjectId obId;
	ctrl.getObjectId(pEnt->id(), obId);
	acutPrintf(L"objectId %ld\n", obId);

	CString tf;
	ctrl.getFormat(pEnt->id(), tf);
	acutPrintf(L"format %s\n", tf);

}

void TVSCommandLead::ShowLeadDlg()
{
	dgMLeadProperty dg;
	dg.DoModal();
}

void TVSCommandLead::execute(void)
{
	// 	 AllocConsole();
	// 	 freopen("CONOUT$", "w", stdout);
	if (!check()) return;
	int pstatus;
	AcGePoint3d pCut;
	ads_name vozd1, eName;
	ACHAR handle[17];
	ads_point pt1, pt2;

	AcDbEntity *pEnt1 = NULL;
	AcDbObjectId id;

	AcGeLine3d Line;
	bool ft = false;

	int Astat;
	bool  Astat2 = false;

	CString resultMessage;
	ACHAR resultss[512];

	MleaderController mCtrl;
	while (ft == false)
	{

		Astat2 = false;
		while (Astat2 == false)
		{
			Astat2 = true;
			acedInitGet(RSG_NONULL, _T("Настройки Н y"));
			Astat = acedEntSel(_T("\nВыберете Блок или Воздуховод или Настройки  [Н]: "), vozd1, pt1);
			switch (Astat)
			{
			case RTCAN:
				return;
				break;
			case RTKWORD:
				acedGetInput(resultss);
				break;
			}

			if (Astat == RTKWORD)
			{
				ShowLeadDlg();
			}

		}

		pCut = asPnt3d(pt1);
		{
			if (acdbGetObjectId(id, vozd1) != eOk) continue;

			if (TVSController::get()->tvsPropertyController.checkProperty(id)) {
				ft = true;
			}
			{
				AcDbObjectPointer<AcDbEntity>pEnt1(id, AcDb::kForRead);


				if (pEnt1.openStatus() == Acad::eOk)
				{
					TVS_Pipe * Pipi1;
					if ((Pipi1 = TVS_Pipe::cast(pEnt1)) != NULL)
					{
						Line.set(Pipi1->FirstPoint, Pipi1->LastPoint);
						pCut = Line.closestPointTo(pCut);
						ft = true;
						pstatus = 1;
					}

					TVS_TAP * Tapie;
					if ((Tapie = TVS_TAP::cast(pEnt1)) != NULL)
					{
						pCut = Tapie->MiddlePoint;
						ft = true;
						pstatus = 2;
					}

					TVS_WYE *wyie;
					if ((wyie = TVS_WYE::cast(pEnt1)) != NULL)
					{
						Line.set(wyie->pA1, wyie->pA3);
						pCut = Line.closestPointTo(pCut);

						ft = true;
						pstatus = 3;
					}

					TVS_TRANS * Transie;
					if ((Transie = TVS_TRANS::cast(pEnt1)) != NULL)
					{
						Line.set(Transie->FirstPoint, Transie->LastPoint);
						pCut = Line.closestPointTo(pCut);

						ft = true;
						pstatus = 4;
					}

					AcDbBlockReference * br;
					if ((br = AcDbBlockReference::cast(pEnt1)) != NULL)
					{

						CString atrType;
						if (mCtrl.GetAtt(br, TagType, atrType) && mCtrl.GetAtt(br, TagSize, atrType))
						{


							pCut = AcGePoint3d(asPnt3d(pt1));
							ft = true;
							pstatus = 5;
						}
					}

				}
				else {
					acutPrintf(_T("\nОбьект заблокирован"));
				}
			}
			if (ft) {

				mCtrl.getStringMessage(id, Settings::get()->mLeader.getFormatForEntity(id), resultMessage);
			}

		}
	}
	pt1[0] = pCut.x;
	pt1[1] = pCut.y;
	pt1[2] = pCut.z;
	if (acedGetPoint(pt1, _T("\nУкажите 2 точку:"), pt2) == RTCAN)
		return;
	createMLeader(resultMessage, pCut, asPnt3d(pt2), id);
	return;
}

