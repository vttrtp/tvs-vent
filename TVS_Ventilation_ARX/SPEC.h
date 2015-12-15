#pragma once
#include "Resource.h"
#include "dbmain.h"
#include "rxmfcapi.h"
#include <vector>
using namespace std;
#include "StdAfx.h"
#include "../TVS_Ventilation_DBX/TVS_Entity.h"
#include "../TVS_Ventilation_DBX/TVS_Tap.h"
#include "../TVS_Ventilation_DBX/TVS_Pipe.h"
#include "../TVS_Ventilation_DBX/TVS_Wye.h"
#include "../TVS_Ventilation_DBX/TVS_TRANS.h"
class SPEC
{
private: 
	void setAcharType( int val);
	ACHAR achartype[512];

public:
	SPEC(void);
	~SPEC(void);
ACHAR name[512];
ACHAR lable [512];
ACHAR param1char [512];
ACHAR param2char [512];
ACHAR unit1 [512];
ACHAR unit2 [512];
double SizeA;
double SizeB;
bool ThisRect;
double SizeA2;
double SizeA3;
double param1;
void setParam1 (double param,int type);
void setParam2 (double param,int type);

double param2;

int param1Type;
int param2Type;
int status;

double Length;
double Length2;
double Swectangle;
double Area;
void add(double pSizeA,
double pSizeB,
bool pThisRect,
double pLength,
double pSwectangle=0,
double pSizeA2=0,
double pSizeA3=0
);
bool add (AcDbEntity * pEnt);
void setName (const ACHAR * pName);
void setLable (const ACHAR * pAchar);
void setLable (double val);
void appendLable (const ACHAR * pAchar);
void appendLable (double par);
void setUnit1 (const ACHAR * pAchar);
void setUnit2 (const ACHAR * pAchar);
int toInt(const ACHAR * pAchar);
void printResult ();
const ACHAR * toChar(double val);
void setParamChars();
double sCircle(double diam);
double lCircle(double diam);

};

class SPEClist
{
	public:
		SPEClist(void);
		~SPEClist(void);
		AcArray <SPEC> specList;
		void append (SPEC line);
		int length;
		int checkRelevations(SPEC param1, SPEC param2);
		void print();
		
		void printSPDSForm(AcGePoint3d cent);
		void printText(AcGePoint3d cent, const ACHAR * pAchar);
		void printLine(AcGePoint3d start, AcGePoint3d end);
};

// class TVSForm
// {
// public:
// 	TVSForm(void);
// 	~TVSForm(void);
// 	int columnsQuantity;
// 	int rowsQuantity;
// 	AcArray <int> columnsWidth;
// 	AcArray <ACHAR> Headlines;
// 	AcArray <TVSRow> Rows;
// 	int HeadlineHight;
// 	int RowHight;
// 	//double columnswidth[9]={2000,13000,6000,3500,4500,2000,2000,2500,4000};
	
// };
// 
// class TVSRow
// {
// public:
// 	TVSRow(void);
// 	~TVSRow(void);
// 	AcArray <ACHAR> cells;

// };