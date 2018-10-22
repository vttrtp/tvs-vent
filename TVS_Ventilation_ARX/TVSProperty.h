#pragma once
#include <string>
#include "commonDef.h"
#define CTVSProperty _T("TVS_Property")

#define CTVSPropertyCategoryName _T("TVS_Свойства")
#define  CTVSProperty_position L"Позиция"
#define  CTVSProperty_name	   L"Имя"
#define  CTVSProperty_type     L"Тип"
#define  CTVSProperty_size     L"Размер"
#define  CTVSProperty_article     L"Артикул"
#define  CTVSProperty_manufacturer     L"Производитель"
#define  CTVSProperty_units     L"Ед.Изм"
#define  CTVSProperty_count     L"Количество"
#define  CTVSProperty_mass     L"Масса"
#define  CTVSProperty_note     L"Примечание"

#define  CTVSProperty_Default_Units    CCommonCount_Unit
#define  CTVSProperty_Default_Length	CCommonCount_Length

#define  CTVSProperty_Number_position 0
#define  CTVSProperty_Number_name	   1
#define  CTVSProperty_Number_type     2
#define  CTVSProperty_Number_size     3
#define  CTVSProperty_Number_article     4
#define  CTVSProperty_Number_manufacturer     5
#define  CTVSProperty_Number_units     6
#define  CTVSProperty_Number_count     7
#define  CTVSProperty_Number_mass     8
#define  CTVSProperty_Number_note    9

class TVSProperty
{
public:
	TVSProperty();
	CString position;
	CString name;
	CString type;
	CString size;
	CString article;
	CString manufacturer;
	CString units;
	double count;
	double mass;
	CString note;
	virtual ~TVSProperty();
};

