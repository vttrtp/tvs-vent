#pragma once
#include "TVS_Pipe.h"
#include "TVS_TRANS.h"
#include "TVS_WYE.h"
#include "TVS_TAP.h"
#include "Settings.h"

class TVSCommand
{
public:
	TVSCommand(void);
	virtual ~TVSCommand(void);
	virtual bool check(void) { return true; };
	virtual void processId(const AcDbObjectId &objId);
	virtual void execute(void);
};
