#include "stdafx.h"
#include "stringHelper.h"

bool stringHelper::splitStringIntoVector(const CString & sourceString, const ACHAR * splitString, std::vector<CString> &splitVector)
{
	int nTokenPos = 0;
	CString rowToken = sourceString.Tokenize(splitString, nTokenPos);
	while (!rowToken.IsEmpty())
	{
		splitVector.push_back(rowToken);
		rowToken = sourceString.Tokenize(splitString, nTokenPos);
	}
	return false;
}
