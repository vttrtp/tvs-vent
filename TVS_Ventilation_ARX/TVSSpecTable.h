#pragma once
#include "vector"
#include "TVSSpecTableColumn.h"
#include "TVSPropertySpec.h"

#define CTVSTablePropertyName L"CTVSTableProperty"
#define CTVSDefaultTableProperty L"\
Поз.; 2000;[Позиция]\r\n\
Наименование и техническая характеристика; 13000; [Имя]\r\n\
Тип, марка, обозначение документа, опросного листа; 6000; [Тип] [Размер]\r\n\
Код продукции; 3500; [Артикул]\r\n\
Поставщик; 4500; [Производитель]\r\n\
Ед. изме - ре - ния; 2000; [Ед.Изм]\r\n\
Кол.; 2000;[Количество]\r\n\
Масса 1 ед., кг; 2500; [Масса]\r\n\
Приме- чание; 4000; [Примечание]\r\n\
"

#define CTVSInstructionTableProperty L"\
Таблица описывается следующим шаблоном\r\n\
Название Столбца1; Ширина1; [Название свойства1]\r\n\
Название Столбца2; Ширина2; [Название свойства2]-[cвойство3]\r\n\
где каждая строчка это столбец спецификации, а символом';'\r\nразделены свойства столбца, где: \r\n\
Название Столбца1 - это имя столбца в шапке таблицы;\r\n\
Ширина1 - это ширина таблицы в единицах autocad;\r\n\
[Название свойства1] - это шаблон записи свойств обьекта. в этот\r\nшаблон можно помещать несколько свойств например [Тип]-[Размер]\r\n\
Поддерживаемые свойства:\r\n\
[Позиция],[Имя],[Тип],[Размер],[Артикул],[Производитель],[Ед.Изм]\r\n[Количество],[Масса],[Примечание]\
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

