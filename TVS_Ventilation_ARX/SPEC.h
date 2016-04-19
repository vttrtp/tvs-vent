#pragma once
#include "Resource.h"
#include "dbmain.h"
#include "rxmfcapi.h"
#include <vector>
using namespace std;
#include "StdAfx.h"
#include "Func.h"
#include "../TVS_Ventilation_DBX/TVS_Entity.h"
#include "../TVS_Ventilation_DBX/TVS_Tap.h"
#include "../TVS_Ventilation_DBX/TVS_Pipe.h"
#include "../TVS_Ventilation_DBX/TVS_Wye.h"
#include "../TVS_Ventilation_DBX/TVS_TRANS.h"
#include "MSExcel.h"

#define TagPos _T("ПОЗИЦИЯ")
#define TagName _T("ИМЯ")
#define TagType _T("ТИП")
#define TagSize _T("РАЗМЕР")
#define TagArticle _T("АРТИКУЛ")
#define TagManufacture _T("ПРОИЗВОДИТЕЛЬ")
#define TagMass _T("МАССА")
#define TagCommit _T("ПРИМЕЧАНИЕ")



class SPEC
{
private: 
	void setAcharType( int val);
	ACHAR achartype[512];

public:
		ACHAR d[512];
			ACHAR grad[512];
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
void printResultChar ();
const ACHAR * toChar(double val);
void setParamChars();
double sCircle(double diam);
double lCircle(double diam);


bool GetAtt(AcDbEntity* pEnt, ACHAR* tag, ACHAR *pVal);
ACHAR sPos[512];
ACHAR sName[512];
ACHAR sTypeSize[512];
ACHAR sType[512];
ACHAR sSize[512];
ACHAR sArticle[512];
ACHAR sManufacture[512];
ACHAR sUnit[512];
ACHAR sValue[512];
ACHAR sMass[512];
ACHAR sCommit[512];
bool addBlock(AcDbEntity * pEnt);

static bool getBlockName(AcDbEntity* pEnt , ACHAR *pName);
};

class SPEClist
{
	public:
		SPEClist(void);
		~SPEClist(void);
		AcArray <SPEC> specList;
		void append (SPEC line);
		int length;
		virtual int checkRelevations(SPEC param1, SPEC param2);

		void print();
		
		virtual void printSPDSForm(AcGePoint3d &cent);
		virtual void printText(AcGePoint3d cent, const ACHAR * pAchar);
	static	void printLine(AcGePoint3d start, AcGePoint3d end);
	virtual bool printToExel(CMSExcel* m_msExcel,long &idx);
	
};

class SpecWithAttrlist : public SPEClist
{
public:
	SpecWithAttrlist(void);
	~SpecWithAttrlist(void);
/*void append (SPEC line);*/
int checkRelevations(SPEC param1, SPEC param2); //First vs two
int checkCharRelevations(ACHAR * param1, ACHAR * param2);
void printSPDSForm(AcGePoint3d &cent);
bool printToExel(CMSExcel* m_msExcel,long &idx);
void print();
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