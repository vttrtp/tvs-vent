#include "stdafx.h"
#include "PropertyAdmin.h"

bool PropertyAdmin::m_bInitialized = false;
CComObject<CTVSPropertyPositionDyn>* m_position = NULL;
CComObject<CTVSPropertyNameDyn>* m_name = NULL;
CComObject<CTVSPropertyTypeDyn>* m_type = NULL;
CComObject<CTVSPropertySizeDyn>* m_size = NULL;
CComObject<CTVSPropertyArticleDyn>* m_article = NULL;
CComObject<CTVSPropertyManufacturerDyn>* m_manufacturer = NULL;
CComObject<CTVSPropertyUnitsDyn>* m_units = NULL;
CComObject<CTVSPropertyCountDyn>* m_CountDyn = NULL;
CComObject<CTVSPropertyMassDyn>* m_MassDyn= NULL;
CComObject<CTVSPropertyNoteDyn>* m_NoteDyn = NULL;



AcRxClass* PropertyAdmin::m_pClass = AcDbEntity::desc();

template<typename T>
void addProperty(CComPtr<IPropertyManager2> &pPropMan,  T*&prop) {
	_com_util::CheckError(T::CreateInstance(&prop));
	prop->AddRef();
	_com_util::CheckError(pPropMan->AddProperty((IDynamicProperty2*)prop));
	
}

template<typename T>
void removeProperty(CComPtr<IPropertyManager2> &pPropMan, T*&prop) {
	if (prop)
	{
		_com_util::CheckError(pPropMan->RemoveProperty((IDynamicProperty2*)prop));
		prop->Release();
	}
}

void PropertyAdmin::initialize()
{
	if (m_bInitialized)
		return;
	m_bInitialized = true;
	try
	{
		CComPtr<IPropertyManager2> pPropMan = (IPropertyManager2*)GET_OPMPROPERTY_MANAGER(m_pClass);
		addProperty(pPropMan, m_position);
		addProperty(pPropMan, m_name);
		addProperty(pPropMan, m_type);
		addProperty(pPropMan, m_size);
		addProperty(pPropMan, m_article);
		addProperty(pPropMan, m_manufacturer);
		addProperty(pPropMan, m_units);
		addProperty(pPropMan, m_CountDyn);
		addProperty(pPropMan, m_MassDyn);
		addProperty(pPropMan, m_NoteDyn);
		uninitialize();
	}
	catch (const _com_error&)
	{
		//uninitialize();
		acutPrintf(_T("\nSimpleDynProps: initialize failed!!!\n"));
		return;
	}
}

void PropertyAdmin::uninitialize()
{
	CComPtr<IPropertyManager2> pPropMan = (IPropertyManager2*)GET_OPMPROPERTY_MANAGER(m_pClass);
	removeProperty(pPropMan, m_position);
	removeProperty(pPropMan, m_name);
	removeProperty(pPropMan, m_type);
	removeProperty(pPropMan, m_size);
	removeProperty(pPropMan, m_article);
	removeProperty(pPropMan, m_manufacturer);
	removeProperty(pPropMan, m_units);
	removeProperty(pPropMan, m_CountDyn);
	removeProperty(pPropMan, m_MassDyn);
	removeProperty(pPropMan, m_NoteDyn);
}
