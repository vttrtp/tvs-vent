#include "stdafx.h"
#include "Settings.h"
Settings settings;

Settings::Settings(void)
{
}


Settings::~Settings(void)
{
}

Settings* Settings::get()
{
	return &settings;
}
