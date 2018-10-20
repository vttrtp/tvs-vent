#include "stdafx.h"
#include "TVSController.h"
TVSController ctrl;
TVSController* TVSController::get()
{
	return &ctrl;
}

TVSController::TVSController()
{
}


TVSController::~TVSController()
{
}
