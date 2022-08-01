#pragma once
#include <iostream>

class N2
{
	double m2x;
public:
	N2(double n)
		:m2x([](double x) -> double {
		return x * 2; }(n))
	{
		std::cout << ([n](double x) { return x; }(m2x)) << '\n';
	}
		double get_value();
		void set_value(double n) {
			m2x = n;
		};
};







class OneTen
{
public:
	OneTen(double n)
		: OneTen([](double n)-> std::string {
		return ((n >= 1 && n <= 10) ? ("true") : ("false"));
			}(n), n)
	{
		std::cout << "OneTen(double) address:" << &*this << '\n';
	}
	friend std::ostream& operator<<(std::ostream& ostr, const OneTen& ot)
	{
		return ostr << "str:" << ot.st << ", n: " << ot.d << '\n';
	}
	
private:
	OneTen(std::string str, double n)
		:
		st(str), d(n)
	{
		std::cout << "OneTen(std::string, double) address:" << &*this << '\n';
	}
	std::string st{"InitLambda"};
	double d{ -1.1 };
};