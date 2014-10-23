#include "test_function_ptr.hpp"
#include <cstdio>

void print(int i)
{
	printf("print %d", i);
}

typedef void (*print_t)(int);

void test_function_ptr()
{
	print_t Print = print;

}
