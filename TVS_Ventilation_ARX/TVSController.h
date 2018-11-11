#pragma once
#include "TVSPropertyController.h"


class TVSController
{
public:
	//return pointer to instance of controller
	static TVSController* get();
	TVSPropertyController tvsPropertyController;
	TVSController();
	virtual ~TVSController();
};

