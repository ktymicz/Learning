#include "Driver.h"

namespace Movable {

	//-----------------------------------------
	// Driver
	Driver::Driver()
		: coordinates{0,0,30},name{"what"}, hard_to_calculate{coordinates.hard_to_calculate}, hardp(coordinates.getnewHard())
	{

	}
	

	Driver::Driver(const Driver& other)
		:coordinates{other.coordinates}, name{other.name}, 
		hard_to_calculate{other.hard_to_calculate}, hardp{coordinates.getnewHard()}
	{
		std::cout << "Copy Constructor\n";
	}

	Driver::Driver(Driver&& move) noexcept
		: coordinates(std::move(move.coordinates)), hard_to_calculate{std::move(move.hard_to_calculate)},
		name{ std::move(name)}, hardp{std::exchange(move.hardp, nullptr)}
	{
		std::cout << "move constructor\n";
	}
	
	Driver& Driver::operator=(const Driver& other)
	{
		std::cout << "copy assignment\n";
		if (this == &other)
			return *this;
		coordinates = other.coordinates;
		name = other.name;
		hard_to_calculate = other.hard_to_calculate;
		hardp = coordinates.getnewHard();
		return *this;
	}

	Driver & Driver::operator=(Driver&& move) noexcept
	{
		std::cout << "move assignment operator\n";
		if(&move == this)
			return *this;
		// if type* hardp you need to delete [] hardp;
		coordinates = std::move(move.coordinates);
		hard_to_calculate = std::move(move.hard_to_calculate);
		name = std::move(move.name);
		hardp = std::exchange(move.hardp, nullptr);
		return *this;

	}

	void Driver::move(int dx, int dy)
	{

		if (coordinates.x + dx <= xmax && coordinates.x + dx >= xmin)
			coordinates.x += dx;
		else
			coordinates.x + dx > xmax ? (coordinates.x = xmax) : (coordinates.x = xmin);
		
		if (coordinates.y + dy <= ymax && coordinates.y + dy >= ymin)
			coordinates.y += dy;
		else
			coordinates.y + dy > ymax ? (coordinates.y = ymax) : coordinates.y = ymin;
	}

	std::ostream& operator<<(std::ostream& str, const Driver& d)
	{
		return str << "name" << d.name << ", Coordinates x,y:" << d.coordinates.x << ',' << d.coordinates.y << '\n';
	}

	//-----------------------------------------
	// Driverp
	Driverp::Driverp()
		: co{ 0,0,30 }, name{ "Stupid Driverp" }, hard_to_calculate{ co.hard_to_calculate }, hardp(co.getnewHard())
	{

	}

	Driverp::Driverp(const Driverp& other)
		:co{ other.co }, name{ other.name }, hard_to_calculate{hard_to_calculate}, hardp{co.getnewHard()}
	{

		// Deep copy use
		// hardp{co.getnewHard()} or  
		// hardp = new int[co.hsize];
		for (size_t i = 0; i < co.hsize; i++)
		{
			hardp[i] = other.hardp[i];
		}
		std::cout << "Copy Constructor\n";
	}

	Driverp::Driverp(Driverp&& move) noexcept
		:co{std::move(move.co)}, name{std::move(move.name)}, 
		hard_to_calculate{std::move(move.hard_to_calculate)}, hardp{std::exchange(move.hardp, nullptr)}
	{
		std::cout << "move constructor\n";
	}

	Driverp& Driverp::operator=(const Driverp& other)
	{
		if (this == &other) return *this;
		std::cout << "copy assignment operator";
		delete[]hardp;
		co = other.co;
		name = other.name;
		hard_to_calculate = other.hard_to_calculate;
		hardp = new int[co.hsize];
		for (size_t i = 0; i < co.hsize; i++)
		{
			hardp[i] = other.hardp[i];
		}		
		return *this;
	}

	Driverp& Driverp::operator=(Driverp&& move) noexcept
	{
		if (this == &move) return *this;
		std::cout << "move assignment operator";
		delete[]hardp;
		co = std::move(move.co);		
		name = std::move(move.name);
		hard_to_calculate = std::move(hard_to_calculate);
		hardp = std::exchange(move.hardp, nullptr);
		return *this;
	}

	void Driverp::move(int dx, int dy)
	{

		if (co.x + dx <= xmax && co.x + dx >= xmin)
			co.x += dx;
		else
			co.x + dx > xmax ? (co.x = xmax) : (co.x = xmin);

		if (co.y + dy <= ymax && co.y + dy >= ymin)
			co.y += dy;
		else
			co.y + dy > ymax ? (co.y = ymax) : co.y = ymin;
	}

	std::ostream& operator<<(std::ostream& str, const Driverp& d)
	{
		str << "int[hsize]==";
		for (size_t i = 0; i < d.co.hsize; i++)
		{
			str << d.hardp[i] << ' ';
		}
		str <<'\n';
		return str << "name" << d.name << ", co x,y:" << d.co.x << ',' << d.co.y << '\n';
	}



}

