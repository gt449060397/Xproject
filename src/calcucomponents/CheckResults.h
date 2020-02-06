/*
 *Copyright 2020 X-prject authors
 *
 * GlassPanel.h (glass panel calculate base class)
 * 
 * */

#pragma once

struct CheckResults
{
	
	enum Result
	{
		PASS=0,
		Fail=1,
	}

	Result m_eResult;//jie guo
	double m_DesignValue;// she ji zhi
	double m_CalValue;//ji suan zhi
	double m_Surplus;//fu yu
};

