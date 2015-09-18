#include "test_default_virtual.hpp"
#include <cstddef>
#include <cstdlib>
#include <cstdio>

enum mode
{
	MODE_B,
	MODE_C,
	MODE_D
};

struct b
{
	virtual void print(mode Mode = MODE_B)
	{
		printf("B: %d\n", Mode);
	}
};

struct c : public b
{
	virtual void print(mode Mode = MODE_C)
	{
		printf("C: %d\n", Mode);
	}
};

struct d : public b
{
	virtual void print(mode Mode)
	{
		printf("D: %d\n", Mode);
	}
};

void test_default_virtual()
{
	b B;
	B.print();

	c C;
	C.print();

	d D;
	D.print(MODE_D);

	b* B1 = &B;
	B1->print();

	b* C1 = &C;
	C1->print();

	b* D1 = &D;
	D1->print();

	printf("\n");
}

