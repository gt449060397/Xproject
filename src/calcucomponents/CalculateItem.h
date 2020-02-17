/*
 *Copyright 2020 X-prject authors
 *
 * CalcuteItem.h (calculate base class)
 * 
 * */

#pragma once
#include "BasicParameters.h"
#include "ResultBase.h"
#include <string>

class CalculateItem
{
	public:
		//item check
		virtual ResultBase* Calculate(const BasicParameters *params)=0;

		//item calculate book
		virtual std::string  CalculateBook(const BasicParameters *params)=0;
};
