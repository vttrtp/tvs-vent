#pragma once

//#include "resource.h"
#include "acdb.h"
#include "dbmain.h"
#include "AcDblClkEdit.h"
#include "Func.h"
using namespace func;


class tdbl :
	public AcDbDoubleClickEdit
{
public:
	tdbl();
	virtual ~tdbl();
	void finishEdit(void);
	void startEdit(AcDbEntity *pEnt, AcGePoint3d pt);
	void InitApplication();
};
