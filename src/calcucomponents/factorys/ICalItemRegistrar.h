/*
 *Copyright 2020 X-prject authors
 *
 * ICalItemRegistrar.h (ICalItemRegistrar class)
 * 
 * */
#pragma once
#include <string>
#include "GLogHelper.h"
#include <map>


template<class CalItemType_t>
class ICalItemRegistrar
{
	public:
		virtual CalItemType_t *CreateCalItem()=0;

	protected:
		//
		ICalItemRegistrar(){}
		virtual ~ICalItemRegistrar(){}
	
	private:
		ICalItemRegistrar(const ICalItemRegistrar&);
		const ICalItemRegistrar &operator =(const ICalItemRegistrar&);
};


//factory
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

			LOG(INFO)<<"m_CalItemRegistry.size(): "<<m_CalItemRegistry.size();
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

template <class CalItemType_t,class CalItemImpl_t>
class CalItemRegistrar:public ICalItemRegistrar<CalItemType_t>
{
	public:
		explicit CalItemRegistrar(std::string name)
		{
			CalItemFactory<CalItemType_t>::Instance().RegisterCalItem(this,name);
		}

		CalItemType_t *CreateCalItem()override
		{
			return new CalItemImpl_t();
		}
};
