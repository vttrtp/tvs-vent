#pragma once
#include "TVSCommand.h"
class TVSCommandPropertyManager :
	public TVSCommand
{
public:
	TVSCommandPropertyManager();
	virtual ~TVSCommandPropertyManager();
	virtual void execute(void);
};

