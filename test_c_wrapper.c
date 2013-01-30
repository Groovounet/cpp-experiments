#include <stdio.h>

void c_func()
{
	printf("c_func\n");
}

void c_decl();

void c_wrapper()
{
	c_decl();
}

