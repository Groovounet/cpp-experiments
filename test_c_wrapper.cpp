#include "test_c_wrapper.hpp"
#include <iostream>

extern "C" void c_func();
extern "C" void c_wrapper();

void cpp_func()
{
	std::cout << "cpp_func" << std::endl;
}

extern "C" void c_decl()
{
	std::cout << "c_decl" << std::endl;
}

void test_c_wrapper()
{
	c_func();
	cpp_func();
	c_wrapper();
}
