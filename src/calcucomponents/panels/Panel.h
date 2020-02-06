/*
 *Copyright 2020 X-prject authors
 *
 * Panel.h (panel calculate base class)
 * 
 * */

#pragma once

#include "../CalculateItem.h"


class Panel:public CalculateItem
{
  
	public:
		virtual bool Calculate() override {return false;}

		//item calculate book
		virtual bool CalculateBook() override {return false;}

	

	protected:
		double m_height;
		double m_width;

};

