#pragma once
#include <string>
#include "commonDef.h"
#define CTVSProperty _T("TVS_Property")

#define CTVSPropertyCategoryName _T("TVS_��������")
#define  CTVSProperty_position L"�������"
#define  CTVSProperty_name	   L"���"
#define  CTVSProperty_type     L"���"
#define  CTVSProperty_size     L"������"
#define  CTVSProperty_article     L"�������"
#define  CTVSProperty_manufacturer     L"�������������"
#define  CTVSProperty_units     L"��.���"
#define  CTVSProperty_count     L"����������"
#define  CTVSProperty_mass     L"�����"
#define  CTVSProperty_note     L"����������"

#define CTVSPropertyCategoryName _T("TVS_��������")
#define  CTVSProperty_position_val L"[�������]"
#define  CTVSProperty_name_val	   L"[���]"
#define  CTVSProperty_type_val     L"[���]"
#define  CTVSProperty_size_val     L"[������]"
#define  CTVSProperty_article_val     L"[�������]"
#define  CTVSProperty_manufacturer_val     L"[�������������]"
#define  CTVSProperty_units_val     L"[��.���]"
#define  CTVSProperty_count_val     L"[����������]"
#define  CTVSProperty_mass_val     L"[�����]"
#define  CTVSProperty_note_val     L"[����������]"

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
	bool isTvsEnt;
	virtual ~TVSProperty();
};

