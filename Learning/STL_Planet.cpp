#include "STL_Planet.h"


void make_heap_stl()
{
	std::vector<int> asi{ 11,10,1,2,3,4,5 };
	std::cout << "initial:";
	for (auto n : asi)
		std::cout << n << ", ";

	std::make_heap(asi.begin(), asi.end());
	std::cout << "after make_heap: ";
	for (auto num : asi)
	{
		std::cout << num << ", ";
	}

	asi.push_back(8);
	std::push_heap(asi.begin(), asi.end());
	for (auto num : asi)
		std::cout << num << ", ";

}