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
#include <memory>
class CalculateItem
{
	public:
		//item check
		virtual ResultBase* Calculate(std::shared_ptr<BasicParameters>params)=0;

		//item calculate book
		virtual std::string  CalculateBook(std::shared_ptr<BasicParameters>params)=0;
};
