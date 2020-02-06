/*
 *Copyright 2020 X-prject authors
 *
 * LoadCombination.h (LoadCombination class)
 * 
 * */

#pragma once

#include "LoadCombination.h"

class GlassLoadCombination:public LoadCombination
{
	public:
		GlassLoadCombination(WindLoad wind,SeismicEffect seismic,DeadLoad deadload):LoadCombination(wind,seismic,deadload){}
		double LoadEffectCombination(CombinationType comType)override;

}
