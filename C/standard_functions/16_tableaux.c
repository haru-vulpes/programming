#include <stdio.h>

void print_board(int array[], size_t size)
{
	for (size_t i = 0; i < size ; i++)
	{
		printf("%d\n", array[i]);
	}
}


int main(void)
{
	int array[] = { 51, 42, 137, 4 };
	print_board(array, 4);

	return 0;
}
