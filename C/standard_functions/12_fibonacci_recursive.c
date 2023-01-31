#include <stdio.h>

unsigned long long fibo(int first_term, int second_term, int n)
{
	unsigned long long result;

	if (n == 1)
		return first_term;
	if (n == 2)
		return second_term;

	result = fibo(first_term, second_term, n - 1) + fibo(first_term, second_term, n - 2);

	return result;
}

int main(void)
{
	int first;
	int second;
	int term;
	unsigned long long result;

	printf("Enter the two first terms of the series, those terms have to be positives integers:\n");
	scanf("%d%d", &first, &second);
	
	if (first >= 0 && second >= 0)
	{
	printf("Enter the term searched in the series, it have to be a positive integer too.\n");
	scanf("%d", &term);
		
		if(term >= 3)
		{
		result = fibo(first, second, term);

		printf("The %d's term has as result %llu.\n", term, result);
		}
		else if (term == 1 || term == 2)
			printf("You know it idiot, it was the terms you enter...\n");
		else
			printf("this number's not allowed\n");
	}
	else 
		printf("these numbers is not valid.\n");

	return 0;
}
