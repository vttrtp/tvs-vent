#pragma once
#include "TVS_Command.h"
class TVSCommandPropertyManager :
	public TVS_Command
{
public:
	TVSCommandPropertyManager();
	virtual ~TVSCommandPropertyManager();
	virtual void execute(void);
};

