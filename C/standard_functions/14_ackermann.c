#include <stdio.h>

unsigned long long ackermann(unsigned long long  m, unsigned long long n)
{
	if (m == 0)
		return n+1;

	if (m > 0 && n == 0)
		return ackermann(m-1, 1);

	if (m > 0 && n > 0)
		return ackermann(m-1, ackermann(m,n-1));
}

int main(void)
{
	unsigned long long m;
	unsigned long long n;

	printf("enter value for ackermann\n");
	scanf("%llu%llu", &m, &n);
	
	unsigned long long result = ackermann(m,n);

	printf("ackermann %llu\n", result);

	return 0;
}
