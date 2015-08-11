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



	if(pEnt->isKindOf(TVS_Entity::desc()) == Adesk::kTrue)
	{


		// 		//from object id to selection set
		// 		ads_name ss, ename, eName, eName2;
		// 
		// 		//create a selection set
		// 		acedSSAdd( NULL, NULL, ss );
		// 
		// 		//get the ads name from objectID
		// 		AcDbObjectId id2=pEnt->id() ;
		// 		acdbGetAdsName( ename, id2 );
		// 
		// 		//add the selected entity ads name to selection set
		// 		acedSSAdd( ename, ss, ss );
		// 	
		// 		acedSSName(ss,0,eName);
		//		acedSSName(ss,1,eName2);
		//select with grip
		// 	//	acedSSSetFirst( ss, NULL );
		// 
		// 		
		// 

		//		AcDbObjectId id,  id3;
		//		acdbGetObjectId(id,eName);
		// 			AcDbEntity * pEnt2, *pEnt3;
		// 	
		// if(pEnt->upgradeOpen()==Acad::eOk)		
		// {
		// 	pEnt->close();
		// }	





		AcApDocument *pDoc=acDocManager->curDocument();
		acDocManager->lockDocument(pDoc,AcAp::kWrite);





		Change(pEnt);

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