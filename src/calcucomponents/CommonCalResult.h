

#pragma once

#include "ResultBase.h"
#include "CheckResults.h"

struct CommonCalResult:public ResultBase
{
	CommonCalResult(){}
	virtual ~CommonCalResult(){}
	std::vector<CheckResults>m_CheckResults;

	void print()
	{
		for(auto iter :m_CheckResults)
		{
			iter.print();
		}
	}

};
