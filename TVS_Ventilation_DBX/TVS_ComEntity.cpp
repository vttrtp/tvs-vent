#include "StdAfx.h"
#include "TVS_ComEntity.h"

bool CTVS_ComEntity::tryToSetCommonDisplayName(const DISPID &dispId, BSTR *propName)
{
	switch (dispId) 
	{ 
		// стандартное 
	case (0x516): 
		*propName  = ::SysAllocString(_T("Цвет")); 
		return true;
		break; 

	case (0x501): 
		*propName  = ::SysAllocString(_T("Слой")); 
		return true;
		break; 

	case (0x502): 
		*propName  = ::SysAllocString(_T("Тип линий")); 
		return true;
		break; 

	case (0x503): 
		*propName  = ::SysAllocString(_T("Масштаб типа линий")); 
		return true;
		break; 

	case (0x513): 
		*propName  = ::SysAllocString(_T("Стиль печати")); 
		return true;
		break; 

	case (0x514): 
		*propName  = ::SysAllocString(_T("Вес линий")); 
		return true;
		break; 

	case (0x515): 
		*propName  = ::SysAllocString(_T("Гиперссылка")); 
		return true;
		break; 

	case (0x577): 
		*propName  = ::SysAllocString(_T("Материал")); 
		return true;
		break; 

	}
	return false;
}



