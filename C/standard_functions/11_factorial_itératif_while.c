#include <stdio.h>

unsigned long long facto(int n)
{
	unsigned long long result = 1;

	if (n == 0)
		return 1;
	else
	{
		long long unsigned result = 1;
		int i = 1;

		while (i <= n)
		{
			result = result * i;
			i++;
		}
		return result;
	}
}

int main(void)
{
        int a;
        long long unsigned result;

        printf("Enter a positive number less than or equal to 20 to get his factorial.\n");
        scanf("%i", &a);

        result = facto(a);

        if (a >= 0 && a <= 20)
                printf("result %i! = %llu\n", a, result);
        else
                printf("You put a number out of the accepted range.\n");

        return 0;
}
