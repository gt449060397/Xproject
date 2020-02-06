

# include "GlassLoadCombination.h"


double GlassLoadCombination:LoadEffectCombination(CombinationType type)
{
	switch(type)
	{
		case DESIGN:
			m_gamma_g=1.2;
			m_gamma_w=1.4;
			m_gamma_E=1.3;
			break;
		case STANDARD:
			m_gamma_g=1.0;
			m_gamma_w=1.0;
			m_gamma_E=1.0;
			break;
	}
	m_psi_w=1.0;
	m_psi_E=0.5;

	double combination=m_psi_w*m_gamma_w*m_wind.CalNominalValue()+m_psi_E*m_gamma_E*m_seismic.CalNominalValue();
	return combination;
}
