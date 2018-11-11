#pragma once
#include "TVSCommand.h"
class TVSCommandSpecification :
	public TVSCommand
{
public:
	TVSCommandSpecification();
	virtual ~TVSCommandSpecification();
	virtual void processId(const AcDbObjectId &objId);
	//virtual void execute(void);
};

