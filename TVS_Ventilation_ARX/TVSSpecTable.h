#pragma once
#include "vector"
#include "TVSSpecTableColumn.h"
#include "TVSPropertySpec.h"

#define CTVSTablePropertyName L"CTVSTableProperty"
#define CTVSDefaultTableProperty L"\
���.; 2000;[�������]\r\n\
������������ � ����������� ��������������; 13000; [���]\r\n\
���, �����, ����������� ���������, ��������� �����; 6000; [���] [������]\r\n\
��� ���������; 3500; [�������]\r\n\
���������; 4500; [�������������]\r\n\
��. ���� - �� - ���; 2000; [��.���]\r\n\
���.; 2000;[����������]\r\n\
����� 1 ��., ��; 2500; [�����]\r\n\
�����- �����; 4000; [����������]\r\n\
"

#define CTVSInstructionTableProperty L"\
������� ����������� ��������� ��������\r\n\
�������� �������1; ������1; [�������� ��������1]\r\n\
�������� �������2; ������2; [�������� ��������2]-[c�������3]\r\n\
��� ������ ������� ��� ������� ������������, � ��������';'\r\n��������� �������� �������, ���: \r\n\
�������� �������1 - ��� ��� ������� � ����� �������;\r\n\
������1 - ��� ������ ������� � �������� autocad;\r\n\
[�������� ��������1] - ��� ������ ������ ������� �������. � ����\r\n������ ����� �������� ��������� ������� �������� [���]-[������]\r\n\
�������������� ��������:\r\n\
[�������],[���],[���],[������],[�������],[�������������],[��.���]\r\n[����������],[�����],[����������]\
"

using namespace std;
class TVSSpecTable
{
public:
	TVSSpecTable();
	int rowsPerList;
	bool paginating;
	double titleHeight;
	double rowHeight;
	double textHeight;
	static bool getRowSettings(CString &rowSettings);
	static bool setRowSettings(const CString &rowSettings);
	bool loadColumnsFromSettings();
	bool buildDataFromSpec(const TVSPropertySpec &spec);
	bool toSimpleTable(const AcGePoint3d &startPoint);
	bool toExcel();
	void showPropsDlg();
	vector<TVSSpecTableColumn> columns;
	vector<vector<CString>> tableData;
	virtual ~TVSSpecTable();
private:
	bool getRowData(const TVSPropertySpecRow &row, const TVSSpecTableColumn &column, CString &data);

};

