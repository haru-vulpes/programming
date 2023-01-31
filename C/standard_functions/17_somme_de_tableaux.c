#include <stdio.h>

int sum_array(int array[], size_t size)
{
	int result = 0;

	for (size_t i = 0; i < size ; i++)
	{
		result += array[i];
	}
	return result;
}


int main(void)
{
	int array[] = { 10, 12, 5, 13, 2 };
	int result = sum_array(array, 5);
	printf("the sum of each bloc of the array is %d\n", result);

	return 0;
}
