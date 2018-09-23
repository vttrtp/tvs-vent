#include "StdAfx.h"
#include "TVS_ComEntity.h"

bool CTVS_ComEntity::tryToSetCommonDisplayName(const DISPID &dispId, BSTR *propName)
{
	switch (dispId) 
	{ 
		// ����������� 
	case (0x516): 
		*propName  = ::SysAllocString(_T("����")); 
		return true;
		break; 

	case (0x501): 
		*propName  = ::SysAllocString(_T("����")); 
		return true;
		break; 

	case (0x502): 
		*propName  = ::SysAllocString(_T("��� �����")); 
		return true;
		break; 

	case (0x503): 
		*propName  = ::SysAllocString(_T("������� ���� �����")); 
		return true;
		break; 

	case (0x513): 
		*propName  = ::SysAllocString(_T("����� ������")); 
		return true;
		break; 

	case (0x514): 
		*propName  = ::SysAllocString(_T("��� �����")); 
		return true;
		break; 

	case (0x515): 
		*propName  = ::SysAllocString(_T("�����������")); 
		return true;
		break; 

	case (0x577): 
		*propName  = ::SysAllocString(_T("��������")); 
		return true;
		break; 

	}
	return false;
}


