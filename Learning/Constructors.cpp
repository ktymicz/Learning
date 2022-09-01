#include "Constructors.h"

Moveable passM(Moveable o)
{
return o;
}

Brush f(Brush o) 
{ 
	std::cout << o;
	return o; 
}


Brush& r(Brush o)
{
	std::cout << o;
	return o;
}