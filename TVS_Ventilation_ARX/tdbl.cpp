#include "StdAfx.h"
#include "tdbl.h"
ACRX_DEFINE_MEMBERS(AcDbDoubleClickEdit);
tdbl::tdbl(void)
{
}

tdbl::~tdbl(void)
{
}

void tdbl::finishEdit(void)
{

}
void tdbl::startEdit(AcDbEntity *pEnt, AcGePoint3d pt)
{
	//AcApDocument *pDoc=acDocManager->curDocument();
// 	TVS_Pipe *pPipe;
// 	//TVS_TRANS *pTrans;
// 	//TVS_WYE *pWye;
// 	TVS_TAP *pTap;
//acutPrintf(_T("edit"));
	// Cast the AcDbEntity pointer to AcDbPolyline	
// 	if(pEnt->isKindOf(TVS_Pipe::desc()) == Adesk::kTrue)
// 	{
// 		AcApDocument *pDoc=acDocManager->curDocument();
// 		acDocManager->lockDocument(pDoc,AcAp::kWrite);
// 	//acutPrintf(_T("TVS_CHANGE"));
// 		Change(pEnt);
// 		acDocManager->unlockDocument(pDoc);
// 		//acedCommand(RTPICKS,RTSTR,"TVS_CHANGE");
// 		
// 	}
// 
// 	if(pEnt->isKindOf(TVS_WYE::desc()) == Adesk::kTrue)
// 	{
// 		AcApDocument *pDoc=acDocManager->curDocument();
// 		acDocManager->lockDocument(pDoc,AcAp::kWrite);
// 
// 		Change(pEnt);
// 
// 		acDocManager->unlockDocument(pDoc);
// 	}
// 
// 	if(pEnt->isKindOf(TVS_TRANS::desc()) == Adesk::kTrue)
// 	{
// 		AcApDocument *pDoc=acDocManager->curDocument();
// 		acDocManager->lockDocument(pDoc,AcAp::kWrite);
// 
// 		Change(pEnt);
// 
// 		acDocManager->unlockDocument(pDoc);
// 	}
// 
// 	if(pEnt->isKindOf(TVS_TAP::desc()) == Adesk::kTrue)
// 	{
// 		AcApDocument *pDoc=acDocManager->curDocument();
// 		acDocManager->lockDocument(pDoc,AcAp::kWrite);
// 
// 		Change(pEnt);
// 
// 		acDocManager->unlockDocument(pDoc);
// 	}


	if(pEnt->isKindOf(TVS_Entity::desc()) == Adesk::kTrue)
	{


		//from object id to selection set
		ads_name ss, ename, eName, eName2;

		//create a selection set
		acedSSAdd( NULL, NULL, ss );

		//get the ads name from objectID
		acdbGetAdsName( ename, pEnt->id() );

		//add the selected entity ads name to selection set
		acedSSAdd( ename, ss, ss );

		acedSSName(ss,0,eName);
		//select with grip
		acedSSSetFirst( ss, NULL );

		acedSSFree( ss );


		AcDbObjectId id;
			acdbGetObjectId(id,eName);
			AcDbEntity * pEnt2;
			acdbOpenAcDbEntity(pEnt2,id,AcDb::kForWrite);
		AcApDocument *pDoc=acDocManager->curDocument();
		acDocManager->lockDocument(pDoc,AcAp::kWrite);





		Change(ss);

		acDocManager->unlockDocument(pDoc);
	}


	
}
void tdbl::InitApplication()
{
	tdbl *pdbl1 = new tdbl;
	tdbl *pdbl2 = new tdbl;
	tdbl *pdbl3 = new tdbl;
	tdbl *pdbl4 = new tdbl;

	TVS_Pipe::desc()->addX(AcDbDoubleClickEdit::desc(),pdbl1);
	TVS_TRANS::desc()->addX(AcDbDoubleClickEdit::desc(),pdbl2);
	TVS_WYE::desc()->addX(AcDbDoubleClickEdit::desc(),pdbl3);
	TVS_TAP::desc()->addX(AcDbDoubleClickEdit::desc(),pdbl4);
}