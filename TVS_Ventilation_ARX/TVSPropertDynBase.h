#pragma once
class TVSPropertyDynBase {
public:
	TVSPropertyDynBase() {};
	virtual ~TVSPropertyDynBase() {};
	BOOL checkEnabled() {
		return TRUE;
	}
};