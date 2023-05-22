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

// STL:querying a proprerty + structer binding 
// + lambda + span + std::size_t
void LOQ::querying_property_stl()
{

	MyStruct w;
	auto& [name, value] = w;
	name = std::string("Name");
	value = 8;
	std::cout << "w.name: " << w.name << " w.value: " << w.value << '\n';
	auto pLam = [](int n) -> std::string { return  n > 0 && n <= 10 ? "One_Ten" : "NO_ONE_TEN"; };
	
	std::vector<MyStruct> vm;
	for (std::size_t offset{ 0 }; vm.size() <= 10; ++offset)
	{
		vm.push_back(MyStruct(pLam(offset+5), offset+5));
	}
	
	for (const auto& v : vm)
	{
		auto& [name, value] = v;
		std::cout << "v.name: " << name << " v.value: " << value << '\n';
	}

	//std::cout << vm[2](10);

	std::cout << "v.value is in range of [5:15]\n result all_of: " 
		<< std::all_of(vm.cbegin(), vm.cend(),
			[](const MyStruct& m) {return m.value>=5 && m.value<=15; }) << '\n';

	std::cout << "if any vm.value have 15:"
		<< std::any_of(vm.cbegin(), vm.cend(),
			[](const MyStruct& m) { return m.value == 15; }) << '\n';

	enum values
	{
		v15 = 15, v16=16, v17=17
	};
	auto v = v15;
	std::cout << "No value is " << v << " : "
		<< std::none_of(vm.cbegin(), vm.cend(), 
			[v](const MyStruct & m) {
				
				return m.value == v  ;
			})
			<< '\n';

			std::cout << (15 != 0) << '\n';
			// 
}

//auto LOQ::operator==(MyStruct a, MyStruct b) -> bool
//{
//	return a.value == b.value;
//}