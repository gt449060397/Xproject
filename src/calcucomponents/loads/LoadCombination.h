/*
 *Copyright 2020 X-prject authors
 *
 * LoadCombination.h (LoadCombination class)
 * 
 * */

#pragma once

#include "WindLoad.h"
#include "SeismicEffect.h"
#include "DeadLoad.h"

class LoadCombination
{

	public:
		enum CombinationType
		{
			STRENGTH=0,
			DEFLECTION=1,
		};
		LoadCombination(CombinationType comType,WindLoad wind,SeismicEffect seismic,DeadLoad deadload);

		//kN/m2
		double LoadEffectCombination();


	private:
		double m_gamma_g;
		double m_gamma_w;
		double m_gamma_E;
		double m_psi_w;
		double m_psi_E;

		CombinationType m_eComType;

		//load
		WindLoad m_wind;
		SeismicEffect m_seismic;
		DeadLoad m_dead;

		
};
