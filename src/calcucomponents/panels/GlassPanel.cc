

#include "GlassPanel.h"
#include <math.h>

double GlassPanel::CalReductionFactor(double theta)
{
	double reductionFactor=0;
	if (theta<=5.0)
		reductionFactor = 1.0;
	else if (theta > 5 && theta <= 10)
		reductionFactor = (1 - 0.96) * (10 - theta) / (10 - 5) + 0.96;
	else if (theta > 10 && theta <= 20)
		reductionFactor = (0.96 - 0.92) * (20 - theta) / (20 - 10) + 0.92;
	else if (theta > 20 && theta <= 40)
		reductionFactor = (0.92 - 0.84) * (40 - theta) / (40 - 20) + 0.84;
	else if (theta > 40 && theta <= 60)
		reductionFactor = (0.84 - 0.78) * (60 - theta) / (60 - 40) + 0.78;
	else if (theta > 60 && theta <= 80)
		reductionFactor = (0.78 - 0.73) * (80 - theta) / (80 - 60) + 0.73;
	else if (theta > 80 && theta <= 100)
		reductionFactor = (0.73 - 0.68) * (100 - theta) / (100 - 80) + 0.68;
	else if (theta > 100 && theta <= 120)
		reductionFactor = (0.68 - 0.65) * (120 - theta) / (120 - 100) + 0.65;
	else if (theta > 120 && theta <= 150)
		reductionFactor = (0.65 - 0.61) * (150 - theta) / (150 - 120) + 0.61;
	else if (theta > 150 && theta <= 200)
		reductionFactor = (0.61 - 0.57) * (200 - theta) / (200 - 150) + 0.57;
	else if (theta > 200 && theta <= 250)
		reductionFactor = (0.57 - 0.54) * (250 - theta) / (250 - 200) + 0.54;
	else if (theta > 250 && theta <= 300)
		reductionFactor = (0.54 - 0.52) * (300 - theta) / (300 - 250) + 0.52;
	else if (theta > 300 && theta <= 350)
		reductionFactor = (0.52 - 0.51) * (350 - theta) / (350 - 300) + 0.51;
	else if (theta > 350 && theta <= 400)
		reductionFactor = (0.51 - 0.50) * (400 - theta) / (400 - 350) + 0.50;
	else if (theta > 400)
		reductionFactor = 0.5;
	return reductionFactor;
}

