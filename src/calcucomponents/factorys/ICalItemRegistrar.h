/*
 *Copyright 2020 X-prject authors
 *
 * ICalItemRegistrar.h (ICalItemRegistrar class)
 * 
 * */
#pragma once


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
