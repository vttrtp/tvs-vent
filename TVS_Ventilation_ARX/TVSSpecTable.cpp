#include "stdafx.h"
#include "TVSSpecTable.h"
#include "stringHelper.h"
#include "graphicHelper.h"
#include "MSExcel.h"	
#include "dgSpecProperty.h"
TVSSpecTable::TVSSpecTable() :
	rowsPerList(21),
	titleHeight(3200),
	rowHeight(800),
	textHeight(250),
	paginating(false)
{
}

TVSSpecTable::~TVSSpecTable()
{
}

bool TVSSpecTable::getRowSettings(CString &rowSettings)
{
	ACHAR stringProperty[2048];
	if (acedGetEnv(CTVSTablePropertyName, stringProperty) == RTNORM) {
		rowSettings = stringProperty;
	}
	else {
		rowSettings = CTVSDefaultTableProperty;
	}
	return true;
}

bool TVSSpecTable::setRowSettings(const CString &rowSettings)
{
	if (acedSetEnv(CTVSTablePropertyName, rowSettings) == RTNORM) {
		return true;
	}
	else {
		return false;
	}
}

bool TVSSpecTable::loadColumnsFromSettings()
{
	CString tvsTablePropertyString;
	if (!getRowSettings(tvsTablePropertyString)) return false;

	vector <CString> rows;
	stringHelper::splitStringIntoVector(tvsTablePropertyString, L"\n", rows);
	for (CString &row : rows) {
		vector<CString> rowStringVector;
		stringHelper::splitStringIntoVector(row, L";", rowStringVector);
		if (rowStringVector.size() == 3)
		{
			TVSSpecTableColumn col;
			col.name = rowStringVector[0].Trim(L"\n\r\t ;");
			col.width = _tstof(rowStringVector[1].Trim(L"\n\r\t ;"));
			col.value = rowStringVector[2].Trim(L"\n\r\t ;");
			columns.push_back(col);
		}
	}
	return true;
}

bool TVSSpecTable::buildDataFromSpec(const TVSPropertySpec &spec)
{
	int colIdx = 0;
	int rowIdx = 0;
	tableData.resize(spec.rows.size());
	for (auto &row : spec.rows) {
		colIdx = 0;
		tableData[rowIdx].resize(columns.size());
		for (auto &column : columns) {
			CString data;
			if (getRowData(row, column, data)) {
				tableData[rowIdx][colIdx] = data;
			}
			colIdx++;
		}
		rowIdx++;
	}
	return true;
}

bool TVSSpecTable::toSimpleTable(const AcGePoint3d &startPoint)
{
	double width = 0;
	for (auto &col : columns) {
		width += col.width;
	}
	double height = titleHeight + tableData.size()*rowHeight;

	//drawVertical lines
	AcGePoint3d curStartPoint = startPoint;
	AcGePoint3d curEndPoint = curStartPoint;
	curEndPoint.y -= height;
	graphicHelper::drawLine(curStartPoint, curEndPoint);
	for (int i = 0; i < columns.size(); i++)
	{
		curStartPoint.x += columns[i].width;
		curEndPoint.x += columns[i].width;
		graphicHelper::drawLine(curStartPoint, curEndPoint);
	}

	//draw horizontal lines
	curStartPoint = startPoint;
	curEndPoint = curStartPoint;
	curEndPoint.x += width;
	//draw title
	graphicHelper::drawLine(curStartPoint, curEndPoint);
	curStartPoint.y -= titleHeight;
	curEndPoint.y -= titleHeight;
	for (int i = 0; i <= tableData.size(); i++)
	{
		graphicHelper::drawLine(curStartPoint, curEndPoint);
		curStartPoint.y -= rowHeight;
		curEndPoint.y -= rowHeight;

	}

	//draw text;
	int colIdx = 0;
	int rowIdx = 0;
	int otstupX = 100;
	int otstupY = 150;
	double curY = startPoint.y - titleHeight + otstupY;
	double curX = startPoint.x + otstupX;
	//draw title;
	for (int i = 0; i < columns.size(); i++) {
		graphicHelper::drawText(AcGePoint3d(curX, curY, startPoint.z), columns[i].name);
		curX += columns[i].width;
	}

	for (auto &row : tableData) {
		colIdx = 0;
		curX = startPoint.x + otstupX;
		curY -= rowHeight;
		for (auto &column : row) {
			graphicHelper::drawText(AcGePoint3d(curX, curY, startPoint.z), column);
			curX += columns[colIdx].width;
			colIdx++;
		}
	}
	return true;
}

bool TVSSpecTable::toExcel()
{
	CMSExcel m_msExcel;
	acedSetStatusBarProgressMeter(_T("Cоздание документа Excel"), 0, 100);
	if (FAILED(m_msExcel.NewExcelBook(false) == E_FAIL))
	{
		acedRestoreStatusBar();
		acutPrintf(_T("\n Ошибка"));
		return false;
	}

	acedSetStatusBarProgressMeter(_T("Экспорт в Excel"), 0, 100);
	const ACHAR* excelColumns = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//title;
	int curRowIdx = 1;
	for (int i = 0; i < columns.size(); i++) {
		CString curCol(i < 26 ? excelColumns[i] : excelColumns[25]);
		m_msExcel.printExelText(curCol.AllocSysString(), curRowIdx, columns[i].name);
	}
	int curColIdx = 0;
	curRowIdx++;
	//rows
	for (auto &row : tableData) {
		curColIdx = 0;
		for (auto &column : row) {
			CString curCol(curColIdx < 26 ? excelColumns[curColIdx] : excelColumns[25]);
			column.Replace(L"%%c", L"⌀");
			m_msExcel.printExelText(curCol.AllocSysString(), curRowIdx, column);
			curColIdx++;
		}
		acedSetStatusBarProgressMeter(_T("Экспорт данных в Excel"), curRowIdx, tableData.size());
		curRowIdx++;
	}

	m_msExcel.SetVisible(true);
	acedRestoreStatusBar();
	return true;
}

void TVSSpecTable::showPropsDlg()
{
	dgSpecProperty dlg;
	dlg.instructionMessage = CTVSInstructionTableProperty;
	getRowSettings(dlg.specProps);
	dlg.DoModal();
	setRowSettings(dlg.specProps);
}

bool TVSSpecTable::getRowData(const TVSPropertySpecRow &row, const TVSSpecTableColumn &column, CString &data)
{
	data = column.value;
	data.Replace(CTVSProperty_position_val, row.tvsPropery.position);
	data.Replace(CTVSProperty_name_val, row.tvsPropery.name);
	data.Replace(CTVSProperty_type_val, row.tvsPropery.type);
	data.Replace(CTVSProperty_size_val, row.tvsPropery.size);
	data.Replace(CTVSProperty_article_val, row.tvsPropery.article);
	data.Replace(CTVSProperty_manufacturer_val, row.tvsPropery.manufacturer);
	data.Replace(CTVSProperty_units_val, row.tvsPropery.units);
	CString temp;
	temp.Format(L"%g", row.tvsPropery.count);
	data.Replace(CTVSProperty_count_val, temp);
	temp.Format(L"%g", row.tvsPropery.mass);
	data.Replace(CTVSProperty_mass_val, temp);
	data.Replace(CTVSProperty_note_val, row.tvsPropery.note);
	data.Trim(L"\n\r\t ;-");
	return true;
}
