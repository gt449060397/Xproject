

#include "OneGlassPanel.h"
#include "GlassLoadCombination.h"
#include "GLogHelper.h"
#include "CommonCalResult.h"

ResultBase* OneGlassPanel::Calculate(std::shared_ptr<BasicParameters> param)
{
	try
	{
		m_params=std::dynamic_pointer_cast<GlassParameters>(param);
		//wind load
		WindLoad windLoad(*param,WindLoad::PANEL);
		//di zheng zuo yong
		double gkA=m_gravityDensity*m_params->m_thickness[0]/1000;
		SeismicEffect seismicEffect(m_params->m_alpha_max,gkA);
		//dead load
		DeadLoad deadLoad(0);

		//load combination
		GlassLoadCombination loadCombination(windLoad,seismicEffect,deadLoad);

		//result
		auto result=new CommonCalResult();
		//strength check
		auto resStrength=CheckStrength(m_params->m_thickness[0],loadCombination);
		resStrength.m_CheckType=STRENGTH;
		result->m_CheckResults.push_back(resStrength);

		// deflection check
		auto resDeflection=CheckDeflection(m_params->m_thickness[0],loadCombination);
		resDeflection.m_CheckType=DEFLECTION;
		result->m_CheckResults.push_back(resDeflection);

		return result;
	}
	catch(...)
	{
		LOG(ERROR)<<"calculation exception!";
		return nullptr;
	}
}




std::string OneGlassPanel::CalculateBook(std::shared_ptr<BasicParameters>param)
{
	return "";
}