double GlassPanel::CalBendingMomnentFactor(double shortAndlongSideRatio)
{
	double bendingMomFactor = 0;
	if (shortAndlongSideRatio <= 0)
		bendingMomFactor = 0.1250;
	else if (shortAndlongSideRatio > 0 && shortAndlongSideRatio <=0.25)
		bendingMomFactor = (0.1250 - 0.1230)*(0.25 - shortAndlongSideRatio)/(0.25 - 0) + 0.1230;
	else if (shortAndlongSideRatio > 0.25 && shortAndlongSideRatio <= 0.33)
		bendingMomFactor = (0.1230 - 0.1180) * (0.33 - shortAndlongSideRatio) / (0.33 - 0.25) + 0.1180;
	else if (shortAndlongSideRatio > 0.33 && shortAndlongSideRatio <= 0.40)
		bendingMomFactor = (0.1180 - 0.1115) * (0.4 - shortAndlongSideRatio) / (0.40 - 0.33) + 0.1115;
	else if (shortAndlongSideRatio > 0.40 && shortAndlongSideRatio <= 0.50)
		bendingMomFactor = (0.1115 - 0.1) * (0.5 - shortAndlongSideRatio) / (0.50 - 0.40) + 0.1;
	else if (shortAndlongSideRatio > 0.50 && shortAndlongSideRatio <= 0.55)
		bendingMomFactor = (0.1 - 0.0934) * (0.55 - shortAndlongSideRatio) / (0.55 - 0.50) + 0.0934;
	else if (shortAndlongSideRatio > 0.55 && shortAndlongSideRatio <= 0.6)
		bendingMomFactor = (0.0934 - 0.0868) * (0.60 - shortAndlongSideRatio) / (0.6 - 0.55) + 0.0868;
	else if (shortAndlongSideRatio > 0.60 && shortAndlongSideRatio <= 0.65)
		bendingMomFactor = (0.0868 - 0.0804) * (0.65 - shortAndlongSideRatio) / (0.65 - 0.60) + 0.0804;
	else if (shortAndlongSideRatio > 0.65 && shortAndlongSideRatio <= 0.70)
		bendingMomFactor = (0.0804 - 0.0742) * (0.70 - shortAndlongSideRatio) / (0.70 - 0.65) + 0.0742;
	else if (shortAndlongSideRatio > 0.70 && shortAndlongSideRatio <= 0.75)
		bendingMomFactor = (0.0742 - 0.0683) * (0.75 - shortAndlongSideRatio) / (0.75 - 0.70) + 0.0683;
	else if (shortAndlongSideRatio > 0.75 && shortAndlongSideRatio <= 0.80)
		bendingMomFactor = (0.0683 - 0.0628) * (0.80 - shortAndlongSideRatio) / (0.80 - 0.75) + 0.0628;
	else if (shortAndlongSideRatio > 0.80 && shortAndlongSideRatio <= 0.85)
		bendingMomFactor = (0.0628 - 0.0576) * (0.85 - shortAndlongSideRatio) / (0.85 - 0.80) + 0.0576;
	else if (shortAndlongSideRatio > 0.85 && shortAndlongSideRatio <= 0.90)
		bendingMomFactor = (0.0576 - 0.0528) * (0.90 - shortAndlongSideRatio) / (0.90 - 0.85) + 0.0528;
	else if (shortAndlongSideRatio > 0.90 && shortAndlongSideRatio <= 0.95)
		bendingMomFactor = (0.0528 - 0.0483) * (0.95 - shortAndlongSideRatio) / (0.95 - 0.90) + 0.0483;
	else if (shortAndlongSideRatio > 0.95 && shortAndlongSideRatio <= 1.0)
		bendingMomFactor = (0.0483 - 0.0442) * (1.0 - shortAndlongSideRatio) / (1.0 - 0.95) + 0.0442;
	return bendingMomFactor;
}

double GlassPanel::GlassStrengthDesignValue(GlassMaterial mat,double thickness)
{
	double strengthValue=0;
	switch (mat)
	{
		case FLAT:
			{
				if (thickness>=5 &&thickness<15)
				{
					strengthValue = 28;
				}
				else if (thickness >= 15 && thickness < 20)
				{
					strengthValue = 24;
				}
				else
					strengthValue = 20;
			}
			break;
		case TEMPERED:
			{
				if (thickness >= 5 && thickness < 15)
				{
					strengthValue = 84;
				}
				else if (thickness >= 15 && thickness < 20)
				{
					strengthValue = 72;
				}
				else
					strengthValue = 59;
			}
			break;
	}
	return strengthValue;
}

double GlassPanel::Caltheta(double q_k,double shortSide,double thickness)
{

	double theta=q_k*pow(shortSide,4)/(m_Eglass*pow(thickness,4));
	return theta;
}

double GlassPanel::CalGlassMaxStress(double thickness,double q,double q_k)
{
	double shortSide=(m_width<=m_height)?m_width:m_height;
	double longSide=(m_width<=m_height)?m_height:m_width;
	double bendingMomFactor=CalBendingMomnentFactor(shortSide/longSide);
	double theta=Caltheta(q_k,shortSide,thickness);
	double reductionFactor=CalReductionFactor(theta);
	//maxStress(MPa)
	double maxStress=6*bendingMomFactor*q*pow(shortSide,2)*reductionFactor/(1000*pow(thickness,2));

	return maxStress;
}

CheckResults GlassPanel:CheckStrength(double thickness,GlassLoadCombination &combination)
{

	double qk=combination.LoadEffectCombination(LoadCombination::STANDARD);
	double q=combination.LoadEffectCombination(LoadCombination::DESIGN);

	double maxStress=CalGlassMaxStress(thickness,q,qk);
	CheckResults results;
	results.m
}
