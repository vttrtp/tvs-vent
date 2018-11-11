#pragma once
#include "TVSCommand.h"
class TVSCommandAddProperties :
	public TVSCommand
{
public:
	TVSCommandAddProperties();
	virtual ~TVSCommandAddProperties();
	virtual void processId(const AcDbObjectId &objId);
	//virtual void execute(void);
};

