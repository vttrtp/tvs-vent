#pragma once
#include "arxheaders.h"
class TableHelper
{
public:
	TableHelper();
	virtual ~TableHelper();

	Acad::ErrorStatus createTable(AcDbTable *&pTbl, const TCHAR *pTblStyle,
		const int nColLen, const int nRowLen)
	{
		pTbl = new AcDbTable();
		Acad::ErrorStatus es;

		// Set the Table Style
		AcDbDictionary *pDict = NULL;
		AcDbObjectId idTblStyle;
		acdbHostApplicationServices()->workingDatabase()->getTableStyleDictionary(pDict, AcDb::kForRead);
		es = pDict->getAt(pTblStyle, idTblStyle);
		pDict->close();

		if (Acad::eOk == es)	pTbl->setTableStyle(idTblStyle);

		pTbl->setSize(nRowLen, nColLen); // The methods setNumColumns() and setNumRows() have been deprecated beyond AutoCAD 2007.
										 //pTbl->setNumColumns(nColLen); 
										 //pTbl->setNumRows(nRowLen); // you can also use insertRows() at later point
		pTbl->generateLayout(); // Very very important, else expect crashes later on

		return es;
	}
};

