﻿
#pragma once
#include "dbmain.h"
#include "../TVS_Ventilation_DBX/TVS_Pipe.h"
#include "../TVS_Ventilation_DBX/TVS_TAP.h"
#include "../TVS_Ventilation_DBX/TVS_WYE.h"
#include "../TVS_Ventilation_DBX/TVS_TRANS.h"
#include "SPEC.h"
#include "dgAllEdit.h"

#include "StdAfx.h"
#include "afxwin.h"
#include <iostream>
#include "afxdb.h"

#include "Settings.h"



namespace func {


	template <typename T>
	class FormParameter

	{
	public:
		FormParameter<T>();

		T parameter;
		int quantity;
		bool isSame;
		CString stringValue;
		void		addParameter(const T &pVal);
		bool	isCompare(const T &pVal);
		T getParameter();

	};





	// class TVS_Attribute {
	// 	public:
	// 	ACHAR  name[512];
	// 	ACHAR  model[512];
	// 	ACHAR  manufacture[512];
	// 	ACHAR  size[512];
	// 	addAtribute(*&fdsfdsf)
	// };

	


	void consoleprint(double It = 0, const ACHAR*format = _T(""));
	void consoleprint(AcGePoint3d pPointi, const ACHAR*format = _T(""));
	//суммирует точки
	AcGePoint3d summ(AcGePoint3d &pA, AcGePoint3d &pB);
	//координаты dx dy точки удаленной от отрезка на расстояние R от точки на этом отрезку
	AcGePoint3d dist(AcGePoint3d &pF,
		AcGePoint3d &pN,
		double &pR);
	//точка пересечения отрезков
	bool intersection(AcGePoint3d &p1,
		AcGePoint3d &p2,
		AcGePoint3d &p3,
		AcGePoint3d &p4,
		AcGePoint3d &MID
	);

	//Точка изгиба двух труб рвдиуса R
	void Givecenterpoint(AcGePoint3d &n1,
		AcGePoint3d &n2,
		AcGePoint3d &n3,
		double &pRadius,
		AcGePoint3d &midp,
		double &pAngle,
		AcGeVector3d &pStartvector);
	void fourpoints(AcGePoint3d &Firstpoint,
		AcGePoint3d &Lastpoint,
		AcGePoint3d &p1,
		AcGePoint3d &p2,
		AcGePoint3d &p3,
		AcGePoint3d &p4,
		double &Radius);
	double angle(AcGePoint3d &pt1, AcGePoint3d &pt2, AcGePoint3d &basepoint = AcGePoint3d(0, 0, 0));
	void Givestartvector(AcGeVector3d &Starvector, AcGeVector3d &v2, double &pangle);
	bool correctpipes(AcGePoint3d &A,
		AcGePoint3d &B,
		AcGePoint3d &C,
		double &pangle,
		double &pSizeA,
		double &pRadius,
		AcGePoint3d &lastpipi,
		bool &pThisRound);
	double length2p(AcGePoint3d A,
		AcGePoint3d B
	);
	AcGePoint3d shortlength(AcGePoint3d &A,
		AcGePoint3d &B,
		double thislegth
	);

	void pCon(AcDbEntity *pEnt1,
		AcDbEntity  *pEnt2
	);

	void startdraw();
	//void changesize ();
	//void nextpipe(AcGePoint3d &A1,
	//			  AcGePoint3d &A2,
	//			  AcGePoint3d &A3,
	//			  TVS_Pipe *pipi
	//			  );


	AcGePoint3d AddSpecLine(AcGePoint3d cent,
		const ACHAR*t1 = _T(""),
		const ACHAR*t2 = _T(""),
		const ACHAR*t3 = _T(""),
		const ACHAR*t4 = _T(""),
		const ACHAR*t5 = _T("")
	);



	void TVS_CS(AcDbEntity *pEnt);
	void TVS_PEdit(AcDbEntity *pEnt);
	void Change(ads_name &sset);
	void Change(AcDbEntity *pEnt);

	void rprov(bool &variableconst,
		bool &firstvariable,
		double &objectvar,
		double &myvar);
	void rprov(bool &variableconst,
		bool &firstvariable,
		const bool &objectvar,
		bool &myvar);
	void rprov(bool &variableconst, bool &firstvariable, int &objectvar, int &myvar);
	void strfil(double &myvar,
		bool &variableconst,
		CString &stringconst
	);

	void strfil(bool &myvar,
		bool &variableconst,
		BOOL &stringconst
	);
	void strfil(int &myvar, bool &variableconst, CString &stringconst);
	void sequal(double &var,
		CString &Svar1,
		CString &Svar2,
		bool &equ
	);

	void sequal(bool &var,
		BOOL &Svar1,
		BOOL &Svar2,
		bool &equ
	);
	void sequal(int &var, CString &Svar1,/*начальный */ CString &Svar2,/*конечный */ bool &equ);
	double getElev(double &Elev,
		int &EMode,
		double &SizeA,
		double &SizeB
	);

	TVS_TAP*drawTapDirect(AcGePoint3d t1,
		AcGePoint3d t2,
		AcGePoint3d t3
	);
	void getdouble(CString &svar, double dvar);
	void getint(CString &svar, int dvar);
	void PostToModelSpace(AcDbEntity *pEnt);
	void SetGlobalProperty(TVS_Entity *pEnt);
	void GiveStartvectorAndAngle(AcGePoint3d &n1, AcGePoint3d &n2, AcGePoint3d &n3, double &pAngle, AcGeVector3d &pStartvector);
	int TVSClassCheck(AcDbEntity* pEnt);
	int whyIsGrose(TVS_Entity* pEnt1, TVS_Entity* pEnt2);

	void drawEntity(AcDbEntity *pent);
	int ActivationErrorMessage();
};

