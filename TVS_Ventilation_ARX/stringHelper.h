#pragma once
#include <arxheaders.h>
#include <vector>
namespace stringHelper {
	bool splitStringIntoVector(const CString &sourceString, const ACHAR *splitString, std::vector<CString> &splitVector);
}


