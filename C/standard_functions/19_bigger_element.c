#include <stdio.h>

int biggest(int array[], size_t size)
{
	int result = array[0];

	for (size_t i = 0 ; i < size ; i++)
		if (array[i] > result)
			result = array[i];
	return result;
}

int main ()
{
	int array [] = { 1 , 20 , 319 , 15 , 2 };
	printf("the biggest number is : %d\n", biggest(array, 5));

	return 0;
}
