#pragma once
#include "TVS_TAP.h"
#include "MLeaderSettings.h"
#include "TVSPropertySettings.h"

#define globalElevUp 1
#define globalElevmid 2
#define globalElevdown 3
#define M_PI 3.14159265358979323846
#define dCONTINUE 0
#define dCONNECT 1
#define dSIZE 2
#define dParal 1
#define dPerpend 0
#define dPeresec 2
#define dNeperesec 3
#define dComplanar 4
#define dObshaiztochka 5
#define isBlocked 0
#define isNoTVS 1
#define isTVS_Pipe 2
#define isTVS_TAP 3
#define isTVS_TRANS 4
#define isTVS_Wye 5
#define TVSEnt1isGrose 0
#define TVSEnt2isGrose 1
#define TVSEntitiesisSame 2

#define TagPos _T("ПОЗИЦИЯ")
#define TagName _T("ИМЯ")
#define TagType _T("ТИП")
#define TagSize _T("РАЗМЕР")
#define TagArticle _T("АРТИКУЛ")
#define TagManufacture _T("ПРОИЗВОДИТЕЛЬ")
#define TagMass _T("МАССА")
#define TagCommit _T("ПРИМЕЧАНИЕ")



static double globSizeA = 150;
static double globSizeB = 150;
static bool globRound = false;
static bool globalWipeout = false;
static bool globalGrani = false;
static bool global1D = false;
static double ftSizeB = 100;
static double ftSizeroundA = 160;
static double ftLengthp = 150;
static int ftTransType = 1;
static int globalMlead = 1;
static int globalRadiusTypeRound = RadiusTypeRound_RadiusSpecific;
static int globalRadiusTypeRect = RadiusTypeRect_RadiusConstant;
static int globalTypeRoundTap = 1;
static int globalTapForm = Form_Direct;
static int globalTransType = 0;
static double globalTapRadiusVariableParameter = 1;
static double globalTapRadiusConst = 150;
static double globalFlow = 0;
static double globalLengthTr = 300;
static double globalLengthW = 50;
static double globalElevMid = 0;
static double globalElev = globalElevdown;
static double globalAxis = 90;
static int globalDuctType = DuctTypeStill;
static double globalWipeoutLength = 50;

class Settings
{
public:
	Settings(void);
	virtual ~Settings(void);
	static Settings* get();
	TVSPropertySettings tvsProperty;
	MLeaderSettings mLeader;
};


