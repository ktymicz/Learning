#include "Polymorphism.h"	

namespace Polymorphism {
	Base::Base()
		: name("noname")
	{
	}

	Base::Base(std::string s)
		: name(s)
	{
	}

	Base::~Base()
	{
	}

	void Base::foo()
	{
		std::cout << "inside Base\n";
	}

	Derived::Derived()
		:Base()
	{

	}
	void Derived::foo() 
	{ std::cout << "inside Derived\n"; }
}
