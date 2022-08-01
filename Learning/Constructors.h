#pragma once
#include <string>
#include <iostream>

class Moveable
{
	std::string str{"start"};
	double d{-1.1};
public:
	Moveable() {}
	Moveable(std::string s, double nd)
	: str(s), d(nd)
	{}
	Moveable(const Moveable& o)
		: str(o.str), d{o.d}
	{
		std::cout << "copy C\n";
	}
	Moveable(Moveable&& o)
		: str(std::move(o.str)), // move(obj), obj - class type
			d( std::exchange(o.d, 0))
	{
		std::cout << "move copy C\n";
	}
	Moveable& operator=(const Moveable& o)
	{
		str = o.str;
		d = o.d;
		std::cout << "assignment Op\n";
		return *this;
	}

	Moveable& operator=(Moveable&& o)
	{
		*this = std::move(o);
		std::cout << "move assignment\n";
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& ost, const Moveable& o)
	{
		return ost << o.str << o.d << '\n';
	}
	~Moveable()
	{}
};

