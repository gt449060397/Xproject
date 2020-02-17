#include "GlassParameters.h"
#include "grpc_basicParameters.pb.h"

const std::string GlassParameters::GlassTypeStrs[]={"ONE","HOLLOW","LAMINATE","HOLLOW_AND_LAMINATE","DOUBLEHOLLOW","DOUBLELAMINATE_AND_HOLLOW"};

GlassParameters::GlassParameters(const GlassRequest *pGlassRequest)
{

	Xproject::grpc_BasicParameters basicParams=pGlassRequest->parameters();
	m_w0=basicParams.w0();
	m_eDesignYears=DesignYears(basicParams.m_edesignyears());
	m_eSiteType=SiteType(basicParams.m_esitetype());
	m_eCalArea=CalculateArea(basicParams.m_ecalarea());
	m_eSeismicFort=SeismicFortification(basicParams.m_eseismicfort());
	m_eSeismicSiteType=SeismicSiteType(basicParams.m_eseismicsitetype());
	m_u_sl=basicParams.m_u_sl();
	m_WindLoadNominalValue=basicParams.m_windloadnominalvalue();
	m_alpha_max=basicParams.m_alpha_max();

	m_eMat=GlassMaterial(pGlassRequest->mat());
}
