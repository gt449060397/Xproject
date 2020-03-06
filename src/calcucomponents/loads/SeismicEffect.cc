#include "SeismicEffect.h"
#include "GLogHelper.h"


double SeismicEffect::CalNominalValue()
{
	LOG(INFO)<<"CalNominalValue";
	return m_beta_E*m_alpha_max*m_G_k_A;
}
