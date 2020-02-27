

#pragma once

#include "ResultBase.h"
#include "CheckResults.h"

struct CommonCalResult:public ResultBase
{
   std::vector<CheckResults>m_CheckResults;

};
