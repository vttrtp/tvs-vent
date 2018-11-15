#pragma once
#include "TVSProperty.h"
#include "list"
#include "TVSController.h"
//#include <functional>
class TVSPropertySpecRow
{
public:
	TVSPropertySpecRow();
	TVSPropertySpecRow(const TVSProperty &props, const AcDbObjectId &objId);
	virtual ~TVSPropertySpecRow();

	TVSProperty tvsPropery;
	list<AcDbObjectId> objectIds;
	bool isChanged;


	// 	mGrid.SetItemText(i, 1, row.tvsPropery.position);
	// 	mGrid.SetItemText(i, 2, row.tvsPropery.name);
	// 	mGrid.SetItemText(i, 3, row.tvsPropery.type);
	// 	mGrid.SetItemText(i, 4, row.tvsPropery.size);
	// 	mGrid.SetItemText(i, 5, row.tvsPropery.article);
	// 	mGrid.SetItemText(i, 6, row.tvsPropery.manufacturer);
	// 	mGrid.SetItemText(i, 7, row.tvsPropery.units);
	// 	mGrid.SetItemText(i, 8, getString(row.tvsPropery.count));
	// 	mGrid.SetItemText(i, 9, getString(row.tvsPropery.mass));
	// 	mGrid.SetItemText(i, 10, row.tvsPropery.note);
	// 	mGrid.SetItemText(i, 11, getString(row.objectIds.size()));

	// 	template <typename T>
	// 	void setAndRecalculate(T &old, const T &newVal, const std::function<bool (const AcDbObjectId &objectId, const T &val)> &func) {
	// 		if (old != newVal)
	// 		{
	// 			old = newVal;
	// 			for (auto id : objectIds)
	// 			{
	// 				func(id, newVal);
	// 
	// 			}
	// 		}
	// 	}

	void setAndRecalculatePosition(const CString &newVal) {

		if (tvsPropery.position != newVal)
		{
			acutPrintf(L"change");
			tvsPropery.position = newVal;
			for (auto &objectId : objectIds)
			{
				TVSController::get()->tvsPropertyController.setPosition(objectId, newVal);
			}
		}

	}

	void setAndRecalculateName(const CString &newVal) {

		if (tvsPropery.name != newVal)
		{
			acutPrintf(L"change");
			tvsPropery.name = newVal;
			for (auto &objectId : objectIds)
			{
				TVSController::get()->tvsPropertyController.setName(objectId, newVal);
			}
		}

	}

	void setAndRecalculateType(const CString &newVal) {

		if (tvsPropery.type != newVal)
		{
			acutPrintf(L"change");
			tvsPropery.type = newVal;
			for (auto &objectId : objectIds)
			{
				TVSController::get()->tvsPropertyController.setType(objectId, newVal);
			}
		}

	}

	void setAndRecalculateSize(const CString &newVal) {

		if (tvsPropery.size != newVal)
		{
			acutPrintf(L"change");
			tvsPropery.size = newVal;
			for (auto &objectId : objectIds)
			{
				TVSController::get()->tvsPropertyController.setSize(objectId, newVal);
			}
		}

	}

	void setAndRecalculateManufacturer(const CString &newVal) {

		if (tvsPropery.manufacturer != newVal)
		{
			acutPrintf(L"change");
			tvsPropery.manufacturer = newVal;
			for (auto &objectId : objectIds)
			{
				TVSController::get()->tvsPropertyController.setManufacturer(objectId, newVal);
			}
		}

	}

	void setAndRecalculateArticle(const CString &newVal) {

		if (tvsPropery.article != newVal)
		{
			acutPrintf(L"change");
			tvsPropery.article = newVal;
			for (auto &objectId : objectIds)
			{
				TVSController::get()->tvsPropertyController.setArticle(objectId, newVal);
			}
		}

	}

	void setAndRecalculateUnits(const CString &newVal) {

		if (tvsPropery.units != newVal)
		{
			acutPrintf(L"change");
			tvsPropery.units = newVal;
			for (auto &objectId : objectIds)
			{
				TVSController::get()->tvsPropertyController.setUnits(objectId, newVal);
			}
		}

	}

	void setAndRecalculateNote(const CString &newVal) {

		if (tvsPropery.note != newVal)
		{
			acutPrintf(L"change");
			tvsPropery.note = newVal;
			for (auto &objectId : objectIds)
			{
				TVSController::get()->tvsPropertyController.setNote(objectId, newVal);
			}
		}

	}

	void setAndRecalculateCount(const double &newVal) {

		if (tvsPropery.count != newVal)
		{
			acutPrintf(L"change");
			tvsPropery.count = newVal;
			for (auto &objectId : objectIds)
			{
				TVSController::get()->tvsPropertyController.setCount(objectId, newVal);
			}
		}

	}

	void setAndRecalculateMass(const double &newVal) {
		if (tvsPropery.mass != newVal)
		{
			acutPrintf(L"change");
			tvsPropery.mass = newVal;
			for (auto &objectId : objectIds)
			{
				TVSController::get()->tvsPropertyController.setMass(objectId, newVal);
			}
		}

	}
};

