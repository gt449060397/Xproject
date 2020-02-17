/*
 *Copyright 2020 X-prject authors
 *
 * GlassPanel.h (glass panel calculate base class)
 * 
 * */

#pragma once

#include "Panel.h"
#include "../CheckResults.h"
#include "../loads/GlassLoadCombination.h"
#include "GlassParameters.h"

class GlassPanel:public Panel
{
	public:
		GlassPanel()=default;
		virtual ~GlassPanel()=default;

		virtual ResultBase* Calculate(const BasicParameters *param) override {return NULL;}

		//item calculate book
		virtual std::string CalculateBook(const BasicParameters *param) override {return "";}


	protected:
		//zhe jian xi shu
		double CalReductionFactor(double theta);
		// wan ju xing shu
		double CalBendingMomnentFactor(double shortAndlongSideRatio);

		//q_k(MPa)
		double Caltheta(double q_k,double shortSide,double thickness);

		//qiang du she ji zhi
		double GlassStrengthDesignValue(GlassParameters::GlassMaterial mat,double thickness);

		//chang bian yu duan bian bi zhi
		double CalShortAndLongSideRatio();
		//qiang du ji suan
		double CalGlassMaxStress(double thickness,double q,double q_k);

		//bo li qiang du yan suan
		CheckResults CheckStrength(double thickness,GlassLoadCombination &combination);

		//nao du xi shu
		double CalDeflectionFactor(double shortAndlongSideRatio);

		//zui da nao du ji suan
		double CalMaxDeflection(double thickness,double w_k);

		//nao du xian suan
		CheckResults CheckDeflection(double thickness,GlassLoadCombination &combination);
	protected:
		const double m_gravityDensity=25.6;//zhong li mi du (kN/m3)
		const double m_Eglass=72000000;//bo li tang xing mo liang(kN/m2)

		GlassParameters *m_params;//can shu

};
