/*
 *Copyright 2020 X-prject authors
 *
 * OneGlassPanel.h (one glass panel calculate  class)
 * 
 * */

#pragma once

#include "GlassPanel.h"
#include "GlassParameters.h"
#include "ICalItemRegistrar.h"

class OneGlassPanel:public GlassPanel
{
	public:
		OneGlassPanel()
		{
		}
		virtual ~OneGlassPanel()=default;

		virtual ResultBase* Calculate(const BasicParameters *param) override;

		//item calculate book
		virtual std::string CalculateBook(const BasicParameters *param) override ;

		//init
		void Init(BasicParameters *parameters);


};


