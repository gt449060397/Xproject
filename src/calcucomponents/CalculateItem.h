/*
 *Copyright 2020 X-prject authors
 *
 * CalcuteItem.h (calculate base class)
 * 
 * */

#pragma once



class CalculateItem
{
	public:
		//item check
		virtual bool Calculate()=0;

		//item calculate book
		virtual bool CalculateBook()=0;

};
