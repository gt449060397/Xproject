/*
 *Copyright 2020 X-prject authors
 *
 * SeismicEffect.h (SeismicEffect class)
 * 
 * */

#pragma once

class SeismicEffect
{

	public:
	SeismicEffect():m_beta_E(5),m_alpha_max(0.16),m_G_k_A(0.03)
	{}
	SeismicEffect(double alpha,double gk,double beta_E=5.0):m_beta_E(beta_E),m_alpha_max(alpha),m_G_k_A(gk)
	{}

//P_EK	
	double CalNominalValue();//kN/m2


	private:
		double m_beta_E;
		double m_alpha_max;
		double m_G_k_A;//kN/m2

};
