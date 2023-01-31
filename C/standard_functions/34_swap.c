#include <stdio.h>


void swap(int *a, int *b)

{
	int c = *a;
	*a = *b;
	*b = c;
}

int main()
{

	int a = 1;
	int b = 2;

	printf("a = %d %p\n", a, &a);
	printf("b = %d %p\n", b, &b);

	swap(&a, &b);

	printf("a = %d %p\n", a, &a);
	printf("b = %d %p\n", b, &b);

return 0;
}
