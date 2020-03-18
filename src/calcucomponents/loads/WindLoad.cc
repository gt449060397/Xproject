/*
 *Copyright 2020 X-prject authors
 *
 * WindLoad.cc (wind load calculate class)
 * 
 * */

#include "WindLoad.h"
#include <math.h>
#include <algorithm>


double WindLoad::CalNominalValue()
{
	LOG(INFO)<<"CalNominalValue";
	//1 zheng feng xi shu
	CalGustCoefficient();
	//2 gao du bian hua xi shu
	CalHeightVariationCoefficient();

	double nominalValue=m_beta_gz*m_u_z*Calu_sl(m_calPart,m_area)*m_parameters.m_w0;
	switch(m_parameters.m_eWindCalMethod)
	{
		case BasicParameters::LOADCODE:
			nominalValue=std::max(nominalValue,1.0);
			break;
		case BasicParameters::CUSTOMIZE:
			nominalValue=m_parameters.m_WindLoadNominalValue;
			break;
		case BasicParameters::ACTUALCAL:
			break;
	}
	
	return nominalValue;
}


void WindLoad::CalGustCoefficient()
{

	LOG(INFO)<<"CalGustCoefficient";
	double height=CalTruncatedHeight();
	switch(m_parameters.m_eSiteType)
	{
		case BasicParameters::A:
			m_beta_gz=1.0+0.6*pow(height/10.0,-0.12);
			break;
		case BasicParameters::B:
			m_beta_gz=1.0+0.7*pow(height/10.0,-0.15);
			break;
		case BasicParameters::C:
			m_beta_gz=1.0+1.15*pow(height/10.0,-0.22);
			break;
		case BasicParameters::D:
			m_beta_gz=1.0+1.95*pow(height/10.0,-0.30);
			break;
		default:
			m_beta_gz=1.0;
			break;

	}
}


void WindLoad::CalHeightVariationCoefficient()
{

	LOG(INFO)<<"CalHeightVariationCoefficient";
	double height=CalTruncatedHeight();
	switch(m_parameters.m_eSiteType)
	{
		case BasicParameters::A:
			m_u_z=1.284*pow(height/10.0,0.24);
			break;
		case BasicParameters::B:
			m_u_z=1.000*pow(height/10.0,0.3);
			break;
		case BasicParameters::C:
			m_u_z=0.544*pow(height/10.0,0.44);
			break;
		case BasicParameters::D:
			m_u_z=0.262*pow(height/10.0,0.60);
			break;
		default:
			m_u_z=1.0;
			break;

	}
}


double WindLoad::CalTruncatedHeight()
{

	LOG(INFO)<<"CalTruncatedHeight";
	double truncatedHeight=m_parameters.m_calHeight;
	switch(m_parameters.m_eSiteType)
	{
		case BasicParameters::A:
			if(m_parameters.m_calHeight>300)truncatedHeight=300;
			if(m_parameters.m_calHeight<5) truncatedHeight=5;
			break;
		case BasicParameters::B:
			if(m_parameters.m_calHeight>350)truncatedHeight=350;
			if(m_parameters.m_calHeight<10)truncatedHeight=10;
			break;
		case BasicParameters::C:
			if(m_parameters.m_calHeight>450)truncatedHeight=450;
			if(m_parameters.m_calHeight<15) truncatedHeight=15;
			break;
		case BasicParameters::D:
			if(m_parameters.m_calHeight>550)truncatedHeight=550;
			if(m_parameters.m_calHeight<30)truncatedHeight=30;
			break;
		default:
			truncatedHeight=m_parameters.m_calHeight;
			break;

	}
	return truncatedHeight;
}

double WindLoad::Calu_sl(const CalPart calPart,double area)
{
	LOG(INFO)<<"Calu_sl";
	double u_sl=0;

	switch(calPart)
	{
		case PANEL:
			u_sl=Calu_sl_panel();
			break;
		case SUPPORTSTUCTURE:
			u_sl=Calu_sl_supportStucture(area);
			break;
		default:
			u_sl=1.0;
	}

	return u_sl;


}

double WindLoad::Calu_sl_panel()
{

	LOG(INFO)<<"Calu_sl_panel";
	double u_sl=0;
	switch(m_parameters.m_eCalArea)
	{
		case BasicParameters::Corner:
			u_sl=1.6;
			break;
		case BasicParameters::Wall:
			u_sl=1.2;
			break;
		case BasicParameters::Other:
			u_sl=m_parameters.m_u_sl;
			break;
		default:
			u_sl=1.0;
	}
	return u_sl;
}

double WindLoad::Calu_sl_supportStucture(double area)
{

	LOG(INFO)<<"Calu_sl_supportStucture";
	double u_sl=0;
	switch(m_parameters.m_eCalArea)
	{
		case BasicParameters::Corner:
			u_sl=1.4;
			break;
		case BasicParameters::Wall:
			u_sl=1.0;
			break;
		case BasicParameters::Other:
			return u_sl=m_parameters.m_u_sl;
			break;
		default:
			u_sl=1.0;
	}
	if(area<=1)
	{
		u_sl*=1.0;

	}
	else if(area>1&&area<25)
	{
		u_sl=u_sl+(0.8*u_sl-u_sl)*log(area)/1.4;
	}
	else
	{
		u_sl*=0.8;
	}
	
	return u_sl+0.2;
}

