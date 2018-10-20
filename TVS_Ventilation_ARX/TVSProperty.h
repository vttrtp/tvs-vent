#pragma once
#include <string>
#define CTVSProperty _T("TVS_Property")

#define CTVSPropertyCategoryName _T("TVS_яБНИЯРБЮ")
#define  CTVSProperty_position L"онгхжхъ"
#define  CTVSProperty_name	   L"хлъ"
#define  CTVSProperty_type     L"рхо"
#define  CTVSProperty_size     L"пюглеп"
#define  CTVSProperty_article     L"юпрхйск"
#define  CTVSProperty_manufacturer     L"опнхгбндхрекэ"
#define  CTVSProperty_units     L"ед.хгл"
#define  CTVSProperty_count     L"йнкхвеярбн"
#define  CTVSProperty_mass     L"люяяю"
#define  CTVSProperty_note     L"опхлевюмхе"

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

