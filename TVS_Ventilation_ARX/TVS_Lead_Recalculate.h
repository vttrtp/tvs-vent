#pragma once
#include "TVS_Command.h"
class TVS_Lead_Recalculate :
	public TVS_Command
{
public:
	TVS_Lead_Recalculate();
	virtual ~TVS_Lead_Recalculate();
	virtual void execute(void);
};

