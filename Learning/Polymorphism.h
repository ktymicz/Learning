#include <iostream>

namespace Polymorphism {
	
	class Base
	{
	public:
		Base();
		Base(std::string s);
		~Base();
		std::string name;
		void foo();
	private:

	};

	class Derived : public Base
	{
	public:
		Derived();
		void foo();
	};


}
