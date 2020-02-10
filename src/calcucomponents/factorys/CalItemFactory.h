/*
 *Copyright 2020 X-prject authors
 *
 * CalItemFactory.h (CalItemFactory class)
 * 
 * */
#pragma once

#include <string>
#include <map>
#include "GLogHelper.h"
#include "ICalItemRegistrar.h"

template <class CalItemType_t>
class CalItemFactory
{
	public:
		static CalItemFactory<CalItemType_t>& Instance()
		{
			static CalItemFactory<CalItemType_t> instance;
			return instance;
		}


		void RegisterCalItem(ICalItemRegistrar<CalItemType_t> *registrar,std::string name)
		{
			m_CalItemRegistry[name]=registrar;

		}

		CalItemType_t* GetCalItem(std::string name)
		{
			LOG(INFO)<<"create cal item "+name;
			if(m_CalItemRegistry.find(name)!=m_CalItemRegistry.end())
			{
				return m_CalItemRegistry[name]->CreateCalItem();

			}

			LOG(ERROR)<<"No CalItem found for "<<name;
			return NULL;
		}	


	private:

		CalItemFactory(){}
		~CalItemFactory(){}


		CalItemFactory(const CalItemFactory&);
		const CalItemFactory &operator =(const CalItemFactory&);

		std::map<std::string,ICalItemRegistrar<CalItemType_t>*> m_CalItemRegistry;
};
