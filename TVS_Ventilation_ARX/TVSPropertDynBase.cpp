#include "stdafx.h"
#include "TVSPropertDynBase.h"
#include "TVSController.h"


BOOL TVSPropertyDynBase::checkEnabled(IUnknown *&pUnk)
{
	AcDbObjectId objId;
	{
		CComQIPtr<IAcadBaseObject> pObj(pUnk);
		pObj->GetObjectId(&objId);
	}
	if (TVSController::get()->tvsPropertyController.checkProperty(objId)) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
