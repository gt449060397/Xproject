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
			STANDARD=0,
			DESIGN=1,
		};
		LoadCombination(WindLoad wind,SeismicEffect seismic,DeadLoad deadload);

		virtual ~LoadCombination()=default;

		//kn/m2
		virtual	double LoadEffectCombination(CombinationType comtype)=0;


	protected:
		double m_gamma_g;
		double m_gamma_w;
		double m_gamma_E;
		double m_psi_w;
		double m_psi_E;

		//load
		WindLoad m_wind;
		SeismicEffect m_seismic;
		DeadLoad m_dead;

};

