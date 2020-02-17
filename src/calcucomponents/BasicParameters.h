/*
 *Copyright 2020 X-prject authors
 *
 * BasicParameters.h (BasicParameters class)
 * 
 * */

#pragma once

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

};
