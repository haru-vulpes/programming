#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//////////
// CORE //
//////////

bool is_prime(int num)
{
	if (num < 2)
		return false;

	for (size_t numdiv = 2; numdiv < num; numdiv++)
		if (num % numdiv == 0)
				return false;
	return true;
}

///////////
// INFRA //
///////////

int main (int argc, char *argv[])
{
	size_t i = 1;
	int num;	

	while (argv[i])
	{
		num = atoi(argv[i]);

		if (is_prime(num))
                        printf("%d is prime.\n", num);
                else
                        printf("%d is not prime.\n", num);
                i++;
        }

	return 0;
}
