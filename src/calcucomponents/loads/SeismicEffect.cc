#include "SeismicEffect.h"


double SeismicEffect::CalNominalValue()
{
	return m_beta_E*m_alpha_max*m_G_k_A;
}
