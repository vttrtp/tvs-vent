#pragma once
#include "TVS_Pipe.h"
#include "TVS_TRANS.h"
#include "TVS_WYE.h"
#include "TVS_TAP.h"
#include "Settings.h"

class TVS_Command
{
public:
	TVS_Command(void);
	virtual ~TVS_Command(void);
	virtual bool check(void){ return true;};
	virtual void execute(void){};
};

