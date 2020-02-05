/*
 *Copyright 2020 X-prject authors
 *
 * GlassPanel.h (glass panel calculate base class)
 * 
 * */

#pragma once

#include "Panel.h"


class GlassPanel:public Panel
{
	public:
		virtual bool Calculate() override {};

		//item calculate book
		virtual bool CalculateBook() override {};
	
	
	protect:
		double thickness;


}
