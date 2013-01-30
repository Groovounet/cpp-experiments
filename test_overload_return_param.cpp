#include "test_overload_return_param.hpp"
#include <iostream>

struct S
{
	template <typename T>
	T f()
	{
		return T();
	}
	
	template <typename T>
	operator T()
	{
		return f<T>();
	}
};

template <>
int S::f()
{
	return 123;
}

template <>
double S::f()
{
	return 456;
}

S f()
{
	return S();
}

void test_overload_return_param()
{
	int i = f();
	double d = f();
	short s = f();

	std::cout <<"i: " <<i <<std::endl;
	std::cout <<"d: " <<d <<std::endl;
	std::cout <<"s: " <<s <<std::endl;
}
