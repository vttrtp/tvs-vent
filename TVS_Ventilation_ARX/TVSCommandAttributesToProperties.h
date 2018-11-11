#pragma once
#include "TVSCommand.h"
class TVSCommandAttributesToProperties :
	public TVSCommand
{
public:
	TVSCommandAttributesToProperties();
	virtual ~TVSCommandAttributesToProperties();
	virtual void execute(void);
};

