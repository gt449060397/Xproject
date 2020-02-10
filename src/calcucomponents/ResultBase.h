#pragma once

struct ResultBase
{

	enum ResultStatus
	{
		OK=0,
		FAIL=1,
	};


	ResultStatus m_status;
};
