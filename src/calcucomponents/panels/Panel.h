/*
 *Copyright 2020 X-prject authors
 *
 * Panel.h (panel calculate base class)
 * 
 * */

#pragma once

#include "../CalculateItem.h"
#include "../BasicParameters.h"

//#include "ResultBase.h"

class Panel:public CalculateItem
{
  
	public:
		virtual ResultBase* Calculate(BasicParameters *param) override {return NULL;}

		//item calculate book
		virtual std::string CalculateBook(BasicParameters *param) override {return "";}
	
	protected:
		double m_height;
		double m_width;

};

