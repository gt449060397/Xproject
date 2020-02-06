

#include "LoadCombination.h"


LoadCombination::LoadCombination(CombinationType comType,WindLoad wind,SeismicEffect seismic,DeadLoad deadload):m_eComType(comType),m_wind(wind),m_seismic(seismic),m_dead(deadload)
{
	switch(m_eComType)
	{
		case STRENGTH:
			m_gamma_g=1.2;
			m_gamma_w=1.4;
			m_gamma_E=1.3;
				break;
		case DEFLECTION:
			m_gamma_g=1.0;
			m_gamma_w=1.0;
			m_gamma_E=0;
			break;
	}
	m_psi_w=1.0;
	m_psi_E=0.5;

}


double LoadCombination::LoadEffectCombination()
{
	double combination=m_gamma_g*m_dead.CalNominalValue()+m_psi_w*m_gamma_w*m_wind.CalNominalValue()+m_psi_E*m_gamma_E*m_seismic.CalNominalValue();
	return combination;
}
