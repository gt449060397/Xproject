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
		virtual ResultBase* Calculate(const BasicParameters *param) override {return NULL;}

		//item calculate book
		virtual std::string CalculateBook(const BasicParameters *param) override {return "";}
	
	protected:
		double m_height;
		double m_width;

};

