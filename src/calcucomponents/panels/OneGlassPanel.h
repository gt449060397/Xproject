/*
 *Copyright 2020 X-prject authors
 *
 * OneGlassPanel.h (one glass panel calculate  class)
 * 
 * */

#pragma once

#include "GlassPanel.h"


class OneGlassPanel:public GlassPanel
{
	public:
		//	OneGlassPanel(double width,double height,double thickness,GlassMaterial mat):GlassPanel(mat),m_width(width),m_height(height),m_thickness(thickness){}
		OneGlassPanel()=default;
		virtual ~OneGlassPanel()=default;

		virtual ResultBase* Calculate(BasicParameters *param) override;

		//item calculate book
		virtual std::string CalculateBook(BasicParameters *param) override ;

	private:
		double m_thickness;

};
