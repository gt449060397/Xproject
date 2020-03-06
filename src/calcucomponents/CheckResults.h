/*
 *Copyright 2020 X-prject authors
 *
 * GlassPanel.h (glass panel calculate base class)
 * 
 * */

#pragma once

#include "GLogHelper.h"

struct CheckResults
{
	
	enum eResult
	{
		PASS=0,
		FAIL=1,
	};

	eResult m_eResult;//jie guo
	double m_DesignValue;// she ji zhi
	double m_CalValue;//ji suan zhi
	double m_Surplus;//fu yu
	int m_CheckType;//yan suan lei xing


	void print()
	{
		LOG(INFO)<<"m_eResult= "<<m_eResult;
		LOG(INFO)<<"m_DesignValue= "<<m_DesignValue<<" m_CalValue= "<<m_CalValue<<" m_Surplus= "<<m_Surplus;
		LOG(INFO)<<"m_CheckType= "<<m_CheckType;

	}
};

