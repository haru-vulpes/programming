#include <stdio.h>
#include <stdlib.h>

unsigned long euclidean_division(unsigned long a, unsigned long b, unsigned long *r)
{
	unsigned long q; 


	if (b == 0)
		printf("'Fin frérot, on divise pas par zéro");
	else 
	{
		q = a/b;
		if (r != NULL)
			*r = a%b;
	}
	return q;
}

void test_code(unsigned long a, unsigned long b, unsigned long q, unsigned long r);

int main (int argc, char *argv[])
{

	unsigned long a = atol(argv[1]);
	unsigned long b = atol(argv[2]);
	unsigned long c;
	unsigned long q;

	if (argv[1] != NULL && argv[2] != NULL)
		q = euclidean_division(a, b, &c); 
		printf("The result is (%lu, %lu).\n", q, c);

	test_code( 10, 5, 2, 0);
	test_code( 1, 5, 0, 1);
	test_code( 10, 3, 3, 1);

	return 0;
}

void test_code(unsigned long a, unsigned long b, unsigned long q, unsigned long r)
{
	unsigned long rest;
	unsigned long quotiant = euclidean_division(a, b, &rest);

	if (r == rest && q == quotiant)
		printf("ok\n");
	else
		printf("KO: expected (%lu, %lu), got (%lu, %lu)\n", r, q, rest, quotiant);
}
