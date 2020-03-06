#pragma once
#include "CheckResults.h"

struct ResultBase
{
	ResultBase(){}
	virtual ~ResultBase(){}
	CheckResults::eResult m_eFinalResult;
};
