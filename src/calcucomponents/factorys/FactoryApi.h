/*
 *Copyright 2020 X-prject authors
 *
 * FactoryApi.h (FactoryApi  class)
 * 
 * */
#pragma once 

#include "CalItemRegistrar.h"
#include "CalItemFactory.h"
#include <string>
#include "../CalculateItem.h"
#include "OneGlassPanel.h"
#include "GLogHelper.h"

 const  std::string OneGlassCalItem="OneGlassPanel";
class FactoryApi
{

	protected:
		FactoryApi()
		{
			CalItemRegistrar<CalculateItem,OneGlassPanel>oneGlassPanel(OneGlassCalItem);
		}

	private:
		static FactoryApi *api;

	public:
		static FactoryApi * Instance();

		//calitems
		CalculateItem* CreateCalItem(std::string name)
		{
			LOG(INFO)<<"create cal item "+name;
			
			return CalItemFactory<CalculateItem>::Instance().GetCalItem(name);
		}
	public:

		
};

FactoryApi* FactoryApi::api=new FactoryApi;

FactoryApi* FactoryApi::Instance()
{
	return api;
}
