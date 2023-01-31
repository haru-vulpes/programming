#include <stdio.h>

int syracuse(int n)
{
	int compt = 0;

	while (n != 1)
	{
		if (n % 2 == 0)
		{
			n = n / 2;
		}
		else
		{	
			n = 3 * n + 1;
		}
		compt++;
	}

	return compt;
}

int main(void)
{
	int number;
	printf("enter your number\n");
	scanf("%d", &number);
	
	int result = syracuse(number);
	printf("there were %d flight\n", result);

	return 0;
}
