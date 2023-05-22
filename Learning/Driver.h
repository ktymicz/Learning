#pragma once
#include <iostream>

namespace Movable{

	enum class def{ xd =50, yd=50 };
	constexpr int xmax = 100;
	constexpr int ymax = 100;
	constexpr int xmin = -100;
	constexpr int ymin = -100;

	struct Coordinates
	{
		int x;
		int y;
		int hard_to_calculate;
		std::unique_ptr<int> getnewHard() { return std::make_unique<int>(8231); }
	};



	class Driver
	{
	public:
		std::string name;
		Coordinates coordinates;
		int hard_to_calculate; // invariant
		std::unique_ptr<int> hardp;
	public:
		Driver();
		Driver(const Driver& other);		
		Driver( Driver&& move) noexcept;		
		Driver& operator=(const Driver& other);
		Driver& operator=(Driver&& move) noexcept;
		~Driver() = default;
		void move(int dx, int dy);
		friend std::ostream& operator<<(std::ostream & str, const Driver&);

	};


	struct Stupid_Coordinates
	{
		int x;
		int y;
		int hard_to_calculate;
		int* getnewHard() { return new int[hsize] {0, 1, 2, 3}; }
		static const int hsize{ 4 };
		
	};
	class Driverp
	{
	public:
		std::string name;
		Stupid_Coordinates co;
		int hard_to_calculate; // invariant
		int* hardp; // pointer to array, owner
	public:
		Driverp();
		Driverp(const Driverp& other);
		Driverp(Driverp&& move) noexcept;
		Driverp& operator=(const Driverp& other);
		Driverp& operator=(Driverp&& move) noexcept;
		~Driverp() { delete[]hardp; };
		void move(int dx, int dy);
		friend std::ostream& operator<<(std::ostream& str, const Driverp&);

	};
	
}
