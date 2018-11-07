#pragma once
#include <arxHeaders.h>
class TVSPropertyDynBase {
public:
	TVSPropertyDynBase() {};
	virtual ~TVSPropertyDynBase() {};
	BOOL checkEnabled(IUnknown *&pUnk);
};