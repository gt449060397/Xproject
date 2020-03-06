#include "GlassParameters.h"

const std::string GlassParameters::GlassTypeStrs[]={"ONE","HOLLOW","LAMINATE","HOLLOW_AND_LAMINATE","DOUBLEHOLLOW","DOUBLELAMINATE_AND_HOLLOW"};

GlassParameters::GlassParameters(const GlassRequest *pGlassRequest):BasicParameters(pGlassRequest->parameters())
{
	m_height=pGlassRequest->height();
	m_width=pGlassRequest->width();
	m_eMat=GlassMaterial(pGlassRequest->mat());

	for(auto i=0;i<pGlassRequest->thickness_size();i++)
	{
		m_thickness.push_back(pGlassRequest->thickness(i));
	}
}

void GlassParameters::print()
{
	::BasicParameters::print();
	LOG(INFO)<<" m_height= "<<m_height;
	LOG(INFO)<<" m_width= "<<m_width;
	LOG(INFO)<<" m_eMat="<<m_eMat;
	for(auto iter:m_thickness)
	{
		LOG(INFO)<<" thickness= "<<iter;
	}


}
