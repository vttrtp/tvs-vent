#pragma once
#include "TVSCommand.h"
class TVSCommandExcelSpecification :
	public TVSCommand
{
public:
	TVSCommandExcelSpecification();
	virtual ~TVSCommandExcelSpecification();
	virtual void processId(const AcDbObjectId &objId);
	//virtual void execute(void);
};

