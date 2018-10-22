#pragma once
#include "MleaderController.h"
#include "TVSPropertyController.h"
#include "TVSPropertySpecController.h"

class TVSController
{
public:
	//return pointer to instance of controller
	static TVSController* get();
	MleaderController mLeaderController;
	TVSPropertyController tvsPropertyController;
	TVSPropertySpecController tvsPropertySpecController;
	TVSController();
	virtual ~TVSController();
};

