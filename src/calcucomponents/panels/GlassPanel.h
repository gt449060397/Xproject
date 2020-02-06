/*
 *Copyright 2020 X-prject authors
 *
 * GlassPanel.h (glass panel calculate base class)
 * 
 * */

#pragma once

#include "Panel.h"
#include "../CheckResults.h"
#include "../loads/LoadCombination.h"

class GlassPanel:public Panel
{
	public:
		enum GlassType
		{
			ONE=0,
			HOLLOW=1,//ZHONG KONG
			LAMINATE=2,//JIA CENG
			HOLLOW_AND_LAMINATE=3,// ZHONG KONG + JIA CENG
			DOUBLEHOLLOW=4,// SHUANG ZHONG KONG
			DOUBLELAMINATE_AND_HOLLOW=5
		};

		enum GlassMaterial
		{
			FLAT=0,//PING BIAN
			TEMPERED=1,//GANG HUA
		};

		virtual bool Calculate() override {return false;}

		//item calculate book
		virtual bool CalculateBook() override {return false;}


	protected:
		//zhe jian xi shu
		double CalReductionFactor(double theta);
		// wan ju xing shu
		double CalBendingMomnentFactor(double shortAndlongSideRatio);

		//q_k(MPa)
		double Caltheta(double q_k,double shortSide,double thickness);

		//qiang du she ji zhi
		double GlassStrengthDesignValue(GlassMaterial mat,double thickness);

		//qiang du ji suan
		double CalGlassMaxStress(double thickness,double q,double q_k);

		//bo li qiang du yan suan
		CheckResults CheckStrength(double thickness,LoadCombination &combination);
	
		



	protected:
		const double m_gravityDensity=25.6;//zhong li mi du (kN/m3)
		const double m_Eglass=72000000;//bo li tang xing mo liang(kN/m2)




};
