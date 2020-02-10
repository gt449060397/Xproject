#pragma once

#include "ICalItemRegistrar.h"
#include "CalItemFactory.h"
#include <string>
#include "GLogHelper.h"
#include "OneGlassPanel.h"

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
			LOG(INFO)<<"create cal item ";
			return new CalItemImpl_t();
		}
};
