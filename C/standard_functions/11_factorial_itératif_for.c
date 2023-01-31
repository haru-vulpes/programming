#include <stdio.h>

long long unsigned facto(int n)
{
	long long unsigned result = 1;

	if (n == 0)
		return 1;

	for (int i = 1; i <= n ; i++)
	{
		result *= i;
	}
	return result;
}

int main(void)
{
        int a;
        long long unsigned result;

        printf("Enter a positive number less than or equal to 20 to get his factorial.\n");
        scanf("%i", &a);

        if (a >= 0 && a < 21)
        {
                result = facto(a);
                printf("result %i! = %llu\n", a, result);
        }
        else
                printf("You put a number out of the accepted range.\n");


        return 0;
}
