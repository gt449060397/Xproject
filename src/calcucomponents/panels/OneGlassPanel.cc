

#include "OneGlassPanel.h"

ResultBase* OneGlassPanel::Calculate(const BasicParameters *param)
{
	m_params=dynamic_cast<const GlassParameters *>(param);

	return NULL;
}




std::string OneGlassPanel::CalculateBook(const BasicParameters *param)
{
	return "";
}
