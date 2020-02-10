#pragma once

#include "ICalItemRegistrar.h"
#include "CalItemFactory.h"
#include <string>

template <class CalItemType_t,class CalItemImpl_t>
class CalItemRegistrar:public ICalItemRegistrar<CalItemType_t>
{
	public:
		explicit CalItemRegistrar(std::string name)
		{
			CalItemFactory<CalItemType_t>::Instance().RegisterCalItem(this,name);
		}

		CalItemType_t *CreateCalItem()
		{
			return new CalItemImpl_t();
		}
};
