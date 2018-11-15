#pragma once
#include "TVSCommand.h"
class TVSCommandLeadRecalculate :
	public TVSCommand
{
public:
	TVSCommandLeadRecalculate();
	virtual ~TVSCommandLeadRecalculate();
	virtual void execute(void);
};
