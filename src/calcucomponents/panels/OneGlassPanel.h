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
		enum eOneGlassPanelResultType
		{
			STRENGTH=0,
			DEFLECTION=1,	
		};
		OneGlassPanel()
		{
		}
		virtual ~OneGlassPanel()=default;

		virtual ResultBase* Calculate(std::shared_ptr<BasicParameters>param) override;

		//item calculate book
		virtual std::string CalculateBook(std::shared_ptr<BasicParameters>param) override ;

};


