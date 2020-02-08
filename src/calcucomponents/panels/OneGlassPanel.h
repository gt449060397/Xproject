/*
 *Copyright 2020 X-prject authors
 *
 * OneGlassPanel.h (one glass panel calculate  class)
 * 
 * */

#pragma once

#include "GlassPanel.h"


Class OneGlassPanel:public GlassPanel
{
	public:
		OneGlassPanel(double width,double height,double thickness,GlassMaterial mat):GlassPanel(mat),m_width(width),m_height(height),m_thickness(thickness){}
		virtual ~OneGlassPanel()=default;

		bool Calculate()override;
		bool CalculateBook()override;


	private:
		double m_thickness;

};
