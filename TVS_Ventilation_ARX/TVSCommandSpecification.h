#pragma once
#include "TVSCommand.h"
class TVSCommandSpecification :
	public TVSCommand
{
public:
	TVSCommandSpecification();
	virtual ~TVSCommandSpecification();
	virtual void execute(void);
};
