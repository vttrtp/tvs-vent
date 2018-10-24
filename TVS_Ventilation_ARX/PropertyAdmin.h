#pragma once
#include "TVSPropertyPositionDyn.h"
#include "TVSPropertyNameDyn.h"
#include "TVSPropertyTypeDyn.h"
#include "TVSPropertyManufacturerDyn.h"
#include "TVSPropertySizeDyn.h"
#include "TVSPropertyArticleDyn.h"
#include "TVSPropertyUnitsDyn.h"
#include "TVSPropertyCountDyn.h"
#include "TVSPropertyMassDyn.h"
#include "TVSPropertyNoteDyn.h"

class PropertyAdmin
{
	static bool m_bInitialized;
	static AcRxClass* m_pClass;
public:
	static void initialize();
	static void uninitialize();
	static bool isInitialized() { return m_bInitialized; }
};