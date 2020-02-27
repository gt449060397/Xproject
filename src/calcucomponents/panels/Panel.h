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
		virtual ResultBase* Calculate(std::shared_ptr<BasicParameters>param) override {return NULL;}

		//item calculate book
		virtual std::string CalculateBook(std::shared_ptr<BasicParameters>param) override {return "";}
	
	protected:

};

