#include <stdio.h>

unsigned long long fibo(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	long long unsigned result;
	long long unsigned a = 0;
	long long unsigned b = 1;

	for (int i = 2; i <= n; i++)
	{
		result = a + b;
		a = b;
		b = result;
	}
	return result;
}


int main(void)
{
	int term;

	printf("enter the term you want to know\n");
	scanf("%d", &term);

	long long unsigned result = fibo(term);

	printf("fibo(%d) = %llu\n", term, result);

	return 0;
}
