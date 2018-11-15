#pragma once
#include "TVSCommand.h"
class TVSCommandExcelSpecification :
	public TVSCommand
{
public:
	TVSCommandExcelSpecification();
	virtual ~TVSCommandExcelSpecification();
	virtual void execute(void);
};

