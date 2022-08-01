#pragma once
#include <cstring>
class Rule_of_three
{
	char* cstring;
	Rule_of_three(const char* s, int n)
		:cstring(new char[n])
	{
		std::memcpy(cstring, s, n);
	}
public:
	Rule_of_three(const char* s = "")
		: Rule_of_three(s, std::strlen(s)+1)
	{	}
	~Rule_of_three()
	{
		delete[] cstring;
	}
	Rule_of_three(const Rule_of_three& other)
		:cstring(other.cstring)
	{}
	Rule_of_three& operator=(const Rule_of_three& other)
	{
		if (this == &other)
			return *this;
		std::size_t n = std::strlen(other.cstring) + 1;
		char* new_cstring = new char[n];
		std::memcpy(new_cstring, other.cstring, n);
		delete[] cstring;

		cstring = new_cstring;
		return *this;

	}
};

