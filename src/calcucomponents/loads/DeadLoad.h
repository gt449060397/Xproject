/*
 *Copyright 2020 X-prject authors
 *
 * LoadCombination.h (LoadCombination class)
 * 
 * */

#pragma once

#include "GLogHelper.h"
class DeadLoad
{
	public:
		DeadLoad(double deadNominal):m_nominal(deadNominal){}

		double CalNominalValue()
		{
			LOG(INFO)<<"CalNominalValue";
			return m_nominal;
		}

	private:
		double	m_nominal;//kN/m2
};
