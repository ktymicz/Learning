#pragma once
#include <string>
#include <iostream>
#include <vector>

struct s{
	s(int i) :n(i){}
	int n{ -1 };
};

class Moveable:s
{
	enum ctor{def,copy,moveC, cpAs, moveAs, user};
	std::string str{"start"};
	double d{-1.1};
public:
	Moveable():s(def) {}
	Moveable(const std::string & s, double nd)
		: str(s), d(nd), s{ user }
	{
		std::cout << "user Ctor\n";
	}
	Moveable(const Moveable& o)
		: str(o.str), d{ o.d }, s{ copy }
	{
		std::cout << "copy Ctor\n";
	}
	Moveable(Moveable&& o)
		: str(std::move(o.str)), // move(obj), obj - class type
			d( std::exchange(o.d, 0)),
		s( std::move(o) )
	{
		std::cout << "n:" << n << ", move Ctor\n";
		n = moveC;
	}
	Moveable& operator=(const Moveable& o)
	{
		str = o.str;
		d = o.d;
		s::n = cpAs;
		std::cout << "copy assignment\n";
		return *this;
	}

	Moveable& operator=(Moveable&& o)
	{
		str = std::move(o.str); // explicit move of a member of class type
		d = std::exchange(o.d, 0); // explicit move of a member of non-class type
		s::operator=(std::move(o));
		std::cout << "n:" << n << ", move assignment\n";
		s::n = moveAs;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& ost, const Moveable& o)
	{
		return ost << "str:" << o.str <<", d:" << o.d << ", s.n:" << o.n <<'\n';
	}
	~Moveable()
	{}
};

Moveable passM(Moveable o);



class Brush
{
	enum mode;
	mode working{ mode::off };
	std::string str{"off"};
public:

	Brush()
	{
		std::cout << "default ctor\n";
	}
	Brush(mode w, const std::string & i) 
	:working{w}, str{i}
	{
		std::cout << "user ctor\n";
	}
	Brush(const Brush& o)
		: working{ o.working }, str{o.str}
	{
		std::cout << "copy ctor\n";
	}
	Brush(Brush&& m)
		: working{ std::exchange(m.working, mode::off) }, str{ std::move(m.str) }
	{
		std::cout << "move ctor\n";
	}
	Brush& operator=(const Brush& o)
	{
		working = o.working;
		str = o.str;
		std::cout << "copy assignment\n";
		return *this;
	}

	Brush& operator=(Brush&& m)
	{
		working = std::exchange(m.working, mode::off);
		str = std::move(m.str);
		std::cout << ", move assignment\n";
	}
	enum mode { off, one, two, three, four };


	friend std::ostream& operator<<(std::ostream& ost, const Brush& o)
	{
		return ost << "str:" << o.str << ", d:" << o.working << '\n';
	}

};

Brush f(Brush o);
Brush& r(Brush o);
