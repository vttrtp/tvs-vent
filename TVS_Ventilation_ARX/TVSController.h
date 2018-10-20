#pragma once
#include "MleaderController.h"
#include "TVSPropertyController.h"
class TVSController
{
public:
	//return pointer to instance of controller
	static TVSController* get();
	MleaderController mLeaderController;
	TVSPropertyController tvsPropertyController;
	TVSController();
	virtual ~TVSController();
};

