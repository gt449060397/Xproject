/*
 *Copyright 2020 X-prject authors
 *
 * BasicParameters.h (BasicParameters class)
 * 
 * */

#pragma once
#include "GLogHelper.h"
#include "grpc_basicParameters.pb.h"
struct BasicParameters
{
	enum DesignYears
	{
		FIFTY=0,
		HUNDRED=2,
	};

	//di main lei xing 
	enum SiteType
	{
		A=0,
		B=1,
		C=2,
		D=3,
	};
	//ti xing xi shu yong
	enum CalculateArea
	{
		Corner=0,
		Wall=1,
		Other=2,

	};

	//kang zhen she fang
	enum SeismicFortification
	{
		STANDARD=0,
		EMPHASIS=1,
		SPECIAL=2,
		MODERATE=3, 
	};

	enum SeismicSiteType
	{
		I0=0,
		I1=1,
		II=2,
		III=3,
		IV=4,
	};

	enum WindLoadCalMethod
	{
		LOADCODE=0,
		CUSTOMIZE=1,
		ACTUALCAL=2,
	};
	BasicParameters():m_w0(0.3),m_eDesignYears(FIFTY),m_eSiteType(B),m_eCalArea(Wall),m_eSeismicFort(STANDARD),m_eSeismicSiteType(II),m_eWindCalMethod(LOADCODE),m_WindLoadNominalValue(1.0){}
	BasicParameters(const Xproject::grpc_BasicParameters &basicParams)
	{
		LOG(INFO)<<"";
		m_w0=basicParams.w0();
		m_eDesignYears=DesignYears(basicParams.m_edesignyears());
		m_eSiteType=SiteType(basicParams.m_esitetype());
		m_eCalArea=CalculateArea(basicParams.m_ecalarea());
		m_eSeismicFort=SeismicFortification(basicParams.m_eseismicfort());
		m_eSeismicSiteType=SeismicSiteType(basicParams.m_eseismicsitetype());
		m_u_sl=basicParams.m_u_sl();
		LOG(INFO)<<"m_u_sl"<<basicParams.m_u_sl();
		m_WindLoadNominalValue=basicParams.m_windloadnominalvalue();
		m_alpha_max=basicParams.m_alpha_max();

		LOG(INFO)<<"m_alpha_max"<<basicParams.m_alpha_max();
		m_calHeight=basicParams.m_calheight();
		LOG(INFO)<<"m_calheight"<<basicParams.m_calheight();

	}
	virtual ~BasicParameters()=default;



	double m_w0;// ji ben feng ya(KN/m2)
	DesignYears m_eDesignYears;
	SiteType m_eSiteType;
	CalculateArea m_eCalArea;
	WindLoadCalMethod m_eWindCalMethod;
	SeismicFortification m_eSeismicFort;
	SeismicSiteType m_eSeismicSiteType;

	double m_u_sl;//ju bu ti xing xi shu
	double m_WindLoadNominalValue;//(KN/m2)

	double m_alpha_max;//di zheng can shu

	double m_calHeight; //ji suan gao du (m)


	virtual void print()
	{
		LOG(INFO)<<" w0= "<<m_w0;
		LOG(INFO)<<" m_edesignyears= "<<m_eDesignYears;
		LOG(INFO)<<" m_esitetype= "<<m_eSiteType;
		LOG(INFO)<<" m_ecalarea= "<<m_eCalArea;
		LOG(INFO)<<" m_ewindcalmethod= "<<m_eWindCalMethod;
		LOG(INFO)<<" m_eseismicfort= "<<m_eSeismicFort;
		LOG(INFO)<<" m_eseismicsitetype= "<<m_eSeismicSiteType;
		LOG(INFO)<<" m_u_sl= "<<m_u_sl;
		LOG(INFO)<<" m_alpha_max= "<<m_alpha_max;
		LOG(INFO)<<" m_windloadnominalvalue= "<<m_WindLoadNominalValue;
		LOG(INFO)<<" m_calHeight= "<<m_calHeight;
	}

};
