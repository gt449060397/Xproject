/*
 *Copyright 2020 X-prject authors
 *
 * WindLoad.h (wind load calculate class)
 * 
 * */

#pragma once

#include "../BasicParameters.h"
class WindLoad
{

	public:
		//ji suan bu wei
		enum CalPart
		{
			PANEL=0,
			SUPPORTSTUCTURE=1,
		};
		WindLoad(double height,BasicParameters parameters,const CalPart calPart,double area=0):m_height(height),m_parameters(parameters),m_calPart(calPart),m_area(area)
	{

	}
		WindLoad(){}

		~WindLoad(){}

		//feng he zai biao zhun zhi
		//(KN/m2)
		double CalNominalValue();

	private:
		//zheng feng xi shu
		void CalGustCoefficient();

		//gao du bian hua xi shu
		void CalHeightVariationCoefficient();

		//jie duan gao du
		double CalTruncatedHeight();

		//ju bu ti xing xi shu
		double Calu_sl(const CalPart calPart,double area=0);

		double Calu_sl_panel();
		double Calu_sl_supportStucture(double area);

	private:
		double m_beta_gz;// zheng feng xi shu
		double m_u_z;//gao du bian hua xi shu
		double m_height;//ji suan gao du
		BasicParameters m_parameters;//can shu

		CalPart m_calPart;
		double m_area;//ji suan bu wei chu mian ji
};
